/*===============================================================
Author: Delta Electronic, INC. IABU, DEIN
                  
Project: VFD-VL

Filename: CM_FOCPM.C

Partner Filename: CM_FOCPM.H

Description: This is a sample code.

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:

History:
===============================================================*/
#ifndef _CM_FOCPM_C
	#define _CM_FOCPM_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

// ---------- FOCPM MAIN LOOP ------------------- //
/****************************************************************************
*******************ADDED BY SCOTTY 20060606**********************************
****************************************************************************/
void TB1_FOCPM(void) //1ms
{
	UWORD uwTemp;

    //float flTemp;				//clear Warning, Special.kung, 03/08/2023

    TB1_SpeedReg();				//calculate speed loop kp/ki gain
	TB1_CurrentReg();			//calculate current loop kp/ki gain
//    FLX_swFlxFreqPu = abs(CRM_slFlxFreqPu>>16);
	SPR_slTqRefLimPu = 30000;	//Scotty, 05/10/2007 100.00% rated torque

	// [ Add Current Limit, DINO, 06/17/2009, Modify by DINO, 11/27/2009
	uwTemp = (ULONG)pr[CURRENT_LIM] * 56300 >> 9;  //New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
	//uwTemp = U16xU16divU16((pr[CURRENT_LIM]*100), COF_uwIIratePu, COF_uwMIratePu);

	if(UCMP)
    {                 
        //[UCMP function, Bernie, 2016/06/14]  
	    uwTemp = U16xU16divU16((pr[CUR_LIM_UCMP]*100), COF_uwMIratePu, COF_uwMIratePu);
	}
    else if((MFI_btTorqDetect) || (BTTx_btTorqDetect))
    {
        //[JES Torq Detect Function, Special.Kung, 2022/09/01]
        //because pr[BTT100] dot1 so /10
        //pr[BTTx_TestTorq dot2 so *0.01
        //and TorqDetect output current should be 0.1/ 0.2/ .../ 1.0 times

        uwTemp = U16xU16divU16(((pr[BTT100]/10)*100), COF_uwMIratePu, COF_uwMIratePu);
        //uwTemp = uwTemp+(uwTemp*((pr[BTTx_TestTorq]*0.01)-1));

        //[Special.Kung, 2022/12/12]
        //Torque should 0.1�A0.2 multiple increase
        uwTemp = (uwTemp*(BTTx_uwTestStep*0.1));
    }
	else
    {
	    uwTemp = U16xU16divU16((pr[CURRENT_LIM]*100), COF_uwIIratePu, COF_uwMIratePu);
	}
	
	if (uwTemp > 30000){
    	SPR_swIqseRefLimPu = 30000;
	}
	else{
    	SPR_swIqseRefLimPu = uwTemp;
	} 
	// ]

	TqLimt();					//Scotty, 05/10/2007
}

void TB3_FOCPM(void) //500us
{
    fout.ul = ((ULONG)COF_uwFbRe * abs(CRM_slFlxFreqPu>>15));

    SPR_slSpdFdbPu = SpDt_slSpdFdbPu;		//SpDt_slSpdFdbPu : from TB3_SpDtPG1_LoIv()-500us
  	SPR_ulThetaFdb = SpDt_ulThetaR;			//100us obtain:SpDt_ulThetaR

	if ((pr[DEBUG_F1]&0x0800) != 0x0800){	// Debug flag bit 11 = 1 (Torque control for PM)
		SPR_slSpdRefPu = TB1_slSpdCmdPu;	//TB1_slSpdCmdPu 1ms updata
	}

	if (ALIGN !=0){ 						
		SpeedReg();
	}
}
extern const SWORD sine[1024];
extern const SWORD sine_high_resolution[16384]; //[Sin Table extend,Jason,2019/09/02]

