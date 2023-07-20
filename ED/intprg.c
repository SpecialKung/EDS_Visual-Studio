/************************************************************************
*
* Device     : RX/RX600/RX63TH
*
* File Name  : intprg.c
*
* Abstract   : Interrupt Program.
*
* History    : 0.50  (2012-08-28)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2012 Renesas Electronics Corporation and
* Renesas Solutions Corp. All rights reserved.
*
*********************************************************************/
#include <machine.h>
#include "vect.h"

#pragma section IntPRG

//#include "Vect.h"
#include "ProgHeader.h"


// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BSC BUSERR
void Excep_BSC_BUSERR(void){ }

// FCU FIFERR
void Excep_FCU_FIFERR(void){ }

// FCU FRDYI
void Excep_FCU_FRDYI(void){ }

// ICU SWINT
void Excep_ICU_SWINT(void){ }

// CMT0 CMI0
void Excep_CMT0_CMI0(void){
/*
#pragma asm
    STS.L    MACH,@-R15
    STS.L    MACL,@-R15	
#pragma endasm
*/
    //CMT0.CMCSR.BIT.CMF = 0;
       //PORTE.PODR.BIT.B4 ^= 1;
    TimeBase_500us();
/*
#pragma asm
    LDS.L  @R15+,MACL
    LDS.L  @R15+,MACH
#pragma endasm
*/
}

// CMT1 CMI1
void Excep_CMT1_CMI1(void){ 
/*
    #pragma asm
        STS.L    MACH,@-R15
        STS.L    MACL,@-R15 
    #pragma endasm
*/    


        // [ Add by DINO, 03/06/2009
        //SpDt_uwPG1CNT = MTU21.TCNT;
        SpDt_uwPG1CNT = MTU1.TCNT;
        //MTU20.TSR.BYTE &= 0xFE;             //clear TGFA flag
        MTU0.TSR.BYTE &= 0xFE;             //clear TGFA flag
        //MTU20.TIER.BYTE |= 0x01;            //TGIEA, speed capture interrupt enable per 100us
        MTU0.TIER.BYTE |= 0x01;            //TGIEA, speed capture interrupt enable per 100us
        // ]
            
        //CMT1.CMCSR.BIT.CMF = 0;
    
        TimeBase_100us();
        
/*    
    #pragma asm
        LDS.L  @R15+,MACL
        LDS.L  @R15+,MACH
    #pragma endasm
*/
}

// CMT2 CMI2
void Excep_CMT2_CMI2(void){
	extern UWORD_UNION	Mntr_uwGenReg;
	extern UBYTE ChCount, ChCountTmp;
	//-----Aevin add to detect in modbus normal/explorer mode---7/2/2015
	if(uwVfd_Explorer_Flag == 0x0001){
		uwVfd_Explorer_Count++;
		if(uwVfd_Explorer_Count >= 15000){//if exceed 1s , then close explorer mode , modi to 3s --Aevin 4/7/2016
			uwVfd_Explorer_Count = 0;
			uwVfd_Explorer_Flag = 0;
			//[force to stop scope mode,Aevin,2016/08/03] 
			USB_vdIniTx(1);
		}
	}
	USB_vdMonitor_Sample();	// USB Tx/Rx Handler // pc monitor sampling function reallocation, Sean, 20141225	
	usb_apl_task_switch();	// USB routine, Sean, 2014/09/16
}

// CMT3 CMI3
void Excep_CMT3_CMI3(void){ }

// USB0 D0FIFO0
// void Excep_USB0_D0FIFO0(void){ }	// combine ED&USB, Sean, 20140812

// USB0 D1FIFO0
void Excep_USB0_D1FIFO0(void){ }

// USB0 USBI0
// void Excep_USB0_USBI0(void){ }	// combine ED&USB, Sean, 20140812

// CAC FERRF
void Excep_CAC_FERRF(void){ }

// CAC MENDF
void Excep_CAC_MENDF(void){ }

// CAC OVFF
void Excep_CAC_OVFF(void){ }

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){ }

// RSPI1 SPRI1
void Excep_RSPI1_SPRI1(void){ }

// RSPI1 SPTI1
void Excep_RSPI1_SPTI1(void){ }

// RSPI1 SPII1
void Excep_RSPI1_SPII1(void){ }

// CAN1 RXF1
void Excep_CAN1_RXF1(void){ }

// CAN1 TXF1
void Excep_CAN1_TXF1(void){ }

// CAN1 RXM1
void Excep_CAN1_RXM1(void){
    //uwtest9 = CAN1.MB[1].DATA[5];
    
    CAN_RX();
    RCAN_RX_Count = 0;

}

