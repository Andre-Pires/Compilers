##-####-####-####-####-####-####-####-####-####-####-####-##
##							  ##
## description:						  ##
##     miniC compiler - part1: the lexer		  ##
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
 proj=proj1
 name=$(id).$(proj)
 pack=$(name).tar.zip

##-####-####-####-####-####-####-####-####-####-####-####-##
## 
## Source-code files specifics
##
#
 files=Makefile $(lexer).l main.h
 lexer=lexer
 OBJS=$(lexer).o
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
 RM=rm -f

##.SILENT:
.SUFFIXES: .l .c .o

##-####-####-####-####-####-####-####-####-####-####-####-##

all: $(OBJS)
	$(CC) $(CCFLAGS) -o $(OUT) $^ $(OFLAGS) $(LIBS)
	$(RM) $^

%.o: %.c
	$(CC) $(CCFLAGS) -c $^
%.c: %.l
	$(LEX) $(LFLAGS) $<

lexer: $(lexer).o
	$(CC) $(CCFLAGS) -o $(OUT) $^ $(OFLAGS) $(LIBS)
	$(RM) $^

clean:
	$(RM) $(OUT) $(OBJS) core *.gch *~

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
