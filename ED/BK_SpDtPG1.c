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
#ifndef _SpDtPG1_C
        #define _SpDtPG1_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_SpDtPG1_pr(void)
{
  //  ULONG SpDt_ulFcRe = 10000000; // timer scalar is 10e6
    ULONG SpDt_ulFcRe = MTU2CLK>>1; // timer scalar is 12MHz, DINO, 09/28/2010
    ULONG SpDt_ultmp1;
    ULONG SpdLeveltmp;
    UWORD uwTemp, uw_PGEPPRtemp;

    SpDt_uwPGErrDet = pr[ENCDET] * 200;
    SpDt_uwOvSpdDet = pr[OSPDET] * 200;
    SpDt_uwSpdDeDet = pr[DEVDET] * 200;
    
	if ( pr[PG_TYPE]>=SIN_SIN ){uw_PGEPPRtemp = pr[EPPR]*10;}		//ADDED BY SC 10/11/2007
	else{uw_PGEPPRtemp = pr[EPPR];}

	if ( pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER )
		//MTU2S4.TIER.BYTE &= 0xF7;	// TGIED, Z-pulse capture interrupt disable, Add by DINO, 08/29/2008
		MTU6.TIER.BYTE &= 0xF7;	// TGIED, Z-pulse capture interrupt disable

    uwTemp = U16xU16divU16(uw_PGEPPRtemp, pr[MPGGA], pr[MPGGB]);
    switch(pr[PGINPUT]){
        case 1:
            //MTU21.TMDR.BYTE = 0x04;             // phase counting mode 1
            MTU1.TMDR1.BYTE = 0x04;             // phase counting mode 1
            PGDIR = 1;
            SpDt_ulPG1Npulse = (ULONG)uwTemp << 2; // Q0 4x
            SpDt_ulPG1NpulseNoMx = (ULONG)uw_PGEPPRtemp << 2;
            break;
        case 2:
            //MTU21.TMDR.BYTE = 0x04;             // phase counting mode 1
            MTU1.TMDR1.BYTE = 0x04;             // phase counting mode 1
            PGDIR = 0;
            SpDt_ulPG1Npulse = (ULONG)uwTemp << 2; // Q0 4x
            SpDt_ulPG1NpulseNoMx = (ULONG)uw_PGEPPRtemp << 2;
            break;
		case 3:
            //MTU21.TMDR.BYTE = 0x05;             // phase counting mode 2
            MTU1.TMDR1.BYTE = 0x05;             // phase counting mode 2
            PGDIR = 1;
            SpDt_ulPG1Npulse = uwTemp; // Q0 1x
            SpDt_ulPG1NpulseNoMx = uw_PGEPPRtemp;
            break;
		case 4:
            //MTU21.TMDR.BYTE = 0x05;             // phase counting mode 2
            MTU1.TMDR1.BYTE = 0x05;             // phase counting mode 2
            PGDIR = 0;
            SpDt_ulPG1Npulse = uwTemp; // Q0 1x
            SpDt_ulPG1NpulseNoMx = uw_PGEPPRtemp;
            break;
		case 5:
            //MTU21.TMDR.BYTE = 0x05;             // phase counting mode 2
            MTU1.TMDR1.BYTE = 0x05;             // phase counting mode 2
            PGDIR = 1;
            SpDt_ulPG1Npulse = uwTemp; // Q0 1x
            SpDt_ulPG1NpulseNoMx = uw_PGEPPRtemp;
            break;                  
		default:
	    	//MTU21.TMDR.BYTE = 0x04;             // phase counting mode 1
	    	MTU1.TMDR1.BYTE = 0x04;             // phase counting mode 1
            PGDIR = 1;
            SpDt_ulPG1Npulse = (ULONG)uwTemp << 2; // Q0 4x
            SpDt_ulPG1NpulseNoMx = (ULONG)uw_PGEPPRtemp << 2;
            break;
    }

	

    // Spd   = pulses * 1/(Npulse*(1/Fc)*PulseWidth)
    //               = pulses/PulseWidth * Fc/Npulse
    // SpdPu = ((pulses/PulseWidth) * (Fc/Npulse))/(Fb/100)*2^31, Q31
    //       = (pulses/PulseWidth) * (Fc/((Npulse*Fb)/100))*2^31, Q31
    //               = (pulses/PulseWidth) * Kmt * 2^31, Q31
    
    //SpDt_ultmp1 = (((ULONG)COF_uwFbRe) * SpDt_ulPG1Npulse) / 100;		//DEL SC 10/29/2007	
    SpDt_ultmp1 = U32xU32divU32( COF_uwFbRe, SpDt_ulPG1Npulse, 100);	//ADDED SC 10/29/2007

    if (SpDt_ulPG1Npulse >= 600){   
        // SpdPu = (pulses*2^4/PulseWidth) * Kmt*2^27, Q31
        // Kmt_HiPus  = (Fc*2^27)/((Npulse*Fb)/100), Q27
        SpDt_ulPG1Kmt_HiPus = U32xU32divU32(0x8000000, SpDt_ulFcRe, SpDt_ultmp1); //Q27 = Q(27+0-0)
   		
   // 	  SpDt_ulPG1Kmt_HiPus = U32xU32divU32(0x1000000, SpDt_ulFcRe, SpDt_ultmp1);	//SC 10/26/2007
    }
    else{
        // SpdPu = (pulses*2^14/PulseWidth) * Kmt*2^17, Q31
        // Kmt_LoPus  = (Fc*2^17)/((Npulse*Fb)/100), Q17
        SpDt_ulPG1Kmt_LoPus = U32xU32divU32(0x20000, SpDt_ulFcRe, SpDt_ultmp1); //Q17 = Q(17+0-0)
    }
        
    // Spd   = pulses * 1/(Npulse*500us)
    // SpdPu = (pulses * 1/(Npulse*500us))/(Fb/100)*2^31, Q31
    //       = pulses * (100/(Npulse*500us*Fb))*2^31, Q31
    //               = (pulses) * ((200000*2^31)/(Npulse*Fb)), Q31
    // Kmt_LoSpd = (200000*2^31)/(Npulse*Fb), Q31
    //SpDt_ultmp1 = (ULONG)COF_uwFbRe * SpDt_ulPG1Npulse;				//DEL SC 10/29/2007
    //SpDt_ultmp1 = U32xU32divU32( COF_uwFbRe, SpDt_ulPG1Npulse, 1);		//ADDED SC 10/29/2007  //Bernie mask
    SpDt_ultmp1 = U32xU32divU32( COF_uwFbRe, SpDt_ulPG1Npulse, 2);  //[fix the encoder puls overflow, Bernie, 2016/01/13]
//      SpDt_ulPG1Kmt_LoSpd = U32xU32divU32(0x80000000, 200000, SpDt_ultmp1); //Q31*Q0/Q0
    //SpDt_ulPG1Kmt_100us = U32xU32divU32(0x80000000, 1000000, SpDt_ultmp1); //Q31*Q0/Q0 	SC 10/26/2007  //Bernie mask
    SpDt_ulPG1Kmt_100us = U32xU32divU32(0x80000000, 500000, SpDt_ultmp1); //Q31*Q0/Q0 	 //[fix the encoder puls overflow, Bernie, 2016/01/13]
//	SpDt_ulPG1Kmt_100us = U32xU32divU32(0x80000000, 125000, SpDt_ultmp1); //Q31*Q0/Q0		SC 10/26/2007

    // speed detect method change frequncy
    // how low frequncy has one pulse at the 500us
    // ChanLeRe = 1/(Npulse*500us) * PolePair * 100, real frequency sacling is x100
    //                      = 50000*4/Npulse * PolePair
#if SCOTTY  /* 04/26/2007 */
    SpDt_uwChanLeRe = U32xU32divU32(50000, (COF_ubMPolePair<<2), SpDt_ulPG1Npulse); //Q0
#else
    SpDt_uwChanLeRe = U16xU16divU16((UWORD)50000, (COF_ubMPolePair<<2), SpDt_ulPG1Npulse); //Q0
#endif
//    SpDt_uwChanLeRe = SpDt_uwChanLeRe << 1;

    SpDt_uwChanLeRe = SpDt_uwChanLeRe * 3 >> 1;  // Switch Frequency is 1.5pulse at 500us, DINO, 07/30/2010

    // PolePair*Npulse <-> 360 <-> 2^32
    // KTheta = 2^32*PolePair/Npulse, In Q32    
    SpDt_ulKTheta = U32xU32divU32(0xFFFFFFFF, COF_ubMPolePair, SpDt_ulPG1Npulse); //Q32
        
/* Item 46: Marked,     SpDt_uwPG1ChkCNT = U32xU32divU32(((ULONG)TB2CLK_Hz*100),((ULONG)COF_ubMPolePair*5), ((ULONG)SpDt_ulPG1Npulse*SpDt_uwChanLeRe)); */

    // at low speed, how long have one pulse
    // Time = (one_pulse*COF_ubMPolePair*1000) / (Npulse * fcmd/100), in msec
    //              = (one_pulse*COF_ubMPolePair*1000*100) / (Npulse * fcmd), in msec
    // OnePusTime = (one_pulse*COF_ubMPolePair*1000*100) / Npulse * 5, 5 is 
//      SpDt_uwKOnePusTime = U16xU16divU16((COF_ubMPolePair*100), (1000*5), SpDt_ulPG1Npulse);

    //====== Calculate over speed level ===================//
    if (pr[PGOSPDL] != 0){
	// 0% <= pr[PGOSPDL] <= 120%, default = 115%, 0% disable overspeed detect
        SpdLeveltmp = U32xU32divU32(SpdMaxPu, pr[PGOSPDL], 100);	//10-05
        if ((ULONG)SpdLeveltmp >= (ULONG)0x7FFFFFFF)
            SpDt_slOvSpdLePu = 0x7FFFFFFF;
        else
            SpDt_slOvSpdLePu = (SLONG)SpdLeveltmp;
    }
        
    //====== Calculate speed deviation level ==============//
    if (pr[PGDEVDL] != 0){
        // 0% <= pr[PGDEVDL] <= 50%, default = 30%, 0% disable deviation detect
        SpdLeveltmp = U32xU32divU32(SpdMaxPu, pr[PGDEVDL], 100);                
        if ((ULONG)SpdLeveltmp >= (ULONG)0x7FFFFFFF)
            SpDt_slSpdDeLePu = 0x7FFFFFFF;
        else
            SpDt_slSpdDeLePu = (SLONG)SpdLeveltmp;
    }                                        


   
         
#if SCOTTY
	if (pr[CTRLM]==FOCPM)
		SpDt_uwAnglePeriod = (UWORD)((ULONG)(SpDt_ulPG1NpulseNoMx << 1)/pr[PM_POLES]);
	else
		SpDt_uwAnglePeriod = (UWORD)((ULONG)(SpDt_ulPG1NpulseNoMx << 1)/pr[POLES1]);

	SpDt_uwPGcorrectvalue = (UWORD)(SpDt_ulPG1NpulseNoMx - (ULONG)(SpDt_uwAnglePeriod*COF_ubMPolePair));	//SC 09/26/2007
	PG_Zoffset = U16xU16divU16(SpDt_uwAnglePeriod, pr[Z_OFFSET], 3600);		//added 01/04/2009,DINO
#endif 


}

