#ifdef _DLC_C
   #define DLC_EXT 
#else
   #define DLC_EXT extern
#endif

#define ubLEFT 	0
#define ubRIGHT 1

#define	DIR_NULL	0
#define	DIR_UP   	1	
#define	DIR_DN	  2

#define	PR_INIT_RD	1
#define	PR_RD				2
#define	PR_WR				3

#define PGBS  100000
#define DLCPOS 1 //1-dont modi pos	// Sean, 20181207

//DLC_ubMode :
#define	MODE_NULL	0
#define	MODE_S1		1
#define	MODE_ACC 	2
//#define	MODE_AUTO_ACC	1
#define MODE_S2		3
#define	MODE_CON	4
#define	MODE_S3		5
#define	MODE_DEC	6
#define	MODE_S4	  7
#define	MODE_DYN	8
#define	MODE_DON	9

// decel sw DLCxx addr
#define	DD1_H	DLC_75ADDR	+	0U
#define	DD1_L	DLC_75ADDR	+	1U
#define	DD2_H	DLC_75ADDR	+	2U
#define	DD2_L	DLC_75ADDR	+	3U
#define	DD3_H	DLC_75ADDR	+	4U
#define	DD3_L	DLC_75ADDR	+	5U
#define	DD4_H	DLC_75ADDR	+	6U
#define	DD4_L	DLC_75ADDR	+	7U
#define	UD1_H	DLC_75ADDR	+	8U
#define	UD1_L	DLC_75ADDR	+	9U
#define	UD2_H	DLC_75ADDR	+	10U
#define	UD2_L	DLC_75ADDR	+	11U
#define	UD3_H	DLC_75ADDR	+	12U
#define	UD3_L	DLC_75ADDR	+	13U
#define	UD4_H	DLC_75ADDR	+	14U
#define	UD4_L	DLC_75ADDR	+	15U
#define	UL_H 	DLC_75ADDR	+	16U
#define	UL_L 	DLC_75ADDR	+	17U

//#15977, LULD detect, James, 2021/04/01
#define	LULD_STANDBY   0
#define	LULD_UP_JUDGE  2
#define	LULD_DN_JUDGE  1
#define	LULD_UP_LUok   5
#define	LULD_DN_LDok   4
#define	LULD_OK_RUN	   6
#define	LULD_Leveling  7
#define	LULD_Fault     8

#define	LU_SHORT       2
#define	LD_SHORT       1
#define	LDok_LU_SHORT  4
#define	LUok_LD_SHORT  5
#define	LULD_SHORT     7
#define	LULD_OPEN      3
#define	LULD_OK        0
//---------------------------------------------//
DLC_EXT	void DLC_Init(void);
DLC_EXT	void DLC_PrMgr(UBYTE Val);
DLC_EXT void DLC_PDO_Byte67(void);
DLC_EXT	void DLC_Algorithm(void);
DLC_EXT	UBYTE DLC_LevStop(ULONG ulDis);
DLC_EXT	void	DLC_LevCur(void);

DLC_EXT	ULONG EqCal_D2(UWORD uwCurSpd);
DLC_EXT	ULONG EqCal_Dcon(UWORD uwVcon);
DLC_EXT	void EqCal_T3_Tdec_T4(UWORD uwVcon);
DLC_EXT	ULONG EqCal_D3(UWORD uwVcon);
DLC_EXT	ULONG EqCal_Ddec(void);
DLC_EXT	ULONG EqCal_D4(void);

DLC_EXT ULONG Spd_NOR(ULONG ulCurSpd);
DLC_EXT ULONG Spd_Dec0S(UWORD uwS3, UWORD uwDec, UWORD uwS4);	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220516 add
DLC_EXT ULONG Spd_Linear(UWORD uwTarSpd, UWORD uwAcc, UWORD uwDec);
DLC_EXT	ULONG Spd_FSD(UWORD uwPrFSD, UWORD uwDecTmr);

DLC_EXT	void WelTunProc(void);
DLC_EXT void WelTunReset(void);
DLC_EXT void WelTun_eeprom(void);

DLC_EXT	UWORD uw_CubRot32c(ULONG x);

