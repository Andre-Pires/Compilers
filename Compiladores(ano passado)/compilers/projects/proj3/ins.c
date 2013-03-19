#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "ins.h"
#include "map.h"
#include "basicblock.h"
#include "reg.h"

#define MAXDIST 32767
#define append(x) appendInstruction(Output, x);
#define copy(a,b) strncpy(a, b, MAX_VAR_NAME_SIZE)
#define strequal(a,b) !strncmp(a, b, MAX_VAR_NAME_SIZE)


//#define VERBOSE

extern int idx;
extern BasicBlock* Output;
extern table* registers;
extern VarMap* LocalVariableMap;

extern void appendInstruction(BasicBlock *p, ins* ip);
extern void load(VALUE var);
extern void store(VALUE var);
extern int loaded(VALUE var);
extern int stored(VALUE var);


/* ********************************************************************
 *   REGISTER's OPERATIONS
 * ********************************************************************/

// reg_search - returns the register holding the given value
reg* reg_search(VALUE value){
	reg* aux;

	#ifdef VERBOSE
//		printf(" [reg_search] for value '%s'\n", value);
	#endif
	if(registers!=NULL && registers->length>0){
		aux=registers->first;
		while(aux!=NULL){
			if(strequal(value, aux->value))
				return (reg*)aux;
			aux=aux->next;
		}
	}

	#ifdef ERRORS
		printf(" [reg_search] input error.\n");
	#endif
	return NULL;
}


// reg_get - returns the register to be used
reg* reg_get(){
	reg* res;
	reg* aux;
	int max=-1;
	if(registers==NULL || registers->length<1)
		return NULL;

	if(registers->free){
		// pop free register
		res=registers->first;
		while(res!=NULL && !strequal(res->next->name, "r0")){
			if(res->free==true) break;
			res=res->next;
		}
		registers->free--;
	} else {
		// findMaxNext
		res=(registers->first);
		aux=(registers->first);
		while(aux!=NULL && !strequal(aux->next->name, "r0")){
			if(((aux->dist<0) || (aux->dist)>max) && aux->dirty){
				max=aux->dist;
				res=aux;
			}
			aux=aux->next;
		}
		// recheck
		if(res==NULL){
			// for(...) check if is dirty, then do it.
			for(aux=(registers->first); aux!=NULL; aux=aux->next){
				if(aux->dirty && !strequal(aux->next->name, "r0")){
					max=aux->dist;
					res=aux;
				}
			}
		}
	}

	res->dirty=false;

	#ifdef VERBOSE
		printf(" [reg_get] returning ");
		if(res!=NULL)
			printf(" '%s'\n", res->name);
		else {
			printf(" null\n");
			table_print(registers);
		}
	#endif

	return res;
}
/* ------------------------------------------------------------------------------------------ */

// reg_allocate - allocates a register to hold value
reg* reg_allocate(VALUE value){
	reg *res, *reg;

	reg=reg_get();	// reuse another register
	// isVar(reg->value)
	if(reg!=NULL && reg->dirty==true){
		// saves 'reg' in memory (solution: check for other reg/ print the instruction?)
		res=reg;
	}
	else
		res=reg;

	copy(res->value, value);
	res->dist=-1;
	res->free=false;


	#ifdef VERBOSE
		printf(" [reg_allocate]\t \'%s\' ~~~> \'%s\'\n", value, res->name);
	#endif

	return res;
}

// reg_ensure - insert value into a register; loading it if needed
reg* reg_ensure(VALUE value){
	reg *res;
	
	res=reg_search(value);
	if(res==NULL)
		res=reg_allocate(value);

	#ifdef VERBOSE
		printf(" [reg_ensure]\t \'%s\' ~~~> \'%s\'\n", value, res->name);
	#endif

	return res;
}

