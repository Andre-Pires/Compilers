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
#include "node.h"
#include "tabid.h"
#include "y.tab.h"

extern void yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, Node * value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
int cclbl; /* label counter for generated cicle labels */
char *mklbl(int n); /* generate counter based label */ 


/* ciclos */
int lbl1, lbl2;

int p, nciclo, nivel;
int pos;
#line 26 "factorial.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int i;      /* integer value */
  double d;    /* double value */
  char *s;    /* symbol name or string literal */
  Node * n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "y.tab.c"

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
#define SHIFT 281
#define GE 282
#define LE 283
#define EQ 284
#define NE 285
#define INC 286
#define DEC 287
#define ATRIB 288
#define ADDR 289
#define POINTER 290
#define IFX 291
#define LIST 292
#define VECTOR 293
#define ELIF 294
#define CALL 295
#define CALL2 296
#define NEG 297
#define FACT 298
#define AND 299
#define OR 300
#define PROG 301
#define ADD 302
#define SUBT 303
#define MUL 304
#define DIV 305
#define LT 306
#define GT 307
#define MOD 308
#define PARAMS 309
#define PARS2 310
#define PARS 311
#define PINTR 312
#define INTR 313
#define DECL 314
#define DECLS 315
#define INIT 316
#define NIL 317
#define PNTR 318
#define EXPS 319
#define EXP 320
#define MALL 321
#define BODY 322
#define JZ 323
#define ETIQ 324
#define LABEL 325
#define JNZ 326
#define JMP 327
#define INSTRS 328
#define UMINUS 329
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   11,   11,   12,   12,   21,   22,   12,   23,
   12,   12,   12,    7,    7,   14,   14,   15,   15,   16,
   16,   13,   13,   13,   13,    3,    3,    3,    3,    3,
    3,   18,   18,   17,   10,   10,    6,    6,    6,    6,
    9,    9,    2,    2,    2,    8,   24,   25,    8,   26,
    8,    8,    8,    8,    8,    8,    8,    8,    8,   19,
   19,   20,   20,    5,    5,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    1,    1,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    7,    6,    0,    0,   12,    0,
   10,    8,    2,    0,    1,    0,    1,    0,    1,    0,
    1,    1,    1,    1,    1,    2,    3,    3,    2,    3,
    2,    3,    1,    3,    2,    3,    2,    3,    3,    4,
    1,    2,    5,    6,    4,    5,    0,    0,    7,    0,
   10,    2,    1,    3,    3,    2,    2,    4,    2,    1,
    1,    0,    2,    3,    1,    1,    1,    1,    1,    4,
    3,    3,    3,    2,    2,    2,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    2,    1,    4,
};
static const short yydefred[] = {                         0,
    0,   21,    0,    0,    3,    0,   13,    4,   19,    0,
   22,   23,   24,   25,    0,   17,    0,    0,    0,    0,
    6,    0,   26,   29,   31,    0,    0,    0,    0,    5,
   27,   30,   28,   12,    0,    0,   33,    0,    0,    0,
    0,    8,    0,    0,   66,   67,    0,   68,    0,   47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   37,    0,    0,   53,   41,    0,    0,    0,   11,   34,
    0,   32,   59,    0,    0,    0,    0,    0,    0,    0,
    0,   56,    0,   57,   76,   75,   95,    0,   74,   96,
    0,   77,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   94,
   52,   39,   42,   38,    0,    0,   35,   15,    0,   71,
    0,    0,    0,    0,   48,    0,   54,   55,   72,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,   36,    9,   70,    0,
   98,    0,    0,    0,   58,    0,    0,   46,    0,   60,
   61,    0,    0,    0,    0,    0,   49,    0,    0,    0,
    0,   50,    0,   43,    0,   44,   51,
};
static const short yydgoto[] = {                          3,
   76,  158,   22,   63,  122,   64,  119,   65,   66,   67,
    4,    5,   36,   17,   10,    6,   37,   38,  162,  169,
   29,   71,   35,   78,  153,  175,
};
static const short yysindex[] = {                      -240,
  -32,    0,    0, -240,    0, -236,    0,    0,    0, -181,
    0,    0,    0,    0,   -7,    0, -217,  -40,   64,    6,
    0,  -14,    0,    0,    0, -218, -212,   10, -181,    0,
    0,    0,    0,    0,  -56,   -7,    0,  -21,  512,   22,
 -174,    0, -181,   32,    0,    0,  -34,    0,  658,    0,
 -163,  -57,  -38, -163, -163, -163,  658,  658, -163,  658,
    0,  -26,   86,    0,    0,  582,  549,   36,    0,    0,
  -56,    0,    0,  536,  658, -214,  117,  650,    9, -169,
   47,    0,   52,    0,    0,    0,    0,   -9,    0,    0,
  143,    0,    0,  658,  658,  658,  658,  658,  658,  658,
  658,  658,  658,  658,  658,  658,  658,  658,  658,    0,
    0,    0,    0,    0,  618,   62,    0,    0,   66,    0,
  469,  -19,  171,  650,    0,  658,    0,    0,    0,  469,
  187,  448,  128,  128,  476,  476,  301,   -9,  128,  128,
   33,   33,   93,   93,   93,    0,    0,    0,    0,  658,
    0, -167, -131,   75,    0,  469,  658,    0,  658,    0,
    0,  658,  349,  370,  398,  650,    0,  658, -138, -251,
  469,    0,  650,    0,  650,    0,    0,
};
static const short yyrindex[] = {                         1,
    0,    0,    0,    4,    0, -164,    0,    0,    0,    0,
    0,    0,    0,    0, -125,    0,    0,    0, -124, -122,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
    0,    0,    0,    0,    0, -125,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  441,    0,    0,    0,    0,    0,    0,    0,    0,
   81,    0,    0,    0,    0,   45,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0, 1244,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,    0,    0,    0,    0,    0,  296,
    0, 1188,  989, 1025, 1107, 1163,  273, 1300, 1050, 1082,
  772,  969,  719,  887,  913,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,    0,    0,    0,    0,
    0,    0,    0,    0, -128,    0,    0,    0,    0,  339,
 -123,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
 1350,  -18,    0, 1385,    0,  -25,    0,  -22,   82,    0,
    0,  159,  156,  131,  149,    0,   -2,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1575
static const short yytable[] = {                         20,
    2,   82,   97,    1,   97,   74,   97,   97,   95,   40,
   97,   97,   97,   97,   97,    1,   97,  173,   21,   42,
   84,  149,   43,  110,  150,    2,    7,  109,   97,   97,
    9,   97,  107,  105,   16,  106,   68,  108,   31,   32,
   72,   18,  157,  113,   30,  118,   28,   33,   65,   97,
  104,   65,  103,   97,   97,  125,   75,   97,   97,   97,
   97,   97,   97,   97,  116,  110,   39,   64,   34,  109,
   64,   92,   93,   94,  107,   97,   97,   69,   97,  108,
   69,   69,   69,   11,   70,   69,   69,   69,   69,   69,
   73,   69,  113,   97,  117,   79,   12,   13,   14,   75,
   18,  152,  126,   69,   69,  127,   69,  110,   26,   97,
  128,  109,  102,   18,   18,   18,  107,  105,  110,  106,
  147,  108,  109,  102,  148,  110,  157,  107,  105,  159,
  106,  172,  108,   16,  104,   18,  103,   69,   10,   14,
   97,   62,    7,  170,  111,  104,   63,  103,  115,  110,
  176,  174,  177,  109,  102,    7,    7,    7,  107,  105,
  110,  106,    8,  108,  109,   15,   41,   27,   69,  107,
  105,    0,  106,    0,  108,  110,  104,    0,  103,  109,
  102,    0,    0,  129,  107,  105,    0,  106,    0,  108,
    0,    0,    0,    0,    0,    0,    0,    0,  101,   81,
    0,    0,  104,  110,  103,    0,    0,  109,  102,  101,
    0,    0,  107,  105,    0,  106,    0,  108,   83,  110,
    0,    0,    0,  109,  102,    0,    0,    0,  107,  105,
  104,  106,  103,  108,    0,    0,    0,   97,    0,   97,
  101,    0,   97,   97,   97,  155,  104,   19,  103,    0,
   97,   97,   97,   97,   97,   97,   97,   97,    0,   92,
   93,   94,    0,  151,    0,   20,  101,   20,   20,    0,
   20,   96,   97,   98,   99,  100,    0,    0,   20,   20,
   20,   20,   20,   20,   97,    0,   97,    0,   97,   97,
   97,   97,    0,    0,  101,    0,    0,   97,   97,   97,
   97,   97,    0,    0,    0,    0,    0,    0,    0,    0,
  101,    0,   69,   92,   69,    0,   92,   69,   69,   69,
   23,   24,   25,    0,    0,   69,   69,   69,   69,   69,
    9,   92,    0,  110,    0,    0,   73,  109,  102,   73,
    0,    0,  107,  105,    0,  106,    0,  108,  160,  161,
    0,    0,    0,    0,   73,   96,   97,   98,   99,  100,
  104,    0,  103,    0,    0,   92,   96,   97,   98,   99,
  100,    0,    0,    0,    0,    0,   45,    0,   45,    0,
   45,  110,    0,   45,  124,  109,  102,    0,   73,    0,
  107,  105,    0,  106,    0,  108,   92,   96,   97,   98,
   99,  100,  110,    0,    0,    0,  109,  102,  104,    0,
  103,  107,  105,    0,  106,    0,  108,    0,    0,    0,
    0,    0,    0,   96,   97,   98,   99,  100,  167,  104,
  110,  103,    0,    0,  109,  102,    0,    0,    0,  107,
  105,    0,  106,    0,  108,    0,    0,    0,    0,    0,
    0,   96,   97,   98,   99,  100,    0,  104,    0,  103,
    0,   45,    0,   45,   45,    0,    0,   96,   97,   98,
   99,  100,  101,   69,    0,    0,    0,   69,   69,    0,
  110,    0,   69,   69,  109,   69,    0,   69,    0,  107,
  105,    0,  106,  101,  108,    0,    0,    0,    0,   69,
   69,  110,   69,    0,    0,  109,  102,  104,  110,  103,
  107,  105,  109,  106,    0,  108,    0,  107,  105,    0,
  106,  101,  108,    0,    0,    0,    0,    0,  104,    0,
  103,    0,    0,    0,    0,  104,    0,  103,    0,    0,
   92,    0,   92,    0,    0,   92,   92,   92,    0,   56,
    0,   60,    0,   59,    0,    0,   58,    0,    0,    0,
    0,    0,    0,   73,   69,   73,    0,    0,   73,   73,
   73,    0,    0,   56,    0,   60,  120,   59,    0,    0,
   58,   96,   97,   98,   99,  100,   56,    0,   60,    0,
   59,    0,  101,   58,   45,   45,   45,   45,   45,   45,
   45,    0,    0,    0,    0,    0,    0,    0,   45,   45,
    0,    0,    0,    0,   45,   45,  166,    0,    0,   56,
    0,   60,    0,   59,   45,   45,   58,    0,    0,   96,
   97,   98,   99,  100,   39,    0,   61,   57,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   96,   97,   98,   99,  100,   56,    0,   60,    0,   59,
    0,   57,   58,    0,    0,    0,    0,    0,    0,    0,
  168,   39,    0,  114,   57,    0,    0,    0,   96,   97,
   98,   99,  100,    0,    0,    0,    0,   56,    0,   60,
    0,   59,    0,    0,   58,   56,    0,   60,    0,   59,
    0,    0,   58,    0,   39,    0,  112,   57,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   69,   69,   69,   69,   69,    0,    0,    0,   97,
   98,   99,  100,    0,    0,    0,    0,    0,    0,    0,
   39,    0,  146,   57,    0,    0,    0,    0,    0,   96,
   97,   98,   99,  100,    0,   80,   80,   97,   98,   80,
   80,   80,   80,   80,    0,   80,    0,   44,   45,   46,
   47,   48,   39,   49,    0,   57,   11,   80,   80,    0,
   80,   50,   51,   57,    0,    0,    0,   52,   53,   12,
   13,   14,   45,   46,   47,   48,    0,   54,   55,    0,
    0,    0,    0,    0,   44,   45,   46,   47,   48,   83,
   49,   80,   83,   11,   83,   83,   83,    0,   50,   51,
    0,   54,   55,    0,   52,   53,   12,   13,   14,    0,
   83,   83,    0,   83,   54,   55,    0,   44,   45,   46,
   47,   48,   80,   49,    0,    0,    0,    0,    0,    0,
    0,   50,   51,    0,    0,    0,    0,   52,   53,    0,
    0,    0,    0,    0,   83,    0,    0,   54,   55,    0,
    0,    0,    0,   44,   45,   46,   47,   48,    0,   49,
    0,    0,    0,    0,    0,    0,    0,   50,   51,    0,
    0,    0,    0,   52,   53,   83,    0,    0,    0,    0,
    0,    0,    0,   54,   55,   44,   45,   46,   47,   48,
    0,   49,    0,    0,   45,   46,   47,   48,    0,   50,
   51,    0,    0,   81,   81,   52,   53,   81,   81,   81,
   81,   81,    0,   81,    0,   54,   55,    0,    0,    0,
    0,    0,    0,   54,   55,   81,   81,    0,   81,   82,
   82,    0,    0,   82,   82,   82,   82,   82,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   82,   82,    0,   82,    0,    0,    0,    0,   81,
    0,    0,    0,    0,    0,    0,   80,    0,   80,    0,
    0,   80,   80,   80,    0,    0,    0,    0,    0,   80,
   80,   80,   80,   80,    0,   82,   84,    0,    0,   84,
   81,   84,   84,   84,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   89,   84,   84,   89,
   84,    0,   89,    0,    0,    0,   82,    0,    0,   83,
    0,   83,    0,    0,   83,   83,   83,   89,   89,    0,
   89,    0,   83,   83,   83,   83,   83,    0,    0,    0,
    0,   84,   90,    0,    0,   90,    0,    0,   90,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   89,    0,   90,   90,    0,   90,   85,    0,    0,
   85,    0,   84,   85,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   85,   85,
    0,   85,   89,    0,    0,    0,    0,   90,    0,   86,
    0,    0,   86,    0,    0,   86,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   86,   86,   85,   86,   87,    0,    0,   87,   90,    0,
   87,    0,    0,    0,   81,    0,   81,    0,    0,   81,
   81,   81,    0,    0,    0,   87,    0,   81,   81,   81,
   81,   81,    0,   85,   86,    0,    0,    0,    0,    0,
   82,    0,   82,    0,    0,   82,   82,   82,    0,    0,
    0,    0,    0,   82,   82,   82,   82,   82,    0,   87,
   88,    0,    0,   88,    0,   86,   88,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   88,    0,    0,    0,   79,    0,    0,   79,    0,
   87,   79,    0,    0,    0,    0,   84,    0,   84,    0,
    0,   84,   84,   84,    0,    0,   79,    0,    0,   84,
   84,   84,   84,   84,    0,   88,   89,    0,   89,    0,
    0,   89,   89,   89,    0,    0,    0,    0,    0,   89,
   89,   89,   89,   89,    0,    0,    0,    0,    0,    0,
   79,   93,    0,    0,   93,    0,   88,   93,    0,    0,
    0,    0,   90,    0,   90,    0,    0,   90,   90,   90,
    0,    0,   93,    0,    0,   90,   90,   90,   90,   90,
    0,   79,    0,    0,    0,    0,    0,   85,    0,   85,
    0,    0,   85,   85,   85,    0,    0,    0,    0,    0,
   85,   85,   85,   85,   85,    0,   93,   91,    0,    0,
   91,    0,    0,   91,    0,    0,    0,    0,    0,   86,
    0,   86,    0,    0,   86,   86,   86,    0,   91,    0,
    0,    0,   86,   86,   86,   86,   86,   93,    0,    0,
    0,    0,    0,    0,   87,    0,   87,    0,    0,   87,
   87,   87,    0,    0,    0,    0,    0,   87,   62,    0,
   87,   87,   91,    0,    0,    0,    0,    0,    0,    0,
   80,    0,    0,   85,   86,   87,    0,    0,   90,    0,
    0,    0,    0,    0,    0,   62,   62,    0,    0,    0,
    0,    0,    0,   91,    0,    0,    0,   62,    0,    0,
   88,    0,   88,   77,    0,   88,   88,   88,    0,    0,
    0,   88,   89,   88,   91,    0,   88,   88,    0,    0,
    0,    0,    0,    0,    0,   79,    0,   79,  121,  123,
   79,   79,   79,    0,   62,    0,    0,    0,   79,    0,
    0,    0,    0,   62,    0,    0,    0,    0,  130,  131,
  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,  145,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  154,   93,    0,   93,    0,   62,   93,   93,   93,    0,
    0,    0,   62,    0,   62,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  156,    0,    0,    0,    0,    0,
    0,  163,    0,  164,    0,    0,  165,    0,    0,    0,
    0,    0,  171,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   91,    0,   91,
    0,    0,   91,   91,   91,
};
static const short yycheck[] = {                         40,
    0,   59,   33,    0,   35,   40,   37,   38,   35,   35,
   41,   42,   43,   44,   45,  256,   47,  269,   59,   41,
   59,   41,   44,   33,   44,  266,   59,   37,   59,   60,
  267,   62,   42,   43,   42,   45,   39,   47,  257,  258,
   43,  259,  294,   66,   59,   71,   41,  260,   41,   33,
   60,   44,   62,   37,   38,   78,   91,   41,   42,   43,
   44,   45,   93,   47,   67,   33,  123,   41,   59,   37,
   44,  286,  287,  288,   42,   59,   60,   33,   62,   47,
   59,   37,   38,  265,  259,   41,   42,   43,   44,   45,
   59,   47,  115,  124,   59,  259,  278,  279,  280,   91,
  265,  124,  272,   59,   60,   59,   62,   33,   45,   93,
   59,   37,   38,  278,  279,  280,   42,   43,   33,   45,
   59,   47,   37,   38,   59,   33,  294,   42,   43,  261,
   45,  270,   47,  259,   60,  260,   62,   93,  123,   59,
  124,  270,  265,  166,   59,   60,  270,   62,   67,   33,
  173,  170,  175,   37,   38,  278,  279,  280,   42,   43,
   33,   45,    4,   47,   37,   10,   36,   19,  124,   42,
   43,   -1,   45,   -1,   47,   33,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  257,
   -1,   -1,   60,   33,   62,   -1,   -1,   37,   38,  124,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,  257,   33,
   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
   60,   45,   62,   47,   -1,   -1,   -1,  268,   -1,  270,
  124,   -1,  273,  274,  275,   59,   60,  288,   62,   -1,
  281,  282,  283,  284,  285,  286,  287,  288,   -1,  286,
  287,  288,   -1,   93,   -1,  265,  124,  267,  265,   -1,
  267,  281,  282,  283,  284,  285,   -1,   -1,  278,  279,
  280,  278,  279,  280,  268,   -1,  270,   -1,  272,  273,
  274,  275,   -1,   -1,  124,   -1,   -1,  281,  282,  283,
  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,  268,   41,  270,   -1,   44,  273,  274,  275,
  257,  258,  259,   -1,   -1,  281,  282,  283,  284,  285,
  267,   59,   -1,   33,   -1,   -1,   41,   37,   38,   44,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,  274,  275,
   -1,   -1,   -1,   -1,   59,  281,  282,  283,  284,  285,
   60,   -1,   62,   -1,   -1,   93,  281,  282,  283,  284,
  285,   -1,   -1,   -1,   -1,   -1,   38,   -1,   40,   -1,
   42,   33,   -1,   45,  268,   37,   38,   -1,   93,   -1,
   42,   43,   -1,   45,   -1,   47,  124,  281,  282,  283,
  284,  285,   33,   -1,   -1,   -1,   37,   38,   60,   -1,
   62,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,  285,   59,   60,
   33,   62,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,  285,   -1,   60,   -1,   62,
   -1,  123,   -1,  125,  126,   -1,   -1,  281,  282,  283,
  284,  285,  124,   33,   -1,   -1,   -1,   37,   38,   -1,
   33,   -1,   42,   43,   37,   45,   -1,   47,   -1,   42,
   43,   -1,   45,  124,   47,   -1,   -1,   -1,   -1,   59,
   60,   33,   62,   -1,   -1,   37,   38,   60,   33,   62,
   42,   43,   37,   45,   -1,   47,   -1,   42,   43,   -1,
   45,  124,   47,   -1,   -1,   -1,   -1,   -1,   60,   -1,
   62,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   38,
   -1,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,
   -1,   -1,   -1,  268,  124,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,   38,   -1,   40,   41,   42,   -1,   -1,
   45,  281,  282,  283,  284,  285,   38,   -1,   40,   -1,
   42,   -1,  124,   45,  256,  257,  258,  259,  260,  261,
  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
   -1,   -1,   -1,   -1,  276,  277,  268,   -1,   -1,   38,
   -1,   40,   -1,   42,  286,  287,   45,   -1,   -1,  281,
  282,  283,  284,  285,  123,   -1,  125,  126,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,  285,   38,   -1,   40,   -1,   42,
   -1,  126,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  273,  123,   -1,  125,  126,   -1,   -1,   -1,  281,  282,
  283,  284,  285,   -1,   -1,   -1,   -1,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   38,   -1,   40,   -1,   42,
   -1,   -1,   45,   -1,  123,   -1,  125,  126,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,  285,   -1,   -1,   -1,  282,
  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,  126,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,  285,   -1,   37,   38,  282,  283,   41,
   42,   43,   44,   45,   -1,   47,   -1,  256,  257,  258,
  259,  260,  123,  262,   -1,  126,  265,   59,   60,   -1,
   62,  270,  271,  126,   -1,   -1,   -1,  276,  277,  278,
  279,  280,  257,  258,  259,  260,   -1,  286,  287,   -1,
   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,   38,
  262,   93,   41,  265,   43,   44,   45,   -1,  270,  271,
   -1,  286,  287,   -1,  276,  277,  278,  279,  280,   -1,
   59,   60,   -1,   62,  286,  287,   -1,  256,  257,  258,
  259,  260,  124,  262,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,  286,  287,   -1,
   -1,   -1,   -1,  256,  257,  258,  259,  260,   -1,  262,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,   -1,
   -1,   -1,   -1,  276,  277,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  256,  257,  258,  259,  260,
   -1,  262,   -1,   -1,  257,  258,  259,  260,   -1,  270,
  271,   -1,   -1,   37,   38,  276,  277,   41,   42,   43,
   44,   45,   -1,   47,   -1,  286,  287,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,   59,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,
   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,  285,   -1,   93,   38,   -1,   -1,   41,
  124,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   38,   59,   60,   41,
   62,   -1,   44,   -1,   -1,   -1,  124,   -1,   -1,  268,
   -1,  270,   -1,   -1,  273,  274,  275,   59,   60,   -1,
   62,   -1,  281,  282,  283,  284,  285,   -1,   -1,   -1,
   -1,   93,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   59,   60,   -1,   62,   38,   -1,   -1,
   41,   -1,  124,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,  124,   -1,   -1,   -1,   -1,   93,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   93,   62,   38,   -1,   -1,   41,  124,   -1,
   44,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,
  274,  275,   -1,   -1,   -1,   59,   -1,  281,  282,  283,
  284,  285,   -1,  124,   93,   -1,   -1,   -1,   -1,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,  285,   -1,   93,
   38,   -1,   -1,   41,   -1,  124,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
  124,   44,   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,
   -1,  273,  274,  275,   -1,   -1,   59,   -1,   -1,  281,
  282,  283,  284,  285,   -1,   93,  268,   -1,  270,   -1,
   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   38,   -1,   -1,   41,   -1,  124,   44,   -1,   -1,
   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,
   -1,   -1,   59,   -1,   -1,  281,  282,  283,  284,  285,
   -1,  124,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,  285,   -1,   93,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,  268,
   -1,  270,   -1,   -1,  273,  274,  275,   -1,   59,   -1,
   -1,   -1,  281,  282,  283,  284,  285,  124,   -1,   -1,
   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,  281,   39,   -1,
  284,  285,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   51,   -1,   -1,   54,   55,   56,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   66,   67,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   78,   -1,   -1,
  268,   -1,  270,   49,   -1,  273,  274,  275,   -1,   -1,
   -1,   57,   58,  281,   60,   -1,  284,  285,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,   74,   75,
  273,  274,  275,   -1,  115,   -1,   -1,   -1,  281,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   94,   95,
   96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,  109,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  126,  268,   -1,  270,   -1,  166,  273,  274,  275,   -1,
   -1,   -1,  173,   -1,  175,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  150,   -1,   -1,   -1,   -1,   -1,
   -1,  157,   -1,  159,   -1,   -1,  162,   -1,   -1,   -1,
   -1,   -1,  168,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 329
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
"IN","STEP","UPTO","DOWNTO","BREAK","CONTINUE","INTEGER","STRING","NUMBER",
"SHIFT","GE","LE","EQ","NE","INC","DEC","ATRIB","ADDR","POINTER","IFX","LIST",
"VECTOR","ELIF","CALL","CALL2","NEG","FACT","AND","OR","PROG","ADD","SUBT",
"MUL","DIV","LT","GT","MOD","PARAMS","PARS2","PARS","PINTR","INTR","DECL",
"DECLS","INIT","NIL","PNTR","EXPS","EXP","MALL","BODY","JZ","ETIQ","LABEL",
"JNZ","JMP","INSTRS","UMINUS",
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
"elifs : ELIF expressao THEN instrucao elifs",
"elifs : ELIF expressao THEN instrucao ELSE instrucao",
"elifs : ELIF expressao THEN instrucao",
"instrucao : IF expressao THEN instrucao elifs",
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
"expressao : expressao SHIFT expressao",
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
#line 259 "factorial.y"
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

char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strdup(buf);
}


char *clbl(int n) {
  static char buf[20];
  sprintf(buf, "_c%d", n);
  return strdup(buf);
}

char **yynames =
#if YYDEBUG > 0
     (char**)yyname;
#else
     0;
#endif
#line 775 "y.tab.c"

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
#line 59 "factorial.y"
	{Node * n = uniNode(PROG, yystack.l_mark[0].n); printNode(n, 0, yynames);}
break;
case 3:
#line 63 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 4:
#line 64 "factorial.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 5:
#line 67 "factorial.y"
	{ IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info, yystack.l_mark[-2].s, 0); declare(yystack.l_mark[-2].s, yystack.l_mark[-1].n); /* alterar o declare para não fazer IDnew e usar o que vem antes dele na declaracao */
                                                              yyval.n=binNode(INIT, strNode(IDENTIF, yystack.l_mark[-2].s), yystack.l_mark[-1].n);
                                                              yyval.n->info = yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info; 
                                                              if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != 4) {
                                                                if(yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info != yystack.l_mark[-1].n->info) yyerror("Atribuição entre tipos diferentes.");}}
