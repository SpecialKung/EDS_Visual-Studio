/*===============================================================
Author: Delta Electronic, INC. IABU, DEI
                  
Project: VFD-IED

Filename: SCI4_PGComm.C

Partner Filename: SCI4_PGComm.H

Description: This SCI4 is for PG Card Communication

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:
    
History:
===============================================================*/
#ifndef _SCI4_PGComm_C
    #define _SCI4_PGComm_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
//#include "PR_Romdata.h"

/* Constant Table =============================================*/
void SCI0_PGHSD_Comm(void){	// PGHSD comm replacement, Sean, 01/09/2012
	UBYTE ubReturn,ubRxCnt;
	UWORD_UNION uwCRC;
	
	if ((pr[DEBUG_F1]&0x0008)!=0x0008){	//normal mode
		if (IED_PG_START &&
			((pr[PG_TYPE] == SIN_ENDAT)	||
			 (pr[PG_TYPE] == SIN_SIN)	||
			 (pr[PG_TYPE] == SIN_HIPER)	||
			 ((pr[DEBUG_PG]&0x0020)!=0))){			//[For IED PG-Card, Sampo, 01/11/2010]
			if ((ASC_RTU0==1)||((pr[DEBUG_PG]&0x0020)!=0)){	//RTU mode			
				if (RX_OK0==1){				
					
					Tx0CNT = 4;
					
					//Byte0=============================================  
					ubReturn = 0x00;
					if (0){	// CPLD_RST, reserved
						ubReturn |= 0x80;
					}
	
					if ((pr[DEBUG_PG]&0x0040)!=0)	// PG_LOSS TEST
						ubReturn &= 0xF7;     
					else
					  ubReturn |= 0x08;     
					  
					if ((pr[PG_MODE]&0x0200)==0)	// Output mode, reserved
						ubReturn &= 0xBF;     //A:  pulse, B:pulse
					else
					  ubReturn |= 0x40;     //A:  pulse, B;level
					  
					if ((pr[PG_MODE]&0x0100)==0)	// Intput mode, reserved
						ubReturn &= 0xDF;     //A: pulse; B: pulse
					else
					  ubReturn |= 0x20;     //A: pulse; B: level
					  
					// disable, useless // PGHSD 1387 offset test, Sean, 11/30/2011  
					//if (IED_PG_RESET){  // Encoder Error Reset
					//	ubReturn |= 0x10;
					//	IED_PG_RESET = 0;
					//}
					
					// PGHSD 1387 offset test, Sean, 11/30/2011
					if ((pr[DEBUG_PG]&0x0080)!=0){
						ubReturn |= 0x10;
					}
					else{
						ubReturn &= ~0x10;
					}
	
					if((pr[DEBUG_PG]&0x0020)==0){
						switch(pr[PG_TYPE]){	// PG type id
							case SIN_ENDAT:
								ubReturn |= 0x00;
								break;
							case SIN_HIPER:
								ubReturn |= 0x01;
							
								break;
							case SIN_SIN:
								ubReturn |= 0x02;
								break;
							default:
								ubReturn |= 0x07;
								break;
						}
					}
					else{
						   ubReturn |= 0x03; //ICT_TEST
					}
	
					TxBuf_0[0] = ubReturn;
					
					//Byte1============================================ 
					TxBuf_0[1] = (SWORD)(255 - (pr[PG_MODE]&0x00ff));
					
					//Byte2!BByte3=====================================
					uwCRC.uw = CRC16(TxBuf_0,2);
					if(((pr[DEBUG_PG]&0x0020)!=0) && ((pr[DEBUG_PG]&0x0004)!=0)){
						if((pr[DEBUG_PG]&0x0018)==0x0000)
							TxBuf_0[2] = 0x01;
						else if((pr[DEBUG_PG]&0x0018)==0x0008)
							TxBuf_0[2] = 0x02;
						else if((pr[DEBUG_PG]&0x0018)==0x0010)
							TxBuf_0[2] = 0x03;
						else if((pr[DEBUG_PG]&0x0018)==0x0018)
							TxBuf_0[2] = 0x04;
					}
					else{
						TxBuf_0[2] = uwCRC.ub.hi;
					}
					TxBuf_0[3] = uwCRC.ub.low;
					TXD_RTS0 = 1;				// ready to send
	   
					TxD_Data_0();
				}
				else {
					//RTU_RxOKChk_4();
	            	
					switch(pr[PG_TYPE]){  //[For IED PG-Card, Sampo, 01/11/2010]
			    		case SIN_ENDAT:
			   				ubRxCnt = 4;
			   			break;
			    		case SIN_HIPER:
			   				ubRxCnt = 4;
			   			break;
			    		case SIN_SIN:
			   				ubRxCnt = 8;
			   			break;
			    		default:
			   				ubRxCnt = 16;//For ICT
			   			break;
					}
				 
					if ((Rx0CNT>=ubRxCnt)&&(Rx0CNT!=0xff)){    //[For IED PG-Card, Sampo, 01/11/2010]
						if (TB_uwPg_Cnt>=10){
							Rx0CNT = 0xff;							     				   	   	    
	   						RxD_Data_0();
	   						RX_OK0 = 1;
	   					}
	   				}
				}
				if (Com_WatchDog0>20){    	// Watch  g Timer > 0.5 sec //[For IED PG-Card, Sampo, 01/11/2010]
					InitSCI0();
					uwPG_OverTimeCnt++;         //[For IED PG-Card, Sampo, 02/25/2010]
					if(((pr[DEBUG_PG]&0x0020)==0) &&(uwPG_OverTimeCnt>15) && ((pr[DEBUG_PG]&0x0001)!=0x0001)){
						if(Error==0)
						    Error = PGHL_ERR;  //[modify Error code,Lyabryan,2016/07/21]
					    	//Error = PGF5_ERR;
					    IED_PG_ERR_OVERTIME = 1;
					}
				}
			}
		}
	}
	else{	// for ICT Test
		if (ASC_RTU0==1){	//RTU mode
	    	RTU_RxOKChk_0();	
		}				
	}	
}

