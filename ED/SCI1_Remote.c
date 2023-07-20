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
#ifndef _SCI1_Remote_C
        #define _SCI1_Remote_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
#include "PR_Romdata.h"

/* Constant Table =============================================*/

UWORD CRC_CHECK_3(UBYTE CRC_CNT)
{
    UWORD_UNION CRC_Result;
    //UWORD  uIndex ; /* will index into CRC lookup table */
    UBYTE i,j;
    CRC_Result.uw = 0xffff;

    for (i=0;i<=CRC_CNT; i++){
        TxBuf_3[i] = RxBuf_3[i];
      
      #if CRC_Table      
        uIndex = CRC_Result.ub.low ^ RxBuf_3[i];
        CRC_Result.ub.low  = CRC_Result.ub.hi ^ auchCRCLo[uIndex] ;
        CRC_Result.ub.hi = auchCRCHi[uIndex] ;
      
      #else
        CRC_Result.ub.low ^= RxBuf_3[i];   
        for (j=0;j<8;j++) {
            if (CRC_Result.uw & 0x01)
                CRC_Result.uw = (CRC_Result.uw >>1 ) ^ 0xa001;
            else
                CRC_Result.uw = CRC_Result.uw >> 1;
        }
      #endif     
    }

    return(CRC_Result.uw);
}

void RTU_RxOKChk_3(void)
{
    DINT(); 
    // RTU_RXF=0, data receiving, and RTU_CNT1 count in 100us	
    if ((RTU_RXF3==0)&&(RTU_CNT3>=RTU_Silent3)) {
        if (Rx3CNT >=7) {            // 7 characters are RTU Minimum string
//#if SH7286 //Sean, 01/25/2010
            SCI3.SCR.BIT.RIE = 0; //SCI2>SCIF3, Sean, 01/20/2010
//#else        	
//            SCI0.SCSCR.BIT.RIE = 0;	// dino, 03/06/2007
//#endif            
            RX_OK3 = 1;                // Check RTU mode End of ETX            
        }
        else{
	    	if (Rx3CNT!=0)
	    	Rx3CNT = 0xFF;
        }
		
        RTU_CNT3 = 0;
        RTU_RXF3 = 1;
    }
    EINT();

}

void TxD_Data_3(void)//Ready To Send
{   
    if ((TXD_RTS3==1)&&(RTU_CNT3>=pr[REM_DT3])){   //Ready To Send
        Com_WatchDog3 = 0;
        RTU_CNT3 = 0;                // clr rtu space timer
        SendCNT3 = 0;
        TXD_RTS3 = 0;

        DINT();     
//#if SH7286 //Sean, 01/25/2010          
        SCI3.TDR = TxBuf_3[SendCNT3];
        //SCI3.SSR.BIT.TDRE = 0;    //Bernie mask
        SCI3.SCR.BIT.TIE = 1;		// Transmit Data Empty Interrupt Enable
        SCI3.SCR.BIT.TEIE = 1;	// Enable Transmit FIFO Empty interrupt
//#else
//        SCI0.SCTDR = TxBuf_1[SendCNT1];	// dino, 03/06/2007
//        SCI0.SCSSR.BIT.TDRE = 0;       	// dino, 03/06/2007
//        SCI0.SCSCR.BIT.TEIE = 1;	// Enable Transmit End interrupt, dino, 03/06/2007
//#endif        
        EINT();
    }
}

void RxDataCheck_3(void)
{
    UBYTE i,k;
    UWORD ChkTemp=0;
    UWORD_UNION Data_CRC, CRC_Result1;
    if (ASC_RTU3==0) {     //ASC mode
            if (RxBuf_3[0]==STX){
        	   // 1. Transfer ASCII code to HEX code
                for (i=1;i<=(Rx3CNT-2);i++){       // i=1 ->cancel "3A" //
                    if ((RxBuf_3[i]>=0x41)&&(RxBuf_3[i]<=0x46))       // A~F
                        RxBuf_3[i-1] = RxBuf_3[i] - 0x37;                    
                    
                    else if ((RxBuf_3[i]>=0x30)&&(RxBuf_3[i]<=0x39))  // 0~9
                        RxBuf_3[i-1] = RxBuf_3[i] - 0x30;                    
                    else{
                        ChkTemp = 0xFF;
                        break;
                    }
                }
            
                // 2. Calculate CRC or LRC value
                if (ChkTemp==0){
                    i = 0;
                    k = 0;
                    do {
                        RxBuf_3[k]=(RxBuf_3[i]<<4)+(RxBuf_3[i+1]&0x0F);
                        ChkTemp = ChkTemp + RxBuf_3[k];      /* LRC calculation */
                        i += 2;
                        k++;

                    } while (i<=(Rx3CNT-3));
                }//if (ChkTemp==0)
            }//if (RxBuf_1[0]==STX)
            Rx3CNT = (Rx3CNT - 6)>>1;
    }//End of ASC mode
    else {  // ASC_RTU=1, RTU mode
            Rx3CNT = Rx3CNT - 2;
            CRC_Result1.uw = CRC_CHECK_3(Rx3CNT);
            
            Data_CRC.ub.low = RxBuf_3[Rx3CNT+1];
            Data_CRC.ub.hi = RxBuf_3[Rx3CNT+2];

            if (CRC_Result1.uw!=Data_CRC.uw)
            	ChkTemp = 0xFF;
    }// End of Receive data check //

    if ((ChkTemp&0x00FF)==0x0000){   // LRC or CRC correct //
        if (RxBuf_3[0]==0x00){
            NO_ECHO3 = 1;      // Broadcast mode, No echo //
            ADDR_MATCH3 = 1;            
        }
        else if ((RxBuf_3[0]==0xFF)||(RxBuf_3[0]==pr[ADDRS3])){
            NO_ECHO3 = 0;
            ADDR_MATCH3 = 1;
            SCIDIR3Flag = 0;
            SCI3_DIR = 0;
        }
        else{				
            InitSCI3();//SCI2>SCIF3, Sean, 01/20/2010
        }
    }
    else{
        InitSCI3();//SCI2>SCIF3, Sean, 01/20/2010
	}        
}

void RxDecoder_3(void)
{
    //------ receive data convert and check ---------------------//
    RxDataCheck_3();

    //CheckPU2();
    if (ADDR_MATCH3==1) {
        switch(RxBuf_3[1]) {
            case 0x03:    /* multi read data */
                if(Rx3CNT==5)
                    RemoteCmd03_3();
                break;
            case 0x63:    /* multi read data */
                if(Rx3CNT==5)
                    RemoteCmd63_3();
                break;    
            case 0x06:    /* set single data */
                if(Rx3CNT==5)
                    RemoteCmd06_3();
                break;
            case 0x10:    /* multi write */
                if (Rx3CNT ==(6+RxBuf_3[6]))
                    RemoteCmd10_3();
                break;
            case 0x65:    /* multi write */           //[UD protocal, Bernie, 2012/12/05]
                if (Rx3CNT ==13){
                    RemoteCmd65_3();
                }
                else{                           //[Fixed Communication issue, Bernie, 2012/11/07]
                    //if(Rx1CNT>5||Rx1CNT<5){
                    COM3Err = PC_CE03;
                    Init_TxData_3(Rx3CNT);
                    //}
                }
                break;
            case 0x08:      /* diagnostic ->echo */
                    Init_TxData_3(Rx3CNT);
                break;
            default:
                COM3Err = PC_CE01;
                break;
        }
        SCI3_ComFault();
    }
}

#if 0
void CHK_PUID3(void)
{
    //----------------------------------------------------
    // #define    IDPU    P5.bit.b7   // PU02 ID pin, 0: PU02 Active
    // PUID Check, 11262003

    if (PUID3_BUF != IDPU3) {
        PUID3Cnt = 0;
        PUID3_BUF = IDPU3;
    }
    else {
        if (PUID3Cnt >= 255){

            PUID3 = PUID3_BUF;      // Port3 status change
         
            
            if ( (pr[PROTBIT]&0x1000)==0x1000 ){	// Bit 12: PUID3 control by pr[PROTBIT]
            	if ( (pr[PROTBIT]&0x0008)==0 )		// Bit 3: external keypad connector enable/disable
            		PUID3 = 1;	// PUON3LINE=0
            	else
            		PUID3 = 0;	// PUON3LINE=1
            }
          
            
            if (PUID3 == 0){		
           
             
                PUON3LINE = 1;
                if(PUON3==1)
                    PUEN = 1;
                else
                    PUEN = 0;
            }  
            else {
         
                PUON3LINE = 0;
//                if (pr[SOOC]>=3)
                if (pr[SOOC]==2)		//SCOTTY 08/31/2007
                    PUEN = 1;
                else   
                    PUEN = 0;
            }    
        }
        else
            PUID3Cnt++;
    }
}
#endif
/*---- Pr09-05: Transmission Fault Treament ------*/
void SCI3_ComFault(void)
{
    if (PUON3LINE){    
        if(COM3Err==CP_CE10){      // Transmission Fault Treament COM1Err = 5 = cP10
            if ((Error==0)&&(WarnCode==0)) {
                WarnCode = COM3Err;
                Keypad_PageTmp3 = Keypad_Page3;
                Keypad_Page3 = WarnPAGE;
                WARNSTOPREC = 1;	//09/05/2007
            }            
            if(pr[C_FAULT3] == 1){
                stop();
                Error = cP10_ERR;
            }
//            else if (pr[C_FAULT2] == 2) {		//SCOTTY delete 09/03/2007 
//                CMDRUN = STOP;				//SCOTTY delete 09/03/2007 
//                CMDFREE = 1;					//SCOTTY delete 09/03/2007 
//                Error = cP10_ERR;				//SCOTTY delete 09/03/2007 
 //           }
        }        
    }
    else {
        if(COM3Err!=0){      // Transmission Fault Treament
            if(pr[C_FAULT3] == 1){
                stop();
                PC_CEError3(COM3Err);
            }   
//            else if (pr[C_FAULT1] == 2) {		//SCOTTY delete 09/03/2007 
//                CMDRUN = STOP;				//SCOTTY delete 09/03/2007 
//                CMDFREE = 1;					//SCOTTY delete 09/03/2007 
//                PC_CEError(COM1Err);			//SCOTTY delete 09/03/2007 
//				  WARNSTOPREC = 1;	//09/05/2007
//            }
 
//            if ((pr[C_FAULT1]!=3)&&(Error==0)&&(WarnCode==0)) 	//SCOTTY delete 09/03/2007 
			if ((pr[C_FAULT3]<2)&&(Error==0)&&(WarnCode==0)) {		//SCOTTY ADD 09/03/2007
                WarnCode = COM3Err;
                Keypad_PageTmp3 = Keypad_Page3;
                Keypad_Page3 = WarnPAGE;
            }
        }
    }
    COM3Err = 0;
}

void HEX2ASC_3(UBYTE byte_cnt)
{
    UBYTE data,j,bx,lrc_data=0;

    TxBuf_3[Tx3CNT] = 0x3a;
    Tx3CNT++;
    for (j=0;j<=byte_cnt;j++) {
        data = RxBuf_3[j];
        lrc_data += data;              // LRC data

        bx = data>>4;
        if (bx>=0x0a)                // 0x0a<=low_nb<=0x0f //
            TxBuf_3[Tx3CNT] = bx + 0x37;
        else                         // 0x0a>low_nb //
            TxBuf_3[Tx3CNT] = bx + 0x30;    //* nibble ->ASCII, store to buffer */
        
        Tx3CNT++;

        bx = data&0x0f;
        if (bx>=0x0a)                // 0x0a<=low_nb<=0x0f //
            TxBuf_3[Tx3CNT] = bx + 0x37;
        else                         // 0x0a>low_nb //
            TxBuf_3[Tx3CNT] = bx + 0x30;    //* nibble ->ASCII, store to buffer */
        Tx3CNT++;
    }

    lrc_data = 0 - lrc_data;           //* lrc_data=(~lrc_data)+1; */
    bx = lrc_data>>4;
    if (bx>=0x0a)                  // 0x0a<=low_nb<=0x0f //
        TxBuf_3[Tx3CNT] = bx + 0x37;
    else                           // 0x0a>low_nb //
        TxBuf_3[Tx3CNT] = bx + 0x30;      //* nibble ->ASCII, store to buffer */
    
    Tx3CNT++;

    bx = lrc_data & 0x0f;
    if (bx>=0x0a)                  // 0x0a<=low_nb<=0x0f //
        TxBuf_3[Tx3CNT] = bx + 0x37;
    else                           // 0x0a>low_nb //
        TxBuf_3[Tx3CNT] = bx + 0x30;      //* nibble ->ASCII, store to buffer */
    
    Tx3CNT++;
}

void Init_TxData_3(UBYTE Data_CNT)//Initial TxD from RxD
{
    UWORD_UNION CRC_Result1;

    if (COM3Err!=0) {
          RxBuf_3[1] |= 0x80;             // force command code bit7=1 (0x8y) //
          RxBuf_3[2] = COM3Err;          // exception code //
          Data_CNT = 2;
    }

    if (ASC_RTU3==0) {             // ASCII mode, 
        HEX2ASC_3(Data_CNT);
        TxBuf_3[Tx3CNT] = CR_0D;
        Tx3CNT++;
        TxBuf_3[Tx3CNT] = LF_0A;
    }
	
    else {                         // RTU mode
         // if ((pr[DEBUG_F1]&0x0008) == 0x0008){      //[ICT Test, Bernie, 08/11/2011]
    		//Data_CNT -= 2;
    	  //}
        CRC_Result1.uw = CRC_CHECK_3(Data_CNT);
        Tx3CNT =  Data_CNT + 1;
        TxBuf_3[Tx3CNT] = CRC_Result1.ub.low;
        Tx3CNT++;
        TxBuf_3[Tx3CNT] = CRC_Result1.ub.hi;
    }
    TXD_RTS3 = 1;                  // ready to send
}

