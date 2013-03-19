%{
/* $Id: compact.y,v 1.10 2012/05/06 17:25:13 prs Exp $ */
/* (Compact with functions included as instructions) */
/* [only grammar, without semantic verifications] */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
%}

%union {
	int i;			/* integer value */
	char *s;		/* symbol name or string literal */
};

%token <i> INTEGER
%token <s> VARIABLE STRING
%token WHILE IF PRINT READ PROGRAM END FUNC RETURN
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%%
file	: decls
	| decls PROGRAM list END
	;

decls	:
	| decls FUNC VARIABLE '(' ids ')' END
	| decls FUNC VARIABLE '(' ids ')' list END
	| decls FUNC VARIABLE '(' ')' END
	| decls FUNC VARIABLE '(' ')' list END
	| decls VARIABLE ';'
	| decls VARIABLE '=' INTEGER ';'
	| decls VARIABLE '=' '-' INTEGER ';'
	;

ids	: VARIABLE
	| ids ',' VARIABLE
	;

stmt	: ';'
	| PRINT STRING ';'
	| PRINT expr ';'
	| READ VARIABLE ';'
	| VARIABLE '=' expr ';'
	| WHILE '(' expr ')' stmt
	| IF '(' expr ')' stmt %prec IFX
	| IF '(' expr ')' stmt ELSE stmt
	| '{' list '}'
	| VARIABLE '=' VARIABLE '(' args ')' 
	| VARIABLE '(' args ')'
	| VARIABLE '=' VARIABLE '(' ')'
	| VARIABLE '(' ')'
	| RETURN expr ';'
	;

list	: stmt
	| list stmt
	;

args	: expr
	| args ',' expr
	;

expr	: INTEGER
	| VARIABLE			  { IDfind($1, 0); }
	| '-' expr %prec UMINUS
	| expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr '%' expr
	| expr '<' expr
	| expr '>' expr
	| expr GE expr
	| expr LE expr
	| expr NE expr
	| expr EQ expr
	| '(' expr ')'
	;
