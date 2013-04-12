%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include "node.h"
#include "tabid.h"
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

%type <i> tipo ptr cons pub left_value expressao init
%%

ficheiro  : declaracoes
          | /*empty*/
          ;

declaracoes  : declaracao
             | declaracoes declaracao
             ;

declaracao  : pub cons tipo ptr IDENTIF init ';'            {IDnew($1+$2+$3+$4, $5, 0);
                                                            if(IDfind($5, 0) != IDfind($6, 0)) yyerror("Atribuição entre tipos diferentes.");}
            | pub cons tipo ptr IDENTIF ';'                 {IDnew($1+$2+$3+$4, $5, 0);}
            ;

ptr   :                      {$$ = 0;}
      | '*'                  {$$ = 4;}
      ;

cons  :                      {$$ = 0;}
      | CONST                {$$ = 8;}
      ;

pub   :                      {$$ = 0;}
      | PUBLIC               {$$ = 16;}
      ;

tipo  : VOID                 {$$ = 0;}
      | INTEGER              {$$ = 1;}
      | STRING               {$$ = 2;}
      | NUMBER               {$$ = 3;}
      ;

init  : ATRIB INT                     {$$ = 1;} 
      | ATRIB cons STRN               {$$ = IDfind($2, 0) + 2;}
      | ATRIB NUM                     {$$ = 3;}
      | ATRIB IDENTIF                 {$$ = IDfind($2, 0);}
      |'(' parametros ')' corpo
      |'(' parametros ')'
      |'(' ')' corpo
      |'(' ')'
      ;

pars : ',' parametro
     | pars ',' parametro
     ;

parametros  : parametro
            | parametro pars
            ;

parametro : tipo ptr IDENTIF            {IDnew($1+$2, $3, 0);}
          ;

pars2 : parametro ';'
      | pars2 parametro ';'
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
          | DO instrucao WHILE expressao ';'
          | FOR left_value IN expressao UPTO expressao DO instrucao 
          | FOR left_value IN expressao DOWNTO expressao DO instrucao 
          | FOR left_value IN expressao UPTO expressao STEP expressao DO instrucao 
          | FOR left_value IN expressao DOWNTO expressao STEP expressao DO instrucao 
          | expressao ';' 
          | corpo
          | BREAK INT ';'
          | CONTINUE INT ';'
          | BREAK ';'
          | CONTINUE ';'
          | left_value '#' expressao ';'
          ;

expressoes  : expressoes ',' expressao
            | expressao
            ;

expressao : INT                           {$$ = 1;}   
          | NUM                           {$$ = 3;}
          | STRN                          {$$ = 2;}
          | left_value              
          | IDENTIF '(' expressoes ')'
          | IDENTIF '(' ')'
          | '(' expressao ')'       
          | left_value ATRIB expressao 
          | '-' expressao %prec UMINUS
          | INC left_value                {int t = IDfind($2, 0); if(t != 1) yyerror("Incremento : Tipo inválido."); $$ = t;}
          | DEC left_value                {int t = IDfind($2, 0); if(t != 1) yyerror("Decremento : Tipo inválido."); $$ = t;}
          | left_value INC                {int t = IDfind($1, 0); if(t != 1) yyerror("Incremento : Tipo inválido."); $$ = t;}
          | left_value DEC                {int t = IDfind($1, 0); if(t != 1) yyerror("Decremento : Tipo inválido."); $$ = t;}
          | expressao '*' expressao       {$$ = mult($1, $3);}
          | expressao '/' expressao       {$$ = mult($1, $3);}
          | expressao '%' expressao   
          | expressao '+' expressao   
          | expressao '-' expressao   
          | expressao '>' expressao  
          | expressao '<' expressao  
          | expressao EQ expressao   
          | expressao NE expressao   
          | expressao GE expressao   
          | expressao LE expressao   
          | expressao '&' expressao  
          | expressao '|' expressao  
          | '~' expressao
          | expressao '!'                {int t = IDfind($1, 0); if(t != 1) yyerror("Factorial : Tipo inválido.");} 
          | '&' left_value %prec ADDR
          | '*' left_value %prec POINTER
          ;

left_value: IDENTIF                     {$$ = IDfind($1, 0);}            
          | IDENTIF '[' expressao ']'   {}
          ;

     
%%

static int mult(int name, int name2) {
 
  if (name == 0 || name2 == 0 || name == 2 || name2 == 2) 
    yyerror("Operação : Tipo inválido.");
  if(name == 3 || name2 == 3) return 3;
  else return 2;
}