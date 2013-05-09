%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include <stdarg.h>
#include "node.h"
#include "tabid.h"
#include "y.tab.h"

extern void yyerror(char *s);
extern void program(int enter, Node *body), declare(char *name, int value);
extern void function(char *name, int enter, Node *body);
int pos; /* local variable offset (no functions inside a function) */
int lbl; /* label counter for generated labels */
char *mklbl(int n); /* generate counter based label */ 

int p, nciclo, nivel;
int pos = 0;
%}

%union {
	int i;			/* integer value */
  double d;    /* double value */
	char *s;		/* symbol name or string literal */
  Node * n;
};

%token <i> INT
%token <d> NUM
%token <s> IDENTIF STRN
%token WHILE IF END RETURN VOID PUBLIC CONST THEN ELSE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE INTEGER STRING NUMBER
%token ELSE GE LE EQ NE INC DEC ATRIB ADDR POINTER IFX

%token CALL NEG FACT AND OR PROG ADD SUBT MUL DIV LT GT MOD PARAMS PARS2 PARS INTRS PINTR INTR DECL DECLS INIT NIL PNTR EXPS EXP MALL BODY JZ ETIQ LABEL JNZ JMP

%nonassoc IFX
%nonassoc ELSE
%right ATRIB
%left '|'
%left '&'
%nonassoc '~'
%left EQ NE
%left GE LE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc  POINTER ADDR '!' UMINUS INC DEC
%nonassoc '(' ')' '[' ']'

%type <n> left_value init expressao expressoes corpo corpop instrucao instrucoes pars2 declaracoes declaracao tipo ptr cons pub parametro parametros  updown step
%%

ficheiro  : declaracoes                      {Node * n = uniNode(PROG, $1); program(-pos, $1); printNode(n, 0, yynames); /*yyselect(n);*/}
          | /*empty*/
          ;

declaracoes  : declaracao                     {$$ = $1;}
             | declaracoes declaracao         {$$ = binNode(DECLS, $1, $2);}
             ;

declaracao  : pub cons tipo ptr IDENTIF init ';'            { IDnew($1->info+$2->info+$3->info+$4->info, $5, 0); declare($5, $6->info);
                                                              $$=binNode(INIT, strNode(IDENTIF, $5), $6);
                                                              $$->info = $1->info+$2->info+$3->info+$4->info; 
                                                              if($3->info+$4->info != 4) {
                                                                if($3->info+$4->info != $6->info) yyerror("Atribuição entre tipos diferentes.");}}

            | pub cons tipo ptr IDENTIF ';'                 { $$=uniNode(DECL, strNode(IDENTIF, $5)); IDnew($1->info+$2->info+$3->info+$4->info, $5, 0); function($5, -pos, 0); pos = 0;}

            | pub cons tipo ptr IDENTIF '('   {IDnew($1->info+$2->info+$3->info+$4->info+32, $5, 0); IDpush(); } parametros ')'
                                              {IDreplace($1->info+$2->info+$3->info+$4->info+32,$5, $8->info); //ver isto, devia passar parametros
                                               if(($3->info+$4->info) != 0) {IDnew($3->info+$4->info, $5, 0);} pos = 0;}  corpop ';'
                                              {$$=binNode(DECL, strNode(IDENTIF, $5), binNode(BODY, $8, $11)); IDpop(); /* usar o YYselect à entrada do corpo*/ function($5, -pos, $11); pos = 0; } 

            | pub cons tipo ptr IDENTIF '(' ')' {IDnew($1->info+$2->info+$3->info+$4->info+32, $5, 0); IDpush();
                                                  if(($3->info+$4->info) != 0) {IDnew(($3->info+$4->info), $5,0);} pos = 0;}  corpo ';' 
                                                  { $$=binNode(DECL, strNode(IDENTIF, $5), $9); IDpop(); function($5, -pos, $9); pos = 0;}

            | pub cons tipo ptr IDENTIF '(' ')' ';'    {$$=binNode(DECL, strNode(IDENTIF, $5), nilNode(NIL)); IDnew($1->info+$2->info+$3->info+$4->info+32, $5, 0); function($5, -pos, 0); pos = 0;} 
            | error ';'                                {yyerrok; }
            ;

