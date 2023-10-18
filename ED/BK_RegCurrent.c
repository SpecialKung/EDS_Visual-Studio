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
#ifndef _CurrentReg_C
	#define _CurrentReg_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_CurrentReg(void)
{
	CUR_swIdseRefPu = 0;
	CUR_swIdseFdbPu = 0;
	CUR_swIqseRefPu = 0;
		CUR_swIqseRefPuOld = 0;	//Limit Current Change Rate, DINO, 10/22/2010
	CUR_swIqseFdbPu = 0;
	CUR_slIdInteg = 0;
	CUR_slIqInteg = 0;
	CUR_swUdseOutPu = 0;
	CUR_swUqseOutPu = 0;	
	swIqssPu = 0;
	swIdssPu = 0;
	swIasRefPu = 0;
	swIbsRefPu = 0;
	swIcsRefPu = 0;
	TB1_CurrentReg();

}

void TB1_CurrentReg(void)
{
    UWORD BW;
	UWORD CarryFreq_tmp,Kp_tmp,Ki_tmp;
	
	if ((pr[CTRLSEL]&0x0004) == 0){ 	//CTRLSEL bit2 = 0               
		if (experiod >= 3428){						//7kHz >= Carry Freq >= 1kHz    //[Kp Ki problem, Bernie, 2017/03/27]
		                                            //2857 <=  experiod  <= 20000
			CarryFreq_tmp = U32divU16((ULONG)960000, experiod);        //[Kp Ki problem, Bernie, 2017/03/27]
			BW = CarryFreq_tmp + 40;
		}
		else if (experiod >= 2666){					//9kHz >= Carry Freq > 7kHz    //[Kp Ki problem, Bernie, 2017/03/27]
		                                            //2222 <=  experiod  < 2857		
			CarryFreq_tmp = U32divU16((ULONG)480000, experiod);    //[Kp Ki problem, Bernie, 2017/03/27]
			BW = CarryFreq_tmp + 180;
	    }    
		else{										//15kHz >= Carry Freq > 9kHz 
		                                            // 1333 <=  experiod  < 2222
			CarryFreq_tmp = U32divU16((ULONG)240000, experiod);    //[Kp Ki problem, Bernie, 2017/03/27]
			BW = CarryFreq_tmp + 280;
		}
	}	
	else{								//CTRLSEL bit2 = 1
		BW = pr[CULPBW];
	}


	if ((pr[CTRLM] == FOCPM)){	//ADDED BY SCOTTY 2006/06/07
	
		//Kp = 100 * BW * LxPu / Fb, Q10
		Kp_tmp = U16xU16divU16((100*BW), COF_uwLxPu, COF_uwFbRe); //Q10  COF_uwLxPu :Q10  05-09 unit:mH
		//Ki = 2*pi * BW * RsPu * 2 / 10000, Q16
		//   = (2*pi/10000)*2^16 * BW * RsPu / 2^16
		//   = 83 * BW * RsPu / 2^16
		
		Ki_tmp = U32xU16shlr16((83*BW), COF_uwRsPu); //Q16   COF_uwRsPu:Q15
		
		CUR_uwqKpPu = (ULONG)Kp_tmp * pr[TRQ_P] / 100;	//12-15
		CUR_uwqKiPu = (ULONG)Ki_tmp * pr[TRQ_I] / 20;	//12-16
		
		CUR_uwdKpPu = (ULONG)Kp_tmp * pr[FLUX_P] / 100;	//12-17
		CUR_uwdKiPu = (ULONG)Ki_tmp * pr[FLUX_I] / 20;	//12-18
	}	
	else{	
		//Kp = 100 * BW * LxPu / Fb, Q10
		Kp_tmp = U16xU16divU16((100*BW), COF_uwLxPu, COF_uwFbRe); //Q10
		//Ki = 2*pi * BW * RsPu * 2 / 10000, Q16
		//   = (2*pi/10000)*2^16 * BW * RsPu / 2^16
		//   = 83 * BW * RsPu / 2^16
		Ki_tmp = U32xU16shlr16((83*BW), COF_uwRsPu); //Q16
    	
		CUR_uwqKpPu = (ULONG)Kp_tmp * pr[TRQ_P] / 100;
		CUR_uwqKiPu = (ULONG)Ki_tmp * pr[TRQ_I] / 100;
		
		CUR_uwdKpPu = (ULONG)Kp_tmp * pr[FLUX_P] / 100;
		CUR_uwdKiPu = (ULONG)Ki_tmp * pr[FLUX_I] / 100;
	}
}

