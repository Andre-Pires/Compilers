%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./lib/node.h"
#include "./lib/tabid.h"
#include "./lib/stack.h"
#include "./lib/tac.h"
#include <string.h>

extern FILE *yyin;
extern int *yylineno;
int yyerror(char* e);
void evaluate(Node *p);

typedef struct info_ {
	unsigned int decl;
	unsigned int stat;
	unsigned int bina;
	char* name;
} info;

typedef struct list_el_ {
	info* info;
	struct list_el_* next;
}list_el;

typedef struct list_info_ {
	struct list_el_* first;
	struct list_el_* last;
} list_info;

void printList(list_info* list);
list_el* newFunction(Node* p);
void checkNodes(Node* p, list_el* el);
list_el* createEl();
int addList(list_info* list , list_el* new);
int checkFunction(Node *p);
char* getFunctionName(Node* p);

Node *treeHead = NULL;
extern stacK_t *stack;
extern short int tdebug;

%}

%union {
	int i;
	char* s;
	struct typeNode *n;
}

%token IDENTIFIER CONSTANT SIZEOF PTR_OP ARRAY_OP GT_OP LT_OP GE_OP LE_OP NE_OP EQ_OP AND_OP OR_OP 
%token TYPEDEF INT CHAR VOID STRUCT IF ELSE WHILE RETURN

%token FUNCTION DECLARATION TYPE_SPECIFIER DECLARATOR 
%token FUNCTION_DEFINITION TYPEDEF_STRUCT STRUCT_DECL_LIST DIRECT_DECL ARRAY_DECL
%token PARAM COMPOUND DECL STATE NEG AST FUNC EXPR_LIST
%token PROGRAM EXPR C_STATE

%type <i> CONSTANT
%type <s> IDENTIFIER
%type <n> program program_aux declaration
%type <n> function_definition type_specifier struct_decl_list 
%type <n> declarator direct_declarator parameter_list
%type <n> statement if_statement compound_statement compound_statement_aux 
%type <n> declaration_list statement_list expression unary_expression unary_ident
%type <n> ptr_op expression_list

%nonassoc IF_PREC
%nonassoc ELSE


%start program

%%

program : program_aux	{ evaluate($1); treeHead = $1; }

program_aux	: function_definition				{	$$ = subNode(PROGRAM,1,$1);	}
		| function_definition program_aux		{	$$ = subNode(PROGRAM,2,$1,$2);	}
		| declaration					{	$$ = subNode(PROGRAM,1,$1);	}
		| declaration program_aux			{	$$ = subNode(PROGRAM,2,$1,$2);	}
		;

declaration	: type_specifier ';'					{	$$ = subNode(DECLARATION,1,$1); }
		| type_specifier declarator ';'				{	$$ = subNode(DECLARATION,2,$1,$2);	}
		;

function_definition	: type_specifier declarator compound_statement	{	$$ = subNode(FUNCTION,3,$1,$2,$3);	}
			;

type_specifier	: VOID							{	$$ = nilNode(VOID);	}
		| INT							{	$$ = nilNode(INT);	}
		| CHAR							{	$$ = nilNode(CHAR);	}
		| STRUCT IDENTIFIER					{	$$ = subNode(STRUCT,1, strNode(IDENTIFIER,$2));	}
		| STRUCT IDENTIFIER '{' struct_decl_list '}'		{	$$ = subNode(STRUCT,2, strNode(IDENTIFIER,$2) , $4);	}
		| TYPEDEF STRUCT '{' struct_decl_list '}' IDENTIFIER	{       $$ = subNode(TYPEDEF_STRUCT, 3, nilNode(' '), $4, strNode(IDENTIFIER,$6));	}
		| TYPEDEF STRUCT IDENTIFIER '{' struct_decl_list '}' IDENTIFIER	{  $$ = subNode(TYPEDEF_STRUCT,3, strNode(IDENTIFIER,$3) , $5, strNode(IDENTIFIER,$7));	}
		;

struct_decl_list: type_specifier declarator ';'				{	$$ = subNode(STRUCT_DECL_LIST,2,$1,$2);	}
		| type_specifier declarator ';' struct_decl_list	{	$$ = subNode(STRUCT_DECL_LIST,3,$1,$2,$4);	}
		;

declarator	: '*' direct_declarator					{	$$ = subNode(DECLARATOR, 2, $2 , NULL);	}
		| direct_declarator					{	$$ = subNode(DECLARATOR, 1, $1);	}
		;

