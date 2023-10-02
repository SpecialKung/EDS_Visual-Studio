#ifdef _PrHandel_C
   #define PRHANDEL_EXT 
#else
   #define PRHANDEL_EXT extern
#endif

#ifdef _PrHandel_C

/*------------- Table of parameter Group ---------------------------------------------*/
const UWORD prtab[(GRALL+1)]={
        GROUP0, GROUP1, GROUP2, GROUP3, GROUP4, GROUP5, GROUP6, GROUP7, GROUP8, GROUP9,
        GROUP10,GROUP11,GROUP12,GROUP13,GROUP14, GROUP15,
};

const UWORD pr_gpno_Sibo[(GRALL+1)]={ //[Only 32 MAP parameter,Lyabryan,2020/09/13]
      (GROUP1-GROUP0), (GROUP2-GROUP1),  (GROUP3-GROUP2),   (GROUP4-GROUP3),
      (GROUP5-GROUP4), (GROUP6-GROUP5),  (GROUP7-GROUP6),   (GROUP8-GROUP7),
      (GROUP9-GROUP8), (GROUP10-GROUP9), (GROUP11-GROUP10), (GROUP12-GROUP11),
      (GROUP13-GROUP12), (GROUP14-GROUP13), (EPMAX-GROUP14), GROUP0,
};

const UWORD pr_gpno[(GRALL+1)]={
      (GROUP1-GROUP0), (GROUP2-GROUP1),  (GROUP3-GROUP2),   (GROUP4-GROUP3),
      (GROUP5-GROUP4), (GROUP6-GROUP5),  (GROUP7-GROUP6),   (GROUP8-GROUP7),
      (GROUP9-GROUP8), (GROUP10-GROUP9), (GROUP11-GROUP10), (GROUP12-GROUP11),
      (UMAP_ADD34-GROUP12), (UMAP_DATA34-GROUP13), (EPMAX-GROUP14), GROUP0,
      //[Only 32 MAP parameter,Lyabryan,2020/09/13]
      //32, 32, (EPMAX-GROUP14), GROUP0,
};

/*------------- Table of parameter attribute ------------------------------------------------
  Low byte: 0                    1          2        3       4       5       6       7
            Limited              set        Select   read    allow
            List by something,   running.   List     only.   reset.
            Give a limit value              jmp to ?
            -------------------------------------------------------------------------------
  HI byte : 8,9                    10      11      12      13      14      15
            dot                                                    No      Hide
            location                                               Copy    Pr
  Low byte:
  Bit 0: Limitation is a variable.
  Bit 1: Allow to set during the drive is running.
  Bit 2: Scroll to select the parameter item.
  Bit 3: Read Only.(1:Read only & monitor ; 0:Can write)
  
  Bit 4: Allow to Reset.
  Bit 5: Binary
  Bit 6: Hex
  Bit 7: Signed bit
  
  Bit 8,9: Dot location.
  Bit 10: Change Dot Location.
  Bit 11:
  
  Bit 12:
  Bit 13:
  Bit 14: Dosen't need to Copy
  Bit 15: Hiding parameters            
 --------------------------------------------------------------------------------------------*/
