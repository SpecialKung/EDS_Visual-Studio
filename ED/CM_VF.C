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
#ifndef _CM_VF_C
	#define _CM_VF_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"
#include "PR_SinTable.h"	// add by DINO, 2006/07/31

void Init_VF(void)
{
    Init_CurrentMod();
//    Init_SpDtPG1();
    Init_TransferValue();

    VF_swSlip = 0;
    VF_SlipLPF.sl = 0;
    
    VFTB1_swUoutPu = 0;
    
    VF_swUout = 0;
    VF_VcompPuLPF.sl = 0;
    
    PG_integral = 0;
    
}

void TB1_VFWsl_byPG(void)
{
	SLONG ax, ex, px;

    ax = U32xU32divU32(fcmd.uw.hi, 0x80000000, COF_uwFbRe);
    ex = ax - abs(SpDt_slSpdFdbPu);

    if (ex > 0){
        if (ex > COF_ulFslipMAXPu)
            ex = COF_ulFslipMAXPu;            
    }
    else{
        if (ex<(-((SLONG)COF_ulFslipMAXPu)))
            ex = -COF_ulFslipMAXPu;
    }
    //------ Proportional Gain ------------------//
    //px = S32xS16shlr16(ex, SPR_uwKpPu );
    px = S32xS16shlr16(ex, pr[SPP1]);
    //------ Integral Control -------------------//
    //ax = S32xS16shlr16(ex, SPR_uwKiPu);
    ax = S32xS16shlr16(ex, pr[SPI1]);

    PG_integral = sl_limit(PG_integral, ax, 0x7FFFFFFF);
    
    px = sl_limit(px,PG_integral,COF_ulFslipMAXPu);    

    fslip.ul = S32xS16shlr16(px, (COF_uwFbRe*2));

    //------ Low Pass filter of fSlip --------------------------------------//
    VF_SlipLPF.sl = lowpass_sl(VFfslip_uwLPG,fslip.uw.hi,VF_SlipLPF.sl);
}



void TB1_VFCal_Slin(void)
{
	float f1, f2;
    UWORD SrFr,fR_fS;
    ULONG temp1_ul, temp2_ul;

    //#define K4 (float)(3.535533906e-1)
    //#define K4 (float)(2.545584412e-1)  //multiply experience value 0.72
    //#define K4 (float)(2.262741700e-1)  //multiply experience value 0.64
    
    //#define K4 (float)(1.873832970e-1)  //multiply experience value 0.53
    
    //#define K4 (float)(1.767766953-1)  // no multiply experience value
    //#define K4 (float)(9.369164851e-2)  //multiply experience value 0.53
    //#define K4 (float)(7.778174593e-2)  //multiply experience value 0.44
    
    // K4 = 4 * sqrt(2)/ (sqrt(3) * 16) = 2.041341452
    #define K4 (float)(2.041241452e-1)
    //#define K4 (float)(1.571755918e-1)  //multiply experience value 0.77
    
    
    f1 = K4;
    SrFr = fbase - ((ULONG)COF_uwRPMRe*COF_Poles*100/120);
    fR_fS = fbase - SrFr;
    temp1_ul = ((ULONG)SrFr * fR_fS);
    
    f1 = f1*((float)temp1_ul);
    f1 = f1*((float)((SLONG)pr[I_RATE]*pr[SLIPC])); // [VF Slip compensator,Lyabryan,2016/05/12]
    f2 = (float)vbase*(float)COF_uwMIrRe*(float)pr[AD_IRATE]*(float)pr[PFEF];
    
    f1 = f1 / f2;
    temp1_ul = (ULONG)f1;
    
    if (temp1_ul != 0){
        f1 = f1 - (float)temp1_ul;                   
    }
    f1 = (float)4294967296*f1;   // 4294967295 = 65536*65536-1

    temp2_ul = (ULONG)f1;

    DINT();
    SlinI = temp1_ul;
    SlinF = temp2_ul;
    EINT();
    
    //     pr[AD_IARTE] * pr[VBASE] * MSPEC * pr[PFEF]
    //Tr = -----------------------------------------------
    //                ISPEC * (fbase - fslipRate)
    Tr =  U32xU32divU32((vbase*pr[AD_IRATE]),(COF_uwMIrRe*pr[PFEF]),(pr[I_RATE]*(fbase-COF_uwFslipRate)));
}

