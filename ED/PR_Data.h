/*------------	Group15	 --------*/						
#define	GROUP15			0					
#define	DEBUG_F1		(GROUP15+0)		//	0	15-00	Debug Flag 1	
#define	DBCCHG_F		(GROUP15+1)		//	1	15-01	DBC CHANGE FREQ	
#define	PFEF			(GROUP15+2)		//	2	15-02	efficiency of Motor	
#define DC_ZSEARCH		(GROUP15+3)		//	3	15-03	Z Phase search current level
#define	AD_IRATE		(GROUP15+4)		//	4	15-04	AD value at Rated Current	
#define	IDQELPFG		(GROUP15+5)		//	5	15-05	Id*,Iq* LPF	
#define	FACTORY1		(GROUP15+6)		//	6	15-06	Only for Factory 1	
#define	FACTORY2		(GROUP15+7)		//	7	15-07	Only for Factory 2	
#define	FACTORY3		(GROUP15+8)		//	8	15-08	Only for Factory 3	
#define	FACTORY4		(GROUP15+9)		//	9	15-09	Only for Factory 4	
#define	RESEVER 		(GROUP15+10)	//	10	15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM	    //clear Warning, Special.kung, 03/08/2023
#define	SKIP_DT			(GROUP15+11)	//	11	15-11	Skip Dead Time	
#define	DCB_AD1			(GROUP15+12)	//	12	15-12	DCBUS 210.0 VDC ad value	
#define	DCB_AD2			(GROUP15+13)	//	13	15-13	DCBUS 310.0 VDC ad value	
#define	DCB_AD3			(GROUP15+14)	//	14	15-14	DCBUS 390.0 VDC ad value	
#define	TRQ_P			(GROUP15+15)	//	15	15-15	Torque control Kp	
#define	TRQ_I			(GROUP15+16)	//	16	15-16	Torque Control Ki	
#define	FLUX_P			(GROUP15+17)	//	17	15-17	Flux Control Kp	
#define	FLUX_I			(GROUP15+18)	//	18	15-18	Flux Control Ki	
#define	SpdSlop_P		(GROUP15+19)	//	19	15-19	Speed slop Control Kp gain	
#define	SpdSlop_I		(GROUP15+20)	//	20	15-20	Speed slop Control Ki gain	
#define	CTRLSEL			(GROUP15+21)	//	21	15-21	Control Selection	
#define	TESTAmp			(GROUP15+22)	//	22	15-22	Test Source Value Amplitude	
#define	HiSpd_LPG		(GROUP15+23)	//	23	15-23	High Speed Low pass Filter Gain	
#define	LoSpd_LPG		(GROUP15+24)	//	24	15-24	Low Speed Low pass filter Gain	
#define	TESTBias		(GROUP15+25)	//	25	15-25	Test Source Value Bias	
#define	EstJ_LPG		(GROUP15+26)	//	26	15-26	Estimate J Low pass Filter Gain	
#define	CALI_REF		(GROUP15+27)	//	27	15-27	Calibration current REF	
#define	CALI_P			(GROUP15+28)	//	28	15-28	Calibration P	
#define	CALI_I			(GROUP15+29)	//	29	15-29	Calibration I	
#define	DCTUN_P			(GROUP15+30)	//	30	15-30	Auto tuning DC test Kp gain	
#define	DCTUN_I			(GROUP15+31)	//	31	15-31	Auto Tuning DC test Ki gain	
#define	HFTUN_P			(GROUP15+32)	//	32	15-32	Auto tuning High Freq. Lock test Kp gain	
#define	DCBUSLPG		(GROUP15+33)	//	33	15-33	ADcbus Low Pass Gain	
#define VCMP_K			(GROUP15+34)	//	34	15-34	Select Zero Speed	
#define NLBOOST			(GROUP15+35)	//	35	15-35	No Load Boost Gain	
#define	AKP			    (GROUP15+36)	//	36	15-36	Acceleration AKP	
#define	AKI			    (GROUP15+37)	//	37	15-37	Acceleration AKI	
#define	CULPBW 			(GROUP15+38)	//	38	15-38	Current Loop BandWidth
#define	DBLEAD2     	(GROUP15+39)	//	39	15-39	DBC Leading 2
#define	DBRATIO2		(GROUP15+40)	//	40	15-40	DBC Ratio 2 with close loop
#define	DBC1			(GROUP15+41)	//	41	15-41	DBC Coef.
#define	DBC2			(GROUP15+42)	//	42	15-42	DBC Dcbus Coef.
#define	DBLEAD			(GROUP15+43)	//	43	15-43	DBC leading 1
#define	DBRATIO			(GROUP15+44)	//	44	15-44	DBC Linear Ratio 1
#define DBC_MODE		(GROUP15+45)	//	45	15-45	DBC MODE
#define	LMPU1			(GROUP15+46)	//	46	15-46	magnitization inductance 1
#define	EMFPU1			(GROUP15+47)	//	47	15-47	main flux linkage 1
#define	LMPU2			(GROUP15+48)	//	48	15-48	magnitization inductance 2
#define	EMFPU2			(GROUP15+49)	//	49	15-49	main flux linkage 2
#define	LMPU3			(GROUP15+50)	//	50	15-50	magnitization inductance 3
#define	EMFPU3			(GROUP15+51)	//	51	15-51	main flux linkage 3
#define	LMPU4			(GROUP15+52)	//	52	15-52	magnitization inductance 4
#define	EMFPU4			(GROUP15+53)	//	53	15-53	main flux linkage 4
#define	LMPU5			(GROUP15+54)	//	54	15-54	magnitization inductance 5
#define	EMFPU5			(GROUP15+55)	//	55	15-55	main flux linkage 5
#define	LMPU6			(GROUP15+56)	//	56	15-56	magnitization inductance 6
#define	EMFPU6			(GROUP15+57)	//	57	15-57	main flux linkage 6
#define	MOD_INDEX		(GROUP15+58)	//	58	15-58	Modulation Index
#define	IZEROLPG		(GROUP15+59)	//	59	15-59	Current Zero Low Pass Gain
#define	COSPHILPG		(GROUP15+60)	//	60	15-60	cos(TB1_uwPhi) low pass gain
#define	DATECODE		(GROUP15+61)	//	61	15-61	reserved // Datecode para change, Henry, 2016/07/20
#define	CAUI2ZERO		(GROUP15+62)	//	62	15-62	calibration for AUI ZeroPoint (0V)
#define	CAUI2MAX		(GROUP15+63)	//	63	15-63	calibration for AUI2 max (+10V)
#define	CAUI2MIN		(GROUP15+64)	//	64	15-64	calibration for AUI2 min (-10V)
#define	CACIMAX			(GROUP15+65)	//	65	15-65	calibration for ACI2 max (20mA)
#define	CACIMID			(GROUP15+66)	//	66	15-66	calibration for ACI mid (12mA)
#define	CACIMIN			(GROUP15+67)	//	67	15-67	calibration for ACI min (4mA)
#define	CAUI1ZERO		(GROUP15+68)	//	68	15-68	calibration for AUI1 ZeroPoint (0V)
#define	CAUI1MAX		(GROUP15+69)	//	69	15-69	calibration for AUI1 max (+10V)
#define	CAUI1MIN		(GROUP15+70)	//	70	15-70	calibration for AUI1 min (-10V)
#define	DKP				(GROUP15+71)	//	71	15-71	Deceleration DKP
#define	DKI				(GROUP15+72)	//	72	15-72	Deceleration DKI
#define	LOW_SPEED		(GROUP15+73)	//	73	15-73	more volt. comp. below this freq.
#define	PGDETCNT		(GROUP15+74)	//	74	15-74	PGLOSS Detect Counter
#define	FMAIN			(GROUP15+75)	//	75	15-75	Main Frequency
#define	PWR_CNT			(GROUP15+76)	//	76	15-76	Power On Counter
#define	GFF_REC_SW		(GROUP15+77)	//	77	15-77	GFF Maximum Value Record, Jerry Yu, 2019/11/11
#define	BLD_VER	        (GROUP15+78)	//	78  15-78   BLD Version //[BootLoader Version, Special.Kung, 2022/10/31]		
#define SIBO_EPS_FRMODE	(GROUP15+79)	//	79	15-79	SIBOCOM EPS FWD/REV EPS Mode, Jason, 191231
#define	OPHL_SPER 		(GROUP15+80)    //  80	15-80   [New OPHL Function,Jerry.SK,2019/12/28]
#define	OPHL_CURER		(GROUP15+81)    //  81	15-81   [New OPHL Function,Jerry.SK,2019/12/28]
#define	OPHL_ERCNT		(GROUP15+82)    //  82	15-82   [New OPHL Function,Jerry.SK,2019/12/28]
#define	BLD_DATECODE	(GROUP15+83)	//	82	15-83   BLD Date Code //[BootLoader DataCode, Special.Kung, 2022/10/31]
#define	FAUIZERO		(GROUP15+84)	//	84	15-84	calibration for AUI ZeroPoint (0V)
#define	FAUIMAX			(GROUP15+85)	//	85	15-85	calibration for AUI max (+2V)
#define	FAUIMIN			(GROUP15+86)	//	86	15-86	calibration for AUI min (-2V)
#define	SINMAX			(GROUP15+87)	//	87	15-87	calibration for SIN max, add by dino, 06/01/2007
#define	SINMIN			(GROUP15+88)	//	88	15-88	calibration for SIN min, add by dino, 06/01/2007
#define	COSMAX			(GROUP15+89)	//	89	15-89	calibration for COS max, add by dino, 06/01/2007
#define	COSMIN			(GROUP15+90)	//	90	15-90	calibration for COS min, add by dino, 06/01/2007
#define	MINI_PULSE		(GROUP15+91)	//	91	15-91	minimum pulse, ADDED BY SCOTTY,2007/07/11
#define	FAN_Dframe		(GROUP15+92)	//  92	15-92	D frame FAN Control
#define Z_SECT			(GROUP15+93)	//  93  15-93	Z phase UVW Section when PG_TYPE = 2, add by dino, 10/29/2007
#define RESEVER  		(GROUP15+94)	//      15-94	RESEVER
#define PG_POSatLV		(GROUP15+95)	//	95 	15-95	PG Position Record, add by scotty, 12/07/2007
#define DAMAX			(GROUP15+96)	//	96 	15-96	AFM max. value
#define DAMIN			(GROUP15+97)	//	97 	15-97	AFM min. value
#define	RLY_TIME		(GROUP15+98)	//	98	15-98	Softstart Delay Time
#define DEBUG_F2  		(GROUP15+99)	//      15-99	Debug Flag 2    //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
#define	ZCAB_MODE		(GROUP15+100)	//	100	15-100	//[Z-calibration compensation speed,Jerry Yu,2019/06/05] 
#define	Qer_min			(GROUP15+101)	//	101	15-101  Qer_min  //[Current Low Frequency Ripple,JerrySK,2019/09/05]
#define	Qer_Shift		(GROUP15+102)	//	102	15-102  Qer_Shift  //[Current Low Frequency Ripple,JerrySK,2019/09/05]
#define Sin_HS_Tab		(GROUP15+103)	//	103	15-103  Sin_HS_Tab //[Sin Table extend,Jason,2019/09/02]
#define PSW_2006H		(GROUP15+105)	//  105 15-105  User Password, Write form 2006H, Read from 21FFH, DINO, 12/23/2009
#define CAN_CTRL		(GROUP15+106)	//  106 15-106  Can Control       //[CAN Control, Sampo, 09/15/2010]
#define CAN_FAULT		(GROUP15+107)	//  106 15-107  Can Fault handle  //[CAN Control, Sampo, 09/15/2010]
#define DEBUG_PG		(GROUP15+108)
#define _47th_DISP		(GROUP15+109)
#define PG_MODE		    (GROUP15+110)
#define	WDT_DIV			(GROUP15+111)	//  109 15-111  WDT Divider Value     //[ICT WDT test, Bernie, 08/16/2011]
#define AFM1_P10CNT     (GROUP15+112)   //  110 15-112  AFM1_P10CNT for AFM1 +10V output
#define AFM1_0CNT       (GROUP15+113)   //  111 15-113  AFM1_0CNT for AFM1 0V output
#define AFM1_M10CNT     (GROUP15+114)   //  110 15-114  AFM1_M10CNT for AFM1 -10V output
#define AFM2_P10CNT     (GROUP15+115)   //  110 15-115  AFM2_P10CNT for AFM2 +10V output
#define AFM2_0CNT       (GROUP15+116)   //  110 15-116  AFM2_0CNT for AFM2 0V output
#define AFM2_M10CNT     (GROUP15+117)   //  110 15-117  AFM2_M10CNT for AFM2 -10V output
#define PROTECT_BIT     (GROUP15+118)   //  XXX 15-118  The switch of Protect finction    //[The switch of Protect finction, Bernie, 2015/05/21]
#define OPH2_CNT        (GROUP15+119)   //  XXX 15-119  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_IRMS       (GROUP15+120)   //  XXX 15-120  The IRMS value of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_GAIN       (GROUP15+121)   //  XXX 15-121  The Gain value of Protect finction     //[Output Phase Loss 2, Sampo, 2015/05/21]
#define PPI_C   		(GROUP15+122)	//	122 15-122  Test parameter, add by dino, 02/20/2008
#define MBF_ERR_REC     (GROUP15+123)   //  1XX 12-123  MBF record after power down         //[MBF can be recorded after power down, Bernie, 2016/02/19]
#define	EOL_RECODHI     (GROUP15+124)   //  [add for UL EoL Verification,Bernie, 2013/04/22]
#define	EOL_RECODLO     (GROUP15+125)   //  [add for UL EoL Verification,Bernie, 2013/04/22]
#define	Par126  		(GROUP15+126)	//	126 15-126	Test parameter, add by dino, 02/20/2008
#define Unavaliable		(GROUP15+127)	//	126 15-127	Test parameter, add by dino, 02/20/2008
/*------------	Group0	 --------*/
#define	GROUP0			(GROUP15+128)
#define	HPSPEC			(GROUP0+0)      //  128 00-00   Model Type of Drive
#define	I_RATE2		    (GROUP0+1)      //  129	00-01   Rated Current
#define	PRRESET			(GROUP0+2)      //  130	00-02   Parameter Reset
#define	S_DISP			(GROUP0+3)      //  131	00-03   Start up Display
#define	U_DISP			(GROUP0+4)      //  132	00-04   User Display
#define	U_SET			(GROUP0+5)      //  133	00-05   User Coefficient
#define	SW_VER			(GROUP0+6)      //  134	00-06   Software Version
#define	PSW_IN			(GROUP0+7)      //  135	00-07   Password Input
#define	PSW_SET			(GROUP0+8)      //  136	00-08   Password Input
#define	CTRLM			(GROUP0+9)      //  137	00-09   Control Methods
#define UNITSEL			(GROUP0+10)	    //  138	00-10   Velocity Unit Select, Add by DINO, 05/25/2009
#define CHG_DIR		    (GROUP0+11)	    //  139	00-11   Change Output Direction, Added by sampo , 06/11/2009
#define	SETCRF			(GROUP0+12)	    //  140	00-12   Carry Frequency
#define	AVR			    (GROUP0+13)	    //  141	00-13   AVR
#define	SOFC			(GROUP0+14)	    //  142	00-14   Source of Freq. Command
#define	SOOC			(GROUP0+15)	    //  143	00-15   Source of Oper. Command
/*------------	Group1	 --------*/
#define	GROUP1			(GROUP0+16)
#define	FMAX			(GROUP1+0)      //  144	01-00   Max Output Freq.
#define	MFBASE1			(GROUP1+1)      //  145	01-01   Motor Base Frequency 1
#define	VMAX1			(GROUP1+2)      //  146	01-02   Max Output Voltage
#define	FMID1_1			(GROUP1+3)      //  147	01-03   Mid Output Freq.1
#define	VMID1_1			(GROUP1+4)      //  148	01-04   Mid Output Voltage 1
#define	FMID1_2			(GROUP1+5)      //  149	01-05   Mid Output Freq.2
#define	VMID1_2			(GROUP1+6)      //  150	01-06   Mid Output Voltage 2
#define	FMIN1			(GROUP1+7)      //  151	01-07   Min Output Freq.
#define	VMIN1			(GROUP1+8)      //  152	01-08   Min Output Voltage
#define	FSTART			(GROUP1+9)      //  153	01-09   Start Frequency
#define	FUPPER			(GROUP1+10)	    //  154	01-10   Upper Bound Freq.
#define	FLOWER			(GROUP1+11)	    //  155	01-11   Lower Bound Freq.
#define	ACCEL1			(GROUP1+12)	    //  156	01-12   1st Acceleration time
#define	DECEL1			(GROUP1+13)	    //  157	01-13   1st Deceleration time
#define	ACCEL2			(GROUP1+14)	    //  158	01-14   2nd Acceleration time
#define	DECEL2			(GROUP1+15)	    //  159	01-15   2nd Deceleration time
#define	ACCEL3			(GROUP1+16)	    //  160	01-16   3rd Acceleration time
#define	DECEL3			(GROUP1+17)	    //  161	01-17   3rd Deceleration time
#define	ACCEL4			(GROUP1+18)	    //  162	01-18   4th Acceleration time
#define	DECEL4			(GROUP1+19)	    //  163	01-19   4th Deceleration time
#define	JOGACC			(GROUP1+20)	    //  164	01-20   JOG Acceleration time	
#define	JOGDEC			(GROUP1+21)	    //  165	01-21   JOG Deceleration time	
#define	JOGF			(GROUP1+22)	    //  166	01-22   JOG Frequency	
#define	FAD1_AD4		(GROUP1+23)	    //  167	01-23   Transition Frequency ACC1/DEC1 to ACC4/DEC4	
#define	S4ACC1			(GROUP1+24)	    //  168	01-24   S curve Accel time 1	
#define	S4ACC2			(GROUP1+25)	    //  169	01-25   S curve Accel time 2	
#define	S4DEC1			(GROUP1+26)	    //  170	01-26   S curve Decel time 1	
#define	S4DEC2			(GROUP1+27)	    //  171	01-27   S curve Decel time 2
#define SL_ZSP			(GROUP1+28)     //  172	01-28   Select Zero Speed		
#define	FLAND			(GROUP1+29)	    //  173	01-29   Landing Frequency
#define	S4DEC3			(GROUP1+30)	    //  174	01-30   S curve Decel time 3
#define	DECEL5			(GROUP1+31)	    //  175	01-31   Stop Deceleration time
#define	FSD			    (GROUP1+32)	    //  175	01-32   FSD
#define	IODHT		    (GROUP1+33)	    //  175	01-33   IODHT IO direct hold time
#define	IODLT           (GROUP1+34)	    //  175	01-34   IODLT IO direct landing freq
#define	CRPLS_Jlim		(GROUP1+35)	    //  175	01-35   IODLT IO direct landing time
#define	IODDE		    (GROUP1+36)	    //  175	01-36   IODLT IO direct DistancE
#define	IODDER		    (GROUP1+37)	    //  175	01-36   IODLT IO direct DistancE
#define	IODEN		    (GROUP1+38)	    //  175	01-36   IODLT IO direct DistancE
#define	FETS    		(GROUP1+39)	    //  175	01-31   Stop Deceleration time
#define	DECEL_ESD       (GROUP1+40)	    //  175	01-31   Stop Deceleration time
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
#define	SIBO_DECEMY  	(GROUP1+41)		//	286	03-85
#define	SIBO_S3EMY 		(GROUP1+42)		//	289	03-88
#define	SIBO_S4EMY 		(GROUP1+43)		//	290	03-89
/*------------	Group2	 --------*/	
#define	GROUP2			(GROUP1+44)	


