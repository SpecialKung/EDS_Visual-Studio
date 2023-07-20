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
#ifndef _ProtectFun_C
	#define _ProtectFun_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void PROTECT_OC(void)
{
    WGOFF;
    if (Error==0){
        if (RUNNING==RUN){
            if (NORMALSP==1 || STtune==1 || MPHL_DET==1)  // DINO, 03/25/2010
                Error = ocn_ERR;
            else if (ACCODEC==ACCON)
                Error = ocA_ERR;
            else if (ACCODEC==DECON)
                Error = ocd_ERR;
        }
        else
            Error = ocS_ERR;
    }
    WGOFF;

#if 1	// add wgoff interception flag, Sean, 11/18/2010
	prt_ubWgEna = 0;
#endif
}

void PROTECT_OV(void)
{
    if (dcbusAD > OVS4ad){
        WGOFF;
        if (Error==0){
            if (RUNNING==RUN){
                if (NORMALSP==1 || STtune==1 || MPHL_DET==1)  // DINO, 03/25/2010
                    Error = ovn_ERR;
                else if (ACCODEC==ACCON)
                    Error = ovA_ERR;
                else if (ACCODEC==DECON)
                    Error = ovd_ERR;
            }
            else
                Error = ovS_ERR;
        }
        WGOFF;
    }

#if 1	// add wgoff interception flag, Sean, 11/18/2010
	prt_ubWgEna = 0;
#endif
}

void PROTECT_GFF(void) 
{
    WGOFF;
    if (Error==0)  /* Add by dino, 06/13/2007 */
       Error = GFF_ERR;     
       WGOFF;

#if 1	// add wgoff interception flag, Sean, 11/18/2010
	prt_ubWgEna = 0;
#endif
}

void PROTECT_CC(void)
{    
	if ((pr[PROTBIT]&0x0080)==0x0000){	// Bit 7: disable cc function
    	WGOFF;
    	CCSET = 1;
    	CC4OL1 = 1;
    	CC4OL = 1;
    	CC4ACCEL = 1;
        ZEROC = 1;
        CC4display = 1;    //[CC Display, Bernie, 2017/04/12]
        CC4KeyPad = 1;
        prt_CCcnt = 5;
    }

#if 1	// add wgoff interception flag, Sean, 11/18/2010
	prt_ubWgEna = 0;
#endif
}

void PROTECT_OCC(void)
{
    WGOFF;
    if (Error==0)  /* Add by dino, 06/13/2007 */
        Error = occ_ERR;
    WGOFF;

#if 1	// add wgoff interception flag, Sean, 11/18/2010
	prt_ubWgEna = 0;
#endif
}

//PHL protect by DC bus detect		modify SCOTTY 2007/09/05
void SWDetectPHL(void)		//20ms execute
{
    // phase loss detection (PHL)
    uwDeltaDcbus = uwMaxDcbus - uwMinDcbus;

    if (RUNNING==RUN){
        if ((((UWORD)PHLbusReLPF.sw.hi < pr[DCBRK4V]) || (TB1_uwPhi < 666))&&(pr[HPSPEC] < VFD_SINGLEPHASE)){      //[Single phase input, Bernie, 01/19/2012]
            // DcbusRe < dc brake level, PF angle < 80 degree
            ulDeltaDcbusLPF.ul = lowpass_ul(PHL_LPG,uwDeltaDcbus,ulDeltaDcbusLPF.ul);
            if (ulDeltaDcbusLPF.uw.hi>=uwPHLADLevel){
                PHLACTIVE = 1;
                ulDeltaDcbusLPF.ul = 0;
            }
        }
        else{
            PHLACTIVE = 0;
            ulDeltaDcbusLPF.ul = 0;
        }
    }
    else{
        PHLACTIVE = 0;
        ulDeltaDcbusLPF.ul = 0;
    }
    
//    uwMaxDcbus = dcbusAD;       // initial maxdcv and mindcv   del 10/17/2007
	uwMaxDcbus = dcbusDC;		//SCOTTY 10/17/2007
    uwMinDcbus = uwMaxDcbus;

}

//PHL protect by DC bus detect		modify SCOTTY 2007/09/05
void PROTECT_PHL(void)  // 1ms execute
{
    ULONG ultmp;
    UWORD uwTemp;
/*
    if (CMDRUN==RUN){
//        uwTemp = dcbusAD;		//del 10/17/2007
		uwTemp = dcbusDC;		//SCOTTY 10/17/2007
        if (uwTemp>=uwMaxDcbus)
            uwMaxDcbus = uwTemp;
        else if (uwTemp<=uwMinDcbus)
            uwMinDcbus = uwTemp;
    }
*/   
    ultmp = ((ULONG)pr[PHL_T])*10;

    if (PHLACTIVE==1){
        if (PHLChkCNT <= ultmp)
       		PHLChkCNT ++;
       	else{
            if (pr[PHL]==0){
                if ((WarnCode==0)&&(Error==0)){
        			Keypad_PageTmp = Keypad_Page;
        			Keypad_Page = WarnPAGE;
        			WarnCode = PHL_WARN;
        		}
            }
            else if (pr[PHL]==1){
       			stop();
       			Error = PHL_ERR;
       			WARNSTOPREC = 1;
            }
            else if (pr[PHL]==2){
                Error = PHL_ERR;
//      	        CMDRUN = STOP;
				LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
   				TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
       	        CMDFREE = 1;
            }
        }
		prt_ubPHLCnt++;
    } //PHLACTIVE==1
   	else{
   		PHLChkCNT = 0;
   		if ((WarnCode==PHL_WARN)&&(Error==0)){
       		WarnCode = 0;
       		Keypad_Page = Keypad_PageTmp;
   		}
   	}
}
/*	//PHL protect by hard circuit AD detect  delete SCOTTY 2007/09/05
void PROTECT_PHL(void)
{
    if (PHLChkCNT >= pr[PHL_T]){
        if (pr[PHL]==0){
            if ((WarnCode==0)&&(Error==0)){
				Keypad_PageTmp = Keypad_Page;
				Keypad_Page = WarnPAGE;
				WarnCode = PHL_WARN;
	    	}
        }
        else if (pr[PHL]==1){
            if ((WarnCode==0)&&(Error==0)){
				Keypad_PageTmp = Keypad_Page;
				Keypad_Page = WarnPAGE;
				WarnCode = PHL_WARN;
	    	}
	    	stop();
//	    	Error = PHL_ERR;					//SCOTTY delete 2007/08/10
        }
        else if (pr[PHL]==2){
	    	Error = PHL_ERR;					
   	    	CMDRUN = STOP;
   	        CMDFREE = 1;          	
        }
    }
}
*/


