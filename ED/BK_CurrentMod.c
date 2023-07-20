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
#ifndef _CurrentMod_C
	#define _CurrentMod_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

#include "PR_SinTable.h"
void Init_CurrentMod(void)
{
	CRM_ulThetaR = 0;
	CRM_ulThetaSL = 0;
	CRM_uwTheta = 0;
	CRM_swIqPu = 0;
	CRM_swIdPu = 0;
//	CRM_slImPu = 0;
	CRM_ImPuLPF.sl = 0;
}

void CurrentMod_noPG(void)
{
    
    if (pr[AUTO_T]!=0 ){
    	CRM_swIdPu = 32767;         //Q15
    	CRM_swIqPu = 0;             //Q15
    	CRM_slSpdPu = S32xS32divS32(TB1_slSpdCmdPu,5,3); //[IM Autotune Modify,Sampo,2018/07/12]
    }

    //Wsl = iSq * Tr_inv / id; which value is in Q31 = Q((15+22+9)-15)
    //CRM_slWslPu = S32xS32divS32(((SLONG)CRM_swIqPu << 9), COF_Tr_inv, CRM_swIdPu);	

    //Wr(Flux Freq) = Ws(Freq Command) + Wsl(Slip Freq) Q31
    //CRM_slFlxFreqPu = CRM_slSpdPu + CRM_slWslPu;
    CRM_slFlxFreqPu = CRM_slSpdPu;

    //Theta = Theta + DeltaTheta * CRM_swFlxFreqPu, (0-360) = (0-65535)
    // CRM_slFlxFreqPu in Q31, COF_ulKTheta in Q16
    // 0x80000000 = 2^31, because Fb scale 100, so COF_ulKTheta sacle 100
    if (VH_EN == 1)    	
        CRM_swThetaStep = (S32xS32shlr31(COF_ulKTheta, CRM_slFlxFreqPu))/10;
    else
    	CRM_swThetaStep = (S32xS32shlr31(COF_ulKTheta, CRM_slFlxFreqPu))/100;
    	
	// [ Lock the electrical angle of MPHL detection, added by Sampo, 05/06/2009
	/*==============================================
	==                                   IA  IB  IC
	==  TB1_swMPHLstep=0/CRM_uwTheta=30   +   0   -  
	==  TB1_swMPHLstep=2/CRM_uwTheta=90   0   +   -  
	==============================================*/
    if ( MPHL_DET ){
		if(TB1_swMPHLstep == 0){
			CRM_uwTheta = phase30;
        }
		else if (TB1_swMPHLstep == 2){
			CRM_uwTheta = phase90;
		}
    }  //]
    else{
		CRM_uwTheta = ((CRM_uwTheta + CRM_swThetaStep) & 0x0FFFF);
	}

  #if 1
    // sin table have 1500 data
   	if(pr[Sin_HS_Tab] == 1){  //[Sin Table extend,Jason,2019/09/02]
		CRM_uwSinIndex = CRM_uwTheta >> 2;
		CRM_uwCosIndex = ((CRM_uwTheta + 16384) & 0x0FFFF) >> 2;
	}
	else{
		CRM_uwSinIndex = CRM_uwTheta >> 6;
		CRM_uwCosIndex = ((CRM_uwTheta + 16384) & 0x0FFFF) >> 6;
	}
    
   	//90 degree map to Q16 is 16384
  #else
    CRM_uwSinIndex = ((ULONG)CRM_uwTheta * 1024) >> 16;
   	if (CRM_uwTheta <= 49151)
   	    CRM_uwCosIndex = ((ULONG)(CRM_uwTheta + 16384) * 1024)>>16;
   	else
   	    CRM_uwCosIndex = ((ULONG)(CRM_uwTheta - 49151) * 1024)>>16;
  #endif
   	if(pr[Sin_HS_Tab] == 1){  //[Sin Table extend,Jason,2019/09/02]
		SinValue = sine_high_resolution[CRM_uwSinIndex];
		CosValue = sine_high_resolution[CRM_uwCosIndex];
	}
	else{
		SinValue = sine[CRM_uwSinIndex];
		CosValue = sine[CRM_uwCosIndex];
	}


#if SCOTTY   							//	SCOTTY 2007/07/17  
    CRM_uwaxisCOR =((CRM_uwTheta + 49152) & 0x0FFFF);
#else
	CRM_uwaxisCOR = CRM_uwTheta;
#endif     
    if (CRM_uwaxisCOR < phase60)
        CRM_SinSection = 0;
    else if (CRM_uwaxisCOR < phase120)
        CRM_SinSection = 1;
    else if (CRM_uwaxisCOR < phase180)
        CRM_SinSection = 2;
    else if (CRM_uwaxisCOR < phase240)
        CRM_SinSection = 3;
    else if (CRM_uwaxisCOR < phase300)
        CRM_SinSection = 4;
    else
        CRM_SinSection = 5;
}