void set_VcmpMax(void) //GS3
{
        float f1;
        /*--------------------------------------------------------------*/
        /* VcmpMax = 10*sqrt(3)*150%*MotroRateCurrent*StatorResistance  */
        /*         = 10*sqrt(3)*1.5*pr[MI_RAT]/100*(pr[RS]/1000/2)      */
        /*         = (1.299038106e-4)*pr[MI_RAT]*pr[RS]                 */
        /*--------------------------------------------------------------*/

        /*--------------------------------------------------------------*/
        /* VcmpMax = 10*sqrt(3)*120%*MotroRateCurrent*StatorResistance  */
        /*         = 10*sqrt(3)*1.2*pr[MI_RAT]/100*(pr[RS]/1000/2)      */
        /*         = (1.039230485e-3)*pr[MI_RAT]*pr[RS]                 */
        /*--------------------------------------------------------------*/
        //f1 = (1.039230485e-3);  //120%
        //f1 = (1.732050808e-4);    //200%
        //f1 = (1.732050808e-6);    //200%
        //f1 = (1.732050808e-6);    //200%  //6a02j mask
        f1 = (8.66025404e-7);    //100%  //6a02j 100% =>100%
        VF_uwVcmpMax = f1*(float)COF_uwMIrRe*(float)COF_uwMRsRe*pr[VCMP_K];
}

void set_Rs(void)
{
       float f1;
       ULONG Rx;
       /*-----------------------------------------------------------------------------*/
       /* Rs = 4096*(V)/(I)=4096*(pr[RS]/1000)*10/sqrt(2)/(pr[AD_IRATE]/(pr[I_RATE]/100)) */
       /*    = 2.896309376*pr[I_RATE]*pr[RS]/pr[AD_IRATE]                              */
       /*-----------------------------------------------------------------------------*/
       //#define K1 (float)(2.896309376)
       //#define K1 (float)(0.1672184998) K1/sqrt(3)
       #define K1 (float)(2.896309376e-1)

       f1 = K1;
       Rx = f1* (float)((ULONG)pr[I_RATE]*COF_uwMRsRe)/(float)pr[AD_IRATE];
       if( Rx  > 65535)
          Rs = 65535;
       else
          Rs = Rx;
}

