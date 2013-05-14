/*
generated at Tue May 14 11:28:46 2013
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
#define yyinstrucao_NT 3
#define yyexpressao_NT 4
#define yylvalue_NT 5
#define yystack_NT 6
#define yydupexp_NT 7

static YYCONST char *yyntname[] = {
	0,
	"corpo",
	"instrucoes",
	"instrucao",
	"expressao",
	"lvalue",
	"stack",
	"dupexp",
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
	/* 293 */ "CALL",
	/* 294 */ "CALL2",
	/* 295 */ "NEG",
	/* 296 */ "FACT",
	/* 297 */ "AND",
	/* 298 */ "OR",
	/* 299 */ "PROG",
	/* 300 */ "ADD",
	/* 301 */ "SUBT",
	/* 302 */ "MUL",
	/* 303 */ "DIV",
	/* 304 */ "LT",
	/* 305 */ "GT",
	/* 306 */ "MOD",
	/* 307 */ "PARAMS",
	/* 308 */ "PARS2",
	/* 309 */ "PARS",
	/* 310 */ "PINTR",
	/* 311 */ "INTR",
	/* 312 */ "DECL",
	/* 313 */ "DECLS",
	/* 314 */ "INIT",
	/* 315 */ "NIL",
	/* 316 */ "PNTR",
	/* 317 */ "EXPS",
	/* 318 */ "EXP",
	/* 319 */ "MALL",
	/* 320 */ "BODY",
	/* 321 */ "JZ",
	/* 322 */ "ETIQ",
	/* 323 */ "LABEL",
	/* 324 */ "JNZ",
	/* 325 */ "JMP",
	/* 326 */ "INSTRS",
	/* 327 */ "UMINUS",
	""
};

