##-####-####-####-####-####-####-####-####-####-####-####-##
##							  ##
## description:						  ##
##     miniC compiler - part2: the parser		  ##
##							  ##
## author:						  ##
##     Nuno AJ de Aniceto				  ##
##							  ##
##-####-####-####-####-####-####-####-####-####-####-####-##
##
#
#
##
## Identification and turn-in settings
#
 id=57682
 proj=proj2
 name=$(id).$(proj)
 pack=$(name).tar.zip

##-####-####-####-####-####-####-####-####-####-####-####-##
## 
## Source-code files specifics
##
#
 files=Makefile $(parser).y $(parser).h $(lexer).l list.c list.h main.h
 lexer=lexer
 parser=parser
 OBJS=list.o $(parser).o $(lexer).o
 OUT=a.out
##-####-####-####-####-####-####-####-####-####-####-####-##
##
## Main code
##
#
 CC=gcc
 LIBS=-lfl
 CCFLAGS=-ansi -pedantic 
 OFLAGS=-Os -pipe -march=native -mtune=native
 LEX=flex
 LFLAGS=-o $@
 YACC=yacc
 YFLAGS=-d -v -y -o $@
 RM=rm -f

##.SILENT:
.SUFFIXES: .c .o

##-####-####-####-####-####-####-####-####-####-####-####-##

all: $(OBJS)
	$(CC) $(CCFLAGS) -o $(OUT) $^ $(OFLAGS) $(LIBS)
	$(RM) $^

%.o: %.c
	$(CC) $(CCFLAGS) -c $< $(OFLAGS)
%.c: %.y
	$(YACC) $(YFLAGS) $<
%.c: %.l
	$(LEX) $(LFLAGS) $<

lexer: $(lexer).o
	$(CC) $(CCFLAGS) -o $(OUT) $^ $(OFLAGS) $(LIBS)
	$(RM) $^

clean:
	$(RM) $(OUT) $(OBJS) $(parser).output *~

zip: clean
	$(RM) $(pack)
	mkdir -p $(name)
	cp -f $(files) $(name)/ 
	tar -cf $(name).tar $(name)/
	zip $(pack) $(name).tar
	$(RM) -r $(name)/ $(name).tar

tgz: clean
	$(RM) $(pack) $(proj).{tar,tgz}*
	tar -czf ../$(proj).tgz * && mv ../$(proj).tgz ./
