%{
/* $Id: at.y,v 1.9 2004/12/09 17:25:13 prs Exp $ */

#include "Node.hpp"
#include "NodeInteger.hpp"
#include "NodeString.hpp"
#include "NodeVariable.hpp"
#include "NodeReal.hpp"
#include "NodeList.hpp"
#include "NodePrint.hpp"
#include "NodePrintLine.hpp"
#include "NodeIf.hpp"
#include "NodeFor.hpp"
#include "NodeIfelse.hpp"
#include "NodeAssign.hpp"
#include "NodeUminus.hpp"
#include "NodeUplus.hpp"
#include "NodeAdd.hpp"
#include "NodeSub.hpp"
#include "NodeMul.hpp"
#include "NodeDiv.hpp"
#include "NodeMod.hpp"
#include "NodeEq.hpp"
#include "NodeNe.hpp"
#include "NodeGt.hpp"
#include "NodeGe.hpp"
#include "NodeLt.hpp"
#include "NodeLe.hpp"
#include "NodeNe.hpp"
#include "NodeAnd.hpp"
#include "NodeOr.hpp"
#include "NodeNot.hpp"
#include "NodePow.hpp"
#include "NodeAddr.hpp"
#include "NodeVar.hpp"
#include "NodeVarAt.hpp"
#include "NodeFunc.hpp"
#include "NodeQui.hpp"
#include "NodeType.hpp"
#include "NodeAlloc.hpp"
#include "NodeAccess.hpp"
#include "NodeStop.hpp"
#include "NodeReturn.hpp"
#include "NodeNext.hpp"
#include "NodeIfLst.hpp"
#include "NodeSect.hpp"
#include "NodeSectList.hpp"
#include "NodeBlock.hpp"
#include "NodeCallFunc.hpp"
#include "NodeQual.hpp"
#include "NodeAtAssign.hpp"
#include "NodeAtRec.hpp"
#include "NodeAtLoad.hpp"
#include "NodeBody.hpp"
#include "NodeElif.hpp"
#include "NodeTrue.hpp"
#include "NodeFor.hpp"
#include "NodeQuad.hpp"
#include "NodeConst.hpp"
#include "NodeInd.hpp"
#include "NodeIndLst.hpp"
#include "NodeIfLstFin.hpp"
#include "NodeLit.hpp"

#include "Parser.hpp"

Parser *parser;
void yyerror(const char *msg);
%}

%token<n> INTEGER LIT_REAL ID
%token<n> LIT_STRING CHAR

%token CONST VOID INT REAL STRING PUBLIC USE NEXT STOP RETURN EXPL OPER PRINT PRINT_NEW_LINE
%nonassoc IFX
%nonassoc ':' SCT
%right '='
%left OR
%left AND
%nonassoc NOT
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '^'
%nonassoc UMINUS UPLUS '#' '?'
%nonassoc '(' ')' '[' ']' '{' '}'

%union{ Node *n; }
%type<n> literal expressao variaveis decl instr instrucao param variavel declaracao iteracao bloco condicao cond funcao tipo qualificador corpo lit secinc seccao cadeia index secfin

%start ficheiro
%%

ficheiro	: decl								{ parser->syntax($1); }
		;
	 
declaracao	: variavel ';'							{ $$ = $1;}
		| funcao							{ $$ = $1;}
		;
				
variavel	: qualificador CONST tipo ID					{ Node* a = new NodeConst();
										  $$ = new NodeVar(*$1, *a, *$3, *$4);					}
		| qualificador tipo ID 						{ Node* a = new Node();
										  $$ = new NodeVar(*$1, *a, *$2, *$3);					}
		| qualificador CONST tipo ID '=' literal			{ Node* a = new NodeConst();
										  $$ = new NodeVarAt(*$1, *a, *$3, *$4, *$6);				}
		| qualificador tipo ID '=' literal				{ Node* a = new Node();
										  $$ = new NodeVarAt(*$1, *a, *$2, *$3, *$5);				}
		| CONST tipo ID							{ Node* a = new Node();
										  Node* b = new NodeConst();
										  $$ = new NodeVar(*a, *b, *$2, *$3);					}
		| tipo ID							{ Node* a = new Node();
										  $$ = new NodeVar(*a, *a, *$1, *$2);					}
		| CONST tipo ID '=' literal					{ Node* a = new Node();
										  Node* b = new NodeConst();
										  $$ = new NodeVarAt(*a, *b, *$2, *$3, *$5);				}
		| tipo ID '=' literal						{ Node* a = new Node();
										  $$ = new NodeVarAt(*a, *a, *$1, *$2, *$4);				}
		;
		
