/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _dq2abc_C
   #define DQ2ABC_EXT 
#else
   #define DQ2ABC_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
DQ2ABC_EXT void dq2abc(void);
DQ2ABC_EXT void Curdq2abc(SWORD Iqss, SWORD Idss);
/* Exported Variable List ======================================*/
DQ2ABC_EXT SWORD          T23_swUqssInPu,
                          T23_swUdssInPu;

DQ2ABC_EXT SWORD          T23_swUasOutPu,
                          T23_swUbsOutPu,
                          T23_swUcsOutPu;

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/