/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _TB_1ms_C
   #define TB_1ms_EXT 
#else
   #define TB_1ms_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
TB_1ms_EXT void PG_speed_search(void);
TB_1ms_EXT void Restart_Prog(void);
TB_1ms_EXT void Speed_Search(void);
TB_1ms_EXT ULONG acc_decel(void);
TB_1ms_EXT void chk_stallc(void);
TB_1ms_EXT void ScurveAcc(void);
TB_1ms_EXT void ScurveDec(void);
TB_1ms_EXT void ScurveDec_CRIPLS(void); // [IODLC, Lyabryan, 2016/11/11]
TB_1ms_EXT void accelerate(void);
TB_1ms_EXT void SmartStallCNew(void);
TB_1ms_EXT void SmartStallVNew(void);                                
TB_1ms_EXT void chk_stallv(void);
TB_1ms_EXT void decelerate(void);
TB_1ms_EXT void Fx2VmCompare(VFTableStruct *VFComp,UWORD f1,UWORD v1,UWORD f2,UWORD v2);
TB_1ms_EXT UWORD GetFx2Vm(UWORD fx);
TB_1ms_EXT void Run_Execute(void);
TB_1ms_EXT void Stop_Execute(void);
TB_1ms_EXT void CarryHandel(void);
TB_1ms_EXT void AFM_Output(void);
TB_1ms_EXT void AFM_Output_GFC(void);     //[APP01 IO carde support, Bernie, 2013/03/20]
TB_1ms_EXT void DFM_Calculate(void);
TB_1ms_EXT void PID_Fbk_Process(void);
TB_1ms_EXT void PID_Ctrl(void);
TB_1ms_EXT void PID_Loss(void);
TB_1ms_EXT void PID_Deviation(void);
TB_1ms_EXT void PID_Sleep(void);
TB_1ms_EXT void TB1_Scale_PG(void);
TB_1ms_EXT void TB1_FOCPGSpdWait(void);
TB_1ms_EXT void TB1_YDSwitchFun(void);
TB_1ms_EXT void TimeBase_500us(void);
TB_1ms_EXT void TimeBase_1ms(void);
TB_1ms_EXT void WgOff2Sby(void);
TB_1ms_EXT void dci_ctrl(UWORD dci_ref, UWORD VLimit);
TB_1ms_EXT void MPHL_Detect(void); //add by Sampo, 05/12/2009
TB_1ms_EXT void dci_MPHL(UWORD dci_ref, UWORD VLimit); //added by Sampo ,05/12/2009
TB_1ms_EXT void Generation_DIR(void); // For generation dir, by Justin , 2010/04/27
TB_1ms_EXT void TimeBase_1msB(void);
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
TB_1ms_EXT void SIBO_STO_Safty(void);
#endif
TB_1ms_EXT void TB3_STO_Safty(void);
TB_1ms_EXT void STO_Truth_Table(void);
TB_1ms_EXT void ErrorAutoReset(void);     //[Add auto restart after fault, Bernie, 06/06/12]
TB_1ms_EXT void Pgz_Disconnect_Init(void);    //[Zphase broken, Lyabryan, 2016/09/01] 
TB_1ms_EXT void OverAccFunction(void);
TB_1ms_EXT void OverAccInit(void);
TB_1ms_EXT void Torq_Tune_Process(void); //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
TB_1ms_EXT void VFGenOrMot_DIR(void);
TB_1ms_EXT void EPS_NormalDetectCurrent(void);
TB_1ms_EXT void AccFunction(void);			//[Rationa 362631, Special.Kung]
TB_1ms_EXT void AccFunctionInit(void);		//[Rationa 362631, Special.Kung]

/* Exported Variable List ======================================*/
TB_1ms_EXT UBYTE		TB1_ub1msCnt,
                		TB1_ub100msCnt,
                		TB1_ub1secCnt,
                		TB1_ub500usCnt,
			  			TB1_ubOverWsCnt,	// CalUBYTE: 5 UBYTE
			  			TB1_ubErrCnt,		// Error detect delay time when power on, dino, 04/12/2007
                    	TB1_ubFOCPGSerCnt,	// CalUBYTE: 8 UBYTE
                    	TB1_MPHL_Buf,		// added by Sampo ,for MPHL Detect 05/12/2009
                    	ubPDO_TxCNT,        // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
                    	EPS_btDirect;

