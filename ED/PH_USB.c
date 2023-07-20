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
* File Name    : r_usb_PCDC_apl.c
* Version      : 1.10
* Device(s)    : Renesas SH-Series, RX-Series
* Tool-Chain   : Renesas SuperH RISC engine Standard Toolchain
*              : Renesas RX Standard Toolchain
* OS           : Common to None and uITRON 4.0 Spec
* H/W Platform : Independent
* Description  : USB Peripheral Communications Devices Class Sample Code
*******************************************************************************/


#ifndef _PH_USB_C
	#define _PH_USB_C
#endif
#if 0
#include "ProgHeader.h"
//#if 0
//#include <machine.h>
//#include <stdio.h>
//#include "iodefine.h"

#include "PH_USB.h"

void usb_cpu_McuInitialize(void)
{
    ULONG    i;

    /* protect off */
    SYSTEM.PRCR.WORD        = 0xA503;

    /* Main clock Oscillator register (MOSTP=Not STOP, Default:262144Cycle) */
    /* Sub clock Oscillator control register (SOSTP=STOP) */
    SYSTEM.MOSCCR.BYTE      = 0x00;
    SYSTEM.MOSCWTCR.BYTE    = 0x0E;

    /* PLL control register ( PLIDIV = 12MHz(/1), STC = 192MHz(*16), PLL enable) */
    /* PLL wait control register(Default:4194304cycle) */
    SYSTEM.PLLCR.WORD       = 0x0F00;
    SYSTEM.PLLCR2.BYTE      = 0x00;
    SYSTEM.PLLWTCR.BYTE     = 0x0F;

    /* wait over 11ms */
    for(i = 0;i< 660;i++)
    {
    }

    /* System clock control register(ICK=PLL/2,BCK,FCK,PCK=PLL/4, CKSEL(10-8)=PLL, UCK(7-4)=48MHz(/4)) */
    SYSTEM.SCKCR.LONG       = 0x21862222;
    SYSTEM.SCKCR3.WORD      = 0x0400;
    SYSTEM.SCKCR2.BIT.UCK   = 3;

    /* Module stop control register (Disable ACSE) */
    SYSTEM.MSTPCRA.LONG     = 0x7FFFFFFF;

    /* protect on */
    SYSTEM.PRCR.WORD        = 0xA500;

}

void usb_cstd_ScheInit(void)
{
    UBYTE i;
    UBYTE j;

    /* Initial Scheduler */
    usb_scstd_ID_use        = USB_NONE;
    usb_scstd_ScheduleFlag  = USB_NONE;

    /* Initialize  priority table pointer and priority table */
    for(i=0;i!=USB_PRIMAX;i++)
    {
        usb_scstd_PriR[i]   = USB_NONE;
        usb_scstd_PriW[i]   = USB_NONE;
        for(j=0;j!=USB_TABLEMAX;j++)
        {
            usb_scstd_TableID[i][j] = USB_IDMAX;
        }
    }

    /* Initialize block table */
    for(i=0;i!=USB_BLKMAX;i++)
    {
        usb_scstd_BlkFlg[i]         = USB_NONE;
    }

    /* Initialize priority */
    for(i=0;i!=USB_IDMAX;i++)
    {
        usb_scstd_Pri[i]            = (UBYTE)USB_IDCLR;
        usb_scstd_WaitAdd[i]        = (USB_MSG_t*)USB_NONE;
        usb_scstd_WaitCounter[i]    = USB_NONE;
    }
}

void usb_cstd_main_task(USB_VP_INT stacd)
{
    usb_cpu_target_init();

    //usb_pcdc_pr_apl_title();

    usb_cstd_task_start();
}

void usb_cpu_target_init( void )
{
    /* initialized USB interrupt */
    usb_cpu_usbint_init();
    usb_cpu_DmaintInit();

}

