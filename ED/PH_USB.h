#ifdef _PH_USB_C
   #define PH_USB_EXT 
#else
   #define PH_USB_EXT extern
#endif
/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>
//#include "r_usb_usrconfig.h"
//#include "r_usb_citron.h"
#if 0

/******************************************************************************
Typedef definitions
******************************************************************************/
typedef struct st_usb       USB_STNBYINT_t;

typedef void (*USB_CB_CHECK_t)(struct USB_UTR *, UWORD**);
typedef void (*USB_CB_t)(struct USB_UTR *, UWORD, UWORD);
typedef void (*USB_CB_INFO_t)(struct USB_UTR *, UWORD, UWORD);
typedef void (*USB_CB_MSG_t)(UWORD, UBYTE*);
typedef void (*USB_CB_REQ_t)(void *);

//#if USB_TARGET_CHIP_PP == USB_ASSP_PP
//typedef struct  USB_REGISTER*   USB_REGADR_t;
//#else
//typedef volatile struct st_usb0 __evenaccess*   USB_REGADR_t;
//#endif

typedef struct
{
    UWORD        ReqType;            /* Request type */
    UWORD        ReqTypeType;        /* Request type TYPE */
    UWORD        ReqTypeRecip;       /* Request type RECIPIENT */
    UWORD        ReqRequest;         /* Request */
    UWORD        ReqValue;           /* Value */
    UWORD        ReqIndex;           /* Index */
    UWORD        ReqLength;          /* Length */
} USB_REQUEST_t;

typedef struct USB_HCDREG
{
    UWORD        rootport;       /* Root port */
    UWORD        devaddr;        /* Device address */
    UWORD        devstate;       /* Device state */
    UWORD        ifclass;        /* Interface Class */
    UWORD        *tpl;           /* Target peripheral list 
                                        (Vendor ID, Product ID) */
    UWORD        *pipetbl;       /* Pipe Define Table address */
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
    UWORD        msginfo;        /* Message Info for F/W */
    UWORD        keyword;        /* Rootport / Device address / Pipe number */
    USB_REGADR_t    ipp;            /* IP Address(USB0orUSB1)*/
    UWORD        ip;             /* IP number(0or1) */
    UWORD        result;         /* Result */
    USB_CB_t        complete;       /* Call Back Function Info */
    void            *tranadr;       /* Transfer data Start address */
    ULONG        tranlen;        /* Transfer data length */
    UWORD        *setup;         /* Setup packet(for control only) */
    UWORD        status;         /* Status */
    UWORD        pipectr;        /* Pipe control register */
    UBYTE         errcnt;         /* Error count */
    UBYTE         segment;        /* Last flag */
    UWORD         fn;             /* File Number */
    void            *usr_data;      
} USB_UTR_t;

/* Class request processing function type. */
typedef void (*USB_CB_TRN_t)(USB_UTR_t *, USB_REQUEST_t*, UWORD ctsq);

typedef struct USB_PCDREG
{
    UWORD        **pipetbl;      /* Pipe Define Table address */
    UBYTE         *devicetbl;     /* Device descriptor Table address */
    UBYTE         *qualitbl;      /* Qualifier descriptor Table address */
    UBYTE         **configtbl;    /* Configuration descriptor
                                        Table address */
    UBYTE         **othertbl;     /* Other configuration descriptor
                                        Table address */
    UBYTE         **stringtbl;    /* String descriptor Table address */
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
    UBYTE         isOpened;
    UBYTE         usb_ip;
    USB_REGADR_t    usb_ipp;            /* IP Address(USB0orUSB1)*/
    UBYTE         devno;
    UBYTE         inPipeNo;
    UBYTE         outPipeNo;
    ULONG         (*class_read)( UWORD, void *, ULONG );
    ULONG         (*class_write)( UWORD , void *, ULONG );
    UWORD        (*close_func)( UWORD );

    USB_CB_t        read_complete;      /* Call Back Function Info */
    USB_CB_t        write_complete;     /* Call Back Function Info */
    ULONG         read_length;        /* Transfer data length */
    ULONG         write_length;       /* Transfer data length */
//  uint16_t        *class_control();
    UWORD         open_state;         /* Open status */
    UWORD         read_state;         /* read status */
    UWORD         write_state;        /* write status */
} USB_FNINFO_t;

