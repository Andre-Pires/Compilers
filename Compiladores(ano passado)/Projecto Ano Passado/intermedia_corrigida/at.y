%{
/* $Id: at.y,v 1.9 2004/12/09 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include "tabid.h"

void evaluate(Node *p);
void yyerror(char *s);
%}

%union { 
	 int ival;
	 char *text;
	 double dval;
}
%token CONST VOID INT REAL STRING PUBLIC USE NEXT STOP RETURN EXPL OPER PRINT PRINT_NEW_LINE
%token<text> CHAR LIT_STRING ID
%token<ival> INTEGER 
%token<dval> LIT_REAL
%nonassoc IFX
%nonassoc ':' SCT
%right '='
%left OR
%left AND
%nonassoc NOT
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '^'
%nonassoc UMINUS UPLUS '#' '?'
%nonassoc '(' ')' '[' ']' '{'

%start ficheiro
%%
ficheiro	: ficheiro declaracao						
		| declaracao							
		;
	 
declaracao	: variavel ';'
		| funcao
		;

variavel	: qualificador CONST tipo ID
		| qualificador tipo ID 
		| qualificador CONST tipo ID '=' literal
		| qualificador tipo ID '=' literal
		| CONST tipo ID
		| tipo ID 
		| CONST tipo ID '=' literal
		| tipo ID '=' literal
		;
		
variaveis	: variavel ',' variaveis
		| variavel
		;
		
funcao		: qualificador VOID ID '(' variaveis ')' corpo
		| qualificador tipo ID '(' variaveis ')' corpo
		| qualificador VOID ID '(' ')' corpo
		| qualificador tipo ID '(' ')' corpo
		| VOID ID '(' variaveis ')' corpo
		| tipo ID '(' variaveis ')' corpo
		| VOID ID '(' ')' corpo
		| tipo ID '(' ')' corpo
		;	

tipo		: INT								
		| REAL								
		| STRING
		| '<' tipo '>'
		;
		
qualificador	: PUBLIC
		| USE
		;

corpo		: lit secinc '[' ']' bloco '>' '>' bloco
		| lit secinc '[' ']' bloco seccao '>' '>' bloco
		| lit secinc '(' ')' bloco '>' '>' bloco
		| lit secinc '(' ')' bloco seccao '>' '>' bloco
		| lit secinc '[' expressao ']' bloco '>' '>' bloco
		| lit secinc '[' expressao ']' bloco seccao '>' '>' bloco
		| lit secinc '(' expressao ')' bloco '>' '>' bloco
		| lit secinc '(' expressao ')' bloco seccao '>' '>' bloco
		| lit secinc bloco '>' '>' bloco
		| lit secinc bloco seccao '>' '>' bloco
		| lit secinc '[' ']' bloco %prec SCT
		| lit secinc '[' ']' bloco seccao 
		| lit secinc '(' ')' bloco %prec SCT
		| lit secinc '(' ')' bloco seccao 
		| lit secinc '[' expressao ']' bloco %prec SCT
		| lit secinc '[' expressao ']' bloco seccao
		| lit secinc '(' expressao ')' bloco %prec SCT
		| lit secinc '(' expressao ')' bloco seccao 
		| lit secinc bloco %prec SCT
		| lit secinc bloco seccao 
		| ';'
		;
		
lit 		: '=' literal
		| /* vazio */
		;
		
secinc		: '<' '<' bloco
		| /* vazio */
		;
		
seccao		: '[' ']' bloco %prec SCT
		| '(' ')' bloco %prec SCT
		| '[' ']' bloco seccao
		| '(' ')' bloco seccao 
		| '[' expressao ']' bloco %prec SCT
		| '(' expressao ')' bloco %prec SCT
		| '[' expressao ']' bloco seccao
		| '(' expressao ')' bloco seccao
		| bloco %prec SCT
		| bloco seccao 
		;

literal		: INTEGER
		| LIT_REAL
		| CHAR
		| LIT_STRING
		;

bloco		: '{' '}'
		| '{' decl '}'
		| '{' instr '}'
		| '{' decl instr '}'
		;
		
decl		: declaracao decl
		| declaracao
		;
		
instr		: instrucao instr
		| instrucao
		;
		
		
instrucao	: expressao ';'
		| expressao PRINT
		| expressao PRINT_NEW_LINE
		| NEXT
		| STOP
		| RETURN
		| condicao
		| iteracao
		| bloco
		;
	
condicao	: '[' expressao ']' '#' instrucao
		| '[' expressao ']' '?' instrucao %prec IFX
		| '[' expressao ']' '?' instrucao ':' instrucao
		| '[' expressao ']' '?' instrucao cond %prec IFX
		| '[' expressao ']' '?' instrucao cond ':' instrucao
		;	
		
cond		: '[' expressao ']' '?' instrucao cond
		| '[' expressao ']' '?' instrucao
		;		
		

iteracao	: '[' variaveis ';' expressao ';' expressao ']' instrucao
		| '[' variaveis ';' expressao ';' ']' instrucao
		| '[' variaveis ';' ';' expressao ']' instrucao
		| '[' variaveis ';' ';' ']' instrucao
		| '[' expressao ';' expressao ';' expressao ']' instrucao
		| '[' expressao ';' expressao ';' ']' instrucao
		| '[' expressao ';' ';' expressao ']' instrucao
		| '[' expressao ';' ';' ']' instrucao
		| '[' ';' expressao ';' expressao ']' instrucao
		| '[' ';' expressao ';' ']' instrucao
		| '[' ';' ';' expressao ']' instrucao
		| '[' ';' ';' ']' instrucao
		;

expressao	: literal						
		| ID							
		| ID '?'							
		| ID '[' expressao ']' '?'
		| ID '=' expressao
		| ID '[' expressao ']' '=' expressao
		| ID '(' param ')'
		| ID '(' ')'					
		| '@' '=' expressao
		| '@' 
		| '@' '(' param ')'
		| '@' '(' ')'
		| '-' expressao %prec UMINUS	
		| '+' expressao %prec UPLUS		  
		| expressao '+' expressao			  
		| expressao '-' expressao			  
		| expressao '*' expressao			  
		| expressao '/' expressao			  
		| expressao '%' expressao			 
		| expressao '<' expressao			  
		| expressao '>' expressao			  
		| expressao GE expressao			 
		| expressao LE expressao			  
		| expressao NE expressao			  
		| expressao EQ expressao 
		| expressao AND expressao //inteiros
		| expressao OR expressao //inteiros
		| NOT expressao  // inteiros
		| ID '[' expressao ']' // indexacao - inteiros
		| ID '=' expressao '#' // reserva de memoria - inteiros
		| expressao '^' expressao // potencia - inteiros			  
		| '(' expressao ')'			  
		;
		
param		: expressao
		| expressao ',' param
		;

%%
char **yynames = (char**)yyname;
