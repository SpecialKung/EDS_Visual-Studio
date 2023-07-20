/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _FFD_C
   #define FFD_EXT 
#else
   #define FFD_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
FFD_EXT void FFD_voDecpl(void);
FFD_EXT void FFD_voDecpl_PM(void);

/* Exported Variable List ======================================*/
                          
FFD_EXT  SWORD	          FFD_swIqsePu,
                          FFD_swIdsePu,
                          FFD_swImPu,
                          FFD_swUqseOutPu,
                          FFD_swUdseOutPu;
                          
FFD_EXT	 SLONG			  FFD_slFlxFreqPu;
                          
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/