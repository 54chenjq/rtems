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

#include <pthread.h>
 
#ifndef _POSIX_THREADS
#error "rtems is supposed to have pthread_mutex_timedlock"
#endif
#ifndef _POSIX_TIMEOUTS
#error "rtems is supposed to have pthread_mutex_timedlock"
#endif

void test( void )
{
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  struct timespec timeout;
  int result;

  result = pthread_mutex_timedlock( &mutex, &timeout );
}