void RTU_RxOKChk_0(void)	// add pghs01, Sean, 12/06/2010
{
    DINT(); 
    // RTU_RXF=0, data receiving, and RTU_CNT0 count in 100us	
    if (RTU_RXF0==0 && RTU_CNT0>=RTU_Silent0){
		if ((pr[DEBUG_F1]&0x0008) == 0x0008){
        	if (Rx0CNT >= 7){			// 7 characters are RTU Minimum string
        	    SCI0.SCR.BIT.RIE = 0;
        	    RX_OK0 = 1;				// Check RTU mode End of ETX            
        	}
        	else{
	    		if (Rx0CNT!=0)
	    		Rx0CNT = 0xFF;
        	}			
		}
		else{
        	if (Rx0CNT >= 8){			// 7 characters are RTU Minimum string
        	    SCI0.SCR.BIT.RIE = 0;
        	    RX_OK0 = 1;				// Check RTU mode End of ETX            
        	}
        	else{
	    		if (Rx0CNT!=0)
	    		Rx0CNT = 0xFF;
        	}			
		}


        RTU_CNT0 = 0;
        RTU_RXF0 = 1;
    }
    EINT();
}

void Init_TxData_0(UBYTE Data_CNT)//Initial TxD from RxD	// add pghs01, Sean, 12/06/2010
{
    UWORD_UNION CRC_Result1;

	CRC_Result1.uw = 0xFFFF;
	if (COM0Err!=0) {
		RxBuf_0[1] |= 0x80;		// force command code bit7=1 (0x8y) //
		RxBuf_0[2] = COM0Err;	// exception code //
		Data_CNT = 2;
	}

    if (ASC_RTU0 == 0){			// ASCII mode, 
        PG_HEX2ASC(Data_CNT);
        TxBuf_0[Tx0CNT] = CR_0D;
        Tx0CNT++;
        TxBuf_0[Tx0CNT] = LF_0A;
    }
    else {						// RTU mode
    	if ((pr[DEBUG_F1]&0x0008) == 0x0008){  // ICT Test
    		Data_CNT -= 2;
    	}
        CRC_Result1.uw = CRC_CHECK_0(Data_CNT);
        if ((pr[DEBUG_F1]&0x0008) == 0x0008){
        	Tx0CNT =  Data_CNT + 1;
        	TxBuf_0[Tx0CNT] = CRC_Result1.ub.low;
        	Tx0CNT++;
        	TxBuf_0[Tx0CNT] = CRC_Result1.ub.hi;
        }
    }
    TXD_RTS0 = 1;				// ready to send
}