variaveis	: variaveis ',' variavel					{ ((NodeList*)($$ = $1))->append(*$3);	}
		| variavel							{ $$ = new NodeList();
									          ((NodeList*)$$)->append(*$1);		}
		;
				
funcao		: qualificador VOID ID '(' variaveis ')' corpo			{ Node* a = new Node();
										  $$ = new NodeFunc(*$1, *a, *$3, *$5, *$7);				}
		| qualificador tipo ID '(' variaveis ')' corpo			{ $$ = new NodeFunc(*$1, *$2, *$3, *$5, *$7);				}
		| qualificador VOID ID '(' ')' corpo				{ Node* a = new Node();
										  $$ = new NodeFunc(*$1, *a, *$3, *a, *$6);				}
		| qualificador tipo ID '(' ')' corpo				{ Node* a = new Node();
										  $$ = new NodeFunc(*$1, *$2, *$3, *a, *$6);				}
		| VOID ID '(' variaveis ')' corpo				{ Node* a = new Node();
										  $$ = new NodeFunc(*a, *a, *$2, *$4, *$6);				}
		| tipo ID '(' variaveis ')' corpo				{ Node* a = new Node();
										  $$ = new NodeFunc(*a, *$1, *$2, *$4, *$6);				}
		| VOID ID '(' ')' corpo						{ Node* a = new Node();
										  $$ = new NodeFunc(*a, *a, *$2, *a, *$5);				}
		| tipo ID '(' ')' corpo						{ Node* a = new Node();
										  $$ = new NodeFunc(*a, *$1, *$2, *a, *$5);				}
		;	

tipo		: INT								{ /*$$ = new NodeType();*/}
		| REAL								{ /*$$ = new NodeType();*/}
		| STRING							{ /*$$ = new NodeType();*/}
		| '<' tipo '>'							{ /*$$ = new NodeType();*/}
		;	
			
qualificador	: PUBLIC							{ /*$$ = new NodeQual();*/}
		| USE								{ /*$$ = new NodeQual();*/}
		;	

corpo		: lit secinc seccao secfin					{ $$ = new NodeBody(*$1, *$2, *$3, *$4);}
		| ';'								{ $$ = new Node();			}
		;
		
lit 		: '=' literal							{ $$ = new NodeLit(*$2);	}
		| '=' '-' literal %prec UMINUS					{ $$ = new NodeUminus(*$3);	}
		| /* vazio */							{ $$ = new Node();		}
		;
		
secinc		: '<' '<' bloco							{ $$ = $3;			}
		| /* vazio */							{ $$ = new Node();		}
		;
		
secfin		: '>' '>' bloco							{ $$ = $3; 			}
		| /* vazio */							{ $$ = new Node();		}
		;		
		
seccao		: '[' ']' bloco %prec SCT					{ Node* a = new NodeTrue();
										  $$ = new NodeSect(*a, *$3);		}
		| '(' ')' bloco %prec SCT					{ Node* a = new NodeTrue();	
										  $$ = new NodeSect(*a, *$3);		}
		| '[' ']' bloco seccao						{ Node* a = new NodeTrue();
										  $$ = new NodeSectList(*a, *$3, *$4);	}
		| '(' ')' bloco seccao 						{ Node* a = new NodeTrue();
										  $$ = new NodeSectList(*a, *$3, *$4);	}
		| '[' expressao ']' bloco %prec SCT				{ $$ = new NodeSect(*$2, *$4);		}
		| '(' expressao ')' bloco %prec SCT				{ $$ = new NodeSect(*$2, *$4);		}
		| '[' expressao ']' bloco seccao				{ $$ = new NodeSectList(*$2, *$4, *$5);	}
		| '(' expressao ')' bloco seccao				{ $$ = new NodeSectList(*$2, *$4, *$5);	}
		| bloco %prec SCT						{ Node* a = new NodeTrue();
										  $$ = new NodeSect(*a, *$1);		}
		| bloco seccao 							{ Node* a = new NodeTrue();
										  $$ = new NodeSectList(*a, *$1, *$2);	}
		;		

literal		: LIT_REAL							{ $$ = $1;}
		| cadeia							{ $$ = $1;}
		;
		
