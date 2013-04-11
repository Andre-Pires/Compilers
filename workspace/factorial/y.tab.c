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
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   14,   14,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   13,   13,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    6,    5,    7,    6,    5,    4,
    6,    5,    5,    4,    6,    5,    4,    3,    5,    4,
    1,    1,    1,    1,    2,    3,    2,    2,    2,    4,
    3,    3,    2,    2,    3,    1,    2,    2,    3,    2,
    3,    2,    3,    3,    4,    1,    2,    4,    6,    5,
    8,    8,   10,   10,    2,    1,    3,    3,    2,    2,
    4,    3,    1,    1,    1,    1,    1,    4,    3,    3,
    3,    2,    2,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    1,    4,
};
static const short yydefred[] = {                         0,
   24,    0,    0,   21,   22,   23,    0,    0,    3,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,    0,    0,    0,    0,   17,    0,
    0,   20,    0,    0,   25,   28,   29,   27,    0,    0,
    0,    0,    0,   10,   14,    0,   19,    0,    0,    9,
   13,    0,   12,   16,    0,   26,    0,   32,   38,    0,
    0,    0,    0,    6,   11,   15,    0,    5,    8,   64,
   65,    0,   66,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   56,    0,    0,    0,
   46,    0,    0,   39,   30,   34,    0,    7,    0,    0,
    0,    0,    0,    0,    0,    0,   59,    0,   60,   73,
   74,   92,    0,   72,   93,    0,   40,   43,    0,    0,
   44,   47,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   91,   55,   75,   76,    0,
    0,   35,   69,    0,    0,    0,    0,    0,    0,   57,
   58,   70,   41,   45,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   68,
    0,   95,    0,    0,    0,   61,    0,    0,   50,    0,
    0,   49,    0,    0,    0,    0,    0,    0,   51,    0,
   52,    0,    0,    0,   53,   54,
};
static const short yydgoto[] = {                          7,
    8,    9,   41,   25,   42,   87,   63,   43,   89,   90,
   91,   92,  102,  145,
};
static const short yysindex[] = {                      -106,
    0,   87, -142,    0,    0,    0,    0, -106,    0,  -39,
 -142,  -35,  -23,    0,  -25, -234,  -21,  -16, -229,    5,
 -228,  166,  -19,    0,  -24,   16,   33, -218,    0,   -7,
   37,    0,   -6,   42,    0,    0,    0,    0, -212,  -64,
    7,   20,   21,    0,    0,   15,    0,   22,   49,    0,
    0,   31,    0,    0,   36,    0,  538,    0,    0, -165,
  -64, -142,   55,    0,    0,    0,   47,    0,    0,    0,
    0,  -20,    0,  516,  696, -148,  -58,  -46, -148, -148,
 -148,  516,  516, -148,  516,    0,    0,   54,  573,  640,
    0,  120,  -29,    0,    0,    0, -142,    0,  335,  516,
  148, -269, -146,   26, -156,   65,    0,   69,    0,    0,
    0,    0,   67,    0,    0,  159,    0,    0,   73,  662,
    0,    0,  516,  516,  516,  516,  516,  516,  516,  516,
  516,  516,  516,  516,  516,    0,    0,    0,    0,  516,
  516,    0,    0,  510,    6,  285,  696,  516,  516,    0,
    0,    0,    0,    0,  268,  268,  489,  489,  185,   67,
  268,  268,  192,  192,  101,  101,  101,  510,  375,    0,
  516,    0, -130,  411,   60,    0,  510,  696,    0,  516,
  516,    0,   88,  109,  696,  516,  696,  516,    0,  441,
    0,  467,  696,  696,    0,    0,
};
static const short yyrindex[] = {                       140,
    0,    0,    0,    0,    0,    0,    0,  141,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   84,
    0,    0,  103,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   86,    0,  114,    0,    0,    0,    0,    0,    0,    0,
    0,  -33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  478,    0,    0,    0,    0,    0,    0,    0,
    0,   25,    0,   -5,    0,    0,    0,    0,    0,    0,
    0,    0,  950,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  890, 1043,  608, 1088, 1178, 1111,
 1063, 1138, 1006, 1026,  933,  959,  986,  871,    0,    0,
    0,    0,  603,    0,    0,    0,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  156,  386,  255,    0,  -17,    0,  -11,    0,   77,
 1079, 1343, 1312,    0,
};
#define YYTABLESIZE 1531
static const short yytable[] = {                         94,
  107,   94,   16,   94,   94,  141,   19,   94,   94,   94,
   94,   94,  109,   94,   23,  138,  139,  140,   21,   99,
   28,   40,   58,   23,   26,   94,   94,   94,   94,   31,
   34,   94,   94,   24,   44,   94,   94,   94,   94,   94,
   49,   94,   29,   95,   23,   88,  170,   56,   60,  171,
   96,   50,   53,   94,   94,   23,   94,   67,   57,   94,
   61,   67,   67,   32,   62,   67,   67,   67,   67,   67,
  100,   67,   23,   64,   45,   63,   23,  119,   63,   62,
   65,   23,   62,   67,   67,  142,   67,   94,   23,   68,
   94,   47,  136,   94,   69,   51,  135,  128,   97,  136,
   54,  133,  131,  135,  132,   98,  134,   66,  133,  131,
  104,  132,  117,  134,  148,  149,  100,   67,   94,  130,
  136,  129,    1,  150,  135,  128,  130,  151,  129,  133,
  131,  153,  132,  136,  134,    4,    5,    6,  178,    2,
    1,  136,   33,   36,   31,  135,  128,  130,   67,  129,
  133,  131,  136,  132,   37,  134,  135,  128,    1,    2,
    3,  133,  131,   14,  132,  120,  134,    0,  130,    0,
  129,    4,    5,    6,    0,    0,    0,    0,  137,  130,
  136,  129,    0,  127,  135,  128,    0,    0,    0,  133,
  131,  136,  132,    0,  134,  135,  128,    0,  106,  152,
  133,  131,    0,  132,    0,  134,    0,  130,    0,  129,
  108,  127,    0,    0,    0,    0,    0,  136,  130,   15,
  129,  135,  128,   18,  136,    0,  133,  131,  135,  132,
    0,  134,  127,  133,   94,   20,   94,   27,  134,   94,
   94,   94,    0,  127,  130,    1,  129,   94,   94,   94,
   94,   94,   94,   94,    0,  138,  139,  140,    4,    5,
    6,   22,   94,    0,   94,   59,   94,   94,   94,   94,
   22,  127,   30,    0,   33,   94,   94,   94,   94,    0,
   46,   48,  127,    0,    0,   52,    0,    0,   55,    0,
    0,   22,   67,    0,   67,    0,    0,   67,   67,   67,
  136,    0,   22,   67,  135,   67,   67,   67,   67,  133,
  131,    0,  132,    0,  134,    0,    0,  136,    0,   22,
    0,  135,  128,   22,    0,    0,  133,  131,   22,  132,
    0,  134,    0,  180,  181,   22,    0,    0,    0,    0,
  123,  124,  125,  126,  130,    0,  129,  123,  124,  125,
  126,    1,    0,   11,    0,    0,    0,  185,    0,    0,
  186,    0,    0,    0,    4,    5,    6,    0,  123,  124,
  125,  126,   81,    0,   85,  143,   84,  172,  187,   83,
    0,  188,    0,    0,    0,   10,    0,   12,   13,  123,
  124,  125,  126,   10,    0,    0,   17,    0,    0,    0,
  123,  124,  125,  126,    0,    0,    0,  136,  127,    0,
    0,  135,  128,    0,    0,  147,  133,  131,    0,  132,
    0,  134,   35,   36,   37,   38,    0,    0,  123,  124,
  125,  126,   39,  176,  130,    0,  129,    0,    0,  123,
  124,  125,  126,  136,    0,    0,    0,  135,  128,    0,
    0,    0,  133,  131,    0,  132,    0,  134,    0,    0,
   82,    0,    0,    0,    0,  123,  124,  125,  126,  179,
  130,    0,  129,  136,    0,    0,    0,  135,  128,    0,
    0,    0,  133,  131,    0,  132,    0,  134,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  127,  136,
  130,    0,  129,  135,  128,    0,    0,    0,  133,  131,
   67,  132,    0,  134,   67,   67,    0,    0,    0,   67,
   67,  136,   67,    0,   67,  135,  130,    0,  129,    0,
  133,  131,    0,  132,  127,  134,   67,   67,    0,   67,
    0,    0,  136,    0,    0,    0,  135,  128,  130,    0,
  129,  133,  131,   81,  132,   85,  134,   84,    0,    0,
   83,    0,    0,    0,  127,  123,  124,  125,  126,  130,
    0,  129,    0,    0,    0,   81,    0,   85,    0,   84,
    0,    0,   83,    0,    0,    0,    0,    0,    0,    0,
  127,   70,   71,   72,   73,    0,    0,    0,    0,    0,
    0,   67,    0,    0,    0,    0,    0,    0,    0,    0,
   81,    0,   85,    0,   84,    0,    0,   83,    0,   79,
   80,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  127,    0,    0,    0,    0,    0,    0,
   48,   82,   48,    0,   48,   84,    0,   48,   84,    0,
    0,   84,    0,    0,    0,  123,  124,  125,  126,    0,
   57,    0,   86,   82,    0,    0,   84,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   81,    0,   85,
    0,   84,    0,    0,   83,    0,    0,    0,    0,    0,
    0,  123,  124,  125,  126,   57,    0,  118,   82,   81,
   84,   85,    0,   84,    0,    0,   83,    0,    0,    0,
  193,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  123,  124,  125,  126,   48,    0,   48,   48,    0,
    0,   84,    0,   81,    0,   85,  194,   84,    0,    0,
   83,    0,    0,    0,    0,    0,    0,  123,  124,  125,
  126,    0,    0,    0,    0,    0,    0,    0,   67,   67,
   67,   67,   57,    0,  121,   82,    0,    0,    0,  123,
  124,    0,   70,   71,   72,   73,    0,    0,    0,    0,
    0,    0,    0,    0,   57,    0,  154,   82,    0,    0,
  123,  124,  125,  126,   70,   71,   72,   73,    0,   74,
   79,   80,    1,    0,    0,    0,    0,   75,   76,    0,
    0,    0,    0,   77,   78,    4,    5,    6,   57,    0,
    0,   82,   79,   80,    0,    0,    0,    0,    0,   70,
   71,   72,   73,    0,   74,    0,    0,    1,    0,    0,
    0,    0,   75,   76,    0,    0,    0,    0,   77,   78,
    4,    5,    6,    0,    0,    0,    0,   79,   80,   48,
   48,   48,   48,   48,   48,    0,    0,    0,    0,    0,
    0,    0,   48,   48,    0,   84,    0,   84,   48,   48,
   84,   84,   84,    0,    0,    0,    0,   48,   48,    0,
   84,   84,    0,    0,    0,    0,   70,   71,   72,   73,
    0,   74,    0,    0,    0,    0,    0,    0,    0,   75,
   76,   71,    0,    0,   71,   77,   78,    0,   70,   71,
   72,   73,    0,   74,   79,   80,    0,   86,    0,   71,
   86,   75,   76,   86,    0,    0,    0,   77,   78,    0,
    0,    0,    0,    0,    0,    0,   79,   80,   86,   86,
    0,   86,   70,   71,   72,   73,    0,   74,    0,    0,
    0,    0,    0,   71,    0,   75,   76,    0,    0,   77,
   77,   77,   78,   77,   77,   77,   77,   77,    0,   77,
   79,   80,   86,    0,    0,    0,    0,   90,    0,    0,
   90,   77,   77,   90,   77,   78,   78,    0,    0,   78,
   78,   78,   78,   78,    0,   78,    0,    0,   90,    0,
    0,    0,    0,   86,    0,    0,    0,   78,   78,    0,
   78,    0,   79,   79,    0,   77,   79,   79,   79,   79,
   79,    0,   79,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   90,   80,   79,   79,   80,   79,   80,   80,
   80,   78,    0,    0,    0,    0,   77,    0,    0,    0,
    0,    0,    0,   81,   80,   80,   81,   80,   81,   81,
   81,    0,    0,   90,    0,    0,    0,    0,   79,    0,
   87,    0,   78,   87,   81,   81,   87,   81,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   80,    0,
   82,   87,   87,   82,   87,    0,   82,    0,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,   81,    0,
    0,   82,   82,    0,   82,   85,    0,    0,   85,   80,
    0,   85,    0,    0,    0,   87,    0,    0,   71,    0,
   71,    0,    0,   71,   71,   71,   85,    0,   88,   81,
    0,   88,    0,  103,   88,   82,    0,   86,    0,   86,
    0,    0,   86,   86,   86,    0,   87,    0,  122,   88,
   86,   86,   86,   86,    0,   83,    0,    0,   83,    0,
   85,   83,    0,    0,    0,    0,   82,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   83,   83,  122,   83,
   77,    0,   77,   88,    0,   77,   77,   77,    0,    0,
    0,   85,    0,   77,   77,   77,   77,   90,   89,   90,
    0,   89,   90,   90,   90,  173,   78,    0,   78,    0,
   83,   78,   78,   78,   88,    0,   89,    0,    0,   78,
   78,   78,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   79,    0,   79,  182,    0,   79,   79,
   79,   83,    0,  189,    0,  191,   79,   79,   79,   79,
   89,  195,  196,   80,    0,   80,    0,    0,   80,   80,
   80,    0,    0,    0,    0,    0,   80,   80,   80,   80,
    0,    0,    0,   81,    0,   81,    0,    0,   81,   81,
   81,   89,    0,    0,    0,    0,   81,   81,   81,   81,
   87,    0,   87,    0,    0,   87,   87,   87,    0,    0,
    0,    0,    0,   87,   87,   87,   87,    0,    0,    0,
   82,    0,   82,    0,    0,   82,   82,   82,    0,    0,
    0,    0,    0,   82,   82,   82,   82,    0,    0,    0,
    0,    0,    0,    0,    0,   85,    0,   85,    0,    0,
   85,   85,   85,    0,    0,    0,    0,    0,   93,    0,
   85,   85,    0,    0,    0,    0,    0,    0,   88,    0,
   88,    0,    0,   88,   88,   88,   93,  105,    0,    0,
  110,  111,  112,    0,    0,  115,    0,    0,    0,    0,
   93,   93,    0,    0,    0,   83,    0,   83,    0,    0,
   83,   83,   83,    0,    0,    0,  101,    0,   83,   83,
   83,   83,    0,    0,  113,  114,    0,  116,    0,    0,
    0,   93,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  144,  146,    0,    0,   89,    0,   89,    0,    0,
   89,   89,   89,    0,    0,    0,    0,    0,   93,    0,
    0,    0,    0,    0,    0,  155,  156,  157,  158,  159,
  160,  161,  162,  163,  164,  165,  166,  167,    0,    0,
    0,    0,  168,  169,    0,    0,    0,    0,    0,   93,
  174,  175,    0,    0,    0,    0,   93,    0,   93,    0,
    0,    0,    0,    0,   93,   93,    0,    0,    0,    0,
    0,    0,    0,  177,    0,    0,    0,    0,    0,    0,
    0,    0,  183,  184,    0,    0,    0,    0,  190,    0,
  192,
};
static const short yycheck[] = {                         33,
   59,   35,   42,   37,   38,   35,   42,   41,   42,   43,
   44,   45,   59,   47,   40,  285,  286,  287,   42,   40,
   42,   41,   40,   40,  259,   59,   60,   33,   62,  259,
  259,   37,   38,   59,   59,   41,   42,   43,   44,   45,
  259,   47,   59,   61,   40,   57,   41,  260,   42,   44,
   62,   59,   59,   59,   60,   40,   62,   33,  123,   93,
   41,   37,   38,   59,   44,   41,   42,   43,   44,   45,
   91,   47,   40,   59,   59,   41,   40,   89,   44,   41,
   59,   40,   44,   59,   60,   97,   62,   93,   40,   59,
  124,   59,   33,  259,   59,   59,   37,   38,   44,   33,
   59,   42,   43,   37,   45,   59,   47,   59,   42,   43,
  259,   45,   59,   47,  261,  272,   91,   93,  124,   60,
   33,   62,  265,   59,   37,   38,   60,   59,   62,   42,
   43,   59,   45,   33,   47,  278,  279,  280,  269,    0,
    0,   33,   59,   41,   59,   37,   38,   60,  124,   62,
   42,   43,   33,   45,   41,   47,   37,   38,  265,  266,
  267,   42,   43,    8,   45,   89,   47,   -1,   60,   -1,
   62,  278,  279,  280,   -1,   -1,   -1,   -1,   59,   60,
   33,   62,   -1,  124,   37,   38,   -1,   -1,   -1,   42,
   43,   33,   45,   -1,   47,   37,   38,   -1,  257,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   60,   -1,   62,
  257,  124,   -1,   -1,   -1,   -1,   -1,   33,   60,  259,
   62,   37,   38,  259,   33,   -1,   42,   43,   37,   45,
   -1,   47,  124,   42,  268,  259,  270,  259,   47,  273,
  274,  275,   -1,  124,   60,  265,   62,  281,  282,  283,
  284,  285,  286,  287,   -1,  285,  286,  287,  278,  279,
  280,  287,  268,   -1,  270,  259,  272,  273,  274,  275,
  287,  124,   18,   -1,   20,  281,  282,  283,  284,   -1,
   26,   27,  124,   -1,   -1,   31,   -1,   -1,   34,   -1,
   -1,  287,  268,   -1,  270,   -1,   -1,  273,  274,  275,
   33,   -1,  287,   49,   37,  281,  282,  283,  284,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   33,   -1,  287,
   -1,   37,   38,  287,   -1,   -1,   42,   43,  287,   45,
   -1,   47,   -1,  274,  275,  287,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   60,   -1,   62,  281,  282,  283,
  284,  265,   -1,  267,   -1,   -1,   -1,  270,   -1,   -1,
  273,   -1,   -1,   -1,  278,  279,  280,   -1,  281,  282,
  283,  284,   38,   -1,   40,   41,   42,   93,  270,   45,
   -1,  273,   -1,   -1,   -1,    0,   -1,    2,    3,  281,
  282,  283,  284,    8,   -1,   -1,   11,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   33,  124,   -1,
   -1,   37,   38,   -1,   -1,  268,   42,   43,   -1,   45,
   -1,   47,  257,  258,  259,  260,   -1,   -1,  281,  282,
  283,  284,  267,   59,   60,   -1,   62,   -1,   -1,  281,
  282,  283,  284,   33,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
  126,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   59,
   60,   -1,   62,   33,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   33,
   60,   -1,   62,   37,   38,   -1,   -1,   -1,   42,   43,
   33,   45,   -1,   47,   37,   38,   -1,   -1,   -1,   42,
   43,   33,   45,   -1,   47,   37,   60,   -1,   62,   -1,
   42,   43,   -1,   45,  124,   47,   59,   60,   -1,   62,
   -1,   -1,   33,   -1,   -1,   -1,   37,   38,   60,   -1,
   62,   42,   43,   38,   45,   40,   47,   42,   -1,   -1,
   45,   -1,   -1,   -1,  124,  281,  282,  283,  284,   60,
   -1,   62,   -1,   -1,   -1,   38,   -1,   40,   -1,   42,
   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,  257,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   -1,   -1,   45,   -1,  285,
  286,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   38,  126,   40,   -1,   42,   38,   -1,   45,   41,   -1,
   -1,   44,   -1,   -1,   -1,  281,  282,  283,  284,   -1,
  123,   -1,  125,  126,   -1,   -1,   59,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,  123,   -1,  125,  126,   38,
   93,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,
  270,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,  123,   -1,  125,  126,   -1,
   -1,  124,   -1,   38,   -1,   40,  270,   42,   -1,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,
  283,  284,  123,   -1,  125,  126,   -1,   -1,   -1,  281,
  282,   -1,  257,  258,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,
  281,  282,  283,  284,  257,  258,  259,  260,   -1,  262,
  285,  286,  265,   -1,   -1,   -1,   -1,  270,  271,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  123,   -1,
   -1,  126,  285,  286,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  280,   -1,   -1,   -1,   -1,  285,  286,  257,
  258,  259,  260,  261,  262,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,   -1,  268,   -1,  270,  276,  277,
  273,  274,  275,   -1,   -1,   -1,   -1,  285,  286,   -1,
  283,  284,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
   -1,  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,
  271,   41,   -1,   -1,   44,  276,  277,   -1,  257,  258,
  259,  260,   -1,  262,  285,  286,   -1,   38,   -1,   59,
   41,  270,  271,   44,   -1,   -1,   -1,  276,  277,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,   59,   60,
   -1,   62,  257,  258,  259,  260,   -1,  262,   -1,   -1,
   -1,   -1,   -1,   93,   -1,  270,  271,   -1,   -1,   37,
   38,  276,  277,   41,   42,   43,   44,   45,   -1,   47,
  285,  286,   93,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   59,   60,   44,   62,   37,   38,   -1,   -1,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   59,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   37,   38,   -1,   93,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   38,   59,   60,   41,   62,   43,   44,
   45,   93,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   38,   59,   60,   41,   62,   43,   44,
   45,   -1,   -1,  124,   -1,   -1,   -1,   -1,   93,   -1,
   38,   -1,  124,   41,   59,   60,   44,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,
   38,   59,   60,   41,   62,   -1,   44,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,
   -1,   59,   60,   -1,   62,   38,   -1,   -1,   41,  124,
   -1,   44,   -1,   -1,   -1,   93,   -1,   -1,  268,   -1,
  270,   -1,   -1,  273,  274,  275,   59,   -1,   38,  124,
   -1,   41,   -1,   75,   44,   93,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,   -1,  124,   -1,   90,   59,
  281,  282,  283,  284,   -1,   38,   -1,   -1,   41,   -1,
   93,   44,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,  120,   62,
  268,   -1,  270,   93,   -1,  273,  274,  275,   -1,   -1,
   -1,  124,   -1,  281,  282,  283,  284,  268,   41,  270,
   -1,   44,  273,  274,  275,  147,  268,   -1,  270,   -1,
   93,  273,  274,  275,  124,   -1,   59,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,  178,   -1,  273,  274,
  275,  124,   -1,  185,   -1,  187,  281,  282,  283,  284,
   93,  193,  194,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,  124,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   57,   -1,
  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,
  270,   -1,   -1,  273,  274,  275,   75,   76,   -1,   -1,
   79,   80,   81,   -1,   -1,   84,   -1,   -1,   -1,   -1,
   89,   90,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,
  273,  274,  275,   -1,   -1,   -1,   74,   -1,  281,  282,
  283,  284,   -1,   -1,   82,   83,   -1,   85,   -1,   -1,
   -1,  120,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   99,  100,   -1,   -1,  268,   -1,  270,   -1,   -1,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  147,   -1,
   -1,   -1,   -1,   -1,   -1,  123,  124,  125,  126,  127,
  128,  129,  130,  131,  132,  133,  134,  135,   -1,   -1,
   -1,   -1,  140,  141,   -1,   -1,   -1,   -1,   -1,  178,
  148,  149,   -1,   -1,   -1,   -1,  185,   -1,  187,   -1,
   -1,   -1,   -1,   -1,  193,  194,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  171,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  180,  181,   -1,   -1,   -1,   -1,  186,   -1,
  188,
};
#define YYFINAL 7
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
"instrucao : BREAK INT ';'",
"instrucao : CONTINUE INT ';'",
"instrucao : BREAK ';'",
"instrucao : CONTINUE ';'",
"instrucao : left_value '#' expressao ';'",
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
#line 163 "factorial.y"
/*
int main()
{
  while (yyparse())
    ;
  return 0;
}

void yyerror(char *s)
{
  printf("%s\n", s);
*/
#line 682 "y.tab.c"

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
