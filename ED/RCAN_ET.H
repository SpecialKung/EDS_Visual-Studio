/*===============================================================
Author: DINO

Project: VFD-VL

Filename: RCAN_ET.h

Partner Filename: RCAN_ET.c

Description: This is a inclue file of RCAN_ET.c

Complier: 

	
History:

===============================================================*/
#ifdef _RCAN_ET_C
   #define RCAN_ET_EXT
#else
   #define RCAN_ET_EXT extern
#endif

RCAN_ET_EXT void CAN_ICT_TX(void);
RCAN_ET_EXT void CAN_TX(void);          //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_RX(void);
RCAN_ET_EXT void CAN_MB_Receive(UBYTE MBOX);
RCAN_ET_EXT void CAN_WaitRx(UBYTE MB);
RCAN_ET_EXT void CAN_PDO_RX_Data(void);
RCAN_ET_EXT void CAN_PDO_TX_return(void);  //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT UWORD UnitTransfer(void);           //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_RX_Decode(void); //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_READ_DATA(void);  //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_Return(UBYTE Fun, UBYTE MB_NUMBER);   //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_READ_ACCESS(void);   //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_ERROR_Return(UBYTE STATUS,UWORD ERROR_CODE);   //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_WRITE_DATA(void);    //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_WRITE_ACCESS(void);    //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_READ_Attribution(void);    //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_READ_Description(void);    //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_Attribution_return(UWORD Attribute, UWORD Minimum, UWORD Maxmum, UWORD Default);    //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void CAN_SDO_Description_return(string20 str);    //[DLC, Bernie, 2014/10/06]
RCAN_ET_EXT void PDO_sub0(UWORD k); //James, 2021/12/03
RCAN_ET_EXT void Update_DLCC40xx(void);    //[DLC, Bernie, 2015/01/22]



RCAN_ET_EXT UWORD can_tmo_cnt;
RCAN_ET_EXT UWORD CAN_uwErrNo,
                  uwPDO_CNT,
                  uwPDOfailCNT,
                  uwPDOInCnt,
                  uwPDOfailBuf;   //[CAN fail rate function, Aevin, 2017/06/14]

RCAN_ET_EXT UBYTE RCAN_MB0[8],
            
                  RCAN_MB1[8],
                  RCAN_MB3[8],
                  RCAN_MB5[8],
                  RCAN_MB7[8];

RCAN_ET_EXT UWORD RCAN_SDO_RX_MB[10],
                  RCAN_SDO_READ_MB[10],
                  RCAN_SDO_WRITE_MB[10];


RCAN_ET_EXT UBYTE RCAN_ubErr4Rgst,
                  RCAN_Timer,
                  DLC_PDO_RX_TF,
                  DLC_PDO_TX_LTF,
                  DLC_PDO_TX_ALF,
                  DLC_PDO_DLC_Mode,
                  DLC_PDO_RX_Data_Mode,
                  DLC_PDO_TX_Data_Mode;

RCAN_ET_EXT UWORD RCAN_ubICTCnt,
                  RCAN_uwstatus,
                  RCAN_RX_Count;

RCAN_ET_EXT ULONG ulDLC_PDO_RX_APS_Pu,
                  ulDLC_PDO_RX_APS_ClipPu,
                  ulDLC_PDO_RX_APS_ClipPuOld;


RCAN_ET_EXT UWORD_UNION CAN_status;

RCAN_ET_EXT UWORD_UNION DLC_PDO_RX_EM,
                        DLC_PDO_RX_DI,
                        DLC_PDO_TX_INV_ST,
                        DLC_PDO_TX_INV_SPD,
                        DLC_PDO_TX_ME;

RCAN_ET_EXT UBYTE_UNION DLC_PDO_RX_RC,
                        DLC_PDO_TX_AskC,
                        DLC_PDO_ID004_B0,
                        DLC_PDO_ID004_B1,
                        DLC_PDO_ID004_B2,
                        DLC_PDO_ID004_B3,
                        DLC_PDO_ID004_B4,
                        DLC_PDO_ID004_B5,
                        DLC_PDO_ID004_B6,
                        DLC_PDO_ID004_B7,
						DLC_PDO_ID005_B0,//Artemis DLC modify , James, 2020/06/02
						DLC_PDO_ID005_B1,
						DLC_PDO_ID005_B2,
						DLC_PDO_ID005_B3,
						DLC_PDO_ID005_B4,
						DLC_PDO_ID005_B5,
						DLC_PDO_ID005_B6,
						DLC_PDO_ID005_B7;

RCAN_ET_EXT UBYTE    DLC_SDO_RX_Command,
                     DLC_SDO_RX_Lenght,
                     DLC_SDO_RX_Address_H,
                     DLC_SDO_RX_Address_L;
                    
RCAN_ET_EXT UWORD DLC_SDO_RX_Data0;      

RCAN_ET_EXT UWORD_UNION    UCMP_STATUS;   //[UCMP function, Bernie, 2016/06/14]
RCAN_ET_EXT UWORD CAN_UWEST_COUNT,      //pr[0
                  CAN_UWEST_STATUS,
                  CAN_UWTABST0_COUNT,
                  CAN_UWTABST1_COUNT,
                  CAN_UWTABST0_STATUS,
                  CAN_UWTABST1_STATUS;


//[GK communication, Bernie, 2013/03/18]
RCAN_ET_EXT UBYTE_UNION  GK_status;
#define RUN_DCI_OK      GK_status.bit.b0 

#define MBOX0  0x00
#define MBOX1  0x01
#define MBOX2  0x02
#define MBOX3  0x03
#define MBOX4  0x04
#define MBOX5  0x05
#define MBOX6  0x06
#define MBOX7  0x07

#define SDO_FRAME1 0x02
#define SDO_FRAME2 0x06
#define SDO_FRAME3 0x0A


#define READ_INVERTER    0x03
#define READ_EXCEPTION   0x83
#define WRITE_INVERTER   0x06
#define WRITE_EXCEPTION  0x86
#define READ_ATTRIBUTION 0x60
#define READ_DESCRIPTION   0x61
#define ATT_EXCEPTION    0xE0
#define DESCR_EXCEPTION  0xE1

#define ERROR_LENGHT   0x01


#define ADDR_UNDEFINED  0x01
#define OVERFLOW        0x02
#define WRITE_SUCCESS   0xFF

#define C40xxMapmax     0x45

