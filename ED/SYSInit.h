/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _SYSInit_C
   #define SYSInit_EXT 
#else
   #define SYSInit_EXT extern
#endif

/* Function Call ==============================================*/
SYSInit_EXT void InitIO(void);
SYSInit_EXT void InitCMT0_500us(void);
SYSInit_EXT void InitCMT1_100us(void);
SYSInit_EXT void InitCMT2(void);	// 200us for USB routine, Sean, 2014/09/16
SYSInit_EXT void InitMTU21_PG1(void);
//SYSInit_EXT void InitMTU22_PG2(void);
SYSInit_EXT void InitMTU234_WG(void);
//SYSInit_EXT void InitMTU2S3_DFM(void);
//SYSInit_EXT void InitMTU2S4_AFM(void);
SYSInit_EXT void InitPOE2_PROTECT(void);
SYSInit_EXT void HW_Test(void);
SYSInit_EXT void HardwareSetup(void);
//SYSInit_EXT void InitAD0_AN2TH1(void);
//SYSInit_EXT void InitAD1_AN6TH2(void);
//SYSInit_EXT void InitAD2_AN8to11(void);

#if SH7286 //Sean, 01/25/2010
SYSInit_EXT void InitSCI0(void);
#else
SYSInit_EXT void InitSCI1(void);
#endif
SYSInit_EXT void InitSCI3(void);
SYSInit_EXT void InitSCI2(void);
//SYSInit_EXT void InitSCIF3(void);
SYSInit_EXT void IIC_Init(void);
SYSInit_EXT void InitWDT(void);
SYSInit_EXT void SYSCLK_Init(void);
SYSInit_EXT void InitDA(void);
SYSInit_EXT void InitLED_Keypad(void);
SYSInit_EXT void InitAFM(void);
SYSInit_EXT void InitCAN(void);
SYSInit_EXT void InitSCIERI(void);

SYSInit_EXT void Initial_Var(void);



/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
