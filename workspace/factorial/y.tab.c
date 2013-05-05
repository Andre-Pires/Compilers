#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "factorial.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include <stdarg.h>
#include "node.h"
#include "tabid.h"

extern void yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, int value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
char *mklbl(int n); /* generate counter based label */ 

int p, nciclo, nivel;
int pos = 0;
#line 21 "factorial.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
  double d;    /* double value */
	char *s;		/* symbol name or string literal */
  Node * n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 51 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define INT 257
#define NUM 258
#define IDENTIF 259
#define STRN 260
#define WHILE 261
#define IF 262
#define END 263
#define RETURN 264
#define VOID 265
#define PUBLIC 266
#define CONST 267
#define THEN 268
#define ELSE 269
#define DO 270
#define FOR 271
#define IN 272
#define STEP 273
#define UPTO 274
#define DOWNTO 275
#define BREAK 276
#define CONTINUE 277
#define INTEGER 278
#define STRING 279
#define NUMBER 280
#define GE 281
#define LE 282
#define EQ 283
#define NE 284
#define INC 285
#define DEC 286
#define ATRIB 287
#define ADDR 288
#define POINTER 289
#define IFX 290
#define CALL 291
#define NEG 292
#define FACT 293
#define AND 294
#define OR 295
#define PROG 296
#define ADD 297
#define SUBT 298
#define MUL 299
#define DIV 300
#define LT 301
#define GT 302
#define MOD 303
#define PARAMS 304
#define PARS2 305
#define PARS 306
#define INTRS 307
#define PINTR 308
#define INTR 309
#define DECL 310
#define DECLS 311
#define INIT 312
#define NIL 313
#define PNTR 314
#define EXPS 315
#define EXP 316
#define MALL 317
#define BODY 318
#define JZ 319
#define ETIQ 320
#define LABEL 321
#define JNZ 322
#define JMP 323
#define UMINUS 324
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   10,   10,   11,   11,   21,   22,   11,   23,
   11,   11,   11,    6,    6,   13,   13,   14,   14,   15,
   15,   12,   12,   12,   12,    2,    2,    2,    2,    2,
    2,   18,   18,   17,   16,    9,    9,    5,    5,    5,
    5,    8,    8,    7,    7,   24,   25,    7,   26,    7,
    7,    7,    7,    7,    7,    7,    7,    7,   19,   19,
   20,   20,    4,    4,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    1,    1,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    7,    6,    0,    0,   12,    0,
   10,    8,    2,    0,    1,    0,    1,    0,    1,    0,
    1,    1,    1,    1,    1,    2,    3,    3,    2,    3,
    2,    3,    0,    2,    3,    2,    3,    2,    3,    3,
    4,    1,    2,    4,    6,    0,    0,    7,    0,   10,
    2,    1,    3,    3,    2,    2,    4,    2,    1,    1,
    0,    2,    3,    1,    1,    1,    1,    1,    4,    3,
    3,    3,    2,    2,    2,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    2,    2,    2,    1,    4,
};
static const short yydefred[] = {                         0,
    0,   21,    0,    0,    3,    0,   13,    4,   19,    0,
   22,   23,   24,   25,    0,   17,    0,    0,    0,    0,
    6,    0,   26,   29,   31,    0,    0,    0,    0,    5,
   27,   30,   28,   12,    0,    0,   33,    0,    0,    0,
    0,    0,    8,    0,   65,   66,    0,   67,    0,   46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0,   52,   42,    0,    0,    0,   11,   35,
    0,    0,   58,    0,    0,    0,    0,    0,    0,    0,
    0,   55,    0,   56,   75,   74,   93,    0,   73,   94,
    0,   76,   77,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   92,   51,
   40,   43,   39,    0,    0,   36,   32,   15,    0,   70,
    0,    0,    0,    0,   47,    0,   53,   54,   71,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   37,    9,   69,    0,   96,
    0,    0,    0,   57,    0,    0,    0,   59,   60,    0,
   45,    0,    0,   48,    0,    0,    0,   49,    0,   50,
};
static const short yydgoto[] = {                          3,
   76,   22,   63,  122,   64,  119,   65,   66,   67,    4,
    5,   36,   17,   10,    6,   37,   38,   42,  160,  166,
   29,   72,   35,   78,  152,  169,
};
static const short yysindex[] = {                      -231,
  -37,    0,    0, -231,    0, -240,    0,    0,    0, -234,
    0,    0,    0,    0,   10,    0, -219,  -40,  -35,   15,
    0,  -16,    0,    0,    0, -210, -195,    9, -234,    0,
    0,    0,    0,    0,  -52,   10,    0,   31,  269,   22,
 -185,   47,    0,   34,    0,    0,  -24,    0,   94,    0,
 -163,  -57,  -53, -163, -163, -163,   94,   94, -163,   94,
    0,  -26,   86,    0,    0,  519,  333,   41,    0,    0,
 -234,  -52,    0,  468,   94, -143,  117,  623,   11, -169,
   50,    0,   52,    0,    0,    0,    0,   -9,    0,    0,
  143,    0,    0,   94,   94,   94,   94,   94,   94,   94,
   94,   94,   94,   94,   94,   94,   94,   94,    0,    0,
    0,    0,    0,  591,   62,    0,    0,    0,   66,    0,
  439,  -23,  169,  623,    0,   94,    0,    0,    0,  439,
  344,  128,  128,  460,  460,  300,   -9,  128,  128,   33,
   33,   73,   73,   73,    0,    0,    0,    0,   94,    0,
 -139, -135,   75,    0,  439,  623,   94,    0,    0,   94,
    0,  372,  400,    0,   94, -123,  439,    0,  623,    0,
};
static const short yyrindex[] = {                         1,
    0,    0,    0,    4,    0, -181,    0,    0,    0,    0,
    0,    0,    0,    0, -110,    0,    0,    0, -109, -164,
    0,    0,    0,    0,    0,    0,    0,   29,    0,    0,
    0,    0,    0,    0,    0, -110,    0,    0,    0,    0,
    0,  112,    0,    0,    0,    0,  -30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  428,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   97,    0,    0,    0,   45,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0, 1014,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -18,    0,    0,    0,    0,    0,    0,    0,    0,  262,
    0,  929,  957,  828, 1076, 1185, 1176,  982, 1023,  889,
  912,  765,  795,  869,    0,    0,    0,    0,    0,    0,
  474,    0,    0,    0,   -2,    0,    0,    0,    0,    0,
    0,    0, -113,    0,    0,    0, -112,    0,    0,    0,
};
static const short yygindex[] = {                         0,
 1260,    0, 1305,    0,  -15,    0,  -29,   96,    0,    0,
  162,  157,  132,  153,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1470
static const short yytable[] = {                         20,
    2,   82,   95,    1,   95,   84,   95,   95,   95,   26,
   95,   95,   95,   95,   95,   74,   95,  148,   21,   40,
  149,    7,   64,  109,    1,   64,    9,  108,   95,   95,
   11,   95,  106,  104,    2,  105,  112,  107,   63,   18,
   68,   63,   30,   12,   13,   14,   31,   32,  125,   95,
  103,   16,  102,   95,   95,   28,  118,   95,   95,   95,
   95,   95,   95,   95,   33,  109,   75,   34,  115,  108,
   39,   43,  117,   70,  106,   95,   95,   68,   95,  107,
   69,   68,   68,   18,  112,   68,   68,   68,   68,   68,
   71,   68,   73,   95,  151,   79,   18,   18,   18,  116,
    7,   75,  126,   68,   68,  109,   68,  109,  127,   95,
  128,  108,  101,    7,    7,    7,  106,  104,  109,  105,
  146,  107,  108,  101,  147,  157,  161,  106,  104,  156,
  105,   56,  107,   60,  103,   59,  102,   68,   58,  170,
   95,   92,   93,   94,  110,  103,  168,  102,   16,  109,
   18,   10,   34,  108,  101,   14,   61,   62,  106,  104,
  109,  105,  114,  107,  108,    8,   15,   41,   68,  106,
  104,   27,  105,    0,  107,  109,  103,    0,  102,  108,
  101,    0,    0,  129,  106,  104,    0,  105,    0,  107,
    0,    0,    0,    0,    0,    0,    0,    0,  100,   81,
    0,  109,  103,   83,  102,  108,  101,    0,    0,  100,
  106,  104,    0,  105,    0,  107,    0,    0,    0,   57,
    0,   23,   24,   25,    0,    0,    0,    0,  103,    0,
  102,    9,    0,    0,    0,    0,    0,   95,    0,   95,
  100,    0,   95,   95,   95,    0,   19,    0,    0,    0,
   95,   95,   95,   95,   95,   95,   95,    0,   92,   93,
   94,  150,    0,    0,    0,   20,  100,   20,   20,    0,
   20,   96,   97,   98,   99,    0,    0,    0,   20,   20,
   20,   20,   20,   20,   95,    0,   95,    0,   95,   95,
   95,   95,  100,    0,    0,    0,    0,   95,   95,   95,
   95,    0,   72,    0,    0,   72,   56,    0,   60,    0,
   59,    0,   68,   58,   68,    0,    0,   68,   68,   68,
   72,    0,    0,    0,    0,   68,   68,   68,   68,    0,
    0,    0,  109,    0,    0,    0,  108,  101,    0,    0,
    0,  106,  104,    0,  105,    0,  107,    0,  158,  159,
   45,   46,   47,   48,   72,   96,   97,   98,   99,  103,
    0,  102,    0,    0,    0,    0,   96,   97,   98,   99,
   56,    0,   60,    0,   59,    0,  109,   58,   54,   55,
  108,  101,    0,    0,  124,  106,  104,    0,  105,    0,
  107,   39,    0,   61,   57,    0,    0,   96,   97,   98,
   99,    0,  154,  103,  109,  102,    0,    0,  108,  101,
    0,    0,    0,  106,  104,    0,  105,    0,  107,    0,
    0,    0,    0,   96,   97,   98,   99,    0,    0,    0,
  164,  103,  109,  102,    0,    0,  108,  101,    0,    0,
    0,  106,  104,    0,  105,    0,  107,    0,    0,   96,
   97,   98,   99,    0,    0,   39,    0,  113,   57,  103,
   68,  102,    0,    0,   68,   68,    0,  100,    0,   68,
   68,  109,   68,    0,   68,  108,  101,    0,    0,    0,
  106,  104,    0,  105,    0,  107,   68,   68,    0,   68,
    0,    0,  109,    0,    0,  100,  108,    0,  103,    0,
  102,  106,  104,    0,  105,   56,  107,   60,  120,   59,
    0,   44,   58,   44,    0,   44,    0,    0,   44,  103,
    0,  102,    0,  100,   44,   45,   46,   47,   48,   72,
   49,   72,    0,   11,   72,   72,   72,    0,   50,   51,
    0,    0,    0,    0,   52,   53,   12,   13,   14,    0,
    0,   68,    0,   54,   55,    0,   56,    0,   60,    0,
   59,    0,  100,   58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   96,   97,   98,   99,    0,    0,    0,    0,   44,   45,
   46,   47,   48,   57,   49,    0,   44,   11,   44,   44,
    0,    0,   50,   51,    0,    0,    0,    0,   52,   53,
   12,   13,   14,    0,    0,    0,    0,   54,   55,    0,
    0,    0,    0,    0,   96,   97,   98,   99,   56,    0,
   60,    0,   59,    0,    0,   58,    0,    0,    0,    0,
    0,   39,    0,  111,   57,    0,    0,    0,    0,    0,
    0,    0,   96,   97,   98,   99,    0,    0,    0,    0,
   56,    0,   60,    0,   59,    0,    0,   58,    0,    0,
    0,    0,  165,    0,    0,    0,    0,    0,    0,    0,
   96,   97,   98,   99,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   68,   68,
   68,   68,    0,   39,    0,  145,   57,    0,    0,   96,
   97,   98,   99,    0,   45,   46,   47,   48,    0,   44,
   44,   44,   44,   44,   44,   44,    0,    0,    0,    0,
   96,   97,    0,   44,   44,   39,    0,    0,   57,   44,
   44,    0,   54,   55,    0,    0,    0,    0,   44,   44,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   44,   45,   46,   47,   48,    0,
   49,    0,    0,    0,    0,    0,    0,    0,   50,   51,
    0,    0,    0,    0,   52,   53,    0,    0,    0,    0,
    0,   78,   78,   54,   55,   78,   78,   78,   78,   78,
    0,   78,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   78,   78,    0,   78,    0,    0,    0,
    0,   79,   79,    0,    0,   79,   79,   79,   79,   79,
    0,   79,    0,    0,    0,    0,   44,   45,   46,   47,
   48,    0,   49,   79,   79,    0,   79,   78,    0,    0,
   50,   51,    0,    0,    0,   85,   52,   53,   85,    0,
    0,   85,    0,    0,    0,   54,   55,    0,   44,   45,
   46,   47,   48,    0,   49,    0,   85,   79,   78,    0,
    0,    0,   50,   51,    0,    0,    0,    0,   52,   53,
    0,    0,    0,    0,    0,   80,   80,   54,   55,   80,
   80,   80,   80,   80,    0,   80,    0,    0,   79,    0,
   85,    0,    0,    0,    0,    0,   81,   80,   80,   81,
   80,   81,   81,   81,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   81,   81,   82,
   81,   85,   82,    0,   82,   82,   82,    0,    0,    0,
    0,   80,    0,    0,    0,    0,   87,    0,    0,   87,
   82,   82,   87,   82,    0,    0,    0,    0,    0,    0,
    0,   81,    0,    0,    0,    0,    0,   87,   87,    0,
   87,    0,   80,    0,   88,    0,    0,   88,    0,    0,
   88,    0,    0,    0,   82,    0,    0,    0,    0,    0,
    0,    0,   81,    0,    0,   88,   88,    0,   88,   83,
    0,   87,   83,    0,    0,   83,    0,    0,    0,    0,
    0,    0,   78,    0,   78,   82,    0,   78,   78,   78,
   83,   83,    0,   83,    0,   78,   78,   78,   78,   88,
    0,   91,   87,    0,   91,    0,    0,   91,    0,    0,
   84,    0,   79,   84,   79,    0,   84,   79,   79,   79,
    0,    0,   91,    0,   83,   79,   79,   79,   79,    0,
   88,   84,   84,    0,   84,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   85,    0,   85,    0,    0,
   85,   85,   85,    0,    0,   83,   91,    0,    0,    0,
   85,   85,    0,   86,    0,   84,   86,    0,    0,   86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   86,    0,   80,   91,   80,    0,
    0,   80,   80,   80,    0,    0,   84,    0,    0,   80,
   80,   80,   80,    0,    0,    0,   81,    0,   81,    0,
    0,   81,   81,   81,    0,    0,    0,    0,   86,   81,
   81,   81,   81,    0,    0,    0,    0,    0,    0,   82,
    0,   82,    0,    0,   82,   82,   82,    0,    0,    0,
    0,    0,   82,   82,   82,   82,   87,    0,   87,   86,
    0,   87,   87,   87,    0,    0,    0,    0,    0,   87,
   87,   87,   87,   89,    0,    0,   89,    0,    0,   89,
    0,    0,    0,    0,   88,   90,   88,    0,   90,   88,
   88,   88,    0,    0,   89,    0,    0,   88,   88,   88,
   88,    0,    0,   90,    0,    0,    0,    0,    0,   83,
    0,   83,    0,    0,   83,   83,   83,    0,    0,    0,
    0,    0,   83,   83,   83,   83,    0,    0,   89,    0,
    0,    0,    0,    0,    0,    0,    0,   90,    0,    0,
    0,   91,    0,   91,    0,    0,   91,   91,   91,    0,
   84,    0,   84,    0,    0,   84,   84,   84,   62,   89,
    0,    0,    0,   84,   84,   84,   84,    0,   90,    0,
   80,    0,    0,   85,   86,   87,    0,    0,   90,    0,
    0,    0,    0,    0,    0,   62,   62,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,    0,
    0,    0,    0,   86,    0,   86,    0,    0,   86,   86,
   86,    0,    0,   77,    0,    0,    0,    0,   86,   86,
    0,   88,   89,    0,   91,    0,    0,    0,    0,    0,
    0,    0,    0,   62,    0,    0,    0,    0,  121,  123,
    0,    0,    0,   62,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  130,  131,
  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,    0,    0,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   62,    0,
  153,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   89,    0,   89,    0,    0,   89,   89,
   89,    0,   90,  155,   90,    0,    0,   90,   90,   90,
    0,  162,    0,    0,  163,    0,    0,    0,    0,  167,
};
static const short yycheck[] = {                         40,
    0,   59,   33,    0,   35,   59,   37,   38,   35,   45,
   41,   42,   43,   44,   45,   40,   47,   41,   59,   35,
   44,   59,   41,   33,  256,   44,  267,   37,   59,   60,
  265,   62,   42,   43,  266,   45,   66,   47,   41,  259,
   39,   44,   59,  278,  279,  280,  257,  258,   78,   33,
   60,   42,   62,   37,   38,   41,   72,   41,   42,   43,
   44,   45,   93,   47,  260,   33,   91,   59,   67,   37,
  123,   41,   71,  259,   42,   59,   60,   33,   62,   47,
   59,   37,   38,  265,  114,   41,   42,   43,   44,   45,
   44,   47,   59,  124,  124,  259,  278,  279,  280,   59,
  265,   91,  272,   59,   60,   33,   62,   33,   59,   93,
   59,   37,   38,  278,  279,  280,   42,   43,   33,   45,
   59,   47,   37,   38,   59,  261,  156,   42,   43,  269,
   45,   38,   47,   40,   60,   42,   62,   93,   45,  169,
  124,  285,  286,  287,   59,   60,  270,   62,  259,   33,
  260,  123,   41,   37,   38,   59,  270,  270,   42,   43,
   33,   45,   67,   47,   37,    4,   10,   36,  124,   42,
   43,   19,   45,   -1,   47,   33,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  257,
   -1,   33,   60,  257,   62,   37,   38,   -1,   -1,  124,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  126,
   -1,  257,  258,  259,   -1,   -1,   -1,   -1,   60,   -1,
   62,  267,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
  124,   -1,  273,  274,  275,   -1,  287,   -1,   -1,   -1,
  281,  282,  283,  284,  285,  286,  287,   -1,  285,  286,
  287,   93,   -1,   -1,   -1,  265,  124,  267,  265,   -1,
  267,  281,  282,  283,  284,   -1,   -1,   -1,  278,  279,
  280,  278,  279,  280,  268,   -1,  270,   -1,  272,  273,
  274,  275,  124,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   41,   -1,   -1,   44,   38,   -1,   40,   -1,
   42,   -1,  268,   45,  270,   -1,   -1,  273,  274,  275,
   59,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   37,   38,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,  274,  275,
  257,  258,  259,  260,   93,  281,  282,  283,  284,   60,
   -1,   62,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   38,   -1,   40,   -1,   42,   -1,   33,   45,  285,  286,
   37,   38,   -1,   -1,  268,   42,   43,   -1,   45,   -1,
   47,  123,   -1,  125,  126,   -1,   -1,  281,  282,  283,
  284,   -1,   59,   60,   33,   62,   -1,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,
   59,   60,   33,   62,   -1,   -1,   37,   38,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,  123,   -1,  125,  126,   60,
   33,   62,   -1,   -1,   37,   38,   -1,  124,   -1,   42,
   43,   33,   45,   -1,   47,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   59,   60,   -1,   62,
   -1,   -1,   33,   -1,   -1,  124,   37,   -1,   60,   -1,
   62,   42,   43,   -1,   45,   38,   47,   40,   41,   42,
   -1,   38,   45,   40,   -1,   42,   -1,   -1,   45,   60,
   -1,   62,   -1,  124,  256,  257,  258,  259,  260,  268,
  262,  270,   -1,  265,  273,  274,  275,   -1,  270,  271,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,   -1,
   -1,  124,   -1,  285,  286,   -1,   38,   -1,   40,   -1,
   42,   -1,  124,   45,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   -1,  256,  257,
  258,  259,  260,  126,  262,   -1,  123,  265,  125,  126,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  280,   -1,   -1,   -1,   -1,  285,  286,   -1,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   38,   -1,
   40,   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,  126,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,
   -1,   -1,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,
  283,  284,   -1,  123,   -1,  125,  126,   -1,   -1,  281,
  282,  283,  284,   -1,  257,  258,  259,  260,   -1,  256,
  257,  258,  259,  260,  261,  262,   -1,   -1,   -1,   -1,
  281,  282,   -1,  270,  271,  123,   -1,   -1,  126,  276,
  277,   -1,  285,  286,   -1,   -1,   -1,   -1,  285,  286,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,   -1,
  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
   -1,   -1,   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,
   -1,   37,   38,  285,  286,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,  256,  257,  258,  259,
  260,   -1,  262,   59,   60,   -1,   62,   93,   -1,   -1,
  270,  271,   -1,   -1,   -1,   38,  276,  277,   41,   -1,
   -1,   44,   -1,   -1,   -1,  285,  286,   -1,  256,  257,
  258,  259,  260,   -1,  262,   -1,   59,   93,  124,   -1,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,
   -1,   -1,   -1,   -1,   -1,   37,   38,  285,  286,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,  124,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   38,   59,   60,   41,
   62,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   38,
   62,  124,   41,   -1,   43,   44,   45,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   59,   60,   44,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,  124,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   59,   60,   -1,   62,   38,
   -1,   93,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,  268,   -1,  270,  124,   -1,  273,  274,  275,
   59,   60,   -1,   62,   -1,  281,  282,  283,  284,   93,
   -1,   38,  124,   -1,   41,   -1,   -1,   44,   -1,   -1,
   38,   -1,  268,   41,  270,   -1,   44,  273,  274,  275,
   -1,   -1,   59,   -1,   93,  281,  282,  283,  284,   -1,
  124,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,
  273,  274,  275,   -1,   -1,  124,   93,   -1,   -1,   -1,
  283,  284,   -1,   38,   -1,   93,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   -1,  268,  124,  270,   -1,
   -1,  273,  274,  275,   -1,   -1,  124,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,  268,   -1,  270,   -1,
   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   93,  281,
  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,  268,
   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,  268,   -1,  270,  124,
   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,  268,   41,  270,   -1,   44,  273,
  274,  275,   -1,   -1,   59,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1,  268,
   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,   93,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,
   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   39,  124,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,  124,   -1,
   51,   -1,   -1,   54,   55,   56,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   66,   67,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   78,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,   49,   -1,   -1,   -1,   -1,  283,  284,
   -1,   57,   58,   -1,   60,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  114,   -1,   -1,   -1,   -1,   74,   75,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,   95,
   96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,   -1,   -1,  156,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  169,   -1,
  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,  268,  149,  270,   -1,   -1,  273,  274,  275,
   -1,  157,   -1,   -1,  160,   -1,   -1,   -1,   -1,  165,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 324
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","NUM","IDENTIF","STRN",
"WHILE","IF","END","RETURN","VOID","PUBLIC","CONST","THEN","ELSE","DO","FOR",
"IN","STEP","UPTO","DOWNTO","BREAK","CONTINUE","INTEGER","STRING","NUMBER","GE",
"LE","EQ","NE","INC","DEC","ATRIB","ADDR","POINTER","IFX","CALL","NEG","FACT",
"AND","OR","PROG","ADD","SUBT","MUL","DIV","LT","GT","MOD","PARAMS","PARS2",
"PARS","INTRS","PINTR","INTR","DECL","DECLS","INIT","NIL","PNTR","EXPS","EXP",
"MALL","BODY","JZ","ETIQ","LABEL","JNZ","JMP","UMINUS",
};
static const char *yyrule[] = {
"$accept : ficheiro",
"ficheiro : declaracoes",
"ficheiro :",
"declaracoes : declaracao",
"declaracoes : declaracoes declaracao",
"declaracao : pub cons tipo ptr IDENTIF init ';'",
"declaracao : pub cons tipo ptr IDENTIF ';'",
"$$1 :",
"$$2 :",
"declaracao : pub cons tipo ptr IDENTIF '(' $$1 parametros ')' $$2 corpop ';'",
"$$3 :",
"declaracao : pub cons tipo ptr IDENTIF '(' ')' $$3 corpo ';'",
"declaracao : pub cons tipo ptr IDENTIF '(' ')' ';'",
"declaracao : error ';'",
"corpop :",
"corpop : corpo",
"ptr :",
"ptr : '*'",
"cons :",
"cons : CONST",
"pub :",
"pub : PUBLIC",
"tipo : VOID",
"tipo : INTEGER",
"tipo : STRING",
"tipo : NUMBER",
"init : ATRIB INT",
"init : ATRIB '-' INT",
"init : ATRIB cons STRN",
"init : ATRIB NUM",
"init : ATRIB '-' NUM",
"init : ATRIB IDENTIF",
"pars : pars ',' parametro",
"pars :",
"parametros : parametro pars",
"parametro : tipo ptr IDENTIF",
"pars2 : parametro ';'",
"pars2 : pars2 parametro ';'",
"corpo : '{' '}'",
"corpo : '{' pars2 '}'",
"corpo : '{' instrucoes '}'",
"corpo : '{' pars2 instrucoes '}'",
"instrucoes : instrucao",
"instrucoes : instrucoes instrucao",
"instrucao : IF expressao THEN instrucao",
"instrucao : IF expressao THEN instrucao ELSE instrucao",
"$$4 :",
"$$5 :",
"instrucao : DO $$4 instrucao $$5 WHILE expressao ';'",
"$$6 :",
"instrucao : FOR left_value IN expressao updown expressao step DO $$6 instrucao",
"instrucao : expressao ';'",
"instrucao : corpo",
"instrucao : BREAK INT ';'",
"instrucao : CONTINUE INT ';'",
"instrucao : BREAK ';'",
"instrucao : CONTINUE ';'",
"instrucao : left_value '#' expressao ';'",
"instrucao : error ';'",
"updown : UPTO",
"updown : DOWNTO",
"step :",
"step : STEP expressao",
"expressoes : expressoes ',' expressao",
"expressoes : expressao",
"expressao : INT",
"expressao : NUM",
"expressao : STRN",
"expressao : left_value",
"expressao : IDENTIF '(' expressoes ')'",
"expressao : IDENTIF '(' ')'",
"expressao : '(' expressao ')'",
"expressao : left_value ATRIB expressao",
"expressao : '-' expressao",
"expressao : DEC left_value",
"expressao : INC left_value",
"expressao : left_value INC",
"expressao : left_value DEC",
"expressao : expressao '*' expressao",
"expressao : expressao '/' expressao",
"expressao : expressao '%' expressao",
"expressao : expressao '+' expressao",
"expressao : expressao '-' expressao",
"expressao : expressao '>' expressao",
"expressao : expressao '<' expressao",
"expressao : expressao EQ expressao",
"expressao : expressao NE expressao",
"expressao : expressao GE expressao",
"expressao : expressao LE expressao",
"expressao : expressao '&' expressao",
"expressao : expressao '|' expressao",
"expressao : '~' expressao",
"expressao : expressao '!'",
"expressao : '&' left_value",
"expressao : '*' left_value",
"left_value : IDENTIF",
"left_value : IDENTIF '[' expressao ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 228 "factorial.y"
static int oper(Node * name, Node * name2) {
 
  if (name->info == 0 || name2->info == 0 || name->info == 2 || name2->info == 2) 
    yyerror("Operação : Tipo inválido.");
  if(name->info == 3 || name2->info == 3) return 3;
  else return 1;
}

static int comp(Node * name, Node * name2) {
 
  if (name->info == 0 || name2->info == 0) yyerror("Comparação : Tipo inválido.");
  if (name->info == 2 && name->info != name2->info) yyerror("Comparação : Tipos incompatíveis.");
  return 1;
}

/*
static Node *mkvar(char *name) {
  long loc;
  int typ = IDfind(name, &loc); /* find type and offset of the variable 
  if (typ >= 32 && loc != 0) /* global variables have offset==0 
    return intNode(LOCAL, loc); /* local variables are accessed by offset 
  return strNode(VARIABLE, name); /* global variables are accessed by name 
}
*/

char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strdup(buf);
}

char **yynames =
#if YYDEBUG > 0
     (char**)yyname;
#else
     0;
#endif
#line 735 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 52 "factorial.y"
	{Node * n = uniNode(PROG, yystack.l_mark[0].n); printNode(n, 0, 0); /*yyselect(n);*/}
break;
case 3:
#line 56 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 4:
#line 57 "factorial.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 5:
#line 60 "factorial.y"
	{ IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info, yystack.l_mark[-2].s, 0); 
                                                              yyval.n=binNode(INIT, strNode(IDENTIF, yystack.l_mark[-2].s), yystack.l_mark[-1].n);
                                                              yyval.n->info = yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info; 
                                                              if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != 4) {
                                                                if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != yystack.l_mark[-1].n->info) yyerror("Atribuição entre tipos diferentes.");}}