DLC_EXT void DLC_Initial_value(void);
DLC_EXT void DLC_Decel_Protect(void); // JINGDO
DLC_EXT ULONG DLC_Decel_Protect_SpdLim(ULONG ulCurSpd); //Artemis speed limit, James, 20200220
DLC_EXT UBYTE DLC_LULD_Protect(Bool LU, Bool LUOld, Bool LD, Bool LDOld);//#15977, LULD detect, James, 2021/04/01
DLC_EXT void Sensor817_Protect(void);	//[Artemis Add Sensor819 Function/Special/2022/06/06]
DLC_EXT void Sensor818_Protect(void);	//[Artemis Add Sensor819 Function/Special/2022/06/06]

// DLC position offset 2, Henry
DLC_EXT void Update_C40xx(void);
//---------------------------------------------//											
DLC_EXT	ULONG	            DLC_ulDacc,
							DLC_ulD2,
							DLC_ulDcon,
							DLC_ulD3,
							DLC_ulDdec,
							DLC_ulD4,
							DLC_ulDStop,
							DLC_ulPgLev[DLCFLOORMAX+1],	//4B=75F	//unit - pg pulse
							DLC_ulPgBrd,        //水平遮板PG脈衝數
							DLC_ulPgSen,        //LD, LU PG脈衝數
							DLC_ulPgCnt,
							DLC_ulPgUp,
							DLC_ulPgDn,
							DLC_ulPgDD1, // JINGDO
							DLC_ulPgDD2, // JINGDO
							DLC_ulPgDD3, // JINGDO
							DLC_ulPgDD4, // JINGDO
							DLC_ulPgUD1, // JINGDO
							DLC_ulPgUD2, // JINGDO
							DLC_ulPgUD3, // JINGDO
							DLC_ulPgUD4, // JINGDO 
							DLC_ulPgUL,
							DLC_ulPosLev[DLCFLOORMAX+1],	//4B=75F   //unit - 0.1mm
							DLC_ulPosVal,
							DLC_ulOffset, // DLC position offset, Henry
							DLC_ulPosDD1, // JINGDO
							DLC_ulPosDD2, // JINGDO
							DLC_ulPosDD3, // JINGDO
							DLC_ulPosDD4, // JINGDO
							DLC_ulPosUD1, // JINGDO
							DLC_ulPosUD2, // JINGDO
							DLC_ulPosUD3, // JINGDO
							DLC_ulPosUD4, // JINGDO
							DLC_ulPosUL,
							COF_ulPls2MMgain,	
							DLC_ulPosRopeCmp,	// Mitong 20220513 add
							DLC_ulPgRopeCmp;	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 add
							
							
							
DLC_EXT ULONG_UNION         DLC_ulPosPar, // DLC position offset, Henryv
					        DLC_ulPosTar, // Sean, 20181207
					        DLC_ulDisTar, // Sean, 20181207
					        ulLiftSpdFdb;
DLC_EXT	ULONG		        ultest1,
                            ultest2,
                            ultest3,
                            ultest4,
                            DLC_ulCurSpd,
							DLC_ulCurSpdOld,			//Rationa 362631, Special.Kung
							DLC_ulCurAcc,				//Rationa 362631, Special.Kung
							DLC_ulCurAccArray[5];

