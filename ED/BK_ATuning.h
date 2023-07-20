/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _ATUNING_C
   #define TUNING_EXT 
#else
   #define TUNING_EXT extern
#endif

/* Function Call ==============================================*/
TUNING_EXT void DBC_Init(void);
TUNING_EXT void DBC_VarInit(void);
TUNING_EXT void DBC_HandelOK(void);
TUNING_EXT void DBC_Calibration(void);
TUNING_EXT void DBC_PROCESS_TB2(void);
TUNING_EXT void TUN_StartInit(void);
TUNING_EXT void TUN_DC_Cmd(void);
TUNING_EXT void TUN_DC_CalRs(void);
TUNING_EXT void TUN_PMLS_3Section(void);		//ADDED BY SCOTTY 2006/09/12
TUNING_EXT void TUN_CalPMLS(void);				//ADDED BY SCOTTY 2006/09/13
TUNING_EXT void TUN_PGZ_Section(void);			//ADDED BY SCOTTY 2007/06/01
TUNING_EXT void TUN_CAL_ZOFFSET(void);			//ADDED BY SCOTTY 2007/06/04
TUNING_EXT void TUN_ZOFFSET(void);				//ADDED BY DINO 08/12/2008
TUNING_EXT void TUN_HFSS_4SectionCmd(void);
TUNING_EXT void TUN_HFSS_CalRrL1sigma(void);
TUNING_EXT void TUN_HFSSTB2_OK(void);
TUNING_EXT void TUN_NLRotaryTB2_INLm(void);
TUNING_EXT void TUN_NLRotary_OK(void);
TUNING_EXT void TUN_CalLmbyPr(void);
TUNING_EXT void Static_Test1(void);
TUNING_EXT void Rolling_Test1(void);
TUNING_EXT void CurGainPWMSetup(void);
TUNING_EXT void CurGainCalib(void);
TUNING_EXT void TUN_ACSmpl(void);
TUNING_EXT void TUN_CalcEmLmN(void);
TUNING_EXT void TUN_CalcZLFSL(SLONG slPPu, SLONG slQPu, SLONG slUsqrPu, SLONG slIsqrPu, UWORD CatchPoint);
TUNING_EXT void TUN_LFSLIdle(void);
TUNING_EXT void TUN_LFSLInit(void);
TUNING_EXT void TUN_LFSLTB1(void);
TUNING_EXT void MRAS_LPF(void);
TUNING_EXT void MRAS_RefBEMF(void);
TUNING_EXT void MRAS_RefQ(void);
TUNING_EXT void TUN_AQR(void);
TUNING_EXT void TUN_LFSLTB2(void);
TUNING_EXT void TUN_ProcessTB2(void);

TUNING_EXT UWORD          DBC_period,
                          DBC_uwDuty_t_10K,
                          DBC_uwD_u_10KUcom,
                          uwCurCalibRatio;                          

TUNING_EXT SLONG          DBC_slCMPUaInt,
                          DBC_slDuty_10KI1,
                          DBC_slDuty_10KI2,
                          DBC_slDuty_5KI1,
                          DBC_slDuty_5KI2,
                          DBC_slUdc_10KI1,                          
                          DBC_slUdc_10KI2,
                          DBC_slUdc_5KI1,                          
                          DBC_slUdc_5KI2,
                          CCB_slIaSum,
                          CCB_slIbSum;

TUNING_EXT UWORD          TUN_Sector,
						  TUN_TESTCNT,			//TEST   scotty
                          TUN_Method;

TUNING_EXT UWORD          TUN_TuningCNT,		
                          TUN_IntegralCnt,
                          TUN_CatchPoint,
                          TUN_uwTB1CNT,
                          TUN_uwUd_K,
                          TUN_uwLSCNT,			//ADDED BY SCOTTY 2006/09/12
                          TUN_uwLSCNT1,			//ADDED BY SCOTTY 2006/09/12
                          TUN_STEPANGMAX,		//ADDED BY SCOTTY 2007/06/01
                          TUN_STEPANG,			//ADDED BY SCOTTY 2007/06/01
                          TUN_Z_COMFIRM,		//ADDED BY SCOTTY 2007/06/01
                          TUN_Z_CAPTURECNT,		//ADDED BY SCOTTY 2007/06/01
                          TUN_Z_CAPTURECNTZ,	//ADDED BY SCOTTY 2007/06/01
                          TUN_Z_COUNT,			//ADDED BY SCOTTY 2007/06/04
                          PG_Zoffset,			//ADDED BY SCOTTY 2007/06/04
                          TUN_SINDATAMAX,		//ADDED BY SCOTTY 2007/06/05
                          TUN_COSDATAMAX,		//ADDED BY SCOTTY 2007/06/05
                          TUN_SINDATAMIN,		//ADDED BY SCOTTY 2007/06/05
                          TUN_COSDATAMIN,		//ADDED BY SCOTTY 2007/06/05 
                          SpDt_uwAnglePeriod,	//ADDED BY SCOTTY 2007/06/05
                          SpDt_uwPG1CNT_Org1,                          
                          TUN_TunLSCNT,
                          TUN_uwLSTmax,
                          TUN_uwLSTmin,
                          TUN_uwLSTIME,			//ADDED BY SCOTTY 2006/09/12
                          TUN_uwVdout,			//ADDED BY SCOTTY 2006/11/03
                          TUN_uwUVWsector,		//ADDED BY SCOTTY 2006/11/06
                          TUN_uwImNRatioPu,
                          TUN_uwQfRatioPu,
                          TUN_uwEmNPu,
                          TUN_uwImNPu,
                          TUN_uwIdCurr,			//Zoffset tuning current, add by DINO, 07/21/2008
                          TUN_uwInitTheta,
                          TUN_uwPMTunCnt,		//ADDED BY SCOTTY 01/29/2007
                          PG_Zoffset_1387;      // [IED 1387 static Tune, 2011/07/06]