void CurrentReg_daxis(void)
{
    SWORD CUR_swIdseErrPu,swErrtmp;
    SLONG dkptemp;
  	
	//CUR_swIdseErrPu = CUR_swIdseRefPu - CUR_swIdseFdbPu;                                 	// revise overflow JOSH 2017/03/15
	CUR_swIdseErrPu = (SWORD)sl_limit_modify(CUR_swIdseRefPu, -CUR_swIdseFdbPu, 0x7FFF); 	// revise overflow JOSH 2017/03/15
	// Proportional Gain
    //dkptemp = sl_limit(((SLONG)CUR_swIdseErrPu * CUR_uwdKpPu), 0, 0x1FFFFFF); //Q25 = Q(15+10)       // revise (dkptemp<<6) underflow by JOSH 2017/03/15
	dkptemp = sl_limit_modify(((SLONG)CUR_swIdseErrPu * CUR_uwdKpPu), 0, 0x1FFFFFF); //Q25 = Q(15+10)  // revise (dkptemp<<6) underflow by JOSH 2017/03/15
	
	if (VolSat_flag==0)
	{	
		// Integral Time
		CUR_slIdInteg = sl_limit(CUR_slIdInteg ,((SLONG)CUR_swIdseErrPu * CUR_uwdKiPu), 0x7FFFFFFF);  //Q31 = Q(15+16)
        CUR_slWindUp = 0;
	}
	else
	{
        swErrtmp = FLX_swVoutPu - FLX_swVsMaxPu; //Q15
      	//CUR_slWindUp = CUR_slWindUp + ((SLONG)swErrtmp*7168)>>10;    // revise anti-windup by JOSH 2017/03/15
        //CUR_slWindUp = CUR_slWindUp + (SLONG)swErrtmp*7;             // revise anti-windup by JOSH 2017/03/15
		//CUR_slWindUp = sl_limit_modify(CUR_slWindUp,  (SLONG)swErrtmp*7, 0x7FFFFFFF);      // revise anti-windup by JOSH 2017/03/15  //[Voltage saturate, Howard, 2018/10/23]
	   	CUR_slWindUp =0;  // revise anti-windup by JJ 2018/11/02


#if 0		
        if (CUR_slIdInteg >= 0)	
           	CUR_slIdInteg = CUR_slIdInteg - CUR_slWindUp;	
        else
            CUR_slIdInteg = CUR_slIdInteg + CUR_slWindUp;
    
#else 
	 //[Voltage saturate, Howard, 2018/10/23]
        // slIdIntegtemp = CUR_slIdInteg;

		if (CUR_slIdInteg > 0)
		{
			CUR_slIdInteg = sl_limit_modify(CUR_slIdInteg,  - CUR_slWindUp, 0x7FFFFFFF);
			if(CUR_slIdInteg <= 0)
			{
				CUR_slIdInteg = 0;
			}
		}
		else  if (CUR_slIdInteg < 0)
		{
			CUR_slIdInteg = sl_limit_modify( CUR_slIdInteg, CUR_slWindUp, 0x7FFFFFFF);
			if(CUR_slIdInteg >= 0)
			{
				CUR_slIdInteg = 0;
			}
		}

         //CUR_slIdInteg = slIdIntegtemp;


#endif
    }
	if (SPSEARCH==1){
		dkptemp = 0;
		CUR_slIdInteg = 0;
	}
			
	CUR_swUdseOutPu = (SWORD)(sl_limit_modify((dkptemp << 6) , CUR_slIdInteg, 0x7FFFFFFF)>>16); //Q15
}

void CurrentReg_qaxis(void)
{
    SWORD CUR_swIqseErrPu;
	SLONG qkptemp;
  //CUR_swIqseErrPu = CUR_swIqseRefPu - CUR_swIqseFdbPu;                                 // revise overflow JOSH 2017/03/15
	CUR_swIqseErrPu = (SWORD)sl_limit_modify(CUR_swIqseRefPu, -CUR_swIqseFdbPu, 0x7FFF); // revise overflow JOSH 2017/03/15

	if(pr[Qer_min] != 0){  //[Current Low Frequency Ripple,JerrySK,2019/09/05]
	    if((CUR_swIqseErrPu < pr[Qer_min]) && (CUR_swIqseErrPu > -pr[Qer_min])){
		    CUR_swIqseErrPu = CUR_swIqseErrPu >> pr[Qer_Shift];
		}
	}



	// Proportional Gain
    //qkptemp = sl_limit(((SLONG)CUR_swIqseErrPu * CUR_uwqKpPu), 0, 0x1FFFFFF); //Q25 = Q(15+10)       // revise (qkptemp<<6) underflow by JOSH 2017/03/15
	qkptemp = sl_limit_modify(((SLONG)CUR_swIqseErrPu * CUR_uwqKpPu), 0, 0x1FFFFFF); //Q25 = Q(15+10)  // revise (qkptemp<<6) underflow by JOSH 2017/03/15

    if (VolSat_flag==0)
    	CUR_slIqInteg = sl_limit(CUR_slIqInteg ,((SLONG)CUR_swIqseErrPu * CUR_uwqKiPu), 0x7FFFFFFF);  //Q31 = Q(15+16)
    else{

#if 0
        if (CUR_slIqInteg >= 0)
            CUR_slIqInteg = CUR_slIqInteg - CUR_slWindUp;
        else
	   CUR_slIqInteg = CUR_slIqInteg + CUR_slWindUp;
#else
	 //[Voltage saturate, Howard, 2018/10/23]
         //slIqIntegtemp = CUR_slIqInteg;

       if (CUR_slIqInteg > 0) {
          CUR_slIqInteg = sl_limit_modify(CUR_slIqInteg,  - CUR_slWindUp, 0x7FFFFFFF);
	if(CUR_slIqInteg <= 0) {
		CUR_slIqInteg = 0;
	    }
       	}
       else if(CUR_slIqInteg < 0){
	CUR_slIqInteg = sl_limit_modify(CUR_slIqInteg, CUR_slWindUp, 0x7FFFFFFF);
	if(CUR_slIqInteg >= 0){
		CUR_slIqInteg = 0;
		}
       	}

         //CUR_slIqInteg = slIqIntegtemp;
 #endif
		

    }

	if (SPSEARCH==1){
		qkptemp = 0;
		CUR_slIqInteg = 0;
	}
	
	sl_IqErrKp  = qkptemp;      // JOSH IqRef vs IqFdb offset TEST 2017/03/15
	sl_IqErrKp6 = qkptemp << 6; // JOSH IqRef vs IqFdb offset TEST 2017/03/15
	CUR_swUqseOutPu = (SWORD)(sl_limit_modify((qkptemp << 6), CUR_slIqInteg , 0x7FFFFFFF)>>16); //Q15
}


#ifdef _CurrentReg_C
    #undef _CurrentReg_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
