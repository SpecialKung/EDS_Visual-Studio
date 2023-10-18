/* CPU Type Select */	//Sean, 01/25/2010
#define SH7286			1			// Function for SH7286, Sean, 01/25/2010

//#define	PG_SIM			1			// Simulation: PG signal, Sean, 06/21/2010
//#define	DR_SIM			1			// Simulation: Door Signal, Sean, 09/06/2010
#define FRAM_BUF		1			// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010  


#if 0
#define	SH7147		    1		    // Function for VL, dino, 03/05/2007
#define SH7149		    !SH7147		// Function for VE, dino, 03/05/2007
#endif

#define MTU2CLK         48000000/2  // 48MHz
#define TB1CLK_Hz	    1000		// 1K Hz (1ms)
#define TB2CLK_Hz	    10000		// 10K Hz (100us)
#define TB3CLK_Hz	    2000		// 2K Hz (500us)
#define CLK2ms_Hz       500

#define DeadTime        96         	//48MHz -> 20.8ns, DeatTime = 2us 
#define DeadTime_2      48         	//DeadTime / 2
#define DeadTime_3      144        	//DeadTime 3/2


#define PU06_EN         0
#define NEWPOE			1			// Setting for New POE circuit
#define ENDAT			1			// Set SCI1 for EnDat, dino, 10/12/2007
#define ACCESS_GROUP    1			// Function for ACCESS GROUP 12 and 13
#define COPYTEST		1
#define OLD_SETTING		0			// OLD Motor Parameter Setting Method, Delete by DINO, 09/09/2008
#define NEW_AD			0			// Shunt Resistor Current Sensing, Add by DINO, 10/09/2009
#define UVW_CAP			0			// U,V,W recieve by capture, DINO, 10/12/2009
#define	WithDTC			1			// SPI receive / transmit intterupt complete by DTC, DINO, 11/02/2009
#define NEWIEDCB		1			// New IED Control Board, DINO, 06/25/2010
#define VLI_RCAN		1           // [Can function, Bernie, 08/16/2011]



#define MFI_TqSpdSw     26
#define MFI_ASRSwitch   27
#define MFI_YCONFUN     29
#define MFI_DCONFUN     30
#define MFO_YCONFUN     31
#define MFO_DCONFUN     32
#define MFI_TQRDIR	    39
#define MFI_PG2MODE	    37
#define MFI_MC_IN	    41
#define MFI_BK_IN1		42  //[change for EN81-1+A3, Bernie, 2015/03/16]
#define MFI_BK_IN2		44  //[change for EN81-1+A3, Bernie, 2015/03/16]


#define MFO_STAR_CON    48


//#define MAXF			40000
#define MAXF			29900  //[modify <300Hz , Special.Kung, 2022/12/16]

//[ //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
#define EDS_DRIVER      1  
#define IEDS_DRIVER     2  

#define VL_VFDSOFT_ID   9
#define IED_VFDSOFT_ID  16
#define EDS_VFDSOFT_ID  17
#define IEDG_VFDSOFT_ID 18
#define DD_VFDSOFT_ID   19
#define IEDS_VFDSOFT_ID 36
//] //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]

//[ //[Language,Lyabryan,2022/08/28]
#define Language_EN   1
#define Language_TC   1
#define Language_SC   0
#define Language_TR   1
#define Language_RUS  1
//] //[Language,Lyabryan,2022/08/28]

/*Star Group power-on filter current center value and SSRY delay 300ms=>500ms*/
#define Def_uwRYCnt 500








//#define AFMCNT          1200

/*==========================================================================
  VDC = [(DCBUS * 0.2/20) - 1.5] * (10/7)
    when VDC = 5.0V, DCBUS should be 500Vdc in 220V model 
    and 1000Vdc in 440V model, so made the Voltage base value is (DCBUS/2)
    which mean the max phase voltage                                                                          */
#if 1
#define VB440V	        5000	//unit: 0.1V
#define VB220V	        2500	//unit: 0.1V
#else
#define VB440V	        4164	//unit: 0.1V, 510*sqrt(2/3)*10
#define VB220V	        2082	//unit: 0.1V, 255*sqrt(2/3)*10
#endif
/*========================================================================*/

#if 0 //Sean, 01/25/2010                  PORT2.PODR.BIT.B1
//------Hardware Protect Pin Define ----------------------------------------//
#define BRAKE_FAULT     PC.DR.BIT.B2   //DI,Braker Fault
#define FAN_LOCK        PC.DR.BIT.B3   //DI,Fan Lock
#define RST316J         PC.DR.BIT.B11  //DO,316J
#define FaultLED        PC.DR.BIT.B10  //DO,Fault LED
#else
#define BRAKE_FAULT     PORTE.PIDR.BIT.B0   //DI,Braker Fault
#define FAN_LOCK        PORT1.PIDR.BIT.B2   //DI,Fan Lock
#define RST316J         PORTB.PODR.BIT.B7   //DO,316J
#define FaultLED        PORTE.PODR.BIT.B4   //DO,Fault LED
#endif


#if 0
#define GFF_CHK         PD.PR.BIT.B17	//POE0			// POE redefine, Sean, 06/25/2010
#define OC_CHK          PD.PR.BIT.B18	//POE5 w/ POE0	// POE redefine, Sean, 06/25/2010
#define CC_CHK          PA.PR.BIT.B23	//POE6 w/ POE0	// POE redefine, Sean, 06/25/2010
#else
#define GFF_CHK         PORTE.PIDR.BIT.B2	//POE0
#define OC_CHK          PORTE.PIDR.BIT.B3	//POE5 w/ POE0	
#define CC_CHK          PORT7.PIDR.BIT.B0	//POE6 w/ POE0
#endif

#if 0
#define OCC_CHK         PB.PR.BIT.B6	//POE3
#define OV_CHK          PB.PR.BIT.B7	//POE4 	
#else
#define OCC_CHK         PORT9.PIDR.BIT.B6	//POE3
#define OV_CHK          PORTB.PIDR.BIT.B4	//POE4 

#endif

//------ IO Control Pin Define ---------------------------------------------//
#if 0 
#define FAN_SWITCH      PE.DR.BIT.B0	//TIOC0A
#define RelayOFF        PC.DR.BIT.B12   //SF RY,DO, control SW-Relay
#define GBP_ON          PC.DR.BIT.B9	//GBP, SW_Brake
#else
#define FAN_SWITCH      PORTA.PODR.BIT.B2	//TIOC0A
#define RelayOFF        PORT1.PODR.BIT.B3   //SF RY,DO, control SW-Relay
#define GBP_ON          PORT3.PODR.BIT.B1	//GBP, SW_Brake
#endif

//------ Communication Pin Define ------------------------------------------//
#if 0
#define SCI0_DIR		PA.DR.BIT.B2	//DIR0, Car Group Control, DINO, 08/19/2010
#define SCI1_DIR		PA.DR.BIT.B5	//DIR1, 
#define SCI2_DIR        PE.DR.BIT.B8	//DIR1, DINO, 03/23/2010
#define SCI3_DIR        PE.DR.BIT.B6	//DIR3, DINO, 03/01/2010
#define IDPU2           PC.DR.BIT.B1	//CKPD
#define SCI4_DIR		PD.DR.BIT.B20	//Change 1)UVW/ABZ 2)SIN/COS. Endat communicate w/ CPLD, Sean, 01/25/2010
#define SCI4_RxD        PD.DR.BIT.B22   //PG DO             //[PGABD function, Bernie, 10/13/2011]
#define SCI4_TxD        PD.DR.BIT.B21   //PG Clock          //[PGABD function, Bernie, 10/13/2011]
#else
//#define SCI12_DIR		PORT8.PODR.BIT.B2	//DIR0, For IO card //[New addition IO card,Lyabryan,2019/07/22]
//#define SCI0_DIR		PA.DR.BIT.B5	//DIR1, No used
#define SCI2_DIR        PORTG.PODR.BIT.B2	//DIR1, 
#define SCI3_DIR        PORTG.PODR.BIT.B5	//DIR3, 
#define IDPU2           PORTF.PODR.BIT.B0	//CKPD
#define SCI0_DIR		PORT3.PODR.BIT.B0	//Change 1)UVW/ABZ 2)SIN/COS. Endat communicate w/ CPLD, Sean, 01/25/2010
#define SCI0_RxD        PORT2.PODR.BIT.B2   //PG DO             //[PGABD function, Bernie, 10/13/2011]
#define SCI0_TxD        PORT2.PODR.BIT.B3   //PG Clock          //[PGABD function, Bernie, 10/13/2011]
#endif

//------ MFO ---------------------------------------------------------------//
#if 0 
#define DO_RLY1_PIN 	PB.DR.BIT.B15	//RA0
#define DO_RLY2_PIN 	PB.DR.BIT.B16	//RA1
#define DO_RLY3_PIN 	PA.DR.BIT.B10	//RA2
#define DO_RLY4_PIN 	PA.DR.BIT.B11	//RA3
#define DO_RLY5_PIN 	PA.DR.BIT.B12	//RA4
#define DO_RLY6_PIN 	PA.DR.BIT.B13	//RA5
#define DO_RLY7_PIN 	PA.DR.BIT.B14	//RA6
#define DO_RLY8_PIN 	PA.DR.BIT.B15	//RA7

#define DOE_RLY1_PIN 	PD.DR.BIT.B0	//RAE0
#define DOE_RLY2_PIN 	PD.DR.BIT.B1	//RAE1
#define DOE_RLY3_PIN 	PD.DR.BIT.B2 	//RAE2
#define DOE_RLY4_PIN 	PD.DR.BIT.B3 	//RAE3
#define DOE_RLY5_PIN 	PD.DR.BIT.B4 	//RAE4
#define DOE_RLY6_PIN 	PD.DR.BIT.B5 	//RAE5
#define DOE_RLY7_PIN 	PD.DR.BIT.B6 	//RAE6
#define DOE_RLY8_PIN 	PD.DR.BIT.B7 	//RAE7
#else
#define DO_RLY1_PIN 	PORTD.PODR.BIT.B2	//R1
#define DO_RLY2_PIN 	PORTD.PODR.BIT.B3	//R2
#define DO_RLY3_PIN 	PORTD.PODR.BIT.B4	//R3
#define DO_RLY4_PIN 	PORTD.PODR.BIT.B5	//R4
#define DO_RLY5_PIN 	PORTD.PODR.BIT.B6	//O1
#define DO_RLY6_PIN 	PORTD.PODR.BIT.B7	//O2
//[ //[New addition IO card,Lyabryan,2019/07/22]
#define DO_RLY7_PIN 	PORT8.PODR.BIT.B1	//O3
#define DO_RLY8_PIN 	PORT8.PODR.BIT.B2	//O4
#define DO_RLY9_PIN 	PORTF.PODR.BIT.B1	//O5
#define DO_RLY10_PIN 	PORT0.PODR.BIT.B1	//O6
//] //[New addition IO card,Lyabryan,2019/07/22]




#if 0
#define DOE_RLY1_PIN 	PORTF.PODR.BIT.B2	//RAE0
#define DOE_RLY2_PIN 	PORTF.PODR.BIT.B3	//RAE1
#define DOE_RLY3_PIN 	PORTD.PODR.BIT.B0 	//RAE2
#else
#define DRIVER_ID_PIN_RE1 	PORTF.PIDR.BIT.B2	//RAE0 //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
#define DRIVER_ID_PIN_RE2	PORTF.PIDR.BIT.B3	//RAE1 //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
#define DOE_RLY3_PIN 	PORTD.PODR.BIT.B0 	//RAE2
#endif
//#define DOE_RLY4_PIN 	PD.DR.BIT.B3 	//RAE3
//#define DOE_RLY5_PIN 	PD.DR.BIT.B4 	//RAE4
//#define DOE_RLY6_PIN 	PD.DR.BIT.B5 	//RAE5
//#define DOE_RLY7_PIN 	PD.DR.BIT.B6 	//RAE6
//#define DOE_RLY8_PIN 	PD.DR.BIT.B7 	//RAE7

