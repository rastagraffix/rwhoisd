/* *************************************************************
   RWhois Software

   Copyright (c) 1994 Scott Williamson and Mark Kosters
   Copyright (c) 1996-2000 Network Solutions, Inc.

   See the file LICENSE for conditions of use and distribution.
**************************************************************** */

#include "compat.h"

/* attempt to get the local hostname; returns a static string */

/*    sekiya@ISI.EDU (IPv6 conversion):
 *    I don't modify this function. This function includes gethostbyname
 *    which is IPv4 only function. But in this function, gethostbuname
 *    is used in order to get local FQDN name. I think it has no need to
 *    modify only in order to get local FQDN.
 */
char *
sys_gethostname()
{
  static char       hostname[MAX_HOSTNAME + 1];
  struct hostent    *hp;

  /* first we get the base hostname */

  gethostname(hostname, MAX_HOSTNAME);

  /* now we attempt to get the FQDN */
  hp = gethostbyname(hostname);
  if (hp)
  {
    char *fqdn = (char *) hp->h_name;

    if (!index (fqdn, '.'))
    {
      /* We still don't have a fully qualified domain name.
         Try to find one in the list of alternate names */
      char **alias = hp->h_aliases;
      while (*alias && !index (*alias, '.'))
        alias++;
      if (*alias)
        fqdn = *alias;
    }
    strncpy(hostname, fqdn, MAX_HOSTNAME);

  }
  return(hostname);
}

int
sys_file_lock(fd, op)
  int           fd;
  file_lock_t   op;
{
/*
 * Generally prefer flock(), but I'm leaving the lockf() code
 * in just in case.  I've read rumblings that, in some cases,
 * lockf() is the only one that works over NFS.
 */
#ifdef HAVE_LOCKF
  if (op == FILE_LOCK) {
    return(lockf(fd, F_LOCK, 0));
  }
  else if (op == FILE_UNLOCK) {
    return(lockf(fd, F_ULOCK, 0));
  }
  else if (op == FILE_TEST) {
    return(lockf(fd, F_TEST, 0));
  }
#endif
  if (op == FILE_LOCK) {
    return(flock(fd, LOCK_EX));
  }
  else if (op == FILE_UNLOCK) {
    return(flock(fd, LOCK_UN));
  }
  else if (op == FILE_TEST) {
    return(flock(fd, LOCK_SH | LOCK_NB));
  }
  else {
    return(-1);
  }
}
