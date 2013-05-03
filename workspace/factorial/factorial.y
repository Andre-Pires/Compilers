%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include <stdarg.h>
#include "node.h"
#include "tabid.h"

int p, nciclo, nivel;
%}

%union {
	int i;			/* integer value */
  double d;    /* double value */
	char *s;		/* symbol name or string literal */
  Node * n;
};

%token <i> INT
%token <d> NUM
%token <s> IDENTIF STRN
%token WHILE IF END RETURN VOID PUBLIC CONST THEN ELSE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE INTEGER STRING NUMBER
%token ELSE GE LE EQ NE INC DEC ATRIB ADDR POINTER IFX

%token DECL DECLS CALL NEG FACT AND OR PROG ADD SUBT MUL DIV LT GT MOD PARS INTRS PINTR

%nonassoc IFX
%nonassoc ELSE
%right ATRIB
%left '|'
%left '&'
%nonassoc '~'
%left EQ NE
%left GE LE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc  POINTER ADDR '!' UMINUS INC DEC
%nonassoc '(' ')' '[' ']'

%type <i> tipo ptr cons pub
%type <n> left_value init parametro parametros pars pars2 expressao expressoes declaracao declaracoes ficheiro corpo corpop instrucao instrucoes
%%

ficheiro  : declaracoes         { Node *n = uniNode(PROG, $1); 
                                  printNode(n, 0, 0);   } 
          | /*empty*/           { Node *n = uniNode(PROG, nilNode(0)); 
                                  printNode(n, 0, 0);   } 
          ;

declaracoes  : declaracao                     {$$ = uniNode(DECL, $1); }
             | declaracoes declaracao         {$$ = binNode(DECLS, $1, $2); }
             ;

declaracao  : pub cons tipo ptr IDENTIF init ';'            { IDnew($1+$2+$3+$4, $5, 0); if($3+$4 != $6) yyerror("Atribuição entre tipos diferentes");}
            | pub cons tipo ptr IDENTIF ';'                 { IDnew($1+$2+$3+$4, $5, 0); }
            | pub cons tipo ptr IDENTIF '(' {IDnew($1+$2+$3+$4+32, $5, 0); IDpush(); } parametros ')' {IDreplace($1+$2+$3+$4+32,$5, p); if(($3+$4) != 0) {IDnew($3+$4, $5, 0);} }  corpop ';' { IDpop();} 
            | pub cons tipo ptr IDENTIF '(' ')' {IDnew($1+$2+$3+$4+32, $5, 0); IDpush();  if(($3+$4) != 0) {IDnew(($3+$4), $5,0);}}  corpo ';'                  {IDpop();}
            | pub cons tipo ptr IDENTIF '(' ')' ';'                                                                                                             {IDnew($1+$2+$3+$4+32, $5, 0);} 
            | error ';'                                                                                                                                         {yyerrok; }
            ;

corpop :                     { $$ = 0; }
       | corpo               { $$ = $1; }
       ;

ptr   :                      { $$ = 0; }
      | '*'                  { $$ = 4; }
      ;

cons  :                      { $$ = 0; }
      | CONST                { $$ = 8; }
      ;

pub   :                      { $$ = 0; }
      | PUBLIC               { $$ = 16; }
      ;

tipo  : VOID                 { $$ = 0; }
      | INTEGER              { $$ = 1; }
      | STRING               { $$ = 2; }
      | NUMBER               { $$ = 3; }
      ;

init  : ATRIB INT                                                          { $$ = uniNode(ATRIB, intNode(INT, $2)); }  // uni ou int?
      | ATRIB '-' INT                                                      { $$ = uniNode(ATRIB, intNode(INT, -$3)); }  // uni ou int?
      | ATRIB cons STRN                                                    { $$ = uniNode(ATRIB, strNode(STRN, $3)); }
      | ATRIB NUM                                                          { $$ = uniNode(ATRIB, realNode(NUM, $2)); }
      | ATRIB '-' NUM                                                      { $$ = uniNode(ATRIB, realNode(NUM, -$3)); }
      | ATRIB IDENTIF                                                      { $$ = uniNode(ATRIB, strNode(IDENTIF, $2)); }
      ;

pars : pars ',' parametro             { $$ = $1 + $3; }
     |                                { $$ = 0; }
     ;

parametros  : parametro pars          { $$ = $1 + $2; }
            ;

parametro : tipo ptr IDENTIF                    { IDnew($1+$2, $3, 0);}
          ;

pars2 : parametro ';'                           { $$ = $1; }
      | pars2 parametro ';'                     { $$ = $1 + $2; }
      ;

corpo : '{' '}'                                 {$$ = nilNode(END);}
      | '{' pars2 '}'                           {$$ = uniNode(PARS, $2);}
      | '{' instrucoes '}'                      {$$ = uniNode(INTRS, $2);}
      | '{' pars2 instrucoes '}'                {$$ = binNode(PINTR, $2 , $3);}
      ;

instrucoes : instrucao                          {$$ = uniNode(INTR, $1);}
           | instrucoes instrucao               {$$ = binNode(INTRS, $1, $2);}
           ;

instrucao : IF expressao THEN instrucao %prec IFX
          | IF expressao THEN instrucao ELSE instrucao
          | DO { nciclo++; } instrucao { nciclo--; } WHILE expressao ';'
          | FOR left_value IN expressao updown expressao step DO { nciclo++; } instrucao { nciclo--; }
          | expressao ';' 
          | corpo
          | BREAK INT ';'                             { if ($2 == 0 || $2 > nciclo) yyerror("Break inválido: Fora de um ciclo"); }
          | CONTINUE INT ';'
          | BREAK ';'                                 { if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); }
          | CONTINUE ';'
          | left_value '#' expressao ';'
          | error ';'                                     { yyerrok; }
          ;

