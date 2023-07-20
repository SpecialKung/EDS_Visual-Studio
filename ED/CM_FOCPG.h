/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: CM_FOCPG.H

Partner Filename: CM_FOCPG.C

Description: This is a inclue file of CM_FOCPG.C

Complier: 

	
History:

===============================================================*/
#ifdef _CM_FOCPG_C
   #define CM_FOCPG_EXT 
#else
   #define CM_FOCPG_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
CM_FOCPG_EXT void Init_FOCPG(void);
CM_FOCPG_EXT void TB1_ModeSelect(void);
CM_FOCPG_EXT void TB1_FOCPG(void);
CM_FOCPG_EXT void TB2_FOCPG(void);
CM_FOCPG_EXT void TB3_FOCPG(void);

/* Exported Variable List ======================================*/

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/