direct_declarator	: IDENTIFIER					{ $$ = strNode(IDENTIFIER, $1);		}
			| direct_declarator '(' parameter_list ')'	{ $$ = subNode(DIRECT_DECL,2,$1,$3); 	}
			| direct_declarator '(' ')'			{ $$ = subNode(DIRECT_DECL,1,$1);	}
			| IDENTIFIER '[' CONSTANT ']'			{ $$ = subNode(ARRAY_DECL,2,strNode(IDENTIFIER, $1) ,intNode(CONSTANT,$3)); }
			;

parameter_list	: type_specifier declarator				{	$$ = subNode(PARAM,2,$1,$2);	}
		| type_specifier declarator ',' parameter_list		{	$$ = subNode(PARAM,3,$1,$2,$4);	}
		;

statement	: if_statement						{	$$ = $1;	}
		| compound_statement					{	$$ = subNode(C_STATE,1,$1);	}
		| ';'							{	$$ = nilNode(';');		}
		| unary_expression '=' expression ';'			{	$$ = subNode('=',2,$1,$3);	}
		| WHILE '(' expression ')' statement			{	$$ = subNode(WHILE,2,$3,$5);	}
		| RETURN expression ';'					{	$$ = subNode(RETURN,1,$2);	}
/* esta expression ';' tem que ser confirmada */
		| expression ';'					{	$$ = subNode(EXPR,1,$1);	}
		;

if_statement	: IF '(' expression ')' statement %prec IF_PREC		{	$$ = subNode(IF,2,$3,$5);	}
		| IF '(' expression ')' statement ELSE statement	{	$$ = subNode(IF,3,$3,$5,$7);	}
		;

compound_statement	: '{' compound_statement_aux '}'		{	$$ = subNode(COMPOUND,1,$2);	}
			;

compound_statement_aux	: declaration_list				{	$$ = $1;	}
			| statement_list				{	$$ = $1;	}
			| declaration_list statement_list		{	$$ = subNode(DECL,2,$1,$2);	}
			|						{	$$ = NULL;	}
			;

declaration_list	: declaration					{	$$ = subNode(DECL,1,$1);	} 
			| declaration declaration_list			{	$$ = subNode(DECL,2,$1,$2);	}
			;

statement_list	: statement statement_list				{	$$ = subNode(STATE,2,$1,$2);	}
		| statement						{	$$ = $1;	}
		;


expression	: unary_expression				{ $$ = $1;			}
		| unary_expression '+' unary_expression		{ $$ = subNode('+', 2, $1, $3);	}
  		| unary_expression '-' unary_expression		{ $$ = subNode('-', 2, $1, $3);	}
		| unary_expression '*' unary_expression		{ $$ = subNode('*', 2, $1, $3);	}
 		| unary_expression '/' unary_expression		{ $$ = subNode('/', 2, $1, $3);	}
		| unary_expression LT_OP unary_expression	{ $$ = subNode(LT_OP, 2, $1, $3);	}
		| unary_expression GT_OP unary_expression	{ $$ = subNode(GT_OP, 2, $1, $3);	}
		| unary_expression LE_OP unary_expression	{ $$ = subNode(LE_OP , 2, $1, $3);	}
		| unary_expression GE_OP unary_expression	{ $$ = subNode(GE_OP , 2, $1, $3);	}
		| unary_expression NE_OP unary_expression	{ $$ = subNode(NE_OP , 2, $1, $3);	}
		| unary_expression EQ_OP unary_expression	{ $$ = subNode(EQ_OP , 2, $1, $3);	}
		| unary_expression AND_OP unary_expression	{ $$ = subNode(AND_OP, 2, $1, $3);	}
		| unary_expression OR_OP unary_expression	{ $$ = subNode(OR_OP , 2, $1, $3);	}
		| '(' expression ')'				{ $$ = $2;	}
		;

expression_list	: expression				{	$$ = $1;	}
		| expression ',' expression_list	{	$$ = subNode(EXPR_LIST,2,$1,$3);	}
		|					{	$$ = NULL;	}
		;


unary_expression: unary_ident				{ $$ = $1;	}
		| '+' unary_ident			{ $$ = $2;	}
		| '-' unary_ident			{ $$ = subNode(NEG,1,$2);	}
		| '*' unary_ident			{ $$ = subNode(AST,1,$2);	}
		| '~' unary_ident			{ $$ = subNode('~',1,$2);	}
		| '&' unary_ident			{ $$ = subNode('&',1,$2);	}
		| IDENTIFIER PTR_OP ptr_op		{ $$ = subNode(PTR_OP,2,strNode(IDENTIFIER,$1),$3);	}
		| IDENTIFIER '[' expression ']'	{ $$ = subNode(ARRAY_OP,2,strNode(IDENTIFIER,$1),$3);	}
		;