break;
case 6:
#line 66 "factorial.y"
	{ yyval.n=uniNode(DECL, strNode(IDENTIF, yystack.l_mark[-1].s)); IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info, yystack.l_mark[-1].s, 0);}
break;
case 7:
#line 68 "factorial.y"
	{IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info+32, yystack.l_mark[-1].s, 0); IDpush(); }
break;
case 8:
#line 69 "factorial.y"
	{IDreplace(yystack.l_mark[-8].n->info+yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+32,yystack.l_mark[-4].s, yystack.l_mark[-1].n->info); /*ver isto, devia passar parametros*/
                                               if((yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info) != 0) {IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info, yystack.l_mark[-4].s, 0);}}
break;
case 9:
#line 71 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-7].s), binNode(BODY, yystack.l_mark[-4].n, yystack.l_mark[-1].n)); IDpop();}
break;
case 10:
#line 73 "factorial.y"
	{IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+32, yystack.l_mark[-2].s, 0); IDpush();
                                                  if((yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info) != 0) {IDnew((yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info), yystack.l_mark[-2].s,0);} }
break;
case 11:
#line 75 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-5].s), yystack.l_mark[-1].n); IDpop();}
break;
case 12:
#line 77 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-3].s), nilNode(NIL)); IDnew(yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+32, yystack.l_mark[-3].s, 0);}
break;
case 13:
#line 78 "factorial.y"
	{yyerrok; }