// CAN1 TXM1
void Excep_CAN1_TXM1(void){

    if(CAN1.MCTL[0].BIT.TX.SENTDATA){
        //CAN1.MCTL[0].BIT.TX.SENTDATA = 0;
  
        //CAN1.MCTL[0].BYTE = 0x00;
       CAN1.MCTL[0].BIT.TX.TRMREQ = 0;
       nop();
       CAN1.MCTL[0].BIT.TX.SENTDATA = 0;

    }
    if(CAN1.MCTL[2].BIT.TX.SENTDATA){
        //CAN1.MCTL[2].BIT.TX.SENTDATA = 0;
  
        //CAN1.MCTL[2].BYTE = 0x00;
        
        CAN1.MCTL[2].BIT.TX.TRMREQ = 0;
        nop();
        CAN1.MCTL[2].BIT.TX.SENTDATA = 0;

    }
    if(CAN1.MCTL[4].BIT.TX.SENTDATA){
        //CAN1.MCTL[4].BIT.TX.SENTDATA = 0;
  
        //CAN1.MCTL[4].BYTE = 0x00;
        CAN1.MCTL[4].BIT.TX.TRMREQ = 0;
        nop();
        CAN1.MCTL[4].BIT.TX.SENTDATA = 0;
    }
    
    if(CAN1.MCTL[6].BIT.TX.SENTDATA){
        //CAN1.MCTL[6].BIT.TX.SENTDATA = 0;
      
        //CAN1.MCTL[6].BYTE = 0x00;
        CAN1.MCTL[6].BIT.TX.TRMREQ = 0;
        nop();
        CAN1.MCTL[6].BIT.TX.SENTDATA = 0;
    
    }
    
    //[Gfc DLC modify,Henry,2018/05/23]
    if(CAN1.MCTL[8].BIT.TX.SENTDATA){
        CAN1.MCTL[8].BIT.TX.TRMREQ = 0;
        nop();
        CAN1.MCTL[8].BIT.TX.SENTDATA = 0;
    
    }
//#if Artemis_ENABLE
    //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]
    if(btArtemisEnable)
    {
    	//Artemis DLC modify , James, 2020/06/02
        if(CAN1.MCTL[10].BIT.TX.SENTDATA)
        {
            CAN1.MCTL[10].BIT.TX.TRMREQ = 0;
            nop();
            CAN1.MCTL[10].BIT.TX.SENTDATA = 0;
        
        }
    }
//#endif	
}

// GPT7 GTCIA7
void Excep_GPT7_GTCIA7(void){ }

// GPT7 GTCIB7
void Excep_GPT7_GTCIB7(void){ }

// GPT7 GTCIC7
void Excep_GPT7_GTCIC7(void){ }

// GPT7 GTCIE7
void Excep_GPT7_GTCIE7(void){ }

// GPT7 GTCIV7
void Excep_GPT7_GTCIV7(void){ }

// CMP CMP4
void Excep_CMP_CMP4(void){ }

// CMP CMP5
void Excep_CMP_CMP5(void){ }

// CMP CMP6
void Excep_CMP_CMP6(void){ }

// DOC DOPCF
void Excep_DOC_DOPCF(void){ }

// DPC RBI0
void Excep_DPC_RBI0(void){ }

// DPC RBI1
void Excep_DPC_RBI1(void){ }

// DPC RBI2
void Excep_DPC_RBI2(void){ }

// DPC RBI3
void Excep_DPC_RBI3(void){ }

// DPC RBI4
void Excep_DPC_RBI4(void){ }

// ICU IRQ0
// void Excep_ICU_IRQ0(void){ }	// combine ED&USB, Sean, 20140812

// ICU IRQ1
// void Excep_ICU_IRQ1(void){ }	// combine ED&USB, Sean, 20140812

// ICU IRQ2
// void Excep_ICU_IRQ2(void){ }	// combine ED&USB, Sean, 20140812

// ICU IRQ3
void Excep_ICU_IRQ3(void){ }

// ICU IRQ4
void Excep_ICU_IRQ4(void){ }

// ICU IRQ5
void Excep_ICU_IRQ5(void){ }

// ICU IRQ6
void Excep_ICU_IRQ6(void){ }

// ICU IRQ7
void Excep_ICU_IRQ7(void){ }

// USB USBR0
//void Excep_USB_USBR0(void){ }	// combine ED&USB, Sean, 20140812

// AD ADI0
void Excep_AD_ADI0(void){ }

// S12AD S12ADI0
void Excep_S12AD_S12ADI0(void){ }

// S12AD S12GBADI0
void Excep_S12AD_S12GBADI0(void){ }

// S12AD1 S12ADI1
void Excep_S12AD1_S12ADI1(void){ }

// S12AD1 S12GBADI1
void Excep_S12AD1_S12GBADI1(void){ }

// ICU GROUP0
void Excep_ICU_GROUP0(void){

}

// ICU GROUP12
void Excep_ICU_GROUP12(void){

    if((SCI2.SSR.BYTE & 0x38) != 0) {
        SCI2.SSR.BYTE &= 0x07;
        InitSCI2();
     }
  
     if((SCI3.SSR.BYTE & 0x38) != 0) {
        SCI3.SSR.BYTE = 0x00;
        InitSCI3();
    }
}

// SCI12 SCIX0
void Excep_SCI12_SCIX0(void){ }

// SCI12 SCIX1
void Excep_SCI12_SCIX1(void){ }

// SCI12 SCIX2
void Excep_SCI12_SCIX2(void){ }

// SCI12 SCIX3
void Excep_SCI12_SCIX3(void){ }

// MTU0 TGIA0
void Excep_MTU0_TGIA0(void){
    ISR_SpDtPG1();
}

// MTU0 TGIB0
void Excep_MTU0_TGIB0(void){ }

// MTU0 TGIC0
void Excep_MTU0_TGIC0(void){ }

// MTU0 TGID0
void Excep_MTU0_TGID0(void){ }

