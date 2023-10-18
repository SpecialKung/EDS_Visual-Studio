/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: Main.H

Partner Filename: Main.C

Description: This is a inclue file of Main.C

Complier:


History:

===============================================================*/
#ifdef _Main_C
   #define Main_EXT
#else
   #define Main_EXT extern
#endif

#define DEBUG_MODE  0	//Enable Debug mode = 1
#define SCOTTY      1  	//
#define DINO        1 	// modify by dino
#define StandStill  1   // StandStill modify by dino
#define STtest      0   // StandStill test modify by dino
#define DIAO        1

#define NEWPARA   1   // new parameter enable/disable some function

#define DEBUG_MODE 0    //Enable Debug mode = 1
Main_EXT SLONG (*const mfai_tbl[12])(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_no_func(UBYTE AIsel,SWORD AIsumvar);  // Modify for new toolchain, DINO, 09/30/2010
Main_EXT SLONG AI_FreqRref(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_TorqRef(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_TorqComp(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_PIDRef(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_PIDFbk(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_PTCInput(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_PosTqLimit(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_NegTqLimit(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_RegenTqLimit(UBYTE AIsel,SWORD AIsumvar);
Main_EXT SLONG AI_PosNegTqLimit(UBYTE AIsel,SWORD AIsumvar);
Main_EXT void DINT(void);
Main_EXT void EINT(void);
Main_EXT void WarnDisplaySave(void);
Main_EXT UWORD ai_transfer(UBYTE AISel,UWORD ai_value,UWORD ai_h,UWORD ai_m,UWORD ai_l);
Main_EXT ULONG cal_time(UWORD f,UWORD t);
Main_EXT void LineEqu(CalLine *xline, SWORD x1, SWORD y1, SWORD x2, SWORD y2);
Main_EXT void VBusLineInit(void);
Main_EXT UWORD ADC2Vdc(UWORD adc_value);
Main_EXT UWORD Vdc2ADC(UWORD vdc_value);
Main_EXT void stop_status(void);
Main_EXT void InitValue(void); 
Main_EXT void Driver_ID_Rec(void); //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
Main_EXT void Pin_power(void);
Main_EXT void Torque_Load(void);
Main_EXT void mfi_FwdRevWarn(void);			//[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
#if SH7149
Main_EXT SWORD AVICalculate(void);
#else
Main_EXT SWORD AUI1Calculate(void);
#endif
Main_EXT void Recent_Setting_Parameter(UWORD prx);
Main_EXT UWORD Group_Check(UWORD prx);
Main_EXT SWORD ACICalculate(void);
Main_EXT SWORD AUI2Calculate(void);
Main_EXT UWORD FWDREVProcess(SLONG AIvar);
Main_EXT void mi_speed(void);

Main_EXT void UpCFByUnderLoad(void);
Main_EXT void DisDownCFByOverLoadTempOver80(void);
Main_EXT void SineDownCFByOverLoadTempOver80(void);
Main_EXT void DisDownCFByOverLoadTempUnder80(void);
Main_EXT void SineDownCFByOverLoadTempUnder80(void);
Main_EXT void DownCFBbyOverLoad(void);

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
Main_EXT void Sibocom_mi_speed(void); //[Sibocom acc/dec,Lyabryan,2019/11/12]
Main_EXT UWORD Sibocom_Speed_Priority(UWORD ax);
#endif

Main_EXT void Temp_vs_fpwm(void);
//Main_EXT UWORD AD2Temp(UWORD xh, UWORD xl, UWORD TempAD, UWORD a, UWORD b);
Main_EXT UWORD AD2Temp(UWORD xh, UWORD xl, SWORD TempAD, SWORD a, SWORD b);
Main_EXT UWORD Vth_to_Temp(UWORD TempAD, UWORD RealTemp);
Main_EXT SWORD thermal(UBYTE frame, SWORD TempAD);
Main_EXT void FanControl(void);
Main_EXT void main(void);
Main_EXT void main1(void);
Main_EXT void function_chk(void);
Main_EXT void Sinusoidal_Position(void);  /* Calculate the absolute position when power on, add by dino, 04/11/2007 */
Main_EXT void LV_REC(void);   					// Save data to EEPROM when Low Voltage, Add by DINO, 10/27/2008

Main_EXT void ICT4SCI3(void);
Main_EXT void ErrorResetInit(void);
Main_EXT void TorqDetect_Function(void);    	//[JES Torq Detect Function, Special.Kung, 2022/09/01]
Main_EXT void TorqDetect_Init(void);        	//[JES Torq Detect Function, Special.Kung, 2022/09/01]

#pragma address IrmsRe=0x0000a10e     			//[Address fixed, Aevin, 2017/06/28]

#pragma address zcal_uwMTU1cnt=0x0000a172     	//[Address fixed, Aevin, 2017/06/28]
#pragma address hsd_uwAbsAngle=0x0000a174     	//[Address fixed, Aevin, 2017/06/28]


Main_EXT UWORD    
                  checkValue,
                  uwFkeypad,
                  uwFcan,    //[CAN Control, Sampo, 09/15/2010]
                  Fkeypad_Buf,
                  Fcmd,
                  fbase,
                  vbase,
                  fmin,
                  fstart,
                  vtemp,
                  v_save,
                  vcmd_ser,
                  mspec,
                  Power_RAT,
                  PF_ANGLE,
                  IrmsRe,
                  IrmsRe1,    //ADDED BY SCOTTY 03/01/2007  TEST
                  stall4ad,
                  dcbrk4ad,
                  dcbrk4ad2,// [DCBRK_BAND function for adjustable reset level, James, 2019/12/05  ]   
                  dcbrkband4ad,
                  OVS4ad,
                  OVR4ad,
                  LVS4ad,
                  LVR4ad,
                  LV4FAN,
                  IGBT_OHLevel,
                  CTRLM_buf,
                  err_uwFfbk,
                  err_uwFcmd,
                  err_uwVout,
                  err_uwDcbus,
                  err_uwIsum,
                  // [ Add Fault Record Data, DINO, 06/11/2009
                  err_uwFkey,
                  err_uwPower,
                  err_uwTorq,
                  err_uwMFI,
                  err_uwMFO,
                  err_uwState;
                  // ]

Main_EXT UWORD    
                  rec_uwFfbk,
                  rec_uwFcmd,
                  rec_uwVout,
                  rec_uwDcbus,
                  rec_uwIsum,
                  rec_uwIGBT,
                  rec_uwSRY,
                  rec_uwFault1,
                  rec_uwFault2,
                  rec_uwFault3,
                  rec_uwFault4,
                  rec_uwFault5,
                  rec_uwFault6,
                  rec_uwError1_1,
                  rec_uwError1_2,
                  rec_uwError1_3,
                  rec_uwError1_4,
                  rec_uwError2_1,
                  rec_uwError2_2,
                  rec_uwError2_3,
                  rec_uwError2_4,
                  rec_uwError3_1,
                  rec_uwError3_2,
                  rec_uwError3_3,
                  rec_uwError3_4,
                  rec_uwError4_1,
                  rec_uwError4_2,
                  rec_uwError4_3,
                  rec_uwError4_4,
                  rec_uwError5_1,
                  rec_uwError5_2,
                  rec_uwError5_3,
                  rec_uwError5_4,
                  rec_uwPWRmin,
                  rec_uwRUNmin,
                  // [ Add Fault Record Data, DINO, 06/11/2009
                  rec_uwErrMin1,
                  rec_uwErrMin2,
                  rec_uwErrMin3,
                  rec_uwErrMin4,
                  rec_uwErrMin5,
                  rec_uwErrMin6,
                  rec_uwErrDay1,
                  rec_uwErrDay2,
                  rec_uwErrDay3,
                  rec_uwErrDay4,
                  rec_uwErrDay5,
                  rec_uwErrDay6,
                  rec_uwFkey,
                  rec_uwPower,
                  rec_uwTorq,
                  rec_uwMFI;
                    
Main_EXT UWORD    
                  rec_uwMFO,
                  rec_uwState,
                  // ]
                  PrTorqueRe,
                  PrTorquePu,
                  uwDheat,
                  PrDiameter,
                  st_uwAngle,
                  st_uwAbsAngle,
                  st_uwPGThetaM,
                  st_uwAnaPGInit,   		// Initail position detected by absolute Sin/Cos signals
                  st_uwInitPos,
                  st_uwAnaPGInitOld,  		// Initail position detected by absolute Sin/Cos signals
                  st_uwHallOld,
                  st_uwHallNew,
                  zcal_uwPulseErr,  		// PG pulse of Z pulse Calibration
                  TUN_DCVolt_OK,
                  RSP_uwRecent_pr,
                  RSP_uwRecent_no,
                  RSP_uwRecent[50],
                  RSP_uwRecent_prold,
                  RSP_uwRecent_prinfo;

Main_EXT UWORD    
                  uwPGThetaE_COM,    		// [IED 1387 static Tune, 2011/07/06]
			  	      uwPGThetaE_COM2;   		// [IED 1387 static Tune, 2011/07/06]

Main_EXT SWORD    
                  n_period,
                  experiod,
                  cf_swCFReal,
                  cf_swCFSet,
                  cf_swOHCarry,
                  cf_swOLCarry,     		// Overload Carry Frequency
                  cf_swChgTemp,
                  cf_step1,
                  cf_swCFDerate,
                  //swAVICalib,           // Move to A_Monitor.h, 11/04/2008
                  //swACICalib,           // Move to A_Monitor.h, 11/04/2008
                  //swAUICalib,           // Move to A_Monitor.h, 11/04/2008
                  PTCInValue,
                  TorqueOut,       		 	//6a16j
                  HS_Temp,
                  IGBT_Temp,
                  st_swSINmean,
                  st_swCOSmean,
                  st_swSINnew,
                  st_swCOSnew,
                  st_swXout,
                  st_swYout,
                  zcal_swThetaErr,  		// Electrical Theta of Z pulse calibration
                  uwAbsMotorHz,
                  zcal_uwPulseDiff, 		// DINO, 08/11/2010
                  BTTx_swDelatPGPosition;

Main_EXT UBYTE    
                  Delay4oc,
                  cfstep,
                  z0_cnt,
                  z1_cnt,
                  z2_cnt,
                  GROUPTmp,     			      // CalUBYTE: 6 UBYTE
                  ubPGData,
                  Speed_check,
                  BTTx_ubTorqDetectRst,      //[JES Torq Detect Function, Special.Kung, 2022/09/01]
                  BTTx_ubTestCase;           //[JES Torq Detect Function, Special.Kung, 2022/09/01]

Main_EXT UWORD    
                  TUNEPMLSLOW_V,  			   //ADDED BY SCOTTY 01/29/2007
                  st_uwInterval,  			   // StandStill falling counts, Added by dino, 04/03/2007
                  ol_uwDeraCnt,
                  uwEPS_SpdLimt,             //[User can change speed when used EPS function, Bernie, 2013/04/16]
				      AFE_uwMOCNT,    			   //[AFE Error Handle/Lyabryan/2022/03/24]
				      BTTx_uwFMI0Temp,           //[JES Torq Detect Function, Special.Kung, 2022/09/01]
				      BTTx_uwTestTorq,           //[JES Torq Detect Function, Special.Kung, 2022/09/01]
                  BTTx_uwTestStep,           //[JES Torq Detect Function, Special.Kung, 2022/09/01]
                  BTTx_uwPGPositionNow,      //[JES Torq Detect Function, Special.Kung, 2022/09/01]
                  BTTx_uwPGPositionOrg;      //[JES Torq Detect Function, Special.Kung, 2022/09/01]

Main_EXT SLONG    
                  SpdMaxPu,
                  AVIslFunVar,
                  AVIslFunVar_1,             //[UD protocal, Bernie, 2012/12/05]
                  ACIslFunVar,
                  AUIslFunVar,
                  slMotorHz,
                  ss4,                       // [IODLC, Lyabryan, 2016/11/11]
                  slSINsquarePu;             // Add by DINO, 09/05/2008
                  
Main_EXT ULONG    
                  IR_ulTcount,               //[Running Dir Count,Special,2018/08/17]
                  BTTx_ulClearbttnCount,     //[JES Torq Detect Function, Special.Kung, 2022/09/01]
				      BTTx_ulTestCount;          //[JES Torq Detect Function, Special.Kung, 2022/09/01]

Main_EXT UBYTE    
                  CPUError,
                  Error,
                  WarnCode,
                  PSW_CNT,
                  fanoffct,
                  PWR_Second,
                  TUNErrorCnt,
                  PWRSaveCNT,               // CalUBYTE: 8 UBYTE
                  Cnt_ubPGWait,
                  Driver_ID;                //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]

Main_EXT UBYTE_UNION    
                  mfi0_status,
                  mfi1_status,
                  mfi2_status,
                  inv_status,
                  inv1_status,
                  inv2_status,
                  inv3_status,        // DIN function
                  warn_status,
                  //err_status,
                  //err1_status,     //SCOTTY 09/05/2007
                  com1_status,
                  com2_status,
                  com3_status,
                  copy_status,
                  lock_status,
                  kpd1_status,
                  kpd2_status,
                  kpd3_status,
                  ext_status,
                  ext1_status,
                  ext2_status,
                  ext3_status,
                  led_status,
                  //cmd_status,
                  //sys_status,
                  //dir1_status,
                  //dir2_status,
                  //wg_status,
                  //wg1_status,
                  //tun_status,
                  //tun1_status,
                  //pre_status,
                  //pre1_status,
                  pg_status,
                  DBC_status,
                  Con_status,
                  Con1_status,
                  WREP_status,
                  //APR_status,
                  //APR_status1,
                  PMstart_status,     //ADDED BY SCOTTY 2007/01/29
                  exto_status,        //ADDED BY Dino, 2008/02/29
                  edt_status,
                  SMTRISE_status,     //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
                  FAN_status,         //ADDED BY SCOTTY   2007/10/15
                  VH_status,          // CalUBYTE: 37 UBYTE
                  WREP_status2,       // [IED 1387 static Tune, 2011/07/06]
                  Time_srquence,      //[DIN time sequence, Bernie, 2013/03/07]
                  SPD_PG_quality,     //[PG quality function, Bernie, 2017/06/20]
                  BTTx_status,
                  AFE_Handle_Flag;
                        
Main_EXT UWORD          
                  st_uwAbsAngleTune,  //[Fix state tune problem, Bernie, 2014/09/02 ]
                  hsd_uwAbsAngle,     //[PGHSD-1 abs angle,Lyabryan,2017/07/17]
                  zcal_uwMTU1cnt;     //[PG count for annoy,Lyabryan,2017/07/17]

Main_EXT UWORD_UNION    
                  dir_status,
                  err_status,
                  cmd_status,
                  wg_status,
                  tun_status,
                  key_status,
                  pre_status,
                  pre_status2,
                  IEDPG_status,
                  APR_status,
                  wg_status_CC,       //[CC Display, Bernie, 2017/04/12]
                  tb_status,
                  EPS_POWER_SWITCH,   //[EPS MO Output,Lyabryan,2018/06/19]
                  Sibocom_spflag,
                  Sibocom_ENflag;


#pragma address fcmd=0x0000a100             //[Address fixed, Aevin, 2017/06/28]
Main_EXT ULONG_UNION    
                  fcmd,
                  fcmd_vf,
                  ftemp,
                  fexternal,
                  fslip,
                  mcount,
                  Pinput;

Main_EXT UWORD_UNION    
                  Service_time,
                  Star_con_status;


Main_EXT PARAM_ATTR attr[PRMAX];

Main_EXT CalLine        AD2DcB1, AD2DcB2,  // AD to DC Bus Line 1[(x1,y1),(x2,y2)], Line 2[(x2,y2),(x3,y3)]
                        DcB2AD1, DcB2AD2;  // DC Bus to AD Line 1[(x1,y1),(x2,y2)], Line 2[(x2,y2),(x3,y3)]

Main_EXT UWORD 			uwVfd_Explorer_Count;	//for count is in VFD Explorer?---------------7/2/2015
Main_EXT UWORD 			uwVfd_Explorer_Flag;	// 1=in explorer mode ; 0 = in normal mode----7/2/2015
Main_EXT UBYTE 			ubNew_VfdExplorerFlag;// 1: use new vfd explorer ; 0; use old vfd explorer--4/7/2016

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
