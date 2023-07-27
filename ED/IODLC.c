#ifndef _IODLC_C
	#define _IODLC_C
#endif

#include "ProgHeader.h"

void IODLC_Initial_value(void){

    IODLC_Parameter_value();



}

void IODLC_Parameter_value(void){  // interrupt 1ms
    ULONG ulcul_tmp;
    
    IODLC_uwPR_fMAX = pr[FMAX]; //Dot2
    IODLC_uwPR_Tfa = pr[ACCEL1]; //Dot2
    IODLC_uwPR_Th = pr[IODHT]; //Dot2
    IODLC_uwPR_Th_Det = IODLC_uwPR_Th*1000/100; // dot2->dot0->1ms cnt
    IODLC_uwPR_Ts1 = pr[S4ACC1]; //Dot2
    IODLC_uwPR_Ts2 = pr[S4ACC2]; //Dot2
    IODLC_ulPR_Ts2x3 = (ULONG)IODLC_uwPR_Ts2*IODLC_uwPR_Ts2*IODLC_uwPR_Ts2/100; //Dot4
    IODLC_uwPR_Tacc = IODLC_uwPR_Tfa - ((IODLC_uwPR_Ts1+IODLC_uwPR_Ts2)>>1); //Dot2
    if(IODLC_uwPR_Tacc<=0)
        IODLC_uwPR_Tacc = 0;
    IODLC_uwPR_Tfd = pr[DECEL1]; //Dot2
    IODLC_uwPR_Ts3 = pr[S4DEC1]; //Dot2
    IODLC_ulPR_Ts3x3 = IODLC_uwPR_Ts3*IODLC_uwPR_Ts3*IODLC_uwPR_Ts3/100; //Dot4
    IODLC_uwPR_Ts4 = pr[S4DEC2]; //Dot2
    CRPLS_uwJlim = pr[CRPLS_Jlim];
    IODLC_ulPR_Ts4x3 = IODLC_uwPR_Ts4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100; //Dot4
    IODLC_uwPR_Tdec = IODLC_uwPR_Tfd - ((IODLC_uwPR_Ts3+IODLC_uwPR_Ts4)>>1); //Dot2
    if(IODLC_uwPR_Tdec<=0){
        IODLC_uwPR_Tdec = 0;
    }
    IODLC_uwPR_Adec = IODLC_uwPR_fMAX/IODLC_uwPR_Tfd; //Dot0
    IODLC_uwPR_Tl = pr[IODLT]; //Dot2
    IODLC_uwPR_Tl_Det = IODLC_uwPR_Tl*1000/100; // dot2->dot0->1ms cnt
    IODLC_uwPR_J1 = (IODLC_uwPR_fMAX*100/IODLC_uwPR_Tfa)/IODLC_uwPR_Ts1; //Dot2+Dot2-Dot2-Dot2 //Dot0
    IODLC_uwPR_J2 = (IODLC_uwPR_fMAX*100/IODLC_uwPR_Tfa)/IODLC_uwPR_Ts2; //Dot2+Dot2-Dot2-Dot2 //Dot0
    IODLC_uwPR_J3 = (IODLC_uwPR_fMAX*100/IODLC_uwPR_Tfd)/IODLC_uwPR_Ts3; //Dot2+Dot2-Dot2-Dot2 //Dot0
    IODLC_uwPR_J4 = (IODLC_uwPR_fMAX*100/IODLC_uwPR_Tfd)/IODLC_uwPR_Ts4; //Dot2+Dot2-Dot2-Dot2 //Dot0
    IODLC_uwPR_delta_fs2 = (IODLC_uwPR_J2*IODLC_uwPR_Ts2*IODLC_uwPR_Ts2/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
    IODLC_uwPR_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwPR_Ts3*IODLC_uwPR_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
    IODLC_uwPR_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
    IODLC_uwPR_fl = pr[FMI2]; //Dot2
    IODLC_uwPR_fs4 = IODLC_uwPR_fl + IODLC_uwPR_delta_fs4; //Dot2
    //=======================================equation=========================================//
    //Fm = (-b+(b^2-4a*c)^(1/2))/2/a                                                          //
    //a = 1;                                b = dot2; c = dot4                                //
    //b = (2*Ts2+1.5*Ts3+2*Th-0.5*Ts4)*Adec + Fl - delta_vs3 + delta_vs4;                     //
    //c = FM^2 + FM*((1.5*Ts3-0.5*Ts4)*Adec + Fl - delta_vs3 + delta_vs4)+(Js2*Ts2^3)/3*Adec; //
    //Fm = (-b+(b^2-4a*c)^(1/2))/2/a                                                          //
    //Flim = Fm - delta_vs2;                                                                  //
    //========================================================================================//
    IODLC_sleqb = (SDOUBLE)((2*IODLC_uwPR_Ts2+(3*(IODLC_uwPR_Ts3>>1))+2*IODLC_uwPR_Th-(IODLC_uwPR_Ts4>>1))*IODLC_uwPR_Adec + IODLC_uwPR_fl - IODLC_uwPR_delta_fs3 + IODLC_uwPR_delta_fs4);
    IODLC_sleqc = (SDOUBLE)(-1)*(IODLC_uwPR_fMAX*IODLC_uwPR_fMAX + IODLC_uwPR_fMAX*(((3*(IODLC_uwPR_Ts3>>1))-(IODLC_uwPR_Ts4>>1))*IODLC_uwPR_Adec 
                            + IODLC_uwPR_fl*100 - IODLC_uwPR_delta_fs3*100 + IODLC_uwPR_delta_fs4*100)+(IODLC_uwPR_J2*IODLC_ulPR_Ts2x3*IODLC_uwPR_Adec)/3);
    IODLC_sleqFm = (-IODLC_sleqb+uw_Sqrt32c((IODLC_sleqb*IODLC_sleqb-4*IODLC_sleqc)))>>1;
    IODLC_sleqFlim = IODLC_sleqFm - IODLC_uwPR_delta_fs2;

    
    IODLC_uwArea_Th = IODLC_uwPR_Th;
    ulcul_tmp = U32xU32divU32(IODLC_uwPR_fMAX*100,2,(IODLC_uwPR_J4+(IODLC_uwPR_J4*IODLC_uwPR_J4)/IODLC_uwPR_J3)); //dot4
    IODLC_uwArea_Ts4 = uw_Sqrt32c(ulcul_tmp);
    if(IODLC_uwArea_Ts4>=IODLC_uwPR_Ts4)
        IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
    IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
    IODLC_uwArea_Ts3 = IODLC_uwArea_Ts4*IODLC_uwPR_J4/IODLC_uwPR_J3;
    IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
    IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
    IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
    IODLC_uwArea_fs4 = IODLC_uwPR_fl + IODLC_uwArea_delta_fs4; //Dot2
    
    if(IODLC_uwPR_fMAX<=(IODLC_uwArea_delta_fs3+IODLC_uwArea_delta_fs4))
        IODLC_uwArea_Tdec = 0;
    else
        IODLC_uwArea_Tdec = U32xU32divU32((IODLC_uwPR_fMAX-IODLC_uwPR_fl),IODLC_uwPR_Tfd,IODLC_uwPR_fMAX)-((IODLC_uwArea_Ts3+IODLC_uwArea_Ts4)>>1);
    IODLC_ulDs2 = 0;
    IODLC_ulDh = 0;//IODLC_uwPR_fMAX*IODLC_uwArea_Th;
    IODLC_ulDs3 = (UDOUBLE)IODLC_uwPR_fMAX*IODLC_uwArea_Ts3 - ((UDOUBLE)(IODLC_uwPR_J3*IODLC_ulArea_Ts3x3*5461)>>15); //5461>>15 = 1/6 //dot4
    IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+IODLC_uwPR_fMAX-IODLC_uwPR_delta_fs3))>>1; //dot4
    IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*IODLC_ulArea_Ts4x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4
    IODLC_ulPRDtotal = IODLC_ulDs2+IODLC_ulDh+IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
    IODLC_uwPRDtotal = (IODLC_ulPRDtotal*(pr[Lift_SPD])/IODLC_uwPR_fMAX)/100;