void PG_HEX2ASC(UBYTE byte_cnt)
{
    UBYTE data,j,bx,lrc_data=0;

    TxBuf_0[Tx0CNT] = 0x3a;
    Tx0CNT++;
    for (j=0;j<=byte_cnt;j++) {
        data = RxBuf_0[j];
        lrc_data += data;              // LRC data

        bx = data>>4;
        if (bx>=0x0a)                // 0x0a<=low_nb<=0x0f //
            TxBuf_0[Tx0CNT] = bx + 0x37;
        else                         // 0x0a>low_nb //
            TxBuf_0[Tx0CNT] = bx + 0x30;    //* nibble ->ASCII, store to buffer */
        
        Tx0CNT++;

        bx = data&0x0f;
        if (bx>=0x0a)                // 0x0a<=low_nb<=0x0f //
            TxBuf_0[Tx0CNT] = bx + 0x37;
        else                         // 0x0a>low_nb //
            TxBuf_0[Tx0CNT] = bx + 0x30;    //* nibble ->ASCII, store to buffer */
        Tx0CNT++;
    }

    lrc_data = 0 - lrc_data;           //* lrc_data=(~lrc_data)+1; */
    bx = lrc_data>>4;
    if (bx>=0x0a)                  // 0x0a<=low_nb<=0x0f //
        TxBuf_0[Tx0CNT] = bx + 0x37;
    else                           // 0x0a>low_nb //
        TxBuf_0[Tx0CNT] = bx + 0x30;      //* nibble ->ASCII, store to buffer */
    
    Tx0CNT++;

    bx = lrc_data & 0x0f;
    if (bx>=0x0a)                  // 0x0a<=low_nb<=0x0f //
        TxBuf_0[Tx0CNT] = bx + 0x37;
    else                           // 0x0a>low_nb //
        TxBuf_0[Tx0CNT] = bx + 0x30;      //* nibble ->ASCII, store to buffer */
    
    Tx0CNT++;
}

UWORD CRC_CHECK_0(UBYTE CRC_CNT)	// add pghs01, Sean, 12/06/2010
{
	UWORD_UNION CRC_Result;
	UBYTE i,j;

	CRC_Result.uw = 0xffff;

	for (i=0;i<=CRC_CNT; i++){
		if ((pr[DEBUG_F1]&0x0008) == 0x0008){
			TxBuf_0[i] = RxBuf_0[i];
    		CRC_Result.ub.low ^= RxBuf_0[i];   	
    	}	
    	else{
			TxBuf_0[i] = TxD_Data_0_Gen(i);
			CRC_Result.ub.low ^= TxBuf_0[i];   	    		
    	}
		
    	for (j=0;j<8;j++) {
		    if (CRC_Result.uw & 0x01)
		        CRC_Result.uw = (CRC_Result.uw >>1 ) ^ 0xa001;
		    else
		        CRC_Result.uw = CRC_Result.uw >> 1;
		}
	}

	return(CRC_Result.uw);
}

void TxD_Data_0(void)//Ready to Send
{   
    if ((TXD_RTS0==1)&&(RTU_CNT0>=100/*pr[REM_DT]*/)){   //Ready To Send
    //if (TXD_RTS4==1){   //Ready To Send	// add pghs01, Sean, 12/06/2010
        Com_WatchDog0 = 0;
        RTU_CNT0 = 0;
        SendCNT0 = 0;
        TXD_RTS0 = 0;
        DINT();     
        SCI0.TDR = TxBuf_0[SendCNT0];
        //SCI0.SSR.BIT.TDRE = 0;
        SCI0.SCR.BIT.TEIE = 1;
        EINT();
        
		if ((pr[DEBUG_F1]&0x0008) != 0x0008){
        	RX_OK0 = 0;
		}
    }
}

UBYTE TxD_Data_0_Gen(UBYTE ubIdx){	// add pghs01, Sean, 12/06/2010
	
	UBYTE ubReturn;
	ubReturn = 0;
	
	switch(ubIdx){
		case 3:
			ubReturn = 0x55;
			break;
		case 0:
			if (0){	// CPLD_RST, reserved
				ubReturn |= 0x80;
			}
			if (0){	// Output mode, reserved
				ubReturn |= 0x40;
			}
			if (0){	// Output mode, reserved
				ubReturn |= 0x20;
			}
			if (pr[PG_TYPE]==SIN_ENDAT){	// 1313 mode select, reserved
				ubReturn |= 0x08;
			}
			switch(pr[PG_TYPE]){	// PG type id
				case SIN_ENDAT:
					ubReturn |= 0x00;
					break;
				case SIN_HIPER:
					ubReturn |= 0x01;
					break;
				case SIN_SIN:
					ubReturn |= 0x02;
					break;
				default:
					ubReturn |= 0x07;
					break;
			}
			break;
		case 2:
			ubReturn = 1;	// freq. div. , reserved
			break;
		default:
			ubReturn = 0;
			break;
	}
	
	return ubReturn;
}



