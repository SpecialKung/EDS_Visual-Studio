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
#ifndef _BK_APR_C
	#define _BK_APR_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void APR_PScurve(void)
{
	//============================================================================//
	// Only Execute in rnnning                                                    //
	//============================================================================//
	ULONG_UNION  Pacc_t1;
	ULONG ulTemp;
	SLONG delta_P, ss2;	
	UWORD PACCT, S4PACC, uwTemp;

		if (LOOPFlag==1){
			if (EXT_SPD2POS==0)
				uwTemp = pr[PGHOME];
			else
				uwTemp = pr[PMI1+speed-1];			
			
			if (APR_uwPGHome!=uwTemp){
				P2PFlag = 1;
						
				if (APR_uwPGHome>uwTemp)
					APR_uwDistance = (SpDt_ulPG1NpulseNoMx - APR_uwPGHome) + uwTemp;
				else
					APR_uwDistance = uwTemp - APR_uwPGHome;
				APR_uwPGHome = uwTemp;
				LOOPFlag = 0;
				
				ONPosition = 0;
				MultiONPosition = 0;	
				APR_uwOnPCNT = 0;
				
				APRCMDDIR = CMDDIR2;
				//uwTemp = U16xU16divU16(APR_uwDistance,pr[MPGGA],pr[MPGGB]);
				uwTemp = APR_uwDistance;
				if (CMDDIR2==FORWARD)
					APR_uwPTarget = APR_uwPTarget + uwTemp;                       //In APR_PScurve(), LOOPFlag = 1 
				else
					APR_uwPTarget = APR_uwPTarget + (SpDt_ulPG1NpulseNoMx - uwTemp);  //In APR_PScurve(), LOOPFlag = 1 
			}
		}
		else{	// Loop Flag = 0
			if (P2PFlag==0){							
				if (EXT_SPD2POS==0){
					if (EXT_PG2REFMODE==0){		// PG2 Ref Speed Control
						//uwTemp = U16xU16divU16(pr[PGHOME], pr[MPGGA], pr[MPGGB]);
						uwTemp = pr[PGHOME];
						if (CMDDIR2==FORWARD)
                            uwTemp = uwTemp + APR_uwZPosition + SpDt_ulPG1NpulseNoMx;
						else
                            uwTemp = (SpDt_ulPG1NpulseNoMx*2) - (uwTemp+APR_uwZPosition);
					}
				}
				else{
					//uwTemp = U16xU16divU16(pr[PMI1+speed-1], pr[MPGGA], pr[MPGGB]);
					uwTemp = pr[PMI1+speed-1];
					if (CMDDIR2==FORWARD)
                        uwTemp = uwTemp + APR_uwZPosition + SpDt_ulPG1NpulseNoMx;
					else
                        uwTemp = (SpDt_ulPG1NpulseNoMx*2) - (uwTemp+APR_uwZPosition);
				}
				if (STOPgoAPR==1){
					if (APRFirstGo==0)
           				APR_uwPTarget = SpDt_ulPG1NpulseNoMx;
					else{	
					    if (CMDDIR2==FORWARD)
	                        APR_uwPTarget = uwTemp + SpDt_ulPG1NpulseNoMx - APR_uwThetaO2;	//In APR_PScurve(), LOOPFlag = 0, STOPgoAPR = 1
	                    else
	                        APR_uwPTarget = uwTemp + APR_uwThetaO2;    					//In APR_PScurve(), LOOPFlag = 0, STOPgoAPR = 1
	                }
                }
                else{
                    APR_uwPTarget = uwTemp;                                               //In APR_PScurve(), LOOPFlag = 0, STOPgoAPR = 0
                }
			}
		}        	

		PACCT = pr[PACCELT];	//% Accel. Time for Position
		S4PACC = pr[APRCURVET];			//% P Scurve Time
	
		Pacc.ul = U32xU32divU32(65535,429496730,((ULONG)PACCT<<16));	
			
		Pacc_t1.ul = (Pacc.ul/S4PACC);
	
		if (Pacc_t1.ul==0)
			Pacc_t1.ul = 1;
			
		if ((APRExeFlag==1)&&(PcurveFlg==0)){
			PcurveFlg = 1;
			Psacc.ul = PsaccMax.ul;
		}				
		if (APR_uwPTarget>=APR_uwPCom)
			delta_P = (SLONG)(APR_uwPTarget - APR_uwPCom)<<15;
		else
			delta_P = (SLONG)((APR_uwPTarget+65535) - APR_uwPCom)<<15;

		if (delta_P > 0){
			ss2 = U32xU32divU32((Psacc.ul>>1),(Psacc.ul>>1),Pacc_t1.ul);
		    if ((SLONG)delta_P > ss2){
				Psacc.ul = Psacc.ul + Pacc_t1.ul;				
				if (Psacc.ul>Pacc.ul){
					Psacc.ul = Pacc.ul;
				}				
		    }
		    else {
		    	ulTemp = U32xU32divU32((Psacc.ul>>1),(Psacc.ul>>1),abs(delta_P));
				Psacc.ul = Psacc.ul - ulTemp;				
				if ((SWORD)Psacc.uw.hi <= 0){
					Psacc.uw.hi = 1;
					Psacc.uw.low = 0;
				}
                if (Psacc.uw.hi<=100)
                    EnterLoop = 1;
		    }
		    if (Psacc.ul>=PsaccMax.ul)
		    	PsaccMax.ul = Psacc.ul;

		    //ftemp.ul = ftemp.ul + Psacc.ul;
			APR_uwPCom = APR_uwPCom + Psacc.uw.hi;
		}
		else if (delta_P==0){
			Psacc.ul = 0;
		}
}

