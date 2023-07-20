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
#ifndef _dq2abc_C
	#define _dq2abc_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void dq2abc(void)
{
	SLONG dq2abcTemp1,dq2abcTemp2;
	/*-----------SCOTTY TYPE-------
	  fas = fqss
	  fbs = -(sqrt(3)/2)fdss - (1/2)fqss = (-sqrt(3)*fdss - fqss)/2
	  fcs = (sqrt(3)/2)fdss - (1/2)fqss= ((sqrt(3)*fdss - fqss)/2)  
	  sqrt(3) in Q13 = 14188.96022 => 14189	
	
	-------- 2 phase qd -> 3 phase abc
	  fas = fdss
	  fbs = (sqrt(3)/2)fqss - (1/2)fdss = (sqrt(3)*fqss - fdss)/2
	  fcs = -(sqrt(3)/2)fqss - (1/2)fdss=-((sqrt(3)*fqss + fdss)/2)  
	  sqrt(3) in Q13 = 14188.96022 => 14189
	*/	

 #if 0
	if (T23_swUdssInPu >= COF_uwVratePu)
	    T23_swUasOutPu = COF_uwVratePu;
    else if (T23_swUdssInPu <= -COF_uwVratePu)
	    T23_swUasOutPu = -COF_uwVratePu;
	else
	    T23_swUasOutPu = T23_swUdssInPu;	
       
    T23_swUbsOutPu = (sl_limit(dq2abcTemp1, -dq2abcTemp2, (((SLONG)COF_uwVratePu<<14)))) >> 14;	
	T23_swUcsOutPu = (sl_limit(-dq2abcTemp1, -dq2abcTemp2, (((SLONG)COF_uwVratePu<<14)))) >> 14;    

 #else

	#if SCOTTY
		dq2abcTemp1 = ((SLONG)T23_swUdssInPu * 14189); //Q28 = Q(15+13)
		dq2abcTemp2 = ((SLONG)T23_swUqssInPu * 8192); //Q28 = Q(15+13)	
		// [ Add Voltage Limit, DINO, 08/20/2009
		if (T23_swUqssInPu >= FLX_swVsMaxPu)				//DEL SCOTTY 11/02/2007
	    	T23_swUasOutPu = FLX_swVsMaxPu;					//DEL SCOTTY 11/02/2007
    	else if (T23_swUqssInPu <= -FLX_swVsMaxPu)			//DEL SCOTTY 11/02/2007
	    	T23_swUasOutPu = -FLX_swVsMaxPu;				//DEL SCOTTY 11/02/2007
		else
	    	T23_swUasOutPu = T23_swUqssInPu;
	    		
      //T23_swUbsOutPu = (sl_limit(-dq2abcTemp1, -dq2abcTemp2, ((SLONG)FLX_swVsMaxPu<<14)) + 8192) >> 14;        // revise overflow cause IqFdb reverse JOSH 2017/03/15
      //T23_swUcsOutPu = (sl_limit(dq2abcTemp1, -dq2abcTemp2, ((SLONG)FLX_swVsMaxPu<<14)) + 8192) >> 14;         // revise overflow cause IqFdb reverse JOSH 2017/03/15
		T23_swUbsOutPu = (sl_limit_modify(-dq2abcTemp1, -dq2abcTemp2, ((SLONG)FLX_swVsMaxPu<<14)) + 8192) >> 14; // revise overflow cause IqFdb reverse JOSH 2017/03/15
		T23_swUcsOutPu = (sl_limit_modify(dq2abcTemp1, -dq2abcTemp2, ((SLONG)FLX_swVsMaxPu<<14)) + 8192) >> 14;  // revise overflow cause IqFdb reverse JOSH 2017/03/15  
		// ]
	#else
		dq2abcTemp1 = ((SLONG)T23_swUqssInPu * 14189); //Q28 = Q(15+13)
		dq2abcTemp2 = ((SLONG)T23_swUdssInPu * 8192); //Q28 = Q(15+13)
		
		if (T23_swUdssInPu >= FLX_swVsMaxPu)
	    	T23_swUasOutPu = FLX_swVsMaxPu;
    	else if (T23_swUdssInPu <= -FLX_swVsMaxPu)
	    	T23_swUasOutPu = -FLX_swVsMaxPu;
		else
	    	T23_swUasOutPu = T23_swUdssInPu;	
	    		
		T23_swUbsOutPu = (sl_limit(dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14;	
		T23_swUcsOutPu = (sl_limit(-dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14;    
	#endif

 #endif
}

void Curdq2abc(SWORD Iqss, SWORD Idss)
{
	SLONG dq2abcTemp1,dq2abcTemp2;
	/*-----------SCOTTY TYPE-------
	  fas = fqss
	  fbs = -(sqrt(3)/2)fdss - (1/2)fqss = (-sqrt(3)*fdss - fqss)/2
	  fcs = (sqrt(3)/2)fdss - (1/2)fqss= ((sqrt(3)*fdss - fqss)/2)  
	  sqrt(3) in Q13 = 14188.96022 => 14189	
	
	-------- 2 phase qd -> 3 phase abc
	  fas = fdss
	  fbs = (sqrt(3)/2)fqss - (1/2)fdss = (sqrt(3)*fqss - fdss)/2
	  fcs = -(sqrt(3)/2)fqss - (1/2)fdss=-((sqrt(3)*fqss + fdss)/2)  
	  sqrt(3) in Q13 = 14188.96022 => 14189
	*/		

#if SCOTTY
	swIasRefPu = Iqss;
	
	dq2abcTemp1 = ((SLONG)Idss * 14189); //Q28 = Q(15+13)
	dq2abcTemp2 = ((SLONG)Iqss * 8192); //Q28 = Q(15+13)
    
  //swIbsRefPu = (sl_limit(-dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14;        // revise overflow JOSH 2017/03/15
	swIbsRefPu = (sl_limit_modify(-dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14; // revise overflow JOSH 2017/03/15
// [ Modify swIcsRefPu calculation by DINO, 03/06/2009
//	swIcsRefPu = (sl_limit(dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14; 
	swIcsRefPu = -swIasRefPu -swIbsRefPu;
// ] 
#else
	swIasRefPu = Idss;
	
	dq2abcTemp1 = ((SLONG)Iqss * 14189); //Q28 = Q(15+13)
	dq2abcTemp2 = ((SLONG)Idss * 8192); //Q28 = Q(15+13)
    
	swIbsRefPu = (sl_limit(dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14;	
	swIcsRefPu = (sl_limit(-dq2abcTemp1, -dq2abcTemp2, 0x1FFFFFFF)) >> 14;    
#endif 
}


#ifdef _dq2abc_C
    #undef _dq2abc_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
