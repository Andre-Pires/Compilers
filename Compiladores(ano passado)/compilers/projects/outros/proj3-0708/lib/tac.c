#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tac.h"
#include "stack.h"
#include "../y.tab.h"

#define dfprintf if(tdebug) fprintf

stacK_t *stack = NULL;
short int tdebug = 0;
int init = 0;
int ret = 0;

char* newLabel() {
	static int counter = 1;
	char* newStr = (char*) malloc(sizeof(char)*6);
	
	newStr[0] = 'L';
	sprintf(newStr+1, "%d", counter);
	counter++;
		
	return newStr;
}

char* newTempVar() {
	static int counter = 1;
	char* newStr = (char*) malloc(sizeof(char)*6);
	
	newStr[0] = 't';
	sprintf(newStr+1, "%d", counter);
	counter++;
		
	return newStr;
}

void printIdent(FILE *fp, int lev) {
	int i;
	for (i = 0; i < 2*lev; i++) {
		dfprintf(fp, " ");
	}
}

void process_attribution(Node *p, FILE *fp, int lev) {
	char *tempVar;
	char *s0, *s1;
			
	printIdent(stderr, lev);
	dfprintf(stderr, "process_attribution!\n");

	generate(p->value.sub.n[0], fp, lev+1);
	generate(p->value.sub.n[1], fp, lev+1);
	s1 = (char*)(stack_pop(stack));
	s0 = (char*)(stack_pop(stack));
	if((p->value.sub.n[0])->attrib = ARRAY_OP) {
		tempVar = newTempVar();
		fprintf(fp, "\t%s = %s\n", tempVar, s1);
		fprintf(fp, "\t%s = %s\n", s0, tempVar);
		//free(tempVar);
	} else {
		fprintf(fp, "\t%s = %s\n", s0, s1);
	}
	//free(s0); free(s1);
	
	printIdent(stderr, lev);
	dfprintf(stderr, "/process_attribution!\n");
}

void process_operator(Node *p, FILE *fp, int lev, char oper) {
	char *s0, *s1, *tempVar1, *tempVar2, *tempVar3;
	char *str = (char*) malloc(sizeof(char)*25);
	
	printIdent(stderr, lev);
	dfprintf(stderr, "process_binaryOperator (oper=%c)!\n", oper);
	
	generate(p->value.sub.n[0], fp, lev+1);
	generate(p->value.sub.n[1], fp, lev+1);
	s1 = (char*)(stack_pop(stack));
	s0 = (char*)(stack_pop(stack));
	if((p->value.sub.n[0])->attrib == ARRAY_OP) {
		tempVar1 = newTempVar();
		fprintf(fp, "\t%s = %s\n", tempVar1, s0);
		s0 = tempVar1;
	}
	if((p->value.sub.n[1])->attrib == ARRAY_OP) {
		tempVar2 = newTempVar();
		fprintf(fp, "\t%s = %s\n", tempVar2, s1);
		s1 = tempVar2;
	}
	tempVar3 = newTempVar();
	fprintf(fp, "\t%s = %s %c %s\n", tempVar3, s0, oper, s1);
	stack_push(stack, (void*)tempVar3);
	//free(s0); free(s1);	
}

void process_comp_operator(Node *p, FILE *fp, int lev, int oper) {
	printIdent(stderr, lev);
	char op[3];
	switch(oper) {
		case LT_OP:
			strcpy(op, "<");
			break;
		case GT_OP:
			strcpy(op, ">");
			break;
		case LE_OP:
			strcpy(op, "<=");
			break;
		case GE_OP:
			strcpy(op,">=");
			break;
		case NE_OP:
			strcpy(op, "!=");
			break;
		case EQ_OP:
			strcpy(op, "==");
			break;
		case AND_OP:
			strcpy(op, "&&");
			break;
		case OR_OP:
			strcpy(op, "||");
			break;
	}
	dfprintf(stderr, "process_compareOperator (oper=%s)!\n", op);
	char *var0 = newTempVar(), *var1 = newTempVar();
	char *s0, *s1;
	char *str = (char*) malloc(sizeof(char)*25);
	generate(p->value.sub.n[0], fp, lev+1);
	generate(p->value.sub.n[1], fp, lev+1);
	s1 = (char*)(stack_pop(stack));
	s0 = (char*)(stack_pop(stack));
	fprintf(fp, "\t%s = %s\n", var0, s0);
	fprintf(fp, "\t%s = %s\n", var1, s1);
	sprintf(str, "%s %s %s", var0, op, var1);
	stack_push(stack, (void*)str);
	//free(s0); free(s1); free(var0); free(var1);
	// free stuff
}