/*-------------- Thermo Preventation for Inverter and Motor ------------------------------*/
void Thermal_OLCHK(void)
{
    UWORD ax,bx;
    UWORD I_Level,M_Level;
#if DINO
//----------------------------------------------------------------------------
//      60 Sec @ over 50%            3 Sec @ over 100 %
//
//      Pr00_12 = 0 --------------  100 %
//      Pr00_12 = 1 --------------  125 %
//
//----------------------------------------------------------------------------
    ULONG ulMOLwet, ulMOLwet_C, ulMOLwet_V ; // For OL modify, by Justin , 2010/02/26
    UWORD uwImP , uwRated, uwRated_C, uwRated_V ; 
    SWORD swError, swError_C, swError_V ;
    UBYTE HPSPEC_temp;

	uwRated_C = 100;  // Constant Torque    // For OL modify, by Justin , 2010/02/26
//	uwRated_V = 125;  // Variable Torque
       
	// [ Modify Derating Function, DINO, 09/01/2010
	/*=====  Io Derating for High Carry Frequency  =======
	=    	Carry 	Frame D	  Frame C
	=	      0k	 100%	   100%
	=	      8k	 100%	   100%
	=	     10k	  90%	   100%
        =         15k	  65%	    80%        
	=====================================================*/
	HPSPEC_temp = pr[HPSPEC];      //[Single phase input, Bernie, 01/19/2012]
    if(pr[HPSPEC]>VFD_SINGLEPHASE)
        HPSPEC_temp-=VFD_SINGLEPHASE;
	//if (pr[HPSPEC] <= 17){           // frame C ;  // For OL modify, by Justin , 2010/02/26   
	if (HPSPEC_temp <= 17){           // frame C ;  // For OL modify, by Justin , 2010/02/26   
		if (pr[SETCRF] >= 10){
        	uwRated_C = ((15 - pr[SETCRF]) * 4 + 80);
//        	uwRated_V = (((15 - pr[SETCRF]) * 4 + 88) * uwRated_V + 50) / 100;         
		}
	}
	else {     // frame D/E ;   // For OL modify, by Justin , 2010/02/26
		if (pr[SETCRF] >= 8){            
        	uwRated_C = ((15 - pr[SETCRF]) * 5 + 65);
//        	uwRated_V = (((15 - pr[SETCRF]) * 5 + 75) * uwRated_V + 50) / 100;
		}
	}    

	prt_uwRatio90  = (ULONG)uwRated_C * 1365 *  90 / 10000;
	prt_uwRatio120 = (ULONG)uwRated_C * 1365 * 120 / 10000;
	prt_uwRatio180 = (ULONG)uwRated_C * 1365 * 180 / 10000;
	prt_uwRatio205 = (ULONG)uwRated_C * 1365 * 205 / 10000;
	// ]

    //[modify derating function, Bernie, 2012/08/16]
    prt_uwRatio140 = (ULONG)uwRated_C * 1365 *  140 / 10000;
    prt_uwRatio155 = (ULONG)uwRated_C * 1365 *  155 / 10000;

    if(CC4display == 1){//[CC Display, Bernie, 2017/04/12]
        uwImP = 180;
    }
    else{
   	    uwImP = prt_OLIrms.uw.hi / 109;  // Modify by dino, 08/21/2007
    }
   	//uwImP = (ULONG)uwImP * 931 >> 10;	// New IED Irated is 110%, 1/1.1*1024=931, DINO, 09/06/2010	// OH/OL update

    // For OL modify, by Justin , 2010/02/26
    swError_C = (SWORD)(uwImP - uwRated_C);
//	swError_V = (SWORD)(uwImP - uwRated_V);
    ulMOLwet_C = (SLONG)swError_C * swError_C;
//	ulMOLwet_V = (SLONG)swError_V * swError_V;

    // Constant Torque, For OL modify, by Justin , 2010/04/30
    if (swError_C > 0){
	    if (swError_C > 100){  // 220%: 0.24sec
	    	ulMOLwet_C = ulMOLwet_C * (5 + ((swError_C-100) * 45 + 10) / 20);
	    }
	    else if ( swError_C > 70 ){  // 200%: 3.0sec
	    	ulMOLwet_C = ulMOLwet_C * (1 + ((swError_C-70) * 4 + 15) / 30);
	    }
	    pwm_ulOL_C += ulMOLwet_C ;						// 150%: 60.0sec
    }
    else {
        if (pwm_ulOL_C > ulMOLwet_C){
        	pwm_ulOL_C -= ulMOLwet_C;
        }
        else {
        	pwm_ulOL_C = 0;
        }
    }
//===================================================================
// Motor OL1 curve preventation
// called by 50ms Timebase
//-------------------------------------------------------------------
//
//  Motor			    			Motor
//  rated			    			rated
// current			   				current
//      ^                               ^
//  100%|     _____________	    	100%|__________________
//      |    /							|
//      |   /							|
//      |  /							|
//      | /								|
//   40%|/								|
//      |								|
//      |_____|____________				|_____|____________
//           50Hz			     			50Hz
//
//	   pr[OL1_SL]==0		   pr[OL1_SL]==1
// 	    ( Derate )			   ( No Derate )
//
//===================================================================

   if ( pr[EOL1_SL]==2 )  {	// pr[EOL1_SL]==2, Non active
      pwm_ulMOL.ul = 0;
   }
   else {
		uwRated = COF_uwMIratePu ;
		if ( pr[EOL1_SL]==0 ) {
			if (fout.uw.hi < 5000 ){	// from 40% to 100% Fbas
				uwRated = U16xU16divU16( fout.uw.hi, 600, 5000 ) + 400 ;
				uwRated = U16xU16divU16( uwRated, COF_uwMIratePu, 1000 ) ;	// uwRated = 40.00%~100.00% COF_uwMIratePu
			}
		}

		//------------------------------------------------------
		// uwImP = Im/motor overload level * 100%
		// uwImP = (ULONG)uwImP*100/uwRated;
		//------------------------------------------------------

		//---if motor overload current less 1.00% of drive rated
		//if ( uwRated < 131 ) { uwImP = 0; }
		if ( uwRated < 109 ) { uwImP = 0; }					//DINO
//      else { uwImP = (ULONG)Ismax_uwPu * 120 / uwRated; }	// uwImP : 100=motor Irated
		else { uwImP = (ULONG)prt_OLIrms.uw.hi * 120 / uwRated; }	// 2007/08/06	SCOTTY

		if ( uwImP > 110 ) {
			ulMOLwet = (ULONG)uwImP * uwImP - 10000;
			pwm_ulMOL.ul += ulMOLwet;
		}
		else if ( uwImP < 95 ) {
			ulMOLwet = 10000 - uwImP * uwImP;
			if ( pwm_ulMOL.ul > ulMOLwet ) { pwm_ulMOL.ul -= ulMOLwet; }
			else { pwm_ulMOL.ul = 0; }
		}
        pr[EOL_RECODHI]  = pwm_ulMOL.uw.hi;   //[add for UL EoL Verification,Bernie, 2013/04/22]
        pr[EOL_RECODLO]  = pwm_ulMOL.uw.low;
	}
#else
    /*------ Inverter OL curve preventation (To protect Inverter) ----------*/
    if (pr[CTSEL]==0)
        ax = COF_uwCTIratePu;
    else
        ax = COF_uwVTIratePu;
        
    I_Level = U16xU16divU16(Ismax_uwPu, 100, COF_uwCTIratePu);
        
    if (I_Level > 100){                   //100% rated current
        if (TB1_uwOLCnt < OLCOUNT){
            if (I_Level < (102+92)){                
                if (CC4OL==1){
                    TB1_uwOLCnt = TB1_uwOLCnt + 480;          // after 5 sec, trip oL (when CC)
                    CC4OL = 0;
                }
                else
                    TB1_uwOLCnt = TB1_uwOLCnt + ol[(I_Level-100)];
            }
            else
                TB1_uwOLCnt = TB1_uwOLCnt + 1200;             // after 2 sec, trip oL (above 200% rated)
        }
    }
    else {
        if (I_Level > 10) {
            bx = ol[(100-I_Level)] + 1;
            if (TB1_uwOLCnt <= bx)
                TB1_uwOLCnt = 0;
            else
                TB1_uwOLCnt = TB1_uwOLCnt - bx;
        }
        else {
            if (TB1_uwOLCnt <= 1200)
                TB1_uwOLCnt = 0;
            else
                TB1_uwOLCnt = TB1_uwOLCnt - 1200;
        }
    }

    /*------ Motor OL1 curve preventation (To protect Motor) ---------------*/
    if (OLSEL != 2) {
        if (OLSEL == 0)                     // Constant Torque
            bx = 100 * mspec;
        else {
            if (fout.uw.hi >= 5000)    		// Variable Torque, fbase = 50.00Hz
              bx = 100 * mspec;
            else
              bx = ((((ULONG)fout.uw.hi*60)/5000)+40) * mspec; // from 40% to 100%
        }

        // scaling to motor rated current
        M_Level = U16xU16divU16(Ismax_uwPu,100,COF_uwMIratePu);

        if (M_Level > 102) {
            if (mcount.ul < ((ULONG)OL1COUNT*OLDelayT)) {
                if (M_Level < (102+92)){
                    if (CC4OL1 == 1){
                        mcount.ul = mcount.ul + 255;
                        CC4OL1 = 0;
                    }
                    else
                        mcount.ul = mcount.ul + ol[(M_Level-102)];
                }
                else
                    mcount.ul = mcount.ul + 255;
            }
        }
        else {
            if (M_Level > 10) {
                bx = ol[(102-M_Level)] + 1;
                    if (mcount.ul <= bx)
                        mcount.ul = 0;
                    else
                        mcount.ul = mcount.ul - bx;
            }
            else {
                if (mcount.ul <= 255)
                    mcount.ul = 0;
                else
                    mcount.ul = mcount.ul - 255;
            }
        }
    }
    else {
        mcount.ul = 0;
        CC4OL1 = 0;
    }
#endif
}

