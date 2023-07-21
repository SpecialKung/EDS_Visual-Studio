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
#ifndef _Main_C
	#define _Main_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
#include "PR_SinTable.h"
//#include "PR_ACosTable.h"		// Add by dino, 06/08/2007

SLONG (*const mfai_tbl[12])(UBYTE AIsel,SWORD AIsumvar) = {
#if NEWPARA
	AI_no_func,			//0: no function, Modify for new toolchain, DINO, 09/30/2010
    AI_FreqRref,		//1: frequency command
    AI_TorqRef,			//2: Torque Reference
    AI_TorqComp,		//3: Torque Compensation
    AI_no_func,			//4: PID Reference, Modify for new toolchain, DINO, 09/30/2010
    AI_no_func,			//5: PID feedback, Modify for new toolchain, DINO, 09/30/2010
    AI_PTCInput,		//6: Positive Temp Coff input
    AI_PosTqLimit,		//7: Positive Torque Limit
    AI_NegTqLimit,		//8: Negative Torque Limit
    AI_RegenTqLimit,	//9: Regenerate Torque Limit
    AI_PosNegTqLimit,	//10: Positive/Negative Torque Limit
    AI_TorqComp,		//11: Preload		//09/06/2007
#else 	
	AI_no_func,			//0: no function
    AI_FreqRref,		//1: frequency command
    AI_TorqRef,			//2: Torque Reference
    AI_TorqComp,		//3: Torque Compensation
    AI_PIDRef,			//4: PID Reference
    AI_PIDFbk,			//5: PID feedback
    AI_PTCInput,		//6: Positive Temp Coff input
    AI_PosTqLimit,		//7: Positive Torque Limit
    AI_NegTqLimit,		//8: Negative Torque Limit
    AI_RegenTqLimit,	//9: Regenerate Torque Limit
    AI_PosNegTqLimit,	//10: Positive/Negative Torque Limit
#endif 
    
};

// [ Modify for new toolchain, DINO, 09/30/2010
SLONG AI_no_func(UBYTE AIsel,SWORD AIsumvar)  // no function
{
}
// ]

SLONG AI_FreqRref(UBYTE AIsel,SWORD AIsumvar)
{
	SLONG AIslFcmd;
	
	if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
	else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
		
	#if 0
		AIslFcmd = ((SLONG)AIsumvar*pr[FMAX] + ADMAX_2)>>ADBit;
	#else
		AIslFcmd = ((SLONG)AIsumvar*(VcomFmax.uw.hi) + ADMAX_2)>>ADBit;
	#endif
	
	return AIslFcmd;
}

SLONG AI_TorqRef(UBYTE AIsel,SWORD AIsumvar)
{
	SLONG AIslTQRcmd;
	 
	if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
	else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
	
	AIslTQRcmd = (((SLONG)AIsumvar*COF_uwTqMaxPu)+ADMAX_2)>>ADBit;
	// refer to pr[TQRMAX] 07-22

	return AIslTQRcmd;
}

SLONG AI_TorqComp(UBYTE AIsel,SWORD AIsumvar)
{
	SLONG AIslTQRofset;

	if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
	else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
	
	AIslTQRofset = (((SLONG)AIsumvar*COF_uwTqratePu)+ADMAX_2)>>ADBit;
	// refer to rated torque value of INV

	return AIslTQRofset;
}

SLONG AI_PIDRef(UBYTE AIsel,SWORD AIsumvar)
{
	SLONG AIslPIDRef;

	if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
	else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
	
	AIslPIDRef = (((SLONG)AIsumvar*pr[FMAX])+ADMAX_2)>>ADBit;
	
	return AIslPIDRef;
}

SLONG AI_PIDFbk(UBYTE AIsel,SWORD AIsumvar)
{
	SLONG AIslPIDFbk;

	if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
	else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
	
	AIslPIDFbk = (((SLONG)AIsumvar*pr[FMAX])+ADMAX_2)>>ADBit;

	return AIslPIDFbk;
}

SLONG AI_PTCInput(UBYTE AIsel,SWORD AIsumvar)
{
	SLONG AIslPTCin;

	if (AIsumvar > ADMAX)
		AIsumvar = ADMAX;
	else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;

	// [ Only Positive Value, Modify by DINO, 06/17/2009
	// [ Debug by DINO, 06/17/2009
	AIslPTCin = (SLONG)AIsumvar * 1000 >> ADBit;
	if (AIslPTCin < 0){
		AIslPTCin = 0;
	}
	// ]

	return AIslPTCin;
}

SLONG AI_PosTqLimit(UBYTE AIsel,SWORD AIsumvar)
{
    SLONG AIslPosTQRLim;

    if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
    else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;

	// [ Add PM Torque Calculation, DINO, 06/17/2009
	if (pr[CTRLM] == FOCPM){
    	AIslPosTQRLim = (((SLONG)AIsumvar*pr[TQRMAX]*100)+ADMAX_2)>>ADBit;
	}
	else{
    	AIslPosTQRLim = (((SLONG)AIsumvar*COF_uwTqMaxPu)+ADMAX_2)>>ADBit;
    	//AIslPosTQRLim = S16xS16divS16(AIslPosTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)
    	AIslPosTQRLim = S32xS32divS32(AIslPosTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)      //[overflow problem, Bernie, 2017/05/09]
    }
    // ]

    // refer to pr[TQRMAX] 07-22
    return abs(AIslPosTQRLim);
}

SLONG AI_NegTqLimit(UBYTE AIsel,SWORD AIsumvar)
{
    SLONG AIslNegTQRLim;

    if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
    else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
	
	// [ Add PM Torque Calculation, DINO, 06/17/2009
	if (pr[CTRLM] == FOCPM){
    	AIslNegTQRLim = (((SLONG)AIsumvar*pr[TQRMAX]*100)+ADMAX_2)>>ADBit;
	}
	else{
    	AIslNegTQRLim = (((SLONG)AIsumvar*COF_uwTqMaxPu)+ADMAX_2)>>ADBit;
    	//AIslNegTQRLim = S16xS16divS16(AIslNegTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)
    	AIslNegTQRLim = S32xS32divS32(AIslNegTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)     //[overflow problem, Bernie, 2017/05/09]
    }
    // ]

    // refer to pr[TQRMAX] 07-22
    return abs(AIslNegTQRLim);
}

SLONG AI_RegenTqLimit(UBYTE AIsel,SWORD AIsumvar)
{
    SLONG AIslRegTQRLim;

    if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
    else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;

	// [ Add PM Torque Calculation, DINO, 06/17/2009
	if (pr[CTRLM] == FOCPM){
    	AIslRegTQRLim = (((SLONG)AIsumvar*pr[TQRMAX]*100)+ADMAX_2)>>ADBit;
	}
	else{
    	AIslRegTQRLim = (((SLONG)AIsumvar*COF_uwTqMaxPu)+ADMAX_2)>>ADBit;
    	//AIslRegTQRLim = S16xS16divS16(AIslRegTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)
    	AIslRegTQRLim = S32xS32divS32(AIslRegTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)     //[overflow problem, Bernie, 2017/05/09]
    }
    // ]

    // refer to pr[TQRMAX] 07-22
    return abs(AIslRegTQRLim);
}

SLONG AI_PosNegTqLimit(UBYTE AIsel,SWORD AIsumvar)
{
    SLONG AIslPosNegTQRLim;

    if (AIsumvar>ADMAX)
		AIsumvar = ADMAX;
    else if (AIsumvar<(SWORD)(-ADMAX))
		AIsumvar = -ADMAX;
	
	// [ Add PM Torque Calculation, DINO, 06/17/2009
	if (pr[CTRLM] == FOCPM){
    	AIslPosNegTQRLim = (((SLONG)AIsumvar*pr[TQRMAX]*100)+ADMAX_2)>>ADBit;
	}
	else{
    	AIslPosNegTQRLim = (((SLONG)AIsumvar*COF_uwTqMaxPu)+ADMAX_2)>>ADBit;
    	//AIslPosNegTQRLim = S16xS16divS16(AIslPosNegTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)
    	AIslPosNegTQRLim = S32xS32divS32(AIslPosNegTQRLim, 2048, COF_uwKt); //Q15 = Q(12+11-8)      //[overflow problem, Bernie, 2017/05/09]
    }
    // ]

    // refer to pr[TQRMAX] 07-22
    return abs(AIslPosNegTQRLim);
}
/* Constant Table =============================================*/
#if 0
UBYTE DINT(void)
{
	UBYTE imaskbits;
	
	imaskbits = get_imask();
	set_imask(15);
	return imaskbits;
}

void EINT(UBYTE maskbits)
{
	set_imask(maskbits);
}
#endif
#pragma inline_asm DINT
void DINT(void) 
{
      CLRPSW   I
}//End of DINT()
//============================================================================//
#pragma inline_asm EINT
void EINT(void)
{
      SETPSW  I
}//End of EINT()


void WarnDisplaySave(void)
{
    if ((WarnCode==0)&&(Error==0)){
	    Keypad_PageTmp = Keypad_Page;
		Keypad_Page = WarnPAGE;
    }    
}


UWORD ai_transfer(UBYTE AISel,UWORD ai_value,UWORD ai_h,UWORD ai_m,UWORD ai_l)
{
    UWORD ax, bx;

    ax = ai_value;
    
    if (ax >= ai_h)
    	ax = ai_h;
    else if (ax <= ai_l)
    	ax = ai_l;
    
    if (AISel == 3){
    	bx = ai_h - ai_l;
#if SH7149
    	ax = U16xU16divU16((ax - ai_l), ADMAX*5, bx);
#else
    	ax = U16xU16divU16((ax - ai_l), ADMAX, bx);
#endif
    }
    else{
		if (ax >= ai_m){
	    	bx = ai_h - ai_m;
	    	ax = U16xU16divU16((ax - ai_m), ADMAX_2, bx) + ADMAX_2;	// dino, 03/07/2007
		}
		else if ((ax < ai_m) && (ax >= ai_l)){
	    	bx = ai_m - ai_l;
	    	ax = U16xU16divU16((ax - ai_l), ADMAX_2, bx);		// dino, 03/07/2007
		}
    }

    return ax;
}


ULONG cal_time(UWORD f,UWORD t)
{                                           
    ULONG ax;
    
    if (t!=0){
        if (pr[U_ACCDEC]==1)
            // 0.001(1ms)*65536*10(0.1Sec) = 655.36,  0.36 => 0.36*65536 = 23592.96        
            //ax = (((ULONG)f*655)/t) + (((ULONG)f*23593/t)>>16);
		    ax = (U32xU32divU32(f,42949673,((ULONG)t<<16)));
		else
		    // 0.001(1ms)*65536*10(0.01Sec)*10 = 6553.6,  0.6 => 0.6*65536/2 = 19660.8
		    //ax = (((ULONG)f*6553)/t) + (((ULONG)f*19661/t)>>15);
		    ax = (U32xU32divU32(f,429496730,((ULONG)t<<16)));
		
		if (ax==0)
			ax = 1;
	}
	else{
		ax = 0;
	}	
    
    return ax;
}

//------------------------------------------------------------------------------
// struct CarLine, ksI, ksF, yBias
// CalLine AD2DcB1, AD2DcB2,      
     // AD to DC Bus Line 1[(x1,y1),(x2,y2)], Line 2[(x2,y2),(x3,y3)]
//        DcB2AD1, DcB2AD2;
     // DC Bus to AD Line 1[(x1,y1),(x2,y2)], Line 2[(x2,y2),(x3,y3)]
//---[ 2 point to get Line Equation ]
//- input  (x1,y1), (x2,y2)
//- output  slope = mi, mf, offset = B

void LineEqu(CalLine *xline, SWORD x1, SWORD y1, SWORD x2, SWORD y2)
{
     SWORD ax, bx;
     ULONG cx, dx;
     
     ax = y2-y1;
     bx = x2-x1;
     // get Slope of Line
//     if(ax > bx){
	 if(ax >= bx){				//modify SCOTTY 2007/08/16
        (*xline).ksI = ax/bx;
        (*xline).ksF = (((ULONG)(ax-(*xline).ksI*bx))<<16)/bx;
     }
     else {
       (*xline).ksI = 0;
       (*xline).ksF = (((ULONG)ax)<<16)/bx;
     }

     // get Bias of Line
     cx = (ULONG)x2*y1;
     dx = (ULONG)x1*y2;
     (*xline).yBias = (SLONG)(cx-dx)/bx;

}


void VBusLineInit(void)
{
    SWORD swTemp;

    if ((pr[HPSPEC]&VFD440V)==VFD440V){       // 440V class
        //---[ DC_Bus(0.1V) = slope*AD + Bias ]---- 06262003 ----------
        LineEqu(&AD2DcB1, pr[DCB_AD1], 4200, pr[DCB_AD2], 6200);     // (x1,y1) (x2,y2)
        LineEqu(&AD2DcB2, pr[DCB_AD2], 6200, pr[DCB_AD3], 7800);     // (x2,y2) (x3,y3)

        //---[ AD = slope*DC_Bus(1V)  + Bias ]----- 06272003 ----------
        LineEqu(&DcB2AD1, 4200, pr[DCB_AD1], 6200, pr[DCB_AD2]);     // (x1,y1) (x2,y2)
        LineEqu(&DcB2AD2, 6200, pr[DCB_AD2], 7800, pr[DCB_AD3]);     // (x2,y2) (x3,y3)
          
        OVS4ad = Vdc2ADC(8300);                 // 830.0Vdc
        OVR4ad = Vdc2ADC(7470);                 // 0.9 * ov_set
        LVS4ad = Vdc2ADC(pr[LVL]);              // 396.0Vdc = 280Vac
        LVR4ad = Vdc2ADC(pr[LVL]+600);          // LV + 60.0V
        LV4FAN = Vdc2ADC(3600);					//Fan start low voltage level

    }
    else{
        //---[ DC_Bus(0.1V) = slope*AD + Bias ]---- 06262003 ----------
        LineEqu(&AD2DcB1, pr[DCB_AD1], 2100, pr[DCB_AD2], 3100);     // (x1,y1) (x2,y2)
        LineEqu(&AD2DcB2, pr[DCB_AD2], 3100, pr[DCB_AD3], 3900);     // (x2,y2) (x3,y3)

        //---[ AD = slope*DC_Bus(1V)  + Bias ]----- 06272003 ----------
        LineEqu(&DcB2AD1, 2100, pr[DCB_AD1], 3100, pr[DCB_AD2]);     // (x1,y1) (x2,y2)
        LineEqu(&DcB2AD2, 3100, pr[DCB_AD2], 3900, pr[DCB_AD3]);     // (x2,y2) (x3,y3)
          
        OVS4ad = Vdc2ADC(4150);                 // 415.0Vdc
        OVR4ad = Vdc2ADC(3735);                 // 0.9 * ov_set
        LVS4ad = Vdc2ADC(pr[LVL]);              // 396.0Vdc = 280Vac
        LVR4ad = Vdc2ADC(pr[LVL]+300);          // LV + 30.0V
		LV4FAN = Vdc2ADC(1800);					//Fan start low voltage level
    }

    swTemp = Vdc2ADC(pr[STALL4V]);
    if ((SWORD)swTemp<0)
        stall4ad = 0;
    else
        stall4ad = swTemp;

    dcbrk4ad = Vdc2ADC(pr[DCBRK4V]);
	dcbrk4ad2= Vdc2ADC(pr[DCBRK4V]-pr[DCBRK_BAND]);// [DCBRK_BAND function for adjustable reset level, James, 2019/12/05  ]   
    dcbusADAVG = dcbusAD;
//    uwPHLADLevel = Vdc2ADC(1500 + pr[PHL_L]);	//SCOTTY 09/05/2007  del 10/18/2007
	uwPHLADLevel = pr[PHL_L];					//SCOTTY 10/18/2007

}

/*======== DCBus calculate =================================================*/
// AD voltage = [DcBus * (1/20) * (3/15) - 1.5v] * (10/7)                   //
//     (Dcbus - 150v) * 5v /(500v - 150v)                                   //
//     0v     -> 150v Dcbus -> 0 adc                                        //
//     5v     -> 500v Dcbus -> 1023 adc                                     //
//     4.28v  -> 450v Dcbus -> 877  adc (Over Voltage)                      //
//     0.57v  -> 190v Dcbus -> 117  adc (Under Voltage)                     //
//==========================================================================//
UWORD ADC2Vdc(UWORD adc_value)
{
        UWORD  vdc_value;

        if(adc_value >= pr[DCB_AD2]){
          vdc_value = (((ULONG)adc_value*AD2DcB2.ksF)>>16)+(adc_value*AD2DcB2.ksI)+AD2DcB2.yBias;
        }
        else{
          vdc_value = (((ULONG)adc_value*AD2DcB1.ksF)>>16)+(adc_value*AD2DcB1.ksI)+AD2DcB1.yBias;
        }
        return vdc_value;
}


UWORD Vdc2ADC(UWORD vdc_value)
{
        UWORD  adc_value;

        if ((pr[HPSPEC]&VFD440V)==VFD440V){       // 440V class
          if (vdc_value >= 6200)
            adc_value = (((ULONG)vdc_value*DcB2AD2.ksF)>>16)+(vdc_value*DcB2AD2.ksI)+DcB2AD2.yBias;
          else
            adc_value = (((ULONG)vdc_value*DcB2AD1.ksF)>>16)+(vdc_value*DcB2AD1.ksI)+DcB2AD1.yBias;
        }
        else{
          if (vdc_value >= 3100)
            adc_value = (((ULONG)vdc_value*DcB2AD2.ksF)>>16)+(vdc_value*DcB2AD2.ksI)+DcB2AD2.yBias;
          else
            adc_value = (((ULONG)vdc_value*DcB2AD1.ksF)>>16)+(vdc_value*DcB2AD1.ksI)+DcB2AD1.yBias;
        }

        return adc_value;
}

void stop_status(void)
{
    UWORD uw_TUNtemp, PGFbkCnt;
    
    WGOFF;
    
    //[ //[New OPHL Function,Jerry.SK,2019/12/28]
	OPHL_Init();
    //] //[New OPHL Function,Jerry.SK,2019/12/28]
    
    inv_status.ub 	 = 0;		// RUNNING=STOP
    pre_status.uw 	&= 0x0c00;	// Modify by DINO, 03/13/2009
    // Add MPHL_DET=0, DINO, 05/12/2009
    RUN_sequence.uw &= 0x01bb;	// RUN_GOING=0, MPHL_DET = 0; ADD BY DINO, 05/12/2009, 06/24/2010
    // ]
     
     
   if(WRITE_PR_ATONCE==1 ){  //[EDS parameter at once,sampo,2018/02/05]
   	  if(uwWritePrCnt<200){
   	  	 uwWritePrCnt++;
   	  }
   }
   

	// [ Clear Generation_Operation Flag, DINO, 04/27/2010
	if(pr[CTRLM]> SVC || !EPS_STOP ){ //[EPS, Sampo, 03/27/2011]
	    if((PR_ubEpsOptMod<3)||(PR_ubEpsOptMod==4)){          //[Modify EPS function, Bernie, 2012/11/27 ] //[EPS auto detect direction,Lyabryan,2018/07/16]
	        PWM_Status.ub &= 0x85;		//	GEN_START=0, GENDIR=0, GEN_OK=0, GEN_OK2_DIR=0, GEN_OK3=0
	        uwEPScnt = 0;
            TB1_uwGencnt = 0;
        }
        else{                        //[Modify EPS function, Bernie, 2012/11/27 ]
            if(EPS == 0){
                PWM_Status.ub &= 0x85;		//	GEN_START=0, GENDIR=0, GEN_OK=0, GEN_OK2_DIR=0, GEN_OK3=0
	            uwEPScnt = 0;
                TB1_uwGencnt = 0;
            }
        }
	}
	// ]

    if (CTRLMCHG==1){
        pr[CTRLM] = CTRLM_buf;
        CTRLMCHG = 0;
    }

	if ( ACI_LOSS ){ swACICalib = 0; }  // Add by dino, 03/27/2008

//    pre1_status.ub = 0;
        
	ftemp.ul = 0;
	fcmd.ul = 0;
	fcmd_vf.ul = 0;
	fout.ul = 0;        
	fhunt.sl = 0;
	//slMotorHz = 0;//James, 2021/08/09

	Fcmd = 0;
	sacc.ul = 0;
	sdec.ul = 0;
	
	Vcmd_LL = 0;
	VF_Vcmd = 0;
	vcmd_ser = 0;
	vtemp = 0;
	v_save = 0;

	tq_boost = 0;
	nl_boost = 0;
	adjcnt = 0;

	Ismax_uwPu = 0;
	prt_OLIrms.ul = 0;		// Add by dino, 08/21/2007
	IrmsRe = 0;
//	slIrmsReLPF = 0;
	IrmsReLPF.sl = 0;	// Add by DINO, 03/08/2009

	PF_ANGLE = 0;
    SLOWSPSTR = 0;  //[Dwell S curve,Lyabryan,2018/11/21]
    SLOWSPSHOW = 0; //[Dwell S curve,Lyabryan,2018/11/21]
	TorqueOut = 0;
	PowerInRe = 0;
	Pinput.ul = 0;

	TUNErrorCnt = 0;

	TB1_slSpdCmdPu = 0;
	TB1_slSpdAcc = 0;		//ADDED BY SCOTTY 01/04/2007
	SPR_slSpdRefPu = 0;
	SPR_slSpdFdbPu = 0;
	//Delta_theta = 0;

    TB1_uwBrkRunCnt  = 0;			// dino, 12/12/2007
    TB1_uwBrkStopCnt = 0;			// dino, 12/12/2007

	RUNDCI = 0;
	STOPDCI = 0;
	TB1_uwDCICnt = 0;
	TUN_uwPMTunCnt = 0;			//ADDED BY SCOTTY 01/29/2007
	TUNEPMLSLOW_V = 0;			//ADDED BY SCOTTY 01/29/2007

	CMDJOG = 0;
	WGDIR = CMDDIR;
	CMDDIR2 = CMDDIR;

//	if ((pr[STOPM]==1)||(Error!=0)) // P1.00 STOP Methods.
//		CMDFREE = 1;
//	else
//		CMDFREE = 0;

	if (pr[KEB_RT]!=0)
		KEB_ON = 0;

    CMDRUN = STOP;
    NORMALSP = 0;
    EXT_FORCESTOP = 0;
    EXT_COASTSTOP = 0;
    HOLD = 0;


// [ Short_Circuit Detection, DINO, 05/19/2010
	prt_ubBRStatus = CHARGE_START;
	// ]
  //  DCBUSREC = 1;
    dcbusDCInit = dcbusDC;
    
	WARNSTOPREC = 0;		//09/05/2007

	if (WarnCode!=0){
        if ((WarnCode==PID_WARN || (WarnCode>=PGFBK_WARN && WarnCode<=PHL_WARN) || WarnCode==oSL_WARN || WarnCode==tUn_WARN ) && WarnCode!=PGL_WARN ){	// Add by Dino, 01/23/2008   // [Warning initial, Lyabryan, 2015/03/12]
        	WarnCode = 0;
        	Keypad_Page = pr[S_DISP];
        	Keypad_PageTmp = 0;
    	}
    }      

    switch(pr[CTRLM]){
        default:
        case VF:
        case VFPG:
        case SVC:
            Init_VF();
            break;
        case FOC:
            Init_FOC();
            break;
        case FOCPG:
#if SCOTTY    	    
        case FOCPM:				//ADDED BY SCOTTY	01/29/2007 
#endif
        case TQCPG:
            Init_FOCPG();
            break;
            
    	case DBCSECA:
            break;    	        
    }

	// [ If MPHL detection doesn't complete, save the buffer to STtune, Add by DINO, 05/12/2009
	if (TB1_swMPHLstep != 4){
		STtune = TB1_MPHL_Buf;
		TB1_swMPHLstep = 4;
	}
	// ]

 	uw_TUNtemp = pr[AUTO_T] + pr[PM_AUTO_T];
    if ((uw_TUNtemp!=0)&&(TUN_START==1)&&(TUN_OK==0)){
    	// [ Save tunning result only if Error=0, Modify by DINO, 05/14/2009
    	if (Error == 0){
    	// ]
        	if (TUN_ROTARY_OK==1){
           		TUN_ROTARY_OK = 0;
          		TUN_NLRotary_OK();	//SCOTTY 03/19/2008	MODIFY
          	}    		
        	switch(pr[AUTO_T]){
            	case 1:
            	case 2:
            	case 3:
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        	    	COF_uwRsPu = TUN_uwRsPu;
        	    	COF_uwRrPu = TUN_uwRrPu;
        	    	COF_uwLmPu = TUN_uwLm1Pu;
        	    	COF_uwLxPu = TUN_uwL1sigmaPu;
        	    	COF_uwI0Pu = TUN_uwI0Pu;
	            	//Tr_inv,  = (Lm/Rr) in Q(15+13-6)
                	COF_Tr_inv = U16xU16divU16(COF_uwRrPu, 8192, COF_uwLmPu); //Q22
                	//IdsLPG = T*1/Tr = T*Rr/Lm = T*(RrPu/LmPu)*(Rb/Lb) = 2*pi*Fb*100us*Tr_inv
                	//24707 = 2*pi*Fb*100us*2^16
                	COF_uwIdsLPG = ((ULONG)24707 * COF_Tr_inv) >> 22; //Q16=Q(16+22-22)

                	//For Te = Kt * Iq
   	            	COF_uwKt = ((ULONG)COF_uwLmPu * COF_uwI0Pu) >> 13; //Q8 = Q(6+15-13)    
#endif
                	WRITE_TUNPR = 1;        
                	break;
            	case 10:
                	WRITE_CCBPR = 1;
                	//PFC.PECRL4.WORD |= 0x1111;
                	//PFC.PECRL3.WORD |= 0x1010;
                	MPC.P76PFS.BYTE = 0x01;
                    MPC.P75PFS.BYTE = 0x01;
                    MPC.P74PFS.BYTE = 0x01;
                    MPC.P73PFS.BYTE = 0x01;
                    MPC.P72PFS.BYTE = 0x01;
                    MPC.P71PFS.BYTE = 0x01;
                	break;
            	default:
                break;
        	}
        
			switch(pr[PM_AUTO_T]){
			//---- added by scotty	2007/06/07----------
	        	case 1:
	        	case 3:  // 08/11/2008
	        		// [ Set STtune=0 if pr[Z_OFFSET] tuning okay, DINO, 05/11/2009
	        		STtune_Buf = 0;
	        		ZCALIB = 1;  // Add by DINO, 11/27/2009
                	WRITE_TUNZOFFSET = 1;
                	// ]
                	break;
			//---- END	2007/06/07----------
			//---- added by scotty	2006/09/04 ---------
	        	case 2:
#if OLD_SETTING  // Modify by DINO, 09/09/2008
       	        	COF_uwRsPu = TUN_uwRsPu;
       	        	COF_uwLxPu = TUN_uwL1sigmaPu;	//ADD 10/05/2007 SC
#endif
               		WRITE_TUNPMPR = 1;
                	break;
			//---- END	2006/09/04----------
            	default:
                	break;
			}      
		}    	
       	TUN_START = 0;
       	TUN_OK = 1;
       	uwFkeypad = Fkeypad_Buf;
       	pr[AUTO_T] = 0;
       	pr[PM_AUTO_T] = 0;
	    STtune = STtune_Buf;  /* add by dino, 04/03/2007 */
    }


	/*-----------------------------------------------------------------
	-- Treatment of EnDat/Hiperface Static Tuning, DINO, 05/11/2009
	-----------------------------------------------------------------*/
	if ( pr[PM_AUTO_T]==3 && STtune==1 ){

    	if (Error==0){

//--- EnDat Static tuning, Add by DINO, 08/29/2008
			if (pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER){

				uw_TUNtemp = PM_uwStart - st_uwPGThetaM;

				if ( PGDIR==0 ){
					uw_TUNtemp = -uw_TUNtemp;
				}

				if ((uw_TUNtemp&0x8000) == 0x8000){
					uw_TUNtemp += SpDt_uwAnglePeriod;
				}
				else if (uw_TUNtemp > SpDt_uwAnglePeriod){
					uw_TUNtemp -= SpDt_uwAnglePeriod;
				}

				PG_Zoffset = uw_TUNtemp;

				WRITE_ZSECT = 1;

				STtune_Buf = 0;

				ZCALIB = 1;  // Add by DINO, 11/27/2009
			}
            else if(/*(pr[PG_TYPE]==SIN_ENDAT) ||	*/	// fix 1313 z offset, Sean, 06/25/2012
 				((pr[PG_TYPE]==SIN_SIN && (NEWHSDSTUNE==1 && ((pr[SysControl]&0x0200)==0x0200))))){     // [IED 1387 static Tune, 2011/07/06]
 				                                                                //[Modify PGHSD01 function, Bernie, 2012/02/05]
				// [ 	// fix motor parameter not save at 1387 static tune, Sean, 05/24/2012
				// trace to WRITE_TUNPMPR = 1. corresponding func not work at 1387 static tune
				//WRITE_TUNPMPR = 1;		//[IED 1387 static Tune, Bernie ,2012/11/20]
				WRITE_TUNZOFFSET = 1;
	   			STtune = 0;
				// ]	
			
                  uw_TUNtemp = PM_uwStart - uwPGThetaE_COM2;

				if ( PGDIR==0 ){
					uw_TUNtemp = -uw_TUNtemp;
				}

				if ((uw_TUNtemp&0x8000) == 0x8000){
					uw_TUNtemp += SpDt_uwAnglePeriod;
				}
				else if (uw_TUNtemp > SpDt_uwAnglePeriod){
					uw_TUNtemp -= SpDt_uwAnglePeriod;
				}

				PG_Zoffset = uw_TUNtemp;

				WRITE_ZSECT = 1;

				STtune_Buf = 0;

				ZCALIB = 1;  // Add by DINO, 11/27/2009	// finish z calibration: no need to find start point for next run, Sean
			}
//--- End on 08/29/2008
		}

		TUN_SS = 0;

		STtune = STtune_Buf;

		pr[PM_AUTO_T] = 0;
	}
	//----------------- Treatment of Static Tune Ending ---------------//

    if (pr[MOTORSEL]==1){
	    if ((YDSetBit&0x03)==0x03){	// Y-Connected
	        MFO_YCON = 1;                
            MFO_DCON = 0;
            YOnCNT = pr[YDDELAYT];                
            DOnCNT = 0;
            YDWGON = 1;
	    }        
    }
    else{
	    if ((YDSetBit&0x30)==0x30){	// Delta-Connected
	        MFO_YCON = 0;                
            MFO_DCON = 1;
            YOnCNT = 0; 
            DOnCNT = pr[YDDELAYT];
            YDWGON = 1;
	    }
    }
		
    APR_status.uw &= 0x4801;	//Position Command is controlled by MFIO
//    APR_status1.ub &= 0x48;	//keep Bit3 (APRFirstGo) & Bit6 (APR_ZChkFlag)
    APR_uwZpulseCnt = 0;
    if (EXT_SPD2POS==0)
        APR_uwPGHome = pr[PGHOME];
    else
        APR_uwPGHome = pr[PMI1+speed-1];

    Psacc.ul = 0;
    PcurveReach = 0;
    APRExeFlag = 0;
    STOPgoAPR = 0;    //in stop_status()
    APR_uwPCom = 0;			
    APR_uwPFbk = 0;
    APR_uwThetaO2 = APR_uwThetaNoMx;
    //APR_uwPFbk = 0;
    APR_uwPGCycle = 0;
    APR_slSpdCmd = 0;
    PsaccMax.ul = 0;
    Psacc.ul = 0;
    APR_uwOnPCNT = 0;

    //MTU22.TCNT = 0; //PG2 Counter
    MTU2.TCNT = 0; //PG2 Counter      //PG2 NO USED
    PG2_uwTheta = 0;
    PG2_uwCNTNew = 0;
    PG2_uwCNTOrg = 0;

	// [ PPI Data Clear, DINO, 07/29/2010
	uw_SCTEST8 =0;
	SPR_swTqOfstPu = 0;		// New PPI Control, Add by DINO, 07/27/2010
	SPR_TqOfstPu.sl = 0;	// New PPI Control, Add by DINO, 07/29/2010
	ZEROSERVO = 0;			// Add by DINO, 05/16/2011
	UNI_ZEROSERVO = 0;		// Add by DINO, 05/16/2011
	ZEROSERVOEND = 0;		// Add by DINO, 05/16/2011
	// ]
    //[PPI decrease cause Speed error,Jerry.sk,2020/04/15]
	SPR_swPPI_Cmp = 0;
	SPR_blPPI_Cmp_Updat_Flag =0;
	COF_flPPI_Cmp = (0.762951f )* pr[I_RATE]/COF_uwMIrRe;	// ref below torque limit, and 0.762951f = 10000/13107
#if SCOTTY 				//SCOTTY 01/15/2008
    if (zcal_swThetaErr != 0){

    	//uw_TUNtemp = MTU21.TCNT;
        uw_TUNtemp = MTU1.TCNT;

		PGFbkCnt = zcal_uwPulseErr - zcal_uwPulseDiff;  // Dynamic Z-pulse calibrate, Add by DINO, 08/11/2010

    	if (PGDIR==1){
    		if (zcal_swThetaErr>=0)
    			//MTU21.TCNT = uw_TUNtemp - PGFbkCnt;
                MTU1.TCNT = uw_TUNtemp - PGFbkCnt;
    		else
    			//MTU21.TCNT = uw_TUNtemp + PGFbkCnt;
                MTU1.TCNT = uw_TUNtemp + PGFbkCnt;
    	}
    	else{
    		if(zcal_swThetaErr>=0) 
    			//MTU21.TCNT = uw_TUNtemp + PGFbkCnt;
                MTU1.TCNT = uw_TUNtemp + PGFbkCnt;
    		else
    			//MTU21.TCNT = uw_TUNtemp - PGFbkCnt;
                MTU1.TCNT = uw_TUNtemp - PGFbkCnt;
    	}

		zcal_swThetaErr = 0;
		zcal_uwPulseErr = 0;
		zcal_uwMTU1cnt = MTU1.TCNT;//---Aevin addto record TCNT--6/22/2017
    }
#endif 
    if(pr[Client_Mode] != 0)
    {
        btArtemisEnable = 1;
    }
    else
    {
        btArtemisEnable = 0;
    }

}
void Driver_ID_Rec(void){
    
    //[ //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
    if((DRIVER_ID_PIN_RE1==0)&&(DRIVER_ID_PIN_RE2==0)) 
        Driver_ID = EDS_DRIVER;
    else if((DRIVER_ID_PIN_RE1==1)&&(DRIVER_ID_PIN_RE2==0))
        Driver_ID = IEDS_DRIVER;
    else if((DRIVER_ID_PIN_RE1==0)&&(DRIVER_ID_PIN_RE2==1))
        Driver_ID = NULL;
    else
        Driver_ID = NULL;
    //] //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
    
}

