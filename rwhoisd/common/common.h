/* *************************************************************
   RWhois Software

   Copyright (c) 1994 Scott Williamson and Mark Kosters
   Copyright (c) 1996-2000 Network Solutions, Inc.

   See the file LICENSE for conditions of use and distribution.
**************************************************************** */

/* This header file describes common macros and defines for
   cross-platform support */

#ifndef _COMMON_H_
#define _COMMON_H_

/* the name 'log' conflicts with gcc-3.1 builtin
 * Bill Campbell <bill@celestial.com>
 */
#define log rwhoisd_log

/* Add prototype support.  */
#ifndef PROTO
#if defined (USE_PROTOTYPES) ? USE_PROTOTYPES : defined (__STDC__)
#define PROTO(ARGS) ARGS
#else
#define PROTO(ARGS) ()
#endif
#endif

/* global includes */
#include "config.h"

/* system includes -- all files should just include this file, rather
   than include stdio.h, et al. themselves. */

/* I guess that everyonse has these... */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/param.h>
#include <arpa/inet.h>

#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <stdarg.h>

/* this should probably be #ifdef USG */
#ifndef HAVE_GETHOSTNAME
#include <sys/utsname.h>
#endif /* ! HAVE_GETHOSTNAME */

#include <sys/wait.h>
#include <fcntl.h>
/* #include <inttypes.h> */
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <syslog.h>
#include <unistd.h>

#include <dirent.h>
#define NAMLEN(dirent) strlen((dirent)->d_name)

#define bzero(a, b) memset((a), 0, (b))
#define bcopy(a, b, c) memcpy((b), (a), (c))

#endif /* _COMMON_H_ */

