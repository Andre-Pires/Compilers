LANG=compact
EXT=cpt
.SUFFIXES: .$(EXT) .asm
LEX=flex -l # -d
YACC=byacc -dv
BURG=pburg # -T
NASM=nasm -felf
LD=ld
CC=gcc
CFLAGS=-g

$(LANG): $(LANG).y $(LANG).l $(LANG).brg
	$(YACC) -dv $(LANG).y
	$(LEX) -l $(LANG).l
	$(BURG) $(LANG).brg
	$(MAKE) -C ../lib
	$(CC) $(CFLAGS) -o $(LANG) -DYYDEBUG -I../lib lex.yy.c y.tab.c yyselect.c ../lib/libutil.a
	$(MAKE) -C ../run

%:%.$(EXT)
	./$(LANG) $<
	$(NASM) $*.asm
	ld -o $@ $*.o -L../run -lrun

install:: $(LANG)
	cp $< ..
	$(MAKE) -C ../run install

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output yyselect.c code.c *.asm *.$(EXT) *~
