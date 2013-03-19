.SUFFIXES: .yak .asm
PROG=yak
PFLAGS=
NASM=nasm -felf
WNASM=nasm -fwin32
LIBDIR=..
LIBS=libyak.a
WINLIBS=yak.lib

.yak.asm:
	$(PROG) $(PFLAGS) $< $@

.asm.o:
	$(NASM) $(NFLAGS) $(FMT) $<

.o.exe:
	link /NOLOGO /OUT:$@ $< /LIBPATH:$(LIBDIR) $(LIBS) KERNEL32.LIB

%: %.o
	ld -o $@ $< $(LIBDIR)/$(LIBS)
