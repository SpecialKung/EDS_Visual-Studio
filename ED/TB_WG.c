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
#ifndef _TB_WG_C
	#define _TB_WG_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

#include "PR_SinTable.h"

void WG_Enable(void)
{
    WGON;
}
/*------------[ WG Disable ]----------------------------------------------*/
void WG_Disable(void)
{
    WGOFF;
}


void WG_Init(void)
{
	UWORD uwMaxcf;
	
    WGOFF;

    WGMODE = 0;

	if ( TUN_START ){
		experiod = U32divU16(MTU2CLK, 6000);  //6k, DINO, 05/19/2010
	}
#if StandStill
    // add by Dino, 07.25.2006
    // Use max carry to StandStill and HFI
    else if ( STtune ) {  /* Modify by dino, 04/03/2007 */
        if(pr[HPSPEC]>VFD_SINGLEPHASE)
            uwMaxcf = maxcf(pr[HPSPEC]-VFD_SINGLEPHASE) * 1000;
        else
            uwMaxcf = maxcf(pr[HPSPEC]) * 1000;
        experiod = U32divU16(MTU2CLK, uwMaxcf); 
    }
#endif
    else{
      	if (pr[CTRLM]==DBCSECA){
            experiod = DBC_period;
        }
        else{
			// [ Modify Derating Function, DINO, 09/01/2010
/*
            cf_swCFReal  = pr[SETCRF] * 1000;
            n_period     = U32divU16(MTU2CLK, cf_swCFReal);
            cf_swCFSet   = cf_swCFReal;
            cf_swOHCarry = cf_swCFReal;
    
            cfstep = 0;
            z0_cnt = 0;
            z1_cnt = 0;
            z2_cnt = 0;
            TB1_uwCCCnt = 0;
            cf_step1 =(cf_swCFReal + 4000)>>1;
*/
			n_period     = U32divU16(MTU2CLK, cf_swCFDerate);
            if (cf_swCFDerate >= 1500){
				experiod = n_period + (n_period>>1);
			}
			else{
				experiod = n_period;
			}
			// ]
        }
    }

    MTU.TCBRA = experiod;
    MTU3.TGRC = experiod + DeadTime;    

	if ( STtune ){  // initial the PWM register include the buffer
        MTU.TCDRA = experiod;
        MTU3.TGRA = experiod + DeadTime;
        MTU3.TGRB = PM_swTmin;
        MTU3.TGRD = PM_swTmin;
        MTU4.TGRA = PM_swTmax;    
        MTU4.TGRC = PM_swTmax;    
        MTU4.TGRB = PM_swTmax;    
        MTU4.TGRD = PM_swTmax;
	}
	else{
    	experiod_Buf = experiod;
    	PWM_swTaOut_Buf = experiod;
    	PWM_swTbOut_Buf = experiod;
    	PWM_swTcOut_Buf = experiod; 

        MTU3.TGRD = experiod;
        MTU4.TGRC = experiod;    
        MTU4.TGRD = experiod;
    }
}


void WG_isr(void)
{
	
    SWORD swIAtemp, swICtemp, sw_Itemp;
    ULONG ul_Itemp1;
    UWORD uwIrmsTmp;

    // fix cc issue, Sean, 11/08/2011
    // real-time current calculation

    swIAtemp   = adc_swIAtemp;       //[fix cc issue, Sean, 11/09/2011]
    swICtemp   = adc_swICtemp;
    sw_Itemp   = swIAtemp + swICtemp;
    ul_Itemp1  = (SLONG)sw_Itemp*sw_Itemp - (SLONG)swIAtemp*swICtemp ;       // Iu^2 + IuIw + Iw^2 = (Iu+Iw)^2 - IuIw
    sw_Itemp   = uw_Sqrt32c(ul_Itemp1);
    uwIrmsTmp    = ((SLONG)sw_Itemp * 63190) >> 15;  // 3.34/sqrt(3) = 63190/32768
	
	if (VH_EN==1){
		TB2_VF();
	}

#if 1	// add wgoff interception flag, Sean, 11/18/2010
	prt_ubWgEna = 0xff;
#endif 
    if ((STANDBY==0)&&(Error==0)&&(RUNNING==RUN)){

		// [ Short_Circuit Detection, DINO, 05/19/2010
		if ( BEFORERUN ){
		}
		// ]
    	else if ( STtune ) {
            if (AD_OK==0 && ((PhaseCnt&0x07)<6)){
				// [ Disable CC flag, add by DINO, 07/22/2007
                //POE2.ICSR1.BIT.POE0F = 0;	// Clear POE0 Flag, DINO, 06/25/2010
        		//POE2.ICSR1.BIT.PIE1 = 1;	// Enable OEI1 interrupt, dino, 11/11/2009
        		POE.ICSR1.BIT.POE0F = 0;	// Clear POE0 Flag, DINO, 06/25/2010       used in NMI
        		POE.ICSR1.BIT.PIE1 = 1;	// Enable OEI1 interrupt, dino, 11/11/2009
				// ] 
            	WGON;
            }
            else { WGOFF; }
        } 
        else if (/*IrmsAD uwIrmsTmp<CCR &&*/ CC_CHK==1){  // Debug OC Detection, DINO, 07/26/2010       // [fix cc issue, Sean, 11/09/2011]             
         	// [ Turn Off IGBT during falling time(step1 or step3) of MPHL Detection, Add by Sampo, 05/12/2009
         	//CC4display = 0;     //[CC Display, Bernie, 2017/04/12]
         	if((TB1_swMPHLstep&0x0001) == 0x0001){
				WGOFF; 
			}
			// ]
            else if (YDWGON==1){
      
     
#if	1
                //POE2.ICSR1.BIT.POE0F = CC_CHK ^1;
				//POE2.ICSR1.BIT.PIE1 = CC_CHK ^0; 

                POE.ICSR1.BIT.POE0F = CC_CHK ^1;  //CC HW FLAG
				POE.ICSR1.BIT.PIE1 = CC_CHK ^0;   //HW Protect interrupt enable/disable flag(1:enable, 0:disable)
                //if(POE2.ICSR1.BIT.POE0F==0 && POE2.ICSR1.BIT.PIE1==1){
				if(POE.ICSR1.BIT.POE0F==0 && POE.ICSR1.BIT.PIE1==1){

                    //MTU2.TOER.BYTE = prt_ubWgEna;
                    if(CC_CHK==1){             //[CC Display, Bernie, 2017/04/12]
                        MTU.TOERA.BYTE = prt_ubWgEna;
                    }
				}
#else		
				// [ Disable CC flag, add by DINO, 07/22/2007
                POE2.ICSR1.BIT.POE0F = 0;	// Clear POE0 Flag, DINO, 06/25/2010
        		POE2.ICSR1.BIT.PIE1 = 1;	// Enable OEI1 interrupt, dino, 11/11/2009
				// ]		
                WGON;
#endif                
            }
            else{
                WGOFF;
            }
        }
    }
}

#ifdef _TB_WG_C
	#undef _TB_WG_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
