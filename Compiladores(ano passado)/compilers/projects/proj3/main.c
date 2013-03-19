#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#define MAX_NUM_LOCAL_VARIABLES	64

#define DEBUG



#include "map.h"
#include "ins.h"
#include "basicblock.h"
#include "reg.h"

/* ------------------------------------------------------------------------------ */
/* Global Variables:								  */
/* ------------------------------------------------------------------------------ */
int 	NumberLocalVariables;
VarMap* LocalVariableMap;

table*	registers;
int 	NumberLoads;
int 	NumberStores;
int 	NumberRegisters;
BasicBlock* 	Code;
int 		idx; // the Output instruction's index
BasicBlock*	Output;

/* *******************************************************************************
 *   ADT
 * ***************************************************************************** */
void count_Loads_and_Stores(){
	int i;
	VarMap *vm;
	NumberLoads=0;
	NumberStores=0;
	for(i=0; i<NumberLocalVariables; i++){
		vm = &LocalVariableMap[i];
		NumberLoads+=vm->loaded;
		NumberStores+=vm->stores;
	}
}
/* ------------------------------------------------------------------------------ */
void initDataStructures(){
  NumberLocalVariables = 0;
  LocalVariableMap = createVarMaps(MAX_NUM_LOCAL_VARIABLES);
  Output = createBasicBlock(0);
  idx = 0;
}

/* ------------------------------------------------------------------------------ */
void printLocalVariableMap(){
  int i;
  VarMap *vm;

  for(i = 0; i < NumberLocalVariables; i++){
    vm = &LocalVariableMap[i];
    printVarMap(vm); 
    printf("\n");
  }
}

/* ------------------------------------------------------------------------------ */
void readInstructionsFromFile(char *fname){
  int i;
  ins *ip;
  FILE *fp;
  char tk[4]={' ', '\t', '\n', '\0'};
  char str[80];
  char *s1, *s2, *s3, *s4, *s5;

  i = 0;
  fp = fopen(fname,"r");
  if(fp == NULL){
    printf(" *** Error: Cannot open (%s) as instruction input file \n",fname);
    Code = NULL;
    return;
  } 

  Code = createBasicBlock(0);

  while(fgets(str,79,fp) != NULL){

#ifdef DEBUG 
// printf("read::: %s", str);
#endif

    s1 = (char*)strtok(str, tk);
    if(s1 == NULL){
      break;
    }
    s2 = (char*)strtok(NULL, tk);
    if(s2[0] != '='){
      printf(" *** Error: Could not locate '=' operator in instruction as second field of input\n");
      continue;
    }
    s3 = (char*)strtok(NULL, tk);

    s4 = (char*)strtok(NULL, tk);
    if(s4 != NULL){
      s5 = (char*)strtok(NULL, tk);
    } else {
      s5 = NULL;
    }
#ifdef DEBUG
//    printf(" parsed::: %s  %s  %s  %s  %s\n",s1, s2, s3, s4, s5);
#endif

    ip = createInstruction(i);

    if(s1[0] == '*'){
      setInstructionDestOperand(ip,'*');
      setInstructionDest(ip, &s1[1]);
    } else {
      setInstructionDest(ip, &s1[0]);
    }
    if((s3[0] == '*') || (s3[0] == '-')){
      setInstructionSource1Operand(ip, s3[0]);
      setInstructionSource1(ip, &s3[1]);
    } else {
      setInstructionSource1(ip, &s3[0]);
    }
    if(s4 != NULL){
      setInstructionSource2Operand(ip, s4[0]);
      if(s5 != NULL){
        setInstructionSource2(ip, s5);
      } else {
	printf(" *** Error: Was expecting a second operand in instruction %d (remove infix operand)\n",i);
        setInstructionSource2Operand(ip,' ');
      }
    }

    appendInstruction(Code,ip); 
#ifdef DEBUG 
//    printf("  ...dumping instruction::\n");
//      dumpInstruction(ip);
//    printf("\n");
#endif

    i++;
  }

#ifdef DEBUG 
 // printf(" Read %d instructions \n",i);
 // printBasicBlock(Code);
#endif

  fclose(fp);
}

/* ------------------------------------------------------------------------------ */
void readVarMapFromFile(char* fname){
  int i;
  FILE *fp;
  char str[80];
  char *s1, *s2;

  i = 0;
  fp = fopen(fname,"r");
  if(fp == NULL){
    printf(" *** Error: Cannot open (%s) as local varaible mapping file \n",fname);
    return;
  }

  while(fgets(str,79,fp) != NULL){
#ifdef DEBUG
   //printf(" read(2) ::: %s \n",str);
#endif
    s1 = (char*)strtok(str," \t");
    s2 = (char*)strtok(NULL," \t");
#ifdef DEBUG
//    printf(" parsed var map  %s : %d \n",s1, atoi(s2));
#endif
    NumberLocalVariables++;
    setVarMap(LocalVariableMap, NumberLocalVariables, i, s1, atoi(s2), s2);
    
    i++;
  }

#ifdef DEBUG
//  printf(" Read %d local variable offset mappings\n",i);
//  printLocalVariableMap();
#endif
}


/* ------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------ */

int main(int argc, char **argv){
  NumberLoads=0;
  NumberStores=0;

  if(argc !=  4){
    printf(" *** Error: Usage %s <instr_file> <num_registers> <map_file>\n",argv[0]);
    return -1;
  }

  initDataStructures();

  readInstructionsFromFile(argv[1]);

  NumberRegisters = atoi(argv[2]);
  if(NumberRegisters <= 0){
	/* DO SOMETHING */
	printf(" Number of Registers: %d\n",NumberRegisters);
	printf(" Number Load Operations: 0\n");
	printf(" Number Store Operations: 0\n");
	return 0;
  }

  readVarMapFromFile(argv[3]);

  /* YOUR CODE HERE */
  printf(" Number of Registers: %d\n", NumberRegisters); // ok

  registers=table_create(NumberRegisters);
  
 // ciclo para usar o checkInstruction() em cada BasicBlock
  checkBasicBlock(Code);
  count_Loads_and_Stores();

  // outputs the result
//  printBasicBlock(Code);
  dumpBasicBlock(Output);


  printf(" Number Load Operations: %d\n", NumberLoads);
  printf(" Number Store Operations: %d\n", NumberStores);

  return 0;
}

