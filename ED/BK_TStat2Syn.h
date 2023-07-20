/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _Stat2Syn_C
   #define S2E_EXT 
#else
   #define S2E_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
S2E_EXT void Stat2Syn_s2e(void);

/* Exported Variable List ======================================*/
S2E_EXT SWORD             TsE_swIqssInPu,
                          TsE_swIdssInPu,
                          TsE_swIqseOutPu,
                          TsE_swIdseOutPu;
                          
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/