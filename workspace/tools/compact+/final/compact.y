%{
/* $Id: compact.y,v 1.11 2013/02/07 17:25:13 prs Exp $ */
/* (Compact with functions included as instructions) */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include "node.h"
#include "tabid.h"
extern void yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, int value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
char *mklbl(int n); /* generate counter based label */ 
static int arg; /* function argument counter (no call within call) */
static void mkcall(char *func, long eargs); /* check function call */
static Node *mkvar(char *name); /* global vs local access */
%}

%union {
	int i;			/* integer value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
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

%type <n> stmt expr list args listp
%type <i> ids

%token LABEL JMP JZ JNZ ETIQ CALL LOCAL
%%
file	: decls
	| decls PROGRAM list END	{ program(-pos, $3); }
	;

decls	:
	| decls FUNC VARIABLE '(' { IDnew(FUNC, $3, 0); IDpush(); } ids ')'
		{ IDreplace(FUNC, $3, (long)$6); pos = 0; } listp END { IDpop(); function($3, -pos, $9); pos = 0; }
	| decls FUNC VARIABLE '(' ')' { IDnew(FUNC, $3, 0); } listp END { function($3, -pos, $7); pos = 0; }
	| decls VARIABLE ';'			{ declare($2,  0); }
	| decls VARIABLE '=' INTEGER ';'	{ declare($2, $4); }
	| decls VARIABLE '=' '-' INTEGER ';'	{ declare($2, -$5); }
	;

ids	: VARIABLE		{ $$ = 1; IDnew(INTEGER, $1, 8); }
	| ids ',' VARIABLE	{ $$ = $1 + 1; IDnew(INTEGER, $3, 4 + 4 * $$); }
	;

listp	:	{ $$ = 0; }
	| list
	;

stmt	: ';'				{ $$ = nilNode(END); }
	| PRINT STRING ';'		{ $$ = strNode(STRING, $2); }
	| PRINT expr ';'		{ $$ = uniNode(PRINT,$2); }
	| READ VARIABLE ';'	{ $$ = uniNode(READ, mkvar($2));
				  if (IDfind($2, 0) == FUNC)
				    yyerror("read with function argument");
				}
	| VARIABLE '=' expr ';'		{ assign($1);
					  $$ = binNode('=', mkvar($1), $3); }
	| WHILE '(' expr ')' stmt	{ int lbl1 = ++lbl, lbl2 = ++lbl;
	    $$ = seqNode(';', 5,
			strNode(JMP, mklbl(lbl1)),
			strNode(LABEL, mklbl(lbl2)),
			$5, /* instr */
			strNode(LABEL, mklbl(lbl1)),
			binNode(JNZ,$3, strNode(ETIQ, mklbl(lbl2))));
					  }
	| IF '(' expr ')' stmt %prec IFX  { int lbl1 = ++lbl;
	    $$ = seqNode(';', 3,
			binNode(JZ,$3, strNode(ETIQ, mklbl(lbl1))),
			$5, /* instr */
			strNode(LABEL, mklbl(lbl1)));
					  }
	| IF '(' expr ')' stmt ELSE stmt  { int lbl1 = ++lbl, lbl2 = ++lbl;
	    $$ = seqNode(';', 6,
			binNode(JZ,$3, strNode(ETIQ, mklbl(lbl1))),
			$5, /* instr */
			strNode(JMP, mklbl(lbl2)),
			strNode(LABEL, mklbl(lbl1)),
			$7, /* else */
			strNode(LABEL, mklbl(lbl2)));
					  }
	| '{' list '}'			{ $$ = $2; }
	| VARIABLE '=' VARIABLE '(' args ')' {
	     mkcall($3, arg); assign($1);
	     $$ = binNode('=', mkvar($1), binNode(CALL, strNode(VARIABLE, $3), $5)); }
	| VARIABLE '(' args ')'		{
	     mkcall($1, arg);
	     $$ = binNode(CALL, strNode(VARIABLE, $1), $3); }
	| VARIABLE '=' VARIABLE '(' ')'	{
	     mkcall($3, 0); assign($1);
	     $$ = binNode('=', mkvar($1), binNode(CALL, strNode(VARIABLE, $3), nilNode(END))); }
	| VARIABLE '(' ')'		{
	     mkcall($1, 0);
	     $$ = binNode(CALL, strNode(VARIABLE, $1), nilNode(END)); }
	| RETURN expr ';'		{ $$ = uniNode(RETURN, $2); }
	;

list	: stmt				{ $$ = $1; }
	| list stmt			{ $$ = binNode(';', $1, $2); }
	;

args	: expr				{ $$ = $1; arg = 1; }
	| args ',' expr			{ $$ = binNode(',', $3, $1); arg++; }
	;

expr	: INTEGER			{ $$ = intNode(INTEGER, $1); }
	| VARIABLE	{ if (IDfind($1, 0) == FUNC)
			    yyerror("function name in expression");
			  $$ = mkvar($1); }
	| '-' expr %prec UMINUS		{ $$ = uniNode(UMINUS, $2); }
	| expr '+' expr			{ $$ = binNode('+', $1, $3); }
	| expr '-' expr			{ $$ = binNode('-', $1, $3); }
	| expr '*' expr			{ $$ = binNode('*', $1, $3); }
	| expr '/' expr			{ $$ = binNode('/', $1, $3); }
	| expr '%' expr			{ $$ = binNode('%', $1, $3); }
	| expr '<' expr			{ $$ = binNode('<', $1, $3); }
	| expr '>' expr			{ $$ = binNode('>', $1, $3); }
	| expr GE expr			{ $$ = binNode(GE, $1, $3); }
	| expr LE expr			{ $$ = binNode(LE, $1, $3); }
	| expr NE expr			{ $$ = binNode(NE, $1, $3); }
	| expr EQ expr			{ $$ = binNode(EQ, $1, $3); }
	| '(' expr ')'			{ $$ = $2; }
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

static Node *mkvar(char *name) {
  long loc;
  int typ = IDfind(name, &loc); /* find type and offset of the variable */
  if (typ != FUNC && loc != 0) /* global variables have offset==0 */
    return intNode(LOCAL, loc); /* local variables are accessed by offset */
  return strNode(VARIABLE, name); /* global variables are accessed by name */
}

char *mklbl(int n) {
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