break;
case 14:
#line 81 "factorial.y"
	{ yyval.n = nilNode(NIL); }
break;
case 15:
#line 82 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 16:
#line 85 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0; }
break;
case 17:
#line 86 "factorial.y"
	{ yyval.n= uniNode(PNTR, 0); yyval.n->info = 4; }
break;
case 18:
#line 89 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0;}
break;
case 19:
#line 90 "factorial.y"
	{ yyval.n= uniNode(CONST, 0); yyval.n->info = 8; }
break;
case 20:
#line 93 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0;}
break;
case 21:
#line 94 "factorial.y"
	{ yyval.n= uniNode(VOID, 0); yyval.n->info = 16; }
break;
case 22:
#line 97 "factorial.y"
	{ yyval.n = uniNode(VOID, 0); yyval.n->info = 0; }
break;
case 23:
#line 98 "factorial.y"
	{ yyval.n = uniNode(INTEGER, 0); yyval.n->info = 1; }
break;
case 24:
#line 99 "factorial.y"
	{ yyval.n = uniNode(STRING, 0); yyval.n->info = 2; }
break;
case 25:
#line 100 "factorial.y"
	{ yyval.n = uniNode(NUMBER, 0); yyval.n->info = 3; }
break;
case 26:
#line 103 "factorial.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 27:
#line 104 "factorial.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 28:
#line 105 "factorial.y"
	{ yyval.n = strNode(STRN, yystack.l_mark[0].s); yyval.n->info = yystack.l_mark[-1].n->info +2;}
