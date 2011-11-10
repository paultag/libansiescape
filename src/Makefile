CXX=g++

include ../meta/libinf.mk

CFLAGS=-Wall -c -fPIC 
LDFLAGS=-shared -W1,-soname,$(LIBNAME).so.$(LIBMAJOR)
LIB=../lib/
INC=../include/

TARGETS=$(shell ls *.cc | sed s/.cc/.o/g)

all: $(TARGETS) link clean

clean:
	@echo "Removing all .o files."
	@rm -f *.o

install:
	mkdir -p $(DESTDIR)/usr/include
	mkdir -p $(DESTDIR)/usr/lib
	cp -r $(INC)* $(DESTDIR)/usr/include/
	cp -r $(LIB)* $(DESTDIR)/usr/lib/

link:
	$(CXX) $(TARGETS) $(LDFLAGS)  -o $(LIB)$(LIBNAME).so

.cc.o:
	$(CXX) $(CFLAGS) -I$(INC) -c -o $@ $<
