/*===============================================================
Author: DINO

Project: VFD-VL

Filename: RCAN_ET.h

Partner Filename: RCAN_ET.c

Description: This is a inclue file of RCAN_ET.c

Complier: 

	
History:

===============================================================*/
#ifdef _PH_RCAN_C
   #define PH_RCAN_EXT
#else
   #define PH_RCAN_EXT extern
#endif
#if 0
/* Function Call ==============================================*/
PH_RCAN_EXT void RCAN_INT_RM0(void);
PH_RCAN_EXT void RCAN_INT_SLE0(void);
PH_RCAN_EXT void RCAN_MB1_TX(void);
PH_RCAN_EXT void RCAN_MB3_TX(void);
PH_RCAN_EXT void RCAN_MB5_TX(void);	//Sean, 03/31/2010

PH_RCAN_EXT void car_vdRcan(void);
PH_RCAN_EXT void car_vdRcanRx(void);
PH_RCAN_EXT void car_vdRcanTx(void);

/* Exported Variable List ======================================*/
PH_RCAN_EXT UBYTE_UNION ECAN_status,CAN_HC_status; // [CAN Protocol for High Cap , Sampo,  2011/09/05]

PH_RCAN_EXT UBYTE MB1_TxData[8],	//MB1 Tx Data
				  MB2_RxData[8],	//MB2 Rx Data
				  MB3_TxData[8],	//MB3 Tx Data
				  MB4_RxData[8],	//MB4 Rx Data
				  MB5_TxData[8],	//MB5 Tx Data	//Sean, 03/31/2010
				  MB6_RxData[8];	//MB6 Rx Data	//Sean, 03/31/2010

PH_RCAN_EXT UBYTE can_ubErr;			//Sean, 03/31/2010
PH_RCAN_EXT UBYTE can_ubDelay;			//Sean, 03/31/2010

//Sean, 05/17/2010

PH_RCAN_EXT UWORD can_uwTRErrTime;	//Tx/Rx Error Count
PH_RCAN_EXT UWORD can_uwErrTime;	//Rx Package Lost Count
PH_RCAN_EXT UBYTE can_ubRxLost;		//Rx Timeout Count
PH_RCAN_EXT UBYTE can_ubRxDone;		//Rx Done flag Registers


PH_RCAN_EXT ULONG_UNION mio_ulCfiNow,	// [Can function, Bernie, 08/16/2011]	// CTB MFI Value, HCB1+HCB0+CTB1+CTB0 ,Sean, 06/10/2010
                     mio_ulCfoNow;				                    // CTB MFO Value, HCB1+HCB0+CTB1+CTB0 ,Sean, 06/10/2010

PH_RCAN_EXT UWORD_UNION car_uwLoadCell;

PH_RCAN_EXT UDOUBLE_UNION lev_udCarSig,
                          lev_udCarSig2;


#define	can_ubRXLOSTTIMEOUT	10		//Time(ms), Rx Timeout Limit
#define	can_uwERRTIMEOUT	1000	//Time(ms), Error timeout
#define	can_uwTRERRTIMEOUT	1000	//Time(ms), Tx/Rx Error Limit
#define	can_ubDELAY			200		//Time(ms), Retry Tx 

#define can_ubMB2_DONE	1
#define can_ubMB4_DONE	2	
#define	can_ubMB6_DONE	4

//Error Code	//Sean, 03/31/2010

#define can_ubERRTEC 	1
#define can_ubERRREC 	2
#define can_ubERROV  	3
#define can_ubERRLOST 	4
#define can_ubERRMAX	4	//Error Code Number
#endif
/************************************************************************
 Copyright (c) 2010 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
