.POSIX:

INSTALL = install

# main directories
SBINDIR     = /usr/local/sbin


# local libs/includes 
COMMON_INC    = -I../common
COMMON_LIBS   = -L../common -lrwcommon

MKDB_INC      = -I../mkdb
MKDB_LIBS     = -L../mkdb -lmkdb

REGEXP_INC    = -I../regexp
REGEXP_LIBS   = -L../regexp -lregexp

LOCAL_INC     = -I. -I.. $(COMMON_INC) $(MKDB_INC) $(REGEXP_INC)
LOCAL_LIBS    = $(MKDB_LIBS) $(COMMON_LIBS) $(REGEXP_LIBS)

ALL_CFLAGS = $(CFLAGS) $(LOCAL_INC)

LIBS = $(LOCAL_LIBS)

OBJS = \
       class_directive.o \
       daemon.o \
       deadman.o \
       directive.o \
       display.o \
       dump.o \
       exit.o \
       forward.o \
       guardian.o \
       holdconnect.o \
       limit.o \
       main.o \
       notify.o \
       referral.o \
       register.o \
       reg_ext.o \
       reg_utils.o \
       register_directive.o \
       rwhois_directive.o \
       schema_directive.o \
       security.o \
       security_directive.o \
       session.o \
       soa.o \
       sresponse.o \
       sschema.o \
       sslave.o \
       ssoa.o \
       sstate.o \
       state.o \
       status.o \
       sxfer.o \
       xfer.o 


#
# rwhois files
#

all: rwhoisd

rwhoisd: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(ALL_CFLAGS) $(LOCAL_INC) -c $<

#
# Procedural
#

install:
	if [ ! -d $(DESTDIR)$(sbindir) ]; then mkdir -p $(DESTDIR)$(sbindir); fi
	$(INSTALL) rwhoisd $(DESTDIR)$(sbindir)

uninstall:
	rm -f $(DESTDIR)$(sbindir)/rwhoisd

clean:
	rm -f *.[oa]
	rm -f rwhoisd

distclean: clean
