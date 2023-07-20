/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-VL

Filename: CM_FOCPM.H

Partner Filename: CM_FOCPM.C

Description: This is a inclue file of CM_FOCPM.C

Complier: 

	
History:

===============================================================*/
#ifdef _CM_FOCPM_C
   #define CM_FOCPM_EXT 
#else
   #define CM_FOCPM_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
CM_FOCPM_EXT void TB1_FOCPM(void);		//ADDED BY SCOTTY 01/29/2007
CM_FOCPM_EXT void TB2_FOCPM(void);		//ADDED BY SCOTTY 01/29/2007
CM_FOCPM_EXT void TB3_FOCPM(void);		//ADDED BY SCOTTY 01/29/2007
CM_FOCPM_EXT void PPI_FOCPM(void);

/* Exported Variable List ======================================*/

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2007 IABU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/