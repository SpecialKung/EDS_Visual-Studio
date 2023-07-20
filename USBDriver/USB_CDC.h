/*******************************************************************************
* File Name    : r_usb_ctypedef.h
* Version      : 2.00
* Device(s)    : Renesas SH-Series, RX-Series
* Tool-Chain   : Renesas SuperH RISC engine Standard Toolchain
*              : Renesas RX Standard Toolchain
* OS           : Common to None and uITRON 4.0 Spec
* H/W Platform : Independent
* Description  : Type Definition Header File
*******************************************************************************
* History : DD.MM.YYYY Version Description
*         : 29.07.2011 0.50    First Release
******************************************************************************/

/* $Id: r_usb_ctypedef.h 143 2012-05-07 09:16:46Z tmura $ */

#ifndef __R_USB_CTYPEDEF_H__
#define __R_USB_CTYPEDEF_H__


/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>
/******************************************************************************
* File Name    : r_usb_usrconfig.h
* Version      : 2.00
* Device(s)    : Renesas SH-Series, RX-Series
* Tool-Chain   : Renesas SuperH RISC engine Standard Toolchain
*              : Renesas RX Standard Toolchain
* OS           : Common to None and uITRON 4.0 Spec
* H/W Platform : Independent
* Description  : USB User definition
******************************************************************************
* History : DD.MM.YYYY Version Description
*         : 29.07.2011 0.50    First Release
******************************************************************************/

/* $Id: r_usb_usrconfig.h 143 2012-05-07 09:16:46Z tmura $ */

#ifndef __R_USB_USRCFG_H__
#define __R_USB_USRCFG_H__

#ifndef __R_USB_DEFVAL_H__
#define __R_USB_DEFVAL_H__

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* !!!!! WARNING--You can not edit this file. !!!!!*/
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*****************************************************************************
Macro definitions (for Preprocessor)
******************************************************************************/

#define USB_FW_OS_PP                1
#define USB_FW_NONOS_PP             2

#define USB_OS_CRE_USE_PP           1   /* cre_* system call USE */
#define USB_OS_CRE_NOTUSE_PP        2   /* cre_* system call Not USE */

#define USB_HS_PP                   1   /* Hi-Speed */
#define USB_FS_PP                   2   /* Full-Speed */

#define USB_1PORT_PP                1   /* 1 port mode */
#define USB_2PORT_PP                2   /* 2 port mode */

#define USB_HOST_PP                 1
#define USB_PERI_PP                 2
#define USB_HOST_PERI_PP            3
#define USB_OTG_PP                  4
#define USB_NOUSE_PP                10
#define USB_USE_PP                  11
#define USB_PERI0_PERI1_PP          17
#define USB_PERI0_HOST1_PP          18
#define USB_HOST0_PERI1_PP          19
#define USB_HOST0_HOST1_PP          20

/* Clock mode */
#define USB_CLK_NOT_STOP_PP         0
#define USB_CLK_XCKE_USE_PP         1
#define USB_CLK_PCUT_USE_PP         2

/* ATCKM mode  */
#define USB_ATCKM_NOT_USE_PP        0
#define USB_ATCKM_USE_PP            1

/* Sleep mode */
#define USB_LPSM_DISABLE_PP         0   /* Low-power sleep disable (SOC) */
#define USB_LPSM_ENABLE_PP          1   /* Low-power sleep enable (ASSP) */

/* IP mode DEVADD MAX */
#define USB_IP_DEVADD_A_PP          10  /* DEVADD_MAX=10 */
#define USB_IP_DEVADD_5_PP          5   /* DEVADD_MAX=5 */

/* Select PIPEBUF fix or variable */
#define USB_PIPEBUF_FIX_PP          1
#define USB_PIPEBUF_CHANGE_PP       2

/* Select target chip define */
#define USB_ASSP_PP                 1
#define USB_RX600_PP                2

/* Data Trans mode */
#define USB_TRANS_DMA_PP            1
#define USB_TRANS_DTC_PP            2

/* Default Bus size */
#define USB_BUSSIZE_16_PP           16
#define USB_BUSSIZE_32_PP           32

/* Low Power Mode */
#define USB_LPWR_NOT_USE_PP         0
#define USB_LPWR_USE_PP             1

/* BYTE ENDIAN */
#define USB_BYTE_LITTLE_PP          0
#define USB_BYTE_BIG_PP             1

#define USB_ANSIIO_NOT_USE_PP       0
#define USB_ANSIIO_USE_PP           1

/* SPEED mode */
#define USB_HS_DISABLE          (uint16_t)0
#define USB_HS_ENABLE           (uint16_t)1

/* H/W function type */
#define USB_HOST                (uint16_t)1     /* Host mode */
#define USB_PERI                (uint16_t)2     /* Peripheral mode */
#define USB_HOST_PERI           (uint16_t)3     /* Host/Peri mode */
#define USB_OTG                 (uint16_t)4     /* Otg mode */

/* H/W function type */
#define USB_BIT0                (uint16_t)0x0001
#define USB_BIT1                (uint16_t)0x0002
#define USB_BIT2                (uint16_t)0x0004
#define USB_BIT3                (uint16_t)0x0008
#define USB_BIT4                (uint16_t)0x0010
#define USB_BIT5                (uint16_t)0x0020
#define USB_BIT6                (uint16_t)0x0040
#define USB_BIT7                (uint16_t)0x0080
#define USB_BIT8                (uint16_t)0x0100
#define USB_BIT9                (uint16_t)0x0200
#define USB_BIT10               (uint16_t)0x0400
#define USB_BIT11               (uint16_t)0x0800
#define USB_BIT12               (uint16_t)0x1000
#define USB_BIT13               (uint16_t)0x2000
#define USB_BIT14               (uint16_t)0x4000
#define USB_BIT15               (uint16_t)0x8000
#define USB_BITSET(x)           (uint16_t)((uint16_t)1 << (x))

/* nonOS Use */
#define USB_SEQ_0               (uint16_t)0x0000
#define USB_SEQ_1               (uint16_t)0x0001
#define USB_SEQ_2               (uint16_t)0x0002
#define USB_SEQ_3               (uint16_t)0x0003
#define USB_SEQ_4               (uint16_t)0x0004
#define USB_SEQ_5               (uint16_t)0x0005
#define USB_SEQ_6               (uint16_t)0x0006
#define USB_SEQ_7               (uint16_t)0x0007
#define USB_SEQ_8               (uint16_t)0x0008
#define USB_SEQ_9               (uint16_t)0x0009
#define USB_SEQ_10              (uint16_t)0x000a

#define USB_HUB_P1              (uint16_t)0x0001
#define USB_HUB_P2              (uint16_t)0x0002
#define USB_HUB_P3              (uint16_t)0x0003
#define USB_HUB_P4              (uint16_t)0x0004

/* Interrupt message num */
#define USB_INTMSGMAX           (uint16_t)15
#define USB_DMAMSGMAX           (uint16_t)15

/* USB IP Number */
#define USB_USBIP_0             (uint16_t)0

/* USB Device Connect */
#define USB_DEV_NO_CONNECT      (uint16_t)0
#define USB_DEV_CONNECTED       (uint16_t)1

#endif
#ifndef __R_USB_FIXEDCFG_RX_H__
#define __R_USB_FIXEDCFG_RX_H__

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* !!!!! WARNING--You can not edit this file. !!!!!*/
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*****************************************************************************
Macro definitions (597IP)
******************************************************************************/
    /* The number of USBIP */
    #define USB_NUM_USBIP           2

    /*  USB mode of USB IP1  */
    #define USB_FUNCSEL_USBIP1_PP       USB_NOUSE_PP

    /* Clock mode */
    #define USB_USBIP_LPW_PP        USB_CLK_NOT_STOP_PP

    /* Sleep mode */
    #define USB_LPWRSEL_PP          USB_LPSM_DISABLE_PP

    /* SPEED mode */
    #define USB_HSESEL              USB_HS_DISABLE

    /* Select target chip define */
    #define USB_TARGET_CHIP_PP      USB_RX600_PP

    /* Select IP mode DEVADD MAX */
    #define USB_IP_DEVADD_PP        USB_IP_DEVADD_5_PP

    /* Select PIPEBUF fix or variable */
    #define USB_PIPEBUF_MODE_PP     USB_PIPEBUF_FIX_PP

    /* Select Transfer Speed */
    #define USB_SPEEDSEL_PP         USB_FS_PP

    /* Default MBW */
    #define USB_BUSSIZE_PP          USB_BUSSIZE_16_PP

    /* Select PORT */
    #define USB_PORTSEL_PP          USB_1PORT_PP    /* 1port in 1IP */

    /* Start Pipe No */
    #define USB_MIN_PIPE_NO         USB_PIPE1

    /* Data Trans mode */
    #define USB_TRANS_MODE_PP       USB_TRANS_DTC_PP

    /* USB Device address define */
    #define USB_DEVICEADDR          1u      /* PORT0 USB Address (1 to 10) */

    /* HUB Address */
    #define USB_HUBDPADDR           (uint16_t)(USB_DEVICEADDR + 1u)

#define USB_MAX_FILENUMBER  16
#define USB_DEVICENUM       10

#endif

/*****************************************************************************
Macro definitions (USER DEFINE)
******************************************************************************/
/* Select using ANSI IO */
    #define USB_ANSIIO_PP       USB_ANSIIO_USE_PP
//  #define USB_ANSIIO_PP       USB_ANSIIO_NOT_USE_PP

/* Select USB mode(Host or Periphera) per each USB IP  */
//  #define USB_FUNCSEL_USBIP0_PP           USB_HOST_PP     // Host Mode
    #define USB_FUNCSEL_USBIP0_PP           USB_PERI_PP     // Peripheral Mode
//  #define USB_FUNCSEL_USBIP0_PP           USB_NOUSE_PP

/* CPU byte endian select */
    #define USB_CPUBYTE_PP          USB_BYTE_LITTLE_PP
//  #define USB_CPUBYTE_PP          USB_BYTE_BIG_PP

/* Select CPU Low Power Mode                      */
    #define USB_CPU_LPW_PP          USB_LPWR_NOT_USE_PP
//  #define USB_CPU_LPW_PP          USB_LPWR_USE_PP


/*****************************************************************************
Macro definitions (Peripheral Mode)
******************************************************************************/
/* bcdUSB */
    #define USB_BCDNUM              0x0200u
/* Release Number */
    #define USB_RELEASE             0x0200u
/* DCP max packet size */
    #define USB_DCPMAXP             64u
/* Configuration number */
    #define USB_CONFIGNUM           1u
/* Max of string descriptor */
    #define USB_STRINGNUM           7u

/*****************************************************************************
Macro definitions (Host Mode)
******************************************************************************/

/* Number of software retries when a no-response condition occurs during a transfer */
    #define USB_PIPEERROR           1u

/* Descriptor size */
    #define USB_DEVICESIZE          20u     /* Device Descriptor size */
    #define USB_CONFIGSIZE          256u    /* Configuration Descriptor size */

/* HUB down port */
    #define USB_HUBDOWNPORT         4u      /* HUB downport (MAX15) */

/* Total number of Interface */
#define USB_IFNUM                   1

/* Total number of Configuration */
#define USB_CFGNUM                  1
#define USB_MAX_DEVICENUM           (USB_DEVICENUM * USB_IFNUM * USB_CFGNUM)

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
********************************************************************************/
/* This definition shows USB IP number that work as USB host mode */
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP
    #define USB_HOST_USBIP_NUM  USB_USBIP_0
    #define USB_HOST_MODE_PP
#endif

/* This definition shows USB IP number that work as USB peripheral mode */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
    #define USB_PERI_USBIP_NUM  USB_USBIP_0
    #define USB_PERI_MODE_PP
#endif

#endif  /* __R_USB_CDEFUSR_H__ */
/******************************************************************************
End  Of File
******************************************************************************/

#ifndef __R_USB_CITRON_H__
#define __R_USB_CITRON_H__

/* Condition compilation by the difference of the operating system */
    #ifndef NULL
      #define   NULL    0u
    #endif  /* NULL */

/*****************************************************************************
Typedef definitions
******************************************************************************/
    typedef void*           VP;             /* Pointer to variable      */
    typedef void            (*FP)(void);    /* Program address          */
    typedef unsigned long   UINT;           /* unsigned integer         */

    typedef long            ER;             /* Error code               */
    typedef short           ID;             /* Object ID (xxxid)        */
    typedef long            TMO;            /* Time out                 */
    typedef unsigned long   RELTIM;         /* System call define       */
    typedef void*           MH;             /* Message Header typedef   */
    typedef unsigned long   ATR;            /* Attribute                */
    typedef unsigned long   STAT;           /* Object status            */
    typedef short           PRI;            /* Task priority            */
    typedef unsigned long   SIZE;           /* Memory area size         */
    typedef long            VP_INT;         /* Integer data             */

    /*----------- msghead -----------*/
    typedef struct
    {
        VP              msghead;        /* Message header               */
    } T_MSG;
    /*----------- cre_tsk -----------*/
    typedef struct                      /* cre_tsk packet               */
    {
        ATR             tskatr;         /* Task attribute               */
        VP_INT          exinf;          /* Extended information         */
        FP              task;           /* Task start address           */
        PRI             itskpri;        /* Initial priority             */
        SIZE            stksz;          /* Stack size                   */
        VP              stk;            /* Stack address                */
    } T_CTSK;
    /*----------- cre_sem -----------*/
    typedef struct                      /* cre_sem packet               */
    {
        ATR             sematr;         /* Semaphore attribute          */
        UINT            isemcnt;        /* Initial semaphore count      */
        UINT            maxsem;         /* Maximum semaphore count      */
    } T_CSEM;
    /*----------- cre_mbx -----------*/
    typedef struct                      /* cre_mbx packet               */
    {
        ATR             mbxatr;         /* Mailbox attribute            */
        PRI             maxmpri;        /* Maximum message priority     */
        VP              mprihd;         /* Message queue header address */
    } T_CMBX;
    /*----------- cre_mpf -----------*/
    typedef struct                      /* cre_mpf packet               */
    {
        ATR             mpfatr;         /* Memorypool attribute         */
        UINT            blkcnt;         /* Total memory block count     */
        UINT            blksz;          /* Memory block size            */
        VP              mpf;            /* Memorypool area address      */
    } T_CMPL;
    /*----------- ref_tst -----------*/
    typedef struct                      /* ref_tst packet               */
    {
        STAT            tskstat;        /* Task status                  */
        STAT            tskwait;        /* Factor of WAIT               */
    } T_RTST;
    /*----------- cre_alm -----------*/
    typedef struct                      /* cre_alm packet               */
    {
        ATR             almatr;         /* Alarm handler attribute      */
        VP_INT          exinf;          /* Extended information         */
        FP              almhdr;         /* Alarm handler address        */
    } T_CALM;

/******************************************************************************
Constant macro definitions
******************************************************************************/

    #define E_OK        0L                  /* Normal end               */
    #define E_TMOUT     (-50L)              /* Time out                 */
    #define E_QOVR      (-43L)              /* Queuing over flow        */


/******************************************************************************
Constant macro definitions
******************************************************************************/

    /*-------------------- Task/Handler attribute (***atr) -------------*/
    #define TA_HLNG     0x00000000u     /* High-level language program  */
    /*----------------------- Object attribute (***atr) ----------------*/
    #define TA_TFIFO    0x00000000u     /* FIFO wait queue              */
    #define TA_MFIFO    0x00000000u     /* FIFO message queue           */
    #define TA_ACT      0x00000002u     /* Create task with activation  */

    /*-------------------------- Object status -------------------------*/
    #define TTS_RUN     0x00000001UL    /* RUNNING                      */
    #define TTS_RDY     0x00000002UL    /* READY                        */
    #define TTS_WAI     0x00000004UL    /* WAITING                      */
    #define TTS_SUS     0x00000008UL    /* SUSPENDED                    */
    #define TTS_WAS     0x0000000cUL    /* WAITING-SUSPENDED            */
    #define TTS_DMT     0x00000010UL    /* DORMANT                      */
    #define TTS_STK     0x40000000UL    /* STACK WAITING                */

    /* <system call> */
    #define USB_NO_SYSTEM_PP

/*****************************************************************************
Typedef definitions
******************************************************************************/
    typedef T_MSG           USB_MSG_t;      /* ITRON message            */
    typedef T_RTST          USB_RTST_t; /* ITRON task status        */

    typedef ER              USB_ER_t;       /* ITRON system call err    */
    typedef ID              USB_ID_t;       /* ITRON system call define */
    typedef TMO             USB_TM_t;       /* ITRON time out           */
    typedef RELTIM          USB_RT_t;       /* ITRON system call define */
    typedef VP              USB_MH_t;       /* ITRON Message Header     */
    typedef VP_INT          USB_VI_t;       /* ITRON system call define */
    typedef ATR             USB_ATR_t;      /* ITRON attribute          */
    typedef FP              USB_FP_t;       /* ITRON task address       */
    typedef PRI             USB_PRI_t;      /* ITRON priority           */
    typedef SIZE            USB_SIZ_t;      /* ITRON size               */
    typedef VP              USB_VP_t;       /* ITRON address            */
    typedef UINT            USB_UINT_t; /* ITRON unsigned integer   */
    typedef VP_INT          USB_VP_INT_t;


/******************************************************************************
Constant macro definitions
******************************************************************************/
#define USB_NULL        NULL
#define USB_VP_INT      VP_INT
#define USB_TA_HLNG TA_HLNG
#define USB_TA_TFIFO    TA_TFIFO
#define USB_TA_MFIFO    TA_MFIFO

#define USB_E_TMOUT E_TMOUT     /* TRCV_MSG time out */
#define USB_E_QOVR      E_QOVR      /* Submit overlap error */
#define USB_E_ERROR (-1L)
#define USB_E_OK        E_OK
#define USB_TMPOL       TMO_POL     /* TRCV_MSG poling */
#define USB_TMFEVR      TMO_FEVR    /* TRCV_MSG no time */
#define USB_TAJLNG      TA_HLNG     /* High-level language program */
#define USB_TATFIFO TA_TFIFO    /* FIFO wait queue */
#define USB_TAMFIFO TA_MFIFO    /* FIFO message queue */
#define USB_TAACT       TA_ACT      /* Create task with activation */
#define USB_TTSRUN      TTS_RUN     /* RUNNING */

#define USB_TTS_RUN TTS_RUN
#define USB_TTS_RDY TTS_RDY
#define USB_TTS_WAI TTS_WAI
#define USB_TTS_SUS TTS_SUS
#define USB_TTS_WAS TTS_WAS
#define USB_TTS_DMT TTS_DMT
#define USB_TTS_STK TTS_STK

#endif  /* __R_USB_CITRON_H__ */


/******************************************************************************
Typedef definitions
******************************************************************************/
typedef struct st_usb       USB_STNBYINT_t;

typedef void (*USB_CB_CHECK_t)(struct USB_UTR *, uint16_t**);
typedef void (*USB_CB_t)(struct USB_UTR *, uint16_t, uint16_t);
typedef void (*USB_CB_INFO_t)(struct USB_UTR *, uint16_t, uint16_t);
typedef void (*USB_CB_MSG_t)(uint16_t, uint8_t*);
typedef void (*USB_CB_REQ_t)(void *);

#if USB_TARGET_CHIP_PP == USB_ASSP_PP
typedef struct  USB_REGISTER*   USB_REGADR_t;
#else
typedef volatile struct st_usb0 __evenaccess*   USB_REGADR_t;
#endif

typedef struct
{
    uint16_t        ReqType;            /* Request type */
    uint16_t        ReqTypeType;        /* Request type TYPE */
    uint16_t        ReqTypeRecip;       /* Request type RECIPIENT */
    uint16_t        ReqRequest;         /* Request */
    uint16_t        ReqValue;           /* Value */
    uint16_t        ReqIndex;           /* Index */
    uint16_t        ReqLength;          /* Length */
} USB_REQUEST_t;

typedef struct USB_HCDREG
{
    uint16_t        rootport;       /* Root port */
    uint16_t        devaddr;        /* Device address */
    uint16_t        devstate;       /* Device state */
    uint16_t        ifclass;        /* Interface Class */
    uint16_t        *tpl;           /* Target peripheral list 
                                        (Vendor ID, Product ID) */
    uint16_t        *pipetbl;       /* Pipe Define Table address */
    USB_CB_INFO_t   classinit;      /* Driver init */
    USB_CB_CHECK_t  classcheck;     /* Driver check */
    USB_CB_INFO_t   devconfig;      /* Device configured */
    USB_CB_INFO_t   devdetach;      /* Device detach */
    USB_CB_INFO_t   devsuspend;     /* Device suspend */
    USB_CB_INFO_t   devresume;      /* Device resume */
    USB_CB_INFO_t   overcurrent;    /* Device over current */
} USB_HCDREG_t;

typedef struct USB_UTR
{
    USB_MH_t        msghead;        /* Message header (for SH-solution) */
    uint16_t        msginfo;        /* Message Info for F/W */
    uint16_t        keyword;        /* Rootport / Device address / Pipe number */
    USB_REGADR_t    ipp;            /* IP Address(USB0orUSB1)*/
    uint16_t        ip;             /* IP number(0or1) */
    uint16_t        result;         /* Result */
    USB_CB_t        complete;       /* Call Back Function Info */
    void            *tranadr;       /* Transfer data Start address */
    uint32_t        tranlen;        /* Transfer data length */
    uint16_t        *setup;         /* Setup packet(for control only) */
    uint16_t        status;         /* Status */
    uint16_t        pipectr;        /* Pipe control register */
    uint8_t         errcnt;         /* Error count */
    uint8_t         segment;        /* Last flag */
    int16_t         fn;             /* File Number */
    void            *usr_data;      
} USB_UTR_t;

/* Class request processing function type. */
typedef void (*USB_CB_TRN_t)(USB_UTR_t *, USB_REQUEST_t*, uint16_t ctsq);

