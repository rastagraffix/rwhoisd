.POSIX:

INSTALL = install
SHELL	= /bin/sh

# set prefix values
prefix      = @prefix@
exec_prefix = @exec_prefix@
bindir      = @bindir@
etcdir      = @sysconfdir@

srcdir	    = @srcdir@
VPATH       = @srcdir@

RWHOIS_ROOT_DIR = $(prefix)

#### end of configuration section ####

SAMPLE_DATA_DIR = sample.data
LIB_SUBDIRS     = common mkdb regexp
BIN_SUBDIRS	= server tools
ALL_SUBDIRS	= $(LIB_SUBDIRS) $(BIN_SUBDIRS) $(SAMPLE_DATA_DIR)

all: libraries binaries

libraries:
	@for dir in $(LIB_SUBDIRS); do \
	  echo "making all in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) all) || exit 1; \
	done

binaries:
	@for dir in $(BIN_SUBDIRS); do \
	  echo "making all in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) all) || exit 1; \
	done


install: install-bin install-sample-data

install-bin: 
	@for dir in $(BIN_SUBDIRS); do \
	  echo "making install in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) install) || exit 1; \
	done


install-sample-data: sample-data-install

sample-data-install:
	(cd $(SAMPLE_DATA_DIR); $(MAKE) $(MFLAGS) install) || exit 1

uninstall: uninstall-bin uninstall-sample-data

uninstall-bin:
	@for dir in $(BIN_SUBDIRS); do \
	  echo "making uninstall in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) uninstall) || exit 1; \
	done

uninstall-sample-data:
	(cd $(SAMPLE_DATA_DIR); $(MAKE) $(MFLAGS) uninstall) || exit 1

clean:
	@for dir in $(ALL_SUBDIRS); do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

distclean: config-clean
	@for dir in $(ALL_SUBDIRS); do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

config-clean:
	rm -f config.h config.cache config.status config.log
	rm -f Makefile

dist:
	@echo "Cleaning first"
	($(MAKE) distclean)
	@echo "makeing tar file"
	make_dist.sh . $$(cat VERSION)