void Init_SpDtPG1(void)
{
	SpDt_uwPG1CNT_Old		= 0;
	SpDt_uwPG1Wdh_Old		= 0;
	SpDt_ubT0OvCnt_Old		= 0;
	SpDt_uwPG1LoSpdCNT_Old  = 0;
	SpDt_uwPG1CNT_Org		= 0;
	SpDt_uwPG1CNT			= 0;
	SpDt_swPGecycle			= 0;	//ADDED BY SCOTTY	09/26/2007
        
	SpDt_uwPG1CNT_OrgNoMx 	= 0;
        
/* Item 46: Marked,	SpDt_uwPG1CNT_Z1 = 0; */
	SpDt_slSpdFdbPu  		= 0;
	SpDt_ubT0OverCnt = 0;
#if SCOTTY  /* 05/10/2007 */
//	SpDt_ubT1OverCnt 		= 0;		//16384 TEST
//	SpDt_ubT1UderCnt		= 0;		//16384 TEST
	SPR_swPIVUVCnt          = 0;
#endif 	
	SpDt_swPG1CNT_ErrOld 	= 0;
/* Item 46:	SpDt_ubPGLossDtCnt = 0; */
	SpDt_uwPGLossCnt  		= 0;
	SpDt_uwPGLossCnt1 		= 0;
	SpDt_uwPGLossCnt2 		= 0; // Low Speed PG Loss cnt
	SpDt_uwPGF1ErrCnt 		= 0;
	SpDt_uwOvSpdCnt 		= 0;
	SpDt_uwSpdDeCnt 		= 0;
	SpDt_ubPG1PoNePusCnt 	= 0;
        
    SpDt_ub100usCnt 		= 0;
    SpDt_uwPG1100usCNT_Old 	= 0;
    SpDt_sw500usCNT_Err 	= 0;
        
/* Item 46:	SpDt_uwPG100usCNT = 0; */
/* Item 46:	SpDt_ubPGLOSSCnt = 0; */
        
	PGFirst 				= 0;
/* Item	46: PGLOSS = 0; */
	SpDt_uwPGErrTmp 				= 0;
        
    //MTU20.TCNT = 0x0000;

    //MTU21.TCNT = 0xFFFF;

    MTU0.TCNT = 0x0000;

    MTU1.TCNT = 0xFFFF;
//	SpDt_uwPG1100usCNT_Old = MTU21.TCNT;	// add by dino, 01/23/2008

    //MTU20.TSR.BYTE &= 0xEE;             //clear TGFA flag & TCFV flag
    MTU0.TSR.BYTE &= 0xEE;             //clear TGFA flag & TCFV flag
                                                                //TCIEV, timer 0 overflow interrupt enable 
//    MTU20.TIER.BYTE |= 0x11;  //TGIEA, speed capture interrupt enable
    //MTU20.TIER.BYTE |= 0x10;    //TCIEV, overflow count
    //MTU0.TIER.BYTE |= 0x10;    //TCIEV, overflow count // disable TCIV0 to avoid Speed drop JOSH 20170706

	//MTU2.TSTR.BIT.CST1 = 1;
	//MTU2.TSTR.BIT.CST0 = 1;         //PG & Timer counter start
    MTU.TSTRA.BIT.CST1 = 1;
	MTU.TSTRA.BIT.CST0 = 1;         //PG & Timer counter start
        
}