void Over_Torque_CHK(void)
{
    UWORD OT1LevelAD,OT2LevelAD;
    
    OT1LevelAD = ((ULONG)pr[OTDL]  * 3494) >> 8;     // (3494/2^8) * 100 = (4095/3), dino, 03/06/2007
    OT2LevelAD = ((ULONG)pr[OTDL2] * 3494) >> 8;     // (3494/2^8) * 100 = (4095/3), dino, 03/06/2007
    /*-------- Over Torque Detection (oL2) ---------------------------------*/
    /*-------- TB1_uwOT1Cnt , count in 100ms -------------------------------------*/
	if ((pr[OTDM]==1)||(pr[OTDM]==2)) {	
		//Over-Torque Detection during constant speed		
		if (TB1_uwNewIrmsAD>=OT1LevelAD){
			if (NORMALSP == 1)
				OT1CST = 1;
		}
		else{
			TB1_uwOT1Cnt = 0;
			OT1CST = 0;
		}
		
	}
	else if (pr[OTDM]>=3) {
		//Over-Torque Detection during acceleration
		if (TB1_uwNewIrmsAD>=OT1LevelAD) {
			if (RUNNING==RUN)
				OT1CST = 1;
		}
		else {
			TB1_uwOT1Cnt = 0;
			OT1CST = 0;
		}		
	}

	if ((pr[OTDM2]==1)||(pr[OTDM2]==2)){		
		if (TB1_uwNewIrmsAD>=OT2LevelAD){
		    if (NORMALSP==1)
		        OT2CST = 1;
		}
		else{
		    OT2CST = 0;
		    TB1_uwOT2Cnt = 0;
	    }
	}
	else if (pr[OTDM2]>=3){
		if (TB1_uwNewIrmsAD>=OT2LevelAD) {
			if (RUNNING==RUN)
				OT2CST = 1;
		}
		else {
			TB1_uwOT2Cnt = 0;
			OT2CST = 0;
		}
	}
	
    if ((OT1CST==1)&&(TB1_uwOT1Cnt>=pr[OTDT])){
       	switch(pr[OTDM]){
       		default:
       		case 0:
       			break;
       		case 1:
       		case 3:
       			if ((Error==0)&&(WarnCode==0)){
			        Keypad_PageTmp = Keypad_Page;
				    Keypad_Page = WarnPAGE;	        
       				WarnCode = OT1_WARN;
       			}break;
       		case 2:
       		case 4:{
       			if (Error==0){
       				WGOFF;
       				Error = ot1_ERR;   					
                    WGOFF;   					
   				}
   				}break;        			
       	}
    }
    else{
		if ((WarnCode==OT1_WARN)&&(TB1_uwOT1Cnt<pr[OTDT])){
        	WarnCode = 0;
        	Keypad_Page = Keypad_PageTmp;
        }
   	}
   	
   	if ((OT2CST==1)&&(TB1_uwOT2Cnt>=pr[OTDT2])){
       	switch(pr[OTDM2]){
       	    default:
       		case 0:
       			break;
       		case 1:
       		case 3:
       			if ((Error==0)&&(WarnCode==0)){
       				WarnCode = OT2_WARN;
			        Keypad_PageTmp = Keypad_Page;
				    Keypad_Page = WarnPAGE;
       			}break;
       		case 2:
       		case 4:{
       			if (Error==0){
       				WGOFF;
       				Error = ot2_ERR;   					
                    WGOFF;   					
   				}
   				}break;        			
       	}
    }
    else{
		if ((WarnCode==OT2_WARN)&&(TB1_uwOT2Cnt<pr[OTDT2])){
        	WarnCode = 0;
        	Keypad_Page = Keypad_PageTmp;
        }
   	}
    /*-------- End of Over Torque Detection --------------------------------*/
}

