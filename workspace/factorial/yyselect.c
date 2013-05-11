/*
generated at Sat May 11 23:56:21 2013
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
#define yyexpressoes_NT 5
#define yylvalue_NT 6

static YYCONST char *yyntname[] = {
	0,
	"corpo",
	"instrucoes",
	"instrucao",
	"expressao",
	"expressoes",
	"lvalue",
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
	/* 292 */ "CALL",
	/* 293 */ "CALL2",
	/* 294 */ "NEG",
	/* 295 */ "FACT",
	/* 296 */ "AND",
	/* 297 */ "OR",
	/* 298 */ "PROG",
	/* 299 */ "ADD",
	/* 300 */ "SUBT",
	/* 301 */ "MUL",
	/* 302 */ "DIV",
	/* 303 */ "LT",
	/* 304 */ "GT",
	/* 305 */ "MOD",
	/* 306 */ "PARAMS",
	/* 307 */ "PARS2",
	/* 308 */ "PARS",
	/* 309 */ "PINTR",
	/* 310 */ "INTR",
	/* 311 */ "DECL",
	/* 312 */ "DECLS",
	/* 313 */ "INIT",
	/* 314 */ "NIL",
	/* 315 */ "PNTR",
	/* 316 */ "EXPS",
	/* 317 */ "EXP",
	/* 318 */ "MALL",
	/* 319 */ "BODY",
	/* 320 */ "JZ",
	/* 321 */ "ETIQ",
	/* 322 */ "LABEL",
	/* 323 */ "JNZ",
	/* 324 */ "JMP",
	/* 325 */ "INSTRS",
	/* 326 */ "UMINUS",
	""
};

struct yystate {
	short cost[7];
	struct {
		unsigned int yycorpo:2;
		unsigned int yyinstrucoes:2;
		unsigned int yyinstrucao:2;
		unsigned int yyexpressao:5;
		unsigned int yyexpressoes:2;
		unsigned int yylvalue:1;
	} rule;
};

static short yynts_0[] = { 0 };
static short yynts_1[] = { yyinstrucoes_NT, 0 };
static short yynts_2[] = { yyinstrucoes_NT, yyinstrucao_NT, 0 };
static short yynts_3[] = { yyinstrucao_NT, 0 };
static short yynts_4[] = { yyexpressao_NT, 0 };
static short yynts_5[] = { yycorpo_NT, 0 };
static short yynts_6[] = { yyexpressoes_NT, yyexpressao_NT, 0 };
static short yynts_7[] = { yylvalue_NT, 0 };
static short yynts_8[] = { yyexpressoes_NT, 0 };
static short yynts_9[] = { yylvalue_NT, yyexpressao_NT, 0 };
static short yynts_10[] = { yyexpressao_NT, yyexpressao_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_0,	/* 3 */
	yynts_2,	/* 4 */
	yynts_3,	/* 5 */
	yynts_4,	/* 6 */
	yynts_5,	/* 7 */
	yynts_6,	/* 8 */
	yynts_4,	/* 9 */
	yynts_0,	/* 10 */
	yynts_0,	/* 11 */
	yynts_0,	/* 12 */
	yynts_7,	/* 13 */
	yynts_8,	/* 14 */
	yynts_0,	/* 15 */
	yynts_9,	/* 16 */
	yynts_4,	/* 17 */
	yynts_0,	/* 18 */
	yynts_0,	/* 19 */
	yynts_0,	/* 20 */
	yynts_0,	/* 21 */
	yynts_10,	/* 22 */
	yynts_10,	/* 23 */
	yynts_10,	/* 24 */
	yynts_10,	/* 25 */
	yynts_10,	/* 26 */
	yynts_10,	/* 27 */
	yynts_10,	/* 28 */
	yynts_10,	/* 29 */
	yynts_10,	/* 30 */
	yynts_10,	/* 31 */
	yynts_10,	/* 32 */
	yynts_10,	/* 33 */
	yynts_10,	/* 34 */
	yynts_4,	/* 35 */
	yynts_4,	/* 36 */
	yynts_7,	/* 37 */
	yynts_7,	/* 38 */
	yynts_0,	/* 39 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"corpo: NIL",
/* 2 */	"corpo: instrucoes",
/* 3 */	"corpo: PINTR",
/* 4 */	"instrucoes: INSTRS(instrucoes,instrucao)",
/* 5 */	"instrucoes: instrucao",
/* 6 */	"instrucao: expressao",
/* 7 */	"instrucao: corpo",
/* 8 */	"expressoes: EXPS(expressoes,expressao)",
/* 9 */	"expressoes: expressao",
/* 10 */	"expressao: INT",
/* 11 */	"expressao: NUM",
/* 12 */	"expressao: STRN",
/* 13 */	"expressao: lvalue",
/* 14 */	"expressao: CALL2(IDENTIF,expressoes)",
/* 15 */	"expressao: CALL(IDENTIF)",
/* 16 */	"expressao: ATRIB(lvalue,expressao)",
/* 17 */	"expressao: UMINUS(expressao)",
/* 18 */	"expressao: INC(IDENTIF,NIL)",
/* 19 */	"expressao: DEC(IDENTIF,NIL)",
/* 20 */	"expressao: INC(NIL,IDENTIF)",
/* 21 */	"expressao: DEC(NIL,IDENTIF)",
/* 22 */	"expressao: MUL(expressao,expressao)",
/* 23 */	"expressao: DIV(expressao,expressao)",
/* 24 */	"expressao: MOD(expressao,expressao)",
/* 25 */	"expressao: ADD(expressao,expressao)",
/* 26 */	"expressao: SUBT(expressao,expressao)",
/* 27 */	"expressao: GT(expressao,expressao)",
/* 28 */	"expressao: LT(expressao,expressao)",
/* 29 */	"expressao: EQ(expressao,expressao)",
/* 30 */	"expressao: NE(expressao,expressao)",
/* 31 */	"expressao: GE(expressao,expressao)",
/* 32 */	"expressao: LE(expressao,expressao)",
/* 33 */	"expressao: AND(expressao,expressao)",
/* 34 */	"expressao: OR(expressao,expressao)",
/* 35 */	"expressao: NEG(expressao)",
/* 36 */	"expressao: FACT(expressao)",
/* 37 */	"expressao: ADDR(lvalue)",
/* 38 */	"expressao: POINTER(lvalue)",
/* 39 */	"lvalue: IDENTIF",
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
};