// MTU0 TCIV0
void Excep_MTU0_TCIV0(void){
    //MTU20.TSR.BYTE &= 0xEF;
    MTU0.TSR.BYTE &= 0xEF;
    SpDt_ubT0OverCnt = SpDt_ubT0OverCnt+1;
}

// MTU0 TGIE0
void Excep_MTU0_TGIE0(void){ }

// MTU0 TGIF0
void Excep_MTU0_TGIF0(void){ }

// MTU1 TGIA1
void Excep_MTU1_TGIA1(void){ }

// MTU1 TGIB1
void Excep_MTU1_TGIB1(void){ }

// MTU1 TCIV1
void Excep_MTU1_TCIV1(void){

     //MTU21.TSR.BYTE &= 0xEF;        //clear overflow flag
     MTU1.TSR.BYTE &= 0xCF;        //clear overflow flag
        // [ Modify PPI Counter, DINO, 05/24/2010
    /*
        if (SpDt_ubT1UderCnt == 1){
            SpDt_ubT1UderCnt = 0;
        }
        else {
            SpDt_ubT1OverCnt = 1;
        }
    */
        SPR_swPIVUVCnt++;  // Modify PPI overflow/underflow Counter, DINO,  05/25/2010
        SPR_swPGoverflwCnt++;    //[PG quality function, Bernie, 2017/06/20]
        // ]

}

// MTU1 TCIU1
void Excep_MTU1_TCIU1(void){

    //MTU21.TSR.BYTE &= 0xDF;     //clear overflow flag
    MTU1.TSR.BYTE &= 0xDF;     //clear overflow flag
        // [ Modify PPI Counter, DINO, 05/24/2010
    /*
        if (SpDt_ubT1OverCnt == 1){
            SpDt_ubT1OverCnt = 0;
        }
        else {
            SpDt_ubT1UderCnt = 1;
        }
    */
        SPR_swPIVUVCnt--;  // Modify PPI overflow/underflow Counter, DINO,  05/25/2010
        SPR_swPGoverflwCnt--;    //[PG quality function, Bernie, 2017/06/20]
        // ]

}

// MTU2 TGIA2
void Excep_MTU2_TGIA2(void){ }

// MTU2 TGIB2
void Excep_MTU2_TGIB2(void){ }

// MTU2 TCIV2
void Excep_MTU2_TCIV2(void){ }

// MTU2 TCIU2
void Excep_MTU2_TCIU2(void){ }

