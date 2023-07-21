/* *************************************************************
   RWhois Software

   Copyright (c) 1994 Scott Williamson and Mark Kosters
   Copyright (c) 1996-2000 Network Solutions, Inc.

   See the file LICENSE for conditions of use and distribution.
**************************************************************** */

#include "security.h"

#include "log.h"
#include "read_config.h"
#include "main_config.h"
#include "types.h"

/***************************************************************************
sets up a security playground by doing a chroot and setuid (taken
from W.Z. Venema's chrootuid code.

returns TRUE if ok
        FALSE otherwise
****************************************************************************/
int
setup_security()
{
  struct passwd *pwd    = NULL;
  char          *userid = NULL;
  int           id      = getuid();

  /* get the userid information *before* chrooting */
  userid = get_process_userid();
  if (id == 0 && STR_EXISTS(userid))
  {
    if ((pwd = getpwnam(userid)) == 0)
    {
      log(L_LOG_WARNING, CONFIG,
          "'%s' user id is unknown -- unable to change id", 
          userid);
    }
  }

  /* attempt to chroot(), if asked to do so */
  if (is_chrooted())
  {
    if (id != 0)
    {
      log(L_LOG_ERR, CONFIG, "Must be root to perform chroot");
    }

    /* now attempt to chroot() */
    if (chroot(get_root_dir())) {
      log(L_LOG_ERR, CONFIG, "chroot to (%s) failed: %s", get_root_dir(),
          strerror(errno));
      return FALSE;
    }

    /* now that we've chrooted, the root directory is now '/' only */
    set_root_dir("/");
    chdir_root_dir();
  }
  
  /* change the user id of the process, if we can */
  if (id == 0)
  {
    /* don't change user id if the value is NULL */
    if (STR_EXISTS(userid) && pwd)
    {
      /* change group id first */
      if (setgid(pwd->pw_gid))
      {
        log(L_LOG_ERR, CONFIG, "setup_security: setgid failed");
        return FALSE;
      }
      /* now change user id */
      if (setuid(pwd->pw_uid))
      {
        log(L_LOG_ERR, CONFIG, "setup_security: setuid failed");
        return (FALSE);
      }
      /* In case we still have the /etc/passwd file still open. */
      endpwent();
    }
    else
    {
      log(L_LOG_WARNING, CONFIG, "running as root");
    }
  }

  /* if we got this far, everything went OK */
  return TRUE;
}

/****************************************************************************
 restricts who can run the command
   returns TRUE if can
           FALSE if not
****************************************************************************/
int
authorized_directive(directive)
  char *directive;
{
/* XXX This used to (conditionally) call tcpwrappers.
 *     I have ripped out support for tcpwrappers.
 *     Maybe this will get replaced with something else ...
 */
  return TRUE;
}

int
authorized_client()
{
  return( authorized_directive( "rwhoisd" ) );
}
