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
#include "y.tab.h"

extern void yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, int value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
char *mklbl(int n); /* generate counter based label */ 

int p, nciclo, nivel;
int pos = 0;
#line 22 "factorial.y"
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
#line 52 "y.tab.c"

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
    0,    0,   10,   10,   11,   11,   20,   21,   11,   22,
   11,   11,   11,    6,    6,   13,   13,   14,   14,   15,
   15,   12,   12,   12,   12,    2,    2,    2,    2,    2,
    2,   17,   17,   16,    9,    9,    5,    5,    5,    5,
    8,    8,    7,    7,   23,   24,    7,   25,    7,    7,
    7,    7,    7,    7,    7,    7,    7,   18,   18,   19,
   19,    4,    4,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    7,    6,    0,    0,   12,    0,
   10,    8,    2,    0,    1,    0,    1,    0,    1,    0,
    1,    1,    1,    1,    1,    2,    3,    3,    2,    3,
    2,    3,    1,    3,    2,    3,    2,    3,    3,    4,
    1,    2,    4,    6,    0,    0,    7,    0,   10,    2,
    1,    3,    3,    2,    2,    4,    2,    1,    1,    0,
    2,    3,    1,    1,    1,    1,    1,    4,    3,    3,
    3,    2,    2,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    1,    4,
};
static const short yydefred[] = {                         0,
    0,   21,    0,    0,    3,    0,   13,    4,   19,    0,
   22,   23,   24,   25,    0,   17,    0,    0,    0,    0,
    6,    0,   26,   29,   31,    0,    0,    0,    0,    5,
   27,   30,   28,   12,    0,    0,   33,    0,    0,    0,
    0,    8,    0,    0,   64,   65,    0,   66,    0,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   37,    0,    0,   51,   41,    0,    0,    0,   11,   34,
    0,   32,   57,    0,    0,    0,    0,    0,    0,    0,
    0,   54,    0,   55,   74,   73,   92,    0,   72,   93,
    0,   75,   76,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   91,   50,
   39,   42,   38,    0,    0,   35,   15,    0,   69,    0,
    0,    0,    0,   46,    0,   52,   53,   70,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,   36,    9,   68,    0,   95,    0,
    0,    0,   56,    0,    0,    0,   58,   59,    0,   44,
    0,    0,   47,    0,    0,    0,   48,    0,   49,
};
static const short yydgoto[] = {                          3,
   76,   22,   63,  121,   64,  118,   65,   66,   67,    4,
    5,   36,   17,   10,    6,   37,   38,  159,  165,   29,
   71,   35,   78,  151,  168,
};
static const short yysindex[] = {                      -235,
  -36,    0,    0, -235,    0, -242,    0,    0,    0, -239,
    0,    0,    0,    0,   -7,    0, -232,  -40,  -35,   -4,
    0,  -14,    0,    0,    0, -215, -195,  -11, -239,    0,
    0,    0,    0,    0,  -42,   -7,    0,    3,  269,   26,
 -168,    0, -239,   36,    0,    0,  -24,    0,   94,    0,
 -159,  -57,  -53, -159, -159, -159,   94,   94, -159,   94,
    0,  -26,   86,    0,    0,  519,  333,   42,    0,    0,
  -42,    0,    0,  468,   94, -212,  117,  623,   11, -169,
   47,    0,   50,    0,    0,    0,    0,   -9,    0,    0,
  143,    0,    0,   94,   94,   94,   94,   94,   94,   94,
   94,   94,   94,   94,   94,   94,   94,   94,    0,    0,
    0,    0,    0,  591,   55,    0,    0,   56,    0,  439,
    8,  169,  623,    0,   94,    0,    0,    0,  439,  344,
  150,  150,  460,  460,  300,   -9,  150,  150,  114,  114,
   78,   78,   78,    0,    0,    0,    0,   94,    0, -148,
 -135,   75,    0,  439,  623,   94,    0,    0,   94,    0,
  372,  400,    0,   94, -143,  439,    0,  623,    0,
};
static const short yyrindex[] = {                         1,
    0,    0,    0,    4,    0, -208,    0,    0,    0,    0,
    0,    0,    0,    0, -129,    0,    0,    0, -120, -181,
    0,    0,    0,    0,    0,    0,    0,   19,    0,    0,
    0,    0,    0,    0,    0, -129,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  428,    0,    0,    0,    0,    0,    0,    0,    0,
   84,    0,    0,    0,    0,   45,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0, 1014,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
    0,    0,    0,    0,    0,    0,    0,    0,  262,    0,
  929,  957,  828, 1076, 1185, 1176,  982, 1023,  889,  912,
  765,  795,  869,    0,    0,    0,    0,    0,    0,  474,
    0,    0,    0,   52,    0,    0,    0,    0,    0,    0,
    0, -126,    0,    0,    0, -121,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  584,    0, 1267,    0,  -15,    0,    2,   85,    0,    0,
  149,  148,  127,  146,    0,  -21,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1460
static const short yytable[] = {                         20,
    2,   82,   94,    1,   94,   84,   94,   94,   95,   26,
   94,   94,   94,   94,   94,   74,   94,   68,   21,   40,
    1,   72,    7,  109,    9,   11,   18,  108,   94,   94,
    2,   94,  106,  104,   16,  105,   28,  107,   12,   13,
   14,   31,   32,   42,   30,  115,   43,   34,  147,   94,
  103,  148,  102,   94,   94,  117,   18,   94,   94,   94,
   94,   94,   94,   94,   33,   63,   75,  112,   63,   18,
   18,   18,   92,   93,   94,   94,   94,   67,   94,  124,
   39,   67,   67,    7,   69,   67,   67,   67,   67,   67,
   70,   67,   62,   94,   73,   62,    7,    7,    7,   79,
  116,   75,  125,   67,   67,  126,   67,  109,  127,   94,
  109,  108,  101,  145,  146,  112,  106,  104,  109,  105,
  155,  107,  108,  101,  150,  156,  167,  106,  104,   16,
  105,   56,  107,   60,  103,   59,  102,   67,   58,   18,
   94,   10,   14,   60,  110,  103,  109,  102,   61,  109,
  108,  114,    8,  108,  101,  106,  160,   15,  106,  104,
  107,  105,   41,  107,   27,    0,    0,    0,   67,  169,
    0,    0,    0,    0,    0,  109,  103,    0,  102,  108,
  101,    0,  109,  128,  106,  104,  108,  105,    0,  107,
    0,  106,  104,    0,  105,    0,  107,    0,  100,   81,
    0,  109,  103,   83,  102,  108,  101,    0,    0,  100,
  106,  104,    0,  105,    0,  107,    0,    0,    0,   57,
    0,   23,   24,   25,    0,    0,    0,    0,  103,    0,
  102,    9,    0,    0,    0,    0,    0,   94,    0,   94,
  100,    0,   94,   94,   94,    0,   19,    0,    0,    0,
   94,   94,   94,   94,   94,   94,   94,    0,   92,   93,
   94,  149,    0,    0,    0,   20,  100,   20,   20,    0,
   20,   96,   97,   98,   99,    0,    0,    0,   20,   20,
   20,   20,   20,   20,   94,    0,   94,    0,   94,   94,
   94,   94,  100,    0,    0,    0,    0,   94,   94,   94,
   94,    0,   71,    0,    0,   71,   56,    0,   60,    0,
   59,    0,   67,   58,   67,    0,    0,   67,   67,   67,
   71,    0,    0,    0,    0,   67,   67,   67,   67,    0,
    0,    0,  109,    0,    0,    0,  108,  101,    0,    0,
    0,  106,  104,    0,  105,    0,  107,    0,  157,  158,
   45,   46,   47,   48,   71,   96,   97,   98,   99,  103,
    0,  102,    0,    0,    0,    0,   96,   97,   98,   99,
   56,    0,   60,    0,   59,    0,  109,   58,   54,   55,
  108,  101,    0,    0,  123,  106,  104,    0,  105,    0,
  107,   39,    0,   61,   57,    0,    0,   96,   97,   98,
   99,    0,  153,  103,  109,  102,    0,    0,  108,  101,
    0,    0,    0,  106,  104,    0,  105,    0,  107,    0,
    0,    0,    0,   96,   97,   98,   99,    0,    0,    0,
  163,  103,  109,  102,    0,    0,  108,  101,    0,    0,
    0,  106,  104,    0,  105,    0,  107,    0,    0,   96,
   97,   98,   99,    0,    0,   39,    0,  113,   57,  103,
   67,  102,    0,    0,   67,   67,    0,  100,    0,   67,
   67,  109,   67,    0,   67,  108,  101,    0,    0,    0,
  106,  104,    0,  105,    0,  107,   67,   67,    0,   67,
    0,    0,  109,    0,    0,  100,  108,    0,  103,    0,
  102,  106,  104,    0,  105,   56,  107,   60,  119,   59,
    0,   43,   58,   43,    0,   43,    0,    0,   43,  103,
    0,  102,    0,  100,   44,   45,   46,   47,   48,   71,
   49,   71,    0,   11,   71,   71,   71,    0,   50,   51,
    0,    0,    0,    0,   52,   53,   12,   13,   14,    0,
    0,   67,    0,   54,   55,    0,   56,    0,   60,    0,
   59,    0,  100,   58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   96,   97,   98,   99,    0,    0,    0,    0,   44,   45,
   46,   47,   48,   57,   49,    0,   43,   11,   43,   43,
    0,    0,   50,   51,    0,    0,    0,    0,   52,   53,
   12,   13,   14,    0,    0,    0,    0,   54,   55,    0,
    0,    0,   62,    0,   96,   97,   98,   99,   56,    0,
   60,    0,   59,    0,   80,   58,    0,   85,   86,   87,
    0,   39,   90,  111,   57,    0,    0,    0,    0,   62,
   62,    0,   96,   97,   98,   99,    0,    0,    0,    0,
   56,   62,   60,    0,   59,    0,    0,   58,    0,    0,
    0,    0,  164,    0,    0,    0,    0,    0,    0,    0,
   96,   97,   98,   99,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,    0,
    0,    0,    0,    0,    0,    0,   62,    0,   67,   67,
   67,   67,    0,   39,    0,  144,   57,    0,    0,   96,
   97,   98,   99,    0,   45,   46,   47,   48,    0,   43,
   43,   43,   43,   43,   43,   43,    0,    0,   62,    0,
   96,   97,    0,   43,   43,   39,    0,    0,   57,   43,
   43,   62,   54,   55,    0,    0,    0,    0,   43,   43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   44,   45,   46,   47,   48,    0,
   49,    0,    0,    0,    0,    0,    0,    0,   50,   51,
    0,    0,    0,    0,   52,   53,    0,    0,    0,    0,
    0,   77,   77,   54,   55,   77,   77,   77,   77,   77,
    0,   77,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   77,   77,    0,   77,    0,    0,    0,
    0,   78,   78,    0,    0,   78,   78,   78,   78,   78,
    0,   78,    0,    0,    0,    0,   44,   45,   46,   47,
   48,    0,   49,   78,   78,    0,   78,   77,    0,    0,
   50,   51,    0,    0,    0,   84,   52,   53,   84,    0,
    0,   84,    0,    0,    0,   54,   55,    0,   44,   45,
   46,   47,   48,    0,   49,    0,   84,   78,   77,    0,
    0,    0,   50,   51,    0,    0,    0,    0,   52,   53,
    0,    0,    0,    0,    0,   79,   79,   54,   55,   79,
   79,   79,   79,   79,    0,   79,    0,    0,   78,    0,
   84,    0,    0,    0,    0,    0,   80,   79,   79,   80,
   79,   80,   80,   80,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   80,   80,   81,
   80,   84,   81,    0,   81,   81,   81,    0,    0,    0,
    0,   79,    0,    0,    0,    0,   86,    0,    0,   86,
   81,   81,   86,   81,    0,    0,    0,    0,    0,    0,
    0,   80,    0,    0,    0,    0,    0,   86,   86,    0,
   86,    0,   79,    0,   87,    0,    0,   87,    0,    0,
   87,    0,    0,    0,   81,    0,    0,    0,    0,    0,
    0,    0,   80,    0,    0,   87,   87,    0,   87,   82,
    0,   86,   82,    0,    0,   82,    0,    0,    0,    0,
    0,    0,   77,    0,   77,   81,    0,   77,   77,   77,
   82,   82,    0,   82,    0,   77,   77,   77,   77,   87,
    0,   90,   86,    0,   90,    0,    0,   90,    0,    0,
   83,    0,   78,   83,   78,    0,   83,   78,   78,   78,
    0,    0,   90,    0,   82,   78,   78,   78,   78,    0,
   87,   83,   83,    0,   83,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   84,    0,   84,    0,    0,
   84,   84,   84,    0,    0,   82,   90,    0,    0,    0,
   84,   84,    0,   85,    0,   83,   85,    0,    0,   85,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   85,    0,   79,   90,   79,    0,
    0,   79,   79,   79,    0,    0,   83,    0,    0,   79,
   79,   79,   79,    0,    0,    0,   80,    0,   80,    0,
    0,   80,   80,   80,    0,    0,    0,    0,   85,   80,
   80,   80,   80,    0,    0,    0,    0,    0,    0,   81,
    0,   81,    0,    0,   81,   81,   81,    0,    0,    0,
    0,    0,   81,   81,   81,   81,   86,    0,   86,   85,
    0,   86,   86,   86,    0,    0,    0,    0,    0,   86,
   86,   86,   86,   88,    0,    0,   88,    0,    0,   88,
    0,    0,    0,    0,   87,   89,   87,    0,   89,   87,
   87,   87,    0,    0,   88,    0,    0,   87,   87,   87,
   87,    0,    0,   89,    0,    0,    0,    0,    0,   82,
    0,   82,    0,    0,   82,   82,   82,    0,    0,    0,
    0,    0,   82,   82,   82,   82,    0,    0,   88,    0,
    0,    0,    0,    0,    0,    0,    0,   89,    0,    0,
    0,   90,    0,   90,    0,    0,   90,   90,   90,    0,
   83,    0,   83,    0,    0,   83,   83,   83,    0,   88,
    0,    0,    0,   83,   83,   83,   83,    0,   89,    0,
    0,    0,    0,    0,    0,   77,    0,    0,    0,    0,
    0,    0,    0,   88,   89,    0,   91,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  120,  122,    0,   85,    0,   85,    0,    0,   85,   85,
   85,    0,    0,    0,    0,    0,    0,    0,   85,   85,
  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,
  139,  140,  141,  142,  143,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  152,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  154,    0,    0,    0,    0,    0,
    0,    0,  161,    0,    0,  162,    0,    0,    0,    0,
  166,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   88,    0,   88,    0,    0,   88,   88,
   88,    0,   89,    0,   89,    0,    0,   89,   89,   89,
};
static const short yycheck[] = {                         40,
    0,   59,   33,    0,   35,   59,   37,   38,   35,   45,
   41,   42,   43,   44,   45,   40,   47,   39,   59,   35,
  256,   43,   59,   33,  267,  265,  259,   37,   59,   60,
  266,   62,   42,   43,   42,   45,   41,   47,  278,  279,
  280,  257,  258,   41,   59,   67,   44,   59,   41,   33,
   60,   44,   62,   37,   38,   71,  265,   41,   42,   43,
   44,   45,   93,   47,  260,   41,   91,   66,   44,  278,
  279,  280,  285,  286,  287,   59,   60,   33,   62,   78,
  123,   37,   38,  265,   59,   41,   42,   43,   44,   45,
  259,   47,   41,  124,   59,   44,  278,  279,  280,  259,
   59,   91,  272,   59,   60,   59,   62,   33,   59,   93,
   33,   37,   38,   59,   59,  114,   42,   43,   33,   45,
  269,   47,   37,   38,  123,  261,  270,   42,   43,  259,
   45,   38,   47,   40,   60,   42,   62,   93,   45,  260,
  124,  123,   59,  270,   59,   60,   33,   62,  270,   33,
   37,   67,    4,   37,   38,   42,  155,   10,   42,   43,
   47,   45,   36,   47,   19,   -1,   -1,   -1,  124,  168,
   -1,   -1,   -1,   -1,   -1,   33,   60,   -1,   62,   37,
   38,   -1,   33,   41,   42,   43,   37,   45,   -1,   47,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,  124,  257,
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
   -1,   -1,   39,   -1,  281,  282,  283,  284,   38,   -1,
   40,   -1,   42,   -1,   51,   45,   -1,   54,   55,   56,
   -1,  123,   59,  125,  126,   -1,   -1,   -1,   -1,   66,
   67,   -1,  281,  282,  283,  284,   -1,   -1,   -1,   -1,
   38,   78,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,
   -1,   -1,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  114,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  281,  282,
  283,  284,   -1,  123,   -1,  125,  126,   -1,   -1,  281,
  282,  283,  284,   -1,  257,  258,  259,  260,   -1,  256,
  257,  258,  259,  260,  261,  262,   -1,   -1,  155,   -1,
  281,  282,   -1,  270,  271,  123,   -1,   -1,  126,  276,
  277,  168,  285,  286,   -1,   -1,   -1,   -1,  285,  286,
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
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,  124,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   49,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   57,   58,   -1,   60,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   74,   75,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,
   94,   95,   96,   97,   98,   99,  100,  101,  102,  103,
  104,  105,  106,  107,  108,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  148,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  156,   -1,   -1,  159,   -1,   -1,   -1,   -1,
  164,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,
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
"parametros : parametros ',' parametro",
"parametros : parametro",
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
#line 227 "factorial.y"
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

static void assign(char *name) {
  if (IDfind(name, (long*)IDtest) < 0)
    IDnew(INTEGER, name, pos -= 4);
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
#line 738 "y.tab.c"

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
#line 53 "factorial.y"
	{Node * n = uniNode(PROG, yystack.l_mark[0].n); program(-pos, yystack.l_mark[0].n); printNode(n, 0, yynames); /*yyselect(n);*/}
break;
case 3:
#line 57 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 4:
#line 58 "factorial.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 5:
#line 61 "factorial.y"
	{ IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info, yystack.l_mark[-2].s, 0); declare(yystack.l_mark[-2].s, yystack.l_mark[-1].n->info);
                                                              yyval.n=binNode(INIT, strNode(IDENTIF, yystack.l_mark[-2].s), yystack.l_mark[-1].n);
                                                              yyval.n->info = yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info; 
                                                              if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != 4) {
                                                                if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != yystack.l_mark[-1].n->info) yyerror("Atribuição entre tipos diferentes.");}}