updown  : UPTO
        | DOWNTO
        ;

step    : 
        | STEP expressao
        ;

expressoes  : expressoes ',' expressao                { $$ = $1 + $3; }
            | expressao                               { $$ = $1; }
            ;

expressao : INT                                       { $$ = intNode(INT, $1); }
          | NUM                                       { $$ = realNode(NUM, $1); }
          | STRN                                      { $$ = strNode(STRN, $1); }
          | left_value                                { $$ = $1; }
          | IDENTIF '(' expressoes ')'                { int n; n = IDfind($1, 0) && (0x7); if(n != 0) $$ = binNode(CALL, strNode(IDENTIF, $1), $3);
                                                                                          else {$$ = IDsearch($1, 0, IDlevel(), 0) && (0x7); }} /* fazer o search no nivel 0 para nao confundir a funcao com a variavel */
          | IDENTIF '(' ')'                           { int n; n = IDfind($1, 0) && (0x7); if(n != 0) $$ = binNode(CALL, strNode(IDENTIF, $1), nilNode(END));
                                                                                           else {$$ = IDsearch($1, 0, IDlevel(), 0) && (0x7); }}      /* iguanilNode(END)*/
          | '(' expressao ')'                         { $$ = $2; }
          | left_value ATRIB expressao                { if ($1 != $3) yyerror("Atribuição entre tipos diferentes"); $$ = binNode('ATRIB', $1, $3); }
          | '-' expressao %prec UMINUS                { if($2 == 0 || $2 == 2) yyerror("Simétrico : Tipo inválido"); $$ = uniNode(UMINUS, $2);}
          | DEC left_value                            { if($2 != 1) yyerror("Decremento : Tipo inválido"); $$ = binNode(DEC, nilNode(END), $2); }
          | INC left_value                            { if($2 != 1) yyerror("Incremento : Tipo inválido"); $$ = binNode(INC, nilNode(END), $2); }
          | left_value INC                            { if($1 != 1) yyerror("Incremento : Tipo inválido"); $$ = binNode(INC, nilNode(END), $1); }
          | left_value DEC                            { if($1 != 1) yyerror("Decremento : Tipo inválido"); $$ = binNode(DEC, nilNode(END), $1); }
          | expressao '*' expressao                   { oper($1, $3); $$ = binNode('MUL', $1, $3);}
          | expressao '/' expressao                   { oper($1, $3); $$ = binNode('DIV', $1, $3);}
          | expressao '%' expressao                   { oper($1, $3); $$ = binNode('MOD', $1, $3);}
          | expressao '+' expressao                   { oper($1, $3); $$ = binNode('ADD', $1, $3);}   
          | expressao '-' expressao                   { oper($1, $3); $$ = binNode('SUBT', $1, $3);}   
          | expressao '>' expressao                   { comp($1, $3); $$ = binNode('GT', $1, $3);}
          | expressao '<' expressao                   { comp($1, $3); $$ = binNode('LT', $1, $3);}
          | expressao EQ expressao                    { comp($1, $3); $$ = binNode('EQ', $1, $3);}
          | expressao NE expressao                    { comp($1, $3); $$ = binNode('NE', $1, $3);}
          | expressao GE expressao                    { comp($1, $3); $$ = binNode('GE', $1, $3);}
          | expressao LE expressao                    { comp($1, $3); $$ = binNode('LE', $1, $3);}
          | expressao '&' expressao                   { if($1 != 1 || $3 != 1) yyerror("Junção Lógica : Tipo inválido"); $$ = binNode('AND', $1, $3); }
          | expressao '|' expressao                   { if($1 != 1 || $3 != 1) yyerror("Alternativa Lógica : Tipo inválido"); $$ = binNode('OR', $1, $3); }
          | '~' expressao                             { if($2 != 1) yyerror("Negação Lógica : Tipo inválido"); $$ = uniNode(NEG, $2); }
          | expressao '!'                             { if($1 != 1) yyerror("Factorial : Tipo inválido"); $$ = uniNode(FACT, $1); }
          | '&' left_value %prec ADDR                 { $$ = uniNode(ADDR, $2); }
          | '*' left_value %prec POINTER              { $$ = uniNode(POINTER, $2); }
          ;

left_value: IDENTIF                                   { $$ = IDfind($1, 0); }
          | IDENTIF '[' expressao ']'                 {int x = IDfind($1, 0);
                                                        if (((x & 0x4) == 4)) 
                                                              $$ = x - 4;
                                                        else if (((x & 0x7) == 2))
                                                              $$ = 1;
                                                        else yyerror("Ponteiro: Tipo inválido.");
              /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
          ;
     
%%

static void mkcall(char *func, long eargs) {
  long fargs; 
  int type = IDsearch(func, &fargs, IDlevel(), 0) && (0x7); /* yyerror if ID does not exist */

  if (type < 32) yyerror("ID is not a function");
  if (fargs != eargs) yyerror("wrong number of arguments in function call");
}

static int oper(int name, int name2) {
 
  if (name == 0 || name2 == 0 || name == 2 || name2 == 2) 
    yyerror("Operação : Tipo inválido.");
  if(name == 3 || name2 == 3) return 3;
  else return 1;
}

static int comp(int name, int name2) {
 
  if (name == 0 || name2 == 0) yyerror("Comparação : Tipo inválido.");
  if (name == 2 && name != name2) yyerror("Comparação : Tipos incompatíveis.");
  return 1;
}