const PARAM_ATTR attr1[PRMAX] = {
//                           attribute                  min,            max,        default,
/*--------      GROUP 15        --------*/            
/* 15-00  DEBUG_F1    */  RLD|WRUN|DOT0|DPH,              0,          65535,              0,       
/* 15-01  DBCCHG_F    */  RLD|WRUN|DOT2,                  0,           MAXF,           1200,       
/* 15-02  PFEF        */      WRUN|DOT0,                  1,            200,             95,       
/* 15-03  DC_ZSEARCH  */  RLD|WRUN|DOT0,                  0,            100,             40,
/* 15-04  AD_IRATE    */      WRUN|DOT0,                  0,           1023,            145,       
/* 15-05  IDQELPFG    */      WRUN|DOT0,                  0,            200,            100,       
/* 15-06  FACTORY1    */      WRUN|DOT0,                  0,          65535,              0,       
/* 15-07  FACTORY2    */      WRUN|DOT0,                  0,          65535,              0,       
/* 15-08  FACTORY3    */      WRUN|DOT0,                  0,          65535,              0,       
/* 15-09  FACTORY4    */      WRUN|DOT0,                  0,          65535,              0,       
/* 15-10  PWM_MODE    */      WRUN|DOT0,                  0,          65535,              0,
/* 15-11  SKIP_DT     */  RLD|WRUN|DOT0,                  0,   DeadTime_2*2,     DeadTime_2,       
/* 15-12  DCB_AD1     */      WRUN|DOT0,                220,           2441,           1638,       
/* 15-13  DCB_AD2     */      WRUN|DOT0,               1389,           3081,           2441,       
/* 15-14  DCB_AD3     */      WRUN|DOT0,               2326,           3800,           3081,       
/* 15-15  TRQ_P       */  RLD|WRUN|DOT0,                  0,          65535,            100,       
/* 15-16  TRQ_I       */  RLD|WRUN|DOT0,                  0,          65535,            100,       
/* 15-17  FLUX_P      */  RLD|WRUN|DOT0,                  0,          65535,            100,       
/* 15-18  FLUX_I      */  RLD|WRUN|DOT0,                  0,          65535,            100,       
/* 15-19  SpdSlop_P   */  RLD|WRUN|DOT0,                  0,          65535,           7618,       
/* 15-20  SpdSlop_I   */  RLD|WRUN|DOT0,                  0,          65535,             30,       
/* 15-21  CTRLSEL     */  RLD|WRUN|DOT0|DPH,              0,          65535,              0,       
/* 15-22  TESTAmp     */  RLD|WRUN|DOT0,                  0,          65535,              0,       
/* 15-23  HiSpd_LPG   */  RLD|WRUN|DOT0,                  0,           2000,            100,       
/* 15-24  LoSpd_LPG   */  RLD|WRUN|DOT0,                  0,           2000,             50,       
/* 15-25  TESTBias    */  RLD|WRUN|DOT0,                  0,          65535,              0,       
/* 15-26  EstJ_LPG    */  RLD|WRUN|DOT3,                  0,          65535,              3,       
/* 15-27  CALI_REF    */  RLD|WRUN|DOT0,                  0,          65535,          16384,       
/* 15-28  CALI_P      */  RLD|WRUN|DOT0,                  0,          65535,           2000,       
/* 15-29  CALI_I      */  RLD|WRUN|DOT0,                  0,          65535,            500,       
/* 15-30  DCTUN_P     */  RLD|WRUN|DOT0,                  0,          65535,             50,       
/* 15-31  DCTUN_I     */  RLD|WRUN|DOT0,                  0,          65535,            150,       
/* 15-32  HFTUN_P     */  RLD|WRUN|DOT0,                  0,          65535,           3500,       
/* 15-33  DCBUSLPG    */  RLD|WRUN|DOT3,                  0,          65535,            100,       
/* 15-34  VCMP_K      */  RLD|WRUN|DOT0,                  1,            300,            200,       
/* 15-35  NLBOOST     */  RLD|WRUN|DOT0,                  0,            100,             50,       
/* 15-36  AKP         */  RLD|DOT0,                       1,          65535,           5000,       
/* 15-37  AKI         */  RLD|DOT0,                       1,          65535,            100,       
/* 15-38  CULPBW      */  RLD|WRUN|DOT0,                  0,          65535,            290,       
/* 15-39  DBLEAD2     */      WRUN|DOT0,                  0,          65535,           4096,       
/* 15-40  DBRATIO2    */      WRUN|DOT0,                  0,          65535,          10000,       
/* 15-41  DBC1        */      WRUN|DOT0,                  0,          65535,            350,       
/* 15-42  DBC2        */      WRUN|DOT0,                  0,          65535,             90,       
/* 15-43  DBLEAD      */      WRUN|DOT0,                  0,          65535,            512,       
/* 15-44  DBRATIO     */      WRUN|DOT0,                  0,          65535,           2500,       
/* 15-45  DBC_MODE    */  RLD|WRUN|DOT0,                  0,          65535,              0,       
/* 15-46  LMPU1       */  RLD|WRUN|DOT0,                  0,          65535,          10380,       
/* 15-47  EMFPU1      */  RLD|WRUN|DOT0,                  0,          65535,           8163,       
/* 15-48  LMPU2       */  RLD|WRUN|DOT0,                  0,          65535,           9817,       
/* 15-49  EMFPU2      */  RLD|WRUN|DOT0,                  0,          65535,          13101,       
/* 15-50  LMPU3       */  RLD|WRUN|DOT0,                  0,          65535,           9235,       
/* 15-51  EMFPU3      */  RLD|WRUN|DOT0,                  0,          65535,          14748,       
/* 15-52  LMPU4       */  RLD|WRUN|DOT0,                  0,          65535,           8192,       
/* 15-53  EMFPU4      */  RLD|WRUN|DOT0,                  0,          65535,          16384,       
/* 15-54  LMPU5       */  RLD|WRUN|DOT0,                  0,          65535,           6678,       
/* 15-55  EMFPU5      */  RLD|WRUN|DOT0,                  0,          65535,          22106,       
/* 15-56  LMPU6       */  RLD|WRUN|DOT0,                  0,          65535,           5150,       
/* 15-57  EMFPU6      */  RLD|WRUN|DOT0,                  0,          65535,          31267,       
/* 15-58  MOD_INDEX   */  RLD|WRUN|DOT2,                 80,          65535,            100,       
/* 15-59  IZEROLPG    */  RLD|WRUN|DOT0,                  0,          65535,             33,       
/* 15-60  COSPHILPG   */  RLD|WRUN|DOT3,                  1,          65535,            100,       
/* 15-61  DATECODE    */S2EEP|RLD|READ|DOT3,              0,          65535,       DateCode,  // Datecode para change, Henry, 2016/07/20
/* 15-62  CAUI2ZERO   */      WRUN|DOT0,               1848,           2248,           2046,       
/* 15-63  CAUI2MAX    */      WRUN|DOT0,               3695,           4095,           4095,       
/* 15-64  CAUI2MIN    */      WRUN|DOT0,                  0,            400,              0,       
/* 15-65  CACIMAX     */      WRUN|DOT0,               3695,           4095,           4095,       
/* 15-66  CACIMID     */      WRUN|DOT0,               2252,           2652,           2452,
/* 15-67  CACIMIN     */      WRUN|DOT0,                416,           1217,            816,       
/* 15-68  CAUI1ZERO   */      WRUN|DOT0,               1848,           2248,           2046,       
/* 15-69  CAUI1MAX    */      WRUN|DOT0,               3695,           4095,           4095,       
/* 15-70  CAUI1MIN    */      WRUN|DOT0,                  0,            400,              0,       
/* 15-71  DKP         */       RLD|DOT0,                  0,          65535,           5000,       
/* 15-72  DKI         */       RLD|DOT0,                  0,          65535,            100,       
/* 15-73  LOW_SPEED   */  RLD|WRUN|DOT2,                  0,            800,            150,       
/* 15-74  PGDETCNT    */  RLD|WRUN|DOT0,                  0,          65535,            200,       
/* 15-75  FMAIN       */       RLD|DOT2,                  0,           MAXF,           6000,       
/* 15-76  PWR_CNT     */      READ|DOT0,                  0,          65535,              0,       
/* 15-77  GFF_REC_SW  */	   RLD|DOT0,				  0,			  1,			  0,	 
/* 15-78  BLD_VER     */ S2EEP|RLD|READ|DOT2,             0,          65535,              0,   //BLD_VER [BootLoader Version, Special.Kung, 2022/10/31]     
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
/* 15-79  SIBO_EPS_FRMODE */   RLD|DOT0,                  0,          	  4,              1,   
#else
/* 15-79  RESERVE     */      READ|DOT0,                  0,          65535,              0,      
#endif
/* 15-80  OPHL_Sp_er  */       RLD|DOT2,                  0,           1000,           1000,   
/* 15-81  OPHL_Cur_er */       RLD|DOT2,                  0,           1000,            550,         
/* 15-82  OPHL_er_cnt */       RLD|DOT1,                100,          10000,            300,        
/* 15-83  BLD_DATECODE*/ S2EEP|RLD|READ|DOT3,             0,          65535,              0,   //[BootLoader DataCode, Special.Kung, 2022/10/31]      
/* 15-84  FAUIZERO    */      WRUN|DOT1,               4620,           5620,           5115,       
/* 15-85  FAUIMAX     */      WRUN|DOT1,               9230,          10230,          10230,       
/* 15-86  FAUIMIN     */      WRUN|DOT1,                  0,           1000,              0,       
/* 15-87  SINMAX      */      WRUN|DOT0,                  0,         0xffff,           4095,       
/* 15-88  SINMIN      */      WRUN|DOT0,                  0,         0xffff,              0,       
/* 15-89  COSMAX      */      WRUN|DOT0,                  0,         0xffff,           4095,       
/* 15-90  COSMIN      */      WRUN|DOT0,                  0,         0xffff,              0,       
/* 15-91  MINI_PULSE  */      WRUN|DOT1,                 10,             40,             20,  
/* 15-92  FAN_Dframe  */      WRUN|DOT0,                  0,              1,              0,
/* 15-93  Z_SECT      */           DOT0,                  0,              6,              6,
/* 15-94  RESERVE     */      READ|DOT0,                  0,          65535,              0,    
/* 15-95  PG_POSatLV  */      WRUN|DOT0,                  0,          65535,          32767,
/* 15-96  DAMAX       */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 15-97  DAMIN       */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 15-98  RLY_TIME    */  RLD|WRUN|DOT3,                  0,           2000,            500,      
/* 15-99  DEBUG_F2    */  RLD|WRUN|DOT0|DPH,              0,          65535,              0, 
/* 15-100 ZCAB_MODE   */      	   DOT0,                  0,              2,              0,
/* 15-101 Qer_min     */  RLD|WRUN|DOT0,                  0,            500,              0,   
/* 15-102 Qer_Shift   */  RLD|WRUN|DOT0,                  1,              5,              4,      
/* 15-103 Sin_HS_Tab  */      WRUN|DOT0,                  0,          	  1,              0,
/* 15-104 RESERVE     */      READ|DOT0,                  0,          65535,              0,
/* 15-105 RESERVE     */      READ|DOT0,                  0,          65535,              0,
/* 15-106 CAN_CTRL    */  RLD|WRUN|DOT0,                  0,              1,              0, //[CAN Control, Sampo, 09/15/2010]
/* 15-107 CAN_FAULT   */  RLD|WRUN|DOT0,                  0,              3,              3, //[CAN Control, Sampo, 09/15/2010]
/* 15-108 DEBUG_PG    */  RLD|WRUN|DOT0|DPH,              0,          65535,              0,
/* 15-109 47th_DISP   */       RLD|DOT0,                  0,           9999,            407,
/* 15-110 PG_MODE     */  RLD|WRUN|DOT0|DPH,              0,          65535,              0, //0x0400    ////[Modify display to Hexadecimal, Bernie, 11/24/2011]
/* 15-111 WDT_DIV     */      RLD|WRUN|DOT0,              0,          65535,              0, //[ICT WDT test, Bernie, 08/16/2011]
/* 15-112 AFM1_P10CNT */      DOT0|WRUN,                  0,           2700,           2380, //[change maximum valie, Bernie, 2017/04/14]  //[change limit valie, Bernie, 2014/09/23]
/* 15-113 AFM1_0CNT   */      DOT0|WRUN,                  0,           2700,           2354, //[change maximum valie, Bernie, 2017/04/14]  //[change limit valie, Bernie, 2014/09/23]
/* 15-114 AFM1_M10CNT */      DOT0|WRUN,                  0,           2700,           2410, //[change maximum valie, Bernie, 2017/04/14]  //[change limit valie, Bernie, 2014/09/23]
/* 15-115 AFM2_P10CNT */      DOT0|WRUN,                  0,           2700,           2380, //[change maximum valie, Bernie, 2017/04/14]  //[change limit valie, Bernie, 2014/09/23]
/* 15-116 AFM2_0CNT   */      DOT0|WRUN,                  0,           2700,           2354, //[change maximum valie, Bernie, 2017/04/14]  //[change limit valie, Bernie, 2014/09/23]
/* 15-117 AFM2_M10CNT */      DOT0|WRUN,                  0,           2700,           2410, //[change maximum valie, Bernie, 2017/04/14]  //[change limit valie, Bernie, 2014/09/23]
/* 15-118 PROTECT_BIT */  RLD|WRUN|DOT0|DPH,              0,          65535,              0, //[The switch of Protect finction, Bernie, 2015/05/21]
/* 15-119 OPH2_CNT    */  RLD|WRUN|DOT0,                  0,          65535,            100, //[The switch of Protect finction, Bernie, 2015/05/21]
/* 15-120 OPH2_IRMS   */  RLD|WRUN|DOT0,                  0,          65535,            150, //[The switch of Protect finction, Bernie, 2015/05/21]
/* 15-121 OPH2_GAIN   */  RLD|WRUN|DOT0,                  0,          65535,              2, //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 15-122 PPI_C       */  RLD|WRUN|DOT0,                  0,          65535,              2,
/* 15-123 MBF_ERR_REC */      READ|DOT0,                  0,          65535,              0, //[MBF can be recorded after power down, Bernie, 2016/02/19]
/* 15-124 EOL_RECODHI */      READ|DOT0,                  0,          65535,              0, //[add for UL EoL Verification,Bernie, 2013/04/22]
/* 15-125 EOL_RECODLO */      READ|DOT0,                  0,          65535,              0, //[add for UL EoL Verification,Bernie, 2013/04/22]
/* 15-126 Par126      */      WRUN|DOT0,                  0,          65535,              0,
/* 15-127 RESERVE     */      READ|DOT0,                  0,          65535,              0,
///* 15-127 PPI_C     */    RLD|WRUN|DOT0,                0,          65535,              2,

/*---------     00 GROUP        --------*/
/* 00-00 HPSPEC       */S2EEP|READ|DOT0,                  0,          65535,              0,
/* 00-01 I_RATE2      */S2EEP|RLD|READ|DOT2,              0,          65535,              0,
/* 00-02 PRRESET      */S2EEP|RLD|DOT0,                   0,          65535,              0,
/* 00-03 S_DISP       */  RLD|WRUN|DOT0,                  0,      STDISPMAX,              0,
/* 00-04 U_DISP       */  RLD|WRUN|DOT0,                  0,     MFDPAGEMAX,              0,
/* 00-05 U_SET        */  RLD|WRUN|DOT0,                  0,          39999,              0,
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
/* 00-06 SW_VER       */S2EEP|RLD|READ|DOT3,              0,           9999,       SWVERS_H,
#else
/* 00-06 SW_VER       */S2EEP|RLD|READ|DOT2,              0,           9999,       SWVERS_H,
#endif
/* 00-07 PSW_IN       */S2EEP|WRUN|DOT0,                  0,          65535,              0,
/* 00-08 PSW_SET      */S2EEP|WRUN|DOT0,                  0,          65535,              0,
/* 00-09 CTRLM        */  RLD|DOT0,                       0,              8,              0,
/* 00-10 UNITSEL      */  RLD|WRUN|DOT0,                  0,              3,              0,
/* 00-11 CHG_DIR      */  RLD|DOT0,                       0,              1,              0,
/* 00-12 SETCRF       */  RLD|WRUN|DOT0,                  2,             15,             12,
/* 00-13 AVR          */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 00-14 SOFC         */  RLD|WRUN|DOT0,                  1,              5,              1,
/* 00-15 SOOC         */  RLD|WRUN|DOT0,                  1,              2,              1,

/*--------      01 GROUP        -------*/
/* 01-00 FMAX         */  RLD|DOT2,                     500,           MAXF,           6000,    //[Change minimum value of 01-00 to 5, Bernie, 2016/12/27]
/* 01-01 MFBASE1      */  RLD|JMP|DOT2,                   0,           MAXF,           6000,
/* 01-02 VMAX1        */  RLD|JMP|V440|DOT1,              0,           5100,           4400,
/* 01-03 FMID1_1      */  RLD|DOT2,                       0,           MAXF,             50,
/* 01-04 VMID1_1      */  RLD|WRUN|V440|DOT1,             0,           5100,            100,
/* 01-05 FMID1_2      */  RLD|DOT2,                       0,           MAXF,             50,
/* 01-06 VMID1_2      */  RLD|WRUN|V440|DOT1,             0,           5100,            100,
/* 01-07 FMIN1        */  RLD|DOT2,                       0,           MAXF,              0,
/* 01-08 VMIN1        */  RLD|WRUN|V440|DOT1,             0,           5100,            100,
/* 01-09 FSTART       */  CHG|RLD|DOT2,                   0,           MAXF,             50,
/* 01-10 FUPPER       */  CHG|RLD|WRUN|DOT2,              0,           MAXF,           MAXF,
/* 01-11 FLOWER       */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 01-12 ACCEL1       */  CHG|RLD|WRUN|DOT1,              0,          60000,            300,
/* 01-13 DECEL1       */  CHG|RLD|WRUN|DOT1,              0,          60000,            200,
/* 01-14 ACCEL2       */  CHG|RLD|WRUN|DOT1,              0,          60000,            300,
/* 01-15 DECEL2       */  CHG|RLD|WRUN|DOT1,              0,          60000,            200,
/* 01-16 ACCEL3       */  CHG|RLD|WRUN|DOT1,              0,          60000,            300,
/* 01-17 DECEL3       */  CHG|RLD|WRUN|DOT1,              0,          60000,            200,
/* 01-18 ACCEL4       */  CHG|RLD|WRUN|DOT1,              0,          60000,            300,
/* 01-19 DECEL4       */  CHG|RLD|WRUN|DOT1,              0,          60000,            200,
/* 01-20 JOGACC       */  CHG|RLD|WRUN|DOT1,              0,          60000,            100,
/* 01-21 JOGDEC       */  CHG|RLD|WRUN|DOT1,              0,          60000,            100,
/* 01-22 JOGF         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            600,
/* 01-23 FAD1_AD4     */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 01-24 S4ACC1       */  CHG|RLD|WRUN|DOT1,              0,           2500,            100,
/* 01-25 S4ACC2       */  CHG|RLD|WRUN|DOT1,              0,           2500,            100,
/* 01-26 S4DEC1       */  CHG|RLD|WRUN|DOT1,              0,           2500,            100,
/* 01-27 S4DEC2       */  CHG|RLD|WRUN|DOT1,              0,           2500,            100,
/* 01-28 SL_ZSP       */  RLD|DOT0,                       0,              2,              1,
/* 01-29 FLAND        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 01-30 S4DEC3       */  CHG|RLD|WRUN|DOT1,              0,           2500,            100,
/* 01-31 DECEL5       */  CHG|RLD|WRUN|DOT1,              0,          60000,            200,
/* 01-32 FSD          */  RLD|DOT3,                     500,           3000,           1500,
/* 01-33 IODHT        */  RLD|DOT2,                       0,           6000,            300,
/* 01-34 IODLT        */  RLD|DOT2,                       0,           6000,            300,
/* 01-35 CRPLS_Jlim   */  RLD|DOT2,                       0,           1000,            200,
/* 01-36 IODDE        */  RLD|DOT2,                       0,          10000,           3000,
/* 01-37 IODDER       */  READ|DOT2,                      0,          65535,              0,
/* 01-38 IODEN        */  RLD|DOT0|DPH,                   0,              3,              0,
/* 01-39 FETS         */  RLD|DOT2,                     500,           MAXF,           6000,    
/* 01-40 DECEL_ESD    */  RLD|WRUN|DOT1,                  0,          60000,            200,
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
/* 01-41 SIBO_DECH4   */  CHG|RLD|WRUN|DOT1   ,           0,          60000,           1257,
/* 01-42 SIBO_S3H4    */  CHG|RLD|WRUN|DOT1   ,           0,           2500,             31,
/* 01-43 SIBO_S4H4    */  CHG|RLD|WRUN|DOT1   ,           0,           2500,             62,
#endif
/*--------      GROUP 02        --------*/
/* 02-00 WIRE2_3      */  RLD|DOT0,                       0,              5,              0,
/* 02-01 MI1          */  RLD|DOT0,                       0,         MFIMAX,              1,
/* 02-02 MI2          */  RLD|DOT0,                       0,         MFIMAX,              2,
/* 02-03 MI3          */  RLD|DOT0,                       0,         MFIMAX,              3,
/* 02-04 MI4          */  RLD|DOT0,                       0,         MFIMAX,              4,
/* 02-05 MI5          */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 02-06 MI6          */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 02-07 MI7          */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 02-08 MI8          */  RLD|DOT0,                       0,         MFIMAX,             40,
/* 02-09 DIN_RES      */  RLD|WRUN|DOT3,                  1,          30000,              5,
/* 02-10 MI_INV       */  RLD|WRUN|DOT0|DPH,              0,          65535,              0,    //[Change the attribution from decimal to hexadecimal, Bernie, 2016/02/22]
/* 02-11 RLY1         */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-12 RLY2         */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-13 MO1          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-14 MO2          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-15 MO3          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-16 MO4          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-17 MO5          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-18 MO6          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-19 MO7          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-20 MO8          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-21 MO9          */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-22 MO10         */  RLD|WRUN|DOT0,                  0,         MFOMAX,              0,
/* 02-23 MO_INV       */  RLD|WRUN|DOT0|DPH,              0,          65535,              0,    //[Change the attribution from decimal to hexadecimal, Bernie, 2016/02/22]
/* 02-24 SEQMOD       */  RLD|DOT0,                       0,              1,              0,
/* 02-25 DESIRE_F1    */  CHG|RLD|WRUN|DOT2,              0,           MAXF,           6000,
/* 02-26 DESIRE_F1B   */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            200,
/* 02-27 DESIRE_F2    */  CHG|RLD|WRUN|DOT2,              0,           MAXF,           6000,
/* 02-28 DESIRE_F2B   */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            200,
/* 02-29 BRK_RUNDT    */  RLD|DOT3,                       0,          65000,            250,
/* 02-30 BRK_STOPDT   */  RLD|DOT3,                       0,          65000,            250,
/* 02-31 MCDELAY_RUN  */  RLD|WRUN|DOT3,                 10,          65000,            200,
/* 02-32 MCDELAY_STOP */  RLD|WRUN|DOT3,                 10,          65000,            200,
/* 02-33 IS_DETECT    */  RLD|WRUN|DOT0,                  0,            100,              0,
/* 02-34 SP_AREA      */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 02-35 BRK_CHKTIME  */  RLD|WRUN|DOT2,                  0,           1000,              0,
/* 02-36 MC_CHKTIME   */  RLD|WRUN|DOT2,                  0,           1000,              0,
/* 02-37 BRK_CHKTQR   */  RLD|DOT0,                       0,              1,              0,
/* 02-38 SCDELAY_RUN  */  RLD|WRUN|DOT3,                 10,          65000,            200,
/* 02-39 SCDELAY_STOP */  RLD|WRUN|DOT3,                 10,          65000,            200,
/* 02-40 LSM          */  RLD|WRUN|DOT0,                  0,              2,              2,    //#15977, LULD detect, James, 2021/04/01
/* 02-41 LS_OPEN_TIME */  RLD|WRUN|DOT1,                  0,            100,             30,    //#15977, LULD detect, James, 2021/04/01
/* 02-42 LS_SHORT_TIME*/  RLD|WRUN|DOT1, 				  0, 		    100, 			 30,    //#15977, LULD detect, James, 2021/04/01
/* 02-43 SpdAgree_B   */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            200,    // 202 02-40   Band of Speed Agree Function #18572 
/* 02-44 STO_SHORT_T  */  RLD|WRUN|DOT1,                  0,            100,             10,    //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
/* 02-45 Sensor819    */  RLD|DOT0,                       0,              4,              0,    //[Artemis Add Sensor819 Function/Special/2022/06/06]
/* 02-46 Lift_SPD     */  CHG|RLD|WRUN|DOT2,             10,            400,             80,    //[Artemis Add Sensor819 Function/Special/2022/06/06]


/*--------      GROUP 03        --------*/
/* 03-00 AUI1_SL      */  RLD|WRUN|DOT0,                  0,             10,              1,
/* 03-01 ACI_SL       */  RLD|WRUN|DOT0|READ,             0,              0,              0,    //[ACI function remove, Bernie, 01/20/2012]
/* 03-02 AUI2_SL      */  RLD|WRUN|DOT0,                  0,             10,              0,
/* 03-03 AUI1BIAS     */ SIGN|RLD|WRUN|DOT1,          -1000,           1000,              0,
/* 03-04 ACIBIAS      */ SIGN|RLD|WRUN|DOT1|READ,     -1000,           1000,              0,
/* 03-05 AUI2BIAS     */ SIGN|RLD|WRUN|DOT1,          -1000,           1000,              0,
/* 03-06 AUI1_PN      */  RLD|WRUN|DOT0,                  0,              4,              0,
/* 03-07 ACI_PN       */  RLD|WRUN|DOT0|READ,             0,              1,              0,
/* 03-08 AUI2_PN      */  RLD|WRUN|DOT0,                  0,              4,              0,
/* 03-09 AUI1GA       */ SIGN|RLD|WRUN|DOT1,          -5000,           5000,           1000,
/* 03-10 ACIGA        */ SIGN|RLD|WRUN|DOT1|READ,         0,           5000,           1000,
/* 03-11 AUI2GA       */ SIGN|RLD|WRUN|DOT1,          -5000,           5000,           1000,
/* 03-12 AUI1_LPG     */  RLD|WRUN|DOT2,                  0,            200,              1,
/* 03-13 ACI_LPG      */  RLD|WRUN|DOT2|READ,             0,            200,              1,
/* 03-14 AUI2_LPG     */  RLD|WRUN|DOT2,                  0,            200,              1,
/* 03-15 LOCELTUN     */  RLD|DOT0|WRUN,                  0,              2,              0,
/* 03-16 AFMCALIB     */  S2EEP|RLD|WRUN|DOT0|DPH,        0,          65535,              0,
/* 03-17 AFM1         */  RLD|WRUN|DOT0,                  0,         AFMMAX,              0,
/* 03-18 AFMGA1       */  RLD|WRUN|DOT1,                  0,           2000,           1000,
/* 03-19 AFM1_MINUS   */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 03-20 AFM2         */  RLD|WRUN|DOT0,                  0,         AFMMAX,              0,
/* 03-21 AFMGA2       */  RLD|WRUN|DOT1,                  0,           2000,           1000,
/* 03-22 AFM2_MINUS   */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 03-23 AUI1_POLAR   */  RLD|DOT0,                       0,              1,              0,
/* 03-24 AUI2_POLAR   */  RLD|DOT0,                       0,              1,              0,
// 03-25 AUI1_COMMUN  */  RLD|WRUN|DOT0,                  0,           4096,           4096,    //	23X 03-25 AUI1 Communciate   //[DLC, Bernie, 2014/10/06]
// 03-26 AUI2_COMMUN  */  RLD|WRUN|DOT0,                  0,           4096,           4096,    //	23X 03-26 AUI2 Communciate


/*--------			GROUP	04				--------*/  
/* 04-00 FMI0         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-01 FMI1         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-02 FMI2         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-03 FMI3         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-04 FMI4         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-05 FMI5         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-06 FMI6         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-07 FMI7         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-08 FMI8         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-09 FMI9         */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-10 FMI10        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-11 FMI11        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-12 FMI12        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-13 FMI13        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-14 FMI14        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 04-15 FMI15        */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,

/* 04-16 RSQ_SPD      */  RLD|DOT2,                       1,             50,             10,    //[DLC, Bernie, 2014/10/06]
/* 04-17 LEV_SPD      */  RLD|DOT2,                       1,             50,              3,    
/* 04-18 AH_SPD       */  RLD|DOT2,                       1,             50,             50,
/* 04-19 ROPE_CMP	  */  RLD|DOT0, 					  0,		    100, 			  0,    //GFC Rope compensation, 2021/03/30		// Mitong 20220513 new
/* 04-20 TABST0_STATUS*/  READ|DOT0,                      0,          65535,              0, 
/* 04-21 TABST1_STATUS*/  READ|DOT0,                      0,          65535,              0,   
/* 04-22 MAX_FLOOR    */  RLD|DOT0,                       1,             75,              8,  
/* 04-23 LEV_CUR      */  RLD|DOT0,                       0,             75,              0, 
/* 04-24 PG_RST_MODE  */  RLD|DOT0,                       0,            100,            100,
/* 04-25 DelayCmp	  */  RLD|DOT3, 					  0,		  10000,			  3,    // Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 new
/* 04-26 LAND_DLY_TIME*/  RLD|DOT0,                       0,           3000,            500,   
/* 04-27 LEV_LEN      */  READ|RLD|DOT0,                  0,          65535,            215,
/* 04-28 INV_POS_H    */  READ|RLD|DOT0,                  0,          65535,              0,   
/* 04-29 INV_POS_L    */  READ|RLD|DOT0,                  0,           9999,              0, 
/* 04-30 CUR_PG_H     */  RLD|DOT0,                       0,          65535,              0,  
/* 04-31 CUR_PG_L     */  RLD|DOT0,                       0,          65535,              0,
/* 04-32 LEV_BRD_PG_H */  RLD|DOT0,                       0,          65535,              0,
/* 04-33 LEV_BRD_PG_L */  RLD|DOT0,                       0,          65535,              0,  
/* 04-34 SENSOR_H     */  RLD|DOT0,                       0,          65535,              0,
/* 04-35 SENSOR_L     */  RLD|DOT0,                       0,          65535,              0, 
/* 04-36 DLC_FUN      */  RLD|DOT0|DPH,                   0,          65535,              0,    
/* 04-37 PDO_TYPE     */  RLD|DOT0,                       0,              3,              0,
/* 04-38 DS_LEN       */  RLD|DOT0,                       0,           2000,              0,
/* 04-39 RATIO        */  RLD|DOT0,                      30,            100,            100,    //[ADCO EPS Modify] 
/* 04-40 DisDly 	  */  RLD|SIGN|DOT0,			    -30,		     30,			  0,    //#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
/* 04-41 EST_STATUS   */  READ|DOT0,                      0,          65535,              0,
/* 04-42 EST_COUNT    */  READ|DOT0,                      0,          65535,              0, 
/* 04-43 TABST0_COUNT */  READ|DOT0,                      0,          65535,              0, 
/* 04-44 TABST1_COUNT */  READ|DOT0,                      0,          65535,              0, 
/* 04-45 DD1_Vlim	  */  RLD|DOT2,						  0,		   9999,			  0,    //Artemis speed limit, James, 20200220
/* 04-46 DD2_Vlim	  */  RLD|DOT2,						  0,		   9999,			  0,    //Artemis speed limit, James, 20200220
/* 04-47 DD3_Vlim	  */  RLD|DOT2,						  0,		   9999,			  0,    //Artemis speed limit, James, 20200220
/* 04-48 DD4_Vlim	  */  RLD|DOT2,						  0,		   9999,			  0,    //Artemis speed limit, James, 20200220
/* 04-49 USER_PAGE    */  RLD|DOT0,                       0,              6,              0,    //adjust floor position,Henry,2019/01/07

// DLC position offset, Henry
/* 04-50 FL_POSIT_1H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-30   1Floor Position H 
/* 04-51 FL_POSIT_1L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-31   1Floor Position L 
/* 04-52 FL_POSIT_2H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-32   2Floor Position H 
/* 04-53 FL_POSIT_2L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-33   2Floor Position L 
/* 04-54 FL_POSIT_3H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-34   3Floor Position H 
/* 04-55 FL_POSIT_3L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-35   3Floor Position L 
/* 04-56 FL_POSIT_4H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-36   4Floor Position H 
/* 04-57 FL_POSIT_4L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-37   4Floor Position L 
/* 04-58 FL_POSIT_5H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-38   5Floor Position H 
/* 04-59 FL_POSIT_5L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-39   5Floor Position L 
/* 04-60 FL_POSIT_6H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-40   6Floor Position H 
/* 04-61 FL_POSIT_6L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-41   6Floor Position L 
/* 04-62 FL_POSIT_7H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-42   7Floor Position H 
/* 04-63 FL_POSIT_7L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-43   7Floor Position L 
/* 04-64 FL_POSIT_8H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-44   8Floor Position H 
/* 04-65 FL_POSIT_8L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-45   8Floor Position L 
/* 04-66 FL_POSIT_9H  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-46   9Floor Position H 
/* 04-67 FL_POSIT_9L  */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-47   9Floor Position L 
/* 04-68 FL_POSIT_10H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-48   10Floor Position H
/* 04-69 FL_POSIT_10L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-49   10Floor Position L
/* 04-70 FL_POSIT_11H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-50   11Floor Position H
/* 04-71 FL_POSIT_11L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-51   11Floor Position L
/* 04-72 FL_POSIT_12H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-52   12Floor Position H
/* 04-73 FL_POSIT_12L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-53   12Floor Position L
/* 04-74 FL_POSIT_13H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-54   13Floor Position H
/* 04-75 FL_POSIT_13L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-55   13Floor Position L
/* 04-76 FL_POSIT_14H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-56   14Floor Position H
/* 04-77 FL_POSIT_14L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-57   14Floor Position L
/* 04-78 FL_POSIT_15H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-58   15Floor Position H
/* 04-79 FL_POSIT_15L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-59   15Floor Position L
/* 04-80 FL_POSIT_16H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-60   16Floor Position H
/* 04-81 FL_POSIT_16L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-61   16Floor Position L
/* 04-82 FL_POSIT_17H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-62   17Floor Position H
/* 04-83 FL_POSIT_17L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-63   17Floor Position L
/* 04-84 FL_POSIT_18H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-64   18Floor Position H
/* 04-85 FL_POSIT_18L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-65   18Floor Position L
/* 04-86 FL_POSIT_19H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-66   19Floor Position H
/* 04-87 FL_POSIT_19L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-67   19Floor Position L
/* 04-88 FL_POSIT_20H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-68   20Floor Position H
/* 04-89 FL_POSIT_20L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-69   20Floor Position L
/* 04-90 FL_POSIT_21H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-70   21Floor Position H
/* 04-91 FL_POSIT_21L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-71   21Floor Position L
/* 04-92 FL_POSIT_22H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-72   22Floor Position H
/* 04-93 FL_POSIT_22L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-73   22Floor Position L
/* 04-94 FL_POSIT_23H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-74   23Floor Position H
/* 04-95 FL_POSIT_23L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-75   23Floor Position L
/* 04-96 FL_POSIT_24H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-76   24Floor Position H
/* 04-97 FL_POSIT_24L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-77   24Floor Position L
/* 04-98 FL_POSIT_25H */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-78   25Floor Position H
/* 04-99 FL_POSIT_25L */  READ|RLD|DOT0,                  0,          65535,              0,    //    2XX 04-79   25Floor Position L
                                                            
/*--------      GROUP 05        --------*/                  
/* 05-00 AUTO_T       */S2EEP|RLD|DOT0,                   0,             10,              0,
/* 05-01 MI_RAT1      */  RLD|DOT2,                       0,          65535,              0,
/* 05-02 P_RATED1     */  RLD|DOT2,                       0,          65535,              0,
/* 05-03 RPM_RATED1   */  RLD|DOT0,                       0,          65535,           1710,
/* 05-04 POLES1       */  RLD|JMP|DOT0,                   2,             48,              4,
/* 05-05 MI_NL1       */  RLD|DOT2,                       0,          65535,              0,
/* 05-06 Rs1          */  RLD|DOT3,                       0,          65535,              0,
/* 05-07 Rr1          */  RLD|DOT3,                       0,          65535,              0,
/* 05-08 Lm1          */  RLD|DOT1,                       0,          65535,              0,
/* 05-09 Lx1          */  RLD|DOT1,                       0,          65535,              0,
/* 05-10 SVC_VLPG     */  RLD|WRUN|DOT3,                  1,          10000,             20,
/* 05-11 SVC_SLPG     */  RLD|WRUN|DOT3,                  1,          10000,            100,
/* 05-12 TQRC_G       */  RLD|WRUN|DOT0,                  0,             10,              0,
/* 05-13 SLIPC        */  RLD|WRUN|DOT2,                  0,           1000,            100,
/* 05-14 SLIPDEVL     */  RLD|WRUN|DOT0,                  0,           1000,              0,
/* 05-15 SLIPDEVT     */  RLD|WRUN|DOT1,                  0,            100,             10,
/* 05-16 OSLIPWAY     */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 05-17 K_HUNT       */  RLD|WRUN|DOT0,                  0,          10000,           2000,
/* 05-18 RUNMIN       */  RLD|DOT0,                       0,           1439,              0,
/* 05-19 RUNDAY       */  RLD|DOT0,                       0,          65535,              0,
/* 05-20 CORELOSS     */      WRUN|DOT0,                  0,            250,             10,       
/* 05-21 PWR_MIN      */      READ|DOT0,                  0,          65535,              0,       
/* 05-22 PWR_DAY      */      READ|DOT0,                  0,          65535,              0,
/* 05-23 GENSL_G      */  RLD|WRUN|DOT1,                  0,           1000,              0,     //[slip compensation function, Bernie, 2012/06/20]
/* 05-24 SLIPC_G      */  RLD|WRUN|DOT1,                  0,           1000,              0,

/*--------      GROUP 06        --------*/
/* 06-00 LVL          */  RLD|WRUN|V440|DOT1,          3200,           4400,           3600,
/* 06-01 PHL          */  RLD|WRUN|DOT0,                  0,              2,              2,
/* 06-02 OCA          */  RLD|WRUN|DOT0,                  0,            250,              0,
/* 06-03 OCN          */  RLD|WRUN|DOT0,                  0,            250,              0,
/* 06-04 STALLSPD     */  RLD|WRUN|DOT0,                  0,              5,              0,
/* 06-05 OTDM         */  RLD|WRUN|DOT0,                  0,              4,              0,
/* 06-06 OTDL         */  RLD|WRUN|DOT0,                 10,            250,            150,
/* 06-07 OTDT         */  RLD|WRUN|DOT1,                  1,            600,              1,
/* 06-08 OTDM2        */  RLD|WRUN|DOT0,                  0,              4,              0,
/* 06-09 OTDL2        */  RLD|WRUN|DOT0,                 10,            250,            150,
/* 06-10 OTDT2        */  RLD|WRUN|DOT1,                  1,            600,              1,
/* 06-11 CURRENT_LIM  */  RLD|WRUN|DOT0,                  0,            250,            200,
/* 06-12 EOL1_SL      */  RLD|DOT0,                       0,              2,              2,
/* 06-13 EOL1_T       */  RLD|WRUN|DOT1,                300,           6000,            600,
/* 06-14 OHWL         */  RLD|WRUN|DOT1,                  0,           1100,            900,
/* 06-15 STALLIMIT    */  RLD|WRUN|DOT0,                  0,            100,             50,
/* 06-16 ERR_REC1     */  READ|DOT0,                      0,          65535,              0,
/* 06-17 ERR_REC2     */  READ|DOT0,                      0,          65535,              0,
/* 06-18 ERR_REC3     */  READ|DOT0,                      0,          65535,              0,
/* 06-19 ERR_REC4     */  READ|DOT0,                      0,          65535,              0,
/* 06-20 ERR_REC5     */  READ|DOT0,                      0,          65535,              0,
/* 06-21 ERR_REC6     */  READ|DOT0,                      0,          65535,              0,
/* 06-22 ERR_OPT1     */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 06-23 ERR_OPT2     */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 06-24 ERR_OPT3     */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 06-25 ERR_OPT4     */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 06-26 PTC_TREAM    */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 06-27 PTC_LEVEL    */  RLD|WRUN|DOT1,                  0,           1000,            500,
/* 06-28 PTC_DFT      */  RLD|WRUN|DOT2,                  0,           1000,             20,
/* 06-29 VEPS         */  RLD|V440|DOT1,                480,           7500,            480,
/* 06-30 ERR_OPTM     */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 06-31 MPHLM        */  RLD|DOT0,                       0,              1,              1,
/* 06-32 ERR_MIN1     */  READ|DOT0,                      0,          65535,              0,
/* 06-33 ERR_DAY1     */  READ|DOT0,                      0,          65535,              0,
/* 06-34 ERR_MIN2     */  READ|DOT0,                      0,          65535,              0,
/* 06-35 ERR_DAY2     */  READ|DOT0,                      0,          65535,              0,
/* 06-36 ERR_MIN3     */  READ|DOT0,                      0,          65535,              0,
/* 06-37 ERR_DAY3     */  READ|DOT0,                      0,          65535,              0,
/* 06-38 ERR_MIN4     */  READ|DOT0,                      0,          65535,              0,
/* 06-39 ERR_DAY4     */  READ|DOT0,                      0,          65535,              0,
/* 06-40 ERR_MIN5     */  READ|DOT0,                      0,          65535,              0,
/* 06-41 ERR_DAY5     */  READ|DOT0,                      0,          65535,              0,
/* 06-42 ERR_MIN6     */  READ|DOT0,                      0,          65535,              0,
/* 06-43 ERR_DAY6     */  READ|DOT0,                      0,          65535,              0,
/* 06-44 FEPS         */  CHG|RLD|DOT2,                   0,           MAXF,              0,    //#13769 Modify EPS speed, James, 07/01/2020
/* 06-45 LV_OPTM      */  RLD|WRUN|DOT0|DPH,              0,             15,              2,
/* 06-46 EPS_OPTM     */  RLD|WRUN|DOT0,                  0,              4,              0,    //[Modify EPS function, Bernie, 2012/11/27 ]
/* 06-47 GEN_T        */  RLD|WRUN|DOT1,                  0,             50,             10,
/* 06-48 UPS_CAP      */  RLD|DOT1,                       0,           1000,              0,
#if Artemis_ENABLE//04-36 //Enable for Artemis
/* 06-49 STO_LOCK     */  WRUN|RLD|DOT0|DPH,              0,         0x000F,              0,
#else
/* 06-49 STO_LOCK	  */  WRUN|RLD|DOT0|DPH,			  0,		 0x0007,			  0,
#endif
/* 06-50 REST_SLT     */  RLD|WRUN|DOT0,                  0,              1,              0,    //[Add auto restart after fault, Bernie, 06/06/12]
/* 06-51 RESTCNT      */  RLD|WRUN|DOT0,                  0,             10,              0,
/* 06-52 RESTINTERVAL */  RLD|WRUN|DOT1,                  5,           6000,            100,
/* 06-53 FKEY_REC     */  CHG|READ|DOT2,                  0,          65535,              0,
/* 06-54 FOUT_REC     */  CHG|READ|DOT2,                  0,          65535,              0,    
/* 06-55 ISUM_REC     */  READ|DOT2,                      0,          65535,              0,   
/* 06-56 FFBK_REC     */  CHG|READ|DOT2,                  0,          65535,              0, 
/* 06-57 VOUT_REC     */  READ|DOT1,                      0,          65535,              0,
/* 06-58 DCBUS_REC    */  READ|DOT1,                      0,          65535,              0, 
/* 06-59 POWER_REC    */  READ|DOT2,                      0,          65535,              0,
/* 06-60 TQ_REC       */  READ|DOT1,                      0,          65535,              0,
/* 06-61 TH_TEMP      */  READ|SIGN|DOT1,            -32768,          32767,              0,  
/* 06-62 MFI_REC      */  READ|DOT0|DPH,                  0,          65535,              0,
/* 06-63 MFO_REC      */  READ|DOT0|DPH,                  0,          65535,              0,
/* 06-64 STATE_REC    */  READ|DOT0|DPH,                  0,          65535,              0,
/* 06-65 CUR_LIM_UCMP */  RLD|WRUN|DOT0,                  0,            200,             85,   //[UCMP function, Bernie, 2016/06/14]
/* 06-66 SERVICE_COUNT*/  DOT0,                           0,          65535,              0,   //[Service time function, Bernie, 2017/03/14]
/* 06-67SERVICE_ENABLE*/  DOT0,                           0,              1,              0,   //[Service time function, Bernie, 2017/03/14]
/* 06-68 EPS_PF       */  RLD|DOT1|WRUN,                  0,           1500,            700,   //[Service time function, Bernie, 2017/03/14]
/* 06-69 EPS_PFREF    */  READ|DOT1|SIGN,             -2000,           2000,              0,   //[Service time function, Bernie, 2017/03/14]
/* 06-70 EPS_DIR      */  READ,                           0,              1,              0,   //[Service time function, Bernie, 2017/03/14]
/* 06-71 EPS_MO_DELAY */  CHG|DOT1|RLD|WRUN,              0,            100,             10,   //[Service time function, Bernie, 2017/03/14]
/* 06-72 EPS_MO_OFF   */  RLD|DOT1,                       0,            600,             30,   //[Service time function, Bernie, 2017/03/14]
/* 06-73 IR_COUNT_H   */  READ|DOT0, 					  0,		  60000,			  0,
/* 06-74 IR_COUNT_L   */  READ|DOT0, 					  0,		   9999,			  0,
/* 06-75 IR_TCOUNT_H  */  READ|DOT0, 					  0,		     20,			  0,
/* 06-76 IR_TCOUNT_L  */  READ|DOT0, 					  0,		   9999,			  0,
/* 06-77 IR_RESETC    */  READ|DOT0, 					  0,		    100,			  0,
/* 06-78 IR_LIFE      */  DOT2,                           0,          20000,            200,
/* 06-79 IR_ENABLE    */  DOT0,       			          0,		      2,			  0,
/* 06-80 FOUT_REC1    */  CHG|READ|DOT2,                  0,          65535,              0,
/* 06-81 DCBUS_REC1   */  READ|DOT1,                      0,          65535,              0,
/* 06-82 ISUM_REC1    */  READ|DOT2,                      0,          65535,              0,
/* 06-83 TH_TEMP1     */  READ|SIGN|DOT1,            -32768,          32767,              0,
/* 06-84 FOUT_REC2    */  CHG|READ|DOT2,                  0,          65535,              0,
/* 06-85 DCBUS_REC2   */  READ|DOT1,                      0,          65535,              0,
/* 06-86 ISUM_REC2    */  READ|DOT2,                      0,          65535,              0,
/* 06-87 TH_TEMP2     */  READ|SIGN|DOT1,            -32768,          32767,              0,
/* 06-88 FOUT_REC3    */  CHG|READ|DOT2,                  0,          65535,              0,
/* 06-89 DCBUS_REC3   */  READ|DOT1,                      0,          65535,              0,
/* 06-90 ISUM_REC3    */  READ|DOT2,                      0,          65535,              0,
/* 06-91 TH_TEMP3     */  READ|SIGN|DOT1,            -32768,          32767,              0,
/* 06-92 FOUT_REC4    */  CHG|READ|DOT2,                  0,          65535,              0,
/* 06-93 DCBUS_REC4   */  READ|DOT1,                      0,          65535,              0,
/* 06-94 ISUM_REC4    */  READ|DOT2,                      0,          65535,              0,
/* 06-95 TH_TEMP4     */  READ|SIGN|DOT1,            -32768,          32767,              0,
/* 06-96 FOUT_REC5    */  CHG|READ|DOT2,                  0,          65535,              0,
/* 06-97 DCBUS_REC5   */  READ|DOT1,                      0,          65535,              0,
/* 06-98 ISUM_REC5    */  READ|DOT2,                      0,          65535,              0,
/* 06-99 TH_TEMP5     */  READ|SIGN|DOT1,            -32768,          32767,              0,

/*--------      GROUP 07        --------*/
/* 07-00 DCBRK4V      */  RLD|WRUN|V440|DOT1,          7000,           9000,           7600,
/* 07-01 DCBRK_BAND	  */  RLD|WRUN|V440|DOT1,	          0,		   1000,		      0,    // [DCBRK_BAND function for adjustable reset level, James, 2019/12/05  ]
/* 07-02 DCICL        */  RLD|WRUN|DOT0,                  0,            100,              0,
/* 07-03 DCISTA       */  RLD|WRUN|DOT1,                  0,            600,              7,
/* 07-04 DCISTP       */  RLD|WRUN|DOT1,                  0,            600,              7,
/* 07-05 DCIFSTA      */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 07-06 DCI_KI       */  RLD|WRUN|DOT0,                  1,            500,             50,
/* 07-07 GEAR_ACCT    */  RLD|WRUN|DOT2,                  0,          60000,              0,
/* 07-08 GEAR_ACCF    */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 07-09 GEAR_DECT    */  RLD|WRUN|DOT2,                  0,          60000,              0,
/* 07-10 GEAR_DECF    */  CHG|RLD|WRUN|DOT2,              0,           MAXF,              0,
/* 07-11 FAN          */  RLD|WRUN|DOT0,                  0,              4,              2,
/* 07-12 TQREF        */  SIGN|RLD|READ|WRUN|DOT1,    -1500,           1500,              0,
/* 07-13 TQRSOOC      */  RLD|WRUN|DOT0,                  0,              2,              2,
/* 07-14 TQRMAX       */  RLD|WRUN|DOT0,                  0,            300,            100,
/* 07-15 TQRLPG       */  RLD|WRUN|DOT3,                  0,           1000,              0,
/* 07-16 SPLIMIT_SL   */  RLD|DOT0,                       0,              1,              0,
/* 07-17 TQPSPDLIM    */  RLD|WRUN|DOT0,                  0,            120,             10,
/* 07-18 TQNSPDLIM    */  RLD|WRUN|DOT0,                  0,            120,             10,
/* 07-19 TQROFSE      */  RLD|WRUN|DOT0,                  0,              3,              0,    //[UD protocal, Bernie, 2012/12/05]
/* 07-20 TQOFSEV      */  RLD|WRUN|DOT1,                  0,           1000,              0,
/* 07-21 TQOFSEVH     */  SIGN|RLD|WRUN|DOT1,         -1000,           1000,            300,
/* 07-22 TQOFSEVM     */  SIGN|RLD|WRUN|DOT1,         -1000,           1000,            200,
/* 07-23 TQOFSEVL     */  SIGN|RLD|WRUN|DOT1,         -1000,           1000,            100,
/* 07-24 FWDM_TQLIM   */  RLD|WRUN|DOT0,                  0,            300,            200,
/* 07-25 FWDR_TQLIM   */  RLD|WRUN|DOT0,                  0,            300,            200,
/* 07-26 REVM_TQLIM   */  RLD|WRUN|DOT0,                  0,            300,            200,
/* 07-27 REVR_TQLIM   */  RLD|WRUN|DOT0,                  0,            300,            200,
/* 07-28 FORSTPWAY    */  RLD|WRUN|DOT0,                  0,              5,              0,
/* 07-29 TQ_LPG       */  RLD|WRUN|DOT3,                  0,           5000,              0,
/* 07-30 STOP_DCICL   */  RLD|WRUN|DOT0,                  0,            100,              0,    //[DCI Level when stop, Bernie, 05/21/2012]
/* 07-31 BTT100       */  RLD|WRUN|DOT1,                  0,           3000,              0,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
/* 07-32 BTTx_Test    */  RLD|DOT0,                       0,              1,              0,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
/* 07-33 BTTx_TestDist*/  RLD|DOT0,                       0,          65535,              0,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
/* 07-34 BTTx_TestTime*/  RLD|DOT1,                       0,             50,             50,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
/* 07-35 BTTx_Torq    */  RLD|READ|DOT2,                  0,            300,              0,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
/* 07-36 BTTx_MinTorq */  RLD|WRUN|DOT2,                  0,            200,              0,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
/* 07-37 BTTx_MaxTorq */  RLD|WRUN|DOT2,                  0,            200,              0,    //[JES Torq Detect Function, Special.Kung, 2022/09/01]

/*--------      GROUP 08        --------*/
/* 08-00 PM_AUTO_T    */S2EEP|RLD|DOT0,                   0,              3,              0,
/* 08-01 PM_MI_RAT    */  RLD|DOT2,                       0,          65535,              0,
/* 08-02 PM_P_RATED   */  RLD|DOT2,                       0,          65535,              0,
/* 08-03 PM_RPM_RATED */  RLD|DOT0,                       0,          65535,           1710,
/* 08-04 PM_POLES     */  RLD|JMP|DOT0,                   2,             96,              4,
/* 08-05 PM_Rs        */  RLD|DOT3,                       0,          65535,              0,
/* 08-06 PM_Ld        */  RLD|DOT1,                       0,          65535,              0,
/* 08-07 PM_Lq        */  RLD|DOT1,                       0,          65535,              0,
/* 08-08 PM_Bemf      */  RLD|V440|DOT1,                  0,          65535,              0,
/* 08-09 Z_OFFSET     */  RLD|DOT1,                       0,           3600,           3600,
/* 08-10 ST_TUNE      */S2EEP|RLD|DOT0,                   0,              1,              0,

/*--------      GROUP 09     -----------*/
/* 09-00 ADDRS3       */  RLD|WRUN|DOT0,                  1,            254,              1,
/* 09-01 BPS3         */  RLD|WRUN|DOT1,                 48,           1152,            192,
/* 09-02 C_FAULT3     */  RLD|WRUN|DOT0,                  0,              3,              3,
/* 09-03 CTODT3       */  RLD|WRUN|DOT1,                  0,           1000,              0,
/* 09-04 PROTOCOL3    */  RLD|WRUN|DOT0,                  0,             17,             13,
/* 09-05 REM_DT3      */  RLD|WRUN|DOT1,                  0,           2000,             20,
#if Artemis_ENABLE
/* 09-06 CAN_BURD     */  RLD|DOT0,                       0,              3,              2,	// [CAN Protocol for High Cap , Sampo,  2011/09/05] //#16550 Artemis default value, James, 20210520
#else
/* 09-06 CAN_BURD     */  RLD|DOT0,                       0,              3,              1,	// [CAN Protocol for High Cap , Sampo,  2011/09/05] 
#endif
/* 09-07 PDO_TX_Time  */  RLD|WRUN|DOT0,                  0,             10,              1,  	// [CAN Protocol for High Cap, Bernie, 09/22/2011] 
/* 09-08 CAN_ChkTime  */  RLD|WRUN|DOT0,                  0,            200,            100,  	// [CAN Protocol for High Cap, Bernie, 09/22/2011]	// Sean, 20181207
/* 09-09 EV_ID        */  DPH|RLD|DOT0|WRUN,              0,          65535,              0,    // 3XX 09-09 Elevator Control Identification Code
/* 09-10 CAN_FUN      */  RLD|DOT0|DPH,                   0,          65535,              0,    // 3XX 09-10 Factory Function  
/* 09-11 DLC_MODE1    */  RLD|DOT0|DPH,                   0,          65535,              0,    // 3XX 09-11 RD Function
/* 09-12 DLC_MODE2    */  READ|RLD|DOT0|DPH,              0,          65535,              0,    // 3XX 09-12 DLC Mode
/* 09-13 DLC_MODE3    */  READ|RLD|DOT0|DPH,              0,          65535,              0,
/* 09-14 CANPDOTXTIME */  RLD|DOT0,		            	  0,		  65535,		      0,    //CANPDOTXTIME--aevin 6/12/2017

/*--------      GROUP 10     -----------*/
/* 10-00 PG_TYPE      */  RLD|DOT0,                       0,              6,              0,
/* 10-01 EPPR         */  RLD|DOT0,                       1,          25000,           2048,    //[Change default valut to 2048, Bernie, 2016/04/25]
/* 10-02 PGINPUT      */  RLD|DOT0,                       0,              5,              0,
/* 10-03 ENCLOSS      */  RLD|WRUN|DOT0,                  0,              2,              2,
/* 10-04 ENCDET       */  RLD|WRUN|DOT1,                  0,            100,             10,
/* 10-05 PGOSPDL      */  RLD|WRUN|DOT0,                  0,            120,            115,
/* 10-06 OSPDET       */  RLD|WRUN|DOT1,                  0,             20,              1,
/* 10-07 PGDEVDL      */  RLD|WRUN|DOT0,                  0,             50,             50,
/* 10-08 DEVDET       */  RLD|WRUN|DOT1,                  0,            100,              5,
/* 10-09 OSPDWAY      */  RLD|WRUN|DOT0,                  0,              2,              2,
/* 10-10 UVW_TYPE     */  RLD|DOT0,                       0,              1,              0,
/* 10-11 ZASRKP       */  RLD|WRUN|DOT1,                  0,          10000,           1000,
/* 10-12 ZASRKI       */  RLD|WRUN|DOT3,                  0,          10000,            100,
/* 10-13 SPP1         */  RLD|WRUN|DOT1,                  0,          10000,           1000,
/* 10-14 SPI1         */  RLD|WRUN|DOT3,                  0,          10000,            100,
/* 10-15 SPP2         */  RLD|WRUN|DOT1,                  0,          10000,           1000,
/* 10-16 SPI2         */  RLD|WRUN|DOT3,                  0,          10000,            100,
/* 10-17 ASR_F1       */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            700,
/* 10-18 PriLPG       */  RLD|WRUN|DOT3,                  1,            350,              8,
/* 10-19 PPI_P        */  RLD|WRUN|DOT2,                  0,          65500,           8000,
/* 10-20 SPI1BAND     */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            500,
/* 10-21 SPI2BAND     */  CHG|RLD|WRUN|DOT2,              0,           MAXF,            500,
/* 10-22 POS_CTIME    */  RLD|WRUN|DOT3,                  0,          65535,            250,
/* 10-23 ZSPLowpass   */  RLD|WRUN|DOT3,                  0,          65535,              4,
/* 10-24 SOPCTRL      */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 10-25 ZASRKP_L     */  RLD|WRUN|DOT1,                  0,          10000,           1000,
/* 10-26 ZASRKI_L     */  RLD|WRUN|DOT3,                  0,          10000,            100,
/* 10-27 ZASRKP_P     */  RLD|WRUN|DOT1,                  0,          10000,           1000,
/* 10-28 ZASRKI_P     */  RLD|WRUN|DOT3,                  0,          10000,            100,
/* 10-29 FREQ_DIV     */  RLD|WRUN|DOT0,                  0,             31,              0,    //[Modify PG Type Define, Bernie, 12/05/2011]
/* 10-30 PG_DIV_MODE  */  RLD|WRUN|DOT0|DPH,              0,              8,              0,    //[Modify PG Type Define, Bernie, 12/05/2011]
/* 10-31 PG_C_TYPE    */  RLD|WRUN|DOT0|DPH,	          0,	      65535,              0,    //0x0400 3XX 10-31   Encoder C+/C- exchange	  //[change parameter to normal group, Bernie, 2014/02/14]
/* 10-32 OVER_ACC_LEVEL*/ RLD|WRUN|DOT1,                  0,            200,              0,    //[Over Acceleration protection function, Bernie, 2017/02/13]
/* 10-33 OVER_ACC_TIME*/  RLD|DOT2,                       1,            500,              5,    //[Over Acceleration protection function, Bernie, 2017/02/13]
/* 10-34 OVER_ACC_SET */  RLD|DOT0,                       0,              1,              0,
/* 10-35 ACCLPF       */  RLD|DOT0,                       0,          65535,              0,    //[Rationa 362631, Special.Kung]
/* 10-36 ACCSampleRate*/  RLD|DOT1,                       0,          65535,              0,    //[Rationa 362631, Special.Kung]

/*--------      GROUP 11        --------*/
/* 11-00 SysControl   */  RLD|DOT0|DPH,                   0,          65535,              0,    //[change default value for support PGHSD-1, Bernie, 2014/07/31]
/* 11-01 Lift_SPD     */  CHG|RLD|WRUN|DOT2,             10,            700,            100,    //Redmine #16202 For GFC-High-Speed elevator, the Max. speed form 4m/s up to 7m/s
/* 11-02 SHEAVE_D     */  RLD|WRUN|DOT0,                100,           2000,            400,
/* 11-03 GearRatio    */  RLD|WRUN|DOT2,                100,          10000,            100,
/* 11-04 SUSPENSION   */  RLD|WRUN|DOT0,                  0,              3,              1,
/* 11-05 JM_PERCENT   */  RLD|WRUN|DOT0,                  1,            300,             40,
/* 11-06 ZSPDLPBW     */  RLD|WRUN|DOT0,                  1,             40,             10,
/* 11-07 SPDLPBW1     */  RLD|WRUN|DOT0,                  1,             40,             10,
/* 11-08 SPDLPBW2     */  RLD|WRUN|DOT0,                  1,             40,             10,
/* 11-09 PDFFKr       */  RLD|WRUN|DOT0,                  0,            200,             30,
/* 11-10 SPDFFDGain   */  RLD|WRUN|DOT0,                  0,            500,              0,
/* 11-11 NH_Deep      */  RLD|WRUN|DOT0,                  0,             20,              0,
/* 11-12 NH_Freq      */  RLD|WRUN|DOT2,                  0,          20000,              0,
/* 11-13 LPF_DISP     */  RLD|WRUN|DOT3,                  1,          65535,            500,
/* 11-14 Lift_ACCi    */  RLD|WRUN|DOT0,                 50,            200,            150,
/* 11-15 Max_MperS    */  CHG|RLD|WRUN|DOT2,             20,            200,             75,
/* 11-16 DATA_SEL     */  S2EEP|WRUN|DOT0|DPH,            0,          65535,              0,
/* 11-17 SHOW_DATA    */  READ|DOT0,                      0,          65535,              0,
/* 11-18 PROTBIT      */  RLD|S2EEP|WRUN|DOT0|DPH,        0,          65535,              0,
/* 11-19 ZSPDLPBW_L   */  RLD|WRUN|DOT0,                  1,             40,             10,
/* 11-20 PWM_MODE     */      WRUN|DOT0,                  0,          65535,              0,
/* 11-21 LPF_LC01DISP */  RLD|WRUN|DOT3,                  1,          65535,            500,
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
/* 11-21 Lift_SPD_RPM */  READ|DOT0, 		          0, 	      65535,              0,
#endif
/* 11-22 Client_Mode  */  RLD|DOT0,                       0,          65535,              0,

/*--------    GROUP 12    --------*/
/* 12-00 UMAP_ADD0    */  RLD|WRUN|DOT0,                  0,           9999,            616,
/* 12-01 UMAP_ADD1    */  RLD|WRUN|DOT0,                  0,           9999,            632,
/* 12-02 UMAP_ADD2    */  RLD|WRUN|DOT0,                  0,           9999,            633,
/* 12-03 UMAP_ADD3    */  RLD|WRUN|DOT0,                  0,           9999,            653,
/* 12-04 UMAP_ADD4    */  RLD|WRUN|DOT0,                  0,           9999,            654,
/* 12-05 UMAP_ADD5    */  RLD|WRUN|DOT0,                  0,           9999,            655,
/* 12-06 UMAP_ADD6    */  RLD|WRUN|DOT0,                  0,           9999,            656,
/* 12-07 UMAP_ADD7    */  RLD|WRUN|DOT0,                  0,           9999,            657,
/* 12-08 UMAP_ADD8    */  RLD|WRUN|DOT0,                  0,           9999,            658,
/* 12-09 UMAP_ADD9    */  RLD|WRUN|DOT0,                  0,           9999,            659,
/* 12-10 UMAP_ADD10   */  RLD|WRUN|DOT0,                  0,           9999,            660,
/* 12-11 UMAP_ADD11   */  RLD|WRUN|DOT0,                  0,           9999,            661,
/* 12-12 UMAP_ADD12   */  RLD|WRUN|DOT0,                  0,           9999,            662,
/* 12-13 UMAP_ADD13   */  RLD|WRUN|DOT0,                  0,           9999,            663,
/* 12-14 UMAP_ADD14   */  RLD|WRUN|DOT0,                  0,           9999,            664,
/* 12-15 UMAP_ADD15   */  RLD|WRUN|DOT0,                  0,           9999,            617,
/* 12-16 UMAP_ADD16   */  RLD|WRUN|DOT0,                  0,           9999,            634,
/* 12-17 UMAP_ADD17   */  RLD|WRUN|DOT0,                  0,           9999,            635,
/* 12-18 UMAP_ADD18   */  RLD|WRUN|DOT0,                  0,           9999,            618,
/* 12-19 UMAP_ADD19   */  RLD|WRUN|DOT0,                  0,           9999,            636,
/* 12-20 UMAP_ADD20   */  RLD|WRUN|DOT0,                  0,           9999,            637,
/* 12-21 UMAP_ADD21   */  RLD|WRUN|DOT0,                  0,           9999,            619,
/* 12-22 UMAP_ADD22   */  RLD|WRUN|DOT0,                  0,           9999,            638,
/* 12-23 UMAP_ADD23   */  RLD|WRUN|DOT0,                  0,           9999,            639,
/* 12-24 UMAP_ADD24   */  RLD|WRUN|DOT0,                  0,           9999,            620,
/* 12-25 UMAP_ADD25   */  RLD|WRUN|DOT0,                  0,           9999,            640,
/* 12-26 UMAP_ADD26   */  RLD|WRUN|DOT0,                  0,           9999,            641,
/* 12-27 UMAP_ADD27   */  RLD|WRUN|DOT0,                  0,           9999,            621,
/* 12-28 UMAP_ADD28   */  RLD|WRUN|DOT0,                  0,           9999,            642,
/* 12-29 UMAP_ADD29   */  RLD|WRUN|DOT0,                  0,           9999,            643,
/* 12-30 UMAP_ADD30   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-31 UMAP_ADD31   */  RLD|WRUN|DOT0,                  0,           9999,           1561, //[default DateCode, Jason, 2018/11/15]
/* 12-32 UMAP_ADD32   */  RLD|WRUN|DOT0,                  0,           9999,           1578, //[BootLoader Version, Special.Kung, 2022/10/31]
/* 12-33 UMAP_ADD33   */  RLD|WRUN|DOT0,                  0,           9999,           1583, //[BootLoader DataCode, Special.Kung, 2022/10/31]
/* 12-34 UMAP_ADD34   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-35 UMAP_ADD35   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-36 UMAP_ADD36   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-37 UMAP_ADD37   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-38 UMAP_ADD38   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-39 UMAP_ADD39   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-40 UMAP_ADD40   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-41 UMAP_ADD41   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-42 UMAP_ADD42   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-43 UMAP_ADD43   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-44 UMAP_ADD44   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-45 UMAP_ADD45   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-46 UMAP_ADD46   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-47 UMAP_ADD47   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-48 UMAP_ADD48   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-49 UMAP_ADD49   */  RLD|WRUN|DOT0,                  0,           9999,              0,
/* 12-50 UMAP_ADD50   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-51 UMAP_ADD51   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-52 UMAP_ADD52   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-53 UMAP_ADD53   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-54 UMAP_ADD54   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-55 UMAP_ADD55   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-56 UMAP_ADD56   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-57 UMAP_ADD57   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-58 UMAP_ADD58   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-59 UMAP_ADD59   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-60 UMAP_ADD60   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-61 UMAP_ADD61   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-62 UMAP_ADD62   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-63 UMAP_ADD63   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-64 UMAP_ADD64   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-65 UMAP_ADD65   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-66 UMAP_ADD66   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-67 UMAP_ADD67   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-68 UMAP_ADD68   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-69 UMAP_ADD69   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-70 UMAP_ADD70   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-71 UMAP_ADD71   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-72 UMAP_ADD72   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-73 UMAP_ADD73   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-74 UMAP_ADD74   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-75 UMAP_ADD75   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-76 UMAP_ADD76   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-77 UMAP_ADD77   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-78 UMAP_ADD78   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-79 UMAP_ADD79   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-80 UMAP_ADD80   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-81 UMAP_ADD81   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-82 UMAP_ADD82   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-83 UMAP_ADD83   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-84 UMAP_ADD84   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-85 UMAP_ADD85   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-86 UMAP_ADD86   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-87 UMAP_ADD87   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-88 UMAP_ADD88   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-89 UMAP_ADD89   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-90 UMAP_ADD90   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-91 UMAP_ADD91   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-92 UMAP_ADD92   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-93 UMAP_ADD93   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-94 UMAP_ADD94   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-95 UMAP_ADD95   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-96 UMAP_ADD96   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-97 UMAP_ADD97   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-98 UMAP_ADD98   */  RLD|READ|DOT0,                  0,           9999,              0,
/* 12-99 UMAP_ADD99   */  RLD|READ|DOT0,                  0,           9999,              0,

/*--------    GROUP 13    --------*/                                   
/* 13-00 UMAP_DATA0   */  READ|DOT0,                      0,          65535,              0,
/* 13-01 UMAP_DATA1   */  READ|DOT0,                      0,          65535,              0,
/* 13-02 UMAP_DATA2   */  READ|DOT0,                      0,          65535,              0,
/* 13-03 UMAP_DATA3   */  READ|DOT0,                      0,          65535,              0,
/* 13-04 UMAP_DATA4   */  READ|DOT0,                      0,          65535,              0,
/* 13-05 UMAP_DATA5   */  READ|DOT0,                      0,          65535,              0,
/* 13-06 UMAP_DATA6   */  READ|DOT0,                      0,          65535,              0,
/* 13-07 UMAP_DATA7   */  READ|DOT0,                      0,          65535,              0,
/* 13-08 UMAP_DATA8   */  READ|DOT0,                      0,          65535,              0,
/* 13-09 UMAP_DATA9   */  READ|DOT0,                      0,          65535,              0,
/* 13-10 UMAP_DATA10  */  READ|DOT0,                      0,          65535,              0,
/* 13-11 UMAP_DATA11  */  READ|DOT0,                      0,          65535,              0,
/* 13-12 UMAP_DATA12  */  READ|DOT0,                      0,          65535,              0,
/* 13-13 UMAP_DATA13  */  READ|DOT0,                      0,          65535,              0,
/* 13-14 UMAP_DATA14  */  READ|DOT0,                      0,          65535,              0,
/* 13-15 UMAP_DATA15  */  READ|DOT0,                      0,          65535,              0,
/* 13-16 UMAP_DATA16  */  READ|DOT0,                      0,          65535,              0,
/* 13-17 UMAP_DATA17  */  READ|DOT0,                      0,          65535,              0,
/* 13-18 UMAP_DATA18  */  READ|DOT0,                      0,          65535,              0,
/* 13-19 UMAP_DATA19  */  READ|DOT0,                      0,          65535,              0,
/* 13-20 UMAP_DATA20  */  READ|DOT0,                      0,          65535,              0,
/* 13-21 UMAP_DATA21  */  READ|DOT0,                      0,          65535,              0,
/* 13-22 UMAP_DATA22  */  READ|DOT0,                      0,          65535,              0,
/* 13-23 UMAP_DATA23  */  READ|DOT0,                      0,          65535,              0,
/* 13-24 UMAP_DATA24  */  READ|DOT0,                      0,          65535,              0,
/* 13-25 UMAP_DATA25  */  READ|DOT0,                      0,          65535,              0,
/* 13-26 UMAP_DATA26  */  READ|DOT0,                      0,          65535,              0,
/* 13-27 UMAP_DATA27  */  READ|DOT0,                      0,          65535,              0,                                                        
/* 13-28 UMAP_DATA28  */  READ|DOT0,                      0,          65535,              0,                                                        
/* 13-29 UMAP_DATA29  */  READ|DOT0,                      0,          65535,              0,                                                        
/* 13-30 UMAP_DATA30  */  READ|DOT0,                      0,          65535,              0,                                                        
/* 13-31 UMAP_DATA31  */  READ|DOT0,                      0,          65535,              0,  
/* 13-32 UMAP_DATA32  */  READ|DOT0,                      0,          65535,              0,
/* 13-33 UMAP_DATA33  */  READ|DOT0,                      0,          65535,              0,
/* 13-34 UMAP_DATA34  */  READ|DOT0,                      0,          65535,              0,
/* 13-35 UMAP_DATA35  */  READ|DOT0,                      0,          65535,              0,
/* 13-36 UMAP_DATA36  */  READ|DOT0,                      0,          65535,              0,
/* 13-37 UMAP_DATA37  */  READ|DOT0,                      0,          65535,              0,
/* 13-38 UMAP_DATA38  */  READ|DOT0,                      0,          65535,              0,
/* 13-39 UMAP_DATA39  */  READ|DOT0,                      0,          65535,              0,
/* 13-40 UMAP_DATA40  */  READ|DOT0,                      0,          65535,              0,
/* 13-41 UMAP_DATA41  */  READ|DOT0,                      0,          65535,              0,
/* 13-42 UMAP_DATA42  */  READ|DOT0,                      0,          65535,              0,
/* 13-43 UMAP_DATA43  */  READ|DOT0,                      0,          65535,              0,
/* 13-44 UMAP_DATA44  */  READ|DOT0,                      0,          65535,              0,
/* 13-45 UMAP_DATA45  */  READ|DOT0,                      0,          65535,              0,
/* 13-46 UMAP_DATA46  */  READ|DOT0,                      0,          65535,              0,
/* 13-47 UMAP_DATA47  */  READ|DOT0,                      0,          65535,              0,
/* 13-48 UMAP_DATA48  */  READ|DOT0,                      0,          65535,              0,
/* 13-49 UMAP_DATA49  */  READ|DOT0,                      0,          65535,              0,
/* 13-50 UMAP_DATA50  */  READ|DOT0,                      0,          65535,              0,
/* 13-51 UMAP_DATA51  */  READ|DOT0,                      0,          65535,              0,
/* 13-52 UMAP_DATA52  */  READ|DOT0,                      0,          65535,              0,
/* 13-53 UMAP_DATA53  */  READ|DOT0,                      0,          65535,              0,
/* 13-54 UMAP_DATA54  */  READ|DOT0,                      0,          65535,              0,
/* 13-55 UMAP_DATA55  */  READ|DOT0,                      0,          65535,              0,
/* 13-56 UMAP_DATA56  */  READ|DOT0,                      0,          65535,              0,
/* 13-57 UMAP_DATA57  */  READ|DOT0,                      0,          65535,              0,
/* 13-58 UMAP_DATA58  */  READ|DOT0,                      0,          65535,              0,
/* 13-59 UMAP_DATA59  */  READ|DOT0,                      0,          65535,              0,
/* 13-60 UMAP_DATA60  */  READ|DOT0,                      0,          65535,              0,
/* 13-61 UMAP_DATA61  */  READ|DOT0,                      0,          65535,              0,
/* 13-62 UMAP_DATA62  */  READ|DOT0,                      0,          65535,              0,
/* 13-63 UMAP_DATA63  */  READ|DOT0,                      0,          65535,              0,
/* 13-64 UMAP_DATA64  */  READ|DOT0,                      0,          65535,              0,
/* 13-65 UMAP_DATA65  */  READ|DOT0,                      0,          65535,              0,
/* 13-66 UMAP_DATA66  */  READ|DOT0,                      0,          65535,              0,
/* 13-67 UMAP_DATA67  */  READ|DOT0,                      0,          65535,              0,
/* 13-68 UMAP_DATA68  */  READ|DOT0,                      0,          65535,              0,
/* 13-69 UMAP_DATA69  */  READ|DOT0,                      0,          65535,              0,
/* 13-70 UMAP_DATA70  */  READ|DOT0,                      0,          65535,              0,
/* 13-71 UMAP_DATA71  */  READ|DOT0,                      0,          65535,              0,
/* 13-72 UMAP_DATA72  */  READ|DOT0,                      0,          65535,              0,
/* 13-73 UMAP_DATA73  */  READ|DOT0,                      0,          65535,              0,
/* 13-74 UMAP_DATA74  */  READ|DOT0,                      0,          65535,              0,
/* 13-75 UMAP_DATA75  */  READ|DOT0,                      0,          65535,              0,
/* 13-76 UMAP_DATA76  */  READ|DOT0,                      0,          65535,              0,
/* 13-77 UMAP_DATA77  */  READ|DOT0,                      0,          65535,              0,
/* 13-78 UMAP_DATA78  */  READ|DOT0,                      0,          65535,              0,
/* 13-79 UMAP_DATA79  */  READ|DOT0,                      0,          65535,              0,
/* 13-80 UMAP_DATA80  */  READ|DOT0,                      0,          65535,              0,
/* 13-81 UMAP_DATA81  */  READ|DOT0,                      0,          65535,              0,
/* 13-82 UMAP_DATA82  */  READ|DOT0,                      0,          65535,              0,
/* 13-83 UMAP_DATA83  */  READ|DOT0,                      0,          65535,              0,
/* 13-84 UMAP_DATA84  */  READ|DOT0,                      0,          65535,              0,
/* 13-85 UMAP_DATA85  */  READ|DOT0,                      0,          65535,              0,
/* 13-86 UMAP_DATA86  */  READ|DOT0,                      0,          65535,              0,
/* 13-87 UMAP_DATA87  */  READ|DOT0,                      0,          65535,              0,
/* 13-88 UMAP_DATA88  */  READ|DOT0,                      0,          65535,              0,
/* 13-89 UMAP_DATA89  */  READ|DOT0,                      0,          65535,              0,
/* 13-90 UMAP_DATA90  */  READ|DOT0,                      0,          65535,              0,
/* 13-91 UMAP_DATA91  */  READ|DOT0,                      0,          65535,              0,
/* 13-92 UMAP_DATA92  */  READ|DOT0,                      0,          65535,              0,
/* 13-93 UMAP_DATA93  */  READ|DOT0,                      0,          65535,              0,
/* 13-94 UMAP_DATA94  */  READ|DOT0,                      0,          65535,              0,
/* 13-95 UMAP_DATA95  */  READ|DOT0,                      0,          65535,              0,
/* 13-96 UMAP_DATA96  */  READ|DOT0,                      0,          65535,              0,
/* 13-97 UMAP_DATA97  */  READ|DOT0,                      0,          65535,              0,
/* 13-98 UMAP_DATA98  */  READ|DOT0,                      0,          65535,              0,
/* 13-99 UMAP_DATA99  */  READ|DOT0,                      0,          65535,              0,

/*----  GROUP 14      ------------------*/
/* 14-00 IdsPSLevel   */  RLD|WRUN|DOT0,                 10,           1000,            100,
/* 14-01 VFSL         */  RLD|DOT0,                       0,              2,              0,
/* 14-02 CTSEL        */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 14-03 AAAD         */  RLD|WRUN|DOT0,                  0,              4,              0,
/* 14-04 U_ACCDEC     */  RLD|DOT0,                       0,              1,              0,
/* 14-05 PWRSAVE      */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 14-06 STOPM        */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 14-07 SETDIR       */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 14-08 FSKIP1H      */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-09 FSKIP1L      */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-10 FSKIP2H      */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-11 FSKIP2L      */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-12 FSKIP3H      */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-13 FSKIP3L      */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-14 MFBASE2      */  RLD|JMP|DOT2,                   0,           MAXF,           6000,
/* 14-15 VMAX2        */  RLD|JMP|V440|DOT1,              0,           5100,           4400,
/* 14-16 FMID2_1      */  RLD|DOT2,                       0,           MAXF,             50,
/* 14-17 VMID2_1      */  RLD|WRUN|V440|DOT1,             0,           4800,            100,
/* 14-18 FMID2_2      */  RLD|DOT2,                       0,           MAXF,             50,
/* 14-19 VMID2_2      */  RLD|WRUN|V440|DOT1,             0,           4800,            100,
/* 14-20 FMIN2        */  RLD|DOT2,                       0,           MAXF,              0,
/* 14-21 VMIN2        */  RLD|WRUN|V440|DOT1,             0,           4800,              0,
/* 14-22 UPDNKEYM     */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 14-23 UPDNKEYS     */  RLD|WRUN|DOT2,                  1,            100,              1,
/* 14-24 CNTCPL       */  RLD|WRUN|DOT0,                  0,          65500,              0,
/* 14-25 CNTPRS       */  RLD|WRUN|DOT0,                  0,          65500,              0,
/* 14-26 LIMIT_SCALE  */  RLD|WRUN|DOT1,                  1,           2000,           1000,    //[weak magnet, Sampo, 03/31/2011]
/* 14-27 MI9          */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 14-28 MI10         */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 14-29 MI11         */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 14-30 MI12         */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 14-31 MI13         */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 14-32 MI14         */  RLD|DOT0,                       0,         MFIMAX,              0,
/* 14-33 EXTON_RUN    */  RLD|WRUN|DOT0,                  0,              1,              1,
/* 14-34 ACISEL       */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 14-35 AISUM        */  RLD|WRUN|DOT0,                  0,              1,              0,
/* 14-36 PMI1         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-37 PMI2         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-38 PMI3         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-39 PMI4         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-40 PMI5         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-41 PMI6         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-42 PMI7         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-43 PMI8         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-44 PMI9         */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-45 PMI10        */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-46 PMI11        */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-47 PMI12        */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-48 PMI13        */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-49 PMI14        */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-50 PMI15        */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-51 MOTORSEL     */  RLD|DOT0,                       1,              2,              1,
/* 14-52 YDSWRPM      */  RLD|WRUN|DOT2,                  0,           MAXF,           6000,
/* 14-53 YDSWEN       */  RLD|DOT0,                       0,              1,              0,
/* 14-54 MI_RAT2      */  RLD|DOT2,                       0,          65535,              0,
/* 14-55 P_RATED2     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-56 RPM_RATED2   */  RLD|WRUN|DOT0,                  0,          65535,           1710,
/* 14-57 POLES2       */  RLD|JMP|DOT0,                   2,             20,              4,
/* 14-58 MI_NL2       */  RLD|DOT2,                       0,          65535,              0,
/* 14-59 Rs2          */  RLD|DOT3,                       0,          65535,              0,
/* 14-60 Rr2          */  RLD|DOT3,                       0,          65535,              0,
/* 14-61 Lm2          */  RLD|DOT1,                       0,          65535,              0,
/* 14-62 Lx2          */  RLD|DOT1,                       0,          65535,              0,
/* 14-63 YDDELAYT     */  RLD|WRUN|DOT3,                  0,          60000,            200,
/* 14-64 STALL4V      */  RLD|WRUN|V440|DOT1,             0,           9000,              0,
/* 14-65 EOL2_SL      */  RLD|WRUN|DOT0,                  0,              2,              2,
/* 14-66 EOL2_T       */  RLD|WRUN|DOT1,                300,           6000,            600,
/* 14-67 PWRLOS       */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 14-68 PWRL_T       */  RLD|WRUN|DOT1,                  1,             50,             20,
/* 14-69 BB_T         */  RLD|WRUN|DOT1,                  1,             50,              5,
/* 14-70 SER_CL       */  RLD|WRUN|DOT0,                 20,            200,            150,
/* 14-71 REST_M       */  RLD|WRUN|DOT0,                  0,              2,              0,
/* 14-72 REST_CNT     */  RLD|WRUN|DOT0,                  0,             10,              0,
/* 14-73 SPD_SER      */  RLD|WRUN|DOT0,                  0,              3,              0,
/* 14-74 KEB_SL       */  RLD|WRUN|DOT0,                  0,              6,              0,
/* 14-75 KEB_RT       */  RLD|WRUN|DOT1,                  0,            250,              0,
/* 14-76 PIDSL        */  RLD|WRUN|DOT0,                  0,              6,              0,
/* 14-77 PID_P        */  RLD|WRUN|DOT1,                  0,           5000,            800,
/* 14-78 PID_I        */  RLD|WRUN|DOT2,                  0,          10000,            100,
/* 14-79 PID_D        */  RLD|WRUN|DOT2,                  0,            100,              0,
/* 14-80 PID_ILIMIT   */  RLD|WRUN|DOT1,                  0,           1000,           1000,
/* 14-81 PIDMAX       */  RLD|WRUN|DOT1,                  0,           1100,           1000,
/* 14-82 PIDOFSET     */  SIGN|RLD|WRUN|DOT1,         -1000,           1000,              0,
/* 14-83 PIDDLY       */  RLD|WRUN|DOT1,                  0,             25,              0,
/* 14-84 FB_DT        */  RLD|WRUN|DOT1,                  0,          36000,              0,
/* 14-85 FB_LOSS      */  RLD|WRUN|DOT0,                  0,              3,              0,
/* 14-86 SLEEPF       */  RLD|WRUN|DOT2,                  0,           6000,              0,
/* 14-87 WAKEF        */  RLD|WRUN|DOT2,                  0,           6000,              0,
/* 14-88 SLEEPT       */  RLD|WRUN|DOT2,                  0,           6000,              0,
/* 14-89 PID_DEV      */  RLD|WRUN|DOT1,                 10,            500,            100,
/* 14-90 PIDDEVT      */  RLD|WRUN|DOT1,                  1,           3000,             50,
/* 14-91 PIDFBLPG     */  RLD|WRUN|DOT1,                  1,           3000,             50,
/* 14-92 FCMAIN       */  RLD|WRUN|DOT2,                  0,           MAXF,           6000,
/* 14-93 BKTRANS1     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-94 BKTRANS2     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-95 BKTRANS3     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-96 BKTRANS4     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-97 BKTRANS5     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-98 BKTRANS6     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-99 BKTRANS7     */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-100 BKTRANS8    */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-101 BKTRANS9    */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-102 BKTRANS10   */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-103 WEAKLPF     */  RLD|WRUN|DOT0,                  0,          65535,          16384,  //[weak magnet, Sampo, 03/31/2011]
/* 14-104 WEAKTHETA   */  RLD|WRUN|DOT0,                  1,            100,             65,  //[weak magnet, Sampo, 03/31/2011]
/* 14-105 OVER_SCALE  */  RLD|WRUN|DOT1,                600,           2000,            750,  //[weak magnet, Sampo, 03/31/2011]
/* 14-106 PGHOME      */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-107 PGATTAIN    */  RLD|WRUN|DOT0,                  0,          20000,             10,
/* 14-108 APRFFGA     */  RLD|WRUN|DOT0,                  0,            100,             30,
/* 14-109 APRDECT     */  RLD|WRUN|DOT1,                  1,          60000,            300,
/* 14-110 VCOMFT      */  RLD|WRUN|DOT2,                  0,           MAXF,           5000,
/* 14-111 PACCELT     */  RLD|WRUN|DOT2,                  0,          65535,            100,
/* 14-112 MPGGA       */  RLD|WRUN|DOT0,                  1,           5000,            100,
/* 14-113 MPGGB       */  RLD|WRUN|DOT0,                  1,           5000,            100,
/* 14-114 JmPu        */  RLD|READ|WRUN|DOT0,             1,          65535,            400,
/* 14-115 M1_IdsRefLim*/  RLD|WRUN|DOT0,                  0,            200,             90,
/* 14-116 M2_IdsRefLim*/  RLD|WRUN|DOT0,                  0,            200,             90,
/* 14-117 PHL_T       */  RLD|WRUN|DOT2,                  1,          60000,             20,
/* 14-118 OH_IN       */  RLD|WRUN|DOT1,                200,           1100,           1100,
/* 14-119 SpdFFD      */  RLD|WRUN|DOT0,                 10,            150,             65,
/* 14-120 SLIPGC_G    */  RLD|WRUN|DOT2,                  0,            100,            100,
/* 14-121 PG2_LPG     */  RLD|WRUN|DOT3,                  0,          65535,            100,
/* 14-122 TENSION     */  RLD|DOT2,                       0,          65535,              0,
/* 14-123 DIAMETER    */  RLD|DOT2,                       0,          65535,              0,
/* 14-124 DEPTH       */  RLD|DOT2,                       0,          65535,              0,
/* 14-125 SRYREC      */      READ|DOT0,                  0,          65535,          65535,
/* 14-126 TB2Time     */  RLD|DOT0,                       0,          65535,            300,
/* 14-127 TGAIN       */  RLD|DOT0,                       0,          65535,              0,
/* 14-128 PHLHOUR     */      READ|DOT0,                  0,          65535,              0,
/* 14-129 APRCURVET   */  RLD|WRUN|DOT2,                  0,          65535,            300,
/* 14-130 Jm_SELECT   */  RLD|WRUN|DOT0,                  0,          65535,              0,
/* 14-131 PHL_L       */  RLD|WRUN|V440|DOT1,             0,           3200,            600,
/* 14-132 MI_STATE    */  RLD|WRUN|DOT0|DPH,              0,          65535,              0,
/* 14-133 STI         */  RLD|WRUN|DOT2,                  0,          65535,              0,
/* 14-134 PGSCALE     */  RLD|WRUN|DOT0,                  1,            255,              1,
/* 14-135 I_RATE      */S2EEP|RLD|READ|DOT2,              0,          65535,              0,
/* 14-136 CAN_HC      */   RLD|DOT0,                      0,              1,              0,    // [CAN Protocol for High Cap , Sampo,  2011/09/05]
/* 14-137 CAN_BURD    */   RLD|DOT0,                      0,              3,              1,    // [CAN Protocol for High Cap , Sampo,  2011/09/05]
/* 14-138 CAN_ChkTime */   RLD|WRUN|DOT0,                 0,            200,            100,    // [CAN Protocol for High Cap, Bernie, 09/22/2011] 	// Sean, 20181207
/* 14-139 PDO_TX_Time */   RLD|WRUN|DOT0,                 1,            200,             20,    // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
/* 14-140 ADDR2       */  RLD|WRUN|DOT0,                  1,            254,              1,    //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]
/* 14-141 BPS2        */  RLD|WRUN|DOT1,                 48,           1152,            192,
/* 14-142 C_FAULT2    */  RLD|WRUN|DOT0,                  0,              3,              3,
/* 14-143 CTODT2      */  RLD|WRUN|DOT1,                  0,           1000,              0,
/* 14-144 PROTOCOL2   */  RLD|WRUN|DOT0,                  0,             17,             13,
/* 14-145 REM_DT2     */  RLD|WRUN|DOT1,                  0,           2000,             20,

/* 14-146 OPH2_10HzCNT*/ RLD|WRUN|DOT0,                   0,          65535,              2,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-147 OPH2_5HzCNT */ RLD|WRUN|DOT0,                   0,          65535,              4,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-148 OPH2_1HzCNT */ RLD|WRUN|DOT0,                   0,          65535,              5,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-149 OPH2_0p5HzCNT*/ RLD|WRUN|DOT0,                  0,          65535,              7,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-150 OPH2_0p2HzCNT*/ RLD|WRUN|DOT0,                  0,          65535,              8,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-151 OPH2_IGAIN_1*/ RLD|WRUN|DOT0,                   0,          65535,            100,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-152 OPH2_IGAIN_2*/ RLD|WRUN|DOT0,                   0,          65535,            100,     //[Output Phase Loss 2, Sampo, 2015/05/21]
/* 14-152 OPH2_IGAIN_3*/ RLD|WRUN|DOT0,	                  0,          65535,             30,     //[Output Phase Loss 2, Sampo, 2015/05/21]

};

