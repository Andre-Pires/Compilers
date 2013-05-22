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
extern YYSTYPE yylval;
