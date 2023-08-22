/***********************************************************************/
/*                                                                     */
/*  FILE        :RCAN_ET.c                                             */
/*  DATE        :Tur, Jun 21, 2007                                     */
/*  DESCRIPTION :Hardware Setup file                                   */
/*  CPU TYPE    :SH7147                                                */
/*                                                                     */
/***********************************************************************/
#ifndef  _RCAN_ET_C
    #define  _RCAN_ET_C
#endif

#include "ProgHeader.h"

void CAN_ICT_TX(void){

 UWORD wait;

    RCAN_ubICTCnt++;

    //CAN1.MCTL[0].BYTE = 0x80;
    CAN1.MB[0].DATA[0] = pr[MO_INV];
    if(RCAN_ubICTCnt > 1000){
        CAN1.MB[0].DATA[3] = 0x04;
        if(RCAN_ubICTCnt > 2000)
            RCAN_ubICTCnt = 0;
    }
    else{
         CAN1.MB[0].DATA[3] = 0x02;
    }

    
    //CAN1.MB[0].DATA[0] = 0x8A;
    CAN1.MB[0].DATA[1] = 0x00;
    CAN1.MB[0].DATA[2] = 0x00;
   
    CAN1.MB[0].DATA[4] = 0x05;
    CAN1.MB[0].DATA[5] = 0x00;
    CAN1.MB[0].DATA[6] = 0x00;
    CAN1.MB[0].DATA[7] = 0x00;

	


    //CAN1.MCTL[0].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[0].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[0].BIT.TX.TRMREQ = 1;         //[CAN bus problem, Bernie, 2016/10/28]
  //}

    CAN1.MCTL[2].BYTE = 0x80;
      
      
    CAN1.MB[2].DATA[0] = 0x8A;
    CAN1.MB[2].DATA[1] = 0x00;
    CAN1.MB[2].DATA[2] = 0x00;
    CAN1.MB[2].DATA[3] = 0x00;
    CAN1.MB[2].DATA[4] = 0x00;
    CAN1.MB[2].DATA[5] = 0x00;
    CAN1.MB[2].DATA[6] = 0x00;
    CAN1.MB[2].DATA[7] = 0x00;
  
  
    //CAN1.MCTL[2].BIT.TX.TRMREQ = 0;
    //nop();
    //CAN1.MCTL[2].BIT.TX.SENTDATA = 0;
  
    CAN1.MCTL[2].BIT.TX.TRMREQ = 1;      //[CAN bus problem, Bernie, 2016/10/28]

      
    CAN1.MCTL[4].BYTE = 0x80;
          

    CAN1.MB[4].DATA[0] = 0x8A;
    CAN1.MB[4].DATA[1] = 0x00;
    CAN1.MB[4].DATA[2] = 0x00;
    CAN1.MB[4].DATA[3] = 0x00;
    CAN1.MB[4].DATA[4] = 0x00;
    CAN1.MB[4].DATA[5] = 0x00;
    CAN1.MB[4].DATA[6] = 0x00;
    CAN1.MB[4].DATA[7] = 0x00;
      
      
    //CAN1.MCTL[4].BIT.TX.TRMREQ = 0;
    //nop();
    //CAN1.MCTL[4].BIT.TX.SENTDATA = 0;
      
    CAN1.MCTL[4].BIT.TX.TRMREQ = 1;    //[CAN bus problem, Bernie, 2016/10/28]

  
}

void CAN_PDO_TX_return(void){

	//DLC_PDO_TX_InvO.uw = UnitTransfer();  //[DLC, Bernie, 2014/10/06]
	    
	CAN1.MB[0].DATA[0] = DLC_PDO_TX_INV_ST.ub.low;	//inv status
	CAN1.MB[0].DATA[1] = DLC_PDO_TX_INV_ST.ub.hi;		//inv status
	CAN1.MB[0].DATA[2] = DLC_PDO_TX_AskC.ub;				//ask command
	CAN1.MB[0].DATA[3] = DLC_PDO_TX_ALF;						//accepted landing floor
	CAN1.MB[0].DATA[4] = DLC_PDO_TX_LTF;						//target floor
	CAN1.MB[0].DATA[5] = DLC_ubLevCur;								//current floor
	CAN1.MB[0].DATA[6] = DLC_PDO_TX_INV_SPD.ub.low;	//speed
	CAN1.MB[0].DATA[7] = DLC_PDO_TX_INV_SPD.ub.hi;	//speed

	//CAN1.MCTL[0].BIT.TX.TRMREQ = 0;         
	//CAN1.MCTL[0].BIT.TX.SENTDATA = 0;
	CAN1.MCTL[0].BIT.TX.TRMREQ = 1;           //[CAN bus problem, Bernie, 2016/10/28]

   //[Gfc DLC modify,Henry,2018/05/23]
	CAN1.MB[8].DATA[0] = DLC_PDO_ID004_B0.ub;
	CAN1.MB[8].DATA[1] = DLC_PDO_ID004_B1.ub;
	CAN1.MB[8].DATA[2] = DLC_PDO_ID004_B2.ub;
	CAN1.MB[8].DATA[3] = DLC_PDO_ID004_B3.ub;
	CAN1.MB[8].DATA[4] = DLC_PDO_ID004_B4.ub;
	CAN1.MB[8].DATA[5] = DLC_PDO_ID004_B5.ub;
	CAN1.MB[8].DATA[6] = DLC_PDO_ID004_B6.ub;
	CAN1.MB[8].DATA[7] = DLC_PDO_ID004_B7.ub;
	CAN1.MCTL[8].BIT.TX.TRMREQ = 1;
//#if Artemis_ENABLE
    //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]
    if(btArtemisEnable)
    {
        if(DLC_btPDO_ID005_Enable)
        {
        	//Artemis DLC modify , James, 2020/06/02
        	CAN1.MB[10].DATA[0] = DLC_PDO_ID005_B0.ub;
        	CAN1.MB[10].DATA[1] = DLC_PDO_ID005_B1.ub;
        	CAN1.MB[10].DATA[2] = DLC_PDO_ID005_B2.ub;
        	CAN1.MB[10].DATA[3] = DLC_PDO_ID005_B3.ub;
        	CAN1.MB[10].DATA[4] = DLC_PDO_ID005_B4.ub;
        	CAN1.MB[10].DATA[5] = DLC_PDO_ID005_B5.ub;
        	CAN1.MB[10].DATA[6] = DLC_PDO_ID005_B6.ub;
        	CAN1.MB[10].DATA[7] = DLC_PDO_ID005_B7.ub;
        	CAN1.MCTL[10].BIT.TX.TRMREQ = 1;
        }
     }
//#endif
} 

