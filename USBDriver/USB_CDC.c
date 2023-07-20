/******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized.
* This software is owned by Renesas Electronics Corporation and is  protected
* under all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING 
* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
* PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE  LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this
* software and to discontinue the availability of this software.
*    By using this software, you agree to the additional terms and conditions 
* found by accessing the following link: 
* http://www.renesas.com/disclaimer
* Copyright (C) 2012 Renesas Electronics Corporation. All rights reserved.    
*******************************************************************************
* File Name    : r_usb_pdriver.c
* Device(s)    : Renesas SH-Series, RX-Series
* Tool-Chain   : Renesas SuperH RISC engine Standard Toolchain
*              : Renesas RX Standard Toolchain
* OS           : Common to None and uITRON 4.0 Spec
* H/W Platform : Independent
* Description  : USB Peripheral driver code.
*******************************************************************************
* History : DD.MM.YYYY Version Description
*         : 29.07.2011 0.50    First Release
*         : 4.1.2012           Function header translation. Ch. tabs to 4 spaces.
*                              SET EDITOR TO INSERT SPACES WHEN TAB PRESSED.
******************************************************************************/

/* $Id: r_usb_pdriver.c 143 2012-05-07 09:16:46Z tmura $ */

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "iodefine.h"
#include "typedefine.h"	// combine ED&USB, Sean, 20140819
#include "USB_CDC.h"
#include "./switch.h"
#include <string.h>
#include <machine.h>
#include "modbus_dec_usr.h"


/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Bit Order Definition "LEFT"
******************************************************************************/
#pragma bit_order left
/* DTC Vector table */ 
typedef struct
{
/* Condition compilation by the difference of the endian */
  #if USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP
    unsigned short WORD;
    union
    {
        unsigned char BYTE;
        struct
        {
            unsigned char CHNE:1;
            unsigned char CHNS:1;
            unsigned char DISEL:1;
            unsigned char DTS:1;
            unsigned char DM:2;
            unsigned char :2;
        }
        BIT;
    }
    MRB;                        /* Mode Register B */
    union
    {
        unsigned char BYTE;
        struct
        {
            unsigned char MD:2;
            unsigned char SZ:2;
            unsigned char SM:2;
            unsigned char :2;
        }
        BIT;
    }
    MRA;                        /* Mode Register A */
    unsigned long  SAR;         /* Source Address */
    unsigned long  DAR;         /* Destination Address */
    unsigned short CRB;         /* Count Register A */
    unsigned short CRA;         /* Count Register B */
  #endif /* USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP */

/* Condition compilation by the difference of the endian */
  #if USB_CPUBYTE_PP == USB_BYTE_BIG_PP
    union
    {
        unsigned char BYTE;
        struct
        {
            unsigned char MD:2;
            unsigned char SZ:2;
            unsigned char SM:2;
            unsigned char :2;
        }
        BIT;
    }
    MRA;                        /* Mode Register A */
    union
    {
        unsigned char BYTE;
        struct
        {
            unsigned char CHNE:1;
            unsigned char CHNS:1;
            unsigned char DISEL:1;
            unsigned char DTS:1;
            unsigned char DM:2;
            unsigned char :2;
        }
        BIT;
    }
    MRB;                        /* Mode Register B */
    unsigned short WORD;
    unsigned long  SAR;         /* Source Address */
    unsigned long  DAR;         /* Destination Address */
    unsigned short CRA;         /* Count Register A */
    unsigned short CRB;         /* Count Register B */
  #endif /* USB_CPUBYTE_PP == USB_BYTE_BIG_PP */
} USB_DTC_t;

/******************************************************************************
Constant macro definitions
******************************************************************************/
#define USB_PswIntDisable               (uint32_t)(7 << 24) /* Processer Status Word - IPL(Level7) */
#define USB_PswIntSleep                 (uint32_t)(1 << 24) /* Processer Status Word - IPL(Level1) */

#define USB_CFIFO_MBW       USB_MBW_16
#define USB_D0FIFO_MBW      USB_MBW_16
#define USB_D1FIFO_MBW      USB_MBW_16

/* Condition compilation by the difference of the endian */
#if USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP
    #define USB_FIFOENDIAN      USB_FIFO_LITTLE
#else   /* USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP */
    #define USB_FIFOENDIAN      USB_FIFO_BIG
#endif  /* USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP */

#define     USB_PCDC_SW1_ON                     1
#define     USB_PCDC_SW2_ON                     2
#define     USB_PCDC_SW3_ON                     4

#define     USB_PCDC_MSG_TIMING                 10000 //41317

#define     USB_PCDC_APL_INST_SEQ_START         3
#define     USB_PCDC_APL_INST_SEQ_END           8

/* CDC Host data receive size */
/* FS:64 HS:512 */
/* Condition compilation by the difference of user define */
#if USB_SPEEDSEL_PP == USB_HS_PP
#define     USB_PCDC_APL_RX_SIZE                512
#else   /* USB_SPEEDSEL_PP == USB_HS_PP */
#define     USB_PCDC_APL_RX_SIZE                64
#endif  /* USB_SPEEDSEL_PP == USB_HS_PP */

/* Comm Port data receive size */
#define USB_PCDC_APL_SRX_SIZE                   64

/* setup packet table size (uint16_t * 5) */
#define     USB_CDC_SETUP_TBL_BSIZE             10


/* Serial port */
/* USB DATA MAX PACKET SIZE define */
#define USB_SCI_MAXPS                   64u
/* Communications Devices Class */
#define USB_SCI_BUFFER_SIZE_MAX         (USB_SCI_MAXPS * 8u)
#define USB_SCI_STX_BUFF_MARGIN         (USB_SCI_MAXPS * 1u)    /* Serial Port Transfer Buffer Margin check define */

#define USB_SCI_MODE_ECHO               1u  /* Echo mode define */
#define USB_SCI_BUFF_BUSY               1u  /* USB Receive data buffer busy */

/* SCI(Serial Communication Interface) Transfer Enable & Receive Enable */
#define USB_SCI_SCI_BYTE_TE_RE          0x30

#define USB_SCI_ENABLE                  1u
#define USB_SCI_DISABLE                 0u

/* SCI Interrupt level */
#define USB_SCI_SCI_INT_LV              5u
/* SCI Data field length */
#define USB_SCI_8BIT_DATA               0u
#define USB_SCI_7BIT_DATA               1u

/* SCI Data Parity setting */
#define USB_SCI_PARITY_ENABLE           1u
#define USB_SCI_PARITY_DISABLE          0u
#define USB_SCI_PARITY_EVEN             0u
#define USB_SCI_PARITY_ODD              1u

/* SCI Data Stop bit length */
#define USB_SCI_1STOP_BIT               0u
#define USB_SCI_2STOP_BIT               1u

#define USB_SCI_CLEAR                   0u
#define USB_SCI_ERR_DETECT              1u

/* CLOCK SELECT for SCI BRG source */
#define USB_SCI_CLK_0DIVID_FREQ         0u
#define USB_SCI_CLK_4DIVID_FREQ         1u
#define USB_SCI_CLK_16DIVID_FREQ        2u
#define USB_SCI_CLK_64DIVID_FREQ        3u

/****************************************/
/* SCI1                                 */
/****************************************/
typedef enum
{
    USB_SCI_DATA_BIT_7  = 7u,   /* Line Coding 7Data bits */
    USB_SCI_DATA_BIT_8  = 8u    /* Line Coding 8Data bits */
} USB_SCI_DATA_BIT_t;

typedef enum
{
    USB_SCI_STOP_BIT_1  = 0u,   /* Line Coding 1Stop bits */
    USB_SCI_STOP_BIT_2  = 2u    /* Line Coding 2Stop bits */
}
USB_SCI_STOT_BIT_t;

typedef enum
{
    USB_SCI_PARITY_BIT_NONE = 0u,   /* Line Coding None Parity */
    USB_SCI_PARITY_BIT_ODD  = 1u,   /* Line Coding Odd Parity */
    USB_SCI_PARITY_BIT_EVEN = 2u    /* Line Coding Even Parity */
}
USB_SCI_PARITY_BIT_t;

typedef enum
{
    USB_SCI_SPEED_1200      = 1200u,    /* Line Coding 1200bps */
    USB_SCI_SPEED_2400      = 2400u,    /* Line Coding 2400bps */
    USB_SCI_SPEED_4800      = 4800u,    /* Line Coding 4800bps */
    USB_SCI_SPEED_9600      = 9600u,    /* Line Coding 9600bps */
    USB_SCI_SPEED_14400     = 14400u,   /* Line Coding 14400bps */
    USB_SCI_SPEED_19200     = 19200u,   /* Line Coding 19200bps */
    USB_SCI_SPEED_38400     = 38400u,   /* Line Coding 38400bps */
    USB_SCI_SPEED_57600     = 57600u,   /* Line Coding 57600bps */
    USB_SCI_SPEED_115200    = 115200u,  /* Line Coding 115200bps */
    USB_SCI_SPEED_250000    = 250000u,  /* Line Coding 250000bps */
    USB_SCI_SPEED_500000    = 500000u,  /* Line Coding 500000bps */
    USB_SCI_SPEED_750000    = 750000u,  /* Line Coding 750000bps */
}USB_SCI_LINE_SPEED_t;

/* Class Notification Serial State */
typedef struct
{
    /* reserve */
    uint16_t                    rsv:9;
    /* Over Run error */
    uint16_t                    bOverRun:1;
    /* Parity error */
    uint16_t                    bParity:1;
    /* Framing error */
    uint16_t                    bFraming:1;
    /* State of ring signal detection of the device */
    uint16_t                    bRingSignal:1;
    /* State of break detection mechanism of teh device */
    uint16_t                    bBreak:1;
    /* DSR signal */
    uint16_t                    bTxCarrier:1;
    /* DCD signal */
    uint16_t                    bRxCarrier:1;
}USB_SCI_SerialState_t;

/* Serial Status register */
typedef struct
{
    unsigned char RSV:2;
    unsigned char ORER:1;
    unsigned char FER:1;
    unsigned char PER:1;
    unsigned char TEND:1;
    unsigned char MPB:1;
    unsigned char MPBT:1;
}USB_SCI_SSR;

/* PCLK=48MHz   */
#define USB_SCI_BRR_1200        77u
#define USB_SCI_BRR_2400        38u
#define USB_SCI_BRR_4800        77u
#define USB_SCI_BRR_9600        155u
#define USB_SCI_BRR_14400       103u
#define USB_SCI_BRR_19200       77u
#define USB_SCI_BRR_38400       38u
#define USB_SCI_BRR_57600       25u
#define USB_SCI_BRR_115200      12u
#define USB_SCI_BRR_250000      5u
#define USB_SCI_BRR_500000      2u
#define USB_SCI_BRR_750000      1u

/*****************************************************************************
Enumerated Types
******************************************************************************/
/* Peripheral CDC Sample application message command */
typedef enum
{
    USB_PCDC_OPEN,
    /* Periodic processing */
    USB_PCDC_PERIODIC_PROCESS,
    /* Data receive from Host cdc */
    USB_PCDC_RX_COMP,
    /* Data send for Host cdc */
    USB_PCDC_TX_COMP,
    /* Notification  */
    USB_PCDC_STATUS_TX_COMP,
    USB_PCDC_CLOSE
}USB_PCDC_APL_COMMAND;

/******************************************************************************
External variables and functions
******************************************************************************/
#ifdef USB_LCD_ENABLE
extern void usb_cpu_LcdInit(void);
#endif /* USB_LCD_ENABLE */

#ifdef USB_KEY_ENABLE
extern void usb_cpu_KeyInit(void);
#endif /* USB_KEY_ENABLE */

#ifdef USB_LED_ENABLE
extern void usb_cpu_LedInit(void);
#endif /* USB_LED_ENABLE */

extern void usb_cpu_DmaintInit(void);
extern USB_ER_t R_usb_pstd_PcdChangeDeviceState(USB_UTR_t *ptr, uint16_t state, uint16_t port_no,
    USB_CB_INFO_t complete);
extern void     R_usb_pstd_DeviceInformation(USB_UTR_t *ptr, uint16_t *tbl);
extern void usb_creg_set_bempenb( USB_UTR_t *ptr, uint16_t pipeno );

extern  void        R_usb_cstd_UsbIpInit( USB_UTR_t *ptr, uint16_t usb_mode );
extern  void        R_usb_cstd_SetTaskPri(uint8_t tasknum, uint8_t pri);
extern  uint16_t    usb_gpstd_intsts0;
void    usb_pstd_SetStallPipe0( USB_UTR_t *ptr );
uint16_t usb_pstd_InitFunction(USB_UTR_t *ptr);


void            usb_cstd_ClassTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);
uint16_t        usb_cstd_ClassTransWaitTmo(uint16_t tmo);
void            usb_cstd_ClassProcessResult(USB_UTR_t *ptr, uint16_t data,uint16_t Dummy);
uint16_t        usb_cstd_ClassProcessWaitTmo(uint16_t tmo);
void            usb_cstd_DummyFunction(USB_UTR_t *ptr, uint16_t data1, uint16_t data2);


/* USB API (Host) */
extern USB_ER_t R_usb_hstd_TransferEnd(USB_UTR_t *ptr, uint16_t pipe, uint16_t status);
extern USB_ER_t R_usb_hstd_MgrChangeDeviceState(USB_UTR_t *ptr, USB_CB_INFO_t complete, uint16_t msginfo,
    uint16_t devaddr);
extern void     R_usb_hstd_DeviceInformation(USB_UTR_t *ptr, uint16_t addr, uint16_t *tbl);

/* USB API (Peripheral) */
extern USB_ER_t R_usb_pstd_TransferEnd(USB_UTR_t *ptr, uint16_t pipe, uint16_t status);
extern USB_ER_t R_usb_pstd_PcdChangeDeviceState(USB_UTR_t *ptr, uint16_t state, uint16_t port_no,
    USB_CB_INFO_t complete);
extern void     R_usb_pstd_DeviceInformation(USB_UTR_t *ptr, uint16_t *tbl);
extern void     R_usb_pstd_SetPipeStall(USB_UTR_t *ptr, uint16_t pipeno);
extern USB_ER_t R_usb_pstd_SetStall(USB_UTR_t *ptr, USB_CB_INFO_t complete, uint16_t pipe);

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP

extern  int16_t (*usb_classopen[])(USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t);
#endif


void    usb_cstd_nrdy_endprocess( USB_UTR_t *ptr, uint16_t pipe );
//extern void usb_cstd_brdy_pipe(void);
extern void usb_cstd_brdy_pipe(USB_UTR_t *ptr, uint16_t bitsts);
extern void usb_cstd_d0fifo_handler(void);

#if USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP
extern USB_UTR_t    usb_gcstd_IntMsg[][USB_INTMSGMAX];  /* Interrupt message */
extern uint16_t     usb_gcstd_IntMsgCnt[];              /* Interrupt message count */
extern void usb2_cstd_d0fifo_handler(void);
#endif

extern void     usb_cpu_int_enable(USB_UTR_t *ptr);
extern void     usb_cpu_int_disable(USB_UTR_t *ptr);

extern void     usb_cpu_d0fifo_enable_dma(USB_UTR_t *ptr );
extern void     usb_cpu_d0fifo_disable_dma(USB_UTR_t *ptr );
extern uint32_t usb_cpu_get_dtc_Source_address(USB_UTR_t *ptr);
extern uint16_t usb_cpu_get_dtc_block_count(USB_UTR_t *ptr);
extern USB_UTR_t       usb_gcstd_IntMsgD0fifo;
extern USB_UTR_t       usb2_gcstd_IntMsgD0fifo;

extern    uint16_t    usb_gpstd_intsts0;
extern void     R_usb_pstd_DeviceInformation(USB_UTR_t *ptr, uint16_t *tbl);

/* Serial Port driver functions */
extern void     usb_cpu_Sci_DataSend(uint16_t mode, void *tranadr, uint16_t length);
extern uint16_t usb_cpu_Sci_DataReceive(uint8_t *tranadr, uint16_t receive_length);
extern uint16_t usb_cpu_Sci_StxBuffStatus(void);
extern void     usb_cpu_Sci_Buffer_init(void);
extern uint16_t usb_cpu_Sci_CopyData_for_Echo(void);
extern uint16_t usb_cpu_Sci_GetSerialState(uint16_t *serial_state);

#ifdef USB_UART_ENABLE
extern void     usb_cpu_Sci_HW_init(void);
extern void     usb_cpu_Sci_enable(void);
extern void     usb_cpu_Sci_disable(void);
#endif /* USB_UART_ENABLE */

/* SW input driver functions */
#ifdef USB_KEY_ENABLE
extern uint16_t usb_cpu_GetKeyNo(void);
#endif /* USB_KEY_ENABLE */

#ifdef  USB_LCD_ENABLE
extern  void    usb_cpu_LcdDisp(uint8_t position, uint8_t *string);
#endif /* USB_LCD_ENABLE */


//=====================================================
//---extern時 必要加入資料型態  否則 執會亂掉-----7/3/2015
extern UWORD uwVfd_Explorer_Flag,uwVfd_Explorer_Count;//Aevin add--7/2/2015


/******************************************************************************
Private global variables and functions
******************************************************************************/
#pragma section _hw
uint16_t g_usb_D0fifoIER    = 0;        /* D0fifo0 Interrupt Request enable */
uint16_t g_usb_D1fifoIER    = 0;        /* D1fifo0 Interrupt Request enable */

/*=== SYSTEM ================================================================*/
void        usb_cpu_McuInitialize(void);
void        usb_cpu_target_init(void);
void        usb_cpu_FunctionUSB0IP(void);

/*=== USB ===================================================================*/
void        usb_cpu_usbint_init(void);
void        usb_cpu_usb_int_hand(void);         /* INT VECTOR 35 */
void        usb_cpu_int_enable(USB_UTR_t *ptr);
void        usb_cpu_int_disable(USB_UTR_t *ptr);
/*=== TIMER =================================================================*/
void        usb_cpu_Delay1us(uint16_t time);
void        usb_cpu_DelayXms(uint16_t time);
/*=== Standby control =======================================================*/
void        usb_cpu_GoWait(void);
void        usb_cpu_RegRecovEnable(USB_UTR_t *ptr);
void        usb_cpu_RegRecovDisable(USB_UTR_t *ptr);
/*=== IRQ ===================================================================*/
void        usb_cpu_IRQ0_Enable(void);
void        usb_cpu_IRQ0_Disable(void);
void        usb_cpu_IRQ1_Enable(USB_UTR_t *ptr);
void        usb_cpu_IRQ1_Disable(void);
void        usb_cpu_IRQ2_Enable(void);
void        usb_cpu_IRQ2_Disable(void);
void        usb_cpu_IRQ0Int(void);
void        usb_cpu_IRQ1Int(void);
void        usb_cpu_IRQ2Int(void);
/*=== DTC ===================================================================*/
void        usb_cpu_DmaintInit(void);
void        usb_cpu_d0fifo_int_hand(void);
void        usb_cpu_d0fifo2buf_start_dma(USB_UTR_t *ptr, uint32_t SourceAddr);
void        usb_cpu_buf2d0fifo_start_dma(USB_UTR_t *ptr, uint32_t DistAdr);
void        usb_cpu_d0fifo_restart_dma(USB_UTR_t *ptr);
void        usb_cpu_d0fifo_stop_dma(USB_UTR_t *ptr);
uint16_t    usb_cpu_get_dtc_block_count(USB_UTR_t *ptr);
void        usb_cpu_d0fifo_enable_dma(USB_UTR_t *ptr );
void        usb_cpu_d0fifo_disable_dma(USB_UTR_t *ptr );


/* Condition compilation by the difference of the devices */
 #if (USB_CPU_LPW_PP == USB_LPWR_USE_PP)
uint16_t    usb_gcpu_RemoteProcess = USB_OFF;
 #endif /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */

#pragma interrupt usb_cpu_usb_int_hand (vect = VECT(USB0, USBI0))	//35
#pragma interrupt usb_cpu_usb_int_hand_r(vect = VECT(USB, USBR0))	//90
#pragma interrupt usb_cpu_GoWait_Int (vect = 11)
#pragma interrupt usb_cpu_IRQ0Int (vect = VECT(ICU, IRQ0))	//64
#pragma interrupt usb_cpu_IRQ1Int (vect = VECT(ICU, IRQ1))	//65
#pragma interrupt usb_cpu_IRQ2Int (vect = VECT(ICU, IRQ2))	//66
#pragma interrupt usb_cpu_d0fifo_int_hand (vect = VECT(USB0, D0FIFO0))	//33

#pragma section _DTCtable

/*
*  Must be set 0 by the Address Low 2bit. (4byte alignment)
*/
/* DTC Control Register */
USB_DTC_t   usb_dtcreg[2u];

/*
*  Must be set 0 by the Address Low 12bit. (0x???? ?000)
*/
/* DTC VECTOR Table  */
uint32_t    usb_dtcctable[48] = 
{
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  0 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  1 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  2 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  3 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  4 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  5 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  6 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  7 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  8 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR  9 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 10 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 11 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 12 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 13 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 14 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 15 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 16 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 17 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 18 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 19 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 20 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 21 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 22 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 23 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 24 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 25 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 26 */
    (uint32_t)0x00000000,       /* DTC VECTOR 27 (SWINT) */
    (uint32_t)0x00000000,       /* DTC VECTOR 28 (CMT0) */
    (uint32_t)0x00000000,       /* DTC VECTOR 29 (CMT1) */
    (uint32_t)0x00000000,       /* DTC VECTOR 30 (CMT2) */
    (uint32_t)0x00000000,       /* DTC VECTOR 31 (CMT3) */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 32 */
    (uint32_t)&usb_dtcreg[0],   /* DTC VECTOR 33 (USB0-D0FIFO) */
    (uint32_t)0x00000000,       /* DTC VECTOR 34 (USB0-D1FIFO) */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 35 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 36 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 37 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 38 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 39 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 40 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 41 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 42 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 43 */
    (uint32_t)0xFFFFFFFF,       /* DTC VECTOR 44 */
    (uint32_t)0x00000000,       /* DTC VECTOR 45 (SPRI0) */
    (uint32_t)0x00000000,       /* DTC VECTOR 46 (SPTI1) */
    (uint32_t)0xFFFFFFFF        /* DTC VECTOR 47 */
};

#pragma section _rx_rsk

/* Communications Devices Class */
uint8_t     usb_gpcdc_stxdata[USB_SCI_BUFFER_SIZE_MAX+4];   /* Comm Port Tx data buffer */
uint16_t    usb_gpcdc_stx_wp;   /* Comm Port Tx data buffer data count */
uint16_t    usb_gpcdc_stx_rp;   /* Comm Port Tx data buffer read data count */


uint8_t     usb_gpcdc_srxdata[USB_SCI_BUFFER_SIZE_MAX+4];   /* Comm Port Rx data buffer */
uint16_t    usb_gpcdc_srx_wp;   /* Comm Port Rx data buffer Write Pointer */
uint16_t    usb_gpcdc_srx_rp;   /* Comm Port Rx data buffer Read Pointer */
USB_SCI_SSR usb_gpcdc_com_port_ssr; /* Serial Status Register read data */

/*=== Serial port ===========================================================*/
void        usb_cpu_Sci_DataSend(uint16_t mode, void *tranadr, uint16_t length);
uint16_t    usb_cpu_Sci_DataReceive(uint8_t *tranadr,uint16_t receive_length);
uint16_t    usb_cpu_Sci_StxBuffStatus(void);
void        usb_cpu_Sci_Buffer_init(void);
uint16_t    usb_cpu_Sci_CopyData_for_Echo(void);
uint16_t    usb_cpu_Sci_GetSerialState(uint16_t *serial_state);
uint16_t    usb_cpu_Sci_EnableStatus(void);
uint16_t    usb_cpu_Sci_SetDataChk(uint8_t *data_rate, uint8_t stop_bit, uint8_t parity, uint8_t data_bit);

#ifdef USB_UART_ENABLE
uint16_t    usb_cpu_Sci_Set1(uint8_t *data_rate, uint8_t stop_bit, uint8_t parity, uint8_t data_bit);
void        usb_cpu_Sci_HW_init(void);
void        usb_cpu_Sci_enable(void);
void        usb_cpu_Sci_disable(void);
void        usb_cpu_Sci_ER_Int(void);
void        usb_cpu_Sci0_RX_Int(void);
void        usb_cpu_Sci0_TX_Int(void);
void        usb_cpu_Sci0_TE_Int(void);
void        usb_cpu_Sci1_RX_Int(void);
void        usb_cpu_Sci1_TX_Int(void);
void        usb_cpu_Sci1_TE_Int(void);

#pragma interrupt usb_cpu_Sci_ER_Int (vect = VECT_ICU_GROUP12)
#pragma interrupt usb_cpu_Sci1_RX_Int (vect = VECT(SCI1, RXI1))
#pragma interrupt usb_cpu_Sci1_TX_Int (vect = VECT(SCI1, TXI1))
#pragma interrupt usb_cpu_Sci1_TE_Int (vect = VECT(SCI1, TEI1))
#pragma interrupt usb_cpu_Sci0_RX_Int (vect = VECT(SCI0, RXI0))
#pragma interrupt usb_cpu_Sci0_TX_Int (vect = VECT(SCI0, TXI0))
#pragma interrupt usb_cpu_Sci0_TE_Int (vect = VECT(SCI0, TEI0))

#endif

/******************************************************************************
Section    <Section Definition> , "Project Sections"
******************************************************************************/
#pragma section _usb

/******************************************************************************
Private global variables and functions
******************************************************************************/
/* Condition compilation by the difference of the devices */
 #if (USB_CPU_LPW_PP == USB_LPWR_USE_PP)
uint16_t usb_gcpu_RemoteProcess;
 #endif /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */

uint16_t        usb_gpstd_StallPipe[USB_MAX_PIPE_NO + 1u];  /* Stall Pipe info */
USB_CB_INFO_t   usb_gpstd_StallCB;                          /* Stall Callback function */
uint16_t        usb_gpstd_ConfigNum = 0;                    /* Current configuration number */
uint16_t        usb_gpstd_AltNum[USB_ALT_NO];               /* Alternate number */
uint16_t        usb_gpstd_RemoteWakeup = USB_NO;            /* Remote wakeup enable flag */

#if USB_TARGET_CHIP_PP == USB_ASSP_PP
  #if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
uint16_t        usb_gpstd_TestModeSelect;                   /* Test mode selectors */
uint16_t        usb_gpstd_TestModeFlag = USB_NO;            /* Test mode flag */
  #endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */
#endif  /* USB_TARGET_CHIP_PP == USB_ASSP_PP */

uint16_t        usb_gpstd_EpTblIndex[USB_MAX_EP_NO + 1u];   /* Index of endpoint information table */
uint16_t        usb_gpstd_ReqType;                          /* Request type */
uint16_t        usb_gpstd_ReqTypeType;                      /* Request type TYPE */
uint16_t        usb_gpstd_ReqTypeRecip;                     /* Request type RECIPIENT */
uint16_t        usb_gpstd_ReqRequest;                       /* Request */
uint16_t        usb_gpstd_ReqValue;                         /* Value */
uint16_t        usb_gpstd_ReqIndex;                         /* Index */
uint16_t        usb_gpstd_ReqLength;                        /* Length */
uint16_t        usb_gpstd_intsts0;                          /* INTSTS0 */

/* Driver registration */
USB_PCDREG_t    usb_gpstd_Driver = 
{
    (uint16_t**)&usb_cstd_DummyFunction,    /* Pipe define table address */
    (uint8_t*)  &usb_cstd_DummyFunction,    /* Device descriptor table address */
    (uint8_t*)  &usb_cstd_DummyFunction,    /* Qualifier descriptor table address */
    (uint8_t**) &usb_cstd_DummyFunction,    /* Configuration descriptor table address */
    (uint8_t**) &usb_cstd_DummyFunction,    /* Other configuration descriptor table address */
    (uint8_t**) &usb_cstd_DummyFunction,    /* String descriptor table address */
    &usb_cstd_DummyFunction,                /* Driver init */
    &usb_cstd_DummyFunction,                /* Device default */
    &usb_cstd_DummyFunction,                /* Device configured */
    &usb_cstd_DummyFunction,                /* Device detach */
    &usb_cstd_DummyFunction,                /* Device suspend */
    &usb_cstd_DummyFunction,                /* Device resume */
    &usb_cstd_DummyFunction,                /* Interfaced change */
    &usb_cstd_DummyTrn,                     /* Control transfer */
};

USB_REQUEST_t   usb_gpstd_ReqReg;           /* Device Request - Request structure */


#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
struct  usb_fninfo  usb_fnInfo[16];

/* Pointer Table for open() function to handle the class */
int16_t (*usb_classopen[])(USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t) = 
{                                           
    usb_open_hcdc,                  /* for Host CDC(Communications Class) */
    usb_open_hcdc,                  /* for Host CDC(Data Class) */
    usb_open_hhid,                  /* for Host HID */
    usb_open_hmsc,                  /* for Host MSC */
    usb_open_hvendor,               /* for Host Vendor class(Bulk Pipe) */
    usb_open_hvendor,               /* for Host Vendor class(Interrupt Pipe) */
    usb_open_pcdc,                  /* for Peripheral CDC(Communications Class) */
    usb_open_pcdc,                  /* for Peripheral CDC(Data Class) */
    usb_open_phid,                  /* for Peripheral HID */
    usb_open_pmsc,                  /* for Peripheral MSC */
    usb_open_pvendor,               /* for Peripheral Vendor class(Bulk Pipe) */
    usb_open_pvendor                /* for Peripheral Vendor class(Interrupt Pipe) */
};
#endif

/* USB data transfer */
/* PIPEn Buffer counter */
uint32_t        usb_gcstd_DataCnt[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1u];
/* DMA0 direction */
uint16_t        usb_gcstd_Dma0Dir[USB_NUM_USBIP];
/* DMA0 buffer size */
uint32_t        usb_gcstd_Dma0Size[USB_NUM_USBIP];
/* DMA0 FIFO buffer size */
uint16_t        usb_gcstd_Dma0Fifo[USB_NUM_USBIP];
/* DMA0 pipe number */
uint16_t        usb_gcstd_Dma0Pipe[USB_NUM_USBIP];
/* PIPEn Buffer pointer(8bit) */
uint8_t         *usb_gcstd_DataPtr[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1u];
/* Message pipe */
USB_UTR_t       *usb_gcstd_Pipe[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1u];
/* XCKE Mode Flag */
uint16_t        usb_gcstd_XckeMode;
/* Hi-speed enable */
uint16_t        usb_gcstd_HsEnable[USB_NUM_USBIP];

USB_UTR_t       usb_gcstd_IntMsg[USB_NUM_USBIP][USB_INTMSGMAX]; /* Interrupt message */
uint16_t        usb_gcstd_IntMsgCnt[USB_NUM_USBIP];             /* Interrupt message count */
USB_UTR_t       usb_gcstd_IntMsgD0fifo;

#if USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP
USB_UTR_t       usb2_gcstd_IntMsgD0fifo;
#endif


/* Priority Table */
static USB_MSG_t*   usb_scstd_TableAdd[USB_PRIMAX][USB_TABLEMAX];
static uint8_t      usb_scstd_TableID[USB_PRIMAX][USB_TABLEMAX];
static uint8_t      usb_scstd_PriR[USB_PRIMAX];
static uint8_t      usb_scstd_PriW[USB_PRIMAX];
static uint8_t      usb_scstd_Pri[USB_IDMAX];

/* Schedule Set Flag  */
static uint8_t      usb_scstd_ScheduleFlag;

/* Fixed-sized memory pools */
static USB_UTR_t    usb_scstd_Block[USB_BLKMAX];
static uint8_t      usb_scstd_BlkFlg[USB_BLKMAX];

static USB_MSG_t*   usb_scstd_Add_use;
static uint8_t      usb_scstd_ID_use;

/* Wait MSG */
static USB_MSG_t*   usb_scstd_WaitAdd[USB_IDMAX];
static uint16_t     usb_scstd_WaitCounter[USB_IDMAX];

void    usb_pstd_ClassReq0(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_ClassReq1(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_ClassReq2(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_ClassReq3(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_ClassReq4(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_ClassReq5(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_VendorReq0(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_VendorReq1(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_VendorReq2(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_VendorReq3(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_VendorReq4(USB_UTR_t *ptr, USB_REQUEST_t *);
void    usb_pstd_VendorReq5(USB_UTR_t *ptr, USB_REQUEST_t *);

uint16_t    usb_gcstd_RhstBit;
uint16_t    usb_gcstd_DvsqBit;
uint16_t    usb_gcstd_AddrBit;
uint16_t    usb_gcstd_SqmonBit;



/* Condition compilation by the difference of hardware reference */
#ifdef USB_SDRAM_USE_PP
    #pragma section _sdram
#else   /* USB_SDRAM_USE_PP */
    #pragma section _apl
#endif  /* USB_SDRAM_USE_PP */
/* Abstract Control Model Notification - SerialState */
uint8_t usb_gpcdc_SerialState_Table[USB_CDC_SETUP_TBL_BSIZE]
    = { 0xA1,           /* bmRequestType */
        0x20,           /* bNotification:SERIAL_STATE */
        0x00,0x00,      /* wValue:Zero */
        0x00,0x00,      /* wIndex:Interface */
        0x02,0x00,      /* wLength:2 */
        0x00,0x00 };    /* Data:UART State bitmap */

/* Peri CDC application enable */
uint16_t usb_gcdc_connected;

void        usb_pcdc_main_task(USB_VP_INT_t);
uint16_t    usb_pcdc_is_connected(void);
void        usb_pcdc_pr_apl_title(void);

/******************************************************************************
Static variables and functions
******************************************************************************/
static USB_PCDINFO_t    *usb_spstd_PcdMsg;  /* Pcd Task receive message */

static  USB_ER_t usb_pstd_SetSubmitutr(USB_UTR_t *ptr, USB_UTR_t *utrmsg);
static  void usb_pstd_SetReTransfer(USB_UTR_t *ptr, uint16_t pipe);

static    void        usb_pstd_GetStatus1(USB_UTR_t *ptr);
static    void        usb_pstd_GetDescriptor1(USB_UTR_t *ptr);
static    void        usb_pstd_GetConfiguration1(USB_UTR_t *ptr);
static    void        usb_pstd_GetInterface1(USB_UTR_t *ptr);
static    void        usb_pstd_ClearFeature0(void);
static    void        usb_pstd_ClearFeature3(USB_UTR_t *ptr);
static    void        usb_pstd_SetFeature0(void);
static    void        usb_pstd_SetFeature3(USB_UTR_t *ptr);
static    void        usb_pstd_SetAddress0(void);
static    void        usb_pstd_SetAddress3(USB_UTR_t *ptr);
static    void        usb_pstd_SetDescriptor2(USB_UTR_t *ptr);
static    void        usb_pstd_SetConfiguration0(USB_UTR_t *ptr);
static    void        usb_pstd_SetConfiguration3(USB_UTR_t *ptr);
static    void        usb_pstd_SetInterface0(USB_UTR_t *ptr);
static    void        usb_pstd_SetInterface3(USB_UTR_t *ptr);
static    void        usb_pstd_SynchFrame1(USB_UTR_t *ptr);

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
static  uint16_t    usb_FileNumberInfo = 0; /* Variable for FileNumber management */
#define USB_NOPIPE  ((uint8_t)0xFF)
#endif

static  void usb_cstd_SelectNak(USB_UTR_t *ptr, uint16_t pipe);
static  void        usb_cstd_D0FifoselSet(USB_UTR_t *ptr);




/* Condition compilation by the difference of hardware reference */
#ifdef USB_SDRAM_USE_PP
    #pragma section _sdram
#else   /* USB_SDRAM_USE_PP */
    #pragma section _apl
#endif  /* USB_SDRAM_USE_PP */


#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
static  int16_t usb_spcdc_data_fn;
static  int16_t usb_spcdc_ctl_fn;
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
static  uint16_t usb_pcdc_get_rcv_data_cnt(USB_UTR_t *mess);
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

static  void    usb_pcdc_rx_notification(USB_UTR_t *mess);
static  void    usb_pcdc_tx_notification(USB_UTR_t *mess);
static  void    usb_pcdc_state_notification(USB_UTR_t *mess);
static  void    usb_pcdc_apl_msg_out(USB_UTR_t *ptr, uint16_t message_no);
static  void    usb_pcdc_apl_init(USB_UTR_t *ptr);
static  void    usb_pcdc_smpl_message_send( USB_UTR_t *ptr, uint16_t msginfo);

void    usb_apl_task_switch(void);
void    usb_pcdc_task_start( void );
static  void    usb_papl_task_start( USB_UTR_t *ptr );
static  void    usb_pcdc_registration(USB_UTR_t *ptr);

/*Main menu text*/
//static  const uint8_t szWelcomeMsg[9][64] = 
uint8_t szWelcomeMsg[9][64] = 
{
    {   
	0xAA,0x01,0x02,0x03,0x04
        // "\r\nRenesas USB CDC Sample, Press Switch SW2\r\n"
    },
    {
        "\r\nStarting Echo:-\r\n"
    },
    {
        "\r\nFinished Echo.\r\n"
    },
    {
        "\r\n[Renesas Serial-USB converter.]\r\n\r\n "
    },
    {
        "Connect serial terminal (e.g. PC COM1) DB9 cable to PC and RSK,"
    },
    {
        "\r\n and USB cable to PC and to mini-B on RSK.\r\n    "
    },
    {
        "                       Support COM Speed 1200bps-115200bps\r\n"
    },
    {
        "\r\nSw2 - Show instructions\r\n"
    },
    {
        "\r\nSw3 - Start Echo of everthing typed <-> Stop Echo\r\n"
    },
};

/* USB TX Data */
static  uint8_t     usb_gpcdc_send_data[802/*USB_PCDC_APL_SRX_SIZE*/ + 4 +100 ];		// increase send buffer size for VFD exploere protocol, Sean, 20141225
/* USB RX Data */																		//aevin add size 4--11/25/2015			
static  uint8_t     usb_gpcdc_receive_data[USB_PCDC_APL_RX_SIZE + 4];
/* Instructions output line sequence */
static  uint16_t    usb_gpcdc_explain_seq;
/* HOST Send wait flag */
static  uint16_t    usb_gpcdc_tx_wait_flag;
/* Notification Serial State sending flag */
static  uint16_t    usb_gpcdc_serial_state_tx;
/* Notification Serial State sending status */
static  uint16_t    usb_gpcdc_serial_state;

/* echo mode flag */
static  uint16_t    usb_gpcdc_echo_mode;
static  uint16_t    usb_gpcdc_sw2push;
/* Switch1 Push Request Message Output Timing Counter */
static  uint32_t    usb_gpcdc_msg_timing_cnt;
/* Receive flow control flag */
static  uint16_t    usb_gpcdc_stx_wait;
/* CDC Peripheral Active flag */
static  uint16_t    usb_gpcdc_active;
/*Debug tool flag*/
static  uint16_t    usb_gpcdc_debug_mode;
/******************************************************************************
Constant macro definitions
******************************************************************************/
#define USB_CFIFO_MBW       USB_MBW_16
#define USB_D0FIFO_MBW      USB_MBW_16
#define USB_D1FIFO_MBW      USB_MBW_16

#define USB_TYPE_NUM_SHIFT  14
#define USB_MXPS_NUM_SHIFT  0

//#pragma end


/******************************************************************************
Section    <Section Difinition> , "Project Sections"
******************************************************************************/
#pragma section _pcdc


/******************************************************************************
Constant macro definitions
******************************************************************************/

/******************************************************************************
User define macro definitions
******************************************************************************/
#define USB_VENDORID    0x0000
#define USB_PRODUCTID   0x0002

/******************************************************************************
External variables and functions
******************************************************************************/
extern uint16_t usb_get_pipedir( uint16_t   *tbl_p, uint16_t pipeno );
extern void usb_pstd_SetStall(USB_UTR_t *ptr, uint16_t pipe);

extern uint8_t usb_gpcdc_SerialState_Table[];


#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP

extern void usb_pstd_SetStall(USB_UTR_t *ptr, uint16_t pipe);

/* Serial Port driver functions */
#ifdef USB_UART_ENABLE
extern uint16_t usb_cpu_Sci_Set1(uint8_t *data_rate_top, uint8_t stop_bit, uint8_t parity, uint8_t data_bit);
#endif /* USB_UART_ENABLE */
extern uint16_t usb_cpu_Sci_SetDataChk(uint8_t *data_rate_top, uint8_t stop_bit, uint8_t parity, uint8_t data_bit);

/* Control Line Status data */
extern USB_PCDC_ControlLineState_t  usb_gcdc_ControlLineState;
/* Duration of Break */
extern uint16_t usb_gcdc_SendBreakDuration;

extern USB_CB_t usb_gpcdc_TxCB;         /* Call Back Function Info */
extern USB_CB_t usb_gpcdc_RxCB;         /* Call Back Function Info */
extern USB_CB_t usb_gpcdc_StatCB;       /* Call Back Function Info */
/******************************************************************************
Private global variables and functions
******************************************************************************/
int16_t usb_open_pcdc( USB_UTR_t *ptr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed );
int32_t usb_pcdc_read_data( int16_t fn, void *buf, uint32_t length );
int32_t usb_pcdc_write_data( int16_t fn, void *buf, uint32_t length );

/* PCDC <--> USB massage */
USB_UTR_t usb_gpcdc_Mess[10];

/* Line Coding data */
USB_PCDC_LineCoding_t usb_gcdc_LineCoding;
/* Line Coding Set Request data */
USB_PCDC_LineCoding_t usb_gcdc_LineCodingReq;

/* Control Line Status data */
USB_PCDC_ControlLineState_t usb_gcdc_ControlLineState;
/* Duration of Break */
uint16_t usb_gcdc_SendBreakDuration;

#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
/* Call Back Function Info Transfer end */
USB_CB_t usb_gpcdc_TxCB;
/* Call Back Function Info Receive complete */
USB_CB_t usb_gpcdc_RxCB;
/* Call Back Function Info Serial Status Transfer end*/
USB_CB_t usb_gpcdc_StatCB;
#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */


USB_ER_t usb_pcdc_UserDataTrans(USB_UTR_t *ptr, uint16_t pipe, uint32_t size, uint8_t *table);
void usb_pcdc_InTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);
void usb_pcdc_OutTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);
uint16_t usb_get_pipedir( uint16_t  *tbl_p, uint16_t pipeno );

void usb_pcdc_SetControlLineState(USB_UTR_t *ptr, USB_CB_INFO_t complete);
void usb_pcdc_SetLineCoding(USB_UTR_t *ptr, USB_CB_INFO_t complete);
void usb_pcdc_GetLineCoding(USB_UTR_t *ptr, USB_CB_INFO_t complete);
void usb_pcdc_SendBreak(USB_UTR_t *ptr, USB_CB_INFO_t complete);

/* Pipe Direction from Host to Device */
uint16_t        usb_gpcdc_Outpipe;
/* Pipe Direction from Device to Host */
uint16_t        usb_gpcdc_Inpipe;
uint16_t        usb_gpcdc_Status_pipe;

//#pragma end



// combine ED&USB, Sean, 20140819
/* USB PC monitor Variable	*/	// combine ED&USB, Sean, 20140819
enum {USB_STOP,USB_START};			// PC_TransState
enum {USB_TXSTANDBY,USB_TXFULL};	// PC_ubTxState
#define PC_INITBYTE 0x56
#define PC_STARTBYTE 0xff
#define USB_ubRXMAX	32
#define USB_ubTXMAX	64
uint8_t USB_ub200us;
uint8_t	USB_ubRxData[USB_ubRXMAX],USB_ubTxData_0[USB_ubTXMAX],USB_ubTxData_1[USB_ubTXMAX];
uint8_t USB_ubRxCnt, USB_ubTxCnt, USB_ubTxBufIdx, USB_ubTxOutIdx;
uint8_t	PC_TxChkSum,PC_TransState,PC_ubTxState;
uint16_t USB_RxTime, PC_TxPktCnt, USB_uwTxOutCnt;
uint16_t USB_uwTxTimOut, USB_uwSampleCnt;
uint16_t Ch1Add, Ch2Add, Ch3Add, Ch4Add, PC_Cha, PC_Chb, PC_Chc, PC_Chd;
//-------aevin add for ChxAdd array---5/24/2016
uint16_t ChxAdd[20];
uint8_t ChCount, ChCountTmp;
//---------------------------------------------
extern UWORD memadd_rd(UWORD x);
extern UWORD memadd_rd1(UWORD x);
static uint16_t uwSet(uint16_t* uwTar, uint16_t uwVal);
static uint16_t uwReset(uint16_t* uwTar, uint16_t uwVal);
static uint16_t uwCheck(uint16_t* uwTar, uint16_t uwVal);

struct	MntrData{	// MNTR for VFDExplorer,Sean, 20141225
uint16_t	uwCh1Dat;	
uint16_t	uwCh2Dat;
uint16_t	uwCh3Dat;
uint16_t	uwCh4Dat;
};

struct MntrData	stMntrData[2][100];
UWORD MNTR_uwCRC[2];
UBYTE MNTR_ubLRC[2];
UWORD_UNION	Mntr_uwGenReg;
#define	MNTR_START	0x0001
#define MNTR_TX_FULL 0x0002

/******************************************************************************
Renesas Abstracted Peripheral Driver functions
******************************************************************************/

#pragma section _usb
/******************************************************************************
Function Name   : usb_cstd_IdleTaskStart
Description     : Idle Task Start process
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cstd_IdleTaskStart(void)
{
/* Condition compilation by the difference of the devices */
#if (USB_CPU_LPW_PP == USB_LPWR_USE_PP)
    R_usb_cstd_SetTaskPri(USB_IDL_TSK, USB_PRI_6);
    USB_SND_MSG(USB_IDL_MBX, 0);
#endif /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */
}
/******************************************************************************
End of function usb_cstd_IdleTaskStart()
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_IdleTask
Description     : Idle Task (sleep sample)
Arguments       : USB_VP_INT stacd      : task start code(not use)
Return value    : none
******************************************************************************/
void usb_cstd_IdleTask(USB_VP_INT stacd)
{
/* Condition compilation by the difference of USB function * /
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    /* nothing * /
#else /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
/* Condition compilation by the difference of the devices */
 #if (USB_CPU_LPW_PP == USB_LPWR_USE_PP)
    void        usb_cpu_GoLpwrSleepMode(void);
    void        usb_cpu_GoDeepStbyMode(ptr);
    uint16_t    res[8], sts0;
    uint8_t     stby;
    USB_UTR_t utr0, *ptr0;

    USB_UTR_t   *mess;
    USB_ER_t    err;
    uint16_t    usb_idle;

    usb_idle = USB_OFF;

    ptr0 = (USB_UTR_t *)&utr0;

    ptr0->ip  = USB_PERI_USBIP_NUM;
    ptr0->ipp = usb_cstd_GetUsbIpAdr( ptr0->ip );

    /* Idle Task message receive (port0) */
    err = USB_TRCV_MSG(USB_IDL_MBX, (USB_MSG_t**)&mess, (USB_TM_t)0);
    if( (err != USB_E_OK) && (err != USB_E_TMOUT) )
    {
        /* USB_PRINTF1("### IdleTask rcv_msg error %ld\n", err); */
    }
    else
    {
        /* Send message to IDL_TSK */
        usb_idle = USB_ON;
        USB_SND_MSG(USB_IDL_MBX, 0);
    }

    if( usb_idle == USB_ON )
    {

/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        R_usb_pstd_DeviceInformation(ptr0, (uint16_t *)res);
#endif /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
/* Condition compilation by the difference of USB function */

        sts0 = res[0];
        if( (sts0 & USB_VBSTS) == 0 )
        {
            sts0 = USB_DETACHED;    /* Port0 detach */
        }
        else if( (sts0 & USB_DS_SPD_CNFG) == USB_DS_SPD_CNFG )
        {
            sts0 = USB_SUSPENDED;   /* Port0 suspend */
        }
        else
        {
            sts0 = USB_PORTOFF;
        }

        if( sts0 == USB_DETACHED )
        {
            /* Detach */
            usb_gcpu_RemoteProcess = USB_OFF;
            /* Get Deep Software Standby Reset Flag */
            stby = usb_cpu_GetDPSRSTF();
            if( stby == 0 )
            {
                /* Deep Standby shift */
                usb_cpu_GoLpwrDeepStby(ptr0);
            }
        }
        else if( sts0 == USB_SUSPENDED )
        {
            /* Suspend */
            usb_cpu_GoLpwrSleep(ptr0);
        }
        else
        {
            usb_gcpu_RemoteProcess = USB_OFF;
        }
    }
 #else /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */
 #endif /* (USB_CPU_LPW_PP == USB_LPWR_NOT_USE_PP) */
//#endif /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
}
/******************************************************************************
End of function usb_cstd_IdleTask()
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_IdleTask
Description     : Call Idle Task (sleep sample)
Arguments       : USB_VP_INT stacd      : task start code(not use)
Return value    : none
******************************************************************************/
void R_usb_cstd_IdleTask(USB_VP_INT stacd)
{
    usb_cstd_IdleTask( stacd );
}
/******************************************************************************
End of function R_usb_cstd_IdleTask()
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_PcdSndMbx
Description     : PCD Send Mailbox
Arguments       : USB_UTR_t *ptr            : USB system internal structure.
                : uint16_t msginfo          : USB system internal structure.
                : uint16_t keyword          : USB system internal structure.
                : USB_CB_INFO_t complete    : Callback function.
Return value    : USB_ER_t                  : Error Info
******************************************************************************/
USB_ER_t usb_pstd_PcdSndMbx(USB_UTR_t *ptr, uint16_t msginfo, uint16_t keyword, USB_CB_INFO_t complete)
{
    USB_MH_t        p_blf;
    USB_ER_t        err, err2;
    USB_PCDINFO_t   *pp;

    /* Get Memory pool for send message */
    err = USB_PGET_BLK(USB_PCD_MPL, &p_blf);
    if( err == USB_E_OK )
    {
        pp = (USB_PCDINFO_t*)p_blf;
        pp->msghead     = (USB_MH_t)USB_NULL;
        pp->msginfo     = msginfo;
        pp->keyword     = keyword;
        pp->complete    = complete;

        pp->ipp         = ptr->ipp;
        pp->ip          = ptr->ip;

        /* Send message for usb_pstd_PcdTask */
        err = USB_SND_MSG(USB_PCD_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### pPcdSndMbx snd_msg error (%ld)\n", err);
            err2 = USB_REL_BLK(USB_PCD_MPL,(USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                USB_PRINTF1("### pPcdSndMbx rel_blk error (%ld)\n", err2);
            }
        }
    }
    else
    {
        USB_PRINTF1("### pPcdSndMbx pget_blk error\n", err);
    }
    return err;
}
/******************************************************************************
End of function usb_pstd_PcdSndMbx
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_PcdRelMpl
Description     : PCD REL_BLK send                          $REA
Arguments       : uint16_t n                                $REA
Return value    : none
******************************************************************************/
void usb_pstd_PcdRelMpl(uint16_t n)
{
    USB_ER_t        err;

    /* PCD memory pool release */
    err = USB_REL_BLK(USB_PCD_MPL, (USB_MH_t)usb_spstd_PcdMsg);
    if( err != USB_E_OK )
    {
        USB_PRINTF2("### usb_pstd_PcdRelMpl (%d) rel_blk error: %d\n", n, err);
    }
}
/******************************************************************************
End of function usb_pstd_PcdRelMpl
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_PcdTask
Description     : The Peripheral Control Driver(PCD) task.
Arguments       : USB_VP_INT stacd
Return value    : none
******************************************************************************/
void usb_pstd_PcdTask(USB_VP_INT stacd)
{
    USB_UTR_t       *mess, *ptr;
    /* Error code */
    USB_ER_t        err;
    uint16_t        pipenum;

    err = USB_TRCV_MSG(USB_PCD_MBX, (USB_MSG_t**)&mess, (USB_TM_t)10000);
    if( (err != USB_E_OK) )
    {
        return;
    }

    ptr = (USB_UTR_t *)mess;

    usb_spstd_PcdMsg = (USB_PCDINFO_t*)mess;
    pipenum = usb_spstd_PcdMsg->keyword;

    /* Detach is all device */
    switch( usb_spstd_PcdMsg->msginfo )
    {
    case USB_MSG_PCD_INT:
        /* USB INT */
        usb_pstd_Interrupt((USB_UTR_t*)usb_spstd_PcdMsg);
        break;
    case USB_MSG_PCD_PCUTINT:
        /* Start Oscillation : Interrupt wakeup */
        usb_cstd_InterruptClock(ptr);
        ptr = (USB_UTR_t*)usb_spstd_PcdMsg;
        /* USB interrupt Handler */
        usb_pstd_InterruptHandler(ptr);
        /* USB INT */
        usb_pstd_Interrupt((USB_UTR_t*)usb_spstd_PcdMsg);
        ptr->msginfo = USB_MSG_PCD_INT;
        break;

    case USB_MSG_PCD_SUBMITUTR:
        /* USB Submit utr */
        usb_pstd_SetSubmitutr(ptr, (USB_UTR_t*)usb_spstd_PcdMsg);
        break;
    case USB_MSG_PCD_REMOTEWAKEUP:
        usb_cstd_SelfClock(ptr);
        usb_pstd_RemoteWakeup(ptr);
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_REMOTEWAKEUP);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)1u);
        break;

    case USB_MSG_PCD_CLRSEQBIT:
        usb_creg_set_sqclr(ptr, pipenum);
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_CLRSEQBIT);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)2u);
        break;
    case USB_MSG_PCD_SETSTALL:
        usb_pstd_SetStall(ptr, pipenum);
        usb_gpstd_StallPipe[pipenum] = USB_YES;
        usb_gpstd_StallCB = usb_spstd_PcdMsg->complete;
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)3u);
        break;

    case USB_MSG_PCD_TRANSEND1:
        /* End of all pipes */
        if( usb_gcstd_Pipe[ptr->ip][pipenum] != USB_NULL )
        {
            /* Transfer timeout */
            usb_cstd_ForcedTermination(ptr, pipenum, (uint16_t)USB_DATA_TMO);
        }
        else
        {
            USB_PRINTF1("### Peri not transferd-1 %d\n", pipenum);
        }
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)4u);
        break;
    case USB_MSG_PCD_TRANSEND2:
        /* End of all pipes */
        if( usb_gcstd_Pipe[ptr->ip][pipenum] != USB_NULL )
        {
            /* Transfer stop */
            usb_cstd_ForcedTermination(ptr, pipenum, (uint16_t)USB_DATA_STOP);
        }
        else
        {
            USB_PRINTF1("### Peri not transferd-2 %d\n", pipenum);
        }
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)5u);
        break;

    case USB_MSG_PCD_DETACH:
        usb_cstd_SelfClock(ptr);
        /* USB detach */
        usb_pstd_DetachProcess(ptr);
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_DETACH);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)6u);
        break;
    case USB_MSG_PCD_ATTACH:
        usb_cstd_SelfClock(ptr);
        usb_pstd_AttachProcess(ptr);
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_ATTACH);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)7u);
        break;

    case USB_MSG_PCD_DP_ENABLE:
        usb_pstd_DpEnable(ptr);
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_DP_ENABLE);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)8u);
        break;
    case USB_MSG_PCD_DP_DISABLE:
        usb_pstd_DpDisable(ptr);
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_DP_DISABLE);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)9u);
        break;
    case USB_MSG_PCD_DM_ENABLE:
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_DM_ENABLE);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)10u);
        break;
    case USB_MSG_PCD_DM_DISABLE:
        /* Process Done Callback function */
        (*usb_spstd_PcdMsg->complete)(ptr, (uint16_t)USB_NO_ARG, USB_MSG_PCD_DM_DISABLE);
        /* PCD memory pool release */
        usb_pstd_PcdRelMpl((uint16_t)11u);
        break;

    case USB_MSG_PCD_D0FIFO_INT:
        usb_cstd_D0fifoInt(ptr);
        break;

    case USB_MSG_PCD_D1FIFO_INT:
        break;

    case USB_MSG_PCD_RESM_INT:
        break;

    default:
        while( 1 )
        {
        };
        break;
    }
}
/******************************************************************************
End of function usb_pstd_PcdTask
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_SetSubmitutr
Description     : 
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : USB_UTR_t *utrmsg             $REA
Return value    : USB_ER_t
******************************************************************************/
USB_ER_t usb_pstd_SetSubmitutr(USB_UTR_t *ptr, USB_UTR_t *utrmsg)
{
    uint16_t    pipenum;

    pipenum = utrmsg->keyword;
    usb_gcstd_Pipe[ptr->ip][pipenum] = utrmsg;

    /* Check state ( Configured ) */
    if( usb_pstd_ChkConfigured(ptr) == USB_YES )
    {
        /* Data transfer */
        usb_pstd_SetReTransfer(ptr, pipenum);
    }
    else
    {
        /* Transfer stop */
        usb_cstd_ForcedTermination(ptr, pipenum, (uint16_t)USB_DATA_ERR);
    }
    return USB_DONE;
}
/******************************************************************************
End of function usb_pstd_SetSubmitutr
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetReTransfer
Description     : Start transmission/reception of data transfer based on the 
                : specified transfer direction.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : uint16_t pipe     : Pipe nr.
Return value    : none
******************************************************************************/
void usb_pstd_SetReTransfer(USB_UTR_t *ptr, uint16_t pipe)
{
    /* Data transfer */
    if( usb_cstd_GetPipeDir(ptr, pipe) == USB_DIR_P_OUT )
    {   /* Out transfer */
        usb_cstd_ReceiveStart(ptr, pipe);
    }
    else
    {
        /* In transfer */
        usb_cstd_SendStart(ptr, pipe);
    }
}
/******************************************************************************
End of function usb_pstd_SetReTransfer
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_Interrupt
Description     : Analyze the USB Peripheral interrupt event and execute the
                : appropriate process.
Arguments       : USB_UTR_t *p    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_Interrupt(USB_UTR_t *ptr)
{
    uint16_t    intsts, status, stginfo;

    intsts = ptr->keyword;
    status = ptr->status;

    usb_gpstd_intsts0 = usb_creg_read_intsts( ptr );

    /* check interrupt status */
    switch( intsts )
    {

    /* BRDY, BEMP, NRDY */
    case USB_INT_BRDY:
        usb_pstd_BrdyPipe(ptr, status);
        break;
    case USB_INT_BEMP:
        usb_pstd_BempPipe(ptr, status);
        break;
    case USB_INT_NRDY:
        usb_pstd_NrdyPipe(ptr, status);
        break;
    /* Resume */
    case USB_INT_RESM:
        USB_PRINTF0("RESUME int peri\n");
        /* Callback */
        (*usb_gpstd_Driver.devresume)(ptr, (uint16_t)USB_NO_ARG, (uint16_t)USB_NO_ARG);
        usb_pstd_ResumeProcess(ptr);
        break;
    /* VBUS */
    case USB_INT_VBINT:
        if( usb_pstd_ChkVbsts(ptr) == USB_ATTACH )
        {
            USB_PRINTF0("VBUS int attach\n");
            /* USB attach */
            usb_pstd_AttachProcess(ptr);
        }
        else
        {
            USB_PRINTF0("VBUS int detach\n");
            /* USB detach */
            usb_pstd_DetachProcess(ptr);
        }
        break;
    /* SOF */
    case USB_INT_SOFR:
        /* User program */
        break;

    /* DVST */
    case USB_INT_DVST:
        switch( (uint16_t)(status & USB_DVSQ) )
        {
        /* Power state  */
        case USB_DS_POWR:
            break;
        /* Default state  */
        case USB_DS_DFLT:
            USB_PRINTF0("USB-reset int peri\n");
            usb_pstd_BusReset(ptr);
            break;
        /* Address state  */
        case USB_DS_ADDS:
            break;
        /* Configured state  */
        case USB_DS_CNFG:
            USB_PRINTF0("Device configuration int peri\n");
            break;
        /* Power suspend state */
        case USB_DS_SPD_POWR:
            /* Continue */
        /* Default suspend state */
        case USB_DS_SPD_DFLT:
            /* Continue */
        /* Address suspend state */
        case USB_DS_SPD_ADDR:
            /* Continue */
        /* Configured Suspend state */
        case USB_DS_SPD_CNFG:
            USB_PRINTF0("SUSPEND int peri\n");
            usb_pstd_SuspendProcess(ptr);
            /* Callback */
            (*usb_gpstd_Driver.devsuspend)(ptr, (uint16_t)USB_NO_ARG, (uint16_t)USB_NO_ARG);
            break;
        /* Error */
        default:
            break;
        }
        break;

    /* CTRT */
    case USB_INT_CTRT:
        stginfo = (uint16_t)(status & USB_CTSQ);
        if( (stginfo == USB_CS_IDST) )
        {
#if USB_TARGET_CHIP_PP == USB_ASSP_PP
  #if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
            /* check Test mode */
            if( usb_gpstd_TestModeFlag == USB_YES )
            {
                /* Test mode */
                usb_pstd_TestMode( ptr );
            }
  #endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */
#endif  /* USB_TARGET_CHIP_PP == USB_ASSP_PP */
        }
        else
        {
            if( ((stginfo == USB_CS_RDDS) || (stginfo == USB_CS_WRDS)) || (stginfo == USB_CS_WRND) )
            {
                /* Save request register */
                usb_pstd_SaveRequest(ptr);
            }
        }

        if( usb_gpstd_ReqTypeType == USB_STANDARD )
        {
                /* Switch on the control transfer stage (CTSQ). */
            switch( stginfo )
            {
            /* Idle or setup stage */
            case USB_CS_IDST:
                usb_pstd_StandReq0(ptr);
                break;
            /* Control read data stage */
            case USB_CS_RDDS:
                usb_pstd_StandReq1(ptr);
                break;
            /* Control write data stage */
            case USB_CS_WRDS:
                usb_pstd_StandReq2(ptr);
                break;
                    /* Status stage of a control write where there is no data stage. */
            case USB_CS_WRND:
                usb_pstd_StandReq3(ptr);
                break;
            /* Control read status stage */
            case USB_CS_RDSS:
                usb_pstd_StandReq4(ptr);
                break;
            /* Control write status stage */
            case USB_CS_WRSS:
                usb_pstd_StandReq5(ptr);
                break;
            /* Control sequence error */
            case USB_CS_SQER:
                usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
                break;
            /* Illegal */
            default:
                usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
                break;
            }
        }
        else
        {
            /* Vender Specific */
            usb_gpstd_ReqReg.ReqType        = usb_gpstd_ReqType;
            usb_gpstd_ReqReg.ReqTypeType    = usb_gpstd_ReqTypeType;
            usb_gpstd_ReqReg.ReqTypeRecip   = usb_gpstd_ReqTypeRecip;
            usb_gpstd_ReqReg.ReqRequest     = usb_gpstd_ReqRequest;
            usb_gpstd_ReqReg.ReqValue       = usb_gpstd_ReqValue;
            usb_gpstd_ReqReg.ReqIndex       = usb_gpstd_ReqIndex;
            usb_gpstd_ReqReg.ReqLength      = usb_gpstd_ReqLength;
            /* Callback */
            (*usb_gpstd_Driver.ctrltrans)(ptr, (USB_REQUEST_t *)&usb_gpstd_ReqReg, stginfo);
        }
        break;

    /* Error */
    case USB_INT_UNKNOWN:
        USB_PRINTF0("pINT_UNKNOWN\n");
        break;
    default:
        USB_PRINTF1("pINT_default %X\n", intsts);
        break;
    }
}
/******************************************************************************
End of function usb_pstd_Interrupt
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_ClearAlt
Description     : Zero-clear the alternate table (buffer).
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_ClearAlt(void)
{
    uint16_t    i;

    for( i = 0; i < USB_ALT_NO; ++i )
    {
        /* Alternate table clear */
        usb_gpstd_AltNum[i] = 0;
    }
}
/******************************************************************************
End of function usb_pstd_ClearAlt
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClearMem
Description     : Initialize global variables defined for peripheral mode.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_ClearMem(void)
{
    /* Configuration number */
    usb_gpstd_ConfigNum = 0;
    /* Remote wakeup enable flag */
    usb_gpstd_RemoteWakeup = USB_NO;
    usb_gcstd_XckeMode = USB_NO;
    /* Alternate setting clear */
    usb_pstd_ClearAlt();
}
/******************************************************************************
End of function usb_pstd_ClearMem
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_SetConfigNum
Description     : Set specified configuration number.
Arguments       : uint16_t value    : Configuration number
Return value    : none
******************************************************************************/
void usb_pstd_SetConfigNum(uint16_t value)
{
    /* Set configuration number */
    usb_gpstd_ConfigNum = value;
    /* Alternate setting clear */
    usb_pstd_ClearAlt();
}
/******************************************************************************
End of function usb_pstd_SetConfigNum
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClearEpTblIndex
Description     : Clear Endpoint Index Table (buffer).
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_ClearEpTblIndex(void)
{
    uint16_t    i;

    for( i = 0; i <= USB_MAX_EP_NO; ++i )
    {
        /* Endpoint index table clear */
        usb_gpstd_EpTblIndex[i] = USB_ERROR;
    }
}
/******************************************************************************
End of function usb_pstd_ClearEpTblIndex
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_GetConfigNum
Description     : Get number of possible configurations.
Arguments       : none
Return value    : uint16_t : Number of possible configurations.
                : (bNumConfigurations)
******************************************************************************/
uint16_t usb_pstd_GetConfigNum(void)
{
    /* Configuration Number */
    return (uint16_t)(usb_gpstd_Driver.devicetbl[USB_DEV_NUM_CONFIG]);
}
/******************************************************************************
End of function usb_pstd_GetConfigNum
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_get_confignum_to_tblindex
Description     : Get Configuration descriptor table index 
Arguments       : uint16_t con_num : Configuration Number
Return value    : uint16_t : Configuration descriptor table index 
******************************************************************************/
uint16_t usb_pstd_get_confignum_to_tblindex(uint16_t con_num)
{
    uint16_t    conf;
    uint16_t    i;
    uint16_t    tbl_index = 0;

    conf = con_num;
    if( conf < (uint16_t)1 )
    {
        /* Address state */
        conf = (uint16_t)1;
    }

    /* Configuration Descriptor search loop */
    for( i = 0; i < con_num; i++ )
    {
        /* Check Configuration Number.   5:bConfigurationValue */
        if( *(uint8_t*)(usb_gpstd_Driver.configtbl[i] + USB_DEV_B_CONFIGURATION_VALUE) == con_num )
        {
            /* Set Configuration tabile index */
            tbl_index = i;
            break;
        }
    }

    return tbl_index;
}
/******************************************************************************
End of function usb_pstd_get_confignum_to_tblindex
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_GetInterfaceNum
Description     : Get interface number 
Arguments       : uint16_t con_num : Configuration Number
Return value    : uint16_t : Number of this interface 
                : (bNumInterfaces)
******************************************************************************/
uint16_t usb_pstd_GetInterfaceNum(uint16_t con_num)
{
    uint16_t    conf;
    uint16_t    num_if = 0;
    uint16_t    tbl_index;

    conf = con_num;
    if( conf < (uint16_t)1 )
    {
        /* Address state */
        conf = (uint16_t)1;
    }

    /* Get Configuration descriptor table index */
    tbl_index = usb_pstd_get_confignum_to_tblindex( conf );

    /* Get NumInterfaces.        4:bNumInterfaces */
    num_if = *(uint8_t*)(usb_gpstd_Driver.configtbl[tbl_index] + USB_DEV_B_NUM_INTERFACES);

    return num_if;
}
/******************************************************************************
End of function usb_pstd_GetInterfaceNum
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_GetAlternateNum
Description     : Get Alternate Setting Number
Arguments       : uint16_t con_num : Configuration Number
                : uint16_t int_num : Interface Number
Return value    : uint16_t : Value used to select this alternate
                : (bAlternateSetting)
******************************************************************************/
uint16_t usb_pstd_GetAlternateNum(uint16_t con_num, uint16_t int_num)
{
    uint16_t    i, conf;
    uint16_t    alt_num = 0;
    uint8_t     *ptr;
    uint16_t    length;
    uint16_t    tbl_index;

    conf = con_num;
    if( conf < (uint16_t)1 )
    {
        /* Address state */
        conf = (uint16_t)1;
    }

    /* Get Configuration descriptor table index */
    tbl_index = usb_pstd_get_confignum_to_tblindex( conf );

    ptr = usb_gpstd_Driver.configtbl[tbl_index];
    i = ptr[0];
    /* Interface descriptor[0] */
    ptr = (uint8_t*)((uint32_t)ptr + ptr[0]);
    length = (uint16_t)(*(uint8_t*)((uint32_t)  usb_gpstd_Driver.configtbl[tbl_index] + (uint16_t)2u));
    length |= (uint16_t)((uint16_t)(*(uint8_t*)((uint32_t)usb_gpstd_Driver.configtbl[tbl_index] + (uint16_t)3u)) << 8u);
    
    /* Search descriptor table size */
    for(  ; i < length;  )
    {
        /* Descriptor type ? */
        switch( ptr[1] )
        {
        /* Interface */
        case USB_DT_INTERFACE:
            if( int_num == ptr[2] )
            {
                /* Alternate number count */
                alt_num = (uint16_t)ptr[3];
            }
            i += ptr[0];
            /* Interface descriptor[0] */
            ptr =(uint8_t*)((uint32_t)ptr + ptr[0]);
            break;
        /* Device */
        case USB_DT_DEVICE:
            /* Continue */
        /* Configuration */
        case USB_DT_CONFIGURATION:
            /* Continue */
        /* String */
        case USB_DT_STRING:
            /* Continue */
        /* Endpoint */
        case USB_DT_ENDPOINT:
            /* Continue */
        /* Class, Vendor, else */
        default:
            i += ptr[0];
            /* Interface descriptor[0] */
            ptr =(uint8_t*)((uint32_t)ptr + ptr[0]);
            break;
        }
    }
    return alt_num;
}
/******************************************************************************
End of function usb_pstd_GetAlternateNum
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_SetEpTblIndex
Description     : Set endpoint index in table (buffer) region based on config-
                : uration descriptor. In other words, set which endpoints to 
                : use based on specified configuration, 
Arguments       : uint16_t con_num : Configuration Number.
                : uint16_t int_num : Interface Number.
                : uint16_t alt_num : Alternate Setting.
Return value    : none
******************************************************************************/
void usb_pstd_SetEpTblIndex(uint16_t con_num, uint16_t int_num, uint16_t alt_num)
{
    uint8_t         *ptr;
    uint16_t        i, j, length, conf;
    uint16_t        start, numbers, ep;
    uint16_t    tbl_index;

    conf = con_num;
    if( conf < (uint16_t)1 )
    {
        /* Address state */
        conf = (uint16_t)1;
    }

    /* Get Configuration descriptor table index */
    tbl_index = usb_pstd_get_confignum_to_tblindex( conf );

    /* Configuration descriptor */
    ptr = usb_gpstd_Driver.configtbl[tbl_index];
    i = *ptr;
    length = (uint16_t)(*(uint8_t*)((uint32_t)ptr + (uint32_t)3u));
    length = (uint16_t)(length << 8);
    length += (uint16_t)(*(uint8_t*)((uint32_t)ptr + (uint32_t)2u));
    ptr =(uint8_t*)((uint32_t)ptr + *ptr);
    start = 0;
    numbers = 0;
    j = 0;

    for(  ; i < length;  )
    {
        /* Descriptor type ? */
        switch(*(uint8_t*)((uint32_t)ptr + (uint32_t)1u) )
        {
        /* Interface */
        case USB_DT_INTERFACE:
            if((*(uint8_t*)((uint32_t)ptr + (uint32_t)2u) == int_num)
                && (*(uint8_t*)((uint32_t)ptr + (uint32_t)3u) == alt_num))
            {
                numbers = *(uint8_t*)((uint32_t)ptr + (uint32_t)4u);
            }
            else
            {
                start += *(uint8_t*)((uint32_t)ptr + (uint32_t)4u);
            }
            i += *ptr;
            ptr =(uint8_t*)((uint32_t)ptr + *ptr);
            break;
        /* Endpoint */
        case USB_DT_ENDPOINT:
            if( j < numbers )
            {
                ep = (uint16_t)*(uint8_t*)((uint32_t)ptr + (uint32_t)2u);
                ep &= (uint16_t)0x0f;
                usb_gpstd_EpTblIndex[ep] = (uint8_t)(start + j);
                ++j;
            }
            i += *ptr;
            ptr = (uint8_t*)((uint32_t)ptr + *ptr);
            break;
        /* Device */
        case USB_DT_DEVICE:
            /* Continue */
        /* Configuration */
        case USB_DT_CONFIGURATION:
            /* Continue */
        /* String */
        case USB_DT_STRING:
            /* Continue */
        /* Class, Vendor, else */
        default:
            i += *ptr;
            ptr = (uint8_t*)((uint32_t)ptr + *ptr);
            break;
        }
    }
}
/******************************************************************************
End of function usb_pstd_SetEpTblIndex
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ChkRemote
Description     : Check if the RemoteWakeUp bit for the configuration descrip-
                : tor is set.
Arguments       : none
Return value    : uint16_t : remote wakeup status (YES/NO).
******************************************************************************/
uint16_t usb_pstd_ChkRemote(void)
{
    uint8_t atr;
    uint16_t    tbl_index;

    if( usb_gpstd_ConfigNum == 0 )
    {
        return USB_NO;
    }

    /* Get Configuration descriptor table index */
    tbl_index = usb_pstd_get_confignum_to_tblindex( usb_gpstd_ConfigNum );

    /* Get Configuration Descriptor - bmAttributes */
    atr = *(uint8_t*)((uint32_t)usb_gpstd_Driver.configtbl[tbl_index] + (uint32_t)7u);
    /* Remote Wakeup check(= D5) */
    if( (atr & USB_CF_RWUPON) == USB_CF_RWUPON )
    {
        return USB_YES;
    }
    return USB_NO;
}
/******************************************************************************
End of function usb_pstd_ChkRemote
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_GetCurrentPower
Description     : Find out how the peripheral is powered by looking at the con-
                : figuration descriptor.
Arguments       : none
Return value    : uint8_t : Current power means; self-powered or bus-powered
                : (GS_SELFPOWERD/GS_BUSPOWERD).
******************************************************************************/
uint8_t usb_pstd_GetCurrentPower(void)
{
    /*
     * Please answer the currently power of your system.
     */

    uint8_t tmp, currentpower, conf;
    uint16_t    tbl_index;

    conf = (uint8_t)usb_gpstd_ConfigNum;
    if( conf < (uint8_t)1 )
    {
        /* Address state */
        conf = (uint8_t)1;
    }

    /* Get Configuration descriptor table index */
    tbl_index = usb_pstd_get_confignum_to_tblindex( conf );

    /* Standard configuration descriptor */
    tmp = *(uint8_t*)((uint32_t)usb_gpstd_Driver.configtbl[tbl_index] + (uint32_t)7u);
    if( (tmp & USB_CF_SELFP) == USB_CF_SELFP )
    {
        /* Self Powered */
        currentpower = USB_GS_SELFPOWERD;
    }
    else
    {
        /* Bus Powered */
        currentpower = USB_GS_BUSPOWERD;
    }

    /* Check currently powered */

    return currentpower;
}
/******************************************************************************
End of function usb_pstd_GetCurrentPower
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetPipeRegister
Description     : Configure specified pipe.
Arguments       : uint16_t pipe_number  : Pipe number.
                : uint16_t *tbl         : DEF_EP table pointer.
Return value    : none
******************************************************************************/
void usb_pstd_SetPipeRegister(USB_UTR_t *ptr, uint16_t pipe_number, uint16_t *tbl)
{
    uint16_t        i, pipe, ep, buf;

    switch( pipe_number )
    {
    /* All pipe initialized */
    case USB_USEPIPE:
        /* Current FIFO port Clear */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE,  USB_NO);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
        for( i = 0; tbl[i] != USB_PDTBLEND; i += USB_EPL )
        {
            /* Pipe number */
            pipe = (uint16_t)(tbl[i + 0] & USB_CURPIPE);
            usb_cstd_pipe_init(ptr, pipe, tbl, i);
        }
        break;
    /* Peripheral pipe initialized */
    case USB_PERIPIPE:
        /* Current FIFO port Clear */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE,  USB_NO);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
        for( ep = USB_EP1; ep <= USB_MAX_EP_NO; ++ep )
        {
            if( usb_gpstd_EpTblIndex[ep] != USB_ERROR )
            {
                i = (uint16_t)(USB_EPL * usb_gpstd_EpTblIndex[ep]);
                /* Pipe number */
                pipe = (uint16_t)(tbl[i + 0] & USB_CURPIPE);
                usb_cstd_pipe_init(ptr, pipe, tbl, i);
            }
        }
        break;
    /* Clear Peripheral pipe register */
    case USB_CLRPIPE:
        /* Current FIFO port Clear */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE,  USB_NO);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
        for( ep = USB_EP1; ep <= USB_MAX_EP_NO; ++ep )
        {
            if( usb_gpstd_EpTblIndex[ep] != USB_ERROR )
            {
                i = (uint16_t)(USB_EPL * usb_gpstd_EpTblIndex[ep]);
                /* Pipe number */
                pipe = (uint16_t)(tbl[i + 0] & USB_CURPIPE);
                usb_cstd_ClrPipeCnfg(ptr, pipe);
            }
        }
        break;
    /* Pipe initialized */
    default:
        /* Current FIFO port clear */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE, USB_NO);
        /* D0FIFO */
        buf = usb_creg_read_fifosel( ptr, USB_D0DMA );
        if( (buf & USB_CURPIPE) == pipe_number )
        {
            usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
        }
        /* D1FIFO */
        buf = usb_creg_read_fifosel( ptr, USB_D1DMA );
        if( (buf & USB_CURPIPE) == pipe_number )
        {
            usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
        }
        for( i = 0; tbl[i] != USB_PDTBLEND; i += USB_EPL )
        {
            /* Pipe number */
            pipe = (uint16_t)(tbl[i + 0] & USB_CURPIPE);
            if( pipe == pipe_number )
            {
                usb_cstd_pipe_init(ptr, pipe, tbl, i);
            }
        }
        break;
    }
}
/******************************************************************************
End of function usb_pstd_SetPipeRegister
******************************************************************************/



/******************************************************************************
Function Name   : usb_pstd_ControlRead
Description     : Called by R_usb_pstd_ControlRead, see it for description.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : uint32_t bsize    : Read size in bytes.
                : uint8_t *table    : Start address of read data buffer.
Return value    : uint16_t          : USB_WRITESHRT/USB_WRITE_END/USB_WRITING/
                :                   : USB_FIFOERROR.
******************************************************************************/
uint16_t usb_pstd_ControlRead(USB_UTR_t *ptr, uint32_t bsize, uint8_t *table)
{
    uint16_t    end_flag;

    usb_gcstd_DataCnt[ptr->ip][USB_PIPE0] = bsize;
    usb_gcstd_DataPtr[ptr->ip][USB_PIPE0] = table;

    usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE, (uint16_t)USB_ISEL);
    
    /* Buffer clear */
    usb_creg_set_bclr( ptr, USB_CUSE );

    usb_creg_clr_sts_bemp( ptr, USB_PIPE0 );

    /* Peripheral Control sequence */
    end_flag = usb_cstd_write_data( ptr, USB_PIPE0, USB_CUSE );

    /* Peripheral control sequence */
    switch( end_flag )
    {
    /* End of data write */
    case USB_WRITESHRT:
        /* Enable not ready interrupt */
        usb_cstd_NrdyEnable(ptr, (uint16_t)USB_PIPE0);
        /* Set PID=BUF */
        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
    /* End of data write (not null) */
    case USB_WRITEEND:
        /* Continue */
    /* Continue of data write */
    case USB_WRITING:
        /* Enable empty interrupt */
        usb_creg_set_bempenb(ptr, (uint16_t)USB_PIPE0);
        /* Enable not ready interrupt */
        usb_cstd_NrdyEnable(ptr, (uint16_t)USB_PIPE0);
        /* Set PID=BUF */
        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
    /* FIFO access error */
    case USB_FIFOERROR:
        break;
    default:
        break;
    }
    /* End or error or continue */
    return (end_flag);
}
/******************************************************************************
End of function usb_pstd_ControlRead
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_ControlEnd
Description     : End control transfer
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : uint16_t status   : Transfer end status
Return value    : none
******************************************************************************/
void usb_pstd_ControlEnd(USB_UTR_t *ptr, uint16_t status)
{
    /* Interrupt disable */
    /* BEMP0 disable */
    usb_creg_clr_bempenb(ptr, (uint16_t)USB_PIPE0);
    /* BRDY0 disable */
    usb_creg_clr_brdyenb(ptr, (uint16_t)USB_PIPE0);
    /* NRDY0 disable */
    usb_creg_clr_nrdyenb(ptr, (uint16_t)USB_PIPE0);

    usb_creg_set_mbw( ptr, USB_CUSE, USB_MBW );

    if( (status == USB_DATA_ERR) || (status == USB_DATA_OVR) )
    {
        /* Request error */
        usb_pstd_SetStallPipe0( ptr );
    }
    else if( status == USB_DATA_STOP )
    {
        /* Pipe stop */
        usb_cstd_SetNak(ptr, (uint16_t)USB_PIPE0);
    }
    else
    {
        /* Set CCPL bit */
        usb_preg_set_ccpl( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_ControlEnd
******************************************************************************/



/******************************************************************************
Function Name   : R_usb_pstd_PcdOpen
Description     : Start PCD(Peripheral Control Driver) task (RTOS version)
                : Initialize pipe information (non-OS version).
Arguments       : USB_UTR_t *ptr : USB system internal structure. Selects channel.
Return value    : USB_ER_t       : Error info.
******************************************************************************/
USB_ER_t R_usb_pstd_PcdOpen(USB_UTR_t *ptr)
{
    uint16_t    i;

    R_usb_cstd_SetTaskPri(USB_PCD_TSK,  USB_PRI_0);

    for( i = USB_PIPE0; i <= USB_MAX_PIPE_NO; i++ )
    {
        usb_gpstd_StallPipe[i]  = USB_DONE;
        usb_gcstd_Pipe[ptr->ip][i]      = (USB_UTR_t*)USB_NULL;
    }

    return USB_E_OK;
}/* eof R_usb_pstd_PcdOpen */

/******************************************************************************
Function Name   : R_usb_pstd_PcdClose
Description     : Stop PCD(Peripheral Control Driver) task
Arguments       : USB_UTR_t *ptr : Not used.
Return value    : USB_ER_t       : Error info.
******************************************************************************/
USB_ER_t R_usb_pstd_PcdClose(USB_UTR_t *ptr)
{
    return USB_E_OK;
}/* eof R_usb_pstd_PcdClose */

/******************************************************************************
Function Name   : R_usb_pstd_TransferStart
Description     : Transfer the data of each pipe 
                : Request PCD to transfer data, and the PCD transfers the data 
                  based on the transfer information stored in ptr
Arguments       : USB_UTR_t *ptr : keyword, msghead and msginfo are used for...  $REA
Return value    : USB_ER_t       : Error info.
******************************************************************************/
USB_ER_t R_usb_pstd_TransferStart(USB_UTR_t *ptr)
{
    USB_ER_t        err;
    uint16_t        pipenum;

    pipenum = ptr->keyword;
    if( usb_gcstd_Pipe[ptr->ip][pipenum] != USB_NULL )
    {
        /* Get PIPE TYPE */
        if( usb_cstd_GetPipeType(ptr, pipenum) != USB_ISO )
        {
            USB_PRINTF1("### R_usb_pstd_TransferStart overlaps %d\n", pipenum);
            return USB_E_QOVR;
        }
    }

    /* Check state ( Configured ) */
    if( usb_pstd_ChkConfigured(ptr) != USB_YES )
    {
        USB_PRINTF0("### R_usb_pstd_TransferStart not configured\n");
        return USB_E_ERROR;
    }

    if( pipenum == USB_PIPE0 )
    {
        USB_PRINTF0("### R_usb_pstd_TransferStart PIPE0 is not support\n");
        return USB_E_ERROR;
    }

    ptr->msghead    = (USB_MH_t)USB_NULL;
    ptr->msginfo    = USB_MSG_PCD_SUBMITUTR;
    /* Send message */
    err = USB_SND_MSG(USB_PCD_MBX, (USB_MSG_t*)ptr);
    if( err != USB_E_OK )
    {
        USB_PRINTF1("### pTransferStart snd_msg error (%ld)\n", err);
    }
    return err;
}/* eof R_usb_pstd_TransferStart() */

/******************************************************************************
Function Name   : R_usb_pstd_TransferEnd
Description     : Force termination of data transfer of specified pipe. Request 
                : PCD to force termination 
                  data transfer, and the PCD forced-terminates data transfer. 
Arguments       : USB_UTR_t *ptr : USB system internal structure. Selects channel. 
                : uint16_t pipe     : Pipe number.
                : uint16_t status   : End status.
Return value    : USB_ER_t          : Error info.
******************************************************************************/
USB_ER_t R_usb_pstd_TransferEnd(USB_UTR_t *ptr, uint16_t pipe, uint16_t status)
{
    uint16_t        info;

    if( usb_gcstd_Pipe[ptr->ip][pipe] == USB_NULL )
    {
        USB_PRINTF0("### R_usb_pstd_TransferEnd overlaps\n");
        return USB_E_QOVR;
    }

    /* check Time out */
    if( status == USB_DATA_TMO )
    {
        info = USB_MSG_PCD_TRANSEND1;
    }
    else
    {
        info = USB_MSG_PCD_TRANSEND2;
    }

    /* PCD Send Mailbox */
    return usb_pstd_PcdSndMbx(ptr, info, pipe, &usb_cstd_DummyFunction);
}/* eof R_usb_pstd_TransferEnd() */

/******************************************************************************
Function Name   : R_usb_pstd_PcdChangeDeviceState
Description     : Change USB Device to the status specified by argument
Arguments       : USB_UTR_t *ptr : USB system internal structure.
                : uint16_t state            : New device status.
                : uint16_t port_no          : Pipe number etc.
                : USB_CB_INFO_t complete    : Callback function.
Return value    : USB_ER_t                  : Error info.
******************************************************************************/
USB_ER_t R_usb_pstd_PcdChangeDeviceState(USB_UTR_t *ptr, uint16_t state, uint16_t port_no, USB_CB_INFO_t complete)
{
    USB_ER_t        err;

    /* PCD Send Mailbox */
    err = usb_pstd_PcdSndMbx(ptr, state, port_no, complete);
    
    return err;
}/* eof R_usb_pstd_PcdChangeDeviceState() */

/******************************************************************************
Function Name   : R_usb_pstd_DeviceInformation
Description     : Get USB Device information such as USB Device status and con-
                : figuration No. etc. 
Arguments       : USB_UTR_t *ptr : USB system internal structure.
                : uint16_t *tbl  : Device information storage pointer TBL. This 
                : pointer is used to provide the caller with the device's sta-
                : tus, speed, configuration and interface number, and the value
                : of the remote wakeup flag.
Return value    : none
******************************************************************************/
void R_usb_pstd_DeviceInformation(USB_UTR_t *ptr, uint16_t *tbl)
{
    /* Device status */
    tbl[0] = usb_creg_read_intsts( ptr ) & (uint16_t)(USB_VBSTS|USB_DVSQ);

    /* Speed */
    tbl[1] = usb_cstd_PortSpeed(ptr, (uint16_t)USB_PORT0);

    /* Configuration number */
    tbl[2] = usb_gpstd_ConfigNum;

    /* Interface number */
    tbl[3] = usb_pstd_GetInterfaceNum(usb_gpstd_ConfigNum);

    /* Remote Wakeup Flag */
    tbl[4] = usb_gpstd_RemoteWakeup;
}/* eof R_usb_pstd_DeviceInformation() */

/******************************************************************************
Function Name   : R_usb_pstd_DriverRegistration
Description     : Register pipe information table, descriptor information table, 
                : callback function, etc. This info is specified by the data in
                : the structure USB_PCDREG_t.
Arguments       : USB_UTR_t *ptr : USB system internal structure.
                : USB_PCDREG_t *registinfo : Class driver structure.
Return value    : none
******************************************************************************/
void R_usb_pstd_DriverRegistration(USB_UTR_t *ptr, USB_PCDREG_t *registinfo)
{
    USB_PCDREG_t    *driver;

    driver = &usb_gpstd_Driver;
    /* Pipe define table address */
    driver->pipetbl     = registinfo->pipetbl;
    /* Device descriptor table address */
    driver->devicetbl   = registinfo->devicetbl;
    /* Qualifier descriptor table address */
    driver->qualitbl    = registinfo->qualitbl;
    /* Configuration descriptor table address */
    driver->configtbl   = registinfo->configtbl;
    /* Other configuration descriptor table address */
    driver->othertbl    = registinfo->othertbl;
    /* String descriptor table address */
    driver->stringtbl   = registinfo->stringtbl;
    /* Driver init */
    driver->classinit   = registinfo->classinit;
    /* Device default */
    driver->devdefault  = registinfo->devdefault;
    /* Device configured */
    driver->devconfig   = registinfo->devconfig;
    /* Device detach */
    driver->devdetach   = registinfo->devdetach;
    /* Device suspend */
    driver->devsuspend  = registinfo->devsuspend;
    /* Device resume */
    driver->devresume   = registinfo->devresume;
    /* Interfaced change */
    driver->interface   = registinfo->interface;
    /* Control transfer */
    driver->ctrltrans   = registinfo->ctrltrans;
    /* Initialized device driver */
    (*driver->classinit)(ptr, (uint16_t)USB_NO_ARG, (uint16_t)USB_NO_ARG);
}/* eof R_usb_pstd_DriverRegistration() */

/******************************************************************************
Function Name   : R_usb_pstd_DriverRelease
Description     : Clear the information registered in the structure USB_PCDREG_t.
Arguments       : none
Return value    : none
******************************************************************************/
void R_usb_pstd_DriverRelease(void)
{
    USB_PCDREG_t    *driver;

    driver = &usb_gpstd_Driver;
    /* Pipe define table address */
    driver->pipetbl     = (uint16_t**)0u;
    /* Device descriptor table address */
    driver->devicetbl   = (uint8_t*)0u;
    /* Qualifier descriptor table address */
    driver->qualitbl    = (uint8_t*)0u;
    /* Configuration descriptor table address */
    driver->configtbl   = (uint8_t**)0u;
    /* Other configuration descriptor table address */
    driver->othertbl    = (uint8_t**)0u;
    /* String descriptor table address */
    driver->stringtbl   = (uint8_t**)0u;
    /* Driver init */
    driver->classinit   = &usb_cstd_DummyFunction;
    /* Device default */
    driver->devdefault  = &usb_cstd_DummyFunction;
    /* Device configured */
    driver->devconfig   = &usb_cstd_DummyFunction;
    /* Device detach */
    driver->devdetach   = &usb_cstd_DummyFunction;
    /* Device suspend */
    driver->devsuspend  = &usb_cstd_DummyFunction;
    /* Device resume */
    driver->devresume   = &usb_cstd_DummyFunction;
    /* Interfaced change */
    driver->interface   = &usb_cstd_DummyFunction;
    /* Control transfer */
    driver->ctrltrans   = &usb_cstd_DummyTrn;
}/* eof R_usb_pstd_DriverRelease() */

/******************************************************************************
Function Name   : R_usb_pstd_SetPipeRegister
Description     : Set specified pipe configuration of specified pipe no.
Arguments       : USB_UTR_t *ptr : USB system internal structure.
                : uint16_t pipe_number  : pipe number
                : uint16_t *tbl         : DEF_EP table pointer
Return value    : none
******************************************************************************/
void R_usb_pstd_SetPipeRegister(USB_UTR_t *ptr, uint16_t pipe_number, uint16_t *tbl)
{
    usb_pstd_SetPipeRegister( ptr, pipe_number, tbl);
}/* eof R_usb_pstd_SetPipeRegister() */

/******************************************************************************
Function Name   : R_usb_pstd_PcdTask
Description     : Call PCD (Peripheral Control Driver) task (API for nonOS).
Arguments       : USB_VP_INT stacd: Start Code
Return value    : none
******************************************************************************/
void R_usb_pstd_PcdTask(USB_VP_INT stacd)
{

    usb_pstd_PcdTask( stacd );

}/* eof R_usb_pstd_PcdTask() */

/******************************************************************************
Function Name   : R_usb_pstd_SetPipeStall
Description     : Pipe Stall Set
Arguments       : USB_UTR_t *ptr
Return value    : none
******************************************************************************/
void R_usb_pstd_SetPipeStall(USB_UTR_t *ptr, uint16_t pipeno)
{
    usb_pstd_SetStall(ptr, pipeno);
}
/******************************************************************************
End of function R_usb_pstd_SetPipeStall
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_pstd_SetStall
Description     : Set pipe stall request
Arguments       : USBC_CB_INFO_t complete ; callback function
                : uint16_t pipe ; pipe number
Return value    : USBC_ER_t Error Info
******************************************************************************/
USB_ER_t R_usb_pstd_SetStall(USB_UTR_t *ptr, USB_CB_INFO_t complete, uint16_t pipe)
{
    /* PCD Send Mailbox */
    return usb_pstd_PcdSndMbx(ptr, (uint16_t)USB_MSG_PCD_SETSTALL, pipe, complete);
}
/******************************************************************************
End of function R_usb_pstd_SetStall
******************************************************************************/

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
uint16_t R_usb_pstd_ControlRead(USB_UTR_t *ptr, uint32_t bsize, uint8_t *table)
{
    uint16_t    end_flag;

    end_flag = usb_pstd_ControlRead( ptr, bsize, table);

    return (end_flag);
}
/******************************************************************************
End of function R_usb_pstd_ControlRead
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_pstd_ControlWrite
Description     : Start control write transfer (API). When a valid control write 
                : request from host is received, the ControlWrite function 
                : enables data reception from the host.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : uint32_t bsize    : Write size in bytes.
                : uint8_t *table    : Start address of write data buffer.
Return value    : none
******************************************************************************/
void R_usb_pstd_ControlWrite(USB_UTR_t *ptr, uint32_t bsize, uint8_t *table)
{
    usb_gcstd_DataCnt[ptr->ip][USB_PIPE0] = bsize;
    usb_gcstd_DataPtr[ptr->ip][USB_PIPE0] = table;

    usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE, USB_NO);
    /* Buffer clear */
    usb_creg_set_bclr( ptr, USB_CUSE );

    /* Interrupt enable */
    /* Enable ready interrupt */
    usb_creg_set_brdyenb(ptr, (uint16_t)USB_PIPE0);
    /* Enable not ready interrupt */
    usb_cstd_NrdyEnable(ptr, (uint16_t)USB_PIPE0);

    /* Set PID=BUF */
    usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
}
/******************************************************************************
End of function R_usb_pstd_ControlWrite
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_pstd_ControlEnd
Description     : End control transfer.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : uint16_t status   : Control transfer status.
Return value    : none
******************************************************************************/
void R_usb_pstd_ControlEnd(USB_UTR_t *ptr, uint16_t status)
{
    usb_pstd_ControlEnd( ptr, status);
}
/******************************************************************************
End of function R_usb_pstd_ControlEnd
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_pstd_usbdriver_start
Description     :  Start peripheral USB low-level driver task.
Argument        : none
Return          : none
******************************************************************************/
void R_usb_pstd_usbdriver_start( USB_UTR_t *ptr )
{
    /* Task Start Processing */
    R_usb_pstd_PcdOpen(ptr);            /* Pcd open */
}
/******************************************************************************
End of function R_usb_pstd_usbdriver_start()
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_BrdyPipe
Description     : Execute data transfer for the PIPE for which a BRDY interrupt 
                : occurred.
Arguments       : uint16_t bitsts : BRDYSTS register & BRDYENB register.
Return value    : none
******************************************************************************/
void usb_pstd_BrdyPipe(USB_UTR_t *ptr, uint16_t bitsts)
{
    /* When operating by the peripheral function, usb_cstd_brdy_pipe() is executed with PIPEx request because */
    /* two BRDY messages are issued even when the demand of PIPE0 and PIPEx has been generated at the same time. */
    if( (bitsts & USB_BRDY0) == USB_BRDY0 )
    {
        switch( usb_cstd_read_data( ptr, USB_PIPE0, USB_CUSE ) )
        {
            /* End of data read */
            case USB_READEND:
                /* Continue */
            /* End of data read */
            case USB_READSHRT:
                usb_creg_clr_brdyenb(ptr, (uint16_t)USB_PIPE0);
            break;
            /* Continue of data read */
            case USB_READING:
                /* PID = BUF */
                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
            break;
            /* FIFO access error */
            case USB_READOVER:
                USB_PRINTF0("### Receive data over PIPE0 \n");
                /* Clear BVAL */
                usb_creg_set_bclr( ptr, USB_CUSE );
                /* Control transfer stop(end) */
                usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_OVR);
            break;
            /* FIFO access error */
            case USB_FIFOERROR:
                USB_PRINTF0("### FIFO access error \n");
                /* Control transfer stop(end) */
                usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
            break;
            default:
            break;
        }
    }
    else
    {
        /* not PIPE0 */
        usb_cstd_BrdyPipe(ptr, bitsts);
    }
}
/******************************************************************************
End of function usb_pstd_BrdyPipe
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_NrdyPipe
Description     : Execute appropriate processing for the PIPE for which a NRDY 
                : interrupt occurred.
Arguments       : uint16_t bitsts : NRDYSTS register & NRDYENB register.
Return value    : none
******************************************************************************/
void usb_pstd_NrdyPipe(USB_UTR_t *ptr, uint16_t bitsts)
{
    /* The function for peripheral driver is created here. */
    if( (bitsts & USB_NRDY0) == USB_NRDY0 )
    {
    }
    else
    {
        /* Nrdy Pipe interrupt */
        usb_cstd_NrdyPipe(ptr, bitsts);
    }
}
/******************************************************************************
End of function usb_pstd_NrdyPipe
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_BempPipe
Description     : Execute data transfer for the PIPE for which a BEMP interrupt 
                : occurred.
Arguments       : uint16_t bitsts : BEMPSTS register & BEMPENB register.
Return value    : none
******************************************************************************/
void usb_pstd_BempPipe(USB_UTR_t *ptr, uint16_t bitsts)
{
    /* When operating by the peripheral function, usb_cstd_bemp_pipe() is executed with PIPEx request because */
    /* two BEMP messages are issued even when the demand of PIPE0 and PIPEx has been generated at the same time. */
    if( (bitsts & USB_BEMP0) == USB_BEMP0 )
    {
        switch( usb_cstd_write_data( ptr, USB_PIPE0, USB_CUSE ) )
        {
            /* End of data write (not null) */
            case USB_WRITEEND:
                /* Continue */
            /* End of data write */
            case USB_WRITESHRT:
                /* Enable empty interrupt */
                usb_creg_clr_bempenb(ptr, (uint16_t)USB_PIPE0);
            break;
            /* Continue of data write */
            case USB_WRITING:
                /* PID = BUF */
                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
            break;
            /* FIFO access error */
            case USB_FIFOERROR:
                USB_PRINTF0("### FIFO access error \n");
                /* Control transfer stop(end) */
                usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
            break;
            default:
            break;
        }
    }
    else
    {
        /* BEMP interrupt */
        usb_cstd_BempPipe(ptr, bitsts);
    }
}
/******************************************************************************
End of function usb_pstd_BempPipe
******************************************************************************/



/******************************************************************************
Function Name   : usb_pstd_DpEnable
Description     : D+ Line Pull-up Enable
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_DpEnable(USB_UTR_t *ptr)
{

    usb_preg_set_dprpu( ptr );

}
/******************************************************************************
End of function usb_pstd_DpEnable
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_DpDisable
Description     : D+ Line Pull-up Disable
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
**************************************************************************/
void usb_pstd_DpDisable(USB_UTR_t *ptr)
{

    usb_preg_clr_dprpu( ptr );

}
/******************************************************************************
End of function usb_pstd_DpDisable
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_BusReset
Description     : A USB bus reset was issued by the host. Execute relevant pro-
                : cessing.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_BusReset(USB_UTR_t *ptr)
{
    uint16_t    connect_info;

    /* Bus Reset */
    usb_pstd_BusresetFunction(ptr);

    /* Memory clear */
    usb_pstd_ClearMem();
    connect_info = usb_cstd_PortSpeed(ptr, (uint16_t)USB_PORT0);
    /* Callback */
    (*usb_gpstd_Driver.devdefault)(ptr, connect_info, (uint16_t)USB_NO_ARG);
    /* DCP configuration register  (0x5C) */
    usb_creg_write_dcpcfg( ptr, 0 );
    /* DCP maxpacket size register (0x5E) */
    usb_creg_write_dcpmxps( ptr, usb_gpstd_Driver.devicetbl[USB_DEV_MAX_PKT_SIZE]);
}
/******************************************************************************
 End of function usb_pstd_BusReset
 ******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_InitConnect
Description     : Set up interrupts and initialize.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_InitConnect(USB_UTR_t *ptr)
{
    uint16_t        connect_info;

    /* Interrupt enable */
    usb_pstd_InterruptEnable(ptr);
    usb_cstd_SetHse(ptr, (uint16_t)USB_PORT0, usb_gcstd_HsEnable[ptr->ip]);

    connect_info = usb_pstd_InitFunction( ptr );
    
    switch( connect_info )
    {
    /* Attach host controller */
    case USB_ATTACH:
        usb_pstd_AttachProcess(ptr);
        break;
    /* Detach host controller */
    case USB_DETACH:
        usb_pstd_DetachProcess(ptr);
        break;
    default:
        break;
    }
}
/******************************************************************************
End of function usb_pstd_InitConnect
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_AttachProcess
Description     : USB attach setting.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_AttachProcess(USB_UTR_t *ptr)
{
    usb_pstd_AttachFunction( ptr );
    usb_cpu_DelayXms((uint16_t)10);
    usb_preg_set_dprpu( ptr );
}
/******************************************************************************
End of function usb_pstd_AttachProcess
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_DetachProcess
Description     : Initialize USB registers for detaching, and call the callback
                : function that completes the detach.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_DetachProcess(USB_UTR_t *ptr)
{
    uint16_t        i, conf;
    uint16_t        *tbl;

    /* Pull-up disable */
    usb_preg_clr_dprpu( ptr );
    usb_cpu_Delay1us((uint16_t)2);
    usb_creg_set_dcfm( ptr );
    usb_cpu_Delay1us((uint16_t)1);
    usb_creg_clr_dcfm( ptr );

    conf = usb_gpstd_ConfigNum;
    if( conf < (uint16_t)1 )
    {
        /* Address state */
        conf = (uint16_t)1;
    }

    /* Configuration number */
    usb_gpstd_ConfigNum = 0;
    /* Remote wakeup enable flag */
    usb_gpstd_RemoteWakeup = USB_NO;

    /* INTSTS0 clear */
    usb_gpstd_intsts0 = 0;

    tbl = usb_gpstd_Driver.pipetbl[conf - 1];
    for( i = 0; tbl[i] != USB_PDTBLEND; i += USB_EPL )
    {
        usb_cstd_ForcedTermination(ptr, tbl[i], (uint16_t)USB_DATA_STOP);
        usb_cstd_ClrPipeCnfg(ptr, tbl[i]);
    }
    /* Callback */
    (*usb_gpstd_Driver.devdetach)(ptr, (uint16_t)USB_NO_ARG, (uint16_t)USB_NO_ARG);
    usb_cstd_StopClock(ptr);
}
/******************************************************************************
End of function usb_pstd_DetachProcess
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SuspendProcess
Description     : Perform a USB peripheral suspend.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_SuspendProcess(USB_UTR_t *ptr)
{
    uint16_t    intsts0, buf;

    /* Resume interrupt enable */
    usb_preg_set_enb_rsme( ptr );

    intsts0 = usb_creg_read_intsts( ptr );
    buf = usb_creg_read_syssts( ptr, USB_PORT0 );
    if(((intsts0 & USB_DS_SUSP) != (uint16_t)0) && ((buf & USB_LNST) == USB_FS_JSTS))
    {
        /* Suspend */
        usb_cstd_StopClock(ptr);
        usb_pstd_SuspendFunction(ptr);
    }
    /* --- SUSPEND -> RESUME --- */
    else
    {
        /* RESM status clear */
        usb_preg_clr_sts_resm( ptr );
        /* RESM interrupt disable */
        usb_preg_clr_enb_rsme( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_SuspendProcess
******************************************************************************/



/******************************************************************************
Function Name   : usb_pstd_SetFeatureFunction
Description     : Process a SET_FEATURE request.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetFeatureFunction(USB_UTR_t *ptr)
{
    /* Request error */
    usb_pstd_SetStallPipe0(ptr);
}
/******************************************************************************
End of function usb_pstd_SetFeatureFunction
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_ChkVbsts
Description     : Return the VBUS status.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return          : uint16_t connection status(ATTACH/DETACH)
******************************************************************************/
uint16_t usb_pstd_ChkVbsts(USB_UTR_t *ptr)
{
    uint16_t    buf1, buf2, buf3;
    uint16_t    connect_info;

    /* VBUS chattering cut */
    do
    {
        buf1 = usb_creg_read_intsts( ptr );
        usb_cpu_Delay1us((uint16_t)10);
        buf2 = usb_creg_read_intsts( ptr );
        usb_cpu_Delay1us((uint16_t)10);
        buf3 = usb_creg_read_intsts( ptr );
    }
    while( ((buf1 & USB_VBSTS) != (buf2 & USB_VBSTS))
          || ((buf2 & USB_VBSTS) != (buf3 & USB_VBSTS)) );

    /* VBUS status judge */
    if( (buf1 & USB_VBSTS) != (uint16_t)0 )
    {
        /* Attach */
        connect_info = USB_ATTACH;
    }
    else
    {
        /* Detach */
        connect_info = USB_DETACH;
    }
    return connect_info;
}
/******************************************************************************
End of function usb_pstd_ChkVbsts
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_AttachFunction
Description     : Processing for attach detect.(Waiting time of stabilize VBUS.)
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_AttachFunction(USB_UTR_t *ptr)
{
    /* Delay about 10ms(Waiting time of stabilize VBUS.) */
    usb_cpu_DelayXms((uint16_t)10);
}
/******************************************************************************
End of function usb_pstd_AttachFunction
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_BusresetFunction
Description     : Processing for USB bus reset detection.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_BusresetFunction(USB_UTR_t *ptr)
{
}
/******************************************************************************
End of function usb_pstd_BusresetFunction
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SuspendFunction
Description     : Processing for suspend signal detection.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SuspendFunction(USB_UTR_t *ptr)
{
}
/******************************************************************************
End of function usb_pstd_SuspendFunction
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_InitFunction
Description     : Call function that checks VBUS status.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
uint16_t usb_pstd_InitFunction(USB_UTR_t *ptr)
{
    /* Wait USBC_VBSTS */
    return usb_pstd_ChkVbsts( ptr );
}
/******************************************************************************
End of function usb_pstd_InitFunction
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_StandReq0
Description     : The idle and setup stages of a standard request from host.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_StandReq0(USB_UTR_t *ptr)
{
    switch( usb_gpstd_ReqRequest )
    {
        case USB_CLEAR_FEATURE:
            /* Clear Feature0 */
            usb_pstd_ClearFeature0();
        break;
        case USB_SET_FEATURE:
            /* Set Feature0 */
            usb_pstd_SetFeature0();
        break;
        case USB_SET_ADDRESS:
            /* Set Address0 */
            usb_pstd_SetAddress0();
        break;
        case USB_SET_CONFIGURATION:
            /* Set Configuration0 */
            usb_pstd_SetConfiguration0(ptr);
        break;
        case USB_SET_INTERFACE:
            /* Set Interface0 */
            usb_pstd_SetInterface0(ptr);
        break;
        default:
        break;
    }
}
/******************************************************************************
End of function usb_pstd_StandReq0
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_StandReq1
Description     : The control read data stage of a standard request from host.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_StandReq1(USB_UTR_t *ptr)
{
    switch( usb_gpstd_ReqRequest )
    {
        case USB_GET_STATUS:
            /* Get Status1 */
            usb_pstd_GetStatus1(ptr);
        break;
        case USB_GET_DESCRIPTOR:
            /* Get Descriptor1 */
            usb_pstd_GetDescriptor1(ptr);
        break;
        case USB_GET_CONFIGURATION:
            /* Get Configuration1 */
            usb_pstd_GetConfiguration1(ptr);
        break;
        case USB_GET_INTERFACE:
            /* Get Interface1 */
            usb_pstd_GetInterface1(ptr);
        break;
        case USB_SYNCH_FRAME:
            /* Synch Frame */
            usb_pstd_SynchFrame1(ptr);
        break;
        default:
            /* Set pipe USB_PID_STALL */
            usb_pstd_SetStallPipe0( ptr );
        break;
    }
}
/******************************************************************************
End of function usb_pstd_StandReq1
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_StandReq2
Description     : The control write data stage of a standard request from host.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_StandReq2(USB_UTR_t *ptr)
{
    if( usb_gpstd_ReqRequest == USB_SET_DESCRIPTOR )
    {
        /* Set Descriptor2 */
        usb_pstd_SetDescriptor2(ptr);
    }
    else
    {
        /* Set pipe USB_PID_STALL */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_StandReq2
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_StandReq3
Description     : Standard request process. This is for the status stage of a 
                : control write where there is no data stage.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_StandReq3(USB_UTR_t *ptr)
{
    switch( usb_gpstd_ReqRequest )
    {
        case USB_CLEAR_FEATURE:
            /* ClearFeature3 */
            usb_pstd_ClearFeature3(ptr);
        break;
        case USB_SET_FEATURE:
            /* SetFeature3 */
            usb_pstd_SetFeature3(ptr);
        break;
        case USB_SET_ADDRESS:
            /* SetAddress3 */
            usb_pstd_SetAddress3(ptr);
        break;
        case USB_SET_CONFIGURATION:
            /* SetConfiguration3 */
            usb_pstd_SetConfiguration3(ptr);
        break;
        case USB_SET_INTERFACE:
            /* SetInterface3 */
            usb_pstd_SetInterface3(ptr);
        break;
        default:
            /* Set pipe USB_PID_STALL */
            usb_pstd_SetStallPipe0( ptr );
        break;
    }
    /* Control transfer stop(end) */
    usb_pstd_ControlEnd(ptr, (uint16_t)USB_CTRL_END);
}
/******************************************************************************
End of function usb_pstd_StandReq3
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_StandReq4
Description     : The control read status stage of a standard request from host.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_StandReq4(USB_UTR_t *ptr)
{
    switch( usb_gpstd_ReqRequest )
    {
        case USB_GET_STATUS:
            /* GetStatus4 */
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
        case USB_GET_DESCRIPTOR:
            /* GetDescriptor4 */
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
        case USB_GET_CONFIGURATION:
            /* GetConfiguration4 */
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
        case USB_GET_INTERFACE:
            /* GetInterface4 */
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
        case USB_SYNCH_FRAME:
            /* SynchFrame4 */
            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
        break;
        default:
            /* Set pipe USB_PID_STALL */
            usb_pstd_SetStallPipe0( ptr );
        break;
    }
    /* Control transfer stop(end) */
    usb_pstd_ControlEnd(ptr, (uint16_t)USB_CTRL_END);
}
/******************************************************************************
End of function usb_pstd_StandReq4
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_StandReq5
Description     : The control write status stage of a standard request from host.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_StandReq5(USB_UTR_t *ptr)
{
    if( usb_gpstd_ReqRequest == USB_SET_DESCRIPTOR )
    {
        /* Set pipe PID_BUF */
        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
    }
    else
    {
        /* Set pipe USB_PID_STALL */
        usb_pstd_SetStallPipe0( ptr );
    }
    /* Control transfer stop(end) */
    usb_pstd_ControlEnd(ptr, (uint16_t)USB_CTRL_END);
}
/******************************************************************************
End of function usb_pstd_StandReq5
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_GetStatus1
Description     : Analyze a Get Status command and process it.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_GetStatus1(USB_UTR_t *ptr)
{
    static uint8_t  tbl[2];
    uint16_t        ep;
    uint16_t        buffer, pipe;

    if( (usb_gpstd_ReqValue == 0) && (usb_gpstd_ReqLength == 2) )
    {
        tbl[0] = 0;
        tbl[1] = 0;
        /* Check request type */
        switch( usb_gpstd_ReqTypeRecip )
        {
            case USB_DEVICE:
                if( usb_gpstd_ReqIndex == 0 )
                {
                    /* Self powered / Bus powered */
                    tbl[0] = usb_pstd_GetCurrentPower();
                    /* Support remote wakeup ? */
                    if( usb_gpstd_RemoteWakeup == USB_YES )
                    {
                        tbl[0] |= USB_GS_REMOTEWAKEUP;
                    }
                    /* Control read start */
                    usb_pstd_ControlRead(ptr, (uint32_t)2, tbl);
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            case USB_INTERFACE:
                if( usb_pstd_ChkConfigured(ptr) == USB_YES )
                {
                    if( usb_gpstd_ReqIndex < usb_pstd_GetInterfaceNum(usb_gpstd_ConfigNum) )
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)2, tbl);
                    }
                    else
                    {
                        /* Request error (not exist interface) */
                        usb_pstd_SetStallPipe0( ptr );
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            case USB_ENDPOINT:
                /* Endpoint number */
                ep = (uint16_t)(usb_gpstd_ReqIndex & USB_EPNUMFIELD);
                /* Endpoint 0 */
                if( ep == 0 )
                {
                    buffer = usb_creg_read_dcpctr( ptr );
                    if( (buffer & USB_PID_STALL) != (uint16_t)0 )
                    {
                       /* Halt set */
                       tbl[0] = USB_GS_HALT;
                    }
                    /* Control read start */
                    usb_pstd_ControlRead(ptr, (uint32_t)2, tbl);
                }
                /* EP1 to max */
                else if( ep <= USB_MAX_EP_NO )
                {
                    if( usb_pstd_ChkConfigured(ptr) == USB_YES )
                    {
                        pipe = usb_cstd_Epadr2Pipe(ptr, usb_gpstd_ReqIndex);
                        if( pipe == USB_ERROR )
                        {
                            /* Set pipe USB_PID_STALL */
                            usb_pstd_SetStallPipe0( ptr );
                        }
                        else
                        {
                            buffer = usb_cstd_GetPid(ptr, pipe);
                            if( (buffer & USB_PID_STALL) != (uint16_t)0 )
                            {
                                /* Halt set */
                                tbl[0] = USB_GS_HALT;
                            }
                            /* Control read start */
                            usb_pstd_ControlRead(ptr, (uint32_t)2, tbl);
                        }
                    }
                    else
                    {
                        /* Set pipe USB_PID_STALL */
                        usb_pstd_SetStallPipe0( ptr );
                    }
                }
                else
                {
                    /* Set pipe USB_PID_STALL */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            default:
                /* Set pipe USB_PID_STALL */
                usb_pstd_SetStallPipe0( ptr );
            break;
        }
    }
    else
    {
        /* Set pipe USB_PID_STALL */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_GetStatus1
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_GetDescriptor1
Description     : Analyze a Get Descriptor command from host and process it.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_GetDescriptor1(USB_UTR_t *ptr)
{
    uint16_t    len;
    uint16_t    idx;
    uint8_t     *table;

    if(usb_gpstd_ReqTypeRecip == USB_DEVICE )
    {
        idx = (uint16_t)(usb_gpstd_ReqValue & USB_DT_INDEX);
        switch( (uint16_t)USB_GET_DT_TYPE(usb_gpstd_ReqValue) )
        {
            /*---- Device descriptor ----*/
            case USB_DT_DEVICE:
                if((usb_gpstd_ReqIndex == (uint16_t)0) && (idx == (uint16_t)0))
                {
                    table = usb_gpstd_Driver.devicetbl;
                    if( usb_gpstd_ReqLength < table[0] )
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)usb_gpstd_ReqLength, table);
                    }
                    else
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)table[0], table);
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            /*---- Configuration descriptor ----*/
            case USB_DT_CONFIGURATION:
                if( usb_gpstd_ReqIndex == 0 )
                {
                    table = usb_gpstd_Driver.configtbl[idx];
                    len   = (uint16_t)(*(uint8_t*)((uint32_t)table + (uint32_t)3));
                    len   = (uint16_t)(len << 8);
                    len   += (uint16_t)(*(uint8_t*)((uint32_t)table + (uint32_t)2));
                    /* Descriptor > wLength */
                    if( usb_gpstd_ReqLength < len )
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)usb_gpstd_ReqLength, table);
                    }
                    else
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)len, table);
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            /*---- String descriptor ----*/
            case USB_DT_STRING:
                if( idx < USB_STRINGNUM )
                {
                    table = usb_gpstd_Driver.stringtbl[idx];
                    len   = (uint16_t)(*(uint8_t*)((uint32_t)table + (uint32_t)0));
                    if( usb_gpstd_ReqLength < len )
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)usb_gpstd_ReqLength, table);
                    }
                    else
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)len, table);
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            /*---- Interface descriptor ----*/
            case USB_DT_INTERFACE:
                /* Set pipe USB_PID_STALL */
                usb_pstd_SetStallPipe0( ptr );
            break;
            /*---- Endpoint descriptor ----*/
            case USB_DT_ENDPOINT:
                /* Set pipe USB_PID_STALL */
                usb_pstd_SetStallPipe0( ptr );
            break;
            case USB_DT_DEVICE_QUALIFIER:
                if( ((usb_cstd_HiSpeedEnable(ptr, (uint16_t)USB_PORT0) == USB_YES)
                    && (usb_gpstd_ReqIndex == 0)) && (idx == 0) )
                {
                    table = usb_gpstd_Driver.qualitbl;
                    if( usb_gpstd_ReqLength < table[0] )
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)usb_gpstd_ReqLength, table);
                    }
                    else
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)table[0], table);
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            case USB_DT_OTHER_SPEED_CONF:
                if( (usb_cstd_HiSpeedEnable(ptr, (uint16_t)USB_PORT0) == USB_YES) && (usb_gpstd_ReqIndex == 0) )
                {
                    table = usb_gpstd_Driver.othertbl[idx];
                    len     = (uint16_t)(*(uint8_t*)((uint32_t)table + (uint32_t)3));
                    len     = (uint16_t)(len << 8);
                    len += (uint16_t)(*(uint8_t*)((uint32_t)table + (uint32_t)2));
                    /* Descriptor > wLength */
                    if( usb_gpstd_ReqLength < len )
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)usb_gpstd_ReqLength, table);
                    }
                    else
                    {
                        /* Control read start */
                        usb_pstd_ControlRead(ptr, (uint32_t)len, table);
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            case USB_DT_INTERFACE_POWER:
                /* Not support */
                usb_pstd_SetStallPipe0( ptr );
            break;
            default:
                /* Set pipe USB_PID_STALL */
                usb_pstd_SetStallPipe0( ptr );
            break;
        }
    }
    else if( usb_gpstd_ReqTypeRecip == USB_INTERFACE )
    {
        usb_gpstd_ReqReg.ReqType        = usb_gpstd_ReqType;
        usb_gpstd_ReqReg.ReqTypeType    = usb_gpstd_ReqTypeType;
        usb_gpstd_ReqReg.ReqTypeRecip   = usb_gpstd_ReqTypeRecip;
        usb_gpstd_ReqReg.ReqRequest     = usb_gpstd_ReqRequest;
        usb_gpstd_ReqReg.ReqValue       = usb_gpstd_ReqValue;
        usb_gpstd_ReqReg.ReqIndex       = usb_gpstd_ReqIndex;
        usb_gpstd_ReqReg.ReqLength      = usb_gpstd_ReqLength;
        (*usb_gpstd_Driver.ctrltrans)(ptr, (USB_REQUEST_t *)&usb_gpstd_ReqReg, (uint16_t)USB_NO_ARG);
    }
    else
    {
        /* Set pipe USB_PID_STALL */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_GetDescriptor1
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_GetConfiguration1
Description     : Analyze a Get Configuration command and process it.
                : (for control read data stage)
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_GetConfiguration1(USB_UTR_t *ptr)
{
    static uint8_t    tbl[2];

    /* check request */
    if( (((usb_gpstd_ReqTypeRecip == USB_DEVICE) 
        && (usb_gpstd_ReqValue == 0)) 
        && (usb_gpstd_ReqIndex == 0)) 
        && (usb_gpstd_ReqLength == 1) )
    {
        tbl[0] = (uint8_t)usb_gpstd_ConfigNum;
        /* Control read start */
        usb_pstd_ControlRead(ptr, (uint32_t)1, tbl);
    }
    else
    {
        /* Set pipe USB_PID_STALL */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_GetConfiguration1
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_GetInterface1
Description     : Analyze a Get Interface command and process it.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_GetInterface1(USB_UTR_t *ptr)
{
    static uint8_t    tbl[2];

    /* check request */
    if( ((usb_gpstd_ReqTypeRecip == USB_INTERFACE) && (usb_gpstd_ReqValue == 0)) && (usb_gpstd_ReqLength == 1) )
    {
        if( usb_gpstd_ReqIndex < USB_ALT_NO )
        {
            tbl[0] = (uint8_t)usb_gpstd_AltNum[usb_gpstd_ReqIndex];
            /* Start control read */
            usb_pstd_ControlRead(ptr, (uint32_t)1, tbl);
        }
        else
        {
            /* Request error */
            usb_pstd_SetStallPipe0( ptr );
        }
    }
    else
    {
        /* Request error */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_GetInterface1
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_ClearFeature0
Description     : Clear Feature0
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_ClearFeature0(void)
{
}
/******************************************************************************
End of function usb_pstd_ClearFeature0
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_ClearFeature3
Description     : Analyze a Clear Feature command and process it.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_ClearFeature3(USB_UTR_t *ptr)
{
    uint16_t        pipe;
    uint16_t        ep;

    if( usb_gpstd_ReqLength == 0 )
    {
        /* check request type */
        switch( usb_gpstd_ReqTypeRecip )
        {
            case USB_DEVICE:
                if( (usb_gpstd_ReqValue == USB_DEV_REMOTE_WAKEUP)
                    && (usb_gpstd_ReqIndex == 0) )
                {
                    if( usb_pstd_ChkRemote() == USB_YES )
                    {
                        usb_gpstd_RemoteWakeup = USB_NO;
                        /* Set pipe PID_BUF */
                        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                    }
                    else
                    {
                        /* Not support remote wakeup */
                        /* Request error */
                        usb_pstd_SetStallPipe0( ptr );
                    }
                }
                else
                {
                    /* Not specification */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            case USB_INTERFACE:
                /* Request error */
                usb_pstd_SetStallPipe0( ptr );
            break;
            case USB_ENDPOINT:
                /* Endpoint number */
                ep = (uint16_t)(usb_gpstd_ReqIndex & USB_EPNUMFIELD);
                if( usb_gpstd_ReqValue == USB_ENDPOINT_HALT )
                {
                    /* EP0 */
                    if( ep == 0 )
                    {
                        /* Stall clear */
                        usb_cstd_ClrStall(ptr, (uint16_t)USB_PIPE0);
                        /* Set pipe PID_BUF */
                        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                    }
                    /* EP1 to max */
                    else if( ep <= USB_MAX_EP_NO )
                    {
                        pipe = usb_cstd_Epadr2Pipe(ptr, usb_gpstd_ReqIndex);
                        if( pipe == USB_ERROR )
                        {
                            /* Request error */
                            usb_pstd_SetStallPipe0( ptr );
                        }
                        else
                        {
                            if( usb_cstd_GetPid(ptr, pipe) == USB_PID_BUF )
                            {
                                usb_cstd_SetNak(ptr, pipe);
                                /* SQCLR=1 */
                                usb_creg_set_sqclr(ptr, pipe);
                                /* Set pipe PID_BUF */
                                usb_cstd_SetBuf(ptr, pipe);
                            }
                            else
                            {
                                usb_cstd_ClrStall(ptr, pipe);
                                /* SQCLR=1 */
                                usb_creg_set_sqclr(ptr, pipe);
                            }
                            /* Set pipe PID_BUF */
                            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                            if( usb_gpstd_StallPipe[pipe] == USB_YES )
                            {
                                usb_gpstd_StallPipe[pipe] = USB_DONE;
                                (*usb_gpstd_StallCB)(ptr, pipe, (uint16_t)0);
                            }
                        }
                    }
                    else
                    {
                        /* Request error */
                        usb_pstd_SetStallPipe0( ptr );
                    }
                }
                else
                {
                    /* Request error */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;
            default:
                usb_pstd_SetStallPipe0( ptr );
            break;
        }
    }
    else
    {
        /* Not specification */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_ClearFeature3
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetFeature0
Description     : Set Feature0 (for idle/setup stage)
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_SetFeature0(void)
{
}
/******************************************************************************
End of function usb_pstd_SetFeature0
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetFeature3
Description     : Analyze a Set Feature command and process it.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetFeature3(USB_UTR_t *ptr)
{
    uint16_t    pipe;
    uint16_t    ep;

    if( usb_gpstd_ReqLength == 0 )
    {
        /* check request type */
        switch( usb_gpstd_ReqTypeRecip )
        {
            case USB_DEVICE:
                switch( usb_gpstd_ReqValue )
                {
                    case USB_DEV_REMOTE_WAKEUP:
                        if( usb_gpstd_ReqIndex == 0 )
                        {
                            if( usb_pstd_ChkRemote() == USB_YES )
                            {
                                usb_gpstd_RemoteWakeup = USB_YES;
                                /* Set pipe PID_BUF */
                                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                            }
                            else
                            {
                                /* Not support remote wakeup */
                                /* Request error */
                                usb_pstd_SetStallPipe0( ptr );
                            }
                        }
                        else
                        {
                            /* Not specification */
                            usb_pstd_SetStallPipe0( ptr );
                        }
                    break;

#if USB_TARGET_CHIP_PP == USB_ASSP_PP
  #if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
                    case USB_TEST_MODE:
                        if( usb_cstd_PortSpeed(ptr, (uint16_t)USB_PORT0) == USB_HSCONNECT )
                        {
                            if( (usb_gpstd_ReqIndex < USB_TEST_RESERVED) || (USB_TEST_VSTMODES <= usb_gpstd_ReqIndex) )
                            {
                                usb_gpstd_TestModeFlag = USB_YES;
                                usb_gpstd_TestModeSelect = usb_gpstd_ReqIndex;
                                /* Set pipe PID_BUF */
                                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                            }
                            else
                            {
                                /* Not specification */
                                usb_pstd_SetStallPipe0( ptr );
                            }
                        }
                        else
                        {
                            /* Not specification */
                            usb_pstd_SetStallPipe0( ptr );
                        }
                    break;
  #endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */
#endif  /* USB_TARGET_CHIP_PP == USB_ASSP_PP */

                    default:
                        usb_pstd_SetFeatureFunction(ptr);
                    break;
                }
            break;
            case USB_INTERFACE:
                /* Set pipe USB_PID_STALL */
                usb_pstd_SetStallPipe0( ptr );
            break;
            case USB_ENDPOINT:
                /* Endpoint number */
                ep = (uint16_t)(usb_gpstd_ReqIndex & USB_EPNUMFIELD);
                if( usb_gpstd_ReqValue == USB_ENDPOINT_HALT )
                {
                    /* EP0 */
                    if( ep == 0 )
                    {
                        /* Set pipe PID_BUF */
                        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                    }
                    /* EP1 to max */
                    else if( ep <= USB_MAX_EP_NO )
                    {
                        pipe = usb_cstd_Epadr2Pipe(ptr, usb_gpstd_ReqIndex);
                        if( pipe == USB_ERROR )
                        {
                            /* Request error */
                            usb_pstd_SetStallPipe0( ptr );
                        }
                        else
                        {
                            /* Set pipe USB_PID_STALL */
                            usb_pstd_SetStall(ptr, pipe);
                            /* Set pipe PID_BUF */
                            usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                        }
                    }
                    else
                    {
                        /* Request error */
                        usb_pstd_SetStallPipe0( ptr );
                    }
                }
                else
                {
                    /* Not specification */
                    usb_pstd_SetStallPipe0( ptr );
                }
            break;

            default:
                /* Request error */
                usb_pstd_SetStallPipe0( ptr );
            break;
        }
    }
    else
    {
        /* Request error */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_SetFeature3
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetAddress0
Description     : Set Address0 (for idle/setup stage).
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_SetAddress0(void)
{
}
/******************************************************************************
End of function usb_pstd_SetAddress0
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetAddress3
Description     : Analyze a Set Address command and process it.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetAddress3(USB_UTR_t *ptr)
{
    if( usb_gpstd_ReqTypeRecip == USB_DEVICE )
    {
        if( (usb_gpstd_ReqIndex == 0) && (usb_gpstd_ReqLength == 0) )
        {
            if( usb_gpstd_ReqValue <= 127 )
            {
                /* Set pipe PID_BUF */
                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
            }
            else
            {
                /* Not specification */
                usb_pstd_SetStallPipe0( ptr );
            }
        }
        else
        {
            /* Not specification */
            usb_pstd_SetStallPipe0( ptr );
        }
    }
    else
    {
        /* Request error */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_SetAddress3
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetDescriptor2
Description     : Return STALL in response to a Set Descriptor command.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetDescriptor2(USB_UTR_t *ptr)
{
    /* Not specification */
    usb_pstd_SetStallPipe0( ptr );
}
/******************************************************************************
End of function usb_pstd_SetDescriptor2
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_SetConfiguration0
Description     : Call callback function to notify the reception of SetConfiguration command
                : (for idle /setup stage)
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetConfiguration0(USB_UTR_t *ptr)
{
    uint16_t config_num;

    config_num = usb_gpstd_ConfigNum;

    /* Configuration number set */
    usb_pstd_SetConfigNum(usb_gpstd_ReqValue);

    if( usb_gpstd_ReqValue != config_num )
    {
        /* Registration open function call */
        (*usb_gpstd_Driver.devconfig)(ptr, usb_gpstd_ConfigNum, (uint16_t)USB_NO_ARG);
    }
}
/******************************************************************************
End of function usb_pstd_SetConfiguration0
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetConfiguration3
Description     : Analyze a Set Configuration command and process it. This is
                : for the status stage of a control write where there is no data
                : stage.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetConfiguration3(USB_UTR_t *ptr)
{
    uint16_t    i, j;
    uint16_t    ifc, cfgnum, cfgok;
    uint16_t    *table;
    uint8_t     *table2;

    if( usb_gpstd_ReqTypeRecip == USB_DEVICE )
    {
        cfgnum  = usb_pstd_GetConfigNum();
        cfgok   = USB_NG;

        for ( j = 0; j < cfgnum; j++ )
        {
            table2 = usb_gpstd_Driver.configtbl[j];

            if( (((usb_gpstd_ReqValue == table2[5]) || (usb_gpstd_ReqValue == 0))
                && (usb_gpstd_ReqIndex == 0)) && (usb_gpstd_ReqLength == 0) )
            {
                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                cfgok    = USB_OK;

                if( ( usb_gpstd_ReqValue > 0 ) && ( usb_gpstd_ReqValue != usb_gpstd_ConfigNum ) )
                {
                    usb_pstd_ClearEpTblIndex();
                    ifc = usb_pstd_GetInterfaceNum(usb_gpstd_ReqValue);
                    for( i = 0; i < ifc; ++i )
                    {
                        /* Pipe Information Table ("endpoint table") initialize */
                        usb_pstd_SetEpTblIndex(usb_gpstd_ReqValue, i, (uint16_t)0);
                    }
                    table = usb_gpstd_Driver.pipetbl[usb_gpstd_ReqValue - 1];
                    /* Clear pipe configuration register */
                    usb_pstd_SetPipeRegister(ptr, (uint16_t)USB_CLRPIPE, table);
                    /* Set pipe configuration register */
                    usb_pstd_SetPipeRegister(ptr, (uint16_t)USB_PERIPIPE, table);
                }
                break;
            }
        }
        if( cfgok == USB_NG )
        {
            /* Request error */
            usb_pstd_SetStallPipe0( ptr );
        }
    }
    else
    {
        /* Request error */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_SetConfiguration3
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetInterface0
Description     : Call callback function to notify reception of SetInterface com-
                : mand. For idle/setup stage.
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pstd_SetInterface0(USB_UTR_t *ptr)
{
    /* Interfaced change function call */
    (*usb_gpstd_Driver.interface)(ptr, usb_gpstd_AltNum[usb_gpstd_ReqIndex], (uint16_t)USB_NO_ARG);
}
/******************************************************************************
End of function usb_pstd_SetInterface0
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SetInterface3
Description     : Analyze a Set Interface command and request the process for 
                : the command. This is for a status stage of a control write 
                : where there is no data stage.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_SetInterface3(USB_UTR_t *ptr)
{
    uint16_t    *table;
    uint16_t    conf;

    conf = usb_gpstd_ConfigNum;
    if( conf < (uint16_t)1 )
    {
        /* Address state */
        conf = (uint16_t)1;
    }

    /* Configured ? */
    if( (usb_pstd_ChkConfigured(ptr) == USB_YES) 
        && (usb_gpstd_ReqTypeRecip == USB_INTERFACE) )
    {
        if( (usb_gpstd_ReqIndex <= usb_pstd_GetInterfaceNum(usb_gpstd_ConfigNum)) && (usb_gpstd_ReqLength == 0) )
        {
            if( usb_gpstd_ReqValue <= usb_pstd_GetAlternateNum(usb_gpstd_ConfigNum, usb_gpstd_ReqIndex) )
            {
                usb_gpstd_AltNum[usb_gpstd_ReqIndex] = (uint16_t)(usb_gpstd_ReqValue & USB_ALT_SET);
                usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);
                usb_pstd_ClearEpTblIndex();
                /* Search endpoint setting */
                usb_pstd_SetEpTblIndex(usb_gpstd_ConfigNum, usb_gpstd_ReqIndex, usb_gpstd_AltNum[usb_gpstd_ReqIndex]);
                table = usb_gpstd_Driver.pipetbl[conf - 1];
                /* Set pipe configuration register */
                usb_pstd_SetPipeRegister(ptr, (uint16_t)USB_PERIPIPE, table);
            }
            else
            {
                /* Request error */
                usb_pstd_SetStallPipe0( ptr );
            }
        }
        else
        {
            /* Request error */
            usb_pstd_SetStallPipe0( ptr );
        }
    }
    else
    {
        /* Request error */
        usb_pstd_SetStallPipe0( ptr );
    }
}
/******************************************************************************
End of function usb_pstd_SetInterface3
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_SynchFrame1
Description     : Return STALL response to SynchFrame command.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pstd_SynchFrame1(USB_UTR_t *ptr)
{
    /* Set pipe USB_PID_STALL */
    usb_pstd_SetStallPipe0( ptr );
}
/******************************************************************************
End of function usb_pstd_SynchFrame1
******************************************************************************/



/******************************************************************************
Function Name   : usb_cstd_ClassTransResult
Description     : send message
Arguments       : USB_UTR_t *mess    : USB system internal message.
Return value    : none
******************************************************************************/
void usb_cstd_ClassTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2)
{
}
/******************************************************************************
End of function usb_cstd_ClassTransResult
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_ClassTransWaitTmo
Description     : receive message
Arguments       : uint16_t tmo              : time out
Return value    : uint16_t                  : status
******************************************************************************/
uint16_t usb_cstd_ClassTransWaitTmo(uint16_t tmo)
{
    return USB_E_OK;
}
/******************************************************************************
End of function usb_cstd_ClassTransWaitTmo
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_ClassProcessResult
Description     : callback function
Arguments       : uint16_t data             : status
                : uint16_t dummy            : not use
Return value    : none
******************************************************************************/
void usb_cstd_ClassProcessResult(USB_UTR_t *ptr, uint16_t data, uint16_t dummy)
{
}
/******************************************************************************
End of function usb_cstd_ClassProcessResult
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_ClassProcessWaitTmo
Description     : receive message
Arguments       : uint16_t tmo              : time out
Return value    : uint16_t                  : status
******************************************************************************/
uint16_t usb_cstd_ClassProcessWaitTmo(uint16_t tmo)
{
    return USB_E_OK;
}
/******************************************************************************
End of function usb_cstd_ClassProcessWaitTmo
******************************************************************************/

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP

/******************************************************************************
Function Name   : usb_GetFileNumber
Description     : Search usb_FileNumberInfo for a vacant number for management.
                : Return the file number. The index is later used for storing 
                : the return value of the open function.
Argument        : NONE
Return          : FileNumber / -1(NG)
******************************************************************************/
static  uint16_t    usb_GetFileNumber( void )
{
    uint16_t    cnt, is_found;

    /* Loop to search the Empty File Number */
    for( cnt = 0, is_found = USB_NO; (cnt < USB_MAX_FILENUMBER) && (is_found == USB_NO); cnt++ )
    {
        /* Found the Empty File Number */
        if( (usb_FileNumberInfo & (1 << cnt)) == 0 )
        {
            is_found = USB_YES;
        }
    }

    return (cnt - 1);
}
/******************************************************************************
End of function usb_GetFileNumber
******************************************************************************/

/******************************************************************************
Function Name   : usb_SetFileNumber
Description     : For management to update usb_FileNumberInfo with the specified
                : one in use.
Argument        : uint16_t fn :  FileNumber
Return          : none
******************************************************************************/
static  void    usb_SetFileNumber( uint16_t fn )
{
    /* Setting the File Number under using */
    usb_FileNumberInfo |= (1 << fn);
}
/******************************************************************************
End of function usb_SetFileNumber
******************************************************************************/

/******************************************************************************
Function Name   : usb_ReleaseFileNumber
Description     : Release specified file number.
Argument        : uint16_t   fn    : File number.
Return          : void
******************************************************************************/
static  void    usb_ReleaseFileNumber( uint16_t fn )
{
    /* Release the File Number */
    usb_FileNumberInfo &= ~(1 << fn);
}
/******************************************************************************
End of function usb_ReleaseFileNumber
******************************************************************************/

/******************************************************************************
Function Name   : usb_open
Description     : Based on the specified class code, call the corresponding 
                : class' open function.
Argument        : USB_CLASS_ENUM_t    class   : Class code
Return          : FileNumber / -1(NG)
******************************************************************************/
int16_t usb_open( USB_CLASS_ENUM_t class )
{
    uint16_t    err;
    uint16_t    fn;

    err = USB_NG;

    /* Getting the empty File Number */
    fn  = usb_GetFileNumber();

    /* Setting the File Number under using */
    usb_SetFileNumber( fn );

    /* Calling open() function that correspond to each mode after checking Host/Peripheral mode */
    if( class & USB_CLASS_PERI_MODE )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        /* Calling open() function for Peripheral mode */
        err = usb_open_peri( class, fn );
#endif
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        /* Calling open() function for Host mode */
        err = usb_open_host( class, fn );
#endif
    }

    /* Checking the return from open() */
    if( USB_OK == err )
    {
//      usb_SetFileNumber( fn );
        return fn;
    }
    else
    {
        /* Release the File Number */
        usb_ReleaseFileNumber( fn );
    }
    return (int16_t)-1;
}
/******************************************************************************
End of function usb_open
******************************************************************************/

/******************************************************************************
Function Name   : usb_close
Description     : Release specified file number which was taken when open was 
                : called.
Argument        : uint16_t   fn        : FileNumber
Return          : 0(OK) / -1(NG)
******************************************************************************/
int16_t usb_close( int16_t fn )
{
    uint16_t err;

    /* Checking whether close() function is registered in usb_funInfo[](structure) variable or not */
    if( USB_NULL != usb_fnInfo[fn].close_func )
    {
        /* Calling close() function for the class */
        err = (usb_fnInfo[fn].close_func)( fn );

        /* Checking the return from close() function for the class */
        if( USB_NG == err )
        {
            return (int16_t)-1;
        }

        /* Setting the File Number under using */
        usb_ReleaseFileNumber( fn );
        return (int16_t)0;
    }
    else
    {
        /* The processing of close() for the class is NG because close() for the class is not registered */
        return (int16_t)-1;
    }
}
/******************************************************************************
End of function usb_close
******************************************************************************/


/******************************************************************************
Function Name   : usb_read
Description     : Receive data for corresponding class.
Argument        : int16_t    fn        : File number
                : void       *buf      : Start address of buffer to store data.
                : uint32_t   length    : Read data length.
Return          : none
******************************************************************************/
int32_t usb_read( int16_t fn, void *buf, uint32_t   length )
{
    int32_t read_len = -1;

    /* Checking whether the class that correspond to the File Number is opened or not */
    if( USB_NO == usb_fnInfo[fn].isOpened )
    {
        /* Return -1(NG) if the class is not opened */
        return -1;
    }

    /*  Checking whether read() function that correspond to the FileNumber is registered 
        in usb_fnInfo[](structure) variable or not */
    if( USB_NULL != usb_fnInfo[fn].class_read )
    {
        /* Calling read() function for the class */
        read_len = usb_fnInfo[fn].class_read( fn, buf, length );
    }
    return read_len;
}
/******************************************************************************
End of function usb_read
******************************************************************************/

/******************************************************************************
Function Name   : usb_write
Description     : Send data for corresponding class.
Argument        : uint16_t   fn        : File number
                : void       *buf      : Top address of buffer to store data.
                : uint32_t   length    : Write data length.
Return          : none
******************************************************************************/
int32_t usb_write( int16_t fn, void *buf, uint32_t  length )
{
    int32_t     write_len = -1;

    /* Checking whether the class that correspond to the File Number is opened or not */
    if( USB_NO == usb_fnInfo[fn].isOpened )
    {
        /* Return -1(NG) if the class is not opened */
        return (int16_t)-1;
    }

    /*  Checking whether write() function that correspond to the FileNumber is registered 
        in usb_fnInfo[](structure) variable or not */
    if( USB_NULL != usb_fnInfo[fn].class_write )
    {
        /* Calling write() function for the class */
        write_len = usb_fnInfo[fn].class_write( fn, buf, length );
    }
    return write_len;
}
/******************************************************************************
End of function usb_write
******************************************************************************/

/******************************************************************************
Function Name   : usb_control
Description     : Process specified (2nd argument) CTRL code.
Argument        : uint16_t   fn        : File number.
                : CTRLCODE   code      : Cotrol code.
                : void       *data     : Pointer of data.
Return          : int16_t   OK(0)/NG(-1)
******************************************************************************/
int16_t usb_control( int16_t fn, USB_CTRLCODE_t code, void *data )
{
    int16_t                 ret_code = 0;
    USB_UTR_t               utr;
    USB_UTR_t               *ptr;
    USB_CTL_PARAMETER_t     *parameter;
    USB_FNINFO_t            *p_fn_info;

    /* Setting USB IP number and USB IP base address that correspond to the FileNumber */
    p_fn_info = &usb_fnInfo[fn];
    ptr = (USB_UTR_t*)&utr;
    utr.ip = p_fn_info->usb_ip;
    utr.ipp = p_fn_info->usb_ipp;

    /* Convert the type of the input parameter for control */
    parameter = (USB_CTL_PARAMETER_t*)data;

    /* Checking the control code */
    switch( code )
    {
        case    USB_CTL_USBIP_NUM:
            /* Store the number of USB IP */
            *(uint16_t *)data = p_fn_info->usb_ip;
        break;

        case    USB_CTL_RD_NOTIFY_SET:
            /* Setting the call-back function is called when read() function completes */
            p_fn_info->read_complete = (USB_CB_t)data;
        break;

        case    USB_CTL_WR_NOTIFY_SET:
            /* Setting the call-back function is called when write() function completes */
            p_fn_info->write_complete = (USB_CB_t)data;
        break;

        case    USB_CTL_RD_LENGTH_GET:
            /* Getting the received data length by read() function */
            *(int32_t*)data = p_fn_info->read_length;
        break;

        case    USB_CTL_WR_LENGTH_GET:
            /* Getting the sent data length by write() function */
            *(int32_t*)data = p_fn_info->write_length;
        break;

        case    USB_CTL_GET_OPEN_STATE:
            /* Getting the open state */
            *(int16_t*)data = p_fn_info->open_state;
        break;

        case    USB_CTL_GET_RD_STATE:
            /* Getting the read state */
            *(int16_t*)data = p_fn_info->read_state;
        break;

        case    USB_CTL_GET_WR_STATE:
            /* Getting the write state */
            *(int16_t*)data = p_fn_info->write_state;
        break;

#ifdef  USB_HOST_MODE_PP
        case    USB_CTL_H_RD_TRANSFER_END:
            /* Forcibly termination processing for read() function */
            ret_code = R_usb_hstd_TransferEnd(ptr, p_fn_info->inPipeNo,
                parameter->transfer_end.status);
        break;

        case    USB_CTL_H_WR_TRANSFER_END:
            /* Forcibly termination processing for write() function */
            ret_code = R_usb_hstd_TransferEnd(ptr, p_fn_info->outPipeNo,
                parameter->transfer_end.status);
        break;

        case    USB_CTL_H_CHG_DEVICE_STATE:
            /* Changing the USB device state */
            ret_code = R_usb_hstd_MgrChangeDeviceState(ptr, parameter->device_state.complete,
                parameter->device_state.msginfo, parameter->device_state.devaddr);

        break;

        case    USB_CTL_H_GET_DEVICE_INFO:
            /* Getting the USB device information */
            R_usb_hstd_DeviceInformation(ptr, usb_devInfo[p_fn_info->devno].devadr,
                parameter->device_information.tbl);
        break;
#endif  /* USB_HOST_MODE_PP */


#ifdef  USB_PERI_MODE_PP
        case    USB_CTL_P_RD_TRANSFER_END:
            /* Forcibly termination processing for read() function */
            ret_code = R_usb_pstd_TransferEnd(ptr, p_fn_info->outPipeNo,
                parameter->transfer_end.status);
        break;

        case    USB_CTL_P_WR_TRANSFER_END:
            /* Forcibly termination processing for write() function */
            ret_code = R_usb_pstd_TransferEnd(ptr, p_fn_info->inPipeNo,
                parameter->transfer_end.status);
        break;

        case    USB_CTL_P_CHG_DEVICE_STATE:
            /* Changing the USB device state */
            ret_code = R_usb_pstd_PcdChangeDeviceState(ptr, parameter->device_state.msginfo,
                (uint16_t)0, parameter->device_state.complete);
        break;

        case    USB_CTL_P_GET_DEVICE_INFO:
            /* Getting the USB device information */
            R_usb_pstd_DeviceInformation(ptr, parameter->device_information.tbl);
        break;

        case    USB_CTL_P_RD_SET_STALL:
            /* Setting the pipe stall for read() processing */
            if( parameter->setstall.complete == NULL )
            {
                R_usb_pstd_SetPipeStall(ptr, p_fn_info->outPipeNo);
            }
            else
            {
                R_usb_pstd_SetStall(ptr, parameter->setstall.complete, p_fn_info->outPipeNo);
            }
        break;

        case    USB_CTL_P_WR_SET_STALL:
            /* Setting the pipe stall for write() processing */
            if( parameter->setstall.complete == NULL )
            {
                /* when the call-back function is not set */
                R_usb_pstd_SetPipeStall(ptr, p_fn_info->inPipeNo);
            }
            else
            {
                /* when the call-back function is set */
                R_usb_pstd_SetStall(ptr, parameter->setstall.complete, p_fn_info->inPipeNo);
            }
        break;
#endif  /* USB_PERI_MODE_PP */

        case    USB_CTL_CLASS_REQUEST:
            ret_code = usb_control_class_request(data);
        break;

        default:
            /* Setting the error(-1) because the control code does not exist */
            ret_code = -1;                  /* Cotrol Code error */
        break;
    }
    return ret_code;
}
/******************************************************************************
End of function usb_control
******************************************************************************/

/******************************************************************************
Function Name   : usb_open_peri
Description     : Call the open function of the specified class, and write to the 
                : usn_fnInfo structure accordingly.
Argument        : USB_CLASS_ENUM_t class   : Class code.
                : int16_t          fn      : File number.
Return          : uint16_t                 : USB_OK (success) / USB_NG (failure).
******************************************************************************/
uint16_t    usb_open_peri( USB_CLASS_ENUM_t class, int16_t fn )
{
    uint16_t    idx, isopened;
    struct      usb_fninfo fnstr;
    USB_UTR_t   utr;

    /* Class Index set */
    idx = (uint8_t)( class - USB_CLASS_PERI_MODE);
    utr.keyword = class;

    /* Calling open function of the class specified by 1st argument(class) */
    isopened = (*usb_classopen[idx])( (USB_UTR_t *)&utr, &fnstr, 0, 0 );

    /* Checking the completion of open() function */
    if( USB_OK == isopened )
    {
        /* Setting the information is gotten by open processing to usb_fnInfo(structure) variable */
        usb_fnInfo[fn]  = fnstr;

        return USB_OK;
    }

    return USB_NG;
} /* eof usb_open_peri */

/******************************************************************************
Function Name   : usb_close_peri
Description     : Clear the usb_fninfo structure.
Argument        : int16_t    fn   : File number.
Return          : uint16_t        : USB_OK (success) / USB_NG (failure).
******************************************************************************/
uint16_t    usb_close_peri( int16_t fn )
{
    /* Clear usb_fnInfo[fn](structure) variable */
    usb_fnInfo[fn].inPipeNo = USB_NOPIPE;
    usb_fnInfo[fn].outPipeNo = USB_NOPIPE;

//  usb_shstd_classErrorInfo = ;
    return USB_OK;
} /* eof usb_close_peri */

#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */


/******************************************************************************
Function Name   : usb_cstd_SendStart
Description     : Start data transmission using CPU/DMA transfer to USB host/
                : /device.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe no.
Return value    : none
******************************************************************************/
void usb_cstd_SendStart(USB_UTR_t *ptr, uint16_t pipe)
{
    USB_UTR_t       *pp;
    uint32_t        length;
    uint16_t        useport;

    /* Evacuation pointer */
    pp = usb_gcstd_Pipe[ptr->ip][pipe];
    length  = pp->tranlen;

    /* Check transfer count */
    if( pp->segment == USB_TRAN_CONT )
    {
        /* Sequence toggle */
        usb_cstd_DoSqtgl(ptr, pipe, pp->pipectr);
    }

    /* Select NAK */
    usb_cstd_SelectNak(ptr, pipe);
    /* Set data count */
    usb_gcstd_DataCnt[ptr->ip][pipe] = length;
    /* Set data pointer */
    usb_gcstd_DataPtr[ptr->ip][pipe] = (uint8_t*)pp->tranadr;
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    /* Ignore count clear */
    usb_ghstd_IgnoreCnt[ptr->ip][pipe] = (uint16_t)0;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

    /* BEMP Status Clear */
    usb_creg_clr_sts_bemp( ptr, pipe );
    /* BRDY Status Clear */
    usb_creg_clr_sts_brdy( ptr, pipe );

    /* Pipe number to FIFO port select */
    useport = usb_cstd_Pipe2Fport(ptr, pipe);
    /* Check use FIFO access */
    switch( useport )
    {
    /* CFIFO use */
    case USB_CUSE:
        /* Buffer to FIFO data write */
        usb_cstd_Buf2Fifo(ptr, pipe, useport);
        /* Set BUF */
        usb_cstd_SetBuf(ptr, pipe);
        break;
    /* D0FIFO use */
    case USB_D0USE:
        /* D0 FIFO access is NG */
        USB_PRINTF1("### USB-ITRON is not support(SND-D0USE:pipe%d)\n", pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    /* D1FIFO use */
    case USB_D1USE:
        /* Buffer to FIFO data write */
        usb_cstd_Buf2Fifo(ptr, pipe, useport);
        /* Set BUF */
        usb_cstd_SetBuf(ptr, pipe);
        break;
    /* D0FIFO DMA */
    case USB_D0DMA:
#if USB_TARGET_CHIP_PP == USB_ASSP_PP
        /* Transfer data address check.( External I/O, SD-RAM ) */
        if( (uint32_t)usb_gcstd_DataPtr[ptr->ip][pipe] < 0x08000000 || 
            (uint32_t)usb_gcstd_DataPtr[ptr->ip][pipe] >= 0x0A000000 )
        {
            /* Access is NG */
            USB_PRINTF1("### USB-ITRON is not support(SND-else:pipe%d)\n", pipe);
            usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        }
#endif  /* USB_TARGET_CHIP_PP == USB_ASSP_PP */

        /* Setting for use PIPE number */
        usb_gcstd_Dma0Pipe[ptr->ip] = pipe;
        /* PIPE direction */
        usb_gcstd_Dma0Dir[ptr->ip]  = usb_cstd_GetPipeDir(ptr, pipe);
        /* Buffer size */
        usb_gcstd_Dma0Fifo[ptr->ip] = usb_cstd_GetBufSize(ptr, pipe);
        /* Check data count */
        if( usb_gcstd_DataCnt[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]] <= usb_gcstd_Dma0Fifo[ptr->ip] )
        {
            /* Transfer data size */
            usb_gcstd_Dma0Size[ptr->ip] = (uint16_t)usb_gcstd_DataCnt[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]];
#if USB_TARGET_CHIP_PP == USB_RX600_PP
            /* Enable Empty Interrupt */
            usb_creg_set_bempenb(ptr, usb_gcstd_Dma0Pipe[ptr->ip]);
#endif /* USB_TARGET_CHIP_PP == USB_RX600_PP */
        }
        else
        {
            /* Data size == FIFO size */
            usb_gcstd_Dma0Size[ptr->ip] = usb_gcstd_Dma0Fifo[ptr->ip];
        }

        usb_cstd_Buf2fifoStartDma( ptr, pipe, useport );

        /* Set BUF */
        usb_cstd_SetBuf(ptr, pipe);
        break;
    /* D1FIFO DMA */
    case USB_D1DMA:
        /* D1 FIFO access is NG */
        USB_PRINTF1("### USB-ITRON is not support(SND-D1DMA:pipe%d)\n", pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    default:
        /* Access is NG */
        USB_PRINTF1("### USB-ITRON is not support(SND-else:pipe%d)\n", pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    }
}
/******************************************************************************
End of function usb_cstd_SendStart
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_Buf2Fifo
Description     : Set USB registers as required to write from data buffer to USB 
                : FIFO, to have USB FIFO to write data to bus.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe     : Pipe no.
                : uint16_t useport  : Port no.
Return value    : none
******************************************************************************/
void usb_cstd_Buf2Fifo(USB_UTR_t *ptr, uint16_t pipe, uint16_t useport)
{
    uint16_t    end_flag;

    /* Disable Ready Interrupt */
    usb_creg_clr_brdyenb(ptr, pipe);
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    /* Ignore count clear */
    usb_ghstd_IgnoreCnt[ptr->ip][pipe] = (uint16_t)0;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

    end_flag = usb_cstd_write_data( ptr, pipe, useport );

    /* Check FIFO access sequence */
    switch( end_flag )
    {
    case USB_WRITING:
        /* Continue of data write */
        /* Enable Ready Interrupt */
        usb_creg_set_brdyenb(ptr, pipe);
        /* Enable Not Ready Interrupt */
        usb_cstd_NrdyEnable(ptr, pipe);
        break;
    case USB_WRITEEND:
        /* End of data write */
        /* continue */
    case USB_WRITESHRT:
        /* End of data write */
        /* Enable Empty Interrupt */
        usb_creg_set_bempenb(ptr, pipe);
        /* Enable Not Ready Interrupt */
        usb_cstd_NrdyEnable(ptr, pipe);
        break;
    case USB_FIFOERROR:
        /* FIFO access error */
        USB_PRINTF0("### FIFO access error \n");
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    default:
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    }
}
/******************************************************************************
End of function usb_cstd_Buf2Fifo
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_write_data
Description     : Switch PIPE, request the USB FIFO to write data, and manage 
                : the size of written data.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe         : Pipe no.
                : uint16_t pipemode     : CUSE/D0DMA/D1DMA
Return value    : uint16_t end_flag
******************************************************************************/
uint16_t usb_cstd_write_data(USB_UTR_t *ptr, uint16_t pipe, uint16_t pipemode )
{
    uint16_t    size, count, buffer, mxps;
    uint16_t    end_flag;

    /* Changes FIFO port by the pipe. */
    if( (pipemode == USB_CUSE) && (pipe == USB_PIPE0) )
    {
        buffer = usb_cstd_is_set_frdy(ptr, pipe, (uint16_t)USB_CUSE, (uint16_t)USB_ISEL);
    }
    else
    {
        buffer = usb_cstd_is_set_frdy(ptr, pipe, (uint16_t)pipemode, USB_NO);
    }

    /* Check error */
    if( buffer == USB_FIFOERROR )
    {
        /* FIFO access error */
        return (USB_FIFOERROR);
    }
    /* Data buffer size */
    size = usb_cstd_GetBufSize(ptr, pipe);
    /* Max Packet Size */
    mxps = usb_cstd_GetMaxPacketSize(ptr, pipe);

    /* Data size check */
    if( usb_gcstd_DataCnt[ptr->ip][pipe] <= (uint32_t)size )
    {
        count = (uint16_t)usb_gcstd_DataCnt[ptr->ip][pipe];
        /* Data count check */
        if( count == 0 )
        {
            /* Null Packet is end of write */
            end_flag = USB_WRITESHRT;
        }
        else if( (count % mxps) != 0 )
        {
            /* Short Packet is end of write */
            end_flag = USB_WRITESHRT;
        }
        else
        {
            if( pipe == USB_PIPE0 )
            {
                /* Just Send Size */
                end_flag = USB_WRITING;
            }
            else
            {
                /* Write continues */
                end_flag = USB_WRITEEND;
            }
        }
    }
    else
    {
        /* Write continues */
        end_flag = USB_WRITING;
        count = size;
    }

    usb_gcstd_DataPtr[ptr->ip][pipe] = usb_cstd_write_fifo( ptr, count, pipemode, usb_gcstd_DataPtr[ptr->ip][pipe] );

    /* Check data count to remain */
    if( usb_gcstd_DataCnt[ptr->ip][pipe] < (uint32_t)size )
    {
        /* Clear data count */
        usb_gcstd_DataCnt[ptr->ip][pipe] = (uint32_t)0u;
        /* Read CFIFOCTR */
        buffer = usb_creg_read_fifoctr( ptr, pipemode );
        /* Check BVAL */
        if( (buffer & USB_BVAL) == 0u )
        {
            /* Short Packet */
            usb_creg_set_bval( ptr, pipemode );
        }
    }
    else
    {
        /* Total data count - count */
        usb_gcstd_DataCnt[ptr->ip][pipe] -= count;
    }
    /* End or Err or Continue */
    return end_flag;
}
/******************************************************************************
End of function usb_cstd_write_data
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_ReceiveStart
Description     : Start data reception using CPU/DMA transfer to USB Host/USB
                : device.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe no.
Return value    : none
******************************************************************************/
void usb_cstd_ReceiveStart(USB_UTR_t *ptr, uint16_t pipe)
{
    USB_UTR_t       *pp;
    uint32_t        length;
    uint16_t        mxps, useport;

    /* Evacuation pointer */
    pp      = usb_gcstd_Pipe[ptr->ip][pipe];
    length  = pp->tranlen;

    /* Check transfer count */
    if( pp->segment == USB_TRAN_CONT )
    {
        /* Sequence toggle */
        usb_cstd_DoSqtgl(ptr, pipe, pp->pipectr);
    }

    /* Select NAK */
    usb_cstd_SelectNak(ptr, pipe);
    /* Set data count */
    usb_gcstd_DataCnt[ptr->ip][pipe] = length;
    /* Set data pointer */
    usb_gcstd_DataPtr[ptr->ip][pipe] = (uint8_t*)pp->tranadr;

#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    /* Ignore count clear */
    usb_ghstd_IgnoreCnt[ptr->ip][pipe] = (uint16_t)0u;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

    /* Pipe number to FIFO port select */
    useport = usb_cstd_Pipe2Fport(ptr, pipe);

    /* Check use FIFO access */
    switch( useport )
    {
    /* D0FIFO use */
    case USB_D0USE:
        /* D0 FIFO access is NG */
        USB_PRINTF1("### USB-ITRON is not support(RCV-D0USE:pipe%d)\n", pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
        
    /* CFIFO use */
    case USB_CUSE:
        /* continue */
        
    /* D1FIFO use */
    case USB_D1USE:
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, pipe, useport, USB_NO);
        /* Max Packet Size */
        mxps = usb_cstd_GetMaxPacketSize(ptr, pipe);
        if( length != (uint32_t)0u )
        {
            /* Data length check */
            if( (length % mxps) == (uint32_t)0u )
            {
                /* Set Transaction counter */
                usb_cstd_SetTransactionCounter(ptr, pipe, (uint16_t)(length / mxps));
            }
            else
            {
                /* Set Transaction counter */
                usb_cstd_SetTransactionCounter(ptr, pipe, (uint16_t)((length / mxps) + (uint32_t)1u));
            }
        }
        /* Set BUF */
        usb_cstd_SetBuf(ptr, pipe);
        /* Enable Ready Interrupt */
        usb_creg_set_brdyenb(ptr, pipe);
        /* Enable Not Ready Interrupt */
        usb_cstd_NrdyEnable(ptr, pipe);
        break;
        
    /* D0FIFO DMA */
    case USB_D0DMA:


#if USB_TARGET_CHIP_PP == USB_ASSP_PP
        /* Transfer data address check.( External I/O, SD-RAM ) */
        if( (uint32_t)usb_gcstd_DataPtr[ptr->ip][pipe] < 0x08000000 || 
            (uint32_t)usb_gcstd_DataPtr[ptr->ip][pipe] >= 0x0A000000 )
        {
            /* Access is NG */
            USB_PRINTF1("### USB-ITRON is not support(SND-else:pipe%d)\n", pipe);
            usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        }
#endif  /* USB_TARGET_CHIP_PP == USB_ASSP_PP */

        /* Setting for use PIPE number */
        usb_gcstd_Dma0Pipe[ptr->ip] = pipe;
        /* PIPE direction */
        usb_gcstd_Dma0Dir[ptr->ip]  = usb_cstd_GetPipeDir(ptr, pipe);
        /* Buffer size */
        usb_gcstd_Dma0Fifo[ptr->ip] = usb_cstd_GetBufSize(ptr, pipe);
        /* Check data count */
        if( usb_gcstd_DataCnt[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]] < usb_gcstd_Dma0Fifo[ptr->ip] )
        {
            /* Transfer data size */
            usb_gcstd_Dma0Size[ptr->ip] = (uint16_t)usb_gcstd_DataCnt[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]];
        }
        else
        {
            /* Data size == FIFO size */
            usb_gcstd_Dma0Size[ptr->ip] = usb_gcstd_Dma0Fifo[ptr->ip];
        }

        usb_cstd_Fifo2BufStartDma( ptr, pipe, useport, length );

        break;
        
    /* D1FIFO DMA */
    case USB_D1DMA:
        /* D1 FIFO access is NG */
        USB_PRINTF1("### USB-ITRON is not support(RCV-D1DMA:pipe%d)\n", pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
        
    default:
        USB_PRINTF1("### USB-ITRON is not support(RCV-else:pipe%d)\n", pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    }
}
/******************************************************************************
End of function usb_cstd_ReceiveStart
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_Fifo2Buf
Description     : Request readout from USB FIFO to buffer and process depending
                : on status; read complete or reading.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe no.
Return value    : none
******************************************************************************/
void usb_cstd_Fifo2Buf(USB_UTR_t *ptr, uint16_t pipe, uint16_t useport)
{
    uint16_t    end_flag;

#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    /* Ignore count clear */
    usb_ghstd_IgnoreCnt[ptr->ip][pipe] = (uint16_t)0;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    end_flag = USB_ERROR;

    end_flag = usb_cstd_read_data( ptr, pipe, useport );

    /* Check FIFO access sequence */
    switch( end_flag )
    {
    case USB_READING:
        /* Continue of data read */
        break;
        
    case USB_READEND:
        /* End of data read */
        usb_cstd_DataEnd(ptr, pipe, (uint16_t)USB_DATA_OK);
        break;
        
    case USB_READSHRT:
        /* End of data read */
        usb_cstd_DataEnd(ptr, pipe, (uint16_t)USB_DATA_SHT);
        break;
        
    case USB_READOVER:
        /* Buffer over */
        USB_PRINTF1("### Receive data over PIPE%d\n",pipe);
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_OVR);
        break;
        
    case USB_FIFOERROR:
        /* FIFO access error */
        USB_PRINTF0("### FIFO access error \n");
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
        
    default:
        usb_cstd_ForcedTermination(ptr, pipe, (uint16_t)USB_DATA_ERR);
        break;
    }
}
/******************************************************************************
End of function usb_cstd_Fifo2Buf
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_read_data
Description     : Request to read data from USB FIFO, and manage the size of 
                : the data read.
Arguments       : uint16_t pipe            : Pipe no.
Return value    : uint16_t end_flag
******************************************************************************/
uint16_t usb_cstd_read_data(USB_UTR_t *ptr, uint16_t pipe, uint16_t pipemode)
{
    uint16_t    count, buffer, mxps, dtln;
    uint16_t    end_flag;

    /* Changes FIFO port by the pipe. */
    buffer = usb_cstd_is_set_frdy(ptr, pipe, (uint16_t)pipemode, USB_NO);
    if( buffer == USB_FIFOERROR )
    {
        /* FIFO access error */
        return (USB_FIFOERROR);
    }
    dtln = (uint16_t)(buffer & USB_DTLN);
    /* Max Packet Size */
    mxps = usb_cstd_GetMaxPacketSize(ptr, pipe);

    if( usb_gcstd_DataCnt[ptr->ip][pipe] < dtln )
    {
        /* Buffer Over ? */
        end_flag = USB_READOVER;
        /* Set NAK */
        usb_cstd_SetNak(ptr, pipe);
        count = (uint16_t)usb_gcstd_DataCnt[ptr->ip][pipe];
        usb_gcstd_DataCnt[ptr->ip][pipe] = dtln;
    }
    else if( usb_gcstd_DataCnt[ptr->ip][pipe] == dtln )
    {
        /* Just Receive Size */
        count = dtln;
        if( (pipe == USB_PIPE0) && ((dtln % mxps) == 0) )
        {
            /* Just Receive Size */
            if( usb_cstd_is_host_mode(ptr) == USB_NO )
            {
                /* Peripheral Function */
                end_flag = USB_READING;
            }
            else
            {
                /* Host Function */
                end_flag = USB_READEND;
                /* Set NAK */
                usb_cstd_SelectNak(ptr, pipe);
            }
        }
        else
        {
            end_flag = USB_READEND;
            /* Set NAK */
            usb_cstd_SelectNak(ptr, pipe);
        }
    }
    else
    {
        /* Continus Receive data */
        count = dtln;
        end_flag = USB_READING;
        if( count == 0 )
        {
            /* Null Packet receive */
            end_flag = USB_READSHRT;
            /* Select NAK */
            usb_cstd_SelectNak(ptr, pipe);
        }
        if( (count % mxps) != 0 )
        {
            /* Null Packet receive */
            end_flag = USB_READSHRT;
            /* Select NAK */
            usb_cstd_SelectNak(ptr, pipe);
        }
    }

    if( dtln == 0 )
    {
        /* 0 length packet */
        /* Clear BVAL */
        usb_creg_set_bclr( ptr, pipemode );
    }
    else
    {
        usb_gcstd_DataPtr[ptr->ip][pipe] = usb_cstd_read_fifo( ptr, count, pipemode, usb_gcstd_DataPtr[ptr->ip][pipe] );
    }
    usb_gcstd_DataCnt[ptr->ip][pipe] -= count;

    /* End or Err or Continue */
    return (end_flag);
}
/******************************************************************************
End of function usb_cstd_read_data
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_DataEnd
Description     : Set USB registers as appropriate after data transmission/re-
                : ception, and call the callback function as transmission/recep-
                : tion is complete.
Arguments       : uint16_t pipe     : Pipe no.
                : uint16_t status   : Transfer status type.
Return value    : none
******************************************************************************/
void usb_cstd_DataEnd(USB_UTR_t *ptr, uint16_t pipe, uint16_t status)
{
    uint16_t    useport;

    /* PID = NAK */
    /* Set NAK */
    usb_cstd_SelectNak(ptr, pipe);
    /* Pipe number to FIFO port select */
    useport = usb_cstd_Pipe2Fport(ptr, pipe);

    /* Disable Interrupt */
    /* Disable Ready Interrupt */
    usb_creg_clr_brdyenb(ptr, pipe);
    /* Disable Not Ready Interrupt */
    usb_creg_clr_nrdyenb(ptr, pipe);
    /* Disable Empty Interrupt */
    usb_creg_clr_bempenb(ptr, pipe);

    /* Disable Transaction count */
    usb_cstd_ClrTransactionCounter(ptr, pipe);

    /* Check use FIFO */
    switch( useport )
    {
    /* CFIFO use */
    case USB_CUSE:
        break;
    /* D0FIFO use */
    case USB_D0USE:
        break;
    /* D0FIFO DMA */
    case USB_D0DMA:
        /* DMA buffer clear mode clear */
        usb_creg_clr_dclrm( ptr, USB_D0DMA );
        usb_creg_set_mbw( ptr, USB_D0DMA, USB_D0FIFO_MBW );
        usb_creg_write_dmacfg( ptr, USB_D0DMA, USB_CPU_ADR_RD_WR );
        break;
    /* D1FIFO use */
    case USB_D1USE:
        break;
    /* D1FIFO DMA */
    case USB_D1DMA:
        /* continue */
    default:
        break;
    }

    /* Call Back */
    if( usb_gcstd_Pipe[ptr->ip][pipe] != USB_NULL )
    {
        /* Check PIPE TYPE */
        if( usb_cstd_GetPipeType(ptr, pipe) != USB_ISO )
        {
            /* Transfer information set */
            usb_gcstd_Pipe[ptr->ip][pipe]->tranlen  = usb_gcstd_DataCnt[ptr->ip][pipe];
            usb_gcstd_Pipe[ptr->ip][pipe]->status   = status;
            usb_gcstd_Pipe[ptr->ip][pipe]->pipectr  = usb_creg_read_pipectr(ptr, pipe);
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
            usb_gcstd_Pipe[ptr->ip][pipe]->errcnt   = (uint8_t)usb_ghstd_IgnoreCnt[ptr->ip][pipe];
#else  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
            usb_gcstd_Pipe[ptr->ip][pipe]->errcnt   = 0;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

            usb_gcstd_Pipe[ptr->ip][pipe]->ipp  = ptr->ipp;
            usb_gcstd_Pipe[ptr->ip][pipe]->ip   = ptr->ip;

            (*usb_gcstd_Pipe[ptr->ip][pipe]->complete)(usb_gcstd_Pipe[ptr->ip][pipe], 0, 0);
            usb_gcstd_Pipe[ptr->ip][pipe] = (USB_UTR_t*)USB_NULL;
        }
        else
        {
            /* Transfer information set */
            usb_gcstd_Pipe[ptr->ip][pipe]->tranlen  = usb_gcstd_DataCnt[ptr->ip][pipe];
            usb_gcstd_Pipe[ptr->ip][pipe]->pipectr  = usb_creg_read_pipectr(ptr, pipe);
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
            usb_gcstd_Pipe[ptr->ip][pipe]->errcnt   = (uint8_t)usb_ghstd_IgnoreCnt[ptr->ip][pipe];
#else  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
            usb_gcstd_Pipe[ptr->ip][pipe]->errcnt   = 0;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

            usb_gcstd_Pipe[ptr->ip][pipe]->ipp  = ptr->ipp;
            usb_gcstd_Pipe[ptr->ip][pipe]->ip   = ptr->ip;

            /* Data Transfer (restart) */
            if( usb_cstd_GetPipeDir(ptr, pipe) == USB_BUF2FIFO )
            {
                /* OUT Transfer */
                usb_gcstd_Pipe[ptr->ip][pipe]->status   = USB_DATA_WRITING;
                (*usb_gcstd_Pipe[ptr->ip][pipe]->complete)(usb_gcstd_Pipe[ptr->ip][pipe], 0, 0);
            }
            else
            {
                /* IN Transfer */
                usb_gcstd_Pipe[ptr->ip][pipe]->status   = USB_DATA_READING;
                (*usb_gcstd_Pipe[ptr->ip][pipe]->complete)(usb_gcstd_Pipe[ptr->ip][pipe], 0, 0);
            }
        }
    }
}
/******************************************************************************
End of function usb_cstd_DataEnd
******************************************************************************/

/******************************************************************************
Function Name   : void usb_cstd_SelectNak(uint16_t pipe)
Description     : Set the specified pipe PID to send a NAK if the transfer type 
                : is BULK/INT. 
Arguments       : uint16_t pipe     : Pipe number.
Return value    : none
******************************************************************************/
void usb_cstd_SelectNak(USB_UTR_t *ptr, uint16_t pipe)
{
    /* Check PIPE TYPE */
    if( usb_cstd_GetPipeType(ptr, pipe) != USB_ISO )
    {
        usb_cstd_SetNak(ptr, pipe);
    }
}
/******************************************************************************
End of function usb_cstd_SelectNak
******************************************************************************/



/******************************************************************************
Function Name   : usb_cstd_BrdyPipe
Description     : Search for the PIPE No. that BRDY interrupt occurred, and 
                  request data transmission/reception from the PIPE
Arguments       : USB_UTR_t *ptr
                : uint16_t bitsts       ; BRDYSTS Register & BRDYENB Register
Return value    : none
******************************************************************************/
void usb_cstd_BrdyPipe(USB_UTR_t *ptr, uint16_t bitsts)
{
    usb_cstd_brdy_pipe(ptr,bitsts);
}
/******************************************************************************
End of function usb_cstd_BrdyPipe
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_NrdyPipe
Description     : Search for PIPE No. that occurred NRDY interrupt, and execute 
                  the process for PIPE when NRDY interrupt occurred
Arguments       : USB_UTR_t *ptr
                : uint16_t bitsts       ; NRDYSTS Register & NRDYENB Register
Return value    : none
******************************************************************************/
void usb_cstd_NrdyPipe(USB_UTR_t *ptr, uint16_t bitsts)
{
/* PERI spec                                                            */
/*  Transmitting pipe                                                   */
/* @5       a) only NRDY                                                */
/* @1       b) NRDY+OVRN    (Isochronous)                               */
/*  Receive pipe                                                        */
/* @5       a) only NRDY                                                */
/* @1       b) NRDY+OVRN    (Isochronous)                               */
/* @2       c) only NRDY    (interval error of isochronous)             */
/* HOST spec                                                            */
/*  Transmitting pipe                                                   */
/* @1       a) NRDY+OVRN    (Isochronous)                               */
/* @4       b) NRDY+NAK     (Ignore)                                    */
/* @3       c) NRDY+STALL   (Receive STALL)                             */
/*  Receive pipe                                                        */
/* @1       a) NRDY+OVRN    (Isochronous)                               */
/* @4       b) NRDY+NAK     (Ignore)                                    */
/* @2       c) NRDY         (Ignore of isochronous)                     */
/* @2       d) NRDY         (CRC error of isochronous)                  */
/* @3       e) NRDY+STALL   (Receive STALL)                             */

    uint16_t        buffer, i;

    for( i = USB_MIN_PIPE_NO; i <= USB_MAX_PIPE_NO; i++ )
    {
        if( (bitsts & USB_BITSET(i)) != 0 )
        {
            /* Interrupt check */
            if( usb_gcstd_Pipe[ptr->ip][i] != USB_NULL )
            {
                if( usb_cstd_GetPipeType(ptr, i) == USB_ISO )
                {
                    /* Wait for About 60ns */
                    buffer = usb_creg_read_frmnum( ptr );
                    if( (buffer & USB_OVRN) == USB_OVRN )
                    {
                        /* @1 */
                        /* End of data transfer */
                        usb_cstd_ForcedTermination(ptr, i, (uint16_t)USB_DATA_OVR);
                        USB_PRINTF1("###ISO OVRN %d\n", usb_gcstd_DataCnt[ptr->ip][i]);
                    }
                    else
                    {
                        /* @2 */
                        /* End of data transfer */
                        usb_cstd_ForcedTermination(ptr, i, (uint16_t)USB_DATA_ERR);
                    }
                }
                else
                {
                    usb_cstd_nrdy_endprocess( ptr, i );
                }
            }
        }
    }
}
/******************************************************************************
End of function usb_cstd_NrdyPipe
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_BempPipe
Description     : Search for PIPE No. that BEMP interrupt occurred, and complete data transmission for the PIPE
Arguments       : USB_UTR_t *ptr
                : uint16_t bitsts       ; BEMPSTS Register & BEMPENB Register
Return value    : none
******************************************************************************/
void usb_cstd_BempPipe(USB_UTR_t *ptr, uint16_t bitsts)
{
    uint16_t        buffer, i;
    uint16_t        useport;

    for( i = USB_MIN_PIPE_NO; i <= USB_PIPE5; i++ )
    {
        if( (bitsts & USB_BITSET(i)) != 0 )
        {
            /* Interrupt check */
            if( usb_gcstd_Pipe[ptr->ip][i] != USB_NULL )
            {
                buffer = usb_cstd_GetPid(ptr, i);
                /* MAX packet size error ? */
                if( (buffer & USB_PID_STALL) == USB_PID_STALL )
                {
                    USB_PRINTF1("### STALL Pipe %d\n", i);
                    usb_cstd_ForcedTermination(ptr, i, (uint16_t)USB_DATA_STALL);
                }
                else
                {
                    if( (usb_creg_read_pipectr( ptr, i ) & USB_INBUFM) != USB_INBUFM )
                    {
                        /* Pipe number to FIFO port select */
                        useport = usb_cstd_Pipe2Fport(ptr, i);
                        if( useport == USB_D0DMA )
                        {
#if USB_TARGET_CHIP_PP == USB_RX600_PP
                            usb_creg_clr_dreqe( ptr, USB_D0DMA );
                            /* DMA stop */
                            usb_cpu_d0fifo_stop_dma(ptr);
#endif /* USB_TARGET_CHIP_PP == USB_RX600_PP */
                            usb_creg_clr_sts_bemp( ptr, i );
                        }
                        /* End of data transfer */
                        usb_cstd_DataEnd(ptr, i, (uint16_t)USB_DATA_NONE);
                    }
                }
            }
        }
    }
    for( i = USB_PIPE6; i <= USB_MAX_PIPE_NO; i++ )
    {
        /* Interrupt check */
        if( (bitsts & USB_BITSET(i)) != 0 )
        {
            if( usb_gcstd_Pipe[ptr->ip][i] != USB_NULL )
            {
                buffer = usb_cstd_GetPid(ptr, i);
                /* MAX packet size error ? */
                if( (buffer & USB_PID_STALL) == USB_PID_STALL )
                {
                    USB_PRINTF1("### STALL Pipe %d\n", i);
                    usb_cstd_ForcedTermination(ptr, i, (uint16_t)USB_DATA_STALL);
                }
                else
                {
                    /* End of data transfer */
                    usb_cstd_DataEnd(ptr, i, (uint16_t)USB_DATA_NONE);
                }
            }
        }
    }
}
/******************************************************************************
End of function usb_cstd_BempPipe
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_InitUsbMessage
Description     : Initialization of message to be used at time of USB interrupt.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t  function    : Host or peripheral mode.
Return value    : none
******************************************************************************/
void usb_cstd_InitUsbMessage(USB_UTR_t *ptr, uint16_t function)
{
    /* TD.5.4 The interruption message of PCD is notified to HCD.  */
    uint16_t        i, msg_info;

    if( function == USB_PERI )
    {
        /* Peripheral Function */
        msg_info = USB_MSG_PCD_INT;
    }
    else
    {
        /* Host Function */
        msg_info = USB_MSG_HCD_INT;
    }

    for( i = 0; i < USB_INTMSGMAX; i++ )
    {
        usb_gcstd_IntMsg[ptr->ip][i].msginfo = msg_info;
    }

    usb_gcstd_IntMsgCnt[ptr->ip] = 0;
}
/******************************************************************************
End of function usb_cstd_InitUsbMessage
******************************************************************************/

#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
/******************************************************************************
Function Name   : usb_cstd_DmaHandler
Description     : DMA interrupt routine. Send message to PCD/HCD task.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cstd_DmaHandler(void)
{

    usb_cstd_d0fifo_handler();
}
/******************************************************************************
End of function usb_cstd_DmaHandler
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_UsbHandler
Description     : USB interrupt routine. Analyze which USB interrupt occurred 
                : and send message to PCD/HCD task.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cstd_UsbHandler(void)
{
    USB_UTR_t       *ptr;


    /* Initial pointer */
    ptr = &usb_gcstd_IntMsg[0][usb_gcstd_IntMsgCnt[0]];
    ptr->ip  = USB_USBIP_0;
    ptr->ipp = usb_cstd_GetUsbIpAdr( ptr->ip );

    usb_cstd_InterruptClock( ptr );

    /* Check Host or Peripheral */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
        USB_ER_t        err;

        /* Peripheral Function */
        /* Peripheral Interrupt handler */
        usb_pstd_InterruptHandler(ptr);
        ptr->msghead = (USB_MH_t)USB_NULL;
        /* Send message */
        err = USB_ISND_MSG(USB_PCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### lib_UsbHandler DEF1 isnd_msg error (%ld)\n", err);
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP
        USB_ER_t        err;

        /* Host Function */
        /* Host Interrupt handler */
        usb_hstd_InterruptHandler(ptr);
        ptr->msghead = (USB_MH_t)USB_NULL;
        /* Send message */
        err = USB_ISND_MSG(USB_HCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### lib_UsbHandler DEF2 isnd_msg error (%ld)\n", err);
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP */
    }

    /* Renewal Message count  */
    usb_gcstd_IntMsgCnt[0]++;
    if( usb_gcstd_IntMsgCnt[0] == USB_INTMSGMAX )
    {
        usb_gcstd_IntMsgCnt[0] = 0;
    }
}
/******************************************************************************
End of function usb_cstd_UsbHandler
******************************************************************************/

#endif  /* #if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP */


#if USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP
/******************************************************************************
Function Name   : usb2_cstd_DmaHandler
Description     : DMA interrupt routine. Send message to PCD/HCD task.
Arguments       : none
Return value    : none
******************************************************************************/

void usb2_cstd_DmaHandler(void)
{
#if USB_FUNCSEL_USBIP1_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
    usb2_cstd_d0fifo_handler();
#endif  /* USB_FUNCSEL_USBIP1_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
}
/******************************************************************************
End of function usb2_cstd_DmaHandler
******************************************************************************/

/******************************************************************************
Function Name   : usb2_cstd_UsbHandler
Description     : USB2 interrupt routine. Analyze which USB interrupt occurred 
                : and send message to PCD/HCD task.
Arguments       : none
Return value    : none
******************************************************************************/
void usb2_cstd_UsbHandler(void)
{
    USB_UTR_t       *ptr;

    /* Initial pointer */
    ptr = &usb_gcstd_IntMsg[1][usb_gcstd_IntMsgCnt[1]];
    ptr->ip  = USB_USBIP_1;
    ptr->ipp = usb_cstd_GetUsbIpAdr( ptr->ip );

    usb_cstd_InterruptClock( ptr );

    /* Check Host or Peripheral */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        USB_ER_t        err;

        /* Peripheral Function */
        /* Peripheral Interrupt handler */
        usb_pstd_InterruptHandler( ptr );
        ptr->msghead = (USB_MH_t)USB_NULL;
        /* Send message */
        err = USB_ISND_MSG(USB_PCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### lib_UsbHandler DEF1 isnd_msg error (%ld)\n", err);
        }
#endif /* USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        USB_ER_t        err;

        /* Host Function */
        /* Host Interrupt handler */
        usb_hstd_InterruptHandler( ptr );
        ptr->msghead = (USB_MH_t)USB_NULL;
        /* Send message */
        err = USB_ISND_MSG(USB_HCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### lib_UsbHandler DEF2 isnd_msg error (%ld)\n", err);
        }
#endif  /* USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }

    /* Renewal Message count  */
    usb_gcstd_IntMsgCnt[1]++;
    if( usb_gcstd_IntMsgCnt[1] == USB_INTMSGMAX )
    {
        usb_gcstd_IntMsgCnt[1] = 0;
    }
}
/******************************************************************************
End of function usb2_cstd_UsbHandler
******************************************************************************/
#endif  /* #if USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP */



/******************************************************************************
Function Name   : usb_cstd_NrdyEnable
Description     : Enable NRDY interrupt of the specified pipe.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : none
******************************************************************************/
void usb_cstd_NrdyEnable(USB_UTR_t *ptr, uint16_t pipe)
{
    /* Check current function */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
        /*  At the peripheral operation, interrupt is disabled, */
        /*  because handler becomes busy. */
    }
    else
    {
        /* Enable NRDY */
        usb_creg_set_nrdyenb( ptr, pipe );
    }
}
/******************************************************************************
End of function usb_cstd_NrdyEnable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_BerneEnable
Description     : Enable BRDY/NRDY/BEMP interrupt.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
Return value    : none
******************************************************************************/
void usb_cstd_BerneEnable(USB_UTR_t *ptr)
{
    /* Enable BEMP, NRDY, BRDY */
    usb_creg_set_intenb( ptr, (USB_BEMPE|USB_NRDYE|USB_BRDYE) );
}
/******************************************************************************
End of function usb_cstd_BerneEnable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_SwReset
Description     : Request USB IP software reset
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
Return value    : none
******************************************************************************/
void usb_cstd_SwReset(USB_UTR_t *ptr)
{
    /* USB Enable */
    usb_creg_set_usbe( ptr );
    /* USB Reset */
    usb_creg_clr_usbe( ptr );
    /* USB Enable */
    usb_creg_set_usbe( ptr );
}
/******************************************************************************
End of function usb_cstd_SwReset
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_GetPid
Description     : Fetch specified pipe's PID.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : uint16_t PID-bit status
******************************************************************************/
uint16_t usb_cstd_GetPid(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t    buf;

    /* PIPE control reg read */
    buf = usb_creg_read_pipectr( ptr, pipe );
    return (uint16_t)(buf & USB_PID);
}
/******************************************************************************
End of function usb_cstd_GetPid
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_DoSqtgl
Description     : Toggle setting of the toggle-bit for the specified pipe by 
                : argument.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe     : Pipe number.
                : uint16_t toggle   : Current toggle status.
Return value    : none
******************************************************************************/
void usb_cstd_DoSqtgl(USB_UTR_t *ptr, uint16_t pipe, uint16_t toggle)
{
    /* Check toggle */
    if( (toggle & USB_SQMON) == USB_SQMON )
    {
        /* Do pipe SQSET */
        usb_creg_set_sqset(ptr, pipe);
    }
    else
    {
        /* Do pipe SQCLR */
        usb_creg_set_sqclr(ptr, pipe);
    }
}
/******************************************************************************
End of function usb_cstd_DoSqtgl
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_GetMaxPacketSize
Description     : Fetch MaxPacketSize of the specified pipe.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : uint16_t MaxPacketSize
******************************************************************************/
uint16_t usb_cstd_GetMaxPacketSize(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t    size, buffer;

    if( pipe == USB_PIPE0 )
    {
        buffer = usb_creg_read_dcpmaxp( ptr );
    }
    else
    {
        /* Pipe select */
        usb_creg_write_pipesel( ptr, pipe );
        buffer = usb_creg_read_pipemaxp( ptr );
    }
    /* Max Packet Size */
    size = (uint16_t)(buffer & USB_MXPS);

    return size;
}
/******************************************************************************
End of function usb_cstd_GetMaxPacketSize
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_GetDevsel
Description     : 
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : uint16_t DEVSEL-bit status
******************************************************************************/
uint16_t usb_cstd_GetDevsel(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t    devsel, buffer;

    /* Check current function */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        /* Peripheral Function */
        /* USB address */
        buffer = usb_creg_read_usbaddr( ptr );
        /* Device address */
        devsel = (uint16_t)(buffer & USB_USBADDR_MASK);
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        if( pipe == USB_PIPE0 )
        {
            buffer = usb_creg_read_dcpmaxp( ptr );
        }
        else
        {
            /* Pipe select */
            usb_creg_write_pipesel( ptr, pipe );
            buffer = usb_creg_read_pipemaxp( ptr );
        }
        /* Device address */
        devsel = (uint16_t)(buffer & USB_DEVSEL);
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }

    return devsel;
}
/******************************************************************************
End of function usb_cstd_GetDevsel
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_GetPipeDir
Description     : Get PIPE DIR
Arguments       : uint16_t pipe  : Pipe number.
Return value    : uint16_t Pipe direction.
******************************************************************************/
uint16_t usb_cstd_GetPipeDir(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t        buffer;

    /* Pipe select */
    usb_creg_write_pipesel( ptr, pipe );
    /* Read Pipe direction */
    buffer = usb_creg_read_pipecfg( ptr );
    return (uint16_t)(buffer & USB_DIRFIELD);
}
/******************************************************************************
End of function usb_cstd_GetPipeDir
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_GetPipeType
Description     : Fetch and return PIPE TYPE.
Arguments       : uint16_t pipe            : Pipe number.
Return value    : uint16_t Pipe type
******************************************************************************/
uint16_t usb_cstd_GetPipeType(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t        buffer;

    /* Pipe select */
    usb_creg_write_pipesel( ptr, pipe );
    /* Read Pipe direction */
    buffer = usb_creg_read_pipecfg( ptr );
    return (uint16_t)(buffer & USB_TYPFIELD);
}
/******************************************************************************
End of function usb_cstd_GetPipeType
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_is_host_mode
Description     : Check current function
Arguments       : none
Return value    : uint16_t    : YES = Host
                :             : NO = Peripheral
******************************************************************************/
uint16_t usb_cstd_is_host_mode(USB_UTR_t *ptr)
{
    uint16_t    buf;
    buf = usb_creg_read_syscfg( ptr, USB_PORT0 );
    if( (buf & USB_DCFM) == USB_DCFM )
    {
        /* Host Function mode */
        return USB_YES;
    }
    else
    {
        /* Peripheral Function mode */
        return USB_NO;
    }
}
/******************************************************************************
End of function usb_cstd_is_host_mode
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_DoAclrm
Description     : Set the ACLRM-bit (Auto Buffer Clear Mode) of the specified 
                : pipe.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : none
******************************************************************************/
void usb_cstd_DoAclrm(USB_UTR_t *ptr, uint16_t pipe)
{
    /* Control ACLRM */
    usb_creg_set_aclrm( ptr, pipe );
    usb_creg_clr_aclrm( ptr, pipe );
}
/******************************************************************************
End of function usb_cstd_DoAclrm
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_SetBuf
Description     : Set PID (packet ID) of the specified pipe to BUF.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : none
******************************************************************************/
void usb_cstd_SetBuf(USB_UTR_t *ptr, uint16_t pipe)
{
    /* PIPE control reg set */
    usb_creg_set_pid( ptr, pipe, USB_PID_BUF );
}
/******************************************************************************
End of function usb_cstd_SetBuf
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_ClrStall
Description     : Set up to NAK the specified pipe, and clear the STALL-bit set
                : to the PID of the specified pipe.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : none
Note            : PID is set to NAK.
******************************************************************************/
void usb_cstd_ClrStall(USB_UTR_t *ptr, uint16_t pipe)
{
    /* Set NAK */
    usb_cstd_SetNak(ptr, pipe);
    /* Clear STALL */
    usb_creg_clr_pid( ptr, pipe, USB_PID_STALL );
}
/******************************************************************************
End of function usb_cstd_ClrStall
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_Epadr2Pipe
Description     : Get the associated pipe no. of the specified endpoint.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t dir_ep : Direction + endpoint number.
Return value    : uint16_t        : OK    : Pipe number.
                :                 : ERROR : Error.
******************************************************************************/
uint16_t usb_cstd_Epadr2Pipe(USB_UTR_t *ptr, uint16_t dir_ep)
{
    uint16_t        i, direp, tmp, *table;

    /* Check current function */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        uint16_t conf;

        conf = usb_gpstd_ConfigNum;
        if( conf < (uint16_t)1 )
        {
            /* Address state */
            conf = (uint16_t)1;
        }

        /* Peripheral */
        /* Get PIPE Number from Endpoint address */
        table = (uint16_t*)((uint16_t**)(usb_gpstd_Driver.pipetbl[conf - 1]));
        direp = (uint16_t)(((dir_ep & 0x80) >> 3) | (dir_ep & 0x0F));
        /* EP table loop */
        for( i = 0; table[i] != USB_PDTBLEND; i += USB_EPL )
        {
            tmp = (uint16_t)(table[i + 1] & (USB_DIRFIELD | USB_EPNUMFIELD));
            /* EP table endpoint dir check */
            if( direp == tmp )
            {
                return table[i];
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        uint16_t        md;
        USB_HCDREG_t    *driver;

        /* Host */
        /* Get PIPE Number from Endpoint address */
        for( md = 0; md < usb_ghstd_DeviceNum[ptr->ip]; md++ )
        {
            if( (usb_ghstd_DeviceDrv[ptr->ip][md].ifclass != USB_IFCLS_NOT) &&
                (usb_ghstd_DeviceDrv[ptr->ip][md].devaddr != USB_NODEVICE) )
            {
                driver = (USB_HCDREG_t*)&usb_ghstd_DeviceDrv[ptr->ip][md];
                table = (uint16_t*)(driver->pipetbl);
                direp = (uint16_t)((((dir_ep & 0x80) ^ 0x80) >> 3) | (dir_ep & 0x0F));
                /* EP table loop */
                for( i = 0; table[i] != USB_PDTBLEND; i += USB_EPL )
                {
                    tmp = (uint16_t)(table[i + 1] & (USB_DIRFIELD | USB_EPNUMFIELD));
                    /* EP table endpoint dir check */
                    if( direp == tmp )
                    {
                        return table[i];
                    }
                }
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }
    return USB_ERROR;
}
/******************************************************************************
End of function usb_cstd_Epadr2Pipe
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_Pipe2Epadr
Description     : Get the associated endpoint value of the specified pipe.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : uint8_t        : OK    : Endpoint nr + direction.
                :                : ERROR : Error.
******************************************************************************/
uint8_t usb_cstd_Pipe2Epadr(USB_UTR_t *ptr, uint16_t pipe)
{

    /* Check current function */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
        /* Peripheral */
        USB_PRINTF0("Not support peripheral function\n");
        return (uint8_t)USB_ERROR;
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        USB_HCDREG_t    *driver;
        uint16_t        i, md, direp, *table;

        /* Host */
        /* Get Endpoint address from PIPE number */
        for( md = 0; md < usb_ghstd_DeviceNum[ptr->ip]; md++ )
        {
            if( (usb_ghstd_DeviceDrv[ptr->ip][md].ifclass != USB_IFCLS_NOT) &&
                (usb_ghstd_DeviceDrv[ptr->ip][md].devaddr != USB_NODEVICE) )
            {
                driver = (USB_HCDREG_t*)&usb_ghstd_DeviceDrv[ptr->ip][md];
                table = (uint16_t*)(driver->pipetbl);
                /* EP table loop */
                for( i = 0; table[i] != USB_PDTBLEND; i += USB_EPL )
                {
                    if( table[i] == pipe )
                    {
                        direp = (uint16_t)((((table[i + 1] & USB_DIRFIELD)
                            ^ USB_DIRFIELD) << 3)
                                + (table[i + 1] & USB_EPNUMFIELD));
                        return (uint8_t)(direp);
                    }
                }
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }
    return (uint8_t)USB_ERROR;
}
/******************************************************************************
End of function usb_cstd_Pipe2Epadr
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_Pipe2Fport
Description     : Get port No. from the specified pipe No. by argument
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : uint16_t       : FIFO port selector.
******************************************************************************/
uint16_t usb_cstd_Pipe2Fport(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t        i, *table;

    /* Check current function */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        uint16_t    conf;

        conf = usb_gpstd_ConfigNum;
        if( conf < (uint16_t)1 )
        {
            /* Address state */
            conf = (uint16_t)1;
        }
        /* Peripheral */
        /* Get FIFO port from PIPE number */
        table = (uint16_t*)((uint16_t**)
            (usb_gpstd_Driver.pipetbl[conf - 1]));
        /* EP table loop */
        for( i = 0; table[i] != USB_PDTBLEND; i += USB_EPL )
        {
            if( table[i] == pipe )
            {
                return table[i + 5];
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        uint16_t        md;
        USB_HCDREG_t    *driver;

        /* Host */
        /* Get FIFO port from PIPE number */
        for( md = 0; md < usb_ghstd_DeviceNum[ptr->ip]; md++ )
        {
            if( (usb_ghstd_DeviceDrv[ptr->ip][md].ifclass != USB_IFCLS_NOT) &&
                (usb_ghstd_DeviceDrv[ptr->ip][md].devaddr != USB_NODEVICE) )
            {
                driver = (USB_HCDREG_t*)&usb_ghstd_DeviceDrv[ptr->ip][md];
                table = (uint16_t*)(driver->pipetbl);
                /* EP table loop */
                for( i = 0; table[i] != USB_PDTBLEND; i += USB_EPL )
                {
                    if( table[i] == pipe)
                    {
                        return table[i + 5];
                    }
                }
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }

    return USB_ERROR;
}
/******************************************************************************
End of function usb_cstd_Pipe2Fport
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_GetDeviceAddress
Description     : Get the device address associated with the specified pipe.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t pipe  : Pipe number.
Return value    : uint16_t DEVSEL-bit status
******************************************************************************/
uint16_t usb_cstd_GetDeviceAddress(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t        buffer;

    /* Check current function */
    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        /* Peripheral */
        /* USB address */
        buffer = usb_creg_read_usbaddr( ptr );
        /* Device address */
        return (uint16_t)(buffer & USB_USBADDR_MASK);
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        uint16_t        i, md;
        USB_HCDREG_t    *driver;

        /* Host */
        if( pipe == USB_PIPE0 )
        {
            buffer = usb_creg_read_dcpmaxp( ptr );
            /* Device address */
            return (uint16_t)(buffer & USB_DEVSEL);
        }
        else
        {
            for( md = 0; md < usb_ghstd_DeviceNum[ptr->ip]; md++ )
            {
                if( (usb_ghstd_DeviceDrv[ptr->ip][md].ifclass != USB_IFCLS_NOT) &&
                    (usb_ghstd_DeviceDrv[ptr->ip][md].devaddr != USB_NODEVICE) )
                {
                    driver = (USB_HCDREG_t*)&usb_ghstd_DeviceDrv[ptr->ip][md];
                    /* EP table loop */
                    for( i = 0; driver->pipetbl[i] != USB_PDTBLEND; i
                        += USB_EPL )
                    {
                        if( driver->pipetbl[i] == pipe )
                        {
                            buffer = driver->pipetbl[i + 3];
                            /* Device address */
                            return (uint16_t)(buffer & USB_DEVSEL);
                        }
                    }
                }
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }
    return USB_ERROR;
}
/******************************************************************************
End of function usb_cstd_GetDeviceAddress
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_ClearIntEnb
Description     : Clear teh INTENB register.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
Return value    : none
******************************************************************************/
void    usb_cstd_ClearIntEnb( USB_UTR_t *ptr )
{
    usb_creg_write_intenb( ptr, 0 );
    /* Conditional compile dep. on difference of USB function */
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    usb_hreg_write_intenb( ptr, USB_PORT0, 0 );
    usb_hreg_write_intenb( ptr, USB_PORT1, 0 );
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
}
/******************************************************************************
End of function usb_cstd_ClearIntEnb
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_ClearIntSts
Description     : Clear the INTSTS register.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
Return value    : none
******************************************************************************/
void    usb_cstd_ClearIntSts( USB_UTR_t *ptr )
{
    usb_creg_write_intsts( ptr, 0 );
/* Conditional compile dep. on difference of USB function */
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    usb_hreg_write_intsts( ptr, USB_PORT0, 0 );
    usb_hreg_write_intsts( ptr, USB_PORT1, 0 );
#endif  /* USB_FUNCSEL_USBIP0_PP != USB_PERI_PP && USB_FUNCSEL_USBIP1_PP != USB_PERI_PP */
}
/******************************************************************************
End of function usb_cstd_ClearIntSts
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_ClearDline
Description     : Clear DRPD/DPRPU; host pulldown of resistors for D+ D- lines.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
Return value    : none
******************************************************************************/
void    usb_cstd_ClearDline( USB_UTR_t *ptr )
{
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
    usb_hreg_clr_drpd( ptr, USB_PORT0 );
    usb_hreg_clr_drpd( ptr, USB_PORT1 );
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
    usb_preg_clr_dprpu( ptr );
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
}
/******************************************************************************
End of function usb_cstd_ClearDline
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_PortSpeed
Description     : Get USB-speed of the specified port.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.
                : uint16_t port  : Root port
Return value    : uint16_t       : HSCONNECT : Hi-Speed
                :                : FSCONNECT : Full-Speed
                :                : LSCONNECT : Low-Speed
                :                : NOCONNECT : not connect
******************************************************************************/
uint16_t usb_cstd_PortSpeed(USB_UTR_t *ptr, uint16_t port)
{
    uint16_t    buf, ConnInf;

    buf = usb_creg_read_dvstctr( ptr, port );

    /* Reset handshake status get */
    buf = (uint16_t)(buf & USB_RHST);

    switch( buf )
    {
    /* Get port speed */
    case USB_HSMODE:    ConnInf = USB_HSCONNECT;    break;
    case USB_FSMODE:    ConnInf = USB_FSCONNECT;    break;
    case USB_LSMODE:    ConnInf = USB_LSCONNECT;    break;
    case USB_HSPROC:    ConnInf = USB_NOCONNECT;    break;
    default:        ConnInf = USB_NOCONNECT;    break;
    }

    return (ConnInf);
}
/******************************************************************************
End of function usb_cstd_PortSpeed
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_HiSpeedEnable
Description     : Check if set to Hi-speed.
Arguments       : USB_UTR_t *ptr : USB internal structure. Selects e.g. channel.    ;
                : uint16_t port  : Root port
Return value    : uint16_t       : YES; Hi-Speed enabled.
                :                : NO; Hi-Speed disabled.
******************************************************************************/
uint16_t usb_cstd_HiSpeedEnable(USB_UTR_t *ptr, uint16_t port)
{
    uint16_t    buf;

    buf = usb_creg_read_syscfg( ptr, port );

    if( (buf & USB_HSE) == USB_HSE )
    {
        /* Hi-Speed Enable */
        return USB_YES;
    }
    else
    {
        /* Hi-Speed Disable */
        return USB_NO;
    }
}
/******************************************************************************
End of function usb_cstd_HiSpeedEnable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_SetHse
Description     : Set/clear the HSE-bit of the specified port.
Arguments       : uint16_t port     : Root port.
                : uint16_t speed    : HS_ENABLE/HS_DISABLE.
Return value    : none
******************************************************************************/
void usb_cstd_SetHse(USB_UTR_t *ptr, uint16_t port, uint16_t speed)
{
    if( speed == USB_HS_DISABLE )
    {
        /* HSE = disable */
        usb_creg_clr_hse( ptr, port );
    }
    else
    {
        /* HSE = enable */
        usb_creg_set_hse( ptr, port );
    }
}
/******************************************************************************
End of function usb_cstd_SetHse
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_DummyFunction
Description     : dummy function
Arguments       : uint16_t data1    : Not used.
                : uint16_t data2    : Not used.
Return value    : none
******************************************************************************/
void usb_cstd_DummyFunction(USB_UTR_t *ptr, uint16_t data1, uint16_t data2)
{
}
/******************************************************************************
End of function usb_cstd_DummyFunction
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_DummyTrn
Description     : dummy function
Arguments       : USB_REQUEST_t *data1  : Not used.
                : uint16_t data2        : Not used.
Return value    : none
******************************************************************************/
void usb_cstd_DummyTrn(USB_UTR_t *ptr, USB_REQUEST_t *data1, uint16_t data2)
{
}
/******************************************************************************
End of function usb_cstd_DummyTrn
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_set_usbip_mode
Description     : Set the Host mode or Peripheral mode to USB H/W
Arguments       : USB_UTR_t *ptr : USB system internal structure.
                : uint16_t function : Host mode/Peripheral mode
Return value    : none
******************************************************************************/
void usb_cstd_set_usbip_mode(USB_UTR_t *ptr, uint16_t function)
{
    /* USB interrupt message initialize */
    usb_cstd_InitUsbMessage(ptr, function);
    /* Select HW function */
    usb_cstd_set_usbip_mode_sub(ptr, function);
}/* eof usb_cstd_set_usbip_mode() */



/******************************************************************************
Function Name   : usb_cstd_RecMsg
Description     : Receive a message to the specified id (mailbox).
Argument        : uint8_t id        : ID number (mailbox).
                : USB_MSG_t** mess  : Message pointer
                : USB_TM_t tm       : Timeout Value
Return          : uint16_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t usb_cstd_RecMsg( uint8_t id, USB_MSG_t** mess, USB_TM_t tm )
{
    if(( id < USB_IDMAX ) && ( usb_scstd_ID_use < USB_IDMAX ))
    {
        if( id == usb_scstd_ID_use )
        {
            *mess = usb_scstd_Add_use;
            return  USB_E_OK;
        }
    }   
    return  USB_E_ERROR;
}
/******************************************************************************
End of function usb_cstd_RecMsg
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_RecMsg
Description     : Receive a message to the specified id (mailbox).
Argument        : uint8_t id        : ID number (mailbox).
                : USB_MSG_t** mess  : Message pointer
                : USB_TM_t tm       : Timeout Value
Return          : uint16_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t R_usb_cstd_RecMsg( uint8_t id, USB_MSG_t** mess, USB_TM_t tm )
{
    USB_ER_t err;

    err = usb_cstd_RecMsg( id,  mess, tm );

    return err;
}
/******************************************************************************
End of function R_usb_cstd_RecMsg
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_SndMsg
Description     : Send a message to the specified id (mailbox).
Argument        : uint8_t id        : ID number (mailbox).
                : USB_MSG_t* mess   : Message pointer
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t usb_cstd_SndMsg( uint8_t id, USB_MSG_t* mess )
{
    USB_ER_t    status;

    /* USB interrupt disable */
    usb_cpu_int_disable((USB_UTR_t*)mess);
    status = usb_cstd_iSndMsg(id,mess);
    /* USB interrupt enable */
    usb_cpu_int_enable((USB_UTR_t*)mess);
    return status;
}
/******************************************************************************
End of function usb_cstd_SndMsg
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_SndMsg
Description     : Send a message to the specified id (mailbox).
Argument        : uint8_t id        : ID number (mailbox).
                : USB_MSG_t* mess   : Message pointer
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t R_usb_cstd_SndMsg( uint8_t id, USB_MSG_t* mess )
{
    USB_ER_t    status;

    status = usb_cstd_SndMsg( id, mess );

    return status;
}
/******************************************************************************
End of function R_usb_cstd_SndMsg
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_iSndMsg
Description     : Send a message to the specified id (mailbox) while executing 
                : an interrupt.
Argument        : uint8_t id        : ID number (mailbox).
                : USB_MSG_t* mess   : Message pointer
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t usb_cstd_iSndMsg( uint8_t id, USB_MSG_t* mess )
{
    uint8_t usb_pri;        /* Task Priority */
    uint8_t usb_write;      /* Priority Table Writing pointer */

    if( id < USB_IDMAX )
    {
        /* Read priority and table pointer */
        usb_pri     = usb_scstd_Pri[id];
        usb_write   = usb_scstd_PriW[usb_pri];
        if( usb_pri < USB_PRIMAX )
        {
            /* Renewal write pointer */
            usb_write++;
            if( usb_write >= USB_TABLEMAX )
            {
                usb_write = USB_TBLCLR;
            }
            /* Check pointer */
            if( usb_write == usb_scstd_PriR[usb_pri])
            {
                return  USB_E_ERROR;
            }
            /* Save message */
            /* Set priority table */
            usb_scstd_TableID[usb_pri][usb_write]   = id;
            usb_scstd_TableAdd[usb_pri][usb_write]  = mess;
            usb_scstd_PriW[usb_pri]                 = usb_write;
            
            return  USB_E_OK;
        }
    }
    USB_PRINTF0("SND_MSG ERROR !!\n");
    return  USB_E_ERROR;

}
/******************************************************************************
End of function usb_cstd_iSndMsg
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_iSndMsg
Description     : Send a message to the specified id (mailbox) while executing 
                : an interrupt.
Argument        : uint8_t id        : ID number (mailbox).
                : USB_MSG_t* mess   : Message pointer
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t R_usb_cstd_iSndMsg( uint8_t id, USB_MSG_t* mess )
{
    USB_ER_t err;

    err = usb_cstd_iSndMsg( id, mess );

    return err;
}
/******************************************************************************
End of function R_usb_cstd_iSndMsg
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_PgetBlk
Description     : Get a memory block for the caller.
Argument        : uint8_t id        : ID number (mailbox).
                : USB_UTR_t** blk   : Memory block pointer.
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t usb_cstd_PgetBlk( uint8_t id, USB_UTR_t** blk )
{
    uint8_t usb_s_pblk_c;

    if( id < USB_IDMAX )
    {
        usb_s_pblk_c = USB_CNTCLR;
        while(usb_s_pblk_c != USB_BLKMAX)
        {
            if(usb_scstd_BlkFlg[usb_s_pblk_c] == USB_FLGCLR)
            {
                /* Acquire fixed-size memory block */
                *blk    = &usb_scstd_Block[usb_s_pblk_c];
                usb_scstd_BlkFlg[usb_s_pblk_c]  = USB_FLGSET;
                return  USB_E_OK;
            }
            usb_s_pblk_c++;
        }
        /* Error of BLK Table Full !!  */
        USB_PRINTF1("usb_scBlkFlg[%d][] Full !!\n",id);
    }
    return  USB_E_ERROR;
}
/******************************************************************************
End of function usb_cstd_PgetBlk
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_PgetBlk
Description     : Call the get memory block function to get a memory block for 
                : the caller.
Argument        : uint8_t id        : ID number (mailbox).
                : USB_UTR_t** blk   : Memory block pointer.
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t R_usb_cstd_PgetBlk( uint8_t id, USB_UTR_t** blk )
{
    USB_ER_t err;

    err = usb_cstd_PgetBlk( id, blk );

    return err;
}
/******************************************************************************
End of function R_usb_cstd_PgetBlk
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_RelBlk
Description     : Release a memory block.
Argument        : uint8_t id        : ID number (mailbox).
                : USB_UTR_t* blk    : Memory block pointer.
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t usb_cstd_RelBlk( uint8_t id,  USB_UTR_t* blk )
{
    uint16_t    usb_s_rblk_c;

    if( id < USB_IDMAX )
    {
        usb_s_rblk_c = USB_CNTCLR;
        while(usb_s_rblk_c != USB_BLKMAX)
        {
            if(blk == &usb_scstd_Block[usb_s_rblk_c])
            {
                /* Release fixed-size memory block */
                usb_scstd_BlkFlg[usb_s_rblk_c] = USB_FLGCLR;
                return  USB_E_OK;
            }
            usb_s_rblk_c++;
        }
        /* Error of BLK Flag is not CLR !!  */
        USB_PRINTF0("TskBlk NO CLR !!\n");
    }
    return  USB_E_ERROR;
}
/******************************************************************************
End of function usb_cstd_RelBlk
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_RelBlk
Description     : Call the function to release a memory block.
Argument        : uint8_t id        : ID number (mailbox).
                : USB_UTR_t* blk    : Memory block pointer.
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR
******************************************************************************/
USB_ER_t R_usb_cstd_RelBlk( uint8_t id,  USB_UTR_t* blk )
{
    USB_ER_t err;

    err = usb_cstd_RelBlk( id, blk );

    return  err;
}
/******************************************************************************
End of function R_usb_cstd_RelBlk
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_WaiMsg
Description     : Runs USB_SND_MSG after running the scheduler the specified 
                : number of times.
Argument        : uint8_t  id       : ID number (mailbox).
                : USB_MSG_t *mess   : Message pointer.
                : uint16_t  times   : Timeout value.
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR.
******************************************************************************/
USB_ER_t usb_cstd_WaiMsg( uint8_t id, USB_MSG_t* mess, uint16_t times )
{
    if( id < USB_IDMAX )
    {
        if( usb_scstd_WaitCounter[id] == 0 )
        {
            usb_scstd_WaitAdd[id] = mess;
            usb_scstd_WaitCounter[id] = times;
            return  USB_E_OK;
        }
    }
    /* Error !!  */
    USB_PRINTF0("WAI_MSG ERROR !!\n");
    return  USB_E_ERROR;
}
/******************************************************************************
End of function usb_cstd_WaiMsg
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_WaiMsg
Description     : Will run USB_SND_MSG after running the scheduler the specified 
                : number of times.
Argument        : uint8_t  id       : ID number (mailbox).
                : USB_MSG_t *mess   : Message pointer.
                : uint16_t  times   : Timeout value.
Return          : USB_ER_t          : USB_E_OK / USB_E_ERROR.
******************************************************************************/
USB_ER_t R_usb_cstd_WaiMsg( uint8_t id, USB_MSG_t* mess, uint16_t times )
{
    USB_ER_t err;

    err = usb_cstd_WaiMsg( id, mess, times );

    return  err;
}
/******************************************************************************
End of function R_usb_cstd_WaiMsg
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_WaitScheduler
Description     : Schedules a wait request.
Argument        : none
Return          : none
******************************************************************************/
void usb_cstd_WaitScheduler(void)
{
    USB_ER_t    err;
    uint8_t     id;

    for( id=0; id < USB_IDMAX; id++ )
    {
        if(usb_scstd_WaitCounter[id] != 0)
        {
            usb_scstd_WaitCounter[id]--;
            if(usb_scstd_WaitCounter[id] == 0)
            {
                err = usb_cstd_SndMsg(id, usb_scstd_WaitAdd[id]);
                if( err != USB_E_OK )
                {
                    usb_scstd_WaitCounter[id]++;
                }
            }
        }
    }
}
/******************************************************************************
End of function usb_cstd_WaitScheduler
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_ScheInit
Description     : Scheduler initialization.
Argument        : none
Return          : none
******************************************************************************/
void usb_cstd_ScheInit(void)
{
    uint8_t i;
    uint8_t j;

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
        usb_scstd_Pri[i]            = (uint8_t)USB_IDCLR;
        usb_scstd_WaitAdd[i]        = (USB_MSG_t*)USB_NONE;
        usb_scstd_WaitCounter[i]    = USB_NONE;
    }
}
/******************************************************************************
End of function usb_cstd_ScheInit
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_Scheduler
Description     : The scheduler.
Argument        : none
Return          : none
******************************************************************************/
void R_usb_cstd_Scheduler(void)
{
    uint8_t    usb_pri;         /* Priority Counter */
    uint8_t    usb_read;        /* Priority Table read pointer */

    /* wait msg */
    usb_cstd_WaitScheduler();

    /* Priority Table reading */
    usb_pri = USB_CNTCLR;
    while( usb_pri < USB_PRIMAX )
    {
        usb_read    = usb_scstd_PriR[usb_pri];
        if( usb_read != usb_scstd_PriW[usb_pri] )
        {
            /* Priority Table read pointer increment */
            usb_read++;     
            if( usb_read >= USB_TABLEMAX )
            {
                usb_read = USB_TBLCLR;
            }
            /* Set practise message */
            usb_scstd_ID_use    = usb_scstd_TableID[usb_pri][usb_read];
            usb_scstd_Add_use   = usb_scstd_TableAdd[usb_pri][usb_read];
            usb_scstd_TableID[usb_pri][usb_read]    = USB_IDMAX;
            usb_scstd_PriR[usb_pri]                 = usb_read;
            usb_scstd_ScheduleFlag                  = USB_FLGSET;
            usb_pri = USB_PRIMAX;
        }
        else
        {
            usb_pri++;
        }
    }
}
/******************************************************************************
End of function R_usb_cstd_Scheduler
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_SetTaskPri
Description     : Set a task's priority.
Argument        : uint8_t tasknum   : Task id.
                : uint8_t pri       : The task priority to be set.
Return          : none
******************************************************************************/
void R_usb_cstd_SetTaskPri(uint8_t tasknum, uint8_t pri)
{
    if(tasknum < USB_IDMAX)
    {
        if(pri < USB_PRIMAX)
        {
            usb_scstd_Pri[tasknum]=pri;
        }
        else if(pri == (uint8_t)USB_IDCLR)
        {
            usb_scstd_Pri[tasknum]=(uint8_t)USB_IDCLR;
        }
        else
        {
        }
    }
}
/******************************************************************************
End of function R_usb_cstd_SetTaskPri
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_CheckSchedule
Description     : Check schedule flag to see if caller's "time has come", then 
                : clear it.
Argument        : none
Return          : flg   : usb_scstd_ScheduleFlag
******************************************************************************/
uint8_t R_usb_cstd_CheckSchedule(void)
{
    uint8_t flg;

    flg = usb_scstd_ScheduleFlag;
    usb_scstd_ScheduleFlag = USB_FLGCLR;
    return flg;
}
/******************************************************************************
End of function R_usb_cstd_CheckSchedule
******************************************************************************/


/******************************************************************************
Function Name   : R_usb_cstd_GetUsbIpAdr  
Description     : Return USB register base address of specified USB IP.
Arguments       : uint16_t  ipno        : USB IP No. that requires the base 
                                          address value 
Return value    : USB_REGADR_t          : Address value
******************************************************************************/
USB_REGADR_t    R_usb_cstd_GetUsbIpAdr( uint16_t ipno )
{
    return (USB_REGADR_t)usb_cstd_GetUsbIpAdr( ipno );
}/* eof R_usb_cstd_GetUsbIpAdr */
 
/******************************************************************************
Function Name   : R_usb_cstd_UsbIpInit
Description     : Initialize the USB IP.
Arguments       : USB_UTR_t *ptr : USB system internal structure.
                : uint16_t  usb_mode    : USB mode (Host/Peripheral).
Return value    : none
******************************************************************************/
void R_usb_cstd_UsbIpInit( USB_UTR_t *ptr, uint16_t usb_mode )
{
    usb_cstd_WaitUsbip( ptr );      /* Wait USB-H/W access enable */
    usb_cstd_AsspConfig( ptr );     /* Set ASSP pin_config */
    usb_cstd_InitialClock( ptr );   /* Start clock */
    R_usb_cstd_ClearHwFunction( ptr );  /* nitinalize USB register (Host/Peripheral common) */
    usb_cstd_Pinconfig( ptr );      /* Set pin_config */

    usb_cstd_set_usbip_mode( ptr, usb_mode );
}/* eof R_usb_cstd_UsbIpInit */
 
/******************************************************************************
Function Name   : R_usb_cstd_ClearHwFunction
Description     : Initinalize USB register (Host/Peripheral common)
Arguments       : USB_UTR_t *ptr : USB system internal structure.
Return value    : none
******************************************************************************/
void R_usb_cstd_ClearHwFunction(USB_UTR_t *ptr)
{
    usb_cstd_SelfClock(ptr);

    usb_cstd_SetNak(ptr, USB_PIPE0);

    usb_cstd_ClearIntEnb( ptr );

    /* Interrupt Disable(BRDY,NRDY,USB_BEMP) */
    usb_creg_write_brdyenb( ptr, 0 );
    usb_creg_write_nrdyenb( ptr, 0 );
    usb_creg_write_bempenb( ptr, 0 );

    /* Interrupt status clear */
    usb_cstd_ClearIntSts( ptr );

    /* Interrupt status clear(USB_BRDY,NRDY,USB_BEMP) */
    usb_creg_write_brdysts( ptr, 0 );
    usb_creg_write_nrdysts( ptr, 0 );
    usb_creg_write_bempsts( ptr, 0 );

    /* D+/D- control line set */
    usb_cstd_ClearDline( ptr );

    usb_creg_clr_hse( ptr, USB_PORT0 );
    usb_creg_clr_hse( ptr, USB_PORT1 );

    /* Function controller select */
    usb_creg_clr_dcfm( ptr ); 
    usb_cstd_SwReset(ptr);

}/* eof R_usb_cstd_ClearHwFunction */

/******************************************************************************
Function Name   : R_usb_cstd_SetRegDvstctr0
Description     : Setting the value(2nd argument) to DVSTCTR0 register
Arguments       : USB_UTR_t *ptr       ; USB internal structure. Selects USB channel.
                : uint16_t   val        : setting value
Return value    : none
******************************************************************************/
void    R_usb_cstd_SetRegDvstctr0( USB_UTR_t *ptr, uint16_t val )
{

    usb_creg_write_dvstctr( ptr, USB_PORT0, val );

}
/******************************************************************************
End of function R_usb_cstd_SetRegDvstctr0
******************************************************************************/

/******************************************************************************
Function Name   : R_usb_cstd_SetRegPipeCtr
Description     : Setting the value(3rd argument) to PIPExCTR register
Arguments       : USB_UTR_t *ptr      ; USB internal structure. Selects USB channel.
                : uint16_t   pipeno    ; Pipe No. 
                : uint16_t   val       ; setting value
Return value    : none
******************************************************************************/
void    R_usb_cstd_SetRegPipeCtr( USB_UTR_t *ptr, uint16_t pipeno, uint16_t val )
{

    usb_creg_write_pipectr( ptr, pipeno, val );

}
/******************************************************************************
End of function R_usb_cstd_SetRegPipeCtr
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_set_usbip_mode_sub
Description     : USB init depending on mode (host peripharal). 
Arguments       : USB_UTR_t *ptr    : USB system internal structure.
                : uint16_t function : HOST/PERI
Return value    : none
******************************************************************************/
void usb_cstd_set_usbip_mode_sub(USB_UTR_t *ptr, uint16_t function)
{

#if USB_PORTSEL_PP == USB_2PORT_PP
    uint16_t   else_connect_inf;
#endif  /* USB_PORTSEL_PP == USB_2PORT_PP */

    if (function == (uint16_t)USB_PERI)
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        /* Interrupt Enable */
        usb_cstd_BerneEnable(ptr);
        usb_pstd_InitConnect(ptr);
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        usb_creg_set_dcfm( ptr );
        usb_creg_set_drpd( ptr, USB_PORT0 );
#if USB_PORTSEL_PP == USB_2PORT_PP
        usb_creg_set_drpd( ptr, USB_PORT1 );
#endif  /* USB_PORTSEL_PP == USB_2PORT_PP */
        /* Interrupt Enable */
        usb_cstd_BerneEnable(ptr);
        /* Wait 10us */
        usb_cpu_Delay1us((uint16_t)10);
#if USB_PORTSEL_PP == USB_2PORT_PP
        else_connect_inf = usb_hstd_InitConnect(ptr, USB_PORT0, USB_DETACHED );
        usb_hstd_InitConnect(ptr, USB_PORT1, else_connect_inf);
#else   /* USB_PORTSEL_PP == USB_2PORT_PP */
        usb_hstd_InitConnect(ptr, USB_PORT0, USB_DETACHED );
#endif  /* USB_PORTSEL_PP == USB_2PORT_PP */
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }
}
/******************************************************************************
End of function usb_cstd_set_usbip_mode_sub
******************************************************************************/


#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP

#if USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_PERI_CDC
int16_t usb_open_pcdc( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_PERI_CDC */

#if USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_HOST_CDC
int16_t usb_open_hcdc( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_HOST_CDC */

#if USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_HOST_HID
int16_t usb_open_hhid( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_HOST_HID */

#if USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_PERI_HID
int16_t usb_open_phid( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_PERI_HID */

#if USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_HOST_MSC
int16_t usb_open_hmsc( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_HOST_MSC */

#if USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_PERI_MSC
int16_t usb_open_pmsc( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP != USB_DEVICE_CLASS_PERI_MSC */

#if USB_DEVICE_CLASS_PP == USB_DEVICE_CLASS_VENDOR
#ifndef USB_HOST_MODE_PP
int16_t usb_open_hvendor( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_HOST_MODE_PP */

#ifndef USB_PERI_MODE_PP
int16_t usb_open_pvendor( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_PERI_MODE_PP */
#else   /* USB_DEVICE_CLASS_PP == USB_DEVICE_CLASS_VENDOR */
int16_t usb_open_hvendor( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}

int16_t usb_open_pvendor( USB_UTR_t *p_utr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    return 0;
}
#endif  /* USB_DEVICE_CLASS_PP == USB_DEVICE_CLASS_VENDOR */

#ifndef USB_CLASS_REQUEST_USE_PP
USB_ER_t usb_control_class_request(void *pram)
{
    return USB_OK;
}
#endif  /* USB_CLASS_REQUEST_USE_PP */
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */



/******************************************************************************
Function Name   : usb_pstd_UsrCtrlTransFunction
Description     : Class request (idle or setup stage)
Arguments       : USB_REQUEST_t *ptr        : request
                : uint16_t stginfo           : stage info
Return value    : none
******************************************************************************/
void usb_pstd_UsrCtrlTransFunction(USB_UTR_t *ptr, USB_REQUEST_t *req, uint16_t stginfo )
{
    if( req->ReqTypeType == USB_CLASS )
    {
        switch( stginfo )
        {
        /* Idle or setup stage */
        case USB_CS_IDST:   usb_pstd_ClassReq0(ptr, req);   break;
        /* Control read data stage */
        case USB_CS_RDDS:   usb_pstd_ClassReq1(ptr, req);   break;
        /* Control write data stage */
        case USB_CS_WRDS:   usb_pstd_ClassReq2(ptr, req);   break;
        /* Control write nodata status stage */
        case USB_CS_WRND:   usb_pstd_ClassReq3(ptr, req);   break;
        /* Control read status stage */
        case USB_CS_RDSS:   usb_pstd_ClassReq4(ptr, req);   break;
        /* Control write status stage */
        case USB_CS_WRSS:   usb_pstd_ClassReq5(ptr, req);   break;

        /* Control sequence error */
        case USB_CS_SQER:
            R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
            break;
        /* Illegal */
        default:
            R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
            break;
        }
    }
    else if( req->ReqTypeType == USB_VENDOR )
    {
        switch( stginfo )
        {
        /* Idle or setup stage */
        case USB_CS_IDST:   usb_pstd_VendorReq0(ptr, req);  break;
        /* Control read data stage */
        case USB_CS_RDDS:   usb_pstd_VendorReq1(ptr, req);  break;
        /* Control write data stage */
        case USB_CS_WRDS:   usb_pstd_VendorReq2(ptr, req);  break;
        /* Control write nodata status stage */
        case USB_CS_WRND:   usb_pstd_VendorReq3(ptr, req);  break;
        /* Control read status stage */
        case USB_CS_RDSS:   usb_pstd_VendorReq4(ptr, req);  break;
        /* Control write status stage */
        case USB_CS_WRSS:   usb_pstd_VendorReq5(ptr, req);  break;

        /* Control sequence error */
        case USB_CS_SQER:
            R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
            break;
        /* Illegal */
        default:
            R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_DATA_ERR);
            break;
        }
    }
    else
    {
        USB_PRINTF2("usb_pstd_UsrCtrlTransFunction Err: %x %x\n", req->ReqTypeType, stginfo );
        R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
    }
}
/******************************************************************************
End of function usb_pstd_UsrCtrlTransFunction
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClassReq0
Description     : Class request (idle or setup stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_ClassReq0(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
}
/******************************************************************************
End of function usb_pstd_ClassReq0
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClassReq1
Description     : Class request (control read data stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_ClassReq1(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
}
/******************************************************************************
End of function usb_pstd_ClassReq1
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClassReq2
Description     : Class Request (control write data stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_ClassReq2(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
}
/******************************************************************************
End of function usb_pstd_ClassReq2
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClassReq3
Description     : Class request (control write nodata status stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_ClassReq3(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
}
/******************************************************************************
End of function usb_pstd_ClassReq3
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClassReq4
Description     : Class request (control read status stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_ClassReq4(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
}
/******************************************************************************
End of function usb_pstd_ClassReq4
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_ClassReq5
Description     : Class request (control write status stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_ClassReq5(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
}
/******************************************************************************
End of function usb_pstd_ClassReq5
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_VendorReq0
Description     : Vendor request (idle or setup stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_VendorReq0(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
}
/******************************************************************************
End of function usb_pstd_VendorReq0
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_VendorReq1
Description     : Vendor request (control read data stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_VendorReq1(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
}
/******************************************************************************
End of function usb_pstd_VendorReq1
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_VendorReq2
Description     : Vendor request (control write data stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_VendorReq2(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
}
/******************************************************************************
End of function usb_pstd_VendorReq2
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_VendorReq3
Description     : Vendor request (control write nodata status stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_VendorReq3(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
}
/******************************************************************************
End of function usb_pstd_VendorReq3
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_VendorReq4
Description     : Vendor request (control read status stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_VendorReq4(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
}
/******************************************************************************
End of function usb_pstd_VendorReq4
******************************************************************************/


/******************************************************************************
Function Name   : usb_pstd_VendorReq5
Description     : Vendor request (control write status stage)
Arguments       : USB_REQUEST_t *req        : request
Return value    : none
******************************************************************************/
void usb_pstd_VendorReq5(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_STALL, USB_PIPE0, (USB_CB_INFO_t)usb_cstd_DummyFunction );
}
/******************************************************************************
End of function usb_pstd_VendorReq5
******************************************************************************/


/******************************************************************************
Function Name   : usb_cstd_GetUsbIpAdr
Description     : Get base address of the selected USB channel's peripheral 
                : registers.
Argument        : uint16_t ipnum  : USB_USBIP_0 (0), or USB_USBIP_1 (1).
Return          : USB_REGADR_t    : A pointer to the USB_597IP register 
                                  : structure USB_REGISTER containing all USB
                                  : channel's registers.
******************************************************************************/
USB_REGADR_t    usb_cstd_GetUsbIpAdr( uint16_t ipnum )
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
Function Name   : usb_cstd_GetD0fifo16Adr
Description     : Get 16 bits of used channel's D0FIFO register content.
Arguments       : USB_UTR_t *ptr : USB system internal structure. Selects channel.
Return          : Address of D0FIFO
******************************************************************************/
uint32_t    usb_cstd_GetD0fifo16Adr( USB_UTR_t *ptr )
{
    return (uint32_t)(&ptr->ipp->D0FIFO.WORD);
}/* eof usb_cstd_GetD0fifo16Adr() */

/******************************************************************************
Function Name   : usb_cstd_GetD0fifo8Adr
Description     : Get 8 bits of used channel's D0FIFO register content.
Arguments       : USB_UTR_t *ptr : USB system internal structure. Selects channel.
Return          : Address of D0FIFO
******************************************************************************/
uint32_t    usb_cstd_GetD0fifo8Adr( USB_UTR_t *ptr )
{
    return (uint32_t)(&ptr->ipp->D0FIFO.BYTE.L);
}/* eof usb_cstd_GetD0fifo8Adr() */

/******************************************************************************
Function Name   : usb_cstd_AsspConfig
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : not used
Return value    : -
******************************************************************************/
void usb_cstd_AsspConfig(USB_UTR_t *ptr)
{
}/* eof usb_cstd_AsspConfig() */

/******************************************************************************
Function Name   : usb_cstd_Pinconfig
Description     : Set FIFO select register. This will assign a pipe to the FIFOs, 
                : and control how FIFOs are accessed.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
Return value    : -
******************************************************************************/
void usb_cstd_Pinconfig(USB_UTR_t *ptr)
{
    /* CFIFO Port Select Register  (0x20) */
    usb_creg_write_fifosel( ptr, USB_CUSE, USB_MBW_16 );
    /* D0FIFO Port Select Register (0x28) */
    usb_creg_write_fifosel( ptr, USB_D0USE, USB_MBW_16 );
    /* D1FIFO Port Select Register (0x2C) */
    usb_creg_write_fifosel( ptr, USB_D1USE, USB_MBW_16 );

    /* setting ENDIAN for CFIFOSEL */
    usb_creg_set_bigend( ptr, USB_CUSE, USB_FIFOENDIAN );
    /* setting ENDIAN for D0FIFOSEL */
    usb_creg_set_bigend( ptr, USB_D0USE, USB_FIFOENDIAN );
    /* setting ENDIAN for D1FIFOSEL */
    usb_creg_set_bigend( ptr, USB_D1USE, USB_FIFOENDIAN );
} /* eof usb_cstd_Pinconfig() */

/******************************************************************************
Function Name   : usb_cstd_InitialClock
Description     : Enable USB module clock. Resets and starts peripheral.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_cstd_InitialClock(USB_UTR_t *ptr)
{
    usb_creg_set_scke( ptr );
}/* eof usb_cstd_InitialClock() */

/******************************************************************************
Function Name   : usb_cstd_InterruptClock
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : Not used
Return value    : none
******************************************************************************/
void usb_cstd_InterruptClock(USB_UTR_t *ptr)
{
}/* eof usb_cstd_InterruptClock() */

/******************************************************************************
Function Name   : usb_cstd_SelfClock
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : Not used
Return value    : none
******************************************************************************/
void usb_cstd_SelfClock(USB_UTR_t *ptr)
{
}/* eof usb_cstd_SelfClock() */

/******************************************************************************
Function Name   : usb_cstd_StopClock
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : Not used
Return value    : none
******************************************************************************/
void usb_cstd_StopClock(USB_UTR_t *ptr)
{
}/* eof usb_cstd_StopClock() */

/******************************************************************************
Function Name   : usb_cstd_D0FifoselSet
Description     : Set DOFIFO access width, set to DMA buffer clear mode and 
                : the endian setting.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_cstd_D0FifoselSet(USB_UTR_t *ptr)
{
    /* Big endian mode set */
//  usb_creg_set_bigend( ptr, USB_D0DMA, 1 ); 
    /* DMA buffer clear mode set */
    usb_creg_clr_dclrm( ptr, USB_D0DMA );
    /* Maximum bit width for FIFO access set */
    usb_creg_set_mbw( ptr, USB_D0DMA, 1 );
}/* eof usb_cstd_D0FifoselSet() */

/******************************************************************************
Function Name   : usb_cstd_GetBufSize
Description     : Return buffer size, or max packet size, of specified pipe.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe number.
Return value    : uint16_t          : FIFO buffer size or max packet size.
******************************************************************************/
uint16_t usb_cstd_GetBufSize(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t    size, buffer;

    if( pipe == USB_PIPE0 )
    {
        /* Not continuation transmit */
        buffer = usb_creg_read_dcpmaxp( ptr );
    }
    else
    {
        /* Pipe select */
        usb_creg_write_pipesel( ptr, pipe );
        buffer = usb_creg_read_pipemaxp( ptr );
    }
    /* Max Packet Size */
    size = (uint16_t)(buffer & USB_MAXP);

    return size;
}/* eof usb_cstd_GetBufSize() */

/******************************************************************************
Function Name   : usb_cstd_pipe_init
Description     : Initialization of registers associated with specified pipe.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe Number
                : uint16_t *tbl     : ep table
                : uint16_t ofs      : ep table offset
Return value    : none
******************************************************************************/
void usb_cstd_pipe_init(USB_UTR_t *ptr, uint16_t pipe, uint16_t *tbl, uint16_t ofs)
{

    usb_gcstd_Pipe[ptr->ip][pipe] = (USB_UTR_t*)USB_NULL;

    /* Interrupt Disable */
    /* Ready         Int Disable */
    usb_creg_clr_brdyenb( ptr, pipe );

    /* NotReady      Int Disable */
    usb_creg_clr_nrdyenb( ptr, pipe );

    /* Empty/SizeErr Int Disable */
    usb_creg_clr_bempenb( ptr, pipe );

    /* PID=NAK & clear STALL */
    usb_cstd_ClrStall(ptr, pipe);
    
    /* PIPE Configuration */
    usb_creg_write_pipesel( ptr, pipe );

    if( USB_D0DMA == tbl[ofs + 5] )
    {
        tbl[ofs + 1] |= USB_BFREON;
    }

    usb_creg_write_pipecfg( ptr, tbl[ofs + 1]);

    usb_creg_write_pipebuf( ptr, tbl[ofs + 2] );
    usb_creg_write_pipemaxp( ptr, tbl[ofs + 3] );
    usb_creg_write_pipeperi( ptr, tbl[ofs + 4] );

    /* FIFO buffer DATA-PID initialized */
    usb_creg_write_pipesel( ptr, USB_PIPE0 );

    /* SQCLR */
    usb_creg_set_sqclr(ptr, pipe);
    /* ACLRM */
    usb_cstd_DoAclrm(ptr, pipe);
    /* CSSTS */
    usb_creg_set_csclr(ptr, pipe);
    
    /* Interrupt status clear */
    /* Ready         Int Clear */
    usb_creg_clr_sts_brdy( ptr, pipe );

    /* NotReady      Int Clear */
    usb_creg_clr_sts_nrdy( ptr, pipe );

    /* Empty/SizeErr Int Clear */
    usb_creg_clr_sts_bemp( ptr, pipe );
}/* eof usb_cstd_pipe_init() */

/******************************************************************************
Function Name   : usb_cstd_ClrPipeCnfg
Description     : Clear specified pipe configuration register.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe_no  : pipe number
Return value    : none
******************************************************************************/
void usb_cstd_ClrPipeCnfg(USB_UTR_t *ptr, uint16_t pipe_no)
{
    uint16_t    buffer;

    usb_gcstd_Pipe[ptr->ip][pipe_no] = (USB_UTR_t*)USB_NULL;

    /* PID=NAK & clear STALL */
    usb_cstd_ClrStall(ptr, pipe_no);
    
    /* Interrupt disable */
    /* Ready         Int Disable */
    usb_creg_clr_brdyenb( ptr, pipe_no );

    /* NotReady      Int Disable */
    usb_creg_clr_nrdyenb( ptr, pipe_no );

    /* Empty/SizeErr Int Disable */
    usb_creg_clr_bempenb( ptr, pipe_no );

    /* PIPE Configuration */
    usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE, USB_NO);
    /* Clear D0FIFO-port */
    buffer = usb_creg_read_fifosel( ptr, USB_D0DMA );

    if( (buffer & USB_CURPIPE) == pipe_no )
    {
        usb_cpu_d0fifo_stop_dma(ptr);
        usb_cstd_D0fifoStopUsb(ptr);
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
    }
    /* Clear D1FIFO-port */
    buffer = usb_creg_read_fifosel( ptr, USB_D1DMA );

    if( (buffer & USB_CURPIPE) == pipe_no )
    {
        usb_creg_set_mbw( ptr, USB_D1USE, USB_MBW );
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
    }
    usb_creg_write_pipesel( ptr, pipe_no );
    usb_creg_write_pipecfg( ptr, 0 );

    usb_creg_write_pipebuf( ptr, 0 );
    usb_creg_write_pipemaxp( ptr, 0 );
    usb_creg_write_pipeperi( ptr, 0 );
    usb_creg_write_pipesel( ptr, 0 );

    /* FIFO buffer DATA-PID initialized */
    /* SQCLR */
    usb_creg_set_sqclr(ptr, pipe_no);
    /* ACLRM */
    usb_cstd_DoAclrm(ptr, pipe_no);
    /* CSSTS */
    usb_creg_set_csclr(ptr, pipe_no);
    usb_cstd_ClrTransactionCounter(ptr, pipe_no);
    
    /* Interrupt status clear */
    /* Ready         Int Clear */
    usb_creg_clr_sts_brdy( ptr, pipe_no );

    /* NotReady      Int Clear */
    usb_creg_clr_sts_nrdy( ptr, pipe_no );

    /* Empty/SizeErr Int Clear */
    usb_creg_clr_sts_bemp( ptr, pipe_no );
}/* eof usb_cstd_ClrPipeCnfg() */

/******************************************************************************
Function Name   : usb_cstd_WaitUsbip
Description     : Wait USB ASSP ready
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_cstd_WaitUsbip(USB_UTR_t *ptr)
{
    /* XCKE Mode Flag */
    usb_gcstd_XckeMode = USB_NO;
    /* Hi-speed enable */
    usb_gcstd_HsEnable[ptr->ip] = USB_HSESEL;
}/* eof usb_cstd_WaitUsbip() */

/******************************************************************************
Function Name   : usb_cstd_SetNak
Description     : Set up to NAK the specified pipe.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe Number
Return value    : none
******************************************************************************/
void usb_cstd_SetNak(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t        buf, n;

    /* Set NAK */
    usb_creg_clr_pid( ptr, pipe, (uint16_t)USB_PID_BUF );

    /* The state of PBUSY continues while transmitting the packet when it is a detach. */
    /* 1ms comes off when leaving because the packet duration might not exceed 1ms.  */
    /* Whether it is PBUSY release or 1ms passage can be judged. */
    for( n = 0; n < 0xFFFFu; ++n )
    {
        /* PIPE control reg read */
        buf = usb_creg_read_pipectr( ptr, pipe );
        if( (uint16_t)(buf & USB_PBUSY) == 0 )
        {
            n = 0xFFFEu;
        }
    }
}/* eof usb_cstd_SetNak() */

/******************************************************************************
Function Name   : usb_cstd_write_fifo
Description     : Write specified amount of data to specified USB FIFO. 
Arguments       : USB_UTR_t *ptr        : USB system internal structure. Selects channel.
                : uint16_t  count       : Write size.
                : uint16_t  pipemode    : The mode of CPU/DMA(D0)/DMA(D1).
                : uint16_t  *write_p    : Address of buffer of data to write.
Return value    : The incremented address of last argument (write_p).
******************************************************************************/
uint8_t *usb_cstd_write_fifo( USB_UTR_t *ptr, uint16_t count, uint16_t pipemode, uint8_t *write_p )
{
    uint16_t    even;

    for( even = (uint16_t)(count >> 1); (even != 0); --even )
    {
        /* 16bit access */
        usb_creg_write_fifo16( ptr, pipemode, *((uint16_t *)write_p) );

        /* Renewal write pointer */
        write_p += sizeof(uint16_t);
    }

    if( (count & (uint16_t)0x0001u) != 0u )
    {
        /* 8bit access */
        /* count == odd */
        /* Change FIFO access width */
        usb_creg_set_mbw( ptr, pipemode, USB_MBW_8 );

        /* FIFO write */
        usb_creg_write_fifo8( ptr, pipemode, *write_p );

        /* Return FIFO access width */
        usb_creg_set_mbw( ptr, pipemode, USB_MBW_16 );

        /* Renewal write pointer */
        write_p++;
    }
    return write_p;
}/* eof usb_cstd_write_fifo() */

/******************************************************************************
Function Name   : usb_cstd_read_fifo
Description     : Read specified buffer size from the USB FIFO.
Arguments       : USB_UTR_t *ptr        : USB system internal structure. Selects channel.
                : uint16_t  count       : Read size.
                : uint16_t  pipemode    : The mode of CPU/DMA(D0)/DMA(D1).
                : uint16_t  *write_p    : Address of buffer to store the read data.
Return value    : Pointer to a buffer that contains the data to be read next.
******************************************************************************/
uint8_t *usb_cstd_read_fifo( USB_UTR_t *ptr, uint16_t count, uint16_t pipemode, uint8_t *read_p )
{
    uint16_t    even;
    uint16_t    odd_byte_data_temp;

    for( even = (uint16_t)(count >> 1); (even != 0); --even )
    {
        /* 16bit FIFO access */
        *(uint16_t *)read_p= usb_creg_read_fifo16( ptr, pipemode );

        /* Renewal read pointer */
        read_p += sizeof( uint16_t );
    }
    if( (count & (uint16_t)0x0001) != 0 )
    {
        /* 16bit FIFO access */
        odd_byte_data_temp = usb_creg_read_fifo16( ptr, pipemode );
/* Condition compilation by the difference of the endian */
#if USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP
        *read_p = (uint8_t)( odd_byte_data_temp & 0x00ff);
#else    /* USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP */
        *read_p = (uint8_t)( odd_byte_data_temp >> 8 );
#endif    /* USB_CPUBYTE_PP == USB_BYTE_LITTLE_PP */
        /* Renewal read pointer */
        read_p += sizeof( uint8_t );
    }
    return read_p;
}/* eof usb_cstd_read_fifo() */

/******************************************************************************
Function Name   : usb_cstd_is_set_frdy
Description     : Changes the specified FIFO port by the specified pipe.
                : Please change the wait time for your MCU.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe Number
                : uint16_t fifosel  : FIFO select
                : uint16_t isel     : ISEL bit status
Return value    : FRDY status
******************************************************************************/
uint16_t usb_cstd_is_set_frdy(USB_UTR_t *ptr, uint16_t pipe, uint16_t fifosel, uint16_t isel)
{
    uint16_t    buffer, i;

    /* Changes the FIFO port by the pipe. */
    usb_cstd_chg_curpipe(ptr, pipe, fifosel, isel);

    for( i = 0; i < 4; i++ )
    {
        buffer = usb_creg_read_fifoctr( ptr, fifosel );

        if( (uint16_t)(buffer & USB_FRDY) == USB_FRDY )
        {
            return (buffer);
        }
        USB_PRINTF1("*** FRDY wait pipe = %d\n", pipe);
        
        /* Caution!!!
     * Depending on the external bus speed of CPU, you may need to wait
     * for 100ns here.
     * For details, please look at the data sheet.   */
    /***** The example of reference. *****/
        buffer = usb_creg_read_syscfg( ptr, USB_PORT0 );
        buffer = usb_creg_read_syssts( ptr, USB_PORT0 );
    /*************************************/
    }
    return (USB_FIFOERROR);
}/* eof of function usb_cstd_is_set_frdy() */

/******************************************************************************
Function Name   : usb_cstd_chg_curpipe
Description     : Switch FIFO and pipe number.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe number.
                : uint16_t fifosel  : FIFO selected (CPU, D0, D1..)
                : uint16_t isel     : CFIFO Port Access Direction.(Pipe1 to 9:Set to 0)
Return value    : none
******************************************************************************/
void usb_cstd_chg_curpipe(USB_UTR_t *ptr, uint16_t pipe, uint16_t fifosel, uint16_t isel)
{
    uint16_t    buffer;

    /* Select FIFO */
    switch( fifosel )
    {
    /* CFIFO use */
    case USB_CUSE:
        /* ISEL=1, CURPIPE=0 */
        usb_creg_rmw_fifosel( ptr, USB_CUSE, (USB_RCNT|isel|pipe), (USB_RCNT|USB_ISEL|USB_CURPIPE) );
        do
        {
            buffer = usb_creg_read_fifosel( ptr, USB_CUSE );
        }
        while( (buffer & (uint16_t)(USB_ISEL|USB_CURPIPE))
            != (uint16_t)(isel|pipe) );
        break;
    /* D0FIFO use */
    case USB_D0USE:
        /* continue */
    /* D0FIFO DMA */
    case USB_D0DMA:
        /* D0FIFO pipe select */
        usb_creg_set_curpipe( ptr, USB_D0DMA, pipe );
        do
        {
            buffer = usb_creg_read_fifosel( ptr, USB_D0DMA );
        }
        while( (uint16_t)(buffer & USB_CURPIPE) != pipe );
        break;
    /* D1FIFO use */
    case USB_D1USE:
        /* continue */
    /* D1FIFO DMA */
    case USB_D1DMA:
        /* D1FIFO pipe select */
        usb_creg_set_curpipe( ptr, USB_D1DMA, pipe );

        do
        {
            buffer = usb_creg_read_fifosel( ptr, USB_D1DMA );
        }
        while( (uint16_t)(buffer & USB_CURPIPE) != pipe );
        break;
    default:
        break;
    }
}/* eof usb_cstd_chg_curpipe() */

/******************************************************************************
Function Name   : usb_cstd_FifoClr
Description     : Clear the specified PIPE FIFO using Auto Buffer Clear Mode.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe Number
Return value    : none
******************************************************************************/
void usb_cstd_FifoClr(USB_UTR_t *ptr, uint16_t pipe)
{
    uint16_t        buf, i;

    if( pipe == USB_USEPIPE )
    {
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
        
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
        for( i = USB_MIN_PIPE_NO; i <= USB_MAX_PIPE_NO; i++ )
        {
            /* Do pipe ACLRM */
            usb_cstd_DoAclrm(ptr, i);
        }
    }
    else
    {
        buf = usb_creg_read_fifosel( ptr, USB_D0USE );
        if( (buf & USB_CURPIPE) == pipe )
        {
            /* Changes the FIFO port by the pipe. */
            usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
        }
        buf = usb_creg_read_fifosel( ptr, USB_D1USE );
        if( (buf & USB_CURPIPE) == pipe )
        {
            /* Changes the FIFO port by the pipe. */
            usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
        }
        /* Do pipe ACLRM */
        usb_cstd_DoAclrm(ptr, pipe);
    }
}/* eof usb_cstd_FifoClr() */

/******************************************************************************
Function Name   : usb_cstd_SetTransactionCounter
Description     : Set specified Pipe Transaction Counter Register.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t trnreg   : Pipe number
                : uint16_t trncnt       : Transaction counter
Return value    : none
******************************************************************************/
void usb_cstd_SetTransactionCounter(USB_UTR_t *ptr, uint16_t trnreg, uint16_t trncnt)
{

    usb_creg_set_trclr( ptr, trnreg );
    usb_creg_write_pipetrn( ptr, trnreg, trncnt );
    usb_creg_set_trenb( ptr, trnreg );

}/* eof usb_cstd_SetTransactionCounter() */

/******************************************************************************
Function Name   : usb_cstd_ClrTransactionCounter
Description     : Clear specified Pipe Transaction Counter Register.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t trnreg   : Pipe Number
Return value    : none
******************************************************************************/
void usb_cstd_ClrTransactionCounter(USB_UTR_t *ptr, uint16_t trnreg)
{
    usb_creg_clr_trenb( ptr, trnreg );
    usb_creg_set_trclr( ptr, trnreg );
}/* eof usb_cstd_ClrTransactionCounter() */

/******************************************************************************
Function Name   : usb_cstd_ForcedTermination
Description     : Terminate data transmission and reception.
Arguments       : USB_UTR_t *ptr    : USB system internal structure. Selects channel.
                : uint16_t pipe     : Pipe Number
                : uint16_t status   : Transfer status type
Return value    : none
Note            : In the case of timeout status, it does not call back.
******************************************************************************/
void usb_cstd_ForcedTermination(USB_UTR_t *ptr, uint16_t pipe, uint16_t status)
{
    uint16_t    buffer;

    /* PID = NAK */
    /* Set NAK */
    usb_cstd_SetNak(ptr, pipe);

    /* Disable Interrupt */
    /* Disable Ready Interrupt */
    usb_creg_clr_brdyenb(ptr, pipe);
    /* Disable Not Ready Interrupt */
    usb_creg_clr_nrdyenb(ptr, pipe);
    /* Disable Empty Interrupt */
    usb_creg_clr_bempenb(ptr, pipe);

    usb_cstd_ClrTransactionCounter(ptr, pipe);

    /* Clear D1FIFO-port */
    buffer = usb_creg_read_fifosel( ptr, USB_CUSE );
    if( (buffer & USB_CURPIPE) == pipe )
    {
        usb_creg_set_mbw( ptr, USB_CUSE, USB_CFIFO_MBW );
        
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE, USB_NO);
    }
    /* Clear D0FIFO-port */
    buffer = usb_creg_read_fifosel( ptr, USB_D0DMA );
    if( (buffer & USB_CURPIPE) == pipe )
    {
        /* Stop DMA,FIFO access */
        usb_cpu_d0fifo_stop_dma(ptr);
        usb_cstd_D0fifoStopUsb(ptr);
        usb_cstd_D0FifoselSet(ptr);
        usb_creg_write_dmacfg( ptr, USB_D0DMA, USB_CPU_ADR_RD_WR );
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D0USE, USB_NO);
    }
    /* Clear D1FIFO-port */
    buffer = usb_creg_read_fifosel( ptr, USB_D1DMA );
    if( (buffer & USB_CURPIPE) == pipe )
    {
        usb_creg_set_mbw( ptr, USB_D1DMA, USB_D1FIFO_MBW );
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_D1USE, USB_NO);
    }

    /* Changes the FIFO port by the pipe. */
    usb_cstd_chg_curpipe(ptr, pipe, (uint16_t)USB_CUSE, USB_NO);
    buffer = usb_creg_read_fifoctr( ptr, USB_CUSE );
    if( (uint16_t)(buffer & USB_FRDY) == USB_FRDY )
    {
        /* Clear BVAL */
        usb_creg_set_bclr( ptr, USB_CUSE );
    }

    /* FIFO buffer SPLIT transaction initialized */
    usb_cstd_chg_curpipe(ptr, (uint16_t)USB_PIPE0, (uint16_t)USB_CUSE, USB_NO);
    usb_creg_set_csclr(ptr, pipe);

    /* Call Back */
    if( usb_gcstd_Pipe[ptr->ip][pipe] != USB_NULL )
    {
        /* Transfer information set */
        usb_gcstd_Pipe[ptr->ip][pipe]->tranlen  = usb_gcstd_DataCnt[ptr->ip][pipe];
        usb_gcstd_Pipe[ptr->ip][pipe]->status   = status;
        usb_gcstd_Pipe[ptr->ip][pipe]->pipectr  = usb_creg_read_pipectr(ptr, pipe);
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        usb_gcstd_Pipe[ptr->ip][pipe]->errcnt   = (uint8_t)usb_ghstd_IgnoreCnt[ptr->ip][pipe];
#else   /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
        usb_gcstd_Pipe[ptr->ip][pipe]->errcnt   = 0;
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */

        usb_gcstd_Pipe[ptr->ip][pipe]->ipp  = ptr->ipp;
        usb_gcstd_Pipe[ptr->ip][pipe]->ip   = ptr->ip;

        if( USB_NULL != ( usb_gcstd_Pipe[ptr->ip][pipe]->complete ) )
        {
            (*usb_gcstd_Pipe[ptr->ip][pipe]->complete)(usb_gcstd_Pipe[ptr->ip][pipe], 0, 0);
        }
        usb_gcstd_Pipe[ptr->ip][pipe] = (USB_UTR_t*)USB_NULL;
    }
}/* eof usb_cstd_ForcedTermination() */

/******************************************************************************
Function Name   : usb_cstd_nrdy_endprocess
Description     : NRDY interrupt processing. (Forced termination of data trans-
                : mission and reception of specified pipe.)
Arguments       : USB_UTR_t *ptr       : USB system internal structure. Selects channel.
                : uint16_t  pipe        : Pipe No
Return value    : none
Note            : none
******************************************************************************/
void    usb_cstd_nrdy_endprocess( USB_UTR_t *ptr, uint16_t pipe )
{
    if( usb_cstd_is_host_mode(ptr) == USB_YES )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        uint16_t    buffer;

        /*
            Host Function
        */
        buffer = usb_cstd_GetPid(ptr, pipe);
        /* STALL ? */
        if( (buffer & USB_PID_STALL) == USB_PID_STALL )
        {
            USB_PRINTF1("### STALL Pipe %d\n", pipe);
            /* @4 */
            /* End of data transfer */
            usb_cstd_ForcedTermination(ptr, pipe, USB_DATA_STALL);
        }
        else
        {
            /* Wait for About 60ns */
            buffer = usb_creg_read_syssts( ptr, USB_PORT0 );
            /* @3 */
            usb_ghstd_IgnoreCnt[ptr->ip][pipe]++;
            USB_PRINTF2("### IGNORE Pipe %d is %d times \n", pipe, usb_ghstd_IgnoreCnt[ptr->ip][pipe]);
            if( usb_ghstd_IgnoreCnt[ptr->ip][pipe] == USB_PIPEERROR )
            {
                /* Data Device Ignore X 3 call back */
                /* End of data transfer */
                usb_cstd_ForcedTermination(ptr, pipe, USB_DATA_ERR);
            }
            else
            {
                /* 5ms wait */
                usb_cpu_DelayXms(5);
                /* PIPEx Data Retry */
                usb_cstd_SetBuf(ptr, pipe);
            }
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }
}/* eof usb_cstd_nrdy_endprocess() */


/******************************************************************************
Function Name   : usb_creg_read_syscfg
Description     : Returns the specified port's SYSCFG register value.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t port   : Port number (not used $REA)
Return value    : SYSCFG content.
******************************************************************************/
uint16_t    usb_creg_read_syscfg( USB_UTR_t *ptr, uint16_t port )
{
    return ptr->ipp->SYSCFG.WORD;
}/* eof usb_creg_read_syscfg() */

/******************************************************************************
Function Name   : usb_creg_write_syscfg
Description     : Write specified value to the SYSCFG register of the given port.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t port   : Port number (only port 0 used $REA)
                : uint16_t data   : Value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_syscfg( USB_UTR_t *ptr, uint16_t port, uint16_t  data )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->SYSCFG.WORD = data;
    }
}/* eof usb_creg_write_syscfg */

/******************************************************************************
Function Name   : usb_creg_set_xtal
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : USB system internal data.
                : uint16_t data     : Not used for 597ASSP silicon.
Return value    : none
******************************************************************************/
void    usb_creg_set_xtal( USB_UTR_t *ptr, uint16_t data )
{
}/* eof usb_creg_set_xtal() */

/******************************************************************************
Function Name   : usb_creg_set_xcke
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : USB system internal data.
Return value    : none
******************************************************************************/
void    usb_creg_set_xcke( USB_UTR_t *ptr )
{
}/* eof usb_creg_set_xcke() */

/******************************************************************************
Function Name   : usb_creg_set_scke
Description     : Enable USB module clock.
Arguments       : USB_UTR_t *ptr : USB system internal structure. Selects channel.
Return value    : -
******************************************************************************/
void    usb_creg_set_scke( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD |= USB_SCKE;
}/* eof usb_creg_set_xcke */

/******************************************************************************
Function Name   : usb_creg_clr_scke
Description     : Disable USB module clock.
Arguments       : USB_UTR_t *ptr : USB system internal structure. Selects channel.
Return value    : -
******************************************************************************/
void    usb_creg_clr_scke( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD &= ~USB_SCKE;
}/* eof usb_creg_clr_scke() */

/******************************************************************************
Function Name   : usb_creg_set_hse
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr  : Not used.
                : uint16_t  port  : Not used.
Return value    : none
******************************************************************************/
void    usb_creg_set_hse( USB_UTR_t *ptr, uint16_t port )
{
}/* eof usb_creg_set_hse() */

/******************************************************************************
Function Name   : usb_creg_clr_hse
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr  : Not used.
                : uint16_t  port  : Not used.
Return value    : none
******************************************************************************/
void    usb_creg_clr_hse( USB_UTR_t *ptr, uint16_t port )
{
}/* eof usb_creg_clr_hse() */

/******************************************************************************
Function Name   : usb_creg_set_dcfm
Description     : DCFM-bit set of register SYSCFG
                : (USB Host mode is selected.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_set_dcfm( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD |= USB_DCFM;
}/* eof usb_creg_set_dcfm() */

/******************************************************************************
Function Name   : usb_creg_clr_dcfm
Description     : DCFM-bit clear of register SYSCFG.
                : (USB Peripheral mode is selected.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_clr_dcfm( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD &= ~USB_DCFM;
}/* eof usb_creg_clr_dcfm() */

/******************************************************************************
Function Name   : usb_creg_set_drpd
Description     : Set bit of the specified port's SYSCFG DRPD register.
                : (for USB Host mode; set D + / D-line PullDown.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : USB port number.
Return value    : none
******************************************************************************/
void    usb_creg_set_drpd( USB_UTR_t *ptr, uint16_t port )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->SYSCFG.WORD |= USB_DRPD;
    }
}/* eof usb_creg_set_drpd() */

/******************************************************************************
Function Name   : usb_creg_clr_drpd
Description     : Clear bit of the specified port's SYSCFG DRPD register.
                : (for USB Host mode; Enable D + / D-line PullDown.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : Port number
Return value    : none
******************************************************************************/
void    usb_creg_clr_drpd( USB_UTR_t *ptr, uint16_t port )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->SYSCFG.WORD &= ~USB_DRPD;
    }
}/* eof usb_creg_clr_drpd() */

/******************************************************************************
Function Name   : usb_creg_set_usbe
Description     : Enable USB operation.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_set_usbe( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD |= USB_USBE;
}/* eof usb_creg_set_usbe() */

/******************************************************************************
Function Name   : usb_creg_clr_usbe
Description     : Enable USB operation.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_clr_usbe( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD &= ~USB_USBE;
}/* eof usb_creg_clr_usbe() */


/***********/
/*  SYSSTS0 */
/***********/
/* System Configuration Status Register 0 */

/******************************************************************************
Function Name   : usb_creg_read_syssts
Description     : Returns the value of the specified port's SYSSTS register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : USB port number. ($REA not used.)
Return value    : SYSSTS0 content
******************************************************************************/
uint16_t    usb_creg_read_syssts( USB_UTR_t *ptr, uint16_t port )
{
    return (uint16_t)(ptr->ipp->SYSSTS0.WORD);
}/* eof usb_creg_read_syssts() */

/******************************************************************************
Function Name   : usb_creg_write_syssts
Description     : Write to the specified port's SYSSTS register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : USB port number.
                : uint16_t  data  : The value to write
Return value    : none
******************************************************************************/
void        usb_creg_write_syssts( USB_UTR_t *ptr, uint16_t port, uint16_t data )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->SYSSTS0.WORD = data;
    }
}/* eof usb_creg_write_syssts() */

/************/
/*  DVSTCTR0  */
/************/
/* Device State Control Register 0 */

/******************************************************************************
Function Name   : usb_creg_read_dvstctr
Description     : Returns the specified port's DVSTCTR register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : USB port number. ($REA not used.)
Return value    : DVSTCTR0 content
******************************************************************************/
uint16_t    usb_creg_read_dvstctr( USB_UTR_t *ptr, uint16_t port )
{
    return (uint16_t)(ptr->ipp->DVSTCTR0.WORD);
}/* eof usb_creg_read_dvstctr() */

/******************************************************************************
Function Name   : usb_creg_write_dvstctr
Description     : Write data to the specified port's DVSTCTR register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : USB port number.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void        usb_creg_write_dvstctr( USB_UTR_t *ptr, uint16_t port, uint16_t data )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->DVSTCTR0.WORD = data;
    }
}/* eof usb_creg_write_dvstctr() */

/******************************************************************************
Function Name   : usb_creg_rmw_dvstctr
Description     : Read-modify-write the specified port's DVSTCTR.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : Port number
                : uint16_t  data  : The value to write.
                : uint16_t  bitptn: Bit pattern to read-modify-write.
Return value    : none
******************************************************************************/
void        usb_creg_rmw_dvstctr( USB_UTR_t *ptr, uint16_t port, uint16_t data, uint16_t bitptn )
{
    uint16_t    buf;

    if( USB_PORT0 == port )
    {
        buf = ptr->ipp->DVSTCTR0.WORD;
        buf &= ~bitptn;
        buf |= (data & bitptn);
        ptr->ipp->DVSTCTR0.WORD = buf;
    }
}/* eof usb_creg_rmw_dvstctr() */

/******************************************************************************
Function Name   : usb_creg_clr_dvstctr
Description     : Clear the bit pattern specified in argument, of the specified 
                : port's DVSTCTR register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : Port number
                : uint16_t  bitptn: Bit pattern to read-modify-write.
Return value    : none
******************************************************************************/
void        usb_creg_clr_dvstctr( USB_UTR_t *ptr, uint16_t port,uint16_t bitptn)
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->DVSTCTR0.WORD &= ~bitptn;
    }
}/* eof usb_creg_clr_dvstctr() */

/******************************************************************************
Function Name   : usb_creg_set_vbout
Description     : Set specified port's VBOUT-bit in the DVSTCTR register.
                : (To output a "High" to pin VBOUT.) 
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : Port number
Return value    : none
******************************************************************************/
void    usb_creg_set_vbout( USB_UTR_t *ptr, uint16_t port )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->DVSTCTR0.WORD |= USB_VBOUT;
    }
}/* eof usb_creg_set_vbout() */

/******************************************************************************
Function Name   : usb_creg_clr_vbout
Description     : Clear specified port's VBOUT-bit in the DVSTCTR register.
                : (To output a "Low" to pin VBOUT.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  port  : Port number
Return value    : none
******************************************************************************/
void    usb_creg_clr_vbout( USB_UTR_t *ptr, uint16_t port )
{
    if( USB_PORT0 == port )
    {
        ptr->ipp->DVSTCTR0.WORD &= ~USB_VBOUT;
    }
}/* eof usb_creg_clr_vbout() */


/**************/
/*  TESTMODE  */
/**************/

/******************************************************************************
Function Name   : usb_creg_set_utst
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr  : 
                : uint16_t  data
Return value    : none
******************************************************************************/
void    usb_creg_set_utst( USB_UTR_t *ptr, uint16_t data )
{
}/* eof usb_creg_set_utst() */


/************/
/*  PINCFG  */
/************/

/******************************************************************************
Function Name   : usb_creg_set_ldrv
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr  : 
Return value    : none
******************************************************************************/
void    usb_creg_set_ldrv( USB_UTR_t *ptr )
{
}/* eof usb_creg_set_ldrv() */

/******************************************************************************
Function Name   : usb_creg_clr_ldrv
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : USB system internal data.
Return value    : none
******************************************************************************/
void    usb_creg_clr_ldrv( USB_UTR_t *ptr )
{
}/* eof usb_creg_clr_ldrv() */

/*********************************/
/*  DMA0CFG, DMA1CFG  for 597ASSP */
/*********************************/

/******************************************************************************
Function Name   : usb_creg_write_dmacfg
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : USB system internal data.
Return value    : none
******************************************************************************/
void    usb_creg_write_dmacfg( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data )
{
}/* eof usb_creg_write_dmacfg() */

/***************************/
/*  CFIFO, D0FIFO, D1FIFO  */
/***************************/
/* FIFO Port Register */

/******************************************************************************
Function Name   : usb_creg_read_fifo32
Description     : Not processed as the functionality is provided by R2R.
Arguments       : USB_UTR_t *ptr    : USB system internal data.
Return value    : none
******************************************************************************/
uint32_t    usb_creg_read_fifo32( USB_UTR_t *ptr, uint16_t pipemode )
{
    /* for R2R */
    return (uint32_t)0;
}/* eof usb_creg_read_fifo32() */

/******************************************************************************
Function Name   : usb_creg_write_fifo32
Description     : Not processed as the functionality is provided by R2R.
Arguments       : USB_UTR_t *ptr    : USB system internal data.
Return value    : none
******************************************************************************/
void    usb_creg_write_fifo32( USB_UTR_t *ptr, uint16_t pipemode, uint32_t data )
{
}/* eof usb_creg_write_fifo32() */

/******************************************************************************
Function Name   : usb_creg_read_fifo16
Description     : Data is read from the specified pipemode's FIFO register, 16-bits 
                : wide, corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipemode  : CUSE/D0DMA/D1DMA
Return value    : CFIFO/D0FIFO/D1FIFO content (16-bit)
******************************************************************************/
uint16_t    usb_creg_read_fifo16( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    data;
    switch( pipemode )
    {
        case    USB_CUSE:
            data = ptr->ipp->CFIFO.WORD;
            break;
        case    USB_D0USE:
        case    USB_D0DMA:
            data = ptr->ipp->D0FIFO.WORD;
            break;
        case    USB_D1USE:
        case    USB_D1DMA:
            data = ptr->ipp->D1FIFO.WORD;
            break;
        default:
            while(1);
            break;
    }
    return data;
}/* eof usb_creg_read_fifo16() */

/******************************************************************************
Function Name   : usb_creg_write_fifo16
Description     : Data is written to the specified pipemode's FIFO register, 16-bits 
                : wide, corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipemode  : CUSE/D0DMA/D1DMA
                : uint16_t  data      : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_fifo16( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data )
{
    switch( pipemode )
    {
        case    USB_CUSE:
            ptr->ipp->CFIFO.WORD = data;
            break;
        case    USB_D0USE:
        case    USB_D0DMA:
            ptr->ipp->D0FIFO.WORD = data;
            break;
        case    USB_D1USE:
        case    USB_D1DMA:
            ptr->ipp->D1FIFO.WORD = data;
            break;
        default:
            while(1);
            break;
    }
}/* eof usb_creg_write_fifo16() */

/******************************************************************************
Function Name   : usb_creg_read_fifo8
Description     : Data is read from the specified pipemode's FIFO register, 8-bits 
                : wide, corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipemode : CUSE/D0DMA/D1DMA.
Return value    : CFIFO/D0FIFO/D1FIFO(8-bit)
******************************************************************************/
uint8_t     usb_creg_read_fifo8( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint8_t buf;
    switch( pipemode )
    {
        case    USB_CUSE:
            buf = ptr->ipp->CFIFO.BYTE.L;
            break;
        case    USB_D0USE:
        case    USB_D0DMA:
            buf = ptr->ipp->D0FIFO.BYTE.L;
            break;
        case    USB_D1USE:
        case    USB_D1DMA:
            buf = ptr->ipp->D1FIFO.BYTE.L;
            break;
        default:
            while(1);
            break;
    }
    return  buf;
}/* eof usb_creg_read_fifo8() */

/******************************************************************************
Function Name   : usb_creg_write_fifo8
Description     : Data is written to the specified pipemode's FIFO register, 8-bits 
                : wide, corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipdemode   : CUSE/D0DMA/D1DMA
                : uint8_t   data        : The value to write.
Return value    : none
******************************************************************************/
void        usb_creg_write_fifo8( USB_UTR_t *ptr, uint16_t pipemode, uint8_t data )
{
    switch( pipemode )
    {
        case    USB_CUSE:
            ptr->ipp->CFIFO.BYTE.L = data;
            break;
        case    USB_D0USE:
        case    USB_D0DMA:
            ptr->ipp->D0FIFO.BYTE.L = data;
            break;
        case    USB_D1USE:
        case    USB_D1DMA:
            ptr->ipp->D1FIFO.BYTE.L = data;
            break;
        default:
            while(1);
            break;
    }
}/* eof usb_creg_write_fifo8() */

/**********************************/
/* CFIFOSEL, D0FIFOSEL, D1FIFOSEL */
/**********************************/
/* FIFO Port Select Register */

/******************************************************************************
Function Name   : usb_creg_get_fifosel_adr
Description     : Returns the *address* of the FIFOSEL register corresponding to 
                : specified PIPEMODE.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipemode  : CUSE/D0DMA/D1DMA
Return value    : none
******************************************************************************/
static  void    *usb_creg_get_fifosel_adr( USB_UTR_t *ptr, uint16_t pipemode )
{
    void    *reg_p;

    switch( pipemode )
    {
        case    USB_CUSE:
            reg_p = (void *)&(ptr->ipp->CFIFOSEL);
            break;
        case    USB_D0USE:
        case    USB_D0DMA:
            reg_p = (void *)&(ptr->ipp->D0FIFOSEL);
            break;
        case    USB_D1USE:
        case    USB_D1DMA:
            reg_p = (void *)&(ptr->ipp->D1FIFOSEL);
            break;
        default:
            while(1);
            break;
    }
    return reg_p;
}/* eof usb_creg_get_fifosel_adr() */

/******************************************************************************
Function Name   : usb_creg_read_fifosel
Description     : Returns the value of the specified pipemode's FIFOSEL register.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t  pipemode  : CUSE/D0DMA/D1DMA
Return value    : FIFOSEL content
******************************************************************************/
uint16_t    usb_creg_read_fifosel( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifosel_adr( ptr, pipemode );

    return *reg_p;
}/* eof usb_creg_read_fifosel() */

/******************************************************************************
Function Name   : usb_creg_write_fifosel
Description     : Data is written to the specified pipemode's FIFOSEL register, 8-bits 
                : wide, corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode  : CUSE/D0DMA/D1DMA
                : uint16_t data     : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_fifosel( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifosel_adr( ptr, pipemode );

    *reg_p = data;
}/* eof usb_creg_write_fifosel() */

/******************************************************************************
Function Name   : usb_creg_rmw_fifosel
Description     : Data is written to the specified pipemode's FIFOSEL register 
                : (the FIFOSEL corresponding to the specified PIPEMODE), using 
                : read-modify-write.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
                : uint16_t data     : The value to write.
                : uint16_t bitptn   : bitptn: Bit pattern to read-modify-write.
Return value    : none
******************************************************************************/
void    usb_creg_rmw_fifosel( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data, uint16_t bitptn )
{
    uint16_t    buf;
    uint16_t    *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifosel_adr( ptr, pipemode );

    buf = *reg_p;
    buf &= ~bitptn;
    buf |= (data & bitptn);
    *reg_p = buf;
}/* eof usb_creg_rmw_fifosel() */

/******************************************************************************
Function Name   : usb_creg_set_dclrm
Description     : Set DCLRM-bits (FIFO buffer auto clear) of the FIFOSEL cor-
                : responding to specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : none
******************************************************************************/
void    usb_creg_set_dclrm( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifosel_adr( ptr, pipemode );

    *reg_p |= USB_DCLRM;
}/* eof usb_creg_set_dclrm() */

/******************************************************************************
Function Name   : usb_creg_clr_dclrm
Description     : Reset DCLRM-bits (FIFO buffer not auto-cleared) of the FIFOSEL 
                : corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : none
******************************************************************************/
void    usb_creg_clr_dclrm( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    *reg_p;

    reg_p = usb_creg_get_fifosel_adr( ptr, pipemode );

    *reg_p &= ~USB_DCLRM;
}/* eof usb_creg_clr_dclrm() */

/******************************************************************************
Function Name   : usb_creg_set_dreqe
Description     : Set DREQE-bits (to output signal DxREQ_Na) of the FIFOSEL cor-
                : responding to specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : none
******************************************************************************/
void    usb_creg_set_dreqe( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    *reg_p;

    reg_p = usb_creg_get_fifosel_adr( ptr, pipemode );

    *reg_p |= USB_DREQE;
}/* eof usb_creg_set_dreqe() */

/******************************************************************************
Function Name   : usb_creg_clr_dreqe
Description     : Clear DREQE-bits (To prohibit the output of the signal DxREQ_N)
                : of the FIFOSEL corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA
Return value    : none
******************************************************************************/
void    usb_creg_clr_dreqe( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    *reg_p;

    reg_p = usb_creg_get_fifosel_adr( ptr, pipemode );

    *reg_p &= ~USB_DREQE;
}/* eof usb_creg_clr_dreqe() */

/******************************************************************************
Function Name   : usb_creg_set_mbw
Description     : Set MBW-bits (CFIFO Port Access Bit Width) of the FIFOSEL cor-
                : responding to the specified PIPEMODE, to select 8 or 16-bit 
                : wide FIFO port access.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
                : uint16_t data     : Defined value of 8 (data = 0) or 16 bit 
                : (data = 1) access mode.
Return value    : none
******************************************************************************/
void    usb_creg_set_mbw( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data )
{
    uint16_t    *reg_p;

    reg_p = usb_creg_get_fifosel_adr( ptr, pipemode );

    if( data != 0 )
    {
        *reg_p |= USB_MBW;
    }
    else
    {
        *reg_p &= ~USB_MBW;
    }
}/* eof usb_creg_set_mbw() */

/******************************************************************************
Function Name   : usb_creg_set_bigend
Description     : Set BIGEND-bit of the FIFOSEL corresponding to the specified 
                : PIPEMODE to select big or little endian of CFIFO.
                : mode of the CFIFO.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
                : uint16_t data     : Defined value of big/little endian.
Return value    : none
******************************************************************************/
void    usb_creg_set_bigend( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data )
{
    uint16_t    *reg_p;

    reg_p = usb_creg_get_fifosel_adr( ptr, pipemode );

    if( data != 0 )
    {
        *reg_p |= USB_BIGEND;
    }
    else
    {
        *reg_p &= ~USB_BIGEND;
    }
}/* eof usb_creg_set_bigend() */
/******************************************************************************
Function Name   : usb_creg_set_curpipe
Description     : Set pipe to the number given; in the FIFOSEL corresponding 
                : to specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
                : uint16_t pipeno   : Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_curpipe( USB_UTR_t *ptr, uint16_t  pipemode, uint16_t  pipeno )
{
    uint16_t    *reg_p;
    uint16_t    reg;

    reg_p = usb_creg_get_fifosel_adr( ptr, pipemode );
    reg = *reg_p;

    reg &= ~USB_CURPIPE;
    reg |= pipeno;
    
    *reg_p = reg;
}/* eof usb_creg_set_curpipe() */

/**********************************/
/* CFIFOCTR, D0FIFOCTR, D1FIFOCTR */
/**********************************/
/* FIFO control Registers */

/******************************************************************************
Function Name   : usb_creg_get_fifoctr_adr
Description     : Returns the *address* of the FIFOCTR register corresponding to 
                : specified PIPEMODE.
                : (FIFO Port Control Register.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : none
******************************************************************************/
static  void    *usb_creg_get_fifoctr_adr( USB_UTR_t *ptr, uint16_t pipemode )
{
    void    *reg_p;

    switch( pipemode )
    {
        case    USB_CUSE:
            reg_p = (void *)&(ptr->ipp->CFIFOCTR);
            break;
        case    USB_D0USE:
        case    USB_D0DMA:
            reg_p = (void *)&(ptr->ipp->D0FIFOCTR);
            break;
        case    USB_D1USE:
        case    USB_D1DMA:
            reg_p = (void *)&(ptr->ipp->D1FIFOCTR);
            break;
        default:
            while(1);
            break;
    }
    return reg_p;
}/* eof usb_creg_get_fifoctr_adr() */

/******************************************************************************
Function Name   : usb_creg_read_fifoctr
Description     : Returns the value of the FIFOCTR register corresponding to 
                : specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : FIFOCTR content
******************************************************************************/
uint16_t    usb_creg_read_fifoctr( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifoctr_adr( ptr, pipemode );

    return *reg_p;
}/* eof usb_creg_read_fifoctr() */

/******************************************************************************
Function Name   : usb_creg_set_bval
Description     : Set BVAL (Buffer Memory Valid Flag) to the number given; in 
                : the FIFOCTR corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : none
******************************************************************************/
void    usb_creg_set_bval( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifoctr_adr( ptr, pipemode );

    *reg_p |= USB_BVAL;
}/* eof usb_creg_set_bval() */

/******************************************************************************
Function Name   : usb_creg_set_bclr
Description     : Set BCLR (CPU Buffer Clear) to the number given; in the 
                : FIFOCTR corresponding to the specified PIPEMODE.
Arguments       : USB_UTR_t *ptr       : USB internal structure. Selects USB channel.
                : uint16_t pipemode : CUSE/D0DMA/D1DMA.
Return value    : none
******************************************************************************/
void    usb_creg_set_bclr( USB_UTR_t *ptr, uint16_t pipemode )
{
    uint16_t *reg_p;

    reg_p = (uint16_t *)usb_creg_get_fifoctr_adr( ptr, pipemode );

    *reg_p = USB_BCLR;
}/* eof usb_creg_set_bclr() */


/*************/
/*  INTENB0  */
/*************/
/* Interrupt Enable Register 0 */

/******************************************************************************
Function Name   : usb_creg_read_intenb
Description     : Returns INTENB0 register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : INTENB0 content
******************************************************************************/
uint16_t    usb_creg_read_intenb( USB_UTR_t *ptr )
{
    return ptr->ipp->INTENB0.WORD;
}/* eof usb_creg_read_intenb() */

/******************************************************************************
Function Name   : usb_creg_write_intenb
Description     : Data is written to INTENB register, 
                : enabling/disabling the various USB interrupts.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_intenb( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->INTENB0.WORD = data;
}/* eof usb_creg_write_intenb() */

/******************************************************************************
Function Name   : usb_creg_set_intenb
Description     : Bit(s) to be set in INTENB register, 
                : enabling the respective USB interrupt(s).
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : Bit pattern: Respective interrupts with '1' 
                                  : will be enabled.
Return value    : none
******************************************************************************/
void    usb_creg_set_intenb( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->INTENB0.WORD |= data;
}/* eof usb_creg_set_intenb() */

/******************************************************************************
Function Name   : usb_creg_clr_enb_vbse
Description     : Clear the VBE-bit of INTENB register,
                : to prohibit VBUS interrupts.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_clr_enb_vbse( USB_UTR_t *ptr )
{
    ptr->ipp->INTENB0.WORD &= ~USB_VBSE;
}/* eof usb_creg_clr_enb_vbse() */

/******************************************************************************
Description     : Clear the SOFE-bit of INTENB register,
                : to prohibit Frame Number Update interrupts.
Function Name   : usb_creg_clr_enb_sofe
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_clr_enb_sofe( USB_UTR_t *ptr )
{
    ptr->ipp->INTENB0.WORD &= ~USB_SOFE;
}/* eof usb_creg_clr_enb_sofe() */


/*************/
/*  INTENB1  */
/*************/

/*************/
/*  BRDYENB  */
/*************/
/* BRDY Interrupt Enable Register */

/******************************************************************************
Function Name   : usb_creg_read_brdyenb
Description     : Returns BRDYENB register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : BRDYENB content
******************************************************************************/
uint16_t    usb_creg_read_brdyenb( USB_UTR_t *ptr )
{
    return ptr->ipp->BRDYENB.WORD;
}/* eof usb_creg_read_brdyenb() */

/******************************************************************************
Function Name   : usb_creg_write_brdyenb
Description     : Data is written to BRDYENB register, 
                : enabling/disabling each respective pipe's BRDY interrupt. 
                : (The BRDY interrupt indicates that a FIFO port is accessible.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data        : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_brdyenb( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->BRDYENB.WORD = data;
}/* eof usb_creg_write_brdyenb() */

/******************************************************************************
Function Name   : usb_creg_set_brdyenb
Description     : A bit is set in the specified pipe's BRDYENB, enabling the 
                : respective pipe BRDY interrupt(s).
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_brdyenb( USB_UTR_t *ptr, uint16_t  pipeno )
{
    ptr->ipp->BRDYENB.WORD |= (1 << pipeno);
}/* eof usb_creg_set_brdyenb() */

/******************************************************************************
Function Name   : usb_creg_clr_brdyenb
Description     : Clear the PIPExBRDYE-bit of the specified pipe to prohibit 
                : BRDY interrupts of that pipe.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_brdyenb( USB_UTR_t *ptr, uint16_t  pipeno )
{
    ptr->ipp->BRDYENB.WORD &= ~(1 << pipeno);
}/* eof usb_creg_clr_brdyenb() */


/*************/
/*  NRDYENB  */
/*************/
/* NRDY (not ready) Interrupt Enable Register */

/******************************************************************************
Function Name   : usb_creg_read_nrdyenb
Description     : Returns NRDYENB register content. 
                : (The NRDY interrupt indicates that more time is needed before 
                : continuing data communication.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : NRDYENB content
******************************************************************************/
uint16_t    usb_creg_read_nrdyenb( USB_UTR_t *ptr )
{
    return ptr->ipp->NRDYENB.WORD;
}/* eof usb_creg_read_nrdyenb() */

/******************************************************************************
Function Name   : usb_creg_write_nrdyenb
Description     : Data is written to NRDYENB register, 
                : enabling/disabling each respective pipe's NRDY interrupt
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_nrdyenb( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->NRDYENB.WORD = data;
}/* eof usb_creg_write_nrdyenb() */

/******************************************************************************
Function Name   : usb_creg_set_nrdyenb
Description     : A bit is set in the specified pipe's NRDYENB, enabling the 
                : respective pipe NRDY interrupt(s).
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_nrdyenb( USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->NRDYENB.WORD |= (1 << pipeno);
}/* eof usb_creg_set_nrdyenb() */

/******************************************************************************
Function Name   : usb_creg_clr_nrdyenb
Description     : Clear the PIPExNRDYE-bit of the specified pipe to prohibit 
                : NRDY interrupts of that pipe.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_nrdyenb(USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->NRDYENB.WORD &= ~(1 << pipeno);
}/* eof usb_creg_clr_nrdyenb() */


/*************/
/*  BEMPENB  */
/*************/
/* BEMP (buffer empty) Interrupt Enable Register */

/******************************************************************************
Function Name   : usb_creg_read_bempenb
Description     : Returns BEMPENB register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : BEMPENB content
******************************************************************************/
uint16_t    usb_creg_read_bempenb( USB_UTR_t *ptr )
{
    return ptr->ipp->BEMPENB.WORD;
}/* eof usb_creg_read_bempenb() */

/******************************************************************************
Function Name   : usb_creg_write_bempenb
Description     : Data is written to BEMPENB register, 
                : enabling/disabling each respective pipe's BEMP interrupt. 
                : (The BEMP interrupt indicates that the USB buffer is empty, 
                : and so the FIFO can now be written to.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_bempenb( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->BEMPENB.WORD = data;
}/* eof usb_creg_write_bempenb() */

/******************************************************************************
Function Name   : usb_creg_set_bempenb
Description     : A bit is set in the specified pipe's BEMPENB enabling the 
                : respective pipe's BEMP interrupt(s).
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_bempenb( USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->BEMPENB.WORD |= (1 << pipeno);
}/* eof usb_creg_set_bempenb() */

/******************************************************************************
Function Name   : usb_creg_clr_bempenb
Description     : Clear the PIPExBEMPE-bit of the specified pipe to prohibit 
                : BEMP interrupts of that pipe.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_bempenb( USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->BEMPENB.WORD &= ~(1 << pipeno);
}/* eof usb_creg_clr_bempenb() */


/*************/
/*  SOFCFG   */
/*************/
/* SOF (start of frame) Output Configuration Register */

/******************************************************************************
Function Name   : usb_creg_read_sofcfg
Description     : Returns SOFCFG register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : SOFCFG content
******************************************************************************/
uint16_t    usb_creg_read_sofcfg( USB_UTR_t *ptr )
{
    return ptr->ipp->SOFCFG.WORD;
}/* eof usb_creg_read_sofcfg() */


/*************/
/*  INTSTS0  */
/*************/
/* Interrupt Status Register 0 */

/******************************************************************************
Function Name   : usb_creg_read_intsts
Description     : Returns INTSTS0 register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : INTSTS0 content
******************************************************************************/
uint16_t    usb_creg_read_intsts( USB_UTR_t *ptr )
{
    return ptr->ipp->INTSTS0.WORD;
}/* eof usb_creg_read_intsts() */

/******************************************************************************
Function Name   : usb_creg_write_intsts
Description     : Data is written to INTSTS0 register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_intsts( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->INTSTS0.WORD = data;
}/* eof usb_creg_write_intsts() */

/******************************************************************************
Function Name   : usb_creg_clr_sts_vbint
Description     : Clear the the VBINT status bit to clear its the VBUS inter-
                : rupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_clr_sts_vbint( USB_UTR_t *ptr )
{
    ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_VBINT;
}/* eof usb_creg_clr_sts_vbint() */

/******************************************************************************
Function Name   : usb_creg_clr_sts_sofr
Description     : Clear the SOFR-bit (Frame Number Refresh Interrupt Status) of 
                : the clear SOF interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_clr_sts_sofr( USB_UTR_t *ptr )
{
    ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_SOFR;
}/* eof usb_creg_clr_sts_sofr() */


/*************/
/*  INTSTS1  */
/*************/
/* Interrupt Status Register 1 */


/*************/
/* BRDYSTS  */
/*************/
/* BRDY (buffer ready) Interrupt Status Register */

/******************************************************************************
Function Name   : usb_creg_read_brdysts
Description     : Returns BRDYSTS register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : BRDYSTS content
******************************************************************************/
uint16_t    usb_creg_read_brdysts( USB_UTR_t *ptr )
{
    return ptr->ipp->BRDYSTS.WORD;
}/* eof usb_creg_read_brdysts() */

/******************************************************************************
Function Name   : usb_creg_write_brdysts
Description     : Data is written to BRDYSTS register, to set the BRDY interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void        usb_creg_write_brdysts( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->BRDYSTS.WORD = data;
}/* eof usb_creg_write_brdysts() */

/******************************************************************************
Function Name   : usb_creg_clr_sts_brdy
Description     : Clear the PIPExBRDY status bit of the specified pipe to clear 
                : its BRDY interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_sts_brdy( USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->BRDYSTS.WORD = (uint16_t)~(1 << pipeno);
}/* eof usb_creg_clr_sts_brdy() */

/************/
/* NRDYSTS  */
/************/
/* NRDY (not ready) Interrupt Status Register */
/******************************************************************************
Function Name   : usb_creg_read_brdysts
Description     : Returns NRDYSTS register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : NRDYSTS content
******************************************************************************/
uint16_t    usb_creg_read_nrdysts( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->NRDYSTS.WORD;
}/* eof usb_creg_read_brdysts() */

/******************************************************************************
Function Name   : usb_creg_write_nrdysts
Description     : Data is written to NRDYSTS register, to
                : set the NRDY interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void        usb_creg_write_nrdysts( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->NRDYSTS.WORD = data;
}/* eof usb_creg_write_nrdysts() */

/******************************************************************************
Function Name   : usb_creg_clr_sts_nrdy
Description     : Clear the PIPExNRDY status bit of the specified pipe to clear 
                : its NRDY interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_sts_nrdy( USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->NRDYSTS.WORD = (uint16_t)~(1 << pipeno);
}/* eof usb_creg_clr_sts_nrdy() */


/************/
/* BEMPSTS  */
/************/
/* BEMP Interrupt Status Register */

/******************************************************************************
Function Name   : usb_creg_read_bempsts
Description     : Returns BEMPSTS register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : BEMPSTS content
******************************************************************************/
uint16_t    usb_creg_read_bempsts( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->BEMPSTS.WORD;
}/* eof usb_creg_read_bempsts() */

/******************************************************************************
Function Name   : usb_creg_write_bempsts
Description     : Data is written to BEMPSTS register, to set the BEMP interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data        : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_bempsts( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->BEMPSTS.WORD = data;
}/* eof usb_creg_write_bempsts() */

/******************************************************************************
Function Name   : usb_creg_clr_sts_bemp
Description     : Clear the PIPExBEMP status bit of the specified pipe to clear 
                : its BEMP interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_sts_bemp( USB_UTR_t *ptr, uint16_t pipeno )
{
    ptr->ipp->BEMPSTS.WORD = (uint16_t)~(1 << pipeno);
}/* eof usb_creg_clr_sts_bemp() */


/***********/
/* FRMNUM   */
/***********/
/* Frame Number Register */

/******************************************************************************
Function Name   : usb_creg_read_frmnum
Description     : Returns FRMNUM register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : FRMNUM content
******************************************************************************/
uint16_t    usb_creg_read_frmnum( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->FRMNUM.WORD;
}/* eof usb_creg_read_frmnum() */


/************/
/* USBADDR  */
/************/
/* USB Address Register */

/******************************************************************************
Function Name   : usb_creg_read_usbaddr
Description     : Returns USBADDR register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : USBADDR content
******************************************************************************/
uint16_t    usb_creg_read_usbaddr( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->USBADDR.WORD;
}/* eof usb_creg_read_usbaddr() */

/******************************************************************************
Function Name   : usb_creg_set_stsrecov
Description     : STSRECOV-bits are set in USBADDR register
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : Value to be set.
Return value    : none
******************************************************************************/
void    usb_creg_set_stsrecov( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->USBADDR.BIT.STSRECOV = data;
}/* eof usb_creg_set_stsrecov() */


/***********/
/* USBREQ   */
/***********/
/* USB Request Type Register (bRequest and bmRequestType) */

/******************************************************************************
Function Name   : usb_creg_read_usbreq
Description     : Returns USBREQ register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : USBREQ content
******************************************************************************/
uint16_t    usb_creg_read_usbreq( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->USBREQ.WORD;
}/* eof usb_creg_read_usbreq() */


/************/
/* USBVAL   */
/************/
/* USB Request Value Register (wValue) */

/******************************************************************************
Function Name   : usb_creg_read_usbval
Description     : Returns USBVAL register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : USBVAL content
******************************************************************************/
uint16_t    usb_creg_read_usbval( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->USBVAL;
}/* eof usb_creg_read_usbval() */


/************/
/* USBINDX  */
/************/
/* USB Request Index Register (wIndex) */

/******************************************************************************
Function Name   : usb_creg_read_usbindx
Description     : Returns USBINDX register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : USBINDX content
******************************************************************************/
uint16_t    usb_creg_read_usbindx( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->USBINDX;
}/* eof usb_creg_read_usbindx() */


/************/
/* USBLENG  */
/************/
/* USB Request Length Register (wLength) */

/******************************************************************************
Function Name   : usb_creg_read_usbleng
Description     : Returns USBLENG register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : USBLENG content
******************************************************************************/
uint16_t    usb_creg_read_usbleng( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->USBLENG;
}/* eof usb_creg_read_usbleng() */


/***********/
/* DCPCFG   */
/***********/
/* DCP Configuration Register */

/******************************************************************************
Function Name   : usb_creg_read_dcpcfg
Description     : Returns DCPCFG register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : DCPCFG content
******************************************************************************/
uint16_t    usb_creg_read_dcpcfg( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->DCPCFG.WORD;
}/* eof usb_creg_read_dcpcfg() */

/******************************************************************************
Function Name   : usb_creg_write_dcpcfg
Description     : Specified data is written to DCPCFG register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data
Return value    : none
******************************************************************************/
void    usb_creg_write_dcpcfg( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->DCPCFG.WORD = data;
}/* eof usb_creg_write_dcpcfg()*/

/******************************************************************************
Function Name   : usb_creg_set_dcpshtnak
Description     : SHTNAK-bit in the DCPCFG register is set.
                : = Pipe disabled at end of transfer.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void    usb_creg_set_dcpshtnak( USB_UTR_t *ptr )
{
    ptr->ipp->DCPCFG.WORD |= USB_SHTNAKON;
}/* eof usb_creg_set_dcpshtnak() */


/************/
/* DCPMAXP  */
/************/
/* DCP Maximum Packet Size Register */

/******************************************************************************
Function Name   : usb_creg_read_dcpmaxp
Description     : Returns DCPMAXP register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : DCPMAXP content
******************************************************************************/
uint16_t    usb_creg_read_dcpmaxp( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->DCPMAXP.WORD;
}/* eof usb_creg_read_dcpmaxp() */

/******************************************************************************
Function Name   : usb_creg_write_dcpmxps
Description     : Specified data is written to DCPMAXP register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_dcpmxps( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->DCPMAXP.WORD = data;
}/* eof usb_creg_write_dcpmxps() */


/************/
/* DCPCTR   */
/************/
/* DCP Control Register */

/******************************************************************************
Function Name   : usb_creg_read_dcpctr
Description     : Returns DCPCTR register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : DCPCTR content
******************************************************************************/
uint16_t    usb_creg_read_dcpctr( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->DCPCTR.WORD;
}/* eof usb_creg_read_dcpctr() */


/************/
/* PIPESEL  */
/************/
/* Pipe Window Select Register */
/******************************************************************************
Function Name   : usb_creg_read_pipesel
Description     : Returns PIPESEL register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : PIPESEL content
******************************************************************************/
uint16_t    usb_creg_read_pipesel( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->PIPESEL.WORD;
}/* eof usb_creg_read_pipesel() */

/******************************************************************************
Function Name   : usb_creg_write_pipesel
Description     : Specified data is written to PIPESEL register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipesel( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->PIPESEL.WORD = data;
}/* eof usb_creg_write_pipesel() */


/************/
/* PIPECFG  */
/************/
/* Pipe Configuration Register */

/******************************************************************************
Function Name   : usb_creg_read_pipecfg
Description     : Returns PIPECFG register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : PIPECFG content
******************************************************************************/
uint16_t    usb_creg_read_pipecfg( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->PIPECFG.WORD;
}/* eof usb_creg_read_pipecfg() */

/******************************************************************************
Function Name   : usb_creg_write_pipecfg
Description     : Specified data is written to PIPECFG register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipecfg( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->PIPECFG.WORD = data;
}/* eof usb_creg_write_pipecfg() */

/******************************************************************************
Function Name   : usb_creg_set_type
Description     : Specified Transfer Type is set in PIPECFG register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : BULK/INT/ISO
Return value    : none
******************************************************************************/
void    usb_creg_set_type( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->PIPECFG.WORD &= (uint16_t)~USB_TYPE;
    ptr->ipp->PIPECFG.WORD |= (data << USB_TYPE_NUM_SHIFT);
}/* eof usb_creg_set_type() */


/************/
/* PIPEBUF  */
/************/
/* - */

/******************************************************************************
Function Name   : usb_creg_write_pipebuf
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : Not used.
                : uint16_t  data    : Not used.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipebuf( USB_UTR_t *ptr, uint16_t data )
{
}/* eof usb_creg_write_pipebuf() */


/************/
/* PIPEMAXP */
/************/
/* Pipe Maximum Packet Size Register */

/******************************************************************************
Function Name   : usb_creg_read_pipemaxp
Description     : Returns PIPEMAXP register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : PIPEMAXP content
******************************************************************************/
uint16_t    usb_creg_read_pipemaxp( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->PIPEMAXP.WORD;
}/* eof usb_creg_read_pipemaxp() */

/******************************************************************************
Function Name   : usb_creg_write_pipemaxp
Description     : Specified data is written to PIPEMAXP register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipemaxp( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->PIPEMAXP.WORD = data;
}/* eof usb_creg_write_pipemaxp() */

/******************************************************************************
Function Name   : usb_creg_set_mxps
Description     : The specified MXPS-bits, Maximum Packet Size, in PIPEMAXP register is set.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : Max packet size value.
Return value    : none
******************************************************************************/
void    usb_creg_set_mxps( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->PIPEMAXP.WORD &= (uint16_t)~USB_MXPS;
    ptr->ipp->PIPEMAXP.WORD |= (data << USB_MXPS_NUM_SHIFT);
}/* eof usb_creg_set_mxps() */


/************/
/* PIPEPERI */
/************/
/* Pipe Cycle Control Register */

/******************************************************************************
Function Name   : usb_creg_read_pipeperi
Description     : Returns PIPEPERI register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : PIPEPERI content
******************************************************************************/
uint16_t usb_creg_read_pipeperi( USB_UTR_t *ptr )
{
    return (uint16_t)ptr->ipp->PIPEPERI.WORD;
}/* eof usb_creg_read_pipeperi() */

/******************************************************************************
Function Name   : usb_creg_write_pipeperi
Description     : Specified data is written to PIPEPERI register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipeperi( USB_UTR_t *ptr, uint16_t data )
{
    ptr->ipp->PIPEPERI.WORD = data;
}/* eof usb_creg_write_pipeperi() */


/********************/
/* DCPCTR, PIPEnCTR */
/********************/
/* PIPEn Control Registers */

/******************************************************************************
Function Name   : usb_creg_read_pipectr
Description     : Returns DCPCTR or the specified pipe's PIPECTR register content.
                : The Pipe Control Register returned is determined by the speci-
                : fied pipe number.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : PIPExCTR content
******************************************************************************/
uint16_t    usb_creg_read_pipectr( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    if( USB_PIPE0 == pipeno )
    {
        reg_p = (uint16_t *)&(ptr->ipp->DCPCTR);
    }
    else
    {
        reg_p = (uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1);
    }

    return *reg_p;
}/* eof usb_creg_read_pipectr() */

/******************************************************************************
Function Name   : usb_creg_write_pipectr
Description     : Specified data is written to the specified pipe's PIPEPERI register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipectr( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data )
{
    uint16_t    *reg_p;

    if( USB_PIPE0 == pipeno )
    {
        reg_p = (uint16_t *)&(ptr->ipp->DCPCTR);
    }
    else
    {
        reg_p = (uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1);
    }
    *reg_p = data;
} /* eof usb_creg_write_pipectr() */

/******************************************************************************
Function Name   : usb_creg_set_csclr
Description     : Not processed as the functionality is provided by R8A66597(ASSP).
Arguments       : USB_UTR_t *ptr    : USB system internal data.
                : uint16_t  pipeno  : Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_csclr( USB_UTR_t *ptr, uint16_t pipeno )
{
}/* eof usb_creg_set_csclr() */

/******************************************************************************
Function Name   : usb_creg_set_aclrm
Description     : The ACLRM-bit (Auto Buffer Clear Mode) is set in the specified 
                : pipe's control register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_aclrm( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1);

    *reg_p |= USB_ACLRM;
}/* eof usb_creg_set_aclrm() */

/******************************************************************************
Function Name   : usb_creg_clr_aclrm
Description     : Clear the ACLRM bit in the specified pipe's control register
                : to disable Auto Buffer Clear Mode.
                : its BEMP interrupt status.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_aclrm( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1);

    *reg_p &= ~USB_ACLRM;
}/* eof usb_creg_clr_aclrm() */

/******************************************************************************
Function Name   : usb_creg_set_sqclr
Description     : The SQCLR-bit (Toggle Bit Clear) is set in the specified pipe's 
                : control register. Setting SQSET to 1 makes DATA0 the expected 
                : data in the pipe's next transfer.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_sqclr( USB_UTR_t *ptr, uint16_t pipeno )
{
    if( pipeno == USB_PIPE0 )
    {
        ptr->ipp->DCPCTR.WORD |= USB_SQCLR;
    }
    else
    {
        uint16_t    *reg_p;

        reg_p = ((uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1));
        *reg_p |= USB_SQCLR;
    }
}/* eof usb_creg_set_sqclr() */

/******************************************************************************
Function Name   : usb_creg_set_sqset
Description     : The SQSET-bit (Toggle Bit Set) is set in the specified pipe's 
                : control register. Setting SQSET to 1 makes DATA1 the expected 
                : data in the next transfer.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_sqset( USB_UTR_t *ptr, uint16_t pipeno )
{
    if( pipeno == USB_PIPE0 )
    {
        ptr->ipp->DCPCTR.WORD |= USB_SQSET;
    }
    else
    {
        uint16_t    *reg_p;

        reg_p = ((uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1));
        *reg_p |= USB_SQSET;
    }
}/* eof usb_creg_set_sqset() */

/******************************************************************************
Function Name   : usb_creg_clr_sqset
Description     : The SQSET-bit (Toggle Bit Set) is cleared in the specified 
                : pipe's control register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_sqset( USB_UTR_t *ptr, uint16_t pipeno )
{
    if( pipeno == USB_PIPE0 )
    {
        ptr->ipp->DCPCTR.WORD &= ~USB_SQSET;
    }
    else
    {
        uint16_t *reg_p;

        reg_p = ((uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1));
        *reg_p &= ~USB_SQSET;
    }
}/* eof usb_creg_clr_sqset() */

/******************************************************************************
Function Name   : usb_creg_set_pid
Description     : Set the specified PID of the specified pipe's DCPCTR/PIPECTR 
                : register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
                : uint16_t  data  : NAK/BUF/STALL.
Return value    : none
******************************************************************************/
void    usb_creg_set_pid( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data )
{
    uint16_t *reg_p;

    if( pipeno == USB_PIPE0 )
    {
        reg_p = ((uint16_t *)&(ptr->ipp->DCPCTR));
    }
    else
    {
        reg_p = ((uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1));
    }
    *reg_p &= ~USB_PID;
    *reg_p |= data;
}/* eof usb_creg_set_pid() */

/******************************************************************************
Function Name   : usb_creg_clr_pid
Description     : Clear the specified PID-bits of the specified pipe's DCPCTR/
                : PIPECTR register.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
                : uint16_t  data  : NAK/BUF/STALL - to be cleared.
Return value    : none
******************************************************************************/
void    usb_creg_clr_pid( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data )
{
    uint16_t *reg_p;

    if( pipeno == USB_PIPE0 )
    {
        reg_p = ((uint16_t *)&(ptr->ipp->DCPCTR));
    }
    else
    {
        reg_p = ((uint16_t *)&(ptr->ipp->PIPE1CTR) + (pipeno - 1));
    }
    *reg_p &= ~data;
}/* eof usb_creg_clr_pid() */


/************/
/* PIPEnTRE */
/************/
/* PIPEn Transaction Counter Enable Registers */

/******************************************************************************
Function Name   : usb_creg_read_pipetre
Description     : Returns the specified pipe's PIPETRE register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : PIPETRE content
******************************************************************************/
uint16_t    usb_creg_read_pipetre( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1TRE) + (pipeno - 1) * 2;
    
    return *reg_p;
}/* eof usb_creg_read_pipetre() */

/******************************************************************************
Function Name   : usb_creg_set_trenb
Description     : The TRENB-bit (Transaction Counter Enable) is set in the speci-
                : fied pipe's control register, to enable the counter.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_trenb( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1TRE) + (pipeno - 1) * 2;

    *reg_p |= USB_TRENB;
}/* eof usb_creg_set_trenb() */

/******************************************************************************
Function Name   : usb_creg_clr_trenb
Description     : The TRENB-bit (Transaction Counter Enable) is cleared in the 
                : specified pipe's control register, to disable the counter.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_clr_trenb( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1TRE) + (pipeno - 1) * 2;

    *reg_p &= ~USB_TRENB;
}/* eof usb_creg_clr_trenb() */

/******************************************************************************
Function Name   : usb_creg_set_trclr
Description     : The TRENB-bit (Transaction Counter Clear) is set in the speci-
                : fied pipe's control register to clear the current counter 
                : value.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
Return value    : none
******************************************************************************/
void    usb_creg_set_trclr( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1TRE) + (pipeno - 1) * 2;

    *reg_p |= USB_TRCLR;
}/* eof usb_creg_set_trclr() */


/************/
/* PIPEnTRN */
/************/
/* PIPEn Transaction Counter Registers */

/******************************************************************************
Function Name   : usb_creg_read_pipetrn
Description     : Returns the specified pipe's PIPETRN register content.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
                : uint16_t  pipeno: Pipe number.
Return value    : PIPETRN content
******************************************************************************/
uint16_t    usb_creg_read_pipetrn( USB_UTR_t *ptr, uint16_t pipeno )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1TRN) + ((pipeno - 1) * 2);

    return *reg_p;
}/* eof usb_creg_read_pipetrn() */

/******************************************************************************
Function Name   : usb_creg_write_pipetrn
Description     : Specified data is written to the specified pipe's PIPETRN reg-
                : ister.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t  pipeno: Pipe number.
                : uint16_t  data  : The value to write.
Return value    : none
******************************************************************************/
void    usb_creg_write_pipetrn( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data )
{
    uint16_t    *reg_p;

    reg_p = (uint16_t *)&(ptr->ipp->PIPE1TRN) + ((pipeno - 1) * 2);

    *reg_p = data;
}/* eof usb_creg_write_pipetrn */

/************/
/* DEVADDn  */
/************/


/******************************************************************************
Function Name   : usb_cstd_Buf2D0fifoStartUsb
Description     : Setup to start DMA/DTC transfer from data buffer to D0FIFO.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_cstd_Buf2D0fifoStartUsb(USB_UTR_t *ptr)
{
    uint16_t    mbw;

    /* Write (MEMORY -> FIFO) : USB register set */
    if( (usb_gcstd_Dma0Size[ptr->ip] & (uint16_t)0x0001) != 0 )
    {
        mbw = USB_MBW_8;
    }
    else
    {
        mbw = USB_MBW_16;
    }
    /* Change MBW setting */
    usb_creg_set_mbw( ptr, USB_D0DMA, mbw );

    /* DTC(D0FIFO) interrupt enable */
    usb_cpu_d0fifo_enable_dma(ptr);

    /* Set DREQ enable */
    usb_creg_set_dreqe( ptr, USB_D0DMA );
}/* eof usb_cstd_Buf2D0fifoStartUsb() */

/******************************************************************************
Function Name   : usb_cstd_D0fifo2BufStartUsb
Description     : Setup to start DMA/DTC transfer D0FIFO to buffer.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_cstd_D0fifo2BufStartUsb(USB_UTR_t *ptr)
{
    /* Read (FIFO -> MEMORY) : USB register set */
    /* DMA buffer clear mode & MBW set */
    usb_creg_set_mbw( ptr, USB_D0DMA, (uint16_t)(USB_MBW_16) );
    usb_creg_clr_dclrm( ptr, USB_D0DMA );

    /* Set DREQ enable */
    usb_creg_set_dreqe( ptr, USB_D0DMA );
}/* eof usb_cstd_D0fifo2BufStartUsb */

/******************************************************************************
Function Name   : usb_cstd_D0fifoStopUsb
Description     : Setup external variables used for USB data transfer; to reg-
                : ister if you want to stop the transfer of DMA/DTC.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_cstd_D0fifoStopUsb(USB_UTR_t *ptr)
{
    uint16_t    ip = ptr->ip;
    uint16_t    pipe = usb_gcstd_Dma0Pipe[ip];
    uint32_t    transfer_size = usb_gcstd_Dma0Size[ip];
    uint32_t    *request_size = &usb_gcstd_DataCnt[ip][pipe];
    uint8_t     *tran_data_ptr = (uint8_t *)&usb_gcstd_DataPtr[ip][pipe];

    usb_creg_clr_dreqe( ptr, USB_D0DMA );

    /* Direction check */
    if( usb_gcstd_Dma0Dir[ip] == USB_BUF2FIFO )
    {
        /* Buffer to FIFO */
        if( *request_size < transfer_size )
        {
            /* >yes then set BVAL */
            *tran_data_ptr += *request_size;
            *request_size = (uint32_t)0u;
            /* Disable Ready Interrupt */
            usb_creg_clr_brdyenb(ptr, pipe);
            /* Set BVAL */
            usb_creg_set_bval( ptr, USB_D0DMA );
        }
        else
        {
            *tran_data_ptr += transfer_size;
            /* Set data count to remain */
            *request_size -= transfer_size;
        }
    }
    else
    {
        /* FIFO to Buffer */
        *tran_data_ptr += transfer_size;
        /* Set data count to remain */
        if( *request_size < transfer_size )
        {
            *request_size = transfer_size - *request_size;
        }
        else
        {
            *request_size -= transfer_size;
        }
    }
}/* eof usb_cstd_D0fifoStopUsb() */

/******************************************************************************
Function Name   : usb_cstd_D0fifoInt
Description     : Set end of DMA/DTC transfer. Set to restart DMA/DTC trans-
                : fer according to data size of remaining functions to be pro-
                : cessed.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_cstd_D0fifoInt(USB_UTR_t *ptr)
{
    uint16_t pipe;
    uint16_t ip;
    uint16_t maxps;
    uint32_t *transfer_count;

    ip = ptr->ip;
    pipe = usb_gcstd_Dma0Pipe[ip];
    maxps = usb_gcstd_Dma0Fifo[ip];
    transfer_count = &usb_gcstd_DataCnt[ip][pipe];

    /* DMA Transfer Request Clear */
    usb_creg_clr_dreqe( ptr, USB_D0DMA );

    /* Transfer count > MAXPS */
    if ( *transfer_count > maxps )
    {
        /* DMA Transfer count update */
        *transfer_count %= maxps;
        /* Transfer continue check */
        if( *transfer_count != 0 )
        {
            /* Transfer count != MAXPS * N */
            /* Odd size data check  */
            if( (*transfer_count & 0x0001u) != 0u )
            {
                /* if count == odd */
                usb_creg_set_mbw( ptr, USB_D0DMA, USB_MBW_8 );
            }
            /* DMA Transfer size update */
            usb_gcstd_Dma0Size[ip] = *transfer_count;
            /* DMA Restart */
            usb_cpu_d0fifo_restart_dma(ptr);
            /* DMA Transfer Request Set */
            usb_creg_set_dreqe( ptr, USB_D0DMA );
        }
    }
    else if( *transfer_count == 0 )
    {
        /* More than enough Interrupt */
        return;
    }
    else
    {
        /* Transfer count < MAXPS */
        usb_creg_set_bval( ptr, USB_D0DMA );
        /* Transfer complete */
        *transfer_count = 0;
    }

    /* Transfer complete check */
    if( *transfer_count == 0 )
    {
        /* Transfer complete */
        usb_cpu_d0fifo_stop_dma(ptr);

        /* Enable Empty Interrupt */
        usb_creg_set_bempenb(ptr, pipe);
    }

}/* eof usb_cstd_D0fifoInt() */

/******************************************************************************
Function Name   : usb_cstd_Buf2fifoStartDma
Description     : Start transfer using DMA/DTC. If transfer size is 0, write 
                : more data to buffer.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t pipe   : Pipe nr.
                : uint16_t useport: FIFO select
Return value    : none
******************************************************************************/
void    usb_cstd_Buf2fifoStartDma( USB_UTR_t *ptr, uint16_t pipe, uint16_t useport )
{
    /* Transfer size check */
    if( usb_gcstd_Dma0Size[ptr->ip] != 0 )
    {
        /* 16bit access */
        if ( (usb_gcstd_Dma0Size[ptr->ip] & 0x0001u) == 0u )
        {
            /* DMA access Buffer to FIFO start */
            usb_cpu_buf2d0fifo_start_dma(ptr, usb_cstd_GetD0fifo16Adr(ptr));
        }
        else
        {
            /* 8bit access */
            /* DMA access Buffer to FIFO start */
            usb_cpu_buf2d0fifo_start_dma(ptr, usb_cstd_GetD0fifo8Adr(ptr));
        }
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, pipe, useport, USB_NO);
        /* Enable Not Ready Interrupt */
        usb_cstd_NrdyEnable(ptr, pipe);
        /* CPU access Buffer to FIFO start */
        usb_cstd_Buf2D0fifoStartUsb(ptr);
    }
    else
    {
        /* Buffer to FIFO data write */
        usb_cstd_Buf2Fifo(ptr, pipe, useport);
    }
}/* eof usb_cstd_Buf2fifoStartDma() */

/******************************************************************************
Function Name   : usb_cstd_Fifo2BufStartDma
Description     : Start transfer using DMA/DTC. If transfer size is 0, clear DMA. 
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t pipe   : Pipe nr.
                : uint16_t useport: FIFO select
                : uint32_t length
Return value    : none
******************************************************************************/
void    usb_cstd_Fifo2BufStartDma( USB_UTR_t *ptr, uint16_t pipe, uint16_t useport, uint32_t length )
{
    uint16_t        mxps;

    /* Data size check */
    if( usb_gcstd_Dma0Size[ptr->ip] != 0u )
    {
        /* 16bit access */
        if( (usb_gcstd_Dma0Size[ptr->ip] & 0x0001u) == 0u )
        {
            /* D0FIFO to Buffer DMA read start */
            usb_cpu_d0fifo2buf_start_dma(ptr, usb_cstd_GetD0fifo16Adr(ptr));
        }
        else
        {
            /* 8bit access */
            /* D0FIFO to Buffer DMA read start */
            usb_cpu_d0fifo2buf_start_dma(ptr, usb_cstd_GetD0fifo8Adr(ptr));
        }

        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, pipe, useport, USB_NO);
        /* Max Packet Size */
        mxps = usb_cstd_GetMaxPacketSize(ptr, pipe);
        if( length != (uint32_t)0u )
        {
            /* Data length check */
            if( (length % mxps) == (uint32_t)0u )
            {
                /* Set Transaction counter */
                usb_cstd_SetTransactionCounter(ptr, pipe, (uint16_t)(length / mxps));
            }
            else
            {
                /* Set Transaction counter */
                usb_cstd_SetTransactionCounter(ptr, pipe, (uint16_t)((length / mxps) + (uint32_t)1u));
            }
        }
        /* Set BUF */
        usb_cstd_SetBuf(ptr, pipe);
        /* Enable Ready Interrupt */
        usb_creg_set_brdyenb(ptr, pipe);
        /* Enable Not Ready Interrupt */
        usb_cstd_NrdyEnable(ptr, pipe);
        usb_cstd_D0fifo2BufStartUsb(ptr);
    }
    else
    {
        /* Changes the FIFO port by the pipe. */
        usb_cstd_chg_curpipe(ptr, pipe, useport, USB_NO);
        /* DMA buffer clear mode set */
        usb_creg_set_dclrm( ptr, USB_D0DMA );
        /* Set BUF */
        usb_cstd_SetBuf(ptr, pipe);
        /* Enable Ready Interrupt */
        usb_creg_set_brdyenb(ptr, pipe);
        /* Enable Not Ready Interrupt */
        usb_cstd_NrdyEnable(ptr, pipe);
    }
}/* eof usb_cstd_Fifo2BufStartDma() */

#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
/******************************************************************************
Function Name   : usb_cstd_d0fifo_handler
Description     : DMA interrupt routine. Send message to PCD/HCD task.
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cstd_d0fifo_handler(void)
{
    USB_UTR_t       *ptr;

    ptr = &usb_gcstd_IntMsgD0fifo;
    ptr->msghead = (USB_MH_t)USB_NULL;
    ptr->keyword = 0;
    ptr->status  = 0;
    ptr->ip  = USB_USBIP_0;
    ptr->ipp = usb_cstd_GetUsbIpAdr( ptr->ip );

    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
        USB_ER_t        err;

        /* Peripheral Function */
        ptr->msginfo = USB_MSG_PCD_D0FIFO_INT;
        /* Send message */
        err = USB_ISND_MSG(USB_PCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
                USB_PRINTF1("### DmaHandler DEF1 isnd_msg error (%ld)\n", err);
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP
        USB_ER_t        err;

        ptr->msginfo = USB_MSG_HCD_D0FIFO_INT;
        /* Send message */
        err = USB_ISND_MSG(USB_HCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### DmaHandler DEF2 isnd_msg error (%ld)\n", err);
        }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP */
    }
} /* eof usb_cstd_d0fifo_handler() */
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP || USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */

#if USB_FUNCSEL_USBIP1_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
/******************************************************************************
Function Name   : usb2_cstd_d0fifo_handler
Description     : DMA interrupt routine. Send message to PCD/HCD task.
Arguments       : none
Return value    : none
******************************************************************************/
void usb2_cstd_d0fifo_handler(void)
{
/* Conditional compile dep. on difference of USB function */
#if USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP
    USB_UTR_t       *ptr;

    ptr = &usb2_gcstd_IntMsgD0fifo;
    ptr->msghead = (USB_MH_t)USB_NULL;
    ptr->keyword = 0;
    ptr->status  = 0;
    ptr->ip  = USB_USBIP_1;
    ptr->ipp = usb_cstd_GetUsbIpAdr( ptr->ip );

    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {
#if USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
        USB_ER_t        err;

        /* Peripheral Function */
        ptr->msginfo = USB_MSG_PCD_D0FIFO_INT;
        /* Send message */
        err = USB_ISND_MSG(USB_PCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### DmaHandler DEF1 isnd_msg error (%ld)\n", err);
        }
#endif /* USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP */
    }
    else
    {
#if USB_FUNCSEL_USBIP1_PP == USB_HOST_PP
        USB_ER_t        err;

        /* Host Function */
        ptr->msginfo = USB_MSG_HCD_D0FIFO_INT;
        /* Send message */
        err = USB_ISND_MSG(USB_HCD_MBX, (USB_MSG_t*)ptr);
        if( err != USB_E_OK )
        {
            USB_PRINTF1("### DmaHandler DEF2 isnd_msg error (%ld)\n", err);
        }
#endif /* USB_FUNCSEL_USBIP1_PP == USB_HOST_PP */
    }
#endif  /* USB_FUNCSEL_USBIP1_PP != USB_NOUSE_PP */
} /* eof usb2_cstd_d0fifo_handler() */
#endif  /* USB_FUNCSEL_USBIP1_PP == USB_HOST_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */

/******************************************************************************
Function Name   : usb_cstd_brdy_pipe
Description     : Search for the PIPE No. that BRDY interrupt occurred, and 
                  request data transmission/reception from the PIPE
Arguments       : USB_UTR_t *ptr
                : uint16_t bitsts       ; BRDYSTS Register & BRDYENB Register
Return value    : none
******************************************************************************/
void usb_cstd_brdy_pipe(USB_UTR_t *ptr, uint16_t bitsts)
{
    uint16_t        useport, buffer, i;
    uint16_t ip;
#if USB_TARGET_CHIP_PP == USB_RX600_PP
    uint16_t maxps;
    uint16_t set_dtc_brock_cnt;
    uint16_t trans_dtc_block_cnt;
#endif /* USB_TARGET_CHIP_PP == USB_RX600_PP */

    ip = ptr->ip;

#if USB_TARGET_CHIP_PP == USB_RX600_PP
    maxps = usb_gcstd_Dma0Fifo[ip];
#endif /* USB_TARGET_CHIP_PP == USB_RX600_PP */

    for( i = USB_PIPE1; i <= USB_MAX_PIPE_NO; i++ )
    {
        if( (bitsts & USB_BITSET(i)) != 0 )
        {
            /* Interrupt check */
            usb_creg_clr_sts_bemp( ptr, i );

            if( usb_gcstd_Pipe[ip][i] != USB_NULL )
            {
                /* Pipe number to FIFO port select */
                useport = usb_cstd_Pipe2Fport(ptr, i);
                if( useport == USB_D0DMA )
                {
#if USB_TARGET_CHIP_PP == USB_RX600_PP
                    /* DMA Transfer request disable */
                    usb_creg_clr_dreqe( ptr, USB_D0DMA );
#endif /* USB_TARGET_CHIP_PP == USB_RX600_PP */
                
                    /* DMA stop */
                    usb_cpu_d0fifo_stop_dma(ptr);
                
#if USB_TARGET_CHIP_PP == USB_RX600_PP
                    /* Changes FIFO port by the pipe. */
                    buffer = usb_cstd_is_set_frdy(ptr, i, useport, USB_NO);

                    set_dtc_brock_cnt = (uint16_t)((usb_gcstd_DataCnt[ip][usb_gcstd_Dma0Pipe[ip]] -1)
                        / usb_gcstd_Dma0Fifo[ip]) +1;

                    trans_dtc_block_cnt = usb_cpu_get_dtc_block_count(ptr);
                    /* Get D0fifo Receive Data Length */
                    usb_gcstd_Dma0Size[ip]
                        = (uint32_t)(buffer & USB_DTLN) + (set_dtc_brock_cnt - (trans_dtc_block_cnt + 1)) * maxps;

                    /* Check data count */
                    if( usb_gcstd_Dma0Size[ip] == usb_gcstd_DataCnt[ptr->ip][i] )
#else   /* USB_TARGET_CHIP_PP == USB_RX600_PP */
                    /* Check data count */
                    if( usb_gcstd_DataCnt[ip][i] == (uint32_t)0u )
#endif  /* USB_TARGET_CHIP_PP == USB_RX600_PP */
                    {
                        usb_gcstd_DataCnt[ip][i] = 0;
                        /* End of data transfer */
                        usb_cstd_DataEnd(ptr, i, (uint16_t)USB_DATA_OK);
                    }
                    else if( usb_gcstd_Dma0Size[ip] > usb_gcstd_DataCnt[ip][i] )
                    {
                        /* D0FIFO access DMA stop */
                        usb_cstd_D0fifoStopUsb(ptr);
                        /* End of data transfer */
                        usb_cstd_DataEnd(ptr, i, (uint16_t)USB_DATA_OVR);
                    }
                    else
                    {
#if USB_TARGET_CHIP_PP != USB_RX600_PP
                        /* Changes FIFO port by the pipe. */
                        buffer = usb_cstd_is_set_frdy(ptr, i, useport, USB_NO);
                        usb_gcstd_Dma0Size[ip] = (uint16_t)(buffer & USB_DTLN);
#endif /* USB_TARGET_CHIP_PP != USB_RX600_PP */
                        /* D0FIFO access DMA stop */
                        usb_cstd_D0fifoStopUsb(ptr);
                        /* End of data transfer */
                        usb_cstd_DataEnd(ptr, i, (uint16_t)USB_DATA_SHT);
                    }
#if USB_TARGET_CHIP_PP == USB_RX600_PP
                    /* Set BCLR */
                    usb_creg_set_bclr( ptr, USB_D0DMA );
#endif /* USB_TARGET_CHIP_PP == USB_RX600_PP */
                }
                else
                {
                    if( usb_cstd_GetPipeDir(ptr, i) == USB_BUF2FIFO )
                    {
                        /* Buffer to FIFO data write */
                        usb_cstd_Buf2Fifo(ptr, i, useport);
                    }
                    else
                    {
                        /* FIFO to Buffer data read */
                        usb_cstd_Fifo2Buf(ptr, i, useport);
                    }
                }
            }
        }
    }
}/* eof usb_cstd_brdy_pipe() */


/******************************************************************************
Function Name   : usb_pstd_InterruptHandler
Description     : Determine which USB interrupt occurred and report results to 
                : the USB_UTR_t argument's ipp, keyword, and status members.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_pstd_InterruptHandler(USB_UTR_t *ptr)
{
    uint16_t    intsts0, intenb0, ists0;
    uint16_t    brdysts, brdyenb, bsts;
    uint16_t    nrdysts, nrdyenb, nsts;
    uint16_t    bempsts, bempenb, ests;

    /* Register Save */
    intsts0 = ptr->ipp->INTSTS0.WORD;
    brdysts = ptr->ipp->BRDYSTS.WORD;
    nrdysts = ptr->ipp->NRDYSTS.WORD;
    bempsts = ptr->ipp->BEMPSTS.WORD;
    intenb0 = ptr->ipp->INTENB0.WORD;
    brdyenb = ptr->ipp->BRDYENB.WORD;
    nrdyenb = ptr->ipp->NRDYENB.WORD;
    bempenb = ptr->ipp->BEMPENB.WORD;
    
    ptr->keyword = USB_INT_UNKNOWN;
    ptr->status     = 0;

    /* Interrupt status get */
    ists0 = (uint16_t)(intsts0 & intenb0);
    bsts  = (uint16_t)(brdysts & brdyenb);
    nsts  = (uint16_t)(nrdysts & nrdyenb);
    ests  = (uint16_t)(bempsts & bempenb);

    if( (intsts0 & (USB_VBINT|USB_RESM|USB_SOFR|USB_DVST|USB_CTRT|USB_BEMP|USB_NRDY|USB_BRDY)) == 0u )
    {
        return;
    }

    /***** Processing USB bus signal *****/
    /***** Resume signal *****/
    if( (ists0 & USB_RESM) == USB_RESM )
    {
        ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_RESM;
        ptr->keyword = USB_INT_RESM;
    }
    /***** Vbus change *****/
    else if( (ists0 & USB_VBINT) == USB_VBINT )
    {
        /* Status clear */
        ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_VBINT;
        ptr->keyword = USB_INT_VBINT;
    }
    /***** SOFR change *****/
    else if( (ists0 & USB_SOFR) == USB_SOFR )
    {
        /* SOFR Clear */
        ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_SOFR;
        ptr->keyword = USB_INT_SOFR;
    }

    /***** Processing device state *****/
    /***** DVST change *****/
    else if( (ists0 & USB_DVST) == USB_DVST )
    {
        /* DVST clear */
        ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_DVST;
        ptr->keyword = USB_INT_DVST;
        ptr->status     = intsts0;
    }

    /***** Processing PIPE0 data *****/
    else if( ((ists0 & USB_BRDY) == USB_BRDY) && ((bsts & USB_BRDY0) == USB_BRDY0) )
    {
        ptr->ipp->BRDYSTS.WORD = (uint16_t)~USB_BRDY0;
        ptr->keyword = USB_INT_BRDY;
        ptr->status     = USB_BRDY0;
    }
    else if( ((ists0 & USB_BEMP) == USB_BEMP) && ((ests & USB_BEMP0) == USB_BEMP0) )
    {
        ptr->ipp->BEMPSTS.WORD = (uint16_t)~USB_BEMP0;
        ptr->keyword = USB_INT_BEMP;
        ptr->status     = USB_BEMP0;
    }
    else if( ((ists0 & USB_NRDY) == USB_NRDY) && ((nsts & USB_NRDY0) == USB_NRDY0) )
    {
        ptr->ipp->NRDYSTS.WORD = (uint16_t)~USB_NRDY0;
        ptr->keyword = USB_INT_NRDY;
        ptr->status     = USB_NRDY0;
    }

    /***** Processing setup transaction *****/
    else if( (ists0 & USB_CTRT) == USB_CTRT )
    {
        /* CTSQ bit changes later than CTRT bit for ASSP. */
        /* CTSQ reloading */
        ptr->status = usb_creg_read_intsts( ptr );
        /* USB_CTRT clear */
        ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_CTRT;
        ptr->keyword = USB_INT_CTRT;
    }

    /***** Processing PIPE1-MAX_PIPE_NO data *****/
    /***** EP0-7 BRDY *****/
    else if( (ists0 & USB_BRDY) == USB_BRDY )
    {
        ptr->ipp->BRDYSTS.WORD = (uint16_t)~bsts;
        ptr->keyword = USB_INT_BRDY;
        ptr->status     = bsts;
    }
    /***** EP0-7 BEMP *****/
    else if( (ists0 & USB_BEMP) == USB_BEMP )
    {
        ptr->ipp->BEMPSTS.WORD = (uint16_t)~ests;
        ptr->keyword = USB_INT_BEMP;
        ptr->status     = ests;
    }
    /***** EP0-7 NRDY *****/
    else if( (ists0 & USB_NRDY) == USB_NRDY )
    {
        ptr->ipp->NRDYSTS.WORD = (uint16_t)~nsts;
        ptr->keyword = USB_INT_NRDY;
        ptr->status     = nsts;
    }
    else
    {
    }
} /* eof usb_pstd_InterruptHandler() */

/******************************************************************************
Function Name   : usb_pstd_SaveRequest
Description     : Save received USB command.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_pstd_SaveRequest(USB_UTR_t *ptr)
{
    uint16_t    buf;

    /* Valid clear */
    usb_preg_clr_sts_valid( ptr );
    buf = usb_creg_read_usbreq( ptr );

    usb_gpstd_ReqType       = (uint16_t)(buf & USB_BMREQUESTTYPE);
    usb_gpstd_ReqTypeType  = (uint16_t)(buf & USB_BMREQUESTTYPETYPE);
    usb_gpstd_ReqTypeRecip = (uint16_t)(buf & USB_BMREQUESTTYPERECIP);
    usb_gpstd_ReqRequest   = (uint16_t)(buf & USB_BREQUEST);

    usb_gpstd_ReqValue    = usb_creg_read_usbval( ptr );
    usb_gpstd_ReqIndex    = usb_creg_read_usbindx( ptr );
    usb_gpstd_ReqLength    = usb_creg_read_usbleng( ptr );
} /* eof usb_pstd_SaveRequest() */

/******************************************************************************
Function Name   : usb_pstd_ChkConfigured
Description     : Check if USB Device is in a CONFIGURED state. 
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : Configuration state (YES/NO)
******************************************************************************/
uint16_t usb_pstd_ChkConfigured(USB_UTR_t *ptr)
{
    uint16_t    buf;

    buf = usb_creg_read_intsts( ptr );
    /* Device Status - Configured check */
    if( (buf & USB_DVSQ) == USB_DS_CNFG )
    {
        /* Configured */
        return USB_YES;
    }
    else
    {
        /* not Configured */
        return USB_NO;
    }
} /* eof usb_pstd_ChkConfigured() */

/******************************************************************************
Function Name   : usb_pstd_InterruptEnable
Description     : Enable the VBSE interrupt (VBUS), and the DVSE (Device State 
                : Transition) and CTRE (Control Transfer Stage Transition) int-
                : errupts.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_pstd_InterruptEnable(USB_UTR_t *ptr)
{
    /* Enable VBSE, DVSE, CTRE */
    usb_creg_set_intenb( ptr, (USB_VBSE | USB_DVSE | USB_CTRE ));
} /* eof usb_pstd_InterruptEnable() */

/******************************************************************************
Function Name   : usb_pstd_RemoteWakeup
Description     : Set the USB peripheral to implement remote wake up.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_pstd_RemoteWakeup(USB_UTR_t *ptr)
{
    uint16_t    buf;
    uint16_t    dev_info[8];

    /* Get USB Device information */
    R_usb_pstd_DeviceInformation(ptr, (uint16_t *)&dev_info );

    /* Support remote wakeup ? */
    if( dev_info[4] == USB_YES )
    {
        /* RESM interrupt disable */
        usb_preg_clr_enb_rsme( ptr );
        
        /* External clock enable */
        usb_creg_set_xcke( ptr );

        /* RESM status read */
        buf = usb_creg_read_intsts( ptr );
        if( (buf & USB_RESM) != (uint16_t)0 )
        {
            /* RESM status clear */
            usb_preg_clr_sts_resm( ptr );
        }
        else
        {
            if( (buf & USB_DS_SUSP) != (uint16_t)0 )
            {
                /* Remote wakeup set */
                usb_preg_set_wkup( ptr );
                usb_gpstd_intsts0    &= (uint16_t)(~USB_DS_SUSP);
            }
        }
    }
} /* eof usb_pstd_RemoteWakeup() */

/******************************************************************************
Function Name   : usb_pstd_ResumeProcess
Description     : Set USB registers to implement resume processing.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_pstd_ResumeProcess(USB_UTR_t *ptr)
{
    /* RESM status clear */
    usb_preg_clr_sts_resm( ptr );

    /* RESM interrupt disable */
    usb_preg_clr_enb_rsme( ptr );

} /* eof usb_pstd_ResumeProcess() */

/******************************************************************************
Function Name   : usb_pstd_SetStall
Description     : Set the specified pipe's PID to STALL.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
                : uint16_t pipe   : Pipe Number
Return value    : none
******************************************************************************/
void usb_pstd_SetStall(USB_UTR_t *ptr, uint16_t pipe)
{
    /* PIPE control reg set */
    usb_creg_set_pid( ptr, pipe, USB_PID_STALL );
} /* eof usb_pstd_SetStall() */

/******************************************************************************
Function Name   : usb_pstd_SetStallPipe0
Description     : Set pipe "0" PID to STALL.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel.
Return value    : none
******************************************************************************/
void usb_pstd_SetStallPipe0(USB_UTR_t *ptr)
{
    /* PIPE control reg set */
    usb_creg_set_pid( ptr, USB_PIPE0, USB_PID_STALL );
} /* eof usb_pstd_SetStallPipe0() */


/************/
/*  SYSCFG  */
/************/

/******************************************************************************
Function Name   : usb_preg_set_dprpu
Description     : Set DPRPU-bit SYSCFG register.
                : (Enable D+Line pullup when PeripheralController function is selected) 
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_set_dprpu( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD |= USB_DPRPU;
} /* eof usb_preg_set_dprpu() */

/******************************************************************************
Function Name   : usb_preg_clr_dprpu
Description     : Clear DPRPU-bit of the SYSCFG register.
                : (Disable D+Line pullup when PeripheralController function is 
                : selected.)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_clr_dprpu( USB_UTR_t *ptr )
{
    ptr->ipp->SYSCFG.WORD &= ~USB_DPRPU;
} /* eof usb_preg_clr_dprpu() */

/************/
/* SYSSTS0  */
/************/

/**************/
/*  DVSTCTR0  */
/**************/
/******************************************************************************
Function Name   : usb_preg_set_wkup
Description     : Set WKUP-bit DVSTCTR register.
                : (Output Remote wakeup signal when PeripheralController function is selected)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_set_wkup( USB_UTR_t *ptr )
{
    ptr->ipp->DVSTCTR0.WORD |= USB_WKUP;
} /* eof usb_preg_set_wkup() */

/**************/
/* TESTMODE  */
/**************/

/************/
/* PINCFG  */
/************/

/**********************************/
/*  DMA0CFG, DMA1CFG  for 597ASSP */
/**********************************/

/***************************/
/*  CFIFO, D0FIFO, D1FIFO  */
/***************************/

/**********************************/
/* CFIFOSEL, D0FIFOSEL, D1FIFOSEL */
/**********************************/

/**********************************/
/* CFIFOCTR, D0FIFOCTR, D1FIFOCTR */
/**********************************/

/*************/
/* INTENB0  */
/*************/
/******************************************************************************
Function Name   : usb_preg_set_enb_rsme
Description     : Enable interrupt from RESUME
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_set_enb_rsme( USB_UTR_t *ptr )
{
    ptr->ipp->INTENB0.WORD |= USB_RSME;
} /* eof usb_preg_set_enb_rsme() */

/******************************************************************************
Function Name   : usb_preg_clr_enb_rsme
Description     : Disable interrupt from RESUME
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_clr_enb_rsme( USB_UTR_t *ptr )
{
    ptr->ipp->INTENB0.WORD &= ~USB_RSME;
} /* eof usb_preg_set_enb_rsme() */

/*************/
/* INTENB1  */
/*************/

/*************/
/* BRDYENB  */
/*************/

/*************/
/* NRDYENB  */
/*************/

/*************/
/* BEMPENB  */
/*************/

/************/
/* SOFCFG   */
/************/

/************/
/* INTSTS0  */
/************/
/******************************************************************************
Function Name   : usb_preg_clr_sts_resm
Description     : Clear interrupt status of RESUME.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_clr_sts_resm( USB_UTR_t *ptr )
{
    ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_RESM;
} /* eof usb_preg_clr_sts_resm() */

/******************************************************************************
Function Name   : usb_preg_clr_sts_dvst
Description     : Clear Device State Transition interrupt flag. 
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_clr_sts_dvst( USB_UTR_t *ptr )
{
    ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_DVST;
} /* eof usb_preg_clr_sts_dvst() */

/******************************************************************************
Function Name   : usb_preg_clr_sts_ctrt
Description     : Clear Control Transfer Stage Transition interrupt flag.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_clr_sts_ctrt( USB_UTR_t *ptr )
{
    ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_CTRT;
} /* eof usb_preg_clr_sts_dvst() */

/******************************************************************************
Function Name   : usb_preg_clr_sts_valid
Description     : Clear the Setup Packet Reception interrupt flag.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_clr_sts_valid( USB_UTR_t *ptr )
{
    ptr->ipp->INTSTS0.WORD = (uint16_t)~USB_VALID;
} /* eof usb_preg_clr_sts_valid() */

/************/
/* INTSTS1  */
/************/

/************/
/* BRDYSTS  */
/************/

/************/
/* NRDYSTS  */
/************/

/************/
/* BEMPSTS  */
/************/

/************/
/* FRMNUM   */
/************/

/************/
/* USBADDR  */
/************/

/************/
/* USBREQ   */
/************/

/************/
/* USBVAL   */
/************/

/************/
/* USBINDX  */
/************/

/************/
/* USBLENG  */
/************/

/************/
/* DCPCFG   */
/************/

/************/
/* DCPMAXP  */
/************/

/************/
/* DCPCTR   */
/************/
/******************************************************************************
Function Name   : usb_preg_clr_sts_valid
Description     : Enable termination of control transfer status stage.
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void    usb_preg_set_ccpl( USB_UTR_t *ptr )
{
    ptr->ipp->DCPCTR.WORD |= USB_CCPL;
} /* eof usb_preg_set_ccpl() */

/************/
/* PIPESEL  */
/************/

/************/
/* PIPECFG  */
/************/

/************/
/* PIPEBUF  */
/************/

/************/
/* PIPEMAXP */
/************/

/************/
/* PIPEPERI */
/************/

/********************/
/* DCPCTR, PIPEnCTR  */
/********************/

/************/
/* PIPEnTRE */
/************/

/************/
/* PIPEnTRN */
/************/

/************/
/* DEVADDn  */
/************/
//#pragma end


#pragma section _pcdc


/******************************************************************************
Function Name   : usb_open_pcdc
Description     : Peripheral CDC Class Open Process
Argument        : USB_UTR_t *ptr            : IP Information(Mode,IP No.,Reg Address)
                : struct usb_fninfo *p_fnstr : File Structure pointer
                : uint8_t devadr             : Device address
                : uint8_t speed              : Device connected speed
Return          : Process rusult(NG(-1), OK(0))
******************************************************************************/
int16_t usb_open_pcdc( USB_UTR_t *ptr, struct usb_fninfo *p_fnstr, uint8_t devadr, uint8_t speed )
{
    uint16_t    buf, pipeno, start_pipe_no, end_pipe_no;

    /* Check complete Enumeration for Host CDC */
    if( USB_ON != usb_pcdc_is_connected() )
    {
//      usb_pcdc_classErrorInfo = ;
        /* Error end when not complete Enumeration */
        return (int16_t)-1;
    }

    /* Check Open request is Data Class ? */
    if( ptr->keyword == USB_CLASS_PCDCD )
    {
        /* When Data Class resource are Pipe1 to Pipe2 */
        start_pipe_no = USB_PIPE1;
        end_pipe_no = USB_PIPE2;
    }
    else if( ptr->keyword == USB_CLASS_PCDCC )
    {
        /* When Communications Class resource is Pipe6 */
        start_pipe_no = USB_PIPE6;
        end_pipe_no = USB_PIPE6;
    }
    else
    {
//      usb_pcdc_classErrorInfo = ;
        return (int16_t)-1;
    }

    /* Search use Pipe number for USB TX and RX */
    for( pipeno = start_pipe_no; pipeno <= end_pipe_no; pipeno++ )
    {
        /* Get from pipe information table USB transfer direction */
        buf = usb_get_pipedir( usb_gpcdc_EpTbl1, pipeno );
        /* Check get pipe information */
        if( USB_NG == buf )
        {
//          usb_pcdc_classErrorInfo = ;
            return (int16_t)-1;
        }
        else
        {
            /* Check transfer direction is IN pipe ? */
            if( buf == USB_DIR_P_IN )
            {
                p_fnstr->inPipeNo = pipeno;         /* Pipe number registration for RX. */
            }
            else
            {
                p_fnstr->outPipeNo = pipeno;        /* Pipe number registration for TX. */
            }
        }
    }

    /* usb_fnInfo[FileNumber] target block is complete open */
    p_fnstr->isOpened       = USB_YES;

    /* Registration read(),write() function for PCDC TX ans RX  */
    p_fnstr->class_read     = &usb_pcdc_read_data;
    p_fnstr->class_write    = &usb_pcdc_write_data;
    /* Registration close() function for PCDC close  */
    p_fnstr->close_func     = &usb_close_peri;          /* Set close function of Peripheral */

    p_fnstr->usb_ip     = USB_PERI_USBIP_NUM;                       /* IP number(0or1) */
    p_fnstr->usb_ipp    = usb_cstd_GetUsbIpAdr(p_fnstr->usb_ip);    /* IP Address(USB0orUSB1) */

    return  USB_OK;
}   /* eof usb_open_pcdc() */

/******************************************************************************
Function Name   : usb_pcdc_read_data
Description     : Peripheral pipe receive process
Argument        : int16_t fn             : File No.
                : void *buf              : Receive data store address
                : uint32_t length        : Receive data size
Return          : Receive size
******************************************************************************/
int32_t usb_pcdc_read_data( int16_t fn, void *buf, uint32_t length )
{
    USB_MH_t            p_blf;
    USB_ER_t            err;
    USB_CLSINFO_t       *cp;

    /* Get mem pool blk */
    if( R_USB_PGET_BLK(USB_PCDC_MPL, &p_blf) == USB_E_OK )
    {
        cp = (USB_CLSINFO_t*)p_blf;
        cp->msghead = (USB_MH_t)NULL;
        cp->msginfo = USB_PCDC_PRECEIVE_DATA;       /* Set Message informaion : Receive data */
        cp->fn = fn;                                /* FileNumber Set */
        cp->tranadr = buf;                          /* Receive data store address */
        cp->tranlen = length;                       /* Receive data size */

        /* Send message */
        err = R_USB_SND_MSG( USB_PCDC_MBX, (USB_MSG_t*)cp );
        if( err == USB_E_OK )
        {
            /* Transfer Start request send OK */
            usb_fnInfo[fn].read_state = USB_CTL_ERR_PROCESS_WAIT;
        }
        else
        {
            /* error */
            err = R_USB_REL_BLK(USB_PCDC_MPL,(USB_MH_t)p_blf);
            USB_PRINTF0( "### usb_pcdc_read_data function snd_msg error\n");
            /* Transfer Start request send NG */
            usb_fnInfo[fn].read_state = USB_CTL_ERR_PROCESS_ERR;
        }
    }
    else
    {
        /* error */
        USB_PRINTF0( "### usb_pcdc_read_data function pget_blk error\n");
        /* Get mem pool blk NG */
        usb_fnInfo[fn].read_state = USB_CTL_ERR_PROCESS_ERR;
    }

    return -1;
}   /* eof usb_pcdc_read_data() */

/******************************************************************************
Function Name   : usb_pcdc_write_data
Description     : Peripheral pipe send process
Argument        : int16_t fn             : File No.
                : void *buf              : Send data store address
                : uint32_t length        : Send data size
Return          : Send size
******************************************************************************/
int32_t usb_pcdc_write_data( int16_t fn, void *buf, uint32_t length )
{
    USB_MH_t            p_blf;
    USB_ER_t            err;
    USB_CLSINFO_t       *cp;

    /* Get mem pool blk */
    if( R_USB_PGET_BLK(USB_PCDC_MPL, &p_blf) == USB_E_OK )
    {
        cp = (USB_CLSINFO_t*)p_blf;
        cp->msghead = (USB_MH_t)NULL;
        cp->msginfo = USB_PCDC_PSEND_DATA;  /* Set Message information : Transfer data */
        cp->fn = fn;                        /* FileNumber Set */
        cp->tranadr = buf;                  /* Send data store address */
        cp->tranlen = length;               /* Send data size */

        /* Send message */
        err = R_USB_SND_MSG( USB_PCDC_MBX, (USB_MSG_t*)cp );
        if( err == USB_E_OK )
        {
            /* Transfer Start request send OK */
            usb_fnInfo[fn].write_state = USB_CTL_ERR_PROCESS_WAIT;
        }
        else
        {
            /* error */
            err = R_USB_REL_BLK(USB_PCDC_MPL,(USB_MH_t)p_blf);
            USB_PRINTF0( "### usb_pstd_write_data function snd_msg error\n");
        }
    }
    else
    {
        /* error */
        USB_PRINTF0( "### usb_pstd_write_data function pget_blk error\n");
        /* Get mem pool blk NG */
        usb_fnInfo[fn].write_state = USB_CTL_ERR_PROCESS_ERR;
    }

    return -1;
}   /* eof usb_pcdc_write_data() */
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */



/******************************************************************************
Function Name   : R_usb_pcdc_task
Description     : Call Peripheral CDC task
Arguments       : USB_VP_INT_t stacd        : start code
Return value    : none
******************************************************************************/
void R_usb_pcdc_task(USB_VP_INT_t stacd)
{
    /* Peripheral CDC Task call */
    usb_pcdc_task( stacd );
} /* eof R_usb_pcdc_task */

/******************************************************************************
Function Name   : R_usb_pcdc_set_interface
Description     : Set_Interface
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : uint16_t data1       ; Not use
                : uint16_t data2       ; Not use
Return value    : none
******************************************************************************/
void R_usb_pcdc_set_interface(USB_UTR_t *ptr, uint16_t data1, uint16_t data2)
{
} /* eof R_usb_pcdc_set_interface */

/******************************************************************************
Function Name   : R_usb_pcdc_descriptor_change
Description     : Descriptor change
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : uint16_t mode        ; Speed mode
                : uint16_t data2       ; Not use
Return value    : none
******************************************************************************/
void R_usb_pcdc_descriptor_change(USB_UTR_t *ptr, uint16_t mode, uint16_t data2)
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

#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
    usb_gpcdc_Inpipe    = usb_gpcdc_EpTbl1[0];              /* Pipe no. set for Data Class TX(BulkIn) */
    usb_gpcdc_Outpipe   = usb_gpcdc_EpTbl1[USB_EPL];        /* Pipe no. set for Data Class RX(BulkOut) */
    usb_gpcdc_Status_pipe = usb_gpcdc_EpTbl1[USB_EPL*2];    /* Pipe no. set for Communications Class */
#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */
} /* eof R_usb_pcdc_descriptor_change */

#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
/******************************************************************************
Function Name   : R_usb_pcdc_SendData
Description     : Data send request for Host
Arguments       : USB_UTR_t     *ptr        ; USB system internal structure. Selects channel.
                : uint8_t       *Table      ; Pointer to Data stored buffer 
                : uint32_t      size        ; Data size
                : USB_CB_INFO_t complete    ; Pointer to Callback function
Return value    : none
******************************************************************************/
void R_usb_pcdc_SendData(USB_UTR_t *ptr, uint8_t *Table, uint32_t size, USB_CB_t complete)
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
        cp->msginfo = (uint16_t)USB_PCDC_PSEND_DATA;            /* Set message information. */
        cp->keyword = (uint16_t)USB_NOT_USED;                   /* Not use */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->tranadr = (void *)Table;                            /* Transfer data Start address */
        cp->tranlen = (uint32_t)size;                           /* Transfer data length */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            /* Send message failure */
            USB_PRINTF1( "### pcdcSendData snd_msg error (%ld)\n", err );
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcSendData rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcSendData pget_blk error (%ld)\n", err );
    }
} /* eof R_usb_pcdc_SendData */

/******************************************************************************
Function Name   : R_usb_pcdc_ReceiveData
Description     : Data Receive request for Host
Arguments       : USB_UTR_t     *ptr        ; USB system internal structure. Selects channel.
                : uint8_t       *Table      ; Pointer to Data stored buffer 
                : uint32_t      size        ; Data size
                : USB_CB_INFO_t complete    ; Pointer to Callback function
Return value    : none
******************************************************************************/
void R_usb_pcdc_ReceiveData(USB_UTR_t *ptr, uint8_t *Table, uint32_t size, USB_CB_t complete)
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
        cp->msginfo = (uint16_t)USB_PCDC_PRECEIVE_DATA;         /* Set message information. */
        cp->keyword = (uint16_t)USB_NOT_USED;                   /* Not use */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->tranadr = (void *)Table;                            /* Transfer data Start address */
        cp->tranlen = (uint32_t)size;                           /* Transfer data length */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            /* Send message failure */
            USB_PRINTF1( "### pcdcReceiveData snd_msg error (%ld)\n", err );
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcReceiveData rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcReceiveData pget_blk error (%ld)\n", err );
    }
} /* eof R_usb_pcdc_ReceiveData */

/******************************************************************************
Function Name   : R_usb_pcdc_SerialStateNotification
Description     : Class Notification Serial State for USB Host
Arguments       : USB_UTR_t *ptr           ; USB system internal structure. Selects channel.
                : uint16_t  serial_state   ; State of UART
                : USB_CB_INFO_t complete   ; Pointer to Callback function
Return value    : none
******************************************************************************/
void R_usb_pcdc_SerialStateNotification(USB_UTR_t *ptr, uint16_t serial_state, USB_CB_t complete)
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
        cp->msginfo = (uint16_t)USB_PCDC_PSERIAL_STATE_NOTIFICATION;    /* Set message information. */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* UART State bitmap set */
        usb_gpcdc_SerialState_Table[8] = (uint8_t)(serial_state & 0xff);
        usb_gpcdc_SerialState_Table[9] = (uint8_t)(serial_state >> 8);

        /* Transfer data Start address */
        cp->tranadr = (void *)&usb_gpcdc_SerialState_Table[0];
        /* Transfer data length */
        cp->tranlen = (uint32_t)10;

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            /* Send message failure */
            USB_PRINTF1( "### pcdcSerialStateNotification snd_msg error (%ld)\n", err );
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcSerialStateNotification rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcSerialStateNotification pget_blk error (%ld)\n", err );
    }
} /* eof R_usb_pcdc_SerialStateNotification */
#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */

/******************************************************************************
Function Name   : R_usb_pcdc_driver_start
Description     : USB Vendor Peripheral Driver Start
Argument        : none
Return          : none
******************************************************************************/
void R_usb_pcdc_driver_start( void )
{
    R_usb_cstd_SetTaskPri(USB_PCDC_TSK, USB_PRI_4);
} /* eof R_usb_pcdc_driver_start */

/******************************************************************************
Function Name   : R_usb_pcdc_usr_ctrl_trans_function
Description     : Class request processing for CDC 
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *preq  ; Class request information
                : uint16_t ctsq        ; Control Stage
Return value    : none
******************************************************************************/
void R_usb_pcdc_usr_ctrl_trans_function(USB_UTR_t *ptr, USB_REQUEST_t *preq, uint16_t ctsq)
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
        USB_PRINTF2("R_usb_pcdc_usr_ctrl_trans_function Err: %x %x\n"
            , preq->ReqTypeType, ctsq);
        usb_pstd_SetStallPipe0( ptr );
    }
} /* eof R_usb_pcdc_usr_ctrl_trans_function */



/******************************************************************************
Function Name   : usb_pcdc_task
Description     : Peripheral Communications Devices Class main task
Arguments       : USB_VP_INT_t stacd        : start code
Return value    : none
******************************************************************************/
void usb_pcdc_task(USB_VP_INT_t stacd)
{
    uint16_t ret;
    USB_UTR_t   *mess;
    USB_ER_t    err = 0l;

    /* Pipe Transfer */
    err = R_USB_TRCV_MSG( USB_PCDC_MBX, (USB_MSG_t**)&mess, (uint16_t)3000 );
    if( err == USB_E_OK )
    {
        switch( mess->msginfo  )
        {
        /* Get Line Coding */
        case USB_PCDC_PGET_LINE_CODING:
            /* CallBack function (SND_MSG) */
            (*mess->complete)(mess, 0, 0 );

            err = USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1( "### pcdcTask case else rel_blk error (%ld)\n", err);
            }
            break;

        /* CDC Class Request Set Line Coding */
        case USB_PCDC_PSET_LINE_CODING:
            /* Line coding set parameter check */
            ret = usb_cpu_Sci_SetDataChk(
                (uint8_t *)&usb_gcdc_LineCodingReq.dwDTERate
                , usb_gcdc_LineCodingReq.bCharFormat
                , usb_gcdc_LineCodingReq.bParityType
                , usb_gcdc_LineCodingReq.bDataBits);
            if( ret == USB_OK )
            {
                /* Line Coding Parameter set */
                memcpy(&usb_gcdc_LineCoding,&usb_gcdc_LineCodingReq,7);
#ifdef USB_UART_ENABLE
                /* Line coding set */
                usb_cpu_Sci_Set1((uint8_t *)&usb_gcdc_LineCoding.dwDTERate
                    , usb_gcdc_LineCoding.bCharFormat
                    , usb_gcdc_LineCoding.bParityType
                    , usb_gcdc_LineCoding.bDataBits);
#endif  /* USB_UART_ENABLE */
            }

            /* CallBack function (SND_MSG) */
            (*mess->complete)(mess, 0, 0 );

            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1( "### pcdcTask case else rel_blk error (%ld)\n", err);
            }
            break;

        /* CDC Class Request Set Control Line State */
        case USB_PCDC_PSET_CONTROL_LINE_STATE:
            /* RS-232 signal RTS & DTR Set */
            /* If RTS/DTR control function is prepared, calls this function here */

            /* CallBack function (SND_MSG) */
            (*mess->complete)(mess, 0, 0 );

            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1( "### pcdcTask case else rel_blk error (%ld)\n", err);
            }
            break;

        /* CDC Class Request Send Break */
        case USB_PCDC_PSEND_BREAK:
            /* RS-232 style break */
            /* If BREAK signal output function is prepared, calls this function here */

            /* CallBack function (SND_MSG) */
            (*mess->complete)(mess, 0, 0 );
            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1( "### pcdcTask case else rel_blk error (%ld)\n", err);
            }
            break;

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
        case USB_PCDC_PSERIAL_STATE_NOTIFICATION:
        case USB_PCDC_PSEND_DATA:
            usb_fnInfo[mess->fn].write_length = mess->tranlen;

            mess->complete = &usb_pcdc_InTransResult;
            mess->ip = usb_fnInfo[mess->fn].usb_ip;
            mess->ipp = usb_fnInfo[mess->fn].usb_ipp;

            err = usb_pcdc_UserDataTrans( mess, usb_fnInfo[mess->fn].inPipeNo, mess->tranlen, mess->tranadr);
            /* Transfer Start request check */
            if( err != USB_OK )
            {
                /* Transfer Start request NG */
                usb_fnInfo[mess->fn].write_state = USB_CTL_ERR_PROCESS_ERR;

                /* User application call back */
                usb_fnInfo[mess->fn].write_length = -1;
//              (*usb_fnInfo[mess->fn].write_complete)( mess, 0, 0 );
            }

            /* Class Notification Serial State for USB Host */
            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1("### pcdcTask SerialStateTx rel_blk error (%ld)\n", err);
            }
            break;

        case USB_PCDC_PRECEIVE_DATA:
            usb_fnInfo[mess->fn].read_length = mess->tranlen;

            mess->complete = &usb_pcdc_OutTransResult;
            mess->ip = usb_fnInfo[mess->fn].usb_ip;
            mess->ipp = usb_fnInfo[mess->fn].usb_ipp;

            err = usb_pcdc_UserDataTrans(mess, usb_fnInfo[mess->fn].outPipeNo, mess->tranlen, mess->tranadr);
            /* Transfer Start request check */
            if( err != USB_OK )
            {
                /* Transfer Start request NG */
                usb_fnInfo[mess->fn].read_state = USB_CTL_ERR_PROCESS_ERR;

                /* User application call back */
                usb_fnInfo[mess->fn].read_length = -1;
//              (*usb_fnInfo[mess->fn].read_complete)( mess, 0, 0 );
            }

            /* Class Notification Serial State for USB Host */
            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1("### pcdcTask SerialStateTx rel_blk error (%ld)\n", err);
            }
            break;
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
        case USB_PCDC_PSEND_DATA:
            usb_gpcdc_TxCB  = (USB_CB_t)mess->complete;

            mess->complete = &usb_pcdc_InTransResult;
            /* Data send request for Host */
            err = usb_pcdc_UserDataTrans(mess, usb_gpcdc_Inpipe, mess->tranlen, mess->tranadr);

            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1("### pcdcTask SendData rel_blk error (%ld)\n", err);
            }
            break;
        case USB_PCDC_PRECEIVE_DATA:
            usb_gpcdc_RxCB  = (USB_CB_t)mess->complete;

            mess->complete = &usb_pcdc_OutTransResult;
            /* Data Receive request for Host */
            err = usb_pcdc_UserDataTrans(mess, usb_gpcdc_Outpipe, mess->tranlen, mess->tranadr);

            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1("### pcdcTask ReceiveData rel_blk error (%ld)\n", err);
            }
            break;
        case USB_PCDC_PSERIAL_STATE_NOTIFICATION:
            usb_gpcdc_StatCB    = (USB_CB_t)mess->complete;

            mess->complete = &usb_pcdc_StatusTransResult;
            /* Serial State send request for Host */
            err = usb_pcdc_UserDataTrans(mess, usb_gpcdc_Status_pipe, mess->tranlen, mess->tranadr);

            /* Class Notification Serial State for USB Host */
            err = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)mess);
            if( err != USB_E_OK )
            {
                USB_PRINTF1("### pcdcTask SerialStateTx rel_blk error (%ld)\n", err);
            }
            break;
        case USB_PCDC_PDATASND:
            /* Data Send Transfer complete call back */
            (usb_gpcdc_TxCB)(mess,0,0);
            break;
        case USB_PCDC_PDATARCV:
            /* Data Receive Transfer complete call back */
            (usb_gpcdc_RxCB)(mess,0,0);
            break;
        case USB_PCDC_PSTATUSSND:
            /* Status Send Transfer complete call back */
            (usb_gpcdc_StatCB)(mess,0,0);
            break;
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
        default:
            break;
        }
    }
} /* eof usb_pcdc_task */


/******************************************************************************
Function Name   : usb_pcdc_SetControlLineState_req
Description     : Class request processing for SetControlLineState request
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_pcdc_SetControlLineState_req(USB_UTR_t *ptr)
{
    /* Class request Set_Control_Line_State */
    usb_pcdc_SetControlLineState(ptr, &usb_cstd_DummyFunction);
} /* eof usb_pcdc_SetControlLineState_req */

/******************************************************************************
Function Name   : usb_pcdc_SetLineCoding_req
Description     : Class request processing for SetLineCoding request
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_pcdc_SetLineCoding_req(USB_UTR_t *ptr)
{
    /* Class request Set_Line_Coding */
    usb_pcdc_SetLineCoding(ptr, &usb_cstd_DummyFunction);
} /* eof usb_pcdc_SetLineCoding_req */

/******************************************************************************
Function Name   : usb_pcdc_GetLineCoding_req
Description     : Class request processing for GetLineCoding request
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_pcdc_GetLineCoding_req(USB_UTR_t *ptr)
{
    /* Class request Get_Line_Coding */
    usb_pcdc_GetLineCoding(ptr, &usb_cstd_DummyFunction);
} /* eof usb_pcdc_GetLineCoding_req */

/******************************************************************************
Function Name   : usb_pcdc_SendBreak_req
Description     : Class request processing for SendBreak request
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
Return value    : none
******************************************************************************/
void usb_pcdc_SendBreak_req(USB_UTR_t *ptr)
{
    /* Class request Get_Line_Coding */
    usb_pcdc_SendBreak(ptr, &usb_cstd_DummyFunction);
} /* eof usb_pcdc_SendBreak_req */

/******************************************************************************
Function Name   : usb_pcdc_UserDataTrans
Description     : Data Transfer Processing to USB Host
Argument        : USB_UTR_t *ptr   ; USB system internal structure. Selects channel.
                : uint16_t pipe    ; Pipe No
                : uint32_t size    ; Size
                : uint8_t  *table  ; Transfer Data Start address
Return          : USB_ER_t         ; 
******************************************************************************/
USB_ER_t usb_pcdc_UserDataTrans(USB_UTR_t *ptr, uint16_t pipe, uint32_t size, uint8_t *table)
{   
    /* PIPE Transfer set */
    usb_gpcdc_Mess[pipe].msghead    = (USB_MH_t)NULL;
    usb_gpcdc_Mess[pipe].keyword    = pipe;
    usb_gpcdc_Mess[pipe].tranadr    = table;
    usb_gpcdc_Mess[pipe].tranlen    = size;
    usb_gpcdc_Mess[pipe].setup  = 0;
    usb_gpcdc_Mess[pipe].complete   = ptr->complete;
    usb_gpcdc_Mess[pipe].segment    = USB_TRAN_END;

    usb_gpcdc_Mess[pipe].ipp        = ptr->ipp;
    usb_gpcdc_Mess[pipe].ip     = ptr->ip;

    usb_gpcdc_Mess[pipe].fn     = ptr->fn;

    return( R_usb_pstd_TransferStart((USB_UTR_t *)&usb_gpcdc_Mess[pipe]) );
} /* eof usb_pcdc_UserDataTrans */

#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
/******************************************************************************
Function Name   : usb_pcdc_StatusTransResult
Description     : CallBack Function
Arguments       : USB_UTR_t *mess  ; Information of the result when UART state is sent to Host
                : uint16_t  data1  ; Not use
                : uint16_t  data2  ; Not use 
Return value    : none
******************************************************************************/
void usb_pcdc_StatusTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2)
{
    USB_ER_t    err;

    /* From USB device to PCDC */
    mess->msginfo = (uint16_t)USB_PCDC_PSTATUSSND;
    if( mess->status == USB_DATA_STOP )
    {
        USB_PRINTF0("### Peripheral Communications Devices driver stoped !\n");
    }
    err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)mess);
    if( err != USB_E_OK )
    {
        /* Send message failure */
        USB_PRINTF1("### pcdcTransResult snd_msg error (%ld)\n", err);
    }
} /* eof usb_pcdc_StatusTransResult */
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

/******************************************************************************
Function Name   : usb_pcdc_InTransResult
Description     : IN Data Transfer Callback Function 
Argument        : USB_UTR_t *mess       ; IN Transfer result information
                : uint16_t  data1       ; Not use
                : uint16_t  data2       ; Not use
Return          : none
******************************************************************************/
void usb_pcdc_InTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2)
{
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    /* Get File No. */
    if( mess->fn != -1 )
    {
        /* Write complete */
        usb_fnInfo[mess->fn].write_state = USB_CTL_ERR_PROCESS_COMPLETE;
        /* Transfer Status check */
        if(mess->status != USB_DATA_NONE)
        {
            /* Transfer NG */
            usb_fnInfo[mess->fn].write_length = -1;
        }
        (*usb_fnInfo[mess->fn].write_complete)( mess, 0, 0 );
    }
    else
    {
        /* Error loop */
//      while(1);
    }
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
    USB_ER_t    err;

    /* From USB device to PCDC */
    mess->msginfo = (uint16_t)USB_PCDC_PDATASND;
    if( mess->status == USB_DATA_STOP )
    {
        USB_PRINTF0("### Peripheral Comm Devices driver stoped !\n");
    }
    err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)mess);
    if( err != USB_E_OK )
    {
        /* Send message failure */
        USB_PRINTF1("### pcdcTransResult snd_msg error (%ld)\n", err);
    }
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
} /* eof usb_pcdc_InTransResult */

/******************************************************************************
Function Name   : usb_pcdc_OutTransResult
Description     : OUT Data Transfer Callback Function 
Argument        : USB_UTR_t *mess      ; OUT Transfer result information
                : uint16_t  data1      ; Not use
                : uint16_t  data2      ; Not use
Return          : none
******************************************************************************/
void usb_pcdc_OutTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2)
{
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    /* Get File No. */
    if( mess->fn != -1 )
    {
        /* Read complete */
        usb_fnInfo[mess->fn].read_state = USB_CTL_ERR_PROCESS_COMPLETE;
        if(mess->status == USB_DATA_OK)
        {
            /* Receive size = Request size */
        }
        else if(mess->status == USB_DATA_SHT)
        {
            /* Receive size < Request size */
            usb_fnInfo[mess->fn].read_length -= mess->tranlen;
        }
        else
        {
            usb_fnInfo[mess->fn].read_length = -1;
        }
        (*usb_fnInfo[mess->fn].read_complete)( mess, 0, 0 );
    }
    else
    {
        /* Error loop */
//      while(1);
    }
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
    USB_ER_t    err;

    /* From USB device to PCDC */
    mess->msginfo = (uint16_t)USB_PCDC_PDATARCV;
    if( mess->status == USB_DATA_STOP )
    {
        USB_PRINTF0("### Peripheral Comm Devices driver stoped !\n");
    }
    err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)mess);
    if( err != USB_E_OK )
    {
        /* Send message failure */
        USB_PRINTF1("### pcdcTransResult snd_msg error (%ld)\n", err);
    }
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
} /* eof usb_pcdc_OutTransResult */

/******************************************************************************
Function Name   : usb_get_pipedir
Description     : Get Pipe Divection
Argument        : uint16_t *tbl_p           ; Pipe Information Table address
                : uint16_t pipeno           ; Pipe No.
Return          : Pipe Direction or Error Statue(USB_NG)
******************************************************************************/
uint16_t usb_get_pipedir( uint16_t  *tbl_p, uint16_t pipeno )
{
    uint16_t    idx, buf;

    for( idx = 0; ; idx += USB_EPL )
    {
        if( *(tbl_p + idx) == pipeno )
        {
            buf = *(tbl_p + idx + 1);
            return ( buf & USB_DIRFIELD );
        }
    }
    return USB_NG;
} /* eof usb_get_pipedir */

/******************************************************************************
Function Name   : usb_pcdc_DataTrans
Description     : Tranfer data from USB
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : uint16_t pipe        ; Pipe No
                : uint32_t size        ; Data Size
                : uint8_t *table       ; Data address
                : USB_CB_t complete    ; Callback function
Return value    : none
******************************************************************************/
void usb_pcdc_DataTrans(USB_UTR_t *ptr, uint16_t pipe, uint32_t size, uint8_t *table, USB_CB_t complete)
{
    /* PIPE Transfer set */
    usb_gpcdc_Mess[pipe].keyword        = pipe;                 /* Pipe No */
    usb_gpcdc_Mess[pipe].tranadr        = table;                /* Data address */
    usb_gpcdc_Mess[pipe].tranlen        = size;                 /* Data Size */
    usb_gpcdc_Mess[pipe].setup          = 0;                    /* Non Setup */
    usb_gpcdc_Mess[pipe].complete       = complete;             /* Callback function */
    usb_gpcdc_Mess[pipe].segment        = USB_TRAN_END;         /* Utr member (segment) */
    usb_gpcdc_Mess[pipe].ip             = ptr->ip;              /* IP number(0or1) */
    usb_gpcdc_Mess[pipe].ipp            = ptr->ipp;             /* IP Address(USB0orUSB1) */

    R_usb_pstd_TransferStart(&usb_gpcdc_Mess[pipe]);            /* USB Transfer Start */
} /* eof usb_pcdc_DataTrans */


/******************************************************************************
Function Name   : usb_pcdc_ControlTrans1
Description     : Class request processing (control read)
Arguments       : USB_UTR_t *ptr       ; USB system internal structure. Selects channel.
                : USB_REQUEST_t *req   ; Class request information
Return value    : none
******************************************************************************/
void usb_pcdc_ControlTrans1(USB_UTR_t *ptr, USB_REQUEST_t *req)
{
    /* Is a request receive target Interface? */
    if( (req->ReqIndex == 0) && (req->ReqTypeRecip == USB_INTERFACE) )
    {
        /* Is a Request Type GetLineCoding? */
        if( req->ReqRequest == USB_PCDC_GET_LINE_CODING )
        {
            /* send get_line_coding */
            R_usb_pstd_ControlRead(ptr, (uint32_t)USB_PCDC_GET_LINE_CODING_LENGTH
                , (uint8_t *)&usb_gcdc_LineCodingReq);
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
        usb_cstd_SetBuf(ptr, (uint16_t)USB_PIPE0);          /* Set BUF */
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
        R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_CTRL_END);
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
            R_usb_pstd_ControlWrite(ptr, 7, (uint8_t *)&usb_gcdc_LineCodingReq);
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
    R_usb_pstd_ControlEnd(ptr, (uint16_t)USB_CTRL_END);
} /* eof usb_pcdc_ControlTrans5 */


/******************************************************************************
Function Name   : usb_pcdc_SetControlLineState
Description     : Peripheral Set Control Line State request
Arguments       : USB_UTR_t     *ptr        ; USB system internal structure. Selects channel.
                : USB_CB_INFO_t complete    ; Pointer to Callback function
Return value    : none
******************************************************************************/
void usb_pcdc_SetControlLineState(USB_UTR_t *ptr, USB_CB_INFO_t complete)
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
        cp->msginfo = (uint16_t)USB_PCDC_PSET_CONTROL_LINE_STATE;   /* Set message information. */
        cp->keyword = (uint16_t)USB_NOT_USED;                   /* Not use */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            /* Send message failure */
            USB_PRINTF1( "### pcdcSetControlLineState snd_msg error (%ld)\n", err);
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcSetControlLineState rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcSetControlLineState pget_blk error (%ld)\n", err);
    }
} /* eof usb_pcdc_SetControlLineState */

/******************************************************************************
Function Name   : usb_pcdc_SetLineCoding
Description     : Peripheral Set Line Coding request
Arguments       : USB_UTR_t     *ptr        ; USB system internal structure. Selects channel.
                : USB_CB_INFO_t complete    ; Pointer to Callback function
Return value    : none
******************************************************************************/
void usb_pcdc_SetLineCoding(USB_UTR_t *ptr, USB_CB_INFO_t complete)
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
        cp->msginfo = (uint16_t)USB_PCDC_PSET_LINE_CODING;      /* Set message information. */
        cp->keyword = (uint16_t)USB_NOT_USED;                   /* Not use */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            /* Send message failure */
            USB_PRINTF1( "### pcdcGetLineCoding snd_msg error (%ld)\n", err );
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcGetLineCoding rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcGetLineCoding pget_blk error (%ld)\n", err );
    }
} /* eof usb_pcdc_SetLineCoding */

/******************************************************************************
Function Name   : usb_pcdc_GetLineCoding
Description     : Peripheral Get Line Coding request
Arguments       : USB_UTR_t     *ptr        ; USB system internal structure. Selects channel.
                : USB_CB_INFO_t complete    ; Callback function
Return value    : none
******************************************************************************/
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
            /* Send message failure */
            USB_PRINTF1( "### pcdcSetLineCoding snd_msg error (%ld)\n", err );
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcSetLineCoding rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcSetLineCoding pget_blk error (%ld)\n", err );
    }
} /* eof usb_pcdc_GetLineCoding */

/******************************************************************************
Function Name   : usb_pcdc_SendBreak
Description     : Peripheral Send Break request
Arguments       : USB_UTR_t     *ptr        ; USB system internal structure. Selects channel.
                : USB_CB_INFO_t complete    ; Pointer to Callback function
Return value    : none
******************************************************************************/
void usb_pcdc_SendBreak(USB_UTR_t *ptr, USB_CB_INFO_t complete)
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
        cp->msginfo = (uint16_t)USB_PCDC_PSEND_BREAK;           /* Set message information. */
        cp->keyword = (uint16_t)USB_NOT_USED;                   /* Not use */
        cp->status      = (uint16_t)USB_NOT_USED;               /* Not use */
        cp->complete    = (USB_CB_t)complete;                   /* Set Callback function */
        cp->ip = ptr->ip;                                       /* IP number(0or1) */
        cp->ipp = ptr->ipp;                                     /* IP Address(USB0orUSB1) */

        /* Send message */
        err = R_USB_SND_MSG(USB_PCDC_MBX, (USB_MSG_t*)p_blf);
        if( err != USB_E_OK )
        {
            /* Send message failure */
            USB_PRINTF1( "### pcdcGetLineCoding snd_msg error (%ld)\n", err );
            err2 = R_USB_REL_BLK(USB_PCDC_MPL, (USB_MH_t)p_blf);
            if( err2 != USB_E_OK )
            {
                /* Release memoryblock failure */
                USB_PRINTF1( "### pcdcSendBreak rel_blk error (%ld)\n", err2 );
            }
        }
    }
    else
    {
        /* Get momoryblock failure */
        USB_PRINTF1( "### pcdcSendBreak pget_blk error (%ld)\n", err );
    }
} /* eof usb_pcdc_SendBreak */



/******************************************************************************
Private global variables and functions
******************************************************************************/
/* Configuration 1 */
uint16_t usb_gpcdc_EpTbl1[] =
{
    USB_PIPE1,
    USB_BULK | USB_BFREOFF | USB_DBLBON | USB_CNTMDOFF | USB_SHTNAKON
        | USB_DIR_P_IN | USB_EP1,
    (uint16_t)USB_BUF_SIZE(512u) | USB_BUF_NUMB(8u),
    USB_SOFT_CHANGE,
    USB_IFISOFF | USB_IITV_TIME(0u),
    USB_CUSE,

    USB_PIPE2,
    USB_BULK | USB_BFREOFF | USB_DBLBON | USB_CNTMDOFF | USB_SHTNAKON
        | USB_DIR_P_OUT | USB_EP2,
    (uint16_t)USB_BUF_SIZE(512u) | USB_BUF_NUMB(24u),
    USB_SOFT_CHANGE,
    USB_IFISOFF | USB_IITV_TIME(0u),
    USB_CUSE,

    USB_PIPE6,
    USB_INT  | USB_DIR_P_IN | USB_EP3,
    (uint16_t)USB_BUF_SIZE(64u) | USB_BUF_NUMB(4u),
    16u,
    USB_IITV_TIME(0u),
    USB_CUSE,

/* Pipe end */
    USB_PDTBLEND,
};

/* Configuration 2 */
uint16_t usb_gpcdc_EpTbl2[] =
{
    0
};
/* Configuration 3 */
uint16_t usb_gpcdc_EpTbl3[] =
{
    0
};
/* Configuration 4 */
uint16_t usb_gpcdc_EpTbl4[] =
{
    0
};
/* Configuration 5 */
uint16_t usb_gpcdc_EpTbl5[] =
{
    0
};


uint16_t *usb_gpcdc_EpPtr[] =
{
    usb_gpcdc_EpTbl1,
    usb_gpcdc_EpTbl2,
    usb_gpcdc_EpTbl3,
    usb_gpcdc_EpTbl4,
    usb_gpcdc_EpTbl5
};

/******************************************************************************
Private global variables and functions
******************************************************************************/

/* Standard Device Descriptor */
uint8_t usb_gpcdc_DeviceDescriptor
    [ USB_PCDC_DD_BLENGTH + ( USB_PCDC_DD_BLENGTH % 2 ) ] =
{
    /*  0:bLength */
    USB_PCDC_DD_BLENGTH,
    /*  1:bDescriptorType */
    USB_DT_DEVICE,
    /*  2:bcdUSB_lo */
    (USB_BCDNUM                     & (uint8_t)0xffu),
    /*  3:bcdUSB_hi */
    ((uint8_t)(USB_BCDNUM >> 8)     & (uint8_t)0xffu),
    /*  4:bDeviceClass */
    USB_IFCLS_CDCC,
    /*  5:bDeviceSubClass */
    0,
    /*  6:bDeviceProtocol */
    0,
    /*  7:bMAXPacketSize(for DCP) */
    (uint8_t)USB_DCPMAXP,
    /*  8:idVendor_lo */
    (USB_VENDORID                   & (uint8_t)0xffu),
    /*  9:idVendor_hi */
    ((uint8_t)(USB_VENDORID >> 8)   & (uint8_t)0xffu),
    /* 10:idProduct_lo */
    ((uint16_t)USB_PRODUCTID        & (uint8_t)0xffu),
    /* 11:idProduct_hi */
    ((uint8_t)(USB_PRODUCTID >> 8)  & (uint8_t)0xffu),
    /* 12:bcdDevice_lo */
    (USB_RELEASE                    & (uint8_t)0xffu),
    /* 13:bcdDevice_hi */
    ((uint8_t)(USB_RELEASE >> 8)    & (uint8_t)0xffu),
    /* 14:iManufacturer */
    1,
    /* 15:iProduct */
    2,
    /* 16:iSerialNumber */
    6,
    /* 17:bNumConfigurations */
    USB_CONFIGNUM
};

/* Device Qualifier Descriptor */
uint8_t usb_gpcdc_QualifierDescriptor
    [ USB_PCDC_QD_BLENGTH + ( USB_PCDC_QD_BLENGTH % 2 ) ] =
{
    /*  0:bLength */
    USB_PCDC_QD_BLENGTH,
    /*  1:bDescriptorType */
    USB_DT_DEVICE_QUALIFIER,
    /*  2:bcdUSB_lo */
    (USB_BCDNUM                     & (uint8_t)0xffu),
    /*  3:bcdUSB_hi */
    ((uint8_t)(USB_BCDNUM >> 8)     & (uint8_t)0xffu),
    /*  4:bDeviceClass */
    0,
    /*  5:bDeviceSubClass */
    0,
    /*  6:bDeviceProtocol */
    0,
    /*  7:bMAXPacketSize(for DCP) */
    (uint8_t)USB_DCPMAXP,
    /*  8:bNumConfigurations */
    USB_CONFIGNUM,
    /*  9:bReserved */
    0
};


/************************************************************
 *  Configuration Or Other_Speed_Configuration Descriptor   *
 ************************************************************/
/* For Full-Speed */
uint8_t usb_gpcdc_ConfigrationF1
    [ USB_PCDC_CD1_BLENGTH + ( USB_PCDC_CD1_BLENGTH % 2 ) ] =
{
    9,                                  /*  0:bLength */
    USB_SOFT_CHANGE,                    /*  1:bDescriptorType */
    USB_PCDC_CD1_BLENGTH % 256,         /*  2:wTotalLength(L) */
    USB_PCDC_CD1_BLENGTH / 256,         /*  3:wTotalLength(H) */
    2,                                  /*  4:bNumInterfaces */
    1,                                  /*  5:bConfigurationValue */
    0,                                  /*  6:iConfiguration */
    USB_CF_RESERVED | USB_CF_SELFP,     /*  7:bmAttributes */
    (10 / 2),                           /*  8:MAXPower (2mA unit) */

    /* Interface Descriptor */
        9,                              /*  0:bLength */
        USB_DT_INTERFACE,               /*  1:bDescriptor */
        0,                              /*  2:bInterfaceNumber */
        0,                              /*  3:bAlternateSetting */
        1,                              /*  4:bNumEndpoints */
        USB_IFCLS_CDCC,                 /*  5:bInterfaceClass */
                                        /*  6:bInterfaceSubClass */
        USB_PCDC_CLASS_SUBCLASS_CODE_ABS_CTR_MDL,
        1,                              /*  7:bInterfaceProtocol */
        0,                              /*  8:iInterface */

        /* Communications Class Functional Descriptorss */
            5,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,      /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_HEADER_FUNC,
            USB_PCDC_BCD_CDC % 256, /*  3:bcdCDC_lo */
            USB_PCDC_BCD_CDC / 256, /*  4:bcdCDC_hi */
        /* Communications Class Functional Descriptorss */
            4,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,          /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_ABSTRACT_CTR_MANAGE_FUNC,
            2,                          /*  3:bmCapabilities */
        /* Communications Class Functional Descriptorss */
            5,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,          /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_UNION_FUNC,
            0,                          /*  3:bMasterInterface */
            1,                          /*  4:bSlaveInterface0 */

        /* Communications Class Functional Descriptorss */
            5,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,      /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_CALL_MANAGE_FUNC,
            /* D1:1-Device can send/receive call management
                    information over a Data Class interface. */
            /* D0:1-Device handles call management itself. */
            3,                          /*  3:bmCapabilities */
            1,                          /*  4:bDataInterface */

        /* Endpoint Descriptor 0 */
            7,                          /*  0:bLength */
            USB_DT_ENDPOINT,            /*  1:bDescriptorType */
            USB_EP_IN  | USB_EP3,       /*  2:bEndpointAddress */
            USB_EP_INT,                 /*  3:bmAttribute */
            16,                         /*  4:wMAXPacketSize_lo */
            0,                          /*  5:wMAXPacketSize_hi */
            0x10,                       /*  6:bInterval */

    /* Interface Descriptor */
        9,                              /*  0:bLength */
        USB_DT_INTERFACE,               /*  1:bDescriptor */
        1,                              /*  2:bInterfaceNumber */
        0,                              /*  3:bAlternateSetting */
        2,                              /*  4:bNumEndpoints */
        USB_IFCLS_CDCD,                 /*  5:bInterfaceClass */
        0,                              /*  6:bInterfaceSubClass */
        0,                              /*  7:bInterfaceProtocol */
        0,                              /*  8:iInterface */

        /* Endpoint Descriptor 0 */
            7,                          /*  0:bLength */
            USB_DT_ENDPOINT,            /*  1:bDescriptorType */
            USB_EP_IN | USB_EP1,        /*  2:bEndpointAddress */
            USB_EP_BULK,                /*  3:bmAttribute */
            64,                         /*  4:wMAXPacketSize_lo */
            0,                          /*  5:wMAXPacketSize_hi */
            0,                          /*  6:bInterval */

        /* Endpoint Descriptor 1 */
            7,                          /*  0:bLength */
            USB_DT_ENDPOINT,            /*  1:bDescriptorType */
            USB_EP_OUT | USB_EP2,       /*  2:bEndpointAddress */
            USB_EP_BULK,                /*  3:bmAttribute */
            64,                         /*  4:wMAXPacketSize_lo */
            0,                          /*  5:wMAXPacketSize_hi */
            0,                          /*  6:bInterval */
};

uint8_t usb_gpcdc_ConfigrationH1
    [ USB_PCDC_CD1_BLENGTH + ( USB_PCDC_CD1_BLENGTH % 2 ) ] =
{
    9,                                  /*  0:bLength */
    USB_SOFT_CHANGE,                    /*  1:bDescriptorType */
    USB_PCDC_CD1_BLENGTH % 256,         /*  2:wTotalLength(L) */
    USB_PCDC_CD1_BLENGTH / 256,         /*  3:wTotalLength(H) */
    2,                                  /*  4:bNumInterfaces */
    1,                                  /*  5:bConfigurationValue */
    0,                                  /*  6:iConfiguration */
    USB_CF_RESERVED | USB_CF_SELFP,     /*  7:bmAttributes */
    (10 / 2),                           /*  8:MAXPower (2mA unit) */

    /* Interface Descriptor */
        9,                              /*  0:bLength */
        USB_DT_INTERFACE,               /*  1:bDescriptor */
        0,                              /*  2:bInterfaceNumber */
        0,                              /*  3:bAlternateSetting */
        1,                              /*  4:bNumEndpoints */
        USB_IFCLS_CDCC,                 /*  5:bInterfaceClass */
                                        /*  6:bInterfaceSubClass */
        USB_PCDC_CLASS_SUBCLASS_CODE_ABS_CTR_MDL,
        1,                              /*  7:bInterfaceProtocol */
        0,                              /*  8:iInterface */

        /* Communications Class Functional Descriptorss */
            5,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,      /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_HEADER_FUNC,
            USB_PCDC_BCD_CDC % 256, /*  3:bcdCDC_lo */
            USB_PCDC_BCD_CDC / 256, /*  4:bcdCDC_hi */
        /* Communications Class Functional Descriptorss */
            4,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,      /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_ABSTRACT_CTR_MANAGE_FUNC,
            2,                          /*  3:bmCapabilities */
        /* Communications Class Functional Descriptorss */
            5,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,      /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_UNION_FUNC,
            0,                          /*  3:bMasterInterface */
            1,                          /*  4:bSlaveInterface0 */

        /* Communications Class Functional Descriptorss */
            5,                          /*  0:bLength */
            USB_PCDC_CS_INTERFACE,      /*  1:bDescriptorType */
                                        /*  2:bDescriptorSubtype */
            USB_PCDC_DT_SUBTYPE_CALL_MANAGE_FUNC,
            /* D1:1-Device can send/receive call management
                    information over a Data Class interface. */
            /* D0:1-Device handles call management itself. */
            3,                          /*  3:bmCapabilities */
            1,                          /*  4:bDataInterface */

        /* Endpoint Descriptor 0 */
            7,                          /*  0:bLength */
            USB_DT_ENDPOINT,            /*  1:bDescriptorType */
            USB_EP_IN  | USB_EP3,       /*  2:bEndpointAddress */
            USB_EP_INT,                 /*  3:bmAttribute */
            16,                         /*  4:wMAXPacketSize_lo */
            0,                          /*  5:wMAXPacketSize_hi */
            0x10,                       /*  6:bInterval */

    /* Interface Descriptor */
        9,                              /*  0:bLength */
        USB_DT_INTERFACE,               /*  1:bDescriptor */
        1,                              /*  2:bInterfaceNumber */
        0,                              /*  3:bAlternateSetting */
        2,                              /*  4:bNumEndpoints */
        USB_IFCLS_CDCD,                 /*  5:bInterfaceClass */
        0,                              /*  6:bInterfaceSubClass */
        0,                              /*  7:bInterfaceProtocol */
        0,                              /*  8:iInterface */

        /* Endpoint Descriptor 0 */
            7,                          /*  0:bLength */
            USB_DT_ENDPOINT,            /*  1:bDescriptorType */
            USB_EP_IN | USB_EP1,        /*  2:bEndpointAddress */
            USB_EP_BULK,                /*  3:bmAttribute */
            0,                          /*  4:wMAXPacketSize_lo */
            2,                          /*  5:wMAXPacketSize_hi */
            0,                          /*  6:bInterval */

        /* Endpoint Descriptor 1 */
            7,                          /*  0:bLength */
            USB_DT_ENDPOINT,            /*  1:bDescriptorType */
            USB_EP_OUT | USB_EP2,       /*  2:bEndpointAddress */
            USB_EP_BULK,                /*  3:bmAttribute */
            0,                          /*  4:wMAXPacketSize_lo */
            2,                          /*  5:wMAXPacketSize_hi */
            0,                          /*  6:bInterval */
};


/* Configuration */
uint8_t *usb_gpcdc_ConPtr[] =
{
    (uint8_t*)USB_SOFT_CHANGE
};

/* Other_Speed_Configuration */
uint8_t *usb_gpcdc_ConPtrOther[] =
{
    (uint8_t*)USB_SOFT_CHANGE
};


/*************************************
 *    String Descriptor              *
 *************************************/
uint8_t usb_gpcdc_StringDescriptor0
    [ USB_PCDC_SD0_BLENGTH + ( USB_PCDC_SD0_BLENGTH % 2 ) ] =
{   /* UNICODE 0x0409 English (United States) */
    USB_PCDC_SD0_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    0x09, 0x04                          /*  2:wLANGID[0] */
};

uint8_t usb_gpcdc_StringDescriptor1
    [ USB_PCDC_SD1_BLENGTH + ( USB_PCDC_SD1_BLENGTH % 2 ) ] =
{   /* iManufacturer */
    USB_PCDC_SD1_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    'R', 0x00,                          /*  2:wLANGID[0] */
    'E', 0x00,
    'N', 0x00,
    'E', 0x00,
    'S', 0x00,
    'A', 0x00,
    'S', 0x00,
};

uint8_t usb_gpcdc_StringDescriptor2
    [ USB_PCDC_SD2_BLENGTH + ( USB_PCDC_SD2_BLENGTH % 2 ) ] =
{   /* iProduct */
    USB_PCDC_SD2_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    'C', 0x00,
    'D', 0x00,
    'C', 0x00,
    ' ', 0x00,
    'U', 0x00,
    'S', 0x00,
    'B', 0x00,
    ' ', 0x00,
    'D', 0x00,
    'e', 0x00,
    'm', 0x00,
    'o', 0x00,
    'n', 0x00,
    's', 0x00,
    't', 0x00,
    'r', 0x00,
    'a', 0x00,
    't', 0x00,
    'i', 0x00,
    'o', 0x00,
    'n', 0x00
};

uint8_t usb_gpcdc_StringDescriptor3
    [ USB_PCDC_SD3_BLENGTH + ( USB_PCDC_SD3_BLENGTH % 2 ) ] =
{   /* iInterface */
    USB_PCDC_SD3_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    'C', 0x00,
    'o', 0x00,
    'm', 0x00,
    'm', 0x00,
    'u', 0x00,
    'n', 0x00,
    'i', 0x00,
    'c', 0x00,
    'a', 0x00,
    't', 0x00,
    'i', 0x00,
    'o', 0x00,
    'n', 0x00,
    's', 0x00,
    ' ', 0x00,
    'D', 0x00,
    'e', 0x00,
    'v', 0x00,
    'i', 0x00,
    'c', 0x00,
    'e', 0x00,
    's', 0x00
};

uint8_t usb_gpcdc_StringDescriptor4
    [ USB_PCDC_SD4_BLENGTH + ( USB_PCDC_SD4_BLENGTH % 2 ) ] =
{   /* iConfiguration */
    USB_PCDC_SD4_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    'F', 0x00,                          /*  2:wLANGID[0] */
    'u', 0x00,
    'l', 0x00,
    'l', 0x00,
    '-', 0x00,
    'S', 0x00,
    'p', 0x00,
    'e', 0x00,
    'e', 0x00,
    'd', 0x00
};

uint8_t usb_gpcdc_StringDescriptor5
    [ USB_PCDC_SD5_BLENGTH + ( USB_PCDC_SD5_BLENGTH % 2 ) ] =
{   /* iConfiguration */
    USB_PCDC_SD5_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    'H', 0x00,                          /*  2:wLANGID[0] */
    'i', 0x00,
    '-', 0x00,
    'S', 0x00,
    'p', 0x00,
    'e', 0x00,
    'e', 0x00,
    'd', 0x00
};

uint8_t usb_gpcdc_StringDescriptor6
    [ USB_PCDC_SD6_BLENGTH + ( USB_PCDC_SD6_BLENGTH % 2 ) ] =
{   /* iSerialNumber */
    USB_PCDC_SD6_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    '0', 0x00,                          /*  2:wLANGID[0] */
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '0', 0x00,
    '1', 0x00,
};

uint8_t *usb_gpcdc_StrPtr[USB_STRINGNUM] =
{
    usb_gpcdc_StringDescriptor0,
    usb_gpcdc_StringDescriptor1,
    usb_gpcdc_StringDescriptor2,
    usb_gpcdc_StringDescriptor3,
    usb_gpcdc_StringDescriptor4,
    usb_gpcdc_StringDescriptor5,
    usb_gpcdc_StringDescriptor6
};


/******************************************************************************
Renesas Abstracted Peripheral Communications Devices Class Driver API functions
******************************************************************************/

//#pragma end



/******************************************************************************
Section    <Section Difinition> , "Project Sections"
******************************************************************************/
#pragma section _apl

/******************************************************************************
Renesas Peripheral Communications Devices Class Sample Code functions
******************************************************************************/

/******************************************************************************
Function Name   : usb_papl_task_start
Description     : Set peripheral application task start conditions. 
Arguments       : none
Return value    : none
******************************************************************************/
void    usb_papl_task_start( USB_UTR_t *ptr )
{
    /* PCDC demo sample application task priority set */
    R_usb_cstd_SetTaskPri(USB_PCDCSMP_TSK, USB_PRI_6);

#ifdef USB_UART_ENABLE
    /* ComPort Hw Initialize */
    usb_cpu_Sci_HW_init();
#endif /* USB_UART_ENABLE */

    /* Application data Initialize and Periodic process request */
    usb_pcdc_apl_init(ptr);
}
/******************************************************************************
End of function usb_papl_task_start()
******************************************************************************/

/******************************************************************************
Function Name   : usb_cstd_task_start
Description     : Start task CSTD; "common" basic USB low level task.
Arguments       : USB_UTR_t *ptr        : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_cstd_task_start( void )
{
    usb_cstd_IdleTaskStart();   /* Idle Task Start */

    usb_pcdc_task_start();      /* Start Peripheral USB driver */

    usb_apl_task_switch();      /* Switch task for nonOS */
}
/******************************************************************************
End of function usb_cstd_task_start()
******************************************************************************/

/******************************************************************************
Function Name   : usb_pstd_task_start
Description     : Set peripheral application task start conditions. 
Arguments       : none
Return value    : none
******************************************************************************/
void usb_pcdc_task_start( void )
{
    USB_UTR_t   utr;
    USB_UTR_t   *ptr;

#ifdef  USB_LCD_ENABLE
    /* Display Debug LCD */
    usb_cpu_LcdDisp( LCD_POS_U0, "USB CDC ");
    usb_cpu_LcdDisp( LCD_POS_D0, "Appstart");
#endif /* USB_LCD_ENABLE */

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
/******************************************************************************
End of function usb_pstd_task_start()
******************************************************************************/

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
    driver.devicetbl    = (uint8_t*)&usb_gpcdc_DeviceDescriptor;
    /* Qualifier descriptor Table address */
    driver.qualitbl     = (uint8_t*)&usb_gpcdc_QualifierDescriptor;
    /* Configuration descriptor Table address */
    driver.configtbl    = (uint8_t**)&usb_gpcdc_ConPtr;
    /* Other configuration descriptor Table address */
    driver.othertbl     = (uint8_t**)&usb_gpcdc_ConPtrOther;
    /* String descriptor Table address */
    driver.stringtbl    = (uint8_t**)&usb_gpcdc_StrPtr;
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

/******************************************************************************
Function Name   : usb_apl_task_switch
Description     : Task switch loop for nonOS version.
Argument        : none
Return          : none
******************************************************************************/
void usb_apl_task_switch(void)
{
	
    //while( 1 )	// combine ED&USB, Sean, 20140819
    //{
        /* Scheduler */
        R_usb_cstd_Scheduler();

        /* Task schedule request check. */
        if( USB_FLGSET == R_usb_cstd_CheckSchedule() )
        {
#ifdef  USB_PERI_MODE_PP
            R_usb_pstd_PcdTask((USB_VP_INT)0);          /* PCD Task */
            /* Peripheral Communications Devices Class Task */
            R_usb_pcdc_task(0);
            /* Peripheral Communications Class Application Task */
            usb_pcdc_main_task(0);
#endif  /* USB_PERI_MODE_PP */
            /* Idle Task (sleep sample) */
            R_usb_cstd_IdleTask(0);
        } 

	
    //}
}   /* eof usb_apl_task_switch() */

/******************************************************************************
Function Name   : usb_pcdc_pr_apl_title
Description     : Output Title
Argument        : none
Return          : none
******************************************************************************/
void usb_pcdc_pr_apl_title(void)
{
#ifdef  USB_LCD_ENABLE
    usb_cpu_TargetLcdClear();
#endif /* USB_LCD_ENABLE */
    USB_PRINTF0("\n");
    USB_PRINTF0("+++++++++++++++++++++++++++++++++++++\n");
    USB_PRINTF0("+   PERI CDC FW SAMPLE              +\n");
    USB_PRINTF0("+                                   +\n");
    USB_PRINTF0("+     RENESAS ELECTRONICS CORP.     +\n");
    USB_PRINTF0("+     RENESAS SOLUTIONS  CORP.      +\n");
    USB_PRINTF0("+++++++++++++++++++++++++++++++++++++\n");
    USB_PRINTF1("       DATE [%s] \n", __DATE__);
    USB_PRINTF1("       TIME [%s] \n", __TIME__);
}   /* eof usb_pcdc_pr_apl_title() */

/******************************************************************************
Function Name   : usb_pcdc_sw_process
Description     : Switch Push Management process
                : - After connect,SW2 push Message output. Message stop by RSK SW2 push.
                : - SW2 : Transfer  operate description  Message 
                : - SW3 : Echo mode On/Off change
                :   ( When Echo mode Off, to USB serial converter)
Arguments       : USB_UTR_t *ptr        : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pcdc_sw_process(USB_UTR_t *ptr)
{
    uint16_t key_data;

    /* SW1-3 Polling */
    /*----------------------------------*/
    /* Initial message SW2Input request */
    /*----------------------------------*/
    /* Send Complete wait flag check */
    if((usb_gpcdc_tx_wait_flag == USB_OFF) && (usb_gpcdc_sw2push == USB_OFF))
    {
        /* Message output timming check */
        usb_gpcdc_msg_timing_cnt++;
        if(usb_gpcdc_msg_timing_cnt >= USB_PCDC_MSG_TIMING)
        {
            usb_gpcdc_msg_timing_cnt = 0;
            /* Show instructions Start */
            usb_pcdc_apl_msg_out(ptr, 0);
        }
    }
    /*----------------------------------*/
    /* SW Polling process               */
    /*----------------------------------*/
    /* Send Complete wait flag check */
    if(usb_gpcdc_tx_wait_flag == USB_OFF)
    {
        /* Switch Input */
#ifdef USB_KEY_ENABLE
        key_data = usb_cpu_GetKeyNo();
#else   /* USB_KEY_ENABLE */
        key_data = USB_OFF;
#endif  /* USB_KEY_ENABLE */
        switch(key_data)
        {
        case USB_PCDC_SW1_ON:
            /* Change Echo mode /USB serial conversion mode */
            if( usb_gpcdc_echo_mode == USB_OFF )
            {
                /* Show instructions Start */
                usb_pcdc_apl_msg_out(ptr, 1);
                /* Start Echo */
                usb_gpcdc_echo_mode = USB_ON;
#ifdef USB_UART_ENABLE
                /* Serial port disable */
                usb_cpu_Sci_disable();
#endif /* USB_UART_ENABLE */
            }
            else
            {
                /* Peri CDC Application Tx Rx data clear */
                usb_cpu_Sci_Buffer_init();
                /* Show instructions Start */
                usb_pcdc_apl_msg_out(ptr, 2);
                /* Stop Echo */
                usb_gpcdc_echo_mode = USB_OFF;
#ifdef USB_UART_ENABLE
                /* Serial port enable */
                usb_cpu_Sci_enable();
#endif /* USB_UART_ENABLE */
            }
            break;
        case USB_PCDC_SW2_ON:
            /* SW2 ON */
            usb_gpcdc_sw2push = USB_ON;
            /* Set Operate description Message start no. */
            usb_gpcdc_explain_seq = USB_PCDC_APL_INST_SEQ_START;
            /* Show instructions Start */
            usb_pcdc_apl_msg_out(ptr, usb_gpcdc_explain_seq);
            break;

        case USB_PCDC_SW3_ON:

            break;

        default:
            /* No switch push */
            /* Show instructions Continue */
            if(( usb_gpcdc_explain_seq >= USB_PCDC_APL_INST_SEQ_START )
                && (usb_gpcdc_explain_seq < USB_PCDC_APL_INST_SEQ_END))
            {
                /* Next operate description Message no. update */
                usb_gpcdc_explain_seq++;
                /* Show instructions Start */
                usb_pcdc_apl_msg_out(ptr, usb_gpcdc_explain_seq);
            }
            break;
        }
    }
}   /* eof usb_pcdc_sw_process() */

/******************************************************************************
Function Name   : usb_pcdc_serial_state_process
Description     : Serial error process
                : Transfer Class Notification SerialState when UART(SCI) error detection
                : ( Parity error / Framing error / Over run error )
Arguments       : USB_UTR_t *ptr        : USB system internal structure.
Return value    : none
******************************************************************************/
void usb_pcdc_serial_state_process(USB_UTR_t *ptr)
{
    /* SerialState(CDC PSTN Subclass UART State bitmap) */
    uint16_t    serial_stat;
    /* Serial error detect */
    uint16_t    serial_error;
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    USB_ER_t    err = 0l;
    int16_t     state;
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */

    /*----------------------------------*/
    /* Communications Port Error check  */
    /*----------------------------------*/
    /* Serial State Notification send flag check */
    if(usb_gpcdc_serial_state_tx == USB_OFF)
    {
        /* Serial error status read */
        serial_error = usb_cpu_Sci_GetSerialState(&serial_stat);
        if(serial_error)
        {
            /* SerialState notification when different error type to last notification error type */
            if(serial_stat != usb_gpcdc_serial_state)
            {
                /* Notifications Serial State */
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
                /* UART State bitmap set */
                usb_gpcdc_SerialState_Table[8] = (uint8_t)(serial_stat & 0xff);
                usb_gpcdc_SerialState_Table[9] = (uint8_t)(serial_stat >> 8);

                /* Transfer Class Notification SerialState */
                write( usb_spcdc_ctl_fn, (uint8_t*)&usb_gpcdc_SerialState_Table[0], USB_CDC_SETUP_TBL_BSIZE );
                /* Write status check */
                err = control( usb_spcdc_ctl_fn, USB_CTL_GET_WR_STATE, (void*)&state );
                if( ( err == -1 ) || ( state != USB_CTL_ERR_PROCESS_WAIT ) )
                {
                    USB_PRINTF0("### usb_pcdc_serial_state_process function data write error\n");
                }
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */
                /* Transfer Class Notification SerialState */
                R_usb_pcdc_SerialStateNotification(ptr, serial_stat, (USB_CB_t)&usb_pcdc_state_notification);
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */
                /* Serial State Notification send flag set */
                usb_gpcdc_serial_state_tx = USB_ON;
                /* Serial Erros State Store */
                usb_gpcdc_serial_state = serial_stat;
            }
        }
        else
        {
            /* Serial Erros State Clear */
            usb_gpcdc_serial_state = 0;
        }
    }
}   /* eof usb_pcdc_serial_state_process() */

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
/******************************************************************************
Function Name   : usb_pcdc_main_task
Description     : Peri CDC Sample Application
Argument        : USB_VP_INT_t
Return          : none
******************************************************************************/
UWORD USB_uwStaCod;
extern UWORD uwtest3,uwtest4,uwtest6,uwtest7,uwtest8,uwtest9;
void usb_pcdc_main_task(USB_VP_INT_t start_code)
{
    USB_UTR_t   *mess;
    USB_ER_t    err = 0l;

    /* Receive Data Count for Comm Port */
    //uint16_t    srcv_cnt;
    /* Receive Data Count for USB Host */
    int32_t     data_cnt;
    int16_t     state;
	
    /* Recieve message for message box of PCDC demo sample application */
    err = R_USB_TRCV_MSG(USB_PCDCSMP_MBX,(USB_MSG_t**)&mess,(uint16_t)3000);
    if( err == USB_E_OK )
    {
    	
        /* Branch by message infomation. */
        switch(mess->msginfo)
        {

        case USB_PCDC_OPEN:
            /* PCDC(Data Class) Open */
            usb_spcdc_data_fn = open((int8_t *)USB_CLASS_PCDCD, 0, 0);
            if( usb_spcdc_data_fn == -1 )
            {
            	USB_uwStaCod = 0x0001;
                /* Make Other Task Processing Time */
                R_USB_DLY_TSK(10);

                /*  Cdc Data Open retry */
                usb_pcdc_smpl_message_send( mess, USB_PCDC_OPEN );
            }
            else
            {
            	USB_uwStaCod = 0x0002;
                /* PCDC(Communications Class) Open */
                usb_spcdc_ctl_fn = open((int8_t *)USB_CLASS_PCDCC, 0, 0); 
                if( usb_spcdc_ctl_fn != -1 )
                {
                    /* Call-Back function set */
                    control( usb_spcdc_data_fn, USB_CTL_RD_NOTIFY_SET, (void*)&usb_pcdc_rx_notification );
                    control( usb_spcdc_data_fn, USB_CTL_WR_NOTIFY_SET, (void*)&usb_pcdc_tx_notification );
                    control( usb_spcdc_ctl_fn, USB_CTL_WR_NOTIFY_SET, (void*)&usb_pcdc_state_notification );

                    /* Sw polling start */
                    usb_pcdc_smpl_message_send( mess, USB_PCDC_PERIODIC_PROCESS );
                }
            }

            /* Release the memory block for the sample application */
            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
            if( err != USB_OK )
            {
            	USB_uwStaCod = 0x0003;
                /* error */
                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
            }
            break;

        case USB_PCDC_PERIODIC_PROCESS:
        	USB_uwStaCod = 0x0004;
            /* Check PCDC(Data Class & Communications Class) Open complete ? */
            if( (usb_spcdc_data_fn != -1) || (usb_spcdc_ctl_fn != -1) )
            {
            	USB_uwStaCod = 0x000E;
                /* Sw polling repetition */
                usb_pcdc_smpl_message_send( mess, USB_PCDC_PERIODIC_PROCESS );

                /* Host CDC Connect check */
                if( usb_pcdc_is_connected() == USB_OFF )
                {
                    /* Peri CDC Not Active set */
                    usb_gpcdc_active = USB_OFF;
                }
                else if( usb_gpcdc_active == USB_OFF )
                {
                    /* Peri CDC Active set */
                    usb_gpcdc_active = USB_ON;
                    /* Host CDC Data receive start */
                    usb_gpcdc_stx_wait = USB_ON;
                }
                /*----------------------------------*/
                /* Switch Push Management process   */
                /*----------------------------------*/
                //usb_pcdc_sw_process(mess);              /* Input RSK SW & Transfer SW push request Message */

                /*----------------------------------*/
                /* Serial error process             */
                /*----------------------------------*/
 //               usb_pcdc_serial_state_process(mess);    /* UART(SCI) error check & SerialState transfer. *///Aevin mark--7/8/2015
    	
    			/*----------------------------------*/
                /* tx timeout detection & handler   */
                /* Reset buffer: no Tx 5 sec 		*/
                /*----------------------------------*/
				if (usb_gpcdc_tx_wait_flag==USB_ON)
					USB_uwTxTimOut = (USB_uwTxTimOut < 5000)? USB_uwTxTimOut+1 : USB_uwTxTimOut;
				else
					USB_uwTxTimOut = 0;

                if (USB_uwTxTimOut>=5000){	//5000=1s
					USB_uwTxTimOut = 0;
					
                	usb_gpcdc_tx_wait_flag = USB_OFF;	/* HOST Send wait flag */
					memset(	USB_ubRxData, 0, USB_ubRXMAX);
					memset(	USB_ubTxData_0, 0, USB_ubRXMAX);
					PC_TransState = USB_STOP;
					USB_ubRxCnt = 0;							
					USB_RxTime = 0;	                	
                }					
              
                /*----------------------------------*/
                /* Communications Port receive check    */
                /*----------------------------------*/
                /* Send Complete wait flag check */
                if(usb_gpcdc_tx_wait_flag == USB_OFF)
                {
                	USB_uwStaCod = 0x0005;
                    /* Echo mode Data copy */
/*//aevin mark--7/87/2015
					if(usb_gpcdc_echo_mode)
                    {
                        // Echo mode data copy Serial TX -> Serial RX 
                        usb_cpu_Sci_CopyData_for_Echo();
                    }
*/				
		    		// combine ED&USB, Sean, 20140819	// TX/RX sequence, Sean, 20141225
					USB_vdRxDecoder();
					USB_vdTxHandler();
					
                    ///* Comm port data receive */
                    //srcv_cnt = usb_cpu_Sci_DataReceive( usb_gpcdc_send_data, USB_PCDC_APL_SRX_SIZE);
                    //if( srcv_cnt != 0 )
                    //{
                    //    /* Comm port receive data -> CDC Host send */
                    //    write( usb_spcdc_data_fn, (uint8_t*)&usb_gpcdc_send_data, srcv_cnt);
                    //    /* Write status check */
                    //    err = control( usb_spcdc_data_fn, USB_CTL_GET_WR_STATE, (void*)&state );
                    //    if( ( err == -1 ) || ( state != USB_CTL_ERR_PROCESS_WAIT ) )
                    //    {
                    //        USB_PRINTF0("### usb_pcdc_main_task function data write error\n");
                    //    }
                    //    /* Send Complete wait flag on */
                    //    usb_gpcdc_tx_wait_flag = USB_ON;
                    //}
                }
                /*----------------------------------*/
                /* CDC Host Bulk In Request         */
                /*----------------------------------*/
                if( usb_gpcdc_stx_wait )                /* Check flow control flag */
                {
                    /* Check UART transfer buffer condition. */
//                    if( usb_cpu_Sci_StxBuffStatus() == 0)
//                    {
                        /* Common Read(BULK OUT) */
                        read( usb_spcdc_data_fn, (uint8_t*)&usb_gpcdc_receive_data, USB_PCDC_APL_RX_SIZE);
                        /* Read status check */
                        err = control( usb_spcdc_data_fn, USB_CTL_GET_RD_STATE, (void*)&state );
                        if( ( err == -1 ) || ( state != USB_CTL_ERR_PROCESS_WAIT ) )
                        {
                            USB_PRINTF0("### usb_pcdc_main_task function bulk read error\n");
                        }
                        /* Receive flow control flag off */
                        usb_gpcdc_stx_wait = USB_OFF;
//                    }
                }
            }

            /* Release the memory block for the sample application */
            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
            if( err != USB_OK )
            {
                /* error */
                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
            }
            break;

        case USB_PCDC_RX_COMP:
        	USB_uwStaCod = 0x0006;
            /* USB receive complete */
            /* Check PCDC(Data Class & Communications Class) Open complete ? */
            if( (usb_spcdc_data_fn != -1) || (usb_spcdc_ctl_fn != -1) )
            {
                /*----------------------------------*/
                /* Get USB Receive Data count       */
                /*----------------------------------*/
                err = control( usb_spcdc_data_fn, USB_CTL_RD_LENGTH_GET, (void*)&data_cnt );
                if( ( err == -1 ) || ( data_cnt == -1 ) )
                {
                    /* Transfer NG */
                    USB_PRINTF0("### usb_pstd_MainTask function int read notify error\n");
                }
                /*----------------------------------*/
                /* CDC Host Bulk In receive check   */
                /*----------------------------------*/
                if(data_cnt > 0)
                {
					// USB Rx Buffer Retriving // combine ED&USB, Sean, 20140819
					memcpy(USB_ubRxData+USB_ubRxCnt,usb_gpcdc_receive_data,data_cnt);
					USB_ubRxCnt += data_cnt;	
					
                    ///* Communications Port Data Send Process */
                    //usb_cpu_Sci_DataSend(usb_gpcdc_echo_mode, &usb_gpcdc_receive_data , data_cnt);
                    usb_gpcdc_stx_wait = USB_ON;//Aevin move to here ---7/8/2015
                }
                /*----------------------------------*/
                /* CDC Host Bulk In Request         */
                /*----------------------------------*/
/*//Aevin mark---7/8/2015
				if( usb_cpu_Sci_StxBuffStatus() == 0)
                {
                	USB_uwStaCod = 0x0007;
                    // Common Read(BULK OUT) 
                    read( usb_spcdc_data_fn, (uint8_t*)&usb_gpcdc_receive_data, USB_PCDC_APL_RX_SIZE);
                    // Read status check 
                    err = control( usb_spcdc_data_fn, USB_CTL_GET_RD_STATE, (void*)&state );
                    if( ( err == -1 ) || ( state != USB_CTL_ERR_PROCESS_WAIT ) )
                    {
                        USB_PRINTF0("### usb_pcdc_main_task function bulk read error\n");
                    }
                }
                else
                {
                	USB_uwStaCod = 0x0008;
                    // Receive flow control flag on 
                    usb_gpcdc_stx_wait = USB_ON;
                }
*/		
            }
            break;
        case USB_PCDC_TX_COMP:
            /* USB transfer complete */
            /* Check PCDC(Data Class & Communications Class) Open complete ? */
            USB_uwStaCod = 0x0009;
            if( (usb_spcdc_data_fn != -1) || (usb_spcdc_ctl_fn != -1) )
            {
            	USB_uwStaCod = 0x000A;
                /*----------------------------------*/
                /* Data send for Host cdc           */
                /*----------------------------------*/
                err = control( usb_spcdc_data_fn, USB_CTL_WR_LENGTH_GET, (void*)&data_cnt );
                if( ( err == -1 ) || ( data_cnt == -1 ) )
                {
                    /* Transfer NG */
                    USB_PRINTF0("### usb_pstd_MainTask function int read notify error\n");
                }

                /* Send Complete wait flag off */
                usb_gpcdc_tx_wait_flag = USB_OFF;
            }
            if (switchFlag==1){	// bootloader over usb for online mode, Sean, 20141030	
            	switch_TxDon = 1;
            	usb_pcdc_close(mess,0,0);	// close port after bootloader jump reply finish  // bootloader over usb for online mode, Sean, 20141030
            }
            break;
        case USB_PCDC_STATUS_TX_COMP:
            /*------------------------------------------*/
            /* Serial State Notification send complete  */
            /*------------------------------------------*/
            /* Serial State Notification send flag clear */
            usb_gpcdc_serial_state_tx = USB_OFF;
            break;
        case USB_PCDC_CLOSE:
        	USB_uwStaCod = 0x000C;
            if( usb_spcdc_data_fn != -1 )
            {
                close(usb_spcdc_data_fn);
                usb_spcdc_data_fn = -1;
            }
            if( usb_spcdc_ctl_fn != -1 )
            {
                close(usb_spcdc_ctl_fn);
                usb_spcdc_ctl_fn = -1;
            }

            /* Application data Initialize and Periodic process request */
            usb_pcdc_apl_init(mess);

            /* Release the memory block for the sample application */
            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
            if( err != USB_OK )
            {
                /* error */
                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
            }
            break;

        default:
        	USB_uwStaCod = 0x000D;
            /*----------------------------------*/
            /* Undefine message                 */
            /*----------------------------------*/
            USB_PRINTF1("### Undefine message:%02x\n",mess->msginfo);
            /* Release the memory block for the sample application */
            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
            if( err != USB_OK )
            {
                /* error */
                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
            }

            break;
        }
    }
}   /* eof usb_pcdc_main_task() */

#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */
/******************************************************************************
Function Name   : usb_pcdc_main_task
Description     : Peri CDC Sample Application
Argument        : USB_VP_INT_t
Return          : none
******************************************************************************/
//void usb_pcdc_main_task(USB_VP_INT_t start_code)
//{
//    USB_UTR_t   *mess;
//    USB_ER_t    err = 0l;
//
//    /* Receive Data Count for Comm Port */
//    uint16_t    srcv_cnt;
//    /* Receive Data Count for USB Host */
//    int32_t     data_cnt;
//
//    /* Recive message for message box of PCDC demo sample application. */
//    err = R_USB_TRCV_MSG(USB_PCDCSMP_MBX,(USB_MSG_t**)&mess,(uint16_t)3000);
//    if( err == USB_E_OK )
//    {
//        /* Branch by message infomation. */
//        switch(mess->msginfo)
//        {
//        case USB_PCDC_PERIODIC_PROCESS:
//            /* Host CDC Connect check */
//            if( usb_pcdc_is_connected() == USB_OFF )
//            {
//                /* Peri CDC Not Active set */
//                usb_gpcdc_active = USB_OFF;
//            }
//            else 
//            {
//                /* Sw polling repetition */
//                usb_pcdc_smpl_message_send( mess, USB_PCDC_PERIODIC_PROCESS );
//            }
//
//            if( usb_gpcdc_active == USB_OFF )
//            {
//                /* Peri CDC Active set */
//                usb_gpcdc_active = USB_ON;
//                /* Host CDC Data receive start */
//                usb_gpcdc_stx_wait = USB_ON;
//            }
//
//            /*----------------------------------*/
//            /* Switch Push Management process   */
//            /*----------------------------------*/
//            //usb_pcdc_sw_process(mess);              /* Input RSK SW & Transfer SW push request Message */
//
//            /*----------------------------------*/
//            /* Serial error process             */
//            /*----------------------------------*/
//            usb_pcdc_serial_state_process(mess);    /* UART(SCI) error check & SerialState transfer. */
//
//            /*----------------------------------*/
//            /* Communications Port receive check    */
//            /*----------------------------------*/
//            /* Send Complete wait flag check */
//            if(usb_gpcdc_tx_wait_flag == USB_OFF)
//            {
//                /* Comm port data receive */
//                srcv_cnt = usb_cpu_Sci_DataReceive( usb_gpcdc_send_data, USB_PCDC_APL_SRX_SIZE );
//                if( srcv_cnt != 0 )
//                {
//                    /* Comm port receive data -> CDC Host send */
//                    R_usb_pcdc_SendData(mess, usb_gpcdc_send_data, srcv_cnt, (USB_CB_t)&usb_pcdc_tx_notification);
//                    /* Send Complete wait flag on */
//                    usb_gpcdc_tx_wait_flag = USB_ON;
//                }
//            }
//            /*----------------------------------*/
//            /* CDC Host Bulk In Request         */
//            /*----------------------------------*/
//            if(usb_gpcdc_stx_wait)                  /* Check flow control flag */
//            {
//                /* Check UART transfer buffer condition. */
//                if( usb_cpu_Sci_StxBuffStatus() == 0)
//                {
//                    /* Common Read(BULK OUT) */
//                    R_usb_pcdc_ReceiveData(mess, (uint8_t *)&usb_gpcdc_receive_data, USB_PCDC_APL_RX_SIZE,(USB_CB_t)&usb_pcdc_rx_notification);
//                    /* Receive flow control flag off */
//                    usb_gpcdc_stx_wait = USB_OFF;
//                }
//            }
//
//            /* Release the memory block for the sample application */
//            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
//            if( err != USB_OK )
//            {
//                /* error */
//                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
//            }
//            break;
//
//        case USB_PCDC_RX_COMP:
//            /*----------------------------------*/
//            /* Get USB Receive Data count       */
//            /*----------------------------------*/
//            data_cnt = usb_pcdc_get_rcv_data_cnt(mess);
//
//            /*----------------------------------*/
//            /* CDC Host Bulk In receive check   */
//            /*----------------------------------*/
//            if(data_cnt > 0)
//            {
//                /* Communications Port Data Send Process */
//                usb_cpu_Sci_DataSend(usb_gpcdc_echo_mode, &usb_gpcdc_receive_data , data_cnt);
//            }
//            /*----------------------------------*/
//            /* CDC Host Bulk In Request         */
//            /*----------------------------------*/
//            if( usb_cpu_Sci_StxBuffStatus() == 0)
//            {
//                /* Common Read(BULK OUT) */
//                R_usb_pcdc_ReceiveData(mess, (uint8_t *)&usb_gpcdc_receive_data, USB_PCDC_APL_RX_SIZE,
//                    (USB_CB_t)&usb_pcdc_rx_notification);
//            }
//            else
//            {
//                /* Receive flow control flag on */
//                usb_gpcdc_stx_wait = USB_ON;
//            }
//            break;
//
//        case USB_PCDC_TX_COMP:
//            /*----------------------------------*/
//            /* Data send for Host cdc           */
//            /*----------------------------------*/
//            /* Send Complete wait flag off */
//            usb_gpcdc_tx_wait_flag = USB_OFF;
//            break;
//
//        case USB_PCDC_STATUS_TX_COMP:
//            /*------------------------------------------*/
//            /* Serial State Notification send complete  */
//            /*------------------------------------------*/
//            /* Serial State Notification send flag clear */
//            usb_gpcdc_serial_state_tx = USB_OFF;
//            break;
//
//        case USB_PCDC_CLOSE:
//            /* Application data Initialize and Periodic process request */
//            usb_pcdc_apl_init(mess);
//
//            /* Release the memory block for the sample application */
//            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
//            if( err != USB_OK )
//            {
//                /* error */
//                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
//            }
//            break;
//
//        default:
//            /*----------------------------------*/
//            /* Undefine message                 */
//            /*----------------------------------*/
//            USB_PRINTF1("### Undefine message:%02x\n",mess->msginfo);
//
//            /* Release the memory block for the sample application */
//            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)mess);
//            if( err != USB_OK )
//            {
//                /* error */
//                USB_PRINTF0("### USB PeripheralSampleClass rel_blk error\n");
//            }
//            break;
//        }
//    }
//}   /* eof usb_pcdc_main_task() */
//
///******************************************************************************
//Function Name   : usb_pcdc_get_rcv_data_cnt
//Description     : Get USB Receive Data count 
//Arguments       : USBC_UTR_t
//Return value    : USB receive data count
//******************************************************************************/
//uint16_t usb_pcdc_get_rcv_data_cnt(USB_UTR_t *mess)
//{
//    /* Receive Data Count for USB Host */
//    uint16_t    rcv_cnt;
//
//    /*----------------------------------*/
//    /* Data receive from Host cdc       */
//    /*----------------------------------*/
//    if(mess->status == USB_DATA_OK)
//    {
//        /* Receive size = Request size */
//        rcv_cnt = USB_PCDC_APL_RX_SIZE;
//    }
//    else if(mess->status == USB_DATA_SHT)
//    {
//        /* Receive size < Request size */
//        rcv_cnt = USB_PCDC_APL_RX_SIZE - mess->tranlen;
//    }
//    else
//    {
//        rcv_cnt = 0;
//    }
//
//    return rcv_cnt;
//}   /* eof usb_pcdc_get_rcv_data_cnt() */

#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */

/******************************************************************************
Function Name   : usb_pcdc_rx_notification
Description     : CDC Host Rx complete Callback
Argument        : USB_UTR_t *mess           : message
Return          : none
******************************************************************************/
void usb_pcdc_rx_notification(USB_UTR_t *mess)
{
    USB_ER_t        err;

    /* Set USB receive complete for APL notification message. */
    mess->msginfo = USB_PCDC_RX_COMP;
    /* Send message */
    err = R_USB_SND_MSG(USB_PCDCSMP_MBX, (USB_MSG_t*)mess);
    if( err != USB_E_OK )
    {
        /* Send Message failure */
        USB_PRINTF1("### usb_pcdc_rx_notification snd_msg error (%ld)\n", err);
    }
}   /* eof usb_pcdc_rx_notification() */

/******************************************************************************
Function Name   : usb_pcdc_tx_notification
Description     : CDC Host Tx complete Callback
Argument        : USB_UTR_t *mess           : message
Return          : none
******************************************************************************/
void usb_pcdc_tx_notification(USB_UTR_t *mess)
{
    USB_ER_t        err;

    /* Set USB transfer complete for APL notification message. */
    mess->msginfo = USB_PCDC_TX_COMP;
    /* Send message */
    err = R_USB_SND_MSG(USB_PCDCSMP_MBX, (USB_MSG_t*)mess);
    if( err != USB_E_OK )
    {
        /* Send Message failure */
        USB_PRINTF1("### usb_pcdc_tx_notification snd_msg error (%ld)\n", err);
    }
}   /* eof usb_pcdc_tx_notification() */

/******************************************************************************
Function Name   : usb_pcdc_SerialStatusTxCB
Description     : CDC Host Tx complete Callback
Argument        : USB_UTR_t *mess           : message
Return          : none
******************************************************************************/
void usb_pcdc_state_notification(USB_UTR_t *mess)
{
    USB_ER_t        err;

    /* Set SerialState transfer complete for APL notification message type. */
    mess->msginfo = USB_PCDC_STATUS_TX_COMP;
    /* Send message */
    err = R_USB_SND_MSG(USB_PCDCSMP_MBX, (USB_MSG_t*)mess);
    if( err != USB_E_OK )
    {
        /* Send Message failure */
        USB_PRINTF1("### usb_pcdc_state_notification snd_msg error (%ld)\n", err);
    }
}   /* eof usb_pcdc_state_notification() */

/******************************************************************************
Function Name   : usb_pcdc_apl_init
Description     : Peri CDC Application memory clear
Argument        : USB_UTR_t *ptr        : USB system internal structure.
Return          : none
******************************************************************************/
void usb_pcdc_apl_init(USB_UTR_t *ptr)
{
    /* echo mode flag clear */
    usb_gpcdc_echo_mode = USB_ON;

    /* Debug mode flag */
    usb_gpcdc_debug_mode = USB_OFF;
    
    /* Clear SW2 push flag */
    usb_gpcdc_sw2push = 0;

    /* Clear SW2 push request Message transfer timming counter */
    usb_gpcdc_msg_timing_cnt = 0;

    /* Peri CDC Not Active set */
    usb_gpcdc_active = USB_OFF;

    /* Clear data for USB TX and RX */
    memset(usb_gpcdc_send_data,0,USB_PCDC_APL_SRX_SIZE);
    memset(usb_gpcdc_receive_data,0,USB_PCDC_APL_RX_SIZE);
    /* Instructions output line sequence */
    usb_gpcdc_explain_seq = 0;
    /* HOST Send wait flag */
    usb_gpcdc_tx_wait_flag = 0;

    /* Peri CDC Application Tx Rx data clear */
    usb_cpu_Sci_Buffer_init();

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    /*  Cdc Application Initial Message send */
    usb_pcdc_smpl_message_send( ptr, USB_PCDC_OPEN );
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
}   /* eof usb_pcdc_apl_init() */

/******************************************************************************
Function Name   : usb_pcdc_apl_msg_out
Description     : Terminal Output message send for Host CDC
Argument        : USB_UTR_t *ptr        : USB system internal structure.
                : uint16_t message_no   : Terminal Output message No.
Return          : none
******************************************************************************/
void usb_pcdc_apl_msg_out(USB_UTR_t *ptr, uint16_t message_no)
{
    uint16_t len;

    /* Message length get */
    len = strlen((char*)szWelcomeMsg[message_no]);
    /* Message send for Host CDC */
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    write( usb_spcdc_data_fn, (uint8_t*)&szWelcomeMsg[message_no], len);
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */
    R_usb_pcdc_SendData(ptr, (uint8_t *)&szWelcomeMsg[message_no], len, (USB_CB_INFO_t)&usb_pcdc_tx_notification);
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP   */

    /* Host CDC Send complete wait flag on */
    usb_gpcdc_tx_wait_flag = USB_ON;
//    szWelcomeMsg[0] = szWelcomeMsg[0] + rand1;
}   /* eof usb_pcdc_apl_msg_out() */

/******************************************************************************
Function Name   : usb_pcdc_smpl_message_send
Description     : Transfer message for Message BOX of demo sample application
Argument        : USB_UTR_t *ptr            : IP Information(Mode,IP No.,Reg Address)
                : uint16_t   msginfo         : Message Information Kind
Return          : none
******************************************************************************/
void usb_pcdc_smpl_message_send( USB_UTR_t *ptr, uint16_t msginfo)
{
    USB_MH_t            p_blf;
    USB_ER_t            err;
    USB_CLSINFO_t       *cp;

    /* Get mem pool blk */
    if( R_USB_PGET_BLK(USB_PCDCSMP_MPL, &p_blf) == USB_E_OK )
    {
        cp = (USB_CLSINFO_t*)p_blf;
        cp->msginfo = msginfo;

        cp->ipp = ptr->ipp;
        cp->ip  = ptr->ip;
        cp->msghead = (USB_MH_t)NULL;
        
        /* Send message */
        err = R_USB_SND_MSG( USB_PCDCSMP_MBX, (USB_MSG_t*)cp );
        if( err != USB_E_OK )
        {
            /* error */
            err = R_USB_REL_BLK(USB_PCDCSMP_MPL,(USB_MH_t)p_blf);
            USB_PRINTF0("### usb_pcdc_smpl_message_send function snd_msg error\n");
        }
    }
    else
    {
        /* error */
        USB_PRINTF0("### usb_pcdc_smpl_message_send function pget_blk error\n");
        while( 1 );
    }
}   /* eof usb_pcdc_smpl_message_send() */

/******************************************************************************
Function Name   : usb_pcdc_open
Description     : Peripheral Communications Devices Class open function
Arguments       : USB_UTR_t *ptr            : IP Information(Mode,IP No.,Reg Address)
                : uint16_t data1            : Not use
                : uint16_t data2            : Not use
Return value    : USB_ER_t                  : USB_E_OK etc
******************************************************************************/
USB_ER_t usb_pcdc_open(USB_UTR_t *ptr, uint16_t data1, uint16_t data2)
{
    /* Peri CDC Application process enable */
    usb_gcdc_connected = USB_ON;

#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
    /* Sample class attach */
    usb_pcdc_smpl_message_send( ptr, USB_PCDC_PERIODIC_PROCESS );
#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */

    return USB_E_OK;
}   /* eof usb_pcdc_open() */


/******************************************************************************
Function Name   : usb_pcdc_close
Description     : Peripheral Communications Devices Class close function
Arguments       : USB_UTR_t *ptr            : IP Information(Mode,IP No.,Reg Address)
                : uint16_t data1            : Not use
                : uint16_t data2            : Not use
Return value    : USB_ER_t                  : USB_E_OK etc
******************************************************************************/
USB_ER_t usb_pcdc_close(USB_UTR_t *ptr, uint16_t data1, uint16_t data2)
{
    /* Sample class detatch */
    usb_pcdc_smpl_message_send( ptr, USB_PCDC_CLOSE );

    /* Peri CDC Application process disable */
    usb_gcdc_connected = USB_OFF;

    return USB_E_OK;
}   /* eof usb_pcdc_close() */

/******************************************************************************
Function Name   : usb_pcdc_is_connected
Description     : Get the USB cable connected state.
Arguments       : none
Return value    : USB_ON = Connected, USB_OFF = Disconnected.
******************************************************************************/
uint16_t usb_pcdc_is_connected(void)
{
    return usb_gcdc_connected;
}   /* eof usb_pcdc_is_connected() */


#pragma section _rx_rsk
#ifdef USB_UART_ENABLE
/******************************************************************************
Serial Port function
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_Set1
Description     : Line coding set
Arguments       : data_rate   : Data terminal rate in bits per second
                : stop_bit    : Stop bits 0-1Stopbit 1-1.5Stopbit 2-2Stopbit
                : parity      : Parity 0-None 1-Odd 2-Even 3-Mark 4-Spase
                : data_bit    : Data bits(5,6,7,8 or 16)
Return value    : Error code  : Error code
******************************************************************************/
uint16_t usb_cpu_Sci_Set1(uint8_t *data_rate_top, uint8_t stop_bit, uint8_t parity, uint8_t data_bit)
{
    uint16_t ret_code = USB_OK;
    volatile register uint32_t  tmp;
    uint32_t data_rate;

    /* DATA RATE Set */
    data_rate = (uint32_t)data_rate_top[0];
    data_rate |= (uint32_t)data_rate_top[1] << 8;
    data_rate |= (uint32_t)data_rate_top[2] << 16;
    data_rate |= (uint32_t)data_rate_top[3] << 24;

    /* SCI desable
       CKE:0 Internal baud rate generator
       TIE,RIE,TE,RE,TEIE = 0 */
    /* Serial Control Register
    b0-b1 CKE  Clock enable bit 
    b2    TEIE Transmit End Interrupt enable bit
    b3    MPIE Mult Processor Interrupt enable bit
    b4    RE   Receive enable bit
    b5    TE   Transmit enable bit
    b6    RIE  Receive Interrupt enable bit
    b7    TIE  Transmit Interrupt enable bit
    */
    SCI1.SCR.BYTE = 0;
    SCI0.SCR.BYTE = 0;

    /* SCI1 TXI Interrypt clear */
    /* Interrupt request register
    b0    IR       Interrupt status flag
    b7-b1 Reserved 0
    */
    ICU.IR[218].BIT.IR = 0;	//TX1
    ICU.IR[215].BIT.IR = 0;	//TX0

    /* Serial Mode */
    /* Smart Card Mode Register
    b0    SMIF     Smart Card Interface Mode Select
    b1    Reserved 0
    b2    SINV     Smart Card Data Invert
    b3    SDIR     Smart Card Data Transfer Direction
    b6-b4 Reserved 0
    b7    BCP2     BCP2 Base Clock Pulse 2
    */
    SCI1.SCMR.BIT.SMIF  = 0;
    SCI0.SCMR.BIT.SMIF  = 0;

    /* Clock source PCLK */
    /* Serial Mode Register
    b0-b1 CKS  Clock Select bit
    b2    MP   Mult Processor mode bit
    b3    STOP Stop bit length bit
    b4    PM   Parity Mode bit
    b5    PE   Parity Enable bit
    b6    CHR  CHARACTER length bit
    b7    CM   Communication Mode bit
    */
    SCI1.SMR.BIT.CKS = USB_SCI_CLK_0DIVID_FREQ;
    SCI0.SMR.BIT.CKS = USB_SCI_CLK_0DIVID_FREQ;

    /* DATA RATE Setting */
    switch(data_rate)
    {
    case USB_SCI_SPEED_1200:
        /* Clock source PCLK/4 */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.CKS = USB_SCI_CLK_16DIVID_FREQ;
	SCI0.SMR.BIT.CKS = USB_SCI_CLK_16DIVID_FREQ;
        /* 48MHz,  1200bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_1200;
	SCI0.BRR = USB_SCI_BRR_1200;
        break;

    case USB_SCI_SPEED_2400:
        /* Clock source PCLK/4 */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.CKS = USB_SCI_CLK_16DIVID_FREQ;
	SCI0.SMR.BIT.CKS = USB_SCI_CLK_16DIVID_FREQ;
        /* 48MHz,  2400bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_2400;
	SCI0.BRR = USB_SCI_BRR_2400;
        break;

    case USB_SCI_SPEED_4800:
        /* Clock source PCLK/4 */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.CKS = USB_SCI_CLK_4DIVID_FREQ;
	SCI0.SMR.BIT.CKS = USB_SCI_CLK_4DIVID_FREQ;
        /* 48MHz,  4800bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_4800;
        SCI0.BRR = USB_SCI_BRR_4800;
        break;

    case USB_SCI_SPEED_9600:
        /* 48MHz,  9600bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_9600;
        SCI0.BRR = USB_SCI_BRR_9600;
        break;

    case USB_SCI_SPEED_14400:
        /* 48MHz,  14400bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_14400;
        SCI0.BRR = USB_SCI_BRR_14400;
        break;

    case USB_SCI_SPEED_19200:
        /* 48MHz,  19200bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_19200;
        SCI0.BRR = USB_SCI_BRR_19200;
        break;

    case USB_SCI_SPEED_38400:
        /* 48MHz,  38400bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_38400;
        SCI0.BRR = USB_SCI_BRR_38400;
        break;

    case USB_SCI_SPEED_57600:
        /* 48MHz,  57600bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_57600;
        SCI0.BRR = USB_SCI_BRR_57600;
        break;

    case USB_SCI_SPEED_115200:
        /* 48MHz,  115200bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_115200;
        SCI0.BRR = USB_SCI_BRR_115200;
        break;
 
    case USB_SCI_SPEED_250000:
        /* 48MHz,  250000bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_250000;
        SCI0.BRR = USB_SCI_BRR_250000;
        break;
    case USB_SCI_SPEED_500000:
        /* 48MHz,  500000bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_500000;
        SCI0.BRR = USB_SCI_BRR_500000;
        break;
	
	case USB_SCI_SPEED_750000:
        /* 48MHz,  500000bps */
        /* Bit Rate Register
        b0-b7 BRR
        */
        SCI1.BRR = USB_SCI_BRR_750000;
        SCI0.BRR = USB_SCI_BRR_750000;
        break;
	
	default:
        ret_code = USB_NG;
        break;
    }

    /* STOP BIT Setting */
    if(stop_bit == USB_SCI_STOP_BIT_1)
    {
        /* 1stop bit */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.STOP = USB_SCI_1STOP_BIT;
	SCI0.SMR.BIT.STOP = USB_SCI_1STOP_BIT;
    }
    else if(stop_bit == USB_SCI_STOP_BIT_2)
    {
        /* 2stop bit */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.STOP = USB_SCI_2STOP_BIT;
	SCI0.SMR.BIT.STOP = USB_SCI_2STOP_BIT;
    }
    else
    {
        ret_code = USB_NG;
    }

    /* PARITY BIT Setting */
    if(parity == USB_SCI_PARITY_BIT_NONE)
    {
        /* Parity disable */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.PE = USB_SCI_PARITY_DISABLE;
	SCI0.SMR.BIT.PE = USB_SCI_PARITY_DISABLE;
    }
    else if(parity == USB_SCI_PARITY_BIT_ODD)
    {
        /* Parity enable */
        /* Parity mode odd */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.PE = USB_SCI_PARITY_ENABLE;
        SCI1.SMR.BIT.PM = USB_SCI_PARITY_ODD;
	SCI0.SMR.BIT.PE = USB_SCI_PARITY_ENABLE;
        SCI0.SMR.BIT.PM = USB_SCI_PARITY_ODD;
    }
    else if(parity == USB_SCI_PARITY_BIT_EVEN)
    {
        /* Parity enable */
        /* Parity mode even */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.PE = USB_SCI_PARITY_ENABLE;
        SCI1.SMR.BIT.PM = USB_SCI_PARITY_EVEN;
	SCI0.SMR.BIT.PE = USB_SCI_PARITY_ENABLE;
        SCI0.SMR.BIT.PM = USB_SCI_PARITY_EVEN;
    }
    else
    {
        ret_code = USB_NG;
    }

    /* CHARACTER LENGTH Setting */
    if(data_bit == USB_SCI_DATA_BIT_8)
    {
        /* character length 8bit */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.CHR = USB_SCI_8BIT_DATA;
	SCI0.SMR.BIT.CHR = USB_SCI_8BIT_DATA;
    }
    else if(data_bit == USB_SCI_DATA_BIT_7)
    {
        /* character length 7bit */
        /* Serial Mode Register
        b0-b1 CKS  Clock Select bit
        b2    MP   Mult Processor mode bit
        b3    STOP Stop bit length bit
        b4    PM   Parity Mode bit
        b5    PE   Parity Enable bit
        b6    CHR  CHARACTER length bit
        b7    CM   Communication Mode bit
        */
        SCI1.SMR.BIT.CHR = USB_SCI_7BIT_DATA;
	SCI0.SMR.BIT.CHR = USB_SCI_7BIT_DATA;
    }
    else
    {
        ret_code = USB_NG;
    }

    /* Wait 1bit time more */
    for( tmp = 0; tmp < 6400; ++tmp ) {
    }

    /* Serial Control Register
    b0-b1 CKE  Clock enable bit 
    b2    TEIE Transmit End Interrupt enable bit
    b3    MPIE Mult Processor Interrupt enable bit
    b4    RE   Receive enable bit
    b5    TE   Transmit enable bit
    b6    RIE  Receive Interrupt enable bit
    b7    TIE  Transmit Interrupt enable bit
    */
    SCI1.SCR.BIT.TIE    = USB_SCI_ENABLE;
    SCI1.SCR.BIT.RIE    = USB_SCI_ENABLE;
    SCI1.SCR.BYTE       |= USB_SCI_SCI_BYTE_TE_RE;
    SCI0.SCR.BIT.TIE    = USB_SCI_ENABLE;
    SCI0.SCR.BIT.RIE    = USB_SCI_ENABLE;
    SCI0.SCR.BYTE       |= USB_SCI_SCI_BYTE_TE_RE;

    return ret_code;
}
/******************************************************************************
End of function usb_cpu_Sci_Set1
******************************************************************************/


/******************************************************************************
Function Name   : usb_cpu_Sci_ER_Int
Description     : ComPort Receive Error Interrupt.
                : Group 12 SCI1 ERI0 (SCI1 reception error) GEN12.EN0 
                : GRP12.IS0 GCR12.CLR0. Interrupt #114.
Arguments       : -
Return value    : -
******************************************************************************/
void usb_cpu_Sci_ER_Int(void)
{
    /* Serial Status Register read */
    /* Serial Status Register
    b0 MPBT Mult Processor Bit Transfer bit
    b1 MPB  Mult Processor Bit
    b2 TEND Transmit End flag
    b3 PER  Parity Error
    b4 FER  Freaming Error
    b5 ORER Over Run Error
    b6-b7 - Reserved
    */
    *(uint8_t *)&usb_gpcdc_com_port_ssr = SCI1.SSR.BYTE | SCI0.SSR.BYTE;
    
    /* Group Interrupt Source register (GROUPL12 SCI1 ERI read)
    b0 IS0 Interrupt Status Flag 0 : SCI0 ERI0
    b1 IS1 Interrupt Status Flag 1 : SCI1 ERI1
    b2 IS2 Interrupt Status Flag 2 : SCI2 ERI2
    b3 IS3 Interrupt Status Flag 3 : SCI3 ERI3
    b4 IS4 Interrupt Status Flag 4 : SCI12 ERI12
    b5 IS5 Interrupt Status Flag 5 : RSPI0 SPEI0
    b6 IS6 Interrupt Status Flag 6 : RSPI1 SPEI1
    b31-b7 Reserved 0
    */
    do
    {
    SCI1.SSR.BYTE = 0;
    SCI0.SSR.BYTE = 0;
    }
    while( ICU.GRP[12].BIT.IS1 != 0 );
}
/******************************************************************************
End of function usb_cpu_Sci_ER_Int
******************************************************************************/


/******************************************************************************
Function Name   : usb_cpu_Sci_RX_Int
Description     : ComPort Receive Interrupt
Arguments       : none
                : 
Return value    : none
******************************************************************************/
void usb_cpu_Sci1_RX_Int(void)
{
    /* Serial Status error clear */
    *(uint8_t *)&usb_gpcdc_com_port_ssr = 0;

    /* Receive data store */
    /* Receive Data Register
    b0-7 :RDR
    */
    usb_gpcdc_srxdata[usb_gpcdc_srx_wp] = SCI1.RDR;
    /* Receive data write pointer update */
    usb_gpcdc_srx_wp++;
    if(usb_gpcdc_srx_wp >= USB_SCI_BUFFER_SIZE_MAX)
    {
        usb_gpcdc_srx_wp = 0;
    }
}
/******************************************************************************
End of function usb_cpu_Sci1_RX_Int
******************************************************************************/
/******************************************************************************
Function Name   : usb_cpu_Sci0_RX_Int
Description     : ComPort Receive Interrupt
Arguments       : none
                : 
Return value    : none
******************************************************************************/
void usb_cpu_Sci0_RX_Int(void)
{
    *(uint8_t *)&usb_gpcdc_com_port_ssr = 0;	/* Serial Status error clear */
    usb_gpcdc_srxdata[usb_gpcdc_srx_wp] = SCI0.RDR;
    /* Receive data write pointer update */
    usb_gpcdc_srx_wp++;
    if(usb_gpcdc_srx_wp >= USB_SCI_BUFFER_SIZE_MAX)
    {
        usb_gpcdc_srx_wp = 0;
    }
}
/******************************************************************************
End of function usb_cpu_Sci0_RX_Int
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci1_TX_Int
Description     : ComPort Transfer Buffer Empty Interrupt
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_Sci1_TX_Int(void)
{
    /* Send Data check */
    if(usb_gpcdc_stx_wp != usb_gpcdc_stx_rp)
    {
        /* Data send */
        /* Transmit Data Register
        b0-7 :TDR
        */
        SCI1.TDR =  usb_gpcdc_stxdata[usb_gpcdc_stx_rp];
	SCI0.TDR = usb_gpcdc_stxdata[usb_gpcdc_stx_rp];
	/* Send data pointer update */
        usb_gpcdc_stx_rp++;
        if(usb_gpcdc_stx_rp >= USB_SCI_BUFFER_SIZE_MAX)
        {
            usb_gpcdc_stx_rp = 0;
        }

        if(usb_gpcdc_stx_wp == usb_gpcdc_stx_rp)
        {
            /* Interrupt enable register (IEN0:TXI1 enable)
            b0 IEN0 Interrupt enable bit
            b1 IEN1 Interrupt enable bit
            b2 IEN2 Interrupt enable bit
            b3 IEN3 Interrupt enable bit
            b4 IEN4 Interrupt enable bit
            b5 IEN5 Interrupt enable bit
            b6 IEN6 Interrupt enable bit
            b7 IEN7 Interrupt enable bit
            */
            ICU.IER[0x1b].BIT.IEN2 = USB_SCI_DISABLE;
        }
    }
}
/******************************************************************************
End of function usb_cpu_Sci1_TX_Int
******************************************************************************/
/******************************************************************************
Function Name   : usb_cpu_Sci0_TX_Int
Description     : ComPort Transfer Buffer Empty Interrupt
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_Sci0_TX_Int(void)
{
    /* Send Data check */
    //PORT2.PODR.BIT.B4 = 1;		//RS-485 Tranciver mode
    if(usb_gpcdc_stx_wp != usb_gpcdc_stx_rp)
    {
	SCI1.TDR =  usb_gpcdc_stxdata[usb_gpcdc_stx_rp];
	SCI0.TDR = usb_gpcdc_stxdata[usb_gpcdc_stx_rp];
        /* Send data pointer update */
        usb_gpcdc_stx_rp++;
        if(usb_gpcdc_stx_rp >= USB_SCI_BUFFER_SIZE_MAX)
        {
            usb_gpcdc_stx_rp = 0;
        }
        if(usb_gpcdc_stx_wp == usb_gpcdc_stx_rp)
        {
            ICU.IER[0x1a].BIT.IEN7 = USB_SCI_DISABLE;
	    //PORT2.PODR.BIT.B4 = 0;		//RS-485 Reciver mode
        }
    }
}
/******************************************************************************
End of function usb_cpu_Sci0_TX_Int
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_TE_Int
Description     : ComPort Transfer End Interrupt
Arguments       : none
                : 
Return value    : none
******************************************************************************/
void usb_cpu_Sci_TE_Int(void)
{
}
/******************************************************************************
End of function usb_cpu_Sci_TE_Int
******************************************************************************/


/******************************************************************************
Function Name   : usb_cpu_Sci_HW_init
Description     : ComPort Hw Initialize
Argument        : none
Return          : none
******************************************************************************/
void usb_cpu_Sci_HW_init(void)
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

    /* SCI1 Enable */
    /* Module stop control register (Enable USB0 module(MSTPB19))
    b0     MSTPB0   CAN stop bit
    b14-b1 Reserved 0
    b15    MSTPB15  Ether DMA stop bit
    b16    MSTPB16  Serial peri1 stop bit
    b17    MSTPB17  Serial peri0 stop bit
    b18    MSTPB18  USB port1 stop bit
    b19    MSTPB19  USB port0 stop bit
    b20    MSTPB20  I2C interface1 stop bit
    b21    MSTPB21  I2C interface0 stop bit
    b22    Reserved 0
    b23    MSTPB23  CRC stop bit
    b24    Reserved 0
    b25    MSTPB25  Serial interface6 stop bit
    b26    MSTPB26  Serial interface5 stop bit
    b27    Reserved 0
    b28    MSTPB28  Serial interface3 stop bit
    b29    MSTPB29  Serial interface2 stop bit
    b30    MSTPB30  Serial interface1 stop bit
    b31    MSTPB31  Serial interface0 stop bit
    */
    SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;	//SCI1
    SYSTEM.MSTPCRB.BIT.MSTPB31 = 0;	//SCI0

    /* Protect register
    b0    PRC0     Protect bit0
    b1    PRC1     Protect bit1
    b2    Reserved 0
    b3    PRC3     Protect bit3
    b7-b4 Reserved 0
    b15-b8 PRKEY   PRC Key code bit
    */
    SYSTEM.PRCR.WORD    = 0xA500;   /* Protect on */

    /* TxD0-A=output */
    /* Data direction register
    b0 B0 Pn0 in/out select bit
    b1 B1 Pn1 in/out select bit
    b2 B2 Pn2 in/out select bit
    b3 B3 Pn3 in/out select bit
    b4 B4 Pn4 in/out select bit
    b5 B5 Pn5 in/out select bit
    b6 B6 Pn6 in/out select bit
    b7 B7 Pn7 in/out select bit
    */
    PORTD.PDR.BIT.B3    = 0;	//Set SCI_TXD1 = input
    PORTD.PDR.BIT.B5    = 0;	//Set SCI_RXD1 = input
    
    PORT2.PDR.BIT.B2 = 0;		//Set SCI_RXD0 = input
    PORT2.PDR.BIT.B3 = 0;		//Set SCI_TXD0 = input
    PORT2.PDR.BIT.B4 = 0;		//Set SCI_CTS0 = input
    
    /* Port mode register (Disable TXD1)
    b0 B0 Pn0 pin mode control bit
    b1 B1 Pn1 pin mode control bit
    b2 B2 Pn2 pin mode control bit
    b3 B3 Pn3 pin mode control bit
    b4 B4 Pn4 pin mode control bit
    b5 B5 Pn5 pin mode control bit
    b6 B6 Pn6 pin mode control bit
    b7 B7 Pn7 pin mode control bit
    */
    PORTD.PMR.BIT.B3    = 0;	//Disable SCI_TXD1
    PORT2.PMR.BIT.B3    = 0;	//Disable SCI_TXD0
    
    /* Port mode register (Disable RXD1)
    b0 B0 Pn0 pin mode control bit
    b1 B1 Pn1 pin mode control bit
    b2 B2 Pn2 pin mode control bit
    b3 B3 Pn3 pin mode control bit
    b4 B4 Pn4 pin mode control bit
    b5 B5 Pn5 pin mode control bit
    b6 B6 Pn6 pin mode control bit
    b7 B7 Pn7 pin mode control bit
    */
    PORTD.PMR.BIT.B5    = 0;	//Disable SCI_RXD1
    PORT2.PMR.BIT.B2    = 0;	//Disable SCI_RXD0
    PORT2.PMR.BIT.B4    = 0;	//Disable SCI_CTS0

    /* Port mode register write enable */
    /* PWPR.PFSWE write protect off */
    /* Write protect register
    b5-b0 Reserved 0
    b6 PFSWE    PFS register write enable bit
    b7 BOWI     PFSWE bit write disable bit
    */
    MPC.PWPR.BYTE           = 0x00;

    /* PFS register write protect off */
    /* Write protect register
    b5-b0 Reserved 0
    b6 PFSWE    PFS register write enable bit
    b7 BOWI     PFSWE bit write disable bit
    */
    MPC.PWPR.BYTE           = 0x40;

    /* TXD0 select */
    /* PortD-bit3 Pin function select register
    b4-b0 PSEL  Pin function select bit
    b5 Reserved 0
    b6 ISEL     Interrupt input function select bit
    b7 Reserved 0
    */
    MPC.PD3PFS.BYTE         = 0x0a;	//Select PD3 to TXD1
    MPC.P23PFS.BYTE         = 0x0a;	//Select P23 to TXD0

    /* RXD0 select */
    /* PortD-bit5 Pin function select register
    b4-b0 PSEL  Pin function select bit
    b5 Reserved 0
    b6 ISEL     Interrupt input function select bit
    b7 Reserved 0
    */
    MPC.PD5PFS.BYTE         = 0x0a;	//Select PD5 to RXD1
    MPC.P22PFS.BYTE         = 0x0a;	//Select P22 to RXD0
    MPC.P24PFS.BYTE         = 0x0a;	//Select P24 to CTS0

    /* Port mode register write disable */
    /* PFS register write protect on */
    /* Write protect register
    b5-b0 Reserved 0
    b6 PFSWE    PFS register write enable bit
    b7 BOWI     PFSWE bit write disable bit
    */
    MPC.PWPR.BYTE           = 0x80;

    /* Port mode register (Enable TXD1)
    b0 B0 Pn0 pin mode control bit
    b1 B1 Pn1 pin mode control bit
    b2 B2 Pn2 pin mode control bit
    b3 B3 Pn3 pin mode control bit
    b4 B4 Pn4 pin mode control bit
    b5 B5 Pn5 pin mode control bit
    b6 B6 Pn6 pin mode control bit
    b7 B7 Pn7 pin mode control bit
    */
    PORTD.PMR.BIT.B3    = 1;	//Enable SCI_TXD1
    PORT2.PMR.BIT.B3    = 1;	//Enable SCI_TXD0

    /* Port mode register (Enable RXD1)
    b0 B0 Pn0 pin mode control bit
    b1 B1 Pn1 pin mode control bit
    b2 B2 Pn2 pin mode control bit
    b3 B3 Pn3 pin mode control bit
    b4 B4 Pn4 pin mode control bit
    b5 B5 Pn5 pin mode control bit
    b6 B6 Pn6 pin mode control bit
    b7 B7 Pn7 pin mode control bit
    */
    PORTD.PMR.BIT.B5    = 1;	//Enable SCI_RXD1
    PORT2.PMR.BIT.B2    = 1;	//Enable SCI_RXD0
    //PORT2.PMR.BIT.B4    = 1;	//Enable SCI_CTS0

    /* TxD1-A=output */
    /* Data direction register
    b0 B0 Pn0 in/out select bit
    b1 B1 Pn1 in/out select bit
    b2 B2 Pn2 in/out select bit
    b3 B3 Pn3 in/out select bit
    b4 B4 Pn4 in/out select bit
    b5 B5 Pn5 in/out select bit
    b6 B6 Pn6 in/out select bit
    b7 B7 Pn7 in/out select bit
    */
    PORTD.PDR.BIT.B3    = 1;	//Set SCI_TXD1 = output
    PORT2.PDR.BIT.B3 = 1;		//Set SCI_TXD0 = output
    PORT2.PDR.BIT.B4 = 1;		//Set SCI_CTS0 = output
    PORT2.PODR.BIT.B4 = 0;
    /* RxD1-A=input */
    /* Data direction register
    b0 B0 Pn0 in/out select bit
    b1 B1 Pn1 in/out select bit
    b2 B2 Pn2 in/out select bit
    b3 B3 Pn3 in/out select bit
    b4 B4 Pn4 in/out select bit
    b5 B5 Pn5 in/out select bit
    b6 B6 Pn6 in/out select bit
    b7 B7 Pn7 in/out select bit
    */
    PORTD.PDR.BIT.B5    = 0;	//Set SCI_RXD1 = input
    PORT2.PDR.BIT.B2 = 0;		//Set SCI_RXD0 = input

    /* Interrupt enable */
    /* Interrupt enable register (IEN1:RXI1 enable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[0x1b].BIT.IEN1 = USB_SCI_ENABLE;	//SCI_RXD1 enable
    ICU.IER[0x1a].BIT.IEN6 = USB_SCI_ENABLE;	//SCI_RXD0 enable

    /* Interrupt enable register (IEN2:TXI1 enable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[0x1b].BIT.IEN2 = USB_SCI_DISABLE;	//SCI_TXD1 disable
    ICU.IER[0x1a].BIT.IEN7 = USB_SCI_DISABLE;	//SCI_TXD0 disable

    /* Interrupt enable register (IEN3:TEI1 enable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[0x1b].BIT.IEN3 = USB_SCI_ENABLE;	//SCI_TEI1 enable
    ICU.IER[0x1b].BIT.IEN0 = USB_SCI_ENABLE;	//SCI_TEI0 enable
    
    /* Priority SCI1=5
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[217].BYTE = USB_SCI_SCI_INT_LV;
    ICU.IPR[214].BYTE = USB_SCI_SCI_INT_LV;

    /* Priority GROUPL12=5
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[114].BYTE = USB_SCI_SCI_INT_LV;

    /* Group Interrupt enable register (GROUPL12 SCI1 ERI enable)
    b0 EN0 Interrupt request enable bit
    b1 EN1 Interrupt request enable bit
    b2 EN2 Interrupt request enable bit
    b3 EN3 Interrupt request enable bit
    b4 EN4 Interrupt request enable bit
    b5 EN5 Interrupt request enable bit
    b6 EN6 Interrupt request enable bit
    b7 EN7 Interrupt request enable bit
    b8 EN8 Interrupt request enable bit
    b9 EN9 Interrupt request enable bit
    b10 EN10 Interrupt request enable bit
    b11 EN11 Interrupt request enable bit
    b12 EN12 Interrupt request enable bit
    b13 EN13 Interrupt request enable bit
    b14 EN14 Interrupt request enable bit
    b15 EN15 Interrupt request enable bit
    b31-b16 Reserved 0
    */
    ICU.GEN[12].BIT.EN0 = USB_SCI_ENABLE;	//SCI0 ERI enable
    ICU.GEN[12].BIT.EN1 = USB_SCI_ENABLE;	//SCI1 ERI enable

    /* Interrupt enable register (IEN2:GROUPL12 enable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[0x0e].BIT.IEN2 = USB_SCI_ENABLE;
}
/******************************************************************************
End of function usb_cpu_Sci_HW_init
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_enable
Description     : Serial port enable (SCI1)
Argument        : none
Return          : none
******************************************************************************/
void usb_cpu_Sci_enable(void)
{
    /* TE = 1, RE = 1 */
    /* Serial Control Register
    b0-b1 CKE  Clock enable bit 
    b2    TEIE Transmit End Interrupt enable bit
    b3    MPIE Mult Processor Interrupt enable bit
    b4    RE   Receive enable bit
    b5    TE   Transmit enable bit
    b6    RIE  Receive Interrupt enable bit
    b7    TIE  Transmit Interrupt enable bit
    */
    SCI1.SCR.BYTE       |= USB_SCI_SCI_BYTE_TE_RE;
}
/******************************************************************************
End of function usb_cpu_Sci_enable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_disable
Description     : Serial port disable (SCI1)
Argument        : none
Return          : none
******************************************************************************/
void usb_cpu_Sci_disable(void)
{
    /* TE = 1, RE = 1 */
    /* Serial Control Register
    b0-b1 CKE  Clock enable bit 
    b2    TEIE Transmit End Interrupt enable bit
    b3    MPIE Mult Processor Interrupt enable bit
    b4    RE   Receive enable bit
    b5    TE   Transmit enable bit
    b6    RIE  Receive Interrupt enable bit
    b7    TIE  Transmit Interrupt enable bit
    */
    SCI1.SCR.BYTE       &= 0xcf;
    SCI0.SCR.BYTE       &= 0xcf;
}
/******************************************************************************
End of function usb_cpu_Sci_disable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_EnableStatus
Description     : Serial Port Enable State Get process
Argument        : none
Return          : 1-Serial port enable 0-Serial port disable
******************************************************************************/
uint16_t usb_cpu_Sci_EnableStatus(void)
{
    uint16_t enable = USB_SCI_DISABLE;

    /* TE & RE check */
    /* Serial Control Register
    b0-b1 CKE  Clock enable bit 
    b2    TEIE Transmit End Interrupt enable bit
    b3    MPIE Mult Processor Interrupt enable bit
    b4    RE   Receive enable bit
    b5    TE   Transmit enable bit
    b6    RIE  Receive Interrupt enable bit
    b7    TIE  Transmit Interrupt enable bit
    */
    if((SCI1.SCR.BYTE & USB_SCI_SCI_BYTE_TE_RE)
        == USB_SCI_SCI_BYTE_TE_RE)
    {
        /* TX enable & RX enable */
        enable = USB_SCI_ENABLE;
    }

    return enable;
}
/******************************************************************************
End of function usb_cpu_Sci_EnableStatus
******************************************************************************/
#endif /* USB_UART_ENABLE */

/******************************************************************************
Function Name   : usb_cpu_Sci_Buffer_init
Description     : Serial Tx Rx data buffer clear
Argument        : none
Return          : none
******************************************************************************/
void usb_cpu_Sci_Buffer_init(void)
{
    /* Comm Port Tx data buffer */
    memset((void *)&usb_gpcdc_stxdata[0],0,USB_SCI_BUFFER_SIZE_MAX);
    /* Comm Port Rx data buffer */
    memset((void *)&usb_gpcdc_srxdata[0],0,USB_SCI_BUFFER_SIZE_MAX);
    /* Comm Port Tx data buffer data count */
    usb_gpcdc_stx_wp = 0;
    /* Comm Port Rx data buffer Read Pointer */
    usb_gpcdc_stx_rp = 0;

    /* Comm Port Rx data buffer Write Pointer */
    usb_gpcdc_srx_wp = 0;
    /* Comm Port Rx data buffer Read Pointer */
    usb_gpcdc_srx_rp = 0;
}
/******************************************************************************
End of function usb_cpu_Sci_Buffer_init
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_DataReceive
Description     : Communications Port Data Receive Process
Arguments       : tranadr     : Transfer Data Address
                : length      : Transfer Data Length
Return value    : uint16_t    : Receive data byte count
******************************************************************************/
uint16_t usb_cpu_Sci_DataReceive(uint8_t *tranadr,uint16_t receive_length)
{
    uint16_t length;
    uint16_t wp;
    uint16_t i;

    /* Write pointer read  */
    wp = usb_gpcdc_srx_wp;

    /* Comm Port receive data count check */
    if(wp == usb_gpcdc_srx_rp)
    {
        return 0;   /* No receive data */
    }
    else if(wp > usb_gpcdc_srx_rp)
    {
        /* Read pointer not late */
        length = wp - usb_gpcdc_srx_rp;
    }
    else
    {
        /* Read pointer late */
        length = USB_SCI_BUFFER_SIZE_MAX - usb_gpcdc_srx_rp + wp;
    }

    /* Read length check */
    if( length > receive_length )
    {
        length = receive_length;
    }

    /* Receive data copy */
    for(i =0; i <length; i++)
    {
        tranadr[i] = usb_gpcdc_srxdata[usb_gpcdc_srx_rp];
        usb_gpcdc_srx_rp++;
        if(usb_gpcdc_srx_rp >= USB_SCI_BUFFER_SIZE_MAX)
        {
            usb_gpcdc_srx_rp = 0;
        }
    }

    return length;
}
/******************************************************************************
End of function usb_cpu_Sci_DataReceive
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_DataSend
Description     : Communications Port Data Send Process
Arguments       : tranadr     : Transfer Data Address
                : length      : Transfer Data Length
Return value    : uint16_t    : 1-Echo mode data copy request
******************************************************************************/
void usb_cpu_Sci_DataSend(uint16_t mode, void *tranadr, uint16_t length)
{
    uint16_t    copy_size1,copy_size2;

    /* Buffer Store Data size check */
    if((usb_gpcdc_stx_wp + length) <= USB_SCI_BUFFER_SIZE_MAX)
    {
        /* All data store for Current Page  */
        memcpy(&usb_gpcdc_stxdata[usb_gpcdc_stx_wp], tranadr, length);
        /* Store Data counter update */
        usb_gpcdc_stx_wp += length;
        if(usb_gpcdc_stx_wp >= USB_SCI_BUFFER_SIZE_MAX)
        {
            usb_gpcdc_stx_wp = 0;
        }
    }
    else
    {
        /* Current Page copy size */
        copy_size1 = USB_SCI_BUFFER_SIZE_MAX - usb_gpcdc_stx_wp;
        /* Reverse Page copy size */
        copy_size2 = length - copy_size1;

        /* Data Store Separation */
        memcpy(&usb_gpcdc_stxdata[usb_gpcdc_stx_wp], tranadr, copy_size1);

        /* Data Store Separation */
        memcpy(&usb_gpcdc_stxdata[0], ((uint8_t *)tranadr + copy_size1), copy_size2);

        /* Store Data counter update */
        usb_gpcdc_stx_wp = copy_size2;
    }

#ifdef USB_UART_ENABLE
    /* Echo mode check */
    if(mode != USB_SCI_MODE_ECHO)
    {
    	if(usb_gpcdc_stx_wp != usb_gpcdc_stx_rp)
	{
		//PORT2.PODR.BIT.B4 = 1;
		/*if(ICU.IER[0x1b].BIT.IEN2 == USB_SCI_DISABLE)
        	{
			ICU.IER[0x1b].BIT.IEN2 = USB_SCI_ENABLE;
		}*/
		if(ICU.IER[0x1a].BIT.IEN7 == USB_SCI_DISABLE)
        	{
			ICU.IER[0x1a].BIT.IEN7 = USB_SCI_ENABLE;
		}
	}

	/* Data Send check */
//        if(ICU.IER[0x1b].BIT.IEN2 == USB_SCI_DISABLE)
//        {
//            /* Send Start */
//            /* Send Data count check */
//            if(usb_gpcdc_stx_wp != usb_gpcdc_stx_rp)
//           {
                /* Transmit interrupt enable */
                /* Interrupt enable register (IEN7:TXI1 enable)
                b0 IEN0 Interrupt enable bit
                b1 IEN1 Interrupt enable bit
                b2 IEN2 Interrupt enable bit
                b3 IEN3 Interrupt enable bit
                b4 IEN4 Interrupt enable bit
                b5 IEN5 Interrupt enable bit
                b6 IEN6 Interrupt enable bit
                b7 IEN7 Interrupt enable bit
                */
//                ICU.IER[0x1b].BIT.IEN2 = USB_SCI_ENABLE;
//            }
//        }
/*	if(ICU.IER[0x1a].BIT.IEN7 == USB_SCI_DISABLE)
        {
            if(usb_gpcdc_stx_wp != usb_gpcdc_stx_rp)
            {
                ICU.IER[0x1a].BIT.IEN7 = USB_SCI_ENABLE;
            }
        }
*/    }
#endif /* USB_UART_ENABLE */
}
/******************************************************************************
End of function usb_cpu_Sci_DataSend
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_CopyData_for_Echo
Description     : Echo mode data copy Serial TX -> Serial RX
Argument        : none
Return          : Error code
******************************************************************************/
uint16_t usb_cpu_Sci_CopyData_for_Echo(void)
{
    uint16_t srx_ptr_check;

    while(1)
    {
        /* Send Data check */
        if(usb_gpcdc_stx_wp != usb_gpcdc_stx_rp)
        {
            /* Receive data write pointer update for Copy Stop Check */
            srx_ptr_check = usb_gpcdc_srx_wp + 1;
            if( srx_ptr_check >= USB_SCI_BUFFER_SIZE_MAX )
            {
                srx_ptr_check = 0;
            }
            /* Copy Stop Check */
            if( srx_ptr_check == usb_gpcdc_srx_rp )
            {
                break;
            }

            /* Receive data store */
            usb_gpcdc_srxdata[usb_gpcdc_srx_wp]
                = usb_gpcdc_stxdata[usb_gpcdc_stx_rp];

            /* Receive data write pointer update */
            usb_gpcdc_srx_wp++;
            if(usb_gpcdc_srx_wp >= USB_SCI_BUFFER_SIZE_MAX)
            {
                usb_gpcdc_srx_wp = 0;
            }
            /* Send data pointer update */
            usb_gpcdc_stx_rp++;
            if(usb_gpcdc_stx_rp >= USB_SCI_BUFFER_SIZE_MAX)
            {
                usb_gpcdc_stx_rp = 0;
            }
        }
        else
        {
            /* Transfer end */
            break;
        }
    }

    return USB_OK;
}
/******************************************************************************
End of function usb_cpu_Sci_CopyData_for_Echo
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_GetSerialState
Description     : Serial State Get process
Argument        : SeraalState(CDC PSTN Subclass UART State bitmap) store addr
Return          : 1-Serial error detect
******************************************************************************/
uint16_t usb_cpu_Sci_GetSerialState(uint16_t *serial_state)
{
    USB_SCI_SerialState_t *state;
    uint16_t ret_code = USB_OK;

    state = (USB_SCI_SerialState_t *)serial_state;

    /* State initalize */
    *serial_state = USB_SCI_CLEAR;

    if(usb_gpcdc_com_port_ssr.ORER)
    {
        /* Over Run error */
        state->bOverRun = USB_ON;
        ret_code = 1;
    }
    if(usb_gpcdc_com_port_ssr.FER)
    {
        /* Framing error */
        state->bFraming = USB_ON;
        ret_code = USB_SCI_ERR_DETECT;
    }
    if(usb_gpcdc_com_port_ssr.PER)
    {
        /* Parity error */
        state->bParity = USB_ON;
        ret_code = USB_SCI_ERR_DETECT;
    }

    return ret_code;
}
/******************************************************************************
End of function usb_cpu_Sci_GetSerialState
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_StxBuffStatus
Description     : Serial port send buffer status check
Arguments       : none
                : 
Return value    : Serial port send buffer status 1:Busy 0:Not Busy
******************************************************************************/
uint16_t usb_cpu_Sci_StxBuffStatus(void)
{
    uint16_t ret_code = 0;
    uint16_t wp_tmp;
    uint16_t rp,wp;

    rp = usb_gpcdc_stx_rp;
    wp = usb_gpcdc_stx_wp;

    /* Serial Transfer Buffer Space calc */
    if(wp < rp)
    {
        /* Write pointer < Read pointer */
        wp_tmp = rp - wp;
    }
    else if(wp > rp)
    {
        /* Write pointer > Read pointer */
        wp_tmp = rp
            + (USB_SCI_BUFFER_SIZE_MAX- wp);
    }
    else    /* wp = rp */
    {
        /* Write pointer = Read pointer */
        wp_tmp = USB_SCI_BUFFER_SIZE_MAX;
    }

    /* Buffer Space check */
    if( USB_SCI_STX_BUFF_MARGIN >= wp_tmp )
    {
        /* Read pointer Overtake */
        ret_code = USB_SCI_BUFF_BUSY;
    }

    return ret_code;
}
/******************************************************************************
End of function usb_cpu_Sci_StxBuffStatus
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Sci_SetDataChk
Description     : Line coding set data check
Arguments       : data_rate   : Data terminal rate in bits per second
                : stop_bit    : Stop bits 0-1Stopbit 1-1.5Stopbit 2-2Stopbit
                : parity      : Parity 0-None 1-Odd 2-Even 3-Mark 4-Spase
                : data_bit    : Data bits(5,6,7,8 or 16)
Return value    : Error code  : Error code
******************************************************************************/
uint16_t usb_cpu_Sci_SetDataChk(uint8_t *data_rate_top, uint8_t stop_bit, uint8_t parity, uint8_t data_bit)
{
    uint16_t ret_code = USB_OK;
    uint32_t data_rate;

    /* DATA RATE Set */
    data_rate = (uint32_t)data_rate_top[0];
    data_rate |= (uint32_t)data_rate_top[1] << 8;
    data_rate |= (uint32_t)data_rate_top[2] << 16;
    data_rate |= (uint32_t)data_rate_top[3] << 24;

    /* DATA RATE Setting */
    if((data_rate != USB_SCI_SPEED_1200)
        && (data_rate != USB_SCI_SPEED_2400)
        && (data_rate != USB_SCI_SPEED_4800)
        && (data_rate != USB_SCI_SPEED_9600)
        && (data_rate != USB_SCI_SPEED_14400)
        && (data_rate != USB_SCI_SPEED_19200)
        && (data_rate != USB_SCI_SPEED_38400)
        && (data_rate != USB_SCI_SPEED_57600)
        && (data_rate != USB_SCI_SPEED_115200)
	&& (data_rate != USB_SCI_SPEED_250000)
	&& (data_rate != USB_SCI_SPEED_500000)
	&& (data_rate != USB_SCI_SPEED_750000))
    {
        ret_code = USB_NG;
    }

    /* STOP BIT Setting */
    if((stop_bit != USB_SCI_STOP_BIT_1)
        && (stop_bit != USB_SCI_STOP_BIT_2))
    {
        ret_code = USB_NG;
    }

    /* PARITY BIT Setting */
    if((parity != USB_SCI_PARITY_BIT_NONE)
        && (parity != USB_SCI_PARITY_BIT_ODD)
        && (parity != USB_SCI_PARITY_BIT_EVEN))
    {
        ret_code = USB_NG;
    }

    /* CHARACTER LENGTH Setting */
    if((data_bit != USB_SCI_DATA_BIT_8) 
        && (data_bit != USB_SCI_DATA_BIT_7))
    {
        ret_code = USB_NG;
    }

    return ret_code;
}
/******************************************************************************
End of function usb_cpu_Sci_SetDataChk
******************************************************************************/

#pragma section _hw
/******************************************************************************
Function Name   : usb_cpu_target_init
Description     : Target System Initialize
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_target_init( void )
{
    /* initialized USB interrupt */
    usb_cpu_usbint_init();
    usb_cpu_DmaintInit();

#ifdef  USB_LED_ENABLE
    usb_cpu_LedInit();              /* Initialized RSK LED */
#endif /* USB_LED_ENABLE */

#ifdef USB_KEY_ENABLE
    usb_cpu_KeyInit();              /* Initialized RSK KEY */
#endif /* USB_KEY_ENABLE */

#ifdef USB_LCD_ENABLE
    usb_cpu_LcdInit();
#endif /* USB_LCD_ENABLE */
}
/******************************************************************************
End of function usb_cpu_target_init
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_FunctionUSB0IP
Description     : USB0 port mode and Switch mode Initialize
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_FunctionUSB0IP(void)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
/* Condition compilation by the difference of USB function */
  #if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
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
  #endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP */
/* Condition compilation by the difference of USB function */
  #if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP
    /* Set port direction as input(USB0 OVRCURA) */
    USB0_OVRCURA_PDR        = 0;
    USB0_OVRCURA_PMR        = 0;                    /* Port mode register (Disable USB0 OVRCURA) */
    USB0_VBUSEN_PDR         = 0;
    USB0_VBUSEN_PMR         = 0;                    /* Port mode register (Disable USB0 VBUSEN) */
    USB0_DRPD_PDR           = 0;
    USB0_DRPD_PMR           = 0;                    /* Port mode register (Disable USB0 DRPD) */
    USB0_DPRPD_PDR          = 0;
    USB0_DPRPD_PMR          = 0;                    /* Port mode register (Disable USB0 DPRPD) */

    /* Port mode register write enable */
    MPC.PWPR.BYTE           = 0x00;
    MPC.PWPR.BYTE           = 0x40;

    /* Initial setting of USB0 */
    USB0_OVRCURA_PFS        = USB0_OVRCURA_ENB;     /* OVRCURA input  enable */
    USB0_VBUSEN_PFS         = USB0_VBUSEN_ENB;      /* VBUSEN  output enable */
    USB0_DRPD_PFS           = USB0_DRPD_ENB;        /* DRPD    output enable */
    USB0_DPRPD_PFS          = USB0_DPRPD_ENB;       /* DPRPD   output enable */

    /* Port mode register write disable */
    MPC.PWPR.BYTE           = 0x80;                 /* PFS register write protect on */
    USB0_OVRCURA_PMR        = 1;                    /* Port mode register (Enable USB0 OVRCURA) */
    USB0_VBUSEN_PMR         = 1;                    /* Port mode register (Enable USB0 VBUSEN) */
    USB0_DRPD_PMR           = 1;                    /* Port mode register (Enable USB0 DRPD) */
    USB0_DPRPD_PMR          = 1;                    /* Port mode register (Enable USB0 DPRPD) */
  #endif  /* USB_FUNCSEL_USBIP0_PP == USB_HOST_PP */
#endif  /* USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP */
}
/******************************************************************************
End of function usb_cpu_FunctionUSB0IP
******************************************************************************/


/******************************************************************************
Function Name   : usb_cpu_usbint_init
Description     : USB interrupt Initialize
Arguments       : void
Return value    : void
******************************************************************************/
void usb_cpu_usbint_init(void)
{
    /* Protect register (protect off) */
    SYSTEM.PRCR.WORD            = 0xA503;   /* protect off */

/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
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

#endif  /* USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP */
    usb_cpu_FunctionUSB0IP();
}
/******************************************************************************
End of function usb_cpu_usbint_init
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_usb_int_hand
Description     : USB interrupt Handler
Arguments       : void
Return value    : void
******************************************************************************/
void usb_cpu_usb_int_hand(void)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
    /* Call USB interrupt routine */
    usb_cstd_UsbHandler();      /* Call interrupt routine */
#endif /* USB_FUNCSEL_USBIP0_PP */
}
/******************************************************************************
End of function usb_cpu_usb_int_hand
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_d0fifo_int_hand
Description     : D0FIFO interrupt Handler
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_d0fifo_int_hand(void)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
    usb_cstd_DmaHandler();      /* Call interrupt routine */
#endif /* USB_FUNCSEL_USBIP0_PP */
}
/******************************************************************************
End of function usb_cpu_d0fifo_int_hand
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_usb_int_hand_r
Description     : RESUME interrupt Handler
                : IRQ #90 (VECT_USB_USBR0)
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_usb_int_hand_r(void)
{
    USB_UTR_t       utr;

    utr.ip  = USB_USBIP_0;
    utr.ipp = usb_cstd_GetUsbIpAdr( utr.ip );

/* Condition compilation by the difference of the operating system */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
    /* Please add the processing for the system. */
    usb_preg_clr_sts_resm( &utr );       /* RESM status clear */
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */

#if USB_CPU_LPW_PP == USB_LPWR_USE_PP
    USB0_USBR_IPR               = 0x00;     /* Priority Resume0=0 */
#endif /* USB_CPU_LPW_PP == USB_LPWR_USE_PP */

    ICU.IR[IR_USB_USBR0].BIT.IR = 0;    /* Interrupt Request USB_resume USBR0 Clear */
}
/******************************************************************************
End of function usb_cpu_usb_int_hand_r
******************************************************************************/

/******************************************************************************
Renesas Abstracted RSK functions
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_int_enable
Description     : USB Interrupt Enable
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : void
******************************************************************************/
void usb_cpu_int_enable(USB_UTR_t *ptr)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
    /* Interrupt enable register (USB0 USBIO enable(IEN3)) */
    /* Interrupt enable register (USB0 D0/D1FIFO restore (IEN1/IEN2)) */
    USB0_USBIO_IER      = 1;
    USB0_D0FIFO_IER     = g_usb_D0fifoIER;
    USB0_D1FIFO_IER     = g_usb_D1fifoIER;
#endif  /* USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP */
}   /* eof usb_cpu_int_enable() */

/******************************************************************************
Function Name   : usb_cpu_int_disable
Description     : USB Interrupt disable
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : void
******************************************************************************/
void usb_cpu_int_disable(USB_UTR_t *ptr)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP
    /* Disable interrupt enable register (USB0 USBIO(IEN3)) */
    /* Backup & disable interrupt enable register (USB0 D0/D1FIFO (IEN1/IEN2)) */
    USB0_USBIO_IER      = 0;
    g_usb_D0fifoIER     = USB0_D0FIFO_IER;
    g_usb_D1fifoIER     = USB0_D1FIFO_IER;
    USB0_D0FIFO_IER     = 0;
#endif  /* USB_FUNCSEL_USBIP0_PP != USB_NOUSE_PP */
}
/******************************************************************************
End of function usb_cpu_int_disable
******************************************************************************/

/******************************************************************************
TIMER function
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_Delay1us
Description     : 1us Delay timer
Arguments       : uint16_t  time        ; Delay time(*1us)
Return value    : none
Note            : Please change for your MCU
******************************************************************************/
void usb_cpu_Delay1us(uint16_t time)
{
    volatile register uint16_t  i;

    /* Wait 1us (Please change for your MCU) */
    for( i = 0; i < (5 * time); ++i )
    {
    };
}
/******************************************************************************
End of function usb_cpu_Delay1us
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_DelayXms
Description     : xms Delay timer
Arguments       : uint16_t  time        ; Delay time(*1ms)
Return value    : void
Note            : Please change for your MCU
******************************************************************************/
void usb_cpu_DelayXms(uint16_t time)
{
    /* Wait xms (Please change for your MCU) */
    volatile register uint32_t  i;

    /* Wait 1ms */
    for( i = 0; i < (6500 * time); ++i )
    {
    };
        /* When "ICLK=48MHz" is set, this code is waiting for 1ms.
          Please change this code with CPU Clock mode. */
}
/******************************************************************************
End of function usb_cpu_DelayXms
******************************************************************************/

/******************************************************************************
SLEEP & STANDBY control function
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_GoLpwrSleep
Description     : Go low power sleep mode
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_GoLpwrSleep(USB_UTR_t *ptr)
{
/* Condition compilation by the difference of the operating system */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
    uint16_t    dev_info[8];
#endif /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */

    if( usb_cstd_is_host_mode(ptr) == USB_YES )
    {
/* Condition compilation by the difference of the devices */
  #if USB_CPU_LPW_PP == USB_LPWR_USE_PP
        if( usb_gcpu_RemoteProcess == USB_OFF )
        {
            /* Standby control register (Software Standby disable)
            b7-b0  Reserved 0
            b12-b8 STS      Standby timer select bit
            b13    Reserved 0
            b14    OPE      Output port enable bit
            b15    SSBY     Software standby bit
            */
            SYSTEM.SBYCR.BIT.SSBY       = 0;

            /* Goto WAIT */
            usb_cpu_GoWait();
        }
  #endif /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */
    }
    else
    {
/* Condition compilation by the difference of the operating system */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP

    /* Get USB Device information */
    R_usb_pstd_DeviceInformation(ptr, (uint16_t *)&dev_info );

/* Condition compilation by the difference of the devices */
  #if USB_CPU_LPW_PP == USB_LPWR_USE_PP
        if( usb_gcpu_RemoteProcess == USB_OFF )
        {
            /* Remote Wakeup Flag */
            if( dev_info[4] == USB_YES )
            {
//                usb_cpu_IRQ2_Enable(ptr);   /* IRQ2(RX63N-RSK_SW1) for Remote wakeup */
            }

            /* Standby control register (Software Standby disable)
            b7-b0  Reserved 0
            b12-b8 STS      Standby timer select bit
            b13    Reserved 0
            b14    OPE      Output port enable bit
            b15    SSBY     Software standby bit
            */
            SYSTEM.SBYCR.BIT.SSBY       = 0;

            /* Goto WAIT */
            usb_cpu_GoWait();

            /* Remote Wakeup Flag */
            if( dev_info[4] == USB_YES )
            {
                usb_gcpu_RemoteProcess = USB_ON;
            }
        }
  #endif /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
    }
}
/******************************************************************************
End of function usb_cpu_GoLpwrSleep
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_GoLpwrDeepStby
Description     : Go Low Power Deep Standby
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_GoLpwrDeepStby(USB_UTR_t *ptr)
{
    USB0_USBR_IPR               = 0x07;     /* Priority Resume0=2 */

    /* Protect register (protect off)
    b0    PRC0     Protect bit0
    b1    PRC1     Protect bit1
    b2    Reserved 0
    b3    PRC3     Protect bit3
    b7-b4 Reserved 0
    b15-b8 PRKEY   PRC Key code bit
    */
    SYSTEM.PRCR.WORD        = 0xA503;   /* protect off */

    /* DTC Transfer disable
    b0    DTCST    DTC module start bit
    b7-b1 Reserved 0
    */
    DTC.DTCST.BIT.DTCST     = 0;

    /* System clock control register3(CKSEL(10-8)=Sub clock)
    b7-b0   Reserved 0
    b10-b8  CKSEL    Clock source select bit
    b15-b11 Reserved 0
    */
    SYSTEM.SCKCR3.BIT.CKSEL         = 3;

    /* Standby control register (Software Standby Shift)
    b7-b0  Reserved 0
    b12-b8 STS      Standby timer select bit
    b13    Reserved 0
    b14    OPE      Output port enable bit
    b15    SSBY     Software standby bit
    */
    SYSTEM.SBYCR.BIT.SSBY       = 1;

    /* Goto WAIT */
    usb_cpu_GoWait();
}
/******************************************************************************
End of function usb_cpu_GoLpwrDeepStby
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_RegRecovEnable
Description     : Register Recover Enable
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_RegRecovEnable(USB_UTR_t *ptr)
{
    if( ptr->ip == USB_USBIP_0 )
    {
        /* Device state change register
        b14-b0 Reserved 0
        b15    DVCHG    Device state change bit
        */
        USB0.DVCHGR.BIT.DVCHG = 1;
    }
}
/******************************************************************************
End of function usb_cpu_RegRecovEnable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_RegRecovDisable
Description     : Register Recover Disable
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_RegRecovDisable(USB_UTR_t *ptr)
{
    if( ptr->ip == USB_USBIP_0 )
    {
        /* Device state change register
        b14-b0 Reserved 0
        b15    DVCHG    Device state change bit
        */
        USB0.DVCHGR.BIT.DVCHG = 0;
    }
}
/******************************************************************************
End of function usb_cpu_RegRecovDisable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_GoWait
Description     : Go Wait
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_GoWait(void)
{
    int_exception(11);              /* Goto usb_cpu_GoWait_Int() */
}
/******************************************************************************
End of function usb_cpu_GoWait
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_GoWait_Int
Description     : Go Wait Interrupt
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_GoWait_Int(void)
{
    wait();                         /* Wait */
}
/******************************************************************************
End of function usb_cpu_GoWait_Int
******************************************************************************/


/******************************************************************************
IRQ function
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ0_Enable
Description     : IRQ0 Interrupt Enable
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ0_Enable(void)
{
    /* Interrupt enable register (IEN0 disable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN0     = 0;        /* Interrupt disable */

    /* IRQ control register
    b1-b0 Reserved 0
    b3-b2 IRQMD    IRQ detect bit
    b7-b4 Reserved 0
    */
    ICU.IRQCR[0].BIT.IRQMD  = 1;        /* Down Edge Set */

    /* Priority Resume0=B
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[64].BYTE        = 0x0B;     /* Priority Resume0=B */

    /* Interrupt request register
    b0    IR       Interrupt status flag
    b7-b1 Reserved 0
    */
    ICU.IR[64].BIT.IR       = 0;

    /* Interrupt enable register (IEN0 enable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN0     = 1;
}
/******************************************************************************
End of function usb_cpu_IRQ0_Enable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ0_Disable
Description     : IRQ0 Interrupt Disable
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ0_Disable(void)
{
    /* Interrupt request register
    b0    IR       Interrupt status flag
    b7-b1 Reserved 0
    */
    ICU.IR[64].BIT.IR       = 0;

    /* Interrupt enable register
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN0     = 0;

    /* Priority Resume0=0
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[64].BYTE        = 0x00;
}
/******************************************************************************
End of function usb_cpu_IRQ0_Disable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ1_Enable
Description     : IRQ8 Interrupt Enable
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_IRQ1_Enable(USB_UTR_t *ptr)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP
    uint16_t    dev_info[8];

    if( usb_cstd_is_host_mode(ptr) == USB_NO )
    {

        /* Get USB Device information */
        R_usb_pstd_DeviceInformation(ptr, (uint16_t *)&dev_info );

        /* Remote Wakeup Flag */
        if( dev_info[4] == USB_YES )
        {
            /* Interrupt enable register (IEN1 disable))
            b0 IEN0 Interrupt enable bit
            b1 IEN1 Interrupt enable bit
            b2 IEN2 Interrupt enable bit
            b3 IEN3 Interrupt enable bit
            b4 IEN4 Interrupt enable bit
            b5 IEN5 Interrupt enable bit
            b6 IEN6 Interrupt enable bit
            b7 IEN7 Interrupt enable bit
            */
            ICU.IER[8].BIT.IEN1     = 0u;

            /* IRQ control register
            b1-b0 Reserved 0
            b3-b2 IRQMD    IRQ detect bit
            b7-b4 Reserved 0
            */
            ICU.IRQCR[1].BIT.IRQMD  = 1u;   /* Down Edge Set */

            /* Priority Resume0=B
            b3-b0 IPR      Interrupt priority
            b7-b4 Reserved 0
            */
            ICU.IPR[65].BYTE        = 0x0B;

            /* Interrupt request register
            b0    IR       Interrupt status flag
            b7-b1 Reserved 0
            */
            ICU.IR[65].BIT.IR       = 0u;

            /* Interrupt enable register (IEN1 enable)
            b0 IEN0 Interrupt enable bit
            b1 IEN1 Interrupt enable bit
            b2 IEN2 Interrupt enable bit
            b3 IEN3 Interrupt enable bit
            b4 IEN4 Interrupt enable bit
            b5 IEN5 Interrupt enable bit
            b6 IEN6 Interrupt enable bit
            b7 IEN7 Interrupt enable bit
            */
            ICU.IER[8].BIT.IEN1     = 1u;
        }
    }
#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */

    if( usb_cstd_is_host_mode(ptr) == USB_YES )
    {
        /* Interrupt enable register (IEN1 disable))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[8].BIT.IEN1     = 0u;

        /* IRQ control register
        b1-b0 Reserved 0
        b3-b2 IRQMD    IRQ detect bit
        b7-b4 Reserved 0
        */
        ICU.IRQCR[1].BIT.IRQMD  = 1u;   /* Down Edge Set */

        /* Priority Resume0=B
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[65].BYTE        = 0x0B;

        /* Interrupt request register
        b0    IR       Interrupt status flag
        b7-b1 Reserved 0
        */
        ICU.IR[65].BIT.IR       = 0u;

        /* Interrupt enable register (IEN1 enable)
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[8].BIT.IEN1     = 1u;
    }
}
/******************************************************************************
End of function usb_cpu_IRQ1_Enable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ1_Disable
Description     : IRQ1 Interrupt Disable
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ1_Disable(void)
{
    /* Interrupt request register
    b0    IR       Interrupt status flag
    b7-b1 Reserved 0
    */
    ICU.IR[65].BIT.IR           = 0u;

    /* Interrupt enable register (IEN1 disable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN1         = 0u;

    /* Priority Resume0=0(Disable)
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[65].BYTE            = 0x00;
}
/******************************************************************************
End of function usb_cpu_IRQ1_Disable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ2_Enable
Description     : IRQ2 Interrupt Enable
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ2_Enable(void)
{
    /* Interrupt enable register (IEN2 disable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN2     = 0;        /* Interrupt disable */

    /* IRQ control register
    b1-b0 Reserved 0
    b3-b2 IRQMD    IRQ detect bit
    b7-b4 Reserved 0
    */
    ICU.IRQCR[2].BIT.IRQMD  = 1;        /* Down Edge Set */

    /* Priority Resume0=B
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[66].BYTE        = 0x0B;     /* Priority Resume0=B */

    /* Interrupt request register
    b0    IR       Interrupt status flag
    b7-b1 Reserved 0
    */
    ICU.IR[66].BIT.IR       = 0;

    /* Interrupt enable register (IEN2 enable)
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN2     = 1;
}
/******************************************************************************
End of function usb_cpu_IRQ2_Enable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ2_Disable
Description     : IRQ2 Interrupt Disable
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ2_Disable(void)
{
    /* Interrupt request register
    b0    IR       Interrupt status flag
    b7-b1 Reserved 0
    */
    ICU.IR[66].BIT.IR       = 0;

    /* Interrupt enable register
    b0 IEN0 Interrupt enable bit
    b1 IEN1 Interrupt enable bit
    b2 IEN2 Interrupt enable bit
    b3 IEN3 Interrupt enable bit
    b4 IEN4 Interrupt enable bit
    b5 IEN5 Interrupt enable bit
    b6 IEN6 Interrupt enable bit
    b7 IEN7 Interrupt enable bit
    */
    ICU.IER[8].BIT.IEN2     = 0;

    /* Priority Resume0=0
    b3-b0 IPR      Interrupt priority
    b7-b4 Reserved 0
    */
    ICU.IPR[66].BYTE        = 0x00;
}
/******************************************************************************
End of function usb_cpu_IRQ2_Disable
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ0Int
Description     : IRQ0 Interrupt process
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ0Int(void)
{
}
/******************************************************************************
End of function usb_cpu_IRQ0Int
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ1Int
Description     : IRQ1 Interrupt process
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ1Int(void)
{
/* Condition compilation by the difference of USB function */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP

/* Condition compilation by the difference of the devices */
#if (USB_CPU_LPW_PP == USB_LPWR_USE_PP)
    USB_UTR_t utr;
    USB_UTR_t *ptr;

    ptr = (USB_UTR_t *)&utr;
    ptr->ip = USB_PERI_USBIP_NUM;
    ptr->ipp = usb_cstd_GetUsbIpAdr( ptr->ip );

    R_usb_pstd_PcdChangeDeviceState(ptr, USB_DO_REMOTEWAKEUP, (uint16_t)0, (USB_CB_INFO_t)usb_cstd_DummyFunction);
    usb_cpu_IRQ2_Disable();
#endif /* (USB_CPU_LPW_PP == USB_LPWR_USE_PP) */

#endif  /* USB_FUNCSEL_USBIP0_PP == USB_PERI_PP || USB_FUNCSEL_USBIP1_PP == USB_PERI_PP */
}
/******************************************************************************
End of function usb_cpu_IRQ1Int
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_IRQ2Int
Description     : IRQ2 Interrupt process
Arguments       : none
Return value    : none
******************************************************************************/
void usb_cpu_IRQ2Int(void)
{
}
/******************************************************************************
End of function usb_cpu_IRQ2Int
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_GetDPSRSTF
Description     : Get Deep Software Standby Reset Flag
Arguments       : none
Return value    : Deep Software Standby Reset Flag
******************************************************************************/
uint8_t usb_cpu_GetDPSRSTF(void)
{
    /* Reset status register (Deep software standby reset check)
    b0    POFR     Power on reset Detection flag
    b1    LVD0F    Voltage Watch 0 reset detection flag
    b2    LVD1F    Voltage Watch 1 reset detection flag
    b3    LVD2F    Voltage Watch 2 reset detection flag
    b6-b4 Reserved 0
    b7    DPSRSTF  Deep software standby reset flag
    */
    return (uint8_t)SYSTEM.RSTSR0.BIT.DPSRSTF;
}
/******************************************************************************
End of function usb_cpu_GetDPSRSTF
******************************************************************************/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    DMA function
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/******************************************************************************
Function Name   : usb_cpu_DmaintInit
Description     : DMA interrupt Initialize
Arguments       : void
Return value    : void
******************************************************************************/
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
End of function usb_cpu_DmaintInit
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_d0fifo2buf_start_dma
Description     : FIFO to Buffer data read DMA start
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
                : uint32_t SourceAddr   : Source address
Return value    : void
******************************************************************************/
void usb_cpu_d0fifo2buf_start_dma(USB_UTR_t *ptr, uint32_t SourceAddr)
{
/* Condition compilation by the difference of the devices */
#if USB_TRANS_MODE_PP == USB_TRANS_DMA_PP
#endif /* USB_TRANS_MODE_PP == USB_TRANS_DMA_PP */

/* Condition compilation by the difference of the devices */
#if USB_TRANS_MODE_PP == USB_TRANS_DTC_PP
    uint16_t    size;
    uint32_t    tmp;

    /* DTC Transfer enable
    b0    DTCST    DTC module start bit
    b7-b1 Reserved 0
    */
    DTC.DTCST.BIT.DTCST         = 1;

    /* DTC control register (Transfer Information Read No Skip)
    b2-b0 Reserved 0
    b3    Reserved 0
    b4    RRS      DTC Transfer Information Read Skip enable bit
    b7-b5 Reserved 0
    */
    DTC.DTCCR.BIT.RRS           = 0;

    /* DTC mode register A (Block Transfer Set)
    b1-b0 Reserved 0
    b3-b2 SM       source address mode bit
    b5-b4 SZ       DTC data transfer size bit
    b7-b6 MD       DTC mode bit
    */
    usb_dtcreg[ptr->ip].MRA.BIT.MD      = 2;

    tmp                     = ((usb_gcstd_Dma0Fifo[ptr->ip] -1)/ 2) +1;

    /* DTC mode register A (Word Size)
    b1-b0 Reserved 0
    b3-b2 SM       source address mode bit
    b5-b4 SZ       DTC data transfer size bit
    b7-b6 MD       DTC mode bit
    */
    usb_dtcreg[ptr->ip].MRA.BIT.SZ  = 1;

    /* DTC mode register A (Source Address fixed)
    b1-b0 Reserved 0
    b3-b2 SM       source address mode bit
    b5-b4 SZ       DTC data transfer size bit
    b7-b6 MD       DTC mode bit
    */
    usb_dtcreg[ptr->ip].MRA.BIT.SM      = 0;

    /* DTC mode register B (Chain Transfer disable)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.CHNE        = 0;

    /* DTC mode register B (Select Data Transfer End Interrupt)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.DISEL   = 0;

    /* DTC mode register B (Source Side Block Area)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.DTS     = 1;

    /* DTC mode register B (Destination Address Increment)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.DM      = 2;

    /* DTC source address register (FIFO port address)
    b31-b0 SAR Destination address
    */
    usb_dtcreg[ptr->ip].SAR             = SourceAddr;

    /* DTC source address register (Table address)
    b31-b0 SAR Source address
    */
    usb_dtcreg[ptr->ip].DAR = (uint32_t)(usb_gcstd_DataPtr[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]]);

    size    = (uint8_t )(tmp);
    size    += (uint16_t)(tmp << 8);

    /* DTC transfer count registerA
    b15-b0 CRA Transfer count
    */
    usb_dtcreg[ptr->ip].CRA             = (uint16_t)(size);

    /* DTC transfer count registerB (Block count)
    b15-b0 CRB Transfer count
    */
    usb_dtcreg[ptr->ip].CRB = (uint16_t)((usb_gcstd_DataCnt[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]] -1)
        / usb_gcstd_Dma0Fifo[ptr->ip]) +1;

    /* DTC address mode register (Full Address Mode)
    b0    SHORT    Short address mode bit
    b7-b1 Reserved 0
    */
    DTC.DTCADMOD.BIT.SHORT      = 0;

    /* DTC control register (Transfer Information Read No Skip)
    b2-b0 Reserved 0
    b3    Reserved 0
    b4    RRS      DTC Transfer Information Read Skip enable bit
    b7-b5 Reserved 0
    */
    DTC.DTCCR.BIT.RRS           = 1;

    if( ptr->ip == USB_USBIP_0 )
    {
        /* Priority D0FIFO0=0
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[33].BYTE            = 0x00;

        /* Interrupt enable register (USB0 D0FIFO enable(IEN4))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[0x04].BIT.IEN1      = 1;

        /* DTC start enable register (USB0 D0FIFO transfer)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[33].BIT.DTCE      = 1;
    }
    else
    {
        /* Priority D1FIFO0=0
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[36].BYTE            = 0x00;

        /* Interrupt enable register (USB1 D0FIFO enable(IEN4))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[0x04].BIT.IEN4      = 1;

        /* DTC start enable register (USB1 D0FIFO transfer)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[36].BIT.DTCE      = 1;
    }
#endif /* USB_TRANS_MODE_PP == USB_TRANS_DTC_PP */
}
/******************************************************************************
End of function usb_cpu_d0fifo2buf_start_dma
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_buf2d0fifo_start_dma
Description     : Buffer to FIFO data write DMA start
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
                : uint32_t DistAddr     : Destination address
Return value    : void
******************************************************************************/
void usb_cpu_buf2d0fifo_start_dma(USB_UTR_t *ptr, uint32_t DistAddr)
{
/* Condition compilation by the difference of the devices */
#if USB_TRANS_MODE_PP == USB_TRANS_DMA_PP
#endif /* USB_TRANS_MODE_PP == USB_TRANS_DMA_PP */

/* Condition compilation by the difference of the devices */
#if USB_TRANS_MODE_PP == USB_TRANS_DTC_PP
    uint16_t    size;
    uint32_t    tmp;

    /* DTC Transfer enable
    b0    DTCST    DTC module start bit
    b7-b1 Reserved 0
    */
    DTC.DTCST.BIT.DTCST = 1;

    /* DTC control register (Transfer Information Read No Skip)
    b2-b0 Reserved 0
    b3    Reserved 0
    b4    RRS      DTC Transfer Information Read Skip enable bit
    b7-b5 Reserved 0
    */
    DTC.DTCCR.BIT.RRS = 0;

    /* DTC mode register A (Block Transfer Set)
    b1-b0 Reserved 0
    b3-b2 SM       source address mode bit
    b5-b4 SZ       DTC data transfer size bit
    b7-b6 MD       DTC mode bit
    */
    usb_dtcreg[ptr->ip].MRA.BIT.MD = 2;
    if( (usb_gcstd_Dma0Size[ptr->ip] & 0x0001) != 0 )
    {
        /* if count == odd */
        tmp = usb_gcstd_Dma0Size[ptr->ip];

        /* DTC mode register A (Byte Size)
        b1-b0 Reserved 0
        b3-b2 SM       source address mode bit
        b5-b4 SZ       DTC data transfer size bit
        b7-b6 MD       DTC mode bit
        */
        usb_dtcreg[ptr->ip].MRA.BIT.SZ  = 0;
    }
    else
    {
        tmp                     = usb_gcstd_Dma0Size[ptr->ip] / 2;

        /* DTC mode register A (Word Size)
        b1-b0 Reserved 0
        b3-b2 SM       source address mode bit
        b5-b4 SZ       DTC data transfer size bit
        b7-b6 MD       DTC mode bit
        */
        usb_dtcreg[ptr->ip].MRA.BIT.SZ  = 1;
    }

    /* DTC mode register A (Source Address Increment)
    b1-b0 Reserved 0
    b3-b2 SM       source address mode bit
    b5-b4 SZ       DTC data transfer size bit
    b7-b6 MD       DTC mode bit
    */
    usb_dtcreg[ptr->ip].MRA.BIT.SM      = 2;

    /* DTC mode register B (Chain Transfer disable)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.CHNE        = 0;

    /* DTC mode register B (Select Data Transfer End Interrupt)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.DISEL   = 0;

    /* DTC mode register B (Destination Side Block Area)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.DTS     = 0;

    /* DTC mode register B (Destination Address fixed)
    b1-b0 Reserved 0
    b3-b2 DM       Destination address mode bit
    b4    DTS      DTC transfer mode select bit
    b5    DISEL    DTC interrupt select bit
    b6    CHNS     DTC chain transfer select bit
    b7    CHNE     DTC chain transfer enable bit
    */
    usb_dtcreg[ptr->ip].MRB.BIT.DM      = 0;

    /* DTC source address register (Table address)
    b31-b0 SAR Destination address
    */
    usb_dtcreg[ptr->ip].SAR = (uint32_t)(usb_gcstd_DataPtr[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]]);

    /* DTC source address register (FIFO port address)
    b31-b0 SAR Source address
    */
    usb_dtcreg[ptr->ip].DAR             = (uint32_t)(DistAddr);
    size    = (uint8_t )(tmp);
    size    += (uint16_t)(tmp << 8);

    /* DTC transfer count registerA
    b15-b0 CRA Transfer count
    */
    usb_dtcreg[ptr->ip].CRA             = (uint16_t)(size);

    /* DTC transfer count registerB (Block count)
    b15-b0 CRB Transfer count
    */
    usb_dtcreg[ptr->ip].CRB = (uint16_t)(usb_gcstd_DataCnt[ptr->ip][usb_gcstd_Dma0Pipe[ptr->ip]]
        / usb_gcstd_Dma0Size[ptr->ip]);

    /* DTC address mode register (Full Address Mode)
    b0    SHORT    Short address mode bit
    b7-b1 Reserved 0
    */
    DTC.DTCADMOD.BIT.SHORT      = 0;

    /* DTC control register (Transfer Information Read No Skip)
    b2-b0 Reserved 0
    b3    Reserved 0
    b4    RRS      DTC Transfer Information Read Skip enable bit
    b7-b5 Reserved 0
    */
    DTC.DTCCR.BIT.RRS           = 1;

    if( ptr->ip == USB_USBIP_0 )
    {
        /* Priority D0FIFO0=0
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[33].BYTE            = 0x00;

        /* Interrupt enable register (USB0 D0FIFO enable(IEN4))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[0x04].BIT.IEN1      = 1;

        /* DTC start enable register (USB0 D0FIFO transfer)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[33].BIT.DTCE      = 1;
    }
    else
    {
        /* Priority D1FIFO0=0
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[36].BYTE            = 0x00;

        /* Interrupt enable register (USB1 D0FIFO enable(IEN4))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[0x04].BIT.IEN4      = 1;

        /* DTC start enable register (USB1 D0FIFO transfer)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[36].BIT.DTCE      = 1;
    }
#endif /* USB_TRANS_MODE_PP == USB_TRANS_DTC_PP */
}
/******************************************************************************
End of function usb_cpu_buf2d0fifo_start_dma
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_d0fifo_stop_dma
Description     : DMA stop
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : void
******************************************************************************/
void usb_cpu_d0fifo_stop_dma(USB_UTR_t *ptr)
{
    if( ptr->ip == USB_USBIP_0 )
    {
        /* Interrupt request register
        b0    IR       Interrupt status flag
        b7-b1 Reserved 0
        */
        ICU.IR[33].BIT.IR           = 0;

        /* Priority D0FIFO0=0
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[33].BYTE            = 0x00;

        /* Interrupt enable register (USB0 D0FIFO disable(IEN4))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[0x04].BIT.IEN1      = 0;

        /* DTC start enable register (USB0 D0FIFO transfer disable)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[33].BIT.DTCE      = 0;
    }
    else
    {
        /* Interrupt request register
        b0    IR       Interrupt status flag
        b7-b1 Reserved 0
        */
        ICU.IR[36].BIT.IR           = 0;

        /* Priority D1FIFO0=0
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[36].BYTE            = 0x00;

        /* Interrupt enable register (USB1 D0FIFO disable(IEN4))
        b0 IEN0 Interrupt enable bit
        b1 IEN1 Interrupt enable bit
        b2 IEN2 Interrupt enable bit
        b3 IEN3 Interrupt enable bit
        b4 IEN4 Interrupt enable bit
        b5 IEN5 Interrupt enable bit
        b6 IEN6 Interrupt enable bit
        b7 IEN7 Interrupt enable bit
        */
        ICU.IER[0x04].BIT.IEN4      = 0;

        /* DTC start enable register (USB1 D0FIFO transfer disable)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[36].BIT.DTCE      = 0;
    }
}
/******************************************************************************
End of function usb_cpu_d0fifo_stop_dma
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_d0fifo_restart_dma
Description     : DMA Restart
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_d0fifo_restart_dma( USB_UTR_t *ptr )
{
/* Condition compilation by the difference of the devices */
 #if USB_TRANS_MODE_PP == USB_TRANS_DMA_PP
 #endif /* USB_TRANS_MODE_PP == USB_TRANS_DMA_PP */

/* Condition compilation by the difference of the devices */
 #if USB_TRANS_MODE_PP == USB_TRANS_DTC_PP
    uint16_t    size;
    uint32_t    tmp;

    if( (usb_gcstd_Dma0Size[ptr->ip] & 0x0001u) != 0u )
    {
        /* if count == odd */
        tmp = usb_gcstd_Dma0Size[ptr->ip];

        /* DTC mode register A (Byte Size)
        b1-b0 Reserved 0
        b3-b2 SM       source address mode bit
        b5-b4 SZ       DTC data transfer size bit
        b7-b6 MD       DTC mode bit
        */
        usb_dtcreg[ptr->ip].MRA.BIT.SZ  = 0;
    }
    else
    {
        tmp = usb_gcstd_Dma0Size[ptr->ip] / 2;

        /* DTC mode register A (Word Size)
        b1-b0 Reserved 0
        b3-b2 SM       source address mode bit
        b5-b4 SZ       DTC data transfer size bit
        b7-b6 MD       DTC mode bit
        */
        usb_dtcreg[ptr->ip].MRA.BIT.SZ  = 1;
    }
    size    = (uint8_t )(tmp);
    size    += (uint16_t)(tmp << 8);

    /* DTC transfer count registerA
    b15-b0 CRA Transfer count
    */
    usb_dtcreg[ptr->ip].CRA             = (uint16_t)(size);

    /* DTC transfer count registerB (Block count)
    b15-b0 CRB Transfer count
    */
    usb_dtcreg[ptr->ip].CRB             = (uint16_t)(1);

    /* DTC Transfer enable
    b0    DTCST    DTC module start bit
    b7-b1 Reserved 0
    */
    DTC.DTCST.BIT.DTCST         = 1;

    if( ptr->ip == USB_USBIP_0 )
    {
        /* DTC start enable register (USB0 D0FIFO transfer)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[33].BIT.DTCE      = 1;
    }
    else
    {
        /* DTC start enable register (USB1 D0FIFO transfer)
        b0    DTCE     DTC start enable bit
        b7-b1 Reserved 0
        */
        ICU.DTCER[36].BIT.DTCE      = 1;
    }

 #endif /* USB_TRANS_MODE_PP == USB_TRANS_DTC_PP */
}
/******************************************************************************
End of function usb_cpu_d0fifo_restart_dma
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_d0fifo_enable_dma
Description     : DTC(D0FIFO) interrupt enable (Interrupt priority 5 set)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_d0fifo_enable_dma(USB_UTR_t *ptr)
{
    if( ptr->ip == USB_USBIP_0 )
    {
        /* Priority D0FIFO0=0(Disable)
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[33].BYTE    = 0x05; /* USB0 */
    }
    else
    {
        /* Priority D0FIFO0=0(Disable)
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[36].BYTE    = 0x05; /* USB1 */
    }
}
/******************************************************************************
End of function usb_cpu_d0fifo_enable_dma
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_d0fifo_disable_dma
Description     : D0FIFO interrupt disable (Interrupt priority 0 set)
Arguments       : USB_UTR_t *ptr  : USB internal structure. Selects USB channel. 
Return value    : none
******************************************************************************/
void usb_cpu_d0fifo_disable_dma(USB_UTR_t *ptr)
{
    if( ptr->ip == USB_USBIP_0 )
    {
        /* Priority D0FIFO0=0(Disable)
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[33].BYTE    = 0x00; /* USB0 */
    }
    else
    {
        /* Priority D0FIFO0=0(Disable)
        b3-b0 IPR      Interrupt priority
        b7-b4 Reserved 0
        */
        ICU.IPR[36].BYTE    = 0x00; /* USB1 */
    }
}
/******************************************************************************
End of function usb_cpu_d0fifo_disable_dma
******************************************************************************/

/******************************************************************************
Function Name   : usb_cpu_get_dtc_block_count
Description     : 
Arguments       : USB_UTR_t *ptr        : USB internal structure. Selects USB channel. 
Return value    : 
******************************************************************************/
uint16_t usb_cpu_get_dtc_block_count(USB_UTR_t *ptr)
{
    return usb_dtcreg[ptr->ip].CRB;
}   /* eof usb_cpu_get_dtc_block_count() */

/******************************************************************************
End  Of File
******************************************************************************/

static uint16_t uwSet(uint16_t* uwTar, uint16_t uwVal){
	*uwTar |= uwVal;
	return 0;	
}

static uint16_t uwReset(uint16_t* uwTar, uint16_t uwVal){
	*uwTar &= ~uwVal;
	return 0;	
}

static uint16_t uwCheck(uint16_t* uwTar, uint16_t uwVal){
	if ((*uwTar & uwVal)!=0)
		return 1;
	return 0;
}

uint16_t ReadRamDataRX63T(uint16_t uwAddr){
	uint16_t uwData;
	if (uwAddr < 0xC000){// On-chip RAM, DINO, 07/05/2010
		uwData = memadd_rd(uwAddr);
	}
	else{               // ADC0, ADC1, ADC2
		uwData = memadd_rd1(uwAddr);
	}
	return uwData;
}

void USB_vdTxHandler(void){
	
	uint16_t	state;
	
	if (PC_ubTxState==USB_TXFULL){
		
		/* Change Tx control state */
		PC_ubTxState = USB_TXSTANDBY;
		
		/* Comm port receive data -> CDC Host send */
		write( usb_spcdc_data_fn, (uint8_t*)&usb_gpcdc_send_data, USB_uwTxOutCnt);

        /* Write status check */
        control( usb_spcdc_data_fn, USB_CTL_GET_WR_STATE, (void*)&state );
		
		usb_gpcdc_tx_wait_flag = USB_ON;
	
		USB_uwTxOutCnt = 0;
	}
	
}

typedef struct UsbMntRx_Ch{
	uint16_t	uwHeader;
	uint16_t	uwAddr;
	uint8_t		ubLRC;	
}USBMNTRX_CHN;

typedef struct UsbMntRx{
	uint8_t	ubIni[2];
	USBMNTRX_CHN	stCh1;
	USBMNTRX_CHN	stCh2;
	USBMNTRX_CHN	stCh3;
	USBMNTRX_CHN	stCh4;
}USBMNTRX;

extern UBYTE ubNew_VfdExplorerFlag;

void USB_vdRxDecoder(void){			
	
	UWORD_UNION uwTmp;
	UWORD uwCRC;
	UBYTE ubLen;
	USBMNTRX	stUsbMntRxBuf;
	UBYTE	ubBuf[USB_ubRXMAX];
	// RxDecoder for multi-protocol, Sean, 20141030
	//
	// NOTE: Rx is based on 64Bytes per unit now...
	//
	if (USB_ubRxCnt != 0){	
		
		if (USB_ubRxData[0]==0x3A){	 
			// PC monitor
			if (USB_ubRxData[1]==0x3A){	    
				switch (PC_TransState){
					case USB_STOP:
						if (USB_ubRxCnt==22){	// MNTR: USB_START commmand
							
							// assing RX data to MNT RX BUF
							memcpy(stUsbMntRxBuf.ubIni,USB_ubRxData,2);
							memcpy(&stUsbMntRxBuf.stCh1.uwHeader,USB_ubRxData+2,5);
							memcpy(&stUsbMntRxBuf.stCh2.uwHeader,USB_ubRxData+7,5);
							memcpy(&stUsbMntRxBuf.stCh3.uwHeader,USB_ubRxData+12,5);
							memcpy(&stUsbMntRxBuf.stCh4.uwHeader,USB_ubRxData+17,5);
							
							// Endin Alteration
							stUsbMntRxBuf.stCh1.uwAddr = USB_uwBytChg(stUsbMntRxBuf.stCh1.uwAddr);
							stUsbMntRxBuf.stCh2.uwAddr = USB_uwBytChg(stUsbMntRxBuf.stCh2.uwAddr);
							stUsbMntRxBuf.stCh3.uwAddr = USB_uwBytChg(stUsbMntRxBuf.stCh3.uwAddr);
							stUsbMntRxBuf.stCh4.uwAddr = USB_uwBytChg(stUsbMntRxBuf.stCh4.uwAddr);
						/*	
							// check data LRC (check passed)
							ubTmp[0] = USB_vdLRCGen(&stUsbMntRxBuf.stCh1.uwHeader, 4);
							ubTmp[1] = USB_vdLRCGen(&stUsbMntRxBuf.stCh2.uwHeader, 4);
							ubTmp[2] = USB_vdLRCGen(&stUsbMntRxBuf.stCh3.uwHeader, 4);
							ubTmp[3] = USB_vdLRCGen(&stUsbMntRxBuf.stCh4.uwHeader, 4);
						*/	
							/* PCmonitor Start Mode */
							/* reset variable*/
							PC_TransState = USB_START;	
							PC_TxPktCnt = 0;
							PC_TxChkSum = 0;						
							USB_ubRxCnt = 0;			
							
							Ch1Add = stUsbMntRxBuf.stCh1.uwAddr;
							Ch2Add = stUsbMntRxBuf.stCh2.uwAddr;
							Ch3Add = stUsbMntRxBuf.stCh3.uwAddr;
							Ch4Add = stUsbMntRxBuf.stCh4.uwAddr;
			    			
			    			memset(	USB_ubRxData, 0, USB_ubRXMAX);	
	            			
							/* PCmonitor Start Byte */
							USB_uwTxOutCnt = 2;
							USB_ubTxData_0[0] = PC_INITBYTE;
							USB_ubTxData_0[1] = PC_STARTBYTE; 
							
							memset(usb_gpcdc_send_data,0,USB_PCDC_APL_SRX_SIZE);
							memcpy(usb_gpcdc_send_data,USB_ubTxData_0,USB_uwTxOutCnt);	// 200us for USB routine, Sean, 2014/09/16	
							PC_ubTxState = USB_TXFULL;						
						}
						break;
					case USB_START:
						if (USB_ubRxCnt==2)	{	// MNTR: USB_STOP commmand
							memset(	USB_ubRxData, 0, USB_ubRXMAX);
							PC_TransState = USB_STOP;
							USB_ubRxCnt = 0;							
							USB_RxTime = 0;							// fix pc monitor abnormal stop, Sean, 09/19/2011
							USB_vdIniTx(1);//fix restart will recieve noice--11/10/2016						
						}
						break;
					default:
						break;
				}
			}
			// Bootloader: jump to bootloader
			else if ((USB_ubRxData[7] == 0x55) && // Bootloader enable, Sean, 20141022	// bootloader over usb for online mode, Sean, 20141030
    			(USB_ubRxData[8] == 0x55) && 
    			(USB_ubRxData[9] == 0x55) && 
    			(USB_ubRxData[10] == 0x55) && 
    			(USB_ubRxData[15] == 0x0D) && 
    			(USB_ubRxData[16] == 0x0A)){	
    			/* Bootloader Reply Data */	
				USB_ubRxData[0] = 0x25;
				uwTmp.uw = USB_vdCRCGen(USB_ubRxData,13);
				memcpy(USB_ubTxData_0,USB_ubRxData,13);
				USB_ubTxData_0[13] = uwTmp.ub.low;
				USB_ubTxData_0[14] = uwTmp.ub.hi;
				USB_ubTxData_0[15] = 0x0D;
				USB_ubTxData_0[16] = 0x0A;		
	    		
				memcpy(usb_gpcdc_send_data,USB_ubTxData_0,USB_ubRxCnt);
				USB_uwTxOutCnt = USB_ubRxCnt;
				PC_ubTxState = USB_TXFULL;
				
				memset(USB_ubRxData,0,USB_ubRxCnt);
				USB_ubRxCnt = 0;	
				LV_REC();//ready to jmp to BLD , need to rec Pr.--1/10/2017
#if BOOTLOADER_ENABLE					
				//jump to Bootloader initial: use default BLD address(switch.h)
				SWITCH_Initial_Val();
				switchFlag = 1;
#endif				
			}
		}

	// =======================VFD Explorer==========================
		else if (USB_ubRxData[0]==0xFF && uwVfd_Explorer_Flag == 0x0001){ 

		  //--------chk crc is right or not-------------------------------------7/8/2015
	  	  uwCRC = crc_16( USB_ubRxData, (USB_ubRxCnt-2),0xffff);
	  	  if((((uwCRC & 0xff00)>>8 == USB_ubRxData[USB_ubRxCnt-1]) && (uwCRC & 0x00ff) == USB_ubRxData[USB_ubRxCnt-2])
	  	    	|| (USB_ubRxData[USB_ubRxCnt-2]== 0x11 && USB_ubRxData[USB_ubRxCnt-1] == 0x22)){

			uwVfd_Explorer_Count = 0;//if in explorer mode ,then clear count//7/2/2015

			/* RX cmd Buffering */	// VFD Explorer: main module (test)	// modbus framework, Sean, 20141225
			memcpy(ubBuf,USB_ubRxData,USB_ubRxCnt);

			//----to check if this cmd exsist in Modbus procotol-----aevin add---6/29/2015
			/* Data Layer: RX cmd Decoding */
			USB_ubRxCnt = modbus_decode(&ubBuf[1],USB_ubRxCnt-3);	//ID:1, CRC:2

			//if USB_ubRxCnt= 0 ,means no need to reply ----1/26/2016 
			if(USB_ubRxCnt>0){
				/* Header & CRC layer */
				USB_ubRxCnt += 1;	// ID Code
				uwCRC = crc_16( ubBuf, USB_ubRxCnt,0xffff);
				ubLen = USB_ubRxCnt + 2;	
			
			//--------bug happened , so MOdi to use down below method-------------Aevin 7/1/2015		
				#if 0	
				//不能連用3次memcpy
    			/* TX Reply Data Assemble*/	
    			memcpy(USB_ubTxData_0,&ubLen,1);				//LEN
				memcpy(USB_ubTxData_0+1,ubBuf,USB_ubRxCnt);		//ID+DATA
				memcpy(USB_ubTxData_0+USB_ubRxCnt+1,&uwCRC,2);	//CRC
				USB_ubRxCnt += 3;	// LEN(1) + CRC(2)
				#else
		
				USB_ubTxData_0[0] = ubLen;		
			//	for(i = 0 ; i <= USB_ubRxCnt ;i++)
			//		USB_ubTxData_0[1+i] = ubBuf[i];
				memcpy(USB_ubTxData_0+1,ubBuf,USB_ubRxCnt+1); 	//ID+DATA		
				memcpy(USB_ubTxData_0+1+USB_ubRxCnt,&uwCRC,2);	//CRC
				USB_ubRxCnt+=3;
				#endif		
			//------------------------------------------------------------------------------
			}
			/* TX Reply Data Send*/	
			memcpy(usb_gpcdc_send_data,USB_ubTxData_0,USB_ubRxCnt);
			USB_uwTxOutCnt = USB_ubRxCnt;
			PC_ubTxState = USB_TXFULL;
			
			memset(USB_ubRxData,0,USB_ubRxCnt);
			USB_ubRxCnt = 0;	
		  }	
		}
		// MODBUS?	// Bootloader enable, Sean, 20141022	// bootloader over usb for online mode, Sean, 20141030
		else{	
	//===========Modbus normal mode========================
			if (USB_ubRxData[0] == 0xFF && uwVfd_Explorer_Flag == 0x0000){	// ID	// modbus framework, Sean, 20141225

			  //--------chk crc is right or not-------------------------------------7/8/2015
	  	      uwCRC = crc_16( USB_ubRxData, (USB_ubRxCnt-2),0xffff);
	  	      if((((uwCRC & 0xff00)>>8 == USB_ubRxData[USB_ubRxCnt-1]) && (uwCRC & 0x00ff) == USB_ubRxData[USB_ubRxCnt-2])
	  	    	   || (USB_ubRxData[USB_ubRxCnt-2]== 0x11 && USB_ubRxData[USB_ubRxCnt-1] == 0x22)){
				/* RX cmd Buffering */
				memcpy(ubBuf,USB_ubRxData,USB_ubRxCnt);
		//-------Aevin modi ---------------------------------------7/2/2015		
		#if 0		
				/* Data Layer: RX cmd Decoding */
				USB_ubRxCnt = modbus_decode(&ubBuf[1],5);
				
				/* Header & CRC layer */
				USB_ubRxCnt += 1;	// ID Code
				uwCRC = crc_16( ubBuf, USB_ubRxCnt,0xffff);
				
    			/* TX Reply Data Assemble*/	
				memcpy(USB_ubTxData_0,ubBuf,USB_ubRxCnt);		//ID+DATA
				memcpy(USB_ubTxData_0+USB_ubRxCnt,&uwCRC,2);	//CRC
				USB_ubRxCnt += 2;	// LEN(1) + CRC(2)
		#else
				USB_ubRxCnt = modbus_decode(&ubBuf[1],USB_ubRxCnt-3);
				if(USB_ubRxCnt>0){		
				/* Header & CRC layer */
					USB_ubRxCnt += 1;	// ID Code
					uwCRC = crc_16( ubBuf, USB_ubRxCnt,0xffff);

					memcpy(USB_ubTxData_0,ubBuf,USB_ubRxCnt+1);	//ID+DATA		
					memcpy(USB_ubTxData_0 + USB_ubRxCnt,&uwCRC,2);	//CRC
					USB_ubRxCnt+=2;
				}
		#endif
		//------------------------------------------------------------------
				/* TX Reply Data Send*/	
				memcpy(usb_gpcdc_send_data,USB_ubTxData_0,USB_ubRxCnt);
				USB_uwTxOutCnt = USB_ubRxCnt;
				PC_ubTxState = USB_TXFULL;
				
				memset(USB_ubRxData,0,USB_ubRxCnt);
				USB_ubRxCnt = 0;
			  }	
			}
		}	
	}
	else{
		// move to RxCnt==0; make sure no rx-replied data overlapped usb_gpcdc_send_data, Sean, 20141225
		if (uwCheck(&Mntr_uwGenReg.uw, MNTR_TX_FULL)){

			if(ubNew_VfdExplorerFlag == 1){
				//new version of explorer-----1/26/2016
				usb_gpcdc_send_data[0] = 0xFF;
				usb_gpcdc_send_data[1] = 0x77;
				usb_gpcdc_send_data[2] = 0xAA;
				usb_gpcdc_send_data[3] = 0x55;
				memcpy(usb_gpcdc_send_data+4,&stMntrData[USB_ubTxOutIdx][0],800);	// Data
				memcpy(usb_gpcdc_send_data+800+4,&MNTR_uwCRC[USB_ubTxOutIdx],2);	// CRC
				USB_uwTxOutCnt = 806;
			}
			else{
				//---------old version of VD explorer-----------------
				memcpy(usb_gpcdc_send_data,&stMntrData[USB_ubTxOutIdx][0],800);	// Data
				memcpy(usb_gpcdc_send_data+800,&MNTR_uwCRC[USB_ubTxOutIdx],2);	// CRC
				USB_uwTxOutCnt = 802;
			}		
			/* set flag: TxFull, send data*/
			PC_ubTxState = USB_TXFULL;
			
			/* next packet preparation */				
			USB_ubTxOutIdx = (USB_ubTxOutIdx==1)?0:1;
			uwReset(&Mntr_uwGenReg.uw, MNTR_TX_FULL);
			
		}		
	}
	
	// Error: Timeout: 2sec	// fix pc monitor abnormal stop, Sean, 09/19/2011
	if (USB_ubRxCnt!=0)
		USB_RxTime = (USB_RxTime<10000)?USB_RxTime+1:USB_RxTime;
	else
		USB_RxTime = 0;
		
 	if (USB_RxTime>=10000){
 		USB_RxTime = 0;
		memset(	USB_ubRxData, 0, USB_ubRXMAX);
		USB_ubRxCnt = 0;
	}

	// Error: Length exceed: 22 bytes
	if (USB_ubRxCnt > 22){
		memset(	USB_ubRxData, 0, USB_ubRXMAX);
		USB_ubRxCnt = 0;
		USB_RxTime = 0;
	}		    
}	

void USB_vdIniClk(void){
	usb_cpu_target_init();
}

void USB_vdIniVar(void){
	usb_cstd_ScheInit();		
    usb_cstd_IdleTaskStart();   /* Idle Task Start */	
    usb_pcdc_task_start();      /* Start Peripheral USB driver */	 
}

void USB_vdIniTx(UBYTE flg){//flg=1: totally reinit ; flg=0:use for Explorer STOP cmd
	uint8_t i ;
	/* Reset Var */
	USB_ubTxBufIdx = 0;
	USB_ubTxOutIdx = 0;
	USB_ubTxCnt = 0;		
	USB_uwTxOutCnt = 0;
	PC_TxPktCnt = 0;
	PC_TxChkSum = 0;
	PC_ubTxState = USB_TXSTANDBY;
	memset(USB_ubTxData_0,0,USB_ubTXMAX);
	memset(usb_gpcdc_send_data,0,USB_PCDC_APL_SRX_SIZE);
	//------reinit all the vars---7/6/2016
	Mntr_uwGenReg.uw = 0x00;
	ChCount = 0;
	ChCountTmp = 0;
	for(i = 0 ; i < 20 ; i++)
		ChxAdd[i] = 0x00;
	memset(stMntrData[0],0,100);
	memset(stMntrData[1],0,100);
	if(flg == 1)//modi to fix re-run step-7/29/2016
		ubNew_VfdExplorerFlag = 0x00;
	
}

void USB_vdMonitor_Sample(void){
	
	uint8_t ubTmp;
	uint8_t* ptDat;
	uint16_t uwheader[2];

	extern UWORD_UNION Mntr_uwGenReg;
	extern DINT(),EINT();
		
	if (PC_TransState == USB_START){//START PCmonitor	
		/* Read Data*/		// sean, emulate read ram function
		PC_Cha = ReadRamDataRX63T(Ch1Add);	
		PC_Chb = ReadRamDataRX63T(Ch2Add);	
		PC_Chc = ReadRamDataRX63T(Ch3Add);	
		PC_Chd = ReadRamDataRX63T(Ch4Add);	
			
		/* PC monitro packet */		
		USB_ubTxData_0[USB_ubTxCnt+0] = PC_Cha & 0xff;
		USB_ubTxData_0[USB_ubTxCnt+1] = (PC_Cha>>8) & 0xff;			
		USB_ubTxData_0[USB_ubTxCnt+2] = PC_Chb & 0xff;	
		USB_ubTxData_0[USB_ubTxCnt+3] = (PC_Chb>>8) & 0xff;			
		USB_ubTxData_0[USB_ubTxCnt+4] = PC_Chc & 0xff;	
		USB_ubTxData_0[USB_ubTxCnt+5] = (PC_Chc>>8) & 0xff;			
		USB_ubTxData_0[USB_ubTxCnt+6] = PC_Chd & 0xff;	
		USB_ubTxData_0[USB_ubTxCnt+7] = (PC_Chd>>8) & 0xff;
		/* checksum calculator*/
		for (ubTmp=USB_ubTxCnt;ubTmp<USB_ubTxCnt+8;ubTmp++)
			PC_TxChkSum += USB_ubTxData_0[ubTmp];	
									
		USB_ubTxCnt += 8;
			
		/* Packet Counter */
		PC_TxPktCnt+=1;		
		if (PC_TxPktCnt==16){
			/* checksum calculator*/
			PC_TxChkSum  = PC_TxChkSum + 0xff;
			USB_ubTxData_0[USB_ubTxCnt+0] = (0xff - PC_TxChkSum) + 0x01;
			USB_ubTxData_0[USB_ubTxCnt+1] = 0xff;	// next start byte
			USB_ubTxCnt +=2;	// two packets added
			
			/* reset Packet Counter */
			PC_TxPktCnt = 0;
			PC_TxChkSum = 0;	// reset checksum
		}
				
		/* Buffer full Check */
		if (USB_ubTxCnt>(USB_ubTXMAX-10)){
			/* Saving Tx Cnt for Tx function */
			USB_uwTxOutCnt = USB_ubTxCnt;
			USB_ubTxCnt = 0;
			memcpy(usb_gpcdc_send_data,USB_ubTxData_0,USB_uwTxOutCnt);	// 200us for USB routine, Sean, 2014/09/16				
				
			/* TxFull, set flag to transfer */
			PC_ubTxState = USB_TXFULL;
		}
	}
		
	if ( uwCheck(&Mntr_uwGenReg.uw, MNTR_START) ){	// Sean, 20141225
		/* Read Data and set PC monitor packet */		
#if 0
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh1Dat = USB_uwBytChg(ReadRamDataRX63T(Ch1Add));
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh2Dat = USB_uwBytChg(ReadRamDataRX63T(Ch2Add));
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh3Dat = USB_uwBytChg(ReadRamDataRX63T(Ch3Add));
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh4Dat = USB_uwBytChg(ReadRamDataRX63T(Ch4Add));
#else
		DINT();	
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh1Dat = USB_uwBytChg(ReadRamDataRX63T(ChxAdd[ChCountTmp++]));
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh2Dat = USB_uwBytChg(ReadRamDataRX63T(ChxAdd[ChCountTmp++]));
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh3Dat = USB_uwBytChg(ReadRamDataRX63T(ChxAdd[ChCountTmp++]));
		stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh4Dat = USB_uwBytChg(ReadRamDataRX63T(ChxAdd[ChCountTmp++]));
		EINT();
		if(ChCountTmp >= (ChCount -1))
			ChCountTmp = 0;
			
#endif		
		if(ubNew_VfdExplorerFlag == 1){//use new explorer--3/31/2016
			//new explorer must add header(FF 77 AA 55)--1/26/2016
			/* CRC accumlation */
			if (PC_TxPktCnt==0){
				MNTR_uwCRC[USB_ubTxBufIdx] = 0xffff;
				uwheader[0] = 0x77FF;
				uwheader[1] = 0x55AA;
				ptDat = &(uint8_t)uwheader[0];//add (uint8_t)--7/18/2016
				MNTR_uwCRC[USB_ubTxBufIdx] = crc_16( ptDat, 4, MNTR_uwCRC[USB_ubTxBufIdx]);
			}
			ptDat = &(uint8_t)stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh1Dat;//add (uint8_t)--7/18/2016
			MNTR_uwCRC[USB_ubTxBufIdx] = crc_16( ptDat, 8, MNTR_uwCRC[USB_ubTxBufIdx]);
		}
		else{//use old explorer--3/31/2016
			//old explorer no need header(FF 77 AA 55)--1/26/2016
			/* CRC accumlation */
			if (PC_TxPktCnt==0)
				MNTR_uwCRC[USB_ubTxBufIdx] = 0xffff;		
			ptDat = &(uint8_t)stMntrData[USB_ubTxBufIdx][PC_TxPktCnt].uwCh1Dat;//add (uint8_t)--7/18/2016
			MNTR_uwCRC[USB_ubTxBufIdx] = crc_16( ptDat, 8, MNTR_uwCRC[USB_ubTxBufIdx]);
		}
		/* Packet Counter */
		PC_TxPktCnt+=1;		
		if (PC_TxPktCnt>=100){
			/* buffer full, set TX, switch MNTR buffer */
			uwSet(&Mntr_uwGenReg.uw, MNTR_TX_FULL);		
			PC_TxPktCnt = 0;
			USB_ubTxBufIdx = (USB_ubTxBufIdx==1)?0:1;				
		}
	}
}

uint16_t USB_vdCRCGen(uint8_t* ubDat, uint8_t ubCnt)	// add CRC/LRC functions, Sean, 20141030
{
    UWORD_UNION CRC_Result;
    //UWORD  uIndex ; /* will index into CRC lookup table */
    UBYTE i,j;
    CRC_Result.uw = 0xffff;

    for (i=0;i<ubCnt; i++){	// chg i<=ubCnt to i<ubCnt
        CRC_Result.ub.low ^= *(ubDat+i);
        for (j=0;j<8;j++) {
            if (CRC_Result.uw & 0x01)
                CRC_Result.uw = (CRC_Result.uw >>1 ) ^ 0xa001;
            else
                CRC_Result.uw = CRC_Result.uw >> 1;
        }
    }

    return(CRC_Result.uw);
}

uint8_t USB_vdLRCGen(uint8_t* ubDat, uint8_t ubLen){	// add CRC/LRC functions, Sean, 20141030
	uint8_t ubSum;
	uint16_t uwRtn;
	
	ubSum = 0;
	while(ubLen!=0){
		ubSum += *(ubDat+(ubLen-1));
		ubLen-=1;
	}
	uwRtn = 0x0100 - ubSum;
	ubSum = uwRtn;
		
	return ubSum;
}

uint16_t USB_uwBytChg(uint16_t uwTmp){
	uint8_t	ubTmp;
	
	ubTmp = uwTmp;
	uwTmp = (uwTmp >> 8) + (ubTmp << 8);
	
	return uwTmp;
}