void CurrentMod_PG(void)
{
    SLONG CRM_theatTmp;
    SLONG slSlipTmp;
 
    //Wsl = iq /(Tr*(1/(1+TrS)*id))
    //Wsl = iq*Tr_inv/(Im)
// [ Modify the LPF function by DINO, 03/06/2009
/* Delete original calculation
	CRM_slImPu = lowpass_sl(COF_uwIdsLPG, CRM_swIdPu, CRM_slImPu); //Q31
    if ((CRM_slImPu>>16) >= ((SWORD)COF_uwI0Pu))
        CRM_slImPu = ((SLONG)COF_uwI0Pu<<16);
*/
    CRM_ImPuLPF.sl += (SLONG)(CRM_swIdPu - CRM_ImPuLPF.sw.hi ) * COF_uwIdsLPG;	// 100ms (base 1ms)
    if (CRM_ImPuLPF.sw.hi >= ((SWORD)COF_uwI0Pu)){
        CRM_ImPuLPF.sw.hi  = COF_uwI0Pu;
        CRM_ImPuLPF.sw.low = 0;
    }
// ]

    //which value is in Q31 = Q((15+22+9)-15)
    CRM_slWslPu = S32xS32divS32(((SLONG)CRM_swIqPu << 9), COF_Tr_inv, CRM_swIdPu);
    
    slSlipTmp = ((SLONG)10 * COF_ulFslipRatePu);
    
    if (CRM_slWslPu > slSlipTmp)
        CRM_slWslPu = slSlipTmp;
    else if (CRM_slWslPu < (-slSlipTmp))
        CRM_slWslPu = -slSlipTmp;        

    //Theta = Theta + DeltaTheta * CRM_slWslPu, (0-360) = (0-65535)
    // CRM_slWslPu in Q31, COF_ulKTheta in Q16
    // 0x80000000 = 2^31, because Fb scale 100, so COF_ulKTheta sacle 100
    CRM_theatTmp = S32xS16shlr16(COF_ulKTheta, (CRM_slWslPu/50));
    CRM_ulThetaSL = (CRM_ulThetaSL + CRM_theatTmp);
    
    CRM_uwTheta = (((CRM_ulThetaR + CRM_ulThetaSL)>>16) & 0x0FFFF);
//    CRM_uwTheta = (((SpDt_ulThetaR + CRM_ulThetaSL)>>16) & 0x0FFFF);

    //Wr(Flux Freq) = Ws(Freq Command) + Wsl(Slip Freq) Q31
    CRM_slFlxFreqPu = CRM_slSpdPu + CRM_slWslPu;

  #if 1
    // sin table have 1500 data

   	if(pr[Sin_HS_Tab] == 1){  //[Sin Table extend,Jason,2019/09/02]
		CRM_uwSinIndex = CRM_uwTheta >> 2;
		CRM_uwCosIndex = ((CRM_uwTheta + 16384) & 0x0FFFF) >> 2;
	}
	else{
		CRM_uwSinIndex = CRM_uwTheta >> 6;
		CRM_uwCosIndex = ((CRM_uwTheta + 16384) & 0x0FFFF) >> 6;
	}    
   	//90 degree map to Q16 is 16384
  #else
    CRM_uwSinIndex = ((ULONG)CRM_uwTheta * 1024) >> 16;
   	if (CRM_uwTheta <= 49151)
   	    CRM_uwCosIndex = ((ULONG)(CRM_uwTheta + 16384) * 1024)>>16;
   	else
   	    CRM_uwCosIndex = ((ULONG)(CRM_uwTheta - 49151) * 1024)>>16;
  #endif
   
      if(pr[Sin_HS_Tab] == 1){ //[Sin Table extend,Jason,2019/09/02]
		  SinValue = sine_high_resolution[CRM_uwSinIndex];
		  CosValue = sine_high_resolution[CRM_uwCosIndex];
	  }
	  else{
		  SinValue = sine[CRM_uwSinIndex];
		  CosValue = sine[CRM_uwCosIndex];
	  }

}
/****************************************************************************
*******************ADDED BY SCOTTY 20060606**********************************
****************************************************************************/

void CurrentMod_PMPG(void)	//獲得SIN、COS查表值	100us
{  
    CRM_uwTheta = ((CRM_ulThetaR>>16) & 0x0FFFF);  
    CRM_slFlxFreqPu = CRM_slSpdPu;


   	if(pr[Sin_HS_Tab] == 1){ //[Sin Table extend,Jason,2019/09/02]
		CRM_uwSinIndex = CRM_uwTheta >> 2;
		CRM_uwCosIndex = ((CRM_uwTheta + 16384) & 0x0FFFF) >> 2;
	}
	else{
		CRM_uwSinIndex = CRM_uwTheta >> 6;
		CRM_uwCosIndex = ((CRM_uwTheta + 16384) & 0x0FFFF) >> 6;
	}


   
   if(pr[Sin_HS_Tab] == 1){ //[Sin Table extend,Jason,2019/09/02]
		   SinValue = sine_high_resolution[CRM_uwSinIndex];
		   CosValue = sine_high_resolution[CRM_uwCosIndex];
   }
   else{
		   SinValue = sine[CRM_uwSinIndex];
		   CosValue = sine[CRM_uwCosIndex];
   }

    
}
#ifdef _CurrentMod_C
    #undef _CurrentMod_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