void CAN_RX(void){
  UWORD wait;
  UBYTE i;

    if(pr[DEBUG_F1]==0x0002){           //for ICT or T1/T2
        if(CAN1.MCTL[1].BIT.RX.NEWDATA){     // If message received, tell user.
            CAN_MB_Receive(MBOX1);
            RCAN_uwstatus = RCAN_MB1[0];     //[Modify for CAN function, Bernie, 2014/09/26]
        }
    }
    else{

        if(CAN1.MCTL[MBOX1].BIT.RX.NEWDATA){   // If message received, tell user.
           
            CAN_MB_Receive(MBOX1);
            
            //CAN1.MCTL[MBOX1].BIT.RX.NEWDATA = 0;

            if(CAN_RX1_OK == 1)            //PDO data receive
                CAN_PDO_RX_Data();

            CAN_RX1_OK = 0;

        }
        if(CAN1.MCTL[MBOX3].BIT.RX.NEWDATA){   // If message received, tell user.
            CAN_MB_Receive(MBOX3);

            DLC_SDO_RX_Command = RCAN_MB3[0];  
            DLC_SDO_RX_Lenght = RCAN_MB3[1];
            DLC_SDO_RX_Address_H = RCAN_MB3[2];
            DLC_SDO_RX_Address_L = RCAN_MB3[3];
            DLC_SDO_RX_Data0 = ((UWORD)RCAN_MB3[4]<<8)+RCAN_MB3[5];
            //CAN1.MCTL[MBOX3].BIT.RX.NEWDATA = 0;
        }
        if(CAN1.MCTL[MBOX5].BIT.RX.NEWDATA){    // If message received, tell user.
           
            CAN_MB_Receive(MBOX5);

          //CAN1.MCTL[MBOX5].BIT.RX.NEWDATA = 0;
        }
        if(CAN1.MCTL[MBOX7].BIT.RX.NEWDATA){    // If message received, tell user.
           
            CAN_MB_Receive(MBOX7);

           //CAN1.MCTL[MBOX7].BIT.RX.NEWDATA = 0;
        }
    }
}


void CAN_MB_Receive(UBYTE MBOX){
    UBYTE i;

    CAN_WaitRx(MBOX);
        
    
    CAN1.MCTL[MBOX].BIT.RX.NEWDATA = 0;    //Clear reception complete flag to 0
    uwPDO_CNT = 0;
	uwPDOInCnt++;//Aevin add--6/14/2017

    if(CAN1.MCTL[MBOX].BIT.RX.MSGLOST){ 
        CAN1.MCTL[MBOX].BIT.RX.MSGLOST = 0;
        CAN_uwErrNo = 0x08;
        Error = CAN_ERR;
        RCAN_ubErr4Rgst = CAN1.EIFR.BYTE;
    }   

    switch(MBOX){
        case MBOX1:
            for(i = 0; i<8 ;i++){
                RCAN_MB1[i] = CAN1.MB[MBOX1].DATA[i];
            }
            CAN_RX1_OK = 1;
            break;
        case MBOX3:
            for(i = 0; i<8 ;i++){
                RCAN_MB3[i] = CAN1.MB[MBOX3].DATA[i];
            }
            CAN_RX3_OK = 1;
            break;
        case MBOX5:
            for(i = 0; i<8 ;i++){
                RCAN_MB5[i] = CAN1.MB[MBOX5].DATA[i];
            }
            CAN_RX5_OK = 1;
            break;
        case MBOX7:
            for(i = 0; i<8 ;i++){
                RCAN_MB7[i] = CAN1.MB[MBOX7].DATA[i];
            }
            CAN_RX7_OK = 1;
            break;
        default:
            break;
    }

    CAN1.MCTL[MBOX].BIT.RX.NEWDATA = 0;   // Set NEWDATA bit to 0 since the mailbox was just emptied and start over with new RxPolls.

}

void CAN_SDO_RX_Decode(void){


    if(CAN_RX3_OK == 1){
        
        switch(DLC_SDO_RX_Command){
            case READ_INVERTER:
                CAN_SDO_READ_DATA();
            break;
            case WRITE_INVERTER:
                CAN_SDO_WRITE_DATA();
            break; 
            case READ_ATTRIBUTION:
                CAN_SDO_READ_Attribution();
            break;
            case READ_DESCRIPTION:
                CAN_SDO_READ_Description();
            break;
        }
      
    }
   
    
}

void CAN_PDO_RX_Data(void){
	UBYTE 		ubDILow,ubDIHi;
	UWORD 		ax, uwspeed;
	ULONG_UNION	ultmp;
	
	DLC_PDO_RX_EM.ub.low = RCAN_MB1[0];
	DLC_PDO_RX_EM.ub.hi = RCAN_MB1[1]; 
	
	DLC_PDO_RX_DI.ub.low = RCAN_MB1[2];
	DLC_PDO_RX_DI.ub.hi = RCAN_MB1[3];
	DLC_PDO_RX_RC.ub = RCAN_MB1[4];
	DLC_PDO_RX_TF = RCAN_MB1[5];

    // GFC APS Jerry.Sk.Tseng 2022/12/23
    if(DLC_PDO_RX_RC.ub & 0x80) //check Byte4 Bit 7
    {
        if(pr[CAN_FUN] & 0x04)  // Check bit 2
        {
            ultmp.ub.b3 = 0;
            ultmp.ub.b2 = RCAN_MB1[5];
            ultmp.ub.b1 = RCAN_MB1[6];  
            ultmp.ub.b0 = RCAN_MB1[7]; 
			ulDLC_PDO_RX_APS_ClipPu = ultmp.ul;	// GFC1test
        }
        else
        {
            ultmp.ub.b3 = 0;
            ultmp.ub.b2 = RCAN_MB1[5];
            ultmp.ub.b1 = RCAN_MB1[6];  
            ultmp.ub.b0 = RCAN_MB1[7];
			ulDLC_PDO_RX_APS_Pu = ultmp.ul;	// GFC1test
        }        
    }else
    {
        DLC_PDO_RX_TF = RCAN_MB1[5];
    }
    
	if(DLC_ubDecel==0){  //20180612 //[Gfc DLC modify,Henry,2018/05/23]
		if((DLC_ubDIR == DIR_NULL) &&
			 (DLC_PDO_RX_TF <= DLC_ubLevMax) &&  // DLC function, Henry, 2016/07/20
			 (DLC_PDO_RX_TF >= DLC_ubLevMin))    // DLC function, Henry, 2016/07/20
			DLC_ubLevTar = DLC_PDO_RX_TF;
		else if((DLC_ubDIR == DIR_UP) && (DLC_PDO_RX_TF >= DLC_ubLevOk) && 
			      (DLC_PDO_RX_TF <= DLC_ubLevMax))  // DLC function, Henry, 2016/07/20
			DLC_ubLevTar = DLC_PDO_RX_TF;
		else if((DLC_ubDIR == DIR_DN) && (DLC_PDO_RX_TF <= DLC_ubLevOk) &&
			      (DLC_PDO_RX_TF >= DLC_ubLevMin))  // DLC function, Henry, 2016/07/20
			DLC_ubLevTar = DLC_PDO_RX_TF;
	}
	else
		DLC_ubLevTar = DLC_ubLevTar; //[Gfc DLC modify,Henry,2018/05/23]
}



void CAN_WaitRx(UBYTE MB_No){
UWORD wait;   

    wait = 0;
    while ((CAN1.MCTL[MB_No].BIT.RX.INVALDATA)){
        wait++;
        if(wait==65535){
            CAN_uwErrNo = 0x07;
            Error = CAN_ERR;
            RCAN_ubErr4Rgst = CAN1.EIFR.BYTE;
            break;
        }
    }
}

UWORD UnitTransfer(void){     //[DLC, Bernie, 2014/10/06]
    UWORD uwTemp;
    
    uwTemp = uwAbsMotorHz;

    if (pr[UNITSEL] == 1){		// Hz->m/s
        uwTemp = flHz2Metric(uwTemp);
    }
    else if(pr[UNITSEL] == 2){	// Hz->ft/s
        uwTemp = Hz2Ft(uwTemp);
    }
    else if(pr[UNITSEL] == 3){  // Hz->mm/s
        uwTemp = flHz2Metric(uwTemp);
        uwTemp *= 100;
    }
    return uwTemp;
}