void sw_protect(void)
{
    UBYTE ubStartSource, HPSPEC_temp;         //[Single phase input, Bernie, 01/19/2012]
    UWORD uwTemp, uwLVS4ad, uwLVR4ad, j;

	if ( EPS ){
		uwLVS4ad = 0;
		uwLVR4ad = 0;
		if((Error >= LvA_ERR) && (Error <= LvS_ERR))
			Error = 0;
	}
	else{
		uwLVS4ad = LVS4ad;
		uwLVR4ad = LVR4ad;
	}

    if (Error==0){
	    if ( TB1_ubErrCnt==25 ){	// delay 500ms when power on, add by dino, 04/12/2007
            if ( (pr[PROTBIT]&0x2000)==0 ){             // Bit13, disable BF, dino, 05/30/2007
	            if (BRAKE_FAULT==0){
	                prt_ubBFChkCnt ++;
	                if (prt_ubBFChkCnt>20)
                        Error = bF_ERR;
	            }
	            else
	                prt_ubBFChkCnt = 0;
	        }

			// [ FanLock Treatment Selection, DINO, 04/27/2010	            	        
			if (FAN_LOCK==0){	//fan lock detected, Sean, 01/25/2010
	            FANChkCNT ++;
	            if ((pr[PROTBIT]&0x0100)==0x0100)		//SCOTTY 10/15/2007 
	            	FANChkCNT = 0;

	            if (FANChkCNT>5000){	// SCOTTY 20->2000 2007/09/06
	            	if (FANLOCKMOD){
                		if ((WarnCode==0)&&(Error==0)){
        					Keypad_PageTmp = Keypad_Page;
        					Keypad_Page = WarnPAGE;
        					WarnCode = Fan_WARN;
        				}
        			}
	            	else{
            	    	Error = Fan_ERR;
						LIFT_ENABLE = 0;
   						TB1_uwMCStopCnt = pr[MCDELAY_STOP];
       	        		CMDFREE = 1;
            	    }
            	}
    	    }
    	    else{
                FANChkCNT = 0;
	    		if (WarnCode == Fan_WARN){
            		WarnCode = 0;     
	    		}
	    	}
	    	// ]

//---Add BY Dino 10/05/2009---
			if ( Error )
				ubStartSource = 0;
			else{
    		    if ((pr[SOOC]==2)||PUEN2||PUEN3||CMDJOG)
					ubStartSource = LIFT_ENABLE;
				else{
					if ( pr[SEQMOD]==0 )
						ubStartSource = LIFT_RUNCMD;
					else
						ubStartSource = LIFT_ENABLE;
				}
			}

			if ( MCCHK_ENABLE ){
				if ( ubStartSource==1 ){
					if ( MOTORCONNECTOR==1 ){
						if ( MFI_MCCHK==0 ){
							if (prt_uwMcChkCnt > (pr[MC_CHKTIME]*10))
								Error = MCF_ERR;
							else
								prt_uwMcChkCnt++;
						}
						else
							prt_uwMcChkCnt = 0;
					}
					else
						prt_uwMcChkCnt = 0;
				}
				else{
					if ( MOTORCONNECTOR==0 ){
						if ( MFI_MCCHK==1 ){
							if (prt_uwMcChkCnt > (pr[MC_CHKTIME]*10))
								Error = MCF_ERR;
							else
								prt_uwMcChkCnt++;
						}
						else
							prt_uwMcChkCnt = 0;
					}
					else
						prt_uwMcChkCnt = 0;
				}
			}
			else
				prt_uwMcChkCnt = 0;
           EN81addA3();
	    }
	    //-------- Over Current --------------------------------------------//
	    if ((pr[PROTBIT]&0x0400)==0x0000){		// Bit 10: disable software oc
	        if (IrmsAD >= OCS){
                PROTECT_OC();
	        }
	    }

	    //-------- Over Voltage --------------------------------------------//
	    if ((pr[PROTBIT]&0x0004)==0x0000){		// Bit 2: disable software OV
	        PROTECT_OV();
        }
	//-------------- Ground Fault (60%rated current) -------------------//
    	if( GFFadLPF.sw.hi > GFFS ){
	        if (((pr[DEBUG_F1]&0x0100)==0x0000)&&(pr[LV_OPTM]&0x0004)==0)  // Bit 0,1: Control GFF Check by POE //[GFF soft enable 06-45, Lyabryan, 2016/03/04]
	            PROTECT_GFF();
	    }
        //-------- Over Load (Inverter) ------------------------------------//
		// 240000 = (150%-110%)*(150%-110%)*(60sec/40ms)
//		if (pwm_ulOL_C>OLCNT_C && pwm_ulOL_V>OLCNT_V) {   // For OL modify, by Justin , 2010/04/30
		if (pwm_ulOL_C > OLCNT_C) {   // For OL modify, DINO, 09/01/2010
	    	WGOFF;
	    	Error = oL_ERR; 
	    	WGOFF;
		}
		//-------- Over Load 1 (Motor) -------------------------------------//
      	// 5000000 = ( 150*150-100*100 ) / 40ms * 0.1sec
      	if ( pwm_ulMOL.ul >= ( (ULONG)31250 * pr[EOL1_T]) ) {
	    	WGOFF;
			Error = EoL1_ERR;
		}

		//-------- Over Slip -----------------------------------------------//
		if (NORMALSP==1 && pr[SLIPDEVL]!=0 && pr[CTRLM]!=FOCPM){  // Slip is invalid in FOCPM, DINO, 08/03/2010
		    uwTemp = abs(fout.uw.hi - fcmd.uw.hi);
		    uwOverWsL = ((ULONG)pr[SLIPDEVL]*COF_uwFslipRate)>>10;
		    if (uwTemp>=uwOverWsL){
				OVERSLIP = 1;
				if ((UWORD)TB1_ubOverWsCnt>pr[SLIPDEVT]){
			    	if (pr[OSLIPWAY]==1){
						stop();
			    	}
			    	else if (pr[OSLIPWAY]==2){
//						CMDRUN = STOP;
						LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
        				TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
						CMDFREE = 1;
						WARNSTOPREC = 1;		//09/05/2007
			    	}
			    	WarnDisplaySave();
					WarnCode = oSL_WARN;
				}
		    }
		    else{
				OVERSLIP = 0;
				TB1_ubOverWsCnt = 0;
		    }
		}
    //--------------------- GFC AFE RST ---------------------//
        if ((AFE_ERR_TRIG)&&!AFE_ERR_TMR)
        {
            WGOFF;
            Error = GFCAFE_ERR;
            LIFT_ENABLE = 0;                    // Add by DINO, 03/28/2008
            TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
            CMDFREE = 1;
            WGOFF;
            //Keypad_Page = ErrPAGE;
            LIFT_RUNCMD = 0;
        }
    //--------------------- GFC AFE RST ---------------------//
    }

	/*-- Soft Start delay time is invalid in D Frame --*/
    HPSPEC_temp =pr[HPSPEC];           //[Single phase input, Bernie, 01/19/2012]
    if(pr[HPSPEC]>VFD_SINGLEPHASE)
        HPSPEC_temp-=VFD_SINGLEPHASE;
	//if (( pr[HPSPEC]>VFD110V43A && pr[HPSPEC]<VFD300V23A ) || (pr[HPSPEC]==VFD300V43A))	// D Frame	// 300V43A chg to frame D, Sean, 03/14/2011
	if ((HPSPEC_temp>VFD110V43A && HPSPEC_temp<VFD300V23A ) || (HPSPEC_temp==VFD300V43A)&&pr[HPSPEC]<VFD_SINGLEPHASE)	// D Frame	// 300V43A chg to frame D, Sean, 03/14/2011
		uwTemp = 0;
	else	// C, E Frame
		uwTemp = pr[RLY_TIME];

    //-------- Under Voltage -----------------------------------------------//
    dcbusADAVG = (dcbusADAVG * 7 + dcbusAD)>>3;
    if (dcbusADAVG < uwLVS4ad){
        if (pr[KEB_SL]==0){
        	if ((EXT_EF==0)||((EXT_EF==1)&&(pr[FORSTPWAY]==0))){
			    WGOFF;
			    if (Error==0){
	    	        if (RUNNING==RUN){
	                    if (NORMALSP==1)
	                        Error = Lvn_ERR;
	        	       	else if (ACCODEC==DECON)
	                       	Error = Lvd_ERR;
	                   	else if (ACCODEC==ACCON)
	                       	Error = LvA_ERR;
	                }
	                else
	                   	Error = LvS_ERR;
				        LVTAT = 0;                      //LV Time Attain
				        TB1_uwLVCnt = pr[PWRL_T] * 100;
	            }
	            WGOFF;
	        }
		}
		else{
	    	if (Error==0 && RUNNING==STOP)
				Error = LvS_ERR;
	    	else{    
				KEB_ON = 1;
				TB1_uwKEBRtCnt = 0;
				if (pr[KEB_RT]!=0)
					fkey.uw.hi = 0;
				else 
					stop();
				Error = DEB_ERR; 
			}    
		}    		  
		RelayOFF = 1;		// Turn off Power relay.
		prt_uwLVCNT = 0;	// Soft Start Relay Delay Counter, Add by DINO, 12/01/2008
   	}
   	// [ Add "equal" condition, DINO, 08/13/2009
   	else if ((dcbusADAVG>=uwLVR4ad) && (TB1_uwRYCnt >= Def_uwRYCnt)){  //LV + 30DVC = LVR, relay delay 200ms, add by DINO, 05/22/2008
	// ]                                                                                                     //relay delay 300ms,modify by Bernie [Single phase input, Bernie, 01/19/2012]
   		//--- Soft Start Relay Delay Time, Add by DINO, 12/01/2008 ---//
   		if ( PWRON )
   			RelayOFF = 0;	// Turn ON Power relay.
   		else{
			if ( prt_uwLVCNT<uwTemp )
				prt_uwLVCNT++;
			else
				RelayOFF = 0;
   		}
   		PWRON = 0;

   		if ((KEB_ON == 1) && (dcbusADAVG > (uwLVR4ad+160))){
   			if (pr[KEB_RT]!=0){
	   		    if (TB1_uwKEBRtCnt>=(pr[KEB_RT]*100)){
	   		    	if (fout.uw.hi<=fmin)
	                	KEB_ON = 0;
	                	if (Error==DEB_ERR)
							Error = 0;
	            }
	            else
	   		        TB1_uwKEBRtCnt++;
	   		}
		}
   		else {
			if ((Error>=LvA_ERR)&&(Error<=LvS_ERR)){
				TB1_uwLVCnt = pr[PWRL_T] * 100;	//keep the counter to prevent LV STOP before RESTART
//   			    KEYRESET = 1;  // Redundant, Delete by DINO, 05/31/2010
   			    if (CMDRUN==STOP){
   		    	    if (Error==LvS_ERR){
   			    	    Error = 0;
						KEYRESET = 0;
   			    	}
					else{
						// [ LV Option Mode, Add by DINO, 11/30/2009
						if (LVMOD == 1){
							Error = 0;
							// [ LED LEYPAD, DINO, 03/12/2010
							/*Keypad_PageTmp = 0;
							KEY_ubDispMode = pr[S_DISP];*/
							// ]
							KEYRESET = 0;
						}
						else
   			    	    	KEYRESET = 1;
   			    	    // ]
   			    	}
   			    }
   			    else{
   				    LVORFLT = 1;
   				    RESTART = 1;
   				    KEYRESET = 1;
   			    }
			}
   		}   
  	}

    if ((Error>=LvA_ERR)&&(Error<=LvS_ERR)){        // Lv progress
	    if (TB1_uwLVCnt==0){
            LVTAT = 1;            
        }
        else
            TB1_uwLVCnt --;
            
        if ((pr[PWRLOS]==0)||(LVTAT)||(CMDRUN==STOP)){
//            CMDRUN = STOP;
			LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
  			TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
            CMDFREE = 1;
            RESTART = 0;
        }
    }
    
    if (Error!=0){ 
        switch(Error){
            case ocA_ERR:
            case ocd_ERR:
	        case ocn_ERR:
            case ocS_ERR:
            case ovA_ERR: 
            case ovd_ERR: 
            case ovn_ERR: 
            case ovS_ERR: 
            case occ_ERR:
            case GFF_ERR:   
            case Fan_ERR:
            /*-------- Restart after Fault -----------------------------*/
            	WGOFF;
    	        Vcmd_LL = 0;	// Let Vcmd = 0
		        if ((pr[REST_CNT]==0)||(CMDRUN==STOP)||(pr[REST_M]==0)){
//              	    CMDRUN = STOP;
					LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    				TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
              	    CMDFREE = 1;
              	    RESTART = 0;
            	}
            	else {
              	    LVORFLT = 0;
              	    RESTART = 1;
            	}
          	    break;
            case PGF1_ERR:  //PG fbk Error
            case PGF2_ERR:  //PG fbk loss
            case PGF3_ERR:
            case PGF4_ERR:
            case PGF5_ERR:
            case PGHL_ERR:   //[modify Error code,Lyabryan,2016/07/21]
            case PGAF_ERR:   //[modify Error code,Lyabryan,2016/07/21]
            case LvA_ERR:
            case Lvd_ERR:
            case Lvn_ERR:
            case LvS_ERR:
            case AFE_ERR:
//            case Fan_ERR:
            case cP10_ERR:
            case cE1_ERR:
            case cE2_ERR:
            case cE3_ERR:
            case cE4_ERR:
            case cE10_ERR:
            case PHL_ERR:
            case bb_ERR:
            case DEB_ERR:
          		break;
                
            case OVERACC_ERR:      //[Over Acceleration protection function, Bernie, 2017/02/13]
                WGOFF;
                //CMDRUN = STOP;
                LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
                TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
                CMDFREE = 1;
                break;

            case EF_ERR:
          	  	if (pr[FORSTPWAY]==0){
          	  	    WGOFF;
          	  	    Vcmd_LL = 0;
//          	  	    CMDRUN = STOP;
					LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    				TB1_uwMCStopCnt = pr[MCDELAY_STOP];// Add by DINO, 03/28/2008
          	  	    CMDFREE = 1;
				}
				else
		        	stop();
				break;
			case Sensor817_ERR:
            case Sensor818_ERR:
				WGOFF;
    	        Vcmd_LL = 0;
				LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
                TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
                CMDFREE = 1;
				break;
            default:
                WGOFF;
    	        Vcmd_LL = 0;                   // Let Vcmd = 0
//                CMDRUN = STOP;
				LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
   				TB1_uwMCStopCnt = pr[MCDELAY_STOP];	// Add by DINO, 03/28/2008
                CMDFREE = 1;
            break;
		}
    }

	//--- ERROR MO Delay 10ms Function, Add by DINO, 10/24/2008  ---//
	// [ LV Option Mode, Add by DINO, 11/30/2009
	if (Error==LvS_ERR || (LVMOD==1 && (Error==LvA_ERR || Error==Lvd_ERR || Error==Lvn_ERR))){
		uwTemp = 0;
	}
	else{
		uwTemp = Error;
	}
	// ]

	if (uwTemp != 0){ //Except for Lv Stop
		if ( prt_uwErrDT<10 )
			prt_uwErrDT++;
		else
			ERR_MO = 1;
	}
	else{
		ERR_MO = 0;
		prt_uwErrDT = 0;
	}

    Over_Torque_CHK();
    if(Error!=0){                         //[fault output bug, Bernie, 2017/06/20]
        uwFaultBitCode |= FaultBitCodeTable[Error];
    }
    else{
        uwFaultBitCode = 0;
    }

	//-- New Error Bit Definition, Add by DINO, 09/17/2008
    if ( pr[ERR_OPTM]==1 )
    	MFI_ubFaultBit = FaultBitCodeTable1[Error];
    else
    	MFI_ubFaultBit = 0;

}

