#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "ins.h"

typedef struct BB {
  struct BB *prev;
  int idx;			// just a general index
  ins *head;			// the first instruction of this basic block;
  ins *tail;			// the last instruction of this basic block;
  struct BB *next;
} BasicBlock;


/* -------------------------------------------------------------------------------------- */
BasicBlock* createBasicBlock(int i){
  BasicBlock* res;

  res = (BasicBlock*)malloc(sizeof(BasicBlock));
  if(res == NULL){
    printf(" *** Error: Could not allocte BasicBlock (createBasicBlock:BasicBlock)\n");
    return NULL;
  }

  res->prev = NULL;
  res->idx  = i;
  res->head = NULL;
  res->tail = NULL;
  res->next = NULL;

  return res;
}

/* -------------------------------------------------------------------------------------- */
void checkBasicBlock(BasicBlock *p){
    ins *tmp;
    
    if(p == NULL) return;

    tmp = p->head;
    while (tmp != NULL){
	checkInstruction(tmp);
	tmp = tmp->next;
    }
}

/* -------------------------------------------------------------------------------------- */
void dumpBasicBlock(BasicBlock *p){
  int i;
  ins *tmp;

  if(p == NULL){
    return;
  }
  i = 0;
  tmp = p->head;
  while (tmp != NULL){
    printInstruction(tmp);
//    printf("\n");
    tmp = tmp->next;
    i++;
  }
}

/* -------------------------------------------------------------------------------------- */
void printBasicBlock(BasicBlock *p){
  int i;
  ins *tmp;

  if(p == NULL){
    printf("(nil)");
    return;
  }
  printf(" Basic Block: %d\n",p->idx);
  i = 0;
  tmp = p->head;
  while (tmp != NULL){
    printf("%d: ",i);
    printInstruction(tmp);
  //  printf("\n");
    tmp = tmp->next;
    i++;
  }
}

/* -------------------------------------------------------------------------------------- */
int getIndex(BasicBlock *p){
  if(p == NULL)
    return -1;
  else
    return p->idx;
}

/* -------------------------------------------------------------------------------------- */
ins* getHeadInstruction(BasicBlock *p){
  if(p == NULL)
    return NULL;
  else
    return p->head;
}

/* -------------------------------------------------------------------------------------- */
ins* getTailInstruction(BasicBlock *p){
  if(p == NULL)
    return NULL;
  else
    return p->tail;
}

/* -------------------------------------------------------------------------------------- */
void appendInstruction(BasicBlock *p, ins *ip){
  if((p == NULL) || (ip == NULL)){
    return;
  }
  if(p->head == NULL){
    p->head = ip;
    p->tail = ip;
  } else {
    p->tail->next = ip;
    ip->prev =  p->tail;
    ip->next =  NULL;
    p->tail = ip;
  }
}

