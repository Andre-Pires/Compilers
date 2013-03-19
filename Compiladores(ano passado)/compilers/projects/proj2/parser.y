/*****************************
	Compilers, Spring 2009
	IST-TagusPark

  miniC compiler;
	The Parser

  --------------------------
	Nuno AJ de Aniceto
	nº 57682
  --------------------------
*****************************/
%{
	#include "main.h"
	#include "list.h"

#define token unsigned short int
#define bool unsigned char
#define true 1
#define false 0

	extern int *yylineno;
	extern FILE *yyin;

	/* function type-checking prototypes */
	token ftype;
	void declare_function(token type);
	void check_return(token type);

	/* identifiers type-checking */
	list* id_list;
	void declare(token type, char* id);
	token lookup(char* id);

	/* parsing-time type-checking */
	token check_cond(token type);
	token check_op(token a_type, token b_type, int* warn);
	token check_logic(token a_type, token b_type, int* warn);
	token check_assign(token a_type, token b_type, int* warn);
	void check_int(token type);

	/* errors and warnings */
	bool got_warning;			/* just-in-case precaution */
	void check_warnings(int* warn);
	void type_error(char* e);
	int yyerror(char* e);

%}

%union {
    struct{
	int warn;
	unsigned short int type;
	char* id;
    } node;
}
%type <node.type> type_specifier type_name
%type <node.id> IDENTIFIER declarator direct_declarator

%type <node> additive_expression multiplicative_expression cast_expression unary_expression postfix_expression primary_expression assignment_operator assignment_expression expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression if_statement statement argument_expression_list declaration_list statement_list declaration

%token IDENTIFIER CONSTANT SIZEOF PTR_OP ARRAY_OP GT_OP LT_OP GE_OP LE_OP NE_OP EQ_OP AND_OP OR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP
%token EQ_ASSIGN RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token TYPEDEF INT FLOAT CHAR VOID STRUCT IF ELSE WHILE RETURN ECM MUL DIV PERCENT TIL SUM SUB BANG STRING

%token FUNCTION DECLARATION TYPE_SPECIFIER DECLARATOR 
%token FUNCTION_DEFINITION TYPEDEF_STRUCT STRUCT_DECL_LIST DIRECT_DECL ARRAY_DECL
%token PARAM COMPOUND DECL STATE NEG AST FUNC EXP_LIST ASSIGN_LIST
%token UNARY_EXP SIZEOF_EXP SIZEOF_TYPE CAST_EXP AR_EXP SHIFT_EXP REL_OP_EXP EQ_OP_EXP NE_OP_EXP AND_OP_EXP EXCLOR_OP_EXP INCLOR_OP_EXP COND_EXP ASSIGN_EXP
%token PROGRAM EXP C_STATE

%nonassoc IF_PREC
%nonassoc ELSE

%start program

%%
program:
		program_aux
		{ }

program_aux:
		function_definition
		{ }
	|	function_definition program_aux
		{ }
	|	declaration
		{ }
	|	declaration program_aux
		{ }
	;

declaration:
		type_specifier ';'
		{ }
	|	type_specifier declarator ';'
		{ declare($1, $2); }
	;

function_definition:
		type_specifier declarator { declare_function($1); } compound_statement
	;

type_specifier:
		VOID
		{ $$=VOID; }
	|	INT
		{ $$=INT; }
	|	FLOAT
		{ $$=FLOAT; }
	|	CHAR
		{ $$=CHAR; }
	|	STRUCT IDENTIFIER
		{ }
	|	STRUCT IDENTIFIER '{' struct_decl_list '}'
		{ }
	|	TYPEDEF STRUCT '{' struct_decl_list '}' IDENTIFIER
		{ }
	|	TYPEDEF STRUCT IDENTIFIER '{' struct_decl_list '}' IDENTIFIER
		{ }
	;

struct_decl_list:
		type_specifier declarator ';'
		{ }
	|	type_specifier declarator ';' struct_decl_list
		{ }
	;

declarator:
		'*' direct_declarator
		{ $$=$2; }
	|	direct_declarator
		{ $$=$1; }
	;

type_name:
		type_specifier
		{ $$=$1; }
	;

direct_declarator:
		IDENTIFIER
		{ $$=$1; }
	|	direct_declarator '(' parameter_list ')'
		{ $$=$1; }
	|	direct_declarator '(' ')'
		{ $$=$1; }
	;

parameter_list:
		type_specifier declarator
		{ declare($1, $2); }
	|	type_specifier declarator ',' parameter_list
		{ declare($1, $2); }
	;

