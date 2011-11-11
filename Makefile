TEMPLATE=./meta/templ

SRC=./src/
INC=./include/
LIB=./lib/

include ./meta/libinf.mk

all: prepare build test

prepare:
	@rm -rf $(LIB)
	@mkdir  $(LIB)

clean:
	@cd src   && make clean
	@cd tests && make clean

build:
	@cd src   && make

test: build simlink
	@cd tests && make

install:
	@cd src   && make install

simlink:
	ln -sf $(LIBNAME).so.$(LIBMINOR)  $(LIB)$(LIBNAME).so.$(LIBMAJOR)
	ln -sf $(LIBNAME).so.$(LIBMINOR)  $(LIB)$(LIBNAME).so

newobj:
	$(TEMPLATE)/gen-src $(name) > $(SRC)/$(name).cc
	$(TEMPLATE)/gen-inc $(name) > $(INC)/$(name).hh
