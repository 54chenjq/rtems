/*
 *  This test file is used to verify that the header files associated with
 *  the callout are correct.
 *
 *  COPYRIGHT (c) 1989-1997. 1995, 1996.
 *  On-Line Applications Research Corporation (OAR).
 *  Copyright assigned to U.S. Government, 1994.
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id$
 */

#include <time.h>
 
#ifndef _POSIX_TIMERS
#error "rtems is supposed to have timer_gettime"
#endif

void test( void )
{
  timer_t           timerid = 0;
  struct itimerspec value;
  int               result;

  result = timer_gettime( timerid, &value );
}