struct yystate {
	short cost[8];
	struct {
		unsigned int yycorpo:2;
		unsigned int yyinstrucoes:2;
		unsigned int yyinstrucao:5;
		unsigned int yyexpressao:5;
		unsigned int yylvalue:1;
		unsigned int yystack:2;
		unsigned int yydupexp:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yyinstrucoes_NT, 0 };
static short yynts_2[] = { yyinstrucoes_NT, yyinstrucao_NT, 0 };
static short yynts_3[] = { yyinstrucao_NT, 0 };
static short yynts_4[] = { yyinstrucao_NT, yyinstrucao_NT, 0 };
static short yynts_5[] = { yyexpressao_NT, 0 };
static short yynts_6[] = { yycorpo_NT, 0 };
static short yynts_7[] = { yyexpressao_NT, yyexpressao_NT, 0 };
static short yynts_8[] = { yylvalue_NT, 0 };
static short yynts_9[] = { yystack_NT, 0 };
static short yynts_10[] = { yydupexp_NT, yylvalue_NT, 0 };
static short yynts_11[] = { yystack_NT, yystack_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_0,	/* 3 */
	yynts_2,	/* 4 */
	yynts_3,	/* 5 */
	yynts_4,	/* 6 */
	yynts_0,	/* 7 */
	yynts_5,	/* 8 */
	yynts_6,	/* 9 */
	yynts_0,	/* 10 */
	yynts_5,	/* 11 */
	yynts_5,	/* 12 */
	yynts_7,	/* 13 */
	yynts_7,	/* 14 */
	yynts_7,	/* 15 */
	yynts_7,	/* 16 */
	yynts_7,	/* 17 */
	yynts_7,	/* 18 */
	yynts_7,	/* 19 */
	yynts_7,	/* 20 */
	yynts_7,	/* 21 */
	yynts_7,	/* 22 */
	yynts_7,	/* 23 */
	yynts_7,	/* 24 */
	yynts_0,	/* 25 */
	yynts_0,	/* 26 */
	yynts_0,	/* 27 */
	yynts_8,	/* 28 */
	yynts_9,	/* 29 */
	yynts_0,	/* 30 */
	yynts_10,	/* 31 */
	yynts_5,	/* 32 */
	yynts_8,	/* 33 */
	yynts_8,	/* 34 */
	yynts_8,	/* 35 */
	yynts_8,	/* 36 */
	yynts_7,	/* 37 */
	yynts_7,	/* 38 */
	yynts_7,	/* 39 */
	yynts_7,	/* 40 */
	yynts_7,	/* 41 */
	yynts_7,	/* 42 */
	yynts_7,	/* 43 */
	yynts_7,	/* 44 */
	yynts_7,	/* 45 */
	yynts_7,	/* 46 */
	yynts_7,	/* 47 */
	yynts_7,	/* 48 */
	yynts_7,	/* 49 */
	yynts_5,	/* 50 */
	yynts_5,	/* 51 */
	yynts_8,	/* 52 */
	yynts_8,	/* 53 */
	yynts_5,	/* 54 */
	yynts_0,	/* 55 */
	yynts_11,	/* 56 */
	yynts_5,	/* 57 */
	yynts_0,	/* 58 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"corpo: NIL",
/* 2 */	"corpo: instrucoes",
/* 3 */	"corpo: PINTR",
/* 4 */	"instrucoes: INSTRS(instrucoes,instrucao)",
/* 5 */	"instrucoes: instrucao",
/* 6 */	"instrucao: LIST(instrucao,instrucao)",
/* 7 */	"instrucao: LABEL",
/* 8 */	"instrucao: expressao",
/* 9 */	"instrucao: corpo",
/* 10 */	"instrucao: JMP",
/* 11 */	"instrucao: JZ(expressao,ETIQ)",
/* 12 */	"instrucao: JNZ(expressao,ETIQ)",
/* 13 */	"instrucao: JZ(LT(expressao,expressao),ETIQ)",
/* 14 */	"instrucao: JZ(LE(expressao,expressao),ETIQ)",
/* 15 */	"instrucao: JZ(GT(expressao,expressao),ETIQ)",
/* 16 */	"instrucao: JZ(GE(expressao,expressao),ETIQ)",
/* 17 */	"instrucao: JZ(EQ(expressao,expressao),ETIQ)",
/* 18 */	"instrucao: JZ(NE(expressao,expressao),ETIQ)",
/* 19 */	"instrucao: JNZ(LT(expressao,expressao),ETIQ)",
/* 20 */	"instrucao: JNZ(LE(expressao,expressao),ETIQ)",
/* 21 */	"instrucao: JNZ(GT(expressao,expressao),ETIQ)",
/* 22 */	"instrucao: JNZ(GE(expressao,expressao),ETIQ)",
/* 23 */	"instrucao: JNZ(EQ(expressao,expressao),ETIQ)",
/* 24 */	"instrucao: JNZ(NE(expressao,expressao),ETIQ)",
/* 25 */	"expressao: INT",
/* 26 */	"expressao: NUM",
/* 27 */	"expressao: STRN",
/* 28 */	"expressao: lvalue",
/* 29 */	"expressao: CALL2(IDENTIF,stack)",
/* 30 */	"expressao: CALL(IDENTIF)",
/* 31 */	"expressao: ATRIB(dupexp,lvalue)",
/* 32 */	"expressao: UMINUS(expressao)",
/* 33 */	"expressao: INC(lvalue,NIL)",
/* 34 */	"expressao: DEC(lvalue,NIL)",
/* 35 */	"expressao: INC(NIL,lvalue)",
/* 36 */	"expressao: DEC(NIL,lvalue)",
/* 37 */	"expressao: MUL(expressao,expressao)",
/* 38 */	"expressao: DIV(expressao,expressao)",
/* 39 */	"expressao: MOD(expressao,expressao)",
/* 40 */	"expressao: ADD(expressao,expressao)",
/* 41 */	"expressao: SUBT(expressao,expressao)",
/* 42 */	"expressao: GT(expressao,expressao)",
/* 43 */	"expressao: LT(expressao,expressao)",
/* 44 */	"expressao: EQ(expressao,expressao)",
/* 45 */	"expressao: NE(expressao,expressao)",
/* 46 */	"expressao: GE(expressao,expressao)",
/* 47 */	"expressao: LE(expressao,expressao)",
/* 48 */	"expressao: AND(expressao,expressao)",
/* 49 */	"expressao: OR(expressao,expressao)",
/* 50 */	"expressao: NEG(expressao)",
/* 51 */	"expressao: FACT(expressao)",
/* 52 */	"expressao: ADDR(lvalue)",
/* 53 */	"expressao: POINTER(lvalue)",
/* 54 */	"dupexp: expressao",
/* 55 */	"lvalue: IDENTIF",
/* 56 */	"stack: EXPS(stack,stack)",
/* 57 */	"stack: expressao",
/* 58 */	"stack: NIL",
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
	4,
	5,
};

static short yydecode_instrucao[] = {
	0,
	6,
	7,
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
};

static short yydecode_expressao[] = {
	0,
	25,
	26,
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
};

static short yydecode_lvalue[] = {
	0,
	55,
};

static short yydecode_stack[] = {
	0,
	56,
	57,
	58,
};

static short yydecode_dupexp[] = {
	0,
	54,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 7)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yycorpo_NT:	return yydecode_corpo[((struct yystate *)state)->rule.yycorpo];
	case yyinstrucoes_NT:	return yydecode_instrucoes[((struct yystate *)state)->rule.yyinstrucoes];
	case yyinstrucao_NT:	return yydecode_instrucao[((struct yystate *)state)->rule.yyinstrucao];
	case yyexpressao_NT:	return yydecode_expressao[((struct yystate *)state)->rule.yyexpressao];
	case yylvalue_NT:	return yydecode_lvalue[((struct yystate *)state)->rule.yylvalue];
	case yystack_NT:	return yydecode_stack[((struct yystate *)state)->rule.yystack];
	case yydupexp_NT:	return yydecode_dupexp[((struct yystate *)state)->rule.yydupexp];
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
	yytrace(a, 9, c + 0, p->cost[yyinstrucao_NT]);
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
	yytrace(a, 5, c + 0, p->cost[yyinstrucoes_NT]);
	if (c + 0 < p->cost[yyinstrucoes_NT]) {
		p->cost[yyinstrucoes_NT] = c + 0;
		p->rule.yyinstrucoes = 2;
		yyclosure_instrucoes(a, c + 0);
	}
}