#endif
//------ MFI ---------------------------------------------------------------//
#if 0
#define DI_FWD_PIN  	PA.DR.BIT.B22	//FWD
#define DI_REV_PIN  	PA.DR.BIT.B21	//REV
#define DI_1_PIN    	PD.DR.BIT.B8	//DI1
#define DI_2_PIN    	PD.DR.BIT.B9	//DI2
#define DI_3_PIN    	PD.DR.BIT.B10	//DI3
#define DI_4_PIN    	PD.DR.BIT.B11	//DI4
#define DI_5_PIN    	PD.DR.BIT.B12	//DI5
#define DI_6_PIN    	PD.DR.BIT.B13	//DI6
#define DI_7_PIN    	PD.DR.BIT.B14	//DI7
#define DI_8_PIN    	PD.DR.BIT.B15	//DI8
#else
#define DI_FWD_PIN  	PORTB.PIDR.BIT.B3	//FWD
#define DI_REV_PIN  	PORTB.PIDR.BIT.B2	//REV
#define DI_1_PIN    	PORTB.PIDR.BIT.B1	//DI1
#define DI_2_PIN    	PORTB.PIDR.BIT.B0	//DI2
#define DI_3_PIN    	PORTA.PIDR.BIT.B5	//DI3
#define DI_4_PIN    	PORTA.PIDR.BIT.B4	//DI4
#define DI_5_PIN    	PORTA.PIDR.BIT.B3	//DI5
#define DI_6_PIN    	PORTA.PIDR.BIT.B1	//DI6
#define DI_7_PIN    	PORTA.PIDR.BIT.B0	//DI7
#define DI_8_PIN    	PORTG.PIDR.BIT.B6	//DI8

#endif

//------ Safty Relay Pin Define --------------------------------------------// 

//#define SRY_A           PC.DR.BIT.B4	// Point A input  �\�ಾ��
//#define SRY_B           PC.DR.BIT.B5	// Point B input  �\�ಾ��
//#define SRY_C           PC.DR.BIT.B6	// Point C input  �\�ಾ��
//#define SRY_D           PC.DR.BIT.B7	// Point D input  �\�ಾ��
//#define SRY_T           PC.DR.BIT.B8	// Function test output  �\�ಾ��

//SH7286 Added pin, Sean, 01/25/2010
//------ Parrallel to Serial Input -----------------------------------------//
#if 0
#define PSDIA			PD.DR.BIT.B25	// Parallel to Serial Digital Input A			
#define PSDIB			PD.DR.BIT.B26	// Parallel to Serial Digital Input B
#define PSDIEA			PD.DR.BIT.B27	// Parallel to Serial Digital Input Extended A
#define PSDIEB			PD.DR.BIT.B28	// Parallel to Serial Digital Input Extended B
#define PSSELA			PD.DR.BIT.B29	// Parallel to Serial Select A
#define PSSELB			PD.DR.BIT.B30	// Parallel to Serial Select B
#define PSSELC			PD.DR.BIT.B31	// Parallel to Serial Select C
#else
#define PSDIEA			PORT0.PIDR.BIT.B1	// Parallel to Serial Digital Input Extended A
#define PSDIEB			PORTF.PIDR.BIT.B1	// Parallel to Serial Digital Input Extended B
#endif

//------ USB Enable --------------------------------------------------------//
//#define USBEN			PB.DR.BIT.B10	// USB Enable Pin  �\�ಾ��

//------ PG Status Pin -----------------------------------------------------//
#if 0
#define PG_RST 			PD.DR.BIT.B16	// PGABL Switch State, DINO, 09/06/2010
#define PG_LOSS			PD.DR.BIT.B23	// PG Loss Detect, AN11 originally
#define PGSEL   		PD.DR.BIT.B19	//PG_SEL: 1/0 => ABZ/UVW, DINO, 03/09/2010
#else
#define PG_RST 			PORTE.PIDR.BIT.B1	// PGABL Switch State, DINO, 09/06/2010
#define PG_LOSS			PORT6.PIDR.BIT.B5	// PG Loss Detect, AN11 originally
#define PGSEL   		PORT2.PODR.BIT.B4	//PG_SEL: 1/0 => ABZ/UVW, DINO, 03/09/2010
#endif

#if 0
#define HALL_LOSS		PB.DR.BIT.B17	// HALL Sensor Loss Detect, DINO, 06/28/2010
#else
#define HALL_LOSS		PORT6.PIDR.BIT.B4	// HALL Sensor Loss Detect, DINO, 06/28/2010

#endif

//------ Keypad Communication Pin-------------------------------------------//
#if 0
#define KEYCLK			PC.DR.BIT.B13	// Keypad Recive Clock
#define LEDDI			PB.DR.BIT.B1 	// Keypad Transmitter Data
#define LEDLCH			PC.DR.BIT.B15	// Keypad Chip Select
#define LEDCLK			PC.DR.BIT.B14	// Keypad Transmitter Clock
#define KEYDI			PB.DR.BIT.B0 	// Keypad Recive data
#else
#define KEYCLK			PORT9.PODR.BIT.B4	// Keypad Recive Clock
#define LEDDI			PORT3.PODR.BIT.B2 	// Keypad Transmitter Data
#define LEDLCH			PORT3.PODR.BIT.B3	// Keypad Chip Select
#define LEDCLK			PORT9.PODR.BIT.B3	// Keypad Transmitter Clock
#define KEYDI			PORT9.PIDR.BIT.B5	// Keypad Recive data
#endif

#if 0  //External Watchdog did't used in ED-s
//------ External Watchdog Timer Pin ---------------------------------------//
#define	EWDT_CLK		PB.DR.BIT.B11	// External Watchdog Timer Clock In	// Sean, 06/25/2010
#define	EWDT_EN			PB.DR.BIT.B12	// External Watchdog Timer Enable	// Sean, 06/25/2010
#endif

//================= Safety Function =================//
#define CC_S            PORTD.PODR.BIT.B1


//------------ Break detect status for UCMP -------------// 
#define UCMP            UCMP_STATUS.bit.b0         //[UCMP function, Bernie, 2016/06/14]






// SH7286 //Sean, 01/25/2010
#define CHIP93C86       1
#define CHIP93C66       !(CHIP93C86)

// 93c86 start-bit and Op code
#define WEN_CODE        0x80    // 100-xxxxxB //
#define READ_CODE       0xc0    // 110-xxxxxB //
#define WRITE_CODE      0xa0    // 101-xxxxxB //

//#define EI              set_imask(0)
//#define DI              set_imask(15)

//#define WGOFF           MTU2.TOER.BYTE = 0x00
//#define WGON            MTU2.TOER.BYTE = 0xFF
#define WGOFF           MTU.TOERA.BYTE = 0x00
#define WGON            MTU.TOERA.BYTE = 0xFF


#define phase30         5461    //  (30/360)*65536
#define phase60	    	10922   //  (60/360)*65536
#define phase90	    	16384   //  (90/360)*65536
#define phase120	    21845   // (120/360)*65536
#define phase180	    32768   // (180/360)*65536
#define phase240	    43690   // (240/360)*65536
#define phase300	    54613   // (300/360)*65536
#define phase360	    65535   // (360/360)*65536

#define Mfunc_p         0x7FFF

#define VF           	0x0000
#define VFPG      	    0x0001
#define SVC             0x0002
#define FOCPG      	    0x0003
#define TQCPG      	    0x0004
#define FOC      	    0x0005          //Reserved
#define TQC             0x0006          //Reserved
#define DBCSECA      	0x0007          //Dead Band Compensation SElf CAlibration
#define FOCPM		    0x0008			//ADDED 01/29/2007

/********************************************************/
/* AUTO TUNING METHOD DEFINATION    					*/
/********************************************************/
#define STOP_TUN        0x0000
#define DC_TEST         0x0001
#define HFSS_TEST       0x0002
#define ROTARY_TEST     0x0003
#define CAL_I0          0x0004
#define PGZ_DETECT	    0x0005		// ADDED BY SCOTTY 06/01/2007
#define PMLS_TEST	    0x0006		// ADDED BY SCOTTY 02/06/2007


#define TUN_NLRLPG      2000
#define TUN_NLRV1       (19661+TUN_NLRLPG)  //12/10
#define TUN_NLRV2       18022               //11/10
#define TUN_NLRV3       16384               //10/10
#define TUN_NLRV4       14746               // 9/10
#define TUN_NLRV5       13107               // 8/10
#define TUN_NLRV6       9830                // 6/10
#define TUN_NLRV7       (16384+TUN_NLRLPG)  //10/10

/********************************************************/
/* AUTO DBC SELF CALIBRATION STEP   					*/
/********************************************************/
#define DBC_IDLE0       0x0000
#define DBC_HiF_S1	    0x0001
#define DBC_IDLE1	    0x0002
#define DBC_HiF_S2	    0x0003
#define DBC_IDLE2	    0x0004
#define DBC_LoF_S1	    0x0005
#define DBC_IDLE3	    0x0006
#define DBC_LoF_S2	    0x0007
#define DBC_Calc	    0x0008
#define DBC_TUNE_OK     0x0009

#define VERRORLIMIT     4064    // 60Vdc, 127 adc * 32
#define IERRORLIMIT     3936	// 30% Rated Current 123 * 32

#define OH_LEVEL_IN     1000     // 100 C
#define OH_LEVEL_OUT    900      // 90 C
#define HS_OHLevel      650      // 90 C     //[OH2 level modify from 55 to 65, Lyabryan, 2015/12/17]

#define ACILOSSLEVEL    194		// 3.78mA

#define EXT_FWD         0x0001
#define EXT_REV         0x0002
#define EXT_FWDREV      0x0003
#define EXT_DI1         0x0004
#define EXT_DI2         0x0008
#define EXT_DI3         0x0010
#define EXT_DI4         0x0020
#define EXT_DI5         0x0040
#define EXT_DI6         0x0080
#define EXT_DI7         0x0100	// dino, 04/03/2007
#define EXT_DI8         0x0200  // dino, 04/03/2007

/********************************************************/
/* EMCODER CARD TYPE                  					*/
/********************************************************/
#define NOPGCARD		0x00
//#define PGABO			0x0001
//#define PGABL			0x0002
//#define PGH01			0x0003
//#define PGS01			0x0004
#define PGAB            0x01    //[Modify PG Type Define, Bernie, 12/05/2011]
#define PGABD           0x02    //[Modify PG Type Define, Bernie, 12/05/2011]
#define PGHSD           0x03    //[Modify PG Type Define, Bernie, 12/05/2011]

/********************************************************/
/* IO CARD TYPE                  						*/
/********************************************************/
#define NOIOCARD		0x0000
#define IO110V			0x0001
#define IOEXTIO			0x0002


/********************************************************/
/* EMCODER TYPE                     					*/
/********************************************************/
#define NOPG    		0x0000
#define ABZ_ONLY		0x0001	// Incremental ABZ
#define ABZ_UVW			0x0002	// Incremental ABZ    + Absolute UVW
#define SIN_SIN			0x0003	// Incremental SINCOS + Absolute SINCOS
#define SIN_ENDAT		0x0004	// Incremental SINCOS + Absoulte EnDat
#define SIN_ONLY		0x0005	// Incremental SINCOS
#define	SIN_HIPER		0x0006	// Incremental SINCOS + Absolute Hiperface

/********************************************************/
/* BEFORE RUN PROCEDURE                					*/
/********************************************************/
#define CHARGE_START	0
#define DIAG_UY1        1
#define DIAG_UY2        2
#define DIAG_VZ1        3
#define DIAG_VZ2        4
#define DIAG_WX1        5
#define DIAG_WX2        6
#define CHARGE_OFF		7