void TB1_VFWsl_byEst(void)
{
	SLONG slTemp1,slTemp2,fs1;
	ULONG RsRs;
	UWORD fmech, Pcore, cx, dx, trtemp, pgtemp;
	SWORD Iu, Iw, swTemp;	
	//======================================================================//
	//          1                                                           //
	// fslip = --- (sqrt(fm^2 + Slin*Pgap) - fm)                            //
	//          2                                                           //
	// Pgap = 3*V*I*PF - 3*Is^2*rs - Pcore                                  //
	//                                                                      //
	//        Is = sqrt(2/3)*sqrt(Iu*(Iu+Iw)+(Iw*Iw))                       //
	//        Is^2 = (2/3)*slTemp1                                          //
	// so, Culoss = 3*Is^2*rs                                               //
	//            = 2*slTemp1*rs                                            //
	//            = slTemp1 * Rs                                            //
	//======================================================================//
		
//	if ((!RESTART)&&(Error==0)&&(!SPSEARCH)&&(pr[AUTO_T]==0)){		//09/05/2007
	if ((!RESTART)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))&&(!SPSEARCH)&&(pr[AUTO_T]==0)){
        DINT();
        Iu = AD_swIAPu >> 2;
        Iw = AD_swICPu >> 2;
        EINT();
    
        I1 = ((SLONG)Iu*(Iu+Iw))+((SLONG)Iw*Iw);
        if ((SLONG)I1 < 0)
            I1 = 0;        

	    if (pr[SLIPC]!=0){ // [VF Slip compensator,Lyabryan,2016/05/12]
	        RsRs = ((ULONG)Rs << 16);
	        //RsRs = ((ULONG)Rs * 75674);     //75674 = 2/sqrt(3) in Q16	    
	        //RsRs = ((ULONG)Rs * 151349);    //151349 = 4/sqrt(3) in Q16
	        //RsRs = ((ULONG)Rs * 107020);    //107020 = 2*sqrt(2)/sqrt(3) in Q16
            Culoss = U32xU32shlr32(I1, RsRs);
        
            //Pin = ((SLONG)TsE_swIqseOutPu>>2)*VF_Vcmd*pr[SLIP_G]/100;     //sqrt(3)/2 in Q14 = 14189
            swTemp = ((SLONG)TsE_swIqseOutPu * 14189)>>16;  //14189 = sqrt(3)/2 in Q14
            Pin = ((SLONG)VF_Vcmd * swTemp);
        
            //slTemp1 = ((SLONG)TsE_swIqseOutPu * 14189)>>16;
            //slTemp1 = ((SLONG)TsE_swIqseOutPu * 34755)>>16; // 3/sqrt(2) in Q14
            //Pin = ((SLONG)slTemp1 * VF_Vcmd);
            //Pin = ((SLONG)slTemp1 * vtemp);
            
            //Coreloss = (((ULONG)vtemp* COF_uwMI0Re * pr[CORELOSS])/100);
            //B+: Pcore=u32div16(pr[AD_IRATE]*pr[CORELOSS], inl_A, pr[ISPEC]*10);
            //Coreloss = U16xU16divU16((pr[CORELOSS]*pr[AD_IRATE]), COF_uwMI0Re, (pr[I_RATE]*100));        
            //Coreloss = (((ULONG)vtemp * COF_uwI0Pu * pr[CORELOSS])/6400);
            Pcore = U32xU32divU32((pr[AD_IRATE]*pr[CORELOSS]), COF_uwMI0Re, (pr[I_RATE]*100));  // Bug - divisor overflow Jerry.sk.Tseng 2021/08/18
            Coreloss = (ULONG)vtemp * Pcore;

            PowerGap = Pin - Culoss - Coreloss;
        
            fmech = fcmd.uw.hi;
        
            if ((SLONG)PowerGap >= 0){
                slTemp1 = U32xU32shlr32(PowerGap,SlinF);
                slTemp2 = PowerGap*SlinI;
            }
            else{
                slTemp1 = -(U32xU32shlr32((-PowerGap),SlinF));
                slTemp2 = PowerGap*SlinI;
            }        
        
            fs1 = ((ULONG)fmech*fmech)+ slTemp1 + slTemp2;
        
       
            if ((SLONG)fs1  < 0) {   //check if fs1 < 0
                VF_swSlip = -(fmech>>1);
            }
            else {
                VF_swSlip = (uw_Sqrt32c(fs1) - fmech)>>1;
            }
            
            //------ NonLinear Compensation ---------------------//
            fs_nonlinear = 0;
    
            if (VF_swSlip >= 0){
                pgtemp = PowerGap>>11;                

                if (fcmd.uw.hi >= 6000)
                    dx = Tr << 1;   // 2Tr
                else {
                    cx = Tr >> 2;   //0.25Tr
                    dx = U16xU16divU16((Tr-cx),fcmd.uw.hi,fbase)+Tr+cx;
                }

                if (fcmd_vf.uw.hi >= 6000)
                    cx = 6000;
                else
                    cx = fcmd_vf.uw.hi;

                dx = ((ULONG)dx*cx*6)>>16;  //sqrt(3/2)*16/2048/100 in Q16 = 6.27069
        
                trtemp = ((ULONG)dx*pr[SLIPC])/100; // [VF Slip compensator,Lyabryan,2016/05/12]

                // None-linear torque approximations.
                if (pgtemp > trtemp){
                    if (pgtemp >= (trtemp<<1)) {
                        fs_nonlinear = COF_uwFslipRate;  
                    }
                    else{
                        cx = U16xU16divU16((pgtemp-trtemp),65535,trtemp);
                        dx = ((ULONG)cx*cx)>>16;    // x^2            
                        fs_nonlinear = ((ULONG)COF_uwFslipRate*dx)>>16;
                    }
                }
            }
    
            if (fcmd.uw.hi > 12000) //120.00Hz
                VF_swSlip = (VF_swSlip<<4) + fs_nonlinear;        
            else
                VF_swSlip = VF_swSlip + fs_nonlinear;            
	    }
	    else{
	        VF_swSlip = 0;
        }
    
        if (VF_swSlip >= (SWORD)COF_uwFslipMAX){
            VF_swSlip = (SWORD)COF_uwFslipMAX;
        }
        else{
            if ((SWORD)VF_swSlip < 0){
                if ((VF_swSlip+(SWORD)COF_uwFslipMAX)<= 0 )
    	            VF_swSlip = -(SWORD)COF_uwFslipMAX;
    	    }
        }
        
        if(VF_IqseOutPuLPF.sw.hi>=0)
            VF_swSlip = S16xS16divS16(VF_swSlip,pr[SLIPC_G],1000);
        else
            VF_swSlip = S16xS16divS16(VF_swSlip,pr[GENSL_G],1000);
        
        if (fcmd.uw.hi==0){
            VF_SlipLPF.sl = 0;
        }
        else{
            if (STALLC==0)
                //------ Low Pass filter of fSlip --------------------------//
                VF_SlipLPF.sl = lowpass_sl(VFfslip_uwLPG,VF_swSlip,VF_SlipLPF.sl);
        }
    }
    else{
       VF_SlipLPF.sl = 0;
    }    
}