static short yydecode_expressao[] = {
	0,
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
};

static short yydecode_expressoes[] = {
	0,
	8,
	9,
};

static short yydecode_lvalue[] = {
	0,
	39,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 6)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yycorpo_NT:	return yydecode_corpo[((struct yystate *)state)->rule.yycorpo];
	case yyinstrucoes_NT:	return yydecode_instrucoes[((struct yystate *)state)->rule.yyinstrucoes];
	case yyinstrucao_NT:	return yydecode_instrucao[((struct yystate *)state)->rule.yyinstrucao];
	case yyexpressao_NT:	return yydecode_expressao[((struct yystate *)state)->rule.yyexpressao];
	case yyexpressoes_NT:	return yydecode_expressoes[((struct yystate *)state)->rule.yyexpressoes];
	case yylvalue_NT:	return yydecode_lvalue[((struct yystate *)state)->rule.yylvalue];
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
	yytrace(a, 7, c + 0, p->cost[yyinstrucao_NT]);
	if (c + 0 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 0;
		p->rule.yyinstrucao = 2;
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
	yytrace(a, 9, c + 0, p->cost[yyexpressoes_NT]);
	if (c + 0 < p->cost[yyexpressoes_NT]) {
		p->cost[yyexpressoes_NT] = c + 0;
		p->rule.yyexpressoes = 2;
	}
	yytrace(a, 6, c + 0, p->cost[yyinstrucao_NT]);
	if (c + 0 < p->cost[yyinstrucao_NT]) {
		p->cost[yyinstrucao_NT] = c + 0;
		p->rule.yyinstrucao = 1;
		yyclosure_instrucao(a, c + 0);
	}
}