ptr_op	: IDENTIFIER			{	$$ = strNode(IDENTIFIER,$1);	}
	| IDENTIFIER PTR_OP ptr_op	{	$$ = subNode(PTR_OP,2,strNode(IDENTIFIER,$1),$3);	}
	;


unary_ident	: CONSTANT				{	$$ = intNode(CONSTANT,$1);	}
		| IDENTIFIER				{	$$ = strNode(IDENTIFIER,$1);	}
		| SIZEOF '(' type_specifier ')'		{	$$ = subNode(SIZEOF,1,$3);	}
		| IDENTIFIER '(' expression_list ')'	{	$$ = subNode(FUNC,2,strNode(IDENTIFIER,$1),$3);	}
		;


%%

int yyerror(char* e) {
	fprintf(stdout,"%s, line %d\n",e,yylineno);
	return -1;
}

int main() {

	do{
		yyparse();
	} while(!feof(yyin));
	
	//printNode(treeHead,NULL,NULL);
	stack = stack_create();
	tdebug = 0; // enable TAC debug mode
	generate(treeHead, stdout, 0);
	freeNode(treeHead);
	
	return 0;
}

void evaluate(Node *p) {
	extern int errors, treeop;
	list_info* list;
	list_el* aux;
	int decl;
	int func;

	decl = 0;
	func = 0;
	
	list = (list_info*) malloc (sizeof(list_info));

	list -> first = NULL;
	list -> last = NULL;

	while ( p != NULL ) {
		if ( checkFunction(p) == 1 ) {
			func++;
			aux = newFunction(p->value.sub.n[0]);
			addList(list, aux);
		}
		else
			decl++;

		if ( p->value.sub.num == 1)
			p = NULL;
		else
			p = p -> value.sub.n[1];
	}
	
	//printf("Top level: %d declarations.\n",decl);
	//printList(list);
}

void printList(list_info* list) {

	list_el* pont;
	info* i;

	pont = list -> first;
	while (pont != NULL) {
		i = pont -> info;
		printf("%s: %d declarations, %d statements, %d binary operations.\n", i -> name ,i -> decl ,i -> stat,i-> bina);
		pont = pont -> next;
	}
}

list_el* newFunction(Node* p) {

	list_el *funct_info;
	int i;

	funct_info = createEl();
	
	
	funct_info -> info -> name = getFunctionName(p->value.sub.n[1]);
	
	for ( i = 0 ; i < p -> value.sub.num ; i++ ) {
		checkNodes(p->value.sub.n[i] , funct_info);		
	}


	return funct_info;
}

char* getFunctionName(Node* p) {
	
	if ( p -> attrib == IDENTIFIER )
		return strdup (p->value.s);
	else
		return getFunctionName(p-> value.sub.n[0]);

}

void checkNodes(Node* p, list_el* el) {
	int b = 0;
	int i;
	int s = 0;

	if ( p == NULL )
		return;
	if ( p->attrib == DECLARATION)
		el -> info -> decl += 1;
	else {
		switch (p -> attrib ) {
			case IF: s = 1; break;
			case RETURN: s = 1; break;
			case WHILE: s = 1; break;
			case EXPR: s = 1; break;
			case '=': s = 1; break;
			case ';': s = 1; break;
			case '+': b = 1; break;
			case '-': b = 1; break;
			case '*': b = 1; break;
			case '/': b = 1; break;
			case '<': b = 1; break;
			case '>': b = 1; break;
			case '[': b = 1; break;
			case ']': b = 1; break;
			case EQ_OP: b = 1; break;
			case OR_OP: b = 1; break;
			case AND_OP: b = 1; break;
		}
		
		el -> info -> stat += s;
		el -> info -> bina += b;
	}

	if ( p -> type != nodeOpr )
		return;

	for ( i = 0 ; i < p -> value.sub.num ; i++ ) {
		checkNodes(p->value.sub.n[i] , el);		
	}
}

list_el* createEl() {
	list_el* aux;

	aux = (list_el*) malloc (sizeof(list_el));
	aux -> info = (info*) malloc (sizeof(info));

	aux -> next = NULL;
	aux -> info -> decl = 0;
	aux -> info -> stat = 0;
	aux -> info -> bina = 0;
	aux -> info -> name = NULL;

	return aux;
}

int addList(list_info* list , list_el* new) {
	if ( list -> first == NULL)
		list -> first = new;
	if ( list -> last != NULL)
		list -> last -> next = new;
	list -> last = new;
	return 1;
}

int checkFunction(Node *p) {
	if (p->value.sub.n[0]->attrib == FUNCTION)
		return 1;
	else
		return 0;
}

