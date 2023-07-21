.POSIX:

COMMON_INC  = -I../common
COMMON_LIBS = -L../common -lrwcommon

REGEXP_INC  = -I../regexp
REGEXP_LIBS = -L../regexp -lregexp

# options
LOCAL_INC   = -I.. $(COMMON_INC) $(REGEXP_INC)
LOCAL_LIBS  = $(COMMON_LIBS) $(REGEXP_LIBS)

LOCAL_OPTIONS =

ALL_CFLAGS = $(CFLAGS) $(LOCAL_INC) $(LOCAL_OPTIONS)

LIBS    = $(LOCAL_LIBS)

PARSEOBJS = y.tab.o \
            lex.yy.o
OBJS =  \
        anon_record.o \
        delete.o \
        fileinfo.o \
        index.o \
        index_file.o \
        metaphon.o \
        records.o \
        search.o \
        search_prim.o \
        $(PARSEOBJS)

#
# rwhois files
#

all: libmkdb.a

libmkdb.a:$(OBJS)
	$(AR) cru $@ $(OBJS)
	$(RANLIB) $@

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(ALL_CFLAGS) -c $<

#
# lex and yacc specific dependancies
#

# note that using '$<' to refer to the first dependency is unsafe, so
# we have to refer to dependency directly in the rule.
y.tab.c: parse.y
	$(YACC) -d parse.y

lex.yy.c: parse.l
	$(LEX) parse.l

# administrative rules

install:

uninstall:

clean:
	rm -f *.o *.a

distclean: clean
