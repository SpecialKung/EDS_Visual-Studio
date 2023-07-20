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
#ifndef _TqCmd_C
	#define _TqCmd_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_TqCmd(void)
{
	TqC_swIqseRefPu = 0;
	TqC_slTqCmdPuLPF = 0;
}
/*	removed by SCOTTY 02/01/2007
void TB1_TqCmd(void)
{

}
*/
void TB3_TqCmd(void)
{	
    SWORD swTemp,swTqRefLimPu;
	
	TqC_slTqCmdPuLPF = lowpass_sl(Tqc_uwTqCmdLPG, TqC_swTqSetPu, TqC_slTqCmdPuLPF);
	
	//IqsPu = (Te/Tb) / (LmPu*IdsPu)
	if (pr[TQROFSE]!=0)
	    swTemp = TqC_swTqOfstPu; //Q12
	else
	    swTemp = 0;

    swTqRefLimPu = ((ULONG)SPR_swIqseRefLimPu * COF_uwKt) >> 11; //Q12 = Q(15+8-11)

    swTemp = sl_limit((TqC_slTqCmdPuLPF>>16), swTemp, swTqRefLimPu); //Q12 = Q12 + Q12

	// iqs = 1/Kt * Te
	TqC_swIqseRefPu = S16xS16divS16(swTemp, 2048, COF_uwKt); //Q15 = Q(12+11-8)

 #if 0
    if (SpDt_slSpdFdbPu >= 0)
		SPR_slSpdRefPu = TqC_swPSpdLimPu<<16;
    else        
		SPR_slSpdRefPu = TqC_swNSpdLimPu<<16;
 #endif

}