corpop :                     { $$ = nilNode(NIL); }
       | corpo               { $$ = $1; }
       ;

ptr   :                      { $$= nilNode(NIL); $$->info = 0; }
      | '*'                  { $$= uniNode(PNTR, 0); $$->info = 4; }
      ;

cons  :                      { $$= nilNode(NIL); $$->info = 0;}
      | CONST                { $$= uniNode(CONST, 0); $$->info = 8; }
      ;

pub   :                      { $$= nilNode(NIL); $$->info = 0;}
      | PUBLIC               { $$= uniNode(VOID, 0); $$->info = 16; }
      ;

tipo  : VOID                 { $$ = uniNode(VOID, 0); $$->info = 0; }
      | INTEGER              { $$ = uniNode(INTEGER, 0); $$->info = 1; }
      | STRING               { $$ = uniNode(STRING, 0); $$->info = 2; }
      | NUMBER               { $$ = uniNode(NUMBER, 0); $$->info = 3; }
      ;

init  : ATRIB INT            { $$ = intNode(INT, $2); $$->info = 1;}
      | ATRIB '-' INT        { $$ = intNode(INT, -$3); $$->info = 1;}
      | ATRIB cons STRN      { $$ = strNode(STRN, $3); $$->info = $2->info +2;}
      | ATRIB NUM            { $$ = realNode(NUM, $2); $$->info = 3;}
      | ATRIB '-' NUM        { $$ = realNode(NUM, -$3); $$->info = 3;}
      | ATRIB IDENTIF        { $$ = strNode(IDENTIF, $2); $$->info = IDfind($2, 0)+4;}
      ;


parametros  : parametros ',' parametro          { $$ = binNode(PARAMS, $1, $3); $$->info = $1->info + $3->info; }
            | parametro                         { $$ = uniNode(PARAMS, $1); $$->info = $1->info;}
            ;

parametro : tipo ptr IDENTIF                    { $$ = strNode(IDENTIF, $3); IDnew($1->info+$2->info, $3, 0); $$->info = $1->info + $2->info;} // parametros da funcao sao positivos e as variaveis locais negativas
          ;

pars2 : parametro ';'                           { $$ = $1; }
      | pars2 parametro ';'                     { $$ = binNode(PARS2, $1, $2); $$->info = $1->info + $2->info; }
      ;

corpo : '{' '}'                                 {$$ = nilNode(NIL);}
      | '{' pars2 '}'                           {$$ = uniNode(PARS, $2);}
      | '{' instrucoes '}'                      {$$ = uniNode(INTRS, $2);}
      | '{' pars2 instrucoes '}'                {$$ = binNode(PINTR, $2 , $3);}
      ;

instrucoes : instrucao                          {$$ = $1;}
           | instrucoes instrucao               {$$ = binNode(INTRS, $1, $2);}
           ;