void TB1_VFWsl_byAmp(void){  // [VF Slip compensator,Lyabryan,2016/05/12]

    UWORD InlAD, IflAD, InowAD, ax, bx;
    SWORD Iu, Iw;  

    //UBYTE ubGenSlGain, ubMotSlGain;       //clear Warning, Special.kung, 03/08/2023
    //UWORD uwSilpGain;                     //clear Warning, Special.kung, 03/08/2023
    //UBYTE imaskValue;                     //clear Warning, Special.kung, 03/08/2023
    /*-------------------------------------------------------------------------
    - ISUM = ASUM = 1.67V~5V (Rate~3Rate)                                     -
    - Rated current of INV IrmsAD = 341                                       -
    - Rated current of Motor IflAD = 341 * COF_uwMIrRe / pr[I_RATE]           -
    - No load Current of Motor InlAD = 341 * COF_uwMI0Re / pr[I_RATE]         -
    -                                                                         -
    -                                      |       --                         -
    -       G*((I)^2-(Inl)^2)^(1/2)        |      --                          -
    -    ---------------------------       |_____--                           -
    -       (Ifl)^2-(Inl)^2)^(1/2)   ,     |     |                            -
    -                                      |_____|___                         -
    --------------------------------------------------------------------------*/
    if(COF_uwSlipRe!=0){
        /*pr[AD_IRATE] = 512/2.5/sqrt(2) = 145*/
        /*sqrt(3/2) = (sqrt(3)/2)*sqrt(2)*/
        /* sqrt(3/2)*8*pr[AD_IRATE] = (9+(52295/65536))*pr[AD_IRATE]*/ //Q13
        ax = (pr[AD_IRATE]*9)+(((ULONG)pr[AD_IRATE]*52295)>>16);
        InlAD = U16xU16divU16(ax, COF_uwMI0Re, pr[I_RATE]);
        IflAD = U16xU16divU16(ax, COF_uwMIrRe, pr[I_RATE]);
        
        DINT();
        Iu = AD_swIAPu >> 3;
        Iw = AD_swICPu >> 3;
        EINT();
    
        I1 = ((SLONG)Iu*(Iu+Iw))+((SLONG)Iw*Iw);
        if ((SLONG)I1 < 0)
            I1 = 0;
        InowAD = uw_Sqrt32c(I1);
        //ubGenSlGain = pr[GENSL_G];
        //ubMotSlGain = pr[MOTSL_G];
        //if(GEN_MOT == 1)
            //uwSilpGain = (pr[SLIPC_G]*ubGenSlGain)/100;
        //else
            //uwSilpGain = (pr[SLIPC_G]*ubMotSlGain)/100;

        if(InowAD > InlAD){
            ax = uw_Sqrt32c((ULONG)(IflAD+InlAD)*(IflAD-InlAD));
            bx = uw_Sqrt32c((ULONG)(InowAD+InlAD)*(InowAD-InlAD));
            VF_swSlip = U32xU32divU32(COF_uwSlipRe, bx, ax);
            //VF_swSlip = U32xU32divU32(uwSilpGain, bx, ax*100);
        }
        else{
            VF_swSlip = 0;
        }
        
        if (fcmd.uw.hi>fbase){
            bx = U16xU16divU16(COF_uwFslipMAX, fcmd.uw.hi, fbase);
            if (VF_swSlip>bx)
                VF_swSlip = bx;
        }
        else{
            if (VF_swSlip>COF_uwFslipMAX)
                VF_swSlip = COF_uwFslipMAX;
        }
        
        if(VF_IqseOutPuLPF.sw.hi>=0)
            VF_swSlip = S16xS16divS16(VF_swSlip,pr[SLIPC_G],1000);
        else
            VF_swSlip = -S16xS16divS16(VF_swSlip,pr[GENSL_G],1000);
        if(STOPDCI||RUNDCI)
            VF_swSlip = 0;
        VF_SlipLPF.sl = lowpass_sl(VFfslip_uwLPG,VF_swSlip,VF_SlipLPF.sl);
    }
    else{
        VF_swSlip = 0;
        VF_SlipLPF.sl = 0;
    }
    
}


void TB1_NL_Boost(SWORD Vlimited)   //6a03j** NL_BIIST = constant
{
    SWORD nl_temp;       
    UWORD v_temp;
    nl_temp = pr[DBC1] + pr[DBC2];
    v_temp = U16xU16divU16(dcbusDC,23170, 32767); //dc-bus/sqrt(2) =>AC Voltage
    v_temp = U16xU16divU16(v_temp,nl_temp,32767);
    nl_boost = U16xU16divU16(v_temp,pr[NLBOOST], 100); //Q15  

}   //6a03j&&

void TB1_VFtq_boost(void)
{
    UWORD cx;
    SWORD Vcmp;
    
    if (pr[TQRC_G]!=0){
        if (fcmd_vf.uw.hi>500){
            cx = 500;   //60 degree, 750 is 90degree
        }
        else{
            // refer PF Angle
            cx = ((500*fcmd_vf.uw.hi)/600)+(500*100/600); 
        }
        
        if (TB1_uwPhi<=cx){
            cx = cx - TB1_uwPhi;
            if (cx > 250)
                cx = 250;
            Vcmp = pr[TQRC_G] * cx;
        }
        else
            Vcmp = 0;
        
        if ((NORMALSP==1)||(adjcnt>=5000))
            VF_VcompPuLPF.sl = lowpass_sl((VFVcomp_uwLPG>>2), Vcmp, VF_VcompPuLPF.sl);
        else
            VF_VcompPuLPF.sl = lowpass_sl((VFVcomp_uwLPG>>6), Vcmp, VF_VcompPuLPF.sl);
            
        if (adjcnt<5000)
            adjcnt++;
            
        if (COF_uwMRsRe!=0){
            if (VF_VcompPuLPF.sw.hi > VF_uwVcmpMax)
                Vcmp = VF_uwVcmpMax;
            else
                Vcmp = VF_VcompPuLPF.sw.hi;
            
            cx = VF_uwVcmpMax;
        }
        else{
            if ((pr[HPSPEC]&VFD440V)==VFD440V){
                if (VF_VcompPuLPF.sw.hi > 125)
                    Vcmp = 125;
                else
                    Vcmp = VF_VcompPuLPF.sw.hi;
            
                cx = 125;
            }
            else{
                if (VF_VcompPuLPF.sw.hi > 250)
                    Vcmp = 250;
                else
                    Vcmp = VF_VcompPuLPF.sw.hi;
            
                cx = 250;
            }                
        }
        TB1_NL_Boost(cx);
        tq_boost = Vcmp + nl_boost;
        
        if (tq_boost > VF_uwVcmpMax)
	        tq_boost = VF_uwVcmpMax;
	    else if (tq_boost < 0)
	        tq_boost = 0;
	}            
}