typedef struct USB_PCDREG
{
    uint16_t        **pipetbl;      /* Pipe Define Table address */
    uint8_t         *devicetbl;     /* Device descriptor Table address */
    uint8_t         *qualitbl;      /* Qualifier descriptor Table address */
    uint8_t         **configtbl;    /* Configuration descriptor
                                        Table address */
    uint8_t         **othertbl;     /* Other configuration descriptor
                                        Table address */
    uint8_t         **stringtbl;    /* String descriptor Table address */
    USB_CB_INFO_t   classinit;      /* Driver init */
    USB_CB_INFO_t   devdefault;     /* Device default */
    USB_CB_INFO_t   devconfig;      /* Device configured */
    USB_CB_INFO_t   devdetach;      /* Device detach */
    USB_CB_INFO_t   devsuspend;     /* Device suspend */
    USB_CB_INFO_t   devresume;      /* Device resume */
    USB_CB_INFO_t   interface;      /* Interface changed */
    USB_CB_TRN_t    ctrltrans;      /* Control Transfer */
} USB_PCDREG_t;

typedef struct USB_UTR      USB_HCDINFO_t;
typedef struct USB_UTR      USB_MGRINFO_t;
typedef struct USB_UTR      USB_PCDINFO_t;
typedef struct USB_UTR      USB_CLSINFO_t;

typedef struct usb_fninfo {
    uint8_t         isOpened;
    uint8_t         usb_ip;
    USB_REGADR_t    usb_ipp;            /* IP Address(USB0orUSB1)*/
    uint8_t         devno;
    uint8_t         inPipeNo;
    uint8_t         outPipeNo;
    int32_t         (*class_read)( int16_t, void *, uint32_t );
    int32_t         (*class_write)( int16_t , void *, uint32_t );
    uint16_t        (*close_func)( int16_t );

    USB_CB_t        read_complete;      /* Call Back Function Info */
    USB_CB_t        write_complete;     /* Call Back Function Info */
    int32_t         read_length;        /* Transfer data length */
    int32_t         write_length;       /* Transfer data length */
//  uint16_t        *class_control();
    int16_t         open_state;         /* Open status */
    int16_t         read_state;         /* read status */
    int16_t         write_state;        /* write status */
} USB_FNINFO_t;

struct usb_devinfo 
{
    uint8_t         devadr;
    uint8_t         speed;
    uint8_t         isTPL;
    uint8_t         interfaceClass;
    uint8_t         isActDev;
    USB_UTR_t       *ptr;
};

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
typedef struct usb_open_parametor
{
    USB_FNINFO_t *p_fnstr;
    uint8_t devadr;
    uint8_t speed;
    uint16_t class;
} USB_OPEN_PARM_t;
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

/*****************************************************************************
Macro definitions
******************************************************************************/
#define USB_NONE            (uint16_t)(0)
#define USB_YES             (uint16_t)(1)
#define USB_NO              (uint16_t)(0)
#define USB_DONE            (uint16_t)(0)
#define USB_ERROR           (uint16_t)(0xFFFF)
#define USB_OK              (uint16_t)(0)
#define USB_NG              (uint16_t)(0xFFFF)
#define USB_ON              (uint16_t)(1)
#define USB_OFF             (uint16_t)(0)
#define USB_OTG_DONE        (uint16_t)(2)
#define USB_NOT_USED        (uint16_t)(0)



#ifndef __R_USB_CKERNELID_H__
#define __R_USB_CKERNELID_H__

/*****************************************************************************
Macro definitions
******************************************************************************/
/* Scheduler use define */
#define USB_TBLCLR          0u                  /* Table clear */
#define USB_CNTCLR          0u                  /* Counter clear */
#define USB_FLGCLR          0u                  /* Flag clear */
#define USB_FLGSET          1u                  /* Flag set */
#define USB_IDCLR           0xFFu               /* Priority clear */

/* Task ID define */
#define USB_TID_0           0u                  /* Task ID 0 */
#define USB_TID_1           1u                  /* Task ID 1 */
#define USB_TID_2           2u                  /* Task ID 2 */
#define USB_TID_3           3u                  /* Task ID 3 */
#define USB_TID_4           4u                  /* Task ID 4 */
#define USB_TID_5           5u                  /* Task ID 5 */
#define USB_TID_6           6u                  /* Task ID 6 */
#define USB_TID_7           7u                  /* Task ID 7 */
#define USB_TID_8           8u                  /* Task ID 8 */
#define USB_TID_9           9u                  /* Task ID 9 */
#define USB_TID_10          10u                 /* Task ID 9 */

/* Task priority define */
#define USB_PRI_0           0u                  /* Priority 0 */
#define USB_PRI_1           1u                  /* Priority 1 */
#define USB_PRI_2           2u                  /* Priority 2 */
#define USB_PRI_3           3u                  /* Priority 3 */
#define USB_PRI_4           4u                  /* Priority 4 */
#define USB_PRI_5           5u                  /* Priority 5 */
#define USB_PRI_6           6u                  /* Priority 6 */

/* Please set with user system */
#define USB_IDMAX           11u                 /* Maximum Task ID +1 */
#define USB_PRIMAX          8u                  /* Maximum Priority number +1 */
#define USB_BLKMAX          20u                 /* Maximum block */
#define USB_TABLEMAX        USB_BLKMAX          /* Maximum priority table */


/* Peripheral Control Driver Task */
#define USB_PCD_TSK         USB_TID_0           /* Task ID */
#define USB_PCD_MBX         USB_PCD_TSK         /* Mailbox ID */
#define USB_PCD_MPL         USB_PCD_TSK         /* Memorypool ID */

/* Host Control Driver Task */
#define USB_HCD_TSK         USB_TID_1           /* Task ID */
#define USB_HCD_MBX         USB_HCD_TSK         /* Mailbox ID */
#define USB_HCD_MPL         USB_HCD_TSK         /* Memorypool ID */

/* Host Manager Task */
#define USB_MGR_TSK         USB_TID_2           /* Task ID */
#define USB_MGR_MBX         USB_MGR_TSK         /* Mailbox ID */
#define USB_MGR_MPL         USB_MGR_TSK         /* Memorypool ID */

/* Hub Task */
#define USB_HUB_TSK         USB_TID_3           /* Task ID */
#define USB_HUB_MBX         USB_HUB_TSK         /* Mailbox ID */
#define USB_HUB_MPL         USB_HUB_TSK         /* Memorypool ID */

/* Peripheral CDC Driver Task */
#define USB_PCDC_TSK        USB_TID_3           /* Task ID */
#define USB_PCDC_MBX        USB_PCDC_TSK        /* Mailbox ID */
#define USB_PCDC_MPL        USB_PCDC_TSK        /* Memorypool ID */

/* Peripheral CDC Sample Task */
#define USB_PCDCSMP_TSK     USB_TID_4           /* Task ID */
#define USB_PCDCSMP_MBX     USB_PCDCSMP_TSK     /* Mailbox ID */
#define USB_PCDCSMP_MPL     USB_PCDCSMP_TSK     /* Memorypool ID */

/* Idle Task */
#define USB_IDL_TSK         USB_TID_10          /* Task ID */
#define USB_IDL_MBX         USB_IDL_TSK         /* Mailbox ID */
#define USB_IDL_MPL         USB_IDL_TSK         /* Memorypool ID */

#endif  /* __R_USB_CKERNELID_H__ */

#ifndef __R_USB_CDEFUSBIP_H__
#define __R_USB_CDEFUSBIP_H__


/*****************************************************************************
Macro definitions
******************************************************************************/

/******************************************************************************
USB specification define
******************************************************************************/

/* Standard Device Descriptor Define */
#define USB_DEV_B_LENGTH                    0u      /* Size of descriptor */
#define USB_DEV_B_DESCRIPTOR_TYPE           1u      /* Descriptor type */
#define USB_DEV_BCD_USB_L                   2u      /* USB Specification Release Number */
#define USB_DEV_BCD_USB_H                   3u      /* USB Specification Release Number */
#define USB_DEV_B_DEVICE_CLASS              4u      /* Class code */
#define USB_DEV_B_DEVICE_SUBCLASS           5u      /* Subclass code */
#define USB_DEV_B_DEVICE_PROTOCOL           6u      /* Protocol code */
#define USB_DEV_B_MAX_PACKET_SIZE_0         7u      /* Max packet size for EP0(only 8,16,32,64 are valid) */
#define USB_DEV_ID_VENDOR_L                 8u      /* Vendor ID */
#define USB_DEV_ID_VENDOR_H                 9u      /* Vendor ID */
#define USB_DEV_ID_PRODUCT_L                10u     /* Product ID */
#define USB_DEV_ID_PRODUCT_H                11u     /* Product ID */
#define USB_DEV_BCD_DEVICE_L                12u     /* Device relese number */
#define USB_DEV_BCD_DEVICE_H                13u     /* Device relese number */
#define USB_DEV_I_MANUFACTURER              14u     /* Index of string descriptor describing manufacturer */
#define USB_DEV_I_PRODUCT                   15u     /* Index of string descriptor describing product */
#define USB_DEV_I_SERIAL_NUMBER             16u     /* Device serial number */
#define USB_DEV_B_NUM_CONFIGURATION         17u     /* Number of possible configuration */

/* Standard Configuration Descriptor Define */
//#define   USB_DEV_B_LENGTH                    0u      /* Size of descriptor */
//#define   USB_DEV_B_DESCRIPTOR_TYPE           1u      /* Descriptor type */
#define USB_DEV_W_TOTAL_LENGTH_L            2       /* Total length of data returned for this configuration */
#define USB_DEV_W_TOTAL_LENGTH_H            3       /* Total length of data returned for this configuration */
#define USB_DEV_B_NUM_INTERFACES            4       /* Number of interfaces supported by this configuration */
#define USB_DEV_B_CONFIGURATION_VALUE       5       /* Configuration value */
#define USB_DEV_I_CONFIGURATION             6       /* Index of string descriptor describing this configuration */
#define USB_DEV_BM_ATTRIBUTES               7       /* Configuration characteristics */
#define USB_DEV_B_MAX_POWER                 8       /* Max power consumption of the USB device from the bus */

/* Descriptor type  Define */
#define USB_DT_DEVICE                       0x01u   /* Configuration Descriptor */
#define USB_DT_CONFIGURATION                0x02u   /* Configuration Descriptor */
#define USB_DT_STRING                       0x03u   /* Configuration Descriptor */
#define USB_DT_INTERFACE                    0x04u   /* Interface Descriptor */
#define USB_DT_ENDPOINT                     0x05u   /* Endpoint Descriptor */
#define USB_DT_DEVICE_QUALIFIER             0x06u   /* Device Qualifier Descriptor */
#define USB_DT_OTHER_SPEED_CONF             0x07u   /* Other Speed Configuration Descriptor */
#define USB_DT_INTERFACE_POWER              0x08u   /* Interface Power Descriptor */
#define USB_DT_OTGDESCRIPTOR                0x09u   /* OTG Descriptor */
#define USB_DT_HUBDESCRIPTOR                0x29u   /* HUB descriptor */

/* Device class Define  */
#define USB_DEVCLS_INTF                     0x00u   /* Class information at interface */
#define USB_DEVCLS_COMM                     0x02u   /* Communication Device */
#define USB_DEVCLS_HUB                      0x90u   /* HUB Device */
#define USB_DEVCLS_DIAG                     0xDCu   /* Diagnostic Device */
#define USB_DEVCLS_WIRE                     0xE0u   /* Wireless Controller */
#define USB_DEVCLS_APL                      0xFEu   /* Application-Specific */
#define USB_DEVCLS_VEN                      0xFFu   /* Vendor-Specific */

/* Interface class Define */
#define USB_IFCLS_NOT                       0x00u   /* Un corresponding Class */
#define USB_IFCLS_AUD                       0x01u   /* Audio Class */
#define USB_IFCLS_CDCC                      0x02u   /* CDC-Control Class */
#define USB_IFCLS_HID                       0x03u   /* HID Class */
#define USB_IFCLS_PHY                       0x05u   /* Physical Class */
#define USB_IFCLS_IMG                       0x06u   /* Image Class */
#define USB_IFCLS_PRN                       0x07u   /* Printer Class */
#define USB_IFCLS_MAS                       0x08u   /* Mass Storage Class */
#define USB_IFCLS_HUB                       0x09u   /* HUB Class */
#define USB_IFCLS_CDCD                      0x0Au   /* CDC-Data Class */
#define USB_IFCLS_CHIP                      0x0Bu   /* Chip/Smart Card Class */
#define USB_IFCLS_CNT                       0x0Cu   /* Content-Security Class */
#define USB_IFCLS_VID                       0x0Du   /* Video Class */
#define USB_IFCLS_DIAG                      0xDCu   /* Diagnostic Device */
#define USB_IFCLS_WIRE                      0xE0u   /* Wireless Controller */
#define USB_IFCLS_APL                       0xFEu   /* Application-Specific */
#define USB_IFCLS_VEN                       0xFFu   /* Vendor-Specific Class */

/* Endpoint Descriptor  Define */
#define USB_EP_DIRMASK                      0x80u   /* Endpoint direction mask [2] */
#define USB_EP_IN                           0x80u   /* In Endpoint */
#define USB_EP_OUT                          0x00u   /* Out Endpoint */
#define USB_EP_NUMMASK                      0x0Fu   /* Endpoint number mask [2] */
#define USB_EP_USGMASK                      0x30u   /* Usage type mask [2] */
#define USB_EP_SYNCMASK                     0x0Cu   /* Synchronization type mask [2] */
#define USB_EP_TRNSMASK                     0x03u   /* Transfer type mask [2] */
#define USB_EP_CNTRL                        0x00u   /* Control Transfer */
#define USB_EP_ISO                          0x01u   /* Isochronous Transfer */
#define USB_EP_BULK                         0x02u   /* Bulk Transfer */
#define USB_EP_INT                          0x03u   /* Interrupt Transfer */

/* Configuration descriptor bit define */
#define USB_CF_RESERVED                     0x80u   /* Reserved(set to 1) */
#define USB_CF_SELFP                        0x40u   /* Self Powered */
#define USB_CF_BUSP                         0x00u   /* Bus Powered */
#define USB_CF_RWUPON                       0x20u   /* Remote Wakeup ON */
#define USB_CF_RWUPOFF                      0x00u   /* Remote Wakeup OFF */

/* OTG descriptor bit define */
#define USB_OTG_HNP                         0x02u   /* HNP support */

/* SRP support */
#define USB_OTG_SRP                         0x01u

/* USB Standard request */
/* USB_BREQUEST         0xFF00u(b15-8) */
#define USB_GET_STATUS                      0x0000u
#define USB_CLEAR_FEATURE                   0x0100u
#define USB_REQRESERVED                     0x0200u
#define USB_SET_FEATURE                     0x0300u
#define USB_REQRESERVED1                    0x0400u
#define USB_SET_ADDRESS                     0x0500u
#define USB_GET_DESCRIPTOR                  0x0600u
#define USB_SET_DESCRIPTOR                  0x0700u
#define USB_GET_CONFIGURATION               0x0800u
#define USB_SET_CONFIGURATION               0x0900u
#define USB_GET_INTERFACE                   0x0A00u
#define USB_SET_INTERFACE                   0x0B00u
#define USB_SYNCH_FRAME                     0x0C00u

/* USB_BMREQUESTTYPEDIR 0x0080u(b7) */
#define USB_HOST_TO_DEV                     0x0000u
#define USB_DEV_TO_HOST                     0x0080u

/* USB_BMREQUESTTYPETYPE    0x0060u(b6-5) */
#define USB_STANDARD                        0x0000u
#define USB_CLASS                           0x0020u
#define USB_VENDOR                          0x0040u

/* USB_BMREQUESTTYPERECIP   0x001Fu(b4-0) */
#define USB_DEVICE                          0x0000u
#define USB_INTERFACE                       0x0001u
#define USB_ENDPOINT                        0x0002u
#define USB_OTHER                           0x0003u

/* GET_STATUS request information */
/* Standard Device status */
#define USB_GS_BUSPOWERD                    0x0000u
#define USB_GS_SELFPOWERD                   0x0001u
#define USB_GS_REMOTEWAKEUP                 0x0002u

/* Endpoint status */
#define USB_GS_NOTHALT                      0x0000u
#define USB_GS_HALT                         0x0001u

/* CLEAR_FEATURE/GET_FEATURE/SET_FEATURE request information */
/* Standard Feature Selector */
#define USB_ENDPOINT_HALT                   0x0000u
#define USB_DEV_REMOTE_WAKEUP               0x0001u
#define USB_TEST_MODE                       0x0002u

/* GET_DESCRIPTOR/SET_DESCRIPTOR request information */
/* Standard Descriptor type */
#define USB_HUB_DESCRIPTOR                  0x0000u
#define USB_DEV_DESCRIPTOR                  0x0100u
#define USB_CONF_DESCRIPTOR                 0x0200u
#define USB_STRING_DESCRIPTOR               0x0300u
#define USB_INTERFACE_DESCRIPTOR            0x0400u
#define USB_ENDPOINT_DESCRIPTOR             0x0500u
#define USB_DEV_QUALIFIER_DESCRIPTOR        0x0600u
#define USB_OTHER_SPEED_CONF_DESCRIPTOR     0x0700u
#define USB_INTERFACE_POWER_DESCRIPTOR      0x0800u

/* HUB CLASS REQUEST */
#define USB_HUB_CLEAR_TT_BUFFER             0x0800u
#define USB_HUB_RESET_TT                    0x0900u
#define USB_HUB_GET_TT_STATE                0x0A00u
#define USB_HUB_STOP_TT                     0x0B00u

/* HUB CLASS FEATURE SELECTER */
#define USB_HUB_C_HUB_LOCAL_POWER           0x0000u
#define USB_HUB_C_HUB_OVER_CURRENT          0x0001u
#define USB_HUB_PORT_CONNECTION             0x0000u
#define USB_HUB_PORT_ENABLE                 0x0001u
#define USB_HUB_PORT_SUSPEND                0x0002u
#define USB_HUB_PORT_OVER_CURRENT           0x0003u
#define USB_HUB_PORT_RESET                  0x0004u
#define USB_HUB_PORT_POWER                  0x0008u
#define USB_HUB_PORT_LOW_SPEED              0x0009u
#define USB_HUB_PORT_HIGH_SPEED             0x000Au
#define USB_HUB_C_PORT_CONNECTION           0x0010u
#define USB_HUB_C_PORT_ENABLE               0x0011u
#define USB_HUB_C_PORT_SUSPEND              0x0012u
#define USB_HUB_C_PORT_OVER_CURRENT         0x0013u
#define USB_HUB_C_PORT_RESET                0x0014u
#define USB_HUB_PORT_TEST                   0x0015u
#define USB_HUB_PORT_INDICATOR              0x0016u

/* HUB PORT STAUS */
#define USB_HUB_STS_PORT_CONNECT            0x0001u
#define USB_HUB_STS_PORT_ENABLE             0x0002u
#define USB_HUB_STS_PORT_SUSPEND            0x0004u
#define USB_HUB_STS_PORT_OVRCURRNET         0x0008u
#define USB_HUB_STS_PORT_RESET              0x0010u
#define USB_HUB_STS_PORT_POWER              0x0100u
#define USB_HUB_STS_PORT_LOWSPEED           0x0200u
#define USB_HUB_STS_PORT_FULLSPEED          0x0000u
#define USB_HUB_STS_PORT_HIGHSPEED          0x0400u
#define USB_HUB_STS_PORT_TEST               0x0800u
#define USB_HUB_STS_PORT_INDICATOR          0x1000u

/* HUB PORT CHANGE */
#define USB_HUB_CHG_PORT_CONNECT            0x0001u
#define USB_HUB_CHG_PORT_ENABLE             0x0002u
#define USB_HUB_CHG_PORT_SUSPEND            0x0004u
#define USB_HUB_CHG_PORT_OVRCURRNET         0x0008u
#define USB_HUB_CHG_PORT_RESET              0x0010u


/******************************************************************************
USB-H/W register define
******************************************************************************/

/* Root port */
#define USB_PORT0                           0u
#define USB_PORT1                           1u

/* Device connect information */
#define USB_ATTACH                          0x0040u
#define USB_ATTACHL                         0x0041u
#define USB_ATTACHF                         0x0042u
#define USB_DETACH                          0x0043u

/* Reset Handshake result */
#define USB_NOCONNECT                       0x0000u /* Speed undecidedness */
#define USB_HSCONNECT                       0x00C0u /* Hi-Speed connect */
#define USB_FSCONNECT                       0x0080u /* Full-Speed connect */
#define USB_LSCONNECT                       0x0040u /* Low-Speed connect */

/* Pipe define */
#define USB_USEPIPE                         0x00FEu
#define USB_PERIPIPE                        0x00FDu
#define USB_CLRPIPE                         0x00FCu /* Clear Pipe registration */
#define USB_PIPE0                           0x0000u /* PIPE 0 */
#define USB_PIPE1                           0x0001u /* PIPE 1 */
#define USB_PIPE2                           0x0002u /* PIPE 2 */
#define USB_PIPE3                           0x0003u /* PIPE 3 */
#define USB_PIPE4                           0x0004u /* PIPE 4 */
#define USB_PIPE5                           0x0005u /* PIPE 5 */
#define USB_PIPE6                           0x0006u /* PIPE 6 */
#define USB_PIPE7                           0x0007u /* PIPE 7 */
#define USB_PIPE8                           0x0008u /* PIPE 8 */
#define USB_PIPE9                           0x0009u /* PIPE 9 */
#define USB_MAX_PIPE_NO                     9u      /* PIPE0 ... PIPE9 */

