%{
/* Para testar apenas o lex, deve ter um yacc mínimo para gerar o y.tab.h
   Basta definir os tokens necessários à linguagem a testar (%token).
   Também a rotina main() deve chamar apenas o lex (yylex()).
   Devemos igualmente fornecer uma rotina de impressão de erros yyerror.
   A gramática é vazia (file: ;) pelo que só reconhece a linguagem vazia, não devendo ser chamado o analisador sintáctico do yacc (yyparse()).

Compilar com:
byacc -dv solex.y
flex -dl lang.l
gcc lex.yy.c y.tab.c -I../lib

Executar os exemplos (apenas com redirecção):
./lang < exemplo.lang

Para garantir que as expressões regulares reconhecem correctamente as sequências de entrada deve adicionar o modo debug (-d) ao flex.
Ao executar os diversos exemplos deve verificar quais as expressões regulares que as reconhecem cada uma das sequências de entrada.
As expressões regulares são identificadas pelo número da linha em que se encontram no ficheiro lex.
*/   
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include "node.h"
#include "tabid.h"
void yyerror(char *s);
%}

%union {
	long int i;			/* integer value */
	char *s;		/* symbol name or string literal */
};

%token <i> NUMBER
%token <s> IDENTIF STRING
%token PROGRAM MODULE IMPORT EXPORT NUMBER STRING FUNCTION VECTOR CONST READ WRITE IF
%nonassoc ELIF
%nonassoc ELSE

%right IATRIB
%left '|'
%left '&' 
%nonassoc '!'
%left EQ NE
%left '<' '>' GE LE
%left '+' '-'
%left '*' '/' '%'
%right POWER
%nonassoc '&' UMINUS INC DEC
%nonassoc '(' ')' '[' ']'

/* %token LABEL JMP JZ JNZ ETIQ CALL IDS */
%%
file	:
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
