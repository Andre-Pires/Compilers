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
    0,    0,   14,   14,   13,   13,   15,   17,   13,   19,
   13,   13,   13,   16,   16,    2,    2,    3,    3,    4,
    4,    1,    1,    1,    1,    6,    6,    6,    6,    9,
    9,    8,    7,   10,   10,   18,   18,   18,   18,   20,
   20,   21,   21,   22,   23,   21,   26,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   24,   24,   25,   25,
   12,   12,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,    5,    5,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    7,    6,    0,    0,   12,    0,
   10,    8,    2,    0,    1,    0,    1,    0,    1,    0,
    1,    1,    1,    1,    1,    2,    3,    2,    2,    3,
    0,    2,    3,    2,    3,    2,    3,    3,    4,    1,
    2,    4,    6,    0,    0,    7,    0,   10,    2,    1,
    3,    3,    2,    2,    4,    2,    1,    1,    0,    2,
    3,    1,    1,    1,    1,    1,    4,    3,    3,    3,
    2,    2,    2,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    2,
    2,    2,    1,    4,
};
static const short yydefred[] = {                         0,
    0,   21,    0,    0,    3,    0,   13,   19,    0,    4,
   22,   23,   24,   25,    0,   17,    0,    0,    0,    0,
    6,    0,   26,   28,   29,    0,    0,    0,    5,   27,
   12,    0,    0,   31,    0,    0,    0,    0,    0,    8,
    0,   63,   64,    0,   65,    0,   44,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,    0,    0,
    0,    0,   50,    0,   40,   11,   33,    0,    0,   56,
    0,    0,    0,    0,    0,    0,    0,    0,   53,    0,
   54,   72,   73,   91,    0,   71,   92,    0,   74,   75,
    0,    0,   34,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   90,
   49,   38,   41,   30,    0,   15,   68,    0,    0,    0,
    0,   45,    0,   51,   52,   69,    0,    0,   35,   39,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,   67,    0,   94,    0,    0,    0,
   55,    0,    0,    0,   57,   58,    0,   43,    0,    0,
   46,    0,    0,    0,   47,    0,   48,
};
static const short yydgoto[] = {                          3,
   33,   17,    9,    4,   73,   22,   34,   35,   39,   61,
   62,  119,    5,    6,   28,  115,   69,   63,   32,   64,
   65,   75,  149,  157,  163,  166,
};
static const short yysindex[] = {                      -217,
  -41,    0,    0, -246,    0, -217,    0,    0, -234,    0,
    0,    0,    0,    0,  -20,    0, -211,  -40, -232,   16,
    0,  -17,    0,    0,    0, -195,   13, -234,    0,    0,
    0,  -49,  -20,    0,   25,  269,   21, -174,   47,    0,
   34,    0,    0,  -24,    0,   94,    0, -160,  -57,  -53,
 -160, -160, -160,   94,   94, -160,   94,    0,  -26,   41,
  333,   86,    0,  519,    0,    0,    0, -234,  -49,    0,
  468,   94, -190,  117,  623,   11, -169,   50,    0,   52,
    0,    0,    0,    0,   -9,    0,    0,  143,    0,    0,
   94,   94,    0,    0,   62,  591,   94,   94,   94,   94,
   94,   94,   94,   94,   94,   94,   94,   94,   94,    0,
    0,    0,    0,    0,   66,    0,    0,  439,  -21,  169,
  623,    0,   94,    0,    0,    0,  439,  344,    0,    0,
  128,  128,  460,  460,  300,   -9,  128,  128,  116,  116,
   73,   73,   73,    0,    0,   94,    0, -143, -134,   75,
    0,  439,  623,   94,    0,    0,   94,    0,  372,  400,
    0,   94, -130,  439,    0,  623,    0,
};
static const short yyrindex[] = {                         1,
    0,    0,    0, -209,    0,    4,    0,    0,    0,    0,
    0,    0,    0,    0, -117,    0,    0,    0, -116, -164,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
    0,    0, -117,    0,    0,    0,    0,    0,  110,    0,
    0,    0,    0,  -30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  428,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   93,    0,
    0,    0,   45,    0,    0,   17,    0,    0,    0,    0,
    0,    0,    0,    0, 1014,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   -4,    0,    0,
    0,    0,    0,    0,    0,    0,  262,    0,    0,    0,
  929,  957,  828, 1076, 1185, 1176,  982, 1023,  889,  912,
  765,  795,  869,    0,    0,    0,    0,  474,    0,    0,
    0,   40,    0,    0,    0,    0,    0,    0,    0, -114,
    0,    0,    0, -113,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  157,  134,  149,    0, 1265,    0,    7,    0,    0,    0,
 1276,    0,  166,    0,    0,    0,    0,  -22,    0,  113,
  -23,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1460
static const short yytable[] = {                         20,
    2,   79,   93,    1,   93,   81,   93,   93,   92,   37,
   93,   93,   93,   93,   93,   71,   93,    7,   21,  145,
    8,   16,  146,  110,   23,   24,   25,  109,   93,   93,
   11,   93,  107,  105,    8,  106,   62,  108,    1,   62,
  113,   29,   60,   12,   13,   14,  116,   18,    2,   93,
  104,  122,  103,   93,   93,   18,   27,   93,   93,   93,
   93,   93,   93,   93,   30,   40,   72,   95,   18,   18,
   18,   31,  113,   36,  114,   93,   93,   66,   93,   66,
   61,   66,   66,   61,   67,   66,   66,   66,   66,   66,
   68,   66,   70,   93,   89,   90,   91,  148,   76,   93,
    7,   72,  123,   66,   66,  110,   66,  110,  124,   93,
  125,  109,  102,    7,    7,    7,  107,  105,  110,  106,
  129,  108,  109,  102,  144,  153,  154,  107,  105,  158,
  106,   53,  108,   57,  104,   56,  103,   66,   55,  165,
   93,   16,  167,   18,  111,  104,   10,  103,  110,  110,
   32,   14,  109,  109,  102,   59,   60,  107,  107,  105,
  110,  106,  108,  108,  109,   15,   38,   26,   66,  107,
  105,   10,  106,   96,  108,  110,  104,    0,  103,  109,
  102,    0,    0,  126,  107,  105,    0,  106,    0,  108,
    0,    0,    0,    0,    0,    0,    0,    0,  101,   78,
    0,  110,  104,   80,  103,  109,  102,    0,    0,  101,
  107,  105,    0,  106,    0,  108,    0,    0,    0,   54,
    0,    0,    0,    0,    0,    0,    0,    0,  104,    0,
  103,    0,    0,    0,    0,    0,    0,   93,    0,   93,
  101,    0,   93,   93,   93,    0,   19,    0,    0,    0,
   93,   93,   93,   93,   93,   93,   93,    0,   89,   90,
   91,  147,    0,    0,    0,   20,  101,   20,   20,    0,
   20,   97,   98,   99,  100,    0,    0,    0,   20,   20,
   20,   20,   20,   20,   93,    0,   93,    0,   93,   93,
   93,   93,  101,    0,    0,    0,    0,   93,   93,   93,
   93,    0,   70,    0,    0,   70,   53,    0,   57,    0,
   56,    0,   66,   55,   66,    0,    0,   66,   66,   66,
   70,    0,    0,    0,    0,   66,   66,   66,   66,    0,
    0,    0,  110,    0,    0,    0,  109,  102,    0,    0,
    0,  107,  105,    0,  106,    0,  108,    0,  155,  156,
   42,   43,   44,   45,   70,   97,   98,   99,  100,  104,
    0,  103,    0,    0,    0,    0,   97,   98,   99,  100,
   53,    0,   57,    0,   56,    0,  110,   55,   51,   52,
  109,  102,    0,    0,  121,  107,  105,    0,  106,    0,
  108,   36,    0,   58,   54,    0,    0,   97,   98,   99,
  100,    0,  151,  104,  110,  103,    0,    0,  109,  102,
    0,    0,    0,  107,  105,    0,  106,    0,  108,    0,
    0,    0,    0,   97,   98,   99,  100,    0,    0,    0,
  161,  104,  110,  103,    0,    0,  109,  102,    0,    0,
    0,  107,  105,    0,  106,    0,  108,    0,    0,   97,
   98,   99,  100,    0,    0,   36,    0,   94,   54,  104,
   66,  103,    0,    0,   66,   66,    0,  101,    0,   66,
   66,  110,   66,    0,   66,  109,  102,    0,    0,    0,
  107,  105,    0,  106,    0,  108,   66,   66,    0,   66,
    0,    0,  110,    0,    0,  101,  109,    0,  104,    0,
  103,  107,  105,    0,  106,   53,  108,   57,  117,   56,
    0,   42,   55,   42,    0,   42,    0,    0,   42,  104,
    0,  103,    0,  101,   41,   42,   43,   44,   45,   70,
   46,   70,    0,   11,   70,   70,   70,    0,   47,   48,
    0,    0,    0,    0,   49,   50,   12,   13,   14,    0,
    0,   66,    0,   51,   52,    0,   53,    0,   57,    0,
   56,    0,  101,   55,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   97,   98,   99,  100,    0,    0,    0,    0,   41,   42,
   43,   44,   45,   54,   46,    0,   42,   11,   42,   42,
    0,    0,   47,   48,    0,    0,    0,    0,   49,   50,
   12,   13,   14,    0,    0,    0,    0,   51,   52,    0,
    0,    0,    0,    0,   97,   98,   99,  100,   53,    0,
   57,    0,   56,    0,    0,   55,    0,    0,    0,    0,
    0,   36,    0,  112,   54,    0,    0,    0,    0,    0,
    0,    0,   97,   98,   99,  100,    0,    0,    0,    0,
   53,    0,   57,    0,   56,    0,    0,   55,    0,    0,
    0,    0,  162,    0,    0,    0,    0,    0,    0,    0,
   97,   98,   99,  100,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   66,   66,
   66,   66,    0,   36,    0,  130,   54,    0,    0,   97,
   98,   99,  100,    0,   42,   43,   44,   45,    0,   42,
   42,   42,   42,   42,   42,   42,    0,    0,    0,    0,
   97,   98,    0,   42,   42,   36,    0,    0,   54,   42,
   42,    0,   51,   52,    0,    0,    0,    0,   42,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   42,   43,   44,   45,    0,
   46,    0,    0,    0,    0,    0,    0,    0,   47,   48,
    0,    0,    0,    0,   49,   50,    0,    0,    0,    0,
    0,   76,   76,   51,   52,   76,   76,   76,   76,   76,
    0,   76,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,   76,    0,   76,    0,    0,    0,
    0,   77,   77,    0,    0,   77,   77,   77,   77,   77,
    0,   77,    0,    0,    0,    0,   41,   42,   43,   44,
   45,    0,   46,   77,   77,    0,   77,   76,    0,    0,
   47,   48,    0,    0,    0,   83,   49,   50,   83,    0,
    0,   83,    0,    0,    0,   51,   52,    0,   41,   42,
   43,   44,   45,    0,   46,    0,   83,   77,   76,    0,
    0,    0,   47,   48,    0,    0,    0,    0,   49,   50,
    0,    0,    0,    0,    0,   78,   78,   51,   52,   78,
   78,   78,   78,   78,    0,   78,    0,    0,   77,    0,
   83,    0,    0,    0,    0,    0,   79,   78,   78,   79,
   78,   79,   79,   79,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   79,   80,
   79,   83,   80,    0,   80,   80,   80,    0,    0,    0,
    0,   78,    0,    0,    0,    0,   85,    0,    0,   85,
   80,   80,   85,   80,    0,    0,    0,    0,    0,    0,
    0,   79,    0,    0,    0,    0,    0,   85,   85,    0,
   85,    0,   78,    0,   86,    0,    0,   86,    0,    0,
   86,    0,    0,    0,   80,    0,    0,    0,    0,    0,
    0,    0,   79,    0,    0,   86,   86,    0,   86,   81,
    0,   85,   81,    0,    0,   81,    0,    0,    0,    0,
    0,    0,   76,    0,   76,   80,    0,   76,   76,   76,
   81,   81,    0,   81,    0,   76,   76,   76,   76,   86,
    0,   89,   85,    0,   89,    0,    0,   89,    0,    0,
   82,    0,   77,   82,   77,    0,   82,   77,   77,   77,
    0,    0,   89,    0,   81,   77,   77,   77,   77,    0,
   86,   82,   82,    0,   82,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   83,    0,   83,    0,    0,
   83,   83,   83,    0,    0,   81,   89,    0,    0,    0,
   83,   83,    0,   84,    0,   82,   84,    0,    0,   84,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   84,    0,   78,   89,   78,    0,
    0,   78,   78,   78,    0,    0,   82,    0,    0,   78,
   78,   78,   78,    0,    0,    0,   79,    0,   79,    0,
    0,   79,   79,   79,    0,    0,    0,    0,   84,   79,
   79,   79,   79,    0,    0,    0,    0,    0,    0,   80,
    0,   80,    0,    0,   80,   80,   80,    0,    0,    0,
    0,    0,   80,   80,   80,   80,   85,    0,   85,   84,
    0,   85,   85,   85,    0,    0,    0,    0,    0,   85,
   85,   85,   85,   87,    0,    0,   87,    0,    0,   87,
    0,    0,    0,    0,   86,   88,   86,    0,   88,   86,
   86,   86,    0,    0,   87,    0,    0,   86,   86,   86,
   86,    0,    0,   88,    0,    0,    0,    0,    0,   81,
    0,   81,    0,    0,   81,   81,   81,    0,    0,    0,
    0,    0,   81,   81,   81,   81,    0,    0,   87,    0,
    0,    0,    0,    0,    0,    0,    0,   88,    0,    0,
    0,   89,    0,   89,    0,    0,   89,   89,   89,    0,
   82,    0,   82,    0,    0,   82,   82,   82,    0,   87,
   59,    0,    0,   82,   82,   82,   82,    0,   88,    0,
    0,    0,   77,    0,    0,   82,   83,   84,    0,    0,
   87,   74,    0,    0,    0,   59,    0,    0,   59,   85,
   86,    0,   88,    0,    0,    0,    0,    0,    0,   59,
    0,    0,    0,   84,    0,   84,  118,  120,   84,   84,
   84,    0,    0,    0,    0,    0,    0,    0,   84,   84,
   59,    0,    0,    0,    0,    0,  127,  128,    0,    0,
    0,    0,  131,  132,  133,  134,  135,  136,  137,  138,
  139,  140,  141,  142,  143,   59,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  150,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   59,    0,    0,
    0,  152,    0,    0,    0,    0,    0,    0,    0,  159,
   59,    0,  160,    0,    0,    0,    0,  164,    0,    0,
    0,    0,    0,   87,    0,   87,    0,    0,   87,   87,
   87,    0,   88,    0,   88,    0,    0,   88,   88,   88,
};
static const short yycheck[] = {                         40,
    0,   59,   33,    0,   35,   59,   37,   38,   35,   32,
   41,   42,   43,   44,   45,   40,   47,   59,   59,   41,
  267,   42,   44,   33,  257,  258,  259,   37,   59,   60,
  265,   62,   42,   43,  267,   45,   41,   47,  256,   44,
   64,   59,   36,  278,  279,  280,   69,  259,  266,   33,
   60,   75,   62,   37,   38,  265,   41,   41,   42,   43,
   44,   45,   93,   47,  260,   41,   91,   61,  278,  279,
  280,   59,   96,  123,   68,   59,   60,   33,   62,   59,
   41,   37,   38,   44,  259,   41,   42,   43,   44,   45,
   44,   47,   59,  124,  285,  286,  287,  121,  259,   59,
  265,   91,  272,   59,   60,   33,   62,   33,   59,   93,
   59,   37,   38,  278,  279,  280,   42,   43,   33,   45,
   59,   47,   37,   38,   59,  269,  261,   42,   43,  153,
   45,   38,   47,   40,   60,   42,   62,   93,   45,  270,
  124,  259,  166,  260,   59,   60,  123,   62,   33,   33,
   41,   59,   37,   37,   38,  270,  270,   42,   42,   43,
   33,   45,   47,   47,   37,    9,   33,   19,  124,   42,
   43,    6,   45,   61,   47,   33,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  257,
   -1,   33,   60,  257,   62,   37,   38,   -1,   -1,  124,
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
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,  124,
   36,   -1,   -1,  281,  282,  283,  284,   -1,  124,   -1,
   -1,   -1,   48,   -1,   -1,   51,   52,   53,   -1,   -1,
   56,   46,   -1,   -1,   -1,   61,   -1,   -1,   64,   54,
   55,   -1,   57,   -1,   -1,   -1,   -1,   -1,   -1,   75,
   -1,   -1,   -1,  268,   -1,  270,   71,   72,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,
   96,   -1,   -1,   -1,   -1,   -1,   91,   92,   -1,   -1,
   -1,   -1,   97,   98,   99,  100,  101,  102,  103,  104,
  105,  106,  107,  108,  109,  121,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  153,   -1,   -1,
   -1,  146,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  154,
  166,   -1,  157,   -1,   -1,   -1,   -1,  162,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
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
"init : ATRIB cons STRN",
"init : ATRIB NUM",
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
#line 177 "factorial.y"

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
#line 665 "y.tab.c"

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
	{ IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i, yystack.l_mark[-2].s, 0); if(yystack.l_mark[-4].i+yystack.l_mark[-3].i != yystack.l_mark[-1].i) yyerror("Atribuição entre tipos diferentes.");}
break;
case 6:
#line 51 "factorial.y"
	{ IDnew(yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+yystack.l_mark[-2].i, yystack.l_mark[-1].s, 0); }
break;
case 7:
#line 52 "factorial.y"
	{IDnew(yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+yystack.l_mark[-2].i+32, yystack.l_mark[-1].s, 0); IDpush(); }
break;
case 8:
#line 52 "factorial.y"
	{IDreplace(yystack.l_mark[-8].i+yystack.l_mark[-7].i+yystack.l_mark[-6].i+yystack.l_mark[-5].i+32,yystack.l_mark[-4].s, p); if((yystack.l_mark[-6].i+yystack.l_mark[-5].i) != 0) {IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i, yystack.l_mark[-4].s, 0);} }
