.POSIX:

# options

REGEXP_INC    = -I../regexp
REGEXP_LIBS   = -L../regexp -lregexp

LOCAL_INC     = -I.. $(REGEXP_INC)
LOCAL_LIBS    = $(REGEXP_LIBS)
LOCAL_OPTIONS =

ALL_CFLAGS    = $(CFLAGS) $(LOCAL_INC) $(LOCAL_OPTIONS)

LIBS = $(LOCAL_LIBS)

OBJS = attributes.o \
        auth_area.o \
        client_msgs.o \
        compat.o \
        directive_conf.o \
        dir_security.o \
        dl_list.o \
        fileutils.o \
        ip_network.o \
        log.o \
        main_config.o \
        misc.o \
        procutils.o \
        punt_ref.o \
        read_config.o \
        rw_log.o \
        schema.o \
        strutil.o \
        validate_rec.o

#
# rwhois files
#
all: librwcommon.a

librwcommon.a: $(OBJS)
	$(AR) cru $@ $(OBJS)
	$(RANLIB) $@


.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(ALL_CFLAGS) -c $<

# administrative rules

install:

uninstall:

clean:
	rm -f *.[oa]

distclean: clean
