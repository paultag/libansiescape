BUILDCHAIN=../meta/buildchain/
include $(BUILDCHAIN)/library-info.mk
# OK. We're clean on the Library front.

INC=../include/
BIN=./bin/
LIB=../lib/

LIBS=-lncurses -lpanel -lutil -lansiescape
CXXFLAGS=-Wall -I$(INC)
LDFLAGS=-L$(LIB) $(LIBS)
OUTPUT=$(BIN)ansi-csi-impl

TARGETS=$(shell ls *.cc | sed s/.cc/.o/g)

all: $(TARGETS) link run
clean:
	rm *.o
link: $(TARGETS)
run: link
	./bin/run-tests

# Basic rules for building cc files & linking.
include $(BUILDCHAIN)build.mk
