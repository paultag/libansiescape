
TEMPLATE=./meta/templ
SRC=./src
INC=./include

BIN=./bin
LIB=./lib

all:
	@rm -rf $(BIN)
	@rm -rf $(LIB)
	@mkdir $(BIN) $(LIB)
	@cd src   && make
	@cd impl  && make
	@cd tests && make

newobj:
	$(TEMPLATE)/gen-src $(name) > $(SRC)/$(name).cc
	$(TEMPLATE)/gen-inc $(name) > $(INC)/$(name).hh