cadeia		: LIT_STRING cadeia						{ ((NodeList*)($$ = $2))->append(*$1);			}
		| CHAR cadeia							{ ((NodeList*)($$ = $2))->append(*$1);			}
		| INTEGER cadeia						{ ((NodeList*)($$ = $2))->append(*$1);			}			
		| LIT_STRING							{ $$ = new NodeList(); ((NodeList*)$$)->append(*$1);	}
		| INTEGER							{ $$ = new NodeList(); ((NodeList*)$$)->append(*$1);	}
		| CHAR								{ $$ = new NodeList(); ((NodeList*)$$)->append(*$1);	} 
		;

bloco		: '{' '}'							{ Node* a = new Node();
										  $$ = new NodeBlock(*a, *a);			}
		| '{' decl '}'							{ Node* a = new NodeList(); ((NodeList*)a)->append(*$2);
										  Node* b = new Node();
										  $$ = new NodeBlock(*a, *b);				}
		| '{' instr '}'							{ Node* a = new NodeList(); ((NodeList*)a)->append(*$2);
										  Node* b = new Node();
										  $$ = new NodeBlock(*b, *a);				}
		| '{' decl instr '}'						{ Node* a = new NodeList(); ((NodeList*)a)->append(*$2);
										  Node* b = new NodeList(); ((NodeList*)b)->append(*$3);
										  $$ = new NodeBlock(*a,*b); 			}
		;	
		
decl		: declaracao decl						{ ((NodeList*)($$ = $2))->append(*$1);			}
		| declaracao							{ $$ = new NodeList(); ((NodeList*)$$)->append(*$1);	}
		;
		
instr		: instrucao instr						{ ((NodeList*)($$ = $1))->append(*$2);			}
		| instrucao							{ $$ = new NodeList(); ((NodeList*)$$)->append(*$1);	}
		;
		
		
instrucao	: expressao ';'							{ $$ = $1;			}
		| expressao PRINT						{ $$ = new NodePrint(*$1);	}
		| expressao PRINT_NEW_LINE					{ $$ = new NodePrintLine(*$1);	}
		| NEXT								{ $$ = new NodeNext();		}
		| STOP								{ $$ = new NodeStop();		}
		| RETURN							{ $$ = new NodeReturn();	}
		| condicao							{ $$ = $1;			}
		| iteracao							{ $$ = $1;			}
		| bloco								{ $$ = $1; 			}
		;
	
condicao	: '[' expressao ']' '#' instrucao				{ $$ = new NodeIf(*$2, *$5);		}
		| '[' expressao ']' '?' instrucao %prec IFX			{ $$ = new NodeIf(*$2, *$5);		}
		| '[' expressao ']' '?' instrucao ':' instrucao			{ $$ = new NodeIfelse(*$2, *$5, *$7);	}
		| '[' expressao ']' '?' instrucao cond %prec IFX		{ $$ = new NodeIfLstFin(*$2, *$5, *$6);	}
		| '[' expressao ']' '?' instrucao cond ':' instrucao		{ $$ = new NodeElif(*$2, *$5, *$6, *$8);}
		;	
		
cond		: '[' expressao ']' '?' instrucao cond				{ $$ = new NodeIfLst(*$2, *$5, *$6);	}
		| '[' expressao ']' '?' instrucao				{ $$ = new NodeIf(*$2, *$5);		}
		;		
		
iteracao	: '[' variaveis ';' expressao ';' expressao ']' instrucao	{ $$ = new NodeFor(*$2, *$4, *$6, *$8);					}
		| '[' variaveis ';' expressao ';' ']' instrucao			{ Node* a = new Node();
										  $$ = new NodeFor(*$2, *$4, *a, *$7);					}
		| '[' variaveis ';' ';' expressao ']' instrucao			{ Node* a = new NodeTrue();
										  $$ = new NodeFor(*$2, *a, *$5 , *$7);					}
		| '[' variaveis ';' ';' ']' instrucao				{ Node* a = new Node();
										  Node* b = new NodeTrue();
										  $$ = new NodeFor(*$2, *b, *a, *$6);					}
		| '[' expressao ';' expressao ';' expressao ']' instrucao	{ $$ = new NodeFor(*$2, *$4, *$6, *$8);					}
		| '[' expressao ';' expressao ';' ']' instrucao			{ Node* a = new Node();
										  $$ = new NodeFor(*$2, *$4, *a, *$7);					}
		| '[' expressao ';' ';' expressao ']' instrucao			{ Node* a = new NodeTrue();
										  $$ = new NodeFor(*$2, *a, *$5 , *$7);					}
		| '[' expressao ';' ';' ']' instrucao				{ Node* a = new Node();
										  Node* b = new NodeTrue();
										  $$ = new NodeFor(*$2, *b, *a, *$6);					}
		| '[' ';' expressao ';' expressao ']' instrucao			{ Node* a = new Node();
										  $$ = new NodeFor( *a, *$3, *$5 , *$7);				}
		| '[' ';' expressao ';' ']' instrucao				{ Node* a = new Node();
										  $$ = new NodeFor( *a, *$3, *a , *$6);					}
		| '[' ';' ';' expressao ']' instrucao				{ Node* a = new Node();
										  Node* b = new NodeTrue();
										  $$ = new NodeFor( *a, *b, *$4 , *$6);					}
		| '[' ';' ';' ']' instrucao					{ Node* a = new Node();
										  Node* b = new NodeTrue();
										  $$ = new NodeFor( *a, *b, *a, *$5);	}
		;

