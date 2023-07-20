/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _EstJ_C
   #define EstJ_EXT 
#else
   #define EstJ_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
EstJ_EXT void Init_Estimate_J(void);
EstJ_EXT void Estimate_J(void);

/* Exported Variable List ======================================*/
EstJ_EXT  UBYTE			EsJ_ubKInt,
						EsJ_ubsteady;
                          
EstJ_EXT  UWORD	        EsJ_uwKJGain,
						EsJ_uwLPG,
						EsJ_uwJmPu;
                          
EstJ_EXT  SWORD	        EsJ_swJPu_New,
						EsJ_swTePu;

EstJ_EXT  SLONG	        EsJ_slJPu,
						EsJ_slTeInt,
						EsJ_slTLPu_FWD,
						EsJ_slTLPu_REV,
						EsJ_slSpdtmpPu;

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