// DLC position offset, Henry
//for page 2
const PARAM_ATTR attr_DLC1[DLC_TABLE] = { // JINGDO
/* 04-50 FL_POSIT_1H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-30   1Floor Position H 
/* 04-51 FL_POSIT_1L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-31   1Floor Position L 
/* 04-52 FL_POSIT_2H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-32   2Floor Position H 
/* 04-53 FL_POSIT_2L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-33   2Floor Position L 
/* 04-54 FL_POSIT_3H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-34   3Floor Position H 
/* 04-55 FL_POSIT_3L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-35   3Floor Position L 
/* 04-56 FL_POSIT_4H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-36   4Floor Position H 
/* 04-57 FL_POSIT_4L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-37   4Floor Position L 
/* 04-58 FL_POSIT_5H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-38   5Floor Position H 
/* 04-59 FL_POSIT_5L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-39   5Floor Position L 
/* 04-60 FL_POSIT_6H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-40   6Floor Position H 
/* 04-61 FL_POSIT_6L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-41   6Floor Position L 
/* 04-62 FL_POSIT_7H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-42   7Floor Position H 
/* 04-63 FL_POSIT_7L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-43   7Floor Position L 
/* 04-64 FL_POSIT_8H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-44   8Floor Position H 
/* 04-65 FL_POSIT_8L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-45   8Floor Position L 
/* 04-66 FL_POSIT_9H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-46   9Floor Position H 
/* 04-67 FL_POSIT_9L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-47   9Floor Position L 
/* 04-68 FL_POSIT_10H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-48   10Floor Position H
/* 04-69 FL_POSIT_10L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-49   10Floor Position L
/* 04-70 FL_POSIT_11H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-50   11Floor Position H
/* 04-71 FL_POSIT_11L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-51   11Floor Position L
/* 04-72 FL_POSIT_12H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-52   12Floor Position H
/* 04-73 FL_POSIT_12L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-53   12Floor Position L
/* 04-74 FL_POSIT_13H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-54   13Floor Position H
/* 04-75 FL_POSIT_13L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-55   13Floor Position L
/* 04-76 FL_POSIT_14H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-56   14Floor Position H
/* 04-77 FL_POSIT_14L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-57   14Floor Position L
/* 04-78 FL_POSIT_15H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-58   15Floor Position H
/* 04-79 FL_POSIT_15L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-59   15Floor Position L
/* 04-80 FL_POSIT_16H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-60   16Floor Position H
/* 04-81 FL_POSIT_16L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-61   16Floor Position L
/* 04-82 FL_POSIT_17H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-62   17Floor Position H
/* 04-83 FL_POSIT_17L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-63   17Floor Position L
/* 04-84 FL_POSIT_18H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-64   18Floor Position H
/* 04-85 FL_POSIT_18L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-65   18Floor Position L
/* 04-86 FL_POSIT_19H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-66   19Floor Position H
/* 04-87 FL_POSIT_19L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-67   19Floor Position L
/* 04-88 FL_POSIT_20H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-68   20Floor Position H
/* 04-89 FL_POSIT_20L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-69   20Floor Position L
/* 04-90 FL_POSIT_21H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-70   21Floor Position H
/* 04-91 FL_POSIT_21L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-71   21Floor Position L
/* 04-92 FL_POSIT_22H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-72   22Floor Position H
/* 04-93 FL_POSIT_22L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-73   22Floor Position L
/* 04-94 FL_POSIT_23H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-74   23Floor Position H
/* 04-95 FL_POSIT_23L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-75   23Floor Position L
/* 04-96 FL_POSIT_24H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-76   24Floor Position H
/* 04-97 FL_POSIT_24L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-77   24Floor Position L
/* 04-98 FL_POSIT_25H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-78   25Floor Position H
/* 04-99 FL_POSIT_25L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-79   25Floor Position L                                                           
};

const PARAM_ATTR attr_DLC2[DLC_TABLE] = { // JINGDO
/* 04-50 FL_POSIT_1H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-30   1Floor Position H 
/* 04-51 FL_POSIT_1L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-31   1Floor Position L 
/* 04-52 FL_POSIT_2H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-32   2Floor Position H 
/* 04-53 FL_POSIT_2L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-33   2Floor Position L 
/* 04-54 FL_POSIT_3H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-34   3Floor Position H 
/* 04-55 FL_POSIT_3L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-35   3Floor Position L 
/* 04-56 FL_POSIT_4H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-36   4Floor Position H 
/* 04-57 FL_POSIT_4L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-37   4Floor Position L 
/* 04-58 FL_POSIT_5H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-38   5Floor Position H 
/* 04-59 FL_POSIT_5L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-39   5Floor Position L 
/* 04-60 FL_POSIT_6H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-40   6Floor Position H 
/* 04-61 FL_POSIT_6L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-41   6Floor Position L 
/* 04-62 FL_POSIT_7H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-42   7Floor Position H 
/* 04-63 FL_POSIT_7L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-43   7Floor Position L 
/* 04-64 FL_POSIT_8H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-44   8Floor Position H 
/* 04-65 FL_POSIT_8L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-45   8Floor Position L 
/* 04-66 FL_POSIT_9H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-46   9Floor Position H 
/* 04-67 FL_POSIT_9L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-47   9Floor Position L 
/* 04-68 FL_POSIT_10H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-48   10Floor Position H
/* 04-69 FL_POSIT_10L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-49   10Floor Position L
/* 04-70 FL_POSIT_11H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-50   11Floor Position H
/* 04-71 FL_POSIT_11L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-51   11Floor Position L
/* 04-72 FL_POSIT_12H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-52   12Floor Position H
/* 04-73 FL_POSIT_12L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-53   12Floor Position L
/* 04-74 FL_POSIT_13H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-54   13Floor Position H
/* 04-75 FL_POSIT_13L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-55   13Floor Position L
/* 04-76 FL_POSIT_14H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-56   14Floor Position H
/* 04-77 FL_POSIT_14L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-57   14Floor Position L
/* 04-78 FL_POSIT_15H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-58   15Floor Position H
/* 04-79 FL_POSIT_15L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-59   15Floor Position L
/* 04-80 FL_POSIT_16H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-60   16Floor Position H
/* 04-81 FL_POSIT_16L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-61   16Floor Position L
/* 04-82 FL_POSIT_17H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-62   17Floor Position H
/* 04-83 FL_POSIT_17L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-63   17Floor Position L
/* 04-84 FL_POSIT_18H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-64   18Floor Position H
/* 04-85 FL_POSIT_18L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-65   18Floor Position L
/* 04-86 FL_POSIT_19H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-66   19Floor Position H
/* 04-87 FL_POSIT_19L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-67   19Floor Position L
/* 04-88 FL_POSIT_20H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-68   20Floor Position H
/* 04-89 FL_POSIT_20L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-69   20Floor Position L
/* 04-90 FL_POSIT_21H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-70   21Floor Position H
/* 04-91 FL_POSIT_21L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-71   21Floor Position L
/* 04-92 FL_POSIT_22H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-72   22Floor Position H
/* 04-93 FL_POSIT_22L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-73   22Floor Position L
/* 04-94 FL_POSIT_23H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-74   23Floor Position H
/* 04-95 FL_POSIT_23L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-75   23Floor Position L
/* 04-96 FL_POSIT_24H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-76   24Floor Position H
/* 04-97 FL_POSIT_24L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-77   24Floor Position L
/* 04-98 FL_POSIT_25H */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-78   25Floor Position H
/* 04-99 FL_POSIT_25L */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-79   25Floor Position L                                                           
};

