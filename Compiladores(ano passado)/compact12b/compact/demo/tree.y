%{
/* $Id: compact.y,v 1.9 2004/12/09 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include "tabid.h"

void evaluate(Node *p);
void yyerror(char *s);
%}

%union {
	regint i;		/* integer value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
};

%token <i> INTEGER
%token <s> VARIABLE STRING
%token WHILE IF PRINT READ PROGRAM END
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%type <n> stmt expr list

%%

program	: PROGRAM list END		  { evaluate($2); freeNode($2); }
	;

stmt	: ';'				  { $$ = 0; }
	| PRINT STRING ';'		  { $$ = strNode(STRING, $2); }
	| PRINT expr ';'		  { $$ = subNode(PRINT, 1, $2); }
	| READ VARIABLE ';'		  { $$ = strNode(READ, $2); }
	| VARIABLE '=' expr ';'		  { $$ = subNode('=', 2, strNode(VARIABLE, $1), $3);}
	| WHILE '(' expr ')' stmt	  { $$ = subNode(WHILE, 2, $3, $5); }
	| IF '(' expr ')' stmt %prec IFX  { $$ = subNode(IF, 2, $3, $5); }
	| IF '(' expr ')' stmt ELSE stmt  { $$ = subNode(IF, 3, $3, $5, $7); }
	| '{' list '}'			  { $$ = $2; }
	;

list	: stmt				  { $$ = subNode(';', 1, $1); }
	| list stmt			  { $$ = addNode($1, $2, $1->value.sub.num); }
	;

expr	: INTEGER			  { $$ = intNode(INTEGER, $1); }
	| VARIABLE			  { $$ = strNode(VARIABLE, $1); }
	| '-' expr %prec UMINUS		  { $$ = subNode(UMINUS, 1, $2); }
	| expr '+' expr			  { $$ = subNode('+', 2, $1, $3); }
	| expr '-' expr			  { $$ = subNode('-', 2, $1, $3); }
	| expr '*' expr			  { $$ = subNode('*', 2, $1, $3); }
	| expr '/' expr			  { $$ = subNode('/', 2, $1, $3); }
	| expr '%' expr			  { $$ = subNode('%', 2, $1, $3); }
	| expr '<' expr			  { $$ = subNode('<', 2, $1, $3); }
	| expr '>' expr			  { $$ = subNode('>', 2, $1, $3); }
	| expr GE expr			  { $$ = subNode(GE, 2, $1, $3); }
	| expr LE expr			  { $$ = subNode(LE, 2, $1, $3); }
	| expr NE expr			  { $$ = subNode(NE, 2, $1, $3); }
	| expr EQ expr			  { $$ = subNode(EQ, 2, $1, $3); }
	| '(' expr ')'			  { $$ = $2; }
	;

%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
