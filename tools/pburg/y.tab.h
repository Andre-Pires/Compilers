#define TERMINAL 257
#define START 258
#define PPERCENT 259
#define ID 260
#define INCLUDE 261
#define BLOCK 262
#define INT 263
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int n;
	char *string;
	Tree tree;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