void FFcalibration3(UBYTE func, UWORD datac)
{
    UWORD cx;

    switch(func){
        case 0x01:  // Current Calibration
        	break;
#if SH7149
        case 0x02:  //AVIMid
            cx = datac;
            if (cx > attr[CACIMID].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[CACIMID] = cx;
                write_ep(0,CACIMID,cx);
            }          
            break;
#else
        case 0x02:  //AUI1 Zero
            cx = datac;
            if (cx > attr[CAUI1ZERO].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[CAUI1ZERO].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[CAUI1ZERO] = cx;
                write_ep(0,CAUI1ZERO,cx);
            }
            break;
#endif
	case 0x03:  //ACIMid
            cx = datac;
            if (cx > attr[CACIMID].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[CACIMID] = cx;
                write_ep(0,CACIMID,cx);
            }                     
            break;                    
#if SH7149
        case 0x04:  //AVIMin
            cx = datac;
            if (cx > attr[CACIMIN].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[CACIMIN] = cx;
                write_ep(0,CACIMIN,cx);
            }          
            break;
        case 0x05:  //AVIMax
            cx = datac;
            if (cx > attr[CACIMAX].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[CACIMAX].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[CACIMAX] = cx;
                write_ep(0,CACIMAX,cx);
            }          	
            break;          
#else
        case 0x04:  // AUI1 MIN, +10V
            cx = datac;
            if (cx > attr[CAUI1MIN].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[CAUI1MIN] = cx;
                write_ep(0,CAUI1MIN,cx);
            }
            break;          
        case 0x05:  // AUI1 MAX, -10V
            cx = datac;
            if (cx > attr[CAUI1MAX].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[CAUI1MAX].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[CAUI1MAX] = cx;
                write_ep(0,CAUI1MAX,cx);
            }
            break;
#endif
        case 0x06:  // ACI MIN
            cx = datac;
            if (cx > attr[CACIMIN].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[CACIMIN] = cx;
                write_ep(0,CACIMIN,cx);
            }
            break;
        case 0x07:  // ACI MAX
            cx = datac;
            if (cx > attr[CACIMAX].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[CACIMAX].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[CACIMAX] = cx;
                write_ep(0,CACIMAX,cx);
            }
            break;
        case 0x08:  // AUI MIN, +10V
            cx = datac;
            if (cx > attr[CAUI2MIN].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[CAUI2MIN] = cx;
                write_ep(0,CAUI2MIN,cx);
            }
            break;          
        case 0x09:  // AUI MAX, -10V
            cx = datac;
            if (cx > attr[CAUI2MAX].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[CAUI2MAX].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[CAUI2MAX] = cx;
                write_ep(0,CAUI2MAX,cx);
            }
            break;
            
        case 0x0A:  //AUI Zero
            cx = datac;
            if (cx > attr[CAUI2ZERO].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[CAUI2ZERO].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[CAUI2ZERO] = cx;
                write_ep(0,CAUI2ZERO,cx);
            }
            break;
        case 0x0B:  // Fine AUI MIN, +2V
            cx = datac;
            if (cx > attr[FAUIMIN].max){
                COM3Err = PC_CE04;
            }
            else{
                pr[FAUIMIN] = cx;
                write_ep(0,FAUIMIN,cx);
            }
            break;          
#if SH7149
        case 0x0C:  // Fine AUI MAX, -2V
            cx = datac;
            if (cx > attr[FAUIMAX].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[FAUIMAX].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[FAUIMAX] = cx;
                write_ep(0,FAUIMAX,cx);
            }
            break;
            
        case 0x0D:  //Fine AUI Zero
            cx = datac;
            if (cx > attr[FAUIZERO].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[FAUIZERO].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[FAUIZERO] = cx;
                write_ep(0,FAUIZERO,cx);
            }
            break;            
#else
        case 0x0C:  // DA MAX, +10V
            cx = datac;
            if (cx > 4095)
                COM3Err = PC_CE04;
            else
                pr[DAMAX] = cx;
            break;
            
        case 0x0D:  // DA MIN, -10V
            cx = datac;
            if (cx > 4095)
                COM3Err = PC_CE04;
            else
                pr[DAMIN] = cx;
            break;            
#endif
        case 0x0E:  // DCB1_AD, AD value for 210.0VDC
            cx = datac;
            if (cx > attr[DCB_AD1].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[DCB_AD1].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[DCB_AD1] = cx;
                write_ep(0,DCB_AD1, cx);
                VBusLineInit();
            }
            break;
        case 0x0F:  // DCB2_AD, AD value for 310.0VDC
            cx = datac;
            if (cx > attr[DCB_AD2].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[DCB_AD2].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[DCB_AD2] = cx;
                write_ep(0,DCB_AD2, cx);
                VBusLineInit();
            }
            break;
        case 0x10:  // DCB3_AD, AD value for 390.0VDC
            cx = datac;
            if (cx > attr[DCB_AD3].max){
                COM3Err = PC_CE04;
            }
            else if (cx < attr[DCB_AD3].min){
                COM3Err = PC_CE04;
            }
            else{
                pr[DCB_AD3] = cx;
                write_ep(0,DCB_AD3, cx);
                VBusLineInit();
            }
            break;
        case 0x13:
            pr[FACTORY1] = datac;
            write_ep(0,FACTORY1,datac);
            break;
        case 0x14:
            pr[FACTORY2] = datac;
            write_ep(0,FACTORY2,datac);
            break;
        case 0x15:
            pr[FACTORY3] = datac;
            write_ep(0,FACTORY3,datac);
            break;
        case 0x16:
            pr[FACTORY4] = datac;
            write_ep(0,FACTORY4,datac);
            break;
        default:
            COM3Err = PC_CE03;
            //cffxx[func]=datac;
            break;
    }
}

/*-------------------------------------------------------------------------
  -     remote command 03H: reading data ----                             -
  -     response: data,max, min, attribute                                -
        -------------------------------------------------------------
  -     rxbuf[0]=adrr; rxbuf[1]=cmd_code;rxbuf[2]_rxbuf[3]=data_addr      -
  -     rxbuf[4]_rxbuf[5]=word_data_count; rxbuf[6]=LRC_data              -
  -------------------------------------------------------------------------*/