void InitValue(void)
{
    UBYTE ubMCChk, ubBKChk1,ubBKChk2, HPSPEC_temp;  //[change for EN81-1+A3, Bernie, 2015/03/16]				
    UWORD i;
    UWORD ax, bx;
    UWORD k, px, j;
    SLONG slSpdLimRe;
    SWORD swTemp;

    void (*mfi_ptr)(UWORD ,UWORD);

    RST316J = 0;		   

    
// [ Modify by Dino 03/03/2010---
    //POE2.ICSR1.WORD &= 0x0FFF;
    //POE2.ICSR2.WORD &= 0x0FFF;
    POE.ICSR1.WORD &= 0x1103;
    POE.ICSR2.WORD &= 0x1103;
    POE.ICSR3.WORD &= 0x1303;
    POE.ICSR4.WORD &= 0x1303;
    POE.ICSR5.WORD &= 0x1303;

	// END 06/13/2007 ]
    //POE2.ICSR1.BIT.PIE1 = 1;
    //POE2.ICSR2.BIT.PIE2 = 1;
    POE.ICSR1.BIT.PIE1 = 1;
    POE.ICSR2.BIT.PIE2 = 1;
    POE.ICSR3.BIT.PIE3 = 1;
    POE.ICSR4.BIT.PIE4 = 1;
    POE.ICSR5.BIT.PIE5 = 1;

	k = SpDt_uwPGErrTmp;

    /*==== Initial All Variable ============================================*/
    if ((CPUError&0x8F)!=0)
	    Error = CPUError;
    else
        Error = 0;

    TB1_swPGQualityDsp = 0;    //[PG quality function, Bernie, 2017/06/20]

    uwFaultBitCode = 0;    
    WarnCode = 0;
    SpDt_uwPGErrTmp = 0;

    inv_status.ub = 0;    
    inv1_status.ub = 0;
    inv2_status.ub = 0;
    //STO_status.ub = 0;  //[Safty function, Bernie, 2013/10/29]//James, 2021/10/25
    SMTRISE_status.ub = 0; //[KEB ESD&ETS Function/Lyabryan/2018/08/10]


//	copy_status.ub = 0;

    mfi0_status.ub	= 0;
    mfi1_status.ub	= 0;
    mfi2_status.ub	= 0;
    RUN_DCI_OK = 0;
//    IEDPG_status.uw = 0;   //[For IED PG-Card, Sampo, 02/25/2010]

    UCMP = 0;           //[UCMP function, Bernie, 2016/06/14]  
    
    warn_status.ub	= 0;
    err_status.uw  &= 0xfc40;	// Modify by DINO, 12/01/2008
    ext_status.ub	= 0;
    ext1_status.ub	= 0;
    ext2_status.ub	= 0;
    ext3_status.ub	= 0;
    key_status.uw  &= 0x0802;    	// Skip KEYEND flag
    led_status.ub	= 0;
    cmd_status.ub.low = 0;		// Modify by DINO, 07/21/2008
    kpd1_status.ub	= 0;
    kpd3_status.ub &= 0x41;		// Skip PUEN,PUON flag
//	tb_status.ub	= 0;		// Delete by DINO, 08/29/2008
    wg_status.uw	= 0;		// Modify by DINO, 07/21/2008
    wg_status_CC.uw = 0;        //[CC Display, Bernie, 2017/04/12]
//	wg1_status.ub	= 0;		// Delete by DINO, 07/21/2008
    tun_status.uw	= 0;		// Modify by DINO, 07/21/2008
//	tun1_status.ub	= 0;		// Delete by DINO, 07/21/2008
	pre_status.uw  &= 0x0c00;	// Modify by DINO, 03/13/2009
	pg_status.ub	= 0;
    WREP_status.ub	= 0x10;
    APR_ubZChkCnt	= 0;		//ADDED BY SCOTTY	02/27/2007
    uw_SCTEST7		= 0;		//ADDED BY SC 12/31/2007
	uw_SCTEST8		= 0;		//ADDED BY SC 03/11/2008
  #if 1
    APR_status.uw &= 0x4801;	//Position Command is controlled by MFIO
//    APR_status1.ub &= 0x48;	//keep Bit3 (APRFirstGo) & Bit6 (APR_ZChkFlag)  
  #else
    APR_status.uw = 0;
//    APR_status1.ub = 0;
  #endif
    Con1_status.ub = 0;
    if ((pr[DEBUG_F1]&0x8000)==0x8000)  // Bit 15: VH mode
    	VH_status.ub &= 0x01;
    else
    	VH_status.ub = 0; 

       	IEDPG_status.uw &= 0x40;  //[For IED PG-Card, Sampo, 02/25/2010]

    APRCMDDIR = CMDDIR;
    CMDDIR2 = CMDDIR;

	TUN_DCVolt_OK = 0;

    fkey.ul = 0;
    fcmd.ul = 0;
    ftemp.ul = 0;
    fcmd_vf.ul = 0;
    fout.ul = 0;

    Vcmd_LL = 0;
    Fcmd = 0;
    fexternal.ul = 0;
    fhunt.sl = 0;
    TB1_slSpdCmdPu = 0;
    VF_SlipLPF.sl = 0;
    VF_swSlip = 0;
    SpDt_swNoground_CNT = 0; //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
    prt_ubPHLCnt = 0;
    uwPHLCNTsec = 0;
	TB1_uwFanCnt  = 0;
	TB1_uwFanCnt1 = 0;
    uwMaxDcbus = dcbusAD;   // initial max dcbus and min dcbus (PHL)	09/05/2007
    uwMinDcbus = uwMaxDcbus;	//	09/05/2007
    
    CopyChk = 0;
    
    prt_ubSRYCnt = 0;		// dino, 04/02/2007

    TB_500us = 0;
    Delay4oc = 0;
    
    trg_cnt = 0;
	// [ Clear "prt_ubBFChkCnt", Add by DINO, 02/20/2009
	prt_ubBFChkCnt = 0;
	// ]

	// MPHL Initial Step is 4, Add by DINO, 05/12/2009
	TB1_swMPHLstep = 4;
	// ]
 
    //uwPDO_CNT = 0;    // [CAN Protocol for High Cap, Bernie, 09/22/2011] 

    //[STO ]
    //TB1_uwSTOErrCnt = 0;//James, 2021/10/25
    //uw_STOStatusOld = 0;
    //uw_STOStatus = 0;
    RST_Status.ub = 0;      //[Add auto restart after fault, Bernie, 06/06/12]
   
    /*==== Load EEPROM Datat from 93c86 & Check Parameter Value ============*/
    LoadEPData();
    //frm_vdDLCRead();
    DLC_PR_initial();

	//--- Write Buffer Data to RAM, Add by DINO, 10/27/2008
	pr[ERR_REC1] = rec_uwFault1;
	pr[ERR_REC2] = rec_uwFault2;
	pr[ERR_REC3] = rec_uwFault3;
	pr[ERR_REC4] = rec_uwFault4;
	pr[ERR_REC5] = rec_uwFault5;
	pr[ERR_REC6] = rec_uwFault6;
    //[special,increase error record, 2018/09/20
    pr[FOUT_REC1] = rec_uwError1_1;
    pr[DCBUS_REC1]= rec_uwError1_2;
    pr[ISUM_REC1] = rec_uwError1_3;
    pr[TH_TEMP1]  = rec_uwError1_4;
    pr[FOUT_REC2] = rec_uwError2_1;
    pr[DCBUS_REC2]= rec_uwError2_2;
    pr[ISUM_REC2] = rec_uwError2_3;
    pr[TH_TEMP2]  = rec_uwError2_4;
    pr[FOUT_REC3] = rec_uwError3_1;
    pr[DCBUS_REC3]= rec_uwError3_2;
    pr[ISUM_REC3] = rec_uwError3_3;
    pr[TH_TEMP3]  = rec_uwError3_4;
    pr[FOUT_REC4] = rec_uwError4_1;
    pr[DCBUS_REC4]= rec_uwError4_2;
    pr[ISUM_REC4] = rec_uwError4_3;
    pr[TH_TEMP4]  = rec_uwError4_4;
    pr[FOUT_REC5] = rec_uwError5_1;
    pr[DCBUS_REC5]= rec_uwError5_2;
    pr[ISUM_REC5] = rec_uwError5_3;
    pr[TH_TEMP5]  = rec_uwError5_4;
    //special,increase error record, 2018/09/20]
	pr[FFBK_REC] = rec_uwFfbk;
	pr[FOUT_REC] = rec_uwFcmd;
	pr[VOUT_REC] = rec_uwVout;
	pr[DCBUS_REC]= rec_uwDcbus;
	pr[ISUM_REC] = rec_uwIsum;
	pr[TH_TEMP]  = rec_uwIGBT;
	pr[SRYREC]   = rec_uwSRY;
	pr[PWR_MIN]  = rec_uwPWRmin;
	pr[RUNMIN]   = rec_uwRUNmin;
	pr[TQREF]	 = TQRCMemswPer;
	pr[FMAIN]    = uwFkeypad;
	pr[FCMAIN]   = C20xx[0x01];
	pr[MI_INV]   = MI_INVMem;
	pr[MO_INV]   = MO_INVMem;
	pr[PGHOME]   = PGHOMEMem;
	// [ Add Fault Record Data, DINO, 06/11/2009
	pr[ERR_MIN1] = rec_uwErrMin1;
	pr[ERR_DAY1] = rec_uwErrDay1;
	pr[ERR_MIN2] = rec_uwErrMin2;
	pr[ERR_DAY2] = rec_uwErrDay2;
	pr[ERR_MIN3] = rec_uwErrMin3;
	pr[ERR_DAY3] = rec_uwErrDay3;
	pr[ERR_MIN4] = rec_uwErrMin4;
	pr[ERR_DAY4] = rec_uwErrDay4;
	pr[ERR_MIN5] = rec_uwErrMin5;
	pr[ERR_DAY5] = rec_uwErrDay5;
	pr[ERR_MIN6] = rec_uwErrMin6;
	pr[ERR_DAY6] = rec_uwErrDay6;
	pr[FKEY_REC] = rec_uwFkey;
    pr[POWER_REC]= rec_uwPower;
    pr[TQ_REC]  = rec_uwTorq;
    pr[MFI_REC]  = rec_uwMFI;
    pr[MFO_REC]  = rec_uwMFO;
	pr[STATE_REC]= rec_uwState;
	
	//pr[RESETCNT]= rec_uwRetryCnt;     //[Add auto restart after fault, Bernie, 06/06/12]
	// ]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	pr[Lift_SPD_RPM] = (120*(flMetric2Hz(pr[Lift_SPD])/100))/COF_uwPole;//[Sibocom Lift speed(11-01) convert to moter speed, Jason, 20200110]
#endif
    //--------------- Star contactor function ---------------//
    for(j=RLY1;j<=MO4;j++){
        if(pr[j] == MFO_STAR_CON){
            STAR_CONTACTOR = 1;
        }
    }
  
    for(i=0;i<=49;i++){ //[Last Key parameter,Lyabryan,2020/02/05]
            RSP_uwRecent[49-i] = pr[UMAP_ADD50+i];
    }

    // If load EPROM data error, then load default data
    if (Error==cF2_ERR) {
        for (j=0; j<EPMAX; j++)
            pr[j] = attr[j].def;
        for(j=0; j<DLCMAX; j++)
            DLCxx[j] = 0;
    }
    
        
    HPSPEC_temp = pr[HPSPEC];          //[Single phase input, Bernie, 01/19/2012]
    if(pr[HPSPEC]>VFD_SINGLEPHASE)
        HPSPEC_temp -= VFD_SINGLEPHASE;
    //if (pr[HPSPEC] > MAXMODELNO)
    if(HPSPEC_temp > MAXMODELNO)    //[Single phase input, Bernie, 01/19/2012]
    	pr[HPSPEC] = VFD110V23A;	// Modify by DINO, 05/27/2008

	//--- Initial position again after PG LOSS Error, Add by DINO, 07/07/2008
	if ( k!=0 ){
        STtune = 1;
        ALIGN = 1;	    				// ADDED SCOTTY 2007/08/06
        Zpulse = 1;
        ZCALIB = 0;
		zcal_uwPulseErr = 0;			// SCOTTY 01/15/2008
		zcal_swThetaErr = 0;			// SCOTTY 01/15/2008
		Pgz_Disconnect_Init(); //[Zphase broken, Lyabryan, 2015/09/17]
        Zphase_countAB_old = uw_SCTEST4; //[Zphase broken, Lyabryan, 2015/09/17]
        REPOS_FAULT_FLAG = 1;
    	//MTU2S4.TSR.BYTE  &= 0xF7;		// clear TGFD flag, dino, 04/09/2007
    	MTU6.TSR.BYTE  &= 0xF7;      // clear TGFD flag, dino, 04/09/2007
    	if ( pr[PG_TYPE]!=SIN_ENDAT && pr[PG_TYPE]!=SIN_HIPER )	// Don't interrupt Z-pulse when EnDat, dino, 08/29/2008
    		//MTU2S4.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable, dino, 04/09/2007 
    		MTU6.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable  
    }

#if 0  // delete by dino, 01/29/2008
    /*------ 1HP don't have Fan, Fan always OFF, 
             else would happened "Fan Locked" ------------------------------*/
    if (pr[HPSPEC]<=VFD007V23A){
        //FAN_SWITCH = 1;
		FAN_ENABLE = 0;		//ADDED BY SCOTTY 10/15/2007
	}
#endif

    VBusLineInit();
    VcomFmax.ul = ((ULONG)pr[FMAX]<<16);
    
    if (pr[FMAIN] > pr[FMAX])
        pr[FMAIN] = pr[FMAX];
    
    if (pr[FCMAIN] > pr[FMAX])
        pr[FCMAIN] = pr[FMAX];
/*--- Delete by DINO, 07/17/2008
    if (pr[CTRLM]==FOCPM){			//added by SC 10/09/2007
    	C20xx[0x01] = 0;
		uwFkeypad = 0;    	
    }
    else{
    	C20xx[0x01] = pr[FCMAIN];
		uwFkeypad = pr[FMAIN];	
	}
*/
	C20xx[0x01] = pr[FCMAIN];		//Recover by DINO, 07/17/2008 (DEL  by SC 10/09/2007)
	uwFkeypad   = pr[FMAIN];

//	PGHOMEMem = pr[PGHOME];			// Delete by DINO, 10/28/2008
	APR_uwPGHome = pr[PGHOME];
//	MI_INVMem = pr[MI_INV];			// Delete by DINO, 10/28/2008
//	MO_INVMem = pr[MO_INV];			// Delete by DINO, 10/28/2008
//	TQRCMemswPer = (SWORD)pr[TQREF];// Delete by DINO, 10/28/2008
	EsJ_uwJmPu = pr[JmPu];

 	SortFskip();
        
    if (pr[CTSEL]==0){
        if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
             pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
        else
            pr[I_RATE] = CTispec[pr[HPSPEC]];
	// 3750000 = (150%-100%)*(150%-100%)*(60sec/40ms)
//		ulOLCNT    = 3750000;
    }
    else {
        if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
            pr[I_RATE] = VTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
        else
            pr[I_RATE] = VTispec[pr[HPSPEC]];
//		ulOLCNT    = 937500;	// dino, 03/09/2007
    }
    if(pr[HPSPEC] < VFD_SINGLEPHASE)      //[Single phase input, Bernie, 01/19/2012]
        pr[I_RATE2] = U16xU16divU16((UWORD)(pr[I_RATE]),1100,1000);
    else if(pr[HPSPEC] > VFD_SINGLEPHASE)
        pr[I_RATE2] = U16xU16divU16((UWORD)(pr[I_RATE]),1100,1000);   //[Single phase input, Bernie, 01/19/2012]     
        
    uwIsDtL = ((ULONG)pr[IS_DETECT] * pr[I_RATE])/100;

    pr[SW_VER] = SWVERS_H;
    pr[DATECODE] = DateCode;
#if SH7149
    if (pr[PRRESET]==8){
    	OPKEY_LOCK = 1;
    	PRLOCK = 1;
    	FSET_LOCK = 1;
    }	
    else if (pr[PRRESET]==1)
    	PRLOCK = 1;
    else {
        OPKEY_LOCK = 0;
    	PRLOCK = 0;
    	FSET_LOCK = 0;
    }		
#else  // Add by DINO, 09/22/2008
	lock_status.ub &= 0xf9;		// OPKEY_LOCK=0, FSET_LOCK=0
    if (pr[PRRESET]==8)
    	lock_status.ub |= 0x06;	// OPKEY_LOCK=1, FSET_LOCK=1
    else if (pr[PRRESET]==1)
    	FSET_LOCK = 1;
#endif

    PGScaleDataTmp = 0;
    if (pr[PGINPUT]>=3){
		PGScaleData = pr[PGSCALE]|0x4000;
	}
	else if (pr[PGINPUT]>=1){
		PGScaleData = pr[PGSCALE];
	}
	else if (pr[PGINPUT]==0){
		PGScaleData = 1;
	}

    if ((pr[PRRESET]&0x0002) == 0x0002){
        SHOW_ENHANCE = 1;
        GROUPTmp = GRALL;
		
		#if DEBUG_MODE
    		SHOW_ALLPR = 1;
		#endif
    }
    else{
        SHOW_ENHANCE = 0;	//SC 
        SIBO_SPDCHG = 0;
        SIBO_PARAMETER = 0; //[Group12&13 Limit count,Lyabryan,2020/09/10]
        if(SIBO_ENABLE){
             SIBO_PARAMETER = 1;
             SIBO_SPDCHG = 1;
		}
        GROUPTmp = GRENHANCE;
        if (grno > GRUSER){
        	grno = 0;
        }
        //GROUPTmp = 13;
    }
#if SH7149  //Delete by DINO, 09/22/2008
    if (pr[PSW_SET]!=0){
    	PRLOCK = 1;
    	pr[PSW_SET] = 1;
    }
#else
    if (pr[PSW_SET]!=0){
		COF_uwPassWord = pr[PSW_SET];
    	if ( PRLOCK )
    		pr[PSW_SET] = 1;
    	else
    		pr[PSW_SET] = 0;
    }
#endif

	if (Error==0){	
		Keypad_Page = pr[S_DISP];   //Start-up display page
        //F_PAGE          0       // F command, same as remote keypad dispaly
        //H_PAGE          1       // H command, same as remote keypad dispaly
        //U_PAGE          2       // Dcbus Display                                 
        //A_PAGE          3       // Current Display               
        //E_PAGE          4       // Output Voltage Display                  
        //USER_PAGE       5       // User Definitation Display
        //DebugPAGE       6       // Debug page display when pr[PRRESET] = 2		
		MFD_page = pr[U_DISP];      //User define Page
		Keypad_PageTmp = 0;
		// [ DINO, 11/18/2010
		//KEY_ubDispMode = 0;
		if (grno == 0)
			KEY_uwPWRCnt = 0;
		
		KEY_ubDispMode = USER_PAGE2;    //[Start Page, Bernie, 08/08/2011]
        switch(pr[S_DISP]){
   	          case 0:
              KEY_ubDispMode = F_PAGE2;
   	          break;
   	          case 1:
   	          spdispx = 2;
   	          break;
   	          case 2:
   	          spdispx = 3;
			  MFD_page = 3;
   	          break;
			  case 3:
   	          spdispx = 0;
   	          break;
   	          case 4:
   	          spdispx = 4;
			  MFD_page = 4;
   	          break;
              case 5:
   	          spdispx = pr[U_DISP];
			  MFD_page = pr[U_DISP];
   	          break;
   	   }

	}

		//GFC Bernie Test
		if((pr[SOFC] == 4) || (pr[SOFC] == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
		    facc1.ul = cal_time(pr[FMAX],0);
		    fdec1.ul = cal_time(pr[FMAX],0);
		    facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
		    fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
		    facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
		    fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
		    facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
		    fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);	
		    fjacc.ul = 0;	
		    fjdec.ul = 0;	
		    fdec5.ul = cal_time(pr[FMAX],0);
		    Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
	        fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]); //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            fdecEMY.ul = cal_time(pr[FMAX],pr[SIBO_DECEMY]);
#endif
		}
		else{
	        facc1.ul = cal_time(pr[FMAX],pr[ACCEL1]);
	        fdec1.ul = cal_time(pr[FMAX],pr[DECEL1]);
	        facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
	        fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
	        facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
	        fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
	        facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
	        fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);	
	        fjacc.ul = cal_time(pr[JOGF],pr[JOGACC]);	
	        fjdec.ul = cal_time(pr[JOGF],pr[JOGDEC]);	
	        fdec5.ul = cal_time(pr[FMAX],pr[DECEL5]);
	        Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
	        fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]); //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            fdecEMY.ul = cal_time(pr[FMAX],pr[SIBO_DECEMY]);
#endif
            
  	    }
    
    //==================================================  Unit == Los pass in 1ms =====//
    VFfslip_uwLPG = Set_LPG(pr[SVC_SLPG],1);		    //0.001, in 1ms, 0.001/1ms = 1
    VFVcomp_uwLPG = Set_LPG(pr[SVC_VLPG],1);            //0.001, in 1ms, 0.001/1ms = 1
    cosphi_uwLPG = Set_LPG(pr[COSPHILPG],1);	        //0.001, in 1ms, 0.001/1ms = 1
    AUI1In_LPG = Set_LPG(pr[AUI1_LPG],10);              //0.01,  in 1ms, 0.01/1ms = 10
    ACIIn_LPG = Set_LPG(pr[ACI_LPG],10);              	//0.01,  in 1ms, 0.01/1ms = 10
    AUI2In_LPG = Set_LPG(pr[AUI2_LPG],10);              //0.01,  in 1ms, 0.01/1ms = 10
    DisplayLPG = Set_LPG(pr[LPF_DISP],1);		        //0.001, in 1ms, 0.001/1ms = 1
    LC01DisplayLPG = Set_LPG(pr[LPF_LC01DISP],1);		//0.001, in 1ms, 0.001/1ms = 1  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
//  SpDt_uwHiLPG = Set_LPG(pr[HiSpd_LPG],1);
    SpDt_uwHiLPG = U16xU16divU16(3217, (pr[HiSpd_LPG]<<4), 2000); //Q13, 3217=2*pi*2^9, 2000=1/500us
//  SpDt_uwLoLPG = Set_LPG(pr[LoSpd_LPG],1);
    SpDt_uwLoLPG = U16xU16divU16(3217, (pr[LoSpd_LPG]<<4), 2000); //Q13, 3217=2*pi*2^9, 2000=1/500us
    PID_LPG = Set_LPG(pr[PIDDLY],100);		            //0.1,   in 1ms, 0.1/1ms = 100
    Tqc_uwTqCmdLPG = Set_LPG(pr[TQRLPG],1);             //0.001, in 1ms, 0.001/1ms = 1
    PG2R_uwCmdLPG = Set_LPG(pr[PG2_LPG],1);             //0.001, in 1ms, 0.001/1ms = 1
    EsJ_uwLPG = Set_LPG(pr[EstJ_LPG],1);      		    //0.001, in 500us, 0.001/500us = 1
    CurZero_LPG = Set_LPG(pr[IZEROLPG],1);              //0.001, in 1ms, 0.001/1ms = 1
	// [ Add by DINO, 06/17/2009
	PTCIn_LPG = Set_LPG(pr[PTC_DFT],10);				//0.01,  in 1ms, 0.01/1ms = 10
	// ]
	dcbusLPG =  Set_LPG(pr[DCBUSLPG],1);				//0.001, in 1ms, 0.001/1ms = 1 
	PHL_LPG = Set_LPG(pr[PHL_T],10);                    //0.01, in 1ms, 0.01/1ms = 10
	SPR_uwPPILPG = Set_LPG(pr[ZSPLowpass],2);			// PPI LPF Gain, 0.001, in 500us, 0.001/500us=2, DINO, 07/28/2010

    IODLC_Initial_value(); // [IODLC, Lyabryan, 2016/11/11]

    if (pr[U_SET]!=0){
        KPDdot = pr[U_SET]/10000;
        KPDmax = pr[U_SET] - KPDdot * 10000;
        KPDset = U16xU16divU16(KPDmax, uwFkeypad, pr[FMAX]);
    }

    TB1_uwBBCnt  = pr[BB_T] * 100;
    TB1_uwLVCnt  = pr[PWRL_T] * 100;
    PID_slofsetv = ((SLONG)pr[PIDOFSET] * pr[FMAX]);
    //-------------------------
    // 220V/440V,  1 ~  15Hp, Rth inside
    // 220V/440V, 20 ~ 100Hp, Rth outside

#if SH7149 // modify 2007/07/10
    if(pr[HPSPEC]<=VFD075V43A)     // thermister inside, pr[HPSPEC]<075V43A, 220/440V: 1~10 Hp
        RTH_IN = 1;
    else    
        RTH_IN = 0;

	if (RTH_IN==1){         // Thermister Inside
        IGBT_OHLevel = pr[OH_IN];
        cf_swChgTemp = 900;
    }
    else {                  // Thermister Outside
        IGBT_OHLevel = pr[OH_OUT];
       cf_swChgTemp = 750;
    }
#else	// VL setting, Add by DINO, 10/20/2008
#if 1	// OH update, Sean, 04/19/2011
	if ( pr[HPSPEC]==VFD300V23A || 	// part of frame E, thermister inside
		 pr[HPSPEC]==VFD370V23A || 
		 pr[HPSPEC]==VFD550V43A || 
		 pr[HPSPEC]==VFD750V43A ||
		 pr[HPSPEC]==VFD1100CH43A){
		IGBT_OHLevel = pr[OH_IN];		//110c
	}
	else if ( 
		 pr[HPSPEC]<=VFD037V43A ||	// frame B
		 pr[HPSPEC]==VFD370V43A ||	// part of frame E
		 pr[HPSPEC]==VFD450V43A ||
		 pr[HPSPEC]==VFD037V21A ||   //[Single phase input, Bernie, 01/19/2012]
		 pr[HPSPEC]==VFD022V21A ){	 //[Single phase input, Bernie, 01/19/2012]

		IGBT_OHLevel = pr[OH_IN] - 50;	//105c
	} 
	else{							// frame C, D, thermister outside
		IGBT_OHLevel = pr[OH_IN] - 150;	// 95c
	}
#else
	if ( pr[HPSPEC]>VFD220V43A ){	// Thermister Inside
		IGBT_OHLevel = pr[OH_IN] - 100;
	}
	else{							// Thermister Outside
		IGBT_OHLevel = pr[OH_IN];
	}
#endif	
#endif
    if ((pr[DEBUG_F1]&0x8000)==0x8000)  // Bit 15: VH mode
        VH_EN = 1;
	else
        VH_EN = 0;    
    /********* Set PWM period, duty cycle, dead time, and carrier period. ***/
    if(pr[HPSPEC]>VFD_SINGLEPHASE)   //[Single phase input, Bernie, 01/19/2012]
        px = maxcf(pr[HPSPEC]-VFD_SINGLEPHASE);
    else
        px = maxcf(pr[HPSPEC]);

    if (pr[SETCRF] > px)
        pr[SETCRF] = px;

    cf_swCFReal = pr[SETCRF]*1000;
	cf_swCFSet = cf_swCFReal;		//ADDED BY DINO, 10/20/2008
	cf_swOHCarry = cf_swCFSet;
	prt_swCon1Fc = cf_swCFSet;
	prt_swCon2Fc = cf_swCFSet;
	prt_swCon3Fc = cf_swCFSet;

    n_period = U32divU16(MTU2CLK, cf_swCFReal);
    experiod = n_period + (n_period>>1);    

    update_experiod = experiod;
    experiod_Buf = experiod;

    //Mark by Max 060127: MTU2.TCDR = experiod;
    //MTU2.TCBR = experiod;
    MTU.TCBRA = experiod;
    //Mark by Max 060127: MTU23.TGRA = experiod + DeadTime;   
    //MTU23.TGRC = experiod + DeadTime;
    MTU3.TGRC = experiod + DeadTime;
    
    COEFInitOnce();
    /*====== motor parameters save in 93c86 is pu value, so after read pr
    from 93c86 must to transfer to real value to show in keypad =========*/
    pr[MI_NL1] = U32xU32divU32(pr[MI_NL1] ,COF_ulIbRe, 46341);  // Jerry.sk.tseng for GFC High elecator 2021/08/17
    pr[Rs1] = (((ULONG)pr[Rs1] * COF_uwRbRe + 8192) >> 14);		// Modify by DINO, 09/09/2008
    pr[Rr1] = (((ULONG)pr[Rr1] * COF_uwRbRe + 8192) >> 14);		// Modify by DINO, 09/09/2008
    pr[Lm1] = U16xU16divU16(pr[Lm1], COF_uwLbRe, 3200);
    pr[Lx1] = U16xU16divU16(pr[Lx1], COF_uwLbRe, 51200);

    pr[MI_NL2] = U32xU32divU32(pr[MI_NL2] ,COF_ulIbRe, 46341);  // Jerry.sk.tseng for GFC High elecator 2021/08/17
    pr[Rs2] = (((ULONG)pr[Rs2] * COF_uwRbRe + 8192) >> 14);		// Modify by DINO, 09/09/2008
    pr[Rr2] = (((ULONG)pr[Rr2] * COF_uwRbRe + 8192) >> 14); 	// Modify by DINO, 09/09/2008       	    
    pr[Lm2] = U16xU16divU16(pr[Lm2], COF_uwLbRe, 3200);     
    pr[Lx2] = U16xU16divU16(pr[Lx2], COF_uwLbRe, 51200);
    
    pr[PM_Rs] = (((ULONG)pr[PM_Rs] * COF_uwRbRe + 8192) >> 14);	// Modify by DINO, 09/09/2008
    pr[PM_Lq] = U16xU16divU16(pr[PM_Lq], COF_uwLbRe, 51200);    
    pr[PM_Ld] = U16xU16divU16(pr[PM_Ld], COF_uwLbRe, 51200); 

#if StandStill   /* Modified by dino, 04/03/2007 */
//    HFIdeltaI_uwLPG = Set_LPG(pr[HFI_ILPG],10);		//0.001, in 100us, 0.001/100us = 10
//    PM_uwStart = (ULONG)pr[START_P] * 2496 >> 16;	//FOCPM start angle
    PM_uwStart = 0;
    Start_Section_old = 24;
    Zpulse = 1;
	ALIGN = 1;	    		//2007/08/06	SCOTTY

    if ( pr[CTRLM]!=FOCPM ){  // Don't operate standstill and Z calibration when IM, dino, 08/20/2007
    	STtune = 0;
    	ZCALIB = 1;
    }

    st_uwInterval = pr[TB2Time];
#endif

    AnaPGInit(); 				// add by dino, 06/01/2007
//    if ( pr[CTRLM]==FOCPM ){ pr[FSTART] = 0; }	//add SCOTTY 10/04/2007
    

	ubMCChk = 0;
	ubBKChk1 = 0;
    ubBKChk2 = 0;    //[change for EN81-1+A3, Bernie, 2015/03/16]
    for (i=MI1;i<=MI8;i++){		// Modify by dino, 05/15/2008

	    if (pr[i] == MFI_ASRSwitch){	// 27:ASR1 to ASR2
	        EXT_ASREN = 1;
		}
		if (pr[i] == MFI_MC_IN){		// 41:Magnetic Contactor Signal Input
			ubMCChk = 1;
		}
		if (pr[i] == MFI_BK_IN1){		// 42:Mechanical Brake Signal Input
			ubBKChk1 = 1;
		}
        if (pr[i] == MFI_BK_IN2){	    // 42:Mechanical Brake Signal Input     //[change for EN81-1+A3, Bernie, 2015/03/16]				
            ubBKChk2 = 1;
        }
    }
	// [ Judgement MCCHK and BKCHK function, Add by DINO, 03/11/2009
	MCCHK_ENABLE = ubMCChk;
	BKCHK_ENABLE1 = ubBKChk1;  //[change for EN81-1+A3, Bernie, 2015/03/16]
	BKCHK_ENABLE2 = ubBKChk2;  //[change for EN81-1+A3, Bernie, 2015/03/16]
	// ]

    //======= Check Motor Selection from Multi-Function ====================//
    // Initial PM motor parameter
    if (pr[CTRLM]==FOCPM)				// Control Mode = PM MOTOR
        Motor3Pr();
    else if (pr[MOTORSEL]==2){
        Motor2Pr();
        if ((YDSetBit&0x30)==0x30){		// Delta-Connected
            MFO_YCON = 0;                                                  
            MFO_DCON = 1;
            YOnCNT = 0;
            DOnCNT = pr[YDDELAYT];
            YDWGON = 1;                       
        }                    
    }
    else{
        mfi_old = 0xFFFF;
        mfi_Pin();
// Delete by DINO, 05/15/2008
/*
        for(i=MI1;i<=MI14;i++){
        	if ((i<=MI6)||(i>=MI7)){
	            if (pr[i]==14){
	            	// Switch between drive 1 & drive 2
	                mfi_ptr=mfi1_tbl[pr[i]];
	                // where +2 is unless REV & FWD
	                if (i<=MI6){
	                	k = ((mfi_now^pr[MI_INV])&_16BitTab[i-MI1+2]);              
	                	(*mfi_ptr)(((mfi_old^mfi_now)&_16BitTab[i-MI1+2]),k);
					}
					else if (i>=MI7){
						k = ((mfi_now^pr[MI_INV])&_16BitTab[i-MI7+2]);              
	                	(*mfi_ptr)(((mfi_old^mfi_now)&_16BitTab[i-MI7+2]),k);
					} 
	                break;
	            }
			}        
        }
*/
        if ((EXT_MOTOR1to2==1)/*||(pr[MOTORSEL]==2)*/){	// motor 2 highest priority
        	Motor2Pr();
        	if ((YDSetBit&0x30)==0x30){		// Delta-Connected
            	MFO_YCON = 0;                                                  
            	MFO_DCON = 1;
            	YOnCNT = 0;
            	DOnCNT = pr[YDDELAYT];
            	YDWGON = 1;                       
        	}        	
    	}
    	else{
            Motor1Pr();
            if ((YDSetBit&0x03)==0x03){		// Y-Connected
                MFO_YCON = 1;                
                MFO_DCON = 0;
                YOnCNT = pr[YDDELAYT];                
                DOnCNT = 0;
                YDWGON = 1;            
            }
        }
		mfi_old = 0xFFFF;
    }
    fstart = MAX(fmin,pr[FSTART]);
    fstart = MIN(pr[FMAX],fstart);            
    
    TQRBaseInit();
    TQRMaxInit();
    MotorPrInit();

	px = U16xU16divU16(pr[DC_ZSEARCH],13107,100);	// Add by DINO, 07/21/2008
	TUN_uwIdCurr = ((ULONG)px * mspec + 50) / 100;	// Change to percentage of Motor, 08/11/2008

	if ( pr[TQ_LPG]==0 )
		COF_uwTqSlopePu = 0;
	else
		COF_uwTqSlopePu = ((ULONG)COF_uwTqratePu * 3 + (pr[TQ_LPG]>>1)) / pr[TQ_LPG];	// Add by DINO, 05/30/2008

    DBC_COEFInit();
    
    VFPG_Init_SlipMax();
    set_Rs();    
    set_VcmpMax();
    TB1_VFCal_Slin();
   
    Init_SpDtPG1_pr();

