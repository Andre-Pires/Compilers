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

int p, nciclo;
#line 13 "factorial.y"
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 42 "y.tab.c"

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
    4,    1,    1,    1,    1,    6,    6,    6,    6,    6,
    6,    9,    9,    8,    7,   10,   10,   18,   18,   18,
   18,   20,   20,   21,   21,   22,   23,   21,   26,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   24,   24,
   25,   25,   12,   12,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,    5,    5,
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
    0,   21,    0,    0,    3,    0,   13,   19,    0,    4,
   22,   23,   24,   25,    0,   17,    0,    0,    0,    0,
    6,    0,   26,   29,   31,    0,    0,    0,    0,    5,
   27,   30,   28,   12,    0,    0,   33,    0,    0,    0,
    0,    0,    8,    0,   65,   66,    0,   67,    0,   46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0,    0,    0,   52,    0,   42,   11,   35,
    0,    0,   58,    0,    0,    0,    0,    0,    0,    0,
    0,   55,    0,   56,   74,   75,   93,    0,   73,   94,
    0,   76,   77,    0,    0,   36,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   92,   51,   40,   43,   32,    0,   15,   70,
    0,    0,    0,    0,   47,    0,   53,   54,   71,    0,
    0,   37,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,   69,    0,   96,
    0,    0,    0,   57,    0,    0,    0,   59,   60,    0,
   45,    0,    0,   48,    0,    0,    0,   49,    0,   50,
};
static const short yydgoto[] = {                          3,
   36,   17,    9,    4,   76,   22,   37,   38,   42,   64,
   65,  122,    5,    6,   29,  118,   72,   66,   35,   67,
   68,   78,  152,  160,  166,  169,
};
static const short yysindex[] = {                      -231,
  -32,    0,    0, -230,    0, -231,    0,    0, -239,    0,
    0,    0,    0,    0,    5,    0, -217,  -40,  -35,    7,
    0,  -16,    0,    0,    0, -235, -208,   -3, -239,    0,
    0,    0,    0,    0,  -52,    5,    0,   25,  269,   13,
 -184,   41,    0,   32,    0,    0,  -24,    0,   94,    0,
 -166,  -57,  -53, -166, -166, -166,   94,   94, -166,   94,
    0,  -26,   36,  333,   86,    0,  519,    0,    0,    0,
 -239,  -52,    0,  468,   94, -143,  117,  623,    9, -176,
   44,    0,   50,    0,    0,    0,    0,   -9,    0,    0,
  143,    0,    0,   94,   94,    0,    0,   55,  591,   94,
   94,   94,   94,   94,   94,   94,   94,   94,   94,   94,
   94,   94,    0,    0,    0,    0,    0,   56,    0,    0,
  439,  -23,  169,  623,    0,   94,    0,    0,    0,  439,
  344,    0,    0,  150,  150,  460,  460,  300,   -9,  150,
  150,   69,   69,   88,   88,   88,    0,    0,   94,    0,
 -144, -134,   75,    0,  439,  623,   94,    0,    0,   94,
    0,  372,  400,    0,   94, -140,  439,    0,  623,    0,
};
static const short yyrindex[] = {                         1,
    0,    0,    0, -234,    0,    4,    0,    0,    0,    0,
    0,    0,    0,    0, -119,    0,    0,    0, -113, -181,
    0,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,    0, -119,    0,    0,    0,    0,
    0,  110,    0,    0,    0,    0,  -30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  428,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   93,    0,    0,    0,   45,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0, 1014,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   24,    0,    0,    0,    0,    0,    0,    0,    0,  262,
    0,    0,    0,  929,  957,  828, 1076, 1185, 1176,  982,
 1023,  889,  912,  765,  795,  869,    0,    0,    0,    0,
  474,    0,    0,    0,   29,    0,    0,    0,    0,    0,
    0,    0, -117,    0,    0,    0, -114,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  148,  125,  144,    0, 1262,    0,   10,    0,    0,    0,
 1273,    0,  159,    0,    0,    0,    0,  -15,    0,  102,
    2,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1460
static const short yytable[] = {                         20,
    2,   82,   95,    1,   95,   84,   95,   95,   95,   26,
   95,   95,   95,   95,   95,   74,   95,  148,   21,   40,
  149,   31,   32,  113,    1,   11,    7,  112,   95,   95,
   18,   95,  110,  108,    2,  109,    8,  111,   12,   13,
   14,   18,   30,   18,   18,   18,   16,   28,   63,   95,
  107,   33,  106,   95,   95,   34,  119,   95,   95,   95,
   95,   95,   95,   95,   64,   43,   75,   64,  116,   63,
   39,   69,   63,   98,   70,   95,   95,   68,   95,  125,
  117,   68,   68,    7,   71,   68,   68,   68,   68,   68,
   73,   68,   79,   95,   96,  126,    7,    7,    7,   75,
  116,  113,  127,   68,   68,  112,   68,  113,  128,   95,
  110,  112,  105,  132,  147,  111,  110,  108,  113,  109,
  113,  111,  112,  105,  156,  151,  157,  110,  108,  168,
  109,   56,  111,   60,  107,   59,  106,   68,   58,   16,
   95,   92,   93,   94,  114,  107,   18,  106,   10,  113,
   34,   14,   61,  112,  105,   62,   15,  161,  110,  108,
   41,  109,   27,  111,   10,   99,    0,    0,   68,    0,
  170,    0,    0,    0,    0,  113,  107,    0,  106,  112,
  105,    0,  113,  129,  110,  108,  112,  109,    0,  111,
    0,  110,  108,    0,  109,    0,  111,    0,  104,   81,
    0,  113,  107,   83,  106,  112,  105,    0,    0,  104,
  110,  108,    0,  109,    0,  111,    0,    0,    0,   57,
    0,   23,   24,   25,    0,    0,    0,    0,  107,    0,
  106,    8,    0,    0,    0,    0,    0,   95,    0,   95,
  104,    0,   95,   95,   95,    0,   19,    0,    0,    0,
   95,   95,   95,   95,   95,   95,   95,    0,   92,   93,
   94,  150,    0,    0,    0,   20,  104,   20,   20,    0,
   20,  100,  101,  102,  103,    0,    0,    0,   20,   20,
   20,   20,   20,   20,   95,    0,   95,    0,   95,   95,
   95,   95,  104,    0,    0,    0,    0,   95,   95,   95,
   95,    0,   72,    0,    0,   72,   56,    0,   60,    0,
   59,    0,   68,   58,   68,    0,    0,   68,   68,   68,
   72,    0,    0,    0,    0,   68,   68,   68,   68,    0,
    0,    0,  113,    0,    0,    0,  112,  105,    0,    0,
    0,  110,  108,    0,  109,    0,  111,    0,  158,  159,
   45,   46,   47,   48,   72,  100,  101,  102,  103,  107,
    0,  106,    0,    0,    0,    0,  100,  101,  102,  103,
   56,    0,   60,    0,   59,    0,  113,   58,   54,   55,
  112,  105,    0,    0,  124,  110,  108,    0,  109,    0,
  111,   39,    0,   61,   57,    0,    0,  100,  101,  102,
  103,    0,  154,  107,  113,  106,    0,    0,  112,  105,
    0,    0,    0,  110,  108,    0,  109,    0,  111,    0,
    0,    0,    0,  100,  101,  102,  103,    0,    0,    0,
  164,  107,  113,  106,    0,    0,  112,  105,    0,    0,
    0,  110,  108,    0,  109,    0,  111,    0,    0,  100,
  101,  102,  103,    0,    0,   39,    0,   97,   57,  107,
   68,  106,    0,    0,   68,   68,    0,  104,    0,   68,
   68,  113,   68,    0,   68,  112,  105,    0,    0,    0,
  110,  108,    0,  109,    0,  111,   68,   68,    0,   68,
    0,    0,  113,    0,    0,  104,  112,    0,  107,    0,
  106,  110,  108,    0,  109,   56,  111,   60,  120,   59,
    0,   44,   58,   44,    0,   44,    0,    0,   44,  107,
    0,  106,    0,  104,   44,   45,   46,   47,   48,   72,
   49,   72,    0,   11,   72,   72,   72,    0,   50,   51,
    0,    0,    0,    0,   52,   53,   12,   13,   14,    0,
    0,   68,    0,   54,   55,    0,   56,    0,   60,    0,
   59,    0,  104,   58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  100,  101,  102,  103,    0,    0,    0,    0,   44,   45,
   46,   47,   48,   57,   49,    0,   44,   11,   44,   44,
    0,    0,   50,   51,    0,    0,    0,    0,   52,   53,
   12,   13,   14,    0,    0,    0,    0,   54,   55,    0,
    0,    0,    0,    0,  100,  101,  102,  103,   56,    0,
   60,    0,   59,    0,    0,   58,    0,    0,    0,    0,
    0,   39,    0,  115,   57,    0,    0,    0,    0,    0,
    0,    0,  100,  101,  102,  103,    0,    0,    0,    0,
   56,    0,   60,    0,   59,    0,    0,   58,    0,    0,
    0,    0,  165,    0,    0,    0,    0,    0,    0,    0,
  100,  101,  102,  103,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   68,   68,
   68,   68,    0,   39,    0,  133,   57,    0,    0,  100,
  101,  102,  103,    0,   45,   46,   47,   48,    0,   44,
   44,   44,   44,   44,   44,   44,    0,    0,    0,    0,
  100,  101,    0,   44,   44,   39,    0,    0,   57,   44,
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
   84,    0,   84,    0,    0,   84,   84,   84,    0,   89,
   62,    0,    0,   84,   84,   84,   84,    0,   90,    0,
    0,    0,   80,    0,    0,   85,   86,   87,    0,    0,
   90,   77,    0,    0,    0,   62,    0,    0,   62,   88,
   89,    0,   91,    0,    0,    0,    0,    0,    0,   62,
    0,    0,    0,   86,    0,   86,  121,  123,   86,   86,
   86,    0,    0,    0,    0,    0,    0,    0,   86,   86,
   62,    0,    0,    0,    0,    0,  130,  131,    0,    0,
    0,    0,  134,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,  145,  146,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  153,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,    0,
    0,  155,    0,    0,    0,    0,    0,    0,    0,  162,
   62,    0,  163,    0,    0,    0,    0,  167,    0,    0,
    0,    0,    0,   89,    0,   89,    0,    0,   89,   89,
   89,    0,   90,    0,   90,    0,    0,   90,   90,   90,
};
static const short yycheck[] = {                         40,
    0,   59,   33,    0,   35,   59,   37,   38,   35,   45,
   41,   42,   43,   44,   45,   40,   47,   41,   59,   35,
   44,  257,  258,   33,  256,  265,   59,   37,   59,   60,
  265,   62,   42,   43,  266,   45,  267,   47,  278,  279,
  280,  259,   59,  278,  279,  280,   42,   41,   39,   33,
   60,  260,   62,   37,   38,   59,   72,   41,   42,   43,
   44,   45,   93,   47,   41,   41,   91,   44,   67,   41,
  123,   59,   44,   64,  259,   59,   60,   33,   62,   78,
   71,   37,   38,  265,   44,   41,   42,   43,   44,   45,
   59,   47,  259,  124,   59,  272,  278,  279,  280,   91,
   99,   33,   59,   59,   60,   37,   62,   33,   59,   93,
   42,   37,   38,   59,   59,   47,   42,   43,   33,   45,
   33,   47,   37,   38,  269,  124,  261,   42,   43,  270,
   45,   38,   47,   40,   60,   42,   62,   93,   45,  259,
  124,  285,  286,  287,   59,   60,  260,   62,  123,   33,
   41,   59,  270,   37,   38,  270,    9,  156,   42,   43,
   36,   45,   19,   47,    6,   64,   -1,   -1,  124,   -1,
  169,   -1,   -1,   -1,   -1,   33,   60,   -1,   62,   37,
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
   39,   -1,   -1,  281,  282,  283,  284,   -1,  124,   -1,
   -1,   -1,   51,   -1,   -1,   54,   55,   56,   -1,   -1,
   59,   49,   -1,   -1,   -1,   64,   -1,   -1,   67,   57,
   58,   -1,   60,   -1,   -1,   -1,   -1,   -1,   -1,   78,
   -1,   -1,   -1,  268,   -1,  270,   74,   75,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,
   99,   -1,   -1,   -1,   -1,   -1,   94,   95,   -1,   -1,
   -1,   -1,  100,  101,  102,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  126,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  156,   -1,   -1,
   -1,  149,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  157,
  169,   -1,  160,   -1,   -1,   -1,   -1,  165,   -1,   -1,
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
#line 666 "y.tab.c"

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
#line 49 "factorial.y"
	{ IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i, yystack.l_mark[-2].s, 0); if(yystack.l_mark[-4].i+yystack.l_mark[-3].i != yystack.l_mark[-1].i) yyerror("Atribuição entre tipos diferentes.");}
break;
case 6:
#line 50 "factorial.y"
	{ IDnew(yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+yystack.l_mark[-2].i, yystack.l_mark[-1].s, 0); }
break;
case 7:
#line 51 "factorial.y"
	{IDnew(yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+yystack.l_mark[-2].i+32, yystack.l_mark[-1].s, 0); IDpush(); }
break;
case 8:
#line 51 "factorial.y"
	{IDreplace(yystack.l_mark[-8].i+yystack.l_mark[-7].i+yystack.l_mark[-6].i+yystack.l_mark[-5].i+32,yystack.l_mark[-4].s, p); if((yystack.l_mark[-6].i+yystack.l_mark[-5].i) != 0) {IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i, yystack.l_mark[-4].s, 0);} }
