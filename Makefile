
TEMPLATE=./templ
SRC=./src
INC=./include

all:
	@echo "Stub"

newobj:
	$(TEMPLATE)/gen-src $(name) > $(SRC)/$(name).cc
	$(TEMPLATE)/gen-inc $(name) > $(INC)/$(name).hh