break;
case 9:
#line 52 "factorial.y"
	{ IDpop();}
break;
case 10:
#line 53 "factorial.y"
	{IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+32, yystack.l_mark[-2].s, 0); IDpush();  if((yystack.l_mark[-4].i+yystack.l_mark[-3].i) != 0) {IDnew((yystack.l_mark[-4].i+yystack.l_mark[-3].i), yystack.l_mark[-2].s,0);}}
break;
case 11:
#line 53 "factorial.y"
	{IDpop();}
break;
case 12:
#line 54 "factorial.y"
	{IDnew(yystack.l_mark[-7].i+yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+32, yystack.l_mark[-3].s, 0);}
break;
case 13:
#line 55 "factorial.y"
	{yyerrok; }
break;
case 16:
#line 60 "factorial.y"
	{ yyval.i = 0; }
break;
case 17:
#line 61 "factorial.y"
	{ yyval.i = 4; }
break;
case 18:
#line 64 "factorial.y"
	{ yyval.i = 0; }
break;
case 19:
#line 65 "factorial.y"
	{ yyval.i = 8; }
break;
case 20:
#line 68 "factorial.y"
	{ yyval.i = 0; }
break;
case 21:
#line 69 "factorial.y"
	{ yyval.i = 16; }
break;
case 22:
#line 72 "factorial.y"
	{ yyval.i = 0; }
