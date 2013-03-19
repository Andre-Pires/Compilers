ID=At
EXT=.at
VER=1.0

.SUFFIXES: $(EXT) .asm
CC=g++ # for y.tab.c that does not have a .cpp extension!
CXXFLAGS=-g
LEX=flex
YACC=byacc
YFLAGS=-dv
NASM=nasm -felf
MV=mv

BID=$(ID)-$(VER)
BIN=$(ID)
RUN=../runtime/
RTL=$(RUN)/librun.a

OBJ = At.o Compiler.o Interp.o Node.o PFdebug.o PFi386.o Postfix.o  \
	Tabid.o y.tab.o yyFlexLexer.o main.o NodeInteger.o NodeString.o \
	NodeVariable.o NodeReal.o NodeList.o NodePrint.o NodeUnary.o \
	NodeBinary.o NodeTernary.o NodeQuad.o NodePrintLine.o NodeIf.o \
	NodeIfelse.o NodeAssign.o NodeUminus.o NodeUplus.o NodeAdd.o NodeSub.o \
	NodeMul.o NodeDiv.o NodeMod.o NodeGt.o NodeLt.o NodeGe.o NodeLe.o \
	NodeNe.o NodeEq.o NodeAnd.o NodeOr.o NodeNot.o NodePow.o NodeAddr.o  \
	NodeFor.o NodeVar.o NodeVarAt.o NodeFunc.o NodeQui.o NodeType.o \
	NodeAlloc.o NodeAccess.o NodeStop.o NodeReturn.o NodeNext.o NodeIfLst.o \
	NodeSect.o NodeSectList.o NodeQual.o NodeBlock.o NodeBody.o NodeElif.o \
	NodeAtRec.o NodeAtAssign.o NodeAtLoad.o NodeTrue.o NodeConst.o \
	NodeCallFunc.o NodeInd.o NodeIndLst.o NodeIfLstFin.o NodeLit.o Symbol.o \
	SymbolNode.o 

all: $(BIN) $(RTL)
	rm *.o
	
%:%.asm
	$(NASM) $*.asm
	$(LD) $*.o -l$(ID) -o $@

$(EXT).asm:
	$(ID) $<

$(ID): $(OBJ)
	$(LINK.c) -o $@ $^

$(RTL):
	cd $(RUN); $(MAKE) $(MFLAGS)

ver.c: Makefile
	echo "char *version = \"" $(VER) "\";" > $@

yyFlexLexer.cpp: $(ID).l y.tab.cpp
	$(LEX) $(LFLAGS) $<

y.tab.cpp: $(ID).y
	$(YACC) $(YFLAGS) $<
	$(MV) y.tab.c $@

examples: $(ID) $(RTL)
	cd ../exemplos; $(MAKE) $(MFLAGS) BIN=../c++/At

clean:
	rm -f *.o core a.out $(BIN) y.tab.* lex.yy.* y.output *.asm $(OBJ)

cleanall: clean
	cd ../runtime; $(MAKE) $(MFLAGS) clean
	cd ../exemplos; $(MAKE) $(MFLAGS) clean

backup: clean
	PWD=`pwd`; CWD=`basename $$PWD`; cd ..; tar cf - $$CWD | gzip -9 > ../$@/$(BID).tgz

depend:
	g++ -MM $(OBJ:.o=.cpp) >> Makefile
	makedepend $(ID).y $(ID).l

.PHONY: all clean cleanall examples backup