void RxD_Data_0(void)	// //[For IED PG-Card, Sampo, 02/25/2010]
{
	UWORD_UNION uwCRC;
	//UBYTE_UNION ubPG_State;
	
	switch(pr[PG_TYPE]){
		case SIN_ENDAT:
			uwCRC.uw = CRC16(RxBuf_0,3);
			if(uwCRC.ub.hi==RxBuf_0[3] && uwCRC.ub.low==RxBuf_0[4]){
				IED_PG_ERR_CRC = 0;
				if((RxBuf_0[0]&0x01)==0x01)
					if(RUNNING == STOP)
						IED_PG_ERR_AB = 1;
					else
						IED_PG_ERR_AB = 0;   
				if((RxBuf_0[0]&0x02)==0x02)
					IED_PG_ERR_TYPE = 1;
				else
					IED_PG_ERR_TYPE = 0;  
				if((RxBuf_0[0]&0x04)==0x04)      
					IED_PG_ERR_ENDAT = 1;			       	   
				else
					IED_PG_ERR_ENDAT = 0;
				uwEndatPosition = (UWORD)RxBuf_0[1]+ (UWORD)(RxBuf_0[2]<<8);
			}
			else
			IED_PG_ERR_CRC = 1;
		break;
		case SIN_HIPER:
			uwCRC.uw = CRC16(RxBuf_0,3);
			if(uwCRC.ub.hi==RxBuf_0[3] && uwCRC.ub.low==RxBuf_0[4]){
				IED_PG_ERR_CRC = 0;
				if((RxBuf_0[0]&0x01)==0x01)
					if(RUNNING == STOP)
						IED_PG_ERR_AB = 1;
					else
						IED_PG_ERR_AB = 0;
				if((RxBuf_0[0]&0x02)==0x02)
					IED_PG_ERR_TYPE = 1;
				else
					IED_PG_ERR_TYPE = 0;
				if((RxBuf_0[0]&0x04)==0x04)
					IED_PG_ERR_HIPER = 1;
				else
					IED_PG_ERR_HIPER = 0;
				uwHiperPosition = (UWORD)RxBuf_0[2]+ (UWORD)(RxBuf_0[1]<<8);
			}
			else
				IED_PG_ERR_CRC = 1;
		break;
		case SIN_SIN:
			uwCRC.uw = CRC16(RxBuf_0,7);
			
			if(uwCRC.ub.hi==RxBuf_0[7] && uwCRC.ub.low==RxBuf_0[8]){
				if((RxBuf_0[0]&/*0x02)==0x02*/0x04)==0x04){	// PGHSD 1387 diff/offset ver, Sean, 11/30/2011
					IED_PG_ERR_Z = 1;
				}
				else{				    
					IED_PG_ERR_Z = 0;
				}   
				if((RxBuf_0[0]&0x02)==0x02)
					IED_PG_ERR_SIN = 1;
				else
					IED_PG_ERR_SIN = 0;
				if((RxBuf_0[0]&0x01)==0x01)
					if(RUNNING == STOP)
						IED_PG_ERR_AB = 1;				       	      			       	   
					/*else				       	  	   
						IED_PG_ERR_AB = 0;*/

				//if((pr[PG_MODE]&0x0400)!=0){    // Debug by Sampo, 2011,02,20 //[For IED PG-Card, Sampo, 02/25/2010]
                if((pr[PG_C_TYPE]&0x0001)!=0){   //[change parameter to normal group, Bernie, 2014/02/14]
					Pgc_uwCne = RxBuf_0[1] + (((UWORD)RxBuf_0[3]&0x0f) << 8);
					Pgc_uwCpo = RxBuf_0[2] + (((UWORD)RxBuf_0[3]&0xf0) << 4);
				}
				else{
					Pgc_uwCpo = RxBuf_0[1] + (((UWORD)RxBuf_0[3]&0x0f) << 8);
					Pgc_uwCne = RxBuf_0[2] + (((UWORD)RxBuf_0[3]&0xf0) << 4);
				}
				Pgc_uwDpo = RxBuf_0[4] + (((UWORD)RxBuf_0[6]&0x0f) << 8);
				Pgc_uwDne = RxBuf_0[5] + (((UWORD)RxBuf_0[6]&0xf0) << 4);
			}
			else{
				IED_PG_ERR_CRC = 0;
			}	
		break;
				   
		default:   //For ICT TEST
			uwCRC.uw = CRC16(RxBuf_0,15);
			if(uwCRC.ub.hi==RxBuf_0[15] && uwCRC.ub.low==RxBuf_0[16]){
				Pgc_uwCpo = RxBuf_0[0] + (((UWORD)RxBuf_0[2]&0x0f) << 8);
				Pgc_uwCne = RxBuf_0[1] + (((UWORD)RxBuf_0[2]&0xf0) << 4);
				Pgc_uwDpo = RxBuf_0[3] + (((UWORD)RxBuf_0[5]&0x0f) << 8);
				Pgc_uwDne = RxBuf_0[4] + (((UWORD)RxBuf_0[5]&0xf0) << 4);
				Pgc_uwApo = RxBuf_0[6] + (((UWORD)RxBuf_0[8]&0x0f) << 8);
				Pgc_uwAne = RxBuf_0[7] + (((UWORD)RxBuf_0[8]&0xf0) << 4);
				Pgc_uwBpo = RxBuf_0[9] + (((UWORD)RxBuf_0[11]&0x0f) << 8);
				Pgc_uwBne = RxBuf_0[10] + (((UWORD)RxBuf_0[11]&0xf0) << 4);
				Pgc_uwRpo = RxBuf_0[12] + (((UWORD)RxBuf_0[14]&0x0f) << 8);
				Pgc_uwRne = RxBuf_0[13] + (((UWORD)RxBuf_0[14]&0xf0) << 4);
			}
		break;
		}
	SCI0.SCR.BIT.RE = 1;
}