break;
case 9:
#line 51 "factorial.y"
	{ IDpop();}
break;
case 10:
#line 52 "factorial.y"
	{IDnew(yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+yystack.l_mark[-3].i+32, yystack.l_mark[-2].s, 0); IDpush();  if((yystack.l_mark[-4].i+yystack.l_mark[-3].i) != 0) {IDnew((yystack.l_mark[-4].i+yystack.l_mark[-3].i), yystack.l_mark[-2].s,0);}}
break;
case 11:
#line 52 "factorial.y"
	{IDpop();}
break;
case 12:
#line 53 "factorial.y"
	{IDnew(yystack.l_mark[-7].i+yystack.l_mark[-6].i+yystack.l_mark[-5].i+yystack.l_mark[-4].i+32, yystack.l_mark[-3].s, 0);}
break;
case 13:
#line 54 "factorial.y"
	{yyerrok; }
break;
case 16:
#line 59 "factorial.y"
	{ yyval.i = 0; }
break;
case 17:
#line 60 "factorial.y"
	{ yyval.i = 4; }
break;
case 18:
#line 63 "factorial.y"
	{ yyval.i = 0; }
break;
case 19:
#line 64 "factorial.y"
	{ yyval.i = 8; }
break;
case 20:
#line 67 "factorial.y"
	{ yyval.i = 0; }
