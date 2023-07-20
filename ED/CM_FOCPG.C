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
#ifndef _CM_FOCPG_C
	#define _CM_FOCPG_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

//UWORD TB3_uwSpdLPG;
//SLONG TB3_slSpdLPPU;
void Init_FOCPG(void)
{
    Con_status.ub = 0;
    Init_CurrentMod();
    Init_CurrentReg();
    Init_SpeedReg();
    Init_TransferValue();
    Init_Flux();
    Init_TqCmd();

#if StandStill			//ADDED BY DINO
    TB2Cnt   = 0;
    PhaseCnt = 0;		// Initialize PhaseCnt, dino, 2006/11/14
#endif
    
    if (EXT_TqSpdEN == 0){
    	
#if SCOTTY				//ADDED BY SCOTTY
		if (pr[CTRLM] == FOCPG || pr[CTRLM] == FOCPM)
#else
        if (pr[CTRLM] == FOCPG)
#endif 

            TqSpdMode = 0; //Speed mode       
        else{
            TqSpdMode = 1;  //Toqure mode 
            TqSpd_flag = 1;	//Toqure mode
        }        
    }
    else{
        TqMode_first = 0;
        TB1_ModeSelect();
    }
    if ((pr[SysControl]&0x0002) == 2) //System Control bit1 = 1 (Estimate J)	pr[11-00]
    	Init_Estimate_J();

    if ((pr[CTRLSEL]&0x0010) == 16) //CTRLSEL bit4 = 1		pr[12-21]
        Init_TestSource();
	
    if (pr[NH_Deep] != 0)			//pr[11-13]
        Init_Notch();
    
    /*Torque init*/
        SPR_slIqseRefPu_LP = 0;
//    SpDt_slSpdFdbPu_LP = SpDt_slSpdFdbPu;

//	TB3_uwSpdLPG = pr[SPDLPBW1] * 206;
//	TB3_slSpdLPPU = 0;

}

void TB1_ModeSelect(void)
{
    if (EXT_TqSpd_flag == 0){
        TqSpdMode = 0;  //Speed mode
        TqMode_first = 0;
    }
    else{
        TqSpdMode = 1;  //Toqure mode 
        if (TqMode_first == 0){
            TqSpd_flag = 1;	//Toqure mode
            TqMode_first = 1;
        }
    }    
}

void TB1_FOCPG(void) //1ms
{
    if (EXT_TqSpdEN == 1)
        TB1_ModeSelect();
    
    TB1_SpeedReg();		//calculate speed loop kp/ki gain
	TB1_CurrentReg();	//calculate current loop kp/ki gain
	//Flux_Control();
    FLX_swFlxFreqPu = abs(CRM_slFlxFreqPu>>16);
    
//	Flux_FlxWkn();
	AsmDaxisSynCurRefHarness();
    
    TqLimt();
}

void TB3_FOCPG(void) //500us
{
    
    fout.ul = ((ULONG)COF_uwFbRe * abs(CRM_slFlxFreqPu>>15));

    SPR_slSpdFdbPu = SpDt_slSpdFdbPu;	
  	SPR_ulThetaFdb = SpDt_ulThetaR;

    if (TqSpdMode == 0){ //Speed control
        SPR_slSpdRefPu = TB1_slSpdCmdPu;
       	SpeedReg();		//obtain current command

        if ((pr[NH_Deep] != 0) && (NORMALSP == 1)){
            SPR_swIqseRefPu = Notch(SPR_swIqseRefPu, Nh_swWn, Nh_swDampZ);
        }
            
        if ((pr[SysControl]&0x0002) == 2){ //System Control bit1 = 1 (Estimate J)
        	EsJ_swTePu = SPR_swTqRefPu;
    	    Estimate_J();
        }

        CUR_swIqseRefPu = SPR_swIqseRefPu;
        
        if (EXT_TqSpdEN == 1)
            TB3_TqCmd();

    }
    else{               //Toqure control
    	TB3_TqCmd();
        if (TqC_swIqseRefPu >= 0)
    		SPR_slSpdRefPu = TqC_swPSpdLimPu<<16;
        else        
    		SPR_slSpdRefPu = TqC_swNSpdLimPu<<16;
       	SpeedReg();

        if (TqSpd_flag == 1){ // Toqure mode
       	    if ((TqC_swIqseRefPu >= 0) && (SpDt_slSpdFdbPu>>16) > TqC_swPSpdLimPu){
    	    	CUR_swIqseRefPu = SPR_swIqseRefPu;
    		    TqSpd_flag = 0; //Speed mode
        	}
            else if ((TqC_swIqseRefPu < 0) && ((SpDt_slSpdFdbPu>>16) < TqC_swNSpdLimPu)){        
        	    CUR_swIqseRefPu = SPR_swIqseRefPu;
    	    	TqSpd_flag = 0; //Speed mode
        	}
            else{
        	    CUR_swIqseRefPu = TqC_swIqseRefPu;
    	    	TqSpd_flag = 1; //Toqure mode        
            }	        	
        }
    
    	if (TqSpd_flag == 0){ // Speed mode
            SPR_slIqseRefPu_LP = lowpass_sl(1022, SPR_swIqseRefPu, SPR_slIqseRefPu_LP);
    
    		if (TqC_swIqseRefPu >= 0){
    		    if (TqC_swIqseRefPu < (SPR_slIqseRefPu_LP>>16)){
    			    CUR_swIqseRefPu = TqC_swIqseRefPu;
        			TqSpd_flag = 1; //Toqure mode
    		    }
                else{
                  	CUR_swIqseRefPu = SPR_swIqseRefPu;
        		}        		
    		}
    		else{
    		    if (TqC_swIqseRefPu > (SPR_slIqseRefPu_LP>>16)){
    			    CUR_swIqseRefPu = TqC_swIqseRefPu;
        			TqSpd_flag = 1; //Toqure mode
    		    }
                else{
                  	CUR_swIqseRefPu = SPR_swIqseRefPu;
    		    }                  
            }
    	}	    
    }
    

    SPR_swTqRefPu = (CUR_swIqseRefPu * COF_uwKt) >> 11; //Q12 = Q(15+8-11)
	TorqueOut = (SPR_swTqRefPu * COF_uwTbRe) >> 12;

}