break;
case 23:
#line 73 "factorial.y"
	{ yyval.i = 1; }
break;
case 24:
#line 74 "factorial.y"
	{ yyval.i = 2; }
break;
case 25:
#line 75 "factorial.y"
	{ yyval.i = 3; }
break;
case 26:
#line 78 "factorial.y"
	{ yyval.i = 1; }
break;
case 27:
#line 79 "factorial.y"
	{ yyval.i = 2; }
break;
case 28:
#line 80 "factorial.y"
	{ yyval.i = 3; }
break;
case 29:
#line 81 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[0].s, 0)+4; }
break;
case 30:
#line 84 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[0].i; }
break;
case 31:
#line 85 "factorial.y"
	{ yyval.i = 0; }
break;
case 32:
#line 88 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i + yystack.l_mark[0].i; }
break;
case 33:
#line 91 "factorial.y"
	{ IDnew(yystack.l_mark[-2].i+yystack.l_mark[-1].i, yystack.l_mark[0].s, 0);}
break;
case 34:
#line 94 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 35:
#line 95 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[-1].i; }
break;
case 44:
#line 110 "factorial.y"
	{ nciclo++; }
break;
case 45:
#line 110 "factorial.y"
	{ nciclo--; }
break;
case 47:
#line 111 "factorial.y"
	{ nciclo++; }