void TB1_SVCtq_boost(void)
{
    ULONG Em_square;
    SLONG Vs1_square,Vs1min_square;   //6925j
    SWORD IdRe, IqRe, Id_Rs, Iq_Rs, SVC_Vcmp;
    UWORD Vs_temp;  //6925j
    UWORD uwTemp;
    
	//=================================================================================//
	//       sqrt(2)                    Vso*fe  2    2            2          2         //
	// Vs = --------*Is(Re)*Rs + sqrt[(--------)  + ---(Is(Re)*Rs)  - (Is*Rs) ]        //
	//         3                          fr         9                                 //
	//                                                                                 //
	// Vs = (Iqse/sqrt(2))*Rs + sqrt(V^2 - ((Idse/sqrt(2))*Rs)^2)                      //
	//      Rs = COF_uwMRsRe/2;                                                        //
	//=================================================================================//
//	if ((!RESTART)&&(Error==0)&&(!SPSEARCH)&&(pr[AUTO_T]==0)){	//09/05/2007
	if ((!RESTART)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))&&(!SPSEARCH)&&(pr[AUTO_T]==0)){
        /*VF_slIqeLPF.sl = lowpass_sl((pr[IDQELPFG]<<2),TsE_swIqseOutPu,VF_slIqeLPF.sl);
        VF_slIdeLPF.sl = lowpass_sl((pr[IDQELPFG]<<2),TsE_swIdseOutPu,VF_slIdeLPF.sl);

        if ((fcmd.uw.hi<=pr[LOW_SPEED])&&(IrmsRe>=COF_uwMIrRe)){
            IdRe = VF_slIdeLPF.sw.hi;
            IqRe = VF_slIqeLPF.sw.hi;
        }  
        else{
            IdRe = TsE_swIdseOutPu;
            IqRe = TsE_swIqseOutPu;
        }*/    //6925j mask
        
        IdRe = TsE_swIdseOutPu;   //6925j 
        IqRe = TsE_swIqseOutPu;   //6925j
                          
        
	    Em_square = ((ULONG)vtemp * vtemp);
	    // TsE_swIdseOutPu in Q15 , 
	    // so, IdRe = (TsE_swIdseOutPu/32768)* 2.5 * sqrt(2) * pr[I_RATE]
	    // where 2.5 * sqrt(2) * pr[I_RATE] = COF_uwIbRe
	    //IdRe = ((ULONG)TsE_swIdseOutPu * COF_uwIbRe)>>15;	    
	    //IdRe = ((SLONG)TsE_swIdseOutPu * pr[I_RATE] * 4)>>16;
	    uwTemp = ((ULONG)pr[I_RATE] * 141890)>>16;  // 141890 = 2.5*sqrt(3)/2 in Q16
	    IdRe = ((SLONG)IdRe * uwTemp)>>15;
        IqRe = ((SLONG)IqRe * uwTemp)>>15; //6925j
	
	    Id_Rs = S16xS16divS16(IdRe, COF_uwMRsRe, 10000);
        Iq_Rs = S16xS16divS16(IqRe, COF_uwMRsRe, 10000); //6925j
	    // where 20000 = 2 * 1000 * 10
	    // 2, COF_uwMRsRe is Resistance of Line-Line, in calculation, Rs should be Resistance of phase
	    // 1000, COF_uwMRsRe scale 1000
	    // 10, voltage scale 10, current scale 100, so divide 10 to have same sacle
	
	    Vs1_square = Em_square - (Id_Rs*Id_Rs);	
        
        if((pr[SysControl]&0x0010)==0x0010){  // System Control Bit 4 = 1 (Vsmin limited by XmI0)
            Vs_temp = U16xU16divU16(63*pr[LOW_SPEED],COF_uwMLmRe,10000);  //2*pi*10=63  scaler=100*10*10
            Vs_temp = U16xU16divU16(Vs_temp,COF_uwMI0Re,10000);           //Vsmin limited by XmI0
            Vs1min_square = Vs_temp * Vs_temp;       
        }
        else if((pr[SysControl]&0x0010)==0x0000){  // System Control Bit 4 = 0 (Vsmin limited by Vbase)
            Vs_temp = U16xU16divU16(pr[LOW_SPEED],vbase,fbase);  //v/f =1.5HZ=>5.5V/220V;11V/440V
            Vs1min_square = Vs_temp * Vs_temp;       
        }  //6925j&&
        	
        //if ((SLONG)Vs1_square < 0)   //6925j mask
	    //    Vs1_square = 0; //6925j mask
	    
       if((SLONG)PowerGap < 0){
            if ((SLONG)Vs1_square < Vs1min_square )  //6925j  
    	        Vs1_square =  Vs1min_square;  //6925j
       }
       else{
	    if ((SLONG)Vs1_square < 0)
	        Vs1_square = 0;
       }
	    //IqRe = ((SLONG)TsE_swIqseOutPu * COF_uwIbRe)>>15;
	    //IqRe = ((SLONG)TsE_swIqseOutPu * pr[I_RATE] * 4)>>16;
	    //uwTemp = ((ULONG)pr[I_RATE] * 141890)>>16;  // 141890 = 2.5*sqrt(3)/2 in Q16  //6925j mask
	    //IqRe = ((SLONG)IqRe * uwTemp)>>15; //6925j mask
	    
	    //Iq_Rs = S16xS16divS16(IqRe, COF_uwMRsRe, 10000);  //6925j mask
	    //SVC_Vcmp = Iq_Rs + uw_Sqrt32c(Vs1_square) - vtemp;  //6925j mask
        SVC_Vcmp = Iq_Rs + uw_Sqrt32c(Vs1_square) - vtemp + 2;  //6925j
            
	    if ((NORMALSP==1)||(adjcnt>=5000))
	        VF_VcompPuLPF.sl = lowpass_sl(VFVcomp_uwLPG, SVC_Vcmp, VF_VcompPuLPF.sl);
	    else
	        VF_VcompPuLPF.sl = lowpass_sl((VFVcomp_uwLPG>>4), SVC_Vcmp, VF_VcompPuLPF.sl);
	
	    if (adjcnt<5000)
	        adjcnt++;
	
	    if (VF_VcompPuLPF.sw.hi > VF_uwVcmpMax)
	        VF_VcompPuLPF.sw.hi = VF_uwVcmpMax;
	
	    TB1_NL_Boost(VF_uwVcmpMax);
	
	    tq_boost = VF_VcompPuLPF.sw.hi + nl_boost;
	
	    if (tq_boost > VF_uwVcmpMax)
	        tq_boost = VF_uwVcmpMax;
	    else if ((SWORD)tq_boost < 0)
	        tq_boost = 0;
	}
	else{
	    tq_boost = 0;
	}
}