break;
case 21:
#line 68 "factorial.y"
	{ yyval.i = 16; }
break;
case 22:
#line 71 "factorial.y"
	{ yyval.i = 0; }
break;
case 23:
#line 72 "factorial.y"
	{ yyval.i = 1; }
break;
case 24:
#line 73 "factorial.y"
	{ yyval.i = 2; }
break;
case 25:
#line 74 "factorial.y"
	{ yyval.i = 3; }
break;
case 26:
#line 77 "factorial.y"
	{ yyval.i = 1; }
break;
case 27:
#line 78 "factorial.y"
	{ yyval.i = 1; /*-$3 */ }
break;
case 28:
#line 79 "factorial.y"
	{ yyval.i = 2; }
break;
case 29:
#line 80 "factorial.y"
	{ yyval.i = 3; }
break;
case 30:
#line 81 "factorial.y"
	{ yyval.i = 3; /*-$3 */}
break;
case 31:
#line 82 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[0].s, 0)+4; }
break;
case 32:
#line 85 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[0].i; }
break;
case 33:
#line 86 "factorial.y"
	{ yyval.i = 0; }
break;
case 34:
#line 89 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i + yystack.l_mark[0].i; }
break;
case 35:
#line 92 "factorial.y"
	{ IDnew(yystack.l_mark[-2].i+yystack.l_mark[-1].i, yystack.l_mark[0].s, 0);}
