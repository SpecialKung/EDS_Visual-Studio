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
#ifndef _Stat2Syn_C
	#define _Stat2Syn_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Stat2Syn_s2e(void)
{
    SLONG sltmp;
	/*-------- Stationary frame -> Synchronous frame --------
	//  fdse =  cos(theta)*fdss + sin(theta)*fqss
	//  fqse =  cos(theta)*fqss - sin(theta)*fdss
	*/	
	sltmp = ((SLONG)TsE_swIdssInPu * CosValue + (SLONG)TsE_swIqssInPu * SinValue)>>15;
	if (sltmp >= 0x7FFF)
        TsE_swIdseOutPu = 0x7FFF;
    else if (sltmp <= -0x7FFF)
        TsE_swIdseOutPu = -0x7FFF;
    else    	   
        TsE_swIdseOutPu = sltmp;
        
    sltmp = ((SLONG)TsE_swIqssInPu * CosValue - (SLONG)TsE_swIdssInPu * SinValue)>>15;
	if (sltmp >= 0x7FFF)
        TsE_swIqseOutPu = 0x7FFF;
    else if (sltmp <= -0x7FFF)
        TsE_swIqseOutPu = -0x7FFF;
    else    	   
        TsE_swIqseOutPu = sltmp;

}


#ifdef _Stat2Syn_C
    #undef _Stat2Syn_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
