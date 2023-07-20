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
#ifndef _CM_TQCPG_C
	#define _CM_TQCPG_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_TQCPG(void)
{
/*
    Con_status.ub = 0;
    TqSpd_flag = 1;	//Toqure mode
    SPR_slIqseRefPu_LP = 0;
    SpDt_slSpdFdbPu_LP = SpDt_slSpdFdbPu;
    Init_CurrentMod();
    Init_CurrentReg();
    Init_SpeedReg();
//    Init_SpDtPG1();
    Init_TqCmd();
    Init_TransferValue();
    Init_Flux();
//	Init_TestSource();

    swUdseLimPu = 0x7FFF;
    swUqseLimPu = 0x7FFF;
*/
}

void TB1_TQCPG(void) //1ms
{
/*
    TB1_SpeedReg();
	TB1_CurrentReg();
	//Flux_Control();
    FLX_swFlxFreqPu = abs(CRM_slFlxFreqPu>>16);
    Flux_FlxWkn();

}

void TB3_TQCPG(void) //500us
{
    fout.ul = ((ULONG)COF_uwFbRe * abs(CRM_slFlxFreqPu>>15));
    
	TB3_TqCmd();

    SPR_slSpdFdbPu = SpDt_slSpdFdbPu;	
	SPR_ulThetaFdb = SpDt_ulThetaR;
	SpeedReg();

    SpDt_slSpdFdbPu_LP = lowpass_sl(511, (SpDt_slSpdFdbPu>>16), SpDt_slSpdFdbPu_LP);
    
    if (TqSpd_flag == 1){ // Toqure mode
       if ((SpDt_slSpdFdbPu>>16) >= TqC_swPSpdLimPu){        
	    	    CUR_swIqseRefPu = SPR_swIqseRefPu;
		        TqSpd_flag = 0; //Speed mode
    	    }
        else if ((SpDt_slSpdFdbPu>>16) <= TqC_swNSpdLimPu){        
    	    	CUR_swIqseRefPu = SPR_swIqseRefPu;
	    	    TqSpd_flag = 0; //Speed mode
    	    }
        else{
    	    CUR_swIqseRefPu = TqC_swIqseRefPu;
	    	TqSpd_flag = 1; //Speed mode        
        }	        	
    }

	if (TqSpd_flag == 0){ // Speed mode
    	CUR_swIqseRefPu = SPR_swIqseRefPu;
        SPR_slIqseRefPu_LP = lowpass_sl(511, SPR_swIqseRefPu, SPR_slIqseRefPu_LP);

		if (SpDt_slSpdFdbPu_LP >= 0){
		    if (TqC_swIqseRefPu < (SPR_slIqseRefPu_LP>>16)){
			    CUR_swIqseRefPu = TqC_swIqseRefPu;
    			TqSpd_flag = 1; //Toqure mode
		    }
		}
		else{
		    if (TqC_swIqseRefPu > (SPR_slIqseRefPu_LP>>16)){
			    CUR_swIqseRefPu = TqC_swIqseRefPu;
    			TqSpd_flag = 1; //Toqure mode
		    }
		}
	}	
*/
}

