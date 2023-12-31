/***********************************************************************/
/*                                                                     */
/*  FILE        :vecttbl.c                                             */
/*  DATE        :Wed, Jul 31, 2013                                     */
/*  DESCRIPTION :Initialize of Vector Table                            */
/*  CPU TYPE    :RX63T                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.51).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
/************************************************************************
*
* Device     : RX/RX600/RX63T
*
* File Name  : vecttbl.c
*
* Abstract   : Initialize of Vector Table.
*
* History    : 1.00  (2012-06-12)  [Hardware Manual Revision : 1.00]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2012 Renesas Electronics Corporation and
* Renesas Solutions Corp. All rights reserved.
*
************************************************************************/

#include "vect.h"
#include "ProgHeader.h"


//#if (APPS_USE_BL == 0) // Start address of Fixed Vectors table is 0xFFFFFFD0

void UndefinedInterruptSource(void){
	
}

#if !BOOTLOADER_ENABLE	// Bootloader enable, Sean, 20141022
#pragma section C FIXEDVECT

void* const Fixed_Vectors[] = {
    
/* 0xffffff90 through 0xffffff9f: Reserved area - must be all 0xFF */
  (void *)0xFFFFFFFF,   /* 0xffffff90 - Reserved */
  (void *)0xFFFFFFFF,   /* 0xffffff94 - Reserved */
  (void *)0xFFFFFFFF,   /* 0xffffff98 - Reserved */

/* The 32-bit area immediately below (0xffffff9c through 0xffffff9f) is a special area that allows the ROM to be 
   protected from reading or writing by a parallel programmer. Please refer to the HW manual for appropriate settings.
   The default (all 0xff) places no restrictions and therefore allows reads and writes by a parallel programmer. */
  (void *)0xFFFFFFFF,   /* 0xffffff9C - ROM Code Protection */

/* The memory are immediately below (0xffffffa0 through 0xffffffaf) is a special area that allows the on-chip firmware 
   to be protected. See the section "ID Code Protection" in the HW manual for details on how to enable protection.  
   Setting the four long words below to non-0xFF values will enable protection.  Do this only after carefully review 
   the HW manual */
   
/* 0xffffffA0 through 0xffffffaf: ID Code Protection */
  (void *) 0xFFFFFFFF,  /* 0xffffffA0 - Control code and ID code */
  (void *) 0xFFFFFFFF,  /* 0xffffffA4 - ID code (cont.) */
  (void *) 0xFFFFFFFF,  /* 0xffffffA8 - ID code (cont.) */
  (void *) 0xFFFFFFFF,  /* 0xffffffAC - ID code (cont.) */
  
/* 0xffffffB0 through 0xffffffcf: Reserved area */
  (void *) 0xFFFFFFFF,  /* 0xffffffB0 - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffB4 - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffB8 - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffBC - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffC0 - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffC4 - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffC8 - Reserved */
  (void *) 0xFFFFFFFF,  /* 0xffffffCC - Reserved */

/* Fixed vector table */
  (void *) Excep_SuperVisorInst,        /* 0xffffffd0  Exception(Supervisor Instruction) */
  (void *) Dummy,   					/* 0xffffffd4  Reserved */
  (void *) Dummy,    					/* 0xffffffd8  Reserved */
  (void *) Excep_UndefinedInst,         /* 0xffffffdc  Exception(Undefined Instruction) */
  (void *) Dummy,    					/* 0xffffffe0  Reserved */
  (void *) Excep_FloatingPoint,         /* 0xffffffe4  Exception(Floating Point) */
  (void *) Dummy,    					/* 0xffffffe8  Reserved */
  (void *) Dummy,    					/* 0xffffffec  Reserved */
  (void *) Dummy,    					/* 0xfffffff0  Reserved */
  (void *) Dummy,    					/* 0xfffffff4  Reserved */
  (void *) NonMaskableInterrupt,        /* 0xfffffff8  NMI */
  (void *) PowerON_Reset_PC             /* 0xfffffffc  RESET */
};
#pragma address MDEreg=0xffffff80 // MDE register (Single Chip Mode)
//#ifdef 1
//const unsigned long MDEreg = 0xfffffff8; // big
//#else
	const unsigned long MDEreg = 0xffffffff; // little
//#endif

//#endif

#endif