// reg_free - frees the given register
void reg_free(reg* reg){

	#ifdef VERBOSE
		printf(" [reg_free]\t \'%s\' <<~~  \'%s\'\n", reg->value, reg->name);
	#endif

	if(reg==NULL) return;
	if(!strequal(reg->value, "store")){
		bzero(reg->value, MAX_VAR_NAME_SIZE);	// !!
		reg->free=true;
		reg->dirty=true; //
		reg->dist=MAXDIST;
		registers->free++;
	}
}



/* ------------------------------------------------------------------------------------------ */
void checkInstruction(ins *p){
	reg *rz=NULL;
	reg *rx=NULL;
	reg *ry=NULL;
	reg *rt=NULL;	// temporary register (may or not be used)
	ins *ip=NULL;	// auxiliary instruction pointer (for other registers)
	ins *ti=NULL;	// temporary instruction pointer (to be used with the temporary register)
	ins *mi=NULL;	// main instruction pointer (used with the final instruction)


	/*
	 *  >> input: rz = rx <op> ry
	 *
	 *
	 *	rx = ARP + lookup(rx->value)
	 *    	rx = * rx
	 *    	ry = ARP + lookup(ry->value)
	 *    	ry = * ry
	 *    	rt = rx <op> ry
	 *    	rz = ARP + lookup(rz->value)
	 *	*rz = rt
	 */


	if(p == NULL)
		return;

	#ifdef VERBOSE
		printf("\n");
		table_print(registers);
		printf("[checkInstruction] ");
		printInstruction(p);
	#endif



// :: -------------------------------- ::   THE ALGORITHM   ::

// 1st step:  ensure that 'rx' and 'ry' have register
// --

	// checking 'rx'
	if((p->src1[0] != '\0') && !isNumeric(p->src1)){
		rx=reg_search(p->src1);
		if(rx==NULL){
	
			// allocates register
			rx=reg_ensure(p->src1);
			if(isVar(p->src1)){
				
				// loading the local variable from memory
				load(p->src1);
				
				ip = createInstruction(idx++);
				copy(ip->dst, rx->name);
				ip->arp=true;
				ip->offset=lookup(p->src1);
				append(ip);

				ip = createInstruction(idx++);
				copy(ip->dst, rx->name);
				ip->ops1='*';
				copy(ip->src1, rx->name);
				append(ip);
			}
			if(rx!=NULL){
				// set properties for register
				rx->dist=distance(p, rx->value);
				rx->dirty=false;
			}
		}
	} else rx=NULL;

	// checking 'ry'
	if((p->src2[0] != '\0') && !isNumeric(p->src2)){
		ry=reg_search(p->src2);
		if(ry==NULL){

			// allocates register
			ry=reg_ensure(p->src2);
			if(isVar(p->src2)){
				
				// loading the local variable 'ry' from memory
				load(p->src2);
				
				// loading the local variable 'ry' from memory
				ip = createInstruction(idx++);
				copy(ip->dst, ry->name);
				ip->arp=true;
				ip->offset=lookup(p->src2);
				append(ip);
	
				ip = createInstruction(idx++);
				copy(ip->dst, ry->name);
				ip->ops1='*';
				copy(ip->src1, ry->name);
				append(ip);
			}
			if(ry!=NULL){
				// set properties for register
				ry->dist=distance(p, ry->value);
				ry->dirty=true;
			}
		}
	} else ry=NULL;

// 2nd step: allocate the 'rt' temporary register; creates the 'ti' temporary instruction
// --

	ti = createInstruction(idx++);

	// get 'rx'
	if(isNumeric(p->src1))
		copy(ti->src1, p->src1);  // found a constant
	else if(rx!=NULL)
		copy(ti->src1, rx->name); // got the 'rx'

	// get the operator
	ti->ops2=p->ops2;

	// get 'ry'
	if(isNumeric(p->src2))
		copy(ti->src2, p->src2);  // found a constant
	else if(ry!=NULL)
		copy(ti->src2, ry->name); // got the 'ry'

	if((p->dst[0] != '\0') && !isNumeric(p->dst)){

		// allocate the 'rt' register ("r0" by default)
		rt=reg_search("store");
//		rt=reg_get();
		if(rt!=NULL)
			rt->dirty=false;
	} else rt=NULL; // this could lead to an error
	if(rt!=NULL)
		copy(ti->dst, rt->name);

	append(ti);

// 3rd step: frees if possible frees 'rx' and 'ry'
// --

	// free 'rx'
	if((rx!=NULL) && (rx->dist==MAXDIST || rx->dist==-2))
		reg_free(rx);
	// free 'ry'
	if((ry!=NULL) && (ry->dist==MAXDIST || ry->dist==-2))
		reg_free(ry);

// 4th step: allocate the 'rz' register and create the main instruction 'mi'
// --

	mi = createInstruction(idx++);

	// allocate the 'rz' register
	if((p->dst[0] != '\0') && !isNumeric(p->dst)){

		// store
		store(p->dst);
		rz=reg_search(p->dst);
		if(rz==NULL){
			
			// allocates register
			rz=reg_ensure(p->dst);

			if(isVar(p->dst)){
				// loads the local variable for store operation
				ip = createInstruction(idx++);
				copy(ip->dst, rz->name);
				ip->arp=true;
				ip->offset=lookup(p->dst);
				append(ip);
			}
			if(rz!=NULL){
				// set properties for register
				rz->dist=distance(p, rz->value);
				rz->dirty=false;
			}
		}
	} else rz=NULL; // this would be an error
	if(rz!=NULL)
		copy(mi->dst, rz->name);
	if(rt!=NULL)
		copy(mi->src1, rt->name);
	if(isVar(p->dst))
		mi->opd='*';
	append(mi);


// 5th step: frees 'rt'; if possible frees 'rz'
// --

	#ifdef VERBOSE
		if(rt!=NULL) printf(" [rt] store: %s :: (%s)\n", rt->name, rt->value);
		else printf(" [rt] is null\n");
		if(rz!=NULL) printf(" [rz] store: %s :: (%s)\n", rz->name, rz->value);
		else printf(" [rz] is null\n");
	#endif
	// free 'rt'
	if(rt!=NULL) reg_free(rt);
	// free 'rz'
	if((rz!=NULL) && (rz->dist==MAXDIST || rz->dist<0))
		reg_free(rz);

// 6th step: set the dirty property for the registers
// --
	// check 'rx'
	if(rx!=NULL)
		rx->dirty=true;
	// check 'ry'
	if(ry!=NULL)
		ry->dirty=true;
	// check 'rt'
	if(rt!=NULL)
		rt->dirty=true;
	// check 'rz'
	if(rz!=NULL)
		rz->dirty=false;

// nota: um registo e' dirty apenas quando o seu conteudo e' manipulado na memoria !!!!
//      (confirmar e corrigir se necessario o 6o passo)
//      mudar os valores de dirty para oposto:  'false' <-> 'true'

// :: -------------------------------- ::   THE END   ::

	#ifdef VERBOSE
		table_print(registers);
		printf("\n");
	#endif
	return;
}
/* ------------------------------------------------------------------------------------------ */
int distance(ins *p, NAME name){
	ins* aux;
	for(aux=p->next; aux!=NULL; aux=aux->next){
		if(strequal(name, aux->src1) || strequal(name, aux->src2))
			return aux->idx;
		if(strequal(name, aux->dst))
			return -2;
	}
	return MAXDIST; // not found
}