void process_PROGRAM(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_PROGRAM!\n");
	int i;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev);
	}
}

process_C_STATE(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_C_STATE!\n");
	generate(p->value.sub.n[0], fp, lev);
}

void process_DECLARATOR(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_DECLARATOR!\n");
	if ((p->value.sub.n[0])->type == nodeStr) {
		generate(p->value.sub.n[0], fp, lev+1);
	} else {
		int i;
		for (i = 0; i < p->value.sub.num; i++) {
			generate(p->value.sub.n[i], fp, lev+1);
		}
	}
}

void process_COMPOUND(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_COMPOUND!\n");
	int i;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
	}
}

void process_DECLARATION(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_DECLARATION!\n");
	int i, elems;
	
	elems = stack_getNumElems(stack);
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
	}
	elems = stack_getNumElems(stack) - elems;
	for(i = 0; i < elems; i++) {
		// tirar da pilha e meter no tabid
		stack_pop(stack);
	}
}

void process_DIRECT_DECL(Node *p, FILE *fp, int lev) {
	char *s0;
	int i, elems;
	printIdent(stderr, lev);
	dfprintf(stderr, "process_DIRECT_DECL!\n");
	
	if (strcmp((p->value.sub.n[0])->value.s, "main") == 0) {
		fprintf(fp, "init");
		init = 1;
	} else {
		fprintf(fp, "%s", (p->value.sub.n[0])->value.s);
	}
	fprintf(fp, ":");
	if(p->value.sub.num > 1) {
		elems = stack_getNumElems(stack);
		generate(p->value.sub.n[1], fp, lev+1);
		elems = stack_getNumElems(stack) - elems;
		
		for(i = 0; i < elems; i++) {
			s0 = (char*)(stack_pop(stack));
			fprintf(fp, "\tgetparam %s\n", s0);
		}
	}
}

void process_ARRAY_DECL(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_ARRAY_DECL!\n");
	// e meter no tabid? era uma boa ideia... era! ^_^
}

void process_ARRAY_OP(Node *p, FILE *fp, int lev) {
	char *tempVar1, *s0, *s1, *str = (char*) malloc(sizeof(char)*25);
	printIdent(stderr, lev);
	dfprintf(stderr, "process_ARRAY_OP!\n");
	
	tempVar1 = newTempVar();
	if((p->value.sub.n[1])->attrib == CONSTANT) {
		generate(p->value.sub.n[0], fp, lev+1);
		generate(p->value.sub.n[1], fp, lev+1);
		s1 = stack_pop(stack);
		s0 = stack_pop(stack);
		sprintf(str ,"%s[%s]", s0, s1);
	} else {
		generate(p->value.sub.n[0], fp, lev+1);
		generate(p->value.sub.n[1], fp, lev+1);
		s1 = stack_pop(stack);
		s0 = stack_pop(stack);
		fprintf(fp, "\t%s = %s\n", tempVar1, s1);
		sprintf(str, "%s[%s]", s0, tempVar1);
	}
	stack_push(stack,str);
	//free(s0); free(s1); free(tempVar1);
		
	printIdent(stderr, lev);
	dfprintf(stderr, "/process_ARRAY_OP!\n");
}

void process_DECL(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_DECL!\n");
	int i;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
	}
}

void process_EXPR(Node *p, FILE *fp, int lev) {
	char *s0;
	int elems;
	printIdent(stderr, lev);
	dfprintf(stderr, "process_EXPR!\n");
	
	elems = stack_getNumElems(stack);
	generate(p->value.sub.n[0], fp, lev+1);
	elems = stack_getNumElems(stack) - elems;
	int i;
	for(i = 0; i < elems; i++) {
		s0 = (char*)(stack_pop(stack));
		fprintf(fp, "\t%s\n", s0);
		//free(s0);
	}
}