break;
case 6:
#line 67 "factorial.y"
	{ yyval.n=uniNode(DECL, strNode(IDENTIF, yystack.l_mark[-1].s)); IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-1].s, yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info);}
break;
case 7:
#line 69 "factorial.y"
	{IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info+32, yystack.l_mark[-1].s, 0); IDpush(); pos = 8; }
break;
case 8:
#line 70 "factorial.y"
	{IDreplace(yystack.l_mark[-8].n->info+yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+32,yystack.l_mark[-4].s, yystack.l_mark[-1].n->info); /*ver isto, devia passar parametros*/
                                               if((yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info) != 0) {IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info, yystack.l_mark[-4].s, 0);} pos = 0;}
break;
case 9:
#line 72 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-7].s), binNode(BODY, yystack.l_mark[-4].n, yystack.l_mark[-1].n)); IDpop(); /* usar o YYselect à entrada do corpo*/ function(yystack.l_mark[-7].s, -pos, yystack.l_mark[-1].n); pos = 0; }
break;
case 10:
#line 74 "factorial.y"
	{IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+32, yystack.l_mark[-2].s, 0); IDpush();
                                                  if((yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info) != 0) {IDnew((yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info), yystack.l_mark[-2].s,0);}}
break;
case 11:
#line 76 "factorial.y"
	{ yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-5].s), yystack.l_mark[-1].n); IDpop(); function(yystack.l_mark[-5].s, -pos, yystack.l_mark[-1].n); pos = 0;}
