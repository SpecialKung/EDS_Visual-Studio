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
#ifndef _Syn2Stat_C
	#define _Syn2Stat_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Syn2Stat_e2s(void)
{
	/*-------- Synchronous frame -> Stationary frame --------
	//  fdss = cos(theta)*fdse - sin(theta)*fqse
	//  fqss = sin(theta)*fdse + cos(theta)*fqse
	*/
  //TeS_swUdssOutPu = (sl_limit( ((long)TeS_swUdseInPu*CosValue), ((long)-TeS_swUqseInPu*SinValue), 0x3FFFFFFF))>>15;        // revise overflow cause IqFdb reverse JOSH 2017/03/15
  //TeS_swUqssOutPu = (sl_limit( ((long)TeS_swUdseInPu*SinValue), ((long) TeS_swUqseInPu*CosValue), 0x3FFFFFFF))>>15;        // revise overflow cause IqFdb reverse JOSH 2017/03/15
	TeS_swUdssOutPu = (sl_limit_modify( ((long)TeS_swUdseInPu*CosValue), ((long)-TeS_swUqseInPu*SinValue), 0x3FFFFFFF))>>15; // revise overflow cause IqFdb reverse JOSH 2017/03/15
	TeS_swUqssOutPu = (sl_limit_modify( ((long)TeS_swUdseInPu*SinValue), ((long) TeS_swUqseInPu*CosValue), 0x3FFFFFFF))>>15; // revise overflow cause IqFdb reverse JOSH 2017/03/15
}


void CurSyn2Stat_e2s(SWORD Iq, SWORD Id)
{
	/*-------- Synchronous frame -> Stationary frame --------
	//  fdss = cos(theta)*fdse - sin(theta)*fqse
	//  fqss = sin(theta)*fdse + cos(theta)*fqse
	*/
  //swIdssPu = (sl_limit( ((long)Id*CosValue), ((long)-Iq*SinValue), 0x3FFFFFFF))>>15;        // revise overflow JOSH 2017/03/15
  //swIqssPu = (sl_limit( ((long)Id*SinValue), ((long) Iq*CosValue), 0x3FFFFFFF))>>15;        // revise overflow JOSH 2017/03/15
	swIdssPu = (sl_limit_modify( ((long)Id*CosValue), ((long)-Iq*SinValue), 0x3FFFFFFF))>>15; // revise overflow JOSH 2017/03/15
	swIqssPu = (sl_limit_modify( ((long)Id*SinValue), ((long) Iq*CosValue), 0x3FFFFFFF))>>15; // revise overflow JOSH 2017/03/15
}

#ifdef _Syn2Stat_C
    #undef _Syn2Stat_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
