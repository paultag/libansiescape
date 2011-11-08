CXX=g++

include ../meta/libinf.mk

CFLAGS=-Wall
LDFLAGS=-L$(LIB) -l$(LIBSHORT)
LIB=../lib/
BIN=../bin/
INC=../include/

TARGETS=$(shell ls *.cc | sed s/.cc/.o/g)

all: $(TARGETS) link clean

clean:
	@echo "Removing all .o files."
	@rm -f *.o

link:
	$(CXX) $(TARGETS) $(LDFLAGS) -o $(BIN)ansi-csi-impl

.cc.o:
	$(CXX) $(CFLAGS) -I$(INC) -c -o $@ $<