/* Protect Level constant */
/*======== AD scale ( dino, 03/07/2007 )====================================*/
//	    SH7149:10bit    SH7147:12bit		                                //
// ADMAX 	1024		    4096			                                //
// ADMAX_2	5120            2048                                            //
//==========================================================================//
#define	SH7147		    1		    // Function for VL, dino, 03/05/2007
#define SH7149		    !SH7147		// Function for VE, dino, 03/05/2007

#if (SH7147)	// dino, 03/07/2007
    #define  ADBit 12
#else
    #define  ADBit 10
#endif
#define ADMAX		    (1<<ADBit)
#define	ADMAX_2		    (ADMAX>>1)
/*======== DCBus calculate =================================================*/
// AD voltage = [DcBus * (1/20) * (3/15) - 1.5v] * (10/7)                   //
//     (Dcbus - 150v) * 5v /(500v - 150v)                                   //
//     0v     -> 150v Dcbus -> 0 adc                                        //
//     5v     -> 500v Dcbus -> 1023 adc                                     //
//     4.28v  -> 450v Dcbus -> 877  adc (Over Voltage)                      //
//     0.57v  -> 190v Dcbus -> 117  adc (Under Voltage)                     //
//==========================================================================//
#define STALL_VL        867         // 410 Vdc, stall v level

/*======== OC level calculate ==============================================//
// AD voltage => Isum = Asum = 1.67V~5V mapping to (Irate ~ 3Rate)          //
//      Irate                ->  1.67V   -> 341 adc                         //
//      CC level (2.2 Irate) ->  3.67V   -> 750 adc                         //
//      CC reset (1.8 Irate) ->  3V      -> 613 adc                         //
//      OC set (3 Irate)     ->  5V      -> 1023 adc                        //
//      OC set (2.7 Irate)   ->  4.5V    -> 920 adc                        //
//      OC reset (0.5 Irate) ->  0.835   -> 170 adc                         //
//==========================================================================*/
//#define OCS             1023        		// OC S/W level = 3 x rated current
//#define OCS             920         		// OC S/W level = 2.7 x rated current
//#define	OCR             170         	// OC Reset level  = 0.5 x rated current 
#define OCS             3686        		// OC S/W level = 2.7 x rated current, SH7147, dino 08/03/2010
#define	OCR             682         		// OC Reset level  = 0.5 x rated current, SH7147, dino 2007/01/29

//#define CCS             750         		// CC level = 2.2 x rated current WGOFF
//#define CCR             613         		// CC reset level = 1.8 x rated current WGON
#define CCS             3003         		// CC level = 2.2 x rated current WGOFF SH7147, dino 2007/01/29
#define CCR             2457  //2457     	// CC reset level = 1.8 x rated current WGON, SH7147, dino 2007/01/29

#define	GFFS		    3035			    // GFFAD S/W level, 60% rated current = 3.705Vad    //[Change the detection level of SW GFF, Bernie, 2016/05/17] 

#define	OH_H		    800
#define otq_level       400			        // Over-Torque level


#define	OLCOUNT		    (61500+2550)
#define	OL1COUNT	    (61500+2550)/600
#define OLCNT_C			3750000				// OL Count in CT
#define	OLCNT_V			937500				// OL Count in VT

#define VIH		        3604				// VIH.min = 5-0.6 = 4.4V = 3604 ad value
#define VIL		        328					// VIL.max = 0.4V = 328 ad value

#define F4CHWGM         1500                    // 15.00Hz for CHANGE WG MODE

#define C20MAX          (0x16+1)                	// MAX ITEM C20XX//2000H~2006H /���B�z??
#define C21MAX          (0x2b+1)                	// MAX ITEM C21XX//2100H~212bH
#define C22MAX          (0x2b+1)                	// MAX ITEM C22XX          //[for test adding maxmum value to 16, Bernie, 08/12/2011]
#define C23MAX          (0x09+1)                	// MAX ITEM C23XX//2300H~2309H
#define C24MAX          ((PRNAME_LEN+UNIT_LEN)/2) 	// MAX ITEM C24XX
#define CALIMAX         (0x20+1)                  	// MAX ITEM CFFXX
#define DESMAX          (0x09+1) 					// MAX ITEM Descript
#define C99MAX			(0x17+1)					// MAX ITEM C99XX//9900H~9917H
#define C40MAX	        (0x015E)                    //[DLC, Bernie, 2014/10/06]  
#if 0
#define DLCMAX           0x96   // JINGDO(0x63+1)  //                  //[DLC, Bernie, 2014/10/06]  
#else
#define DLCMAX           0x015E   
#endif
#define DLCFLOORMAX          0x4B     //4B=75F
#define DLC_25ADDR           0x0032   // 0~31  pr[1~50] [1fH~25fL] page0
#define DLC_50ADDR           0x0064   // 32~63 pr[51~100] [26fH~50fL] page1
#define DLC_75ADDR           0x0096   // 64~95 pr[101~150] [51fH~75fL] page2
#define DLC_LimADDR          0x00c8   // 96~c7 pr[151~200] [DDS1H~UDS4L] page3
#define DLC_Adj50ADDRUP      0x00fa   // c8~f9 pr[201~250] [1fUPoffset~50fUPoffset] page4
#define DLC_Adj50ADDRDN      0x012c   // fa~12b pr[250~300] [1fDNoffset~50fDNoffset] page5
#define DLC_Adj5175ADDRUPDN  0x015E   // 12c~15e pr[300~350] [51fUPoffset~75fDNoffset] page6




#define TX_LENGTH       200
#define RX_LENGTH       200
#define PRNAME_LEN      24
#define UNIT_LEN        4

//[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTT_Standby      0
#define BTT_StartTest    1
#define BTT_Testing      2
#define BTT_StopTest     3
#define BTT_ErrorHandle  4

#if PU06_EN
  #define STDISPMAX	    3
#else
  #define STDISPMAX     5
#endif

#define UPAGEMAX        6

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
#define MFDPAGEMAX      39
#else
#define MFDPAGEMAX      40
#endif

#define MAX(A,B)        (A > B) ? A : B
#define MIN(A,B)        (A < B) ? A : B

#define RUN             1
#define STOP            0

#define REVERSE         1
#define FORWARD         0

#define ACCON           1
#define DECON           0

#define END             1
#define ERR             0
// For NTC calculate, 04/20/2007, dino
#define CFRAME          0
#define DFRAME          1
#define EFRAME        	2

#define SFRMAX          36
#define ACCESS			11
#define GRUSER          13
#define GRENHANCE	    14            
#define GRALL           15

#define MAPGOURP		13

#define DATA_LEN        20      // 20 DATA WORDs, 40 data bytes
#define STX             0x3a    // start character ':'
#define CR_0D           0x0d    // end character, CR
#define LF_0A           0x0a    // end character, LF

#define PC_CE01         1 		// CE-01 - illegal command code //
#define PC_CE02         2 		// CE-02 - illegal data address //
#define PC_CE03         3 		// CE-03 - illegal data value //
#define PC_CE04         4 		// CE-04 - slave device failure //
#define PC_CE10         5		// CE-10 - time out
#define CP_CE10         6       // CP-10 - Keypad Time out
#define SE1_WARN        7		// Copy Failure
#define SE2_WARN        8		// Copy Fail 2, SE2
#define oH1_WARN        9       // Over Heat 1
#define oH2_WARN        10      // Over Heat 1
#define PID_WARN        11      // PID Loss Warning
#define ANL_WARN        12      // Analog loss
#define uC_WARN         13      // under Current 
#define AUE_WARN        14      // Auto Tun
#define PGFBK_WARN      15      // PG feedback Error
#define PGL_WARN        16      // PG loss (PG Open)
#define OSPD_WARN       17      // Over speed
#define DEVA_WARN       18      // Deviation warning
#define PHL_WARN        19      // Phase Loss
#define OT1_WARN        20      // Over Torque 1 warning
#define OT2_WARN        21      // Over Torque 2 warning
#define oH3_WARN        22      // oH3 warning (PTC)
#define CC_WARN         23      // CC warning
#define oSL_WARN	    24		// Over Slip Warning
#define tUn_WARN	    25		// Auto Tuning message
#define Fan_WARN		26		// FanLock warning
#define CANOFF_WARN		27		// CAN bus off Warning  //[CAN Control, Sampo, 09/15/2010]
#define STO_WARN        28      // Safe Torque Off Warning code  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
#define UCMP_WARN       29      // UCMP Warning     //[UCMP function, Bernie, 2016/06/14]
#define SE3_WARN        30      // SE3 Warn         //[Add SE3 Warn]
#define SERVICE_WARN    31      //[Running Dir Count,Special,2018/08/17]
#define DLCDIR_WARN     32      //Artemis DLC Reverse direction command Issue, James, 2020/01/16
#define UD1_Vlim_WARN   33      //Artemis speed limit, James, 20200220
#define UD2_Vlim_WARN   34      //Artemis speed limit, James, 20200220
#define UD3_Vlim_WARN   35      //Artemis speed limit, James, 20200220
#define UD4_Vlim_WARN   36      //Artemis speed limit, James, 20200220
#define DD1_Vlim_WARN   37      //Artemis speed limit, James, 20200220
#define DD2_Vlim_WARN   38      //Artemis speed limit, James, 20200220
#define DD3_Vlim_WARN   39      //Artemis speed limit, James, 20200220
#define DD4_Vlim_WARN   40      //Artemis speed limit, James, 20200220
#define FWDREV_WARN     41		//[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
#define SOS_WARN     	42		//[Sibocom SOS Warn, James, 2020/04/28]
#define LULD_WARN     	43		//#15977, LULD detect, James, 2021/04/01
#define STOb_WARN       44      //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
#define STOc_WARN       45     
#define Sensor817_WARN  46      //[Artemis Add Sensor819 Function/Special/2022/06/06]
#define Sensor818_WARN  47      //[Artemis Add Sensor819 Function/Special/2022/06/06]
#define BTT1_WARN     	48		//BTTx Testing [JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTT2_WARN     	49		//BTTx Normal  [JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTT3_WARN     	50		//BTTx Success [JES Torq Detect Function, Special.Kung, 2022/09/01]
#define WARNMAX         51	
//-------------------Error code----------------------
// Driver occur serious fault, then driver stop operation.
// User must press RESET to restart driver.
//--------------------------------------------------------
#define ocA_ERR         1       //OC when Acceleration
#define ocd_ERR         2       //OC when Deceleration
#define ocn_ERR         3       //OC on normal speed
#define GFF_ERR         4       //Ground Fault
#define occ_ERR         5       //short circuit
#define ocS_ERR         6       //OC when STOP
#define ovA_ERR         7       //ov when Acceleration
#define ovd_ERR         8       //ov when Deceleration
#define ovn_ERR         9       //ov on normal speed
#define ovS_ERR         10      //ov when STOP
#define LvA_ERR         11      //Lv when Acceleration
#define Lvd_ERR         12      //Lv when Deceleration
#define Lvn_ERR         13      //Lv on normal speed
#define LvS_ERR         14      //Lv when STOP
#define PHL_ERR         15      //Phase Lack
#define oH1_ERR         16      //IGBT
#define oH2_ERR         17      //40HP above
#define tH1o_ERR        18      //TH1 open
#define tH2o_ERR        19      //TH2 open
#define Fan_ERR         20      //Fan Lock
#define oL_ERR          21      //150% 1Min, Inverter
#define EoL1_ERR        22      //Thermal Relay (Motor1)
#define EoL2_ERR        23      //Thermal Relay (Motor2)
#define oH3_ERR         24      //PTC
#define FuSE_ERR        25      //Fuse Error
#define ot1_ERR         26      //Over Torque level 1
#define ot2_ERR         27      //Over Torque level 2
#define uc1_ERR         28      //Under Torque level 1
#define uc2_ERR         29      //Under Torque level 2
#define cF1_ERR         30      //EEPROM write Error
#define cF2_ERR         31      //EEPROM read Error
#define cd0_ERR         32      //Isum AD channel Error
#define cd1_ERR         33      //U-phase AD channel Error
#define cd2_ERR         34      //V-phase AD channel Error
#define cd3_ERR         35      //W-phase AD channel Error
#define Hd0_ERR         36      //cc hardward Error
#define Hd1_ERR         37      //oc Hardward Error
#define Hd2_ERR         38      //ov Hardward Error
#define Hd3_ERR         39      //GFF Hardward Error
#define AuE_ERR         40      //Auto Tuning Error
#define AFE_ERR         41      //PID Feedback Error
#define PGF1_ERR        42      //PG fbk Error
#define PGF2_ERR        43      //PG fbk loss
#define PGF3_ERR        44      //PG fbk Over speed
#define PGF4_ERR        45      //PG fbk deviation Error
#define PGr1_ERR        46      //PG Ref Error
#define PGr2_ERR        47      //PG Ref Loss
#define ACE_ERR         48      //ACI Loss
#define EF_ERR          49      //External Fault
#define EF1_ERR         50      //External Fault 1
#define bb_ERR          51      //Base Block
#define PcodE_ERR       52      //Password
#define ccodE_ERR       53      //SW
#define cE1_ERR         54      //PC Communication Error (illegal command code)
#define cE2_ERR         55      //PC Communication Error (illegal data address)
#define cE3_ERR         56      //PC Communication Error (illegal data value)
#define cE4_ERR         57      //PC Communication Error (Slave device failure)
#define cE10_ERR        58      //PC Communication Error (Time Out)
#define cP10_ERR        59      //PU Communication Error (Time Out)
#define bF_ERR          60      //Braking Transistor Fault
#define ydc_ERR         61      //Y-Delta connected Error
#define DEB_ERR         62      // DEB Error
#define SRY_ERR         63      //Safety relay Error, add by dino, 06/06/2007
#define MbF_ERR			64		//Mechanical brake failed
#define PGF5_ERR		65		//PG Hardware Error
#define MCF_ERR			66		//Magnetic Contactor Failed
#define MPHL_ERR		67		//Motor Phase Loss Failed , added by Sampo , 05/12/2009
#define CAN_ERR		    68      //CANbus OFF Failed, //[CAN Control, Sampo, 09/15/2010]
#define OVERACC_ERR     71      // Over Acceleration            //[Over Acceleration protection function, Bernie, 2017/02/13]
#define STOL1_ERR       72      //STOL1 Error
#define PGcd_ERR        73      //mask by Lyabryan
#define PGHL_ERR        74      //[modify Error code,Lyabryan,2016/07/21]
#define PGAF_ERR        75      //[modify Error code,Lyabryan,2016/07/21]
#define STOL_ERR        76      //STOL Error  //[modify STO function, Bernie, 2014/11/24]
#define STOL2_ERR       77      //STOL2 Error
#define STOL3_ERR       78      //STOL3 Error
#define SERVICE_ERR     81      // Service time function
#define OPHLU_ERR       82      
#define OPHLV_ERR       83
#define OPHLW_ERR       84
#define DLC_ERR         85
#define LULD_SHORT_ERR  86		//#15977, LULD detect, James, 2021/04/01
#define LULD_OPEN_ERR   87		//#15977, LULD detect, James, 2021/04/01
#define CurCtrl_ERR     88
#define STOL4_ERR       89      //#12225,STOL4 Short Error, power on to reset
#define STOr_ERR        90      //#12225,STO error at running 
#define STOS_ERR        91      //#12225,STO Short error  
#define Sensor817_ERR   92      //[Artemis Add Sensor819 Function/Special/2022/06/06]
#define Sensor818_ERR   93      //[Artemis Add Sensor819 Function/Special/2022/06/06]
#define BTT1_ERR        94      //BTT Test Fail [JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTT2_ERR        95      //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTT3_ERR        96      //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
#define GFCAFE_ERR    	97		//[AFE Error Handle/Lyabryan/2022/03/24]
#define ERRMAX          98