void usb_cstd_task_start( void )
{
    //usb_cstd_IdleTaskStart();   /* Idle Task Start */

    usb_pcdc_task_start();      /* Start Peripheral USB driver */

    usb_apl_task_switch();      /* Switch task for nonOS */
}

void usb_pcdc_task_start( void )
{
    USB_UTR_t   utr;
    USB_UTR_t   *ptr;

//#ifdef  USB_LCD_ENABLE
    /* Display Debug LCD */
    //usb_cpu_LcdDisp( LCD_POS_U0, "USB CDC ");
    //usb_cpu_LcdDisp( LCD_POS_D0, "Appstart");
//#endif /* USB_LCD_ENABLE */

    ptr = &utr;                             /* Set USB IP no. and USB IP base address store pointer */
    ptr->ip = USB_PERI_USBIP_NUM;           /* IP number(0or1) */
    if( USB_NOUSE_PP != ptr->ip )           /* USB IP number check */
    {
        ptr->ipp = R_usb_cstd_GetUsbIpAdr( ptr->ip );   /* IP Address(USB0orUSB1) */

        usb_pcdc_registration( ptr );       /* Peripheral Application Registration */
        usb_papl_task_start( ptr );         /* Peripheral Application Task Start Setting */
        R_usb_pcdc_driver_start();          /* Peripheral Class Driver Task Start Setting */
        R_usb_pstd_usbdriver_start( ptr );  /* Peripheral USB Driver Start Setting */

        /* Initialize USB IP */
        R_usb_cstd_UsbIpInit( ptr, USB_PERI_PP );
    }
}

USB_REGADR_t  R_usb_cstd_GetUsbIpAdr( UWORD ipno )
{
    return (USB_REGADR_t)usb_cstd_GetUsbIpAdr( ipno );
}/* eof R_usb_cstd_GetUsbIpAdr */
USB_REGADR_t    usb_cstd_GetUsbIpAdr( UWORD ipnum )
{
    USB_REGADR_t    ptr;

    if( ipnum == USB_USBIP_0 )
    {
        ptr = (USB_REGADR_t)&USB0;
    }
    else
    {
        while(1);
    }
    return ptr;
} /* eof usb_cstd_GetUsbIpAdr() */

/******************************************************************************
Function Name   : usb_pcdc_registration
Description     : Registration of peripheral Communications Devices Driver
Arguments       : USB_UTR_t *ptr        : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pcdc_registration(USB_UTR_t *ptr)
{
    USB_PCDREG_t    driver;

    /* Driver registration */
    /* Pipe Define Table address */
    driver.pipetbl      = &usb_gpcdc_EpPtr[0];
    /* Device descriptor Table address */
    driver.devicetbl    = (UBYTE*)&usb_gpcdc_DeviceDescriptor;
    /* Qualifier descriptor Table address */
    driver.qualitbl     = (UBYTE*)&usb_gpcdc_QualifierDescriptor;
    /* Configuration descriptor Table address */
    driver.configtbl    = (UBYTE**)&usb_gpcdc_ConPtr;
    /* Other configuration descriptor Table address */
    driver.othertbl     = (UBYTE**)&usb_gpcdc_ConPtrOther;
    /* String descriptor Table address */
    driver.stringtbl    = (UBYTE**)&usb_gpcdc_StrPtr;
    /* Driver init */
    driver.classinit    = &usb_cstd_DummyFunction;
    /* Device default */
    driver.devdefault   = &R_usb_pcdc_descriptor_change;
    /* Device configuered */
    driver.devconfig    = (USB_CB_INFO_t)&usb_pcdc_open;
    /* Device detach */
    driver.devdetach    = (USB_CB_INFO_t)&usb_pcdc_close;
    /* Device suspend */
    driver.devsuspend   = &usb_cstd_DummyFunction;
    /* Device resume */
    driver.devresume    = &usb_cstd_DummyFunction;
    /* Interfaced change */
    driver.interface    = &R_usb_pcdc_set_interface;
    /* Control Transfer */
    driver.ctrltrans    = (USB_CB_TRN_t)&R_usb_pcdc_usr_ctrl_trans_function;

    /* PCDC class driver registration  */
    R_usb_pstd_DriverRegistration(ptr, &driver);
}   /* eof usb_pcdc_registration() */

