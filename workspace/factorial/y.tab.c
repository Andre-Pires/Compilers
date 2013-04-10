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
#line 10 "factorial.y"
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
#line 39 "y.tab.c"

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
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    3,    3,    3,    3,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    7,    7,    5,    5,    8,    8,    9,
    9,    6,    6,    6,    6,   10,   10,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   14,
   14,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   13,   13,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    6,    5,    7,    6,    5,    4,
    6,    5,    5,    4,    6,    5,    4,    3,    5,    4,
    1,    1,    1,    1,    2,    3,    2,    2,    2,    4,
    3,    3,    2,    2,    3,    1,    2,    2,    3,    2,
    3,    2,    3,    3,    4,    1,    2,    4,    6,    5,
    8,    8,   10,   10,    2,    1,    5,    5,    4,    3,
    1,    1,    1,    1,    1,    4,    3,    3,    2,    2,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    1,    4,
};
static const short yydefred[] = {                         0,
   24,    0,    0,   21,   22,   23,    0,    0,    3,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,    0,    0,    0,    0,   17,    0,
    0,   20,    0,    0,   25,   28,   29,   27,    0,    0,
    0,    0,    0,   10,   14,    0,   19,    0,    0,    9,
   13,    0,   12,   16,    0,   26,    0,   32,   38,    0,
    0,    0,    0,    6,   11,   15,    0,    5,    8,   62,
   63,    0,   64,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   56,    0,    0,    0,
   46,    0,    0,   39,   30,   34,    0,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   71,   89,
    0,   69,   90,    0,   40,   43,    0,    0,   44,   47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   88,   55,   72,   73,    0,    0,   35,
    0,    0,    0,    0,    0,    0,    0,    0,   67,   41,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,    0,   92,    0,
    0,    0,    0,    0,   59,    0,    0,   50,    0,    0,
   57,   58,   49,    0,    0,    0,    0,    0,    0,   51,
    0,   52,    0,    0,    0,   53,   54,
};
static const short yydgoto[] = {                          7,
    8,    9,   41,   25,   42,   87,   63,   43,   89,   90,
   91,   92,  102,  142,
};
static const short yysindex[] = {                       -96,
    0, -166, -200,    0,    0,    0,    0,  -96,    0,  -26,
 -200,  -20,    7,    0,  -27, -244,    9,  -23, -238,  -12,
 -228, -151,  -34,    0,  -22,    5,   14, -226,    0,  -13,
   15,    0,   -9,   37,    0,    0,    0,    0, -207,  -62,
   29,   35,   38,    0,    0,   22,    0,   30,   46,    0,
    0,   36,    0,    0,   44,    0,  534,    0,    0, -165,
  -62, -200,   60,    0,    0,    0,   51,    0,    0,    0,
    0,  -39,    0,  379,  724, -148,   41,   43, -148, -148,
 -148,  379,  379, -148,  379,    0,    0,   61,  575,  635,
    0,  130,  -29,    0,    0,    0, -200,    0,  379,  379,
  158, -267, -134,   50, -135, -114, -113,    0,    0,    0,
  547,    0,    0,  280,    0,    0,   91,  672,    0,    0,
  379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
  379,  379,  379,    0,    0,    0,    0,  379,  379,    0,
  506,  -21,  343,  724,  379,  379,   52,   65,    0,    0,
    0,  169,  169,   93,   93,  540,  547,  169,  169,  180,
  180,  121,  121,  121,  385,  506,    0,  379,    0, -109,
  413,   55,  103,  105,    0,  506,  724,    0,  379,  379,
    0,    0,    0,   86,  114,  724,  379,  724,  379,    0,
  441,    0,  457,  724,  724,    0,    0,
};
static const short yyrindex[] = {                       165,
    0,    0,    0,    0,    0,    0,    0,  166,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  119,
    0,    0,  139,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  122,    0,  144,    0,    0,    0,    0,    0,    0,    0,
    0,  -33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  473,    0,    0,    0,    0,    0,    0,    0,
    0,   25,    0,   -3,    0,    0,    0,    0,    0,    0,
  253,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   81,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1013, 1036, 1137, 1183,  511,  649, 1092, 1112,  929,
  996,  842,  909,  970,    0,  640,    0,    0,    0,  605,
    0,    0,    0,    0,    0,   98,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  178,  221,  323,    0,  -37,    0,  -14,    0,   99,
  214, 1348, 1246,    0,
};
#define YYTABLESIZE 1537
static const short yytable[] = {                         91,
   99,   91,   58,   91,   91,  138,   40,   91,   91,   91,
   91,   91,   23,   91,   26,   16,   23,  136,  137,  167,
   31,   19,  168,   95,  139,   91,   91,   23,   91,   91,
   34,   24,   49,   91,   91,   29,   44,   91,   91,   91,
   91,   91,   88,   91,   23,   50,   32,   96,   21,   53,
   28,  100,   56,   23,   23,   91,   91,   65,   91,   91,
   57,   65,   65,   45,    1,   65,   65,   65,   65,   65,
   60,   65,   47,   51,  117,   61,   23,    4,    5,    6,
   64,   62,  140,   65,   65,   23,   65,  134,   65,   91,
   91,  133,  126,   94,   68,   54,  131,  129,    1,  130,
   11,  132,   69,   97,   66,   35,   36,   37,   38,   98,
  104,    4,    5,    6,  128,   39,  127,   65,  134,  115,
   91,   61,  133,  126,   61,  134,  145,  131,  129,  133,
  130,  106,  132,  107,  131,  129,  146,  130,   60,  132,
  100,   60,  147,  148,  173,  128,  134,  127,   65,  150,
  133,  126,  128,  134,  127,  131,  129,  174,  130,  177,
  132,  181,  134,  182,    2,    1,  133,  126,    1,    2,
    3,  131,  129,  128,  130,  127,  132,   33,  125,   36,
   31,    4,    5,    6,   37,   14,    0,  118,  135,  128,
  134,  127,    0,    0,  133,  126,    0,    0,    0,  131,
  129,  134,  130,    0,  132,  133,    0,    0,    0,  125,
  131,  129,  134,  130,    0,  132,  133,  128,    0,  127,
   10,  131,   12,   13,    0,    0,  132,    0,   10,    0,
    1,   17,   15,    0,   91,    0,   91,  125,   18,   91,
   91,   91,    0,    4,    5,    6,    0,   91,   91,   91,
   91,   91,   91,  125,    0,  136,  137,    0,   91,   22,
    0,    0,  139,   22,   91,   20,   91,   27,   91,   91,
   91,   91,    0,    0,   22,    0,    0,   91,   91,   91,
   91,  125,    0,    0,    0,    0,    0,   59,  103,    0,
   87,   22,   65,   87,   65,    0,   87,   65,   65,   65,
   22,   22,    0,  120,    0,   65,   65,   65,   65,    0,
    0,   87,  134,    0,    0,    0,  133,  126,    0,    0,
  149,  131,  129,   22,  130,    0,  132,    0,  179,  180,
    0,  120,   22,    0,    0,  121,  122,  123,  124,  128,
   30,  127,   33,    0,    0,   87,    0,    0,   46,   48,
    0,    0,    0,   52,    0,  186,   55,  170,  187,    0,
    0,    0,    0,    0,    0,    0,  121,  122,  123,  124,
    0,   67,    0,  121,  122,  134,   87,    0,    0,  133,
  126,    0,    0,  188,  131,  129,  189,  130,    0,  132,
  183,    0,    0,    0,  121,  122,  123,  124,    0,  190,
    0,  192,  128,  125,  127,    0,    0,  196,  197,    0,
  121,  122,  123,  124,    0,    0,   81,  134,   85,    0,
   84,  133,  126,   83,    0,  144,  131,  129,    0,  130,
    0,  132,    0,    0,    0,  169,    0,    0,  121,  122,
  123,  124,    0,  175,  128,  134,  127,    0,    0,  133,
  126,    0,    0,    0,  131,  129,    0,  130,    0,  132,
    0,    0,    0,    0,    0,    0,  125,    0,    0,    0,
    0,  178,  128,  134,  127,    0,    0,  133,  126,    0,
    0,    0,  131,  129,    0,  130,    0,  132,    0,  134,
    0,    0,    0,  133,  126,    0,    0,    0,  131,  129,
  128,  130,  127,  132,   82,   65,    0,    0,  125,   65,
   65,    0,    0,    0,   65,   65,  128,   65,  127,   65,
   87,    0,   87,    0,    0,   87,   87,   87,    0,    0,
    0,   65,   65,    0,   65,    0,  125,    0,  134,    0,
    0,    0,  133,  126,    0,    0,    0,  131,  129,    0,
  130,   86,  132,    0,   86,    0,    0,    0,    0,    0,
  121,  122,  123,  124,  125,  128,    0,  127,    0,   86,
    0,   81,  134,   85,    0,   84,  133,  126,   83,  134,
  125,  131,  129,  133,  130,    0,  132,    0,  131,  129,
    0,  130,    0,  132,    0,    0,   65,    0,    0,  128,
    0,  127,    0,   86,    0,    0,  128,    0,  127,    0,
    0,    0,   81,    0,   85,    0,   84,    0,    0,   83,
    0,    0,    0,  121,  122,  123,  124,    0,    0,  125,
    0,    0,    0,    0,   86,   70,   71,   72,   73,    0,
    0,    0,   48,    0,   48,    0,   48,    0,    0,   48,
    0,    0,    0,    0,    0,    0,   57,    0,   86,   82,
    0,    0,    0,   79,   80,  121,  122,  123,  124,    0,
    0,    0,   81,    0,   85,    0,   84,    0,    0,   83,
   68,    0,    0,   68,    0,    0,   85,    0,    0,   85,
    0,    0,   85,  121,  122,  123,  124,   57,   68,  116,
   82,    0,    0,    0,    0,    0,    0,   85,    0,   81,
  194,   85,    0,   84,    0,    0,   83,    0,    0,    0,
    0,  121,  122,  123,  124,    0,  195,   48,    0,   48,
   48,    0,   68,    0,    0,    0,    0,  121,  122,  123,
  124,   85,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   65,   65,   65,   65,   57,    0,  119,
   82,   81,    0,   85,    0,   84,    0,    0,   83,    0,
    0,    0,   85,    0,    0,    0,    0,    0,   86,    0,
   86,    0,    0,   86,   86,   86,  121,  122,  123,  124,
   70,   71,   72,   73,   57,   74,  151,   82,    1,    0,
    0,    0,    0,   75,   76,    0,    0,    0,    0,   77,
   78,    4,    5,    6,    0,    0,    0,    0,   79,   80,
  121,  122,  123,  124,    0,    0,    0,  121,  122,  123,
  124,   70,   71,   72,   73,    0,   74,    0,    0,    1,
    0,    0,    0,    0,   75,   76,   57,    0,    0,   82,
   77,   78,    4,    5,    6,    0,    0,    0,    0,   79,
   80,   48,   48,   48,   48,   48,   48,    0,    0,    0,
    0,    0,    0,    0,   48,   48,    0,    0,   74,   74,
   48,   48,   74,   74,   74,   74,   74,    0,   74,   48,
   48,   70,   71,   72,   73,    0,   74,    0,    0,    0,
   74,   74,    0,   74,   75,   76,    0,   68,    0,   68,
   77,   78,   68,   68,   68,    0,   85,    0,   85,   79,
   80,   85,   85,   85,    0,    0,    0,    0,   70,   71,
   72,   73,    0,   74,   74,    0,    0,    0,    0,    0,
    0,   75,   76,    0,    0,   75,   75,   77,   78,   75,
   75,   75,   75,   75,    0,   75,   79,   80,    0,    0,
    0,    0,    0,    0,    0,   74,   77,   75,   75,   77,
   75,   77,   77,   77,    0,    0,    0,    0,    0,    0,
   70,   71,   72,   73,    0,   74,    0,   77,   77,    0,
   77,    0,    0,   75,   76,    0,    0,    0,    0,   77,
   78,   75,    0,    0,    0,    0,   76,   76,   79,   80,
   76,   76,   76,   76,   76,    0,   76,    0,    0,    0,
    0,   77,    0,    0,    0,    0,    0,    0,   76,   76,
    0,   76,   75,   78,    0,    0,   78,    0,   78,   78,
   78,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   83,    0,   77,   83,   78,   78,   83,   78,    0,    0,
    0,    0,   76,    0,    0,    0,    0,    0,    0,    0,
    0,   83,   83,   84,   83,    0,   84,    0,    0,   84,
    0,    0,    0,    0,    0,    0,    0,    0,   78,    0,
    0,    0,    0,   76,   84,   84,    0,   84,    0,    0,
    0,    0,    0,    0,    0,   83,    0,    0,    0,   74,
    0,   74,    0,    0,   74,   74,   74,    0,    0,   78,
    0,    0,   74,   74,   74,   74,    0,    0,   84,   79,
    0,    0,   79,    0,    0,   79,   83,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   80,
   79,   79,   80,   79,    0,   80,    0,    0,    0,   84,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   80,   80,    0,   80,   81,    0,   75,   81,   75,    0,
   81,   75,   75,   75,   79,    0,    0,    0,    0,   75,
   75,   75,   75,    0,    0,   81,   77,    0,   77,    0,
    0,   77,   77,   77,   80,    0,    0,    0,    0,   77,
   77,   77,   77,    0,    0,   79,    0,    0,    0,    0,
   82,    0,    0,   82,    0,    0,   82,    0,    0,   81,
    0,    0,    0,    0,    0,   80,    0,   76,    0,   76,
    0,   82,   76,   76,   76,    0,    0,    0,    0,    0,
   76,   76,   76,   76,    0,    0,    0,    0,    0,    0,
   81,    0,    0,   78,    0,   78,    0,    0,   78,   78,
   78,    0,    0,    0,    0,   82,   78,   78,   78,   78,
   83,    0,   83,    0,    0,   83,   83,   83,    0,    0,
    0,    0,    0,   83,   83,   83,   83,    0,    0,    0,
    0,    0,   93,   84,    0,   84,   82,    0,   84,   84,
   84,    0,    0,    0,    0,    0,   84,   84,   84,   84,
   93,  105,    0,    0,  108,  109,  110,    0,    0,  113,
    0,    0,    0,    0,   93,   93,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,   79,    0,   93,   79,   79,   79,    0,    0,    0,
    0,    0,   79,   79,   79,   79,    0,    0,    0,   80,
    0,   80,    0,    0,   80,   80,   80,    0,    0,   93,
    0,    0,   80,   80,   80,   80,    0,    0,    0,    0,
    0,    0,    0,    0,   81,    0,   81,    0,    0,   81,
   81,   81,    0,    0,    0,    0,    0,    0,    0,   81,
   81,  101,   93,    0,    0,    0,    0,    0,    0,  111,
  112,   93,  114,   93,    0,    0,    0,    0,    0,   93,
   93,    0,    0,    0,    0,    0,  141,  143,    0,    0,
   82,    0,   82,    0,    0,   82,   82,   82,    0,    0,
    0,    0,    0,    0,    0,   82,   82,    0,  152,  153,
  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,
  164,    0,    0,    0,    0,  165,  166,    0,    0,    0,
    0,    0,  171,  172,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  176,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  184,  185,    0,    0,
    0,    0,    0,    0,  191,    0,  193,
};
static const short yycheck[] = {                         33,
   40,   35,   40,   37,   38,   35,   41,   41,   42,   43,
   44,   45,   40,   47,  259,   42,   40,  285,  286,   41,
  259,   42,   44,   61,  292,   59,   60,   40,   62,   33,
  259,   59,  259,   37,   38,   59,   59,   41,   42,   43,
   44,   45,   57,   47,   40,   59,   59,   62,   42,   59,
   42,   91,  260,   40,   40,   59,   60,   33,   62,   93,
  123,   37,   38,   59,  265,   41,   42,   43,   44,   45,
   42,   47,   59,   59,   89,   41,   40,  278,  279,  280,
   59,   44,   97,   59,   60,   40,   62,   33,   59,   93,
  124,   37,   38,  259,   59,   59,   42,   43,  265,   45,
  267,   47,   59,   44,   59,  257,  258,  259,  260,   59,
  259,  278,  279,  280,   60,  267,   62,   93,   33,   59,
  124,   41,   37,   38,   44,   33,  261,   42,   43,   37,
   45,   91,   47,   91,   42,   43,  272,   45,   41,   47,
   91,   44,  257,  257,   93,   60,   33,   62,  124,   59,
   37,   38,   60,   33,   62,   42,   43,   93,   45,  269,
   47,   59,   33,   59,    0,    0,   37,   38,  265,  266,
  267,   42,   43,   60,   45,   62,   47,   59,  124,   41,
   59,  278,  279,  280,   41,    8,   -1,   89,   59,   60,
   33,   62,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,
   43,   33,   45,   -1,   47,   37,   -1,   -1,   -1,  124,
   42,   43,   33,   45,   -1,   47,   37,   60,   -1,   62,
    0,   42,    2,    3,   -1,   -1,   47,   -1,    8,   -1,
  265,   11,  259,   -1,  268,   -1,  270,  124,  259,  273,
  274,  275,   -1,  278,  279,  280,   -1,  281,  282,  283,
  284,  285,  286,  124,   -1,  285,  286,   -1,  292,  287,
   -1,   -1,  292,  287,  268,  259,  270,  259,  272,  273,
  274,  275,   -1,   -1,  287,   -1,   -1,  281,  282,  283,
  284,  124,   -1,   -1,   -1,   -1,   -1,  259,   75,   -1,
   38,  287,  268,   41,  270,   -1,   44,  273,  274,  275,
  287,  287,   -1,   90,   -1,  281,  282,  283,  284,   -1,
   -1,   59,   33,   -1,   -1,   -1,   37,   38,   -1,   -1,
   41,   42,   43,  287,   45,   -1,   47,   -1,  274,  275,
   -1,  118,  287,   -1,   -1,  281,  282,  283,  284,   60,
   18,   62,   20,   -1,   -1,   93,   -1,   -1,   26,   27,
   -1,   -1,   -1,   31,   -1,  270,   34,  144,  273,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   -1,   49,   -1,  281,  282,   33,  124,   -1,   -1,   37,
   38,   -1,   -1,  270,   42,   43,  273,   45,   -1,   47,
  177,   -1,   -1,   -1,  281,  282,  283,  284,   -1,  186,
   -1,  188,   60,  124,   62,   -1,   -1,  194,  195,   -1,
  281,  282,  283,  284,   -1,   -1,   38,   33,   40,   -1,
   42,   37,   38,   45,   -1,  268,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   93,   -1,   -1,  281,  282,
  283,  284,   -1,   59,   60,   33,   62,   -1,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   59,   60,   33,   62,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   33,
   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
   60,   45,   62,   47,  126,   33,   -1,   -1,  124,   37,
   38,   -1,   -1,   -1,   42,   43,   60,   45,   62,   47,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,  124,   -1,   33,   -1,
   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   41,   47,   -1,   44,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,  124,   60,   -1,   62,   -1,   59,
   -1,   38,   33,   40,   -1,   42,   37,   38,   45,   33,
  124,   42,   43,   37,   45,   -1,   47,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  124,   -1,   -1,   60,
   -1,   62,   -1,   93,   -1,   -1,   60,   -1,   62,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,  124,
   -1,   -1,   -1,   -1,  124,  257,  258,  259,  260,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,  126,
   -1,   -1,   -1,  285,  286,  281,  282,  283,  284,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,
   41,   -1,   -1,   44,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,  281,  282,  283,  284,  123,   59,  125,
  126,   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,   38,
  270,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,   -1,  270,  123,   -1,  125,
  126,   -1,   93,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,  123,   -1,  125,
  126,   38,   -1,   40,   -1,   42,   -1,   -1,   45,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,  268,   -1,
  270,   -1,   -1,  273,  274,  275,  281,  282,  283,  284,
  257,  258,  259,  260,  123,  262,  125,  126,  265,   -1,
   -1,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,
  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,  286,
  281,  282,  283,  284,   -1,   -1,   -1,  281,  282,  283,
  284,  257,  258,  259,  260,   -1,  262,   -1,   -1,  265,
   -1,   -1,   -1,   -1,  270,  271,  123,   -1,   -1,  126,
  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,
  286,  257,  258,  259,  260,  261,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  270,  271,   -1,   -1,   37,   38,
  276,  277,   41,   42,   43,   44,   45,   -1,   47,  285,
  286,  257,  258,  259,  260,   -1,  262,   -1,   -1,   -1,
   59,   60,   -1,   62,  270,  271,   -1,  268,   -1,  270,
  276,  277,  273,  274,  275,   -1,  268,   -1,  270,  285,
  286,  273,  274,  275,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,   -1,  262,   93,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,   -1,   -1,   37,   38,  276,  277,   41,
   42,   43,   44,   45,   -1,   47,  285,  286,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   38,   59,   60,   41,
   62,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   -1,  262,   -1,   59,   60,   -1,
   62,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,
  277,   93,   -1,   -1,   -1,   -1,   37,   38,  285,  286,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,  124,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   38,   -1,  124,   41,   59,   60,   44,   62,   -1,   -1,
   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   38,   62,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,
   -1,   -1,   -1,  124,   59,   60,   -1,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,  268,
   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,  124,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,   93,   38,
   -1,   -1,   41,   -1,   -1,   44,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,
   59,   60,   41,   62,   -1,   44,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   -1,   62,   38,   -1,  268,   41,  270,   -1,
   44,  273,  274,  275,   93,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   59,  268,   -1,  270,   -1,
   -1,  273,  274,  275,   93,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,  124,   -1,  268,   -1,  270,
   -1,   59,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,   -1,   -1,   93,  281,  282,  283,  284,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,
   -1,   -1,   57,  268,   -1,  270,  124,   -1,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   75,   76,   -1,   -1,   79,   80,   81,   -1,   -1,   84,
   -1,   -1,   -1,   -1,   89,   90,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,
   -1,  270,   -1,  118,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,  268,
   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,  144,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,
  284,   74,  177,   -1,   -1,   -1,   -1,   -1,   -1,   82,
   83,  186,   85,  188,   -1,   -1,   -1,   -1,   -1,  194,
  195,   -1,   -1,   -1,   -1,   -1,   99,  100,   -1,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  283,  284,   -1,  121,  122,
  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,
  133,   -1,   -1,   -1,   -1,  138,  139,   -1,   -1,   -1,
   -1,   -1,  145,  146,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  168,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  179,  180,   -1,   -1,
   -1,   -1,   -1,   -1,  187,   -1,  189,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
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
"LE","EQ","NE","INC","DEC","ATRIB","ADDR","POINTER","IFX","UMINUS","\":=\"",
};
static const char *yyrule[] = {
"$accept : ficheiro",
"ficheiro : declaracoes",
"ficheiro :",
"declaracoes : declaracao",
"declaracoes : declaracoes declaracao",
"declaracao : PUBLIC tipo '*' IDENTIF init ';'",
"declaracao : tipo '*' IDENTIF init ';'",
"declaracao : PUBLIC CONST tipo '*' IDENTIF init ';'",
"declaracao : CONST tipo '*' IDENTIF init ';'",
"declaracao : PUBLIC tipo IDENTIF init ';'",
"declaracao : tipo IDENTIF init ';'",
"declaracao : PUBLIC CONST tipo IDENTIF init ';'",
"declaracao : CONST tipo IDENTIF init ';'",
"declaracao : PUBLIC tipo '*' IDENTIF ';'",
"declaracao : tipo '*' IDENTIF ';'",
"declaracao : PUBLIC CONST tipo '*' IDENTIF ';'",
"declaracao : CONST tipo '*' IDENTIF ';'",
"declaracao : PUBLIC tipo IDENTIF ';'",
"declaracao : tipo IDENTIF ';'",
"declaracao : PUBLIC CONST tipo IDENTIF ';'",
"declaracao : CONST tipo IDENTIF ';'",
"tipo : INTEGER",
"tipo : STRING",
"tipo : NUMBER",
"tipo : VOID",
"init : ATRIB INT",
"init : ATRIB CONST STRN",
"init : ATRIB STRN",
"init : ATRIB NUM",
"init : ATRIB IDENTIF",
"init : '(' parametros ')' corpo",
"init : '(' parametros ')'",
"init : '(' ')' corpo",
"init : '(' ')'",
"pars : ',' parametro",
"pars : pars ',' parametro",
"parametros : parametro",
"parametros : parametro pars",
"parametro : tipo IDENTIF",
"parametro : tipo '*' IDENTIF",
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
"instrucao : DO instrucao WHILE expressao ';'",
"instrucao : FOR left_value IN expressao UPTO expressao DO instrucao",
"instrucao : FOR left_value IN expressao DOWNTO expressao DO instrucao",
"instrucao : FOR left_value IN expressao UPTO expressao STEP expressao DO instrucao",
"instrucao : FOR left_value IN expressao DOWNTO expressao STEP expressao DO instrucao",
"instrucao : expressao ';'",
"instrucao : corpo",
"instrucao : BREAK '[' INT ']' ';'",
"instrucao : CONTINUE '[' INT ']' ';'",
"instrucao : left_value '#' expressao ';'",
"expressoes : expressoes ',' expressao",
"expressoes : expressao",
"expressao : INT",
"expressao : NUM",
"expressao : STRN",
"expressao : left_value",
"expressao : IDENTIF '(' expressoes ')'",
"expressao : '(' expressao ')'",
"expressao : left_value \":=\" expressao",
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
#line 160 "factorial.y"

int main(int argc, char *argv[])
{
  while (yyparse())
    ;
  return 0;
}

/*
void yyerror(char *s)
{
  printf("%s\n", s);
*/
#line 680 "y.tab.c"

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