void sw_brake(void)
{
	// [ SW_Brake Control by IO, DINO, 09/30/2009
    if (RUNNING==RUN) {
        if (dcbusAD >= dcbrk4ad){            
            GBP_ON = 1;
        }
        else if(dcbusAD <= dcbrk4ad2){  // [DCBRK_BAND function for adjustable reset level, James, 2019/12/05  ]                 
            GBP_ON = 0;
        }
    }
    else{
    	if (TB1_uwSBKCnt >= 750){  // Delay Turn-off GBP 750ms
        	GBP_ON = 0;
        }
    }
	// ]
}

/*---- Safty Relay Function (dino, 04/02/2007) ----
//
// SRY_A = 1 --> SRY_B==SRY_D --> ERROR
//            -> SRY_B!=SRY_D --> nothing
// SRY_A = 0 --> SRY_B==1     --> ERROR
//            -> SRY_B==0     --> nothing
-------------------------------------------------*/
/*
void safe_off(void)
{
    if( SRY_A ){  // pin71=high, safety relay board is installed
    	//----- verify pt.B & pt.D every 1ms ----- dino, 04/02/2007 -----
    	if( SRY_B==SRY_D){
      	    prt_ubSRYCnt++;
    	}
    	else{
    		prt_ubSRYCnt = 0;
    	}

    	if(prt_ubSRYCnt>7){    // 8ms pt.B=pt.D continuous
	    	Error = SRY_ERR;	// SRY fault
	    	prt_ubSRYrec = 2;
            prt_ubSRYCnt = 0;
    	}
    }
    else{  // pin71=low, without connecting safety relay board
		if ( SRY_B ){  		// pt.B = 1
            prt_ubSRYCnt2++;  // V201D6R0_F111
    	}
    	else{
    		prt_ubSRYCnt2 = 0;
    	}

    	if(prt_ubSRYCnt2>7){   // 8ms
	    	Error = SRY_ERR;	// SRY fault
            prt_ubSRYCnt2 = 0;
	    	prt_ubSRYrec = 3;
        }
    }

}
*/
/*-------- Check AMPs ----------- -----------------------
 -      Check AMPs when fault cause of hight current    -
 -      OCR : constant for OC reset Level               -
 -      KEYRESET : Could reset flag?                    -
 -------------------------------------------------------*/