void usb_cstd_DummyFunction(USB_UTR_t *ptr, UWORD data1, UWORD data2)
{
}

void R_usb_pcdc_descriptor_change(USB_UTR_t *ptr, UWORD mode, UWORD data2)
{
    /* Connect Speed = Hi-Speed? */
    if( mode == USB_HSCONNECT )
    {
        /* Set Descriptor type.  */
        /* Hi-Speed Mode */
        usb_gpcdc_ConfigrationH1[1]     = USB_DT_CONFIGURATION;
        usb_gpcdc_ConfigrationF1[1]     = USB_DT_OTHER_SPEED_CONF;
        /* HIGH */
        usb_gpcdc_ConPtr[0]             = usb_gpcdc_ConfigrationH1;
        /* FULL */
        usb_gpcdc_ConPtrOther[0]        = usb_gpcdc_ConfigrationF1;
        /* Max Packet Size set */
        usb_gpcdc_EpTbl1[3]             = 512;
        usb_gpcdc_EpTbl1[USB_EPL + 3u]  = 512;
    }
    else
    {
        /* Set Descriptor type. */
        /* Full-Speed Mode */
        usb_gpcdc_ConfigrationF1[1]     = USB_DT_CONFIGURATION;
        usb_gpcdc_ConfigrationH1[1]     = USB_DT_OTHER_SPEED_CONF;
        /* FULL */
        usb_gpcdc_ConPtr[0]             = usb_gpcdc_ConfigrationF1;
        /* HIGH */
        usb_gpcdc_ConPtrOther[0]        = usb_gpcdc_ConfigrationH1;
        /* Max Packet Size set */
        usb_gpcdc_EpTbl1[3]             = 64;
        usb_gpcdc_EpTbl1[USB_EPL + 3u]  = 64;
    }

//#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
    //usb_gpcdc_Inpipe    = usb_gpcdc_EpTbl1[0];              /* Pipe no. set for Data Class TX(BulkIn) */
    //usb_gpcdc_Outpipe   = usb_gpcdc_EpTbl1[USB_EPL];        /* Pipe no. set for Data Class RX(BulkOut) */
    //usb_gpcdc_Status_pipe = usb_gpcdc_EpTbl1[USB_EPL*2];    /* Pipe no. set for Communications Class */
//#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */
} /* eof R_usb_pcdc_descriptor_change */

USB_ER_t usb_pcdc_open(USB_UTR_t *ptr, UBYTE data1, UBYTE data2)
{
    /* Peri CDC Application process enable */
    usb_gcdc_connected = USB_ON;

//#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
    /* Sample class attach */
    //usb_pcdc_smpl_message_send( ptr, USB_PCDC_PERIODIC_PROCESS );
//#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */

    return USB_E_OK;
}   /* eof usb_pcdc_open() */

USB_ER_t usb_pcdc_close(USB_UTR_t *ptr, UBYTE data1, UBYTE data2)
{
    /* Sample class detatch */
    usb_pcdc_smpl_message_send( ptr, USB_PCDC_CLOSE );

    /* Peri CDC Application process disable */
    usb_gcdc_connected = USB_OFF;

    return USB_E_OK;
}   /* eof usb_pcdc_close() */

void R_usb_pcdc_set_interface(USB_UTR_t *ptr, UWORD data1, UWORD data2)
{
} 