statement:
		if_statement
		{ }
	|	compound_statement
		{ }
	|	';'
		{ }
	|	WHILE '(' expression ')' { check_cond($3.type); }
		statement
		{ }
	|	RETURN expression { check_return($2.type); }
		';'
		{ }
	|	expression ';'
		{ }
	;

if_statement:
		if_condition statement %prec IF_PREC
		{ }
	|	if_condition statement ELSE statement
		{ }
	;
if_condition:
	    	IF '(' expression ')' { check_cond($3.type); }
	;

compound_statement:
		'{' compound_statement_aux '}'
		{ }
	;

compound_statement_aux:
		declaration_list
		{ }
	|	statement_list
		{ }
	|	declaration_list statement_list
		{ }
	|
		{ }
	;

unary_operator:
		'&'
		{ }
	|	'*'
		{ }
	|	'+'
		{ }
	|	'-'
		{ }
	|	'~'
		{ }
	|	'!'
		{ }
	;

primary_expression:
		IDENTIFIER
		{ $$.type=(token)lookup((char*)$1); }
	|	CONSTANT
		{ }
	|	STRING
		{ }
	|	'(' expression ')'
		{ $$=$2; }
	;

postfix_expression:
		primary_expression
		{ $$=$1; }
	|	postfix_expression '[' expression ']'
		{ $$=$1; }
	|	postfix_expression '(' ')'
		{ $$=$1; }
	|	postfix_expression '(' argument_expression_list ')'
		{ $$=$1; }
	|	postfix_expression '.' IDENTIFIER
		{ $$=$1; }
	|	postfix_expression PTR_OP IDENTIFIER
		{ $$=$1; }
	|	postfix_expression INC_OP
		{
		    $$=$1;
		    check_int($1.type);
		}
	|	postfix_expression DEC_OP
		{
		    $$=$1;
		    check_int($1.type);
		}
	;

unary_expression:
		postfix_expression
		{ $$=$1; }
	|	unary_operator cast_expression
		{ $$=$2; }
	|	SIZEOF unary_expression
		{ $$.type=INT; }
	|	SIZEOF '(' type_name ')'
		{ $$.type=INT; }
	;

cast_expression:
		unary_expression
		{ $$=$1; }
	|	'(' type_name ')' cast_expression
		{
		    $$=$4;
		    $$.type=$2;
		}
	;

multiplicative_expression:
		cast_expression
		{ $$=$1; }
	|	multiplicative_expression '*' cast_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	|	multiplicative_expression '/' cast_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	|	multiplicative_expression '%' cast_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	;

additive_expression:
		multiplicative_expression
		{ $$=$1; }
	|	additive_expression '+' multiplicative_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	|	additive_expression '-' multiplicative_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	;

shift_expression:
		additive_expression
		{ $$=$1; }
	|	shift_expression LEFT_OP additive_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	|	shift_expression RIGHT_OP additive_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	;

relational_expression:
		shift_expression
		{ $$=$1; }
	|	relational_expression '<' shift_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	|	relational_expression '>' shift_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	|	relational_expression LE_OP shift_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	|	relational_expression GE_OP shift_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

equality_expression:
		relational_expression
		{ $$=$1; }
	|	equality_expression EQ_OP relational_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	|	equality_expression NE_OP relational_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

and_expression:
		equality_expression
		{ $$=$1; }
	|	and_expression '&' equality_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

exclusive_or_expression:
		and_expression
		{ $$=$1; }
	|	exclusive_or_expression '^' and_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

inclusive_or_expression:
		exclusive_or_expression
		{ $$=$1; }
	|	inclusive_or_expression '|' exclusive_or_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

logical_and_expression:
		inclusive_or_expression
		{ $$=$1; }
	|	logical_and_expression AND_OP inclusive_or_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

logical_or_expression:
		logical_and_expression
		{ $$=$1; }
	|	logical_or_expression OR_OP logical_and_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_logic($1.type, $3.type, &$$.warn);
		}
	;

conditional_expression:
		logical_or_expression
		{ $$=$1; }
	|	logical_or_expression '?' logical_or_expression ':' conditional_expression
		{
		    check_cond($1.type);
		    if($3.type == $5.type) $$.type=$3.type;
		    /* else: < error> */
		}
	;

assignment_expression:
		conditional_expression
		{ $$=$1; }
	|	unary_expression assignment_operator assignment_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_assign($1.type, $3.type, &$$.warn);
		}
	;