void ISR_SpDtPG1(void)
{    
    DINT(); // for Spd drop JOSH 2017/05/04
    //MTU20.TSR.BYTE &= 0xFE;             //clear TGFA flag
    //MTU20.TIER.BYTE &= 0xFE;    //TGIEA, speed capture interrupt disable
    MTU0.TSR.BYTE &= 0xFE;             //clear TGFA flag
    MTU0.TIER.BYTE &= 0xFE;    //TGIEA, speed capture interrupt disable

	SpDt_ubT0OvCnt_New = SpDt_ubT0OverCnt;
	//SpDt_uwPG1Wdh_New = MTU20.TGRA;
	//SpDt_uwPG1CNT_New = MTU21.TGRA;
    SpDt_uwPG1Wdh_New = MTU0.TGRA;
	SpDt_uwPG1CNT_New = MTU1.TGRA;
    EINT(); // for Spd drop JOSH 2017/05/04
        
}

void TB3_SpDtPG1_LoIv(void)
{    
    UWORD uwPG1LoSpdCNT, uwTemp;
    SWORD sw500usCNT_Errtmp, ub100usCNT_tmp;
    SWORD PG1LoSpd_Errtmp;
    ULONG KmtLoSpd_tmp;
    SLONG PG1DtPoNePus, SpdDeLe_Hi, SpdDeLe_Lo;


    
    
    //======================================================================//
	// speed detect method change frequncy
	// how low frequncy has one pulse at the 500us
	// ChanLeRe = 1/(Npulse*500us) * PolePair * 100, real frequency sacling is x100
	//                      = 50000*4/Npulse * PolePair                             
    //if ((fcmd.uw.hi > SpDt_uwChanLeRe) && (pr[CTRLM] != TQCPG)){
	if ((fcmd.uw.hi > SpDt_uwChanLeRe) && (TqSpdMode == 0))
	{
        TB3_SpDtPG1();
    }
    else
	{    	
        //uwPG1LoSpdCNT = MTU21.TCNT;
        uwPG1LoSpdCNT = MTU1.TCNT;

        DINT();
        sw500usCNT_Errtmp = SpDt_sw500usCNT_Err;
        ub100usCNT_tmp = (SWORD)SpDt_ub100usCnt;
        SpDt_sw500usCNT_Err = 0;
        SpDt_ub100usCnt = 0;
        EINT();

                
        if (PGDIR != 1)
            uwPG1LoSpdCNT = 65535 - uwPG1LoSpdCNT;

        PG1LoSpd_Errtmp = sw500usCNT_Errtmp * COF_ubMPolePair;		//PULSE COUNTER / 500us
        if (PG1LoSpd_Errtmp != 0){
            // where get pulse input at low speed
            PG1DtPoNePus = (SLONG)PG1LoSpd_Errtmp * SpDt_swPG1LoSpdCNT_Err;
            SpDt_swPG1LoSpdCNT_Err = PG1LoSpd_Errtmp;
                        
            if (PG1DtPoNePus < 0){
                SpDt_ubPG1PoNePusCnt ++;
                if (SpDt_ubPG1PoNePusCnt > 11)
                    SpDt_ubPG1PoNePusCnt = 11;
                                
                uwTemp = SpDt_ulPG1Kmt_LoSpd_Wei[SpDt_ubPG1PoNePusCnt];
                KmtLoSpd_tmp = U32xU16shlr16(SpDt_ulPG1Kmt_100us, uwTemp); //Q31
            }
            else{
                SpDt_ubPG1PoNePusCnt = 0;
                KmtLoSpd_tmp = SpDt_ulPG1Kmt_100us;
            }

            if ((PG1LoSpd_Errtmp < 0) && (pr[PGINPUT] == 5))
                PG1LoSpd_Errtmp = -PG1LoSpd_Errtmp;

            if (PG1LoSpd_Errtmp > 0){
	            SpDt_slPG1FdbPu = U32xU32divU32(PG1LoSpd_Errtmp, KmtLoSpd_tmp, ub100usCNT_tmp); 
            }
            else{
	            SpDt_slPG1FdbPu = 0 - U32xU32divU32(-PG1LoSpd_Errtmp, KmtLoSpd_tmp, ub100usCNT_tmp);
            }            
            PGFirst = 0; //first run
/* Item 46: Marked, Change PGF2 detected method, Marked begin
		}
        else{
            SpDt_slPG1FdbPu = 0;

            if ((SPR_slSpdRefPu!=0)&&(PGFirst==1)&&(APRExeFlag==0)){
                if (SpDt_uwPGLossCnt2<SpDt_uwPGErrDet)
                    SpDt_uwPGLossCnt2 ++;       //PG Loss, start count
                else{
                    if (SpDt_uwPGErrTmp==0){
                        SpDt_uwPGErrTmp = PGF2_ERR;   //SpDt_uwPGLossCnt2
                    }
                }
            }
        }

        if ((SPR_slSpdRefPu!=0)&&(NORMALSP==1)&&(APRExeFlag==0)){
            if (EXT_PG2REFMODE==0){
                PG1LoSpd_Errtmp = abs(SpDt_uwPG1LoSpdCNT_Z1 - SpDt_uwPG1LoSpdCNT_Old);
                if ((PG1LoSpd_Errtmp<=3)&&(pr[CTRLM]<TQCPG)){	//09/21
                    if (SpDt_uwPGLossCnt2<SpDt_uwPGErrDet)    // 30000 = 15 * 2000 => 15 sec
                        SpDt_uwPGLossCnt2++;            //PG Loss, start count
                    else{
                        if (SpDt_uwPGErrTmp==0){
                            SpDt_uwPGErrTmp = PGF2_ERR;    //SpDt_uwPGLossCnt2
                        }
                    }
                }
                else
                    SpDt_uwPGLossCnt2 = 0;
            }
        }
Marked END ======================*/
		/* Item 46: Change PGF2 detected method, Begin --------------------*/
            if (pr[CTRLM]!=VF && pr[CTRLM]!=SVC){
				if ((abs(SPR_slSpdRefPu)>=357913)&&(APRExeFlag==0)&&(TqSpdMode==0)&&(STANDBY==0)&&(UCMP == 0)&&(MFI_btTorqDetect==0)&&(BTTx_btTorqDetect==0)){	//357913 = 0.10Hz * 2^31 / 600Hz  //[UCMP function, Bernie, 2016/06/14]  
					if (EXT_PG2REFMODE==0){
					    uwTemp = abs((SWORD)SpDt_uwPG1LoSpdCNT_Old-(SWORD)SpDt_uwPG1LoSpdCNT_Z1);
					    if ((uwTemp<=3)&&(pr[CTRLM]!=TQCPG) && (pr[DEBUG_F1]&0x0800)!=0x0800){
					        if (SpDt_uwPGLossCnt2<SpDt_uwPGErrDet)    // 30000 = 15 * 2000 => 15 sec
					            SpDt_uwPGLossCnt2++;		//PG Loss, start count
					        else{
					        	if (SpDt_uwPGErrTmp==0){
					            	SpDt_uwPGErrTmp = PGF2_ERR;    //SpDt_uwPGLossCnt2
					            }
					        }
					    }
					    else
					        SpDt_uwPGLossCnt2 = 0;
					}
				}
			}
		}
		else{
			SpDt_slPG1FdbPu = 0;
			
			if (pr[CTRLM]!=VF && pr[CTRLM]!=SVC){
				if ((abs(SPR_slSpdRefPu)>=357913)&&(APRExeFlag==0)&&(TqSpdMode==0)&&(STANDBY==0)&&((pr[DEBUG_F1]&0x0800)!=0x0800)&&(UCMP == 0)&&(MFI_btTorqDetect==0)&&(BTTx_btTorqDetect==0)){	//357913 = 0.10Hz * 2^31 / 600Hz  //[UCMP function, Bernie, 2016/06/14]
					if (EXT_PG2REFMODE==0){
					    uwTemp = abs((SWORD)SpDt_uwPG1LoSpdCNT_Old-(SWORD)SpDt_uwPG1LoSpdCNT_Z1);
						if (uwTemp<=3){
					    	if (SpDt_uwPGLossCnt2<SpDt_uwPGErrDet)
						    	SpDt_uwPGLossCnt2 ++;	//PG Loss, start count
							else{
								if (SpDt_uwPGErrTmp==0)
						    		SpDt_uwPGErrTmp = PGF2_ERR;   //SpDt_uwPGLossCnt2
				    		}
						}
					}
				}
			}
		}

		/* Item 46: Change PGF2 detected method, END  =======================*/
        SpDt_slSpdFdbPu = LowPass_Hz(SpDt_uwLoLPG, SpDt_slPG1FdbPu, SpDt_slSpdFdbPu);
        
        SpDt_uwPG1LoSpdCNT_Old = uwPG1LoSpdCNT;
        SpDt_uwPG1CNT_Old = uwPG1LoSpdCNT;
	}

#if DINO  /* 05/19/2008 */
	//====== PG Loss Hardware detect ========//
#if SH7286 //Sean, 01/25/2010
	if (TqSpdMode==1 || (pr[DEBUG_F1]&0x0200)==0x0200 || SpDt_ubPGCard==PGHSD){	// Bit9=1: Don't detect by hardware, DINO, 08/12/2010
		PGLOSS_H = 0;
	}
	else{  // PG type: ABZ
#if NEWIEDCB
		if (PG_LOSS==1 && PG_RST==1){	// High Active, DINO, 06/28/2010, PG_RST=0/1:OPEN/LINE, PG_LOSS is invalid in OPEN  DINO, 09/06/2010
#endif
			PGLOSS_H = 1;
		}
		else 
			PGLOSS_H = 0;
	}
#endif		

	if ( PGLOSS_H==1 ){
		if (SpDt_uwPGLossCnt3<SpDt_uwPGErrDet)
		    SpDt_uwPGLossCnt3 ++;	   //PG Loss, start count
		else{
			if (SpDt_uwPGErrTmp==0)
		    	SpDt_uwPGErrTmp = PGHL_ERR;	// PG Hardware Error, Add by DINO, 10/09/2008 //[modify Error code,Lyabryan,2016/07/21]
		}
	}
	else{
		
        if(HALL_LOSS) 
            SpDt_uwPGLossCnt3 = 0;  //[HALL_LOSS for Error by TB3_SpDtPG1_Err(), Lyabryan, 2015/03/13]

	}
	//====== Absolute Signal Loss Hardware detect ========//
	if ( PGLOSS_ABS==1 ){
    	// [ 15-21 bit6=1, disable Absolute Position detection, DINO, 08/15/2009
    	if ((pr[CTRLSEL]&0x0040) == 0){	//CTRLSEL bit6 = 1
			SpDt_uwPGLossCnt4 = SpDt_uwPGErrDet;
			if (SpDt_uwPGErrTmp==0){
		    	SpDt_uwPGErrTmp = PGHL_ERR;   	// PG Hardware Error, Add by DINO, 10/09/2008  //[modify Error code,Lyabryan,2016/07/21]
		    }
		}
	}
#endif

	//====== Over speed detect ==============//
	if ((pr[PGOSPDL]!=0)&&(TqSpdMode==0)){
       	if (abs(SpDt_slSpdFdbPu)>=SpDt_slOvSpdLePu){
	    	if (SpDt_uwOvSpdCnt <= SpDt_uwOvSpdDet){
	        	SpDt_uwOvSpdCnt ++;
            }
            else{
	    		if (SpDt_uwPGErrTmp==0){
	        		SpDt_uwPGErrTmp = PGF3_ERR;
                }
            }	        
		}
		else{
            if (SpDt_uwOvSpdCnt < SpDt_uwOvSpdDet){
        	    SpDt_uwOvSpdCnt = 0;
            }	   
	   }
    }

	//====== speed deviation detect =========//
	if ((pr[PGDEVDL] != 0)&&(SPSEARCH==0)&&(TqSpdMode==0)&&(UCMP == 0)&&(MFI_btTorqDetect==0)&&(BTTx_btTorqDetect==0)){      //[UCMP function, Bernie, 2016/06/14]
        SpdDeLe_Hi = sl_limit(TB1_slSpdCmdPu, SpDt_slSpdDeLePu , 0x7FFFFFFF);
        SpdDeLe_Lo = sl_limit(TB1_slSpdCmdPu, -SpDt_slSpdDeLePu, 0x7FFFFFFF);

        if (SpDt_uwSpdDeCnt<SpDt_uwSpdDeDet){ //SpDt_uwSpdDeDet = pr[DEVDET] * 200;
            if (SpDt_slSpdFdbPu >= SpdDeLe_Hi)
                SpDt_uwSpdDeCnt ++;
            else if (SpDt_slSpdFdbPu <= SpdDeLe_Lo)
                SpDt_uwSpdDeCnt ++;
            else
                SpDt_uwSpdDeCnt = 0;
        }
	
        if (SpDt_uwSpdDeCnt>=SpDt_uwSpdDeDet){
          	if (SpDt_uwPGErrTmp==0){
               	SpDt_uwPGErrTmp = PGF4_ERR;  //PG fbk deviation Error
            }
        }
    }

}

