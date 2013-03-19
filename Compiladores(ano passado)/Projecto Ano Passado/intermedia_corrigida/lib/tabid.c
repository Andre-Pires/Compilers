/* $Id: tabid.c,v 1.1 2005/10/17 12:51:02 prs Exp $ */
#include "tabid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yyerror(char*);
static char buf[80]; /* for error messages */
int IDdebug;

static struct id { int type, attrib; char *name; struct id *next; } *root = 0;
/* define a new  ID => 'name' != 0 (if 'next' is 0 then EOF)
   define a new BUCKET => 'name' == 0 && 'next' points to previous BUCKET
*/

void *IDroot(void *swap) {
  struct id *old = root;
  root = (struct id *)swap;
  return old;
}

static int level;
static void IDadd(int typ, char *s, int attrib) {
  struct id *aux = (struct id*)malloc(sizeof(struct id));

  if (aux == 0) { yyerror("No memory.\n"); return; }
  aux->name = s;
  aux->next = root;
  aux->type = typ;
  aux->attrib = attrib;
  root = aux;
  if (IDdebug != 0) {
    if (s == 0) printf(">>>PUSH=%d\n", level);
    else printf(">>>ADD=%s\n", s);
  }
}

void IDpush() { level++; IDadd(0,0,0); }
void IDpop() {
  struct id *aux;

  while ((aux = root) != 0) {
    root = aux->next;
    if (aux->name == 0) { free(aux); break; }
    free(aux);
  }
  if (IDdebug != 0) printf(">>>POP=%d\n", level);
  level--;
}

/* insert a new ID into the current bucket, return:
   1 - if is new ID (might have been defined in an upper bucket)
   0 - there is an ID with the same name in the bucket
*/
int IDnew(int typ, char *s, int attrib) {
  struct id *aux;

  for (aux = root; aux != 0 && aux->name != 0; aux = aux->next)
    if (strcmp(aux->name, s) == 0) {
      if (attrib != IDtest) {
        sprintf(buf, "\t%s: already defined.\n", s);
        yyerror(buf);
      }
      return 0;
    }
  IDadd(typ, s, attrib);
  return 1;
}

int IDreplace(int typ, char *s, int attrib) {
  struct id *aux;

  for (aux = root; aux != 0; aux = aux->next)
    if (aux->name != 0 && strcmp(aux->name, s) == 0) {
      aux->type = typ;
      aux->attrib = attrib;
      return 1;
    }
  return -1;
}

/* find an ID, return:
   -1 - if no ID can be found in any visible bucket up to the root
   type - there is an accessible ID previously defined
*/
int IDfind(char *s, int *attrib) {
  struct id *aux;

  for (aux = root; aux != 0; aux = aux->next)
    if (aux->name != 0 && strcmp(aux->name, s) == 0) {
      if (attrib != 0 && attrib != ((int*)IDtest)) *attrib = aux->attrib;
      return aux->type;
    }
  if (attrib != ((int*)IDtest)) {
    sprintf(buf, "\t%s: undefined.\n", s);
    yyerror(buf);
  }
  return -1;
}

int IDforall(IDfunc f) {
  struct id *aux;
  int cnt = 0, ret;

  for (aux = root; aux != 0; aux = aux->next, cnt += ret)
    if (aux->name == 0) {
      if ((ret = (*f)(0,"",0)) < 0)
        break;
    }
    else
      if ((ret = (*f)(aux->type, aux->name, aux->attrib)) < 0)
        break;

  return cnt;
}

void IDprint() {
  struct id *aux;

  for (aux = root; aux != 0; aux = aux->next)
    if (aux->name == 0)
      printf(":");
    else
      printf(" %s", aux->name);
  printf("\n");
}
