
TEMPLATE=./meta/templ
SRC=./src
INC=./include

all:
	@cd src   && make
	@cd impl  && make
	@cd tests && make

newobj:
	$(TEMPLATE)/gen-src $(name) > $(SRC)/$(name).cc
	$(TEMPLATE)/gen-inc $(name) > $(INC)/$(name).hh
