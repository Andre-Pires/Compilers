/*****************************
   Compilers, Spring 2008
   IST-TagusPark
  
   Project2: file "yacc2.y"
  
    »» THE PARSER ««
  ----------------------
    Nuno AJ de Aniceto
    no 57682
*****************************/

%{
    /* headers */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "node.h"
    
    /* macros */
    #define MAX_FUNCTIONS 75

    /* references */
    extern FILE *yyin;
    extern int line;

    /* aux variables */
    int i, j;
    int fi, ai; /* indexes */
    int debug;
    
    /* information data */
    int top_lvl_decl;
    typedef struct {
        char* function;
        int argsno;
        int declarations;
        int statements;
        int binary_ops;
        char* args[16];
        int value_return;
    } f_info;
    f_info info[MAX_FUNCTIONS];

%}

%union {
      int i;
      char* s;
      struct typeNode *n;
    }

%token IDENTIFIER CONSTANT TYPEDEF INT CHAR VOID STRUCT IF ELSE WHILE RETURN SIZEOF COMMA SEMICOLON
%token PTR_OP LT_OP GT_OP LE_OP GE_OP ARRAY_OP NE_OP EQ_OP AND_OP OR_OP ADD_OP SUB_OP MULT_OP DIV_OP

/************  parsing tree:  tokens not returned from the lexer   ************/
%token STRUCT_DECL_LIST COMPOUND STATE FUNCTION DECLARATION FUNCTION_DEFINITION
%token PROGRAM EXPR_LIST TYPE_SPECIFIER DIRECT_DECL PARAM NEG EXPR TOPLD VALUE
%token DECL DECLARATOR ARRAY_DECL IF_ELSE PARAM_FUNCTION TYPED_STR_ID TYPED_STR
/******************************************************************************/

%nonassoc STATE
%nonassoc IF
%nonassoc ELSE

%type <n> program toplevel_declaration declaration function_definition direct_function function_call
%type <n> type_specifier struct_decl_list declarator direct_declarator parameter_list argument_list
%type <n> statement compound_statement declaration_list statement_list expression unary_expression
%type <n> unary value ops if_statement if_clause initial

%type <s> IDENTIFIER STRUCT CHAR VOID INT COMMA SEMICOLON TYPEDEF RETURN WHILE SIZEOF EXPR IF ELSE
%type <s> PTR_OP LT_OP GT_OP LE_OP GE_OP ARRAY_OP NE_OP EQ_OP AND_OP OR_OP ADD_OP SUB_OP MULT_OP DIV_OP
%type <i> CONSTANT

/*** precedences ***/
%right '=' PTR_OP
%left '*' '/' '+' '-'
/*******************/

%start initial

%%

initial: 
            program
{ 
    switch(debug) {
            case 1:
                printf("Top level: %d declarations.\n", top_lvl_decl);
                for(i=0; i<fi; i++) {
                    printf("%s (%d): %d declarations, %d statements, %d binary operations.\n \\\\* args: ", info[i].function, info[i].argsno, info[i].declarations, info[i].statements, info[i].binary_ops);
                    for(j=(info[i].argsno-1); j>=0; j--) printf("\'%s\' ", info[i].args[j]);
                    printf("*//\n");
                }
            break;
            default:
                printf("Top level: %d declarations.\n", top_lvl_decl);
                for(i=0; i<fi; i++) {
                    printf("%s: ", info[i].function);
                    printf("%d declarations, ", info[i].declarations);
                    printf("%d statements, ", info[i].statements);
                    printf("%d binary operations.\n", info[i].binary_ops);
                }
            break;
        }
 }
       ;
program:
            function_definition
                { $$=$1; subNode(PROGRAM, 1, $1); }
        |   function_definition program
                { $$=subNode(PROGRAM,2,$1,$2); }
        |   toplevel_declaration
                { top_lvl_decl++; $$=subNode(PROGRAM, 1, $1);}
        |   toplevel_declaration program
                { top_lvl_decl++; $$=subNode(PROGRAM,2,$1,$2); }
        ;

toplevel_declaration:
            type_specifier ';'
                { $$=subNode(TOPLD, 1, $1); }
        |   type_specifier declarator ';'
                { $$=subNode(TOPLD , 2, $1, $2); }
        ;

declaration:
            type_specifier ';'
                { info[fi].declarations++; $$=subNode(DECLARATION, 1, $1); }
        |   type_specifier declarator ';'
                { info[fi].declarations++; $$=subNode(DECLARATION, 2, $1, $2); }
        ;

declaration_list:
            declaration
                { $$=subNode(DECL, 1, $1); }
        |   declaration_list declaration
                { $$=subNode(DECL, 2, $1, $2); }
        ;