struct usb_devinfo 
{
    UBYTE         devadr;
    UBYTE         speed;
    UBYTE         isTPL;
    UBYTE         interfaceClass;
    UBYTE         isActDev;
    USB_UTR_t       *ptr;
};

//#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
//typedef struct usb_open_parametor
//{
    //USB_FNINFO_t *p_fnstr;
    //UBYTE devadr;
    //UBYTE speed;
    //UWORD class;
//} USB_OPEN_PARM_t;
//#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

/*****************************************************************************
Macro definitions
******************************************************************************/
#define USB_NONE            (UWORD)(0)
#define USB_YES             (UWORD)(1)
#define USB_NO              (UWORD)(0)
#define USB_DONE            (UWORD)(0)
#define USB_ERROR           (UWORD)(0xFFFF)
#define USB_OK              (UWORD)(0)
#define USB_NG              (UWORD)(0xFFFF)
#define USB_ON              (UWORD)(1)
#define USB_OFF             (UWORD)(0)
#define USB_OTG_DONE        (UWORD)(2)
#define USB_NOT_USED        (UWORD)(0)


/******************************************************************************
Private global variables and functions              r_usb_cscheduler.c
******************************************************************************/
/* Priority Table */
PH_USB_EXT USB_MSG_t*   usb_scstd_TableAdd[USB_PRIMAX][USB_TABLEMAX];
PH_USB_EXT UBYTE      usb_scstd_TableID[USB_PRIMAX][USB_TABLEMAX];
PH_USB_EXT UBYTE      usb_scstd_PriR[USB_PRIMAX];
PH_USB_EXT UBYTE      usb_scstd_PriW[USB_PRIMAX];
PH_USB_EXT UBYTE      usb_scstd_Pri[USB_IDMAX];

/* Schedule Set Flag  */
PH_USB_EXT UBYTE      usb_scstd_ScheduleFlag;

/* Fixed-sized memory pools */
PH_USB_EXT USB_UTR_t    usb_scstd_Block[USB_BLKMAX];
PH_USB_EXT UBYTE      usb_scstd_BlkFlg[USB_BLKMAX];

PH_USB_EXT USB_MSG_t*   usb_scstd_Add_use;
PH_USB_EXT UBYTE      usb_scstd_ID_use;

/* Wait MSG */
PH_USB_EXT USB_MSG_t*   usb_scstd_WaitAdd[USB_IDMAX];
PH_USB_EXT UWORD     usb_scstd_WaitCounter[USB_IDMAX];


/* Please set with user system */          // r_usb_ckernelid.h
#define USB_IDMAX           11u                 /* Maximum Task ID +1 */
#define USB_PRIMAX          8u                  /* Maximum Priority number +1 */
#define USB_BLKMAX          20u                 /* Maximum block */
#define USB_TABLEMAX        USB_BLKMAX          /* Maximum priority table */




/*****************************************************************************
Typedef definitions                     r_usb_cItron.h
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
#define USB_VP_INT      VP_INT



/*****************************************************************************
Macro definitions
******************************************************************************/
/* Scheduler use define */
#define USB_TBLCLR          0u                  /* Table clear */
#define USB_CNTCLR          0u                  /* Counter clear */
#define USB_FLGCLR          0u                  /* Flag clear */
#define USB_FLGSET          1u                  /* Flag set */
#define USB_IDCLR           0xFFu               /* Priority clear */


PH_USB_EXT void usb_cstd_main_task(USB_VP_INT);
PH_USB_EXT void usb_cpu_SdramInit(void);



/* Peri CDC application enable */
PH_USB_EXT UBYTE usb_gcdc_connected;

PH_USB_EXT void   usb_pcdc_main_task(USB_VP_INT_t);
PH_USB_EXT UBYTE  usb_pcdc_is_connected(void);
//PH_USB_EXT void   usb_pcdc_pr_apl_title(void);

/******************************************************************************
Static variables and functions
******************************************************************************/
//#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
//PH_USB_EXT  UWORD usb_spcdc_data_fn;
//PH_USB_EXT  UWORD usb_spcdc_ctl_fn;
//#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
PH_USB_EXT  UWORD usb_pcdc_get_rcv_data_cnt(USB_UTR_t *mess);
//#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