#else				
#define	GROUP2			(GROUP1+41)	
#endif			
#define	WIRE2_3			(GROUP2+0)	    //	176	02-00	2/3 wire control
#define	MI1			    (GROUP2+1)	    //	177	02-01	Multi-Function Input 1
#define	MI2			    (GROUP2+2)	    //	178	02-02	Multi-Function Input 2
#define	MI3			    (GROUP2+3)	    //	179	02-03	Multi-Function Input 3
#define	MI4			    (GROUP2+4)	    //	180	02-04	Multi-Function Input 4
#define	MI5			    (GROUP2+5)	    //	181	02-05	Multi-Function Input 5
#define	MI6			    (GROUP2+6)	    //	182	02-06	Multi-Function Input 6
#define	MI7			    (GROUP2+7)	    //	183	02-07	Multi-Function Input 7
#define	MI8			    (GROUP2+8)	    //	184	02-08	Multi-Function Input 8		
#define	DIN_RES			(GROUP2+9)	    //	185	02-09	Digital in response time		
#define	MI_INV			(GROUP2+10)		//	186	02-10	Multi-Function Input Inverse		
#define	RLY1			(GROUP2+11)		//	187	02-11	Multi-Function Relay 1		
#define	RLY2			(GROUP2+12)		//	188	02-12	Multi-Function Relay 2		
#define	MO1			    (GROUP2+13)		//	189	02-13	Multi-Function Output 1		
#define	MO2			    (GROUP2+14)		//	190	02-14	Multi-Function Output 2		
#define	MO3			    (GROUP2+15)		//	191	02-15	Multi-Function Output 1		
#define	MO4			    (GROUP2+16)		//	192	02-16	Multi-Function Output 2		
#define	MO5			    (GROUP2+17)		//	193	02-17	Multi-Function Output 1		
#define	MO6			    (GROUP2+18)		//	194	02-18	Multi-Function Output 2		
#define	MO7			    (GROUP2+19)		//	195	02-19	Multi-Function Output 1		
#define	MO8			    (GROUP2+20)		//	196	02-20	Multi-Function Output 2		
#define	MO9			    (GROUP2+21)		//	197	02-21	Multi-Function Output 1		
#define	MO10		    (GROUP2+22)		//	198	02-22	Multi-Function Output 2		
#define	MO_INV			(GROUP2+23)		//	199	02-23   Multi-Function Output inverse
#define SEQMOD			(GROUP2+24)     // 	200 02-24   Sequence start mode
#define	DESIRE_F1		(GROUP2+25)		//	201	02-25	Desired Frequency 1		
#define	DESIRE_F1B		(GROUP2+26)		//	202	02-26	Band of Desired Frequency 1		
#define	DESIRE_F2		(GROUP2+27)		//	203	02-27	Desired Frequency 2		
#define	DESIRE_F2B		(GROUP2+28)		//	204	02-28	Band of Desired Frequency 2		
#define	BRK_RUNDT		(GROUP2+29)		//	205	02-29	Brake Delay Timer Run
#define	BRK_STOPDT		(GROUP2+30)		//	206	02-30	Brake Delay Timer Stop
#define	MCDELAY_RUN		(GROUP2+31)		//	207 02-31	Mech Contact delay time at run
#define	MCDELAY_STOP	(GROUP2+32)		//	208	02-32	Mech Contact delay time at stop	
#define	IS_DETECT		(GROUP2+33)		//	209	02-33	Isum Current Output Detect	
#define	SP_AREA			(GROUP2+34)		//	210	02-34	Speed Area	
#define BRK_CHKTIME		(GROUP2+35)		//  211 02-35	Mechanical Brake Checking Time
#define MC_CHKTIME		(GROUP2+36)		//  212 02-36	Magnetic Contactor Checking Time
#define BRK_CHKTQR		(GROUP2+37)		//	213 02-37   Mechanical Brake Checking Current Enable
#define SCDELAY_RUN     (GROUP2+38)	    //  214 02-38   Star Contactor delay time when driver run    //[Star contactor function, Bernie, 2017/03/22]
#define SCDELAY_STOP    (GROUP2+39)	    //  215 02-39   Star Contactor delay time when driver stop  //[Star contactor function, Bernie, 2017/03/22]
#define LS_Method       (GROUP2+40)	    //  216 02-40   //#15977, LULD detect, James, 2021/04/01
#define LS_OPEN_TIME    (GROUP2+41)	    //  217 02-41   //#15977, LULD detect, James, 2021/04/01
#define LS_SHORT_TIME   (GROUP2+42)	    //  217 02-42   //#15977, LULD detect, James, 2021/04/01
#define	SpdAgree_B      (GROUP2+43)	    //  202 02-43   //#18572, Band of Speed Agree Function 	
#define	STO_SHORT_T     (GROUP2+44)	    //  218 02-44 STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
#define Sensor819       (GROUP2+45)		//  2xx 02-45	//[Artemis Add Sensor819 Function/Special/2022/06/06]
#define Speed_Limit     (GROUP2+46)		//  2xx 02-46	//[Artemis Add Sensor819 Function/Special/2022/06/06]