static void yyclosure_lvalue(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 13, c + 0, p->cost[yyexpressao_NT]);
	if (c + 0 < p->cost[yyexpressao_NT]) {
		p->cost[yyexpressao_NT] = c + 0;
		p->rule.yyexpressao = 4;
		yyclosure_expressao(a, c + 0);
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* ARG */
		break;
	case 257: /* INT */
		/* expressao: INT */
		yytrace(a, 10, 1 + 0, p->cost[yyexpressao_NT]);
		if (1 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 1 + 0;
			p->rule.yyexpressao = 1;
			yyclosure_expressao(a, 1 + 0);
		}
		break;
	case 258: /* NUM */
		/* expressao: NUM */
		yytrace(a, 11, 0 + 0, p->cost[yyexpressao_NT]);
		if (0 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 0 + 0;
			p->rule.yyexpressao = 2;
			yyclosure_expressao(a, 0 + 0);
		}
		break;
	case 259: /* IDENTIF */
		/* lvalue: IDENTIF */
		yytrace(a, 39, 1 + 0, p->cost[yylvalue_NT]);
		if (1 + 0 < p->cost[yylvalue_NT]) {
			p->cost[yylvalue_NT] = 1 + 0;
			p->rule.yylvalue = 1;
			yyclosure_lvalue(a, 1 + 0);
		}
		break;
	case 260: /* STRN */
		/* expressao: STRN */
		yytrace(a, 12, 0 + 0, p->cost[yyexpressao_NT]);
		if (0 + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = 0 + 0;
			p->rule.yyexpressao = 3;
			yyclosure_expressao(a, 0 + 0);
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
		yytrace(a, 31, c + 0, p->cost[yyexpressao_NT]);
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
		yytrace(a, 32, c + 0, p->cost[yyexpressao_NT]);
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
		yytrace(a, 29, c + 0, p->cost[yyexpressao_NT]);
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
		yytrace(a, 30, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 21;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 285: /* INC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: INC(IDENTIF,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* IDENTIF */
			OP_LABEL(RIGHT_CHILD(a)) == 313 /* NIL */
		) {
			c = 1;
			yytrace(a, 18, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 9;
				yyclosure_expressao(a, c + 0);
			}
		}
		if (	/* expressao: INC(NIL,IDENTIF) */
			OP_LABEL(LEFT_CHILD(a)) == 313 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = 1;
			yytrace(a, 20, c + 0, p->cost[yyexpressao_NT]);
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
		if (	/* expressao: DEC(IDENTIF,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* IDENTIF */
			OP_LABEL(RIGHT_CHILD(a)) == 313 /* NIL */
		) {
			c = 1;
			yytrace(a, 19, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 10;
				yyclosure_expressao(a, c + 0);
			}
		}
		if (	/* expressao: DEC(NIL,IDENTIF) */
			OP_LABEL(LEFT_CHILD(a)) == 313 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = 1;
			yytrace(a, 21, c + 0, p->cost[yyexpressao_NT]);
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
		/* expressao: ATRIB(lvalue,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 3;
		yytrace(a, 16, c + 0, p->cost[yyexpressao_NT]);
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
		yytrace(a, 37, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 28;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 289: /* POINTER */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: POINTER(lvalue) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvalue_NT] + 0;
		yytrace(a, 38, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 29;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 290: /* IFX */
		break;
	case 291: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		if (	/* expressao: CALL(IDENTIF) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = 2;
			yytrace(a, 15, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 6;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 292: /* CALL2 */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expressao: CALL2(IDENTIF,expressoes) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* IDENTIF */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressoes_NT] + 2;
			yytrace(a, 14, c + 0, p->cost[yyexpressao_NT]);
			if (c + 0 < p->cost[yyexpressao_NT]) {
				p->cost[yyexpressao_NT] = c + 0;
				p->rule.yyexpressao = 5;
				yyclosure_expressao(a, c + 0);
			}
		}
		break;
	case 293: /* NEG */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: NEG(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 26;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 294: /* FACT */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: FACT(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 0;
		yytrace(a, 36, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 27;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 295: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: AND(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 24;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 296: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: OR(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 25;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 297: /* PROG */
		break;
	case 298: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: ADD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 16;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 299: /* SUBT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: SUBT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 17;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 300: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MUL(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 22, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 13;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 301: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: DIV(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 23, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 14;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 302: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: LT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 28, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 19;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 303: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: GT(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 27, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 18;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 304: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressao: MOD(expressao,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 24, c + 0, p->cost[yyexpressao_NT]);
		if (c + 0 < p->cost[yyexpressao_NT]) {
			p->cost[yyexpressao_NT] = c + 0;
			p->rule.yyexpressao = 15;
			yyclosure_expressao(a, c + 0);
		}
		break;
	case 305: /* PARAMS */
		break;
	case 306: /* PARS2 */
		break;
	case 307: /* PARS */
		break;
	case 308: /* PINTR */
		/* corpo: PINTR */
		yytrace(a, 3, 0 + 0, p->cost[yycorpo_NT]);
		if (0 + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = 0 + 0;
			p->rule.yycorpo = 3;
			yyclosure_corpo(a, 0 + 0);
		}
		break;
	case 309: /* INTR */
		break;
	case 310: /* DECL */
		break;
	case 311: /* DECLS */
		break;
	case 312: /* INIT */
		break;
	case 313: /* NIL */
		/* corpo: NIL */
		yytrace(a, 1, 0 + 0, p->cost[yycorpo_NT]);
		if (0 + 0 < p->cost[yycorpo_NT]) {
			p->cost[yycorpo_NT] = 0 + 0;
			p->rule.yycorpo = 1;
			yyclosure_corpo(a, 0 + 0);
		}
		break;
	case 314: /* PNTR */
		break;
	case 315: /* EXPS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expressoes: EXPS(expressoes,expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressoes_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpressao_NT] + 0;
		yytrace(a, 8, c + 0, p->cost[yyexpressoes_NT]);
		if (c + 0 < p->cost[yyexpressoes_NT]) {
			p->cost[yyexpressoes_NT] = c + 0;
			p->rule.yyexpressoes = 1;
		}
		break;
	case 316: /* EXP */
		break;
	case 317: /* MALL */
		break;
	case 318: /* BODY */
		break;
	case 319: /* JZ */
		break;
	case 320: /* ETIQ */
		break;
	case 321: /* LABEL */
		break;
	case 322: /* JNZ */
		break;
	case 323: /* JMP */
		break;
	case 324: /* INSTRS */
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
	case 325: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expressao: UMINUS(expressao) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpressao_NT] + 1;
		yytrace(a, 17, c + 0, p->cost[yyexpressao_NT]);
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
	case 39: /* lvalue: IDENTIF */
	case 21: /* expressao: DEC(NIL,IDENTIF) */
	case 20: /* expressao: INC(NIL,IDENTIF) */
	case 19: /* expressao: DEC(IDENTIF,NIL) */
	case 18: /* expressao: INC(IDENTIF,NIL) */
	case 15: /* expressao: CALL(IDENTIF) */
	case 12: /* expressao: STRN */
	case 11: /* expressao: NUM */
	case 10: /* expressao: INT */
	case 3: /* corpo: PINTR */
	case 1: /* corpo: NIL */
		break;
	case 13: /* expressao: lvalue */
	case 9: /* expressoes: expressao */
	case 7: /* instrucao: corpo */
	case 6: /* instrucao: expressao */
	case 5: /* instrucoes: instrucao */
	case 2: /* corpo: instrucoes */
		kids[0] = p;
		break;
	case 34: /* expressao: OR(expressao,expressao) */
	case 33: /* expressao: AND(expressao,expressao) */
	case 32: /* expressao: LE(expressao,expressao) */
	case 31: /* expressao: GE(expressao,expressao) */
	case 30: /* expressao: NE(expressao,expressao) */
	case 29: /* expressao: EQ(expressao,expressao) */
	case 28: /* expressao: LT(expressao,expressao) */
	case 27: /* expressao: GT(expressao,expressao) */
	case 26: /* expressao: SUBT(expressao,expressao) */
	case 25: /* expressao: ADD(expressao,expressao) */
	case 24: /* expressao: MOD(expressao,expressao) */
	case 23: /* expressao: DIV(expressao,expressao) */
	case 22: /* expressao: MUL(expressao,expressao) */
	case 16: /* expressao: ATRIB(lvalue,expressao) */
	case 8: /* expressoes: EXPS(expressoes,expressao) */
	case 4: /* instrucoes: INSTRS(instrucoes,instrucao) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 14: /* expressao: CALL2(IDENTIF,expressoes) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 38: /* expressao: POINTER(lvalue) */
	case 37: /* expressao: ADDR(lvalue) */
	case 36: /* expressao: FACT(expressao) */
	case 35: /* expressao: NEG(expressao) */
	case 17: /* expressao: UMINUS(expressao) */
		kids[0] = LEFT_CHILD(p);
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
	case 3: /* corpo: PINTR */
#line 84 "factorial.brg"

		break;
	case 4: /* instrucoes: INSTRS(instrucoes,instrucao) */
#line 86 "factorial.brg"

		break;
	case 5: /* instrucoes: instrucao */
#line 87 "factorial.brg"

		break;
	case 6: /* instrucao: expressao */
#line 90 "factorial.brg"

		break;
	case 7: /* instrucao: corpo */
#line 91 "factorial.brg"

		break;
	case 8: /* expressoes: EXPS(expressoes,expressao) */
#line 105 "factorial.brg"

		break;
	case 9: /* expressoes: expressao */
#line 106 "factorial.brg"

		break;
	case 10: /* expressao: INT */
#line 108 "factorial.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 11: /* expressao: NUM */
#line 109 "factorial.brg"
{ fprintf(outfp, pfIMM, p->value.i); }
		break;
	case 12: /* expressao: STRN */
#line 110 "factorial.brg"

		break;
	case 13: /* expressao: lvalue */
#line 111 "factorial.brg"

		break;
	case 14: /* expressao: CALL2(IDENTIF,expressoes) */
#line 112 "factorial.brg"
{ fprintf(outfp, pfCALL pfTRASH, p->SUB(0)->value.s, p->SUB(0)->user); printf("%d - call- 2 args\n", p->SUB(0)->user);}
		break;
	case 15: /* expressao: CALL(IDENTIF) */
#line 113 "factorial.brg"
{ fprintf(outfp, pfCALL pfTRASH, p->SUB(0)->value.s, p->SUB(0)->user); printf("%d - call\n", p->SUB(0)->user);}
		break;
	case 16: /* expressao: ATRIB(lvalue,expressao) */
#line 114 "factorial.brg"
{ fprintf(outfp, pfDUP pfADDR pfSTORE, p->SUB(0)->value.s); }
		break;
	case 17: /* expressao: UMINUS(expressao) */
#line 115 "factorial.brg"
{ fprintf(outfp, pfNEG); }
		break;
	case 18: /* expressao: INC(IDENTIF,NIL) */
#line 116 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 19: /* expressao: DEC(IDENTIF,NIL) */
#line 117 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 20: /* expressao: INC(NIL,IDENTIF) */
#line 118 "factorial.brg"
{ fprintf(outfp, pfINCR, 1);}
		break;
	case 21: /* expressao: DEC(NIL,IDENTIF) */
#line 119 "factorial.brg"
{ fprintf(outfp, pfDECR, 1);}
		break;
	case 22: /* expressao: MUL(expressao,expressao) */
#line 120 "factorial.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 23: /* expressao: DIV(expressao,expressao) */
#line 121 "factorial.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 24: /* expressao: MOD(expressao,expressao) */
#line 122 "factorial.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 25: /* expressao: ADD(expressao,expressao) */
#line 123 "factorial.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 26: /* expressao: SUBT(expressao,expressao) */
#line 124 "factorial.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 27: /* expressao: GT(expressao,expressao) */
#line 125 "factorial.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 28: /* expressao: LT(expressao,expressao) */
#line 126 "factorial.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 29: /* expressao: EQ(expressao,expressao) */
#line 127 "factorial.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 30: /* expressao: NE(expressao,expressao) */
#line 128 "factorial.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 31: /* expressao: GE(expressao,expressao) */
#line 129 "factorial.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 32: /* expressao: LE(expressao,expressao) */
#line 130 "factorial.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 33: /* expressao: AND(expressao,expressao) */
#line 131 "factorial.brg"
{ fprintf(outfp, pfAND); }
		break;
	case 34: /* expressao: OR(expressao,expressao) */
#line 132 "factorial.brg"
{ fprintf(outfp, pfOR); }
		break;
	case 35: /* expressao: NEG(expressao) */
#line 133 "factorial.brg"
{ fprintf(outfp, pfNOT); }
		break;
	case 36: /* expressao: FACT(expressao) */
#line 134 "factorial.brg"

		break;
	case 37: /* expressao: ADDR(lvalue) */
#line 135 "factorial.brg"

		break;
	case 38: /* expressao: POINTER(lvalue) */
#line 136 "factorial.brg"

		break;
	case 39: /* lvalue: IDENTIF */
#line 138 "factorial.brg"
{   if (p->user == GLOBAL)
                          fprintf(outfp, pfADDRV, p->value.s); 
                        else
                          fprintf(outfp, pfLOCV, p->user); 
                    }
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


#line 149 "factorial.brg"


void function(char *name, int enter, Node *body) {
  int i;
  extern int trace;


  if(trace) printNode(body, stdout, yynames);
  if (body == 0) /* forward declaration */
    fprintf(outfp, pfEXTRN, name);
  else { /* function body */
    if (strcmp(name, "entry") == 0) 
      fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, "_entry", pfFUNC, "_entry", enter);
    else
    fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, name, pfFUNC, name, enter);
    if (yyselect(body) == 1) yyerror("No match for syntactic tree.");
    fprintf(outfp, pfLEAVE pfRET); /* just in case there is no 'return' */
    //  freeNode(body);
  }

  /*if (!strcmp(name, "entry")) { // deve ser corrigido - serve para o caso da entry
    fprintf(outfp, pfEXTRN pfEXTRN pfEXTRN pfEXTRN,
      U_"prints", U_"printi", U_"println", U_"readi");    
  }*/

}

void program(int enter, Node *body) {
  function("_entry", enter, body);
  fprintf(outfp, pfEXTRN pfEXTRN pfEXTRN pfEXTRN,
  		U_"prints", U_"printi", U_"println", U_"readi");
}

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

  }
  else if((value & 0x3) == 3){

  }
}


//fprintf(outfp, pfDATA pfALIGN pfLABEL pfINTEGER pfTEXT, name, value);