void process_EXPR_LIST(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_EXPR_LIST!\n");
	int i;
	char *s0, *tempVar1;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
		if((p->value.sub.n[i])->attrib == ARRAY_OP) {
			tempVar1 = newTempVar();
			s0 = (char*)(stack_pop(stack));
			fprintf(fp, "\t%s = %s\n", tempVar1, s0);
			stack_push(stack, (void*)tempVar1);
		}
	}
}

void process_FUNC(Node *p, FILE *fp, int lev) {
	char *s0, *tempVar1, *str = (char*) malloc(sizeof(char)*25);
	printIdent(stderr, lev);
	dfprintf(stderr, "process_FUNC!\n");
	
	int i, elems = 0;
	if(p->value.sub.n[1] != NULL) {
		  elems = stack_getNumElems(stack);
		  generate(p->value.sub.n[1], fp, lev+1);
		  if((p->value.sub.n[1])->attrib == ARRAY_OP) {
			tempVar1 = newTempVar();
			s0 = (char*)(stack_pop(stack));
			fprintf(fp, "\t%s = %s\n", tempVar1, s0);
			stack_push(stack, (void*)tempVar1);
		  }
		  elems = stack_getNumElems(stack) - elems;
		  
		  for(i = 0; i < elems; i++) {
			s0 = (char*)(stack_pop(stack));
			fprintf(fp, "\tputparam %s\n", s0);
			//free(s0);
		  }
	}

	generate(p->value.sub.n[0], fp, lev+1);
	s0 = (char*)(stack_pop(stack));
	sprintf(str, "call %s, %d", s0, elems);
	stack_push(stack, (void*)str);
	//free(s0);
}

void process_STATE(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_STATE!\n");
	int i;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
	}
}

void process_PARAM(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_PARAM!\n");
	int i;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
	}
	
}

void process_RETURN(Node *p, FILE *fp, int lev) {
	char *s0, *tempVar1;
	printIdent(stderr, lev);
	dfprintf(stderr, "process_RETURN!\n");
	
	if(p->value.sub.n[0] != NULL) {
	  	generate(p->value.sub.n[0], fp, lev+1);
		if((p->value.sub.n[0])->attrib == ARRAY_OP) {
	   		tempVar1 = newTempVar();
	   		s0 = (char*)(stack_pop(stack));
	   		fprintf(fp, "\t%s = %s\n", tempVar1, s0);
	   		stack_push(stack, (void*)tempVar1);
	  	}
		s0 = (char*)(stack_pop(stack));
		fprintf(fp, "\treturn %s\n", s0);
	} else {
		fprintf(fp, "\treturn\n");
	}
	ret = 1;
	//free(s0);
}

void process_IF(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_IF!\n");
	char *s0, *trueLabel, *falseLabel;
	
	trueLabel = newLabel();
	falseLabel = newLabel();
	generate(p->value.sub.n[0], fp, lev+1);
	s0 = (char*)(stack_pop(stack));
	fprintf(fp, "\tif %s goto %s\n", s0, trueLabel);
	if(p->value.sub.num > 2) {
		generate(p->value.sub.n[2], fp, lev+1);
	}
	fprintf(fp, "\tgoto %s\n%s:", falseLabel, trueLabel);
	generate(p->value.sub.n[1], fp, lev+1);
	fprintf(fp,"\tgoto %s\n%s:", falseLabel, falseLabel);
	//free(s0); free(trueLabel); free(falseLabel);
}

void process_WHILE(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_WHILE!\n");
	char *loopLabel = newLabel();
	char *trueLabel = newLabel();
	char *falseLabel = newLabel();
	char *s0, *tempVar1, *str = (char*) malloc(sizeof(char)*25);
	
	fprintf(fp, "%s:", loopLabel);
	generate(p->value.sub.n[0], fp, lev+1);
	if((p->value.sub.n[0])->attrib == CONSTANT) {
		tempVar1 = newTempVar();
		s0 = (char*)stack_pop(stack);
		fprintf(fp, "\t%s = %s\n", tempVar1, s0);
		sprintf(str, "%s != 0", tempVar1);
		stack_push(stack, (void*)str);
	}
	s0 = (char*)stack_pop(stack);
	fprintf(fp, "\tif %s goto %s\n\tgoto %s\n%s:", s0, trueLabel, falseLabel, trueLabel);
	generate(p->value.sub.n[1], fp, lev+1);
	fprintf(fp, "\tgoto %s\n%s:", loopLabel, falseLabel);
	//free(loopLabel); free(trueLabel); free(falseLabel); free(s0);
}