break;
case 36:
#line 95 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 37:
#line 96 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[-1].i; }
break;
case 46:
#line 111 "factorial.y"
	{ nciclo++; }
break;
case 47:
#line 111 "factorial.y"
	{ nciclo--; }
break;
case 49:
#line 112 "factorial.y"
	{ nciclo++; }
break;
case 50:
#line 112 "factorial.y"
	{ nciclo--; }
break;
case 53:
#line 115 "factorial.y"
	{ if (yystack.l_mark[-1].i == 0 || yystack.l_mark[-1].i > nciclo) yyerror("Break inválido: Fora de um ciclo"); }
break;
case 55:
#line 117 "factorial.y"
	{ if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); }
break;
case 58:
#line 120 "factorial.y"
	{ yyerrok; }
break;
case 63:
#line 131 "factorial.y"
	{ yyval.i = yystack.l_mark[-2].i + yystack.l_mark[0].i; }
break;
case 64:
#line 132 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 65:
#line 135 "factorial.y"
	{ yyval.i = 1; }
break;
case 66:
#line 136 "factorial.y"
	{ yyval.i = 3; }
break;
case 67:
#line 137 "factorial.y"
	{ yyval.i = 2; }
break;
case 68:
#line 138 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 69:
#line 139 "factorial.y"
	{ yyval.i = IDsearch(yystack.l_mark[-3].s, 0, IDlevel(), 0) && (0x7); }
