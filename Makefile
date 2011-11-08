TEMPLATE=./meta/templ
SRC=./src/
INC=./include/

BIN=./bin/
LIB=./lib/

include ./meta/libinf.mk

all: prepare build similink

prepare:
	@rm -rf $(BIN)
	@rm -rf $(LIB)
	@mkdir $(BIN) $(LIB)

build:
	@cd src   && make
	@cd impl  && make
	@cd tests && make

similink:
	ln -s $(LIBNAME).so  $(LIB)$(LIBNAME).so.$(LIBMAJOR)
	ln -s $(LIBNAME).so  $(LIB)$(LIBNAME).so.$(LIBMINOR)

newobj:
	$(TEMPLATE)/gen-src $(name) > $(SRC)/$(name).cc
	$(TEMPLATE)/gen-inc $(name) > $(INC)/$(name).hh
