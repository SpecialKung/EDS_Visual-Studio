/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _TestSource_C
   #define TestSource_EXT 
#else
   #define TestSource_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
TestSource_EXT void Init_TestSource(void);
TestSource_EXT void TB1_TestSource(void);
TestSource_EXT void TB2_TestSource(void);

/* Exported Variable List ======================================*/
                          
TestSource_EXT  SWORD		TS_swSoOutPu,
							TS_swAmpPu,
							TS_swAmpLimPu,
							TS_swOffsetPu;

TestSource_EXT  UWORD		TS_uwcnt,
							TS_uwTheta;
                          
TestSource_EXT  SLONG		TS_slSoFreqPu;

TestSource_EXT  ULONG		TS_ulKTheta;
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/