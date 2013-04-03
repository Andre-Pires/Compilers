ID=compact+

TAR=tar czvf $(ID).tgz
RM=rm -f

all:
	$(MAKE) -C solex
	$(MAKE) -C lib
	$(MAKE) -C interm
	$(MAKE) -C final
	$(MAKE) -C run
	$(MAKE) -C exs

install: all
	$(MAKE) -C final install
	$(MAKE) -C run install

backup: clean
	cd ..; $(TAR) $(ID)

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C solex clean
	$(MAKE) -C interm clean
	$(MAKE) -C final clean
	$(MAKE) -C run clean
	$(MAKE) -C exs clean
	$(RM) librun.a compact
