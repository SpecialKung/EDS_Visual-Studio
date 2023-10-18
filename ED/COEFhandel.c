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
#ifndef _COEFhandel_C
	#define _COEFhandel_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void COEFInitOnce(void)
{

	//-------- Frequency Base ----------------------------------------------//
	// Frequency sacle 100, 400.00Hz in program is 40000                    //
	COF_uwFbRe = 60000;	//scale 100
	
	//-------- Current Base ------------------------------------------------//
	// AD Max value is 1023, mapping to 2.5 time Reated current (rms)       //
	// S1 * (-1/3) + 2.5 V                                                  //
	// So, I base = Irated * 2.5 * sqrt(2)                                  //
	// where 231705 = 2.5 * sqrt(2) * 2^16                                  //
	if(pr[I_RATE] <= 15000)
    {
        COF_ulIbRe = ((ULONG)pr[I_RATE] * 231705) >> 16;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
    }else
    {
        COF_ulIbRe = ((ULONG)pr[I_RATE] * 115258) >> 15;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
    }
	
	if ((pr[HPSPEC]&VFD440V)==VFD220V)
	    COF_uwVbRe = VB220V;
	else
	    COF_uwVbRe = VB440V;

	//-------- Resistance Base ---------------------------------------------//
	// Power Base = Vb * Ib, where Vb scale 10 (L-L), Ib scale 100,         //
	// Unit of P is kW
	COF_uwPbRe = ((ULONG)COF_ulIbRe * COF_uwVbRe / 10); // Jerry.sk.tseng for GFC High elecator 2021/08/17
	
	COF_uwKUdcPuCnv = U16xU16divU16(512, 65535, COF_uwVbRe);
		
	//-------- Resistance Base ---------------------------------------------//
	// Rb = 1/Zb = Vb/Ib, where Vb scale 10 (L-L), Ib scale 100,            //
	// Unit of R is mOhm, so Rb scale 1000                                  //
	// where 1000 * 10 = 10000
	COF_uwRbRe = U32xU32divU32(COF_uwVbRe, 10000, COF_ulIbRe);  // Jerry.sk.tseng for GFC High elecator 2021/08/17
	
    //-------- Indutance Base ----------------------------------------------//
	// Lb = Rb/(2*pi*Fb), where Fb scale 100, Rb scale 1000                 //
	// Unit of L is uH, so Lb scale 1000000                                 //
	// So, 15916 = [1/(2*pi)] * 1000000 / 10                                //
	COF_uwLbRe = U16xU16divU16(COF_uwRbRe,15916,COF_uwFbRe);	
	
    //====== Inverter Max. Rated Current in pu =============================//
    // in Q15, 46341 = sqrt(2) * 32768
    COF_uwIIratePu = U32xU32divU32(pr[I_RATE] ,46341, COF_ulIbRe);  // Jerry.sk.tseng for GFC High elecator 2021/08/17
    if(pr[HPSPEC] > VFD_SINGLEPHASE){ //[Single phase input, Bernie, 01/19/2012]
        //====== Constant Torque Motor IratePu =================================//
        COF_uwCTIratePu = U32xU32divU32(CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE],46341, COF_ulIbRe);   // Jerry.sk.tseng for GFC High elecator 2021/08/17
        //====== Variable Torque Motor IratePu =================================//
        COF_uwVTIratePu = U32xU32divU32(VTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE],46341, COF_ulIbRe);   // Jerry.sk.tseng for GFC High elecator 2021/08/17
    }
    else{
        //====== Constant Torque Motor IratePu =================================//
        COF_uwCTIratePu = U32xU32divU32(CTispec[pr[HPSPEC]],46341, COF_ulIbRe);// Jerry.sk.tseng for GFC High elecator 2021/08/17
        //====== Variable Torque Motor IratePu =================================//
        COF_uwVTIratePu = U32xU32divU32(VTispec[pr[HPSPEC]],46341, COF_ulIbRe);// Jerry.sk.tseng for GFC High elecator 2021/08/17
	}	
	//====== Current model, theta step Gain ================================// 
    //--- Current model step, In Q16,65536*FB/FTB2, 10000 => 10KHz (100us)
    if (VH_EN==0)
		COF_ulKTheta = U32xU32divU32(COF_uwFbRe, (ULONG)(65536), TB2CLK_Hz);
	
    //====== Max. speed pu value ===========================================//
	SpdMaxPu = U32xU32divU32(pr[FMAX],0x7FFFFFFF,COF_uwFbRe); //Q31
	
    // 20589 = 2*pi*0.1*32768
    COF_uwTctrTb2Pu = U16xU16divU16(6000, 20589, TB2CLK_Hz);	//Q15
    // 2059 = 2*3.14*0.01*32768
	//COF_uwTctrTb2Pu = U16xU16divU16(60000, 2059, TB2CLK_Hz);	//Q15

    //====== EPS voltage pu value ==========================================//
   	// in Q15, 18919 = 32768 / sqrt(3)
	COF_uwVEPSPu = U16xU16divU16(pr[VEPS], 18919, COF_uwVbRe);  // EPS voltage PU, add by dino, 02/18/2008