// DLC position offset, Henry
const PARAM_ATTR attr_DLC3[DLC_TABLE] = {   // JINGDO
/* 04-50 DD1_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-30   1Floor Position H 
/* 04-51 DD1_POSIT_L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-31   1Floor Position L 
/* 04-52 DD2_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-32   2Floor Position H 
/* 04-53 DD2_POSIT_L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-33   2Floor Position L 
/* 04-54 DD3_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-34   3Floor Position H 
/* 04-55 DD3_POSIT_L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-35   3Floor Position L 
/* 04-56 DD4_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-36   4Floor Position H 
/* 04-57 DD4_POSIT_L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-37   4Floor Position L 
/* 04-58 UD1_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-38   5Floor Position H 
/* 04-59 UD1_POSIT_L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-39   5Floor Position L 
/* 04-60 UD2_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-40   6Floor Position H 
/* 04-61 UD2_POSIT_L  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-41   6Floor Position L 
/* 04-62 UD3_POSIT_H  */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-42   7Floor Position H 
/* 04-63 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-43   7Floor Position L 
/* 04-64 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-44   8Floor Position H 
/* 04-65 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-45   8Floor Position L 
/* 04-66 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-46   9Floor Position H 
/* 04-67 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-47   9Floor Position L 
/* 04-68 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-48   10Floor Position H
/* 04-69 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-49   10Floor Position L
/* 04-70 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-50   11Floor Position H
/* 04-71 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-51   11Floor Position L
/* 04-72 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-52   12Floor Position H
/* 04-73 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-53   12Floor Position L
/* 04-74 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-54   13Floor Position H
/* 04-75 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-55   13Floor Position L
/* 04-76 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-56   14Floor Position H
/* 04-77 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-57   14Floor Position L
/* 04-78 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-58   15Floor Position H
/* 04-79 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-59   15Floor Position L
/* 04-80 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-60   16Floor Position H
/* 04-81 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-61   16Floor Position L
/* 04-82 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-62   17Floor Position H
/* 04-83 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-63   17Floor Position L
/* 04-84 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-64   18Floor Position H
/* 04-85 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-65   18Floor Position L
/* 04-86 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-66   19Floor Position H
/* 04-87 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-67   19Floor Position L
/* 04-88 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-68   20Floor Position H
/* 04-89 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-69   20Floor Position L
/* 04-90 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-70   21Floor Position H
/* 04-91 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-71   21Floor Position L
/* 04-92 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-72   22Floor Position H
/* 04-93 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-73   22Floor Position L
/* 04-94 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-74   23Floor Position H
/* 04-95 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-75   23Floor Position L
/* 04-96 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-76   24Floor Position H
/* 04-97 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-77   24Floor Position L
/* 04-98 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-78   25Floor Position H
/* 04-99 Reserved     */  READ|RLD|DOT0,                  0,          65535,              0,   //    2XX 04-79   25Floor Position L                                                           
};