// MTU3 TGIA3
void Excep_MTU3_TGIA3(void){
    UBYTE ubVector;
    SWORD swTaOut, swTbOut, swTcOut;
/*
#pragma asm
    STS.L    MACH,@-R15
    STS.L    MACL,@-R15	
#pragma endasm
*/
    /*=== Timer Status Register (TSR) ======================================*/
    /* Bit[7]         1     :TCFD, TCNT Counts up                           */
    /* Bit[6-5]       10    :RESERVED                                        */
    /* Bit[4]         0     :TCFV,Overflow flag 0:clear 1:set               */
    /* Bit[3]         0     :TGFD,Compare-match flag TGRD                   */
    /* Bit[2]         0     :TGFC,Compare-match flag TGRC                   */
    /* Bit[1]         0     :TGFB,Compare-match flag TGRB                   */
    /* Bit[0]         0     :TGFA,Compare-match flag TGRA                   */    
    //MTU23.TSR.BYTE &= 0xC0;       /* Clear Compare-match flag              */
    MTU3.TSR.BYTE &= 0xC0;       /* Clear Compare-match flag              */

    if( pr[CTRLM]!=FOCPM && TUN_START==1) //[IM Autotune Modify,Sampo,2018/07/12]
      ReadAD();
   if(experiod_Buf==2400){  //[current ripple,sampo,2018/01/15]
    if(CMT1.CMCNT <200 )
    	   CMT1.CMCNT = 200;
    }
    // [ Short_Circuit Detection, DINO, 05/19/2010
    if(BEFORERUN){

        if(CMDRUN == RUN){    //[Ocd Error occurred when BeforeRun, Lyabryan, 2015/01/05]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                //ACCODEC = ACCON;                    //[Ocd Error occurred when BeforeRun, Lyabryan, 2015/01/05]
#else 
                ACCODEC = ACCON;                    //[Ocd Error occurred when BeforeRun, Lyabryan, 2015/01/05]

#endif
			prt_voDiagnosticProcess();
    	}
    }
    // ]
    else if ( STtune ){
		if (CMDRUN == RUN){
	    	if ( TB2Cnt==st_uwInterval ) {
				TB2Cnt = 0;
                AD_OK = 0;
        		PhaseCnt++;
                /* add by dino, 04/03/2007 */
                if ( (PhaseCnt&0x07)>5 ){ st_uwInterval = 100; }	// waiting for 100 * 1/carry *2
                else { st_uwInterval = pr[TB2Time]; }
	    	}

	    	ubVector = PhaseCnt & 0x07;

	    	if ( AD_OK==0 ) {
				switch (ubVector){
            	    case 0:
            	    	if (  AD_swIAPu>=COF_uwSSIratedPu ){ IAPCnt=TB2Cnt;    st_uwInterval=TB2Cnt<<1;    AD_OK=1;    TB2Cnt=0; }
            	    	break;
            	    case 1:
            	    	if ( -AD_swIAPu>=COF_uwSSIratedPu ){ IANCnt=TB2Cnt;    st_uwInterval=TB2Cnt<<1;    AD_OK=1;    TB2Cnt=0; }
            	    	break;
            	    case 2:
            	    	if (  AD_swIBPu>=COF_uwSSIratedPu ){ IBPCnt=TB2Cnt;    st_uwInterval=TB2Cnt<<1;    AD_OK=1;    TB2Cnt=0; }
            	    	break;
            	    case 3:
            	    	if ( -AD_swIBPu>=COF_uwSSIratedPu ){ IBNCnt=TB2Cnt;    st_uwInterval=TB2Cnt<<1;    AD_OK=1;    TB2Cnt=0; }
            	    	break;
            	    case 4:
            	    	if (  AD_swICPu>=COF_uwSSIratedPu ){ ICPCnt=TB2Cnt;    st_uwInterval=TB2Cnt<<1;    AD_OK=1;    TB2Cnt=0; }
            	    	break;
            	    case 5:
            	    	if ( -AD_swICPu>=COF_uwSSIratedPu ){ ICNCnt=TB2Cnt;    st_uwInterval=TB2Cnt<<1;    AD_OK=1;    TB2Cnt=0; }
            	    	break;
            	}
	    	}

	        swTaOut = PM_swTmax;    swTbOut = PM_swTmax;    swTcOut = PM_swTmax;

            if ( ubVector==0 ){      swTaOut= PM_swTmin;    			        } //   0
            else if ( ubVector==1 ){ swTbOut= PM_swTmin;    swTcOut= PM_swTmin; } // 180
            else if ( ubVector==2 ){ swTbOut= PM_swTmin;			            } // 120
            else if ( ubVector==3 ){ swTaOut= PM_swTmin;    swTcOut= PM_swTmin; } // 300
            else if ( ubVector==4 ){ swTcOut= PM_swTmin;    			        } // 240
            else if ( ubVector==5 ){ swTaOut= PM_swTmin;    swTbOut= PM_swTmin;	} //  60

	    	//MTU2.TCBR = experiod;
            MTU.TCBRA = experiod;
	    	//MTU23.TGRC = experiod + DeadTime;
            MTU3.TGRC = experiod + DeadTime;
			// [ Change Output Direction, Added by sampo , 06/11/2009
	        if(0){  // Delete CHGDIR Function, DINO, 08/03/2010
	    		//MTU23.TGRD = swTbOut;
	    		//MTU24.TGRC = swTaOut;
                MTU3.TGRD = swTbOut;
	    		MTU4.TGRC = swTaOut;
	    	}
	    	else{
	    		//MTU23.TGRD = swTaOut;
	    		//MTU24.TGRC = swTbOut;
                MTU3.TGRD = swTaOut;
	    		MTU4.TGRC = swTbOut;
	    	}
	    	// ]
	    	//MTU24.TGRD = swTcOut;
            MTU4.TGRD = swTcOut;

	    	TB2Cnt++;
		}
    }
    else {
    	
    	  if ((RUNNING==RUN)&&(Error==0 || (Error!=0 && WARNSTOPREC==1) ) && TUN_START==1 && pr[CTRLM]!=FOCPM){  //[IM Autotune Modify,Sampo,2018/07/12]
		// [ Calculate MPHL Detected Output Voltage, Add by Sampo, 05/12/2009
           TUN_ProcessTB2();
        
    }
    	
    	
    	
    	
    	//MTU2.TCBR  = experiod_Buf;
    	//MTU23.TGRC = experiod_Buf + DeadTime;
        MTU.TCBRA  = experiod_Buf;
    	MTU3.TGRC = experiod_Buf + DeadTime;
		// [ Change Output Direction, Added by sampo , 06/11/2009
    	if (0){  // Delete CHGDIR Function, DINO, 08/03/2010
			//MTU23.TGRD = PWM_swTbOut_Buf;
			//MTU24.TGRC = PWM_swTaOut_Buf;
            MTU3.TGRD = PWM_swTbOut_Buf;
			MTU4.TGRC = PWM_swTaOut_Buf;
        }
        else{
			//MTU23.TGRD = PWM_swTaOut_Buf;
			//MTU24.TGRC = PWM_swTbOut_Buf;
            MTU3.TGRD = PWM_swTaOut_Buf;
			MTU4.TGRC = PWM_swTbOut_Buf;
        }
		// ]
    	//MTU24.TGRD = PWM_swTcOut_Buf;

        MTU4.TGRD = PWM_swTcOut_Buf;
	}
	
    if(CC4display && prt_CCcnt == 0){       //[CC Display, Bernie, 2017/04/12]    
        CC4display = 0;
    }
    if(CC4display && (prt_CCcnt != 0)){     //[CC Display, Bernie, 2017/04/12]
        prt_CCcnt--;
    }
    
    WG_isr();
/*
#pragma asm
    LDS.L  @R15+,MACL
    LDS.L  @R15+,MACH
#pragma endasm
*/
}

// MTU3 TGIB3
void Excep_MTU3_TGIB3(void){ }

// MTU3 TGIC3
void Excep_MTU3_TGIC3(void){ }

// MTU3 TGID3
void Excep_MTU3_TGID3(void){ }

// MTU3 TCIV3
void Excep_MTU3_TCIV3(void){ }

