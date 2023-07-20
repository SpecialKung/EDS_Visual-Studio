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
#ifndef _EstJ_C
	#define _EstJ_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
void Init_Estimate_J(void)
{	
	EsJ_ubKInt = 66; //Q17, 500us * 2^17 = 66
	EsJ_swTePu = 0;
	EsJ_slTeInt = 0;
	EsJ_slSpdtmpPu = 0;
	EsJ_ubCnt = 0;
	EsJ_ubsteady = 0;
}

void Estimate_J(void)
{
	SLONG EsJ_slSpdErr,slSpdErr1;
	
//    if (fcmd.uw.hi != 0){   
    if ((RUNDCI == 0)&&(STOPDCI == 0)){   
 #if 0
    	if (NORMALSP == 0){
    		EsJ_ubCnt = 1;
    		
    		if (TB1_slSpdCmdPu >= 0)
        		EsJ_slTeInt = EsJ_slTeInt + (SLONG)(EsJ_swTePu - (EsJ_slTLPu_FWD>>16)) * EsJ_ubKInt; //Q17
            else
        		EsJ_slTeInt = EsJ_slTeInt + (SLONG)(EsJ_swTePu - (EsJ_slTLPu_REV>>16)) * EsJ_ubKInt; //Q17
    
    		if (SPR_slSpdFdbPu != 0){
    			EsJ_slSpdErr = SPR_slSpdFdbPu-EsJ_slSpdtmpPu;
       			EsJ_swJPu_New = S32xS32divS32(EsJ_slTeInt, EsJ_uwKJGain, EsJ_slSpdErr) >> 4; //Q8
    		}
    		else
    			EsJ_swJPu_New = 256; //Q8, 1pu
    	}
    	else{
    		if (TB1_slSpdCmdPu >= 0)
        		EsJ_slTLPu_FWD = lowpass_sl((EsJ_uwLPG>>4), EsJ_swTePu, EsJ_slTLPu_FWD);
            else
        		EsJ_slTLPu_REV = lowpass_sl((EsJ_uwLPG>>4), EsJ_swTePu, EsJ_slTLPu_REV);
            
    		EsJ_slTeInt = 0;
    		EsJ_slSpdtmpPu = SPR_slSpdRefPu;
    
    		if ((EsJ_ubCnt == 1) && (EsJ_swJPu_New > 0)){
    			EsJ_ubCnt = 0;
    			
    			EsJ_slJPu = lowpass_sl(EsJ_uwLPG, EsJ_swJPu_New, EsJ_slJPu);
    		}
    	}
 #else
        if (NORMALSP == 0)    
            EsJ_ubsteady = 0;

        slSpdErr1 = (abs(TB1_slSpdCmdPu - SPR_slSpdFdbPu))>>16;
        if (slSpdErr1 < 20){
            EsJ_ubsteady ++;
            if (EsJ_ubsteady > 5)
                EsJ_ubsteady = 6;    
        }
                    
        if ((NORMALSP == 1) && (EsJ_ubsteady > 5)){
    		if (TB1_slSpdCmdPu >= 0)
        		EsJ_slTLPu_FWD = lowpass_sl((EsJ_uwLPG>>4), EsJ_swTePu, EsJ_slTLPu_FWD);
            else
        		EsJ_slTLPu_REV = lowpass_sl((EsJ_uwLPG>>4), EsJ_swTePu, EsJ_slTLPu_REV);
            
    		EsJ_slTeInt = 0;
    		EsJ_slSpdtmpPu = SPR_slSpdRefPu;
    
    		if ((EsJ_ubCnt == 1) && (EsJ_swJPu_New > 0)){
    			EsJ_ubCnt = 0;
    			
    			EsJ_slJPu = lowpass_sl(EsJ_uwLPG, EsJ_swJPu_New, EsJ_slJPu);
    		}         
        }
        else{
    		EsJ_ubCnt = 1;            
    		
    		if (TB1_slSpdCmdPu >= 0)
        		EsJ_slTeInt = EsJ_slTeInt + (SLONG)(EsJ_swTePu - (EsJ_slTLPu_FWD>>16)) * EsJ_ubKInt; //Q17
            else
        		EsJ_slTeInt = EsJ_slTeInt + (SLONG)(EsJ_swTePu - (EsJ_slTLPu_REV>>16)) * EsJ_ubKInt; //Q17
    
    		if (SPR_slSpdFdbPu != 0){
    			EsJ_slSpdErr = SPR_slSpdFdbPu-EsJ_slSpdtmpPu;
       			EsJ_swJPu_New = S32xS32divS32(EsJ_slTeInt, EsJ_uwKJGain, EsJ_slSpdErr) >> 4; //Q8
    		}
    		else
    			EsJ_swJPu_New = 256; //Q8, 1pu
        }
 #endif

	}
	else{
		EsJ_slTeInt = 0;
		EsJ_slSpdtmpPu = SPR_slSpdRefPu;    

  		if ((EsJ_ubCnt == 1) && (EsJ_swJPu_New > 0)){
   			EsJ_ubCnt = 0;
   			
   			EsJ_slJPu = lowpass_sl(EsJ_uwLPG, EsJ_swJPu_New, EsJ_slJPu);
   		}

    }

    pr[JmPu] = (EsJ_slJPu>>16);
}

#ifdef _EstJ_C
    #undef _EstJ_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
