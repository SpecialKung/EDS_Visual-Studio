/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _SpDtPG1_C
   #define SpDtPG1_EXT 
#else
   #define SpDtPG1_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
SpDtPG1_EXT void Init_SpDtPG1(void);
SpDtPG1_EXT void Init_SpDtPG1_pr(void);
SpDtPG1_EXT void ISR_SpDtPG1(void);
SpDtPG1_EXT void TB3_SpDtPG1(void);
SpDtPG1_EXT void TB3_PGErrProcess(void);
SpDtPG1_EXT void TB3_SpDtPG1_LoIv(void);
SpDtPG1_EXT void TB3_SpDtPG1_Err(void);
SpDtPG1_EXT void TB2_SpDtPG1(void);
SpDtPG1_EXT void PGDIR_Detect(void); //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]


/* Exported Variable List ======================================*/
SpDtPG1_EXT UBYTE	SpDt_ubT0OverCnt,
					SpDt_ubT0OvCnt_New,
					SpDt_ubT0OvCnt_Old,
/* Item 46: Marked					SpDt_ubPGLossDtCnt, */
					SpDt_ubPG1PoNePusCnt,	// have Positive & Negative pulse
					SpDt_ubT1OverCnt,		//16384 TEST, scotty, 05/10/2007
					SpDt_ubT1UderCnt,		//16384 TEST, scotty, 05/10/2007
/* Item 46: Marked					SpDt_uwPGErrTmp, */
                    SpDt_ub100usCnt;
//            		SpDt_ubPGLOSSCnt,
//SpDtPG1_EXT UBYTE   SpDt_ubPGCard;    //Move to Pr_handle.h //[Modify PG Type Define, Bernie, 12/05/2011]    

SpDtPG1_EXT UWORD	SpDt_uwPG1CNT_New,
					SpDt_uwPG1CNT_Old,
					SpDt_uwPG1Wdh_New,
					SpDt_uwPG1Wdh_Old,
					SpDt_uwPG1LoSpdCNT_Old,
					SpDt_uwPG1LoSpdCNT_Z1,
					SpDt_uwPG1CNT,
					SpDt_uwPG1CNT_Org,
					SpDt_uwPG1CNT_OrgNoMx,
					SpDt_uwChanLeRe,
					SpDt_uwHiLPG,
					SpDt_uwLoLPG,
					SpDt_uwPGErrDet,
					SpDt_uwOvSpdDet,
					SpDt_uwSpdDeDet,
					SpDt_uwPGF1ErrCnt,
					SpDt_uwPGLossCnt,
					SpDt_uwPGLossCnt1,
					SpDt_uwPGLossCnt2,
					SpDt_uwPGLossCnt3,			// PG Loss Hardware Detected counter, add by DINO, 05/18/2008
					SpDt_uwPGLossCnt4,			// Absolute PG Loss Detected counter, add by DINO, 06/12/2008
					SpDt_uwOvSpdCnt,
					SpDt_uwSpdDeCnt,
                    SpDt_uwPG1100usCNT_Old,
                    SpDt_uwPGcorrectvalue,		// Added by SC, 09/26/2007
                    SpDt_uwFfbk,
                    SpDt_uwPGCDin_old,    //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
                    SpDt_uwPGABin_old,    //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
                    SpDt_uwNoground_CNT,  //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]				// Add by dino, 05/30/2007
                    SpDt_uwAccCalcul,     //[Over Acceleration protection function, Bernie, 2017/02/13]
                    SpDt_uwAccOpt,
                    SpDt_uwAccCalculOld;

SpDtPG1_EXT UWORD   OverAccTimeSet,
                    uwOverAccLev,
                    uwOverAccCnt;


SpDtPG1_EXT SLONG_UNION 
					AccTemp_LPF;   		//[Over Acceleration protection function, Bernie, 2017/02/13]

SpDtPG1_EXT SLONG 
					SpDt_slPG1FdbPu_temp,
                  	SpDt_slPG1FdbPu_temp1;

					
SpDtPG1_EXT SWORD	SpDt_swPG1LoSpdCNT_Err,
					SpDt_swPG1CNT_ErrOld,
					SpDt_swPGecycle,			// Added by SC, 09/26/2007
                    SpDt_sw500usCNT_Err,
                    SpDt_sw40ms_tmp,
                    SpDt_sw200ms_Flag,
                    SpDt_swPGCDerr_Detect,
                    SpDt_swNoground_CNT,	//[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
                    SpDt_swCDerrold; 		//[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]

SpDtPG1_EXT ULONG	SpDt_ulPG1Npulse,
					SpDt_ulPG1NpulseNoMx,
					SpDt_ulPG1Kmt_HiPus,
					SpDt_ulPG1Kmt_HiPus1,
					SpDt_ulPG1Kmt_LoPus,
                    SpDt_ulKTheta,
					SpDt_ulThetaR,
                    SpDt_ulPG1Kmt_100us;

SpDtPG1_EXT SLONG	SpDt_slPG1FdbPu,
					SpDt_slOvSpdLePu,
					SpDt_slSpdDeLePu;
					
SpDtPG1_EXT UWORD	/* Item 46: Marked:
					SpDt_uwPG1ChkCNT,
					SpDt_uwPG100usCNT,
					SpDt_uwPG1CNT_Z1; /*  */
					SpDt_uwPGErrTmp,	/* Item 46: Moved */
					SpDt_uwPG1CNT_Save;

SpDtPG1_EXT SLONG_UNION  PGABerr_add,
                         PGABerr_add_old,
                         PGCDerr_add,
                         PGCDerr_add_old,
                         PGABerr_LPF,
                         PGCDerr_LPF; //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]


/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
