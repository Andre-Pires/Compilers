/*
generated at Thu May 16 17:56:53 2013
by $Id: pburg.c,v 2.3a 2012/10/07 00:51:11 prs Exp $
*/
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.3a"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#endif

#line 1 "factorial.brg"

/* Instruction selection with postfix.h
 */
    
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"
#include "y.tab.h"

#ifndef U_
#define U_ "_"
#endif

#define GLOBAL 0
extern FILE *outfp;
extern int lbl;
extern char *mklbl(int n);
extern char **yynames;

int trash;
static int stk;

static int sameVar(NODEPTR_TYPE p) {
  return strcmp(p->SUB(0)->value.s, p->SUB(1)->SUB(0)->value.s) ? 0x7fff : 2;
}
static int sameLoc(NODEPTR_TYPE p) {
  return p->SUB(0)->value.s == p->SUB(1)->SUB(0)->value.s ? 0x7fff : 2;
}

#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
static void yylabel(NODEPTR_TYPE,NODEPTR_TYPE);
static int yyrule(void*, int);

#define yycorpo_NT 1
#define yyinstrucoes_NT 2
#define yypars2_NT 3
#define yyinstrucao_NT 4
#define yyexpressao_NT 5
#define yylvalue_NT 6
#define yystack_NT 7
#define yydupexp_NT 8
#define yylvalue2_NT 9

static YYCONST char *yyntname[] = {
	0,
	"corpo",
	"instrucoes",
	"pars2",
	"instrucao",
	"expressao",
	"lvalue",
	"stack",
	"dupexp",
	"lvalue2",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "ARG",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "NUM",
	/* 260 */ "IDENTIF",
	/* 261 */ "STRN",
	/* 262 */ "WHILE",
	/* 263 */ "IF",
	/* 264 */ "END",
	/* 265 */ "RETURN",
	/* 266 */ "VOID",
	/* 267 */ "PUBLIC",
	/* 268 */ "CONST",
	/* 269 */ "THEN",
	/* 270 */ "ELSE",
	/* 271 */ "DO",
	/* 272 */ "FOR",
	/* 273 */ "IN",
	/* 274 */ "STEP",
	/* 275 */ "UPTO",
	/* 276 */ "DOWNTO",
	/* 277 */ "BREAK",
	/* 278 */ "CONTINUE",
	/* 279 */ "INTEGER",
	/* 280 */ "STRING",
	/* 281 */ "NUMBER",
	/* 282 */ "GE",
	/* 283 */ "LE",
	/* 284 */ "EQ",
	/* 285 */ "NE",
	/* 286 */ "INC",
	/* 287 */ "DEC",
	/* 288 */ "ATRIB",
	/* 289 */ "ADDR",
	/* 290 */ "POINTER",
	/* 291 */ "IFX",
	/* 292 */ "LIST",
	/* 293 */ "VECTOR",
	/* 294 */ "CALL",
	/* 295 */ "CALL2",
	/* 296 */ "NEG",
	/* 297 */ "FACT",
	/* 298 */ "AND",
	/* 299 */ "OR",
	/* 300 */ "PROG",
	/* 301 */ "ADD",
	/* 302 */ "SUBT",
	/* 303 */ "MUL",
	/* 304 */ "DIV",
	/* 305 */ "LT",
	/* 306 */ "GT",
	/* 307 */ "MOD",
	/* 308 */ "PARAMS",
	/* 309 */ "PARS2",
	/* 310 */ "PARS",
	/* 311 */ "PINTR",
	/* 312 */ "INTR",
	/* 313 */ "DECL",
	/* 314 */ "DECLS",
	/* 315 */ "INIT",
	/* 316 */ "NIL",
	/* 317 */ "PNTR",
	/* 318 */ "EXPS",
	/* 319 */ "EXP",
	/* 320 */ "MALL",
	/* 321 */ "BODY",
	/* 322 */ "JZ",
	/* 323 */ "ETIQ",
	/* 324 */ "LABEL",
	/* 325 */ "JNZ",
	/* 326 */ "JMP",
	/* 327 */ "INSTRS",
	/* 328 */ "UMINUS",
	""
};