break;
case 12:
#line 78 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-3].s), nilNode(NIL)); IDnew(yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+32, yystack.l_mark[-3].s, 0); function(yystack.l_mark[-3].s, -pos, 0); pos = 0;}
break;
case 13:
#line 79 "factorial.y"
	{yyerrok; }
break;
case 14:
#line 82 "factorial.y"
	{ yyval.n = nilNode(NIL); }
break;
case 15:
#line 83 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 16:
#line 86 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0; }
break;
case 17:
#line 87 "factorial.y"
	{ yyval.n= uniNode(PNTR, 0); yyval.n->info = 4; }
break;
case 18:
#line 90 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0;}
break;
case 19:
#line 91 "factorial.y"
	{ yyval.n= uniNode(CONST, 0); yyval.n->info = 8; }
break;
case 20:
#line 94 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0;}
break;
case 21:
#line 95 "factorial.y"
	{ yyval.n= uniNode(VOID, 0); yyval.n->info = 16; }
break;
case 22:
#line 98 "factorial.y"
	{ yyval.n = uniNode(VOID, 0); yyval.n->info = 0; }
break;
case 23:
#line 99 "factorial.y"
	{ yyval.n = uniNode(INTEGER, 0); yyval.n->info = 1; }
break;
case 24:
#line 100 "factorial.y"
	{ yyval.n = uniNode(STRING, 0); yyval.n->info = 2; }
