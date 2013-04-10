%{
/* $Id: interm.y,v 1.11 2013/02/06 17:25:13 prs Exp $ */
/* (Compact with functions included as instructions) */
/* semantic processing merges function declaration with arguments,
 * introducing 'listp' non-terminal. */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include "tabid.h"
extern void yyerror(char *s);
static int pos; /* local variable offset */
static void mkcall(char *func, long eargs); /* check function call */
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

%type <i> args ids

%%
file	: decls
	| decls PROGRAM list END
	;

decls	:
	| decls FUNC VARIABLE '(' { IDnew(FUNC, $3, 0); IDpush(); } ids ')'
		{ IDreplace(FUNC, $3, (long)$6); } listp END { IDpop(); pos = 0; }
	| decls FUNC VARIABLE '(' ')' { IDnew(FUNC, $3, 0); } listp END { pos = 0; }
	| decls VARIABLE ';'				{ IDnew(INTEGER, $2, 0); }
	| decls VARIABLE '=' INTEGER ';'		{ IDnew(INTEGER, $2, 0); }
	| decls VARIABLE '=' '-' INTEGER ';'		{ IDnew(INTEGER, $2, 0); }
	;

ids	: VARIABLE		{ $$ = 1; IDnew(INTEGER, $1, 8); }
	| ids ',' VARIABLE	{ $$ = $1 + 1; IDnew(INTEGER, $3, 4 + 4 * $$); }
	;

listp	:
	| list
	;

stmt	: ';'
	| PRINT STRING ';'
	| PRINT expr ';'
	| READ VARIABLE ';'	{ if (IDfind($2, 0) == FUNC)
				    yyerror("read with function argument");
				}
	| VARIABLE '=' expr ';'			{ assign($1); }
	| WHILE '(' expr ')' stmt
	| IF '(' expr ')' stmt %prec IFX
	| IF '(' expr ')' stmt ELSE stmt
	| '{' list '}'
	| VARIABLE '=' VARIABLE '(' args ')' 	{ mkcall($3, $5); assign($1); }
	| VARIABLE '(' args ')'			{ mkcall($1, $3); }
	| VARIABLE '=' VARIABLE '(' ')'		{ mkcall($3, 0); assign($1); }
	| VARIABLE '(' ')'			{ mkcall($1, 0); }
	| RETURN expr ';'
	;

list	: stmt	
	| list stmt
	;

args	: expr			{ $$ = 1; }
	| args ',' expr		{ $$ = $1 + 1; }
	;

expr	: INTEGER
	| VARIABLE	{ if (IDfind($1, 0) == FUNC)
			    yyerror("function name in expression");
			}
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
%%
static void assign(char *name) {
  if (IDfind(name, (long*)IDtest) < 0)
    IDnew(INTEGER, name, pos -= 4);
}

static void mkcall(char *func, long eargs) {
  long fargs; 
  int type = IDfind(func, &fargs); /* yyerror if ID does not exist */

  if (type != FUNC) yyerror("ID is not a function");
  if (fargs != eargs) yyerror("wrong number of arguments in functiom call");
}
