CXX=g++

LIBNAME=libansi
LIBMAJOR=1
LIBMINOR=1.0.0

CFLAGS=-Wall -c -fPIC 
LDFLAGS=-shared -Wl,-soname,$(LIBNAME).so.$(LIBMAJOR)
LIB=../lib/
INC=../include/

TARGETS=$(shell ls *.cc | sed s/.cc/.o/g)


all: $(TARGETS) link clean

clean:
	@echo "Removing all .o files."
	@rm -f *.o

link:
	$(CXX) $(TARGETS) $(LDFLAGS)  -o $(LIB)$(LIBNAME).so.$(LIBMINOR)

.cc.o:
	$(CXX) $(CFLAGS) -I$(INC) -c -o $@ $<