/*------------	Group3	 --------*/
#define	GROUP3			(GROUP2+47)
#define AUI1_SL			(GROUP3+0)	    //	214	03-00	AVI selection	
#define ACI_SL 			(GROUP3+1)	    //	215	03-01	ACI selection	
#define AUI2_SL			(GROUP3+2)	    //	216	03-02	AUI selection	
#define	AUI1BIAS		(GROUP3+3)	    //	217	03-03	AVI input Bias	
#define	ACIBIAS			(GROUP3+4)	    //	218	03-04	ACI input Bias	
#define	AUI2BIAS		(GROUP3+5)	    //	219	03-05	AUI input Bias	
#define	AUI1_PN			(GROUP3+6)	    //	220 03-06	AVI input Polarity	
#define	ACI_PN			(GROUP3+7)	    //	221 03-07	ACI input Polarity	
#define	AUI2_PN			(GROUP3+8)	    //	222 03-08	AUI input Polarity	
#define	AUI1GA			(GROUP3+9)	    //	223 03-09	AVI input Gain	
#define	ACIGA			(GROUP3+10)		//	224 03-10	ACI input Gain	
#define	AUI2GA			(GROUP3+11)		//	225 03-11	AUI input Gain	
#define	AUI1_LPG		(GROUP3+12)		//	226 03-12	Low pass filter of Analong input	
#define	ACI_LPG			(GROUP3+13)		//	227 03-13	Low pass filter of Analong input	
#define	AUI2_LPG		(GROUP3+14)		//	228 03-14	Low pass filter of Analong input	
#define	LOCELTUN		(GROUP3+15)		//	229 03-15	Loss of ACI	
#define AFMCALIB		(GROUP3+16)     // 	230 03-16	Analog output calibration Flag	
#define	AFM1		    (GROUP3+17)		//	231 03-17	Analong Output 1	
#define	AFMGA1			(GROUP3+18)		//	232 03-18	Analong Output 1 Gain
#define	AFM1_MINUS		(GROUP3+19)		//	233 03-19	AO1 in minus value
#define	AFM2		    (GROUP3+20)		//	234 03-20	Analong Output 1	
#define	AFMGA2			(GROUP3+21)		//	235 03-21	Analong Output 1 Gain
#define	AFM2_MINUS		(GROUP3+22)		//	236 03-22	AO1 in minus value
#define AUI1_POLAR		(GROUP3+23)		//  237 03-23	AUI1 Input Polar
#define AUI2_POLAR		(GROUP3+24)		//  238 03-24	AUI2 Input Polar
//#define AUI1_COMMUN     (GROUP3+25)     //	23X 03-25 AUI1 Communciate   //[DLC, Bernie, 2014/10/06]
//#define AUI2_COMMUN     (GROUP3+26)     //	23X 03-26 AUI2 Communciate

/*------------	Group4	 --------*/
#define	GROUP4			(GROUP3+25)
#define	FMI0			(GROUP4+0)	    //  239	04-00	Multi-Speed 0
#define	FMI1			(GROUP4+1)	    //  240	04-01	Multi-Speed 1	
#define	FMI2			(GROUP4+2)	    //  241	04-02	Multi-Speed 2	
#define	FMI3			(GROUP4+3)	    //  242	04-03	Multi-Speed 3	
#define	FMI4			(GROUP4+4)	    //  243 04-04	Multi-Speed 4	
#define	FMI5			(GROUP4+5)	    //  244 04-05	Multi-Speed 5	
#define	FMI6			(GROUP4+6)	    //  245 04-06	Multi-Speed 6	
#define	FMI7			(GROUP4+7)	    //  246 04-07	Multi-Speed 7	
#define	FMI8			(GROUP4+8)	    //  247 04-08	Multi-Speed 8	
#define	FMI9			(GROUP4+9)	    //  248 04-09	Multi-Speed 9	
#define	FMI10			(GROUP4+10)     //  249 04-10	Multi-Speed 10  	
#define	FMI11			(GROUP4+11)     //  250 04-11	Multi-Speed 11  	
#define	FMI12			(GROUP4+12)     //  251 04-12	Multi-Speed 12  
#define	FMI13			(GROUP4+13)     //  252 04-13	Multi-Speed 13  
#define	FMI14			(GROUP4+14)     //  253 04-14	Multi-Speed 14  
#define	FMI15			(GROUP4+15)     //  254 04-15	Multi-Speed 15

#define RSQ_SPD         (GROUP4+16)		//  2XX 04-16 Rescue Speed 
#define LEV_SPD         (GROUP4+17)		//  2XX 04-17 Re-Leveling Speed
#define AH_SPD          (GROUP4+18)
#define ROPE_CMP   		(GROUP4+19)     //  2XX 04-19 GFC Rope compensation, 2021/03/30
#define TABST0_STATUS   (GROUP4+20)     //  2XX 04-20 Leveling Plank Length
#define TABST1_STATUS   (GROUP4+21)     //  2XX 04-21 Maximum Floor
#define MAX_FLOOR       (GROUP4+22)
#define LEV_CUR  	    (GROUP4+23)
#define	PG_RST_MODE     (GROUP4+24)
#define	DelayCmp        (GROUP4+25)
#define LAND_DLY_TIME   (GROUP4+26)
#define LEV_LEN         (GROUP4+27)
#define INV_POS_H       (GROUP4+28)
#define INV_POS_L       (GROUP4+29)
#define CUR_PG_H        (GROUP4+30)
#define CUR_PG_L        (GROUP4+31)
#define LEV_BRD_PG_H    (GROUP4+32)
#define LEV_BRD_PG_L    (GROUP4+33)
#define SENSOR_H        (GROUP4+34)
#define SENSOR_L        (GROUP4+35)
#define DLC_FUN         (GROUP4+36)
#define PDO_TYPE        (GROUP4+37)
#define DS_LEN          (GROUP4+38)
#define RATIO           (GROUP4+39)     //[ADCO EPS Modify]
#define DisDly          (GROUP4+40)//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13 
#define EST_STATUS      (GROUP4+41)
#define EST_COUNT       (GROUP4+42)
#define TABST0_COUNT    (GROUP4+43)
#define TABST1_COUNT    (GROUP4+44)
#define DD1_Vlim        (GROUP4+45)     //Artemis speed limit, James, 20200220
#define DD2_Vlim        (GROUP4+46)     //Artemis speed limit, James, 20200220
#define DD3_Vlim        (GROUP4+47)     //Artemis speed limit, James, 20200220
#define DD4_Vlim        (GROUP4+48)     //Artemis speed limit, James, 20200220

#define FLOOR_PAGE      (GROUP4+49)     //  2XX 04-49 Floor information for DLC function 

#define FL_POSIT_1H     (GROUP4+50)     //  2XX 04-50 1Floor Position H 
#define FL_POSIT_1L     (GROUP4+51)     //  2XX 04-51 1Floor Position L 
#define FL_POSIT_2H     (GROUP4+52)     //  2XX 04-52 2Floor Position H 
#define FL_POSIT_2L     (GROUP4+53)     //  2XX 04-53 2Floor Position L 
#define FL_POSIT_3H     (GROUP4+54)     //  2XX 04-54 3Floor Position H 
#define FL_POSIT_3L     (GROUP4+55)     //  2XX 04-55 3Floor Position L 
#define FL_POSIT_4H     (GROUP4+56)     //  2XX 04-56 4Floor Position H 
#define FL_POSIT_4L     (GROUP4+57)     //  2XX 04-57 4Floor Position L 
#define FL_POSIT_5H     (GROUP4+58)     //  2XX 04-58 5Floor Position H 
#define FL_POSIT_5L     (GROUP4+59)     //  2XX 04-59 5Floor Position L 
#define FL_POSIT_6H     (GROUP4+60)     //  2XX 04-60 6Floor Position H 
#define FL_POSIT_6L     (GROUP4+61)     //  2XX 04-61 6Floor Position L 
#define FL_POSIT_7H     (GROUP4+62)     //  2XX 04-62 7Floor Position H 
#define FL_POSIT_7L     (GROUP4+63)     //  2XX 04-63 7Floor Position L 
#define FL_POSIT_8H     (GROUP4+64)     //  2XX 04-64 8Floor Position H 
#define FL_POSIT_8L     (GROUP4+65)     //  2XX 04-65 8Floor Position L 
#define FL_POSIT_9H     (GROUP4+66)     //  2XX 04-66 9Floor Position H 
#define FL_POSIT_9L     (GROUP4+67)     //  2XX 04-67 9Floor Position L 
#define FL_POSIT_10H    (GROUP4+68)     //  2XX 04-68 10Floor Position H
#define FL_POSIT_10L    (GROUP4+69)     //  2XX 04-69 10Floor Position L
#define FL_POSIT_11H    (GROUP4+70)     //  2XX 04-70 11Floor Position H
#define FL_POSIT_11L    (GROUP4+71)     //  2XX 04-71 11Floor Position L
#define FL_POSIT_12H    (GROUP4+72)     //  2XX 04-72 12Floor Position H
#define FL_POSIT_12L    (GROUP4+73)     //  2XX 04-73 12Floor Position L
#define FL_POSIT_13H    (GROUP4+74)     //  2XX 04-74 13Floor Position H
#define FL_POSIT_13L    (GROUP4+75)     //  2XX 04-75 13Floor Position L
#define FL_POSIT_14H    (GROUP4+76)     //  2XX 04-76 14Floor Position H
#define FL_POSIT_14L    (GROUP4+77)     //  2XX 04-77 14Floor Position L
#define FL_POSIT_15H    (GROUP4+78)     //  2XX 04-78 15Floor Position H
#define FL_POSIT_15L    (GROUP4+79)     //  2XX 04-79 15Floor Position L
#define FL_POSIT_16H    (GROUP4+80)     //  2XX 04-80 16Floor Position H
#define FL_POSIT_16L    (GROUP4+81)     //  2XX 04-81 16Floor Position L
#define FL_POSIT_17H    (GROUP4+82)     //  2XX 04-82 17Floor Position H
#define FL_POSIT_17L    (GROUP4+83)     //  2XX 04-83 17Floor Position L
#define FL_POSIT_18H    (GROUP4+84)     //  2XX 04-84 18Floor Position H
#define FL_POSIT_18L    (GROUP4+85)     //  2XX 04-85 18Floor Position L
#define FL_POSIT_19H    (GROUP4+86)     //  2XX 04-86 19Floor Position H
#define FL_POSIT_19L    (GROUP4+87)     //  2XX 04-87 19Floor Position L
#define FL_POSIT_20H    (GROUP4+88)     //  2XX 04-88 20Floor Position H
#define FL_POSIT_20L    (GROUP4+89)     //  2XX 04-89 20Floor Position L
#define FL_POSIT_21H    (GROUP4+90)     //  2XX 04-90 21Floor Position H
#define FL_POSIT_21L    (GROUP4+91)     //  2XX 04-91 21Floor Position L
#define FL_POSIT_22H    (GROUP4+92)     //  2XX 04-92 22Floor Position H
#define FL_POSIT_22L    (GROUP4+93)     //  2XX 04-93 22Floor Position L
#define FL_POSIT_23H    (GROUP4+94)     //  2XX 04-94 23Floor Position H
#define FL_POSIT_23L    (GROUP4+95)     //  2XX 04-95 23Floor Position L
#define FL_POSIT_24H    (GROUP4+96)     //  2XX 04-96 24Floor Position H
#define FL_POSIT_24L    (GROUP4+97)     //  2XX 04-97 24Floor Position L
#define FL_POSIT_25H    (GROUP4+98)     //  2XX 04-98 25Floor Position H
#define FL_POSIT_25L    (GROUP4+99)     //  2XX 04-99 25Floor Position L

