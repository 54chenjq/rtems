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

#include <sched.h>

#ifndef _POSIX_PRIORITY_SCHEDULING
#error "rtems is supposed to have sched_setscheduler"
#endif
 
void test( void )
{
  pid_t  pid;
  int    policy;
  struct sched_param param;
  int    result;

  pid = 0;

  policy = SCHED_RR;
  policy = SCHED_FIFO;
  policy = SCHED_OTHER;
#ifdef _POSIX_SPORADIC_SERVER
  policy = SCHED_SPORADIC;
#endif

  /*
   *  really should use sched_get_priority_min() and sched_get_priority_max()
   */

  param.sched_priority = 0;
#ifdef _POSIX_SPORADIC_SERVER
  param.ss_low_priority = 0;
  param.ss_replenish_period.tv_sec = 0;
  param.ss_replenish_period.tv_nsec = 0;
  param.ss_initial_budget.tv_sec = 0;
  param.ss_initial_budget.tv_nsec = 0;
#endif

  result = sched_setscheduler( pid, policy, &param );
}
