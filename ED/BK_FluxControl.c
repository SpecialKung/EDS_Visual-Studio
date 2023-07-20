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
#ifndef _FluxControl_C
	#define _FluxControl_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_Flux(void)
{
    FLX_swIdseRefPu = COF_uwI0Pu;
    FLX_IdRefPuLPF.sl = COF_uwI0Pu << 16;

    FLX_slWslErrKi = 0;
    FLX_slVsErrKi = 0;    
    
    FLX_uwWslMaxPu = (COF_uwLmPu << 2) + (COF_uwLxPu >> 2); //Q8,Q8=Q(6+2)+Q(10-2)
    FLX_uwWslMaxPu = U16xU16divU16(COF_Tr_inv, (FLX_uwWslMaxPu>>3), (COF_uwLxPu<<2)); //Q15,Q(22+8-3-10-2)
    FLX_uwWslMaxPu = (FLX_uwWslMaxPu * pr[SpdFFD]) / 100;

}

/*************************************************************** 
 Function: Flux_FlxWkn;
 Description: high speed flux control
 Call by: functions in TB1;
 Subroutine Call: N/A;
 Reference: N/A
****************************************************************/
void Flux_FlxWkn(void)
{   
    SWORD swIdsRef_tmp,swVsErrPu,swVsErrKp;
    SWORD swTqRefPuTmp,swTqLow,swTqHigh;
	ULONG ulIqLim_tmp;
	SLONG slIdRef_tmp;

/* Disable Flied Weakness, DINO, 12/30/2008	  	  
    if (FLX_swFlxFreqPu >= (COF_uwFRatePu+(COF_ulFslipRatePu>>16))){
        swIdsRef_tmp = U16xU16divU16(COF_uwI0Pu, COF_uwFRatePu, (abs(SpDt_slSpdFdbPu>>16)));
        if (pr[YDSWEN] == 0){
            if((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2))	//motor 2 highest priority
            	swIdsRef_tmp = ((SLONG)swIdsRef_tmp * pr[M2_IdsRefLim]) / 100;                
            else
                swIdsRef_tmp = ((SLONG)swIdsRef_tmp * pr[M1_IdsRefLim]) / 100;
        }
        else{
            if (YDConnectFlag == 0)
                swIdsRef_tmp = ((SLONG)swIdsRef_tmp * pr[M1_IdsRefLim]) / 100;
            else
                swIdsRef_tmp = ((SLONG)swIdsRef_tmp * pr[M2_IdsRefLim]) / 100;            
        }
    }
    else{  */
        swIdsRef_tmp = COF_uwI0Pu; //Q15
//	}
    
    swTqLow = ((SLONG)COF_uwTqratePu * 35 )/100;
    swTqHigh = ((SLONG)COF_uwTqratePu * 50 )/100;
    if (pr[PWRSAVE]!=0){
        if (NORMALSP == 1){
            swTqRefPuTmp = abs(SPR_swTqRefPu);
            if (swTqRefPuTmp < swTqLow){      
                if (PWRSaveCNT <= 250)
                    PWRSaveCNT ++;
                else
                    FOCPGPowerSave = 1;
            }    
            else if (swTqRefPuTmp > swTqHigh){
                FOCPGPowerSave = 0;
                PWRSaveCNT = 0;
            }
        }
	    else{
            FOCPGPowerSave = 0;
            PWRSaveCNT = 0;
        }        
    }
    else{
        FOCPGPowerSave = 0;
        PWRSaveCNT = 0;
    }           
   
    if (ACCODEC == DECON){
        swVsErrPu = FLX_swVsMaxPu - FLX_swVoutPu; //Q15
                
            //IdsInteg = IdsInteg + VsErr * Ki
        if (IdRefSat_flag == 0)
            FLX_slVsErrKi = FLX_slVsErrKi + ((SLONG)swVsErrPu * 660); //Q31 = Q31+Q(15+16)
              
        swVsErrKp = ((SLONG)swVsErrPu * 256) >> 10; //Q15

        slIdRef_tmp = COF_uwI0Pu + swVsErrKp + (FLX_slVsErrKi >> 16);

        if (slIdRef_tmp >= COF_uwI0Pu){
            slIdRef_tmp = COF_uwI0Pu;
            IdRefSat_flag = 1;
        }
        else if (slIdRef_tmp < swIdsRef_tmp){
            slIdRef_tmp = swIdsRef_tmp;
            IdRefSat_flag = 1;       
        }
        else
            IdRefSat_flag = 0;
        
        swIdsRef_tmp = slIdRef_tmp;        
    }
    else
        FLX_slVsErrKi = 0;
    
    if (FOCPGPowerSave == 0){
// [ Modify the LPF function by DINO, 03/07/2009
//		FLX_slIdRefPu_LP = lowpass_sl(4120, swIdsRef_tmp, FLX_slIdRefPu_LP);
		FLX_IdRefPuLPF.sl += (SLONG)(swIdsRef_tmp - FLX_IdRefPuLPF.sw.hi) * 4120;
// ]
    }
    else{
        slIdRef_tmp = abs(S16xS16divS16(SPR_swIqseRefPu, (PowerIn>>13), (QowerIn>>15)));
        slIdRef_tmp = (slIdRef_tmp * pr[IdsPSLevel])/100;

        if(slIdRef_tmp > swIdsRef_tmp){
            slIdRef_tmp = swIdsRef_tmp;            
        }

// [ Modify the LPF function by DINO, 03/07/2009
//		FLX_slIdRefPu_LP = lowpass_sl(103, slIdRef_tmp, FLX_slIdRefPu_LP);
		FLX_IdRefPuLPF.sl += (SLONG)((SWORD)slIdRef_tmp - FLX_IdRefPuLPF.sw.hi) * 103;
// ]

    }
    //end Power Save
    FLX_swIdseRefPu = FLX_IdRefPuLPF.sw.hi;

    COF_uwKt = ((ULONG)COF_uwLmPu * FLX_swIdseRefPu) >> 13; //Q8 = Q(6+15-13)
   
	//IqRefLim = sqrt((InvIrate_max*pr[CURRENT_LIM])^2 - Ids^2)
    //ulIqLim_tmp = ((ULONG)COF_uwIIratePu * ((ULONG)pr[CURRENT_LIM] * 563 >> 9)) / 100;  //New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
    if(UCMP)
    {        
        //[UCMP function, Bernie, 2016/06/14]  
	    ulIqLim_tmp = ((ULONG)COF_uwMIratePu * ((ULONG)pr[CUR_LIM_UCMP] * 563 >> 9)) / 100;  //New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
    }
	else{
        ulIqLim_tmp = ((ULONG)COF_uwIIratePu * ((ULONG)pr[CURRENT_LIM] * 563 >> 9)) / 100;  //New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
    }
	if (ulIqLim_tmp >= 0x7FFF){
		ulIqLim_tmp = 0x7FFF;
	}

	// [ If Irms<Id, Iq=0, Add by DINO, 06/17/2009
	if ((SWORD)ulIqLim_tmp < FLX_swIdseRefPu){
		SPR_swIqseRefLimPu = 0;
	}
	else{
    	ulIqLim_tmp = (ulIqLim_tmp * ulIqLim_tmp) - ((ULONG)FLX_swIdseRefPu * FLX_swIdseRefPu);
		SPR_swIqseRefLimPu = uw_Sqrt32c(ulIqLim_tmp); //Q15
	}
	// ]

    if (NORMALSP == 1)
        FLX_slWslErrKi = 0;

}

#ifdef _FluxControl_C
    #undef _FluxControl_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
