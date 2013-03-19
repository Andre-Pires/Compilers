#include "reg.h"

#define DEBUG


/* ********************************************************************
 *   auxiliary functions
 * ********************************************************************/
VALUE gen_reg(int n){
    int i, length;
    char *str;
    char aux;

    str=(char*)malloc(sizeof(char) * MAX_VAR_NAME_SIZE);

    // generate the string (reversed)
    if(n!=0){
	for(i=0; n>0; i++){
		str[i]=(char) ('0' + n%10);
		n /= 10;
	}
    } else {
	str[0]='0';
	i=1;
    }
    str[i++]='r';
    str[i] = '\0';
    length = i;

    // then reverse the string
    for(i=0; i<(length/2); i++){
	aux = str[i];
	str[i] = str[length-i-1];
	str[length-i-1] = aux;
    }
    
    return str; // ok
}

/* ********************************************************************
 *   TABLE's - Abstract Data Type
 * ********************************************************************/

// table_new - allocates memory for a new table
table* table_new(){
	table *new;
	new=(table*) malloc(sizeof(table));

	new->length=0;
	new->free=0;

	new->first=NULL;
	new->last=NULL;

	return new;
}
// table_put - insert a new register with given index 'i'
void table_put(table* tbl, int n){
	reg *tmp;
	tmp = (reg*) malloc(sizeof(reg));

	tmp->idx=n;
	tmp->name=gen_reg(n);
	tmp->value=(VALUE) malloc(sizeof(char) * MAX_VAR_NAME_SIZE);
	bzero(tmp->value, MAX_VAR_NAME_SIZE);
	if(n!=0){
		tmp->free=true;
		tmp->dirty=true;
	} else{
		tmp->free=false;
		tmp->dirty=false;
		tmp->store=true;
		strncpy(tmp->value, "store", MAX_VAR_NAME_SIZE);
	}

	tmp->dist=-1;

	if(tbl->length==0) {
		tbl->first=tmp;
		tmp->previous=NULL;

	} else {
		tmp->previous=tbl->last;
		(tbl->last)->next=tmp;
	}
	tmp->next=NULL;
	tbl->last=tmp;
	tbl->free++;
	tbl->length++;
}

// table_create - allocates memory for a table for 'n' registers and initiates the structure
table* table_create(int n) {
	table *new;
	int i;

	if(n<1) return (table*)NULL;

	new=table_new();
	for(i=n; i>0; i--)
		table_put(new, i-1);

	return (table*) new;
}

// table_destroy - frees all memory used by table and its elements
void table_destroy(table *tbl) {
	reg* aux;

	if(tbl!=NULL && tbl->length>-1){
		while(tbl->length){
			aux=tbl->last;
			tbl->last=tbl->last->previous;
			free(aux->name);
			free(aux->value);
			free(aux);
			tbl->length--;
		}
		tbl->first = NULL;
		tbl->last = NULL;
		free(tbl);

		return;
	}
	#ifdef ERRORS
		printf(" [table_destroy] input error.\n");
	#endif
}



// -
//  debugging functions
// --------------------------------------------------

// table_print - print each pair ('register'.'value')
void table_print(table *tbl){
	reg* aux;
	int i;
	if(tbl==NULL) return;

	if(tbl->length>-1){
		printf(" >>> \n");
		if(tbl->length==0){
			printf(" <<< \n");
			return;
		}
		aux=(tbl->first);
		for(i=0; (i<tbl->length) && (aux!=NULL); i++){
			printf("  | [\'%s\'] :: \'%s\'\t~%d\n",
				aux->name, aux->value, aux->dist);
			aux=aux->next;
		}
		printf(" <<< \n");
		return;
	}
	#ifdef ERRORS
		printf(" [table_print] input error.\n");
	#endif
}

