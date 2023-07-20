/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _CM_VF_C
   #define CM_VF_EXT 
#else
   #define CM_VF_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
CM_VF_EXT void Init_VF(void);
CM_VF_EXT void TB1_VFWsl_byPG(void);
CM_VF_EXT void TB1_VFCal_Slin(void);
CM_VF_EXT void set_VcmpMax(void);
CM_VF_EXT void set_Rs(void);
CM_VF_EXT void TB1_VFWsl_byEst(void);
CM_VF_EXT void TB1_NL_Boost(SWORD Vlimited);
CM_VF_EXT void TB1_VFtq_boost(void);
CM_VF_EXT void TB1_SVCtq_boost(void);
CM_VF_EXT void TB1_VF(void);
CM_VF_EXT void TB2_VF(void);
CM_VF_EXT void TB2_PM(void);
CM_VF_EXT void TB1_VFWsl_byAmp(void);

/* Exported Variable List ======================================*/
CM_VF_EXT UWORD          Ismax_uwPu,
                         Is_uwPu,
                         VF_Vcmd,
                         VF_uwVcmpMax,
                         fs_nonlinear, 
						 Tr;

CM_VF_EXT SWORD          VFTB1_swUoutPu,
                         VF_swUout,
                         VF_swSlip,
                         Is,
                         I2;

CM_VF_EXT SLONG          PowerInRe;

CM_VF_EXT SLONG          I1, 
						 I5, 
						 I6,
                         PG_integral,                         
                         Pin,
                         PowerIn,
                         slPowerInLPF,
                         QowerIn,
                         Power_S,
                         Culoss,
                         Coreloss,
                         PowerGap;
                         
CM_VF_EXT SLONG_UNION    VF_VcompPuLPF,
                         VF_SlipLPF,
                         VF_SlipLPF_out,   //[slip compensation function, Bernie, 2012/06/20]
                         VF_slIqeLPF,
                         VF_slIdeLPF;      

CM_VF_EXT ULONG          SlinI,
                         SlinF;

CM_VF_EXT SLONG_UNION    Inl_integral;

CM_VF_EXT UWORD          adjcnt;

CM_VF_EXT SWORD          tq_boost, 
						 nl_boost;
						 
//---ADDED BY DINO , Standstill,--
CM_VF_EXT SWORD
						HFI_swUoutPu,
                        HFI_swIqseOutPu,
/*                      AD_swIAPu_Max,
                        AD_swIBPu_Max,
                        AD_swICPu_Max,
                        AD_swIAPu_Min,
                        AD_swIBPu_Min,
                        AD_swICPu_Min,*/
                        AD_swIAPu_Diff,
                        AD_swIBPu_Diff,
                        AD_swICPu_Diff;

CM_VF_EXT UWORD	  		TB2Cnt,
                        IAPCnt, IANCnt, IBPCnt, IBNCnt, ICPCnt, ICNCnt,
						PhaseCnt,
//						AD_OK,
						uwTGain;		// add by dino, 2006/08/03
			
CM_VF_EXT UWORD			Start_Section,
						Start_Section_old,
						TUN_uwSection,
						Zpulse,
						uwPGInit; 
						
/*
CM_VF_EXT SLONG			AD_slIAPu_MaxSum,
						AD_slIBPu_MaxSum,
						AD_slICPu_MaxSum,
						AD_slIAPu_MinSum,
						AD_slIBPu_MinSum,
						AD_slICPu_MinSum;
*/
CM_VF_EXT UWORD			AD_uwIAPu_MaxSum,
						AD_uwIBPu_MaxSum,
						AD_uwICPu_MaxSum,
						AD_uwIAPu_MinSum,
						AD_uwIBPu_MinSum,
						AD_uwICPu_MinSum;

CM_VF_EXT SWORD
//		  				PM_swT[6],
		  				PM_swTmax,
						PM_swTmin;
//---The end, ADDED BY DINO , Standstill,--						                   
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