// MTU4 TGIA4
void Excep_MTU4_TGIA4(void){ }

// MTU4 TGIB4
void Excep_MTU4_TGIB4(void){ }

// MTU4 TGIC4
void Excep_MTU4_TGIC4(void){ }

// MTU4 TGID4
void Excep_MTU4_TGID4(void){ }

// MTU4 TCIV4
void Excep_MTU4_TCIV4(void){ }

// MTU5 TGIU5
void Excep_MTU5_TGIU5(void){ }

// MTU5 TGIV5
void Excep_MTU5_TGIV5(void){ }

// MTU5 TGIW5
void Excep_MTU5_TGIW5(void){ }

// MTU6 TGIA6
void Excep_MTU6_TGIA6(void){ }

// MTU6 TGIB6
void Excep_MTU6_TGIB6(void){ }

// MTU6 TGIC6
void Excep_MTU6_TGIC6(void){ }

// MTU6 TGID6
void Excep_MTU6_TGID6(void){
    UWORD uwTemp, uwTemp1;
    ULONG_UNION ul_temp;

	
    //MTU2S4.TSR.BYTE &= 0xF7;	// clear TGFD flag
    MTU6.TSR.BYTE &= 0xF7;	// clear TGFD flag

    SPR_uwPGTCNT = MTU1.TCNT;

    //if(SPR_uwPGTCNT>SPR_uwPGTCNT_old){
        //SPR_ulPGQualityCnt = (ULONG)(SPR_uwPGTCNT)+((abs(SPR_swPGoverflwCnt)-1)*0xFFFF)+(0xFFFF-SPR_uwPGTCNT_old);       //CW
        //SPR_ulPGQualityCnt = (ULONG)(0xFFFF-SPR_uwPGTCNT)+((abs(SPR_swPGoverflwCnt)-1)*0xFFFF)+(SPR_uwPGTCNT_old);  //CCW
        //uwtest23 = 0xFFFF-SPR_uwPGTCNT;
    //}
    //else{
    //}

	// [ Modify by DINO, 11/27/2009
	uwTemp = (UWORD)(SpDt_ulThetaR >> 16);
	// ]
	//uw_SCTEST4 = MTU21.TCNT;	// For hardware test
	uw_SCTEST4 = MTU1.TCNT;	// For hardware test
	//[ //[Zphase broken, Lyabryan, 2015/09/17]
    Zphase_swcountAB_error = uw_SCTEST4 - Zphase_countAB_old;//[Zphase broken, Lyabryan, 2015/09/17]
    
    if(((Zphase_swcountAB_error>=0)||(Zphase_swcountAB_error<=0))&&(abs(Zphase_swcountAB_error)<10)){
        Zphase_error_zero = 1;
        Zphase_countAB_count = 0;
    }
    
    if(((Zphase_swcountAB_error<0)||(Zphase_swcountAB_error>0))&&(Zphase_swcountAB_error == Zphase_swcountAB_error_old)&&(abs(Zphase_swcountAB_error) <= 100)&&(Zphase_error_zero == 0)){
        Zphase_error_zero = 0;
        Zphase_countAB_count++;
    }
    else{
        Zphase_error_zero = 0;
        Zphase_countAB_count = 0;
    }
    
    if(Zphase_countAB_count >= 4){//[Zphase broken, Lyabryan, 2015/09/17] //[Two Zpulses,Lyabryan,2016/07/15]
        Zphase_countAB_flag = 1;
        Zphase_countAB_count = 0;
    }
    
    if(abs(Zphase_swcountAB_error) <= 100) //[Two Zpulses,Lyabryan,2016/07/15]
        Zphase_tune_count++;
    else {
        Zphase_tune_count = 0;
        if(RUNNING == RUN){
            //if(FIRST_FLAG==0){             
                if(SPR_uwPGDIR==1){
                    if(SPR_swPGoverflwCnt==0){
                        SPR_ulPGQualityCnt = (ULONG)(abs(SPR_uwPGTCNT_old-SPR_uwPGTCNT));
                    }
                    else{
                        SPR_ulPGQualityCnt = (ULONG)(SPR_uwPGTCNT)+((abs(SPR_swPGoverflwCnt)-1)*0xFFFF+1)+(0xFFFF-SPR_uwPGTCNT_old+1);       //CW
                        //uwtest22++;
                    }
                }
                else{
                    if(SPR_swPGoverflwCnt==0){
                        SPR_ulPGQualityCnt = (ULONG)(abs(SPR_uwPGTCNT-SPR_uwPGTCNT_old));
                    }
                    else{
                        SPR_ulPGQualityCnt = (ULONG)(0xFFFF-SPR_uwPGTCNT+1)+((abs(SPR_swPGoverflwCnt)-1)*0xFFFF+1)+(SPR_uwPGTCNT_old)+1;  //CCW
                        //uwtest22--;
                    }
                }
                
            //}
            //else{
                //FIRST_FLAG = 0;
            //}
                if(FIRST_FLAG){
                    TB1_uwPGQualityZcnt++;
                    if(TB1_uwPGQualityZcnt==2){
                        FIRST_FLAG = 0;
                    }
                }
                SPR_swPGoverflwCnt_old = SPR_swPGoverflwCnt;
                SPR_swPGoverflwCnt = 0;
                SPR_uwPGTCNT_old = SPR_uwPGTCNT;
                SPR_uwPGDIRRec = SPR_uwPGDIR;
       
        }
    }
    
    Zphase_countAB_old = uw_SCTEST4;//[Zphase broken, Lyabryan, 2015/09/17]
    Zphase_swcountAB_error_old = Zphase_swcountAB_error;
    //] //[Zphase broken, Lyabryan, 2015/09/17]    
    uw_PGtest = uw_SCTEST4 - uw_PGReCoDer;

    uw_PGReCoDer = uw_SCTEST4;
 
	if ((pr[PM_AUTO_T]==1 || pr[PM_AUTO_T]==3) && !TUN_PHASEZ_OK && (Zphase_tune_count == 0)){  // 08/11/2008 //[Two Zpulses,Lyabryan,2016/07/15]
		if ( TUN_POS_DC_OK==1 ){  // Add by DINO, 08/14/2008
			TUN_Z_CAPTURECNTZ = TUN_Z_CAPTURECNT;
			TUN_Z_CAPTURECNT  = ((ULONG)uwTemp * SpDt_uwAnglePeriod) >> 16;

			TUN_Z_COUNT++;
			if (TUN_Z_COUNT>=5)
				TUN_PHASEZ_OK = 1;
		}
	}
	
	if ( (pr[DEBUG_F1]&0x0080)==0 && (Zphase_tune_count == 0)){  // Bit7: Don't operate Z correct when Bit7=1 //[Two Zpulses,Lyabryan,2016/07/15]
		if (pr[PM_AUTO_T]==0 && pr[Z_OFFSET]!=3600 && ZCALIB==0 && STtune==0){	//added scotty 09/28/2007 SC	
			ZCALIB = 1;
			ul_temp.ul = U32xU32getlo(PG_Zoffset, SpDt_ulKTheta);  // Npulse of degree -> 2^32
			uwTemp1 = ul_temp.uw.hi;  // 2^16
			zcal_swThetaErr = (SWORD)(uwTemp - uwTemp1);  // 2^16
			if (zcal_swThetaErr>=0){
				zcal_uwPulseErr = U16xU16divU16(zcal_swThetaErr,SpDt_uwAnglePeriod,65535);  // Npulse of degree
			}
			else{
				zcal_uwPulseErr = U16xU16divU16(-zcal_swThetaErr,SpDt_uwAnglePeriod,65535);	// Npulse of degree
			}
			// ] END of 01/15/2008

			zcal_uwPulseDiff = 0;  // Dynamic Z-pulse calibrate, Add by DINO, 08/11/2010

		}
	}

    Zpulse = 2;
    
    

}