/*
    IODLC_ulDs2 = 0;
    IODLC_ulDh = 0;
    IODLC_ulDs3 = 0;
    IODLC_ulDdec = 0;
    IODLC_ulDs4plusDl = 0;*/
    pr[IODDER] = IODLC_uwPRDtotal;
    IODLC_MIinput = MI_OFF;
    IODLC_ubArea_status = AreaStop;
    IODLC_decpoint = 0;
    IODLC_speedset = 0;
    IODLC_ulDtotal_dp = 0;
    
}



void IODLC_Distance_calculate(void){
    UWORD uwspeed_min,uwdelta_ts3,ults3;
    ULONG ults3x3;
    SLONG slcul_tmp;
    
    uwspeed_tmp = fcmd.uw.hi;

    switch(IODLC_ubArea_status){
        case AreaS1: // done 
            ulcul_tmp1 = U32xU32divU32(uwspeed_tmp*100,2,IODLC_uwPR_J1); //dot4 // Ts1^2
            IODLC_uwArea_Ts1 = uw_Sqrt32c(ulcul_tmp1); //Dot2
            IODLC_uwArea_Ts2 = IODLC_uwArea_Ts1*IODLC_uwPR_J1/IODLC_uwPR_J2; //Dot2
            IODLC_ulArea_Ts2x3 = (ULONG)IODLC_uwArea_Ts2*IODLC_uwArea_Ts2*IODLC_uwArea_Ts2/100; //Dot4
            IODLC_uwArea_delta_fs2 = (IODLC_uwPR_J2*IODLC_uwArea_Ts2*IODLC_uwArea_Ts2/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            uwspeed_max = uwspeed_tmp + IODLC_uwArea_delta_fs2;
            ulcul_tmp = U32xU32divU32(uwspeed_max*100,2,(IODLC_uwPR_J4+(IODLC_uwPR_J4*IODLC_uwPR_J4)/IODLC_uwPR_J3)); //dot4
            IODLC_uwArea_Ts4 = uw_Sqrt32c(ulcul_tmp);
            if(IODLC_uwArea_Ts4>=IODLC_uwPR_Ts4)
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
            //uwtest21 = IODLC_uwArea_Ts4;
            IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
            IODLC_uwArea_Ts3 = IODLC_uwArea_Ts4*IODLC_uwPR_J4/IODLC_uwPR_J3;
            IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
            IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
            IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            IODLC_uwArea_fs4 = IODLC_uwPR_fl + IODLC_uwArea_delta_fs4; //Dot2

            if(uwspeed_max<=(IODLC_uwArea_delta_fs3+IODLC_uwArea_fs4))
                IODLC_uwArea_Tdec = 0;
            else{
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
                IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
                IODLC_uwArea_Ts3 = IODLC_uwPR_Ts3;
                IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
                IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
                IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
                IODLC_uwArea_Tdec = U32xU32divU32((uwspeed_max-IODLC_uwPR_fl),IODLC_uwPR_Tfd,IODLC_uwPR_fMAX)-((IODLC_uwArea_Ts3+IODLC_uwArea_Ts4)>>1);
                if((SWORD)IODLC_uwArea_Tdec<0)
                    IODLC_uwArea_Tdec = 0;
            }
            IODLC_ulDs2 = (UDOUBLE)uwspeed_max*IODLC_uwArea_Ts2 - ((UDOUBLE)(IODLC_uwPR_J2*IODLC_ulArea_Ts2x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDh = uwspeed_max*IODLC_uwPR_Th; //dot4
            IODLC_ulDs3 = (UDOUBLE)uwspeed_max*IODLC_uwArea_Ts3 - ((UDOUBLE)(IODLC_uwPR_J3*IODLC_ulArea_Ts3x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+uwspeed_max-IODLC_uwPR_delta_fs3))>>1; //dot4
            IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*IODLC_ulArea_Ts4x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4

            IODLC_ulDtotal = IODLC_ulDs2+IODLC_ulDh+IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
            IODLC_AreaDec = 1;


        break;
        
        case AreaAcc: // done


            IODLC_uwArea_Ts1 = IODLC_uwPR_Ts1; //Dot2
            IODLC_uwArea_Ts2 = IODLC_uwPR_Ts2; //Dot2
            IODLC_ulArea_Ts2x3 = (ULONG)IODLC_uwArea_Ts2*IODLC_uwArea_Ts2*IODLC_uwArea_Ts2/100; //Dot4
            IODLC_uwArea_delta_fs2 = (IODLC_uwPR_J2*IODLC_uwArea_Ts2*IODLC_uwArea_Ts2/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            uwspeed_max = uwspeed_tmp + IODLC_uwArea_delta_fs2;
            ulcul_tmp = U32xU32divU32(uwspeed_max*100,2,(IODLC_uwPR_J4+(IODLC_uwPR_J4*IODLC_uwPR_J4)/IODLC_uwPR_J3)); //dot4
            IODLC_uwArea_Ts4 = uw_Sqrt32c(ulcul_tmp);
            if(IODLC_uwArea_Ts4>=IODLC_uwPR_Ts4)
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
            //uwtest21 = IODLC_uwArea_Ts4;
            IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
            IODLC_uwArea_Ts3 = IODLC_uwArea_Ts4*IODLC_uwPR_J4/IODLC_uwPR_J3;
            IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
            IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
            IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            IODLC_uwArea_fs4 = IODLC_uwPR_fl + IODLC_uwArea_delta_fs4; //Dot2
            if(uwspeed_max<=(IODLC_uwArea_delta_fs3+IODLC_uwArea_fs4))
                IODLC_uwArea_Tdec = 0;
            else{
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
                IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
                IODLC_uwArea_Ts3 = IODLC_uwPR_Ts3;
                IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
                IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
                IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
                IODLC_uwArea_Tdec = U32xU32divU32((uwspeed_max-IODLC_uwPR_fl),IODLC_uwPR_Tfd,IODLC_uwPR_fMAX)-((IODLC_uwArea_Ts3+IODLC_uwArea_Ts4)>>1);
                if((SWORD)IODLC_uwArea_Tdec<0)
                    IODLC_uwArea_Tdec = 0;
            }
            IODLC_ulDs2 = (UDOUBLE)uwspeed_max*IODLC_uwArea_Ts2 - ((UDOUBLE)(IODLC_uwPR_J2*IODLC_ulArea_Ts2x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDh = uwspeed_max*IODLC_uwPR_Th; //dot4
            IODLC_ulDs3 = (UDOUBLE)uwspeed_max*IODLC_uwArea_Ts3 - ((UDOUBLE)(IODLC_uwPR_J3*IODLC_ulArea_Ts3x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+uwspeed_max-IODLC_uwPR_delta_fs3))>>1; //dot4
            IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*IODLC_ulArea_Ts4x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4
            IODLC_ulDtotal = IODLC_ulDs2+IODLC_ulDh+IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
            IODLC_AreaDec = 1;
        break;
        
        case AreaS2: // not yet
        
            uwspeed_max = fkey.uw.hi;
            
            ulcul_tmp1 = U32xU32divU32((uwspeed_max-uwspeed_tmp)*100,2,IODLC_uwPR_J2); //dot4
            IODLC_uwArea_Ts2 = uw_Sqrt32c(ulcul_tmp1); //Dot2
            IODLC_ulArea_Ts2x3 = (ULONG)IODLC_uwArea_Ts2*IODLC_uwArea_Ts2*IODLC_uwArea_Ts2/100; //Dot4
            
            ulcul_tmp = U32xU32divU32(uwspeed_max*100,2,(IODLC_uwPR_J4+(IODLC_uwPR_J4*IODLC_uwPR_J4)/IODLC_uwPR_J3)); //dot4
            //ulcul_tmp = U32xU32divU32(uwspeed_tmp*100,2,(IODLC_uwPR_J4+(IODLC_uwPR_J4*IODLC_uwPR_J4)/IODLC_uwPR_J3)); //dot4
            IODLC_uwArea_Ts4 = uw_Sqrt32c(ulcul_tmp);
            if(IODLC_uwArea_Ts4>=IODLC_uwPR_Ts4)
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
            //uwtest21 = IODLC_uwArea_Ts4;
            IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
            IODLC_uwArea_Ts3 = IODLC_uwArea_Ts4*IODLC_uwPR_J4/IODLC_uwPR_J3;
            IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
            IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
            IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            IODLC_uwArea_fs4 = IODLC_uwPR_fl + IODLC_uwArea_delta_fs4; //Dot2

            if(uwspeed_max<=(IODLC_uwArea_delta_fs3+IODLC_uwArea_fs4))
                IODLC_uwArea_Tdec = 0;
            else{
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
                IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
                IODLC_uwArea_Ts3 = IODLC_uwPR_Ts3;
                IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
                IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
                IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
                IODLC_uwArea_Tdec = U32xU32divU32((uwspeed_max-IODLC_uwPR_fl),IODLC_uwPR_Tfd,IODLC_uwPR_fMAX)-((IODLC_uwArea_Ts3+IODLC_uwArea_Ts4)>>1);
                if((SWORD)IODLC_uwArea_Tdec<0)
                    IODLC_uwArea_Tdec = 0;
            }
            //uwtest22 = U32xU32divU32(uwspeed_max,IODLC_uwPR_Tfd,IODLC_uwPR_fMAX);
            IODLC_ulDs2 = (UDOUBLE)uwspeed_max*IODLC_uwArea_Ts2 - ((UDOUBLE)(IODLC_uwPR_J2*IODLC_ulArea_Ts2x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDh = uwspeed_max*IODLC_uwPR_Th;
            IODLC_ulDs3 = (UDOUBLE)uwspeed_max*IODLC_uwArea_Ts3 - ((UDOUBLE)(IODLC_uwPR_J3*IODLC_ulArea_Ts3x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+uwspeed_max-IODLC_uwPR_delta_fs3))>>1; //dot4
            IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*IODLC_ulArea_Ts4x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4
            IODLC_ulDtotal = IODLC_ulDs2+IODLC_ulDh+IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
            IODLC_AreaDec = 1;
            
        break;
        
        case Areahold: // done
            IODLC_uwArea_Th = IODLC_uwPR_Th;
            ulcul_tmp = U32xU32divU32(uwspeed_tmp*100,2,(IODLC_uwPR_J4+(IODLC_uwPR_J4*IODLC_uwPR_J4)/IODLC_uwPR_J3)); //dot4
            IODLC_uwArea_Ts4 = uw_Sqrt32c(ulcul_tmp);
            if(IODLC_uwArea_Ts4>=IODLC_uwPR_Ts4)
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
            IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
            IODLC_uwArea_Ts3 = IODLC_uwArea_Ts4*IODLC_uwPR_J4/IODLC_uwPR_J3;
            IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
            IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
            IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            IODLC_uwArea_fs4 = IODLC_uwPR_fl + IODLC_uwArea_delta_fs4; //Dot2

            if(uwspeed_tmp<=(IODLC_uwArea_delta_fs3+IODLC_uwArea_fs4))
                IODLC_uwArea_Tdec = 0;
            else{
                IODLC_uwArea_Ts4 = IODLC_uwPR_Ts4;
                IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
                IODLC_uwArea_Ts3 = IODLC_uwPR_Ts3;
                IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
                IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
                IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
                IODLC_uwArea_Tdec = U32xU32divU32((uwspeed_tmp-IODLC_uwPR_fl),IODLC_uwPR_Tfd,IODLC_uwPR_fMAX)-((IODLC_uwArea_Ts3+IODLC_uwArea_Ts4)>>1);
            }
            IODLC_ulDs2 = 0;
            IODLC_ulDh = 0;//uwspeed_tmp*IODLC_uwArea_Th;
            IODLC_ulDs3 = (UDOUBLE)uwspeed_tmp*IODLC_uwArea_Ts3 - ((UDOUBLE)(IODLC_uwPR_J3*IODLC_ulArea_Ts3x3*5461)>>15); //5461>>15 = 1/6 //dot4
            IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+uwspeed_tmp-IODLC_uwPR_delta_fs3))>>1; //dot4
            IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*IODLC_ulArea_Ts4x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4
            IODLC_ulDtotal = IODLC_ulDs2+IODLC_ulDh+IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
            
            if(IODLC_holdover){
                if(IODLC_cutspeed)
                    IODLC_swArea_Th_Det = ((SLONG)(IODLC_ulPRDtotal-IODLC_ulDtotal)*10/uwspeed_tmp);
                else
                    IODLC_swArea_Th_Det = IODLC_uwPR_Th_Det+(((SLONG)(IODLC_ulPRDtotal-IODLC_ulDtotal_dp)*10/uwspeed_tmp));
            }
            else 
                IODLC_swArea_Th_Det = IODLC_uwPR_Th_Det;
            if(IODLC_swArea_Th_Det<=0){
                IODLC_swArea_Th_Det = 0;
            }
            IODLC_ulDh = uwspeed_tmp*IODLC_swArea_Th_Det/10;
            IODLC_ulDtotal = IODLC_ulDs2+IODLC_ulDh+IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
            if(IODLC_control == IODLC_control_get){
                IODLC_holdCNT = 1;
                if(IODLC_uwPR_Th_CNT>=IODLC_swArea_Th_Det){
                    IODLC_control = IODLC_control_return;
                    //PCRemote2001H(IODLC_uwPR_fl); 
                    IODLC_uwPR_Th_CNT = 0;
                    if(IODLC_holdover)
                        IODLC_swArea_Th_Det = IODLC_uwPR_Th*1000/100; // dot2->dot0->1ms cnt
                    IODLC_holdCNT = 0;
                    IODLC_holdover = 0;
                }
            }
            IODLC_AreaDec = 1;
        break;
        case AreaS3: // not yet

            if(IODLC_AreaDec){
                IODLC_uwdecMaxSpeed = uwspeed_tmp;
                IODLC_AreaDec = 0;
            }
        
            ulcul_tmp = U32xU32divU32((IODLC_uwdecMaxSpeed-uwspeed_tmp)*100,2,IODLC_uwPR_J3); //dot4
            uwdelta_ts3= uw_Sqrt32c(ulcul_tmp);
            ults3= IODLC_uwArea_Ts3 - uwdelta_ts3;
            ults3x3 = ults3*ults3*ults3/100;
            
            //IODLC_ulArea_Ts4x3 = (ULONG)IODLC_uwArea_Ts4*IODLC_uwArea_Ts4*IODLC_uwArea_Ts4/100; //dot4
            //IODLC_uwArea_Ts3 = IODLC_uwArea_Ts4*IODLC_uwPR_J4/IODLC_uwPR_J3;
            //IODLC_ulArea_Ts3x3 = (ULONG)IODLC_uwArea_Ts3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100; //Dot4
            //IODLC_uwArea_delta_fs3 = (IODLC_uwPR_J3*IODLC_uwArea_Ts3*IODLC_uwArea_Ts3/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2            
            //IODLC_uwArea_delta_fs4 = (IODLC_uwPR_J4*IODLC_uwPR_Ts4*IODLC_uwPR_Ts4/100)>>1; // Dot0+Dot2+Dot2-Dot2 //Dot2
            //IODLC_uwArea_fs4 = IODLC_uwPR_fl + IODLC_uwArea_delta_fs4; //Dot2

            //if(uwspeed_tmp<=(IODLC_uwArea_delta_fs3+IODLC_uwArea_delta_fs4))
                //IODLC_uwArea_Tdec = 0;
            //else
                //IODLC_uwArea_Tdec = U32xU32divU32(uwspeed_tmp,IODLC_uwPR_Tfd,IODLC_uwPR_fMAX)-((IODLC_uwArea_Ts3+IODLC_uwArea_Ts4)>>1);
            //IODLC_ulDs2 = 0;
            //IODLC_ulDh = 0;
            IODLC_ulDs3 = (UDOUBLE)uwspeed_tmp*ults3 - ((UDOUBLE)(IODLC_uwPR_J3*ults3x3*5461)>>15); //5461>>15 = 1/6 //dot4
            //IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+uwspeed_tmp-IODLC_uwPR_delta_fs3))>>1; //dot4
            //IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*IODLC_ulArea_Ts4x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4
            IODLC_ulDtotal = IODLC_ulDs3+IODLC_ulDdec+IODLC_ulDs4plusDl;
        break;
        case AreaDec: // not yet
        
        IODLC_uwArea_Tdec = (uwspeed_tmp-IODLC_uwArea_fs4)/IODLC_uwPR_Adec;
        IODLC_ulDdec = (IODLC_uwArea_Tdec*(IODLC_uwArea_fs4+uwspeed_tmp))>>1; //dot4
        IODLC_ulDtotal = IODLC_ulDdec+IODLC_ulDs4plusDl;

        break;
        case AreaS4: // not yet

        ulcul_tmp = U32xU32divU32((uwspeed_tmp-IODLC_uwPR_fl)*100,2,IODLC_uwPR_J4); //dot4
        ults3= uw_Sqrt32c(ulcul_tmp);
        ults3x3 = ults3*ults3*ults3/100;
        
        IODLC_ulDs4plusDl = (UDOUBLE)((IODLC_uwPR_J4*ults3x3*5461)>>15) + IODLC_uwPR_fl*(IODLC_uwArea_Ts4+IODLC_uwPR_Tl); //dot4


        IODLC_ulDtotal = IODLC_ulDs4plusDl;
        break;
        case Arealand: // not yet
        
        /*
            IODLC_uwPR_Tl_CNT++;
            if(IODLC_uwPR_Tl_CNT>=IODLC_uwPR_Tl_Det){
                IODLC_control = IODLC_control_return;
                IODLC_MIcheck = 0;
                IODLC_holdover = 0;
                IODLC_uwPR_Tl_CNT = 0;
                IODLC_ulDtotal = 0;
                //stop();
            }
            */
        break;
        case AreaStop:
            IODLC_decpoint = 0;
            IODLC_speedset = 0;
            IODLC_ctrlgetonce = 0;
            IODLC_dpinaccnod = 0;
            IODLC_cutspeed = 0;
            IODLC_control = IODLC_control_return;
            IODLC_ulDtotal_dp = 0;
            IODLC_CRPLSset = 0;
            IODLC_CRPLS_S4 = 0;
            IODLC_ulSFDistance = 0;
	        IODLC_ulCPSDistance = 0;
            IODLC_CRPLS_MISW = 0;
            IODLC_CRPLS_SWSPD = 0;
			btIODLC_TrigSpeed = 0;	//Task 268622 IO Direct Landing	//Mitong 20230221 add	
        default:
            
        break;
    }
    if(IODLC_MIinput==MI_ON){
        if(!IODLC_ctrlgetonce){
            IODLC_control = IODLC_control_get;
            IODLC_ctrlgetonce = 1;
        }

        if(IODLC_speedset == 0){
            if(IODLC_ubArea_status<AreaS2){
                IODLC_ulDtotal+=IODLC_ulSFDistance;
                if(IODLC_ulDtotal<IODLC_ulPRDtotal){
                    IODLC_uwSpeed = pr[FMI3];//uwspeed_max;
                    IODLC_dpinaccnod = 1;
                    
                }
                else if(IODLC_ulDtotal>=IODLC_ulPRDtotal){
                    if(IODLC_dpinaccnod){
                        IODLC_uwSpeed = uwspeed_max;
                        //IODLC_holdover = 1;
                        //IODLC_control = IODLC_control_return;
                        IODLC_speedset = 1;
                    }
                    else{
                        IODLC_ulDtotal_dp = IODLC_ulDtotal;
                        slcul_tmp = IODLC_uwPR_Th_Det+(((SLONG)(IODLC_ulPRDtotal-IODLC_ulDtotal_dp)*10/uwspeed_max));
                        if(slcul_tmp>=0) //500
                            IODLC_uwSpeed = uwspeed_max;//uwspeed_max;
                        else{
                            IODLC_cutspeed = 1;
                            IODLC_uwSpeed = uwspeed_tmp;//uwspeed_max;
                            //IODLC_ubArea_status = Areahold;
                        }
                        IODLC_holdover = 1;
                        IODLC_speedset = 1;
                    }
                }
            }
            else if(IODLC_ubArea_status==AreaS2){
                //IODLC_uwSpeed = uwspeed_max;
                
                if(IODLC_ulDtotal>=IODLC_ulPRDtotal){
                    IODLC_ulDtotal_dp = IODLC_ulDtotal;
                    slcul_tmp = IODLC_uwPR_Th_Det+(((SLONG)(IODLC_ulPRDtotal-IODLC_ulDtotal_dp)*10/uwspeed_max));
                    if(slcul_tmp>=0)  //500
                        IODLC_uwSpeed = uwspeed_max;//uwspeed_max;
                    else{
                        IODLC_cutspeed = 1;
                        IODLC_uwSpeed = uwspeed_tmp;//uwspeed_max;
                        //IODLC_ubArea_status = Areahold;
                    }
                    IODLC_holdover = 1;
                    IODLC_speedset = 1;
                }
            }
            
            else if(IODLC_ubArea_status==Areahold){
                //IODLC_uwSpeed = uwspeed_max;
                IODLC_control = IODLC_control_return;
                IODLC_speedset = 1;
            }
            
        }
            
    }
    

}

void IODLC_CRPLS(void){
    
    uwspeed_tmp = fcmd.uw.hi;
#if 0
    if(!IODLC_CRPLSset)
        IODLC_ulPR_Distance = pr[IODDE]*IODLC_uwPR_fMAX/pr[Lift_SPD]; //dot2+dot2+dot2-dot2 = dot4
    else
        IODLC_ulPR_Distance -= (uwspeed_tmp*100)/1000;
    
    if(IODLC_CRPLS_SW){
        if(!IODLC_CRPLSset){
            IODLC_CRPLS_S4 = 1;
            CRPLS_ulTs4 = IODLC_ulPR_Distance*3/uwspeed_tmp; //dot2
            cul_speed_tmp = (UDOUBLE)uwspeed_tmp*uwspeed_tmp*uwspeed_tmp*10000;
            cul_D_tmp = (UDOUBLE)IODLC_ulPR_Distance*IODLC_ulPR_Distance;
            CRPLS_ulJs4 = ((cul_speed_tmp*29127)/(cul_D_tmp))>>17; //29127>>17 = 2/9; //dot2
            //if(CRPLS_ulJs4>(200*IODLC_uwPR_J4))
                //CRPLS_ulJs4 = IODLC_uwPR_J4*200;
        }
    }
#else
    if(!IODLC_CRPLSset){
        IODLC_ulPR_Distance = pr[IODDE]*IODLC_uwPR_fMAX/pr[Lift_SPD]; //dot2+dot2+dot2-dot2 = dot4
        if((pr[CTRLM]==SVC)||(pr[CTRLM]==VF)) //[Creep-Optimis,Lyabryan,2019/02/11]
            IODLC_ulPR_Distance -= (pr[IODLT]*pr[FLAND]);
        IODLC_CRPLSset = 1;
    }
    else{
        if((pr[CTRLM]!=FOCPM)&&(pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=VFPG))
            IODLC_ulPR_Distance -= (uwspeed_tmp*100)/1000;   //(dot2+dot2)*1ms //dot4
        else
            IODLC_ulPR_Distance -= (uwAbsMotorHz*100)/1000;
        if(IODLC_ulPR_Distance>(pr[IODDE]*IODLC_uwPR_fMAX/pr[Lift_SPD])) //[Creep-Optimis,Lyabryan,2019/02/11]
            IODLC_ulPR_Distance = 0;
    }

    if(IODLC_CRPLS_SW){
        //if(!IODLC_CRPLSset){
            IODLC_CRPLS_S4 = 1;
            //IODLC_CRPLSset = 1;
			//[  //[Creep-Optimis,Lyabryan,2019/02/11]
            if((pr[CTRLM]!=FOCPM)&&(pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=VFPG)){
                CRPLS_ulTs4 = IODLC_ulPR_Distance*3/(uwspeed_tmp+(2*(pr[FLAND]))); //dot2
                cul_speed_tmp = (UDOUBLE)(uwspeed_tmp-pr[FLAND])*(uwspeed_tmp+(2*pr[FLAND]))*(uwspeed_tmp+(2*pr[FLAND]))*10000;
                cul_D_tmp = (UDOUBLE)IODLC_ulPR_Distance*IODLC_ulPR_Distance;
                CRPLS_ulJs4 = ((cul_speed_tmp*29127)/(cul_D_tmp))>>17; //29127>>17 = 2/9; //dot2
            }
			//] //[Creep-Optimis,Lyabryan,2019/02/11]
            else{
                CRPLS_ulTs4 = IODLC_ulPR_Distance*3/uwspeed_tmp; //dot2
                cul_speed_tmp = (UDOUBLE)uwspeed_tmp*uwspeed_tmp*uwspeed_tmp*10000;
                cul_D_tmp = (UDOUBLE)IODLC_ulPR_Distance*IODLC_ulPR_Distance;
                CRPLS_ulJs4 = ((cul_speed_tmp*29127)/(cul_D_tmp))>>17; //29127>>17 = 2/9; //dot2
            }       
        //}
    }
#endif





}






#ifndef _IODLC_C
	#undef _IODLC_C
#endif
