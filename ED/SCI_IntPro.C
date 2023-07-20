/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN
                  
Project: VFD-V pro

Filename: Sample.C

Partner Filename: Sample.H

Description: This is a sample code.

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:
	
History:
===============================================================*/
#ifndef _SCI_IntPro_C
	#define _SCI_IntPro_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

/* Constant Table =============================================*/

// [ Car Group Control, DINO, 08/19/2010
void SCI12_RxINT(void)
{
#if 0
    UBYTE Rx0BufTmp, imaskValue;	
	
    SCI0.SCSSR.BIT.RDRF = 0;
    Rx0BufTmp = SCI0.SCRDR;
    RTU_CNT0 = 0;
    if ((SCI0.SCSSR.BYTE & 0x38)!=0){
		InitSCI0();		
    }
    else{
		Com_WatchDog0 = 0;	    
	    
		if ((Rx0CNT < RX_LENGTH)||(Rx0CNT==0xFF))
	    	Rx0CNT = Rx0CNT + 1;
	    
		RxBuf_0[Rx0CNT] = Rx0BufTmp;

		// [ DINO, 04/01/2010
		if (ASC_RTU0==0){           //ASC_RTU: 0=ASC mode; 1=RTU mode
	    	RxBuf_0[Rx0CNT] = RxBuf_0[Rx0CNT] & 0x7F;
	    	if (RxBuf_0[Rx0CNT]==STX){
				Rx0CNT = 0;
				RxBuf_0[0] = STX;
	    	}
	    	else if ((RxBuf_0[Rx0CNT]==LF_0A)&&(RxBuf_0[0]==STX)&&(Rx0CNT>=5)){
				if (RxBuf_0[Rx0CNT-1]==CR_0D){
	    	    	imaskValue = DINT();
	    	    	SCI0.SCSCR.BIT.RIE = 0;
		    		RX_OK0 = 1;
	    	    	EINT(imaskValue);
				}
				else{
		    		Rx0CNT = 0xFF;
				}
	    	}
		}// if (ASC_RTU==0)
		else{
		// ]
			RTU_RXF0 = 0;
		}
    }
    if (Rx0CNT >= RX_LENGTH)                  // out of rxd length
        Rx0CNT = 0xFF;	
#endif
}


void SCI12_TxINT(void)
{
#if 0 
    SendCNT0++;

    if (SendCNT0<=Tx0CNT){
        Com_WatchDog0 = 0;
        
        SCI0.SCTDR = TxBuf_0[SendCNT0];
        SCI0.SCSSR.BIT.TDRE = 0;        
    }
    else {
        SCI0.SCSCR.BIT.TEIE = 0;
        InitSCI0();
    }
    RTU_CNT0 = 0;		// clr rtu space timer //
    SCI0_TodCNT = 0;	// clr time out detection counter.
#endif
}
// ]


void SCI3_RxINT(void)
{
    UBYTE Rx3BufTmp;	
	
//SCI2>SCIF3, Sean, 01/20/2010
    //SCI3.SSR.BIT.RDRF = 0;
    Rx3BufTmp = SCI3.RDR;
    RTU_CNT3 = 0;
    //if (SCI1.SCSSR.BYTE & 0x90)//||
    	//(SCI1.SCLSR.WORD & 0x0001))	//ER,ORRE,BRK detection
    if ((SCI3.SSR.BYTE & 0x38)!=0)
    	InitSCI3();

    else{
		Com_WatchDog3 = 0;	    
	    
		if ((Rx3CNT < RX_LENGTH)||(Rx3CNT==0xFF))
	    	Rx3CNT = Rx3CNT + 1;
	    
		RxBuf_3[Rx3CNT] = Rx3BufTmp;
	    
		if (ASC_RTU3==0){           //ASC_RTU: 0=ASC mode; 1=RTU mode
	    	RxBuf_3[Rx3CNT] = RxBuf_3[Rx3CNT] & 0x7F;
	    	if (RxBuf_3[Rx3CNT]==STX){
				Rx3CNT = 0;
				RxBuf_3[0] = STX;
	    	}
	    	else if ((RxBuf_3[Rx3CNT]==LF_0A)&&(RxBuf_3[0]==STX)&&(Rx3CNT>=5)){
				if (RxBuf_3[Rx3CNT-1]==CR_0D){
	    	    	DINT();
	    	    	SCI3.SCR.BIT.RIE = 0;
		    		RX_OK3 = 1;
	    	    	EINT();
				}
				else{
		    		Rx3CNT = 0xFF;
				}
	    	}
		}// if (ASC_RTU==0)
		else{
			RTU_RXF3 = 0;
		}
    }
    if (Rx3CNT >= RX_LENGTH)                  // out of rxd length
        Rx3CNT = 0xFF;	
}