UWORD CRC16(UBYTE *dt, UWORD length)    //[For IED PG-Card, Sampo, 01/11/2010]
{
	UWORD crc = 0xffff;
	UWORD i, j, flag;
	for (i=0; i<length; i++)
	{

		crc = crc^dt[i];
		for (j=0; j<8; j++)
		{
		  flag = crc&1;
		  crc = crc>>1;
		  if (flag)
		    crc = crc^0xa001;
		}
	}
	return crc;
}

// add pghsd1 code, Sean, 05/28/2012
// to EndOfFile

/*********************************************************************************************
 Function:hdh_AdStartSci2R() 
 Description: Cdif and Ddif converter start  for test of absolute position 
*********************************************************************************************/
void hsd_ProssTxRxTb1(HSD_ST_IED_SEND_IN*in,HSD_ST_PG_REPLY_OUT*out)
{  
	//uwtest4 = hsd_ubRxTxSta;

	switch(hsd_ubRxTxSta){
		
		case HSD_TX_STATUS_CONST:  /* generater CRC and fist data TX */
		{
			hsd_TxStaPro();
			hsd_ubRxTxSta = HSD_RX_STATUS_CONST;
			hsd_ubTxTimCnt++;
			break ;
		}
		case HSD_RX_STATUS_CONST: /*receive data  */
		{
			hsd_ubTxTimCnt++ ;
            hsd_uwTxTimOutCnt++; //[PG card can't work, Bernie, 2015/09/21]
            if(hsd_uwTxTimOutCnt > 230){ //[PG card can't work, Bernie, 2015/09/21]
                if(HSDTIMEOUT == 1){
                    hsd_uwTxTimOutCnt = 0;
                    hsd_uwRxTimOutCnt = 0;
                    HSDTIMEOUT = 0;
                }
                else{ //[PG card can't work, Bernie, 2015/09/21]
                    hsd_uwTxTimOutCnt = 0;
                    hsd_uwRxTimOutCnt = 0;
                    if(((pr[DEBUG_PG]&0x0100) == 0x0000) && Error==0)
                        Error = PGF5_ERR;
                    HSDTIMEOUT = 0;
                }
            }
            
			if(hsd_ubTxTimCnt >= HSD_NOR_TIME_DELAY_CONST){   /*delay time is check*/
				hsd_ubRxTxSta = HSD_ERR_STATUS_CONST;
				/* the error  time out of PGHSD replay*/
				hsd_stPgReplyOut.ubErrSign |= HSD_TIME_OUT_PG_RX_ERR_CONST;
				if(hsd_stPgReplyOut.ubErrTiOutCnt<HSD_MAX_ERR_CNT_CONST ){
					hsd_stPgReplyOut.ubErrTiOutCnt++;
				}
				else{
				}
				hsd_ubErrClcTiOutCnt  = HSD_ERR_CLEAR_MAX_CONST;
			}
			else{
			}
			break ;
		}
		case HSD_CHECK_STATUS_CONST:  /*check the receive data*/
		{
		    HSDTIMEOUT = 1; //[PG card can't work, Bernie, 2015/09/21]
			hsd_ubTxTimCnt++ ;
            //if(hsd_uwTxTimOutCnt>0)
                hsd_uwRxTimOutCnt++; //[PG card can't work, Bernie, 2015/09/21]
            //if(hsd_uwTxTimOutCnt != 0){
                
                //hsd_uwRxTimOutCnt = 0;
            //}
			hsd_RxStaPro();
			/*clear the error of  time out  */
			hsd_stPgReplyOut.ubErrSign &= 0xDF;
			if(hsd_ubErrClcTiOutCnt >0){
				hsd_ubErrClcTiOutCnt--;
			}
			else{
				hsd_stPgReplyOut.ubErrTiOutCnt = 0; 
			}
			break;
		}
		case HSD_DELAY_STATUS_CONST:  /*delay time count */
		{
			hsd_ubTxTimCnt++ ;
			if(hsd_ubTxTimCnt >= HSD_NOR_TIME_DELAY_CONST){   /*delay time is check*/
				hsd_ubTxTimCnt = 0 ;
				hsd_ubRxTxSta = HSD_TX_STATUS_CONST;
				/*reset variable of receive count */
				hsd_ubRxCnt = 0;
				Rx0CNT = 0xFF;
			}
			break;
		}
		case HSD_ERR_STATUS_CONST:  /*the error when  timer over of receive or  CRC error*/
		{
			hsd_ubTxTimCnt++ ;
			if(hsd_ubTxTimCnt >= HSD_ERR_TIME_DELAY_CONST){   /*delay time is check*/
				hsd_ubTxTimCnt = 0 ;
				hsd_ubRxTxSta = HSD_TX_STATUS_CONST;
				/*reset variable of receive count */
				hsd_ubRxCnt = 0;
				Rx0CNT = 0xFF;
				/*clear the SCI4  ERROR INTERRUPT */
				SCI0.SSR.BYTE &= 0xC7;
			}
			else{
			}
			break;
		}
		default :
		{
			hsd_ubRxTxSta = HSD_TX_STATUS_CONST ;
			/*reset variable of receive count */
			hsd_ubRxCnt = 0;
			Rx0CNT = 0xFF;
			break;
		}
	}
	
	 /* the PGloss2 testing at every turn*/
	if(HSD_PGLSS2_REG_MACRO == HSD_PGLOSS2_VALID_CONST){
		hsd_stPgReplyOut.ubPgLoss2 =1;
	}
	else{
		hsd_stPgReplyOut.ubPgLoss2 =0;
	}
}