break;
case 70:
#line 140 "factorial.y"
	{ yyval.i = IDsearch(yystack.l_mark[-2].s, 0, IDlevel(), 0) && (0x7); }
break;
case 71:
#line 141 "factorial.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 72:
#line 142 "factorial.y"
	{ if (yystack.l_mark[-2].i != yystack.l_mark[0].i) yyerror("Atribuição entre tipos diferentes."); yyval.i = yystack.l_mark[-2].i; }
break;
case 73:
#line 143 "factorial.y"
	{ if(yystack.l_mark[0].i == 0 || yystack.l_mark[0].i == 2) yyerror("Simétrico : Tipo inválido."); yyval.i = yystack.l_mark[0].i; }
break;
case 74:
#line 144 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Incremento : Tipo inválido."); yyval.i = 1; }
break;
case 75:
#line 145 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Decremento : Tipo inválido."); yyval.i = 1; }
break;
case 76:
#line 146 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Incremento : Tipo inválido."); yyval.i = 1; }
break;
case 77:
#line 147 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Decremento : Tipo inválido."); yyval.i = 1; }
break;
case 78:
#line 148 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 79:
#line 149 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 80:
#line 150 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 81:
#line 151 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 82:
#line 152 "factorial.y"
	{ yyval.i = oper(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 83:
#line 153 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 84:
#line 154 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 85:
#line 155 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 86:
#line 156 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 87:
#line 157 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 88:
#line 158 "factorial.y"
	{ yyval.i = comp(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 89:
#line 159 "factorial.y"
	{ if(yystack.l_mark[-2].i != 1 || yystack.l_mark[0].i != 1) yyerror("Junção Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 90:
#line 160 "factorial.y"
	{ if(yystack.l_mark[-2].i != 1 || yystack.l_mark[0].i != 1) yyerror("Alternativa Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 91:
#line 161 "factorial.y"
	{ if(yystack.l_mark[0].i != 1) yyerror("Negação Lógica : Tipo inválido."); yyval.i = 1; }
break;
case 92:
#line 162 "factorial.y"
	{ if(yystack.l_mark[-1].i != 1) yyerror("Factorial : Tipo inválido."); yyval.i = 3; }
break;
case 93:
#line 163 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 94:
#line 164 "factorial.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 95:
#line 167 "factorial.y"
	{ yyval.i = IDfind(yystack.l_mark[0].s, 0); }
break;
case 96:
#line 168 "factorial.y"
	{int x = IDfind(yystack.l_mark[-3].s, 0);
                                                        if (((x & 0x4) == 4)) 
                                                              yyval.i = x - 4;
                                                        else if (((x & 0x7) == 2))
                                                              yyval.i = 1;
                                                        else yyerror("Ponteiro: Tipo inválido.");
              /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
break;
#line 1166 "y.tab.c"
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
