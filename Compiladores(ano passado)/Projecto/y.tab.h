#define NUMBER 257
#define IDENTIF 258
#define STRING 259
#define PROGRAM 260
#define MODULE 261
#define IMPORT 262
#define EXPORT 263
#define FUNCTION 264
#define VECTOR 265
#define CONST 266
#define READ 267
#define WRITE 268
#define IF 269
#define LOOP 270
#define AGAIN 271
#define NEXT 272
#define RETURN 273
#define ELIF 274
#define ELSE 275
#define ATRIB 276
#define EQ 277
#define NE 278
#define GE 279
#define LE 280
#define POWER 281
#define UAND 282
#define UMINUS 283
#define INC 284
#define DEC 285
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	long int i;			/* integer value */
	char *s;		/* symbol name or string literal */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