instrucao : IF expressao THEN instrucao %prec IFX                      { int lbl1 = ++lbl;
                                                                        $$ = seqNode(IFX, 3,
                                                                        binNode(JZ,$2, strNode(ETIQ, mklbl(lbl1))),
                                                                        $4, /* instr */
                                                                        strNode(LABEL, mklbl(lbl1)));
                                                                       }
          | IF expressao THEN instrucao ELSE instrucao                { int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                        $$ = seqNode(ELSE, 6,
                                                                        binNode(JZ,$2, strNode(ETIQ, mklbl(lbl1))),
                                                                        $4, /* instr */
                                                                        strNode(JMP, mklbl(lbl2)),
                                                                        strNode(LABEL, mklbl(lbl1)),
                                                                        $6, /* else */
                                                                        strNode(LABEL, mklbl(lbl2)));
                                                                      }

          | DO { nciclo++; } instrucao { nciclo--; } WHILE expressao ';'      { int lbl1 = ++lbl, lbl2 = ++lbl;
                                                                                $$ = seqNode(WHILE, 5,
                                                                                strNode(JMP, mklbl(lbl1)),
                                                                                strNode(LABEL, mklbl(lbl2)),
                                                                                $3, /* instr */
                                                                                strNode(LABEL, mklbl(lbl1)),
                                                                                binNode(JNZ,$6, strNode(ETIQ, mklbl(lbl2))));
                                                                              }

          | FOR left_value IN expressao updown expressao step DO { nciclo++; } instrucao { nciclo--; }  // fazer o for

          | expressao ';'                                 {$$ = $1;}
          | corpo                                         {$$ = $1;}
          | BREAK INT ';'                                 { if ($2 == 0 || $2 > nciclo) yyerror("Break inválido: Fora de um ciclo"); {$$ = uniNode(BREAK, intNode(INT, $2));}}
          | CONTINUE INT ';'                              {$$ = uniNode(CONTINUE, intNode(INT, $2));}
          | BREAK ';'                                     { if (nciclo == 0) yyerror("Break inválido: Fora de um ciclo"); $$ = uniNode(BREAK, 0);}
          | CONTINUE ';'                                  {$$ = uniNode(CONTINUE, 0);}  
          | left_value '#' expressao ';'                  {$$ = binNode(MALL, $1, $3); $$->info = $1->info;}
          | error ';'                                     { yyerrok; }
          ;

updown  : UPTO                                        { $$ = uniNode(UPTO, 0); }
        | DOWNTO                                      { $$ = uniNode(DOWNTO, 0);}
        ;

step    :                                              { $$ = nilNode(NIL);}
        | STEP expressao                               { $$ = uniNode(STEP, $2); }
        ;

expressoes  : expressoes ',' expressao                { $$ = binNode(EXPS, $1 ,$3);}
            | expressao                               { $$ = $1; }
            ;