#if !DINO
	//--2007/08/27 SCOTTY --		        
	if (pr[CTRLM]==FOCPM){
    	COF_uwIm1Pu = 0;
    	COF_uwRs1Pu = pr[PM_Rs];
    	COF_uwRr1Pu = 0;
    	COF_uwLm1Pu = 0;
    	COF_uwLx1Pu = pr[PM_Lq];
    			
	}
	else{
    	COF_uwIm1Pu = pr[MI_NL1];
    	COF_uwRs1Pu = pr[Rs1];
    	COF_uwRr1Pu = pr[Rr1];
    	COF_uwLm1Pu = pr[Lm1];
    	COF_uwLx1Pu = pr[Lx1];
	}
#else
    COF_uwIm1Pu = pr[MI_NL1];
    COF_uwRs1Pu = pr[Rs1];
    COF_uwRr1Pu = pr[Rr1];
    COF_uwLm1Pu = pr[Lm1];
    COF_uwLx1Pu = pr[Lx1];

    COF_uwIm3Pu = 0;
    COF_uwRs3Pu = pr[PM_Rs];
    COF_uwRr3Pu = 0;
    COF_uwLm3Pu = 0;
    COF_uwLx3Pu = pr[PM_Lq];
#endif

    COF_uwIm2Pu = pr[MI_NL2];
    COF_uwRs2Pu = pr[Rs2];
    COF_uwRr2Pu = pr[Rr2];
    COF_uwLm2Pu = pr[Lm2];
    COF_uwLx2Pu = pr[Lx2];
}

void Motor1Pr(void)
{
	ULONG_UNION FLimit;

    fbase 		= pr[MFBASE1];
    vbase 		= pr[VMAX1];   
    if(vbase == 0)            //[The minimum value setting of rated voltage, Bernie, 10/26/2011]
        vbase = 1;
    fmin 		= pr[FMIN1];

	COF_uwMIrRe = pr[MI_RAT1];		// STOP		1970
    COF_uwMPRe  = pr[P_RATED1];		// RUN		563
    COF_uwRPMRe = pr[RPM_RATED1];	// RUN		1710
    COF_uwPole  = pr[POLES1];		// STOP		4
    COF_uwMI0Re = pr[MI_NL1];		// STOP		875(876)
    COF_uwMRsRe = pr[Rs1];			// STOP		899(900)
    COF_uwMLmRe = pr[Lm1];  //6925j	// STOP		799(801)
    COF_uwSlipRe = fbase - U16xU16divU16(COF_uwRPMRe,COF_uwPole*100,120); // Rated Slip //*100 = DOT2  //[slip compensation function, Bernie, 2012/06/20]
    
	COF_uwI0Pu  = COF_uwIm1Pu;		// STOP		5241(5241)
    COF_uwRrPu  = COF_uwRr1Pu;//Q15	// STOP		6088(6088
    COF_uwRsPu  = COF_uwRs1Pu;//Q15	// STOP		4566
    COF_uwLxPu  = COF_uwLx1Pu;//Q10	// STOP		23925
    COF_uwLmPu  = COF_uwLm1Pu;//Q6	// STOP		2990
#if OLD_SETTING  // Modify by DINO, 09/09/2008
    OLSEL 		= pr[EOL1_SL];		// STOP
    OLDelayT 	= pr[EOL1_T];   	// RUN
#endif

	// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
	FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
	//FLimit.ul = (ULONG)pr[UPS_CAP] * 1000 * 37 / COF_uwMIrRe >> 6;
	if (FLimit.ul > vbase){
		COF_uwVUPSRe = vbase;
	}
	else{
		COF_uwVUPSRe = FLimit.uw.low;
	}
	// ]

	//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
	COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//[#13769 Modify EPS speed, James, 07/01/2020]
	pr[FEPS] = COF_uwFepsLimit;
}    

