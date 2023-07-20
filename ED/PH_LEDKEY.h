/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-VL

Filename: PH_LED.H

Partner Filename: PH_LED.C

Description: This is a inclue file of PH_LED.C

Complier: 

	
History:

===============================================================*/
#ifdef _LEDKEY_C
   #define LEDKEY_EXT 
#else
   #define LEDKEY_EXT extern
#endif

//****************************************************************
// @Typedefs
//****************************************************************
typedef struct{
        UBYTE    s0;
        UBYTE    s1;
        UBYTE    s2;
        UBYTE    s3;
        UBYTE    s4;
        UBYTE    s5;
        UBYTE    s6;
}LEDSEG;                                // Which are LED 7 Segment

typedef struct{
        UBYTE    s4;
        UBYTE    s2;
        UBYTE    s1;
        UBYTE    s0;
}LEDDATASEG;                                // Which are LED 7 Segment


#define REPEATC0        12  //  The constant of repeat key
#define REPEATC1       120  //  The constant of repeat key
#define DLY4END			40	// 800ms/20ms


#if NEWIEDCB
//Keyin address
#define MODEKEY         1
#define STOPKEY         2	// RESERVED
#define RUNKEY          2	// RESERVED
#define SHIFTKEY        3
#define JOGKEY          4	// RESERVED
#define UPKEY           6
#define DOWNKEY         7
#define PROGKEY         8
#define RECENT_KEY     19 //[add RecentPG,Lyabryan,2020/03/14]
/*---------- LED EQUATION ---------------
        ___6 ___
       |             |
    5 |             | 7
       |___4___|
       |             |
    1 |             | 3
       |___2___|   o
                             0
                                       */
#define _Ubar	0x4e    //.EQU    0101 0011B    ;u_
#define _Z		0x44	//.EQU    0001 0001B    ;Z
#define _NEG	0x10	//.EQU    0000 0100b	;-
#define _BLK	0x00	//.EQU	  0000 0000b	;

#define _0		0xee	//.EQU    0111 1011B	;0 
#define _1		0x88	//.EQU    0110 0000B    ;1 
#define _2		0xd6	//.EQU    0011 0111B    ;2 
#define _3		0xdc	//.EQU    0111 0101B    ;3 
#define _4		0xb8	//.EQU    0110 1100B    ;4 
#define _5		0x7c	//.EQU    0101 1101B    ;5 
#define _6		0x7e	//.EQU    0101 1111B    ;6 
#define _7		0xc8	//.EQU    0111 0000B    ;7
#define _8		0xfe	//.EQU    0111 1111B    ;8
#define _9		0xfc	//.EQU    0111 1101B    ;9
#define _A		0xfa	//.EQU    0111 1110B    ;A
#define _b		0x3e	//.EQU    0100 1111B    ;b
#define _C		0x66	//.EQU    0001 1011B    ;C
#define _c		0x16	//.EQU    0000 0111B    ;c
#define _d		0x9e	//.EQU    0110 0111B    ;d
#define _E		0x76	//.EQU    0001 1111B    ;E
#define _F		0x72	//.EQU    0001 1110B    ;F
#define _G		0x6e	//.EQU    0101 1011B    ;G
#define _H		0xba	//.EQU    0110 1110B    ;H
#define _h		0x3a	//.EQU    0110 1110B    ;H
#define _i		0x08	//.EQU    0001 0011B    ;i
#define _J		0x87	//                      ;J
#define _L		0x26	//.EQU    0000 1011B    ;L
#define _M		0xea	//                      ;M
#define _n		0x1a	//.EQU    0100 0110B    ;n
#define _o		0x1e	//.EQU    0100 0111B    ;o
#define _P		0xf2	//.EQU    0011 1110B    ;P
#define _q		0xf8	//.EQU    0111 1100B    ;q
#define _r		0x12	//.EQU    0000 0110B    ;r
#define _S		0x7c	//.EQU    0101 1101B    ;S
#define _T		0x62	//.EQU    0001 1010b	;T
#define _t		0x36	//.EQU    0000 1111B    ;t
#define _U		0xae	//.EQU    0110 1011B    ;U
#define _u		0x0e	//.EQU    0100 0011B    ;u
#define _v		0x0e	//.EQU    0100 0011B    ;v
#define _y		0xbc	//.EQU    0110 1101B    ;y
#define _DOT	0x01	//						;.
#define _ONON	0xaa	//.EQU	  1010 1010B	;||
#define	_OFOF	0x0a	//.EQU	  0000 1010B	;..
#define	_OFON	0x8a	//.EQU	  1000 1010B	;.|
#define	_ONOF	0x2a	//.EQU	  0010 1010B	;|.
#define _IOB1	0x40	
#define _IOB2	0x80	
#define _IOB3	0x08	
#define _IOB4	0x04	
#define _IOB5	0x02	
#define _IOB6	0x20	
#define _IOB7	0x10	
#define _IOB8	0x01	
#define _UP		0xe0	//.EQU    1110 0000B	;0 
#define _DN		0x0e	//.EQU    0000 1110B	;0 