void CAN_SDO_READ_DATA(void){
    
  UWORD uw_ADDRESS;
  UWORD ax,bx;
  UBYTE i;
  UWORD_UNION  umap_addr, rxdata;
  
    uw_ADDRESS =  (DLC_SDO_RX_Address_H << 8) + DLC_SDO_RX_Address_L;

    //normal parametr group 0~15
    if(DLC_SDO_RX_Address_H < 0x16){   
        if(SHOW_ALLPR == 1)
            bx = GRALL;
        else{
            if(SHOW_ENHANCE == 1)
                bx = GRENHANCE;
            else
                bx = GRUSER;          
        }
        if(DLC_SDO_RX_Address_H <= bx){  // Group number //       
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                ax = pr_gpno_Sibo[DLC_SDO_RX_Address_H];
            else
                ax = pr_gpno[DLC_SDO_RX_Address_H];
            
            //DLC function, Henry, 2016/07/20
            // function number //
            if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght)<= ax)
            {           
            		//DLC function, Henry, 2016/07/20
                bx = (UWORD)prtab[DLC_SDO_RX_Address_H] + DLC_SDO_RX_Address_L; 
                
                //Read data
                for(i=0; i<(DLC_SDO_RX_Lenght); i++)
                {                
                    RCAN_SDO_RX_MB[i] = pr[bx+i] ;                        
                }
                CAN_SDO_READ_ACCESS();
            }
            else
            {
                KEYEND = ERR;
                CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
            }
        }
        else{
            KEYEND = ERR;
            CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
        }           
    }
  	else if(DLC_SDO_RX_Address_H==0x16){ //read DLCxx
	     if(DLC_SDO_RX_Lenght==1)
		 {
			bx = DLC_SDO_RX_Address_L; 
			if(bx<0x96)
			{
	        	if(bx<0x32)
				{
		          	RCAN_SDO_RX_MB[0] = DLCxx[DLC_LimADDR+bx];
		          	uwtest21++;
	          	}
	          	else if((bx>=0x32)&&(bx<0x64)) 
				{
		          	RCAN_SDO_RX_MB[0] = DLCxx[bx-0x32+DLC_Adj50ADDRUP];
		          	uwtest21++;
	          	}
	          	else if((bx>=0x64)&&(bx<0x96)) 
				{
		          	RCAN_SDO_RX_MB[0] = DLCxx[bx-0x64+DLC_Adj50ADDRDN];
		          	uwtest21++;
				}				
	         	uwtest20 = RCAN_SDO_RX_MB[0];
	       		CAN_SDO_READ_ACCESS();
			}
			else
			{
				KEYEND = ERR;
				CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
			}
	    }
	    else
		{
	    	KEYEND = ERR;
	    	CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
	    }
 	 }

    else if(DLC_SDO_RX_Address_H == 0x40){
        if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght) <= C40MAX){
               
                for(i=0; i<(DLC_SDO_RX_Lenght); i++){                //Read data
                    RCAN_SDO_RX_MB[i] = C40xx[DLC_SDO_RX_Address_L+i] ;
                }

                CAN_SDO_READ_ACCESS();
   
        }   
        else{
            CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
        }
        
    }

    //[C21xx function can be read, Bernie, 2015/04/27]
    else if(DLC_SDO_RX_Address_H == 0x21){
            if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght) <= C21MAX){
               
                for(i=0; i<(DLC_SDO_RX_Lenght); i++){                //Read data
                    RCAN_SDO_RX_MB[i] = C21xx[DLC_SDO_RX_Address_L+i] ;
                }

                CAN_SDO_READ_ACCESS();
   
            }   
            else{
                CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
            }
       
    }
    else if(DLC_SDO_RX_Address_H == 0x22){  //[C22xx function can be read, Bernie, 2017/05/23]
        if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght) <= C22MAX){
               
            for(i=0; i<(DLC_SDO_RX_Lenght); i++){                //Read data
                RCAN_SDO_RX_MB[i] = C22xx[DLC_SDO_RX_Address_L+i] ;
            }

            CAN_SDO_READ_ACCESS();
   
        }   
        else{
            CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
        }
       
    }
    else{
        CAN_ERROR_Return(READ_EXCEPTION,ADDR_UNDEFINED);
    }
    
}

void CAN_SDO_Return(UBYTE Fun, UBYTE MB_NUMBER)
{
    switch(MB_NUMBER){
        
        case MBOX2:
            CAN1.MB[2].DATA[0]= Fun;
            CAN1.MB[2].DATA[1]= DLC_SDO_RX_Lenght;
            CAN1.MB[2].DATA[2]= DLC_SDO_RX_Address_H;
            CAN1.MB[2].DATA[3]= DLC_SDO_RX_Address_L;
            CAN1.MB[2].DATA[4]= (UBYTE)((RCAN_SDO_RX_MB[0]&0xFF00)>>8);
            CAN1.MB[2].DATA[5]= (UBYTE)((RCAN_SDO_RX_MB[0]&0x00FF));
            CAN1.MB[2].DATA[6]= (UBYTE)((RCAN_SDO_RX_MB[1]&0xFF00)>>8);
            CAN1.MB[2].DATA[7]= (UBYTE)((RCAN_SDO_RX_MB[1]&0x00FF));
            break;
            
        case MBOX4: 
            CAN1.MB[4].DATA[0]= (UBYTE)((RCAN_SDO_RX_MB[2]&0xFF00)>>8);
            CAN1.MB[4].DATA[1]= (UBYTE)((RCAN_SDO_RX_MB[2]&0x00FF));
            CAN1.MB[4].DATA[2]= (UBYTE)((RCAN_SDO_RX_MB[3]&0xFF00)>>8);
            CAN1.MB[4].DATA[3]= (UBYTE)((RCAN_SDO_RX_MB[3]&0x00FF));
            CAN1.MB[4].DATA[4]= (UBYTE)((RCAN_SDO_RX_MB[4]&0xFF00)>>8);
            CAN1.MB[4].DATA[5]= (UBYTE)((RCAN_SDO_RX_MB[4]&0x00FF));
            CAN1.MB[4].DATA[6]= (UBYTE)((RCAN_SDO_RX_MB[5]&0xFF00)>>8);
            CAN1.MB[4].DATA[7]= (UBYTE)((RCAN_SDO_RX_MB[5]&0x00FF));
            break;

        case MBOX6: 
            CAN1.MB[6].DATA[0]= (UBYTE)((RCAN_SDO_RX_MB[6]&0xFF00)>>8);
            CAN1.MB[6].DATA[1]= (UBYTE)((RCAN_SDO_RX_MB[6]&0x00FF));
            CAN1.MB[6].DATA[2]= (UBYTE)((RCAN_SDO_RX_MB[7]&0xFF00)>>8);
            CAN1.MB[6].DATA[3]= (UBYTE)((RCAN_SDO_RX_MB[7]&0x00FF));
            CAN1.MB[6].DATA[4]= (UBYTE)((RCAN_SDO_RX_MB[8]&0xFF00)>>8);
            CAN1.MB[6].DATA[5]= (UBYTE)((RCAN_SDO_RX_MB[8]&0x00FF));
            CAN1.MB[6].DATA[6]= (UBYTE)((RCAN_SDO_RX_MB[9]&0xFF00)>>8);
            CAN1.MB[6].DATA[7]= (UBYTE)((RCAN_SDO_RX_MB[9]&0x00FF));
            break;
    }



    //CAN1.MCTL[MB_NUMBER].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[MB_NUMBER].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[MB_NUMBER].BIT.TX.TRMREQ = 1;           //[CAN bus problem, Bernie, 2016/10/28]
}