/* ------------------------------------------------------------------------------------------ */
void printInstruction(ins *p){
  if(p == NULL){
    return;
  } 
    printf("\t");

    if(p->opd != ' ')
      printf("%c",p->opd);
    printf("%s = ",p->dst);
    if(p->arp==true){
	    printf("ARP + %d\n", p->offset);
	    return;
    }


    if(p->ops1 != ' ')
      printf("%c",p->ops1);
    printf("%s",p->src1);
    if(p->ops2 != ' '){
      if(p->ops2 == '*'){
        printf(" %c",p->ops2);
      } else {
        printf(" %c ",p->ops2);
      }
    }
    if(p->src2[0] != '\0')
	printf("%s",p->src2);
    printf("\n");
  
}
/* ------------------------------------------------------------------------------------------ */
void dumpInstruction(ins *p){
  if(p == NULL){
    printf("(nil)");
  } else {

    if(p->opd != ' ')
      printf("opd: (%c)",p->opd);
    printf("dst:(%s) ",p->dst);
    if(p->ops1 != ' ')
      printf("ops1: (%c)",p->ops1);
    printf("src1: (%s)",p->src1);
    if(p->ops2 != ' ')
      printf("ops2:(%c)",p->ops2);
    if(p->src2[0] != '\0')
      printf("src2: (%s) ",p->src2);
  }
}
/* ------------------------------------------------------------------------------------------ */
ins* createInstruction(int i){
  ins *res;

  res = (ins*)malloc(sizeof(ins));
  if(res == NULL){
    return res;
  }

  res->prev = NULL;
  res->idx = i;
  res->opd = ' ';
  res->dst[0] = '\0';
  res->ops1 = ' ';
  res->src1[0] = '\0';
  res->ops2 = ' ';
  res->src2[0] = '\0';
  res->next = NULL;

  res->arp=false;
  res->offset=0;

  return res;
}

