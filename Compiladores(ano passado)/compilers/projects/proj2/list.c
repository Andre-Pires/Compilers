/*
 *  «list.c»
 *	Implementation of functions to manipulate type 'list'
 *
 */

#include "list.h"

/* list_create - allocates memory for list_t and initiates the structure */
list* list_create() {
	list *new;

	new = (list*) malloc(sizeof(list));
	new->length = 0;
	new->first = NULL;
	new->last = NULL;

	return (list*) new;
}

/* list_destroy - frees all memory used by list and its elements */
void list_destroy(list *lst) {
	list_element_t* aux;

	if(lst!=NULL && lst->length>-1){
		while(lst->length){
			aux=lst->last;
			lst->last=lst->last->previous;
			aux->id=NULL;
			aux->type=(TYPE)0;
			free(aux);
			lst->length--;
		}
		memset(lst, (int)NULL, sizeof(list));
		free(lst);

	/* just in case - to avoid segfault */
		lst->length = -1;
		lst->first = NULL;
		lst->last = NULL;
		return;
	}
	#ifdef VERBOSITY
		printf(" [list_destroy] input error.\n");
	#endif
}

/* list_put - insert 'id' in list at it's last position */
void list_put(list *lst, TYPE type, ID id) {
	list_element_t* new;

	if(lst!=NULL && lst->length>-1){
		new=(list_element_t*) malloc(sizeof(list_element_t));
		if(lst->length==0){
			new->previous=NULL;
			lst->first=new;
		} else {
			new->previous=lst->last;
			(lst->last)->next=new;
		}
		lst->last=new;
		new->next=NULL;
		memcpy(&(new->id), &id, sizeof(ID));
		new->type = type;
/*		memcpy(&(new->type), &type, sizeof(TYPE));*/
		lst->length++;
		return;
	}
	#ifdef VERBOSITY
		printf(" [list_put] input error.\n");
	#endif
}

/* list_search - returns the type of the given 'id' if found; otherwise returns NULL */
TYPE list_search(list *lst, ID id){
	list_element_t* aux;

	#ifdef VERBOSITY
		printf(" [list_search] for id '%s'\n", id);
	#endif
	if(lst!=NULL && lst->length>-1){
		aux=lst->first;
		while(aux!=NULL){
			if(!memcmp(id, aux->id, sizeof(ID)))
			       return (TYPE)(aux->type);
			aux=aux->next;
		}
	}

	#ifdef VERBOSITY
		printf(" [list_search] input error.\n");
	#endif
	return (TYPE)0;
}

/* list_print - print each pair ('id'.'type') of the given list */
void list_print(list *lst){
	list_element_t* aux;
	int i;

	if(lst!=NULL && lst->length>-1){
		printf(" >>> \n");
		if(lst->length==0){
			printf(" <<< \n");
			return;
		}
		aux=(lst->first);
		for(i=0; i<(lst->length); i++){
			printf(" ( \'%d\' . \'%s\')\n", aux->type, aux->id);
			aux=aux->next;
		}
		printf(" <<< \n");
		return;
	}
	#ifdef VERBOSITY
		printf(" [list_print] input error.\n");
	#endif
}
