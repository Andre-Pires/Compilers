#ifndef REG_H
#define REG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#ifndef MAX_VAR_NAME_SIZE
  #define MAX_VAR_NAME_SIZE 8
#endif

#define bool unsigned char
#define true 1
#define false 0
#define NAME char*
#define VALUE char*

//  main structure
typedef struct link {
	int idx;		// the indice starting from '1'

	NAME name;		// the register's name
	bool free;		// 
	VALUE value;		// the variable
	int dist;		// the distance
	bool dirty;		//
	bool store;		// if its the store register ('r0' by default)

	struct link *previous;	// 
	struct link *next;	// 
} reg;

typedef struct {
	int length;		// starting from '1'
	int free;		// number of free registers

	reg *first;
	reg *last;
} table;

/* ********************************************************************
 *   auxiliary functions
 * ********************************************************************/
NAME gen_reg(int n); 	// the representation of the register

/* ********************************************************************
 *   TABLE's - Abstract Data Type
 * ********************************************************************/
table* table_new(); 			// allocates memory for a new table
table* table_create(int n); 		// creates a table of 'n' registers
void table_put(table* tbl, int n); 	// insert a new register in the table
void table_destroy(table* tbl); 	// frees memory used by table and its elements

// debug only
void table_print(table* tbl); 	// print each pair ('register'.'value')


#endif

