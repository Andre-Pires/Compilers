
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 13 "yacc2.y"

    /* headers */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "node.h"
    
    /* macros */
    #define MAX_FUNCTIONS 75

    /* references */
    extern FILE *yyin;
    extern int line;

    /* aux variables */
    int i, j;
    int fi, ai; /* indexes */
    int debug;
    
    /* information data */
    int top_lvl_decl;
    typedef struct {
        char* function;
        int argsno;
        int declarations;
        int statements;
        int binary_ops;
        char* args[16];
        int value_return;
    } f_info;
    f_info info[MAX_FUNCTIONS];



/* Line 189 of yacc.c  */
#line 108 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     TYPEDEF = 260,
     INT = 261,
     CHAR = 262,
     VOID = 263,
     STRUCT = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     RETURN = 268,
     SIZEOF = 269,
     COMMA = 270,
     SEMICOLON = 271,
     PTR_OP = 272,
     LT_OP = 273,
     GT_OP = 274,
     LE_OP = 275,
     GE_OP = 276,
     ARRAY_OP = 277,
     NE_OP = 278,
     EQ_OP = 279,
     AND_OP = 280,
     OR_OP = 281,
     ADD_OP = 282,
     SUB_OP = 283,
     MULT_OP = 284,
     DIV_OP = 285,
     STRUCT_DECL_LIST = 286,
     COMPOUND = 287,
     STATE = 288,
     FUNCTION = 289,
     DECLARATION = 290,
     FUNCTION_DEFINITION = 291,
     PROGRAM = 292,
     EXPR_LIST = 293,
     TYPE_SPECIFIER = 294,
     DIRECT_DECL = 295,
     PARAM = 296,
     NEG = 297,
     EXPR = 298,
     TOPLD = 299,
     VALUE = 300,
     DECL = 301,
     DECLARATOR = 302,
     ARRAY_DECL = 303,
     IF_ELSE = 304,
     PARAM_FUNCTION = 305,
     TYPED_STR_ID = 306,
     TYPED_STR = 307
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define TYPEDEF 260
#define INT 261
#define CHAR 262
#define VOID 263
#define STRUCT 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define RETURN 268
#define SIZEOF 269
#define COMMA 270
#define SEMICOLON 271
#define PTR_OP 272
#define LT_OP 273
#define GT_OP 274
#define LE_OP 275
#define GE_OP 276
#define ARRAY_OP 277
#define NE_OP 278
#define EQ_OP 279
#define AND_OP 280
#define OR_OP 281
#define ADD_OP 282
#define SUB_OP 283
#define MULT_OP 284
#define DIV_OP 285
#define STRUCT_DECL_LIST 286
#define COMPOUND 287
#define STATE 288
#define FUNCTION 289
#define DECLARATION 290
#define FUNCTION_DEFINITION 291
#define PROGRAM 292
#define EXPR_LIST 293
#define TYPE_SPECIFIER 294
#define DIRECT_DECL 295
#define PARAM 296
#define NEG 297
#define EXPR 298
#define TOPLD 299
#define VALUE 300
#define DECL 301
#define DECLARATOR 302
#define ARRAY_DECL 303
#define IF_ELSE 304
#define PARAM_FUNCTION 305
#define TYPED_STR_ID 306
#define TYPED_STR 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 47 "yacc2.y"

      int i;
      char* s;
      struct typeNode *n;
    