break;
case 29:
#line 106 "factorial.y"
	{ yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 30:
#line 107 "factorial.y"
	{ yyval.n = realNode(NUM, -yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 31:
#line 108 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0)+4;}
break;
case 32:
#line 111 "factorial.y"
	{ yyval.n = binNode(PARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[0].n->info; }
break;
case 33:
#line 112 "factorial.y"
	{ yyval.n = nilNode(NIL); yyval.n->info = 0;}
break;
case 34:
#line 115 "factorial.y"
	{ yyval.n = binNode(PARAMS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-1].n->info + yystack.l_mark[0].n->info; }
break;
case 35:
#line 118 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); IDnew(yystack.l_mark[-2].n->info+yystack.l_mark[-1].n->info, yystack.l_mark[0].s, 0); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info;}
break;
case 36:
#line 121 "factorial.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 37:
#line 122 "factorial.y"
	{ yyval.n = binNode(PARS2, yystack.l_mark[-2].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info; }
break;
case 38:
#line 125 "factorial.y"
	{yyval.n = nilNode(NIL);}
break;
case 39:
#line 126 "factorial.y"
	{yyval.n = uniNode(PARS, yystack.l_mark[-1].n);}
break;
case 40:
#line 127 "factorial.y"
	{yyval.n = uniNode(INTRS, yystack.l_mark[-1].n);}
break;
case 41:
#line 128 "factorial.y"
	{yyval.n = binNode(PINTR, yystack.l_mark[-2].n , yystack.l_mark[-1].n);}
break;
case 42:
#line 131 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 43:
#line 132 "factorial.y"
	{yyval.n = binNode(INTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 44:
#line 135 "factorial.y"
	{ int lbl1 = ++lbl;
                                                                        yyval.n = seqNode(IFX, 3,
                                                                        binNode(JZ,yystack.l_mark[-2].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[0].n, /* instr */
                                                                        strNode(LABEL, mklbl(lbl1)));
                                                                       }
break;
case 45:
#line 141 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                        yyval.n = seqNode(IF, 6,
                                                                        binNode(JZ,yystack.l_mark[-4].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[-2].n, /* instr */
                                                                        strNode(JMP, mklbl(lbl2)),
                                                                        strNode(LABEL, mklbl(lbl1)),
                                                                        yystack.l_mark[0].n, /* else */
                                                                        strNode(LABEL, mklbl(lbl2)));
                                                                      }
break;
case 46:
#line 151 "factorial.y"
	{ nciclo++; }
break;
case 47:
#line 151 "factorial.y"
	{ nciclo--; }
break;
case 48:
#line 151 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                                yyval.n = seqNode(WHILE, 5,
                                                                                strNode(JMP, mklbl(lbl1)),
                                                                                strNode(LABEL, mklbl(lbl2)),
                                                                                yystack.l_mark[-4].n, /* instr */
                                                                                strNode(LABEL, mklbl(lbl1)),
                                                                                binNode(JNZ,yystack.l_mark[-1].n, strNode(ETIQ, mklbl(lbl2))));
                                                                              }
break;
case 49:
#line 160 "factorial.y"
	{ nciclo++; }
break;
case 50:
#line 160 "factorial.y"
	{ nciclo--; }
break;
case 51:
#line 162 "factorial.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 52:
#line 163 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 53:
#line 164 "factorial.y"
	{ if (yystack.l_mark[-1].i == 0 || yystack.l_mark[-1].i > nciclo) yyerror("Break inválido: Fora de um ciclo"); {yyval.n = uniNode(BREAK, intNode(INT, yystack.l_mark[-1].i));}}
break;
case 54:
#line 165 "factorial.y"
	{yyval.n = uniNode(CONTINUE, intNode(INT, yystack.l_mark[-1].i));}
break;
case 55:
#line 166 "factorial.y"
	{ if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); yyval.n = uniNode(BREAK, 0);}
break;
case 56:
#line 167 "factorial.y"
	{yyval.n = uniNode(CONTINUE, 0);}
break;
case 57:
#line 168 "factorial.y"
	{yyval.n = binNode(MALL, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 58:
#line 169 "factorial.y"
	{ yyerrok; }
break;
case 59:
#line 172 "factorial.y"
	{ yyval.n = uniNode(UPTO, 0); }
break;
case 60:
#line 173 "factorial.y"
	{ yyval.n = uniNode(DOWNTO, 0);}
break;
case 61:
#line 176 "factorial.y"
	{ yyval.n = nilNode(NIL);}
break;
case 62:
#line 177 "factorial.y"
	{ yyval.n = uniNode(STEP, yystack.l_mark[0].n); }
break;
case 63:
#line 180 "factorial.y"
	{ yyval.n = binNode(EXPS, yystack.l_mark[-2].n ,yystack.l_mark[0].n);}
break;
case 64:
#line 181 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 65:
#line 184 "factorial.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 66:
#line 185 "factorial.y"
	{ yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 67:
#line 186 "factorial.y"
	{ yyval.n = strNode(STRN, yystack.l_mark[0].s); yyval.n->info = 2;}
break;
case 68:
#line 187 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 69:
#line 188 "factorial.y"
	{ int n; n = IDfind(yystack.l_mark[-3].s, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) {yyval.n = binNode(CALL, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = n;} else {yyval.n = binNode(CALL, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = IDsearch(yystack.l_mark[-3].s, 0, IDlevel(), 0) & (0x7);}}
break;
case 70:
#line 189 "factorial.y"
	{ int n; n = IDfind(yystack.l_mark[-2].s, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) {yyval.n = uniNode(CALL, strNode(IDENTIF, yystack.l_mark[-2].s)); yyval.n->info = n;} else {yyval.n = uniNode(CALL, strNode(IDENTIF, yystack.l_mark[-2].s)); yyval.n->info = IDsearch(yystack.l_mark[-2].s, 0, IDlevel(), 0) & (0x7);}}
break;
case 71:
#line 190 "factorial.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 72:
#line 191 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 4){if (yystack.l_mark[-2].n->info != yystack.l_mark[0].n->info) yyerror("Atribuição entre tipos diferentes.");} yyval.n = binNode(ATRIB, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 73:
#line 192 "factorial.y"
	{ if(yystack.l_mark[0].n->info == 0 || yystack.l_mark[0].n->info == 2) yyerror("Simétrico : Tipo inválido"); yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 74:
#line 193 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Decremento : Tipo inválido"); yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 75:
#line 194 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Incremento : Tipo inválido"); yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 76:
#line 195 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Incremento : Tipo inválido"); yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 77:
#line 196 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Decremento : Tipo inválido"); yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 78:
#line 197 "factorial.y"
	{ yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 198 "factorial.y"
	{ yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 199 "factorial.y"
	{ yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 200 "factorial.y"
	{ yyval.n = binNode(ADD, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 201 "factorial.y"
	{ yyval.n = binNode(SUBT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 202 "factorial.y"
	{ yyval.n = binNode(GT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 203 "factorial.y"
	{ yyval.n = binNode(LT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 204 "factorial.y"
	{ yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 205 "factorial.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 87:
#line 206 "factorial.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 88:
#line 207 "factorial.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 89:
#line 208 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 1 || yystack.l_mark[0].n->info != 1) yyerror("Junção Lógica : Tipo inválido"); yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 90:
#line 209 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 1 || yystack.l_mark[0].n->info != 1) yyerror("Alternativa Lógica : Tipo inválido"); yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 91:
#line 210 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Negação Lógica : Tipo inválido"); yyval.n = uniNode(NEG, yystack.l_mark[0].n); }
break;
case 92:
#line 211 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Factorial : Tipo inválido"); yyval.n = uniNode(FACT, yystack.l_mark[-1].n); }
break;
case 93:
#line 212 "factorial.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 94:
#line 213 "factorial.y"
	{ yyval.n = uniNode(POINTER, yystack.l_mark[0].n); }
break;
case 95:
#line 216 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0); }
break;
case 96:
#line 218 "factorial.y"
	{int x = IDfind(yystack.l_mark[-3].s, 0); yyval.n = binNode(POINTER, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n);
                                                        if (((x & 0x4) == 4)) 
                                                              yyval.n->info = x - 4;
                                                        else if (((x & 0x7) == 2))
                                                              yyval.n->info = 1;
                                                        else yyerror("Ponteiro: Tipo inválido.");
                                                        /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
break;
#line 1353 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