void RemoteCmd03_3(void)
{
        UBYTE TxCntTemp=0, bx, ubCHGFlag, ubGrNum, ubPrNum, HPSPEC_temp,gpno;
        UWORD TempValue, ax, rxdata, uwAddr;
        UWORD_UNION umap_addr, uwEEPData;
        
        umap_addr.uw = 0;

        if (RxBuf_3[2] == 0x20){            // Communication Memory Address 20xxH               
            ax = RxBuf_3[3];
            if ((C20MAX >= (ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                RxBuf_3[2] = RxBuf_3[5]<<1;         // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_3[5];                  // data count //
                do {                          // prepare data //
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp] = (UBYTE)(C20xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp] = (UBYTE)(C20xx[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }
        else if (RxBuf_3[2]==0x21){
            ax = RxBuf_3[3];
            if ((C21MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
                Update_C21xx();
                RxBuf_3[2] = RxBuf_3[5]<<1;           // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_3[5];                    // data count //
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }
        else if (RxBuf_3[2]==0x22) {
            ax = RxBuf_3[3];
            if ((C22MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                RxBuf_3[2]=RxBuf_3[5]<<1;
                TxCntTemp = 2;
                bx = RxBuf_3[5];
                Update_C22xx();
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=(UBYTE)(C22xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=(UBYTE)(C22xx[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }
        else if (RxBuf_3[2]==0x23) {
            ax = RxBuf_3[3];
            if ((C23MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                RxBuf_3[2]=RxBuf_3[5]<<1;
                TxCntTemp = 2;
                bx = RxBuf_3[5];
                Update_KeypadDisp();
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=(UBYTE)(KC23xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=(UBYTE)(KC23xx[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }
        else if (RxBuf_3[2]==0x24){
                ax = RxBuf_3[3];
                if ((DESMAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                RxBuf_3[2] = RxBuf_3[5]<<1;
                TxCntTemp = 2;
                bx = RxBuf_3[5];
                Update_LCDescription();
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=(UBYTE)(Descript[ax]>>8);
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=(UBYTE)(Descript[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }
        // [ Display Group for VLI, DINO, 03/22/2010
      /*  else if (RxBuf_1[2]==0x2A){
            ax = RxBuf_1[3];
            if ((C2AMAX>=(ax+RxBuf_1[5]))&&(RxBuf_1[5]!=0)&&(RxBuf_1[4]==0)){
                RxBuf_1[2] = RxBuf_1[5]<<1;           // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_1[5];                    // data count //
                do {                            // prepare data //
                	uwEEPData.uw = C2Axx[ax];
                    TxCntTemp++;
                    RxBuf_1[TxCntTemp] = uwEEPData.ub.hi;
                    TxCntTemp++;
                    RxBuf_1[TxCntTemp] = uwEEPData.ub.low;
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM1Err = PC_CE03;
        }*/
        // ]
//---Add BY Dino 06/25/2007---
        else if (RxBuf_3[2]==0xff){
            if((RxBuf_3[3]< CALIMAX)&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
                if(SHOW_ALLPR==1){ //FF - 00 -00
                    RxBuf_3[2]=RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
                    ax = RxBuf_3[3];
                    do {                          // prepare data //
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(CFFxx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(CFFxx[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
                                        
            }
            else
                COM3Err = PC_CE03;
        }   
        else if ((RxBuf_3[2]<=0xF3)&&(RxBuf_3[2]>=0xC0)){ // Communication Memory Address >= 80xxH + SFR(0300~03FF)
        	ax = ((UWORD)RxBuf_3[2]<<8) + RxBuf_3[3];
        	if ((RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
            	RxBuf_3[2] = RxBuf_3[5]<<1;		// word->byte data_count
            	TxCntTemp = 2;
            	bx = RxBuf_3[5];				// data count //
            	do {                            // prepare data //
              		TxCntTemp++;
              		RxBuf_3[TxCntTemp] = (UBYTE)(MEMADDR[ax]>>8);
              		TxCntTemp++;
              		RxBuf_3[TxCntTemp] = (UBYTE)(MEMADDR[ax]);
              		ax++;
              		bx--;
            	} while(bx!=0);
          	}
          	else
            	COM3Err = PC_CE03;
        }
//---END 06/25/2007---------------	
        else if (RxBuf_3[2]==0x31){
            if (RxBuf_3[3]<=GROUPTmp){
                if (RxBuf_3[5]<=DESMAX){                
                    RxBuf_3[2] = RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
                    	//ShowDescription(gpname[RxBuf_1[3]]);
                    // [ Traditional Chinese Display, Add by DINO, 09/28/2010
                    if ((C20xx[0x05]&0xff00) == 0x0200)
                        #if Language_TC
                        ShowDescription(gpname_tc[RxBuf_3[3]]);
                        #else
                        ShowDescription(gpname[RxBuf_3[3]]);
                        #endif
                    else if ((C20xx[0x05]&0xff00) == 0x0300)
                        #if Language_SC
                        ShowDescription(gpname_sc[RxBuf_3[3]]);
                        #else
                        ShowDescription(gpname[RxBuf_3[3]]);
                        #endif
                    else
                        ShowDescription(gpname[RxBuf_3[3]]);
                    // ]
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
                                        
            }
            else
                COM3Err = PC_CE02;
        }        
        else if (RxBuf_3[2]==0x32){
            if (RxBuf_3[3]<=ERRMAX){
                if (RxBuf_3[5]<=(DESMAX+0x04)){  // For VFD-Cx, DINO, 03/16/2010
                    RxBuf_3[2] = RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
    				if (Error!=0){
    					
							//ShowDescription(errinfo[Error]);	// RxBuf_1[0] ~ RxBuf_1[19]
                        if ((C20xx[0x05]&0xff00) == 0x0200)
                            #if Language_TC
                            ShowDescription(errinfo_tc[Error]);
                            #else
                            ShowDescription(errinfo[Error]); 
                            #endif
			            else if ((C20xx[0x05]&0xff00) == 0x0300)
                            #if Language_SC
                            ShowDescription(errinfo_sc[Error]); 
                            #else
                            ShowDescription(errinfo[Error]); 
                            #endif
                        else
                            ShowDescription(errinfo[Error]); 

    				}
    			
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
                                        
            }
            else
                COM3Err = PC_CE02;
        }
		else if (RxBuf_3[2]==0x33){	// Warning Description, 16+4 byte
//        	if (RxBuf_1[3]<=WARNMAX){
    		if (RxBuf_3[3]<=(WARNMAX+3)){  // IED Error Display, DINO, 08/13/2010
				if (RxBuf_3[5]<=DESMAX){                
                    RxBuf_3[2] = RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];           
                    	//ShowDescription(warninfo[WarnCode]);
                    // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                    if ((C20xx[0x05]&0xff00) == 0x0200)
                        #if Language_TC
                        ShowDescription(warninfo_tc[WarnCode]);
                        #else
                    	ShowDescription(warninfo[WarnCode]);
                        #endif
                    else if ((C20xx[0x05]&0xff00) == 0x0300)
                        #if Language_SC
                    	ShowDescription(warninfo_sc[WarnCode]);
                        #else
                    	ShowDescription(warninfo[WarnCode]);
                        #endif
                    else
                    	//ShowDescription(warninfo[WarnCode]);
                    	if(BTTx_ubTestCase==BTT_Testing)
                        {
                            ShowDescription(BTTxinfo[BTTx_uwTestStep]);
                        }
                        else
                        {
                            ShowDescription(warninfo[WarnCode]);
                        }
                    // ]
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;        	
			}
			else
				COM3Err = PC_CE02;
		}        
			else if (RxBuf_3[2]==0x34){
                HPSPEC_temp = RxBuf_3[3];
                if(RxBuf_3[3]>VFD_SINGLEPHASE)      //[Single phase input, Bernie, 01/19/2012]
                    HPSPEC_temp -= VFD_SINGLEPHASE;
                
			//if (RxBuf_1[3]<=MAXMODELNO){
			if (HPSPEC_temp<=MAXMODELNO){          //[Single phase input, Bernie, 01/19/2012]
				if (RxBuf_3[5]<=DESMAX){                
                    RxBuf_3[2] = RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
                    if(RxBuf_3[3]>VFD_SINGLEPHASE)            //[Single phase input, Bernie, 01/19/2012]
                        ShowDescription(ModelinfoSingle[RxBuf_3[3]-100]);
                    else
                        ShowDescription(Modelinfo[RxBuf_3[3]]);
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;			
			}
			else
				COM3Err = PC_CE02;			
		}
		else if (RxBuf_3[2]==0x35){
			if (RxBuf_3[3]<=MFDPAGEMAX){
				if (RxBuf_3[5]<=DESMAX){                
                    RxBuf_3[2] = RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
					// [ Actual Freq. Unit Change, Add by DINO, 05/25/2009
					if (RxBuf_3[3] == 2){
						if (pr[UNITSEL] == 1){
                    		ShowDescription(sfrinfo_vel_sel[0]);	// Actual Speed m/s
						}
						else if (pr[UNITSEL] == 2){
                    		ShowDescription(sfrinfo_vel_sel[1]);	// Actual Speed ft/s
						}
                        else if (pr[UNITSEL] == 3){                           //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                    		ShowDescription(sfrinfo_vel_sel[2]);	// Actual Speed ft/s
						}
						else{
							ShowDescription(sfrinfo[RxBuf_3[3]]);	// Actual Freq. Hz
						}
					}
					else{
						ShowDescription(sfrinfo[RxBuf_3[3]]);
					}
					// ]
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;			
			}
			else
				COM3Err = PC_CE02;			
		}
		else if ((RxBuf_3[2]>=0x40)&&(RxBuf_3[2]<0x50)){
      		ax = RxBuf_3[2] - 0x40;
      		if (ax<GROUPTmp){
                if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
      			ax = pr_gpno_Sibo[RxBuf_3[3]];
                else
      			ax = pr_gpno[RxBuf_3[3]];
            	if ((UWORD)RxBuf_3[3]< ax) {    // function number //
              		if ((RxBuf_3[5]<C24MAX)){
                		ax=(SWORD)prtab[(RxBuf_3[2]&0x0F)]+RxBuf_3[3];     // pr index //Max.SJ
                		RxBuf_3[2]=RxBuf_3[5]<<1;     // word->byte data_count
                		TxCntTemp=2;
                		bx=RxBuf_3[5];         // data count //
              			//ShowDescription(prinfo[ax]);
						// [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
              			if ((C20xx[0x05]&0xff00) == 0x0200){                              
              			    if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                 #if Language_TC
                                 ShowDescription(prinfo_tc[ax]);
                                 #else
                                 ShowDescription(prinfo[ax]);
                                 #endif
                        }
                        else{
                        	//JINGDO
                            #if Language_TC
                        	if(pr[FLOOR_PAGE]==1)
                          	ShowDescription(prinfo_tc_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                        	else if(pr[FLOOR_PAGE]==2)
                        		ShowDescription(prinfo_tc_DLC2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		ShowDescription(prinfo_tc_DLC3[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	    ShowDescription(prinfo_DLC_tc_Adjst[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	    ShowDescription(prinfo_DLC_tc_Adjst2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	    ShowDescription(prinfo_DLC_tc_Adjst3[(ax-DLC_PR)]);
                            #else
                        	if(pr[FLOOR_PAGE]==1)
                          	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                        	else if(pr[FLOOR_PAGE]==2)
                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                            #endif
                        }
                    }
              			else if ((C20xx[0x05]&0xff00) == 0x0300){
              			    if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                #if Language_SC
                                ShowDescription(prinfo_sc[ax]);
                                #else
                                ShowDescription(prinfo[ax]);
                                #endif
                        }
                        else{
                            #if Language_SC
                        	if(pr[FLOOR_PAGE]==1)
                          	ShowDescription(prinfo_sc_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                        	else if(pr[FLOOR_PAGE]==2)
                        		ShowDescription(prinfo_sc_DLC2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		ShowDescription(prinfo_sc_DLC3[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                            #else
                        	if(pr[FLOOR_PAGE]==1)
                          	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                        	else if(pr[FLOOR_PAGE]==2)
                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                            #endif
                        }
                    }
                        else{
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){  
                            	ShowDescription(prinfo[ax]);
                            }
                            else{
                            	if(pr[FLOOR_PAGE]==1)
                            		ShowDescription(prinfo_DLC[(ax-DLC_PR)]);             //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                            	else if(pr[FLOOR_PAGE]==2)
                            		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	        ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	        ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	        ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                            }
                        }
                        // ]
              			ax = 0;
              			do {   // prepare data
                			TxCntTemp++;
                			RxBuf_3[TxCntTemp]=(UBYTE)(Descript[ax]>>8);
                			TxCntTemp++;
                			RxBuf_3[TxCntTemp]=(UBYTE)Descript[ax];
                			ax++;
                			bx--;
              			} while(bx!=0);
              		}
              		else
                		COM3Err = PC_CE03;
                }
				else
                	COM3Err = PC_CE03;
			}
			else
				COM3Err = PC_CE03;
		}
        else if(RxBuf_3[2]==(GROUPTmp+1)){
            ax = RxBuf_3[3];
            if (((GROUPTmp+1)>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
                RxBuf_3[2] = RxBuf_3[5]<<1;    // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_3[5];             // data count
                do{
      				if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                    	TempValue = pr_gpno_Sibo[ax] - 1;
      				else
                    	TempValue = pr_gpno[ax] - 1;
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=((UWORD)TempValue >> 8);
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp]=((UWORD)TempValue & 0x00ff);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }
		//--- Address 9999H: "DELAT ELECTRONICS   " Copyright Display, Add by DINO, 12/01/2008 ---//
		else if (RxBuf_3[2]==0x99){	// Warning Description, 16+4 byte
			if ( RxBuf_3[3]==0x99 ){
				Descript[0] = 0x4040 + 0x0405 ;	// 0x4445, "D","E"
				Descript[1] = 0x4050 + 0x0C04 ;	// 0x4C54, "L","T"
				Descript[2] = 0x4020 + 0x0100 ;	// 0x4120, "A"," "
				Descript[3] = 0x4040 + 0x050C ;	// 0x454C, "E","L"
				Descript[4] = 0x4040 + 0x0503 ;	// 0x4543, "E","C"
				Descript[5] = 0x5050 + 0x0402 ;	// 0x5452, "T","R"
				Descript[6] = 0x4040 + 0x0F0E ;	// 0x4F4E, "O","N"
				Descript[7] = 0x4040 + 0x0903 ;	// 0x4943, "I","C"
				Descript[8] = 0x5020 + 0x0300 ;	// 0x5320, "S"," "
				Descript[9] = 0x2020 + 0x0000 ;	// 0x2020. " "," "
				RxBuf_3[2] 	= 0x14 ;			// Number of datas = 20 bytes
				ax = 0 ;
				bx = RxBuf_3[5];             	// data count

				TxCntTemp = 2 ;
				do {				// prepare data
					umap_addr.uw = Descript[ax] ;
					TxCntTemp++;
					RxBuf_3[TxCntTemp] = umap_addr.ub.hi;
					TxCntTemp++;
					RxBuf_3[TxCntTemp] = umap_addr.ub.low;
					ax++;
					bx--;
				} while(bx!=0);
			}
			else
				COM3Err = PC_CE02;
		}
        else{
            if (SHOW_ALLPR==1)
                ax = GRALL;
            else{
            	// [ 00-02 Setting, DINO, 06/03/2010
            	
            	if (SHOW_ENHANCE==1)
            		ax = GRENHANCE;
            	else
					ax = GRUSER;
			}

            if (RxBuf_3[2]<=ax){        // group number //
      		    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                	ax = pr_gpno_Sibo[RxBuf_3[2]];
      	        else
                	ax = pr_gpno[RxBuf_3[2]];
                if (RxBuf_3[3]< ax) {    // function number //            
                    if ((PUON3LINE==1)||(RxBuf_3[0]==0xFF)){//read parameter by PU
                        if ((RxBuf_3[5]==0x0A)&&(RxBuf_3[4]==0)) {

	                        ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3]; // pr index //

                            bx = RxBuf_3[5];
                            TxCntTemp = 2;
                            RxBuf_3[2] = RxBuf_3[5]<<1;
            				if (CHKCPR==1)
					            function_chk();
					       else{
#if ACCESS_GROUP
                                // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                ubCHGFlag = 0;

                                if ( umap_addr.ub.hi==21 ){
                        		    ShowDescription(c21info[ax]);
                        		    if ((DispAttr[ax].ati&CHG) == CHG){
                        		    	ubCHGFlag = 1;
                        		    }
                        		}
                                else if ( umap_addr.ub.hi==22 ){

                                    ax = umap_addr.ub.low;        //[solve the problem about access c22xx, Bernie, 2016/02/01]

                        		    ShowDescription(c22info[ax]);
                        		}
                                else{
#endif
					                //ShowDescription(prinfo[ax]);
									// [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                                    if ((C20xx[0x05]&0xff00) == 0x0200){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_TC
                                        	ShowDescription(prinfo_tc[ax]);
                                            #else
                                        	ShowDescription(prinfo[ax]);
                                        	#endif
                                        }
                                        else{
                                            #if Language_TC
                                        	// JINGDO
                                        	if(pr[FLOOR_PAGE]==1)
                                        		ShowDescription(prinfo_tc_DLC[(ax-DLC_PR)]);             //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_tc_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_tc_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_tc_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_tc_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_tc_Adjst3[(ax-DLC_PR)]);
                                            #else
                                        	if(pr[FLOOR_PAGE]==1)
                                        		ShowDescription(prinfo_DLC[(ax-DLC_PR)]);             //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            #endif 
                                        }
                                    }
                                    else if ((C20xx[0x05]&0xff00) == 0x0300){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_SC
                                            ShowDescription(prinfo_sc[ax]);
                                            #else
                                        	ShowDescription(prinfo[ax]);
                                            #endif
                                        }
                                        else{
                                            #if Language_SC
                                        	// JINGDO
                                        	if(pr[FLOOR_PAGE]==1)
                                          	ShowDescription(prinfo_sc_DLC[(ax-DLC_PR)]);             //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_sc_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_sc_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                                            #else
                                        	if(pr[FLOOR_PAGE]==1)
                                          	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);             //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            #endif
                                        }
                                    }
                                    else{
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                          ShowDescription(prinfo[ax]);
                                        }
                                        else{
                                        	// JINGDO
                                        	if(pr[FLOOR_PAGE]==1)
                                          	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);                //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        	                	ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                        }
                                    }
                                    // ]

                        		    //if ((attr[ax].ati&CHG) == CHG){
                        		    	//ubCHGFlag = 1;
                        		    //}
                        		    if((pr[SOFC]<=3) && (pr[UNITSEL]<3)){                          //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                        		        if ((attr[ax].ati&CHG) == CHG){
                        		    	    ubCHGFlag = 1;
                        		        }
                                    }
                        		    else{                                                         //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                                        if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){
                                		    if((ax == ACCEL1)||
                                               (ax == DECEL1)||
                                               (ax == JOGACC)||
                                               (ax == JOGDEC)||
                                               (ax == DECEL5)
                                             ){
                                                ubCHGFlag = 1;
                                            }
                                        else if(ax == JOGF)  //DLC function, Henry, 2016/07/20
                                        	{
                                        		ubCHGFlag = 2;
                                        	}
                                        }
                                    }
					            }

								if (ubCHGFlag == 1 || ubCHGFlag == 2){
									if (pr[UNITSEL] == 1){
										if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
											|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
											|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
											|| (ax == JOGDEC) || (ax == DECEL5))
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('m'<<8)+'/';
											Descript[9] = ('s'<<8)+'2';											
										}
										else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
												|| (ax == S4DEC2) || (ax == S4DEC3))
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('m'<<8)+'/';
											Descript[9] = ('s'<<8)+'3';
										}
										else{  // m/s
											Descript[8]  = ('m'<<8)+'/';
											Descript[9] = ('s'<<8)+' ';
										}
									}
									else if (pr[UNITSEL] == 2){
										if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // ft/s2
											|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
											|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
											|| (ax == JOGDEC) || (ax == DECEL5))
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'2';											
										}
										else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // ft/s3
												|| (ax == S4DEC2) || (ax == S4DEC3))
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'3';
										}
										else{  // ft/s
										Descript[8]  = ('f'<<8)+'t';
										Descript[9] = ('/'<<8)+'s';
										}
									}
                  else if (pr[UNITSEL] == 3 && ubCHGFlag == 1){   //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+'2';
									}
									else if (pr[UNITSEL] == 3 && ubCHGFlag == 2){   //DLC function, Henry, 2016/07/20
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+' ';
									}
								}
								// ]
					        }
                            ax = 0;
                            do{
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                                ax++;
                                bx--;
                            } while(bx!=0);
                        }
                        //Data,Max,Min,Att,Def
                        else if ((RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
#if ACCESS_GROUP
							if (RxBuf_3[2] == MAPGOURP){
    	    	        		umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_3[3]] / 100;
                				umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_3[3]] - umap_addr.ub.hi * 100;
                                if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                                    gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                                else
                                    gpno = pr_gpno[umap_addr.ub.hi];
                				// Access to C21xx
                				if (umap_addr.ub.hi==21 && umap_addr.ub.low<C21MAX){
                				    if ( (DispAttr[umap_addr.ub.low].ati&JMP)==JMP && SHOW_ALLPR==0 ){
                				        ax = Unavaliable;
                				        umap_addr.ub.hi = 0;
                				    }
                				    else
                				    	ax = umap_addr.ub.low;
                				}
                				// Access to C22xx
                				else if (umap_addr.ub.hi==22 && umap_addr.ub.low<C22MAX){
                				    if ( (DispAttr[(umap_addr.ub.low+C21MAX-1)].ati&JMP)==JMP && SHOW_ALLPR==0 ){ //[solve the problem about access c22xx, Bernie, 2016/02/01]     // Modify by DINO, 09/08/2008
                				        ax = Unavaliable;
                				        umap_addr.ub.hi = 0;
                				    }
                				    else{
                				    	ax = umap_addr.ub.low;
                				    }
                				}
                				// Access to user parameter
                				// [ Mapping to hidden parameters, DINO, 12/23/2009
                				else if ((umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno ){
//                				else if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] ){
            	    				ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    			}
            	    			// ]
            	    			// Access to unavailable address
            	    			else{
            	    				umap_addr.ub.hi = 0;
            	    				ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
            	    			}
							}
							else
#endif
	                            ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3]; // pr index //        
                            bx = RxBuf_3[5];
                            TxCntTemp = 2;
                            RxBuf_3[2] = RxBuf_3[5]<<1;
#if ACCESS_GROUP
                            // [ Velocity Unit Change, Add by DINO, 05/25/2009
                            ubCHGFlag = 0;
                            // ]
                            
                            if ( umap_addr.ub.hi==21 ){
            					//Data Content
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                                //Data Max
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0xff;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0xff;
                                //Data Min
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                //Data attribute
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = DispAttr[ax].ati>>8;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = DispAttr[ax].ati&0x00ff;
                                //Data default
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                //Data Description
                                ShowDescription(c21info[ax]);
                                // [ Velocity Unit Change, Add by DINO, 05/25/2009
                         		if ((DispAttr[ax].ati&CHG) == CHG){
									ubCHGFlag = 1;
                        		}
                        		// ]
                           }
                            else if ( umap_addr.ub.hi==22 ){
            					//Data Content
								
            			        ax = umap_addr.ub.low;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = ((UWORD)C22xx[ax]>>8);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = ((UWORD)C22xx[ax] & 0x00ff);
                                //Data Max
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0xff;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0xff;
                                //Data Min
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                //Data attribute
                                TxCntTemp++;

                                //RxBuf_3[TxCntTemp] = DispAttr[(ax+C21MAX)].ati>>8;
                                RxBuf_3[TxCntTemp] = DispAttr_c22xx[(ax)].ati>>8;        //[solve the problem about access c22xx, Bernie, 2016/02/01]
                                TxCntTemp++;
                                //RxBuf_3[TxCntTemp] = DispAttr[(ax+C21MAX)].ati&0x00ff;
                                RxBuf_3[TxCntTemp] = DispAttr_c22xx[(ax)].ati&0x00ff;    //[solve the problem about access c22xx, Bernie, 2016/02/01]
                                //Data default
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = 0x00;
                                //Data Description
                                    ax = umap_addr.ub.low;           //[solve the problem about access c22xx, Bernie, 2016/02/01]

                                    
                                ShowDescription(c22info[ax]);
                            }
#endif
                            else{
                                TxCntTemp++;
                                // [ Velocity Unit Change, Add by DINO, 05/25/2009
                        		uwEEPData.uw = GetParData(ax);
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
								// ]

                                uwEEPData.uw = GetParMax(ax);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.low;

                                uwEEPData.uw = GetParMin(ax);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#if SH7149
                                if ((attr[ax].ati&0x0400)==0x0400){
                                    rxdata = GetParAttr(ax);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)rxdata>>8);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)rxdata&0x00ff);
								}		
                                else {
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)attr[ax].ati>>8);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)attr[ax].ati&0x00ff);
                                }       
#else	// Modify by DINO, 09/22/2008
                            	uwEEPData.uw = GetParAttr(ax);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#endif

//-- Add by VE item91, 10/30/2008
                            	if ((pr[HPSPEC]&VFD440V)==VFD220V){    // 220V class
#if DINO
									if ( (attr[ax].ati&V440)==V440 )
										uwEEPData.uw = attr[ax].def>>1;
									else
										uwEEPData.uw = attr[ax].def;
#else
                            	    switch(ax){
                            	        case VMAX1:
                            	    	case VMID1_1:
                            	    	case VMID1_2:
                            	    	case VMIN1:    
                            	    	case LVL:	
                            	    	case STALL4V:
                            	    	case DCBRK4V:
                            	    	case VMAX2:
                            	    	case VMID2_1:
                            	    	case VMID2_2:
                            	    	case VMIN2:
                            	    	case PHL_L:
                            	            rxdata = attr[ax].def>>1;
                            	            break;
                            	        default:
                            	            rxdata = attr[ax].def;
                            	            break;
                            	    }
#endif
                            	}
                            	else{
                            	    uwEEPData.uw = attr[ax].def;
                            	}
//-- End on 10/30/2008
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
                                //Data Description
           						if (CHKCPR==1)
					                function_chk();
					            else{
                                    //ShowDescription(prinfo[ax]);
                                    // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                                    if ((C20xx[0x05]&0xff00) == 0x0200){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_TC
                                            ShowDescription(prinfo_tc[ax]);
                                            #else
                                            ShowDescription(prinfo[ax]);
                                            #endif
                                        }
                                        else{
                                            #if Language_TC
                                        	// JINGDO
                                        	if(pr[FLOOR_PAGE]==1)
                                          	ShowDescription(prinfo_tc_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_tc_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_tc_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_tc_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_tc_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_tc_Adjst3[(ax-DLC_PR)]);
                                            #else
                                        	if(pr[FLOOR_PAGE]==1)
                                          	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            #endif
                                        }    
                                    }
                                    else if ((C20xx[0x05]&0xff00) == 0x0300){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_SC
                                            ShowDescription(prinfo_sc[ax]);
                                            #else
                                            ShowDescription(prinfo[ax]);
                                            #endif
                                        }
                                        else{
                                            #if Language_SC
                                        	// JINGDO
                                        	if(pr[FLOOR_PAGE]==1)
                                          	    ShowDescription(prinfo_sc_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_sc_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_sc_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                                            #else
                                        	if(pr[FLOOR_PAGE]==1)
                                          	    ShowDescription(prinfo_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                        	else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            #endif
                                        }
                                    }
                                    else{
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            ShowDescription(prinfo[ax]);
                                        }
                                        else{ //[adjust floor position adjust,Aevin,2018/06/19]
                                            if(pr[FLOOR_PAGE]==1)
                                                ShowDescription(prinfo_DLC[(ax-DLC_PR)]);       //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                            else if(pr[FLOOR_PAGE]==2)
                                        		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3)
                        		                  ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                               	ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                               	ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                               	ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                        }
                                    }
                               	    // ]
                                	// [ Velocity Unit Change, Add by DINO, 05/25/2009
                        		    //if ((attr[ax].ati&CHG) == CHG){
                        		    	//ubCHGFlag = 1;
                        		    //}
                        		    // ]
                        		    if((pr[SOFC]<=3) && (pr[UNITSEL]<3)){                       //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                        		        if ((attr[ax].ati&CHG) == CHG){
                        		    	    ubCHGFlag = 1;
                        		        }
                                    }
                        		    else{                                                      //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                                        if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){
                                		    if((ax == ACCEL1)||
                                               (ax == DECEL1)||
                                               (ax == JOGACC)||
                                               (ax == JOGDEC)||
                                               (ax == JOGF)  ||
                                               (ax == DECEL5)
                                             ){
                                                ubCHGFlag = 1;
                                            }
                                        }
                                    }
                                }
                        	}

                            // [ Velocity Unit Change, Add by DINO, 05/25/2009
							if (ubCHGFlag == 1){
								if (pr[UNITSEL] == 1){
									if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
										|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
										|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
										|| (ax == JOGDEC) || (ax == DECEL5))
										&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+'2'; 										
									}
									else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
											|| (ax == S4DEC2) || (ax == S4DEC3))
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+'3';
									}
									else{  // m/s
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+' ';
									}
								}
								else if (pr[UNITSEL] == 2){
									if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // ft/s2
										|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
										|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
										|| (ax == JOGDEC) || (ax == DECEL5))
										&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
										Descript[8]  = ('f'<<8)+'/';
										Descript[9] = ('s'<<8)+'2'; 										
									}
									else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // ft/s3
											|| (ax == S4DEC2) || (ax == S4DEC3))
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'3';
									}
									else{  // ft/s
									Descript[8]  = ('f'<<8)+'t';
									Descript[9] = ('/'<<8)+'s';
									}
								}
                                else if (pr[UNITSEL] == 3){                //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
									Descript[8]  = ('m'<<8)+'/';
									Descript[9] = ('s'<<8)+'2';
								}
							}
							// ]


                            ax = 0;
                            do{
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                                TxCntTemp++;
                                RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                                ax++;
                            }while(ax < DESMAX);
                            TxCntTemp = (bx<<1) + 2;
                        }
                        else
                            COM3Err = PC_CE03;
                    }
                 else{//Normal read parameter value
                        if ((RxBuf_3[3]+RxBuf_3[5]<=ax)&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                        	// [ Modify Read Function of Mapping Group, DINO, 07/02/2010
							ubGrNum = RxBuf_3[2];	// PR. Group
							ubPrNum = RxBuf_3[3];	// PR. Number
                 			uwAddr = prtab[ubGrNum] + ubPrNum;
							ax = 0;
                            RxBuf_3[2] = RxBuf_3[5]<<1;     // word->byte data_count
                            TxCntTemp = 2;
                            bx=RxBuf_3[5];  // data count //
                			do {   // prepare data //
#if ACCESS_GROUP
								if (ubGrNum == MAPGOURP){
    	    	        			umap_addr.ub.hi = pr[UMAP_ADD0+ubPrNum+ax] / 100;
                					umap_addr.ub.low = pr[UMAP_ADD0+ubPrNum+ax] - umap_addr.ub.hi * 100;
                                    
                                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                                        gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                                    else
                                        gpno = pr_gpno[umap_addr.ub.hi];

                					// Access to C21xx
                					if (umap_addr.ub.hi==21 && umap_addr.ub.low<C21MAX){
                					    if ( (DispAttr[umap_addr.ub.low].ati&JMP)==JMP && SHOW_ALLPR==0 ){
                					        rxdata = Unavaliable;
                					        umap_addr.ub.hi = 0;
                					    }
                					    else
                					    	rxdata = umap_addr.ub.low;
                					}
                					// Access to C22xx
                					else if (umap_addr.ub.hi==22 && umap_addr.ub.low<C22MAX){
                					    if ( (DispAttr[(umap_addr.ub.low+C21MAX-1)].ati&JMP)==JMP && SHOW_ALLPR==0 ){   //[solve the problem about access c22xx, Bernie, 2016/02/01]    // Modify by DINO, 09/08/2008
                					        rxdata = Unavaliable;
                					        umap_addr.ub.hi = 0;
                					    }
                					    else
                					    	rxdata = umap_addr.ub.low;
                					}
                					// Access to user parameter
                					else if ((umap_addr.ub.hi<=ACCESS  || SHOW_ALLPR==1) && umap_addr.ub.low<gpno){
            	    					rxdata = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    				}
            	    				// Access to unavailable address
            	    				else{
            	    					umap_addr.ub.hi = 0;
            	    					rxdata = Unavaliable;	// Unavailable parameter, display "Unavailable"
            	    				}

                                	// Access to C21xx
                                	if (umap_addr.ub.hi == 21){
                                	    TxCntTemp++;
                  						RxBuf_3[TxCntTemp] = ((UWORD)C21xx[rxdata]>>8);
                  						TxCntTemp++;
                  						RxBuf_3[TxCntTemp] = ((UWORD)C21xx[rxdata] & 0x00ff);
                                	}
                                	// Access to C22xx
                                	else if (umap_addr.ub.hi == 22){
                                	    TxCntTemp++;
                  						RxBuf_3[TxCntTemp] = ((UWORD)C22xx[rxdata]>>8);
                  						TxCntTemp++;
                  						RxBuf_3[TxCntTemp] = ((UWORD)C22xx[rxdata] & 0x00ff);
                                	}
                                	// Access to User Parameter
                                	else{
                                	    if ((rxdata>=BKTRANS1)&&(rxdata<=BKTRANS10)){
                                	        rxdata = BLKTransferRead(rxdata);
                                	        TxCntTemp++;
                                	        RxBuf_3[TxCntTemp]=((UWORD)rxdata>>8);
                  						    TxCntTemp++;
                  						    RxBuf_3[TxCntTemp]=((UWORD)rxdata & 0x00ff);
                                	    }
                                	    else{
                                	        TxCntTemp++;
                  						    RxBuf_3[TxCntTemp]=((UWORD)pr[rxdata]>>8);
                  						    TxCntTemp++;
                  						    RxBuf_3[TxCntTemp]=((UWORD)pr[rxdata] & 0x00ff);
                  						}
                  					}
								}
#endif
								else{
                					umap_addr.uw = uwAddr + ax;
                                    if ((umap_addr.uw>=BKTRANS1)&&(umap_addr.uw<=BKTRANS10)){
                                        rxdata = BLKTransferRead(umap_addr.uw);
                                        TxCntTemp++;
                                        RxBuf_3[TxCntTemp]=((UWORD)rxdata>>8);
                  					    TxCntTemp++;
                  					    RxBuf_3[TxCntTemp]=((UWORD)rxdata & 0x00ff);
                                    }
                                    else{
                                        TxCntTemp++;
                  					    RxBuf_3[TxCntTemp]=((UWORD)pr[umap_addr.uw]>>8);
                  					    TxCntTemp++;
                  					    RxBuf_3[TxCntTemp]=((UWORD)pr[umap_addr.uw] & 0x00ff);
                  					}
                  				}
                  				ax++;
                  				bx--;
                			}while(bx!=0);
                  			// ]
                		}
              			else  //Data length out of range
                			COM3Err = PC_CE03;
            		}
            	}
            	else  //Function number error
            		COM3Err = PC_CE02;
          	}
          	else //group number error
          		COM3Err = PC_CE02;
        }
        Init_TxData_3(TxCntTemp);
}

void RemoteCmd06_3(void)
{
    UWORD_UNION rxdata, umap_addr;
    UWORD ax, MaxTemp, MinTemp/*, uwParData*/;
    UBYTE gpno,TxCntTemp = 0;

    if (RxBuf_3[2] == 0x20){            // Communication Memory Address 20xxH
        if (RxBuf_3[3] < C20MAX){
            TxCntTemp = Rx3CNT;
            rxdata.ub.hi = RxBuf_3[4];
            rxdata.ub.low = RxBuf_3[5];
            Keypad_20xxH(RxBuf_3[3],rxdata.uw);
        }
        else
        	COM3Err = PC_CE02;
    }
    else if (RxBuf_3[2] == 0x21){    //21xx read only
		COM3Err = PC_CE04;
    }
    else if (RxBuf_3[2] == 0x23){    //23xx read only
		COM3Err = PC_CE04;
    }
/*    // [ Display Group for VLI, DINO, 03/22/2010
    else if (RxBuf_1[2] == 0x2A){    //2Axx read only
		COM1Err = PC_CE04;
    }*/
    // ]
#if !SH7286 //Sean, 01/25/2010    
    else if (RxBuf_3[2] == 0xff){
		if (RxBuf_3[3]<CALIMAX){
            if ((RxBuf_3[3]==0||RxBuf_3[3]==CFFxx[0]) && (SHOW_ALLPR==1)){
                TxCntTemp = Rx3CNT;
                rxdata.ub.hi = RxBuf_3[4];
                rxdata.ub.low = RxBuf_3[5];
                if (RxBuf_3[3]==0)
                    CFFxx[0] = rxdata.uw;
                else
                    FFcalibration1(RxBuf_3[3],rxdata.uw);
            }
            else
                COM3Err = PC_CE04;
        }
        else
            COM3Err = PC_CE02;
    }	        
#else    
#if SH7147  /* dino, 05/08/2007 */
    else if (RxBuf_3[2] == 0xff){
		if (RxBuf_3[3]<CALIMAX){
            if ((RxBuf_3[3]==0||RxBuf_3[3]==CFFxx[0]) && (SHOW_ALLPR==1)){
                TxCntTemp = Rx3CNT;
                rxdata.ub.hi = RxBuf_3[4];
                rxdata.ub.low = RxBuf_3[5];
                if (RxBuf_3[3]==0)
                    CFFxx[0] = rxdata.uw;
                else
                    FFcalibration3(RxBuf_3[3],rxdata.uw);
            }
            else
                COM3Err = PC_CE04;
        }
        else
            COM3Err = PC_CE02;
    }	    
#endif
#endif
    else 
    {
        if (SHOW_ALLPR==1)
        {
    	    ax = GRALL;
        }
        else
        {
        	// [ 00-02 Setting, DINO, 06/03/2010
			if (SHOW_ENHANCE==1)
        		ax = GRENHANCE;
        	else
        	// ]
				ax = GRUSER;        
		}
        
        /*---------------------------------------------------------------------------------
          - rxbuf[0]=adrr; rxbuf[1]=cmd_code; rxbuf[2]=gp_n0; rxbuf[3]=fn_no (data_addr)
          - rxbuf[4]_rxbuf[5]=data;
         ---------------------------------------------------------------------------------*/
        if (RxBuf_3[2]<=ax) {      // group NO. //
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	ax = pr_gpno_Sibo[RxBuf_3[2]];
            else
            	ax = pr_gpno[RxBuf_3[2]];
            
            if (RxBuf_3[3]<ax){     // function NO. //
                if ((PUON3LINE==1)||(RxBuf_3[0]==0xFF))
                    KEYPAD_CMD = 1;                
                else
                    KEYPAD_CMD = 0;
#if ACCESS_GROUP
				if (RxBuf_3[2] == MAPGOURP){
                	umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_3[3]] / 100;
                	umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_3[3]] - umap_addr.ub.hi * 100;
                    
                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                        gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                    else
                        gpno = pr_gpno[umap_addr.ub.hi];

          			// [ Mapping to hidden parameters, DINO, 12/23/2009
          			if ( (umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno )
//          			if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] )
            	    	ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    // ]
            	    else
            	    	ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
				}
				else
#endif
               	ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3];     // pr index //

                TxCntTemp = Rx3CNT;
                rxdata.ub.hi = RxBuf_3[4];
                rxdata.ub.low = RxBuf_3[5];
                
				MaxTemp = GetParMax(ax);
                MinTemp = GetParMin(ax);

				if ((attr[ax].ati&SIGN)!=0)
                {
	                if (((SWORD)rxdata.uw<=(SWORD)MaxTemp)&&((SWORD)rxdata.uw>=(SWORD)MinTemp))
                    {   
    	                write_pr(ax,rxdata.uw);
                    }
    	            else
                    {   
                        //SCOTTY ADD 08/31/2007
    	            	KEYEND = ERR;				//SCOTTY ADD 08/31/2007
                    }
    	        }
    	        else
                {
	                if ((rxdata.uw<=MaxTemp)&&(rxdata.uw>=MinTemp))
                    {   
    	                write_pr(ax,rxdata.uw);
                    }
    	            else
                    {   
                        //SCOTTY ADD 08/31/2007
    	            	KEYEND = ERR;    	        //SCOTTY ADD 08/31/2007
                    }
				}                

                if (KEYEND==ERR)
                {
                    COM3Err = PC_CE02;
                }

                KEYPAD_CMD = 0;         
            }
            else
            {
                COM3Err = PC_CE02;   // Illegal function NO. //
            }
        }
        else
        {
            COM3Err = PC_CE02;   // Illegal group NO. //
        }
    }
    Init_TxData_3(TxCntTemp);
}

void RemoteCmd63_3(void)
{
    UBYTE TxCntTemp = 0, bx, ubCHGFlag,gpno;
    UWORD ax;
    UWORD_UNION umap_addr;
    UWORD_UNION uwEEPData;
    
    umap_addr.uw = 0;
        
    if (RxBuf_3[2] == 0x20){            // Communication Memory Address 20xxH               
        ax = RxBuf_3[3];
        if ((C20MAX >= (ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
            RxBuf_3[2] = RxBuf_3[5]<<1;         // word->byte data_count
            TxCntTemp = 2;
            bx = RxBuf_3[5];                  // data count //
            //Data Content
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = (UBYTE)(C20xx[ax]>>8);
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = (UBYTE)(C20xx[ax]);
            //Data Max
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0xff;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0xff;
            //Data Min
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            //Data attribute
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            //Data default
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            //Data Description
            ShowDescription(c20info[ax]);
            ax = 0;
            do{
                TxCntTemp++;
                RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                TxCntTemp++;
                RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                ax++;
            }while(ax < DESMAX);
            TxCntTemp = (bx<<1) + 2;
        }
        else
            COM3Err = PC_CE03;
    }        
    else if (RxBuf_3[2]==0x21){
        ax = RxBuf_3[3];
        if ((C21MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
            //Update_C21xx();
            RxBuf_3[2] = RxBuf_3[5]<<1;           // word->byte data_count
            TxCntTemp = 2;
            bx = RxBuf_3[5];                    // data count //
            //Data Content
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
            //Data Max
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0xff;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0xff;
            //Data Min
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            //Data attribute
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = DispAttr[ax].ati>>8;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = DispAttr[ax].ati&0x00ff;
            //Data default
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_3[TxCntTemp] = 0x00;
            //Data Description
            ax = umap_addr.ub.low;        //[solve the problem about access c22xx, Bernie, 2016/02/01]

            ShowDescription(c21info[ax]);
			// [ Velocity Unit Change, Add by DINO, 05/25/2009
			if ((DispAttr[ax].ati&CHG) == CHG){
				if (pr[UNITSEL] == 1){
					Descript[8]  = ('m'<<8)+'/';
					Descript[9] = ('s'<<8)+' ';
				}
				else if (pr[UNITSEL] == 2){
					Descript[8]  = ('f'<<8)+'t';
					Descript[9] = ('/'<<8)+'s';
				}
                else if (pr[UNITSEL] == 3){            //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
					Descript[8]  = ('m'<<8)+'/';
					Descript[9] = ('s'<<8)+'2';
				}
			}
			// ]
            ax = 0;
            do{
                TxCntTemp++;
                RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                TxCntTemp++;
                RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                ax++;
            }while(ax < DESMAX);
            TxCntTemp = (bx<<1) + 2;
        }
        else
            COM3Err = PC_CE03;
    }
    else{
        if (SHOW_ALLPR==1)
            ax = GRALL;
        else{

		    if (SHOW_ENHANCE==1)
        	    ax = GRENHANCE;
    	    else
			    ax = GRUSER;
	    }

        if (RxBuf_3[2]<=ax){        // group number //
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	ax = pr_gpno_Sibo[RxBuf_3[2]];
            else
            	ax = pr_gpno[RxBuf_3[2]];
            if (RxBuf_3[3]< ax) {    // function number //            
                //Data,Max,Min,Att,Def
                if ((RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
#if ACCESS_GROUP
					if (RxBuf_3[2] == MAPGOURP){
                		umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_3[3]] / 100;
                		umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_3[3]] - umap_addr.ub.hi * 100;
                        if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                            gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                        else
                            gpno = pr_gpno[umap_addr.ub.hi];
                		// Access to C21xx
                		if ( umap_addr.ub.hi==21 && umap_addr.ub.low<C21MAX ){
                		    if ( (DispAttr[umap_addr.ub.low].ati&JMP)==JMP && SHOW_ALLPR==0 ){
                		        ax = Unavaliable;
                		        umap_addr.ub.hi = 0;
                		    }
                		    else
                		    	ax = umap_addr.ub.low;
                		}
                		// Access to C22xx
                		else if ( umap_addr.ub.hi==22 && umap_addr.ub.low<C22MAX ){
                		    if ( (DispAttr[(umap_addr.ub.low+C21MAX-1)].ati&JMP)==JMP && SHOW_ALLPR==0 ){  //[solve the problem about access c22xx, Bernie, 2016/02/01]    // Modify by DINO, 09/08/2008
                		        ax = Unavaliable;
                		        umap_addr.ub.hi = 0;
                		    }
                		    else
                		    	ax = umap_addr.ub.low;
                		}
                		// Access to user parameter
                		// [ Mapping to hidden parameters, DINO, 12/23/2009
                		else if ( (umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno)
//                		else if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] )
            	    		ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    	// ]
            	    	// Access to unavailable address
            	    	else{
            	    		umap_addr.ub.hi = 0;
            	    		ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
            	    	}
					}
					else
#endif
	                    ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3]; // pr index //                                

#if ACCESS_GROUP
					// [ Velocity Unit Change, Add by DINO, 05/25/2009
					ubCHGFlag = 0;
					// ]

					if ( umap_addr.ub.hi==21 ){
                        //Update_C21xx();
                        ax = umap_addr.ub.low;     //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        RxBuf_3[2] = RxBuf_3[5]<<1;           // word->byte data_count
                        TxCntTemp = 2;
                        bx = RxBuf_3[5];                    // data count //
                        //Data Content
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                        //Data Max
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0xff;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0xff;
                        //Data Min
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        //Data attribute
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = DispAttr[ax].ati>>8;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = DispAttr[ax].ati&0x00ff;
                        //Data default
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        //Data Description
                        ax = umap_addr.ub.low;       //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        ShowDescription(c21info[ax]);
						// [ Velocity Unit Change, Add by DINO, 05/25/2009
						if ((DispAttr[ax].ati&CHG) == CHG){
							ubCHGFlag = 1;
                        }
                        // ]
					}
					else if ( umap_addr.ub.hi==22 ){
					    ax = umap_addr.ub.low;         //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        //Update_C21xx();
                        RxBuf_3[2] = RxBuf_3[5]<<1;           // word->byte data_count
                        TxCntTemp = 2;
                        bx = RxBuf_3[5];                    // data count //
                        //Data Content
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = ((UWORD)C22xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = ((UWORD)C22xx[ax] & 0x00ff);
                        //Data Max
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0xff;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0xff;
                        //Data Min
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        //Data attribute
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = DispAttr_c22xx[(ax)].ati>>8;            //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = DispAttr_c22xx[(ax)].ati&0x00ff;        //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        //Data default
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = 0x00;
                        //Data Description
                        ax = umap_addr.ub.low;                //[solve the problem about access c22xx, Bernie, 2016/02/01]

                        ShowDescription(c22info[ax]);
					}
#endif
					else{
                        bx = RxBuf_3[5];
                        TxCntTemp = 2;
                        RxBuf_3[2] = RxBuf_3[5]<<1;
                        TxCntTemp++;
                        // [ Velocity Unit Change, Add by DINO, 05/25/2009
                        uwEEPData.uw = GetParData(ax);
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
						// ]

						uwEEPData.uw = GetParMax(ax);
						TxCntTemp++;
						RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
						TxCntTemp++;
						RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
						
						uwEEPData.uw = GetParMin(ax);
						TxCntTemp++;
						RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
						TxCntTemp++;
						RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#if DINO  // 10/19/2007
						uwEEPData.uw = GetParAttr(ax);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#else
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#endif

//-- Add by VE item91, 10/30/2008
						if ((pr[HPSPEC]&VFD440V)==VFD220V){    // 220V class
#if DINO
							if ( (attr[ax].ati&V440)==V440 )
								uwEEPData.uw = attr[ax].def>>1;
							else
								uwEEPData.uw = attr[ax].def;
#else
                            switch(ax){
                                case VMAX1:
                            	case VMID1_1:
                            	case VMID1_2:
                            	case VMIN1:    
                            	case LVL:	
                            	case STALL4V:
                            	case DCBRK4V:
                            	case VMAX2:
                            	case VMID2_1:
                            	case VMID2_2:
                            	case VMIN2:
                            	case PHL_L:
                                    uwEEPData.uw = attr[ax].def>>1;
                                    break;
                                default:
                                    uwEEPData.uw = attr[ax].def;
                                    break;
                            }
#endif
						}
						else{
						    uwEEPData.uw = attr[ax].def;
						}
//-- End on 10/30/2008
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
                        
                        //Data Description
                        //ShowDescription(prinfo[ax]);
						// [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                        if ((C20xx[0x05]&0xff00) == 0x0200){
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                #if Language_TC
                                ShowDescription(prinfo_tc[ax]);
                                #else
                                ShowDescription(prinfo[ax]);
                                #endif
                            }
                            else{
                                #if Language_TC
                            	// JINGDO
                            	if(pr[FLOOR_PAGE]==1)
                              	ShowDescription(prinfo_tc_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                            	else if(pr[FLOOR_PAGE]==2)
                            		ShowDescription(prinfo_tc_DLC2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		    ShowDescription(prinfo_tc_DLC3[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_tc_Adjst[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_tc_Adjst2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_tc_Adjst3[(ax-DLC_PR)]);
                                #else
                            	if(pr[FLOOR_PAGE]==1)
                              	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                            	else if(pr[FLOOR_PAGE]==2)
                            		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                #endif
                            }
                        }
                        else if ((C20xx[0x05]&0xff00) == 0x0300){
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                #if Language_SC
                                ShowDescription(prinfo_sc[ax]);
                                #else
                                ShowDescription(prinfo[ax]);
                                #endif
                            }
                            else{
                                #if Language_SC
                            	// JINGDO
                            	if(pr[FLOOR_PAGE]==1)
                              	ShowDescription(prinfo_sc_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                            	else if(pr[FLOOR_PAGE]==2)
                            		ShowDescription(prinfo_sc_DLC2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		    ShowDescription(prinfo_sc_DLC3[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                                #else
                            	if(pr[FLOOR_PAGE]==1)
                              	ShowDescription(prinfo_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                            	else if(pr[FLOOR_PAGE]==2)
                            		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                #endif
                            }
                        }
                        else{
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                ShowDescription(prinfo[ax]);
                            }
                            else{
                            	// JINGDO
                            	if(pr[FLOOR_PAGE]==1)
                                ShowDescription(prinfo_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                            	else if(pr[FLOOR_PAGE]==2)
                            		ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                              	    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                            }
                        }
                        // ]
						// [ Velocity Unit Change, Add by DINO, 05/25/2009
						if ((attr[ax].ati&CHG) == CHG){
							ubCHGFlag = 1;
						}
						// ]
						if((pr[SOFC]<=3) && (pr[UNITSEL]<3)){                         //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                            if ((attr[ax].ati&CHG) == CHG){
                        	    ubCHGFlag = 1;
                        	}
                        }
                        else{                                                        //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                            if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){
                                if((ax == ACCEL1)||
                                   (ax == DECEL1)||
                                   (ax == JOGACC)||
                                   (ax == JOGDEC)||
                                   (ax == JOGF)  ||
                                   (ax == DECEL5)
                                ){
                                    ubCHGFlag = 1;
                                }
                             }
                         }
                	}

                    // [ Velocity Unit Change, Add by DINO, 05/25/2009
					if (ubCHGFlag == 1){
						if (pr[UNITSEL] == 1){
							if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
								|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
								|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
								|| (ax == JOGDEC) || (ax == DECEL5))
								&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
							Descript[8]  = ('m'<<8)+'/';
								Descript[9] = ('s'<<8)+'2'; 										
							}
							else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
									|| (ax == S4DEC2) || (ax == S4DEC3))
									&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
								Descript[8]  = ('m'<<8)+'/';
								Descript[9] = ('s'<<8)+'3';
							}
							else{  // m/s
								Descript[8]  = ('m'<<8)+'/';
							Descript[9] = ('s'<<8)+' ';
							}
						}
						else if (pr[UNITSEL] == 2){
							if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // ft/s2
								|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
								|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
								|| (ax == JOGDEC) || (ax == DECEL5))
								&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
								Descript[8]  = ('f'<<8)+'/';
								Descript[9] = ('s'<<8)+'2'; 										
							}
							else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // ft/s3
									|| (ax == S4DEC2) || (ax == S4DEC3))
									&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
								Descript[8]  = ('f'<<8)+'/';
								Descript[9] = ('s'<<8)+'3';
							}
							else{  // ft/s
							Descript[8]  = ('f'<<8)+'t';
							Descript[9] = ('/'<<8)+'s';
							}
						}
                        else if (pr[UNITSEL] == 3){               //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
							Descript[8]  = ('m'<<8)+'/';
							Descript[9] = ('s'<<8)+'2';
						}
					}
					// ]


                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                    }while(ax < DESMAX);
                    TxCntTemp = (bx<<1) + 2;
                }
                else
                    COM3Err = PC_CE03;
            }          
            else  //Function number error
                COM3Err = PC_CE02;
        }
        else //group number error
            COM3Err = PC_CE02;
    }
    Init_TxData_3(TxCntTemp);
}