PH_USB_EXT  void    usb_pcdc_rx_notification(USB_UTR_t *mess);
PH_USB_EXT  void    usb_pcdc_tx_notification(USB_UTR_t *mess);
PH_USB_EXT  void    usb_pcdc_state_notification(USB_UTR_t *mess);
PH_USB_EXT  void    usb_pcdc_apl_msg_out(USB_UTR_t *ptr, UWORD message_no);
PH_USB_EXT  void    usb_pcdc_apl_init(USB_UTR_t *ptr);
PH_USB_EXT  void    usb_pcdc_smpl_message_send( USB_UTR_t *ptr, UWORD msginfo);

PH_USB_EXT  void    usb_apl_task_switch(void);
PH_USB_EXT  void    usb_pcdc_task_start( void );
PH_USB_EXT  void    usb_papl_task_start( USB_UTR_t *ptr );
PH_USB_EXT  void    usb_pcdc_registration(USB_UTR_t *ptr);
/* USB TX Data */
PH_USB_EXT  UBYTE     usb_gpcdc_send_data[USB_PCDC_APL_SRX_SIZE + 4];
/* USB RX Data */
PH_USB_EXT  UBYTE     usb_gpcdc_receive_data[USB_PCDC_APL_RX_SIZE + 4];
/* Instructions output line sequence */
PH_USB_EXT  UWORD    usb_gpcdc_explain_seq;
/* HOST Send wait flag */
PH_USB_EXT  UWORD    usb_gpcdc_tx_wait_flag;
/* Notification Serial State sending flag */
PH_USB_EXT  UWORD    usb_gpcdc_serial_state_tx;
/* Notification Serial State sending status */
PH_USB_EXT  UWORD    usb_gpcdc_serial_state;

/* echo mode flag */
PH_USB_EXT  UWORD    usb_gpcdc_echo_mode;
PH_USB_EXT  UWORD    usb_gpcdc_sw2push;
/* Switch1 Push Request Message Output Timing Counter */
PH_USB_EXT  ULONG    usb_gpcdc_msg_timing_cnt;
/* Receive flow control flag */
PH_USB_EXT  UWORD    usb_gpcdc_stx_wait;
/* CDC Peripheral Active flag */
PH_USB_EXT  UWORD    usb_gpcdc_active;

/******************************************************************************
Section    <Section Difinition> , "Project Sections"
******************************************************************************/
#pragma section _apl

PH_USB_EXT UBYTE_UNION	 USB_status;

/******************************************************************************
Constant macro definitions
******************************************************************************/
#define     USB_PCDC_SW1_ON                     1
#define     USB_PCDC_SW2_ON                     2
#define     USB_PCDC_SW3_ON                     4

#define     USB_PCDC_MSG_TIMING                 41317

#define     USB_PCDC_APL_INST_SEQ_START         3
#define     USB_PCDC_APL_INST_SEQ_END           8

/* CDC Host data receive size */
/* FS:64 HS:512 */
/* Condition compilation by the difference of user define */

#define     USB_PCDC_APL_RX_SIZE                64

/* Comm Port data receive size */
#define USB_PCDC_APL_SRX_SIZE                   64

/* setup packet table size (uint16_t * 5) */
#define     USB_CDC_SETUP_TBL_BSIZE             10

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
}
USB_PCDC_APL_COMMAND;


/******************************************************************************
Private global variables and functions
******************************************************************************/
/* Abstract Control Model Notification - SerialState */
PH_USB_EXT UBYTE usb_gpcdc_SerialState_Table[USB_CDC_SETUP_TBL_BSIZE]
            = { 0xA1,           /* bmRequestType */
                0x20,           /* bNotification:SERIAL_STATE */
                0x00,0x00,      /* wValue:Zero */
                0x00,0x00,      /* wIndex:Interface */
                0x02,0x00,      /* wLength:2 */
                0x00,0x00 };    /* Data:UART State bitmap */


PH_USB_EXT void usb_cpu_usbint_init(void);
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

PH_USB_EXT void usb_cpu_FunctionUSB0IP(void);