void CAN_SDO_READ_ACCESS(void){

  UBYTE i;  

    if(DLC_SDO_RX_Lenght <= SDO_FRAME1)
    {
        KEYEND = END;
        CAN_SDO_Return(READ_INVERTER, MBOX2);    //Frame one
        
        for(i=0; i<SDO_FRAME1; i++){
            RCAN_SDO_RX_MB[i] = 0;
        }
        CAN_RX3_OK = 0; 
    }
    else if(DLC_SDO_RX_Lenght > SDO_FRAME1 && DLC_SDO_RX_Lenght <= SDO_FRAME2)
    {
        KEYEND = END;
        CAN_SDO_Return(READ_INVERTER, MBOX2);    //Frame one
        CAN_SDO_Return(READ_INVERTER, MBOX4);    //Frame two
        for(i=0; i<SDO_FRAME2; i++){
            RCAN_SDO_RX_MB[i] = 0;
        }
        CAN_RX3_OK = 0; 
        CAN_RX5_OK = 0; 
    }
    else
    {
        KEYEND = END;
        CAN_SDO_Return(READ_INVERTER, MBOX2);    //Frame one
        CAN_SDO_Return(READ_INVERTER, MBOX4);    //Frame two
        CAN_SDO_Return(READ_INVERTER, MBOX6);    //Frame three
         for(i=0; i<SDO_FRAME3; i++){
            RCAN_SDO_RX_MB[i] = 0;
        } 
        CAN_RX3_OK = 0; 
        CAN_RX5_OK = 0; 
        CAN_RX7_OK = 0; 
    }
    
}

void CAN_ERROR_Return(UBYTE STATUS,UWORD ERROR_CODE){

    CAN_RX3_OK = 0; 
    CAN_RX5_OK = 0; 
    CAN_RX7_OK = 0; 
    
    CAN1.MB[2].DATA[0]= STATUS;
    if((STATUS & 0x80) == 0x80)
    {
        CAN1.MB[2].DATA[1]= 0x01;
    }
    else
    {
        CAN1.MB[2].DATA[1]= DLC_SDO_RX_Lenght;
    }
    
    //DLC function, Henry, 2016/07/20
    CAN1.MB[2].DATA[2]= DLC_SDO_RX_Address_H;
    CAN1.MB[2].DATA[3]= DLC_SDO_RX_Address_L;
    CAN1.MB[2].DATA[4]= (ERROR_CODE&0xFF00)>>8;
    CAN1.MB[2].DATA[5]= (ERROR_CODE&0x00ff);
    CAN1.MB[2].DATA[6]= 0x00;
    CAN1.MB[2].DATA[7]= 0x00;

    //CAN1.MCTL[MBOX2].BIT.TX.TRMREQ = 0;
	//  nop();
	//  CAN1.MCTL[MBOX2].BIT.TX.SENTDATA = 0;
    CAN1.MCTL[MBOX2].BIT.TX.TRMREQ = 1;                 //[CAN bus problem, Bernie, 2016/10/28]

    
}


void CAN_SDO_WRITE_DATA(void){
  UBYTE i,  Function, ubPageTemp;
  UWORD ax, bx, cx,Errcode;
  UWORD uwMaxTemp, uwMinTemp, uw_ADDRESS, uwCanData;
  UWORD uw_ADDRESSMax;

      uw_ADDRESS = (DLC_SDO_RX_Address_H << 8) + DLC_SDO_RX_Address_L;
      CAN_SDO_WRITE_ACCESS();
      
      //normal parametr group 0~15
      if(DLC_SDO_RX_Address_H < 0x16)
      {   
          if(SHOW_ALLPR == 1)
              bx = GRALL;
          else
          {
              if(SHOW_ENHANCE == 1)
                  bx = GRENHANCE;
              else
                  bx = GRUSER;          
          }

          if(DLC_SDO_RX_Address_H <= bx)
          {   
              if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
              cx = pr_gpno_Sibo[DLC_SDO_RX_Address_H];                              
              else
              cx = pr_gpno[DLC_SDO_RX_Address_H];                              
            	//DLC function, Henry, 2016/07/20
              if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght)<= cx)
              {
                  for(i=0; i<DLC_SDO_RX_Lenght; i++)
                  {  
                      //uwCanData = (ubCanHC_Rx_H[i] << 8) + ubCanHC_Rx_L[i];
                      uwCanData = RCAN_SDO_WRITE_MB[i];
                      
                      //DLC function, Henry, 2016/07/20
                      ax = (UWORD)prtab[DLC_SDO_RX_Address_H] + DLC_SDO_RX_Address_L + i;
                      uwMaxTemp = GetParMax(ax);
                      uwMinTemp = GetParMin(ax);
    
                      if ((attr[ax].ati&SIGN) != 0)
                      {
                          if (((SWORD)uwCanData<=(SWORD)uwMaxTemp)&&((SWORD)uwCanData>=(SWORD)uwMinTemp))
                          {
                              write_pr(ax,uwCanData);
                              Errcode = (UWORD)((UWORD)RCAN_SDO_WRITE_MB[1]<<8) + RCAN_SDO_WRITE_MB[0];   //[DLC, Bernie, 2015/01/22]
                              Function = WRITE_INVERTER;
                          }
                          else 
                          { 
                              Errcode = ADDR_UNDEFINED; 
                              Function = WRITE_EXCEPTION;
                          }                    
                      }
                      else
                      {    
                          if ((uwCanData<=uwMaxTemp)&&(uwCanData>=uwMinTemp))
                          {
                              write_pr(ax,uwCanData);
                              Errcode = (UWORD)((UWORD)RCAN_SDO_WRITE_MB[1]<<8) + RCAN_SDO_WRITE_MB[0];   //[DLC, Bernie, 2015/01/22]
                              Function = WRITE_INVERTER;
															
															//DLC function, Henry, 2016/07/20
															pr[ax] = uwCanData;
			                    }
                          else{   
                              Errcode = ADDR_UNDEFINED;
                              Function = WRITE_EXCEPTION;
                          }                   
                      }
                      if(Function == WRITE_EXCEPTION){       //[DLC, Bernie, 2015/01/22]
                            CAN_ERROR_Return(Function,Errcode);
                      }
                  
                  }
              }
              else{
                 KEYEND = ERR;
                 CAN_ERROR_Return(WRITE_EXCEPTION,ADDR_UNDEFINED);
              }
              if((DLC_SDO_RX_Lenght <= SDO_FRAME1) && (CAN_RX3_OK == 1)){
                  //KEYEND = END;
                  //CAN_RX3_OK = 0;
                  CAN_ERROR_Return(Function,Errcode);
              }
              else if(DLC_SDO_RX_Lenght <= SDO_FRAME2 && CAN_RX5_OK == 1){
                  //KEYEND = END;
                  CAN_ERROR_Return(Function,Errcode);
                  //CAN_RX3_OK = 0; 
                  //CAN_RX5_OK = 0;
              }
              else if(DLC_SDO_RX_Lenght <= SDO_FRAME3 && CAN_RX7_OK == 1){
                  //KEYEND = END;
                  CAN_ERROR_Return(Function,Errcode);
                  //CAN_RX3_OK = 0; 
                  //CAN_RX5_OK = 0;
                  //CAN_RX7_OK = 0;
              }
          }
          else
          {
              KEYEND = ERR;
              //Errcode = 0x01;  
              CAN_ERROR_Return(WRITE_EXCEPTION,ADDR_UNDEFINED);
          } 

      }
    	else if(DLC_SDO_RX_Address_H==0x16){ 
    		uwtest21 ++;
	      if(DLC_SDO_RX_Lenght==1){
	      	uwCanData = RCAN_SDO_WRITE_MB[0];
	      	ax = DLC_SDO_RX_Address_L;
			ubPageTemp = pr[FLOOR_PAGE];//Save Page
			if(ax<0x96)
			{
		      	if(ax<0x32)
				{
		      		//pr[FLOOR_PAGE] = 4; //replace to P04_49 for changing Attribution					
					P04_49(FLOOR_PAGE, 4);
		      		cx = FL_POSIT_1H+DLC_SDO_RX_Address_L;
		      	}			
				else if((ax>=0x32)&&(ax<0x64)) 
				{
		      		//pr[FLOOR_PAGE] = 5;					
					P04_49(FLOOR_PAGE, 5);
		      		cx = DLC_SDO_RX_Address_L-0x32+FL_POSIT_1H;
				}
				else if((ax>=0x64)&&(ax<0x96)) 
				{
		      		//pr[FLOOR_PAGE] = 6;					
					P04_49(FLOOR_PAGE, 6);
		      		cx = DLC_SDO_RX_Address_L-0x64+FL_POSIT_1H;
		      	}
		      	P04_50(cx, uwCanData);
				P04_49(FLOOR_PAGE, ubPageTemp);//0x16xx doesn't change Page for Artemis, James, 2021/02/23
	      	}
	      	else
		  	{
		  		KEYEND=ERR;
		  	}
	     	if(KEYEND==ERR){
	          	Errcode = OVERFLOW; 
	            Function = WRITE_EXCEPTION;
	     		CAN_ERROR_Return(Function,Errcode);
	     	}
	     	else{
	            Errcode = (UWORD)((UWORD)RCAN_SDO_WRITE_MB[1]<<8) + RCAN_SDO_WRITE_MB[0];   //[DLC, Bernie, 2015/01/22]
	            Function = WRITE_INVERTER;
	     		CAN_ERROR_Return(Function,Errcode);
	     	}
    		}
    		else
    			CAN_ERROR_Return(Function,Errcode);
    	}
