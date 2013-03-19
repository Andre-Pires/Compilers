#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include "ins.h"

typedef struct BB {

  struct BB *prev;

  int idx;			// just a general index
  ins *head;			// the first instruction of this basic block;
  ins *tail;			// the last instruction of this basic block;

  struct BB *next;

} BasicBlock;

extern BasicBlock*	createBasicBlock(int i);
extern void 		checkBasicBlock(BasicBlock *p);
extern void 		dumpBasicBlock(BasicBlock *p);
extern void 		printBasicBlock(BasicBlock *p);
extern int 		getIndex(BasicBlock *p);
extern ins* 		getHeadInstruction(BasicBlock *p);
extern ins* 		getTailInstruction(BasicBlock *p);
extern void 		appendInstruction(BasicBlock *p, ins *ip);

#endif
