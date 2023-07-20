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
#ifndef _PR_Motor_C
	#define _PR_Motor_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

//Jm scale 10000
UWORD JmTalbe(UWORD H)
{
	UWORD Jm,Hp_Index;
	
	Hp_Index = (H + 38) / 75;
#if SH7149
	if(Hp_Index <= 1)        	//1Hp
		Jm = 23;
    else if((1 < Hp_Index) && (Hp_Index <= 2))	//2Hp
		Jm = 43;   	
    else if((2 < Hp_Index) && (Hp_Index < 4))	    //3Hp
		Jm = 83;
    else if((4 <= Hp_Index) && (Hp_Index <= 6))	//5Hp
		Jm = 148;
    else if((6 < Hp_Index) && (Hp_Index <= 8))    //7.5Hp
		Jm = 260;    
    else if((8 < Hp_Index) && (Hp_Index <= 12))	//10Hp
		Jm = 358;
    else if((12 < Hp_Index) && (Hp_Index <= 17))	//15Hp
		Jm = 743;
    else if((17 < Hp_Index) && (Hp_Index <= 22))	//20Hp
		Jm = 953;
    else if((22 < Hp_Index) && (Hp_Index <= 27))	//25Hp
		Jm = 1428;    
    else if((27 < Hp_Index) && (Hp_Index <= 35))	//30Hp
        Jm = 1765;
    else if((35 < Hp_Index) && (Hp_Index <= 45))	//40Hp
        Jm = 2025;
    else if((45 < Hp_Index) && (Hp_Index <= 55))	//50Hp
        Jm = 3555;
    else if((55 < Hp_Index) && (Hp_Index <= 65))	//60Hp
        Jm = 2025;
    else
        Jm = 10565;                        	//75Hp 
#else
	if ( Hp_Index>65 )		//75Hp 
        Jm = 10565;
    else if ( Hp_Index>55 )	//60Hp
    	Jm = 2025;
    else if ( Hp_Index>45 )	//50Hp
    	Jm = 3555;
    else if ( Hp_Index>35 )	//40Hp
    	Jm = 2025;
    else if ( Hp_Index>27 ) //30Hp
    	Jm = 1765;
    else if ( Hp_Index>22 ) //25Hp
    	Jm = 1428;
    else if ( Hp_Index>17 ) //20Hp
    	Jm = 953;
    else if ( Hp_Index>12 ) //15Hp
    	Jm = 743;
    else if ( Hp_Index>8 )	//10Hp
    	Jm = 358;
    else if ( Hp_Index>6 )	// 7.5Hp
    	Jm = 260;
    else if ( Hp_Index>4 )	// 5Hp
    	Jm = 148;
    else if ( Hp_Index>2 )	// 3Hp
    	Jm = 83;
    else if ( Hp_Index>1 )	// 2Hp
    	Jm = 43;
	else					// 1Hp
		Jm = 23;
#endif
	return Jm;
}


#ifdef _PR_Motor_C
    #undef _PR_Motor_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