#if 0        
      else if(DLC_SDO_RX_Address_H = 0x40){
        
          uw_ADDRESSMax = DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght;
          
          if(uw_ADDRESSMax <= C40MAX){
            
                  for(i=0; i<DLC_SDO_RX_Lenght; i++){
                      if(RCAN_SDO_WRITE_MB[i]<10000){               //[DLC, Bernie, 2015/01/22]
                          //if(RCAN_SDO_WRITE_MB[i]){
                          // DLC position offset, Henry
                          //C40xx[DLC_SDO_RX_Address_L+i] = RCAN_SDO_WRITE_MB[i];    //[DLC, Bernie, 2015/01/22]
                          Errcode = (UWORD)((UWORD)DLC_SDO_RX_Address_H<<8) + DLC_SDO_RX_Address_L; //[return address, Bernie, 2015/01/22]
                          Function = WRITE_INVERTER;
                          //}
                      }
                      else{       //[DLC, Bernie, 2015/01/22]
                          //Errcode = ADDR_UNDEFINED;
                          CAN_ERROR_Return(WRITE_EXCEPTION,ADDR_UNDEFINED);
                      }
                  }
                  if((DLC_SDO_RX_Lenght <= SDO_FRAME1) && (CAN_RX3_OK == 1)){   //[DLC, Bernie, 2015/01/22]
                      //CAN_RX3_OK = 0;
                      CAN_ERROR_Return(Function,Errcode);
                  }
                  else if(DLC_SDO_RX_Lenght <= SDO_FRAME2 && CAN_RX5_OK == 1){
                  
                      CAN_ERROR_Return(Function,Errcode);
                      //CAN_RX3_OK = 0; 
                      //CAN_RX5_OK = 0;
                  }
                  else if(DLC_SDO_RX_Lenght <= SDO_FRAME3 && CAN_RX7_OK == 1){
                  
                      CAN_ERROR_Return(Function,Errcode);
                      //CAN_RX3_OK = 0; 
                      //CAN_RX5_OK = 0;
                      //CAN_RX7_OK = 0;
                  }
                  //CAN_ERROR_Return(Function,Errcode);
             
          }  
          else{
              //KEYEND = ERR;
              CAN_ERROR_Return(WRITE_EXCEPTION,ADDR_UNDEFINED);
          }
        
      }
#endif
      else{
          CAN_ERROR_Return(WRITE_EXCEPTION,ADDR_UNDEFINED);
      }
    
}

void CAN_SDO_WRITE_ACCESS(void)
{
    UBYTE i, j; 

    if(DLC_SDO_RX_Lenght <= SDO_FRAME1)
    {
        RCAN_SDO_WRITE_MB[0] = ((UWORD)RCAN_MB3[4]<<8) + RCAN_MB3[5];
        RCAN_SDO_WRITE_MB[1] = ((UWORD)RCAN_MB3[6]<<8) + RCAN_MB3[7]; 
                     
    }
    else if(DLC_SDO_RX_Lenght > SDO_FRAME1 && DLC_SDO_RX_Lenght <= SDO_FRAME2)
    {
        RCAN_SDO_WRITE_MB[0] = ((UWORD)RCAN_MB3[4]<<8)+RCAN_MB3[5];
        RCAN_SDO_WRITE_MB[1] = ((UWORD)RCAN_MB3[6]<<8)+RCAN_MB3[7];
        RCAN_SDO_WRITE_MB[2] = ((UWORD)RCAN_MB5[0]<<8)+RCAN_MB5[1];
        RCAN_SDO_WRITE_MB[3] = ((UWORD)RCAN_MB5[2]<<8)+RCAN_MB5[3];
        RCAN_SDO_WRITE_MB[4] = ((UWORD)RCAN_MB5[4]<<8)+RCAN_MB5[5];
        RCAN_SDO_WRITE_MB[5] = ((UWORD)RCAN_MB5[6]<<8)+RCAN_MB5[7];
       
    }
    else if(DLC_SDO_RX_Lenght > SDO_FRAME2 && DLC_SDO_RX_Lenght <= SDO_FRAME3)
    {    
        RCAN_SDO_WRITE_MB[0] = ((UWORD)RCAN_MB3[4]<<8)+RCAN_MB3[5];
        RCAN_SDO_WRITE_MB[1] = ((UWORD)RCAN_MB3[6]<<8)+RCAN_MB3[7];
        RCAN_SDO_WRITE_MB[2] = ((UWORD)RCAN_MB5[0]<<8)+RCAN_MB5[1];
        RCAN_SDO_WRITE_MB[3] = ((UWORD)RCAN_MB5[2]<<8)+RCAN_MB5[3];
        RCAN_SDO_WRITE_MB[4] = ((UWORD)RCAN_MB5[4]<<8)+RCAN_MB5[5];
        RCAN_SDO_WRITE_MB[5] = ((UWORD)RCAN_MB5[6]<<8)+RCAN_MB5[7];
        RCAN_SDO_WRITE_MB[6] = ((UWORD)RCAN_MB7[0]<<8)+RCAN_MB7[1];
        RCAN_SDO_WRITE_MB[7] = ((UWORD)RCAN_MB7[2]<<8)+RCAN_MB7[3];
        RCAN_SDO_WRITE_MB[8] = ((UWORD)RCAN_MB7[4]<<8)+RCAN_MB7[5];
        RCAN_SDO_WRITE_MB[9] = ((UWORD)RCAN_MB7[6]<<8)+RCAN_MB7[7];
    }
    
}

