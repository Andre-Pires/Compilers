# Makefile
FLAGS = -O2 #-g
EXTRAFLAGS = #-Wall -Wextra
LIBS = -lfl
TARGET = a.out
OBJECTS = lex.yy.o y.tab.o lib/node.o lib/tabid.o lib/tac.o lib/stack.o

all : lex yacc build

yacc: y.tab.o

y.tab.c : yacc2.y
	yacc -d -v yacc2.y

lex: lex.yy.c

lex.yy.c : lex2.l
	flex -l lex2.l

build : ${TARGET}

${TARGET} : ${OBJECTS}
	gcc -o $@ $? ${FLAGS} ${LIBS} ${EXTRAFLAGS}

%.o : %.c
	gcc -c -o $@ $? ${FLAGS} ${EXTRAFLAGS} -I.

clean :
	rm -f *~ lib/*~ ${OBJECTS} ${TARGET} lex.yy.c y.tab.h y.output y.tab.c
