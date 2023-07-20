/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: Main.H

Partner Filename: Main.C

Description: This is a inclue file of Main.C

Complier: 

	
History:

===============================================================*/
#ifdef _SCI3_Remote_C
   #define SCI3_Remote_EXT
#else
   #define SCI3_Remote_EXT extern
#endif

SCI3_Remote_EXT void CHK_PUID2(void);
SCI3_Remote_EXT UWORD CRC_CHECK_2(UBYTE CRC_CNT);
SCI3_Remote_EXT void RTU_RxOKChk_2(void);
SCI3_Remote_EXT void TxD_Data_2(void);
SCI3_Remote_EXT void RxDataCheck_2(void);
SCI3_Remote_EXT void RxDecoder_2(void);
SCI3_Remote_EXT void HEX2ASC_2(UBYTE byte_cnt);
SCI3_Remote_EXT void Init_TxData_2(UBYTE Data_CNT);
SCI3_Remote_EXT void RemoteCmd03_2(void);
SCI3_Remote_EXT void RemoteCmd06_2(void);
SCI3_Remote_EXT void RemoteCmd63_2(void);
SCI3_Remote_EXT void RemoteCmd10_2(void);
SCI3_Remote_EXT void RemoteCmd17_2(void);         //[APP01 IO carde support, Bernie, 2013/03/20]
SCI3_Remote_EXT void SCI2_ComFault(void);	//SCI2>SCIF3, Sean, 01/20/2010
SCI3_Remote_EXT UWORD BLKTransferRead(UWORD prx);
SCI3_Remote_EXT void PC_CEError(UBYTE CeErr);
SCI3_Remote_EXT void FFcalibration(UBYTE func, UWORD datac);

SCI3_Remote_EXT UBYTE     Keypad_Page,
                          Keypad_PageTmp,
                          COM2Err,
                          PUID2Cnt,
                          MFD_page;				//CalUBYTE: 5 UBYTE

SCI3_Remote_EXT UBYTE     Rx2CNT,
                          Tx2CNT,
                          SendCNT2,
                          RxBuf_2[RX_LENGTH],	//RX_LENGTH = 100
                          TxBuf_2[TX_LENGTH];	//RX_LENGTH = 100
                          						//CalUBYTE: 203 UBYTE

SCI3_Remote_EXT UBYTE     RTU_Silent2,
                          Com_WatchDog2,
						  SCIDIR2Flag,
						  SCI2_ubTXIDalay,		// TXI Delay Time, Add by DINO, 03/02/2010
						  SCI2_ubCNT;
                          
SCI3_Remote_EXT UWORD     SCI2_TodCNT,
                          RTU_CNT2;

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