void CAN_SDO_WRITE_C40xx(void){
    
}



void CAN_SDO_READ_Attribution(void){
  UWORD uw_ADDRESS,ax,bx,uwMaxTemp,uwMinTemp;
  UWORD uw_AttrTemp,uw_Default;
  UBYTE Errcode;
  UWORD cx;

  
    if(DLC_SDO_RX_Lenght == 4){
        //uw_ADDRESS = (DLC_SDO_RX_Address_H << 8) + DLC_SDO_RX_Address_L;

        if(SHOW_ALLPR == 1)
              bx = GRALL;
        else{
            if(SHOW_ENHANCE == 1)
                  bx = GRENHANCE;
            else
                  bx = GRUSER;          
        }

        
        if(DLC_SDO_RX_Address_H <= bx){
            //attr[]
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            cx = pr_gpno_Sibo[DLC_SDO_RX_Address_H];                              
            else
            cx = pr_gpno[DLC_SDO_RX_Address_H];                              
            if( DLC_SDO_RX_Address_L < cx){
            		//DLC function, Henry, 2016/07/20
                ax = (UWORD)prtab[DLC_SDO_RX_Address_H] + DLC_SDO_RX_Address_L;
                //uw_AttrTemp = attr[ax].ati; 
                uw_AttrTemp = GetParAttr(ax);   // get wrong para atti, v0.05
                uwMaxTemp = GetParMax(ax);
                uwMinTemp = GetParMin(ax);
                uw_Default = attr[ax].def;
                
                CAN_SDO_Attribution_return(uw_AttrTemp,uwMinTemp,uwMaxTemp,uw_Default);
            }
            else{
                Errcode = 0x80|0x60;
                CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
            }
        }
      	else if(DLC_SDO_RX_Address_H==0x16){
          if((DLC_SDO_RX_Address_L+DLC_SDO_RX_Lenght)<=100)
		  {
              ax = (UWORD)DLC_SDO_RX_Address_L;
			  if(ax<0x96)
			  {
	              if(ax<0x32)
				  {
		              uw_AttrTemp = attr_DLC_adjst[ax].ati;
		              uwMaxTemp = attr_DLC_adjst[ax].max;
		              uwMinTemp = attr_DLC_adjst[ax].min;
		              uw_Default = attr_DLC_adjst[ax].def;
		          }			  
				  else if((ax>=0x32)&&(ax<0x64)) 
				  {
		              uw_AttrTemp = attr_DLC_adjst2[ax-0x32].ati;
		              uwMaxTemp = attr_DLC_adjst2[ax-0x32].max;
		              uwMinTemp = attr_DLC_adjst2[ax-0x32].min;
		              uw_Default = attr_DLC_adjst2[ax-0x32].def;   	
				  }
				  else if((ax>=0x64)&&(ax<0x96)) 
				  {
		              uw_AttrTemp = attr_DLC_adjst3[ax-0x64].ati;
		              uwMaxTemp = attr_DLC_adjst3[ax-0x64].max;
		              uwMinTemp = attr_DLC_adjst3[ax-0x64].min;
		              uw_Default = attr_DLC_adjst3[ax-0x64].def;   	
		          }
	              CAN_SDO_Attribution_return(uw_AttrTemp,uwMinTemp,uwMaxTemp,uw_Default);
			  	}
				else
				{
					Errcode = 0x80|0x60;
					CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
				}
		  }
          else
		  {
              Errcode = 0x80|0x60;
              CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
          }      	
      	}
        else if(DLC_SDO_RX_Address_H == 0x21){ //[C22xx function can be read, Bernie, 2017/05/23]
            if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght) <= C21MAX){
            		//DLC function, Henry, 2016/07/20
                ax = (UWORD)DLC_SDO_RX_Address_L;
                //uw_AttrTemp = attr[ax].ati; 
                uw_AttrTemp = DispAttr[ax].ati;   // get wrong para atti, v0.05
                uwMaxTemp = 65535;
                uwMinTemp = 0;
                uw_Default = 0;
                
                CAN_SDO_Attribution_return(uw_AttrTemp,uwMinTemp,uwMaxTemp,uw_Default);
            }
            else{
                Errcode = 0x80|0x60;
                CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
            }
        }
        else if(DLC_SDO_RX_Address_H == 0x22){ //[C22xx function can be read, Bernie, 2017/05/23]
            if((DLC_SDO_RX_Address_L + DLC_SDO_RX_Lenght) <= C22MAX){
            		//DLC function, Henry, 2016/07/20
                ax = (UWORD)DLC_SDO_RX_Address_L;
                //uw_AttrTemp = attr[ax].ati; 
                uw_AttrTemp = DispAttr_c22xx[ax].ati;   // get wrong para atti, v0.05
                uwMaxTemp = 65535;
                uwMinTemp = 0;
                uw_Default = 0;
                
                CAN_SDO_Attribution_return(uw_AttrTemp,uwMinTemp,uwMaxTemp,uw_Default);
            }
            else{
                Errcode = 0x80|0x60;
                CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
            }
        }
        else{
            Errcode = 0x80|0x60;
            CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
        }
        
    }
    else{
        Errcode = 0x80|0x60;
        CAN_ERROR_Return(ATT_EXCEPTION,Errcode);
    } 
}