#define CPU_ERR_ILL     0x81
#define CPU_ERR_SORT    0x82
#define CPU_ERR_ADDR    0x83
#define CPU_ERR_DTC     0x84

// frame E oH2 update, Sean, 11/24/2010
#define	CAP2K_DEG_N30		4007
#define	CAP2K_DEG_N25		3977
#define	CAP2K_DEG_N15		3888
#define	CAP2K_DEG_0		    3656
#define	CAP2K_DEG_15		3270
#define	CAP2K_DEG_25		2925
#define	CAP2K_DEG_35		2529
#define	CAP2K_DEG_40		2321
#define	CAP2K_DEG_41		2279
#define	CAP2K_DEG_42		2238
#define	CAP2K_DEG_43		2196
#define	CAP2K_DEG_44		2155
#define	CAP2K_DEG_45		2113
#define	CAP2K_DEG_46		2072
#define	CAP2K_DEG_47		2031
#define	CAP2K_DEG_48		1991
#define	CAP2K_DEG_49		1950
#define	CAP2K_DEG_50		1910
#define	CAP2K_DEG_51		1870
#define	CAP2K_DEG_52		1831
#define	CAP2K_DEG_53		1791
#define	CAP2K_DEG_54		1753
#define	CAP2K_DEG_55		1714
#define	CAP2K_DEG_56		1677
#define	CAP2K_DEG_57		1639
#define	CAP2K_DEG_58		1602
#define	CAP2K_DEG_59		1566
#define	CAP2K_DEG_60		1530
#define	CAP2K_DEG_61		1494
#define	CAP2K_DEG_62		1459
#define	CAP2K_DEG_63		1425
#define	CAP2K_DEG_64		1391
#define	CAP2K_DEG_65		1358
#define	CAP2K_DEG_66		1325
#define	CAP2K_DEG_67		1293
#define	CAP2K_DEG_68		1262
#define	CAP2K_DEG_69		1231
#define	CAP2K_DEG_70		1200
#define	CAP2K_DEG_71		1171
#define	CAP2K_DEG_72		1142
#define	CAP2K_DEG_73		1113
#define	CAP2K_DEG_74		1085
#define	CAP2K_DEG_75		1058
#define	CAP2K_DEG_76		1031
#define	CAP2K_DEG_77		1005
#define	CAP2K_DEG_78		979
#define	CAP2K_DEG_79		954
#define	CAP2K_DEG_80		929
#define	CAP2K_DEG_81		905
#define	CAP2K_DEG_82		882
#define	CAP2K_DEG_83		859
#define	CAP2K_DEG_84		837
#define	CAP2K_DEG_85		815
#define	CAP2K_DEG_86		794
#define	CAP2K_DEG_87		773
#define	CAP2K_DEG_88		753
#define	CAP2K_DEG_89		733
#define	CAP2K_DEG_90		714
#define	CAP2K_DEG_91		695
#define	CAP2K_DEG_92		677
#define	CAP2K_DEG_93		659
#define	CAP2K_DEG_94		642
#define	CAP2K_DEG_95		625
#define	CAP2K_DEG_96		609
#define	CAP2K_DEG_97		593
#define	CAP2K_DEG_98		577
#define	CAP2K_DEG_99		562
#define	CAP2K_DEG_100		547
#define	CAP2K_DEG_101		533
#define	CAP2K_DEG_102		519
#define	CAP2K_DEG_103		505
#define	CAP2K_DEG_104		492
#define	CAP2K_DEG_105		479
#define	CAP2K_DEG_106		466
#define	CAP2K_DEG_107		454
#define	CAP2K_DEG_108		442
#define	CAP2K_DEG_109		431
#define	CAP2K_DEG_110		420
#define	CAP2K_DEG_130		250
#define	CAP2K_DEG_150		153

/*---------------------------------------------------------------------------*/
//---------[ Keypad display page definition ]---------------------------------
#define F_PAGE          0       // F command, same as remote keypad dispaly
#define H_PAGE          1       // H command, same as remote keypad dispaly
#define U_PAGE          2       // Dcbus Display                                 
#define A_PAGE          3       // Current Display               
#define E_PAGE          4       // Output Voltage Display                  
#define USER_PAGE       5       // User Definitation Display
#define DebugPAGE       6       // Debug page display when pr[PRRESET] = 2

#define WarnPAGE        7       // Warnning page display
#define ErrPAGE         8       // Error page display
/*---------------------------------------------------------------------------*/


#define STANDBY         inv_status.bit.b0  // INVERTER STATUS
#define ACCODEC         inv_status.bit.b1  // ACCEL, DECEL STATUS
#define RUNNING         inv_status.bit.b2  // RUNNING STATUS
#define NORMALSP        inv_status.bit.b3  // NORMAL SPEED
#define AVREN           inv_status.bit.b4  // AVR enable flag
#define ZEROSP          inv_status.bit.b5  // Zero speed flag enable
#define ZEROST          inv_status.bit.b6  // Zero speed start
#define DCBUSREC        inv_status.bit.b7  // Record DCbus value before RUN

#define JOG_DIR         inv1_status.bit.b0 // Operation Command source 0:First/ 1:Second
#define ADGROUP_SEL     inv1_status.bit.b1 // AD group selection
#define T_DERATING      inv1_status.bit.b2 // heatsink temp. up ->derating ->down carry freq
#define CCSET           inv1_status.bit.b3 // H/W CC ON
//#define AD0CHSEL        inv1_status.bit.b4 // AD0 Channel Selection Flag
#define OL_DEARTING     inv1_status.bit.b4 // Overload Derating Flag, Add by DINO, 10/20/2008
#define YCONNECTOK      inv1_status.bit.b5 // Check Y-connected OK
#define DCONNECTOK      inv1_status.bit.b6 // Check Delta-connected OK
#define YDWGON          inv1_status.bit.b7 // WGON flag when Y-D changed

#define RTH_IN          inv2_status.bit.b0  // RTH_IN=1, Rth Inside
#define YDConnectFlag   inv2_status.bit.b1  // Y-Delta Connected flag 0:Y; 1:D
#define BRK_RLS         inv2_status.bit.b2  // Braker Release
#define TRGST           inv2_status.bit.b3  // TRG Start
#define MFO_YCON        inv2_status.bit.b4  // MFO to control Y-Connected
#define MFO_DCON        inv2_status.bit.b5  // MFO to control Delta-Connected
#define ACI_EF          inv2_status.bit.b6  // ACI LOSS E.F
#define ACI_LOSS        inv2_status.bit.b7  // ACI LOSS E.F

#define BRK_RLS2        inv3_status.bit.b0  // Braker Release 2      // DIN function
#define AUI_TUNE        inv3_status.bit.b1  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08] // Braker Release 2      // DIN function
#define AUI_TUNE_FINISH inv3_status.bit.b2  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
#define ICTDetectGBP    inv3_status.bit.b3  //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023

