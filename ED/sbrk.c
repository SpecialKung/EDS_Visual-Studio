/*********************************************************************
*
* Device     : RX
*
* File Name  : sbrk.c
*
* Abstract   : Program of sbrk.
*
* History    : 1.00  (2009-08-07)
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2009 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
*
*********************************************************************/

#include <stddef.h>
#include <stdio.h>
#include "typedefine.h"
#include "sbrk.h"

SBYTE  *sbrk(size_t size);

//const size_t _sbrk_size=		/* Specifies the minimum unit of	*/
					/* the defined heap area		*/

extern SBYTE *_s1ptr;

union HEAP_TYPE {
    SWORD  dummy ;		/* Dummy for 4-byte boundary			*/
    SBYTE heap[HEAPSIZE];	/* Declaration of the area managed by sbrk	*/
};

static union HEAP_TYPE heap_area ;

/* End address allocated by sbrk	*/
static SBYTE *brk=(SBYTE *)&heap_area;

/**************************************************************************/
/*     sbrk:Memory area allocation                                        */
/*          Return value:Start address of allocated area (Pass)           */
/*                       -1                              (Failure)        */
/**************************************************************************/
SBYTE  *sbrk(size_t size)                      /* Assigned area size   */
{
    SBYTE  *p;

    if(brk+size > heap_area.heap+HEAPSIZE){     /* Empty area size      */
        p = (SBYTE *)-1;
    }
    else {
        p = brk;                                /* Area assignment      */
        brk += size;                            /* End address update   */
    }
    return p;
}

