/*===============================================================
Author: Delta Electronic, INC. IABU

Project: VFD-IED

Filename: SCI0_CARGroup.H

Partner Filename: SCI0_CARGroup.C

Description: This is a inclue file of SCI0_CARGroup.C

Complier: 

	
History:

===============================================================*/
#ifdef _SCI4_PGComm_C
   #define SCI4_PGComm_EXT
#else
   #define SCI4_PGComm_EXT extern
#endif

SCI4_PGComm_EXT void CHK_PUID0(void);
SCI4_PGComm_EXT UWORD CRC_CHECK_0(UBYTE CRC_CNT);
SCI4_PGComm_EXT void RTU_RxOKChk_0(void);
SCI4_PGComm_EXT void TxD_Data_0(void);
SCI4_PGComm_EXT void RxDataCheck_0(void);
SCI4_PGComm_EXT void RxDecoder_0(void);
SCI4_PGComm_EXT void PG_HEX2ASC(UBYTE byte_cnt);
SCI4_PGComm_EXT void Init_TxData_0(UBYTE Data_CNT);
SCI4_PGComm_EXT void PG_RemoteCmd03(void);
SCI4_PGComm_EXT void PG_RemoteCmd06(void);
SCI4_PGComm_EXT void PG_RemoteCmd63(void);
SCI4_PGComm_EXT void PG_RemoteCmd10(void);
SCI4_PGComm_EXT void SCI0_ComFault(void);
SCI4_PGComm_EXT UWORD CRC16(UBYTE *dt, UWORD length);   //[For IED PG-Card, Sampo, 01/11/2010]
SCI4_PGComm_EXT	void SCI0_PGHSD_Comm(void);				// PGHSD comm replacement, Sean, 01/09/2012

SCI4_PGComm_EXT UBYTE TxD_Data_0_Gen(UBYTE ubIdx);
SCI4_PGComm_EXT void RxD_Data_0(void);

SCI4_PGComm_EXT UBYTE_UNION com0_status;

SCI4_PGComm_EXT UBYTE	Rx0CNT,
						ubRx0CNT,
                        Tx0CNT,
                        SendCNT0,
                        RxBuf_0[RX_LENGTH],
                        TxBuf_0[TX_LENGTH];

SCI4_PGComm_EXT UBYTE   RTU_Silent0,
						SCIDIR0Flag;

SCI4_PGComm_EXT UBYTE   COM0Err,
                        PUID0Cnt,
                        Com_WatchDog0;

SCI4_PGComm_EXT UWORD   SCI0_TodCNT,
                        RTU_CNT0,
                        uwPG_OverTimeCnt;  //[For IED PG-Card, Sampo, 02/25/2010]
                        
SCI4_PGComm_EXT UBYTE 	Pgc_ubSta;
SCI4_PGComm_EXT UWORD 	uwEndatPosition,  //[For IED PG-Card, Sampo, 01/11/2010]
                        uwHiperPosition;  //[For IED PG-Card, Sampo, 01/11/2010]

// add pghsd1 code, Sean, 05/28/2012
// to EndOfFile
typedef struct{	
	UWORD uwAngle; 			/*the from EMED-PGHSD*/	
	UBYTE ubErrSign; 		/*the error sign from PG and testing of IED for PG*/
	UBYTE ubErrAbCnt; 		/*count number of AB break line error , 	ubErrSign.bit0 =1 times */
	UBYTE ubErrTypCnt; 		/*count numbes of encoder type error , 	ubErrSign.bit1 =1 times */
	UBYTE ubErrPgCnt; 		/*count number of encoder error , ubErrsign.bit2 =1 times */ 
	UBYTE ubErrPgCrcCnt; 	/*count number of PG CRC error , 	ubErrsign.bit3 =1 times */ 
	UBYTE ubErrPgOveCnt; 	/*count number of encoder type over error , 	ubErrsign.bit4 =1 times */ 
	UBYTE ubErrTiOutCnt; 	/*count number of PG replay over time error , ubErrsign.bit5 =1 times */ 
	UBYTE ubErrMatCnt; 		/*count number of matching error , 			ubErrsign.bit6 =1 times */ 
	UBYTE ubErrCrcCnt; 		/*count number of IED CRC error , 				ubErrsign.bit7 =1 times */ 
	UBYTE ubPgLoss2; 		/*the realult of PGlOSS2 sign*/
} HSD_ST_PG_REPLY_OUT ;
typedef struct{
	UBYTE	ubEndTyp ;			/*the encoder type to EMED-PGHSD from IED */
	UBYTE	ubDivFre ; 	/*in addition to the frequency coefficients IED*/
} HSD_ST_IED_SEND_IN;

