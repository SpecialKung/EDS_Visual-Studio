/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

History:

===============================================================*/
#ifdef _PrHandel_C
   #define PrHandel_EXT 
#else
   #define PrHandel_EXT extern
#endif

/*======= Modules used (included header files) ==================*/

/*========== @ Defines =========================================*/



/* Struct Type define =========================================*/

/* Function Call ==============================================*/
PrHandel_EXT UWORD maxcf(UWORD model);
PrHandel_EXT UWORD GetParMax(UWORD prx);
PrHandel_EXT UWORD GetParMin(UWORD prx);
PrHandel_EXT UWORD GetParAttr(UWORD prx);

PrHandel_EXT void write_pr(UWORD prx,UWORD prvalue);
PrHandel_EXT void updatepr(UWORD prx,UWORD prvalue);
PrHandel_EXT void fnone(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_03(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_05(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_07(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_08(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_09(UWORD prx, UWORD prvalue);
// [ Change Output Direction, Added by sampo , 06/11/2009
PrHandel_EXT void P00_11(UWORD prx, UWORD prvalue);
// ]
PrHandel_EXT void P00_12(UWORD prx, UWORD prvalue);
PrHandel_EXT void P00_14(UWORD prx, UWORD prvalue);

PrHandel_EXT void P01_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P01_01(UWORD prx, UWORD prvalue);
PrHandel_EXT void P01_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P01_07(UWORD prx, UWORD prvalue);
PrHandel_EXT void P01_10(UWORD prx, UWORD prvalue);

PrHandel_EXT void P02_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P02_01(UWORD prx, UWORD prvalue);
PrHandel_EXT void P02_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P02_11(UWORD prx, UWORD prvalue);
PrHandel_EXT void P02_33(UWORD prx, UWORD prvalue);

PrHandel_EXT void P03_15(UWORD prx, UWORD prvalue);

PrHandel_EXT void P04_23(UWORD prx, UWORD prvalue); // mod cur lev writable, v0.03

//jerk adj,Henry
PrHandel_EXT void P04_49(UWORD prx, UWORD prvalue);
PrHandel_EXT void P04_50(UWORD prx, UWORD prvalue);

PrHandel_EXT void P05_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_01(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_03(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_04(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_05(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_06(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_07(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_08(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_09(UWORD prx, UWORD prvalue);
PrHandel_EXT void P05_18(UWORD prx, UWORD prvalue);

PrHandel_EXT void P06_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P06_16(UWORD prx, UWORD prvalue);
PrHandel_EXT void P06_17(UWORD prx, UWORD prvalue);
PrHandel_EXT void P06_44(UWORD prx, UWORD prvalue);  //[User can change speed when used EPS function, Bernie, 2013/04/16]
PrHandel_EXT void P06_46(UWORD prx, UWORD prvalue);  //[SIBOCOM, Jason, 2020/05/05]
PrHandel_EXT void P06_51(UWORD prx, UWORD prvalue);    //[Add auto restart after fault, Bernie, 06/06/12]
PrHandel_EXT void P06_52(UWORD prx, UWORD prvalue);    //[Add auto restart after fault, Bernie, 06/06/12]
PrHandel_EXT void P06_67(UWORD prx, UWORD prvalue);    //[Service time function, Bernie, 2017/03/14]
PrHandel_EXT void P06_79(UWORD prx, UWORD prvalue);    //[Running Dir Count,Special,2018/08/17]


PrHandel_EXT void P07_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P07_12(UWORD prx, UWORD prvalue);
PrHandel_EXT void P07_14(UWORD prx, UWORD prvalue);
PrHandel_EXT void P07_17(UWORD prx, UWORD prvalue);
PrHandel_EXT void P07_21(UWORD prx, UWORD prvalue);

PrHandel_EXT void P08_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_01(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_03(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_04(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_05(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_06(UWORD prx, UWORD prvalue);
PrHandel_EXT void P08_09(UWORD prx, UWORD prvalue);	// StandStill tune parameter, add by dino, 2006/08/07
PrHandel_EXT void P08_10(UWORD prx, UWORD prvalue);	// StandStill tune parameter, add by dino, 2006/08/07

PrHandel_EXT void P09_01(UWORD prx, UWORD prvalue);
PrHandel_EXT void P09_05(UWORD prx, UWORD prvalue);
PrHandel_EXT void P09_07(UWORD prx, UWORD prvalue);
PrHandel_EXT void P09_14(UWORD prx, UWORD prvalue);



PrHandel_EXT void P10_01(UWORD prx, UWORD prvalue);
PrHandel_EXT void P10_03(UWORD prx, UWORD prvalue);
PrHandel_EXT void P10_10(UWORD prx, UWORD prvalue);
PrHandel_EXT void P10_17(UWORD prx, UWORD prvalue);
PrHandel_EXT void P10_32(UWORD prx, UWORD prvalue);    //[Over Acceleration protection function, Bernie, 2017/02/13]
PrHandel_EXT void P10_33(UWORD prx, UWORD prvalue);    //[Over Acceleration protection function, Bernie, 2017/02/13]



PrHandel_EXT void P11_02(UWORD prx, UWORD prvalue);			//ADDED BY SCOTTY
PrHandel_EXT void P11_05(UWORD prx, UWORD prvalue);			//ADDED BY SCOTTY
PrHandel_EXT void P11_11(UWORD prx, UWORD prvalue);
PrHandel_EXT void P11_16(UWORD prx, UWORD prvalue);			//ADDED BY SCOTTY
PrHandel_EXT void P11_18(UWORD prx, UWORD prvalue);			//ADDED BY Dino, 2008/02/21

PrHandel_EXT void P14_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_04(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_07(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_08(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_51(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_53(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_64(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_68(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_82(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_92(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_93(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_103(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_104(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_112(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_114(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_118(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_122(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_131(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_133(UWORD prx, UWORD prvalue);
PrHandel_EXT void P14_136(UWORD prx, UWORD prvalue);   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
PrHandel_EXT void P14_137(UWORD prx, UWORD prvalue);   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
PrHandel_EXT void P14_138(UWORD prx, UWORD prvalue);   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
PrHandel_EXT void P01_33(UWORD prx, UWORD prvalue); // [IODLC, Lyabryan, 2016/11/11]


PrHandel_EXT void P15_00(UWORD prx, UWORD prvalue);
PrHandel_EXT void P15_02(UWORD prx, UWORD prvalue);
PrHandel_EXT void P15_34(UWORD prx, UWORD prvalue);
PrHandel_EXT void P15_12(UWORD prx, UWORD prvalue);
PrHandel_EXT void P15_41(UWORD prx, UWORD prvalue);
PrHandel_EXT void P15_42(UWORD prx, UWORD prvalue);

PrHandel_EXT void ACC_Unit_SecToms2(void);
PrHandel_EXT void ACC_Unit_ms2ToSec(void);

PrHandel_EXT void flashpr(UWORD prx, UWORD prvalue);
PrHandel_EXT UWORD Set_LPG(UWORD prvalue , UWORD ds);
PrHandel_EXT void P15_87(UWORD prx, UWORD prvalue);			// dino, 06/01/2007
PrHandel_EXT void P15_108(UWORD prx, UWORD prvalue);	

PrHandel_EXT void LPFGain(UWORD prx, UWORD prvalue);
PrHandel_EXT void PrArea(UWORD prvalue);
PrHandel_EXT void Fault_Record(void);
PrHandel_EXT void SortFskip(void);
PrHandel_EXT void AnaPGInit(void);							// dino, 06/01/2007
// [ Velocity Unit Change, Add by DINO, 05/25/2009
PrHandel_EXT UWORD Metric2Hz(UWORD uwSpeed);
PrHandel_EXT UWORD Hz2Metric(UWORD uwFreq);
PrHandel_EXT UWORD Ft2Hz(UWORD uwFt);
PrHandel_EXT UWORD Hz2Ft(UWORD uwFreq);
PrHandel_EXT UWORD GetParData(UWORD uwParAdr);
// ]
PrHandel_EXT UWORD Hz2MperS2(UWORD uwFreq);

PrHandel_EXT float SToMs3(float flSInput, float flAccTimePrValue);
PrHandel_EXT float Ms3ToS(float flMs3Input, float flAccTimePrValue);
PrHandel_EXT float SToMs2(float flAccTimeS);
PrHandel_EXT float Ms2ToS(float flAccMs2);
PrHandel_EXT UWORD SToFts2(UWORD uwAccTimeS);
PrHandel_EXT UWORD Fts2ToS(UWORD uwAccMs2);
PrHandel_EXT UWORD SToFts3(UWORD uwSInput, UWORD uwAccTimePrValue);
PrHandel_EXT UWORD Fts3ToS(UWORD uwMs3Input, UWORD uwAccTimePrValue);
PrHandel_EXT float SCurve_UnitConv(UWORD prx, float prvalue, UBYTE ConvFlag);
PrHandel_EXT float ACC_UnitConv(float prvalue, UBYTE ConvFlag);
PrHandel_EXT float flHz2Metric(float flFreq);
PrHandel_EXT float flMetric2Hz(float flSpeed);
/* Exported Variable List ======================================*/
/*======= Low Pass Filter Gain =======*/			
PrHandel_EXT UWORD      fskip1h,
						fskip1l,                            		
                        fskip2h,
						fskip2l,
                        fskip3h,
						fskip3l,
						PM_uwStart,		// FOCPM start angle, add by dino 2006/07/27
			            DisplayLPG,		// Display LowPass Gain
			            LC01DisplayLPG, // [JES Torq Detect Function, Special.Kung, 2022/09/01]
			            uwInitialCnt,	// Initial Position Counter
			            uwCAN_ChkTime;  // [CAN Protocol for High Cap, Bernie, 09/22/2011] 

PrHandel_EXT UBYTE     	MotorRUNSec,	//CalUBYTE: 2 UBYTE
                        SpDt_ubPGCard,  //[Modify PG Type Define, Bernie, 12/05/2011]
                        PR_ubEpsOptMod;

PrHandel_EXT float      PR_flAccel1ms2,
                        PR_flAccel2ms2,
                        PR_flAccel3ms2,
                        PR_flAccel4ms2,
                        PR_flDecel1ms2,
                        PR_flDecel2ms2,
                        PR_flDecel3ms2,
                        PR_flDecel4ms2,
                        PR_flDecel5ms2,
                        PR_flDecelJogms2,
                        PR_flAccelJogms2,
                        PR_flDecelEsdms2,
                        PR_flDecelEMYSIBOms2,
                        PR_flSAcc1Esdms3,
                        PR_flSAcc2Esdms3,
                        PR_flSDec1Esdms3,
                        PR_flSDec2Esdms3,
                        PR_flSDec3Esdms3,
                        PR_flS3EMYms3,
                        PR_flS4EMYms3,
                        PR_flFJog_ms,
                        PR_flFEps_ms,
                        PR_flfkey_ms;

PrHandel_EXT float      PR_flFmi0ms,
                        PR_flFmi1ms,
                        PR_flFmi2ms,
                        PR_flFmi3ms,
                        PR_flFmi4ms,
                        PR_flFmi5ms,
                        PR_flFmi6ms,
                        PR_flFmi7ms,
                        PR_flFmi8ms,
                        PR_flFmi9ms,
                        PR_flFmi10ms, 
                        PR_flFmi11ms, 
                        PR_flFmi12ms, 
                        PR_flFmi13ms, 
                        PR_flFmi14ms, 
                        PR_flFmi15ms;

PrHandel_EXT float      PR_flAccel1sec,
                        PR_flAccel2sec,
                        PR_flAccel3sec,
                        PR_flAccel4sec,
                        PR_flDecel1sec,
                        PR_flDecel2sec,
                        PR_flDecel3sec,
                        PR_flDecel4sec,
                        PR_flDecel5sec,
                        PR_flDecelJogsec,
                        PR_flAccelJogsec,
                        PR_flDecelEsdsec,
                        PR_flDecelEMYSIBOsec,
                        PR_flSAcc1Esdsec,
                        PR_flSAcc2Esdsec,
                        PR_flSDec1Esdsec,
                        PR_flSDec2Esdsec,
                        PR_flSDec3Esdsec,
                        PR_flS3EMYsec,
                        PR_flS4EMYsec,
                        PR_flFJog_Hz,
                        PR_flfkey_Hz;

PrHandel_EXT float      PR_flFmi0Hz,
                        PR_flFmi1Hz,
                        PR_flFmi2Hz,
                        PR_flFmi3Hz,
                        PR_flFmi4Hz,
                        PR_flFmi5Hz,
                        PR_flFmi6Hz,
                        PR_flFmi7Hz,
                        PR_flFmi8Hz,
                        PR_flFmi9Hz,
                        PR_flFmi10Hz, 
                        PR_flFmi11Hz, 
                        PR_flFmi12Hz, 
                        PR_flFmi13Hz, 
                        PR_flFmi14Hz, 
                        PR_flFmi15Hz;


// [ Time Display, DINO, 08/16/2010
#ifdef _PrHandel_C
						//Jan. Feb. Mar. Apr. May June July Aug. Sep. Oct. Nov. Dec.
const UBYTE MthMax[12] ={  31,  29,  31,  30, 31,  30,  31,  31,  30,  31,  30,  31,};

#else

extern const UBYTE MthMax[12];

#endif
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
