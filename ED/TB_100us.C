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
#ifndef _TB_100us_C
	#define _TB_100us_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

#include "PR_SinTable.h"

UWORD uwWdtCnt;
void TimeBase_100us(void)
{
    UBYTE ubRxCnt;    
    UWORD uw_temp/*,vcmdPu_tmp*/;         //[weak magnet, Sampo, 03/31/2011]

    //UWORD uw_temp,uwIrmsTmp/*,vcmdPu_tmp*/;         //clear Warning, Special.kung, 03/08/2023
    //ULONG ul_Itemp1;                                //clear Warning, Special.kung, 03/08/2023
    //SWORD swIAtemp,swICtemp,sw_Itemp;               //clear Warning, Special.kung, 03/08/2023
    
#if DINO  // Read UVW state, 10/09/2007
    UWORD uwPGA, uwPGB, uwPGZ, uwHall;

    /*-------------------------------------------------------------------------
    --  uwPGA    uwPGB    uwPGZ  st_uwHallOld  Start_Section(Electrical angle)
    --    1        0        1          5           0         (    60.0 deg    )
    --    1        0        0          4           1         (   120.0 deg    )
    --    1        1        0          6           2         (   180.0 deg    )
    --    0        1        0          2           3         (   240.0 deg    )
    --    0        1        1          3           4         (   300.0 deg    )
    --    0        0        1          1           5         (     0.0 deg    )
    --
    --------------------------------------------------------------------------*/

    
    //if(Error != 0)
        //CC_S = 0;
    //else
        //CC_S = 1;
  
    switch(pr[PG_TYPE]){  //[For IED PG-Card, Sampo, 01/11/2010]
        case SIN_ENDAT:
  	        ubRxCnt = 4;
  	    break;
        case SIN_HIPER:
  	        ubRxCnt = 4;
  	    break;
        case SIN_SIN:
  	        ubRxCnt = 8;
  	    break;
        default:
  	        ubRxCnt = 16;
        break;
    }



    if ((pr[DEBUG_F1]&0x0008)==0x0008)
        ubRxCnt = 7;
	// add pghs01, Sean, 12/06/2010
	if ((Rx0CNT>=ubRxCnt)&&(Rx0CNT!=0xff)){	//[For IED PG-Card, Sampo
		TB_uwPg_Cnt = (TB_uwPg_Cnt<=10)?(TB_uwPg_Cnt+1):TB_uwPg_Cnt;
	}
	else{
		TB_uwPg_Cnt = 0;
	}
	
	
    //uwPGA = PA.PR.BIT.B6;	// U phase
    //uwPGB = PA.PR.BIT.B7;	// V phase
    //uwPGZ = PD.PR.BIT.B24;	// W phase
    uwPGA = PORT2.PIDR.BIT.B1;   // U phase
    uwPGB = PORT2.PIDR.BIT.B0;   // V phase
    uwPGZ = PORT9.PIDR.BIT.B2;   // W phase

	//-- Digital Filter, Added by DINO, 09/23/2008
    uwHall = (uwPGA<<2) + (uwPGB<<1) + uwPGZ;
    if ( uwHall==st_uwHallOld )
    	st_uwHallNew = uwHall;
    st_uwHallOld = uwHall;
#endif

	//_8051();   //USB FUNCTION BERNIE
//	USB_vdMonitor_Sample();	// USB Tx/Rx Handler 	// combine ED&USB, Sean, 20140819

  	//------ Read Data Register --------------------------------------------//
    
      if( pr[CTRLM]==FOCPM || !TUN_START) //[IM Autotune Modify,Sampo,2018/07/12]
        ReadAD();

/* // Yikai CC
    swIAtemp   = adc_swIAtemp;       //[fix cc issue, Sean, 11/09/2011]
    swICtemp   = adc_swICtemp;
    sw_Itemp   = swIAtemp + swICtemp;
    ul_Itemp1  = (SLONG)sw_Itemp*sw_Itemp - (SLONG)swIAtemp*swICtemp ;       // Iu^2 + IuIw + Iw^2 = (Iu+Iw)^2 - IuIw
    sw_Itemp   = uw_Sqrt32c(ul_Itemp1);
    uwIrmsTmp    = ((SLONG)sw_Itemp * 63190) >> 15;  // 3.34/sqrt(3) = 63190/32768
*/
    
    //if((pr[PROTECT_BIT]&0x0001)==0x0001){
        //OPHL2();   //[Output Phase Loss 2, Sampo, 2015/05/21]
    //}
    //------ Dead Time Calculation -----------------------------------------//
   	TB2_SpDtPG1();

   	CarryHandel();
    
    uw_temp = U16xU16divU16(dcbusDC, 18919, COF_uwVbRe); //Q15	SCOTTY 09/05/2007
	if (uw_temp >32767)
		uw_temp = 32767;
	FLX_swVsMaxPu = S16xS16divS16((SWORD)uw_temp,(SWORD)pr[LIMIT_SCALE],1000);   //[weak magnet, Sampo, 03/31/2011]
	
	
  /*  DcbusDCLPF2.sl += (SLONG)(dcbusDC - DcbusDCLPF2.sw.hi) * (UWORD)pr[WEAKLPF];	//DCbus  //[weak magnet, Sampo, 03/31/2011]
    
    if (pr[CTRLM]==FOCPM &&((pr[SysControl]&0x0040) == 0x0040)){   //[weak magnet, Sampo, 03/31/2011]
      
       Vsquare = ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu) + ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu);		
        if (Vsquare >= 0x3FFFFFFF)
            Vsquare = 0x3FFFFFFF;
   
        vcmdPu_tmp = uw_Sqrt32c(Vsquare); //Q15
    }

	if (vcmdPu_tmp > FLX_swVsMaxPu){
		vcmdPu_tmp = FLX_swVsMaxPu;
	}


	 vcmdPu_tmp = ((ULONG)vcmdPu_tmp * COF_uwVbRe + 32768)>>15; //Q0=Q(15-15)
	 Vcmd_LL2 = ((ULONG)vcmdPu_tmp * 40132)>>15; //Q0=Q(0+15-15)
     VcmdLLPF2.sl   += (SLONG)(Vcmd_LL2 - VcmdLLPF2.sw.hi) * (UWORD)pr[WEAKLPF];*/
     
     
    /*====== pr[PROTBIT] Control Bit setting ===============================*/
    /* Bit 1-0 : 0  -> Control GFF Check by POE                             */
    /*           1  -> Control GFF Check in 100us                           */
    /*           2  -> Disable GFF Check                                    */
    /*           3  -> Disable GFF Check                                    */
    /* Bit 2   : 0  -> Enable PHL                                           */
    /*           1  -> Disable PHL                                          */     
    /*     5   : 0  -> PG Error Process Enable                              */
    /*           1  -> PG Error Process Disable                             */
    /*     6   : 0  -> TB3_SpDtPG1_Err Enable                               */
    /*           1  -> TB3_SpDtPG1_Err Disable                              */
    /*     7   : 1  -> Disable CC function                                  */
    /* ---------------------------------------------------------------------*/
    /* Bit 8   : 1  -> Disable OCC protect                                  */
    /*     9   :                                                            */
    /*     10  :                                                            */
    /*     11  :                                                            */
    /* ---------------------------------------------------------------------*/
    /* Bit 12  :                                                            */
    /*     13  :                                                            */
    /*     14  :                                                            */
    /*======================================================================*/
   	
    if ((pr[PROTBIT]&0x0003)==0x0001){	// Bit 0,1: Control GFF Check in 100us
       if (GFF_CHK==0){
           PROTECT_GFF();
       }
    }    
   	
 //   if ((RUNNING==RUN)&&(Error==0)){	//09/05/2007
     if ((RUNNING==RUN)&&(Error==0 || (Error!=0 && WARNSTOPREC==1) ) && BEFORERUN==0){  //Short_Circuit Detection, DINO, 05/19/2010
		// [ Calculate MPHL Detected Output Voltage, Add by Sampo, 05/12/2009
    	if ( MPHL_DET ){
			TB2_VF();
		}
		// ]
        else if( TUN_START==1 ){
            if(pr[CTRLM]==FOCPM) //[IM Autotune Modify,Sampo,2018/07/12]
                TUN_ProcessTB2();
        }

        else if ( STtune ){
    	    TB2_PM();
    	}

        else{
            switch(pr[CTRLM]){    	
                default:
    	        case VF:
    	        case VFPG:    	        
    	        case SVC:
    	        	if (VH_EN==0)
    	            	TB2_VF();
    		        break;
    	        case FOC:
	    	    	TB2_FOC();
	    	    	break;
    	        case FOCPG:
    			case TQCPG:
                    TB2_FOCPG();
    	            break;
    	        case DBCSECA:
    	            DBC_PROCESS_TB2();
    		        break;
 		   
    		    case FOCPM:		//ADDED BY SCOTTY 2006/06/06
    		    	TB2_FOCPM();
    				break;
    
            }
            if ( pr[MPHLM]==1 ){ //[New OPHL Function,Jerry.SK,2019/12/28]
                if(((pr[PROTECT_BIT]&0x0001)==0x0000) && (EPS==0) && (CCSET == 0))//disable MPHL in EPS mode for GFC, James, 2020/08/03
        			OPHL_Detection();
            }
            
            CUR_swIqseRefPuOld = CUR_swIqseRefPu;	//Limit Current Change Rate, DINO, 10/25/2010
        }
    }

    //------ Dead Time Calculation -----------------------------------------//
    DBCValue();
           
    if (RTU_CNT2<0xFFFF){  // Keypad
    	RTU_CNT2++;
    }


// [ Transmit FIFO Data Empty, delay 1byte time then Initial SCIF3, DINO, 03/02/2010
	if (TXD_TDFE == 1){
		if(SCI2_ubCNT < SCI2_ubTXIDalay){    // Keypad
			SCI2_ubCNT++;
		}
		else{
			InitSCI2();
		}
	}
// ]
/*    if((STANDBY==0)&&(Error==0)&&(RUNNING==RUN)){ // Yikai CC
        if((uwIrmsTmp>=CCR) && ZEROC==1)
            WGOFF;
        else if((uwIrmsTmp<CCR) && ZEROC==1){
            ZEROC = 0;
            WGON;
        }
    }
*/    
    // [ Disable Interrupt, Add by DINO, 06/09/2009
    DINT();
    if (RTU_CNT3<0xFFFF){       //RTU_CNT1 ==> RTU_CNT3
    	RTU_CNT3++;
    }
     // [ PG Communication, DINO, 08/19/2010
    if (RTU_CNT0<0xFFFF){       //RTU_CNT4 ==> RTU_CNT0
    	RTU_CNT0++;
    }
    // ]

	EINT();
	// ]
}