#pragma address TB1_uwBrkRunCnt=0x0000a12a       //[Address fixed, Aevin, 2017/06/28]
#pragma address TB1_uwBrkStopCnt=0x0000a12c
#pragma address TB1_uwMCRunCnt=0x0000a12e
#pragma address TB1_uwMCStopCnt=0x0000a130
#pragma address TB1_uwDCICnt=0x0000a136

TB_1ms_EXT UWORD		OLDelayT,
                		OLSEL,
                		uwGBPcnt,
                		saf_uwPGF5_Type,
                		PIDFcmd,
                		PID_LPG,
                		AFMOut[2],
                		uwIsDtL,
                		PGScaleDataTmp,
                		PGScaleData,
                		TB1_uwSTORSETCnt,
						TB1_uwSTObRESETCnt,
						TB1_uwSTOARESETCnt,
                		TB1_uwSOSRSETCnt,//[Sibocom SOS Warn, James, 2020/04/28]
                		uw_STOStatus,
                		uw_STOStatusOld,
//              		  PGScaleOut,
                		uwSIN_data,
                		uwCOS_data,
						TB1_uwBrkRunCnt, 
                		TB1_uwBrkStopCnt,
                		TB1_uwPIDLossCnt,
                		TB1_uwPIDDeviCnt,
                		TB1_uwSleepCnt,
                		TB1_uwCCCnt,
                		TB1_uwFanCnt,		// added by scotty 10/15/2007
                		TB1_uwFanCnt1,		// added by scotty 10/15/2007
                		TB1_uwMCRunCnt,		// added by scotty 12/04/2007
                		TB1_uwMCStopCnt,	// added by scotty 12/04/2007
                		TB1_uwSBKCnt,		// SBK delay time after RUNNING==STOP, add by dino, 12/14/2007
                		TB1_uwRYCnt,		// Relay delay counter, add by DINO, 05/22/2008
						TB1_uwOLCnt, 
						TB1_uwOT1Cnt,
						TB1_uwOT2Cnt,
						TB1_uwLVCnt, 
						TB1_uwBBCnt, 
						TB1_uwDCICnt,
                		TB1_uwKEBRtCnt,
                		TB1_uw0p5secCnt,
                		TB1_uwMaxFout,
                		TB1_uwNewIrmsAD,
                		uwEPScnt,         //[EPS, Sampo, 03/27/2011]
                        uwSt1387cnt,      // [IED 1387 static Tune, 2011/07/06] 
                        uwEPS_Delay_CNT,
                        uwEPS_Off_CNT,
                        TB1_uw1secCnt;
						
#pragma address TB1_uwStarConRunCnt=0x0000a132      //[Address fixed, Aevin, 2017/06/28]
#pragma address TB1_uwStarConStopCnt=0x0000a134

TB_1ms_EXT UWORD		TB1_uwStarConRunCnt,
                        TB1_uwStarConStopCnt;

                          
TB_1ms_EXT SLONG		PIDinteg_rem,
                		PIDintegral,
                		PID_slofsetv;
                         
TB_1ms_EXT SWORD		accel_error,
                		decel_error,
                		piderr,
                		piderr_Z1,
  			  			TB1_swCosphi,
                		cosphi_z1, 
                		delta_cosphi,
			  			TQRCMemswPer,
                		TB1_swMPHLcnt,		// added by Sampo, 05/12/2009
                		TB1_swMPHLstep,		// added by Sampo, 05/12/2009
                		TB1_swTempcnt,
                		TB1_swTemp1,
                		TB1_swTemp2,
                		TB1_swTemp3;		// added by Sampo, 05/12/2009

TB_1ms_EXT SLONG		//TB1_slSpdCmdPu,
                		TB1_slSpdSerPu;