//--- PM Motor Parameter PU, Add by DINO, 09/09/2008
void Motor3Pr(void)
{
	ULONG_UNION FLimit;

    fbase 		= pr[MFBASE1];
    vbase 		= pr[VMAX1];           //[The minimum value setting of rated voltage, Bernie, 10/26/2011]
    if(vbase == 0)
        vbase = 1;
    fmin  		= pr[FMIN1];

	COF_uwMIrRe = pr[PM_MI_RAT];		// 1250
    COF_uwMPRe  = pr[PM_P_RATED];		// 340
    COF_uwRPMRe = pr[PM_RPM_RATED];		// 96
    COF_uwPole  = pr[PM_POLES];			// 24
    COF_uwMI0Re = 0;					// 0
    COF_uwMRsRe = pr[PM_Rs];			// 2498
    COF_uwMLmRe = 0;  //6925j			// 0

	COF_uwI0Pu 	= COF_uwIm3Pu;			// 0
    COF_uwRrPu 	= COF_uwRr3Pu;   //Q15	// 0
    COF_uwRsPu 	= COF_uwRs3Pu;   //Q15	// 12674
    COF_uwLxPu 	= COF_uwLx3Pu;	//Q10	// 20874
    COF_uwLmPu 	= COF_uwLm3Pu;	//Q6	// 0

	// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
	FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
//	FLimit.ul = (ULONG)pr[UPS_CAP] * 1000 * 37 / COF_uwMIrRe >> 6;
	if (FLimit.ul > vbase){
		COF_uwVUPSRe = vbase;
	}
	else{
		COF_uwVUPSRe = FLimit.uw.low;
	}
	// ]

	//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
	COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//[#13769 Modify EPS speed, James, 07/01/2020]
	pr[FEPS] = COF_uwFepsLimit;
}

void Motor2Pr(void)
{    
	ULONG_UNION FLimit;

	fbase 		= pr[MFBASE2];
    vbase 		= pr[VMAX2];
    fmin 		= pr[FMIN2];

    COF_uwMIrRe = pr[MI_RAT2];
    COF_uwMPRe  = pr[P_RATED2];
    COF_uwRPMRe = pr[RPM_RATED2];
    COF_uwPole  = pr[POLES2];
    COF_uwMI0Re = pr[MI_NL2];
    COF_uwMRsRe = pr[Rs2];
    COF_uwMLmRe = pr[Lm1];  //6925j

    COF_uwI0Pu  = COF_uwIm2Pu;
    COF_uwRrPu  = COF_uwRr2Pu;   //Q15
    COF_uwRsPu  = COF_uwRs2Pu;   //Q15
    COF_uwLxPu  = COF_uwLx2Pu;	//Q10    
    COF_uwLmPu  = COF_uwLm2Pu;	//Q6
#if OLD_SETTING  // Modify by DINO, 09/09/2008
    OLSEL 		= pr[EOL2_SL];
    OLDelayT 	= pr[EOL2_T];
#endif

	// [ Calculate UPS Speed Limit by UPS Capacity, DINO, 05/05/2010
	FLimit.ul = U32xU32divU32(((ULONG)pr[UPS_CAP]*37), 100000, ((ULONG)COF_uwMIrRe<<7));
	//FLimit.ul = (ULONG)pr[UPS_CAP] * 1000 * 37 / COF_uwMIrRe >> 6;
	if (FLimit.ul > vbase){
		COF_uwVUPSRe = vbase;
	}
	else{
		COF_uwVUPSRe = FLimit.uw.low;
	}
	// ]

	//COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase >> 1;  // Add by DINO, 05/22/2008
	COF_uwFepsLimit = (ULONG)COF_uwVUPSRe * fbase / vbase;//[#13769 Modify EPS speed, James, 07/01/2020]
	pr[FEPS] = COF_uwFepsLimit;
}