expressao	: literal							{ $$ = $1;					}
		| ID								{ $$ = $1;					} 
		| ID '?'							{ $$ = new NodeAddr(*$1);			}
		| ID index '?'							{ Node* a = new NodeAccess(*$1,*$2);
										  $$ = new NodeAddr(*a);			}
		| ID '=' expressao						{ $$ = new NodeAssign(*$1, *$3);		}
		| ID index '=' expressao					{ Node* a = new NodeAccess(*$1,*$2);
										  $$ = new NodeAssign(*a, *$4);			} 
		| ID '(' param ')'						{ $$ = new NodeCallFunc(*$1, *$3);		}
		| ID '(' ')'							{ Node* a = new Node();
										  $$ = new NodeCallFunc(*$1, *a);		}
		| '@' '=' expressao						{ $$ = new NodeAtAssign(*$3);			}
		| '@' 								{ $$ = new NodeAtLoad();			}	
		| '@' '(' param ')'						{ $$ = new NodeAtRec(*$3);			}	
		| '@' '(' ')'							{ Node* a = new Node();
										  $$ = new NodeAtRec(*a);			}
		| '-' expressao %prec UMINUS					{ $$ = new NodeUminus(*$2);			}
		| '+' expressao %prec UPLUS		  			{ $$ = new NodeUplus(*$2); 			}
		| expressao '+' expressao			  		{ $$ = new NodeAdd(*$1, *$3);			}
		| expressao '-' expressao			  		{ $$ = new NodeSub(*$1, *$3);			}
		| expressao '*' expressao			  		{ $$ = new NodeMul(*$1, *$3);			}
		| expressao '/' expressao			  		{ $$ = new NodeDiv(*$1, *$3);			}
		| expressao '%' expressao			 		{ $$ = new NodeMod(*$1, *$3);			}
		| expressao '<' expressao			  		{ $$ = new NodeLt(*$1, *$3);			}
		| expressao '>' expressao			  		{ $$ = new NodeGt(*$1, *$3);			}
		| expressao GE expressao			 		{ $$ = new NodeGe(*$1, *$3);			}
		| expressao LE expressao			  		{ $$ = new NodeLe(*$1, *$3);			}
		| expressao NE expressao			  		{ $$ = new NodeNe(*$1, *$3);			}
		| expressao EQ expressao 					{ $$ = new NodeEq(*$1, *$3);			}
		| expressao AND expressao 					{ $$ = new NodeAnd(*$1, *$3);			}	//inteiros
		| expressao OR expressao 					{ $$ = new NodeOr(*$1, *$3);			}	//inteiros
		| NOT expressao  						{ $$ = new NodeNot(*$2);			}	//inteiros
		| ID index							{ $$ = new NodeAccess(*$1,*$2);			}	// indexacao - inteiros
		| ID '=' expressao '#' 						{ $$ = new NodeAlloc(*$1, *$3);			}	// reserva de memoria 	
		| expressao '^' expressao 					{ $$ = new NodePow(*$1, *$3);			}	// potencia - inteiros
		| '(' expressao ')'			  			{ $$ = $2;					}
		;
		
index		: '[' expressao ']' index					{ $$ = new NodeIndLst(*$2, *$4);		}
		| '[' expressao ']'						{ $$ = new NodeInd(*$2);			}
		;
		
param		: expressao							{ $$ = new NodeList(); ((NodeList*)$$)->append(*$1);	}
		| param ',' expressao						{ ((NodeList*)($$ = $1))->append(*$3);			}
		;

%%
void yyerror(const char *msg) { parser->error(msg); }
int yylex() { return parser->lex(); }