/*********************************************************************************************
 Function: 
 Description: Cdif and Ddif converter start  for test of absolute position 
*********************************************************************************************/
void hsd_TxStaPro(void)
{
	UWORD_UNION  uwTemp1 ;
	/*the TX data save to the buffer of TX*/
	hsd_ubTxBuf[0]=hsd_stIedSendIn.ubEndTyp ;
	hsd_ubTxBuf[1]=hsd_stIedSendIn.ubDivFre ;
	/*the last receive data send to TX*/
	hsd_ubTxBuf[2]= hsd_ubRxBuf[2] ;
	/*genrater the  CRC*/
	uwTemp1.uw = CRC16(&hsd_ubTxBuf[0], 3) ;
	/*CRC value assignment */
	//in->stSendSign.uwCrc= uwTemp1.uw;
	hsd_ubTxBuf[3] = uwTemp1.ub.hi;
	hsd_ubTxBuf[4] = uwTemp1.ub.low;	
	
	Tx0CNT = 5;	//length    
	SCI0.TDR = hsd_ubTxBuf[0] ;
	//SCI0.SSR.BIT.TDRE = 0;   //Bernie mask
	SCI0.SCR.BIT.TEIE = 1;	
	hsd_ubTxCnt1 = 0;	
	//SendCNT4 = 0;
    Com_WatchDog0= 0;
    RTU_CNT0 = 0;
    SendCNT0 = 0;
    TXD_RTS0 = 0;	
}
/*********************************************************************************************
 Function: 
 Description: Cdif and Ddif converter start  for test of absolute position 
*********************************************************************************************/
void hsd_RxStaPro(void)
{
	UWORD_UNION  uwTemp1,uwTemp2,uwTemp3 ;
	UBYTE_UNION  ubTemp1;

	//UBYTE  ubTmep1;				//clear Warning, Special.kung, 03/08/2023
	
	/* genrater the  CRC */
	uwTemp1.uw = CRC16(&hsd_ubRxBuf[0], 5) ;
	/* read  receive data CRC */

	uwTemp2.ub.low= hsd_ubRxBuf[5];
	uwTemp2.ub.hi = hsd_ubRxBuf[6];
	
	/*CRC check */
	if(uwTemp1.uw==uwTemp2.uw){ /*check OK */
		/*data save */
		/*save  the  PGSHD error and  clear the error as  time  out and CRC error of PG-->IED*/ 
		hsd_stPgReplyOut.ubErrSign = hsd_ubRxBuf[2]&0x1F;
		ubTemp1.ub=hsd_ubRxBuf[2];
		/*angle data save */
		uwTemp3.ub.low = hsd_ubRxBuf[4];
		uwTemp3.ub.hi  = hsd_ubRxBuf[3];	
			
		// fix 1387 C+- on PGHSD1, Sean, 06/25/2012
		//if ((pr[PG_TYPE]==SIN_SIN)&&((pr[PG_MODE]&0x0400)==0)){	// VL-1387 definition


		if (pr[PG_TYPE]==SIN_HIPER){	//[PGHSD Add Hiperface, Jerry Yu, 2019/11/15]
			uwTemp3.uw = uwTemp3.uw>>2;
			if ((pr[PG_C_TYPE]&0x8000)==0x0000){
				if(uwTemp3.uw>4095)                  //absoluation Angle >180
	                uwTemp3.uw = uwTemp3.uw - 4096;  //shift 180
	            else                                 //absoluation Angle <=180                             
	                uwTemp3.uw = uwTemp3.uw + 4096;  //shift 180
			}
			if ((pr[PG_C_TYPE]&0x8000)==0x8000){
				if (uwTemp3.uw>4095)
						uwTemp3.uw = 8191 + 4095 - uwTemp3.uw;
				else
					uwTemp3.uw = 4095 - uwTemp3.uw;
			}
		}
		else{
			if ((pr[PG_TYPE]==SIN_SIN)&&((pr[PG_C_TYPE]&0x0001)==0)){	// VL-1387 definition   //[change parameter to normal group, Bernie, 2014/02/14]
				if (uwTemp3.uw>4095)
					uwTemp3.uw = 8191 + 4095 - uwTemp3.uw;
				else
					uwTemp3.uw = 4095 - uwTemp3.uw;
	                     

				//uwTemp3.uw += 4095;
				//if (uwTemp3.uw>8191)
				//	uwTemp3.uw -= 8191;
			}		
	        else{                  //[fix 1387 C -+ on PGHSD-1, Bernie, 2014/08/14
	            if(uwTemp3.uw>4095)                  //absoluation Angle >180
	                uwTemp3.uw = uwTemp3.uw - 4096;  //shift 180
	            else                                 //absoluation Angle <=180                             
	                uwTemp3.uw = uwTemp3.uw + 4096;  //shift 180
	        }
		}
   
		hsd_stPgReplyOut.uwAngle =uwTemp3.uw; 
		#if 0 //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
		ANGLE_BALANCE[ANGLE_BALANCE_CNT] = hsd_stPgReplyOut.uwAngle;
		ANGLE_BALANCE_AVERAGE += ANGLE_BALANCE[ANGLE_BALANCE_CNT];
		ANGLE_BALANCE_CNT++;
		if(ANGLE_BALANCE_CNT>9){ 
			
			ANGLE_BALANCE_AVERAGE /= ANGLE_BALANCE_CNT;
			ANGLE_BALANCE_CNT = 0;
			ANGLE_BALANCE_TAKE = ANGLE_BALANCE_AVERAGE;
		}
		#endif
		/*the error from IED count if  the enable */
		if(ubTemp1.ub>0){
			hsd_PgErrorPro(ubTemp1) ;
		}
		else{
			hsd_PgErrClcPro();
		}
		/*set the modle status as  delay  retransmission*/
		hsd_ubRxTxSta = HSD_DELAY_STATUS_CONST ;
		/*last TX data  not matching   RX data error */
		if((hsd_ubRxBuf[0]==hsd_ubTxBuf[0])&&(hsd_ubRxBuf[1]==hsd_ubTxBuf[1])){/*matching */
		/*clear the error sign of matching error */
			hsd_stPgReplyOut.ubErrSign &=0xBF; //~0x40U ;
			if(hsd_ubErrClcMatCnt >0){
				hsd_ubErrClcMatCnt--;
			}
			else{
				hsd_stPgReplyOut.ubErrMatCnt = 0; 
			}
		}
		else{
		/*set the matching error */
			hsd_stPgReplyOut.ubErrSign |= HSD_MATCH_ERR_CONST; //0x40U ;
			if(hsd_stPgReplyOut.ubErrMatCnt<HSD_MAX_ERR_CNT_CONST ){
				hsd_stPgReplyOut.ubErrMatCnt++;
			}
			else{
			}
			hsd_ubErrClcMatCnt  = HSD_ERR_CLEAR_MAX_CONST;
		}
		/*clear  the IED CRC error */
		if(hsd_ubErrClcCrcCnt >0)  {
			hsd_ubErrClcCrcCnt-- ;
		}
		else{
			hsd_stPgReplyOut.ubErrCrcCnt=0; 
		}
	}
	else{
		hsd_ubRxTxSta = HSD_ERR_STATUS_CONST ;
		/*the error is PGHSD-->IED CRC */
		hsd_stPgReplyOut.ubErrSign |= HSD_PG_TO_IED_ERR_CONST;
		if(hsd_stPgReplyOut.ubErrCrcCnt<HSD_MAX_ERR_CNT_CONST ){
			hsd_stPgReplyOut.ubErrCrcCnt++;
		}
		else{
		}
		hsd_ubErrClcCrcCnt  = HSD_ERR_CLEAR_MAX_CONST;
	}
}