// [ Modify the LED Index, DINO, 09/28/2010
#define LED_UP		0x01
#define LED_DN		0x02
#define LED_D1		0x08
#define LED_D3 		0x10
#define	LED_D2		0x40	// Sean, 12/06/2010
#define	LED_D4		0x01	// Sean, 12/06/2010
// ]

#else

//Keyin address
#define MODEKEY         4
#define STOPKEY         1	// RESERVED
#define RUNKEY          1	// RESERVED
#define SHIFTKEY        3
#define JOGKEY          8	// RESERVED
#define UPKEY           6
#define DOWNKEY         5
#define PROGKEY         7

/*------ LED EQUATION                   ;DECIMAL TO 7 SEGMENTS
        ___1___
       |             |
    2 |             | 0
       |___3___|
       |             |
    6 |             | 4
       |___5___|   o
                            7

                76543210	*/
#define CHAR2_Ubar	0x72    //.EQU    0101 0011B    ;u_
#define CHAR2_Z		0x22	//.EQU    0001 0001B    ;Z
#define CHAR2_NEG	0x08	//.EQU    0000 0100b	;-
#define CHAR2_BLK	0x00	//.EQU	  0000 0000b	;

#define CHAR2_0		0x77	//.EQU    0111 1011B	;0 
#define CHAR2_1		0x11	//.EQU    0110 0000B    ;1 
#define CHAR2_2		0x6b	//.EQU    0011 0111B    ;2 
#define CHAR2_3		0x3b	//.EQU    0111 0101B    ;3 
#define CHAR2_4		0x1d	//.EQU    0110 1100B    ;4 
#define CHAR2_5		0x3e	//.EQU    0101 1101B    ;5 
#define CHAR2_6		0x7e	//.EQU    0101 1111B    ;6 
#define CHAR2_7		0x13	//.EQU    0111 0000B    ;7
#define CHAR2_8		0x7f	//.EQU    0111 1111B    ;8
#define CHAR2_9		0x3f	//.EQU    0111 1101B    ;9
#define CHAR2_A		0x5f	//.EQU    0111 1110B    ;A
#define CHAR2_b		0x7c	//.EQU    0100 1111B    ;b
#define CHAR2_C		0x66	//.EQU    0001 1011B    ;C
#define CHAR2_c		0x68	//.EQU    0000 0111B    ;c
#define CHAR2_d		0x79	//.EQU    0110 0111B    ;d
#define CHAR2_E		0x6e	//.EQU    0001 1111B    ;E
#define CHAR2_F		0x4e	//.EQU    0001 1110B    ;F
#define CHAR2_G		0x76	//.EQU    0101 1011B    ;G
#define CHAR2_H		0x5d	//.EQU    0110 1110B    ;H
#define CHAR2_i		0x62	//.EQU    0001 0011B    ;i
#define CHAR2_J		0x71
#define CHAR2_L		0x64	//.EQU    0000 1011B    ;L
#define CHAR2_M		0x57
#define CHAR2_n		0x58	//.EQU    0100 0110B    ;n
#define CHAR2_o		0x78	//.EQU    0100 0111B    ;o
#define CHAR2_P		0x4f	//.EQU    0011 1110B    ;P
#define CHAR2_q		0x1f	//.EQU    0111 1100B    ;q
#define CHAR2_r		0x48	//.EQU    0000 0110B    ;r
#define CHAR2_S		0x3e	//.EQU    0101 1101B    ;S
#define CHAR2_T		0x46	//.EQU    0001 1010b	;T
#define CHAR2_t		0x6c	//.EQU    0000 1111B    ;t
#define CHAR2_U		0x75	//.EQU    0110 1011B    ;U
#define CHAR2_v		0x70	//.EQU    0100 0011B    ;v
#define CHAR2_y		0x3d	//.EQU    0110 1101B    ;y
#define CHAR2_DOT	0x80	//						;.

