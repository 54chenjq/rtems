/*  Timer_functions
 *
 *  These routines are the timer service routines used by this test.
 *
 *  Input parameters:  NONE
 *
 *  Output parameters:  NONE
 *
 *  COPYRIGHT (c) 1989-1997.
 *  On-Line Applications Research Corporation (OAR).
 *  Copyright assigned to U.S. Government, 1994.
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id$
 */

#include "system.h"

rtems_timer_service_routine TA1_send_18_to_self_5_seconds(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 1 ], RTEMS_EVENT_18 );
  directive_failed( status, "rtems_event_send of 18" );
}

rtems_timer_service_routine TA1_send_8_to_self_60_seconds(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 1 ], RTEMS_EVENT_8 );
  directive_failed( status, "rtems_event_send of 8" );
}

rtems_timer_service_routine TA1_send_9_to_self_60_seconds(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 1 ], RTEMS_EVENT_9 );
  directive_failed( status, "rtems_event_send of 9" );
}

rtems_timer_service_routine TA1_send_10_to_self(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 1 ], RTEMS_EVENT_10 );
  directive_failed( status, "rtems_event_send of 10" );
}

rtems_timer_service_routine TA1_send_1_to_self_every_second(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 1 ], RTEMS_EVENT_1 );
  directive_failed( status, "rtems_event_send of 1" );
}

rtems_timer_service_routine TA1_send_11_to_self(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 1 ], RTEMS_EVENT_11 );
  directive_failed( status, "rtems_event_send of 11" );
}

rtems_timer_service_routine TA2_send_10_to_self(
  rtems_id  ignored_id,
  void     *ignored_address
)
{
  rtems_status_code status;

  status = rtems_event_send( Task_id[ 2 ], RTEMS_EVENT_10 );
  directive_failed( status, "rtems_event_send of 10" );
}
