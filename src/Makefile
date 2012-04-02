BUILDCHAIN=../meta/buildchain/
include $(BUILDCHAIN)/library-info.mk

LIB=../lib/
INC=../include/

TARGETS=$(shell ls *.cc | sed s/.cc/.o/g)
CXXFLAGS=-Wall -c -fPIC -I$(INC)
CXX=g++

LDFLAGS=-shared \
	-Wl,-soname,$(LIBRARY_NAME).so.$(LIBRARY_VERSION_MAJOR)

OUTPUT=$(LIB)$(LIBRARY_NAME).so.$(LIBRARY_VERSION_MINOR)

all: $(TARGETS) link

clean:
	rm -f *.o
	rm -f $(OUTPUT)

include $(BUILDCHAIN)build.mk