/* ------------------------------------------------------------------------------------------ */
void setInstructionDest(ins *p, char *d){
  if(p != NULL){
    strncpy(p->dst,d,MAX_VAR_NAME_SIZE);
  }
}

void setInstructionDestOperand(ins *p, char c){
  if(p != NULL){
    p->opd = c;
  }
}

void setInstructionSource1(ins *p, char *s){
  if(p != NULL){
    strncpy(p->src1,s,MAX_VAR_NAME_SIZE);
  }
}

void setInstructionSource1Operand(ins *p, char c){
  if(p != NULL){
    p->ops1 = c;
  }
}

void setInstructionSource2(ins *p, char *s){
  if(p != NULL){
    strncpy(p->src2,s,MAX_VAR_NAME_SIZE);
  }
}

void setInstructionSource2Operand(ins *p, char c){
  if(p != NULL){
    p->ops2 = c;
  }
}

/* ------------------------------------------------------------------------------------------ */
int isNumeric(char *p){
  if(p == NULL)
    return 0;
 return isdigit(p[0]);
}

int isRegister(char *p){
  if(p == NULL)
    return 0;
  if(p[0] == 'r')
    return 1;
  return 0;
}

int isVar(char *p){
  if(p == NULL)
    return 0;
  if((p[0] != 't') && (p[0] != 'r') && (!isdigit(p[0])))
    return 1;
  return 0;
}

int isTemp(char *p){
  if(p == NULL)
    return 0;
  if(p[0] == 't')
    return 1;
  return 0;
}

int isSymbol(char *p){
  if(p == NULL)
    return 0;
  if((p[0] != 'r') && (!isdigit(p[0])))
    return 1;
  return 0;
}
/* ------------------------------------------------------------------------------------------ */




	/*///-------------------------------------------------------------------------
	ins *ip;
 	res=reg_search(value);
	if(res==NULL){

		// allocates a register for 'res'
		res=reg_allocate(value);
		load(res->value);

		if(isNumeric(value)){
			// inserts the constant in the register
			ip = createInstruction(idx++);
			copy(ip->dst, res->name);
			copy(ip->src1, res->value);
			append(ip);
		}
		if(isVar(value)){
			// loading the local variable 'res' from memory
			ip = createInstruction(idx++);
			copy(ip->dst, res->name);
			ip->arp=true;
			ip->offset=lookup(value);
			append(ip);

			ip = createInstruction(idx++);
			copy(ip->dst, res->name);
			ip->ops1='*';
			copy(ip->src1, res->name);
			append(ip);
		}
	}
	**///-------------------------------------------------------------------------