void TB2_FOCPG(void) //100us
{
    SWORD swVrefSqu;
    ULONG ulVoutSqu;
    UWORD uwULimit;
/*
    if ((pr[CTRLSEL]&0x0010) == 16) //CTRLSEL bit4 = 1
        TB2_TestSource();
*/
	CRM_swIdPu = FLX_swIdseRefPu;
    CRM_swIqPu = CUR_swIqseRefPu;
    CRM_slSpdPu = SpDt_slSpdFdbPu; //Q31 TB3_SpDtPG1:obtaun 	SpDt_slSpdFdbPu 目的與滑差頻率後得到的頻率為電氣頻率-此頻率供弱磁控制使用。

	if (SpDt_uwPGErrTmp==0){
		CRM_ulThetaR = SpDt_ulThetaR;
	}
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
//   	FFD_swIqsePu = TsE_swIqseOutPu;
//   	FFD_swIdsePu = TsE_swIdseOutPu;
    FFD_swIqsePu = CUR_swIqseRefPu;
    FFD_swIdsePu = CUR_swIdseRefPu;
#if DINO
    FFD_swImPu = CRM_ImPuLPF.sw.hi;
#else
    FFD_swImPu = (CRM_slImPu >> 16);
#endif
	FFD_slFlxFreqPu = CRM_slFlxFreqPu;
	FFD_voDecpl();

//-DINO 2008/02/20
	if ( EPS )
		uwULimit = COF_uwVEPSPu;
	else
		uwULimit = 0x7FFF;
//-END 2008/02/20 

   	//TeS_swUdseInPu = sl_limit(CUR_swUdseOutPu, FFD_swUdseOutPu, uwULimit); 
	TeS_swUdseInPu = sl_limit_modify(CUR_swUdseOutPu, FFD_swUdseOutPu, uwULimit); //[Voltage saturate, Howard, 2018/10/23]

   	//TeS_swUqseInPu = sl_limit(CUR_swUqseOutPu, FFD_swUqseOutPu, uwULimit);	
	TeS_swUqseInPu = sl_limit_modify(CUR_swUqseOutPu, FFD_swUqseOutPu, uwULimit);//[Voltage saturate, Howard, 2018/10/23]

#if 0
	//Ud^2+Uq^2 > Urate_max^2 = 32767^2 = 2^30
	ulVoutSqu = ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu) + ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu);

    if (ulVoutSqu >= 0x3FFFFFFF)
        ulVoutSqu = 0x3FFFFFFF;
#else
	//Ud^2+Uq^2 > Urate_max^2 = 32767^2 = 2^30
	ulVoutSqu =sl_limit_modify( ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu), ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu), 0x3FFFFFFF); //[Voltage saturate, Howard, 2018/10/23]
#endif
   	swVrefSqu = (((SLONG)FLX_swVsMaxPu*FLX_swVsMaxPu) >> 16) - 128; //1V/255V*32768 = 128

	if ((ulVoutSqu>>16) >= swVrefSqu)
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
    
    if (ulVoutSqu >= 0x3FFFFFFF)
        FLX_swVoutPu = 32767;
    else
        FLX_swVoutPu = uw_Sqrt32c_1(ulVoutSqu); //Q15   
    
}


#ifdef _CM_FOCPG_C
    #undef _CM_FOCPG_C
#endif

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