void TB2_FOCPM(void) //100us
{
    SWORD swVrefSqu;
    UWORD uwULimit,uwWeakMagThetaId,uwWeakMagThetaIq,uwMaxVac,uwWeakMagThetaV,uwbaseV;  //[weak magnet, Sampo, 03/31/2011]
    ULONG ulVoutSqu;

   if((pr[SysControl]&0x0040)==0x0040){   //[weak magnet, Sampo, 03/31/2011]
       uwMaxVac = U16xU16divU16(DcbusDCLPF.sw.hi,pr[OVER_SCALE],1414);  //  Power-in = dcbus/sqrt(2)*1.15
       if(VcmdLLPF.sw.hi > uwMaxVac){        
           if ((pr[HPSPEC]&VFD440V)==VFD220V)
       	      uwbaseV = 500;  //230.0v - 180.0v
       	    else
       	      uwbaseV = 1000; //460.0v - 360.0v/
       	      
       	    uwWeakMagThetaV = U16xU16divU16((VcmdLLPF.sw.hi-uwMaxVac),(UWORD)pr[WEAKTHETA],uwbaseV);
       	      
       	    if (uwWeakMagThetaV > 30)
       	       uwWeakMagThetaV = 30;
       }
       else
         uwWeakMagThetaV = 1;
        
        uwWeakMagThetaId = U16xU16divU16(uwWeakMagThetaV,1024,360);
	    uwWeakMagThetaIq = U16xU16divU16((90-uwWeakMagThetaV),1024,360);
    }
    else{
       uwWeakMagThetaId = U16xU16divU16((UWORD)pr[WEAKTHETA],1024,360);
	   uwWeakMagThetaIq = U16xU16divU16((90-(UWORD)pr[WEAKTHETA]),1024,360);
	}

	CRM_swIdPu = 0;					//dead time compensation 2007/08/03	SCOTTY
	CRM_swIqPu = CUR_swIqseRefPu;	//dead time compensation 2007/08/03	SCOTTY
    CRM_slSpdPu = SpDt_slSpdFdbPu; 

	if (SpDt_uwPGErrTmp==0)
		CRM_ulThetaR = SpDt_ulThetaR;	
    
    CurrentMod_PMPG();					//��oSIN�BCOS�d����

    T32_swIasInPu = AD_swIAPu;
    T32_swIbsInPu = AD_swIBPu;
    abc2dq();
    
    TsE_swIdssInPu = T32_swIdssOutPu;
    TsE_swIqssInPu = T32_swIqssOutPu;
    Stat2Syn_s2e();

	PPI_FOCPM();  // New PPI Control, Add by DINO, 07/29/2010

    //-------- d - axis current regulator --------//
    if (ALIGN==0)
        CUR_swIdseRefPu =  U16xU16divU16(pr[DCICL],13107,100);		//pr[07-01]
    else{
    	if((pr[SysControl]&0x0100)==0x0100)    //[weak magnet, Sampo, 03/31/2011]
          CUR_swIdseRefPu =  -abs(S16xS16divS16((SPR_swIqseRefPu + SPR_swTqOfstPu),(sine[uwWeakMagThetaId]) ,32767));
        else
          CUR_swIdseRefPu = 0;
    }
    CUR_swIdseFdbPu = TsE_swIdseOutPu;         
	CurrentReg_daxis();    

    //-------- q - axis current regulator --------//
    if ( ALIGN==0 )
        CUR_swIqseRefPu = 0;	// Debug by DINO, 05/16/2011
    else{
//    	CUR_swIqseRefPu = SPR_swIqseRefPu;
       if((pr[SysControl]&0x0100)==0x0100 )    //[weak magnet, Sampo, 03/31/2011]
          CUR_swIqseRefPu = S16xS16divS16((SPR_swIqseRefPu + SPR_swTqOfstPu),(sine[uwWeakMagThetaIq]) ,32767);
       else{
    		// [ Position Control after Iq>6.25% Irated, DINO, 10/25/2010
    		if (ZEROSERVO)
    			CUR_swIqseRefPu = SPR_swIqseRefPu + SPR_swTqOfstPu;  // Start-up Position Control, Add by DINO, 10/04/2010
    		else
				CUR_swIqseRefPu = SPR_swIqseRefPu;
			// ]
		}
    }
    CUR_swIqseFdbPu = TsE_swIqseOutPu;
    CurrentReg_qaxis();    
    //-------- Feedforward decoupler ------------//
//   	FFD_swIqsePu = TsE_swIqseOutPu;
//   	FFD_swIdsePu = TsE_swIdseOutPu;
    FFD_swIqsePu = CUR_swIqseRefPu;
    FFD_swIdsePu = CUR_swIdseRefPu;
#if DINO
    FFD_swImPu = CRM_ImPuLPF.sw.hi;
#else
    FFD_swImPu = (CRM_slImPu >> 16);
#endif
    FFD_slFlxFreqPu = CRM_slFlxFreqPu;
	
    // [ FFD Function of FOCPM, Add by DINO, 06/03/2009
    if ((pr[CTRLSEL]&0x0001) == 0x0001){     // Bemf compensation enable
		FFD_voDecpl_PM();
    } 
    // ]
    else{
        FFD_swUdseOutPu = 0;
        FFD_swUqseOutPu = 0; 
    }

//-DINO 2008/02/20
	if ( EPS )
		uwULimit = COF_uwVEPSPu;
	else
		uwULimit = 0x7FFF;
//-END 2008/02/20 

    TeS_swUdseInPu = sl_limit_modify(CUR_swUdseOutPu, FFD_swUdseOutPu, uwULimit);
    TeS_swUqseInPu = sl_limit_modify(CUR_swUqseOutPu, FFD_swUqseOutPu, uwULimit);		
       			
#if 0
	//Ud^2+Uq^2 > Urate_max^2 = 32767^2 = 2^30
	ulVoutSqu = ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu) + ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu);

    if (ulVoutSqu >= 0x3FFFFFFF)
        ulVoutSqu = 0x3FFFFFFF;