/*------------	Grop5	 --------*/					
#define	GROUP5          (GROUP4+100)				
#define	AUTO_T			(GROUP5+0)      //	255	05-00	Motor Auto-Tuning
#define	MI_RAT1			(GROUP5+1)	    //	256	05-01	Motor 1 rated Current
#define	P_RATED1		(GROUP5+2)	    //	257	05-02	Motor 1 Rated Power
#define	RPM_RATED1		(GROUP5+3)	    //	258	05-03	Motor 1 Rated RPM
#define	POLES1			(GROUP5+4)	    //	259	05-04	Motor 1 pole No.
#define	MI_NL1			(GROUP5+5)	    //	260	05-05	Motor 1 No-Load Current
#define	Rs1			    (GROUP5+6)	    //	261	05-06	Motor 1 Rs
#define	Rr1			    (GROUP5+7)	    //	262	05-07	Motor 1 Rr
#define	Lm1			    (GROUP5+8)	    //	263	05-08	Motor 1 Lm
#define	Lx1			    (GROUP5+9)	    //	264	05-09	Motor 1 Lx
#define	SVC_VLPG		(GROUP5+10)		//	265	05-10	Vector Voltage Filter	
#define	SVC_SLPG		(GROUP5+11)		//	266	05-11	Vector Slip Filter	
#define	TQRC_G			(GROUP5+12)		//	267	05-12	Torque Compensation Gain	
#define	SLIPC			(GROUP5+13)		//	268	05-13	Slip Compensation Gain	  //[slip compensation function, Bernie, 2012/06/20]
#define	SLIPDEVL		(GROUP5+14)		//	269	05-14	Slip Deviation level	
#define	SLIPDEVT		(GROUP5+15)		//	270	05-15	Slip Deviation Detect Time	
#define	OSLIPWAY		(GROUP5+16)		//	271	05-16	Over Slip treatment	
#define	K_HUNT			(GROUP5+17)		//	272	05-17	Coeff for hunting disable	
#define	RUNMIN			(GROUP5+18)		//	273	05-18	Accumulative Motor Operation Min	
#define	RUNDAY			(GROUP5+19)		//	274	05-19	Accumulative Motor Operation Day	
#define	CORELOSS		(GROUP5+20)		//	275	05-20	Coreloss % of output Power	
#define	PWR_MIN			(GROUP5+21)		//	276 05-21  	Power On Min
#define	PWR_DAY			(GROUP5+22)		//	277	05-22	Power On Day
#define GENSL_G         (GROUP5+23)     //  2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
#define SLIPC_G         (GROUP5+24)     //  2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
/*------------	Group6	 --------*/						
#define	GROUP6			(GROUP5+25)
#define	LVL			    (GROUP6+0)	    //	278	06-00	Low voltage level	
#define	PHL				(GROUP6+1)	    //	279	06-01	Phase loss	
#define	OCA			    (GROUP6+2)	    //	280	06-02	OC stall during Accel	
#define	OCN			    (GROUP6+3)	    //	281	06-03	OC stall during Decel	
#define	STALLSPD		(GROUP6+4)	    //	282	06-04	Stall preventation Accel/Decel time selection	
#define	OTDM			(GROUP6+5)	    //	283	06-05	Over-Torque 1 Selection	
#define	OTDL			(GROUP6+6)	    //	284	06-06	Over-Torque 1 level	
#define	OTDT			(GROUP6+7)	    //	285	06-07	Over-Torque 1 Time	
#define	OTDM2			(GROUP6+8)	    //	286	06-08	Over-Torque 2 Selection	
#define	OTDL2			(GROUP6+9)	    //	287	06-09	Over-Torque 2 level	
#define	OTDT2			(GROUP6+10)		//	288	06-10	Over-Torque 2 Time	
#define	CURRENT_LIM		(GROUP6+11)		//	289	06-11	Current Limit	
#define	EOL1_SL			(GROUP6+12)		//	290	06-12	Thermal Relay 1 Selection	
#define	EOL1_T			(GROUP6+13)		//	291	06-13	Thermal Relay 1 Time	
#define	OHWL			(GROUP6+14)		//	292	06-14	OH Warning Level	
#define	STALLIMIT		(GROUP6+15)		//	293	06-15	Stall preventation Limit Level	
#define	ERR_REC1		(GROUP6+16)		//	294	06-16	1st Fault Record	
#define	ERR_REC2		(GROUP6+17)		//	295	06-17	2nd Fault Record	
#define	ERR_REC3		(GROUP6+18)		//	296	06-18	3rd Fault Record	
#define	ERR_REC4		(GROUP6+19)		//	297	06-19	4th Fault Record	
#define	ERR_REC5		(GROUP6+20)		//	298	06-20	5th Fault Record	
#define	ERR_REC6		(GROUP6+21)		//	299	06-21	6th Fault Record	
#define	ERR_OPT1		(GROUP6+22)		//	300	06-22	Fault Option 1	
#define	ERR_OPT2		(GROUP6+23)		//	301 06-23	Fault Option 2	
#define	ERR_OPT3		(GROUP6+24)		//	302	06-24	Fault Option 3	
#define	ERR_OPT4		(GROUP6+25)		//	303	06-25	Fault Option 4	
#define	PTC_TREAM		(GROUP6+26)		//	304	06-26	PTC over Treatments	
#define	PTC_LEVEL		(GROUP6+27)		//	305	06-27	PTC Level	
#define	PTC_DFT  		(GROUP6+28)		//	306	06-28	PTC Detect Filter time	
#define	VEPS     		(GROUP6+29)		//	307	06-29	EPS voltage level, add by dino, 2008/02/15
#define	ERR_OPTM 		(GROUP6+30)		//	308	06-30	Fault Option Mode, add by dino, 2008/02/15
#define MPHLM			(GROUP6+31)		//	309	06-31	Motor Phase Detection Mode, Add by DINO, 05/12/2009
#define ERR_MIN1		(GROUP6+32)		//	310 06-32	1st Fault Time(MIN)
#define ERR_DAY1        (GROUP6+33)     //	311 06-33	1st Fault Time(DAY)
#define ERR_MIN2        (GROUP6+34)     //	312 06-34	2nd Fault Time(MIN)
#define ERR_DAY2        (GROUP6+35)     //	313 06-35	2nd Fault Time(DAY)
#define ERR_MIN3        (GROUP6+36)     //	314 06-36	3rd Fault Time(MIN)
#define ERR_DAY3        (GROUP6+37)     //	315 06-37	3rd Fault Time(DAY)
#define ERR_MIN4        (GROUP6+38)     //	316 06-38	4th Fault Time(MIN)
#define ERR_DAY4        (GROUP6+39)     //	317 06-39	4th Fault Time(DAY)
#define ERR_MIN5        (GROUP6+40)     //	318 06-40	5th Fault Time(MIN)
#define ERR_DAY5        (GROUP6+41)     //	319 06-41	5th Fault Time(DAY)
#define ERR_MIN6        (GROUP6+42)     //	320 06-42	6th Fault Time(MIN)
#define ERR_DAY6        (GROUP6+43)     //	321 06-43	6th Fault Time(DAY)
#define FEPS            (GROUP6+44)     //	322 06-44	EPS Frequency, add by DINO, 06/24/2009
#define LV_OPTM			(GROUP6+45)		//  323 06-45   LV Option Mode, Add by DINO, 11/30/2009
#define EPS_OPTM		(GROUP6+46)		//  324 06-46   EPS Operation Mode
#define GEN_T			(GROUP6+47)		//  325 06-47   Generation Operation Detected Time
#define UPS_CAP			(GROUP6+48)		//  326 06-48   UPS Capacity (0.1KVA)
#define STO_LOCK        (GROUP6+49)		//  326 06-49   STO Lock selection    //[Safty function, Bernie]
#define RESET_SLT       (GROUP6+50)     //  3xx 06-50   Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
#define RESETCNT        (GROUP6+51)     //  3xx 06-51   Auto restart times after fault
#define RESETINTERVAL   (GROUP6+52)     //  3xx 06-52   Auto restart interval
#define	FKEY_REC		(GROUP6+53)	    //	99	15-99	Fkey Record
#define	FOUT_REC        (GROUP6+54)	    //  94  15-94   Fcmd Record, add by dino, 10/31/2007
#define	ISUM_REC        (GROUP6+55)	    //  82  15-82   Isum Record
#define	FFBK_REC        (GROUP6+56)	    //	79	15-79	Fout Record
#define	VOUT_REC        (GROUP6+57)	    //	80	15-80	Vout Record
#define	DCBUS_REC       (GROUP6+58)  	//	81	15-81	Dcbus Record
#define POWER_REC       (GROUP6+59)     //  100 15-100	Power Record
#define TQ_REC          (GROUP6+60)     //  101 15-101	Torque Record
#define	TH_TEMP         (GROUP6+61)	    //	83	15-83	IGBT Temperature Record
#define MFI_REC         (GROUP6+62)     //	102	15-102	MFI State Record
#define MFO_REC         (GROUP6+63)     //	103	15-103	MFO State Record
#define STATE_REC       (GROUP6+64)     //	104	15-104	Drive State Record
#define CUR_LIM_UCMP    (GROUP6+65)     //  3XX 06-65  Current limitation for UCMP function  //[UCMP function, Bernie, 2016/06/14]
#define SERVICE_COUNT   (GROUP6+66)     //  3xx 06-66   Service time count                       //[Service time function, Bernie, 2017/03/14]
#define SERVICE_ENABLE  (GROUP6+67)     //  3XX 06-67   Service time function Enable
#define	EPS_PF	        (GROUP6+68)	    //	EPS Detect Current    
#define	EPS_PFREF	    (GROUP6+69)	    //	EPS Detect Current Ref
#define	EPS_DIR	        (GROUP6+70)	    //	EPS Detect direction
#define	EPS_MO_DELAY    (GROUP6+71)	    //	EPS MO Off Time
#define	EPS_MO_OFF	    (GROUP6+72)    	//	EPS MO Off Time
#define	IR_COUNT_H      (GROUP6+73)	    //	Running direction count high
#define	IR_COUNT_L      (GROUP6+74)	    //	Running direction count low
#define	IR_TCOUNT_H	    (GROUP6+75)    	//	Temp running direction count high
#define	IR_TCOUNT_L     (GROUP6+76)	    //	Temp running direction count low
#define	IR_RESTEC       (GROUP6+77)	    //	Temp running reset count 
#define	IR_LIFE  	    (GROUP6+78)    	//  Running life 
#define	IR_ENABLE	    (GROUP6+79)		//  Running function
#define	FOUT_REC1	    (GROUP6+80)		//  increase FOUT error record1
#define	DCBUS_REC1	    (GROUP6+81)		//  increase DCBUS error record1
#define	ISUM_REC1	    (GROUP6+82)		//  increase ISUM error record1
#define	TH_TEMP1	    (GROUP6+83)		//  increase TH_TEMP error record1
#define	FOUT_REC2	    (GROUP6+84)		//  increase FOUT error record2
#define	DCBUS_REC2	    (GROUP6+85)		//  increase DCBUS error record2
#define	ISUM_REC2	    (GROUP6+86)		//  increase ISUM error record2
#define	TH_TEMP2	    (GROUP6+87)		//  increase TH_TEMP error record2
#define	FOUT_REC3	    (GROUP6+88)		//  increase FOUT error record3
#define	DCBUS_REC3	    (GROUP6+89)		//  increase DCBUS error record3
#define	ISUM_REC3	    (GROUP6+90)		//  increase ISUM error record3
#define	TH_TEMP3	    (GROUP6+91)		//  increase TH_TEMP error record3
#define	FOUT_REC4	    (GROUP6+92)		//  increase FOUT error record4
#define	DCBUS_REC4	    (GROUP6+93)		//  increase DCBUS error record4
#define	ISUM_REC4	    (GROUP6+94)		//  increase ISUM error record4
#define	TH_TEMP4	    (GROUP6+95)		//  increase TH_TEMP error record4
#define	FOUT_REC5	    (GROUP6+96)		//  increase FOUT error record5
#define	DCBUS_REC5	    (GROUP6+97)		//  increase DCBUS error record5
#define	ISUM_REC5	    (GROUP6+98)		//  increase ISUM error record5
#define	TH_TEMP5	    (GROUP6+99)		//  increase TH_TEMP error record5
/*------------	Group7	 --------*/						
#define	GROUP7			(GROUP6+100)
#define	DCBRK4V			(GROUP7+0)      //  327  07-00    SW Braking Level	
#define DCBRK_BAND		(GROUP7+1)      //  328  07-01    DB Enable Duty, add by dino 2007/02/12
#define	DCICL			(GROUP7+2)      //  329  07-01    DCI Current Level	
#define	DCISTA			(GROUP7+3)      //  330  07-02    DCI Time at Start 	
#define	DCISTP			(GROUP7+4)      //  331  07-03    DCI Time at STOP	
#define	DCIFSTA			(GROUP7+5)      //  332  07-04    DCI Freq. At start	
#define	DCI_KI			(GROUP7+6)      //  333  07-05    DCI KI	
#define	GEAR_ACCT		(GROUP7+7)      //  334  07-07    Gear wait time when acceleration		
#define	GEAR_ACCF		(GROUP7+8)      //  335  07-08    Gear wait frequency when acceleration		
#define	GEAR_DECT		(GROUP7+9)      //  336  07-09    Gear wait time when deceleration		
#define	GEAR_DECF		(GROUP7+10)	    //  337  07-10    Gear wait frequency when deceleration		
#define	FAN			    (GROUP7+11)	    //  338  07-11    Fan Control		
#define	TQREF    		(GROUP7+12)	    //  339  07-12    TQC Reference from RS485		
#define	TQRSOOC			(GROUP7+13)	    //  340  07-13    Source of Torque Command		
#define	TQRMAX			(GROUP7+14)	    //  341  07-14    Torque max. level	
#define	TQRLPG			(GROUP7+15)	    //  342  07-15    Torque command filter	
#define	SPLIMIT_SL 		(GROUP7+16)	    //  343  07-16    Speed Limit selection	
#define	TQPSPDLIM		(GROUP7+17)	    //  344  07-17    Torque mode positive speed limit	
#define	TQNSPDLIM   	(GROUP7+18)	    //  345  07-18    Torque mode negative speed limit	
#define	TQROFSE			(GROUP7+19)	    //  346  07-19    Torque offset selection	
#define	TQOFSEV			(GROUP7+20)	    //  347  07-20    Torque offset setting level	
#define	TQOFSEVH		(GROUP7+21)	    //  348  07-21    Torque offset setting level High	
#define	TQOFSEVM		(GROUP7+22)	    //  349  07-22    Torque offset setting level Middle	
#define	TQOFSEVL		(GROUP7+23)	    //  350  07-23    Torque offset setting level Low	
#define	FWDM_TQLIM		(GROUP7+24)	    //  351  07-24    FWD Motoring Tq Limit	
#define	FWDR_TQLIM		(GROUP7+25)	    //  352  07-25    FWD Regeneration Tq Limit	
#define	REVM_TQLIM		(GROUP7+26)	    //  353  07-26    REV Motoring Tq Limit	
#define	REVR_TQLIM		(GROUP7+27)	    //  354  07-27    REV Regeneration Tq Limit	
#define	FORSTPWAY		(GROUP7+28)	    //  355  07-28    Emergency Stop & Forced Stop selection	
#define TQ_LPG			(GROUP7+29)	    //  356  07-29    Torque Decrease Time, add by dino, 05/29/2008
#define STOP_DCICL      (GROUP7+30)     //  3xx  07-30    STOP DC Inject Level                  //[DCI Level when stop, Bernie, 05/21/2012]
#define	BTT100			(GROUP7+31)		//	3xx  07-31    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define	BTTx_Test		(GROUP7+32)		//	3xx  07-32    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define	BTTx_TestDist	(GROUP7+33)		//	3xx  07-33    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTTx_TestTime	(GROUP7+34)		//	3xx  07-34    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define	BTTx_TestTorq	(GROUP7+35)		//	3xx  07-35    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define	BTTx_MinTorq	(GROUP7+36)		//	3xx  07-36    //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define	BTTx_MaxTorq	(GROUP7+37)		//	3xx  07-36    //[JES Torq Detect Function, Special.Kung, 2022/09/01]