//    Init_SpDtPG1();
    FanControl();		//ADDED SCOTTY 10/17/2007 

/*-- Delete by DINO, 01/04/2009
#if SCOTTY
	SpDt_uwAnglePeriod = (UWORD)((ULONG)(SpDt_ulPG1NpulseNoMx << 1)/pr[PM_POLES]);
	PG_Zoffset = U16xU16divU16(SpDt_uwAnglePeriod, pr[Z_OFFSET], 3600);		//added 09/17/2007 SC
#endif 
-- End on 01/04/2009  */

#if SH7149	// dino, 03/08/2007
   /* if (pr[PGREFIN]!= 0){
        Init_PG2Ref();
    }*/
#endif
    if (EXT_TqSpdEN == 0){
        if (pr[CTRLM] == TQCPG)
            TqSpdMode = 1;  //Toqure mode         
        else
            TqSpdMode = 0;  //FOCPG, VF, SVC, VF+PG                 
    }
    else{
        if (EXT_TqSpd_flag == 0)
            TqSpdMode = 0;  //Speed mode
        else
            TqSpdMode = 1;  //Toqure mode  
    }

//  if (pr[CTRLM]==TQCPG){
	if (TqSpdMode==1){
		swTemp = ((SWORD)pr[TQREF]);
		TqC_swTqSetPu = (((SLONG)swTemp*COF_uwTqMaxPu)+500)/1000;		
	}
	else{	
		if (pr[SETDIR]!=0){
    		if (pr[SETDIR]==1){
    			CMDDIR = FORWARD;
    		}	
    		else{
    			if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){  //[EPS autodetect dir,Lyabryan,2018/07/02]      //GEN_OK3 = 0; GEN_START = 0;// Generation Operation, DINO, 04/27/2010
    				CMDDIR = REVERSE;
    			}
    		}
    	}
    }
	    
    APR_uwP2PMem = 0;
    /*==== Communication Register Initial ==================================*/
    /* 2000H Command (Read/Write)
       b15   :     Not used
       b14-13:     
    */
    C20xx[0x00] = 0x0000;      
    
    /* 2300H
       b9, ODM product
       b8, Enable to describe the name of group (310GH)
    */
    KC23xx[0x00] = (0x0100|SWVERS_L);
    
    /* 2301H
       High byte, word count for LCD description
       Low byte, word count for Drive status from 2304H
    */
    KC23xx[0x01] = 0x0A06;

    KC23xx[0x02] = 0;
    KC23xx[0x03] = 0;
    KC23xx[0x05] = 0;


    Update_C21xx();
    Update_C22xx();
        
    function_chk();

    RST316J = 1;

    //for estimate J
	EsJ_swJPu_New = 0;
   	EsJ_slJPu = 256 << 16; //Q24 = Q(8+16),1pu, is the output variable
	EsJ_slTLPu_FWD = 0;
    EsJ_slTLPu_REV = 0;
    
    //for Torque control
    slSpdLimRe = (pr[TQPSPDLIM]* pr[FMAX])/100;
    if (slSpdLimRe >= 60000)
        slSpdLimRe = 60000;
    TqC_uwPSpdLimRe = slSpdLimRe;
    TqC_swPSpdLimPu = U16xU16divU16(slSpdLimRe,0x7FFF,COF_uwFbRe);

    slSpdLimRe = (pr[TQNSPDLIM]* pr[FMAX])/100;
    if (slSpdLimRe >= 60000)
        slSpdLimRe = 60000;
    TqC_uwNSpdLimRe = slSpdLimRe;
    TqC_swNSpdLimPu = 0 - U16xU16divU16(slSpdLimRe,0x7FFF,COF_uwFbRe);

   //[Gfc DLC modify,Henry,2018/05/23]
   DLC_PDO_ID004_B0.ub = 0x00;
   DLC_PDO_ID004_B1.ub = 0x00;
   DLC_PDO_ID004_B2.ub = 0x00;
   DLC_PDO_ID004_B3.ub = 0x00;
   DLC_PDO_ID004_B4.ub = 0x00;
   DLC_PDO_ID004_B5.ub = 0x00;
   DLC_PDO_ID004_B6.ub = 0x00;
   DLC_PDO_ID004_B7.ub = 0x00;

   PR_ubEpsOptMod = pr[EPS_OPTM];   
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
   pr[Lift_SPD_RPM] = (120*(flMetric2Hz(pr[Lift_SPD])/100))/COF_uwPole;//[Sibocom Lift speed(11-01) convert to moter speed, Jason, 20200110]
   pr[UNITSEL] = 1;
   write_ep(BLK_WRITE, UNITSEL, 1);
    
    for(bx = 0; bx<=EPMAX; bx++){
        ax =  GetParAttr(bx);
        if((bx <= FMI15) || (bx >= FMI0)){
            attr[bx].ati = ax;
        }
        else{
        }
    }
    PR_flDecelEMYSIBOsec = pr[SIBO_DECEMY];
    PR_flS3EMYsec = pr[SIBO_S3EMY];
    PR_flS4EMYsec = pr[SIBO_S4EMY];
    PR_flFmi7Hz = pr[FMI7];
    PR_flFmi8Hz = pr[FMI8];
    PR_flFmi9Hz = pr[FMI9];
    PR_flFmi10Hz = pr[FMI10];
    PR_flFmi11Hz = pr[FMI11];
    PR_flFmi12Hz = pr[FMI12];
    PR_flFJog_Hz = pr[JOGF];
#endif
    PR_flAccel1sec = pr[ACCEL1];
    PR_flAccel2sec = pr[ACCEL2];
    PR_flAccel3sec = pr[ACCEL3];
    PR_flAccel4sec = pr[ACCEL4];
    PR_flDecel1sec = pr[DECEL1];
    PR_flDecel2sec = pr[DECEL2];
    PR_flDecel3sec = pr[DECEL3];
    PR_flDecel4sec = pr[DECEL4];
    PR_flDecel5sec = pr[DECEL5];
    PR_flDecelJogsec = pr[JOGDEC];
    PR_flAccelJogsec = pr[JOGACC];
    PR_flDecelEsdsec = pr[DECEL_ESD];
    PR_flSAcc1Esdsec = pr[S4ACC1];
    PR_flSAcc2Esdsec = pr[S4ACC2];
    PR_flSDec1Esdsec = pr[S4DEC1];
    PR_flSDec2Esdsec = pr[S4DEC2];
    PR_flSDec3Esdsec = pr[S4DEC3];    

    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    TorqDetect_Init();

    //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
    pr[DEBUG_F2] = (pr[DEBUG_F2]&0xFFFE);
    write_ep(BLK_WRITE,DEBUG_F2, pr[DEBUG_F2]);
    ICTDetectGBP = 0;

}

void Pin_power(void)           // Pin (W)
{
    UWORD uwCosphiLPF;
    ULONG ax,bx;
    
    // 3^(0.5)*Vcmd*Irms*cosphi/10/100
    ax = ((ULONG) IrmsRe * Vcmd_LL);     

#if SH7149
	bx = U32xU16shlr16(ax, (cosphiLPF.sw.hi<<2));
    // where 113 = (sqrt(3)/10/100)*2^16
    PowerInRe = U32xU16shlr16(bx, 113);
#else	// Modify by DINO, 09/22/2008
	if ( cosphiLPF.sw.hi>=0 ){ 
		bx = U32xU16shlr16(ax, (cosphiLPF.sw.hi<<2));
    	// where 11.3 = (sqrt(3)/100/100)*2^16 = 91 / 8
    	PowerInRe = U32xU16shlr16(bx, 91);
    	PowerInRe = PowerInRe >>3;
    }

	else{
		uwCosphiLPF = -cosphiLPF.sw.hi;
		bx = U32xU16shlr16(ax, (uwCosphiLPF<<2));
    	// where 11.3 = (sqrt(3)/100/100)*2^16 = 91 / 8
    	PowerInRe = -U32xU16shlr16(bx, 91);
    	PowerInRe = PowerInRe >>3;
	}
	
#endif
    // xxx.xx KW, Max 100Hp =75 kw
   	
    Pinput.ul = lowpass_sl(DisplayLPG,PowerInRe,Pinput.ul);

}

void Torque_Load(void)              // TL, torque
{
    //ULONG sx;
    SLONG sx;
    SWORD ax;
    UWORD uw_temp;

        // 18 = (1.141/pi/10/10/16)*65536
    if((pr[CTRLM]==SVC)){ //SVC MODE  //6911j **
        /*if (PowerGap >=0){
          //sx = ((ULONG)((PowerGap*18)>>16)*pr[I_RATE]/pr[AD_IRATE])*1000;
          sx = ((ULONG)((PowerGap*18)>>16)*pr[I_RATE]/pr[AD_IRATE])*1000;
        }
        else {
          //sx = ((ULONG)(((-PowerGap)*18)>>16)*pr[I_RATE]/pr[AD_IRATE])*1000;
          sx = ((ULONG)(((PowerGap)*18)>>16)*pr[I_RATE]/pr[AD_IRATE])*1000;
        }*/
        sx = ((SLONG)((PowerGap*18)>>16)*pr[I_RATE]/pr[AD_IRATE])*1000;
        
        if (fout.uw.hi != 0)
          TorqueOut = (S32xS32divS32(sx,1024,fout.uw.hi))>>10;
        else
          TorqueOut = 0;
    }   //6911j&&
    else{ //6a13j** //FOCPG/TQCPG/VF/VFPG MODE
    
        /*if(TsE_swIqseOutPu >=0){
            ax = (UWORD)(S16xS16divS16(TsE_swIqseOutPu, COF_uwKt, 2048));
        }
        else{
            ax = (UWORD)((S16xS16divS16(TsE_swIqseOutPu, COF_uwKt, 2048)));
        }*/
        if ((pr[CTRLM]==FOCPM)){
        	uw_temp = U16xU16divU16(13107 ,100, pr[I_RATE]);	//pr[I_RATE] 00-01	
        	ax = (SWORD)(S16xS16divS16(CUR_swIqseFdbPu, 100, uw_temp));  //TorquePu=kt*Iq
        	if (RUNNING == RUN)
            	TorqueOut = S16xS16divS16(ax, COF_uwKt, 1000);
        	else
            	TorqueOut = 0;        	
        }
        else {    
        	ax = (SWORD)(S16xS16divS16(TsE_swIqseOutPu, COF_uwKt, 2048));  //TorquePu=kt*Iq
         
        	if (fout.uw.hi != 0)
            	TorqueOut = S16xS16divS16(ax, COF_uwTbRe,4096);
        	else
            	TorqueOut = 0;
        }

    }   //6a13j&&
}
#if SH7149
SWORD AVICalculate(void)
{
    SWORD ax,ay;
    // AI Input for AVI 0-10V
    // y = G(x + b) for positive Offset.
    // y = G(x - b) for negative Offset.            
	
    ay = ai_transfer(1,AVIadLPF.sw.hi,pr[CAVIMAX],pr[CAVIMID],pr[CAVIMIN]);
	
    ax = ((SLONG)((SWORD)pr[AUI1BIAS]) * pr[CAVIMAX])/1000;	

    if (pr[AUI1_PN]==0){
	// no bias
	ay = ((SLONG)pr[AUI1GA]*ay) / 1000;
    }
    else if (pr[AUI1_PN]==1){
	// value lower than bias = bias
	ay = ((SLONG)pr[AUI1GA]*(ax+ay))/1000;
	ax = ((SLONG)pr[AUI1GA]*ax)/1000;
	if (ay<=ax)
	    ay = ax;
    }
    else if (pr[AUI1_PN]==2){
	// value higher than bias = bias
	ay = ((SLONG)pr[AUI1GA]*(ay+ax))/1000;
	ax = ((SLONG)pr[AUI1GA]*ax)/1000;
	if (ay>=ax)
	    ay = ax;
    }
    else if (pr[AUI1_PN]==3){
	//  the absoult value of the bias voltage while serving as the center
	ay = abs(((SLONG)pr[AUI1GA]*(ay+ax))/1000);
    }
    else if (pr[AUI1_PN]==4){
	//  the value of the bias voltage while serving as the center
	ay = ((SLONG)pr[AUI1GA]*(ay+ax))/1000;
    }

    if (ay>=(SWORD)ADMAX)
	ay = ADMAX;
    else if (ay<=(SWORD)(-ADMAX))
	ay = -ADMAX;

    swAVICalib = ay;
			
    return ay;
}
#endif

SWORD ACICalculate(void)
{
    SWORD ax, ay, swGain/*, swAUI1Min*/;
    //UWORD uwPN;

    // AI2 Input for 4-20mA
    // y = G(x + b) for positive Offset.
    // y = G(x - b) for negative Offset.
    // Loss of ACI detect
	swGain = (SWORD)pr[ACIGA];

#if SH7149
    if (pr[ACISEL]==0)
    	ay = ai_transfer(2,ACIadLPF.sw.hi,pr[CACIMAX],pr[CACIMID],pr[CACIMIN]);
    else
    	ay = ai_transfer(2,ACIadLPF.sw.hi,pr[CAVIMAX],pr[CAVIMID],pr[CAVIMIN]);
#else	// dino, 03/21/2007
    ay = ai_transfer(2,ACIadLPF.sw.hi,pr[CACIMAX],pr[CACIMID],pr[CACIMIN]);
#endif

	swACICalib = (SLONG)ay * 1000 >> 12;

    if ( (AD_uwACIad<=(pr[CACIMIN]-60)) && (pr[ACISEL]==0) ){	// ACI Loss, dino, 03/07/2007
        /*  //[ //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
    	if (pr[LOCELTUN]==0){
	    //ACI loss                  				
       	    ay = 0; 		
       	    ACI_LOSS = 1;
       	}
    	else if (pr[LOCELTUN]==1){
    		// Continue operate in the last speed
       	    ay = swACICalib; 		
       	    ACI_LOSS = 1;
       	}
   		else if (pr[LOCELTUN]==3){
   	    	// Stop immediately and display "EF"
   	    	ACI_EF = 1;
  	    	ACI_LOSS = 1;
  	    	ay = 0;
   		}
        */ //]  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
    }
    else{
		ACI_EF = 0;
		ACI_LOSS = 0;
#if SH7149
		if (pr[ACISEL]==0)
   	    	ax = ((SLONG)((SWORD)pr[ACIBIAS])*pr[CACIMAX])/1000;
		else
   	    	ax = ((SLONG)((SWORD)pr[ACIBIAS])*pr[CAVIMAX])/1000;
#else
		ax = S16xS16divS16((SWORD)pr[ACIBIAS],pr[CACIMAX],1000);
#endif

     	if (pr[ACI_PN]==0){
     	    // No Offset
            ay = S16xS16divS16(swGain,ay,1000);
        }
//--- Add by DINO, 12/14/2007
      	else /*if (pr[ACI_PN]==1)*/{
    		// value lower than bias = bias
    		if (ay <= ax){
    		    ay = ax;
    		}
			ay = S16xS16divS16(swGain,(ay-ax),1000);
        }
/*
//--- Add by DINO, 12/14/2007
      	else if (pr[ACI_PN]==2){
    		// value higher than bias = bias
    		if (ay >= ax){
    		    ay = ax;
    		}
   			ay = S16xS16divS16(swGain,(ay-ax),1000);
        }
        else if (pr[ACI_PN]==3){
    		//  the absoult value of the bias voltage while serving as the center
			ay = S16xS16divS16(swGain,(ay-ax),1000);
			if (ay < 0){
				ay = -ay;
			}
		}
		else {
			//  the value of the bias voltage while serving as the center
    		ay = S16xS16divS16(swGain,(ay-ax),1000);
		}
*/
    }

    if (ay >= (SWORD)ADMAX){
		ay = ADMAX;
	}
    else if (ay <= 0){
		ay = 0;
	}
		
    return ay;
}


SWORD AUI1Calculate(void)
{
    SWORD ax, ay, swGain, swAUI1Min;
    UWORD uwPN;

    // ------ calculate For AUI1 -10V~+10V Analog Input        
    // AUI1 -10V input => AD_uwAUI1ad = 4095
    // AUI1 +10V input => AD_uwAUI1ad = 0

	swGain = (SWORD)pr[AUI1GA];
	uwPN   = pr[AUI1_PN];

    if (AVIadLPF.sw.hi > pr[CAUI1ZERO]){	//AUI1:0~-10V (AN13:2048~4095)
    	ay = -ai_transfer(3,AVIadLPF.sw.hi,pr[CAUI1MAX],0,pr[CAUI1ZERO]);	// -4096 ~ 0
    }
    else{	//AUI1:10V~0V (AN13:0~2048)
		ay = 4096 - ai_transfer(3, AVIadLPF.sw.hi, pr[CAUI1ZERO], 0, pr[CAUI1MIN]);  // 0 ~ 4096, dino, 07/22/2007
    }
    swAVICalib = (SLONG)ay * 1000 >> 12;

	if (pr[AUI1_POLAR] == 1){	// Unipolar: 0~10V only
		// Unipolar: Gain is always > 0
		if (swGain < 0){
			swGain = 0;
		}
		// Unipolar: ay should be > 0
		if (ay < 0){
			ay = 0;
		}
		// Unipolar: No Absolute Bias
		if (uwPN == 3){
			uwPN = 1;
		}
		swAUI1Min = 0;
	}
	else{
		swAUI1Min = -ADMAX;
	}
    if((pr[AUI1_SL]==3)||(pr[AUI2_SL]==3))  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
    	ax = S16xS16divS16((SWORD)pr[AUI1BIAS],4095,1000);
    else
    	ax = S16xS16divS16((SWORD)pr[AUI1BIAS],pr[CAUI1MAX],1000);
    
    if (uwPN==0){		//03-06 偏壓模式
		// No offset
        ay = S16xS16divS16(swGain,ay,1000);
    }					
    else if (uwPN==1){
    	// value lower than bias = bias
    	if (ay <= ax){
    	    ay = ax;
    	}
		ay = S16xS16divS16(swGain,(ay-ax),1000);
	}					
    else if (uwPN==2){
    	// value higher than bias = bias
    	if (ay >= ax){
    	    ay = ax;
    	}
   		ay = S16xS16divS16(swGain,(ay-ax),1000);
    }
    else if (uwPN==3){
    	//  the absoult value of the bias voltage while serving as the center
		ay = S16xS16divS16(swGain,(ay-ax),1000);
		if (ay < 0){
			ay = -ay;
		}
    }
    else {
		//  the value of the bias voltage while serving as the center
    	ay = S16xS16divS16(swGain,(ay-ax),1000);
    }


    if (ay >= (SWORD)ADMAX){
		ay = ADMAX;
	}
    else if (ay <= swAUI1Min){
		ay = swAUI1Min;
	}
   
    return ay;
}

SWORD AUI2Calculate(void)
{

    SWORD ax, ay, swGain, swAUI2Min;
    UWORD uwPN;

    // ------ calculate For AUI2 -10V~+10V Analog Input        
    // AUI2 -10V input => AD_uwAUI2ad = 4095
    // AUI2 +10V input => AD_uwAUI2ad = 0
	swGain = (SWORD)pr[AUI2GA];
	uwPN   = pr[AUI2_PN];

    if (AUIadLPF.sw.hi > pr[CAUI2ZERO]){	//AUI2:0~-10V (AN14:2048~4095)
    	ay = -ai_transfer(3,AUIadLPF.sw.hi,pr[CAUI2MAX],0,pr[CAUI2ZERO]);	// -4096 ~ 0
    }
    else{	//AUI2:10V~0V (AN14:0~2048)
		ay = 4096 - ai_transfer(3, AUIadLPF.sw.hi, pr[CAUI2ZERO], 0, pr[CAUI2MIN]);  // 0 ~ 4096, dino, 07/22/2007
    }

    swAUICalib = (SLONG)ay * 1000 >> 12;

	if (pr[AUI2_POLAR] == 1){	// Unipolar: 0~10V only
		// Unipolar: Gain is always > 0
		if (swGain < 0){
			swGain = 0;
		}
		// Unipolar: ay should be > 0
		if (ay < 0){
			ay = 0;
		}
		// Unipolar: No Absolute Bias
		if (uwPN == 3){
			uwPN = 1;
		}
		swAUI2Min = 0;
	}
	else{
		swAUI2Min = -ADMAX;
	}

	ax = S16xS16divS16((SWORD)pr[AUI2BIAS],pr[CAUI2MAX],1000);
    
    if (uwPN==0){
		// No offset
        ay = S16xS16divS16(swGain,ay,1000);
    }					
    else if (uwPN==1){
    	// value lower than bias = bias
    	if (ay <= ax){
    	    ay = ax;
    	}
		ay = S16xS16divS16(swGain,(ay-ax),1000);
	}					
    else if (uwPN==2){
    	// value higher than bias = bias
    	if (ay >= ax){
    	    ay = ax;
    	}
   		ay = S16xS16divS16(swGain,(ay-ax),1000);
    }
    else if (uwPN==3){
    	//  the absoult value of the bias voltage while serving as the center
		ay = S16xS16divS16(swGain,(ay-ax),1000);
		if (ay < 0){
			ay = -ay;
		}
    }
    else {
		//  the value of the bias voltage while serving as the center
    	ay = S16xS16divS16(swGain,(ay-ax),1000);
    }

    if (ay >= (SWORD)ADMAX){
		ay = ADMAX;
	}
    else if (ay <= swAUI2Min){
		ay = swAUI2Min;
	}

	return ay;
}

//[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
void mfi_FwdRevWarn(void){
	if((WarnCode == 0)&&(Error == 0)){
		WarnCode = FWDREV_WARN;
	}
}