function_definition:
            type_specifier declarator compound_statement
                { fi++; $$=subNode(FUNCTION_DEFINITION, 3, $1, $2, $3);}
        ;

type_specifier:
            VOID
                { $$=nilNode(VOID); }
        |   INT
                { $$=nilNode(INT); }
        |   CHAR
                { $$=nilNode(CHAR); }
        |   STRUCT IDENTIFIER '{' struct_decl_list '}'
                { $$=subNode(STRUCT, 3, strNode(STRUCT, $1), strNode(IDENTIFIER, $2), $4); }
        |   STRUCT IDENTIFIER
                { $$=subNode(STRUCT, 2, strNode(STRUCT, $1), strNode(IDENTIFIER, $2)); }
        |   TYPEDEF STRUCT '{' struct_decl_list '}' IDENTIFIER
                { $$=subNode(TYPED_STR, 4, strNode(STRUCT, $1), strNode(IDENTIFIER, $2), $4, strNode(IDENTIFIER, $6)); }
        |   TYPEDEF STRUCT IDENTIFIER '{' struct_decl_list '}' IDENTIFIER
                { $$=subNode(TYPED_STR_ID, 4, strNode(STRUCT, $1), strNode(IDENTIFIER, $2), strNode(IDENTIFIER, $3), $5, strNode(IDENTIFIER, $7)); }
        ;

struct_decl_list:
            type_specifier declarator ';'
                { $$=subNode(STRUCT_DECL_LIST, 2, $1, $2); }
        |   type_specifier declarator ';' struct_decl_list
                { $$=subNode(STRUCT_DECL_LIST, 3, $1, $2, $4); }
        |   type_specifier declarator '=' CONSTANT ';'
                { $$=subNode(STRUCT_DECL_LIST, 3, $1, $2, $4); }
        ;

declarator:
            '*' declarator
                { $$=$2; /** $$=subNode(DECLARATOR, 1, $2); /**/ }
        |   direct_declarator
                { $$=$1; /** $$=subNode(DECLARATOR, 1, $1); /**/ }
        ;

direct_declarator:
            IDENTIFIER
                { /** $$=strNode(IDENTIFIER, $1); /**/ }
        |   IDENTIFIER '(' parameter_list ')'
                { info[fi].function=(char *)$1; $$=subNode(DIRECT_DECL, 2, strNode(IDENTIFIER, $1), $3); }
        |   IDENTIFIER '(' ')'
                { info[fi].function=(char *)$1; $$=subNode(DIRECT_DECL, 1, strNode(IDENTIFIER, $1)); }
        |   IDENTIFIER '[' unary ']'
                { $$=subNode(ARRAY_DECL, 2, strNode(IDENTIFIER, $1), $3); }
        ;

parameter_list:
            type_specifier declarator
                { info[fi].args[ai]=(char *)$2; info[fi].argsno++; $$=subNode(PARAM, 2, $1, $2); }
        |   type_specifier declarator ',' parameter_list
                { ai++; info[fi].args[ai]=(char *)$2; info[fi].argsno++; $$=subNode(PARAM, 3, $1, $2, $4); ai=0; }
        ;

if_statement:
            IF '(' expression ')' if_clause %prec IF
                { $$=subNode(IF, 3, strNode(IF, $1), $3, $5); }
        |   IF '(' expression ')' if_clause ELSE statement
                { $$=subNode(IF_ELSE, 5, strNode(IF, $1), $3, $5, strNode(ELSE, $6), $7); }
        ;

if_clause:
            statement %prec STATE
                { $$=$1; }
        ;

statement:
            unary_expression '=' expression ';'
                { info[fi].statements++; $$=subNode('=', 2, $1, $3); }
        |   WHILE '(' expression ')' statement
                { info[fi].statements++; $$=subNode(WHILE, 3, strNode(WHILE, $1), $3, $5); }
        |   RETURN expression ';'
                { info[fi].statements++; $$=subNode(RETURN, 2, strNode(RETURN, $1), $2); }
        |   if_statement
                { info[fi].statements++; $$=$1; }
        |   ';'
                { info[fi].statements++; $$=nilNode(';'); }
        |   compound_statement
                { $$=subNode(COMPOUND, 1, $1); }
        |   function_call ';'
                { info[fi].statements++; $$=$1; }
        ;

compound_statement:
            '{'  '}'
                { }
        |   '{'  declaration_list '}'
                { $$=subNode(DECL, 1, $2); }
        |   '{'  statement_list '}'
                { $$=subNode(STATE, 1, $2); }
        |   '{'  declaration_list statement_list '}'
                { $$=subNode(COMPOUND, 2, $2, $3); }
        ;