#define USB_PSEL11          0x11
/* VBUS(PE5) */
#define USB0_VBUS_PDR       PORTE.PDR.BIT.B5
#define USB0_VBUS_PMR       PORTE.PMR.BIT.B5
#define USB0_VBUS_PFS       MPC.PE5PFS.BYTE
#define USB0_VBUS_ENB       USB_PSEL11

/* USB0 DPUPE(UDPUPEPFS) */
#define USB0_DPRPU_PFS      MPC.UDPUPEPFS.BYTE
#define USB0_DPRPU_ENB      USB_PSEL11

PH_USB_EXT void usb_cpu_DmaintInit(void);


USB_DTC_t   usb_dtcreg[2u];


ULONG usb_dtcctable[48] = 
{
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  0 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  1 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  2 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  3 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  4 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  5 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  6 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  7 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  8 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR  9 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 10 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 11 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 12 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 13 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 14 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 15 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 16 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 17 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 18 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 19 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 20 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 21 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 22 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 23 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 24 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 25 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 26 */
    (ULONG)0x00000000,       /* DTC VECTOR 27 (SWINT) */
    (ULONG)0x00000000,       /* DTC VECTOR 28 (CMT0) */
    (ULONG)0x00000000,       /* DTC VECTOR 29 (CMT1) */
    (ULONG)0x00000000,       /* DTC VECTOR 30 (CMT2) */
    (ULONG)0x00000000,       /* DTC VECTOR 31 (CMT3) */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 32 */
    (ULONG)&usb_dtcreg[0],   /* DTC VECTOR 33 (USB0-D0FIFO) */
    (ULONG)0x00000000,       /* DTC VECTOR 34 (USB0-D1FIFO) */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 35 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 36 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 37 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 38 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 39 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 40 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 41 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 42 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 43 */
    (ULONG)0xFFFFFFFF,       /* DTC VECTOR 44 */
    (ULONG)0x00000000,       /* DTC VECTOR 45 (SPRI0) */
    (ULONG)0x00000000,       /* DTC VECTOR 46 (SPTI1) */
    (ULONG)0xFFFFFFFF        /* DTC VECTOR 47 */
};


typedef struct
{
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
} USB_DTC_t;

PH_USB_EXT void usb_cstd_task_start( void );

#define USB_PERI_USBIP_NUM  USB_USBIP_0
#define USB_PERI_MODE_PP

#define USB_USBIP_0             (UWORD)0

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

typedef volatile struct st_usb0 __evenaccess*   USB_REGADR_t;

typedef struct USB_UTR
{
    USB_MH_t        msghead;        /* Message header (for SH-solution) */
    UWORD        msginfo;        /* Message Info for F/W */
    UWORD        keyword;        /* Rootport / Device address / Pipe number */
    USB_REGADR_t    ipp;            /* IP Address(USB0orUSB1)*/
    UWORD        ip;             /* IP number(0or1) */
    UWORD        result;         /* Result */
    USB_CB_t        complete;       /* Call Back Function Info */
    void            *tranadr;       /* Transfer data Start address */
    ULONG        tranlen;        /* Transfer data length */
    UWORD        *setup;         /* Setup packet(for control only) */
    UWORD        status;         /* Status */
    UWORD        pipectr;        /* Pipe control register */
    UBYTE         errcnt;         /* Error count */
    UBYTE         segment;        /* Last flag */
    UWORD         fn;             /* File Number */
    void            *usr_data;      
} USB_UTR_t;

UBYTE usb_gpcdc_EpTbl1[] =
{
    USB_PIPE1,
    USB_BULK | USB_BFREOFF | USB_DBLBON | USB_CNTMDOFF | USB_SHTNAKON
        | USB_DIR_P_IN | USB_EP1,
    (UBYTE)USB_BUF_SIZE(512u) | USB_BUF_NUMB(8u),
    USB_SOFT_CHANGE,
    USB_IFISOFF | USB_IITV_TIME(0u),
    USB_CUSE,

    USB_PIPE2,
    USB_BULK | USB_BFREOFF | USB_DBLBON | USB_CNTMDOFF | USB_SHTNAKON
        | USB_DIR_P_OUT | USB_EP2,
    (UBYTE)USB_BUF_SIZE(512u) | USB_BUF_NUMB(24u),
    USB_SOFT_CHANGE,
    USB_IFISOFF | USB_IITV_TIME(0u),
    USB_CUSE,

    USB_PIPE6,
    USB_INT  | USB_DIR_P_IN | USB_EP3,
    (UBYTE)USB_BUF_SIZE(64u) | USB_BUF_NUMB(4u),
    16u,
    USB_IITV_TIME(0u),
    USB_CUSE,

/* Pipe end */
    USB_PDTBLEND,
};

