/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _COEFhandel_C
   #define COEF_EXT 
#else
   #define COEF_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
COEF_EXT void COEFInitOnce(void);
COEF_EXT void Motor1Pr(void);
COEF_EXT void Motor2Pr(void);
COEF_EXT void Motor3Pr(void);		// Add by DINO, 09/09/2008
COEF_EXT void MotorPrSel(void);		// Add by DINO, 09/09/2008
COEF_EXT void TQRBaseInit(void);
COEF_EXT void TQRMaxInit(void);
COEF_EXT void MotorPrInit(void);
COEF_EXT void VFPG_Init_SlipMax(void);
#if StandStill
COEF_EXT void STDutyInit(void);		// dino, 2006/08/15
#endif

/* Exported Variable List ======================================*/
COEF_EXT UBYTE  COF_ubMPolePair,
                COF_PolePair,
                COF_Poles,
			  	AD_AUIadChkCnt,
			  	AD_AVIadChkCnt;	// CalUBYTE: 5 UBYTE
                          
COEF_EXT UWORD  COF_uwVbRe,
                COF_uwFbRe,
                //COF_uwIbRe, // Jerry.sk.tseng for GFC High elecator 2021/08/17
                COF_uwRbRe,
                COF_uwLbRe,
                COF_uwTbRe,
                COF_uwJbRe,
                COF_uwPbRe,
                COF_uwVratePu,
                COF_uwMIratePu,
                COF_uwIIratePu,
                COF_uwI0Pu,
                COF_uwFslipRate,                          
                COF_uwFRatePu,
                COF_uwFslipMAX,
                COF_uwCTIratePu,
                COF_uwVTIratePu,
                COF_uwTqrateRe,
                COF_uwTqratePu,
                COF_uwTqMaxPu, 
                COF_uwSSIratedPu, 	//ADDED by dino
                COF_uwImotorNP,		//ADDED by dino, 03/09/2007
                COF_uwSPDPMFFD,		//ADDED BY SCOTTY 	01/07/2007                         
                COF_uwIdsLPG,
                COF_uwVEPSPu,
                COF_uwFepsLimit,		//EPS limit freq., Add by dino, 05/22/2008
                COF_uwTqSlopePu;	//Torque decrease slope, add by dino, 05/29/2008

COEF_EXT UWORD  COF_uwRrPu,
                COF_uwRsPu,
                COF_uwLxPu,
                COF_uwLmPu,
                COF_Tr_inv,
                COF_uwKt,
                Rs,
                COF_uwZoffset;

COEF_EXT ULONG  COF_ulKTheta,
                COF_ulFslipRatePu,
                COF_ulFslipMAXPu,
                COF_ulIbRe;  // Jerry.sk.tseng for GFC High elecator 2021/08/17

COEF_EXT UWORD  COF_uwMIrRe,
                COF_uwMPRe,
                COF_uwRPMRe,
                COF_uwPole,
//                COF_uwElecPole,   // dino, 05/17/2007
                COF_uwMI0Re,
                COF_uwMRsRe,
                COF_uwMLmRe,  	//6925j
				COF_uwMFrRe,		// Motor Rated Freq. calculated by Motor RPM, dino, 06/03/2009
				COF_uwVUPSRe,
				COF_uwSlipRe;        //[slip compensation function, Bernie, 2012/06/20]


#pragma address uwtest1=0x0000a140           //[Address fixed, Aevin, 2017/06/28]
#pragma address uwtest2=0x0000a142
#pragma address uwtest3=0x0000a144
#pragma address uwtest4=0x0000a146
#pragma address uwtest5=0x0000a148
#pragma address uwtest6=0x0000a14a
#pragma address uwtest7=0x0000a14c
#pragma address uwtest8=0x0000a14e
#pragma address uwtest9=0x0000a150
#pragma address uwtest10=0x0000a152
#pragma address uwtest11=0x0000a154
#pragma address uwtest12=0x0000a156
#pragma address uwtest13=0x0000a158
#pragma address uwtest14=0x0000a15a
#pragma address uwtest15=0x0000a15c
#pragma address uwtest16=0x0000a15e
#pragma address uwtest17=0x0000a160
#pragma address uwtest18=0x0000a162
#pragma address uwtest19=0x0000a164
#pragma address uwtest20=0x0000a166
#pragma address uwtest21=0x0000a168
#pragma address uwtest22=0x0000a16a
#pragma address uwtest23=0x0000a16c
#pragma address uwtest24=0x0000a16e
#pragma address uwtest25=0x0000a170

COEF_EXT UWORD	COF_uwIm1Pu,
              	COF_uwRs1Pu,
              	COF_uwRr1Pu,
              	COF_uwLm1Pu,
              	COF_uwLx1Pu,
              	COF_uwIm2Pu,
              	COF_uwRs2Pu,
              	COF_uwRr2Pu,
              	COF_uwLm2Pu,
              	COF_uwLx2Pu,
              	COF_uwIm3Pu,
              	COF_uwRs3Pu,
              	COF_uwRr3Pu,
              	COF_uwLm3Pu,
              	COF_uwLx3Pu,
              	COF_uwTctrTb2Pu,
              	COF_uwKUdcPuCnv,
              	COF_uwPassWord,
              	uwtest1,
              	uwtest2,
              	uwtest3,
              	uwtest4,
              	uwtest5,
              	uwtest6,
              	uwtest7,
              	uwtest8,
              	uwtest9,
              	uwtest10,
              	uwtest11,
              	uwtest12,
              	uwtest13,
              	uwtest14,
              	uwtest15,
              	uwtest16,
              	uwtest17,
              	uwtest18,
              	uwtest19,
              	uwtest20,
              	uwtest21,
              	uwtest22,
              	uwtest23,
              	uwtest24,
              	uwtest25,
              	COF_uwVBase1_4,
              	COF_uwVBase1_8,
              	COF_uwFBase1_4,
              	COF_uwFBase3_10,
              	COF_uwI0DtLPu,		// Add by DINO, 06/29/2009
				COF_uwBemfPu;		// Motor BEMF, phase to phase, rms, Add by DINO, 06/03/2009

COEF_EXT SLONG	COF_sltest1;		//ADDED BY DINO

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
