/*
 *  genoffsets.c
 *
 *  This file generates the offsets.h for the HP PA-RISC port of RTEMS.
 *
 *  NOTE:  It only prints the offset for structures actually used
 *         by the assembly code.
 *
 *  COPYRIGHT (c) 1989-1997.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id$
 */

#include <stdio.h>

#if defined(__hpux__) && defined(__hppa__)
#include <rtems/system.h>
#endif

void print_information( void );

int main(
  int argc,
  char **argv
)
{
#if defined(__hpux__) && defined(__hppa__)
  unsigned int size = 0;
#endif

  /*
   * Print the file header
   */

printf(
  "/*  offsets.h\n"
  " *\n"
  " *  This include file contains the offsets of elements in the\n"
  " *  C data structures used by the assembly language code for the\n"
  " *  HP PA-RISC 1.1 port of RTEMS.\n"
  " *\n"
  " *  NOTE:  THIS FILE IS AUTOMATICALLY GENERATED!!!!\n"
  " *         DO NOT EDIT THIS BY HAND!!!!\n"
  " *\n"
  " *  COPYRIGHT (c) 1989-1997.\n"
  " *  On-Line Applications Research Corporation (OAR).\n"
  " *  Copyright assigned to U.S. Government, 1994.\n"
  " *\n"
  " *  The license and distribution terms for this file may be\n"
  " *  found in the file LICENSE in this distribution or at\n"
  " *  http://www.OARcorp.com/rtems/license.html.\n"
  " */\n"
  "\n"
  "#ifndef __OFFSETS_h\n"
  "#define __OFFSETS_h\n"
  "\n"
);

#define PRINT_IT( STRING, TYPE, FIELD ) \
  printf( "#define\t%s\t0x%p\t\t/* %d */\n", \
          STRING, \
          &((TYPE)0)->FIELD, \
          (int) &((TYPE)0)->FIELD );

#define PRINT_SIZE( STRING, item ) \
  printf( "#ifdef ASM\n#define\t%s\t%d\t\t/* 0x%x */\n#endif\n", \
          STRING, \
          sizeof(item), \
          sizeof(item) );

#define PRINT_COMMENT( STRING ) \
  printf(       \
    "\n"        \
    "/*\n"      \
    " * " STRING "\n" \
    " */\n"     \
    "\n"        \
  );

#if defined(__hpux__) && defined(__hppa__)

/*
 *  Offsets of elements in the Context_control structure.
 */

  PRINT_COMMENT("Context_Control information");

  PRINT_IT( "FLAGS_OFFSET", Context_Control *, flags );
  PRINT_IT( "R1_OFFSET", Context_Control *, gr1 );
  PRINT_IT( "R2_OFFSET", Context_Control *, gr2 );
  PRINT_IT( "R3_OFFSET", Context_Control *, gr3 );
  PRINT_IT( "R4_OFFSET", Context_Control *, gr4 );
  PRINT_IT( "R5_OFFSET", Context_Control *, gr5 );
  PRINT_IT( "R6_OFFSET", Context_Control *, gr6 );
  PRINT_IT( "R7_OFFSET", Context_Control *, gr7 );
  PRINT_IT( "R8_OFFSET", Context_Control *, gr8 );
  PRINT_IT( "R9_OFFSET", Context_Control *, gr9 );
  PRINT_IT( "R10_OFFSET", Context_Control *, gr10 );
  PRINT_IT( "R11_OFFSET", Context_Control *, gr11 );
  PRINT_IT( "R12_OFFSET", Context_Control *, gr12 );
  PRINT_IT( "R13_OFFSET", Context_Control *, gr13 );
  PRINT_IT( "R14_OFFSET", Context_Control *, gr14 );
  PRINT_IT( "R15_OFFSET", Context_Control *, gr15 );
  PRINT_IT( "R16_OFFSET", Context_Control *, gr16 );
  PRINT_IT( "R17_OFFSET", Context_Control *, gr17 );
  PRINT_IT( "R18_OFFSET", Context_Control *, gr18 );
  PRINT_IT( "R19_OFFSET", Context_Control *, gr19 );
  PRINT_IT( "R20_OFFSET", Context_Control *, gr20 );
  PRINT_IT( "R21_OFFSET", Context_Control *, gr21 );
  PRINT_IT( "R22_OFFSET", Context_Control *, gr22 );
  PRINT_IT( "R23_OFFSET", Context_Control *, gr23 );
  PRINT_IT( "R24_OFFSET", Context_Control *, gr24 );
  PRINT_IT( "R25_OFFSET", Context_Control *, gr25 );
  PRINT_IT( "R26_OFFSET", Context_Control *, gr26 );
  PRINT_IT( "R27_OFFSET", Context_Control *, gr27 );
  PRINT_IT( "R28_OFFSET", Context_Control *, gr28 );
  PRINT_IT( "R29_OFFSET", Context_Control *, gr29 );
  PRINT_IT( "R30_OFFSET", Context_Control *, sp );
  PRINT_IT( "R31_OFFSET", Context_Control *, gr31 );

  /*
   * And common aliases for the above
   */

  PRINT_COMMENT("Common aliases for above");

  PRINT_IT( "RP_OFFSET",   Context_Control *, gr2 );
  PRINT_IT( "ARG3_OFFSET", Context_Control *, gr23 );
  PRINT_IT( "ARG2_OFFSET", Context_Control *, gr24 );
  PRINT_IT( "ARG1_OFFSET", Context_Control *, gr25 );
  PRINT_IT( "ARG0_OFFSET", Context_Control *, gr26 );
  PRINT_IT( "SP_OFFSET",   Context_Control *, sp );
  PRINT_IT( "DP_OFFSET",   Context_Control *, gr27 );
  PRINT_IT( "RET0_OFFSET", Context_Control *, gr28 );
  PRINT_IT( "RET1_OFFSET", Context_Control *, gr29 );

  PRINT_SIZE("CPU_CONTEXT_SIZE", Context_Control);

  PRINT_COMMENT("Context_Control_fp information");

  PRINT_IT( "FR0_OFFSET", Context_Control_fp *, fr0 );
  PRINT_IT( "FR1_OFFSET", Context_Control_fp *, fr1 );
  PRINT_IT( "FR2_OFFSET", Context_Control_fp *, fr2 );
  PRINT_IT( "FR3_OFFSET", Context_Control_fp *, fr3 );
  PRINT_IT( "FR4_OFFSET", Context_Control_fp *, fr4 );
  PRINT_IT( "FR5_OFFSET", Context_Control_fp *, fr5 );
  PRINT_IT( "FR6_OFFSET", Context_Control_fp *, fr6 );
  PRINT_IT( "FR7_OFFSET", Context_Control_fp *, fr7 );
  PRINT_IT( "FR8_OFFSET", Context_Control_fp *, fr8 );
  PRINT_IT( "FR9_OFFSET", Context_Control_fp *, fr9 );
  PRINT_IT( "FR10_OFFSET", Context_Control_fp *, fr10 );
  PRINT_IT( "FR11_OFFSET", Context_Control_fp *, fr11 );
  PRINT_IT( "FR12_OFFSET", Context_Control_fp *, fr12 );
  PRINT_IT( "FR13_OFFSET", Context_Control_fp *, fr13 );
  PRINT_IT( "FR14_OFFSET", Context_Control_fp *, fr14 );
  PRINT_IT( "FR15_OFFSET", Context_Control_fp *, fr15 );
  PRINT_IT( "FR16_OFFSET", Context_Control_fp *, fr16 );
  PRINT_IT( "FR17_OFFSET", Context_Control_fp *, fr17 );
  PRINT_IT( "FR18_OFFSET", Context_Control_fp *, fr18 );
  PRINT_IT( "FR19_OFFSET", Context_Control_fp *, fr19 );
  PRINT_IT( "FR20_OFFSET", Context_Control_fp *, fr20 );
  PRINT_IT( "FR21_OFFSET", Context_Control_fp *, fr21 );
  PRINT_IT( "FR22_OFFSET", Context_Control_fp *, fr22 );
  PRINT_IT( "FR23_OFFSET", Context_Control_fp *, fr23 );
  PRINT_IT( "FR24_OFFSET", Context_Control_fp *, fr24 );
  PRINT_IT( "FR25_OFFSET", Context_Control_fp *, fr25 );
  PRINT_IT( "FR26_OFFSET", Context_Control_fp *, fr26 );
  PRINT_IT( "FR27_OFFSET", Context_Control_fp *, fr27 );
  PRINT_IT( "FR28_OFFSET", Context_Control_fp *, fr28 );
  PRINT_IT( "FR29_OFFSET", Context_Control_fp *, fr29 );
  PRINT_IT( "FR30_OFFSET", Context_Control_fp *, fr30 );
  PRINT_IT( "FR31_OFFSET", Context_Control_fp *, fr31 );

  PRINT_SIZE("CPU_CONTEXT_FP_SIZE", Context_Control_fp);

  /*
   *  And the control registers
   */

  PRINT_COMMENT("Control register portion of context");

  PRINT_IT( "SAR_OFFSET", Context_Control *, sar );
  PRINT_IT( "IPSW_OFFSET", Context_Control *, ipsw );
  PRINT_IT( "IIR_OFFSET", Context_Control *, iir );
  PRINT_IT( "IOR_OFFSET", Context_Control *, ior );
  PRINT_IT( "ISR_OFFSET", Context_Control *, isr );
  PRINT_IT( "PCOQFRONT_OFFSET", Context_Control *, pcoqfront );
  PRINT_IT( "PCOQBACK_OFFSET", Context_Control *, pcoqback );
  PRINT_IT( "PCSQFRONT_OFFSET", Context_Control *, pcsqfront );
  PRINT_IT( "PCSQBACK_OFFSET", Context_Control *, pcsqback );
  PRINT_IT( "ITIMER_OFFSET", Context_Control *, itimer );

  /*
   *  Full interrupt frame (integer + float)
   */
  PRINT_COMMENT("Interrupt frame information");

  PRINT_IT( "INTEGER_CONTEXT_OFFSET", CPU_Interrupt_frame *, Integer );
  PRINT_IT( "FP_CONTEXT_OFFSET", CPU_Interrupt_frame *, Floating_Point );
  size = sizeof( CPU_Interrupt_frame );

  if ( size % CPU_STACK_ALIGNMENT )
    size += CPU_STACK_ALIGNMENT - (size % CPU_STACK_ALIGNMENT);

  printf( "#define\tCPU_INTERRUPT_FRAME_SIZE\t%d\t\t/* 0x%x */\n", size, size );

#else

  print_information();

#endif

#undef PRINT_IT
#undef PRINT_SIZE
#undef PRINT_COMMENT

  /*
   *  Print the end of file stuff
   */

   printf(
    "\n"
    "#endif    /* __OFFSETS_h  */\n"
    "\n"
    "/* end of include file */\n"
  );

  return 0;
}