SCI4_PGComm_EXT void hsd_ProssTxRxTb1(HSD_ST_IED_SEND_IN *in, HSD_ST_PG_REPLY_OUT *out);
SCI4_PGComm_EXT	void hsd_TxStaPro(void);
SCI4_PGComm_EXT	void hsd_RxStaPro(void);
SCI4_PGComm_EXT	void hsd_PgErrClcPro(void) ;
SCI4_PGComm_EXT	void hsd_PgErrorPro(UBYTE_UNION ub);

SCI4_PGComm_EXT HSD_ST_PG_REPLY_OUT	hsd_stPgReplyOut;
SCI4_PGComm_EXT HSD_ST_IED_SEND_IN	hsd_stIedSendIn;
SCI4_PGComm_EXT UBYTE hsd_ubRxTxSta;		/*the TX and RX status varable */
SCI4_PGComm_EXT UBYTE hsd_ubTxTimCnt;		/*the one by one time count varable */
SCI4_PGComm_EXT UBYTE hsd_ubTxCnt1;			/*the TX number count varable */
SCI4_PGComm_EXT UBYTE hsd_ubRxCnt;			/*the RX number count varable */
SCI4_PGComm_EXT UBYTE hsd_ubRxBuf[7] ;		/*the RX data buffer*/
SCI4_PGComm_EXT UBYTE hsd_ubTxBuf[5] ;
SCI4_PGComm_EXT UBYTE hsd_ubErrClcAbCnt; 	/*clear count numbers of AB break line error , 		ubErrSign.bit0 =1 times */
SCI4_PGComm_EXT UBYTE hsd_ubErrClcTypCnt;	/*clear count numbes of encoder type error , 		ubErrSign.bit1 =1 times */
SCI4_PGComm_EXT UBYTE hsd_ubErrClcPgCnt; 	/*clear count number of encoder error , 			ubErrsign.bit2 =1 times */ 
SCI4_PGComm_EXT UBYTE hsd_ubErrClcPgCrcCnt; /*clear count number of PG CRC error , 				ubErrsign.bit3 =1 times */ 
SCI4_PGComm_EXT UBYTE hsd_ubErrClcPgOveCnt; /*clear count number of encoder type over error , 	ubErrsign.bit4 =1 times */ 
SCI4_PGComm_EXT UBYTE hsd_ubErrClcTiOutCnt; /*clear count number of PG replay over time error , ubErrsign.bit5 =1 times */ 
SCI4_PGComm_EXT UBYTE hsd_ubErrClcMatCnt; 	/*clear count number of matching error , 			ubErrsign.bit6 =1 times */ 
SCI4_PGComm_EXT UBYTE hsd_ubErrClcCrcCnt ; 	/*clear count number of IED crc error 				ubErrsign.bit7 =1 times*/

SCI4_PGComm_EXT UWORD hsd_uwTxTimOutCnt, //[PG card can't work, Bernie, 2015/09/21]
                      hsd_uwRxTimOutCnt; //[PG card can't work, Bernie, 2015/09/21]