/* Line 214 of yacc.c  */
#line 256 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 268 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
      61,    62,    54,    56,    65,    57,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    58,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,    67,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    15,    18,    22,
      25,    29,    31,    34,    38,    40,    42,    44,    50,    53,
      60,    68,    72,    77,    83,    86,    88,    90,    95,    99,
     104,   107,   112,   118,   126,   128,   133,   139,   143,   145,
     147,   149,   152,   155,   159,   163,   168,   170,   173,   175,
     179,   182,   187,   192,   196,   198,   201,   204,   207,   211,
     215,   219,   221,   223,   225,   227,   229,   231,   233,   235,
     237,   239,   241,   243,   245,   247,   251,   256,   260,   264,
     268,   272,   277,   280,   283,   286,   288,   290,   292,   294,
     297
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    70,    -1,    74,    -1,    74,    70,    -1,
      71,    -1,    71,    70,    -1,    75,    58,    -1,    75,    77,
      58,    -1,    75,    58,    -1,    75,    77,    58,    -1,    72,
      -1,    73,    72,    -1,    75,    77,    83,    -1,     8,    -1,
       6,    -1,     7,    -1,     9,     3,    59,    76,    60,    -1,
       9,     3,    -1,     5,     9,    59,    76,    60,     3,    -1,
       5,     9,     3,    59,    76,    60,     3,    -1,    75,    77,
      58,    -1,    75,    77,    58,    76,    -1,    75,    77,    53,
       4,    58,    -1,    54,    77,    -1,    78,    -1,     3,    -1,
       3,    61,    79,    62,    -1,     3,    61,    62,    -1,     3,
      63,    91,    64,    -1,    75,    77,    -1,    75,    77,    65,
      79,    -1,    10,    61,    88,    62,    81,    -1,    10,    61,
      88,    62,    81,    11,    82,    -1,    82,    -1,    90,    53,
      88,    58,    -1,    12,    61,    88,    62,    82,    -1,    13,
      88,    58,    -1,    80,    -1,    58,    -1,    83,    -1,    87,
      58,    -1,    59,    60,    -1,    59,    73,    60,    -1,    59,
      84,    60,    -1,    59,    73,    84,    60,    -1,    82,    -1,
      82,    84,    -1,    88,    -1,    88,    65,    85,    -1,     9,
       3,    -1,     9,     3,    65,    85,    -1,     3,    61,    85,
      62,    -1,     3,    61,    62,    -1,    86,    -1,    54,    87,
      -1,    66,    87,    -1,    67,    87,    -1,    88,    89,    90,
      -1,    88,    89,    87,    -1,    61,    88,    62,    -1,    90,
      -1,    87,    -1,    29,    -1,    30,    -1,    27,    -1,    28,
      -1,    18,    -1,    19,    -1,    24,    -1,    21,    -1,    20,
      -1,    23,    -1,    25,    -1,    26,    -1,    91,    17,    90,
      -1,    92,    63,    90,    64,    -1,    91,    56,    90,    -1,
      91,    57,    90,    -1,    91,    54,    90,    -1,    91,    55,
      90,    -1,    14,    61,    75,    62,    -1,    67,    90,    -1,
      57,    90,    -1,    56,    90,    -1,    91,    -1,     4,    -1,
      92,    -1,     3,    -1,    66,    92,    -1,    54,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,   109,   111,   113,   115,   120,   122,   127,
     129,   134,   136,   141,   146,   148,   150,   152,   154,   156,
     158,   163,   165,   167,   172,   174,   179,   181,   183,   185,
     190,   192,   197,   199,   204,   209,   211,   213,   215,   217,
     219,   221,   226,   228,   230,   232,   237,   239,   244,   246,
     248,   250,   255,   257,   262,   263,   264,   265,   269,   271,
     273,   275,   277,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   297,   299,   301,   303,   305,
     307,   309,   311,   313,   315,   317,   322,   323,   327,   328,
     329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "TYPEDEF",
  "INT", "CHAR", "VOID", "STRUCT", "IF", "ELSE", "WHILE", "RETURN",
  "SIZEOF", "COMMA", "SEMICOLON", "PTR_OP", "LT_OP", "GT_OP", "LE_OP",
  "GE_OP", "ARRAY_OP", "NE_OP", "EQ_OP", "AND_OP", "OR_OP", "ADD_OP",
  "SUB_OP", "MULT_OP", "DIV_OP", "STRUCT_DECL_LIST", "COMPOUND", "STATE",
  "FUNCTION", "DECLARATION", "FUNCTION_DEFINITION", "PROGRAM", "EXPR_LIST",
  "TYPE_SPECIFIER", "DIRECT_DECL", "PARAM", "NEG", "EXPR", "TOPLD",
  "VALUE", "DECL", "DECLARATOR", "ARRAY_DECL", "IF_ELSE", "PARAM_FUNCTION",
  "TYPED_STR_ID", "TYPED_STR", "'='", "'*'", "'/'", "'+'", "'-'", "';'",
  "'{'", "'}'", "'('", "')'", "'['", "']'", "','", "'&'", "'~'", "$accept",
  "initial", "program", "toplevel_declaration", "declaration",
  "declaration_list", "function_definition", "type_specifier",
  "struct_decl_list", "declarator", "direct_declarator", "parameter_list",
  "if_statement", "if_clause", "statement", "compound_statement",
  "statement_list", "argument_list", "direct_function", "function_call",
  "expression", "ops", "unary_expression", "unary", "value", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    61,    42,    47,    43,    45,    59,   123,
     125,    40,    41,    91,    93,    44,    38,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     3,     2,
       3,     1,     2,     3,     1,     1,     1,     5,     2,     6,
       7,     3,     4,     5,     2,     1,     1,     4,     3,     4,
       2,     4,     5,     7,     1,     4,     5,     3,     1,     1,
       1,     2,     2,     3,     3,     4,     1,     2,     1,     3,
       2,     4,     4,     3,     1,     2,     2,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     3,     3,
       3,     4,     2,     2,     2,     1,     1,     1,     1,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,    16,    14,     0,     0,     2,     5,     3,
       0,     0,    18,     1,     6,     4,    26,     0,     7,     0,
      25,     0,     0,     0,     0,     0,    24,     8,     0,    13,
       0,     0,     0,     0,    28,     0,     0,    88,    86,     0,
       0,     0,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    39,    42,     0,     0,    11,     0,     0,    38,    46,
      40,     0,    54,     0,     0,    85,    87,     0,     0,     0,
      17,    30,    27,    90,    89,    29,     0,     0,     0,     0,
      62,     0,    61,     0,     0,    55,     0,    84,    83,    56,
      57,    82,    43,    12,     0,     9,     0,    47,    44,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      19,     0,     0,    53,     0,    48,     0,     0,     0,    67,
      68,    71,    70,    72,    69,    73,    74,    65,    66,    63,
      64,    37,     0,     0,     0,     0,     0,    45,    10,     0,
      75,    79,    80,    77,    78,     0,    20,     0,    22,    31,
      50,    52,     0,     0,     0,    60,    59,    58,    81,    35,
      76,    23,     0,    49,    32,    34,    36,    51,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    55,    56,     9,    31,    32,    19,
      20,    36,    58,   164,    59,    60,    61,   114,    62,    80,
     115,   132,    82,    65,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -142