DLC_EXT	UWORD	            PR_S4ACC1,
                            PR_S4ACC2,
                            PR_S4DEC1,
                            PR_S4DEC2,
                            DLC_uwPOWCnt,
							DLC_uwInit,
                            DLC_uwTR1,
							DLC_uwTR2,
							DLC_uwTR3,
							DLC_uwTR4,
							DLC_uwT1,		//運算後, S1的時間
							DLC_uwT2,		//運算後, S2的時間
							DLC_uwT3,		//運算後, S3的時間
							DLC_uwT4,		//運算後, S4的時間
							DLC_uwTd,		//運算後, eq dec的時間
							DLC_uwTc,	//等速段時間
							DLC_uwRateSpd,
							DLC_uwRateSpdMax,
							DLC_uwTRa,		//idea Tacc
							DLC_uwTRd,		//idea Tdec
							DLC_uwTd,
							DLC_uwAa,		//idea Aacc
							DLC_uwAd,		//idea Adec
							DLC_uwJR1,	//idea Jerk1
							DLC_uwJR2,	//idea Jerk2
							DLC_uwJR3,	//idea Jerk3
							DLC_uwJR4,	//idea Jerk4
							DLC_uwJ4,
							DLC_uwVR1,	//idea spd variable V1
							DLC_uwVR2,	//idea spd variable V2
							DLC_uwVR3,	//idea spd variable V3
							DLC_uwVR4,	//idea spd variable V4
							DLC_uwV1,			//real spd variable V1
							DLC_uwV2,		//real spd variable V2	//以目前的速度開始計算,當S2結束後,速度會是多少,單位mm/s
							DLC_uwJR3_Dec0S,//idea Jerk3	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwJR4_Dec0S,//idea Jerk4	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwT3_Dec0S,	//運算後S3實際要走的時間	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwT4_Dec0S,	//運算後S4實際要走的時間	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwV3_Dec0S,	//從S3開始到S3結束,速度會減少多少,單位mm/s	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwV4_Dec0S,	//S4開始時的速度	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwTd_Dec0S,	//等減速段要走的時間 ms	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwVd_Dec0S,	//等減速段要走的速度變化量	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwAd_Dec0S,	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_uwVc_Dec0S;	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
DLC_EXT	UWORD    			DLC_uwV3,			//real spd variable V3
							DLC_uwV4,			//real spd variable V4
							DLC_uwVc,		//real const spd
							DLC_uwVd,		//real spd variable Vdec
							DLC_uwV4Dif,
							DLC_uwS1Tmr,
							DLC_uwAccTmr,
							DLC_uwS2Tmr,
							DLC_uwConTmr,
							DLC_uwS3Tmr,
							DLC_uwDecTmr,
							DLC_uwS4Tmr,
							DLC_uwInsAccTmr,
							DLC_uwInsDecTmr,
							MTU1_Old,
							DLC_uwWelTra,
							DLC_uwTra1,
							DLC_uwTra2,
							DynJerkTmr,
							uwDI_buf,
							uwDI_old,
							DLC_uwTmr,						//Rationa 362631, Special.Kung
							DLC_uwTmrOld;					//Rationa 362631, Special.Kung
							
DLC_EXT	UWORD DLC_uwTra3,
							DLC_uwTra4,
							DLC_uwTra5,
							DLC_uwSpdTra,
							DLC_uwEeprom,
							DLC_uwSpdLim,  //(m/s, dot3)//Artemis speed limit, James, 20200220							
							DLC_uwLuLdResetTimer,//#15977, LULD detect, James, 2021/08/03
							DLC_uwLuLdTimer;//#15977, LULD detect, James, 2021/04/01
							
DLC_EXT	UWORD	DLC_uwTra3,
							DLC_uwTra4,
							DLC_uwJD,
							DLC_uwTD,
							DLC_uwTDCnt,
							DLC_uwATmp,
							DLC_uwFlagCnt,
							//DLC_uwS4Cnt,		// Mitong 20220513 del
							DLC_uwPeriodCnt,
							DLC_uwDCICnt,
							DLC_uwSfbk;
							
DLC_EXT	SWORD				swRopeCmp,
							DLC_swCurAcc;

DLC_EXT	UBYTE	DLC_ubSubtra,	 //Subtra addr, H=tra, L=Subtra
							DLC_ubtra,
							DLC_ubLevMax,
							DLC_ubLevMin,
							DLC_ubLevCur,  //Cur addr, H=Tar, L=Cur
							DLC_ubLevTar,
							DLC_ubLevOk,
							DLC_ubMode,    //Mode addr, H=ModeOld, L=Mode
							DLC_ubModeOld,
							DLC_ubWelTuntra,	//map WelTuntra addr, H=PgPosClr, L=WelTuntra
							DLC_ubDIR,
							DLC_ubCnt,
							DLC_ubDecel,  //20180612
							DLC_ubSpdLimMode,//bit6&5 over speed treatment>>00:disable 01:Force stop 10:re-leveling
							DLC_ubSpdLimFlag,//Artemis speed limit, James, 20200220
							DLC_ubLuLdError,//#15977, LULD detect, James, 2021/04/01
							DLC_ubLuLdProtectState,//#15977, LULD detect, James, 2021/04/01
							DLC_ubDec0SModeTmr,	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add
							DLC_ubDec0SMode;	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220616 add