/*---------- mfi0 status ------*/
#define MFI_CHG         mfi0_status.bit.b0  // Multi_Function_Input status change //
#define MFI_BB          mfi0_status.bit.b1  // BB
#define MFI_UP          mfi0_status.bit.b2  // ext up freq command //
#define MFI_DOWN        mfi0_status.bit.b3  // ext down freq command //
#define MFI_PIDDIS      mfi0_status.bit.b4  // PID disable
#define MFI_REMOTE      mfi0_status.bit.b5  // MFI speed Remote
#define MFI_WG          mfi0_status.bit.b6  // Output OFF
#define MFI_AAADDIS     mfi0_status.bit.b7  // Disable Auto Accel/Decel
/*---------- mfi1 status ------*/
#define HOLD            mfi1_status.bit.b0  // Hold Speed
#define EXTUPDN         mfi1_status.bit.b1  // EXT Up Down Key (1:Up/Down 0:Hold)
#define MFI_AVI         mfi1_status.bit.b2  // FREQ. command source AVI
#define MFI_ACI         mfi1_status.bit.b3  // FREQ. command source ACI
#define MFI_AUI         mfi1_status.bit.b4  // FREQ. command source AUI
#define TRGEN           mfi1_status.bit.b5  // TRG Enable
#define TRGRST          mfi1_status.bit.b6  // TRG Reset
#define MFI_APRbyVcom   mfi1_status.bit.b7
/*---------- mfi2 status ------*/
#define MFI_BRKCHK1      mfi2_status.bit.b0  // Mechanical brake checking state 1         //[change for EN81-1+A3, Bernie, 2015/03/16]
#define MFI_MCCHK		 mfi2_status.bit.b1  // Magnetic Contactor checking state
#define MFI_BRKCHK2      mfi2_status.bit.b2  // Mechanical brake checking state 2         //[change for EN81-1+A3, Bernie, 2015/03/16]
#define MFI_btSensor819_Button mfi2_status.bit.b3  // 819 Switch				//[Artemis Add top and ground floor Switch Function/Special/2022/06/06]
#define MFI_btSensor819_Top    mfi2_status.bit.b4  // 819 Switch				//[Artemis Add top and ground floor Switch Function/Special/2022/06/06]
#define MFI_btSensor819_Both   mfi2_status.bit.b5

/*--------external di status ------*/
#define EXT_EF          ext_status.bit.b0   // E.F
#define EXT_EF1         ext_status.bit.b1   // EF1
#define EXT_TQCDIR	    ext_status.bit.b2   // direction of Torque command
#define EF_AUTO         ext_status.bit.b3   // Emergercy stop by automatic deceleration
#define EXT_JOG         ext_status.bit.b4   // External JOG Command
#define EXT_SPD2POS	    ext_status.bit.b5   // MI speed/MI position
#define EXT_PG2REFMODE	ext_status.bit.b6   // PG2 Ref mode
#define EXT_MOTOR1to2   ext_status.bit.b7   // Motor 1 change to Motor 2

#define EXT_ASR1to2     ext1_status.bit.b0  // ASR1 to ASR 2
#define EXT_PWRONRUN	ext1_status.bit.b1  // Power on Run
#define EXT_FORCESTOP 	ext1_status.bit.b2  // Force STOP
#define EXT_COASTSTOP	ext1_status.bit.b3  // Coast STOP
#define EXT_PcomCLK	    ext1_status.bit.b4  // SPI Position Command CLK 
#define EXT_PcomData	ext1_status.bit.b5  // SPI Position Command data
#define EXT_SPIPcomGO	ext1_status.bit.b6  // SPI Position Enable 
#define EXT_ASREN   	ext1_status.bit.b7  // external ASR switch enable
 
#define EXT_ASROld   	ext2_status.bit.b0  // external ASR old state 
#define EXT_TQRDIRSET   ext2_status.bit.b1	// TQR Direction Control
#define AUIChangeFlag	ext2_status.bit.b2  // AUI change to fine tuning
#define BLK_WRITE       ext2_status.bit.b3  // BLK Transfer Write
#define VPHOLD		    ext2_status.bit.b4  // Vcom position, speed HOLD
#define EXT_PG2MODE     ext2_status.bit.b5  // PG2 mode change setting
#define EXT_TqSpdEN 	ext2_status.bit.b6  // external Tq or Spd switch enable
#define EXT_ENABLE  	ext2_status.bit.b7  // external RUN enable

#define CAN_ENABLE  	ext3_status.bit.b0  // CAN RUN enable  //[CAN Control, Sampo, 09/15/2010]
#define CAN_RWERR  	    ext3_status.bit.b1  // CAN R/W ERROR   //[CAN Control, Sampo, 09/15/2010]
#define CAN_RXOK        ext3_status.bit.b2  // CAN Rx accomplish  //[CAN Control, Sampo, 09/15/2010]
#define CAN_DECODEING   ext3_status.bit.b3  // CAN Rx DECODERING //[CAN Control, Sampo, 09/15/2010]

/*---------- BTTx status -------*/
#define MFO_btTorqDetect    BTTx_status.bit.b0	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define MFI_btTorqDetect    BTTx_status.bit.b1	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTTx_btPr0732Flag   BTTx_status.bit.b2	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTTx_btTorqDetect   BTTx_status.bit.b3	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#define BTTx_btFWDREVReset  BTTx_status.bit.b4	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]

/*------ warn STATUS -----*/
#define WARNOL2         warn_status.bit.b0  // Warning flag: OL2
#define WARNPID         warn_status.bit.b1  // Warning flag: PID Feedback Error
#define WARNPGLOSS      warn_status.bit.b2  // Warning flag: Encoder loss
#define WARNPGERR       warn_status.bit.b3  // Warning flag: Encoder quadrature error
#define WARNCE          warn_status.bit.b4  // Warning flag: Communication Error
#define WARNSTOP        warn_status.bit.b5  // Warning flag: Warn to STOP
#define WARNOH          warn_status.bit.b6  // Warning flag: OverHeat
#define WARN_PAGE       warn_status.bit.b7  // Switch to warn page flag

/*------ error STATUS -----*/
#define CHKAMPS         err_status.bit.b0	// check amps if below OCR
#define PIDDEVF         err_status.bit.b1	// PID deviation flag
#define COM_BB          err_status.bit.b2   // Comm bb
#define ERR_MO			err_status.bit.b3	// Error Delay Output flag, Add by DINO, 10/24/2008
#define MODELCHG        err_status.bit.b4	// Model Change Flag
#define STALL_TY        err_status.bit.b5	// STALL TYPE
#define PWRON			err_status.bit.b6	// Power ON Flag, add by DINO, 12/01/2008
#define REGEN           err_status.bit.b7	// RE-GENERATION
#define PHLACTIVE       err_status.bit.b8	// PHL active flag
#define WARNSTOPREC     err_status.bit.b9	// recording flag of Warning stop	09/05/2007
#define LVMOD			err_status.bit.b10	// LV Treatment, 0:Error/1:Warn
#define FANLOCKMOD		err_status.bit.b11	// FanLock Treatment, 0:Error/1:Warn
#define PWRON_IF		err_status.bit.b12	//[SERV READ ONLY,Lyabryan,2018/08/17]

//---------- UART1 comm. status --------*/	
#define ASC_RTU1        com1_status.bit.b0  // ASC(0)/RTU(1) mode
#define RTU_RXF1        com1_status.bit.b1  // RTU Receiving Flag
#define RX_OK1          com1_status.bit.b2  // Receice OK
#define NO_ECHO1        com1_status.bit.b3  //
#define ADDR_MATCH1     com1_status.bit.b4  //
#define TXD_RTS1        com1_status.bit.b5  // Ready to Send
//---------- UART3 comm. status --------*/

#define ASC_RTU2        com2_status.bit.b0  // ASC(0)/RTU(1) mode
#define RTU_RXF2        com2_status.bit.b1  // RTU Receiving Flag
#define RX_OK2          com2_status.bit.b2  // Receice OK
#define NO_ECHO2        com2_status.bit.b3  //
#define ADDR_MATCH2     com2_status.bit.b4  //
#define TXD_RTS2        com2_status.bit.b5  // Ready to Send
#define TXD_TDFE		com2_status.bit.b6	// Transmit FIFO Data Empty, DINO, 03/02/2010


//---------- UART3 comm. status --------*/
#define ASC_RTU3        com3_status.bit.b0  // ASC(0)/RTU(1) mode
#define RTU_RXF3        com3_status.bit.b1  // RTU Receiving Flag
#define RX_OK3          com3_status.bit.b2  // Receice OK
#define NO_ECHO3        com3_status.bit.b3  //
#define ADDR_MATCH3     com3_status.bit.b4  //
#define TXD_RTS3        com3_status.bit.b5  // Ready to Send

//---------- UART0 comm. status --------//	// For PG card RX63TH, Bernie
#define ASC_RTU0        com0_status.bit.b0  // ASC(0)/RTU(1) mode
#define RTU_RXF0        com0_status.bit.b1  // RTU Receiving Flag
#define RX_OK0          com0_status.bit.b2  // Receice OK
#define NO_ECHO0        com0_status.bit.b3  //
#define ADDR_MATCH0     com0_status.bit.b4  //
#define TXD_RTS0        com0_status.bit.b5  // Ready to Send

//---------- Keypad status ------------*/
#define COPYEN          copy_status.bit.b0 	// COPY Enable
#define COPYFAIL        copy_status.bit.b1
#define COPYOK          copy_status.bit.b2
#define LCDTEXT         copy_status.bit.b3 	// provide LCD data discription
#define CopyChk         copy_status.bit.b4
#define LCDKEY          copy_status.bit.b5	// LCD:1 or LED:0 keypad
#define COPYFLAG        copy_status.bit.b6	// 0:Keypad Copy  1:VfdSoft Copy  //[JES SE1_ERR, Rational 282940, Special.Kung, 2022/08/24]

//---------- Lock status --------------*/
#define PRLOCK          lock_status.bit.b0
#define OPKEY_LOCK      lock_status.bit.b1
#define FSET_LOCK       lock_status.bit.b2
#define PASSWDUNCLOCK   lock_status.bit.b3

/*------ KEY STATUS ------*/
#define KEYPRESS        key_status.bit.b0   // key press status
#define KEYEND          key_status.bit.b1   // key Attribute -End- or -Err-
#define KEYLKPR         key_status.bit.b2   // 
#define KEY2FM          key_status.bit.b3   // key UP/DOWN for change to setpoint dispmode
#define KEYRESET        key_status.bit.b4   // reset key enable ?
#define KEYRPT          key_status.bit.b5   // key repeat 0
#define FSET            key_status.bit.b6
#define KEYPAD_CMD      key_status.bit.b7   // Command from keypad
#define PR_LOCK         key_status.bit.b8	// Parameter Lock by Pr00-08
#define KEY_10x         key_status.bit.b9	// key press * 10
#define KEY_50x			key_status.bit.b10	// key press * 20
#define COPYRIGHT       key_status.bit.b11	//

#define PUEN3           kpd1_status.bit.b0  // PU Enable
#define KEYLOCK3        kpd1_status.bit.b1  // KEYPAD LOCKED
#define PAGECHG3        kpd1_status.bit.b2  // Page change
#define PIDSPNT3        kpd1_status.bit.b3  // PID SETPOINT
#define UPCR3           kpd1_status.bit.b4  //
#define PUON3LINE       kpd1_status.bit.b5  // PU On Line
#define PUON3           kpd1_status.bit.b6  // PU On status
#define KEYRELEASE3     kpd1_status.bit.b7  // Keypad release

#define PUEN2           kpd3_status.bit.b0  // PU Enable
#define KEYLOCK2        kpd3_status.bit.b1  // KEYPAD LOCKED
#define PAGECHG2        kpd3_status.bit.b2  // Page change
#define PIDSPNT2        kpd3_status.bit.b3  // PID SETPOINT
#define UPCR2           kpd3_status.bit.b4  //
#define PUON2LINE       kpd3_status.bit.b5  // PU On Line
#define PUON2           kpd3_status.bit.b6  // PU On status
#define KEYRELEASE2     kpd3_status.bit.b7  // Keypad release

/*------ LED STATUS ------*/
#define LED4NOTE        led_status.bit.b0   // led.s4 for note
#define LEDBLINK        led_status.bit.b1   // led blink
#define PRUPDATE        led_status.bit.b2   // parameter update
#define ERR_LOG         led_status.bit.b3   // fault record complete flag inv1_status.bit.b3  // H/W CC ON
#define WRINFO          led_status.bit.b4   // Write some infomation into EPROM.
#define PRERROR         led_status.bit.b5   // Parameter value Error
#define WARN_LOG        led_status.bit.b6   // warning record complete flag 
#define SHOW_ALLPR      led_status.bit.b7

