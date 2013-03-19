%{ 
/* factorial.l,v 1.0 2013/02/18 12:00:00 */
#include <stdlib.h> 
#include <string.h> 
#include "y.tab.h"  
void yyerror(char *s);
int nested;
%} 

DECIMAL 0|[1-9][0-9]*
OCTAL 0[0-9]+
BIN 0b(0|1)+
EXP [Ee][+-]?{DECIMAL}
REAL {DECIMAL}"."{DECIMAL}({EXP})?


%x COMMENTS

%%
"++"				return INC;
"--"				return DEC;
":="				return ATRIB;
"=="				return EQ;
">="				return GE;
"<="				return LE;
"<>"				return NE;
"void"				return VOID;
"integer"			return INTEGER;
"string"			return STRING;
"public"			return PUBLIC;
"number"			return NUMBER;
"const"				return CONST;
"if"				return IF;
"then"				return THEN;
"else"				return ELSE;
"while"				return WHILE;
"do"				return DO;
"for"				return FOR;
"in"				return IN;
"step"				return STEP;
"upto"				return UPTO;
"downto"			return DOWNTO;
"break"				return BREAK;
"continue"			return CONTINUE;

[ \t\n\r]+		; /* ignore whitespace */ 

"==".*\n		;/*Comentarios linha*/

"=<"	{BEGIN COMMENTS; nested = 0; /*Comentarios extensos*/}
<COMMENTS>"=<" 	{++nested;}
<COMMENTS>"=>"	{if(--nested <= 0) BEGIN INITIAL;}
<COMMENTS>.|\n	;

[A-Za-z][A-Za-z0-9_]*		{ yylval.s = strdup(yytext); return IDENTIF; /* Identificador */} 
\"[^"]*|(\")*\"				{ yytext[yyleng-1] = 0; yylval.s = strdup(yytext+1); return STRING; /*String */}
{OCTAL}						{ yylval.i = strtol(yytext, 0, 8); return INTEGER; /* Literal - Octal */} 
{DECIMAL}					{ yylval.i = strtol(yytext, 0, 10); return INTEGER; /* Literal - Inteiro */} 
{BIN}						{ yylval.i = strtol(yytext, 0, 2); return INTEGER; /* Literal - Binario */}
{REAL}						{ yylval.i = strtol(yytext, 0, 36); return NUMBER; /* Literal - Real !!!!!!!!! Qual é a base? !!!!!!!!*/}
[-+*/%<>=!|&~]				return *yytext; /* Operadores de expressoes */ 
[#\[\]{}();,]				return *yytext; /*Delimitadores e separadores */ 

.							yyerror("Unknown character"); 

%% 
int yywrap(void) { return 1; } 
char *getyytext() { return yytext; }