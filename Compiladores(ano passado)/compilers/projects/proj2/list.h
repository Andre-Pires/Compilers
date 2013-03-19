/*
 *  «list.h»
 *    Definition and declarations of the type 'list'
 *
 */

#ifndef LIST_H
#define LIST_H

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef VERBOSITY
 /*#define VERBOSITY 1*/
#endif

#define ID char*
#define TYPE unsigned short int

/*  structures of the ADT 'list'  */
typedef struct list_link {
	int i;
	ID *id;
	TYPE type;
	struct list_link *next;
	struct list_link *previous;
} list_element_t;

typedef struct {
	int length;
	list_element_t *last;
	list_element_t *first;
} list;

/* list_create - allocates memory for list_t and initiates the structure */
list* list_create();

/* list_destroy - frees all memory used by list and its elements */
void list_destroy(list *lst);

/* list_put - insert 'id' in list at it's last position */
void list_put(list *lst, TYPE type, ID id);
/* list_search - returns the type of the given 'id' */
TYPE list_search(list *lst, ID id);

/* list_print - print each pair ('id'.'type') of the given list */
void list_print(list *lst);

#endif