void CAN_SDO_READ_Description(void){
  UWORD uw_ADDRESS,ax,bx,cx,datac,datab;
  UBYTE Errcode;
  
    if(DLC_SDO_RX_Lenght == 0x0A){
        if(SHOW_ALLPR == 1)
              bx = GRALL;
        else{
            if(SHOW_ENHANCE == 1)
                  bx = GRENHANCE;
            else
                  bx = GRUSER;          
        }

        
        if(DLC_SDO_RX_Address_H <= bx){
            if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
            cx = pr_gpno_Sibo[DLC_SDO_RX_Address_H];                              
            else
            cx = pr_gpno[DLC_SDO_RX_Address_H];                              
            if((DLC_SDO_RX_Address_L)< cx){
            		//DLC function, Henry, 2016/07/20
                ax = (UWORD)prtab[DLC_SDO_RX_Address_H] + DLC_SDO_RX_Address_L;
                 //prinfo_tc[ax];
                 switch(DLC_SDO_RX_Data0&0x0003){
                    #if Language_TC
                    case 1:
                        datab = 0x0200;
                        datac = (C20xx[0x05] & 0x00ff);
                        datac |= datab;
                        
                        C20xx[0x05] = datac;
                    break;
                    #endif
                    #if Language_SC
                    case 2:
                        datab = 0x0300;
                        datac = (C20xx[0x05] & 0x00ff);
                        datac |= datab;
                        
                        C20xx[0x05] = datac;
                    break;
                    #endif

                    case 0:
                    default:
                        datab = 0x0100;
                        datac = (C20xx[0x05] & 0x00ff);
                        datac |= datab;
                        
                        C20xx[0x05] = datac;

                    break;
                 }
                CAN_SDO_Description_return(prinfo[ax]);
            }
            else{
                Errcode = 0x80|0x61;
                CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
            }
        }
      	else if(DLC_SDO_RX_Address_H==0x16){
            if(DLC_SDO_RX_Address_L<100){
                switch(DLC_SDO_RX_Data0&0x0003){
                   #if Language_TC
                   case 1:
                       datab = 0x0200;
                       datac = (C20xx[0x05] & 0x00ff);
                       datac |= datab;
                       C20xx[0x05] = datac;
                       ax = DLC_SDO_RX_Address_L;
                       if(ax<0x96)
                       {
                           if(ax<0x32)
                               CAN_SDO_Description_return(prinfo_DLC_tc_Adjst[ax]);
                           else if((ax>=0x32)&&(ax<0x64)) 
                               CAN_SDO_Description_return(prinfo_DLC_tc_Adjst2[ax-0x32]);
                           else if((ax>=0x64)&&(ax<0x96))                  
                               CAN_SDO_Description_return(prinfo_DLC_tc_Adjst3[ax-0x64]);
                       }
                       else
                       {
                           Errcode = 0x80|0x61;
                           CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
                       }
                   break;
                   #endif
                   #if Language_SC
                   case 2:
                       datab = 0x0300;
                       datac = (C20xx[0x05] & 0x00ff);
                       datac |= datab;
                       C20xx[0x05] = datac;
                       ax = DLC_SDO_RX_Address_L;
                       if(ax<0x96)
                       {
                           if(ax<0x32)
                               CAN_SDO_Description_return(prinfo_DLC_sc_Adjst[ax]);
                           else if((ax>=0x32)&&(ax<0x64)) 
                               CAN_SDO_Description_return(prinfo_DLC_sc_Adjst2[ax-0x32]);
                           else if((ax>=0x64)&&(ax<0x96))                  
                               CAN_SDO_Description_return(prinfo_DLC_sc_Adjst3[ax-0x64]);
                       }
                       else
                       {
                           Errcode = 0x80|0x61;
                           CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
                       }
                   break;
                   #endif
                   case 0:
                   default:
                       datab = 0x0100;
                       datac = (C20xx[0x05] & 0x00ff);
                       datac |= datab;
                       C20xx[0x05] = datac;
                       ax = DLC_SDO_RX_Address_L;
                       if(ax<0x96)
                       {
                           if(ax<0x32)
                               CAN_SDO_Description_return(prinfo_DLC_Adjst[ax]);
                           else if((ax>=0x32)&&(ax<0x64)) 
                               CAN_SDO_Description_return(prinfo_DLC_Adjst2[ax-0x32]);
                           else if((ax>=0x64)&&(ax<0x96))                  
                               CAN_SDO_Description_return(prinfo_DLC_Adjst3[ax-0x64]);
                       }
                       else
                       {
                           Errcode = 0x80|0x61;
                           CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
                       }
                
                   break;
                }
            }
            else{
                Errcode = 0x80|0x61;
                CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
            }
      	}
        else{
            Errcode = 0x80|0x61;
            CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
        }
    }
    else{

        Errcode = 0x80|0x61;
        CAN_ERROR_Return(DESCR_EXCEPTION,Errcode);
    }
    
}

void CAN_SDO_Attribution_return(UWORD Attribute, UWORD Minimum, UWORD Maxmum, UWORD Default){

    CAN1.MB[2].DATA[0]= READ_ATTRIBUTION;
    CAN1.MB[2].DATA[1]= DLC_SDO_RX_Lenght;
    CAN1.MB[2].DATA[2]= DLC_SDO_RX_Address_H;
    CAN1.MB[2].DATA[3]= DLC_SDO_RX_Address_L;
    CAN1.MB[2].DATA[4]= (UBYTE)((Attribute&0xFF00)>>8);
    CAN1.MB[2].DATA[5]= (UBYTE)((Attribute&0x00FF));
    CAN1.MB[2].DATA[6]= (UBYTE)((Minimum&0xFF00)>>8);
    CAN1.MB[2].DATA[7]= (UBYTE)((Minimum&0x00FF));
    
    //CAN1.MCTL[2].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[2].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[2].BIT.TX.TRMREQ = 1;                    //[CAN bus problem, Bernie, 2016/10/28]

    CAN1.MB[4].DATA[0]= (UBYTE)((Maxmum&0xFF00)>>8);
    CAN1.MB[4].DATA[1]= (UBYTE)((Maxmum&0x00FF));
    CAN1.MB[4].DATA[2]= (UBYTE)((Default&0xFF00)>>8);
    CAN1.MB[4].DATA[3]= (UBYTE)((Default&0x00FF));

    //CAN1.MCTL[4].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[4].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[4].BIT.TX.TRMREQ = 1;                  //[CAN bus problem, Bernie, 2016/10/28]

    CAN_RX3_OK = 0;     //clear flag 
    CAN_RX5_OK = 0; 
    CAN_RX7_OK = 0; 
    
}

void CAN_SDO_Description_return(string20 str){

    //CAN1.MB[2].DATA[0]= str.x[0];
 
    CAN1.MB[2].DATA[0]= READ_DESCRIPTION;
    CAN1.MB[2].DATA[1]= DLC_SDO_RX_Lenght;
    CAN1.MB[2].DATA[2]= DLC_SDO_RX_Address_H;
    CAN1.MB[2].DATA[3]= DLC_SDO_RX_Address_L;
    CAN1.MB[2].DATA[4]= str.x[0];
    CAN1.MB[2].DATA[5]= str.x[1];
    CAN1.MB[2].DATA[6]= str.x[2];
    CAN1.MB[2].DATA[7]= str.x[3];
    
    //CAN1.MCTL[2].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[2].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[2].BIT.TX.TRMREQ = 1;                     //[CAN bus problem, Bernie, 2016/10/28]

    CAN1.MB[4].DATA[0]= str.x[4];
    CAN1.MB[4].DATA[1]= str.x[5];
    CAN1.MB[4].DATA[2]= str.x[6];
    CAN1.MB[4].DATA[3]= str.x[7];
    CAN1.MB[4].DATA[4]= str.x[8];
    CAN1.MB[4].DATA[5]= str.x[9];
    CAN1.MB[4].DATA[6]= str.x[10];
    CAN1.MB[4].DATA[7]= str.x[11];

    //CAN1.MCTL[4].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[4].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[4].BIT.TX.TRMREQ = 1;                    //[CAN bus problem, Bernie, 2016/10/28]
 
    CAN1.MB[6].DATA[0]= str.x[12];
    CAN1.MB[6].DATA[1]= str.x[13];
    CAN1.MB[6].DATA[2]= str.x[14];
    CAN1.MB[6].DATA[3]= str.x[15];
    CAN1.MB[6].DATA[4]= str.x[16];
    CAN1.MB[6].DATA[5]= str.x[17];
    CAN1.MB[6].DATA[6]= str.x[18];
    CAN1.MB[6].DATA[7]= str.x[19];

    //CAN1.MCTL[6].BIT.TX.TRMREQ = 0;
	//nop();
	//CAN1.MCTL[6].BIT.TX.SENTDATA = 0;

    CAN1.MCTL[6].BIT.TX.TRMREQ = 1;                     //[CAN bus problem, Bernie, 2016/10/28]

    CAN_RX3_OK = 0;  //clear flag 
    CAN_RX5_OK = 0; 
    CAN_RX7_OK = 0; 
    
}


