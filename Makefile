SUBDIRS=src lib tests
.PHONY: subdirs $(SUBDIRS)
     
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
     
lib: src
tests: lib

all: subdirs