break;
case 6:
#line 73 "factorial.y"
	{ yyval.n=uniNode(DECL, strNode(IDENTIF, yystack.l_mark[-1].s)); IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-1].s, 0);}
break;
case 7:
#line 75 "factorial.y"
	{IDnew(yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+yystack.l_mark[-2].n->info+32, yystack.l_mark[-1].s, 0); IDpush(); pos = 8; }
break;
case 8:
#line 76 "factorial.y"
	{IDreplace(yystack.l_mark[-8].n->info+yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+32,yystack.l_mark[-4].s, yystack.l_mark[-1].n->info); 
                                               if((yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info) != 0) {IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info, yystack.l_mark[-4].s, pos = -4);} else pos = 0;}
break;
case 9:
#line 78 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-7].s), binNode(BODY, yystack.l_mark[-4].n, yystack.l_mark[-1].n)); IDpop(); function(yystack.l_mark[-7].s, -pos, yystack.l_mark[-1].n); pos = 0; }
break;
case 10:
#line 80 "factorial.y"
	{IDnew(yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info+32, yystack.l_mark[-2].s, 0); IDpush();
                                                  if((yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info) != 0) {IDnew((yystack.l_mark[-4].n->info+yystack.l_mark[-3].n->info), yystack.l_mark[-2].s,pos = -4);}}