void TB3_SpDtPG1(void)
{    
    SBYTE SpDt_sbT0OvCnt_Err;
    UBYTE ubT0OvCnt_tmp;
    UWORD uwPG1CNT_tmp,uwPG1Wdh_tmp;
    SWORD PG1Loss_tmp,SpDt_swPG1CNT_Err;
    SLONG slPG1CNT_Errtmp;//, SpdDeLe_Hi, SpdDeLe_Lo;
    ULONG SpDt_ulPG1Wdh_Err;
        
    DINT();
    ubT0OvCnt_tmp = SpDt_ubT0OvCnt_New;
    uwPG1Wdh_tmp = SpDt_uwPG1Wdh_New;
    uwPG1CNT_tmp = SpDt_uwPG1CNT_New;
    EINT();

	if (PGDIR != 1){
		uwPG1CNT_tmp = -uwPG1CNT_tmp;
	}
        
	SpDt_swPG1CNT_Err = uwPG1CNT_tmp - SpDt_uwPG1CNT_Old;
        
	if (SpDt_swPG1CNT_Err != 0){
            
		//====== PG Loss : A or B connect detect ================//
/* Item 46: Marked, Change PGF2 detected method, Marked begin

		if ((PGLOSS==0)&&((Fcmd>SpDt_uwChanLeRe)||(TqC_swTqSetPu!=0))){
			PG1Loss_tmp = SpDt_swPG1CNT_ErrOld + SpDt_swPG1CNT_Err;
			if (PG1Loss_tmp == 0){
				SpDt_ubPGLossDtCnt ++;
				if (SpDt_ubPGLossDtCnt > 5){
					PGLOSS = 1;
				}
				else{
					PGLOSS = 0;
				}
			}
			else{
				SpDt_ubPGLossDtCnt = 0;
			}

			SpDt_swPG1CNT_ErrOld = SpDt_swPG1CNT_Err ;
			SpDt_uwPGLossCnt = 0;
		}               
Marked END ==================*/

		/* Item 46: Change PGF2 detected method, begin-----------------------*/
	    if (pr[CTRLM]!=VF && pr[CTRLM]!=SVC){
	    	if ((abs(SPR_slSpdRefPu)>=357913)&&(APRExeFlag==0)&&(TqSpdMode==0)&&(UCMP == 0)&&(MFI_btTorqDetect==0)&&(BTTx_btTorqDetect==0)){	//357913 = 0.10Hz * 2^31 / 600Hz   //[UCMP function, Bernie, 2016/06/14]  
		    	if (((Fcmd>SpDt_uwChanLeRe)&&(pr[CTRLM]&0x0001)==0x0001)||((pr[CTRLM]==TQCPG)&&(TqC_swTqSetPu!=0)) || (pr[DEBUG_F1]&0x0800)!=0x0800){
		    		PG1Loss_tmp = SpDt_swPG1CNT_ErrOld + SpDt_swPG1CNT_Err;
					SpDt_swPG1CNT_ErrOld = SpDt_swPG1CNT_Err;	
										
					if (PG1Loss_tmp == 0){
					    SpDt_uwPGLossCnt = SpDt_uwPGLossCnt + 2;						
					}
					else{
						if (SpDt_uwPGLossCnt!=0)
							SpDt_uwPGLossCnt = SpDt_uwPGLossCnt - 1;
					}
					
					if (SpDt_uwPGLossCnt>=SpDt_uwPGErrDet){
		    			if (SpDt_uwPGErrTmp==0)
		        			SpDt_uwPGErrTmp = PGF2_ERR;	//SpDt_uwPGLossCnt
					}
				}
			}
		}
		/* Item 46: Change PGF2 detected method, END ========================*/

		//====== PG Loss Detect end =============================//             
                
		SpDt_sbT0OvCnt_Err = ubT0OvCnt_tmp - SpDt_ubT0OvCnt_Old;

		if (SpDt_sbT0OvCnt_Err >= 1)
			SpDt_ulPG1Wdh_Err = ((ULONG)SpDt_sbT0OvCnt_Err <<16) + uwPG1Wdh_tmp - SpDt_uwPG1Wdh_Old;
		else{
			SpDt_ulPG1Wdh_Err = uwPG1Wdh_tmp - SpDt_uwPG1Wdh_Old;
		}
        
        ubRevise = 0x00;// JOSH revise SpdFdb flag clear every 500ms 2017/05/08
		if ((SpDt_ulPG1Wdh_Err & 0x80000000) == 0x80000000){
			SpDt_ulPG1Wdh_Err += 65535;
			ubT0OvCnt_tmp ++;
            ubRevise |= 0x01;// JOSH revise SpdFdb flag 2017/05/08
		}
        
        // JOSH avoid Spd Drop 2017/05/08
        // revise PGwdh if PGwdh>65536
        // normal:PGwdh=6000 if PGerr >1, Error case:T0OvCnt overflow too early
        if((PGFirst==1) && (abs(SpDt_swPG1CNT_Err)>1) && (SpDt_ulPG1Wdh_Err > 65535))
        {
            ubT0OvCnt_tmp -= (SpDt_ulPG1Wdh_Err/65536);
            SpDt_ulPG1Wdh_Err %= 65536;
            ubRevise |= 0x02;
        }// end of JOSH avoid Spd Drop 2017/05/08

		SpDt_uwPG1CNT_Old = uwPG1CNT_tmp;
		SpDt_uwPG1Wdh_Old = uwPG1Wdh_tmp;
		SpDt_ubT0OvCnt_Old = ubT0OvCnt_tmp;

		if (PGFirst==1){
		//SpdFdb = K_MT * PG1CNT_Err / PG1Width_Err * PolePair
			if (SpDt_ulPG1Npulse >= 600){   
			// SpdPu = (pulses*2^4*PolePair/PulseWidth) * Kmt_HiPus, Q31 = Q(4+27) 
				slPG1CNT_Errtmp = ((ULONG)SpDt_swPG1CNT_Err << 4) * COF_ubMPolePair;

				if (slPG1CNT_Errtmp > 0)
					SpDt_slPG1FdbPu = U32xU32divU32(slPG1CNT_Errtmp, SpDt_ulPG1Kmt_HiPus, SpDt_ulPG1Wdh_Err); //Q31
				else{
					SpDt_slPG1FdbPu = 0 - (U32xU32divU32(-slPG1CNT_Errtmp, SpDt_ulPG1Kmt_HiPus, SpDt_ulPG1Wdh_Err)); //Q31

					if (pr[PGINPUT] == 5)
						SpDt_slPG1FdbPu = -SpDt_slPG1FdbPu;
				}
			}
			else{
				// SpdPu = (pulses*2^14*PolePair/PulseWidth) * Kmt_LoPus, Q31 = Q(14+17) 
				slPG1CNT_Errtmp = ((ULONG)SpDt_swPG1CNT_Err << 14) * COF_ubMPolePair;
        
				if (slPG1CNT_Errtmp > 0)
					SpDt_slPG1FdbPu = U32xU32divU32(slPG1CNT_Errtmp, SpDt_ulPG1Kmt_LoPus, SpDt_ulPG1Wdh_Err); //Q31
				else{
					SpDt_slPG1FdbPu = 0 - (U32xU32divU32(-slPG1CNT_Errtmp, SpDt_ulPG1Kmt_LoPus, SpDt_ulPG1Wdh_Err)); //Q31

					if (pr[PGINPUT] == 5)
						SpDt_slPG1FdbPu = -SpDt_slPG1FdbPu;
				}
			}
		}
		// [ First time run high speed feedback should use the LPF SpDt_slPG1FdbPu, DINO, 07/30/2010
		else{
			SpDt_slPG1FdbPu = SpDt_slSpdFdbPu;
            slFdbOld = SpDt_slPG1FdbPu;// JOSH for avoiding speed drop 2017/05/08
		}
		// ]

        // JOSH avoid speed drop 2017/05/08
        // if SpdErr>50% in low speed && SpdErr>20% in high speed,
        // revise SpdFdb and do not revise continuously
        slFdbErr = abs(SpDt_slPG1FdbPu-slFdbOld);
        UBYTE ubPGerr50 = (slFdbErr>abs(slFdbOld/2)) && (abs(SpDt_swPG1CNT_Err)<20) && (abs(SpDt_swPG1CNT_Err)>1);
        UBYTE ubPGerr20 = (slFdbErr>abs(slFdbOld/5)) && (abs(SpDt_swPG1CNT_Err)>=20);
        if((PGFirst==1) && (ubPGrevCnt==0) && (ubPGerr50||ubPGerr20)){
            SpDt_slPG1FdbPu = slFdbOld;
            ubRevise |= 0x04;
            ubPGrevCnt++;
        }
        else{
            ubPGrevCnt = 0;
        }
        swErrTEST = (SpDt_slPG1FdbPu-slFdbOld)/(slFdbOld/100);
        slFdbOld = SpDt_slPG1FdbPu;
        // end of JOSH avoid speed drop 2017/05/08

        SpDt_slSpdFdbPu = LowPass_Hz(SpDt_uwHiLPG, SpDt_slPG1FdbPu, SpDt_slSpdFdbPu);
		PGFirst = 1; //first run
		SpDt_uwPGLossCnt1 = 0;
	}
	else{
		//PG Loss : signal input detect         
/* Item 46: Marked, Change PGF2 detected method, Marked begin
		if (CMDRUN==RUN){
			if (SpDt_uwPGLossCnt1<SpDt_uwPGErrDet)
				SpDt_uwPGLossCnt1 ++;   //PG Loss in high speed, start count
		}

		if ((SpDt_uwPGLossCnt1>=SpDt_uwPGErrDet)&&(APRExeFlag==0)){
			if (SpDt_uwPGErrTmp==0){
				SpDt_uwPGErrTmp = PGF2_ERR;
			}
		}
	}

	if (PGLOSS==1){
		// PG Loss : A or B connect detect
		if (SpDt_uwPGLossCnt<SpDt_uwPGErrDet)
			SpDt_uwPGLossCnt ++;
                
		if ((SpDt_uwPGLossCnt>=20)&&(APRExeFlag==0)){
            if (SpDt_uwPGErrTmp==0){
				SpDt_uwPGErrTmp = PGF2_ERR;
			}
		}
    }
Marked END ==================*/

		/* Item 46: Change PGF2 detected method, begin ----------------------*/
		if (pr[CTRLM]!=VF && pr[CTRLM]!=SVC){
			if ((abs(SPR_slSpdRefPu)>=357913)&&(APRExeFlag==0)&&(TqSpdMode==0)&&((pr[DEBUG_F1]&0x0800)!=0x0800)&&(UCMP == 0)&&(MFI_btTorqDetect==0)&&(BTTx_btTorqDetect==0)){	//357913 = 0.10Hz * 2^31 / 600Hz   //[UCMP function, Bernie, 2016/06/14]
			    if (SpDt_uwPGLossCnt1<SpDt_uwPGErrDet)
			        SpDt_uwPGLossCnt1 ++;	//PG Loss in high speed, start count
				else{
					if (SpDt_uwPGErrTmp==0){
			    		SpDt_uwPGErrTmp = PGF2_ERR;	//SpDt_uwPGLossCnt1
				    }
				}
			}
		}
	}	
		/* Item 46: Change PGF2 detected method, END ========================*/

    if (TqSpdMode != 1){ //not at TQCPG mode
		//======PG Error:SpdFdb contrary detect =//
		if (TB1_slSpdCmdPu==0){
			SpDt_uwPGF1ErrCnt = 0;
		}
		else{
			if((fcmd.uw.hi>=10) && (UCMP == 0)&&(MFI_btTorqDetect==0)&&(BTTx_btTorqDetect==0)){   //[UCMP function, Bernie, 2016/06/14]
				if (SpDt_slSpdFdbPu > 0){
					if (TB1_slSpdCmdPu < 0)
						SpDt_uwPGF1ErrCnt ++;
					else
						SpDt_uwPGF1ErrCnt = 0;
					}
				else if (SpDt_slSpdFdbPu < 0){
					if (TB1_slSpdCmdPu > 0)
						SpDt_uwPGF1ErrCnt ++;
					else
						SpDt_uwPGF1ErrCnt = 0;
				}
			}
			else{
				SpDt_uwPGF1ErrCnt = 0;
			}
		}

		if ((SpDt_uwPGF1ErrCnt >= SpDt_uwPGErrDet)&&(APRExeFlag==0)){
			if (SpDt_uwPGErrTmp==0){
				SpDt_uwPGErrTmp = PGF1_ERR;
			}
		}
	}

	SpDt_uwPG1LoSpdCNT_Old = SpDt_uwPG1CNT;
    SpDt_sw500usCNT_Err = 0;
    SpDt_ub100usCnt = 0;

}

