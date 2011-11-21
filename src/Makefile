CXX=g++

include ../meta/libinf.mk

CFLAGS=-Wall -c -fPIC -DANSIESCAPE_DEBUG=YES
LDFLAGS=-shared -Wl,-soname,$(LIBNAME).so.$(LIBMAJOR)
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
	$(CXX) $(LDFLAGS) $(TARGETS) -o $(LIB)$(LIBNAME).so.$(LIBMINOR)

translist:
	@grep \&ansi_state_ . -r | grep -v ./ansiescape.cc | sed s/:.*\&/\ /g | \
		sed s/ansi_state_//g | sed s/\;.*$$//g | sed 's/^\.\///g' | sed 's/\.cc//g' \
		| sort | uniq

.cc.o:
	$(CXX) $(CFLAGS) -I$(INC) -c -o $@ $<