// DLC floor position offest ---Aevin 6/19/2018
const PARAM_ATTR attr_DLC_adjst[DLC_TABLE] = {   // JINGDO
/* 04-50 1F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-51 2F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-52 3F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-53 4F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-54 5F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-55 6F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-56 7F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-57 8F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-58 9F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-59 10F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-60 11F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-61 12F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-62 13F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0, 
/* 04-63 14F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-64 15F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-65 16F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-66 17F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-67 18F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-68 19F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-69 20F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-70 21F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-71 22F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-72 23F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-73 24F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-74 25F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-75 26F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-76 27F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-77 28F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-78 29F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-79 30F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-80 31F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-81 32F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-82 33F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-83 34F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-84 35F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-85 36F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-86 37F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-87 38F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-88 39F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-89 40F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-90 41F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-91 42F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-92 43F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-93 44F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-94 45F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-95 46F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-96 47F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-97 48F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-98 49F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-99 50F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
};

//adjust floor position,Henry,2019/01/07
const PARAM_ATTR attr_DLC_adjst2[DLC_TABLE] = {
/* 04-50 1F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,
/* 04-51 2F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-52 3F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-53 4F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-54 5F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-55 6F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-56 7F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-57 8F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-58 9F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-59 10F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-60 11F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-61 12F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-62 13F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0, 
/* 04-63 14F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-64 15F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-65 16F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-66 17F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-67 18F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-68 19F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-69 20F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-70 21F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-71 22F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-72 23F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-73 24F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-74 25F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-75 26F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-76 27F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-77 28F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-78 29F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-79 30F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-80 31F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-81 32F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-82 33F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-83 34F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-84 35F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-85 36F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-86 37F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-87 38F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-88 39F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-89 40F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-90 41F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-91 42F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-92 43F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-93 44F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-94 45F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-95 46F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-96 47F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-97 48F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-98 49F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-99 50F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
};

const PARAM_ATTR attr_DLC_adjst3[DLC_TABLE] = {
/* 04-50 1F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,
/* 04-51 2F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-52 3F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-53 4F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-54 5F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-55 6F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-56 7F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-57 8F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-58 9F flr offset */  SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-59 10F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-60 11F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-61 12F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-62 13F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0, 
/* 04-63 14F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-64 15F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-65 16F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,     
/* 04-66 17F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-67 18F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-68 19F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-69 20F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-70 21F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-71 22F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-72 23F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-73 24F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-74 25F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-75 26F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-76 27F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-77 28F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-78 29F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-79 30F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-80 31F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-81 32F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-82 33F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-83 34F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-84 35F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-85 36F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-86 37F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-87 38F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-88 39F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-89 40F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-90 41F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,  
/* 04-91 42F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-92 43F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-93 44F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-94 45F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-95 46F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-96 47F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-97 48F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
/* 04-98 49F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,   
/* 04-99 50F flr offset */ SIGN|RLD|DOT0,              -100,            100,              0,    
};