/*------------	Group8	 --------*/	
#define	GROUP8			(GROUP7+38)				
#define	PM_AUTO_T		(GROUP8+0)		//	357	08-00	PMotor Auto-Tuning
#define	PM_MI_RAT		(GROUP8+1)		//	358	08-01	PMotor rated Current
#define	PM_P_RATED		(GROUP8+2)		//	359	08-02	PMotor Rated Power
#define	PM_RPM_RATED	(GROUP8+3)		//	360	08-03	PMotor Rated RPM
#define	PM_POLES		(GROUP8+4)		//	361	08-04	PMotor pole No.
#define	PM_Rs			(GROUP8+5)		//	362	08-05	PMotor Rs
#define	PM_Ld			(GROUP8+6)		//	363	08-06	PMotor Ld
#define	PM_Lq			(GROUP8+7)		//	364	08-07	PMotor Lq
#define	PM_Bemf			(GROUP8+8)		//	365	08-08	PMotor Bemf coff				
#define Z_OFFSET		(GROUP8+9)		//	366	08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
#define	ST_TUNE			(GROUP8+10)		//	367	08-10	//ADDED BY DINO
/*------------	Group9	 --------*/					
#define	GROUP9			(GROUP8+11)				
#define	ADDRS3			(GROUP9+0)		//  368	09-00	Comm Address
#define	BPS3			(GROUP9+1)		//  369	09-01	Tranmission speed
#define	C_FAULT3		(GROUP9+2)		//  370	09-02	Comm fault Treatment
#define	CTODT3			(GROUP9+3)		//  371	09-03	Comm Time out
#define	PROTOCOL3		(GROUP9+4)		//  372	09-04	Comm Protocol
#define	REM_DT3			(GROUP9+5)		//  373	09-05	ASC remote Response Delay Time, 1=100us
#define CAN_BURD        (GROUP9+6)      //  3XX 09-06   CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
#define PDO_TX_Time     (GROUP9+7)      //  3XX 09-07   CAN PDO Handshaking Period
#define CAN_ChkTime     (GROUP9+8)      //  3XX 09-08   CAN Communiction Timeout
#define EV_ID           (GROUP9+9)      //  3XX 09-09   Elevator Control Identification Code
#define CAN_FUN         (GROUP9+10)     //  3XX 09-10   Factory Function
#define DLC_MODE1       (GROUP9+11)     //  3XX 09-11   RD Function
#define DLC_MODE2       (GROUP9+12)     //  3XX 09-12   DLC Mode
#define	DLC_MODE3       (GROUP9+13)     //  3XX 09-13
#define	CANPDOTXTIME    (GROUP9+14)     //  3XX 09-14   CAN Fail rate aevin add--6/12/2017