/* Pipe configuration table define */
#define USB_EPL                             6u      /* Pipe configuration table length */
#define USB_TYPFIELD                        0xC000u /* Transfer type */
#define   USB_PERIODIC                      0x8000u /* Periodic pipe */
#define   USB_ISO                           0xC000u /* Isochronous */
#define   USB_INT                           0x8000u /* Interrupt */
#define   USB_BULK                          0x4000u /* Bulk */
#define   USB_NOUSE                         0x0000u /* Not configuration */
#define USB_BFREFIELD                       0x0400u /* Buffer ready interrupt mode select */
#define   USB_BFREON                        0x0400u
#define   USB_BFREOFF                       0x0000u
#define USB_DBLBFIELD                       0x0200u /* Double buffer mode select */
#define   USB_DBLBON                        0x0200u
#define   USB_DBLBOFF                       0x0000u
#define USB_CNTMDFIELD                      0x0100u /* Continuous transfer mode select */
#define   USB_CNTMDON                       0x0100u
#define   USB_CNTMDOFF                      0x0000u
#define USB_SHTNAKFIELD                     0x0080u /* Transfer end NAK */
#define   USB_SHTNAKON                      0x0080u
#define   USB_SHTNAKOFF                     0x0000u
#define USB_DIRFIELD                        0x0010u /* Transfer direction select */
#define   USB_DIR_H_OUT                     0x0010u /* HOST OUT */
#define   USB_DIR_P_IN                      0x0010u /* PERI IN */
#define   USB_DIR_H_IN                      0x0000u /* HOST IN */
#define   USB_DIR_P_OUT                     0x0000u /* PERI OUT */
#define   USB_BUF2FIFO                      0x0010u /* Buffer --> FIFO */
#define   USB_FIFO2BUF                      0x0000u /* FIFO --> buffer */
#define USB_EPNUMFIELD                      0x000Fu /* Endpoint number select */
#define USB_MAX_EP_NO                       15u     /* EP0 EP1 ... EP15 */
#define   USB_EP0                           0x0000u
#define   USB_EP1                           0x0001u
#define   USB_EP2                           0x0002u
#define   USB_EP3                           0x0003u
#define   USB_EP4                           0x0004u
#define   USB_EP5                           0x0005u
#define   USB_EP6                           0x0006u
#define   USB_EP7                           0x0007u
#define   USB_EP8                           0x0008u
#define   USB_EP9                           0x0009u
#define   USB_EP10                          0x000Au
#define   USB_EP11                          0x000Bu
#define   USB_EP12                          0x000Cu
#define   USB_EP13                          0x000Du
#define   USB_EP14                          0x000Eu
#define   USB_EP15                          0x000Fu

#define USB_BUF_SIZE(x)                     ((uint16_t)(((x) / 64u) - 1u) << 10u)
#define USB_BUF_NUMB(x)                     (x)

#define USB_IFISFIELD                       0x1000u /* Isochronous in-buf flash mode */
#define   USB_IFISON                        0x1000u
#define   USB_IFISOFF                       0x0000u
#define USB_IITVFIELD                       0x0007u /* Isochronous interval */
#define USB_IITV_TIME(x)                    (x)

/* FIFO port & access define */
#define USB_CUSE                            0u  /* CFIFO CPU trans */
#define USB_D0USE                           1u  /* D0FIFO CPU trans */
#define USB_D0DMA                           2u  /* D0FIFO DMA trans */
#define USB_D1USE                           3u  /* D1FIFO CPU trans */
#define USB_D1DMA                           4u  /* D1FIFO DMA trans */
#define USB_CUSE2                           5u  /* CFIFO CPU trans (not trans count) */


/******************************************************************************
Another define
******************************************************************************/
/* FIFO read / write result */
#define USB_FIFOERROR                       USB_ERROR   /* FIFO not ready */
#define USB_WRITEEND                        0x0000u     /* End of write (but packet may not be outputting) */
#define USB_WRITESHRT                       0x0001u     /* End of write (send short packet) */
#define USB_WRITING                         0x0002u     /* Write continues */
#define USB_READEND                         0x0000u     /* End of read */
#define USB_READSHRT                        0x0001u     /* Insufficient (receive short packet) */
#define USB_READING                         0x0002u     /* Read continues */
#define USB_READOVER                        0x0003u     /* Buffer size over */

/* Pipe define table end code */
#define USB_PDTBLEND                        0xFFFFu /* End of table */

/* Transfer status Type */
#define USB_CTRL_END                        0u
#define USB_DATA_NONE                       1u
#define USB_DATA_WAIT                       2u
#define USB_DATA_OK                         3u
#define USB_DATA_SHT                        4u
#define USB_DATA_OVR                        5u
#define USB_DATA_STALL                      6u
#define USB_DATA_ERR                        7u
#define USB_DATA_STOP                       8u
#define USB_DATA_TMO                        9u
#define USB_CTRL_READING                    17u
#define USB_CTRL_WRITING                    18u
#define USB_DATA_READING                    19u
#define USB_DATA_WRITING                    20u

/* Utr member (segment) */
#define USB_TRAN_CONT                       0x00u
#define USB_TRAN_END                        0x80u

/* Callback argument */
#define USB_NO_ARG                          0u

/* USB interrupt type (common)*/
#define USB_INT_UNKNOWN                     0x0000u
#define USB_INT_BRDY                        0x0001u
#define USB_INT_BEMP                        0x0002u
#define USB_INT_NRDY                        0x0003u

/* USB interrupt type (PERI)*/
#define USB_INT_VBINT                       0x0011u
#define USB_INT_RESM                        0x0012u
#define USB_INT_SOFR                        0x0013u
#define USB_INT_DVST                        0x0014u
#define USB_INT_CTRT                        0x0015u
#define USB_INT_ATTACH                      0x0016u
#define USB_INT_DETACH                      0x0017u

/* USB interrupt type (HOST)*/
#define USB_INT_OVRCR0                      0x0041u
#define USB_INT_BCHG0                       0x0042u
#define USB_INT_DTCH0                       0x0043u
#define USB_INT_ATTCH0                      0x0044u
#define USB_INT_EOFERR0                     0x0045u
#define USB_INT_OVRCR1                      0x0051u
#define USB_INT_BCHG1                       0x0052u
#define USB_INT_ATTCH1                      0x0053u
#define USB_INT_DTCH1                       0x0054u
#define USB_INT_EOFERR1                     0x0055u
#define USB_INT_SACK                        0x0061u
#define USB_INT_SIGN                        0x0062u

/******************************************************************************
HCD driver specification define
******************************************************************************/

/******************************************************************************
HCD driver common define
******************************************************************************/
/* Global macro Define  */
#define USB_UACTON                          (1u)
#define USB_UACTOFF                         (0u)
#define USB_VBON                            (1u)
#define USB_VBOFF                           (0u)

/******************************************************************************
USB specification define
******************************************************************************/
/* Device class Define  */
#define USB_NOVENDOR                        0xFFFFu /* Vendor ID nocheck */
#define USB_NOPRODUCT                       0xFFFFu /* Product ID nocheck */

/* Interface class Define */
#define USB_INTFCLSHET                      0xAAu   /* Host electrical test class */

/******************************************************************************
USB-H/W register define
******************************************************************************/
/* Root port */
#define USB_NOPORT                          0xFFFFu /* Not connect */

/* Max device */
#define USB_MAXPIPE_BULK                    5
#define     USB_MAXPIPE_ISO                 2
#define     USB_MAXPIPE_NUM                 9

 /* Condition compilation by the difference of IP */
#if USB_IP_DEVADD_PP == USB_IP_DEVADD_A_PP
#define USB_MAXDEVADDR                      10u
#else /* USB_IP_DEVADD_PP = USB_IP_DEVADD_A_PP */
#define USB_MAXDEVADDR                      5u
#endif /* USB_IP_DEVADD_PP = USB_IP_DEVADD_A_PP */

#define   USB_DEVICE_0                      0x0000u /* Device address 0 */
#define   USB_DEVICE_1                      0x1000u /* Device address 1 */
#define   USB_DEVICE_2                      0x2000u /* Device address 2 */
#define   USB_DEVICE_3                      0x3000u /* Device address 3 */
#define   USB_DEVICE_4                      0x4000u /* Device address 4 */
#define   USB_DEVICE_5                      0x5000u /* Device address 5 */
#define   USB_DEVICE_6                      0x6000u /* Device address 6 */
#define   USB_DEVICE_7                      0x7000u /* Device address 7 */
#define   USB_DEVICE_8                      0x8000u /* Device address 8 */
#define   USB_DEVICE_9                      0x9000u /* Device address 9 */
#define   USB_DEVICE_A                      0xA000u /* Device address A */
#define   USB_NODEVICE                      0xF000u /* No device */
#define   USB_DEVADDRBIT                    12u

/* DCP Max packetsize */
#define USB_MAXPFIELD                       0x007Fu /* Maxpacket size of DCP */

/******************************************************************************
Another define
******************************************************************************/
/* ControlPipe Max Packet size */
#define USB_DEFPACKET                       0x0040u /* Default DCP Max packet size */

/* Device state define */
#define USB_NONDEVICE                       0u
#define USB_DEVICEERR                       1u
#define USB_ATTACHDEVICE                    2u
#define USB_DEVICEENUMERATION               3u
#define USB_DEVICEADDRESSED                 4u
#define USB_DEVICECONFIGURED                5u
#define USB_COMPLETEPIPESET                 10u
#define USB_DEVICESUSPENDED                 20u
#define USB_ELECTRICALTEST                  30u

/* Control Transfer Stage */
#define USB_IDLEST                          0u  /* Idle */
#define USB_SETUPNDC                        1u  /* Setup Stage No Data Control */
#define USB_SETUPWR                         2u  /* Setup Stage Control Write */
#define USB_SETUPRD                         3u  /* Setup Stage Control Read */
#define USB_DATAWR                          4u  /* Data Stage Control Write */
#define USB_DATARD                          5u  /* Data Stage Control Read */
#define USB_STATUSRD                        6u  /* Status stage */
#define USB_STATUSWR                        7u  /* Status stage */
#define USB_SETUPWRCNT                      17u /* Setup Stage Control Write */
#define USB_SETUPRDCNT                      18u /* Setup Stage Control Read */
#define USB_DATAWRCNT                       19u /* Data Stage Control Write */
#define USB_DATARDCNT                       20u /* Data Stage Control Read */

/******************************************************************************
HUB define
******************************************************************************/
/* HUB spec */
#define USB_FSHUB                           1u
#define USB_HSHUBS                          2u
#define USB_HSHUBM                          3u

/* Interface number */
#define USB_HUB_INTNUMFS                    1u
#define USB_HUB_INTNUMHSS                   1u
#define USB_HUB_INTNUMHSM                   1u


/******************************************************************************
OTG define
******************************************************************************/
#define USB_ADEVICE                         0x0000u
#define USB_BDEVICE                         0x0004u

#define USB_UNDER05                         0x0000u
#define USB_MID05TO14                       0x4000u
#define USB_MID14TO45                       0x8000u
#define USB_OVER45                          0xC000u


/*  USB Manager mode    */
#define USB_PORTOFF                         0u      /* Disconnect(VBUSoff) */
#define USB_DETACHED                        10u     /* Disconnect(VBUSon) */
#define USB_ATTACHED                        20u     /* Disconnect(HUBdiconfigured) */
#define USB_POWERED                         30u     /* Start reset handshake */
#define USB_DEFAULT                         40u     /* Set device address */
#define USB_ADDRESS                         50u     /* Enumeration start */
#define USB_ENUMERATION                     60u     /* Wait device enumeration */
#define USB_CONFIGURED                      70u     /* Detach detected */
#define USB_SUSPENDED                       80u     /* Device suspended */
#define USB_DETACH_PROCESS                  101u    /* Wait device detach */
#define USB_SUSPENDED_PROCESS               102u    /* Wait device suspend */
#define USB_RESUME_PROCESS                  103u    /* Wait device resume */
/* Condition compilation by the difference of IP */
#if USB_IPSEL_PP == USB_596IP_PP
#define USB_DISABLEDET                      90u /* Disable detach detected */
#endif  /* USB_596IP_PP */


/******************************************************************************
Task request message type
******************************************************************************/
/* HCD common task message command */
#define USB_MSG_HCD_ATTACH                  0x0101u
#define USB_MSG_HCD_DETACH                  0x0102u
#define USB_MSG_HCD_USBRESET                0x0103u
#define USB_MSG_HCD_SUSPEND                 0x0104u
#define USB_MSG_HCD_RESUME                  0x0105u
#define USB_MSG_HCD_REMOTE                  0x0106u
#define USB_MSG_HCD_VBON                    0x0107u
#define USB_MSG_HCD_VBOFF                   0x0108u
#define USB_MSG_HCD_CLR_STALL               0x0109u
#define USB_MSG_HCD_DETACH_MGR              0x010Au
#define USB_MSG_HCD_ATTACH_MGR              0x010Bu

#define USB_MSG_HCD_CLR_STALL_RESULT        0x010Cu
#define USB_MSG_HCD_CLR_STALLBIT            0x010Du
#define USB_MSG_HCD_CTRL_END                0x010Eu
#define USB_MSG_HCD_SQTGLBIT                0x010Fu

/* HCD task message command */
#define USB_MSG_HCD_SETDEVICEINFO           0x0111u
#define USB_MSG_HCD_SUBMITUTR               0x0112u
#define USB_MSG_HCD_TRANSEND1               0x0113u
#define USB_MSG_HCD_TRANSEND2               0x0114u
#define USB_MSG_HCD_CLRSEQBIT               0x0115u
#define USB_MSG_HCD_SETSEQBIT               0x0116u
#define USB_MSG_HCD_INT                     0x0117u
#define USB_MSG_HCD_PCUTINT                 0x0118u
#define USB_MSG_HCD_DMAINT                  0x0119u

#define USB_MSG_HCD_D0FIFO_INT              0x0141u
#define USB_MSG_HCD_D1FIFO_INT              0x0142u
#define USB_MSG_HCD_RESM_INT                0x0143u
#define USB_MSG_PCD_D0FIFO_INT              0x0144u
#define USB_MSG_PCD_D1FIFO_INT              0x0145u
#define USB_MSG_PCD_RESM_INT                0x0146u

/* USB Manager task message command */
#define USB_MSG_MGR_AORDETACH               0x0121u
#define USB_MSG_MGR_OVERCURRENT             0x0122u
#define USB_MSG_MGR_STATUSRESULT            0x0123u
#define USB_MSG_MGR_SUBMITRESULT            0x0124u
#define USB_MSG_MGR_TRANSENDRESULT          0x0125u

#define USB_MSG_MGR_SETCONFIGURATION        0x0300
#define USB_MSG_MGR_SETCONFIGURATION_RESULT 0x0301

#define USB_MSG_MGR_GETDESCRIPTOR           0x0400
#define USB_MSG_MGR_GETDESCRIPTOR_RESULT    0x0401

/* USB HUB task message command */
#define USB_MSG_HUB_HUB2HUBSTART            0x0131u
#define USB_MSG_HUB_START                   0x0132u
#define USB_MSG_HUB_STOP                    0x0133u
#define USB_MSG_HUB_SUBMITRESULT            0x0134u
#define USB_MSG_HUB_IVENT                   0x0135u /* nonOS */
#define USB_MSG_HUB_ATTACH                  0x0136u /* nonOS */
#define USB_MSG_HUB_RESET                   0x0137u /* nonOS */

/* CLS task message command */
#define USB_MSG_CLS_CHECKREQUEST            0x0201u /* nonOS */
#define USB_MSG_CLS_INIT                    0x0202u /* nonOS */
#define USB_MSG_CLS_TASK                    0x0203u /* nonOS */
#define USB_MSG_CLS_WAIT                    0x0204u /* nonOS */
#define USB_MSG_CLS_PROCESSRESULT           0x0205u /* nonOS */

/* HET task message command */
#define USB_MSG_HET_UACTOFF                 0x0171u
#define USB_MSG_HET_UACTON                  0x0172u
#define USB_MSG_HET_VBUSOFF                 0x0173u
#define USB_MSG_HET_VBUSON                  0x0174u
#define USB_MSG_HET_RESET                   0x0175u
#define USB_MSG_HET_SUSPEND                 0x0176u
#define USB_MSG_HET_RESUME                  0x0177u
#define USB_MSG_HET_ENUMERATION             0x0178u
#define USB_MSG_HET_TESTNONE                0x0181u
#define USB_MSG_HET_TESTPACKET              0x0182u
#define USB_MSG_HET_TESTJ                   0x0183u
#define USB_MSG_HET_TESTK                   0x0184u
#define USB_MSG_HET_TESTSE0                 0x0185u
#define USB_MSG_HET_TESTSIGSTOP             0x0186u
#define USB_MSG_HET_SINGLESETUP             0x0187u
#define USB_MSG_HET_SINGLEDATA              0x0188u

/******************************************************************************
USB driver specification define
******************************************************************************/

/******************************************************************************
Another define
******************************************************************************/
/* Descriptor index */
#define USB_DEV_MAX_PKT_SIZE                7u  /* Index of bMAXPacketSize */
#define USB_DEV_NUM_CONFIG                  17u /* Index of bNumConfigurations */
#define USB_ALT_NO                          255u
#define USB_SOFT_CHANGE                     0u

/******************************************************************************
Task request message type
******************************************************************************/
/* USB Peripheral task message command */
#define USB_MSG_PCD_INT                     0x0151u
#define USB_MSG_PCD_SUBMITUTR               0x0152u
#define USB_MSG_PCD_TRANSEND1               0x0153u
#define USB_MSG_PCD_TRANSEND2               0x0154u
#define USB_MSG_PCD_REMOTEWAKEUP            0x0155u
#define USB_MSG_PCD_DETACH                  0x0161u
#define USB_MSG_PCD_ATTACH                  0x0162u
#define USB_MSG_PCD_CLRSEQBIT               0x0163u
#define USB_MSG_PCD_SETSTALL                0x0164u
#define USB_MSG_PCD_PCUTINT                 0x0156u

#define USB_MSG_PCD_DP_ENABLE               0x0157u
#define USB_MSG_PCD_DP_DISABLE              0x0158u
#define USB_MSG_PCD_DM_ENABLE               0x0159u
#define USB_MSG_PCD_DM_DISABLE              0x015Au

#define USB_MSG_PCD_DMAINT                  0x015bu

#define USB_DO_REMOTEWAKEUP                 USB_MSG_PCD_REMOTEWAKEUP
#define USB_DP_ENABLE                       USB_MSG_PCD_DP_ENABLE
#define USB_DP_DISABLE                      USB_MSG_PCD_DP_DISABLE
#define USB_DM_ENABLE                       USB_MSG_PCD_DM_ENABLE
#define USB_DM_DISABLE                      USB_MSG_PCD_DM_DISABLE

#define USB_DO_STALL                        USB_MSG_PCD_SETSTALL

#define USB_GO_POWEREDSTATE                 0x0201u /* USB_MSG_HCD_DETACH */
#define USB_DO_RESET_AND_ENUMERATION        0x0202u /* USB_MSG_HCD_ATTACH */
#define USB_PORT_ENABLE                     0x0203u /* USB_MSG_HCD_VBON */
#define USB_PORT_DISABLE                    0x0204u /* USB_MSG_HCD_VBOFF */
#define USB_DO_GLOBAL_SUSPEND               0x0205u /* USB_MSG_HCD_SUSPEND */
#define USB_DO_SELECTIVE_SUSPEND            0x0206u /* USB_MSG_HCD_SUSPEND */
#define USB_DO_GLOBAL_RESUME                0x0207u /* USB_MSG_HCD_RESUME */
#define USB_DO_SELECTIVE_RESUME             0x0208u /* USB_MSG_HCD_RESUME */

#endif  /* __R_USB_CDEFUSBIP_H__ */

#ifndef __R_USB_CMACPRINT_H__
#define __R_USB_CMACPRINT_H__


/*****************************************************************************
Macro definitions
******************************************************************************/
/* Condition compilation by the difference of quality control */
#ifndef USB_MISRA_CHECK_PP
//#define       USB_DEBUGUART_PP        /* PC Terminal */
//#define       USB_DEBUGPRINT_PP       /* HEW Console */
#endif  /* USB_MISRA_CHECK_PP */

/* Condition compilation by the difference of useful function */
#ifdef USB_DEBUGUART_PP
    #include    <stdlib.h>          /* @@@MISRA del */
    #include    <stdio.h>           /* @@@MISRA del */
    #define USB_SPRINTF0(FORM)                          fprintf(stderr,FORM)
    #define USB_SPRINTF1(FORM,x1)                       fprintf(stderr,FORM,x1)
    #define USB_SPRINTF2(FORM,x1,x2)                    fprintf(stderr,FORM,x1,x2)
    #define USB_SPRINTF3(FORM,x1,x2,x3)                 fprintf(stderr,FORM,x1,x2,x3)
    #define USB_SPRINTF4(FORM,x1,x2,x3,x4)              fprintf(stderr,FORM,x1,x2,x3,x4)
    #define USB_SPRINTF5(FORM,x1,x2,x3,x4,x5)           fprintf(stderr,FORM,x1,x2,x3,x4,x5)
    #define USB_SPRINTF6(FORM,x1,x2,x3,x4,x5,x6)        fprintf(stderr,FORM,x1,x2,x3,x4,x5,x6)
    #define USB_SPRINTF7(FORM,x1,x2,x3,x4,x5,x6,x7)     fprintf(stderr,FORM,x1,x2,x3,x4,x5,x6,x7)
    #define USB_SPRINTF8(FORM,x1,x2,x3,x4,x5,x6,x7,x8)  fprintf(stderr,FORM,x1,x2,x3,x4,x5,x6,x7,x8)
#else   /* USB_DEBUGUART_PP */
    #define USB_SPRINTF0(FORM)
    #define USB_SPRINTF1(FORM,x1)
    #define USB_SPRINTF2(FORM,x1,x2)
    #define USB_SPRINTF3(FORM,x1,x2,x3)
    #define USB_SPRINTF4(FORM,x1,x2,x3,x4)
    #define USB_SPRINTF5(FORM,x1,x2,x3,x4,x5)
    #define USB_SPRINTF6(FORM,x1,x2,x3,x4,x5,x6)
    #define USB_SPRINTF7(FORM,x1,x2,x3,x4,x5,x6,x7)
    #define USB_SPRINTF8(FORM,x1,x2,x3,x4,x5,x6,x7,x8)
#endif  /* USB_DEBUGUART_PP */

/* Condition compilation by the difference of useful function */
#ifdef USB_DEBUGPRINT_PP
    #include    <stdlib.h>          /* @@@MISRA del */
    #include    <stdio.h>           /* @@@MISRA del */
    #define USB_PRINTF0(FORM)                           printf(FORM)
    #define USB_PRINTF1(FORM,x1)                        printf(FORM,x1)
    #define USB_PRINTF2(FORM,x1,x2)                     printf(FORM,x1,x2)
    #define USB_PRINTF3(FORM,x1,x2,x3)                  printf(FORM,x1,x2,x3)
    #define USB_PRINTF4(FORM,x1,x2,x3,x4)               printf(FORM,x1,x2,x3,x4)
    #define USB_PRINTF5(FORM,x1,x2,x3,x4,x5)            printf(FORM,x1,x2,x3,x4,x5)
    #define USB_PRINTF6(FORM,x1,x2,x3,x4,x5,x6)         printf(FORM,x1,x2,x3,x4,x5,x6)
    #define USB_PRINTF7(FORM,x1,x2,x3,x4,x5,x6,x7)      printf(FORM,x1,x2,x3,x4,x5,x6,x7)
    #define USB_PRINTF8(FORM,x1,x2,x3,x4,x5,x6,x7,x8)   printf(FORM,x1,x2,x3,x4,x5,x6,x7,x8)
