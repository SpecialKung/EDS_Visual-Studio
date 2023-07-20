/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef abc2dq_C
   #define ABC2DQ_EXT 
#else
   #define ABC2DQ_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
ABC2DQ_EXT void Init_TransferValue(void);
ABC2DQ_EXT void abc2dq(void);

/* Exported Variable List ======================================*/
ABC2DQ_EXT SWORD          T32_swIasInPu,
                          T32_swIbsInPu;
                          
ABC2DQ_EXT SWORD          T32_swIdssOutPu,
                          T32_swIqssOutPu;
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