struct yystate {
	short cost[10];
	struct {
		unsigned int yycorpo:2;
		unsigned int yyinstrucoes:2;
		unsigned int yypars2:2;
		unsigned int yyinstrucao:5;
		unsigned int yyexpressao:5;
		unsigned int yylvalue:2;
		unsigned int yystack:2;
		unsigned int yydupexp:1;
		unsigned int yylvalue2:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yyinstrucoes_NT, 0 };
static short yynts_2[] = { yypars2_NT, yyinstrucoes_NT, 0 };
static short yynts_3[] = { yyinstrucoes_NT, yyinstrucao_NT, 0 };
static short yynts_4[] = { yyinstrucao_NT, 0 };
static short yynts_5[] = { yyinstrucao_NT, yyinstrucao_NT, 0 };
static short yynts_6[] = { yyexpressao_NT, 0 };
static short yynts_7[] = { yycorpo_NT, 0 };
static short yynts_8[] = { yyexpressao_NT, yyexpressao_NT, 0 };
static short yynts_9[] = { yylvalue_NT, 0 };
static short yynts_10[] = { yystack_NT, 0 };
static short yynts_11[] = { yydupexp_NT, yylvalue_NT, 0 };
static short yynts_12[] = { yylvalue2_NT, yyexpressao_NT, 0 };
static short yynts_13[] = { yystack_NT, yystack_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_0,	/* 4 */
	yynts_0,	/* 5 */
	yynts_3,	/* 6 */
	yynts_4,	/* 7 */
	yynts_5,	/* 8 */
	yynts_0,	/* 9 */
	yynts_6,	/* 10 */
	yynts_7,	/* 11 */
	yynts_0,	/* 12 */
	yynts_6,	/* 13 */
	yynts_6,	/* 14 */
	yynts_8,	/* 15 */
	yynts_8,	/* 16 */
	yynts_8,	/* 17 */
	yynts_8,	/* 18 */
	yynts_8,	/* 19 */
	yynts_8,	/* 20 */
	yynts_8,	/* 21 */
	yynts_8,	/* 22 */
	yynts_8,	/* 23 */
	yynts_8,	/* 24 */
	yynts_8,	/* 25 */
	yynts_8,	/* 26 */
	yynts_0,	/* 27 */
	yynts_0,	/* 28 */
	yynts_9,	/* 29 */
	yynts_10,	/* 30 */
	yynts_0,	/* 31 */
	yynts_11,	/* 32 */
	yynts_6,	/* 33 */
	yynts_9,	/* 34 */
	yynts_9,	/* 35 */
	yynts_9,	/* 36 */
	yynts_9,	/* 37 */
	yynts_8,	/* 38 */
	yynts_8,	/* 39 */
	yynts_8,	/* 40 */
	yynts_8,	/* 41 */
	yynts_8,	/* 42 */
	yynts_8,	/* 43 */
	yynts_8,	/* 44 */
	yynts_8,	/* 45 */
	yynts_8,	/* 46 */
	yynts_8,	/* 47 */
	yynts_8,	/* 48 */
	yynts_8,	/* 49 */
	yynts_8,	/* 50 */
	yynts_6,	/* 51 */
	yynts_6,	/* 52 */
	yynts_9,	/* 53 */
	yynts_9,	/* 54 */
	yynts_6,	/* 55 */
	yynts_0,	/* 56 */
	yynts_12,	/* 57 */
	yynts_9,	/* 58 */
	yynts_13,	/* 59 */
	yynts_6,	/* 60 */
	yynts_0,	/* 61 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"corpo: NIL",
/* 2 */	"corpo: instrucoes",
/* 3 */	"corpo: PINTR(pars2,instrucoes)",
/* 4 */	"pars2: PARS2",
/* 5 */	"pars2: IDENTIF",
/* 6 */	"instrucoes: INSTRS(instrucoes,instrucao)",
/* 7 */	"instrucoes: instrucao",
/* 8 */	"instrucao: LIST(instrucao,instrucao)",
/* 9 */	"instrucao: LABEL",
/* 10 */	"instrucao: expressao",
/* 11 */	"instrucao: corpo",
/* 12 */	"instrucao: JMP",
/* 13 */	"instrucao: JZ(expressao,ETIQ)",
/* 14 */	"instrucao: JNZ(expressao,ETIQ)",
/* 15 */	"instrucao: JZ(LT(expressao,expressao),ETIQ)",
/* 16 */	"instrucao: JZ(LE(expressao,expressao),ETIQ)",
/* 17 */	"instrucao: JZ(GT(expressao,expressao),ETIQ)",
/* 18 */	"instrucao: JZ(GE(expressao,expressao),ETIQ)",
/* 19 */	"instrucao: JZ(EQ(expressao,expressao),ETIQ)",
/* 20 */	"instrucao: JZ(NE(expressao,expressao),ETIQ)",
/* 21 */	"instrucao: JNZ(LT(expressao,expressao),ETIQ)",
/* 22 */	"instrucao: JNZ(LE(expressao,expressao),ETIQ)",
/* 23 */	"instrucao: JNZ(GT(expressao,expressao),ETIQ)",
/* 24 */	"instrucao: JNZ(GE(expressao,expressao),ETIQ)",
/* 25 */	"instrucao: JNZ(EQ(expressao,expressao),ETIQ)",
/* 26 */	"instrucao: JNZ(NE(expressao,expressao),ETIQ)",
/* 27 */	"expressao: INT",
/* 28 */	"expressao: STRN",
/* 29 */	"expressao: lvalue",
/* 30 */	"expressao: CALL2(IDENTIF,stack)",
/* 31 */	"expressao: CALL(IDENTIF)",
/* 32 */	"expressao: ATRIB(dupexp,lvalue)",
/* 33 */	"expressao: UMINUS(expressao)",
/* 34 */	"expressao: INC(lvalue,NIL)",
/* 35 */	"expressao: DEC(lvalue,NIL)",
/* 36 */	"expressao: INC(NIL,lvalue)",
/* 37 */	"expressao: DEC(NIL,lvalue)",
/* 38 */	"expressao: MUL(expressao,expressao)",
/* 39 */	"expressao: DIV(expressao,expressao)",
/* 40 */	"expressao: MOD(expressao,expressao)",
/* 41 */	"expressao: ADD(expressao,expressao)",
/* 42 */	"expressao: SUBT(expressao,expressao)",
/* 43 */	"expressao: GT(expressao,expressao)",
/* 44 */	"expressao: LT(expressao,expressao)",
/* 45 */	"expressao: EQ(expressao,expressao)",
/* 46 */	"expressao: NE(expressao,expressao)",
/* 47 */	"expressao: GE(expressao,expressao)",
/* 48 */	"expressao: LE(expressao,expressao)",
/* 49 */	"expressao: AND(expressao,expressao)",
/* 50 */	"expressao: OR(expressao,expressao)",
/* 51 */	"expressao: NEG(expressao)",
/* 52 */	"expressao: FACT(expressao)",
/* 53 */	"expressao: ADDR(lvalue)",
/* 54 */	"expressao: POINTER(lvalue)",
/* 55 */	"dupexp: expressao",
/* 56 */	"lvalue: IDENTIF",
/* 57 */	"lvalue: VECTOR(lvalue2,expressao)",
/* 58 */	"lvalue2: lvalue",
/* 59 */	"stack: EXPS(stack,stack)",
/* 60 */	"stack: expressao",
/* 61 */	"stack: NIL",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_corpo[] = {
	0,
	1,
	2,
	3,
};

static short yydecode_instrucoes[] = {
	0,
	6,
	7,
};

static short yydecode_pars2[] = {
	0,
	4,
	5,
};

static short yydecode_instrucao[] = {
	0,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
};

static short yydecode_expressao[] = {
	0,
	27,
	28,
	29,
	30,
	31,
	32,
	33,
	34,
	35,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	51,
	52,
	53,
	54,
};

static short yydecode_lvalue[] = {
	0,
	56,
	57,
};

static short yydecode_stack[] = {
	0,
	59,
	60,
	61,
};

static short yydecode_dupexp[] = {
	0,
	55,
};

static short yydecode_lvalue2[] = {
	0,
	58,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 9)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yycorpo_NT:	return yydecode_corpo[((struct yystate *)state)->rule.yycorpo];
	case yyinstrucoes_NT:	return yydecode_instrucoes[((struct yystate *)state)->rule.yyinstrucoes];
	case yypars2_NT:	return yydecode_pars2[((struct yystate *)state)->rule.yypars2];
	case yyinstrucao_NT:	return yydecode_instrucao[((struct yystate *)state)->rule.yyinstrucao];
	case yyexpressao_NT:	return yydecode_expressao[((struct yystate *)state)->rule.yyexpressao];
	case yylvalue_NT:	return yydecode_lvalue[((struct yystate *)state)->rule.yylvalue];
	case yystack_NT:	return yydecode_stack[((struct yystate *)state)->rule.yystack];
	case yydupexp_NT:	return yydecode_dupexp[((struct yystate *)state)->rule.yydupexp];
	case yylvalue2_NT:	return yydecode_lvalue2[((struct yystate *)state)->rule.yylvalue2];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_corpo(NODEPTR_TYPE, int);
static void yyclosure_instrucoes(NODEPTR_TYPE, int);
static void yyclosure_instrucao(NODEPTR_TYPE, int);
static void yyclosure_expressao(NODEPTR_TYPE, int);
static void yyclosure_lvalue(NODEPTR_TYPE, int);

static void yyclosure_corpo(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 0, p->cost[yyinstrucao_NT]);
	if (c + 0 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 0;
		p->rule.yyinstrucao = 4;
		yyclosure_instrucao(a, c + 0);
	}
}

static void yyclosure_instrucoes(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 2, c + 0, p->cost[yycorpo_NT]);
	if (c + 0 < p->cost[yycorpo_NT]) {
		p->cost[yycorpo_NT] = c + 0;
		p->rule.yycorpo = 2;
		yyclosure_corpo(a, c + 0);
	}
}