//#define HSD_PGLSS2_REG_MACRO		PB.PR.BIT.B17 /*the pin PB17 read register (PGLOSS2)*/
#define HSD_PGLSS2_REG_MACRO		PORT6.PIDR.BIT.B4 /*the pin PB17 read register (PGLOSS2)*/
SCI4_PGComm_EXT UBYTE_UNION hsd_status;

#define HSD_NOR_TIME_DELAY_CONST		24	/*500us*24=12ms, the delay time of one by one when tranmit normal*/
#define HSD_ERR_TIME_DELAY_CONST		148	/*500us*48=24ms, the delay time of one by one when tranmit error*/
#define HSD_MAX_ERR_CNT_CONST			50	/*the max count number of error CRC or timer over of receive*/
#define HSD_RX_MAX_CNT_CONST			6	/*the MAX number of RX*/
#define HSD_TX_STATUS_CONST				0	/*the modle TX of status CONST */ 
#define HSD_RX_STATUS_CONST				1	/*the modle RX of status CONST */
#define HSD_CHECK_STATUS_CONST			2	/*the modle check of status CONST */
#define HSD_DELAY_STATUS_CONST			3	/*the modle delay of status CONST */
#define HSD_ERR_STATUS_CONST			4	/*the modle error of status CONST */
#define HSD_PG_TO_IED_ERR_CONST			0x80/*the error bit of PG-->IED crc */
#define HSD_TIME_OUT_PG_RX_ERR_CONST	0x20/*the error time out of PGHSD replay*/
#define HSD_MATCH_ERR_CONST 			0x40/*last TX data not matching RX data error */
#define HSD_PGLOSS2_VALID_CONST 		0	/*low level, the PGLOSS2 is valid statu of PB17 const*/
#define HSD_ERR_CLEAR_MAX_CONST 		3	/*the max number of clear error const*/
#define	SCI_0_MODE_UART_CONST			1	/*the set the mode  SCI4 is  UART mode*/
#define	SCI_0_BITRAT_31250_CONST		5	/*the set the UART of SCI4  bitrat  is  31250*/
#define	SCI_0_INT_PRIO_1_LEV_CONST		1	/*the SCI4 interrupt priotity  lvevel const*/ 
#define	SCI_0_INT_PRIO_2_LEV_CONST		2   
#define	SCI_0_INT_PRIO_3_LEV_CONST		3     
#define	SCI_0_INT_PRIO_4_LEV_CONST		4   
#define	SCI_0_INT_PRIO_5_LEV_CONST		5  
#define	SCI_0_INT_PRIO_6_LEV_CONST		6     
#define	SCI_0_INT_PRIO_7_LEV_CONST		7   
#define	SCI_0_INT_PRIO_8_LEV_CONST		8  
/*const of input and output mode  */
#define  MCU_PIN_INPUT_CONST			0	/*the pin is input mode const*/
#define  MCU_PIN_OUTPUT_CONST			1	/*the pin is output mode const*/
/*const  of pull-up set  */
#define  MCU_PIN_MOS_ON_CONST			1	/*the pin is turn  on  input pull-up MOS const */
#define  MCU_PIN_MOS_OFF_COSNT			0	/*the pin is turn  off  input pull-up MOS const */
/*const the pin function (mode) set  const*/ 
#define MCU_PD22_FUNC_SCI4_RX_COSNT		5	/*the  pin function (mode) is SCI4  RX const */
#define MCU_PD21_FUNC_SCI4_TX_CONST		5	/*the  pin function (mode) is SCI4  TX const */  
#define MCU_PB17_FUNC_IO_CONST			0	/*the  pin function (mode) is IO  const */
#define	HSD_PGT_SIN						0x02	// SIN_SIN: 	1387
#define	HSD_PGT_ENDAT					0x00	// SIN_ENDAY:	1313
#define	HSD_PGT_HIPER					0x01	// SIN_HIPER:	Hiperface
/************************************************************************
 Copyright (c) 2010 IABU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