void RemoteCmd10_3(void)
{
        /* rxbuf[0]=adrr; rxbuf[1]=cmd_code;rxbuf[2]=gp_n0; rxbuf[3]=fn_no (data_addr)
           rxbuf[4]_rxbuf[5]=word_data_count; rxbuf[6,7...]=data_1, data2.....          */

        UWORD_UNION rxdata;
        UBYTE ax,bx,TxCntTemp = 0; 
        UWORD rinx, MaxTemp, MinTemp;

        if (RxBuf_3[2]==0x20){            // Communication Memory Address 20xxH
          ax = RxBuf_3[3];
          if ((C20MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
            bx=RxBuf_3[5];
            TxCntTemp=7;
            do {
              rxdata.ub.hi=RxBuf_3[TxCntTemp];
              rxdata.ub.low=RxBuf_3[TxCntTemp+1];
              Keypad_20xxH(ax,rxdata.uw);              
              TxCntTemp += 2;
              ax++;
              bx--;
            } while (bx!=0);
          }
          else
            COM3Err=PC_CE03;   // Illegal uw count //
        }
			else if (RxBuf_3[2]==0x21)
				COM3Err=PC_CE04;                    // read only
			else {

				if (SHOW_ENHANCE==1)
					ax = GRENHANCE;
			 	else
					ax = GRUSER;

          if (PRLOCK==1 || FSET_LOCK==1)
            ax = GRALL;
          if (RxBuf_3[2]<=ax) {    // group NO.
            // get the no of pr 
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	bx = pr_gpno_Sibo[RxBuf_3[2]];
            else
            	bx = pr_gpno[RxBuf_3[2]];

            if ((RxBuf_3[3]+RxBuf_3[5])<=bx) {  // function NO.
              ax = RxBuf_3[3];
              if ((RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
                if ((PUON3LINE==1)||(RxBuf_3[0]==0xFF))
                    KEYPAD_CMD = 1;                
                else
                    KEYPAD_CMD = 0;             
                bx=RxBuf_3[5];
                TxCntTemp=7;
                do {
                  rinx=prtab[RxBuf_3[2]]+ax;  // pr index
                  rxdata.ub.hi=RxBuf_3[TxCntTemp];
                  rxdata.ub.low=RxBuf_3[TxCntTemp+1];
                  MaxTemp = GetParMax(rinx);
                  MinTemp = GetParMin(rinx);
                  if ((rxdata.uw <= MaxTemp) && (rxdata.uw >= MinTemp))
                    write_pr(rinx,rxdata.uw);
                    if (KEYEND==ERR)
                        COM3Err = PC_CE02;
                  TxCntTemp += 2;
                  ax++;
                  bx--;
                } while (bx!=0);
                KEYPAD_CMD = 0;
              }
              else
                COM3Err=PC_CE03;   // Illegal uw count
            }
            else
              COM3Err=PC_CE02;     // Illegal function number
          }
          else
            COM3Err=PC_CE02;       // Illegal group number
        }
        Init_TxData_3(5);
}
void RemoteCmd65_3(void)    //[UD protocal, Bernie, 2012/12/05]
{
    UBYTE ax,bx,cx;
    UWORD_UNION uwTemp1,uwTemp2;
    SWORD_UNION swTemp1;
    SWORD swTemp2;
    SLONG (*mfai_ptr)(UBYTE,SWORD);
    UWORD_UNION TX_CRC_Result1;


//====================== Rx ======================//    
    ax = RxBuf_3[6];

    //========== Byte 6 ==========//
    //if (RxBuf_1[6]!=0x00){ 
        
        //====== bit7 ======//
        if((ax&0x80)!=0){
            reset();
        }
        //====== bit6 ======//
        if((ax&0x40)==0){
            RxBuf_3[4] = 0x00;
            RxBuf_3[5] = 0x01;
            RemoteCmd65_3_RdData();
        }
        else{
            RemoteCmd65_3_WrData();
        }
        //====== bit3 ======//
        if((ax&0x08)==0){ 
            EXT_ENABLE = 1;    //disable
            stop(); 
        }
        else{
            EXT_ENABLE = 0;    //enable
        }
        //====== bit2======//
        if((ax&0x04)!=0){
            if (!CMDJOG &&(EXT_ENABLE==0)){
                LIFT_RUNCMD = 1;
                run();
                
            }
        }
        else{
            
            LIFT_RUNCMD = 0;
            stop();
        }
        //====== bit1 & bit0 ======//
        if(((ax&0x03)!=0)&&(TUN_START==0)&&((PWM_Status.ub&0x42)==0)&&(!EPS_MODE4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]    //GEN_OK3 = 0; GEN_START = 0;
             bx = ax&0x03;
             switch(bx){
                case 0x01: {          // forward direction
                    if (pr[SETDIR]!=2) {    // disable forward 
                        CMDDIR=FORWARD;
                        if (RUNNING==STOP)
                            WGDIR = FORWARD;
                    }
                } break;
                case 0x02: {          // reverse direction
                    if (pr[SETDIR]!=1) {    // disable reverse
                        CMDDIR=REVERSE;                  
                        if (RUNNING==STOP)
                            WGDIR = REVERSE;
                    }
                }break;
                default:
                    break;
             }
       }
    
    //}
    //else
        //stop();

    //========== Byte 7 ==========//
       swTemp2 = RxBuf_3[7];
       swTemp2 = (4095/0xff)*swTemp2;

       mfai_ptr = mfai_tbl[3];
       
       AVIslFunVar_1 = (*mfai_ptr)(1,swTemp2);

    //==========  Byte11 ==========//

    //if((RxBuf_1[12]!=0x00)||(RxBuf_1[11]!=0x00)){
        uwTemp1.ub.low= RxBuf_3[11];
	    uwTemp1.ub.hi = RxBuf_3[10];
        //Fcmd = uwTemp1.uw;
        if ((pr[SOFC]==1)||(PUON3LINE && OPKEY_LOCK==0)){
         PCRemote2001H(uwTemp1.uw);
        }

    Init_TxData_3(13);
    //}

//====================== Tx ======================//
    //if(RxBuf_1[1]==0x65){
        cx = 0;
    //========== Byte6 ==========//
       //====== bit7 ======//
         if(Error == 0 && PGREADY == 1)
             cx |= 0x80;
       //====== bit6 ======//
         if(Error == 0)
             cx |= 0x40;
       //====== bit5 ======//
       
       //====== bit4 ======//  
         if(WarnCode!=0)
             cx |= 0x10;
       //====== bit3 ======//  
         if(ABV_CURT == 0)
             cx |= 0x08;
       //====== bit2 ======//  
         if(BRK_RLS==1)         //Release bit2 = 1     Lock bit2 = 0 
             cx |= 0x04;
       //====== bit1 ======//
         if(WGDIR == FORWARD) //|| WGDIR == REVERSE)  //bit7
             cx |= 0x02;
       //====== bit0 ======//
         if(RUNNING==RUN)     //bit0  RUN = 1  STOP = 0
             cx |= 0x01;
  
    TxBuf_3[6] = cx;
    //}  
   //========== Byte7 ==========//
    TxBuf_3[7] = 0x00;

   //========== Byte8 9 ==========//
    uwTemp2.uw = fout.uw.hi;
	TxBuf_3[8] = uwTemp2.ub.hi;
    TxBuf_3[9] = uwTemp2.ub.low;

   //========== Byte10 11 ==========//
    TxBuf_3[10] = Error;
    TxBuf_3[11] = WarnCode;
    
   //========== Byte12 13 ==========//
    swTemp1.sw = IrmsReLPF.sw.hi;
    TxBuf_3[12] = swTemp1.sb.hi;
    TxBuf_3[13] = swTemp1.sb.low;
    
    TX_CRC_Result1.uw = CRC_CHECK_UD(13);
    Tx3CNT =  13 + 1;
    TxBuf_3[Tx3CNT] = TX_CRC_Result1.ub.low;
    Tx3CNT++;
    TxBuf_3[Tx3CNT] = TX_CRC_Result1.ub.hi;


}


void RemoteCmd65_3_WrData(void)         //[UD protocal, Bernie, 2012/12/05]
{
    UWORD_UNION rxdata, umap_addr;
    UWORD ax, MaxTemp, MinTemp, uwParData;
    UBYTE gpno,TxCntTemp = 0;

    if (RxBuf_3[2] == 0x20){            // Communication Memory Address 20xxH
        if (RxBuf_3[3] < C20MAX){
            TxCntTemp = Rx3CNT;
            rxdata.ub.hi = RxBuf_3[4];
            rxdata.ub.low = RxBuf_3[5];
            Keypad_20xxH(RxBuf_3[3],rxdata.uw);
        }
        else
        	COM3Err = PC_CE02;
    }
    else if (RxBuf_3[2] == 0x21){    //21xx read only
		COM3Err = PC_CE04;
    }
    else if (RxBuf_3[2] == 0x23){    //23xx read only
		COM3Err = PC_CE04;
    }
/*    // [ Display Group for VLI, DINO, 03/22/2010
    else if (RxBuf_1[2] == 0x2A){    //2Axx read only
		COM1Err = PC_CE04;
    }*/
    // ]
#if !SH7286 //Sean, 01/25/2010    
    else if (RxBuf_3[2] == 0xff){
		if (RxBuf_3[3]<CALIMAX){
            if ((RxBuf_3[3]==0||RxBuf_3[3]==CFFxx[0]) && (SHOW_ALLPR==1)){
                TxCntTemp = Rx3CNT;
                rxdata.ub.hi = RxBuf_3[4];
                rxdata.ub.low = RxBuf_3[5];
                if (RxBuf_3[3]==0)
                    CFFxx[0] = rxdata.uw;
                else
                    FFcalibration3(RxBuf_3[3],rxdata.uw);
            }
            else
                COM3Err = PC_CE04;
        }
        else
            COM3Err = PC_CE02;
    }	        
#else    
#if SH7147  /* dino, 05/08/2007 */
    else if (RxBuf_3[2] == 0xff){
		if (RxBuf_3[3]<CALIMAX){
            if ((RxBuf_3[3]==0||RxBuf_3[3]==CFFxx[0]) && (SHOW_ALLPR==1)){
                TxCntTemp = Rx3CNT;
                rxdata.ub.hi = RxBuf_3[4];
                rxdata.ub.low = RxBuf_3[5];
                if (RxBuf_3[3]==0)
                    CFFxx[0] = rxdata.uw;
                else
                    FFcalibration3(RxBuf_3[3],rxdata.uw);
            }
            else
                COM3Err = PC_CE04;
        }
        else
            COM3Err = PC_CE02;
    }	    
#endif
#endif
    else {
        if (SHOW_ALLPR==1)
        	ax = GRALL;
        else{
        	// [ 00-02 Setting, DINO, 06/03/2010
			if (SHOW_ENHANCE==1)
        		ax = GRENHANCE;
        	else
        	// ]
				ax = GRUSER;        
		}
        
        /*---------------------------------------------------------------------------------
          - rxbuf[0]=adrr; rxbuf[1]=cmd_code; rxbuf[2]=gp_n0; rxbuf[3]=fn_no (data_addr)
          - rxbuf[4]_rxbuf[5]=data;
         ---------------------------------------------------------------------------------*/
        if (RxBuf_3[2]<=ax) {      // group NO. //
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	ax = pr_gpno_Sibo[RxBuf_3[2]];
            else
            	ax = pr_gpno[RxBuf_3[2]];
            if (RxBuf_3[3]<ax){     // function NO. //
                if ((PUON3LINE==1)||(RxBuf_3[0]==0xFF))
                    KEYPAD_CMD = 1;                
                else
                    KEYPAD_CMD = 0;
#if ACCESS_GROUP
				if (RxBuf_3[2] == MAPGOURP){
                	umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_3[3]] / 100;
                	umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_3[3]] - umap_addr.ub.hi * 100;
                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                        gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                    else
                        gpno = pr_gpno[umap_addr.ub.hi];
          			// [ Mapping to hidden parameters, DINO, 12/23/2009
          			if ( (umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno )
//          			if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] )
            	    	ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    // ]
            	    else
            	    	ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
				}
				else
#endif
               	ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3];     // pr index //

                TxCntTemp = Rx3CNT;
                rxdata.ub.hi = RxBuf_3[4];
                rxdata.ub.low = RxBuf_3[5];
                
				MaxTemp = GetParMax(ax);
                MinTemp = GetParMin(ax);

				if ((attr[ax].ati&SIGN)!=0){
	                if (((SWORD)rxdata.uw<=(SWORD)MaxTemp)&&((SWORD)rxdata.uw>=(SWORD)MinTemp))
    	                write_pr(ax,rxdata.uw);
    	            else 							//SCOTTY ADD 08/31/2007
    	            	KEYEND = ERR;				//SCOTTY ADD 08/31/2007
    	        }
    	        else{
	                if ((rxdata.uw<=MaxTemp)&&(rxdata.uw>=MinTemp))
    	                write_pr(ax,rxdata.uw); 
    	            else 							//SCOTTY ADD 08/31/2007
    	            	KEYEND = ERR;    	        //SCOTTY ADD 08/31/2007    	        	
				}                

                if (KEYEND==ERR)
                    COM3Err = PC_CE02;          

                KEYPAD_CMD = 0;         
            }
            else
                COM3Err = PC_CE02;   // Illegal function NO. //
        }
        else
            COM3Err = PC_CE02;   // Illegal group NO. //
    }

}
void RemoteCmd65_3_RdData(void)             //[UD protocal, Bernie, 2012/12/05]
    {
            UBYTE TxCntTemp=0, bx, ubCHGFlag, ubGrNum, ubPrNum, HPSPEC_temp,gpno;
            UWORD TempValue, ax, rxdata, uwAddr;
            UWORD_UNION umap_addr, uwEEPData;
            
            umap_addr.uw = 0;
    
            if (RxBuf_3[2] == 0x20){            // Communication Memory Address 20xxH               
                ax = RxBuf_3[3];
                if ((C20MAX >= (ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                    RxBuf_3[2] = RxBuf_3[5]<<1;         // word->byte data_count
                    //TxCntTemp = 2;
                    TxCntTemp = 3;
                    //bx = RxBuf_1[5];                  // data count //
                    do {                          // prepare data //
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(C20xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = (UBYTE)(C20xx[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
            }
            else if (RxBuf_3[2]==0x21){
                ax = RxBuf_3[3];
                if ((C21MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
                    Update_C21xx();
                    RxBuf_3[2] = RxBuf_3[5]<<1;           // word->byte data_count
                    //TxCntTemp = 2;
                    //bx = RxBuf_1[5];                    // data count //
                    TxCntTemp = 3;
                    do {                            // prepare data //
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
            }
            else if (RxBuf_3[2]==0x22) {
                ax = RxBuf_3[3];
                if ((C22MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                    RxBuf_3[2]=RxBuf_3[5]<<1;
                    //TxCntTemp = 2;
                    //bx = RxBuf_1[5];
                    TxCntTemp = 3;
                    Update_C22xx();
                    do {                            // prepare data //
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(C22xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(C22xx[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
            }
            else if (RxBuf_3[2]==0x23) {
                ax = RxBuf_3[3];
                if ((C23MAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                    RxBuf_3[2]=RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
                    Update_KeypadDisp();
                    do {                            // prepare data //
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(KC23xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(KC23xx[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
            }
            else if (RxBuf_3[2]==0x24){
                    ax = RxBuf_3[3];
                    if ((DESMAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                    RxBuf_3[2] = RxBuf_3[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_3[5];
                    Update_LCDescription();
                    do {                            // prepare data //
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_3[TxCntTemp]=(UBYTE)(Descript[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM3Err = PC_CE03;
            }

    //---Add BY Dino 06/25/2007---
            /*else if (RxBuf_1[2]==0xff){
                if((RxBuf_1[3]< CALIMAX)&&(RxBuf_1[5]!=0)&&(RxBuf_1[5]<=DATA_LEN)&&(RxBuf_1[4]==0)){
                    if(SHOW_ALLPR==1){ //FF - 00 -00
                        RxBuf_1[2]=RxBuf_1[5]<<1;
                        TxCntTemp = 2;
                        bx = RxBuf_1[5];
                        ax = RxBuf_1[3];
                        do {                          // prepare data //
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp]=(UBYTE)(CFFxx[ax]>>8);
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp]=(UBYTE)(CFFxx[ax]);
                            ax++;
                            bx--;
                        } while(bx!=0);
                    }
                    else
                        COM1Err = PC_CE03;
                                            
                }
                else
                    COM1Err = PC_CE03;
            }*/   
            /*else if ((RxBuf_1[2]<=0xF3)&&(RxBuf_1[2]>=0xC0)){ // Communication Memory Address >= 80xxH + SFR(0300~03FF)
                ax = ((UWORD)RxBuf_1[2]<<8) + RxBuf_1[3];
                if ((RxBuf_1[5]!=0)&&(RxBuf_1[5]<=DATA_LEN)&&(RxBuf_1[4]==0)) {
                    RxBuf_1[2] = RxBuf_1[5]<<1;     // word->byte data_count
                    TxCntTemp = 2;
                    bx = RxBuf_1[5];                // data count //
                    do {                            // prepare data //
                        TxCntTemp++;
                        RxBuf_1[TxCntTemp] = (UBYTE)(MEMADDR[ax]>>8);
                        TxCntTemp++;
                        RxBuf_1[TxCntTemp] = (UBYTE)(MEMADDR[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM1Err = PC_CE03;
            }*/
    //---END 06/25/2007---------------  
           /* else if (RxBuf_1[2]==0x31){
                if (RxBuf_1[3]<=GROUPTmp){
                    if (RxBuf_1[5]<=DESMAX){                
                        RxBuf_1[2] = RxBuf_1[5]<<1;
                        TxCntTemp = 2;
                        bx = RxBuf_1[5];
                            //ShowDescription(gpname[RxBuf_1[3]]);
                        // [ Traditional Chinese Display, Add by DINO, 09/28/2010
                        if ((C20xx[0x05]&0xff00) == 0x0200)
                            ShowDescription(gpname_tc[RxBuf_1[3]]);
                        else if ((C20xx[0x05]&0xff00) == 0x0300)
                            ShowDescription(gpname_sc[RxBuf_1[3]]);
                        else
                            ShowDescription(gpname[RxBuf_1[3]]);
                        // ]
                        ax = 0;
                        do{
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)Descript[ax];
                            ax++;
                            bx--;
                        }while(bx!=0);
                    }
                    else
                        COM1Err = PC_CE03;
                                            
                }
                else
                    COM1Err = PC_CE02;
            }   */     
          /*  else if (RxBuf_1[2]==0x32){
                if (RxBuf_1[3]<=ERRMAX){
                    if (RxBuf_1[5]<=(DESMAX+0x04)){  // For VFD-Cx, DINO, 03/16/2010
                        RxBuf_1[2] = RxBuf_1[5]<<1;
                        TxCntTemp = 2;
                        bx = RxBuf_1[5];
                        if (Error!=0){
                            
                                //ShowDescription(errinfo[Error]);  // RxBuf_1[0] ~ RxBuf_1[19]
                            if ((C20xx[0x05]&0xff00) == 0x0200)
                                ShowDescription(errinfo_tc[Error]); 
                            else if ((C20xx[0x05]&0xff00) == 0x0300)
                                ShowDescription(errinfo_sc[Error]); 
                            else
                                ShowDescription(errinfo[Error]); 
    
                        }
                    
                        ax = 0;
                        do{
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)Descript[ax];
                            ax++;
                            bx--;
                        }while(bx!=0);
                    }
                    else
                        COM1Err = PC_CE03;
                                            
                }
                else
                    COM1Err = PC_CE02;
            }*/
           /* else if (RxBuf_1[2]==0x33){ // Warning Description, 16+4 byte
    //          if (RxBuf_1[3]<=WARNMAX){
                if (RxBuf_1[3]<=(WARNMAX+3)){  // IED Error Display, DINO, 08/13/2010
                    if (RxBuf_1[5]<=DESMAX){                
                        RxBuf_1[2] = RxBuf_1[5]<<1;
                        TxCntTemp = 2;
                        bx = RxBuf_1[5];           
                            //ShowDescription(warninfo[WarnCode]);
                        // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                        if ((C20xx[0x05]&0xff00) == 0x0200)
                            ShowDescription(warninfo_tc[WarnCode]);
                        else if ((C20xx[0x05]&0xff00) == 0x0300)
                            ShowDescription(warninfo_sc[WarnCode]);
                        else
                            ShowDescription(warninfo[WarnCode]);
                        // ]
                        ax = 0;
                        do{
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)Descript[ax];
                            ax++;
                            bx--;
                        }while(bx!=0);
                    }
                    else
                        COM1Err = PC_CE03;          
                }
                else
                    COM1Err = PC_CE02;
            }    */    
               /* else if (RxBuf_1[2]==0x34){
                    HPSPEC_temp = RxBuf_1[3];
                    if(RxBuf_1[3]>VFD_SINGLEPHASE)      //[Single phase input, Bernie, 01/19/2012]
                        HPSPEC_temp -= VFD_SINGLEPHASE;
                    
                //if (RxBuf_1[3]<=MAXMODELNO){
                if (HPSPEC_temp<=MAXMODELNO){          //[Single phase input, Bernie, 01/19/2012]
                    if (RxBuf_1[5]<=DESMAX){                
                        RxBuf_1[2] = RxBuf_1[5]<<1;
                        TxCntTemp = 2;
                        bx = RxBuf_1[5];
                        if(RxBuf_1[3]>VFD_SINGLEPHASE)            //[Single phase input, Bernie, 01/19/2012]
                            ShowDescription(ModelinfoSingle[RxBuf_1[3]-100]);
                        else
                            ShowDescription(Modelinfo[RxBuf_1[3]]);
                        ax = 0;
                        do{
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)Descript[ax];
                            ax++;
                            bx--;
                        }while(bx!=0);
                    }
                    else
                        COM1Err = PC_CE03;          
                }
                else
                    COM1Err = PC_CE02;          
            }*/
           /* else if (RxBuf_1[2]==0x35){
                if (RxBuf_1[3]<=MFDPAGEMAX){
                    if (RxBuf_1[5]<=DESMAX){                
                        RxBuf_1[2] = RxBuf_1[5]<<1;
                        TxCntTemp = 2;
                        bx = RxBuf_1[5];
                        // [ Actual Freq. Unit Change, Add by DINO, 05/25/2009
                        if (RxBuf_1[3] == 2){
                            if (pr[UNITSEL] == 1){
                                ShowDescription(sfrinfo_vel_sel[0]);    // Actual Speed m/s
                            }
                            else if (pr[UNITSEL] == 2){
                                ShowDescription(sfrinfo_vel_sel[1]);    // Actual Speed ft/s
                            }
                            else{
                                ShowDescription(sfrinfo[RxBuf_1[3]]);   // Actual Freq. Hz
                            }
                        }
                        else{
                            ShowDescription(sfrinfo[RxBuf_1[3]]);
                        }
                        // ]
                        ax = 0;
                        do{
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                            TxCntTemp++;
                            RxBuf_1[TxCntTemp] = (UBYTE)Descript[ax];
                            ax++;
                            bx--;
                        }while(bx!=0);
                    }
                    else
                        COM1Err = PC_CE03;          
                }
                else
                    COM1Err = PC_CE02;          
            }*/
            /*else if ((RxBuf_1[2]>=0x40)&&(RxBuf_1[2]<0x50)){
                ax = RxBuf_1[2] - 0x40;
                if (ax<GROUPTmp){
                    ax = pr_gpno[RxBuf_1[3]];
                    if ((UWORD)RxBuf_1[3]< ax) {    // function number //
                        if ((RxBuf_1[5]<C24MAX)){
                            ax=(SWORD)prtab[(RxBuf_1[2]&0x0F)]+RxBuf_1[3];     // pr index //Max.SJ
                            RxBuf_1[2]=RxBuf_1[5]<<1;     // word->byte data_count
                            TxCntTemp=2;
                            bx=RxBuf_1[5];         // data count //
                            //ShowDescription(prinfo[ax]);
                            // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                            if ((C20xx[0x05]&0xff00) == 0x0200)
                                ShowDescription(prinfo_tc[ax]);
                            else if ((C20xx[0x05]&0xff00) == 0x0300)
                                ShowDescription(prinfo_sc[ax]);
                            else
                                ShowDescription(prinfo[ax]);
                            // ]
                            ax = 0;
                            do {   // prepare data
                                TxCntTemp++;
                                RxBuf_1[TxCntTemp]=(UBYTE)(Descript[ax]>>8);
                                TxCntTemp++;
                                RxBuf_1[TxCntTemp]=(UBYTE)Descript[ax];
                                ax++;
                                bx--;
                            } while(bx!=0);
                        }
                        else
                            COM1Err = PC_CE03;
                    }
                    else
                        COM1Err = PC_CE03;
                }
                else
                    COM1Err = PC_CE03;
            }*/
            /*else if(RxBuf_1[2]==(GROUPTmp+1)){
                ax = RxBuf_1[3];
                if (((GROUPTmp+1)>=(ax+RxBuf_1[5]))&&(RxBuf_1[5]!=0)&&(RxBuf_1[5]<=DATA_LEN)&&(RxBuf_1[4]==0)){
                    RxBuf_1[2] = RxBuf_1[5]<<1;    // word->byte data_count
                    TxCntTemp = 2;
                    bx = RxBuf_1[5];             // data count
                    do{
                        
                            TempValue = pr_gpno[ax] - 1;
                        
                        TxCntTemp++;
                        RxBuf_1[TxCntTemp]=((UWORD)TempValue >> 8);
                        TxCntTemp++;
                        RxBuf_1[TxCntTemp]=((UWORD)TempValue & 0x00ff);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM1Err = PC_CE03;
            }*/
            //--- Address 9999H: "DELAT ELECTRONICS   " Copyright Display, Add by DINO, 12/01/2008 ---//
            /*else if (RxBuf_1[2]==0x99){ // Warning Description, 16+4 byte
                if ( RxBuf_1[3]==0x99 ){
                    Descript[0] = 0x4040 + 0x0405 ; // 0x4445, "D","E"
                    Descript[1] = 0x4050 + 0x0C04 ; // 0x4C54, "L","T"
                    Descript[2] = 0x4020 + 0x0100 ; // 0x4120, "A"," "
                    Descript[3] = 0x4040 + 0x050C ; // 0x454C, "E","L"
                    Descript[4] = 0x4040 + 0x0503 ; // 0x4543, "E","C"
                    Descript[5] = 0x5050 + 0x0402 ; // 0x5452, "T","R"
                    Descript[6] = 0x4040 + 0x0F0E ; // 0x4F4E, "O","N"
                    Descript[7] = 0x4040 + 0x0903 ; // 0x4943, "I","C"
                    Descript[8] = 0x5020 + 0x0300 ; // 0x5320, "S"," "
                    Descript[9] = 0x2020 + 0x0000 ; // 0x2020. " "," "
                    RxBuf_1[2]  = 0x14 ;            // Number of datas = 20 bytes
                    ax = 0 ;
                    bx = RxBuf_1[5];                // data count
    
                    TxCntTemp = 2 ;
                    do {                // prepare data
                        umap_addr.uw = Descript[ax] ;
                        TxCntTemp++;
                        RxBuf_1[TxCntTemp] = umap_addr.ub.hi;
                        TxCntTemp++;
                        RxBuf_1[TxCntTemp] = umap_addr.ub.low;
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM1Err = PC_CE02;
            }*/
            else{
                if (SHOW_ALLPR==1)
                    ax = GRALL;
                else{
                    // [ 00-02 Setting, DINO, 06/03/2010
                    
                    if (SHOW_ENHANCE==1)
                        ax = GRENHANCE;
                    else
                        ax = GRUSER;
                }
    
                if (RxBuf_3[2]<=ax){        // group number //
                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                        ax = pr_gpno_Sibo[RxBuf_3[2]];
                    else
                        ax = pr_gpno[RxBuf_3[2]];
            
                    if (RxBuf_3[3]< ax) {    // function number //            
                        if ((PUON3LINE==1)||(RxBuf_3[0]==0xFF)){//read parameter by PU
                            if ((RxBuf_3[5]==0x0A)&&(RxBuf_3[4]==0)) {
    
                                ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3]; // pr index //
    
                                bx = RxBuf_3[5];
                                TxCntTemp = 3;
                                //TxCntTemp = 2;
                                //RxBuf_1[2] = RxBuf_1[5]<<1;
                                if (CHKCPR==1)
                                    function_chk();
                               else{
#if ACCESS_GROUP
                                    // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                    ubCHGFlag = 0;
    
                                    if ( umap_addr.ub.hi==21 ){
                                        ShowDescription(c21info[ax]);
                                        if ((DispAttr[ax].ati&CHG) == CHG){
                                            ubCHGFlag = 1;
                                        }
                                    }
                                    else if ( umap_addr.ub.hi==22 ){
                                        ShowDescription(c22info[ax]);
                                    }
                                    else{
#endif
                                        //ShowDescription(prinfo[ax]);
                                        // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                                        if ((C20xx[0x05]&0xff00) == 0x0200){
                                           if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_TC
                                           	ShowDescription(prinfo_tc[ax]);
                                            #else
                                            ShowDescription(prinfo[ax]);
                                            #endif
                                           }
                                           else{
                                            #if Language_TC
											// JINGDO
											if(pr[FLOOR_PAGE]==1)
											    ShowDescription(prinfo_tc_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
											else if(pr[FLOOR_PAGE]==2)
									        	ShowDescription(prinfo_tc_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_tc_DLC3[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_tc_Adjst[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_tc_Adjst2[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_tc_Adjst3[(ax-DLC_PR)]);
                                            #else
                                            if(pr[FLOOR_PAGE]==1)
                                            ShowDescription(prinfo_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                            else if(pr[FLOOR_PAGE]==2)
                                                ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                                                ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            #endif
                                           }
                                        }
                                        else if ((C20xx[0x05]&0xff00) == 0x0300){
                                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                                #if Language_SC
                                                ShowDescription(prinfo_sc[ax]);
                                                #else
                                                ShowDescription(prinfo[ax]);
                                                #endif
                                            }
                                            else{
                                                #if Language_SC
											    // JINGDO
											    if(pr[FLOOR_PAGE]==1)
												    ShowDescription(prinfo_sc_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
										        else if(pr[FLOOR_PAGE]==2)
												    ShowDescription(prinfo_sc_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                    ShowDescription(prinfo_sc_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                                                #else
                                                if(pr[FLOOR_PAGE]==1)
                                                ShowDescription(prinfo_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                                else if(pr[FLOOR_PAGE]==2)
                                                    ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                                                    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                                #endif
                                            }
                                        }
                                        else{
                                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                                ShowDescription(prinfo[ax]);
                                            }
                                            else{
											// JINGDO
											    if(pr[FLOOR_PAGE]==1)
												    ShowDescription(prinfo_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
												else if(pr[FLOOR_PAGE]==2)
													ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            }
                                        }
                                        // ]
    
                                        //if ((attr[ax].ati&CHG) == CHG){
                                            //ubCHGFlag = 1;
                                        //}
                                        if((pr[SOFC]<=3) && (pr[UNITSEL]<3)){                      //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                        		            if ((attr[ax].ati&CHG) == CHG){
                        		    	        ubCHGFlag = 1;
                        		            }
                                        }
                            		    else{                                                     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                                            if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){
                                    		    if((ax == ACCEL1)||
                                                   (ax == DECEL1)||
                                                   (ax == JOGACC)||
                                                   (ax == JOGDEC)||
                                                   (ax == JOGF)  ||
                                                   (ax == DECEL5)
                                                 ){
                                                    ubCHGFlag = 1;
                                                }
                                            }
                                        }
                                    }
    
                                    if (ubCHGFlag == 1){
                                        if (pr[UNITSEL] == 1){
											if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
												|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
												|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
												|| (ax == JOGDEC) || (ax == DECEL5))
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
                                            Descript[8]  = ('m'<<8)+'/';
												Descript[9] = ('s'<<8)+'2'; 										
											}
											else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
													|| (ax == S4DEC2) || (ax == S4DEC3))
													&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												Descript[8]  = ('m'<<8)+'/';
												Descript[9] = ('s'<<8)+'3';
											}
											else{  // m/s
												Descript[8]  = ('m'<<8)+'/';
                                            Descript[9] = ('s'<<8)+' ';
											}
										}
                                        else if (pr[UNITSEL] == 2){
											if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // ft/s2
												|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
												|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
												|| (ax == JOGDEC) || (ax == DECEL5))
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												Descript[8]  = ('f'<<8)+'/';
												Descript[9] = ('s'<<8)+'2'; 										
											}
											else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // ft/s3
													|| (ax == S4DEC2) || (ax == S4DEC3))
													&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												Descript[8]  = ('f'<<8)+'/';
												Descript[9] = ('s'<<8)+'3';
											}
											else{  // ft/s
                                            Descript[8]  = ('f'<<8)+'t';
                                            Descript[9] = ('/'<<8)+'s';
											}
                                        }
                                        else if (pr[UNITSEL] == 3){            //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                                            Descript[8]  = ('m'<<8)+'/';
                                            Descript[9] = ('s'<<8)+'2';
                                        }
                                    }
                                    // ]
                                }
                                ax = 0;
                                do{
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                                    ax++;
                                    bx--;
                                } while(bx!=0);
                            }
                            //Data,Max,Min,Att,Def
                            else if ((RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)){
#if ACCESS_GROUP
                                if (RxBuf_3[2] == MAPGOURP){
                                    umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_3[3]] / 100;
                                    umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_3[3]] - umap_addr.ub.hi * 100;
                                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                                        gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                                    else
                                        gpno = pr_gpno[umap_addr.ub.hi];
                                    // Access to C21xx
                                    if (umap_addr.ub.hi==21 && umap_addr.ub.low<C21MAX){
                                        if ( (DispAttr[umap_addr.ub.low].ati&JMP)==JMP && SHOW_ALLPR==0 ){
                                            ax = Unavaliable;
                                            umap_addr.ub.hi = 0;
                                        }
                                        else
                                            ax = umap_addr.ub.low;
                                    }
                                    // Access to C22xx
                                    else if (umap_addr.ub.hi==22 && umap_addr.ub.low<C22MAX){
                                        if ( (DispAttr[(umap_addr.ub.low+C21MAX)].ati&JMP)==JMP && SHOW_ALLPR==0 ){ // Modify by DINO, 09/08/2008
                                            ax = Unavaliable;
                                            umap_addr.ub.hi = 0;
                                        }
                                        else
                                            ax = umap_addr.ub.low;
                                    }
                                    // Access to user parameter
                                    // [ Mapping to hidden parameters, DINO, 12/23/2009
                                    else if ((umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno){
    //                              else if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] ){
                                        ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
                                    }
                                    // ]
                                    // Access to unavailable address
                                    else{
                                        umap_addr.ub.hi = 0;
                                        ax = Unavaliable;   // Unavailable parameter, display "Unavailable"
                                    }
                                }
                                else
#endif
                                    ax = (UWORD)prtab[RxBuf_3[2]]+RxBuf_3[3]; // pr index //        
                                bx = RxBuf_3[5];
                                TxCntTemp = 2;
                                RxBuf_3[2] = RxBuf_3[5]<<1;
#if ACCESS_GROUP
                                // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                ubCHGFlag = 0;
                                // ]
                                
                                if ( umap_addr.ub.hi==21 ){
                                    //Data Content
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                                    //Data Max
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0xff;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0xff;
                                    //Data Min
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    //Data attribute
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = DispAttr[ax].ati>>8;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = DispAttr[ax].ati&0x00ff;
                                    //Data default
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    //Data Description
                                    ShowDescription(c21info[ax]);
                                    // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                    if ((DispAttr[ax].ati&CHG) == CHG){
                                        ubCHGFlag = 1;
                                    }
                                    // ]
                               }
                                else if ( umap_addr.ub.hi==22 ){
                                    //Data Content
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)C22xx[ax]>>8);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = ((UWORD)C22xx[ax] & 0x00ff);
                                    //Data Max
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0xff;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0xff;
                                    //Data Min
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    //Data attribute
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = DispAttr[(ax+C21MAX)].ati>>8;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = DispAttr[(ax+C21MAX)].ati&0x00ff;
                                    //Data default
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = 0x00;
                                    //Data Description
                                    ShowDescription(c22info[ax]);
                                }
#endif
                                else{
                                    TxCntTemp++;
                                    // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                    uwEEPData.uw = GetParData(ax);
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
                                    // ]
    
                                    uwEEPData.uw = GetParMax(ax);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
    
                                    uwEEPData.uw = GetParMin(ax);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#if SH7149
                                    if ((attr[ax].ati&0x0400)==0x0400){
                                        rxdata = GetParAttr(ax);
                                        TxCntTemp++;
                                        RxBuf_3[TxCntTemp] = ((UWORD)rxdata>>8);
                                        TxCntTemp++;
                                        RxBuf_3[TxCntTemp] = ((UWORD)rxdata&0x00ff);
                                    }       
                                    else {
                                        TxCntTemp++;
                                        RxBuf_3[TxCntTemp] = ((UWORD)attr[ax].ati>>8);
                                        TxCntTemp++;
                                        RxBuf_3[TxCntTemp] = ((UWORD)attr[ax].ati&0x00ff);
                                    }       
#else	// Modify by DINO, 09/22/2008
                                    uwEEPData.uw = GetParAttr(ax);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
#endif
    
    //-- Add by VE item91, 10/30/2008
                                    if ((pr[HPSPEC]&VFD440V)==VFD220V){    // 220V class
#if DINO
                                        if ( (attr[ax].ati&V440)==V440 )
                                            uwEEPData.uw = attr[ax].def>>1;
                                        else
                                            uwEEPData.uw = attr[ax].def;
#else
                                        switch(ax){
                                            case VMAX1:
                                            case VMID1_1:
                                            case VMID1_2:
                                            case VMIN1:    
                                            case LVL:   
                                            case STALL4V:
                                            case DCBRK4V:
                                            case VMAX2:
                                            case VMID2_1:
                                            case VMID2_2:
                                            case VMIN2:
                                            case PHL_L:
                                                rxdata = attr[ax].def>>1;
                                                break;
                                            default:
                                                rxdata = attr[ax].def;
                                                break;
                                        }
#endif
                                    }
                                    else{
                                        uwEEPData.uw = attr[ax].def;
                                    }
    //-- End on 10/30/2008
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
                                    //Data Description
                                    if (CHKCPR==1)
                                        function_chk();
                                    else{
                                        //ShowDescription(prinfo[ax]);
                                        // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                                        if ((C20xx[0x05]&0xff00) == 0x0200){
                                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                                #if Language_TC
                                                ShowDescription(prinfo_tc[ax]);
                                                #else
                                                ShowDescription(prinfo[ax]);
                                                #endif
                                            }
                                            else{
                                                #if Language_TC
											    // JINGDO
											    if(pr[FLOOR_PAGE]==1)
													ShowDescription(prinfo_tc_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
												else if(pr[FLOOR_PAGE]==2)
												    ShowDescription(prinfo_tc_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                    ShowDescription(prinfo_tc_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_tc_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_tc_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_tc_Adjst3[(ax-DLC_PR)]);
                                                #else
                                                if(pr[FLOOR_PAGE]==1)
                                                ShowDescription(prinfo_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                                else if(pr[FLOOR_PAGE]==2)
                                                    ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                                                    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                                #endif
                                            }
                                        }
                                        else if ((C20xx[0x05]&0xff00) == 0x0300){
                                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                                #if Language_SC
                                                ShowDescription(prinfo_sc[ax]);
                                                #else
                                                ShowDescription(prinfo[ax]);
                                                #endif
                                            }
                                            else{
                                                #if Language_SC
												// JINGDO
												if(pr[FLOOR_PAGE]==1)
												    ShowDescription(prinfo_sc_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
												else if(pr[FLOOR_PAGE]==2)
													ShowDescription(prinfo_sc_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                    ShowDescription(prinfo_sc_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                                                #else
                                                if(pr[FLOOR_PAGE]==1)
                                                ShowDescription(prinfo_DLC[(ax-DLC_PR)]);         //[DLC parameter display in Group 4, Bernie, 2016/01/27]
                                                else if(pr[FLOOR_PAGE]==2)
                                                    ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                                                    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                                                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                                #endif
                                            }
                                        }
                                        else{
                                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                                ShowDescription(prinfo[ax]);
                                            }
                                            else{
												// JINGDO
												if(pr[FLOOR_PAGE]==1)
												    ShowDescription(prinfo_DLC[(ax-DLC_PR)]);            //[DLC parameter display in Group 4, Bernie, 2016/01/27]
												else if(pr[FLOOR_PAGE]==2)
													ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                    ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==4) //[adjust floor position,Henry,2019/01/07]
                          	                        ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                          	                        ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                                                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                          	                        ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            }
                                        }
                                        // ]
                                        // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                        if ((attr[ax].ati&CHG) == CHG){
                                            ubCHGFlag = 1;
                                        }
                                        // ]
                                    }
                                }
    
                                // [ Velocity Unit Change, Add by DINO, 05/25/2009
                                if (ubCHGFlag == 1){
                                    if (pr[UNITSEL] == 1){
										if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
											|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
											|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
											|| (ax == JOGDEC) || (ax == DECEL5))
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
                                        Descript[8]  = ('m'<<8)+'/';
											Descript[9] = ('s'<<8)+'2';											
										}
										else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
												|| (ax == S4DEC2) || (ax == S4DEC3))
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('m'<<8)+'/';
											Descript[9] = ('s'<<8)+'3';
										}
										else{  // m/s
											Descript[8]  = ('m'<<8)+'/';
                                        Descript[9] = ('s'<<8)+' ';
										}
									}
                                    else if (pr[UNITSEL] == 2){
										if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // ft/s2
											|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
											|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
											|| (ax == JOGDEC) || (ax == DECEL5))
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'2';											
										}
										else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // ft/s3
												|| (ax == S4DEC2) || (ax == S4DEC3))
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'3';
										}
										else{  // ft/s
                                        Descript[8]  = ('f'<<8)+'t';
                                        Descript[9] = ('/'<<8)+'s';
										}
                                    }
                                    else if (pr[UNITSEL] == 3){           //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                                        Descript[8]  = ('m'<<8)+'/';
                                        Descript[9] = ('s'<<8)+'s';
                                    }
                                }
                                // ]
    
    
                                ax = 0;
                                do{
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                                    TxCntTemp++;
                                    RxBuf_3[TxCntTemp] = (UBYTE)Descript[ax];
                                    ax++;
                                }while(ax < DESMAX);
                                TxCntTemp = (bx<<1) + 2;
                            }
                            else
                                COM3Err = PC_CE03;
                        }
                     else{//Normal read parameter value
                            if ((RxBuf_3[3]+RxBuf_3[5]<=ax)&&(RxBuf_3[5]!=0)&&(RxBuf_3[5]<=DATA_LEN)&&(RxBuf_3[4]==0)) {
                                // [ Modify Read Function of Mapping Group, DINO, 07/02/2010
                                ubGrNum = RxBuf_3[2];   // PR. Group
                                ubPrNum = RxBuf_3[3];   // PR. Number
                                uwAddr = prtab[ubGrNum] + ubPrNum;
                                ax = 0;
                                
                                //RxBuf_1[2] = RxBuf_1[5]<<1;     // word->byte data_count
                                //TxCntTemp = 2;

                                TxCntTemp = 3;
                                bx=RxBuf_3[5];  // data count //
                                do {   // prepare data //
#if ACCESS_GROUP
                                    if (ubGrNum == MAPGOURP){
                                        umap_addr.ub.hi = pr[UMAP_ADD0+ubPrNum+ax] / 100;
                                        umap_addr.ub.low = pr[UMAP_ADD0+ubPrNum+ax] - umap_addr.ub.hi * 100;
                                        if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                                            gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                                        else
                                            gpno = pr_gpno[umap_addr.ub.hi];
                                        // Access to C21xx
                                        if (umap_addr.ub.hi==21 && umap_addr.ub.low<C21MAX){
                                            if ( (DispAttr[umap_addr.ub.low].ati&JMP)==JMP && SHOW_ALLPR==0 ){
                                                rxdata = Unavaliable;
                                                umap_addr.ub.hi = 0;
                                            }
                                            else
                                                rxdata = umap_addr.ub.low;
                                        }
                                        // Access to C22xx
                                        else if (umap_addr.ub.hi==22 && umap_addr.ub.low<C22MAX){
                                            if ( (DispAttr[(umap_addr.ub.low+C21MAX)].ati&JMP)==JMP && SHOW_ALLPR==0 ){ // Modify by DINO, 09/08/2008
                                                rxdata = Unavaliable;
                                                umap_addr.ub.hi = 0;
                                            }
                                            else
                                                rxdata = umap_addr.ub.low;
                                        }
                                        // Access to user parameter
                                        else if ((umap_addr.ub.hi<=ACCESS  || SHOW_ALLPR==1) && umap_addr.ub.low<gpno){
                                            rxdata = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
                                        }
                                        // Access to unavailable address
                                        else{
                                            umap_addr.ub.hi = 0;
                                            rxdata = Unavaliable;   // Unavailable parameter, display "Unavailable"
                                        }
    
                                        // Access to C21xx
                                        if (umap_addr.ub.hi == 21){
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp] = ((UWORD)C21xx[rxdata]>>8);
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp] = ((UWORD)C21xx[rxdata] & 0x00ff);
                                        }
                                        // Access to C22xx
                                        else if (umap_addr.ub.hi == 22){
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp] = ((UWORD)C22xx[rxdata]>>8);
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp] = ((UWORD)C22xx[rxdata] & 0x00ff);
                                        }
                                        // Access to User Parameter
                                        else{
                                            if ((rxdata>=BKTRANS1)&&(rxdata<=BKTRANS10)){
                                                rxdata = BLKTransferRead(rxdata);
                                                TxCntTemp++;
                                                RxBuf_3[TxCntTemp]=((UWORD)rxdata>>8);
                                                TxCntTemp++;
                                                RxBuf_3[TxCntTemp]=((UWORD)rxdata & 0x00ff);
                                            }
                                            else{
                                                TxCntTemp++;                                   
                                                RxBuf_3[TxCntTemp]=((UWORD)pr[rxdata]>>8);
                                                TxCntTemp++;
                                                RxBuf_3[TxCntTemp]=((UWORD)pr[rxdata] & 0x00ff);
                                            }
                                        }
                                    }
#endif
                                    else{
                                        umap_addr.uw = uwAddr + ax;
                                        if ((umap_addr.uw>=BKTRANS1)&&(umap_addr.uw<=BKTRANS10)){
                                            rxdata = BLKTransferRead(umap_addr.uw);
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp]=((UWORD)rxdata>>8);
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp]=((UWORD)rxdata & 0x00ff);
                                        }
                                        else{
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp]=((UWORD)pr[umap_addr.uw]>>8);
                                            TxCntTemp++;
                                            RxBuf_3[TxCntTemp]=((UWORD)pr[umap_addr.uw] & 0x00ff);
                                        }
                                    }
                                    ax++;
                                    bx--;
                                }while(bx!=0);
                                // ]
                            }
                            else  //Data length out of range
                                COM3Err = PC_CE03;
                        }
                    }
                    else  //Function number error
                        COM3Err = PC_CE02;
                }
                else //group number error
                    COM3Err = PC_CE02;
            }
            //if(RxBuf_1[2]!=0x65)
            //Init_TxData_1(TxCntTemp);
    }

UWORD CRC_CHECK_UD(UBYTE CRC_CNT)
{
    UWORD_UNION CRC_Result;
    UWORD  uIndex ; /* will index into CRC lookup table */
    UBYTE i,j;
    CRC_Result.uw = 0xffff;

    for (i=0;i<=CRC_CNT; i++){
        //TxBuf_1[i] = RxBuf_1[i];
      
      #if CRC_Table      
        uIndex = CRC_Result.ub.low ^ RxBuf_3[i];
        CRC_Result.ub.low  = CRC_Result.ub.hi ^ auchCRCLo[uIndex] ;
        CRC_Result.ub.hi = auchCRCHi[uIndex] ;
      
      #else
        CRC_Result.ub.low ^= TxBuf_3[i];   
        for (j=0;j<8;j++) {
            if (CRC_Result.uw & 0x01)
                CRC_Result.uw = (CRC_Result.uw >>1 ) ^ 0xa001;
            else
                CRC_Result.uw = CRC_Result.uw >> 1;
        }
      #endif     
    }

    return(CRC_Result.uw);
}



// move to here by dino, 03/08/2007
void PC_CEError3(UBYTE CeErr)
{
    switch (CeErr){
        case 1:
            Error = cE1_ERR;
        	break;
        case 2:
            Error = cE2_ERR;
        	break;
        case 3:
            Error = cE3_ERR;
        	break;
        case 4:
            Error = cE4_ERR;
        	break;
        case 5:
            Error = cE10_ERR;
        	break;            
        default:
        	break;
    }   
}

#ifdef _SCI1_Remote_C
	#undef _SCI1_Remote_C
#endif

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
