%{ 
/* yak.l,v 1.0 2012/04/11 13:23:00 */
#include <stdlib.h> 
#include <string.h> 
#include "y.tab.h"  
void yyerror(char *s);
int nested;
%} 

DECIMAL 0|[1-9][0-9]*
HEXA (0x|0X)[A-Fa-f0-9]+
OCTAL 0[0-7]+

%x COMMENTS

%% 
"++"				return INC;
"--"				return DEC;
"**"				return POWER;
":="				return ATRIB;
"=="				return EQ;
">="				return GE;
"<="				return LE;
"<>"				return NE;
"program"			return PROGRAM; 
"module"			return MODULE; 
"import"			return IMPORT; 
"export"			return EXPORT; 
"number"			return NUMBER; 
"string"			return STRING; 
"function"			return FUNCTION; 
"vector"			return VECTOR; 
"const"				return CONST; 
"read"				return READ; 
"write"				return WRITE; 
"if"				return IF; 
"elif"				return ELIF; 
"else"				return ELSE; 
"loop"				return LOOP; 
"again"				return AGAIN;
"next"				return NEXT;  
"return"			return RETURN; 

[ \t\n\r]+		; /* ignore whitespace */ 

"//".*\n		;/*Comentarios linha*/

"<<"	{BEGIN COMMENTS; nested = 0; /*Comentarios extensos*/}
<COMMENTS>"<<" 	{++nested;}
<COMMENTS>">>"	{if(--nested <= 0) BEGIN INITIAL;}
<COMMENTS>.|\n	;

[A-Za-z][A-Za-z0-9_]*		{ yylval.s = strdup(yytext); return IDENTIF; /* Identificador */} 
\"[^"]*|(\")*\"				{ yytext[yyleng-1] = 0; yylval.s = strdup(yytext+1); return STRING; /*String */}
{OCTAL}						{ yylval.i = strtol(yytext, 0, 8); return NUMBER; /* Literal - Octal */} 
{DECIMAL}					{ yylval.i = strtol(yytext, 0, 10); return NUMBER; /* Literal - Inteiro */} 
{HEXA}						{ yylval.i = strtol(yytext, 0, 16); return NUMBER; /* Literal - Hexadecimal */} 
[-+*/%<>=!|&]				return *yytext; /* Operadores de expressoes */ 
[#\[\]{}();:.,]				return *yytext; /*Delimitadores e separadores */ 

.			yyerror("Unknown character"); 

%% 
int yywrap(void) { return 1; } 
char *getyytext() { return yytext; }
