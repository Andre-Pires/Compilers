ID=compact
EXT=.cpt
VER=1g

BID=$(ID)-$(VER)
COPY="$(BID) (C)prs, 2012"

.SUFFIXES: $(EXT) .brg .asm
LOADLIBS=$(UTIL) # -lfl
CC=gcc
CFLAGS=-g -DYYDEBUG -I$(LIB)
#CFLAGS=-O2 -I$(LIB)
LEX=flex
LFLAGS=-l
YACC=byacc
YFLAGS=-dv
BURG=pburg
BFLAGS=-R
NASM=nasm -felf

BID=$(ID)-$(VER)
LIB=../lib
UTIL=$(LIB)/libutil.a
BIN=$(ID)
RUN=../runtime/librun.a

all: $(UTIL) $(BIN) $(RUN)

.brg.c:
	$(BURG) $(BFLAGS) -p $* $< $@

%:%.asm
	$(NASM) $*.asm -o $*$(EXT)
	$(LD) $*.o $(RUN) -o $@

$(EXT).asm:
	$(ID) $<

$(ID): scan.o gram.o i386.o $(UTIL)
	$(LINK.c) -o $@ $^

full: all cptarm cptpepe postfix trans gram greedy interp stab jasmin msil

cptarm: scan.o gram.o arm.o $(UTIL)
	$(LINK.c) -o $@ $^

cptpepe: scan.o gram.o pepe.o $(UTIL)
	$(LINK.c) -o $@ $^

postfix: scan.o tree.o postfix.o $(UTIL)
	$(LINK.c) -o $@ $^

trans: scan.o tree.o trans.o $(UTIL)
	$(LINK.c) -o $@ $^

gram: scan.o syntax.o $(UTIL)
	$(LINK.c) -o $@ $^

greedy: scan.o tree.o greedy.o $(UTIL)
	$(LINK.c) -o $@ $^

interp: scan.o tree.o interp.o $(UTIL)
	$(LINK.c) -o $@ $^

stab: scan.o tree.o stab.o $(UTIL)
	$(LINK.c) -o $@ $^

jasmin: scan.o tree.o jasmin.o $(UTIL)
	$(LINK.c) -o $@ $^

msil: scan.o tree.o msil.o $(UTIL)
	$(LINK.c) -o $@ $^

scan.o: tree.c syntax.c gram.c

$(UTIL):
	cd $(LIB); $(MAKE) $(MFLAGS) CC=$(CC)

$(RUN):
	cd ../runtime; $(MAKE) $(MFLAGS) CC=$(CC)

ver.c: Makefile
	echo "char *version = \"" $(VER) "\";" > $@

lex.yy.c: $(ID).l y.tab.c
	$(LEX) $(LFLAGS) $<

y.tab.c: $(ID).y
	$(YACC) $(YFLAGS) $<

examples: $(RUN) $(ID)
	cd ../examples; $(MAKE) $(MFLAGS) BIN=../c/compact

clean:
	rm -f *.o core a.out $(BIN) y.tab.* lex.yy.* y.output *.asm tree.c syntax.c gram.c cptarm cptpepe postfix trans gram greedy interp stab jasmin msil

cleanall: clean
	cd $(LIB); $(MAKE) $(MFLAGS) clean
	cd ../runtime; $(MAKE) $(MFLAGS) clean
	cd ../examples; $(MAKE) $(MFLAGS) clean

backup: clean
	PWD=`pwd`; CWD=`basename $$PWD`; cd ..; tar cf - $$CWD | gzip -9 > $@/$(BID).tgz

.PHONY: all clean cleanall backup examples
