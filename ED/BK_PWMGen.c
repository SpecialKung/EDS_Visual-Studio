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
#ifndef _PWMGen_C
	#define _PWMGen_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void ZeroPWM(void)
{
    PWM_swTaInPu = 1;
    PWM_swTbInPu = 1;
    PWM_swTcInPu = 1;
    PWM_GEN();    
}

void UabcPu2Duty(void)
{
	SWORD Duty_swTa,Duty_swTb,Duty_swTc;
	UWORD Duty_uwTasInPu, Duty_uwTbsInPu, Duty_uwTcsInPu;
//	UWORD Ku4Uout;
	ULONG Ku4Uout2;
	ULONG_UNION VbRe;

	update_experiod = experiod;
    //where Ku4Uout = Vb/(vdc/2) = 2*Vb/Vdc 
    // [ Modify the calculation of Ku4Uout2, Debug by DINO, 06/24/2009
	VbRe.uw.hi  = COF_uwVbRe;
	VbRe.uw.low = 0;
    if (AVREN==1){
		Ku4Uout2 = VbRe.ul / dcbusDC;//DcbusDCLPF.sw.hi;//dcbusDC;
//		Ku4Uout2 = U16xU16divU16(COF_uwVbRe, 65535, dcbusDC); //Q15
//		Ku4Uout2 = (ULONG)COF_uwVbRe * 65535 / dcbusDC;
    }
    else{
		Ku4Uout2 = VbRe.ul / dcbusDCInit;
//		Ku4Uout2 = U16xU16divU16(COF_uwVbRe, 65535, dcbusDCInit); //Q15
//		Ku4Uout2 = (ULONG)COF_uwVbRe * 65535 / dcbusDCInit;
    }
    // ]

/*
    Duty_swTa = U16xS16shlr16(Ku4Uout, Duty_swTasInPu, 65535); //Q(15+15-16)=Q14
    Duty_swTb = U16xS16shlr16(Ku4Uout, Duty_swTbsInPu, 65535); //Q(15+15-16)=Q14
    Duty_swTc = U16xS16shlr16(Ku4Uout, Duty_swTcsInPu, 65535); //Q(15+15-16)=Q14
*/

//-DINO 2008/02/18
	if ( Duty_swTasInPu < 0 ){ Duty_uwTasInPu = -Duty_swTasInPu; }    else { Duty_uwTasInPu = Duty_swTasInPu; }
	if ( Duty_swTbsInPu < 0 ){ Duty_uwTbsInPu = -Duty_swTbsInPu; }    else { Duty_uwTbsInPu = Duty_swTbsInPu; }
	if ( Duty_swTcsInPu < 0 ){ Duty_uwTcsInPu = -Duty_swTcsInPu; }    else { Duty_uwTcsInPu = Duty_swTcsInPu; }
#if 0
    Duty_swTa = U32divU16((Ku4Uout2*Duty_uwTasInPu), 65535); //Q(15+15-16)=Q14
    Duty_swTb = U32divU16((Ku4Uout2*Duty_uwTbsInPu), 65535); //Q(15+15-16)=Q14
    Duty_swTc = U32divU16((Ku4Uout2*Duty_uwTcsInPu), 65535); //Q(15+15-16)=Q14
#else
    Duty_swTa = Ku4Uout2 * Duty_uwTasInPu >> 16; //Q(15+15-16)=Q14
    Duty_swTb = Ku4Uout2 * Duty_uwTbsInPu >> 16; //Q(15+15-16)=Q14
    Duty_swTc = Ku4Uout2 * Duty_uwTcsInPu >> 16; //Q(15+15-16)=Q14
#endif
	if ( Duty_swTasInPu < 0 ){ Duty_swTa = -Duty_swTa; }
	if ( Duty_swTbsInPu < 0 ){ Duty_swTb = -Duty_swTb; }
	if ( Duty_swTcsInPu < 0 ){ Duty_swTc = -Duty_swTc; }
//-END 2008/02/18

    PWM_swTaInPu = S32xS16shlr16((SLONG)(16384 - Duty_swTa), ((SLONG)update_experiod)<<1); //Q0 = Q((14+1)+1-16)
    PWM_swTbInPu = S32xS16shlr16((SLONG)(16384 - Duty_swTb), ((SLONG)update_experiod)<<1); //Q0 = Q((14+1)+1-16)
    PWM_swTcInPu = S32xS16shlr16((SLONG)(16384 - Duty_swTc), ((SLONG)update_experiod)<<1); //Q0 = Q((14+1)+1-16)
      
    PWM_GEN();
    
}


