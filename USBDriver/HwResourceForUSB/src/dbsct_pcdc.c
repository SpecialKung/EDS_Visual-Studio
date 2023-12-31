/***********************************************************************/
/*                                                                     */
/*  FILE        :dbsct.c                                               */
/*  DATE        :Mon, Jul 06, 2009                                     */
/*  DESCRIPTION :Setting of B,R Section                                */
/*  CPU TYPE    :Other                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.13).    */
/*                                                                     */
/***********************************************************************/

/* $Id: dbsct.c 143 2012-05-07 09:16:46Z tmura $ */

#include "typedefine.h"

#pragma unpack

#pragma section $DSEC
extern const struct {
    _UBYTE *rom_s;       /* Start address of the initialized data section in ROM */
    _UBYTE *rom_e;       /* End address of the initialized data section in ROM   */
    _UBYTE *ram_s;       /* Start address of the initialized data section in RAM */
}   _DTBL[] = {
    { __sectop("D"),            __secend("D"),              __sectop("R") },
    { __sectop("D_2"),          __secend("D_2"),            __sectop("R_2") },
    { __sectop("D_1"),          __secend("D_1"),            __sectop("R_1") },
    { __sectop("D_usb"),        __secend("D_usb"),          __sectop("R_usb") },
    { __sectop("D_pcdc"),       __secend("D_pcdc"),         __sectop("R_pcdc") },
    { __sectop("D_apl"),        __secend("D_apl"),          __sectop("R_apl") },

    // nonOS
    { __sectop("D_hw"),         __secend("D_hw"),           __sectop("R_hw") },
    { __sectop("D_rx_rsk"),     __secend("D_rx_rsk"),       __sectop("R_rx_rsk") },

    // DTC table
    { __sectop("D_DTCtable"),   __secend("D_DTCtable"),     __sectop("R_DTCtable") },

    /* User data */
    { __sectop("D_sdram"),      __secend("D_sdram"),        __sectop("R_sdram") },
};

#pragma section $BSEC
extern const struct {
    _UBYTE *b_s;         /* Start address of non-initialized data section */
    _UBYTE *b_e;         /* End address of non-initialized data section */
}   _BTBL[] = {
    { __sectop("B"),            __secend("B") },
    { __sectop("B_2"),          __secend("B_2") },
    { __sectop("B_1"),          __secend("B_1") },
    { __sectop("B_usb"),        __secend("B_usb") },
    { __sectop("B_pcdc"),       __secend("B_pcdc") },
    { __sectop("B_apl"),        __secend("B_apl") },

    // nonOS
    { __sectop("B_hw"),         __secend("B_hw") },
    { __sectop("B_rx_rsk"),     __secend("B_rx_rsk") },

    // DTC table
    { __sectop("B_DTCtable"),   __secend("B_DTCtable") },

    /* User data */
    { __sectop("B_sdram"),      __secend("B_sdram") },
};

#pragma section

/*
** CTBL prevents excessive output of L1100 messages when linking.
** Even if CTBL is deleted, the operation of the program does not change.
*/
_UBYTE *_CTBL[] = {
    __sectop("C_1"), __sectop("C_2"), __sectop("C"),
    __sectop("W_1"), __sectop("W_2"), __sectop("W")
};

#pragma packoption