void TB3_PGErrProcess(void)
{
	UWORD Spd2Hz;

    if (CTRLMCHG==0){
        CTRLMCHG = 1;
        VF_swSlip = 0;
        VF_SlipLPF.sl = 0;

        VF_swUout = 0;
        VF_VcompPuLPF.sl = 0;
    
        tq_boost = 0;
        CTRLM_buf = pr[CTRLM];
		pr[CTRLM] = SVC;
    
        Spd2Hz = U32xU32shlr32(((ULONG)COF_uwFbRe<<1), abs(TB1_slSpdCmdPu));
    
        fcmd.uw.hi = Spd2Hz;
        ftemp.uw.hi = Spd2Hz;
    }
    
}

void TB3_SpDtPG1_Err(void)
{       
	UBYTE TmpFlag = 0;      
    //====== PG feedback Error ==================//
    switch(pr[CTRLM]){
		case VFPG:
        case TQCPG:
        case FOCPG:
        case FOCPM:
                
				      if (pr[PGINPUT]==0 && RUNNING){       // [delete PGF1 before run, Lyabryan, 2015/03/23]
					      WGOFF;
					      Error = PGF1_ERR;
					      WGOFF;
	      //				      CMDRUN = STOP;
					      LIFT_ENABLE = 0;				      // Add by DINO, 03/28/2008
					      TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
					      CMDFREE = 1;
				      	}
			//====== PGF1_ERR: PG Feedback Error ==============//
			//====== PGF2_ERR: PG Open Error ==================//
			//====== PGF5_ERR: PG Hardware Error ==============//
	  		if (SpDt_uwPGLossCnt >= SpDt_uwPGErrDet)	/* Item 46: Change PGF2 detected method, 20 is replaced by SpDt_uwPGErrDet */
				TmpFlag = 1;
			else if (SpDt_uwPGLossCnt1 >= SpDt_uwPGErrDet)
				TmpFlag = 1;
			else if (SpDt_uwPGLossCnt2 >= SpDt_uwPGErrDet)
				TmpFlag = 1;
			else if (SpDt_uwPGF1ErrCnt >= SpDt_uwPGErrDet)
/* Item 46:Marked				TmpFlag = 1; */
/* Item 46:Marked			else if (SpDt_ubPGLOSSCnt>=pr[PGDETCNT]) */
				TmpFlag = 1;
			else if (SpDt_uwPGLossCnt3 >= SpDt_uwPGErrDet)	// Add by DINO, 05/19/2008
				TmpFlag = 1;
			else if (SpDt_uwPGLossCnt4 >= SpDt_uwPGErrDet)	// Add by DINO, 06/12/2008
				TmpFlag = 1;
			else
				TmpFlag = 0;

			if ((TmpFlag==1)&&(Error==0)){
				if ((pr[ENCLOSS]==2 || pr[CTRLM]==FOCPM)){	//[detect the fault when driver did't have any Error, Bernie, 2015/10/01]      // Modify by DINO, 05/13/2008    
 					if (SpDt_uwPGErrTmp==PGF2_ERR){
						WGOFF;
						Error = PGF2_ERR;
						WGOFF;
//						CMDRUN = STOP;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
					}
					else if (SpDt_uwPGErrTmp==PGF1_ERR){
						WGOFF;  
						Error = PGF1_ERR;
						WGOFF;
//						CMDRUN = STOP;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
					}
					else if (SpDt_uwPGErrTmp==PGF5_ERR){
						WGOFF;  
						Error = PGF5_ERR;
						WGOFF;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
					}
					else if (SpDt_uwPGErrTmp==PGHL_ERR){  //[modify Error code,Lyabryan,2016/07/21]
						WGOFF;  
						Error = PGHL_ERR;
						WGOFF;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
					}
				}
				else if (pr[ENCLOSS]==1){    //[detect the fault when driver did't have any Error, Bernie, 2015/10/01] 
					if (SpDt_uwPGErrTmp==PGF2_ERR){
						Error = PGF2_ERR; 
						stop();
                        WARNSTOPREC = 1;		//09/05/2007
					}
					else if (SpDt_uwPGErrTmp==PGF1_ERR){
						Error = PGF1_ERR;
						stop(); 
                        WARNSTOPREC = 1;		//09/05/2007
					}                       
					else if (SpDt_uwPGErrTmp==PGF5_ERR){	// Add by DINO, 11/14/2008
						Error = PGF5_ERR;
						stop();
                        WARNSTOPREC = 1;
					} 
					else if (SpDt_uwPGErrTmp==PGHL_ERR){	// Add by DINO, 11/14/2008  //[modify Error code,Lyabryan,2016/07/21]
						Error = PGHL_ERR;
						stop();
                        WARNSTOPREC = 1;
					} 
				}
				else{  //[pr[ENCLOSS] = 0 for Warning, Lyabryan, 2015/03/13]  //else if(pr[ENCLOSS]==0 && pr[CTRLM]!=FOCPM)
				    if ((pr[PROTBIT]&0x0020)==0x0000)	// Bit 5: PG Error Process 
				        TB3_PGErrProcess();

				        WarnDisplaySave();
				        if (SpDt_uwPGErrTmp==PGF2_ERR)
				            WarnCode = PGL_WARN;
				        else if (SpDt_uwPGErrTmp==PGF1_ERR)
					        WarnCode = PGFBK_WARN;
				        else if (SpDt_uwPGErrTmp==PGF5_ERR)		// Add by DINO, 11/14/2008
					        WarnCode = PGL_WARN;  //[modify Error code,Lyabryan,2016/07/21]
					    else if (SpDt_uwPGErrTmp==PGHL_ERR)		// Add by DINO, 11/14/2008  //[modify Error code,Lyabryan,2016/07/21]
					        WarnCode = PGL_WARN;
				}
			}
            
			//====== PGF3_ERR: PG Over Speed ==================//
			if ((SpDt_uwOvSpdCnt >= SpDt_uwOvSpdDet)&&(Error==0)){   
				if (SpDt_uwPGErrTmp==PGF3_ERR){
					if (pr[OSPDWAY]==2){
						WGOFF;
						Error = PGF3_ERR;
						WGOFF;
//						CMDRUN = STOP;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
					}
					else if (pr[OSPDWAY]==1){
						Error = PGF3_ERR;
						stop();
						WARNSTOPREC = 1;		//09/05/2007
 					}
					else{
						WarnDisplaySave();
						WarnCode = OSPD_WARN;
						if ((pr[PROTBIT]&0x0020)==0x0000)   // Bit 5: PG Error Process
							TB3_PGErrProcess();
					}
				}
 			}

			//====== PGF4_ERR: PG Deviation Error =============//
			if ((SpDt_uwSpdDeCnt >= SpDt_uwSpdDeDet)&&(Error==0)){    
				if (SpDt_uwPGErrTmp==PGF4_ERR){
					if (pr[OSPDWAY]==2){
						WGOFF;
						Error = PGF4_ERR;
						WGOFF;
//						CMDRUN = STOP;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    					TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
					}
					else if (pr[OSPDWAY]==1){
						Error = PGF4_ERR;
						stop();
						WARNSTOPREC = 1;			//09/05/2007
					}
					else {
						WarnDisplaySave();
						WarnCode = DEVA_WARN;
						if ((pr[PROTBIT]&0x0020)==0x0000)   // Bit 5: PG Error Process
							TB3_PGErrProcess();
					}
				}
			} 
			break;
		case SVC:
		case VF:
		default:
			
			//if(pr[PG_TYPE]==0){  //[Clear PGF2 warning, Lyabryan, 2015/03/16] //need fix
			    //WarnCode = 0;
			    //uwtest8 = 1500;
			//}
			break;          
	}
}

