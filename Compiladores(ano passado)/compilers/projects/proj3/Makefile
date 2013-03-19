##-####-####-####-####-####-####-####-####-####-####-####-##
##							  ##
## description:						  ##
##     miniC compiler - part3: IR optimizer backend 	  ##
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
 proj=proj3
 name=$(id).$(proj)
 pack=$(name).tar.zip

##-####-####-####-####-####-####-####-####-####-####-####-##
## 
## Source-code files specifics
##
#
 files=Makefile basicblock.? ins.? map.? reg.? main.?
 OBJS=reg.o ins.o basicblock.o map.o main.o
 OUT=a.out
 OUT2=$(proj)
##-####-####-####-####-####-####-####-####-####-####-####-##
##
## Main code
##
# flags debug: -g -pg
#
 CC=gcc
 LIBS=
 CCFLAGS=-Wall -Wextra
 OFLAGS=-Os -pipe -march=native -mtune=native
 RM=rm -f

##.SILENT:
.SUFFIXES: .c .o

##-####-####-####-####-####-####-####-####-####-####-####-##

all: $(OBJS)
	$(CC) $(CCFLAGS) -o $(OUT) $^ $(OFLAGS) $(LIBS)
	cp -f $(OUT) $(OUT2)
	$(RM) $^

%.o: %.c
	$(CC) $(CCFLAGS) -c $< $(OFLAGS)

clean:
	$(RM) $(OUT) $(OUT2) $(OBJS) *~ $(name).{tar,tgz,tar.zip} gmon.out core

zip: clean
	mkdir -p $(name)
	cp -f $(files) $(name)/ 
	tar -cf $(name).tar $(name)/
	zip $(pack) $(name).tar
	$(RM) -r $(name)/ $(name).tar

tgz: clean
	tar -chzf ../$(proj).tgz * && mv ../$(proj).tgz ./
