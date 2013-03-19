%{
/* definitions of constants */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

#define PV ';'
#define PCA '{'
#define PCF '}'
#define VI ','
#define IG '='
#define PA '('
#define PF ')'
#define ECM '&'
#define TIL '~'
#define SUB '-'
#define SOM '+'
#define MUL '*'
#define DIV '/'
#define LB '['
#define RB ']'

/* -------------------------------------- */
/* -- change the use of yylineno stack -- */
/* -------------------------------------- */
#define MAX_INCLUDE_DEPTH 20
YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
int lineno_stack[MAX_INCLUDE_DEPTH];
int include_stack_ptr = 0;

%}
%option		yylineno
/* regular definitions */
delim 		[\t\n" "]
ws		{delim}+
letter		[A-Za-z\_]
digit		[0-9]
id		{letter}({letter}|{digit})*
number		(\+|\-)?{digit}+
include		\#"include"[\t" "]*[\<\"]

%x incl comment
%%		
{ws}		{ /* no action no return */ }
";"		{ return (PV); }
"{"		{ return (PCA); }
"}"		{ return (PCF); }
","		{ return (VI); }
"="		{ return (IG); }
"("		{ return (PA); }
")"		{ return (PF); }
"&"		{ return (ECM); }
"~"		{ return (TIL); }
"-"		{ return (SUB); }
"+"		{ return (SOM); }
"*"		{ return (MUL); }
"/"		{ return (DIV); }
"<"		{ return (LT_OP); }
"<="		{ return (LE_OP); }
">"		{ return (GT_OP); }
">="		{ return (GE_OP); }
"["		{ return (LB); }
"]"		{ return (RB); }
sizeof		{ return(SIZEOF); }
"->"		{ return(PTR_OP); }
"!="		{ return(NE_OP); }
"=="		{ return(EQ_OP); }
"&&"		{ return(AND_OP); }
"||"		{ return(OR_OP); }
typedef		{ return(TYPEDEF); }
int		{ return(INT); }
char		{ return(CHAR); }
void		{ return(VOID); }
struct		{ return(STRUCT); }
if		{ return(IF); }
else		{ return(ELSE); }
while		{ return(WHILE); }
return		{ return(RETURN); }
{number} 	{ yylval.i = atoi(yytext);return(CONSTANT); }
{include}       { BEGIN(incl); }
"/*"		{ BEGIN(comment); }
{id}		{ yylval.s = strdup(yytext);return(IDENTIFIER); }

<incl>({letter}|{digit})+(\.)*({letter}|{digit})*[\>\"] {
	
	if(include_stack_ptr >= MAX_INCLUDE_DEPTH) {
		fprintf(stderr, "Includes nested too deeply" );
		exit(1);
	}
	
	yytext[strlen(yytext)-1] = '\0';
	
	FILE *yyintmp;
	
	yyintmp = fopen(yytext, "r"); 
	
	if (yyintmp != NULL) {
/*/		YY_CURRENT_BUFFER->yy_bs_lineno = yylineno; */
		lineno_stack[include_stack_ptr] = yylineno;
		include_stack[include_stack_ptr++] = YY_CURRENT_BUFFER;
		yylineno = 1;
		yyin = yyintmp;
		yyintmp = NULL;
		yy_switch_to_buffer(yy_create_buffer(yyin, YY_BUF_SIZE));
	}
	
	BEGIN(INITIAL);
	
}
<<EOF>> {
	
	if ( --include_stack_ptr < 0 ) {
		yyterminate();
	}
	else {
		yy_delete_buffer( YY_CURRENT_BUFFER );
	/*	yylineno = include_stack[include_stack_ptr]->yy_bs_lineno; */
		yylineno = lineno_stack[include_stack_ptr]; 
            	yy_switch_to_buffer(include_stack[include_stack_ptr]);
	}
	
	BEGIN(INITIAL);
	
}
<comment>(.|\n)
<comment>"*/" {
	
	BEGIN(INITIAL);
	
}	

%%

int yywrap() { return 1; }