void TB2_SpDtPG1(void)	//100us obtain:SpDt_ulThetaR
{    
    SWORD SpDt_swtheatTmp, swTemp, sw100usCNT_Err;
    UWORD uwTemp;

	if (ALIGN == 0){			//2007/08/06	SCOTTY
        //MTU21.TCNT = 0;
        MTU1.TCNT = 0;
        SpDt_uwPG1CNT_Org = 0;
    }

// [ Move SpDt_uwPG1CNT setting to INT_CMT1_CMI1(), Modify by DINO, 03/06/2009
/*
    SpDt_uwPG1CNT = MTU21.TCNT;

    MTU20.TSR.BYTE &= 0xFE;             //clear TGFA flag
    MTU20.TIER.BYTE |= 0x01;    		//TGIEA, speed capture interrupt enable per 100us
*/
// ]

    if (PGDIR != 1){
		SpDt_uwPG1CNT = -SpDt_uwPG1CNT;	
	}

    SpDt_swtheatTmp = (SWORD)(SpDt_uwPG1CNT - SpDt_uwPG1CNT_Org);



    if (SpDt_swtheatTmp >= 0){
        if(SpDt_swtheatTmp >= SpDt_uwAnglePeriod){
            SpDt_swtheatTmp = SpDt_swtheatTmp - SpDt_uwAnglePeriod;
            SpDt_uwPG1CNT_Org = SpDt_uwPG1CNT_Org + SpDt_uwAnglePeriod;
            SpDt_swPGecycle++;				//ADDED BY SC 09/26/2007
        }
        APR_uwTheta = SpDt_swtheatTmp;
        SpDt_ulThetaR = U32xU32getlo(SpDt_swtheatTmp, SpDt_ulKTheta); //Q32 = Q(0+32)
    }
    else{
        if((-SpDt_swtheatTmp) >= SpDt_uwAnglePeriod){
            SpDt_swtheatTmp = SpDt_swtheatTmp + SpDt_uwAnglePeriod;
            SpDt_uwPG1CNT_Org = SpDt_uwPG1CNT_Org - SpDt_uwAnglePeriod;
            SpDt_swPGecycle--;				//ADDED BY SC 09/26/2007
        }
        APR_uwTheta = SpDt_swtheatTmp + SpDt_uwAnglePeriod;
        SpDt_ulThetaR = 0xFFFFFFFF - (U32xU32getlo((-SpDt_swtheatTmp), SpDt_ulKTheta)); //Q32 = Q(0+32)
        if (pr[PGINPUT] == 5){
            SpDt_ulThetaR = 0xFFFFFFFF - SpDt_ulThetaR;
        }
    }

//--- SC 09/26/2007	PG accumulate error
    if (abs(SpDt_swPGecycle) >= COF_ubMPolePair ){
    	if (SpDt_swPGecycle > 0){
    		SpDt_swPGecycle = SpDt_swPGecycle - COF_ubMPolePair;
    		SpDt_uwPG1CNT_Org = SpDt_uwPG1CNT_Org + SpDt_uwPGcorrectvalue;
    	}
    	else{
    		SpDt_swPGecycle = SpDt_swPGecycle + COF_ubMPolePair;
    		SpDt_uwPG1CNT_Org = SpDt_uwPG1CNT_Org - SpDt_uwPGcorrectvalue;
    	}
    }
//--- END SC 09/26/2007

	APR_uwThetaPu = U16xU16divU16(APR_uwTheta,65535,SpDt_uwAnglePeriod);

    SpDt_swtheatTmp = (SWORD)(SpDt_uwPG1CNT - SpDt_uwPG1CNT_OrgNoMx);

    if (SpDt_swtheatTmp >= 0){  
        if(SpDt_swtheatTmp >= SpDt_ulPG1NpulseNoMx){
            SpDt_swtheatTmp = SpDt_swtheatTmp - SpDt_ulPG1NpulseNoMx;
            SpDt_uwPG1CNT_OrgNoMx = SpDt_uwPG1CNT_OrgNoMx + SpDt_ulPG1NpulseNoMx;
            APR_uwZpulseCnt++;
            APR_uwPGCycle++;
        }
        if ((pr[DEBUG_F1]&0x0008) != 0x0008)    //[Used For PG ABD Test, Bernie, 10/28/2011]
        APR_uwThetaNoMx = SpDt_swtheatTmp;
    }
    else{
        if((-SpDt_swtheatTmp) >= SpDt_ulPG1NpulseNoMx){
            SpDt_swtheatTmp = SpDt_swtheatTmp + SpDt_ulPG1NpulseNoMx;
            SpDt_uwPG1CNT_OrgNoMx = SpDt_uwPG1CNT_OrgNoMx - SpDt_ulPG1NpulseNoMx;
            APR_uwZpulseCnt++;
            APR_uwPGCycle++;
        }
        if ((pr[DEBUG_F1]&0x0008) != 0x0008)     //[Used For PG ABD Test, Bernie, 10/28/2011]
        APR_uwThetaNoMx = SpDt_swtheatTmp + SpDt_ulPG1NpulseNoMx;
    }

    sw100usCNT_Err = (SWORD)(SpDt_uwPG1CNT - SpDt_uwPG1100usCNT_Old);

    SpDt_sw500usCNT_Err = SpDt_sw500usCNT_Err + sw100usCNT_Err;
    SpDt_ub100usCnt ++;

    SpDt_uwPG1100usCNT_Old = SpDt_uwPG1CNT;

	// [ Add by DINO, 05/12/2009
	SpDt_uwPG1CNT_Save = SpDt_uwPG1CNT_Org;
	// ]
}

