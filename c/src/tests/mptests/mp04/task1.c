/*  Test_task
 *
 *  This task tests the rtems_task_set_priority directive on a remote task.
 *
 *  Input parameters:
 *    argument - task argument
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

extern rtems_multiprocessing_table Multiprocessing_configuration;

rtems_task Test_task(
  rtems_task_argument argument
)
{
  rtems_id            tid;
  rtems_status_code   status;
  rtems_unsigned32    remote_node;
  rtems_id            remote_tid;
  rtems_task_priority previous_priority;
  rtems_task_priority previous_priority_1;

  status = rtems_task_ident( RTEMS_SELF, RTEMS_SEARCH_ALL_NODES, &tid );
  directive_failed( status, "rtems_task_ident" );

  puts( "Getting TID of remote task" );
  remote_node = (Multiprocessing_configuration.node == 1) ? 2 : 1;
  puts_nocr( "Remote task's name is : " );
  put_name( Task_name[ remote_node ], TRUE );

  do {
      status = rtems_task_ident(
          Task_name[ remote_node ],
          RTEMS_SEARCH_ALL_NODES,
          &remote_tid
          );
  } while ( status != RTEMS_SUCCESSFUL );

  directive_failed( status, "rtems_task_ident" );

  status = rtems_task_set_priority(
    remote_tid,
    Multiprocessing_configuration.node,
    &previous_priority
  );
  directive_failed( status, "rtems_task_set_priority" );

  if ( previous_priority != remote_node ) {
    printf(
      "Remote priority (0x%x) does not match remote node (0x%x)!!!\n",
      previous_priority,
      remote_node
    );
    exit( 0xf0000 );
  }

  do {
    status = rtems_task_set_priority(
      RTEMS_SELF,
      RTEMS_CURRENT_PRIORITY,
      &previous_priority_1
    );
    directive_failed( status, "rtems_task_set_priority" );
  } while ( previous_priority_1 != remote_node );

  puts( "Local task priority has been set" );

  puts( "*** END OF TEST 4 ***" );
  exit( 0 );
}