break;
case 48:
#line 111 "factorial.y"
	{ nciclo--; }
break;
case 51:
#line 114 "factorial.y"
	{ if (yystack.l_mark[-1].i == 0 || yystack.l_mark[-1].i > nciclo) yyerror("Break inválido: Fora de um ciclo"); }
break;
case 53:
#line 116 "factorial.y"
	{ if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); }
break;
case 56:
#line 119 "factorial.y"
	{ yyerrok; }
break;
case 61:
#line 130 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[0].i; }
break;
case 62:
#line 131 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 63:
#line 134 "factorial.y"
	{ yyval.i = 1; }
break;
case 64:
#line 135 "factorial.y"
	{ yyval.i = 3; }
break;
case 65:
#line 136 "factorial.y"
	{ yyval.i = 2; }
break;
case 66:
#line 137 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 67:
#line 138 "factorial.y"
	{ yyval.i = IDsearch(yystack.l_mark[-3].s, 0, IDlevel(), 0) && (0x7); }
break;
case 68:
#line 139 "factorial.y"
	{ yyval.i = IDsearch(yystack.l_mark[-2].s, 0, IDlevel(), 0) && (0x7); }
break;
case 69:
#line 140 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 70:
#line 141 "factorial.y"
	{ if (yystack.l_mark[-2].i != yystack.l_mark[0].i) yyerror("Atribuição entre tipos diferentes."); yyval.i = yystack.l_mark[-2].i; }
