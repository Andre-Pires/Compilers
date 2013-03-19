%{
/* Para testar apenas o lex, deve ter um yacc mínimo para gerar o y.tab.h
   Basta definir os tokens necessários à linguagem a testar (%token).
   Também a rotina main() deve chamar apenas o lex (yylex()).
   Devemos igualmente fornecer uma rotina de impressão de erros yyerror.
   A gramática é vazia (file: ;) pelo que só reconhece a linguagem vazia, não devendo ser chamado o analisador sintáctico do yacc (yyparse()).

Compilar com:
byacc -dv solex.y
flex -dl lang.l
gcc lex.yy.c y.tab.c

Executar os exemplos (apenas com redirecção):
./lang < exemplo.lang

Para garantir que as expressões regulares reconhecem correctamente as sequências de entrada deve adicionar o modo debug (-d) ao flex.
Ao executar os diversos exemplos deve verificar quais as expressões regulares que as reconhecem cada uma das sequências de entrada.
As expressões regulares são Identificadas pelo número da linha em que se encontram no ficheiro lex.
*/   
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
%}

%union {
	int i;			/* integer value */
  double d;    /* double value */
	char *s;		/* symbol name or string literal */
};

%token <i> INTEGER
%token <d> NUMBER
%token <s> IDENTIF STRING
%token WHILE IF END RETURN VOID PUBLIC CONST IF THEN ELSE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE
%token ELSE GE LE EQ NE INC DEC ATRIB ADDR POINTER


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
%%

ficheiro  = declaração
          | 
          ;

declaração  =  PUBLIC tipo '*' IDENTIF init ';'
            | tipo '*' IDENTIF init ';'
            | PUBLIC CONST tipo '*' IDENTIF init ';'
            | CONST tipo '*' IDENTIF init ';'
            | PUBLIC tipo IDENTIF init ';'
            | tipo IDENTIF init ';'
            | PUBLIC CONST tipo IDENTIF init ';'
            | CONST tipo IDENTIF init ';'
            | PUBLIC tipo '*' IDENTIF ';'
            | tipo '*' IDENTIF ';'
            | PUBLIC CONST tipo '*' IDENTIF ';'
            | CONST tipo '*' IDENTIF ';'
            | PUBLIC tipo IDENTIF ';'
            | tipo IDENTIF ';'
            | PUBLIC CONST tipo IDENTIF ';'
            | CONST tipo IDENTIF ';'
            ;

tipo  = INTEGER 
      | STRING 
      | NUMBER 
      | VOID
      ;

init  = ATRIB INTEGER 
      | ATRIB CONST STRING
      | ATRIB STRING
      | ATRIB NUMBER
      | ATRIB IDENTIF
      |'(' parâmetros ')' corpo
      |'(' parâmetros ')'
      |'(' ')' corpo 
      |'(' ')'
      ;

pars = ',' parâmetro
     | ',' pars
     ;

parâmetros  = parâmetro
            | parâmetro pars
            ;

parâmetro = tipo IDENTIF
          | tipo '*' IDENTIF
          ;

pars2 = parâmetro ';'
     | pars2 ';'
     ;

corpo = '{' '}'
      | '{' pars2 '}'
      | '{' instrucoes } '}'
      | '{' pars2 instrucoes '}'
      ;

instrucoes = instrução
           | instrucoes
           ;

instrução = IF expressão THEN instrução ELSE instrução
          | IF expressão THEN instrução
          | DO expressão WHILE instrução 
          | FOR left-value IN expressão UPTO expressão DO instrução 
          | FOR left-value IN expressão DOWNTO expressão DO instrução 
          | FOR left-value IN expressão UPTO expressão STEP expressão DO instrução 
          | FOR left-value IN expressão DOWNTO expressão STEP expressão DO instrução 
          | expressão ';' 
          | corpo
          | BREAK INTEGER ';'
          | CONTINUE INTEGER ';'
          | left-value '#' expressão ';'
          ;
%%
int main()
{
  while (yylex())
    ;
  return 0;
}

void yyerror(char *s)
{
  printf("%s\n", s);
}