/*------------	Group10	 --------*/
#define	GROUP10			(GROUP9+15)
#define	PG_TYPE			(GROUP10+0)		//	374	10-00	PG TYPE
#define	EPPR			(GROUP10+1)		//	375	10-01	Encoder pulses	
#define	PGINPUT			(GROUP10+2)		//	376	10-02	PG input setting	
#define	ENCLOSS			(GROUP10+3)		//	377	10-03	PG fbk fault treatment	
#define	ENCDET			(GROUP10+4)		//	378	10-04	PG fbk Error Detection Time	
#define	PGOSPDL			(GROUP10+5)		//	379	10-05	PG fbk overspeed detection level	
#define	OSPDET			(GROUP10+6)		//	380	10-06	Over speed Detection Time	
#define	PGDEVDL			(GROUP10+7)		//	381	10-07	PG fbk speed deviation level	
#define	DEVDET			(GROUP10+8)		//	382	10-08	Deviation Detect Time	
#define	OSPDWAY			(GROUP10+9)		//  383	10-09	Operation at overspeed	
#define UVW_TYPE		(GROUP10+10)	//  384 10-10   Hall Input Types
#define ZASRKP			(GROUP10+11)	//	385	10-11	KP gain of ASR in Zero speed	
#define ZASRKI			(GROUP10+12)	//	386	10-12	Ki gain of ASR in Zero speed		
#define	SPP1			(GROUP10+13)	//	387	10-13	ASR P Gain 1	
#define	SPI1			(GROUP10+14)	//	388	10-14	ASR I Gain 1	
#define	SPP2			(GROUP10+15)	//	389	10-15	ASR P Gain 2	
#define	SPI2			(GROUP10+16)	//	390	10-16	ASR I Gain 2	
#define	ASR_F1			(GROUP10+17)	//	391	10-17	ASR1/ASR2 switch freq	
#define	PriLPG			(GROUP10+18)	//	392	10-18	Primary LowPass filter Gain
#define PPI_P			(GROUP10+19) 	//	393	10-19	PPI P Gain
#define SPI1BAND        (GROUP10+20)    //  394 10-20   SPI1 Band
#define	SPI2BAND		(GROUP10+21)	//	395	10-21	SPI2 Band
#define POS_CTIME		(GROUP10+22)	//	396	10-22	position control time
#define	ZSPLowpass		(GROUP10+23)	//	397	10-23	position control LOW POSS FILTER
#define SOPCTRL			(GROUP10+24)	//  398 10-24   Source of Position Control
#define ZASRKP_L  		(GROUP10+25)	//	399	10-25	KP gain of ASR in Zero speed of Landing, DINO, 08/02/2010
#define ZASRKI_L   		(GROUP10+26)	//	400	10-26	Ki gain of ASR in Zero speed of Landing, DINO, 08/02/2010
#define ZASRKP_P		(GROUP10+27)	//	385	10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
#define ZASRKI_P		(GROUP10+28)	//	386	10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
#define FREQ_DIV        (GROUP10+29)	//	386	10-29   PG Card Frequency Division Output    //[Modify PG Type Define, Bernie, 12/05/2011]
#define PG_DIV_MODE     (GROUP10+30)	//	386	10-30   PG Card Frequency Division Mode setting                       //[Modify PG Type Define, Bernie, 12/05/2011]
#define PG_C_TYPE       (GROUP10+31)    //  3XX  10-31   Encoder C+/C- exchange           //[change parameter to normal group, Bernie, 2014/02/14]
#define OVER_ACC_LEVEL  (GROUP10+32)    //  3XX  10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
#define OVER_ACC_TIME   (GROUP10+33)    //  3XX  10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
#define OVER_ACC_SET    (GROUP10+34)    //  3XX  10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
/*------------	Group11	 --------*/
#define	GROUP11			(GROUP10+35)
#define	SysControl		(GROUP11+0)		//	401	11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo 
#define Lift_SPD		(GROUP11+1)		//	402	11-01	Lift operation speed
#define	SHEAVE_D		(GROUP11+2)		//	403	11-02	SHEAVE diameter			ADDED BY SCOTTY
#define GearRatio		(GROUP11+3) 	//  404	11-03	Gear Ratio
#define	SUSPENSION		(GROUP11+4)		//	405	11-04	Suspension ratio
#define	JM_PERCENT		(GROUP11+5)		//	406	11-05	inertia	percent			ADDED BY SCOTTY
#define	ZSPDLPBW		(GROUP11+6)		//	407	11-06	Zero Speed Loop BandWidth
#define	SPDLPBW1		(GROUP11+7)		//	408	11-07	Speed Loop BandWidth1
#define	SPDLPBW2		(GROUP11+8)		//	409	11-08	Speed Loop BandWidth2
#define	PDFFKr			(GROUP11+9)		//	410	11-09	PDFFKr		
#define	SPDFFDGain		(GROUP11+10)	//	411	11-10	SPEED FFD GAIN			ADDED BY SCOTTY
#define	NH_Deep			(GROUP11+11)	//	412	11-11	Netch filter deep(db)	
#define	NH_Freq			(GROUP11+12)	//	413	11-12	Netch filter frequency	
#define	LPF_DISP		(GROUP11+13)	//	414	11-13	Low Pass Filter for display	
#define Lift_ACCi		(GROUP11+14)	//	415	11-14	ACC Max current
#define Max_MperS		(GROUP11+15)	//	416	11-15	max meter/sec	
#define DATA_SEL		(GROUP11+16)	//	417	11-16	Display address,add by dino 2007/03/08
#define SHOW_DATA		(GROUP11+17)	//	418	11-17	Display data,   add by dino 2007/03/08
#define PROTBIT			(GROUP11+18)	//	419	11-18	Protect Bit	
#define	ZSPDLPBW_L   	(GROUP11+19)	//	420	11-19	Zero Speed Loop BandWidth of Landing, DINO, 08/02/2010
#define	PWM_MODE		(GROUP11+20)	//	420	11-20	PWM MODE, 0=SVPWM+DPWM,1=SVPWM	    //[move parameter to 11-20, Bernie, 2017/02/16]
#define	LPF_LC01DISP	(GROUP11+21)    //	420	11-21   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
#define Lift_SPD_RPM  	(GROUP11+21)	//	10	11-21	LIFT_SPD_CMD	    //[SIBOCOM, Jason, 2019/12/31]
/*------------ Group12 ----------*/
//#define GROUP12			(GROUP11+22)
#else

#define Client_Mode     (GROUP11+22)    //	420	11-21   //Save Customer bit
/*------------ Group12 ----------*/

#define GROUP12			(GROUP11+23)
#endif
#define	UMAP_ADD0		(GROUP12+0)		//	421	12-00
#define	UMAP_ADD1		(GROUP12+1)		//	422	12-01
#define	UMAP_ADD2		(GROUP12+2)		//	423	12-02	
#define UMAP_ADD3		(GROUP12+3)		//	424	12-33	
#define	UMAP_ADD4		(GROUP12+4)		//	425	12-04
#define	UMAP_ADD5		(GROUP12+5)		//	426	12-05		
#define	UMAP_ADD6		(GROUP12+6)		//	427	12-06		
#define	UMAP_ADD7		(GROUP12+7)		//	428	12-07	
#define UMAP_ADD8		(GROUP12+8)		//	429	12-08	
#define	UMAP_ADD9		(GROUP12+9)		//	430	12-09
#define	UMAP_ADD10		(GROUP12+10)	//	431	12-10		
#define	UMAP_ADD11		(GROUP12+11)	//	432	12-11		
#define	UMAP_ADD12		(GROUP12+12)	//	433	12-12	
#define UMAP_ADD13		(GROUP12+13)	//	434	12-13	
#define	UMAP_ADD14		(GROUP12+14)	//	435	12-14
#define	UMAP_ADD15		(GROUP12+15)	//	436	12-15		
#define	UMAP_ADD16		(GROUP12+16)	//	437	12-16		
#define	UMAP_ADD17		(GROUP12+17)	//	438	12-17	
#define UMAP_ADD18		(GROUP12+18)	//	439	12-18	
#define	UMAP_ADD19		(GROUP12+19)	//	440	12-19
#define	UMAP_ADD20		(GROUP12+20)	//	441	12-20		
#define	UMAP_ADD21		(GROUP12+21)	//	442	12-21		
#define	UMAP_ADD22		(GROUP12+22)	//	443	12-22	
#define UMAP_ADD23		(GROUP12+23)	//	444	12-23	
#define	UMAP_ADD24		(GROUP12+24)	//	445	12-24
#define	UMAP_ADD25		(GROUP12+25)	//	446	12-25		
#define	UMAP_ADD26		(GROUP12+26)	//	447	12-26		
#define	UMAP_ADD27		(GROUP12+27)	//	448	12-27	
#define UMAP_ADD28		(GROUP12+28)	//	449	12-28	
#define	UMAP_ADD29		(GROUP12+29)	//	450	12-29
#define UMAP_ADD30		(GROUP12+30)	//	451	12-30	
#define	UMAP_ADD31		(GROUP12+31)	//	452	12-31
#define	UMAP_ADD32		(GROUP12+32)    //	421	12-32
#define	UMAP_ADD33		(GROUP12+33)	//	422	12-33
#define	UMAP_ADD34		(GROUP12+34)	//	423	12-34	
#define UMAP_ADD35		(GROUP12+35)	//	424	12-35	
#define	UMAP_ADD36		(GROUP12+36)	//	425	12-36
#define	UMAP_ADD37		(GROUP12+37)	//	426	12-37		
#define	UMAP_ADD38		(GROUP12+38)	//	427	12-38		
#define	UMAP_ADD39		(GROUP12+39)	//	428	12-38	
#define	UMAP_ADD40		(GROUP12+40)	//	421	12-40
#define	UMAP_ADD41		(GROUP12+41)	//	422	12-41
#define	UMAP_ADD42		(GROUP12+42)	//	423	12-42	
#define UMAP_ADD43		(GROUP12+43)	//	424	12-43	
#define	UMAP_ADD44		(GROUP12+44)	//	425	12-44
#define	UMAP_ADD45		(GROUP12+45)	//	426	12-45		
#define	UMAP_ADD46		(GROUP12+46)	//	427	12-46		
#define	UMAP_ADD47		(GROUP12+47)	//	428	12-47	
#define UMAP_ADD48		(GROUP12+48)	//	429	12-48	
#define	UMAP_ADD49		(GROUP12+49)	//	430	12-49
#define	UMAP_ADD50		(GROUP12+50)	//	421	12-50
#define	UMAP_ADD51		(GROUP12+51)	//	422	12-51
#define	UMAP_ADD52		(GROUP12+52)	//	423	12-52	
#define UMAP_ADD53		(GROUP12+53)	//	424	12-53	
#define	UMAP_ADD54		(GROUP12+54)	//	425	12-54
#define	UMAP_ADD55		(GROUP12+55)	//	426	12-55		
#define	UMAP_ADD56		(GROUP12+56)	//	427	12-56		
#define	UMAP_ADD57		(GROUP12+57)	//	428	12-57	
#define UMAP_ADD58		(GROUP12+58)	//	429	12-58	
#define	UMAP_ADD59		(GROUP12+59)	//	430	12-59
#define	UMAP_ADD60		(GROUP12+60)	//	421	12-60
#define	UMAP_ADD61		(GROUP12+61)	//	422	12-61
#define	UMAP_ADD62		(GROUP12+62)	//	423	12-62	
#define UMAP_ADD63		(GROUP12+63)	//	424	12-63	
#define	UMAP_ADD64		(GROUP12+64)	//	425	12-64
#define	UMAP_ADD65		(GROUP12+65)	//	426	12-65		
#define	UMAP_ADD66		(GROUP12+66)	//	427	12-66		
#define	UMAP_ADD67		(GROUP12+67)	//	428	12-67	
#define UMAP_ADD68		(GROUP12+68)	//	429	12-68	
#define	UMAP_ADD69		(GROUP12+69)	//	430	12-69
#define	UMAP_ADD70		(GROUP12+70)	//	421	12-70
#define	UMAP_ADD71		(GROUP12+71)	//	422	12-71
#define	UMAP_ADD72		(GROUP12+72)	//	423	12-72	
#define UMAP_ADD73		(GROUP12+73)	//	424	12-73	
#define	UMAP_ADD74		(GROUP12+74)	//	425	12-74
#define	UMAP_ADD75		(GROUP12+75)	//	426	12-75		
#define	UMAP_ADD76		(GROUP12+76)	//	427	12-76		
#define	UMAP_ADD77		(GROUP12+77)	//	428	12-77	
#define UMAP_ADD78		(GROUP12+78)	//	429	12-78	
#define	UMAP_ADD79		(GROUP12+79)	//	430	12-79
#define	UMAP_ADD80		(GROUP12+80)	//	421	12-80
#define	UMAP_ADD81		(GROUP12+81)	//	422	12-81
#define	UMAP_ADD82		(GROUP12+82)	//	423	12-82	
#define UMAP_ADD83		(GROUP12+83)	//	424	12-83	
#define	UMAP_ADD84		(GROUP12+84)	//	425	12-84
#define	UMAP_ADD85		(GROUP12+85)	//	426	12-85		
#define	UMAP_ADD86		(GROUP12+86)	//	427	12-86		
#define	UMAP_ADD87		(GROUP12+87)	//	428	12-87	
#define UMAP_ADD88		(GROUP12+88)	//	429	12-88	
#define	UMAP_ADD89		(GROUP12+89)	//	430	12-89
#define	UMAP_ADD90		(GROUP12+90)	//	421	12-90
#define	UMAP_ADD91		(GROUP12+91)	//	422	12-91
#define	UMAP_ADD92		(GROUP12+92)	//	423	12-92	
#define UMAP_ADD93		(GROUP12+93)	//	424	12-93	
#define	UMAP_ADD94		(GROUP12+94)	//	425	12-94
#define	UMAP_ADD95		(GROUP12+95)	//	426	12-95		
#define	UMAP_ADD96		(GROUP12+96)	//	427	12-96		
#define	UMAP_ADD97		(GROUP12+97)	//	428	12-97	
#define UMAP_ADD98		(GROUP12+98)	//	429	12-98	
#define	UMAP_ADD99		(GROUP12+99)	//	430	12-99
/*------------ Group13 ----------*/            
#define GROUP13			(GROUP12+100)           
#define	UMAP_DATA0		(GROUP13+0)		//	453	13-00		
#define	UMAP_DATA1		(GROUP13+1)		//	454	13-01		
#define	UMAP_DATA2		(GROUP13+2)		//	455	13-02	
#define UMAP_DATA3		(GROUP13+3)		//	456	13-33	
#define	UMAP_DATA4		(GROUP13+4)		//	457	13-04
#define	UMAP_DATA5		(GROUP13+5)		//	458	13-05		
#define	UMAP_DATA6		(GROUP13+6)		//	459	13-06		
#define	UMAP_DATA7		(GROUP13+7)		//	460	13-07	
#define UMAP_DATA8		(GROUP13+8)		//	461	13-08	
#define	UMAP_DATA9		(GROUP13+9)		//	462	13-09
#define	UMAP_DATA10		(GROUP13+10)	//	463	13-10		
#define	UMAP_DATA11		(GROUP13+11)	//	464	13-11		
#define	UMAP_DATA12		(GROUP13+12)	//	465	13-12	
#define UMAP_DATA13		(GROUP13+13)	//	466	13-13	
#define	UMAP_DATA14		(GROUP13+14)	//	467	13-14
#define	UMAP_DATA15		(GROUP13+15)	//	468	13-15		
#define	UMAP_DATA16		(GROUP13+16)	//	469	13-16		
#define	UMAP_DATA17		(GROUP13+17)	//	470	13-17	
#define UMAP_DATA18		(GROUP13+18)	//	471	13-18	
#define	UMAP_DATA19		(GROUP13+19)	//	472	13-19
#define	UMAP_DATA20		(GROUP13+20)	//	473	13-20		
#define	UMAP_DATA21		(GROUP13+21)	//	474	13-21		
#define	UMAP_DATA22		(GROUP13+22)	//	475	13-22	
#define UMAP_DATA23		(GROUP13+23)	//	476	13-23	
#define	UMAP_DATA24		(GROUP13+24)	//	477	13-24
#define	UMAP_DATA25		(GROUP13+25)	//	478	13-25		
#define	UMAP_DATA26		(GROUP13+26)	//	479	13-26		
#define	UMAP_DATA27		(GROUP13+27)	//	480	13-27	
#define UMAP_DATA28		(GROUP13+28)	//	481	13-28	
#define	UMAP_DATA29		(GROUP13+29)	//	482	13-29
#define UMAP_DATA30		(GROUP13+30)	//	483	13-30	
#define	UMAP_DATA31		(GROUP13+31)	//	484	13-31	
#define	UMAP_DATA32		(GROUP13+32)	//	455	13-32	
#define UMAP_DATA33		(GROUP13+33)	//	456	13-33	
#define	UMAP_DATA34		(GROUP13+34)	//	457	13-34
#define	UMAP_DATA35		(GROUP13+35)	//	458	13-35		
#define	UMAP_DATA36		(GROUP13+36)	//	459	13-36		
#define	UMAP_DATA37		(GROUP13+37)	//	460	13-37	
#define UMAP_DATA38		(GROUP13+38)	//	461	13-38	
#define	UMAP_DATA39		(GROUP13+39)	//	462	13-39
#define	UMAP_DATA40		(GROUP13+40)	//	453	13-40		
#define	UMAP_DATA41		(GROUP13+41)	//	454	13-41		
#define	UMAP_DATA42		(GROUP13+42)	//	455	13-42	
#define UMAP_DATA43		(GROUP13+43)	//	456	13-43	
#define	UMAP_DATA44		(GROUP13+44)	//	457	13-44
#define	UMAP_DATA45		(GROUP13+45)	//	458	13-45		
#define	UMAP_DATA46		(GROUP13+46)	//	459	13-46		
#define	UMAP_DATA47		(GROUP13+47)	//	460	13-47	
#define UMAP_DATA48		(GROUP13+48)	//	461	13-48	
#define	UMAP_DATA49		(GROUP13+49)	//	462	13-49
#define	UMAP_DATA50		(GROUP13+50)	//	453	13-50	
#define	UMAP_DATA51		(GROUP13+51)	//	454	13-51		
#define	UMAP_DATA52		(GROUP13+52)	//	455	13-52	
#define UMAP_DATA53		(GROUP13+53)	//	456	13-53	
#define	UMAP_DATA54		(GROUP13+54)	//	457	13-54
#define	UMAP_DATA55		(GROUP13+55)	//	458	13-55		
#define	UMAP_DATA56		(GROUP13+56)	//	459	13-56		
#define	UMAP_DATA57		(GROUP13+57)	//	460	13-57	
#define UMAP_DATA58		(GROUP13+58)	//	461	13-58	
#define	UMAP_DATA59		(GROUP13+59)	//	462	13-59
#define	UMAP_DATA60		(GROUP13+60)	//	453	13-60		
#define	UMAP_DATA61		(GROUP13+61)	//	454	13-61		
#define	UMAP_DATA62		(GROUP13+62)	//	455	13-62	
#define UMAP_DATA63		(GROUP13+63)	//	456	13-63	
#define	UMAP_DATA64		(GROUP13+64)	//	457	13-64
#define	UMAP_DATA65		(GROUP13+65)	//	458	13-65		
#define	UMAP_DATA66		(GROUP13+66)	//	459	13-66		
#define	UMAP_DATA67		(GROUP13+67)	//	460	13-67	
#define UMAP_DATA68		(GROUP13+68)	//	461	13-68	
#define	UMAP_DATA69		(GROUP13+69)	//	462	13-69
#define	UMAP_DATA70		(GROUP13+70)	//	453	13-70		
#define	UMAP_DATA71		(GROUP13+71)	//	454	13-71		
#define	UMAP_DATA72		(GROUP13+72)	//	455	13-72	
#define UMAP_DATA73		(GROUP13+73)	//	456	13-73	
#define	UMAP_DATA74		(GROUP13+74)	//	457	13-74
#define	UMAP_DATA75		(GROUP13+75)	//	458	13-75		
#define	UMAP_DATA76		(GROUP13+76)	//	459	13-76		
#define	UMAP_DATA77		(GROUP13+77)	//	460	13-77	
#define UMAP_DATA78		(GROUP13+78)	//	461	13-78	
#define	UMAP_DATA79		(GROUP13+79)	//	462	13-79
#define	UMAP_DATA80		(GROUP13+80)	//	453	13-80		
#define	UMAP_DATA81		(GROUP13+81)	//	454	13-81		
#define	UMAP_DATA82		(GROUP13+82)	//	455	13-82	
#define UMAP_DATA83		(GROUP13+83)	//	456	13-83	
#define	UMAP_DATA84		(GROUP13+84)	//	457	13-84
#define	UMAP_DATA85		(GROUP13+85)	//	458	13-85		
#define	UMAP_DATA86		(GROUP13+86)	//	459	13-86		
#define	UMAP_DATA87		(GROUP13+87)	//	460	13-87	
#define UMAP_DATA88		(GROUP13+88)	//	461	13-88	
#define	UMAP_DATA89		(GROUP13+89)	//	462	13-89
#define	UMAP_DATA90		(GROUP13+90)	//	453	13-90		
#define	UMAP_DATA91		(GROUP13+91)	//	454	13-91		
#define	UMAP_DATA92		(GROUP13+92)	//	455	13-92	
#define UMAP_DATA93		(GROUP13+93)	//	456	13-93	
#define	UMAP_DATA94		(GROUP13+94)	//	457	13-94
#define	UMAP_DATA95		(GROUP13+95)	//	458	13-95		
#define	UMAP_DATA96		(GROUP13+96)	//	459	13-96		
#define	UMAP_DATA97		(GROUP13+97)	//  460	13-97	
#define UMAP_DATA98		(GROUP13+98)	//  461	13-98	
#define	UMAP_DATA99		(GROUP13+99)	//	462	13-99
/*------------	Group14	 --------*/            
#define GROUP14			(GROUP13+100)     
#define	IdsPSLevel		(GROUP14+0)		//	485	14-00	Ids Power Save Level
#define	VFSL			(GROUP14+1)		//	486	14-01	VF voltage mode selection
#define	CTSEL			(GROUP14+2)		//	487	14-02	Constant Torque Selection
#define	AAAD			(GROUP14+3)		//	488	14-03	Auto Accel/Decel
#define	U_ACCDEC		(GROUP14+4)		//	489	14-04	Unit of Acc/Dec time
#define	PWRSAVE			(GROUP14+5)		//	490	14-05	Power Save mode
#define	STOPM			(GROUP14+6)		//	491	14-06	Stop Methods
#define	SETDIR			(GROUP14+7)		//	492	14-07	Reverse Operation
#define	FSKIP1H			(GROUP14+8)		//	493	14-08	Skip Freq. Point 1 upper limit	
#define	FSKIP1L			(GROUP14+9)		//	494	14-09	Skip Freq. Point 1 lower limit	
#define	FSKIP2H			(GROUP14+10)	//	495	14-10	Skip Freq. Point 2 upper limit	
#define	FSKIP2L			(GROUP14+11)	//	496	14-11	Skip Freq. Point 2 lower limit	
#define	FSKIP3H			(GROUP14+12)	//	497	14-12	Skip Freq. Point 3 upper limit	
#define	FSKIP3L			(GROUP14+13)	//	498	14-13	Skip Freq. Point 3 lower limit	
#define	MFBASE2			(GROUP14+14)	//	499	14-14	Motor Base Frequency 2	
#define	VMAX2			(GROUP14+15)	//	500	14-15	Max Output Voltage 2
#define	FMID2_1			(GROUP14+16)	//	501	14-16	Mid Output Freq.2 1
#define	VMID2_1			(GROUP14+17)	//	502	14-17	Mid Output Voltage 2 1
#define	FMID2_2			(GROUP14+18)	//	503	14-18	Mid Output Freq.2 2
#define	VMID2_2			(GROUP14+19)	//	504	14-19	Mid Output Voltage 2 2
#define	FMIN2			(GROUP14+20)	//	505 14-20	Min Output Freq. 2
#define	VMIN2			(GROUP14+21)	//	506	14-21	Min Output Voltage 2
#define	UPDNKEYM		(GROUP14+22)	//	507	14-22	up/down key mode		
#define	UPDNKEYS		(GROUP14+23)	//	508	14-23	up/down key speed
#define	CNTCPL			(GROUP14+24)	//	509	14-24	Counter Value Set (Complete)		
#define	CNTPRS			(GROUP14+25)	//	510	14-25	Counter Value Reach (Preset)		
#define	LIMIT_SCALE	    (GROUP14+26)	//	511	14-26	LIMIT_SCALE  //[weak magnet, Sampo, 03/31/2011]		
#define	MI9	    		(GROUP14+27)	//	512	14-27	Multi-Function Input 9	
#define	MI10    		(GROUP14+28)	//	513	14-28	Multi-Function Input 10	
#define	MI11    		(GROUP14+29)	//	514	14-29	Multi-Function Input 11	
#define	MI12    		(GROUP14+30)	//	515	14-30	Multi-Function Input 12	
#define	MI13    		(GROUP14+31)	//	516	14-31	Multi-Function Input 13	
#define	MI14    		(GROUP14+32)	//	517	14-32	Multi-Function Input 14	
#define EXTON_RUN		(GROUP14+33)	//	518	14-33	External Terminal Run after Fault Reset		
#define	ACISEL			(GROUP14+34)	//	519	14-34	ACI change to AVI2
#define	AISUM			(GROUP14+35)	// 	520	14-35	Addition Function of AI	
#define	PMI1			(GROUP14+36)	//	521	14-36	Multi-Position Point 1
#define	PMI2			(GROUP14+37)	//	522	14-37	Multi-Position Point 2
#define	PMI3			(GROUP14+38)	//	523	14-38	Multi-Position Point 3
#define	PMI4			(GROUP14+39)	//	524	14-39	Multi-Position Point 4
#define	PMI5			(GROUP14+40)	//	525	14-40	Multi-Position Point 5
#define	PMI6			(GROUP14+41)	//	526	14-41	Multi-Position Point 6
#define	PMI7			(GROUP14+42)	//	527	14-42	Multi-Position Point 7
#define	PMI8			(GROUP14+43)	//	528	14-43	Multi-Position Point 8
#define	PMI9			(GROUP14+44)	//	529	14-44	Multi-Position Point 9
#define	PMI10			(GROUP14+45)	//	530	14-45	Multi-Position Point 10
#define	PMI11			(GROUP14+46)	//	531	14-46	Multi-Position Point 11
#define	PMI12			(GROUP14+47)	//	532	14-47	Multi-Position Point 12
#define	PMI13			(GROUP14+48)	//	533	14-48	Multi-Position Point 13
#define	PMI14			(GROUP14+49)	//	534	14-49	Multi-Position Point 14
#define	PMI15			(GROUP14+50)	//	535	14-50	Multi-Position Point 15
#define	MOTORSEL		(GROUP14+51)	//	536	14-51	Motor Selection 1 or 2
#define	YDSWRPM			(GROUP14+52)	//	537	14-52	Y-Delta Connected switching rpm	
#define	YDSWEN			(GROUP14+53)	//	538	14-53	Y-Delta switched Enable	
#define	MI_RAT2			(GROUP14+54)	//	539	14-54	Motor 2 rated Current	
#define	P_RATED2		(GROUP14+55)	//	540	14-55	Motor 2 Rated Power	
#define	RPM_RATED2		(GROUP14+56)	//	541	14-56	Motor 2 Rated RPM	
#define	POLES2			(GROUP14+57)	//	542	14-57	Motor 2 pole No.	
#define	MI_NL2			(GROUP14+58)	//	543	14-58	Motor 2 No-Load Current	
#define	Rs2			    (GROUP14+59)	//	544	14-59	Motor 2 Rs	
#define	Rr2			    (GROUP14+60)	//	545	14-60	Motor 2 Rr	
#define	Lm2			    (GROUP14+61)	//	546	14-61	Motor 2 Lm	
#define	Lx2			    (GROUP14+62)	//	547	14-62	Motor 2 Lx
#define	YDDELAYT		(GROUP14+63)	//	548	14-63	Y-Delta On delay time	
#define	STALL4V			(GROUP14+64)	//	549	14-64	OV stall level
#define	EOL2_SL			(GROUP14+65)	//	550	14-65	Thermal Relay 2 Selection	
#define	EOL2_T			(GROUP14+66)	//	551	14-66	Thermal Relay 2 Time	
#define	PWRLOS			(GROUP14+67)	//	552	14-67	Momentary Power Loss		
#define	PWRL_T			(GROUP14+68)	//	553	14-68	Max. allowable PL time		
#define	BB_T			(GROUP14+69)	//	554	14-69	BB Time for speed serach		
#define	SER_CL			(GROUP14+70)	//	555	14-70	Current level for SPD serach		
#define	REST_M			(GROUP14+71)	//	556	14-71	bb treatment for oc, ov, bb		
#define	REST_CNT		(GROUP14+72)	//	557	14-72	Auto restart after fault		
#define	SPD_SER			(GROUP14+73)	//	558	14-73	Auto restart Speed serach method		
#define	KEB_SL			(GROUP14+74)	//	559	14-74	Deceleration at Momertary Power loss 		
#define	KEB_RT			(GROUP14+75)	//	560	14-75	KEB Return Time	
#define	PIDSL			(GROUP14+76)	//	561	14-76	PID feedback selection	
#define	PID_P			(GROUP14+77)	//	562	14-77	P gain of PID	
#define	PID_I			(GROUP14+78)	//	563	14-78	I gain of PID	
#define	PID_D			(GROUP14+79)	//	564	14-79	D gain of PID	
#define	PID_ILIMIT		(GROUP14+80)	//	565	14-80	Upper bound for integral	
#define	PIDMAX			(GROUP14+81)	//	566	14-81	PID output Freq. Limit	
#define	PIDOFSET		(GROUP14+82)	//	567	14-82	PID offset	
#define	PIDDLY			(GROUP14+83)	//	568	14-83	Derivative Filter Time Constant	
#define	FB_DT			(GROUP14+84)	//	569	14-84	Feedback signal detection time	
#define	FB_LOSS			(GROUP14+85)	//	570	14-85	PID feedback loss	
#define	SLEEPF			(GROUP14+86)	//	571	14-86	Sleep Frequency	
#define	WAKEF			(GROUP14+87)	//	572	14-87	Wake up Frequency	
#define	SLEEPT			(GROUP14+88)	//	573	14-88	Sleep Time	
#define	PID_DEV			(GROUP14+89)	//	574	14-89	PID Deviation Level	
#define	PIDDEVT			(GROUP14+90)	//	575	14-90	PID Deviation Time	
#define	PIDFBLPG		(GROUP14+91)	//	576	14-91	PID feedback filter
#define	FCMAIN			(GROUP14+92)	//	577	14-92	Main Frequency from communication
#define	BKTRANS1		(GROUP14+93)	//	578	14-93	Block Transfer 1
#define	BKTRANS2		(GROUP14+94)	//	579	14-94	Block Transfer 2
#define	BKTRANS3		(GROUP14+95)	//	580	14-95	Block Transfer 3	
#define	BKTRANS4		(GROUP14+96)	//	581	14-96	Block Transfer 4	
#define	BKTRANS5		(GROUP14+97)	//	582	14-97	Block Transfer 5	
#define	BKTRANS6		(GROUP14+98)	//	583	14-98	Block Transfer 6	
#define	BKTRANS7		(GROUP14+99)	//	584	14-99	Block Transfer 7	
#define	BKTRANS8		(GROUP14+100)	//	585	14-100	Block Transfer 8	
#define	BKTRANS9		(GROUP14+101)	//	586	14-101	Block Transfer 9	
#define	BKTRANS10		(GROUP14+102)	//	587	14-102	Block Transfer 10	
#define	WEAKLPF			(GROUP14+103)	//	588	14-103	WEAKLPF      //[weak magnet, Sampo, 03/31/2011]
#define	WEAKTHETA		(GROUP14+104)	//	589	14-104	WEAKTHETA	 //[weak magnet, Sampo, 03/31/2011]
#define OVER_SCALE		(GROUP14+105)	//	590	14-105	OVER_SCALE	 //[weak magnet, Sampo, 03/31/2011]
#define PGHOME			(GROUP14+106)	//	591	14-106	PG Position Control Point (Home)	
#define PGATTAIN		(GROUP14+107)	//	592	14-107	Range for PG Position Attained	
#define APRFFGA			(GROUP14+108)	//	593	14-108	Gain of APR feedforward		
#define APRDECT			(GROUP14+109)	//	594	14-109	Decelerate time of APR		
#define	VCOMFT			(GROUP14+110)	//	595	14-110	FMax Target by Vcommand Position		
#define	PACCELT			(GROUP14+111)	//	596	14-111	Accel. Time for Position		
#define MPGGA			(GROUP14+112)	//	597	14-112	PG Mechanical Gear A		
#define MPGGB			(GROUP14+113)	//	598	14-113	PG Mechanical Gear B
#define	JmPu			(GROUP14+114)	//	599	14-114	Interia of motor PU		
#define	M1_IdsRefLim	(GROUP14+115)	//	600	14-115	Motor1 IdsRef Limit		
#define	M2_IdsRefLim	(GROUP14+116)	//	601	14-116	Motor2 IdsRef Limit		
#define	PHL_T			(GROUP14+117)	//	602	14-117	Phase Loss Time	
#define	OH_IN			(GROUP14+118)	//	603	14-118	Thermo inside Temp	
#define	SpdFFD			(GROUP14+119)	//	604	14-119	Speed feed forword
#define	SLIPGC_G		(GROUP14+120)	//	605	14-120	SVC Slip Generation Compensation Gain //6a02j	
#define	PG2_LPG			(GROUP14+121)	//	606	14-121	PG2 Command Low pass Filter Gain	
#define	TENSION			(GROUP14+122)	//	607	14-122	Tension of Torque Control	
#define	DIAMETER		(GROUP14+123)	//	608	14-123	Diameter of Material	
#define	DEPTH			(GROUP14+124)	//	609	14-124	Depth of meterial	
#define	SRYREC			(GROUP14+125)	//	610	14-125	Safety Relay Record
#define	TB2Time			(GROUP14+126)	//	611	14-126	The interval between pulse time	ADDED BY DINO
#define	TGAIN			(GROUP14+127)	//	612	14-127	Pulse duty						ADDED BY DINO
#define	PHLHOUR			(GROUP14+128)	//	613	14-128	Timer of Phase loss (hour)	
#define	APRCURVET		(GROUP14+129)	//	614	14-129	Time of APR Curve
#define Jm_SELECT		(GROUP14+130)	//	615	14-130	IM control use inertia source				
#define PHL_L			(GROUP14+131)   //	616 14-131  Level of Phase Loss
#define MI_STATE        (GROUP14+132)   //  617 14-132  MI9 ~MI14 State
#define	STI   			(GROUP14+133)	//	618	14-133	Standstill Current, add by dino, 12/19/2007
#define	PGSCALE			(GROUP14+134)	//	619	14-134  Division factor of PG	
#define I_RATE          (GROUP14+135)   
//#define CAN_HC          (GROUP14+136)   //      14-136 [CAN Protocol for High Cap , Sampo,  2011/09/05]  
//#define CAN_BURD        (GROUP14+137)   //      14-136 [CAN Protocol for High Cap , Sampo,  2011/09/05]  
//#define CAN_ChkTime     (GROUP14+138)   //    623 14-138 // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
//#define PDO_TX_Time     (GROUP14+139)   //    623 14-138 // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
#define	ADDRS2			(GROUP14+140)	//	368	09-00	Comm Address  for Keypad     //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]
#define	BPS2			(GROUP14+141)	//	369	09-01	Tranmission speed for Keypad
#define	C_FAULT2		(GROUP14+142)	//	370	09-02	Comm fault Treatment for Keypad
#define	CTODT2			(GROUP14+143)	//	371	09-03	Comm Time out for Keypad
#define	PROTOCOL2		(GROUP14+144)	//	372	09-04	Comm Protocol for Keypad
#define	REM_DT2			(GROUP14+145)	//	373	09-05	ASC remote Response Delay Time, 1=100us for Keypad

#define OPH2_10HzCNT    (GROUP14+146)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_5HzCNT     (GROUP14+147)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_1HzCNT     (GROUP14+148)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_0p5HzCNT   (GROUP14+149)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_0p2HzCNT   (GROUP14+150)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_IGAIN_1    (GROUP14+151)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_IGAIN_2    (GROUP14+152)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]
#define OPH2_IGAIN_3    (GROUP14+153)   //    3XX  //[Output Phase Loss 2, Sampo, 2015/05/21]

#define	EPMAX			(GROUP14+154)				
/*-----	--------------		---------------------------*/				
#define DLC_PR          (GROUP4+50)    //[Modify DLC parameter, Bernie, 2016/01/22]

#define	PRMAX		EPMAX	

#define DLC_TABLE   50               //[Modify DLC parameter, Bernie, 2016/01/22]

#ifdef _Main_C							
        UWORD pr[PRMAX];
        UWORD pr_copy[PRMAX];
        UWORD fram_buf[PRMAX];		// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010         						
#else							
        extern UWORD pr[PRMAX];
        extern UWORD pr_copy[PRMAX];
        extern UWORD fram_buf[PRMAX];// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010       			
#endif							
