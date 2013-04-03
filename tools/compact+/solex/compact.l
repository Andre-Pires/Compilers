%{ 
/* $Id: compact.l,v 1.8 2012/02/15 01:13:32 prs Exp $ */
/* (Compact with functions included as instructions) */
#include <stdlib.h> 
#include <string.h> 
#include "y.tab.h" 
void yyerror(char *s);
%} 

%% 
"#".*			; /* comment */
">="			return GE; 
"<="			return LE; 
"=="			return EQ; 
"!="			return NE; 
"while"			return WHILE; 
"if"			return IF; 
"else"			return ELSE; 
"print"			return PRINT; 
"read"			return READ; 
"program"		return PROGRAM; 
"function"		return FUNC; 
"end"			return END; 
"return"		return RETURN; 

[A-Za-z][A-Za-z0-9_]*	{ yylval.s = strdup(yytext); return VARIABLE; } 
\'[^']*\'		{ yytext[yyleng-1] = 0; yylval.s = strdup(yytext+1); return STRING; }
[0-9]+			{ yylval.i = strtol(yytext, 0, 10); return INTEGER; } 
[-<>=+*/%;{}.(),]	return *yytext; 
 
[ \t\n\r]+		; /* ignore whitespace */ 
 
.			yyerror("Unknown character"); 
%% 
int yywrap(void) { return 1; } 
char *getyytext() { return yytext; }
