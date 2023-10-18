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
#ifndef _SCI3_Remote_C
        #define _SCI3_Remote_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
#include "PR_Romdata.h"

/* Constant Table =============================================*/

UWORD CRC_CHECK_2(UBYTE CRC_CNT)
{
    UWORD_UNION CRC_Result;
    //UWORD  uIndex ; /* will index into CRC lookup table */
    UBYTE i,j;
    CRC_Result.uw = 0xffff;

    for (i=0;i<=CRC_CNT; i++){
        TxBuf_2[i] = RxBuf_2[i];
      
      #if CRC_Table      
        uIndex = CRC_Result.ub.low ^ RxBuf_2[i];
        CRC_Result.ub.low  = CRC_Result.ub.hi ^ auchCRCLo[uIndex] ;
        CRC_Result.ub.hi = auchCRCHi[uIndex] ;
      
      #else
        CRC_Result.ub.low ^= RxBuf_2[i];   
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

void RTU_RxOKChk_2(void)
{
    DINT(); 
    // RTU_RXF=0, data receiving, and RTU_CNT0 count in 100us	
    if ((RTU_RXF2==0)&&(RTU_CNT2>=RTU_Silent2)) {
        if (Rx2CNT >=7) {            // 7 characters are RTU Minimum string
#if SH7286 //Sean, 01/25/2010
            SCI2.SCR.BIT.RIE = 0; //SCIF3==>SCI2, Bernie, 2013/08/15
#else        	
            SCI0.SCSCR.BIT.RIE = 0;	// dino, 03/06/2007
#endif            
            RX_OK2 = 1;                // Check RTU mode End of ETX            
        }
        else{
	    	if (Rx2CNT!=0)
	    	Rx2CNT = 0xFF;
        }

        RTU_CNT2 = 0;
        RTU_RXF2 = 1;
    }
    EINT();

}

void TxD_Data_2(void)//Ready To Send
{   
    if ((TXD_RTS2==1)&&(RTU_CNT2>=pr[REM_DT2])){   //Ready To Send
        Com_WatchDog2 = 0;
        RTU_CNT2 = 0;                // clr rtu space timer
        SendCNT2 = 0;
        TXD_RTS2 = 0;

        DINT();     
#if SH7286 //Sean, 01/25/2010          
        SCI2.TDR = TxBuf_2[SendCNT2];
        //SCI2.SSR.BIT.TDRE = 0;   //Bernie mask
        SCI2.SCR.BIT.TIE = 1;		// Transmit Data Empty Interrupt Enable
        SCI2.SCR.BIT.TEIE = 1;	// Enable Transmit FIFO Empty interrupt
#else
        SCI0.SCTDR = TxBuf_2[SendCNT2];	// dino, 03/06/2007
        SCI0.SCSSR.BIT.TDRE = 0;       	// dino, 03/06/2007
        SCI0.SCSCR.BIT.TEIE = 1;	// Enable Transmit End interrupt, dino, 03/06/2007
#endif        
        EINT();
    }
}

void RxDataCheck_2(void)
{
    UBYTE i,k;
    UWORD ChkTemp=0;
    UWORD_UNION Data_CRC, CRC_Result2;
    if (ASC_RTU2==0) {     //ASC mode
            if (RxBuf_2[0]==STX){
        	   // 1. Transfer ASCII code to HEX code
                for (i=1;i<=(Rx2CNT-2);i++){       // i=1 ->cancel "3A" //
                    if ((RxBuf_2[i]>=0x41)&&(RxBuf_2[i]<=0x46))       // A~F
                        RxBuf_2[i-1] = RxBuf_2[i] - 0x37;                    
                    
                    else if ((RxBuf_2[i]>=0x30)&&(RxBuf_2[i]<=0x39))  // 0~9
                        RxBuf_2[i-1] = RxBuf_2[i] - 0x30;                    
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
                        RxBuf_2[k]=(RxBuf_2[i]<<4)+(RxBuf_2[i+1]&0x0F);
                        ChkTemp = ChkTemp + RxBuf_2[k];      /* LRC calculation */
                        i += 2;
                        k++;

                    } while (i<=(Rx2CNT-3));
                }//if (ChkTemp==0)
            }//if (RxBuf_3[0]==STX)
            Rx2CNT = (Rx2CNT - 6)>>1;
    }//End of ASC mode
    else {  // ASC_RTU=1, RTU mode
            Rx2CNT = Rx2CNT - 2;
            CRC_Result2.uw = CRC_CHECK_2(Rx2CNT);
            
            Data_CRC.ub.low = RxBuf_2[Rx2CNT+1];
            Data_CRC.ub.hi = RxBuf_2[Rx2CNT+2];

            if (CRC_Result2.uw!=Data_CRC.uw)
            	ChkTemp = 0xFF;
    }// End of Receive data check //

    if ((ChkTemp&0x00FF)==0x0000){   // LRC or CRC correct //
        if (RxBuf_2[0]==0x00){
            NO_ECHO2 = 1;      // Broadcast mode, No echo //
            ADDR_MATCH2 = 1;            
        }
        else if ((RxBuf_2[0]==0xFF)||(RxBuf_2[0]==pr[ADDRS2])){
            NO_ECHO2 = 0;
            ADDR_MATCH2 = 1;
            SCIDIR2Flag = 0;
            SCI2_DIR = 0;
        }
        else{				
            InitSCI2();//SCI2>SCIF3, Sean, 01/20/2010
        }
    }
    else{
        InitSCI2();//SCI2>SCIF3, Sean, 01/20/2010
	}        
}

void RxDecoder_2(void)
{
    //------ receive data convert and check ---------------------//
    RxDataCheck_2();
    
    //CheckPU2();
    if (ADDR_MATCH2==1) {
        switch(RxBuf_2[1]) {
            case 0x03:    /* multi read data */
                if(Rx2CNT==5)
                    RemoteCmd03_2();
                break;
            case 0x63:    /* multi read data */
                if(Rx2CNT==5)
                    RemoteCmd63_2();
                break;    
            case 0x06:    /* set single data */
                if(Rx2CNT==5)
                    RemoteCmd06_2();
                break;
            case 0x10:    /* multi write */
                if (Rx2CNT ==(6+RxBuf_2[6]))
                    RemoteCmd10_2();
                break;
            //case 0x17:      /* diagnostic ->echo */      //[APP01 IO carde support, Bernie, 2013/03/20]
                    //RemoteCmd17_2();
                //break;
            case 0x08:      /* diagnostic ->echo */
                    Init_TxData_2(Rx2CNT);
                break;
            default:
                COM2Err = PC_CE01;
                break;
        }
        SCI2_ComFault();
    }
}


void CHK_PUID2(void)
{
    //----------------------------------------------------
    // #define    IDPU    P5.bit.b7   // PU02 ID pin, 0: PU02 Active
    // PUID Check, 11262003

    if (PUID2_BUF != IDPU2) {
        PUID2Cnt = 0;
        PUID2_BUF = IDPU2;
    }
    else {
        if (PUID2Cnt >= 255){

            PUID2 = PUID2_BUF;      // Port3 status change
         
            
            if ( (pr[PROTBIT]&0x1000)==0x1000 ){	// Bit 12: PUID3 control by pr[PROTBIT]
            	if ( (pr[PROTBIT]&0x0008)==0 )		// Bit 3: external keypad connector enable/disable
            		PUID2 = 1;	// PUON2LINE=0
            	else
            		PUID2 = 0;	// PUON2LINE=1
            }
          
            
            if (PUID2 == 0){		
           
             
                PUON2LINE = 1;
                if(PUON2==1)
                    PUEN2 = 1;
                else
                    PUEN2 = 0;
            }  
            else {
         
                PUON2LINE = 0;
//                if (pr[SOOC]>=3)
                if (pr[SOOC]==2)		//SCOTTY 08/31/2007
                    PUEN2 = 1;
                else   
                    PUEN2 = 0;
            }    
        }
        else
            PUID2Cnt++;
    }
}

/*---- Pr09-05: Transmission Fault Treament ------*/
void SCI2_ComFault(void)
{
    if (PUON2LINE){    
        if(COM2Err==CP_CE10){      // Transmission Fault Treament COM3Err = 5 = cP10
            if ((Error==0)&&(WarnCode==0)) {
                WarnCode = COM2Err;
                Keypad_PageTmp = Keypad_Page;
                Keypad_Page = WarnPAGE;
                WARNSTOPREC = 1;	//09/05/2007
            }            
            if(pr[C_FAULT2] == 1){
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
        if(COM2Err!=0){      // Transmission Fault Treament
            if(pr[C_FAULT2] == 1){
                stop();
                PC_CEError(COM2Err);
            }   
//            else if (pr[C_FAULT1] == 2) {		//SCOTTY delete 09/03/2007 
//                CMDRUN = STOP;				//SCOTTY delete 09/03/2007 
//                CMDFREE = 1;					//SCOTTY delete 09/03/2007 
//                PC_CEError(COM3Err);			//SCOTTY delete 09/03/2007 
//				  WARNSTOPREC = 1;	//09/05/2007
//            }
 
//            if ((pr[C_FAULT1]!=3)&&(Error==0)&&(WarnCode==0)) 	//SCOTTY delete 09/03/2007 
			if ((pr[C_FAULT2]<2)&&(Error==0)&&(WarnCode==0)) {		//SCOTTY ADD 09/03/2007
                WarnCode = COM2Err;
                Keypad_PageTmp = Keypad_Page;
                Keypad_Page = WarnPAGE;
            }
        }
    }
    COM2Err = 0;
}

void HEX2ASC_2(UBYTE byte_cnt)
{
    UBYTE data,j,bx,lrc_data=0;

    TxBuf_2[Tx2CNT] = 0x3a;
    Tx2CNT++;
    for (j=0;j<=byte_cnt;j++) {
        data = RxBuf_2[j];
        lrc_data += data;              // LRC data

        bx = data>>4;
        if (bx>=0x0a)                // 0x0a<=low_nb<=0x0f //
            TxBuf_2[Tx2CNT] = bx + 0x37;
        else                         // 0x0a>low_nb //
            TxBuf_2[Tx2CNT] = bx + 0x30;    //* nibble ->ASCII, store to buffer */
        
        Tx2CNT++;

        bx = data&0x0f;
        if (bx>=0x0a)                // 0x0a<=low_nb<=0x0f //
            TxBuf_2[Tx2CNT] = bx + 0x37;
        else                         // 0x0a>low_nb //
            TxBuf_2[Tx2CNT] = bx + 0x30;    //* nibble ->ASCII, store to buffer */
        Tx2CNT++;
    }

    lrc_data = 0 - lrc_data;           //* lrc_data=(~lrc_data)+1; */
    bx = lrc_data>>4;
    if (bx>=0x0a)                  // 0x0a<=low_nb<=0x0f //
        TxBuf_2[Tx2CNT] = bx + 0x37;
    else                           // 0x0a>low_nb //
        TxBuf_2[Tx2CNT] = bx + 0x30;      //* nibble ->ASCII, store to buffer */
    
    Tx2CNT++;

    bx = lrc_data & 0x0f;
    if (bx>=0x0a)                  // 0x0a<=low_nb<=0x0f //
        TxBuf_2[Tx2CNT] = bx + 0x37;
    else                           // 0x0a>low_nb //
        TxBuf_2[Tx2CNT] = bx + 0x30;      //* nibble ->ASCII, store to buffer */
    
    Tx2CNT++;
}

void Init_TxData_2(UBYTE Data_CNT)//Initial TxD from RxD
{
    UWORD_UNION CRC_Result2;

    if (COM2Err!=0) {
          RxBuf_2[1] |= 0x80;             // force command code bit7=1 (0x8y) //
          RxBuf_2[2] = COM2Err;          // exception code //
          Data_CNT = 2;
    }

    if (ASC_RTU2==0) {             // ASCII mode, 
        HEX2ASC_2(Data_CNT);
        TxBuf_2[Tx2CNT] = CR_0D;
        Tx2CNT++;
        TxBuf_2[Tx2CNT] = LF_0A;
    }
#if BOOTLOADER_ENABLE    
	else if(Data_CNT == 0x3A){	// Bootloader enable, Sean, 20141022
		RxBuf_2[0] = 0x25;
		CRC_Result2.uw = CRC_CHECK_2(12);          //12
		Tx2CNT =  12 + 1;
		TxBuf_2[Tx2CNT] = CRC_Result2.ub.low;
		Tx2CNT++;
		TxBuf_2[Tx2CNT] = CRC_Result2.ub.hi;
		Tx2CNT++;
		TxBuf_2[Tx2CNT] = 0x0D;
		Tx2CNT++;
		TxBuf_2[Tx2CNT] = 0x0A;
	}
#endif	
    else {                         // RTU mode
        CRC_Result2.uw = CRC_CHECK_2(Data_CNT);
        Tx2CNT =  Data_CNT + 1;
        TxBuf_2[Tx2CNT] = CRC_Result2.ub.low;
        Tx2CNT++;
        TxBuf_2[Tx2CNT] = CRC_Result2.ub.hi;
    }
    TXD_RTS2 = 1;                  // ready to send
}

void FFcalibration(UBYTE func, UWORD datac)
{
    UWORD cx;

    switch(func){
        case 0x01:  // Current Calibration
        	break;
#if SH7149
        case 0x02:  //AVIMid
            cx = datac;
            if (cx > attr[CACIMID].max){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else if (cx < attr[CAUI1ZERO].min){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else{
                pr[CACIMIN] = cx;
                write_ep(0,CACIMIN,cx);
            }          
            break;
        case 0x05:  //AVIMax
            cx = datac;
            if (cx > attr[CACIMAX].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[CACIMAX].min){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else{
                pr[CAUI1MIN] = cx;
                write_ep(0,CAUI1MIN,cx);
            }
            break;          
        case 0x05:  // AUI1 MAX, -10V
            cx = datac;
            if (cx > attr[CAUI1MAX].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[CAUI1MAX].min){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else{
                pr[CACIMIN] = cx;
                write_ep(0,CACIMIN,cx);
            }
            break;
        case 0x07:  // ACI MAX
            cx = datac;
            if (cx > attr[CACIMAX].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[CACIMAX].min){
                COM2Err = PC_CE04;
            }
            else{
                pr[CACIMAX] = cx;
                write_ep(0,CACIMAX,cx);
            }
            break;
        case 0x08:  // AUI MIN, +10V
            cx = datac;
            if (cx > attr[CAUI2MIN].max){
                COM2Err = PC_CE04;
            }
            else{
                pr[CAUI2MIN] = cx;
                write_ep(0,CAUI2MIN,cx);
            }
            break;          
        case 0x09:  // AUI MAX, -10V
            cx = datac;
            if (cx > attr[CAUI2MAX].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[CAUI2MAX].min){
                COM2Err = PC_CE04;
            }
            else{
                pr[CAUI2MAX] = cx;
                write_ep(0,CAUI2MAX,cx);
            }
            break;
            
        case 0x0A:  //AUI Zero
            cx = datac;
            if (cx > attr[CAUI2ZERO].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[CAUI2ZERO].min){
                COM2Err = PC_CE04;
            }
            else{
                pr[CAUI2ZERO] = cx;
                write_ep(0,CAUI2ZERO,cx);
            }
            break;
        case 0x0B:  // Fine AUI MIN, +2V
            cx = datac;
            if (cx > attr[FAUIMIN].max){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else if (cx < attr[FAUIMAX].min){
                COM2Err = PC_CE04;
            }
            else{
                pr[FAUIMAX] = cx;
                write_ep(0,FAUIMAX,cx);
            }
            break;
            
        case 0x0D:  //Fine AUI Zero
            cx = datac;
            if (cx > attr[FAUIZERO].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[FAUIZERO].min){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            else
                pr[DAMAX] = cx;
            break;
            
        case 0x0D:  // DA MIN, -10V
            cx = datac;
            if (cx > 4095)
                COM2Err = PC_CE04;
            else
                pr[DAMIN] = cx;
            break;            
#endif
        case 0x0E:  // DCB1_AD, AD value for 210.0VDC
            cx = datac;
            if (cx > attr[DCB_AD1].max){
                COM2Err = PC_CE04;
            }
            else if (cx < attr[DCB_AD1].min){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else if (cx < attr[DCB_AD2].min){
                COM2Err = PC_CE04;
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
                COM2Err = PC_CE04;
            }
            else if (cx < attr[DCB_AD3].min){
                COM2Err = PC_CE04;
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
            COM2Err = PC_CE03;
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
void RemoteCmd03_2(void)
{
        UBYTE TxCntTemp=0, bx, ubCHGFlag, ubGrNum, ubPrNum, HPSPEC_temp,gpno;
        UWORD TempValue, ax, rxdata, uwAddr,cx;
        UWORD_UNION umap_addr, uwEEPData;

        
        umap_addr.uw = 0;

        if (RxBuf_2[2] == 0x20){            // Communication Memory Address 20xxH               
            ax = RxBuf_2[3];
            if ((C20MAX >= (ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
                RxBuf_2[2] = RxBuf_2[5]<<1;         // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_2[5];                  // data count //
                do {                          // prepare data //
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp] = (UBYTE)(C20xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp] = (UBYTE)(C20xx[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM2Err = PC_CE03;
        }
        else if (RxBuf_2[2]==0x21){
            ax = RxBuf_2[3];
            if ((C21MAX>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
                Update_C21xx();
                RxBuf_2[2] = RxBuf_2[5]<<1;           // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_2[5];                    // data count //
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM2Err = PC_CE03;
        }
        else if (RxBuf_2[2]==0x22) {
            ax = RxBuf_2[3];
            if ((C22MAX>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
                RxBuf_2[2]=RxBuf_2[5]<<1;
                TxCntTemp = 2;
                bx = RxBuf_2[5];
                Update_C22xx();
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=(UBYTE)(C22xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=(UBYTE)(C22xx[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM2Err = PC_CE03;
        }
        else if (RxBuf_2[2]==0x23) {
            ax = RxBuf_2[3];
            if ((C23MAX>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
                RxBuf_2[2]=RxBuf_2[5]<<1;
                TxCntTemp = 2;
                bx = RxBuf_2[5];
                Update_KeypadDisp();
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=(UBYTE)(KC23xx[ax]>>8);
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=(UBYTE)(KC23xx[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM2Err = PC_CE03;
        }
        else if (RxBuf_2[2]==0x24){
                ax = RxBuf_2[3];
                if ((DESMAX>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
                RxBuf_2[2] = RxBuf_2[5]<<1;
                TxCntTemp = 2;
                bx = RxBuf_2[5];
                Update_LCDescription();
                do {                            // prepare data //
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=(UBYTE)(Descript[ax]>>8);
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=(UBYTE)(Descript[ax]);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM2Err = PC_CE03;
        }
        // [ Display Group for VLI, DINO, 03/22/2010
      /*  else if (RxBuf_3[2]==0x2A){
            ax = RxBuf_3[3];
            if ((C2AMAX>=(ax+RxBuf_3[5]))&&(RxBuf_3[5]!=0)&&(RxBuf_3[4]==0)){
                RxBuf_3[2] = RxBuf_3[5]<<1;           // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_3[5];                    // data count //
                do {                            // prepare data //
                	uwEEPData.uw = C2Axx[ax];
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp] = uwEEPData.ub.hi;
                    TxCntTemp++;
                    RxBuf_3[TxCntTemp] = uwEEPData.ub.low;
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM3Err = PC_CE03;
        }*/
        // ]
//---Add BY Dino 06/25/2007---
        else if (RxBuf_2[2]==0xff){
            if((RxBuf_2[3]< CALIMAX)&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
                if(SHOW_ALLPR==1){ //FF - 00 -00
                    RxBuf_2[2]=RxBuf_2[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_2[5];
                    ax = RxBuf_2[3];
                    do {                          // prepare data //
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp]=(UBYTE)(CFFxx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp]=(UBYTE)(CFFxx[ax]);
                        ax++;
                        bx--;
                    } while(bx!=0);
                }
                else
                    COM2Err = PC_CE03;
            }
            else
                COM2Err = PC_CE03;
        }   
        else if ((RxBuf_2[2]<=0xF3)&&(RxBuf_2[2]>=0xC0)){ // Communication Memory Address >= 80xxH + SFR(0300~03FF)
        	ax = ((UWORD)RxBuf_2[2]<<8) + RxBuf_2[3];
        	if ((RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
            	RxBuf_2[2] = RxBuf_2[5]<<1;		// word->byte data_count
            	TxCntTemp = 2;
            	bx = RxBuf_2[5];				// data count //
            	do {                            // prepare data //
              		TxCntTemp++;
              		RxBuf_2[TxCntTemp] = (UBYTE)(MEMADDR[ax]>>8);
              		TxCntTemp++;
              		RxBuf_2[TxCntTemp] = (UBYTE)(MEMADDR[ax]);
              		ax++;
              		bx--;
            	} while(bx!=0);
          	}
          	else
            	COM2Err = PC_CE03;
        }
//---END 06/25/2007---------------	
        else if (RxBuf_2[2]==0x31){
            if (RxBuf_2[3]<=GROUPTmp){
                if (RxBuf_2[5]<=DESMAX){                
                    RxBuf_2[2] = RxBuf_2[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_2[5];
                    	//ShowDescription(gpname[RxBuf_3[3]]);
                    if ((C20xx[0x05]&0xff00) == 0x0200)
                        #if Language_TC
                        ShowDescription(gpname_tc[RxBuf_2[3]]);
                        #else
                        ShowDescription(gpname[RxBuf_2[3]]);
                        #endif
                    else if ((C20xx[0x05]&0xff00) == 0x0300)
                        #if Language_SC
                        ShowDescription(gpname_sc[RxBuf_2[3]]);
                        #else
                        ShowDescription(gpname[RxBuf_2[3]]);
                        #endif
                    else if ((C20xx[0x05]&0xff00) == 0x0400)
                        #if Language_TR
                        ShowDescription(gpname_tur[RxBuf_2[3]]);
                        #else
                        ShowDescription(gpname[RxBuf_2[3]]);
                        #endif
                    else if ((C20xx[0x05]&0xff00) == 0x0800)
                        #if Language_RUS
                        ShowDescription(gpname_rus[RxBuf_2[3]]);
                        #else
                        ShowDescription(gpname[RxBuf_2[3]]);
                        #endif
                    else
                        ShowDescription(gpname[RxBuf_2[3]]);
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM2Err = PC_CE03;
                                        
            }
            else
                COM2Err = PC_CE02;
        }        
        else if (RxBuf_2[2]==0x32){
            if (RxBuf_2[3]<=ERRMAX){
                if (RxBuf_2[5]<=(DESMAX+0x04)){  // For VFD-Cx, DINO, 03/16/2010
                    RxBuf_2[2] = RxBuf_2[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_2[5];
    				if (Error!=0){
    					
							//ShowDescription(errinfo[Error]);	// RxBuf_3[0] ~ RxBuf_3[19]
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
                        else if ((C20xx[0x05]&0xff00) == 0x0400)
                            #if Language_TR
                            ShowDescription(errinfo_tur[Error]); 
                            #else
                            ShowDescription(errinfo[Error]); 
                            #endif
                        else if ((C20xx[0x05]&0xff00) == 0x0800)
                            #if Language_RUS
                            ShowDescription(errinfo_rus[Error]);
                            #else
                            ShowDescription(errinfo[Error]); 
                            #endif
                        else
                            ShowDescription(errinfo[Error]); 
                        Descript[10] = pr[FFBK_REC];   //[6 : Fault Record,Lyabryan,2016/07/15]
                        Descript[11] = pr[ISUM_REC];   //[6 : Fault Record,Lyabryan,2016/07/15]
                        Descript[12] = pr[VOUT_REC];   //[6 : Fault Record,Lyabryan,2016/07/15]
                        Descript[13] = pr[DCBUS_REC];  //[6 : Fault Record,Lyabryan,2016/07/15]

    				}
    			
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM2Err = PC_CE03;
                                        
            }
            else
                COM2Err = PC_CE02;
        }
		else if (RxBuf_2[2]==0x33){	// Warning Description, 16+4 byte
//        	if (RxBuf_3[3]<=WARNMAX){
    		if (RxBuf_2[3]<=(WARNMAX+3)){  // IED Error Display, DINO, 08/13/2010
				if (RxBuf_2[5]<=DESMAX){                
                    RxBuf_2[2] = RxBuf_2[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_2[5];           
                    	//ShowDescription(warninfo[WarnCode]);
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
					else if ((C20xx[0x05]&0xff00) == 0x0400)
                        #if Language_TR
						ShowDescription(warninfo_tur[WarnCode]); 
                        #else
                        ShowDescription(warninfo[WarnCode]);
                        #endif
					else if ((C20xx[0x05]&0xff00) == 0x0800)
                        #if Language_RUS
						ShowDescription(warninfo_rus[WarnCode]); 
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
					
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM2Err = PC_CE03;        	
			}
			else
				COM2Err = PC_CE02;
		}        
			else if (RxBuf_2[2]==0x34){
                HPSPEC_temp = RxBuf_2[3];
                if(RxBuf_2[3]>VFD_SINGLEPHASE)      //[Single phase input, Bernie, 01/19/2012]
                    HPSPEC_temp -= VFD_SINGLEPHASE;

            //if (RxBuf_3[3]<=MAXMODELNO){
            if (HPSPEC_temp<=MAXMODELNO){           //[Single phase input, Bernie, 01/19/2012]
				if (RxBuf_2[5]<=DESMAX){                
                    RxBuf_2[2] = RxBuf_2[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_2[5];
                    if(RxBuf_2[3]>VFD_SINGLEPHASE)          //[Single phase input, Bernie, 01/19/2012]
                        ShowDescription(ModelinfoSingle[RxBuf_2[3]-VFD_SINGLEPHASE]);
                    else
                        ShowDescription(Modelinfo[RxBuf_2[3]]);
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM2Err = PC_CE03;			
			}
			else
				COM2Err = PC_CE02;			
		}
		else if (RxBuf_2[2]==0x35){
			if (RxBuf_2[3]<=MFDPAGEMAX){
				if (RxBuf_2[5]<=DESMAX){                
                    RxBuf_2[2] = RxBuf_2[5]<<1;
                    TxCntTemp = 2;
                    bx = RxBuf_2[5];
					// [ Actual Freq. Unit Change, Add by DINO, 05/25/2009
					if (RxBuf_2[3] == 2){
						if (pr[UNITSEL] == 1){
                    		ShowDescription(sfrinfo_vel_sel[0]);	// Actual Speed m/s
						}
						else if (pr[UNITSEL] == 2){
                    		ShowDescription(sfrinfo_vel_sel[1]);	// Actual Speed ft/s
						}
                        else if (pr[UNITSEL] == 3){                 //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                    		ShowDescription(sfrinfo_vel_sel[2]);	// Actual Speed ft/s
						}
						else{
							ShowDescription(sfrinfo[RxBuf_2[3]]);	// Actual Freq. Hz
						}
					}
					else{
						ShowDescription(sfrinfo[RxBuf_2[3]]);
					}
					// ]
                    ax = 0;
                    do{
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                        bx--;
                    }while(bx!=0);
                }
                else
                    COM2Err = PC_CE03;			
			}
			else
				COM2Err = PC_CE02;			
		}
		else if ((RxBuf_2[2]>=0x40)&&(RxBuf_2[2]<0x50)){
      		ax = RxBuf_2[2] - 0x40;
      		if (ax<GROUPTmp){
                if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
          			ax = pr_gpno_Sibo[RxBuf_2[3]];
                else
                    ax = pr_gpno[RxBuf_2[3]];
            	if ((UWORD)RxBuf_2[3]< ax) {    // function number //
              		if ((RxBuf_2[5]<C24MAX)){
                		ax=(SWORD)prtab[(RxBuf_2[2]&0x0F)]+RxBuf_2[3];     // pr index //Max.SJ
                		RxBuf_2[2]=RxBuf_2[5]<<1;     // word->byte data_count
                		TxCntTemp=2;
                		bx=RxBuf_2[5];         // data count //
              			//ShowDescription(prinfo[ax]);
                        if ((C20xx[0x05]&0xff00) == 0x0400){// Add RUS and TUR Text, Jason, 2020/07/22
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
                                    if(pr[UNITSEL] == 1){
                                        if(ax == S4DEC3){
                                            ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                        }
                                        else{
                                            ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                        }
                                    }
                                    else if(pr[UNITSEL] == 2){
                                        if(ax == S4DEC3){
                                            ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                        }
                                        else{
                                            ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                        }
                                    }
                                }
                                else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)){
                                    if(pr[UNITSEL] == 1){
                                        if(ax == DECEL5){
                                            ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                        }
                                        else{
                                            ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                        }
                                    }
                                    else if(pr[UNITSEL] == 2){
                                        if(ax == DECEL5){
                                            ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                        }
                                        else{
                                            ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                        }
                                    }
                                }
                                else if((ax==STO_LOCK)||(ax==FLAND)){
                                        #if SIBO_ENABLE
                                        ShowDescription(prinfo_tur[ACI_SL]);
                                        #else
                                        #if Language_TR
                                        ShowDescription(prinfo_tur[ax]);
                                        #else
                                        ShowDescription(prinfo[ax]);
                                        #endif
                                        #endif
                                }
                                else if((ax>=FMI0)&&(ax<=FMI15)){
                                        #if SIBO_ENABLE
                                        ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                        #else
                                        #if Language_TR
                                        ShowDescription(prinfo_tur[ax]);
                                        #else
                                        ShowDescription(prinfo[ax]);
                                        #endif
                                        #endif
                                }
                                else if((ax>=JOGACC)&&(ax<=JOGF)){
                                        #if SIBO_ENABLE
                                        ShowDescription(SIBO_INS[ax-JOGACC]);
                                        #else
                                        #if Language_TR
                                        ShowDescription(prinfo_tur[ax]);
                                        #else
                                        ShowDescription(prinfo[ax]);
                                        #endif
                                        #endif
                                }
                                //] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
                                else{
                                    #if Language_TR
                                    ShowDescription(prinfo_tur[ax]);
                                    #else
                                    ShowDescription(prinfo[ax]);
                                    #endif
                                }
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

                        else if ((C20xx[0x05]&0xff00) == 0x0800){
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
								if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
									if(pr[UNITSEL] == 1){
										if(ax == S4DEC3){
                                            #if Language_RUS
											ShowDescription(prinfo_rus_SCurve_ms3[ax-S4DEC3+4]);
                                            #else
											ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                            #endif
										}
										else{
                                            #if Language_RUS
											ShowDescription(prinfo_rus_SCurve_ms3[ax-S4ACC1]);
                                            #else
											ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                            #endif
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == S4DEC3){
                                            #if Language_RUS
											ShowDescription(prinfo_rus_SCurve_fts3[ax-S4DEC3+4]);
                                            #else
											ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                            #endif
										}
										else{
                                            #if Language_RUS
											ShowDescription(prinfo_rus_SCurve_fts3[ax-S4ACC1]);
                                            #else
											ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                            #endif
										}
									}
								}
								else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)){
									if(pr[UNITSEL] == 1){
										if(ax == DECEL5){
                                            #if Language_RUS
											ShowDescription(prinfo_rus_ACC_ms2[ax-DECEL5+10]);
                                            #else
											ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                            #endif
										}
										else{
                                            #if Language_RUS
											ShowDescription(prinfo_rus_ACC_ms2[ax-ACCEL1]);
                                            #else
											ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                            #endif
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == DECEL5){
                                            #if Language_RUS
											ShowDescription(prinfo_rus_ACC_fts2[ax-DECEL5+10]);
                                            #else
											ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                            #endif
										}
										else{
                                            #if Language_RUS
											ShowDescription(prinfo_rus_ACC_fts2[ax-ACCEL1]);
                                            #else
											ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                            #endif
										}
									}
								}
                                else if((ax==STO_LOCK)||(ax==FLAND)){
                                    #if SIBO_ENABLE
                                    ShowDescription(prinfo_rus[ACI_SL]);
                                    #else
                                    #if Language_RUS
                                    ShowDescription(prinfo_rus[ax]);
                                    #else
                                    ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
                                }
                                else if((ax>=FMI0)&&(ax<=FMI15)){
                                        #if SIBO_ENABLE
                                        ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                        #else
                                        #if Language_RUS
                                        ShowDescription(prinfo_rus[ax]);
                                        #else
                                        ShowDescription(prinfo[ax]);
                                        #endif
                                        #endif
								}
                                else if((ax>=JOGACC)&&(ax<=JOGF)){
                                        #if SIBO_ENABLE
                                        ShowDescription(SIBO_INS[ax-JOGACC]);
                                        #else
                                        #if Language_RUS
                                        ShowDescription(prinfo_rus[ax]);
                                        #else
                                        ShowDescription(prinfo[ax]);
                                        #endif
                                        #endif
                                }
								//] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
								else{
                                    #if Language_RUS
                               	 	ShowDescription(prinfo_rus[ax]);
                                    #else
                               	 	ShowDescription(prinfo[ax]);
                                    #endif
								}
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
                        // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                        else if ((C20xx[0x05]&0xff00) == 0x0200){
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
								if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
									if(pr[UNITSEL] == 1){
										if(ax == S4DEC3){
                                            #if Language_TC
											ShowDescription(prinfo_tc_SCurve_ms3[ax-S4DEC3+4]);
                                            #else
											ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                            #endif
										}
										else{
                                            #if Language_TC
											ShowDescription(prinfo_tc_SCurve_ms3[ax-S4ACC1]);
                                            #else
											ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                            #endif
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == S4DEC3){
                                            #if Language_TC
											ShowDescription(prinfo_tc_SCurve_fts3[ax-S4DEC3+4]);
                                            #else
											ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                            #endif
										}
										else{
                                            #if Language_TC
											ShowDescription(prinfo_tc_SCurve_fts3[ax-S4ACC1]);
                                            #else
											ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                            #endif
										}
									}
								}
								else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
									if(pr[UNITSEL] == 1){
										if(ax == DECEL5){
                                            #if Language_TC
											ShowDescription(prinfo_tc_ACC_ms2[ax-DECEL5+10]);
                                            #else
											ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                            #endif
										}
										else{
                                            #if Language_TC
											ShowDescription(prinfo_tc_ACC_ms2[ax-ACCEL1]);
                                            #else
											ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                            #endif
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == DECEL5){
                                            #if Language_TC
											ShowDescription(prinfo_tc_ACC_fts2[ax-DECEL5+10]);
                                            #else
											ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                            #endif
										}
										else{
                                            #if Language_TC
											ShowDescription(prinfo_tc_ACC_fts2[ax-ACCEL1]);
                                            #else
											ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                            #endif
										}
									}
								}
                                else if((ax==STO_LOCK)||(ax==FLAND)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(prinfo_tc[ACI_SL]);
                                    #else
                                    #if Language_TC
                                        ShowDescription(prinfo_tc[ax]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
                                }
                                else if((ax>=FMI0)&&(ax<=FMI15)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                    #else
                                    #if Language_TC
                                        ShowDescription(prinfo_tc[ax]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
								}
                                else if((ax>=JOGACC)&&(ax<=JOGF)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(SIBO_INS[ax-JOGACC]);
                                    #else
                                    #if Language_TC
                                        ShowDescription(prinfo_tc[ax]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
                                }
								//] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
								else{
                                    #if Language_TC
                               	 	ShowDescription(prinfo_tc[ax]);
                                    #else
                               	 	ShowDescription(prinfo[ax]);
                                    #endif
								}
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
								if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
									if(pr[UNITSEL] == 1){
										if(ax == S4DEC3){
                                            #if Language_SC
											ShowDescription(prinfo_sc_SCurve_ms3[ax-S4DEC3+4]);
                                            #else
											ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                            #endif
										}
										else{
                                            #if Language_SC
											ShowDescription(prinfo_sc_SCurve_ms3[ax-S4ACC1]);
                                            #else
											ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                            #endif
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == S4DEC3){
                                            #if Language_SC
											ShowDescription(prinfo_sc_SCurve_fts3[ax-S4DEC3+4]);
                                            #else
											ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                            #endif
										}
										else{
                                            #if Language_SC
											ShowDescription(prinfo_sc_SCurve_fts3[ax-S4ACC1]);
                                            #else
											ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                            #endif
										}
									}
								}
								else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)){
									if(pr[UNITSEL] == 1){
										if(ax == DECEL5){
                                            #if Language_SC
											ShowDescription(prinfo_sc_ACC_ms2[ax-DECEL5+10]);
                                            #else
											ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                            #endif
										}
										else{
                                            #if Language_SC
											ShowDescription(prinfo_sc_ACC_ms2[ax-ACCEL1]);
                                            #else
											ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                            #endif
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == DECEL5){
                                            #if Language_SC
											ShowDescription(prinfo_sc_ACC_fts2[ax-DECEL5+10]);
                                            #else
											ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                            #endif
										}
										else{
                                            #if Language_SC
											ShowDescription(prinfo_sc_ACC_fts2[ax-ACCEL1]);
                                            #else
											ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                            #endif
										}
									}
								}
                                else if((ax==STO_LOCK)||(ax==FLAND)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(prinfo_sc[ACI_SL]);
                                    #else
                                    #if Language_SC
                                        ShowDescription(prinfo_sc[ax]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
								}
                                else if((ax>=FMI0)&&(ax<=FMI15)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                    #else
                                    #if Language_SC
                                        ShowDescription(prinfo_sc[ax]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
                                }
                                else if((ax>=JOGACC)&&(ax<=JOGF)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(SIBO_INS[ax-JOGACC]);
                                    #else
                                    #if Language_SC
                                        ShowDescription(prinfo_sc[ax]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                    #endif
                                }
								else{
                                    #if Language_SC
                               	 	ShowDescription(prinfo_sc[ax]);
                                    #else
                               	 	ShowDescription(prinfo[ax]);
                                    #endif
								}
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
							//[ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
								if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
									if(pr[UNITSEL] == 1){
										if(ax == S4DEC3){
											ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
										}
										else{
											ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == S4DEC3){
											ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
										}
										else{
											ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
										}
									}
								}
								else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)){
									if(pr[UNITSEL] == 1){
										if(ax == DECEL5){
											ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
										}
										else{
											ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
										}
									}
									else if(pr[UNITSEL] == 2){
										if(ax == DECEL5){
											ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
										}
										else{
											ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
										}
									}
								}
                                else if((ax==STO_LOCK)||(ax==FLAND)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(prinfo[ACI_SL]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
								}
                                else if((ax>=FMI0)&&(ax<=FMI15)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                }
                                else if((ax>=JOGACC)&&(ax<=JOGF)){
                                    #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                        ShowDescription(SIBO_INS[ax-JOGACC]);
                                    #else
                                        ShowDescription(prinfo[ax]);
                                    #endif
                                }
								else{
                               	 	ShowDescription(prinfo[ax]);
								}
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
              			ax = 0;
              			do {   // prepare data
                			TxCntTemp++;
                			RxBuf_2[TxCntTemp]=(UBYTE)(Descript[ax]>>8);
                			TxCntTemp++;
                			RxBuf_2[TxCntTemp]=(UBYTE)Descript[ax];
                			ax++;
                			bx--;
              			} while(bx!=0);
              		}
              		else
                		COM2Err = PC_CE03;
                }
				else
                	COM2Err = PC_CE03;
			}
			else
				COM2Err = PC_CE03;
		}
		else if ((RxBuf_2[2]>=0x50)&&(RxBuf_2[2]<0x60)){
            bx = (RxBuf_2[2]) & (UBYTE)0x0F;    // Group index
            cx = (RxBuf_2[3]);
            ax = (UWORD)prtab[bx] + cx; 
            if (bx == MAPGOURP){
                umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_2[3]] / 100;
                umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_2[3]] - umap_addr.ub.hi * 100;
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
                    if((DispAttr_c22xx[(umap_addr.ub.low+C22MAX-1)].ati&JMP)==JMP){ //[solve the problem about access c22xx, Bernie, 2016/02/01]  // Modify by DINO, 09/08/2008
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
//                              else if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] ){
                    ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
                }
                // ]
                // Access to unavailable address
                else{
                    //[Remove DateCode unavaliable, Jason, 2018/11/15]
                    if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 61)
                    {
                        ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                    }
                    else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 78)
                    {
                        //[BootLoader Version, Special.Kung, 2022/10/31]
                        ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                    }
                    else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 83)
                    {
                        //[BootLoader DataCode, Special.Kung, 2022/10/31]
                        ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                    }
                    else
                    {
                        umap_addr.ub.hi = 0;
                        ax = Unavaliable;   // Unavailable parameter, display "Unavailable"
                    }
                }
            }
    		if ((attr[ax].ati & ITEM)==ITEM){	// Have item display
    			bx = RxBuf_2[5];

    			//dx = ((attr[ax].LangAti & (UWORD)0x7FC0)>>6);
    			if (bx==0x08){            
    				cx = RxBuf_2[4]; 
    				RxBuf_2[2] = (UBYTE)(bx<<1);
    				TxCntTemp = 2;
                    //ShowDescription(prinfo[cx]);  
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                    if((ax <= FMI6) && (ax >= FMI0))
                        ShowDescription(SIBO_SPOPTTABLE[cx]);  
#endif  		
                    //else if(ax==SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15])
                       //ShowDescription(ENABLE_TABLE[cx]);
                    
    				ax = 0;
    				do{				// prepare data
    					umap_addr.uw = Descript[ax] ;
    					TxCntTemp++;
    					RxBuf_2[TxCntTemp] = umap_addr.ub.hi;
    					TxCntTemp++;
    					RxBuf_2[TxCntTemp] = umap_addr.ub.low;
    					ax++;
    					bx--;
    				}while(bx!=0);
    			}
    			else{
                    COM2Err = PC_CE03;
    			}
    		}
			else
				COM2Err = PC_CE03;
		}

        else if(RxBuf_2[2]==(GROUPTmp+1)){
            ax = RxBuf_2[3];
            if (((GROUPTmp+1)>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
                RxBuf_2[2] = RxBuf_2[5]<<1;    // word->byte data_count
                TxCntTemp = 2;
                bx = RxBuf_2[5];             // data count
                do{
      				if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                    	TempValue = pr_gpno_Sibo[ax] - 1;
      				else
                    	TempValue = pr_gpno[ax] - 1;
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=((UWORD)TempValue >> 8);
                    TxCntTemp++;
                    RxBuf_2[TxCntTemp]=((UWORD)TempValue & 0x00ff);
                    ax++;
                    bx--;
                } while(bx!=0);
            }
            else
                COM2Err = PC_CE03;
        }
		//--- Address 9999H: "DELAT ELECTRONICS   " Copyright Display, Add by DINO, 12/01/2008 ---//
		else if (RxBuf_2[2]==0x99){	// Warning Description, 16+4 byte
			if ( RxBuf_2[3]==0x99 ){
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
				RxBuf_2[2] 	= 0x14 ;			// Number of datas = 20 bytes
				ax = 0 ;
				bx = RxBuf_2[5];             	// data count

				TxCntTemp = 2 ;
				do {				// prepare data
					umap_addr.uw = Descript[ax] ;
					TxCntTemp++;
					RxBuf_2[TxCntTemp] = umap_addr.ub.hi;
					TxCntTemp++;
					RxBuf_2[TxCntTemp] = umap_addr.ub.low;
					ax++;
					bx--;
				} while(bx!=0);
			}
			else
				COM2Err = PC_CE02;
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

            if (RxBuf_2[2]<=ax){        // group number //
      		    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                	ax = pr_gpno_Sibo[RxBuf_2[2]];
      	        else
                	ax = pr_gpno[RxBuf_2[2]];
                if (RxBuf_2[3]< ax) {    // function number //            
                    if ((PUON2LINE==1)||(RxBuf_2[0]==0xFF)){//read parameter by PU
                        if ((RxBuf_2[5]==0x0A)&&(RxBuf_2[4]==0)) {

	                        ax = (UWORD)prtab[RxBuf_2[2]]+RxBuf_2[3]; // pr index //

                            bx = RxBuf_2[5];
                            TxCntTemp = 2;
                            RxBuf_2[2] = RxBuf_2[5]<<1;
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
					                // Add RUS and TUR Text, Jason, 2020/07/22					                
                                    if ((C20xx[0x05]&0xff00) == 0x0400){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_TR
                                            ShowDescription(prinfo_tur[ax]);
                                            #else
                                            ShowDescription(prinfo[ax]);
                                            #endif
                                        }
                                        else{
										    // JINGDO
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
                                        }
                                    }
                                    else if ((C20xx[0x05]&0xff00) == 0x0800){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                            #if Language_RUS
                                            ShowDescription(prinfo_rus[ax]);
                                            #else
                                            ShowDescription(prinfo[ax]);
                                            #endif
                                        }
                                        else{
										    // JINGDO
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
                                        }
                                    }
                                    // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                                    else if ((C20xx[0x05]&0xff00) == 0x0200){
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

                        		    if ((attr[ax].ati&CHG) == CHG){
                        		    	ubCHGFlag = 1;
                        		    }
					            }

								if (ubCHGFlag == 1){
									if (pr[UNITSEL] == 1){
										if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
										|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
										|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
										|| (ax == JOGDEC) || (ax == DECEL5)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
										|| (ax == SIBO_DECEMY)
#endif
										)
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('m'<<8)+'/';
											Descript[9] = ('s'<<8)+'2';											
										}
										else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
											|| (ax == S4DEC2) || (ax == S4DEC3)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
											|| (ax == SIBO_S3EMY)|| (ax == SIBO_S4EMY)
#endif
											)
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
										if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
										|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
										|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
										|| (ax == JOGDEC) || (ax == DECEL5)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
										|| (ax == SIBO_DECEMY)
#endif
										)
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'2';											
										}
										else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
											|| (ax == S4DEC2) || (ax == S4DEC3)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
											|| (ax == SIBO_S3EMY)|| (ax == SIBO_S4EMY)
#endif
											)
												&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
											Descript[8]  = ('f'<<8)+'/';
											Descript[9] = ('s'<<8)+'3';
										}
										else{  // ft/s
											Descript[8]  = ('f'<<8)+'t';
											Descript[9] = ('/'<<8)+'s';
										}
									}
                                    else if (pr[UNITSEL] == 3){          //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+'2';
									}
								}
								// ]
					        }
                            ax = 0;
                            do{
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                                ax++;
                                bx--;
                            } while(bx!=0);
                        }
                        //Data,Max,Min,Att,Def
                        else if ((RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
#if ACCESS_GROUP
							if (RxBuf_2[2] == MAPGOURP){
    	    	        		umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_2[3]] / 100;
                				umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_2[3]] - umap_addr.ub.hi * 100;
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
                                    if((DispAttr_c22xx[(umap_addr.ub.low+C22MAX-1)].ati&JMP)==JMP){ //[solve the problem about access c22xx, Bernie, 2016/02/01]  // Modify by DINO, 09/08/2008
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
									//[Remove DateCode unavaliable, Jason, 2018/11/15]
									if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 61)
                                    {                           
										ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                                    }
                                    else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 78)
                                    {
                                        //[BootLoader Version, Special.Kung, 2022/10/31]
                                        ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                                    }
                                    else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 83)
                                    {
                                        //[BootLoader DataCode, Special.Kung, 2022/10/31]
                                        ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                                    }
									else
									{
	            	    				umap_addr.ub.hi = 0;
	            	    				ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
									}
            	    			}
							}
							else
#endif
	                            ax = (UWORD)prtab[RxBuf_2[2]]+RxBuf_2[3]; // pr index //        
                                bx = RxBuf_2[5];
                                TxCntTemp = 2;
                                RxBuf_2[2] = RxBuf_2[5]<<1;
#if ACCESS_GROUP
                            // [ Velocity Unit Change, Add by DINO, 05/25/2009
                            ubCHGFlag = 0;
                            // ]
                            
                            if ( umap_addr.ub.hi==21 ){
            					//Data Content
            					ax = umap_addr.ub.low;            //[solve the problem about access c22xx, Bernie, 2016/02/01] 
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                                //Data Max
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0xff;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0xff;
                                //Data Min
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                //Data attribute
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = DispAttr[ax].ati>>8;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = DispAttr[ax].ati&0x00ff;
                                //Data default
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
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
								
            			        ax = umap_addr.ub.low;      //[solve the problem about access c22xx, Bernie, 2016/02/01]
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = ((UWORD)C22xx[ax]>>8);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = ((UWORD)C22xx[ax] & 0x00ff);
                                //Data Max
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0xff;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0xff;
                                //Data Min
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                //Data attribute
                                TxCntTemp++;

                                //RxBuf_2[TxCntTemp] = DispAttr[(ax+C21MAX)].ati>>8;
                                RxBuf_2[TxCntTemp] = DispAttr_c22xx[(ax)].ati>>8;         //[solve the problem about access c22xx, Bernie, 2016/02/01]
                                TxCntTemp++;
                                //RxBuf_2[TxCntTemp] = DispAttr[(ax+C21MAX)].ati&0x00ff;
                                RxBuf_2[TxCntTemp] = DispAttr_c22xx[(ax)].ati&0x00ff;     //[solve the problem about access c22xx, Bernie, 2016/02/01]
                                //Data default
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = 0x00;
                                //Data Description
                                    ax = umap_addr.ub.low;       //[solve the problem about access c22xx, Bernie, 2016/02/01]

                                    
                                ShowDescription(c22info[ax]);
                            }
#endif
                            else{
                                TxCntTemp++;
                                // [ Velocity Unit Change, Add by DINO, 05/25/2009
                        		uwEEPData.uw = GetParData(ax);
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
								// ]

                                uwEEPData.uw = GetParMax(ax);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.low;

                                uwEEPData.uw = GetParMin(ax);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
                            	uwEEPData.uw = GetParAttr(ax);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.low;

//-- Add by VE item91, 10/30/2008
                            	if ((pr[HPSPEC]&VFD440V)==VFD220V){    // 220V class
									if ( (attr[ax].ati&V440)==V440 )
										uwEEPData.uw = attr[ax].def>>1;
									else
										uwEEPData.uw = attr[ax].def;
                            	}
                            	else{
                            	    uwEEPData.uw = attr[ax].def;
                            	}
//-- End on 10/30/2008
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
                                //Data Description
           						if (CHKCPR==1)
					                function_chk();
					            else{
                                    //ShowDescription(prinfo[ax]);
                                    // Add RUS and TUR Text, Jason, 2020/07/22
                                    if ((C20xx[0x05]&0xff00) == 0x0400){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
											if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
												if(pr[UNITSEL] == 1){
													if(ax == S4DEC3){
														ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
													}
													else{
														ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == S4DEC3){
														ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
													}
													else{
														ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
													}
												}
											}
											else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												if(pr[UNITSEL] == 1){
													if(ax == DECEL5){
														ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
													}
													else{
														ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == DECEL5){
														ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
													}
													else{
														ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
													}
												}
											}
                                            else if((ax==STO_LOCK)||(ax==FLAND)){
                                                    #if SIBO_ENABLE
                                                    ShowDescription(prinfo_tur[ACI_SL]);
                                                    #else
                                                    #if Language_TR
                                                    ShowDescription(prinfo_tur[ax]);
                                                    #else
                                                    ShowDescription(prinfo[ax]);
                                                    #endif
                                                    #endif
                                            }
                                            else if((ax>=FMI0)&&(ax<=FMI15)){
                                                    #if SIBO_ENABLE
                                                    ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                                    #else
                                                    #if Language_TR
                                                    ShowDescription(prinfo_tur[ax]);
                                                    #else
                                                    ShowDescription(prinfo[ax]);
                                                    #endif
                                                    #endif
                                            }
                                            else if((ax>=JOGACC)&&(ax<=JOGF)){
                                                    #if SIBO_ENABLE
                                                    ShowDescription(SIBO_INS[ax-JOGACC]);
                                                    #else
                                                    #if Language_TR
                                                    ShowDescription(prinfo_tur[ax]);
                                                    #else
                                                    ShowDescription(prinfo[ax]);
                                                    #endif
                                                    #endif
                                            }
											//] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
											else{
                                                #if Language_TR
											    ShowDescription(prinfo_tur[ax]);
                                                #else
											    ShowDescription(prinfo[ax]);
                                                #endif
											}
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
                                    else if ((C20xx[0x05]&0xff00) == 0x0800){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
											if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
												if(pr[UNITSEL] == 1){
													if(ax == S4DEC3){
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_SCurve_ms3[ax-S4DEC3+4]);
                                                        #else
														ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                                        #endif
													}
													else{
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_SCurve_ms3[ax-S4ACC1]);
                                                        #else
														ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                                        #endif
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == S4DEC3){
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_SCurve_fts3[ax-S4DEC3+4]);
                                                        #else
														ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                                        #endif
													}
													else{
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_SCurve_fts3[ax-S4ACC1]);
                                                        #else
														ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                                        #endif
													}
												}
											}
											else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												if(pr[UNITSEL] == 1){
													if(ax == DECEL5){
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_ACC_ms2[ax-DECEL5+10]);
                                                        #else
														ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                                        #endif
													}
													else{
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_ACC_ms2[ax-ACCEL1]);
                                                        #else
														ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                                        #endif
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == DECEL5){
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_ACC_fts2[ax-DECEL5+10]);
                                                        #else
														ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                                        #endif
													}
													else{
                                                        #if Language_RUS
														ShowDescription(prinfo_rus_ACC_fts2[ax-ACCEL1]);
                                                        #else
														ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                                        #endif
													}
												}
											}
                                            else if((ax==STO_LOCK)||(ax==FLAND)){
                                                    #if SIBO_ENABLE
                                                    ShowDescription(prinfo_rus[ACI_SL]);
                                                    #else
                                                    #if Language_RUS
                                                    ShowDescription(prinfo_rus[ax]);
                                                    #else
                                                    ShowDescription(prinfo[ax]);
                                                    #endif
                                                    #endif
                                            }
                                            else if((ax>=FMI0)&&(ax<=FMI15)){
                                                    #if SIBO_ENABLE
                                                    ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                                    #else
                                                    #if Language_RUS
                                                    ShowDescription(prinfo_rus[ax]);
                                                    #else
                                                    ShowDescription(prinfo[ax]);
                                                    #endif
                                                    #endif
                                            }
                                            else if((ax>=JOGACC)&&(ax<=JOGF)){
                                                    #if SIBO_ENABLE
                                                    ShowDescription(SIBO_INS[ax-JOGACC]);
                                                    #else
                                                    #if Language_RUS
                                                    ShowDescription(prinfo_rus[ax]);
                                                    #else
                                                    ShowDescription(prinfo[ax]);
                                                    #endif
                                                    #endif
                                            }
											//] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
											else{
                                                #if Language_RUS
											    ShowDescription(prinfo_rus[ax]);
                                                #else
                                                ShowDescription(prinfo[ax]);
                                                #endif
											}
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
                                    // [ Add Traditional and Simple Chinese Text, DINO, 10/14/2010
                                    else if ((C20xx[0x05]&0xff00) == 0x0200){
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
											if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
												if(pr[UNITSEL] == 1){
													if(ax == S4DEC3){
                                                        #if Language_TC
														ShowDescription(prinfo_tc_SCurve_ms3[ax-S4DEC3+4]);
                                                        #else
														ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                                        #endif
													}
													else{
                                                        #if Language_TC
														ShowDescription(prinfo_tc_SCurve_ms3[ax-S4ACC1]);
                                                        #else
														ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                                        #endif
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == S4DEC3){
                                                        #if Language_TC
														ShowDescription(prinfo_tc_SCurve_fts3[ax-S4DEC3+4]);
                                                        #else
														ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                                        #endif
													}
													else{
                                                        #if Language_TC
														ShowDescription(prinfo_tc_SCurve_fts3[ax-S4ACC1]);
                                                        #else
														ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                                        #endif
													}
												}
											}
											else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												if(pr[UNITSEL] == 1){
													if(ax == DECEL5){
                                                        #if Language_TC
														ShowDescription(prinfo_tc_ACC_ms2[ax-DECEL5+10]);
                                                        #else
														ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                                        #endif
													}
													else{
                                                        #if Language_TC
														ShowDescription(prinfo_tc_ACC_ms2[ax-ACCEL1]);
                                                        #else
														ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                                        #endif
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == DECEL5){
                                                        #if Language_TC
														ShowDescription(prinfo_tc_ACC_fts2[ax-DECEL5+10]);
                                                        #else
														ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                                        #endif
													}
													else{
                                                        #if Language_TC
														ShowDescription(prinfo_tc_ACC_fts2[ax-ACCEL1]);
                                                        #else
														ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                                        #endif
													}
												}
											}
                                            else if((ax==STO_LOCK)||(ax==FLAND)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(prinfo_tc[ACI_SL]);
                                                #else
                                                #if Language_TC
                                                    ShowDescription(prinfo_tc[ax]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                                #endif
                                            }
                                            else if((ax>=FMI0)&&(ax<=FMI15)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                                #else
                                                #if Language_TC
                                                    ShowDescription(prinfo_tc[ax]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                                #endif
                                            }
                                            else if((ax>=JOGACC)&&(ax<=JOGF)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(SIBO_INS[ax-JOGACC]);
                                                #else
                                                #if Language_TC
                                                    ShowDescription(prinfo_tc[ax]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                                #endif
                                            }
											//] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
											else{
                                                #if Language_TC
											    ShowDescription(prinfo_tc[ax]);
                                                #else
											    ShowDescription(prinfo[ax]);
                                                #endif
											}
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
											if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
												if(pr[UNITSEL] == 1){
													if(ax == S4DEC3){
                                                        #if Language_SC
														ShowDescription(prinfo_sc_SCurve_ms3[ax-S4DEC3+4]);
                                                        #else
														ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
                                                        #endif
													}
													else{
                                                        #if Language_SC
														ShowDescription(prinfo_sc_SCurve_ms3[ax-S4ACC1]);
                                                        #else
														ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
                                                        #endif
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == S4DEC3){
                                                        #if Language_SC
														ShowDescription(prinfo_sc_SCurve_fts3[ax-S4DEC3+4]);
                                                        #else
														ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
                                                        #endif
													}
													else{
                                                        #if Language_SC
														ShowDescription(prinfo_sc_SCurve_fts3[ax-S4ACC1]);
                                                        #else
														ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
                                                        #endif
													}
												}
											}
											else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												if(pr[UNITSEL] == 1){
													if(ax == DECEL5){
                                                        #if Language_SC
														ShowDescription(prinfo_sc_ACC_ms2[ax-DECEL5+10]);
                                                        #else
														ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
                                                        #endif
													}
													else{
                                                        #if Language_SC
														ShowDescription(prinfo_sc_ACC_ms2[ax-ACCEL1]);
                                                        #else
														ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
                                                        #endif
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == DECEL5){
                                                        #if Language_SC
														ShowDescription(prinfo_sc_ACC_fts2[ax-DECEL5+10]);
                                                        #else
														ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
                                                        #endif
													}
													else{
                                                        #if Language_SC
														ShowDescription(prinfo_sc_ACC_fts2[ax-ACCEL1]);
                                                        #else
														ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
                                                        #endif
													}
												}
											}
                                            else if((ax==STO_LOCK)||(ax==FLAND)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(prinfo_sc[ACI_SL]);
                                                #else
                                                #if Language_SC
                                                    ShowDescription(prinfo_sc[ax]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                                #endif
                                            }
                                            else if((ax>=FMI0)&&(ax<=FMI15)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                                #else
                                                #if Language_SC
                                                    ShowDescription(prinfo_sc[ax]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                                #endif
                                            }
                                            else if((ax>=JOGACC)&&(ax<=JOGF)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(SIBO_INS[ax-JOGACC]);
                                                #else
                                                #if Language_SC
                                                    ShowDescription(prinfo_sc[ax]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                                #endif 
                                            }
											else{
                                                #if Language_SC
											    ShowDescription(prinfo_sc[ax]);
                                                #else
                                                ShowDescription(prinfo[ax]);
                                                #endif
											}
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
                        		            else if(pr[FLOOR_PAGE]==4)//[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_sc_Adjst[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==5)//[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_sc_Adjst2[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==6)//[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_sc_Adjst3[(ax-DLC_PR)]);
                                            #else
											if(pr[FLOOR_PAGE]==1)
											    ShowDescription(prinfo_DLC[(ax-DLC_PR)]);     //[DLC parameter display in Group 4, Bernie, 2016/01/27]
											else if(pr[FLOOR_PAGE]==2)
											    ShowDescription(prinfo_DLC2[(ax-DLC_PR)]);
                                            else if(pr[FLOOR_PAGE]==3) //[adjust floor position adjust,Aevin,2018/06/19]
                        		                ShowDescription(prinfo_DLC3[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==4)//[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==5)//[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst2[(ax-DLC_PR)]);
                        		            else if(pr[FLOOR_PAGE]==6)//[adjust floor position,Henry,2019/01/07]
                          	                    ShowDescription(prinfo_DLC_Adjst3[(ax-DLC_PR)]);
                                            #endif
                                       }
                                    }
                                    else{
                                        if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
										//[ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
											if((((ax >= S4ACC1)&&(ax <= S4DEC2))||(ax == S4DEC3))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){ //[S curve, ACC unit,Jason,2019/10/01]
												if(pr[UNITSEL] == 1){
													if(ax == S4DEC3){
														ShowDescription(prinfo_SCurve_ms3[ax-S4DEC3+4]);
													}
													else{
														ShowDescription(prinfo_SCurve_ms3[ax-S4ACC1]);
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == S4DEC3){
														ShowDescription(prinfo_SCurve_fts3[ax-S4DEC3+4]);
													}
													else{
														ShowDescription(prinfo_SCurve_fts3[ax-S4ACC1]);
													}
												}
											}
											else if((((ax >= ACCEL1)&&(ax <= DECEL4))||(ax == DECEL5))&&(pr[UNITSEL] >= 1)&&((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
												if(pr[UNITSEL] == 1){
													if(ax == DECEL5){
														ShowDescription(prinfo_ACC_ms2[ax-DECEL5+10]);
													}
													else{
														ShowDescription(prinfo_ACC_ms2[ax-ACCEL1]);
													}
												}
												else if(pr[UNITSEL] == 2){
													if(ax == DECEL5){
														ShowDescription(prinfo_ACC_fts2[ax-DECEL5+10]);
													}
													else{
														ShowDescription(prinfo_ACC_fts2[ax-ACCEL1]);
													}
												}
											}
                                            else if((ax==STO_LOCK)||(ax==FLAND)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(prinfo[ACI_SL]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                            }
                                            else if((ax>=FMI0)&&(ax<=FMI15)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(SIBO_GROUP4[ax-FMI0]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                            }
                                            else if((ax>=JOGACC)&&(ax<=JOGF)){
                                                #if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                                                    ShowDescription(SIBO_INS[ax-JOGACC]);
                                                #else
                                                    ShowDescription(prinfo[ax]);
                                                #endif
                                            }
                                            //] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
											else{
												ShowDescription(prinfo[ax]);
											}
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

                                    if((pr[SOFC]<=3) && (pr[UNITSEL]<3)){                 //[DLC  function Change unit to m/s2, Bernie, 2015/09/02] //[Sibocom S curve, ACC unit,Jason,2019/10/01]
                        		        if ((attr[ax].ati&CHG) == CHG){
                        		    	    ubCHGFlag = 1;
                        		        }
                                    }
                        		    else{                                                 //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
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
										|| (ax == JOGDEC) || (ax == DECEL5)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
										|| (ax == SIBO_DECEMY)
#endif
										)
										&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
										Descript[8]  = ('m'<<8)+'/';
										Descript[9] = ('s'<<8)+'2'; 										
									}
									else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
											|| (ax == S4DEC2) || (ax == S4DEC3)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
											|| (ax == SIBO_S3EMY)|| (ax == SIBO_S4EMY)
#endif
											)
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
									if(((ax == ACCEL1) || (ax == DECEL1) || (ax == ACCEL2)	  // m/s2
										|| (ax == DECEL2) || (ax == ACCEL3) || (ax == DECEL3)
										|| (ax == ACCEL4) || (ax == DECEL4) || (ax == JOGACC)
										|| (ax == JOGDEC) || (ax == DECEL5)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
										|| (ax == SIBO_DECEMY)
#endif
										)
										&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
										Descript[8]  = ('f'<<8)+'/';
										Descript[9] = ('s'<<8)+'2'; 										
									}
									else if(((ax == S4ACC1) || (ax == S4ACC2) || (ax == S4DEC1) // m/s3
											|| (ax == S4DEC2) || (ax == S4DEC3)
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
											|| (ax == SIBO_S3EMY)|| (ax == SIBO_S4EMY)
#endif
											)
											&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
										Descript[8]  = ('f'<<8)+'/';
										Descript[9] = ('s'<<8)+'3';
									}
									else{  // ft/s
										Descript[8]  = ('f'<<8)+'t';
										Descript[9] = ('/'<<8)+'s';
									}
								}
                                else if (pr[UNITSEL] == 3){             //[parameter in keypad, Bernie, 2015/09/02 ]
									Descript[8]  = ('m'<<8)+'/';   //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
									Descript[9] = ('s'<<8)+'2';
								}
							}
							// ]


                            ax = 0;
                            do{
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                                TxCntTemp++;
                                RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                                ax++;
                            }while(ax < DESMAX);
                            TxCntTemp = (bx<<1) + 2;
                        }
                        else
                            COM2Err = PC_CE03;
                    }
                 else{//Normal read parameter value
                        if ((RxBuf_2[3]+RxBuf_2[5]<=ax)&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
                        	// [ Modify Read Function of Mapping Group, DINO, 07/02/2010
							ubGrNum = RxBuf_2[2];	// PR. Group
							ubPrNum = RxBuf_2[3];	// PR. Number
                 			uwAddr = prtab[ubGrNum] + ubPrNum;
							ax = 0;
                            RxBuf_2[2] = RxBuf_2[5]<<1;     // word->byte data_count
                            TxCntTemp = 2;
                            bx=RxBuf_2[5];  // data count //
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
                					    if ( (DispAttr[(umap_addr.ub.low+C21MAX-1)].ati&JMP)==JMP && SHOW_ALLPR==0 ){ //[solve the problem about access c22xx, Bernie, 2016/02/01]  // Modify by DINO, 09/08/2008
                					        rxdata = Unavaliable;
                					        umap_addr.ub.hi = 0;
                					    }
                					    else
                					    	rxdata = umap_addr.ub.low;
                					}
                					// Access to user parameter
                					else if ((umap_addr.ub.hi<=ACCESS  || SHOW_ALLPR==1) && umap_addr.ub.low<gpno ){
            	    					rxdata = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    				}
            	    				// Access to unavailable address
            	    				else{
                                        //[Remove DateCode unavaliable, Jason, 2018/11/15]
                                        if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 61)
                                        {
                                            ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                                        }
                                        else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 78)
                                        {
                                            //[BootLoader Version, Special.Kung, 2022/10/31]
                                            ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                                        }
                                        else if(umap_addr.ub.hi == 15 && umap_addr.ub.low == 83)
                                        {
                                            //[BootLoader DataCode, Special.Kung, 2022/10/31]
                                            ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;
                                        }
                                        else
                                        {
                                            umap_addr.ub.hi = 0;
                                            ax = Unavaliable;   // Unavailable parameter, display "Unavailable"
                                        }
            	    				}

                                	// Access to C21xx
                                	if (umap_addr.ub.hi == 21){
                                	    TxCntTemp++;
                  						RxBuf_2[TxCntTemp] = ((UWORD)C21xx[rxdata]>>8);
                  						TxCntTemp++;
                  						RxBuf_2[TxCntTemp] = ((UWORD)C21xx[rxdata] & 0x00ff);
                                	}
                                	// Access to C22xx
                                	else if (umap_addr.ub.hi == 22){
                                	    TxCntTemp++;
                  						RxBuf_2[TxCntTemp] = ((UWORD)C22xx[rxdata]>>8);
                  						TxCntTemp++;
                  						RxBuf_2[TxCntTemp] = ((UWORD)C22xx[rxdata] & 0x00ff);
                                	}
                                	// Access to User Parameter
                                	else{
                                	    if ((rxdata>=BKTRANS1)&&(rxdata<=BKTRANS10)){
                                	        rxdata = BLKTransferRead(rxdata);
                                	        TxCntTemp++;
                                	        RxBuf_2[TxCntTemp]=((UWORD)rxdata>>8);
                  						    TxCntTemp++;
                  						    RxBuf_2[TxCntTemp]=((UWORD)rxdata & 0x00ff);
                                	    }
                                	    else{
                                	        TxCntTemp++;
                  						    RxBuf_2[TxCntTemp]=((UWORD)pr[rxdata]>>8);
                  						    TxCntTemp++;
                  						    RxBuf_2[TxCntTemp]=((UWORD)pr[rxdata] & 0x00ff);
                  						}
                  					}
								}
#endif
								else{
                					umap_addr.uw = uwAddr + ax;
                                    if ((umap_addr.uw>=BKTRANS1)&&(umap_addr.uw<=BKTRANS10)){
                                        rxdata = BLKTransferRead(umap_addr.uw);
                                        TxCntTemp++;
                                        RxBuf_2[TxCntTemp]=((UWORD)rxdata>>8);
                  					    TxCntTemp++;
                  					    RxBuf_2[TxCntTemp]=((UWORD)rxdata & 0x00ff);
                                    }
                                    else{
                                        TxCntTemp++;
                  					    RxBuf_2[TxCntTemp]=((UWORD)pr[umap_addr.uw]>>8);
                  					    TxCntTemp++;
                  					    RxBuf_2[TxCntTemp]=((UWORD)pr[umap_addr.uw] & 0x00ff);
                  					}
                  				}
                  				ax++;
                  				bx--;
                			}while(bx!=0);
                  			// ]
                		}
              			else  //Data length out of range
                			COM2Err = PC_CE03;
            		}
            	}
            	else  //Function number error
            		COM2Err = PC_CE02;
          	}
          	else //group number error
          		COM2Err = PC_CE02;
        }
        Init_TxData_2(TxCntTemp);
}

void RemoteCmd06_2(void)
{
    UWORD_UNION rxdata, umap_addr;
    UWORD ax, MaxTemp, MinTemp/*,uwParData*/;
    UBYTE gpno,TxCntTemp = 0;

    //[JES SE1_ERR, Rational 282940, Special.Kung, 2022/08/24]
    COPYFLAG = 0;

    if (RxBuf_2[2] == 0x20)
    {            
        // Communication Memory Address 20xxH
        if (RxBuf_2[3] < C20MAX)
        {
            TxCntTemp = Rx2CNT;
            rxdata.ub.hi = RxBuf_2[4];
            rxdata.ub.low = RxBuf_2[5];
            Keypad_20xxH(RxBuf_2[3],rxdata.uw);
        }
        else
        {
            COM2Err = PC_CE02;
        }
    }
    else if (RxBuf_2[2] == 0x21)
    {    
        //21xx read only
		COM2Err = PC_CE04;
    }
    else if (RxBuf_2[2] == 0x23)
    {    
        //23xx read only
		COM2Err = PC_CE04;
    }
    else if (RxBuf_2[2] == 0xff)
    {
		if (RxBuf_2[3]<CALIMAX)
        {
            if ((RxBuf_2[3]==0||RxBuf_2[3]==CFFxx[0]) && (SHOW_ALLPR==1))
            {
                TxCntTemp = Rx2CNT;
                rxdata.ub.hi = RxBuf_2[4];
                rxdata.ub.low = RxBuf_2[5];
                if (RxBuf_2[3]==0)
                {
                    CFFxx[0] = rxdata.uw;
                }
                else
                {
                    FFcalibration(RxBuf_2[3],rxdata.uw);
                }
            }
            else
            {
                COM2Err = PC_CE04;
            }
        }
        else
        {
            COM2Err = PC_CE02;
        }
    }	            
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
        if (RxBuf_2[2]<=ax)
        {      
            // group NO. //
            if(SIBO_PARAMETER)
            {
                //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	ax = pr_gpno_Sibo[RxBuf_2[2]];
            }
            else
            {
        	    ax = pr_gpno[RxBuf_2[2]];
            }
            if (RxBuf_2[3]<ax)
            {     
                // function NO. //
                if ((PUON2LINE==1)||(RxBuf_2[0]==0xFF))
                {
                    KEYPAD_CMD = 1;
                }
                else
                {
                    KEYPAD_CMD = 0;
                }
				if (RxBuf_2[2] == MAPGOURP)
                {
                	umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_2[3]] / 100;
                	umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_2[3]] - umap_addr.ub.hi * 100;
                    if(SIBO_PARAMETER)
                    {
                        //[Group12&13 Limit count,Lyabryan,2020/09/10]
                        gpno = pr_gpno_Sibo[umap_addr.ub.hi];
                    }
                    else
                    {
                        gpno = pr_gpno[umap_addr.ub.hi];
                    }
          			// [ Mapping to hidden parameters, DINO, 12/23/2009
          			if ( (umap_addr.ub.hi<=ACCESS || SHOW_ALLPR==1) && umap_addr.ub.low<gpno )
                    {       
         			    //if ( umap_addr.ub.hi<=ACCESS && umap_addr.ub.low<pr_gpno[umap_addr.ub.hi] )
            	    	ax = (UWORD)prtab[umap_addr.ub.hi] + umap_addr.ub.low;     // pr index //
            	    // ]
                    }
            	    else
                    {   
            	    	ax = Unavaliable;	// Unavailable parameter, display "Unavailable"
                    }
				}
				else
                {            
               	    ax = (UWORD)prtab[RxBuf_2[2]]+RxBuf_2[3];     // pr index //
                }

                TxCntTemp = Rx2CNT;
                rxdata.ub.hi = RxBuf_2[4];
                rxdata.ub.low = RxBuf_2[5];
                
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
                    COM2Err = PC_CE02;
                }

                KEYPAD_CMD = 0;         
            }
            else
            {
                COM2Err = PC_CE02;   // Illegal function NO. //
            }
        }
        else
        {
            COM2Err = PC_CE02;   // Illegal group NO. //
        }
    }
    Init_TxData_2(TxCntTemp);
}

void RemoteCmd63_2(void)
{
    UBYTE TxCntTemp = 0, bx, ubCHGFlag,gpno;
    UWORD ax;
    UWORD_UNION umap_addr;
    UWORD_UNION uwEEPData;

    
    umap_addr.uw = 0;
        
    if (RxBuf_2[2] == 0x20){            // Communication Memory Address 20xxH               
        ax = RxBuf_2[3];
        if ((C20MAX >= (ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)) {
            RxBuf_2[2] = RxBuf_2[5]<<1;         // word->byte data_count
            TxCntTemp = 2;
            bx = RxBuf_2[5];                  // data count //
            //Data Content
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = (UBYTE)(C20xx[ax]>>8);
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = (UBYTE)(C20xx[ax]);
            //Data Max
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0xff;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0xff;
            //Data Min
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            //Data attribute
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            //Data default
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            //Data Description
            ShowDescription(c20info[ax]);
            ax = 0;
            do{
                TxCntTemp++;
                RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                TxCntTemp++;
                RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                ax++;
            }while(ax < DESMAX);
            TxCntTemp = (bx<<1) + 2;
        }
        else
            COM2Err = PC_CE03;
    }        
    else if (RxBuf_2[2]==0x21){
        ax = RxBuf_2[3];
        if ((C21MAX>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
            //Update_C21xx();
            RxBuf_2[2] = RxBuf_2[5]<<1;           // word->byte data_count
            TxCntTemp = 2;
            bx = RxBuf_2[5];                    // data count //
            //Data Content
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
            //Data Max
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0xff;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0xff;
            //Data Min
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            //Data attribute
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = DispAttr[ax].ati>>8;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = DispAttr[ax].ati&0x00ff;
            //Data default
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
            TxCntTemp++;
            RxBuf_2[TxCntTemp] = 0x00;
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
                else if (pr[UNITSEL] == 3){           //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]    
					Descript[8]  = ('m'<<8)+'/';
					Descript[9] = ('s'<<8)+'2';
				}
			}
			// ]
            ax = 0;
            do{
                TxCntTemp++;
                RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                TxCntTemp++;
                RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                ax++;
            }while(ax < DESMAX);
            TxCntTemp = (bx<<1) + 2;
        }
        else
            COM2Err = PC_CE03;
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

        if (RxBuf_2[2]<=ax){        // group number //
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	ax = pr_gpno_Sibo[RxBuf_2[2]];
            else
            	ax = pr_gpno[RxBuf_2[2]];
            if (RxBuf_2[3]< ax) {    // function number //            
                //Data,Max,Min,Att,Def
                if ((RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
#if ACCESS_GROUP
					if (RxBuf_2[2] == MAPGOURP){
                		umap_addr.ub.hi = pr[UMAP_ADD0+RxBuf_2[3]] / 100;
                		umap_addr.ub.low = pr[UMAP_ADD0+RxBuf_2[3]] - umap_addr.ub.hi * 100;
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
                		    if ( (DispAttr[(umap_addr.ub.low+C21MAX-1)].ati&JMP)==JMP && SHOW_ALLPR==0 ){ //[solve the problem about access c22xx, Bernie, 2016/02/01]  // Modify by DINO, 09/08/2008
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
	                    ax = (UWORD)prtab[RxBuf_2[2]]+RxBuf_2[3]; // pr index //                                

#if ACCESS_GROUP
					// [ Velocity Unit Change, Add by DINO, 05/25/2009
					ubCHGFlag = 0;
					// ]

					if ( umap_addr.ub.hi==21 ){
                        //Update_C21xx();
                        ax = umap_addr.ub.low;             //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        RxBuf_2[2] = RxBuf_2[5]<<1;           // word->byte data_count
                        TxCntTemp = 2;
                        bx = RxBuf_2[5];                    // data count //
                        //Data Content
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = ((UWORD)C21xx[ax] & 0x00ff);
                        //Data Max
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0xff;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0xff;
                        //Data Min
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        //Data attribute
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = DispAttr[ax].ati>>8;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = DispAttr[ax].ati&0x00ff;
                        //Data default
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        //Data Description
                        ax = umap_addr.ub.low;                  //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        ShowDescription(c21info[ax]);
						// [ Velocity Unit Change, Add by DINO, 05/25/2009
						if ((DispAttr[ax].ati&CHG) == CHG){
							ubCHGFlag = 1;
                        }
                        // ]
					}
					else if ( umap_addr.ub.hi==22 ){
					    ax = umap_addr.ub.low;                   //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        //Update_C21xx();
                        RxBuf_2[2] = RxBuf_2[5]<<1;           // word->byte data_count
                        TxCntTemp = 2;
                        bx = RxBuf_2[5];                    // data count //
                        //Data Content
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = ((UWORD)C22xx[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = ((UWORD)C22xx[ax] & 0x00ff);
                        //Data Max
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0xff;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0xff;
                        //Data Min
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        //Data attribute
                        TxCntTemp++;
                        //RxBuf_2[TxCntTemp] = DispAttr[(ax+C21MAX)].ati>>8;
                        RxBuf_2[TxCntTemp] = DispAttr_c22xx[(ax)].ati>>8;     //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        TxCntTemp++;
                        //RxBuf_2[TxCntTemp] = DispAttr[(ax+C21MAX)].ati&0x00ff;
                        RxBuf_2[TxCntTemp] = DispAttr_c22xx[(ax)].ati&0x00ff;  //[solve the problem about access c22xx, Bernie, 2016/02/01]
                        //Data default
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = 0x00;
                        //Data Description
                        ax = umap_addr.ub.low;      //[solve the problem about access c22xx, Bernie, 2016/02/01]

                        ShowDescription(c22info[ax]);
					}
#endif
					else{
                        bx = RxBuf_2[5];
                        TxCntTemp = 2;
                        RxBuf_2[2] = RxBuf_2[5]<<1;
                        TxCntTemp++;
                        // [ Velocity Unit Change, Add by DINO, 05/25/2009
                        uwEEPData.uw = GetParData(ax);
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
						// ]

						uwEEPData.uw = GetParMax(ax);
						TxCntTemp++;
						RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
						TxCntTemp++;
						RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
						
						uwEEPData.uw = GetParMin(ax);
						TxCntTemp++;
						RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
						TxCntTemp++;
						RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
#if DINO  // 10/19/2007
						uwEEPData.uw = GetParAttr(ax);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
#else
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
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
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.hi;
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = uwEEPData.ub.low;
                        
                        //Data Description
                        //ShowDescription(prinfo[ax]);
                        // Add Russian and Turkish Text, Jason, 2020/08/03
                        if ((C20xx[0x05]&0xff00) == 0x0400){// Add RUS and TUR Text, Jason, 2020/07/22
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                #if Language_TR
                                ShowDescription(prinfo_tur[ax]);
                                #else
                                ShowDescription(prinfo[ax]);
                                #endif
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
                        else if ((C20xx[0x05]&0xff00) == 0x0800){
                            if((ax < DLC_PR) || (ax >= GROUP5) || (pr[FLOOR_PAGE]==0)){
                                #if Language_RUS
                                ShowDescription(prinfo_rus[ax]);
                                #else
                                ShowDescription(prinfo[ax]);
                                #endif
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
                        else if ((C20xx[0x05]&0xff00) == 0x0200){
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
						//if ((attr[ax].ati&CHG) == CHG){
							//ubCHGFlag = 1;
						//}
                        if((pr[SOFC]<=3) && (pr[UNITSEL]<3)){         //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]//[Sibocom S curve, ACC unit,Jason,2019/10/01]
                            if ((attr[ax].ati&CHG) == CHG){
  	                            ubCHGFlag = 1;
                            }
                        }
                        else{                                         //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
                            if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(pr[UNITSEL]==3)){  //unit change
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
						// ]
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
                        RxBuf_2[TxCntTemp] = (UBYTE)(Descript[ax]>>8);
                        TxCntTemp++;
                        RxBuf_2[TxCntTemp] = (UBYTE)Descript[ax];
                        ax++;
                    }while(ax < DESMAX);
                    TxCntTemp = (bx<<1) + 2;
                }
                else
                    COM2Err = PC_CE03;
            }          
            else  //Function number error
                COM2Err = PC_CE02;
        }
        else //group number error
            COM2Err = PC_CE02;
    }
    Init_TxData_2(TxCntTemp);
}

void RemoteCmd10_2(void)
{
        /* rxbuf[0]=adrr; rxbuf[1]=cmd_code;rxbuf[2]=gp_n0; rxbuf[3]=fn_no (data_addr)
           rxbuf[4]_rxbuf[5]=word_data_count; rxbuf[6,7...]=data_1, data2.....          */

        UWORD_UNION rxdata;
        UBYTE ax,bx,TxCntTemp = 0; 
        UWORD rinx, MaxTemp, MinTemp;

        if (RxBuf_2[2]==0x20){            // Communication Memory Address 20xxH
          ax = RxBuf_2[3];
          if ((C20MAX>=(ax+RxBuf_2[5]))&&(RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
            bx=RxBuf_2[5];
            TxCntTemp=7;
            do {
              rxdata.ub.hi=RxBuf_2[TxCntTemp];
              rxdata.ub.low=RxBuf_2[TxCntTemp+1];
              Keypad_20xxH(ax,rxdata.uw);              
              TxCntTemp += 2;
              ax++;
              bx--;
            } while (bx!=0);
          }
          else
            COM2Err=PC_CE03;   // Illegal uw count //
        }
			else if (RxBuf_2[2]==0x21)
				COM2Err=PC_CE04;                    // read only
			else {

				if (SHOW_ENHANCE==1)
					ax = GRENHANCE;
			 	else
					ax = GRUSER;

          if (PRLOCK==1 || FSET_LOCK==1)
            ax = GRALL;
          if (RxBuf_2[2]<=ax) {    // group NO.
            // get the no of pr 	
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            	bx = pr_gpno_Sibo[RxBuf_2[2]];
            else
            	bx = pr_gpno[RxBuf_2[2]];
      		

            if ((RxBuf_2[3]+RxBuf_2[5])<=bx) {  // function NO.
              ax = RxBuf_2[3];
              if ((RxBuf_2[5]!=0)&&(RxBuf_2[5]<=DATA_LEN)&&(RxBuf_2[4]==0)){
                if ((PUON2LINE==1)||(RxBuf_2[0]==0xFF))
                    KEYPAD_CMD = 1;                
                else
                    KEYPAD_CMD = 0;             
                bx=RxBuf_2[5];
                TxCntTemp=7;
                do {
                  rinx=prtab[RxBuf_2[2]]+ax;  // pr index
                  rxdata.ub.hi=RxBuf_2[TxCntTemp];
                  rxdata.ub.low=RxBuf_2[TxCntTemp+1];
                  MaxTemp = GetParMax(rinx);
                  MinTemp = GetParMin(rinx);
                  if ((rxdata.uw <= MaxTemp) && (rxdata.uw >= MinTemp))
                    write_pr(rinx,rxdata.uw);
                    if (KEYEND==ERR)
                        COM2Err = PC_CE02;
                  TxCntTemp += 2;
                  ax++;
                  bx--;
                } while (bx!=0);
                KEYPAD_CMD = 0;
              }
              else
                COM2Err=PC_CE03;   // Illegal uw count
            }
            else
              COM2Err=PC_CE02;     // Illegal function number
          }
          else
            COM2Err=PC_CE02;       // Illegal group number
        }
        Init_TxData_2(5);
}


void RemoteCmd17_2(void)     //[APP01 IO carde support, Bernie, 2013/03/20]
{
  
    UBYTE TxCntTemp;
    UWORD bx;
    UWORD ax;
    
    TxCntTemp = 2;

    /*write*/
    if ((RxBuf_2[6] == 0x02) && (RxBuf_2[7] == 0x0A)){
        ax = (UWORD)prtab[RxBuf_2[6]] + RxBuf_2[7]; // pr index //    
    
        //mfi_ExtIOnow = ((UWORD)RxBuf_1[11])<<8;
        //pr[MI_INV] = (pr[ax]&0x00FF) | bx;
    }
    else{
        COM2Err = PC_CE02;
    }
        
    /*read*/
    if ((RxBuf_2[2] == 0x09) && (RxBuf_2[3] == 0x15)){    
        ax = (UWORD)prtab[RxBuf_2[2]] + RxBuf_2[3]; // pr index //    
    
        bx = ((UWORD)RxBuf_2[4] << 8) + RxBuf_2[5];    
        if (bx == 3){
            RxBuf_2[2] = bx << 1;               //Byte Count
            /*i = 0;
            do{
                TxCntTemp++;
                RxBuf_3[TxCntTemp] = pr[ax+i] >> 8;               //Read Data Hi
                TxCntTemp++;
                RxBuf_3[TxCntTemp] = pr[ax+i] & 0x00ff;           //Read Data Lo    
                i++;
            }while(i<bx);*/

        RxBuf_2[3] = 0x03;
        RxBuf_2[4] = 0xE8;
        RxBuf_2[5] = APP01_uwSO1 >> 8;     //Read Data Hi
        RxBuf_2[6] = APP01_uwSO1 & 0x00ff;     //Read Data Lo
        RxBuf_2[7] = APP01_uwSO2 >>8;     //Read Data Hi
        RxBuf_2[8] = APP01_uwSO2 & 0x00ff;     //Read Data Lo


            
        }
        else{
            COM2Err = PC_CE03;
        }
    }
    else{
        COM2Err = PC_CE02;
    }

    Init_TxData_2(8);
}
// move to here by dino, 03/08/2007
void PC_CEError(UBYTE CeErr)
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

#ifdef _SCI3_Remote_C
	#undef _SCI3_Remote_C
#endif

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
