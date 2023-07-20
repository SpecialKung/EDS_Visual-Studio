/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _CurrentMod_C
   #define CRM_EXT 
#else
   #define CRM_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
CRM_EXT void Init_CurrentMod(void);
CRM_EXT void CurrentMod_PG(void);
CRM_EXT void CurrentMod_noPG(void);

CRM_EXT void CurrentMod_PMPG(void);    //ADDED BY SCOTTY 2006/06/06
/* Exported Variable List ======================================*/
CRM_EXT UWORD             CRM_uwTheta,
						  CRM_uwaxisCOR,	//ADDED BY SCOTTY 2007/07/17
                          CRM_SinSection;

CRM_EXT UWORD             CRM_uwSinIndex,
                          CRM_uwCosIndex;

CRM_EXT SWORD             SinValue,
                          CosValue,
                          CRM_swThetaStep,
                          CRM_swIqPu,
                          CRM_swIdPu;
                          
CRM_EXT ULONG             CRM_ulThetaR,
                          CRM_ulThetaSL;

CRM_EXT SLONG			CRM_slSpdPu,
						CRM_slWslPu;
//						CRM_slFlxFreqPu,
//						CRM_slImPu;                          

CRM_EXT SLONG_UNION		CRM_ImPuLPF;

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
