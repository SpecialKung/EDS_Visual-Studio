/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: Main.H

Partner Filename: Main.C

Description: This is a inclue file of Main.C

Complier: 

	
History:

===============================================================*/
#ifdef _SCI1_Remote_C
   #define SCI1_Remote_EXT
#else
   #define SCI1_Remote_EXT extern
#endif

//SCI1_Remote_EXT void CHK_PUID1(void);
SCI1_Remote_EXT UWORD CRC_CHECK_3(UBYTE CRC_CNT);
SCI1_Remote_EXT UWORD CRC_CHECK_UD(UBYTE CRC_CNT);//[UD protocal, Bernie, 2012/12/05]
SCI1_Remote_EXT void RTU_RxOKChk_3(void);
SCI1_Remote_EXT void TxD_Data_3(void);
SCI1_Remote_EXT void RxDataCheck_3(void);
SCI1_Remote_EXT void RxDecoder_3(void);
SCI1_Remote_EXT void HEX2ASC_3(UBYTE byte_cnt);
SCI1_Remote_EXT void Init_TxData_3(UBYTE Data_CNT);
SCI1_Remote_EXT void RemoteCmd03_3(void);
SCI1_Remote_EXT void RemoteCmd06_3(void);
SCI1_Remote_EXT void RemoteCmd63_3(void);
SCI1_Remote_EXT void RemoteCmd10_3(void);
SCI1_Remote_EXT void RemoteCmd65_3(void);       //[UD protocal, Bernie, 2012/12/05]
SCI1_Remote_EXT void RemoteCmd65_3_WrData(void); //[UD protocal, Bernie, 2012/12/05]
SCI1_Remote_EXT void RemoteCmd65_3_RdData(void);  //[UD protocal, Bernie, 2012/12/05]


SCI1_Remote_EXT void SCI3_ComFault(void);	//SCI2>SCIF3, Sean, 01/20/2010
//SCI1_Remote_EXT UWORD BLKTransferRead(UWORD prx);
SCI1_Remote_EXT void PC_CEError3(UBYTE CeErr);
SCI1_Remote_EXT void FFcalibration3(UBYTE func, UWORD datac);

SCI1_Remote_EXT UBYTE     Keypad_Page3,
                          Keypad_PageTmp3,
                          COM3Err,
                          PUID3Cnt;
                          //MFD_page;				//CalUBYTE: 5 UBYTE

SCI1_Remote_EXT UBYTE     Rx3CNT,
                          Tx3CNT,
                          SendCNT3,
                          RxBuf_3[RX_LENGTH],	//RX_LENGTH = 100
                          TxBuf_3[TX_LENGTH];	//RX_LENGTH = 100
                          						//CalUBYTE: 203 UBYTE

SCI1_Remote_EXT UBYTE     RTU_Silent3,
                          Com_WatchDog3,
						  SCIDIR3Flag,
						  SCI3_ubTXIDalay,		// TXI Delay Time, Add by DINO, 03/02/2010
						  SCI3_ubCNT;

                          
SCI1_Remote_EXT UWORD     SCI3_TodCNT,
                          RTU_CNT3;


/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