break;
case 11:
#line 82 "factorial.y"
	{ yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-5].s), yystack.l_mark[-1].n); IDpop(); function(yystack.l_mark[-5].s, -pos, yystack.l_mark[-1].n); pos = 0;}
break;
case 12:
#line 84 "factorial.y"
	{yyval.n=binNode(DECL, strNode(IDENTIF, yystack.l_mark[-3].s), nilNode(NIL)); IDnew(yystack.l_mark[-7].n->info+yystack.l_mark[-6].n->info+yystack.l_mark[-5].n->info+yystack.l_mark[-4].n->info+32, yystack.l_mark[-3].s, 0); function(yystack.l_mark[-3].s, -pos, 0); pos = 0;}
break;
case 13:
#line 85 "factorial.y"
	{yyerrok; }
break;
case 14:
#line 88 "factorial.y"
	{ yyval.n = nilNode(NIL); }
break;
case 15:
#line 89 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 16:
#line 92 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0; }
break;
case 17:
#line 93 "factorial.y"
	{ yyval.n= uniNode(PNTR, 0); yyval.n->info = 4; }
break;
case 18:
#line 96 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0;}
break;
case 19:
#line 97 "factorial.y"
	{ yyval.n= uniNode(CONST, 0); yyval.n->info = 8; }