void OPHL_Detection(void){ //[New OPHL Function,Jerry.SK,2019/12/28]
	//[OPHL,JerrySK,2019/12/13]
	
	UWORD OPHL_uw_fcmd, uwZeroCurCntLevl;
	SLONG sltmp;
	SWORD OPHL_swCur_errIdss, OPHL_swCur_errIqss;

	/*** Time Delay****/


	if(OPHL_swEst_Det_Delay <5000){
		OPHL_swEst_Det_Delay++;
	}


	if(pr[CTRLM]<=SVC)
	{
		/*****Stator Frequency Estimation*****/
		
		OPHL_uw_fcmd = ((fcmd.ul + VF_SlipLPF.sl) >> 16); 

		if(OPHL_uw_fcmd == 0)
		{
			OPHL_swEst_Det_Delay = 0;
		}
		
		if(T32_swIdssOutPu < 0)
		{
			OPHL_swIdss = -T32_swIdssOutPu;
		}else
		{
			OPHL_swIdss = T32_swIdssOutPu;
		}
		if(T32_swIqssOutPu < 0)
		{
			OPHL_swIqss = -T32_swIqssOutPu;
		}else
		{
			OPHL_swIqss = T32_swIqssOutPu;
		}
		
		
		if(OPHL_swIdss > OPHL_swIqss)
		{
			
			if((T32_swIqssOutPu>0 && T32_swIdssOutPu<0) || (T32_swIqssOutPu<0 && T32_swIdssOutPu>0))
			{
				OPHL_uwTheta = 46034 - arctan[U16xU16divU16(1023,(UWORD)OPHL_swIqss,(UWORD)OPHL_swIdss)];
			}else
			{
				OPHL_uwTheta = arctan[U16xU16divU16(1023,(UWORD)OPHL_swIqss,(UWORD)OPHL_swIdss)];
			}
		
		
		}else
		{
			if((T32_swIqssOutPu>0 && T32_swIdssOutPu>0) || (T32_swIqssOutPu<0 && T32_swIdssOutPu<0))
			{
				OPHL_uwTheta = 46034 - arctan[U16xU16divU16(1023,(UWORD)OPHL_swIdss,(UWORD)OPHL_swIqss)];
			}else
			{
				OPHL_uwTheta = arctan[U16xU16divU16(1023,(UWORD)OPHL_swIdss,(UWORD)OPHL_swIqss)];
			}
		}
	
		OPHL_uwTheta = U16xU16divU16(65535,OPHL_uwTheta,46034);
		OPHL_uwDeltaTheta = OPHL_uwTheta - OPHL_uwTheta_Z1;
		OPHL_uwTheta_Z1 = OPHL_uwTheta;
	
		OPHL_swEst_Sp_Filter_Z1 = (SWORD)OPHL_uwDeltaTheta * 1.907f; 
	
		// 1.907 = 100/(8*65535*100uS)
		// 8 is 360/45deg
		// 100 is dot 2
	
	
		OPHL_swEst_Sp_Filter = OPHL_swEst_Sp_Filter*0.99 + OPHL_swEst_Sp_Filter_Z1 * 0.01;
	
	
		if(OPHL_swEst_Sp_Filter>=0)
		{
			OPHL_swEst_Sp_Error = OPHL_uw_fcmd - OPHL_swEst_Sp_Filter;
		}else
		{
			OPHL_swEst_Sp_Error = OPHL_uw_fcmd + OPHL_swEst_Sp_Filter;
		}


		
	/***** Open Loop Control OPHL Detattion ****/
	
	
	
		if((OPHL_swEst_Sp_Error >= pr[OPHL_SPER] || OPHL_swEst_Sp_Error <= -pr[OPHL_SPER]) && OPHL_swEst_Det_Delay >=5000 && pr[OPHL_SPER] != 0)
			{
				OPHL_swEst_Err_Cnt++;
				if(OPHL_swEst_Err_Cnt >=pr[OPHL_ERCNT])
				{
                    OPHL_swEst_Err_Cnt = pr[OPHL_ERCNT];
					OPHL_swEst_Err_State = 1;
                    if(TB1_uwSTOErrCnt==0){
    					Error = MPHL_ERR;
                    }
                    TB1_swMPHLcnt  = 0;
                    LIFT_ENABLE    = 0;
                    TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
                    CMDFREE = 1;
				}
		}
		else if( (pr[OPHL_SPER] > (OPHL_uw_fcmd - 100) && (pr[OPHL_SPER] < (OPHL_uw_fcmd + 100))) && (OPHL_swEst_Sp_Error >= (pr[OPHL_SPER] >> 1) || OPHL_swEst_Sp_Error <= -(pr[OPHL_SPER] >> 1)) && OPHL_swEst_Det_Delay >=5000 && pr[OPHL_SPER] != 0)
		{
				OPHL_swEst_Err_Cnt++;
				if(OPHL_swEst_Err_Cnt >=pr[OPHL_ERCNT])
				{
                    OPHL_swEst_Err_Cnt = pr[OPHL_ERCNT];
					OPHL_swEst_Err_State = 1;
                    if(TB1_uwSTOErrCnt==0){
    					Error = MPHL_ERR;
                    }
                    TB1_swMPHLcnt  = 0;
                    LIFT_ENABLE    = 0;
                    TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
                    CMDFREE = 1;

				}
		}
		else
		{
			OPHL_swEst_Err_Cnt = 0;
	
		}



	}
    else
	{
		/*-------- Stationary frame -> Synchronous frame --------
		//	fdss =	cos(theta)*fdse - sin(theta)*fqse
		//	fqss =	sin(theta)*fdse + cos(theta)*fqse
		*/	
		sltmp = ((SLONG)CUR_swIdseRefPu * CosValue - (SLONG)CUR_swIqseRefPu * SinValue)>>15;
		if (sltmp >= 0x7FFF)
			OPHL_swIdss_cmd = 0x7FFF;
		else if (sltmp <= -0x7FFF)
			OPHL_swIdss_cmd = -0x7FFF;
		else		   
			OPHL_swIdss_cmd = sltmp;

		sltmp = ((SLONG)CUR_swIdseRefPu * SinValue + (SLONG)CUR_swIqseRefPu * CosValue)>>15;
		if (sltmp >= 0x7FFF)
			OPHL_swIqss_cmd = 0x7FFF;
		else if (sltmp <= -0x7FFF)
			OPHL_swIqss_cmd = -0x7FFF;
		else		   
			OPHL_swIqss_cmd = sltmp;


		OPHL_swCur_errIdss = OPHL_swIdss_cmd - T32_swIdssOutPu;
		OPHL_swCur_errIqss = OPHL_swIqss_cmd - T32_swIqssOutPu;
		if(OPHL_swCur_errIdss < 0)
		{
			OPHL_swCur_errIdss = -OPHL_swCur_errIdss;
		}

		if(OPHL_swCur_errIqss < 0)
		{
			OPHL_swCur_errIqss = -OPHL_swCur_errIqss;
		}
		OPHL_swCur_err =  OPHL_swCur_errIdss + OPHL_swCur_errIqss;

		OPHL_swCur_err_Filter = OPHL_swCur_err_Filter * 0.99 + OPHL_swCur_err * 0.01;


		OPHL_swCur_err_Limit = (SWORD)(pr[OPHL_CURER] * 1.44F);

		// Percent Current to Pu,  1.44 = 32767*1.1/2.5/10000 

        uwZeroCurCntLevl = pr[OPHL_ERCNT] * 0.8;

		if(OPHL_swCur_err_Filter >= OPHL_swCur_err_Limit && OPHL_swEst_Det_Delay >=5000 && pr[OPHL_CURER] != 0)
		{
			OPHL_swEst_Err_Cnt++;
			if(OPHL_swEst_Err_Cnt >=pr[OPHL_ERCNT])
				{
                    OPHL_swEst_Err_Cnt = pr[OPHL_ERCNT];
					OPHL_swEst_Err_State = 1;
                    OPHL_uwCurZeroState = OPHL_uwAPhZeroState + OPHL_uwBPhZeroState + OPHL_uwCPhZeroState;

                    if(TB1_uwSTOErrCnt==0){
                        switch(OPHL_uwCurZeroState)
                            {
                                case 0: // 0 phase zero current
                                    //Error = CurCtrl_ERR;
                                    OPHL_swEst_Err_Cnt = 0; // Jerry.SK.Tseng 2022/04/28 Closed CLCE Error
                                break;
                                
                                case 1:// one phase zero current
                                    if(OPHL_uwAPhZeroState == 1)
                                    {
                                        Error = OPHLU_ERR;
                                    }else if(OPHL_uwBPhZeroState == 1)
                                    {
                                        Error = OPHLV_ERR;
                                    }else
                                    {
                                        Error = OPHLW_ERR;
                                    }                                    
                                break;                               
                                case 2:
                                    Error = MPHL_ERR;
                                break;
                                
                                case 3:
                                    Error = MPHL_ERR;
                                break;

                                default:
                                    //Error = CurCtrl_ERR;
                                    OPHL_swEst_Err_Cnt = 0; // Jerry.SK.Tseng 2022/04/28 Closed CLCE Error
                                break;
                            }
                    }
                    if(OPHL_swEst_Err_Cnt != 0)// Jerry.SK.Tseng 2023/01/07 Closed CLCE Error
                    {
	                    TB1_swMPHLcnt  = 0;
	                    LIFT_ENABLE    = 0;
	                    TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
	                    CMDFREE = 1;
                    }
    		}

            // MPHL Improve Jerry.sk.Tseng 2021/07/22
                    
            if(AD_swIAPu < 720 && AD_swIAPu > -720) // 720 is 5% rated current (Maxumum value)
            {
                OPHL_uwAPhZeroCnt++;
                if(OPHL_uwAPhZeroCnt > uwZeroCurCntLevl)
                {
                    OPHL_uwAPhZeroState = 1;
                }

            }else
            {
                OPHL_uwAPhZeroCnt = 0;
                OPHL_uwAPhZeroState = 0;
            }

            if(AD_swIBPu < 720 && AD_swIBPu > -720) // 720 is 5% rated current (Maxumum value)
            {
                OPHL_uwBPhZeroCnt++;
                if(OPHL_uwBPhZeroCnt > uwZeroCurCntLevl)
                {
                    OPHL_uwBPhZeroState = 1;
                }
            }else
            {
                OPHL_uwBPhZeroCnt = 0;
                OPHL_uwBPhZeroState = 0;
            }

            if(AD_swICPu < 720 && AD_swICPu > -720) // 720 is 5% rated current (Maxumum value)
            {
                OPHL_uwCPhZeroCnt++;
                if(OPHL_uwCPhZeroCnt > uwZeroCurCntLevl)
                {
                    OPHL_uwCPhZeroState = 1;
                }
            }else
            {
                OPHL_uwCPhZeroCnt = 0;
                OPHL_uwCPhZeroState = 0;
            }            
		}else
		{
			OPHL_swEst_Err_Cnt = 0;
            OPHL_uwAPhZeroCnt = 0;
            OPHL_uwBPhZeroCnt = 0;
            OPHL_uwCPhZeroCnt = 0;
            OPHL_uwAPhZeroState = 0;
            OPHL_uwBPhZeroState = 0;
            OPHL_uwCPhZeroState = 0;
            OPHL_uwCurZeroState = 0;

		}

	}
}


void OPHL_Init(void){ //[New OPHL Function,Jerry.SK,2019/12/28]

    OPHL_swEst_Err_State = 0;
    OPHL_swEst_Err_Cnt = 0;
    OPHL_swEst_Det_Delay = 0;
    OPHL_swCur_err = 0;
    OPHL_swEst_Sp_Filter = 0;
    OPHL_swCur_err_Filter = 0;

    // MPHL Improve Jerry.sk.Tseng 2021/07/22
    OPHL_uwAPhZeroCnt = 0;
    OPHL_uwBPhZeroCnt = 0;
    OPHL_uwCPhZeroCnt = 0;
    OPHL_uwAPhZeroState = 0;
    OPHL_uwBPhZeroState = 0;
    OPHL_uwCPhZeroState = 0;
    OPHL_uwCurZeroState = 0;


}

#ifdef _TB_100us_C
    #undef _TB_100us_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