TB_1ms_EXT SLONG_UNION	cosphiLPF,
						TH1adLPF,
						TH2adLPF,
						AVIadLPF,
						ACIadLPF,
						AUIadLPF,
						PTCInLPF,
						GFFadLPF,
						SINadLPF,
						COSadLPF,
						PGLadLPF;

TB_1ms_EXT ULONG_UNION  facc1,
                        facc2,
                        facc3,
                        facc4,
                        fdec1,
                        fdec2,
                        fdec3,
                        fdec4,
                        fjacc,
                        fjdec,
                        fdec5,
                        fdec_ESD,
                        facc,
                        fdec,
                        sacc,
                        sdec,
                        sdec_old,
                        sdec_tmp,
                        fdec_t2,
                        PIDoutf,
                        TB1_ulSpdtempPu,	//ADDED BY SCOTTY 02/05/2007
			  			Pfdec,
			  			TB1_CmdRpm;

TB_1ms_EXT ULONG_UNION  faccH1,      //[]
                        faccH2,
                        faccH3,
                        faccEMY,
                        fdecH1,
                        fdecH2,
                        fdecH3,
                        fdecEMY,
                        faccL1,      //[]
                        faccL2,
                        faccL3,
                        faccINS,
                        fdecL1,
                        fdecL2,
                        fdecL3,
                        fdecINS;

TB_1ms_EXT UWORD    	VFfslip_uwLPG,
                    	cosphi_uwLPG,
                    	VFVcomp_uwLPG,
                    	AUI1In_LPG,
                    	ACIIn_LPG,
                    	EPS_DIRtemp, //[ADCO EPS Modify]
                    	AUI2In_LPG,
                    	PTCIn_LPG,
                    	dcbusLPG,			//ADDED BY SCOTTY 09/05/2007
                    	PHL_LPG,			//ADDED BY SCOTTY 09/05/2007
                    	CurZero_LPG,
                    	APP01_uwSO1,      //[APP01 IO carde support, Bernie, 2013/03/20]
                    	APP01_uwSO2;       //[APP01 IO carde support, Bernie, 2013/03/20]

TB_1ms_EXT SWORD        EPS_swRecord_S1,
                        EPS_swRecord_CNT,
                        EPS_swRecord_AVG,
                        EPS_swRecord_up,
                        EPS_swRecord_dw,
						//[ //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
                        AUI_swoffset,
                        AUI_swgain,
                        AUI_swem_V,
                        AUI_swem_T,
                        AUI_swfl_V,
                        AUI_swfl_T;
						//] //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]

TB_1ms_EXT UWORD		TB1_uwPhi,
                        Zphase_countAB_count,			//[Zphase broken, Lyabryan, 2015/09/17]
                        Zphase_countAB_flag,			//[Zphase broken, Lyabryan, 2015/09/17]
                        Zphase_countAB_old, 			//[Zphase broken, Lyabryan, 2015/09/17]
                        Zphase_error_zero, 				//[Zphase broken, Lyabryan, 2015/09/17]
                        Zphase_tune_count; 				//[Zphase broken, Lyabryan, 2015/09/17]

TB_1ms_EXT SWORD        Zphase_swcountAB_error, 		//[Zphase broken, Lyabryan, 2015/09/17]
                        Zphase_swcountAB_error_old; 	//[Zphase broken, Lyabryan, 2015/09/17]

TB_1ms_EXT SLONG		dec_integral, 
                		acc_integral,
                		TB1_slSpdAcc,			//ADDED BY SCOTTY 02/05/2007 
                		acc1_integral;
						
                          
TB_1ms_EXT UWORD		reg_t2s3TCR,
			    		PGHOMEMem,
			    		MI_INVMem,
			    		MO_INVMem,
			    		uwOverWsL,
			    		uwAFMda,
                		TB1_uwGencnt,         // For generation dir, by Justin , 2010/04/27
						uwFWDPFangle,
						uwREVPFangle,
						TB1_uwFcmdOld,		// Last Fcmd, DINO, 08/02/2010 
						Vcmd_LL2;       	//[weak magnet, Sampo, 03/31/2011]

