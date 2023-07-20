/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _BK_APR_C
   #define BK_APR_EXT 
#else
   #define BK_APR_EXT extern
#endif
/*======= Modules used (included header files) ==================*/

/*========== @ Defines =========================================*/

/* Struct Type define =========================================*/

/* Function Call ==============================================*/
BK_APR_EXT void APR_PScurve(void);
BK_APR_EXT void TB1_APRExeFun(UWORD PGRef, UWORD PGFbk);
BK_APR_EXT void EnterAPRExe(void);
BK_APR_EXT void TB1_PositionControl(void);
/* Exported Variable List ======================================*/
BK_APR_EXT UBYTE	APR_ubZChkCnt,
					APR_ubTemp,
					APR_ubMultiP;
					
BK_APR_EXT UWORD	APR_uwZarray[8];

BK_APR_EXT UWORD	APR_uwTheta,
					APR_uwThetaNoMx,
					APR_uwThetaPu,
					APR_uwP2PMem,
					APR_uwZOServoP,
					APR_ZeroTheta,
					APR_ZeroThetaOld,
					APR_uwPTarget,
					APR_uwZpulseCnt,
					APR_uwPCom,
//					APR_uwPG2PCom,		// Move to A_Monitor.h, 11/04/2008
					APR_uwPG2PComOld,
//					APR_uwZPosition,	// Move to A_Monitor.h, 11/04/2008
					APR_uwPFbk,
					APR_uwThetaO,
					APR_uwThetaO2,
					APR_uwPGHome,
					APR_uwDistance,
					APR_uwOnPCNT,
//					APR_uwPGPosition,	// Move to A_Monitor.h, 11/04/2008
					APR_uwPGCycle,
					ZCyclePeriod,
					ZCycleCNT;

BK_APR_EXT SLONG	APR_slSpdCmd;

BK_APR_EXT ULONG_UNION	Psacc,
						Pacc,
						PsaccMax,
						VcomFmax;

BK_APR_EXT SLONG_UNION	APR_slZPLPF;
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