#else   /* USB_DEBUGPRINT_PP */
    #define USB_PRINTF0(FORM)
    #define USB_PRINTF1(FORM,x1)
    #define USB_PRINTF2(FORM,x1,x2)
    #define USB_PRINTF3(FORM,x1,x2,x3)
    #define USB_PRINTF4(FORM,x1,x2,x3,x4)
    #define USB_PRINTF5(FORM,x1,x2,x3,x4,x5)
    #define USB_PRINTF6(FORM,x1,x2,x3,x4,x5,x6)
    #define USB_PRINTF7(FORM,x1,x2,x3,x4,x5,x6,x7)
    #define USB_PRINTF8(FORM,x1,x2,x3,x4,x5,x6,x7,x8)
#endif  /* USB_DEBUGPRINT_PP */


#endif  /* __R_USB_CMACPRINT_H__ */

#ifndef __R_USB_CMACSYSTEMCALL_H__
#define __R_USB_CMACSYSTEMCALL_H__


/*****************************************************************************
Macro definitions
******************************************************************************/
/* uITRON4.0 system call */
#ifndef USB_NO_SYSTEM_PP
    #define USB_CRE_TSK(ID,INFO)        cre_tsk( (USB_ID_t)ID, (USB_TSK_t*)INFO )
    #define USB_DEL_TSK(ID)             del_tsk( (USB_ID_t)ID )
    #define USB_STA_TSK(ID,CODE)        sta_tsk( (USB_ID_t)ID, (USB_VI_t)CODE )
    #define USB_ACT_TSK(ID)             act_tsk( (USB_ID_t)ID )
    #define R_USB_ACT_TSK(ID)           act_tsk( (USB_ID_t)ID )
    #define USB_TER_TSK(ID)             ter_tsk( (USB_ID_t)ID )
    #define USB_EXT_TSK()               ext_tsk( )
    #define USB_REF_TST(ID, STS)        ref_tst( (USB_ID_t)ID, (USB_RTST_t*)STS )

    #define USB_DLY_TSK(TIME)           dly_tsk( (USB_RT_t)TIME )
    #define R_USB_DLY_TSK(TIME)         dly_tsk( (USB_RT_t)TIME )

    #define USB_CRE_MBX(ID, INFO)       cre_mbx( (USB_ID_t)ID, (USB_MBX_t*)INFO )
    #define USB_DEL_MBX(ID)             del_mbx( (USB_ID_t)ID )
    #define USB_SND_MSG(ID, MESS)       snd_mbx( (USB_ID_t)ID, (USB_MSG_t*)MESS )
    #define R_USB_SND_MSG(ID, MESS)     snd_mbx( (USB_ID_t)ID, (USB_MSG_t*)MESS )
    #define USB_ISND_MSG(ID, MESS)      isnd_mbx( (USB_ID_t)ID, (USB_MSG_t*)MESS )
    #define USB_RCV_MSG(ID, MESS)       rcv_mbx( (USB_ID_t)ID, (USB_MSG_t**)MESS )
    #define R_USB_RCV_MSG(ID, MESS)     rcv_mbx( (USB_ID_t)ID, (USB_MSG_t**)MESS )
    #define USB_PRCV_MSG(ID, MESS)      prcv_mbx( (USB_ID_t)ID, (USB_MSG_t**)MESS )
    #define R_USB_PRCV_MSG(ID, MESS)    prcv_mbx( (USB_ID_t)ID, (USB_MSG_t**)MESS )
    #define USB_TRCV_MSG(ID, MESS, TM)  trcv_mbx( (USB_ID_t)ID, (USB_MSG_t**)MESS, (USB_TM_t)TM )
    #define R_USB_TRCV_MSG(ID, MESS, TM)    trcv_mbx( (USB_ID_t)ID, (USB_MSG_t**)MESS, (USB_TM_t)TM )

    #define USB_CRE_MPL(ID, INFO)       cre_mpf( (USB_ID_t)ID, (USB_MPL_t*)INFO )
    #define USB_DEL_MPL(ID)             del_mpf( (USB_ID_t)ID )
    #define USB_PGET_BLK(ID, BLK)       pget_mpf( (USB_ID_t)ID, (USB_MH_t*)BLK )
    #define R_USB_PGET_BLK(ID, BLK)     pget_mpf( (USB_ID_t)ID, (USB_MH_t*)BLK )
    #define USB_IPGET_BLK(ID, BLK)      ipget_mpf( (USB_ID_t)ID, (USB_MH_t*)BLK )
    #define USB_REL_BLK(ID, BLK)        rel_mpf( (USB_ID_t)ID, (USB_MH_t)BLK )
    #define R_USB_REL_BLK(ID, BLK)      rel_mpf( (USB_ID_t)ID, (USB_MH_t)BLK )

    #define USB_CRE_SEM(ID, INFO)       cre_sem( (USB_ID_t)ID, (USB_SEM_t*)INFO )
    #define USB_WAI_SEM(ID)             wai_sem( (USB_ID_t)ID )
    #define USB_POL_SEM(ID)             pol_sem( (USB_ID_t)ID )
    #define USB_SIG_SEM(ID)             sig_sem( (USB_ID_t)ID )

    #define USB_CRE_ALM(ID, INFO)       cre_alm( (USB_ID_t)ID, (USB_ALM_t*)INFO )
    #define USB_STA_ALM(ID, TIME)       sta_alm( (USB_ID_t)ID, (USB_RT_t)TIME )
    #define USB_STP_ALM(ID)             stp_alm( (USB_ID_t)ID )
    #define USB_DEL_ALM(ID)             del_alm( (USB_ID_t)ID )

    #define USB_REL_WAI(ID)             rel_wai( (USB_ID_t)ID )
    #define USB_IREL_WAI(ID)            irel_wai( (USB_ID_t)ID )
#else   /* USB_NO_SYSTEM_PP */
    /* nonOS */
    #define USB_CRE_TSK(ID,INFO)        USB_NG
    #define USB_DEL_TSK(ID)             USB_NG
    #define USB_STA_TSK(ID,CODE)        USB_NG
    #define USB_ACT_TSK(ID)             USB_NG
    #define USB_TER_TSK(ID)             USB_NG
    #define USB_EXT_TSK()               USB_NG
    #define USB_REF_TST(ID, STS)        USB_NG

    #define USB_DLY_TSK(TIME)
    #define R_USB_DLY_TSK(TIME)

    #define USB_CRE_MBX(ID, INFO)       USB_NG
    #define USB_DEL_MBX(ID)             USB_NG
    #define USB_SND_MSG(ID, MESS)       usb_cstd_SndMsg( (uint8_t)ID, (USB_MSG_t*)MESS )
    #define R_USB_SND_MSG(ID, MESS)     R_usb_cstd_SndMsg( (uint8_t)ID, (USB_MSG_t*)MESS )
    #define USB_ISND_MSG(ID, MESS)      usb_cstd_iSndMsg( (uint8_t)ID, (USB_MSG_t*)MESS )
    #define R_USB_ISND_MSG(ID, MESS)    R_usb_cstd_iSndMsg( (uint8_t)ID, (USB_MSG_t*)MESS )
    #define USB_WAI_MSG(ID, MESS, TM)   usb_cstd_WaiMsg( (uint8_t)ID, (USB_MSG_t*)MESS, (uint16_t)TM )
    #define R_USB_WAI_MSG(ID, MESS, TM) R_usb_cstd_WaiMsg( (uint8_t)ID, (USB_MSG_t*)MESS, (uint16_t)TM )
    #define USB_RCV_MSG(ID, MESS)       usb_cstd_RecMsg( (uint8_t)ID, (USB_MSG_t**)MESS, (USB_TM_t)0u )
    #define R_USB_RCV_MSG(ID, MESS)     R_usb_cstd_RecMsg( (uint8_t)ID, (USB_MSG_t**)MESS, (USB_TM_t)0u )
    #define USB_PRCV_MSG(ID, MESS)      USB_NG
    #define R_USB_TRCV_MSG(ID, MESS, TM)    R_usb_cstd_RecMsg( (uint8_t)ID, (USB_MSG_t**)MESS, (USB_TM_t)TM )
    #define USB_TRCV_MSG(ID, MESS, TM)  usb_cstd_RecMsg( (uint8_t)ID, (USB_MSG_t**)MESS, (USB_TM_t)TM )
    
    #define USB_CRE_MPL(ID, INFO)       USB_NG
    #define USB_DEL_MPL(ID)             USB_NG
    #define R_USB_PGET_BLK(ID, BLK)     R_usb_cstd_PgetBlk( (uint8_t)ID, (USB_UTR_t**)BLK )
    #define USB_PGET_BLK(ID, BLK)       usb_cstd_PgetBlk( (uint8_t)ID, (USB_UTR_t**)BLK )
    #define USB_IPGET_BLK(ID, BLK)      USB_NG
    #define R_USB_REL_BLK(ID, BLK)      R_usb_cstd_RelBlk( (uint8_t)ID,  (USB_UTR_t*)BLK )
    #define USB_REL_BLK(ID, BLK)        usb_cstd_RelBlk( (uint8_t)ID,  (USB_UTR_t*)BLK )

    #define USB_CRE_SEM(ID, INFO)       USB_NG
    #define USB_WAI_SEM(ID)             USB_NG
    #define USB_POL_SEM(ID)             USB_NG
    #define USB_SIG_SEM(ID)             USB_NG

    #define USB_CRE_ALM(ID, INFO)       USB_NG
    #define USB_STA_ALM(ID, TIME)       USB_NG
    #define USB_STP_ALM(ID)             USB_NG
    #define USB_DEL_ALM(ID)             USB_NG

    #define USB_REL_WAI(ID)
    #define USB_IREL_WAI(ID)
#endif  /* USB_NO_SYSTEM_PP */


#endif  /* __R_USB_CMACSYSTEMCALL_H__ */

#ifndef __R_USB_CEXTERN_H__
#define __R_USB_CEXTERN_H__


/*****************************************************************************
Public Variables
******************************************************************************/
/* r_usb_cDataIO.c */
extern uint32_t         usb_gcstd_DataCnt[][USB_MAX_PIPE_NO + 1u];  /* PIPEn Buffer counter */
extern uint16_t         usb_gcstd_Dma0Dir[];                /* DMA0 direction */
extern uint32_t         usb_gcstd_Dma0Size[];               /* DMA0 buffer size */
extern uint16_t         usb_gcstd_Dma0Fifo[];               /* DMA0 FIFO buffer size */
extern uint16_t         usb_gcstd_Dma0Pipe[];               /* DMA0 pipe number */
extern uint8_t          *usb_gcstd_DataPtr[][USB_MAX_PIPE_NO + 1u]; /* PIPEn Buffer pointer(8bit) */
extern uint16_t         usb_ghstd_IgnoreCnt[][USB_MAX_PIPE_NO + 1u];    /* Ignore count */
extern USB_UTR_t        *usb_gcstd_Pipe[][USB_MAX_PIPE_NO + 1u];    /* Message pipe */
extern uint16_t         usb_gcstd_XckeMode;                 /* XCKE Mode Flag */
extern uint16_t         usb_gcstd_HsEnable[];               /* Hi-speed enable */


/* r_usb_hDriver.c */
extern USB_HCDREG_t     usb_ghstd_DeviceDrv[][USB_MAXDEVADDR + 1u]; /* Device driver (registration) */
extern uint16_t         usb_ghstd_DeviceInfo[][USB_MAXDEVADDR + 1u][8u];
                                                            /* port status, config num, interface class, speed, */
extern uint16_t         usb_ghstd_RemortPort[];
extern uint16_t         usb_ghstd_Ctsq[];                   /* Control transfer stage management */
extern uint16_t         usb_ghstd_MgrMode[][2u];            /* Manager mode */
extern uint16_t         usb_ghstd_DcpRegister[][USB_MAXDEVADDR + 1u];   /* DEVSEL & DCPMAXP (Multiple device) */
extern uint16_t         usb_ghstd_DeviceAddr[];         /* Device address */
extern uint16_t         usb_ghstd_DeviceSpeed[];            /* Reset handshake result */
extern uint16_t         usb_ghstd_DeviceNum[];          /* Device driver number */


/* r_usb_hManager.c */
extern uint16_t         usb_ghstd_EnumSeq[];                /* Enumeration request */
extern uint16_t         usb_ghstd_DeviceDescriptor[USB_DEVICESIZE / 2u];
extern uint16_t         usb_ghstd_ConfigurationDescriptor[USB_CONFIGSIZE / 2u];
extern uint16_t         usb_ghstd_SuspendPipe[USB_MAX_PIPE_NO + 1u];
extern uint8_t          usb_ghstd_EnuWait[];                /* Class check TaskID */
extern uint16_t         usb_ghstd_CheckEnuResult[];     /* Enumeration result check */

/* r_usb_pDriver.c */
extern uint16_t         usb_gpstd_StallPipe[USB_MAX_PIPE_NO + 1u];  /* Stall Pipe info */
extern USB_CB_INFO_t    usb_gpstd_StallCB;                  /* Stall Callback function */
extern uint16_t         usb_gpstd_ConfigNum;                /* Configuration Number */
extern uint16_t         usb_gpstd_AltNum[];                 /* Alternate */
extern uint16_t         usb_gpstd_RemoteWakeup;             /* Remote Wakeup Enable Flag */
extern uint16_t         usb_gpstd_TestModeSelect;           /* Test Mode Selectors */
extern uint16_t         usb_gpstd_TestModeFlag;             /* Test Mode Flag */
extern uint16_t         usb_gpstd_EpTblIndex[];             /* Index of Endpoint Information table */
extern uint16_t         usb_gpstd_ReqType;                  /* Request type */
extern uint16_t         usb_gpstd_ReqTypeType;              /* Request type TYPE */
extern uint16_t         usb_gpstd_ReqTypeRecip;             /* Request type RECIPIENT */
extern uint16_t         usb_gpstd_ReqRequest;               /* Request */
extern uint16_t         usb_gpstd_ReqValue;                 /* Value */
extern uint16_t         usb_gpstd_ReqIndex;                 /* Index */
extern uint16_t         usb_gpstd_ReqLength;                /* Length */
extern uint16_t         usb_gpstd_intsts0;                  /* INTSTS0 */
extern USB_PCDREG_t     usb_gpstd_Driver;                   /* Driver registration */
extern USB_REQUEST_t    usb_gpstd_ReqReg;                   /* Request variable */


/* r_usb_creg_abs.c */
extern uint16_t         usb_gcstd_RhstBit;
extern uint16_t         usb_gcstd_DvsqBit;
extern uint16_t         usb_gcstd_AddrBit;
extern uint16_t         usb_gcstd_SqmonBit;


//extern uint16_t           usb_gcstd_PcutMode[2u];             /* PCUT Mode Flag */

/*****************************************************************************
Public Functions
******************************************************************************/
/* main.c */
void        usb_cstd_IdleTaskStart(void);
void        usb_cstd_IdleTask(USB_VP_INT stacd);

/* r_usb_cIntHandler.c */
void        usb_cstd_InitUsbMessage(USB_UTR_t *ptr, uint16_t function);
void        usb_cstd_DmaHandler(void);
void        usb_cstd_UsbHandler(void);


/* r_usb2_cIntHandler.c */
void        usb2_cstd_DmaHandler(void);
void        usb2_cstd_UsbHandler(void);