//Command status
#define CMDRUN    	    cmd_status.bit.b0   //run command status
#define CMDJOG    	    cmd_status.bit.b1   //jog command status
#define CMDDIR    	    cmd_status.bit.b2   //direction command status
#define CMDFREE   	    cmd_status.bit.b3   //Free RUN 
#define RUNDCI    	    cmd_status.bit.b4   //RUN DC injection
#define STOPDCI   	    cmd_status.bit.b5   //STOP DC injection
#define FcmdOverFlag    cmd_status.bit.b6   //Fcmd over 16384, the flag = 1
#define SHOW_ENHANCE	cmd_status.bit.b7   //Show Enhance parameter
#define INIT_USER       cmd_status.bit.b8   // for user define page display
#define FREM_ON         cmd_status.bit.b9   // for keypad control freq source
#define FACTORY         cmd_status.bit.b10  // for Factory Parameter Reset
#define RUNDCI2         cmd_status.bit.b11  //
#define CHKCPR          cmd_status.bit.b12  //
#define YSETOK          cmd_status.bit.b13  // Y-Connected setting OK
#define DSETOK          cmd_status.bit.b14  // D-Connceted setting OK
#define CMDDIR2         cmd_status.bit.b15  // direction command status 2

//--------  Direction status -----------
#define PUID2           dir_status.bit.b0   // flag of PU06 PnP, 0:PU06 ON
#define PUID2_BUF       dir_status.bit.b1   // flag of IDPU, PU06 PnP, 0:PU06 ON
//[ //[Dwell S curve,Lyabryan,2018/11/21]
#define SLOWSPSTR       dir_status.bit.b8   // AI DIR ENABLE
#define SLOWSPSHOW      dir_status.bit.b9   // 50Hz factory settings
//#define OPSINGLE        dir_status.bit.b10 // open single phase setting
//#define PUID1           dir_status.bit.b11 // flag of PU06 PnP, 0:PU06 ON
//#define PUID1_BUF       dir_status.bit.b12 // flag of IDPU, PU06 PnP, 0:PU06 ON
//#define CHECK_SW        dir_status.bit.b13 // 12/05/2003 CopyRight
//#define COPY_CHK        dir_status.bit.b14 // 12/05/2003 CopyRight
//] //[Dwell S curve,Lyabryan,2018/11/21]
#define btGearFlag      dir_status.bit.b10  //[JES Gear no output MO=2, Special.Kung, 2022/10/12]
#define btArtemisEnable dir_status.bit.b11  //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]


//---------------- EPS Power Enable ----------------// 
#define MI_EPS_SWITCH        EPS_POWER_SWITCH.bit.b0
#define MO_EPS_SWITCH        EPS_POWER_SWITCH.bit.b1
#define EPS_MO_JUDGEMENT     EPS_POWER_SWITCH.bit.b2
#define DUTY_ON              EPS_POWER_SWITCH.bit.b3

//-----------IED PG Flag---------------////[For IED PG-Card, Sampo, 02/14/2010]
#define IED_PG_ERR_CRC       IEDPG_status.bit.b0   //CRC Check Error
#define IED_PG_ERR_SIN       IEDPG_status.bit.b1   //SIN/COS PG loss
#define IED_PG_ERR_AB        IEDPG_status.bit.b2   //AB PG loss
#define IED_PG_ERR_OVERTIME  IEDPG_status.bit.b3   //Comunication Over Time
#define IED_PG_ERR_ERRBIT    IEDPG_status.bit.b4   //Endat Error bit
#define IED_PG_RESET         IEDPG_status.bit.b5   //Encoder PG Reset
#define IED_PG_START         IEDPG_status.bit.b6   //Encoder PG START
#define IED_PG_ERR_Z         IEDPG_status.bit.b7   //Z LOss
#define IED_PG_ERR_ENDAT     IEDPG_status.bit.b8   //Z LOss
#define IED_PG_ERR_HIPER     IEDPG_status.bit.b9   //Z LOss
#define IED_PG_ERR_TYPE      IEDPG_status.bit.b10  //Z LOss


//-------- Time Base status ------------
#define TB_1sec         tb_status.bit.b0
#define TB_40ms         tb_status.bit.b1
#define TB_100ms        tb_status.bit.b2
#define TB_100ms2       tb_status.bit.b3
#define TB_20ms         tb_status.bit.b4
#define TB_500us        tb_status.bit.b5
#define TB_2ms          tb_status.bit.b6
#define TB_2sec         tb_status.bit.b7
#define TB_500ms        tb_status.bit.b8

//-------- wg status -------------------
#define WGMODE          wg_status.bit.b0  // sine or discontinuous mode
#define WGDIR           wg_status.bit.b1  // operate direct
#define WGARMU          wg_status.bit.b2  // continuous arm u phase
#define WGARMV          wg_status.bit.b3  //                v
#define WGARMW          wg_status.bit.b4  //                w
#define WGDBC           wg_status.bit.b5  // double carry frequency
#define PWMUPDATEOK     wg_status.bit.b6  // PWM duty value update flag
#define WGDBC1          wg_status.bit.b7  // carry frequency below 6KHz
#define WGARMU_BAR      wg_status.bit.b8  // inverse of continuous arm u phase
#define WGARMV_BAR      wg_status.bit.b9  // inverse of        "       v
#define WGARMW_BAR      wg_status.bit.b10 // inverse of        "       w
#define CFEXEN          wg_status.bit.b11 // Carry freq. exchange
#define ZEROC           wg_status.bit.b12 // zero crossing
#define CC4ACCEL        wg_status.bit.b13 // CC be set For OL1
#define CC4OL1          wg_status.bit.b14 // CC be set For OL1
#define CC4OL           wg_status.bit.b15 // CC be set For OL

#define CC4display      wg_status_CC.bit.b0 // For CC display   //[CC Display, Bernie, 2017/04/12]
#define CC4KeyPad       wg_status_CC.bit.b1


/*------ Auto-Tuning status -------*/
#define TUN_START       tun_status.bit.b0  // Auto Tun start
#define TUN_OK          tun_status.bit.b1  // Auto Tun completed
#define TUN_DC_OK       tun_status.bit.b2  // Auto Tun DC test
#define TUN_HFSS_OK     tun_status.bit.b3  // Auto Tun still
#define TUN_ROTARY_OK   tun_status.bit.b4  // Auto Tun Rotary flag
#define TUN_WAIT        tun_status.bit.b5  // Auto Tun Wait flag for entering next TEST
#define TUN_IACrossZero tun_status.bit.b6  // Auto Tun Wait flag for entering next TEST
#define TUN_DBC_OK      tun_status.bit.b7  // Dead time compensation ok flag
#define TUN_ROLLING     tun_status.bit.b8  // Auto Tun Rolling Flag
#define TUN_SAMPLEON	tun_status.bit.b9  // Auto Tun Sample Flag
#define TUN_LFSL_OK     tun_status.bit.b10 // Auto Tun LFSL OK
#define TUN_LFSL        tun_status.bit.b11 // Auto Tun Shaft Lock Flag
#define TUN_PMLS_OK	    tun_status.bit.b12 // Auto Tun PM LS	//ADDED BY SCOTTY
#define TUN_PMLS_ST	    tun_status.bit.b13 // Auto Tun PM LS	//ADDED BY SCOTTY
#define TUN_POS_DC_OK	tun_status.bit.b14 // Auto Tun PG Z		//ADDED BY SCOTTY 2007/06/01
#define TUN_PHASEZ_OK	tun_status.bit.b15 // Auto Tun PG Z		//ADDED BY SCOTTY 2007/06/01

/*------ preventation status ------*/
#define STALLV          pre_status.bit.b0	// stall for volt
#define STALLC          pre_status.bit.b1	// stall for current
#define BBTAT           pre_status.bit.b2	// BB Time attain
#define LVTAT           pre_status.bit.b3	// LV Time Attain
#define SPSEARCH        pre_status.bit.b4	// Speed search Method (1: Reference, 0:Min Speed)
#define LVORFLT         pre_status.bit.b5	// LV or Fault Speed Search (1:Lv, 0:Fault)
#define RESTART         pre_status.bit.b6	// Restart flag
#define FSKIPFLG        pre_status.bit.b7	// FSKIP FLAG
#define OT1CST          pre_status.bit.b8	// OT1 Counter Start
#define OT2CST          pre_status.bit.b9	// OT2 Counter Start
#define ABV_CURT        pre_status.bit.b10	// current above setting level
#define ABV_SPDA        pre_status.bit.b11	// speed above setting area
#define CTRLMCHG        pre_status.bit.b12	// Control mode be changed falg
#define STALLC2         pre_status.bit.b13	// Stall for Current 2
#define OVERSLIP	    pre_status.bit.b14	// Over Slip flag
#define BEFORERUN		pre_status.bit.b15  // Flag of before run diagnostic test procedure

#define ABV_PGSPDA      pre_status2.bit.b0	// #16698 PG speed Above Speed Area for NRG//James, 2021/08/09


//---------- PG status ----------------*/
#define PGDIR           pg_status.bit.b0    // motor direction by PG
#define PGLOSS          pg_status.bit.b1    // encoder signal loss flag
#define PGDIR2	        pg_status.bit.b2    // direction of PG reference 2
#define PG2OverFlow     pg_status.bit.b3    // Flag of PG2 Overflow
#define PG2UnderFlow    pg_status.bit.b4    // Flag of PG2 UnderFlow
#define PGLOSS_ABS      pg_status.bit.b5    // Absolute encoder signal loss flag
#define PGFirst         pg_status.bit.b6    // first run flag
#define PGLOSS_H        pg_status.bit.b7    // Hardware encoder signal loss flag

//--------- Saturation status ---------*/
#define CurSat_flag	    Con_status.bit.b0   // current saturation
#define VolSat_flag	    Con_status.bit.b1   // voltage saturation
#define CurSat_first	Con_status.bit.b2   // current saturation first time
#define IdRefSat_flag	Con_status.bit.b3   // Id refence saturation
#define SpdSlop_flag	Con_status.bit.b4   // Speed slop
#define FOCPGPowerSave	Con_status.bit.b5   // FOCPG Power Save flag
#define EsJ_ubCnt   	Con_status.bit.b6   // Eestimate intia flag

//--------- Control mode ---------*/
#define TqSpd_flag	    Con1_status.bit.b0  // Toqure : 1, Speed : 0 in the Toqure control
#define EXT_TqSpd_flag	Con1_status.bit.b1  // Toqure : 1, Speed : 0 at External control 
#define TqSpdMode	    Con1_status.bit.b2  // Toqure mode: 1, Speed mode: 0 
#define TqMode_first	Con1_status.bit.b3  // first run toqure mode 
#define ZEROSTOP		Con1_status.bit.b4  // Zero Stop Flag for Zero BW, DINO, 08/02/2010
#define ZEROSERVO		Con1_status.bit.b5  // Zero Servo Start Flag (Iq>6.25%Irated), DINO, 05/16/2011
#define UNI_ZEROSERVO	Con1_status.bit.b6  // Unipolar Zero Servo Start Flag (Iq>6.25%Irated), DINO, 05/16/2011
#define ZEROSERVOEND    Con1_status.bit.b7  // Zero Servo End Flag, DINO, 05/16/2011

//--------- Write Pr to EEPROM --------*/
#define WRITE_TUNPR     WREP_status.bit.b0
#define WRITE_DBCPR     WREP_status.bit.b1
#define WRITE_FLUXPR    WREP_status.bit.b2
#define WRITE_CCBPR     WREP_status.bit.b3
#define WRITE_LVEEP		WREP_status.bit.b4	//Add by DINO, 03/04/2010
#define WRITE_TUNZOFFSET WREP_status.bit.b5	//ADDED SCOTTY 2007/06/07
#define WRITE_TUNPMPR	WREP_status.bit.b6	//ADDED SCOTTY 2007/08/27
#define WRITE_ZSECT		WREP_status.bit.b7  //Added DINO   2008/07/09