statement_list:
            statement
                { $$=$1; }
        |   statement statement_list
                { $$=subNode(STATE, 2, $1, $2); }
        ;

argument_list:
            expression
                { $$=$1; }
        |   expression ',' argument_list
                { $$=subNode(EXPR_LIST, 2, $1, $3); }
        |   STRUCT IDENTIFIER
                { $$=subNode(EXPR_LIST, 2, strNode(STRUCT, $1), strNode(IDENTIFIER, $2)); }
        |   STRUCT IDENTIFIER ',' argument_list
                { $$=subNode(EXPR_LIST, 3, strNode(STRUCT, $1), strNode(IDENTIFIER, $2), $4); }
        ;

direct_function:
            IDENTIFIER '(' argument_list ')'
                { $$=subNode(FUNCTION, 2, strNode(IDENTIFIER, $1), $3); }
        |   IDENTIFIER '(' ')'
                { $$=subNode(FUNCTION, 1, strNode(IDENTIFIER, $1)); }
        ;

function_call:
            direct_function         { $$=$1; }
        |   '*' function_call       { $$=subNode('*', 1, $2); }
        |   '&' function_call       { $$=subNode('&', 1, $2); }
        |   '~' function_call       { $$=subNode('~', 1, $2); }
        ;

expression:
            expression ops unary_expression
                { info[fi].binary_ops++; $$=subNode(EXPR, 3, $1, $2, $3); }
        |   expression ops function_call
                { info[fi].binary_ops++; $$=subNode(EXPR, 3, $1, $2, $3); }
        |   '(' expression ')'
                { $$=$2; }
        |   unary_expression
                { $$=$1; }
        |   function_call
                { $$=$1; }
        ;

ops:
            MULT_OP     { $$=strNode(MULT_OP, $1); }
        |   DIV_OP      { $$=strNode(DIV_OP, $1); }
        |   ADD_OP      { $$=strNode(ADD_OP, $1); }
        |   SUB_OP      { $$=strNode(SUB_OP, $1); }
        |   LT_OP       { $$=strNode(LT_OP, $1); }
        |   GT_OP       { $$=strNode(GT_OP, $1); }
        |   EQ_OP       { $$=strNode(EQ_OP, $1); }
        |   GE_OP       { $$=strNode(GE_OP, $1); }
        |   LE_OP       { $$=strNode(LE_OP, $1); }
        |   NE_OP       { $$=strNode(NE_OP, $1); }
        |   AND_OP      { $$=strNode(AND_OP, $1); }
        |   OR_OP       { $$=strNode(OR_OP, $1); }
        ;

unary_expression:
            unary PTR_OP unary_expression
                { $$=subNode(EXPR, 3, $1, strNode(PTR_OP, $2), $3); }
        |   value '[' unary_expression ']'
                { $$=subNode(EXPR, 2, $1, $3); }
        |   unary '+' unary_expression
                { info[fi].binary_ops++; $$ = subNode(ADD_OP, 2, $1, $3); }
        |   unary '-' unary_expression
                { info[fi].binary_ops++; $$ = subNode(SUB_OP, 2, $1, $3); }
        |   unary '*' unary_expression
                { info[fi].binary_ops++; $$ = subNode(MULT_OP, 2, $1, $3); }
        |   unary '/' unary_expression
                { info[fi].binary_ops++; $$ = subNode(DIV_OP, 2, $1, $3); }
        |   SIZEOF '(' type_specifier ')'
                { $$=subNode(SIZEOF, 2, strNode(SIZEOF, $1), $3); }
        |   '~' unary_expression
                { $$ = subNode('~', 1, $2); }
        |   '-' unary_expression
                { $$=subNode(NEG,1, $2); }
        |   '+' unary_expression
                { $$=$2; }
        |   unary
                { $$=$1; }
        ;

unary:
            CONSTANT        { $$=intNode(CONSTANT, $1); }
        |   value           { $$=subNode(VALUE, 1, $1); }
        ;

value:
            IDENTIFIER      { $$=strNode(IDENTIFIER, $1); }
        |   '&' value       { $$=subNode('&', 1, $2); }
        |   '*' value       { $$=subNode('*', 1, $2); }
        ;

%%

int yyerror(char* msg){
    fprintf(stderr, "%s, line %d\n", msg, line);
    return 1;
}

/* code for traversing (dfs) the syntax tree and generating three-address code */
int main(){
    do { yyparse(); }
    while(!feof(yyin));
    return 0;
}
/*** The End ***/
