/***********************************************************************/
/*                                                                     */
/*  FILE        :RCAN_ET.c                                             */
/*  DATE        :Tur, Jun 21, 2007                                     */
/*  DESCRIPTION :Hardware Setup file                                   */
/*  CPU TYPE    :SH7147                                                */
/*                                                                     */
/***********************************************************************/
#ifndef  _PH_RCAN_C
    #define  _PH_RCAN_C
#endif
#if 0
#include "ProgHeader.h"


//Func Add by Sean, 03/31/2010

//any CAN error remain over certain time, then it's major Error, Sean, note
//MBn_Done not set over certain time, it coulbe be major or minor Error, Sean, note
void car_vdRcan(void){
	UWORD uwErr;
	
	//Start Rx Tx
	car_vdRcanRx();

#if 0	//MB4 not implemented yet, Sean, 05/17/2010
	if ((can_ubRxDone&(can_ubMB2_DONE|can_ubMB6_DONE)) != 0){	
#else	// cmd board di/do correction, Sean, 09/07/2010
	if ((can_ubRxDone&(can_ubMB2_DONE|can_ubMB4_DONE|can_ubMB6_DONE)) == (can_ubMB2_DONE|can_ubMB4_DONE|can_ubMB6_DONE)){	
#endif			
		can_ubRxDone = 0;
		car_vdRcanTx();
		can_ubDelay = 0;
		can_ubRxLost = 0;
#if 1
#else
		if (can_ubErr == can_ubERRLOST)
#endif			
			can_ubErr = 0;
	}
	else{
		can_ubDelay++;
		if (can_ubDelay >= can_ubDELAY){
			can_ubDelay = 0;
			car_vdRcanTx();
			can_ubRxLost++;
			if (can_ubRxLost > can_ubRXLOSTTIMEOUT){
				can_ubRxLost = 0;
				can_ubErr = can_ubERRLOST;
			}
		}
	}
		
	//CAN error Handler
	uwErr = RCANET.IRR.WORD;
	if ((uwErr & 0x0200) == 0x0200){		// IRR9:Msg Overrun/Overwrtie
		RCANET.UMSR0.WORD = 0xffff;	//rest IRR9, Sean, 05/17/2010
		can_ubErr = can_ubERROV;
	}	
	else if ( (uwErr & 0x0020) == 0x0020){		// IRR5:Error Passive Mode
#if 1	// reset CAN err flag, Sean, 10/08/2010
		RCANET.IRR.WORD |= 0x0020;	//reset IRR5
#else		
		RCANET.IRR.WORD &= 0x0020;	//reset IRR5
#endif		
		can_uwTRErrTime++;
		if (can_uwTRErrTime>can_uwTRERRTIMEOUT){
			can_uwTRErrTime = 0;
#if 0	// tec/rec can err masked, Sean, 11/10/2010			
			if (RCANET.TECREC.BIT.TEC>0x80)
				can_ubErr = can_ubERRTEC;
			else
				can_ubErr = can_ubERRREC;
#endif				
		}
	}
#if 1	// reset CAN err flag, Sean, 10/08/2010
	else if ((uwErr & 0x0008) == 0x0008){
		RCANET.IRR.WORD |= 0x0008;	//reset IRR3
	}
	else if ((uwErr & 0x0010) == 0x0010){
		RCANET.IRR.WORD |= 0x0010;	//reset IRR4
	}
	else if ((uwErr & 0x0040) == 0x0040){	//BUS OFF
		RCANET.IRR.WORD |= 0x0040;	//reset IRR6
	}	
	else if ((uwErr & 0x0080) == 0x0080){	//Overload Frame
		RCANET.IRR.WORD |= 0x0080;	//reset IRR7
	}	
	else if (can_ubErr!=can_ubERRLOST){
		can_ubErr = 0;
	}
#endif	
	
	//CAN error handler
	if (can_ubErr!=0){
		if (can_uwErrTime>can_uwERRTIMEOUT){
#if 1	//not implemented to main Error, Sean, note, 05/17/2010	
			can_uwErrTime = 0;			
#else			
			//Error = can_ubErr + CAN_ERR_BASE;	//return CAN_Error to IED_Error, Sean, 05/17/2010
						
#endif			
		}
		else{
/*	// debug, Sean, 06/22/2010			
			can_uwErrTime++;
			InitRCANET();	
   			RCANET.MCR.WORD &= 0xfffe;                      // Clear MCR0
    		while ( (RCANET.GSR.WORD&0x0008)!=0x0000 );    	// GSR3=0?
    		
    		can_ubRxDone|=(can_ubMB2_DONE|can_ubMB6_DONE);	//test, Sean, 05/17/2010
    		MB1_Done = 1;
    		MB3_Done = 1;
    		MB5_Done = 1;
*/
		}			
	}
	else{
		can_uwErrTime = 0;
	}
}

//CTB MFI/MFO Implement, car_vdRcanRx/car_uvRcanTx replaced, Sean, 06/10/2010
void car_vdRcanRx(void){	

	//MB2:Car Signal
	if (MB2_Done){		
		can_ubRxDone |= can_ubMB2_DONE;	//Sean, 05/17/2010

#if 0	//old CTB protocol test, Sean, 06/10/2010;
		car_uwLoadCell.ub.low = MB2_RxData[0];
		car_uwLoadCell.ub.hi = MB2_RxData[1];
		mio_ulCfiNow.ub.b0 = MB2_RxData[2];				
#else
		//CTB MFI
		mio_ulCfiNow.ub.b0 = MB2_RxData[0];
		mio_ulCfiNow.ub.b1 = MB2_RxData[1];	// cmd board di/do correction, Sean, 09/07/2010
		//LoadCell
		car_uwLoadCell.ub.low = MB2_RxData[2];
		car_uwLoadCell.ub.hi = MB2_RxData[3];
		//Resrved AD Input: MB2[4],MB2[5]
		//Other are Reserved
#endif		
		
		//Reset Flag
		MB2_Done = 0;
	}
	//MB4:Floor Signal 2nd source
	if (MB4_Done){
		can_ubRxDone |= can_ubMB4_DONE;	//Sean, 05/17/2010
		
#if 0	//old CTB protocol test, Sean, 06/10/2010;		
		lev_udCarSig2.ub.b0	= MB4_RxData[0];
		lev_udCarSig2.ub.b1	= MB4_RxData[1];
		lev_udCarSig2.ub.b2	= MB4_RxData[2];
		lev_udCarSig2.ub.b3	= MB4_RxData[3];
		lev_udCarSig2.ub.b4	= MB4_RxData[4];
		lev_udCarSig2.ub.b5	= MB4_RxData[5];		
#else
		lev_udCarSig2.ub.b0	= MB4_RxData[0];
		lev_udCarSig2.ub.b1	= MB4_RxData[1];
		mio_ulCfiNow.ub.b3 = MB4_RxData[2];
		lev_udCarSig2.ub.b2	= MB4_RxData[3];
		lev_udCarSig2.ub.b3	= MB4_RxData[4];
		lev_udCarSig2.ub.b4	= MB4_RxData[5];
		//Other are Reserved
#endif		
		//Reset Flag		
		MB4_Done = 0;	
	}		
	//MB6:Floor Signal 1st source
	if (MB6_Done){	
		can_ubRxDone |= can_ubMB6_DONE;	//Sean, 05/17/2010
#if 0	//old CTB protocol test, Sean, 06/10/2010;	
		lev_udCarSig.ub.b0 = MB6_RxData[0];
		lev_udCarSig.ub.b1 = MB6_RxData[1];
		lev_udCarSig.ub.b2 = MB6_RxData[2];
		lev_udCarSig.ub.b3 = MB6_RxData[3];
		lev_udCarSig.ub.b4 = MB6_RxData[4];
		lev_udCarSig.ub.b5 = MB6_RxData[5];
#else		
		lev_udCarSig.ub.b0 = MB6_RxData[0];
		lev_udCarSig.ub.b1 = MB6_RxData[1];
		mio_ulCfiNow.ub.b2 = MB6_RxData[2];
		lev_udCarSig.ub.b2 = MB6_RxData[3];
		lev_udCarSig.ub.b3 = MB6_RxData[4];
		lev_udCarSig.ub.b4 = MB6_RxData[5];
		//lev_btCarCmdClr = ((MB6_RxData[6]&0x01)==0x01)?1:0;	// car cmd doulbe-click(clear) in short time(1s), Sean, 10/13/2010  //Bernie mask 08/16/2011	
			
		//Other are Reserved
#endif		
		//Reset Flag		
		MB6_Done = 0;				
	}
}

void car_vdRcanTx(void){
	//MB1:Current Level, Car Status, Door Control
	UBYTE ubTmp,ubTmp2;
	UDOUBLE_UNION udCmd;
	
	if(MB1_Done){
	/*
		MB1_TxData[0]	= mio_ulCfoNow.ub.b0;	// cmd board di/do correction, Sean, 09/07/2010
		MB1_TxData[1]	= mio_ulCfoNow.ub.b1;	// cmd board di/do correction, Sean, 09/07/2010
		MB1_TxData[2]	= hcb_ubDisMap(pr[_1st_DISP+(lev_ubCur-1)],ubLEFT);
		MB1_TxData[3]	= hcb_ubDisMap(pr[_1st_DISP+(lev_ubCur-1)],ubRIGHT);				
		MB1_TxData[4]	= car_uwStatus.ub.low;	// cmd board di/do correction, Sean, 09/07/2010
		//Other are Reserved		
		MB1_TxData[5]	= 0;
		MB1_TxData[6]	= 0;
		MB1_TxData[7]	= 0;
	*/
		//Start MB1 Tx
		RCAN_MB1_TX();
		//Reset Flag		
		MB1_Done = 0;		
	}
	//MB3:Floor Status 2nd source
	if(MB3_Done){
/*  Bernie mask 08/16/2011
#if 1	// add lev_xxxSta, Sean, 10/13/2010
		MB3_TxData[0]	= lev_udCarSta.ub.b0;
		MB3_TxData[1]	= lev_udCarSta.ub.b1;
		MB3_TxData[2]	= mio_ulCfoNow.ub.b3;
		MB3_TxData[3]	= lev_udCarSta.ub.b2;
		MB3_TxData[4]	= lev_udCarSta.ub.b3;
		MB3_TxData[5]	= lev_udCarSta.ub.b4;
		//Other are Reserved
		MB3_TxData[6]	= 0;
		MB3_TxData[7]	= 0;
#else		
		MB3_TxData[0]	= lev_udCarCmd.ub.b0;
		MB3_TxData[1]	= lev_udCarCmd.ub.b1;
		MB3_TxData[2]	= mio_ulCfoNow.ub.b3;
		MB3_TxData[3]	= lev_udCarCmd.ub.b2;
		MB3_TxData[4]	= lev_udCarCmd.ub.b3;
		MB3_TxData[5]	= lev_udCarCmd.ub.b4;
		//Other are Reserved
		MB3_TxData[6]	= 0;
		MB3_TxData[7]	= 0;
#endif	
*/
		//Start MB5 Tx
		RCAN_MB3_TX();
		//Reset Flag		
		MB3_Done = 0;
	}		
	//MB5:Floor Status 1st source
	if(MB5_Done){
/*    //Bernie mask 08/16/2011
#if 1	// add lev_xxxSta, Sean, 10/13/2010
		MB5_TxData[0]	= lev_udCarSta.ub.b0;
		MB5_TxData[1]	= lev_udCarSta.ub.b1;
		MB5_TxData[2]	= mio_ulCfoNow.ub.b2;
		MB5_TxData[3]	= lev_udCarSta.ub.b3;
		MB5_TxData[4]	= lev_udCarSta.ub.b4;
		MB5_TxData[5]	= lev_udCarSta.ub.b5;
		//Other are Reserved
		MB5_TxData[6]	= 0;
		MB5_TxData[7]	= 0;
#else	
		MB5_TxData[0]	= lev_udCarCmd.ub.b0;
		MB5_TxData[1]	= lev_udCarCmd.ub.b1;
		MB5_TxData[2]	= mio_ulCfoNow.ub.b2;
		MB5_TxData[3]	= lev_udCarCmd.ub.b3;
		MB5_TxData[4]	= lev_udCarCmd.ub.b4;
		MB5_TxData[5]	= lev_udCarCmd.ub.b5;
		//Other are Reserved
		MB5_TxData[6]	= 0;
		MB5_TxData[7]	= 0
#endif	
*/
		//Start MB1 Tx
		RCAN_MB5_TX();
		//Reset Flag		
		MB5_Done = 0;		
	}			
}

void RCAN_INT_RM0(void)
{
	UBYTE tmp=0;

	if ( (RCANET.IRR.WORD  & 0x0002)==0x0002 ){		//IRR1:data frame received

		//MB2
		if ((RCANET.RXPR0.WORD&0x0004)==0x0004){ //chk MB2 Rx Flag				
			for (tmp=0;tmp<8;tmp++)
				MB2_RxData[tmp] = RCANET.MB[2].MSG_DATA[tmp];	//read data			
			MB2_Done = 1;
			RCANET.RXPR0.WORD |= 0x0004;				//clear MB2 Rx Flag		
		}
		
		//MB4
		if ((RCANET.RXPR0.WORD&0x0010)==0x0010){ //chk MB4 Rx Flag				
			for (tmp=0;tmp<8;tmp++)
				MB4_RxData[tmp] = RCANET.MB[4].MSG_DATA[tmp];	//read data		
			MB4_Done = 1;
			RCANET.RXPR0.WORD |= 0x0010;				//clear MB4 Rx Flag		
		}

		//MB6
		if ((RCANET.RXPR0.WORD&0x0040)==0x0040){ //chk MB6 Rx Flag				
			for (tmp=0;tmp<8;tmp++)
				MB6_RxData[tmp] = RCANET.MB[6].MSG_DATA[tmp];	//read data		
			MB6_Done = 1;
			RCANET.RXPR0.WORD |= 0x0040;				//clear MB6 Rx Flag		
		}		
		//if more RX MB used, add here, Sean, 03/10/10
	}	
}


void RCAN_INT_SLE0(void)
{
    if ( (RCANET.IRR.WORD&0x0100)==0x0100 ){		//IRR8:Any Tx Mailbox Empty(Transmission Done(ACK/ABT))
		//MB1
   		if ( (RCANET.TXACK0.WORD&0x0002)==0x0002 ){//chk MB1 Tx Flag
    		RCANET.TXACK0.WORD |= 0x0002;				//Clear MB1 Tx lag
    		MB1_Done = 1;							//MB1 Tx Done Flag
		}
		//MB3
   		if ( (RCANET.TXACK0.WORD&0x0008)==0x0008 ){//chk MB3 Tx Flag
    		RCANET.TXACK0.WORD |= 0x0008;				//Clear MB3 Tx lag
    		MB3_Done = 1;							//MB3 Tx Done Flag		
		}
		//MB5
   		if ( (RCANET.TXACK0.WORD&0x0020)==0x0020 ){//chk MB5 Tx Flag
    		RCANET.TXACK0.WORD |= 0x0020;				//Clear MB5 Tx lag
    		MB5_Done = 1;							//MB5 Tx Done Flag		
		}		
		
		//if more TX MB used, add here	
    }	
}


void RCAN_MB1_TX(void)
{
	UBYTE tmp;
	for (tmp=0;tmp<8;tmp++){
		RCANET.MB[1].MSG_DATA[tmp] = MB1_TxData[tmp];	//write data
	}
    RCANET.TXPR10.LONG |= 0x00000002;				//start Tx 
}


void RCAN_MB3_TX(void)
{
	UBYTE tmp;
	for (tmp=0;tmp<8;tmp++){
		RCANET.MB[3].MSG_DATA[tmp] = MB3_TxData[tmp];	//write data
	}
    RCANET.TXPR10.LONG |= 0x00000008;				//start Tx 
}

void RCAN_MB5_TX(void)
{
	UBYTE tmp;
	for (tmp=0;tmp<8;tmp++){
		RCANET.MB[5].MSG_DATA[tmp] = MB5_TxData[tmp];	//write data
	}
    RCANET.TXPR10.LONG |= 0x00000020;				//start Tx 
}
#endif

#ifdef  _PH_RCAN_C
    #undef  _PH_RCAN_C
#endif

/************************************************************************
 Copyright (c) 2007 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
