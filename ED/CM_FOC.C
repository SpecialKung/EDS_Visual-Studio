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
#ifndef _CM_FOC_C
	#define _CM_FOC_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_FOC(void)
{
    Con_status.ub = 0;
    Init_CurrentMod();
    Init_CurrentReg();
    Init_SpeedReg();
//    Init_SpDtPG1();
    Init_TransferValue();

	Init_TestSource();

}

void TB1_FOC(void)
{
    fout.ul = ((ULONG)COF_uwFbRe * abs(CRM_slFlxFreqPu>>15));
    
    SPR_slSpdRefPu = TB1_slSpdCmdPu;
    SPR_slSpdFdbPu = SpDt_slSpdFdbPu;	
	SPR_ulThetaFdb = SpDt_ulThetaR;
	SpeedReg();
		
	//Flux_Control();
    FLX_swFlxFreqPu = CRM_slFlxFreqPu>>16;
    Flux_FlxWkn();
//	TB1_TestSource();
}


void TB2_FOC(void)
{
	SLONG Vout_tmp, VsquareTemp;
	
	TB2_SpDtPG1();
	
//	TB2_TestSource();	

	CRM_swIdPu = FLX_swIdseRefPu;
	CRM_swIqPu = SPR_swIqseRefPu;
	CRM_slSpdPu = SPR_slSpdFdbPu; //Q31
	CRM_ulThetaR = SpDt_ulThetaR;
    CurrentMod_noPG();

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
    CUR_swIqseRefPu = SPR_swIqseRefPu;
    CUR_swIqseFdbPu = TsE_swIqseOutPu;
    CurrentReg_qaxis();    
       
    //-------- Feedforward decoupler ------------//
	FFD_swIqsePu = SPR_swIqseRefPu; 
	FFD_swIdsePu = FLX_swIdseRefPu;
    FFD_swImPu = FLX_swIdseRefPu;
	FFD_slFlxFreqPu = CRM_slFlxFreqPu;
	FFD_voDecpl();

	if ((pr[CTRLSEL]&0x0001) == 0){ //CTRLSEL bit0 = 0
		TeS_swUdseInPu = sl_limit(CUR_swUdseOutPu, FFD_swUdseOutPu, COF_uwVratePu);
		TeS_swUqseInPu = sl_limit(CUR_swUqseOutPu, FFD_swUqseOutPu, COF_uwVratePu);					
	}	
	else{							//CTRLSEL bit0 = 1
        TeS_swUdseInPu = CUR_swUdseOutPu;
        TeS_swUqseInPu = CUR_swUqseOutPu;
	}
	//Ud^2+Uq^2 > Urate_max^2 = 32767^2 = 2^30
	Vout_tmp = ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu) + ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu);
	
	VsquareTemp = ((SLONG)COF_uwVratePu*COF_uwVratePu);
	if(Vout_tmp >= VsquareTemp)
		VolSat_flag = 1;
	else
		VolSat_flag = 0;
    Syn2Stat_e2s();
    
    T23_swUqssInPu = TeS_swUqssOutPu;
    T23_swUdssInPu = TeS_swUdssOutPu;
    dq2abc();
    
	Duty_swTasInPu = T23_swUasOutPu;
	Duty_swTbsInPu = T23_swUbsOutPu;
	Duty_swTcsInPu = T23_swUcsOutPu;
    UabcPu2Duty();    
    
}

#ifdef _CM_FOC_C
    #undef _CM_FOC_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