const DP_PARAM_ATTR DispAttr[(C21MAX+C22MAX)] = {
/* 2100H Error code      */  READ|DOT0,
/* 2101H Drive status    */  READ|DOT0|DPH,
/* 2102H Freq. setpoint  */  READ|DOT2|CHG,
/* 2103H Output freq.    */  READ|DOT2|CHG,
/* 2104H Output current  */  READ|DOT2,
/* 2105H DC-Bus voltage  */  READ|DOT1,
/* 2106H Output voltage  */  READ|DOT1,
/* 2107H Multi-speed     */  READ|DOT0,
/* 2108H PLC timer       */  READ|DOT0,
/* 2109H Trigger count   */  READ|DOT0,
/* 210AH PF angle        */  READ|DOT1,
/* 210BH Output Torque   */  READ|DOT0,
/* 210CH Motor RPM       */  READ|DOT0,
/* 210DH PG fbk pulse cnt*/  READ|DOT1,
/* 210EH PG ref pulse cnt*/  READ|DOT0,
/* 210FH Output Power    */  READ|DOT0,
/* 2110H VFD type ID     */  READ|DOT0|JMP,
/* 2111H Group number    */  READ|DOT0|JMP,
/* 2112H Software ver.   */  READ|DOT2|JMP,
/* 2113H Start up disp.  */  READ|DOT0|JMP,
/* 2114H Reserved        */  READ|DOT0|JMP,
/* 2115H Feedback freq.  */  READ|DOT2|JMP,
/* 2116H User define     */  READ|DOT0,
/* 2117H User define att */  READ|DOT0|DPH|JMP,
/* 2118H Warn + Error    */  READ|DOT0|JMP,
/* 2119H Drive status    */  READ|DOT0|DPH,
/* 211AH F page value    */  READ|DOT0,
/* 211BH Max of Fcmd     */  READ|DOT2,
/* 211CH H page value    */  READ|DOT2,
/* 211DH F, Fmax, H att  */  READ|DOT0|DPH|JMP,
/* 211EH A page value    */  READ|DOT2|JMP,
/* 211FH A attribute     */  READ|DOT0|DPH|JMP,
/* 2120H Error Fcmd      */  READ|DOT2,
/* 2121H Error Fout      */  READ|DOT2,
/* 2122H Error Isum      */  READ|DOT2,
/* 2123H Error Ffbk      */  READ|DOT2,
/* 2124H Error Vout      */  READ|DOT1,
/* 2125H Error Vbus      */  READ|DOT1,
/* 2126H Error Power     */  READ|SIGN|DOT2,
/* 2127H Error Torque    */  READ|SIGN|DOT1,
/* 2128H Error IGBT Temp.*/  READ|SIGN|DOT1,
/* 2129H Error MI State  */  READ|DOT0|DPH,
/* 212AH Error MO State  */  READ|DOT0|DPH,
/* 212BH Error Drive St. */  READ|DOT0|DPH,
/* 2200H PID Feedback    */  READ|DOT2|JMP,
/* 2201H User define(LWd)*/  READ|DOT0,
/* 2202H User define(HWd)*/  READ|DOT0,
/* 2203H AUI1            */  READ|SIGN|DOT1,
/* 2204H ACI             */  READ|SIGN|DOT1,
/* 2205H AUI2            */  READ|SIGN|DOT1,
/* 2206H IGBT Temp.      */  READ|SIGN|DOT1,
/* 2207H HeatSink Temp.  */  READ|SIGN|DOT1,
/* 2208H MFI State       */  READ|DOT0,
/* 2209H MFO State       */  READ|DOT0,
/* 220AH Password        */  READ|DOT0|JMP,
/* 220BH Reserved        */  READ|DOT0|JMP,
/* 220CH Debug Page Num. */  READ|DOT0|JMP,
/* 220DH Z Pulse Flag    */  READ|DOT0|JMP,
/* 220EH GFF Analog      */  READ|DOT0|JMP,
/* 220FH Safety & CC Flag*/  READ|DOT0|JMP,
/* 221AH Reserved        */  READ|DOT0|JMP,
/* 221BH Reserved        */  READ|DOT0|JMP,
/* 221CH Reserved        */  READ|DOT0|JMP,
/* 221DH Reserved        */  READ|DOT0|JMP,
/* 221EH Reserved        */  READ|DOT0|JMP,
/* 221FH Reserved        */  READ|DOT0|JMP,
/* 2220H Error Fcmd      */  READ|DOT2,
/* 2221H Error Fout      */  READ|DOT2,
/* 2222H Error Isum      */  READ|DOT2,
/* 2223H Error Ffbk      */  READ|DOT2,
/* 2224H Error Vout      */  READ|DOT1,
/* 2225H Error Vbus      */  READ|DOT1,
/* 2226H Error Power     */  READ|SIGN|DOT2,
/* 2227H Error Torque    */  READ|SIGN|DOT1,
/* 2228H Error IGBT Temp.*/  READ|SIGN|DOT1,
/* 2229H Error MI State  */  READ|DOT0|DPH,
/* 222AH Error MO State  */  READ|DOT0|DPH,
/* 222BH Error Drive St. */  READ|DOT0|DPH,
};


