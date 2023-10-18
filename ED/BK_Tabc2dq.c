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
#ifndef abc2dq_C
	#define abc2dq_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_TransferValue(void)
{
    CosValue = 0;
    SinValue = 0;
    //Stationary Frame to Synchronous Frame
    TeS_swUdssOutPu = 0;
    TeS_swUqssOutPu = 0;
    TeS_swUdseInPu = 0;
    TeS_swUqseInPu = 0;
    
    //Synchronous Frame to Stationary Frame    
    TeS_swUdseInPu = 0;
    TeS_swUqseInPu = 0;
    TeS_swUqssOutPu = 0;
    TeS_swUqssOutPu = 0;
    
    // 3 phase to 2 phase
    T32_swIasInPu = 0;
    T32_swIbsInPu = 0;
    
    T32_swIdssOutPu = 0;
    T32_swIqssOutPu = 0;
    
    // 2 phase to 3 phase
    T23_swUdssInPu = 0;
    T23_swUqssInPu = 0;
    
}

void abc2dq(void)
{
    SLONG slIdssOutPu;

    //SLONG slIqssOutPu, slIdssOutPu;         //clear Warning, Special.kung, 03/08/2023

    /*--------SCOTTY TYPE----------------------
	fqss = fas 
	fdss = (1/sqrt(3))[-fas - 2fbs]
	f0ss = (1/3)[fas + fbs + fcs]
	(1/sqrt(3)) in Q15 = 18919	    



    -------- 3 phase abc -> 2 phase dq --------
	fdss = fas 
	fqss = (1/sqrt(3))[fas + 2fbs]
	f0ss = (1/3)[fas + fbs + fcs]
	(1/sqrt(3)) in Q15 = 18919
    */
	
#if SCOTTY
    T32_swIqssOutPu = T32_swIasInPu;
    slIdssOutPu = ((SLONG)(-T32_swIasInPu - 2*T32_swIbsInPu)*18919)>>15;

    if (slIdssOutPu >= 0x7FFF)
        T32_swIdssOutPu = 0x7FFF;
    else if (slIdssOutPu <= -0x7FFF)
        T32_swIdssOutPu = -0x7FFF;
    else
        T32_swIdssOutPu = slIdssOutPu;  
#endif       


  
}


#ifdef abc2dq_C
    #undef abc2dq_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