void R_usb_pcdc_usr_ctrl_trans_function(USB_UTR_t *ptr, USB_REQUEST_t *preq, UWORD ctsq)
{
    if( preq->ReqTypeType == USB_CLASS )
    {
        switch( ctsq )
        {
        /* Idle or setup stage */
        case USB_CS_IDST:   usb_pcdc_ControlTrans0(ptr, preq);  break;
        /* Control read data stage */
        case USB_CS_RDDS:   usb_pcdc_ControlTrans1(ptr, preq);  break;
        /* Control write data stage */
        case USB_CS_WRDS:   usb_pcdc_ControlTrans2(ptr, preq);  break;
        /* Control write nodata status stage */
        case USB_CS_WRND:   usb_pcdc_ControlTrans3(ptr, preq);  break;
        /* Control read status stage */
        case USB_CS_RDSS:   usb_pcdc_ControlTrans4(ptr, preq);  break;
        /* Control write status stage */
        case USB_CS_WRSS:   usb_pcdc_ControlTrans5(ptr, preq);  break;

        /* Control sequence error */
        case USB_CS_SQER:
            R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR); break;
        /* Illegal */
        default:
            R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR); break;
        }
    }
    else
    {
        usb_pstd_SetStallPipe0( ptr );
    }
} /* eof R_usb_pcdc_usr_ctrl_trans_function */

void usb_cpu_usbint_init(void)
{
    /* Protect register (protect off) */
    SYSTEM.PRCR.WORD            = 0xA503;   /* protect off */

/* Condition compilation by the difference of USB function */
//#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
    /* Module stop control register (Enable USB0 module(MSTPB19)) */
    /* Deep standby USB monitor register (USB0 Transceiver Output fixed) */
    SYSTEM.MSTPCRB.BIT.MSTPB19  = 0;

    /* USB0 interrupt */
    USB0_D0FIFO_IER             = 0;        /* Disable D0FIFO interrupt(IEN4) */
    USB0_D1FIFO_IER             = 0;        /* Disable D1FIFO interrupt(IEN5) */
    USB0_USBIO_IER              = 1;        /* Enable  USBIO  interrupt(IEN6) */
    USB0_USBR_IER               = 1;        /* Enable Resume interrupt(IEN2) */

    /* USB0 Priority */
    USB0_D0FIFO_IPR             = 0x00;     /* Priority D0FIFO0=0(Disable) */
    USB0_D1FIFO_IPR             = 0x00;     /* Priority D1FIFO0=0(Disable) */
    USB0_USBIO_IPR              = 0x03;     /* Priority USBINT0=3 */
    USB0_USBR_IPR               = 0x00;     /* Priority Resume0=0 */

//#endif  /* USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP */
    usb_cpu_FunctionUSB0IP();
}

void usb_cpu_FunctionUSB0IP(void)
{

/* Condition compilation by the difference of USB function */
    /* Set port direction as input(USB0 DPRPU/VBUS) */
    USB0_VBUS_PDR           = 0;
    USB0_VBUS_PMR           = 0;                    /* Port mode register (Disable USB0 VBUS) */

    /* Port mode register write enable */
    MPC.PWPR.BYTE           = 0x00;
    MPC.PWPR.BYTE           = 0x40;

    /* Initial setting of USB0 */
    USB0_DPRPU_PFS          = USB0_DPRPU_ENB;       /* DPUPE output enable */
    USB0_VBUS_PFS           = USB0_VBUS_ENB;        /* VBUS  input  enable */
    /* Enable USB0 DPRPU pullup register */
    MPC.PFUSB0.BIT.PUPHZS   = 1;                    /* DPUPE eneble */

    /* Port mode register write disable */
    MPC.PWPR.BYTE           = 0x80;                 /* PFS register write protect on */
    USB0_VBUS_PMR           = 1;                    /* Port mode register (Enable USB0 VBUS) */
/* Condition compilation by the difference of USB function */
}