const DP_PARAM_ATTR DispAttr_c22xx[(C22MAX)] = {
    /* 2200H PID Feedback    */  READ|DOT2|JMP,
    /* 2201H User define(LWd)*/  READ|DOT0,
    /* 2202H User define(HWd)*/  READ|DOT0,
    /* 2203H AUI1            */  READ|SIGN|DOT1,
    /* 2204H ACI             */  READ|SIGN|DOT1,
    /* 2205H AUI2            */  READ|SIGN|DOT1,
    /* 2206H IGBT Temp.      */  READ|SIGN|DOT1,
    /* 2207H HeatSink Temp.  */  READ|SIGN|DOT1,
    /* 2208H MFI State       */  READ|DOT0,
    /* 2209H MFO State       */  READ|DOT0,
    /* 220AH Password        */  READ|DOT0|JMP,
    /* 220BH Reserved        */  READ|DOT0|JMP,
    /* 220CH Debug Page Num. */  READ|DOT0|JMP,
    /* 220DH Z Pulse Flag    */  READ|DOT0|JMP,
    /* 220EH GFF Analog      */  READ|DOT0|JMP,
    /* 220FH Safety & CC Flag*/  READ|DOT0|JMP,
    /* 2210H DATECODE        */  S2EEP|RLD|READ|DOT3|JMP,
    /* 2211H Reserved        */  READ|DOT0|JMP,
    /* 2212H Reserved        */  READ|DOT0|JMP,
    /* 2213H Reserved        */  READ|DOT0|JMP,
    /* 2214H Reserved        */  READ|DOT0|JMP,
    /* 2215H Reserved        */  READ|DOT0|JMP,
    /* 2216H Reserved        */  READ|DOT0|JMP,
    /* 2217H Reserved        */  READ|DOT0|JMP,
    /* 2218H Reserved        */  READ|DOT0|JMP,
    /* 2219H Reserved        */  READ|DOT0|JMP,
    /* 221AH Reserved        */  READ|DOT0|JMP,
    /* 221BH Reserved        */  READ|DOT0|JMP,
    /* 221CH Reserved        */  READ|DOT0|JMP,
    /* 221DH Reserved        */  READ|DOT0|JMP,
    /* 221EH Reserved        */  READ|DOT0|JMP,
    /* 221FH Reserved        */  READ|DOT0|JMP,
    /* 2220H Error Fcmd      */  READ|DOT2,
    /* 2221H Error Fout      */  READ|DOT2,
    /* 2222H Error Isum      */  READ|DOT2,
    /* 2223H Error Ffbk      */  READ|DOT2,
    /* 2224H Error Vout      */  READ|DOT1,
    /* 2225H Error Vbus      */  READ|DOT1,
    /* 2226H Error Power     */  READ|SIGN|DOT2,
    /* 2227H Error Torque    */  READ|SIGN|DOT1,
    /* 2228H Error IGBT Temp.*/  READ|SIGN|DOT1,
    /* 2229H Error MI State  */  READ|DOT0|DPH,
    /* 222AH Error MO State  */  READ|DOT0|DPH,
    /* 222BH Error Drive St. */  READ|DOT0|DPH,

};

#if 1 // OH update, Sean, 04/19/2011
const UWORD CTispec[MAXMODELNO+1]={
//      0       1       2       3       4       5       6       7       8       9
//     220V    440V    220V    440V    220V    440V    220V    440V    220V    440V
//-------------------------------------------------------------------------------------
//    -0.2kW(1/4Hp)-  -0.4kW(1/2Hp)-   -0.75kW(1Hp)-   -1.5kW(2Hp)-    -2.2kW(3Hp)-
        160,    10,     300,    160,    500,    300,    750,    420,    1091,   600,
//-------------------------------------------------------------------------------------
// 10 -3.7kW(5Hp)-    -5.5kW(7.5Hp)-   -7.5kW(10Hp)-   -11 kW(15Hp)    -15kW(20Hp)-
        1818,   1045,    2182,   1182,   2727,   1545,   4091,   2091,   5273,   2727,
//-------------------------------------------------------------------------------------
// 20 -18.5kW(25Hp)-   -22kW(30Hp)-    -30kW(40Hp)-    -37 kW(50Hp)    -45kW(60Hp)-
        7000,   3455,   7909,   4091,   12000,  5273,   14636,  7273,   18200,  9091,
//-------------------------------------------------------------------------------------
// 30 -55kW(75Hp)-     -75kW(100Hp)-   -90kW(125Hp)-   -110kW(150Hp)    -132kW(175Hp)-
        22000,  11636,  30000,  15000,  1,      18700,  1,      20000,  1,      26000,
//-------------------------------------------------------------------------------------
   // unit: 0.01A,  "1": no such type      
};

const UWORD CTispecSingle[MAXMODELNO+1]={         //[Single phase input, Bernie, 01/19/2012]
//      0       1       2       3       4       5       6       7       8       9
//     220V    440V    220V    440V    220V    440V    220V    440V    220V    440V
//-------------------------------------------------------------------------------------
//    -0.2kW(1/4Hp)-  -0.4kW(1/2Hp)-   -0.75kW(1Hp)-   -1.5kW(2Hp)-    -2.2kW(3Hp)-
        160,    10,     300,    160,    500,    300,    750,    420,    1091,   600,
//-------------------------------------------------------------------------------------
// 10 -3.7kW(5Hp)-    -5.5kW(7.5Hp)-   -7.5kW(10Hp)-   -11 kW(15Hp)    -15kW(20Hp)-
        1545,   1045,    2182,   1182,   2727,   1545,   4091,   2091,   5273,   2727,
//-------------------------------------------------------------------------------------
// 20 -18.5kW(25Hp)-   -22kW(30Hp)-    -30kW(40Hp)-    -37 kW(50Hp)    -45kW(60Hp)-
        7000,   3455,   7909,   4091,   12000,  5273,   14636,  7273,   18200,  9091,
//-------------------------------------------------------------------------------------
// 30 -55kW(75Hp)-     -75kW(100Hp)-   -90kW(125Hp)-   -110kW(150Hp)    -132kW(175Hp)-
        22000,  11636,  30000,  15000,  1,      18700,  1,      20000,  1,      26000,
//-------------------------------------------------------------------------------------
   // unit: 0.01A,  "1": no such type      
};

#else
const UWORD CTispec[MAXMODELNO+1]={
//      0       1       2       3       4       5       6       7       8       9
//     220V    440V    220V    440V    220V    440V    220V    440V    220V    440V
//-------------------------------------------------------------------------------------
//    -0.2kW(1/4Hp)-  -0.4kW(1/2Hp)-   -0.75kW(1Hp)-   -1.5kW(2Hp)-    -2.2kW(3Hp)-
        160,    10,     300,    160,    500,    300,    750,    420,    1090,   600,
//-------------------------------------------------------------------------------------
// 10 -3.7kW(5Hp)-    -5.5kW(7.5Hp)-   -7.5kW(10Hp)-   -11 kW(15Hp)    -15kW(20Hp)-
        1820,   1050,    2190,   1230,   2710,   1580,   4110,   2100,   5300,   2700,
//-------------------------------------------------------------------------------------
// 20 -18.5kW(25Hp)-   -22kW(30Hp)-    -30kW(40Hp)-    -37 kW(50Hp)    -45kW(60Hp)-
        7000,   3400,   7900,   4100,   12000,  5270,   14600,  7300,   18200,  9100,
//-------------------------------------------------------------------------------------
// 30 -55kW(75Hp)-     -75kW(100Hp)-   -90kW(125Hp)-   -110kW(150Hp)    -132kW(175Hp)-
        22000,  11600,  30000,  15000,  1,      18700,  1,      22000,  1,      26000,
//-------------------------------------------------------------------------------------
   // unit: 0.01A,  "1": no such type      
};

#endif

const UWORD VTispec[MAXMODELNO+1]={
//      0       1       2       3       4       5       6       7       8       9
//     220V    440V    220V    440V    220V    440V    220V    440V    220V    440V
//-------------------------------------------------------------------------------------
//    -0.2kW(1/4Hp)-  -0.4kW(1/2Hp)-   -0.75kW(1Hp)-   -1.5kW(2Hp)-    -2.2kW(3Hp)-
        200,    13,     375,    200,    625,    380,    940,    530,    1300,   750,
//-------------------------------------------------------------------------------------
// 10 -3.7kW(5Hp)-    -5.5kW(7.5Hp)-   -7.5kW(10Hp)-   -11 kW(15Hp)    -15kW(20Hp)-
        2100,  1000,    2500,   1400,   3100,   1800,   4700,   2400,   6000,   3100,
//-------------------------------------------------------------------------------------
// 20 -18.5kW(25Hp)-   -22kW(30Hp)-    -30kW(40Hp)-    -37 kW(50Hp)    -45kW(60Hp)-
        8000,   3900,   9000,   4700,   15000,  7500,   18200,  9100,   22700, 11300,
//-------------------------------------------------------------------------------------
// 30 -55kW(75Hp)-     -75kW(100Hp)-   -90kW(125Hp)-   -110kW(150Hp)    -132kW(175Hp)-
        27500,  13800,  37500,  18800,  1,      23300,  1,      27500,  1,      32500,
//-------------------------------------------------------------------------------------
   // unit: 0.01A,  "1": no such type      
};

const UWORD VTispecSingle[MAXMODELNO+1]={        //[Single phase input, Bernie, 01/19/2012]
//      0       1       2       3       4       5       6       7       8       9
//     220V    440V    220V    440V    220V    440V    220V    440V    220V    440V
//-------------------------------------------------------------------------------------
//    -0.2kW(1/4Hp)-  -0.4kW(1/2Hp)-   -0.75kW(1Hp)-   -1.5kW(2Hp)-    -2.2kW(3Hp)-
        200,    13,     375,    200,    625,    380,    940,    530,    1300,   750,
//-------------------------------------------------------------------------------------
// 10 -3.7kW(5Hp)-    -5.5kW(7.5Hp)-   -7.5kW(10Hp)-   -11 kW(15Hp)    -15kW(20Hp)-
        2100,  1000,    2500,   1400,   3100,   1800,   4700,   2400,   6000,   3100,
//-------------------------------------------------------------------------------------
// 20 -18.5kW(25Hp)-   -22kW(30Hp)-    -30kW(40Hp)-    -37 kW(50Hp)    -45kW(60Hp)-
        8000,   3900,   9000,   4700,   15000,  7500,   18200,  9100,   22700, 11300,
//-------------------------------------------------------------------------------------
// 30 -55kW(75Hp)-     -75kW(100Hp)-   -90kW(125Hp)-   -110kW(150Hp)    -132kW(175Hp)-
        27500,  13800,  37500,  18800,  1,      23300,  1,      27500,  1,      32500,
//-------------------------------------------------------------------------------------
   // unit: 0.01A,  "1": no such type      
};

