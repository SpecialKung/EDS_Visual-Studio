/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _CurrentReg_C
   #define CUR_EXT 
#else
   #define CUR_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
CUR_EXT void Init_CurrentReg(void);
CUR_EXT void TB1_CurrentReg(void);
CUR_EXT void CurrentReg_daxis(void);
CUR_EXT void CurrentReg_qaxis(void);

/* Exported Variable List ======================================*/
CUR_EXT  UWORD            CUR_uwqKpPu,
                          CUR_uwqKiPu,
                          CUR_uwdKpPu,
                          CUR_uwdKiPu;

#pragma address CUR_swIqseFdbPu=0x0000a124    //[Address fixed, Aevin, 2017/06/28]
#pragma address CUR_swIdseFdbPu=0x0000a128    //[Address fixed, Aevin, 2017/06/28]
CUR_EXT  SWORD            //CUR_swIqseRefPu,
                          //CUR_swIdseRefPu,
                          CUR_swIqseRefPuOld,
                          CUR_swIqseFdbPu,
                          CUR_swIdseFdbPu,
                          CUR_swUqseOutPu,
                          CUR_swUdseOutPu;

CUR_EXT  SLONG            CUR_slIqInteg,
                          CUR_slIdInteg,
                          CUR_slWindUp;
                          
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/