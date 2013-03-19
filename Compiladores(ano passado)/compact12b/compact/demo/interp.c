/* $Id: interp.c,v 1.3 2004/02/15 01:14:18 prs Exp $ */
#include <stdio.h>
#include "node.h"
#include "y.tab.h"
#include "tabid.h"
#define SUB(x)  value.sub.n[x]

static int ex(Node *p);
void evaluate(Node *p) { ex(p); }

static int ex(Node *p) {
    int i, val = 0;
    char *name;

    if (p == 0) return 0;
    switch(p->attrib) {
    case INTEGER:
        return p->value.i;
    case STRING:
    	printf("%s\n", p->value.s);
        break;
    case VARIABLE:
	IDfind(p->value.s, &val);
	return val;
    case WHILE:
	while (ex(p->SUB(0)))
	  ex(p->SUB(1));
	break;
    case IF:
	if (ex(p->SUB(0)))
	    ex(p->SUB(1));
	else if (p->value.sub.num > 2)
	    ex(p->SUB(2));
	break;
    case '=':
	name = p->SUB(0)->value.s;
        val = ex(p->SUB(1));
	if (IDfind(name, (int*)IDtest) == -1)
	  IDnew(INTEGER, name, val);
	else
	  IDreplace(INTEGER, name, val);
    	break;
    case READ:
	if (IDfind(p->value.s, 0) >= 0) {
	  scanf("%d", &val);
	  IDreplace(INTEGER, p->value.s, val);
	}
	break;
    case PRINT:  printf("%d\n", ex(p->SUB(0))); break;
    case ';':
	for (i = 0; i < p->value.sub.num; i++)
	  val = ex(p->SUB(i));
	return val;
    case UMINUS: return -ex(p->SUB(0));
    case '+':    return ex(p->SUB(0))  + ex(p->SUB(1));
    case '-':    return ex(p->SUB(0))  - ex(p->SUB(1));
    case '*':    return ex(p->SUB(0))  * ex(p->SUB(1));
    case '/':    return ex(p->SUB(0))  / ex(p->SUB(1));
    case '%':    return ex(p->SUB(0))  % ex(p->SUB(1));
    case '<':    return ex(p->SUB(0))  < ex(p->SUB(1));
    case '>':    return ex(p->SUB(0))  > ex(p->SUB(1));
    case GE:     return ex(p->SUB(0)) >= ex(p->SUB(1));
    case LE:     return ex(p->SUB(0)) <= ex(p->SUB(1));
    case NE:     return ex(p->SUB(0)) != ex(p->SUB(1));
    case EQ:     return ex(p->SUB(0)) == ex(p->SUB(1));
    default:     printf("unknown %d('%c')\n", p->attrib, p->attrib);
    }
    return 0;
}