/* r_usb_cDataIO.c */
void        usb_cstd_SendStart(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_Buf2Fifo(USB_UTR_t *ptr, uint16_t Pipe, uint16_t useport);
uint16_t    usb_cstd_write_data(USB_UTR_t *, uint16_t, uint16_t);
void        usb_cstd_ReceiveStart(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_Fifo2Buf(USB_UTR_t *ptr, uint16_t Pipe, uint16_t useport);
uint16_t    usb_cstd_read_data(USB_UTR_t *, uint16_t, uint16_t);
void        usb_cstd_DataEnd(USB_UTR_t *ptr, uint16_t Pipe, uint16_t Status);
void        usb_cstd_ForcedTermination(USB_UTR_t *ptr, uint16_t Pipe, uint16_t Status);


/* r_usb_cIntFIFO.c */
void        usb_cstd_BrdyPipe(USB_UTR_t *ptr, uint16_t bitsts);
void        usb_cstd_NrdyPipe(USB_UTR_t *ptr, uint16_t bitsts);
void        usb_cstd_BempPipe(USB_UTR_t *ptr, uint16_t bitsts);


/* r_usb_cScheduler.c */
USB_ER_t    usb_cstd_RecMsg( uint8_t id, USB_MSG_t** mess, USB_TM_t tm );
USB_ER_t    usb_cstd_SndMsg( uint8_t id, USB_MSG_t* mess );
USB_ER_t    usb_cstd_iSndMsg( uint8_t id, USB_MSG_t* mess );
USB_ER_t    usb_cstd_WaiMsg( uint8_t id, USB_MSG_t* mess, uint16_t times );
void        usb_cstd_WaitScheduler(void);
USB_ER_t    usb_cstd_PgetBlk( uint8_t id, USB_UTR_t** blk );
USB_ER_t    usb_cstd_RelBlk( uint8_t id,  USB_UTR_t* blk );
void        usb_cstd_ScheInit(void);


/* r_usb_cStdApi.c */
void        usb_cstd_set_usbip_mode(USB_UTR_t *ptr, uint16_t function);


/* r_usb_hControlRW */
uint16_t    usb_hstd_ControlWriteStart(USB_UTR_t *ptr, uint32_t bsize, uint8_t *table);
void        usb_hstd_ControlReadStart(USB_UTR_t *ptr, uint32_t bsize, uint8_t *table);
void        usb_hstd_StatusStart(USB_UTR_t *ptr);
void        usb_hstd_ControlEnd(USB_UTR_t *ptr, uint16_t Status);
void        usb_hstd_SetupStart(USB_UTR_t *ptr);


/* r_usb_hDriver.c */
uint16_t    usb_hstd_get_device_state(USB_UTR_t *ptr, uint16_t devaddr);
uint8_t     *usb_hstd_DevDescriptor(void);
uint8_t     *usb_hstd_ConDescriptor(void);
uint16_t    usb_hstd_HsFsResult(USB_UTR_t *ptr);
void        usb_hstd_DeviceResume(USB_UTR_t *ptr, uint16_t devaddr);
USB_ER_t    usb_hstd_HcdSndMbx(USB_UTR_t *ptr, uint16_t msginfo, uint16_t dat, uint16_t *adr, USB_CB_INFO_t callback);
void        usb_hstd_MgrSndMbx(USB_UTR_t *ptr, uint16_t msginfo, uint16_t dat, uint16_t res);
void        usb_hstd_HcdTask(USB_VP_INT_t);
USB_ER_t    usb_hstd_ChangeDeviceState(USB_UTR_t *ptr, USB_CB_t complete, uint16_t msginfo, uint16_t member);
USB_ER_t    usb_hstd_TransferStart(USB_UTR_t *ptr);


uint16_t    usb_hstd_ClearStall(USB_UTR_t *ptr, uint16_t pipe, USB_CB_t complete);
uint16_t    usb_hstd_ClearFeature(USB_UTR_t *ptr, uint16_t addr, uint16_t epnum, USB_CB_t complete);
uint16_t    usb_hstd_GetStringDescriptor1Check(uint16_t errcheck);
void        usb_hstd_Suspend(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_Interrupt(USB_UTR_t *p);
void        usb_hstd_BusIntDisable(USB_UTR_t *ptr, uint16_t port);


/* r_usb_hIntFIFO.c */
void        usb_hstd_BrdyPipe(USB_UTR_t *ptr);
void        usb_hstd_NrdyPipe(USB_UTR_t *ptr);
void        usb_hstd_BempPipe(USB_UTR_t *ptr);


/* r_usb_hManager.c */
void        usb_hstd_NotifAtorDetach(USB_UTR_t *ptr, uint16_t result, uint16_t port);
void        usb_hstd_OvcrNotifiation(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_StatusResult(USB_UTR_t *ptr, uint16_t port, uint16_t result);
void        usb_hstd_EnumGetDescriptorAnsi(USB_UTR_t *ptr, uint8_t addr, uint8_t cnt_value);
void        usb_hstd_EnumGetDescriptor(USB_UTR_t *ptr, uint16_t addr, uint16_t cnt_value);
void        usb_hstd_EnumSetAddress(USB_UTR_t *ptr, uint16_t addr, uint16_t setaddr);
void        usb_hstd_EnumSetConfiguration(USB_UTR_t *ptr, uint16_t addr, uint16_t confnum);
void        usb_hstd_EnumDummyRequest(USB_UTR_t *ptr, uint16_t addr, uint16_t CntValue);
void        usb_hstd_MgrTask(USB_VP_INT_t);


/* r_usb_hStdFunction.c */
void        usb_hstd_Bchg0Function(USB_UTR_t *ptr);
void        usb_hstd_LsConnectFunction(USB_UTR_t *ptr);
void        usb_hstd_AttachFunction(void);
uint16_t    usb_hstd_EnumFunction1(void);
uint16_t    usb_hstd_EnumFunction2(uint16_t* enummode);
void        usb_hstd_EnumFunction3(USB_UTR_t *ptr, uint16_t devaddr, uint16_t enum_seq);
void        usb_hstd_EnumFunction4(uint16_t* reqnum, uint16_t* enummode, uint16_t devaddr);
void        usb_hstd_EnumFunction5(void);


/* r_usb_pDriver.c */
USB_ER_t    usb_pstd_PcdSndMbx(USB_UTR_t *ptr, uint16_t msginfo, uint16_t keyword, USB_CB_INFO_t complete);
void        usb_pstd_PcdRelMpl(uint16_t);
void        usb_pstd_PcdTask(USB_VP_INT_t);
void        usb_pstd_Interrupt(USB_UTR_t *ptr);
void        usb_pstd_ClearMem(void);
void        usb_pstd_SetConfigNum(uint16_t Value);
void        usb_pstd_ClearEpTblIndex(void);
uint16_t    usb_pstd_GetConfigNum(void);
uint16_t    usb_pstd_GetInterfaceNum(uint16_t Con_Num);
uint16_t    usb_pstd_GetAlternateNum(uint16_t Con_Num, uint16_t Int_Num);
void        usb_pstd_SetEpTblIndex(uint16_t Con_Num, uint16_t Int_Num, uint16_t Alt_Num);
uint16_t    usb_pstd_ChkRemote(void);
uint8_t     usb_pstd_GetCurrentPower(void);
USB_ER_t    R_usb_pstd_SetStall(USB_UTR_t *ptr, USB_CB_INFO_t complete, uint16_t pipe);


/* r_usb_pIntFIFO.c */
void        usb_pstd_BrdyPipe(USB_UTR_t *ptr, uint16_t bitsts);
void        usb_pstd_NrdyPipe(USB_UTR_t *ptr, uint16_t bitsts);
void        usb_pstd_BempPipe(USB_UTR_t *ptr, uint16_t bitsts);


/* r_usb_pStdFunction.c */
void        usb_pstd_AttachFunction(USB_UTR_t *ptr);
void        usb_pstd_BusresetFunction(USB_UTR_t *ptr);
void        usb_pstd_SuspendFunction(USB_UTR_t *ptr);

/* r_usb_pStdRequest.c */
void        usb_pstd_StandReq0(USB_UTR_t *ptr);
void        usb_pstd_StandReq1(USB_UTR_t *ptr);
void        usb_pstd_StandReq2(USB_UTR_t *ptr);
void        usb_pstd_StandReq3(USB_UTR_t *ptr);
void        usb_pstd_StandReq4(USB_UTR_t *ptr);
void        usb_pstd_StandReq5(USB_UTR_t *ptr);
void        usb_pstd_SetFeatureFunction(USB_UTR_t *ptr);


/* r_usb_smp_cSub.c */
void        usb_cstd_DummyFunction(USB_UTR_t *ptr, uint16_t data1, uint16_t data2);
void        usb_cstd_DummyTrn(USB_UTR_t *ptr, USB_REQUEST_t *data1, uint16_t data2);
void        usb_cstd_ClassProcessResult(USB_UTR_t *ptr, uint16_t data,uint16_t dummy);
void        usb_cstd_ClassTransResult(USB_UTR_t *mess, uint16_t, uint16_t);


/* r_usb_smp_hSub.c */
uint16_t    usb_hstd_CheckDescriptor(uint8_t *table, uint16_t spec);
uint16_t    usb_hstd_GetConfigDesc(USB_UTR_t *ptr, uint16_t addr, uint16_t length, USB_CB_t complete);
uint16_t    usb_hstd_SetFeature(USB_UTR_t *ptr, uint16_t addr, uint16_t epnum, USB_CB_t complete);
uint16_t    usb_hstd_GetStringDescriptor1(USB_UTR_t *ptr, uint16_t devaddr, uint16_t index, USB_CB_t complete);
uint16_t    usb_hstd_GetStringDescriptor2(USB_UTR_t *ptr, uint16_t devaddr, uint16_t index, USB_CB_t complete);
uint16_t    usb_hstd_GetStringDescriptor2Check(uint16_t errcheck);
uint16_t    usb_hstd_StdReqCheck(uint16_t errcheck);

/* r_usb_hHubsys.c, r_usb_hHubsys_uitron.c */
void        usb_hhub_Initial(USB_UTR_t *ptr, uint16_t data1, uint16_t data2);
void        usb_hhub_Task(USB_VP_INT_t);
void        usb_hhub_ChkClass(USB_UTR_t *ptr, uint16_t **table);
USB_ER_t    usb_hhub_ChangeState(USB_UTR_t *ptr, uint16_t devaddr, uint16_t msginfo, USB_CB_INFO_t callback);

/* r_usb_creg_abs.c */
USB_REGADR_t    usb_cstd_GetUsbIpAdr( uint16_t ipno );

uint32_t    usb_cstd_GetD0fifo16Adr( USB_UTR_t *ptr );
uint32_t    usb_cstd_GetD0fifo8Adr( USB_UTR_t *ptr );
void        usb_cstd_AsspConfig(USB_UTR_t *ptr);
void        usb_cstd_Pinconfig(USB_UTR_t *ptr);
void        usb_cstd_InitialClock(USB_UTR_t *ptr);
void        usb_cstd_InterruptClock(USB_UTR_t *ptr);
void        usb_cstd_SelfClock(USB_UTR_t *ptr);
void        usb_cstd_StopClock(USB_UTR_t *ptr);
void        usb_cstd_NrdyEnable(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_BerneEnable(USB_UTR_t *ptr);
void        usb_cstd_SwReset(USB_UTR_t *ptr);
uint16_t    usb_cstd_GetPid(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_ClearIntEnb( USB_UTR_t *ptr );
void        usb_cstd_ClearIntSts( USB_UTR_t *ptr );
void        usb_cstd_ClearDline( USB_UTR_t *ptr );
uint16_t    usb_cstd_PortSpeed(USB_UTR_t *ptr, uint16_t port);
uint16_t    usb_cstd_HiSpeedEnable(USB_UTR_t *ptr, uint16_t port);
void        usb_cstd_SetHse(USB_UTR_t *ptr, uint16_t port, uint16_t speed);
void        usb_cstd_DoSqtgl(USB_UTR_t *ptr, uint16_t Pipe, uint16_t toggle);
uint16_t    usb_cstd_GetBufSize(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_GetMaxPacketSize(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_GetDevsel(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_GetPipeDir(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_GetPipeType(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_pipe_init(USB_UTR_t *ptr, uint16_t pipe, uint16_t *tbl, uint16_t ofs);
void        usb_cstd_ClrPipeCnfg(USB_UTR_t *ptr, uint16_t PipeNo);
uint16_t    usb_cstd_is_host_mode(USB_UTR_t *ptr);
void        usb_cstd_set_usbip_mode_sub(USB_UTR_t *ptr, uint16_t function);
void        usb_cstd_WaitUsbip(USB_UTR_t *ptr);
void        usb_cstd_DoAclrm(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_SetBuf(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_SetNak(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_cstd_ClrStall(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_Epadr2Pipe(USB_UTR_t *ptr, uint16_t Dir_Ep);
uint8_t     usb_cstd_Pipe2Epadr(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_Pipe2Fport(USB_UTR_t *ptr, uint16_t Pipe);
uint16_t    usb_cstd_GetDeviceAddress(USB_UTR_t *ptr, uint16_t Pipe);
uint8_t     *usb_cstd_write_fifo( USB_UTR_t *, uint16_t, uint16_t, uint8_t * );
uint8_t     *usb_cstd_read_fifo( USB_UTR_t *, uint16_t, uint16_t, uint8_t * );
uint16_t    usb_cstd_is_set_frdy(USB_UTR_t *ptr, uint16_t Pipe, uint16_t fifosel, uint16_t isel);
void        usb_cstd_chg_curpipe(USB_UTR_t *ptr, uint16_t Pipe, uint16_t fifosel, uint16_t isel);
void        usb_cstd_SetTransactionCounter(USB_UTR_t *ptr, uint16_t trnreg, uint16_t trncnt);
void        usb_cstd_ClrTransactionCounter(USB_UTR_t *ptr, uint16_t trnreg);


/* r_usb_creg_dmadtc.c */
void        usb_cstd_D0fifoStopUsb(USB_UTR_t *ptr);
void        usb_cstd_D0fifoInt(USB_UTR_t *ptr);
void        usb_cstd_Buf2fifoStartDma( USB_UTR_t *, uint16_t, uint16_t );
void        usb_cstd_Fifo2BufStartDma( USB_UTR_t *, uint16_t, uint16_t, uint32_t );


/* r_usb_hostelectrical.c */
void        usb_hstd_TestStop(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_TestSignal(USB_UTR_t *ptr, uint16_t port, uint16_t command);
void        usb_hstd_TestUactControl(USB_UTR_t *ptr, uint16_t port, uint16_t command);
void        usb_hstd_TestVbusControl(USB_UTR_t *ptr, uint16_t port, uint16_t command);
void        usb_hstd_TestBusReset(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_TestSuspend(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_TestResume(USB_UTR_t *ptr, uint16_t port);


/* r_usb_hreg_abs */
void        usb_hstd_SetDevAddr(USB_UTR_t *ptr, uint16_t addr, uint16_t speed, uint16_t port);
void        usb_hstd_SetHubPort(USB_UTR_t *ptr, uint16_t addr, uint16_t upphub, uint16_t hubport);
void        usb_hstd_BchgEnable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_BchgDisable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_SetUact(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_OvrcrEnable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_OvrcrDisable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_AttchEnable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_AttchDisable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_DtchEnable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_DtchDisable(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_InterruptHandler(USB_UTR_t *ptr);
void        usb_hstd_SetPipeRegister(USB_UTR_t *ptr, uint16_t PipeNo, uint16_t *tbl);
uint16_t    usb_hstd_GetRootport(USB_UTR_t *ptr, uint16_t addr);
uint16_t    usb_hstd_ChkDevAddr(USB_UTR_t *ptr, uint16_t addr, uint16_t rootport);
uint16_t    usb_hstd_GetDevSpeed(USB_UTR_t *ptr, uint16_t addr);
void        usb_hstd_VbusControl(USB_UTR_t *ptr, uint16_t port, uint16_t command);
void        usb_hstd_SuspendProcess(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_Attach(USB_UTR_t *ptr, uint16_t result, uint16_t port);
void        usb_hstd_Detach(USB_UTR_t *ptr, uint16_t port);
uint16_t    usb_hstd_InitConnect(USB_UTR_t *ptr, uint16_t port, uint16_t else_connect_inf );

uint16_t    usb_hstd_ChkAttach(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_ChkClk(USB_UTR_t *ptr, uint16_t port, uint16_t event);
void        usb_hstd_ChkClk2(USB_UTR_t *ptr, uint16_t else_connect_inf );
void        usb_hstd_DetachProcess(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_ReadLnst(USB_UTR_t *ptr, uint16_t port, uint16_t *buf);
void        usb_hstd_AttachProcess(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_ChkSof(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_BusReset(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_ResumeProcess(USB_UTR_t *ptr, uint16_t port);
void        usb_hstd_Ovrcr0Function(USB_UTR_t *ptr);
uint16_t    usb_hstd_support_speed_check( USB_UTR_t *ptr, uint16_t port );


/* r_usb_preg_abs.c */
void        usb_pstd_InterruptHandler(USB_UTR_t *ptr);
void        usb_pstd_SaveRequest(USB_UTR_t *ptr);
uint16_t    usb_pstd_ChkConfigured(USB_UTR_t *ptr);
void        usb_pstd_InterruptEnable(USB_UTR_t *ptr);
void        usb_pstd_DpEnable(USB_UTR_t *ptr);
void        usb_pstd_DpDisable(USB_UTR_t *ptr);
void        usb_pstd_BusReset(USB_UTR_t *ptr);
void        usb_pstd_RemoteWakeup(USB_UTR_t *ptr);
void        usb_pstd_InitConnect(USB_UTR_t *ptr);
void        usb_pstd_TestMode(USB_UTR_t *ptr);
void        usb_pstd_AttachProcess(USB_UTR_t *ptr);
void        usb_pstd_DetachProcess(USB_UTR_t *ptr);
void        usb_pstd_SuspendProcess(USB_UTR_t *ptr);
void        usb_pstd_ResumeProcess(USB_UTR_t *ptr);
uint16_t    usb_pstd_ChkVbsts(USB_UTR_t *ptr);
void        usb_pstd_SetStall(USB_UTR_t *ptr, uint16_t Pipe);
void        usb_pstd_SetStallPipe0(USB_UTR_t *ptr);


/* RX_RSK.c */
void        usb_cpu_DelayXms(uint16_t time);
void        usb_cpu_soft_wait_ms(uint16_t time);
void        usb_cpu_Delay1us(uint16_t time);
#if USB_TARGET_CHIP_PP == USB_RX600_PP
void        usb_cpu_d0fifo2buf_start_dma(USB_UTR_t *ptr, uint32_t SourceAddr);
void        usb_cpu_buf2d0fifo_start_dma(USB_UTR_t *ptr, uint32_t DistAdr);
#else   /* USB_TARGET_CHIP_PP == USB_RX600_PP */
void        usb_cpu_d0fifo2buf_start_dma(USB_UTR_t *ptr, uint32_t SourceAddr, uint32_t count );
void        usb_cpu_buf2d0fifo_start_dma(USB_UTR_t *ptr, uint32_t DistAdr, uint32_t count );
#endif  /* USB_TARGET_CHIP_PP == USB_RX600_PP */
void        usb_cpu_d0fifo_stop_dma(USB_UTR_t *ptr);
void        usb_cpu_target_init(void);
void        usb_cpu_TargetLcdClear(void);
void        usb_cpu_McuInitialize(void);
void        usb_cpu_DisableDma(USB_UTR_t *ptr);
void        usb_cpu_EnableDma(USB_UTR_t *ptr);
void        usb_cpu_d0fifo_restart_dma( USB_UTR_t *ptr );


/* resetprg.c */

uint16_t    usb_pstd_ControlRead(USB_UTR_t *ptr, uint32_t Bsize, uint8_t *Table);
void        usb_pstd_ControlWrite(USB_UTR_t *ptr, uint32_t Bsize, uint8_t *Table);
void        usb_pstd_ControlEnd(USB_UTR_t *ptr, uint16_t status);

/* r_usb_pDriverAPI.c */
void        usb_pstd_SetPipeRegister(USB_UTR_t *ptr, uint16_t PipeNo, uint16_t *tbl);

uint16_t    usb_setEpTbl( uint8_t pipe, uint16_t *p_eptbl );
uint8_t     *usb_search_ifDesc( uint8_t class );

#endif  /* __R_USB_CEXTERN_H__ */

/* $Id: r_usb_reg_access.h 143 2012-05-07 09:16:46Z tmura $ */

/************/
/*  SYSCFG  */
/************/
uint16_t    usb_creg_read_syscfg( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_write_syscfg( USB_UTR_t *ptr, uint16_t port, uint16_t  data );
void        usb_creg_set_xtal( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_xcke( USB_UTR_t *ptr );
void        usb_creg_set_scke( USB_UTR_t *ptr );
void        usb_creg_clr_scke( USB_UTR_t *ptr );
void        usb_creg_set_hse( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_clr_hse( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_set_dcfm( USB_UTR_t *ptr );
void        usb_creg_clr_dcfm( USB_UTR_t *ptr );
void        usb_creg_set_drpd( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_clr_drpd( USB_UTR_t *ptr, uint16_t port );
void        usb_preg_set_dprpu( USB_UTR_t *ptr );
void        usb_preg_clr_dprpu( USB_UTR_t *ptr );
void        usb_creg_set_usbe( USB_UTR_t *ptr );
void        usb_creg_clr_usbe( USB_UTR_t *ptr );
void        usb_hreg_clr_drpd( USB_UTR_t *ptr, uint16_t port );

/************/
/*  SYSSTS0 */
/************/
uint16_t    usb_creg_read_syssts( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_write_syssts( USB_UTR_t *ptr, uint16_t port, uint16_t data );

/**************/
/*  DVSTCTR0  */
/**************/
uint16_t    usb_creg_read_dvstctr( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_write_dvstctr( USB_UTR_t *ptr, uint16_t port, uint16_t data );
void        usb_creg_rmw_dvstctr( USB_UTR_t *ptr, uint16_t port, uint16_t data, uint16_t width );
void        usb_creg_clr_dvstctr( USB_UTR_t *ptr, uint16_t port, uint16_t data );
void        usb_creg_set_vbout( USB_UTR_t *ptr, uint16_t port );
void        usb_creg_clr_vbout( USB_UTR_t *ptr, uint16_t port );
void        usb_preg_set_wkup( USB_UTR_t *ptr );
void        usb_hreg_set_rwupe( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_rwupe( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_set_resume( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_resume( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_set_uact( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_uact( USB_UTR_t *ptr, uint16_t port );

/**************/
/*  TESTMODE  */
/**************/
void        usb_creg_set_utst( USB_UTR_t *ptr, uint16_t data );

/************/
/*  PINCFG  */
/************/
void        usb_creg_set_ldrv( USB_UTR_t *ptr );
void        usb_creg_clr_ldrv( USB_UTR_t *ptr );

/**********************************/
/*  DMA0CFG, DMA1CFG  for 597ASSP */
/**********************************/
void        usb_creg_write_dmacfg( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data );

/***************************/
/*  CFIFO, D0FIFO, D1FIFO  */
/***************************/
uint32_t    usb_creg_read_fifo32( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_write_fifo32( USB_UTR_t *ptr, uint16_t pipemode, uint32_t data );
uint16_t    usb_creg_read_fifo16( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_write_fifo16( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data );
uint8_t     usb_creg_read_fifo8( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_write_fifo8( USB_UTR_t *ptr, uint16_t pipemode, uint8_t data );
/************************************/
/*  CFIFOSEL, D0FIFOSEL, D1FIFOSEL  */
/************************************/
uint16_t    usb_creg_read_fifosel( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_write_fifosel( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data );
void        usb_creg_rmw_fifosel( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data, uint16_t width );
void        usb_creg_set_dclrm( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_clr_dclrm( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_set_dreqe( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_clr_dreqe( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_set_mbw( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data );
void        usb_creg_set_bigend( USB_UTR_t *ptr, uint16_t pipemode, uint16_t data );
void        usb_creg_set_curpipe( USB_UTR_t *ptr, uint16_t  pipemode, uint16_t  pipeno );

/**********************************/
/* CFIFOCTR, D0FIFOCTR, D1FIFOCTR */
/**********************************/
uint16_t    usb_creg_read_fifoctr( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_set_bval( USB_UTR_t *ptr, uint16_t pipemode );
void        usb_creg_set_bclr( USB_UTR_t *ptr, uint16_t pipemode );

/*************/
/*  INTENB0  */
/*************/
uint16_t    usb_creg_read_intenb( USB_UTR_t *ptr );
void        usb_creg_write_intenb( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_intenb( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_clr_enb_vbse( USB_UTR_t *ptr );
void        usb_preg_set_enb_rsme( USB_UTR_t *ptr );
void        usb_preg_clr_enb_rsme( USB_UTR_t *ptr );
void        usb_creg_clr_enb_sofe( USB_UTR_t *ptr );

/*************/
/*  INTENB1  */
/*************/
uint16_t    usb_hreg_read_intenb( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_write_intenb( USB_UTR_t *ptr, uint16_t port, uint16_t data );
void        usb_hreg_set_enb_ovrcre( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_enb_ovrcre( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_set_enb_bchge( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_enb_bchge( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_set_enb_dtche( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_enb_dtche( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_set_enb_attche( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_enb_attche( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_set_enb_signe( USB_UTR_t *ptr );
void        usb_hreg_clr_enb_signe( USB_UTR_t *ptr );
void        usb_hreg_set_enb_sacke( USB_UTR_t *ptr );
void        usb_hreg_clr_enb_sacke( USB_UTR_t *ptr );

/*************/
/*  BRDYENB  */
/*************/
uint16_t    usb_creg_read_brdyenb( USB_UTR_t *ptr );
void        usb_creg_write_brdyenb( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_brdyenb( USB_UTR_t *ptr, uint16_t  pipeno );
void        usb_creg_clr_brdyenb( USB_UTR_t *ptr, uint16_t  pipeno );

/*************/
/*  NRDYENB  */
/*************/
uint16_t    usb_creg_read_nrdyenb( USB_UTR_t *ptr );
void        usb_creg_write_nrdyenb( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_nrdyenb( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_clr_nrdyenb(USB_UTR_t *ptr, uint16_t pipeno );

/*************/
/*  BEMPENB  */
/*************/
uint16_t    usb_creg_read_bempenb( USB_UTR_t *ptr );
void        usb_creg_write_bempenb( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_bempenb( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_clr_bempenb( USB_UTR_t *ptr, uint16_t pipeno );

/*************/
/*  SOFCFG   */
/*************/
uint16_t    usb_creg_read_sofcfg( USB_UTR_t *ptr );
void        usb_hreg_set_trnensel( USB_UTR_t *ptr );
void        usb_hreg_clr_trnensel( USB_UTR_t *ptr );

/*************/
/*  INTSTS0  */
/*************/
uint16_t    usb_creg_read_intsts( USB_UTR_t *ptr );
void        usb_creg_write_intsts( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_clr_sts_vbint( USB_UTR_t *ptr );
void        usb_preg_clr_sts_resm( USB_UTR_t *ptr );
void        usb_creg_clr_sts_sofr( USB_UTR_t *ptr );
void        usb_preg_clr_sts_dvst( USB_UTR_t *ptr );
void        usb_preg_clr_sts_ctrt( USB_UTR_t *ptr );
void        usb_preg_clr_sts_valid( USB_UTR_t *ptr );

/*************/
/*  INTSTS1  */
/*************/
uint16_t    usb_hreg_read_intsts( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_write_intsts( USB_UTR_t *ptr, uint16_t port, uint16_t data );
void        usb_hreg_clr_sts_ovrcr( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_sts_bchg( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_sts_dtch( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_sts_attch( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_sts_eoferr( USB_UTR_t *ptr, uint16_t port );
void        usb_hreg_clr_sts_sign( USB_UTR_t *ptr );
void        usb_hreg_clr_sts_sack( USB_UTR_t *ptr );

/************/
/* BRDYSTS  */
/************/
uint16_t    usb_creg_read_brdysts( USB_UTR_t *ptr );
void    usb_creg_write_brdysts( USB_UTR_t *pt, uint16_t data );
void        usb_creg_clr_sts_brdy( USB_UTR_t *ptr, uint16_t pipeno );

/************/
/* NRDYSTS  */
/************/
uint16_t    usb_creg_read_nrdysts( USB_UTR_t *ptr );
void        usb_creg_write_nrdysts( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_clr_sts_nrdy( USB_UTR_t *ptr, uint16_t pipeno );

/************/
/* BEMPSTS  */
/************/
uint16_t    usb_creg_read_bempsts( USB_UTR_t *ptr );
void        usb_creg_write_bempsts( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_clr_sts_bemp( USB_UTR_t *ptr, uint16_t pipeno );

/************/
/* FRMNUM   */
/************/
uint16_t    usb_creg_read_frmnum( USB_UTR_t *ptr );

/************/
/* USBADDR  */
/************/
uint16_t    usb_creg_read_usbaddr( USB_UTR_t *ptr );
void        usb_creg_set_stsrecov( USB_UTR_t *ptr, uint16_t data );

/************/
/* USBREQ   */
/************/
uint16_t    usb_creg_read_usbreq( USB_UTR_t *ptr );
void        usb_hreg_write_usbreq( USB_UTR_t *ptr, uint16_t data );

/************/
/* USBVAL   */
/************/
uint16_t    usb_creg_read_usbval( USB_UTR_t *ptr );
void        usb_hreg_set_usbval( USB_UTR_t *ptr, uint16_t data );

/************/
/* USBINDX  */
/************/
uint16_t    usb_creg_read_usbindx( USB_UTR_t *ptr );
void        usb_hreg_set_usbindx( USB_UTR_t *ptr, uint16_t data );

/************/
/* USBLENG  */
/************/
uint16_t    usb_creg_read_usbleng( USB_UTR_t *ptr );
void        usb_hreg_set_usbleng( USB_UTR_t *ptr, uint16_t data );

/************/
/* DCPCFG   */
/************/
uint16_t    usb_creg_read_dcpcfg( USB_UTR_t *ptr );
void        usb_creg_write_dcpcfg( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_dcpshtnak( USB_UTR_t *ptr );

/************/
/* DCPMAXP  */
/************/
uint16_t    usb_creg_read_dcpmaxp( USB_UTR_t *ptr );
void    usb_creg_write_dcpmxps( USB_UTR_t *ptr, uint16_t data );

/************/
/* DCPCTR   */
/************/
uint16_t    usb_creg_read_dcpctr( USB_UTR_t *ptr );
void        usb_hreg_write_dcpctr( USB_UTR_t *ptr, uint16_t data );
void        usb_hreg_set_sureq( USB_UTR_t *ptr );
void        usb_hreg_set_sureqclr( USB_UTR_t *ptr );
void        usb_preg_set_ccpl( USB_UTR_t *ptr );

/************/
/* PIPESEL  */
/************/
uint16_t    usb_creg_read_pipesel( USB_UTR_t *ptr );
void        usb_creg_write_pipesel( USB_UTR_t *ptr, uint16_t data );

/************/
/* PIPECFG  */
/************/
uint16_t    usb_creg_read_pipecfg( USB_UTR_t *ptr );
void        usb_creg_write_pipecfg( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_type( USB_UTR_t *ptr, uint16_t data );

/************/
/* PIPEBUF  */
/************/
void        usb_creg_write_pipebuf( USB_UTR_t *ptr, uint16_t data );

/************/
/* PIPEMAXP */
/************/
uint16_t    usb_creg_read_pipemaxp( USB_UTR_t *ptr );
void        usb_creg_write_pipemaxp( USB_UTR_t *ptr, uint16_t data );
void        usb_hreg_set_devsel( USB_UTR_t *ptr, uint16_t data );
void        usb_creg_set_mxps( USB_UTR_t *ptr, uint16_t data );

/************/
/* PIPEPERI */
/************/
uint16_t    usb_creg_read_pipeperi( USB_UTR_t *ptr );
void        usb_creg_write_pipeperi( USB_UTR_t *ptr, uint16_t data );

/********************/
/* DCPCTR, PIPEnCTR */
/********************/
uint16_t    usb_creg_read_pipectr( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_write_pipectr( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data );
void        usb_creg_set_csclr( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_set_aclrm( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_clr_aclrm( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_set_sqclr( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_set_sqset( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_clr_sqset( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_set_pid( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data );
void        usb_creg_clr_pid( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data );

/************/
/* PIPEnTRE */
/************/
uint16_t    usb_creg_read_pipetre( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_set_trenb( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_clr_trenb( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_set_trclr( USB_UTR_t *ptr, uint16_t pipeno );

/************/
/* PIPEnTRN */
/************/
uint16_t    usb_creg_read_pipetrn( USB_UTR_t *ptr, uint16_t pipeno );
void        usb_creg_write_pipetrn( USB_UTR_t *ptr, uint16_t pipeno, uint16_t data );

/************/
/* DEVADDn  */
/************/
uint16_t    usb_hreg_read_devadd( USB_UTR_t *ptr, uint16_t devadr );
void        usb_hreg_set_usbspd( USB_UTR_t *ptr, uint16_t devadr, uint16_t data );

#ifndef __R_USB_CUSBDEFBITDEFINE_H__
#define __R_USB_CUSBDEFBITDEFINE_H__


/*****************************************************************************
Structure Types
******************************************************************************/

/* USB_597IP_PP Register definition */

/* System Configuration Control Register */
/*#define   USB_SYSCFG0     (*((REGP*)(USB_BASE+0x00))) */
/*#define   USB_SYSCFG1     (*((REGP*)(USB_BASE+0x02))) */
#define USB_XTAL                (0xC000u)   /* b15-14: Crystal selection */
#define   USB_XTAL48             0x8000u        /* 48MHz */
#define   USB_XTAL24             0x4000u        /* 24MHz */
#define   USB_XTAL12             0x0000u        /* 12MHz */
#define USB_XCKE                (0x2000u)   /* b13: External clock enable */
#define USB_CNTFLG              (0x1000u)   /* b12: Auto clock monitor */
#define USB_PLLC                (0x0800u)   /* b11: PLL control */
#define USB_SCKE                (0x0400u)   /* b10: USB clock enable */
#define USB_PCSDIS              (0x0200u)   /* b9: not CS wakeup */
#define USB_LPSME               (0x0100u)   /* b8: Low power sleep mode */
#define USB_HSE             (0x0080u)   /* b7: Hi-speed enable */
#define USB_DCFM                (0x0040u)   /* b6: Function select */
#define USB_DRPD                (0x0020u)   /* b5: D+/D- pull down control */
#define USB_DPRPU               (0x0010u)   /* b4: D+ pull up control */
#define USB_USBE                (0x0001u)   /* b0: USB module enable */

/* System Configuration Status Register */
/*#define   USB_SYSSTS0     (*((REGP*)(USB_BASE+0x04))) */
/*#define   USB_SYSSTS1     (*((REGP*)(USB_BASE+0x06))) */
#define USB_OVCBIT              (0x8000u)   /* b15-14: Over-current bit */
#define USB_OVCMON              (0xC000u)   /* b15-14: Over-current monitor */
#define USB_HTACT               (0x0040u)   /* b6: USB Host Sequencer Status Monitor */
#define USB_SOFEA               (0x0020u)   /* b5: SOF monitor */
#define USB_IDMON               (0x0004u)   /* b2: ID-pin monitor */
#define USB_LNST                (0x0003u)   /* b1-0: D+, D- line status */
#define   USB_SE1                0x0003u        /* SE1 */
#define   USB_FS_KSTS            0x0002u        /* Full-Speed K State */
#define   USB_FS_JSTS            0x0001u        /* Full-Speed J State */
#define   USB_LS_JSTS            0x0002u        /* Low-Speed J State */
#define   USB_LS_KSTS            0x0001u        /* Low-Speed K State */
#define   USB_SE0                0x0000u        /* SE0 */

/* Device State Control Register */
/*#define   USB_DVSTCTR0        (*((REGP*)(USB_BASE+0x08))) */
/*#define   USB_DVSTCTR1        (*((REGP*)(USB_BASE+0x0A))) */
#define USB_HNPBTOA         (0x0800u)   /* b11: Host negotiation protocol
                                             (BtoA) */
#define USB_EXTLP0              (0x0400u)   /* b10: External port */
#define USB_VBOUT               (0x0200u)   /* b9: VBUS output */
#define USB_WKUP                (0x0100u)   /* b8: Remote wakeup */
#define USB_RWUPE               (0x0080u)   /* b7: Remote wakeup sense */
#define USB_USBRST              (0x0040u)   /* b6: USB reset enable */
#define USB_RESUME              (0x0020u)   /* b5: Resume enable */
#define USB_UACT                (0x0010u)   /* b4: USB bus enable */
#define USB_RHST                (0x0007u)   /* b2-0: Reset handshake status */
#define   USB_HSPROC             0x0004u        /* HS handshake processing */
#define   USB_HSMODE             0x0003u        /* Hi-Speed mode */
#define   USB_FSMODE             0x0002u        /* Full-Speed mode */
#define   USB_LSMODE             0x0001u        /* Low-Speed mode */
#define   USB_UNDECID            0x0000u        /* Undecided */

/* Test Mode Register */
/*#define   USB_TESTMODE        (*((REGP*)(USB_BASE+0x0C))) */
#define USB_UTST                (0x000Fu)   /* b3-0: Test select */
#define   USB_H_TST_PACKET       0x000Cu        /* HOST TEST Packet */
#define   USB_H_TST_SE0_NAK  0x000Bu        /* HOST TEST SE0 NAK */
#define   USB_H_TST_K            0x000Au        /* HOST TEST K */
#define   USB_H_TST_J            0x0009u        /* HOST TEST J */
#define   USB_H_TST_NORMAL       0x0000u        /* HOST Normal Mode */
#define   USB_P_TST_PACKET       0x0004u        /* PERI TEST Packet */
#define   USB_P_TST_SE0_NAK  0x0003u        /* PERI TEST SE0 NAK */
#define   USB_P_TST_K            0x0002u        /* PERI TEST K */
#define   USB_P_TST_J            0x0001u        /* PERI TEST J */
#define   USB_P_TST_NORMAL       0x0000u        /* PERI Normal Mode */

/* Data Pin Configuration Register */
/*#define   USB_PINCFG          (*((REGP*)(USB_BASE+0x0E))) */
#define USB_LDRV                (0x8000u)   /* b15: Drive Current Adjust */
#define   USB_VIF1               0x0000u        /* VIF = 1.8V */
#define   USB_VIF3               0x8000u        /* VIF = 3.3V */
#define USB_INTA                (0x0001u)   /* b1: USB INT-pin active */


/* DMAx Pin Configuration Register */
/*#define   USB_DMA0CFG     (*((REGP*)(USB_BASE+0x10))) */
/*#define   USB_DMA1CFG     (*((REGP*)(USB_BASE+0x12))) */
#define USB_DREQA               (0x4000u)   /* b14: Dreq active select */
#define USB_BURST               (0x2000u)   /* b13: Burst mode */
#define USB_DACKA               (0x0400u)   /* b10: Dack active select */
#define USB_DFORM               (0x0380u)   /* b9-7: DMA mode select */
#define   USB_CPU_ADR_RD_WR  0x0000u        /* Address + RD/WR mode
                                                 (CPU bus) */
#define   USB_CPU_DACK_RD_WR     0x0100u        /* DACK + RD/WR (CPU bus) */
#define   USB_CPU_DACK_ONLY  0x0180u        /* DACK only (CPU bus) */
#define   USB_SPLIT_DACK_ONLY    0x0200u        /* DACK only (SPLIT bus) */
#define USB_DENDA               (0x0040u)   /* b6: Dend active select */
#define USB_PKTM                (0x0020u)   /* b5: Packet mode */
#define USB_DENDE               (0x0010u)   /* b4: Dend enable */
#define USB_OBUS                (0x0004u)   /* b2: OUTbus mode */


/* CFIFO/DxFIFO Port Register */
/*#define   USB_CFIFO           (*((REGP*)(USB_BASE+0x14))) */
/*#define   USB_CFIFO_8     (*((REGP8*)(USB_BASE+0x14))) */
/*#define   USB_D0FIFO          (*((REGP*)(USB_BASE+0x18))) */
/*#define   USB_D0FIFO_8        (*((REGP8*)(USB_BASE+0x18))) */
/*#define   USB_D1FIFO          (*((REGP*)(USB_BASE+0x1C))) */
/*#define   USB_D1FIFO_8        (*((REGP8*)(USB_BASE+0x1C))) */

/* CFIFO/DxFIFO Port Select Register */
/*#define   USB_CFIFOSEL        (*((REGP*)(USB_BASE+0x20))) */
/*#define   USB_D0FIFOSEL       (*((REGP*)(USB_BASE+0x28))) */
/*#define   USB_D1FIFOSEL       (*((REGP*)(USB_BASE+0x2C))) */
#define USB_RCNT                (0x8000u)   /* b15: Read count mode */
#define USB_REW             (0x4000u)   /* b14: Buffer rewind */
#define USB_DCLRM               (0x2000u)   /* b13: DMA buffer clear mode */
#define USB_DREQE               (0x1000u)   /* b12: DREQ output enable */
#define USB_MBW             (0x0400u)   /* b10: Maximum bit width for
                                                     FIFO access */
#define   USB_MBW_8          0x0000u        /*  8bit */
#define   USB_MBW_16             0x0400u        /* 16bit */
#define USB_BIGEND              (0x0100u)   /* b8: Big endian mode */
#define   USB_FIFO_LITTLE        0x0000u        /* Little endian */
#define   USB_FIFO_BIG           0x0100u        /* Big endian */
#define USB_ISEL                (0x0020u)   /* b5: DCP FIFO port direction
                                             select */
#define USB_CURPIPE         (0x000Fu)   /* b2-0: PIPE select */

/* CFIFO/DxFIFO Port Control Register */
/*#define   USB_CFIFOCTR        (*((REGP*)(USB_BASE+0x22))) */
/*#define   USB_D0FIFOCTR       (*((REGP*)(USB_BASE+0x2A))) */
/*#define   USB_D1FIFOCTR       (*((REGP*)(USB_BASE+0x2E))) */
#define USB_BVAL                (0x8000u)   /* b15: Buffer valid flag */
#define USB_BCLR                (0x4000u)   /* b14: Buffer clear */
#define USB_FRDY                (0x2000u)   /* b13: FIFO ready */
#define USB_DTLN                (0x0FFFu)   /* b11-0: FIFO data length */


/* Interrupt Enable Register 0 */
/*#define   USB_INTENB0     (*((REGP*)(USB_BASE+0x30))) */
#define USB_VBSE                (0x8000u)   /* b15: VBUS interrupt */
#define USB_RSME                (0x4000u)   /* b14: Resume interrupt */
#define USB_SOFE                (0x2000u)   /* b13: Frame update interrupt */
#define USB_DVSE                (0x1000u)   /* b12: Device state transition
                                             interrupt */
#define USB_CTRE                (0x0800u)   /* b11: Control transfer stage
                                             transition interrupt */
#define USB_BEMPE               (0x0400u)   /* b10: Buffer empty interrupt */
#define USB_NRDYE               (0x0200u)   /* b9: Buffer notready interrupt */
#define USB_BRDYE               (0x0100u)   /* b8: Buffer ready interrupt */

/* Interrupt Enable Register 1 */
/*#define   USB_INTENB1     (*((REGP*)(USB_BASE+0x32))) */
/*#define   USB_INTENB2     (*((REGP*)(USB_BASE+0x34))) */
#define USB_OVRCRE              (0x8000u)   /* b15: Over-current interrupt */
#define USB_BCHGE               (0x4000u)   /* b14: USB bus change interrupt */
#define USB_DTCHE               (0x1000u)   /* b12: Detach sense interrupt */
#define USB_ATTCHE              (0x0800u)   /* b11: Attach sense interrupt */
#define USB_EOFERRE         (0x0040u)   /* b6: EOF error interrupt */
#define USB_SIGNE               (0x0020u)   /* b5: SETUP IGNORE interrupt */
#define USB_SACKE               (0x0010u)   /* b4: SETUP ACK interrupt */

/* BRDY Interrupt Enable/Status Register */
/*#define   USB_BRDYENB     (*((REGP*)(USB_BASE+0x36))) */
/*#define   USB_BRDYSTS     (*((REGP*)(USB_BASE+0x46))) */
#define USB_BRDY9               (0x0200u)   /* b9: PIPE9 */
#define USB_BRDY8               (0x0100u)   /* b8: PIPE8 */
#define USB_BRDY7               (0x0080u)   /* b7: PIPE7 */
#define USB_BRDY6               (0x0040u)   /* b6: PIPE6 */
#define USB_BRDY5               (0x0020u)   /* b5: PIPE5 */
#define USB_BRDY4               (0x0010u)   /* b4: PIPE4 */
#define USB_BRDY3               (0x0008u)   /* b3: PIPE3 */
#define USB_BRDY2               (0x0004u)   /* b2: PIPE2 */
#define USB_BRDY1               (0x0002u)   /* b1: PIPE1 */
#define USB_BRDY0               (0x0001u)   /* b1: PIPE0 */

/* NRDY Interrupt Enable/Status Register */
/*#define   USB_NRDYENB     (*((REGP*)(USB_BASE+0x38))) */
/*#define   USB_NRDYSTS     (*((REGP*)(USB_BASE+0x48))) */
#define USB_NRDY9               (0x0200u)   /* b9: PIPE9 */
#define USB_NRDY8               (0x0100u)   /* b8: PIPE8 */
#define USB_NRDY7               (0x0080u)   /* b7: PIPE7 */
#define USB_NRDY6               (0x0040u)   /* b6: PIPE6 */
#define USB_NRDY5               (0x0020u)   /* b5: PIPE5 */
#define USB_NRDY4               (0x0010u)   /* b4: PIPE4 */
#define USB_NRDY3               (0x0008u)   /* b3: PIPE3 */
#define USB_NRDY2               (0x0004u)   /* b2: PIPE2 */
#define USB_NRDY1               (0x0002u)   /* b1: PIPE1 */
#define USB_NRDY0               (0x0001u)   /* b1: PIPE0 */

/* BEMP Interrupt Enable/Status Register */
/*#define   USB_BEMPENB     (*((REGP*)(USB_BASE+0x3A))) */
/*#define   USB_BEMPSTS     (*((REGP*)(USB_BASE+0x4A))) */
#define USB_BEMP9               (0x0200u)   /* b9: PIPE9 */
#define USB_BEMP8               (0x0100u)   /* b8: PIPE8 */
#define USB_BEMP7               (0x0080u)   /* b7: PIPE7 */
#define USB_BEMP6               (0x0040u)   /* b6: PIPE6 */
#define USB_BEMP5               (0x0020u)   /* b5: PIPE5 */
#define USB_BEMP4               (0x0010u)   /* b4: PIPE4 */
#define USB_BEMP3               (0x0008u)   /* b3: PIPE3 */
#define USB_BEMP2               (0x0004u)   /* b2: PIPE2 */
#define USB_BEMP1               (0x0002u)   /* b1: PIPE1 */
#define USB_BEMP0               (0x0001u)   /* b0: PIPE0 */

/* SOF Pin Configuration Register */
/*#define   USB_SOFCFG          (*((REGP*)(USB_BASE+0x3C))) */
#define USB_TRNENSEL            (0x0100u)   /* b8: Select transaction enable
                                             period */
#define USB_BRDYM               (0x0040u)   /* b6: BRDY clear timing */
#define USB_INTL                (0x0020u)   /* b5: Interrupt sense select */
#define USB_EDGESTS         (0x0010u)   /* b4:  */
#define USB_SOFMODE         (0x000Cu)   /* b3-2: SOF pin select */
#define   USB_SOF_125US      0x0008u        /* SOF 125us Frame Signal */
#define   USB_SOF_1MS            0x0004u        /* SOF 1ms Frame Signal */
#define   USB_SOF_DISABLE        0x0000u        /* SOF Disable */


/* Interrupt Status Register 0 */
/*#define   USB_INTSTS0     (*((REGP*)(USB_BASE+0x40))) */
#define USB_VBINT               (0x8000u)   /* b15: VBUS interrupt */
#define USB_RESM                (0x4000u)   /* b14: Resume interrupt */
#define USB_SOFR                (0x2000u)   /* b13: SOF update interrupt */
#define USB_DVST                (0x1000u)   /* b12: Device state transition
                                             interrupt */
#define USB_CTRT                (0x0800u)   /* b11: Control transfer stage
                                             transition interrupt */
#define USB_BEMP                (0x0400u)   /* b10: Buffer empty interrupt */
#define USB_NRDY                (0x0200u)   /* b9: Buffer notready interrupt */
#define USB_BRDY                (0x0100u)   /* b8: Buffer ready interrupt */
#define USB_VBSTS               (0x0080u)   /* b7: VBUS input port */
#define USB_DVSQ                (0x0070u)   /* b6-4: Device state */
#define   USB_DS_SPD_CNFG        0x0070u        /* Suspend Configured */
#define   USB_DS_SPD_ADDR        0x0060u        /* Suspend Address */
#define   USB_DS_SPD_DFLT        0x0050u        /* Suspend Default */
#define   USB_DS_SPD_POWR        0x0040u        /* Suspend Powered */
#define   USB_DS_SUSP            0x0040u        /* Suspend */
#define   USB_DS_CNFG            0x0030u        /* Configured */
#define   USB_DS_ADDS            0x0020u        /* Address */
#define   USB_DS_DFLT            0x0010u        /* Default */
#define   USB_DS_POWR            0x0000u        /* Powered */
#define USB_DVSQS               (0x0030u)   /* b5-4: Device state */
#define USB_VALID               (0x0008u)   /* b3: Setup packet detect flag */
#define USB_CTSQ                (0x0007u)   /* b2-0: Control transfer stage */
#define   USB_CS_SQER            0x0006u        /* Sequence error */
#define   USB_CS_WRND            0x0005u        /* Ctrl write nodata status
                                                 stage */
#define   USB_CS_WRSS            0x0004u        /* Ctrl write status stage */
#define   USB_CS_WRDS            0x0003u        /* Ctrl write data stage */
#define   USB_CS_RDSS            0x0002u        /* Ctrl read status stage */
#define   USB_CS_RDDS            0x0001u        /* Ctrl read data stage */
#define   USB_CS_IDST            0x0000u        /* Idle or setup stage */

/* Interrupt Status Register 1 */
/*#define   USB_INTSTS1     (*((REGP*)(USB_BASE+0x42))) */
/*#define   USB_INTSTS2     (*((REGP*)(USB_BASE+0x44))) */
#define USB_OVRCR               (0x8000u)   /* b15: Over-current interrupt */
#define USB_BCHG                (0x4000u)   /* b14: USB bus change interrupt */
#define USB_DTCH                (0x1000u)   /* b12: Detach sense interrupt */
#define USB_ATTCH               (0x0800u)   /* b11: Attach sense interrupt */
#define USB_EOFERR              (0x0040u)   /* b6: EOF-error interrupt */
#define USB_SIGN                (0x0020u)   /* b5: Setup ignore interrupt */
#define USB_SACK                (0x0010u)   /* b4: Setup ack interrupt */

/* Frame Number Register */
/*#define   USB_FRMNUM          (*((REGP*)(USB_BASE+0x4C))) */
#define USB_OVRN                (0x8000u)   /* b15: Overrun error */
#define USB_CRCE                (0x4000u)   /* b14: Received data error */
#define USB_FRNM                (0x07FFu)   /* b10-0: Frame number */

/* Micro Frame Number Register */
/*#define   USB_UFRMNUM     (*((REGP*)(USB_BASE+0x4E))) */
#define USB_UFRNM               (0x0007u)   /* b2-0: Micro frame number */


/* USB Address / Low Power Status Recovery Register */
/*#define   USB_USBADDR     (*((REGP*)(USB_BASE+0x50))) */
#define USB_USBADDR_MASK        (0x007Fu)   /* b6-0: USB address */
#define USB_STSRECOV            (0x0F00u)   /* b11-8: Status Recovery */
#define   USB_STSR_SET           0x0800u

/* USB Request Type Register */
/*#define   USB_USBREQ          (*((REGP*)(USB_BASE+0x54))) */
#define USB_BREQUEST            (0xFF00u)   /* b15-8: USB_BREQUEST */
#define USB_BMREQUESTTYPE       (0x00FFu)   /* b7-0: USB_BMREQUESTTYPE */
#define USB_BMREQUESTTYPEDIR    (0x0080u)   /* b7  : Data transfer direction */
#define USB_BMREQUESTTYPETYPE   (0x0060u)   /* b6-5: Type */
#define USB_BMREQUESTTYPERECIP  (0x001Fu)   /* b4-0: Recipient */

/* USB Request Value Register */
/*#define   USB_USBVAL          (*((REGP*)(USB_BASE+0x56))) */
#define USB_WVALUE              (0xFFFFu)   /* b15-0: wValue */
#define USB_DT_TYPE         (0xFF00u)
#define USB_GET_DT_TYPE(v)      (((v) & USB_DT_TYPE) >> 8)
#define USB_DT_INDEX            (0x00FFu)
#define USB_CONF_NUM            (0x00FFu)
#define USB_ALT_SET         (0x00FFu)

/* USB Request Index Register */
/*#define   USB_USBINDX     (*((REGP*)(USB_BASE+0x58))) */
#define USB_WINDEX              (0xFFFFu)   /* b15-0: wIndex */
#define USB_TEST_SELECT     (0xFF00u)   /* b15-b8: Test Mode Selectors */
#define   USB_TEST_J             0x0100u        /* Test_J */
#define   USB_TEST_K             0x0200u        /* Test_K */
#define   USB_TEST_SE0_NAK       0x0300u        /* Test_SE0_NAK */
#define   USB_TEST_PACKET        0x0400u        /* Test_Packet */
#define   USB_TEST_FORCE_ENABLE 0x0500u     /* Test_Force_Enable */
#define   USB_TEST_STSelectors   0x0600u        /* Standard test selectors */
#define   USB_TEST_RESERVED  0x4000u        /* Reserved */
#define   USB_TEST_VSTMODES  0xC000u        /* VendorSpecific test modes */
#define USB_EP_DIR              (0x0080u)   /* b7: Endpoint Direction */
#define   USB_EP_DIR_IN      0x0080u
#define   USB_EP_DIR_OUT         0x0000u

/* USB Request Length Register */
/*#define   USB_USBLENG     (*((REGP*)(USB_BASE+0x5A))) */
#define USB_WLENGTH         (0xFFFFu)   /* b15-0: wLength */


/* Pipe Window Select Register */
/*#define   USB_PIPESEL     (*((REGP*)(USB_BASE+0x64))) */
#define USB_PIPENM              (0x0007u)   /* b2-0: Pipe select */

/* Default Control Pipe Configuration Register */
/*#define   USB_DCPCFG          (*((REGP*)(USB_BASE+0x5C))) */
/* Pipe Configuration Register */
/*#define   USB_PIPECFG     (*((REGP*)(USB_BASE+0x68))) */
/* Refer to usbd_DefUSBIP.h */
#define USB_TYPE            (0xC000u)   /* b15-14: Transfer type */
/*#define   USB_BFRE            (0x0400u)   /* b10: Buffer ready interrupt
                                                 mode select */
/*#define   USB_DBLB            (0x0200u)   /* b9: Double buffer mode select */
/*#define   USB_CBTMD           (0x0100u)   /* b8: Continuous transfer mode
                                                 select */
/*#define   USB_SHTNAK          (0x0080u)   /* b7: Transfer end NAK */
/*#define   USB_DIR         (0x0010u)   /* b4: Transfer direction select */
/*#define   USB_EPNUM           (0x000Fu)   /* b3-0: Endpoint number select */

/* Pipe Buffer Configuration Register */
/*#define   USB_PIPEBUF     (*((REGP*)(USB_BASE+0x6A))) */
/* Refer to usbd_DefUSBIP.h */
#define USB_BUFSIZE         (0x7C00u)   /* b14-10: Pipe buffer size */
#define USB_BUFNMB              (0x007Fu)   /* b6-0: Pipe buffer number */
#define USB_PIPE0BUF            (256u)
#define USB_PIPEXBUF            (64u)

/* Default Control Pipe Maxpacket Size Register */
/* Pipe Maxpacket Size Register */
/*#define   USB_DCPMAXP     (*((REGP*)(USB_BASE+0x5E))) */
/* Pipe Maxpacket Size Register */
/*#define   USB_PIPEMAXP        (*((REGP*)(USB_BASE+0x6C))) */
#define USB_DEVSEL              (0xF000u)   /* b15-14: Device address select */
#define USB_MAXP                (0x007Fu)   /* b6-0: Maxpacket size of default
                                             control pipe */
#define USB_MXPS                (0x07FFu)   /* b10-0: Maxpacket size */

/* Pipe Cycle Configuration Register */
/*#define   USB_PIPEPERI        (*((REGP*)(USB_BASE+0x6E))) */
/* Refer to usbd_DefUSBIP.h */
/*#define   USB_IFIS            (0x1000u)   /* b12: Isochronous in-buffer
                                                 flash mode select */
/*#define   USB_IITV            (0x0007u)   /* b2-0: Isochronous interval */

/* Default Control Pipe Control Register */
/*#define   USB_DCPCTR          (*((REGP*)(USB_BASE+0x60))) */
/* Pipex Control Register */
/*#define   USB_PIPE1CTR        (*((REGP*)(USB_BASE+0x70))) */
/*#define   USB_PIPE2CTR        (*((REGP*)(USB_BASE+0x72))) */
/*#define   USB_PIPE3CTR        (*((REGP*)(USB_BASE+0x74))) */
/*#define   USB_PIPE4CTR        (*((REGP*)(USB_BASE+0x76))) */
/*#define   USB_PIPE5CTR        (*((REGP*)(USB_BASE+0x78))) */
/*#define   USB_PIPE6CTR        (*((REGP*)(USB_BASE+0x7A))) */
/*#define   USB_PIPE7CTR        (*((REGP*)(USB_BASE+0x7C))) */
/*#define   USB_PIPE8CTR        (*((REGP*)(USB_BASE+0x7E))) */
/*#define   USB_PIPE9CTR        (*((REGP*)(USB_BASE+0x80))) */
#define USB_BSTS                (0x8000u)   /* b15: Buffer status */
#define USB_SUREQ               (0x4000u)   /* b14: Send USB request  */
#define USB_INBUFM              (0x4000u)   /* b14: IN buffer monitor
                                                (Only for PIPE1 to 5) */
#define USB_CSCLR               (0x2000u)   /* b13: c-split status clear */
#define USB_CSSTS               (0x1000u)   /* b12: c-split status */
#define USB_SUREQCLR            (0x0800u)   /* b11: stop setup request */
#define USB_ATREPM              (0x0400u)   /* b10: Auto repeat mode */
#define USB_ACLRM               (0x0200u)   /* b9: buffer auto clear mode */
#define USB_SQCLR               (0x0100u)   /* b8: Sequence bit clear */
#define USB_SQSET               (0x0080u)   /* b7: Sequence bit set */
#define USB_SQMON               (0x0040u)   /* b6: Sequence bit monitor */
#define USB_PBUSY               (0x0020u)   /* b5: pipe busy */
#define USB_PINGE               (0x0010u)   /* b4: ping enable */
#define USB_CCPL                (0x0004u)   /* b2: Enable control transfer
                                             complete */
#define USB_PID                 (0x0003u)   /* b1-0: Response PID */
#define USB_PID_STALL           0x0002u     /* STALL */
#define USB_PID_BUF             0x0001u     /* BUF */
#define USB_PID_NAK             0x0000u     /* NAK */


/* PIPExTRE */
/*#define   USB_PIPE1TRE        (*((REGP*)(USB_BASE+0x90))) */
/*#define   USB_PIPE2TRE        (*((REGP*)(USB_BASE+0x94))) */
/*#define   USB_PIPE3TRE        (*((REGP*)(USB_BASE+0x98))) */
/*#define   USB_PIPE4TRE        (*((REGP*)(USB_BASE+0x9C))) */
/*#define   USB_PIPE5TRE        (*((REGP*)(USB_BASE+0xA0))) */
#define USB_TRENB               (0x0200u)   /* b9: Transaction count enable */
#define USB_TRCLR               (0x0100u)   /* b8: Transaction count clear */


/* PIPExTRN */
/*#define   USB_PIPE1TRN        (*((REGP*)(USB_BASE+0x92))) */
/*#define   USB_PIPE2TRN        (*((REGP*)(USB_BASE+0x96))) */
/*#define   USB_PIPE3TRN        (*((REGP*)(USB_BASE+0x9A))) */
/*#define   USB_PIPE4TRN        (*((REGP*)(USB_BASE+0x9E))) */
/*#define   USB_PIPE5TRN        (*((REGP*)(USB_BASE+0xA2))) */
#define USB_TRNCNT              (0xFFFFu)   /* b15-0: Transaction counter */


/* DEVADDx */
/*#define   USB_DEVADD0     (*((REGP*)(USB_BASE+0xD0))) */
/*#define   USB_DEVADD1     (*((REGP*)(USB_BASE+0xD2))) */
/*#define   USB_DEVADD2     (*((REGP*)(USB_BASE+0xD4))) */
/*#define   USB_DEVADD3     (*((REGP*)(USB_BASE+0xD6))) */
/*#define   USB_DEVADD4     (*((REGP*)(USB_BASE+0xD8))) */
/*#define   USB_DEVADD5     (*((REGP*)(USB_BASE+0xDA))) */
/*#define   USB_DEVADD6     (*((REGP*)(USB_BASE+0xDC))) */
/*#define   USB_DEVADD7     (*((REGP*)(USB_BASE+0xDE))) */
/*#define   USB_DEVADD8     (*((REGP*)(USB_BASE+0xE0))) */
/*#define   USB_DEVADD9     (*((REGP*)(USB_BASE+0xE2))) */
/*#define   USB_DEVADDA     (*((REGP*)(USB_BASE+0xE4))) */
#define USB_UPPHUB              (0x7800u)
#define USB_HUBPORT         (0x0700u)
#define USB_USBSPD              (0x00C0u)
#define USB_RTPORT              (0x0001u)


/* Invalid Register. for CS-return from PCUT */
/*#pragma   USB_ADDRESS     INVALID_REG (_USBBASE + EEh) */

#endif  /* __R_USB_CUSBDEFBITDEFINE_H__ */


/* $Id: r_usb_ansi.h 143 2012-05-07 09:16:46Z tmura $ */


#define USB_CLASS_PERI_MODE 0x100

typedef enum
{
    USB_CLASS_HCDCC =   0x0,
    USB_CLASS_HCDCD,
    USB_CLASS_HHID,
    USB_CLASS_HMSC,
    USB_CLASS_HSTD_BULK,
    USB_CLASS_HSTD_INT,
    USB_CLASS_PCDCC = (USB_CLASS_PERI_MODE + USB_CLASS_HSTD_INT + 1),
    USB_CLASS_PCDCD,
    USB_CLASS_PHID,
    USB_CLASS_PMSC,
    USB_CLASS_PSTD_BULK,
    USB_CLASS_PSTD_INT, 
    USB_CLASS_MAX = ((USB_CLASS_PSTD_INT + 1) & (~USB_CLASS_PERI_MODE))
} USB_CLASS_ENUM_t;

#define     USB_RSVED_FN        3
#define     USB_NOPIPE          ((uint8_t)0xFF)

int16_t     usb_open( USB_CLASS_ENUM_t );
int16_t     usb_close( int16_t );
int32_t     usb_read( int16_t, void *, uint32_t );
int32_t     usb_write( int16_t , void *, uint32_t );
uint16_t    usb_open_peri( USB_CLASS_ENUM_t class, int16_t fn );
uint16_t    usb_open_host( USB_CLASS_ENUM_t class, int16_t fn );
uint16_t    usb_close_peri( int16_t fn );
uint16_t    usb_close_host( int16_t fn );

int16_t usb_open_hcdc( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );
int16_t usb_open_hhid( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );
int16_t usb_open_hmsc( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );
int16_t usb_open_pcdc( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );
int16_t usb_open_phid( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );
int16_t usb_open_pmsc( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );

int16_t usb_open_hvendor( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );
int16_t usb_open_pvendor( USB_UTR_t *, struct usb_fninfo *, uint8_t, uint8_t );

extern  int32_t pcdc_read_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t pcdc_write_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hcdc_read_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hcdc_write_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hcdc_read_control( int16_t fn, void *buf, uint32_t length );
extern  int32_t pvendor_read_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t pvendor_write_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hvendor_read_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hvendor_write_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hhid_read_data( int16_t fn, void *buf, uint32_t length );
extern  int32_t hhid_write_data( int16_t fn, void *buf, uint32_t length );

extern  USB_ER_t usb_control_class_request(void *pram);
extern  struct  usb_fninfo  usb_fnInfo[];
extern  struct  usb_devinfo usb_devInfo[];

/* $Id: r_usb_control.h 143 2012-05-07 09:16:46Z tmura $ */

/******************************************************************************
Typedef definitions
******************************************************************************/
typedef enum
{
    USB_CTL_USBIP_NUM = 0,
} USB_CTRLCODE_t;

/* Control function command type */
typedef enum _CTLCOD
{
       USB_CTL_USB_IP_NUM = 0,
       USB_CTL_RD_NOTIFY_SET,
       USB_CTL_WR_NOTIFY_SET,
       USB_CTL_RD_LENGTH_GET,
       USB_CTL_WR_LENGTH_GET,
       USB_CTL_GET_OPEN_STATE,
       USB_CTL_GET_RD_STATE,
       USB_CTL_GET_WR_STATE,
       USB_CTL_H_RD_TRANSFER_END,
       USB_CTL_H_WR_TRANSFER_END,
       USB_CTL_H_CHG_DEVICE_STATE,
       USB_CTL_H_GET_DEVICE_INFO,
       USB_CTL_P_RD_TRANSFER_END,
       USB_CTL_P_WR_TRANSFER_END,
       USB_CTL_P_CHG_DEVICE_STATE,
       USB_CTL_P_GET_DEVICE_INFO,
       USB_CTL_P_RD_SET_STALL,
       USB_CTL_P_WR_SET_STALL,
       USB_CTL_CLASS_REQUEST,
} CTLCODE;

/* Control function error type */
typedef enum _CTLERRCOD
{
       USB_CTL_ERR_NONE = 0,
       USB_CTL_ERR_PROCESS_COMPLETE,
       USB_CTL_ERR_PROCESS_WAIT = -2,
       USB_CTL_ERR_PROCESS_ERR = -3,
       USB_CTL_ERR_PAR = -17,
} CTLERRCODE;

/* USB_CTL_HOST_TRANSFER_END/USB_CTL_PERI_TRANSFER_END Arguments */
typedef struct usb_control_transfer_end
{
    uint16_t        status;             /* End Status */
}
USB_CTL_TRANSFER_END_t;

/* USB_CTL_H_GET_DEVICE_INFO/USB_CTL_P_GET_DEVICE_INFO Arguments */
typedef struct usb_control_device_information
{
    uint16_t        *tbl;               /* Table Pointer */
}
USB_CTL_DEVICE_INFORMATION_t;

/* USB_CTL_H_CHG_DEVICE_STATE/USB_CTL_P_CHG_DEVICE_STATE Arguments */
typedef struct usb_control_change_device_state
{
    USB_CB_t        complete;           /* Callback function */
    uint16_t        msginfo;            /* Request type */
    uint16_t        devaddr;            /* Rootport/Pipe number */
}
USB_CTL_CHANGE_DEVICE_STATE_t;


/* USB_CTL_P_RD_SET_STALL/USB_CTL_P_WR_SET_STALL Arguments */
typedef struct usb_control_set_pipe_stall
{
    USB_CB_t        complete;           /* Callback function */
}
USB_CTL_SET_PIPE_STALL_t;

/* Input parameter for control() function */
typedef union {
    USB_CTL_CHANGE_DEVICE_STATE_t   device_state;
    USB_CTL_DEVICE_INFORMATION_t    device_information;
    USB_CTL_TRANSFER_END_t          transfer_end;
    USB_CTL_SET_PIPE_STALL_t        setstall;
} USB_CTL_PARAMETER_t;

/******************************************************************************
Constant macro definitions
******************************************************************************/
/* Class Request File No. for control function */
#define     CLASS_REQUEST_FN    0x10

/******************************************************************************
Private global variables and functions
******************************************************************************/
int16_t     usb_control( int16_t, USB_CTRLCODE_t, void * );

extern  USB_ER_t usb_control_class_request(void *pram);

/* This definition shows USB IP number that work as USB host mode */
#if USB_FUNCSEL_USBIP0_PP == USB_HOST_PP
    #define USB_HOST_USBIP_NUM  USB_USBIP_0
    #define USB_HOST_MODE_PP
#endif

/* This definition shows USB IP number that work as USB peripheral mode */
#if USB_FUNCSEL_USBIP0_PP == USB_PERI_PP
    #define USB_PERI_USBIP_NUM  USB_USBIP_0
    #define USB_PERI_MODE_PP
#endif


#ifndef __R_USB_API_H__
#define __R_USB_API_H__

//#include "r_usb_ctypedef.h"

/*****************************************************************************
Public Functions (API)
******************************************************************************/

/* ANSI IO */
int16_t open( int8_t *, uint16_t, uint16_t );
int16_t close( int16_t );
int32_t write( int16_t, uint8_t *, int32_t );
int32_t read( int16_t, uint8_t *, int32_t );
//int16_t control( int16_t, USB_CTRLCODE_t, void * );
int16_t control( int16_t, CTLCODE, void * );
/* USB API (Host) */
uint16_t    R_usb_hstd_allocatePipe(USB_UTR_t *ptr, uint16_t type);
void        R_usb_hstd_freePipe(USB_UTR_t *ptr, uint8_t pipeno);
USB_ER_t    R_usb_hstd_EnumGetDescriptor(USB_UTR_t *ptr, uint8_t addr, uint8_t cnt_value, USB_CB_t complete);
USB_ER_t    R_usb_hstd_MgrEnumSetConfiguration(USB_UTR_t *ptr, uint8_t devadr, uint8_t config_val, USB_CB_t complete);
USB_ER_t    R_usb_hstd_TransferStart(USB_UTR_t *utr_table);
USB_ER_t    R_usb_hstd_SetPipeRegistration(USB_UTR_t *ptr, uint16_t *table, uint16_t pipe);
USB_ER_t    R_usb_hstd_TransferEnd(USB_UTR_t *ptr, uint16_t pipe, uint16_t status);
USB_ER_t    R_usb_hstd_ChangeDeviceState(USB_UTR_t *ptr, USB_CB_INFO_t complete, uint16_t msginfo, uint16_t rootport);
USB_ER_t    R_usb_hstd_MgrOpen(USB_UTR_t *ptr);
USB_ER_t    R_usb_hstd_MgrClose(void);
void        R_usb_hstd_DriverRegistration(USB_UTR_t *ptr, USB_HCDREG_t *callback);
void        R_usb_hstd_DriverRelease(USB_UTR_t *ptr, uint8_t devclass);
uint16_t    R_usb_hstd_ChkPipeInfo(uint16_t speed, uint16_t *EpTbl, uint8_t *Descriptor);
void        R_usb_hstd_SetPipeInfo(uint16_t *EpTbl, uint16_t *TmpTbl, uint16_t length);
void        R_usb_hstd_DeviceInformation(USB_UTR_t *ptr, uint16_t addr, uint16_t *tbl);
USB_ER_t    R_usb_hstd_MgrChangeDeviceState(USB_UTR_t *ptr, USB_CB_t complete, uint16_t msginfo, uint16_t devaddr);
void        R_usb_hstd_ReturnEnuMGR(USB_UTR_t *ptr, uint16_t cls_result);
void        R_usb_hstd_EnuWait(USB_UTR_t *ptr, uint8_t taskID);
uint16_t    R_usb_hstd_DetachControl(uint16_t port);
void        R_usb_hstd_usbdriver_start( USB_UTR_t *ptr );

USB_ER_t    R_usb_hstd_HcdOpen(USB_UTR_t *ptr);
USB_ER_t    R_usb_hstd_HcdClose(void);

/* USB API (Peripheral) */
uint16_t    R_usb_pstd_ControlRead(USB_UTR_t *ptr, uint32_t Bsize, uint8_t *Table);
void        R_usb_pstd_ControlWrite(USB_UTR_t *ptr, uint32_t Bsize, uint8_t *Table);
void        R_usb_pstd_ControlEnd(USB_UTR_t *ptr, uint16_t status);
USB_ER_t    R_usb_pstd_PcdOpen(USB_UTR_t *ptr);
USB_ER_t    R_usb_pstd_PcdClose(USB_UTR_t *ptr);
USB_ER_t    R_usb_pstd_TransferStart(USB_UTR_t *ptr);
USB_ER_t    R_usb_pstd_TransferEnd(USB_UTR_t *ptr, uint16_t pipe, uint16_t status);
USB_ER_t    R_usb_pstd_PcdChangeDeviceState(USB_UTR_t *ptr, uint16_t state, uint16_t port_no, USB_CB_INFO_t complete);
void        R_usb_pstd_DeviceInformation(USB_UTR_t *ptr, uint16_t *tbl);
void        R_usb_pstd_DriverRegistration(USB_UTR_t *ptr, USB_PCDREG_t *callback);
void        R_usb_pstd_DriverRelease(void);
void        R_usb_pstd_SetPipeRegister(USB_UTR_t *ptr, uint16_t PipeNo, uint16_t *tbl);
void        R_usb_pstd_SetPipeStall(USB_UTR_t *ptr, uint16_t pipeno);
void        R_usb_pstd_usbdriver_start( USB_UTR_t *ptr );

/* USB API (Other) */
void        R_usb_cstd_ClearHwFunction(USB_UTR_t *ptr);
void        R_usb_cstd_UsbIpInit( USB_UTR_t *ptr, uint16_t usb_mode );
uint8_t     R_usb_cstd_CheckSchedule(void);
void        R_usb_ScheInit( void );
USB_REGADR_t    R_usb_cstd_GetUsbIpAdr( uint16_t ipno );
void        R_usb_cstd_UsbIpInit( USB_UTR_t *ptr, uint16_t usb_mode );
void        R_usb_cstd_SetRegDvstctr0( USB_UTR_t *ptr, uint16_t val );
void        R_usb_cstd_SetRegPipeCtr( USB_UTR_t *ptr, uint16_t pipeno, uint16_t val );



void        R_usb_hhub_Open(USB_UTR_t *ptr, uint16_t devaddr, uint16_t data2);
void        R_usb_hhub_Close(USB_UTR_t *ptr, uint16_t hubaddr, uint16_t data2);
void        R_usb_hhub_Registration(USB_UTR_t *ptr, USB_HCDREG_t *callback);
USB_ER_t    R_usb_hhub_ChangeDeviceState(USB_UTR_t *ptr, USB_CB_t complete, uint16_t msginfo, uint16_t devaddr);
uint16_t    R_usb_hhub_GetHubInformation(USB_UTR_t *ptr, uint16_t hubaddr, USB_CB_t complete);
uint16_t    R_usb_hhub_GetPortInformation(USB_UTR_t *ptr, uint16_t hubaddr, uint16_t port, USB_CB_t complete);

uint16_t    R_usb_hhub_get_hub_addr(USB_UTR_t *ptr, uint16_t devadr);
uint16_t    R_usb_hhub_get_hub_port_no(USB_UTR_t *ptr, uint16_t devadr);
uint16_t    R_usb_hhub_chk_connect_status(USB_UTR_t *ptr, uint16_t hub_adr);

void        R_usb_pstd_PcdTask(USB_VP_INT_t);
void        R_usb_hhub_Task(USB_VP_INT_t);
void        R_usb_hstd_MgrTask(USB_VP_INT_t);
void        R_usb_hstd_HcdTask(USB_VP_INT_t);
void        R_usb_cstd_IdleTask(USB_VP_INT stacd);
void        R_usb_hstd_HubRegistAll(USB_UTR_t *ptr);

/* for NonOS Scheduler */
USB_ER_t    R_usb_cstd_RecMsg( uint8_t id, USB_MSG_t** mess, USB_TM_t tm );
USB_ER_t    R_usb_cstd_SndMsg( uint8_t id, USB_MSG_t* mess );
USB_ER_t    R_usb_cstd_iSndMsg( uint8_t id, USB_MSG_t* mess );
USB_ER_t    R_usb_cstd_PgetBlk( uint8_t id, USB_UTR_t** blk );
USB_ER_t    R_usb_cstd_RelBlk( uint8_t id,  USB_UTR_t* blk );
void        R_usb_cstd_Scheduler(void);
void        R_usb_cstd_SetTaskPri(uint8_t tasknum, uint8_t pri);


#endif  /* __R_USB_API_H__ */

#ifndef __R_USB_CLASS_FUSRCFG_H__
#define __R_USB_CLASS_FUSRCFG_H__

/*****************************************************************************
Macro definitions (DEVICE CLASS DEFINE)
******************************************************************************/

#define USB_DEVICE_CLASS_VENDOR     0xff
#define USB_DEVICE_CLASS_HOST_CDC   0x02    
#define USB_DEVICE_CLASS_HOST_HID   0x03
#define USB_DEVICE_CLASS_HOST_MSC   0x08
#define USB_DEVICE_CLASS_PERI_CDC   0x82
#define USB_DEVICE_CLASS_PERI_HID   0x83
#define USB_DEVICE_CLASS_PERI_MSC   0x88

/* Select Device class  */
#define USB_DEVICE_CLASS_PP     USB_DEVICE_CLASS_PERI_CDC

#endif  /* __R_USB_CLASS_FUSRCFG_H__ */


#ifndef __R_USB_PCDC_EXTERN_H__
#define __R_USB_PCDC_EXTERN_H__


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#ifndef __R_USB_PCDC_DEFINE_H__
#define __R_USB_PCDC_DEFINE_H__

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
//#include "r_usb_cTypedef.h"         /* Type define */


/*****************************************************************************
Macro definitions
******************************************************************************/
/* CDC Class Requests IDs*/
#define USB_PCDC_SET_LINE_CODING            0x2000
#define USB_PCDC_GET_LINE_CODING            0x2100
#define USB_PCDC_SET_CONTROL_LINE_STATE 0x2200
#define USB_PCDC_SEND_BREAK             0x2300

/* Class-Specific Configuration Descriptors */
#define     USB_PCDC_CS_INTERFACE                               0x24

/* bDescriptor SubType in Communications Class Functional Descriptors */
/* Header Functional Descriptor */
#define     USB_PCDC_DT_SUBTYPE_HEADER_FUNC                 0x00
/* Call Management Functional Descriptor. */
#define     USB_PCDC_DT_SUBTYPE_CALL_MANAGE_FUNC                0x01
/* Abstract Control Management Functional Descriptor. */
#define     USB_PCDC_DT_SUBTYPE_ABSTRACT_CTR_MANAGE_FUNC        0x02
/* Union Functional Descriptor */
#define     USB_PCDC_DT_SUBTYPE_UNION_FUNC                      0x06

/* Communications Class Subclass Codes */
#define     USB_PCDC_CLASS_SUBCLASS_CODE_ABS_CTR_MDL            0x02

/* USB Class Definitions for Communications Devices Specification 
   release number in binary-coded decimal. */
#define     USB_PCDC_BCD_CDC                                    0x0110

/* GET_LINE_CODING request wLength */
#define     USB_PCDC_GET_LINE_CODING_LENGTH                 0x07

/* Descriptor length */
#define USB_PCDC_DD_BLENGTH     18
#define USB_PCDC_QD_BLENGTH     10
#define USB_PCDC_CD1_BLENGTH        67
#define USB_PCDC_SD0_BLENGTH        4
#define USB_PCDC_SD1_BLENGTH        16
#define USB_PCDC_SD2_BLENGTH        44
#define USB_PCDC_SD3_BLENGTH        46
#define USB_PCDC_SD4_BLENGTH        22
#define USB_PCDC_SD5_BLENGTH        18
#define USB_PCDC_SD6_BLENGTH        28

/*****************************************************************************
Enumerated Types
******************************************************************************/
/* USB Communications Devices Device Class Phase. */
enum usb_gpcdc_Phase
{
    /* Class Request SET_LINE_CODING */
    USB_PCDC_PSET_LINE_CODING               = 0x10,
    /* Class Request GET_LINE_CODING */
    USB_PCDC_PGET_LINE_CODING               = 0x11,
    /* Class Request SET_CONTROL_LINE_STATE */
    USB_PCDC_PSET_CONTROL_LINE_STATE        = 0x12,
    /* Class Request SEND_BREAK */
    USB_PCDC_PSEND_BREAK                    = 0x13,
    /* Send Data ( Device to Host ) */
    USB_PCDC_PDATASND                       = 0x14,
    /* Receive Data ( Host to Device ) */
    USB_PCDC_PDATARCV                       = 0x15,
    /* Data send request for USB Host */
    USB_PCDC_PSEND_DATA                 = 0x17,
    /* Data receive request for USB Host */
    USB_PCDC_PRECEIVE_DATA                  = 0x18,
    /* Class Notification Serial State */
    USB_PCDC_PSERIAL_STATE_NOTIFICATION = 0x19,
    /* Send Serial Status ( Device to Host ) */
    USB_PCDC_PSTATUSSND                 = 0x20,
};

/******************************************************************************
Typedef definitions
******************************************************************************/
typedef struct
{
    /* Data terminal rate, in bits per second */
    uint32_t                    dwDTERate;
    /* Stop bits */
    uint8_t                     bCharFormat;
    /* Parity */
    uint8_t                     bParityType;
    /* Data bits */
    uint8_t                     bDataBits;
    /* reserve */
    uint8_t                     rsv;
}
USB_PCDC_LineCoding_t;

typedef struct
{
    /* reserve */
    uint16_t                    rsv:14;
    /* RTS */
    uint16_t                    bRTS:1;
    /* DTR */
    uint16_t                    bDTR:1;
}
USB_PCDC_ControlLineState_t;

#endif  /* __R_USB_PCDC_DEFINE_H__ */

/*****************************************************************************
Macro definitions
******************************************************************************/


/*****************************************************************************
Enumerated Types
******************************************************************************/


/******************************************************************************
Typedef definitions
******************************************************************************/


/******************************************************************************
External variables and functions
******************************************************************************/

extern uint16_t         *usb_gpcdc_EpPtr[];
extern uint16_t         usb_gpcdc_EpTbl1[];
extern uint16_t         usb_gpcdc_EpTbl2[];
extern uint16_t         usb_gpcdc_EpTbl3[];
extern uint16_t         usb_gpcdc_EpTbl4[];
extern uint16_t         usb_gpcdc_EpTbl5[];
extern uint8_t          *usb_gpcdc_ConPtr[];
extern uint8_t          *usb_gpcdc_ConPtrOther[];
extern uint8_t          *usb_gpcdc_StrPtr[];
extern uint8_t          usb_gpcdc_ConfigrationF1[];
extern uint8_t          usb_gpcdc_ConfigrationH1[];
extern uint8_t          usb_gpcdc_DeviceDescriptor[];
extern uint8_t          usb_gpcdc_QualifierDescriptor[];
extern uint8_t          usb_gpcdc_StringDescriptor0[];
extern uint8_t          usb_gpcdc_StringDescriptor1[];
extern uint8_t          usb_gpcdc_StringDescriptor2[];
extern uint8_t          usb_gpcdc_StringDescriptor3[];
extern uint8_t          usb_gpcdc_StringDescriptor4[];
extern uint8_t          usb_gpcdc_StringDescriptor5[];
extern uint8_t          usb_gpcdc_StringDescriptor6[];
extern USB_UTR_t        usb_gpcdc_Mess[];

/* Line Coding data */
extern USB_PCDC_LineCoding_t    usb_gcdc_LineCoding;
/* Line Coding Set Request data */
extern USB_PCDC_LineCoding_t    usb_gcdc_LineCodingReq;

#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
extern uint16_t         usb_gpcdc_Inpipe;
extern uint16_t         usb_gpcdc_Outpipe;
extern uint16_t         usb_gpcdc_Status_pipe;

#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */

USB_ER_t    usb_pcdc_close(USB_UTR_t *ptr, uint16_t data1, uint16_t data2);
USB_ER_t    usb_pcdc_open(USB_UTR_t *ptr, uint16_t data1, uint16_t data2);
void        usb_pcdc_ControlTrans0(USB_UTR_t *ptr, USB_REQUEST_t *req);
void        usb_pcdc_ControlTrans1(USB_UTR_t *ptr, USB_REQUEST_t *req);
void        usb_pcdc_ControlTrans2(USB_UTR_t *ptr, USB_REQUEST_t *req);
void        usb_pcdc_ControlTrans3(USB_UTR_t *ptr, USB_REQUEST_t *req);
void        usb_pcdc_ControlTrans4(USB_UTR_t *ptr, USB_REQUEST_t *req);
void        usb_pcdc_ControlTrans5(USB_UTR_t *ptr, USB_REQUEST_t *req);
void        usb_pcdc_DataTrans(USB_UTR_t *ptr, uint16_t Pipe, uint32_t Size, uint8_t *Table, USB_CB_t complete);
void        usb_pcdc_StatusTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);
void        usb_pcdc_task(USB_VP_INT_t);


void        usb_pcdc_SetControlLineState_req(USB_UTR_t *ptr);
void        usb_pcdc_SetLineCoding_req(USB_UTR_t *ptr);
void        usb_pcdc_GetLineCoding_req(USB_UTR_t *ptr);
void        usb_pcdc_SendBreak_req(USB_UTR_t *ptr);
uint16_t    usb_pcdc_is_connected(void);

void        usb_pcdc_SetControlLineState(USB_UTR_t *ptr, USB_CB_INFO_t complete);
void        usb_pcdc_SetLineCoding(USB_UTR_t *ptr, USB_CB_INFO_t complete);
void        usb_pcdc_GetLineCoding(USB_UTR_t *ptr, USB_CB_INFO_t complete);
void        usb_pcdc_SendBreak(USB_UTR_t *ptr, USB_CB_INFO_t complete);

void        usb_pcdc_StatusTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);
void        usb_pcdc_InTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);
void        usb_pcdc_OutTransResult(USB_UTR_t *mess, uint16_t data1, uint16_t data2);

#endif  /* __R_USB_PCDC_EXTERN_H__ */


#ifndef __HW_RESOURCE_H__
#define __HW_RESOURCE_H__

/******************************************************************************
Constant macro definitions
******************************************************************************/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    RSK USE IO SELECT
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//#define     USB_LCD_ENABLE
//#define     USB_LED_ENABLE
//#define     USB_KEY_ENABLE
//#define     USB_UART_ENABLE
//#define     USB_ADC_ENABLE

/******************************************************************************
Macro definitions
******************************************************************************/
/* LCD DEFINE */
#define     LCD_MAXCHARA    8
#define     LCD_POS_U0      0
#define     LCD_POS_U1      1
#define     LCD_POS_U2      2
#define     LCD_POS_U3      3
#define     LCD_POS_U4      4
#define     LCD_POS_U5      5
#define     LCD_POS_U6      6
#define     LCD_POS_U7      7
#define     LCD_POS_D0      LCD_POS_U0+LCD_MAXCHARA
#define     LCD_POS_D1      LCD_POS_U1+LCD_MAXCHARA
#define     LCD_POS_D2      LCD_POS_U2+LCD_MAXCHARA
#define     LCD_POS_D3      LCD_POS_U3+LCD_MAXCHARA
#define     LCD_POS_D4      LCD_POS_U4+LCD_MAXCHARA
#define     LCD_POS_D5      LCD_POS_U5+LCD_MAXCHARA
#define     LCD_POS_D6      LCD_POS_U6+LCD_MAXCHARA
#define     LCD_POS_D7      LCD_POS_U7+LCD_MAXCHARA

#endif  /* __HW_RESOURCE_H__ */





#ifndef __R_USB_PCDC_API_H__
#define __R_USB_PCDC_API_H__

/*****************************************************************************
Public Functions (API)
******************************************************************************/
void R_usb_pcdc_task(USB_VP_INT_t stacd);
void R_usb_pcdc_set_interface(USB_UTR_t *ptr, uint16_t data1, uint16_t data2);
void R_usb_pcdc_descriptor_change(USB_UTR_t *ptr, uint16_t mode, uint16_t data2);
void R_usb_pcdc_SendData(USB_UTR_t *ptr, uint8_t *Table, uint32_t size, USB_CB_t complete);
void R_usb_pcdc_ReceiveData(USB_UTR_t *ptr, uint8_t *Table, uint32_t size, USB_CB_t complete);
void R_usb_pcdc_SerialStateNotification(USB_UTR_t *ptr, uint16_t serial_state, USB_CB_t complete);
void R_usb_pcdc_driver_start( void );
void R_usb_pcdc_usr_ctrl_trans_function(USB_UTR_t *ptr, USB_REQUEST_t *preq, uint16_t ctsq);

#endif  /* __R_USB_PCDC_API_H__ */


#ifndef __RX_MCU_H__
#define __RX_MCU_H__

/******************************************************************************
Constant macro definitions
******************************************************************************/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    USB port macro define
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    USB interrupt macro define
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define USB0_D0FIFO_NUM         33
#define USB0_D1FIFO_NUM         34
#define USB0_D0FIFO_IER         ICU.IER[0x04].BIT.IEN1
#define USB0_D1FIFO_IER         ICU.IER[0x04].BIT.IEN2
#define USB0_USBIO_IER          ICU.IER[0x04].BIT.IEN3
#define USB0_USBR_IER           ICU.IER[0x0B].BIT.IEN2
#define USB0_D0FIFO_IPR         ICU.IPR[USB0_D0FIFO_NUM].BYTE
#define USB0_D1FIFO_IPR         ICU.IPR[USB0_D1FIFO_NUM].BYTE
#define USB0_USBIO_IPR          ICU.IPR[35].BYTE
#define USB0_USBR_IPR           ICU.IPR[90].BYTE

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    USB interrupt macro define
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define USB_PSEL11          0x11

/* VBUS(PE5) */
    #define USB0_VBUS_PDR       PORTE.PDR.BIT.B5
    #define USB0_VBUS_PMR       PORTE.PMR.BIT.B5
    #define USB0_VBUS_PFS       MPC.PE5PFS.BYTE
    #define USB0_VBUS_ENB       USB_PSEL11
/* OVRCURB(PE0) */
    #define USB0_OVRCURB_PDR    PORTE.PDR.BIT.B0
    #define USB0_OVRCURB_PMR    PORTE.PMR.BIT.B0
    #define USB0_OVRCURB_PFS    MPC.PE0PFS.BYTE
    #define USB0_OVRCURB_ENB    USB_PSEL11                  /* PE0PFS = 0x11 */
/* OVRCURA(PE1) */
    #define USB0_OVRCURA_PDR    PORTE.PDR.BIT.B1
    #define USB0_OVRCURA_PMR    PORTE.PMR.BIT.B1
    #define USB0_OVRCURA_PFS    MPC.PE1PFS.BYTE
    #define USB0_OVRCURA_ENB    USB_PSEL11                  /* PE1PFS = 0x11 */
/* DRPD(P01) */
    #define USB0_DRPD_PDR       PORT0.PDR.BIT.B1
    #define USB0_DRPD_PMR       PORT0.PMR.BIT.B1
    #define USB0_DRPD_PFS       MPC.P01PFS.BYTE
    #define USB0_DRPD_ENB       USB_PSEL11
/* DPRPD(P12) */
    #define USB0_DPRPD_PDR      PORT1.PDR.BIT.B2
    #define USB0_DPRPD_PMR      PORT1.PMR.BIT.B2
    #define USB0_DPRPD_PFS      MPC.P12PFS.BYTE
    #define USB0_DPRPD_ENB      USB_PSEL11
/* ID(PD2) */
    #define USB0_ID_PDR         PORTD.PDR.BIT.B2
    #define USB0_ID_PMR         PORTD.PMR.BIT.B2
    #define USB0_ID_PFS         MPC.PD2PFS.BYTE
    #define USB0_ID_ENB         USB_PSEL11
/* EXICEN(PD1) */
    #define USB0_EXICEN_PDR     PORTD.PDR.BIT.B1
    #define USB0_EXICEN_PMR     PORTD.PMR.BIT.B1
    #define USB0_EXICEN_PFS     MPC.PD1PFS.BYTE
    #define USB0_EXICEN_ENB     USB_PSEL11
/* USB0 DPUPE(UDPUPEPFS) */
    #define USB0_DPRPU_PFS      MPC.UDPUPEPFS.BYTE
    #define USB0_DPRPU_ENB      USB_PSEL11
/* VBUSEN(P13) */
    #define USB0_VBUSEN_PDR     PORT1.PDR.BIT.B3
    #define USB0_VBUSEN_PMR     PORT1.PMR.BIT.B3
    #define USB0_VBUSEN_PFS     MPC.P13PFS.BYTE
    #define USB0_VBUSEN_ENB     USB_PSEL11
#endif  /* __RX_MCU_H__ */


#ifndef __RX_RSK_EXTERN_H__
#define __RX_RSK_EXTERN_H__

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
//#include "r_usb_ctypedef.h"     /* Type define */


/******************************************************************************
External variables and functions
******************************************************************************/
/* SW input driver functions */
extern uint16_t     usb_cpu_GetKeyNo(void);
extern void         usb_cpu_AcquisitionKeyNo(void);
extern uint8_t      usb_cpu_KeepKeyNo(void);
extern uint8_t      usb_cpu_SingleKeyNo(void);

/* AD driver functions */
extern void         usb_cpu_AdInit(void);
extern uint32_t     usb_cpu_AdData(void);

/* LED driver functions */
extern void         usb_cpu_LedInit(void);
extern void         usb_cpu_LedSetBit(uint8_t bit, uint8_t data);

/* Serial Port driver functions */
extern uint16_t     usb_cpu_Sci_Set1(uint8_t *data_rate_top, uint8_t stop_bit, uint8_t parity, uint8_t data_bit);
extern void         usb_cpu_Sci_DataSend(uint16_t mode, void *tranadr, uint16_t length);
extern uint16_t     usb_cpu_Sci_DataReceive(uint8_t *tranadr, uint16_t receive_length);
extern uint16_t     usb_cpu_Sci_StxBuffStatus(void);
extern void         usb_cpu_Sci_Buffer_init(void);
extern void         usb_cpu_Sci_HW_init(void);
extern void         usb_cpu_Sci_enable(void);
extern void         usb_cpu_Sci_disable(void);
extern uint16_t     usb_cpu_Sci_CopyData_for_Echo(void);
extern uint16_t     usb_cpu_Sci_GetSerialState(uint16_t *serial_state);
extern uint16_t     usb_cpu_Sci_EnableStatus(void);
extern uint16_t     usb_cpu_Sci_SetDataChk(uint8_t *data_rate_top, uint8_t stop_bit, uint8_t parity, uint8_t data_bit);

#endif  /* __RX_RSK_EXTERN_H__ */

#endif  /* __R_USB_CTYPEDEF_H__ */

// combine ED&USB, Sean, 20140819
void USB_vdTxHandler(void);
void USB_vdRxDecoder(void);
void USB_vdMonitor_Sample(void);
void usb_pcdc_task_start(void);      
void usb_apl_task_switch(void);     
void USB_vdIniClk(void);
void USB_vdIniVar(void);
uint16_t USB_vdCRCGen(uint8_t* ubDat, uint8_t ubCnt);	// add CRC/LRC functions, Sean, 20141030
uint8_t USB_vdLRCGen(uint8_t* ubDat, uint8_t ubLen);	// add CRC/LRC functions, Sean, 20141030
void USB_vdIniTx(uint8_t flg);							// RxDecoder for multi-protocol, Sean, 20141030
uint16_t USB_uwBytChg(uint16_t uwTmp);

/******************************************************************************
End  Of File
******************************************************************************/