//void PDO_sub0(UWORD k)          // 2_wire: di_0: run/fwd, di_1:run/rev //
//{
//    if (((pr[EXTON_RUN]==1)&&((pr[WIRE2_3]&0x01)==0x00)/*&&TUN_STOP==0*/&&DLC_ubSTOP==0)){
//		//k=EXT_FWD, mean EXT_REV active
//		if (k==EXT_FWD){        
////	    	run();	// delete by dino, 03/08/2007
//            if (pr[SETDIR]==2) {           // disable Forward //
//				//CMDDIR = REVERSE;// gfc
//				if (RUNNING==STOP){
//					CMDDIR = REVERSE;// gfc
//		    		WGDIR = REVERSE;
//		    }
//	    	}
//	    	else {
//	    		if ((PWM_Status.ub&0x42) == 0){  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010   //0x12 to 0x42 [Modify EPS function, Bernie, 2012/11/27 ]
//					//CMDDIR = FORWARD;// gfc
//					if (RUNNING==STOP){
//						CMDDIR = FORWARD;// gfc
//		    			WGDIR = FORWARD;
//		    	}
//		    	}
//	    	}
//	    	// gfc
//	    	if (CMDJOG==0 && !GEN_START &&(RUNNING==STOP)){	// Add by DINO, 11/28/2008 //[EPS, Sampo, 03/27/2011]
//	    		LIFT_RUNCMD = 1;
//	    		run();	// dino, 03/08/2007
//	    	}
//		}
//		//k=EXT_REV, mean EXT_FWD active
//		else if (k==EXT_REV) {  
////	    	run();	// delete by dino, 03/08/2007
//	    	if (pr[SETDIR]==1){
//              	//CMDDIR = FORWARD;// gfc
//              	if (RUNNING==STOP){
//              		CMDDIR = FORWARD;// gfc
//                  WGDIR = FORWARD;
//                }
//	    	}
//	    	else{
//	    		if ((PWM_Status.ub&0x42) == 0){  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010    //0x12 to 0x42 [Modify EPS function, Bernie, 2012/11/27 ]
//             		//CMDDIR = REVERSE;// gfc
//               		if (RUNNING==STOP){
//               			CMDDIR = REVERSE;// gfc
//                    	WGDIR = REVERSE;
//                  }
//                }
//	    	}
//	    	// gfc
//	    	if (CMDJOG==0 && !GEN_START && (RUNNING==STOP)){	// Add by DINO, 11/28/2008 //[EPS, Sampo, 03/27/2011]
//	    		LIFT_RUNCMD = 1;
//	    		run();	// dino, 03/08/2007
//	    	}
//		}
//		else{
//	    	if (CMDJOG==0){	// Add by DINO, 11/28/2008
//				LIFT_RUNCMD = 0;
//	    		stop();
//	    	}
//	    }
//    }
//}

void PDO_sub0(UWORD k)          // 2_wire: di_0: run/fwd, di_1:run/rev //
{
		if (((pr[EXTON_RUN]==1)&&((pr[WIRE2_3]&0x01)==0x00)/*&&TUN_STOP==0*/)&&(STO_FLAG ==0)){   //[STO function has fixed, Bernie, 2015/03/02]
		//k=EXT_FWD, mean EXT_REV active
		if (k==EXT_FWD){        
//	    	run();	// delete by dino, 03/08/2007
            RUN_DETECT = 1;
            if (pr[SETDIR]==2) {           // disable Forward //
				//CMDDIR = REVERSE;// gfc
				if (RUNNING==STOP){
					CMDDIR = REVERSE;// gfc
    		    	WGDIR = REVERSE;
    		    }
	    	}
	    	else {
	    		if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010   //0x12 to 0x42 [Modify EPS function, Bernie, 2012/11/27 ]
					CMDDIR = FORWARD;// gfc
             		if(WGDIR!=CMDDIR) //[Wrong dir in Ins,Lyabryan,2018/07/16]
                        stop();
					if(RUNNING==STOP){
						CMDDIR = FORWARD;
						WGDIR = FORWARD;
					}
		    	}
	    	}
	    	// gfc
	    	if (CMDJOG==0 && !GEN_START && (MODE3==0)&&(RUNNING==STOP)){	// Add by DINO, 11/28/2008 //[EPS, Sampo, 03/27/2011]  //[DIN time sequence, Bernie, 2013/03/07]
	    		LIFT_RUNCMD = 1;
	    		run();	// dino, 03/08/2007
	    	}
            else{                        //[DIN time sequence, Bernie, 2013/03/07]
                if((MODE3 == 1)){
                    LIFT_RUNCMD = 0;
	    		    stop();
                }
            }
		}
		//k=EXT_REV, mean EXT_FWD active
		else if (k==EXT_REV) {  
//	    	run();	// delete by dino, 03/08/2007
            RUN_DETECT = 1;
	    	if (pr[SETDIR]==1){
					if(RUNNING==STOP){
						CMDDIR = FORWARD;
						WGDIR = FORWARD;
					}
	    	}
	    	else{
	    		if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){  //[EPS autodetect dir,Lyabryan,2018/07/02] //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010    //0x12 to 0x42 [Modify EPS function, Bernie, 2012/11/27 ]
             		CMDDIR = REVERSE;// gfc
             		if(WGDIR!=CMDDIR) //[Wrong dir in Ins,Lyabryan,2018/07/16]
                        stop();
                  // GEN_OK done, chg eps dir, Henry, 20170621
                    if(RUNNING==STOP){
                    	CMDDIR = REVERSE;
                    	WGDIR = REVERSE;
                    }
                }
	    	}
	    	// gfc
	    	if (CMDJOG==0 && !GEN_START && (MODE3==0)&&(RUNNING==STOP)){	// Add by DINO, 11/28/2008 //[EPS, Sampo, 03/27/2011]  //[DIN time sequence, Bernie, 2013/03/07]
	    		LIFT_RUNCMD = 1;
	    		run();	// dino, 03/08/2007
	    	}
            else{                    //[DIN time sequence, Bernie, 2013/03/07]
                if((MODE3 == 1)){
                    LIFT_RUNCMD = 0;
                    stop();
      	        }
            }
		}
		else{
	    	if (CMDJOG==0){	// Add by DINO, 11/28/2008
				LIFT_RUNCMD = 0;           
                MODE2 = 0;  //[DIN time sequence, Bernie, 2013/03/07]
                MODE3 = 0;			
	    		stop();
                RUN_DETECT = 0; //[Russia time srequence for IM, Bernie, 2015/07/13]
	    	}
	    }
    }
}

#if 0
void Update_DLCC40xx(void){    //[DLC, Bernie, 2015/01/22]
  UWORD i;
   for(i=0; i<0x46; i++){
       pr[FL_POSIT_1H+i] = C40xx[i];
       write_ep(0,FL_POSIT_1H+i,pr[FL_POSIT_1H+i]);
   }
}
#endif

#ifdef  _RCAN_ET_C
    #undef  _RCAN_ET_C
#endif

/************************************************************************
 Copyright (c) 2007 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