#else
	//Ud^2+Uq^2 > Urate_max^2 = 32767^2 = 2^30
	ulVoutSqu =sl_limit_modify( ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu), ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu), 0x3FFFFFFF); //[Voltage saturate, Howard, 2018/10/23]
    if (ulVoutSqu >= 0x3FFFFFFF)
        ulVoutSqu = 0x3FFFFFFF;
#endif
    //swVrefSqu = bus voltage, if Vout> swVrefSqu volt_Sat_flag=1
    //Question : saturation & bus voltage relationship       
   	swVrefSqu = (((SLONG)FLX_swVsMaxPu*FLX_swVsMaxPu) >> 16) - 128; //1V/255V*32768 = 128
		
	if ((ulVoutSqu>>16) >= swVrefSqu){
		VolSat_flag = 1;
	}
	else{
		VolSat_flag = 0;
	}

    Syn2Stat_e2s();
    
    T23_swUqssInPu = TeS_swUqssOutPu;
    T23_swUdssInPu = TeS_swUdssOutPu;
    dq2abc();
    
	Duty_swTasInPu = T23_swUasOutPu;
	Duty_swTbsInPu = T23_swUbsOutPu;
	Duty_swTcsInPu = T23_swUcsOutPu;
    UabcPu2Duty();
    
    if (ulVoutSqu >= 0x3FFFFFFF)
        FLX_swVoutPu = 32767;
    else
        FLX_swVoutPu = uw_Sqrt32c_1(ulVoutSqu); //Q15
}