#define WRITE_Z_1387	WREP_status2.bit.b0 // [IED 1387 static Tune, 2011/07/06]
#define WRITE_PR_ATONCE WREP_status2.bit.b1

#define PositionCom     APR_status.bit.b0
#define APRExeFlag	    APR_status.bit.b1
#define LOOPFlag        APR_status.bit.b2
#define APRCMDDIR       APR_status.bit.b3
#define ZeroServo       APR_status.bit.b4
#define EnterLoop	    APR_status.bit.b5
#define PcurveFlg	    APR_status.bit.b6
#define P2PFlag		    APR_status.bit.b7
#define PcurveReach	    APR_status.bit.b8 
#define ONPosition	    APR_status.bit.b9 
#define STOPgoAPR       APR_status.bit.b10
#define APRFirstGo      APR_status.bit.b11
#define MultiONPosition	APR_status.bit.b12
#define STPgoAPRChkZ	APR_status.bit.b13
#define APR_ZChkFlag	APR_status.bit.b14
#define APR_ZEROSTOP	APR_status.bit.b15

//--------- PM MOTOR status -----------//
#define	ALIGN			PMstart_status.bit.b0
#define STtune			PMstart_status.bit.b1	// StandStill tune flag, dino 2006/08/07
#define AD_OK			PMstart_status.bit.b2	// for StandStill tune when POWER_ON or pr[ST_TUNE]=1, dino 2006/08/07
#define STtune_Buf		PMstart_status.bit.b3	// StandStill tune temp flag, dino, 04/03/2007
#define ZCALIB    		PMstart_status.bit.b4	// Z pulse calibration flag, dino, 01/24/2008
#define TUN_SS			PMstart_status.bit.b5   // PM motor standstill tuning, dino 07/22/2008
#define PGREADY			PMstart_status.bit.b6	// Absoulte Signal Ready Flag, DINO, 12/23/2009

//------------ ECAN status -------------//               // [Can function, Bernie, 08/16/2011]
//#define MB1_Done		ECAN_status.bit.b0		//MB1 Tx Done Flag
//#define MB2_Done		ECAN_status.bit.b1		//MB2 Rx Done Flag
//#define MB3_Done		ECAN_status.bit.b2		//MB3 Tx Done Flag
//#define MB4_Done		ECAN_status.bit.b3		//MB4 Rx Done Flag
//#define MB5_Done		ECAN_status.bit.b4		//MB5 Tx Done Flag
//#define MB6_Done		ECAN_status.bit.b5		//MB6 Rx Done Flag

//------------ ECAN status -------------//      // [CAN Protocol for High Cap , Sampo,  2011/09/05]
//#define SDO_RX0_OK      CAN_HC_status.bit.b0 
//#define SDO_RX1_OK      CAN_HC_status.bit.b1   
//#define SDO_RX2_OK      CAN_HC_status.bit.b2 
//#define PDO_RX0_OK      CAN_HC_status.bit.b3

//------------ R_CAN status -------------//  
#define CAN_RX1_OK      CAN_status.bit.b0 
#define CAN_RX3_OK      CAN_status.bit.b1 
#define CAN_RX5_OK      CAN_status.bit.b2 
#define CAN_RX7_OK      CAN_status.bit.b3
#define PGCD_AF_FLAG    CAN_status.bit.b13
#define OBKEYPROG       CAN_status.bit.b14




//------------ STO status ------------ //
#define S1_C      STO_status.bit.b0
#define S2_C      STO_status.bit.b1
#define S1_DC     STO_status.bit.b2
#define P_5V      STO_status.bit.b3
#define STOLOSS   STO_status.bit.b4
#define STO1LOSS  STO_status.bit.b5
#define STO2LOSS  STO_status.bit.b6
#define STO3LOSS  STO_status.bit.b7

//------------ USB status -------------//
//#define	USBLOAD		    USB_status.bit.b0		// 100us, ADD BY Sean, 02/22/2010

//------------ PWM update status-------//
#define PWM_UpdateDUTY	PWM_Status.bit.b0		// ADDED BY SCOTTY	,06/30/2007
#define GEN_START    	PWM_Status.bit.b1  		// For generation dir flag, by Justin , 2010/04/27
#define GEN_EN			PWM_Status.bit.b2		// Operation in Generation Direction if UPS
#define GENDIR			PWM_Status.bit.b3		// Generation Direction if UPS, 0:REVERSE/1:FORWARD
#define GEN_OK			PWM_Status.bit.b4		// Generation Direction if UPS detect okay
#define GEN_OK2_DIR		PWM_Status.bit.b5       // Generation Direction if UPS when used PM control Mode, 0:REVERSE/1:FORWARD  //[Modify EPS function, Bernie, 2012/11/27 ] 
#define GEN_OK3			PWM_Status.bit.b6
#define EPS_STOP	    PWM_Status.bit.b7       //[EPS, Sampo, 03/27/2011]

//------------ PWM update status-------//
#define EPS_S1current_get      EPS_Direct_flag.bit.b0		// ADDED BY SCOTTY	,06/30/2007
#define EPS_S2current_get      EPS_Direct_flag.bit.b1  		// For generation dir flag, by Justin , 2010/04/27
#define EPS_CAL_CUR			   EPS_Direct_flag.bit.b2		// Operation in Generation Direction if UPS
#define EPS_CAL_CUREND         EPS_Direct_flag.bit.b3		// Generation Direction if UPS, 0:REVERSE/1:FORWARD
#define EPS_MODE4			   EPS_Direct_flag.bit.b4		// Generation Direction if UPS detect okay
#define EPS_NOS1		       EPS_Direct_flag.bit.b5       // Generation Direction if UPS when used PM control Mode, 0:REVERSE/1:FORWARD  //[Modify EPS function, Bernie, 2012/11/27 ] 
#define EPS_DIR_CATCH		   EPS_Direct_flag.bit.b6
#define EPS_TUNE_END	       EPS_Direct_flag.bit.b7       //[EPS, Sampo, 03/27/2011]


//------------ FAN Control ------------//		// ADDED BY SCOTTY , 10/15/2007
#define FAN_ENABLE  	FAN_status.bit.b0
#define MCCHK_ENABLE	FAN_status.bit.b1
#define BKCHK_ENABLE1	FAN_status.bit.b2   //[change for EN81-1+A3, Bernie, 2015/03/16]  
#define BKCHK_ENABLE2	FAN_status.bit.b3   //[change for EN81-1+A3, Bernie, 2015/03/16]


//------------ RUN START sequence------//
#define MOTORCONNECTOR		RUN_sequence.bit.b0
#define LIFT_ENABLE			RUN_sequence.bit.b1
#define RUN_GOING			RUN_sequence.bit.b2
#define REPOS_FAULT_FLAG	RUN_sequence.bit.b3	
#define LIFT_RUNCMD			RUN_sequence.bit.b4
#define EPS        			RUN_sequence.bit.b5  // EPS start flag, add by dino, 02/18/2008
#define MPHL_DET			RUN_sequence.bit.b6  // MPHL start flag, Sampo , 05/11/2009
#define I0CHK				RUN_sequence.bit.b7  // Iflux Confirm Flag, Add by DINO, 06/29/2009
#define TUN_STOP			RUN_sequence.bit.b8
#define LAND_PPI			RUN_sequence.bit.b9  // Landing PPI Flag, Add by DINO, 08/05/2010
#define EPS_MI_SET			RUN_sequence.bit.b10 //EPS function of DLC mode , James, 20200408

/*-------- External output status --------*/
#define DO_MO3_PIN      exto_status.bit.b0  // MO3
#define DO_MO4_PIN      exto_status.bit.b1  // MO4
#define DO_MO5_PIN      exto_status.bit.b2  // MO5
#define DO_MO6_PIN      exto_status.bit.b3  // MO6
#define DO_MO7_PIN      exto_status.bit.b4  // MO7
#define DO_MO8_PIN      exto_status.bit.b5  // MO8
#define DO_MO9_PIN      exto_status.bit.b6  // MO9
#define DO_MO10_PIN		exto_status.bit.b7  // MO10

//---------- EnDat status ----------------*/
#define EDT_DATA_ERR	edt_status.bit.b0	// DATA Error Flag
#define EDT_CRC_ERR		edt_status.bit.b1	// CRC Error Flag
#define EDT_EBIT_ERR	edt_status.bit.b2	// Error Bit Flag
#define EDT_READY		edt_status.bit.b3	// EnDat Ready
#define EDT_INIT		edt_status.bit.b4	// EnDAT or Hiperface Data Initial


//---------------- EnDat status ----------------//
#define MODE2           Time_srquence.bit.b0       //[DIN time sequence, Bernie, 2013/03/07]
#define MODE3           Time_srquence.bit.b4       //[DIN time sequence, Bernie, 2013/03/07]
#define MODE1           Time_srquence.bit.b5       //[DIN time sequence, Bernie, 2013/03/07]


//---------------- PG quality ----------------//
#define FIRST_FLAG      SPD_PG_quality.bit.b0      //[PG quality function, Bernie, 2017/06/20]

#define AFE_ERR_TRIG      AFE_Handle_Flag.bit.b0
#define AFE_ERR_TMR       AFE_Handle_Flag.bit.b1
#define AFE_ERR_RECORD    AFE_Handle_Flag.bit.b2
#define AFE_Level_Delay   AFE_Handle_Flag.bit.b3
#define AFE_ERR_RST_CNT   500
//---------------- Smart rise ---------------//

#define btSR_ESD           SMTRISE_status.bit.b0
#define btSR_ETS           SMTRISE_status.bit.b1
#define btSR_speedCTRL_ESD SMTRISE_status.bit.b2
#define btSR_speedCTRL_ETS SMTRISE_status.bit.b3
#define btSR_ESD_EDGE      SMTRISE_status.bit.b4
#define btSR_ETS_EDGE      SMTRISE_status.bit.b5



//---------------- MC2 ----------------//  //[Russia time srequence for IM, Bernie, 2015/07/13]
#define MOTORCONNECTOR2   Run_Time_srquence.bit.b0
#define RUN_DETECT        Run_Time_srquence.bit.b1

//---------- PGHSD-01 ----------//
#define NEWHSDSTUNE      vfd_uwFunSel2.bit.b0   // state tune            //[Modify PGHSD01 function, Bernie, 2012/02/05]
#define	vfd_btPGHSD1Set  vfd_uwFunSel2.bit.b9	//IED Function	: PGHSD1 setting

#define  APPS_USE_BL  (1)
#define HSDTIMEOUT    hsd_status.bit.b0 //[PG card can't work, Bernie, 2015/09/21]

//--------- VH, KEB Flag --------------//
#define VH_F3600        36000               // 3600.0Hz
#define VH_F3000	    30000               // 3000.0Hz
#define VH_EN           VH_status.bit.b0    // VH Enable
#define KEB_ON          VH_status.bit.b1    // KEB ON
#define KEB_AUTO        VH_status.bit.b2    // KEB Automatic
#define STALL_AUTO      VH_status.bit.b3    // Stall Automatic
#define PIDHOLD         VH_status.bit.b5    // PID at last freq.


//--------- Auto Restart function flag define ---------//  //[Add auto restart after fault, Bernie, 06/06/12]
#define RST_CNT_OK      RST_Status.bit.b0     //
#define RST_EN          RST_Status.bit.b1

#define SIBO_ZEROF       Sibocom_spflag.bit.b0
#define SIBO_INSF        Sibocom_spflag.bit.b1
#define SIBO_LEVELF      Sibocom_spflag.bit.b2      
#define SIBO_RELEVELF    Sibocom_spflag.bit.b3      
#define SIBO_LOWF        Sibocom_spflag.bit.b4      
#define SIBO_MIDF        Sibocom_spflag.bit.b5      
#define SIBO_HIGHF       Sibocom_spflag.bit.b6      
#define SIBO_NORMALF     Sibocom_spflag.bit.b7
#define SIBO_EMYFLAG     Sibocom_spflag.bit.b8
//#define         Sibocom_spflag.bit.b9
//#define         Sibocom_spflag.bit.b10     
//#define         Sibocom_spflag.bit.b11
//#define         Sibocom_spflag.bit.b12
//#define         Sibocom_spflag.bit.b13
//#define         Sibocom_spflag.bit.b14     
//#define         Sibocom_spflag.bit.b15

