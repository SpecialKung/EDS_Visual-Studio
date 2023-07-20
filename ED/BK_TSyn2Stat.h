/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _Syn2Stat_C
   #define E2S_EXT 
#else
   #define E2S_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
E2S_EXT void Syn2Stat_e2s(void);
E2S_EXT void CurSyn2Stat_e2s(SWORD Iq, SWORD Id);
/* Exported Variable List ======================================*/
E2S_EXT SWORD             TeS_swUqseInPu,
                          TeS_swUdseInPu,
                          TeS_swUqssOutPu,
                          TeS_swUdssOutPu;
                          
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/