#define LED_RUN		0x08
#define LED_FWD		0x10
#define LED_REV		0x20
#define LED_STOP	0x02
#endif



//---------[ Keypad display page definition ]---------------------------------
#define 	F_PAGE2   	0       // F command, same as remote keypad dispaly
#define 	H_PAGE2   	1       // H command, same as remote keypad dispaly
#define 	U_PAGE2		2       // Dcbus Display                                 
#define 	A_PAGE2		3       // Current Display               
#define 	E_PAGE2		4       // Output Voltage Display           
//#define		MIOPAGE2	5		// MI Page	// add mi/mo page in led keypad, Sean, 05/04/2011
#define 	USER_PAGE2	5       // User Definitation Display
#define 	GrPAGE2   	7       // Group
#define 	FunPAGE2  	8       // Function
#define 	DataPAGE2 	9       // Data
#define 	MsgPAGE2  	10      // Message, End, Err, READ, SAVE
#define 	ErrPAGE2  	11      // Error message, same as remote keypad dispaly
#define 	WarnPAGE2 	12      // Warning message, same as remote keypad dispaly
#define 	PU02SAVE2	13      // PU02 write Parameter data to VFD
#define     RECENTPG    14

/* Function Call ==============================================*/
LEDKEY_EXT void KEY_IN(void);
LEDKEY_EXT void LED_OUT(void);
LEDKEY_EXT void Bcd2Led(ULONG data, UBYTE unit);
LEDKEY_EXT void key_prog(void);
LEDKEY_EXT void Update_LEDKeyDisp(void);
LEDKEY_EXT void LED_HexBcd(ULONG data, UBYTE unit);
LEDKEY_EXT void LED_BinBcd(ULONG data, UBYTE unit);
LEDKEY_EXT void incgrno(void);
LEDKEY_EXT void decgrno(void);
LEDKEY_EXT void blink_seg(UBYTE x);
LEDKEY_EXT void ErrorMSG(void);
LEDKEY_EXT void warndisp(UBYTE ubWarnCode);
LEDKEY_EXT void LED_MioBcd(UBYTE page);
LEDKEY_EXT void D1toD4_Display(void);   //[Added D1 to D4 on board display, Bernie, 2013/01/29]
LEDKEY_EXT void LED_MIMO_Display(void);

/* Exported Variable List ======================================*/
LEDKEY_EXT UBYTE	keyinx,
					keyin1,
   					keyct0,
   					keyct1,
   					keyct2,
   					keyct3,
					ledx,
					KEY_ubDispMode,
					KEY_ubDispTmp,
					KEY_ubWarnTmp,
					disptemp,
					dot,
					endct,
					spdispx,
					msg_page,
					grno,
					prno,
					blinks,
					blinkf,
					blinku,
					KEY_ubPrno[(GRALL+1)],
					rst_det,	// reset key detecting and excuting, Sean, 08/19/2010
					recent_pr; //[add RecentPG,Lyabryan,2020/03/14]
LEDKEY_EXT UWORD	recent_no;
LEDKEY_EXT UWORD_UNION     Recentflag; //[add RecentPG,Lyabryan,2020/03/14]

#define GPMODE         Recentflag.bit.b0
//#define GPMODE         Recentflag.bit.b1
//#define GPMODE         Recentflag.bit.b2
//#define GPMODE         Recentflag.bit.b3
//#define GPMODE         Recentflag.bit.b4
//#define GPMODE         Recentflag.bit.b5
//#define GPMODE         Recentflag.bit.b6
//#define GPMODE         Recentflag.bit.b7
//#define GPMODE         Recentflag.bit.b8
//#define GPMODE         Recentflag.bit.b9
//#define GPMODE         Recentflag.bit.b10
//#define GPMODE         Recentflag.bit.b11
//#define GPMODE         Recentflag.bit.b12
//#define GPMODE         Recentflag.bit.b13
//#define GPMODE         Recentflag.bit.b14
//#define GPMODE         Recentflag.bit.b15

LEDKEY_EXT UWORD	relprno,
                    relprno13,
					userfkey,
					KEY_uwPrData,
					KEY_uwPWRCnt;

//LEDKEY_EXT SWORD    KEY_uwPrData;
					
LEDKEY_EXT UBYTE	KEY_MioPag;