#define SIBO_PARAMETER   Sibocom_ENflag.bit.b0 //[Group12&13 Limit count,Lyabryan,2020/09/10]
#define STO_STRWARN      Sibocom_ENflag.bit.b1
#define STO_RUNWARN      Sibocom_ENflag.bit.b2
#define STO_SOSWARN      Sibocom_ENflag.bit.b3//[Sibocom SOS Warn, James, 2020/04/28]
#define STO_STATUS_FLAG  Sibocom_ENflag.bit.b4
#define SIBO_SPDCHG      Sibocom_ENflag.bit.b5
//#define         Sibocom_ENflag.bit.b6
//#define         Sibocom_ENflag.bit.b7
//#define         Sibocom_ENflag.bit.b8
//#define         Sibocom_ENflag.bit.b9
//#define         Sibocom_ENflag.bit.b10     
//#define         Sibocom_ENflag.bit.b11
//#define         Sibocom_ENflag.bit.b12
//#define         Sibocom_ENflag.bit.b13
//#define         Sibocom_ENflag.bit.b14     
//#define         Sibocom_ENflag.bit.b15

#define INSPECTIONSP 0
#define LEVELSP      1
#define RELEVELSP    2
#define LOWSP        3
#define MIDSP        4
#define HIGHSP       5
#define NOMINALSP    6



//--------------- Lock driver function ---------------//
#define RUN_SENSOR0       Service_time.bit.b0
#define RUN_SENSOR1       Service_time.bit.b1
#define SERV_KEY          Service_time.bit.b2      //[SERV READ ONLY,Lyabryan,2018/08/17]
#define CMDDIR_OLD        Service_time.bit.b3      //[Running Dir Count,Special,2018/08/17] 
#define IRF_ENABLE        Service_time.bit.b4      //[Running Dir Count,Special,2018/08/17] 
#define IRF_Warning       Service_time.bit.b5      //[Running Dir Count,Special,2018/08/17] 
#define IRF_Error         Service_time.bit.b6      //[Running Dir Count,Special,2018/08/17] 
#define SERVICE_RESET     Service_time.bit.b7
#define SERVICE_KEYRESET  Service_time.bit.b8
#define IR_KEYRESET       Service_time.bit.b9

//--------------- Star contactor function ---------------//
#define STAR_CONTACTOR  Star_con_status.bit.b0         //[Star contactor function, Bernie, 2017/03/22]
#define STAR_OUTPUT     Star_con_status.bit.b1         //[Star contactor function, Bernie, 2017/03/22]


/* These macros are for determining if some can while loop times out. If they do,
the canx_sw_err variable will be non zero. This is to prevent an error in the 
can peripheral and driver from blocking the CPU indefinatly. */
#define DEC_CHK_CAN_SW_TMR		(--can_tmo_cnt != 0)
#define RESET_CAN_SW_TMR		(can_tmo_cnt = MAX_CAN_SW_DELAY);

/* Max delay waiting for CAN register to flip. Set to whatever theoretical 
worst latency you could accept. It should never timeout. Do not set to 0. */
#define MAX_CAN_SW_DELAY 	   (0x2000)


//====STO Error count define====//
//Count++/500us
#define STO_RUN_CNT     22		// 500us*22=11ms
#define STO_ERR_CNT     20		// 500us*20=10ms
#define STOL1_ERR_CNT   220 	// 500us*220=110ms
#define STOb_RESET_CNT  0 		
#define STOb_RUN_CNT  	2000	// 500us*2000=1s
#define STOr_RESET_CNT  10000	// 500us*10000=5s
#define STOc_RESET_CNT  2000 	// 500us*2000=1s
#define STOA_RESET_CNT  100		// 500us*100=50ms

//====Auto reset  count define====//
#define TEN_MINS_CNT  60000           //60000  //[Add auto restart after fault, Bernie, 06/06/12]




#define MFIMAX		    59  //adco	
#define MFOMAX		    52    
#define AFMMAX		    21

#define BERNIE   0
#define __BIG    0

#define AD_3V   620
//--------  Drive Type --------

#define VFD022V21A      108   //[Single phase input, Bernie, 01/19/2012]
#define VFD037V21A      110   // 5HP 220V single phase input   //[Single phase input, Bernie, 01/19/2012]

#define VFD007V23A      4    // 1HP 230V
#define VFD007V43A      5    // 1HP 460V
#define VFD015V23A      6    // 2HP 230V
#define VFD015V43A      7    // 2HP 460V
#define VFD022V23A      8    // 3HP 230V
#define VFD022V43A      9    // 3HP 460V
#define VFD037V23A      10   // 5HP 230V
#define VFD037V43A      11   // 5HP 460V
#define VFD055V23A      12   // 7.5HP 230V 
#define VFD055V43A      13   // 7.5HP 460V
#define VFD075V23A      14   // 10HP 230V
#define VFD075V43A      15   // 10HP 460V
#define VFD110V23A      16   // 15HP 230V
#define VFD110V43A      17   // 15HP 460V
#define VFD150V23A      18	 // 20HP 230V
#define VFD150V43A      19   // 20HP 460V
#define VFD185V23A      20   // 25HP 230V
#define VFD185V43A      21   // 25HP 460V
#define VFD220V23A      22   // 30HP 230V
#define VFD220V43A      23   // 30HP 460V
#define VFD300V23A      24   // 40HP 230V
#define VFD300V43A      25   // 40HP 460V
#define VFD370V23A      26   // 50HP 230V
#define VFD370V43A      27   // 50HP 460V
#define VFD450V23A      28   // 60HP 230V
#define VFD450V43A      29   // 60HP 460V
#define VFD550V23A      30	 // 75HP 230V
#define VFD550V43A      31   // 75HP 460V
#define VFD750V23A      32	 // 100HP 230V
#define VFD750V43A      33   // 100HP 460V 
#define VFD1100CH43A      37   // 100HP 460V 

#define MAXMODELNO      39

#define VFD_SINGLEPHASE 100     //[Single phase input, Bernie, 01/19/2012]

#define VFD440V         0x0001
#define VFD220V         0x0000

//-------- TH1 CURVE (IGBT) --------
#define IN_DEG_0        897
#define IN_DEG_25       720
#define IN_DEG_50       499
#define IN_DEG_80       282
#define IN_DEG_100      196
#define IN_DEG_150      50

//-------- TH1,TH2 CURVE (Heat Sink) --------
#define OUT_DEG_0       884
#define OUT_DEG_25      695
#define OUT_DEG_50      436
#define OUT_DEG_80      208
#define OUT_DEG_100     112
#define OUT_DEG_150     50

/*-------------------------------------------------------------------------------------------*/
/*------ LED EQUATION                   ;DECIMAL TO 7 SEGMENTS
         ___4___
        |       |
       3|       | 5
        |___2___|
        |       |
       1|       | 6
        |___0___|   o
                    7

                76543210	*/
#define CHAR_Ubar	0x53    //.EQU    0101 0011B    ;u_
#define CHAR_i      0x13	//.EQU    0001 0011B    ;i
#define CHAR_Z	    0x11	//.EQU    0001 0001B    ;Z
#define CHAR_NEG    0x04	//.EQU    0000 0100b    ;-
#define CHAR_T	    0x1a	//.EQU    0001 1010b    ;T

#define CHAR_0      0x7b	//.EQU    0111 1011B    ;0 
#define CHAR_1      0x60	//.EQU    0110 0000B    ;1 
#define CHAR_2      0x37	//.EQU    0011 0111B    ;2 
#define CHAR_3      0x75	//.EQU    0111 0101B    ;3 
#define CHAR_4      0x6c	//.EQU    0110 1100B    ;4 
#define CHAR_5      0x5d	//.EQU    0101 1101B    ;5 
#define CHAR_6      0x5f	//.EQU    0101 1111B    ;6 
#define CHAR_7      0x70	//.EQU    0111 0000B    ;7
#define CHAR_8      0x7f	//.EQU    0111 1111B    ;8
#define CHAR_9      0x7d	//.EQU    0111 1101B    ;9
#define CHAR_A      0x7e	//.EQU    0111 1110B    ;A
#define CHAR_b      0x4f	//.EQU    0100 1111B    ;b
#define CHAR_C      0x1b	//.EQU    0001 1011B    ;C
#define CHAR_c      0x07	//.EQU    0000 0111B    ;c
#define CHAR_d      0x67	//.EQU    0110 0111B    ;d
#define CHAR_E      0x1f	//.EQU    0001 1111B    ;E
#define CHAR_F      0x1e	//.EQU    0001 1110B    ;F
#define CHAR_G      0x5b	//.EQU    0101 1011B    ;G
#define CHAR_H      0x6e	//.EQU    0110 1110B    ;H
#define CHAR_L      0x0b	//.EQU    0000 1011B    ;L
#define CHAR_n      0x46	//.EQU    0100 0110B    ;n
#define CHAR_o      0x47	//.EQU    0100 0111B    ;o
#define CHAR_P      0x3e	//.EQU    0011 1110B    ;P
#define CHAR_q      0x7c	//.EQU    0111 1100B    ;q
#define CHAR_r      0x06	//.EQU    0000 0110B    ;r
#define CHAR_S      0x5d	//.EQU    0101 1101B    ;S
#define CHAR_t      0x0f	//.EQU    0000 1111B    ;t
#define CHAR_U      0x6b	//.EQU    0110 1011B    ;U
#define CHAR_v      0x43	//.EQU    0100 0011B    ;v
#define CHAR_y      0x6d	//.EQU    0110 1101B    ;y
/*
        ___4___
       |       |
      3|       | 5
       |___2___|
       |       |
      1|       | 6
       |___0___|   o
                   7

*/

#define AND_BIT00       0xFFFE
#define AND_BIT01       0xFFFD
#define AND_BIT02       0xFFFB
#define AND_BIT03       0xFFF7
#define AND_BIT04       0xFFEF
#define AND_BIT05       0xFFDF
#define AND_BIT06       0xFFBF
#define AND_BIT07       0xFF7F
#define AND_BIT08       0xFEFF
#define AND_BIT09       0xFDFF
#define AND_BIT10       0xFBFF
#define AND_BIT11       0xF7FF
#define AND_BIT12       0xEFFF
#define AND_BIT13       0xDFFF
#define AND_BIT14       0xBFFF
#define AND_BIT15       0x7FFF

#define OR_BIT00        0x0001
#define OR_BIT01        0x0002
#define OR_BIT02        0x0004
#define OR_BIT03        0x0008
#define OR_BIT04        0x0010
#define OR_BIT05        0x0020
#define OR_BIT06        0x0040
#define OR_BIT07        0x0080
#define OR_BIT08        0x0100
#define OR_BIT09        0x0200
#define OR_BIT10        0x0400
#define OR_BIT11        0x0800
#define OR_BIT12        0x1000
#define OR_BIT13        0x2000
#define OR_BIT14        0x4000
#define OR_BIT15        0x8000
/* ---------- ] */



/* ==== Symbol Definition ==== */
//#define DTC_SSU_TX (*(volatile struct st_dtc_info*)0xFFFF8810) /* DTC transfer information */ //[Sampo, 09/11/2009]
//#define DTC_SSU_RX (*(volatile struct st_dtc_info*)0xFFFF8800) /* DTC Receive information  */
//#define DTC_VECT_BASE 0x0FFFF8000   /* DTC vector table address */VECT_BASE 0x0FFFF8000   /* DTC vector table address */
