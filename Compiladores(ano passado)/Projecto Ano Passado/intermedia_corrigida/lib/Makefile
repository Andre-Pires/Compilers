LIB=util
CFLAGS=-g
BID=$(ID)-$(VER)

NASM=nasm -felf
YACC=byacc
LEX=flex -l

all: lib$(LIB).a

lib$(LIB).a: tabid.o main.o
	ar crl $@ $?

#malloc.o: malloc.c
#	$(COMPILE.c) -Drcheck=2 $<

#depend:
#	makedepend -Y node.c tabid.c

backup: clean
	PWD=`pwd`; CWD=`basename $$PWD`; cd ..; tar cf - $$CWD | gzip -9 > $@/$(BID).tgz

clean:
	rm -f lib$(LIB).a *.o a.out core