static const yytype_int16 yypact[] =
{
     257,    14,  -142,  -142,  -142,    13,    40,  -142,   257,   257,
      36,     3,    -9,  -142,  -142,  -142,   -27,     7,  -142,     5,
    -142,    -2,   257,   257,   243,    16,  -142,  -142,    39,  -142,
     257,     7,    11,    23,  -142,     7,    22,  -142,  -142,    35,
      35,    21,  -142,    25,    27,    30,   176,    41,     0,   190,
     190,  -142,  -142,     0,   204,  -142,   129,    69,  -142,   143,
    -142,    43,  -142,    42,    54,   167,    46,    50,   -51,   112,
    -142,    51,  -142,  -142,  -142,  -142,   110,   176,   176,   176,
    -142,   312,  -142,   257,     2,  -142,   190,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,    57,  -142,    60,  -142,  -142,  -142,
     176,   190,   190,   190,   190,   190,   190,   118,   127,   257,
    -142,   257,   119,  -142,    83,   254,   267,   283,   297,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,   204,    86,    25,     2,     2,  -142,  -142,   328,
    -142,  -142,  -142,  -142,  -142,    85,  -142,    92,  -142,  -142,
      87,  -142,   159,   143,   143,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,   159,  -142,   140,  -142,  -142,  -142,   143,  -142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,    71,  -142,    98,  -142,  -142,     9,   -22,    24,
    -142,    47,  -142,  -142,  -141,   146,   -45,  -137,  -142,   -24,
      82,  -142,   -28,   144,   166
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      64,    33,   108,    43,    63,   134,    21,   109,    67,    10,
      16,    94,   165,   166,    97,   163,    12,    10,    10,    37,
      38,    87,    88,    11,    85,   167,    91,   169,    64,    89,
      90,    64,    63,    35,    24,    63,    25,    57,    37,    16,
      13,    26,    43,    38,     1,     2,     3,     4,     5,    44,
      23,    45,    46,    47,    48,    68,   135,    30,    91,    71,
      90,    17,    22,    27,    28,    57,    53,    84,   136,    84,
      39,    69,    16,   140,   141,   142,   143,   144,   145,    14,
      15,    96,    40,    70,    72,    75,    76,   148,    77,    39,
      17,    78,   133,    48,    18,    49,    50,    51,    28,    52,
      99,    40,    83,    98,   157,    53,    54,   100,   156,   106,
     107,    85,    89,    43,    38,   110,   111,   137,   138,   112,
      35,   146,   150,    17,    47,    64,    64,    95,    81,    63,
      63,   147,    43,    38,     1,     2,     3,     4,     5,    44,
      64,    45,    46,    47,    63,   151,    43,    38,   158,   160,
     161,   168,   162,    44,    93,    45,    46,    47,   149,   116,
     117,   118,    43,    38,    48,    29,    49,    50,   112,    41,
       0,    79,   113,    47,     0,     0,    53,    54,     0,    43,
      38,     0,   139,    48,   101,    49,    50,    51,    28,    92,
      47,    42,     0,    37,    38,    53,    54,    48,     0,    49,
      50,    51,    28,     0,    47,    73,    74,    43,    38,    53,
      54,     0,     0,    48,    73,    49,    50,     0,    47,    74,
      79,   102,   103,   104,   105,    53,    54,     0,     0,     0,
      48,     0,    49,    50,     0,     0,     0,    79,     0,     0,
       0,     0,    53,    54,    39,     0,    49,    50,     1,     2,
       3,     4,     5,     0,     0,     0,    40,    86,    48,     0,
      49,    50,     1,     2,     3,     4,     5,     0,     0,     0,
      53,    54,   119,   120,   121,   122,     0,   123,   124,   125,
     126,   127,   128,   129,   130,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,   119,   120,   121,   122,    34,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   119,   120,   121,   122,   152,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   153,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,   154,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   128,   129,   130,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159
};