/* Configuration 2 */
UBYTE usb_gpcdc_EpTbl2[] =
{
    0
};
/* Configuration 3 */
UBYTE usb_gpcdc_EpTbl3[] =
{
    0
};
/* Configuration 4 */
UBYTE usb_gpcdc_EpTbl4[] =
{
    0
};
/* Configuration 5 */
UBYTE usb_gpcdc_EpTbl5[] =
{
    0
};

#define USB_BUF_SIZE(x)                     ((UBYTE)(((x) / 64u) - 1u) << 10u)
#define USB_BUF_NUMB(x)                     (x)


UWORD *usb_gpcdc_EpPtr[] =
{
    usb_gpcdc_EpTbl1,
    usb_gpcdc_EpTbl2,
    usb_gpcdc_EpTbl3,
    usb_gpcdc_EpTbl4,
    usb_gpcdc_EpTbl5
};

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

/******************************************************************************
Another define
******************************************************************************/
/* Descriptor index */
#define USB_DEV_MAX_PKT_SIZE                7u  /* Index of bMAXPacketSize */
#define USB_DEV_NUM_CONFIG                  17u /* Index of bNumConfigurations */
#define USB_ALT_NO                          255u
#define USB_SOFT_CHANGE                     0u

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

/* Pipe define table end code */
#define USB_PDTBLEND                        0xFFFFu /* End of table */


/* Device Qualifier Descriptor */
UBYTE usb_gpcdc_QualifierDescriptor
    [ USB_PCDC_QD_BLENGTH + ( USB_PCDC_QD_BLENGTH % 2 ) ] =
{
    /*  0:bLength */
    USB_PCDC_QD_BLENGTH,
    /*  1:bDescriptorType */
    USB_DT_DEVICE_QUALIFIER,
    /*  2:bcdUSB_lo */
    (USB_BCDNUM & (UBYTE)0xffu),
    /*  3:bcdUSB_hi */
    ((UBYTE)(USB_BCDNUM >> 8) & (UBYTE)0xffu),
    /*  4:bDeviceClass */
    0,
    /*  5:bDeviceSubClass */
    0,
    /*  6:bDeviceProtocol */
    0,
    /*  7:bMAXPacketSize(for DCP) */
    (UBYTE)USB_DCPMAXP,
    /*  8:bNumConfigurations */
    USB_CONFIGNUM,
    /*  9:bReserved */
    0
};

/******************************************************************************
Private global variables and functions
******************************************************************************/

/* Standard Device Descriptor */
UBYTE usb_gpcdc_DeviceDescriptor
    [ USB_PCDC_DD_BLENGTH + ( USB_PCDC_DD_BLENGTH % 2 ) ] =
{
    /*  0:bLength */
    USB_PCDC_DD_BLENGTH,
    /*  1:bDescriptorType */
    USB_DT_DEVICE,
    /*  2:bcdUSB_lo */
    (USB_BCDNUM                     & (UBYTE)0xffu),
    /*  3:bcdUSB_hi */
    ((UBYTE)(USB_BCDNUM >> 8)     & (UBYTE)0xffu),
    /*  4:bDeviceClass */
    USB_IFCLS_CDCC,
    /*  5:bDeviceSubClass */
    0,
    /*  6:bDeviceProtocol */
    0,
    /*  7:bMAXPacketSize(for DCP) */
    (UBYTE)USB_DCPMAXP,
    /*  8:idVendor_lo */
    (USB_VENDORID                   & (UBYTE)0xffu),
    /*  9:idVendor_hi */
    ((UBYTE)(USB_VENDORID >> 8)   & (UBYTE)0xffu),
    /* 10:idProduct_lo */
    ((UBYTE)USB_PRODUCTID        & (UBYTE)0xffu),
    /* 11:idProduct_hi */
    ((UBYTE)(USB_PRODUCTID >> 8)  & (UBYTE)0xffu),
    /* 12:bcdDevice_lo */
    (USB_RELEASE                    & (UBYTE)0xffu),
    /* 13:bcdDevice_hi */
    ((UBYTE)(USB_RELEASE >> 8)    & (UBYTE)0xffu),
    /* 14:iManufacturer */
    1,
    /* 15:iProduct */
    2,
    /* 16:iSerialNumber */
    6,
    /* 17:bNumConfigurations */
    USB_CONFIGNUM
};