void chkamps(void)
{
	if (CHKAMPS){
	    if (IrmsAD<OCR) {
            if (RESTART){
        	    KEYRESET = 1;        	
            }
    	    if (Delay4oc >= 50){   // 5000*100ms = 5sec
    		    KEYRESET = 1;    		
    		    Delay4oc = 0;    		
    	    }
    	    else{
    		    Delay4oc++;
    	    }
        }
        else {
    	    Delay4oc = 0;
            KEYRESET = 0;
        }
    }    
}

void Error_Handel(void)
{
    switch (Error) {

		case ocS_ERR:	//Over current
		case ocA_ERR:	//Over current during acceleration
		case ocd_ERR:	//Over current during deceleration
		case ocn_ERR:	//Over current during steady state		
		    if ( OC_CHK==1 )  // dino, 07/22/2007
		        CHKAMPS = 1;
		break;
		case oL_ERR:	//Over Load
		    CHKAMPS = 1;
		break;
		case GFF_ERR:	//Ground or fuse fault
		    if ( GFF_CHK==1 )  // dino, 07/22/2007
		        CHKAMPS = 1;
		break;
		case ovA_ERR:   //Over voltage during Acceleration
		case ovd_ERR:   //Over voltage during Deceleration
		case ovn_ERR:   //Over voltage during steady state
		case ovS_ERR:   //Over voltage when stop
    		if ( dcbusAD<OVR4ad && OV_CHK==1 )	// dino, 07/22/2007
		        KEYRESET = 1;
        break;
			   

		case Fan_ERR:			
	    	if (FAN_LOCK==1){	//FAN_LCOK released, Sean, 01/25/2010
				KEYRESET = 1;
				FANChkCNT = 0;	
	    	}
		break;
  

		case PHL_ERR:	//Power phase loss
	    	if (PHLACTIVE==0)  // dino, 09/23/2008
			KEYRESET = 1;
        break;
        
		case oH1_ERR:
		case tH1o_ERR:
		    if (IGBT_Temp<(IGBT_OHLevel-50))   //oH1-5 degree, Modify by DINO, 09/04/2008
			    KEYRESET = 1;
		break;
        
		case oH2_ERR:
		case tH2o_ERR:
		    if (HS_Temp<(HS_OHLevel-50))     //oH2-5 degree 
		        KEYRESET = 1; 	    
		break;
        
		case oH3_ERR:
            if ((PTCInLPF.sw.hi<=(pr[PTC_LEVEL]-50))||(PTCInLPF.sw.hi<=0))
                    KEYRESET = 1;		          
		break;

		case EF_ERR:
			if (EXT_EF==0)
        		KEYRESET = 1;
        break;
        case ACE_ERR:
			if (ACI_EF==0)
				KEYRESET = 1;
		break;
		case EF1_ERR:
			if (EXT_EF1==0)
				KEYRESET = 1;
		break;

		// [ KEYRESET of LV is set in sw_protect(), DINO, 05/31/2010
		case LvA_ERR:
        case Lvd_ERR:
        case Lvn_ERR:
        case LvS_ERR:
        break;
        // ]
        case CAN_ERR:            // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
            //if (uwPDO_CNT == 0)
                KEYRESET = 1;
        break;

        case STOL_ERR:
			if((pr[STO_LOCK] != 0x0000) && (pr[STO_LOCK] != 0x0002))//1,3, 4~7,8
			{
				KEYRESET = 1;
			}
			else if((STOLOSS ==0) && (STO1LOSS ==0) && (STO2LOSS ==0) && (STO3LOSS ==0))//James, 2021/11/10
			{
				KEYRESET = 1;
			}
			else
			{
				KEYRESET = 0;
			}
        break;
        //case STOr_ERR:
        case STOS_ERR:
			if(pr[STO_LOCK] != 0x0006)//0,1,2,3,4,5,7,8
			{
				KEYRESET = 1;
			}
			else if((STOLOSS ==1) || (STO1LOSS ==1) || (STO2LOSS ==1))//James, 2021/10/25
			{
				KEYRESET = 1;
			}
			else
			{
				KEYRESET = 0;
			}
        break;
        case STOL1_ERR:
        case STOL2_ERR:
        case STOL3_ERR:
        case STOL4_ERR:
                KEYRESET = 0;
        break;
        case SERVICE_ERR:                     //[Service time function, Bernie, 2017/03/14]
            if(SERVICE_RESET)
                KEYRESET = 1;     //can not be reset, must to power off
        break;
		case cd0_ERR:
        case cd1_ERR:
		case cd2_ERR:
		case cd3_ERR:
		case Hd0_ERR:
		case Hd1_ERR:
		case Hd2_ERR:
		case Hd3_ERR:
		case ccodE_ERR:
		case PcodE_ERR:
		case ydc_ERR:
		case SRY_ERR:		 // Safyte relay Error, add by dino, 06/06/2007
		    KEYRESET = 0;     //can not be reset, must to power off
		break;

        case OPHLW_ERR:
        case OPHLV_ERR:
        case OPHLU_ERR:
        case MPHL_ERR:
            KEYRESET = 1;     //can not be reset, must to power off
		break;
		case DLC_ERR:
		    if ((pr[CTRLM]==FOCPG || pr[CTRLM]==FOCPM))// Can't do Tuning without setting PG_TYPE, James, 20201201
		        KEYRESET = 1; 	    
		break;
		case Sensor817_ERR:
		case Sensor818_ERR:
        case BTT1_ERR:          //[JES Torq Detect Function, Special.Kung, 2022/09/01]
        case BTT2_ERR:          //[JES Torq Detect Function, Special.Kung, 2022/09/01]
            KEYRESET = 1;       //can reset
		break;
        case GFCAFE_ERR:
            //if(AFE_ERR_TRIG==1)
            //{
            //    KEYRESET = 0;     //can not be reset, must to power off
            //}
            //else
            //{
                KEYRESET = 1;     //can reset 
            //}
        break;
        //[AFE Error Handle/Lyabryan/2022/03/24]		
		default:
		    KEYRESET = 1;     //can reset 
		break;	//Break of case NULL:

    }//End of switch (Error)

}