UWORD FWDREVProcess(SLONG AIvar)
{
	UWORD uwTemp;
	if (AIvar>=0){
		if (pr[SETDIR]==2){	// FWD Disable
			CMDDIR = REVERSE;
			uwTemp = 0;
		}
		else{
			if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]   //GEN_OK3 = 0; GEN_START = 0;// Generation Operation, DINO, 04/27/2010
				if (CMDDIR==REVERSE){
					CMDDIR = FORWARD;
				}
			}
			uwTemp = (UWORD)abs(AIvar);			
		}		
	}
	else{								                	        	
    	if (pr[SETDIR]==1){	// REV Disable
	    	CMDDIR = FORWARD;
    		uwTemp = 0;
		}     	
        else{
        	if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){//[EPS autodetect dir,Lyabryan,2018/07/02]    //GEN_OK3 = 0; GEN_START = 0;// Generation Operation, DINO, 04/27/2010
        		if (CMDDIR==FORWARD){
					CMDDIR = REVERSE;
				}
			}
			uwTemp = (UWORD)abs(AIvar);
		}		
    }

	return uwTemp;
}
/*==========================================================================//
//mi_speed function process souce of frequency which include                //
// JOG Frequency, External terminal select AI input                         //
// Keypad, Communication, AI input,                                         //
//==========================================================================*/
void mi_speed(void)
{
    UWORD uwTemp;
    SWORD swTemp;
    SLONG slTemp;  //6a16j
    //----------------------------------------------------------------------//
    //     bit 9: Main Frequency by external terminal (EXT)                 //
    //     bit 8: Main Frequency by Communication                           //
    //     bit 2: JOG active                                                //
    //----------------------------------------------------------------------//
    C21xx[0x01] &=  0xfcfb; 
    C21xx[0x19] &=  0xfcfb; 
	
    if (pr[CTRLM]!=TQCPG)
    {    // Speed control mode   //6a17j mask
		if (speed==0)
        {
			if (CMDJOG == 1)
            {    
				if (pr[JOGF] > pr[FMAX])
                {            
            	    pr[JOGF] = pr[FMAX];
                }
            	C21xx[0x01] |= 0x0004;      //JOG active
            	C21xx[0x19] |= 0x0004;  
            	C21xx[0x02] = pr[JOGF];
            	fkey.uw.hi = pr[JOGF];
			}
			else
            {
	    		if (EXT_AISEL!=0)
                {
					C21xx[0x01] |= 0x0200;      //2101H.bit9 EXT led in Keypad light on
					C21xx[0x19] |= 0x0200;      //2119H.bit9 EXT led in Keypad light on
                	
                	switch(EXT_AISEL)
                    {
                    	default:
		    			case 1:	//AUI1
                    	case 3:
                    	case 5:
                    	case 7:
                			if (pr[AUI1_SL]==1)
                            {
#if SH7149 
                	    		if ((pr[AUI1_PN]!=0)&&(((SWORD)pr[AUI1BIAS])!=0))
                					fkey.uw.hi = FWDREVProcess(AVIslFunVar);
                	    		else{
                	    			if (AVIslFunVar<0)
                		    			AVIslFunVar = 0;
                					fkey.uw.hi = abs(AVIslFunVar);
			    				}
#else
			    				// [ Unipolar: AUI1 no direction, DINO, 06/17/2009
			    				if (pr[AUI1_POLAR] == 0)
                                {
			    					fkey.uw.hi = FWDREVProcess(AVIslFunVar);  /* dino, 03/21/2007 */
			    				}
			    				else
                                {
                					fkey.uw.hi = abs(AVIslFunVar);
			    				}
			    				// ]
#endif
							}
							else
                            {                     
			    				fkey.uw.hi = 0;
                            }
							break;
		    			case 2: //ACI         
		    			case 6:
							if (pr[ACI_SL]==1)
                            {
								// [ Modify the Speed Command Calculation of ACI, DINO, 06/17/2009
				    			fkey.uw.hi = abs(ACIslFunVar);
								
			    				//if ((pr[ACI_PN]!=0)&&(((SWORD)pr[ACIBIAS])!=0))
									//fkey.uw.hi = FWDREVProcess(ACIslFunVar);
			    				//else{
									//if (ACIslFunVar<0)
				    					//ACIslFunVar = 0;
				    				    //fkey.uw.hi = abs(ACIslFunVar);
			    				//}
								
							}
							else
                            {
			    				fkey.uw.hi = 0;  
			    			}
							break;
						
		    			case 4: //AUI2
							if (pr[AUI2_SL]==1)
                            {
								// [ Unipolar: AUI2 no direction, DINO, 06/17/2009
								if (pr[AUI2_POLAR] == 0)
                                {
			    					fkey.uw.hi = FWDREVProcess(AUIslFunVar);
			    				}
			    				else
                                {
			    					fkey.uw.hi = abs(AUIslFunVar);
			    				}
			    				// ]
			    			}
							else
                            {
			    				fkey.uw.hi = 0;  
			    			}
							break;							
					}
	    		}
				else
                {
				 	if(pr[CAN_CTRL]==1)   //[CAN Control, Sampo, 09/15/2010]
                    {              
						fkey.uw.hi = uwFcan;
                    }
				 	else
                    {                       
						switch(pr[SOFC])
                        {
		    				case 0:	// Frequency Command form Keypad
								if (uwFkeypad > pr[FMAX])
                                {                        
                  					uwFkeypad = pr[FMAX];
                                }
								if ((PositionCom==0)&&(KEB_ON==0))
                                {                        
                      				fkey.uw.hi = uwFkeypad;		// Digital Keypad
                                }
								break;
		    				case 1:	// Frequency Command from Communication
                        		C21xx[0x01] |= 0x0100;
                				C21xx[0x19] |= 0x0100;   
								if ((PositionCom==0)&&(KEB_ON==0))         		
                                {                        
              		    			fkey.uw.hi = C20xx[0x01];	// Communication
                                }
              					break;                        
		    				case 2:	// Frequency Command from AI
                				C21xx[0x01] |= 0x0200;
                				C21xx[0x19] |= 0x0200;
                				if ((PositionCom==0)&&(KEB_ON==0))
                                {
               	        	    	if (pr[AUI1_SL]==1)
                                    {
#if SH7149              	
               	        				if ((pr[AUI1_PN]!=0)&&(((SWORD)pr[AUI1BIAS])!=0))
                			    			fkey.uw.hi = FWDREVProcess(AVIslFunVar);
                						else{
                			    			if (AVIslFunVar<0)
                								AVIslFunVar = 0;
                			    			fkey.uw.hi = abs(AVIslFunVar);
										}
#else                   	
			    						// [ Unipolar: AUI1 no direction, DINO, 06/17/2009
			    						if (pr[AUI1_POLAR] == 0)
                                        {
			    							fkey.uw.hi = FWDREVProcess(AVIslFunVar);  /* dino, 03/21/2007 */
			    						}
			    						else
                                        {
                							fkey.uw.hi = abs(AVIslFunVar);
			    						}
			    						// ]
#endif
               	        	    	}
               	        	    	else if (pr[ACI_SL]==1)
                                    {
										// [ Modify the Speed Command Calculation of ACI, DINO, 06/17/2009
				    					fkey.uw.hi = abs(ACIslFunVar);
										/*
               	        				if ((pr[ACI_PN]!=0)&&(((SWORD)pr[ACIBIAS])!=0))
				    						fkey.uw.hi = FWDREVProcess(ACIslFunVar);
										else{
				    						if (ACIslFunVar<0)
												ACIslFunVar = 0;
				    						fkey.uw.hi = abs(ACIslFunVar);
										}
										*/
										// ]
			    					}
               	        	    	else if (pr[AUI2_SL]==1)
                                    {
										// [ Unipolar: AUI2 no direction, DINO, 06/17/2009
										if (pr[AUI2_POLAR] == 0)
                                        {
			    							fkey.uw.hi = FWDREVProcess(AUIslFunVar);
			    						}
			    						else
                                        {
			    							fkey.uw.hi = abs(AUIslFunVar);
			    						}
			    						// ]
               	        			}
               	        	    	else{
               	        				fkey.uw.hi = 0;
               	        			}
								}	
								break;
// Add by DINO, 10/09/2007
		    				case 3:	// Frequency Command from External
                        		C21xx[0x01] |= 0x0200;
                	    		C21xx[0x19] |= 0x0200;
                	    		if ((PositionCom==0)&&(KEB_ON==0))
                                {
                	    			// [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
	    							#if 0
	    							if (pr[FMI0+speed] > pr[FMAX])
										pr[FMI0+speed] = pr[FMAX];
									fkey.uw.hi = pr[FMI0+speed];
									#else
	    							if (pr[FMI0] > pr[FMAX])
                                    {                        
										pr[FMI0] = pr[FMAX];
                                    }
									fkey.uw.hi = pr[FMI0];      // External
									#endif
									// ]
								}
            					break;
// End of add by DINO   	
#if SH7149						
		    				case 3:	// Frequency Command from External
                        		C21xx[0x01] |= 0x0200;
                	    		C21xx[0x19] |= 0x0200;
                	    		if ((PositionCom==0)&&(KEB_ON==0))
            		   				fkey.ul = fexternal.ul;		// external
            					break;
		    				case 4:	// Frequency Command from PGref without direction
                    			C21xx[0x01] |= 0x0200;
                				C21xx[0x19] |= 0x0200;
                				if ((PositionCom==0)&&(KEB_ON==0))
            		   				fkey.ul = PG2_ulSpdCmdLPF.ul;
            					break;
		    				case 5:	// Frequencu Command from PGref with direction
                  	  			C21xx[0x01] |= 0x0200;
                				C21xx[0x19] |= 0x0200;
               					if ((PositionCom==0)&&(KEB_ON==0)){
                					if (PG2_slSpdCmd>=0){								                	        	
                			   			if (pr[SETDIR]==2){
                			      			// FWD disable
            								CMDDIR = REVERSE;
            								fkey.ul = 0;
            							}
            							else{
            								if ((PWM_Status.ub&0x42) == 0){  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
            									CMDDIR = FORWARD;
            								}
            								fkey.ul = PG2_ulSpdCmdLPF.ul;
            							}            						
                			    	}
                			  		else if (PG2_slSpdCmd<0){                	        	
                  	  		       		if (pr[SETDIR]==1){
                  	  		        		// REV disable
            								CMDDIR = FORWARD;
											fkey.uw.hi = 0;
										}      	
        								else{
        									if ((PWM_Status.ub&0x42) == 0){  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
												CMDDIR = REVERSE;
											}
											fkey.ul = PG2_ulSpdCmdLPF.ul;
										}     
                			  		}               	        	
                				}
            					break;
#endif             			
		    				default:
								break;
						}                	                   	     
	    			}                 
				}
			}
		}
        // [ speed!=0, Add by DINO, 05/15/2009
		else
        {
        	if (CMDJOG == 1)
            {    
            	if (pr[JOGF] > pr[FMAX])
                {   
                	pr[JOGF] = pr[FMAX];
                }
                C21xx[0x01] |= 0x0004;      //JOG active
                C21xx[0x19] |= 0x0004;  
                C21xx[0x02] = pr[JOGF];
                fkey.uw.hi = pr[JOGF];
            }
            else if((SLOWSPSHOW)&&(!SLOWSPSTR)&&(pr[GEAR_ACCT]!=0))
            {   //&&((pr[SysControl]&0x0400) == 0x0400) //[Dwell S curve,Lyabryan,2018/11/21]
                fkey.uw.hi = pr[GEAR_ACCF]; // [IODLC, Lyabryan, 2016/11/11]
                btGearFlag = 1;             //[JES Gear no output MO=2, Special.Kung, 2022/09/01]
            }
            else
            {
                //[JES Gear no output MO=2, Special.Kung, 2022/09/01]
                btGearFlag = 0;
                
            	if (EXT_SPD2POS==0)
                {
              		if (pr[FMI0+speed] > pr[FMAX])
                    {    
                    	pr[FMI0+speed] = pr[FMAX];
                    }
					// [Turn-on the EXT led when MI-speed, Add by DINO, 08/26/2009
					C21xx[0x01] |= 0x0200;      //2101H.bit9 EXT led in Keypad light on
					C21xx[0x19] |= 0x0200;      //2119H.bit9 EXT led in Keypad light on
					// ]
					if(IODLC_control == IODLC_control_get)
                    { 
                        // [IODLC, Lyabryan, 2016/11/11]
                   	    fkey.uw.hi = IODLC_uwSpeed; // [IODLC, Lyabryan, 2016/11/11]
                    }
					else if((btSR_speedCTRL_ETS==SR_control_get)||(btSR_speedCTRL_ESD==SR_control_get))
                    { 
                        //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
                        fkey.uw.hi = pr[FLAND]; 
                    }
                    else
                    { 
                        // [IODLC, Lyabryan, 2016/11/11]
                        fkey.uw.hi = pr[FMI0+speed];
                    }
               	}
               	else
                {
              		if (pr[FMI0+speed] > SpDt_ulPG1NpulseNoMx)
                    {    
                    	pr[FMI0+speed] = SpDt_ulPG1NpulseNoMx;
                    }
    			}
    		}
		}
		// [ Set EPS Frequency Command, Add by DINO, 06/24/2009
		//  Delete by DINO, 08/30/2010
		if ( EPS ){
			if (pr[FEPS] > COF_uwFepsLimit){
				fkey.uw.hi = COF_uwFepsLimit;
			}
			if(fkey.uw.hi>COF_uwFepsLimit){
				fkey.uw.hi = COF_uwFepsLimit;
			}
		}
		// ]

        //Freq. Command for vfd-soft/ explore Display, Special.Kung, 2022/11/4
        fkeyDisplay = fkey.uw.hi;
	}	// ]

	if ((pr[PIDSL]!=0)&&(!MFI_PIDDIS))
		PIDsource = U16xU16divU16(KPDmax, fkey.uw.hi, pr[FMAX]);
    //}    //6a17j mask    
    //else{     //6a17j mask  
//  if (pr[CTRLM]==TQCPG){ //6a17j
    if ((TqSpdMode == 1) || (EXT_TqSpdEN == 1) || (pr[CTRLM]==FOCPM && (pr[DEBUG_F1]&0x0800)==0x0800)){
    	//====== Torque control mode ======//
        if (pr[TQRSOOC]<=1){
        	if ((pr[TENSION]!=0)&&(pr[DIAMETER]!=0)&&(pr[TQRSOOC]==0)){
        		uwTemp = U32xU32divU32(pr[DEPTH], APR_uwThetaNoMx, SpDt_ulPG1NpulseNoMx);
        		PrDiameter = PrDiameter - uwTemp;
    			PrTorqueRe = ((ULONG)pr[TENSION] * PrDiameter)>>1;    	
    			PrTorquePu = U32xU32divU32(PrTorqueRe,100000,(COF_uwTqrateRe*pr[TQRMAX]));        		
        		swTemp = PrTorquePu;
			}
			else{
				swTemp = ((SWORD)pr[TQREF]);
			}        	        	
		}
		else if (pr[TQRSOOC]==2){			 
			if (pr[AUI1_SL]==2){
				// [ EXT_TQCDIR is only valid in Unipolar AUI1, Modify by DINO, 06/17/2009
				if (pr[AUI1_POLAR] == 1){
					if (EXT_TQCDIR==0)
						swTemp = (SWORD)AVIslFunVar;
					else
						swTemp = (SWORD)(-AVIslFunVar);
				}
				else{
					swTemp = (SWORD)AVIslFunVar;
				}
				// ]
			}
			else if (pr[ACI_SL]==2){
				if (EXT_TQCDIR==0)
					swTemp = (SWORD)ACIslFunVar;
				else
					swTemp = (SWORD)(-ACIslFunVar);					
			}
			else if (pr[AUI2_SL]==2){
				// [ EXT_TQCDIR is only valid in Unipolar AUI2, Modify by DINO, 06/17/2009
				if(pr[AUI2_POLAR] == 1){
					if (EXT_TQCDIR==0)
						swTemp = (SWORD)AUIslFunVar;
					else
						swTemp = (SWORD)(-AUIslFunVar);
				}
				else{
					swTemp = (SWORD)AUIslFunVar;
				}
				// ]
			}
			else{
				swTemp = 0;
			}
				
    		pr[TQREF] = ((SWORD)S16xS16divS16(swTemp,1000,COF_uwTqMaxPu));
    		swTemp = ((SWORD)pr[TQREF]);

		}
		
		swTemp = (((SLONG)swTemp * COF_uwTqMaxPu)+500)/1000;
		
        if (swTemp >=(SWORD)COF_uwTqMaxPu)
            swTemp = (SWORD)COF_uwTqMaxPu;
        else if (swTemp<=(SWORD)(-COF_uwTqMaxPu))
        	swTemp = (SWORD)(-COF_uwTqMaxPu);

        TqC_swTqSetPu = swTemp;
    }    
    //if(CMDRUN != RUN){               //[Modify preload function, Bernie, 01/20/2012]
    if((CMDRUN != RUN)&&(RUNNING == STOP)){   //[Pre-Torque BUG,Lyabryan,2019/01/08]            //[Modify preload function, Bernie, 01/20/2012]
	    if (pr[TQROFSE] == 0){	//07-19 轉矩命令偏壓來源
		    TqC_swTqOfstPu = 0;
        }
	    else if (pr[TQROFSE] == 1){
		    // [ Delete Analog Input Function 11, DINO, 06/17/2009
		    if (pr[AUI1_SL] == 3)
			    TqC_swTqOfstPu = (SWORD)AVIslFunVar;
		    else if (pr[ACI_SL] == 3)
			    TqC_swTqOfstPu = (SWORD)ACIslFunVar;
		    else if (pr[AUI2_SL] == 3)
			    TqC_swTqOfstPu = (SWORD)AUIslFunVar;
		    else
			    TqC_swTqOfstPu = 0;
		    // ]
	    }	    	
	    else if (pr[TQROFSE] == 2){
	        TqC_swTqOfstPu = ((SLONG)pr[TQOFSEV] * COF_uwTqratePu)>>10;  //Q(10+12)-10 = Q12
	    } 
        else if(pr[TQROFSE] == 4){                //[UD protocal, Bernie, 2012/12/05]
            TqC_swTqOfstPu = (SWORD)AVIslFunVar_1;
        }
	    else /*if (pr[TQROFSE]==3)*/{
	        switch(MFI_TQCSel){
	    	    default:
	    	    case 0:
	    		    swTemp = -(pr[TQOFSEVH] + pr[TQOFSEVM] + pr[TQOFSEVL]); //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 1:
	    		    swTemp = pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 2:
	    		    swTemp = pr[TQOFSEVM]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 3:
	    		    swTemp = pr[TQOFSEVM] + pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 4:
	    		    swTemp = pr[TQOFSEVH]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 5:
	    		    swTemp = pr[TQOFSEVH] + pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 6:
	    		    swTemp = pr[TQOFSEVH] + pr[TQOFSEVM]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 7:
	    		    swTemp = pr[TQOFSEVH] + pr[TQOFSEVM] + pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    		
		    }                
	            
	        TqC_swTqOfstPu = ((SLONG)swTemp * COF_uwTqratePu)>>10;  //Q(10+12)-10 = Q12;
	    }
	}
//	if (pr[CTRLM]==TQCPG){ //6a16j**
	if(TqSpdMode == 1){   //6a16j**
	   slTemp = ((SLONG)(TqC_swTqSetPu + TqC_swTqOfstPu) * 1000) + 500;
	   TqC_swTqCmd = (S32xS32divS32(slTemp,1024,COF_uwTqratePu))>>10;
	}
	else{
//	   TqC_swTqCmd = 0;    //6a16j&&
		if (pr[CTRLM]==FOCPM){
	   		TqC_swTqCmd = 0;
	   		//T= KT*I;
	   	}
	   	else {
	   		TqC_swTqCmd = 0;    //6a16j&&
	   	}
	}
}
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
void Sibocom_mi_speed(void) //[Sibocom acc/dec,Lyabryan,2019/11/12]
{
    UWORD uwTemp,uwspeed;
    SWORD swTemp;
    SLONG slTemp;  //6a16j
    //----------------------------------------------------------------------//
    //     bit 9: Main Frequency by external terminal (EXT)                 //
    //     bit 8: Main Frequency by Communication                           //
    //     bit 2: JOG active                                                //
    //----------------------------------------------------------------------//
    C21xx[0x01] &=  0xfcfb; 
    C21xx[0x19] &=  0xfcfb; 


  
    if(pr[CTRLM]!=TQCPG){    // Speed control mode   //6a17j mask
        if((SLOWSPSHOW)&&(!SLOWSPSTR)&&(pr[GEAR_ACCT]!=0))//&&((pr[SysControl]&0x0400) == 0x0400) //[Dwell S curve,Lyabryan,2018/11/21]
        {
            fkey.uw.hi = pr[GEAR_ACCF]; // [IODLC, Lyabryan, 2016/11/11]
        }
        else{
            if(RUNNING==RUN)
                Speed_check = Sibocom_Speed_Priority(speed);
            else{
                Speed_check = speed;
                Sibocom_spflag.uw = 0;
            }
            
            switch(Speed_check){
                case 0:{
                    C21xx[0x01] |= 0x0200;
                    C21xx[0x19] |= 0x0200;
                    if ((PositionCom==0)&&(KEB_ON==0)){
                        if(EPS){
                            if (pr[FEPS] > pr[FMAX])
                                pr[FEPS] = pr[FMAX];
                            fkey.uw.hi = pr[FEPS];
                        }
                        else
						    fkey.ul = 0;
                        // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                    }
                }
                break;
                case 1:{
                    switch(pr[FMI0]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                case 2:{
                    switch(pr[FMI1]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                case 3:{
                    switch(pr[FMI2]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                case 4:{
                    switch(pr[FMI3]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                case 5:{
                    switch(pr[FMI4]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                case 6:{
                    switch(pr[FMI5]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                case 7:{
                    switch(pr[FMI6]){
                        case 1:{ //Low speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI7] > pr[FMAX])
                                    pr[FMI7] = pr[FMAX];
                                fkey.uw.hi = pr[FMI7];
                                // ]
                            }
                        }
                        break;
                        case 2:{//Low speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI8] > pr[FMAX])
                                    pr[FMI8] = pr[FMAX];
                                fkey.uw.hi = pr[FMI8];
                                // ]
                            }
                        }
                        break;
                        case 3:{//Low speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI9] > pr[FMAX])
                                    pr[FMI9] = pr[FMAX];
                                fkey.uw.hi = pr[FMI9];
                                // ]
                            }
                        }
                        break;
                        case 4:{//High speed1
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI10] > pr[FMAX])
                                    pr[FMI10] = pr[FMAX];
                                fkey.uw.hi = pr[FMI10];
                                // ]
                            }
                        }
                        break;
                        case 5:{//High speed2
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI11] > pr[FMAX])
                                    pr[FMI11] = pr[FMAX];
                                fkey.uw.hi = pr[FMI11];
                                // ]
                            }
                        }
                        break;
                        case 6:{//High speed3
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[FMI12] > pr[FMAX])
                                    pr[FMI12] = pr[FMAX];
                                fkey.uw.hi = pr[FMI12];
                                // ]
                            }
                        }
                        break;
                        case 0:{//Inspection speed
                            C21xx[0x01] |= 0x0200;
                            C21xx[0x19] |= 0x0200;
                            if ((PositionCom==0)&&(KEB_ON==0)){
                                // [ Main Frequency is Pr.04-00, Modify by DINO, 05/15/2009
                                if (pr[JOGF] > pr[FMAX])
                                    pr[JOGF] = pr[FMAX];
                                fkey.uw.hi = pr[JOGF];
                                // ]
                            }
                        }
                        break;
                        default:{
                        }
                        break;
                    }
                }
                break;
                default:
                break;
            }
        }

    }


    if ( EPS ){
        if (pr[FEPS] > COF_uwFepsLimit){
        	fkey.uw.hi = COF_uwFepsLimit;
        }
        if(fkey.uw.hi>COF_uwFepsLimit){
        	fkey.uw.hi = COF_uwFepsLimit;
        }
    }


    if((CMDRUN != RUN)&&(RUNNING == STOP)){   //[Pre-Torque BUG,Lyabryan,2019/01/08]            //[Modify preload function, Bernie, 01/20/2012]
	    if (pr[TQROFSE] == 0){	//07-19 轉矩命令偏壓來源
		    TqC_swTqOfstPu = 0;
        }
	    else if (pr[TQROFSE] == 1){
		    // [ Delete Analog Input Function 11, DINO, 06/17/2009
		    if (pr[AUI1_SL] == 3)
			    TqC_swTqOfstPu = (SWORD)AVIslFunVar;
		    else if (pr[ACI_SL] == 3)
			    TqC_swTqOfstPu = (SWORD)ACIslFunVar;
		    else if (pr[AUI2_SL] == 3)
			    TqC_swTqOfstPu = (SWORD)AUIslFunVar;
		    else
			    TqC_swTqOfstPu = 0;
		    // ]
	    }	    	
	    else if (pr[TQROFSE] == 2){
	        TqC_swTqOfstPu = ((SLONG)pr[TQOFSEV] * COF_uwTqratePu)>>10;  //Q(10+12)-10 = Q12
	    } 
        else if(pr[TQROFSE] == 4){                //[UD protocal, Bernie, 2012/12/05]
            TqC_swTqOfstPu = (SWORD)AVIslFunVar_1;
        }
	    else /*if (pr[TQROFSE]==3)*/{
	        switch(MFI_TQCSel){
	    	    default:
	    	    case 0:
	    		    swTemp = -(pr[TQOFSEVH] + pr[TQOFSEVM] + pr[TQOFSEVL]); //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 1:
	    		    swTemp = pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 2:
	    		    swTemp = pr[TQOFSEVM]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 3:
	    		    swTemp = pr[TQOFSEVM] + pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 4:
	    		    swTemp = pr[TQOFSEVH]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 5:
	    		    swTemp = pr[TQOFSEVH] + pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 6:
	    		    swTemp = pr[TQOFSEVH] + pr[TQOFSEVM]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    	    case 7:
	    		    swTemp = pr[TQOFSEVH] + pr[TQOFSEVM] + pr[TQOFSEVL]; //[Pre-Torque BUG,Lyabryan,2019/01/08]
	    		    break;
	    		
		    }                
	            
	        TqC_swTqOfstPu = ((SLONG)swTemp * COF_uwTqratePu)>>10;  //Q(10+12)-10 = Q12;
	    }
	}
}
#endif


/*
//-------------------------------------------------------------------
// OverLoad Derating, Carrier Freq change Rule:
//                    pr00-17 ---> cfstep1 ---> 4000Hz
//                    pr00-17 <--- cfstep1 <--- 4000Hz
//
// cf_step1 = [(pr00_17)+4000]/2,
// cf_step2 = 4000

// Load Current < 110%
void UpCFByUnderLoad(void)
{
    z1_cnt =0;
    z2_cnt =0;
    if(cfstep !=0){
        z0_cnt++;
        if(cfstep ==1){
            if(z0_cnt>=30){    // 3.0sec
                cfstep =0;
                cf_swOLCarry = cf_swCFSet;      // original setting
                z0_cnt =0;
            }
        }
        else if(cfstep ==2){
            if(z0_cnt>=20){      //2.0sec
                cfstep =1;
                cf_swOLCarry = cf_step1;
                z0_cnt =0;
            }
        }
    }
}

// (Temp>=80) or (fout<1.00Hz), Discontinue mode,
void DisDownCFByOverLoadTempOver80(void)
{

    if(IrmsAD >= 1911){    // 140% * (4095/3) = 1911, dino, 03/06/2007
        z0_cnt = 0;
        z1_cnt++;
        if(cfstep==0){
            if(z1_cnt>=10){    // 1.0sec-
                cfstep = 1;
                cf_swOLCarry = cf_step1;
                z1_cnt = 0;
            }
        }
        else if(cfstep==1){
            if(z1_cnt>=10){
                cfstep = 2;
                cf_swOLCarry = 4000;     // cf_step2
                z1_cnt =0;
            }
        }
    }
    else if(IrmsAD <= 1229){    // 90% * (4095/3) = 1229, dino, 03/06/2007
        UpCFByUnderLoad();
    }
}

// (Temp>=80) or (fout<1.0Hz)sine mode,
void SineDownCFByOverLoadTempOver80(void)
{
    if(IrmsAD >= 1775){    // 130% * (4095/3) = 1775, dino, 03/06/2007
        z1_cnt++;
        z2_cnt++;
        z0_cnt=0;
        if(cfstep==0){
            if((z1_cnt>=50)||(z2_cnt>=10)){    //1.0sec
                cfstep=1;
                cf_swOLCarry = cf_step1;
                z1_cnt =0;
                z2_cnt =0;
            }
        }
        else if(cfstep==1){
            if(z2_cnt>=10){        // 1.0 sec
                cfstep=2;
                cf_swOLCarry = 4000;     // cf_step2
                z2_cnt =0;
            }
        }
    }
    else if(IrmsAD >= 1502){    //  1.1<= IL <1.3, 110% * (4095/3) = 1502, dino, 03/06/2007
        z1_cnt++;
        z2_cnt=0;
        z0_cnt=0;
        if(cfstep==0){
            if(z1_cnt>=20){    //2.0 sec
                cfstep = 1;
                cf_swOLCarry = cf_step1;
                z1_cnt = 0;
                z2_cnt = 0;
            }
        }
        else if(cfstep==1){
            if(z1_cnt>=20){
                cfstep = 2;
                cf_swOLCarry = 4000;     // cf_step2
                z1_cnt = 0;
            }
        }
    }
    else if(IrmsAD <= 1229){    // 90% * (4095/3) = 1229, dino, 03/06/2007
        UpCFByUnderLoad();
    }
}

// (Temp<80)
// (Temp>=40) && (fout>1.00Hz), Discontinue mode
void DisDownCFByOverLoadTempUnder80(void)
{
    if (IrmsAD >= 2321){     // 170% * (4095/3) = 2321, dino, 03/06/2007
        z0_cnt = 0;
        z1_cnt++;
        if (cfstep==0){
            if (z1_cnt>=100){    // 10.0sec
                cfstep = 1;
                cf_swOLCarry = cf_step1;
                z1_cnt =0;
            }
        }
        else if(cfstep==1){
            if(z1_cnt>=30){    // 3.0sec
                cfstep = 2;
                cf_swOLCarry = 4000;     // cf_step2
                z1_cnt =0;
            }
        }
    }
    else if(IrmsAD <= 1229){    // 90% * (4095/3) = 1229, dino, 03/06/2007
       UpCFByUnderLoad();
    }
}

// (Temp<80)
// (Temp>=40) && (fout>1.00Hz), Sine mode
void SineDownCFByOverLoadTempUnder80(void)
{
    if (IrmsAD >= 2184){  // 160% * (4095/3) = 2184, dino, 03/06/2007
        z0_cnt = 0;
        z1_cnt++;
        z2_cnt++;
        if (cfstep==0){
            if((z1_cnt>=200)||(z2_cnt>=100)){
                cfstep=1;
                cf_swOLCarry = cf_step1;
                z1_cnt =0;
                z2_cnt =0;
            }
        }
        else if (cfstep==1){
            if (z2_cnt>=30){        // 3.0sec
                cfstep=2;
                cf_swOLCarry = 4000;    // cf_step2
                z2_cnt =0;
            }
        }
    }
    else if(IrmsAD >= 1775){    //  1.3<= IL <1.6, 130% * (4095/3) = 1775, dino, 03/06/2007
        z1_cnt++;
        z2_cnt=0;
        if (cfstep==0){
            if (z1_cnt>=200){    // 20.0sec
                cfstep = 1;
                cf_swOLCarry = cf_step1;
                z1_cnt =0;
                z2_cnt =0;
            }
        }
        else if (cfstep==1){
            if (z1_cnt>=50){        // 5.0sec
                cfstep=2;
                cf_swOLCarry = 4000;    // cf_step2
                z1_cnt =0;
            }
        }
    }
    else if(IrmsAD <=1229){    // 90% * (4095/3) = 1229, dino, 03/06/2007
        UpCFByUnderLoad();
    }
}
*/
void DownCFBbyOverLoad(void)
{
	SWORD swDefCarry;

	// [ Modify Derating Function, DINO, 05/18/2010
	//if ( pr[HPSPEC]>VFD220V43A ){  //Frame E
	if ( pr[HPSPEC]>VFD220V43A &&pr[HPSPEC]<VFD_SINGLEPHASE){  //Frame E   //[Single phase input, Bernie, 01/19/2012]
		// OL Derating Condition1: when Fcmd<3.00Hz & Fout<3.00Hz & Iout>120% => 3KHz
		//if (fcmd.uw.hi<=300 && fout.uw.hi<=300 && TB1_uwNewIrmsAD>prt_uwRatio120){
		if (fcmd.uw.hi<=200 && fout.uw.hi<=200 && TB1_uwNewIrmsAD>prt_uwRatio140){  //[modify derating function, Bernie, 2012/08/16]
				prt_swCon1Fc   = 3000;
			}
		else if (fout.uw.hi>500 || TB1_uwNewIrmsAD<prt_uwRatio90){
			prt_swCon1Fc = cf_swCFSet;
		}

		// OL Derating Condition2: Invalid
		prt_swCon2Fc  = cf_swCFSet;

		// OL Derating Condition3: when Fcmd<=5.00Hz & Iout>120% & TH>70oC => 3KHz
		//if (fout.uw.hi<=500 && TB1_uwNewIrmsAD>prt_uwRatio120 && IGBT_Temp>700){
        if (fout.uw.hi<=500 && TB1_uwNewIrmsAD>prt_uwRatio155 && IGBT_Temp>700){  //[modify derating function, Bernie, 2012/08/16]
			prt_swCon3Fc = 3000;
		}
		else if (fout.uw.hi>500 || TB1_uwNewIrmsAD<prt_uwRatio90){
			prt_swCon3Fc = cf_swCFSet;
		}
	}
	else{  //Frame C/D
		// OL Derating Condition1: when Fcmd<3.00Hz & Fout<3.00Hz & Iout>120% => 3KHz
		//if (fcmd.uw.hi<=300 && fout.uw.hi<=300 && TB1_uwNewIrmsAD>prt_uwRatio120){
        if (fcmd.uw.hi<=200 && fout.uw.hi<=200 && TB1_uwNewIrmsAD>prt_uwRatio140){  //[modify derating function, Bernie, 2012/08/16]
				prt_swCon1Fc   = 3000;
			}
		else if (fout.uw.hi>500 || TB1_uwNewIrmsAD<prt_uwRatio90){
			prt_swCon1Fc = cf_swCFSet;
		}

		// OL Derating Condition2: when Iout>205% => default Fc, Recover when Iout<=180%
		if(pr[HPSPEC]< VFD_SINGLEPHASE){        //[Single phase input, Bernie, 01/19/2012]
		    if (pr[HPSPEC]<=VFD110V43A)	//7.5 ~ 15Hp, Frame C
			    swDefCarry = 10000;
		    else
			    swDefCarry = 8000;		//15 ~ 30Hp, Frame D
        }
        else{                  //[Single phase input, Bernie, 01/19/2012]
            swDefCarry = 10000;  
        }

		if (cf_swCFSet > swDefCarry){
			if (TB1_uwNewIrmsAD > prt_uwRatio205){
				prt_swCon2Fc = swDefCarry;
			}
			else if (TB1_uwNewIrmsAD <= prt_uwRatio180){
				prt_swCon2Fc = cf_swCFSet;
			}
		}
		else{
			prt_swCon2Fc  = cf_swCFSet;
		}

		// OL Derating Condition3: when Fcmd<=5.00Hz & Iout>120% & TH>70oC => 3KHz
		//if (fout.uw.hi<=500 && TB1_uwNewIrmsAD>prt_uwRatio120 && IGBT_Temp>700){
        if (fout.uw.hi<=500 && TB1_uwNewIrmsAD>prt_uwRatio155 && IGBT_Temp>700){  //[modify derating function, Bernie, 2012/08/16]
			prt_swCon3Fc = 3000;
		}
		else if (fout.uw.hi>500 || TB1_uwNewIrmsAD<prt_uwRatio90){
			prt_swCon3Fc = cf_swCFSet;
		}
	}

	if (prt_swCon1Fc >= prt_swCon2Fc){
		swDefCarry = prt_swCon2Fc;
	}
	else{
		swDefCarry = prt_swCon1Fc;
	}

	if (swDefCarry >= prt_swCon3Fc){
		swDefCarry = prt_swCon3Fc;
	}

	if(swDefCarry >= cf_swOHCarry)
	    cf_swCFDerate = cf_swOHCarry;
	else
	    cf_swCFDerate = swDefCarry;
	// ]
}

// VFD-V: VFD have heat sink thermal Over 40HP

// RTH_IN:    =======T85======T90======T100
//        (1) ===========(B)==>>==(C)==>> OH
//        (2) =======<<=================
//-------------------------------------------------------
//  1~ 25HP(pr[I_RATE]>=22):
// 30~100HP(pr[I_RATE]> 22):
//-------------------------------------------------------
// RTH_OUT:   =======T75======T80=======T90
//        (1) ================(B)==(C)==>> OH
//        (2) =======<<=================

void Temp_vs_fpwm(void)
{
	// [ Modify Derating Function, DINO, 09/01/2010
	SWORD UpTemp, LoTemp, HPSPEC_temp;
	//UWORD uwCFLimit;
    
    if(pr[HPSPEC]>VFD_SINGLEPHASE)           //[Single phase input, Bernie, 01/19/2012]
        HPSPEC_temp = pr[HPSPEC]-VFD_SINGLEPHASE;
    else
        HPSPEC_temp = pr[HPSPEC]; //[Modify Derating Bug for Temp,Lyabryan,2019/11/01]
    if(pr[HPSPEC]<VFD300V23A && pr[HPSPEC]!=VFD300V43A && HPSPEC_temp<VFD300V23A){	// 7.5~30Hp, thermister inside, 85C, 90C    // 300V43A chg to frame D, Sean, 03/14/2011   	 
    	UpTemp = 900;
    	LoTemp = 850;
    }
    else{						// thermister outside, 75C, 80C
    	UpTemp = 800;
    	LoTemp = 750;
	}

	// TH1>=90.0 & keeping 2.0sec => 4kHz
	if (IGBT_Temp >= UpTemp){
		if (prt_ubOHSCnt >= 20){
			prt_ubOHSCnt = 0;
			cf_swOHCarry -= 1000;
			if (cf_swOHCarry < 4000){
				cf_swOHCarry = 4000;
			}
		}
		else{
			prt_ubOHSCnt++;
		}
		prt_ubOHRCnt = 0;
	}
	// TH1<85.0 & keeping 5.0sec => recover
	else if(IGBT_Temp < LoTemp){
		if (prt_ubOHRCnt >= 50){
			prt_ubOHRCnt = 0;
			cf_swOHCarry += 1000;
			if (cf_swOHCarry > cf_swCFSet){
				cf_swOHCarry = cf_swCFSet;
			}
		}
		else{
			prt_ubOHRCnt++;
		}
		prt_ubOHSCnt = 0;
	}
	else{
		prt_ubOHSCnt = 0;
		prt_ubOHRCnt = 0;
	}
	// ]
}

//-------- (TempAD-xl)/(xh-xl) * a + b, where a is (TempHi-TempLow), b is TempLow 
UWORD AD2Temp(UWORD xl, UWORD xh, UWORD TempAD,UWORD a, UWORD b)
{
    return ((((ULONG)(xh-TempAD)*a)/(UWORD)(xh-xl))+b);    
}    

UWORD Vth_to_Temp(UWORD TempAD, UWORD RealTemp)
{    
#if 1	// frame E oH2 update, Sean, 11/24/2010
    SWORD xtemp;

    if( TempAD >= CAP2K_DEG_N30 )
    {
        xtemp = -30;
    }
    else  if( TempAD >= CAP2K_DEG_N25 )
    {
        xtemp
        = AD2Temp( CAP2K_DEG_N25, CAP2K_DEG_N30, TempAD, ( ( -250 ) - ( -300 ) ), ( -300 ) );
    }
    else  if( TempAD >= CAP2K_DEG_N15 )
    {
        xtemp
        = AD2Temp( CAP2K_DEG_N15, CAP2K_DEG_N25, TempAD, ( ( -150 ) - ( -250 ) ), ( -250 ) );
    }
    else  if( TempAD >= CAP2K_DEG_0 )
    {
        xtemp = AD2Temp( CAP2K_DEG_0, CAP2K_DEG_N15, TempAD, ( 0 - ( -150 ) ), ( -150 ) );
    }
    else  if( TempAD >= CAP2K_DEG_15 )
    {
        xtemp = AD2Temp( CAP2K_DEG_15, CAP2K_DEG_0, TempAD, ( 150 - 0 ), 0 );
    }
    else  if( TempAD >= CAP2K_DEG_25 )
    {
        xtemp = AD2Temp( CAP2K_DEG_25, CAP2K_DEG_15, TempAD, ( 250 - 150 ), 150 );
    }
    else  if( TempAD >= CAP2K_DEG_35 )
    {
        xtemp = AD2Temp( CAP2K_DEG_35, CAP2K_DEG_25, TempAD, ( 350 - 250 ), 250 );
    }
    else  if( TempAD >= CAP2K_DEG_40 )
    {
        xtemp = AD2Temp( CAP2K_DEG_40, CAP2K_DEG_35, TempAD, ( 400 - 350 ), 350 );
    }
    else  if( TempAD >= CAP2K_DEG_41 )
    {
        xtemp = AD2Temp( CAP2K_DEG_41, CAP2K_DEG_40, TempAD, ( 410 - 400 ), 400 );
    }
    else  if( TempAD >= CAP2K_DEG_42 )
    {
        xtemp = AD2Temp( CAP2K_DEG_42, CAP2K_DEG_41, TempAD, ( 420 - 410 ), 410 );
    }
    else  if( TempAD >= CAP2K_DEG_43 )
    {
        xtemp = AD2Temp( CAP2K_DEG_43, CAP2K_DEG_42, TempAD, ( 430 - 420 ), 420 );
    }
    else  if( TempAD >= CAP2K_DEG_44 )
    {
        xtemp = AD2Temp( CAP2K_DEG_44, CAP2K_DEG_43, TempAD, ( 440 - 430 ), 430 );
    }
    else  if( TempAD >= CAP2K_DEG_45 )
    {
        xtemp = AD2Temp( CAP2K_DEG_45, CAP2K_DEG_44, TempAD, ( 450 - 440 ), 440 );
    }
    else  if( TempAD >= CAP2K_DEG_46 )
    {
        xtemp = AD2Temp( CAP2K_DEG_46, CAP2K_DEG_45, TempAD, ( 460 - 450 ), 450 );
    }
    else  if( TempAD >= CAP2K_DEG_47 )
    {
        xtemp = AD2Temp( CAP2K_DEG_47, CAP2K_DEG_46, TempAD, ( 470 - 460 ), 460 );
    }
    else  if( TempAD >= CAP2K_DEG_48 )
    {
        xtemp = AD2Temp( CAP2K_DEG_48, CAP2K_DEG_47, TempAD, ( 480 - 470 ), 470 );
    }
    else  if( TempAD >= CAP2K_DEG_49 )
    {
        xtemp = AD2Temp( CAP2K_DEG_49, CAP2K_DEG_48, TempAD, ( 490 - 480 ), 480 );
    }
    else  if( TempAD >= CAP2K_DEG_50 )
    {
        xtemp = AD2Temp( CAP2K_DEG_50, CAP2K_DEG_49, TempAD, ( 500 - 490 ), 490 );
    }
    else  if( TempAD >= CAP2K_DEG_51 )
    {
        xtemp = AD2Temp( CAP2K_DEG_51, CAP2K_DEG_50, TempAD, ( 510 - 500 ), 500 );
    }
    else  if( TempAD >= CAP2K_DEG_52 )
    {
        xtemp = AD2Temp( CAP2K_DEG_52, CAP2K_DEG_51, TempAD, ( 520 - 510 ), 510 );
    }
    else  if( TempAD >= CAP2K_DEG_53 )
    {
        xtemp = AD2Temp( CAP2K_DEG_53, CAP2K_DEG_52, TempAD, ( 530 - 520 ), 520 );
    }
    else  if( TempAD >= CAP2K_DEG_54 )
    {
        xtemp = AD2Temp( CAP2K_DEG_54, CAP2K_DEG_53, TempAD, ( 540 - 530 ), 530 );
    }
    else  if( TempAD >= CAP2K_DEG_55 )
    {
        xtemp = AD2Temp( CAP2K_DEG_55, CAP2K_DEG_54, TempAD, ( 550 - 540 ), 540 );
    }
    else  if( TempAD >= CAP2K_DEG_56 )
    {
        xtemp = AD2Temp( CAP2K_DEG_56, CAP2K_DEG_55, TempAD, ( 560 - 550 ), 550 );
    }
    else  if( TempAD >= CAP2K_DEG_57 )
    {
        xtemp = AD2Temp( CAP2K_DEG_57, CAP2K_DEG_56, TempAD, ( 570 - 560 ), 560 );
    }
    else  if( TempAD >= CAP2K_DEG_58 )
    {
        xtemp = AD2Temp( CAP2K_DEG_58, CAP2K_DEG_57, TempAD, ( 580 - 570 ), 570 );
    }
    else  if( TempAD >= CAP2K_DEG_59 )
    {
        xtemp = AD2Temp( CAP2K_DEG_59, CAP2K_DEG_58, TempAD, ( 590 - 580 ), 580 );
    }
    else  if( TempAD >= CAP2K_DEG_60 )
    {
        xtemp = AD2Temp( CAP2K_DEG_60, CAP2K_DEG_59, TempAD, ( 600 - 590 ), 590 );
    }
    else  if( TempAD >= CAP2K_DEG_61 )
    {
        xtemp = AD2Temp( CAP2K_DEG_61, CAP2K_DEG_60, TempAD, ( 610 - 600 ), 600 );
    }
    else  if( TempAD >= CAP2K_DEG_62 )
    {
        xtemp = AD2Temp( CAP2K_DEG_62, CAP2K_DEG_61, TempAD, ( 620 - 610 ), 610 );
    }
    else  if( TempAD >= CAP2K_DEG_63 )
    {
        xtemp = AD2Temp( CAP2K_DEG_63, CAP2K_DEG_62, TempAD, ( 630 - 620 ), 620 );
    }
    else  if( TempAD >= CAP2K_DEG_64 )
    {
        xtemp = AD2Temp( CAP2K_DEG_64, CAP2K_DEG_63, TempAD, ( 640 - 630 ), 630 );
    }
    else  if( TempAD >= CAP2K_DEG_65 )
    {
        xtemp = AD2Temp( CAP2K_DEG_65, CAP2K_DEG_64, TempAD, ( 650 - 640 ), 640 );
    }
    else  if( TempAD >= CAP2K_DEG_66 )
    {
        xtemp = AD2Temp( CAP2K_DEG_66, CAP2K_DEG_65, TempAD, ( 660 - 650 ), 650 );
    }
    else  if( TempAD >= CAP2K_DEG_67 )
    {
        xtemp = AD2Temp( CAP2K_DEG_67, CAP2K_DEG_66, TempAD, ( 670 - 660 ), 660 );
    }
    else  if( TempAD >= CAP2K_DEG_68 )
    {
        xtemp = AD2Temp( CAP2K_DEG_68, CAP2K_DEG_67, TempAD, ( 680 - 670 ), 670 );
    }
    else  if( TempAD >= CAP2K_DEG_69 )
    {
        xtemp = AD2Temp( CAP2K_DEG_69, CAP2K_DEG_68, TempAD, ( 690 - 680 ), 680 );
    }
    else  if( TempAD >= CAP2K_DEG_70 )
    {
        xtemp = AD2Temp( CAP2K_DEG_70, CAP2K_DEG_69, TempAD, ( 700 - 690 ), 690 );
    }
    else  if( TempAD >= CAP2K_DEG_71 )
    {
        xtemp = AD2Temp( CAP2K_DEG_71, CAP2K_DEG_70, TempAD, ( 710 - 700 ), 700 );
    }
    else  if( TempAD >= CAP2K_DEG_72 )
    {
        xtemp = AD2Temp( CAP2K_DEG_72, CAP2K_DEG_71, TempAD, ( 720 - 710 ), 710 );
    }
    else  if( TempAD >= CAP2K_DEG_73 )
    {
        xtemp = AD2Temp( CAP2K_DEG_73, CAP2K_DEG_72, TempAD, ( 730 - 720 ), 720 );
    }
    else  if( TempAD >= CAP2K_DEG_74 )
    {
        xtemp = AD2Temp( CAP2K_DEG_74, CAP2K_DEG_73, TempAD, ( 740 - 730 ), 730 );
    }
    else  if( TempAD >= CAP2K_DEG_75 )
    {
        xtemp = AD2Temp( CAP2K_DEG_75, CAP2K_DEG_74, TempAD, ( 750 - 740 ), 740 );
    }
    else  if( TempAD >= CAP2K_DEG_76 )
    {
        xtemp = AD2Temp( CAP2K_DEG_76, CAP2K_DEG_75, TempAD, ( 760 - 750 ), 750 );
    }
    else  if( TempAD >= CAP2K_DEG_77 )
    {
        xtemp = AD2Temp( CAP2K_DEG_77, CAP2K_DEG_76, TempAD, ( 770 - 760 ), 760 );
    }
    else  if( TempAD >= CAP2K_DEG_78 )
    {
        xtemp = AD2Temp( CAP2K_DEG_78, CAP2K_DEG_77, TempAD, ( 780 - 770 ), 770 );
    }
    else  if( TempAD >= CAP2K_DEG_79 )
    {
        xtemp = AD2Temp( CAP2K_DEG_79, CAP2K_DEG_78, TempAD, ( 790 - 780 ), 780 );
    }
    else  if( TempAD >= CAP2K_DEG_80 )
    {
        xtemp = AD2Temp( CAP2K_DEG_80, CAP2K_DEG_79, TempAD, ( 800 - 790 ), 790 );
    }
    else  if( TempAD >= CAP2K_DEG_81 )
    {
        xtemp = AD2Temp( CAP2K_DEG_81, CAP2K_DEG_80, TempAD, ( 810 - 800 ), 800 );
    }
    else  if( TempAD >= CAP2K_DEG_82 )
    {
        xtemp = AD2Temp( CAP2K_DEG_82, CAP2K_DEG_81, TempAD, ( 820 - 810 ), 810 );
    }
    else  if( TempAD >= CAP2K_DEG_83 )
    {
        xtemp = AD2Temp( CAP2K_DEG_83, CAP2K_DEG_82, TempAD, ( 830 - 820 ), 820 );
    }
    else  if( TempAD >= CAP2K_DEG_84 )
    {
        xtemp = AD2Temp( CAP2K_DEG_84, CAP2K_DEG_83, TempAD, ( 840 - 830 ), 830 );
    }
    else  if( TempAD >= CAP2K_DEG_85 )
    {
        xtemp = AD2Temp( CAP2K_DEG_85, CAP2K_DEG_84, TempAD, ( 850 - 840 ), 840 );
    }
    else  if( TempAD >= CAP2K_DEG_86 )
    {
        xtemp = AD2Temp( CAP2K_DEG_86, CAP2K_DEG_85, TempAD, ( 860 - 850 ), 850 );
    }
    else  if( TempAD >= CAP2K_DEG_87 )
    {
        xtemp = AD2Temp( CAP2K_DEG_87, CAP2K_DEG_86, TempAD, ( 870 - 860 ), 860 );
    }
    else  if( TempAD >= CAP2K_DEG_88 )
    {
        xtemp = AD2Temp( CAP2K_DEG_88, CAP2K_DEG_87, TempAD, ( 880 - 870 ), 870 );
    }
    else  if( TempAD >= CAP2K_DEG_89 )
    {
        xtemp = AD2Temp( CAP2K_DEG_89, CAP2K_DEG_88, TempAD, ( 890 - 880 ), 880 );
    }
    else  if( TempAD >= CAP2K_DEG_90 )
    {
        xtemp = AD2Temp( CAP2K_DEG_90, CAP2K_DEG_89, TempAD, ( 900 - 890 ), 890 );
    }
    else  if( TempAD >= CAP2K_DEG_91 )
    {
        xtemp = AD2Temp( CAP2K_DEG_91, CAP2K_DEG_90, TempAD, ( 910 - 900 ), 900 );
    }
    else  if( TempAD >= CAP2K_DEG_92 )
    {
        xtemp = AD2Temp( CAP2K_DEG_92, CAP2K_DEG_91, TempAD, ( 920 - 910 ), 910 );
    }
    else  if( TempAD >= CAP2K_DEG_93 )
    {
        xtemp = AD2Temp( CAP2K_DEG_93, CAP2K_DEG_92, TempAD, ( 930 - 920 ), 920 );
    }
    else  if( TempAD >= CAP2K_DEG_94 )
    {
        xtemp = AD2Temp( CAP2K_DEG_94, CAP2K_DEG_93, TempAD, ( 940 - 930 ), 930 );
    }
    else  if( TempAD >= CAP2K_DEG_95 )
    {
        xtemp = AD2Temp( CAP2K_DEG_95, CAP2K_DEG_94, TempAD, ( 950 - 940 ), 940 );
    }
    else  if( TempAD >= CAP2K_DEG_96 )
    {
        xtemp = AD2Temp( CAP2K_DEG_96, CAP2K_DEG_95, TempAD, ( 960 - 950 ), 950 );
    }
    else  if( TempAD >= CAP2K_DEG_97 )
    {
        xtemp = AD2Temp( CAP2K_DEG_97, CAP2K_DEG_96, TempAD, ( 970 - 960 ), 960 );
    }
    else  if( TempAD >= CAP2K_DEG_98 )
    {
        xtemp = AD2Temp( CAP2K_DEG_98, CAP2K_DEG_97, TempAD, ( 980 - 970 ), 970 );
    }
    else  if( TempAD >= CAP2K_DEG_99 )
    {
        xtemp = AD2Temp( CAP2K_DEG_99, CAP2K_DEG_98, TempAD, ( 990 - 980 ), 980 );
    }
    else  if( TempAD >= CAP2K_DEG_100 )
    {
        xtemp = AD2Temp( CAP2K_DEG_100, CAP2K_DEG_99, TempAD, ( 1000 - 990 ), 990 );
    }
    else  if( TempAD >= CAP2K_DEG_110 )
    {
        xtemp = AD2Temp( CAP2K_DEG_110, CAP2K_DEG_100, TempAD, ( 1100 - 1000 ), 1000 );
    }
    else  if( TempAD >= CAP2K_DEG_130 )
    {
        xtemp = AD2Temp( CAP2K_DEG_130, CAP2K_DEG_110, TempAD, ( 1300 - 1100 ), 1100 );
    }
    else  if( TempAD >= CAP2K_DEG_150 )
    {
        xtemp = AD2Temp( CAP2K_DEG_150, CAP2K_DEG_130, TempAD, ( 1500 - 1300 ), 1300 );
    }
    else
    {
        xtemp = 1500;
    }

    RealTemp = /* ( RealTemp + */xtemp /*)>>1*/;
    return RealTemp;

#else	
	UWORD xtemp;	
    
    TempAD = TempAD >> 6;
    
    if (RTH_IN){    // Rth Inside, OH=100 degree
        if (TempAD<=IN_DEG_0){
            if (TempAD<=IN_DEG_25){
                if (TempAD<=IN_DEG_50){
                    if (TempAD<=IN_DEG_80){
                        if (TempAD<=IN_DEG_100){
                            if (TempAD <= IN_DEG_150)
                                xtemp = 1500;
                            else
                                xtemp = AD2Temp(IN_DEG_150, IN_DEG_100, TempAD,(1500-1000),1000);
                        }       
                        else
                            xtemp = AD2Temp(IN_DEG_100, IN_DEG_80, TempAD,(1000-800),800);
                    }
                    else
                       xtemp = AD2Temp(IN_DEG_80, IN_DEG_50, TempAD,(800-500),500);
                }
                else        
                    xtemp = AD2Temp(IN_DEG_50, IN_DEG_25, TempAD,(500-250),250);
            }
            else        
                xtemp = AD2Temp(IN_DEG_25, IN_DEG_0, TempAD,(250-0),0);
        }
        else
            xtemp = 0;
    }
    else {  // Rth Outside, OH=90 degree
        if (TempAD<=OUT_DEG_0){
            if (TempAD<=OUT_DEG_25){
                if (TempAD<=OUT_DEG_50){
                    if (TempAD<=OUT_DEG_80){
                        if (TempAD<=OUT_DEG_100){
                            if (TempAD <= OUT_DEG_150)
                                xtemp = 1500;
                            else
                                xtemp = AD2Temp(OUT_DEG_150, OUT_DEG_100, TempAD,(1500-1000),1000);
                        }       
                        else
                            xtemp = AD2Temp(OUT_DEG_100, OUT_DEG_80, TempAD,(1000-800),800);
                    }
                    else
                       xtemp = AD2Temp(OUT_DEG_80, OUT_DEG_50, TempAD,(800-500),500);
                }
                else        
                    xtemp = AD2Temp(OUT_DEG_50, OUT_DEG_25, TempAD,(500-250),250);
            }
            else        
                xtemp = AD2Temp(OUT_DEG_25, OUT_DEG_0, TempAD,(250-0),0);
        }
        else
            xtemp = 0;
    }
    RealTemp = (RealTemp + xtemp)>>1 ;
    return RealTemp;
#endif    
}



SWORD thermal(UBYTE frame, SWORD TempAD)
{
    SWORD swTmpC ;
    SLONG_UNION Thermal ;
    UBYTE gain1, gain2, gain3;
    UWORD gain4;
    ULONG gain5;
 
    //----------------------------------------------------------------
    // swTmpC = X = 0 ~ 1023
    //
    // Frame C IGBT NTC formula:
    // temperature = -0.00000033041*(L3^3)+0.00057914*(L3^2)-0.4366*L3+154.3386
    // Thermal.sl  = (-(AD*33)*(AD*43))/65536*AD + 38*(AD^2) - 28613*AD + (10114734+32768) )
    // temperature = Thermal.sw.hi
    //
    // Frame D IGBT NTC formula:
    // temperature = -0.00000028573*(AD^3)+0.00048782*(AD^2)-0.3633*AD+148.5111
    // Thermal.sl  = (-(AD*35)*(AD*35))/65536*AD + 32*(AD^2) - 23809*AD + (9732823+32768) )
    // temperature = Thermal.sw.hi

    //--for Sep pilot run
    // Frame D IGBT NTC formula:
    // temperature = -0.00000028878*(AD^3)+0.00050839*(AD^2)-0.4178*AD+179.6553
    // Thermal.sl  = (-(AD*41)*(AD*30))/65536*AD + 33*(AD^2) - 27381*AD + (11773889+32768) )
    // temperature = Thermal.sw.hi

    //
    // Heatsink NTC formula:
    // temperature =-2.8517e-007*(AD^3)+4.8892e-004*(AD^2)-0.3700*AD+152.7173
    // Thermal.sl = ((AD*34)*(AD*36))/65536*AD - 32*(AD^2) - 24248*AD + (10041249+32768) )
    // temperature = Thermal.sw.hi
    //
    //----------------------------------------------------------------
    switch(frame){
        default:
        case CFRAME:
			gain1=33;
			gain2=43;
			gain3=38;
			gain4=28613;
			gain5=10114734;
			break;

        case DFRAME:
    		gain1=33;
    		gain2=37;
    		gain3=32;
    		gain4=25136;
    		gain5=9570654;
			break;
        case EFRAME:
#if 1	// frame E temp curve update, Sean, 11/24/2010
   			gain1=30;
			gain2=52;
			gain3=42;
			gain4=31346;
			gain5=11624087;			
#else        	
   			gain1=34;
   			gain2=36;
   			gain3=32;
   			gain4=24248;
   			gain5=10041249;
   			break;
#endif   			
    }
 
    swTmpC = (SWORD)(TempAD >> 2);

    Thermal.sl = (SLONG)( swTmpC * gain1 ) * ((UWORD)swTmpC * gain2) ;
    Thermal.sl = -(SLONG)Thermal.sw.hi * swTmpC + (SLONG)swTmpC * gain3 * swTmpC - (SLONG)swTmpC * gain4 + (gain5+32768) ;
    Thermal.sl *= 10;
   
    return Thermal.sw.hi;
}
 


void VFD_Timer(void)
{
    UBYTE ubFrame, HPSPEC_temp;

    TB_1sec = 0;
    PWR_Second ++;
    


#if ENDAT
	//--- test, transmit EnDat power on 3.0sec later, 08/27/2008
	//if ( (TB_2sec==0)&&(pr[PG_TYPE]==SIN_ENDAT) ){  //[PGABD Output error, Lyabryan, 2015/08/13]
	if ( (TB_2sec==0)&&((pr[PG_TYPE]==SIN_ENDAT)||(pr[PG_TYPE]==SIN_HIPER)) ){	//[PGHSD Add Hiperface, Jerry Yu, 2019/11/15]
		if ( PWR_Second==2 ){
			TB_2sec = 1;
			InitSCI0();
		}
	}
#endif

    if (RUNNING==RUN)
    	MotorRUNSec++;
    
    if (prt_ubPHLCnt>=100){
		prt_ubPHLCnt = 0;
		uwPHLCNTsec++;
    }
	
    if (uwPHLCNTsec>=3600){
		uwPHLCNTsec = 0;
		if (pr[PHLHOUR]<65535){
	    	pr[PHLHOUR]++;
	    	write_ep(0,PHLHOUR,pr[PHLHOUR]);
		}		
    }    	    
    
    if (PWR_Second>=60){    // vfd POWER ON timer
        PWR_Second = 0;
        pr[PWR_MIN]++;
        if (pr[PWR_MIN]>=1440){
            pr[PWR_MIN] = 0;
            pr[PWR_DAY]++;
            write_ep(0,PWR_DAY,pr[PWR_DAY]);
        }
    }
    
    if (MotorRUNSec>=60){    // Motor RUN timer
        MotorRUNSec = 0;
        pr[RUNMIN]++;
        if (pr[RUNMIN]>1439){
            pr[RUNMIN] = 0;
            pr[RUNDAY]++;
            write_ep(0,RUNDAY,pr[RUNDAY]);
        }
    }

        
    /*---------[ oH ]---------------*/
    //Real Temperature is small when AD value is big.
      HPSPEC_temp = pr[HPSPEC];            //[Single phase input, Bernie, 01/19/2012]
      if(pr[HPSPEC]>VFD_SINGLEPHASE)
          HPSPEC_temp -= VFD_SINGLEPHASE;
      //if (pr[HPSPEC]>=VFD300V23A && pr[HPSPEC]!=VFD300V43A){		    	// Over 40HP have Thermo in Heat sink	// 300V43A chg to frame D, Sean, 03/14/2011
      if (HPSPEC_temp>=VFD300V23A && HPSPEC_temp!=VFD300V43A){	
#if SH7149
	    HS_Temp = Vth_to_Temp(AN2, HS_Temp);    // Heat Sink Temperature
#else
	   HS_Temp = Vth_to_Temp(TH2adLPF.sw.hi, HS_Temp); // Sean, 11/24/2010
#endif
	    
    	if ( (pr[PROTBIT]&0x8000)==0 ){             // Bit15, OH2, dino, 05/24/2007
		    if ((Error==0)||(Error==bb_ERR)){
                if (HS_Temp>=(SWORD)HS_OHLevel)
                    Error = oH2_ERR;    
                //if (AN8>4000)		// dino, 03/29/2007
                if (AN02>4000)		// dino, 03/29/2007
                    Error = tH2o_ERR;               //Thermo Open Error
		    }
		    
		    //------ HeatSink Over heat Warning check -------------------//
		    if (HS_Temp>=(SWORD)pr[OHWL]){
                WarnDisplaySave();
		  	    WarnCode = oH2_WARN;
		    }
		    else if (HS_Temp<(SWORD)(pr[OHWL]-100)){	// dino, 03/07/2007
                if ((Error==0)&&(WarnCode==oH2_WARN)){
           		    WarnCode = 0;
        		    Keypad_Page = Keypad_PageTmp;
           	    }
		    }
		}  // End if (pr[PROTBIT]&0x8000)==0
	}

#if SH7149
	IGBT_Temp = Vth_to_Temp(AN6, IGBT_Temp);    // IGBT Temperature
#else
	//if ( pr[HPSPEC]<VFD150V23A ){ ubFrame = CFRAME; }
	//else if ( pr[HPSPEC]>=VFD300V23A && pr[HPSPEC]!=VFD300V43A ){ ubFrame = EFRAME; }	//  IGBT_Temp & HS_Temp is the same in Frame E,Add by DINO, 09/04/2008	// 300V43A chg to frame D, Sean, 03/14/2011
	//else { ubFrame = DFRAME; }
	if ( HPSPEC_temp<VFD150V23A ){ ubFrame = CFRAME; }    //[Single phase input, Bernie, 01/19/2012]
	else if ( HPSPEC_temp>=VFD300V23A && HPSPEC_temp!=VFD300V43A ){ ubFrame = EFRAME; }	//  IGBT_Temp & HS_Temp is the same in Frame E,Add by DINO, 09/04/2008	// 300V43A chg to frame D, Sean, 03/14/2011
	else { ubFrame = DFRAME; }

	IGBT_Temp = thermal(ubFrame, TH1adLPF.sw.hi);	// dino, 10/18/2007
#endif
    if ( (pr[PROTBIT]&0x8000)==0 ){             // Bit15, OH1, SCOTTY, 10/11/2007    
    	if ((Error==0)||(Error==bb_ERR)){
	    	if (IGBT_Temp>=(SWORD)IGBT_OHLevel)
	        	Error = oH1_ERR;
	    #if NEWIEDCB
	    	//if (AN9>4000)	// IO Define, Sean, 06/25/2010
	    	if (AN03>4000)	// IO Define, Sean, 06/25/2010
	    #else
	    	if (AN7>4000)	// dino, 03/01/2010
	    #endif
	        	Error = tH1o_ERR;
    	}
    //------ IGBT Over heat Warning check -------------------//
    	if (IGBT_Temp>=(SWORD)pr[OHWL]){
	    	WarnDisplaySave();
	    	WarnCode = oH1_WARN;
    	}
    	else if (IGBT_Temp<(SWORD)(pr[OHWL]-50)){
	    	if ((Error==0)&&(WarnCode==oH1_WARN)){
            	WarnCode = 0;      
       	    	Keypad_Page = Keypad_PageTmp;
	    	}        
    	}
	} // End if (pr[PROTBIT]&0x8000)==0
	
    /*------ Fan Control = 0 mode ------*/
    if (!RUNNING) {
        if (fanoffct <= 60)
            fanoffct++;
    }
    
    // Auto Saving Timer
    if (pr[PWRSAVE]!=0){
        if (pr[CTRLM] != FOCPG){
            if ((NORMALSP==1)&&(TB1_uwPhi>=542)){
                if (PWRSaveCNT != 0xFF)
                    PWRSaveCNT ++;
            }
            else
                PWRSaveCNT = 0;
        }
    }
    else{
        PWRSaveCNT = 0;
    }
}

#define FAN_ON_TEMP   600    // 60 degree_C
#define FAN_OFF_TEMP  400    // 40 degree_C

void FanControl(void) 
{
    UBYTE ubFanEn;

    switch (pr[FAN]) {
        default:
        case 0:    //always ON
        	ubFanEn = 1;			// FAN ON ADDED BY SCOTTY 10/15/2007	
            break;        
        case 1:    // RUN ON, stop 60sec OFF
            if(RUNNING == RUN) {	// Change FAN enable condition, DINO, 04/27/2010
                fanoffct = 0;
                ubFanEn = 1;		// FAN ON ADDED BY SCOTTY 10/15/2007	
            }
            else {
                if(fanoffct >= 60)	// delay 1 minute
                    ubFanEn = 0;	// FAN OFF ADDED BY SCOTTY 10/15/2007	
                else
                	ubFanEn = FAN_ENABLE;
            }
            break;        
        case 2:    // run on, stop off
            if(RUNNING == RUN)		// Change FAN enable condition, DINO, 04/27/2010
            	ubFanEn = 1;		// FAN ON ADDED BY SCOTTY 10/15/2007	
            else
            	ubFanEn = 0;		// FAN OFF ADDED BY SCOTTY 10/15/2007	
            break;        
        case 3:    //depends on heatsink TEMP. 60 Degree-C ON, 40 OFF
            if(IGBT_Temp >= (SWORD)FAN_ON_TEMP)
            	ubFanEn = 1;		// FAN ON ADDED BY SCOTTY 10/15/2007	
            else if(IGBT_Temp < (SWORD)FAN_OFF_TEMP)
            	ubFanEn = 0;		// FAN OFF ADDED BY SCOTTY 10/15/2007	
            else
            	ubFanEn = FAN_ENABLE;
            break;
        case 4:    // always OFF
            ubFanEn = 0;			//FAN OFF ADDED BY SCOTTY 10/15/2007
            break;
    }

    /*------ 1HP don't have Fan, Fan always OFF, 
             else would happened "Fan Locked" ------------------------------*/
    if (pr[HPSPEC]<=VFD007V23A /*&& pr[HPSPEC] != VFD037V21A*/)      //[Single phase input, Bernie, 01/19/2012]
		FAN_ENABLE = 0;
	else if ( EPS )					// Add by dino, 02/18/2008
    	FAN_ENABLE = 0;
    else if (dcbusADAVG < LVS4ad)	// Add by dino, 01/30/2008
    	FAN_ENABLE = 0;
    else
    	FAN_ENABLE = ubFanEn;

}

void ErrorResetInit(void)
{
    uwRetryCnt = pr[RESETCNT];     //[Add auto restart after fault, Bernie, 06/06/12]
    uwRetryTimeCnt = pr[RESETINTERVAL]*10;
    //ubRetryTimes =0;


}


void main(void)
{
    UWORD ax, bx;
    UBYTE i,ubRxCnt;  //[For IED PG-Card, Sampo, 02/14/2010]
    SWORD swTemp1,swTemp2,swTemp3;
    SWORD swSpdP_tmp,swSpdN_tmp;   //6a17j
    SLONG (*mfai_ptr)(UBYTE,SWORD);
    UWORD uwTemp;
    ULONG ulTemp;	
    ULONG DATASEL;	// dino, 03/08/2007
    ULONG_UNION FDisplay;
	UBYTE ubReturn;    //[For IED PG-Card, Sampo, 02/14/2010]
    UWORD_UNION uwCRC; //[For IED PG-Card, Sampo, 02/14/2010]
    UWORD uwPGA, uwPGB, uwPGZ, uwHall;    //[Used For PG ABD Test, Bernie, 10/28/2011]
    ULONG ulPGSWCnt;                      //[Used For PG ABD Test, Bernie, 10/28/2011]
    UBYTE ubPGCard;                       //[Modify PG Type Define, Bernie, 12/05/2011]
    UWORD uwHi, uwLow, uwMid;             //[Modify PG Type Define, Bernie, 12/05/2011]
    SWORD swAD_temp;
    SLONG aa;
    UWORD wait, j;
	//[ //[DLC function, Henry, 2016/07/20]
	#if FRAM_BUF	// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 
	frm_vdRead();
    #endif	
	frm_vdDLCRead(); //[DLC function, Henry, 2016/07/20]
    ax = read_ep(FLOOR_PAGE);
    if(ax ==0){
        for(bx = 0; bx<EPMAX; bx++){
            //attr[bx].ati = attr1[bx].ati;
            //attr[bx].min = attr1[bx].min;
            //attr[bx].max = attr1[bx].max;
            //attr[bx].def = attr1[bx].def;
            attr[bx] = attr1[bx];
        }
    }
    else if(ax == 1){
      for(bx = 0; bx<EPMAX; bx++){
        if((bx < DLC_PR) || (bx >= GROUP5)){
          attr[bx] = attr1[bx];
        }
        else{
      	  attr[bx] = attr_DLC1[bx-DLC_PR];
        }
      }
    }
    else if(ax == 2){// JINGDO
      for(bx = 0; bx<EPMAX; bx++){
        if((bx < DLC_PR) || (bx >= GROUP5)){
          attr[bx] = attr1[bx];
        }
        else{
      	  attr[bx] = attr_DLC2[bx-DLC_PR];
        }
      }
  	}
    else if(ax == 3){  //[adjust floor position adjust,Aevin,2018/06/19]
      for(bx = 0; bx<EPMAX; bx++){
        if((bx < DLC_PR) || (bx >= GROUP5)){
          attr[bx] = attr1[bx];
        }
        else{
      	  attr[bx] = attr_DLC3[bx-DLC_PR];
        }
      }
  	}
    else if(ax == 4){  //[ //[adjust floor position,Henry,2019/01/07]
      for(bx = 0; bx<EPMAX; bx++){
        if((bx < DLC_PR) || (bx >= GROUP5)){
          attr[bx] = attr1[bx];
        }
        else{
      	  attr[bx] = attr_DLC_adjst[bx-DLC_PR];
        }
      }
  	}    
    else if(ax == 5){  //[ //[adjust floor position,Henry,2019/01/07]
      for(bx = 0; bx<EPMAX; bx++){
        if((bx < DLC_PR) || (bx >= GROUP5)){
          attr[bx] = attr1[bx];
        }
        else{
      	  attr[bx] = attr_DLC_adjst2[bx-DLC_PR];
        }
      }
  	}    
    else if(ax == 6){  //[ //[adjust floor position,Henry,2019/01/07]
      for(bx = 0; bx<EPMAX; bx++){
        if((bx < DLC_PR) || (bx >= GROUP5)){
          attr[bx] = attr1[bx];
        }
        else{
      	  attr[bx] = attr_DLC_adjst3[bx-DLC_PR];
        }
      }
  	}
	//] //[adjust floor position,Henry,2019/01/07]
    
    TB1_uw0p5secCnt = 0;
    //usb_cstd_main_task((USB_VP_INT_t)0);   //USB FUNCTION BERNIE
    PGCD_AF_FLAG = 0; 
    RUN_sequence.uw = 0;		//ADDED BY SC 12/04/2007, 06/24/2010
    Run_Time_srquence.uw = 0;   //[Russia time srequence for IM, Bernie, 2015/07/13]
    Init_SpDtPG1();
    
    Driver_ID_Rec(); //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
    
//---ADDED BY DINO 09/22/2008---
	ax = read_ep(PSW_SET); 
    if (ax!=0)
    	PRLOCK = 1;
//--- End 09/22/2008
    for(j=0;j<=49;j++) //[Last Key parameter,Lyabryan,2020/02/05]
        RSP_uwRecent[j] = 0;

	//--- Initialize BUFFER Data, Add by DINO, 10/27/2008
	rec_uwFault1 = read_ep(ERR_REC1);
	rec_uwFault2 = read_ep(ERR_REC2);
	rec_uwFault3 = read_ep(ERR_REC3);
	rec_uwFault4 = read_ep(ERR_REC4);
	rec_uwFault5 = read_ep(ERR_REC5);
	rec_uwFault6 = read_ep(ERR_REC6);
    //[special,increase error record, 2018/09/20
    rec_uwError1_1 = read_ep(FOUT_REC1);
    rec_uwError1_2 = read_ep(DCBUS_REC1);
    rec_uwError1_3 = read_ep(ISUM_REC1);
    rec_uwError1_4 = read_ep(TH_TEMP1);
    rec_uwError2_1 = read_ep(FOUT_REC2);
    rec_uwError2_2 = read_ep(DCBUS_REC2);
    rec_uwError2_3 = read_ep(ISUM_REC2);
    rec_uwError2_4 = read_ep(TH_TEMP2);
    rec_uwError3_1 = read_ep(FOUT_REC3);
    rec_uwError3_2 = read_ep(DCBUS_REC3);
    rec_uwError3_3 = read_ep(ISUM_REC3);
    rec_uwError3_4 = read_ep(TH_TEMP3);
    rec_uwError4_1 = read_ep(FOUT_REC4);
    rec_uwError4_2 = read_ep(DCBUS_REC4);
    rec_uwError4_3 = read_ep(ISUM_REC4);
    rec_uwError4_4 = read_ep(TH_TEMP4);
    rec_uwError5_1 = read_ep(FOUT_REC5);
    rec_uwError5_2 = read_ep(DCBUS_REC5);
    rec_uwError5_3 = read_ep(ISUM_REC5);
    rec_uwError5_4 = read_ep(TH_TEMP5);
    //special,increase error record, 2018/09/20]
	rec_uwFfbk   = read_ep(FFBK_REC);
	rec_uwFcmd   = read_ep(FOUT_REC);
	rec_uwVout   = read_ep(VOUT_REC);
	rec_uwDcbus  = read_ep(DCBUS_REC);
	rec_uwIsum   = read_ep(ISUM_REC);
	rec_uwIGBT   = read_ep(TH_TEMP);
	rec_uwSRY    = read_ep(SRYREC);	
	rec_uwPWRmin = read_ep(PWR_MIN);
	rec_uwRUNmin = read_ep(RUNMIN);
	TQRCMemswPer = read_ep(TQREF);
	uwFkeypad	 = read_ep(FMAIN);
	C20xx[0x01]  = read_ep(FCMAIN);
	MI_INVMem  	 = read_ep(MI_INV);
	MO_INVMem    = read_ep(MO_INV);
	PGHOMEMem    = read_ep(PGHOME);
	// [ Add Fault Record Data, DINO, 06/11/2009
	rec_uwErrMin1 = read_ep(ERR_MIN1);
	rec_uwErrDay1 = read_ep(ERR_DAY1);
	rec_uwErrMin2 = read_ep(ERR_MIN2);
	rec_uwErrDay2 = read_ep(ERR_DAY2);
	rec_uwErrMin3 = read_ep(ERR_MIN3);
	rec_uwErrDay3 = read_ep(ERR_DAY3);
	rec_uwErrMin4 = read_ep(ERR_MIN4);
	rec_uwErrDay4 = read_ep(ERR_DAY4);
	rec_uwErrMin5 = read_ep(ERR_MIN5);
	rec_uwErrDay5 = read_ep(ERR_DAY5);
	rec_uwErrMin6 = read_ep(ERR_MIN6);
	rec_uwErrDay6 = read_ep(ERR_DAY6);
	rec_uwFkey	 = read_ep(FKEY_REC);
    rec_uwPower  = read_ep(POWER_REC);
    rec_uwTorq   = read_ep(TQ_REC);
    rec_uwMFI    = read_ep(MFI_REC);
    rec_uwMFO    = read_ep(MFO_REC);
	rec_uwState  = read_ep(STATE_REC);
	// ]
    pwm_ulMOL.uw.hi = read_ep(EOL_RECODHI);   //[add for UL EoL Verification,Bernie, 2013/04/22]
    pwm_ulMOL.uw.low = read_ep(EOL_RECODLO);
    
    rec_uwRetryCnt = read_ep(RESETCNT);    //[Add auto restart after fault, Bernie, 06/06/12]
 
    Pgz_Disconnect_Init(); //[Zphase broken, Lyabryan, 2015/09/17]

    btArtemisEnable = read_ep(Client_Mode); //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]


	//#16550 Artemis default value, James, 20210520
//#if Artemis_ENABLE
    //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]
    if(btArtemisEnable)
    {
        if((read_ep(SW_VER) != SWVERS_H) || (read_ep(DATECODE) != DateCode))
        {
        	write_ep(BLK_WRITE,SW_VER, SWVERS_H);
        	write_ep(BLK_WRITE,DATECODE, DateCode);
        	pr[CAN_BURD] = 2;
        	write_ep(BLK_WRITE,CAN_BURD, 2);
        	DLC_Initial_value();
        }
    }
//#endif

    InitValue();   //BERNIE MASK

    //[ //[Running Dir Count,Special,2018/08/17]
    //Running Dir Count 
    if(pr[IR_ENABLE]==1){
        IRF_ENABLE = 1;
		IRF_Warning = 1;
    }
    else if(pr[IR_ENABLE]==2){
        IRF_ENABLE = 1;
		IRF_Error= 1;
    }
    IR_ulTcount = pr[IR_TCOUNT_H]*10000+pr[IR_TCOUNT_L];
    //] //[Running Dir Count,Special,2018/08/17]
    //InitRCANET();  // [CAN Protocol for High Cap , Sampo,  2011/09/05]
    for (j=0; j<EPMAX; j++)
         pr_copy[j] = attr[j].def;

    InitSCI2();
    InitSCI3();	//SCIF3>SCI3, Bernie 2013/08/15
//	InitSCI0(); // [PGABD Output error, Lyabryan, 2015/08/13] 
    
	InitCAN(); 
    OverAccInit();     //[Over Acceleration protection function, Bernie, 2017/02/13]

    CUR_swIdseFdbPu = 0;  //[grace toqure proof bug,Sampo,2018/01/08]
    if ((pr[DEBUG_F1]&0x8000)==0x8000)  // Bit 15: VH mode
        VH_EN = 1;
    else
        VH_EN = 0;
    
    if (pr[PWR_CNT] != 65535) {
        pr[PWR_CNT]++;
        write_ep(0,PWR_CNT,pr[PWR_CNT]);
    }        
   
     //USB_SetBuff();	//Add by Sean, 02/22/2010  //USB FUNCTION BERNIE
#if SH7286 //Sean, 01/25/2010	    
    //COSadLPF.sw.hi = ADC2.ADDR8;
    //COSadLPF.sw.hi = AD0.ADDR2;
    COSadLPF.sw.hi =(SWORD)((ULONG)(AD0.ADDRC.WORD & 0x3FF)*4095)>>10;


    for(i=0;i<16;i++){    
	    //------ Calculate COS_data (SCI2_DIR=0) -------------------//    
		//COSadLPF.sl += (SLONG)( (SWORD)ADC2.ADDR8 - COSadLPF.sw.hi ) * 0x4000;	//AD8:SIN/COS
		COSadLPF.sl += (SLONG)( /*(SWORD)*/(((ULONG)(AD0.ADDRC.WORD & 0x3FF)*4095)>>10) - COSadLPF.sw.hi ) * 0x4000;	//AD8:SIN/COS
	}
#endif		
//---END 10/16/2007---------------	
	
    //HW_Test(); 
    
    TB1_ubErrCnt = 0;	// dino, 04/12/2007
	edt_ubErr	 = 1;	// Initial EnDat Error Flag=1, Add by DINO, 10/08/2008

    /* bit[7]   = b'0   : Transmit-data-empty interrupt disable     */
    /* bit[6]   = b'1   : Receive Interrupt Enable                  */
    /* bit[5]   = b'1   : Transmit Enable                           */
    /* bit[4]   = b'1   : Receive Enable                            */
    /* bit[3]   = b'0   : Multiprocess interrupt diable             */
    /* bit[2]   = b'1   : Transmit End interrupt Enable             */
    /* bit[1-0] = b'00  : Internal clock, SCK pin used for input pin*/


    //SCI2.SCSCR.BYTE |= 0x70;
    SCI2.SCR.BYTE |= 0x70;	//SCIF3 ==> SCI2, Bernie, 2013/08/15
   	/* Resset State Releasing, dino, 06/21/2007 */
    SCI3.SCR.BYTE |= 0x70;	//SCIF3 ==> SCI2, Bernie, 2013/08/15
   	//RCANET.MCR.WORD &= 0xfffe;                      /* Clear MCR0 */
    //while ( (RCANET.GSR.WORD&0x0008)!=0x0000 );     /* GSR3=0? */
    uwCAN_ChkTime = pr[CAN_ChkTime];  // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
//CAN FUNCTION BERNIE


    //set_imask(0);               /* Clear interrupt mask.                    */
    EINT();

    /**** Start timer counters on channels 0,1,2,3 and 4. *******************/
    //MTU2.TSTR.BYTE = 0xC7;      /* Start the timer counters.                */
    MTU.TSTRA.BYTE = 0xC7;      /* Start the timer counters.                */
    
    //CMT.CMSTR.WORD |= 0x0003;   /* Start Compare Match counter              */
    CMT.CMSTR0.WORD |= 0x0003;   /* Start Compare Match counter              */
    CMT.CMSTR1.BIT.STR2 = 1;	// 200us for USB routine, Sean, 2014/09/16

    //MTU2S.TSTR.BIT.CST4 = 1;	/* PGZ Capturer Start                       */
    MTU.TSTRB.BIT.CST6 = 1;     /* PGZ Capturer Start                       */
    /**** Start AD Conversion ***********************************************/
    //ADC0.ADCR.BIT.ADST = 1;        // A/D module 0 start bit, Continuely Mode
    //ADC1.ADCR.BIT.ADST = 1;        // A/D module 1 start bit, Continuely Mode
    //ADC2.ADCR.BIT.ADST = 1;        // A/D module 2 start bit, Continuely Mode    
    S12ADB0.ADCSR.BIT.ADST = 1;
    S12ADB1.ADCSR.BIT.ADST = 1;
    AD0.ADCSR.BIT.ADST = 1;
    // [ AVI->AUI ref voltage generation, Sean, 12/06/2010

	DA.DADR1 = 421;   
	DA.DADR0 = 421;             //[AUI2 setting for ED, Bernie, 08/25/2011]
	// ]
	

  //if ((POE2.ICSR1.WORD&0x7000)!=0)
	    //POE2.ICSR1.WORD &= 0xFFFF;		//FFFF:POE3 added, Sean, 01/25/2010
  //if ((POE2.ICSR2.WORD&0x7000)!=0)
	    //POE2.ICSR2.WORD &= 0x8FFF;
  if((POE.ICSR1.WORD&0x1000)!=0 ||((POE.ICSR2.WORD&0x1000)!=0)/*||(POE.ICSR3.WORD&0x1000)*/){
      POE.ICSR1.WORD &= 0x1103;
      POE.ICSR2.WORD &= 0x1103; 
     
  }
  if(((POE.ICSR3.WORD&0x1000)!=0) ||((POE.ICSR4.WORD&0x1000)!=0)||((POE.ICSR5.WORD&0x1000)!=0)){
      POE.ICSR3.WORD &= 0x1303;
      POE.ICSR4.WORD &= 0x1303;
      POE.ICSR5.WORD &= 0x1303;
  }
    //POE2.ICSR1.BIT.PIE1 = 1;
    //POE2.ICSR2.BIT.PIE2 = 1;
    POE.ICSR1.BIT.PIE1 = 1;
    POE.ICSR2.BIT.PIE2 = 1;
    POE.ICSR3.BIT.PIE3 = 1;
    POE.ICSR4.BIT.PIE4 = 1;
    POE.ICSR5.BIT.PIE5 = 1;
    
    //PUID1 = 1;
    //PUID1_BUF = 1;
    
    //DCBUSREC = 1;
    
    if (((YDSetBit&0x03)==0x03)||((YDSetBit&0x30)==0x30)){
        bx = mfo_chg2Y(_16BitTab[i],(pr[MO_INV]&_16BitTab[i]));
        if (bx==0){
            mfo_OFF(_16BitTab[i]);
        }  
        else{
            mfo_ON(_16BitTab[i]);
            mfo_now |= _16BitTab[i];
        }
    }
            
    //-------- Check for Mfi lockout --------
    if ((pr[WIRE2_3]&0x01)==0x01){      // Cheeck 2_3 Wire Line Lockout
        mfi_Pin();
        mfi_buf=mfi_now;
        mfi_old=mfi_buf;                // same condition, no change no input
        EXT_PWRONRUN = 0;
    }
    else{
        mfi_old=0xffff;                 // initialize all pin status
        EXT_PWRONRUN = 1;
    }

    APR_status.uw = 0;
//    APR_status1.ub = 0;
    //if ((pr[PG_TYPE] == ABZ_ONLY)||(pr[PG_TYPE] == ABZ_UVW)||(pr[PG_TYPE] == NOPG)){ // [PGABD Output error, Lyabryan, 2015/08/13] 
        
    //}

   if((pr[PG_TYPE] != ABZ_ONLY)&&(pr[PG_TYPE] != ABZ_UVW)&&(pr[PG_TYPE] != NOPG)){ // [PGABD Output error, Lyabryan, 2015/08/13] 
	  InitSCI0();
	  TB_2ms = 0;	        // Add by DINO, 10/09/2008
	  edt_ubStep = 0; // Add by DINO, 10/09/2008
        }
   else{

       PORT2.PMR.BIT.B3 = 0; //[0: Uses the pin as a general I/O pin.];[1: Uses the pin as an I/O port for peripheral functions.]
       PORT2.PMR.BIT.B2 = 0; //[0: Uses the pin as a general I/O pin.];[1: Uses the pin as an I/O port for peripheral functions.]
       PORT3.PMR.BIT.B0 = 0; //[0: Uses the pin as a general I/O pin.];[1: Uses the pin as an I/O port for peripheral functions.]
       PORT2.PDR.BIT.B3 = 1; //[0: Input (Functions as an input pin.)];[1: Output (Functions as an output pin.)]
       PORT2.PDR.BIT.B2 = 1; //[0: Input (Functions as an input pin.)];[1: Output (Functions as an output pin.)]
       PORT3.PDR.BIT.B0 = 1; //[0: Input (Functions as an input pin.)];[1: Output (Functions as an output pin.)]
       PORT2.PODR.BIT.B2 = 0; // Initial PORD Output is zero.
       PORT2.PODR.BIT.B3 = 0; // Initial PORD Output is zero.
       PORT3.PODR.BIT.B0 = 0; // Initial PORD Output is zero.
       
    }
   
  /*=========== PG Card type detact  ===========   //[Modify PG Type Define, Bernie, 12/05/2011]
                                  AN5
                          PGHSD  3.133V
                           ---------- 2.5V
                          PGABD 1.983V
                           ---------- 1.5V
                          PGAB  1.035V
                           ---------- 0.5V
                          NO PG   0.000V
     ===============================*/  
    uwHi  = 512; // 2.5/5.0V * 1024 = 512
    uwMid = 307; // 1.5/5.0V * 1024 = 307
    uwLow = 102;  // 0.5/5.0V * 1024 = 102

    //if (AN5 > uwHi)
    if (AN00 > uwHi)
        ubPGCard = PGHSD;
    
    //else if (AN5 > uwMid)
    else if (AN00 > uwMid)
        ubPGCard = PGABD;

    //else if (AN5 > uwLow)
    else if (AN00 > uwLow)
        ubPGCard = PGAB;

    else
        ubPGCard = NOPGCARD;

    SpDt_ubPGCard = ubPGCard;
    
    // modbus framework, Sean, 20141225
    modbus_decode_init();
    modbus_device_init();
    modbus_usr_init();
	USB_vdIniTx(1); //[force to stop scope mode,Aevin,2016/08/03]

    ErrorResetInit(); //[Add auto restart after fault, Bernie, 06/06/12]

    if(pr[MBF_ERR_REC]!=0){              //[MBF can be recorded after power down, Bernie, 2016/02/19]
        Error = pr[MBF_ERR_REC];
    }

    CAN_UWTABST0_COUNT = pr[TABST0_COUNT];
    CAN_UWTABST0_STATUS = pr[TABST0_STATUS];
    CAN_UWTABST1_COUNT = pr[TABST1_COUNT];
    CAN_UWTABST1_STATUS = pr[TABST1_STATUS];
    CAN_UWEST_COUNT = pr[EST_COUNT];
    CAN_UWEST_STATUS = pr[EST_STATUS];

    FIRST_FLAG = 1;     //[PG quality function, Bernie, 2017/06/20]

    while(1)
    {    
     //===================== Encoder quality ====================//
      if(TB1_uwPGQuality_1sec>=1000 && FIRST_FLAG==0){                                           //[PG quality function, Bernie, 2017/06/20]
          TB1_swPGQualityDsp = 1000-(SWORD)((SPR_ulPGQualityCnt*1000)/SpDt_ulPG1NpulseNoMx);
          if((TB1_swPGQualityDsp<=5)){
          //if(FIRST_FLAG==1){
              TB1_swPGQualityDsp = 0;   //dot1
          }
          //uwtest24++;
          TB1_uwPGQuality_1sec = 0;
      }

    
      /*================= Service Times function ===================*/
      if(((RUN_SENSOR0 == 1) && (RUN_SENSOR1 == 0))&&(pr[SERVICE_ENABLE]==1)&&(RUNNING==RUN)){   //[Service time function, Bernie, 2017/03/14]
          if(pr[SERVICE_COUNT]!=0){
              pr[SERVICE_COUNT]--;
              write_ep(0,SERVICE_COUNT ,pr[SERVICE_COUNT]);
              RUN_SENSOR1 = 1;
          }
          else{
              SERVICE_KEYRESET = 1;
              Error = SERVICE_ERR;
              write_ep(0,SERVICE_COUNT ,pr[SERVICE_COUNT]);
          }
      }
      //[ //[Running Dir Count,Special,2018/08/17]
	  /*================= Running Dir Count function ===================*/
	  if((CMDDIR_OLD != CMDDIR)&&(RUNNING == RUN)){
	  	
		  if(pr[IR_COUNT_L] == 9999){
			  pr[IR_COUNT_L]=0;
			  pr[IR_COUNT_H]=pr[IR_COUNT_H]+1;
              write_ep(0,IR_COUNT_H ,pr[IR_COUNT_H]);
		  }
		  else{
			  pr[IR_COUNT_L]=pr[IR_COUNT_L]+1;
              write_ep(0,IR_COUNT_L ,pr[IR_COUNT_L]);
		  }
          if(IRF_ENABLE){    
          	  if(pr[IR_TCOUNT_L] == 9999){
          		  pr[IR_TCOUNT_L]=0;
          		  pr[IR_TCOUNT_H]=pr[IR_TCOUNT_H]+1;
                  write_ep(0,IR_TCOUNT_H ,pr[IR_TCOUNT_H]);
          	  }
          	  else{
          		  pr[IR_TCOUNT_L]=pr[IR_TCOUNT_L]+1;
                  write_ep(0,IR_TCOUNT_L ,pr[IR_TCOUNT_L]);
          	  }
			  IR_ulTcount = pr[IR_TCOUNT_H]*10000+pr[IR_TCOUNT_L];
          }
          
          CMDDIR_OLD=CMDDIR;
	  }
	  
      if(pr[IR_COUNT_H] == 60000){
          WGOFF;
          Error = SERVICE_ERR;
          WGOFF;
          TB1_uwMCStopCnt = pr[MCDELAY_STOP];
          LIFT_ENABLE = 0;
          CMDFREE = 1;
      }
      
      if(IR_ulTcount==209999){
          IRF_Error = 1;
      }
        

	  if(IR_ulTcount>(pr[IR_LIFE]*10)){
   	  	  if(IRF_Warning == 1){
   			  WarnDisplaySave();
   			  WarnCode = SERVICE_WARN;
   		  }
   		  else if(IRF_Error == 1 ){
              WGOFF;
   			  Error = SERVICE_ERR;
   			  WGOFF;
   			  TB1_uwMCStopCnt = pr[MCDELAY_STOP];
              LIFT_ENABLE = 0;
   			  CMDFREE = 1;
              IR_KEYRESET = 1;
   		  }
	  }
      //] //[Running Dir Count,Special,2018/08/17]				
	  
	  
  //=====================EPS MO Output======================// //[EPS MO Output,Lyabryan,2018/06/19]
        if((MI_EPS_SWITCH == 1)||((Error==LvA_ERR)||(Error==Lvd_ERR)||(Error==Lvn_ERR)||(Error==LvS_ERR))){ 
            if(MO_EPS_SWITCH == 1){
                if(EPS == 1){
                    EPS_MO_JUDGEMENT = 1;
                }
            }
        }
        if(EPS == 0 && EPS_MO_JUDGEMENT==1){ 
            //EPS_MO_JUDGEMENT = 0;
            if(uwEPS_Off_CNT>=pr[EPS_MO_OFF]*100){
                MO_EPS_SWITCH = 0;
                uwEPS_Delay_CNT = 0;
                uwEPS_Off_CNT = 0;
            }
        }
  //========================================================// //[EPS MO Output,Lyabryan,2018/06/19]
      if(DLC_uwEeprom == 1){
    		
    		WelTun_eeprom();
    		DLC_uwEeprom = 0;
      }
    
    /*================= PGABD ===================*/  //[PGABD function, Bernie, 10/13/2011]
        if ((pr[DEBUG_F1]&0x0008) != 0x0008){
            if(pr[PG_TYPE] == ABZ_ONLY || pr[PG_TYPE] == ABZ_UVW){
                //ubPGData = (pr[PG_MODE] & 0x001F) + ((pr[PG_MODE] & 0x100) >> 3) + ((pr[PG_MODE] & 0x200) >> 3) + 0x80;
                ubPGData = pr[FREQ_DIV]+
                          ((pr[PG_DIV_MODE]&0x0001)<<5)+
                          ((pr[PG_DIV_MODE]&0x0002)<<5)+
                           0x80;                                  //[Modify PG Type Define, Bernie, 12/05/2011]
                ubPGData = ~ubPGData;           //inverse the signal 
                for (i = 0; i<8; i++) {      // send data to 74595
            
                    SCI0_TxD = 0 ;          // P9.3(B4) 74595_srclk
            
                    if ((ubPGData & 0x80) != 0)
                        SCI0_RxD = 0;          // P9.2(B3) 74595_ser(data_in)
                    else
                        SCI0_RxD = 1;
        
                    ubPGData = ubPGData << 1;    // left shift
                    SCI0_TxD = 1 ;          // B4(P9.3)
        
                }    
                SCI0_DIR = !0;             // B8(P9.5)=0 -> load keypad data //
                SCI0_TxD = 0;
                SCI0_DIR = !1;             // P9.5 Low to High, latch 74595 data //
            }
        }
    /*================= CAN Protocol for DLC ===================*/	
//#if 1
    	//if((pr[DEBUG_F1]&0x0008) != 0x0008){
            
        if(CAN_RX3_OK == 1 || CAN_RX5_OK == 1 ||CAN_RX7_OK == 1){  // [CAN Protocol for High Cap , Sampo,  2011/09/05]
            CAN_SDO_RX_Decode();
        }

        //[Gfc DLC modify,Henry,2018/05/23]
        if((pr[SOFC]==4)||(pr[SOFC]==5)){
        	// [CAN Protocol for High Cap, Bernie, 09/22/2011] 
            if((uwCAN_ChkTime!=0)&&(uwPDO_CNT >= uwCAN_ChkTime)){    
    					//DLC function, Henry, 2016/07/20 [
                Keypad_Page = WarnPAGE;	   
                WarnCode = CANOFF_WARN;
    					
    					//[Those codes fixed keypad can't diaplay warn code, Bernie, 2016/01/29]
    				  //warndisp(CANOFF_WARN);
    					//]
    					
    					//Error = CAN_ERR;
            //uwPDO_CNT = 0;             //[CAN ERR can't clear after pr[CAN_HC]=0, Bernie, 2013/04/11]
            }
            else{
          	//DLC function, Henry, 2016/07/20
          	    if(WarnCode == CANOFF_WARN){
              		InitCAN();
              		WarnCode = 0;
              		uwPDO_CNT = 0;
                }
            }
          
          // PDO CANOFF_WARN reset init, v0.05
            if(CAN1.STR.BIT.EST == 1){
                CAN_UWEST_COUNT++;
                //CAN_UWEST_STATUS = CAN1.STR.BIT.EST ;
                CAN_UWEST_STATUS &=0X0000;
                CAN_UWEST_STATUS = CAN1.EIFR.BYTE;
                pr[EST_COUNT] = CAN_UWEST_COUNT;
                pr[EST_STATUS] = CAN_UWEST_STATUS;
                InitCAN();
            }
        
            if(CAN1.STR.BIT.TABST == 1){
                if(CAN1.MCTL[0].BIT.TX.TRMABT == 1){
                    CAN_UWTABST0_COUNT++;
                    CAN_UWTABST0_STATUS = CAN1.ECSR.BYTE;
                    CAN1.MCTL[0].BIT.TX.TRMABT = 0;
                    pr[TABST0_COUNT] = CAN_UWTABST0_COUNT;
                    pr[TABST0_STATUS] = CAN_UWTABST0_STATUS;
                }
                if(CAN1.MCTL[2].BIT.TX.TRMABT == 1){
                    CAN_UWTABST1_COUNT++;
                    CAN_UWTABST1_STATUS = CAN1.ECSR.BYTE;
                    CAN1.MCTL[2].BIT.TX.TRMABT = 0;
                    pr[TABST1_COUNT] = CAN_UWTABST1_COUNT;
                    pr[TABST1_STATUS] = CAN_UWTABST1_STATUS;
                }
            }
        }
        //}
//#endif
    /*================= PG Card for Sinusoidal type ===================*/    
        
    	if ( pr[PG_TYPE]==SIN_SIN )
        	Sinusoidal_Position();
    
/*================= Keypad Communication Control ===================*/			

        CHK_PUID2();

        if (ASC_RTU2==1){          //RTU mode
            RTU_RxOKChk_2();                
        }

        if (RX_OK2==1){
                //if ((pr[DEBUG_F1]&0x0008) == 0x0008){      //[ICT Test, Bernie, 08/11/2011]       
                    //for(i=0; i<=Rx2CNT; i++){
                        //RxBuf_2[i] = 0xff - RxBuf_2[i];    
                    //}
                    //SCIDIR2Flag = 0;	// Transmit    
                    //Init_TxData_2(Rx2CNT-2);
                //}
#if BOOTLOADER_ENABLE	// Bootloader enable, Sean, 20141022
            if(RxBuf_2[0] == 0x3A && 
               RxBuf_2[7] == 0x55 && 
               RxBuf_2[8] == 0x55 &&
               RxBuf_2[9] == 0x55 && 
               RxBuf_2[10] == 0x55 && 
               RxBuf_2[15] == 0x0D && 
               RxBuf_2[16] == 0x0A){
            		
            	// Transmit DIR flag	
                SCIDIR2Flag = 0;      
                Init_TxData_2(0x3A);				
    			
    			//jump to Bootloader initial: use default BLD address(switch.h)
                SWITCH_Initial_Val();
                switchFlag = 1;
                switch_TxDon = 1;
                LV_REC();
            }
            else{
				if (Rx2CNT >= 7){
    		        #if 1
					RxDecoder_2();	//[force to stop scope mode,Aevin,2016/08/03]
					#else
					//----use modbus structure---4/26/2016
					//keypad is work ,soft is work too
					RxDataCheck_2();
    				if (ADDR_MATCH2==1){
						Rx2CNT	= modbus_decode(&RxBuf_2[1],Rx2CNT);							
						memcpy(TxBuf_2,RxBuf_2,Rx2CNT+1); //ID+DATA							
						Init_TxData_2(Rx2CNT);
    				}
					#endif			
    	        }
    	        else{
    		         InitSCI2();
    	        }
            }
#else
    	        if (Rx2CNT >= 7){

#if 1
					RxDecoder_2();	//[force to stop scope mode,Aevin,2016/08/03]
#else
					//----use modbus structure---4/26/2016
					//keypad is work ,soft is work too
					RxDataCheck_2();
    				if (ADDR_MATCH2==1){
						Rx2CNT	= modbus_decode(&RxBuf_2[1],Rx2CNT);							
						memcpy(TxBuf_2,RxBuf_2,Rx2CNT+1); //ID+DATA							
						Init_TxData_2(Rx2CNT);
    				}
#endif				
    	        }
    	        else{
    		         InitSCI2();
    	        }			
#endif
            SCI2_TodCNT = 0;
            RX_OK2 = 0;			
        }

        TxD_Data_2();

        DINT();
        SCI2_DIR = SCIDIR2Flag;        
        EINT();
	    
#if BOOTLOADER_ENABLE	// Bootloader enable, Sean, 20141022
    	if(switch_TxDonWait>1000){	//wait 1sec	// bootloader over usb for online mode, Sean, 20141030	
    		switch_TxDon = 0;
    		switchFlag = 0;
    		switch_TxDonWait = 0;
    		//SWITCH_GOTO_BLD_Section();	
    		SYSTEM.SWRR.WORD = 0xA501;	// software reset	// test, Sean, 20141030
    	}
#endif		
	    

     /*================= JSG3 Communication Control ===================*/			

        if (ASC_RTU3==1){          //RTU mode
            RTU_RxOKChk_3();
        }

        if (RX_OK3==1){	
            if ((pr[DEBUG_F1]&0x0008) == 0x0008){      //[ICT Test, Bernie, 08/11/2011]       
                for(i=0; i<=Rx3CNT; i++){
                    RxBuf_3[i] = 0xff - RxBuf_3[i];    
                }
                SCIDIR3Flag = 0;	// Transmit    
                Init_TxData_3(Rx3CNT-2);
            }
    		
            else{ 
         	    if (Rx3CNT >= 7){
    	            RxDecoder_3();
                }
                else{
                    InitSCI3();
                }
            }
            SCI3_TodCNT = 0;
            RX_OK3 = 0;			
        }

        if ((pr[DEBUG_F1]&0x0001) == 0x0001){      //[ICT Test, Bernie, 08/11/2011]  
             ICT4SCI3();
        }

        TxD_Data_3();

        DINT();
        SCI3_DIR = SCIDIR3Flag;        
        EINT();


       if (vfd_btPGHSD1Set==1){	// fix pghsd1 code, Sean, 06/01/2012
    		/*testing for  EMED-PGHSD*/
    		switch(pr[PG_TYPE]){
    			case SIN_ENDAT:	hsd_stIedSendIn.ubEndTyp = HSD_PGT_ENDAT;	break;
    			case SIN_SIN:	hsd_stIedSendIn.ubEndTyp = HSD_PGT_SIN;		break;
    			case SIN_HIPER:	hsd_stIedSendIn.ubEndTyp = HSD_PGT_HIPER;	break;
    			default:		hsd_stIedSendIn.ubEndTyp = HSD_PGT_SIN;		break;
    		}
    		//hsd_stIedSendIn.ubDivFre = (UBYTE)pr[PG_MODE];
            hsd_stIedSendIn.ubDivFre = (UBYTE)pr[FREQ_DIV];        //[PG Card Frequency Division Output for PGHSD-1, Bernie, 2013/03/14]
    		//hsd_stIedSendIn.ubErrSign = 0x03;
    		hsd_ProssTxRxTb1(&hsd_stIedSendIn,&hsd_stPgReplyOut);
    		hsd_uwAbsAngle = hsd_stPgReplyOut.uwAngle;
    	}
    	else{     //[delete PGHSD, Lyabryan, 2015/12/17]
    		SCI0_PGHSD_Comm();
    	}

	

//---Add BY Dino 06/21/2007---
    	//if(pr[CAN_CTRL]==0 && pr[CAN_HC]==0){    //[CAN Control, Sampo, 09/15/2010] // [CAN Protocol for High Cap , Sampo,  2011/09/05]
        	//if ( swTest1==7788 ){								/* Mailbox1 start transmission */
    	    	//swTest1 = 5566;
    	    	//for ( i=0; i<8; i++ ){							/* Write Mailbox1 */
    		    	//RCANET.MB[1].MSG_DATA[i] = RxBuf_RCAN[i];
    	    	//}

    	    	/* Transmission Setting */
    	    	//RCANET.TXPR10.LONG = 0x00000002;					/* Set MB1 to transmission wait status */
        	//}
    	//}          //CAN FUNCTION BERNIE
//---END 06/21/2007---------------	

        
        if(COPYEN){

            if((COPYFAIL)||(COM2Err!=0)||(Com_WatchDog2>=50))
            {    
                // 50*40ms = 2sec  //[modify watchdog to SCI2, Bernie, 2017/08/10]
                InitValue();
                copy_status.ub = 0;
                WarnDisplaySave();
                WarnCode = SE1_WARN;        // Copy Fail 1, SE1
                KC23xx[0x05] &= 0xefff;     // clear bit12 Enable to Copy
            }
            else if(COPYOK){

                for(ax=GROUP0; ax<GROUP13; ax++){
                	uwTemp = GetParAttr(ax);
                    if( (uwTemp&(HIDE|S2EEP|READ))==0 ){	// Modify by DINO, 10/28/2008

                        bx = pr_copy[ax];
                        write_pr(ax,bx);
                        if(KEYEND == ERR){
                            COPYFAIL = 1;
                            break;
                        }
                    }
                }
                

                if(COPYFAIL){
                    InitValue();    			// clr COPYOK(b7), COPYFAIL(b6), COPYOK(b5)
    				copy_status.ub = 0;
                    WarnDisplaySave();
                    WarnCode = SE2_WARN;        // Copy Fail 1, SE2
                    KC23xx[0x05] &= 0xefff;     // clear bit12 Enable to Copy                    
                }
                else {  // COPYFAIL=0
                    InitValue();    			// clr COPYOK(b7), COPYFAIL(b6), COPYOK(b5)
                    C21xx[0x20] |= 0x1000;	    // [For VFD-Cx reload chinese parameter information, Bernie, 10/06/2011]
    				copy_status.ub = 0;
                }                
            }
        }
        else{  // Non copy mode


//            if ((pr[CTODT2]!=0)&&(pr[C_FAULT2]!=3)) {            // Enable Time out Detection //SCOTTY delete 09/03/2007 
            if((pr[CTODT2]!=0)&&(pr[C_FAULT2]<2)){		//SCOTTY ADD 09/03/2007
                if(SCI2_TodCNT > pr[CTODT2]){ 
                    if (PUON2LINE)
                        COM2Err = CP_CE10;
                    else
                        COM2Err = PC_CE10;    
                    SCI2_ComFault();
                }
                else{
                    if((Error==0)&&(WarnCode<=CP_CE10 && WarnCode>=PC_CE01)){
                        Keypad_Page = Keypad_PageTmp;
                        WarnCode = 0;
                    }    
                }
            }

	        if(Com_WatchDog2>50){   // WatchDog Timer > 5.0 sec
	            InitSCI2();
            }   

            if((pr[CTODT3]!=0)&&(pr[C_FAULT3]<2)){		//SCOTTY ADD 09/03/2007
                if (SCI3_TodCNT > pr[CTODT3]){ 
                    if (PUON3LINE)
                        COM3Err = CP_CE10;
                    else
                        COM3Err = PC_CE10;    
                    SCI3_ComFault();
                }
                else{
                    if((Error==0)&&(WarnCode<=CP_CE10 && WarnCode>=PC_CE01)){
                        Keypad_Page = Keypad_PageTmp;
                        WarnCode = 0;
                    }    
                }
            }

	        if(Com_WatchDog3>50){   // WatchDog Timer > 5.0 sec
	            InitSCI3();
            }                         
        }
        /*------ End of Remote Control function ------*/	    


		//------ Reflash VFD status -----------------------------//
		VFDStatus();	    

		//------ Multi-Input terminal process -------------------//
		mfi_process();

		//pr[FEPS] = COF_uwFepsLimit; //[#13769 Modify EPS speed, James, 07/01/2020]	// 06-44 Display EPS Limit Speed, Add by DINO, 08/30/2010 James
		//uwEPS_SpdLimt = COF_uwFepsLimit;        //[User can change speed when used EPS function, Bernie, 2013/04/16]

		//------ Multi-Output terminal process ------------------//
		mfo_process();
		
		//------ LED KEYPAD Program, DINO, 03/09/2010 -----------//
		if (COPYEN == 0){  // KEYPAD is invalid during Save, DINO, 03/16/2010
			key_prog();
			// [ Initial Page, DINO, 06/01/2010
			KEY_ubPrno[grno] = prno;
			// ]
		}
		
        if((pr[IODEN]&0x0001)==0x0001){ // [IODLC, Lyabryan, 2016/11/11]
            IODLC_Distance_calculate(); // [IODLC, Lyabryan, 2016/11/11]
        }
        ////[EPS, Sampo, 03/27/2011]
        if(EPS && pr[CTRLM]<=SVC && RUNNING==STOP && GEN_START && EPS_STOP){
            EPS_STOP = 0;
            if(uwEPScnt>1){
                if(PR_ubEpsOptMod==1){           //[Modify EPS function, Bernie, 2012/11/27 ]         
                    if (uwFWDPFangle > uwREVPFangle){
               	        CMDDIR = FORWARD;
                        GEN_OK3 = 1;               //be used to control CMDDIR in EPS function
                        GEN_OK2_DIR = FORWARD;  
     	            }
    			    else {
        		        CMDDIR = REVERSE;
                        GEN_OK3 = 1;                //be used to control CMDDIR in EPS function
                        GEN_OK2_DIR = REVERSE;  
    			    }		        
                    if(pr[CHG_DIR]==1){             //GENDIR related to para 00-11, Henry, 2017/05/24
					    CMDDIR ^= 1; //GENDIR related to para 00-11, James, 2019/12/20
                    }
                }
                else if(PR_ubEpsOptMod==4){ //[EPS autodetect dir,Lyabryan,2018/07/02]
                    CMDDIR = pr[EPS_DIR];
                }
                GEN_OK = 1;
                
		        //GENDIR = CMDDIR ^ 1;
		        if(PR_ubEpsOptMod!=4)      //[EPS autodetect dir,Lyabryan,2018/07/02]
                    GENDIR = GEN_OK2_DIR ^ 1;            //[Modify EPS function, Bernie, 2012/11/27 ]     
                else
    		        GENDIR = pr[EPS_DIR];
                
		        if(pr[CHG_DIR]==1){             //GENDIR related to para 00-11, Henry, 2017/05/24
                    GENDIR ^= 1;
                }
            }

            LIFT_RUNCMD = 1;
            run();
        
            
            if(uwEPScnt>1){  
                GEN_START = 0;
                uwEPScnt = 0;
            }

            
        }
		//------ Multi-AI function ------------------------------//
		swTemp1 = AUI1Calculate();
		swTemp2 = ACICalculate();
		swTemp3 = AUI2Calculate(); 

		if (pr[AISUM]==0){
   		    mfai_ptr = mfai_tbl[pr[AUI1_SL]];
   		    AVIslFunVar = (*mfai_ptr)(1,swTemp1);	    	
	    	
	    	mfai_ptr = mfai_tbl[pr[ACI_SL]];
   	    	ACIslFunVar = (*mfai_ptr)(2,swTemp2);
   			
		    mfai_ptr = mfai_tbl[pr[AUI2_SL]];
   		    AUIslFunVar = (*mfai_ptr)(3,swTemp3);
   		}
   		else{   			
		    if (pr[AUI1_SL]==pr[ACI_SL]){
		    	if (pr[ACI_SL]==pr[AUI2_SL]){
		            // AVI = ACI = AUI
		    	    swTemp1 = swTemp1 + swTemp2 + swTemp3;
		    	    mfai_ptr = mfai_tbl[pr[AUI1_SL]];
		    	    AVIslFunVar = (*mfai_ptr)(4,swTemp1);
		    	    ACIslFunVar = AVIslFunVar;
		    	    AUIslFunVar = AVIslFunVar;
		    	}
		    	else{
		    	    // AVI = ACI != AUI
		    	    swTemp1 = swTemp1 + swTemp2;
		    	    mfai_ptr = mfai_tbl[pr[AUI1_SL]];
		    	    AVIslFunVar = (*mfai_ptr)(5,swTemp1);
		    	    ACIslFunVar = AVIslFunVar;
		    	    mfai_ptr = mfai_tbl[pr[AUI2_SL]];
			    	AUIslFunVar = (*mfai_ptr)(3,swTemp3);
				}
		    }
		    else if (pr[AUI1_SL]==pr[AUI2_SL]){
				if (pr[AUI2_SL]==pr[ACI_SL]){
			    // AVI = ACI = AUI
		    	    swTemp1 = swTemp1 + swTemp2 + swTemp3;
		    	    mfai_ptr = mfai_tbl[pr[AUI1_SL]];
		    	    AVIslFunVar = (*mfai_ptr)(4,swTemp1);
		    	    ACIslFunVar = AVIslFunVar;
		    	    AUIslFunVar = AVIslFunVar;
				}
				else{
			    // AVI = AUI = !ACI
		    	    swTemp1 = swTemp1 + swTemp3;
		    	    mfai_ptr = mfai_tbl[pr[AUI1_SL]];
		    	    AVIslFunVar = (*mfai_ptr)(6,swTemp1);
		    	    AUIslFunVar = AVIslFunVar;
			    // ACI
			    	mfai_ptr = mfai_tbl[pr[ACI_SL]];
			    	ACIslFunVar = (*mfai_ptr)(2,swTemp2);				
				}
		    }
		    else if (pr[AUI2_SL]==pr[ACI_SL]){
				if (pr[ACI_SL]==pr[AUI1_SL]){
			    // AVI = ACI = AUI
		    	    swTemp1 = swTemp1 + swTemp2 + swTemp3;
		    	    mfai_ptr = mfai_tbl[pr[AUI1_SL]];
		    	    AVIslFunVar = (*mfai_ptr)(4,swTemp1);
		    	    ACIslFunVar = AVIslFunVar;
		    	    AUIslFunVar = AVIslFunVar;
				}
				else{
			    	// ACI = AUI != AVI
			    	swTemp2 = swTemp2 + swTemp3;
			    	mfai_ptr = mfai_tbl[pr[AUI2_SL]];
			    	AUIslFunVar = (*mfai_ptr)(7,swTemp2);
			    	ACIslFunVar = AUIslFunVar;
			    	// AVI
			    	mfai_ptr = mfai_tbl[pr[AUI1_SL]];
			    	AVIslFunVar = (*mfai_ptr)(1,swTemp1);
    	
				}
		    }			
		}
        //-------------AUI Slope and offset calculate------------// //[ //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
        if((AUI_TUNE_FINISH==1)&&(pr[LOCELTUN]==2)){
            aa = (AUI_swem_T*AUI_swfl_V)-(AUI_swfl_T*AUI_swem_V);//em_T*fl_V-fl_T*em_V
            swTemp2 = (AUI_swem_T-AUI_swfl_T);//em_T - fl_T
            if(swTemp2!=0)
                AUI_swoffset = aa/swTemp2;
            else
                AUI_swoffset = 0;
            
            if(AUI_swoffset>1000)
                AUI_swoffset = 1000;
            else if(AUI_swoffset<-1000)
                AUI_swoffset = -1000;
            
            swTemp1 = AUI_swem_T;//em_T
            swTemp2 = AUI_swem_V-AUI_swoffset; //em_V - AUI_swoffset
            if(swTemp2!=0){
                if(pr[CTRLM]==FOCPM)
                    AUI_swgain = S16xS16divS16(swTemp1,100,swTemp2);
                else if(pr[CTRLM]==FOCPG){
                    AUI_swgain = S16xS16divS16(swTemp1,1000,swTemp2);
                    //AUI_swgain= AUI_swgain*100/ pr[TQRMAX];
                }
            }
            else
                AUI_swgain = 0;
            
            if(AUI_swgain>5000)
                AUI_swgain = 5000;
            else if(AUI_swgain<-5000)
                AUI_swgain = -5000;
            
            updatepr(AUI1BIAS,AUI_swoffset);
            updatepr(AUI1GA,AUI_swgain);
            
            P03_15(LOCELTUN,0);
        } //] //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]

		//------ Multi-Input source of frequency ----------------//
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        Sibocom_mi_speed();
#else
        mi_speed();
#endif
		//------ TQC mode Speed limit //6a17j **
		//for Torque control	  	
		if (TqSpdMode == 1){
		        swSpdP_tmp = U16xU16divU16(TqC_uwPSpdLimRe,0x7FFF,COF_uwFbRe);        
		        swSpdN_tmp = 0 - U16xU16divU16(TqC_uwNSpdLimRe,0x7FFF,COF_uwFbRe);
		        
		    if (pr[SPLIMIT_SL]==1){
		        if (CMDDIR==FORWARD){
		            swSpdP_tmp = U16xU16divU16(fcmd.uw.hi,0x7FFF,COF_uwFbRe);
		        }
		        else{
		            swSpdN_tmp = 0 - U16xU16divU16(fcmd.uw.hi,0x7FFF,COF_uwFbRe);
		        }  	
		    }
		    TqC_swPSpdLimPu = swSpdP_tmp;
		    TqC_swNSpdLimPu = swSpdN_tmp;
			  	//6a17j&&
		}

		//------ Calculate pv value -----------------------------//
		PID_Fbk_Process();
	  	
		//------ Fan Control ------------------------------------//
		FanControl();

		//------Torque Load calculation-------//
		Torque_Load();  //6911j

        if(!RUNDCI)
        {
	        TorqDetect_Function();  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
        }
		
		//------ PTC Input Detect -------------------------------//
		if (pr[AUI1_SL]==6){
			PTCInValue = AVIslFunVar;
		}
		else if (pr[ACI_SL]==6){
			PTCInValue = ACIslFunVar;            
		}
		else if (pr[AUI2_SL]==6){
			PTCInValue = AUIslFunVar;
		}
        
		if (PTCInLPF.sw.hi > pr[PTC_LEVEL]){
			switch (pr[PTC_TREAM]){
				default:
    	            case 0:
    	                Keypad_PageTmp = Keypad_Page;
					    Keypad_Page = WarnPAGE;	        
    	   				WarnCode = oH3_WARN;
    	            break;
    	            case 1:
    	                stop();
    	                Error = oH3_ERR;
    	                WARNSTOPREC = 1;        	//09/05/2007                
    	            break;
    	            case 2:
//  	                  CMDRUN = STOP;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
    	          		CMDFREE = 1;
    	          		Error = oH3_ERR;
    	            break;
			}   
		}
		else{
			if (WarnCode == oH3_WARN){
				WarnCode = 0;
				Keypad_Page = Keypad_PageTmp;
			}   
		}
		
		if ((LOOPFlag==0)&&(RUNNING==RUN)){		
			if (APR_ZChkFlag==0){
				if (APR_ubZChkCnt==8){
					ulTemp = 0;
					for (i=0;i<=7;i++){
						ulTemp += (ULONG)APR_uwZarray[i];
					}

					uwTemp = abs(APR_uwZarray[1] - (ulTemp>>3));
		       		if (uwTemp>pr[PGATTAIN])
		       			APR_ubZChkCnt = 0;

		       		uwTemp = abs(APR_uwZarray[3] - (ulTemp>>3));
		       		if (uwTemp>pr[PGATTAIN])
		       			APR_ubZChkCnt = 0;

		       		uwTemp = abs(APR_uwZarray[5] - (ulTemp>>3));
		       		if (uwTemp>pr[PGATTAIN])
		       			APR_ubZChkCnt = 0;

		       		uwTemp = abs(APR_uwZarray[7] - (ulTemp>>3));
		       		if (uwTemp>pr[PGATTAIN])
		       			APR_ubZChkCnt = 0;

		       		if (APR_ubZChkCnt==8){
		       			APR_uwZPosition = (ulTemp>>3);
		       			APR_ZChkFlag = 1;
		       			MTU0.TIER.BYTE &= 0xFD;
		       		}
				}        		
			}
			if (APRFirstGo==0){
		        //---------------------------------------------------------//
		        //Power On, APR First Go Flag = 0, First Run to APR,       //
				//must to search position of Z, after double check Z value //
				//make APR First Go Flag = 1                               //
				//---------------------------------------------------------//
		        if (APR_ZChkFlag==1){
		        	APRFirstGo = 1;
		        }
			}
		}

		if (APR_uwThetaNoMx>=APR_uwZPosition)
			APR_uwPGPosition = APR_uwThetaNoMx - APR_uwZPosition;
		else
			APR_uwPGPosition = SpDt_ulPG1NpulseNoMx + APR_uwThetaNoMx - APR_uwZPosition;

// [ Move from TimeBase_1ms(), DINO, 03/09/2009
		// SpDt_slSpdFdbPu: Q31
        if (pr[PGINPUT]!=0){
	        if (SpDt_slSpdFdbPu >=0){
	            uwTemp = ((SLONG)COF_uwFbRe * (SpDt_slSpdFdbPu>>15))>>16;
	            slMotorHz = (SLONG)uwTemp;
	            swMotorRpm = (SWORD)U16xU16divU16(uwTemp, 120, (COF_uwPole*100));
	        }
	        else{
	            uwTemp = ((ULONG)COF_uwFbRe * (-SpDt_slSpdFdbPu>>15))>>16;
	            slMotorHz = (SLONG)(-uwTemp);
	            swMotorRpm = (SWORD)(-U16xU16divU16(uwTemp, 120, (COF_uwPole*100)));
	        }
	        SpDt_uwFfbk = uwTemp;
		}
		else{
			slMotorHz = 0;
			swMotorRpm = 0;
			SpDt_uwFfbk = 0;
		}

      	// [ Velocity Unit Change, Add by DINO, 05/25/2009
      	uwTemp = (UWORD)(abs(slMotorHz));
		if (pr[UNITSEL] == 1){		// Hz->m/s
			uwTemp = Hz2Metric(uwTemp);
		}
		else if(pr[UNITSEL] == 2){	// Hz->ft/s
			uwTemp = Hz2Ft(uwTemp);
		}
        //else if(pr[UNITSEL] == 3){	// Hz->ft/s
			//uwTemp = Hz2Ft(uwTemp);
		//}
		uwAbsMotorHz = uwTemp;
		// ]


		swTemp1 = (SWORD)(U16xU16divU16(TB1_CmdRpm.uw.hi, 120, (COF_uwPole*100)));
	   	if(WGDIR==FORWARD){
	   		swCmdRpm = swTemp1;
	   	}
	   	else{
	   		swCmdRpm = -swTemp1;
		}

        swTqRefPu = S16xS16divS16(TorqueOut, 1000, COF_uwTqrateRe);
        swTqFbkPu = (CUR_swIqseFdbPu * COF_uwKt) >> 13; //Q10 = Q(15+8-13)

        if(IrmsRe >= uwIsDtL)
            ABV_CURT = 1;
        else
            ABV_CURT = 0;
            
        if(fout.uw.hi >= pr[SP_AREA])
        {
            ABV_SPDA = 1;
        }
        else
		{
		    ABV_SPDA = 0;
        }

        // #16698 PG speed Above Speed Area for NRG//James, 2021/08/09
        if((pr[SP_AREA]==0) || (abs(slMotorHz)<pr[SP_AREA]))
        {
		    ABV_PGSPDA = 0;
        }
        else
        {
            // Rational351466, Special.Kung, 2023/07/10
            /*
            if(Error == 0)
            {
                Error = PGF3_ERR;
            }
            */
            ABV_PGSPDA = 1;
        }
// ]
		
		if(TB_100ms==1){
	    	TB_100ms = 0;

			// [ Add by DINO, 11/30/2009
		  if(((pr[DEBUG_PG]&0x0020)!=0)||pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER || pr[PG_TYPE]==SIN_SIN){  	
			if (Cnt_ubPGWait < 10){  //[For IED PG-Card, Sampo, 01/11/2010]
				Cnt_ubPGWait++;
			}
			else if(Cnt_ubPGWait < 20){  //[For IED PG-Card, Sampo, 01/11/2010]
				Cnt_ubPGWait++;
				IED_PG_START = 1;
			}
			else{
			
					EDT_READY = 1;
				
			}
		  }
			// ]

			Temp_vs_fpwm();     //update cf_swOHCarry every 20sec



			DownCFBbyOverLoad();
		}

		if(TB_1sec==1){
			VFD_Timer();
		}

		if(SHOW_ALLPR){
    	    Update_CFFxx();
    	}

    	if(Error!=0){

        	FaultLED = 1;               			//Fault LED Turn ON, DINO, 03/03/2010

			// [ LED KEYPAD, DINO, 03/12/2010
			if(KEY_ubDispTmp ==0){
				KEY_ubDispMode = ErrPAGE2;
				KEY_ubWarnTmp = 0;
			}
			// ]
			//-- Update Buffer & RAM Data
			// [ LV Option Mode, Add by DINO, 11/30/2009
			uwTemp = Error;
			if(Error==LvS_ERR || Error==bb_ERR || (LVMOD==1 && (Error==LvA_ERR || Error==Lvd_ERR || Error==Lvn_ERR))){
				uwTemp = 0;
			}

			if(uwTemp != 0){
				Fault_Record();
			}
			// ]

			if(WRINFO==0){
				rec_uwPWRmin = pr[PWR_MIN];
				rec_uwRUNmin = pr[RUNMIN];
				TQRCMemswPer = (SWORD)pr[TQREF];
				WRINFO = 1;
			}

        	Error_Handel();

    	}
    	else{
    	    FaultLED = 0;               			//Fault LED, Active Low
		    WRINFO = 0;                 		// write infomation into eprom.
		    ERR_LOG = 0;
		    err_uwFfbk = (UWORD)(abs(slMotorHz));	// Motor Speed
		    err_uwFcmd = fcmd.uw.hi;				// Output Frequency, add by dino, 10/31/2007
		    err_uwVout = Vcmd_LL;					// Output Voltage
		    err_uwDcbus = dcbusDC;					// VBUS
		    err_uwIsum = IrmsRe;					// Output Current
		    // [ Add Fault Record Data, DINO, 06/11/2009
		    err_uwFkey = fkey.uw.hi;				// Frequency Command
		    err_uwPower = Pinput.uw.hi;				// Output Power
		    // [ Change to save toruqe pu, DINO, 09/30/2009
		    err_uwTorq = swTqRefPu;				// Output Torque
		    // ]
		    err_uwMFI = mfi_now;					// Input Terminal State
		    err_uwMFO = mfo_now;					// Output Terminal State
		    err_uwState = C21xx[0x19];				// Drive State
		    // ]
		    // [ LED KEYPAD, DINO, 03/12/2010
		    KEY_ubDispTmp = 0;
		    if(WarnCode != 0){
				if(KEY_ubWarnTmp ==0){
					KEY_ubDispMode = WarnPAGE2;
				}
			}
			else{
				// [ Add by DINO, 05/31/2010
				if(KEY_ubDispMode == ErrPAGE2){
					// [ DINO, 11/18/2010
					//KEY_ubDispMode = pr[S_DISP];
    				KEY_ubDispMode = /*FunPAGE2*/0;
    				if(grno == 0)
    					KEY_uwPWRCnt = 0;
    				// ]
					Keypad_PageTmp = 0;
				}
				// ]
				else if(KEY_ubDispMode == WarnPAGE2){
					// [ DINO, 11/18/2010
					//KEY_ubDispMode = pr[S_DISP];
    				KEY_ubDispMode = /*FunPAGE2*/0;
    				if(grno == 0)
    					KEY_uwPWRCnt = 0;
    				// ]
					KEY_ubWarnTmp = 0;
				}
			}	    	
		    // ]
		    
    	}    
     
		// [ Low Voltage Record, Modify by DINO, 05/31/2010
		if(RelayOFF==1 && WRITE_PR_ATONCE==0){  // [EDS parameter at once, sampo,2018/02/05]
	     if(WRITE_LVEEP == 1){
				LV_REC();
				WRITE_LVEEP = 0;
			}
		}
		else{
			if(WRITE_PR_ATONCE==1 && uwWritePrCnt>=200){  //[EDS parameter at once,sampo,2018/02/05]
   	     frm_vdDLCWrite();
         frm_vdWrite();
   	     WRITE_PR_ATONCE = 0;
		  }
		  else
		  		WRITE_LVEEP = 1;
		}
		// ]
    
    	if(WRITE_TUNPR==1){
    	    /*--------------------------------------------------------------
    	    // COF_uwRsPu = U16xU16divU16(pr[Rs1], 16384, COF_uwRbRe);	//Q15
		    // COF_uwRrPu = U16xU16divU16(pr[Rr1], 16384, COF_uwRbRe);	//Q15
		    // COF_uwLxPu = U16xU16divU16(pr[Lx1], 51200, COF_uwLbRe);	//Q10
		    // COF_uwLmPu = U16xU16divU16(pr[Lm1], 3200, COF_uwLbRe);	//Q6
		    // COF_uwI0Pu = U16xU16divU16(pr[MI_NL1] ,46341, COF_uwIbRe);	
    	    ----------------------------------------------------------------*/       	
    	    if((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// motor 2 highest priority
    	        COF_uwIm2Pu = TUN_uwI0Pu;
    	        COF_uwRs2Pu = TUN_uwRsPu;   //Q15
    	        COF_uwRr2Pu = TUN_uwRrPu;   //Q15
    	        COF_uwLm2Pu = TUN_uwLm1Pu;	//Q6
    	        COF_uwLx2Pu = TUN_uwL1sigmaPu;	//Q10       
    	
    	        write_ep(BLK_WRITE,MI_NL2, TUN_uwI0Pu);
    	        write_ep(BLK_WRITE,Rs2, TUN_uwRsPu);
    	        write_ep(BLK_WRITE,Rr2, TUN_uwRrPu);
    	        write_ep(BLK_WRITE,Lm2, TUN_uwLm1Pu);
    	        write_ep(BLK_WRITE,Lx2, TUN_uwL1sigmaPu);      
    	        // 46341 = sqrt(2)*2^15
    	        pr[MI_NL2] = U32xU32divU32(TUN_uwI0Pu ,COF_ulIbRe, 46341);  // Jerry.sk.tseng for GFC High elecator 2021/08/17
    	
    	        // where shift right 14 mean (*2)
    	        pr[Rs2] = (((ULONG)TUN_uwRsPu * COF_uwRbRe + 8192) >> 14);	// Modify by DINO, 09/09/2008
    	        pr[Rr2] = (((ULONG)TUN_uwRrPu * COF_uwRbRe + 8192) >> 14);	// Modify by DINO, 09/09/2008
    	
    	        pr[Lm2] = U16xU16divU16(TUN_uwLm1Pu, COF_uwLbRe, 3200);     
    	        pr[Lx2] = U16xU16divU16(TUN_uwL1sigmaPu, COF_uwLbRe, 51200);          	              
#if OLD_SETTING  // Modify by DINO, 09/09/2008
            	COF_uwMI0Re = pr[MI_NL2];
            	COF_uwMRsRe = pr[Rs2];
#endif	        
        	}
        	else{									// motor 1
        	    COF_uwIm1Pu = TUN_uwI0Pu;
        	    COF_uwRs1Pu = TUN_uwRsPu;   //Q15
        	    COF_uwRr1Pu = TUN_uwRrPu;   //Q15
        	    COF_uwLm1Pu = TUN_uwLm1Pu;	//Q6
        	    COF_uwLx1Pu = TUN_uwL1sigmaPu;	//Q10
        	
        	    write_ep(BLK_WRITE,MI_NL1, TUN_uwI0Pu);
        	    write_ep(BLK_WRITE,Rs1, TUN_uwRsPu);
        	    write_ep(BLK_WRITE,Rr1, TUN_uwRrPu);
        	    write_ep(BLK_WRITE,Lm1, TUN_uwLm1Pu);
        	    write_ep(BLK_WRITE,Lx1, TUN_uwL1sigmaPu);
        	
        	    pr[MI_NL1] = U32xU32divU32(TUN_uwI0Pu ,COF_ulIbRe, 46341);  // Jerry.sk.tseng for GFC High elecator 2021/08/17
        	    pr[Rs1] = (((ULONG)TUN_uwRsPu * COF_uwRbRe + 8192) >> 14);	// Modify by DINO, 09/09/2008
        	    pr[Rr1] = (((ULONG)TUN_uwRrPu * COF_uwRbRe + 8192) >> 14);	// Modify by DINO, 09/09/2008
        	    pr[Lm1] = U16xU16divU16(TUN_uwLm1Pu, COF_uwLbRe, 3200);     
        	    pr[Lx1] = U16xU16divU16(TUN_uwL1sigmaPu, COF_uwLbRe, 51200);
#if OLD_SETTING  // Modify by DINO, 09/09/2008
            	COF_uwMI0Re = pr[MI_NL1];
            	COF_uwMRsRe = pr[Rs1];
#endif
        	}

			MotorPrSel();	// Add by DINO, 09/09/2008

        	if (WRITE_FLUXPR==1){
        	    write_ep(BLK_WRITE,LMPU6, pr[LMPU6]);
        	    write_ep(BLK_WRITE,EMFPU6, pr[EMFPU6]);
        	    write_ep(BLK_WRITE,LMPU5, pr[LMPU5]);
        	    write_ep(BLK_WRITE,EMFPU5, pr[EMFPU5]);
        	    write_ep(BLK_WRITE,LMPU3, pr[LMPU4]);
        	    write_ep(BLK_WRITE,EMFPU3, pr[EMFPU4]);
        	    write_ep(BLK_WRITE,LMPU2, pr[LMPU2]);
        	    write_ep(BLK_WRITE,EMFPU2, pr[EMFPU2]);
        	    write_ep(BLK_WRITE,LMPU1, pr[LMPU1]);
        	    write_ep(BLK_WRITE,EMFPU1, pr[EMFPU1]);
		    
        	    WRITE_FLUXPR = 0;
	    	}
          WRITE_PR_ATONCE = 1;   // [EDS parameter at once, sampo,2018/02/05]
          uwWritePrCnt = 200;    // [EDS parameter at once, sampo,2018/02/05]
    	    WRITE_TUNPR = 0;    		
    	    set_Rs();    
    	    set_VcmpMax();
    	}
    
    	if (WRITE_DBCPR==1){
    	    write_ep(BLK_WRITE,DBC1, DBC_uwDuty_t_10K);
    	    pr[DBC1] = DBC_uwDuty_t_10K;
    	    write_ep(BLK_WRITE,DBC2, DBC_uwD_u_10KUcom);
    	    pr[DBC2] = DBC_uwD_u_10KUcom;
    	    WRITE_PR_ATONCE = 1;   //[EDS parameter at once,sampo,2018/02/05]
          uwWritePrCnt = 0;    //[EDS parameter at once,sampo,2018/02/05]
    	    WRITE_DBCPR = 0;            
    	    DBC_COEFInit();
    	}
    
    	if (WRITE_CCBPR==1){
    	    write_ep(BLK_WRITE,CALI_REF,uwCurCalibRatio);
    	    pr[CALI_REF] = uwCurCalibRatio;
    	    WRITE_PR_ATONCE = 1;   //[EDS parameter at once,sampo,2018/02/05]
          uwWritePrCnt = 0;    //[EDS parameter at once,sampo,2018/02/05]
    	    WRITE_CCBPR = 0;
    	}
        
// add scotty 2007/08/27         
    	if(WRITE_TUNPMPR == 1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
			COF_uwRs1Pu = TUN_uwRsPu;   //Q15
			COF_uwLx1Pu = TUN_uwL1sigmaPu;	//Q10
#else
			COF_uwRs3Pu = TUN_uwRsPu;   //Q15
			COF_uwLx3Pu = TUN_uwL1sigmaPu;	//Q10
#endif		
			write_ep(BLK_WRITE,PM_Rs, TUN_uwRsPu);
			pr[PM_Rs] = (((ULONG)TUN_uwRsPu * COF_uwRbRe + 8192) >> 14);	// Modify by DINO, 09/09/2008
#if OLD_SETTING  // Modify by DINO, 09/09/2008
			COF_uwMRsRe = pr[PM_Rs];
#endif		  
        	write_ep(BLK_WRITE,PM_Lq, TUN_uwL1sigmaPu);   
        	pr[PM_Lq] = U16xU16divU16(TUN_uwL1sigmaPu, COF_uwLbRe, 51200);
			// [ Calculate BEMF, Add by DINO, 06/03/2009
			/*========================================================================================================
            =           P     2
			=   BEMF = --- * --- - Rs * i
			=           i     3
			=               (COF_uwMPRe*10)      2             COF_uwRrPu * COF_uwRbRe     COF_uwMIrRe
			=   BEMF =  ( ------------------- * --- * 16384 - ------------------------- * ------------- ) * 10
		    =(dot1,Q14)    (COF_uwMIrRe/100)     3                       1000                   100
			=   
			=  10*100*2/3*16384*10 = 109226667
			=========================================================================================================*/
			ulTemp = U32xU32divU32(109226667, pr[PM_P_RATED], pr[PM_MI_RAT]);
			ulTemp = (ulTemp - ((ULONG)COF_uwRs3Pu * COF_uwRbRe / 10000 * pr[PM_MI_RAT]));
        	uwTemp = (UWORD)(ulTemp >> 14);
        	// [ Save 2 times BEMF to EEPROM in 220V types, Modify by DINO, 07/13/2009
        	pr[PM_Bemf] = uwTemp;
			if ((pr[HPSPEC]&VFD440V) == VFD220V){		// 220V class
				uwTemp <<= 1;
			}
			// End on 07/13/2009 ]
        	write_ep(BLK_WRITE,PM_Bemf, uwTemp);
			COF_uwBemfPu = U16xU16divU16(pr[PM_Bemf], 26755, COF_uwVbRe);
   			// End on 06/03/2009 ]

			MotorPrSel();	// Add by DINO, 09/09/2008
      WRITE_PR_ATONCE = 1;   //[EDS parameter at once,sampo,2018/02/05]
      uwWritePrCnt = 200;    //[EDS parameter at once,sampo,2018/02/05]
			WRITE_TUNPMPR = 0;    		
    	} 
    
// add scotty 2007/06/07        
#if SCOTTY 
		if(WRITE_TUNZOFFSET == 1){
			uwTemp = U16xU16divU16(PG_Zoffset, 3600, SpDt_uwAnglePeriod);	//ADD 09/17/2007	SC
			if (uwTemp == 3600){uwTemp = 0;}		//3600 reverse for Z phase tuning	09/28/2007
			write_ep(BLK_WRITE,Z_OFFSET, uwTemp);		//ADD 09/17/2007	SC
			pr[Z_OFFSET] = uwTemp ;						//ADD 09/17/2007	SC
		
//		write_ep(BLK_WRITE,Z_OFFSET, PG_Zoffset);	//delect 09/17/2007 SC
//		pr[Z_OFFSET] = U16xU16divU16(PG_Zoffset, 3600, SpDt_uwAnglePeriod); //delect 09/17/2007 SC
//---- added by dino	06/07/2007 ---------

        	write_ep(BLK_WRITE,SINMAX, TUN_SINDATAMAX);  // Pr15-87
        	pr[SINMAX] = TUN_SINDATAMAX;
        	write_ep(BLK_WRITE,SINMIN, TUN_SINDATAMIN);  // Pr15-88
        	pr[SINMIN] = TUN_SINDATAMIN;
        	write_ep(BLK_WRITE,COSMAX, TUN_COSDATAMAX);  // Pr15-89
        	pr[COSMAX] = TUN_COSDATAMAX;
        	write_ep(BLK_WRITE,COSMIN, TUN_COSDATAMIN);  // Pr15-90
        	pr[COSMIN] = TUN_COSDATAMIN;         
        	AnaPGInit();
        	if(pr[PG_TYPE]==ABZ_UVW){						 //11/06/2007 SC
        	  	if(TUN_uwUVWsector==1)
        	  	    ax = 5;
        	  	else if(TUN_uwUVWsector==2) 
        	  	    ax = 3;
        	  	else if(TUN_uwUVWsector==3)
        	  	    ax = 4;
        	  	else if(TUN_uwUVWsector==4)
        	  	    ax = 1;
        	  	else if(TUN_uwUVWsector==5)
        	  	    ax = 0;
        	  	else
        	  	    ax = 2;
        		write_ep(BLK_WRITE,Z_SECT, ax);  // Pr15-90
        		pr[Z_SECT] = ax;
        	}
      WRITE_PR_ATONCE = 1;   //[EDS parameter at once,sampo,2018/02/05]
      uwWritePrCnt = 200;    //[EDS parameter at once,sampo,2018/02/05]
			WRITE_TUNZOFFSET = 0;
//---- End 06/07/2007 ---------
		}
        
        if((WRITE_Z_1387 == 1) && (uwSt1387cnt>1500)){     // [IED 1387 static Tune, 2011/07/06]
        	PG_Zoffset_1387 = uwPGThetaE_COM;
        	uwTemp = U16xU16divU16(PG_Zoffset_1387, 3600, SpDt_uwAnglePeriod);	
			if (uwTemp == 3600){uwTemp = 0;}		
			write_ep(BLK_WRITE,Z_OFFSET, uwTemp);		
			pr[Z_OFFSET] = uwTemp ;		
        	WRITE_Z_1387 = 0;
        	uwSt1387cnt = 0;
        }
#endif
// end 2007/06/07 

//---- Save UVW Standstill Tunning datas to EEPROM, Add by DINO, 07/09/2008
		if(WRITE_ZSECT==1){
//--- EnDat Static tuning, Add by DINO, 08/29/2008
			// pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER
			uwTemp = U16xU16divU16(PG_Zoffset, 3600, SpDt_uwAnglePeriod);	//ADD 09/17/2007	SC
			if(uwTemp == 3600){
			    uwTemp = 0;
			}		//3600 reverse for Z phase tuning	09/28/2007
			write_ep(BLK_WRITE,Z_OFFSET, uwTemp);		//ADD 09/17/2007	SC
			pr[Z_OFFSET] = uwTemp ;						//ADD 09/17/2007	SC
//--- End on 08/29/2008
      WRITE_PR_ATONCE = 1;   //[EDS parameter at once,sampo,2018/02/05]
      uwWritePrCnt = 200;    //[EDS parameter at once,sampo,2018/02/05]
			WRITE_ZSECT = 0;
		}
//---- End on 07/09/2008

        if ((pr[DEBUG_F1]&0x0008) == 0x0008)
        {   // Bit 3: Enable all ICT test
            if (pr[PG_TYPE] == SIN_ENDAT){
                DINT();
                SCI0_DIR = SCIDIR0Flag;
                EINT();

                if (RX_OK0==1){
                    SCIDIR0Flag = 0;
                    Init_TxData_0(Rx0CNT);
                    SCI0_TodCNT = 0;
					RX_OK0 = 0;
				}
				TxD_Data_0();
				if (Com_WatchDog0>50)    	// WatchDog Timer > 5.0 sec
					InitSCI0();
        	}
            if(pr[PG_TYPE] == ABZ_UVW){           //[Used For PG ABD Test, Bernie, 10/28/2011]
                STtune =1;
			    PGSEL = 0;
			    ulPGSWCnt = 0;
                while(ulPGSWCnt < 90000){ // waiting for ABZ->UVW 7000us(At least 3914us+100us), turn on 4ms, sample UVW 100us, DINO, 03/09/2010
                    ulPGSWCnt++;
                    nop();
                    nop();
                    nop();
                    nop();
                }
			    //uwPGA = PA.PR.BIT.B6;   // U phase
			    //uwPGB = PA.PR.BIT.B7;   // V phase
			    //uwPGZ = PD.PR.BIT.B24;  // W phase  
                uwPGA = PORT2.PIDR.BIT.B1;   // U phase
                uwPGB = PORT2.PIDR.BIT.B0;   // V phase
                uwPGZ = PORT9.PIDR.BIT.B2;   // W phase
			    PGSEL =1;
			    uwHall = (uwPGA<<2) + (uwPGB<<1) + uwPGZ;
                APR_uwThetaNoMx = uwHall;
            }
        	//else{
     			// [ Modify ICT Test Method, DINO, 03/03/2010
            if((pr[DEBUG_F1]&0x0010)==0x0010){	// Bit 4: for ICT test
                DO_RLY1_PIN  = 0;   
                DO_RLY2_PIN  = 1;
                DO_RLY3_PIN  = 0;
                DO_RLY4_PIN  = 1;
                DO_RLY5_PIN  = 0;
                DO_RLY6_PIN  = 1;

                //DOE_RLY1_PIN = 0;     //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]  //[ICT Relay test, Bernie, 08/15/2011]
                //DOE_RLY2_PIN = 1;     //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]

                DOE_RLY3_PIN = 0;
                //DOE_RLY4_PIN = 1;
                //DOE_RLY5_PIN = 0;
                //DOE_RLY6_PIN = 1;
                //DOE_RLY7_PIN = 0;
                //DOE_RLY8_PIN = 1;
            }
            else if((pr[DEBUG_F1]&0x0010)==0x0000){// Bit 4: for ICT test
                DO_RLY1_PIN  = 1;
                DO_RLY2_PIN  = 0;
                DO_RLY3_PIN  = 1;
                DO_RLY4_PIN  = 0;
                DO_RLY5_PIN  = 0;
                DO_RLY6_PIN  = 1;

                //DOE_RLY1_PIN = 1;     //[IEDS vs. EDS deriver,Lyabryan,2016/07/14] //[ICT Relay test, Bernie, 08/15/2011]
                //DOE_RLY2_PIN = 0;     //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
                DOE_RLY3_PIN = 1;
                //DOE_RLY4_PIN = 0;
                //DOE_RLY5_PIN = 1;
                //DOE_RLY6_PIN = 0;
                //DOE_RLY7_PIN = 1;
                //DOE_RLY8_PIN = 0;
            }
        	//}
		}
//--- Add by DINO, 12/14/2007
		else
        {
    	    if(pr[PG_TYPE]<ABZ_UVW){    //[Modify PG Type Define, Bernie, 12/05/2011]
    	       if((pr[DEBUG_F1]&0x0020)==0x0020)	// Bit 5: change PGSEL
                   PGSEL = 0;	// Read UVW, DINO, 03/09/2010
    	       else
                   PGSEL = 1;   // Read ABZ, DINO, 03/09/2010
    	    }

    	}
//--- End by DINO, 12/14/2007

#if DINO	// dino, 03/08/2007
		if (pr[PRRESET] == 0x0002){
			DATASEL = pr[DATA_SEL];
			DATASEL |=0x00000000; //for test
#if 1	// RAM read parameter by ReadRamDataRX63T, Sean, 20141225
			pr[SHOW_DATA] = ReadRamDataRX63T(pr[DATA_SEL]);
#else			
			pr[SHOW_DATA]=*(UWORD *)DATASEL ;   //[Data display in keypad, Bernie, 08/22/2011] 
			pr[SHOW_DATA] = ReadRamData(pr[DATA_SEL]);       // USB FUNCTION BERNIE
#endif			
		}
#endif
    }   //End of while(1) loop
}

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
/*====================================================================================================*/
//速度優先權定義
//1.啟動運行至高速等速前，可以接受所有命令速度指令
//2.高速等速減速至低速等速(平層速)中，可接受速度命令低於當前運行速度，若速度命令大於當前運行速度，
//  不接受並持續運行至前一個目標速度
//3.檢修運行時，可接受比檢修速度低的速度命令，但不能高
//4.救援速度不能被其他速度切換(除了零速或停止)
/*====================================================================================================*/
UWORD Sibocom_Speed_Priority(UWORD ax){

    UBYTE btx;
    UWORD freq;

    btx = pr[FMI0+speed-1];
	if(!EPS){
	    if((speed!=0)&&(SIBO_EMYFLAG==0)){
	        SIBO_ZEROF = 0;
	        Sibocom_spflag.uw &=0x000A;
	        switch(btx){
	            case 0:
	                freq = pr[JOGF];
	                SIBO_INSF = 1;
	                Speed_INS = speed;
	            break;
	            case 1:
	                freq = pr[FMI7];
	                SIBO_LEVELF = 1;
	            break;
	            case 2:
	                freq = pr[FMI8];
	                SIBO_RELEVELF = 1;
	                Speed_RELEVEL = speed;
	            break;
	            case 3:
	                freq = pr[FMI9];
	                SIBO_LOWF = 1;
	            break;
	            case 4:
	                freq = pr[FMI10];
	                SIBO_MIDF = 1;
	            break;
	            case 5:
	                freq = pr[FMI11];
	                SIBO_HIGHF = 1;
	            break;
	            case 6:
	                freq = pr[FMI12];
	                SIBO_NORMALF = 1;
	            break;
	            default:
	                freq = 0;
	            break;
	        }
	    }
	    else{
	        freq = 0;
	        SIBO_ZEROF = 1;
	    }

	    if(IODLC_ubArea_status<Areahold){
	        ax = speed;
	    }
	    else if((IODLC_ubArea_status>=Areahold)&&(IODLC_ubArea_status<=Arealand)){
	        if(freq>=fcmd.uw.hi){
	            ax = Speed_check;
	        }
	        else
	            ax = speed;
	    }
	    else if(IODLC_ubArea_status>Arealand){
	        if(SIBO_ZEROF==0){
	            if(freq>=fcmd.uw.hi){
	                ax = Speed_check;
	            }
	            else
	                ax = speed;
	        }
	        else
	            ax = 0;
	    }

	    if(SIBO_INSF){
	        if(SIBO_ZEROF==0){
	            if(freq<=fcmd.uw.hi)
	                ax = speed;
	            else
	                ax = Speed_INS;
	        }
	        else{
	            ax = 0;
	            if(fcmd.uw.hi == 0)
	                SIBO_INSF = 0;
	        }
	    }
	    if(SIBO_RELEVELF){
	        if(SIBO_ZEROF==1){
	            ax = 0;
	            //SIBO_RELEVELF= 0;
	        }
	        else
	            ax = Speed_RELEVEL;
	        if(fcmd.uw.hi == 0)
	            SIBO_RELEVELF = 0;
	    }
	}
	else{
		if(speed==0){
			SIBO_RELEVELF = 1;
			for(UBYTE i=0;i<=6;i++){
				if(pr[FMI0+i]==RELEVELSP){
					Speed_RELEVEL = i+1;
					break;
				}
			}
			ax = Speed_RELEVEL;
		}
		else{
			ax = speed;
		}
	    if(SIBO_RELEVELF){
	        if((IODLC_ubArea_status>Areahold)&&(fcmd.uw.hi == 0))
	            SIBO_RELEVELF = 0;
	    }
	}
		
    return ax;

}
#endif
void function_chk(void)
{
    UWORD ix,iy;
    UWORD_UNION iz;
    UBYTE i,j;

    i = 0;
    j = 0;
    do{
        ix = checkV[i];
        iy = CPR[i];
        i++;
        iz.ub.hi = ix + iy;
        ix = checkV[i];
        iy = CPR[i];
        i++;          
        iz.ub.low = ix + iy;;
        checkValue += (iz.ub.hi + iz.ub.low);
        Descript[j] = iz.uw;
        j++;          
    }while (i<16);
}


void Sinusoidal_Position(void)
{
    UBYTE ubStage;
    SWORD swSIN, swCOS, swX, swY, swS, swC, swPGInit;
    UWORD uwTan, uwOffset,uw_Z90angle,uw_Xangle,uw_temp, uwPGThetaE;
    ULONG ulPGThetaE_COMtemp;     // [IED 1387 static Tune, 2011/07/06]

#if 1/*IED_PG_ERN1387*/ //[For ERN1387, Sampo, 01/08/2010]
   
  //  st_swSINmean = (Pgc_uwCpo + Pgc_uwCne)>>1;                  
	//	st_swCOSmean = (Pgc_uwDpo + Pgc_uwDne)>>1;        
	 /* if(PGDIR){        //[For IED PG-Card, Sampo, 02/25/2010]
	    st_swSINmean =  (Pgc_uwDpo + Pgc_uwDne)>>1;                
	    st_swCOSmean =  (Pgc_uwCpo + Pgc_uwCne)>>1;          
	    swSIN = Pgc_uwDpo;    
	    swCOS = Pgc_uwCpo;	
	   }
	  else{*/
    st_swSINmean =  (Pgc_uwCpo + Pgc_uwCne)>>1;                
    st_swCOSmean =  (Pgc_uwDpo + Pgc_uwDne)>>1;          
    swSIN = Pgc_uwCpo;    
    swCOS = Pgc_uwDpo;
      //} 
                        
    if(swSIN>=4095){
        swSIN = 4095;
    }
    else if(swSIN<=0){
        swSIN = 1;
    }

                                        
    if(swCOS>=4095){
        swCOS = 4095;
    }
    else if(swCOS<=0){
        swCOS = 1;
    }


    swSIN = swSIN - st_swSINmean;                               
    swS = swSIN;
    if(swSIN<0){
        swSIN = -swSIN;
    }
    swSIN = ((SLONG)swSIN<<12) / (4095 - st_swSINmean);	        

    swCOS = swCOS - st_swCOSmean;                              
    swC = swCOS;
    if(swCOS<0){
        swCOS = -swCOS;
    }
    swCOS = ((SLONG)swCOS<<12) / (4095 - st_swCOSmean);	        

    st_swSINnew = swSIN<<3;                                   
    st_swCOSnew = swCOS<<3;                                     

#else

    swSIN = SINadLPF.sw.hi;	// Sin_data
	if ( swSIN>=pr[SINMAX] ){ swSIN = pr[SINMAX]-1; }
	else if ( swSIN<=pr[SINMIN] ){ swSIN = pr[SINMIN]+1; }

    swCOS = COSadLPF.sw.hi;	// Cos_data
	if ( swCOS>=pr[COSMAX] ){ swCOS = pr[COSMAX]-1; }
	else if ( swCOS<=pr[COSMIN] ){ swCOS = pr[COSMIN]+1; }

    swSIN = swSIN - st_swSINmean;
    swS = swSIN;
    if ( swSIN<0 ){ swSIN = -swSIN; }
    swSIN = ((SLONG)swSIN<<12) / (pr[SINMAX] - st_swSINmean);	//Q12

    swCOS = swCOS - st_swCOSmean;
    swC = swCOS;
    if ( swCOS<0 ){ swCOS = -swCOS; }
    swCOS = ((SLONG)swCOS<<12) / (pr[COSMAX] - st_swCOSmean);	//Q12
    
    st_swSINnew = swSIN<<3;
    st_swCOSnew = swCOS<<3;
#endif

	slSINsquarePu = ((SLONG)st_swSINnew*st_swSINnew + (SLONG)st_swCOSnew*st_swCOSnew);
 

/*   ____    ____          ____    ____
         \  /    \        /    \  /    \
  sin     \/      \      /      \/      \
          /\       \    /       /\       \
  -------/--\-------\--/-------/--\-------\
        /    \       \/       /    \
  cos  /      \      /\      /      \
     _/        \____/  \____/        \____
          |  |  |  | |  |  |  |
  stage   0  1  2  3 4  5  6  7
*/

    if(swS > 0){
        if(swC > 0){
        	if(swSIN < swCOS){
        	    ubStage = 0;
        	}
        	else{
        	    ubStage = 1;
        	}
        }
        else{
        	if(swSIN < swCOS){
        	    ubStage = 3;
        	}
        	else{
        	    ubStage = 2;
        	}
        }
    } 
    else{
        if(swC > 0){
        	if(swSIN < swCOS){
        	    ubStage = 7;
        	}
        	else{
        	    ubStage = 6;
        	}
        }
        else{
        	if(swSIN < swCOS){
        	    ubStage = 4;
        	}
        	else{
        	    ubStage = 5;
        	}
        }
    }

    if(swSIN<swCOS){
        swX = swSIN;
        swY = swCOS;
    }
    else{
        swX = swCOS;
        swY = swSIN;
    }

    st_swXout = swX;
    st_swYout = swY;

	if(swY==0)
	    swY=1;
	    
    uwTan = ((SLONG)swX << 10) / swY;							// Q10

    if(uwTan>1023){
        uwTan = 1023;
    }							// max = sin/cos =1 = 45
    
    st_uwAngle = arctan[uwTan];  								// Mechanical angle, 0~45, Q10
 
    if(ubStage & 0x0001){
        uwOffset = 46080 - st_uwAngle;
    }      // 0~45 => decreasing  46080 = (360<<7)
    else{
        uwOffset = st_uwAngle;
    }                                // 0~45 => increasing
   
   
    if(vfd_btPGHSD1Set==1){	// fix pghsd1 code, Sean, 06/01/2012
        st_uwAbsAngle = (UWORD)(((ULONG)hsd_stPgReplyOut.uwAngle * 45) >> 3);	// down scaling to 360: 45=(360,Q10/8192(res)), then shift to Q7
	}
	else{  //[delete PGHSD, Lyabryan, 2015/12/17]
    	st_uwAbsAngle = ((UWORD)ubStage * 45 << 7) + (uwOffset>>3);    // Mechanical angle, 0~360 Q7 (46080 vs 360, normal Heidmain Zpulse:180*128=23040 )
	}
//    st_uwPGThetaM = st_uwAbsAngle % ( (360<<7) / (pr[PM_POLES]>>1) ); // PG pulse corresponding to mechanical angle, Q7,

     st_uwAbsAngleTune = st_uwAbsAngle;                        //[Fix state tune problem, Bernie, 2014/09/02 ]
     if(st_uwAbsAngleTune>=23040)                              //if Absangle >= 180    23040 = (180<<7)
         st_uwAbsAngleTune = st_uwAbsAngleTune - 23040;        //Absangle - 180
     else
         st_uwAbsAngleTune = st_uwAbsAngleTune + 23040;        //Absangle + 180

     //ulPGThetaE_COMtemp = (((ULONG)(st_uwAbsAngle) * SpDt_ulPG1NpulseNoMx / 360 ) >> 7); // [IED 1387 static Tune, 2011/07/06]
     ulPGThetaE_COMtemp = (((ULONG)(st_uwAbsAngleTune) * SpDt_ulPG1NpulseNoMx / 360 ) >> 7); // [IED 1387 static Tune, 2011/07/06]
     uwPGThetaE_COM2 = ulPGThetaE_COMtemp % SpDt_uwAnglePeriod;                          // [IED 1387 static Tune, 2011/07/06]


//-- Add by DINO, 08/13/2007
	if(PGDIR==1){

		if(st_uwAbsAngle >= (180<<7)){
			uwPGThetaE = (UWORD)(((ULONG)(st_uwAbsAngle - (180<<7)) * SpDt_ulPG1NpulseNoMx / 360 ) >> 7);
			st_uwAnaPGInit = ( uwPGThetaE + PG_Zoffset) % SpDt_uwAnglePeriod;
		}
		else{
			uwPGThetaE = (UWORD)(((ULONG)((180<<7) - st_uwAbsAngle) * SpDt_ulPG1NpulseNoMx / 360 ) >> 7);
			if(uwPGThetaE >= PG_Zoffset)
				st_uwAnaPGInit = SpDt_uwAnglePeriod - (( uwPGThetaE - PG_Zoffset) % SpDt_uwAnglePeriod);
			else
				st_uwAnaPGInit = SpDt_uwAnglePeriod - (( uwPGThetaE + SpDt_uwAnglePeriod - PG_Zoffset) % SpDt_uwAnglePeriod);
		}
	}
	else{
		
		if(st_uwAbsAngle >= (180<<7)){
			uwPGThetaE = (UWORD)(((ULONG)(st_uwAbsAngle - (180<<7)) * SpDt_ulPG1NpulseNoMx / 360 ) >> 7);
			if(uwPGThetaE >= PG_Zoffset)
				st_uwAnaPGInit = ( uwPGThetaE - PG_Zoffset) % SpDt_uwAnglePeriod;
			else
				st_uwAnaPGInit = ( uwPGThetaE + SpDt_uwAnglePeriod - PG_Zoffset) % SpDt_uwAnglePeriod;
		}
		else{
			uwPGThetaE = (UWORD)(((ULONG)((180<<7) - st_uwAbsAngle) * SpDt_ulPG1NpulseNoMx / 360 ) >> 7);
			st_uwAnaPGInit = SpDt_uwAnglePeriod - (( uwPGThetaE + PG_Zoffset) % SpDt_uwAnglePeriod);
		}
	}
//-- End 08/13/2007
      
}

void ICT4SCI3(void){
    //if(mfi_status == 0x0008){
    Rx3CNT = 16;
    Tx3CNT = 16;
    
    RxBuf_3[0] = 0x3A;
    RxBuf_3[1] = 0x38;
    RxBuf_3[2] = 0x32;
    RxBuf_3[3] = 0x31;
    RxBuf_3[4] = 0x34;
    RxBuf_3[5] = 0x30;
    RxBuf_3[6] = 0x41;
    RxBuf_3[7] = 0x30;
    RxBuf_3[8] = 0x30;
    RxBuf_3[9] = 0x30;
    RxBuf_3[10] = 0x32;
    RxBuf_3[11] = 0x30;
    RxBuf_3[12] = 0x30;
    RxBuf_3[13] = 0x35;
    RxBuf_3[14] = 0x45;
    
    SCIDIR3Flag = 0;   // Transmit    
    Init_TxData_3(14);
    TxBuf_3[15] = CR_0D;
    
    TxBuf_3[16] = LF_0A;
    //}

}    

void Recent_Setting_Parameter(UWORD prx){ //[Last Key parameter,Lyabryan,2020/02/05]
    SWORD i;
    
    if(PRUPDATE==1){
        RSP_uwRecent_pr = prx;
        if(RSP_uwRecent_prold!=RSP_uwRecent_pr){
            RSP_uwRecent_prinfo = Group_Check(RSP_uwRecent_pr);
            RSP_uwRecent_no = 0;
            for(i=0;i<=49;i++){
                if(pr[UMAP_ADD99-i]==RSP_uwRecent_prinfo){
                    RSP_uwRecent_no = i;
                    break;
                }
            }
            if(RSP_uwRecent_no!=0){
                for(i=(RSP_uwRecent_no-1);i>=0;i--){
                    RSP_uwRecent[i+1] = RSP_uwRecent[i];
                }
            }
            else{
                for(i=49;i>=0;i--){
                    RSP_uwRecent[i+1] = RSP_uwRecent[i];
                }
            }
            RSP_uwRecent[0] = RSP_uwRecent_prinfo;
            for(i=0;i<=49;i++)
                pr[UMAP_ADD50+i] = RSP_uwRecent[49-i];
        }
        RSP_uwRecent_prold = RSP_uwRecent_pr;
    }
}
UWORD Group_Check(UWORD prx){
    UWORD group,number;
    if(prx>=GROUP14){
        number = 0;
        group = 0;
    }
    else if(prx>=GROUP13){
        number = 0;
        group = 0;
    }
    else if(prx>=GROUP12){
        number = 0;
        group = 0;
    }
    else if(prx>=GROUP11){
        number = prx -  GROUP11;
        group = 11;
    }
    else if(prx>=GROUP10){
        number = prx -  GROUP10;
        group = 10;
    }
    else if(prx>=GROUP9){
        number = prx -  GROUP9;
        group = 9;
    }
    else if(prx>=GROUP8){
        number = prx -  GROUP8;
        group = 8;
    }
    else if(prx>=GROUP7){
        number = prx -  GROUP7;
        group = 7;
    }
    else if(prx>=GROUP6){
        number = prx -  GROUP6;
        group = 6;
    }
    else if(prx>=GROUP5){
        number = prx -  GROUP5;
        group = 5;
    }
    else if(prx>=GROUP4){
        number = prx -  GROUP4;
        group = 4;
    }
    else if(prx>=GROUP3){
        number = prx -  GROUP3;
        group = 3;
    }
    else if(prx>=GROUP2){
        number = prx -  GROUP2;
        group = 2;
    }
    else if(prx>=GROUP1){
        number = prx -  GROUP1;
        group = 1;
    }
    else if(prx>=GROUP0){
        number = prx -  GROUP0;
        group = 0;
    }
    else{
        number = 0;
        group = 0;
    }
    prx = group*100+number;
    return prx;
}
void LV_REC(void)
{
	UWORD uwEEPData, uwBuffer, uwEEPData1,i;

	if ( EPS==0){  // Don't write EEPROM when EPS==1

		//uwEEPData = MTU21.TCNT;
		uwEEPData = MTU1.TCNT;
		if(PGDIR!=1){
    		uwEEPData = 65535 - uwEEPData + 1;
		}
		uwBuffer = uwEEPData - SpDt_uwPG1CNT_Save;
		
		write_ep(BLK_WRITE,PG_POSatLV,uwBuffer);
		pr[PG_POSatLV] = uwBuffer;
		for(i=0;i<=49;i++){
            write_ep(0,(UMAP_ADD50+i),pr[(UMAP_ADD50+i)]);
		}
    	write_ep(0,FFBK_REC,pr[FFBK_REC]);
    	write_ep(0,FOUT_REC,pr[FOUT_REC]);
		write_ep(0,VOUT_REC,pr[VOUT_REC]);
    	write_ep(0,DCBUS_REC,pr[DCBUS_REC]);
		write_ep(0,ISUM_REC,pr[ISUM_REC]);	   	   
    	write_ep(0,TH_TEMP,pr[TH_TEMP]);
    	write_ep(0,SRYREC,pr[SRYREC]);
        //[special,increase error record, 2018/09/20
        write_ep(0,FOUT_REC1,pr[FOUT_REC1]);
    	write_ep(0,DCBUS_REC1,pr[DCBUS_REC1]);
		write_ep(0,ISUM_REC1,pr[ISUM_REC1]);
        write_ep(0,TH_TEMP1,pr[TH_TEMP1]);
        write_ep(0,FOUT_REC2,pr[FOUT_REC2]);
    	write_ep(0,DCBUS_REC2,pr[DCBUS_REC2]);
		write_ep(0,ISUM_REC2,pr[ISUM_REC2]);
        write_ep(0,TH_TEMP2,pr[TH_TEMP2]);
        write_ep(0,FOUT_REC3,pr[FOUT_REC3]);
        write_ep(0,DCBUS_REC3,pr[DCBUS_REC3]);
		write_ep(0,ISUM_REC3,pr[ISUM_REC3]);
        write_ep(0,TH_TEMP3,pr[TH_TEMP3]);
        write_ep(0,FOUT_REC4,pr[FOUT_REC4]);
        write_ep(0,DCBUS_REC4,pr[DCBUS_REC4]);
		write_ep(0,ISUM_REC4,pr[ISUM_REC4]);
        write_ep(0,TH_TEMP4,pr[TH_TEMP4]);
        write_ep(0,FOUT_REC5,pr[FOUT_REC5]);
        write_ep(0,DCBUS_REC5,pr[DCBUS_REC5]);
		write_ep(0,ISUM_REC5,pr[ISUM_REC5]);
        write_ep(0,TH_TEMP5,pr[TH_TEMP5]);
        
        //special,increase error record, 2018/09/20]

    	write_ep(0,ERR_REC1,pr[ERR_REC1]);
    	write_ep(0,ERR_MIN1,pr[ERR_MIN1]);
    	write_ep(0,ERR_DAY1,pr[ERR_DAY1]);

    	write_ep(0,ERR_REC2,pr[ERR_REC2]);
    	write_ep(0,ERR_MIN2,pr[ERR_MIN2]);
    	write_ep(0,ERR_DAY2,pr[ERR_DAY2]);

    	write_ep(0,ERR_REC3,pr[ERR_REC3]);
    	write_ep(0,ERR_MIN3,pr[ERR_MIN3]);
    	write_ep(0,ERR_DAY3,pr[ERR_DAY3]);

    	write_ep(0,ERR_REC4,pr[ERR_REC4]);
    	write_ep(0,ERR_MIN4,pr[ERR_MIN4]);
    	write_ep(0,ERR_DAY4,pr[ERR_DAY4]);

    	write_ep(0,ERR_REC5,pr[ERR_REC5]);
    	write_ep(0,ERR_MIN5,pr[ERR_MIN5]);
    	write_ep(0,ERR_DAY5,pr[ERR_DAY5]);

    	write_ep(0,ERR_REC6,pr[ERR_REC6]);
    	write_ep(0,ERR_MIN6,pr[ERR_MIN6]);
    	write_ep(0,ERR_DAY6,pr[ERR_DAY6]);


    	write_ep(0,PWR_MIN,pr[PWR_MIN]);
    	write_ep(0,RUNMIN,pr[RUNMIN]);
    	write_ep(0,TQREF,pr[TQREF]);

    	write_ep(0,FMAIN,uwFkeypad);
    	write_ep(0,FCMAIN,6000);

    	write_ep(0,PGHOME,PGHOMEMem);
    	write_ep(0,MI_INV,MI_INVMem);
    	write_ep(0,MO_INV,MO_INVMem);
    	write_ep(0,FKEY_REC,pr[FKEY_REC]);
    	write_ep(0,POWER_REC,pr[POWER_REC]);
		write_ep(0,TQ_REC,pr[TQ_REC]);
    	write_ep(0,MFI_REC,pr[MFI_REC]);
		write_ep(0,MFO_REC,pr[MFO_REC]);
		write_ep(0,STATE_REC,pr[STATE_REC]);
        
        write_ep(0,EOL_RECODHI,pr[EOL_RECODHI]);  //[add for UL EoL Verification,Bernie, 2013/04/22]
        write_ep(0,EOL_RECODLO,pr[EOL_RECODLO]);  //[add for UL EoL Verification,Bernie, 2013/04/22]

		write_ep(0,CUR_PG_H,pr[CUR_PG_H]);
		write_ep(0,CUR_PG_L,pr[CUR_PG_L]);
		
		write_ep(0,TABST0_COUNT,pr[TABST0_COUNT]);	
		write_ep(0,TABST1_COUNT,pr[TABST1_COUNT]);
		write_ep(0,TABST0_STATUS,pr[TABST0_STATUS]);	
		write_ep(0,TABST1_STATUS,pr[TABST1_STATUS]);	
		write_ep(0,EST_STATUS ,pr[EST_STATUS ]);
		write_ep(0,EST_COUNT ,pr[EST_COUNT ]);

        write_ep(0,SERVICE_COUNT ,pr[SERVICE_COUNT]);    //[Service time function, Bernie, 2017/03/14]
          //DLC para initial error
          //[
		          //fram_buf[CUR_PG_H] = pr[CUR_PG_H];   //Bernie
		          //fram_buf[CUR_PG_L] = pr[CUR_PG_L];   //Bernie      
          //]	
			
#if FRAM_BUF	// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 
    frm_vdDLCWrite();

    frm_vdWrite();
#endif

 


	}  // EPS==0
}

//[JES Torq Detect Function, Special.Kung, 2022/09/01]
void TorqDetect_Init(void)
{
    BTTx_ubTestCase        = 0;
    BTTx_uwTestStep        = 0;
    BTTx_swDelatPGPosition = 0;
    BTTx_uwPGPositionNow   = 0;
    BTTx_uwPGPositionOrg   = 0;
    BTTx_status.ub         = 0;
    BTTx_ulClearbttnCount  = 0;
    BTTx_ulTestCount       = 0;
}

//[JES Torq Detect Function, Special.Kung, 2022/09/01]
void TorqDetect_Function(void)
{        
	if(Error)
	{
		BTTx_ubTestCase= BTT_ErrorHandle;
    }
    else if(WarnCode==PID_WARN || (WarnCode>=PGFBK_WARN && WarnCode<=PHL_WARN) || WarnCode==oSL_WARN || WarnCode==tUn_WARN)
    {
		BTTx_ubTestCase= BTT_ErrorHandle;
    }

    if(pr[BTTx_Test]==1)
    {
        BTTx_btTorqDetect = 1;
        BTTx_btPr0732Flag = 1;
    }
    else
    {
        BTTx_btTorqDetect = 0;
    }

    switch(BTTx_ubTestCase)
    {
        case BTT_Standby:
            if((BTTx_btTorqDetect) && (CMDRUN==STOP))
        	{
                MFO_btTorqDetect       = 0;
        	    BTTx_ulTestCount       = 0;
                BTTx_ulClearbttnCount  = 0;
                BTTx_uwTestStep        = 0;
                BTTx_swDelatPGPosition = 0;
                BTTx_uwPGPositionNow   = 0;
                BTTx_uwPGPositionOrg   = 0;
                
                BTTx_ubTestCase = BTT_StartTest;
        	}
            else if((MFI_btTorqDetect) && (!BTTx_ubTorqDetectRst) && (CMDRUN==STOP))
            {
                MFO_btTorqDetect       = 0;
        	    BTTx_ulTestCount       = 0;
                BTTx_ulClearbttnCount  = 0;
                BTTx_uwTestStep        = 0;
                BTTx_swDelatPGPosition = 0;
                BTTx_uwPGPositionNow   = 0;
                BTTx_uwPGPositionOrg   = 0;
                
                BTTx_ubTestCase = BTT_StartTest;
        	}
            else
            {
                BTTx_ubTestCase = BTT_Standby;
            }            
            break;
        case BTT_StartTest:
            if(CMDRUN==RUN)
            {
                BTTx_uwPGPositionOrg = MTU1.TCNT;   //PG initial position
                BTTx_ubTorqDetectRst = 1;           //for MI57 reset
                BTTx_btFWDREVReset   = 1;
                BTTx_uwTestStep      = 1;
                BTTx_uwFMI0Temp      = pr[FMI0];    //before testing Pr[04-00] value
                
                BTTx_ubTestCase = BTT_Testing;
            }
            else if((BTTx_btPr0732Flag) && (!BTTx_btTorqDetect)) 
            {
                BTTx_ubTestCase = BTT_StopTest;
            }
            else if((!BTTx_btPr0732Flag) && (!MFI_btTorqDetect)) 
            {
                BTTx_ubTestCase = BTT_StopTest;
            }
            else
            {
                BTTx_ubTestCase = BTT_StartTest;
            }
            break;
        case BTT_Testing:
            if(BTTx_ulTestCount<(pr[BTTx_TestTime]*100))
            {
                WarnCode = BTT1_WARN;   //BTTx Testing    bttA

                BTTx_uwTestTorq = (10+BTTx_uwTestStep)*10;
                pr[BTTx_TestTorq] = BTTx_uwTestTorq;

                //JES no set MI speed so EDS set Pr[04-00]=Pr[01-00]*0.15 at BTT testing
                pr[FMI0] = pr[FMAX]*0.15;
			}
            else
            {
                BTTx_uwTestStep = BTTx_uwTestStep+1;
                BTTx_swDelatPGPosition = 0;
				BTTx_ulTestCount = 0;
            }
             
            /*  pr[BTTx_MaxTorq]is dot2 so must /10 
                Ex: 
                pr[BTTx_MaxTorq]=200/10=20-10=10 
                BTTx_uwTestStep+1 to 11 
                Torq test step is exactly 10 times
            */
            
            if(BTTx_uwTestStep>(pr[BTTx_MaxTorq]/10)-10)
            {
                BTTx_ubTestCase = BTT_StopTest;
            }
            else
            {
                BTTx_uwPGPositionNow = MTU1.TCNT;
                BTTx_swDelatPGPosition =abs((SWORD)(BTTx_uwPGPositionNow - BTTx_uwPGPositionOrg));
                
                /*
                if moving angle=5, so 1024*(5/360)=14.2=15 plus
                When Pr[10-01]=1024, and APR_uwPGPosition=4095
                Actually pr[BTTx_TestDist]*4=60 pluse
                */
                if(BTTx_swDelatPGPosition>(pr[BTTx_TestDist]*4))
                {
                    BTTx_ubTestCase = BTT_StopTest;
                }
                else
                {
                    BTTx_ubTestCase = BTT_Testing;
                }
            
                if(CMDRUN==STOP)
                {
                    //BTTx Error      bttE
                    Error = BTT2_ERR;
                    BTTx_ubTestCase = BTT_StopTest;
                }
                else if((BTTx_btPr0732Flag) && (!BTTx_btTorqDetect))
                {
                    //BTTx Error      bttE
                    Error = BTT2_ERR;
                    BTTx_ubTestCase = BTT_StopTest;
                }
                else if((!BTTx_btPr0732Flag) && (!MFI_btTorqDetect))
                {
                    //BTTx Error      bttE
                    Error = BTT2_ERR;
                    BTTx_ubTestCase = BTT_StopTest;
                }
            }
            break;
        case BTT_StopTest:
            stop();
            if(BTTx_ubTorqDetectRst)
            {
                if(WarnCode==BTT1_WARN)
                {
                    WarnCode = 0;
                }
                
                BTTx_btTorqDetect = 0;
                BTTx_btPr0732Flag = 0;
                MFI_btTorqDetect = 0;
        		MFO_btTorqDetect = 1;
            }
            else
            {
                BTTx_btTorqDetect = 0;
                BTTx_btPr0732Flag = 0;
                MFI_btTorqDetect = 0;
            }
            BTTx_ubTestCase = BTT_ErrorHandle;

            break;
        case BTT_ErrorHandle:

            if(BTTx_uwTestStep)
            {                
                pr[BTTx_Test] = 0;
                updatepr(BTTx_Test,0);

                pr[FMI0] = BTTx_uwFMI0Temp;
                updatepr(FMI0,BTTx_uwFMI0Temp);

                BTTx_uwTestTorq = (10+BTTx_uwTestStep-1)*10;
                pr[BTTx_TestTorq] = BTTx_uwTestTorq;
                write_ep(0,BTTx_TestTorq,pr[BTTx_TestTorq]);
            }

            if(MFO_btTorqDetect)
            {
                if((pr[BTTx_TestTorq])<(pr[BTTx_MinTorq]))
                {
                    //BTTx Fail       btt
                    Error = BTT1_ERR;
                    BTTx_ubTestCase = BTT_ErrorHandle;
                }
                else if((pr[BTTx_TestTorq])>=(pr[BTTx_MaxTorq]))
                {
                    //BTTx Success    bttS
                    WarnCode = BTT3_WARN;
                    BTTx_ubTestCase = BTT_ErrorHandle;
                }
                else
                {
                    //BTTx Normal     bttn
                    WarnCode = BTT2_WARN;
                    BTTx_ubTestCase = BTT_ErrorHandle;
                }
            }
            else
            {
                BTTx_ubTestCase = BTT_Standby;
            }

            if(WarnCode == BTT2_WARN)
            {
                if(BTTx_ulClearbttnCount>5000)
                {
                    WarnCode = 0;
                    BTTx_ubTestCase = BTT_Standby;
                }
                else
                {
                    BTTx_ubTestCase = BTT_ErrorHandle;
                }
            }
            else if(WarnCode == BTT3_WARN)
            {
                if(BTTx_ulClearbttnCount>5000)
                {
                    WarnCode = 0;
                    BTTx_ubTestCase = BTT_Standby;
                }
                else
                {
                    BTTx_ubTestCase = BTT_ErrorHandle;
                }
            }
            else
            {
                BTTx_ubTestCase = BTT_Standby;
            }
            break;
        
        default:
            BTTx_ubTestCase = BTT_Standby;
            break;
    }
}


#ifdef _Main_C
	#undef _Main_C
#endif
