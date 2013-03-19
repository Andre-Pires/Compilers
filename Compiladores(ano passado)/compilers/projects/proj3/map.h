#ifndef MAP_H
#define MAP_H

#define MAX_VAR_NAME_SIZE 8

typedef struct {
  char var[MAX_VAR_NAME_SIZE];
  char os[MAX_VAR_NAME_SIZE];  // offset in string format
  int offset;
  // user defined
  int loaded; // '0' or '1'
  int stores; // number of times stored
} VarMap;

extern VarMap	*lookUpVarMap(char* vname);	//
extern int	lookup(char* vname);		//
extern int 	loaded(char* vname); 		//
extern int 	stored(char* vname); 		//

extern void 	printVarMap(VarMap *p);
extern VarMap* 	createVarMaps(int n);
extern void 	setVarMap(VarMap *vm, int sz, int idx, char *vname, int off, char *os);
extern void 	clearVarMap(VarMap *vm, int sz, int idx);

#endif