void process_FUNCTION(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "process_FUNCTION!\n");
	int i, isMain = init;
	for (i = 0; i < p->value.sub.num; i++) {
		generate(p->value.sub.n[i], fp, lev+1);
	}
	if(isMain != init) {
		fprintf(fp, "\thalt\n");
	} else if(!ret) {
		fprintf(fp, "\treturn\n");
		ret = 0;
	}
}

void process_nodeInt(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "NodeInt!\n");
	//dfprintf(fp, "%d", p->value.i);
	char *str = (char*) malloc(sizeof(char)*6);
	sprintf(str, "%d", p->value.i);
	stack_push(stack, (void*)(str));
}

void process_nodeStr(Node *p, FILE *fp, int lev) {
	printIdent(stderr, lev);
	dfprintf(stderr, "NodeStr!\n");
	//dfprintf(fp, "%s", p->value.s);
	stack_push(stack, (void*)(p->value.s));
}

void process_nodeOpr(Node *p, FILE *fp, int lev) {
	//dfprintf(stderr, "NodeOpr!\n");
	switch (p->attrib) {
		case PROGRAM:
			process_PROGRAM(p, fp, lev);
			break;
		case DECLARATION:
			process_DECLARATION(p, fp, lev);
			break;
		case FUNCTION:
			process_FUNCTION(p, fp, lev);
			break;
		case DECLARATOR:
			process_DECLARATOR(p, fp, lev);
			break;
		case COMPOUND:
			process_COMPOUND(p, fp, lev);
			break;
		case DIRECT_DECL:
			process_DIRECT_DECL(p, fp, lev);
			break;
		case DECL:
			process_DECL(p, fp, lev);
			break;
		case ARRAY_DECL:
			process_ARRAY_DECL(p, fp, lev);
			break;
		case STATE:
			process_STATE(p, fp, lev);
			break;
		case EXPR:
			process_EXPR(p, fp, lev);
			break;
		case EXPR_LIST:
			process_EXPR_LIST(p, fp, lev);
			break;
		case FUNC:
			process_FUNC(p, fp, lev);
			break;
		case PARAM:
			process_PARAM(p, fp, lev);
			break;
		case ARRAY_OP:
			process_ARRAY_OP(p, fp, lev);
			break;
		case RETURN:
			process_RETURN(p, fp, lev);
			break;
		case WHILE:
			process_WHILE(p, fp, lev);
			break;
		case IF:
			process_IF(p, fp, lev);
			break;
		case C_STATE:
			process_C_STATE(p, fp, lev);
			break;
		case '=':
			process_attribution(p, fp, lev);
			break;
		case '+':
		case '-':
		case '/':
		case '*':
			process_operator(p, fp, lev, p->attrib);
			break;
		case LT_OP:
		case GT_OP:
		case LE_OP:
		case GE_OP:
		case NE_OP:
		case EQ_OP:
		case AND_OP:
		case OR_OP:
			process_comp_operator(p, fp, lev, p->attrib);
			break;
		default:
			printIdent(stderr, lev);
			dfprintf(stderr, "process_nodeOpr: Unknown attrib type (type=%d)\n", p->attrib);
	}
}

void generate(Node *p, FILE *fp, int lev) {
	int i;

	if (p == 0) return;
	
	switch (p->type) {
		case nodeNil: break;
		case nodeInt:
			process_nodeInt(p, fp, lev);
			break;
		case nodeStr:
			process_nodeStr(p, fp, lev);
			break;
	/*	case nodeReal:
			process_nodeReal(p, fp, lev);
			break;
		case nodeData:
			process_nodeData(p, fp, lev);
			break;
	*/
		case nodeOpr:
			process_nodeOpr(p, fp, lev);
			break;
		default:
			printIdent(stderr, lev);
			dfprintf(stderr, "generate: Unknown node (type=%d)\n", p->type);
	}
}
