/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _CM_TQCPG_C
   #define CM_TQCPG_EXT 
#else
   #define CM_TQCPG_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
CM_TQCPG_EXT void Init_TQCPG(void);
CM_TQCPG_EXT void TB1_TQCPG(void);
CM_TQCPG_EXT void TB2_TQCPG(void);
CM_TQCPG_EXT void TB3_TQCPG(void);

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