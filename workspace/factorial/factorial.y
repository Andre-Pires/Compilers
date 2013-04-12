%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include "node.h"
#include "tabid.h"

int p, nciclo;
%}

%union {
	int i;			/* integer value */
  double d;    /* double value */
	char *s;		/* symbol name or string literal */
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

%type <i> tipo ptr cons pub left_value expressao init parametro parametros pars pars2 expressao expressoes
%%

ficheiro  : declaracoes
          | /*empty*/
          ;

declaracoes  : declaracao
             | declaracoes declaracao
             ;

declaracao  : pub cons tipo ptr IDENTIF init ';'            { IDnew($1+$2+$3+$4, $5, 0);
                                                            if($3+$4 != ($6 & 0x7)) yyerror("Atribuição entre tipos diferentes.");
                                                            if ($6 == 32) IDreplace($1+$2+$3+$4+32, $5, p); }
            | pub cons tipo ptr IDENTIF ';'                 { IDnew($1+$2+$3+$4, $5, 0); }
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

init  : ATRIB INT                     { $$ = 1; } 
      | ATRIB cons STRN               { $$ = 2; }
      | ATRIB NUM                     { $$ = 3; }
      | ATRIB IDENTIF                 { $$ = IDfind($2, 0)+4; }
      |'(' parametros ')' corpo       { $$ = 32; p = $2; }
      |'(' parametros ')'             { $$ = 32; p = $2; }
      |'(' ')' corpo                  { $$ = 0; }
      |'(' ')'                        { $$ = 0; }
      ;

pars : ',' parametro                  { $$ = $2; }
     | pars ',' parametro             { $$ = $1 + $3; }
     ;

parametros  : parametro               { $$ = $1; }
            | parametro pars          { $$ = $1 + $2; }
            ;

parametro : tipo ptr IDENTIF          { IDnew($1+$2, $3, 0); }
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
          | BREAK INT ';'                             { if ($2 == 0 || $2 > nciclo) yyerror(""); }
          | CONTINUE INT ';'
          | BREAK ';'                                 { if (nciclo == 0) yyerror(""); }
          | CONTINUE ';'
          | left_value '#' expressao ';'
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
          | IDENTIF '(' expressoes ')'                { $$ = IDfind($1, 0) + $3; }
          | IDENTIF '(' ')'                           { $$ = IDfind($1, 0); }
          | '(' expressao ')'                         { $$ = $2; }
          | left_value ATRIB expressao                { if ($1 != $3) yyerror("Atribuição entre tipos diferentes."); $$ = $1; }
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
          | expressao '!'                             { if($1 != 1) yyerror("Factorial : Tipo inválido."); $$ = $1; } 
          | '&' left_value %prec ADDR
          | '*' left_value %prec POINTER
          ;

left_value: IDENTIF                                   { $$ = IDfind($1, 0); }
          | IDENTIF '[' expressao ']'                 { $$ = IDfind($1, 0); 
                                            /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
          ;
     
%%

static int oper(int name, int name2) {
 
  if (name == 0 || name2 == 0 || name == 2 || name2 == 2) 
    yyerror("Operação : Tipo inválido.");
  if(name == 3 || name2 == 3) return 3;
  else return 2;
}

static int comp(int name, int name2) {
 
  if (name == 0 || name2 == 0) yyerror("Comparação : Tipo inválido.");
  if (name == 2 && name != name2) yyerror("Comparação : Tipos incompatíveis.");
  return 1;
}