void TB1_APRExeFun(UWORD PGRef, UWORD PGFbk)
{
	SWORD swTemp;
	UWORD uwTemp;
	SLONG slTemp;
	ULONG ulTemp;
	
	
    if (EXT_PG2REFMODE==0){		// PG2 Ref Speed Control
    	if (ZeroServo==0){
	        APR_PScurve();
	        PGRef = APR_uwPCom;
	        if (CMDDIR2==FORWARD)
	            APR_uwPFbk = SpDt_uwPG1CNT - APR_uwThetaO;
	    	else
	    		APR_uwPFbk = (65535 - SpDt_uwPG1CNT) - APR_uwThetaO;
				    			
	    	PGFbk = APR_uwPFbk;
		}
		else{
			APR_uwPTarget = PGRef;
		}
		swTemp = (SWORD)(PGRef - PGFbk);
		slTemp = ((SLONG)swTemp * pr[ZASRKP] * 10);
    }
    else if (EXT_PG2REFMODE==1){	// PG2 Ref Position Control    
      	APR_uwPG2PComOld = U16xU16divU16(APR_uwPG2PCom, 65535, SpDt_ulPG1NpulseNoMx);
		APR_uwPFbk = U16xU16divU16(APR_uwThetaNoMx, 65535, SpDt_ulPG1NpulseNoMx) - APR_uwThetaO2;
		PGRef = APR_uwPG2PComOld;
		PGFbk = APR_uwPFbk;		
		swTemp = (SWORD)(PGRef - PGFbk);
		slTemp = ((SLONG)swTemp * pr[ZASRKP]);
	}            	
								
    if (EXT_PG2REFMODE==0){		// PG2 Ref Speed Control
  		if ((abs(APR_uwPTarget-PGFbk)<=pr[PGATTAIN])&&(EnterLoop==1))
   			LOOPFlag = 1;
   	}
			
	if (LOOPFlag==1){
		if (ZeroServo==0){
			if (EXT_SPD2POS==0){
	    		if (EXT_PG2REFMODE==0)		// PG2 Ref Speed Control
	    			uwTemp = pr[PGHOME];
	    	}
	    	else{
	    		uwTemp = pr[PMI1+speed-1];
	    	}
    		//uwTemp = U16xU16divU16(uwTemp, pr[MPGGA], pr[MPGGB]);
	    	PGRef = uwTemp + APR_uwZPosition;

	    	if (PGRef>SpDt_ulPG1NpulseNoMx)
	    		PGRef = PGRef - SpDt_ulPG1NpulseNoMx;
    	}

		PGFbk = APR_uwThetaNoMx;

    	if (CMDDIR2==FORWARD){
    		swTemp = SpDt_ulPG1NpulseNoMx - PGFbk + PGRef;
    		if (swTemp>=SpDt_ulPG1NpulseNoMx)
    			swTemp = swTemp - SpDt_ulPG1NpulseNoMx;
    	}
    	else{
    		swTemp = PGFbk - PGRef;
    		if (swTemp<0)
    			swTemp = swTemp + SpDt_ulPG1NpulseNoMx;
    	}
    			
    	if (swTemp==SpDt_ulPG1NpulseNoMx)
    		swTemp = 0;
    		
    	if (CMDDIR2==FORWARD){
    		if (swTemp >= (SpDt_ulPG1NpulseNoMx>>1)){
    			APRCMDDIR = REVERSE;
    			swTemp = SpDt_ulPG1NpulseNoMx - swTemp;
    		}
    		else if (swTemp < (SpDt_ulPG1NpulseNoMx>>1)){
    			APRCMDDIR = FORWARD;
    		}
    	}
    	else{
    		if (swTemp >= (SpDt_ulPG1NpulseNoMx>>1)){
    			APRCMDDIR = FORWARD;
    			swTemp = SpDt_ulPG1NpulseNoMx - swTemp;
    		}
    		else if (swTemp < (SpDt_ulPG1NpulseNoMx>>1)){
    			APRCMDDIR = REVERSE;					
    		}				
    	}
    		
        slTemp = ((SLONG)swTemp * pr[ZASRKP] * 10);
			
    	if (ONPosition==0){
    		if ((abs(swTemp)<=pr[PGATTAIN])&&(APR_uwOnPCNT>=500)){
				ONPosition = 1;    			
				APR_uwPGCycle = 0;    			
    			if (EXT_SPD2POS==1){
    				uwTemp = APR_uwThetaNoMx - APR_uwZPosition;
    				if (abs(pr[PMI1+speed-1]-uwTemp)<=pr[PGATTAIN]){
    					MultiONPosition = 1;
    				}
				}
    		}
    		APR_uwOnPCNT ++;
    	}
    					
    	Psacc.ul = 0;			
	}
		
	APR_slSpdCmd = slTemp;
	if (EXT_PG2REFMODE==1){		// PG2 Ref Position Control
		//ulTemp = U32xU32divU32((PG2_ulSpdCmdLPF.ul>>5), pr[MPGGB], pr[MPGGA]);
		ulTemp = (PG2_ulSpdCmdLPF.ul>>5);
       	if (PG2_slSpdCmd>=0)
			slTemp = APR_slSpdCmd + ulTemp * pr[APRFFGA];
		else
			slTemp = APR_slSpdCmd - ulTemp * pr[APRFFGA];				
			
		if (slTemp>=0){								                	        	
			if (pr[SETDIR]==2)     // FWD disable                
	           	CMDDIR = REVERSE;
	        else{
	        	if ((PWM_Status.ub&0x42) == 0)  //GEN_OK3 = 0; GEN_START = 0; // Generation Operation, DINO, 04/27/2010
	           		CMDDIR = FORWARD;
	        }
       	}
       	else if (slTemp<0){                	        	
	        if (pr[SETDIR]==1)      // REV disable
	           	CMDDIR = FORWARD;
	       	else{
	       		if ((PWM_Status.ub&0x42) == 0)  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
					CMDDIR = REVERSE;				
			}
       	}        	
       	APRCMDDIR = CMDDIR;
       	CMDDIR2 = CMDDIR;
       	WGDIR = CMDDIR;
		if ((slTemp>>1)>=((SLONG)pr[FMAX]<<15))
	        fkey.ul = (ULONG)(pr[FMAX]<<16);
	    else if ((slTemp>>1)<=((SLONG)(-pr[FMAX]<<15)))
	   		fkey.ul = (ULONG)(pr[FMAX]<<16);
	   	else
	   		fkey.ul = abs(slTemp);
    }
    else{
    	//ulTemp = U32xU32divU32(((ULONG)Psacc.uw.hi<<16), pr[MPGGB], pr[MPGGA]);
    	ulTemp = ((ULONG)Psacc.uw.hi<<16);
        slTemp = APR_slSpdCmd + ulTemp * pr[APRFFGA];
		if (slTemp<=0)
	        fkey.ul = 0;
	    else if ((slTemp>>1)>=(pr[FMAX]<<15))
	   		fkey.ul = (pr[FMAX]<<16);
	   	else
	   		fkey.ul = (ULONG)slTemp;						
	}
}