void usb_cpu_DmaintInit(void)
{
    /* Protect register
    b0    PRC0     Protect bit0
    b1    PRC1     Protect bit1
    b2    Reserved 0
    b3    PRC3     Protect bit3
    b7-b4 Reserved 0
    b15-b8 PRKEY   PRC Key code bit
    */
    SYSTEM.PRCR.WORD    = 0xA503;   /* Protect off */

    /* Module stop control register (Enable DTC module)
    b3-b0   Reserved 0
    b4      MSTPA4   8bit timer3,2 stop bit
    b5      MSTPA5   8bit timer1,0 stop bit
    b8-b6   Reserved 0
    b9      MSTPA9   Multifunction timer unit0 stop bit
    b10     MSTPA10  Programmable pulse unit1 stop bit
    b11     MSTPA11  Programmable pulse unit0 stop bit
    b12     MSTPA12  16Bit timer pulse unit1 stop bit
    b13     MSTPA13  16Bit timer pulse unit0 stop bit
    b14     MSTPA14  Compare timer unit1 stop bit
    b15     MSTPA15  Compare timer unit0 stop bit
    b16     Reserved 0
    b17     MSTPA17  12bit AD stop bit
    b18     Reserved 0
    b19     MSTPA19  DA stop bit
    b22-b20 Reserved 0
    b23     MSTPA23  10bit AD unit0 stop bit
    b24     MSTPA24  Module stop A24 set bit
    b26-b25 Reserved 0
    b27     MSTPA27  Module stop A27 set bit
    b28     MSTPA28  DMA/DTC stop bit
    b29     MSTPA29  Module stop A29 set bit
    b30     Reserved 0
    b31     ACSE     All clock stop bit
    */
    SYSTEM.MSTPCRA.BIT.MSTPA28  = 0;        /* Enable DMA module(MSTPA28) */

    /* DTC vector register
    b21-b0 DTCVBR Vector table address
    */
    DTC.DTCVBR                  = (void*)&usb_dtcctable;

    /* Protect register
    b0    PRC0     Protect bit0
    b1    PRC1     Protect bit1
    b2    Reserved 0
    b3    PRC3     Protect bit3
    b7-b4 Reserved 0
    b15-b8 PRKEY   PRC Key code bit
    */
    SYSTEM.PRCR.WORD    = 0xA500;   /* Protect on */
}

/******************************************************************************
Function Name   : usb_pcdc_ControlTrans1
Description     : Class request processing (control read)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Class request information
Return value    : none
******************************************************************************/

    
/* Control Line Status data */
USB_PCDC_ControlLineState_t usb_gcdc_ControlLineState;


void usb_pcdc_ControlTrans1(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    /* Is a request receive target Interface? */
    if( (req->ReqIndex == 0) && (req->ReqTypeRecip == USB_INTERFACE) )
    {
        /* Is a Request Type GetLineCoding? */
        if( req->ReqRequest == USB_PCDC_GET_LINE_CODING )
        {
            /* send get_line_coding */
            R_usb_pstd_ControlRead(ptr, (ULONG)USB_PCDC_GET_LINE_CODING_LENGTH
                , (UBYTE *)&usb_gcdc_LineCodingReq);
        }
        else
        {
            /* Set Stall */
            usb_pstd_SetStallPipe0( ptr );    /* Req Error */
        }
    }
    else
    {
        /* Set Stall */
        usb_pstd_SetStallPipe0( ptr );        /* Req Error */
    }
} /* eof usb_pcdc_ControlTrans1 */

/******************************************************************************
Function Name   : usb_pcdc_ControlTrans4
Description     : Class request processing (control read status stage)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Pointer to Class request information
Return value    : none
******************************************************************************/
void usb_pcdc_ControlTrans4(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    /* Is a Request Type GetLineCoding? */
    if( req->ReqRequest == USB_PCDC_GET_LINE_CODING )
    {
        usb_cstd_SetBuf(ptr, (UWORD)USB_PIPE0);          /* Set BUF */
        /* Get Line Coding Request */
        usb_pcdc_GetLineCoding_req(ptr);
    }
    else
    {
        /* Set Stall */
        usb_pstd_SetStallPipe0( ptr );        /* Req Error */
    }
    R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_CTRL_END);
} /* eof usb_pcdc_ControlTrans4 */

