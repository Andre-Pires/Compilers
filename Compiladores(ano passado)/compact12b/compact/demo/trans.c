/* $Id: trans.c,v 1.4 2004/12/09 17:25:13 prs Exp $ */
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"
#include "tabid.h"
#define SUB(x)  value.sub.n[x]

static FILE *out;

static void decl(Node *p) {
  char *name;
  int i;

  if (p != 0 && p->type == nodeOpr)
    switch (p->attrib) {
      case WHILE:
	decl(p->SUB(1));
	break;
      case IF:
	decl(p->SUB(1));
	if (p->value.sub.num > 2) decl(p->SUB(2));
	break;
      case ';':
	for (i = 0; i < p->value.sub.num; i++)
	  decl(p->SUB(i));
	break;
      case '=':
	name = p->SUB(0)->value.s;
	if (IDfind(name, (int*)IDtest) == -1) {
	  fprintf(out, "int %s;\n", name);
	  IDnew(INTEGER, name, 0);
	}
	break;
      default:
	break;
    }
}

static int eval(Node *p) {
  char *name;

  if (p == 0) return;
  switch(p->attrib) {
  case INTEGER:
    fprintf(out, " %d ", p->value.i);
    break;
  case STRING:
    fprintf(out, "printf(\"%%s\\n\", \"%s\");\n", p->value.s);
    break;
  case VARIABLE:
    if (IDfind(p->value.s, 0) >= 0)
      fprintf(out, " %s ", p->value.s);
    break;
  case WHILE:
    fprintf(out, "while(");
    eval(p->SUB(0));
    fprintf(out, ") {\n");
    eval(p->SUB(1));
    fprintf(out, ";}\n");
    break;
  case IF:
    fprintf(out, "if (");
    eval(p->SUB(0));
    fprintf(out, ") {\n");
    eval(p->SUB(1));
    if (p->value.sub.num > 2) { /* if else */
	fprintf(out, ";} else {\n");
	eval(p->SUB(2));
    }
    fprintf(out, ";}\n");
    break;
  case READ:
    if (IDfind(p->value.s, 0) >= 0)
      fprintf(out, "scanf(\"%%d\", &%s);\n", p->value.s);
    break;
  case PRINT:
    fprintf(out, "printf(\"%%d\\n\", ");
    eval(p->SUB(0));
    fprintf(out, ");\n");
    break;
  case ';':
    eval(p->SUB(0));
    fprintf(out, ";\n");
    eval(p->SUB(1));
    fprintf(out, ";\n");
    break;
  case '=':
    fprintf(out, " %s = ", p->SUB(0)->value.s);
    eval(p->SUB(1));
    break;
  case UMINUS:
    fprintf(out, " - ");
    eval(p->SUB(0));
    break;
  default:
    eval(p->SUB(0));			/* evaluate first argument    */
    switch(p->attrib) {			/* make the operation ...     */
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '<':
    case '>':
      fprintf(out, " %c ", p->attrib); break;
    case GE:    fprintf(out, " >= "); break;
    case LE:    fprintf(out, " <= "); break;
    case NE:    fprintf(out, " != "); break;
    case EQ:    fprintf(out, " == "); break;
    default:    fprintf(stderr, "unknown %d ('%c')\n", p->attrib, p->attrib);
    }
    eval(p->SUB(1));			/* evaluate second argument   */
  }
}

void evaluate(Node *p) {
  extern char *outfile;
  if (outfile != 0) {
    int len = strlen(outfile);
    if (len > 4 && outfile[len-4] == '.')
	strcpy(outfile+len-4, ".c");
    if ((out = fopen(outfile, "w")) == 0) {
      extern int errors;
      perror(outfile);
      errors++;
      return;
    }
  }
  else
    out = stdout;
  fprintf(out, "int reg[26];\nint main() {\n");
  decl(p);
  eval(p);
  fprintf(out, "return 0;\n}\n");
}