static void yyclosure_instrucao(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 7, c + 0, p->cost[yyinstrucoes_NT]);
	if (c + 0 < p->cost[yyinstrucoes_NT]) {
		p->cost[yyinstrucoes_NT] = c + 0;
		p->rule.yyinstrucoes = 2;
		yyclosure_instrucoes(a, c + 0);
	}
}

static void yyclosure_expressao(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 60, c + 0, p->cost[yystack_NT]);
	if (c + 0 < p->cost[yystack_NT]) {
		p->cost[yystack_NT] = c + 0;
		p->rule.yystack = 2;
	}
	yytrace(a, 55, c + 1, p->cost[yydupexp_NT]);
	if (c + 1 < p->cost[yydupexp_NT]) {
		p->cost[yydupexp_NT] = c + 1;
		p->rule.yydupexp = 1;
	}
	yytrace(a, 10, c + 1, p->cost[yyinstrucao_NT]);
	if (c + 1 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 1;
		p->rule.yyinstrucao = 3;
		yyclosure_instrucao(a, c + 1);
	}
}

static void yyclosure_lvalue(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 58, c + 1, p->cost[yylvalue2_NT]);
	if (c + 1 < p->cost[yylvalue2_NT]) {
		p->cost[yylvalue2_NT] = c + 1;
		p->rule.yylvalue2 = 1;
	}
	yytrace(a, 29, c + 1, p->cost[yyexpressao_NT]);
	if (c + 1 < p->cost[yyexpressao_NT]) {
		p->cost[yyexpressao_NT] = c + 1;
		p->rule.yyexpressao = 3;
		yyclosure_expressao(a, c + 1);
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* ARG */
		break;
	case 257: /* INT */
		/* expressao: INT */
		yytrace(a, 27, 1 + 0, p->cost[yyexpressao_NT]);
		if (1 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 1 + 0;
			p->rule.yyexpressao = 1;
			yyclosure_expressao(a, 1 + 0);
		}
		break;
	case 258: /* NUM */
		break;
	case 259: /* IDENTIF */
		/* pars2: IDENTIF */
		yytrace(a, 5, 0 + 0, p->cost[yypars2_NT]);
		if (0 + 0 < p->cost[yypars2_NT]) {
			p->cost[yypars2_NT] = 0 + 0;
			p->rule.yypars2 = 2;
		}
		/* lvalue: IDENTIF */
		yytrace(a, 56, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
			yyclosure_lvalue(a, 1 + 0);
		}
		break;
	case 260: /* STRN */
		/* expressao: STRN */
		yytrace(a, 28, 3 + 0, p->cost[yyexpressao_NT]);
		if (3 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 3 + 0;
			p->rule.yyexpressao = 2;
			yyclosure_expressao(a, 3 + 0);
		}
		break;
	case 261: /* WHILE */
		break;
	case 262: /* IF */
		break;
	case 263: /* END */
		break;
	case 264: /* RETURN */
		break;
	case 265: /* VOID */
		break;
	case 266: /* PUBLIC */
		break;
	case 267: /* CONST */
		break;
	case 268: /* THEN */
		break;
	case 269: /* ELSE */
		break;
	case 270: /* DO */
		break;
	case 271: /* FOR */
		break;
	case 272: /* IN */
		break;
	case 273: /* STEP */
		break;
	case 274: /* UPTO */
		break;
	case 275: /* DOWNTO */
		break;
	case 276: /* BREAK */
		break;
	case 277: /* CONTINUE */
		break;
	case 278: /* INTEGER */
		break;
	case 279: /* STRING */
		break;
	case 280: /* NUMBER */
		break;
	case 281: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: GE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 21;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 282: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 48, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 22;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 283: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: EQ(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 19;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 284: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: NE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 46, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 20;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 285: /* INC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: INC(lvalue,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 315 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 34, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 8;
				yyclosure_expressao(a, c + 0);
			}
		}
		if (	/* expressao: INC(NIL,lvalue) */
			OP_LABEL(LEFT_CHILD(a)) == 315 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 36, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 10;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 286: /* DEC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: DEC(lvalue,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 315 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 35, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 9;
				yyclosure_expressao(a, c + 0);
			}
		}
		if (	/* expressao: DEC(NIL,lvalue) */
			OP_LABEL(LEFT_CHILD(a)) == 315 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 37, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 11;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 287: /* ATRIB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ATRIB(dupexp,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydupexp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 6;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 288: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: ADDR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 0;
		yytrace(a, 53, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 27;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 289: /* POINTER */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: POINTER(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 28;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 290: /* IFX */
		break;
	case 291: /* LIST */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrucao: LIST(instrucao,instrucao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrucao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucao_NT] + 0;
		yytrace(a, 8, c + 0, p->cost[yyinstrucao_NT]);
		if (c + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = c + 0;
			p->rule.yyinstrucao = 1;
			yyclosure_instrucao(a, c + 0);
		}
		break;
	case 292: /* VECTOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* lvalue: VECTOR(lvalue2,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 3;
		yytrace(a, 57, c + 0, p->cost[yylvalue_NT]);
		if (c + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = c + 0;
			p->rule.yylvalue = 2;
			yyclosure_lvalue(a, c + 0);
		}
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		if (	/* expressao: CALL(IDENTIF) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = 2;
			yytrace(a, 31, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 5;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 294: /* CALL2 */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: CALL2(IDENTIF,stack) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystack_NT] + 3;
			yytrace(a, 30, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 4;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 295: /* NEG */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: NEG(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 2;
		yytrace(a, 51, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 25;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 296: /* FACT */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: FACT(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 0;
		yytrace(a, 52, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 26;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 297: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: AND(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 7;
		yytrace(a, 49, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 23;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 298: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: OR(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 7;
		yytrace(a, 50, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 24;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 299: /* PROG */
		break;
	case 300: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ADD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 41, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 15;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 301: /* SUBT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: SUBT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 16;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 302: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MUL(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 38, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 12;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 303: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: DIV(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 13;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 304: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 44, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 18;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 305: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: GT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 43, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 17;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 306: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MOD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 14;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 307: /* PARAMS */
		break;
	case 308: /* PARS2 */
		/* pars2: PARS2 */
		yytrace(a, 4, 0 + 0, p->cost[yypars2_NT]);
		if (0 + 0 < p->cost[yypars2_NT]) {
			p->cost[yypars2_NT] = 0 + 0;
			p->rule.yypars2 = 1;
		}
		break;
	case 309: /* PARS */
		break;
	case 310: /* PINTR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* corpo: PINTR(pars2,instrucoes) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yypars2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucoes_NT] + 0;
		yytrace(a, 3, c + 0, p->cost[yycorpo_NT]);
		if (c + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = c + 0;
			p->rule.yycorpo = 3;
			yyclosure_corpo(a, c + 0);
		}
		break;
	case 311: /* INTR */
		break;
	case 312: /* DECL */
		break;
	case 313: /* DECLS */
		break;
	case 314: /* INIT */
		break;
	case 315: /* NIL */
		/* corpo: NIL */
		yytrace(a, 1, 0 + 0, p->cost[yycorpo_NT]);
		if (0 + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = 0 + 0;
			p->rule.yycorpo = 1;
			yyclosure_corpo(a, 0 + 0);
		}
		/* stack: NIL */
		yytrace(a, 61, 0 + 0, p->cost[yystack_NT]);
		if (0 + 0 < p->cost[yystack_NT]) {
			p->cost[yystack_NT] = 0 + 0;
			p->rule.yystack = 3;
		}
		break;
	case 316: /* PNTR */
		break;
	case 317: /* EXPS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* stack: EXPS(stack,stack) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystack_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystack_NT] + 0;
		yytrace(a, 59, c + 0, p->cost[yystack_NT]);
		if (c + 0 < p->cost[yystack_NT]) {
			p->cost[yystack_NT] = c + 0;
			p->rule.yystack = 1;
		}
		break;
	case 318: /* EXP */
		break;
	case 319: /* MALL */
		break;
	case 320: /* BODY */
		break;
	case 321: /* JZ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrucao: JZ(expressao,ETIQ) */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
			yytrace(a, 13, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 6;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(LT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 304 && /* LT */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 15, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 8;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(LE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 282 && /* LE */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 16, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 9;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(GT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 305 && /* GT */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 17, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 10;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(GE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 281 && /* GE */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 18, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 11;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 283 && /* EQ */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 19, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 12;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(NE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 284 && /* NE */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 20, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 13;
				yyclosure_instrucao(a, c + 0);
			}
		}
		break;
	case 322: /* ETIQ */
		break;
	case 323: /* LABEL */
		/* instrucao: LABEL */
		yytrace(a, 9, 1 + 0, p->cost[yyinstrucao_NT]);
		if (1 + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = 1 + 0;
			p->rule.yyinstrucao = 2;
			yyclosure_instrucao(a, 1 + 0);
		}
		break;
	case 324: /* JNZ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrucao: JNZ(expressao,ETIQ) */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
			yytrace(a, 14, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 7;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 304 && /* LT */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 21, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 14;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 282 && /* LE */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 22, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 15;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 305 && /* GT */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 23, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 16;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 281 && /* GE */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 24, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 17;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 283 && /* EQ */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 25, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 18;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 284 && /* NE */
			OP_LABEL(RIGHT_CHILD(a)) == 322 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 26, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 19;
				yyclosure_instrucao(a, c + 0);
			}
		}
		break;
	case 325: /* JMP */
		/* instrucao: JMP */
		yytrace(a, 12, 1 + 0, p->cost[yyinstrucao_NT]);
		if (1 + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = 1 + 0;
			p->rule.yyinstrucao = 5;
			yyclosure_instrucao(a, 1 + 0);
		}
		break;
	case 326: /* INSTRS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrucoes: INSTRS(instrucoes,instrucao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrucoes_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucao_NT] + 0;
		yytrace(a, 6, c + 0, p->cost[yyinstrucoes_NT]);
		if (c + 0 < p->cost[yyinstrucoes_NT]) {
			p->cost[yyinstrucoes_NT] = c + 0;
			p->rule.yyinstrucoes = 1;
			yyclosure_instrucoes(a, c + 0);
		}
		break;
	case 327: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: UMINUS(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 7;
			yyclosure_expressao(a, c + 0);
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 61: /* stack: NIL */
	case 56: /* lvalue: IDENTIF */
	case 31: /* expressao: CALL(IDENTIF) */
	case 28: /* expressao: STRN */
	case 27: /* expressao: INT */
	case 12: /* instrucao: JMP */
	case 9: /* instrucao: LABEL */
	case 5: /* pars2: IDENTIF */
	case 4: /* pars2: PARS2 */
	case 1: /* corpo: NIL */
		break;
	case 60: /* stack: expressao */
	case 58: /* lvalue2: lvalue */
	case 55: /* dupexp: expressao */
	case 29: /* expressao: lvalue */
	case 11: /* instrucao: corpo */
	case 10: /* instrucao: expressao */
	case 7: /* instrucoes: instrucao */
	case 2: /* corpo: instrucoes */
		kids[0] = p;
		break;
	case 59: /* stack: EXPS(stack,stack) */
	case 57: /* lvalue: VECTOR(lvalue2,expressao) */
	case 50: /* expressao: OR(expressao,expressao) */
	case 49: /* expressao: AND(expressao,expressao) */
	case 48: /* expressao: LE(expressao,expressao) */
	case 47: /* expressao: GE(expressao,expressao) */
	case 46: /* expressao: NE(expressao,expressao) */
	case 45: /* expressao: EQ(expressao,expressao) */
	case 44: /* expressao: LT(expressao,expressao) */
	case 43: /* expressao: GT(expressao,expressao) */
	case 42: /* expressao: SUBT(expressao,expressao) */
	case 41: /* expressao: ADD(expressao,expressao) */
	case 40: /* expressao: MOD(expressao,expressao) */
	case 39: /* expressao: DIV(expressao,expressao) */
	case 38: /* expressao: MUL(expressao,expressao) */
	case 32: /* expressao: ATRIB(dupexp,lvalue) */
	case 8: /* instrucao: LIST(instrucao,instrucao) */
	case 6: /* instrucoes: INSTRS(instrucoes,instrucao) */
	case 3: /* corpo: PINTR(pars2,instrucoes) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 54: /* expressao: POINTER(lvalue) */
	case 53: /* expressao: ADDR(lvalue) */
	case 52: /* expressao: FACT(expressao) */
	case 51: /* expressao: NEG(expressao) */
	case 35: /* expressao: DEC(lvalue,NIL) */
	case 34: /* expressao: INC(lvalue,NIL) */
	case 33: /* expressao: UMINUS(expressao) */
	case 14: /* instrucao: JNZ(expressao,ETIQ) */
	case 13: /* instrucao: JZ(expressao,ETIQ) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 26: /* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
	case 25: /* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
	case 24: /* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
	case 23: /* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
	case 22: /* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
	case 21: /* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
	case 20: /* instrucao: JZ(NE(expressao,expressao),ETIQ) */
	case 19: /* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
	case 18: /* instrucao: JZ(GE(expressao,expressao),ETIQ) */
	case 17: /* instrucao: JZ(GT(expressao,expressao),ETIQ) */
	case 16: /* instrucao: JZ(LE(expressao,expressao),ETIQ) */
	case 15: /* instrucao: JZ(LT(expressao,expressao),ETIQ) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		break;
	case 37: /* expressao: DEC(NIL,lvalue) */
	case 36: /* expressao: INC(NIL,lvalue) */
	case 30: /* expressao: CALL2(IDENTIF,stack) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[10];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* corpo: NIL */
#line 82 "factorial.brg"

		break;
	case 2: /* corpo: instrucoes */
#line 83 "factorial.brg"

		break;
	case 3: /* corpo: PINTR(pars2,instrucoes) */
#line 84 "factorial.brg"

		break;
	case 4: /* pars2: PARS2 */
#line 86 "factorial.brg"

		break;
	case 5: /* pars2: IDENTIF */
#line 87 "factorial.brg"

		break;
	case 6: /* instrucoes: INSTRS(instrucoes,instrucao) */
#line 89 "factorial.brg"

		break;
	case 7: /* instrucoes: instrucao */
#line 90 "factorial.brg"

		break;
	case 8: /* instrucao: LIST(instrucao,instrucao) */
#line 92 "factorial.brg"

		break;
	case 9: /* instrucao: LABEL */
#line 93 "factorial.brg"
{ fprintf(outfp, pfLABEL, p->value.s); }
		break;
	case 10: /* instrucao: expressao */
#line 94 "factorial.brg"
{ fprintf(outfp, pfTRASH, 4); }
		break;
	case 11: /* instrucao: corpo */
#line 95 "factorial.brg"

		break;
	case 12: /* instrucao: JMP */
#line 96 "factorial.brg"
{ fprintf(outfp, pfJMP, p->value.s); }
		break;
	case 13: /* instrucao: JZ(expressao,ETIQ) */
#line 97 "factorial.brg"
{ fprintf(outfp, pfJZ, p->SUB(1)->value.s); }
		break;
	case 14: /* instrucao: JNZ(expressao,ETIQ) */
#line 98 "factorial.brg"
{ fprintf(outfp, pfJNZ, p->SUB(1)->value.s); }
		break;
	case 15: /* instrucao: JZ(LT(expressao,expressao),ETIQ) */
#line 99 "factorial.brg"
{ fprintf(outfp, pfJGE, p->SUB(1)->value.s); }
		break;
	case 16: /* instrucao: JZ(LE(expressao,expressao),ETIQ) */
#line 100 "factorial.brg"
{ fprintf(outfp, pfJGT, p->SUB(1)->value.s); }
		break;
	case 17: /* instrucao: JZ(GT(expressao,expressao),ETIQ) */
#line 101 "factorial.brg"
{ fprintf(outfp, pfJLE, p->SUB(1)->value.s); }
		break;
	case 18: /* instrucao: JZ(GE(expressao,expressao),ETIQ) */
#line 102 "factorial.brg"
{ fprintf(outfp, pfJLT, p->SUB(1)->value.s); }
		break;
	case 19: /* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
#line 103 "factorial.brg"
{ fprintf(outfp, pfJNE, p->SUB(1)->value.s); }
		break;
	case 20: /* instrucao: JZ(NE(expressao,expressao),ETIQ) */
#line 104 "factorial.brg"
{ fprintf(outfp, pfJEQ, p->SUB(1)->value.s); }
		break;
	case 21: /* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
#line 105 "factorial.brg"
{ fprintf(outfp, pfJLT, p->SUB(1)->value.s); }
		break;
	case 22: /* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
#line 106 "factorial.brg"
{ fprintf(outfp, pfJLE, p->SUB(1)->value.s); }
		break;
	case 23: /* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
#line 107 "factorial.brg"
{ fprintf(outfp, pfJGT, p->SUB(1)->value.s); }
		break;
	case 24: /* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
#line 108 "factorial.brg"
{ fprintf(outfp, pfJGE, p->SUB(1)->value.s); }
		break;
	case 25: /* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
#line 109 "factorial.brg"
{ fprintf(outfp, pfJEQ, p->SUB(1)->value.s); }
		break;
	case 26: /* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
#line 110 "factorial.brg"
{ fprintf(outfp, pfJNE, p->SUB(1)->value.s); }
		break;
	case 27: /* expressao: INT */
#line 119 "factorial.brg"
{ fprintf(outfp, pfIMM, p->value.i); printf("INT: %d\n", p->value.i);}
		break;
	case 28: /* expressao: STRN */
#line 121 "factorial.brg"
{ int l = ++lbl; char *s = p->value.s;
                                              fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(l));
                                              do fprintf(outfp, pfCHAR, (unsigned char)*s); while (*s++ != 0);
                                              fprintf(outfp, pfTEXT pfADDR, mklbl(l)); }
		break;
	case 29: /* expressao: lvalue */
#line 125 "factorial.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 30: /* expressao: CALL2(IDENTIF,stack) */
#line 126 "factorial.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, p->SUB(0)->value.s, stk); printf("CALL2- 2 args\n"); stk = 0;}
		break;
	case 31: /* expressao: CALL(IDENTIF) */
#line 127 "factorial.brg"
{ fprintf(outfp, pfCALL pfPUSH, p->SUB(0)->value.s); printf("CALL\n"); stk = 0;}
		break;
	case 32: /* expressao: ATRIB(dupexp,lvalue) */
#line 128 "factorial.brg"
{ fprintf(outfp, pfSTORE /*pfSWAP pfSTORE*/); printf("STORE: %d\n", p->SUB(0)->value.i);}
		break;
	case 33: /* expressao: UMINUS(expressao) */
#line 129 "factorial.brg"
{ fprintf(outfp, pfNEG); printf("UMINUS: %d\n", p->SUB(0)->value.i);}
		break;
	case 34: /* expressao: INC(lvalue,NIL) */
#line 130 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 35: /* expressao: DEC(lvalue,NIL) */
#line 131 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 36: /* expressao: INC(NIL,lvalue) */
#line 132 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 37: /* expressao: DEC(NIL,lvalue) */
#line 133 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 38: /* expressao: MUL(expressao,expressao) */
#line 134 "factorial.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 39: /* expressao: DIV(expressao,expressao) */
#line 135 "factorial.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 40: /* expressao: MOD(expressao,expressao) */
#line 136 "factorial.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 41: /* expressao: ADD(expressao,expressao) */
#line 137 "factorial.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 42: /* expressao: SUBT(expressao,expressao) */
#line 138 "factorial.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 43: /* expressao: GT(expressao,expressao) */
#line 139 "factorial.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 44: /* expressao: LT(expressao,expressao) */
#line 140 "factorial.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 45: /* expressao: EQ(expressao,expressao) */
#line 141 "factorial.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 46: /* expressao: NE(expressao,expressao) */
#line 142 "factorial.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 47: /* expressao: GE(expressao,expressao) */
#line 143 "factorial.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 48: /* expressao: LE(expressao,expressao) */
#line 144 "factorial.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 49: /* expressao: AND(expressao,expressao) */
#line 145 "factorial.brg"
{ char *l = mklbl(++lbl); 
                                             fprintf(outfp, pfSWAP pfDUP pfJZ pfTRASH pfLABEL pfSWAP pfTRASH, l, 4, l, 4); }
		break;
	case 50: /* expressao: OR(expressao,expressao) */
#line 147 "factorial.brg"
{ char *l = mklbl(++lbl); 
                                             fprintf(outfp, pfSWAP pfDUP pfJNZ pfTRASH pfLABEL pfSWAP pfTRASH, l, 4, l, 4);  }
		break;
	case 51: /* expressao: NEG(expressao) */
#line 149 "factorial.brg"
{ fprintf(outfp, pfIMM pfEQ, 0);}
		break;
	case 52: /* expressao: FACT(expressao) */
#line 150 "factorial.brg"

		break;
	case 53: /* expressao: ADDR(lvalue) */
#line 151 "factorial.brg"
{ /* empty */ }
		break;
	case 54: /* expressao: POINTER(lvalue) */
#line 152 "factorial.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 55: /* dupexp: expressao */
#line 155 "factorial.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 56: /* lvalue: IDENTIF */
#line 157 "factorial.brg"
{ if (p->user == GLOBAL)
                          {fprintf(outfp, pfADDR, p->value.s); printf("GLOBAL - %s\n", p->value.s);}
                        else
                          {fprintf(outfp, pfLOCAL, p->user); printf("LOCAL - %d\n", p->user);}
                    }
		break;
	case 57: /* lvalue: VECTOR(lvalue2,expressao) */
#line 162 "factorial.brg"
{fprintf(outfp, pfIMM pfMUL pfADD, 4);printf("VECTOR - lvalue\n");}
		break;
	case 58: /* lvalue2: lvalue */
#line 164 "factorial.brg"
{ fprintf(outfp, pfLOAD); printf("LOAD - lvalue - %d\n", p->user); }
		break;
	case 59: /* stack: EXPS(stack,stack) */
#line 166 "factorial.brg"

		break;
	case 60: /* stack: expressao */
#line 167 "factorial.brg"
{ stk += 4; }
		break;
	case 61: /* stack: NIL */
#line 168 "factorial.brg"
{ stk = 0; }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yycorpo == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 170 "factorial.brg"


void function(char *name, int enter, Node *body) {
  int i;
  extern int trace;

  if(trace) printNode(body, stdout, yynames);
  if (body == 0 || body->attrib == NIL) /* forward declaration */
    fprintf(outfp, pfEXTRN, name);
  else { /* function body */
    if (strcmp(name, "entry") == 0) // para a funcao entry
      fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, "_entry", pfFUNC, "_entry", enter);
    else
    fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, name, pfFUNC, name, enter);
    if (yyselect(body) == 1) yyerror("No match for syntactic tree.");
    fprintf(outfp, pfLEAVE pfRET); /* just in case there is no 'return' */
    //  freeNode(body);
  }
}

/*   contido no function
void program(int enter, Node *body) {
  function("_entry", enter, body);
  fprintf(outfp, pfEXTRN pfEXTRN pfEXTRN pfEXTRN,
  		U_"prints", U_"printi", U_"println", U_"readi");
}*/


/* pfID para o pointer */
void declare(char *name, Node * value) {
  int tipo = IDfind(name, 0);
  if (tipo == 0)
    fprintf(outfp, pfBSS pfALIGN pfLABEL pfBYTE pfTEXT, name, 4);
  else if ((tipo & 0x3) == 1){ //Se for inteiro
    if ((tipo & 0x7) == 5) fprintf(outfp, pfDATA pfALIGN pfLABEL pfID pfTEXT, name, value->value.s);
    else{
    if ((tipo & 0x15) == 9){ //Se for cons
      if ((tipo & 0x31) == 17){ //Se for public
        fprintf(outfp, pfRODATA pfALIGN pfGLOBL pfLABEL pfINTEGER pfTEXT, name, pfINTEGER, name, value->value.i);
      } else
        fprintf(outfp, pfRODATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value->value.i);
    } else
      fprintf(outfp, pfDATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value->value.i);
    }
  }
  else if((tipo & 0x3) == 2){
    if ((tipo & 0x15) == 10){ //Se for cons
      if ((tipo & 0x31) == 18){ //Se for public
        fprintf(outfp, pfRODATA pfALIGN pfGLOBL pfLABEL pfSTR pfTEXT, name, pfSTR, name, name, value);
      } else
        fprintf(outfp, pfRODATA pfALIGN pfLABEL pfSTR pfTEXT, name, name, value);
    } else
      fprintf(outfp, pfDATA pfALIGN pfLABEL pfSTR pfTEXT, name, name, value);
  }
  else if((tipo & 0x3) == 3){

  }
}


//fprintf(outfp, pfDATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value);