void TB1_VF(void)
{   
    UWORD fx, fx1;
        
    TB1_SpeedReg();
    
    switch(pr[CTRLM]){
    	default:
    	case VF:               	        
            SPR_slSpdRefPu = TB1_slSpdCmdPu;
            SPR_slSpdFdbPu = TB1_slSpdCmdPu;
            TB1_VFtq_boost();
            TB1_VFWsl_byAmp();   // [VF Slip compensator,Lyabryan,2016/05/12] //[slip compensation function, Bernie, 2012/06/20]
            //TB1_VFWsl_byEst();
    	    break;    	
        case VFPG:            
            SPR_slSpdRefPu = TB1_slSpdCmdPu;
            SPR_slSpdFdbPu = SpDt_slSpdFdbPu;            
            TB1_VFtq_boost();
            TB1_VFWsl_byPG();            
            break;
        case SVC:    	    
            SPR_slSpdRefPu = TB1_slSpdCmdPu;
            SPR_slSpdFdbPu = TB1_slSpdCmdPu;	
            TB1_SVCtq_boost();
            TB1_VFWsl_byEst();      
            break;            
    }   
        
    if (TUN_START==0){    
        if (fcmd.uw.hi < pr[FMAX]){
            if (pr[VFSL]==1) {            //vx ^ 1.5
                fx = ((ULONG)fcmd.uw.hi<<16)/pr[FMAX];
                fx1 = ((ULONG)fx*fx)>>16;
                fcmd.uw.hi = ((ULONG)pr[FMAX]*uw_Sqrt32c((ULONG)fx1*fx))>>16;
            }    
            else if (pr[VFSL]==2){        //vx ^ 2.0
                fx = ((ULONG)fcmd.uw.hi<<16)/pr[FMAX];
                fcmd.ul = (((UDOUBLE)(ULONG)fx*fx)*pr[FMAX])>>16;
            }    
        }        
    
        // Auto Engery Saving
        if (PWRSaveCNT >= 30){
            if (TB1_uwPhi >= 542){
                if(v_save<(((ULONG)vtemp*19661)>>16))     // 30%
                    v_save ++;
            }
        }
        else{   // savecnt < 30
            if(v_save!=0)
                v_save --;
        }
    }
    else {         // if(TUN_ST !=0)
    	v_save = 0;
    }
    
//    if(abs(fcmd.ul-abs(VF_SlipLPF.sl))<(fcmd.ul*3/100)) // [VF Slip compensator,Lyabryan,2016/05/12]//[remove,Jason,2019/08/15]
//        VF_SlipLPF.sl = 0;
		
    if (VF_SlipLPF.sl<0){
    	if (fcmd.ul<abs(VF_SlipLPF.sl))
    		fcmd_vf.ul = 0;
    	else
    		fcmd_vf.ul = fcmd.ul + VF_SlipLPF.sl;
	}
	else{
		fcmd_vf.ul = fcmd.ul + VF_SlipLPF.sl;
	}
    
    if (fcmd_vf.uw.hi>65500)
        fcmd_vf.ul = 0xFFDC0000;
    
    
    if ((RUNDCI==0)&&(STOPDCI==0)&&(SPSEARCH==0)&&(YDWGON==1)){
        vtemp = GetFx2Vm(fcmd_vf.uw.hi);
        fx = vtemp + tq_boost - v_save;
        if ((SWORD)fx<0)
            fx = 0;
            
        if (fx > vbase)
            fx = vbase;
        VF_Vcmd = fx;
    }    
    
    VFTB1_swUoutPu = U16xU16divU16(VF_Vcmd , 26755, COF_uwVbRe);    //26754 = sqrt(2/3) * 32767 
    
    if ((UWORD)VFTB1_swUoutPu >= COF_uwVratePu)
        VFTB1_swUoutPu = COF_uwVratePu;

//-DINO 2008/02/18
	if ( EPS ){
    	if ((UWORD)VFTB1_swUoutPu >= COF_uwVEPSPu)
        	VFTB1_swUoutPu = COF_uwVEPSPu;
	}
//-END 2008/02/18

    VF_swUout = VFTB1_swUoutPu;
    
    //-------- Hunting Compensation --------    
    if ((pr[K_HUNT]!=0)&&(fcmd.uw.hi>500)&&(VH_EN==0)){
        delta_cosphi = cosphi_z1 - TB1_swCosphi;
        cosphi_z1 = TB1_swCosphi;
        fhunt.sl = (SLONG)delta_cosphi*pr[K_HUNT];
    }
    else
        fhunt.sl = 0;

    //-------- End of Hunting Compensation ------
        
    fout.ul = fcmd_vf.ul;

}

