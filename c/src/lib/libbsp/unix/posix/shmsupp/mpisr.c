/*  Shm_setvec
 *
 *  This driver routine sets the SHM interrupt vector to point to the
 *  driver's SHM interrupt service routine.
 *
 *  Input parameters:  NONE
 *
 *  Output parameters: NONE
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

#include <bsp.h>
#include <shm.h>

void Shm_setvec( void )
{
  int vector;

  vector = _CPU_SHM_Get_vector();

  if ( vector )
    set_vector( Shm_isr, vector, 1 );
}
