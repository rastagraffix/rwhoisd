.POSIX:

INSTALL = install

SUBDIRS = rwhois_indexer rwhois_deleter rwhois_repack

all:
	@for dir in $(SUBDIRS); do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

install:
	@for dir in $(SUBDIRS); do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

uninstall:
	@for dir in $(SUBDIRS); do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

clean:
	@for dir in $(SUBDIRS) ; do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

distclean: config-clean
	@for dir in $(SUBDIRS); do \
	  echo "making $@ in $$dir"; \
	  (cd $$dir; $(MAKE) $(MFLAGS) $@) || exit 1; \
	done

config-clean:
