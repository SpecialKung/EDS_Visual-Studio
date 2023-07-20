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
#ifndef _SpeedReg_C
	#define _SpeedReg_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void Init_SpeedReg(void)
{
    SPR_ubASRCnt 	= 0;
	SPR_slSpdRefPu 	= 0;
	SPR_slSpdFdbPu 	= 0;
    SPR_ulThetaRef 	= SpDt_ulThetaR;
	SPR_ulThetaFdb 	= 0;
	SPR_slSpdInteg 	= 0;
	SPR_swIqseRefPu = 0;
	SPR_IqseRefPuLPF.sl = 0;
	SPR_slSpdRefPu_Old = 0;
	SPR_slspdFFDPu 	= 0;
	SPR_slSpdSatPu 	= 0;
			
	if (pr[CTRLM]==FOCPM){						//ADDED BY SCOTTY 05/10/2007	TORQUE LIMITED
		SPR_swIqseRefLimPu 	= 30000;			//limit Tq_cmd
    	SPR_swIqseFWDMPu 	= 30000;
    	SPR_swIqseFWDRPu 	= 30000;
    	SPR_swIqseREVMPu 	= 30000;
    	SPR_swIqseREVRPu 	= 30000;	
	}
	else{			
		SPR_swIqseRefLimPu 	= 0x7FFF;
    	SPR_swIqseFWDMPu 	= 0x7FFF;
    	SPR_swIqseFWDRPu 	= 0x7FFF;
    	SPR_swIqseREVMPu 	= 0x7FFF;
    	SPR_swIqseREVRPu 	= 0x7FFF;
    }
    SPR_swFFD = 0;				//ADDED BY SCOTTY 	01/04/2007	FEEDDORWARD
    TB1_ulSpdtempPu.ul = 0;		//ADDED BY SCOTTY 	02/09/2007	FEEDDORWARD
	SPR_swSCTEST2 = 0;				//ADDED BY SCOTTY 10/31/2007
	
    EXT_ASROld = EXT_ASR1to2;
    TB1_SpeedReg();
    // [ PPI LPF, Add by DINO, 07/28/2010
    SPR_SpdRefPuLPF.sl = 0;
    SPR_ulSpdRefPuLPF2 = 0;
    SPR_slPIVInteg = 0;
    // ]
}


void TB1_SpeedReg(void)
{
	UWORD uwKp_tmp0,uwKi_tmp0;
	UWORD uwKp_tmp1,uwKi_tmp1,uwKiNew_tmp1;
    UWORD uwKp_tmp2,uwKi_tmp2;
    UWORD uwTqLPG1,uwTqLPG2,uwTqLPG0;
    UWORD uwZSPDLPBW, uwZASRKP, uwZASRKI;
	SLONG slSlope;

	//speed loop controller is (1+Ki/s)*Kp
	//so,Kp + Kp*Ki/s
	//Ki = BW/2000 (real) 2000->2kHz->500us
	//KiPu = 2*pi*BW/(2*pi*2000), automatic adjust
	//     = BW/(2000) or
    //     = (1000/pr[SPI]) / 2000, manual adjust
    //     = 1/(2*pr[SPI]) or 
    //     = (BW/2000) * (1000/pr[SPI])/10, 10 is BW default value
    //     = (BW/2000) * (100/pr[SPI])

	//Kp = 2*pi*BW*J (real)
	//KpPu = 2*pi*2*pi*BW*Jpu*Jb/(polepair*(Tb/Fb)*2^8*10000)
	//	   = BW*Jpu*2*pi*2*pi*Fb*Jb/(polepair*Tb*2^8*10000))
	//	   = BW * KpKiGain * Jpu/256;
	//     = KpPu' * Jpu/256;
	//KpKiGain = ((2*pi)^2*Fb*Jb)/(polepair*Tb*10000)
	//         = (20213 * Fb * Jb) / (polepair*10000*Tb), Q9, 20213 = (2*pi)^2*2^9
    //KpPu' = BW * KpKiGain /2^5; Q4 = Q(0+9-5)

    //Kr = J*Ki (real)
    //KrPu = 2*pi*Ki*Jpu*Jb/(polepair*(Tb/Fb)*2^8*10000)
    //     = (Ki * KrGain) * JmPu/256;
    //     = KrPu' * JmPu/256;
    //KrGain = 2*pi*Fb*Jb/(polepair*Tb*10000)
    //       = (12868*Fb*Jb)/(polepair*10000*Tb), Q11, 12868 = 2*pi*2^11
    //KrPu' = Ki * 2000 * KrGain / 2^24; Q7 = Q(20+11-24)

	// [ Add Zero Speed Gain of Landing, DINO, 08/02/2010
	if (ZEROSTOP == 0){
		uwZSPDLPBW = pr[ZSPDLPBW];
		// [ Separate PPI & Spd Control PI Gain, Add by DINO, 05/16/2011
		if ((uw_SCTEST8<(pr[POS_CTIME]*10)) && ZEROSERVO==1 && (pr[CTRLSEL]&0x2000)==0x0000){
			uwZASRKP = pr[ZASRKP_P];
			uwZASRKI = pr[ZASRKI_P];
		}
		// ]
		else{
			uwZASRKP = pr[ZASRKP];
			uwZASRKI = pr[ZASRKI];
		}
	}
	else{
		uwZSPDLPBW = pr[ZSPDLPBW_L];
		uwZASRKP = pr[ZASRKP_L];
		uwZASRKI = pr[ZASRKI_L];
	}
	// ]

//	SPR_ultmp = U32xU32divU32(20213, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q9
	uwKp_tmp1 = (SPR_uwKpKiGain * pr[SPDLPBW1]) >> 5; //Q4 = Q(9-5)	11-02
    if (uwKp_tmp1 >= 0x7FFF){
        uwKp_tmp1 = 0x7FFF;
    }
	uwKp_tmp2 = (SPR_uwKpKiGain * pr[SPDLPBW2]) >> 5; //Q4 = Q(9-5)	11-03
    if (uwKp_tmp2 >= 0x7FFF){
        uwKp_tmp2 = 0x7FFF;
    }
	uwKp_tmp0 = (SPR_uwKpKiGain * uwZSPDLPBW) >> 5; //Q4 = Q(9-5)	11-11
    if (uwKp_tmp0 >= 0x7FFF){
        uwKp_tmp0 = 0x7FFF;
    }

    uwKi_tmp1 = (((ULONG)pr[SPDLPBW1])<<20) /2000; //Q20, 500us		
   	uwKi_tmp2 = (((ULONG)pr[SPDLPBW2])<<20) /2000; //Q20, 500us
   	uwKi_tmp0 = (((ULONG)uwZSPDLPBW)<<20) /2000; //Q20, 500us

    uwTqLPG1 = (pr[SPDLPBW1] << 2) * 206; 
    uwTqLPG2 = (pr[SPDLPBW2] << 2) * 206;
    uwTqLPG0 = (uwZSPDLPBW << 2) * 206;

	SPR_uw_posCtime = pr[POS_CTIME]<<1;

    if (pr[PriLPG] != 0)
        uwTqLPG0 = U16xU16divU16(uwTqLPG0, 8, pr[PriLPG]);

    if ((pr[SysControl]&0x0001) == 0){ 	//System Control bit0 = 0 (BW/ PID) 	[11-00]	bit0
        uwKp_tmp1 = ((UWORD)uwKp_tmp1 * pr[SPP1]) / 1000; //Q4
        uwKp_tmp2 = ((UWORD)uwKp_tmp2 * pr[SPP2]) / 1000; //Q4
        uwKp_tmp0 = ((UWORD)uwKp_tmp0 * uwZASRKP) / 1000; //Q4			[10-21] 

        if (pr[SPI1] != 0)
            uwKi_tmp1 = U16xU16divU16(uwKi_tmp1, 100, pr[SPI1]);
        else
            uwKi_tmp1 = 0;

        if (pr[SPI2] != 0)
            uwKi_tmp2 = U16xU16divU16(uwKi_tmp2, 100, pr[SPI2]);
        else
            uwKi_tmp2 = 0;

        if (uwZASRKI != 0)												//[10-22] 
            uwKi_tmp0 = U16xU16divU16(uwKi_tmp0, 100, uwZASRKI);
        else
            uwKi_tmp0 = 0;

        if (pr[PriLPG] != 0){
            uwTqLPG1 = U16xU16divU16(uwTqLPG1, 8, pr[PriLPG]);
            uwTqLPG2 = U16xU16divU16(uwTqLPG2, 8, pr[PriLPG]);
            uwTqLPG0 = U16xU16divU16(uwTqLPG0, 8, pr[PriLPG]);
        }
        else{
            uwTqLPG1 = 0;
            uwTqLPG2 = 0;
            uwTqLPG0 = 0;
        }
    }
    
    /* external ASR switch disable*/
    if (EXT_ASREN == 0){
#if DINO  // added by DINO, 01/22/2008
        if (fcmd.uw.hi == 0){
            SPR_uwKpPu = uwKp_tmp0;
            if (pr[CTRLM]==FOCPM) 
            	SPR_uwKpKiPu = ((ULONG)uwKp_tmp0*uwKi_tmp0) >> 12; //Q9 = Q(4+20-15)
            else
            	SPR_uwKpKiPu = ((ULONG)uwKp_tmp0*uwKi_tmp0) >> 15; //Q9 = Q(4+20-15)
            	
            SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKi_tmp0*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
            SPR_uwTqLPG = uwTqLPG0;        
        }
        else if ((fcmd.uw.hi > 0) && (fcmd.uw.hi < pr[SPI1BAND])){
            //Kp
            slSlope = (SLONG)uwKp_tmp1 - (SLONG)uwKp_tmp0;
            slSlope = (slSlope<<16) / pr[SPI1BAND]; //Q4
            SPR_uwKpPu = (SWORD)uwKp_tmp0 + ((slSlope * fcmd.uw.hi)>>16);
            //Ki
            slSlope = (SLONG)uwKi_tmp1 - (SLONG)uwKi_tmp0; 
            slSlope = (slSlope<<16) / pr[SPI1BAND]; //Q8
            uwKiNew_tmp1 = (SWORD)uwKi_tmp0 + ((slSlope * fcmd.uw.hi)>>16);
            
           	SPR_uwKpKiPu = ((ULONG)SPR_uwKpPu*uwKiNew_tmp1) >> 15; //Q9 = Q(4+20-15)
            SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKiNew_tmp1*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
            SPR_uwTqLPG = uwTqLPG1;      
        }
        else if ((fcmd.uw.hi >= pr[SPI1BAND]) && (fcmd.uw.hi <= pr[ASR_F1])){
            SPR_uwKpPu = uwKp_tmp1;
            SPR_uwKpKiPu = ((ULONG)uwKp_tmp1*uwKi_tmp1) >> 15; //Q9 = Q(4+20-15)
            SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKi_tmp1*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
            SPR_uwTqLPG = uwTqLPG1;            
        }
        else if ((fcmd.uw.hi > pr[ASR_F1]) && (fcmd.uw.hi < (pr[ASR_F1]+pr[SPI2BAND]))){
            //Kp
            slSlope = (SLONG)uwKp_tmp2 - (SLONG)uwKp_tmp1;
            slSlope = (slSlope<<16) / pr[SPI2BAND]; //Q4
            slSlope = (slSlope * (fcmd.uw.hi - pr[ASR_F1])) >> 16;
            SPR_uwKpPu = (SWORD)uwKp_tmp1 + slSlope;
            //Ki
            slSlope = (SLONG)uwKi_tmp2 - (SLONG)uwKi_tmp1;
            slSlope = (slSlope<<16) / pr[SPI2BAND]; //Q8
            slSlope = (slSlope * (fcmd.uw.hi - pr[ASR_F1])) >> 16;
            uwKiNew_tmp1 = (SWORD)uwKi_tmp1 + slSlope;
            
            SPR_uwKpKiPu = ((ULONG)SPR_uwKpPu*uwKiNew_tmp1) >> 15; //Q9 = Q(4+20-15)
            SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKiNew_tmp1*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
            SPR_uwTqLPG = uwTqLPG2;
        }
        else{
            SPR_uwKpPu = uwKp_tmp2;
            SPR_uwKpKiPu = ((ULONG)uwKp_tmp2*uwKi_tmp2) >> 15; //Q9 = Q(4+20-15)
            SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKi_tmp2*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
            SPR_uwTqLPG = uwTqLPG2;
        }

#endif
    }
    /* external ASR enable*/   
    else{
        /* external ASR old state */
        if (EXT_ASR1to2 == EXT_ASROld){
            if(EXT_ASR1to2 == 0){ //ASR1
                SPR_uwKpPu = uwKp_tmp1;
                SPR_uwKpKiPu = ((ULONG)uwKp_tmp1*uwKi_tmp1) >> 15; //Q9 = Q(4+20-15)
                SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKi_tmp1*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
                SPR_uwTqLPG = uwTqLPG1;                        
            }
            else{                 //ASR2  
                SPR_uwKpPu = uwKp_tmp2;
                SPR_uwKpKiPu = ((ULONG)uwKp_tmp2*uwKi_tmp2) >> 15; //Q9 = Q(4+20-15)
                SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKi_tmp2*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
                SPR_uwTqLPG = uwTqLPG2;            
            }
            EXT_ASROld = EXT_ASR1to2;
        }
        else{
            if (EXT_ASR1to2 == 1){ //ASR1 -> ASR2
                //Kp
                slSlope = (SLONG)uwKp_tmp2 - (SLONG)uwKp_tmp1;
                slSlope = (slSlope<<16) / 100; //Q4
                slSlope = (slSlope * SPR_ubASRCnt) >> 16;
                SPR_uwKpPu = (SWORD)uwKp_tmp1 + slSlope;            

                //Ki
                slSlope = (SLONG)uwKi_tmp2 - (SLONG)uwKi_tmp1;
                slSlope = (slSlope<<16) / 100; //Q8
                slSlope = (slSlope * SPR_ubASRCnt) >> 16;
                uwKiNew_tmp1 = (SWORD)uwKi_tmp1 + slSlope;

                SPR_uwKpKiPu = ((ULONG)SPR_uwKpPu*uwKiNew_tmp1) >> 15; //Q9 = Q(4+20-15)
                SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKiNew_tmp1*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
                SPR_uwTqLPG = uwTqLPG2;      

            }
            else{                  //ASR2 -> ASR1
                //Kp
                slSlope = (SLONG)uwKp_tmp1 - (SLONG)uwKp_tmp2;
                slSlope = (slSlope<<16) / 100; //Q4
                slSlope = (slSlope * SPR_ubASRCnt) >> 16;
                SPR_uwKpPu = (SWORD)uwKp_tmp2 + slSlope;            

                //Ki
                slSlope = (SLONG)uwKi_tmp1 - (SLONG)uwKi_tmp2;
                slSlope = (slSlope<<16) / 100; //Q8
                slSlope = (slSlope * SPR_ubASRCnt) >> 16;
                uwKiNew_tmp1 = (SWORD)uwKi_tmp2 + slSlope;

                SPR_uwKpKiPu = ((ULONG)SPR_uwKpPu*uwKiNew_tmp1) >> 15; //Q9 = Q(4+20-15)
                SPR_uwKrPu = (U32xU16shlr16(((ULONG)uwKiNew_tmp1*125), SPR_uwKrGain)) >> 4; //Q7 = Q(20+11-24)
                SPR_uwTqLPG = uwTqLPG1;      
            }
            
            SPR_ubASRCnt++;
            if (SPR_ubASRCnt >= 100){
                SPR_ubASRCnt = 0;
                EXT_ASROld = EXT_ASR1to2;            
            }
        }
    }
    SPR_uwKrPu = SPR_uwKrPu * pr[PDFFKr] / 100; //Q9
    
    
    SPR_ulPIVKp = U32xU32divU32(SPR_uwKpPu, pr[PPI_P], 200);
	SPR_slSpdErrPuLimit  = S32xS32divS32(0x7FFFFFFF, 1, (SPR_uwKpPu * 1.2));
    
    //[Special.Kung, 2022/12/12]
    //JES Verify ECN_v91.09 occurre PGF4_ERR at IM
    //SPR_slSpdErrPuLimit value is too small
    SPR_slSpdErrPuLimit  = S32xS32divS32(SPR_slSpdErrPuLimit, 0x10000, 1);
}

void SpeedReg(void)
{
    SWORD SPR_swTqRefPu_tmp, COF_uwMIrateTemp,SPR_swPIVThidaErr,COF_uwMIrateTemp_inv, sw_TortoIqs_inv;
    UWORD uwSOPCTRL;
    SLONG spdPtemp,spdItemp,spdRtemp, spdFFDtemp;
    SLONG spdIFtemp,spdIFRtemp,spdPIFRPtemp;
    SLONG SPR_slSpdErrPu,slSpdRefErrPu;
    SLONG SPR_slIqseRefPu_tmp,SPR_slTqRefPu_tmp,sl_TortoIqs;
    SLONG_UNION SPR_sltemp, PIVUVCnt;
	Float32	flPPI_Cmp_temp;

	// Source of position control, Add by DINO, 06/30/2008
	if ( pr[SOPCTRL]==0 )
		uwSOPCTRL = BRK_RLS;	// control by Pr.02-29
	else if(pr[SOPCTRL]==1)
		uwSOPCTRL = MFI_BRKCHK1;	// Control by MI 42
    else
        uwSOPCTRL = MFI_BRKCHK2;	// Control by MI 44
	// [ Modify PPI control, DINO, 07/27/2010
	if ((pr[SysControl]&0x0080)==0x0080 && (pr[DEBUG_F1]&0x0004)==0x0004){ // Old PPI Control, DINO, 07/29/2010
		if (pr[CTRLM]==FOCPM && RUNDCI==1 && uwSOPCTRL==1 && (uw_SCTEST8<SPR_uw_posCtime)){

			uw_SCTEST8 ++;

			// [ Modify PPI Counter, DINO, 06/03/2010
			DINT();  // Get MTU21.TCNT & SPR_swPIVUVCnt and the same time
			//SPR_slPIVthidaFbk = MTU21.TCNT;
            SPR_slPIVthidaFbk = MTU1.TCNT;
			PIVUVCnt.sw.hi = SPR_swPIVUVCnt;
			EINT();
			PIVUVCnt.sw.low = 0;
			if (PGDIR == 0){
				SPR_slPIVthidaFbk = -SPR_slPIVthidaFbk;
			}

			if (PGDIR == 1){
				SPR_slPIVThidaErr = SPR_slPIVthidaCom - (SPR_slPIVthidaFbk + PIVUVCnt.sl);
			}
			else{
				SPR_slPIVThidaErr = SPR_slPIVthidaCom - (SPR_slPIVthidaFbk - PIVUVCnt.sl);
			}

			if (SPR_slPIVThidaErr > 0x7fff){
				SPR_swPIVThidaErr = 0x7fff;
			}
			else if (SPR_slPIVThidaErr < 0xffff8000){
				SPR_swPIVThidaErr = 0x8000;
			}
			else{
				SPR_swPIVThidaErr = (UWORD)SPR_slPIVThidaErr;
			}

//			SPR_uwTqLPG = U16xU16divU16(16384, 8, pr[ZSPLowpass]);	// Delete by DINO, 07/28/2010
            
			if (abs(SPR_swPIVThidaErr)>=1){
				SPR_sltemp.sw.hi = SPR_swPIVThidaErr;

				if (SPR_swPIVThidaErr > 0)
					spdPtemp = U32xU32divU32(SPR_sltemp.sl, 0x8000 , COF_uwFbRe); //Q31
				else{
					spdPtemp = 0 - (U32xU32divU32(-SPR_sltemp.sl, 0x8000, COF_uwFbRe)); //Q31
				}

				if (spdPtemp > 0)
					SPR_sltemp.sl = U32xU32divU32(spdPtemp, SPR_ulPIVKp , SpDt_ulPG1Npulse); //Q31
				else{
					SPR_sltemp.sl = 0 - (U32xU32divU32(-spdPtemp, SPR_ulPIVKp, SpDt_ulPG1Npulse)); //Q31
				}
			}
			else{ 
				SPR_sltemp.sl = 0; 
			}

			// [ PPI LPF, Add by DINO, 07/28/2010
			SPR_SpdRefPuLPF.sl += (SLONG)(SPR_sltemp.sw.hi - SPR_SpdRefPuLPF.sw.hi) * SPR_uwPPILPG;
            SPR_ulSpdRefPuLPF2 = lowpass_ul(SPR_uwPPILPG, (UWORD)SPR_sltemp.sw.low, SPR_ulSpdRefPuLPF2);
			SPR_slSpdRefPu = ((SLONG)SPR_SpdRefPuLPF.sw.hi<<16) + (SLONG)(SPR_ulSpdRefPuLPF2>>16);
			// ]

			SPR_slSpdRefPu = SPR_sltemp.sl;
		}
	}
	// End of 07/27/2010 ]

//- SCOTTY 2008/02/21
	if (RUNDCI==1 && uw_SCTEST8==SPR_uw_posCtime){
		SPD_slPOScon.sl = SPR_slSpdFdbPu;
		if (SPD_slPOScon.sw.hi == 0){
			SPR_slSpdFdbPu = 0;
		}
	}
//- END SCOTTY 2008/02/21

    //#15977, Spd_err*kp overflow protect, James, 2021/04/01
	SPR_slSpdErrPu = SPR_slSpdRefPu - SPR_slSpdFdbPu; //Q31
	
	if(abs(SPR_slSpdErrPu) > SPR_slSpdErrPuLimit)
	{
		if(SPR_slSpdErrPu >= 0)
		{
			SPR_slSpdErrPu = SPR_slSpdErrPuLimit;
		}
		else
		{
			SPR_slSpdErrPu = -SPR_slSpdErrPuLimit;
		}
	}
    
	slSpdRefErrPu = SPR_slSpdRefPu - SPR_slSpdRefPu_Old; //Q31
    //==============#15977 End==================
    
	//	SPEED comand/feedback
    uw_fcomref = fcmd.uw.hi;
    uw_fcomfbk = fout.uw.hi;	//SPEED fback
    sw_fcomerr = (SWORD)(uw_fcomref - uw_fcomfbk);
	
	// Proportional Gain
	spdPtemp = S32xS16shlr16(SPR_slSpdErrPu, SPR_uwKpPu ); //Q19 = Q(31+4-16) 
	
	// Integral Time
    if (CurSat_flag == 0){ //current saturation
		if (TqSpdMode == 0){	//Speed mode
			spdItemp = S32xS16shlr16(SPR_slSpdErrPu, SPR_uwKpKiPu); //Q24 = Q(31+9-16)

			SPR_slSpdInteg = sl_limit(SPR_slSpdInteg, spdItemp, 0x7FFFFFFF); //Q24 = Q24+Q24
		}
		else					//Toqure mode
			SPR_slSpdInteg = 0;
	}
	if (SPSEARCH==1){
		SPR_slSpdInteg = 0;
	}		

 
/*----------------------------------------------------------------------------------------
--- 				FOCPM SPEED LOOP CONTROL + FEEDFORWARD CONTROL 		--
--- 										    	--
----------------------------------------------------------------------------------------*/
	if (pr[CTRLM]==FOCPM){
		SPR_swTqRefPu_tmp = (SWORD)(sl_limit_modify(spdPtemp, (SPR_slSpdInteg>>5), (SPR_slTqRefLimPu<<5))>>5); //100.00%
		
		SPR_FFD();

		
    	
    	if ((pr[SysControl]&0x0001) == 1){  //System Control bit0 = 1 (control gain calculate)
		    spdRtemp = S32xS16shlr16(SPR_slSpdFdbPu, SPR_uwKrPu);
		    SPR_sltest = spdRtemp>>9;    
    		SPR_swTqRefPu_tmp = (SWORD)( SPR_swTqRefPu_tmp + SPR_swFFD);
			SPR_swTqRefPu_tmp = SPR_swTqRefPu_tmp - SPR_sltest;
    	}
		

#if SCOTTY  /*05/10/2007 */

        if ((pr[DEBUG_F1]&0x0800) == 0x0800){  // Debug flag Bit11 = 1 (Torque control for PM)
        	SPR_swSCTEST0 = pr[TQREF];
        	SPR_swSCTEST1 = (SWORD)(SPR_swSCTEST0*10); 

        	if (SPR_swSCTEST0 > 0){
    			SPR_slSpdRefPu = TqC_swPSpdLimPu<<16;
    			SPR_slSpdErrPu = SPR_slSpdRefPu - SPR_slSpdFdbPu; //Q31	
        		if (SPR_slSpdErrPu <=0){
        			if (abs(SPR_slSpdErrPu)>=0xffff && SPR_swSCTEST2>=0){
        				SPR_swSCTEST2 = SPR_swSCTEST2 - 5;
        			}
        		}
        		else{
        			if (SPR_swSCTEST2 <= SPR_swSCTEST1)
        				SPR_swSCTEST2 = SPR_swSCTEST2 + 10;
        			else
        				SPR_swSCTEST2 = SPR_swSCTEST1;
        		}
        	}
        	else{
    			SPR_slSpdRefPu = 0 - (TqC_swPSpdLimPu<<16);
    			SPR_slSpdErrPu = SPR_slSpdRefPu - SPR_slSpdFdbPu; //Q31	
        		if (SPR_slSpdErrPu >=0){
        			if (abs(SPR_slSpdErrPu)>=0xffff && SPR_swSCTEST2<=0){
        				SPR_swSCTEST2 = SPR_swSCTEST2 + 5;
        			}	
        		}
        		else{
        			if (SPR_swSCTEST2 >= SPR_swSCTEST1)
        				SPR_swSCTEST2 = (SPR_swSCTEST2 - 10);
        			else
        				SPR_swSCTEST2 = SPR_swSCTEST1;
        		}       			
       		}
        	SPR_slIqseRefPu_tmp = (SLONG)SPR_swSCTEST2;
        }  
        else{
	    	// [ Modify the Pre-Load Calculation, DINO, 06/17/2009
			//[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
    		TqC_slTqOfstPu.sl += (SLONG)((SWORD)TqC_swTqOfstPu - TqC_slTqOfstPu.sw.hi) * SPR_uwTqLPG; 
		    //SPR_slTqRefPu_tmp = SPR_slTqRefPu_tmp + TqC_swTqOfstPu; //Q12
	    	SPR_slIqseRefPu_tmp = (SLONG)(SPR_swTqRefPu_tmp + TqC_slTqOfstPu.sw.hi); 	//SCOTTY 2007/08/07  ADD TqC_swTqOfstPu
	    	//SPR_slIqseRefPu_tmp = (SLONG)(SPR_swTqRefPu_tmp + TqC_swTqOfstPu); 	//SCOTTY 2007/08/07  ADD TqC_swTqOfstPu
	    	// ]
	    }
        //[PPI decrease cause Speed error,Jerry.sk,2020/04/15]
		if((ZEROSERVOEND == 1) && (SPR_blPPI_Cmp_Updat_Flag == 0))
		{
			SPR_blPPI_Cmp_Updat_Flag = 1;
			SPR_IqseRefPuLPF.sw.hi += SPR_swTqOfstPu; //Bypass LPF, assuming PPI below the limited
			SPR_swIqseRefPu = SPR_IqseRefPuLPF.sw.hi;
			
			SPR_swPPI_Cmp = SPR_swTqOfstPu;
			SPR_TqOfstPu.sl = 0;
			SPR_swTqOfstPu = 0;
		}

		flPPI_Cmp_temp = SPR_swPPI_Cmp * COF_flPPI_Cmp;
		SPR_slIqseRefPu_tmp = SPR_slIqseRefPu_tmp + (SWORD)flPPI_Cmp_temp;
        //[PPI decrease cause Speed error,Jerry.sk,2020/04/15]

#endif


		
/*  --- END FOCPM SPEED LOOP CONTROL + FEEDFORWARD CONTROL ----------------------------*/

	}
   	else{
// -- «Ý¬d Kr -- 
    	if ((TqSpdMode == 0) && (EXT_TqSpdEN == 0)){
    		//Rtemp = SpdFdb * Kr	
			spdRtemp = S32xS16shlr16(SPR_slSpdFdbPu, SPR_uwKrPu); //Q22 = Q(7+31-16)
    		SPR_sltest = spdRtemp;
    	}
    	else
        	spdRtemp = 0;

		// feedforward compensation	
    	if (pr[SPDFFDGain] != 0){ //System Control [11-00]bit0 = 1  control gain calculate	
			//FFDtemp = LowPass((d/dt)SpdRef)
        	spdFFDtemp = (slSpdRefErrPu >> 3) * 2000; // Q28 = Q(31-3)	
        	SPR_slspdFFDPu = LowPass_Hz(2058, spdFFDtemp, SPR_slspdFFDPu); //Q28, 2058 = 2*pi*80*2^13/2000
        	//SPR_slspdFFDPu = S16xS16divS16(SPR_slspdFFDPu, pr[SPDFFDGain], 100);
        	SPR_slspdFFDPu = S32xS32divS32(SPR_slspdFFDPu, pr[SPDFFDGain], 100);   //[overflow problem, Bernie, 2017/05/09]
    	}
    	else{
        	SPR_slspdFFDPu = 0;
    	}

		// spdIFtemp = I control output + ffd control output - SPEED_fbk*Kr   
    	spdIFtemp = sl_limit(SPR_slSpdInteg, (SPR_slspdFFDPu>>4), 0x7FFFFFFF); //Q24
    	spdIFRtemp = (spdIFtemp>>2) - spdRtemp; //Q22 = Q(24-2)-Q(22)
    	
		// 	spdPIFRPtemp = spdIFRtemp + P controller
		spdPIFRPtemp = sl_limit(spdPtemp, (spdIFRtemp>>3), 0x7FFFFFFF); //Q19 = Q(19)+Q(22-3)

		// Torque output = controller output* J	
    	SPR_slTqRefPu_tmp = S32xS16shlr16(spdPIFRPtemp ,(EsJ_uwJmPu<<1)); //Q12 = Q(19+8+1-16)

		if (pr[TQROFSE]!= 0){	//07-19 Torque command source
    		TqC_slTqOfstPu.sl += (SLONG)((SWORD)TqC_swTqOfstPu - TqC_slTqOfstPu.sw.hi) * SPR_uwTqLPG;  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
		    //SPR_slTqRefPu_tmp = SPR_slTqRefPu_tmp + TqC_swTqOfstPu; //Q12
		    SPR_slTqRefPu_tmp = SPR_slTqRefPu_tmp + TqC_slTqOfstPu.sw.hi; //Q12
		}

    	if (SPR_slTqRefPu_tmp >= 0x7FFF)
	    	SPR_slTqRefPu_tmp = 0x7FFF;	
		else if (SPR_slTqRefPu_tmp <= -0x7FFF)
			SPR_slTqRefPu_tmp = -0x7FFF;

		//SPR_slIqseRefPu_tmp = S16xS16divS16(SPR_slTqRefPu_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)
		SPR_slIqseRefPu_tmp = S32xS32divS32(SPR_slTqRefPu_tmp, 2048, COF_uwKt); //Q15 = Q(12+11-8)  //[overflow problem, Bernie, 2017/05/09]
        sw_TortoIqs_inv = S32xS32divS32(SPR_slIqseRefPu_tmp,COF_uwKt,2048); //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
        swTqInPu_Mon = sw_TortoIqs_inv; //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
    }
/*  --- END FOCIM SPEED LOOP CONTROL -------------------------------------*/		

//  --- 4 PHASE TORQUE LIMITED START--------------------------------------//

	//-----------------------------------------------------
	// TORQUE DECREASE WHEN STOP (Add by DINO, 05/30/2008)
	//-----------------------------------------------------
	if ( STOPDCI==1 && TB1_uwDCICnt>=(pr[DCISTP]*100) ){
		SPR_slIqseLimit -= COF_uwTqSlopePu;
		if ( SPR_slIqseLimit<0 ){ SPR_slIqseLimit = 0; }
		SPR_swIqseFWDMPu = SPR_slIqseLimit;
		SPR_swIqseFWDRPu = SPR_slIqseLimit;
		SPR_swIqseREVRPu = SPR_slIqseLimit;
		SPR_swIqseREVMPu = SPR_slIqseLimit;
	}
	else{
		if ( SPR_slIqseRefPu_tmp>=0 )
			SPR_slIqseLimit = SPR_slIqseRefPu_tmp;
		else
			SPR_slIqseLimit = -SPR_slIqseRefPu_tmp;
	}

    if (SPR_slSpdRefPu >= 0){
		if (SPR_slIqseRefPu_tmp >= (SLONG)SPR_swIqseFWDMPu){
			CurSat_flag = 1;
			SPR_slIqseRefPu_tmp = SPR_swIqseFWDMPu;        
		}
		else if (SPR_slIqseRefPu_tmp <= -((SLONG)SPR_swIqseFWDRPu)){
			CurSat_flag = 1;
			SPR_slIqseRefPu_tmp = -SPR_swIqseFWDRPu;
		}
		else
			CurSat_flag = 0;
	}                
    else{    
    	if (SPR_slIqseRefPu_tmp >= (SLONG)SPR_swIqseREVRPu){
    		CurSat_flag = 1;
    		SPR_slIqseRefPu_tmp = SPR_swIqseREVRPu;        
    	}
    	else if (SPR_slIqseRefPu_tmp <= -((SLONG)SPR_swIqseREVMPu)){
    		CurSat_flag = 1;
			SPR_slIqseRefPu_tmp = -SPR_swIqseREVMPu;
    	}
    	else
    		CurSat_flag = 0;
    }
//---	4 PHASE TORQUE LIMITED END ---------------------------------------//

#if SCOTTY  /* 05/10/2007 */
	if (pr[CTRLM] == FOCPM){
		swTqInPu = SPR_slIqseRefPu_tmp;

		sl_TortoIqs = S32xS32divS32(swTqInPu, COF_uwMIrRe , 10000);		// (Tout/100)*Trated; percentage of rated torque
		COF_uwMIrateTemp = U16xU16divU16(13107 ,100, pr[I_RATE]);	//pr[I_RATE] 00-01	
		//SPR_slIqseRefPu_tmp = S16xS16divS16(sw_TortoIqs, COF_uwMIrateTemp, 100); //dot0 
		SPR_slIqseRefPu_tmp = S32xS32divS32(sl_TortoIqs, COF_uwMIrateTemp, 100); //dot0
        //[ //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
        COF_uwMIrateTemp_inv = S32xS32divS32(SPR_slIqseRefPu_tmp,100,COF_uwMIrateTemp);
        sw_TortoIqs_inv = S32xS32divS32(COF_uwMIrateTemp_inv,10000,COF_uwMIrRe);
        swTqInPu_Mon = sw_TortoIqs_inv;
		//] //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
	}
#endif
// [ Modify the LPF function by DINO, 03/07/2009
	SPR_IqseRefPuLPF.sl += (SLONG)((SWORD)SPR_slIqseRefPu_tmp - SPR_IqseRefPuLPF.sw.hi) * SPR_uwTqLPG;
	SPR_swIqseRefPu = SPR_IqseRefPuLPF.sw.hi;
// ]
		
//	if (pr[PDFFKr] != 0){					//modified by scotty
    if (pr[PDFFKr] != 0 && pr[CTRLM]!=FOCPM){ 
        if (CurSat_flag == 0){ //current saturation
            if (CurSat_first == 1){
                CurSat_first = 0;
                SPR_slSpdErrPu = SPR_slSpdFdbPu - SPR_slSpdSatPu; //Q31
                spdRtemp = S32xS16shlr16(SPR_slSpdErrPu, SPR_uwKrPu); //Q22 = Q(7+31-16)                
                SPR_slSpdInteg = SPR_slSpdInteg + (spdRtemp << 2); //Q24 = Q(24)+Q(22+2)            
            }    
        }
        else{
            if (CurSat_first == 0){
                CurSat_first = 1;
                SPR_slSpdSatPu = SPR_slSpdFdbPu;    //system saturation
            }
        }
    }
   
    SPR_slSpdRefPu_Old = SPR_slSpdRefPu;
}