/* Descriptor length */
#define USB_PCDC_DD_BLENGTH     18
#define USB_PCDC_QD_BLENGTH     10
#define USB_PCDC_CD1_BLENGTH    67
#define USB_PCDC_SD0_BLENGTH     4
#define USB_PCDC_SD1_BLENGTH    16
#define USB_PCDC_SD2_BLENGTH    44
#define USB_PCDC_SD3_BLENGTH    46
#define USB_PCDC_SD4_BLENGTH    22
#define USB_PCDC_SD5_BLENGTH    18
#define USB_PCDC_SD6_BLENGTH    28

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

/******************************************************************************
User define macro definitions
******************************************************************************/
#define USB_VENDORID    0x0000
#define USB_PRODUCTID   0x0002

/* Configuration */
UBYTE *usb_gpcdc_ConPtr[] =
{
    (UBYTE*)USB_SOFT_CHANGE
};

/* Other_Speed_Configuration */
UBYTE *usb_gpcdc_ConPtrOther[] =
{
    (UBYTE*)USB_SOFT_CHANGE
};

UBYTE *usb_gpcdc_StrPtr[USB_STRINGNUM] =
{
    usb_gpcdc_StringDescriptor0,
    usb_gpcdc_StringDescriptor1,
    usb_gpcdc_StringDescriptor2,
    usb_gpcdc_StringDescriptor3,
    usb_gpcdc_StringDescriptor4,
    usb_gpcdc_StringDescriptor5,
    usb_gpcdc_StringDescriptor6
};

/*************************************
 *    String Descriptor              *
 *************************************/
UBYTE usb_gpcdc_StringDescriptor0
    [ USB_PCDC_SD0_BLENGTH + ( USB_PCDC_SD0_BLENGTH % 2 ) ] =
{   /* UNICODE 0x0409 English (United States) */
    USB_PCDC_SD0_BLENGTH,               /*  0:bLength */
    USB_DT_STRING,                      /*  1:bDescriptorType */
    0x09, 0x04                          /*  2:wLANGID[0] */
};

UBYTE usb_gpcdc_StringDescriptor1
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

UBYTE usb_gpcdc_StringDescriptor2
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

UBYTE usb_gpcdc_StringDescriptor3
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

UBYTE usb_gpcdc_StringDescriptor4
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

UBYTE usb_gpcdc_StringDescriptor5
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

UBYTE usb_gpcdc_StringDescriptor6
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

#define USB_NOCONNECT                       0x0000u /* Speed undecidedness */
#define USB_HSCONNECT                       0x00C0u /* Hi-Speed connect */
#define USB_FSCONNECT                       0x0080u /* Full-Speed connect */
#define USB_LSCONNECT                       0x0040u /* Low-Speed connect */

/************************************************************
 *  Configuration Or Other_Speed_Configuration Descriptor   *
 ************************************************************/
/* For Full-Speed */
UBYTE usb_gpcdc_ConfigrationF1
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

UBYTE usb_gpcdc_ConfigrationH1
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

/* Configuration descriptor bit define */
#define USB_CF_RESERVED                     0x80u   /* Reserved(set to 1) */
#define USB_CF_SELFP                        0x40u   /* Self Powered */
#define USB_CF_BUSP                         0x00u   /* Bus Powered */
#define USB_CF_RWUPON                       0x20u   /* Remote Wakeup ON */
#define USB_CF_RWUPOFF                      0x00u   /* Remote Wakeup OFF */

/* Class-Specific Configuration Descriptors */
#define     USB_PCDC_CS_INTERFACE                               0x24

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

