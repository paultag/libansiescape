TEMPLATE=./meta/templ

SRC=./src/
INC=./include/
LIB=./lib/

include ./meta/libinf.mk

all: prepare build similink

prepare:
	@rm -rf $(LIB)
	@mkdir  $(LIB)

clean:
	@cd src   && make clean
	@cd tests && make clean

build:
	@cd src   && make
	@cd tests && make

install:
	@cd src   && make install

similink:
	ln -s $(LIBNAME).so  $(LIB)$(LIBNAME).so.$(LIBMAJOR)
	ln -s $(LIBNAME).so  $(LIB)$(LIBNAME).so.$(LIBMINOR)

newobj:
	$(TEMPLATE)/gen-src $(name) > $(SRC)/$(name).cc
	$(TEMPLATE)/gen-inc $(name) > $(INC)/$(name).hh
