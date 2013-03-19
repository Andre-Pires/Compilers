/*****************************
	Compilers, Spring 2009
	IST-TagusPark

  miniC compiler;
	The Lexer

  --------------------------
	Nuno AJ de Aniceto
	nº 57682
  --------------------------
*****************************/

%{
	#include "main.h"
	lbuffer info[MAX_INCLUDES];

	FILE *file=NULL;
	char *fname="";
	int ptr=0;

%}
%x comment
%x include
%x include_end

/*** regular expressions ***/
int				"int"
char			"char"
void			"void"
struct			"struct"
pointer			"->"
dot				"."
digit			[0-9]
letter			[a-zA-Z_]
integer			[+-]?({digit})+
identifier		{letter}({digit}|{letter})*
if				"if"
else			"else"
while			"while"
typedef			"typedef"
return			"return"
sizeof			"sizeof"
and				"&&"
or				"||"
gt				">"
lt				"<"
eq				"=="
ne				"!="
ge				">="
le				"<="
comment_start	"/*"
comment_end		"*/"
newline			"\n"
wspace			" "|"\t"
include_start	({wspace})*("#")({wspace})*("include")({wspace})*("<"|"\"")
others			"&"|"("|")"|"+"|"-"|"*"|"/"|"~"|";"|","|"="|"["|"]"|"{"|"}"

%%

{newline}				info[ptr].ln++;
{wspace}				/* ignore whitespaces */
{pointer}				return PTR_OP;
{dot}					return DOT_OP;
{int}					return INT;
{char}					return CHAR;
{void}					return VOID;
{struct}				return STRUCT;
{integer}				return CONSTANT;
{if}					return IF;
{else}					return ELSE;
{typedef}				return TYPEDEF;
{while}					return WHILE;
{return}				return RETURN;
{sizeof}				return SIZEOF;
{identifier}			return IDENTIFIER;
{and}					return AND_OP;
{or}					return OR_OP;
{gt}					return GT_OP;
{lt}					return LT_OP;
{eq}					return EQ_OP;
{ne}					return NE_OP;
{ge}					return GE_OP;
{le}					return LE_OP;
{others}  				YYTEXT_TO_INT;
{comment_start}			BEGIN comment;
^{include_start}		BEGIN include;
.						{ ECHO; }

<comment>.						/* ignore comment */
<comment>{newline}				info[ptr].ln++;
<comment>{comment_end}			BEGIN INITIAL;

<include>[^(">"|"\""|"\n")]+ 	{ store_filename(); BEGIN include_end; }
<include_end>(">"|"\"")			{ got_include(); BEGIN INITIAL; }

<include>{newline}				{ /* error case */ info[ptr].ln++; BEGIN INITIAL; }
<include>(">"|"\"").*			{ /* error case */ BEGIN INITIAL; }
<include_end>{newline}			{ /* error case */ printf("%s", fname); info[ptr].ln++; BEGIN INITIAL; }

<<EOF>> 	{
	ptr--;
	if(ptr<0) yyterminate();
	else manage_eof();
}

%%

int store_filename(){
	fname=yytext;
	file=fopen(yytext,"r");
	return 0;
}
int got_include(){
	if (ptr<MAX_INCLUDES && (file!=NULL)) {
		info[ptr].buffer=YY_CURRENT_BUFFER;
		ptr++;
		/* check up another file */
		info[ptr].ln=1;
		yy_switch_to_buffer(yy_create_buffer(file,YY_BUF_SIZE));
	}
	return 0;
}
int manage_eof(){
	yy_delete_buffer(YY_CURRENT_BUFFER);
	yy_switch_to_buffer(info[ptr].buffer);
	return 0;
}

/* yywrap just for debugging */
int yywrap(void) { return 1; }

/* main engine */
int main(int argc, char* argv[], char *envp[]) {
	int tok, n=0;

	info[ptr].buffer=YY_CURRENT_BUFFER;
	info[ptr].ln=1;

	while(1) {
		if(!(tok = yylex())) break;
		printf("%d %d %s\n", info[ptr].ln, tok, yytext);
		n++;
	}
	printf("#Total Number of Tokens Matched was %d\n",n);

	return 0;
}