break;
case 20:
#line 100 "factorial.y"
	{ yyval.n= nilNode(NIL); yyval.n->info = 0;}
break;
case 21:
#line 101 "factorial.y"
	{ yyval.n= uniNode(VOID, 0); yyval.n->info = 16; }
break;
case 22:
#line 104 "factorial.y"
	{ yyval.n = uniNode(VOID, 0); yyval.n->info = 0; }
break;
case 23:
#line 105 "factorial.y"
	{ yyval.n = uniNode(INTEGER, 0); yyval.n->info = 1; }
break;
case 24:
#line 106 "factorial.y"
	{ yyval.n = uniNode(STRING, 0); yyval.n->info = 2; }
break;
case 25:
#line 107 "factorial.y"
	{ yyval.n = uniNode(NUMBER, 0); yyval.n->info = 3; }
break;
case 26:
#line 110 "factorial.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 27:
#line 111 "factorial.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[0].i); yyval.n->info = 1;}
break;
case 28:
#line 112 "factorial.y"
	{ yyval.n = strNode(STRN, yystack.l_mark[0].s); yyval.n->info = yystack.l_mark[-1].n->info +2;}
break;
case 29:
#line 113 "factorial.y"
	{ yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 30:
#line 114 "factorial.y"
	{ yyval.n = realNode(NUM, -yystack.l_mark[0].d); yyval.n->info = 3;}
break;
case 31:
#line 115 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0)+4;}
break;
case 32:
#line 119 "factorial.y"
	{ yyval.n = binNode(PARAMS, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[0].n->info;}
break;
case 33:
#line 120 "factorial.y"
	{ yyval.n = uniNode(PARAMS, yystack.l_mark[0].n);  yyval.n->info = yystack.l_mark[0].n->info; /* tentar alterar o IDnew para fazer as variaveis dos parametros das funcoes (positivos) compact*/}
break;
case 34:
#line 123 "factorial.y"
	{ yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); if (pos >= 8) { yyval.n->user = pos; IDnew(yystack.l_mark[-2].n->info+yystack.l_mark[-1].n->info, yystack.l_mark[0].s, pos); pos += 4; } else { pos -= 4; yyval.n->user = pos; IDnew(yystack.l_mark[-2].n->info+yystack.l_mark[-1].n->info, yystack.l_mark[0].s, pos); } yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info;}
break;
case 35:
#line 126 "factorial.y"
	{ yyval.n = yystack.l_mark[-1].n; /* tentar alterar o IDnew para fazer as variaveis locais das funcoes (negativos) compact*/}
break;
case 36:
#line 127 "factorial.y"
	{ yyval.n = binNode(PARS2, yystack.l_mark[-2].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info; }
break;
case 37:
#line 130 "factorial.y"
	{yyval.n = nilNode(NIL);}
break;
case 38:
#line 131 "factorial.y"
	{yyval.n = uniNode(PARS, yystack.l_mark[-1].n); }
break;
case 39:
#line 132 "factorial.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 40:
#line 133 "factorial.y"
	{yyval.n = binNode(PINTR, yystack.l_mark[-2].n , yystack.l_mark[-1].n);}
break;
case 41:
#line 136 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 42:
#line 137 "factorial.y"
	{yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 43:
#line 141 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                        yyval.n = seqNode(LIST, 6,
                                                                        binNode(JZ,yystack.l_mark[-3].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[-1].n, /* instr */
                                                                        strNode(JMP, mklbl(lbl2)),
                                                                        strNode(LABEL, mklbl(lbl1)),
                                                                        yystack.l_mark[0].n, /* else */
                                                                        strNode(LABEL, mklbl(lbl2)));
                                                                       }
break;
case 44:
#line 151 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                        yyval.n = seqNode(LIST, 6,
                                                                        binNode(JZ,yystack.l_mark[-4].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[-2].n, /* instr */
                                                                        strNode(JMP, mklbl(lbl2)),
                                                                        strNode(LABEL, mklbl(lbl1)),
                                                                        yystack.l_mark[0].n, /* else */
                                                                        strNode(LABEL, mklbl(lbl2)));
                                                                      }
break;
case 45:
#line 161 "factorial.y"
	{ int lbl1 = ++lbl;
                                                                        yyval.n = seqNode(LIST, 3,
                                                                        binNode(JZ,yystack.l_mark[-2].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[0].n, /* instr */
                                                                        strNode(LABEL, mklbl(lbl1)));
                                                                       }
break;
case 46:
#line 171 "factorial.y"
	{ int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                        yyval.n = seqNode(LIST, 6,
                                                                        binNode(JZ,yystack.l_mark[-3].n, strNode(ETIQ, mklbl(lbl1))),
                                                                        yystack.l_mark[-1].n, /* instr */
                                                                        strNode(JMP, mklbl(lbl2)),
                                                                        strNode(LABEL, mklbl(lbl1)),
                                                                        yystack.l_mark[0].n, /* elifs */
                                                                        strNode(LABEL, mklbl(lbl2)));
                                                                       }
break;
case 47:
#line 183 "factorial.y"
	{ nciclo++; lbl1 = ++cclbl; lbl2 = ++cclbl;}
break;
case 48:
#line 183 "factorial.y"
	{ nciclo--; }
break;
case 49:
#line 183 "factorial.y"
	{ yyval.n = seqNode(LIST, 4,
                                                                                strNode(LABEL, clbl(lbl1)),
                                                                                yystack.l_mark[-4].n, /* instr */
                                                                                binNode(JNZ,yystack.l_mark[-1].n, strNode(ETIQ, clbl(lbl1))),
                                                                                strNode(LABEL,clbl(lbl2)));
                                                                                lbl1-=2; lbl2-=2; /* causam conflitos entre labels em certas situaçoes*/
                                                                              }
break;
case 50:
#line 191 "factorial.y"
	{ nciclo++; }
break;
case 51:
#line 191 "factorial.y"
	{ nciclo--; }
break;
case 52:
#line 193 "factorial.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 53:
#line 194 "factorial.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 54:
#line 195 "factorial.y"
	{ if (yystack.l_mark[-1].i == 0 || yystack.l_mark[-1].i > nciclo) yyerror("Break inválido: Fora de um ciclo"); {yyval.n = strNode(JMP, clbl(lbl2 - 2*(yystack.l_mark[-1].i - 1)));}}
break;
case 55:
#line 196 "factorial.y"
	{yyval.n = strNode(JMP, clbl(lbl1 - 2*(yystack.l_mark[-1].i -1)));}
break;
case 56:
#line 197 "factorial.y"
	{ if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); yyval.n = strNode(JMP, clbl(lbl2));}
break;
case 57:
#line 198 "factorial.y"
	{yyval.n = strNode(JMP, clbl(lbl1));}
break;
case 58:
#line 199 "factorial.y"
	{yyval.n = binNode(MALL, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 59:
#line 200 "factorial.y"
	{ yyerrok; }
break;
case 60:
#line 203 "factorial.y"
	{ yyval.n = uniNode(UPTO, 0); }
break;
case 61:
#line 204 "factorial.y"
	{ yyval.n = uniNode(DOWNTO, 0);}
break;
case 62:
#line 207 "factorial.y"
	{ yyval.n = nilNode(NIL);}
break;
case 63:
#line 208 "factorial.y"
	{ yyval.n = uniNode(STEP, yystack.l_mark[0].n); }
break;
case 64:
#line 211 "factorial.y"
	{ yyval.n = binNode(EXPS, yystack.l_mark[0].n ,yystack.l_mark[-2].n);}
break;
case 65:
#line 212 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 66:
#line 215 "factorial.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 67:
#line 216 "factorial.y"
	{ yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = 3; }
break;
case 68:
#line 217 "factorial.y"
	{ yyval.n = strNode(STRN, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 69:
#line 218 "factorial.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 70:
#line 219 "factorial.y"
	{ int n; n = IDfind(yystack.l_mark[-3].s, 0) & (0x7); if(n != -1 && n == 4) {yyval.n = binNode(CALL2, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = n;} else {yyval.n = binNode(CALL2, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = IDsearch(yystack.l_mark[-3].s, 0, IDlevel(), 0) & (0x7);}}
break;
case 71:
#line 220 "factorial.y"
	{ int n; n = IDfind(yystack.l_mark[-2].s, 0) & (0x7); if(n != -1 && n == 4) {yyval.n = uniNode(CALL, strNode(IDENTIF, yystack.l_mark[-2].s)); yyval.n->info = n;} else {yyval.n = uniNode(CALL, strNode(IDENTIF, yystack.l_mark[-2].s)); yyval.n->info = IDsearch(yystack.l_mark[-2].s, 0, IDlevel(), 0) & (0x7);}}
break;
case 72:
#line 221 "factorial.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 73:
#line 222 "factorial.y"
	{ /*if($1->info != 4){if ($1->info != $3->info) yyerror("Atribuição entre tipos diferentes.");} */ yyval.n = binNode(ATRIB, yystack.l_mark[0].n, yystack.l_mark[-2].n);  yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 74:
#line 223 "factorial.y"
	{ if(yystack.l_mark[0].n->info == 0 || yystack.l_mark[0].n->info == 2) yyerror("Simétrico : Tipo inválido"); yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 75:
#line 224 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Decremento : Tipo inválido"); yyval.n = uniNode(DEC, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 76:
#line 225 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Incremento : Tipo inválido"); yyval.n = uniNode(INC, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 77:
#line 226 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Incremento : Tipo inválido"); yyval.n = uniNode(INC, yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 78:
#line 227 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Decremento : Tipo inválido"); yyval.n = uniNode(DEC, yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 79:
#line 228 "factorial.y"
	{ yyval.n = binNode(SHIFT, yystack.l_mark[-2].n, yystack.l_mark[0].n); /*$$->info = oper($1, $3)<-;*/ }
break;
case 80:
#line 229 "factorial.y"
	{ yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 230 "factorial.y"
	{ yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 231 "factorial.y"
	{ yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 232 "factorial.y"
	{ yyval.n = binNode(ADD, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 233 "factorial.y"
	{ yyval.n = binNode(SUBT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = oper(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 234 "factorial.y"
	{ yyval.n = binNode(GT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 235 "factorial.y"
	{ yyval.n = binNode(LT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 87:
#line 236 "factorial.y"
	{ yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 88:
#line 237 "factorial.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 89:
#line 238 "factorial.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 90:
#line 239 "factorial.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = comp(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 91:
#line 240 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 1 || yystack.l_mark[0].n->info != 1) yyerror("Junção Lógica : Tipo inválido"); yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 92:
#line 241 "factorial.y"
	{ if(yystack.l_mark[-2].n->info != 1 || yystack.l_mark[0].n->info != 1) yyerror("Alternativa Lógica : Tipo inválido"); yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 93:
#line 242 "factorial.y"
	{ if(yystack.l_mark[0].n->info != 1) yyerror("Negação Lógica : Tipo inválido"); yyval.n = uniNode(NEG, yystack.l_mark[0].n); yyval.n->info = 1;}
break;
case 94:
#line 243 "factorial.y"
	{ if(yystack.l_mark[-1].n->info != 1) yyerror("Factorial : Tipo inválido"); yyval.n = uniNode(FACT, yystack.l_mark[-1].n); yyval.n->info = 1;}
break;
case 95:
#line 244 "factorial.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 96:
#line 245 "factorial.y"
	{ yyval.n = uniNode(POINTER, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 97:
#line 248 "factorial.y"
	{long pos; yyval.n = strNode(IDENTIF, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, &pos); yyval.n->user = pos;}
break;
case 98:
#line 250 "factorial.y"
	{long pos; int x = IDfind(yystack.l_mark[-3].s, &pos); yyval.n = binNode(VECTOR, strNode(IDENTIF, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->user = pos; yyval.n->value.sub.n[0]->user = pos; 
                                                        if (((x & 0x4) == 4)) 
                                                              {yyval.n->info = x - 4; yyval.n->value.sub.n[0]->info = yyval.n->info;}
                                                        else if (((x & 0x7) == 2))
                                                              {yyval.n->info = 1; yyval.n->value.sub.n[0]->info = 1;}
                                                        else yyerror("Ponteiro: Tipo inválido.");
                                                        /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
break;
#line 1416 "y.tab.c"
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