void SCI3_TxINT(void)
{
    SendCNT3++;
    if (SendCNT3<=Tx3CNT){
        Com_WatchDog3 = 0;
//SCI2>SCIF3, Sean, 01/20/2010        
        SCI3.TDR = TxBuf_3[SendCNT3];
		//SCI1.SSR.BIT.TDRE = 0;  
    }
    else {
        SCI3.SCR.BIT.TEIE = 0;	//no TEND, Sean, 02/10/2010
        // [ Transmit FIFO Data Empty, delay 1byte time then Initial SCIF3, DINO, 03/02/2010
        SCI3_ubCNT = 0;
        TXD_RTS3 = 1;
		InitSCI3();
		// ]
    }

    RTU_CNT3 = 0;                  // clr rtu space timer //
    SCI3_TodCNT = 0;               // clr time out detection counter.
}


void SCI2_RxINT(void)
{
    UBYTE Rx2BufTmp;	
	
//SCI2>SCIF3, Sean, 01/20/2010
    //SCIF3.SCFSR.BIT.RDF = 0;
    Rx2BufTmp = SCI2.RDR;
    RTU_CNT2 = 0;
    //if ((SCIF3.SCFSR.WORD & 0x0090)||
    	//(SCIF3.SCLSR.WORD & 0x0001))	//ER,ORRE,BRK detection
    if ((SCI2.SSR.BYTE & 0x38)!=0)
    	InitSCI2();
    else{
		Com_WatchDog2 = 0;	    
	    
		if ((Rx2CNT < RX_LENGTH)||(Rx2CNT==0xFF))
	    	Rx2CNT = Rx2CNT + 1;
	    
		RxBuf_2[Rx2CNT] = Rx2BufTmp;
	    
		if (ASC_RTU2==0){           //ASC_RTU: 0=ASC mode; 1=RTU mode
	    	RxBuf_2[Rx2CNT] = RxBuf_2[Rx2CNT] & 0x7F;
	    	if (RxBuf_2[Rx2CNT]==STX){
				Rx2CNT = 0;
				RxBuf_2[0] = STX;
	    	}
	    	else if ((RxBuf_2[Rx2CNT]==LF_0A)&&(RxBuf_2[0]==STX)&&(Rx2CNT>=5)){
				if (RxBuf_2[Rx2CNT-1]==CR_0D){
	    	    	DINT();
	    	    	SCI2.SCR.BIT.RIE = 0;
		    		RX_OK2 = 1;
	    	    	EINT();
				}
				else{
		    		Rx2CNT = 0xFF;
				}
	    	}
		}// if (ASC_RTU==0)
		else{
			RTU_RXF2 = 0;
		}
    }
    if (Rx2CNT >= RX_LENGTH)                  // out of rxd length
        Rx2CNT = 0xFF;	
}


void SCI2_TxINT(void)
{
    SendCNT2++;
    if (SendCNT2<=Tx2CNT){
        Com_WatchDog2 = 0;
//SCI2>SCIF3, Sean, 01/20/2010        
        SCI2.TDR = TxBuf_2[SendCNT2];
        //SCIF3.SCFSR.BIT.TDFE = 0;        
    }
    else {
        SCI2.SCR.BIT.TIE = 0;	//no TEND, Sean, 02/10/2010
        //SCI2.SCR.BIT.TEIE = 0;
         //SCI2.SCR.BIT.TE = 0;
        // [ Transmit FIFO Data Empty, delay 1byte time then Initial SCIF3, DINO, 03/02/2010
        SCI2_ubCNT = 0;
        TXD_RTS2 = 1;
        TXD_TDFE = 1;
		InitSCI2();
		// ]
    }

    RTU_CNT2 = 0;                  // clr rtu space timer //
    SCI2_TodCNT = 0;               // clr time out detection counter.
}

// [ SCI Communication, Dino, 03/23/2010