void PWM_GEN(void)
{
    SWORD TH;
    SWORD Tmax, Tmin, Tz, swUcom;
    UWORD ua, ub, uc, ut;	
	

	/*
	  Equation: Th = Tz - uTz + uTM - uTm - TM
	  u = 0.5, SVPWM
	  u = 1 or 0, Discontinue PWM
	*/
//- ADDED BY SCOTTY  2007/07/11

#if SCOTTY    
    uw_UPdeadtime = (UWORD)((pr[MINI_PULSE]<<1));
	uw_LOWdeadtime = (UWORD)(DeadTime + (pr[MINI_PULSE]<<1));
#endif 
//-END 2007/07/11

	Tz = update_experiod >> 1; // helf experiod
	
	if (PWM_swTaInPu > PWM_swTbInPu){
	    if (PWM_swTaInPu > PWM_swTcInPu){
	    	//(Ta > Tb) & (Ta > Tc)
            Tmax = PWM_swTaInPu;
            if (PWM_swTbInPu > PWM_swTcInPu)
                //Ta > Tb > Tc, In section 1
                Tmin = PWM_swTcInPu;
            else
                //Ta > Tc >= Tb, In section 2
                Tmin = PWM_swTbInPu;
		}
		else{
		    //Tc >= Ta > Tb, In section 3
            Tmax = PWM_swTcInPu;
		    Tmin = PWM_swTbInPu;
		}
	}
    else{
        if (PWM_swTaInPu > PWM_swTcInPu){
        	//Tb >= Ta > Tc, In section 6
      	    Tmax = PWM_swTbInPu;
        	Tmin = PWM_swTcInPu;
        }
        else{
            //Ta <= Tc & Ta <= Tb
            Tmin = PWM_swTaInPu;
            if (PWM_swTbInPu > PWM_swTcInPu)
                //Tb > Tc >= Ta, In section 5
                Tmax = PWM_swTbInPu;
            else
                //Tc >= Tb >= Ta, In section 4
                Tmax = PWM_swTcInPu;
        }
    }

    //======== A Phase ========//    
    if (PWM_swTaInPu > Tz)
        ua = 1;
    else
        ua = 0;

    if (PWM_swTbInPu > Tz)
        ub = 1;
    else
        ub = 0;

    if (PWM_swTcInPu > Tz)
        uc = 1;
    else
        uc = 0;
    
    if (WGMODE==1){
        if ((ua+ub+uc)==2)
            ut = 2;
        else
            ut = 0;
    }
    else
        ut = 1;

    if ((pr[AUTO_T]!=0 || pr[PM_AUTO_T]!=0) && pr[PM_AUTO_T]!=3) {  // Modify by DINO, 08/13/2008
        if (TUN_ROLLING==1)
            TH = (SWORD)((update_experiod*(2 - ut))+(ut*(Tmax - Tmin))-(Tmax * 2))>>1;
        else
            TH = 0;
    }
    else{
        if (WGMODE==0 && pr[PWM_MODE]==3)
            TH = 0;
        else    
            TH = (SWORD)((update_experiod*(2 - ut))+(ut*(Tmax - Tmin))-(Tmax * 2))>>1;
    }

    PWM_swTaOut = PWM_swTaInPu + TH - UaDBC + DeadTime_2;
    PWM_swTbOut = PWM_swTbInPu + TH - UbDBC + DeadTime_2;
    PWM_swTcOut = PWM_swTcInPu + TH - UcDBC + DeadTime_2;

    if ((pr[DEBUG_F1]&0x2000)==0x2000){  // Bit 13: PWM skip time by 12-11
        if (PWM_swTaOut > (update_experiod-pr[SKIP_DT])){
            PWM_swTaOut = update_experiod+(DeadTime);
        }    
        else if (PWM_swTaOut < (DeadTime+pr[SKIP_DT])){
            PWM_swTaOut = 0;
        }    
    
        if (PWM_swTbOut > (update_experiod-pr[SKIP_DT])){
            PWM_swTbOut = update_experiod+(DeadTime);
        }    
        else if (PWM_swTbOut < (DeadTime+pr[SKIP_DT])){
            PWM_swTbOut = 0;
        }    
    
        if (PWM_swTcOut > (update_experiod-pr[SKIP_DT])){
            PWM_swTcOut = update_experiod+(DeadTime);
        }    
        else if (PWM_swTcOut < (DeadTime+pr[SKIP_DT])){
            PWM_swTcOut = 0;
        }
    }
    else{
	    if ((pr[DEBUG_F1]&0x4000)==0x0000){  // Bit 14: PWM skip 2us 
	        if (PWM_swTaOut > (update_experiod - uw_UPdeadtime)){
	            PWM_swTaOut = update_experiod + (DeadTime);
	        }    
	        else if (PWM_swTaOut < uw_LOWdeadtime){
	            PWM_swTaOut = 0;
	        }    
	    
	        if (PWM_swTbOut > (update_experiod - uw_UPdeadtime)){
	            PWM_swTbOut = update_experiod + (DeadTime);
	        }    
	        else if (PWM_swTbOut < uw_LOWdeadtime){
	            PWM_swTbOut = 0;
	        }    
	    
	        if (PWM_swTcOut > (update_experiod - uw_UPdeadtime)){
	            PWM_swTcOut = update_experiod + (DeadTime);
	        }    
	        else if (PWM_swTcOut < uw_LOWdeadtime){
	            PWM_swTcOut = 0;
	        }
	    }
	    else{
			// [ Correct the minimun pulse function by DINO, 01/21/2009
	        if (PWM_swTaOut > (update_experiod - uw_UPdeadtime)){
	            swUcom = update_experiod + DeadTime - PWM_swTaOut;
	            PWM_swTaOut = update_experiod + (DeadTime);
	        }    
	        else if (PWM_swTaOut < uw_LOWdeadtime){
	            swUcom = -PWM_swTaOut;
	            PWM_swTaOut = 0;
	        }
	        else{
	        	swUcom = 0;
	        }
	   		PWM_swTbOut += swUcom;
	   		PWM_swTcOut += swUcom;

	        if (PWM_swTbOut > (update_experiod - uw_UPdeadtime)){
	            swUcom = update_experiod + DeadTime - PWM_swTbOut;
	            PWM_swTbOut = update_experiod + (DeadTime);
	        }    
	        else if (PWM_swTbOut < uw_LOWdeadtime){
	            swUcom = -PWM_swTbOut;
	            PWM_swTbOut = 0;
	        }    
	        else{
	        	swUcom = 0;
	        }
	   		PWM_swTcOut += swUcom;
	   		PWM_swTaOut += swUcom;
	    
	        if (PWM_swTcOut > (update_experiod - uw_UPdeadtime)){
	            swUcom = update_experiod + DeadTime - PWM_swTcOut;
	            PWM_swTcOut = update_experiod + (DeadTime);
	        }    
	        else if (PWM_swTcOut < uw_LOWdeadtime){
	            swUcom = -PWM_swTcOut;
	            PWM_swTcOut = 0;
	        }
	        else{
	        	swUcom = 0;
	        }
	   		PWM_swTaOut += swUcom;
	   		PWM_swTbOut += swUcom;
	   		// End on 01/21/2009 ]
/*	        if (PWM_swTaOut > (update_experiod)){
	            PWM_swTaOut = update_experiod+(DeadTime);
	        }    
	        else if (PWM_swTaOut < DeadTime){
	            PWM_swTaOut = 0;
	        }    
	    
	        if (PWM_swTbOut > (update_experiod)){
	            PWM_swTbOut = update_experiod+(DeadTime);
	        }    
	        else if (PWM_swTbOut < DeadTime){
	                PWM_swTbOut = 0;
	        }
	     
	        if (PWM_swTcOut > (update_experiod)){
	            PWM_swTcOut = update_experiod+(DeadTime);
	        }    
	        else if (PWM_swTcOut < DeadTime){
	            PWM_swTcOut = 0;
	        }
*/
	    }
	}

	PWM_swTabOut = PWM_swTaOut - PWM_swTbOut;
	PWM_swTbcOut = PWM_swTbOut - PWM_swTcOut;
	PWM_swTcaOut = PWM_swTcOut - PWM_swTaOut;

	DINT();
	experiod_Buf = update_experiod;
	PWM_swTaOut_Buf = PWM_swTaOut;
    PWM_swTbOut_Buf = PWM_swTbOut;    
    PWM_swTcOut_Buf = PWM_swTcOut;
	EINT();
}


#ifdef _PWMGen_C
    #undef _PWMGen_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/