// MTU6 TCIV6
void Excep_MTU6_TCIV6(void){ }

// MTU7 TGIA7
void Excep_MTU7_TGIA7(void){ }

// MTU7 TGIB7
void Excep_MTU7_TGIB7(void){ }

// MTU7 TGIC7
void Excep_MTU7_TGIC7(void){ }

// MTU7 TGID7
void Excep_MTU7_TGID7(void){ }

// MTU7 TCIV7
void Excep_MTU7_TCIV7(void){ }

// POE OEI1
void Excep_POE_OEI1(void){
        POE.ICSR1.BIT.PIE1 = 0;        // disable OEI1 interrupt, dino, 06/13/2007

       //if ((POE2.ICSR1.WORD & 0xF000)!=0){ // CC, OC, GFF, OCC Detection
            //POE2.ICSR1.BIT.PIE1 = 0;        // disable OEI1 interrupt, dino, 06/13/2007
        if ((POE.ICSR1.BIT.POE0F)!=0){ // CC, OC, GFF, OCC Detection
           

            //if (POE2.ICSR1.BIT.POE0F==1){   // CC, OC, GFF - POE0
            if (POE.ICSR1.BIT.POE0F==1){   // CC, OC, GFF - POE0  
                // [ Debug OC Detection, DINO, 07/26/2010
                 //POE.ICSR1.BIT.POE0F = 0; //[PWM reopen problem, Jason, 2019/07/04]
                //if (POE2.ICSR2.BIT.POE5F==0 && POE2.ICSR2.BIT.POE6F==0){
                if (POE.ICSR4.BIT.POE10F==0 && POE.ICSR5.BIT.POE11F==0){
                    //POE.ICSR1.BIT.POE0F = 0;
                    PROTECT_CC();
					POE.ICSR1.BIT.POE0F = 0; //[PWM reopen problem, Jason, 2019/07/04]
                }
                else{
                    POE.ICSR4.BIT.PIE4 = 0;
                    POE.ICSR5.BIT.PIE5 = 0;
                    if (POE.ICSR4.BIT.POE10F==1){    // GFF,POE5

                        if ((pr[PROTBIT]&0x0003)==0x0000){   // Bit 0,1: Control GFF Check by POE
                            //POE.ICSR4.BIT.POE10F = 0;
                            PROTECT_GFF();
							POE.ICSR4.BIT.POE10F = 0; //[PWM reopen problem, Jason, 2019/07/04]
                        }
                        else {
                            //POE2.ICSR2.BIT.POE5F = 0;
                            //POE2.ICSR2.BIT.PIE2  = 1;
                            POE.ICSR4.BIT.POE10F = 0;
                            POE.ICSR4.BIT.PIE4  = 1;
                        }
                    }       

                    if ((POE.ICSR5.BIT.POE11F)==1){
                         //POE.ICSR5.BIT.POE11F = 0;
                         PROTECT_OC();
						 POE.ICSR5.BIT.POE11F = 0; //[PWM reopen problem, Jason, 2019/07/04]
                    }
                    POE.ICSR4.BIT.PIE4 = 1;
                    POE.ICSR5.BIT.PIE5 = 1;
                    
                }
                // ]                
				POE.ICSR1.BIT.POE0F = 0; //[PWM reopen problem, Jason, 2019/07/04]
            }
#if 0
            //if (POE2.ICSR1.BIT.POE3F==1){   // OCC - POE3
            if (POE.ICSR2.BIT.POE4F==1){   // OCC - POE3
                POE.ICSR2.BIT.POE4F = 0;
                PROTECT_OCC();
            }

            if (POE.ICSR4.BIT.POE10F==1){    // GFF,POE5
        
                if ((pr[PROTBIT]&0x0003)==0x0000){   // Bit 0,1: Control GFF Check by POE
                    POE.ICSR4.BIT.POE10F = 0;
                    PROTECT_GFF();
                }
                else {
                    //POE2.ICSR2.BIT.POE5F = 0;
                    //POE2.ICSR2.BIT.PIE2  = 1;
                    POE.ICSR4.BIT.POE10F = 0;
                    POE.ICSR4.BIT.PIE4  = 1;
                }
            }       
        
            if ((POE.ICSR5.BIT.POE11F)==1){
                 POE.ICSR5.BIT.POE11F = 0;
                 PROTECT_OC();
            }
 #endif           
        }

        POE.ICSR1.BIT.PIE1 = 1;        // disable OEI1 interrupt, dino, 06/13/2007

}

