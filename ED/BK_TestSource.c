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
#ifndef _TestSource_C
	#define _TestSource_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
#include "PR_SinTable.h"

void Init_TestSource(void)
{
	TS_uwcnt = 0;
	TS_uwTheta = 0;
	TS_swSoOutPu = 0;
	TS_swAmpPu = 0;
#if 0
	//for current loop test
	TS_swAmpLimPu = U16xU16divU16(pr[TESTAmp] ,46341, COF_uwIbRe);
    TS_swOffsetPu = U16xU16divU16(pr[TESTBias] ,46341, COF_uwIbRe);
	TS_slSoFreqPu = 2863311; //1Hz / 750Hz * 2^31
	TS_ulKTheta = U32xU32divU32((ULONG)75000, (ULONG)(65536), 10000);
#else
    //for speed loop test
	TS_swAmpLimPu = U16xU16divU16(pr[TESTAmp] ,32767, COF_uwFbRe);
    TS_swOffsetPu = U16xU16divU16(pr[TESTBias] ,32767, COF_uwFbRe);
//	TS_slSoFreqPu = 21474836; //1Hz / 100Hz * 2^31
	TS_slSoFreqPu = 0;
	TS_ulKTheta = U32xU32divU32((ULONG)5000, (ULONG)(65536), 10000);
//	TS_ulKTheta = U32xU32divU32((ULONG)1000, (ULONG)(65536), 10000);
#endif
}

void TB1_TestSource(void)
{
	if (TS_uwcnt >= 2000){

	    TS_swAmpPu = sl_limit(TS_swAmpPu, 1, TS_swAmpLimPu);	
	}		
}

void TB2_TestSource(void)
{	
	SWORD TS_swSinValue,TS_swThetaStep;
	UWORD TS_uwSinIndex;
		
	TS_uwcnt++;
	if (TS_uwcnt > 2000){
		TS_uwcnt = 2001;
		//20s arrive 750hz => 20s/100us ---> 2^31
		//step = 2^31/200000 = 10737
   		TS_slSoFreqPu = sl_limit(TS_slSoFreqPu, 10737, 0x7FFFFFFF);	    
	    TS_swThetaStep = (S32xS32shlr31(TS_ulKTheta, TS_slSoFreqPu))/100;
	}
	else
		TS_swThetaStep = 0;

   	TS_uwTheta = (((ULONG)TS_uwTheta + TS_swThetaStep) & 0x0FFFF);

   	TS_uwSinIndex = TS_uwTheta >> 6;
    TS_swSinValue = sine[TS_uwSinIndex];
   	    
    TS_swSoOutPu = (((SLONG)TS_swAmpLimPu<<1) * TS_swSinValue)>>16;
	
    TS_swSoOutPu = TS_swSoOutPu + TS_swOffsetPu;
	
}
#ifdef _TestSource_C
    #undef _TestSource_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