TB_1ms_EXT UWORD		uwRetryCnt,         //[Add auto restart after fault, Bernie, 06/06/12]
						uwRetryTimeCnt,     //[Add auto restart after fault, Bernie, 06/06/12]
						rec_uwRetryCnt,     //[Add auto restart after fault, Bernie, 06/06/12]
						uwReset_10mCnt;     //[Add auto restart after fault, Bernie, 06/06/12]

TB_1ms_EXT UWORD	    TB1_uwGenorMotCnt;	//[Add Generator or Motor Direction, Bernie, 05/21/2012]  

TB_1ms_EXT ULONG		GearAccCnt, 
                		GearDecCnt,
                		speed_tmp;
                          
TB_1ms_EXT SLONG_UNION	fhunt,
						IqseOutPuLPF,DcbusDCLPF2,VcmdLLPF2;//[weak magnet, Sampo, 03/31/2011]

TB_1ms_EXT SLONG_UNION	VF_IqseOutPuLPF;     //[Add Generator or Motor Direction, Bernie, 05/21/2012]


TB_1ms_EXT UWORD		STO_FLAG,
                        STO_FLAG2,
                        WarnSTO,
						TB1_uwStoRunCnt,
                        TB1_uwSTOErrCnt,
                        TB1_uwSTOStrCnt,
                        TB1_uwSTOStrWARNCnt,
                        TB1_uwSTORunWARNCnt,
                        TB1_uwSOSStrCnt,//[Sibocom SOS Warn, James, 2020/04/28]
						TB1_uwSOSRunWARNCnt;


TB_1ms_EXT UWORD   uwAcc10msCount,uwWritePrCnt;    //[Over Acceleration protection function, Bernie, 2017/02/13]  // [EDS parameter at once, sampo,2018/02/05]

					
TB_1ms_EXT UWORD_UNION  Run_Time_srquence;   //[Russia time srequence for IM, Bernie, 2015/07/13]
TB_1ms_EXT UBYTE_UNION  RST_Status;          //[Add auto restart after fault, Bernie, 06/06/12]

TB_1ms_EXT SLONG        sl_IqErrKp,         // JOSH IqRef vs IqFdb offset TEST 
                        sl_IqErrKp6,        // JOSH IqRef vs IqFdb offset TEST
                        slFdbOld,           // JOSH avoid speed drop 2017/03/22
                        slFdbErr;           // JOSH avoid speed drop 2017/03/22
TB_1ms_EXT SWORD        swErrTEST;          // JOSH Speed Error %
TB_1ms_EXT UBYTE        ubPGrevCnt,         // JOSH don't revise SpdFdb continuously
                        ubRevise;           // JOSH revise SpdFdb flag
TB_1ms_EXT UWORD		uwGFF_MaxVal;		// GFF Maximum Value Record, Jerry Yu, 2019/11/11
TB_1ms_EXT UBYTE		ubIntervalSeted;	//[Add GFF and Ocx auto reset function, Jerry Yu, 2019/05/23]

TB_1ms_EXT UWORD
						TB1_uwSampleRate;		//[Rationa 362631, Special.Kung]

TB_1ms_EXT SLONG_UNION
						AccFbTemp_LPF,			//[Rationa 362631, Special.Kung]
						AccCmdTemp_LPF;   		//[Rationa 362631, Special.Kung]

TB_1ms_EXT SWORD
						TB1_swAccCalculOld,		//[Rationa 362631, Special.Kung]
						TB1_swAccCmdOpt,		//[Rationa 362631, Special.Kung]
						TB1_swAccCmdCalculOld;	//[Rationa 362631, Special.Kung]

TB_1ms_EXT SLONG
						TB1_slAccTemp1,			//[Rationa 362631, Special.Kung]
						TB1_slAccTemp2,			//[Rationa 362631, Special.Kung]
						TB1_slAccCalculOld;		//[Rationa 362631, Special.Kung]

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