void TB2_VF(void)
{
    UWORD TB2_TMP;    
 #if 1
 /*test*/	
    T32_swIasInPu = AD_swIAPu;
    T32_swIbsInPu = AD_swIBPu;
    abc2dq();
    
    TsE_swIdssInPu = T32_swIdssOutPu;
    TsE_swIqssInPu = T32_swIqssOutPu;
    Stat2Syn_s2e();
    //TsE_swIdseOutPu
    //TsE_swIqseOutPu
 /*test end*/
 #endif
	
    
    CUR_swUdseOutPu = 0;
    CUR_swUqseOutPu = VF_swUout;
    TB2_TMP = U32divU16(((ULONG)DcbusDCLPF.sw.hi*18918),COF_uwVbRe);
    TB2_TMP = ((ULONG)TB2_TMP*pr[MOD_INDEX])/100;
//    if ((UWORD)CUR_swUqseOutPu > TB2_TMP) 
    if ((UWORD)CUR_swUqseOutPu > TB2_TMP && AVREN)		//modified by SCOTTY 2007/07/02
        CUR_swUqseOutPu = TB2_TMP;
        
    CRM_swIdPu = 0;
    CRM_swIqPu = 32767;       

    CRM_slSpdPu = TB1_slSpdCmdPu;
    CurrentMod_noPG();
         
    TeS_swUdseInPu = CUR_swUdseOutPu;
    TeS_swUqseInPu = CUR_swUqseOutPu;
    Syn2Stat_e2s();
    
    T23_swUqssInPu = TeS_swUqssOutPu;
    T23_swUdssInPu = TeS_swUdssOutPu;
    dq2abc();        

	Duty_swTasInPu = T23_swUasOutPu;
	Duty_swTbsInPu = T23_swUbsOutPu;
	Duty_swTcsInPu = T23_swUcsOutPu;
    UabcPu2Duty();
        
}
#if StandStill
void TB2_PM(void)
{
    SWORD swImax, swImin;
//    SWORD PM_swTcos[6];

    //UBYTE n;                    //clear Warning, Special.kung, 03/08/2023

//    PM_swTmax = experiod + DeadTime;  /* delete by dino, 04/03/2007 */
//    PM_swTmin = (SWORD)(experiod + DeadTime) - (SWORD)((ULONG)experiod*uwTGain>>8);  /* delete by dino, 04/03/2007 */

    /*---------------------------------------------------------------------------------------------
    -- 2006.07.05 add by Dino									 --
    -- Compare which current is the biggest and the difference between X and Xbar is the biggest --
    --												 --
    -- A_diff = A_max - A_min									 --
    -- B_diff = B_max - B_min									 --
    -- C_diff = C_max - C_min									 --
    ---------------------------------------------------------------------------------------------*/
    if ( (PhaseCnt&0x07)==6 && (ICNCnt!=0) ) {	// Judge when (PhaseCnt&0x07)==6
	    if ( IAPCnt<IBPCnt && IAPCnt<ICPCnt ) { swImax = IAPCnt; }
	    else if ( IBPCnt<IAPCnt && IBPCnt<ICPCnt ) { swImax = IBPCnt; }
	    else { swImax = ICPCnt; }

	    if ( IANCnt<IBNCnt && IANCnt<ICNCnt ) { swImin = IANCnt; }
	    else if ( IBNCnt<IANCnt && IBNCnt<ICNCnt ) { swImin = IBNCnt; }
	    else { swImin = ICNCnt; }
	    
	    if ( swImax < swImin ){
	    	if ( swImax==IAPCnt ){
	    		TUN_uwSection = 6;
	    		if ( IBNCnt<ICNCnt )
	    			Start_Section = 5;
	    		else
	    			Start_Section = 7;
	    	}
	    	else if ( swImax==IBPCnt ){
	    		TUN_uwSection = 14;
	    		if ( ICNCnt<IANCnt )
	    			Start_Section = 13;
	    		else
	    			Start_Section = 15;
	    	}
	    	else {  //swImax==ICPCnt
	    		TUN_uwSection = 22;
	    		if ( IANCnt<IBNCnt )
	    			Start_Section = 21;
	    		else
	    			Start_Section = 23;
	    	}
	    }
	    else {
	    	if ( swImin==IANCnt ){
	    		TUN_uwSection = 18;
	    		if ( IBPCnt<ICPCnt )
	    			Start_Section = 17;
	    		else
	    			Start_Section = 19;
	    	}
	    	else if ( swImin==IBNCnt ){
	    		TUN_uwSection = 2;
	    		if ( ICPCnt<IAPCnt )
	    			Start_Section = 1;
	    		else
	    			Start_Section = 3;
	    	}
	    	else {  //swImin==ICNCnt
	    		TUN_uwSection = 10;
	    		if ( IAPCnt<IBPCnt )		
	    			Start_Section = 9;
	    		else
	    			Start_Section = 11;
	    	}
	    }
		/*AD_OK = 0;
	    AD_swIAPu_Max = 0;    AD_swIBPu_Max = 0;    AD_swICPu_Max = 0;
	    AD_swIAPu_Min = 0;    AD_swIBPu_Min = 0;    AD_swICPu_Min = 0;*/
	    IAPCnt = 0;    IANCnt = 0;    IBPCnt = 0;    IBNCnt = 0;    ICPCnt = 0;    ICNCnt = 0;

	    if ( Start_Section==Start_Section_old ){
		    PM_uwStart = (UWORD)( (ULONG)Start_Section * SpDt_uwAnglePeriod / 24 );  // dino, 06/06/2007
		    if ( PGDIR!=1 )
		        PM_uwStart = -PM_uwStart;
            Init_SpDtPG1();    
            //MTU21.TCNT=PM_uwStart;   
            MTU1.TCNT = PM_uwStart; 
            //SpDt_uwPG1100usCNT_Old = MTU21.TCNT;
            SpDt_uwPG1100usCNT_Old = MTU1.TCNT;
		    if (PGDIR != 1)
				SpDt_uwPG1100usCNT_Old = 65535 - SpDt_uwPG1100usCNT_Old + 1;	
		    
		    AD_OK = 0;
		    TB2Cnt = 0;    
		    st_uwInterval = pr[TB2Time];  /* add by dino, 04/03/2007 */
		    Start_Section_old = 24;

			if ( TUN_SS ){
				TUN_HFSS_OK = 1;
// Modify by DINO, 08/11/2008
				// Only operate static tune when pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER, Modify by DINO, 05/11/2009
				//if (pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER || (pr[PG_TYPE]==SIN_SIN && ((pr[SysControl]&0x4000)!=0))){  // [IED 1387 static Tune, 2011/07/06]
				if (pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER || (pr[PG_TYPE]==SIN_SIN && (NEWHSDSTUNE==1 && ((pr[SysControl]&0x0200)==0x0200)))){        //[Modify PGHSD01 function, Bernie, 2012/02/05]
					TUN_STOP = 1;  //[For IED PG-Card, Sampo, 02/25/2010]
					stop();
				}
				else{
		    		STtune = 0;
					TUN_SS = 0;
		    		Init_FOCPG();    
		    		SpdSearchAtStart();    // FOCPM initial
            		//****** Auto Tun Running Command **************************//
                	TUN_StartInit();
                	TUN_START = 1;
				}
				// End on 05/11/2009]
// End of 08/11/2008
			}
			else{
		    	STtune = 0;   
		    	Init_FOCPG();    
		    	SpdSearchAtStart();    // FOCPM initial
		    }
		    pr[ST_TUNE] = 0;

	    }
	    else { Start_Section_old = Start_Section ; }

    }
}
#endif
#ifdef _CM_VF_C
    #undef _CM_VF_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