void TqLimt(void)
{
	SWORD swPosTqLim,swNegTqLim,swRegTqLim,swPosNegTqLim;
    SLONG slTq_tmp;

    if (EXT_TqSpdEN == 0){ 
        if ((pr[AUI1_SL] == 7) || (pr[ACI_SL] == 7) || (pr[AUI2_SL] == 7)){
            if (pr[AUI1_SL] == 7)
                swPosTqLim = AVIslFunVar;
            else if (pr[ACI_SL] == 7)    
                swPosTqLim = ACIslFunVar;
            else
                swPosTqLim = AUIslFunVar;
        }
        else
            swPosTqLim = 0x7FFF;
        
        if ((pr[AUI1_SL] == 8) || (pr[ACI_SL] == 8) || (pr[AUI2_SL] == 8)){
            if (pr[AUI1_SL] == 8)
                swNegTqLim = AVIslFunVar;
            else if (pr[ACI_SL] == 8)    
                swNegTqLim = ACIslFunVar;
            else
                swNegTqLim = AUIslFunVar;
        }
        else
            swNegTqLim = 0x7FFF;
            
        if ((pr[AUI1_SL] == 9) || (pr[ACI_SL] == 9) || (pr[AUI2_SL] == 9)){
            if (pr[AUI1_SL] == 9)
                swRegTqLim = AVIslFunVar;
            else if (pr[ACI_SL] == 9)    
                swRegTqLim = ACIslFunVar;
            else
                swRegTqLim = AUIslFunVar;
        }
        else
            swRegTqLim = 0x7FFF;
            
        if ((pr[AUI1_SL] == 10) || (pr[ACI_SL] == 10) || (pr[AUI2_SL] == 10)){
            if (pr[AUI1_SL] == 10)
                swPosNegTqLim = AVIslFunVar;
            else if (pr[ACI_SL] == 10)    
                swPosNegTqLim = ACIslFunVar;
            else
                swPosNegTqLim = AUIslFunVar;
        }
        else
            swPosNegTqLim = 0x7FFF;
    
        if (swPosNegTqLim <= swPosTqLim)
            swPosTqLim = swPosNegTqLim;
    
        if (swPosNegTqLim <= swNegTqLim)
            swNegTqLim = swPosNegTqLim;
    
        /*------------FWD Motoring Tq Limit---------------------------------*/
		// [ Add PM Torque Calculation, DINO, 06/17/2009
		if (pr[CTRLM]==FOCPM){
			slTq_tmp = pr[FWDM_TQLIM] * 100;
		}
		else{
			slTq_tmp = ((SLONG)COF_uwTqratePu * pr[FWDM_TQLIM] )/100; //Q12
        	slTq_tmp = S32xS32divS32(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)   //[Overflow problem, Bernie, 2017/03/27]
        }
/*
		slTq_tmp = ((SLONG)COF_uwTqratePu * pr[FWDM_TQLIM] )/100; //Q12
        slTq_tmp = S16xS16divS16(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)
#if SCOTTY  // 05/10/2007
		if (pr[CTRLM]==FOCPM){						//ADDED BY SCOTTY 03/12/2007
			swPosTqLim = S16xS16divS16(10000, pr[FWDM_TQLIM], 100); 
    		slTq_tmp = SPR_swIqseRefLimPu; 
    	}
#endif 
*/
		// ]
        if (swPosTqLim < slTq_tmp)
            slTq_tmp = swPosTqLim;   //(swPosTqLim/swPosNegTqLim) < parameter
                
        if (slTq_tmp <= SPR_swIqseRefLimPu)  
            SPR_swIqseFWDMPu = slTq_tmp;
    	else
    		SPR_swIqseFWDMPu = SPR_swIqseRefLimPu;
    	/*------------------------------------------------------------------*/
        
        /*------------REV Motoring Tq Limit---------------------------------*/    
		// [ Add PM Torque Calculation, DINO, 06/17/2009
		if (pr[CTRLM]==FOCPM){
			slTq_tmp = pr[REVM_TQLIM] * 100;
		}
		else{
        	slTq_tmp = ((SLONG)COF_uwTqratePu * pr[REVM_TQLIM] )/100; //Q12
        	slTq_tmp = S32xS32divS32(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)  //[Overflow problem, Bernie, 2017/03/27]
        }
/*
        slTq_tmp = ((SLONG)COF_uwTqratePu * pr[REVM_TQLIM] )/100; //Q12
        slTq_tmp = S16xS16divS16(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)
#if SCOTTY // 05/10/2007
		if (pr[CTRLM]==FOCPM){					//ADDED BY SCOTTY 03/12/2007
			swNegTqLim = S16xS16divS16(10000, pr[REVM_TQLIM], 100); 
    		slTq_tmp = SPR_swIqseRefLimPu; 
    	}
#endif         
*/
        if (swNegTqLim < slTq_tmp)
            slTq_tmp = swNegTqLim;   //(swNegTqLim/swPosNegTqLim) < parameter
    
        if (slTq_tmp <= SPR_swIqseRefLimPu)  
            SPR_swIqseREVMPu = slTq_tmp;
    	else
    		SPR_swIqseREVMPu = SPR_swIqseRefLimPu;
    	/*------------------------------------------------------------------*/
    	
        /*------------FWD Regeneration Tq Limit-----------------------------*/     
		// [ Add PM Torque Calculation, DINO, 06/17/2009
		if (pr[CTRLM]==FOCPM){
			slTq_tmp = pr[FWDR_TQLIM] * 100;
		}
		else{
			slTq_tmp = ((SLONG)COF_uwTqratePu * pr[FWDR_TQLIM] )/100; //Q12
			slTq_tmp = S32xS32divS32(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)  //[Overflow problem, Bernie, 2017/03/27]
        }
/*
        slTq_tmp = ((SLONG)COF_uwTqratePu * pr[FWDR_TQLIM] )/100; //Q12
        slTq_tmp = S16xS16divS16(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)
#if SCOTTY // 05/10/2007
		if (pr[CTRLM]==FOCPM){					//ADDED BY SCOTTY 03/12/2007
			swRegTqLim = S16xS16divS16(10000, pr[FWDR_TQLIM], 100); 
    		slTq_tmp = SPR_swIqseRefLimPu; 
    	}   
#endif 
*/
        if (swRegTqLim < swNegTqLim)
            swNegTqLim = swRegTqLim;
        
        if (swNegTqLim < slTq_tmp) // AD value < parameter
            slTq_tmp = swNegTqLim;       
            
        if (slTq_tmp <= SPR_swIqseRefLimPu)  
            SPR_swIqseFWDRPu = slTq_tmp;
    	else
    		SPR_swIqseFWDRPu = SPR_swIqseRefLimPu;
    	/*------------------------------------------------------------------*/
    
        /*------------REV Regeneration Tq Limit-----------------------------*/     
		// [ Add PM Torque Calculation, DINO, 06/17/2009
		if (pr[CTRLM]==FOCPM){
			slTq_tmp = pr[REVR_TQLIM] * 100;
		}
		else{
			slTq_tmp = ((SLONG)COF_uwTqratePu * pr[REVR_TQLIM] )/100; //Q12
			slTq_tmp = S32xS32divS32(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)   //[Overflow problem, Bernie, 2017/03/27]
        }
/*
        slTq_tmp = ((SLONG)COF_uwTqratePu * pr[REVR_TQLIM] )/100; //Q12
        slTq_tmp = S16xS16divS16(slTq_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)
#if SCOTTY // 05/10/2007
		if (pr[CTRLM]==FOCPM){					//ADDED BY SCOTTY 03/12/2007
			swRegTqLim = S16xS16divS16(10000, pr[REVR_TQLIM], 100); 
    		slTq_tmp = SPR_swIqseRefLimPu; 
    	} 
#endif 
*/
        if (swRegTqLim < swPosTqLim)
            swPosTqLim = swRegTqLim;
        
        if (swPosTqLim < slTq_tmp) // AD value < parameter
            slTq_tmp = swPosTqLim;       
    
        if (slTq_tmp <= SPR_swIqseRefLimPu)  
    		SPR_swIqseREVRPu = slTq_tmp;
    	else
            SPR_swIqseREVRPu = SPR_swIqseRefLimPu;
    	/*-------------------------------------------------------------------*/
    }
    else{
        swPosTqLim = abs(TqC_swIqseRefPu);
   		SPR_swIqseFWDMPu = swPosTqLim;
   		SPR_swIqseREVMPu = swPosTqLim;
   		SPR_swIqseFWDRPu = swPosTqLim;
        SPR_swIqseREVRPu = swPosTqLim;        
    }
}

#ifdef _TqCmd_C
    #undef _TqCmd_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