void TB2_TQCPG(void) //100us
{	
/*
    UBYTE DVolSat_flag,QVolSat_flag;
	SLONG Vout_tmp, VsquareTemp;
    SLONG slUdseInPu, slUqseInPu;

    TB2_SpeedReg();  

//	TB2_TestSource();	
//	CUR_swIqseRefPu = TS_swSoOutPu;
	
	CRM_swIdPu = FLX_swIdseRefPu;
	CRM_swIqPu = CUR_swIqseRefPu;
    CRM_slSpdPu = SpDt_slSpdFdbPu; //Q31	
	CRM_ulThetaR = SpDt_ulThetaR;
    CurrentMod_PG();
	
    T32_swIasInPu = AD_swIAPu;
    T32_swIbsInPu = AD_swIBPu;
    abc2dq();
    
    TsE_swIdssInPu = T32_swIdssOutPu;
    TsE_swIqssInPu = T32_swIqssOutPu;
    Stat2Syn_s2e();

    //-------- d - axis current regulator --------//
    CUR_swIdseRefPu = FLX_swIdseRefPu;
    CUR_swIdseFdbPu = TsE_swIdseOutPu;
    CurrentReg_daxis();    
    
    //-------- q - axis current regulator --------//
//  CUR_swIqseRefPu = SPR_swIqseRefPu;
    CUR_swIqseFdbPu = TsE_swIqseOutPu;
    CurrentReg_qaxis();    
       
    //-------- Feedforward decoupler ------------//
//	FFD_swIqsePu = TsE_swIqseOutPu;
	FFD_swIdsePu = TsE_swIdseOutPu;
	FFD_swIqsePu = CUR_swIqseRefPu;
//	FFD_swIdsePu = CUR_swIdseRefPu;
    FFD_swImPu = (CRM_slImPu >> 16);
	FFD_slFlxFreqPu = CRM_slFlxFreqPu;
	FFD_voDecpl();

 #if 0
	TeS_swUdseInPu = sl_limit(CUR_swUdseOutPu, FFD_swUdseOutPu, swUdseLimPu);
	TeS_swUqseInPu = sl_limit(CUR_swUqseOutPu, FFD_swUqseOutPu, swUqseLimPu);		

	//Ud^2+Uq^2 > Urate_max^2 = 32767^2 = 2^30
	Vout_tmp = (((SLONG)TeS_swUdseInPu*TeS_swUdseInPu) + ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu)) >> 16;
	
	VsquareTemp = (((SLONG)COF_uwVratePu*COF_uwVratePu) >> 16) - 128; //1V/255V*32768 = 128
	
	if(Vout_tmp >= VsquareTemp){
		VolSat_flag = 1;
	}
    else{
		VolSat_flag = 0;
	}

 #else
	slUdseInPu = (SLONG)CUR_swUdseOutPu + FFD_swUdseOutPu;
	slUqseInPu = (SLONG)CUR_swUqseOutPu + FFD_swUqseOutPu;		

    if (slUdseInPu >= 0x7FFF)
        FLX_swUdseInPu = 0x7FFF;
    else if (slUdseInPu <= -0x7FFF)
        FLX_swUdseInPu = -0x7FFF;
    else
        FLX_swUdseInPu = slUdseInPu;
            
    if (slUqseInPu >= 0x7FFF)
        FLX_swUqseInPu = 0x7FFF;
    else if (slUqseInPu <= -0x7FFF)
        FLX_swUqseInPu = -0x7FFF;
    else
        FLX_swUqseInPu = slUqseInPu;

//    FLX_ulVoutPu = ((SLONG)slUdseInPu*slUdseInPu) + ((SLONG)slUqseInPu*slUqseInPu); //Q30
    
    //D axis Limit
    if (slUdseInPu >= swUdseLimPu){
        TeS_swUdseInPu = swUdseLimPu;
      	DVolSat_flag = 1;
    }
    else if (slUdseInPu <= -swUdseLimPu){
        TeS_swUdseInPu = -swUdseLimPu;
      	DVolSat_flag = 1;
    }
    else{
        TeS_swUdseInPu = slUdseInPu;
      	DVolSat_flag = 0;
    }
    
    //Q axis Limit
    if (slUqseInPu >= swUqseLimPu){
        TeS_swUqseInPu = swUqseLimPu;
      	QVolSat_flag = 1;
    }
    else if (slUqseInPu <= -swUqseLimPu){
        TeS_swUqseInPu = -swUqseLimPu;
      	QVolSat_flag = 1;
    }
    else{
        TeS_swUqseInPu = slUqseInPu;
      	QVolSat_flag = 0;
    }
    
    VolSat_flag = DVolSat_flag | QVolSat_flag; 

 #endif

    Syn2Stat_e2s();
    
    T23_swUqssInPu = TeS_swUqssOutPu;
    T23_swUdssInPu = TeS_swUdssOutPu;
    dq2abc();
    
	Duty_swTasInPu = T23_swUasOutPu;
	Duty_swTbsInPu = T23_swUbsOutPu;
	Duty_swTcsInPu = T23_swUcsOutPu;
    UabcPu2Duty();   
*/     
}

#ifdef _CM_TQCPG_C
    #undef _CM_TQCPG_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
