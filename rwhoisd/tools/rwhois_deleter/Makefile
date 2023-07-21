.POSIX:

BINDIR=		/usr/local/bin

COMMON_INC  = -I../../common
COMMON_LIBS = -L../../common -lrwcommon

MKDB_INC = -I../../mkdb
MKDB_LIBS = -L../../mkdb -lmkdb

REGEXP_INC = -I../../regexp
REGEXP_LIBS = -L../../regexp -lregexp

# options
LOCAL_INC = -I../.. $(COMMON_INC) $(MKDB_INC) $(REGEXP_INC)
LOCAL_LIBS = $(MKDB_LIBS) $(COMMON_LIBS) $(REGEXP_LIBS)

ALL_CFLAGS = $(CFLAGS) $(LOCAL_INC) $(LOCAL_OPTIONS)

LIBS    = $(LOCAL_LIBS)

OBJS = rwhois_deleter.o

all: rwhois_deleter

rwhois_deleter: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(ALL_CFLAGS) -c $<

# procedural

install:
	if [ ! -d $(DESTDIR)$(BINDIR) ]; then mkdir -p $(DESTDIR)$(bindir); fi
	$(INSTALL) rwhois_deleter $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/rwhois_deleter

clean:
	rm -f *.o rwhois_deleter

distclean: clean