static const yytype_int16 yycheck[] =
{
      28,    23,    53,     3,    28,     3,     3,    58,    30,     0,
       3,    56,   153,   154,    59,   152,     3,     8,     9,     3,
       4,    49,    50,     9,    48,   162,    54,   168,    56,    53,
      54,    59,    56,    24,    61,    59,    63,    28,     3,     3,
       0,    17,     3,     4,     5,     6,     7,     8,     9,    10,
      59,    12,    13,    14,    54,    31,    54,    59,    86,    35,
      84,    54,    59,    58,    59,    56,    66,    67,    66,    67,
      54,    60,     3,   101,   102,   103,   104,   105,   106,     8,
       9,    57,    66,    60,    62,    64,    61,   109,    61,    54,
      54,    61,    83,    54,    58,    56,    57,    58,    59,    60,
      58,    66,    61,    60,   132,    66,    67,    53,   132,    63,
      60,   135,   136,     3,     4,     3,    65,    60,    58,     9,
     111,     3,     3,    54,    14,   153,   154,    58,    46,   153,
     154,     4,     3,     4,     5,     6,     7,     8,     9,    10,
     168,    12,    13,    14,   168,    62,     3,     4,    62,    64,
      58,    11,    65,    10,    56,    12,    13,    14,   111,    77,
      78,    79,     3,     4,    54,    19,    56,    57,     9,    25,
      -1,    61,    62,    14,    -1,    -1,    66,    67,    -1,     3,
       4,    -1,   100,    54,    17,    56,    57,    58,    59,    60,
      14,    25,    -1,     3,     4,    66,    67,    54,    -1,    56,
      57,    58,    59,    -1,    14,    39,    40,     3,     4,    66,
      67,    -1,    -1,    54,    48,    56,    57,    -1,    14,    53,
      61,    54,    55,    56,    57,    66,    67,    -1,    -1,    -1,
      54,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    54,    -1,    56,    57,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    66,    67,    54,    -1,
      56,    57,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      66,    67,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    18,    19,    20,    21,    62,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    18,    19,    20,    21,    65,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    62,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    62,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    69,    70,    71,    74,
      75,     9,     3,     0,    70,    70,     3,    54,    58,    77,
      78,     3,    59,    59,    61,    63,    77,    58,    59,    83,
      59,    75,    76,    76,    62,    75,    79,     3,     4,    54,
      66,    91,    92,     3,    10,    12,    13,    14,    54,    56,
      57,    58,    60,    66,    67,    72,    73,    75,    80,    82,
      83,    84,    86,    87,    90,    91,    92,    76,    77,    60,
      60,    77,    62,    92,    92,    64,    61,    61,    61,    61,
      87,    88,    90,    61,    67,    87,    67,    90,    90,    87,
      87,    90,    60,    72,    84,    58,    77,    84,    60,    58,
      53,    17,    54,    55,    56,    57,    63,    60,    53,    58,
       3,    65,     9,    62,    85,    88,    88,    88,    88,    18,
      19,    20,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    58,    89,    75,     3,    54,    66,    60,    58,    88,
      90,    90,    90,    90,    90,    90,     3,     4,    76,    79,
       3,    62,    65,    62,    62,    62,    87,    90,    62,    58,
      64,    58,    65,    85,    81,    82,    82,    85,    11,    82
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 86 "yacc2.y"
    { 
    switch(debug) {
            case 1:
                printf("Top level: %d declarations.\n", top_lvl_decl);
                for(i=0; i<fi; i++) {
                    printf("%s (%d): %d declarations, %d statements, %d binary operations.\n \\\\* args: ", info[i].function, info[i].argsno, info[i].declarations, info[i].statements, info[i].binary_ops);
                    for(j=(info[i].argsno-1); j>=0; j--) printf("\'%s\' ", info[i].args[j]);
                    printf("*//\n");
                }
            break;
            default:
                printf("Top level: %d declarations.\n", top_lvl_decl);
                for(i=0; i<fi; i++) {
                    printf("%s: ", info[i].function);
                    printf("%d declarations, ", info[i].declarations);
                    printf("%d statements, ", info[i].statements);
                    printf("%d binary operations.\n", info[i].binary_ops);
                }
            break;
        }
 }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 110 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); subNode(PROGRAM, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 112 "yacc2.y"
    { (yyval.n)=subNode(PROGRAM,2,(yyvsp[(1) - (2)].n),(yyvsp[(2) - (2)].n)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 114 "yacc2.y"
    { top_lvl_decl++; (yyval.n)=subNode(PROGRAM, 1, (yyvsp[(1) - (1)].n));}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 116 "yacc2.y"
    { top_lvl_decl++; (yyval.n)=subNode(PROGRAM,2,(yyvsp[(1) - (2)].n),(yyvsp[(2) - (2)].n)); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 121 "yacc2.y"
    { (yyval.n)=subNode(TOPLD, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 123 "yacc2.y"
    { (yyval.n)=subNode(TOPLD , 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 128 "yacc2.y"
    { info[fi].declarations++; (yyval.n)=subNode(DECLARATION, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 130 "yacc2.y"
    { info[fi].declarations++; (yyval.n)=subNode(DECLARATION, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 135 "yacc2.y"
    { (yyval.n)=subNode(DECL, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 137 "yacc2.y"
    { (yyval.n)=subNode(DECL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 142 "yacc2.y"
    { fi++; (yyval.n)=subNode(FUNCTION_DEFINITION, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 147 "yacc2.y"
    { (yyval.n)=nilNode(VOID); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 149 "yacc2.y"
    { (yyval.n)=nilNode(INT); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 151 "yacc2.y"
    { (yyval.n)=nilNode(CHAR); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 153 "yacc2.y"
    { (yyval.n)=subNode(STRUCT, 3, strNode(STRUCT, (yyvsp[(1) - (5)].s)), strNode(IDENTIFIER, (yyvsp[(2) - (5)].s)), (yyvsp[(4) - (5)].n)); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 155 "yacc2.y"
    { (yyval.n)=subNode(STRUCT, 2, strNode(STRUCT, (yyvsp[(1) - (2)].s)), strNode(IDENTIFIER, (yyvsp[(2) - (2)].s))); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 157 "yacc2.y"
    { (yyval.n)=subNode(TYPED_STR, 4, strNode(STRUCT, (yyvsp[(1) - (6)].s)), strNode(IDENTIFIER, (yyvsp[(2) - (6)].s)), (yyvsp[(4) - (6)].n), strNode(IDENTIFIER, (yyvsp[(6) - (6)].s))); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 159 "yacc2.y"
    { (yyval.n)=subNode(TYPED_STR_ID, 4, strNode(STRUCT, (yyvsp[(1) - (7)].s)), strNode(IDENTIFIER, (yyvsp[(2) - (7)].s)), strNode(IDENTIFIER, (yyvsp[(3) - (7)].s)), (yyvsp[(5) - (7)].n), strNode(IDENTIFIER, (yyvsp[(7) - (7)].s))); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 164 "yacc2.y"
    { (yyval.n)=subNode(STRUCT_DECL_LIST, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 166 "yacc2.y"
    { (yyval.n)=subNode(STRUCT_DECL_LIST, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 168 "yacc2.y"
    { (yyval.n)=subNode(STRUCT_DECL_LIST, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].i)); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 173 "yacc2.y"
    { (yyval.n)=(yyvsp[(2) - (2)].n); /** $$=subNode(DECLARATOR, 1, $2); /**/ }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 175 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); /** $$=subNode(DECLARATOR, 1, $1); /**/ }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 180 "yacc2.y"
    { /** $$=strNode(IDENTIFIER, $1); /**/ }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 182 "yacc2.y"
    { info[fi].function=(char *)(yyvsp[(1) - (4)].s); (yyval.n)=subNode(DIRECT_DECL, 2, strNode(IDENTIFIER, (yyvsp[(1) - (4)].s)), (yyvsp[(3) - (4)].n)); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 184 "yacc2.y"
    { info[fi].function=(char *)(yyvsp[(1) - (3)].s); (yyval.n)=subNode(DIRECT_DECL, 1, strNode(IDENTIFIER, (yyvsp[(1) - (3)].s))); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 186 "yacc2.y"
    { (yyval.n)=subNode(ARRAY_DECL, 2, strNode(IDENTIFIER, (yyvsp[(1) - (4)].s)), (yyvsp[(3) - (4)].n)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 191 "yacc2.y"
    { info[fi].args[ai]=(char *)(yyvsp[(2) - (2)].n); info[fi].argsno++; (yyval.n)=subNode(PARAM, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 193 "yacc2.y"
    { ai++; info[fi].args[ai]=(char *)(yyvsp[(2) - (4)].n); info[fi].argsno++; (yyval.n)=subNode(PARAM, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); ai=0; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 198 "yacc2.y"
    { (yyval.n)=subNode(IF, 3, strNode(IF, (yyvsp[(1) - (5)].s)), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 200 "yacc2.y"
    { (yyval.n)=subNode(IF_ELSE, 5, strNode(IF, (yyvsp[(1) - (7)].s)), (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), strNode(ELSE, (yyvsp[(6) - (7)].s)), (yyvsp[(7) - (7)].n)); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 205 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 210 "yacc2.y"
    { info[fi].statements++; (yyval.n)=subNode('=', 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 212 "yacc2.y"
    { info[fi].statements++; (yyval.n)=subNode(WHILE, 3, strNode(WHILE, (yyvsp[(1) - (5)].s)), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 214 "yacc2.y"
    { info[fi].statements++; (yyval.n)=subNode(RETURN, 2, strNode(RETURN, (yyvsp[(1) - (3)].s)), (yyvsp[(2) - (3)].n)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 216 "yacc2.y"
    { info[fi].statements++; (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 218 "yacc2.y"
    { info[fi].statements++; (yyval.n)=nilNode(';'); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 220 "yacc2.y"
    { (yyval.n)=subNode(COMPOUND, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 222 "yacc2.y"
    { info[fi].statements++; (yyval.n)=(yyvsp[(1) - (2)].n); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 227 "yacc2.y"
    { }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 229 "yacc2.y"
    { (yyval.n)=subNode(DECL, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 231 "yacc2.y"
    { (yyval.n)=subNode(STATE, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 233 "yacc2.y"
    { (yyval.n)=subNode(COMPOUND, 2, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 238 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 240 "yacc2.y"
    { (yyval.n)=subNode(STATE, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 245 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 247 "yacc2.y"
    { (yyval.n)=subNode(EXPR_LIST, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 249 "yacc2.y"
    { (yyval.n)=subNode(EXPR_LIST, 2, strNode(STRUCT, (yyvsp[(1) - (2)].s)), strNode(IDENTIFIER, (yyvsp[(2) - (2)].s))); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 251 "yacc2.y"
    { (yyval.n)=subNode(EXPR_LIST, 3, strNode(STRUCT, (yyvsp[(1) - (4)].s)), strNode(IDENTIFIER, (yyvsp[(2) - (4)].s)), (yyvsp[(4) - (4)].n)); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 256 "yacc2.y"
    { (yyval.n)=subNode(FUNCTION, 2, strNode(IDENTIFIER, (yyvsp[(1) - (4)].s)), (yyvsp[(3) - (4)].n)); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 258 "yacc2.y"
    { (yyval.n)=subNode(FUNCTION, 1, strNode(IDENTIFIER, (yyvsp[(1) - (3)].s))); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 262 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 263 "yacc2.y"
    { (yyval.n)=subNode('*', 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 264 "yacc2.y"
    { (yyval.n)=subNode('&', 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 265 "yacc2.y"
    { (yyval.n)=subNode('~', 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 270 "yacc2.y"
    { info[fi].binary_ops++; (yyval.n)=subNode(EXPR, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 272 "yacc2.y"
    { info[fi].binary_ops++; (yyval.n)=subNode(EXPR, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 274 "yacc2.y"
    { (yyval.n)=(yyvsp[(2) - (3)].n); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 276 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 278 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 282 "yacc2.y"
    { (yyval.n)=strNode(MULT_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 283 "yacc2.y"
    { (yyval.n)=strNode(DIV_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 284 "yacc2.y"
    { (yyval.n)=strNode(ADD_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 285 "yacc2.y"
    { (yyval.n)=strNode(SUB_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 286 "yacc2.y"
    { (yyval.n)=strNode(LT_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 287 "yacc2.y"
    { (yyval.n)=strNode(GT_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 288 "yacc2.y"
    { (yyval.n)=strNode(EQ_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 289 "yacc2.y"
    { (yyval.n)=strNode(GE_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 290 "yacc2.y"
    { (yyval.n)=strNode(LE_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 291 "yacc2.y"
    { (yyval.n)=strNode(NE_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 292 "yacc2.y"
    { (yyval.n)=strNode(AND_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 293 "yacc2.y"
    { (yyval.n)=strNode(OR_OP, (yyvsp[(1) - (1)].s)); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 298 "yacc2.y"
    { (yyval.n)=subNode(EXPR, 3, (yyvsp[(1) - (3)].n), strNode(PTR_OP, (yyvsp[(2) - (3)].s)), (yyvsp[(3) - (3)].n)); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 300 "yacc2.y"
    { (yyval.n)=subNode(EXPR, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 302 "yacc2.y"
    { info[fi].binary_ops++; (yyval.n) = subNode(ADD_OP, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 304 "yacc2.y"
    { info[fi].binary_ops++; (yyval.n) = subNode(SUB_OP, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 306 "yacc2.y"
    { info[fi].binary_ops++; (yyval.n) = subNode(MULT_OP, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 308 "yacc2.y"
    { info[fi].binary_ops++; (yyval.n) = subNode(DIV_OP, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 310 "yacc2.y"
    { (yyval.n)=subNode(SIZEOF, 2, strNode(SIZEOF, (yyvsp[(1) - (4)].s)), (yyvsp[(3) - (4)].n)); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 312 "yacc2.y"
    { (yyval.n) = subNode('~', 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 314 "yacc2.y"
    { (yyval.n)=subNode(NEG,1, (yyvsp[(2) - (2)].n)); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 316 "yacc2.y"
    { (yyval.n)=(yyvsp[(2) - (2)].n); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 318 "yacc2.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 322 "yacc2.y"
    { (yyval.n)=intNode(CONSTANT, (yyvsp[(1) - (1)].i)); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 323 "yacc2.y"
    { (yyval.n)=subNode(VALUE, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 327 "yacc2.y"
    { (yyval.n)=strNode(IDENTIFIER, (yyvsp[(1) - (1)].s)); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 328 "yacc2.y"
    { (yyval.n)=subNode('&', 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 329 "yacc2.y"
    { (yyval.n)=subNode('*', 1, (yyvsp[(2) - (2)].n)); }
    break;



/* Line 1455 of yacc.c  */
#line 2306 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 332 "yacc2.y"


int yyerror(char* msg){
    fprintf(stderr, "%s, line %d\n", msg, line);
    return 1;
}

/* code for traversing (dfs) the syntax tree and generating three-address code */
int main(){
    do { yyparse(); }
    while(!feof(yyin));
    return 0;
}
/*** The End ***/