const UWORD RatedPower[38] = {
//   0     1     2     3     4     5     6     7     8     9 
     1,    1,    1,    1,    1,    1,    1,    1,    1,    1, 
//  10    11    12    13    14    15    16    17    18    19 
   400,  400,  550 ,  550,  750,  750,  1100, 1100, 1500,   1500, 
//  20    21    22    23    24    25    26    27    28    29
   1850, 1850, 2200, 2200, 3000, 3000, 3700, 3700,   1,   4500, 
//  30    31    32    33 
     1,   5500,   1,  7500, 1, 1, 1, 11000
};


const UWORD RatedPower_SINGLE[13] = {                           //[Add output power selection, Bernie, 2016/06/08]
//  0     1     2     3     4     5     6     7     8     9 
    1,    1,    1,    1,    1,    1,    1,    1,   220,    1, 
// 10    11    12        
   370,    1,    1,

};


const UWORD SpDt_ulPG1Kmt_LoSpd_Wei[12] = {
  65535, // 1.00
  55706, // 0.85
  47350, // 0.72
  40247, // 0.61
  34210, // 0.52
  29078, // 0.44
  24717, // 0.37
  21009, // 0.32
  17857, // 0.27
  15179, // 0.23
  12902, // 0.16
  9322   // 0.12
};

const SWORD Nh_swDeepDB[21] = {    //Q15,1/(10^(x/20)) * 2^15
    32767, // 0 db
    29205, // 1 db
    26029, // 2 db
    23198, // 3 db
    20675, // 4 db
    18427, // 5 db
    16423, // 6 db
    14637, // 7 db
    13045, // 8 db
    11627, // 9 db
    10362, //10 db
    9235 , //11 db
    8231 , //12 db
    7336 , //13 db
    6538 , //14 db
    5827 , //15 db
    5193 , //16 db
    4629 , //17 db
    4125 , //18 db
    3676 , //19 db
    3277   //20 db
};

const UWORD FaultBitCodeTable[ERRMAX+1] = {
  0 , //   0: No Error
  1 , //   1: ocA
  1 , //   2: ocd
  1 , //   3: ocn
  32, //   4: GFF
  1 , //   5: occ
  1 , //   6: ocS
  2 , //   7: ovA
  2 , //   8: ovd
  2 , //   9: ovn
  2 , //  10: ovS
  2 , //  11: LvA
  2 , //  12: Lvd
  2 , //  13: Lvn
  2 , //  14: LvS
  32, //  15: PHL
  4 , //  16: oH1  (IGBT)
  4 , //  17: oH2  (40HP above)
  4 , //  18: tH1o (TH1 open)
  4 , //  19: tH2o (TH2 open)
  32, //  20: Fan
  4 , //  21: oL   (150% 1Min, Inverter)
  4 , //  22: EoL1 (Motor 1)
  4 , //  23: EoL2 (Motor 2)
  4 , //  24: oH3  (PTC)
  32, //  25: FuSE
  4 , //  26: ot1
  4 , //  27: ot2
  1 , //  28: uc1
  1 , //  29: uc2
  8 , //  30: cF1
  8 , //  31: cF2
  8 , //  32: cd0
  8 , //  33: cd1
  8 , //  34: cd2
  8 , //  35: cd3
  8 , //  36: Hd0
  8 , //  37: Hd1
  8 , //  38: Hd2
  8 , //  39: Hd3
  8 , //  40: AuE  (Auto Tun Error)
  16, //  41: AFE  (PID Feed back Error)
  16, //  42: PGF1 (PG fbk Error)
  16, //  43: PGF2 (PG fbk Loss)
  16, //  44: PGF3 (PG fbk Overspeed)
  16, //  45: PGF4 (PG fbk Deviation Error)
  16, //  46: PGr1 (PG Ref Error)
  16, //  47: PGr2 (PG Ref Loss)
  16, //  48: ACE  (ACI Loss)
  32, //  49: EF   (External Fault)
  32, //  50: EF1  (Emergency Stop)
  32, //  51: bb   (base block)
  8 , //  52: PcodE(Password)
  8 , //  53: ccodE(SW)
  64, //  54: cE1  (communication)
  64, //  55: cE2
  64, //  56: cE3
  64, //  57: cE4
  64, //  58: cE10 (Communication Time Out)
  64, //  59: cP10 (PU Time out)
  32, //  60: bF   (Braking Transistor Fault)
  32, //  61: ydc  (Y-Delta connected Error)
  2 , //  62: Decel. Energy Backup Error (DEB)
  8 , //  63: SRY  (Safety Relay Error), add by dino, 06/06/2007
  32, //  64: MbF  (Mechanical Brake Failed), add by DINO, 05/14/2008
  8 , //  65: PGF5 (PG Hardware Error)
  32, //  66: MCF  (Magnetic Contactor Failed), add by DINO, 03/25/2009
  32, //  67: MPHL (Motor Phase Loss), add by Sampo, 05/12/2009
  64, //  68: CAN Error  //[Parameter added by  ]
  8 , //  69: STO  //[STO function has fixed, Bernie, 2015/03/02]
  8 , //  70: STL1
  16, //  71: Over Acc
  8 , //  72: STL3
  8 , //  73: PGcd
  8 , //  74: PGHL  //[modify Error code,Lyabryan,2016/07/21]
  8 , //  75: PGAF  //[modify Error code,Lyabryan,2016/07/21]
  0 , //  76: No Error
  0 , //  77: No Error
  0 , //  78: No Error
  0 , //  79: No Error
  0 , //  80: No Error
  0 , //  81: No Error
  32, //  82: OPHLU_ERR
  32, //  83: OPHLV_ERR
  32, //  84: OPHLW_ERR
  0 , //  85: DLC Error
  0 , //  86: LSS //#15977, LULD detect, James, 2021/04/01
  0 , //  87: LSO //#15977, LULD detect, James, 2021/04/01
  32, //  88: CurCtrl_ERR //#16434 MPHL improvement, Jerry, 2021/06/30
  0 , //  89: STOL4_ERR 
  0 , //  90: STOr_ERR
  0 , //  91: STOS_ERR
  8 , //  92: Sensor817_ERR //[Artemis Add Sensor819 Function/Special/2022/06/06]
  8 , //  93: Sensor818_ERR //[Artemis Add Sensor819 Function/Special/2022/06/06]
  8 , //  94: BTT Test Fail     //BTT Test Fail [JES Torq Detect Function, Special.Kung, 2022/09/01]
  8 , //  95: BTT Test Error    //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
  8 , //  96: BTT No Action     //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
  0 , //  94: No Error
};


const UBYTE FaultBitCodeTable1[ERRMAX+1] = {
  0 , //   0: No Error
  1 , //   1: ocA
  1 , //   2: ocd
  1 , //   3: ocn
  1 , //   4: GFF
  1 , //   5: occ
  1 , //   6: ocS
  2 , //   7: ovA
  2 , //   8: ovd
  2 , //   9: ovn
  2 , //  10: ovS
  3 , //  11: LvA
  3 , //  12: Lvd
  3 , //  13: Lvn
  3 , //  14: LvS
  3 , //  15: PHL
  4 , //  16: oH1  (IGBT)
  4 , //  17: oH2  (40HP above)
  4 , //  18: tH1o (TH1 open)
  4 , //  19: tH2o (TH2 open)
  0 , //  20: Reserved
  5 , //  21: oL   (150% 1Min, Inverter)
  6 , //  22: EoL1 (Motor 1)
  6 , //  23: EoL2 (Motor 2)
  6 , //  24: oH3  (PTC)
  8 , //  25: FuSE
  7 , //  26: ot1
  7 , //  27: ot2
  7 , //  28: uc1
  7 , //  29: uc2
  8 , //  30: cF1
  8 , //  31: cF2
  8 , //  32: cd0
  8 , //  33: cd1
  8 , //  34: cd2
  8 , //  35: cd3
  8 , //  36: Hd0
  8 , //  37: Hd1
  8 , //  38: Hd2
  8 , //  39: Hd3
  9 , //  40: AuE  (Auto Tun Error)
  10, //  41: AFE  (PID Feed back Error)
  10, //  42: PGF1 (PG fbk Error)
  10, //  43: PGF2 (PG fbk Loss)
  7 , //  44: PGF3 (PG fbk Overspeed)
  10, //  45: PGF4 (PG fbk Deviation Error)
  10, //  46: PGr1 (PG Ref Error)
  10, //  47: PGr2 (PG Ref Loss)
  10, //  48: ACE  (ACI Loss)
  11, //  49: EF   (External Fault)
  11, //  50: EF1  (Emergency Stop)
  11, //  51: bb   (base block)
  9 , //  52: PcodE(Password)
  9 , //  53: ccodE(SW)
  12, //  54: cE1  (communication)
  12, //  55: cE2
  12, //  56: cE3
  12, //  57: cE4
  12, //  58: cE10 (Communication Time Out)
  12, //  59: cP10 (PU Time out)
  8 , //  60: bF   (Braking Transistor Fault)
  11, //  61: ydc  (Y-Delta connected Error)
  1 , //  62: Decel. Energy Backup Error (DEB)
  11, //  63: SRY  (Safety Relay Error), add by dino, 06/06/2007
  11, //  64: MbF  (Mechanical Brake Failed), add by DINO, 05/14/2008
  8 , //  65: PGF5 (PG Hardware Error)
  11, //  66: MCF  (Magnetic Contactor Failed), add by DINO, 03/25/2009
  11, //  67: MPHL (Motor Phase Loss), add by Sampo, 05/12/2009
  13, //  68: CAN Error  //[Parameter added by  ]
  14, //  69: STO   //[STO function has fixed, Bernie, 2015/03/02]
  14, //  70: STL1
  7 , //  71: Over Acc
  14, //  72: STL3
  8 , //  73: PGcd
  8 , //  74: PGHL  //[modify Error code,Lyabryan,2016/07/21]
  8 , //  75: PGAF  //[modify Error code,Lyabryan,2016/07/21]
  0 , //  76: No Error
  0 , //  77: No Error
  0 , //  78: No Error
  0 , //  79: No Error
  0 , //  80: No Error
  0 , //  81: No Error
  11, //  82: OPHLU_ERR
  11, //  83: OPHLV_ERR
  11, //  84: OPHLW_ERR
  0 , //  85: DLC Error
  0 , //  86: LSS //#15977, LULD detect, James, 2021/04/01
  0 , //  87: LSO //#15977, LULD detect, James, 2021/04/01
  11, //  88: CurCtrl_ERR //#16434 MPHL improvement, Jerry, 2021/06/30
  0 , //  89: STOL4_ERR 
  0 , //  90: STOr_ERR
  0 , //  91: STOS_ERR
  8 , //  92: Sensor817_ERR //[Artemis Add Sensor819 Function/Special/2022/06/06]
  8 , //  93: Sensor818_ERR //[Artemis Add Sensor819 Function/Special/2022/06/06]
  8 , //  94: BTT Test Fail
  8 , //  95: BTT Test Error
  8 , //  96: BTT No Action
  0 , //  97: No Error
};


const UBYTE HEX2ASC[16] = {
//   0     1     2     3     4     5     6     7     8     9  
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
//     a     b     c     d     e     f
  0x41, 0x42, 0x43, 0x44, 0x45, 0x46 };

const UWORD HEX2ASC16[256] = {
//  0       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
 0x3030, 0x3031, 0x3032, 0x3033, 0x3034, 0x3035, 0x3036, 0x3037, 0x3038, 0x3039, 0x3041, 0x3042, 0x3043, 0x3044, 0x3045, 0x3046, /* 0 */
 0x3130, 0x3131, 0x3132, 0x3133, 0x3134, 0x3135, 0x3136, 0x3137, 0x3138, 0x3139, 0x3141, 0x3142, 0x3143, 0x3144, 0x3145, 0x3146, /* 1 */
 0x3230, 0x3231, 0x3232, 0x3233, 0x3234, 0x3235, 0x3236, 0x3237, 0x3238, 0x3239, 0x3241, 0x3242, 0x3243, 0x3244, 0x3245, 0x3246, /* 2 */
 0x3330, 0x3331, 0x3332, 0x3333, 0x3334, 0x3335, 0x3336, 0x3337, 0x3338, 0x3339, 0x3341, 0x3342, 0x3343, 0x3344, 0x3345, 0x3346, /* 3 */
 0x3430, 0x3431, 0x3432, 0x3433, 0x3434, 0x3435, 0x3436, 0x3437, 0x3438, 0x3439, 0x3441, 0x3442, 0x3443, 0x3444, 0x3445, 0x3446, /* 4 */
 0x3530, 0x3531, 0x3532, 0x3533, 0x3534, 0x3535, 0x3536, 0x3537, 0x3538, 0x3539, 0x3541, 0x3542, 0x3543, 0x3544, 0x3545, 0x3546, /* 5 */
 0x3630, 0x3631, 0x3632, 0x3633, 0x3634, 0x3635, 0x3636, 0x3637, 0x3638, 0x3639, 0x3641, 0x3642, 0x3643, 0x3644, 0x3645, 0x3646, /* 6 */
 0x3730, 0x3731, 0x3732, 0x3733, 0x3734, 0x3735, 0x3736, 0x3737, 0x3738, 0x3739, 0x3741, 0x3742, 0x3743, 0x3744, 0x3745, 0x3746, /* 7 */
 0x3830, 0x3831, 0x3832, 0x3833, 0x3834, 0x3835, 0x3836, 0x3837, 0x3838, 0x3839, 0x3841, 0x3842, 0x3843, 0x3844, 0x3845, 0x3846, /* 8 */
 0x3930, 0x3931, 0x3932, 0x3933, 0x3934, 0x3935, 0x3936, 0x3937, 0x3938, 0x3939, 0x3941, 0x3942, 0x3943, 0x3944, 0x3945, 0x3946, /* 9 */
 0x4130, 0x4131, 0x4132, 0x4133, 0x4134, 0x4135, 0x4136, 0x4137, 0x4138, 0x4139, 0x4141, 0x4142, 0x4143, 0x4144, 0x4145, 0x4146, /* A */
 0x4230, 0x4231, 0x4232, 0x4233, 0x4234, 0x4235, 0x4236, 0x4237, 0x4238, 0x4239, 0x4241, 0x4242, 0x4243, 0x4244, 0x4245, 0x4246, /* B */
 0x4330, 0x4331, 0x4332, 0x4333, 0x4334, 0x4335, 0x4336, 0x4337, 0x4338, 0x4339, 0x4341, 0x4342, 0x4343, 0x4344, 0x4345, 0x4346, /* C */
 0x4430, 0x4431, 0x4432, 0x4433, 0x4434, 0x4435, 0x4436, 0x4437, 0x4438, 0x4439, 0x4441, 0x4442, 0x4443, 0x4444, 0x4445, 0x4446, /* D */
 0x4530, 0x4531, 0x4532, 0x4533, 0x4534, 0x4535, 0x4536, 0x4537, 0x4538, 0x4539, 0x4541, 0x4542, 0x4543, 0x4544, 0x4545, 0x4546, /* E */
 0x4630, 0x4631, 0x4632, 0x4633, 0x4634, 0x4635, 0x4636, 0x4637, 0x4638, 0x4639, 0x4641, 0x4642, 0x4643, 0x4644, 0x4645, 0x4646  /* F */
};
#else
    extern const UWORD prtab[(GRALL+1)];
    extern const UWORD pr_gpno_Sibo[(GRALL+1)];
    extern const UWORD pr_gpno[(GRALL+1)];
    extern const PARAM_ATTR attr1[PRMAX];
    extern const DP_PARAM_ATTR DispAttr[(C21MAX+C22MAX)];
    extern const DP_PARAM_ATTR DispAttr_c22xx[(C22MAX)];
    extern const UWORD CTispec[MAXMODELNO+1];
    extern const UWORD VTispec[MAXMODELNO+1];
    extern const UWORD CTispecSingle[MAXMODELNO+1];         //[Single phase input, Bernie, 01/19/2012]
    extern const UWORD VTispecSingle[MAXMODELNO+1];         //[Single phase input, Bernie, 01/19/2012]
    extern const UBYTE ol[93];
    extern const UWORD SpDt_ulPG1Kmt_LoSpd_Wei[12];
    extern const SWORD Nh_swDeepDB[20];
    extern const UWORD FaultBitCodeTable[ERRMAX+1];
    extern const UBYTE FaultBitCodeTable1[ERRMAX+1];
    extern const UBYTE HEX2ASC[16];
    extern const UWORD HEX2ASC16[256];
    extern const UWORD RatedPower_SINGLE[13]; //[Add output power selection, Bernie, 2016/06/08]
    extern const UWORD RatedPower[34]; //[Add output power selection, Bernie, 2016/06/08]
    extern const PARAM_ATTR attr_DLC1[DLC_TABLE];  // JINGDO
    extern const PARAM_ATTR attr_DLC2[DLC_TABLE];  // JINGDO
    extern const PARAM_ATTR attr_DLC3[DLC_TABLE];  // JINGDO
    extern const PARAM_ATTR attr_DLC_adjst[DLC_TABLE];  // JINGDO
    extern const PARAM_ATTR attr_DLC_adjst2[DLC_TABLE]; //adjust floor position,Henry,2019/01/07
    extern const PARAM_ATTR attr_DLC_adjst3[DLC_TABLE]; //adjust floor position,Henry,2019/01/07
#endif
