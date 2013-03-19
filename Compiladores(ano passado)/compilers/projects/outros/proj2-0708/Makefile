## user options ##
 lexer=lex2.l
 parser=yacc2.y
 target=p2
 OUT=a.out
##################

 CC=gcc
 LEX=flex
 YACC=yacc

 CFLAGS=-lfl
 CCFLAGS=-Wall -pedantic
 YFLAGS=-d -v

 OBJS=lex.yy.o y.tab.o tabid.o node.o

.IGNORE:
.SUFFIXES: .c .o

all: $(OBJS)
	$(CC) -o $(OUT) $^ $(CFLAGS)

lex.yy.o: $(lexer)
	$(LEX) $<
	$(CC) -c lex.yy.c

y.tab.o: $(parser)
	$(YACC) $(YFLAGS) $<
	$(CC) -c y.tab.c

lexer: lex.yy.o
parser: y.tab.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $*.c

trace: clean lexer $(parser) node.o tabid.o
	$(YACC) $(YFLAGS) -t $(parser)
	$(CC) -c y.tab.c
	$(CC) -o $(OUT) $(OBJS) $(CFLAGS)

refresh: clean all

clean:
	rm -f $(OUT) $(OBJS) core *.o *.gch *.yy.? *.tab.? y.output

tar: clean
	tar -zcf ../$(target)_`date +%j-%H%M`.tgz *
