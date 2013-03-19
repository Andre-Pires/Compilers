%{
/* $Id: lingen.y,v 1.9 2011/07/14 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
/* ETIQ + subNode(';', 2, */

void evaluate(Node *p);
void yyerror(char *s);
int lbl;
static char *mklbl(int n);
%}

%union {
	int i;			/* integer value */
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

%token LABEL JMP JZ JNZ ETIQ
%%

program	: PROGRAM list END		  { evaluate($2); freeNode($2); }
	;

stmt	: ';'				  { $$ = 0; }
	| PRINT STRING ';'		  { $$ = strNode(STRING, $2); }
	| PRINT expr ';'		  { $$ = subNode(PRINT, 1, $2); }
	| READ VARIABLE ';'		  { $$ = strNode(READ, $2); }
	| VARIABLE '=' expr ';'		  { $$ = subNode('=', 2, strNode(VARIABLE, $1), $3);}
	| WHILE '(' expr ')' stmt	  { int lbl1 = ++lbl, lbl2 = ++lbl;
			  $$ = subNode(';', 2, strNode(JMP, mklbl(lbl1)),
				 subNode(';', 2, strNode(LABEL, mklbl(lbl2)),
				 subNode(';', 2, $5, /* instr */
				 subNode(';', 2, strNode(LABEL, mklbl(lbl1)),
				   subNode(JNZ, 2, $3 /* cond */,
				     strNode(ETIQ, mklbl(lbl2)))))));
					  }
	| IF '(' expr ')' stmt %prec IFX  { int lbl1 = ++lbl;
			  $$ = subNode(';', 2, subNode(JZ, 2, $3 /* cond */,
						 strNode(ETIQ, mklbl(lbl1))),
				 subNode(';', 2, $5, /* instr */
				   strNode(LABEL, mklbl(lbl1))));
					  }
	| IF '(' expr ')' stmt ELSE stmt  { int lbl1 = ++lbl, lbl2 = ++lbl;
			  $$ = subNode(';', 2, subNode(JZ, 2, $3 /* cond */,
						 strNode(ETIQ, mklbl(lbl1))),
				 subNode(';', 2, $5, /* instr */
				 subNode(';', 2, strNode(JMP, mklbl(lbl2)),
				 subNode(';', 2, strNode(LABEL, mklbl(lbl1)),
				 subNode(';', 2, $7, /* else */
				   strNode(LABEL, mklbl(lbl2)))))));
					  }
	| '{' list '}'			  { $$ = $2; }
	;

list	: stmt				  { $$ = $1; }
	| list stmt			  { $$ = subNode(';', 2, $1, $2); }
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
static char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strdup(buf);
}
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
