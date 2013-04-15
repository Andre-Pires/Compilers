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

char var[100];
int p, tipo, nciclo;
#line 14 "factorial.y"
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

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
#define UMINUS 291
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   14,   14,   13,   13,   13,    2,    2,    3,
    3,    4,    4,    1,    1,    1,    1,    6,    6,    6,
    6,    6,    6,   16,    6,    6,    9,    9,   17,    8,
    7,   10,   10,   15,   15,   15,   15,   18,   18,   19,
   19,   20,   21,   19,   24,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   22,   22,   23,   23,   12,   12,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    5,    5,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    7,    6,    2,    0,    1,    0,
    1,    0,    1,    1,    1,    1,    1,    2,    3,    2,
    2,    4,    3,    0,    4,    2,    3,    0,    0,    3,
    3,    2,    3,    2,    3,    3,    4,    1,    2,    4,
    6,    0,    0,    7,    0,   10,    2,    1,    3,    3,
    2,    2,    4,    2,    1,    1,    0,    2,    3,    1,
    1,    1,    1,    1,    4,    3,    3,    3,    2,    2,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    1,    4,
};
static const short yydefred[] = {                         0,
    0,   13,    0,    0,    3,    0,    7,   11,    0,    4,
   14,   15,   16,   17,    0,    9,    0,    0,    0,    0,
    6,    0,   18,   20,   21,    0,    0,    0,    0,    5,
   19,    0,    0,    0,   28,    0,   25,   22,    0,    0,
    0,   61,   62,    0,   63,    0,   42,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,    0,    0,
    0,    0,   48,    0,   38,   31,    0,   54,    0,    0,
    0,    0,    0,    0,    0,    0,   51,    0,   52,   70,
   71,   89,    0,   69,   90,    0,   72,   73,    0,    0,
   32,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   88,   47,   36,
   39,   27,   66,    0,    0,    0,    0,   43,    0,   49,
   50,   67,    0,    0,   33,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   65,
    0,   92,    0,    0,    0,   53,    0,    0,    0,   55,
   56,    0,   41,    0,    0,   44,    0,    0,    0,   45,
    0,   46,
};
static const short yydgoto[] = {                          3,
   34,   17,    9,    4,   71,   22,   35,   28,   40,   61,
   62,  115,    5,    6,   63,   32,   29,   64,   65,   73,
  144,  152,  158,  161,
};
static const short yysindex[] = {                      -231,
  -37,    0,    0, -236,    0, -231,    0,    0, -239,    0,
    0,    0,    0,    0,   -5,    0, -214,  -40,  -66,    8,
    0,   -3,    0,    0,    0, -203,    0,   28, -239,    0,
    0,  -51,  -51,   -5,    0,  269,    0,    0, -186,   37,
   26,    0,    0,  -24,    0,   94,    0, -168,  -57,  -53,
 -168, -168, -168,   94,   94, -168,   94,    0,  -26,   34,
  333,   86,    0,  519,    0,    0, -239,    0,  468,   94,
 -160,  117,  623,    5, -177,   41,    0,   42,    0,    0,
    0,    0,   -9,    0,    0,  143,    0,    0,   94,   94,
    0,    0,   44,  591,   94,   94,   94,   94,   94,   94,
   94,   94,   94,   94,   94,   94,   94,    0,    0,    0,
    0,    0,    0,  439,  -21,  169,  623,    0,   94,    0,
    0,    0,  439,  344,    0,    0,  128,  128,  460,  460,
  300,   -9,  128,  128,   33,   33,   73,   73,   73,    0,
   94,    0, -158, -152,   75,    0,  439,  623,   94,    0,
    0,   94,    0,  372,  400,    0,   94, -156,  439,    0,
  623,    0,
};
static const short yyrindex[] = {                         1,
    0,    0,    0, -181,    0,    4,    0,    0,    0,    0,
    0,    0,    0,    0, -143,    0,    0,    0, -139, -122,
    0,    0,    0,    0,    0,    0,  -49,    0,    0,    0,
    0,    0,   71, -143,    0,    0,    0,    0,    0,   99,
    0,    0,    0,  -30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  428,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   45,    0,    0,   17,    0,    0,    0,    0,    0,    0,
    0,    0, 1014,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    3,    0,    0,    0,    0,    0,    0,
    0,    0,  262,    0,    0,    0,  929,  957,  828, 1076,
 1185, 1176,  982, 1023,  889,  912,  765,  795,  869,    0,
    0,    0,  474,    0,    0,    0,   24,    0,    0,    0,
    0,    0,    0,    0, -128,    0,    0,    0, -126,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
  138,  115,  132,    0, 1263,    0,  -15,    0,    0,    0,
 1286,    0,  146,    0,   10,    0,    0,   92,  -46,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 1460
static const short yytable[] = {                         20,
    2,   77,   91,    1,   91,   79,   91,   91,   90,   26,
   91,   91,   91,   91,   91,   69,   91,  111,   21,  140,
   60,    7,  141,  108,    1,   11,  118,  107,   91,   91,
    8,   91,  105,  103,    2,  104,   16,  106,   12,   13,
   14,   37,   38,   60,   18,   93,   60,  111,   27,   91,
  102,  112,  101,   91,   91,   30,   31,   91,   91,   91,
   91,   91,   91,   91,   59,  108,   70,   59,   33,  107,
  143,   36,   66,   24,  105,   91,   91,   64,   91,  106,
   67,   64,   64,   10,   68,   64,   64,   64,   64,   64,
   74,   64,   91,   91,  119,   70,   10,   10,   10,  120,
  121,  153,  125,   64,   64,  108,   64,  108,  149,   91,
  148,  107,  100,  160,  162,    8,  105,  103,  108,  104,
   10,  106,  107,  100,   87,   88,   89,  105,  103,   23,
  104,   53,  106,   57,  102,   56,  101,   64,   55,   30,
   91,   57,   29,   58,  109,  102,   15,  101,   39,  108,
   26,   10,   94,  107,  100,   29,   29,   29,  105,  103,
  108,  104,    0,  106,  107,    0,    0,    0,   64,  105,
  103,    0,  104,    0,  106,  108,  102,    0,  101,  107,
  100,    0,    0,  122,  105,  103,    0,  104,    0,  106,
   23,   24,   25,    0,    0,    0,    0,    0,   99,   76,
    8,  108,  102,   78,  101,  107,  100,    0,    0,   99,
  105,  103,    0,  104,    0,  106,    0,    0,    0,   54,
    0,    0,    0,    0,    0,    0,    0,    0,  102,    0,
  101,    0,    0,    0,    0,    0,    0,   91,    0,   91,
   99,    0,   91,   91,   91,    0,   19,    0,    0,    0,
   91,   91,   91,   91,   91,   91,   91,    0,   87,   88,
   89,  142,    0,    0,    0,   12,   99,   12,   12,    0,
   12,   95,   96,   97,   98,    0,    0,    0,   12,   12,
   12,   12,   12,   12,   91,    0,   91,    0,   91,   91,
   91,   91,   99,    0,    0,    0,    0,   91,   91,   91,
   91,    0,   68,    0,    0,   68,   53,    0,   57,    0,
   56,    0,   64,   55,   64,    0,    0,   64,   64,   64,
   68,    0,    0,    0,    0,   64,   64,   64,   64,    0,
    0,    0,  108,    0,    0,    0,  107,  100,    0,    0,
    0,  105,  103,    0,  104,    0,  106,    0,  150,  151,
   42,   43,   44,   45,   68,   95,   96,   97,   98,  102,
    0,  101,    0,    0,    0,    0,   95,   96,   97,   98,
   53,    0,   57,    0,   56,    0,  108,   55,   51,   52,
  107,  100,    0,    0,  117,  105,  103,    0,  104,    0,
  106,   36,    0,   58,   54,    0,    0,   95,   96,   97,
   98,    0,  146,  102,  108,  101,    0,    0,  107,  100,
    0,    0,    0,  105,  103,    0,  104,    0,  106,    0,
    0,    0,    0,   95,   96,   97,   98,    0,    0,    0,
  156,  102,  108,  101,    0,    0,  107,  100,    0,    0,
    0,  105,  103,    0,  104,    0,  106,    0,    0,   95,
   96,   97,   98,    0,    0,   36,    0,   92,   54,  102,
   64,  101,    0,    0,   64,   64,    0,   99,    0,   64,
   64,  108,   64,    0,   64,  107,  100,    0,    0,    0,
  105,  103,    0,  104,    0,  106,   64,   64,    0,   64,
    0,    0,  108,    0,    0,   99,  107,    0,  102,    0,
  101,  105,  103,    0,  104,   53,  106,   57,  113,   56,
    0,   40,   55,   40,    0,   40,    0,    0,   40,  102,
    0,  101,    0,   99,   41,   42,   43,   44,   45,   68,
   46,   68,    0,   11,   68,   68,   68,    0,   47,   48,
    0,    0,    0,    0,   49,   50,   12,   13,   14,    0,
    0,   64,    0,   51,   52,    0,   53,    0,   57,    0,
   56,    0,   99,   55,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   95,   96,   97,   98,    0,    0,    0,    0,   41,   42,
   43,   44,   45,   54,   46,    0,   40,   11,   40,   40,
    0,    0,   47,   48,    0,    0,    0,    0,   49,   50,
   12,   13,   14,    0,    0,    0,    0,   51,   52,    0,
    0,    0,    0,    0,   95,   96,   97,   98,   53,    0,
   57,    0,   56,    0,    0,   55,    0,    0,    0,    0,
    0,   36,    0,  110,   54,    0,    0,    0,    0,    0,
    0,    0,   95,   96,   97,   98,    0,    0,    0,    0,
   53,    0,   57,    0,   56,    0,    0,   55,    0,    0,
    0,    0,  157,    0,    0,    0,    0,    0,    0,    0,
   95,   96,   97,   98,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   64,   64,
   64,   64,    0,   36,    0,  126,   54,    0,    0,   95,
   96,   97,   98,    0,   42,   43,   44,   45,    0,   40,
   40,   40,   40,   40,   40,   40,    0,    0,    0,    0,
   95,   96,    0,   40,   40,   36,    0,    0,   54,   40,
   40,    0,   51,   52,    0,    0,    0,    0,   40,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   42,   43,   44,   45,    0,
   46,    0,    0,    0,    0,    0,    0,    0,   47,   48,
    0,    0,    0,    0,   49,   50,    0,    0,    0,    0,
    0,   74,   74,   51,   52,   74,   74,   74,   74,   74,
    0,   74,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   74,   74,    0,   74,    0,    0,    0,
    0,   75,   75,    0,    0,   75,   75,   75,   75,   75,
    0,   75,    0,    0,    0,    0,   41,   42,   43,   44,
   45,    0,   46,   75,   75,    0,   75,   74,    0,    0,
   47,   48,    0,    0,    0,   81,   49,   50,   81,    0,
    0,   81,    0,    0,    0,   51,   52,    0,   41,   42,
   43,   44,   45,    0,   46,    0,   81,   75,   74,    0,
    0,    0,   47,   48,    0,    0,    0,    0,   49,   50,
    0,    0,    0,    0,    0,   76,   76,   51,   52,   76,
   76,   76,   76,   76,    0,   76,    0,    0,   75,    0,
   81,    0,    0,    0,    0,    0,   77,   76,   76,   77,
   76,   77,   77,   77,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   77,   77,   78,
   77,   81,   78,    0,   78,   78,   78,    0,    0,    0,
    0,   76,    0,    0,    0,    0,   83,    0,    0,   83,
   78,   78,   83,   78,    0,    0,    0,    0,    0,    0,
    0,   77,    0,    0,    0,    0,    0,   83,   83,    0,
   83,    0,   76,    0,   84,    0,    0,   84,    0,    0,
   84,    0,    0,    0,   78,    0,    0,    0,    0,    0,
    0,    0,   77,    0,    0,   84,   84,    0,   84,   79,
    0,   83,   79,    0,    0,   79,    0,    0,    0,    0,
    0,    0,   74,    0,   74,   78,    0,   74,   74,   74,
   79,   79,    0,   79,    0,   74,   74,   74,   74,   84,
    0,   87,   83,    0,   87,    0,    0,   87,    0,    0,
   80,    0,   75,   80,   75,    0,   80,   75,   75,   75,
    0,    0,   87,    0,   79,   75,   75,   75,   75,    0,
   84,   80,   80,    0,   80,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   81,    0,   81,    0,    0,
   81,   81,   81,    0,    0,   79,   87,    0,    0,    0,
   81,   81,    0,   82,    0,   80,   82,    0,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   82,    0,   76,   87,   76,    0,
    0,   76,   76,   76,    0,    0,   80,    0,    0,   76,
   76,   76,   76,    0,    0,    0,   77,    0,   77,    0,
    0,   77,   77,   77,    0,    0,    0,    0,   82,   77,
   77,   77,   77,    0,    0,    0,    0,    0,    0,   78,
    0,   78,    0,    0,   78,   78,   78,    0,    0,    0,
    0,    0,   78,   78,   78,   78,   83,    0,   83,   82,
    0,   83,   83,   83,    0,    0,    0,    0,    0,   83,
   83,   83,   83,   85,    0,    0,   85,    0,    0,   85,
    0,    0,    0,    0,   84,   86,   84,    0,   86,   84,
   84,   84,    0,    0,   85,    0,    0,   84,   84,   84,
   84,    0,    0,   86,    0,    0,    0,    0,    0,   79,
    0,   79,    0,    0,   79,   79,   79,    0,    0,    0,
    0,    0,   79,   79,   79,   79,    0,    0,   85,    0,
    0,    0,    0,    0,    0,    0,    0,   86,    0,    0,
    0,   87,    0,   87,    0,    0,   87,   87,   87,    0,
   80,    0,   80,    0,    0,   80,   80,   80,   59,   85,
    0,    0,    0,   80,   80,   80,   80,    0,   86,    0,
   75,    0,    0,   80,   81,   82,    0,    0,   85,    0,
    0,    0,    0,   59,    0,    0,   59,    0,    0,    0,
    0,   72,    0,    0,    0,   59,    0,    0,    0,   83,
   84,    0,   86,   82,    0,   82,    0,    0,   82,   82,
   82,    0,    0,    0,  114,  116,   59,    0,   82,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  123,  124,    0,    0,    0,   59,
  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,
  137,  138,  139,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  145,    0,    0,    0,    0,    0,
   59,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   59,    0,    0,  147,    0,    0,    0,
    0,    0,    0,    0,  154,    0,    0,  155,    0,    0,
    0,    0,  159,   85,    0,   85,    0,    0,   85,   85,
   85,    0,   86,    0,   86,    0,    0,   86,   86,   86,
};
static const short yycheck[] = {                         40,
    0,   59,   33,    0,   35,   59,   37,   38,   35,   59,
   41,   42,   43,   44,   45,   40,   47,   64,   59,   41,
   36,   59,   44,   33,  256,  265,   73,   37,   59,   60,
  267,   62,   42,   43,  266,   45,   42,   47,  278,  279,
  280,   32,   33,   41,  259,   61,   44,   94,   41,   33,
   60,   67,   62,   37,   38,   59,  260,   41,   42,   43,
   44,   45,   93,   47,   41,   33,   91,   44,   41,   37,
  117,  123,  259,  123,   42,   59,   60,   33,   62,   47,
   44,   37,   38,  265,   59,   41,   42,   43,   44,   45,
  259,   47,   59,  124,  272,   91,  278,  279,  280,   59,
   59,  148,   59,   59,   60,   33,   62,   33,  261,   93,
  269,   37,   38,  270,  161,  259,   42,   43,   33,   45,
  260,   47,   37,   38,  285,  286,  287,   42,   43,   59,
   45,   38,   47,   40,   60,   42,   62,   93,   45,   41,
  124,  270,  265,  270,   59,   60,    9,   62,   34,   33,
   19,    6,   61,   37,   38,  278,  279,  280,   42,   43,
   33,   45,   -1,   47,   37,   -1,   -1,   -1,  124,   42,
   43,   -1,   45,   -1,   47,   33,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
  257,  258,  259,   -1,   -1,   -1,   -1,   -1,  124,  257,
  267,   33,   60,  257,   62,   37,   38,   -1,   -1,  124,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  126,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,
   62,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
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
  268,   -1,  270,   -1,   -1,  273,  274,  275,   36,  124,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,  124,   -1,
   48,   -1,   -1,   51,   52,   53,   -1,   -1,   56,   -1,
   -1,   -1,   -1,   61,   -1,   -1,   64,   -1,   -1,   -1,
   -1,   46,   -1,   -1,   -1,   73,   -1,   -1,   -1,   54,
   55,   -1,   57,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,   -1,   69,   70,   94,   -1,  283,  284,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   89,   90,   -1,   -1,   -1,  117,
   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
  105,  106,  107,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  119,   -1,   -1,   -1,   -1,   -1,
  148,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  161,   -1,   -1,  141,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  149,   -1,   -1,  152,   -1,   -1,
   -1,   -1,  157,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
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
"LE","EQ","NE","INC","DEC","ATRIB","ADDR","POINTER","IFX","UMINUS",
};
static const char *yyrule[] = {
"$accept : ficheiro",
"ficheiro : declaracoes",
"ficheiro :",
"declaracoes : declaracao",
"declaracoes : declaracoes declaracao",
"declaracao : pub cons tipo ptr IDENTIF init ';'",
"declaracao : pub cons tipo ptr IDENTIF ';'",
"declaracao : error ';'",
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
"init : ATRIB cons STRN",
"init : ATRIB NUM",
"init : ATRIB IDENTIF",
"init : '(' parametros ')' corpo",
"init : '(' parametros ')'",
"$$1 :",
"init : '(' ')' $$1 corpo",
"init : '(' ')'",
"pars : pars ',' parametro",
"pars :",
"$$2 :",
"parametros : $$2 parametro pars",
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
"$$3 :",
"$$4 :",
"instrucao : DO $$3 instrucao $$4 WHILE expressao ';'",
"$$5 :",
"instrucao : FOR left_value IN expressao updown expressao step DO $$5 instrucao",
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
"expressao : INC left_value",
"expressao : DEC left_value",
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
#line 178 "factorial.y"

static int oper(int name, int name2) {
 
  if (name == 0 || name2 == 0 || name == 2 || name2 == 2) 
    yyerror("Operação : Tipo inválido.");
  if(name == 3 || name2 == 3) return 3;
  else return 1;
}

static int comp(int name, int name2) {
 
  if (name == 0 || name2 == 0) yyerror("Comparação : Tipo inválido.");
  if (name == 2 && name != name2) yyerror("Comparação : Tipos incompatíveis.");
  return 1;
}
#line 663 "y.tab.c"

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
case 5:
#line 50 "factorial.y"
	{ IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i, yystack.l_mark[-2].s, 0); 
                                                            if((yystack.l_mark[-4].i+yystack.l_mark[-3].i != (yystack.l_mark[-1].i & 0x7)) && (yystack.l_mark[-1].i != 32)) yyerror("Atribuição entre tipos diferentes.");
                                                            if(yystack.l_mark[-1].i == 32){  IDreplace(yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+32, yystack.l_mark[-2].s, p); strcpy(var, yystack.l_mark[-2].s);}}
break;
case 6:
#line 53 "factorial.y"
	{ IDnew(yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+yystack.l_mark[-2].i, yystack.l_mark[-1].s, 0); }
break;
case 7:
#line 54 "factorial.y"
	{ yyval.i = 0; yyerrok; }
break;
case 8:
#line 57 "factorial.y"
	{ yyval.i = 0; }
break;
case 9:
#line 58 "factorial.y"
	{ yyval.i = 4; }
break;
case 10:
#line 61 "factorial.y"
	{ yyval.i = 0; }
break;
case 11:
#line 62 "factorial.y"
	{ yyval.i = 8; }
break;
case 12:
#line 65 "factorial.y"
	{ yyval.i = 0; }
break;
case 13:
#line 66 "factorial.y"
	{ yyval.i = 16; }
break;
case 14:
#line 69 "factorial.y"
	{ yyval.i = 0; }
break;
case 15:
#line 70 "factorial.y"
	{ yyval.i = 1; }
break;
case 16:
#line 71 "factorial.y"
	{ yyval.i = 2; }
break;
case 17:
#line 72 "factorial.y"
	{ yyval.i = 3; }
break;
case 18:
#line 75 "factorial.y"
	{ yyval.i = 1; }
break;
case 19:
#line 76 "factorial.y"
	{ yyval.i = 2; }
break;
case 20:
#line 77 "factorial.y"
	{ yyval.i = 3; }
break;
case 21:
#line 78 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[0].s, 0)+4; }
break;
case 22:
#line 79 "factorial.y"
	{ yyval.i = 32; p = yystack.l_mark[-2].i; IDpop();}
break;
case 23:
#line 80 "factorial.y"
	{ yyval.i = 32; p = yystack.l_mark[-1].i; IDpop();}
break;
case 24:
#line 81 "factorial.y"
	{ tipo = IDfind(var, 0); IDprint(0,0); IDinsert(0, tipo, var, 0);IDpush(); if(tipo != 0) {IDnew(tipo-32, var,0);}}
break;
case 25:
#line 81 "factorial.y"
	{ yyval.i = 0; IDpop();}
break;
case 26:
#line 82 "factorial.y"
	{ yyval.i = 0; }
break;
case 27:
#line 85 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[0].i; }
break;
case 28:
#line 86 "factorial.y"
	{ yyval.i = 0; }
break;
case 29:
#line 89 "factorial.y"
	{tipo = IDfind(var, 0); IDprint(0,0); IDinsert(0, tipo, var, 0); IDpush(); if(tipo != 0) {IDnew(tipo-32, var,0);}}
break;
case 30:
#line 89 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[-1].i; }
break;
case 31:
#line 92 "factorial.y"
	{ IDnew(yystack.l_mark[-2].i+yystack.l_mark[-1].i, yystack.l_mark[0].s, 0); }
break;
case 32:
#line 95 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 33:
#line 96 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[-1].i; }
break;
case 42:
#line 111 "factorial.y"
	{ nciclo++; }
break;
case 43:
#line 111 "factorial.y"
	{ nciclo--; }
break;
case 45:
#line 112 "factorial.y"
	{ nciclo++; }
break;
case 46:
#line 112 "factorial.y"
	{ nciclo--; }
break;
case 49:
#line 115 "factorial.y"
	{ if (yystack.l_mark[-1].i == 0 || yystack.l_mark[-1].i > nciclo) yyerror("Break inválido: Fora de um ciclo"); }
break;
case 51:
#line 117 "factorial.y"
	{ if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); }