void TQRBaseInit(void)
{	
    UWORD uw_temp1, uw_ItoAcc;    
    ULONG ul_SPDFFDtemp, ultmp1, ultmp2, ulAlphaRe;
    ULONG_UNION	ul_temp, ulJbRe;

	//UWORD COF_uwTbReTmp, uw_temp, COF_uwJbRetable, uw_temp1, uw_ItoAcc;				//clear Warning, Special.kung, 03/08/2023

// [ Add by DINO, 03/06/2009
	COF_uwVBase1_4  = vbase >> 2;
	COF_uwVBase1_8  = COF_uwVBase1_4 >> 1;
	COF_uwFBase1_4  = fbase >> 2;
	COF_uwFBase3_10 = ((ULONG)fbase * 77) >> 8;  // 0.3 = 77/256
// ]

    //-------- Motor1 Pole Pair --------------------------------------------//
    COF_ubMPolePair = COF_uwPole >> 1;
//    COF_uwElecPole  = (360<<7) / (COF_ubMPolePair*6);    /* dino, 05/17/2007 */
	uw_ItoAcc = pr[Lift_ACCi] - 50;			
	if (uw_ItoAcc < 80){uw_ItoAcc = 80;}
    
/*===========================================================================
	calculate suitable inertia : using parameter diameter/rated speed(rpm)/rated power/max raising speed
	
	
         	  	  P_rated(08-02)*10        (watt)
      Trated = ------------------------------------ * 100    (dot2)
 	    	 	rpm_rated(08-03)*(2*pi)/60 (rad/s)

 				60 * 1000
      9549 = ---------------
      		  	  2*pi

02/16/2007--------------------	  

      1000 = Trated resoultion dot2 + P_rated resolution;  P_rated must be dot3 ,but 08-02 only own dot2
  
      20213 = (2pi)^2 *2^9 

      10000/2^2 = 2500
      
      2500 -> 25   considered JM resoultion must be dot4, but real Jm only has dot2		    
      
      			25 * 2^10
      256 =  --------------
      		   	   100
      		   
      100 = Trated resoltion dot2


05/09/2007-------------------
      						 		   COF_uwFbRe 	    1			  	  JbRe(dot2)
      [speed error * (2pi)^2 * 2^9 * -----------  * ---------- ](dot2)* ------------ * 100(dot2)  = 10000     
      								   2^16 *2^15	 polepair		 	 Trated(dot2)
			
			20213  * COF_uwFbRe  *JbRe * 100
	==>	--------------------------------------
			2^15 * Trated * polepair
	
	
			20213  * COF_uwFbRe  *JbRe * 100
	==>	--------------------------------------
			16384 * Trated * polepair


			20213  * COF_uwFbRe  *JbRe 
	==>	-------------------------------
			164 * Trated * polepair


10/14/2008 --- Modify by DINO ---

	//-- Rated Toruqe when acceleration (dot2) --//
		  	   Prated	         Prated*10(watt)           (Pr11_14-50)                  Prated      (Pr11_14-50) 
	Trated = ---------- = ----------------------------- * -------------- * 100(dot2) = ---------- * -------------- * 9549
		 	  RPMrated	   (RPMrated*(2*pi)/60)(rad/s)		    100		                RPMrated          100		   
                                                                                                    
	"Prated = Pr05_02 or Pr08_02; RPMrated = Pr05_03 or Pr08_03"


	//-- Angular Acceleration (dot2) --//
             (Pr.11_15 *10)(mm) * GearRatio * Suspension                                           Pr.11_15 * Pr.11_03 * Pr.11_04 * 10000
	Alpha = ----------------------------------------------- * (2*pi) * 5(tolerance) * 100(dot2) = ----------------------------------------
			               Diameter * pi                                                                          Pr.11_02

               RPMrated                       (RPMrated*(2*pi)/60)(rad/s)                                RPMrated
	      = --------------- * 5(tolerance) = ----------------------------- * 5(tolerance) * 100(dot2) = ---------- * Pr.11-15 * 26803 >> 512
			   Car Speed                                Pr.11-01                                         Pr.11-01
			  -----------                              ----------
			    Car Acc.                                Pr.11-15



	//-- Moment of Inertia --//
                       Trated                   Pr11_05
	Inertia J(dot2) = -------- * 10000(dot4) * ---------
                       Alpha                      100
=============================================================================*/  

//-- ADDED BY SCOTTY	02/16/2007----
#if SCOTTY
/*
//	uw_temp = U16xU16divU16(pr[Max_MperS], 2000, pr[SHEAVE_D]);		//dot1 w = v/r ;85 =0.85m/sec
//	uw_temp = U16xU16divU16(pr[Max_MperS], 7000, pr[SHEAVE_D]);		//tolerance 3.5 times
#if DINO  //-- Modify by DINO, 10/14/2008
	uw_temp    = U16xU16divU16(pr[Max_MperS], 10000, pr[SHEAVE_D]);	//tolerance 5 times
	uw_temp1   = pr[GearRatio] * (pr[SUSPENSION]+1);				//Suspension * GearRatio, 11/07/2008 DINO
	ulAlphaRe  = (ULONG)uw_temp * uw_temp1;
#else
	uw_temp    = U16xU16divU16(pr[Max_MperS], 10000, pr[SHEAVE_D]);	//tolerance 5 times
#endif
	COF_sltest1 = ulAlphaRe;

	/*---------------------------------------------------------------
	    New Angular Acceleration Calculation
	    Add by DINO, 12/29/2008
	---------------------------------------------------------------*/
	ulAlphaRe = ((ULONG)COF_uwRPMRe * 26803 + (pr[Lift_SPD]>>1)) / pr[Lift_SPD] * pr[Max_MperS] >> 9;


    uw_temp1   = (ULONG)uw_ItoAcc * 9545 / 100;						//Acc. Curremt
    ul_temp.ul = U32xU32divU32(COF_uwMPRe, uw_temp1, COF_uwRPMRe); 	//4775 = 9545>>1   0.5Trated
    ul_temp.ul = U32xU32divU32(ul_temp.ul, 10000, ulAlphaRe); 		//dot4   J = T/acc
    ulJbRe.ul  = U32xU32divU32(ul_temp.ul, pr[JM_PERCENT], 100); 	//pr[JM_PERCENT] is dot2
/*--- Delete by DINO, 11/06/2008
	if (ul_temp.ul >= 0xFFFF){ul_temp.ul = 0xFFFF;}
	else if (ul_temp.ul <= 1){ul_temp.ul = 1;}
	COF_uwJbRetable = (UWORD)ul_temp.uw.low;	/*  */
#endif 
//------ END	02/16/2007		----    
	//-------- Torque Base -------------------------------------------------//
	if ((pr[CTRLM] == FOCPM)){		//MODIFY 06/28
    	ulJbRe.ul	   /= 100;								// dot4 -> dot2, Modify by DINO 11/06/2008
		if (ulJbRe.ul >= 0xFFFF){ulJbRe.ul = 0xFFFF;}
		else if ( ulJbRe.ul==0 ){ulJbRe.ul = 1;}
		COF_uwJbRe		= ulJbRe.uw.low;
		ul_temp.ul		= U32xU32divU32(COF_uwMPRe, 9549, COF_uwRPMRe);	//Trated 0.01NM
		COF_uwKt		= U32xU32divU32(ul_temp.ul, 100, COF_uwMIrRe);	//0.01 N-M/A
		COF_uwTbRe		= ((ULONG)COF_ulIbRe * COF_uwKt) / 1000;		//0.1 N-M/A // Jerry.sk.tseng for GFC High elecator 2021/08/17
		SPR_uwKpKiGain	= U32xU32divU32(20213, ((ULONG)COF_uwFbRe*COF_uwJbRe),(ul_temp.ul*COF_ubMPolePair*164));  /* Scotty, 05/10/2007 */
		SPR_uwKrGain	= U32xU32divU32(12868, ((ULONG)COF_uwFbRe*COF_uwJbRe),(ul_temp.ul*COF_ubMPolePair*164));  /* Scotty, 07/19/2007 */
// Feedforward coefficient
// 6283 = 2*pi*1000				;1000 = 1/1ms		updata speed command per 1ms

    	ul_SPDFFDtemp	= U32xU32divU32(6283,COF_uwJbRe,COF_ubMPolePair);
    	ul_SPDFFDtemp	= U32xU32divU32(ul_SPDFFDtemp, 100, ul_temp.ul);		//dot2
    	COF_uwSPDPMFFD	= (UWORD)ul_SPDFFDtemp;

	}
	else{
//-- ADDED BY SCOTTY	02/16/2007----
		COF_uwJbRe = JmTalbe(COF_uwMPRe);  
	#if DINO	// 11/05/2008
		if ( (pr[DEBUG_F1]&0x1000)==0 ){	// Bit12=0, Calculate Moment of Inertia by Elevator Parameter, DINO, 11/07/2008
			EsJ_uwJmPu = (ulJbRe.ul << 8) / COF_uwJbRe;
			pr[JmPu]   = EsJ_uwJmPu;
		}
	#else
		if (pr[Jm_SELECT]){
			EsJ_uwJmPu = U16xU16divU16(COF_uwJbRetable, 2560, COF_uwJbRe);	
			pr[JmPu] = EsJ_uwJmPu;
		}
	#endif
//-- END 02/16/2007			----------	

		// Tb=1.5*np*Lb*Ib*Ib   ;unit:0.01NM
		ultmp1 = (ULONG)COF_ulIbRe * COF_ulIbRe;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
		ultmp2 = (ULONG)COF_uwLbRe * COF_ubMPolePair * 30;
		COF_uwTbRe = U32xU32divU32(ultmp1, ultmp2, 2000000000);
	
		SPR_uwKpKiGain	= U32xU32divU32(20213, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q9		     
		SPR_uwKrGain    = U32xU32divU32(12868, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q11		     
	}
}
void TQRMaxInit(void)
{
    //ULONG ul_temp;				//clear Warning, Special.kung, 03/08/2023
    
    if ((pr[CTRLM] == FOCPM)){
   		// Calculate Rated Torque of PM, Add by DINO, 09/30/2009
   		//====== Torque pu calculation =========================================//    	
   		//--- Reated torque 0.1Nm,  955 = (60/2pi)*100
   		COF_uwTqrateRe = U16xU16divU16(COF_uwMPRe, 955, COF_uwRPMRe);
   		// ]
    	//--- Rated torque pu value in 0.01%
    	COF_uwTqratePu = 10000;
    	//--- Torque max level setting in pu
    	COF_uwTqMaxPu = COF_uwTqratePu * pr[TQRMAX]/100; 
    }
    else{
   		//====== Torque pu calculation =========================================//    	
   		//--- Reated torque,  9549 = (60/2pi)*1000
   		COF_uwTqrateRe = U16xU16divU16(COF_uwMPRe, 9549, COF_uwRPMRe);
    	//--- Rated torque pu value in Q12
    	COF_uwTqratePu = U16xU16divU16(COF_uwTqrateRe, 4096, COF_uwTbRe);
    	//--- Torque max level setting in pu
    	COF_uwTqMaxPu = COF_uwTqratePu * pr[TQRMAX]/100;
	}
}

void MotorPrInit(void)
{
    UWORD uwIrated, uw_temp1, uw_ItoAcc;
    ULONG ulAlphaRe;
    ULONG_UNION ul_temp, ulJbRe;

	//UWORD PuTemp, uw_temp, uwIrated, uw_temp1, uw_ItoAcc;				//clear Warning, Special.kung, 03/08/2023

    /*------------------------ Add by dino 11.07.2006 ---------------------------------
    -- Calculate the current AD level for Stnadstill                                 --
    -- COF_uwSSIratedPu = COF_uwMIrRe * 1.6 / pr[I_RATE] / sqrt(2) / 2.5 * 512 * 2^6 --
    -- 1.6 = 29491 / 2^14                                                            --
    -- 1/sqrt(2) = 46341 / 2^16                                                      --
    -- 1/2.5 = 2/5                                                                   --
    ---------------------------------------------------------------------------------*/ 
	//-- COF_uwSSIratedPu only relative to pr[PM_MI_RAT], Modify by DINO, 09/09/2008
    if ( pr[STI]==0 ){
    	if ( pr[PM_MI_RAT] > pr[I_RATE] ){ uwIrated = pr[I_RATE]; }
    	else { uwIrated = pr[PM_MI_RAT]; }
    }
    else
    	uwIrated = pr[STI];
    COF_uwSSIratedPu = ((ULONG)uwIrated * 26214 / pr[I_RATE] * 46341 >> 14) / 5;
    
   	//====== Motor Max. Rated Voltage in pu ================================//
   	// in Q15, 26754 = sqrt(2/3) * 32768
   	COF_uwVratePu = U16xU16divU16(vbase, 26755, COF_uwVbRe);        
    
    //====== Motor Max. Rated Current in pu ================================//
    // in Q15, 46341 = sqrt(2) * 32768
    COF_uwMIratePu = U32xU32divU32(COF_uwMIrRe ,46341, COF_ulIbRe); // Jerry.sk.tseng for GFC High elecator 2021/08/17
    if (pr[CTSEL]==0)
        mspec = U16xU16divU16(COF_uwMIratePu, 100, COF_uwCTIratePu);
    else
        mspec = U16xU16divU16(COF_uwMIratePu, 100, COF_uwVTIratePu);

	uw_ItoAcc = pr[Lift_ACCi] - 50;			
	if (uw_ItoAcc < 80){uw_ItoAcc = 80;}

#if SCOTTY
/*
//	uw_temp = U16xU16divU16(pr[Max_MperS], 2000, pr[SHEAVE_D]);		//dot1 w = v/r ;85 =0.85m/sec
//	uw_temp = U16xU16divU16(pr[Max_MperS], 7000, pr[SHEAVE_D]);		//tolerance 3.5 times
#if DINO  //-- Modify by DINO, 10/14/2008
	uw_temp		= U16xU16divU16(pr[Max_MperS], 10000, pr[SHEAVE_D]);//tolerance 5 times
	uw_temp1   = pr[GearRatio] * (pr[SUSPENSION]+1);				//Suspension * GearRatio, 11/07/2008 DINO
	ulAlphaRe  = (ULONG)uw_temp * uw_temp1;
#else
	uw_temp		= U16xU16divU16(pr[Max_MperS], 10000, pr[SHEAVE_D]);//tolerance 5 times	10/15/2007 SC
#endif
	/*---------------------------------------------------------------
	    New Angular Acceleration Calculation
	    Add by DINO, 12/29/2008
	---------------------------------------------------------------*/
	ulAlphaRe = ((ULONG)COF_uwRPMRe * 26803 + (pr[Lift_SPD]>>1)) / pr[Lift_SPD] * pr[Max_MperS] >> 9;

    uw_temp1   = (ULONG)uw_ItoAcc * 9545 / 100;						//Acc. Curremt
	ul_temp.ul	= U32xU32divU32(COF_uwMPRe, uw_temp1, COF_uwRPMRe); //4775 = 9545>>1   0.5Trated
	ul_temp.ul	= U32xU32divU32(ul_temp.ul, 10000, ulAlphaRe); 		//dot4   J = T/acc
	ulJbRe.ul	= U32xU32divU32(ul_temp.ul, pr[JM_PERCENT], 100); 	//dot2
/*--- Delete by DINO, 11/06/2008
	if (ul_temp.ul >= 0xFFFF){ul_temp.ul = 0xFFFF;}
	else if (ul_temp.ul <= 1){ul_temp.ul = 1;}
	COF_uwJbRetable = (UWORD)ul_temp.uw.low;	/*  */
#endif 

	if ((pr[CTRLM] == FOCPM)){										//ADDED BY SCOTTY 2006/06/20
    	ulJbRe.ul	   /= 100;								// dot4 -> dot2, Modify by DINO 11/06/2008
		if ( ulJbRe.ul>=0xFFFF ){ulJbRe.ul = 0xFFFF;}
		else if ( ulJbRe.ul==0 ){ulJbRe.ul = 1;}
		COF_uwJbRe		= ulJbRe.uw.low;	
		ul_temp.ul		= U32xU32divU32(COF_uwMPRe, 9549, COF_uwRPMRe);  	//Trated 0.01NM
		COF_uwKt		= U32xU32divU32(ul_temp.ul, 100, COF_uwMIrRe);		//0.01 NM/A
		COF_uwTbRe 		= ((ULONG)COF_ulIbRe * COF_uwKt) / 1000;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
		SPR_uwKpKiGain	= U32xU32divU32(20213, ((ULONG)COF_uwFbRe*COF_uwJbRe),(ul_temp.ul*COF_ubMPolePair*164));  /* Scotty, 05/10/2007 */
		SPR_uwKrGain	= U32xU32divU32(12868, ((ULONG)COF_uwFbRe*COF_uwJbRe),(ul_temp.ul*COF_ubMPolePair*164));  /* Scotty, 07/19/2007 */
		// [ Calculate BEMF, Add by DINO, 06/03/2009
		COF_uwBemfPu = U16xU16divU16(pr[PM_Bemf], 26755, COF_uwVbRe);
   		// ]
	}
	else {
		//-------- Intertia Base -----------------------------------------------//
		//Intertia sacle 10000		
		COF_uwJbRe = JmTalbe(COF_uwMPRe);  
	#if DINO	// 11/05/2008
		if ( (pr[DEBUG_F1]&0x1000)==0 ){	// Bit12=0, Calculate Moment of Inertia by Elevator Parameter, DINO, 11/07/2008
			EsJ_uwJmPu = (ulJbRe.ul << 8) / COF_uwJbRe;
			pr[JmPu] = EsJ_uwJmPu;
		}
	#else
		if (pr[Jm_SELECT]){
			EsJ_uwJmPu = U16xU16divU16(COF_uwJbRetable, 25600, COF_uwJbRe);	
			pr[JmPu] = EsJ_uwJmPu;
		}	     
	#endif
    	//====== Inverse of rotor time constant ================================//
		//Tr_inv,  = (Lm/Rr) in Q(15+13-6)
    	COF_Tr_inv = U16xU16divU16(COF_uwRrPu, 8192, COF_uwLmPu); //Q22
// 0/16679
    	//IdsLPG = T*1/Tr = T*Rr/Lm = T*(RrPu/LmPu)*(Rb/Lb) = 2*pi*Fb*100us*Tr_inv
    	//24707 = 2*pi*Fb*100us*2^16
    	COF_uwIdsLPG = ((ULONG)24707 * COF_Tr_inv) >> 22; //Q16=Q(16+22-22)

    	//For Te = Kt * Iq
   		COF_uwKt = ((ULONG)COF_uwLmPu * COF_uwI0Pu) >> 13; //Q8 = Q(6+15-13)    
// 2705/1912
		EsJ_uwKJGain = U16xU16divU16((3183* COF_uwPole)<< 1, COF_uwTbRe, COF_uwFbRe); //Q1
		EsJ_uwKJGain = U16xU16divU16(EsJ_uwKJGain, 2048, COF_uwJbRe); //Q12		
		SPR_uwKpKiGain = U32xU32divU32(20213, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q9		     
		SPR_uwKrGain = U32xU32divU32(12868, ((ULONG)COF_uwFbRe*COF_uwJbRe),(10000*COF_uwTbRe*COF_ubMPolePair)); //Q11		     
	}

	// [ Calculate rated frequency, Add by DINO, 06/03/2009
	// Rated Freq. = Rated RPM / 60 * (P/2) * 100, dot0 -> dot2
	COF_uwMFrRe = ((ULONG)COF_uwRPMRe * COF_uwPole * 5) / 6;
	// ]

	// [ Calculate Flux Confirm Level, Add by DINO, 06/29/2009
	COF_uwI0DtLPu = (ULONG)COF_uwI0Pu * 717 >> 10;	// Flux Confirm Level is 70% Iflux, 717/1024=0.7
	// ]

}
void VFPG_Init_SlipMax(void)
{
    UWORD cx;

    // n = 120*f / p, f:frequency p:poles(2 pole pair)
    // n(RPM) = 60 * f / (pole pair)
    // s = (n - n1)/n, s:slip, n:synchronous rpm, n1:motor stable rpm
    cx = U16xU16divU16(fbase,60,COF_uwRPMRe);
    
    COF_PolePair = (UBYTE)(cx/100);
    COF_Poles = COF_PolePair<<1;    
    
    //-------- Rated Slip in RPM -------------------------------------------//
    // fbase scale 100, RPM don't scale , so RPM must (* 100)
    // COF_uwFslipRate scale 100.
    COF_uwFslipRate = (ULONG)fbase - (((ULONG)COF_uwRPMRe*COF_Poles*5)/6);   //Real
    COF_uwFslipMAX = COF_uwFslipRate * 2;
    
    COF_ulFslipRatePu = U32xU32divU32(COF_uwFslipRate,0x80000000,COF_uwFbRe);           //Q31    
    COF_ulFslipMAXPu = COF_ulFslipRatePu * 2;   //Q31, FslipMAX = 2 * Fslip
    
    COF_uwFRatePu = U32xU32divU32(fbase,0x8000,COF_uwFbRe);
}

#if StandStill	// dino, 2006/08/15
void STDutyInit(void)
{
    UWORD px, k, uwMinDuty, uwIrated;
    ULONG ulTGain;

    /*====================================================================
    --  Calculate the duty to reach 160 percent motor rated current     --
    --  at 32 PWM periods for StandStill                                --
    --                                                                  --
    --  Vbus = 1/L * ( dT / (irated*1.6) )	
    --    where 1.6 = 51>>5			--
    --  dT = L * irated / (dcbusDC/10) (us)                             --
    --  uwTGain = ( dT + 32 * deadtime ) * C.F. * 256 / 32              --
    --    where deadtime = 4(us)                                        --
    --------------------------------------------------------------------*/

    if ( pr[TGAIN]==0 ){
        if(pr[HPSPEC]>VFD_SINGLEPHASE)   //[Single phase input, Bernie, 01/19/2012]
            px = maxcf(pr[HPSPEC]-VFD_SINGLEPHASE);
        else
            px = maxcf(pr[HPSPEC]);
        k = dcbusDC;
        if ( pr[PM_MI_RAT] > pr[I_RATE] ){ uwIrated = pr[I_RATE]; }
        else{ uwIrated = pr[PM_MI_RAT]; }
        ulTGain = (((ULONG)pr[PM_Lq] * uwIrated * 10 * 51 >> 5) + (k>>1)) / k;
        ulTGain = (ulTGain + 128) * px * 8;
		uwTGain = (ulTGain + 500 ) / 1000;
        // (uwMinDuty/256)*(1/carry)us=4us=deadtime, duty can't smaller than deadtime
        // uwMinDuty = 4us * (carry*1e3) * 256 * 1e-6
        // 1024 = 256 *4
        uwMinDuty = ( (px<<10) + 500 ) / 1000;
		if ( uwTGain < uwMinDuty ){ uwTGain = uwMinDuty + 1; }
		else if ( uwTGain > 255 ){ uwTGain = 255; }
	}
    else { uwTGain = pr[TGAIN]; }
}
#endif

//--- Select Motor Parameter PU, Add by DINO, 09/09/2008
void MotorPrSel(void)
{
    if (pr[CTRLM]==FOCPM)		// Control Mode = PM MOTOR
        Motor3Pr();
    else if (pr[MOTORSEL]==2)	// Motor Select = MOTOR2
        Motor2Pr();
    else{
        if (EXT_MOTOR1to2==1)	// MOTOR2 Selected
        	Motor2Pr();
    	else					// MOTOR1 Selected
            Motor1Pr();
    }

    TQRBaseInit();
    TQRMaxInit();
    MotorPrInit();
}


#ifdef _COEFhandel_C
    #undef _COEFhandel_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