DLC_EXT	UBYTE	DLC_EPS_Source,//1:MI, 2:CAN
				DLC_uwAutoTar;
// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 add -------------
DLC_EXT	ULONG	DLC_ulSpd0p1mm;
DLC_EXT	UBYTE	DLC_ubLevSta;
// ---------------------------------------------------------------------
DLC_EXT	UBYTE	ubDLC_btUD1_Stop, ubDLC_btDD1_Stop;   //Jerry.sk.Tseng 2022/11/25

DLC_EXT	UWORD_UNION DLC_uwEM;
#define	DLC_btErr				 DLC_uwEM.bit.b0
#define	DLC_btRdy				 DLC_uwEM.bit.b1
#define	DLC_btModNor		     DLC_uwEM.bit.b2
#define	DLC_btModZeo		     DLC_uwEM.bit.b3
#define	DLC_btModIns		     DLC_uwEM.bit.b4
#define	DLC_btModRsq		     DLC_uwEM.bit.b5
#define	DLC_btModLev		     DLC_uwEM.bit.b6
#define DLC_btModAutoLev         DLC_uwEM.bit.b7
#define DLC_btReCalFlag          DLC_uwEM.bit.b8
#define DLC_btEPS                DLC_uwEM.bit.b9
#define	DLC_btModFSD	    	 DLC_uwEM.bit.b10
#define	DLC_btModHome	         DLC_uwEM.bit.b11
//#define DLC_btEffic      DLC_uwEM.bit.b12
#define DLC_btAutoFlag           DLC_uwEM.bit.b13
#define DLC_btModDec             DLC_uwEM.bit.b14

DLC_EXT	UWORD_UNION DLC_uwDI;
#define	DLC_btRst			DLC_uwDI.bit.b0
#define	DLC_btUP			DLC_uwDI.bit.b1
#define	DLC_btDN			DLC_uwDI.bit.b2
#define DLC_btDirTri        DLC_uwDI.bit.b3


DLC_EXT	UWORD_UNION	DLC_MI;   // adco
#define	DLC_btLU			DLC_MI.bit.b0
#define	DLC_btLUOld		    DLC_MI.bit.b1
#define	DLC_btLD			DLC_MI.bit.b2
#define	DLC_btLDOld		    DLC_MI.bit.b3
#define DLC_btDZN           DLC_MI.bit.b4
#define DLC_btDZNOld        DLC_MI.bit.b5
#define	DLC_btULS			DLC_MI.bit.b6
#define	DLC_btULSOld	    DLC_MI.bit.b7
#define	DLC_btDLS			DLC_MI.bit.b8
#define	DLC_btDLSOld	    DLC_MI.bit.b9
#define	DLC_btLU1		    DLC_MI.bit.b10
#define DLC_btLD1	        DLC_MI.bit.b11
#define DLC_btSpdL		    DLC_MI.bit.b12
#define DLC_btFSD1          DLC_MI.bit.b13
#define DLC_btCANOff        DLC_MI.bit.b15

DLC_EXT	UWORD_UNION	mio_MI1;       // JINGDO
#define mio_btDD1  mio_MI1.bit.b1  // JINGDO  DLC_btDDS_1
#define mio_btDD2  mio_MI1.bit.b2  // JINGDO
#define mio_btDD3  mio_MI1.bit.b3  // JINGDO
#define mio_btDD4  mio_MI1.bit.b4  // JINGDO
#define mio_btUD1  mio_MI1.bit.b5  // JINGDO  DLC_btUDS_1
#define mio_btUD2  mio_MI1.bit.b6  // JINGDO
#define mio_btUD3  mio_MI1.bit.b7  // JINGDO
#define mio_btUD4  mio_MI1.bit.b8  // JINGDO