// [ Short_Circuit Detection, DINO, 05/19/2010
void prt_voDiagnosticProcess(void) // chiuju091112
{
	SWORD sw_experiod;

    if(prt_ubBRStatus != CHARGE_OFF)
    {
    	sw_experiod = U32divU16(MTU2CLK, 4000); // Carry frequency 4kHz
    	//MTU2.TCBR  = sw_experiod;
    	//MTU23.TGRC = sw_experiod + DeadTime;
        MTU.TCBRA = sw_experiod;
        MTU3.TGRC = sw_experiod + DeadTime;
        prt_swPeriod = (SWORD)((SLONG)sw_experiod * 820 >> 11); // 50us = 1 / (4k*2) * 0.4, 0.4 = 820/2048
    	//prt_swPeriod = (SWORD)((SLONG)sw_experiod * 82 >> 11); // 5us = 1 / (4k*2) * 0.04, 0.04 = 82/2048
    	//prt_swPeriod = (SWORD)((SLONG)sw_experiod * 82 >> 13); // 1.25us = 1 / (4k*2) * 0.01, 0.01 = 82/8192
    }

	switch(prt_ubBRStatus)
	{
		case CHARGE_START:
			WGOFF;
//			prt_uwBeforeRunCnt = 0;
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = DIAG_UY1;
			break;
/*
		case CHARGE_X:
			MTU2.TOER.BYTE = 0x08; // X active
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			
			if(++ prt_uwBeforeRunCnt >= gt1_uwDIAGTIME1)
			{
				prt_ubBRStatus = CHARGE_Y;
				prt_uwBeforeRunCnt = 0;
			}
			break;
			
		case CHARGE_Y:
			MTU2.TOER.BYTE = 0x10; // Y active
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			
			if(++ prt_uwBeforeRunCnt >= gt1_uwDIAGTIME2)
			{
				prt_ubBRStatus = CHARGE_Z;
				prt_uwBeforeRunCnt = 0;
			}
			break;
			
		case CHARGE_Z:
			MTU2.TOER.BYTE = 0x20; // Z active
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			
			if(++ prt_uwBeforeRunCnt >= gt1_uwDIAGTIME3)
			{
				// [ chiuju100126 modify, chiuju091229 modify
				//prt_ubBRStatus = DIAG_EMPTY0;
				//prt_ubBRStatus = CHARGE_OFF;
				prt_ubBRStatus = DIAG_EMPTY0;
				// ]
				
				prt_uwBeforeRunCnt = 0;
			}
			break;
		case DIAG_EMPTY0:
			MTU2.TOER.BYTE &= 0xF8;
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = DIAG_UY1;
			break;
*/			
		case DIAG_UY1:
			//MTU2.TOER.BYTE = 0x11; // U and Y active
			MTU.TOERA.BYTE = 0x11; // U and Y active
			PWM_swTaOut_Buf = prt_swPeriod;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = DIAG_UY2;
			break;
			
		case DIAG_UY2:
			//MTU2.TOER.BYTE &= 0xF8;
            MTU.TOERA.BYTE &= 0xF8;
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = DIAG_VZ1;
			break;
			
		case DIAG_VZ1:
			//MTU2.TOER.BYTE = 0x22; // V and Z active
			MTU.TOERA.BYTE = 0x22; // V and Z active
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = prt_swPeriod;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = DIAG_VZ2;
			break;
			
		case DIAG_VZ2:
			//MTU2.TOER.BYTE &= 0xF8;
            MTU.TOERA.BYTE &= 0xF8;
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = DIAG_WX1;
			break;
			
		case DIAG_WX1:
			//MTU2.TOER.BYTE = 0x0C; // W and X active
			MTU.TOERA.BYTE = 0x0C; // W and X active
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = prt_swPeriod;
			prt_ubBRStatus = DIAG_WX2;
			break;
			
		case DIAG_WX2:
			//MTU2.TOER.BYTE &= 0xF8;
            MTU.TOERA.BYTE &= 0xF8;
			PWM_swTaOut_Buf = 0;
			PWM_swTbOut_Buf = 0;
	    	PWM_swTcOut_Buf = 0;
			prt_ubBRStatus = CHARGE_OFF;
			break;
			
		case CHARGE_OFF:
			WGOFF;			
			prt_ubBRStatus = CHARGE_START;
			WG_Init();
			BEFORERUN = 0; // Restore the original PWM carry frequency setting			
			break;
			
		default:
			break;
	}
	
	//MTU23.TGRD = MTU23.TGRC - PWM_swTaOut_Buf;
	//MTU24.TGRC = MTU23.TGRC - PWM_swTbOut_Buf;
   	//MTU24.TGRD = MTU23.TGRC - PWM_swTcOut_Buf;
    if(Error == 0){ //[2 pulses when GFF,Lyabryan,2016/07/19]
        MTU3.TGRD = MTU3.TGRC - PWM_swTaOut_Buf;
        MTU4.TGRC = MTU3.TGRC - PWM_swTbOut_Buf;
        MTU4.TGRD = MTU3.TGRC - PWM_swTcOut_Buf;
    }
    else //[2 pulses when GFF,Lyabryan,2016/07/19]
        WGOFF;
}
// ]