void PGDIR_Detect(void){	//[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]


    SWORD swPGCDerr,swPGABerr,swPGABerr_LPF_err,swPGCDerr_LPF_err;
    UWORD uwPGABin;
    UWORD uwPGCDin;
    UBYTE i,j;
    //UWORD PGCDinn_C[100];


    uwPGABin = MTU1.TCNT;
    uwPGCDin = (hsd_stPgReplyOut.uwAngle)<<3;//hsd_stPgReplyOut.uwAngle;//ANGLE_BALANCE_TAKE;





    if((uwPGCDin!=SpDt_uwPGCDin_old)){ //do as error detact //&&(SpDt_uwNoground_CNT==0)
        swPGCDerr = (SWORD)(uwPGCDin - SpDt_uwPGCDin_old);
        PGCDerr_LPF.sl += ((swPGCDerr>>3) - PGCDerr_LPF.sw.hi)*(6553); // Lowpass
    }
//    if(uwPGABin!=SpDt_uwPGABin_old){
        swPGABerr = (SWORD)(uwPGABin - SpDt_uwPGABin_old);
        PGABerr_LPF.sl += (swPGABerr - PGABerr_LPF.sw.hi)*(6553);
    




   



  if(((abs(slMotorHz)>=(pr[MFBASE1]/10))||(Fcmd>20))&&RUNNING){//&&(SpDt_uwNoground_CNT>3)

      if((abs(PGABerr_LPF.sw.hi)>2)){	// C,D phase inverse
          if(PGABerr_LPF.sw.hi>0){
              if(PGCDerr_LPF.sw.hi<0){
                  SpDt_swNoground_CNT++;
                  if(SpDt_swNoground_CNT>=200)
                      SpDt_swPGCDerr_Detect = 1;
                  if(SpDt_swPGCDerr_Detect){
                      WGOFF;
                      Error = PGcd_ERR; 
                      stop();
                  }
              }
              else{                
                  SpDt_swNoground_CNT--;
                  if(SpDt_swNoground_CNT<=0)
                      SpDt_swNoground_CNT = 0;
              }
          }
          else if(PGABerr_LPF.sw.hi<0){
              if(PGCDerr_LPF.sw.hi>0){
                  SpDt_swNoground_CNT++;
                  if(SpDt_swNoground_CNT>=200)
                      SpDt_swPGCDerr_Detect = 1;
                  if(SpDt_swPGCDerr_Detect){
                      WGOFF;
                      Error = PGcd_ERR; 
                      stop();
                  }
              }
              else{                
                  SpDt_swNoground_CNT--;
                  if(SpDt_swNoground_CNT<=0)
                      SpDt_swNoground_CNT = 0;
              }                
          }
      }
  }

    SpDt_uwPGCDin_old = uwPGCDin;
    SpDt_uwPGABin_old = uwPGABin;


}