void TB2_SpeedReg(void)
{
    //SLONG SPR_theatTmp;
	
    //Theta = Theta + DeltaTheta * SPR_slSpdRefPu, (0-360) = (0-2^32)
    // SPR_slSpdRefPu in Q31, COF_ulKTheta in Q16
    // 0x80000000 = 2^31, because Fb scale 100, so COF_ulKTheta sacle 100
//	SPR_theatTmp = S32xS16shlr16((COF_ulKTheta<<1), (SPR_slSpdRefPu/100)); //Q32 = Q(16+1+31-16)
//	SPR_theatTmp = (S32xS16shlr16(COF_ulKTheta, (SPR_slSpdRefPu/50)))>>2; //Q30 = Q(16+1+31-16)-Q2
/*    if (SPR_slSpdRefPu >= 0)
	   SPR_theatTmp = U32xU32divU32_C(COF_ulKTheta, SPR_slSpdRefPu, (50<<16))+1; //Q32 = Q(16+1+31-16)
	else
   	   SPR_theatTmp = 0 - U32xU32divU32_C(COF_ulKTheta, -SPR_slSpdRefPu, (50<<16))-1; //Q32 = Q(16+1+31-16)
	
    SPR_ulThetaRef = SPR_ulThetaRef + SPR_theatTmp;
*/
}

/*--- Feedforward Compensation control 01/04/2007 by SCOTTY -----
-- FFD = Afa* J^ + w * b^
-- Afa unit: 0.01 hz * 2^16
---------------------------------------------------------------*/
void SPR_FFD(void)
{
    SLONG_UNION SPR_sltemp;

    SPR_sltemp.sl = S32xS32divS32(TB1_slSpdAcc, COF_uwSPDPMFFD*pr[SPDFFDGain], 100);
    SPR_swFFD = SPR_sltemp.sw.hi;

}
/*=== End feedforward control ====================*/

#ifdef _SpeedReg_C
    #undef _SpeedReg_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