void EN81addA3(void){              //[change for EN81-1+A3, Bernie, 2015/03/16]

    if(BKCHK_ENABLE1){
        if((LIFT_ENABLE) ||(RUNNING == RUN)){
            if(BRK_RLS==1){
                if(MFI_BRKCHK1==0){
                    if(prt_uwBrkChkCnt1 > (pr[BRK_CHKTIME]*10))
                        Error = MbF_ERR;
                    else
                        prt_uwBrkChkCnt1++;
                }
                else
                    prt_uwBrkChkCnt1 = 0;
            }
            else
                prt_uwBrkChkCnt1 = 0;
         }
         else{
             if(BRK_RLS==0){
                 if(MFI_BRKCHK1==1){
                     if(prt_uwBrkChkCnt1 > (pr[BRK_CHKTIME]*10))
                         Error = MbF_ERR;
                     else
                         prt_uwBrkChkCnt1++;
                     }
                 else
                     prt_uwBrkChkCnt1 = 0;
             }
             else
                 prt_uwBrkChkCnt1 = 0;
         }
     }
     else
         prt_uwBrkChkCnt1 = 0;
     
     if(BKCHK_ENABLE2){
         if((LIFT_ENABLE) ||(RUNNING == RUN)){
             if(BRK_RLS==1){
                 if(MFI_BRKCHK2==0){
                     if(prt_uwBrkChkCnt2 > (pr[BRK_CHKTIME]*10))
                         Error = MbF_ERR;
                     else
                         prt_uwBrkChkCnt2++;
                 }
                 else
                     prt_uwBrkChkCnt2 = 0;
             }
             else
                 prt_uwBrkChkCnt2 = 0;
         }
         else{
             if(BRK_RLS==0){
                 if(MFI_BRKCHK2==1){
                     if(prt_uwBrkChkCnt2 > (pr[BRK_CHKTIME]*10))
                         Error = MbF_ERR;
                     else
                         prt_uwBrkChkCnt2++;
                  }
                  else
                      prt_uwBrkChkCnt2 = 0;
              }
              else
                  prt_uwBrkChkCnt2 = 0;
          }
      }
      else
          prt_uwBrkChkCnt2 = 0;


      if(Error == MbF_ERR){                    //[MBF can be recorded after power down, Bernie, 2016/02/19]
        pr[MBF_ERR_REC] = Error;
        write_ep(0,MBF_ERR_REC, MbF_ERR);
      }

}


#ifdef _ProtectFun_C
    #undef _ProtectFun_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
