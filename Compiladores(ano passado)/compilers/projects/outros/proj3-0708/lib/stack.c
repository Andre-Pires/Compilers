#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stacK_t* stack_create()
{
	stacK_t *stack;
	stack = (stacK_t*) malloc(sizeof(stacK_t));
	stack->numElems = 0;
	stack->first = NULL;
	stack->last = NULL;
	return stack;
}

int stack_destroy(stacK_t *stack)
{
	if (stack == NULL ) {
		return 0;
	}
	if (stack->first != NULL) {
		return -1;
	} else {
		free(stack);
		return 0;
	}
}

void stack_push(stacK_t *stack, void *object)
{
	if (stack == NULL || object == NULL) {
		return;
	}

	stack_element_t *new_element;
	new_element = (stack_element_t*) malloc(sizeof(stack_element_t));
	new_element->object = object;
	new_element->next = stack->first;

	if(stack->first == NULL) {
		stack->first = new_element;
		stack->last = new_element;
	} else {
		stack->first = new_element;
		//stack->last->next = new_element;
		//stack->last = new_element;
	}
	(stack->numElems)++;
}

void stack_bpush(stacK_t *stack, void *object)
{
	if (stack == NULL || object == NULL) {
		return;
	}

	stack_element_t *new_element;
	new_element = (stack_element_t*) malloc(sizeof(stack_element_t));
	new_element->object = object;
	new_element->next = NULL;

	if(stack->first == NULL) {
		stack->first = new_element;
		stack->last = new_element;
	} else {
		//stack->first = new_element;
		stack->last->next = new_element;
		stack->last = new_element;
	}
	(stack->numElems)++;
}

int stack_is_empty(stacK_t *stack)
{
	if (stack == NULL || stack->first == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void* stack_peek(stacK_t *stack)
{
	if (stack != NULL && stack->first != NULL) {
		return stack->first->object;
	} else {
		return NULL;
	}
}

void* stack_pop(stacK_t *stack)
{
	if (stack == NULL || stack->first == NULL) {
		return NULL;
	}
   
	stack_element_t *out_element = stack->first;
	if (stack->first == stack->last) {
		stack->first = NULL;
		stack->last = NULL;
	} else {
		stack->first = out_element->next;
	}
   
	void* temp = out_element->object;
	free(out_element);
	(stack->numElems)--;
	return temp;
}

void stack_clean(stacK_t *stack) {
	stack_element_t *aux1 = stack->first, *aux2;
	
	while(aux1 != NULL) {
		aux2 = aux1->next;
		free(aux1);
		aux1 = aux2;
	}
	stack->first = stack->last = NULL;
}

int stack_getNumElems(stacK_t *stack) {
	return (stack->numElems);
}

void stack_print(stacK_t * stack, FILE *fp) {
	stack_element_t *aux = stack->first;
	while(aux != NULL) {
		fprintf(fp, "%s\n", (char*)(aux->object));
		aux = aux->next;
	}
}
