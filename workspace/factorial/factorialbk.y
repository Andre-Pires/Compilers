%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include <stdarg.h>
#include "node.h"
#include "tabid.h"

int p, nciclo;
%}

%union {
  int i;      /* integer value */
  double d;    /* double value */
  char *s;    /* symbol name or string literal */
};

%token <i> INT
%token <d> NUM
%token <s> IDENTIF STRN
%token WHILE IF END RETURN VOID PUBLIC CONST THEN ELSE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE INTEGER STRING NUMBER
%token ELSE GE LE EQ NE INC DEC ATRIB ADDR POINTER IFX

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

%type <i> tipo ptr cons pub left_value init parametro parametros pars pars2 expressao expressoes declaracao
%%

ficheiro  : declaracoes
          | /*empty*/
          ;

declaracoes  : declaracao
             | declaracoes declaracao
             ;

declaracao  : pub cons tipo ptr IDENTIF init ';'            { IDnew($1+$2+$3+$4, $5, 0); if($3+$4 != 4) {if($3+$4 != $6) yyerror("Atribuição entre tipos diferentes.");}}
            | pub cons tipo ptr IDENTIF ';'                 { IDnew($1+$2+$3+$4, $5, 0); }
            | pub cons tipo ptr IDENTIF '(' {IDnew($1+$2+$3+$4+32, $5, 0); IDpush(); } parametros ')' {IDreplace($1+$2+$3+$4+32,$5, $7); if(($3+$4) != 0) {IDnew($3+$4, $5, 0);} }  corpop ';' { IDpop();} 
            | pub cons tipo ptr IDENTIF '(' ')' {IDnew($1+$2+$3+$4+32, $5, 0); IDpush();  if(($3+$4) != 0) {IDnew(($3+$4), $5,0);}}  corpo ';'                  {IDpop();}
            | pub cons tipo ptr IDENTIF '(' ')' ';'                                                                                                             {IDnew($1+$2+$3+$4+32, $5, 0);} 
            | error ';'                                                                                                                                         {yyerrok; }
            ;
corpop :
       | corpo
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

init  : ATRIB INT                                                          { $$ = 1; } 
      | ATRIB '-' INT                                                      { $$ = 1; /*-$3 */ } 
      | ATRIB cons STRN                                                    { $$ = 2; }
      | ATRIB NUM                                                          { $$ = 3; }
      | ATRIB '-' NUM                                                      { $$ = 3; /*-$3 */}
      | ATRIB IDENTIF                                                      { $$ = IDfind($2, 0)+4;}
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

corpo : '{' '}'
      | '{' pars2 '}' 
      | '{' instrucoes '}' 
      | '{' pars2 instrucoes '}' 
      ;

instrucoes : instrucao
           | instrucoes instrucao
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

expressao : INT                                       { $$ = 1; }   
          | NUM                                       { $$ = 3; }
          | STRN                                      { $$ = 2; }
          | left_value                                { $$ = $1; }
          | IDENTIF '(' expressoes ')'                { int n; n = IDfind($1, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) $$ = n; else {$$ = IDsearch($1, 0, IDlevel(), 0) & (0x7);}}    /* fazer o search no nivel 0 para nao confundir a funcao com a variavel */
          | IDENTIF '(' ')'                           { int n; n = IDfind($1, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) $$ = n; else {$$ = IDsearch($1, 0, IDlevel(), 0) & (0x7);}}                                                                                      
          | '(' expressao ')'                         { $$ = $2; }
          | left_value ATRIB expressao                { if($1 != 4){if ($1 != $3) yyerror("Atribuição entre tipos diferentes.");} $$ = $1; }
          | '-' expressao %prec UMINUS                { if($2 == 0 || $2 == 2) yyerror("Simétrico : Tipo inválido."); $$ = $2; }
          | INC left_value                            { if($2 != 1) yyerror("Incremento : Tipo inválido."); $$ = 1; }
          | DEC left_value                            { if($2 != 1) yyerror("Decremento : Tipo inválido."); $$ = 1; }
          | left_value INC                            { if($1 != 1) yyerror("Incremento : Tipo inválido."); $$ = 1; }
          | left_value DEC                            { if($1 != 1) yyerror("Decremento : Tipo inválido."); $$ = 1; }
          | expressao '*' expressao                   { $$ = oper($1, $3); }
          | expressao '/' expressao                   { $$ = oper($1, $3); }
          | expressao '%' expressao                   { $$ = oper($1, $3); }   
          | expressao '+' expressao                   { $$ = oper($1, $3); }   
          | expressao '-' expressao                   { $$ = oper($1, $3); }   
          | expressao '>' expressao                   { $$ = comp($1, $3); }
          | expressao '<' expressao                   { $$ = comp($1, $3); }  
          | expressao EQ expressao                    { $$ = comp($1, $3); }   
          | expressao NE expressao                    { $$ = comp($1, $3); }   
          | expressao GE expressao                    { $$ = comp($1, $3); }   
          | expressao LE expressao                    { $$ = comp($1, $3); }   
          | expressao '&' expressao                   { if($1 != 1 || $3 != 1) yyerror("Junção Lógica : Tipo inválido."); $$ = 1; }
          | expressao '|' expressao                   { if($1 != 1 || $3 != 1) yyerror("Alternativa Lógica : Tipo inválido."); $$ = 1; }
          | '~' expressao                             { if($2 != 1) yyerror("Negação Lógica : Tipo inválido."); $$ = 1; }
          | expressao '!'                             { if($1 != 1) yyerror("Factorial : Tipo inválido."); $$ = 3; }
          | '&' left_value %prec ADDR                 { $$ = $2; }
          | '*' left_value %prec POINTER              { $$ = $2; }
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