DLC_EXT	UWORD_UNION	DLC_MI2;
#define DLC_btDD1  DLC_MI2.bit.b0  // JINGDO DLC_btDDS
#define DLC_btDD2  DLC_MI2.bit.b1  // JINGDO
#define DLC_btDD3  DLC_MI2.bit.b2  // JINGDO
#define DLC_btDD4  DLC_MI2.bit.b3  // JINGDO
#define DLC_btUD1  DLC_MI2.bit.b4  // JINGDO DLC_btUDS
#define DLC_btUD2  DLC_MI2.bit.b5  // JINGDO
#define DLC_btUD3  DLC_MI2.bit.b6  // JINGDO
#define DLC_btUD4  DLC_MI2.bit.b7  // JINGDO
#define DLC_btDD1Old  DLC_MI2.bit.b8  // JINGDO DLC_btDDSOld
#define DLC_btDD2Old  DLC_MI2.bit.b9  // JINGDO
#define DLC_btDD3Old  DLC_MI2.bit.b10  // JINGDO
#define DLC_btDD4Old  DLC_MI2.bit.b11  // JINGDO
#define DLC_btUD1Old  DLC_MI2.bit.b12  // JINGDO DLC_btUDSOld
#define DLC_btUD2Old  DLC_MI2.bit.b13  // JINGDO
#define DLC_btUD3Old  DLC_MI2.bit.b14  // JINGDO
#define DLC_btUD4Old  DLC_MI2.bit.b15  // JINGDO

DLC_EXT	UWORD_UNION	DLC_uwCAN;	 //09-10 factory function
#define	DLC_btPRChk   	DLC_uwCAN.bit.b0	// power-on parameter check successful
#define	DLC_btWelDone   DLC_uwCAN.bit.b1	// FHM sucessful
#define	DLC_btWelExc    DLC_uwCAN.bit.b2	// FHM execute
#define	DLC_btWelRec    DLC_uwCAN.bit.b3	// PG Pulse Record
#define	DLC_btWelRst    DLC_uwCAN.bit.b4	// PG Pulse Reset

DLC_EXT UWORD_UNION DLC_0436;
#define DLC_btADCO      DLC_0436.bit.b0
#define DLC_btEPSDir    DLC_0436.bit.b1  // adco-3
#define DLC_btDznMd     DLC_0436.bit.b2
#define DLC_btWelDec    DLC_0436.bit.b3
#define DLC_btCanEmStp  DLC_0436.bit.b4  //Gfc DLC modify , Henry, 2018/05/23
#define DLC_btTorOfsDir	DLC_0436.bit.b7	// Sean, 20181207
#define DLC_btPDO_ID005_Enable	DLC_0436.bit.b8//Artemis Speed &Position PDO transmition , James, 20200603
#define DLC_btPosLULDCal DLC_0436.bit.b9	//James, 20210421


DLC_EXT UWORD_UNION DLC_Word1;
#define DLC_btParkTooFar	DLC_Word1.bit.b0	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220516 //停車過頭
#define DLC_btAccDec1ms		DLC_Word1.bit.b1	// Task 268638 直接停靠-多段速加減速及S曲線 Mitong 20220516 add
//#define DLC_bt			DLC_Word1.bit.b2	//
//#define DLC_bt			DLC_Word1.bit.b3	//
//#define DLC_bt			DLC_Word1.bit.b4	//
//#define DLC_bt			DLC_Word1.bit.b5	//
//#define DLC_bt			DLC_Word1.bit.b6	// 
//#define DLC_bt			DLC_Word1.bit.b7	//
//#define DLC_bt			DLC_Word1.bit.b8	//
#define DLC_btDisTar0mm		DLC_Word1.bit.b9	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 add
#define DLC_btModNorOld		DLC_Word1.bit.b10	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 add
//#define DLC_bt     		DLC_Word1.bit.b11
//#define DLC_bt      		DLC_Word1.bit.b12
//#define DLC_bt      		DLC_Word1.bit.b13
//#define DLC_bt      		DLC_Word1.bit.b14
//#define DLC_bt      		DLC_Word1.bit.b15
