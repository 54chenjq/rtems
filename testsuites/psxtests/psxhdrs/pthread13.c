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
 
#ifndef _POSIX_THREAD_PRIORITY_SCHEDULING
#error "RTEMS is supposed to have pthread_attr_setscope"
#endif

void test( void )
{
  pthread_attr_t  attr;
  int             contentionscope;
  int             result;

  contentionscope = PTHREAD_SCOPE_SYSTEM;
  contentionscope = PTHREAD_SCOPE_PROCESS;

  result = pthread_attr_setscope( &attr, contentionscope );
}
