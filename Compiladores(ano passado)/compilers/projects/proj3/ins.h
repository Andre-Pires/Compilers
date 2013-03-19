#ifndef INS_H
#define INS_H

#define MAX_VAR_NAME_SIZE 8
#include "reg.h"

typedef struct ins_node {
  
  struct ins_node* prev;

  int idx;				// just a general index
  char opd;				// the operator of the destination to do *r1 = ...
  char dst[MAX_VAR_NAME_SIZE];		// the destination register or variable
  char ops1;				// the operator of the first src operand to do ... = *r1
  char src1[MAX_VAR_NAME_SIZE];		// the first source operand which can be an integer
  char ops2;				// the infix operand
  char src2[MAX_VAR_NAME_SIZE];		// the second source operand which can be an integer

  bool arp;	// if its to load from arp
  int offset;	// ARP offset (only if src1 == "ARP")

  struct ins_node* next;

} ins;

// Allocation basis
int 	lookup(VALUE value);
void 	store(VALUE value);
void 	load(VALUE value);
NAME 	allocate(VALUE value);

// --------------------------------------------------------------------------------------

// -- Register's functions
reg* reg_get();				// returns the next register to be used
reg* reg_search(VALUE value);		// returns the register's struct

reg* reg_ensure(VALUE value);		// insert the given value into a register
reg* reg_allocate(VALUE value);		// allocates the given register
void reg_free(reg* reg);			// frees the given register

// --------------------------------------------------------------------------------------

// -- Instruction's ADT
extern int 	distance(ins *p, VALUE value); 	// the distance to the given name
extern void 	checkInstruction(ins *p); 	// check the instruction
extern void 	dumpInstruction(ins *p);
extern void 	printInstruction(ins *p);
extern ins* 	createInstruction(int i);
extern void 	setInstructionDestOperand(ins *p, char c);
extern void 	setInstructionDest(ins *p, char *d);
extern void 	setInstructionSource1Operand(ins *p, char c);
extern void 	setInstructionSource1(ins *p, char *s);
extern void 	setInstructionSource2Operand(ins *p, char c);
extern void 	setInstructionSource2(ins *p, char *s);

extern int 	isNumeric(char *p);
extern int 	isRegister(char *p);
extern int 	isVar(char *p);
extern int 	isTemp(char *p);
extern int 	isSymbol(char *p);

#endif