/******************************************************************************
Function Name   : usb_pcdc_ControlTrans3
Description     : Class request processing(control no data write)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Pointer to Class request information
Return value    : none
******************************************************************************/
void usb_pcdc_ControlTrans3(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    /* Is a request receive target Interface? */
    if( (req->ReqIndex == 0) && (req->ReqTypeRecip == USB_INTERFACE) )
    {
        /* Is a Request Type SetControlLineState? */
        if( req->ReqRequest == USB_PCDC_SET_CONTROL_LINE_STATE )
        {
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);          /* Set BUF */
            /* DTR & RTS set value store */
            *(uint16_t *)&usb_gcdc_ControlLineState = req->ReqValue;

            /* send Set_Control_Line_State */
            usb_pcdc_SetControlLineState_req(ptr);
        }
        else if( req->ReqRequest == USB_PCDC_SEND_BREAK )
        {
            /* When Request Type case SendBreak */
            /* Duration of Break value store */
            usb_gcdc_SendBreakDuration = req->ReqValue;

            /* send Send_Break */
            usb_pcdc_SendBreak_req(ptr);
        }
        else
        {
            /* Set Stall */
            usb_pstd_SetStallPipe0( ptr );    /* Req Error */
        }
    }
    else
    {
        /* Set Stall */
        usb_pstd_SetStallPipe0( ptr );        /* Req Error */
    }
    if( req->ReqRequest != 0 )
    {
        R_usb_pstd_ControlEnd(ptr, (UWORD)USB_CTRL_END);
    }
} /* eof usb_pcdc_ControlTrans3 */

/******************************************************************************
Function Name   : usb_pcdc_ControlTrans0
Description     : Class request processing(idle or setup stage)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Pointer to Class request information
Return value    : none
******************************************************************************/
void usb_pcdc_ControlTrans0(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
} /* eof usb_pcdc_ControlTrans0 */

/******************************************************************************
Function Name   : usb_pcdc_ControlTrans2
Description     : Class request processing (control write data stage)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Pointer to Class request information
Return value    : none
******************************************************************************/
void usb_pcdc_ControlTrans2(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    /* Is a request receive target Interface? */
    if( (req->ReqIndex == 0) && (req->ReqTypeRecip == USB_INTERFACE) )
    {
        /* Is a Request Type SetLineCoding? */
        if( req->ReqRequest == USB_PCDC_SET_LINE_CODING )
        {
            /* send Set_Line_Coding */
            R_usb_pstd_ControlWrite(ptr, 7, (UBYTE *)&usb_gcdc_LineCodingReq);
        }
        else
        {
            /* Set Stall */
            usb_pstd_SetStallPipe0( ptr );    /* Req Error */
        }
    }
    else
    {
        /* Set Stall */
        usb_pstd_SetStallPipe0( ptr );        /* Req Error */
    }
} /* eof usb_pcdc_ControlTrans2 */

/******************************************************************************
Function Name   : usb_pcdc_ControlTrans5
Description     : Process class request (control write status stage)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Pointer to Class request information
Return value    : none
******************************************************************************/
void usb_pcdc_ControlTrans5(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    /* Is a request receive target Interface? */
    if( (req->ReqIndex == 0) && (req->ReqTypeRecip == USB_INTERFACE) )
    {
        /* Is a Request Type SetLineCoding? */
        if( req->ReqRequest == USB_PCDC_SET_LINE_CODING )
        {
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);          /* Set BUF */
            /* send Set_Line_Coding */
            usb_pcdc_SetLineCoding_req(ptr);
        }
        else
        {
            /* Set Stall */
            usb_pstd_SetStallPipe0( ptr );    /* Req Error */
        }
    }
    else
    {
        /* Set Stall */
        usb_pstd_SetStallPipe0( ptr );        /* Req Error */
    }
    R_usb_pstd_ControlEnd(ptr, (UWORD)USB_CTRL_END);
} /* eof usb_pcdc_ControlTrans5 */