// POE OEI2
void Excep_POE_OEI2(void){
    POE.ICSR2.BIT.PIE2 = 0;

     if (POE.ICSR2.BIT.POE4F==1){
        PROTECT_OCC();
        POE.ICSR2.BIT.POE4F = 0;
     }

    POE.ICSR2.BIT.PIE2 = 1;
}

// POE OEI3
void Excep_POE_OEI3(void){
    POE.ICSR3.BIT.PIE3 = 0;

        // [ Debug OC Detection, DINO, 07/26/2010
    //if ((POE2.ICSR2.WORD & 0x7000)!=0){ // OV, OC, GFF Detection
    if ((POE.ICSR3.BIT.POE8F)!=0 ){ 
    
        //if (POE2.ICSR2.BIT.POE4F==1){   // OV,POE4
        //if (POE.ICSR3.BIT.POE8F==1){   // OV,POE4

            POE.ICSR3.BIT.POE8F = 0;
            PROTECT_OV();
            if (Error == 0){
                //POE2.ICSR2.BIT.POE4F = 0;
                //POE2.ICSR2.BIT.PIE2  = 1;
                POE.ICSR3.BIT.POE8F = 0;
                POE.ICSR3.BIT.PIE3  = 1;
            }
        //}
    
    }


    POE.ICSR3.BIT.PIE3 = 1;

}

// POE OEI4
void Excep_POE_OEI4(void){
    POE.ICSR4.BIT.PIE4 = 0;
    POE.ICSR5.BIT.PIE5 = 0;

    if (POE.ICSR4.BIT.POE10F==1){    // GFF,POE5

        if ((pr[PROTBIT]&0x0003)==0x0000){   // Bit 0,1: Control GFF Check by POE
            //POE.ICSR4.BIT.POE10F = 0; 
            PROTECT_GFF();
			POE.ICSR4.BIT.POE10F = 0;//[PWM reopen problem, Jason, 2019/07/04]
        }
        else {
            POE.ICSR4.BIT.POE10F = 0;
            POE.ICSR4.BIT.PIE4  = 1;
        }
    }       

    if ((POE.ICSR5.BIT.POE11F)==1){
         //POE.ICSR5.BIT.POE11F = 0;
         PROTECT_OC();
		 POE.ICSR5.BIT.POE11F = 0;//[PWM reopen problem, Jason, 2019/07/04]
    }

    POE.ICSR4.BIT.PIE4 = 1;
    POE.ICSR5.BIT.PIE5 = 1;

    

}

// POE OEI5
void Excep_POE_OEI5(void){

}

// CMP CMP0
void Excep_CMP_CMP0(void){ }

// CMP CMP1
void Excep_CMP_CMP1(void){ }

// CMP CMP2
void Excep_CMP_CMP2(void){ }

// GPT4 GTCIA4
void Excep_GPT4_GTCIA4(void){ }

// GPT4 GTCIB4
void Excep_GPT4_GTCIB4(void){ }

// GPT4 GTCIC4
void Excep_GPT4_GTCIC4(void){ }

// GPT4 GTCIE4
void Excep_GPT4_GTCIE4(void){ }

// GPT4 GTCIV4
void Excep_GPT4_GTCIV4(void){ }

// GPT4 LOCOI4
void Excep_GPT4_LOCOI4(void){ }

// GPT5 GTCIA5
void Excep_GPT5_GTCIA5(void){ }

// GPT5 GTCIB5
void Excep_GPT5_GTCIB5(void){ }

// GPT5 GTCIC5
void Excep_GPT5_GTCIC5(void){ }

