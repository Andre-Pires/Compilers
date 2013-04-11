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

%type <i> tipo ptr cons pub
%%

ficheiro  : declaracoes
          | /*empty*/
          ;

declaracoes  : declaracao
             | declaracoes declaracao
             ;

declaracao  : pub cons tipo ptr IDENTIF init ';'            {IDnew($1+$2+$3+$4, $5, 0);}
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

init  : ATRIB INT
      | ATRIB CONST STRN
      | ATRIB STRN
      | ATRIB NUM
      | ATRIB IDENTIF
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

parametro : tipo IDENTIF
          | tipo '*' IDENTIF
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

expressao : INT             
          | NUM
          | STRN
          | left_value              
          | IDENTIF '(' expressoes ')'
          | IDENTIF '(' ')'
          | '(' expressao ')'       
          | left_value ATRIB expressao
          | '-' expressao %prec UMINUS
          | INC left_value            
          | DEC left_value            
          | left_value INC            
          | left_value DEC               
          | expressao '*' expressao   
          | expressao '/' expressao   
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
          | expressao '!'        
          | '&' left_value %prec ADDR
          | '*' left_value %prec POINTER
          ;

left_value: IDENTIF                
          | IDENTIF '[' expressao ']'    
          ;

     
%%