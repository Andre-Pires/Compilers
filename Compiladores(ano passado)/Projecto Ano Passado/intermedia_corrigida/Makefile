ID=at
EXT=.at
VER=1a

#.SUFFIXES: $(EXT) .asm
LOADLIBS=$(UTIL) # -lfl
CC=gcc
CFLAGS=-g -Wall -DYYDEBUG -I$(LIB)
#CFLAGS=-O2 -I$(LIB)
LEX=flex
LFLAGS=-l
YACC=byacc
YFLAGS=-dv
#NASM=nasm -felf

BID=$(ID)-$(VER)
LIB=lib
UTIL=$(LIB)/libutil.a
BIN=$(ID)
#RUN=runtime/librun.a

all: $(UTIL) $(BIN)

#%:%.asm
	#$(NASM) $*.asm
	#$(LD) $*.o -l$(ID) -o $@

#$(EXT).asm:
	#$(ID) $<

BASE= y.tab.o lex.yy.o
$(ID): $(BASE) $(UTIL)
	$(LINK.c) -o $@ $^

#full: all trans gram interp
#trans: $(BASE) trans.o $(UTIL)
	#$(LINK.c) -o $@ $^

#gram: lex.yy.o gram.o $(UTIL)
	#$(LINK.c) -o $@ $^

#interp: $(BASE) interp.o $(UTIL)
	#$(LINK.c) -o $@ $^

$(UTIL):
	cd $(LIB); $(MAKE) $(MFLAGS) CC=$(CC)

#$(RUN):
	#cd runtime; $(MAKE) $(MFLAGS) CC=$(CC)

#ver.c: Makefile
#	echo "char *version = \"" $(VER) "\";" > $@

lex.yy.c: $(ID).l y.tab.c
	$(LEX) $(LFLAGS) $<

y.tab.c: $(ID).y
	$(YACC) $(YFLAGS) $<

#examples: $(RUN) $(ID)
#	cd ../examples; $(MAKE) $(MFLAGS) BIN=../c/compact

clean:
	rm -f *.o core a.out $(BIN) y.tab.* lex.yy.* y.output *.asm trans interp gram

cleanall: clean
	cd $(LIB); $(MAKE) $(MFLAGS) clean
	#cd runtime; $(MAKE) $(MFLAGS) clean
	#cd examples; $(MAKE) $(MFLAGS) clean

backup: clean
	PWD=`pwd`; CWD=`basename $$PWD`; cd ..; tar cf - $$CWD | gzip -9 > $@/$(BID).tgz

.PHONY: all clean cleanall backup examples
