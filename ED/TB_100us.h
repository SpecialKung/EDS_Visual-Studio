/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _TB_100us_C
   #define TB_100us_EXT 
#else
   #define TB_100us_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
TB_100us_EXT void TimeBase_100us(void);
/* Exported Variable List ======================================*/
TB_100us_EXT void OPHL_Detection(void);    //[New OPHL Function,Jerry.SK,2019/12/28]
TB_100us_EXT void OPHL_Init(void);  //[New OPHL Function,Jerry.SK,2021/07/22]


/*== Local Variable List (Variables not open to other files)  ==*/
TB_100us_EXT UWORD	TB_uw100usCnt;
TB_100us_EXT UWORD 	TB_uwPg_Cnt;	// Test, Sean, 12/30




TB_100us_EXT SWORD		OPHL_swIqss,
						OPHL_swIdss,
						OPHL_swIqss_cmd,
						OPHL_swIdss_cmd,
						OPHL_swCur_err;

TB_100us_EXT UWORD		OPHL_uwTheta,
						OPHL_uwTheta_Z1,
						OPHL_uwDeltaTheta,
						OPHL_uwDeltaTheta_Filter,
						OPHL_uwAPhZeroCnt,
						OPHL_uwBPhZeroCnt,
						OPHL_uwCPhZeroCnt,
						OPHL_uwAPhZeroState,
						OPHL_uwBPhZeroState,
						OPHL_uwCPhZeroState,
						OPHL_uwCurZeroState;
						//CRM_uwTheta

TB_100us_EXT SWORD		OPHL_swEst_Sp_Filter,
						OPHL_swEst_Sp_Filter_Z1,
						OPHL_swEst_Sp_Error,
						OPHL_swEst_Err_Cnt,
						OPHL_swEst_Err_State,
						OPHL_swEst_Det_Delay,
						OPHL_swCur_err_Filter,
						OPHL_swCur_err_Limit;

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
