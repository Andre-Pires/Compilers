#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


#include "ins.h"
#include "map.h"

extern int isVar(char* vn);

extern int NumberLocalVariables;
extern VarMap *LocalVariableMap;

/* ------------------------------------------------------------------------------ */

// get the address of the given variable; sets the number of stores/loads on the varmap
int lookup(VALUE var){
	VarMap* p;

	if(isVar(var))
		p=lookUpVarMap(var);
	else return 0;

	return p->offset;
}
/* ------------------------------------------------------------------------------------------ */
int loaded(VALUE var){
	VarMap* p;
	if(isVar(var))
		p=lookUpVarMap(var);
	else return 0;

	return p->loaded;
}
/* ------------------------------------------------------------------------------------------ */
int stored(VALUE var){
	VarMap* p;
	if(isVar(var))
		p=lookUpVarMap(var);
	else return 0;

	return p->stores;
}
/* ------------------------------------------------------------------------------------------ */
void store(VALUE var){
	VarMap* p;
	
	if(isVar(var))
		p=lookUpVarMap(var);
	else return;

	p->stores++;
}
/* ------------------------------------------------------------------------------------------ */
void load(VALUE var){
	VarMap* p;
	
	if(isVar(var))
		p=lookUpVarMap(var);
	else return;

	p->loaded=true;
}
/* ------------------------------------------------------------------------------ */
VarMap *lookUpVarMap(char* vname){
  int i;
  VarMap *vm;

  for(i = 0; i < NumberLocalVariables; i++){
    vm = &LocalVariableMap[i];
    if(strcmp(vm->var, vname) == 0){
      return vm;
    }
  }
  return NULL;
}
/* ------------------------------------------------------------------------------------------ */
void printVarMap(VarMap *p){
  if(p == NULL)
    printf(" (nil) ");
  else 
    printf(" (%s : %d) ",p->var, p->offset);
}

/* ------------------------------------------------------------------------------------------ */
VarMap* createVarMaps(int n){
  int i;

  VarMap *res;
  if(n <= 0)
    return NULL;

  res = (VarMap*)malloc(sizeof(VarMap)*n);
  if(res == NULL)
    return NULL;

  for(i = 0; i < n; i++){
    res[i].var[0] = '\0';
    res[i].offset = 0;
    res[i].loaded=0;
    res[i].stores=0;
  }

  return res;
}

/* ------------------------------------------------------------------------------------------ */
void setVarMap(VarMap *vm, int sz, int idx, char *vname, int off, char* os){
  VarMap *tmp;

  if((vm == NULL) || (sz <= 0) || (idx < 0) || (idx >= sz)){
    printf(" *** Error: Invalid invocaton of setVarMap. Ignored.\n");
    return;
  }
  if((vname == NULL) || (off < 0) ){
    printf(" *** Error: Invalid var map arguments (vname is null or offset is negative. Ignored.\n");
    return;
  }
  
  tmp = &vm[idx];
  strncpy(tmp->var,vname,MAX_VAR_NAME_SIZE);
  strncpy(tmp->os, os,MAX_VAR_NAME_SIZE);
  tmp->offset = off;
}

/* ------------------------------------------------------------------------------------------ */
void clearVarMap(VarMap *vm, int sz, int idx){
  VarMap *tmp;

  if((vm == NULL) || (sz <= 0) || (idx < 0) || (idx >= sz)){
    printf(" *** Error: Invalid invocaton of clearVarMap. Ignored.\n");
    return;
  }

  tmp = &vm[idx];
  tmp->var[0] = '\0';
  tmp->offset = 0;
}

/* ------------------------------------------------------------------------------------------ */