static void yyclosure_expressao(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 57, c + 0, p->cost[yystack_NT]);
	if (c + 0 < p->cost[yystack_NT]) {
		p->cost[yystack_NT] = c + 0;
		p->rule.yystack = 2;
	}
	yytrace(a, 54, c + 1, p->cost[yydupexp_NT]);
	if (c + 1 < p->cost[yydupexp_NT]) {
		p->cost[yydupexp_NT] = c + 1;
		p->rule.yydupexp = 1;
	}
	yytrace(a, 8, c + 1, p->cost[yyinstrucao_NT]);
	if (c + 1 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 1;
		p->rule.yyinstrucao = 3;
		yyclosure_instrucao(a, c + 1);
	}
}

static void yyclosure_lvalue(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 28, c + 1, p->cost[yyexpressao_NT]);
	if (c + 1 < p->cost[yyexpressao_NT]) {
		p->cost[yyexpressao_NT] = c + 1;
		p->rule.yyexpressao = 4;
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* ARG */
		break;
	case 257: /* INT */
		/* expressao: INT */
		yytrace(a, 25, 1 + 0, p->cost[yyexpressao_NT]);
		if (1 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 1 + 0;
			p->rule.yyexpressao = 1;
			yyclosure_expressao(a, 1 + 0);
		}
		break;
	case 258: /* NUM */
		/* expressao: NUM */
		yytrace(a, 26, 1 + 0, p->cost[yyexpressao_NT]);
		if (1 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 1 + 0;
			p->rule.yyexpressao = 2;
			yyclosure_expressao(a, 1 + 0);
		}
		break;
	case 259: /* IDENTIF */
		/* lvalue: IDENTIF */
		yytrace(a, 55, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
			yyclosure_lvalue(a, 1 + 0);
		}
		break;
	case 260: /* STRN */
		/* expressao: STRN */
		yytrace(a, 27, 3 + 0, p->cost[yyexpressao_NT]);
		if (3 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 3 + 0;
			p->rule.yyexpressao = 3;
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
		yytrace(a, 46, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 22;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 282: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 23;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 283: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: EQ(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 44, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 20;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 284: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: NE(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 21;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 285: /* INC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: INC(lvalue,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 314 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 33, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 9;
				yyclosure_expressao(a, c + 0);
			}
		}
		if (	/* expressao: INC(NIL,lvalue) */
			OP_LABEL(LEFT_CHILD(a)) == 314 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 35, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 11;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 286: /* DEC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: DEC(lvalue,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 314 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 34, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 10;
				yyclosure_expressao(a, c + 0);
			}
		}
		if (	/* expressao: DEC(NIL,lvalue) */
			OP_LABEL(LEFT_CHILD(a)) == 314 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
			yytrace(a, 36, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 12;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 287: /* ATRIB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ATRIB(dupexp,lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydupexp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 31, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 7;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 288: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: ADDR(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 0;
		yytrace(a, 52, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 28;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 289: /* POINTER */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: POINTER(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 1;
		yytrace(a, 53, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 29;
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
		yytrace(a, 6, c + 0, p->cost[yyinstrucao_NT]);
		if (c + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = c + 0;
			p->rule.yyinstrucao = 1;
			yyclosure_instrucao(a, c + 0);
		}
		break;
	case 292: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		if (	/* expressao: CALL(IDENTIF) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = 2;
			yytrace(a, 30, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 6;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 293: /* CALL2 */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: CALL2(IDENTIF,stack) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystack_NT] + 3;
			yytrace(a, 29, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 5;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 294: /* NEG */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: NEG(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 2;
		yytrace(a, 50, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 26;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 295: /* FACT */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: FACT(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 0;
		yytrace(a, 51, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 27;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 296: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: AND(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 7;
		yytrace(a, 48, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 24;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 297: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: OR(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 7;
		yytrace(a, 49, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 25;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 298: /* PROG */
		break;
	case 299: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ADD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 16;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 300: /* SUBT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: SUBT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 41, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 17;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 301: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MUL(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 13;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 302: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: DIV(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 38, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 14;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 303: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 43, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 19;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 304: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: GT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 18;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 305: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MOD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 15;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 306: /* PARAMS */
		break;
	case 307: /* PARS2 */
		break;
	case 308: /* PARS */
		break;
	case 309: /* PINTR */
		/* corpo: PINTR */
		yytrace(a, 3, 0 + 0, p->cost[yycorpo_NT]);
		if (0 + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = 0 + 0;
			p->rule.yycorpo = 3;
			yyclosure_corpo(a, 0 + 0);
		}
		break;
	case 310: /* INTR */
		break;
	case 311: /* DECL */
		break;
	case 312: /* DECLS */
		break;
	case 313: /* INIT */
		break;
	case 314: /* NIL */
		/* corpo: NIL */
		yytrace(a, 1, 0 + 0, p->cost[yycorpo_NT]);
		if (0 + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = 0 + 0;
			p->rule.yycorpo = 1;
			yyclosure_corpo(a, 0 + 0);
		}
		/* stack: NIL */
		yytrace(a, 58, 0 + 0, p->cost[yystack_NT]);
		if (0 + 0 < p->cost[yystack_NT]) {
			p->cost[yystack_NT] = 0 + 0;
			p->rule.yystack = 3;
		}
		break;
	case 315: /* PNTR */
		break;
	case 316: /* EXPS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* stack: EXPS(stack,stack) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystack_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystack_NT] + 0;
		yytrace(a, 56, c + 0, p->cost[yystack_NT]);
		if (c + 0 < p->cost[yystack_NT]) {
			p->cost[yystack_NT] = c + 0;
			p->rule.yystack = 1;
		}
		break;
	case 317: /* EXP */
		break;
	case 318: /* MALL */
		break;
	case 319: /* BODY */
		break;
	case 320: /* JZ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrucao: JZ(expressao,ETIQ) */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
			yytrace(a, 11, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 6;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(LT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 303 && /* LT */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 13, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 8;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(LE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 282 && /* LE */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 14, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 9;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(GT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 304 && /* GT */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 15, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 10;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(GE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 281 && /* GE */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 16, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 11;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 283 && /* EQ */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 17, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 12;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JZ(NE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 284 && /* NE */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 18, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 13;
				yyclosure_instrucao(a, c + 0);
			}
		}
		break;
	case 321: /* ETIQ */
		break;
	case 322: /* LABEL */
		/* instrucao: LABEL */
		yytrace(a, 7, 1 + 0, p->cost[yyinstrucao_NT]);
		if (1 + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = 1 + 0;
			p->rule.yyinstrucao = 2;
			yyclosure_instrucao(a, 1 + 0);
		}
		break;
	case 323: /* JNZ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrucao: JNZ(expressao,ETIQ) */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
			yytrace(a, 12, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 7;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 303 && /* LT */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 19, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 14;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 282 && /* LE */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 20, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 15;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 304 && /* GT */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 21, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 16;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 281 && /* GE */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 22, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 17;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 283 && /* EQ */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 23, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 18;
				yyclosure_instrucao(a, c + 0);
			}
		}
		if (	/* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
			OP_LABEL(LEFT_CHILD(a)) == 284 && /* NE */
			OP_LABEL(RIGHT_CHILD(a)) == 321 /* ETIQ */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpressao_NT] + 1;
			yytrace(a, 24, c + 0, p->cost[yyinstrucao_NT]);
			if (c + 0 < p->cost[yyinstrucao_NT]) {
				p->cost[yyinstrucao_NT] = c + 0;
				p->rule.yyinstrucao = 19;
				yyclosure_instrucao(a, c + 0);
			}
		}
		break;
	case 324: /* JMP */
		/* instrucao: JMP */
		yytrace(a, 10, 1 + 0, p->cost[yyinstrucao_NT]);
		if (1 + 0 < p->cost[yyinstrucao_NT]) {
			p->cost[yyinstrucao_NT] = 1 + 0;
			p->rule.yyinstrucao = 5;
			yyclosure_instrucao(a, 1 + 0);
		}
		break;
	case 325: /* INSTRS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instrucoes: INSTRS(instrucoes,instrucao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrucoes_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrucao_NT] + 0;
		yytrace(a, 4, c + 0, p->cost[yyinstrucoes_NT]);
		if (c + 0 < p->cost[yyinstrucoes_NT]) {
			p->cost[yyinstrucoes_NT] = c + 0;
			p->rule.yyinstrucoes = 1;
			yyclosure_instrucoes(a, c + 0);
		}
		break;
	case 326: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: UMINUS(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 8;
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
	case 58: /* stack: NIL */
	case 55: /* lvalue: IDENTIF */
	case 30: /* expressao: CALL(IDENTIF) */
	case 27: /* expressao: STRN */
	case 26: /* expressao: NUM */
	case 25: /* expressao: INT */
	case 10: /* instrucao: JMP */
	case 7: /* instrucao: LABEL */
	case 3: /* corpo: PINTR */
	case 1: /* corpo: NIL */
		break;
	case 57: /* stack: expressao */
	case 54: /* dupexp: expressao */
	case 28: /* expressao: lvalue */
	case 9: /* instrucao: corpo */
	case 8: /* instrucao: expressao */
	case 5: /* instrucoes: instrucao */
	case 2: /* corpo: instrucoes */
		kids[0] = p;
		break;
	case 56: /* stack: EXPS(stack,stack) */
	case 49: /* expressao: OR(expressao,expressao) */
	case 48: /* expressao: AND(expressao,expressao) */
	case 47: /* expressao: LE(expressao,expressao) */
	case 46: /* expressao: GE(expressao,expressao) */
	case 45: /* expressao: NE(expressao,expressao) */
	case 44: /* expressao: EQ(expressao,expressao) */
	case 43: /* expressao: LT(expressao,expressao) */
	case 42: /* expressao: GT(expressao,expressao) */
	case 41: /* expressao: SUBT(expressao,expressao) */
	case 40: /* expressao: ADD(expressao,expressao) */
	case 39: /* expressao: MOD(expressao,expressao) */
	case 38: /* expressao: DIV(expressao,expressao) */
	case 37: /* expressao: MUL(expressao,expressao) */
	case 31: /* expressao: ATRIB(dupexp,lvalue) */
	case 6: /* instrucao: LIST(instrucao,instrucao) */
	case 4: /* instrucoes: INSTRS(instrucoes,instrucao) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 53: /* expressao: POINTER(lvalue) */
	case 52: /* expressao: ADDR(lvalue) */
	case 51: /* expressao: FACT(expressao) */
	case 50: /* expressao: NEG(expressao) */
	case 34: /* expressao: DEC(lvalue,NIL) */
	case 33: /* expressao: INC(lvalue,NIL) */
	case 32: /* expressao: UMINUS(expressao) */
	case 12: /* instrucao: JNZ(expressao,ETIQ) */
	case 11: /* instrucao: JZ(expressao,ETIQ) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 24: /* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
	case 23: /* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
	case 22: /* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
	case 21: /* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
	case 20: /* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
	case 19: /* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
	case 18: /* instrucao: JZ(NE(expressao,expressao),ETIQ) */
	case 17: /* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
	case 16: /* instrucao: JZ(GE(expressao,expressao),ETIQ) */
	case 15: /* instrucao: JZ(GT(expressao,expressao),ETIQ) */
	case 14: /* instrucao: JZ(LE(expressao,expressao),ETIQ) */
	case 13: /* instrucao: JZ(LT(expressao,expressao),ETIQ) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		break;
	case 36: /* expressao: DEC(NIL,lvalue) */
	case 35: /* expressao: INC(NIL,lvalue) */
	case 29: /* expressao: CALL2(IDENTIF,stack) */
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
#line 83 "factorial.brg"

		break;
	case 2: /* corpo: instrucoes */
#line 84 "factorial.brg"

		break;
	case 3: /* corpo: PINTR */
#line 85 "factorial.brg"

		break;
	case 4: /* instrucoes: INSTRS(instrucoes,instrucao) */
#line 87 "factorial.brg"

		break;
	case 5: /* instrucoes: instrucao */
#line 88 "factorial.brg"

		break;
	case 6: /* instrucao: LIST(instrucao,instrucao) */
#line 90 "factorial.brg"

		break;
	case 7: /* instrucao: LABEL */
#line 91 "factorial.brg"
{ fprintf(outfp, pfLABEL, p->value.s); }
		break;
	case 8: /* instrucao: expressao */
#line 92 "factorial.brg"
{ fprintf(outfp, pfTRASH, 4); }
		break;
	case 9: /* instrucao: corpo */
#line 93 "factorial.brg"

		break;
	case 10: /* instrucao: JMP */
#line 94 "factorial.brg"
{ fprintf(outfp, pfJMP, p->value.s); }
		break;
	case 11: /* instrucao: JZ(expressao,ETIQ) */
#line 95 "factorial.brg"
{ fprintf(outfp, pfJZ, p->SUB(1)->value.s); }
		break;
	case 12: /* instrucao: JNZ(expressao,ETIQ) */
#line 96 "factorial.brg"
{ fprintf(outfp, pfJNZ, p->SUB(1)->value.s); }
		break;
	case 13: /* instrucao: JZ(LT(expressao,expressao),ETIQ) */
#line 97 "factorial.brg"
{ fprintf(outfp, pfJGE, p->SUB(1)->value.s); }
		break;
	case 14: /* instrucao: JZ(LE(expressao,expressao),ETIQ) */
#line 98 "factorial.brg"
{ fprintf(outfp, pfJGT, p->SUB(1)->value.s); }
		break;
	case 15: /* instrucao: JZ(GT(expressao,expressao),ETIQ) */
#line 99 "factorial.brg"
{ fprintf(outfp, pfJLE, p->SUB(1)->value.s); }
		break;
	case 16: /* instrucao: JZ(GE(expressao,expressao),ETIQ) */
#line 100 "factorial.brg"
{ fprintf(outfp, pfJLT, p->SUB(1)->value.s); }
		break;
	case 17: /* instrucao: JZ(EQ(expressao,expressao),ETIQ) */
#line 101 "factorial.brg"
{ fprintf(outfp, pfJNE, p->SUB(1)->value.s); }
		break;
	case 18: /* instrucao: JZ(NE(expressao,expressao),ETIQ) */
#line 102 "factorial.brg"
{ fprintf(outfp, pfJEQ, p->SUB(1)->value.s); }
		break;
	case 19: /* instrucao: JNZ(LT(expressao,expressao),ETIQ) */
#line 103 "factorial.brg"
{ fprintf(outfp, pfJLT, p->SUB(1)->value.s); }
		break;
	case 20: /* instrucao: JNZ(LE(expressao,expressao),ETIQ) */
#line 104 "factorial.brg"
{ fprintf(outfp, pfJLE, p->SUB(1)->value.s); }
		break;
	case 21: /* instrucao: JNZ(GT(expressao,expressao),ETIQ) */
#line 105 "factorial.brg"
{ fprintf(outfp, pfJGT, p->SUB(1)->value.s); }
		break;
	case 22: /* instrucao: JNZ(GE(expressao,expressao),ETIQ) */
#line 106 "factorial.brg"
{ fprintf(outfp, pfJGE, p->SUB(1)->value.s); }
		break;
	case 23: /* instrucao: JNZ(EQ(expressao,expressao),ETIQ) */
#line 107 "factorial.brg"
{ fprintf(outfp, pfJEQ, p->SUB(1)->value.s); }
		break;
	case 24: /* instrucao: JNZ(NE(expressao,expressao),ETIQ) */
#line 108 "factorial.brg"
{ fprintf(outfp, pfJNE, p->SUB(1)->value.s); }
		break;
	case 25: /* expressao: INT */
#line 117 "factorial.brg"
{ fprintf(outfp, pfIMM, p->value.i); printf("INT: %d\n", p->value.i);}
		break;
	case 26: /* expressao: NUM */
#line 118 "factorial.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 27: /* expressao: STRN */
#line 119 "factorial.brg"
{ int l = ++lbl; char *s = p->value.s;
                                              fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(l));
                                              do fprintf(outfp, pfCHAR, (unsigned char)*s); while (*s++ != 0);
                                              fprintf(outfp, pfTEXT pfADDR, mklbl(l)); }
		break;
	case 28: /* expressao: lvalue */
#line 123 "factorial.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 29: /* expressao: CALL2(IDENTIF,stack) */
#line 124 "factorial.brg"
{ fprintf(outfp, pfCALL pfTRASH pfPUSH, p->SUB(0)->value.s, stk); printf("CALL2- 2 args\n"); stk = 0;}
		break;
	case 30: /* expressao: CALL(IDENTIF) */
#line 125 "factorial.brg"
{ fprintf(outfp, pfCALL pfPUSH, p->SUB(0)->value.s); printf("CALL\n"); stk = 0;}
		break;
	case 31: /* expressao: ATRIB(dupexp,lvalue) */
#line 126 "factorial.brg"
{ fprintf(outfp, pfSTORE /*pfSWAP pfSTORE*/); printf("STORE: %d\n", p->SUB(0)->value.i); /*ATRIB(duplval,expressao)*/}
		break;
	case 32: /* expressao: UMINUS(expressao) */
#line 127 "factorial.brg"
{ fprintf(outfp, pfNEG); printf("UMINUS: %d\n", p->SUB(0)->value.i);}
		break;
	case 33: /* expressao: INC(lvalue,NIL) */
#line 128 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 34: /* expressao: DEC(lvalue,NIL) */
#line 129 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 35: /* expressao: INC(NIL,lvalue) */
#line 130 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 36: /* expressao: DEC(NIL,lvalue) */
#line 131 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 37: /* expressao: MUL(expressao,expressao) */
#line 132 "factorial.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 38: /* expressao: DIV(expressao,expressao) */
#line 133 "factorial.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 39: /* expressao: MOD(expressao,expressao) */
#line 134 "factorial.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 40: /* expressao: ADD(expressao,expressao) */
#line 135 "factorial.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 41: /* expressao: SUBT(expressao,expressao) */
#line 136 "factorial.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 42: /* expressao: GT(expressao,expressao) */
#line 137 "factorial.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 43: /* expressao: LT(expressao,expressao) */
#line 138 "factorial.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 44: /* expressao: EQ(expressao,expressao) */
#line 139 "factorial.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 45: /* expressao: NE(expressao,expressao) */
#line 140 "factorial.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 46: /* expressao: GE(expressao,expressao) */
#line 141 "factorial.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 47: /* expressao: LE(expressao,expressao) */
#line 142 "factorial.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 48: /* expressao: AND(expressao,expressao) */
#line 143 "factorial.brg"
{ char *l = mklbl(++lbl); 
                                             fprintf(outfp, pfSWAP pfDUP pfJZ pfTRASH pfLABEL pfSWAP pfTRASH, l, 4, l, 4); }
		break;
	case 49: /* expressao: OR(expressao,expressao) */
#line 145 "factorial.brg"
{ char *l = mklbl(++lbl); 
                                             fprintf(outfp, pfSWAP pfDUP pfJNZ pfTRASH pfLABEL pfSWAP pfTRASH, l, 4, l, 4);  }
		break;
	case 50: /* expressao: NEG(expressao) */
#line 147 "factorial.brg"
{ fprintf(outfp, pfIMM pfEQ, 0);}
		break;
	case 51: /* expressao: FACT(expressao) */
#line 148 "factorial.brg"

		break;
	case 52: /* expressao: ADDR(lvalue) */
#line 149 "factorial.brg"
{ /* empty */ }
		break;
	case 53: /* expressao: POINTER(lvalue) */
#line 150 "factorial.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 54: /* dupexp: expressao */
#line 154 "factorial.brg"
{ fprintf(outfp, pfDUP); }
		break;
	case 55: /* lvalue: IDENTIF */
#line 156 "factorial.brg"
{   if (p->user == GLOBAL)
                          {fprintf(outfp, pfADDR, p->value.s); printf("GLOBAL - %d\n", p->user);}
                        else
                          {fprintf(outfp, pfLOCAL, p->user); printf("LOCAL - %d\n", p->user);}
                    }
		break;
	case 56: /* stack: EXPS(stack,stack) */
#line 163 "factorial.brg"

		break;
	case 57: /* stack: expressao */
#line 164 "factorial.brg"
{ stk += 4; }
		break;
	case 58: /* stack: NIL */
#line 165 "factorial.brg"
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


#line 167 "factorial.brg"


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

void declare(char *name, int value) {
  //IDnew(INTEGER, name, 0);
  if (value == 0)
    fprintf(outfp, pfBSS pfALIGN pfLABEL pfBYTE pfTEXT, name, 4);
  else if ((value & 0x3) == 1){ //Se for inteiro
    if ((value & 0x15) == 9){ //Se for cons
      if ((value & 0x31) == 17){ //Se for public
        fprintf(outfp, pfRODATA pfALIGN pfGLOBL pfLABEL pfINTEGER pfTEXT, name, pfINTEGER, name, value);
      } else
        fprintf(outfp, pfRODATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value);
    } else
      fprintf(outfp, pfDATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value);
  }
  else if((value & 0x3) == 2){
    if ((value & 0x15) == 10){ //Se for cons
      if ((value & 0x31) == 18){ //Se for public
        fprintf(outfp, pfRODATA pfALIGN pfGLOBL pfLABEL pfSTR pfTEXT, name, pfSTR, name, name, value);
      } else
        fprintf(outfp, pfRODATA pfALIGN pfLABEL pfSTR pfTEXT, name, name, value);
    } else
      fprintf(outfp, pfDATA pfALIGN pfLABEL pfSTR pfTEXT, name, name, value);
  }
  else if((value & 0x3) == 3){

  }
}


//fprintf(outfp, pfDATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value);