LEDKEY_EXT LEDSEG	led;

#define	KEY_MI_PAGA 0
#define	KEY_MI_PAG0	1
#define	KEY_MI_PAG1	2
#define	KEY_MI_PAG2	3
#define	KEY_MI_PAG3 4
#define	KEY_MO_PAGA 5
#define	KEY_MO_PAG0	6
#define	KEY_MO_PAG1 7

/*== Local Variable List (Variables not open to other files)  ==*/
#ifdef _LEDKEY_C

// Warn Code Table for LED Display
const LEDDATASEG WarnMSG[WARNMAX/*+IED_ERRMAX-ERRMAX)*/] = {  // IED Error Display, DINO, 08/13/2010
	  _C,    _E,    _0,   _1,	// cE1     001  CE-01 - illegal command code
	  _C,    _E,    _0,   _2,	// cE1     001  CE-01 - illegal command code
      _C,    _E,    _0,   _3,   // cE1     001  CE-01 - illegal command code
      _C,    _E,    _0,   _4,   // cE1     001  CE-01 - illegal command code
	  _C,    _E,    _1,   _0,   // cE10    005  CE-10 - time out
	  _C,    _P,    _1,   _0,   // cP10    006  CP-10 - Keypad Time out
	_BLK,    _S,    _E,   _1,   // SE1     007  Copy Failure
	_BLK,    _S,    _E,   _2,   // SE2     008  Copy Fail 2, SE2
	_BLK,    _o,    _H,   _1,   // oH1     009  Over Heat 1
	_BLK,    _o,    _H,   _2,   // oH2     010  Over Heat 1
	_BLK,    _P,    _i,   _d,   // Pid     011  PID Loss Warning
	_BLK,    _A,    _n,   _L,   // AnL     012  Analog loss
	_BLK,    _u,    _C, _BLK,   // uC      013  under Current
	_BLK,    _A,    _u,   _E,   // AuE     014  Auto Tun
	  _P,    _G,    _F,   _1,   // PGF1    015  PG feedback Error
	  _P,    _G,    _F,   _2,   // PGF2    016  PG loss (PG Open)
	  _P,    _G,    _F,   _3,   // PGF3    017  Over speed
	  _P,    _G,    _F,   _4,   // PGF4    018  Deviation warning
	_BLK,    _P,    _H,   _L,   // PHL     019  Phase Loss
	_BLK,    _o,    _t,   _1,   // ot1     020  Over Torque 1 warning
	_BLK,    _o,    _t,   _2,   // ot2     021  Over Torque 2 warning
	_BLK,    _o,    _H,   _3,   // oH3     011  oH3 warning (PTC)
	_BLK,    _C,  _DOT,   _C,   // c.c     023  CC warning
	_BLK,    _o,    _S,   _L,   // oSL     024  Over Slip Warning
	_BLK,    _t,    _U,   _n,   // tUn     025  Auto Tuning message
	_BLK,    _F,    _A,   _n,   // FAn     026  FanLock warning
	  _d,    _C,    _A,   _n,   // CAn     027  CAN warning
	  _S,    _t,    _o,   _A,   // STO     028  STO Warning    //[STO function add Warning code and run rule, Bernie, 2016/03/22]
      _U,    _C,    _M,   _P,   // UCMP    029  UCMP Warning   //[UCMP function, Bernie, 2016/06/14]
    _BLK,    _S,    _E,   _3,   // SE3     030  COPY Fail 3, Model name Error	
      _S,    _E,    _r,   _v,   // serv    031  Service time function //[Running Dir Count,Special,2018/08/17]
    _BLK,    _d,	_i,	  _r,   // DLCDIR_WARN      032  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
	  _U,    _d,	_S,	  _1,   // UD1_Vlim_WARN	033  //Artemis speed limit, James, 20200220
	  _U,    _d,	_S,	  _2,   // UD2_Vlim_WARN	034  
	  _U,    _d,	_S,	  _3,   // UD3_Vlim_WARN	035  
	  _U,    _d,	_S,	  _4,   // UD4_Vlim_WARN	036  
	  _d,    _d,	_S,	  _1,   // DD1_Vlim_WARN	037  
	  _d,    _d,	_S,	  _2,   // DD2_Vlim_WARN	038  
	  _d,    _d,	_S,	  _3,   // DD3_Vlim_WARN	039  
	  _d,    _d,	_S,	  _4,   // DD4_Vlim_WARN	040  	
	  _E,    _F,    _r,   _n,   // EFrn	        041  Exist FWD/REV Warn  //[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
	_BLK,    _S,    _o,   _S,   // SOS	        042  //[Sibocom SOS Warn, James, 2020/04/28]
    _BLK,    _L,    _S, _BLK,   // LS           043  //#15977, LULD detect, James, 2021/04/01
      _S,    _t,    _o,   _b,   // STOb         044  STO Sequence Warning  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14 
      _S,    _t,    _o,   _c,   // STOc         045  STO Short Warning     //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    _BLK,    _S,	_n,	  _7,   // Sensor817	046  //[Artemis Add Sensor819 Function/Special/2022/06/06]
    _BLK,    _S,	_n,	  _8,   // Sensor818	047  //[Artemis Add Sensor819 Function/Special/2022/06/06]
      _b,    _t,    _t,   _A,   // bttA	        048  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
      _b,    _t,    _t,   _n,   // bttn	        049  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
      _b,    _t,    _t,   _S,   // btts	        049  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
    
	/*_BLK,  _BLK,    _c,   _t,	// ct		E68	 CAN Tx Error
	_BLK,  _BLK,    _c,   _r,	// cr		E69  CAN Rx Error
	_BLK,  _BLK,    _c,   _o,	// co		E70  CAN Overwrite
	_BLK,    _c,    _t,   _o,	// cto		E71  CAN Timeout
	  _L,    _d,    _i,   _F,	// Ldif		E72  Position Difference Over
	_BLK,    _E,    _7,   _3,
	_BLK,  _BLK,    _L,   _t,	// Lt		E74  Leveling Timeout
	_BLK,  _BLK,    _L,   _S,	// LS		E75  Leveling Single
	_BLK,    _L,    _o,   _S,	// LoS		E76	 Over Speed
	_BLK,  _BLK,    _d,   _o,	// do		E77	 Door Opened (illegally)
	_BLK,    _d,    _o,   _F,	// dof		E78  Door Open Fail
	_BLK,    _d,    _C,   _F,	// dcl		E79	 Door Close Fail
	_BLK,    _d,    _o,   _t,	// dot		E80  Door Open Timeout
	_BLK,    _d,    _c,   _t,	// dct		E81  Door Close Timeout
	_BLK,    _t,    _u,   _d,	// tud		E82	 Welltune UnDone
	_BLK,    _E,    _8,   _3,
	_BLK,    _r,    _L,   _u,	// rLu		E84  Up Limit Switch
	_BLK,    _E,    _8,   _5,
	_BLK,    _E,    _8,   _6,
	_BLK,    _E,    _8,   _7,
	_BLK,    _r,    _L,   _d,	// rLd		E88  Down Limit Switch
	_BLK,    _E,    _8,   _9,
	_BLK,    _E,    _9,   _0,
	_BLK,    _E,    _9,   _1,
	_BLK,    _S,    _S,   _L,	// SSL		E92	 System Safe Lock
	_BLK,    _S,    _A,   _F,	// SAF		E93	 Safe Loop Lost
	  _S,    _r,    _u,   _n,	// Srun		E94	 Motor Feedback Lost
	_BLK,    _S,    _b,   _r,	// Sbbr		E95  Brake Feedback Lost
	  _S,    _d,    _b,   _P,	// SdbP		E96	 Door Bypass Lost
	_BLK,    _E,    _9,   _7,
	_BLK,    _E,    _9,   _8,*/



// Error Code Table for LED Display
const LEDDATASEG ErrMSG[ERRMAX] = {
    _BLK,    _o,    _c,   _A,	//  ocA         001  //OC when Acceleration                          
    _BLK,    _o,    _c,   _d,   //  ocd         002  //OC when Deceleration                          
    _BLK,    _o,    _c,   _n,   //  ocn         003  //OC on normal speed                            
    _BLK,    _G,    _F,   _F,   //  GFF         004  //Ground Fault                                  
    _BLK,    _o,    _c,   _c,   //  occ         005  //short circuit                                 
    _BLK,    _o,    _c,   _S,   //  ocS         006  //OC when STOP                                  
    _BLK,    _o, _Ubar,   _A,   //  ovA         007  //ov when Acceleration                          
    _BLK,    _o, _Ubar,   _d,   //  ovd         008  //ov when Deceleration                          
    _BLK,    _o, _Ubar,   _n,   //  ovn         009  //ov on normal speed                            
    _BLK,    _o, _Ubar,   _S,   //  ovS         010  //ov when STOP                                  
    _BLK,    _L, _Ubar,   _A,   //  LvA         011  //Lv when Acceleration                          
    _BLK,    _L, _Ubar,   _d,   //  Lvd         012  //Lv when Deceleration                          
    _BLK,    _L, _Ubar,   _n,   //  Lvn         013  //Lv on normal speed                            
    _BLK,    _L, _Ubar,   _S,   //  LvS         014  //Lv when STOP                                  
    _BLK,    _P,    _H,   _L,   //  PHL         015  //Phase Lack                                    
    _BLK,    _o,    _H,   _1,   //  oH1         016  //IGBT                                          
    _BLK,    _o,    _H,   _2,   //  oH2         017  //40HP above                                    
    _t  ,    _H,    _1,   _o,   // tH1o         018  //TH1 open                                      
    _t  ,    _H,    _2,   _o,   // tH2o         019  //TH2 open                                      
    _BLK,    _F,    _A,   _n,   //  Fan         020  //Fan Lock                                      
    _BLK,  _BLK,    _o,   _L,   //   oL         021  //150% 1Min, Inverter                           
    _E  ,    _o,    _L,   _1,   // EoL1         022  //Thermal Relay (Motor1)                        
    _E  ,    _o,    _L,   _2,   // EoL2         023  //Thermal Relay (Motor2)                        
    _BLK,    _o,    _H,   _3,   //  oH3         024  //PTC                                           
    _F  ,    _u,    _S,   _E,   // FuSE         025  //Fuse Error                                    
    _BLK,    _o,    _t,   _1,   //  ot1         026  //Over Torque level 1                           
    _BLK,    _o,    _t,   _2,   //  ot2         027  //Over Torque level 2                           
    _BLK,    _u,    _c,   _1,   //  uc1         028  //Under Torque level 1                          
    _BLK,    _u,    _c,   _2,   //  uc2         029  //Under Torque level 2                          
    _BLK,    _c,    _F,   _1,   //  cF1         030  //EEPROM write Error                            
    _BLK,    _c,    _F,   _2,   //  cF2         031  //EEPROM read Error                             
    _BLK,    _c,    _d,   _0,   //  cd0         032  //Isum AD channel Error                         
    _BLK,    _c,    _d,   _1,   //  cd1         033  //U-phase AD channel Error                      
    _BLK,    _c,    _d,   _2,   //  cd2         034  //V-phase AD channel Error                      
    _BLK,    _c,    _d,   _3,   //  cd3         035  //W-phase AD channel Error                      
    _BLK,    _H,    _d,   _0,   //  Hd0         036  //cc hardward Error                             
    _BLK,    _H,    _d,   _1,   //  Hd1         037  //oc Hardward Error                             
    _BLK,    _H,    _d,   _2,   //  Hd2         038  //ov Hardward Error                             
    _BLK,    _H,    _d,   _3,   //  Hd3         039  //GFF Hardward Error                            
    _BLK,    _A,    _U,   _E,   //  AuE         040  //Auto Tuning Error                             
    _BLK,    _A,    _F,   _E,   //  AFE         041  //PID Feedback Error                            
    _P  ,    _G,    _F,   _1,   // PGF1         042  //PG fbk Error                                  
    _P  ,    _G,    _F,   _2,   // PGF2         043  //PG fbk loss                                   
    _P  ,    _G,    _F,   _3,   // PGF3         044  //PG fbk Over speed                             
    _P  ,    _G,    _F,   _4,   // PGF4         045  //PG fbk deviation Error                        
    _P  ,    _G,    _r,   _1,   // PGr1         046  //PG Ref Error                                  
    _P  ,    _G,    _r,   _2,   // PGr2         047  //PG Ref Loss                                   
    _BLK,    _A,    _c,   _E,   //  ACE         048  //ACI Loss                                      
    _BLK,    _E,    _F, _BLK,   //  EF          049  //External Fault                                
    _BLK,    _E,    _F,   _1,   //  EF1         050  //External Fault 1                              
    _BLK,    _b,    _b, _BLK,   //  bb          051  //Base Block                                    
    _P  ,	 _c,    _o,   _d,   // PcodE        052  //Password                                      
    _c  ,	 _c,    _d,   _E,   // ccodE        053  //SW                                            
    _C  ,    _E,    _0,   _1,   //  CE1         054  //PC Communication Error (illegal command code) 
    _C  ,    _E,    _0,   _2,   //  CE2         055  //PC Communication Error (illegal data address) 
    _C  ,    _E,    _0,   _3,   //  CE3         056  //PC Communication Error (illegal data value)   
    _C  ,    _E,    _0,   _4,   //  CE4         057  //PC Communication Error (Slave device failure) 
    _C  ,    _E,    _1,   _0,   // CE10         058  //PC Communication Error (Time Out)             
    _C  ,    _P,    _1,   _0,   // CP10         059  //PU Communication Error (Time Out)             
    _BLK,    _b,    _F, _BLK,   //  bF          060  //Braking Transistor Fault                      
    _BLK,    _y,    _d,   _c,   //  ydc         061  //Y-Delta connected Error                       
    _BLK,    _d,    _E,   _b,   //  DEB         062  // DEB Error                                    
    _BLK,    _S,    _r,   _y,   //  SRY         063  //Safety relay Error, add by dino, 06/06/2007   
    _BLK,    _M,    _b,   _F,   //  MbF	        064  //Mechanical brake failed                       
    _P  ,    _G,    _F,   _5,   // PGF5	        065  //PG Hardware Error                             
    _BLK,    _M,    _C,   _F,   //  MCF	        066  //Magnetic Contactor Failed                     
    _M  ,    _P,    _H,   _L,   // MPHL         067  //Motor Phase Loss Failed , added by Sampo , 05/
    _C  ,    _A,    _n,   _F,   // CAnF         068  //CAN BUS Failed  // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    _BLK,  _BLK,  _BLK, _BLK,   //              069
    _BLK,  _BLK,  _BLK, _BLK,   //              070
    _P  ,    _G,    _o,   _A,   //              071
    _S  ,    _t,    _L,   _1,   // StL1         072  //Safty torque Loss  // [Safty function, Bernie, 09/22/2011] 
    _P  ,    _G,    _c,   _d,   // PGcd         073
    _P  ,    _G,    _H,   _L,   // PGHL         074
    _P  ,    _G,    _A,   _F,   // PGAF         075 
    _S  ,    _t,    _o, _BLK,   // Sto          076  //Safty torque Loss  // [Safty function, Bernie, 09/22/2011] 
    _S  ,    _t,    _L,   _2,   // StL2         077  //Safty torque Loss  // [Safty function, Bernie, 09/22/2011] 
    _S  ,    _t,    _L,   _3,   // StL3         078  //Safty torque Loss  // [Safty function, Bernie, 09/22/2011] 
    _BLK,  _BLK,  _BLK, _BLK,   //              079
    _BLK,  _BLK,  _BLK, _BLK,   //              080
    _S  ,    _E,    _r,   _v,   //              081  Service time function
    _A  ,    _P,    _H,   _L,   // aPHL         082
    _b  ,    _P,    _H,   _L,   // bPHL         083
    _C  ,    _P,    _H,   _L,   // cPHL         084
    _d  ,    _L,    _C,   _C,   // DLCC         085  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    _BLK,    _L,    _S,   _S,   // LSS          086  //#15977, LULD detect, James, 2021/04/01
    _BLK,    _L,    _S,   _o,   // LSO          087  //#15977, LULD detect, James, 2021/04/01
    _C  ,    _L,    _C,   _E,   // CLCE         088  //#16434 MPHL improvement, Jerry, 2021/06/30
    _S  ,    _t,    _L,   _4,   // STOL4        089  //STOL4 Short Error, power on to reset//#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    _S  ,    _t,    _o,   _r,   // STOr         090  //STOr error at running //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    _S  ,    _t,    _o,   _S,   // STOS         091  //STOS Short error  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
	_S	,	 _n,	_E,   _7,	// Sensor817	092  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	_S	,	 _n,	_E,   _8,	// Sensor818	093  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	_BLK,    _b,    _t,   _t,   // BBT          094  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    _b  ,    _t,    _t,   _E,   // BBTE         095  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    _b  ,    _t,    _t,   _n,   // BBTn         096  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	_BLK,    _A,    _E,   _L,   // AEL          097  //[AFE Error Handle/Lyabryan/2022/03/24]
};

#else

extern const LEDDATASEG ErrMSG[ERRMAX];
extern const LEDDATASEG WarnMSG[(WARNMAX)/*+IED_ERRMAX-ERRMAX)*/];

#endif

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