expression:
		assignment_expression
		{
		    $$=$1;
		    got_warning=false;
		/** avoid the non-associated warnings (before shift-reduce happens) */
		}
	|	expression ',' assignment_expression
		{
		    $$.warn=($1.warn+$3.warn);
		    $$.type=check_op($1.type, $3.type, &$$.warn);
		}
	;

assignment_operator:
		'='			{ $$.id="="; }
	|	RIGHT_ASSIGN		{ $$.id=">>="; }
	|	LEFT_ASSIGN		{ $$.id="<<="; }
	|	ADD_ASSIGN		{ $$.id="+="; }
	|	SUB_ASSIGN		{ $$.id="-="; }
	|	MUL_ASSIGN		{ $$.id="*="; }
	|	DIV_ASSIGN		{ $$.id="/="; }
	|	MOD_ASSIGN		{ $$.id="%="; }
	|	AND_ASSIGN		{ $$.id="&="; }
	|	XOR_ASSIGN		{ $$.id="^="; }
	|	OR_ASSIGN		{ $$.id="|="; }
	;

argument_expression_list:
		assignment_expression
		{ $$=$1; }
	|	argument_expression_list ',' assignment_expression
		{ $$.warn=($1.warn+$3.warn); }
	;

declaration_list:
		declaration
		{ $$=$1; }
	|	declaration declaration_list
		{ $$.warn=($1.warn+$2.warn); }
	;

statement_list:
		statement statement_list
		{ $$.warn=($1.warn+$2.warn); }
	|	statement
		{ $$=$1; }
	;

%%

void declare_function(token type){
    ftype=(token)type;
}

void check_return(token type){
    if((type == VOID) || (ftype == VOID))
	type_error("illegal usage of void");
    if(ftype != type){
    	if((ftype == INT) && (type == FLOAT))
		type_error("int expression expected");
	else if((ftype == FLOAT) && (type == INT))
		fprintf(stdout,"warning: type cast int to float, line %d\n", yylineno);
    }
}

void declare(token type, char* id){
    list_put(id_list, type, id);
}

token lookup(char* id){
    return (token)list_search(id_list, (char*)id);
}

/** ***** TYPE-CHECKING *****
 * check_logic: checks relational expressions	- returns type 'int'
 * check_cond: checks conditions 		- input should be 'int'
 * check_op: check math expressions		- return the type (float/int)
 * check_assign: check assignements		- return the type (float/int)
 */
token check_logic(token a, token b, int* warn){
    if((a == VOID) || (b == VOID))
	type_error("numerical expression expected");

    if(a != b){
	check_warnings(warn);
	(*warn)++;
    }

    return INT;
}

token check_cond(token type){
    if((type == VOID))
	type_error("illegal usage of void");
    if((type == FLOAT))
	type_error("int expression expected");

    return INT;
}

token check_op(token a, token b, int* warn){
    if((a == VOID) || (b == VOID))
	type_error("numerical expression expected");

    if(a != b) {
	check_warnings(warn);
	(*warn)++;
	return FLOAT;
    }
    return a;
}

token check_assign(token a, token b, int* warn){
    if((a == VOID) || (b == VOID))
	type_error("illegal usage of void");
    if((a == INT) && (b == FLOAT))
	type_error("int expression expected");

    if((a == FLOAT) && (b ==INT)){
	check_warnings(warn);
	(*warn)++;
	return FLOAT;
    }
    return INT;
}

void check_int(token type){
    switch (type) {
	case VOID:
		type_error("illegal usage of void");
	case FLOAT:
		type_error("int expression expected");
	case INT:
		break;
	default:	/* error */
		break;
    }
}

/** warnings:
 *  - type cast int to float
 */
void check_warnings(int* warn){
    if(warn != NULL && *warn==0 && !got_warning)
	fprintf(stdout,"warning: type cast int to float, line %d\n", yylineno);
    got_warning=true;
}

/** errors:
 *  - int expession expected
 *  - numerical expession expected
 *  - illegal usage of void
 */
void type_error(char* e) {
    fprintf(stdout,"type error: %s, line %d\n", e, yylineno);
    exit(0);
}

int yyerror(char* e) {
    fprintf(stdout,"%s, line %d\n", e, yylineno);
    return -1; 
}

/** main engine */
int main() {
    id_list=list_create();
    got_warning=false;
    do{
	yydebug=0;
	yyparse();
    } while(!feof(yyin));
    list_destroy(id_list);
    return 0;
}