/* USB Class Definitions for Communications Devices Specification 
   release number in binary-coded decimal. */
#define     USB_PCDC_BCD_CDC                                    0x0110


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

/* USB_BMREQUESTTYPERECIP   0x001Fu(b4-0) */
#define USB_DEVICE                          0x0000u
#define USB_INTERFACE                       0x0001u
#define USB_ENDPOINT                        0x0002u
#define USB_OTHER                           0x0003u

/* CDC Class Requests IDs*/
#define USB_PCDC_SET_LINE_CODING            0x2000
#define USB_PCDC_GET_LINE_CODING            0x2100
#define USB_PCDC_SET_CONTROL_LINE_STATE 0x2200
#define USB_PCDC_SEND_BREAK             0x2300

PH_USB_EXT UWORD R_usb_pstd_ControlRead(USB_UTR_t *ptr, ULONG bsize, UBYTE *table);
PH_USB_EXT void usb_pcdc_ControlTrans0(USB_UTR_t *ptr, USB_REQUEST_t *req);
PH_USB_EXT void usb_pcdc_ControlTrans1(USB_UTR_t *ptr, USB_REQUEST_t *req);
PH_USB_EXT void usb_pcdc_ControlTrans4(USB_UTR_t *ptr, USB_REQUEST_t *req);
PH_USB_EXT void usb_pcdc_ControlTrans3(USB_UTR_t *ptr, USB_REQUEST_t *req);
PH_USB_EXT void usb_pcdc_ControlTrans2(USB_UTR_t *ptr, USB_REQUEST_t *req);
PH_USB_EXT void usb_pcdc_ControlTrans5(USB_UTR_t *ptr, USB_REQUEST_t *req);

PH_USB_EXT void R_usb_pcdc_usr_ctrl_trans_function(USB_UTR_t *ptr, USB_REQUEST_t *preq, UWORD ctsq);

/* USB_BMREQUESTTYPETYPE    0x0060u(b6-5) */
#define USB_STANDARD                        0x0000u
#define USB_CLASS                           0x0020u
#define USB_VENDOR                          0x0040u

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

#define     USB_PCDC_GET_LINE_CODING_LENGTH                 0x07

typedef struct
{
    /* reserve */
    UWORD                    rsv:14;
    /* RTS */
    UWORD                    bRTS:1;
    /* DTR */
    UWORD                    bDTR:1;
}
USB_PCDC_ControlLineState_t;

#define USB_PID                 (0x0003u)   /* b1-0: Response PID */
#define USB_PID_STALL           0x0002u     /* STALL */
#define USB_PID_BUF             0x0001u     /* BUF */
#define USB_PID_NAK             0x0000u     /* NAK */


/******************************************************************************
Private global variables and functions
******************************************************************************/
/* USB data transfer */
/* PIPEn Buffer counter */
UWORD        usb_gcstd_DataCnt[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1u];
/* DMA0 direction */
UWORD        usb_gcstd_Dma0Dir[USB_NUM_USBIP];
/* DMA0 buffer size */
ULONG        usb_gcstd_Dma0Size[USB_NUM_USBIP];
/* DMA0 FIFO buffer size */
UWORD        usb_gcstd_Dma0Fifo[USB_NUM_USBIP];
/* DMA0 pipe number */
UWORD        usb_gcstd_Dma0Pipe[USB_NUM_USBIP];
/* PIPEn Buffer pointer(8bit) */
UBYTE         *usb_gcstd_DataPtr[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1u];
/* Message pipe */
USB_UTR_t       *usb_gcstd_Pipe[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1u];
/* XCKE Mode Flag */
UWORD        usb_gcstd_XckeMode;
/* Hi-speed enable */
UWORD        usb_gcstd_HsEnable[USB_NUM_USBIP];


/* The number of USBIP */
#define USB_NUM_USBIP           2

/* GET_LINE_CODING request wLength */
#define     USB_PCDC_GET_LINE_CODING_LENGTH                 0x07

/* Line Coding Set Request data */
USB_PCDC_LineCoding_t usb_gcdc_LineCodingReq;



#endif

//#endif	/* __USB_PROTOTYPE__	*/