TUNING_EXT SWORD          TUN_swIdseRefPu,
                          TUN_swIdseFdbPu,
                          TUN_swUoutPu,
                          TUN_swUaPu,
                          TUN_swUbPu,
                          TUN_swUalfa,
                          TUN_swUbeta,
                          TUN_UalfaZ1,
                          TUN_UbetaZ1,
                          TUN_VoltInP,
                          TUN_VoltInQ,                          
                          TUN_swUqssPuZ1,
                          TUN_swZANGLE,			//ADDED BY SCOTTY 2007/06/13
                          TUN_swIhigh,			//ADDED BY SCOTTY 2006/09/12
                          TUN_swImid,			//ADDED BY SCOTTY 2006/09/12
                          TUN_swIlow;			//ADDED BY SCOTTY 2006/09/12

TUNING_EXT SLONG          TUN_slUdIntPu,
                          TUN_slIphS1,
                          TUN_slUphS1,
                          TUN_slIphS2,
                          TUN_slUphS2,
                          TUN_slFreqPu,
                          TUN_slIsqr,
                          TUN_slUsqr,
                          TUN_slP,
                          TUN_slQ,
                          TUN_slP1,
                          TUN_slQ1,
                          TUN_slP2,
                          TUN_slQ2,                          
                          TUN_slPQSquare,
                          TUN_slXpu,
                          TUN_slLFSLFminPu,
                          TUN_slFcmdPuMax,
                          TUN_slIqIntePu;
                          

TUNING_EXT SLONG          TUN_HFSS_P_I1F1,
                          TUN_HFSS_P_I1F2,
                          TUN_HFSS_P_I2F1,
                          TUN_HFSS_P_I2F2,
                          TUN_HFSS_I_I1F1,
                          TUN_HFSS_I_I1F2,
                          TUN_HFSS_I_I2F1,
                          TUN_HFSS_I_I2F2,
                          TUN_slI0sqr,
                          TUN_slI0Sqr6,
                          TUN_slI0Sqr5,
                          TUN_slI0Sqr4,
                          TUN_slI0Sqr3,
                          TUN_slI0Sqr2,
                          TUN_slI0Sqr1,
                          TUN_slX6,
                          TUN_slX5,
                          TUN_slX4,
                          slXsNPu,
                          slEsNPu;
                          

TUNING_EXT UWORD          TUN_uwRsPu,
                          TUN_HFSS_R_F1,
                          TUN_HFSS_R_F2,
                          TUN_HFSS_R_F0,
                          TUN_uwRrPu,
                          TUN_uwL1sigmaPu,
                          TUN_uwLm1Pu,
                          TUN_uwLmPu,
                          TUN_uwI0Pu,
                          TUN_uwLmx6Pu,
                          TUN_uwLmx5Pu,
                          TUN_uwLmx4Pu,
                          TUN_uwLmxPu,
                          TUN_uwLmx2Pu,
                          TUN_uwLmx1Pu;

TUNING_EXT UWORD          mrs_LpfKit,
                          TUN_uwTheta,
                          TUN_uwSinIndex,
                          TUN_uwCosIndex,
                          uwXPu,
                          uwRPu,
                          uwIsPu,
                          uwX1Pu,
                          uwIs1Pu,
                          uwX2Pu,
                          uwIs2Pu,
                          uwTrPu;

TUNING_EXT SWORD          swEalfaPu,
                          swEbetaPu,
                          swIalfaOldPu,
                          swIbetaOldPu;

TUNING_EXT SLONG          slUalfaPuLPF,
                          slUbetaPuLPF,
                          slIalfaPuLPF,
                          slIbetaPuLPF,
                          slQRefPu,
                          slQFdbPu;
                          
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