void usb_pstd_SetStallPipe0(USB_UTR_t *ptr)
{
    /* PIPE control reg set */
    usb_creg_set_pid( ptr, USB_PIPE0, USB_PID_STALL );
} /* eof usb_pstd_SetStallPipe0() */

void    usb_creg_set_pid( USB_UTR_t *ptr, UWORD pipeno, UWORD data )
{
    UWORD *reg_p;

    if( pipeno == USB_PIPE0 )
    {
        reg_p = ((UWORD *)&(ptr->ipp->DCPCTR));
    }
    else
    {
        reg_p = ((UWORD *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1));
    }
    *reg_p &= ~USB_PID;
    *reg_p |= data;
}/* eof usb_creg_set_pid() */


/******************************************************************************
Function Name   : R_usb_pstd_ControlRead
Description     : Start control read transfer (API). When a valid control read 
                : request is received from host, the ControlRead function gen-
                : erates data for transmission to the host and writes it to the 
                : FIFO.
Arguments       : uint32_t bsize    : Read size in bytes.
                : uint8_t *table    : Start address of read data buffer.
Return value    : uint16_t          : USB_WRITESHRT/USB_WRITE_END/USB_WRITING/
                :                   : USB_FIFOERROR.
******************************************************************************/
UWORD R_usb_pstd_ControlRead(USB_UTR_t *ptr, ULONG bsize, UBYTE *table)
{
    UWORD    end_flag;

    end_flag = usb_pstd_ControlRead( ptr, bsize, table);

    return (end_flag);
}
void R_usb_pstd_ControlWrite(USB_UTR_t *ptr, ULONG bsize, UBYTE *table)
{
    usb_gcstd_DataCnt[ptr->ip][USB_PIPE0] = bsize;
    usb_gcstd_DataPtr[ptr->ip][USB_PIPE0] = table;

    usb_cstd_chg_curpipe(ptr, (UWORD)USB_PIPE0, (UWORD)USB_CUSE, USB_NO);
    /* Buffer clear */
    usb_creg_set_bclr( ptr, USB_CUSE );

    /* Interrupt enable */
    /* Enable ready interrupt */
    usb_creg_set_brdyenb(ptr, (UWORD)USB_PIPE0);
    /* Enable not ready interrupt */
    usb_cstd_NrdyEnable(ptr, (UWORD)USB_PIPE0);

    /* Set PID=BUF */
    usb_cstd_SetBuf(ptr, (UWORD)USB_PIPE0);
}

/******************************************************************************
Function Name   : usb_cstd_SetBuf
Description     : Set PID (packet ID) of the specified pipe to BUF.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : none
******************************************************************************/
void usb_cstd_SetBuf(USB_UTR_t *ptr, UWORD pipe)
{
    /* PIPE control reg set */
    usb_creg_set_pid( ptr, pipe, USB_PID_BUF );
}

void usb_pcdc_GetLineCoding_req(USB_UTR_t *ptr)
{
    /* Class request Get_Line_Coding */
    usb_pcdc_GetLineCoding(ptr, &usb_cstd_DummyFunction);
} /* eof usb_pcdc_GetLineCoding_req */


void usb_pcdc_GetLineCoding(USB_UTR_t *ptr, USB_CB_INFO_t complete)
{
    USB_MH_t    p_blf;
    USB_ER_t    err, err2;
    USB_UTR_t   *cp;

    /* Get mem pool blk */
    err = R_USB_PGET_BLK(USB_PCDC_MPL, &p_blf);
    if( err == USB_E_OK )
    {
        cp = (USB_UTR_t*)p_blf;
        cp->msghead = (USB_MH_t)NULL;
        cp->msginfo = (uint16_t)USB_PCDC_PGET_LINE_CODING;      /* Set message information. */
        cp->keyword = (uint16_t)USB_NOT_USED;                   /* Not use */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);

        }
    }
} /* eof usb_pcdc_GetLineCoding */

#endif
#ifdef _PH_USB_C
	#undef _PH_USB_C
#endif
