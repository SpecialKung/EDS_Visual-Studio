/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _SpeedReg_C
   #define SPR_EXT volatile
#else
   #define SPR_EXT extern volatile
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
SPR_EXT void SpeedReg(void);
SPR_EXT void Init_SpeedReg(void);
SPR_EXT void TB1_SpeedReg(void);
SPR_EXT void TB2_SpeedReg(void);
SPR_EXT void SPR_FFD(void);						//ADDED BY SCOTTY	01/04/2007

/* Exported Variable List ======================================*/
SPR_EXT  UBYTE			  SPR_ubASRCnt,
//						  SPR_ubT1UnderCntNEW,	//ADDED BY SCOTTY 10/11/2007
						  SPR_ubT1UnderCntOLD,	//ADDED BY SCOTTY 10/11/2007
//						  SPR_ubT1OverCntNEW,	//ADDED BY SCOTTY 10/11/2007
						  SPR_ubT1OverCntOLD;	//ADDED BY SCOTTY 10/11/2007
						  
SPR_EXT  UWORD            SPR_uwKpPu,
                          SPR_uwKpKiPu,
                          SPR_uwKrPu,
                          SPR_uwTqLPG,
                          SPR_uwKpKiGain,
			  			  SPR_uw_posCtime,		//ADDED BY SCOTTY 03/11/2008                       
                          SPR_uwKrGain,
                          SPR_uwPPILPG;			// PPI LPF Gain, DINO, 07/28/2010

SPR_EXT  SWORD            SPR_swIqseRefPu,
						  SPR_swIqseRefLimPu,
						  SPR_swTqRefPu,
//						  SPR_swFFD,			//ADDED BY SCOTTY
						  sw_fcomerr,       	//ADDED BY SCOTTY
						  swTqInPu,
						  swTqInPu_Mon,			//[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]	//ADDED BY SCOTTY 
                          SPR_swIqseFWDMPu,
                          SPR_swIqseFWDRPu,
                          SPR_swIqseREVMPu,
                          SPR_swIqseREVRPu,
                          SPR_swPIVUVCnt,
                          SPR_swTqOfstPu;		// Iqe Compensation of New PPI Control, DINO, 07/29/2010

SPR_EXT  SLONG            SPR_slSpdRefPu,
                          SPR_slSpdFdbPu,
                          SPR_slSpdInteg,
						  SPR_slIqseRefPu_LP,
                          SPR_slSpdRefPu_Old,
                          SPR_slspdFFDPu,
                          SPR_slspePIFout,		//ADDED BY SCOTTY
                          SPR_slTqRefLimPu,		//ADDED BY SCOTTY, 05/10/2007
                          SPR_sltest,			//ADDED BY SCOTTY 07/18/2007
                          SPR_slIqseTurqRefPu,	//ADDED BY SCOTTY 10/31/2007
                          SPR_slSpdSatPu,
						  SPR_slIqseLimit,
			  			  SPR_slPIVthidaCom,	//PPI Control Position Command, DINO, 06/03/2010
			  			  SPR_slPIVthidaFbk,	//PPI COntrol Position Feedback, DINO, 06/03/2010
			  			  SPR_slPIVThidaErr,
			  			  SPR_slPIVInteg;

SPR_EXT  ULONG            SPR_ulThetaRef,
						  SPR_ulPIVKp,			//ADDED BY SCOTTY 10/11/2007 
                          SPR_ulThetaFdb,
                          SPR_ulSpdRefPuLPF2;	// LPF of SPR_slSpdRefPu of Low WORD, DINO, 07/28/2010
                         
SPR_EXT  SLONG_UNION	  SPD_slPOScon,			//SCOTTY 03/11/2008
						  SPR_IqseRefPuLPF,
						  SPR_SpdRefPuLPF,		// LPF of SPR_slSpdRefPu of High WORD, DINO, 07/28/2010
						  SPR_TqOfstPu;			// Iqe Compensation of New PPI Control, DINO, 07/29/2010

SPR_EXT SWORD     		  SPR_swSCTEST0,
						  SPR_swSCTEST1,
						  SPR_swSCTEST2,
						  TB1_swPGQualityDsp;       //[PG quality function, Bernie, 2017/06/20]


SPR_EXT SWORD            SPR_swPGoverflwCnt,        //[PG quality function, Bernie, 2017/06/20]
                         SPR_swPGoverflwCnt_old;    //[PG quality function, Bernie, 2017/06/20]

SPR_EXT SWORD			 SPR_swPPI_Cmp;
SPR_EXT	Float32			 COF_flPPI_Cmp;

SPR_EXT	Bool			 SPR_blPPI_Cmp_Updat_Flag;
SPR_EXT ULONG            SPR_ulPGQualityCnt;        //[PG quality function, Bernie, 2017/06/20]

SPR_EXT UWORD            SPR_uwPGTCNT,              //[PG quality function, Bernie, 2017/06/20]
                         SPR_uwPGTCNT_old,          //[PG quality function, Bernie, 2017/06/20]
                         SPR_uwPGDIR,               //[PG quality function, Bernie, 2017/06/20]
                         SPR_uwPGDIRCnt,            //[PG quality function, Bernie, 2017/06/20]
                         SPR_uwPGDIRRec,            //[PG quality function, Bernie, 2017/06/20]
                         TB1_uwPGQuality_1sec,
                         TB1_uwPGQualityZcnt;      //[PG quality function, Bernie, 2017/06/20]
SPR_EXT  SLONG			 SPR_slSpdErrPuLimit;      //#15977, Spd_err*kp overflow protect, James, 2021/04/01

                 
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
