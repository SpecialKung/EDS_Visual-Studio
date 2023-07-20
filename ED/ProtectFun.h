/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _ProtectFun_C
   #define PROTECT_EXT 
#else
   #define PROTECT_EXT extern
#endif
/*======= Modules used (included header files) ==================*/

/* Struct Type define =========================================*/

/* Function Call ==============================================*/
PROTECT_EXT void PROTECT_OC(void);
PROTECT_EXT void PROTECT_OV(void);
PROTECT_EXT void PROTECT_GFF(void);
PROTECT_EXT void PROTECT_CC(void);
PROTECT_EXT void PROTECT_OCC(void);
PROTECT_EXT void PROTECT_PHL(void);
PROTECT_EXT void SWDetectPHL(void);		//SCOTTY 09/05/2007
PROTECT_EXT void Thermal_OLCHK(void);
PROTECT_EXT void Over_Torque_CHK(void);
PROTECT_EXT void sw_protect(void);
PROTECT_EXT void sw_brake(void);
PROTECT_EXT void safe_off(void);
PROTECT_EXT void chkamps(void);
PROTECT_EXT void Error_Handel(void);
PROTECT_EXT void EN81addA3(void);   //[change for EN81-1+A3, Bernie, 2015/03/16]

/* Exported Variable List ======================================*/
PROTECT_EXT UBYTE	//FFChkCNT,
              		prt_ubBFChkCnt,
             		//FANChkCNT,
			  		prt_ubPHLCnt,	// CalUBYTE: 5 UBYTE
			  		prt_ubSRYCnt,
			  		prt_ubSRYCnt2,
			  		prt_ubSRYrec,	// SRY fault record
			  		prt_ubOHSCnt,
			  		prt_ubOHRCnt,
			  		prt_ubBRStatus;

PROTECT_EXT SWORD	prt_swCon1Fc,
					prt_swCon2Fc,
					prt_swCon3Fc;

PROTECT_EXT UWORD	PHLChkCNT,
                    FANChkCNT,
                    prt_uwBrkChkCnt1,  //Brake Check Counter, dino, 05/14/2008   //[change for EN81-1+A3, Bernie, 2015/03/16]
                    prt_uwBrkChkCnt2,  //[change for EN81-1+A3, Bernie, 2015/03/16]
                    prt_uwMcChkCnt,	//Manetic Contactor Check Counter, dino, 12/18/2008
                    uwMaxDcbus,		//scotty 09/04/2007
                    uwMinDcbus,		//scotty 09/04/2007					
                    uwDeltaDcbus,	//scotty 09/04/2007
                    uwPHLADLevel,	//scotty 09/04/2007
                    uwPHLCNTsec,
                    prt_uwErrDT,	//Error Output Delay counter, Add by DINO, 10/24/2008
                    prt_uwLVCNT,	// dino, 12/01/2008
                    prt_uwRatio90,
                    prt_uwRatio120,
                    prt_uwRatio180,
                    prt_uwRatio205,
                    uwIacnt,      //[Output Phase Loss 2, Sampo, 2015/05/21]
                    uwIbcnt,      //[Output Phase Loss 2, Sampo, 2015/05/21]
                    uwIccnt,      //[Output Phase Loss 2, Sampo, 2015/05/21]
                    uwIabcCnt,    //[Output Phase Loss 2, Sampo, 2015/05/21]
                    uwStartMphl2cnt;   //[Output Phase Loss 2, Sampo, 2015/05/21]

PROTECT_EXT UWORD   prt_uwRatio140,   //[modify derating function, Bernie, 2012/08/16]
                    prt_uwRatio155;

PROTECT_EXT UWORD   prt_CCcnt;


                    
PROTECT_EXT SWORD	prt_swPeriod;
                    
                    

PROTECT_EXT ULONG	sbk_ulWatt,	// Soft brake turn on timer, dino, 03/08/2007
			  		pwm_ulOL,	// OL  counting value, dino, 03/09/2007
			  		//pwm_ulMOL,	// OL1 counting value, dino, 03/09/2007
//			  		ulOLCNT,	// OL  counting level, dino, 03/09/2007
			  		pwm_ulOL_C,	// OL  counting value for constant torque
//			  		pwm_ulOL_V,	// OL  counting value for variable torque
	                ulOLCNT_C;	// OL  counting level for constant torque by Justin , 2010/03/02 
//			        ulOLCNT_V;	// OL  counting level for variable torque by Justin , 2010/03/02

PROTECT_EXT ULONG_UNION prt_OLIrms,			  
						ulDeltaDcbusLPF;	

//PROTECT_EXT ULONG_UNION prt_OLRecoder;  //[add for UL EoL Verification,Bernie, 2013/04/22]
PROTECT_EXT ULONG_UNION pwm_ulMOL;

PROTECT_EXT SLONG_UNION	IaPuLPF,
                        IbPuLPF,
                        IcPuLPF;



/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