void EnterAPRExe(void)
{
    LOOPFlag = 0;
    
	ONPosition = 0;
	MultiONPosition = 0;
	APR_uwOnPCNT = 0;

	EnterLoop = 0;
	APR_uwPCom = 0;
	APR_uwPFbk = 0;
	PcurveFlg = 0;
	APR_uwP2PMem = APR_uwPTarget;
    APR_uwThetaO2 = APR_uwThetaNoMx;
						
	if (CMDDIR2==FORWARD){
		APR_uwThetaO = SpDt_uwPG1CNT;
	}						
	else{
		APR_uwThetaO = 65535 - SpDt_uwPG1CNT;
	}						

}

void TB1_PositionControl(void)
{
    if (PositionCom==1){
		RUNDCI    = 0;
       	STOPDCI   = 0;
       	TB1_uwDCICnt = 0;
		          
		if ((APRExeFlag==0)&&(PcurveReach==0)&&(EXT_PG2REFMODE==0)){
		//=================================================================//
		//When Position Command ON, Looking forward "PsaccMax.ul" first,   //
		//PScurve is executed once time, when Pcurve reach at PTarget,     //
		//Set PcurveReach = 1, then APRExeFlag = 1, enter the APRExeFun()  //
		//=================================================================//
	    	APR_PScurve();
	    	if ((APR_uwPTarget-APR_uwPCom)<=1)
				PcurveReach = 1;
		}
			
		if (STOPgoAPR==1){
		//=================================================================//
		// STOP-> Position Command on -> RUN -> APR                        //
		//=================================================================//
	    	if (APRExeFlag==0){
				fkey.ul = (U32xU32divU32(PsaccMax.ul,pr[MPGGB],pr[MPGGA])) * pr[APRFFGA];               	
				
                if (PcurveReach==1){
				//---------------------------------------------------------//
				//When first Pcurve is executed, Pcurve reach at PTarget   //
				//Set APRExeFlag = 1 & clear some flags which be set on    //
				//First Pcurve, and will execute Pcurve second time        //
				//---------------------------------------------------------//
		    		if (APRFirstGo==1){
						APRExeFlag = 1;
						EnterAPRExe();
		    		}
                }
            }
        }
        else{
			//=================================================================//
			// RUN -> Position Command on -> APR                               //
			//=================================================================//        
	    	if (EXT_PG2REFMODE==0){		// PG2 Ref Speed Control        	        	
				if (APRExeFlag==0){	        		
		    		fkey.ul = (U32xU32divU32(PsaccMax.ul,pr[MPGGB],pr[MPGGA])) * pr[APRFFGA];
		    		if (fcmd.uw.hi==fkey.uw.hi){      	
						if ((APR_uwThetaNoMx<=10)||(APR_uwThetaNoMx>=(SpDt_ulPG1NpulseNoMx-10))){
			    			APRExeFlag = 1;
			    			EnterAPRExe();
						}
		    		}
				}
	    	}
        }
		
		if (APRExeFlag==1) 	
	    	TB1_APRExeFun(APR_uwP2PMem,APR_uwThetaNoMx);
    }
    else{
    	if ((pr[SysControl]&0x0004)==0x0004){	//System Control bit2 (Zero Servo)
	    	if ((fcmd.uw.hi==0)&&(pr[AUTO_T]==0)&&(Fcmd==0)&&(MFI_APRbyVcom==0)){
				if (ZeroServo==0){
		    		ZeroServo = 1;
		    		APRExeFlag = 1;
		    		APR_uwZOServoP = APR_uwThetaNoMx;
				}
	    	}
			else{
				if (ZeroServo==1){
		    		ZeroServo = 0;
		    		APRExeFlag = 0;
		    		LOOPFlag = 0;
				}       			
	    	}
	    	if (APRExeFlag==1)
				TB1_APRExeFun(APR_uwZOServoP,APR_uwThetaNoMx);
		}
	}
}

#ifdef _BK_APR_C
    #undef _BK_APR_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