void SCI0_RxINT(void)
{

    UBYTE Rx0BufTmp,ubRxCnt;
    //SCI4.SCSSR.BIT.RDRF = 0;
    Rx0BufTmp = SCI0.RDR;    
    
	if ((pr[DEBUG_F1]&0x0018) == 0x0018){	// Bit 3: Enable all ICT test, Synchronous Series Communication
	}
	else if ((pr[DEBUG_F1]&0x0018)==0x0008 /*|| pr[PG_TYPE]==SIN_HIPER*/){	// Pr.15-00=8, ASC for ICT test, Modify by DINO, 09/19/2008	//[For IED PG-Card, Sampo, 01/11/2010]
		RTU_CNT0 = 0;
		if ((SCI0.SSR.BYTE & 0x38)!=0){
			InitSCI0();	
		}
		else{
			Com_WatchDog0 = 0;	    
		    
			if ((Rx0CNT < RX_LENGTH)||(Rx0CNT==0xFF))
		    	Rx0CNT++;
		    
			RxBuf_0[Rx0CNT] = Rx0BufTmp;
		    
			if (ASC_RTU0==0){           //ASC_RTU: 0=ASC mode; 1=RTU mode
		    	RxBuf_0[Rx0CNT] = RxBuf_0[Rx0CNT] & 0x7F;
		    	if (RxBuf_0[Rx0CNT]==STX){
					Rx0CNT = 0;
					RxBuf_0[0] = STX;
		    	}
		    	else if ((RxBuf_0[Rx0CNT]==LF_0A)&&(RxBuf_0[0]==STX)&&(Rx0CNT>=5)){
					if (RxBuf_0[Rx0CNT-1]==CR_0D){
		    	    	DINT();
						SCI0.SCR.BIT.RIE = 0;
			    		RX_OK0 = 1;
		    	    	EINT();
					}
					else
			    		Rx0CNT = 0xFF;	
		    	}
			}// if (ASC_RTU==0)
			else
				RTU_RXF0 = 0;
		}
		if (Rx0CNT >= RX_LENGTH)                  // out of rxd length
                Rx0CNT = 0xFF;	
    }
    else {
		switch(pr[PG_TYPE]){  //[For IED PG-Card, Sampo, 01/11/2010]
			case SIN_ENDAT:
				ubRxCnt = 5;
				break;
			case SIN_HIPER:
				ubRxCnt = 5;
				break;
			case SIN_SIN:
				ubRxCnt = 9;
				break;
			default:
				ubRxCnt = 17;
				break;
		}
		
		Rx0CNT++;	// cnt++ before read value // fix pghsd1 code, Sean, 06/01/2012
		if (vfd_btPGHSD1Set==1){	// fix pghsd1 code, Sean, 06/01/2012
			hsd_ubRxBuf[hsd_ubRxCnt] = Rx0BufTmp; 

			hsd_ubRxCnt++;
			ubRxCnt = HSD_RX_MAX_CNT_CONST;
			if(hsd_ubRxCnt>ubRxCnt){ 	 				/*the receive count number is  ok*/

				hsd_ubRxTxSta =HSD_CHECK_STATUS_CONST;	/*set status to  check the CRC*/
			}
		}
		else{ //[delete PGHSD, Lyabryan, 2015/12/17]
			RxBuf_0[Rx0CNT] = Rx0BufTmp;
		}	
		
		if (Rx0CNT>=/*7*/ubRxCnt){    //[For IED PG-Card, Sampo, 01/11/2010]
			SCI0.SCR.BIT.RE = 0;
			//Rx4CNT = 0xFF;
			//SCIDIR4Flag = 0;  // Transmit Data	// test
			//SCI4_DIR = SCIDIR4Flag;				// test
		} 			
    }
}


void SCI0_TxINT(void)
{    
	if ((pr[DEBUG_F1]&0x0008)==0x0008 /*|| pr[PG_TYPE]==SIN_HIPER*/){	// Bit 3: Enable all ICT test, Asynchronous Series Communication	//[For IED PG-Card, Sampo, 01/11/2010]
        SendCNT0++;
        if (SendCNT0<=Tx0CNT){
            Com_WatchDog0 = 0;            
            SCI0.TDR = TxBuf_0[SendCNT0];
            //SCI0.SCSSR.BIT.TDRE = 0;        
        }
        else {							// Transmit End
            SCI0.SCR.BIT.TEIE = 0;
            InitSCI0();
            // [ 05/19/2009
            if (pr[PG_TYPE] == SIN_HIPER){
            	SCIDIR0Flag = 1;		// DIR=Receive
            }
            // ]
        }
        RTU_CNT0 = 0;					// clr rtu space timer
        SCI0_TodCNT = 0;				// clr time out detection counter.
	}
    else { 	
		SendCNT0++;
        if (SendCNT0<Tx0CNT){
            Com_WatchDog0 = 0;
            //-- test, 08/27/2008
            if ( SendCNT0==(Tx0CNT-1) )
        		SCI0.SCR.BIT.TIE  = 0;
        	//-- End test
        	
        	if (vfd_btPGHSD1Set==1)	// fix pghsd1 code, Sean, 06/01/2012
        		SCI0.TDR = hsd_ubTxBuf[SendCNT0];
        	else //[delete PGHSD, Lyabryan, 2015/12/17]
            	SCI0.TDR = TxBuf_0[SendCNT0];
            	
            //SCI0.SSR.BIT.TDRE = 0;        
        }
        else{
        	
			//--- Add by DINO, 09/25/2008
			DINT();
			SCI0_DIR = 1;	// CLK low
			EINT();	/*  */
			
			DINT();
			SCI0_DIR = 0;	// CLK high
			EINT();	/*  */
			//--- End on 09/25/2008
        
        	//InitSCI4();			//mask, Sean
        	SCI0.SCR.BIT.TEIE = 0;
        	SCI0.SCR.BIT.RIE = 1;	//Sean
			SCI0.SCR.BIT.RE = 1;
		}
    }
}


#ifdef _SCI_IntPro_C
	#undef _SCI_IntPro_C
#endif

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
