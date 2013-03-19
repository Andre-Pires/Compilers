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

	/* auxiliary structure */
	typedef struct {
	    int ln;		 	/* line number    */
	    YY_BUFFER_STATE buffer;	/* lexer's buffer state */
	} lbuffer;

	/* data-types */
	lbuffer info[MAX_INCLUDES];
	FILE *yyintmp=NULL;
	char *fname="";
	int ptr=0;

	/* prototypes */
	void store_filename();
	void got_include();
	void manage_eof();

%}
%option yylineno
%x comment
%x include
%x include_end

/*** regular expressions ***/
int		"int"
char		"char"
void		"void"
struct		"struct"
float		"float"
pointer		"->"
digit		[0-9]
letter		[a-zA-Z_]
number		[+-]?({digit})+
fnumber		({number})(".")({digit})+
identifier	({letter})({digit}|{letter})*
if		"if"
else		"else"
while		"while"
typedef		"typedef"
return		"return"
sizeof		"sizeof"
and_op		"&&"
or_op		"||"
eq_op		"=="
ne_op		"!="
ge_op		">="
le_op		"<="
gt_op		">"
lt_op		"<"
right_assign	">>="
left_assign	"<<="
add_assign	"+="
sub_assign	"-="
mult_assign	"*="
div_assign	"/="
mod_assign	"%="
and_assign	"&="
xor_assign	"^="
or_assign	"|="
right_op	">>"
left_op		"<<"
inc_op		"++"
dec_op		"--"
comment_start	"/*"
comment_end	"*/"
newline		"\n"
wspace		(" "|"\t")+
include_start	("#")({wspace})*("include")({wspace})*("<"|"\"")
others		("<"|">"|"&"|"("|")"|"+"|"-"|"*"|"/"|"~"|";"|","|"="|"{"|"}"|"["|"]")

%%

{pointer}		return PTR_OP;
{int}			return INT;
{char}			return CHAR;
{void}			return VOID;
{float}			return FLOAT;
{struct}		return STRUCT;
{if}			return IF;
{else}			return ELSE;
{typedef}		return TYPEDEF;
{while}			return WHILE;
{return}		return RETURN;
{sizeof}		return SIZEOF;
{and_op}		return AND_OP;
{or_op}			return OR_OP;
{eq_op}			return EQ_OP;
{ne_op}			return NE_OP;
{ge_op}			return GE_OP;
{le_op}			return LE_OP;
{right_assign}		return RIGHT_ASSIGN;
{left_assign}		return LEFT_ASSIGN;
{add_assign}		return ADD_ASSIGN;
{sub_assign}		return SUB_ASSIGN;
{mult_assign}		return MUL_ASSIGN;
{div_assign}		return DIV_ASSIGN;
{mod_assign}		return MOD_ASSIGN;
{and_assign}		return AND_ASSIGN;
{xor_assign}		return XOR_ASSIGN;
{or_assign}		return OR_ASSIGN;
{right_op}		return RIGHT_OP;
{left_op}		return LEFT_OP;
{inc_op}		return INC_OP;
{dec_op}		return DEC_OP;
{wspace}		/* ignore whitespaces */
{number}		{
			    yylval.node.type = INT;
			    return CONSTANT;
			}
{fnumber}		{
			    yylval.node.type = FLOAT;
			    return CONSTANT;
			}
{identifier}		{
			    yylval.node.type = IDENTIFIER;
			    yylval.node.id = (char*)strdup(yytext);
			    return IDENTIFIER;
			}
{newline}		info[ptr].ln++;
{others}  		YYTEXT_TO_INT;
{comment_start}		BEGIN comment;
^{include_start}	BEGIN include;
.			ECHO;

<comment>.			/* ignore comment */
<comment>{newline}		info[ptr].ln++;
<comment>{comment_end}		BEGIN INITIAL;

<include>[^(">"|"\""|"\n")]+ 	{ store_filename(); BEGIN include_end; }
<include_end>(">"|"\"")		{ got_include(); BEGIN INITIAL; }

<include>(">"|"\"")		{ /*error*/ BEGIN INITIAL; }
<include>{newline}		{ /*error*/ info[ptr].ln++; BEGIN INITIAL; }
<include_end>{newline}		{ /*error*/
				    info[ptr].ln++;
				    printf("%s", fname);
				    BEGIN INITIAL;
				}

<<EOF>> 	{   /* end of the *actual* buffer */
		    ptr--;
		    if(ptr<0) yyterminate();
		    else manage_eof();
		}

%%

void store_filename(){
    fname=yytext;
    yyintmp=fopen(yytext,"r");
}
void got_include(){
    if(ptr<MAX_INCLUDES && (yyintmp!=NULL)) {
	info[ptr].buffer=YY_CURRENT_BUFFER;
	ptr++;
	/* check up another file */
	info[ptr].ln=1;
	yylineno=1;
	yy_switch_to_buffer(yy_create_buffer(yyintmp,YY_BUF_SIZE));
    }
}
void manage_eof(){
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yy_switch_to_buffer(info[ptr].buffer);
    yylineno=info[ptr].ln;
}

/* yywrap just for debugging */
int yywrap(void) { return 1; }


/* main engine *
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
} **/