void print_information( void )
{

#define PRINT_IT( STRING, NUMBER ) \
  printf( "#define\t%s\t0x%x\t\t/* %d */\n", \
          STRING, \
          NUMBER, \
          NUMBER );

#define PRINT_SIZE( STRING, NUMBER ) \
  printf( "#define\t%s\t0x%x\t\t/* %d */\n", \
          STRING, \
          NUMBER, \
          NUMBER );

#define PRINT_COMMENT( STRING ) \
  printf(       \
    "\n"        \
    "/*\n"      \
    " * " STRING "\n" \
    " */\n"     \
    "\n"        \
  );

/*
 *  Offsets of elements in the Context_control structure.
 */

  PRINT_COMMENT("Context_Control information");

  PRINT_IT( "FLAGS_OFFSET",  0x00 );
  PRINT_IT( "R1_OFFSET",     0x04 );
  PRINT_IT( "R2_OFFSET",     0x08 );
  PRINT_IT( "R3_OFFSET",     0x0c );
  PRINT_IT( "R4_OFFSET",     0x00 );
  PRINT_IT( "R5_OFFSET",     0x14 );
  PRINT_IT( "R6_OFFSET",     0x18 );
  PRINT_IT( "R7_OFFSET",     0x1c );
  PRINT_IT( "R8_OFFSET",     0x20 );
  PRINT_IT( "R9_OFFSET",     0x24 );
  PRINT_IT( "R10_OFFSET",    0x28 );
  PRINT_IT( "R11_OFFSET",    0x2c );
  PRINT_IT( "R12_OFFSET",    0x30 );
  PRINT_IT( "R13_OFFSET",    0x34 );
  PRINT_IT( "R14_OFFSET",    0x38 );
  PRINT_IT( "R15_OFFSET",    0x3c );
  PRINT_IT( "R16_OFFSET",    0x40 );
  PRINT_IT( "R17_OFFSET",    0x44 );
  PRINT_IT( "R18_OFFSET",    0x48 );
  PRINT_IT( "R19_OFFSET",    0x4c );
  PRINT_IT( "R20_OFFSET",    0x50 );
  PRINT_IT( "R21_OFFSET",    0x54 );
  PRINT_IT( "R22_OFFSET",    0x58 );
  PRINT_IT( "R23_OFFSET",    0x5c );
  PRINT_IT( "R24_OFFSET",    0x60 );
  PRINT_IT( "R25_OFFSET",    0x64 );
  PRINT_IT( "R26_OFFSET",    0x68 );
  PRINT_IT( "R27_OFFSET",    0x6c );
  PRINT_IT( "R28_OFFSET",    0x70 );
  PRINT_IT( "R29_OFFSET",    0x74 );
  PRINT_IT( "R30_OFFSET",    0x78 );
  PRINT_IT( "R31_OFFSET",    0x7c );

  /*
   * And common aliases for the above
   */

  PRINT_COMMENT("Common aliases for above");

  PRINT_IT( "RP_OFFSET",   0x08 );
  PRINT_IT( "ARG3_OFFSET", 0x5c );
  PRINT_IT( "ARG2_OFFSET", 0x60 );
  PRINT_IT( "ARG1_OFFSET", 0x64 );
  PRINT_IT( "ARG0_OFFSET", 0x68 );
  PRINT_IT( "SP_OFFSET",   0x78 );
  PRINT_IT( "DP_OFFSET",   0x6c );
  PRINT_IT( "RET0_OFFSET", 0x74 );
  PRINT_IT( "RET1_OFFSET", 0x74 );

  PRINT_SIZE("CPU_CONTEXT_SIZE", 168 );

  PRINT_COMMENT("Context_Control_fp information");

  PRINT_SIZE("CPU_CONTEXT_FP_SIZE", 256);

  /*
   *  And the control registers
   */

  PRINT_COMMENT("Control register portion of context");

  PRINT_IT( "SAR_OFFSET",        0x80 );
  PRINT_IT( "IPSW_OFFSET",       0x84 );
  PRINT_IT( "IIR_OFFSET",        0x88 );
  PRINT_IT( "IOR_OFFSET",        0x8c );
  PRINT_IT( "ISR_OFFSET",        0x90 );
  PRINT_IT( "PCOQFRONT_OFFSET",  0x94 );
  PRINT_IT( "PCOQBACK_OFFSET",   0x98 );
  PRINT_IT( "PCSQFRONT_OFFSET",  0x9c );
  PRINT_IT( "PCSQBACK_OFFSET",   0xa0 );
  PRINT_IT( "ITIMER_OFFSET",     0xa4 );

  /*
   *  Full interrupt frame (integer + float)
   */

  PRINT_COMMENT("Interrupt frame information");

  PRINT_IT( "INTEGER_CONTEXT_OFFSET",   0x00 );
  PRINT_IT( "FP_CONTEXT_OFFSET",        0xa8 );
  PRINT_SIZE( "CPU_INTERRUPT_FRAME_SIZE", 448 );

}
