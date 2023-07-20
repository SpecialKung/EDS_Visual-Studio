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
#ifndef _FFD_C
	#define _FFD_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void FFD_voDecpl(void)
{	
    SLONG q_tmp,d_tmp;

    // Ud = -We*Lx*Iq
    d_tmp = ((SLONG)COF_uwLxPu * FFD_swIqsePu) >> 10; //Q15 = Q(10+15-10)
    d_tmp = S32xS32shlr31(-FFD_slFlxFreqPu, d_tmp); //Q15 = Q(31+15-31)
    // [ Add Voltage Limit, DINO, 08/20/2009
    FFD_swUdseOutPu = sl_limit_modify(d_tmp, 0, FLX_swVsMaxPu) ;	
    // ]

    // Uq = We*(Lx*Id + Lm*Im)
    //q_tmp = ((((SLONG)COF_uwLxPu>>2) * FFD_swIdsePu) >> 8)+((((SLONG)COF_uwLmPu<<2) * FFD_swImPu)>>8);
    q_tmp = ((((SLONG)COF_uwLxPu) * FFD_swIdsePu) >> 10)+((((SLONG)COF_uwLmPu) * FFD_swImPu)>>6);
    q_tmp = S32xS32shlr31(FFD_slFlxFreqPu, q_tmp); //Q15 = Q(31+15-31)
    // [ Add Voltage Limit, DINO, 08/20/2009
    FFD_swUqseOutPu = sl_limit_modify(q_tmp, 0, FLX_swVsMaxPu);
    // ]

    if (SPSEARCH==1){
		FFD_swUqseOutPu = 0;
		FFD_swUdseOutPu = 0;
    }		
	
}


// [ PM FFD Decouple, Add by DINO, 06/03/2009
void FFD_voDecpl_PM(void)
{	
    SLONG q1_tmp, q2_tmp, d_tmp;

    // Ud = -We*Lq*Iq
    d_tmp = ((SLONG)COF_uwLxPu * FFD_swIqsePu) >> 10; //Q15 = Q(10+15-10)
    d_tmp = S32xS32shlr31(-FFD_slFlxFreqPu, d_tmp); //Q15 = Q(31+15-31)
    FFD_swUdseOutPu = sl_limit(d_tmp, 0, 0x7FFF) ;	

    // Uq = We*(Ld*Id + Lm*Im) = We*(Ld*Id + lamda_M)
    q1_tmp = ((((SLONG)COF_uwLxPu>>2) * FFD_swIdsePu) >> 8)/*+((((SLONG)COF_uwLmPu<<2) * FFD_swImPu)>>8)*/;
    q1_tmp = S32xS32shlr31(FFD_slFlxFreqPu, q1_tmp); //Q15 = Q(31+15-31)

	// We*lamda_M
	q2_tmp = U16xU16divU16(COF_uwBemfPu, fout.uw.hi, COF_uwMFrRe);	//Q15 = Q(15+16-16)

    FFD_swUqseOutPu = sl_limit(q1_tmp, q2_tmp, 0x7FFF);

    if (SPSEARCH==1){
		FFD_swUdseOutPu = 0;
		FFD_swUqseOutPu = 0;
    }
	
}
// ]


#ifdef _FFD_C
    #undef _FFD_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
