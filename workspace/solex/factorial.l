%{
/* factorial.l,v 1.0 2013/02/18 12:00:00 */
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#define MAXIMO 2147483647

void yyerror(char *s);
int nested;
char string[200];
char * buffer;
%}

DECIMAL 0|[1-9][0-9]*
OCTAL 0[0-9]+
BIN (0b|0B)(0|1)+
EXP [Ee][+-]?{DECIMAL}
REAL {DECIMAL}"."{DECIMAL}{EXP}?


%x COMMENTS STR

%%

"++"				return INC;
"--"				return DEC;
":="				return ATRIB;
"="					return EQ;
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

[ \t\n\r]+		;	/* ignore whitespace */

"==".*\n		;	/*Comentarios linha*/

"=<"					{BEGIN COMMENTS; nested = 0; /*Comentarios extensos*/}
<COMMENTS>"=<" 				{++nested;}
<COMMENTS>"=>"				{if(--nested <= 0) BEGIN INITIAL;}
<COMMENTS>.|\n				;

[A-Za-z][A-Za-z0-9_]*		{ yylval.s = strdup(yytext); return IDENTIF; /* Identificador */}

\"						{ BEGIN STR; buffer = (char *) malloc(sizeof(char)); buffer[0] = '\0';}
<STR>\\n					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\n"); }
<STR>\\t					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\t"); }
<STR>\\r					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\r"); }
<STR>\\\"					{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + 2)); strcat(buffer, "\""); }
<STR>([^"\\])|(\\[0-9a-fA-F][0-9a-fA-F]?)	{ buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + strlen(yytext) + 1)); strcat(buffer, yytext); }
<STR>\"						{ BEGIN INITIAL; yytext[yyleng-1] = 0;
					  			buffer = (char *) realloc(buffer, sizeof(char) * (strlen(buffer) + strlen(yytext) + 1)); 
					 			strcat(buffer, yytext); yylval.s = strdup(buffer); return STRING;}
<STR>.						yyerror("Unknown character");






{OCTAL}|{DECIMAL}|{BIN}	{ if(atoi(yytext) == MAXIMO && yytext[yyleng-1] != '7')  /* devia ser o strtol pq ele da errange
					   {
						sprintf(string, "Lexical error: Value %s caused overflow", yytext);
						yyerror(string);  
					   }
					   yylval.i = atoi(yytext); return INTEGER;  }






{REAL}						{ yylval.d = strtol(yytext, 0, 10); return NUMBER; /* Literal - Real */}
[-+*/%<>=!|&~]				return *yytext; /* Operadores de expressoes */
[#\[\]{}();,]				return *yytext; /* Delimitadores e separadores */

.							yyerror("Unknown character");

%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }