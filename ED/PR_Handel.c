/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN
                  
Project: VFD-V pro

Filename: Sample.C

Partner Filename: Sample.H

Description: This is a sample code.

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:
	
History:
===============================================================*/
#ifndef _PrHandel_C
	#define _PrHandel_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

/*--------      The parameter table for functionality        --------*/
void (*const pr_tbl[PRMAX])(UWORD prx, UWORD prvalue) = {
/*---- GROUP 15---------------------------------------*/
		P15_00	,	//	0	15-00	Debug Flag 1
		updatepr,	//	1	15-01	DBC CHANGE FREQ
		P15_02	,	//	2	15-02	efficiency of Motor
		updatepr,	//	3	15-03	DC_ZSEARCH		
		P15_02	,	//	4	15-04	AD value at Rated Current
		updatepr,	//	5	15-05	Id*,Iq* LPF
		fnone	,	//	6	15-06	Only for Factory 1
		fnone	,	//	7	15-07	Only for Factory 2
		fnone	,	//	8	15-08	Only for Factory 3
		fnone	,	//	9	15-09	Only for Factory 4
		fnone   ,	//	10	15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM   //[move parameter to 11-20, Bernie, 2017/02/16]
		updatepr,	//	11	15-11	Skip DeadTime
		P15_12	,	//	12	15-12	DCBUS 210.0 VDC ad value
		P15_12	,	//	13	15-13	DCBUS 310.0 VDC ad value
		P15_12	,	//	14	15-14	DCBUS 390.0 VDC ad value
		updatepr,	//	15	15-15	Torque control Kp
		updatepr,	//	16	15-16	Torque Control Ki
		updatepr,	//	17	15-17	Flux Control Kp
		updatepr,	//	18	15-18	Flux Control Ki
		updatepr,	//	19	15-19	Speed slop Control Kp gain
		updatepr,	//	20	15-20	Speed slop Control Ki gain
		updatepr,	//	21	15-21	Control Selection
		updatepr,	//	22	15-22	Test Source Value Amplitude
		LPFGain	,	//	23	15-23	High Speed Low pass Filter Gain
		LPFGain	,	//	24	15-24	Low Speed Low pass filter Gain
		updatepr,	//	25	15-25	Test Source Value Bias
		LPFGain	,	//	26	15-26	Estimate J Low pass Filter Gain
		updatepr,	//	27	15-27	Calibration current REF
		updatepr,	//	28	15-28	Calibration P
		updatepr,	//	29	15-29	Calibration I
		updatepr,	//	30	15-30	Auto tuning DC test Kp gain
		updatepr,	//	31	15-31	Auto Tuning DC test Ki gain
		updatepr,	//	32	15-32	Auto tuning High Freq. Lock test Kp gain
		LPFGain ,	//	33	15-33	Dcbus Low Pass Gain
		P15_34	,	//	34	15-34	Select Zero Speed
		updatepr,	//	35	15-35	No Load Boost Gain
		updatepr,	//	36	15-36	Acceleration AKP
		updatepr,	//	37	15-37	Acceleration AKI
		updatepr,	//	38	15-38	Current Loop BandWidth
		updatepr,	//	39	15-39	DBC Leading 2
		updatepr,	//	40	15-40	DBC Ratio 2 with close loop
		P15_41  ,	//	41	15-41	DBC Coef.
		P15_42  ,	//	42	15-42	DBC Dcbus Coef.
		updatepr,	//	43	15-43	DBC leading 1
		updatepr,	//	44	15-44	DBC Linear Ratio 1
		updatepr,	//	45	15-45	DBC MODE
		updatepr,	//	46	15-46	magnitization inductance 1
		updatepr,	//	47	15-47	main flux linkage 1
		updatepr,	//	48	15-48	magnitization inductance 2
		updatepr,	//	49	15-49	main flux linkage 2
		updatepr,	//	50	15-50	magnitization inductance 3
		updatepr,	//	51	15-51	main flux linkage 3
		updatepr,	//	52	15-52	magnitization inductance 4
		updatepr,	//	53	15-53	main flux linkage 4
		updatepr,	//	54	15-54	magnitization inductance 5
		updatepr,	//	55	15-55	main flux linkage 5
		updatepr,	//	56	15-56	magnitization inductance 6
		updatepr,	//	57	15-57	main flux linkage 6
		updatepr,	//	58	15-58	magnitization inductance 7
		LPFGain	,	//	59	15-59	Current Zero Low Pass Gain
		LPFGain	,	//	60	15-60	cos(TB1_uwPhi) low pass gain
		fnone  	,	//	61	15-61	reserved  //Datecode para change, Henry, 2016/07/20
		updatepr,	//	62	15-62	calibration for AUI ZeroPoint (0V)
		updatepr,	//	63	15-63	calibration for AUI max (+10V)
		updatepr,	//	64	15-64	calibration for AUI min (-10V)
		updatepr,	//	65	15-65	calibration for ACI max (20mA)
		updatepr,	//	66	15-66	calibration for ACI mid (12mA)
		updatepr,	//	67	15-67	calibration for ACI min (4mA)
		updatepr,	//	68	15-68	calibration for AVI max (+10V)
		updatepr,	//	69	15-69	calibration for AVI mid (+5V)
		updatepr,	//	70	15-70	calibration for AVI min (0V)
		updatepr,	//	71	15-71	Deceleration DKP
		updatepr,	//	72	15-72	Deceleration DKI
		updatepr,	//	73	15-73	more volt. comp. below this freq.
		updatepr,	//	74	15-74	PGLOSS Detect Counter
		updatepr,	//	75	15-75	Main Frequency
		updatepr,	//	76	15-76	Power On Counter
		updatepr,	//	77	15-77   GFF Maximum Value Record, Jerry Yu, 2019/11/11
		fnone   ,	//	78	15-78	BLD Version  //[BootLoader Version, Special.Kung, 2022/10/31] 
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
		updatepr,   //  79  15-79
#else
		fnone   ,   //  79  15-79
#endif
		updatepr,   //  80  15-80
		updatepr,   //  81  15-81
		updatepr,   //  82  15-82
		fnone   ,   //  83  15-83   BLD DataCode //[BootLoader DataCode, Special.Kung, 2022/10/31]
		updatepr,	//	84	15-84	calibration for AUI ZeroPoint (0V)
		updatepr,	//	85	15-85	calibration for AUI max (+2V)
		updatepr,	//	86	15-86	calibration for AUI min (-2V)
		P15_87  ,	//	87	15-87	calibration for AUI max (+10V)
		P15_87  ,	//	88	15-88	calibration for AUI min (-10V)
		P15_87  ,	//	89	15-89	calibration for AUI max (+10V)
		P15_87  ,	//	90	15-90	calibration for AUI min (-10V)
		updatepr,	//	91	15-91	minimun pulse 
		updatepr,	//	92	15-92	D Frame Fan control
		updatepr,	//  93  15-93   Z phase UVW Section when pr[PG_TYPE]=ABZ_UVW, add by dino, 10/29/2007
		fnone   ,   //  94
		updatepr,	//	95 	15-95	record PG COUNTER at driver LV
		flashpr ,	//	96	15-96	AFM max. value
		flashpr ,	//	97	15-97	AFM min. value
		updatepr,	//	98	15-98	Softstart Delay Time
		fnone	,	//	99       
		updatepr,   //  100 15-100
		updatepr,   //  101 15-101
		updatepr,   //  102
		updatepr,   //  103
		fnone   ,   //  104
		fnone  	,	//	105
		updatepr,	//	106 15-106  CAN_CTRL  //[CAN Control, Sampo, 09/15/2010]
		updatepr,	//	107 15-107  CAN_FAULT //[CAN Control, Sampo, 09/15/2010]
		P15_108 ,	//	108
		updatepr,	//	109
		updatepr,	//	110
		updatepr,	//	111 15-111	WDT_DIV	//[ICT WDT test, Bernie, 08/16/2011]
	    updatepr,	//	112 15-112      AFM1 PWM 10 setting  
		updatepr,	//	113 15-113	AFM1 PWM 0 count setting  
		updatepr,	//	114 15-114	AFM1 PWM -10  setting  
		updatepr,	//	115 15-115      AFM2 PWM 10 setting  
		updatepr,	//	116 15-116	AFM2 PWM 0 count setting  
		updatepr,	//	117 15-117	AFM2 PWM -10  setting  
		P11_18  ,	//	118 15-118     The switch of Protect finction    //[The switch of Protect finction, Bernie, 2015/05/21]
		updatepr,	//	119                                                           //[Output Phase Loss 2, Sampo, 2015/05/21]
		updatepr,	//	120
		updatepr,	//	121 15-121  The Gain value of Protect finction     //[Output Phase Loss 2, Sampo, 2015/05/21]
		updatepr,	//	122
		updatepr,	//	123 15-123  MBF record after power off
		updatepr,	//	124         //[add for UL EoL Verification,Bernie, 2013/04/22]
		updatepr,	//	125         //[add for UL EoL Verification,Bernie, 2013/04/22]
		updatepr,	//	126
		fnone   ,	//	127

/*---- GROUP 00---------------------------------------*/
		P00_00	,	//	128	00-00	Model Type of Drive
		fnone	,	//	129	00-01	Rated Current
		P00_02	,	//	130	00-02	Parameter Reset
		P00_03	,	//	131	00-03	Start up Display
		P00_03	,	//	132	00-04	User Display
		P00_05	,	//	133	00-05	User Coefficient
		fnone	,	//	134	00-06	Software Version
		P00_07	,	//	135	00-07	Password Input
		P00_08	,	//	136	00-08	Password Input
		P00_09  ,	//	137	00-09	Control Methods
		updatepr,	//	138	00-10   Velocity Unit Select
		updatepr,	//	138	00-11   Change Output Direction, Added by sampo, 06/11/2009  // Delete CHGDIR Function, DINO, 08/02/2010
		P00_12	,	//	140	00-12	Carry Frequency
		updatepr,	//	141	00-13	AVR
		P00_14	,	//	142	00-14	Source of Freq. Command
		updatepr,	//	143	00-15	Source of Oper. Command

/*---- GROUP 01---------------------------------------*/
		P01_00	,	//	144	01-00	Max Output Freq.
		P01_01	,	//	145	01-01	Motor Base Frequency 1
		P01_02	,	//	146	01-02	Max Output Voltage
		updatepr,	//	147	01-03	Mid Output Freq.1
		updatepr,	//	148	01-04	Mid Output Voltage 1
		updatepr,	//	149	01-05	Mid Output Freq.2
		updatepr,	//	150	01-06	Mid Output Voltage 2
		P01_07	,	//	151	01-07	Min Output Freq.
		updatepr,	//	152	01-08	Min Output Voltage
		P01_07  ,	//	153	01-09	Start Frequency
		P01_10	,	//	154	01-10	Upper Bound Freq.
		P01_10	,	//	155	01-11	Lower Bound Freq.
		P01_10	,	//	156	01-12	1st Acceleration time
		P01_10	,	//	157	01-13	1st Deceleration time
		P01_10	,	//	158	01-14	2nd Acceleration time
		P01_10	,	//	159	01-15	2nd Deceleration time
		P01_10	,	//	160	01-16	3rd Acceleration time
		P01_10	,	//	161	01-17	3rd Deceleration time
		P01_10	,	//	162	01-18	4th Acceleration time
		P01_10	,	//	163	01-19	4th Deceleration time
		P01_10	,	//	164	01-20	JOG Acceleration time
		P01_10	,	//	165	01-21	JOG Deceleration time
		P01_10	,	//	166	01-22	JOG Frequency
		updatepr,	//	167	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
		updatepr,	//	168	01-24	S curve Accel time 1
		updatepr,	//	169	01-25	S curve Accel time 2
		updatepr,	//	170	01-26	S curve Decel time 1
		updatepr,	//	171	01-27	S curve Decel time 2
		updatepr,	//	172	01-28	Select Zero Speed	
		updatepr,	//	173	01-29	Landing Speed
		updatepr,	//	174	01-30	S curve Decel time 3
		P01_10	,	//	175	01-31	Stop Deceleration time
        updatepr,   //  176 01-32   FSD
        P01_33  ,   //  176 01-33   IODHT IO direct hold time
        P01_33  ,   //  176 01-34   IODLT IO direct landing time
        P01_33  ,   //  176 01-35   CRPLS_Jlim IO direct Jerk limit
        P01_33  ,   //  176 01-36   IODLT IO direct DistancE
        fnone   ,   //  176 01-37   IODLT IO direct DistancE reference
        updatepr,   //  174 01-38   IODLC ENABLE
        updatepr,   //  174 01-39   ETS Function //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
        P01_10,     //  175 01-40   ESD Function //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        P01_10  ,   //  286 03-83   SIBO_DECEMY  
        updatepr  ,   //  289 03-84   SIBO_S3EMY  
        updatepr  ,   //  290 03-85   SIBO_S4EMY  
#endif
/*---- GROUP 02---------------------------------------*/
		P02_00	,	//	176	02-00	2/3 wire control
		P02_01	,	//	177	02-01	Multi-Function Input 1
		P02_02	,	//	178	02-02	Multi-Function Input 2
		P02_02	,	//	179	02-03	Multi-Function Input 3
		P02_02	,	//	180	02-04	Multi-Function Input 4
		P02_02	,	//	181	02-05	Multi-Function Input 5
		P02_02	,	//	182	02-06	Multi-Function Input 6
		P02_02	,	//	183	02-07	Multi-Function Input 7
		P02_02	,	//	184	02-08	Multi-Function Input 8
		updatepr,	//	185	02-09	Digital in response time
		flashpr	,	//	186	02-10	Multi-Function Input Inverse
		P02_11,   	//	187	02-11	Multi-Function Relay 1
		P02_11,	    //	188	02-12	Multi-Function Relay 2
		P02_11,  	//	189	02-13	Multi-Function Output 1
		P02_11,	    //	190	02-14	Multi-Function Output 2
		P02_11,	    //	191	02-15	Multi-Function Output 3
		P02_11,	    //	192	02-16	Multi-Function Output 4
		P02_11,	    //	193	02-17	Multi-Function Output 5
		P02_11,	    //	194	02-18	Multi-Function Output 6
		P02_11,	    //	195	02-19	Multi-Function Output 7
		P02_11,	    //	196	02-20	Multi-Function Output 8
		fnone,	    //	197	02-21	Multi-Function Output 9
		fnone,	    //	198	02-22	Multi-Function Output 10
		flashpr	,	//	199	02-23	Multi-Function Output inverse
		updatepr,	//	200	02-24	Sequence start mode
		updatepr,	//	201	02-25	Desired Frequency 1
		updatepr,	//	202	02-26	Band of Desired Frequency 1
		updatepr,	//	203	02-27	Desired Frequency 2
		updatepr,	//	204	02-28	Band of Desired Frequency 2
		updatepr,	//	205	02-29	Brake Delay Timer Run 
		updatepr,	//	206	02-30	Brake Delay Timer Stop 
		updatepr,	//	207	02-31	Mech Contact Delay Timer Run
		updatepr,	//	208	02-32	Mech Contact Delay Timer STOP
		P02_33	,	//	209	02-33	Isum Current Output Detect
		updatepr,	//	210	02-34	Speed Area
		updatepr,	//	211	02-35	Mechanical Brake Checking Time
		updatepr,	//	212	02-36	Magnetic Contactor Checking Time
		updatepr,	//	213	02-37	Mechanical Brake Checking Current Enable
		updatepr,   //	2xx 02-38       Star Contactor delay time when driver run     //[Star contactor function, Bernie, 2017/03/22]
		updatepr,   //	2xx 02-39       Star Contactor delay time when driver stop   //[Star contactor function, Bernie, 2017/03/22]
		updatepr,	//	2xx 02-40	LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
		updatepr,	//	2xx 02-41	LD/LD OPEN Detect Time    //#15977, LULD detect, James, 2021/04/01
	    updatepr,	//	2xx 02-42	LD/LD SHORT Detect Time	  //#15977, LULD detect, James, 2021/04/01
		updatepr,	//	202 02-43	Band of Speed Agree Function //#18572   
		updatepr,   //	218 02-44 STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
		updatepr,	//  2xx 02-45	//[Artemis Add Sensor819 Function/Special/2022/06/06]
		updatepr,	//  2xx 02-46 //[Artemis Add Sensor819 Function/Special/2022/06/06]
/*---- GROUP 03---------------------------------------*/
		updatepr,	//	214  03-00	AVI selection
		updatepr,	//	215  03-01	ACI selection
		updatepr,	//	216  03-02	AUI selection
		updatepr,	//	217  03-03	AVI input Bias
		updatepr,	//	218  03-04	ACI input Bias
		updatepr,	//	219  03-05	AUI input Bias
		updatepr,	//	220  03-06	AVI input Polarity
		updatepr,	//	221  03-07	ACI input Polarity
		updatepr,	//	222  03-08	AUI input Polarity
		updatepr,	//	223  03-09	AVI input Gain
		updatepr,	//	224  03-10	ACI input Gain
		updatepr,	//	225  03-11	AUI input Gain
		LPFGain	,	//	226  03-12	Low pass filter of Analong input
		LPFGain	,	//	227  03-13	Low pass filter of Analong input
		LPFGain ,	//	228  03-14	Low pass filter of Analong input
		P03_15  ,	//	229  03-15	Loss of ACI
		flashpr ,	//	230  03-16	AD Calibration Flag
		updatepr,	//	231  03-17	Analog Output 1 Setting
		updatepr,	//	232  03-18	Analog Output 1 Gain
		updatepr,	//	233  03-19	AO1 in minus value
		updatepr,	//	234  03-20	Analog Output 1 Setting
		updatepr,	//	235  03-21	Analog Output 1 Gain
		updatepr,	//	236  03-22	AO1 in minus value
		updatepr,	//	237  03-23	AUI1 Input Polar
		updatepr,	//	238  03-24	AUI2 Input Polar
		//updatepr,	//	2XX  03-25      AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
		//updatepr,	//	2XX  03-26	AUI2 Communciate
        
/*---- GROUP 04-------------------------------------*/
        updatepr, //  239  04-00  Multi-Speed 0
        updatepr, //  240  04-01  Multi-Speed 1
        P01_33  , //  241  04-02  Multi-Speed 2 // [IODLC, Lyabryan, 2016/11/11]
        updatepr, //  242  04-03  Multi-Speed 3
        updatepr, //  243  04-04  Multi-Speed 4
        updatepr, //  244  04-05  Multi-Speed 5
        updatepr, //  245  04-06  Multi-Speed 6
        updatepr, //  246  04-07  Multi-Speed 7
        updatepr, //  247  04-08  Multi-Speed 8
        updatepr, //  248  04-09  Multi-Speed 9
        updatepr, //  249  04-10  Multi-Speed 10
        updatepr, //  250  04-11  Multi-Speed 11
        updatepr, //  251  04-12  Multi-Speed 12
        updatepr, //  252  04-13  Multi-Speed 13
        updatepr, //  253  04-14  Multi-Speed 14
        updatepr, //  254  04-15  Multi-Speed 15     
        
        updatepr, //  2XX 04-16   DLC Acceleration    //[DLC, Bernie, 2014/10/06] 
        updatepr, //  2XX 04-17   DLC Deceleration                   
        updatepr, //  2XX 04-18   Rescue Speed                                           
        updatepr, //  2XX 04-19   GFC Rope compensation, 2021/03/30                                
        updatepr, //  2XX 04-20   Re-Leveling Speed                                      
        updatepr, //  2XX 04-21   Forced Stop2 Deceleration (FSD)                                      
        updatepr, //  2XX 04-22                                          
        P04_23,   //  2XX 04-23   current lev   // mod cur lev writable, v0.03               
        updatepr, //  2XX 04-24                                                      
        updatepr, //  2XX 04-25   Landing Tolerance Delay Time                         
        updatepr, //  2XX 04-26   Leveling Plank Length                                
        updatepr, //  2XX 04-27   Maximum Floor                                        
        updatepr, //  2XX 04-28   Minimum Floor                                        
        updatepr, //  2XX 04-29   Inverter Target Floor 
        updatepr, //  2XX 04-30   RESERVE
        updatepr, //  2XX 04-31   RESERVE
        updatepr, //  2XX 04-32   RESERVE
        updatepr, //  2XX 04-33   RESERVE
         
        updatepr, //  2XX 04-34   RESERVE
        updatepr, //  2XX 04-35   RESERVE
        updatepr, //  2XX 04-36   RESERVE
        updatepr, //  2XX 04-37   RESERVE
        updatepr, //  2XX 04-38   RESERVE
        updatepr, //  2XX 04-39   RESERVE
        updatepr, //  2XX 04-40   DelayCmp//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
        updatepr, //  2XX 04-41   RESERVE
        updatepr, //  2XX 04-42   RESERVE
        updatepr, //  2XX 04-43   RESERVE
        updatepr, //  2XX 04-44   RESERVE
        //P04_45, //  2XX 04-45   RESERVE //jerk adj,Henry
        updatepr, //  2XX 04-45   DD1_Vlim //Artemis speed limit, James, 20200220
        updatepr, //  2XX 04-46   DD2_Vlim //Artemis speed limit, James, 20200220
        updatepr, //  2XX 04-47   DD3_Vlim //Artemis speed limit, James, 20200220
        updatepr, //  2XX 04-48   DD4_Vlim //Artemis speed limit, James, 20200220
        
        P04_49, //  2XX 04-49   User page
        
        // DLC position offset, Henry
        //#if DLCPOS     
        #if 1       //[adjust floor position adjust,Aevin,2018/06/19]
        P04_50, //  2XX 04-50   1Floor Position H                                  
        P04_50, //  2XX 04-51   1Floor Position L                                  
        P04_50, //  2XX 04-52   2Floor Position H                                  
        P04_50, //  2XX 04-53   2Floor Position L                                  
        P04_50, //  2XX 04-54   3Floor Position H                                  
        P04_50, //  2XX 04-55   3Floor Position L                                  
        P04_50, //  2XX 04-56   4Floor Position H                                  
        P04_50, //  2XX 04-57   4Floor Position L                                  
        P04_50, //  2XX 04-58   5Floor Position H                                  
        P04_50, //  2XX 04-59   5Floor Position L                                  
        P04_50, //  2XX 04-60   6Floor Position H                                  
        P04_50, //  2XX 04-61   6Floor Position L                                  
        P04_50, //  2XX 04-62   7Floor Position H                                  
        P04_50, //  2XX 04-63   7Floor Position L                                  
        P04_50, //  2XX 04-64   8Floor Position H                                  
        P04_50, //  2XX 04-65   8Floor Position L                                  
        P04_50, //  2XX 04-66   9Floor Position H                                  
        P04_50, //  2XX 04-67   9Floor Position L                                  
        P04_50, //  2XX 04-68   10Floor Position H                                 
        P04_50, //  2XX 04-69   10Floor Position L                                 
        P04_50, //  2XX 04-70   11Floor Position H                                 
        P04_50, //  2XX 04-71   11Floor Position L                                 
        P04_50, //  2XX 04-72   12Floor Position H                                 
        P04_50, //  2XX 04-73   12Floor Position L                                 
        P04_50, //  2XX 04-74   13Floor Position H                                 
        P04_50, //  2XX 04-75   13Floor Position L                                 
        P04_50, //  2XX 04-76   14Floor Position H                                 
        P04_50, //  2XX 04-77   14Floor Position L                                 
        P04_50, //  2XX 04-78   15Floor Position H                                 
        P04_50, //  2XX 04-79   15Floor Position L                                 
        P04_50, //  2XX 04-80   16Floor Position H                                 
        P04_50, //  2XX 04-81   16Floor Position L                                 
        P04_50, //  2XX 04-82   17Floor Position H                                 
        P04_50, //  2XX 04-83   17Floor Position L                                 
        P04_50, //  2XX 04-84   18Floor Position H                                 
        P04_50, //  2XX 04-85   18Floor Position L                                 
        P04_50, //  2XX 04-86   19Floor Position H                                 
        P04_50, //  2XX 04-87   19Floor Position L                                 
        P04_50, //  2XX 04-88   20Floor Position H                                 
        P04_50, //  2XX 04-89   20Floor Position L                                 
        P04_50, //  2XX 04-90   21Floor Position H                                 
        P04_50, //  2XX 04-91   21Floor Position L                                 
        P04_50, //  2XX 04-92   22Floor Position H                                 
        P04_50, //  2XX 04-93   22Floor Position L                                 
        P04_50, //  2XX 04-94   23Floor Position H                                 
        P04_50, //  2XX 04-95   23Floor Position L                                 
        P04_50, //  2XX 04-96   24Floor Position H                                 
        P04_50, //  2XX 04-97   24Floor Position L                                 
        P04_50, //  2XX 04-98   25Floor Position H                                 
        P04_50, //  2XX 04-99   25Floor Position L                           
        #else
        updatepr, //  2XX 04-50   1Floor Position H                                  
        updatepr, //  2XX 04-51   1Floor Position L                                  
        updatepr, //  2XX 04-52   2Floor Position H                                  
        updatepr, //  2XX 04-53   2Floor Position L                                  
        updatepr, //  2XX 04-54   3Floor Position H                                  
        updatepr, //  2XX 04-55   3Floor Position L                                  
        updatepr, //  2XX 04-56   4Floor Position H                                  
        updatepr, //  2XX 04-57   4Floor Position L                                  
        updatepr, //  2XX 04-58   5Floor Position H                                  
        updatepr, //  2XX 04-59   5Floor Position L                                  
        updatepr, //  2XX 04-60   6Floor Position H                                  
        updatepr, //  2XX 04-61   6Floor Position L                                  
        updatepr, //  2XX 04-62   7Floor Position H                                  
        updatepr, //  2XX 04-63   7Floor Position L                                  
        updatepr, //  2XX 04-64   8Floor Position H                                  
        updatepr, //  2XX 04-65   8Floor Position L                                  
        updatepr, //  2XX 04-66   9Floor Position H                                  
        updatepr, //  2XX 04-67   9Floor Position L                                  
        updatepr, //  2XX 04-68   10Floor Position H                                 
        updatepr, //  2XX 04-69   10Floor Position L                                 
        updatepr, //  2XX 04-70   11Floor Position H                                 
        updatepr, //  2XX 04-71   11Floor Position L                                 
        updatepr, //  2XX 04-72   12Floor Position H                                 
        updatepr, //  2XX 04-73   12Floor Position L                                 
        updatepr, //  2XX 04-74   13Floor Position H                                 
        updatepr, //  2XX 04-75   13Floor Position L                                 
        updatepr, //  2XX 04-76   14Floor Position H                                 
        updatepr, //  2XX 04-77   14Floor Position L                                 
        updatepr, //  2XX 04-78   15Floor Position H                                 
        updatepr, //  2XX 04-79   15Floor Position L                                 
        updatepr, //  2XX 04-80   16Floor Position H                                 
        updatepr, //  2XX 04-81   16Floor Position L                                 
        updatepr, //  2XX 04-82   17Floor Position H                                 
        updatepr, //  2XX 04-83   17Floor Position L                                 
        updatepr, //  2XX 04-84   18Floor Position H                                 
        updatepr, //  2XX 04-85   18Floor Position L                                 
        updatepr, //  2XX 04-86   19Floor Position H                                 
        updatepr, //  2XX 04-87   19Floor Position L                                 
        updatepr, //  2XX 04-88   20Floor Position H                                 
        updatepr, //  2XX 04-89   20Floor Position L                                 
        updatepr, //  2XX 04-90   21Floor Position H                                 
        updatepr, //  2XX 04-91   21Floor Position L                                 
        updatepr, //  2XX 04-92   22Floor Position H                                 
        updatepr, //  2XX 04-93   22Floor Position L                                 
        updatepr, //  2XX 04-94   23Floor Position H                                 
        updatepr, //  2XX 04-95   23Floor Position L                                 
        updatepr, //  2XX 04-96   24Floor Position H                                 
        updatepr, //  2XX 04-97   24Floor Position L                                 
        updatepr, //  2XX 04-98   25Floor Position H                                 
        updatepr, //  2XX 04-99   25Floor Position L            
        #endif   
                      
/*---- GROUP 05-------------------------------------*/
		P05_00	,	//	255  05-00	Motor Auto-Tuning
		P05_01	,	//	256  05-01	Motor 1 rated Current
		P05_02	,	//	257  05-02	Motor 1 Rated Power
		P05_03	,	//	258  05-03	Motor 1 Rated RPM
		P05_04	,	//	259  05-04	Motor 1 pole No.
		P05_05	,	//	260  05-05	Motor 1 No-Load Current
		P05_06	,	//	261  05-06	Motor 1 Rs
		P05_07	,	//	262  05-07	Motor 1 Rr
		P05_08	,	//	263  05-08	Motor 1 Lm
		P05_09	,	//	264  05-09	Motor 1 Lx
		LPFGain	,	//	265  05-10	Vector Voltage Filter
		LPFGain	,	//	266  05-11	Vector Slip Filter
		updatepr,	//	267  05-12	Torque Compensation Gain
		P15_02	,	//	268  05-13	Slip Compensation Gain
		updatepr,	//	269  05-14	Slip Deviation level
		updatepr,	//	270  05-15	Slip Deviation Detect Time
		updatepr,	//	271  05-16	Over Slip treatment
		updatepr,	//	272  05-17	Coeff for hunting disable
		P05_18	,	//	273  05-18	Accumulative Motor Operation Min
		P05_18	,	//	274  05-19	Accumulative Motor Operation Day
		updatepr,	//	275  05-20	Coreloss % of output Power
		updatepr,	//	276  05-21	Power On Min
		updatepr,	//	277  05-22	Power On Day		
        updatepr,   //  2XX  05-23  Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
        updatepr,   //  123
        
/*---- GROUP 06-------------------------------------*/
		P06_00	,	//    278   06-00	Low voltage level
		updatepr,	//    279   06-01	Phase loss
		updatepr,	//    280   06-02	OC stall during Accel
		updatepr,	//    281   06-03	OC stall during Decel
		updatepr,	//    282   06-04	Stall preventation Accel/Decel time selection
		updatepr,	//    283   06-05	Over-Torque 1 Selection
		updatepr,	//    284   06-06	Over-Torque 1 level
		updatepr,	//    285   06-07	Over-Torque 1 Time
		updatepr,	//    286   06-08	Over-Torque 2 Selection
		updatepr,	//    287   06-09	Over-Torque 2 level
		updatepr,	//    288   06-10	Over-Torque 2 Time
		updatepr,	//    289   06-11	Current Limit
		updatepr,	//    290   06-12	Thermal Relay 1 Selection
		updatepr,	//    291   06-13	Thermal Relay 1 Time
		updatepr,	//    292   06-14	OH Warning Level
		updatepr,	//    293   06-15	Stall preventation Limit Level
		P06_16	,	//    294   06-16	1st Fault Record
		P06_17	,	//    295   06-17	2nd Fault Record
		P06_17	,	//    296   06-18	3rd Fault Record
		P06_17	,	//    297   06-19	4th Fault Record
		P06_17	,	//    298   06-20	5th Fault Record
		P06_17	,	//    299   06-21	6th Fault Record
		updatepr,	//    300   06-22	Fault Option 1
		updatepr,	//    301   06-23	Fault Option 2
		updatepr,	//    302   06-24	Fault Option 3
		updatepr,	//    303   06-25	Fault Option 4
		updatepr,	//    304   06-26	PTC over Treatments
		updatepr,	//    305   06-27	PTC Level
		LPFGain ,	//    306   06-28	PTC Detect Filter time
		P06_00	,	//    307   06-29	EPS voltage level
		updatepr,	//    308   06-30	Fault Option Mode
		updatepr,	//    309   06-31	Motor Phase Detection Mode, Add by DINO, 05/12/2009
		fnone  	,	//    310   06-32	1st Fault Time(MIN)
		fnone  	,	//    311   06-33	1st Fault Time(DAY)
		fnone  	,	//    312   06-34	2nd Fault Time(MIN)
		fnone  	,	//    313   06-35	2nd Fault Time(DAY)
		fnone  	,	//    314   06-36	3rd Fault Time(MIN)
		fnone  	,	//    315   06-37	3rd Fault Time(DAY)
		fnone  	,	//    316   06-38	4th Fault Time(MIN)
		fnone  	,	//    317   06-39	4th Fault Time(DAY)
		fnone  	,	//    318   06-40	5th Fault Time(MIN)
		fnone  	,	//    319   06-41	5th Fault Time(DAY)
		fnone  	,	//    320   06-42	6th Fault Time(MIN)
		fnone  	,	//    321   06-43	6th Fault Time(DAY)
		updatepr,	//    322   06-44	EPS Frequency
		updatepr,	//    323   06-45	LV Option
		P06_46,	    //    324   06-46	EPS Option
		updatepr,	//    325   06-47   Generation Operation Deteced Time
		P06_00,		//    326   06-48	UPS Capacity (0.1KVA)
		updatepr,   //    3xx   06-49   STO Lock selection     //[Safty function, Bernie]
		updatepr,   //    3xx   06-50	Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
		P06_51,     //    3xx   06-51	Auto restart times after fault
		P06_52,     //    3xx   06-52   Auto restart interval
		fnone	,   //    99    06-53   Fkey Record     
		updatepr,	//    94    06-54   Fcmd Record, add by dino, 10/31/2007
        updatepr,   //    82    06-55   Isum Record
        updatepr,	//    79    06-56   Fout Record
        updatepr,	//    80    06-57   Vout Record
		updatepr,	//    81    06-58   Dcbus Record
		fnone	,	//    100   06-59   Power Record      
		fnone  	,	//    101   06-60   Torque Record  
		updatepr,	//    83    06-61   IGBT Temperature Record
		fnone  	,	//    102   06-62   MFI State Record  
		fnone  	,	//    103   06-63   MFO State Record  
		fnone  	,	//    104   06-64   Drive State Record
        updatepr,   //    3xx   06-65   Current limitation for UCMP function             //[UCMP function, Bernie, 2016/06/14]
        updatepr,   //    3xx   06-66   Service time count                                  //[Service time function, Bernie, 2017/03/14]
        P06_67  ,   //    3xx   06-67   Service time function Enable                      //[Service time function, Bernie, 2017/03/14]
        updatepr,   //    103   06-68   MFO State Record   //[EPS autodetect dir,Lyabryan,2018/07/02]
        fnone   ,   //    104   06-69   Drive State Record //[EPS autodetect dir,Lyabryan,2018/07/02]
        fnone   ,   //    103   06-70   MFO State Record   //[EPS autodetect dir,Lyabryan,2018/07/02]
        updatepr,   //    104   06-71   Drive State Record //[EPS MO Output,Lyabryan,2018/06/19]
        updatepr,   //    104   06-72   Drive State Record //[EPS MO Output,Lyabryan,2018/06/19]
		//[ //[Running Dir Count,Special,2018/08/17]
        fnone   ,   //    3xx   06-73   
        fnone   ,   //    3xx   06-74   
        fnone   ,   //    103   06-75   
        fnone   ,   //    104   06-76   
        fnone   ,   //    103   06-77   
        updatepr,   //    104   06-78   
        P06_79  ,   //    104   06-79  
        //] //[Running Dir Count,Special,2018/08/17]
        fnone    , //    104   06-80
        fnone    ,//    104   06-81
        fnone    ,//    104   06-82
        fnone    ,//    104   06-83
        fnone    ,//    104   06-84
        fnone    ,//    104   06-85
        fnone    ,//    104   06-86
        fnone    ,//    104   06-87
        fnone    ,//    104   06-88
        fnone    ,//    104   06-89
        fnone    ,//    104   06-90
        fnone    ,//    104   06-91
        fnone    ,//    104   06-92
        fnone    ,//    104   06-93
        fnone    ,//    104   06-94
        fnone    ,//    104   06-95
        fnone    ,//    104   06-96
        fnone    ,//    104   06-97
        fnone    ,//    104   06-98
        fnone    ,//    104   06-99
/*---- GROUP 07-------------------------------------*/
		P07_00  ,	//	327    07-00	SW Braking Level
		P07_00  ,	//	328    07-01	// [DCBRK_BAND function for adjustable reset level, James, 2019/12/05  ]  
		updatepr,	//	329    07-02	DCI Current Level
		updatepr,	//	330    07-03	DCI Time at Start 
		updatepr,	//	331    07-04	DCI Time at STOP
		updatepr,	//	332    07-05	DCI Freq. At start
		updatepr,	//	333    07-06	DCI KI
		updatepr,	//	334    07-07	Gear wait time when acceleration
		updatepr,	//	335    07-08	Gear wait frequency when acceleration
		updatepr,	//	336    07-09	Gear wait time when deceleration
		updatepr,	//	337    07-10	Gear wait frequency when deceleration
		updatepr,	//	338    07-11	Fan Control
		P07_12	,	//	339    07-12	TQC Reference from RS485
		updatepr,	//	340    07-13	Source of Torque Command
		P07_14	,	//	341    07-14	Torque max. level
		LPFGain	,	//	342    07-15	Torque command filter
		updatepr,	//	343    07-16	Speed Limit selection
		P07_17	,	//	344    07-17	Torque mode positive speed limit
		P07_17	,	//	345    07-18	Torque mode negative speed limit
		updatepr,	//	346    07-19	Torque offset selection
		updatepr,	//	347    07-20	Torque offset setting level
		//P07_21	,	//	348    07-21	Torque offset setting level High
		//P07_21	,	//	349    07-22	Torque offset setting level Middle
		//P07_21	,	//	350    07-23	Torque offset setting level Low
        updatepr,   //  348    07-21    Torque offset setting level High
        updatepr,   //  349    07-22    Torque offset setting level Middle
        updatepr,   //  350    07-23    Torque offset setting level Low
		updatepr,	//	351    07-24	FWD Motoring Tq Limit
		updatepr,	//	352    07-25	FWD Regeneration Tq Limit
		updatepr,	//	353    07-26	REV Motoring Tq Limit
		updatepr,	//	354    07-27	REV Regeneration Tq Limit
		updatepr,	//	355    07-28	Emergency Stop & Forced Stop selection
		updatepr,	//	356    07-29	Torque Decrease Time
		updatepr,   //  356    07-30    STOP DC Inject Level          //[DCI Level when stop, Bernie, 05/21/2012]
		updatepr,   //  356    07-31    //BTT100                //[JES Torq Detect Function, Special.Kung, 2022/09/01]
		updatepr,   //  356    07-32    //BTTx Detect           //[JES Torq Detect Function, Special.Kung, 2022/09/01]
		updatepr,   //  356    07-33    //BTTx Distance         //[JES Torq Detect Function, Special.Kung, 2022/09/01]
		updatepr,   //  356    07-34    //BTTx Detect Step      //[JES Torq Detect Function, Special.Kung, 2022/09/01]
		updatepr,   //  356    07-35    //BTTx Fail Torq        //[JES Torq Detect Function, Special.Kung, 2022/09/01]
		updatepr,   //  356    07-36    //BTTx Min Torq         //[JES Torq Detect Function, Special.Kung, 2022/09/01]
        updatepr,   //  356    07-37    //BTTx Min Torq         //[JES Torq Detect Function, Special.Kung, 2022/09/01]
        
/*---- GROUP 08-------------------------------------*/
		P08_00	,	//	357    08-00	PMotor Auto-Tuning
		P08_01	,	//	358    08-01	PMotor rated Current
		P08_02	,	//	359    08-02	PMotor Rated Power
		P08_03	,	//	360    08-03	PMotor Rated RPM
		P08_04	,	//	361    08-04	PMotor pole No.
		P08_05	,	//	362    08-05	PMotor Rs
		P08_06	,	//	363    08-06	PMotor Ld
		P08_06	,	//	364    08-07	PMotor Lq
		P08_01	,	//	365    08-08	PMotor Bemf coff
		P08_09	,	//	366    08-09	PM_VECTOR
		P08_10	,	//	367    08-10	StandStill Tune

/*---- GROUP 09--------------------------------------*/
		updatepr,	//	368    09-00	Comm Address
		P09_07	,	//	369    09-01	Tranmission speed
		updatepr,	//	370    09-02	Comm fault Treatment
		updatepr,	//	371    09-03	Comm Time out
		P09_07  ,	//	372    09-04	Comm Protocol
		updatepr,	//	373    09-05	ASC remote Response Delay Time, 1=100us
		P14_137 ,	//	3XX    09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
		updatepr,	//	3XX    09-07    CAN Communiction Timeout	 //[claer state when Error occur ,Bernie, 2015/05/12
		P14_138 ,	//	3XX    09-08    CAN PDO Handshaking Period //[claer state when Error occur ,Bernie, 2015/05/12
		updatepr,   //    3XX    09-09    Elevator Control Identification Code
        updatepr,   //    3XX    09-10    Factory Function
        updatepr,   //    3XX    09-11    RD Function
        updatepr,   //    3XX    09-12    DLC Mode
        updatepr,   //    3XX    09-13    
	    P09_14,	    //	  3XX	 09-14	

/*---- GROUP 10---------------------------------------*/
		P10_01	,	//	374    10-00	PG TYPE
		P10_01	,	//	375    10-01	Encoder pulses
		P10_01	,	//	376    10-02	PG input setting
		P10_03	,	//	377    10-03	PG fbk fault treatment
		P10_01	,	//	378    10-04	PG fbk Error Detection Time
		P10_01	,	//	379    10-05	PG fbk overspeed detection level
		updatepr,	//	380    10-06	Over speed Detection Time
		P10_01	,	//	381    10-07	PG fbk speed deviation level
		updatepr,	//	382    10-08	Deviation Detect Time
		updatepr,	//	383    10-09	Operation at overspeed
		updatepr,	//  384    10-10   Hall Input Types
		updatepr,	//	385    10-11	KP gain of ASR in Zero speed
		updatepr,	//	386    10-12	Ki gain of ASR in Zero speed
		updatepr,	//	387    10-13	ASR P Gain 1
		updatepr,	//	388    10-14	ASR I Gain 1
		updatepr,	//	389    10-15	ASR P Gain 2
		updatepr,	//	390    10-16	ASR I Gain 2
		P10_17	,	//	391    10-17	ASR1/ASR2 switch freq
		updatepr,	//	392    10-18	Primary LowPass filter Gain
		updatepr,	//  393    10-19 PPI P Gain
		P10_17	,	//	394    10-20 SPI1 Band
		updatepr,	//	395    10-21 SPI2 Band
		updatepr,	//	396    10-22	Primary LowPass filter Gain
		LPFGain,	//  397    10-23 PPI LPF Gain, Add by DINO, 07/28/2010
		updatepr,	//	398    10-24 Source of position control, add by dino, 06/30/2008
		updatepr,	//	399    10-25	KP gain of ASR in Zero speed of Landing, DINO, 08/02/2010
		updatepr,	//	400    10-26	Ki gain of ASR in Zero speed of Landing, DINO, 08/02/2010
		updatepr,	//	401    10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
		updatepr,	//	402    10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
        updatepr,   //    4xx    10-29     PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
        updatepr,   //    4xx    10-30     PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
        updatepr,   //[change parameter to normal group, Bernie, 2014/02/14]
        P10_32,     //    3XX  10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
        P10_33,     //    3XX  10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
        updatepr,   //    3XX  10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]

/*---- GROUP 11---------------------------------------*/
		updatepr,	//	401    11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo
		P11_02	,	//	402    11-01	Lift operation speed
		P11_02	,	//	403    11-02	SHEAVE_D
		P11_05	,	//	404    11-03	Gear Ratio
		P11_05  ,	//	405    11-04	Suspension	Ratio
		P11_05	,	//	406    11-05	JM_PERCENT
		updatepr,	//	407    11-06	Zero Speed Loop BandWidth
		updatepr,	//	408    11-07	Speed Loop BandWidth1
		updatepr,	//	409    11-08	Speed Loop BandWidth2
		updatepr,	//	410    11-09	PDFFKr
		updatepr,	//	411    11-10	SPDFFDGain
		P11_11	,	//	412    11-11	Netch filter deep(db)
		P11_11	,	//	413    11-12	Netch filter frequency
		LPFGain	,	//	414    11-13	Low Pass Filter for display
		P11_05	,	//	415    11-14	ACC Max current
		P11_05	,	//	416    11-15	Max meter per Sec
		P11_16	,	//	417    11-16	DATA_SEL
		updatepr,	//	418    11-17	SHOW_DATA
		P11_18  ,	//	419    11-18	Protect Bit
		updatepr,	//	420    11-19	Zero Speed Loop BandWidth of Landing, DINO, 08/02/2010
		updatepr,   //  4XX    11-20    PWM MODE, 0=SVPWM+DPWM,1=SVPWM   //[move parameter to 11-20, Bernie, 2017/02/16]
		LPFGain	,	//	414    11-21	Low Pass Filter for LC01
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
		fnone   ,   //  4XX    11-21    lift spd cmd for Sibocom, Jason, 2019/12/31
#endif
/*---- GROUP 12 --------------------------------------*/
		updatepr,	//	421    12-00	user define address	00
		updatepr,	//	422    12-01	user define address 01
		updatepr,	//	423    12-02	user define address 02
		updatepr,	//	424    12-03	user define address 03
		updatepr,	//	425    12-04	user define address 04
		updatepr,	//	426    12-05	user define address 05
		updatepr,	//	427    12-06	user define address 06
		updatepr,	//	428    12-07	user define address 07
		updatepr,	//	429    12-08	user define address 08
		updatepr,	//	430    12-09	user define address 09
		updatepr,	//	431    12-10	user define address 10
		updatepr,	//	432    12-11	user define address	11
		updatepr,	//	433    12-12	user define address 12
		updatepr,	//	434    12-13	user define address 13
		updatepr,	//	435    12-14	user define address 14
		updatepr,	//	436    12-15	user define address 15
		updatepr,	//	437    12-16	user define address 16
		updatepr,	//	438    12-17	user define address 17
		updatepr,	//	439    12-18	user define address 18
		updatepr,	//	440    12-19	user define address 19
		updatepr,	//	441    12-20	user define address 20
		updatepr,	//	442    12-21	user define address 21
		updatepr,	//	443    12-22	user define address 22
		updatepr,	//	444    12-23	user define address	23
		updatepr,	//	445    12-24	user define address 24
		updatepr,	//	446    12-25	user define address 25
		updatepr,	//	447    12-26	user define address 26
		updatepr,	//	448    12-27	user define address 27
		updatepr,	//	449    12-28	user define address 28
		updatepr,	//	450    12-29	user define address 29
		updatepr,	//	451    12-30	user define address 30
		updatepr,	//	452    12-31	user define address 31
		updatepr,	//	453    12-32	user define address 32
		updatepr,	//	454    12-33	user define address 33
		updatepr,	//	455    12-34	user define address 34
		updatepr,	//	456    12-35	user define address 35
		updatepr,	//	457    12-36	user define address 36
		updatepr,	//	458    12-37	user define address 37
		updatepr,	//	459    12-38	user define address 38
		updatepr,	//	460    12-39	user define address 39		
		updatepr,	//	461    12-40	user define address	40
		updatepr,	//	462    12-41	user define address 41
		updatepr,	//	463    12-42	user define address 42
		updatepr,	//	464    12-43	user define address 43
		updatepr,	//	465    12-44	user define address 44
		updatepr,	//	466    12-45	user define address 45
		updatepr,	//	467    12-46	user define address 46
		updatepr,	//	468    12-47	user define address 47
		updatepr,	//	469    12-48	user define address 48
		updatepr,	//	470    12-49	user define address 49
		updatepr,	//	471    12-50	user define address	50
		updatepr,	//	472    12-51	user define address 51
		updatepr,	//	473    12-52	user define address 52
		updatepr,	//	474    12-53	user define address 53
		updatepr,	//	475    12-54	user define address 54
		updatepr,	//	476    12-55	user define address 55
		updatepr,	//	477    12-56	user define address 56
		updatepr,	//	478    12-57	user define address 57
		updatepr,	//	479    12-58	user define address 58
		updatepr,	//	480    12-59	user define address 59
		updatepr,	//	481    12-60	user define address	60
		updatepr,	//	482    12-61	user define address 61
		updatepr,	//	483    12-62	user define address 62
		updatepr,	//	484    12-63	user define address 63
		updatepr,	//	485    12-64	user define address 64
		updatepr,	//	486    12-65	user define address 65
		updatepr,	//	487    12-66	user define address 66
		updatepr,	//	488    12-67	user define address 67
		updatepr,	//	489    12-68	user define address 68
		updatepr,	//	490    12-69	user define address 69
		updatepr,	//	491    12-70	user define address	70
		updatepr,	//	492    12-71	user define address 71
		updatepr,	//	493    12-72	user define address 72
		updatepr,	//	494    12-73	user define address 73
		updatepr,	//	495    12-74	user define address 74
		updatepr,	//	496    12-75	user define address 75
		updatepr,	//	497    12-76	user define address 76
		updatepr,	//	498    12-77	user define address 77
		updatepr,	//	499    12-78	user define address 78
		updatepr,	//	500    12-79	user define address 79
		updatepr,	//	501    12-80	user define address	80
		updatepr,	//	502    12-81	user define address 81
		updatepr,	//	503    12-82	user define address 82
		updatepr,	//	504    12-83	user define address 83
		updatepr,	//	505    12-84	user define address 84
		updatepr,	//	506    12-85	user define address 85
		updatepr,	//	507    12-86	user define address 86
		updatepr,	//	508    12-87	user define address 87
		updatepr,	//	509    12-88	user define address 88
		updatepr,	//	510    12-89	user define address 89
		updatepr,	//	511    12-90	user define address	90
		updatepr,	//	512    12-91	user define address 91
		updatepr,	//	513    12-92	user define address 92
		updatepr,	//	514    12-93	user define address 93
		updatepr,	//	515    12-94	user define address 94
		updatepr,	//	516    12-95	user define address 95
		updatepr,	//	517    12-96	user define address 96
		updatepr,	//	518    12-97	user define address 97
		updatepr,	//	519    12-98	user define address 98
		updatepr,	//	520    12-99	user define address 99

/*---- GROUP 13 --------------------------------------*/
		fnone	,	//	453    13-00	user address mapping data 00
		fnone	,	//	454    13-01	user address mapping data 01
		fnone	,	//	455    13-02	user address mapping data 02
		fnone	,	//	456    13-03	user address mapping data 03
		fnone	,	//	457    13-04	user address mapping data 04
		fnone	,	//	458    13-05	user address mapping data 05
		fnone	,	//	459    13-06	user address mapping data 06
		fnone	,	//	460    13-07	user address mapping data 07
		fnone	,	//	461    13-08	user address mapping data 08
		fnone	,	//	462    13-09	user address mapping data 09
		fnone	,	//	463    13-10	user address mapping data 10
		fnone	,	//	464    13-11	user address mapping data 11
		fnone	,	//	465    13-12	user address mapping data 12
		fnone	,	//	466    13-13	user address mapping data 13
		fnone	,	//	467    13-14	user address mapping data 14
		fnone	,	//	468    13-15	user address mapping data 15
		fnone	,	//	469    13-16	user address mapping data 16
		fnone	,	//	470    13-17	user address mapping data 17
		fnone	,	//	471    13-18	user address mapping data 18
		fnone	,	//	472    13-19	user address mapping data 19
		fnone	,	//	473    13-20	user address mapping data 20
		fnone	,	//	474    13-21	user address mapping data 21
		fnone	,	//	475    13-22	user address mapping data 22
		fnone	,	//	476    13-23	user address mapping data 23
		fnone	,	//	477    13-24	user address mapping data 24
		fnone	,	//	478    13-25	user address mapping data 25
		fnone	,	//	479    13-26	user address mapping data 26
		fnone	,	//	480    13-27	user address mapping data 27
		fnone	,	//	481    13-28	user address mapping data 28
		fnone	,	//	482    13-29	user address mapping data 29
		fnone	,	//	483    13-30	user address mapping data 30
		fnone	,	//	484    13-31	user address mapping data 31
		fnone	,	//	455    13-32	user address mapping data 32
		fnone	,	//	456    13-33	user address mapping data 33
		fnone	,	//	457    13-34	user address mapping data 34
		fnone	,	//	458    13-35	user address mapping data 35
		fnone	,	//	459    13-36	user address mapping data 36
		fnone	,	//	460    13-37	user address mapping data 37
		fnone	,	//	461    13-38	user address mapping data 38
		fnone	,	//	462    13-39	user address mapping data 39		
		fnone	,	//	453    13-40	user address mapping data 40
		fnone	,	//	454    13-41	user address mapping data 41
		fnone	,	//	455    13-42	user address mapping data 42
		fnone	,	//	456    13-43	user address mapping data 43
		fnone	,	//	457    13-44	user address mapping data 44
		fnone	,	//	458    13-45	user address mapping data 45
		fnone	,	//	459    13-46	user address mapping data 46
		fnone	,	//	460    13-47	user address mapping data 47
		fnone	,	//	461    13-48	user address mapping data 48
		fnone	,	//	462    13-49	user address mapping data 49
		fnone	,	//	453    13-50	user address mapping data 50
		fnone	,	//	454    13-51	user address mapping data 51
		fnone	,	//	455    13-52	user address mapping data 52
		fnone	,	//	456    13-53	user address mapping data 53
		fnone	,	//	457    13-54	user address mapping data 54
		fnone	,	//	458    13-55	user address mapping data 55
		fnone	,	//	459    13-56	user address mapping data 56
		fnone	,	//	460    13-57	user address mapping data 57
		fnone	,	//	461    13-58	user address mapping data 58
		fnone	,	//	462    13-59	user address mapping data 59
		fnone	,	//	453    13-60	user address mapping data 60
		fnone	,	//	454    13-61	user address mapping data 61
		fnone	,	//	455    13-62	user address mapping data 62
		fnone	,	//	456    13-63	user address mapping data 63
		fnone	,	//	457    13-64	user address mapping data 64
		fnone	,	//	458    13-65	user address mapping data 65
		fnone	,	//	459    13-66	user address mapping data 66
		fnone	,	//	460    13-67	user address mapping data 67
		fnone	,	//	461    13-68	user address mapping data 68
		fnone	,	//	462    13-69	user address mapping data 69
		fnone	,	//	453    13-70	user address mapping data 70
		fnone	,	//	454    13-71	user address mapping data 71
		fnone	,	//	455    13-72	user address mapping data 72
		fnone	,	//	456    13-73	user address mapping data 73
		fnone	,	//	457    13-74	user address mapping data 74
		fnone	,	//	458    13-75	user address mapping data 75
		fnone	,	//	459    13-76	user address mapping data 76
		fnone	,	//	460    13-77	user address mapping data 77
		fnone	,	//	461    13-78	user address mapping data 78
		fnone	,	//	462    13-79	user address mapping data 79
		fnone	,	//	453    13-80	user address mapping data 80
		fnone	,	//	454    13-81	user address mapping data 81
		fnone	,	//	455    13-82	user address mapping data 82
		fnone	,	//	456    13-83	user address mapping data 83
		fnone	,	//	457    13-84	user address mapping data 84
		fnone	,	//	458    13-85	user address mapping data 85
		fnone	,	//	459    13-86	user address mapping data 86
		fnone	,	//	460    13-87	user address mapping data 87
		fnone	,	//	461    13-88	user address mapping data 88
		fnone	,	//	462    13-89	user address mapping data 89
		fnone	,	//	453    13-90	user address mapping data 90
		fnone	,	//	454    13-91	user address mapping data 91
		fnone	,	//	455    13-92	user address mapping data 92
		fnone	,	//	456    13-93	user address mapping data 93
		fnone	,	//	457    13-94	user address mapping data 94
		fnone	,	//	458    13-95	user address mapping data 95
		fnone	,	//	459    13-96	user address mapping data 96
		fnone	,	//	460    13-97	user address mapping data 97
		fnone	,	//	461    13-98	user address mapping data 98
		fnone	,	//	462    13-99	user address mapping data 99

/*---- GROUP 14---------------------------------------*/
		updatepr,	//	485    14-00	Ids Power Save Level
		updatepr,	//	486    14-01	VF voltage mode selection
		P14_02	,	//	487    14-02	Constant Torque Selection
		updatepr,	//	488    14-03	Auto Accel/Decel
		P14_04  ,	//	489    14-04	Unit of Acc/Dec time
		updatepr,	//	490    14-05	Power Save mode
		updatepr,	//	491    14-06	Stop Methods
		P14_07	,	//	492    14-07	Reverse Operation
		P14_08	,	//	493    14-08	Skip Freq. Point 1 upper limit
		P14_08	,	//	494    14-09	Skip Freq. Point 1 lower limit
		P14_08	,	//	495    14-10	Skip Freq. Point 2 upper limit
		P14_08	,	//	496    14-11	Skip Freq. Point 2 lower limit
		P14_08	,	//	497    14-12	Skip Freq. Point 3 upper limit
		P14_08	,	//	498    14-13	Skip Freq. Point 3 lower limit
		P01_01	,	//	499    14-14	Motor Base Frequency 2
		P01_02	,	//	500    14-15	Max Output Voltage 2
		updatepr,	//	501    14-16	Mid Output Freq.2 1
		updatepr,	//	502    14-17	Mid Output Voltage 2 1
		updatepr,	//	503    14-18	Mid Output Freq.2 2
		updatepr,	//	504    14-19	Mid Output Voltage 2 2
		P01_07	,	//	505    14-20	Min Output Freq. 2
		updatepr,	//	506    14-21	Min Output Voltage 2
		updatepr,	//	507    14-22	up/down key mode
		updatepr,	//	508    14-23	up/down key speed
		updatepr,	//	509    14-24	Counter Value Set (Complete)
		updatepr,	//	510    14-25	Counter Value Reach (Preset)
		updatepr,	//	511    14-26	LIMIT_SCALE    //[weak magnet, Sampo, 03/31/2011]
		P02_02	,	//	512    14-27	Multi-Function Input 9
		P02_02	,	//	513    14-28	Multi-Function Input 10
		P02_02	,	//	514    14-29	Multi-Function Input 11
		P02_02	,	//	515    14-30	Multi-Function Input 12
		P02_02	,	//	516    14-31	Multi-Function Input 13
		P02_02	,	//	517    14-32	Multi-Function Input 14
		updatepr,	//	518    14-33	External Terminal Run after Fault Reset
		updatepr,	//	519    14-34	ACI change to AVI2
		updatepr,	//	520    14-35	Addition Function of AI
		updatepr,	//	521    14-36	Multi-Position Point 1
		updatepr,	//	522    14-37	Multi-Position Point 2
		updatepr,	//	523    14-38	Multi-Position Point 3
		updatepr,	//	524    14-39	Multi-Position Point 4
		updatepr,	//	525    14-40	Multi-Position Point 5
		updatepr,	//	526    14-41	Multi-Position Point 6
		updatepr,	//	527    14-42	Multi-Position Point 7
		updatepr,	//	528    14-43	Multi-Position Point 8
		updatepr,	//	529    14-44	Multi-Position Point 9
		updatepr,	//	530    14-45	Multi-Position Point 10
		updatepr,	//	531    14-46	Multi-Position Point 11
		updatepr,	//	532    14-47	Multi-Position Point 12
		updatepr,	//	533    14-48	Multi-Position Point 13
		updatepr,	//	534    14-49	Multi-Position Point 14
		updatepr,	//	535    14-50	Multi-Position Point 15
		P14_51	,	//	536    14-51	Motor Selection 1 or 2
		updatepr,	//	537    14-52	Y-Delta Connected switching rpm
		P14_53	,	//	538    14-53	Y-Delta switched Enable
		P05_01	,	//	539    14-54	Motor 2 rated Current
		P05_02	,	//	540    14-55	Motor 2 Rated Power
		P05_03	,	//	541    14-56	Motor 2 Rated RPM
		P05_04	,	//	542    14-57	Motor 2 pole No.
		P05_05	,	//	543    14-58	Motor 2 No-Load Current
		P05_06	,	//	544    14-59	Motor 2 Rs
		P05_07	,	//	545    14-60	Motor 2 Rr
		P05_08	,	//	546    14-61	Motor 2 Lm
		P05_09	,	//	547    14-62	Motor 2 Lx
		updatepr,	//	548    14-63	Y-Delta On delay time
		P14_64	,	//	549    14-64	OV stall level
		updatepr,	//	550    14-65	Thermal Relay 2 Selection
		updatepr,	//	551    14-66	Thermal Relay 2 Time
		updatepr,	//	552    14-67	Momentary Power Loss
		P14_68	,	//	553    14-68	Max. allowable PL time
		P14_68	,	//	554    14-69	BB Time for speed serach
		updatepr,	//	555    14-70	Current level for SPD serach
		updatepr,	//	556    14-71	bb treatment for oc, ov, bb
		updatepr,	//	557    14-72	Auto restart after fault
		updatepr,	//	558    14-73	Auto restart Speed serach method
		updatepr,	//	559    14-74	Deceleration at Momertary Power loss 
		updatepr,	//	560    14-75	KEB Return Time
		updatepr,	//	561    14-76	PID feedback selection
		updatepr,	//	562    14-77	P gain of PID
		updatepr,	//	563    14-78	I gain of PID
		updatepr,	//	564    14-79	D gain of PID
		updatepr,	//	565    14-80	Upper bound for integral
		updatepr,	//	566    14-81	PID output Freq. Limit
		P14_82	,	//	567    14-82	PID offset
		LPFGain	,	//	568    14-83	Derivative Filter Time Constant
		updatepr,	//	569    14-84	Feedback signal detection time
		updatepr,	//	570    14-85	PID feedback loss
		updatepr,	//	571    14-86	Sleep Frequency
		updatepr,	//	572    14-87	Wake up Frequency
		updatepr,	//	573    14-88	Sleep Time
		updatepr,	//	574    14-89	PID Deviation Level
		updatepr,	//	575    14-90	PID Deviation Time
		updatepr,	//	576    14-91	PID feedback filter
		P14_92  ,	//	577    14-92	Main Frequency from communication
		P14_93  ,	//	578    14-93	Block Transfer 1
		P14_93  ,	//	579    14-94	Block Transfer 2
		P14_93  ,	//	580    14-95	Block Transfer 3
		P14_93  ,	//	581    14-96	Block Transfer 4
		P14_93  ,	//	582    14-97	Block Transfer 5
		P14_93  ,	//	583    14-98	Block Transfer 6
		P14_93  ,	//	584    14-99	Block Transfer 7
		P14_93  ,	//	585    14-100	Block Transfer 8
		P14_93  ,	//	586    14-101	Block Transfer 9
		P14_93  ,	//	587    14-102	Block Transfer 10
		updatepr,	//	588    14-103	WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
		updatepr,	//	589    14-104	WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
		updatepr,	//	590    14-105	OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
		flashpr	,	//	591    14-106	PG Position Control Point (Home)
		updatepr,	//	592    14-107	Range for PG Position Attained
		updatepr,	//	593    14-108	Gain of APR feedforward
		P01_10	,	//	594    14-109	Decelerate time of APR
		updatepr,	//	595    14-110	FMax Target by Vcommand Position
		updatepr,	//	596    14-111	Accel. Time for Position
		P14_112	,	//	597    14-112	PG Mechanical Gear A
		P14_112	,	//	598    14-113	PG Mechanical Gear B
		P14_114	,	//	599    14-114	Interia of motor PU
		updatepr,	//	600    14-115	Motor1 IdsRef Limit
		updatepr,	//	601    14-116	Motor2 IdsRef Limit
		LPFGain,	//	602    14-117	Phase Loss Time
		P14_118	,	//	603    14-118	Thermo inside Temp
		updatepr,	//	604    14-119	Speed feed forword
		updatepr,	//	605    14-120	SVC Slip Generation Compensation Gain //6a02j
		LPFGain	,	//	606    14-121	PG2 Command Low pass Filter Gain
		P14_122	,	//	607    14-122	Tension of Torque Control
		P14_122	,	//	608    14-123	Diameter of Material
		updatepr,	//	609    14-124	Depth of meterial
		updatepr,	//	610    14-125	Safety Relay Record
		updatepr,	//	611    14-126	The interval between pulse time
		updatepr,	//	612    14-127	Pulse duty
		P06_17	,	//	613    14-128	Timer of Phase loss (hour)
		updatepr,	//	614    14-129	Time of APR Curve
		P11_05	,	//	615    14-130	Jm calculation select
		P14_131	,	//	616    14-131	Level of Phase Loss
		updatepr,	//	617    14-132	Virtual MI State
		P14_133 ,	//	618    14-133	Standstill Current
		P10_10	,	//	619    14-134   Division factor of PG
		fnone	,	//	620    14-135	Motor Base Frequency 1
		P14_136 ,	//	617    14-136	// [CAN Protocol for High Cap , Sampo,  2011/09/05]
		P14_137 ,	//	617    14-137	// [CAN Protocol for High Cap , Sampo,  2011/09/05]
		P14_138 ,	//	617    14-138	// [CAN Protocol for High Cap, Bernie, 09/22/2011] 
		updatepr,	//	617    14-139	// [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	    updatepr,	//	368    14-140  09-00	Comm Address      //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]
		P09_01	,	//	369    14-141  09-01	Tranmission speed
		updatepr,	//	370    14-142  09-02	Comm fault Treatment
		updatepr,	//	371    14-143  09-03	Comm Time out
		P09_01  ,	//	372    14-144  09-04	Comm Protocol
		updatepr,	//	373    14-145  09-05	ASC remote Response Delay Time, 1=100us
		updatepr,   //    3XX    14-146
		updatepr,   //    3XX    14-147
		updatepr,   //    3XX    14-148
		updatepr,   //    3XX    14-149
		updatepr,   //    3XX    14-150
		updatepr,   //    3XX    14-151
		updatepr,   //    3XX    14-152
		updatepr,   //    3XX    14-153
};

UWORD maxcf(UWORD model)
{
  UBYTE HPSPEC_temp;           
    
    HPSPEC_temp = pr[HPSPEC];         //[Single phase input, Bernie, 01/19/2012]
    if(HPSPEC_temp>VFD_SINGLEPHASE)
        HPSPEC_temp -= VFD_SINGLEPHASE;

    //if (pr[HPSPEC]<=VFD220V43A){    //1~5Hp,7.5~30Hp, 23	,modify SCOTTY 2007/07/20 
    if (HPSPEC_temp<=VFD220V43A){
//    	if (VH_EN==1)
//           return(22);   //22k
//        else
            return(15);   //15k, dino, 05/22/2007
    }
    //else if(pr[HPSPEC]<=VFD450V43A) //30~60Hp, 29
    else if(HPSPEC_temp<=VFD450V43A) //30~60Hp, 29
        return(9);   // 9k
    else                            //75~100Hp
        return(6);   // 6k
}

UWORD GetParMax(UWORD prx)
{
    UWORD ax, uwPRMax;
    UBYTE HPSPEC_temp;     //[Single phase input, Bernie, 01/19/2012]

    HPSPEC_temp = pr[HPSPEC];   //[Single phase input, Bernie, 01/19/2012]
    if(pr[HPSPEC] > VFD_SINGLEPHASE)
        HPSPEC_temp -= VFD_SINGLEPHASE;

    switch (prx) {
        case PRRESET:
            if ((SHOW_ALLPR==1)||(SHOW_ENHANCE==1))
              ax = 65535;
            else
              ax = 10;
            break;
            
        case PWM_MODE:             //[move parameter to 11-20, Bernie, 2017/02/16]
		case PG_C_TYPE:
            if ((SHOW_ALLPR==1)||(SHOW_ENHANCE==1))
              ax = 65535;
            else
              ax = 1;
            break;

        case SETCRF:
            if(pr[HPSPEC]>VFD_SINGLEPHASE)  //[Single phase input, Bernie, 01/19/2012]
                ax = maxcf(pr[HPSPEC]-VFD_SINGLEPHASE);
            else
                ax = maxcf(pr[HPSPEC]);
            break;

    	case VMAX1:
    	case VMID1_1:
    	case VMID1_2:
    	case VMIN1:    
    	case LVL:
    	case STALL4V:
    	case VEPS:
    	case DCBRK4V:
    	case VMAX2:
    	case VMID2_1:
    	case VMID2_2:
    	case VMIN2:
    	case PHL_L:
    	    if ((pr[HPSPEC]&VFD440V)==VFD220V)    // 220V class
    	    	ax = attr[prx].max >> 1;
    	    else
    	        ax = attr[prx].max;
    	    break;
     //Gfc DLC modify , Henry, 2018/05/23
//        case SOFC:
//            if(SHOW_DLCSOFC) //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
//              //ax = 4;
//              ax = 5;
//            else
//              ax = 3;
//                
//
//        break;

//============ Create for DLC function ============//
    	case ACCEL1:
    	case DECEL1:
    	case JOGACC:
    	case JOGDEC: 	
        	//Gfc DLC modify , Henry, 2018/05/23
          if((pr[SOFC]==4)||(pr[SOFC]==5)){ //[Gfc DLC modify,Henry,2018/05/23]
    	        ax = 150;  //Dot 2  1.5 m/s^2  
    	    }
    	    else{
        	    if (pr[U_ACCDEC]==0)
        	        ax = attr[prx].max;
                else
                    ax = attr[prx].max/10;
            }
                
    	    break;

        case DECEL5:
        	//Gfc DLC modify , Henry, 2018/05/23
          if((pr[SOFC]==4)||(pr[SOFC]==5)){ //[Gfc DLC modify,Henry,2018/05/23]
    	        ax = 0; //Dot 2  0.00 m/s
    	    }
    	    else{
        	    if (pr[U_ACCDEC]==0)
        	        ax = attr[prx].max;
                else
                    ax = attr[prx].max/10;
            }
                
    	    break;

        case JOGF:
        	//Gfc DLC modify , Henry, 2018/05/23
          if((pr[SOFC]==4)||(pr[SOFC]==5)){ //[Gfc DLC modify,Henry,2018/05/23]
    	        ax = 600; //Dot 2  6.00 m/s
    	    }
    	    else{
        	    if (VH_EN==1)
                   	ax = VH_F3600;
                else
                    ax = attr[prx].max;
            }
        	break;
        	
//========================================//
        	
    	//case ACCEL1:        //[move to upside for DLC function, Bernie, 2016/01/26]
    	//case DECEL1:        //[move to upside for DLC function, Bernie, 2016/01/26]
    	case ACCEL2:
    	case DECEL2:
    	case ACCEL3:
    	case DECEL3:
    	case ACCEL4:
    	case DECEL4:
    	//case JOGACC:        //[move to upside for DLC function, Bernie, 2016/01/26]
    	//case JOGDEC:        //[move to upside for DLC function, Bernie, 2016/01/26]
    	case S4ACC1:
    	case S4ACC2:
    	case S4DEC1:
    	case S4DEC2:
    	case S4DEC3:
        case DECEL_ESD:       //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
    	//case DECEL5:        //[move to upside for DLC function, Bernie, 2016/01/26]
    	case APRDECT:
        //[ //[Sibocom acc/dec,Lyabryan,2019/11/12]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        case SIBO_DECEMY:
#endif
        //] //[Sibocom acc/dec,Lyabryan,2019/11/12]
    	    if (pr[U_ACCDEC]==0)
    	        ax = attr[prx].max;
            else
                ax = attr[prx].max/10;
    	    break;

      	case AUTO_T:
      		if (SHOW_ALLPR==1)
      			ax = attr[AUTO_T].max;
      		else
#if !SH7147  /* scotty, 06/06/2007 */
      			ax = 6;
#else
      			ax = 2;
#endif
      		break;

        case MI_RAT1:
        case PM_MI_RAT:
		case MI_RAT2:
				if ((pr[PROTBIT]&0x0800)==0x0800){	// Bit 11: rated amps of motor
					//if (pr[HPSPEC]<=VFD550V43A){
					if (HPSPEC_temp <= VFD550V43A){
                        if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                            ax = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE+2];
                        else
						    ax = CTispec[pr[HPSPEC]+2];
                    }
					else
	                	ax = pr[I_RATE];
	            }
	            else{
	            	ax = ((ULONG)pr[I_RATE] * 150 / 100);  //Sean fuck you write by Bernie
				}
            break;
        case MI_NL1:
                ax = pr[MI_RAT1];
            break;
        case MI_NL2:
                ax = pr[MI_RAT2];
            break;

        case FMAX:
        case MFBASE1:
        case FMID1_1:
        case FMID1_2:
        case FMIN1:
        case MFBASE2:
        case FMID2_1:
        case FMID2_2:
        case FMIN2:
        case FSTART:
        //case JOGF:          //[move to upside for DLC function, Bernie, 2016/01/26]
        case FUPPER:
        case FLOWER:
        case FSKIP1H:
        case FSKIP1L:        
        case FSKIP2H:
        case FSKIP2L:
        case FSKIP3H:
        case FSKIP3L:
        case UPDNKEYS:
        case DESIRE_F1:
        case DESIRE_F1B:
        case DESIRE_F2:
        case DESIRE_F2B:
#if !SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        case FMI0:
        case FMI1:
        case FMI2:
        case FMI3:
        case FMI4:
        case FMI5:
        case FMI6:
#endif
        case FMI7:
        case FMI8:
        case FMI9:
        case FMI10:
        case FMI11:
        case FMI12:
        case FMI13:
        case FMI14:
        case FMI15:
        case YDSWRPM:
        case GEAR_ACCF:
        case GEAR_DECF:
        case DCIFSTA:
        case SLEEPF:
        case WAKEF:
        case ASR_F1:
        case DBCCHG_F:
        case FMAIN:
            if (VH_EN==1)
               	ax = VH_F3600;
            else
                ax = attr[prx].max;
        	break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        case FMI0:
        case FMI1:
        case FMI2:
        case FMI3:
        case FMI4:
        case FMI5:
        case FMI6:
               	ax = 6;
        break;
#endif
        case PMI1:
        case PMI2:
        case PMI3:
        case PMI4:
        case PMI5:
        case PMI6:
        case PMI7:
        case PMI8:
        case PMI9:
        case PMI10:
        case PMI11:
        case PMI12:
        case PMI13:
        case PMI14:
        case PMI15:
		case PGHOME:
	    	ax = SpDt_ulPG1NpulseNoMx;
	    	break;
        case STO_LOCK:
            if(btArtemisEnable)
            {
                ax = 0x000F;
            }
            else
            {
    	        ax = 3;
            }
	    	break; 

        default:
            ax = attr[prx].max;
            break;
    }

	// [ Change Maximum Data of Velocity Unit, Add by DINO, 05/25/2009
	/*---------------------------- [ Maximum Velocity Data ] ----------------------------
	--  pr[UNITSEL] = 0: Hz  : attr[ax].max;
	--              = 1: m/s : attr[Lift_SPD].max;
	--              = 2: ft/s: attr[Lift_SPD].max * 3.28;
	--
	--  3.28 = 13435 / 4096
	-----------------------------------------------------------------------------------*/
    	if ((attr[prx].ati&CHG) == CHG){
    		// Maximum Value of m/s
    		//[ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
    		if ((pr[UNITSEL] == 1) && (prx != Lift_SPD) && (prx != Max_MperS)){
    			if(((prx == ACCEL1) || (prx == DECEL1) || (prx == ACCEL2)	  // m/s2
    				|| (prx == DECEL2) || (prx == ACCEL3) || (prx == DECEL3)
    				|| (prx == ACCEL4) || (prx == DECEL4) || (prx == JOGACC)
    				|| (prx == JOGDEC) || (prx == DECEL5))
    				&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
    				if(pr[U_ACCDEC] == 0){
    					ax = ACC_UnitConv(attr[prx].min, 0);
    				}
    				else{
    					ax = ACC_UnitConv(attr[prx].min/10, 0);
    				}
    			}
    			else if(((prx == S4ACC1) || (prx == S4ACC2) || (prx == S4DEC1) // m/s3
    					|| (prx == S4DEC2) || (prx == S4DEC3))
    					&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
    					if(pr[U_ACCDEC] == 0){
    						ax = SCurve_UnitConv(prx, attr[prx].min, 0);
    					}
    					else{
    						ax = SCurve_UnitConv(prx, attr[prx].min/10, 0);
    					}					
    			}
    			else{
    				ax = flHz2Metric(MAXF);	// m/s
    			}
    		}
    		// Maximum Value of ft/s
    		else if(pr[UNITSEL] == 2){
    			if (prx == Lift_SPD){
    				uwPRMax = attr[Lift_SPD].max;	// m/s
    			}
    			else if (prx == Max_MperS){
    				uwPRMax = attr[Max_MperS].max;	// m/s
    			}
    			else{
    				uwPRMax = flHz2Metric(MAXF);		// Hz->m/s
    			}
    			ax = ((ULONG)uwPRMax * 13435 + 2048) >> 12;	// m/s->ft/s
    			if(((prx == ACCEL1) || (prx == DECEL1) || (prx == ACCEL2)	  // ft/s2
    				|| (prx == DECEL2) || (prx == ACCEL3) || (prx == DECEL3)
    				|| (prx == ACCEL4) || (prx == DECEL4) || (prx == JOGACC)
    				|| (prx == JOGDEC) || (prx == DECEL5))
    				&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
    				if(pr[U_ACCDEC] == 0){
    					ax = ACC_UnitConv(attr[prx].min, 2);
    				}
    				else{
    					ax = ACC_UnitConv(attr[prx].min/10, 2);
    				}
    			}
    			else if(((prx == S4ACC1) || (prx == S4ACC2) || (prx == S4DEC1) // ft/s3
    					|| (prx == S4DEC2) || (prx == S4DEC3)) 
    					&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
    					if(pr[U_ACCDEC] == 0){
    						ax = SCurve_UnitConv(prx, attr[prx].min, 2);
    					}
    					else{
    						ax = SCurve_UnitConv(prx, attr[prx].min/10, 2);
    					}
    			}			
    		}
            else if(pr[UNITSEL] == 3){
            }
            else{
                ax = attr[prx].max;
            }
    	}
	// ]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        switch (prx) {
        	case JOGF:
                ax = 40;
            break;
        	case JOGACC:
                ax = 50;
            break;
        	case JOGDEC:
                ax = 240;
            break;
        	case SIBO_DECEMY:
                ax = 240;
            break;
            default:
            break;
        }
#endif
    return(ax);
}

UWORD GetParMin(UWORD prx)
{
    UWORD ax, uwPRMin;

    switch (prx) {
    	case VMAX1:
    	case VMID1_1:
    	case VMID1_2:
    	case VMIN1:
    	case VMAX2:
    	case VMID2_1:
    	case VMID2_2:
    	case VMIN2:
    	case LVL:
    	case STALL4V:
    	case VEPS:
    	case DCBRK4V:
    	case PHL_L:
    	    if ((pr[HPSPEC]&VFD440V)==VFD220V)    // 220V class
    	    	ax = attr[prx].min >> 1;
    	    else
    	        ax = attr[prx].min;
    	    break;
        //case MI_RAT1:
        //case PM_MI_RAT:
		//case MI_RAT2:
			//if ((pr[PROTBIT]&0x0800)==0x0800)	// Bit 11: rated amps of motor
				//ax = attr[prx].min;
			//else{
//				ax = ((ULONG)pr[I_RATE] * 40 / 100);
				//ax = ((ULONG)pr[I_RATE] * 30 / 100);
			//}
			//break;
		// [ Change Minimum Data of Velocity Unit, Add by DINO, 05/25/2009
    	case Lift_SPD:
    	case Max_MperS:
    		if(pr[UNITSEL] == 2){
				uwPRMin = attr[prx].min;
				ax = (UWORD)(((ULONG)uwPRMin * 13435 + 2048) >> 12);
			}
			else{
				ax = attr[prx].min;
			}
		// ]
            break;
//============ Create for DLC function ============//
		case ACCEL1:
    	case DECEL1:
    	case JOGACC:
    	case JOGDEC:
        	  //Gfc DLC modify , Henry, 2018/05/23
            if((pr[SOFC]==4)||(pr[SOFC]==5)){    //[Gfc DLC modify,Henry,2018/05/23]          
                ax = 10;   //Dot 2  0.10 m/s^2
                
            }
            else{
                ax = attr[prx].min;
                
            }
            break;
		case ACCEL2:
		case DECEL2:
		case ACCEL3:
		case DECEL3:
		case ACCEL4:
		case DECEL4:
        //[ //[Sibocom acc/dec,Lyabryan,2019/11/12]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        case SIBO_DECEMY:
#endif
        case S4ACC1:
        case S4ACC2:
        case S4DEC1:
        case S4DEC2:
        	  //Gfc DLC modify , Henry, 2018/05/23
            if((pr[SOFC]==4)||(pr[SOFC]==5)){   //[Gfc DLC modify,Henry,2018/05/23]
                ax = 1;   //Dot 2  0.01 sec
            }
            else{
                ax = attr[prx].min;
            }
    	
            break;
//========================================//
    	
    	default:
            ax = attr[prx].min;
            break;
    }

	if ((attr[prx].ati&CHG) == CHG){
		// Maximum Value of m/s
		//[ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
		if ((pr[UNITSEL] == 1) && (prx != Lift_SPD) && (prx != Max_MperS)){
			if(((prx == ACCEL1) || (prx == DECEL1) || (prx == ACCEL2)	  // m/s2
				|| (prx == DECEL2) || (prx == ACCEL3) || (prx == DECEL3)
				|| (prx == ACCEL4) || (prx == DECEL4) || (prx == JOGACC)
				|| (prx == JOGDEC) || (prx == DECEL5))
				&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
				if(pr[U_ACCDEC] == 0){
					ax = ACC_UnitConv(attr[prx].max, 0);
				}
				else{
					ax = ACC_UnitConv(attr[prx].max/10, 0);
				}
			}
			else if(((prx == S4ACC1) || (prx == S4ACC2) || (prx == S4DEC1) // m/s3
					|| (prx == S4DEC2) || (prx == S4DEC3)) 
					&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
					if(pr[U_ACCDEC] == 0){
						ax = SCurve_UnitConv(prx, attr[prx].max, 0);
					}
					else{
						ax = SCurve_UnitConv(prx, attr[prx].max/10, 0);
					}					
			}
			else{
			}
		}
		// Maximum Value of ft/s
		else if(pr[UNITSEL] == 2){
			if(((prx == ACCEL1) || (prx == DECEL1) || (prx == ACCEL2)	  // ft/s2
				|| (prx == DECEL2) || (prx == ACCEL3) || (prx == DECEL3)
				|| (prx == ACCEL4) || (prx == DECEL4) || (prx == JOGACC)
				|| (prx == JOGDEC) || (prx == DECEL5))
				&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
				if(pr[U_ACCDEC] == 0){
					ax = ACC_UnitConv(attr[prx].max, 2);
				}
				else{
					ax = ACC_UnitConv(attr[prx].max/10, 2);
				}
			}
			else if(((prx == S4ACC1) || (prx == S4ACC2) || (prx == S4DEC1) // ft/s3
					|| (prx == S4DEC2) || (prx == S4DEC3)) 
					&& ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
					if(pr[U_ACCDEC] == 0){
						ax = SCurve_UnitConv(prx, attr[prx].max, 2);
					}
					else{
						ax = SCurve_UnitConv(prx, attr[prx].max/10, 2);
					}
			}
			else{
			}
		}        
        else if(pr[UNITSEL] == 3){
        }
        else{
            ax = attr[prx].min;
        }
	}//] //[Sibocom S curve, ACC unit,Jason,2019/10/01]    
	#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        switch (prx) {
        	case JOGF:
                ax = 1;
            break;
        	case JOGACC:
                ax = 1;
            break;
        	case JOGDEC:
                ax = 64;
            break;
        	case SIBO_DECEMY:
                ax = 80;
            break;
            default:
            break;
        }
    #endif
    return(ax);
}

UWORD GetParAttr(UWORD prx)
{
    UWORD ax;

    switch (prx) {
    	case HPSPEC:
    		if (SHOW_ALLPR==1)
    			ax = (attr[prx].ati&0xfff7);
    		else
    			//ax = (attr[prx].ati|0x4409);
                ax = (attr[prx].ati|0x4009);
    		break;
    	case ACCEL1:
    	case DECEL1:
    	case ACCEL2:
    	case DECEL2:
    	case ACCEL3:
    	case DECEL3:
    	case ACCEL4:
    	case DECEL4:
    	case JOGACC:
    	case JOGDEC:
    	case S4ACC1:
    	case S4ACC2:
    	case S4DEC1:
    	case S4DEC2:
    	case S4DEC3:    	
    	case DECEL5:
        case DECEL_ESD:    //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
    	case APRDECT:
        //[ //[Sibocom acc/dec,Lyabryan,2019/11/12]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        case SIBO_DECEMY:
#endif
    	    if (pr[U_ACCDEC]==0){
    	        ax = ((attr[prx].ati&0xfcff)|0x0200);
    	    }    
    	    else{
    	        ax = ((attr[prx].ati&0xfcff)|0x0100);
    	    }
    	    break;
        case SERVICE_ENABLE:
            if(SERV_KEY==0){  //[SERV READ ONLY,Lyabryan,2018/08/17]
                ax = (attr[prx].ati|READ);
            }
            else{
                ax = (attr[prx].ati&(~READ));
            }
        break;                
        case SERVICE_COUNT:              //[Service time function, Bernie, 2017/03/14]
            if((pr[SERVICE_ENABLE]==1)||(SERV_KEY==0)){
                ax = (attr[prx].ati|READ);
            }
            else{
                ax = ((attr[prx].ati&(~READ)));
            }
            break;
        case IR_LIFE:              //[Service time function, Bernie, 2017/03/14]
            if(pr[IR_ENABLE]>0){
                ax = (attr[prx].ati|READ);
            }
            else{
                ax = ((attr[prx].ati&(~READ)));
            }
            break;
        case FMAX:
        case MFBASE1:
        case FMID1_1:
        case FMID1_2:
        case FMIN1:
        case MFBASE2:
        case FMID2_1:
        case FMID2_2:
        case FMIN2:
        case FSTART:
        case JOGF:
        case FUPPER:
        case FLOWER:
        case FSKIP1H:
        case FSKIP1L:        
        case FSKIP2H:
        case FSKIP2L:
        case FSKIP3H:
        case FSKIP3L:
        case UPDNKEYS:
        case DESIRE_F1:
        case DESIRE_F1B:
        case DESIRE_F2:
        case DESIRE_F2B:
        case FMI7:
        case FMI8:
        case FMI9:
        case FMI10:
        case FMI11:
        case FMI12:
#if !SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
		case FMI1:
        case FMI2:
        case FMI3:
        case FMI4:
        case FMI5:
        case FMI6:
        case FMI13:
        case FMI14:
        case FMI15:
#endif
        case YDSWRPM:
        case GEAR_ACCF:
        case GEAR_DECF:
        case DCIFSTA:
        case SLEEPF:
        case WAKEF:
        case ASR_F1:
        case DBCCHG_F:
        case FMAIN:
            if (VH_EN==1)
            {
                ax = ((attr[prx].ati&0xfcff)|0x0100);    
            }
            else
            {
                ax = attr[prx].ati;
            }
        break;
        //[ //[Sibocom acc/dec,Lyabryan,2019/11/12]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        case FLAND:
        case FMI13:
        case FMI14:
        case FMI15:
        case STO_LOCK:
        case UNITSEL:
        case SIBO_S3EMY:
        case SIBO_S4EMY:
                ax = (attr1[prx].ati|0x8008);
        break;
        case FMI0:
        case FMI1:
        case FMI2:
        case FMI3:
        case FMI4:
        case FMI5:
        case FMI6:
                ax = ((attr1[prx].ati&0xf8fD)|ITEM);   // Cancel DOT & WRUN & CHG
        	break;
        //] //[Sibocom acc/dec,Lyabryan,2019/11/12]
#endif
        case TQREF:
        	if (pr[TQRSOOC]==0){
        		if ((pr[TENSION]!=0)&&(pr[DIAMETER]!=0))
        			ax = (attr[prx].ati|0x059A);	//monintor
        		else
        			ax = (attr[prx].ati&0xfff7);
        	}
        	else
        		ax = (attr[prx].ati|0x059A);	//monintor
        	break;
        case JmPu:
        	if (RUNNING==STOP)
        		ax = (attr[prx].ati&0xfff7);
        	else
        		ax = (attr[prx].ati|0x041A);	//monintor
        	break;   	
        default:
            ax = attr[prx].ati;
            break;
    }

//-- Read only when PRLOCK, Add by DINO, 09/22/2008
	if ( PRLOCK==1 ){	// 00-08=PSW, Only 00-07 could be set
		if ( prx!=PSW_IN )
			ax |= READ;
	}
	else if ( FSET_LOCK==1 ){
		if ( OPKEY_LOCK==1 ){	// 00-02=8, Only 00-02 & 00-07 could be set
			if ( prx!=PRRESET && prx!=PSW_IN )
				ax |= READ;
		}
		else {	// 00-02=1, Only 00-00~00-07 could be set
			if ( (prx>PSW_IN) || (prx<HPSPEC) )
				ax |= READ;
		}
	}
//-- End on 09/22/2008

    return(ax);
}

void write_pr(UWORD prx,UWORD prvalue)
{
    void (*write_ptr)(UWORD,UWORD);
     
    if (COPYEN==1){
        if(COPYOK==0){
            KEYEND = END;
            //if (pr[prx]!=prvalue)			// Store the difference  //[store all parameter, Bernie, 2017/08/08]
            if(prx!=HPSPEC){
                pr_copy[prx] = prvalue;
            }
            else{
                if(pr[HPSPEC]==prvalue){
                }
                else{
                    InitValue();
                    copy_status.ub = 0;
                    WarnDisplaySave();
                    WarnCode = SE3_WARN;        // Copy Fail 3, SE3
                }
            }
                

        }
        else{
        	//Normal Write
            //KEYEND = ERR;
            PRUPDATE = 0;
            
            if (prx < PRMAX){
                write_ptr = pr_tbl[prx];
                (*write_ptr)(prx, prvalue);
            }
        }    
    }
    else{
    	//Normal Write
        KEYEND = ERR;
        PRUPDATE = 0;
        
        if (prx < PRMAX){
            write_ptr = pr_tbl[prx];
            (*write_ptr)(prx, prvalue);
        }
    }    
}

/*------------- Update Parameter Function ---------------------------------------------
 -      prx : index of Pr.
 -      prvalue: (local variable) for Pr. content
 -------------------------------------------------------------------------------------*/
void updatepr(UWORD prx,UWORD prvalue)
{
    UWORD uwEEPData, uwAttr, uwParData;
    float flParData;

//[ Read only when PRLOCK, Add by DINO, 09/22/2008
	uwAttr = attr[prx].ati;

	if ( PRLOCK==1 ){	// 00-08=PSW, Only 00-07 could be set
		if ( prx!=PSW_IN )
			uwAttr |= READ;
	}
	else if ( FSET_LOCK==1 ){
		if ( OPKEY_LOCK==1 ){	// 00-02=8, Only 00-02 & 00-07 could be set
			if ( prx!=PRRESET && prx!=PSW_IN )
				uwAttr |= READ;
		}
		else {	// 00-02=1, Only 00-00~00-07 could be set
			if ( (prx>PSW_IN) || (prx<HPSPEC) )
				uwAttr |= READ;
		}
	}
// End on 09/22/2008 ]

	// [ Change Voltage Data, Modify by DINO, 12/17/2008
	if ( (uwAttr&V440)==V440 ){
		if ((pr[HPSPEC]&VFD440V) == VFD220V){		// 220V class
			prvalue <<= 1;
		}
	}

	// [ Change Velocity Data, Add by DINO, 05/25/2009
	if ((uwAttr&CHG) == CHG){
		if ((pr[UNITSEL] == 1) && (prx != Lift_SPD) && (prx != Max_MperS)){
			if((//((prx >= SIBO_ACCMID)&&(prx <= SIBO_DECMID))||
                //((prx >= SIBO_ACCHIGH)&&(prx <= SIBO_DECHIGH))||
                //((prx >= SIBO_ACCNOMINAL)&&(prx <= SIBO_DECNOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                ((prx == SIBO_DECEMY))||
#endif
                //((prx >= SIBO_ACCLEVEL)&&(prx <= SIBO_DECLEVEL))||
                //((prx >= SIBO_ACCRELEVEL)&&(prx <= SIBO_DECRELEVEL))||
                //((prx >= SIBO_ACCLOW)&&(prx <= SIBO_DECLOW))||
                //((prx >= SIBO_ACCINS)&&(prx <= SIBO_DECINS))||
                ((prx == ACCEL1)||(prx == DECEL1)|| 
                 (prx == ACCEL2)||(prx == DECEL2)|| 
                 (prx == ACCEL3)||(prx == DECEL3)|| 
                 (prx == ACCEL4)||(prx == DECEL4)|| 
                 (prx == JOGACC)||(prx == JOGDEC)||(prx == DECEL5))) // m/s2
				  && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
				if(pr[U_ACCDEC] == 0){
					flParData = ACC_UnitConv(prvalue, 1);
				}
				else{
					flParData = ACC_UnitConv(prvalue/10, 1);
				}                
			}
			else if((//((prx >= SIBO_S1MID)&&(prx <= SIBO_S4MID))||
                     //((prx >= SIBO_S1HIGH)&&(prx <= SIBO_S4HIGH))||
                     //((prx >= SIBO_S1NOMINAL)&&(prx <= SIBO_S4NOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                     ((prx >= SIBO_S3EMY)&&(prx <= SIBO_S4EMY))||
#endif
                     //((prx >= SIBO_S1LEVEL)&&(prx <= SIBO_S4LEVEL))||
                     //((prx >= SIBO_S1RELEVEL)&&(prx <= SIBO_S4RELEVEL))||
                     //((prx >= SIBO_S1LOW)&&(prx <= SIBO_S4LOW))||
                      (prx == S4ACC1) || (prx == S4ACC2) || 
                      (prx == S4DEC1)||(prx == S4DEC2) || (prx == S4DEC3))    // m/s3
					  && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
					if(pr[U_ACCDEC] == 0){
						flParData = SCurve_UnitConv(prx, prvalue, 1);
					}
					else{
						flParData = SCurve_UnitConv(prx, prvalue/10, 1);
					}					
			}
			else{
				flParData = flMetric2Hz(prvalue);	// m/s
			}
			prvalue = (UWORD)(flParData+0.5);
		}
		else if(pr[UNITSEL] == 2){	// ft/s
			if ((prx == Lift_SPD) || (prx== Max_MperS)){
				/*-------------------------- [ 0.01ft/s -> 0.01m/s (Q14) ] --------------------------
				--  m/s = (ft/s) / 3.28
				--  1/3.28 = 4995/16384
				-----------------------------------------------------------------------------------*/
				flParData = ((ULONG)prvalue * 4995 + 8192) >> 14;
			}
			else if((//((prx >= SIBO_ACCMID)&&(prx <= SIBO_DECMID))||
                     //((prx >= SIBO_ACCHIGH)&&(prx <= SIBO_DECHIGH))||
                     //((prx >= SIBO_ACCNOMINAL)&&(prx <= SIBO_DECNOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                     ((prx == SIBO_DECEMY))||
#endif
                     //((prx >= SIBO_ACCLEVEL)&&(prx <= SIBO_DECLEVEL))||
                     //((prx >= SIBO_ACCRELEVEL)&&(prx <= SIBO_DECRELEVEL))||
                     //((prx >= SIBO_ACCLOW)&&(prx <= SIBO_DECLOW))||
                     //((prx >= SIBO_ACCINS)&&(prx <= SIBO_DECINS))||
                     ((prx == ACCEL1)||(prx == DECEL1)|| 
                      (prx == ACCEL2)||(prx == DECEL2)|| 
                      (prx == ACCEL3)||(prx == DECEL3)|| 
                      (prx == ACCEL4)||(prx == DECEL4)|| 
                      (prx == JOGACC)||(prx == JOGDEC)||(prx == DECEL5))) // m/s2
     				  && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
					if(pr[U_ACCDEC] == 0){
						flParData = ACC_UnitConv(prvalue, 3);
					}
					else{
						flParData = ACC_UnitConv(prvalue/10, 3);
					}
			}
			else if((//((prx >= SIBO_S1MID)&&(prx <= SIBO_S4MID))||
                     //((prx >= SIBO_S1HIGH)&&(prx <= SIBO_S4HIGH))||
                     //((prx >= SIBO_S1NOMINAL)&&(prx <= SIBO_S4NOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                     ((prx >= SIBO_S3EMY)&&(prx <= SIBO_S4EMY))||
#endif
                     //((prx >= SIBO_S1LEVEL)&&(prx <= SIBO_S4LEVEL))||
                     //((prx >= SIBO_S1RELEVEL)&&(prx <= SIBO_S4RELEVEL))||
                     //((prx >= SIBO_S1LOW)&&(prx <= SIBO_S4LOW))||
                      (prx == S4ACC1) || (prx == S4ACC2) || 
                      (prx == S4DEC1)||(prx == S4DEC2) || (prx == S4DEC3))    // m/s3
					  && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
					if(pr[U_ACCDEC] == 0){
						flParData = SCurve_UnitConv(prx, prvalue, 3);
					}
					else{
						flParData = SCurve_UnitConv(prx, prvalue/10, 3);
					}
			}	
			else{
				flParData = Ft2Hz(prvalue);
			}
			prvalue = (UWORD)(flParData+0.5);
		}
        else{
            flParData = prvalue;
        }
        
	}
	// ]
        switch(prx){
            case ACCEL1:
                PR_flAccel1sec = flParData;
                break;            
            case ACCEL2:
                PR_flAccel2sec = flParData;
                break;
            case ACCEL3:
                PR_flAccel3sec = flParData;
                break;
            case ACCEL4:
                PR_flAccel4sec = flParData;
                break;            
            case DECEL1:
                PR_flDecel1sec = flParData;
                break;
            case DECEL2:
                PR_flDecel2sec = flParData;
                break;
            case DECEL3:
                PR_flDecel3sec = flParData;
                break;            
            case DECEL4:
                PR_flDecel4sec = flParData;
                break;
            case DECEL5:
                PR_flDecel5sec = flParData;
                break;
            case JOGDEC:
                PR_flDecelJogsec = flParData;
                break;            
            case JOGACC:
                PR_flAccelJogsec = flParData;
                break;
            case DECEL_ESD:
                PR_flDecelEsdsec = flParData;
                break;    
            case S4ACC1:
                PR_flSAcc1Esdsec = flParData;
                break;
            case S4ACC2:
                PR_flSAcc2Esdsec = flParData;
                break;
            case S4DEC1:
                PR_flSDec1Esdsec = flParData;
                break;            
            case S4DEC2:
                PR_flSDec2Esdsec = flParData;
                break;
            case S4DEC3:
                PR_flSDec3Esdsec = flParData; 
                break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]  //[Sibocom unit convert to moter speed, Jason, 20200512]
            case SIBO_DECEMY:
                PR_flDecelEMYSIBOsec = flParData;
                break;            				
            case SIBO_S3EMY:
                PR_flS3EMYsec = flParData; 
                break;
            case SIBO_S4EMY:
                PR_flS4EMYsec = flParData; 
                break;
            case FMI7:
                PR_flFmi7Hz = flParData;
                break;            
            case FMI8:
                PR_flFmi8Hz = flParData;
                break;
            case FMI9:
                PR_flFmi9Hz = flParData;
                break;
            case FMI10:
                PR_flFmi10Hz = flParData;
                break;            
            case FMI11:
                PR_flFmi11Hz = flParData;
                break;
            case FMI12:
                PR_flFmi12Hz = flParData;
                break;
            case JOGF:
                PR_flFJog_Hz = flParData;
                break;
#endif
            default:
            break;
        }        


    uwEEPData = read_ep(prx);

	if ( (uwAttr&READ)==0 ){
    	if ((RUNNING==STOP)||(attr[prx].ati&WRUN)) {
        	KEYEND = END;
        	if (uwEEPData != prvalue){
/*
            	if ((pr[HPSPEC]&VFD440V)==VFD220V){		// 220V class
               		if ( (attr[prx].ati&V440)==V440 )	// Modify by DINO, 12/17/2008
                 		prvalue <<= 1;
             	}
*/             	
                if ((attr[prx].ati&SIGN)!=0){    //Signed Parameter
                    if (((SWORD)prvalue<=(SWORD)attr[prx].max)&&((SWORD)prvalue>=(SWORD)attr[prx].min)){
	           		    write_ep(BLK_WRITE,prx,prvalue);
	           		    pr[prx] = prvalue;
	           		    PRUPDATE = 1;
                        OBKEYPROG = 1; //[13Grop modify,Lyabryan,2016/07/19]
	           		}
	           		else
	           		    KEYEND = ERR;
	            }
	            else{   //Unsigned Parameter
                    if ((prvalue<=attr[prx].max)&&(prvalue>=attr[prx].min)){
                        //[Encoder direction foolproof, Lyabryan, 2016/03/07] //[
                        if((prx == PG_TYPE)&&(pr[PGINPUT]>=3)){ 
                            if(prvalue>=3)
                                KEYEND = ERR;
                            else{
                                write_ep(BLK_WRITE,prx,prvalue);
                                pr[prx] = prvalue;
                                PRUPDATE = 1;  // PAR is changed
                                OBKEYPROG = 1; //[13Grop modify,Lyabryan,2016/07/19]
                            }
                        }
                        else if((prx == PGINPUT)&&(pr[PG_TYPE]>=3)){
                            if(prvalue>=3)
                                KEYEND = ERR;                            
                            else{
                                write_ep(BLK_WRITE,prx,prvalue);
                                pr[prx] = prvalue;
                                PRUPDATE = 1;  // PAR is changed
                                OBKEYPROG = 1; //[13Grop modify,Lyabryan,2016/07/19]
                            }
                        }
                        else{ //] //[Encoder direction foolproof, Lyabryan, 2016/03/07]
                        
    	           		    write_ep(BLK_WRITE,prx,prvalue);

    						// [ Recover RAM Data, Modify by DINO, 12/17/2008
                   			if ( (uwAttr&V440) == V440){
                				if ((pr[HPSPEC]&VFD440V) == VFD220V)	// 220V class
                     				prvalue >>= 1;
                 			}
                 			// ]
                   		    pr[prx] = prvalue;
                   		    PRUPDATE = 1;  // PAR is changed
                   		    OBKEYPROG = 1; //[13Grop modify,Lyabryan,2016/07/19]
                        }
            	    }
            	    else
            		    KEYEND = ERR;
                }
        
				// Set parameter OK, reload RAM paramter, add by DINO, 05/29/2008
				if ( PRUPDATE==1 ){
					  WRITE_PR_ATONCE = 1; //[EDS parameter at once,sampo,2018/02/05]
					  uwWritePrCnt = 0;    //[EDS parameter at once,sampo,2018/02/05]
				  	rec_uwRUNmin = pr[RUNMIN];  //--- Update Buffer Data, Add by DINO, 10/27/2008

        			if ( pr[TQ_LPG]==0 )
        				COF_uwTqSlopePu = 0;
        			else
        				COF_uwTqSlopePu = ((ULONG)COF_uwTqratePu * 3 + (pr[TQ_LPG]>>1)) / pr[TQ_LPG];

        			uwEEPData =  U16xU16divU16(pr[DC_ZSEARCH],13107,100);	// Pr.15-03, Add by DINO, 07/21/2008
        			TUN_uwIdCurr = ((ULONG)uwEEPData * mspec + 50) / 100;	// Change to percentage of Motor, 08/11/2008
        		}
        
			}
			else{
				// [ Don't set RAM data if prx= Motor Parameter, DINO, 03/27/2009
				switch(prx){
				    case MI_NL1:
				    case Rs1:
				    case Rr1:
				    case Lm1:
				    case Lx1:
				    case MI_NL2:
				    case Rs2:
				    case Rr2:
				    case Lm2:
				    case Lx2:
				    case PM_Rs:
				    case PM_Ld:
				    case PM_Lq:
				        break;
				    default:
               			// [ Recover RAM Data, Modify by DINO, 12/17/2008
               			if ((uwAttr&V440) == V440){
            				if ((pr[HPSPEC]&VFD440V) == VFD220V){	// 220V class
                 				prvalue >>= 1;
                 			}
             			}
             			// ]
				    	pr[prx] = prvalue;
				        break;
				}
				// ]
	        }
		}
    	else      
    		KEYEND = ERR;
    }
    Recent_Setting_Parameter(prx);
}


void fnone(UWORD prx, UWORD prvalue)
{
     KEYEND = END;      //[Copy parameters fail by using CC01, Freeman, 2017/06/22]
}

void P00_00(UWORD prx, UWORD prvalue)
{
    UBYTE HPSPEC_temp;
    
    HPSPEC_temp = prvalue;                    //[Single phase input, Bernie, 01/19/2012]
    if(HPSPEC_temp > VFD_SINGLEPHASE)
        HPSPEC_temp -= VFD_SINGLEPHASE;
    // if ((prvalue<=MAXMODELNO)&&(SHOW_ALLPR==1)){
    if ((HPSPEC_temp<=MAXMODELNO)&&(SHOW_ALLPR==1)){   //[Single phase input, Bernie, 01/19/2012]
        KEYEND = END;
//        MODELCHG = 1;
        write_ep(0,HPSPEC,prvalue);
        pr[HPSPEC] = prvalue;

        wr_def2ep();

        DINT();                
        InitValue();
        EINT();
                
//        MODELCHG = 0;
        if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
            pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
        else
            pr[I_RATE] = CTispec[pr[HPSPEC]];
    }
    else{
		KEYEND = END;            
    }
}
void P00_02(UWORD prx, UWORD prvalue)
{
    if (RUNNING==STOP && PRLOCK==0){
	    switch(prvalue){

			case 0:
                updatepr(PRRESET, 2);
                updatepr(PRRESET, prvalue);
			    if (PRUPDATE){
			    	SHOW_ALLPR   = 0;
			    	SHOW_ENHANCE = 0;	//SC
			    	OPKEY_LOCK   = 0;
                	FSET_LOCK    = 0;
					C21xx[0x20] |= 0x1000;	// [For VFD-Cx reload parameter information, Bernie, 09/22/2011]
                    SIBO_PARAMETER = 0; //[Group12&13 Limit count,Lyabryan,2020/09/10]
                    SIBO_SPDCHG = 0;
                    if(SIBO_ENABLE){
                        SIBO_SPDCHG = 1;
                        SIBO_PARAMETER = 1;
                    }
                }
            	break;
			case 1:    //------ Parameter Lock, can not read parameter //
                updatepr(PRRESET, prvalue);
			    if ( PRUPDATE ){
					SHOW_ALLPR   = 0;
					SHOW_ENHANCE = 0;	//SC
					FSET_LOCK    = 1;     
					OPKEY_LOCK   = 0;             		
				}
				break;
			case 2:
                //updatepr(PRRESET, prvalue);	// debug mode
			    //if ( PRUPDATE ){
			        pr[PRRESET] = 2;
                  	SHOW_ENHANCE = 1;
					C21xx[0x20] |= 0x1000;	// [For VFD-Cx reload parameter information, Bernie, 09/22/2011]
                    KEYEND = END;
                //}
                break;
            case 5:                           //[DLC  function Change unit to m/s2, Bernie, 2015/09/02] 
                updatepr(PRRESET, prvalue);   
			    if ( PRUPDATE ){
                    facc1.ul = cal_time(pr[FMAX],0);
                    fdec1.ul = cal_time(pr[FMAX],0);
                    //facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
                    //fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
                    //facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
                    //fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
                    //facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
                    //fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);	
                    fjacc.ul = 0;	
                    fjdec.ul = 0;	
                    fdec5.ul = cal_time(pr[FMAX],0);
                    //Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);

                    DLC_Initial_value();
                    DINT();
    				InitValue();
    				EINT();
			    }
                break;
			case 8:
                updatepr(PRRESET, prvalue);
			    if ( PRUPDATE ){
					SHOW_ALLPR   = 0;
					SHOW_ENHANCE = 0;	//SC
					FSET_LOCK    = 1;
					OPKEY_LOCK   = 1;
			    }
			    break;
			case  9:          /* reset User Parameter only */
			case 10:
				KEYEND = END;
				wr_def2ep();
				PrArea(prvalue);
                //[ //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
                if(Driver_ID == IEDS_DRIVER){ 
                    //if((prvalue == 4) || (prvalue == 5)){                   
                    facc1.ul = cal_time(pr[FMAX],0);
                    fdec1.ul = cal_time(pr[FMAX],0);
                    //facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
                    //fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
                    //facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
                    //fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
                    //facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
                    //fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]); 
                    fjacc.ul = 0;   
                    fjdec.ul = 0;   
                    fdec5.ul = cal_time(pr[FMAX],0);
                    //Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
                
                    DLC_Initial_value();
                } //] //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]   //[Sibocom unit convert to moter speed, Jason, 20200512]
                    updatepr(UNITSEL, 1);
                    //write_ep(BLK_WRITE,UNITSEL, pr[UNITSEL]);            
                    updatepr(FMI0,0);
                    updatepr(FMI1,2);
                    updatepr(FMI2,6);
                    updatepr(FMI3,1);
                    updatepr(FMI4,3);
                    updatepr(FMI5,4);
                    updatepr(FMI6,5);
                    updatepr(FMI7,25);
                    updatepr(FMI8,40);
                    updatepr(FMI9,50);
                    updatepr(FMI10,75);
                    updatepr(FMI11,100);
                    updatepr(FMI12,60);
                    P01_10(ACCEL1,50);
                    P01_10(DECEL1,50);
                    P01_10(ACCEL2,50);
                    P01_10(DECEL2,50);
                    P01_10(ACCEL3,50);
                    P01_10(DECEL3,50);
                    P01_10(ACCEL4,50);
                    P01_10(DECEL4,50);
                    P01_10(DECEL5,50);
                    P01_10(JOGACC,10);
                    P01_10(JOGDEC,100);
                    P01_10(JOGF,25);
                    updatepr(S4ACC1,30);
                    updatepr(S4ACC2,30);
                    updatepr(S4DEC1,30);
                    updatepr(S4DEC2,30);
                    PR_flAccel1sec = pr[ACCEL1];
                    PR_flAccel2sec = pr[ACCEL2];
                    PR_flAccel3sec = pr[ACCEL3];
                    PR_flAccel4sec = pr[ACCEL4];
                    PR_flDecel1sec = pr[DECEL1];
                    PR_flDecel2sec = pr[DECEL2];
                    PR_flDecel3sec = pr[DECEL3];
                    PR_flDecel4sec = pr[DECEL4];
                    PR_flDecel5sec = pr[DECEL5];
                    PR_flDecelJogsec = pr[JOGDEC];
                    PR_flAccelJogsec = pr[JOGACC];
                    PR_flDecelEsdsec = pr[DECEL_ESD];
                    PR_flDecelEMYSIBOsec = pr[SIBO_DECEMY];
                    PR_flSAcc1Esdsec = pr[S4ACC1];
                    PR_flSAcc2Esdsec = pr[S4ACC2];
                    PR_flSDec1Esdsec = pr[S4DEC1];
                    PR_flSDec2Esdsec = pr[S4DEC2];
                    PR_flSDec3Esdsec = pr[S4DEC3];
                    PR_flS3EMYsec = pr[SIBO_S3EMY];
                    PR_flS4EMYsec = pr[SIBO_S4EMY];
                    PR_flFmi7Hz = pr[FMI7];
                    PR_flFmi8Hz = pr[FMI8];
                    PR_flFmi9Hz = pr[FMI9];
                    PR_flFmi10Hz = pr[FMI10];
                    PR_flFmi11Hz = pr[FMI11];
                    PR_flFmi12Hz = pr[FMI12];         
                
                    PR_flFJog_Hz = pr[JOGF];
#endif

				DINT();
				InitValue();
				EINT();         
				break;

			case 84:        /* VH series */
				if (FSET_LOCK==0 && SHOW_ALLPR==1){
                	KEYEND = END;                
	     			if (VH_EN == 0){
                		wr_def2ep();
                   		DINT();
              			InitValue();
              			EINT();  	          	    
	          	    	pr[DEBUG_F1] = (pr[DEBUG_F1]|0x8000);
                  	  	write_ep(0,DEBUG_F1,pr[DEBUG_F1]);
                  	 	pr[DBC1] = 0;
                  	  	write_ep(0,DBC1,pr[DBC1]);
                  		pr[DBC2] = 0;
                  		write_ep(0,DBC2,pr[DBC2]);
                  		//pr[PWM_MODE] = 2;  
                        pr[PWM_MODE] = 1;       //[move parameter to 11-20, Bernie, 2017/02/16]
                  	  	write_ep(0,PWM_MODE,pr[PWM_MODE]);                  	        
                  		VH_EN = 1;
                	}
        		} break;
                
           	case 89:        /* VX standard Series */
               	if (FSET_LOCK==0 && SHOW_ALLPR==1){
                 	KEYEND = END;                
	          	  	if (VH_EN == 1){
                     	wr_def2ep();
                     	DINT();
              			InitValue();
              			EINT();  	          	    
	          	      	pr[DEBUG_F1] = (pr[DEBUG_F1]&(0xffff-0x8000));
                  	 	write_ep(0,DEBUG_F1,pr[DEBUG_F1]);
						pr[DBC1] = attr[DBC1].def;
                  	  	write_ep(0,DBC1,pr[DBC1]);
                  	  	pr[DBC2] = attr[DBC2].def;
                  	  	write_ep(0,DBC2,pr[DBC2]);
                  	  	pr[PWM_MODE] = attr[PWM_MODE].def;
                  	  	write_ep(0,PWM_MODE,pr[PWM_MODE]);
                  	 	VH_EN = 0;
                	}
            	} break;
      //[specoal para rst for GFC,Henry,2017/07/14]
            case 100:
                KEYEND = END;
                wr_def2ep();
                PrArea(prvalue);
                                
                facc1.ul = cal_time(pr[FMAX],0);
                fdec1.ul = cal_time(pr[FMAX],0);
                fjacc.ul = 0;   
                fjdec.ul = 0;   
                fdec5.ul = cal_time(pr[FMAX],0);
                DLC_Initial_value();
                
                P00_09(CTRLM,8);           //00-09=8
                updatepr(UNITSEL,3);       //00-10=3
                P00_12(SETCRF,12);         //00-12=12
                //Gfc DLC modify , Henry, 2018/05/23
                P00_14(SOFC,5);            //00-14=5
                //P00_14(SOFC,4);          //00-14=4
                updatepr(SOOC,2);          //00-15=2
                P01_10(ACCEL1,80);         //01-12=0.8
                P01_10(DECEL1,80);         //01-13=0.8
                P01_10(JOGACC,25);         //01-20=0.25
                P01_10(JOGDEC,75);         //01-21=0.75
                P01_10(JOGF,25);           //01-22=0.25
                updatepr(S4ACC1,125);      //01-24=1.25
                updatepr(S4ACC2,125);      //01-25=1.25
                updatepr(S4DEC1,125);      //01-26=1.25
                updatepr(S4DEC2,200);      //01-27=2.00
                updatepr(S4DEC3,0);        //01-30=0
                P01_10(DECEL5,0);          //01-31=0
                updatepr(FSD,250);         //01-32=0.250
                P02_01(MI1,45);            //02-01=45
                P02_02(MI2,46);            //02-02=46
                P02_02(MI3,47);            //02-03=47
                P02_02(MI4,48);            //02-04=48
                P02_02(MI7,5);             //02-07=5
                P02_02(MI8,0);             //02-08=0
                P02_11(RLY1,9);            //02-11=9
                P02_11(RLY2,12);           //02-12=12
                P02_11(MO1,6);             //02-13=6
                P02_11(MO2,15);            //02-14=15
                updatepr(BRK_RUNDT,25);    //02-29=0.025
                updatepr(BRK_STOPDT,25);   //02-30=0.025
                updatepr(MCDELAY_RUN,25);  //02-31=0.025
                updatepr(MCDELAY_STOP,25); //02-32=0.025
                updatepr(AFM1,2);          //03-17=2
                updatepr(AFM2,3);          //03-20=3
                updatepr(RSQ_SPD,16);      //04-16=0.16
                
                //Gfc DLC modify , Henry, 2018/05/23
                updatepr(PDO_TYPE, 3);     //04-37=3
                
                updatepr(OHWL,850);        //06-14=85
                P06_00(VEPS,960);          //06-29=96
                updatepr(ERR_OPTM,1);      //06-30=1
                updatepr(MPHLM,1);         //06-31=1
                
                //Gfc DLC modify , Henry, 2018/05/23
                updatepr(LV_OPTM,2);       //06-45=2
                updatepr(RESETCNT,3);      //06-51=3
                updatepr(RESETINTERVAL,30);//06-52=3.0
                
                updatepr(DCISTA,6);        //07-03=0.6
                updatepr(DCISTP,6);        //07-04=0.6
                updatepr(FAN,3);           //07-11=3
                updatepr(TQ_LPG,500);      //07-29=0.5
                P08_09(Z_OFFSET,3600);     //08-09=360.0
                P09_14(CANPDOTXTIME,5);    //09-14=5
                P10_01(PG_TYPE,3);         //10-00=3
                P10_01(PGINPUT,2);         //10-02=2
    
                //Gfc DLC modify , Henry, 2018/05/23
                updatepr(ENCDET,18);       //10-04=1.8
                updatepr(DEVDET,10);       //10-08=1
                
                updatepr(POS_CTIME,450);   //10-22=0.45
                updatepr(SysControl,0x0281); //11-00=0x0281;
                P11_02(Lift_SPD,250);      //11-01=2.50
                P11_05(JM_PERCENT,45);     //11-05=45
                updatepr(ZSPDLPBW,12);     //11-06=12
                updatepr(SPDLPBW1,8);      //11-07=8
                updatepr(SPDLPBW2,10);     //11-08=10
                P11_05(Lift_ACCi,170);     //11-14=170
              
                DINT();
                InitValue();
                EINT();
            break;
      //]
            case 200:
				KEYEND = END;                
                btArtemisEnable = 1;        //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]

                wr_def2ep();
                PrArea(prvalue);
                DLC_Initial_value();

                updatepr(CAN_BURD,2);       //09-06=2

                DINT();
                InitValue();
                EINT();
			break;
			case 1234:
				if ((FSET_LOCK==0)&&(SHOW_ALLPR==1)){
					KEYEND = END;
					wr_FF2ep();
				}
			break;
            case 5566: //[Running Dir Count,Special,2018/08/17]
                if ((FSET_LOCK==0)&&(SHOW_ENHANCE==1)){
                    pr[IR_COUNT_H] = 0;
                    write_ep(0,IR_COUNT_H,0);
                    pr[IR_COUNT_L] = 0;
                    write_ep(0,IR_COUNT_L,0);
                    P06_79(IR_ENABLE,0);         
                    pr[IR_RESTEC] = 0;
                    write_ep(0,IR_RESTEC,0);
                    KEYEND = END;
                }
            break;
            case 9487: //[SERV READ ONLY,Lyabryan,2018/08/17]
                if(FSET_LOCK==0 && SHOW_ENHANCE==1){
                    SERV_KEY = 1;
                    KEYEND = END;
                }
            break;
			case 5577: //[Running Dir Count,Special,2018/08/17] 
		    if (FSET_LOCK==0 && SHOW_ENHANCE==1){
				  SHOW_ALLPR = 1;
					C21xx[0x20] |= 0x1000;	// [For VFD-Cx reload parameter information, Bernie, 09/22/2011]
					KEYEND = END;
		    }
		  break;
			case 33582:
		    	if (FSET_LOCK==0 && SHOW_ALLPR==1){
                	KEYEND = END;
                  	pr[ERR_REC1] = 0;
                  	write_ep(0,ERR_REC1, 0);
                  	pr[ERR_REC2] = 0;
                  	write_ep(0,ERR_REC2, 0);
                  	pr[ERR_REC3] = 0;
                  	write_ep(0,ERR_REC3, 0);
                  	pr[ERR_REC4] = 0;
                  	write_ep(0,ERR_REC4, 0);
                  	pr[ERR_REC5] = 0;
                  	write_ep(0,ERR_REC5, 0);
                  	pr[ERR_REC6] = 0;
                  	write_ep(0,ERR_REC6, 0);

                    //special, increase error record, 2018/09/20
                    pr[FOUT_REC1] = 0;
                  	write_ep(0,FOUT_REC1, 0);
                    pr[DCBUS_REC1] = 0;
                  	write_ep(0,DCBUS_REC1, 0);
                    pr[ISUM_REC1] = 0;
                  	write_ep(0,ISUM_REC1, 0);
                    pr[TH_TEMP1] = 0;
                  	write_ep(0,TH_TEMP1, 0);
                    pr[FOUT_REC2] = 0;
                  	write_ep(0,FOUT_REC2, 0);
                    pr[DCBUS_REC2] = 0;
                  	write_ep(0,DCBUS_REC2, 0);
                    pr[ISUM_REC2] = 0;
                  	write_ep(0,ISUM_REC2, 0);
                    pr[TH_TEMP2] = 0;
                  	write_ep(0,TH_TEMP2, 0);
                    pr[FOUT_REC3] = 0;
                  	write_ep(0,FOUT_REC3, 0);
                    pr[DCBUS_REC3] = 0;
                  	write_ep(0,DCBUS_REC3, 0);
                    pr[ISUM_REC3] = 0;
                  	write_ep(0,ISUM_REC3, 0);
                    pr[TH_TEMP3] = 0;
                  	write_ep(0,TH_TEMP3, 0);
                    pr[FOUT_REC4] = 0;
                    write_ep(0,FOUT_REC4, 0);
                    pr[DCBUS_REC4] = 0;
                  	write_ep(0,DCBUS_REC4, 0);
                    pr[ISUM_REC4] = 0;
                  	write_ep(0,ISUM_REC4, 0);
                    pr[TH_TEMP4] = 0;
                  	write_ep(0,TH_TEMP4, 0);
                    pr[FOUT_REC5] = 0;
                    write_ep(0,FOUT_REC5, 0);
                    pr[DCBUS_REC5] = 0;
                  	write_ep(0,DCBUS_REC5, 0);
                    pr[ISUM_REC5] = 0;
                  	write_ep(0,ISUM_REC5, 0);
                    pr[TH_TEMP5] = 0;
                  	write_ep(0,TH_TEMP5, 0);
                    //special, increase error record, 2018/09/20

                  	pr[PWR_MIN] = 0;
                  	write_ep(0,PWR_MIN, 0);
                  	pr[PWR_DAY] = 0;
                  	write_ep(0,PWR_DAY, 0);
                  	pr[PWR_CNT] = 0;
                  	write_ep(0,PWR_CNT, 0);
                  		
					pr[FFBK_REC] = 0;
					write_ep(0,FFBK_REC,0);
					pr[FOUT_REC] = 0;
					write_ep(0,FOUT_REC,0);
					pr[VOUT_REC] = 0;
					write_ep(0,VOUT_REC,0);
					pr[DCBUS_REC] = 0;
					write_ep(0,DCBUS_REC,0);
					pr[ISUM_REC] = 0;
					write_ep(0,ISUM_REC,0);
					pr[TH_TEMP] = 0;
					write_ep(0,TH_TEMP, 0);
					pr[SRYREC]  = 0;
					write_ep(0,SRYREC, 0);

					//--- Update Buffer Data, Add by DINO, 10/27/2008
					rec_uwFault1 = pr[ERR_REC1];
					rec_uwFault2 = pr[ERR_REC2];
					rec_uwFault3 = pr[ERR_REC3];
					rec_uwFault4 = pr[ERR_REC4];
					rec_uwFault5 = pr[ERR_REC5];
					rec_uwFault6 = pr[ERR_REC6];
                    
                    //special, increase error record, 2018/09/20
                    rec_uwError1_1 = pr[FOUT_REC1];
                    rec_uwError1_2 = pr[DCBUS_REC1];
                    rec_uwError1_3 = pr[ISUM_REC1];
                    rec_uwError1_4 = pr[TH_TEMP1];
                    rec_uwError2_1 = pr[FOUT_REC2];
                    rec_uwError2_2 = pr[DCBUS_REC2];
                    rec_uwError2_3 = pr[ISUM_REC2];
                    rec_uwError2_4 = pr[TH_TEMP2];
                    rec_uwError3_1 = pr[FOUT_REC3];
                    rec_uwError3_2 = pr[DCBUS_REC3];
                    rec_uwError3_3 = pr[ISUM_REC3];
                    rec_uwError3_4 = pr[TH_TEMP3];
                    rec_uwError4_1 = pr[FOUT_REC4];
                    rec_uwError4_2 = pr[DCBUS_REC4];
                    rec_uwError4_3 = pr[ISUM_REC4];
                    rec_uwError4_4 = pr[TH_TEMP4];
                    rec_uwError5_1 = pr[FOUT_REC5];
                    rec_uwError5_2 = pr[DCBUS_REC5];
                    rec_uwError5_3 = pr[ISUM_REC5];
                    rec_uwError5_4 = pr[TH_TEMP5];
                    //special, increase error record, 2018/09/20
                    
					rec_uwFfbk   = pr[FFBK_REC];
					rec_uwFcmd   = pr[FOUT_REC];
					rec_uwVout   = pr[VOUT_REC];
					rec_uwDcbus  = pr[DCBUS_REC];
					rec_uwIsum   = pr[ISUM_REC];
					rec_uwIGBT   = pr[TH_TEMP];
					rec_uwSRY    = pr[SRYREC];	
					rec_uwPWRmin = pr[PWR_MIN];

					// [ Add Fault Record Data, DINO, 06/11/2009
                  	pr[ERR_MIN1] = 0;
                  	write_ep(0,ERR_MIN1, 0);
                  	rec_uwErrMin1= 0;

                  	pr[ERR_DAY1] = 0;
                  	write_ep(0,ERR_DAY1, 0);
                  	rec_uwErrDay1= 0;

                  	pr[ERR_MIN2] = 0;
                  	write_ep(0,ERR_MIN2, 0);
                  	rec_uwErrMin2= 0;

                  	pr[ERR_DAY2] = 0;
                  	write_ep(0,ERR_DAY2, 0);
                  	rec_uwErrDay2= 0;

                  	pr[ERR_MIN3] = 0;
                  	write_ep(0,ERR_MIN3, 0);
                  	rec_uwErrMin3= 0;

                  	pr[ERR_DAY3] = 0;
                  	write_ep(0,ERR_DAY3, 0);
                  	rec_uwErrDay3= 0;

                  	pr[ERR_MIN4] = 0;
                  	write_ep(0,ERR_MIN4, 0);
                  	rec_uwErrMin4= 0;

                  	pr[ERR_DAY4] = 0;
                  	write_ep(0,ERR_DAY4, 0);
                  	rec_uwErrDay4= 0;

                  	pr[ERR_MIN5] = 0;
                  	write_ep(0,ERR_MIN5, 0);
                  	rec_uwErrMin5= 0;

                  	pr[ERR_DAY5] = 0;
                  	write_ep(0,ERR_DAY5, 0);
                  	rec_uwErrDay5= 0;

                  	pr[ERR_MIN6] = 0;
                  	write_ep(0,ERR_MIN6, 0);
                  	rec_uwErrMin6= 0;

                  	pr[ERR_DAY6] = 0;
                  	write_ep(0,ERR_DAY6, 0);
                  	rec_uwErrDay1= 0;

					pr[FKEY_REC] = 0;
					write_ep(0,FKEY_REC,0);
					rec_uwFkey	 = pr[FKEY_REC];

					pr[POWER_REC]= 0;
					write_ep(0,POWER_REC,0);
    				rec_uwPower  = pr[POWER_REC];

					pr[TQ_REC]   = 0;
					write_ep(0,TQ_REC,0);
    				rec_uwTorq   = pr[TQ_REC];

					pr[MFI_REC]  = 0;
					write_ep(0,MFI_REC,0);
    				rec_uwMFI    = pr[MFI_REC];

					pr[MFO_REC]  = 0;
					write_ep(0,MFO_REC,0);
    				rec_uwMFO    = pr[MFO_REC];

					pr[STATE_REC]= 0;
					write_ep(0,STATE_REC, 0);
					rec_uwState  = pr[STATE_REC];
					// ]
					//[ //[Running Dir Count,Special,2018/08/17] 
                    pr[IR_COUNT_H] = 0;
                    write_ep(0,IR_COUNT_H,0);
                    pr[IR_COUNT_L] = 0;
                    write_ep(0,IR_COUNT_L,0);
                    P06_79(IR_ENABLE,0);         
                    pr[IR_RESTEC] = 0;
                    write_ep(0,IR_RESTEC,0);
                    KEYEND = END;
                    //] //[Running Dir Count,Special,2018/08/17] 
		    	} break;
            case 5180:
                if(SHOW_ENHANCE){
                    SIBO_SPDCHG = 1;
                    if(SHOW_ALLPR){
                        SIBO_PARAMETER = 1; //[Group12&13 Limit count,Lyabryan,2020/09/10]
                    }
                }
                C21xx[0x20] |= 0x1000;  // [For VFD-Cx reload parameter information, Bernie, 09/22/2011]
                KEYEND = END;
            break;
			default:
				SHOW_ALLPR = 0;
          		KEYEND = END;
          	break;				
			
	    }
    }
}

void P00_03(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        switch(prx){
            case S_DISP:
                Keypad_Page = pr[S_DISP];
                break;
            case U_DISP:
                MFD_page = pr[U_DISP];
                break;
            default:
                break;
        }
    }
}

void P00_05(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        if (prvalue>10000){
            KPDdot = prvalue/10000;
            KPDmax = (prvalue - KPDdot * 10000);
        }
        else{
            KPDdot = 0;
            KPDmax = prvalue;
        }        
        KPDset = U16xU16divU16(KPDmax, uwFkeypad, pr[FMAX]);
    }
}

void P00_07(UWORD prx, UWORD prvalue)
{
	UWORD ax;

	ax = read_ep(PSW_SET);

    KEYEND = END;
#if DINO
    if (ax!=0){
    	if (prvalue==ax){
            if ( PRLOCK ){
                PSW_CNT = 0;
	            PRLOCK = 0;
	            pr[PSW_SET] = 0;		//00-08
//	            write_ep(BLK_WRITE,PSW_SET,0);
//	            pr[PASSWRD] = 0;		//12-80
//	            write_ep(BLK_WRITE,PASSWRD,0);
	            pr[PSW_IN] = 0;			//00-07
	            PASSWDUNCLOCK = 0;
	    	}
      	}
      	else if (prvalue==9999){
      		if ( PRLOCK ){
      			if (PASSWDUNCLOCK==1){  
					pr[PSW_SET] = 0;	//00-08
        			write_ep(BLK_WRITE,PSW_SET,0);
	            	PRLOCK	   = 0;
	            	PSW_CNT    = 0;
        			pr[PSW_IN] = 0;
        		
                  	wr_def2ep();
                  	DINT();
                  	InitValue();
                  	EINT();
	            	PASSWDUNCLOCK = 0;
	            }
	            else
	            	PASSWDUNCLOCK = 1;
	        }
		}
      	else{
      		if (PRLOCK){
        		PSW_CNT++;
        		if (PSW_CNT>=3)
          			Error = PcodE_ERR;
          	}
          	else{
				PRLOCK 		= 1;
				PSW_CNT		= 0;
  				pr[PSW_SET] = 1;			//00-08
        	}              
        	pr[PSW_IN] = PSW_CNT;			//00-07
      	}
    }
#else    
    if (pr[PASSWRD]!=0){
    	if (prvalue==pr[PASSWRD]){
            PSW_CNT = 0;
	        PRLOCK = 0;
	        pr[PSW_SET] = 0;				//00-08
	        write_ep(BLK_WRITE,PSW_SET,0);
	        pr[PASSWRD] = 0;				//15-98
	        write_ep(BLK_WRITE,PASSWRD,0);
	        pr[PSW_IN] = 0;
	        PASSWDUNCLOCK = 0;
      	}
      	else if (prvalue==9999){
      		if (PASSWDUNCLOCK==1){  
				if (pr[PSW_SET]==1){
                	SHOW_ENHANCE = 0;
                    SIBO_PARAMETER = 0; //[Group12&13 Limit count,Lyabryan,2020/09/10]
                    SIBO_SPDCHG = 0;
                    if(SIBO_ENABLE){
                        SIBO_SPDCHG = 1;
                        SIBO_PARAMETER = 1;
                    }
                	KEYEND = END;
              			
					pr[PSW_SET] = 0;
        			write_ep(BLK_WRITE,PSW_SET,0);
        			pr[PSW_IN] = 0;
        	
              		wr_def2ep();
              		DINT();
              		InitValue();
              		EINT();
				}			     	
	        	PASSWDUNCLOCK = 0;	        	
	        }
	        else
	        	PASSWDUNCLOCK = 1;
		}
      	else{
        	PSW_CNT++;
        	pr[PSW_IN] = PSW_CNT;		//00-07
        	if (PSW_CNT>=4){
          		Error = PcodE_ERR;
        	}              
      	}
    }
#endif
}

void P00_08(UWORD prx, UWORD prvalue)
{
	if (PRLOCK==0 && FSET_LOCK==0){
		if (prvalue==0){
			pr[PSW_SET] = 0;	// 00-08
			write_ep(BLK_WRITE,PSW_SET,prvalue);
    		KEYEND = END;
		}
		else if (prvalue!=9999){
			PRLOCK = 1;
#if DINO
	  		write_ep(BLK_WRITE,PSW_SET,prvalue);
	  		pr[PSW_SET] = 1;		// 00-08
    		KEYEND = END;
#else
			if (PSW_CNT==0){
	  			write_ep(BLK_WRITE,PSW_SET,prvalue);
	  			pr[PSW_SET] = 1;		// 00-08
	  			write_ep(BLK_WRITE,PASSWRD,prvalue);	  			
	  			pr[PASSWRD] = prvalue;	// 12-80
	  			PRLOCK = 1;
				KEYEND = END;
    		}
#endif
		}
    }
}

void P00_09(UWORD prx, UWORD prvalue)
{
    UBYTE mode_change;
    UWORD uwEEPData;
    SWORD swTemp;

#if SCOTTY
    if (prvalue>4 && prvalue<8){	//ADDED BY SCOTTY	2006/06/28
#else
    if (prvalue>4)
#endif    
    	if (SHOW_ALLPR==1){
    	    if ((prvalue <= attr[prx].max)&&(CMDRUN==STOP)){
    	        CTRLM_buf = pr[CTRLM];
    		    pr[CTRLM] = prvalue;
    		    KEYEND = END;
    		}
		}
    	else{
    		KEYEND = ERR;
    		PRUPDATE = 0;
    	}
    }
    else{
        if (((pr[CTRLM]^prvalue)&0x02)&&COPYEN==0)
            mode_change = 1;
        else
            mode_change = 0;

		uwEEPData = read_ep(prx);

    	if ( prvalue!=uwEEPData ){
        	if ( prvalue==FOCPM )
				STtune = 1;
        	else 
				STtune = 0; 
    	}
            
    	updatepr(prx,prvalue);
    	if (PRUPDATE==1){
#if !OLD_SETTING  // Modify by DINO, 09/09/2008
			MotorPrSel();
	    	Init_SpDtPG1_pr();
	    	// [ Calculate Fslip after change mode, Add by DINO, 06/03/2009
	    	VFPG_Init_SlipMax();
	    	// ]
#endif
    	    if (mode_change==1){
    	        if (pr[CTRLM]==SVC)
    	            prvalue = 100;
    	        else
    	            prvalue = 0;
    	    
    	        prx = SLIPC;
    	        updatepr(prx,prvalue);
    	        TB1_VFCal_Slin();
    	    }
    	}
  	}
  	
  	if ((pr[CTRLM]==FOCPG)||(pr[CTRLM]==TQCPG)||(pr[CTRLM]==FOCPM)){
  	    if (pr[PGINPUT]==5)
  	        pr[PGINPUT] = 0;

        if ( pr[CTRLM]==FOCPG || pr[CTRLM]==FOCPM )
            TqSpdMode = 0;
        else /*if (pr[CTRLM]==TQCPG)*/{
            TqSpdMode = 1;
  	    	swTemp = ((SWORD)pr[TQREF]);
			TqC_swTqSetPu = (((SLONG)swTemp*COF_uwTqMaxPu)+500)/1000;	    	            
        }    
    }
    else
        TqSpdMode = 0;

#if OLD_SETTING  // Modify by DINO, 09/09/2008
  	Motor1Pr();
	MotorPrInit();
	TQRMaxInit();	// Add by DINO, 05/30/2008
//	InitValue();
#endif
}

void P14_02(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1){
        if (prvalue==0){
            if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
            else
                pr[I_RATE] = CTispec[pr[HPSPEC]];
            // 3750000 = (150%-100%)*(150%-100%)*(60sec/40ms)
//            ulOLCNT    = 3750000;	
        }
        else {
            if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                pr[I_RATE] = VTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
            else
                pr[I_RATE] = VTispec[pr[HPSPEC]];
//            ulOLCNT    = 937500;	
        }
    }
}

void P14_04(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1){
        if (pr[U_ACCDEC]==0){
            pr[ACCEL1]=pr[ACCEL1]*10;
            pr[DECEL1]=pr[DECEL1]*10;
            pr[ACCEL2]=pr[ACCEL2]*10;
            pr[DECEL2]=pr[DECEL2]*10;
            pr[ACCEL3]=pr[ACCEL3]*10;
            pr[DECEL3]=pr[DECEL3]*10;
            pr[ACCEL4]=pr[ACCEL4]*10;
            pr[DECEL4]=pr[DECEL4]*10;
            pr[JOGACC]=pr[JOGACC]*10;
            pr[JOGDEC]=pr[JOGDEC]*10;
            pr[S4ACC1]=pr[S4ACC1]*10;
            pr[S4ACC2]=pr[S4ACC2]*10;
            pr[S4DEC1]=pr[S4DEC1]*10;
            pr[S4DEC2]=pr[S4DEC2]*10;
            pr[S4DEC3]=pr[S4DEC3]*10;            
            pr[DECEL5]=pr[DECEL5]*10;
            pr[DECEL_ESD]=pr[DECEL_ESD]*10;  //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
            pr[APRDECT]=pr[APRDECT]*10;
        }
        else{
            pr[ACCEL1]=pr[ACCEL1]/10;
            pr[DECEL1]=pr[DECEL1]/10;
            pr[ACCEL2]=pr[ACCEL2]/10;
            pr[DECEL2]=pr[DECEL2]/10;
            pr[ACCEL3]=pr[ACCEL3]/10;
            pr[DECEL3]=pr[DECEL3]/10;
            pr[ACCEL4]=pr[ACCEL4]/10;
            pr[DECEL4]=pr[DECEL4]/10;
            pr[JOGACC]=pr[JOGACC]/10;
            pr[JOGDEC]=pr[JOGDEC]/10;
            pr[S4ACC1]=pr[S4ACC1]/10;
            pr[S4ACC2]=pr[S4ACC2]/10;
            pr[S4DEC1]=pr[S4DEC1]/10;
            pr[S4DEC2]=pr[S4DEC2]/10;
            pr[S4DEC3]=pr[S4DEC3]/10;            
            pr[DECEL5]=pr[DECEL5]/10;
            pr[DECEL_ESD]=pr[DECEL_ESD]/10;  //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
            pr[APRDECT]=pr[APRDECT]/10;
        }
          write_ep(BLK_WRITE,ACCEL1,pr[ACCEL1]);
          write_ep(BLK_WRITE,DECEL1,pr[DECEL1]);
          write_ep(BLK_WRITE,ACCEL2,pr[ACCEL2]);
          write_ep(BLK_WRITE,DECEL2,pr[DECEL2]);
          write_ep(BLK_WRITE,ACCEL3,pr[ACCEL3]);
          write_ep(BLK_WRITE,DECEL3,pr[DECEL3]);
          write_ep(BLK_WRITE,ACCEL4,pr[ACCEL4]);
          write_ep(BLK_WRITE,DECEL4,pr[DECEL4]);
          write_ep(BLK_WRITE,JOGACC,pr[JOGACC]);
          write_ep(BLK_WRITE,JOGDEC,pr[JOGDEC]);
          write_ep(BLK_WRITE,S4ACC1,pr[S4ACC1]);
          write_ep(BLK_WRITE,S4ACC2,pr[S4ACC1]);
          write_ep(BLK_WRITE,S4DEC1,pr[S4DEC1]);
          write_ep(BLK_WRITE,S4DEC2,pr[S4DEC2]);
          write_ep(BLK_WRITE,S4DEC3,pr[S4DEC3]);
          write_ep(BLK_WRITE,DECEL5,pr[DECEL5]);
          write_ep(BLK_WRITE,DECEL_ESD,pr[DECEL_ESD]);  //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
          write_ep(BLK_WRITE,APRDECT,pr[APRDECT]);
        }
}

// Add by dino, 2006/08/07
void P08_10(UWORD prx, UWORD prvalue)
{
    if ( RUNNING==STOP ) {	// can't setting when running
	    if(prvalue <= attr[prx].max ){
            KEYEND = END ;
            pr[prx] = prvalue ;
            if ( prvalue==1 ) {
            	STtune = 1;
            	ALIGN = 1;	    //ADDED SCOTTY 2007/08/06
            	Zpulse = 1;
            	ZCALIB = 0;
				zcal_uwPulseErr = 0;			//SCOTTY 01/15/2008
				zcal_swThetaErr = 0;			//SCOTTY 01/15/2008
            	REPOS_FAULT_FLAG = 1;
    		    //MTU2S4.TSR.BYTE  &= 0xF7;		// clear TGFD flag, dino, 04/09/2007	
    		    MTU6.TSR.BYTE &= 0xF7;       // clear TGFD flag
    			if (pr[PG_TYPE]!=SIN_ENDAT && pr[PG_TYPE]!=SIN_HIPER)	// Don't interrupt Z-pulse when EnDat, dino, 08/29/2008
    		    	//MTU2S4.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable, dino, 04/09/2007 
    		    	MTU6.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable  
    		    uwInitialCnt++;
			}
			else {  // disable Z-align and standstill
           		if (prvalue==2){			//ADDED SCOTTY 2007/08/06
            		ALIGN = 0;			
            		if (pr[DCICL]==0)		//09/28/2007
            			pr[DCICL] = 10;
            	}
            	STtune = 0;
            	Zpulse = 0;
    		    //MTU2S4.TIER.BYTE &= 0xF7;	// TGIED, Z-pulse capture interrupt disable
                MTU6.TIER.BYTE &= 0xF7; // TGIED, Z-pulse capture interrupt disable
            }
        }
    }
}

void P08_09(UWORD prx, UWORD prvalue)  /* Modify by dino, 04/03/2007 */
{
	UWORD uw_temp;
/*	delect 09/17/2007	SC
	PG_Zoffset = U16xU16divU16(prvalue, SpDt_uwAnglePeriod, 3600);
    updatepr(prx,PG_Zoffset);
    pr[Z_OFFSET] = prvalue;
*/
//-ADD 09/17/2007	SC
    updatepr(prx,prvalue);
    if(PRUPDATE==1){
    	pr[Z_OFFSET] = prvalue;
    	PG_Zoffset = U16xU16divU16(prvalue, SpDt_uwAnglePeriod, 3600);
    }
// end 09/17/2007	SC    	
}

// [ Change Output Direction, Added by sampo , 06/11/2009
void P00_11(UWORD prx, UWORD prvalue)
{
    
	UWORD  uwThetaR_Temp, uwEEPData;
	SWORD swZ_OFFSET_Temp;
	SLONG slThetaR_Temp;

	uwEEPData = read_ep(CHG_DIR);

    updatepr(prx, prvalue);

    if (PRUPDATE == 1){
    	if (prvalue != uwEEPData){

			slThetaR_Temp = phase300 - (SpDt_ulThetaR>>16);
			if (slThetaR_Temp < 0){ slThetaR_Temp +=65536; }

			slThetaR_Temp = ((ULONG)(slThetaR_Temp * SpDt_ulPG1Npulse))>>16;
			uwThetaR_Temp = U32divU16(slThetaR_Temp, COF_ubMPolePair);

			Init_SpDtPG1_pr();

			if(PGDIR != 1){	uwThetaR_Temp = -uwThetaR_Temp;}

			//MTU21.TCNT = uwThetaR_Temp;
            MTU1.TCNT = uwThetaR_Temp;
			//SpDt_uwPG1100usCNT_Old = MTU21.TCNT;
            SpDt_uwPG1100usCNT_Old = MTU1.TCNT;

			SpDt_uwPG1CNT_Org = 0;

			if (pr[Z_OFFSET] != 3600){
				swZ_OFFSET_Temp = pr[Z_OFFSET];
				swZ_OFFSET_Temp = 3000 - swZ_OFFSET_Temp;
				if(swZ_OFFSET_Temp < 0){ swZ_OFFSET_Temp += 3600; }

				pr[Z_OFFSET] =  swZ_OFFSET_Temp;    
				write_ep(BLK_WRITE, Z_OFFSET, pr[Z_OFFSET]);
				PG_Zoffset = U16xU16divU16(SpDt_uwAnglePeriod, pr[Z_OFFSET], 3600);
			}
		}
	}
}
// ]

void P00_12(UWORD prx, UWORD prvalue)
{
    UBYTE HPSPEC_temp;

    HPSPEC_temp = pr[HPSPEC];     //[Single phase input, Bernie, 01/19/2012]
    if(HPSPEC_temp>VFD_SINGLEPHASE)
        HPSPEC_temp -= VFD_SINGLEPHASE;

    //if (prvalue<=maxcf(pr[HPSPEC])){
    if (prvalue<=maxcf(HPSPEC_temp)){ //[Single phase input, Bernie, 01/19/2012]
        updatepr(prx,prvalue);
        cf_swCFSet = pr[SETCRF] * 1000;
//        cf_swCFSet = cf_swCFReal;		//ADDED BY SCOTTY 2007/07/02
//        cf_swOHCarry = cf_swCFReal;				//ADDED BY SCOTTY 2007/07/02
//        n_period = U32divU16(MTU2CLK, cf_swCFReal);
//        experiod = n_period + (n_period>>1);    
    }
}
 
void P00_14(UWORD prx, UWORD prvalue)
{ 
/*
    if(fram_buf[prx] == 4){
                if(prvalue != 4){
                    KEYEND = END;
                    wr_def2ep();
                    //PrArea(prvalue);
                    DINT();
                    InitValue();
                    EINT(); 
                    
                }
        }
*/
 	updatepr(prx, prvalue);
 	
 	
    if (PRUPDATE==1){
     	
        if (pr[SOFC]==3)
            fexternal.ul = 0;
        /*
        if((prvalue == 4) || (prvalue == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
            facc1.ul = cal_time(pr[FMAX],0);
            fdec1.ul = cal_time(pr[FMAX],0);
            //facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
            //fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
            //facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
            //fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
            //facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
            //fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);	
            fjacc.ul = 0;	
            fjdec.ul = 0;	
            fdec5.ul = cal_time(pr[FMAX],0);
            //Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);

            DLC_Initial_value();
            write_ep(0,prx,prvalue);
        }
        */
    }    
}

void P14_07(UWORD prx, UWORD prvalue)	//Reverse Operation
{
	updatepr(prx,prvalue);
   	if ((PRUPDATE==1)&&(prvalue!=0)){
   		if (prvalue==1){
   			if (CMDDIR==REVERSE){
   				CMDDIR = FORWARD;
   			}
   		}
   		else{
   			if (CMDDIR==FORWARD){
   				CMDDIR = REVERSE;
   			}
   		}
   		if (RUNNING==STOP)              //Tinchung 11/10/2005
   		    WGDIR = CMDDIR;
   	}
}

void P01_00(UWORD prx, UWORD prvalue)	//FMAX
{

    ACC_Unit_SecToms2();
    updatepr(prx,prvalue);
   	if (PRUPDATE==1){      	
	    VcomFmax.ul = ((ULONG)pr[FMAX]<<16);	
        fstart = MAX(fmin,pr[FSTART]);
   	    fstart = MIN(pr[FMAX],fstart);
        if (pr[FMAIN]>pr[FMAX])
        	pr[FMAIN] = pr[FMAX];
        if (pr[FCMAIN]>pr[FMAX])
        	pr[FCMAIN] = pr[FMAX];
        if (uwFkeypad>pr[FMAX])
        	uwFkeypad = pr[FMAX];
        //--- Add by DINO, 08/20/2008
        if (C20xx[0x01]>pr[FMAX])
        	C20xx[0x01] = pr[FMAX];
                                    //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]

			
		//GFC Bernie Test    
		if((pr[SOFC] == 4) || (pr[SOFC] == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
            facc1.ul = cal_time(pr[FMAX],0);
            fdec1.ul = cal_time(pr[FMAX],0);
            facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
            fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
            facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
            fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
            facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
            fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);   
            fjacc.ul = cal_time(pr[FMAX],0);
            fjdec.ul = cal_time(pr[FMAX],0);
            fdec5.ul = cal_time(pr[FMAX],0);
            Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
            fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]);  //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            fdecEMY.ul = cal_time(pr[FMAX],pr[SIBO_DECEMY]);
#endif
        }
        else{			
			facc1.ul = cal_time(pr[FMAX],pr[ACCEL1]);
    	    fdec1.ul = cal_time(pr[FMAX],pr[DECEL1]);
    	    facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
    	    fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
    		facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
    		fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
    		facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
    		fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);
    		fdec5.ul = cal_time(pr[FMAX],pr[DECEL5]);
    		Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
	        fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]);  //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
        }
        if(SIBO_SPDCHG) //[ACC value reset to 0,Lyabryan,2020/09/10]
            ACC_Unit_ms2ToSec();
        
		SpdMaxPu = U32xU32divU32(pr[FMAX],0x7FFFFFFF,COF_uwFbRe); //Q31
		Init_SpDtPG1_pr();
    }        	 
}

void P01_01(UWORD prx, UWORD prvalue)
{
	ULONG_UNION FLimit;

    updatepr(prx,prvalue);
    
    uwOverAccLev = (((ULONG)(pr[OVER_ACC_LEVEL])*(pr[MFBASE1]/10))/(pr[Lift_SPD]))<<2;   //[Over Acceleration protection function, Bernie, 2017/02/13]
   
    if (PRUPDATE==1){
    	if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
    		if (prx==MFBASE2){
    			fbase = pr[MFBASE2];
			}
    	}
    	else{										// Motor 1
    		if (prx==MFBASE1){
    			fbase = pr[MFBASE1];
			}    		
		}
// [ Add by DINO, 03/04/2009
		COF_uwFBase1_4  = fbase >> 2;
		COF_uwFBase3_10 = ((ULONG)fbase * 77) >> 8;  // 0.3 = 77/256
// End 03/04/2009 ]
        MotorPrSel(); // [update motor pr for VF slip, Lyabryan, 2016/05/23]
		TB1_VFCal_Slin();
		VFPG_Init_SlipMax();		

		// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
		FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
		if (FLimit.ul > vbase){
			COF_uwVUPSRe = vbase;
		}
		else{
			COF_uwVUPSRe = FLimit.uw.low;
		}
		// ]
		//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
		COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//#13769 Modify EPS speed, James, 07/01/2020
		pr[FEPS] = COF_uwFepsLimit;

    }
}


void P01_02(UWORD prx, UWORD prvalue)   //VMAX
{
	ULONG_UNION FLimit;

	updatepr(prx,prvalue);
	if (PRUPDATE==1){        	        
	    //====== Motor Max. Rated Voltage in pu ================================//
	    // in Q15, 26754 = sqrt(2/3) * 32768
		if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
			if (prx==VMAX2){
				vbase = pr[VMAX2];
			}
		}
		else{										// Motor 1
			if (prx==VMAX1){
				vbase = pr[VMAX1];
                if(vbase == 0)              //[The minimum value setting of rated voltage, Bernie, 10/26/2011]
                    vbase = 1;
			}    		
		}
// [ Add by DINO, 03/06/2009
		COF_uwVBase1_4 = vbase >> 2;
		COF_uwVBase1_8= COF_uwVBase1_4 >> 1;
// ]
	    COF_uwVratePu = U16xU16divU16(vbase, 26755, COF_uwVbRe);
		TB1_VFCal_Slin();       	        

		// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
		FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
		if (FLimit.ul > vbase){
			COF_uwVUPSRe = vbase;
		}
		else{
			COF_uwVUPSRe = FLimit.uw.low;
		}
		// ]
		//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
		COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//#13769 Modify EPS speed, James, 07/01/2020
		pr[FEPS] = COF_uwFepsLimit;
	}
}
    
void P01_07(UWORD prx, UWORD prvalue)	// Fmin
{
	updatepr(prx,prvalue);
	if (PRUPDATE==1){
   		if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
   			if (prx==FMIN2){
   				fmin = pr[FMIN2];
			}
   		}
   		else{										// Motor 1
   			if (prx==FMIN1){
   				fmin = pr[FMIN1];
			}    		
		}		
       	fstart = MAX(fmin,pr[FSTART]);
       	fstart = MIN(pr[FMAX],fstart);
    }    
}

void P01_10(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    
    if (PRUPDATE==1){
        switch(prx){
      		case ACCEL1:
      			//facc1.ul = cal_time(pr[FMAX],prvalue);
      			// facc1, fdec1, v0.04
      			if((pr[SOFC] == 4) || (pr[SOFC] == 5))
      				facc1.ul = cal_time(pr[FMAX],0);
      			else	
      				facc1.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;      	
      		case DECEL1:
      			//fdec1.ul = cal_time(pr[FMAX],prvalue);
      			// facc1, fdec1, v0.04
      			if((pr[SOFC] == 4) || (pr[SOFC] == 5))
      				fdec1.ul = cal_time(pr[FMAX],0);
      			else
      				fdec1.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;
      		case ACCEL2:
      			facc2.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;      	
      		case DECEL2:
      			fdec2.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;
      		case ACCEL3:
      			facc3.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;      	
      		case DECEL3:
      			fdec3.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;
      		case ACCEL4:
      			facc4.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;      	
      		case DECEL4:
      			fdec4.ul = cal_time(pr[FMAX],pr[prx]);
      	    	break;      	
      	    case JOGACC:
                if((pr[SOFC] == 4) || (pr[SOFC] == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
                    fjacc.ul = 0;
                }
                else{
                    fjacc.ul = cal_time(pr[JOGF],pr[prx]);
                }
      	    	break;
      		case JOGDEC:    
                
                if((pr[SOFC] == 4) || (pr[SOFC] == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
                    fjdec.ul = 0;
                }
                else{
                    fjdec.ul = cal_time(pr[JOGF],pr[prx]);
                }
      		    break;
      		case JOGF:
                if((pr[SOFC] == 4) || (pr[SOFC] == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
                    fjdec.ul = 0;
                    fjacc.ul = 0;
                }
                else{
                    fjacc.ul = cal_time(pr[JOGF],pr[JOGACC]);
                    fjdec.ul = cal_time(pr[JOGF],pr[JOGDEC]);
                }
      		    break;
            case DECEL_ESD:         //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
                fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]);
                break;
      		case DECEL5:
      			if((pr[SOFC] == 4) || (pr[SOFC] == 5)){ 
      				  fdec5.ul = cal_time(pr[FMAX],0);
      			}
      			else{
      			    fdec5.ul = cal_time(pr[FMAX],pr[prx]);
      		    }
      	    	break;      	
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]				
            case SIBO_DECEMY:
      		    fdecEMY.ul = cal_time(pr[SIBO_DECEMY],pr[prx]);
      	    	break;  
#endif    	
      		case APRDECT:
      			Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
      			break;
      		case FUPPER:
      	    case FLOWER:
      		default:
      	    	break;
      	}
    }	  
}

void P01_33(UWORD prx, UWORD prvalue) // [IODLC, Lyabryan, 2016/11/11]
{

    updatepr(prx,prvalue);
    if(PRUPDATE==1){
        IODLC_Parameter_value();
    }
}

void SortFskip()
{
        UWORD ax;
        
        fskip1h = MAX(pr[FSKIP1H],pr[FSKIP1L]);
        fskip2h = MAX(pr[FSKIP2H],pr[FSKIP2L]);
        fskip3h = MAX(pr[FSKIP3H],pr[FSKIP3L]);
        if (fskip1h<fskip2h){
            if (fskip1h<fskip3h){
                fskip1l = MIN(pr[FSKIP1H],pr[FSKIP1L]); 
                if (fskip2h<fskip3h){
                    // skip1 < skip2 < skip3
                    fskip2l = MIN(pr[FSKIP2H],pr[FSKIP2L]); 
                    fskip3l = MIN(pr[FSKIP3H],pr[FSKIP3L]); 
                }
                else{
                    // skip1 < skip3 < skip2
                    ax = fskip2h;                           
                    fskip2h = fskip3h;
                    fskip2l = MIN(pr[FSKIP3H],pr[FSKIP3L]); 
                
                    fskip3h = ax;                           
                    fskip3l = MIN(pr[FSKIP2H],pr[FSKIP2L]); 
                }    
            }    
            else{
                // skip3 < skip1 < skip2
                ax = fskip1h;                           
                fskip1h = fskip3h;
                fskip1l = MIN(pr[FSKIP3H],pr[FSKIP3L]); 
                
                ax = fskip2h;
                fskip2h = fskip1h;
                fskip2l = MIN(pr[FSKIP1H],pr[FSKIP1L]); 
                
                fskip3h = ax;                           
                fskip3l = MIN(pr[FSKIP2H],pr[FSKIP2L]); 
            }    
        }    
        else{
            if (fskip3h>fskip1h){
                // skip2 < skip1 < skip3
                ax = fskip1h;                           
                fskip1h = fskip2h;
                fskip1l = MIN(pr[FSKIP2H],pr[FSKIP2L]); 
                
                fskip2h = ax;                           
                fskip2l = MIN(pr[FSKIP1H],pr[FSKIP1L]); 
                
                fskip3l = MIN(pr[FSKIP3H],pr[FSKIP3L]); 
                
            }
            else{    
                if (fskip2h>fskip3h){   
                    // skip3 < skip2 < skip1
                    ax = fskip1h;                           
                    fskip1h = fskip3h;
                    fskip1l = MIN(pr[FSKIP3H],pr[FSKIP3L]); 
                
                    fskip2l = MIN(pr[FSKIP2H],pr[FSKIP2L]); 
               
                    fskip3h = ax;                           
                    fskip3l = MIN(pr[FSKIP1H],pr[FSKIP1L]); 
                }
                else{
                    // skip2 < skip3 < skip1
                    ax = fskip1h;                           
                    fskip1h = fskip2h;
                    fskip1l = MIN(pr[FSKIP2H],pr[FSKIP2L]); 
                
                    fskip2h = fskip3h;
                    fskip2l = MIN(pr[FSKIP3H],pr[FSKIP3L]); 
                
                    fskip3h = ax;                           
                    fskip3l = MIN(pr[FSKIP1H],pr[FSKIP1L]); 
                }    
            }    
        }    
}    

void P14_08(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1)
        SortFskip();
    
}    

void P02_00(UWORD prx, UWORD prvalue)
{
    UBYTE j, ubMCChk, ubBKChk1, ubBKChk2;   //[change for EN81-1+A3, Bernie, 2015/03/16];

    updatepr(prx,prvalue);
    if (PRUPDATE==1){
        if (prvalue>=4){	// Debug by DINO, 10/16/2008
            pr[MI1]=0;
            write_ep(BLK_WRITE,MI1,0);
//-- Add by Dino, 11/28/2008
			speed 		   = 0;
	        acc_dec 	   = 0;
	        EXT_AISEL 	   = 0;
	        MFI_TQCSel     = 0;
	        mfi0_status.ub = 0;
	        mfi1_status.ub = 0;
	        mfi2_status.ub = 0;
	        ext_status.ub  = 0;
	        ext1_status.ub = 0;
	        ext2_status.ub = 0;
	        ext3_status.ub = 0;  //[CAN Control, Sampo, 09/15/2010]
//-- End on 11/28/2008

			// [ MC Confirm and BK Confirm function check, add by DINO, 03/11/2009
			ubMCChk = 0;
			ubBKChk1 = 0;
            ubBKChk2 = 0;
			for (j=MI1;j<=MI8;j++){
	    		if (pr[j]==MFI_ASRSwitch){	// 27:ASR1 to ASR2
	        		EXT_ASREN = 1;
				}
				if (pr[j] == MFI_MC_IN){	// 41:Magnetic Contactor Signal Input
					ubMCChk = 1;
				}
				if (pr[j] == MFI_BK_IN1){	// 42:Mechanical Brake Signal Input 1
					ubBKChk1 = 1;
				}
                if (pr[j] == MFI_BK_IN2){	// 44:Mechanical Brake Signal Input 2   //[change for EN81-1+A3, Bernie, 2015/03/16];
					ubBKChk2 = 1;
				}
			}
			MCCHK_ENABLE = ubMCChk;
			BKCHK_ENABLE1 = ubBKChk1;  //[change for EN81-1+A3, Bernie, 2015/03/16]
	        BKCHK_ENABLE2 = ubBKChk2;  //[change for EN81-1+A3, Bernie, 2015/03/16]
			// ]
        }
    }
}

void P02_01(UWORD prx, UWORD prvalue)
{
    UBYTE j, ubMCChk, ubBKChk1,ubBKChk2;  //[change for EN81-1+A3, Bernie, 2015/03/16]	
	
    if (prvalue==0){
		updatepr(prx,prvalue);
    }
    else if ((prvalue<=MFIMAX)&&(pr[WIRE2_3]<4 )){
        for (j=MI2;j<=MI8;j++){ //Compare with the other MFITx setting
			if (prvalue==pr[j]){
				j = 0;               //if prvalue is the same with the other setting, j=0
				KEYEND = ERR;
				break;
			}    
		}
        
		if (j!=0){
			updatepr(prx,prvalue);
		}
	}    

	if (PRUPDATE==1){
	    speed 			= 0;
	    acc_dec			= 0;
	    EXT_AISEL		= 0;
	    MFI_TQCSel		= 0;
	    mfi0_status.ub	= 0;
	    mfi1_status.ub	= 0;
	    mfi2_status.ub	= 0;
	    ext_status.ub	= 0;
	    ext1_status.ub	= 0;
	    ext2_status.ub	= 0;
	    ext3_status.ub  = 0; //[CAN Control, Sampo, 09/15/2010]

		// [ MC Confirm and BK Confirm function check, add by DINO, 03/11/2009
		ubMCChk = 0;
        ubBKChk1 = 0;
		ubBKChk2 = 0;  //[change for EN81-1+A3, Bernie, 2015/03/16]	
		for (j=MI1;j<=MI8;j++){
	    	if (pr[j]==MFI_ASRSwitch){	// 27:ASR1 to ASR2
	        	EXT_ASREN = 1;
			}
			if (pr[j] == MFI_MC_IN){	// 41:Magnetic Contactor Signal Input
				ubMCChk = 1;
			}
			if (pr[j] == MFI_BK_IN1){	// 42:Mechanical Brake Signal Input 1
				ubBKChk1 = 1;
			}
            if (pr[j] == MFI_BK_IN2){	// 44:Mechanical Brake Signal Input 2   //[change for EN81-1+A3, Bernie, 2015/03/16]
				ubBKChk2 = 1;
			}
		}
		MCCHK_ENABLE = ubMCChk;
		BKCHK_ENABLE1 = ubBKChk1;  //[change for EN81-1+A3, Bernie, 2015/03/16]
	    BKCHK_ENABLE2 = ubBKChk2;  //[change for EN81-1+A3, Bernie, 2015/03/16]
		// ]
	}      


}

void P02_02(UWORD prx, UWORD prvalue)
{
    UBYTE j, ubMCChk, ubBKChk1,ubBKChk2;  //[change for EN81-1+A3, Bernie, 2015/03/16]	

    if (prvalue==0){
        updatepr(prx,prvalue);
    }
    else if (prvalue<=MFIMAX){
        for (j=MI1;j<=MI8;j++){   //Compare with the other MFITx setting,Max.SJ
            if ((prvalue==pr[j])&&(j!=prx)){
                j = 0;               //if prvalue is the same with the other setting, j=0
                KEYEND = ERR;
                break;
            }
        }		

        if (j!=0){
            updatepr(prx,prvalue);
        }
    }

	if (PRUPDATE==1){
	    speed 			= 0;
	    acc_dec			= 0;
	    EXT_AISEL		= 0;
	    MFI_TQCSel		= 0;
	    mfi0_status.ub	= 0;
	    mfi1_status.ub	= 0;
	    mfi2_status.ub	= 0;
	    ext_status.ub	= 0;
	    ext1_status.ub	= 0;
	    ext2_status.ub	= 0;

		// [ MC Confirm and BK Confirm function check, add by DINO, 03/11/2009
		ubMCChk = 0;
        ubBKChk1 = 0;
		ubBKChk2 = 0;   //[change for EN81-1+A3, Bernie, 2015/03/16]
		for (j=MI1;j<=MI8;j++){
	    	if (pr[j]==MFI_ASRSwitch){	// 27:ASR1 to ASR2
	        	EXT_ASREN = 1;
			}
			if (pr[j] == MFI_MC_IN){	// 41:Magnetic Contactor Signal Input
				ubMCChk = 1;
			}
			if (pr[j] == MFI_BK_IN1){	// 42:Mechanical Brake Signal Input
				ubBKChk1 = 1;
			}
            if (pr[j] == MFI_BK_IN2){	// 42:Mechanical Brake Signal Input     //[change for EN81-1+A3, Bernie, 2015/03/16]				
                ubBKChk2 = 1;
			}
		}
		MCCHK_ENABLE = ubMCChk;
		BKCHK_ENABLE1 = ubBKChk1;  //[change for EN81-1+A3, Bernie, 2015/03/16]
	    BKCHK_ENABLE2 = ubBKChk2;  //[change for EN81-1+A3, Bernie, 2015/03/16]
		// ]
	}        
}

void P02_11(UWORD prx, UWORD prvalue)
{
    UBYTE j;
    
    if (prvalue==0){
        //for(j=RLY1;j<=MO4;j++){
       updatepr(prx,prvalue);
            if((STAR_CONTACTOR)
              &&(pr[RLY1]!=MFO_STAR_CON)
              &&(pr[RLY2]!=MFO_STAR_CON)
              &&(pr[MO1]!=MFO_STAR_CON)
              &&(pr[MO2]!=MFO_STAR_CON)
              &&(pr[MO3]!=MFO_STAR_CON)
              &&(pr[MO4]!=MFO_STAR_CON)
			  //[ //[New addition IO card,Lyabryan,2019/07/22]
              &&(pr[MO5]!=MFO_STAR_CON)
              &&(pr[MO6]!=MFO_STAR_CON)
              &&(pr[MO7]!=MFO_STAR_CON)
              &&(pr[MO8]!=MFO_STAR_CON)){
              //] //[New addition IO card,Lyabryan,2019/07/22]
                  STAR_CONTACTOR = 0;
            }
        //}
        
    }
    else if((prvalue!=0) && (prvalue<=MFOMAX)){
        updatepr(prx,prvalue);
        
        for(j=RLY1;j<=MO8;j++){ 
            if(pr[j] == MFO_STAR_CON){
                STAR_CONTACTOR = 1;
            }
           
        }
        if((STAR_CONTACTOR)
            &&(pr[RLY1]!=MFO_STAR_CON)
            &&(pr[RLY2]!=MFO_STAR_CON)
            &&(pr[MO1]!=MFO_STAR_CON)
            &&(pr[MO2]!=MFO_STAR_CON)
            &&(pr[MO3]!=MFO_STAR_CON)
            &&(pr[MO4]!=MFO_STAR_CON)
            &&(pr[MO5]!=MFO_STAR_CON)
            &&(pr[MO6]!=MFO_STAR_CON)
            &&(pr[MO7]!=MFO_STAR_CON)
            &&(pr[MO8]!=MFO_STAR_CON)){
                STAR_CONTACTOR = 0;
        }
        
        
    }
}


/*
void P02_11(UWORD prx, UWORD prvalue)
{
    UBYTE j;
    if (prvalue==0){
        updatepr(prx,prvalue);
    }
    else if (prvalue<=MFOMAX){
        for (j=RLY1;j<=MO10;j++){
            if ((prvalue>=31)&&(prvalue<=32)){            
                if ((prvalue==pr[j])&&(j!=prx)){
                    j = 0;  //if prvalue is the same with the other setting, j=0
                    KEYEND = ERR;
                    break;
                }
                if (prvalue==MFO_YCONFUN)
                    YDSetBit |= 0x01;
                if (prvalue==MFO_DCONFUN)
                    YDSetBit |= 0x10;    
            }
        }
        
        if (j!=0){
            updatepr(prx,prvalue);
        }
    }
}
*/

void P05_00(UWORD prx, UWORD prvalue)
{
    if (PRLOCK==0 && FSET_LOCK==0){
    	if (prvalue == 0){
    		KEYEND = END;
    	}
    	else{
    		if (pr[PM_AUTO_T]==0){
        		if ((prvalue <= attr[prx].max)&&(CMDRUN==STOP)){
        	    	if (SHOW_ALLPR==1){
        	        	KEYEND = END;
        	        	pr[prx] = prvalue;
        	    	}
        	    	else{
        	        	if (prvalue<6){
        	            	KEYEND = END;
        	            	pr[prx] = prvalue;
        	        	}
        	    	}
        		}
    		}
    		else{
    			KEYEND = ERR;
    		}
    	}
    }
}

void P05_01(UWORD prx, UWORD prvalue)   // MI_RAT1 & MI_RAT2
{
    UWORD uwIrated;
    ULONG ul_temp;
    UWORD MIRate,MIRate_tmp;
    
    updatepr(prx,prvalue);
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==MI_RAT2){            
                COF_uwMIrRe = prvalue;
                if (prvalue < pr[MI_NL2]){
                    pr[MI_NL2] = prvalue;
                    write_ep(BLK_WRITE,MI_NL2,prvalue);
                }    
            }
        }
        else{
            if (prx==MI_RAT1){
                COF_uwMIrRe = prvalue;
                if (prvalue < pr[MI_NL1]){
                    pr[MI_NL1] = prvalue;
                    write_ep(BLK_WRITE,MI_NL1,prvalue);
                }
            }
        }

#if STtest
        STDutyInit();	// dino, 2006/08/15
#endif  
         /*--------------------------- Add by dino 11.07.2006 ------------------------------
         -- Calculate the current AD level for Stnadstill                                 --
         -- COF_uwSSIratedPu = COF_uwMIrRe * 1.8 / pr[I_RATE] / sqrt(2) / 2.5 * 512 * 2^6 --
         -- 1.6 = 26214 / 2^14                                                            --
         -- 1/sqrt(2) = 46341 / 2^16                                                      --
         -- 1/2.5 = 2/5                                                                   --
         ---------------------------------------------------------------------------------*/ 

        if ( pr[STI]==0 ){
        	if ( COF_uwMIrRe > pr[I_RATE] ){ uwIrated = pr[I_RATE]; }
        	else { uwIrated = COF_uwMIrRe; }
        }
        else
        	uwIrated = pr[STI];
        COF_uwSSIratedPu = ((ULONG)uwIrated * 26214 / pr[I_RATE] * 46341 >> 14) / 5;
              
        COF_uwMIratePu = U32xU32divU32(COF_uwMIrRe ,46341, COF_ulIbRe);
        if (pr[CTSEL]==0)
            mspec = U16xU16divU16(COF_uwMIratePu, 100, COF_uwCTIratePu);
        else
            mspec = U16xU16divU16(COF_uwMIratePu, 100, COF_uwVTIratePu);
        
        set_VcmpMax();
        TB1_VFCal_Slin(); 
        
//        if (pr[CTRLM] == FOCPM){  				//ADDED BY SCOTTY
//	    	TQRBaseInit();          
//        }                 
#else
		if (prx==MI_RAT2)
			uwIrated = MI_NL2;
		else
			uwIrated = MI_NL1;

		if (prvalue<pr[uwIrated]){
			pr[uwIrated] = prvalue;
			write_ep(BLK_WRITE,uwIrated,prvalue);
		}

        //[ //[Noload current default,Lyabryan,2016/05/12]
        
        MIRate_tmp = prvalue;    // 3686 / 2^12 = 0.8999023 // motor rated = CTi*0.9
        //MIRate = ((ULONG)COF_uwIIratePu*1638)>>12;    // 1638 / 2^12 = 0.3999023
        MIRate = ((ULONG)COF_uwIIratePu*((prvalue<<12)/pr[I_RATE]))>>12;    // 3686 / 2^12 = 0.8999023
        if(pr[HPSPEC]>=VFD370V23A){
            if(pr[HPSPEC]<VFD_SINGLEPHASE)
                MIRate = MIRate*3000/10000;    // 3686 / 2^12 = 0.8999023                            
            else
                MIRate = MIRate*3500/10000;    // 3686 / 2^12 = 0.8999023                           
        }
        else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD220V)){
            if(prvalue<=((CTispec[10]*3686)>>12))
                MIRate = MIRate*3500/10000;
            else    
                MIRate = MIRate*(((SLONG)prvalue*(-5681)+468046114)>>17)/10000;    // 3686 / 2^12 = 0.8999023
        }
        else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD440V)){            
            if(prvalue<=((CTispec[11]*3686)>>12))
                MIRate = MIRate*3500/10000;
            else    
                MIRate = MIRate*(((SLONG)prvalue*(-5846)+234874163)>>16)/10000;    // 3686 / 2^12 = 0.8999023
        }
        write_ep(BLK_WRITE,MI_NL1,MIRate);
        COF_uwIm1Pu = MIRate;
        //] //[Noload current default,Lyabryan,2016/05/12]
		MotorPrSel();
        set_VcmpMax();
        TB1_VFCal_Slin(); 
        pr[MI_NL1] = U32xU32divU32(MIRate ,COF_ulIbRe, 46341); //[Noload current default,Lyabryan,2016/05/12]
#endif
    }
}

void P05_02(UWORD prx, UWORD prvalue)   // P_RATED1 & P_RATED2
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        pr[prx] = prvalue;        
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==P_RATED2){
                COF_uwMPRe = prvalue;                
            }
        }
        else{
            if (prx==P_RATED1){
                COF_uwMPRe = prvalue;
            }
        }

//		if (pr[CTRLM] == FOCPM){	
//	    	TQRBaseInit();
//		}
//		else{
    	    COF_uwJbRe = JmTalbe(COF_uwMPRe);
      		EsJ_uwKJGain = U16xU16divU16((3183* COF_uwPole)<< 1, COF_uwTbRe, COF_uwFbRe); //Q1
	    	EsJ_uwKJGain = U16xU16divU16(EsJ_uwKJGain, 2048, COF_uwJbRe); //Q12
      		SPR_uwKpKiGain = U32xU32divU32(20213, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q9		     
    		SPR_uwKrGain = U32xU32divU32(12868, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q11		     
        
//    	}
    	TQRMaxInit();
#else
		MotorPrSel();
#endif
    }    
}

void P05_03(UWORD prx, UWORD prvalue)   // RPM_RATED1 & RPM_RATED2
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==RPM_RATED2)
                COF_uwRPMRe = prvalue;
        }
        else{
            if (prx==RPM_RATED1)
                COF_uwRPMRe = prvalue;
        }
        TQRMaxInit();
#else
		MotorPrSel();
#endif
        VFPG_Init_SlipMax();
        TB1_VFCal_Slin();
        
//		if (pr[CTRLM] == FOCPM){	//ADDED BY SCOTTY 12/22/2006
//	    	TQRBaseInit();
//		}    
    }

}

void P05_04(UWORD prx, UWORD prvalue)   // POLES1 & POLES2
{
    if ((prvalue&0x0001)==0x0000){
        ACC_Unit_SecToms2();
	    updatepr(prx, prvalue);
		if (PRUPDATE==1){        
			MotorPrSel();
	    	Init_SpDtPG1_pr();
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            pr[Lift_SPD_RPM] = (120*(flMetric2Hz(pr[Lift_SPD])/100))/COF_uwPole;//[Sibocom Lift speed(11-01) convert to moter speed, Jason, 20200110]
#endif
            if(SIBO_SPDCHG) //[ACC value reset to 0,Lyabryan,2020/09/10]
                ACC_Unit_ms2ToSec();

		}
    }
    else
        KEYEND = ERR;
}

void P05_05(UWORD prx, UWORD prvalue)   // MI_NL1 & MI_NL2
{
	UWORD PuTemp;

    PuTemp = U32xU32divU32(prvalue ,46341, COF_ulIbRe);
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==MI_NL2){
                COF_uwI0Pu = PuTemp;
                COF_uwMI0Re = prvalue;                
            }
        }
        else{
            if (prx==MI_NL1){
                COF_uwI0Pu = PuTemp;
                COF_uwMI0Re = prvalue;                
            }
        }
       	COF_uwKt = ((ULONG)COF_uwLmPu * COF_uwI0Pu) >> 13; //Q8 = Q(6+15-13)
#else
		if (prx==MI_NL1)
    		COF_uwIm1Pu = PuTemp;
		else
    		COF_uwIm2Pu = PuTemp;
		MotorPrSel();
#endif
    }
}

void P05_06(UWORD prx, UWORD prvalue)   // Rs1 & Rs2
{
    UWORD PuTemp;
    
    PuTemp = U16xU16divU16(prvalue, 16384, COF_uwRbRe);	//Q15
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==Rs2){
                COF_uwRsPu = PuTemp;
                COF_uwMRsRe = prvalue;
            }
        }
        else{
            if (prx==Rs1){
                COF_uwRsPu = PuTemp;
                COF_uwMRsRe = prvalue;
            }
        }
#else
		if (prx==Rs1)
    		COF_uwRs1Pu = PuTemp;
		else
    		COF_uwRs2Pu = PuTemp;
		MotorPrSel();
#endif
        set_Rs();
        set_VcmpMax();
    }    
}

void P05_07(UWORD prx, UWORD prvalue)   // Rr1 & Rr2
{
	UWORD PuTemp;

    PuTemp = U16xU16divU16(prvalue, 16384, COF_uwRbRe);	//Q15
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==Rr2){
                COF_uwRrPu = PuTemp;
            }
        }
        else{
            if (prx==Rr1){
                COF_uwRrPu = PuTemp;
            }
        }            
        //Tr_inv, Inverse of rotor time constant = (Lm/Rr) in Q(15+13-6)
        COF_Tr_inv = U16xU16divU16(COF_uwRrPu, 8192, COF_uwLmPu); //Q22        
        //IdsLPG = T*1/Tr = T*Rr/Lm = T*(RrPu/LmPu)*(Rb/Lb) = 2*pi*Fb*100us*Tr_inv
        //24707 = 2*pi*Fb*100us*2^16
        COF_uwIdsLPG = ((ULONG)24707 * COF_Tr_inv) >> 22; //Q16=Q(16+22-22)
#else
		if (prx==Rr1)
    		COF_uwRr1Pu = PuTemp;
		else
    		COF_uwRr2Pu = PuTemp;
		MotorPrSel();
#endif
    }
}

void P05_08(UWORD prx, UWORD prvalue)   // Lm1 & Lm2
{
    UWORD PuTemp;

    PuTemp = U16xU16divU16(prvalue, 3200, COF_uwLbRe);	//Q6
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==Lm2){
                COF_uwLmPu = PuTemp;
            }
        }
        else{
            if (prx==Lm1){
                COF_uwLmPu = PuTemp;
            }
        }
        //Tr_inv, Inverse of rotor time constant = (Lm/Rr) in Q(15+9-6)
		COF_Tr_inv = U16xU16divU16(COF_uwRrPu, 512, COF_uwLmPu); //Q18
		//IdsLPG = T*1/Tr = T*Rr/Lm = T*(RrPu/LmPu)*(Rb/Lb) = 2*pi*Fb*100us*Tr_inv
		//24707 = 2*pi*Fb*100us*2^16
		COF_uwIdsLPG = ((ULONG)24707 * COF_Tr_inv) >> 22; //Q16=Q(16+22-22)
		COF_uwKt = ((ULONG)COF_uwLmPu * COF_uwI0Pu) >> 13; //Q8 = Q(6+15-13)     
#else
		if (prx==Lm1)
    		COF_uwLm1Pu = PuTemp;
		else
    		COF_uwLm2Pu = PuTemp;
		MotorPrSel();
#endif
    }    
}

void P05_09(UWORD prx, UWORD prvalue)   // Lx1 & Lx2
{
	UWORD PuTemp;

    PuTemp = U16xU16divU16(prvalue, 51200, COF_uwLbRe);	//Q10
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){        
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){	// Motor 2 highest priority
            if (prx==Lx2)
                COF_uwLxPu = PuTemp;            
        }
        else{
            if (prx==Lx1)
                COF_uwLxPu = PuTemp;
        }
#else
		if (prx==Lx1)
    		COF_uwLx1Pu = PuTemp;
		else
    		COF_uwLx2Pu = PuTemp;
		MotorPrSel();
#endif
	}
}

void P14_51(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        if (prvalue==2){	// Motor 2
            Motor2Pr();
            if ((YDSetBit&0x30)==0x30){
                MFO_YCON = 0;
                MFO_DCON = 1;
                DOnCNT = pr[YDDELAYT];
                YOnCNT = 0;                    
            }                
        }            
        else if (prvalue==1){	// Motor 1
            Motor1Pr();
            if ((YDSetBit&0x03)==0x03){
                MFO_DCON = 0;
                MFO_YCON = 1;
                YOnCNT = pr[YDDELAYT];
                DOnCNT = 0;
            }
        }
		TQRBaseInit();
		TQRMaxInit();
		MotorPrInit();
#else
        if (prvalue==2){	// Motor 2
            if ((YDSetBit&0x30)==0x30){
                MFO_YCON = 0;
                MFO_DCON = 1;
                DOnCNT = pr[YDDELAYT];
                YOnCNT = 0;                    
            }                
        }            
        else if (prvalue==1){	// Motor 1
            if ((YDSetBit&0x03)==0x03){
                MFO_DCON = 0;
                MFO_YCON = 1;
                YOnCNT = pr[YDDELAYT];
                DOnCNT = 0;
            }
        }
		MotorPrSel();
#endif
        TB1_VFCal_Slin();
        VFPG_Init_SlipMax();		    
	}
}

void P14_53(UWORD prx, UWORD prvalue)	// Y-Delta switched Enable
{
	ULONG_UNION FLimit;

    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        if (prvalue==1){
        	Motor1Pr();
        	if ((YDSetBit&0x03)==0x03){		// Y-Connected
                MFO_DCON = 0;
                MFO_YCON = 1;
                YOnCNT = pr[YDDELAYT];
                DOnCNT = 0;
            }
            fbase = pr[MFBASE1];
            vbase = pr[VMAX1];
            if(vbase == 0)         //[The minimum value setting of rated voltage, Bernie, 10/26/2011]
                vbase = 1;
// [ Add by DINO, 03/06/2009
			COF_uwVBase1_4  = vbase >> 2;
			COF_uwVBase1_8  = COF_uwVBase1_4 >> 1;
			COF_uwFBase1_4  = fbase >> 2;
			COF_uwFBase3_10 = ((ULONG)fbase * 77) >> 8;  // 0.3 = 77/256
// ]
            fmin = pr[FMIN1];
          	TB1_VFCal_Slin();
        	VFPG_Init_SlipMax();

			// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
			FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
			if (FLimit.ul > vbase){
				COF_uwVUPSRe = vbase;
			}
			else{
				COF_uwVUPSRe = FLimit.uw.low;
			}
			// ]
			//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
			COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//#13769 Modify EPS speed, James, 07/01/2020
			pr[FEPS] = COF_uwFepsLimit;
        }            
    }
}

void P02_33(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        uwIsDtL = ((ULONG)prvalue * pr[I_RATE])/100;
    }
}

void P03_15(UWORD prx, UWORD prvalue)  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        if(prvalue>0)
            AUI_TUNE = 1;
        else{
            AUI_TUNE_FINISH = 0;
            AUI_TUNE = 0;
        }
    }
    
}

// DLC function, Henry, 2016/07/20
void P04_23(UWORD prx, UWORD prvalue)
{
	UWORD i;	
	
	updatepr(prx, prvalue);
	i = prvalue;
	
	if((DLC_btLU == 1) && (DLC_btLD == 1) && (fcmd.uw.hi == 0) &&  // LU, LD, zero-spd
		 (i <= DLC_ubLevMax) && (i >= DLC_ubLevMin)){
		DLC_ulPgCnt = DLC_ulPgLev[i];
		DLC_ubLevCur = i;
		pr[LEV_CUR] = i;
	}
}


void P04_49(UWORD prx, UWORD prvalue){
  UWORD i;
  
    updatepr(prx, prvalue);
   
    if (prvalue == 0){  //prvalue = 0 
        for(i=0; i<DLC_25ADDR; i++){
        // DLC position offset, Henry
          pr[FL_POSIT_1H+i]= DLCxx[i]; 
        }
    }    
    else if(prvalue == 1){    //prvalue = 1    
        for(i=DLC_25ADDR; i<DLC_50ADDR; i++){
          // DLC position offset, Henry
          pr[FL_POSIT_1H+i-DLC_25ADDR]= DLCxx[i]; 
        }
    }
    else if(prvalue == 2){    //prvalue = 2 // 04-49=2 page display, Henry, 2017/05/25
      for(i=DLC_50ADDR; i<DLC_75ADDR; i++){
      	// DLC position offset, Henry
        pr[FL_POSIT_1H+i-DLC_50ADDR]= DLCxx[i]; 
      }
    }

    else if(prvalue == 3){    //[adjust floor position adjust,Aevin,2018/06/19] //prvalue = 3 floor offset ----Aevin 6/19/2018
      for(i=DLC_75ADDR; i<DLC_LimADDR; i++){
      	// DLC position offset, Henry
        pr[FL_POSIT_1H+i-DLC_75ADDR]= DLCxx[i]; 
      }
    }
    else if(prvalue == 4){   //[adjust floor position,Henry,2019/01/07]  //[adjust floor position adjust,Aevin,2018/06/19] //prvalue = 3 floor offset ----Aevin 6/19/2018
      for(i=DLC_LimADDR; i<DLC_Adj50ADDRUP; i++){
        pr[FL_POSIT_1H+i-DLC_LimADDR]= DLCxx[i];
      }
    }
    else if(prvalue == 5){   //[adjust floor position,Henry,2019/01/07]  //[adjust floor position adjust,Aevin,2018/06/19] //prvalue = 3 floor offset ----Aevin 6/19/2018
      for(i=DLC_Adj50ADDRUP; i<DLC_Adj50ADDRDN; i++){
        pr[FL_POSIT_1H+i-DLC_Adj50ADDRUP]= DLCxx[i];
      }
    }
    else if(prvalue == 6){   //[adjust floor position,Henry,2019/01/07]  //[adjust floor position adjust,Aevin,2018/06/19] //prvalue = 3 floor offset ----Aevin 6/19/2018
      for(i=DLC_Adj50ADDRDN; i<DLC_Adj5175ADDRUPDN; i++){
        pr[FL_POSIT_1H+i-DLC_Adj50ADDRDN]= DLCxx[i];
      }
    }
	
	//Only scan DLC attribute instead of scanning all  PR groups , James, 2021/02/23
    if(prvalue ==0){
        for(i = 0; i<EPMAX; i++){
            attr[i] = attr1[i];
        }
    }
    else if(prvalue == 1){
        for(i = DLC_PR; i<GROUP5; i++){
			attr[i] = attr_DLC1[i-DLC_PR];
        }
    }
 		else if(prvalue == 2){
        for(i = DLC_PR; i<GROUP5; i++){
			attr[i] = attr_DLC2[i-DLC_PR];
        }
    }
    else if(prvalue == 3){
        for(i = DLC_PR; i<GROUP5; i++){
			attr[i] = attr_DLC3[i-DLC_PR];
        }
    }    
    else if(prvalue == 4){ 
        for(i = DLC_PR; i<GROUP5; i++){
			attr[i] = attr_DLC_adjst[i-DLC_PR];
        }
	}      
    else if(prvalue == 5){ 
        for(i = DLC_PR; i<GROUP5; i++){
			attr[i] = attr_DLC_adjst2[i-DLC_PR];
        }
	}    
    else if(prvalue == 6){ 
        for(i = DLC_PR; i<GROUP5; i++){
			attr[i] = attr_DLC_adjst3[i-DLC_PR];
        }
	}

#if 0 //Only scan DLC attribute instead of all  PR groups , James, 2021/02/23
    if(prvalue ==0){
        for(i = 0; i<EPMAX; i++){
            attr[i] = attr1[i];
        }
    }
    else if(prvalue == 1){
        for(i = 0; i<EPMAX; i++){
            if((i < DLC_PR) || (i >= GROUP5)/* || (pr[FLOOR_PAGE]==0)*/){
                attr[i] = attr1[i];
            }
            else{
                attr[i] = attr_DLC1[i-DLC_PR];
            }
        }
    }
 		else if(prvalue == 2){  // JINGDO
      for(i = 0; i<EPMAX; i++){
      	if((i < DLC_PR) || (i >= GROUP5))
        	attr[i] = attr1[i];
        else
        	//attr[i] = attr_DLC1[i-DLC_PR];
            attr[i] = attr_DLC2[i-DLC_PR]; //Aevin modi to attr_DLC2 --6/19/2018
      }
 	}
    else if(prvalue == 3){ //[adjust floor position adjust,Aevin,2018/06/19] // adjust floor position  Aevin 6/19/2018
      for(i = 0; i<EPMAX; i++){
        if((i < DLC_PR) || (i >= GROUP5)){
          attr[i] = attr1[i];
        }
        else{
            attr[i] = attr_DLC3[i-DLC_PR]; //Aevin modi to attr_DLC2 --6/19/2018
        }
      }
  	}    
    else if(prvalue == 4){ //[adjust floor position,Henry,2019/01/07]
        for(i = 0; i<EPMAX; i++){
            if((i < DLC_PR) || (i >= GROUP5)){
                attr[i] = attr1[i];
            }
            else{
    	        attr[i] = attr_DLC_adjst[i-DLC_PR];
            }
        }
	}      
    else if(prvalue == 5){ //[adjust floor position,Henry,2019/01/07]
        for(i = 0; i<EPMAX; i++){
            if((i < DLC_PR) || (i >= GROUP5)){
                attr[i] = attr1[i];
            }
            else{
    	        attr[i] = attr_DLC_adjst2[i-DLC_PR];
            }
        }
	}    
    else if(prvalue == 6){ //[adjust floor position,Henry,2019/01/07]
        for(i = 0; i<EPMAX; i++){
            if((i < DLC_PR) || (i >= GROUP5)){
                attr[i] = attr1[i];
            }
            else{
    	        attr[i] = attr_DLC_adjst3[i-DLC_PR];
            }
        }
	}
#endif	
}
#if 0
void P04_50(UWORD prx, UWORD prvalue){
	UWORD i;
	
	 if(pr[FLOOR_PAGE] == 0){  //prvalue = 0
      for(i=0; i<DLC_25ADDR; i++)
        pr[FL_POSIT_1H+i]= DLCxx[i];
   }    
    else{    //prvalue = 1    
      for(i=0; i<DLC_25ADDR; i++)
      	pr[FL_POSIT_1H+i]= DLCxx[(DLC_25ADDR+i)];
    }

    updatepr(prx, prvalue);
    
    if(pr[FLOOR_PAGE]==0)
      DLCxx[(prx-FL_POSIT_1H)] = pr[prx];
    else if(pr[FLOOR_PAGE]==1)  // JINGDO
      DLCxx[(prx-FL_POSIT_1H+DLC_25ADDR)] = pr[prx];
    else if(pr[FLOOR_PAGE]==2)  // JINGDO
    	DLCxx[(prx-FL_POSIT_1H+DLC_50ADDR)] = pr[prx];
}
#else
 //[adjust floor position adjust,Aevin,2018/06/19] //Modify to support adjust floor position--Aevin 7/6/2018
void P04_50(UWORD prx, UWORD prvalue){
	SWORD swval;
	ULONG ulBrdLen,ulSenLen;

		//adjust floor position,Henry,2019/01/07
    //if(pr[FLOOR_PAGE]==3){
    if((pr[FLOOR_PAGE]==4)||(pr[FLOOR_PAGE]==5)||(pr[FLOOR_PAGE]==6)){ //[adjust floor position,Henry,2019/01/07]
        // 這個寫法 用來限制微調大小----7/6/2018
        if(DLC_ulPgBrd !=0){
            //mod pulse to mm [
            //get brd's length mm
    	    //ulBrdLen = U32xU32divU32((DLC_ulPgBrd>>2), COF_ulPls2MMgain, 65536);	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 source
	        //ulBrdLen = ulBrdLen/10;//get borad's length								// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 source

            //if(DLC_PDO_DLC_Mode == DLC_MODE_APS) // GFC APS Jerry.Sk.Tseng 2022/12/23
            //{
            //    ulBrdLen = (DLC_ulPgBrd + 1) >> 1;
            //}
            //else
            //{
            //    ulBrdLen = (ULONG)(((UDOUBLE)DLC_ulPgBrd * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440); // Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 new
            //} 
			ulBrdLen = (ULONG)pos_PGto1MM((UDOUBLE)DLC_ulPgBrd);	// GFC1test

	        if(DLC_ulPgSen && (DLC_ulPgSen<DLC_ulPgBrd)){
                //ulSenLen = U32xU32divU32((DLC_ulPgSen>>2), COF_ulPls2MMgain, 65536);	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 source
	            //ulSenLen = ulBrdLen/10;//get sensors distance							// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 source
	            //ulSenLen = (ULONG)(((UDOUBLE)DLC_ulPgSen * (UDOUBLE)COF_ulPls2MMgain + 1310720) / 2621440); // Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 new
	            ulSenLen = (ULONG)pos_PGto1MM((UDOUBLE)DLC_ulPgSen);	// GFC1test
            }
            else{
                ulSenLen = 0; 
            }
            swval = (SWORD)prvalue;
            swval = (swval < 0) ? swval*(-1) : swval;
            if(/*prvalue*/swval <= ((ulBrdLen/2) - (ulSenLen/2))){                
                updatepr(prx, prvalue);
                
                
                //adjust floor position,Henry,2019/01/07
                #if 0
                DLCxx[(prx-FL_POSIT_1H+DLC_LimADDR)] = pr[prx];
                #else
                if(pr[FLOOR_PAGE]==4)
                	DLCxx[(prx-FL_POSIT_1H+DLC_LimADDR)] = pr[prx];
                else if(pr[FLOOR_PAGE]==5) //[adjust floor position,Henry,2019/01/07]
                	DLCxx[prx-FL_POSIT_1H+DLC_Adj50ADDRUP] = pr[prx];
                else if(pr[FLOOR_PAGE]==6) //[adjust floor position,Henry,2019/01/07]
                	DLCxx[prx-FL_POSIT_1H+DLC_Adj50ADDRDN] = pr[prx];
                #endif  
            }
            else
                KEYEND = ERR;    
        }
        else
            KEYEND = ERR;    
    }
    else{
        KEYEND = ERR;
    }
}

#endif

void P05_18(UWORD prx, UWORD prvalue)
{
    if (prvalue == 0)
        updatepr(prx, prvalue);
    else
    	KEYEND = END;
}    

void P14_64(UWORD prx, UWORD prvalue)
{
    SWORD swTemp;
    
    updatepr(prx, prvalue);    
    if (PRUPDATE==1){
        swTemp = Vdc2ADC(pr[STALL4V]);
        if ((SWORD)swTemp<0)
            stall4ad = 0;
        else
            stall4ad = (UWORD)swTemp;
    }    
}

void P06_00(UWORD prx, UWORD prvalue)
{
	ULONG_UNION FLimit;

    updatepr(prx, prvalue);
    if (PRUPDATE==1){
    	if ((pr[HPSPEC]&VFD440V)==VFD440V){     // 440V class
        	LVS4ad = Vdc2ADC(pr[LVL]);          // 396.0Vdc = 280Vac
        	LVR4ad = Vdc2ADC(pr[LVL]+600);      // LV + 60.0V
    	}
    	else{
        	LVS4ad = Vdc2ADC(pr[LVL]);          // 396.0Vdc = 280Vac
        	LVR4ad = Vdc2ADC(pr[LVL]+300);      // LV + 30.0V
    	}

		// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
		/*---------------------------------------------------------------------------------------------
		--                KVA/2(dot1)           pr[UPS_CAP] * 100 / 2     1     pr[UPS_CAP] * 1000 * 37
		-- Veps = ------------------------- = ------------------------ * --- = -------------------------   (dot1)
		--         sqrt(3) * MIrated(dot2)     sqrt(3) * (MIrated/100)    10      COF_uwMIrRe * 64 * 2
		--
		-- 1/sqrt(3) = 37/64
		----------------------------------------------------------------------------------------------*/
		FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
		//FLimit.ul = (ULONG)pr[UPS_CAP] * 1000 * 37 / COF_uwMIrRe >> 6;
		if (FLimit.ul > vbase){
			COF_uwVUPSRe = vbase;
		}
		else{
			COF_uwVUPSRe = FLimit.uw.low;
		}
		// ]

   		// in Q15, 18919 = 32768 / sqrt(3)
   		/*-----------------------------------------------------------------
		-- COF_uwVEPSPu = (Pr.06_29 / sqrt(2)) * 26755 / COF_uwVbRe      --
		--              = Pr.06_29 * 18919 / COF_uwVbRe                  --
		-----------------------------------------------------------------*/
		COF_uwVEPSPu = U16xU16divU16(pr[VEPS], 18919, COF_uwVbRe);  // EPS voltage PU, add by dino, 02/18/2008

		//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
		COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//#13769 Modify EPS speed, James, 07/01/2020
		pr[FEPS] = COF_uwFepsLimit;

        //pr[FEPS] = COF_uwFepsLimit;     //[User can change speed when used EPS function, Bernie, 2013/04/16]
    }
}

void P06_44(UWORD prx, UWORD prvalue)         //[User can change speed when used EPS function, Bernie, 2013/04/16]
{
    updatepr(prx, prvalue);
    //if (PRUPDATE==1){
        if(prvalue<=uwEPS_SpdLimt){
            pr[FEPS] = prvalue;
        }
        else{
            pr[FEPS] = uwEPS_SpdLimt;
        }
    //}
}


void P06_16(UWORD prx, UWORD prvalue)
{
    if (PRLOCK==0 && FSET_LOCK==0){
        KEYEND = END;
        if (prvalue == 473){          // For Clear Fault Record
            pr[ERR_REC6] = 0;
            write_ep(0,ERR_REC6,0);
            pr[ERR_REC5] = 0;
            write_ep(0,ERR_REC5,0);
            pr[ERR_REC4] = 0;
            write_ep(0,ERR_REC4,0);
            pr[ERR_REC3] = 0;
            write_ep(0,ERR_REC3,0);
            pr[ERR_REC2] = 0;
            write_ep(0,ERR_REC2,0);
            pr[ERR_REC1] = 0;
            write_ep(0,ERR_REC1,0);
			//--- Add by DINO, 10/27/2008
			rec_uwFault1 = pr[ERR_REC1];
			rec_uwFault2 = pr[ERR_REC2];
			rec_uwFault3 = pr[ERR_REC3];
			rec_uwFault4 = pr[ERR_REC4];
			rec_uwFault5 = pr[ERR_REC5];
			rec_uwFault6 = pr[ERR_REC6];
			// [ Add Fault Record Data, DINO, 06/11/2009
			pr[ERR_MIN1] = 0;
			write_ep(0,ERR_MIN1, 0);
			rec_uwErrMin1= 0;
			pr[ERR_DAY1] = 0;
			write_ep(0,ERR_DAY1, 0);
			rec_uwErrDay1= 0;
			pr[ERR_MIN2] = 0;
			write_ep(0,ERR_MIN2, 0);
			rec_uwErrMin2= 0;
			pr[ERR_DAY2] = 0;
			write_ep(0,ERR_DAY2, 0);
			rec_uwErrDay2= 0;
			pr[ERR_MIN3] = 0;
			write_ep(0,ERR_MIN3, 0);
			rec_uwErrMin3= 0;
			pr[ERR_DAY3] = 0;
			write_ep(0,ERR_DAY3, 0);
			rec_uwErrDay3= 0;
			pr[ERR_MIN4] = 0;
			write_ep(0,ERR_MIN4, 0);
			rec_uwErrMin4= 0;
			pr[ERR_DAY4] = 0;
			write_ep(0,ERR_DAY4, 0);
			rec_uwErrDay4= 0;
			pr[ERR_MIN5] = 0;
			write_ep(0,ERR_MIN5, 0);
			rec_uwErrMin5= 0;
			pr[ERR_DAY5] = 0;
			write_ep(0,ERR_DAY5, 0);
			rec_uwErrDay5= 0;
			pr[ERR_MIN6] = 0;
			write_ep(0,ERR_MIN6, 0);
			rec_uwErrMin6= 0;
			pr[ERR_DAY6] = 0;
			write_ep(0,ERR_DAY6, 0);
			rec_uwErrDay1= 0;
			// ]
        }
        else if (prvalue == 8463){    // Reset Run Timer, Power ON Timer
           	pr[PWR_MIN] = 0;
           	write_ep(0,PWR_MIN,0);
           	pr[PWR_DAY] = 0;
           	write_ep(0,PWR_DAY,0);
            pr[PWR_CNT] = 0;
            write_ep(0,PWR_CNT, 0);            
			rec_uwPWRmin = pr[PWR_MIN];
        }
		else if (prvalue == 37767){
			pr[FFBK_REC] = 0;
			write_ep(0,FFBK_REC,0);
			pr[FOUT_REC] = 0;
			write_ep(0,FOUT_REC,0);
           	pr[VOUT_REC] = 0;
           	write_ep(0,VOUT_REC,0);
            pr[DCBUS_REC] = 0;
            write_ep(0,DCBUS_REC, 0);
            pr[ISUM_REC] = 0;
            write_ep(0,ISUM_REC, 0);
            pr[TH_TEMP] = 0;
            write_ep(0,TH_TEMP, 0);
			pr[SRYREC]  = 0;
			write_ep(0,SRYREC, 0);
			//--- Add by DINO, 10/27/2008
			rec_uwFfbk  = pr[FFBK_REC];
			rec_uwFcmd  = pr[FOUT_REC];
			rec_uwVout  = pr[VOUT_REC];
			rec_uwDcbus = pr[DCBUS_REC];
			rec_uwIsum  = pr[ISUM_REC];
			rec_uwIGBT  = pr[TH_TEMP];
			rec_uwSRY   = pr[SRYREC];	
			// [ Add Fault Record Data, DINO, 06/11/2009
			pr[FKEY_REC]  = 0;
			write_ep(0,FKEY_REC ,0);
			pr[POWER_REC] = 0;
			write_ep(0,POWER_REC,0);
			pr[TQ_REC]    = 0;
			write_ep(0,TQ_REC  ,0);
			pr[MFI_REC]   = 0;
			write_ep(0,MFI_REC  ,0);
			pr[MFO_REC]   = 0;
			write_ep(0,MFO_REC  ,0);
			pr[STATE_REC] = 0;
			write_ep(0,STATE_REC,0);

			rec_uwFkey	 = pr[FKEY_REC];
    		rec_uwPower  = pr[POWER_REC];
    		rec_uwTorq   = pr[TQ_REC];
    		rec_uwMFI    = pr[MFI_REC];
    		rec_uwMFO    = pr[MFO_REC];
			rec_uwState  = pr[STATE_REC];
			// ]
		}            
        else if (prvalue == 6658){
            CHKCPR = 1;
        }   
    }       
}           

void P06_17(UWORD prx, UWORD prvalue)
{
	KEYEND = END;
}

void P06_46(UWORD prx, UWORD prvalue)     
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
		PR_ubEpsOptMod = pr[EPS_OPTM];
    }
}    
void P06_51(UWORD prx, UWORD prvalue)     //[Add auto restart after fault, Bernie, 06/06/12]
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
		uwRetryCnt = pr[RESETCNT];       //write the setting value to actual Count 
        rec_uwRetryCnt = pr[RESETCNT];    //write the setting value to Count recoder parameter

        write_ep(0,RESETCNT,rec_uwRetryCnt);
    }
}    

void P06_52(UWORD prx, UWORD prvalue)     //[Add auto restart after fault, Bernie, 06/06/12]
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
		uwRetryTimeCnt = pr[RESETINTERVAL]*10;
    }
}  

void P06_67(UWORD prx, UWORD prvalue){    //[Service time function, Bernie, 2017/03/14]

    
    if(prvalue == 1){
        if(pr[SERVICE_COUNT]!=0){
            updatepr(prx,prvalue);
            SERV_KEY = 0;
            SERVICE_RESET = 0;
        }    
        else{
            KEYEND = ERR;
        }
    }
    else if(prvalue == 0){
        updatepr(prx,prvalue);
        if (PRUPDATE==1){
            if(SERVICE_KEYRESET==1){
                if(Error==SERVICE_ERR){
                    SERVICE_KEYRESET = 0;
                    SERVICE_RESET = 1;
                }
            }
        }
    }
}


void P06_79(UWORD prx, UWORD prvalue){  //[Running Dir Count,Special,2018/08/17]

	updatepr(prx,prvalue);
    
    if (PRUPDATE==1){
    	if(prvalue==0){
            if((pr[IR_TCOUNT_H]!=0)||(pr[IR_TCOUNT_L]!=0))
            {
        		pr[IR_RESTEC] = pr[IR_RESTEC] + 1;
                if(pr[IR_RESTEC]==101)
                    pr[IR_RESTEC] = 0;
            }
            else
            {
                pr[IR_RESTEC] = pr[IR_RESTEC];
            }
            
            write_ep(0,IR_RESTEC,pr[IR_RESTEC]);
            
    		pr[IR_TCOUNT_H] = 0;
            write_ep(0,IR_TCOUNT_H,0);
    		pr[IR_TCOUNT_L] = 0;
            write_ep(0,IR_TCOUNT_L,0);
            IR_ulTcount = pr[IR_TCOUNT_H]*10000 + pr[IR_TCOUNT_L];
    		IRF_ENABLE = 0;
    		IRF_Warning = 0;
    		IRF_Error = 0;
    		if(WarnCode == SERVICE_WARN){	
    			WarnCode = 0;
                Keypad_Page = pr[S_DISP];
                Keypad_PageTmp = 0;
            }
            if((Error==SERVICE_ERR)&&(IR_KEYRESET==1)){
                SERVICE_RESET = 1;
                IR_KEYRESET = 0;
            }
    	}
    	else if(prvalue==1){ // Ironwire Warning
    		IRF_ENABLE = 1;
    		IRF_Warning = 1;
            IRF_Error = 0;
            SERVICE_RESET = 0;
    	}
    	else if(prvalue==2){ //Ironwire Error
    		IRF_ENABLE = 1;
            IRF_Warning = 0;
    		IRF_Error = 1;
            SERVICE_RESET = 0;
    	}
    }
}

void P07_00(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);    
    if (PRUPDATE){
        dcbrk4ad = Vdc2ADC(pr[DCBRK4V]);
    }  
}

void P14_68(UWORD prx, UWORD prvalue)
{
	updatepr(prx, prvalue);
	if (PRUPDATE==1){
	    switch(prx){	        
	        case BB_T:
	            TB1_uwBBCnt = pr[BB_T] * 100;
	            break;
	        case PWRL_T:
	            TB1_uwLVCnt = pr[PWRL_T] * 100;
	            break;
	        case SLEEPT:
	            TB1_uwSleepCnt = pr[SLEEPT];
	            break;
	        default:
	            break;
	    }
	}
	        
}

void P07_12(UWORD prx, UWORD prvalue)
{
	if ((pr[TQRSOOC]<=1)&& PRLOCK==0 && FSET_LOCK==0){   //6a25j_1  Torque ref source by keypad or comm.
    	if ((attr[prx].ati&SIGN)!=0){    //Signed Parameter
    		if ((RUNNING==STOP)||(attr[prx].ati&WRUN)){
	            if (((SWORD)prvalue<=(SWORD)attr[prx].max)&&((SWORD)prvalue>=(SWORD)attr[prx].min)){
					pr[TQREF] = (SWORD)prvalue;
					TQRCMemswPer = (SWORD)pr[TQREF];
					KEYEND = END;
				}
			}			
		}
	}
	else
	   KEYEND = ERR;    //6a25j_1
}

void P07_14(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        COF_uwTqMaxPu = COF_uwTqratePu * pr[TQRMAX]/100;    
    }
}

void P07_17(UWORD prx, UWORD prvalue)
{
    SLONG slSpdLimRe;;
    
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        slSpdLimRe = (pr[TQPSPDLIM]* pr[FMAX])/100;
        if (slSpdLimRe >= 60000)
            slSpdLimRe = 60000;
        TqC_uwPSpdLimRe = slSpdLimRe;
        
        TqC_swPSpdLimPu = U16xU16divU16(slSpdLimRe,0x7FFF,COF_uwFbRe);

        slSpdLimRe = (pr[TQNSPDLIM]* pr[FMAX])/100;
        if (slSpdLimRe >= 60000)
            slSpdLimRe = 60000;
        TqC_uwNSpdLimRe = slSpdLimRe;

        TqC_swNSpdLimPu = 0 - U16xU16divU16(slSpdLimRe,0x7FFF,COF_uwFbRe);
    }
}

void P07_21(UWORD prx, UWORD prvalue)
{
    SWORD sw_TQOFSEVH,sw_TQOFSEVM,sw_TQOFSEVL;

    sw_TQOFSEVH = (SWORD)pr[TQOFSEVH];
    sw_TQOFSEVM = (SWORD)pr[TQOFSEVM];
    sw_TQOFSEVL = (SWORD)pr[TQOFSEVL];
    
    switch(prx){
        case TQOFSEVH:
            if ((SWORD)prvalue>=sw_TQOFSEVM)
                updatepr(prx,prvalue);
            else
                KEYEND = ERR;
            break;
        case TQOFSEVM:
            if (((SWORD)prvalue<=sw_TQOFSEVH)&&((SWORD)prvalue>=sw_TQOFSEVL))
                updatepr(prx,prvalue);
            else
                KEYEND = ERR;
            break;
        case TQOFSEVL:
            if ((SWORD)prvalue<=sw_TQOFSEVM)
                updatepr(prx,prvalue);
            else
                KEYEND = ERR;
            break;
        default:
            break;
    }
}


void P14_82(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        PID_slofsetv = ((SLONG)pr[PIDOFSET] * pr[FMAX]);
    }
}

void P08_00(UWORD prx, UWORD prvalue)
{
    if (PRLOCK==0 && FSET_LOCK==0){
    	if (prvalue == 0){
    		KEYEND = END;
    	}
    	else{
    		if (pr[AUTO_T] == 0){
        		if ((prvalue <= attr[prx].max)&&(CMDRUN==STOP)){
        	    	KEYEND = END;
        	    	//-- Add by DINO, 07/08/2008
        	    	// [ Set STtune before pr[PM_AUTO_T], Modify by DINO, 05/11/2009
        	    	if ( prvalue==3  ){
    					STtune_Buf = STtune;
        	    		STtune = 0;
        	    		TUN_SS = 1;
                        if(pr[PG_TYPE]>=SIN_SIN)
                        NEWHSDSTUNE = 1;       //[Modify PGHSD01 function, Bernie, 2012/02/05]
        	    	}
        	    	else{
                        if(prvalue==1)
                             NEWHSDSTUNE = 0;       //[Modify PGHSD01 function, Bernie, 2012/02/05]
        	    		if (TUN_SS == 1){
        	    			TUN_SS = 0;
        	    			STtune = STtune_Buf;
        	    		}
        	    	}
        	    	pr[prx] = prvalue;
        	    	// End on 05/11/2009]
        		}
    		}
    		else{
        		KEYEND = ERR;
        	}
    	}
    }
    
}

void P08_01(UWORD prx, UWORD prvalue)   
{
    UWORD uwIrated;
    ULONG ul_temp;
    
    updatepr(prx,prvalue);
    
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
		COF_uwMIrRe = prvalue;

#if STtest
        STDutyInit();	// dino, 2006/08/15
#endif
         /*--------------------------- Add by dino 11.07.2006 ------------------------------
         -- Calculate the current AD level for Stnadstill                                 --
         -- COF_uwSSIratedPu = COF_uwMIrRe * 1.8 / pr[I_RATE] / sqrt(2) / 2.5 * 512 * 2^6 --
         -- 1.6 = 26214 / 2^14                                                            --
         -- 1/sqrt(2) = 46341 / 2^16                                                      --
         -- 1/2.5 = 2/5                                                                   --
         ---------------------------------------------------------------------------------*/ 
        if ( pr[STI]==0 ){
        	if ( COF_uwMIrRe > pr[I_RATE] ){ uwIrated = pr[I_RATE]; }
        	else { uwIrated = COF_uwMIrRe; }
        }
        else
        	uwIrated = pr[STI];
        COF_uwSSIratedPu = ((ULONG)uwIrated * 26214 / pr[I_RATE] * 46341 >> 14) / 5;
        COF_uwMIratePu = U32xU32divU32(COF_uwMIrRe ,46341, COF_ulIbRe); // Jerry.sk.tseng for GFC High elecator 2021/08/17
        
        if (pr[CTSEL]==0)
            mspec = U16xU16divU16(COF_uwMIratePu, 100, COF_uwCTIratePu);
        else
            mspec = U16xU16divU16(COF_uwMIratePu, 100, COF_uwVTIratePu);
		
		TQRBaseInit();                   
#else
		MotorPrSel();
#endif
    }
}

void P08_02(UWORD prx, UWORD prvalue)   
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
        pr[prx] = prvalue; 
		COF_uwMPRe = prvalue;
		TQRBaseInit();
    	TQRMaxInit();
#else
		MotorPrSel();
#endif
    }    
}

void P08_03(UWORD prx, UWORD prvalue)   
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1){
#if OLD_SETTING  // Modify by DINO, 09/09/2008
		COF_uwRPMRe = prvalue;
        TQRMaxInit();
	   	TQRBaseInit();
#else
		MotorPrSel();
#endif
    }

}

void P08_04(UWORD prx, UWORD prvalue)   // POLES
{
    if ((prvalue&0x0001)==0x0000){
        ACC_Unit_SecToms2();
	    updatepr(prx, prvalue);
		if (PRUPDATE==1){        
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]    //[Sibocom unit convert to moter speed, Jason, 20200512]
            pr[Lift_SPD_RPM] = (120*(flMetric2Hz(pr[Lift_SPD])/100))/COF_uwPole;//[Sibocom Lift speed(11-01) convert to moter speed, Jason, 20200110]
#endif
			MotorPrSel();
	    	Init_SpDtPG1_pr();
            if(SIBO_SPDCHG) //[ACC value reset to 0,Lyabryan,2020/09/10]
                ACC_Unit_ms2ToSec();

		}
    }
    else
        KEYEND = ERR;
}


void P08_05(UWORD prx, UWORD prvalue)   // Rs
{
    UWORD PuTemp;
    
    PuTemp = U16xU16divU16(prvalue, 16384, COF_uwRbRe);	//Q15
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
		COF_uwRsPu = PuTemp;
        COF_uwMRsRe = prvalue;
        set_VcmpMax();
    } 
    Motor1Pr();   //added SC 10/05/2007
#else
		COF_uwRs3Pu = PuTemp;
		MotorPrSel();
    } 
#endif
}

void P08_06(UWORD prx, UWORD prvalue)   // Ld & Lq
{
	UWORD PuTemp;

    PuTemp = U16xU16divU16(prvalue, 51200, COF_uwLbRe);	//Q10
    updatepr(prx,PuTemp);
    if (PRUPDATE==1){        
        pr[prx] = prvalue;
#if OLD_SETTING  // Modify by DINO, 09/09/2008
		COF_uwLxPu = PuTemp;
	}
	Motor1Pr();		//added SC 10/05/2007
#else
		COF_uwLx3Pu = PuTemp;
		MotorPrSel();
    } 
#endif
}


void P09_01(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1)
        InitSCI2();
}

void P09_05(UWORD prx, UWORD prvalue)
{
//    updatepr(prx,prvalue);
//    if (PRUPDATE==1){
//        InitSCI2();
//    }
}

void P09_07(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1)
        InitSCI3();
}


void P14_92(UWORD prx, UWORD prvalue)
{
    if (PRLOCK==0 && FSET_LOCK==0){     
        if ((pr[SOFC]==3)||((PUON3LINE||PUON2LINE)&&OPKEY_LOCK==0)||(COPYEN==1)){
            PCRemote2001H(prvalue);
            KEYEND = END;
        }
        else
            KEYEND = ERR;
    }
}

void P14_93(UWORD prx, UWORD prvalue)
{
    void (*write_ptr)(UWORD,UWORD);
    UBYTE ax,gx,px,gpno;
    
    if (PRLOCK==0 && FSET_LOCK==0){
        /*-------- Block Transfer Write --------*/
        if (KEYPAD_CMD==0){
                prx = pr[prx];
              #if 1
                gx = (UBYTE)(prx/100);
                px = (UBYTE)(prx%100);
              #else
                gx = (UBYTE)((prx&0xff00)>>8);
                px = (UBYTE)(prx&0x00ff);
         	  #endif
                if (SHOW_ALLPR==1)
                    ax = GRALL;
                else{
	       		    if (SHOW_ENHANCE==1)
            		    ax = GRENHANCE;
            	    else
	   			    	ax = GRUSER;            
	       	    }
            
                if (gx <= ax) {         // group NO. //
                if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                    gpno = pr_gpno_Sibo[gx];
                else
                    gpno = pr_gpno[gx];
                    ax = gpno;
                    if (px < ax) {      // function NO. //
                        prx = (UWORD)prtab[gx]+px;       // pr index //
                        BLK_WRITE = 1;
                        KEYEND = ERR;
                        PRUPDATE = 0;
                        if ((prx<PRMAX)&&((prx<BKTRANS1)||(prx>BKTRANS10))){
                            write_ptr = pr_tbl[prx];
                            (*write_ptr)(prx, prvalue);
                        }
                        BLK_WRITE = 0;
                    }
                    else
                        KEYEND = ERR;   // Illegal function NO. //
                }
                else
                    KEYEND = ERR;       // Illegal group NO. //
        }/*-------- End of Block Transfer Write --------*/
        else
            updatepr(prx,prvalue);
    }                
}


void P09_14(UWORD prx, UWORD prvalue)
{
    if(prvalue > pr[CAN_ChkTime])
		pr[prx] = pr[CAN_ChkTime];
    else
	    updatepr(prx,prvalue);
}


void P10_01(UWORD prx, UWORD prvalue)
{
    UBYTE ubPGCard;
    UWORD uwHi, uwLow, uwMid;

    updatepr(prx,prvalue);


    /*=========== PG Card type detact  ===========   //[Modify PG Type Define, Bernie, 12/05/2011]
                                  AN5
                          PGHSD  3.133V
                           ---------- 2.5V
                          PGABD 1.983V
                           ---------- 1.5V
                          PGAB  1.035V
                           ---------- 0.5V
                          NO PG   0.000V
      ===============================*/  
    //uwHi  = 2048; // 2.5/5.0V * 4095 = 2048
    //uwMid = 1229; // 1.5/5.0V * 4095 = 1229
    //uwLow = 410;  // 0.5/5.0V * 4095 = 410
    uwHi  = 512; // 2.5/5.0V * 1024 = 512
    uwMid = 307; // 1.5/5.0V * 1024 = 307
    uwLow = 102;  // 0.5/5.0V * 1024 = 102

    if (AN00 > uwHi)
        ubPGCard = PGHSD;
    
    else if (AN00 > uwMid)
        ubPGCard = PGABD;

    else if (AN00 > uwLow)
        ubPGCard = PGAB;

    else
        ubPGCard = NOPGCARD;

    SpDt_ubPGCard = ubPGCard;

    
    if (PRUPDATE==1){
        Init_SpDtPG1_pr();
		if (prx==PGINPUT){
	        if (prvalue>=3)
				PGScaleData = pr[PGSCALE]|0x4000;
	        else if (prvalue>=1)
				PGScaleData = pr[PGSCALE];
	        else // if (prvalue==0)
				PGScaleData = 1;

/*   // Mask by Lyabryan 
	if(prvalue >=3){
                if(pr[PG_TYPE]>=3){
                    updatepr(PGINPUT,0);
                    Error = PGF5_1_ERR;
                }
            }
            */
		}
		else if ( prx == PG_TYPE ){
            //if( pr[PG_TYPE] == ABZ_ONLY || pr[PG_TYPE] == ABZ_UVW){         //[PGABD function, Bernie, 10/13/2011]
            //    PFC.PDCRH2.WORD = 0x0000;
            //    PFC.PDIORH.WORD = 0xE078;
            //}
            //else{
                //PFC.PDCRH2.WORD = 0x0550;            //[PGABD function, Bernie, 10/13/2011]
                //PFC.PDIORH.WORD = 0xE038;
/*  // Mask by Lyabryan 
	      if(prvalue >=3){
                    if(pr[PGINPUT]>=3){
                        updatepr(PG_TYPE,0);
                        Error = PGF5_1_ERR;
                    }
                }
                */
                if ((prvalue == ABZ_ONLY)||(prvalue == ABZ_UVW)||(prvalue == NOPG)){ // [PGABD Output error, Lyabryan, 2015/08/13] 
	      	
		PORT2.PMR.BIT.B3 = 0; //[0: Uses the pin as a general I/O pin.];[1: Uses the pin as an I/O port for peripheral functions.]
		PORT2.PMR.BIT.B2 = 0; //[0: Uses the pin as a general I/O pin.];[1: Uses the pin as an I/O port for peripheral functions.]
		PORT3.PMR.BIT.B0 = 0; // Initial PORD Output is zero.
		PORT2.PDR.BIT.B3 = 1; //[0: Input (Functions as an input pin.)];[1: Output (Functions as an output pin.)]
		PORT2.PDR.BIT.B2 = 1; //[0: Input (Functions as an input pin.)];[1: Output (Functions as an output pin.)]
		PORT3.PDR.BIT.B0 = 1; // Initial PORD Output is zero.
		PORT2.PODR.BIT.B2 = 0; // Initial PORD Output is zero.
		PORT2.PODR.BIT.B3 = 0; // Initial PORD Output is zero.
		PORT3.PODR.BIT.B0 = 0; // Initial PORD Output is zero.
                }
	      
                else{ // [PGABD Output error, Lyabryan, 2015/08/13] 
		        InitSCI0();
	    	    TB_2ms = 0;		// Add by DINO, 10/09/2008
	    	    edt_ubStep = 0;	// Add by DINO, 10/09/2008
	    	}
	    }
#if SH7149
		else if (prx==EPPR)
	    	Init_PG2Ref();
#endif
    }
}

void P10_03(UWORD prx, UWORD prvalue)
{
    if (prvalue==5){
        if ((pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=TQCPG)){
            updatepr(prx,prvalue);
        }
    }
    else{
        updatepr(prx,prvalue);
    }
    
    if (PRUPDATE==1)
        Init_SpDtPG1_pr();    
    
}
/*
void P14_103(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
//#if SH7149
//    if (PRUPDATE==1){
//	Init_PG2Ref();
//    }
//#endif
}
*/
void P10_10(UWORD prx, UWORD prvalue)
{
    updatepr(prx,prvalue);
    if (PRUPDATE==1){
        if (pr[PGINPUT]>=3){
			PGScaleData = prvalue|0x4000;
		}
		else if (pr[PGINPUT]>=1){
			PGScaleData = prvalue;
		}
		else if (pr[PGINPUT]==0){
			PGScaleData = 1;
		}
	}
}

void P10_32(UWORD prx, UWORD prvalue){
    updatepr(prx,prvalue);
    uwOverAccLev = (UWORD)(((ULONG)(pr[OVER_ACC_LEVEL])*(pr[MFBASE1]/10))/(pr[Lift_SPD]))<<2;
}


void P10_33(UWORD prx, UWORD prvalue){    //[Over Acceleration protection function, Bernie, 2017/02/13]

    updatepr(prx,prvalue);
    OverAccTimeSet = pr[OVER_ACC_TIME];
}

void P14_104(UWORD prx, UWORD prvalue){    //[Over Acceleration protection function, Bernie, 2017/02/13]
    
    updatepr(prx,prvalue);
//#if SH7149
//    if (PRUPDATE==1){
//	Init_PG2Ref();
//    }
//#endif
}


void P14_112(UWORD prx, UWORD prvalue)
{
	updatepr(prx,prvalue);
	if (PRUPDATE==1){
		Init_SpDtPG1_pr();
	}
}

void P14_114(UWORD prx, UWORD prvalue)
{
	if (PRLOCK==0 && FSET_LOCK==0){
		if (RUNNING==STOP) {
        	KEYEND = END;
       		if (EsJ_uwJmPu!=prvalue){
       			if ((prvalue<=attr[prx].max)&&(prvalue>=attr[prx].min)){
       				write_ep(BLK_WRITE,prx,prvalue);
           		    EsJ_uwJmPu = prvalue;
           		    pr[prx] = prvalue;
       			}
       			else
       				KEYEND = ERR;
			}        			
		}
	}		
}

void P14_118(UWORD prx, UWORD prvalue)
{
	updatepr(prx, prvalue);	
#if SH7149
	switch(prx){
	    case OH_IN:
	        IGBT_OHLevel = pr[OH_IN];
	        break;
//	    case OH_OUT:
//	        IGBT_OHLevel = pr[OH_OUT];
	        break;
	    default:
            break;    
	}
#else	// VL setting, Add by DINO, 10/20/2008
#if 1	// OH update, Sean, 04/19/2011
	if ( pr[HPSPEC]==VFD300V23A || 	// part of frame E, thermister inside
		 pr[HPSPEC]==VFD370V23A || 
		 pr[HPSPEC]==VFD550V43A || 
		 pr[HPSPEC]==VFD750V43A){
		IGBT_OHLevel = pr[OH_IN];		//110c
	}
	else if ( 
		 pr[HPSPEC]<=VFD037V43A ||	// frame B
		 pr[HPSPEC]==VFD370V43A ||	// part of frame E
		 pr[HPSPEC]==VFD450V43A ||
		 pr[HPSPEC]==VFD037V21A ||   //[Single phase input, Bernie, 01/19/2012]
		 pr[HPSPEC]==VFD022V21A ){	 //[Single phase input, Bernie, 01/19/2012]

		IGBT_OHLevel = pr[OH_IN] - 50;	//105c
	} 
	else{							// frame C, D, thermister outside
		IGBT_OHLevel = pr[OH_IN] - 150;	// 95c
	}
#else
	if ( pr[HPSPEC]>VFD220V43A ){	// Thermister Inside
		IGBT_OHLevel = pr[OH_IN] - 100;
	}
	else{							// Thermister Outside
		IGBT_OHLevel = pr[OH_IN];
	}
#endif	
#endif
}

void P11_11(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
        Nh_swWn = ((SLONG)pr[NH_Freq] * 6283) / 100000; //6238=2*pi*1000
        Nh_swDampZ = Nh_swDeepDB[pr[NH_Deep]];
    }
}

void P14_122(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1){
    	PrDiameter = pr[DIAMETER];
    	PrTorqueRe = ((ULONG)pr[TENSION] * pr[DIAMETER])>>1;    	
    	PrTorquePu = U32xU32divU32(PrTorqueRe,100000,(COF_uwTqrateRe*pr[TQRMAX]));    	
    }
}


void P14_131(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
	if (PRUPDATE==1){
//	   uwPHLADLevel = Vdc2ADC(1500 + pr[PHL_L]); 	del 10/18/2007
	  uwPHLADLevel = pr[PHL_L];				//SCOTTY 10/18/2007
	}		
}

void P14_136(UWORD prx, UWORD prvalue)   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
{
#if 0  //CAN FUNCTION BERNIE
    updatepr(prx, prvalue);
	if (PRUPDATE==1){
        if(prvalue==1){    // [CAN Protocol for High Cap , Sampo,  2011/09/05]
    	RCANET.MBIMR0.WORD &= 0xfe01;					/* MB1,2 INT for IRR1/Irr2/IRR8/IRR9 is enable */
    	RCANET.IMR.WORD    &= 0xfefd;					/* IRR1 & IRR8 is not masked */
#if 0    	
    	RCANET.MB[1].CTRL0.WORD.H = 0x0004;             //standard ID, data flam, ID= 0x001 = 0,0000,0000,01--
    	RCANET.MB[1].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[1].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */
    	
    	RCANET.MB[2].CTRL0.WORD.H = 0x0008;             //standard ID, data flam, ID= 0x002 = 0,0000,0000,10--
    	RCANET.MB[2].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[2].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */
#endif 
        
    	//  SDO-Read VL to Host Data1                                        // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    	RCANET.MB[1].CTRL0.WORD.H = 0x0540;             //standard ID, data flam, ID= 0x150 = 0,0101,0100,00--
    	RCANET.MB[1].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[1].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */
    	
    	//  SDO-Read Host to VL
    	RCANET.MB[2].CTRL0.WORD.H = 0x0400;             //standard ID, data flam, ID= 0x100 = 0,0100,0000,00--
    	RCANET.MB[2].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[2].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */
    	
    	//  SDO-Read VL to Host Data2
    	RCANET.MB[3].CTRL0.WORD.H = 0x0544;             //standard ID, data flam, ID= 0x151 = 0,0101,0100,01--
    	RCANET.MB[3].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[3].CTRL1.WORD   = 0x0008;				/* Set Mailbox3 for transmission, data length 8 bytes */
        
        //  SDO-Read VL to Host Data2
    	RCANET.MB[4].CTRL0.WORD.H = 0x0548;             //standard ID, data flam, ID= 0x152 = 0,0101,0100,02--
    	RCANET.MB[4].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[4].CTRL1.WORD   = 0x0008;				/* Set Mailbox4 for transmission, data length 8 bytes */

        //  SDO-Read Host to VL                                                   // [CAN Protocol for High Cap , Bernie,  09/22/2011]
        RCANET.MB[5].CTRL0.WORD.H = 0x0404;             //standard ID, data flam, ID= 0x101 = 0,0100,0000,01--
        RCANET.MB[5].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
        RCANET.MB[5].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */
        
        //  SDO-Read Host to VL
        RCANET.MB[6].CTRL0.WORD.H = 0x0408;             //standard ID, data flam, ID= 0x102 = 0,0100,0000,10--
        RCANET.MB[6].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
        RCANET.MB[6].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */

        //  PDO-Read Host to VL
        RCANET.MB[7].CTRL0.WORD.H = 0x0800;             //standard ID, data flam, ID= 0x200 = 0,1000,0000,00--
        RCANET.MB[7].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
        RCANET.MB[7].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */

        //  SDO-Read VL to Host Data1
    	RCANET.MB[8].CTRL0.WORD.H = 0x0940;             //standard ID, data flam, ID= 0x250 = 0,1001,0100,00--
    	RCANET.MB[8].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[8].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */
    	/* BitRate Setting */		
       //   	
       //		   			  fclk 
       //BitRate = ------------------------------ , 7<  (TSETG1+TSEG2+1) <26
       //		  (2*(BRP+1)) * (TSEG1+TSEG2+1)          TSEG1=16(17tq),TSEG2=7(8tq),SJW=0,BSP=0
       //
       /* fclk=48MHz, BR:125kbps */
        switch(pr[CAN_BURD]){
        	case 0:  //1Mbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0000;                        
            break;
        	case 1:  //500kbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0001;                       
            break;
        	case 2:  //250kbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0003;                      
            break;
        	case 3:  //125kbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0007;                        
            break;
            default:
            break;
//        }	
            
		}
        }
    else{

    
   	/* Interrupt Setting */ //set MBIBR0 for added MBn
   	//RCANET.MBIMR0.WORD &= 0xfff9;					/* Mailbox1 & Mailbox2 INT for IRR1/Irr2/IRR8/IRR9 is enable */
	RCANET.MBIMR0.WORD &= 0xff81;					/* MB1,2,3,4 INT for IRR1/Irr2/IRR8/IRR9 is enable */
	RCANET.IMR.WORD    &= 0xfefd;					/* IRR1 & IRR8 is not masked */

    /* MB1 Setting */
#if VLI_RCAN	
	RCANET.MB[1].CTRL0.WORD.H = 0x1c08;				/* standard ID, data flam, ID=0x702=1,1100,0000,10-- */	//VLI_RCAN	
#else	
	RCANET.MB[1].CTRL0.WORD.H = 0x1c04;				/* standard ID, data flam, ID=0x701=1,1100,0000,01-- */	//7286CB	
#endif	

   	RCANET.MB[1].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */	
  	RCANET.MB[1].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */


    /* MB2 Setting */
#if VLI_RCAN	
	RCANET.MB[2].CTRL0.WORD.H = 0x1c04;				/* standard ID, data flam, ID=0x0701=1,1100,0000,01-- */	//VLI_RCAN	
#else	
	RCANET.MB[2].CTRL0.WORD.H = 0x1c08;				/* standard ID, data flam, ID=0x0702=1,1100,0000,10-- */	//7286CB		
#endif	

   	RCANET.MB[2].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
   	RCANET.MB[2].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */

    /* MB3 Setting */
#if VLI_RCAN	
	RCANET.MB[3].CTRL0.WORD.H = 0x1c34;				/* standard ID, data flam, ID=0x070d=1,1100,0011,01-- */	//VLI_RCAN	
#else	
	RCANET.MB[3].CTRL0.WORD.H = 0x1c30;				/* standard ID, data flam, ID=0x070c=1,1100,0011,00-- */	//7286CB		
#endif	

   	RCANET.MB[3].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
   	RCANET.MB[3].CTRL1.WORD   = 0x0008;				/* Set Mailbox3 for reception, data length 8 bytes */
	
    /* MB4 Setting */
#if VLI_RCAN	
	RCANET.MB[4].CTRL0.WORD.H = 0x1c30;				/* standard ID, data flam, ID=0x070c=1,1100,0011,00-- */	//VLI_RCAN	
#else	
	RCANET.MB[4].CTRL0.WORD.H = 0x1c34;				/* standard ID, data flam, ID=0x070d=1,1100,0011,01-- */	//7286CB				
#endif	

   	RCANET.MB[4].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
   	RCANET.MB[4].CTRL1.WORD   = 0x0208;				/* Set Mailbox4 for reception, data length 8 bytes */

    /* MB5 Setting */
#if VLI_RCAN	
	RCANET.MB[5].CTRL0.WORD.H = 0x1c3c;				/* standard ID, data flam, ID=0x070f=1,1100,0011,11-- */	//VLI_RCAN	
#else	
	RCANET.MB[5].CTRL0.WORD.H = 0x1c38;				/* standard ID, data flam, ID=0x070e=1,1100,0011,10-- */	//7286CB		
#endif	

   	RCANET.MB[5].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
   	RCANET.MB[5].CTRL1.WORD   = 0x0008;				/* Set Mailbox3 for reception, data length 8 bytes */
	
    /* MB6 Setting */
#if VLI_RCAN	
	RCANET.MB[6].CTRL0.WORD.H = 0x1c38;				/* standard ID, data flam, ID=0x070e=1,1100,0011,10-- */	//VLI_RCAN	
#else	
	RCANET.MB[6].CTRL0.WORD.H = 0x1c3c;				/* standard ID, data flam, ID=0x070f=1,1100,0011,11-- */	//7286CB				
#endif	

   	RCANET.MB[6].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
   	RCANET.MB[6].CTRL1.WORD   = 0x0208;				/* Set Mailbox4 for reception, data length 8 bytes */
		
	
	/* BitRate Setting */	
	
//   	
//		   			  fclk 
//BitRate = ------------------------------ , 7<  (TSETG1+TSEG2+1) <26
//		  (2*(BRP+1)) * (TSEG1+TSEG2+1)
//
//	
   	/* fclk=48MHz, BR:50kbps */
// 	RCANET.BCR1.WORD = 0xf600;						/* TSEG1=16(17tq),TSEG2=7(8tq),SJW=0,BSP=0 */
// 	RCANET.BCR0.WORD = 0x0013;                      /* BRP = 19 */
   	/* fclk=48MHz, BR:100kbps */
//	RCANET.BCR1.WORD = 0xf600;						/* TSEG1=16(17tq),TSEG2=7(8tq),SJW=0,BSP=0 */
//	RCANET.BCR0.WORD = 0x0009;                      /* BRP = 9 */		
   	/* fclk=48MHz, BR:125kbps */
  	RCANET.BCR1.WORD = 0xf600;						/* TSEG1=16(17tq),TSEG2=7(8tq),SJW=0,BSP=0  */	//Sean, 03/31/2010
  	RCANET.BCR0.WORD = 0x0007;                      /* BRP = 7 */		
   	/* fclk=48MHz, BR:250kbps */
//	RCANET.BCR1.WORD = 0xf600;						/* TSEG1=16(17tq),TSEG2=7(8tq),SJW=0,BSP=0  */	//Sean, 03/31/2010
//	RCANET.BCR0.WORD = 0x0003;                      /* BRP = 3 */		
   	/* fclk=48MHz, BR:500kbps */
//	RCANET.BCR1.WORD = 0x6300;						/* TSEG1=7(8tq),TSEG2=4(5tq),SJW=0,BSP=0 */
//	RCANET.BCR0.WORD = 0x0003;                      /* BRP = 3 */		
   	/* fclk=48MHz, BR:666kbps */
//	RCANET.BCR1.WORD = 0x6300;						/* TSEG1=7(8tq),TSEG2=4(5tq),SJW=0,BSP=0 */
// 	RCANET.BCR0.WORD = 0x0002;                      /* BRP = 2 */		
   	/* fclk=48MHz, BR:1000kbps */
// 	RCANET.BCR1.WORD = 0x6300;						/* TSEG1=7(8tq),TSEG2=4(5tq),SJW=0,BSP=0 */
// 	RCANET.BCR0.WORD = 0x0001;                      /* BRP = 1 */		
 //  }
} 
	}	
#endif
}

void P14_137(UWORD prx, UWORD prvalue)   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
{

    updatepr(prx, prvalue);
    InitCAN();
    
#if 0  //CAN FUNCTION BERNIE
	if (PRUPDATE==1){
       if(pr[CAN_HC]==1){    // [CAN Protocol for High Cap , Sampo,  2011/09/05]
    	RCANET.MBIMR0.WORD &= 0xfe01;					/* MB1,2 INT for IRR1/Irr2/IRR8/IRR9 is enable */
    	RCANET.IMR.WORD    &= 0xfefd;					/* IRR1 & IRR8 is not masked */
#if 0   	
    	RCANET.MB[1].CTRL0.WORD.H = 0x0004;             //standard ID, data flam, ID= 0x001 = 0,0000,0000,01--
    	RCANET.MB[1].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[1].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */
    	
    	RCANET.MB[2].CTRL0.WORD.H = 0x0008;             //standard ID, data flam, ID= 0x002 = 0,0000,0000,10--
    	RCANET.MB[2].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[2].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */
#endif    
    	//  SDO-Read VL to Host Data1                                         // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    	RCANET.MB[1].CTRL0.WORD.H = 0x0540;             //standard ID, data flam, ID= 0x150 = 0,0101,0100,00--
    	RCANET.MB[1].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[1].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */
    	
    	//  SDO-Read Host to VL
    	RCANET.MB[2].CTRL0.WORD.H = 0x0400;             //standard ID, data flam, ID= 0x100 = 0,0100,0000,00--
    	RCANET.MB[2].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[2].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */
    	
    	//  SDO-Read VL to Host Data2
    	RCANET.MB[3].CTRL0.WORD.H = 0x0544;             //standard ID, data flam, ID= 0x151 = 0,0101,0100,01--
    	RCANET.MB[3].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[3].CTRL1.WORD   = 0x0008;				/* Set Mailbox3 for transmission, data length 8 bytes */
        
        //  SDO-Read VL to Host Data2
    	RCANET.MB[4].CTRL0.WORD.H = 0x0548;             //standard ID, data flam, ID= 0x152 = 0,0101,0100,02--
    	RCANET.MB[4].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[4].CTRL1.WORD   = 0x0008;				/* Set Mailbox4 for transmission, data length 8 bytes */

        //  SDO-Read Host to VL                                                   // [CAN Protocol for High Cap , Bernie,  09/22/2011]
        RCANET.MB[5].CTRL0.WORD.H = 0x0404;             //standard ID, data flam, ID= 0x101 = 0,0100,0000,01--
        RCANET.MB[5].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
        RCANET.MB[5].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */
        
        //  SDO-Read Host to VL
        RCANET.MB[6].CTRL0.WORD.H = 0x0408;             //standard ID, data flam, ID= 0x102 = 0,0100,0000,10--
        RCANET.MB[6].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
        RCANET.MB[6].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */

        //  PDO-Read Host to VL
        RCANET.MB[7].CTRL0.WORD.H = 0x0800;             //standard ID, data flam, ID= 0x200 = 0,1000,0000,00--
        RCANET.MB[7].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
        RCANET.MB[7].CTRL1.WORD   = 0x0208;				/* Set Mailbox2 for reception, data length 8 bytes */

        //  SDO-Read VL to Host Data1
    	RCANET.MB[8].CTRL0.WORD.H = 0x0940;             //standard ID, data flam, ID= 0x250 = 0,1001,0100,00--
    	RCANET.MB[8].LAFM.WORD.H  = 0x0000;				/* Set STD_LAFM, IDE_LAFM is not required */
    	RCANET.MB[8].CTRL1.WORD   = 0x0008;				/* Set Mailbox1 for transmission, data length 8 bytes */


    	/* BitRate Setting */		
       //   	
       //		   			  fclk 
       //BitRate = ------------------------------ , 7<  (TSETG1+TSEG2+1) <26
       //		  (2*(BRP+1)) * (TSEG1+TSEG2+1)          TSEG1=16(17tq),TSEG2=7(8tq),SJW=0,BSP=0
       //
       /* fclk=48MHz, BR:125kbps */
        switch(prvalue){
        	case 0:  //1Mbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0000;                        
            break;
        	case 1:  //500kbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0001;                       
            break;
        	case 2:  //250kbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0003;                      
            break;
        	case 3:  //125kbps
  	          RCANET.BCR1.WORD = 0xf600;						
              RCANET.BCR0.WORD = 0x0007;                        
            break;
            default:
            break;
        }	
}    
	}	
#endif
}

void P14_138(UWORD prx, UWORD prvalue)   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
{
  updatepr(prx, prvalue);
  uwCAN_ChkTime = prvalue;
}

void P14_133(UWORD prx, UWORD prvalue)
{
    UWORD uwIrated;

    updatepr(prx, prvalue);
    if (PRUPDATE==1){
		//-- COF_uwSSIratedPu only relative to pr[PM_MI_RAT], Modify by DINO, 09/09/2008
        if ( pr[STI]==0 ){
        	if ( pr[PM_MI_RAT] > pr[I_RATE] ){ uwIrated = pr[I_RATE]; }
        	else { uwIrated = pr[PM_MI_RAT]; }
        }
        else
        	uwIrated = pr[STI];
        COF_uwSSIratedPu = ((ULONG)uwIrated * 26214 / pr[I_RATE] * 46341 >> 14) / 5;
    }
}

void P10_17(UWORD prx, UWORD prvalue)
{
	UWORD uwParData;	

	// [ Change Velocity Data, Add by DINO, 05/25/2009
	if (pr[UNITSEL] == 1){
		uwParData = flMetric2Hz(prvalue);
	}
	else if (pr[UNITSEL] == 2){
		uwParData = Ft2Hz(prvalue);
	}
	else{
		uwParData = prvalue;
	}
	// ]

	switch(prx){
		case ASR_F1:
    		if (uwParData >= pr[SPI1BAND]){
    			updatepr(prx, prvalue);
    		}
    		break;
		case SPI1BAND:
    		if (uwParData <= pr[ASR_F1]){
    			updatepr(prx, prvalue);
    		}
    		break;
    }
}


/*========================================*///ADDED BY SCOTTY 12/22/06
/*======================================*/ // ONLY FOR PM MOTOR
void P11_02(UWORD prx, UWORD prvalue)
{
    ACC_Unit_SecToms2();
    updatepr(prx, prvalue);
    
    uwOverAccLev = (UWORD)(((ULONG)(pr[OVER_ACC_LEVEL])*(pr[MFBASE1]/10))/(pr[Lift_SPD]))<<2;    //[Over Acceleration protection function, Bernie, 2017/02/13]
    
    if (PRUPDATE==1){
        TQRBaseInit();
    }
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	pr[Lift_SPD_RPM] = (120*(flMetric2Hz(pr[Lift_SPD])/100))/COF_uwPole;//[Sibocom Lift speed(11-01) convert to moter speed, Jason, 20200110]
#endif
    if(SIBO_SPDCHG) //[ACC value reset to 0,Lyabryan,2020/09/10]
        ACC_Unit_ms2ToSec();

}


void P11_05(UWORD prx, UWORD prvalue)   
{
    ULONG ul_temp;
    
    ACC_Unit_SecToms2();
    updatepr(prx, prvalue);
    if (PRUPDATE==1){        
        TQRBaseInit();
        TQRMaxInit();
    }
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	pr[Lift_SPD_RPM] = (120*(flMetric2Hz(pr[Lift_SPD])/100))/COF_uwPole;//[Sibocom Lift speed(11-01) convert to moter speed, Jason, 20200110]
#endif
    if(SIBO_SPDCHG) //[ACC value reset to 0,Lyabryan,2020/09/10]
        ACC_Unit_ms2ToSec();

}

void P11_16(UWORD prx, UWORD prvalue)   // DATA ADDRESS
{
    if ((prvalue&0x0001)==0x0000){
	    updatepr(prx, prvalue);
    }
    else
        KEYEND = ERR;
}

//-DINO 2008/02/21
void P11_18(UWORD prx, UWORD prvalue)   // Protect Bit
{
	if (SHOW_ALLPR==1)
	    updatepr(prx, prvalue);
	else
		KEYEND = ERR;
}
//-END 2008/02/21 

void P15_00(UWORD prx, UWORD prvalue)
{
    UWORD uwDEBUG_F1;

    uwDEBUG_F1 = pr[DEBUG_F1];

    if ((prvalue&0x0008)==0x0008){
        if ((prvalue&0x0010)==0x0010){
            pr[prx] |= prvalue & 0x0018;
            KEYEND = END;
        }
        else{
            pr[prx] = prvalue & 0xFFEF;
            KEYEND = END;
        }
    }
    else{
        updatepr(prx,prvalue);
        MotorPrSel();	// 11/06/2008
    }
    if ((uwDEBUG_F1 & 0x0002)== 0x0002)
        InitCAN();

    if ( ((uwDEBUG_F1^pr[DEBUG_F1])&0x0018)!=0 )  // bit3 or 4 are modified, initial SCI1
        InitSCI0();
}

void P15_02(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1)
        TB1_VFCal_Slin();
}

void P15_34(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1)
        set_VcmpMax();
}

void P15_12(UWORD prx, UWORD prvalue)
{
    updatepr(prx, prvalue);
    if (PRUPDATE==1)
        VBusLineInit();
}

void P15_41(UWORD prx, UWORD prvalue)
{
	updatepr(prx, prvalue);
    if (PRUPDATE==1)
        DBCDu = pr[DBC1]>>4;

}
void P15_42(UWORD prx, UWORD prvalue)
{
	updatepr(prx, prvalue);
    if (PRUPDATE==1)
        DBCDt = pr[DBC2]>>4;

}
void ACC_Unit_SecToms2(void) //[Unit sec=>m/(sec^2)]
{
                PR_flAccel1ms2 = ACC_UnitConv(PR_flAccel1sec, 0);
                PR_flAccel2ms2 = ACC_UnitConv(PR_flAccel2sec, 0);
                PR_flAccel3ms2 = ACC_UnitConv(PR_flAccel3sec, 0);
                PR_flAccel4ms2 = ACC_UnitConv(PR_flAccel4sec, 0);
                PR_flDecel1ms2 = ACC_UnitConv(PR_flDecel1sec, 0);
                PR_flDecel2ms2 = ACC_UnitConv(PR_flDecel2sec, 0);
                PR_flDecel3ms2 = ACC_UnitConv(PR_flDecel3sec, 0);
                PR_flDecel4ms2 = ACC_UnitConv(PR_flDecel4sec, 0);
                PR_flDecel5ms2 = ACC_UnitConv(PR_flDecel5sec, 0);
                PR_flDecelJogms2 = ACC_UnitConv(PR_flDecelJogsec, 0);
                PR_flAccelJogms2 = ACC_UnitConv(PR_flAccelJogsec, 0);
                PR_flDecelEsdms2 = ACC_UnitConv(PR_flDecelEsdsec, 0);
                
                PR_flSAcc1Esdms3 = SCurve_UnitConv(S4ACC1, PR_flSAcc1Esdsec, 0);
                PR_flSAcc2Esdms3 = SCurve_UnitConv(S4ACC2, PR_flSAcc2Esdsec, 0);
                PR_flSDec1Esdms3 = SCurve_UnitConv(S4DEC1, PR_flSDec1Esdsec, 0);
                PR_flSDec2Esdms3 = SCurve_UnitConv(S4DEC2, PR_flSDec2Esdsec, 0);
                PR_flSDec3Esdms3 = SCurve_UnitConv(S4DEC3, PR_flSDec3Esdsec, 0);
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]    //[Sibocom unit convert to moter speed, Jason, 20200512]
                PR_flDecelEMYSIBOms2 = ACC_UnitConv(PR_flDecelEMYSIBOsec, 0);
                PR_flS3EMYms3 = SCurve_UnitConv(SIBO_S3EMY, PR_flS3EMYsec, 0);
                PR_flS4EMYms3 = SCurve_UnitConv(SIBO_S4EMY, PR_flS4EMYsec, 0);
                PR_flFmi7ms = flHz2Metric(PR_flFmi7Hz);
                PR_flFmi8ms = flHz2Metric(PR_flFmi8Hz);
                PR_flFmi9ms = flHz2Metric(PR_flFmi9Hz);
                PR_flFmi10ms = flHz2Metric(PR_flFmi10Hz);
                PR_flFmi11ms = flHz2Metric(PR_flFmi11Hz);
                PR_flFmi12ms = flHz2Metric(PR_flFmi12Hz);
                
                PR_flFJog_ms = flHz2Metric(PR_flFJog_Hz); 
                //PR_flfkey_ms = flHz2Metric(fkey.uw.hi);
#endif

}

void ACC_Unit_ms2ToSec(void)
{
    if((pr[SOFC] == 4) || (pr[SOFC] == 5)){     //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]               
        facc1.ul = cal_time(pr[FMAX],0);
        fdec1.ul = cal_time(pr[FMAX],0);
        facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
        fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
        facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
        fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
        facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
        fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);   
        fjacc.ul = cal_time(pr[FMAX],0);
        fjdec.ul = cal_time(pr[FMAX],0);
        fdec5.ul = cal_time(pr[FMAX],0);
        Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
        fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]);  //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        fdecEMY.ul = cal_time(pr[FMAX],pr[SIBO_DECEMY]);
#endif
    }
    else{           

        PR_flAccel1sec = ACC_UnitConv(PR_flAccel1ms2, 1);
        PR_flAccel2sec = ACC_UnitConv(PR_flAccel2ms2, 1);
        PR_flAccel3sec = ACC_UnitConv(PR_flAccel3ms2, 1);
        PR_flAccel4sec = ACC_UnitConv(PR_flAccel4ms2, 1);
        PR_flDecel1sec = ACC_UnitConv(PR_flDecel1ms2, 1);
        PR_flDecel2sec = ACC_UnitConv(PR_flDecel2ms2, 1);
        PR_flDecel3sec = ACC_UnitConv(PR_flDecel3ms2, 1);
        PR_flDecel4sec = ACC_UnitConv(PR_flDecel4ms2, 1);
        PR_flDecel5sec = ACC_UnitConv(PR_flDecel5ms2, 1);
        PR_flDecelJogsec = ACC_UnitConv(PR_flDecelJogms2, 1);
        PR_flAccelJogsec = ACC_UnitConv(PR_flAccelJogms2, 1);
        PR_flDecelEsdsec = ACC_UnitConv(PR_flDecelEsdms2, 1);
        PR_flSAcc1Esdsec = SCurve_UnitConv(S4ACC1, PR_flSAcc1Esdms3, 1);
        PR_flSAcc2Esdsec = SCurve_UnitConv(S4ACC2, PR_flSAcc2Esdms3, 1);
        PR_flSDec1Esdsec = SCurve_UnitConv(S4DEC1, PR_flSDec1Esdms3, 1);
        PR_flSDec2Esdsec = SCurve_UnitConv(S4DEC2, PR_flSDec2Esdms3, 1);
        PR_flSDec3Esdsec = SCurve_UnitConv(S4DEC3, PR_flSDec3Esdms3, 1); 
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        PR_flDecelEMYSIBOsec = ACC_UnitConv(PR_flDecelEMYSIBOms2, 1);
        PR_flS3EMYsec = SCurve_UnitConv(SIBO_S3EMY, PR_flS3EMYms3, 1);
        PR_flS4EMYsec = SCurve_UnitConv(SIBO_S4EMY, PR_flS4EMYms3, 1);
        PR_flFmi7Hz = flMetric2Hz(PR_flFmi7ms);
        PR_flFmi8Hz = flMetric2Hz(PR_flFmi8ms);
        PR_flFmi9Hz = flMetric2Hz(PR_flFmi9ms);
        PR_flFmi10Hz = flMetric2Hz(PR_flFmi10ms);
        PR_flFmi11Hz = flMetric2Hz(PR_flFmi11ms);
        PR_flFmi12Hz = flMetric2Hz(PR_flFmi12ms);
        PR_flFJog_Hz = flMetric2Hz(PR_flFJog_ms);
#endif
        pr[ACCEL1] = PR_flAccel1sec;
        pr[ACCEL2] = PR_flAccel2sec;
        pr[ACCEL3] = PR_flAccel3sec;
        pr[ACCEL4] = PR_flAccel4sec;
        pr[DECEL1] = PR_flDecel1sec;
        pr[DECEL2] = PR_flDecel2sec;
        pr[DECEL3] = PR_flDecel3sec;
        pr[DECEL4] = PR_flDecel4sec;
        pr[DECEL5] = PR_flDecel5sec;
        pr[JOGDEC] = PR_flDecelJogsec;
        pr[JOGACC] = PR_flAccelJogsec;
        pr[DECEL_ESD] = PR_flDecelEsdsec;
        
        pr[S4ACC1] = PR_flSAcc1Esdsec;
        pr[S4ACC2] = PR_flSAcc2Esdsec;
        pr[S4DEC1] = PR_flSDec1Esdsec;
        pr[S4DEC2] = PR_flSDec2Esdsec;
        pr[S4DEC3] = PR_flSDec3Esdsec;  
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        pr[SIBO_DECEMY] = PR_flDecelEMYSIBOsec;
        pr[SIBO_S3EMY] = PR_flS3EMYsec;
        pr[SIBO_S4EMY] = PR_flS4EMYsec;
        pr[FMI7] = PR_flFmi7Hz;
        pr[FMI8] = PR_flFmi8Hz;
        pr[FMI9] = PR_flFmi9Hz;
        pr[FMI10] = PR_flFmi10Hz;
        pr[FMI11] = PR_flFmi11Hz;
        pr[FMI12] = PR_flFmi12Hz;
        pr[JOGF] = PR_flFJog_Hz;
#endif
        write_ep(BLK_WRITE, ACCEL1, pr[ACCEL1]);
        write_ep(BLK_WRITE, ACCEL2, pr[ACCEL2]);
        write_ep(BLK_WRITE, ACCEL3, pr[ACCEL3]);
        write_ep(BLK_WRITE, ACCEL4, pr[ACCEL4]);
        write_ep(BLK_WRITE, DECEL1, pr[DECEL1]);
        write_ep(BLK_WRITE, DECEL2, pr[DECEL2]);
        write_ep(BLK_WRITE, DECEL3, pr[DECEL3]);
        write_ep(BLK_WRITE, DECEL4, pr[DECEL4]);
        write_ep(BLK_WRITE, DECEL5, pr[DECEL5]);
        write_ep(BLK_WRITE, JOGDEC, pr[JOGDEC]);
        write_ep(BLK_WRITE, JOGACC, pr[JOGACC]);
        write_ep(BLK_WRITE, DECEL_ESD, pr[DECEL_ESD]);
        write_ep(BLK_WRITE, S4ACC1, pr[S4ACC1]);
        write_ep(BLK_WRITE, S4ACC2, pr[S4ACC2]);
        write_ep(BLK_WRITE, S4DEC1, pr[S4DEC1]);
        write_ep(BLK_WRITE, S4DEC2, pr[S4DEC2]);
        write_ep(BLK_WRITE, S4DEC3, pr[S4DEC3]);
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        write_ep(BLK_WRITE, SIBO_DECEMY, pr[SIBO_DECEMY]);
        write_ep(BLK_WRITE, SIBO_S3EMY, pr[SIBO_S3EMY]);
        write_ep(BLK_WRITE, SIBO_S4EMY, pr[SIBO_S4EMY]);
        write_ep(BLK_WRITE, FMI7, pr[FMI7]);
        write_ep(BLK_WRITE, FMI8, pr[FMI8]);
        write_ep(BLK_WRITE, FMI9, pr[FMI9]);
        write_ep(BLK_WRITE, FMI10, pr[FMI10]);
        write_ep(BLK_WRITE, FMI11, pr[FMI11]);
        write_ep(BLK_WRITE, FMI12, pr[FMI12]);
        //fkey.uw.hi = flMetric2Hz(PR_flfkey_ms);
#endif
        facc1.ul = cal_time(pr[FMAX],pr[ACCEL1]);
        fdec1.ul = cal_time(pr[FMAX],pr[DECEL1]);
        facc2.ul = cal_time(pr[FMAX],pr[ACCEL2]);
        fdec2.ul = cal_time(pr[FMAX],pr[DECEL2]);
        facc3.ul = cal_time(pr[FMAX],pr[ACCEL3]);
        fdec3.ul = cal_time(pr[FMAX],pr[DECEL3]);
        facc4.ul = cal_time(pr[FMAX],pr[ACCEL4]);
        fdec4.ul = cal_time(pr[FMAX],pr[DECEL4]);   
        fjacc.ul = cal_time(pr[JOGF],pr[JOGACC]);   
        fjdec.ul = cal_time(pr[JOGF],pr[JOGDEC]);   
        fdec5.ul = cal_time(pr[FMAX],pr[DECEL5]);
        Pfdec.ul = cal_time(pr[FMAX],pr[APRDECT]);
        fdec_ESD.ul = cal_time(pr[FMAX],pr[DECEL_ESD]); //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        fdecEMY.ul = cal_time(pr[FMAX],pr[SIBO_DECEMY]);
#endif
    }

}


void flashpr(UWORD prx, UWORD prvalue)
{
	if (((attr[prx].ati&READ)==0)&& PRLOCK==0 && FSET_LOCK==0){
    	if ((RUNNING==STOP)||(attr[prx].ati&WRUN)) {        	
    		if ((prvalue<=attr[prx].max)&&(prvalue>=attr[prx].min)){
#if DINO //-- Add by DINO, 09/05/2008
				KEYEND = END;
				if ( prx==AFMCALIB ){
					if ( SHOW_ALLPR )
						pr[AFMCALIB] = prvalue;
					else
						KEYEND = ERR;
				}
				else
					pr[prx] = prvalue;
				//-- Update Buffer Data, Add by DINO, 10/28/2008
				MI_INVMem = pr[MI_INV];
				MO_INVMem = pr[MO_INV];
				PGHOMEMem = pr[PGHOME];
#else
				switch(prx){
					case PGHOME:
						pr[PGHOME] = prvalue;
						KEYEND = END;
						break;
					case MI_INV:
						pr[MI_INV] = prvalue;
						KEYEND = END;
						break;
					case MO_INV:
						pr[MO_INV] = prvalue;
						KEYEND = END;
						break;
//-- Add by DINO, 03/07/2008
					case AFMCALIB:
						if ( SHOW_ALLPR ){
							pr[AFMCALIB] = prvalue;
							KEYEND = END;
						}
						else
							KEYEND = ERR;
						break;
//-- End 03/07/2008
					default:
						break;
				}
#endif
			}
		}
	}
}

UWORD Set_LPG(UWORD prvalue , UWORD ds)
{
	UWORD ax,bx;
	
    if(prvalue != 0){
    	bx = prvalue * ds;
    	ax = 65535/bx;
    	return ax;
    }
    else{
    	return 65535;
    }
}


void LPFGain(UWORD prx, UWORD prvalue)
{
	updatepr(prx,prvalue);
    if (PRUPDATE==1){
    	switch(prx){
    		case SVC_SLPG:
    		    VFfslip_uwLPG = Set_LPG(pr[SVC_SLPG],1);	
    		    break;
    		case SVC_VLPG:
    		    VFVcomp_uwLPG = Set_LPG(pr[SVC_VLPG],1);
    		    break;
    		case COSPHILPG:
    		    cosphi_uwLPG = Set_LPG(pr[COSPHILPG],1);
    		    break;
    		case AUI1_LPG:{
    			AUI1In_LPG = Set_LPG(pr[AUI1_LPG],10);
    			}break;
    		case ACI_LPG:{
    			ACIIn_LPG = Set_LPG(pr[ACI_LPG],10);
				}break;
    		case AUI2_LPG:{
    			AUI2In_LPG = Set_LPG(pr[AUI2_LPG],10);
				}break;
    		case LPF_DISP:{
    			DisplayLPG = Set_LPG(pr[LPF_DISP],1);
    			}break;
    		case HiSpd_LPG:{
//    			SpDt_uwHiLPG = Set_LPG(pr[HiSpd_LPG],1);
    			SpDt_uwHiLPG = U16xU16divU16(3217, (pr[HiSpd_LPG]<<4), 2000); //Q13, 3217=2*pi*2^9, 2000=1/500us
    			}break;
    		case LoSpd_LPG:{
//    			SpDt_uwLoLPG = Set_LPG(pr[LoSpd_LPG],1);
    			SpDt_uwLoLPG = U16xU16divU16(3217, (pr[LoSpd_LPG]<<4), 2000); //Q13, 3217=2*pi*2^9, 2000=1/500us
    			}break;
    	    case TQRLPG:{
    	        Tqc_uwTqCmdLPG = Set_LPG(pr[TQRLPG],1);
    	        }break;
    	    case PG2_LPG:{
    	        PG2R_uwCmdLPG = Set_LPG(pr[PG2_LPG],1);
    	        }break;
    	    case EstJ_LPG:{
    	        EsJ_uwLPG = Set_LPG(pr[EstJ_LPG],1);
    	        }break;
            case PIDDLY:{
                PID_LPG = Set_LPG(pr[PIDDLY],100);
                }break;
            case IZEROLPG:{
                CurZero_LPG = Set_LPG(pr[IZEROLPG],1);
                }break;
            case PTC_DFT:
                PTCIn_LPG = Set_LPG(pr[PTC_DFT],10);
                break; 
			case DCBUSLPG:
				dcbusLPG =  Set_LPG(pr[DCBUSLPG],1);    //0.001, in 1ms, 0.001/1ms = 1
				break;
			case PHL_T:									//SCOTTY 09/05/2007
                PHL_LPG = Set_LPG(pr[PHL_T],10);        //0.01, in 1ms, 0.01/1ms = 10
                break;                               
			// [ PPI LPF Gain, DINO, 07/28/2010
			case ZSPLowpass:
                SPR_uwPPILPG = Set_LPG(pr[ZSPLowpass],2);	//0.001, in 500us, 0.001/500us = 2
                break;
            case LPF_LC01DISP:
                LC01DisplayLPG = Set_LPG(pr[LPF_LC01DISP],1);   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
                break;
            // ]
    	    default:
    	        break;
    	}
  	}    
}


void PrArea(UWORD prvalue)
{
	UWORD ax;

	if(prvalue !=0) {
       	if(prvalue== 9){        // 50Hz, 220V/380V
       		if((pr[HPSPEC]&VFD440V)==VFD220V)
          		ax = 4400;     // 230V(460V) for 220V series
       		else
           		ax = 3800;     // 400V, for 440V series

       		pr[VMAX1]= ax;
       		pr[VMAX2] = ax;
       		write_ep(BLK_WRITE,VMAX1, ax);
       		write_ep(BLK_WRITE,VMAX2, ax);

       		//----[ Fbase, Vbase parameter setting ]-----------------
       		pr[FMAX]      = 5000;
       		pr[FMAIN]     = 5000;
       		pr[FCMAIN]    = 5000;
       		pr[MFBASE1]   = 5000;
       		pr[MFBASE2]   = 5000;
       		pr[DESIRE_F1] = 5000;
       		pr[DESIRE_F2] = 5000;
       		INIT_USER     = 1;
       		uwFkeypad     = 5000;
       		C20xx[0x01]   = 5000;	// Add by DINO, 10/27/2008

       		write_ep(BLK_WRITE,FMAX, 5000);
       		write_ep(BLK_WRITE,FMAIN, 5000);
       		write_ep(BLK_WRITE,FCMAIN,5000);
       		write_ep(BLK_WRITE,MFBASE1, 5000);
       		write_ep(BLK_WRITE,MFBASE2, 5000);
       		write_ep(BLK_WRITE,DESIRE_F1, 5000);
       		write_ep(BLK_WRITE,DESIRE_F2, 5000);

		}
       	else if(prvalue== 10){		// 60Hz, 230V/460V
       		ax = 4400;     			// 230V(460V)
       		pr[VMAX1]= ax;
       		pr[VMAX2] = ax;
       		write_ep(BLK_WRITE,VMAX1, ax);
       		write_ep(BLK_WRITE,VMAX2, ax);

       		//----[ Fbase, Vbase parameter setting ]-----------------
       		pr[FMAX]      = 6000;          		
       		pr[FMAIN]     = 6000;
       		pr[FCMAIN]    = 6000;
       		pr[MFBASE1]   = 6000;
       		pr[MFBASE2]   = 6000;
       		pr[DESIRE_F1] = 6000;
       		pr[DESIRE_F2] = 6000;
       		INIT_USER     = 1;
       		uwFkeypad     = 6000;
       		C20xx[0x01]   = 6000;	// Add by DINO, 10/27/2008

       		write_ep(BLK_WRITE,FMAX, 6000);
       		write_ep(BLK_WRITE,FMAIN, 6000);
       		write_ep(BLK_WRITE,FCMAIN, 6000);
       		write_ep(BLK_WRITE,MFBASE1, 6000);
       		write_ep(BLK_WRITE,MFBASE2, 6000);
       		write_ep(BLK_WRITE,DESIRE_F1, 6000);
       		write_ep(BLK_WRITE,DESIRE_F2, 6000);
       	}
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            pr[UNITSEL] = 1;
            write_ep(BLK_WRITE, UNITSEL, 1);
#endif
     }
}

/*------ Fault Record ------------------------------------------------------*/
void Fault_Record(void)
{
    if (ERR_LOG==0) {                   // fault record complete flag

        //[special,increase error record, 2018/09/20
        pr[FOUT_REC5]  = pr[FOUT_REC4];
        rec_uwError5_1 = pr[FOUT_REC5];

        pr[DCBUS_REC5] = pr[DCBUS_REC4];
        rec_uwError5_2 = pr[DCBUS_REC5];

        pr[ISUM_REC5]  = pr[ISUM_REC4];
        rec_uwError5_3 = pr[ISUM_REC5];

        pr[TH_TEMP5]   = pr[TH_TEMP4];
        rec_uwError5_4 = pr[TH_TEMP5];
        
        pr[FOUT_REC4]  = pr[FOUT_REC3];
        rec_uwError4_1 = pr[FOUT_REC4];

        pr[DCBUS_REC4] = pr[DCBUS_REC3];
        rec_uwError4_2 = pr[DCBUS_REC4];

        pr[ISUM_REC4]  = pr[ISUM_REC3];
        rec_uwError4_3 = pr[ISUM_REC4];

        pr[TH_TEMP4]   = pr[TH_TEMP3];
        rec_uwError4_4 = pr[TH_TEMP4];
        
        pr[FOUT_REC3]  = pr[FOUT_REC2];
        rec_uwError3_1 = pr[FOUT_REC3];

        pr[DCBUS_REC3] = pr[DCBUS_REC2];
        rec_uwError3_2 = pr[DCBUS_REC3];

        pr[ISUM_REC3]  = pr[ISUM_REC2];
        rec_uwError3_3 = pr[ISUM_REC3];

        pr[TH_TEMP3]   = pr[TH_TEMP2];
        rec_uwError3_4 = pr[TH_TEMP3];

        pr[FOUT_REC2]  = pr[FOUT_REC1];
        rec_uwError2_1 = pr[FOUT_REC2];

        pr[DCBUS_REC2] = pr[DCBUS_REC1];
        rec_uwError2_2 = pr[DCBUS_REC2];

        pr[ISUM_REC2]  = pr[ISUM_REC1];
        rec_uwError2_3 = pr[ISUM_REC2];

        pr[TH_TEMP2]   = pr[TH_TEMP1];
        rec_uwError2_4 = pr[TH_TEMP2];

        pr[FOUT_REC1]  = pr[FOUT_REC];
        rec_uwError1_1 = pr[FOUT_REC1];

        pr[DCBUS_REC1] = pr[DCBUS_REC];
        rec_uwError1_2 = pr[DCBUS_REC1];

        pr[ISUM_REC1]  = pr[ISUM_REC];
        rec_uwError1_3 = pr[ISUM_REC1];

        pr[TH_TEMP1]   = pr[TH_TEMP];
        rec_uwError1_4 = pr[TH_TEMP1];
        //special,increase error record, 2018/09/20]


        pr[FFBK_REC] = err_uwFfbk;
		rec_uwFfbk   = pr[FFBK_REC];
//      write_ep(0,FFBK_REC,pr[FFBK_REC]);
       
		// add by dino, 10/31/2007
		pr[FOUT_REC] = err_uwFcmd;
		rec_uwFcmd   = pr[FOUT_REC];
//      write_ep(0,FOUT_REC,pr[FOUT_REC]);
 
 		pr[VOUT_REC] = err_uwVout;
 		rec_uwVout   = pr[VOUT_REC];
//		write_ep(0,VOUT_REC,pr[VOUT_REC]);
       
		pr[DCBUS_REC] = err_uwDcbus;
		rec_uwDcbus   = pr[DCBUS_REC];
//        write_ep(0,DCBUS_REC,pr[DCBUS_REC]);

		pr[ISUM_REC] = err_uwIsum;
		rec_uwIsum   = pr[ISUM_REC];
//		write_ep(0,ISUM_REC,pr[ISUM_REC]);

        pr[TH_TEMP] = IGBT_Temp;
        rec_uwIGBT  = pr[TH_TEMP];
//        write_ep(0,TH_TEMP,pr[TH_TEMP]);
//#if SH7147  /* 04/20/2007, dino */
		pr[SRYREC] = prt_ubSRYrec;
		rec_uwSRY  = pr[SRYREC];
//        write_ep(0,SRYREC,pr[SRYREC]);
//#endif
        pr[ERR_REC6] = pr[ERR_REC5];     // record5 ->record6 //
		rec_uwFault6 = pr[ERR_REC6];
//        write_ep(0,ERR_REC6,pr[ERR_REC6]);

        pr[ERR_REC5] = pr[ERR_REC4];     // record4 ->record5 //
		rec_uwFault5 = pr[ERR_REC5];
//        write_ep(0,ERR_REC5,pr[ERR_REC5]);

        pr[ERR_REC4] = pr[ERR_REC3];     // record3 ->record4 //
		rec_uwFault4 = pr[ERR_REC4];
//        write_ep(0,ERR_REC4,pr[ERR_REC4]);

        pr[ERR_REC3] = pr[ERR_REC2];     // record2 ->record3 //
		rec_uwFault3 = pr[ERR_REC3];
//        write_ep(0,ERR_REC3,pr[ERR_REC3]);

        pr[ERR_REC2] = pr[ERR_REC1];     // record1 ->record2 //
		rec_uwFault2 = pr[ERR_REC2];
//        write_ep(0,ERR_REC2,pr[ERR_REC2]);

        pr[ERR_REC1] = Error;            // ERROR ->record1   //
		rec_uwFault1 = pr[ERR_REC1];
//        write_ep(0,ERR_REC1,pr[ERR_REC1]);

		// [ Add Fault Record Data, DINO, 06/11/2009
		pr[ERR_MIN6] = pr[ERR_MIN5];
		rec_uwErrMin6= pr[ERR_MIN6];

		pr[ERR_DAY6] = pr[ERR_DAY5];
		rec_uwErrDay6= pr[ERR_DAY6];

		pr[ERR_MIN5] = pr[ERR_MIN4];
		rec_uwErrMin5= pr[ERR_MIN5];

		pr[ERR_DAY5] = pr[ERR_DAY4];
		rec_uwErrDay5= pr[ERR_DAY5];

		pr[ERR_MIN4] = pr[ERR_MIN3];
		rec_uwErrMin4= pr[ERR_MIN4];

		pr[ERR_DAY4] = pr[ERR_DAY3];
		rec_uwErrDay4= pr[ERR_DAY4];

		pr[ERR_MIN3] = pr[ERR_MIN2];
		rec_uwErrMin3= pr[ERR_MIN3];

		pr[ERR_DAY3] = pr[ERR_DAY2];
		rec_uwErrDay3= pr[ERR_DAY3];

		pr[ERR_MIN2] = pr[ERR_MIN1];
		rec_uwErrMin2= pr[ERR_MIN2];

		pr[ERR_DAY2] = pr[ERR_DAY1];
		rec_uwErrDay2= pr[ERR_DAY2];

		pr[ERR_MIN1] = pr[PWR_MIN];  // Modify from RUNMIN to PWRMIN, DINO, 09/30/2009
		rec_uwErrMin1= pr[ERR_MIN1];

		pr[ERR_DAY1] = pr[PWR_DAY];  // Modify from RUNDAY to PWRDAY, DINO, 09/30/2009
		rec_uwErrDay1= pr[ERR_DAY1];
		

		pr[FKEY_REC] = err_uwFkey;
		rec_uwFkey   = pr[FKEY_REC];

		pr[POWER_REC]= err_uwPower;
		rec_uwPower  = pr[POWER_REC];

		pr[TQ_REC]   = err_uwTorq;
		rec_uwTorq   = pr[TQ_REC];

		pr[MFI_REC]  = err_uwMFI;
		rec_uwMFI    = pr[MFI_REC];

		pr[MFO_REC]  = err_uwMFO;
		rec_uwMFO    = pr[MFO_REC];

		pr[STATE_REC]= err_uwState;
		rec_uwState  = pr[STATE_REC];
		// ]

        ERR_LOG = 1;                   // ERR_LOG=1, fault record complete //
     }
}

void P15_87(UWORD prx, UWORD prvalue)
{
	updatepr(prx, prvalue);
    if (PRUPDATE==1)
        AnaPGInit();

}

void P15_108(UWORD prx, UWORD prvalue)
{
	updatepr(prx, prvalue);
    if (PRUPDATE==1)
        InitSCI0();

}

void AnaPGInit(void){
    st_swSINmean = (pr[SINMAX] + pr[SINMIN]) >>1;
    st_swCOSmean = (pr[COSMAX] + pr[COSMIN]) >>1;
}


/*-------------- [ 0.01m/s -> 0.01Hz (Q5), Add by DINO, 05/25/2009 ] --------------
--
--        m/s * pr[GearRatio] * (pr[SUSPENSION]+1) * COF_uwPole      1000
--  Hz = ------------------------------------------------------- * --------
--                            pr[SHEAVE_D]                          2 * pi
--
--  1000/2/pi = 5093/32
---------------------------------------------------------------------------------*/
UWORD Metric2Hz(UWORD uwSpeed)
{
	UWORD bx, uwFreq;
	ULONG_UNION FDisplay;
    UWORD uwSuspensionR;
    
    switch(pr[SUSPENSION]){
        case 0:
            uwSuspensionR = 1;
            break;        
        case 1:
            uwSuspensionR = 2;
            break;
        case 2:
            uwSuspensionR = 4;
            break;        
        case 3:
            uwSuspensionR = 8;
            break;            
        default:
            uwSuspensionR = 1;
            break;
    }

	//bx = COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1);
    //bx = ((COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1))+50)/100;       //[Gear ratio change, Bernie, 2015/09/08]
    bx = ((COF_uwPole * pr[GearRatio] * uwSuspensionR)+50)/100;    //[fix SUSPENSION err, Jason, 2020/04/28]

	FDisplay.ul = U32xU32divU32((uwSpeed*5093), bx, pr[SHEAVE_D]);
	FDisplay.ul = (FDisplay.ul + 16) >> 5;

	if (FDisplay.ul > MAXF){
		uwFreq = MAXF;
	}
	else{
		uwFreq = FDisplay.uw.low;
	}

	return(uwFreq);
}

/*-------------- [ 0.01m/s -> 0.01Hz (Q5), Add by DINO, 05/25/2009 ] --------------
--
--        m/s * pr[GearRatio] * (pr[SUSPENSION]+1) * COF_uwPole      1000
--  Hz = ------------------------------------------------------- * --------
--                            pr[SHEAVE_D]                          2 * pi
--
--  1000/2/pi = 5093/32
---------------------------------------------------------------------------------*/
float flMetric2Hz(float flSpeed)
{
	UWORD bx, uwFreq;
	ULONG_UNION FDisplay;
    UWORD uwSuspensionR;
    float flDen, flNum, flFreq;
    float flGearRatio, flSheaveDiaM;
    
    switch(pr[SUSPENSION]){
        case 0:
            uwSuspensionR = 1;
            break;        
        case 1:
            uwSuspensionR = 2;
            break;
        case 2:
            uwSuspensionR = 4;
            break;        
        case 3:
            uwSuspensionR = 8;
            break;            
        default:
            uwSuspensionR = 1;
            break;
    }
    flGearRatio = (float)pr[GearRatio] * 0.01;
    flSheaveDiaM = (float)pr[SHEAVE_D] * 0.001;
    //bx = ((COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1))+50)/100;       //[Gear ratio change, Bernie, 2015/09/08]
    //bx = ((COF_uwPole * pr[GearRatio] * uwSuspensionR)+50)/100;    //[fix SUSPENSION err, Jason, 2020/04/28]
    flNum = flSpeed * (float)COF_uwPole * flGearRatio * (float)uwSuspensionR;    //[fix SUSPENSION err, Jason, 2020/04/28]
    flDen = flSheaveDiaM * TWO_PI; 

    if(flDen != 0){
        flFreq = flNum/flDen;
    }
    else{
        flFreq = MAXF;
    }
    if(flFreq > MAXF){
        flFreq = MAXF;
    }
	//FDisplay.ul = U32xU32divU32((uwSpeed*5093), bx, pr[SHEAVE_D]);
	//FDisplay.ul = (FDisplay.ul + 16) >> 5;

	//if (FDisplay.ul > MAXF){
	//	uwFreq = MAXF;
	//}
	//else{
	//	uwFreq = FDisplay.uw.low;
	//}

	return(flFreq);
}

/*------------- [ 0.01Hz -> 0.01m/s (Q18), Add by DINO, 05/25/2009 ] --------------
--
--                            pr[SHEAVE_D]                          2 * pi
--  Hz = ------------------------------------------------------- * --------
--        m/s * pr[GearRatio] * (pr[SUSPENSION]+1) * COF_uwPole      1000
--
--  2*pi/1000 = 1647/2^18
---------------------------------------------------------------------------------*/
UWORD Hz2Metric(UWORD uwFreq)
{
	UWORD bx, uwSpeed;
	ULONG_UNION FDisplay;
    UWORD uwSuspensionR;
    
    switch(pr[SUSPENSION]){
        case 0:
            uwSuspensionR = 1;
            break;        
        case 1:
            uwSuspensionR = 2;
            break;
        case 2:
            uwSuspensionR = 4;
            break;        
        case 3:
            uwSuspensionR = 8;
            break;            
        default:
            uwSuspensionR = 1;
            break;
    }

    //bx = ((COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1))+50)/100;       //[Gear ratio change, Bernie, 2015/09/08]
    bx = ((COF_uwPole * pr[GearRatio] * uwSuspensionR)+50)/100;    //[fix SUSPENSION err, Jason, 2020/04/28]

	FDisplay.ul = ((((ULONG)uwFreq * 1647 + (bx>>1)) / bx * pr[SHEAVE_D] + 2) >> 2) + 32768;

/*	if (FDisplay.uw.hi > attr[Lift_SPD].max){
		uwSpeed = attr[Lift_SPD].max;
	}
	else{	/* */
		uwSpeed = FDisplay.uw.hi;
//	}

	return(uwSpeed);
}

/*------------- [ 0.01Hz -> 0.01m/s (Q18), Add by DINO, 05/25/2009 ] --------------
--
--                      Hz * pr[SHEAVE_D]                       2 * pi
--  m/s = -------------------------------------------------- * --------
--          pr[GearRatio] * (pr[SUSPENSION]+1) * COF_uwPole      1000
--
--  2*pi/1000 = 1647/2^18
---------------------------------------------------------------------------------*/

float flHz2Metric(float flFreq)
{
	UWORD bx, uwSpeed;
	ULONG_UNION FDisplay;
    UWORD uwSuspensionR;
    float flDen, flNum, flSpeed;
    float flGearRatio, flSheaveDiaM;
    
    switch(pr[SUSPENSION]){
        case 0:
            uwSuspensionR = 1;
            break;        
        case 1:
            uwSuspensionR = 2;
            break;
        case 2:
            uwSuspensionR = 4;
            break;        
        case 3:
            uwSuspensionR = 8;
            break;            
        default:
            uwSuspensionR = 1;
            break;
    }    
    flGearRatio = (float)pr[GearRatio] * 0.01;
    flSheaveDiaM = (float)pr[SHEAVE_D] * 0.001;
    //bx = ((COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1))+50)/100;       //[Gear ratio change, Bernie, 2015/09/08]
    //bx = ((COF_uwPole * pr[GearRatio] * uwSuspensionR)+50)/100;    //[fix SUSPENSION err, Jason, 2020/04/28]
    flDen = (float)COF_uwPole * flGearRatio * (float)uwSuspensionR;    //[fix SUSPENSION err, Jason, 2020/04/28]
    flNum = flFreq * flSheaveDiaM * TWO_PI; 

	//FDisplay.ul = ((((ULONG)uwFreq * 1647 + (bx>>1)) / bx * pr[SHEAVE_D] + 2) >> 2) + 32768;
    
    if(flDen != 0){
        flSpeed = flNum / flDen;
    }
    else{
        flSpeed = 65535;
    }
    if(flSpeed > 65535){
        flSpeed = 65535;
    }

/*	if (FDisplay.uw.hi > attr[Lift_SPD].max){
		uwSpeed = attr[Lift_SPD].max;
	}
	else{	/* */
	//	uwSpeed = FDisplay.uw.hi;
//	}

	return(flSpeed);
}



/*------------- [ 0.01ft/s -> 0.01Hz (Q7), Add by DINO, 05/25/2009 ] --------------
--
--        ft/s * pr[GearRatio] * (pr[SUSPENSION]+1) * COF_uwPole     1000        1
--  Hz = ------------------------------------------------------- * -------- * -------
--                            pr[SHEAVE_D]                          2 * pi      3.28
--
--  1000*3.28/2/pi = 6211/128
---------------------------------------------------------------------------------*/
UWORD Ft2Hz(UWORD uwFt)
{
	UWORD bx, uwFreq;
	ULONG_UNION FDisplay;

	//bx = COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1);
    bx = ((COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1))+50)/100;       //[Gear ratio change, Bernie, 2015/09/08]

	FDisplay.ul = U32xU32divU32((uwFt*6211), bx, pr[SHEAVE_D]);
	FDisplay.ul = (FDisplay.ul + 64) >> 7;

	if (FDisplay.ul > MAXF){
		uwFreq = MAXF;
	}
	else{
		uwFreq = FDisplay.uw.low;
	}

	return(uwFreq);
}


/*------------- [ 0.01Hz -> 0.01ft/s (Q19), Add by DINO, 05/25/2009 ] --------------
--
--                            pr[SHEAVE_D]                          2 * pi
--  Hz = ------------------------------------------------------- * -------- * 3.28
--        m/s * pr[GearRatio] * (pr[SUSPENSION]+1) * COF_uwPole      1000
--
--  2*pi*3.28/1000 = 10805/2^19
----------------------------------------------------------------------------------*/
UWORD Hz2Ft(UWORD uwFreq)
{
	UWORD bx, uwFt, uwPRMax;
	ULONG_UNION FDisplay;

//	uwPRMax = ((ULONG)attr[Lift_SPD].max * 13435 + 2048) >> 12;
	//bx = COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1);
    bx = ((COF_uwPole * pr[GearRatio] * (pr[SUSPENSION]+1))+50)/100;       //[Gear ratio change, Bernie, 2015/09/08]

	FDisplay.ul = ((((ULONG)uwFreq * 10805 + (bx>>1)) / bx * pr[SHEAVE_D] + 4) >> 3) + 32768;
/*
	if (FDisplay.uw.hi > uwPRMax){
		uwFt = uwPRMax;
	}
	else{  /*  */
		uwFt = FDisplay.uw.hi;
//	}

	return(uwFt);
}

//[ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
/* AccTimeS: Dot2, return: Dot2*/
float SToMs2(float flAccTimeS){	
	float flAcc;
	if(flAccTimeS == 0){
		flAcc = 65535;
	}
	else{
		flAcc = (flHz2Metric(pr[FMAX])/flAccTimeS)*100.f;
		if(flAcc > 65535){
			flAcc = 65535;
		}
	}
	return flAcc;
}

/* AccMs2: Dot2, return: Dot2*/
float Ms2ToS(float flAccMs2){	
	float flTimeS;
	if(flAccMs2 == 0){
		flTimeS = 60000;
	}
	else{
        
		flTimeS = (flHz2Metric(pr[FMAX])/flAccMs2)*100.f;
		if(flTimeS > 60000){
			flTimeS = 60000;
		}
	}
	return flTimeS;
}
/* Ms3Input: Dot2, AccTimePrValue: Dot2, return: Dot2*/
float Ms3ToS(float flMs3Input, float flAccTimePrValue)
{
	float flAcc;
	float flTime;
	
	if(flAccTimePrValue == 0){
		flAcc = 65535.f;
	}
	else{
		flAcc = (flHz2Metric(pr[FMAX])/flAccTimePrValue)*100.f;
	}
	
	if(flMs3Input == 0){
		flTime = 2500.f;
	}
	else{
		flTime = (flAcc/flMs3Input)*100.f;
		if(flTime > 2500.f){
			flTime = 2500.f;
		}
	}
	return flTime;
}
/* SInput: Dot2, AccTimePrValue: Dot2, return: Dot2*/
float SToMs3(float flSInput, float flAccTimePrValue)
{
	float flAcc;
	float flJerk;

	if(flAccTimePrValue == 0){
		flAcc = 65535.f;
	}
	else{
		flAcc = flHz2Metric(pr[FMAX])/flAccTimePrValue*100.f;
	}
	if(flSInput == 0){
		flJerk = 65535.f;
	}
	else{
		flJerk = (flAcc/flSInput)*100.f;
		if(flJerk>65535.f){
			flJerk = 65535.f;
		}
	}
	return flJerk;
}
/* AccTimeS: Dot2, return: Dot2*/
UWORD SToFts2(UWORD uwAccTimeS){	
	float flAcc;
	if(uwAccTimeS == 0){
		flAcc = 65535;
	}
	else{
		flAcc = ((float)(Hz2Ft(pr[FMAX]))/(float)uwAccTimeS)*100.F+0.5;
		if(flAcc > 65535){
			flAcc = 65535;
		}
	}
	return (UWORD)flAcc;
}
/* AccMs2: Dot2, return: Dot2*/
UWORD Fts2ToS(UWORD uwAccMs2){	
	float flTimeS;
	if(uwAccMs2 == 0){
		flTimeS = 60000;
	}
	else{
		flTimeS = ((float)(Hz2Ft(pr[FMAX]))/(float)uwAccMs2)*100.F+0.5;
		if(flTimeS > 60000){
			flTimeS = 60000;
		}
	}
	return (UWORD)flTimeS;
}

UWORD Fts3ToS(UWORD uwMs3Input, UWORD uwAccTimePrValue)
{
	float flAcc;
	ULONG ulTime;
	
	if(uwAccTimePrValue == 0){
		flAcc = 65535;
	}
	else{
		flAcc = ((float)(Hz2Ft(pr[FMAX]))/(float)uwAccTimePrValue)*100.F;
	}
	
	if(uwMs3Input == 0){
		ulTime = 2500U;
	}
	else{
		ulTime = (ULONG)((flAcc/(float)uwMs3Input)*100.F+0.5);
		if(ulTime > 2500U){
			ulTime = 2500U;
		}
	}
	return (UWORD)ulTime;
}
/* SInput: Dot2, AccTimePrValue: Dot2, return: Dot2*/
UWORD SToFts3(UWORD uwSInput, UWORD uwAccTimePrValue)
{
	float flAcc;
	ULONG ulJerk;

	if(uwAccTimePrValue == 0){
		flAcc = 65535;
	}
	else{
		flAcc = ((float)(Hz2Ft(pr[FMAX]))/(float)uwAccTimePrValue)*100.F;
	}
	if(uwSInput == 0){
		ulJerk = 65535;
	}
	else{
		ulJerk = (ULONG)((flAcc/(float)uwSInput)*100.F+0.5);
		if(ulJerk>65535){
			ulJerk = 65535;
		}
	}
	return (UWORD)ulJerk;
}

float ACC_UnitConv(float prvalue, UBYTE ConvFlag)
{
	if(ConvFlag == 1){
		return Ms2ToS(prvalue);
	}
	else if(ConvFlag == 0){
		return SToMs2(prvalue);
	}
	else if(ConvFlag == 2){
		return SToFts2(prvalue);
	}
	else if(ConvFlag == 3){
		return Fts2ToS(prvalue);
	}
}
float SCurve_UnitConv(UWORD prx, float prvalue, UBYTE ConvFlag)
{
	if(ConvFlag == 1){
		switch(prx){
			case S4ACC1:
				return Ms3ToS(prvalue, pr[ACCEL1]);
				break;
			case S4ACC2:
				return Ms3ToS(prvalue, pr[ACCEL1]);
				break;
			case S4DEC1:
				return Ms3ToS(prvalue, pr[DECEL1]);
				break;
			case S4DEC2:
				return Ms3ToS(prvalue, pr[DECEL1]);
				break;
			case S4DEC3:
				return Ms3ToS(prvalue, pr[DECEL5]);
				break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            case SIBO_S3EMY:
                return Ms3ToS(prvalue, pr[SIBO_DECEMY]);
                break;
            case SIBO_S4EMY:
                return Ms3ToS(prvalue, pr[SIBO_DECEMY]);
                break;
#endif
			default:
				return prvalue;
				break;
		}
	}
	else if(ConvFlag == 0){
		switch(prx){
			case S4ACC1:
				return SToMs3(prvalue, pr[ACCEL1]);
				break;
			case S4ACC2:
				return SToMs3(prvalue, pr[ACCEL1]);
				break;
			case S4DEC1:
				return SToMs3(prvalue, pr[DECEL1]);
				break;
			case S4DEC2:
				return SToMs3(prvalue, pr[DECEL1]);
				break;
			case S4DEC3:
				return SToMs3(prvalue, pr[DECEL5]);
				break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            case SIBO_S3EMY:
                return SToMs3(prvalue, pr[SIBO_DECEMY]);
                break;
            case SIBO_S4EMY:
                return SToMs3(prvalue, pr[SIBO_DECEMY]);
                break;
#endif
			default:
				return prvalue;
				break;
		}
	}
	else if(ConvFlag == 2){
		switch(prx){
			case S4ACC1:
				return SToFts3(prvalue, pr[ACCEL1]);
				break;
			case S4ACC2:
				return SToFts3(prvalue, pr[ACCEL1]);
				break;
			case S4DEC1:
				return SToFts3(prvalue, pr[DECEL1]);
				break;
			case S4DEC2:
				return SToFts3(prvalue, pr[DECEL1]);
				break;
			case S4DEC3:
				return SToFts3(prvalue, pr[DECEL5]);
				break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            case SIBO_S3EMY:
                return SToFts3(prvalue, pr[SIBO_DECEMY]);
                break;
            case SIBO_S4EMY:
                return SToFts3(prvalue, pr[SIBO_DECEMY]);
                break;
#endif
			default:
				return prvalue;
				break;
		}
	}
	else if(ConvFlag == 3){
		switch(prx){
			case S4ACC1:
				return Fts3ToS(prvalue, pr[ACCEL1]);
				break;
			case S4ACC2:
				return Fts3ToS(prvalue, pr[ACCEL1]);
				break;
			case S4DEC1:
				return Fts3ToS(prvalue, pr[DECEL1]);
				break;
			case S4DEC2:
				return Fts3ToS(prvalue, pr[DECEL1]);
				break;
			case S4DEC3:
				return Fts3ToS(prvalue, pr[DECEL5]);
				break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            case SIBO_S3EMY:
                return Fts3ToS(prvalue, pr[SIBO_DECEMY]);
                break;
            case SIBO_S4EMY:
                return Fts3ToS(prvalue, pr[SIBO_DECEMY]);
                break;
#endif
			default:
				return prvalue;
				break;
		}
	}
}
/*--------------- [ Velocity Data Change, Add by DINO, 05/25/2009 ] ----------------
--  pr[UNITSEL] = 0: Hz
--              = 1: m/s : Hz2Metric()
--              = 2: ft/s: Hz2Ft()
----------------------------------------------------------------------------------*/
UWORD GetParData(UWORD uwParAdr)
{
    UWORD uwParData, uwAttr;
      
    uwAttr = attr[ uwParAdr ].ati ;

	if ((uwAttr&CHG) == CHG){
        if ((pr[UNITSEL] == 1) && (uwParAdr != Lift_SPD) && (uwParAdr != Max_MperS)){
            //[ //[Sibocom S curve, ACC unit,Jason,2019/10/01]
            if((     //((uwParAdr >= SIBO_ACCMID)&&(uwParAdr <= SIBO_DECMID))||
                     //((uwParAdr >= SIBO_ACCHIGH)&&(uwParAdr <= SIBO_DECHIGH))||
                     //((uwParAdr >= SIBO_ACCNOMINAL)&&(uwParAdr <= SIBO_DECNOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]                     
					 ((uwParAdr == SIBO_DECEMY))||
#endif
                     //((uwParAdr >= SIBO_ACCLEVEL)&&(uwParAdr <= SIBO_DECLEVEL))||
                     //((uwParAdr >= SIBO_ACCRELEVEL)&&(uwParAdr <= SIBO_DECRELEVEL))||
                     //((uwParAdr >= SIBO_ACCLOW)&&(uwParAdr <= SIBO_DECLOW))||
                     //((uwParAdr >= SIBO_ACCINS)&&(uwParAdr <= SIBO_DECINS))||
                     ((uwParAdr == ACCEL1)||(uwParAdr == DECEL1)|| 
                      (uwParAdr == ACCEL2)||(uwParAdr == DECEL2)|| 
                      (uwParAdr == ACCEL3)||(uwParAdr == DECEL3)|| 
                      (uwParAdr == ACCEL4)||(uwParAdr == DECEL4)|| 
                      (uwParAdr == JOGACC)||(uwParAdr == JOGDEC)||(uwParAdr == DECEL5)))
                && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
                if(pr[U_ACCDEC] == 0){
                    uwParData = ACC_UnitConv(pr[uwParAdr], 0);
                }
                else{
                    uwParData = ACC_UnitConv(pr[uwParAdr]/10, 0);
                }
            }
            else if((//((uwParAdr >= SIBO_S1MID)&&(uwParAdr <= SIBO_S4MID))||
                     //((uwParAdr >= SIBO_S1HIGH)&&(uwParAdr <= SIBO_S4HIGH))||
                     //((uwParAdr >= SIBO_S1NOMINAL)&&(uwParAdr <= SIBO_S4NOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]                     
					 ((uwParAdr >= SIBO_S3EMY)&&(uwParAdr <= SIBO_S4EMY))||
#endif                     
					 //((uwParAdr >= SIBO_S1LEVEL)&&(uwParAdr <= SIBO_S4LEVEL))||
                     //((uwParAdr >= SIBO_S1RELEVEL)&&(uwParAdr <= SIBO_S4RELEVEL))||
                     //((uwParAdr >= SIBO_S1LOW)&&(uwParAdr <= SIBO_S4LOW))||
                      (uwParAdr == S4ACC1) || (uwParAdr == S4ACC2) || 
                      (uwParAdr == S4DEC1)||(uwParAdr == S4DEC2) || (uwParAdr == S4DEC3))
                    && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
                    if(pr[U_ACCDEC] == 0){
                        uwParData = SCurve_UnitConv(uwParAdr, pr[uwParAdr], 0);
                    }
                    else{
                        uwParData = SCurve_UnitConv(uwParAdr, pr[uwParAdr]/10, 0);
                    }                   
            }
            else{
                uwParData = flHz2Metric(pr[uwParAdr]);  // Hz->m/s
            }               
        }
        else if(pr[UNITSEL] == 2){
            if ((uwParAdr == Lift_SPD) || (uwParAdr== Max_MperS)){  // m/s->ft/s
                /*-------------------------- [ 0.01m/s -> 0.01ft/s (Q12) ] --------------------------
                --  ft/s = (m/s) * 3.28
                --  3.28 = 13435 / 4096
                -----------------------------------------------------------------------------------*/
                uwParData = ((ULONG)pr[uwParAdr] * 13435 + 2048) >> 12;
            }
            else if((//((uwParAdr >= SIBO_ACCMID)&&(uwParAdr <= SIBO_DECMID))||
                     //((uwParAdr >= SIBO_ACCHIGH)&&(uwParAdr <= SIBO_DECHIGH))||
                     //((uwParAdr >= SIBO_ACCNOMINAL)&&(uwParAdr <= SIBO_DECNOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]                     
					 ((uwParAdr == SIBO_DECEMY))||
#endif
					 //((uwParAdr >= SIBO_ACCLEVEL)&&(uwParAdr <= SIBO_DECLEVEL))||
                     //((uwParAdr >= SIBO_ACCRELEVEL)&&(uwParAdr <= SIBO_DECRELEVEL))||
                     //((uwParAdr >= SIBO_ACCLOW)&&(uwParAdr <= SIBO_DECLOW))||
                     //((uwParAdr >= SIBO_ACCINS)&&(uwParAdr <= SIBO_DECINS))||
                     ((uwParAdr == ACCEL1)||(uwParAdr == DECEL1)|| 
                      (uwParAdr == ACCEL2)||(uwParAdr == DECEL2)|| 
                      (uwParAdr == ACCEL3)||(uwParAdr == DECEL3)|| 
                      (uwParAdr == ACCEL4)||(uwParAdr == DECEL4)|| 
                      (uwParAdr == JOGACC)||(uwParAdr == JOGDEC)||(uwParAdr == DECEL5)))
                    && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
                    if(pr[U_ACCDEC] == 0){
                        uwParData = ACC_UnitConv(pr[uwParAdr], 2);
                    }
                    else{
                        uwParData = ACC_UnitConv(pr[uwParAdr]/10, 2);
                    }
            }
            else if((//((uwParAdr >= SIBO_S1MID)&&(uwParAdr <= SIBO_S4MID))||
                     //((uwParAdr >= SIBO_S1HIGH)&&(uwParAdr <= SIBO_S4HIGH))||
                     //((uwParAdr >= SIBO_S1NOMINAL)&&(uwParAdr <= SIBO_S4NOMINAL))||
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]                     
					 ((uwParAdr >= SIBO_S3EMY)&&(uwParAdr <= SIBO_S4EMY))||
#endif                     
					 //((uwParAdr >= SIBO_S1LEVEL)&&(uwParAdr <= SIBO_S4LEVEL))||
                     //((uwParAdr >= SIBO_S1RELEVEL)&&(uwParAdr <= SIBO_S4RELEVEL))||
                     //((uwParAdr >= SIBO_S1LOW)&&(uwParAdr <= SIBO_S4LOW))||
                      (uwParAdr == S4ACC1) || (uwParAdr == S4ACC2) || 
                      (uwParAdr == S4DEC1)||(uwParAdr == S4DEC2) || (uwParAdr == S4DEC3))
                    && ((pr[SOFC]!=4)&&(pr[SOFC]!=5))){
                    if(pr[U_ACCDEC] == 0){
                        uwParData = SCurve_UnitConv(uwParAdr, pr[uwParAdr], 2);
                    }
                    else{
                        uwParData = SCurve_UnitConv(uwParAdr, pr[uwParAdr]/10, 2);
                    }
			}
			else{  // Hz->ft/s
				uwParData = Hz2Ft(pr[uwParAdr]);
			}
		}
		else{
			uwParData = pr[uwParAdr];
		}
	}
	else{
        uwParData = pr[uwParAdr];
	}

    return uwParData;
}






#ifdef _PrHandel_C
	#undef _PrHandel_C
#endif


/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
