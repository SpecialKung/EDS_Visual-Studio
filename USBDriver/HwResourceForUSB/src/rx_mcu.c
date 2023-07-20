/******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized.
* This software is owned by Renesas Electronics Corporation and is  protected
* under all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY,
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR  A
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE  EXPRESSLY
* DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE  LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this
* software and to discontinue the availability of this software.
* By using this software, you agree to the additional terms and
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
*******************************************************************************
* Copyright (C) 2010(2011) Renesas Electronics Corpration
* and Renesas Solutions Corp. All rights reserved.
*******************************************************************************
* File Name     : rx_rsk.c
* Version       : 2.00
* Device(s)     : RX-Series
* Tool-Chain    : Renesas RX Standard Toolchain
* OS            : Common to None and uITRON 4.0 Spec
* H/W Platform  : Independent
* Description   : RX63T RSK processing
******************************************************************************
* History : DD.MM.YYYY Version Description
*         : 29.06.2012 0.50    First Release
******************************************************************************/

/* $Id: rx_rsk.c 162 2012-05-21 10:20:32Z ssaek $ */

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <machine.h>
#include "USB_CDC.h"
#include "iodefine.h"




/******************************************************************************
Section    <Section Definition> , "Project Sections"
******************************************************************************/
    #pragma address MDEreg=0xffffff80 /* MDE register (Single Chip Mode) */
    #ifdef __BIG
        const unsigned long MDEreg = 0xfffffff8; /* big */
    #else   /* __BIG */
        const unsigned long MDEreg = 0xffffffff; /* little */
    #endif  /* __BIG */

/******************************************************************************
Section    <Section Definition> , "Project Sections"
******************************************************************************/
#pragma section _hw

/******************************************************************************
Renesas Abstracted RSK functions
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_McuInitialize
Description     : MCU Initialize
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_McuInitialize(void)
{
    uint32_t    i;
    
    SYSTEM.PRCR.WORD        = 0xA503;		/* protect off */

    /* Main clock Oscillator register (MOSTP=Not STOP, Default:262144Cycle, Zeus:131072Cycle) */
    /* Sub clock Oscillator control register (SOSTP=STOP) */
    SYSTEM.MOSCCR.BYTE      = 0x00;
    SYSTEM.MOSCWTCR.BYTE    = 0x0D;	//Allen:Default setting 0x0E, Zeus setting 0x0D

    /* PLL control register ( PLIDIV = 12MHz(/1), STC = 192MHz(*16), PLL enable) */
    /* PLL wait control register(Default:0x0F,4194304cycle Zeus:0x0A,131072cycle) */
    SYSTEM.PLLCR.WORD       = 0x0F00;
    SYSTEM.PLLCR2.BYTE      = 0x00;
    SYSTEM.PLLWTCR.BYTE     = 0x0A;	//Allen:Default:0x0F, Zeus setting:0x0A

    /* wait over 11ms */
    for(i = 0;i< 660;i++){}

    /* System clock control register(ICK=PLL/2,BCK,FCK,PCK=PLL/4, CKSEL(10-8)=PLL, UCK(7-4)=48MHz(/4)) */
    SYSTEM.SCKCR.LONG       = 0x21821212;    //Allen:Default:0x21862222, Zeus:0x21821212
    SYSTEM.SCKCR3.WORD      = 0x0400;
    SYSTEM.SCKCR2.BIT.UCK   = 3;	//SYSTEM.SCKCR2.BIT.UCK = 1;    // USB bus clock = 1/2 ICLK

    /* Module stop control register (Disable ACSE) */
    SYSTEM.MSTPCRA.LONG     = 0x7FFFFFFF;

    /* protect on */
    SYSTEM.PRCR.WORD        = 0xA500;

}
/******************************************************************************
End of function usb_cpu_McuInitialize
******************************************************************************/

/******************************************************************************
End  Of File
******************************************************************************/