break;
case 71:
#line 142 "factorial.y"
	{ if(yystack.l_mark[0].i == 0 || yystack.l_mark[0].i == 2) yyerror("Simétrico : Tipo inválido."); yyval.i = yystack.l_mark[0].i; }
break;
case 72:
#line 143 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Incremento : Tipo inválido."); yyval.i = 1; }
break;
case 73:
#line 144 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Decremento : Tipo inválido."); yyval.i = 1; }
break;
case 74:
#line 145 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Incremento : Tipo inválido."); yyval.i = 1; }
break;
case 75:
#line 146 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Decremento : Tipo inválido."); yyval.i = 1; }
break;
case 76:
#line 147 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 77:
#line 148 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 78:
#line 149 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 79:
#line 150 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 80:
#line 151 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 81:
#line 152 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 82:
#line 153 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 83:
#line 154 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 84:
#line 155 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 85:
#line 156 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 86:
#line 157 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 87:
#line 158 "factorial.y"
	{ if(yystack.l_mark[-2].i != 1 || yystack.l_mark[0].i != 1) yyerror("Junção Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 88:
#line 159 "factorial.y"
	{ if(yystack.l_mark[-2].i != 1 || yystack.l_mark[0].i != 1) yyerror("Alternativa Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 89:
#line 160 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Negação Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 90:
#line 161 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Factorial : Tipo inválido."); yyval.i = yystack.l_mark[-1].i; }
break;
case 91:
#line 162 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 92:
#line 163 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 93:
#line 166 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[0].s, 0); }
break;
case 94:
#line 167 "factorial.y"
	{int x = IDfind(yystack.l_mark[-3].s, 0);
                                                        if (((x & 0x4) == 4)) 
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
