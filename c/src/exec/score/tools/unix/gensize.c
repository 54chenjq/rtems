/*
 *  gensize.c
 *
 *  This file generates the file unixsize.h
 *
 *  NOTE:  It only prints the minimal information required.
 *
 *  COPYRIGHT (c) 1989-1997.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id$
 *
 */

/* 
 *  This feels like a very crude way to determine if we are on a Solaris
 *  host but it does work.
 */

#if defined(__sun__) && defined(__sparc__) && \
    defined(__unix__) && defined(__svr4__)
#undef  _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 3
#undef  __STRICT_ANSI__
#endif

#include <stdio.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>

typedef struct {
  jmp_buf     regs;
  int         isr_level;
} Context_Control;

int main(
  int argc,
  char **argv
)
{
  Context_Control *cc = 0;

  /*
   * Print the file header
   */

printf(
  "/*  unixsize.h\n"
  " *\n"
  " *  This include file contans the size of the context control block\n"
  " *  C data structure.  This structure must be defined in such a way\n"
  " *  that files NOT including the native header files can work.\n"
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
  "#ifndef __UNIXSIZE_h\n"
  "#define __UNIXSIZE_h\n"
  "\n"
);

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

  PRINT_COMMENT("Context_Control information");

  PRINT_SIZE("CPU_CONTEXT_SIZE_IN_BYTES", sizeof( Context_Control ) );
  PRINT_SIZE("CPU_CONTEXT_REGISTERS_OFFSET_IN_BYTES", (int) &cc->regs );
  PRINT_SIZE("CPU_CONTEXT_SIGNALS_OFFSET_IN_BYTES", (int) &cc->isr_level );

  /*
   *  Print the end of file stuff
   */

   printf(
    "\n"
    "#endif    /* __UNIXSIZE_h  */\n"
    "\n"
    "/* end of include file */\n"
  );

  return 0;
}