expressao : INT                                       { $$ = intNode(INT, $1); $$->info = 1; }
          | NUM                                       { $$ = realNode(NUM, $1); $$->info = 3;}
          | STRN                                      { $$ = strNode(STRN, $1); $$->info = 2;}
          | left_value                                { $$ = $1;}
          | IDENTIF '(' expressoes ')'                { int n; n = IDfind($1, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) {$$ = binNode(CALL, strNode(IDENTIF, $1), $3); $$->info = n;} else {$$ = binNode(CALL, strNode(IDENTIF, $1), $3); $$->info = IDsearch($1, 0, IDlevel(), 0) & (0x7);}}    /* fazer o search no nivel 0 para nao confundir a funcao com a variavel */
          | IDENTIF '(' ')'                           { int n; n = IDfind($1, 0) & (0x7); printf("%d\n",n); if(n != -1 && n == 4) {$$ = uniNode(CALL, strNode(IDENTIF, $1)); $$->info = n;} else {$$ = uniNode(CALL, strNode(IDENTIF, $1)); $$->info = IDsearch($1, 0, IDlevel(), 0) & (0x7);}}                                                                                      
          | '(' expressao ')'                         { $$ = $2; }
          | left_value ATRIB expressao                { if($1->info != 4){if ($1->info != $3->info) yyerror("Atribuição entre tipos diferentes.");} $$ = binNode(ATRIB, $1, $3);  $$->info = $3->info;}
          | '-' expressao %prec UMINUS                { if($2->info == 0 || $2->info == 2) yyerror("Simétrico : Tipo inválido"); $$ = uniNode(UMINUS, $2); $$->info = $2->info;}
          | DEC left_value                            { if($2->info != 1) yyerror("Decremento : Tipo inválido"); $$ = binNode(DEC, nilNode(NIL), $2); $$->info = 1;}
          | INC left_value                            { if($2->info != 1) yyerror("Incremento : Tipo inválido"); $$ = binNode(INC, nilNode(NIL), $2); $$->info = 1;}
          | left_value INC                            { if($1->info != 1) yyerror("Incremento : Tipo inválido"); $$ = binNode(INC, nilNode(NIL), $1); $$->info = 1;}
          | left_value DEC                            { if($1->info != 1) yyerror("Decremento : Tipo inválido"); $$ = binNode(DEC, nilNode(NIL), $1); $$->info = 1;}
          | expressao '*' expressao                   { $$ = binNode(MUL, $1, $3); $$->info = oper($1, $3); }
          | expressao '/' expressao                   { $$ = binNode(DIV, $1, $3); $$->info = oper($1, $3); }
          | expressao '%' expressao                   { $$ = binNode(MOD, $1, $3);  $$->info = oper($1, $3); }
          | expressao '+' expressao                   { $$ = binNode(ADD, $1, $3);  $$->info = oper($1, $3); }   
          | expressao '-' expressao                   { $$ = binNode(SUBT, $1, $3); $$->info = oper($1, $3); }   
          | expressao '>' expressao                   { $$ = binNode(GT, $1, $3); $$->info = comp($1, $3); }
          | expressao '<' expressao                   { $$ = binNode(LT, $1, $3); $$->info = comp($1, $3); }
          | expressao EQ expressao                    { $$ = binNode(EQ, $1, $3); $$->info = comp($1, $3); }
          | expressao NE expressao                    { $$ = binNode(NE, $1, $3); $$->info = comp($1, $3); }
          | expressao GE expressao                    { $$ = binNode(GE, $1, $3); $$->info = comp($1, $3); }
          | expressao LE expressao                    { $$ = binNode(LE, $1, $3); $$->info = comp($1, $3); }
          | expressao '&' expressao                   { if($1->info != 1 || $3->info != 1) yyerror("Junção Lógica : Tipo inválido"); $$ = binNode(AND, $1, $3); $$->info = 1;}
          | expressao '|' expressao                   { if($1->info != 1 || $3->info != 1) yyerror("Alternativa Lógica : Tipo inválido"); $$ = binNode(OR, $1, $3); $$->info = 1;}
          | '~' expressao                             { if($2->info != 1) yyerror("Negação Lógica : Tipo inválido"); $$ = uniNode(NEG, $2); $$->info = 1;}
          | expressao '!'                             { if($1->info != 1) yyerror("Factorial : Tipo inválido"); $$ = uniNode(FACT, $1); $$->info = 1;}
          | '&' left_value %prec ADDR                 { $$ = uniNode(ADDR, $2); $$->info = $2->info;}
          | '*' left_value %prec POINTER              { $$ = uniNode(POINTER, $2); $$->info = $2->info;}
          ;

left_value: IDENTIF                                   { $$ = strNode(IDENTIF, $1); $$->info = IDfind($1, 0); } // deslocamento as variaveis para o place, para sber se é global

          | IDENTIF '[' expressao ']'                 {int x = IDfind($1, 0); $$ = binNode(POINTER, strNode(IDENTIF, $1), $3);
                                                        if (((x & 0x4) == 4)) 
                                                              $$->info = x - 4;
                                                        else if (((x & 0x7) == 2))
                                                              $$->info = 1;
                                                        else yyerror("Ponteiro: Tipo inválido.");
                                                        /* tem de ser ponteiro ou string e devolve tipo base (sem ponteiro) ou integer se for string */ }
          ;
     
%%
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

/*
static Node *mkvar(char *name) {
  long loc;
  int typ = IDfind(name, &loc); /* find type and offset of the variable 
  if (typ >= 32 && loc != 0) /* global variables have offset==0 
    return intNode(LOCAL, loc); /* local variables are accessed by offset 
  return strNode(VARIABLE, name); /* global variables are accessed by name 
}
*/

char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strdup(buf);
}

char **yynames =
#if YYDEBUG > 0
     (char**)yyname;
#else
     0;
#endif