//[Rationa 362631, Special.Kung]
void TB3_AccFunction(void)
{
    UWORD uwCnt, uwLPF;
	ULONG ultmp;
	SWORD swAccTemp1;
    SLONG slAccTemp1, slAccTemp2, slAccTemp3;


    uwCnt = pr[ACC_SampleRate]/5;
    uwLPF = pr[ACC_LPF];

	ultmp = (ULONG)((pr[Lift_SPD])*100/(pr[FMAX]));	

	TB3_uwSampleRate = TB3_uwSampleRate+1;

	if(uwCnt<=1)
	{
		uwCnt=0;
	}
	else
	{
		uwCnt = uwCnt+1;
	}

    if(TB3_uwSampleRate>=uwCnt)
    {
        TB3_uwSampleRate = 0;

        /************************************先量化再計算Acc************************************/
        //swAccTemp1 = ((SLONG)COF_uwFbRe * (SpDt_slSpdFdbPu>>15))>>14;
        //TB3_AccCmdTemp_LPF.sl += (swAccTemp1 - TB3_AccCmdTemp_LPF.sw.hi)*(uwLPF); // Lowpass
        
		//TB3_swAccCmdOpt  = TB3_AccCmdTemp_LPF.sw.hi - TB3_swAccCmdCalculOld;

		//TB3_swAccCmdCalculOld = TB3_AccCmdTemp_LPF.sw.hi;
        /************************************先量化再計算Acc************************************/


        /************************************先計算Acc再量化************************************/
		slAccTemp1 = SpDt_slSpdFdbPu*1832;
		slAccTemp2 = TB3_slAccCalculOld*1832;

		slAccTemp3 = (slAccTemp1-slAccTemp2);
		swAccTemp1 = ((SLONG)COF_uwFbRe * (slAccTemp3>>15))>>18;
        //TB3_slAccTemp2 = SpDt_slSpdFdbPu - TB3_slAccCalculOld;
        //TB3_swAccTemp2 = ((SLONG)COF_uwFbRe * (TB3_slAccTemp2>>15))>>14;

        TB3_AccFbTemp_LPF.sl += (swAccTemp1 - TB3_AccFbTemp_LPF.sw.hi)*(uwLPF); // Lowpass
		TB3_swAccOpt = TB3_AccFbTemp_LPF.sw.hi;

		TB3_swAccOpt = (TB3_swAccOpt*ultmp)>>2;

        TB3_slAccCalculOld = SpDt_slSpdFdbPu;
        /************************************先計算Acc再量化************************************/


    }    
}
//[Rationa 362631, Special.Kung]

#ifdef _SpDtPG1_C
    #undef _SpDtPG1_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
