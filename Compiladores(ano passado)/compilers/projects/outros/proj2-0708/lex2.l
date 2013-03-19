/*****************************
   Compilers, Spring 2008
   IST-TagusPark
  
   Project2: file "lex2.l"
  
    »» THE SCANNER ««
  --------------------------
    Nuno AJ de Aniceto
    nº 57682
*****************************/

%{
    /* headers */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tokens.h"

    /* Max depth of files to be included */
    #define MAX_INCLUDES 25

    /* tokenizer */
    #ifndef YYTEXT_TO_INT
    #define YYTEXT_TO_INT { return (int) yytext[0]; }
    #endif

    /* variables */    
    int line_numbers[MAX_INCLUDES];
    FILE *including_file;
    char *including_filename="";
    int line=1;

    /* buffers */
    YY_BUFFER_STATE array_includes[MAX_INCLUDES];
    int including_file_ptr=0;
    int ready_to_include=0;

    /* parsing step */
    YYSTYPE yylval;

%}
%x comment
%x get_filename include_end

/*** Regular Expressions ***/

int             ("int")
char            ("char")
void            ("void")
struct          ("struct")
pointers        ("->")
digit           [0-9]
integer         [+-]?({digit})+
letter          [a-zA-Z_]
identifier      {letter}({digit}|{letter})*
alphanumeric    ({identifier}|({digit})+)
if              ("if")
else            ("else")
typedef         ("typedef")
while           ("while")
return          ("return")
sizeof          ("sizeof")
and             ("&&")
or              ("||")
gt              (">")
lt              ("<")
eq              ("==")
ne              ("!=")
ge              (">=")
le              ("<=")
cx_start        ("/*")
cx_end          ("*/")
newline         ("\n")
wspace          (" "|"\t")
incl_start      (("#")({wspace})*("include")({wspace})*("<"|"\""))
others		("&"|"("|")"|"*"|"+"|"-"|"/"|";"|","|"="|"["|"]"|"{"|"}"|"~")

/*** End of Reg Exp ***/

%%

{newline}       line++;
{wspace}        /* do nothing - scanner will eat the whitespaces */
{pointers}      return PTR_OP;
{int}           return INT;
{char}          return CHAR;
{void}          return VOID;
{struct}        return STRUCT;
{integer}       { yylval.i = atoi(yytext); return CONSTANT; }
{if}            return IF;
{else}          return ELSE;
{typedef}       return TYPEDEF;
{while}         return WHILE;
{return}        return RETURN;
{sizeof}        return SIZEOF;
{identifier}    { yylval.s = strdup(yytext); return IDENTIFIER; }
{and}           return AND_OP;
{or}            return OR_OP;
{gt}            return GT_OP;
{lt}            return LT_OP;
{eq}            return EQ_OP;
{ne}            return NE_OP;
{ge}            return GE_OP;
{le}            return LE_OP;
{others}  	YYTEXT_TO_INT;
{cx_start}      BEGIN comment;
^{incl_start}   BEGIN get_filename;
.               ECHO;

<comment>.          /* eat any comment */
<comment>{newline}  line++;
<comment>{cx_end}   BEGIN INITIAL;

<get_filename>[^(">"|"\""|"\n")]+      {
    /* got filename */
    including_filename=yytext;
    if(including_file=fopen(yytext,"r")) ready_to_include=1;
    BEGIN include_end;
}

<get_filename>(">"|"\"").*        BEGIN INITIAL;

<get_filename>{newline}      {
    line++; /* got a newline */
    BEGIN INITIAL;
}

<include_end>[^(">"|"\""|"\n")]+        BEGIN INITIAL;

<include_end>("\n")       {
    /* printf("%s",including_filename); */
    BEGIN INITIAL;
}

<include_end>(">"|"\"")     {
    if (including_file_ptr<MAX_INCLUDES && ready_to_include) {
        /* manage buffers to be resumed */
        line_numbers[including_file_ptr]=line;
        array_includes[including_file_ptr]=YY_CURRENT_BUFFER;
        including_file_ptr+=1;
        /* resuming */
        line=1;
        ready_to_include=0;
        yy_switch_to_buffer(yy_create_buffer(including_file,YY_BUF_SIZE));
        BEGIN INITIAL;
    }
}

<<EOF>> {
    including_file_ptr-=1;
    if(including_file_ptr<0) yyterminate();
    else {
        /* resumes the buffer */
        line=line_numbers[including_file_ptr];
        yy_delete_buffer(YY_CURRENT_BUFFER);
        yy_switch_to_buffer(array_includes[including_file_ptr]);
    }
}

%%

/*** C code ***/

/* yywrap just for debugging */
int yywrap(void) { return 1; }

 
/**
int checkup(char* filename) {
    int tok, n;
    n=0;
    yyin = fopen(filename,"r");
    while(1) {
        if(!(tok = yylex())) break;
        printf("%d %d %s\n", line, tok, yytext);
        n++;
    }
    fclose(yyin);
    return n;
}

int main(int argc, char* argv[], char *envp[]) {
    int tok, n;
    n=0;
    if (argv[1]) n=checkup(argv[1]);
    else while(1) {
        if(!(tok = yylex())) break;
        printf("%d %d %s\n", line, tok, yytext);
        n++;
    }
    printf("#Total Number of Tokens Matched was %d\n",n);
    return 0;
}
/**/
/*** The End ***/