// GPT5 GTCIE5
void Excep_GPT5_GTCIE5(void){ }

// GPT5 GTCIV5
void Excep_GPT5_GTCIV5(void){ }

// GPT6 GTCIA6
void Excep_GPT6_GTCIA6(void){ }

// GPT6 GTCIB6
void Excep_GPT6_GTCIB6(void){ }

// GPT6 GTCIC6
void Excep_GPT6_GTCIC6(void){ }

// GPT6 GTCIE6
void Excep_GPT6_GTCIE6(void){ }

// GPT6 GTCIV6
void Excep_GPT6_GTCIV6(void){ }

// RIIC1 EEI1
void Excep_RIIC1_EEI1(void){ }

// RIIC1 RXI1
void Excep_RIIC1_RXI1(void){ }

// RIIC1 TXI1
void Excep_RIIC1_TXI1(void){ }

// RIIC1 TEI1
void Excep_RIIC1_TEI1(void){ }

// RIIC0 EEI0
void Excep_RIIC0_EEI0(void){ }

// RIIC0 RXI0
void Excep_RIIC0_RXI0(void){ }

// RIIC0 TXI0
void Excep_RIIC0_TXI0(void){ }

// RIIC0 TEI0
void Excep_RIIC0_TEI0(void){ }

// DMAC DMAC0I
void Excep_DMAC_DMAC0I(void){ }

// DMAC DMAC1I
void Excep_DMAC_DMAC1I(void){ }

// DMAC DMAC2I
void Excep_DMAC_DMAC2I(void){ }

// DMAC DMAC3I
void Excep_DMAC_DMAC3I(void){ }

// SCI0 RXI0
void Excep_SCI0_RXI0(void){

//if (SCI0.SCSSR.BIT.RDRF==1) {
      uwPG_OverTimeCnt = 0;
      SCI0_RxINT();
  //}

}

// SCI0 TXI0
void Excep_SCI0_TXI0(void){ }

// SCI0 TEI0
void Excep_SCI0_TEI0(void){
  if (SCI0.SSR.BIT.TEND == 1){
      SCI0.SSR.BIT.TEND = 0;
      SCI0_TxINT();
  }

}

// SCI1 RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1 TXI1
void Excep_SCI1_TXI1(void){ }

// SCI1 TEI1
void Excep_SCI1_TEI1(void){ }

// SCI2 RXI2
void Excep_SCI2_RXI2(void){

    SCI2_RxINT();
}

// SCI2 TXI2
void Excep_SCI2_TXI2(void){ }

// SCI2 TEI2
void Excep_SCI2_TEI2(void){
	if (SCI2.SSR.BIT.TEND == 1){
		SCI2.SSR.BIT.TEND = 0;
		SCI2_TxINT();
    }
}

// SCI3 RXI3
void Excep_SCI3_RXI3(void){
    //PORT9.PODR.BIT.B1 ^= 1;
    //PORT9.PODR.BIT.B0 ^= 1;

	    SCI3_RxINT();
}

// SCI3 TXI3
void Excep_SCI3_TXI3(void){ }

// SCI3 TEI3
void Excep_SCI3_TEI3(void){
	if (SCI3.SSR.BIT.TEND == 1){
		SCI3.SSR.BIT.TEND = 0;
		SCI3_TxINT();
    }
}

// GPT0 GTCIA0
void Excep_GPT0_GTCIA0(void){ }

// GPT0 GTCIB0
void Excep_GPT0_GTCIB0(void){ }

// GPT0 GTCIC0
void Excep_GPT0_GTCIC0(void){ }

// GPT0 GTCIE0
void Excep_GPT0_GTCIE0(void){ }

// GPT0 GTCIV0
void Excep_GPT0_GTCIV0(void){ }

// GPT0 LOCOI0
void Excep_GPT0_LOCOI0(void){ }

// GPT1 GTCIA1
void Excep_GPT1_GTCIA1(void){ }

// GPT1 GTCIB1
void Excep_GPT1_GTCIB1(void){ }

// GPT1 GTCIC1
void Excep_GPT1_GTCIC1(void){ }

// GPT1 GTCIE1
void Excep_GPT1_GTCIE1(void){ }

// GPT1 GTCIV1
void Excep_GPT1_GTCIV1(void){ }

// GPT2 GTCIA2
void Excep_GPT2_GTCIA2(void){ }

// GPT2 GTCIB2
void Excep_GPT2_GTCIB2(void){ }

// GPT2 GTCIC2
void Excep_GPT2_GTCIC2(void){ }

// GPT2 GTCIE2
void Excep_GPT2_GTCIE2(void){ }

// GPT2 GTCIV2
void Excep_GPT2_GTCIV2(void){ }

// GPT3 GTCIA3
void Excep_GPT3_GTCIA3(void){ }

// GPT3 GTCIB3
void Excep_GPT3_GTCIB3(void){ }

// GPT3 GTCIC3
void Excep_GPT3_GTCIC3(void){ }

// GPT3 GTCIE3
void Excep_GPT3_GTCIE3(void){ }

// GPT3 GTCIV3
void Excep_GPT3_GTCIV3(void){ }

// SCI12 RXI12
void Excep_SCI12_RXI12(void){ }

// SCI12 TXI12
void Excep_SCI12_TXI12(void){ }

// SCI12 TEI12
void Excep_SCI12_TEI12(void){ }

