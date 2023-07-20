/*********************************************************************
*
* Device     : RX
*
* File Name  : dbsct.c
*
* Abstract   : Setting of B,R Section.
*
* History    : 1.00  (2009-08-07)
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2009 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
*
*********************************************************************/

#include "typedefine.h"

#pragma unpack

#pragma section C C$DSEC
extern const struct {
    UBYTE *rom_s;       /* Start address of the initialized data section in ROM */
    UBYTE *rom_e;       /* End address of the initialized data section in ROM   */
    UBYTE *ram_s;       /* Start address of the initialized data section in RAM */
}   _DTBL[] = {
    { __sectop("D"), __secend("D"), __sectop("R") },
    { __sectop("D_2"), __secend("D_2"), __sectop("R_2") },
    { __sectop("D_1"), __secend("D_1"), __sectop("R_1") },

/*    
    // Add USB //
    { __sectop("D_usb_dev"),     	__secend("D_usb_dev"),       	__sectop("R_usb_dev") },
    { __sectop("D_usb_dev_2"),		__secend("D_usb_dev_2"),	__sectop("R_usb_dev_2") },
    { __sectop("D_usb_dev_1"),     	__secend("D_usb_dev_1"),       	__sectop("R_usb_dev_1") },

    { __sectop("D_usb_desc"), 		__secend("D_usb_desc"),   	__sectop("R_usb_desc") },
    { __sectop("D_usb_desc_2"), 	__secend("D_usb_desc_2"),	__sectop("R_usb_desc_2") },
    { __sectop("D_usb_desc_1"), 	__secend("D_usb_desc_1"),	__sectop("R_usb_desc_1") },

    { __sectop("D_usb_hw"),     	__secend("D_usb_hw"),       	__sectop("R_usb_hw") },
    { __sectop("D_usb_hw_2"), 		__secend("D_usb_hw_2"),		__sectop("R_usb_hw_2") },
    { __sectop("D_usb_hw_1"), 		__secend("D_usb_hw_1"),		__sectop("R_usb_hw_1") },

    { __sectop("D_usbp_DTCtable"),   __secend("D_usbp_DTCtable"),     __sectop("R_usbp_DTCtable") },

    //---add for flash API---//
    { __sectop("PFRAM"), __secend("PFRAM"), __sectop("RPFRAM") },
    
*/
};
#pragma section C C$BSEC
extern const struct {
    UBYTE *b_s;         /* Start address of non-initialized data section */
    UBYTE *b_e;         /* End address of non-initialized data section */
}   _BTBL[] = {
    { __sectop("B"), __secend("B") },
    { __sectop("B_2"), __secend("B_2") },
    { __sectop("B_1"), __secend("B_1") },

/*    // From USB project	//
    { __sectop("B_usb_dev"),     	__secend("B_usb_dev") },
    { __sectop("B_usb_dev_2"),		__secend("B_usb_dev_2") },
    { __sectop("B_usb_dev_1"),		__secend("B_usb_dev_1") },

    { __sectop("B_usbp_DTCtable"),	   __secend("B_usbp_DTCtable") },
*/
};

#pragma section

/*
** CTBL prevents excessive output of L1100 messages when linking.
** Even if CTBL is deleted, the operation of the program does not change.
*/
UBYTE * const _CTBL[] = {
    __sectop("C_1"), __sectop("C_2"), __sectop("C"),
    __sectop("W_1"), __sectop("W_2"), __sectop("W")
};

#pragma packoption