// [ New PPI Control, Add by DINO, 07/29/2010
void PPI_FOCPM(void)
{
    SWORD SPR_swPIVThidaErr, swTqOfstPu;
    SLONG_UNION SPR_sltemp, PIVUVCnt;
    SLONG SPR_slPIVThidaErr;

	if ((pr[SysControl]&0x0080)==0x0080 && (pr[DEBUG_F1]&0x0004)==0){	// bit2=0, New PPI Control

		if (RUNDCI==1 && BRK_RLS==1 && (uw_SCTEST8<(pr[POS_CTIME]*10))){

			// [ New Position Control, DINO, 10/25/2010
    		if ((pr[CTRLSEL]&0x0100) == 0x0100){  // bit8=1, enable PPI if Iq>6.25%MIrated
    			if (abs(CUR_swIqseRefPu)>(COF_uwMIratePu>>3)){
    				if (ZEROSERVO == 0){
						SPR_swPIVUVCnt = 0;  // Modify PPI overflow/underflow Counter, DINO,  05/25/2010
                		//SPR_slPIVthidaCom = MTU21.TCNT;
                        SPR_slPIVthidaCom = MTU1.TCNT;
                		if (PGDIR != 1){
                			SPR_slPIVthidaCom = -SPR_slPIVthidaCom;
                		}
                	}
    				ZEROSERVO = 1;
    			}
    		}
    		else{
    			ZEROSERVO = 1;
    		}

			if (ZEROSERVO){

				uw_SCTEST8 ++;

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
				else if (SPR_slPIVThidaErr < -0x7fff){   //[change minimun by Lyabryan, Lyabryan, 2015/03/10]
					SPR_swPIVThidaErr = -0x7fff;   //[change minimun by Lyabryan, Lyabryan, 2015/03/10]
				}
				else{
					SPR_swPIVThidaErr = (UWORD)SPR_slPIVThidaErr;
				}

                if(abs(SPR_swPIVThidaErr) <= pr[PPI_C]){                   //[PPI function, Sampo, 2015/09/08]
        	  	    SPR_swPIVThidaErr = 0;
                }
        	    else{
        	 	    if(SPR_swPIVThidaErr>0)
        	 	    	  SPR_swPIVThidaErr = SPR_swPIVThidaErr - (pr[PPI_C]);
        	 	    else
        	 	    	  SPR_swPIVThidaErr = SPR_swPIVThidaErr + (pr[PPI_C]);
        	 	   
        	    }

				// SPR_swTqOfstPu = ThetaErr * pr[PPI_P] / 1000000 * COF_uwMIratePu, 1% Err supply P% Current
				// In order to match the old definition of pr[PPI_P], multiple 5 of the pr[PPI_P], 1000000/5=200000
				SPR_sltemp.sl = S32xS32divS32(((SLONG)SPR_swPIVThidaErr*pr[PPI_P]), (SLONG)COF_uwMIratePu, 200000);

				// Iqe Compensation is limited by Irated of Motor
				if (SPR_sltemp.sl > COF_uwMIratePu){
					SPR_sltemp.sl = COF_uwMIratePu;
				}
				else if (SPR_sltemp.sl < -COF_uwMIratePu){
					SPR_sltemp.sl = -COF_uwMIratePu;
				}

				// [ New Position Control, DINO, 11/05/2010
				if (1){  //bit9=1 PPI Control Unipolar
    				UNI_ZEROSERVO = 1;

					if (UNI_ZEROSERVO){
						swTqOfstPu = SPR_swTqOfstPu;
						if (SPR_sltemp.sl >= 0){
							if (swTqOfstPu >= 0){
								if (SPR_sltemp.sl > swTqOfstPu){
									swTqOfstPu = SPR_sltemp.sw.low;
								}
							}
						}
						else{
							if (swTqOfstPu <= 0){
								if (SPR_sltemp.sl < swTqOfstPu){
									swTqOfstPu = SPR_sltemp.sw.low;
								}
							}
						}
						SPR_sltemp.sw.low = swTqOfstPu;
					}
				}
				// ]

				SPR_swTqOfstPu = SPR_sltemp.sw.low;
				SPR_TqOfstPu.sw.hi = SPR_swTqOfstPu;
			}	// End if (ZEROSERVO)
		}
		else{
			// Decrease Iqe Compensation to Zero after RUNDCI
		//	if (((RUNDCI == 0)&&(fcmd.uw.hi==Fcmd)) || ZEROSERVOEND==1){	// Dino, 12/07/2010
			if (RUNDCI == 0){	// Dino, 12/07/2010		
				ZEROSERVOEND = 1;
                //==============================================//
                //[PPI decrease cause Speed error,Jerry.sk,2020/04/15]

				/*-------------------------------------------------------------------------
				   Spend 6.5536sec decreasing Iqe from 100% to 0
				   Therefore, decrease slope is COF_uwMIratePu/32768
				   SPR_swTqOfstPu = SPR_swTqOfstPu * 2^16 - COF_uwMIratePu * 2^16 / 2^14
				                  = SPR_swTqOfstPu * 2^16 - COF_uwMIratePu
				-------------------------------------------------------------------------*/
				/*if (SPR_TqOfstPu.sl > 0){
					SPR_TqOfstPu.sl = SPR_TqOfstPu.sl - ((ULONG)COF_uwMIratePu<<1);  //DINO, 12/07/2010
					if (SPR_TqOfstPu.sl < 0){
						SPR_TqOfstPu.sl = 0;
					}
				}
				else if (SPR_TqOfstPu.sl < 0){
					SPR_TqOfstPu.sl = SPR_TqOfstPu.sl + ((ULONG)COF_uwMIratePu<<1);  //DINO, 12/07/2010
					if (SPR_TqOfstPu.sl > 0){
						SPR_TqOfstPu.sl = 0;
					}
				}





				SPR_swTqOfstPu = SPR_TqOfstPu.sw.hi;*/
				
			}
		}

	}
}
// ] End of 07/29/2010

#ifdef _CM_FOCPM_C
    #undef _CM_FOCPM_C
#endif

/************************************************************************
 Copyright (c) 2006 IABU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
