.POSIX:

# options
LOCAL_INC = -I.
LOCAL_LIBS = 
LOCAL_OPTIONS = 

CFLAGS  = -g -O $(LOCAL_INC) $(LOCAL_OPTIONS)
LDFLAGS = 


OBJS = \
        regerror.o \
        regexp.o \
        regsub.o


all: libregexp.a

libregexp.a:$(OBJS)
	$(AR) cru libregexp.a $(OBJS)
	$(RANLIB) libregexp.a

.c.o:
	$(CC) -c $(CFLAGS) $*.c

clean:
	rm -f *.[oa]

distclean: clean