/*********************************************************************************************
 Function: hsd_PgErrorPro() 
 Description:  count of the  error  from PG  and  clear    
*********************************************************************************************/
void hsd_PgErrorPro(UBYTE_UNION ub)
{
	/* 1. added or clear count number of the  AB error*/ 
	if(ub.bit.b7==1){
		if(hsd_stPgReplyOut.ubErrAbCnt<HSD_MAX_ERR_CNT_CONST ){
			hsd_stPgReplyOut.ubErrAbCnt++;
		}
		else{
		}
		hsd_ubErrClcAbCnt  = HSD_ERR_CLEAR_MAX_CONST;
	}
	else{
		if(hsd_ubErrClcAbCnt >0)  {
			hsd_ubErrClcAbCnt--;
		}
		else{
			hsd_stPgReplyOut.ubErrAbCnt=0; 
		}
	}
	/* 2. added or clear count number of the  encoder type  error*/ 
	if(ub.bit.b6==1){
		if(hsd_stPgReplyOut.ubErrTypCnt<HSD_MAX_ERR_CNT_CONST ){
			hsd_stPgReplyOut.ubErrTypCnt++;
		}
		else{
		}
		hsd_ubErrClcTypCnt  = HSD_ERR_CLEAR_MAX_CONST;
	}
	else{
		if(hsd_ubErrClcTypCnt >0)  {
			hsd_ubErrClcTypCnt--;
		}
		else{
			hsd_stPgReplyOut.ubErrTypCnt=0; 
		}
	}
	/* 3. added or clear count number of the  encoder error*/ 
	if(ub.bit.b5==1){
		if(hsd_stPgReplyOut.ubErrPgCnt<HSD_MAX_ERR_CNT_CONST ){
			hsd_stPgReplyOut.ubErrPgCnt++;
		}
		else{
		}
		hsd_ubErrClcPgCnt  = HSD_ERR_CLEAR_MAX_CONST;
	}
	else{
		if(hsd_ubErrClcPgCnt >0){
			hsd_ubErrClcPgCnt--;
		}
		else{
			hsd_stPgReplyOut.ubErrPgCnt=0; 
		}
	}
	/* 4. added or clear count number of the  PG  CRC  error*/ 
	if(ub.bit.b4==1U){
		if(hsd_stPgReplyOut.ubErrPgCrcCnt<HSD_MAX_ERR_CNT_CONST ){
			hsd_stPgReplyOut.ubErrPgCrcCnt++;
		}
		else{
		}
		hsd_ubErrClcPgCrcCnt  = HSD_ERR_CLEAR_MAX_CONST;
	}
	else{
		if(hsd_ubErrClcPgCrcCnt >0){
			hsd_ubErrClcPgCrcCnt--;
		}
		else{
			hsd_stPgReplyOut.ubErrPgCrcCnt=0; 
		}
	}
	/* 5. added or clear count number of the  encoder type over error */ 
	if(ub.bit.b3==1U){
		if(hsd_stPgReplyOut.ubErrPgOveCnt<HSD_MAX_ERR_CNT_CONST ){
			hsd_stPgReplyOut.ubErrPgOveCnt++;
		}
		else{
		}
		hsd_ubErrClcPgOveCnt  = HSD_ERR_CLEAR_MAX_CONST;
	}
	else{
		if(hsd_ubErrClcPgOveCnt >0){
			hsd_ubErrClcPgOveCnt--;
		}
		else{
			hsd_stPgReplyOut.ubErrPgOveCnt=0; 
		}
	}
}
/*********************************************************************************************
 Function: hsd_PgErrClcPro() 
 Description: the count number  of the  error  from PG  clear    
*********************************************************************************************/
void hsd_PgErrClcPro(void )
{
	/* 1.  clear count number of the  AB error*/ 
	if(hsd_ubErrClcAbCnt >0){
		hsd_ubErrClcAbCnt--;
	}
	else{
		hsd_stPgReplyOut.ubErrAbCnt = 0; 
	}
	/* 2.  clear count number of the  encoder type  error*/ 
	if(hsd_ubErrClcTypCnt >0){
		hsd_ubErrClcTypCnt--;
	}
	else{
		hsd_stPgReplyOut.ubErrTypCnt = 0; 
	}
	/* 3.  clear count number of the  encoder error*/ 
	if(hsd_ubErrClcPgCnt >0){
		hsd_ubErrClcPgCnt--;
	}
	else{
		hsd_stPgReplyOut.ubErrPgCnt = 0; 
	}
	/* 4.  clear count number of the  PG  CRC  error*/ 
	if(hsd_ubErrClcPgCrcCnt >0){
		hsd_ubErrClcPgCrcCnt--;
	}
	else{
		hsd_stPgReplyOut.ubErrPgCrcCnt=0; 
	}
	/* 5. added or clear count number of the  encoder type over error */ 
	if(hsd_ubErrClcPgOveCnt >0){ 
		hsd_ubErrClcPgOveCnt--;
	}
	else{
		hsd_stPgReplyOut.ubErrPgOveCnt=0; 
	}
}

#ifdef _SCI4_PGComm_C
    #undef _SCI4_PGComm_C
#endif

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