break;
case 25:
#line 101 "factorial.y"
	{ yyval.n = uniNode(NUMBER, 0); yyval.n->info = 3; }
break;
case 26:
#line 104 "factorial.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 27:
#line 105 "factorial.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 28:
#line 106 "factorial.y"
	{ yyval.n = strNode(STRN, yystack.l_mark[0].s); yyval.n->info = yystack.l_mark[-1].n->info +2;}
break;
case 29:
#line 107 "factorial.y"
	{ yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 30:
#line 108 "factorial.y"
	{ yyval.n = realNode(NUM, -yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 31:
#line 109 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0)+4;}
break;
case 32:
#line 113 "factorial.y"
	{ yyval.n = binNode(PARAMS, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[0].n->info;}
break;
case 33:
#line 114 "factorial.y"
	{ yyval.n = uniNode(PARAMS, yystack.l_mark[0].n);  yyval.n->info = yystack.l_mark[0].n->info; /* tentar alterar o IDnew para fazer as variaveis dos parametros das funcoes (positivos) compact*/}
break;
case 34:
#line 117 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); IDnew(yystack.l_mark[-2].n->info+yystack.l_mark[-1].n->info, yystack.l_mark[0].s, 0); if (pos >= 8) { yyval.n->user = pos; pos += 4; } else { pos -= 4; yyval.n->user = pos;} yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info;}
break;
case 35:
#line 120 "factorial.y"
	{ yyval.n = yystack.l_mark[-1].n; /* tentar alterar o IDnew para fazer as variaveis locais das funcoes (negativos) compact*/}
break;
case 36:
#line 121 "factorial.y"
	{ yyval.n = binNode(PARS2, yystack.l_mark[-2].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info; }
break;
case 37:
#line 124 "factorial.y"
	{yyval.n = nilNode(NIL);}
break;
case 38:
#line 125 "factorial.y"
	{yyval.n = uniNode(PARS, yystack.l_mark[-1].n);}
break;
case 39:
#line 126 "factorial.y"
	{yyval.n = uniNode(INTRS, yystack.l_mark[-1].n);}
break;
case 40:
#line 127 "factorial.y"
	{yyval.n = binNode(PINTR, yystack.l_mark[-2].n , yystack.l_mark[-1].n);}
break;
case 41:
#line 130 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 42:
#line 131 "factorial.y"
	{yyval.n = binNode(INTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 43:
#line 134 "factorial.y"
	{ int lbl1 = ++lbl;
                                                                        yyval.n = seqNode(IFX, 3,
                                                                        binNode(JZ,yystack.l_mark[-2].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[0].n, /* instr */
                                                                        strNode(LABEL, mklbl(lbl1)));
                                                                       }
break;
case 44:
#line 140 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                        yyval.n = seqNode(ELSE, 6,
                                                                        binNode(JZ,yystack.l_mark[-4].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[-2].n, /* instr */
                                                                        strNode(JMP, mklbl(lbl2)),
                                                                        strNode(LABEL, mklbl(lbl1)),
                                                                        yystack.l_mark[0].n, /* else */
                                                                        strNode(LABEL, mklbl(lbl2)));
                                                                      }
break;
case 45:
#line 150 "factorial.y"
	{ nciclo++; }
break;
case 46:
#line 150 "factorial.y"
	{ nciclo--; }
break;
case 47:
#line 150 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                                yyval.n = seqNode(WHILE, 5,
                                                                                strNode(JMP, mklbl(lbl1)),
                                                                                strNode(LABEL, mklbl(lbl2)),
                                                                                yystack.l_mark[-4].n, /* instr */
                                                                                strNode(LABEL, mklbl(lbl1)),
                                                                                binNode(JNZ,yystack.l_mark[-1].n, strNode(ETIQ, mklbl(lbl2))));
                                                                              }
break;
case 48:
#line 159 "factorial.y"
	{ nciclo++; }
break;
case 49:
#line 159 "factorial.y"
	{ nciclo--; }
break;
case 50:
#line 161 "factorial.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 51:
#line 162 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 52:
#line 163 "factorial.y"
	{ if (yystack.l_mark[-1].i == 0 || yystack.l_mark[-1].i > nciclo) yyerror("Break inválido: Fora de um ciclo"); {yyval.n = uniNode(BREAK, intNode(INT, yystack.l_mark[-1].i));}}
break;
case 53:
#line 164 "factorial.y"
	{yyval.n = uniNode(CONTINUE, intNode(INT, yystack.l_mark[-1].i));}
break;
case 54:
#line 165 "factorial.y"
	{ if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); yyval.n = uniNode(BREAK, 0);}
break;
case 55:
#line 166 "factorial.y"
	{yyval.n = uniNode(CONTINUE, 0);}
break;
case 56:
#line 167 "factorial.y"
	{yyval.n = binNode(MALL, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 57:
#line 168 "factorial.y"
	{ yyerrok; }
break;
case 58:
#line 171 "factorial.y"
	{ yyval.n = uniNode(UPTO, 0); }
break;
case 59:
#line 172 "factorial.y"
	{ yyval.n = uniNode(DOWNTO, 0);}
break;
case 60:
#line 175 "factorial.y"
	{ yyval.n = nilNode(NIL);}
break;
case 61:
#line 176 "factorial.y"
	{ yyval.n = uniNode(STEP, yystack.l_mark[0].n); }
break;
case 62:
#line 179 "factorial.y"
	{ yyval.n = binNode(EXPS, yystack.l_mark[-2].n ,yystack.l_mark[0].n);}
break;
case 63:
#line 180 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 64:
#line 183 "factorial.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 65:
#line 184 "factorial.y"
	{ yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 66:
#line 185 "factorial.y"
	{ yyval.n = strNode(STRN, yystack.l_mark[0].s); yyval.n->info = 2;}
break;
case 67:
#line 186 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 68:
#line 187 "factorial.y"
	{ int n; n = IDfind(yystack.l_mark[-3].s, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) {yyval.n = binNode(CALL, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = n;} else {yyval.n = binNode(CALL, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = IDsearch(yystack.l_mark[-3].s, 0, IDlevel(), 0) & (0x7);}}
break;
case 69:
#line 188 "factorial.y"
	{ int n; n = IDfind(yystack.l_mark[-2].s, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) {yyval.n = uniNode(CALL, strNode(IDENTIF, yystack.l_mark[-2].s)); yyval.n->info = n;} else {yyval.n = uniNode(CALL, strNode(IDENTIF, yystack.l_mark[-2].s)); yyval.n->info = IDsearch(yystack.l_mark[-2].s, 0, IDlevel(), 0) & (0x7);}}
break;
case 70:
#line 189 "factorial.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 71:
#line 190 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 4){if (yystack.l_mark[-2].n->info != yystack.l_mark[0].n->info) yyerror("Atribuição entre tipos diferentes.");} yyval.n = binNode(ATRIB, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 72:
#line 191 "factorial.y"
	{ if(yystack.l_mark[0].n->info == 0 || yystack.l_mark[0].n->info == 2) yyerror("Simétrico : Tipo inválido"); yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 73:
#line 192 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Decremento : Tipo inválido"); yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 74:
#line 193 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Incremento : Tipo inválido"); yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 75:
#line 194 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Incremento : Tipo inválido"); yyval.n = binNode(INC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 76:
#line 195 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Decremento : Tipo inválido"); yyval.n = binNode(DEC, nilNode(NIL), yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 77:
#line 196 "factorial.y"
	{ yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 197 "factorial.y"
	{ yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 198 "factorial.y"
	{ yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 199 "factorial.y"
	{ yyval.n = binNode(ADD, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 200 "factorial.y"
	{ yyval.n = binNode(SUBT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 201 "factorial.y"
	{ yyval.n = binNode(GT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 202 "factorial.y"
	{ yyval.n = binNode(LT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 203 "factorial.y"
	{ yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 204 "factorial.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 205 "factorial.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 87:
#line 206 "factorial.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 88:
#line 207 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 1 || yystack.l_mark[0].n->info != 1) yyerror("Junção Lógica : Tipo inválido"); yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 89:
#line 208 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 1 || yystack.l_mark[0].n->info != 1) yyerror("Alternativa Lógica : Tipo inválido"); yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 90:
#line 209 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Negação Lógica : Tipo inválido"); yyval.n = uniNode(NEG, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 91:
#line 210 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Factorial : Tipo inválido"); yyval.n = uniNode(FACT, yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 92:
#line 211 "factorial.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 93:
#line 212 "factorial.y"
	{ yyval.n = uniNode(POINTER, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 94:
#line 215 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0); }
break;
case 95:
#line 217 "factorial.y"
	{int x = IDfind(yystack.l_mark[-3].s, 0); yyval.n = binNode(POINTER, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n);
                                                        if (((x & 0x4) == 4)) 
                                                              yyval.n->info = x - 4;
                                                        else if (((x & 0x7) == 2))
                                                              yyval.n->info = 1;
                                                        else yyerror("Ponteiro: Tipo inválido.");
                                                        /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
break;
#line 1352 "y.tab.c"
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
