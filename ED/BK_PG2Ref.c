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
#ifndef _PG2Ref_C
	#define _PG2Ref_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
#if SH7149	// dino, 03/08/2007
void Init_PG2Ref(void)
{	
	/*switch(pr[PGREFIN]){
		default:		
		case 1:
		    MTU22.TMDR.BYTE = 0x04;
		    PG2_ulNpulse = U32xU32divU32((pr[EPPR]<<2), pr[PGGA], pr[PGGB]);
			PGDIR2 = 1;
			break;
		case 2:
		    MTU22.TMDR.BYTE = 0x04;
		    PG2_ulNpulse = U32xU32divU32((pr[EPPR]<<2), pr[PGGA], pr[PGGB]);
			PGDIR2 = 0;
			break;
		case 3:
		    MTU22.TMDR.BYTE = 0x05;
		    PG2_ulNpulse = U32xU32divU32(pr[EPPR], pr[PGGA], pr[PGGB]);
			PGDIR2 = 1;
			break;
		case 4:
		    MTU22.TMDR.BYTE = 0x05;
		    PG2_ulNpulse = U32xU32divU32(pr[EPPR], pr[PGGA], pr[PGGB]);
			PGDIR2 = 0;
			break;
	}
	
    MTU22.TCNT = 0x0000;

	MTU2.TSTR.BIT.CST2 = 1;
	
	PG2_uwCNTNew = 0;*/

}

void TB1_PG2Ref(void)
{
	SWORD swTemp;
	
	//-------- Calculate PG2 Position ------------------------------------------//
	if (PGDIR2==0)
		PG2_uwCNTNew = 65535 - MTU22.TCNT;
	else
		PG2_uwCNTNew = MTU22.TCNT;
		
	swTemp = (SWORD)(PG2_uwCNTNew - PG2_uwCNTOrg);
	if (swTemp >= 0){	
	    if(swTemp >= PG2_ulNpulse){
		    swTemp = swTemp - PG2_ulNpulse;
			PG2_uwCNTOrg = PG2_uwCNTOrg + PG2_ulNpulse;
        }
       	PG2_uwTheta = swTemp;
	}
	else{
	    if((-swTemp) >= PG2_ulNpulse){
		    swTemp = swTemp + PG2_ulNpulse;
			PG2_uwCNTOrg = PG2_uwCNTOrg - PG2_ulNpulse;
		}
		PG2_uwTheta = PG2_ulNpulse + swTemp;
    }

   	APR_uwPG2PCom = ((ULONG)PG2_uwTheta * pr[PGGB])/pr[PGGA];
	//==========================================================================//
	
	if (PG2OverFlow==1){
		swTemp = (SWORD)(PG2_uwCNTNew + (65536 - PG2_uwCNTOld));
		PG2OverFlow = 0;
	}
	else if (PG2UnderFlow==1){
		swTemp = (SWORD)(PG2_uwCNTNew + (65536 - PG2_uwCNTOld));
		PG2UnderFlow = 0;
	}
	else{
		swTemp = (SWORD)(PG2_uwCNTNew - PG2_uwCNTOld);
	}
	
	#if 1	
		if (abs(swTemp)<=10){
			PG2_1msCNT++;
			PG2_swCNTIntgral = PG2_swCNTIntgral + swTemp;		
			if (PG2_1msCNT>20){
				PG2_slSpdCmd = S32xS32divS32((PG2_swCNTIntgral*100), (TB1CLK_Hz*COF_ubMPolePair), PG2_ulNpulse*PG2_1msCNT);
				PG2_1msCNT = 0;
				PG2_swCNTIntgral = 0;
			}
		}
		else{
			PG2_slSpdCmd = S32xS32divS32(((swTemp+PG2_swCNTIntgral)*100), (TB1CLK_Hz*COF_ubMPolePair), PG2_ulNpulse*(PG2_1msCNT+1));
			PG2_1msCNT = 0;
			PG2_swCNTIntgral = 0;
		}
		PG2_uwCNTOld = PG2_uwCNTNew;
	
	#else
	
		PG2_1msCNT++;
		if ((abs(swTemp)>=10)||(PG2_1msCNT>20)){
			PG2_slSpdCmd = S32xS32divS32((swTemp*100), (TB1CLK_Hz*COF_ubMPolePair), PG2_ulNpulse*PG2_1msCNT);
			PG2_1msCNT = 0;
			PG2_uwCNTOld = PG2_uwCNTNew;
		}
	
	#endif
	
	if (PG2_slSpdCmd>=(SLONG)pr[FMAX])
		PG2_slSpdCmd = (SLONG)pr[FMAX];
	else if (PG2_slSpdCmd<=(SLONG)(-pr[FMAX]))
		PG2_slSpdCmd = (SLONG)(-pr[FMAX]);

	PG2_ulSpdCmdLPF.ul = lowpass_ul(PG2R_uwCmdLPG,(UWORD)(abs(PG2_slSpdCmd)),PG2_ulSpdCmdLPF.ul);
	
   	if ((pr[PIDSL]!=0)&&(!MFI_PIDDIS)){
   		if ((pr[PIDSL]==2)||(pr[PIDSL]==5)){
       		pv = U16xU16divU16(KPDmax, abs(PG2_ulSpdCmdLPF.uw.hi), pr[FMAX]);
       	}
       	else if ((pr[PIDSL]==3)||(pr[PIDSL]==6)){
       		pv = S16xS16divS16(KPDmax, PG2_ulSpdCmdLPF.uw.hi, pr[FMAX]);
		}
   	}		

	// Control mode = FOCPG, PG2 Ref Position control
	if (EXT_PG2MODE==1){
		if ((pr[CTRLM]==FOCPG)&&(pr[SOFC]>4)){
			if (EXT_PG2REFMODE==1){		// PG2 Ref Position Control
				if (CMDRUN==RUN){				    
					PositionCom = 1;
					if (APRExeFlag==0){
						APRExeFlag = 1;
						
						MTU22.TCNT = 0; //PG2 Counter
        				PG2_uwTheta = 0;
        				PG2_uwCNTNew = 0;
        				PG2_uwCNTOrg = 0;        				
						PG2_uwCNTOld = 0;
        				
        				PG2_swCNTIntgral = 0;
        				PG2_slSpdCmd = 0;
						
						PG2_ulSpdCmdLPF.ul = 0;
						Psacc.ul = 0;
						PsaccMax.ul = 0;
					    
						EnterAPRExe();					    
					    APR_uwThetaO2 = U16xU16divU16(APR_uwThetaO2, 65535, SpDt_ulPG1NpulseNoMx);					    
					}
				}
			}
		#if 0	//2006/11/14 ARIX marked
			else if ((EXT_PG2REFMODE==0)&&(PositionCom==0)){
        		APR_status.ub = 0x00;
        		APR_status1.ub &= 0x08;	//keep Bit3 (APRFirstGo)
			} 	
		#endif
		}
	}
}
#endif
#ifdef _PG2Ref_C
    #undef _PG2Ref_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