break;
case 54:
#line 120 "factorial.y"
	{ yyerrok; }
break;
case 59:
#line 131 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[0].i; }
break;
case 60:
#line 132 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 61:
#line 135 "factorial.y"
	{ yyval.i = 1; }
break;
case 62:
#line 136 "factorial.y"
	{ yyval.i = 3; }
break;
case 63:
#line 137 "factorial.y"
	{ yyval.i = 2; }
break;
case 64:
#line 138 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 65:
#line 139 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[-3].s, 0) + yystack.l_mark[-1].i; }
break;
case 66:
#line 140 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[-2].s, 0); }
break;
case 67:
#line 141 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 68:
#line 142 "factorial.y"
	{ if (yystack.l_mark[-2].i != yystack.l_mark[0].i) yyerror("Atribuição entre tipos diferentes."); yyval.i = yystack.l_mark[-2].i; }
break;
case 69:
#line 143 "factorial.y"
	{ if(yystack.l_mark[0].i == 0 || yystack.l_mark[0].i == 2) yyerror("Simétrico : Tipo inválido."); yyval.i = yystack.l_mark[0].i; }
break;
case 70:
#line 144 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Incremento : Tipo inválido."); yyval.i = 1; }
break;
case 71:
#line 145 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Decremento : Tipo inválido."); yyval.i = 1; }
break;
case 72:
#line 146 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Incremento : Tipo inválido."); yyval.i = 1; }
break;
case 73:
#line 147 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Decremento : Tipo inválido."); yyval.i = 1; }
break;
case 74:
#line 148 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 75:
#line 149 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 76:
#line 150 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 77:
#line 151 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 78:
#line 152 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 79:
#line 153 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 80:
#line 154 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 81:
#line 155 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 82:
#line 156 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 83:
#line 157 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 84:
#line 158 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 85:
#line 159 "factorial.y"
	{ if(yystack.l_mark[-2].i != 1 || yystack.l_mark[0].i != 1) yyerror("Junção Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 86:
#line 160 "factorial.y"
	{ if(yystack.l_mark[-2].i != 1 || yystack.l_mark[0].i != 1) yyerror("Alternativa Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 87:
#line 161 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Negação Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 88:
#line 162 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Factorial : Tipo inválido."); yyval.i = yystack.l_mark[-1].i; }
break;
case 89:
#line 163 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 90:
#line 164 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 91:
#line 167 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[0].s, 0); }
break;
case 92:
#line 168 "factorial.y"
	{int x = IDfind(yystack.l_mark[-3].s, 0);
                                                        if (((x & 0x7) == 4) || ((x & 0x7) == 5)  || ((x & 0x7) == 7)) 
                                                              yyval.i = x - 4;
                                                        else if (((x & 0x7) == 2))
                                                              yyval.i = 1;
                                                        else yyerror("Ponteiro: Tipo inválido.");
              /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
break;
#line 1157 "y.tab.c"
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
