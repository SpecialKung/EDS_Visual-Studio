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
#ifndef _TB_1ms_C
  #define _TB_1ms_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void WgOff2Sby(void)
{
    WGOFF;

    STANDBY = 1;

    ftemp.ul = 0;
    fcmd.ul = 0;
    fcmd_vf.ul = 0;
    fout.ul = 0;       

    Fcmd = 0;   
    sacc.ul = 0;
    sdec.ul = 0;

    Vcmd_LL = 0;
    VF_Vcmd = 0;
    vcmd_ser = 0;

    Ismax_uwPu = 0;
    prt_OLIrms.ul = 0;  // Add by dino, 08/21/2007
    IrmsRe = 0;
//    slIrmsReLPF = 0;
    IrmsReLPF.sl = 0;

    fhunt.sl = 0;

    RUNDCI = 0;
    STOPDCI = 0;
    TB1_uwDCICnt = 0;

    FSKIPFLG = 0;
}

void PG_speed_search(void)
{
    UWORD Spd2Hz;
    
    if (pr[PGINPUT]!=5){
        if (SpDt_slSpdFdbPu>=0){
            WGDIR = FORWARD;            
        }    
        else{
            WGDIR = REVERSE;
        }         
    }    
    Spd2Hz = U32xU32shlr32(((ULONG)COF_uwFbRe<<1), abs(SpDt_slSpdFdbPu));
    fcmd.uw.hi = Spd2Hz;
    ftemp.uw.hi = Spd2Hz;
    fcmd_vf.uw.hi = Spd2Hz;
    TB1_slSpdCmdPu = SpDt_slSpdFdbPu;
    TB1_ubFOCPGSerCnt = 0;
    vtemp = GetFx2Vm(fcmd_vf.uw.hi);
}

/*------------ Restart Subroutine after Fault-------------------------------*/
void Restart_Prog(void)
{
  UWORD FreqStart;

  if ( pr[CTRLM]==FOCPM )
    FreqStart = 0;
  else
    FreqStart = fstart;

    if (BBTAT){                             // BB Time Attain
        RST316J = 0;
        Error = 0;
        KEYRESET = 0;
        CCSET = 0;
        vcmd_ser = 0;
        TB1_uwBBCnt = pr[BB_T] * 100;
        TB1_uwLVCnt = pr[PWRL_T] * 100;

        if (LVORFLT) {                      
            //------ LVORFLT = 1 is Lv Speed serach ------------------------//
/* Item 46: Marked,            if((pr[PGINPUT]==0)||PGLOSS){  */
            if(pr[PGINPUT]==0){
                if(pr[PWRLOS]==1){          // Speed search from Speed reference, pr[POWLOS]= 1
                    SPSEARCH = 1;
                }
                else if(pr[PWRLOS]==2){     // Speed search from Min Speed, pr[POWLOS]= 2
                  if (Fcmd>FreqStart){
                      fcmd.uw.hi = FreqStart;
                      ftemp.uw.hi = FreqStart;
                    }
                    else{
                      fcmd.uw.hi = Fcmd;
                      ftemp.uw.hi = Fcmd;                     
          }
                    SPSEARCH = 0;
                }
            }
            else {
                SPSEARCH = 1;
                PG_speed_search();
            }
            //------ End of Lv Speed serach --------------------------------//
        }
        else {   
            //------ fault restart -----------------------------------------//
/* Item 46: Marked,            if((pr[PGINPUT]==0)||PGLOSS){  */
            if(pr[PGINPUT]==0){
                if(pr[REST_M]==1){         // Speed search from Speed reference, pr[SPD_SER]=1
                    SPSEARCH = 1;
                }
                else if(pr[REST_M]==2){    // Speed search from Min Speed, pr[SPD_SER]=2
                  if (Fcmd>FreqStart){
                      fcmd.uw.hi = FreqStart;
                      ftemp.uw.hi = FreqStart;
          }
          else{
                      fcmd.uw.hi = Fcmd;
                      ftemp.uw.hi = Fcmd;
          }
                    SPSEARCH = 0;
                }
            }
            else {
                SPSEARCH = 1;
                PG_speed_search();
            }

            if ((pr[REST_CNT]!=0)&&(Error!= bb_ERR))
                pr[REST_CNT] --;
        }

        RST316J = 1;
        WGON;
        RESTART = 0;       // Clear Restart Flag
        BBTAT = 0;
    }
    else {  // else of [ if(BBTAT) ]
#if SH7286 //Sean, 02/22/2010
      if ( KEYRESET &&
         ((PORT7.PIDR.BIT.B0  &1)==1) &&     // Confirm OC/CC/GF is high
         ((PORT9.PIDR.BIT.B6  &1)==1) &&     // Confirm OCC is high         
         ((PORTB.PIDR.BIT.B4 &1)==1) ){     // Confirm OV is high
#endif    
          if ( RelayOFF==0 ){   // Auto-restart after Soft-start turn ON, Add by DINO, 12/01/2008
              if(TB1_uwBBCnt==0){
//---Add BY Dino 06/13/2007---
#if SH7286 //Sean, 01/25/2010
                  //POE2.ICSR1.WORD &= 0xFFFF;
                  //POE2.ICSR2.WORD &= 0x8FFF;
                  //POE2.ICSR1.BIT.PIE1 = 1;
                  //POE2.ICSR2.BIT.PIE2 = 1;
                  POE.ICSR1.WORD &= 0x1103;
                  POE.ICSR2.WORD &= 0x1103; 
                  POE.ICSR3.WORD &= 0x1303;
                  POE.ICSR4.WORD &= 0x1303;
                  POE.ICSR5.WORD &= 0x1303;
                  POE.ICSR1.BIT.PIE1 = 1;
                  POE.ICSR2.BIT.PIE2 = 1;
                  POE.ICSR3.BIT.PIE3 = 1;
                  POE.ICSR4.BIT.PIE4 = 1;
                  POE.ICSR5.BIT.PIE5 = 1;
#endif
//---END 06/13/2007---------------  
                  BBTAT = 1;
                  KEYRESET = 0;
              }
              else {
                  BBTAT = 0;
                  TB1_uwBBCnt --;
              }
              VF_Vcmd = 0;
          }
        }
    }
}  /*--------------- End of Restart Progress ------------*/

/*--------------------------------------------------------------------------
  -      Reference Speed Search Subroutine
  --------------------------------------------------------------------------*/
void Speed_Search(void)
{
    UWORD SpdSerLevelAD, Spd2Hz;
    
    switch(pr[CTRLM]){
        default:
        case VF:        
        case SVC:
            SpdSerLevelAD = ((ULONG)pr[SER_CL] * 3494) >>8;  // (3494/2^8) * 100 = (4095/3), dino, 03/06/2007
            if (IrmsAD < SpdSerLevelAD) {   // Below Search current Level
                if (fcmd.uw.hi>=fmin) {
                    if (vcmd_ser >= vtemp) {
                        ftemp.ul = fcmd.ul;     // speed search is finished
                        SPSEARCH = 0;
                        //vcmd_ser = 0;
                    }
                    else {
                        if (vcmd_ser >= vbase)
                            vcmd_ser = vbase;
                        else {
                            if (pr[HPSPEC]&VFD440V)
                                vcmd_ser += 4;       // 440V class
                            else
                                vcmd_ser += 2;       // 220V class
                        } 
                    }
                }
                else {
                    ftemp.ul = fcmd.ul;         // speed search is finished
                    SPSEARCH = 0;
                    //vcmd_ser = 0;
                }
            }
            else {                              // Above Search current Level
                if (vcmd_ser > 4){
                    if (IrmsAD > SpdSerLevelAD) {
                        if (fcmd.uw.hi>fmin){
                            fcmd.uw.hi -= 1;        // 0.01Hz
                        }
                    }
                    
                    if (pr[HPSPEC]&VFD440V)
                      vcmd_ser -= 4;          // 440V class
                    else
                        vcmd_ser -= 2;          // 220V class
                }
                else{            
                    if (fcmd.uw.hi<=fmin) {
                        ftemp.ul = fcmd.ul;     // speed search is finished
                        SPSEARCH = 0;
                        //vcmd_ser = 0;
                    }
                    else{
                      fcmd.uw.hi -= 1;        // 0.01Hz
                    }
                }
            }
            VF_Vcmd = vcmd_ser;            
            break;
        case FOC:
        case VFPG:
            Spd2Hz = U32xU32shlr32(((ULONG)COF_uwFbRe<<1), abs(SpDt_slSpdFdbPu));
            vtemp = GetFx2Vm(Spd2Hz);
            if (vcmd_ser >= vtemp){
                vcmd_ser = vtemp;
                ftemp.uw.hi = Spd2Hz;
                fcmd.uw.hi = Spd2Hz;
                SPSEARCH = 0;
            }
            else {
                if (pr[HPSPEC]&VFD440V)
                    vcmd_ser += 4;       // 440V class
                else
                    vcmd_ser += 2;       // 220V class
            } 
            VF_Vcmd = vcmd_ser;
            break;
        case FOCPG:             
            ftemp.ul = fcmd.ul;
            if (pr[YDSWEN]==1){
              if ((YDConnectFlag==1)&&(DOnCNT>=pr[YDDELAYT])) //Delta Connect
                  SPSEARCH = 0;
                else if ((YDConnectFlag==0)&&(YOnCNT>=pr[YDDELAYT]))
                    SPSEARCH = 0;
            }
            else
              SPSEARCH = 0;
            
            vcmd_ser = 0;             
            break;
    }            
} /*--------------- End of Refer speed search  Progress ------------*/
ULONG acc_decel(void)
{
  SWORD swWslErr;
  ULONG ax;
  SLONG slSpdSlope;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    UWORD uwtmp;
    
	if(!EPS){
	    if((ACCODEC == ACCON)&&(NORMALSP!=1)){
	        Speed_old = speed;
	    }
	    else if((ACCODEC == DECON)&&(fcmd.uw.hi!=Fcmd)){
	    }
	    else{
	        Speed_old = Speed_check;
	    }
	}    
	else{
		Speed_old = Speed_check;
	}	
//============EMY Function=============//
    uwtmp = U16xU16divU16(120,pr[FMI7],100); // Leveling speed
    if(CMDRUN==RUN){
        if((Speed_old<=7)&&(Speed_old!=0)){
            if(SIBO_RELEVELF){ 
                if(speed==0){
                    if(fcmd.uw.hi>=uwtmp){
                        acc_dec = 4;
                        SIBO_EMYFLAG = 1;
                    }
                }
                else{
                    acc_dec = 0;
                }
            }
            else if(SIBO_INSF&&(!SIBO_RELEVELF)){ //inspection mode
                if(speed==0){
                    acc_dec = 0;
                }
            }
            else{   
                if((speed==0)&&(fcmd.uw.hi>=uwtmp)){
                    acc_dec = 4;
                    SIBO_EMYFLAG = 1;
                }
                else if(speed!=0){   
                    acc_dec = 0;
                }
                else{
                }
            }
        }
    }
    else{
        if(fcmd.uw.hi>=uwtmp){
            acc_dec = 4;
            SIBO_EMYFLAG = 1;
        }
    }
//============EMY Function=============//

#endif
    if(STALLC2 == 0){
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        if((SIBO_INSF==1)||(CMDJOG == 1)){
#else
        if(CMDJOG == 1){
#endif
            if (ACCODEC == ACCON)
                ax = fjacc.ul;
            else
                ax = fjdec.ul;      
        }
        else{
            if(PositionCom==1){
                if (APRExeFlag==0)
                    ax = Pfdec.ul;
                else
                    ax = 0;
            }
            else{
                if(CMDRUN==RUN){
                    switch(acc_dec){
                        case 1:{
                            if (ACCODEC == ACCON)
                                ax = facc2.ul;        
                            else{
                                if(EPS){                         //[MI EPS status, Bernie, 2015/10/05]
                                    if((!GEN_START)&& GEN_OK){   //[MI EPS status, Bernie, 2015/10/05]
                                         MODE2 = 1;     //[DIN time sequence, Bernie, 2013/03/07]
                                    }
                                }
                                else{                            //[MI EPS status, Bernie, 2015/10/05]
                                    MODE2 = 1;     //[DIN time sequence, Bernie, 2013/03/07]
                                }
                                ax = fdec2.ul;  
                            }
                        }break;
                        case 2:{
                            if (ACCODEC == ACCON)
                                ax = facc3.ul;
                            else{
                                if(EPS){                         //[MI EPS status, Bernie, 2015/10/05]
                                    if((!GEN_START)&& GEN_OK){   //[MI EPS status, Bernie, 2015/10/05]
                                        MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                                    }
                                }
                                else{                            //[MI EPS status, Bernie, 2015/10/05]
                                    MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                                }
                                ax = fdec3.ul;
                            }
                        }break;
                        case 3:{
                            if (ACCODEC == ACCON)
                                ax = facc4.ul;
                            else{
                                if(EPS){                         //[MI EPS status, Bernie, 2015/10/05]
                                    if((!GEN_START)&& GEN_OK){   //[MI EPS status, Bernie, 2015/10/05]
                                        MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                                    }
                                }
                                else{                            //[MI EPS status, Bernie, 2015/10/05]
                                    MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                                }
                                ax = fdec4.ul;
                            }
                        }break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                        case 4:{
                            if (ACCODEC == ACCON){
                            }
                            else{
                                if(EPS){                         //[MI EPS status, Bernie, 2015/10/05]
                                    if((!GEN_START)&& GEN_OK){   //[MI EPS status, Bernie, 2015/10/05]
                                         MODE2 = 1;     //[DIN time sequence, Bernie, 2013/03/07]
                                    }
                                }
                                else{                            //[MI EPS status, Bernie, 2015/10/05]
                                    MODE2 = 1;     //[DIN time sequence, Bernie, 2013/03/07]
                                }
                                ax = fdecEMY.ul;  
                            }
                        }break;
#endif
                        default:{
                            if (ACCODEC==ACCON){
                                if (fcmd.uw.hi >= pr[FAD1_AD4])
                                    ax = facc1.ul;
                                else
                                    ax = facc4.ul;
                            }
                            else{
                                if(EPS){                         //[MI EPS status, Bernie, 2015/10/05]
                                    if((!GEN_START)&& GEN_OK){   //[MI EPS status, Bernie, 2015/10/05]
                                        MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                                    }
                                }
                                else{                            //[MI EPS status, Bernie, 2015/10/05]
                                    MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                                }
                                if (fcmd.uw.hi >= pr[FAD1_AD4])
                                    ax = fdec1.ul;
                                else
                                    ax = fdec4.ul;
                            }
                        }break;
                    } //Switch Case 
                    
                    if((btSR_ESD||btSR_ETS)&&(pr[CTRLM] != VF)&&(pr[CTRLM] != SVC)){ //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
                    
                        ax = fdec_ESD.ul;
                    
                    }
                }
                else{
                    if(EPS){                                         //[MI EPS status, Bernie, 2015/10/05]
                        if((!GEN_START)&& GEN_OK){                   //[MI EPS status, Bernie, 2015/10/05]
                            MODE2=1;       //[DIN time sequence, Bernie, 2013/03/07]
                        }
                    }
                    else{                                            //[MI EPS status, Bernie, 2015/10/05]
                        MODE2=1;     //[DIN time sequence, Bernie, 2013/03/07]
                    }
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                    if(SIBO_EMYFLAG)
                        ax = fdecEMY.ul;
                    else
#endif
                    ax = fdec5.ul;
                }
            } //Position Command = 0
        } //CMDJOG = 0
    } //STALLC2 = 0
    else{
        STALL_AUTO = 0;       
        switch (pr[STALLSPD]){
            default:
            case 1:
                if (ACCODEC == ACCON)
                    ax = facc1.ul;        
                else
                    ax = fdec1.ul;        
                break;
            case 2:
                if (ACCODEC == ACCON)
                    ax = facc2.ul;        
                else
                    ax = fdec2.ul;        
                break;
            case 3:
                if (ACCODEC == ACCON)
                    ax = facc3.ul;        
                else
                    ax = fdec3.ul;        
                break;
            case 4:
                if (ACCODEC == ACCON)
                    ax = facc4.ul;        
                else
                    ax = fdec4.ul;        
                break;
            case 5:{    // Automatic, 60Hz, 0.1sec
                STALL_AUTO = 1;
                if (ACCODEC == ACCON)       
                    ax = ((ULONG)(6000*655)+(((ULONG)6000*23593)>>16));
                else
                    ax = fdec1.ul;    
            } break;
        }
    }

    if (KEB_ON==1){
        KEB_AUTO = 0;
        switch (pr[KEB_SL]){
            case 1:{
                ax = fdec1.ul;
            } break;
            case 2:{
                ax = fdec2.ul;
            } break;
            case 3:{
                ax = fdec3.ul;
            } break;
            case 4:{
                ax = fdec4.ul;
            } break;
            case 6:{    // Automatic, 60Hz, 0.1sec
                KEB_AUTO = 1;
                ax = ((ULONG)(6000*655)+(((ULONG)6000*23593)>>16));
            } break;
            default:
            break;
        }
    }
  
//  if ( (EXT_EF==1 || (EXT_FORCESTOP==1 && EXT_COASTSTOP==0)) && pr[FORSTPWAY]!=0 ){
    if ( (Error==EF_ERR || (EXT_FORCESTOP==1 && EXT_COASTSTOP==0)) && pr[FORSTPWAY]!=0 ){  // Add by DINO, 03/31/2008
        EF_AUTO = 0;
        switch(pr[FORSTPWAY]){
          case 1:
                    ax = fdec1.ul;
                  break;
                case 2:
                    ax = fdec2.ul;
                  break;
                case 3:
                    ax = fdec3.ul;
                  break;
                case 4:
                    ax = fdec4.ul;
                  break;
                case 5:
                    ax = fdec5.ul;
                  break;
                case 6: // Automatic, 60Hz, 0.1sec
                    EF_AUTO = 1;
                    ax = ((ULONG)(6000*655)+(((ULONG)6000*23593)>>16));
                  break;
                default:
                  break;
        }
    }       





    if ((pr[CTRLM]==FOCPG)&&(FLX_swFlxFreqPu>=COF_uwFRatePu)){
        swWslErr = FLX_uwWslMaxPu - (abs(CRM_slWslPu>>16));
              
        if (SpdSlop_flag == 0)
            FLX_slWslErrKi = FLX_slWslErrKi + ((SLONG)swWslErr * pr[SpdSlop_I]); //Q31 = Q31+Q(15+16)
                  
        slSpdSlope = (SLONG)swWslErr * pr[SpdSlop_P]; //Q15
                                  
        slSpdSlope = (SLONG)ax + slSpdSlope + FLX_slWslErrKi;
       
        if (slSpdSlope >= (SLONG)ax){
            slSpdSlope = (SLONG)ax;
            SpdSlop_flag = 1;
        }
        else if (slSpdSlope <= 100){
            slSpdSlope = 100;
            SpdSlop_flag = 1;
        }
        else
            SpdSlop_flag = 0;
                    
        ax = (ULONG)slSpdSlope;
        
    }       

    return ax;
}

void chk_stallc(void)
{
    UWORD ex;
    UWORD uwStallC, uwOCLevel, uwcAD, uwIrmsAD;
    UBYTE ubStallC2 ;

#if DINO  // Modify by dino, 2007/01/29

     uwIrmsAD = TB1_uwNewIrmsAD >> 2;  // New IED Irated is 110%, DINO, 09/06/2010

    if (NORMALSP==1){           //------------ at normal speed
    uwOCLevel = pr[OCN];
        if (pr[STALLSPD]!=0)
            ubStallC2 = 1;               
        else
            ubStallC2 = 0;   
    }
    else {
    uwOCLevel = pr[OCA];
    ubStallC2 = 0;
    }

    if ( (uwOCLevel!=0) && (pr[CTRLM]<3) ){
    uwcAD = ((ULONG)uwOCLevel * 873) >> 8;    //OC stall Level of AD scale, dino,2007/01/29
    
    if (fout.uw.hi>fbase){                  // stall in the weak flux area
        uwStallC = ((ULONG)uwcAD * fbase)/fout.uw.hi;
        ex = ((ULONG)uwcAD * pr[STALLIMIT])/100;
        if (uwStallC<ex)            // 10%, dino,2007/01/29
          uwStallC = ex;        // dino,2007/01/29
      }
      else{ uwStallC = uwcAD; }

        if (uwStallC > 17)  //341 * 0.05 = 17.05
            ex = uwStallC - 17;     // below 5.0%
        else 
            ex = 0;

    if ( (uwIrmsAD>=uwStallC) ||(CC4ACCEL==1) ){
        STALLC = 1;
        STALLC2 = ubStallC2;
    }
    else if (uwIrmsAD < ex){
        STALLC = 0;
        CCSET  = 0;
        //CC4display = 0;
    }
    }
    else {          // disable stall current
    ex = (1023-20);   // 295% rated Current
    STALLC = 0;
    }
    
#else

    cnAD = ((ULONG)pr[OCN] * 873) >> 8;   //873/2^8 = 3.41
    caAD = ((ULONG)pr[OCA] * 873) >> 8;   

    if (fout.uw.hi>fbase){                // stall in the weak flux area
      stallcn = ((ULONG)cnAD * fbase)/fout.uw.hi;
      ex = ((ULONG)cnAD * pr[STALLIMIT])/100;
        if (stallcn<ex)
          stallcn = ex;
          
        stallca = ((ULONG)caAD * fbase)/fout.uw.hi;
        ex = ((ULONG)caAD * pr[STALLIMIT])/100;
        if (stallca<ex)
            stallca = ex;
    }
    else{
      stallcn = cnAD;
        stallca = caAD;
    }

    /*------------- Stall Prevention During Accel. ----------------------------------*/
    if (NORMALSP==1){ //---- at normal speed
      if ((pr[OCN]!=0)&&(pr[CTRLM]<3)){
            if (stallcn > 17) //341 * 0.05 = 17.05
                ex = stallcn - 17;      // below 5.0%
            else 
                ex = 0;    

            if ((IrmsAD >= stallcn)||(CC4ACCEL==1)){
              STALLC = 1;
              if (pr[STALLSPD]!=0)
                  STALLC2 = 1;               
              else
                    STALLC2 = 0;   
            } 
            else if (IrmsAD < ex){
              STALLC = 0;
              CCSET = 0;
              //CC4display = 0;
            }
        }
        else {        // disable stall current
            ex = (1023-17);
            STALLC = 0;
        }
    }
    else {        //---- not normal speed
      if ((pr[OCA]!=0)&&(pr[CTRLM]<3)){
          if (stallca > 17)
                ex = stallca - 17;      // below 5.0%
            else 
                ex = 0;

            //max if ((Irms_ad >= stallca)||(Ferror > 300))
            if ((IrmsAD >= stallca)||(CC4ACCEL==1))
              STALLC = 1;
            else if (IrmsAD < ex){
              STALLC = 0;
              CCSET = 0;
              //CC4display = 0;
            }
        }
        else {                  // disable stall current
            ex = (1023-17);
            STALLC = 0;
        }
    }
#endif
    if (CC4ACCEL==1) {
      accel_error = ex - 900;             // cc be set
        if (TB1_uwNewIrmsAD < ex)  // New IED Irated is 110%, DINO, 09/06/2010
            CC4ACCEL = 0;
    }
    else
      accel_error = (ex-TB1_uwNewIrmsAD)<<5;  // New IED Irated is 110%, DINO, 09/06/2010

    if (accel_error > (SWORD)IERRORLIMIT)
        accel_error = IERRORLIMIT;
    else if (accel_error < (SWORD)-IERRORLIMIT)
        accel_error = -IERRORLIMIT;
    /*----------------- End of Accel Stall Function -----------------*/
}

void ScurveAcc(void)
{
    ULONG_UNION  facc_t1,facc_t2;
    SLONG delta_f, ss2;

    if (Fcmd>=16384)
        delta_f = (SLONG)(Fcmd - ftemp.uw.hi)<<15;  
    else
        delta_f = (SLONG)(Fcmd - ftemp.uw.hi)<<17;
  
    if (delta_f > 0){ 
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        if ((pr[S4ACC2]!=0)&&(SIBO_INSF==0)){
#else
        if (pr[S4ACC2]!=0){
#endif
            if (pr[U_ACCDEC] == 0) //2 dot
                facc_t2.ul = (facc.ul/(pr[S4ACC2]*10));
            else
                facc_t2.ul = (facc.ul/(pr[S4ACC2]*100));
            if (facc_t2.ul == 0)
                facc_t2.ul = 1;
        }        
        else
            facc_t2.ul = facc.ul;        
        
        if (Fcmd>=16384)
            ss2 = U32xU32divU32(sacc.ul>>1,sacc.ul>>1,facc_t2.ul);
        else
            ss2 = U32xU32divU32(sacc.ul,sacc.ul,facc_t2.ul);
        if (((SLONG)delta_f > ss2)){ //&&(IODLC_ubArea_status!=AreaS2)
                IODLC_ubArea_status = AreaS1;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            if ((pr[S4ACC1]!=0)&&(SIBO_INSF==0)){
#else
            if (pr[S4ACC1]!=0){
#endif
                if (pr[U_ACCDEC] == 0) //2 dot
                    facc_t1.ul = (facc.ul/(pr[S4ACC1]*10));
                else
                    facc_t1.ul = (facc.ul/(pr[S4ACC1]*100));
                if (facc_t1.ul == 0)
                    facc_t1.ul = 1;    
                sacc.ul = sacc.ul + facc_t1.ul;
                if (sacc.ul > facc.ul){
                    IODLC_ubArea_status = AreaAcc; // [IODLC, Lyabryan, 2016/11/11]
                    sacc.ul = facc.ul;
                }
            }
            else
                sacc.ul = facc.ul;        
        }
        else {
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
            if ((pr[S4ACC2]!=0)&&(SIBO_INSF==0)){  
#else
            if (pr[S4ACC2]!=0){  
#endif
                IODLC_ubArea_status = AreaS2; // [IODLC, Lyabryan, 2016/11/11]
                if (Fcmd>=16384)            
                    facc_t2.ul = U32xU32divU32(sacc.ul>>1,sacc.ul>>1,delta_f);
                else
                    facc_t2.ul = U32xU32divU32(sacc.ul,sacc.ul,delta_f);
                    
                if (facc_t2.ul == 0)
                    facc_t2.ul = 1;
                sacc.ul = sacc.ul - facc_t2.ul;
                if((SWORD)sacc.uw.hi < 0){
                    sacc.ul = 0;
                }    
            }        
            else        
                sacc.ul = facc.ul;
        }
        //ftemp.ul = ulAplusB_Over(ftemp.ul, sacc.ul);
        ftemp.ul = ftemp.ul + sacc.ul;
    }  
}
void ScurveDec_CRIPLS(void) // [IODLC, Lyabryan, 2016/11/11]
{
    UWORD fx, ssdino;
    ULONG_UNION  fdec_t1,fdec_t3;
    SLONG delta_f;
    fx = MAX(Fcmd,fmin);
    delta_f = ((ftemp.ul - (fx<<16))>>1);

    if ( ftemp.uw.hi > pr[FLAND] )
        ssdino = 1;   // S-Curve = pr[S4DEC2]
    else
        ssdino = 0;   // S-Curve = pr[S4DEC3]

    if (delta_f > 0){
      
        if (pr[S4DEC2]!=0){
            if (pr[U_ACCDEC] == 0){ //2 dot
                if(IODLC_CRPLS_S4){
                    sdec_tmp.ul = ((CRPLS_ulJs4*CRPLS_ulTs4)<<16)/100000; //1000(1ms)/100(dot2)
                    fdec_t2.ul = (sdec.ul/(CRPLS_ulTs4*10)); //Jerk //Js4(dot2)/1000(1ms)/1000(1ms)
                    IODLC_sldelta_sdec = (SLONG)(sdec_tmp.ul-sdec_old.ul);
                    if(IODLC_sldelta_sdec>0){
                        IODLC_ubArea_status = AreaS3;
                        if(IODLC_sldelta_sdec>(CRPLS_uwJlim*(IODLC_uwPR_J4<<16)/1000000))
                            IODLC_sldelta_sdec = (CRPLS_uwJlim*(IODLC_uwPR_J4<<16)/1000000);
                    }
                    else if(IODLC_sldelta_sdec<0){
                        IODLC_ubArea_status = AreaS4;
                        if(abs(IODLC_sldelta_sdec)>(CRPLS_uwJlim*(IODLC_uwPR_J4<<16)/1000000))
                            IODLC_sldelta_sdec = -(CRPLS_uwJlim*(IODLC_uwPR_J4<<16)/1000000);
                    }
                    sdec.ul = sdec.ul + IODLC_sldelta_sdec;
                
                if((SLONG)sdec.ul < 0){
                    sdec.ul = 0;
                }    
                if ((ftemp.ul<sdec.ul)||(sdec.ul == 0))
                    ftemp.ul = 0;
                else
                    ftemp.ul = ftemp.ul - sdec.ul;
                                
                }
                else
                    fdec_t2.ul = (fdec.ul/(pr[S4DEC2]*10));
            }
            else
                fdec_t2.ul = (fdec.ul/(pr[S4DEC2]*100));
            
            if (fdec_t2.ul == 0)
                fdec_t2.ul = 1;
        }
        else{
            fdec_t2.ul =  fdec.ul;  
        }

        if (pr[S4DEC3]!=0){
            if (pr[U_ACCDEC] == 0) //2 dot
                fdec_t3.ul = (fdec.ul/(pr[S4DEC3]*10));
            else
                fdec_t3.ul = (fdec.ul/(pr[S4DEC3]*100));
            if (fdec_t3.ul == 0)
                fdec_t3.ul = 1;
        }
        else
            fdec_t3.ul =  fdec.ul;            
     
        if ( ssdino ){
            ss4 = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,fdec_t2.ul);
        }
        else{
            ss4 = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,fdec_t3.ul);
        }
        
    }
    sdec_old.ul = sdec.ul;
    

}

void ScurveDec(void)
{
  UWORD fx, ssdino;
  ULONG_UNION  fdec_t1,fdec_t2,fdec_t3;
  SLONG delta_f;
  
  fx = MAX(Fcmd,fmin);
  #if 1
  delta_f = ((ftemp.ul - (fx<<16))>>1);
  #else
  if (FcmdOverFlag==1)
    delta_f = ((ftemp.ul - (fx<<16))>>1);
  else
      delta_f = ((ftemp.ul - (fx<<16))<<1) ;
  #endif  

  if ( ftemp.uw.hi > pr[FLAND] )
      ssdino = 1;   // S-Curve = pr[S4DEC2]
  else
      ssdino = 0;   // S-Curve = pr[S4DEC3]

  if (delta_f > 0){
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        if ((pr[S4DEC2]!=0)&&(SIBO_EMYFLAG==0)&&(SIBO_INSF==0)){
#else
      if (pr[S4DEC2]!=0){
#endif
          if (pr[U_ACCDEC] == 0) //2 dot
              fdec_t2.ul = (fdec.ul/(pr[S4DEC2]*10));
          else
              fdec_t2.ul = (fdec.ul/(pr[S4DEC2]*100));
          if (fdec_t2.ul == 0)
              fdec_t2.ul = 1;
      }
      else
          fdec_t2.ul =  fdec.ul;            
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        if ((pr[S4DEC3]!=0)&&(SIBO_EMYFLAG==0)&&(SIBO_INSF==0)){
#else
      if (pr[S4DEC3]!=0){
#endif
          if (pr[U_ACCDEC] == 0) //2 dot
              fdec_t3.ul = (fdec.ul/(pr[S4DEC3]*10));
          else
              fdec_t3.ul = (fdec.ul/(pr[S4DEC3]*100));
          if (fdec_t3.ul == 0)
              fdec_t3.ul = 1;
      }
      else
          fdec_t3.ul =  fdec.ul;            
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
        if((SIBO_EMYFLAG==1)&&(pr[SIBO_S4EMY]!=0)&&(SIBO_INSF==0)){
            if (pr[U_ACCDEC] == 0) //2 dot
                fdec_t2.ul = (fdec.ul/(pr[SIBO_S4EMY]*10));
            else
                fdec_t2.ul = (fdec.ul/(pr[SIBO_S4EMY]*100));
            if (fdec_t2.ul == 0)
                fdec_t2.ul = 1;
        }
        else
            fdec_t3.ul =  fdec.ul;            
        
#endif
      if ( ssdino ){
          ss4 = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,fdec_t2.ul);
      }
      else{
          ss4 = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,fdec_t3.ul);
      }

      if ((delta_f > ss4)){ //&&(IODLC_ubArea_status != AreaS4)&&(IODLC_ubArea_status != AreaS6)
          if ( ssdino ){
              if(IODLC_ubArea_status < Arealand)
                  IODLC_ubArea_status = AreaS3;
              else if(IODLC_ubArea_status>=Arealand)
                  IODLC_ubArea_status = AreaS5;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
              if ((pr[S4DEC1]!=0)&&(SIBO_EMYFLAG==0)&&(SIBO_INSF==0)){
#else
              if (pr[S4DEC1]!=0){
#endif
                  if (pr[U_ACCDEC] == 0) //2 dot
                      fdec_t1.ul = (fdec.ul/(pr[S4DEC1]*10));
                  else
                      fdec_t1.ul = (fdec.ul/(pr[S4DEC1]*100));
                  if (fdec_t1.ul == 0)
                      fdec_t1.ul = 1;    
                  sdec.ul = sdec.ul + fdec_t1.ul;
                  if (sdec.ul > fdec.ul){                    
                      IODLC_ubArea_status = AreaDec;
                      sdec.ul = fdec.ul;
                  }
              }
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                else if((pr[SIBO_S3EMY]!=0)&&(SIBO_EMYFLAG==1)&&(SIBO_INSF==0)){
                    if (pr[U_ACCDEC] == 0) //2 dot
                        fdec_t1.ul = (fdec.ul/(pr[SIBO_S3EMY]*10));
                    else
                        fdec_t1.ul = (fdec.ul/(pr[SIBO_S3EMY]*100));
                    if (fdec_t1.ul == 0)
                        fdec_t1.ul = 1;    
                    sdec.ul = sdec.ul + fdec_t1.ul;
                    if (sdec.ul > fdec.ul){                    
                        IODLC_ubArea_status = AreaDec;
                        sdec.ul = fdec.ul;
                    }
                }
#endif
              else
                  sdec.ul = fdec.ul;
          }
          else {
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
              if ((pr[S4DEC3]!=0)&&(SIBO_EMYFLAG==0)&&(SIBO_INSF==0)){
#else
              if (pr[S4DEC3]!=0){
#endif
                  if (pr[U_ACCDEC] == 0) //2 dot
                      fdec_t3.ul = (fdec.ul/(pr[S4DEC3]*10));
                  else
                      fdec_t3.ul = (fdec.ul/(pr[S4DEC3]*100));
                  if (fdec_t3.ul == 0)
                      fdec_t3.ul = 1;    
                  sdec.ul = sdec.ul + fdec_t3.ul;
                  if (sdec.ul > fdec.ul)
                      sdec.ul = fdec.ul;
              }
              else{
                  sdec.ul = fdec.ul;
              }
          }
          
      }
      else {
          if ( ssdino ){
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                if ((pr[S4DEC2]!=0)&&(SIBO_EMYFLAG==0)&&(SIBO_INSF==0)){
#else
              if (pr[S4DEC2]!=0){
#endif
                  if(IODLC_ubArea_status < Arealand)
                      IODLC_ubArea_status = AreaS4;
                  else if(IODLC_ubArea_status >= Arealand)
                      IODLC_ubArea_status = AreaS6;
                  
              #if 1
                  fdec_t2.ul = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,delta_f);
              #else
                  if (FcmdOverFlag==1)
                      fdec_t2.ul = (U32xU32divU32(sdec.ul,sdec.ul,delta_f))>>2;
                    else
                      fdec_t2.ul = U32xU32divU32(sdec.ul,sdec.ul,delta_f);
              #endif
                
                    if (fdec_t2.ul == 0)
                        fdec_t2.ul = 1;
                    sdec.ul = sdec.ul - fdec_t2.ul;
                    if((SLONG)sdec.ul < 0){
                        sdec.ul = 0;
                    }    
                }
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
                else if((SIBO_EMYFLAG==1)&&(pr[SIBO_S4EMY]!=0)&&(SIBO_INSF==0)){
                    if(IODLC_ubArea_status < Arealand)
                        IODLC_ubArea_status = AreaS4;
                    else if(IODLC_ubArea_status >= Arealand)
                        IODLC_ubArea_status = AreaS6;
                    fdec_t2.ul = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,delta_f);
                  if (fdec_t2.ul == 0)
                      fdec_t2.ul = 1;
                  sdec.ul = sdec.ul - fdec_t2.ul;
                  if((SLONG)sdec.ul < 0){
                      sdec.ul = 0;
                  }    
              }     
#endif   
              else        
                  sdec.ul = fdec.ul;
          }
          else{
//                       if (pr[S4DEC2]!=0){
              if (pr[S4DEC3]!=0){
                  fdec_t3.ul = U32xU32divU32(sdec.ul>>1,sdec.ul>>1,delta_f);
                
                  if (fdec_t3.ul == 0)
                      fdec_t3.ul = 1;
                  sdec.ul = sdec.ul - fdec_t3.ul;
                  if((SLONG)sdec.ul < 0){
                      sdec.ul = 0;
                  }    
              }        
              else{        
                  sdec.ul = fdec.ul;
              }
          }
          
      }
    //ftemp.ul = ulAminusB_Under(ftemp.ul, sdec.ul);
      if (ftemp.ul<sdec.ul)
          ftemp.ul = 0;
      else
          ftemp.ul = ftemp.ul - sdec.ul;
  }
  
  sdec_old.ul = sdec.ul;
}    
    
void accelerate(void)
{
    ULONG ax;         

    dec_integral = fcmd.ul;
    sdec.ul = 0;                        
    if (STALLC==0){
        ACCODEC = ACCON;  

        if ((pr[S4ACC1]==0)&&(pr[S4ACC2]==0)){
            if (ftemp.uw.hi< Fcmd) {
              if (((pr[AAAD]!=1)&&(pr[AAAD]!=3))||(MFI_AAADDIS==1))
                  ax = acc_decel(); // Linear Adjustable Accel/Decel                    
                else                            // 60.00Hz, 0.1 sec
                  ax = (ULONG)(6000*655)+(((ULONG)6000*23593)>>16);
                
                //--- 03/06/06  Max.SJ.Chang: when acc/dec time = 0, ftemp.ul = Fcmd directly
                if (ax==0){
                    ftemp.uw.hi = Fcmd;
                    ftemp.uw.low = 0;
                }
                else{
                    //ftemp.ul = ulAplusB_Over(ftemp.ul, ax);
                    ftemp.ul = ftemp.ul + ax;                    
                }
            }
        }
        else {
            if (((pr[AAAD]!=1)&&(pr[AAAD]!=3))||(MFI_AAADDIS==1))
                facc.ul = acc_decel(); // Linear Adjustable Accel/Decel                   
            else                            // 60.00Hz, 0.1 sec
                facc.ul = (ULONG)(6000*655)+(((ULONG)6000*23593)>>16);        
            //--- 03/06/06  Max.SJ.Chang: if facc.ul = 0, skip Scurve
            if (facc.ul==0){
                ftemp.uw.hi = Fcmd;
                ftemp.uw.low = 0;
            }
            else{
                ScurveAcc();
            }
        }
        //-------- Gear Gap Function
        if (ftemp.uw.hi >= pr[GEAR_ACCF]){
            if (GearAccCnt<((ULONG)pr[GEAR_ACCT]*10)){
                ftemp.uw.hi = pr[GEAR_ACCF];
                GearAccCnt ++;
            }    
            else //[Dwell S curve,Lyabryan,2018/11/21]
                SLOWSPSTR = 1;
        } 
        else{ 
            SLOWSPSHOW = 1; //[Dwell S curve,Lyabryan,2018/11/21]
            GearAccCnt = 0; 
        }
        //-------- End of Gear Gap Function
    }//End of Stall by current
    else{
        if (NORMALSP==1){
            ACCODEC = DECON;            // DECEL ON
            ax = acc_decel();
              
            if (ax==0){
                ftemp.uw.hi = Fcmd;
                ftemp.uw.low = 0;
            }
            else{
              //ftemp.ul = ulAminusB_Under(ftemp.ul, ax);
              if (ftemp.ul<ax)
                ftemp.ul = 0;
              else
                ftemp.ul = ftemp.ul - ax;
            }
        }
    }
    
  if (ftemp.uw.hi >= Fcmd){
        ftemp.ul = ((ULONG)Fcmd<<16);
    }

    if (((pr[AAAD]==1)||(pr[AAAD]==3)||(pr[AAAD]==4)||(STALL_AUTO==1))&&(MFI_AAADDIS==0)){
        //AUTO_DECEL=1;       // Auto Decel
        SmartStallCNew();
    }
    else
        fcmd.ul = ftemp.ul;

    if (fcmd.uw.hi >= Fcmd){         // Normal speed check
        if(IODLC_ubArea_status <= AreaS2)
            IODLC_ubArea_status = Areahold;
        else if(IODLC_ubArea_status >= AreaS3) //[Creep-Optimis,Lyabryan,2019/02/11]
            IODLC_ubArea_status = Arealand;
        NORMALSP = 1;
        STALLC2 = 0;
    }    
          
}


void chk_stallv(void)
{
    UWORD RegLevel, uwStall4ad, uwdcbusAD;
    
    uwdcbusAD = dcbusAD >> 2; // dino, 03/07/2007
    uwStall4ad = stall4ad >> 2; // dino, 03/07/2007

        if (KEB_ON==1)
            RegLevel = (LVR4ad>>2)+20;
        else{
            if (pr[STALL4V] == 0){
                STALLV = 0;
                RegLevel = STALL_VL-20;
            }
            else {
                RegLevel = uwStall4ad-20;
                if (uwdcbusAD >= uwStall4ad)
                    STALLV = 1;
                else if (uwdcbusAD < RegLevel)
                    STALLV = 0;
            }
        }    
                
        decel_error = (SWORD)((uwdcbusAD - RegLevel)<< 5);
        if (decel_error > (SWORD)VERRORLIMIT)
            decel_error = VERRORLIMIT;
        else if (decel_error < (SWORD)-VERRORLIMIT)
            decel_error = -VERRORLIMIT;
}
/*-------- end of check stall function --------------*/

void SmartStallCNew(void)
{
    SLONG px,qx;                                
    ULONG rx;                                 
    UWORD ax, uwIrmsAD;

    uwIrmsAD = TB1_uwNewIrmsAD >> 2;  // New IED Irated is 110%, DINO, 09/06/2010
                 
    if (uwIrmsAD < 341){          // where 341 is I rated 
        ax = ((341-uwIrmsAD)>>6)+1;
    }  
    else
        ax = 1;                                                                  
            
        px = ((SLONG)accel_error*pr[AKP]);      
        // Integral Time,                                 
        rx = ((ULONG)pr[FMAX]<<16);               
        qx = (SLONG)accel_error*(pr[AKI]*ax);            
        acc_integral += qx;                 
        if (acc_integral < 0){
            acc_integral = 0;
        }
        else if (acc_integral > rx){
            acc_integral = rx;
        }
                                                          
        px += acc_integral;                          
    if (px > (SLONG)ftemp.ul){
      px = ftemp.ul;
    }

        if (px > 0){                        
            fcmd.ul = px;
            if (fcmd.uw.hi > pr[FMAX])
                fcmd.ul = (ULONG)pr[FMAX]<<16;
        }                                                 
        else                                              
            fcmd.ul = 0;
}

//===============================================//
// VDC = [(DC_BUS * 0.2/20) - 1.5]*(10/7)        //
// VDC_ad = (VDC / 5 )*1023                      //
//===============================================//
//#define     VDC370V     761
#define     VDC370V     643
void SmartStallVNew(void)                                 
{                                                         
    SLONG px,qx;                                
    ULONG rx;                                 
    UWORD ax, uwdcbusAD;
        
    uwdcbusAD = dcbusAD >> 2; // dino, 03/07/2007

    if ((uwdcbusAD < VDC370V)&&(KEB_ON==0)){
    ax = ((VDC370V-uwdcbusAD)>>6)+1;
    }        
    else{
    ax = 1;
  }

    px = ((SLONG)decel_error*pr[DKP]);          
    // Integral Time,                                 
    rx = ((ULONG)pr[FMAX]<<16);               
    qx = (SLONG)decel_error*(pr[DKI]*ax);            
    dec_integral += qx;                 
    if (dec_integral < 0){
    dec_integral = 0;
  }
    else if (dec_integral > rx){
    dec_integral = rx;
  }
                                                          
    px += dec_integral;                          

  if (px < (SLONG)ftemp.ul){
    px = ftemp.ul;
  }

    if (px > 0){
    fcmd.ul = px;
    if (fcmd.uw.hi > pr[FMAX])
            fcmd.ul = (ULONG)pr[FMAX]<<16;
    }
    else
    fcmd.ul = 0;
}                                                         
 
void SmartVdcCtrl(void)                             
{
    SLONG px,qx;
    ULONG rx;
    UWORD uwstall4ad, uwdcbusAD;

    uwstall4ad = stall4ad >> 2; // dino, 03/07/2007
    uwdcbusAD = dcbusAD >> 2; // dino, 03/07/2007

    decel_error = ((SWORD)(uwdcbusAD+40-uwstall4ad))<<5;

    px = ((SLONG)decel_error*pr[DKP]);
    // Integral Time,
    rx = ((ULONG)(3000<<15));
    qx = (SLONG)decel_error*pr[DKI];
    acc1_integral = acc1_integral + qx;
    if (acc1_integral < 0){
    acc1_integral = 0;
  }
    else if (acc1_integral > rx){
    acc1_integral = rx;
  }

    px += acc1_integral;
    if (px > 0){
    if (px > (SLONG)(3000<<16)){
            px = (SLONG)(3000<<16);
        }
    }
    else{
    px = 0;
  }
}       

void decelerate(void)
{
    ULONG ax;

    acc1_integral = 0;       // SmartVdcCtrl used
    acc_integral = fcmd.ul;
    sacc.ul = 0;                        

    if (STALLV==0){
        ACCODEC = DECON;  
        
        if ((pr[S4DEC1]==0)&&(pr[S4DEC2]==0)&&pr[S4DEC3]==0){
            if (ftemp.uw.hi>Fcmd){
                if (((pr[AAAD]!=2)&&(pr[AAAD]!=3))||(MFI_AAADDIS==1))   // Decel (Linear)
                    ax = acc_decel();
                else                                // 60.00Hz, 0.1 sec                    
//          ax = (ULONG)(6000*655)+(((ULONG)6000*23593)>>16);
                    ax = 3932160;

                //--- 03/06/06  Max.SJ.Chang: when dec time = 0, ftemp.uw.hi = Fcmd directly
                if (ax==0){
                    ftemp.uw.hi = Fcmd;
                    ftemp.uw.low = 0;
                }
                else{
                //ftemp.ul = ulAminusB_Under(ftemp.ul,ax);
                    if (ftemp.ul<ax)
                        ftemp.ul = 0;
                    else
                        ftemp.ul -= ax;                
                }
            }
        }
        else{
            if (((pr[AAAD]!=2)&&(pr[AAAD]!=3))||(MFI_AAADDIS==1)){   // Decel (Linear)
                    fdec.ul = acc_decel();
            }
            else                                // 60.00Hz, 0.1 sec                    
//        fdec.ul = (ULONG)(6000*655)+(((ULONG)6000*23593)>>16);
                fdec.ul = 3932160;

            //--- 03/06/06  Max.SJ.Chang: if fdec.ul=0, skip S-curve
            if (fdec.ul==0){
                ftemp.uw.hi = Fcmd;
                ftemp.uw.low = 0;
            }
            else{                
                if(IODLC_CRPLS_SW&&(pr[SOFC]==3)&&((pr[IODEN]&0x0002)==0x0002)&&pr[IODDE]!=0){ // [IODLC, Lyabryan, 2016/11/11]
                    IODLC_CRPLS();
                    ScurveDec_CRIPLS();
                }
                else
                    ScurveDec();
            }
        }

        if (ftemp.uw.hi < Fcmd){ //add 07232004
            ftemp.uw.hi = Fcmd;
            ftemp.uw.low = 0;
        }
        //-------- Gear Gap Function
        if (ftemp.uw.hi <= pr[GEAR_DECF]){
            if (GearDecCnt<((ULONG)pr[GEAR_DECT]*10)){
                ftemp.uw.hi = pr[GEAR_DECF];
                GearDecCnt ++;
            }    
        } 
        else
            GearDecCnt = 0;   
        //-------- End of Gear Gap Function
    }

//  if (((pr[AAAD]==2)||(pr[AAAD]==3)||(pr[AAAD]==4)||(KEB_AUTO==1)||(EF_AUTO==1))&&(MFI_AAADDIS==0)){
  if (((pr[AAAD]>1) || (KEB_AUTO==1) || (EF_AUTO==1)) && (MFI_AAADDIS==0)){
        SmartStallVNew();
    }
    else
        fcmd.ul = ftemp.ul;
}

void Fx2VmCompare(VFTableStruct *VFComp,UWORD f1,UWORD v1,UWORD f2,UWORD v2)
{
  if (f1>=f2){
    (*VFComp).F1 = f1;
    (*VFComp).V1 = v1;
    (*VFComp).F2 = f2;
    (*VFComp).V2 = v2;
  }
  else{
    (*VFComp).F1 = f2;
    (*VFComp).V1 = v2;
    (*VFComp).F2 = f1;
    (*VFComp).V2 = v1;
  }
}

UWORD GetFx2Vm(UWORD fx)
{
  UWORD vmaxTmp, vminTmp;
  VFTableStruct VFTable;
  SLONG sltemp;
  //==============================//  
  //  typedef struct{       //
    //      UWORD F1;       //
    //      UWORD V1;       //
    //      UWORD F2;       //
    //      UWORD V2;           //
  //  }VFTableStruct;       //
  //==============================//
  if ((pr[AUTO_T]==1)||(pr[CTRLM]>=SVC)){
           if (fx >= fbase)
              return vbase;
         else{   //[SVC boost,Sampo,2018/06/13]
         	     vminTmp = pr[VMIN1];
         	     sltemp = (SLONG)(fx*(vbase-vminTmp)/fbase) + (SLONG)vminTmp;
         	     return(sltemp);
              //return (((ULONG)fx * vbase)/fbase);
            }
    }
    else{
        if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2)){// Motor 2 highest priority
          Fx2VmCompare(&VFTable,pr[FMID2_1],pr[VMID2_1],pr[FMID2_2],pr[VMID2_2]);
          vminTmp = pr[VMIN2];
          vmaxTmp = pr[VMAX2];
        }
        else{
          Fx2VmCompare(&VFTable,pr[FMID1_1],pr[VMID1_1],pr[FMID1_2],pr[VMID1_2]);
          vminTmp = pr[VMIN1];
          vmaxTmp = pr[VMAX1];
            if(vmaxTmp == 0)      //[The minimum value setting of rated voltage, Bernie, 10/26/2011]
                vmaxTmp = 1;
    }
    
        if (fx >= fbase)
          return vmaxTmp;      
        else if (fx >= VFTable.F1){
            if (VFTable.F1==fbase){
        return VFTable.V1;
      }
            else{
              return ((((SLONG)(fx-VFTable.F1)*(SLONG)(vmaxTmp-VFTable.V1))/((SLONG)(fbase-VFTable.F1)))+(SLONG)VFTable.V1);
              //----------------------------------------------------//
              //              (vmax - V1)                           //
              //    (fx-F1)* ------------- + V1                     //
              //              (fbase - F1)                          //
              //----------------------------------------------------//                
            }
        }    
        else if (fx >= VFTable.F2 && fx < VFTable.F1){
          if (VFTable.F2==VFTable.F1){
              return VFTable.V2;
            }
            else{
                return ((((SLONG)(fx-VFTable.F2)*(SLONG)(VFTable.V1-VFTable.V2))/((SLONG)(VFTable.F1-VFTable.F2)))+(SLONG)VFTable.V2);
              //----------------------------------------------------//
              //              (V1 - V2)                             //
              //    (fx-F2)* ------------- + V2                     //
              //              (F1 - F2)                             //
              //----------------------------------------------------//                
            }
        }    
        else if ((fx > fmin)&&(fx < VFTable.F2)){
          if (VFTable.F2==fmin){
              return vminTmp;
            }
            else{
              return ((((SLONG)(fx-fmin)*(SLONG)(VFTable.V2-vminTmp))/((SLONG)(VFTable.F2-fmin)))+(SLONG)vminTmp);
              //----------------------------------------------------//
              //               (V2 - vmin)                          //
              //    (fx-fmin)* ------------ + vmin                  //
              //               (F2 - fmin)                          //
              //----------------------------------------------------//              
            }
        }    
        else{
          return vminTmp;
        }            
    }   
}


#define DCI_LIMIT      20              // 20 = 2.0v  Limit per step vcmd.
#define DCI_DEC        20              // DCI decrease
/*------------- DC Injection Control -------------------------------------------------------
 -      Vcmd = Vcmd + Kp * (dc_level-Isum), where Isum is Ad7,
 -      dc_level is dc current level (dci_cl)
 -----------------------------------------------------------------------------------------*/
void dci_ctrl(UWORD dci_ref, UWORD VLimit)
{
    SWORD ax;
        
    if (pr[CTRLM]!=FOCPG){
        ax = dci_ref - Ismax_uwPu;

        if (ax > (SWORD)0) {
            if (ax > DCI_LIMIT)
                ax = DCI_LIMIT;            // Limit 20 = 2.0V
                VF_Vcmd = VF_Vcmd + (((ULONG)ax*pr[DCI_KI])>>8);
            if (VF_Vcmd >= VLimit)         // 50% vbase_l
                VF_Vcmd = VLimit;
            
        }
        else if (ax < (SWORD)0) {
            ax = -ax;
            if (ax > DCI_LIMIT)
                ax = DCI_LIMIT;            // Limit 20 = 2.0V
                ax = (((ULONG)ax*pr[DCI_KI])>>8);
            if (VF_Vcmd <= ax)
                VF_Vcmd = 0;
            else
                VF_Vcmd = VF_Vcmd - ax;
        }
    }        
}

void Run_Execute(void)
{
    UWORD uwBKRUNT, FreqStart, uwFUPper;

    if ( pr[CTRLM]==FOCPM )
      FreqStart = 0;
    else
      FreqStart = fstart;
/*  // Delete by DINO, 03/05/2010
  //====== Record Dcbus Value 
  if (DCBUSREC==1){
    dcbusDCInit = dcbusDC;
    DCBUSREC = 0;
  }
*/      
    if (RUNDCI==1) 
    {
        if (ZEROST == 1)
        {
            if (ZEROSP == 1)
            { 
                //Zero speed flag enable [01-34] 
                ftemp.ul = 0;
                fcmd.ul = 0;
                // 13107 = 9268 * sqrt(2)
                if ((pr[CTRLM]==VF)||(pr[CTRLM]==VFPG))
                {
                    if ((EXT_MOTOR1to2==1)||(pr[MOTORSEL]==2))  // Motor 2 highest priority
                    {
                        dci_ctrl(U16xU16divU16(COF_uwMIrRe, 13107, pr[I_RATE]), pr[VMIN2]);
                    }
                    else
                    {
                        dci_ctrl(U16xU16divU16(COF_uwMIrRe, 13107, pr[I_RATE]), pr[VMIN1]);
                    }
                }        
                else if (pr[CTRLM]==SVC)
                {
                    dci_ctrl(U16xU16divU16(COF_uwMIrRe,13107,pr[I_RATE]),VF_uwVcmpMax>>1);
                }
            }  //end if (ZEROSP == 1)
            else
            {
                if (Fcmd>FreqStart)
                {
                    fcmd.uw.hi = FreqStart;
                    ftemp.uw.hi = FreqStart;
                }
                else
                {
                    fcmd.uw.hi = Fcmd;
                    ftemp.uw.hi = Fcmd;                     
                }
                      
                ftemp.uw.low = 0;
                fcmd.uw.low = 0;
                RUNDCI = 0;
                TB1_uwDCICnt = 0;   //[DCI redesign, Bernie, 2016/11/18]
                ZEROST = 0;
            }
      }
      else
      {
          if (TB1_uwDCICnt >= (pr[DCISTA]*100))
          { // RUN DC Injection finished
              if (Fcmd>FreqStart)
              {
                  fcmd.uw.hi = FreqStart;
                  ftemp.uw.hi = FreqStart;
              }
              else
              {
                  fcmd.uw.hi = Fcmd;
                  ftemp.uw.hi = Fcmd;
              }
              ftemp.uw.low = 0;
              fcmd.uw.low = 0;
              RUNDCI = 0;

              STOPDCI = 0;       //[DCI redesign, Bernie, 2016/11/18]
              RUN_DCI_OK = 1;            //[GK communication, Bernie, 2013/03/18].
              TB1_uwDCICnt = 0;
#if SCOTTY
              if (pr[CTRLM]==FOCPM)
              {        //ADDED BY SCOTTY 2007/08/06
                  if (ALIGN ==0)
                  {
                      Init_SpDtPG1();
                      ALIGN = 1;
                      pr[ST_TUNE] = 0;      //ADDED SCOTTY 09/27/2007
                  }
              }
#endif
          }
          else
          {   // DC Injection processing
              ftemp.ul = 0;
              fcmd.ul = 0;
              TB1_uwDCICnt++; 
              if (pr[CTRLM]!=FOCPM)
              {   //ADDED BY SCOTTY 2006/06/30        
                  dci_ctrl(U16xU16divU16(pr[DCICL],COF_uwIIratePu,100),(vbase>>1));
              }
          }
      }    
    }//End RUN DC-injection
    // [For generation direction, by Justin , 2010/04/27
    else if ( GEN_START )
    {
      Generation_DIR();
    }
    //]

    Torq_Tune_Process();   //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]







    
    if (((PositionCom==1)||(ZeroServo==1))&&(APRCMDDIR!=WGDIR))
    {
        NORMALSP = 0;
        adjcnt = 0;
        Fcmd = 0;
          
        if (fcmd.uw.hi > fmin)
        {
            if ((!HOLD)&&(!RESTART)&&(!SPSEARCH)&&(!RUNDCI)&&(!VPHOLD))
            {
                chk_stallv();
                decelerate();
            }
        }
        else
        {
            ZCycleCNT = 0;
            WGDIR = APRCMDDIR;
            PG_integral = 0;
            VF_SlipLPF.sl = 0;
        }
    }
    else if ((PositionCom==0)&&(ZeroServo==0)&&(CMDDIR!=WGDIR))
    {
        NORMALSP = 0;
        adjcnt = 0;
        Fcmd = 0;
        APR_uwZpulseCnt = 0;
        APR_uwPGCycle = 0;
      
        if (fcmd.uw.hi > fmin)
        {
            if ((!HOLD)&&(!RESTART)&&(!SPSEARCH)&&(!RUNDCI)&&(!VPHOLD))
            {
                chk_stallv();
                decelerate();
            }
        }
        else
        {           
            WGDIR = CMDDIR;
            PG_integral = 0;
            VF_SlipLPF.sl = 0;
            ZCycleCNT = 0;
        }
        CMDDIR2 = CMDDIR;
        APRCMDDIR = CMDDIR;
    }
    else
    {
        CMDDIR2 = CMDDIR;
        APRCMDDIR = CMDDIR;
        if (TUN_START == 1)
        {
            if ( pr[PM_AUTO_T]==3 )  // Add by DINO, 08/11/2008
            {
                HOLD = 0;
            }
            else if ((TUN_DC_OK==0)||(TUN_HFSS_OK==0))
            {
                if (pr[PM_AUTO_T]!= 2 )   // Debug BY SCOTTY 04/09/2007
                {
                    HOLD = 1;       // Hold Speed 禁止加減速
                }
            }
            else
            {
                HOLD = 0;
            }
        }
        // [ Generation Operation, DINO, 04/27/2010
        else if ((GEN_START == 1)&&(pr[CTRLM] > SVC)&&(pr[EPS_OPTM]!=4)) //[EPS autodetect dir,Lyabryan,2018/07/02] //[EPS, Sampo, 03/27/2011]
            Fcmd = 0;
        // ]
        else
        {
            if (Fcmd!=fkey.uw.hi)
            {
                NORMALSP = 0;
                adjcnt = 0;
            }
                    
            if ((pr[PIDSL]==0)||(MFI_PIDDIS==1))
            {
                if (CMDJOG==0)
                  ext_updown();
          
                Fcmd = fkey.uw.hi;    
            }
            else
            {
                if (PIDHOLD==0)                
                    PID_Ctrl();
                PID_Sleep();
            }
            if (MFI_WG==1)
            {
                WgOff2Sby();
            }
        }
                  
        if ((Fcmd < pr[FLOWER])&&(Fcmd>=fmin))
        {
            Fcmd = pr[FLOWER];
            fcmd.uw.low = 0;
        }

        // [ EPS Speed Limit, Add by DINO, 08/30/2010
        if ( EPS )
          uwFUPper = COF_uwFepsLimit;
        else
          uwFUPper = pr[FUPPER];
        if (Fcmd > uwFUPper){
            Fcmd = uwFUPper;
        }
        // ]

        //==========  Skip freq.============================
        if (FSKIPFLG == 0){
            if (Fcmd==fcmd.uw.hi)
                FSKIPFLG = 1;
            if ((Fcmd>fskip3l)&&(Fcmd<fskip3h)){ 
                Fcmd = fskip3l;
                FSKIPFLG = 0;
            }    
            if ((Fcmd>fskip2l)&&(Fcmd<fskip2h)){ 
                Fcmd = fskip2l;    
                FSKIPFLG = 0;
            }    
            if ((Fcmd>fskip1l)&&(Fcmd<fskip1h)){ 
                Fcmd = fskip1l;        
                FSKIPFLG = 0;
            }    
                
            if (Fcmd>pr[FMAX])
                Fcmd = pr[FMAX];
        }
        else {
            if (Fcmd==fcmd.uw.hi)
                FSKIPFLG = 0;
            if ((Fcmd>fskip1l)&&(Fcmd<fskip1h)){
              if (fskip1h>=pr[FMAX]){
                  if (fskip1l>pr[FMAX])
                    Fcmd = pr[FMAX];
                  else
            Fcmd = fskip1l;
                }
                else
                    Fcmd = fskip1h;
                FSKIPFLG = 1;
            }    
            if ((Fcmd>fskip2l)&&(Fcmd<fskip2h)){
                if (fskip2h>=pr[FMAX]){
                  if (fskip2l>pr[FMAX])
                    Fcmd = pr[FMAX];
                  else
                    Fcmd = fskip2l;
                }
                else
                    Fcmd = fskip2h;    
                FSKIPFLG = 1;
            }    
            if ((Fcmd>fskip3l)&&(Fcmd<fskip3h)){
                if (fskip3h>=pr[FMAX]){
                  if (fskip3l>pr[FMAX])
                    Fcmd = pr[FMAX];
                  else
                    Fcmd = fskip3l;
                }
                else
                    Fcmd = fskip3h;        
                FSKIPFLG = 1;    
            }    
        }        
            
    if ((!HOLD)&&(!RESTART)&&(!SPSEARCH)&&(!RUNDCI)&&(!STtune)&&(!VPHOLD)){
          if (fcmd.uw.hi <= Fcmd){
              chk_stallc();
              accelerate();
          }   
          else if (fcmd.uw.hi > Fcmd){
              chk_stallv();
              decelerate();
          }
        }
        /*--------- Check Standby ---------*/
    if (TUN_START==0 && MFI_WG==0 && TqSpdMode==0 && STtune==0){
            if ((fcmd.uw.hi<=fmin) && (Fcmd<=fmin)){
              // [ Change STANDBY condition, DINO, 05/03/2010
                if ((pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=FOCPM)){
                    if (pr[SL_ZSP]==0){ //standby
                        WgOff2Sby();
                    }
                    else if (pr[SL_ZSP]==1){
                        if (ZEROSP==0){
                            fout.ul = 0;
                            Vcmd_LL = 0;
                            if((pr[SysControl]&0x0800)==0x0000){     //[DCI redesign, Bernie, 2016/11/18]
                                 RUNDCI = 1;
                                 ZEROST = 1;
                                 ZEROSP = 1;
                            }
                        }
                    }
                    else if (pr[SL_ZSP]==2){
                        fcmd.ul = ((ULONG)fmin<<16);
                        ftemp.ul = ((ULONG)fmin<<16);
                    }
                }
                else{                   //control mode is FOCPG or FOCPM
                    if (pr[SL_ZSP]==2){
                        fcmd.ul = ((ULONG)fmin<<16);
                        ftemp.ul = ((ULONG)fmin<<16);
                    }
                    else{               //[When Fcmd = fmin can't stop, Bernie, 2012/02/06]
                        fcmd.ul = 0;
                        ftemp.ul = 0;
                    }
                }
          }
          // ]
        }
          
        if ((fcmd.uw.hi>=fmin)&&(Fcmd!=0)){
            if (STANDBY==1){              //01-28 = 0
                STANDBY = 0;
                fcmd.ul = ((ULONG)fmin<<16);
                ftemp.ul = ((ULONG)fmin<<16);
            }
            else{                   //01-28 = 1 or 2
                if (ZEROSP==1)
                    ZEROSP = 0;
            }
        }         
          
        /*-------- Braker Lock & Release --------*/
        if (pr[PM_AUTO_T] == 1){  // disable BK RUN delay time, dino, 08/11/2008
//          if ( TUN_WAIT==1 )
          if ( CUR_swIdseRefPu!=TUN_uwIdCurr )  // Modify by DINO, 07/21/2008
            uwBKRUNT = 65535;   // Don't release BRK during TUN_WAIT, modify by DINO, 06/27/2008
          else
            uwBKRUNT = 0;
        }
        // [ Don't release BRK before rolling, Add by DINO, 06/29/2009
    else if (pr[AUTO_T] == 1){
          if (TUN_ROLLING == 0)
            uwBKRUNT = 65535;
          else
        uwBKRUNT = 0;
    }
        // ]
    else{
          uwBKRUNT = pr[BRK_RUNDT];
    }

        if (pr[PM_AUTO_T]==2 || STtune==1 || TUN_SS==1)
        {  // dino, 08/11/2008
            BRK_RLS = 0;  //lock
        }
        // [ Don't release BRK in Static Tune, Add by DINO, 06/29/2009
        else if (pr[AUTO_T] == 2)
        {
            BRK_RLS = 0;  //lock
        }         
        else
        {
            // [ Flux Confirm, Add by DINO, 06/29/2009
            if (I0CHK == 0)
            {
                BRK_RLS = 0;
            }
            // ]
            else
            {
                if (fcmd.uw.hi != 0)
                {
                    BRK_RLS = 1;  //release
                    TB1_uwBrkRunCnt = uwBKRUNT+1;
                }
                else
                {
                    if ( TB1_uwBrkRunCnt > uwBKRUNT )
                        BRK_RLS = 1;  //release
                    else 
                    {
                        BRK_RLS = 0;  //lock
                        if(UCMP == 0)
                        {    //[UCMP function, Bernie, 2016/06/14]
                            TB1_uwBrkRunCnt++;
                        }
                    }
                }
            }
        } 

        /*-------- AVR function -----------------------*/
        if ((pr[AVR]==0)||((pr[AVR]==2)&&(ACCODEC==ACCON)))
            AVREN = 1;
        else
            AVREN = 0;                  
    } 
}

void Stop_Execute(void)
{
//- add 12/12/2007  DINO
    UWORD uwFmin, uwFdci, uwIdci, uwStopDCITime;

    if ( pr[CTRLM]==FOCPM || pr[CTRLM]==FOCPG  ){
        uwFmin = 0;
        uwFdci = 0;
        uwIdci = 10;
        if ( SPR_slIqseLimit==0 )
          uwStopDCITime = pr[DCISTP]*100;   // Stop DCI Time=Pr07-04, addd by DINO, 07/10/2008
        else
          uwStopDCITime = pr[DCISTP]*100 + pr[TQ_LPG];  // Stop DCI Time=Pr07-04 + Pr15-100, add by DINO, 05/29/2008
    }
    else{
        uwFmin = fmin;
        uwFdci = pr[DCIFSTA];
        //uwIdci = pr[DCICL];                 //mask by Bernie    //[DCI Level when stop, Bernie, 05/21/2012]
        uwIdci = pr[STOP_DCICL];    //[DCI Level when stop, Bernie, 05/21/2012]
        uwStopDCITime = pr[DCISTP]*100;         // Stop DCI Time=Pr07-04, add by DINO, 05/29/2008
    }
//- end 12/12/2007

    if (((CMDFREE==1)||(MFI_WG==1)/*||(RUNDCI==1)*/||(STANDBY==1)||(STtune==1)||(BEFORERUN==1))){  // Short_Circuit Detection, DINO, 05/19/2010  //remove RUNDCI flag for DCI function redesign //[DCI redesign, Bernie, 2016/11/18]
        stop_status();  
    }
    else{                           // Stopping
        if (STOPDCI==0){  // Stopping don't have DC injection
            if ((fcmd.uw.hi<=uwFmin)){
                if ((uwIdci!=0)&&(uwStopDCITime!=0)&&(!CMDJOG)&&(RUNNING)&&(TUN_START==0 || TUN_PHASEZ_OK==1)){  // Modify by DINO, 07/10/2008
                      STOPDCI = 1;
                      RUNDCI = 0;
                      TB1_uwDCICnt = 0;
                }
                else{
                    stop_status();
                }
            }
            else{
                if ((!HOLD)&&(!RESTART)&&(!SPSEARCH)&&(RUNNING)&&(!VPHOLD)){
                      chk_stallv();
                      decelerate();
                }
                if ((uwIdci!=0)&&(uwStopDCITime!=0)&&(!CMDJOG)&&(!TUN_START)){
                    if (fcmd.uw.hi<=uwFdci){
                        STOPDCI = 1;
                        RUNDCI = 0;
                        TB1_uwDCICnt = 0;
                    }
                }   
            }
          }
          else{
              if (TB1_uwDCICnt>=uwStopDCITime){   //STOP DC Inject time
                  stop_status();
                  RUN_DCI_OK = 0;            //[GK communication, Bernie, 2013/03/18]
              }
              else{
                  if (fcmd.ul!=0){
                      if (VF_Vcmd != 0) {
                          if (VF_Vcmd <= DCI_DEC)
                              VF_Vcmd = 0;
                          else
                              VF_Vcmd -= DCI_DEC;
                      }
                      else {
                          ftemp.ul = 0;
                          fcmd.ul = 0;
                      }
                  }               // DC Injection processing
                  else {
                      TB1_uwDCICnt++;
                      RUN_DCI_OK = 0;  //DLC function, Henry, 2016/07/20
                      dci_ctrl(U16xU16divU16(pr[STOP_DCICL],COF_uwIIratePu,100),(vbase>>1));
                      if ((WGDIR!=CMDDIR)&&(ZeroServo==1)&&(pr[CTRLM]==FOCPG)){
                          WGDIR = CMDDIR;
                      }
                  }    
              }
          }
    }

  /*-------- Braker Lock & Release --------*/
    if (RUNNING == STOP){
      BRK_RLS = 0;      //lock
      if(TB1_uw0p5secCnt<500){
          TB1_uw0p5secCnt++;
          if(TB1_uw0p5secCnt>=500){
            TB1_uw0p5secCnt = 500;
              TB_500ms = 1;
          }
      }
        //AD_uwIA0 = LowPass(CurZero_LPG, (AN0<<4), AD_uwIA0);
        //AD_uwIB0 = LowPass(CurZero_LPG, (AN1<<4), AD_uwIB0);
        //AD_uwIC0 = LowPass(CurZero_LPG, (AN2<<4), AD_uwIC0);
      if((!GEN_START)&&(TB_500ms)|| (PWRON == 1)){  //(((pr[LV_OPTM]&0x0008)==0x0008)||(PWRON_IF)) //[remove DCI when EPS status, Lyabryan, 2015/12/09]
        AD_uwIA0 = LowPass(CurZero_LPG, (AN000<<4), AD_uwIA0);
        AD_uwIB0 = LowPass(CurZero_LPG, (AN001<<4), AD_uwIB0);
        AD_uwIC0 = LowPass(CurZero_LPG, (AN002<<4), AD_uwIC0);
      }
    }
    else if (pr[PM_AUTO_T]==2 || (pr[PM_AUTO_T]==3 && STtune==1)){  // Added by dino, 07/0/2008  Modify by DINO, 08/11/2008
        BRK_RLS = 0;  //lock
    }
  // [ Don't release BRK in Static Tune, Add by DINO, 06/29/2009
    else if (pr[AUTO_T] == 2){
        BRK_RLS = 0;  //lock
    }
    else{
    // [ Flux Confirm => BRK_RLS=0, don't release Brake , Add by DINO, 06/29/2009
        if (BRK_RLS == 1){
    // ]
            if (fcmd.uw.hi <= uwFmin){
                if (TB1_uwBrkStopCnt >= pr[BRK_STOPDT]){
                    BRK_RLS = 0;  //lock
                    TB1_uwBrkRunCnt = 0;  // BK RUN Counter, dino, 12/12/2007
                }
                else{
                    BRK_RLS = 1;  //release
                    TB1_uwBrkStopCnt++;
                }
            }
            else {
                BRK_RLS = 1;    //release
            }
        }
    }

//  ext_updown();
}

void CarryHandel(void)
{
  UBYTE cx;
  UWORD bx,dx;

// [ Delete by DINO, 03/06/2009
/*
  vbase1_4 = vbase >> 2;
  vbase1_8 = vbase1_4 >> 1;
*/
// ]
    if (pr[CTRLM]==DBCSECA){
        experiod = DBC_period;
    }
    else{
        if ((pr[AUTO_T]!=0 || pr[PM_AUTO_T]!=0) && TUN_SS==0) {
             experiod = U32divU16(MTU2CLK, 6000);  //6k, DINO, 05/19/2010
            WGMODE = 0;
        }
#if StandStill
        else if ( STtune || TUN_SS ) {
            if(pr[HPSPEC]>VFD_SINGLEPHASE)               //[Single phase input, Bernie, 01/19/2012])
                bx = maxcf(pr[HPSPEC]-VFD_SINGLEPHASE) * 1000;
            else
                bx = maxcf(pr[HPSPEC]) * 1000;
            experiod = U32divU16(MTU2CLK, bx); 
            WGMODE = 0;
        }
#endif
        else {
            dx = cf_swCFReal;
            if ((pr[PROTBIT]&0x4000)==0x0000){  // Bit14, disable Derating, dino, 05/30/2007
//                if ((RUNNING)&&(!STANDBY)&&(Error==0)) {  //09/05/2007
                if ((RUNNING)&&(!STANDBY)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))) {
                  // [ Modify Derating Function, DINO, 05/18/2010
// [ Delete by DINO, 10/21/2008
/*
                    dx = cf_swCFSet;
                    if(CCSET == 1){    //---  CC Derating Check ----              
                        TB1_uwCCCnt++;
                        if(TB1_uwCCCnt >= 500) {
                            if(cfstep==0){
                                cfstep=1;
                                cf_swOLCarry = cf_step1;
                                TB1_uwCCCnt = 0;
                            }
                            else if(cfstep==1){
                                TB1_uwCCCnt = 0;
                                cfstep=2;
                                cf_swOLCarry = 4000;     // cf_step2
                            }
        
                            if(T_DERATING==1){
                                if(cf_swOLCarry >= cf_swOHCarry)
                                    cf_swCFDerate = cf_swOHCarry;    // Carrier Freq for Derating
                                else
                                    cf_swCFDerate = cf_swOLCarry;
                            }
                        }
                    }
                    else {
                        TB1_uwCCCnt = 0;
                    }
                    if((cf_swCFDerate!=0)&&(TUN_START==0)) {
                        if (cf_swCFSet > cf_swCFDerate){
                            dx = cf_swCFDerate;         // derating
                        }
                    }
*/
// ]
          dx = cf_swCFDerate;
          // ]
                }
            }
            cf_swCFReal = dx;
            //------ Limitation Carry Frequency ------------------------------------//
            if (VH_EN==1){
                //bx = ((ULONG)pr[FMAX]*52429)>>16; // (pr[FMAX]*8(step)/10)
                if ((pr[PROTBIT]&0x0010)==0x0000) //Bit 4: six step / eight step
                  bx = ((ULONG)fkey.uw.hi*39322)>>16; // (pr[FMAX]*6(step)/10)
                else
                  bx = ((ULONG)fkey.uw.hi*52429)>>16; // (pr[FMAX]*8(step)/10)
            }
//-DINO 2008/02/21
            else if ( pr[CTRLM]==FOCPG || pr[CTRLM]==FOCPM )
                bx = 3000;              // Min. Carry = 3k
//-END 2008/02/21 
            else
                bx = pr[FMAX]>>4; // (pr[FMAX]*6.25(step)/100)

            //------ Limitation Carry Frequency ------------------------------------//
            //bx = (((ULONG)pr[FMAX]*4719)>>16); // (pr[FMAX]*6(step)/100)*1.2
            
            if (bx > cf_swCFReal)    
                cf_swCFReal = bx;
                
            if (VH_EN==1)
              COF_ulKTheta = U32xU32divU32(COF_uwFbRe, (ULONG)(65536), cf_swCFReal);
            //----------------------------------------------------------------------//
    
            dx = U32divU16(MTU2CLK, cf_swCFReal);
      /*------------------------------------------------------------*/ 
      /* PWM_MODE = 0, SVPWM 66%, DPWM 100%                         */
      /* PWM_MODE = 1, SVPWM 100%, SVPWM 100%                       */
      /* PWM_MODE = 2, SVPWM 66%, SVPWM 66%                         */
      /* PWM_MODE = 3, SPWM 66%, SPWM 100%                          */
      /* PWM_MODE = 4, SVPWM 100%, DPWM 100%                        */
      /*------------------------------------------------------------*/
            switch (pr[PWM_MODE]){        //Pr[12-10]
                default:
                case 0:     //SVPWM + DPWM
                case 1:     //SVPWM : (2/3) CF on all process  //[move parameter to 11-20, Bernie, 2017/02/16]
                case 3:     //SPWM  + DPWM
                case 4:   //SPWM + DPWM: 100% CF on ALL Process
                    cx = WGMODE;
                    if (TqSpdMode == 1){
                        experiod = dx;
                        WGMODE = 0; //SVPWM
                    }
                    else{
                        if ((RUNNING)&&(!STANDBY)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))) {
                            /*-------- Change WG mode, cx is variable for WG mode --------------*/
#if DINO
                            // [ Modify by DINO, 03/04/2009
                            if (WGMODE == 0){
                              if ((fcmd.uw.hi>=COF_uwFBase3_10) && (Vcmd_LL>=COF_uwVBase1_4)){
                                  cx = 1;   //Discontinue Mode
                                }
                            }
                            else{ //if (WGMODE == 1)
                              if ((fcmd.uw.hi<=COF_uwFBase1_4) || (Vcmd_LL<=COF_uwVBase1_8)){
                                  cx = 0;   //Sine Mode
                                }
                            }
                            // End 03/04/2009 ]
#else
                            if ((fcmd.uw.hi>=(F4CHWGM+500))&&(WGMODE==0)&&(Vcmd_LL>=600)){
                                cx = 1;                 //Discontinue Mode
                            }
                            else if ((fcmd.uw.hi<=F4CHWGM)&&(WGMODE==1)||(Vcmd_LL<=500)){
                                cx = 0;                 //Sine Mode
                            }
#endif
                        }
    
                        if (cx == 0){
                          if (pr[PWM_MODE]!=4)
                              dx = dx + (dx >> 1);  
                            experiod = dx;
                            WGMODE = 0;   // SVPWM,2/3 carry freq.
                        }
                        else{
                            //if (pr[PWM_MODE]==2){    //[move parameter to 11-20, Bernie, 2017/02/16]
                            if (pr[PWM_MODE]==1){ 
                                dx = dx + (dx >> 1);  
                                experiod = dx;
                                WGMODE = 0;     // SVPWM
                            }
                            else{    
                                experiod = dx;
                                WGMODE = 1;         //DisContinue
                            }    
                        }
                    }    
                    break;
                case 2: //SVPWM      //[move parameter to 11-20, Bernie, 2017/02/16]
                    //dx = dx + (dx >> 1);  
                    experiod = dx;                 
                    WGMODE = 0;
                    break;
            }    
        }//if (pr[AUTO_T]==0)
    }
}

#if 0
void AFM_Output_GFC(void)          //[APP01 IO carde support, Bernie, 2013/03/20]
{ 
  UBYTE i;
  SLONG DispValue, DispBase, DispTemp;
  UWORD uwFout;

  for (i=0; i<2; i++ ){
      if(i==0){	
          //uwFout = fout.uw.hi;
          DispValue = SpDt_uwFfbk;
          //DispValue = uwFout;
          DispBase = pr[FMAX];
          if (WGDIR==REVERSE)
              DispValue = -DispValue;
      }
	  if(i==1){
          DispValue = IrmsRe;
          DispBase = (pr[I_RATE] * 5)>>1;	  	  
      }
	  DispValue = abs(DispValue);

      // [ Debug by DINO, 11/02/2009
      DispTemp = S32xS32divS32(DispValue, 4096, DispBase);
      // ]
      DispTemp = (DispTemp * 1000) / 1000;
          /*if (DispTemp > 2047)
              DispTemp = 2047;
          else if (DispTemp<-2048)
        	  DispTemp = -2048;*/

	  AFMOut[i] = DispTemp ;

        if (AFMOut[i] > 4095)
            AFMOut[i] = 4095;

	  
   }  //  for (i=0; i<2; i++ )
   if ( (pr[AFMCALIB]&0x0002)==0 )   // AVO1 Calibration
		uwAFMda = AFMOut[0];
	else							 // AVO2 Calibration
		uwAFMda = AFMOut[1];

    APP01_uwSO1 = AFMOut[0];
    APP01_uwSO2 = AFMOut[1];
}

#endif

void AFM_Output(void)
{   
  UBYTE i;

  ULONG DispBase,AFM1_temp,AFM2_temp;
  SLONG DispTemp,DispValue;
  UWORD AFMCNT,HPSPEC_temp;

  for (i=0; i<2; i++ ){
    
        switch(pr[AFM1+(i*3)]){
            default:
            case 0:     // Output Frequency(Hz)
                DispValue = fcmd.uw.hi;
                DispBase = pr[FMAX];
                if (WGDIR==REVERSE)
                    DispValue = -DispValue;
                break;
            case 1:     // Frequency Command(Hz)
                DispValue = fkey.uw.hi;
                DispBase = pr[FMAX];
                if (CMDDIR==REVERSE)
                    DispValue = -DispValue;
                break;
            case 2:
        // Motor Speed(Hz)
                DispValue = SpDt_uwFfbk;
                DispBase = pr[FMAX];
                if (WGDIR==REVERSE)
                    DispValue = -DispValue;
                break;
            case 3:     // Output Current (rms)
                DispValue = IrmsRe;
                DispBase = (pr[I_RATE] * 5)>>1;
                break;
            case 4:     // Output Voltage
                DispValue = Vcmd_LL;
                DispBase = vbase * 2;
                break;
            case 5:     // DCbus Voltage
                DispValue = dcbusDC;
                if ((pr[HPSPEC]&VFD440V)==VFD220V)
                  DispBase = 4500;
                else
                  DispBase = 9000;
                break;
            case 6:     // Power Factor
                DispValue = TB1_uwPhi;
                DispBase = 1800;
                break;
            case 7:     // Power
                DispValue = (SWORD)(PowerIn>>16);
                DispBase = Power_S;
                break;
            case 8:     // Torque Output
                //DispValue = TorqueOut;    //6a16j
                DispValue = TqC_swTqCmd;    //6a16j display Torque display
                DispBase = COF_uwTbRe;
                break;
            case 9:     // AVI
                DispValue = swAVICalib;
        // [ Modify the scale of swAVICalib, DINO, 06/17/2009
                DispBase = 1000;  // Modify by dino, 04/02/2008
        // ]
                break;
            case 10:    // ACI
                DispValue = swACICalib;
        // [ Modify the scale of swACICalib, DINO, 06/17/2009
                DispBase = 1000;  // Modify by dino, 04/02/2008
        // ]
                break;
            case 11:    // AUI
                DispValue = swAUICalib;
        // [ Modify the scale of swAUICalib, DINO, 06/17/2009
                DispBase = 1000;  // Modify by dino, 04/02/2008
        // ]
                break;
            case 12:    // Iq Ref
                DispValue = CUR_swIqseRefPu;
                DispBase = 32768;
                break;
            case 13:    // Iq Fdb
                DispValue = CUR_swIqseFdbPu;
                DispBase = 32768;
                break;
            case 14:    // Id Ref
                DispValue = CUR_swIdseRefPu;
                DispBase = 32768;        
                break;
            case 15:    // Id Fdb
                DispValue = CUR_swIdseFdbPu;
                DispBase = 32768;        
                break;
            case 16:    // Vq Command
                DispValue = TeS_swUqseInPu;
                DispBase = 32768;        
                break;
            case 17:    // Vd Command
                DispValue = TeS_swUdseInPu;
                DispBase = 32768;        
                break;
            case 18:    // Torque Ref
                DispValue = SPR_swTqRefPu;
                DispBase = 4096;        
                break;
            case 19:    // PG Frequency
                DispValue = PG2_ulSpdCmdLPF.uw.hi;
                DispBase = pr[FMAX];
                if (PG2_slSpdCmd<0)
                    DispValue = -DispValue;
                break;
            case 20:    // Probe memory
                DispValue = pr[SHOW_DATA];
                if((pr[AFMCALIB]&0x0081)==0x0080)     // 10V
                    DispValue = 0x00007fff;
                else if((pr[AFMCALIB]&0x0081)==0x0081)  // -10V
                    DispValue = 0xffff8000;
                DispBase = 32768;
                break;
                
            case 21:    // Output Power                  //[Add output power selection, Bernie, 2016/06/08]
                if((Pinput.uw.hi&0x8000)==0){
                    DispValue = Pinput.uw.hi;
                }
                else{
                    DispValue = -(SWORD)(0xffff - Pinput.uw.hi + 1);
                }
                if(pr[HPSPEC]>VFD_SINGLEPHASE){
                    HPSPEC_temp = pr[HPSPEC] - VFD_SINGLEPHASE;
                    //DispBase = RatedPower[pr[HPSPEC]];
                    DispBase = RatedPower_SINGLE[HPSPEC_temp];
                }
                else{
                    HPSPEC_temp = pr[HPSPEC];
                    //DispBase = RatedPower[pr[HPSPEC]];
                    DispBase = RatedPower[HPSPEC_temp];
                }
                break;
        }
            
        switch (pr[AFM1_MINUS+(i*3)]){
            default:
            case 0:
                DispValue = abs(DispValue);
                if(i == 0){
                    //AFMCNT = pr[AFM1_0CNT];//1200; //0~10V
                    //AFM1_temp = pr[AFM1_P10CNT];   //0~10V
                    AFMCNT = pr[AFM1_0CNT]>>1;//1200;
                    AFM1_temp = pr[AFM1_P10CNT]>>1; 
                }
                else{
                    AFMCNT = pr[AFM2_0CNT]>>1;//1200;
                    AFM2_temp = pr[AFM2_P10CNT]>>1;
                }
                break;
            case 1:
                if (DispValue < 0){
                    DispValue = 0;
                    if(i == 0){
                        //AFMCNT = pr[AFM1_0CNT];//1200;   //0~10V
                        AFMCNT = pr[AFM1_0CNT]>>1;//1200;  //0~10V
                       
                    }
                    else{
                        AFMCNT = pr[AFM2_0CNT]>>1;//1200;
                       
                    }
                }
                else{
                    if(i == 0){
                        //AFMCNT = pr[AFM1_0CNT];//1200; //0~10V
                        //AFM1_temp = pr[AFM1_P10CNT];    //0~10V
                        AFMCNT = pr[AFM1_0CNT]>>1;//1200;
                        AFM1_temp = pr[AFM1_P10CNT]>>1;
                    }
                    else{
                        AFMCNT = pr[AFM2_0CNT]>>1;;//1200;
                        AFM2_temp = pr[AFM2_P10CNT]>>1;
                    }
                }
                break;        
            case 2:
                if(i == 0){
                    AFMCNT = pr[AFM1_0CNT]>>1;//1200;
                    AFM1_temp = pr[AFM1_P10CNT]>>1;
                    if (DispValue < 0)
                        AFM1_temp = pr[AFM1_M10CNT]>>1;
                    
                }
                else{
                    AFMCNT = pr[AFM2_0CNT]>>1;//1200;
                    AFM2_temp = pr[AFM2_P10CNT]>>1;
                    if (DispValue < 0)
                        AFM2_temp = pr[AFM2_M10CNT]>>1;    
                }
                break;                
        }

        if(i == 0){
            //AFM1_temp = pr[AFM1_CNT];
            DispTemp = S32xS32divS32(DispValue, AFM1_temp, DispBase);

			DispTemp = (DispTemp * pr[AFMGA1])/1000;//[add Gain function,Aevin,2018/06/20]
				
            if(DispTemp>AFMCNT)
                DispTemp = AFMCNT;
            
            GPT5.GTCCRE = AFMCNT - DispTemp;

        }
        else{
            //AFM2_temp = pr[AFM2_CNT];
            DispTemp = S32xS32divS32(DispValue, AFM2_temp, DispBase);

			DispTemp = (DispTemp * pr[AFMGA2])/1000;//[add Gain function,Aevin,2018/06/20]
			
            if(DispTemp>AFMCNT)
                DispTemp = AFMCNT;
            
            GPT6.GTCCRE = AFMCNT - DispTemp;
        }

  }

}

#if SH7149  // dino, 03/08/2007
void DFM_Calculate(void)
{
    ULONG dfm, fclk;
    UWORD set_reg,vx;
    
    if (fout.uw.hi > fmin){       
      dfm = ((ULONG)pr[DFM_G]*fout.uw.hi);
      if (dfm >= 32000){                                  //20MHz/32000=62500
        fclk = 2000000000;
          /*=== Timer Control Register (TCR3S) ===================================*/
            /* Bit[7-5]       001   :CCLR2~0,TCNT cleared by TGRA                   */
            /* Bit[4-3]       00    :CKEG1~0,Count at rising edge                   */
            /* Bit[2-0]       000   :TPSC2~0,Internal Clock:phi/1                   */
            set_reg = 0x20;
        }
        else if ((dfm >= 8000)&&(dfm<32000)){               //5MHz/8000=62500
          fclk = 500000000;
          /*=== Timer Control Register (TCR3S) ===================================*/
            /* Bit[7-5]       001   :CCLR2~0,TCNT cleared by TGRA                   */
            /* Bit[4-3]       00    :CKEG1~0,Count at rising edge                   */
            /* Bit[2-0]       001   :TPSC2~0,Internal Clock:phi/4                   */
            set_reg = 0x21;
        }
        else if ((dfm>=2000)&&(dfm<8000)){                  //1.25MHz/2000=62500
          fclk = 125000000;
          /*=== Timer Control Register (TCR3S) ===================================*/
            /* Bit[7-5]       001   :CCLR2~0,TCNT cleared by TGRA                   */
            /* Bit[4-3]       00    :CKEG1~0,Count at rising edge                   */
            /* Bit[2-0]       010   :TPSC2~0,Internal Clock:phi/16                  */
            set_reg = 0x22;
        }
        else if ((dfm>=500)&&(dfm<2000)){                  //312.5KHz/5=62500
          fclk = 31250000;
          /*=== Timer Control Register (TCR3S) ===================================*/
            /* Bit[7-5]       001   :CCLR2~0,TCNT cleared by TGRA                   */
            /* Bit[4-3]       00    :CKEG1~0,Count at rising edge                   */
            /* Bit[2-0]       011   :TPSC2~0,Internal Clock:phi/64                  */
            set_reg = 0x23;
        }
        else if ((dfm>=125)&&(dfm<500)){                    //78.125KHz/1.25=62500
          fclk = 7812500;
          /*=== Timer Control Register (TCR3S) ===================================*/
            /* Bit[7-5]       001   :CCLR2~0,TCNT cleared by TGRA                   */
            /* Bit[4-3]       00    :CKEG1~0,Count at rising edge                   */
            /* Bit[2-0]       100   :TPSC2~0,Internal Clock:phi/256                 */
            set_reg = 0x24;
        }
        else{                                               //19.53125KHz
          fclk = 1953125;
          /*=== Timer Control Register (TCR3S) ===================================*/
            /* Bit[7-5]       001   :CCLR2~0,TCNT cleared by TGRA                   */
            /* Bit[4-3]       00    :CKEG1~0,Count at rising edge                   */
            /* Bit[2-0]       101   :TPSC2~0,Internal Clock:phi/1024                */
            set_reg = 0x25;
        }
        
        vx = U32xU32divU32((fclk+(dfm>>1)),1,dfm)-1;
        
        if (reg_t2s3TCR!= set_reg){
            MTU2S.TSTR.BIT.CST3 = 0;      /* DFM Counter Start                    */
            reg_t2s3TCR = set_reg;
            MTU2S3.TCR.BYTE = set_reg;
        
            MTU2S3.TGRC = vx;
            MTU2S.TSTR.BIT.CST3 = 1;      /* DFM Counter Start                    */
        }
        else{
            MTU2S3.TGRC = vx;
            MTU2S.TSTR.BIT.CST3 = 1;      /* DFM Counter Start                    */
        } 
    }
    else{
        MTU2S.TSTR.BIT.CST3 = 0;          /* DFM Counter Start                    */
    }
}
#endif
/*------------- PID control Function ---------------------------------------
        P = Kp * E               E -- Kp ------ 1  ---|
        I = Kp/Ti * E                     |-- 1/Ti ---|---->
        D = Kp*Td * E                     |---- Td ---|
 ---------------------------------------------------------------------------*/
 
void PID_Fbk_Process(void)
{
    //------ Calculate pv value --------------------------------------------//
    if ((pr[PIDSL]==0)||(MFI_PIDDIS==1)){
        pv = 0;
    }
    else{
      switch(pr[PIDSL]){
          default:
      case 1:
        case 4:   // pv: Analog input
          if (pr[AUI1_SL]==5)
            pv = (SWORD)AVIslFunVar;
          else if (pr[ACI_SL]==5)
            pv = (SWORD)ACIslFunVar;
          else if (pr[AUI2_SL]==5)
            pv = (SWORD)AUIslFunVar;
          else
            pv = 0;
        break;
      case 2:
      case 5:   // pv: PG fbk without direction
          if (pr[PGINPUT]!=0)
          pv = abs(slMotorHz);        
          else
          pv = 0;
        break;
      case 3:
      case 6:   // pv: PG fbk with direction
          if (pr[PGINPUT]!=0)
          pv = slMotorHz;
          else
          pv = 0;
        break;
    }
    }         
}


void PID_Ctrl(void)
{
    SLONG px,qx,ax,bx;
    ULONG rx;

    if (KPDmax!=0){     //KPDmax is controlled by char 0 ~3 of pr[U_SET]
        // Select which chanel is feed back signal
        if (pr[PIDSL]<=3){    //Input Negative PID feedback
            piderr = S16xS16divS16((PIDsource - pv), pr[FMAX], KPDmax);
        }
        else if (pr[PIDSL]>=4){ //Input Positive PID feedback
            piderr = S16xS16divS16((pv - PIDsource), pr[FMAX], KPDmax);
        }
    }
    else{
        piderr = 0;
    }      

    // Proportional Gain,
    qx = (SLONG)piderr * (pr[PID_P] << 1);
    px = qx * 5;
    
    // Integral Time,
    if (pr[PID_I] != 0) {
        
        rx = ((ULONG)pr[PID_ILIMIT] * pr[FMAX]);
        
        ax = S16xS16divS16(piderr,pr[PID_P],pr[PID_I]);
        
        if ((ax == 0)&&(qx!=0)) {
            PIDinteg_rem = PIDinteg_rem + qx;
            bx = pr[PID_I];
            if (PIDinteg_rem >= bx){
                PIDinteg_rem = bx;
                ax = 1;
            }
            else if (PIDinteg_rem <= -bx){
                PIDinteg_rem = -bx;
                ax = -1;
            }
        }
        else
            PIDinteg_rem = 0;
                                
        PIDintegral = PIDintegral + ax;
        
        if (PIDintegral < 0)
            PIDintegral = 0;
        else if (PIDintegral > rx)
                PIDintegral = rx;
        
        px = px + PIDintegral;
    }
        
    // Derivative Time
    if (pr[PID_D] != 0)
        px = px + ((SLONG)(piderr-piderr_Z1) * pr[PID_P] * pr[PID_D] * 100);

    if (pr[PIDDLY]!=0)
        PIDoutf.ul = lowpass_sl(PID_LPG, px, PIDoutf.ul);
    else
        PIDoutf.ul = px;
               
    px = ((SLONG)PIDoutf.ul + PID_slofsetv);
    
    if ( px < 0)
        PIDFcmd = 0;
    else { 
        rx = ((SLONG)pr[PIDMAX] * pr[FMAX]);
        if (px > rx)
            px = rx;
        PIDFcmd = (px + 500)/1000;
    }
    
    piderr_Z1 = piderr;
}


/*------------- PID Feedback signal loss detection -------------------------*/
void PID_Loss(void)
{
    if ((CMDRUN==RUN)&&(pr[FB_DT]!=0)){
        if ((pr[PIDSL]==1)||(pr[PIDSL]==4)&&(MFI_PIDDIS==0)){ 
            if ((AD_uwACIad<=800)&&(pr[ACISEL]==0)&&(pr[ACI_SL]==5)){   // only for PID signal = 4-20mA
                if (TB1_uwPIDLossCnt>=pr[FB_DT]){
                    if (WARNPID==0) {
                        if (pr[FB_LOSS]==1){    // PID Feedback Loss = 0 warn and stop
                            stop();
                            Error = AFE_ERR;
                            WARNSTOPREC = 1;  //09/05/2007
                        }
                        else if (pr[FB_LOSS]==2){
                            //WGOFF;
//                            CMDRUN = STOP;
              LIFT_ENABLE = 0;            // Add by DINO, 03/28/2008
                TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
                            CMDFREE = 1;
                            Error = AFE_ERR;
                        }
                        else if (pr[FB_LOSS]==3){   // Warn and Keep at last Freq.
                            PIDHOLD = 1;
                        }
                        //Show PID loss warning message and save to fault history //
                        WARNPID = 1;          // set PID warning flag
                        WarnCode = PID_WARN;
                        Keypad_PageTmp = Keypad_Page;
                Keypad_Page = WarnPAGE;
                    }
                }
                else
                    TB1_uwPIDLossCnt ++;      //Count in 100ms
            }
            else {
                if (WARNPID!=0){
                    WARNPID = 0;
                    TB1_uwPIDLossCnt = 0;
                    WarnCode = 0;
                    Keypad_Page = Keypad_PageTmp;
                }
                PIDHOLD = 0;
            }
        }
    }
}


/*------------- PID Feedback signal loss detection -------------------------*/
void PID_Deviation(void)
{
    UWORD ax;

    if (RUNNING) {
        if ((pr[PIDSL]!=0)&&(MFI_PIDDIS==0)){    // PID signal = 4-20mA
            ax = piderr;
            if (ax < 0)
                ax = -ax;
            ax = ((ULONG)ax*1000)/pr[FMAX];

            if (ax>=pr[PID_DEV]){
                if (TB1_uwPIDDeviCnt>=pr[PIDDEVT])
                    PIDDEVF = 1;
                else
                    TB1_uwPIDDeviCnt ++;      //Count in 100ms
            }
            else {
                PIDDEVF = 0;
                TB1_uwPIDDeviCnt = 0;
            }
        }
    }
    else
        PIDDEVF = 0;
}

void PID_Sleep(void)
{
    if (pr[SLEEPF]!=0){
        if (PIDFcmd >= pr[WAKEF]){  // vfd wakeup
            TB1_uwSleepCnt = pr[SLEEPT];
            Fcmd = PIDFcmd;
        }
        else {
            if (fout.uw.hi<=pr[SLEEPF]){
                if (TB1_uwSleepCnt==0||fout.uw.hi==0){   // enter sleep mode
                    Fcmd = 0;
                }
                else{
                    if (TB_100ms2 == 1){
                        TB_100ms2 = 0;
                        TB1_uwSleepCnt--;
                    }
                }
            }
            else {  // fout.uw.hi>pr[FSLEEP]
                TB1_uwSleepCnt = pr[SLEEPT];
                if (PIDFcmd < pr[SLEEPF]){
                    if (pr[SLEEPF] < fmin){
                        Fcmd = 0;
                    }
                    else{
                        Fcmd = pr[SLEEPF];
                    }
                }
                else
                    Fcmd = PIDFcmd;
            }
        }
    }
    else
        Fcmd = PIDFcmd;
    
}
#if SH7149  // dino, 03/08/2007
void TB1_Scale_PG(void)
{
  if (PGScaleDataTmp!=PGScaleData){           
      if (PGScaleBit==0){
         PG_OEN = 0;
         PGScaleOut = (UWORD)(PGScaleData | 0x0200);
        }
        
        if (PGScaleBit<16){
            PG_SCLK = 0;        
            if ((PGScaleOut&0x8000)!=0)
                PG_DI = 1;
            else
                PG_DI = 0;        
                        
            PGScaleOut = (UWORD)(PGScaleOut << 1);
            PG_SCLK = 1;
        }
        PGScaleBit++;
        
        if (PGScaleBit==16){
            PG_LCLK = 0;
            PG_OEN = 1;
            PG_SCLK = 0;            
            PGScaleDataTmp = PGScaleData;            
        }                                         
    }
  else{
    if ((pr[DEBUG_F1]&0x0008)==0x0000){ // Bit 3: ICT Enable
          PG_LCLK = 1;
      PG_OEN = 0;
    }
    PGScaleBit = 0;
    }
}
#endif
void TB1_FOCPGSpdWait(void)
{
  SLONG slTemp;
  
    if (TB1_ubFOCPGSerCnt>=100){
    HOLD = 0;
  }
  else{
    TB1_ubFOCPGSerCnt++;
    if ((SLONG)TB1_slSpdCmdPu>=0)
      slTemp = TB1_slSpdCmdPu - SpDt_slSpdFdbPu;
    else
      slTemp = SpDt_slSpdFdbPu - TB1_slSpdCmdPu;
      
    slTemp = ((SLONG)(slTemp>>15)*COF_uwFbRe);
    if (slTemp>=0){
      if (fcmd.ul<=slTemp)
        fcmd.ul = 0;
      else
        fcmd.ul = (SLONG)fcmd.ul - slTemp;
    }
    else{
      if ((((SLONG)fcmd.ul-slTemp)>>1)>(pr[FMAX]<<15))
        fcmd.ul = pr[FMAX]<<16;
      else
        fcmd.ul = (SLONG)fcmd.ul - slTemp;
    }
    ftemp.ul = fcmd.ul; 
  }
}

void TB1_YDSwitchFun(void)
{
  UWORD uwTemp1, uwTemp2;
  
    if ((YCONNECTOK==1)&&(DCONNECTOK==1)){
        WGOFF;
        Error = ydc_ERR;
        WGOFF;
    }

    if (RUNNING==RUN){
      uwTemp1 = pr[YDSWRPM] + 200;
      uwTemp2 = pr[YDSWRPM] - 200;
        
    if ((fcmd.uw.hi>=uwTemp1)&&(Fcmd>=uwTemp1))
          YDConnectFlag = 1;  // Delta Connected
        else if ((fcmd.uw.hi<uwTemp2)&&(Fcmd<uwTemp2))
          YDConnectFlag = 0;  // Y Connected
        
        if (YDConnectFlag==1){
            //Delta-connected 
            MFO_DCON = 1;
            MFO_YCON = 0;
            if (DOnCNT<pr[YDDELAYT]){  // DonCnt be cleared on MFO_fun                
                if (YCONNECTOK==0)       
                    DOnCNT++;   // after Y-Connected be release, DOnCnt start count
                YDWGON = 0;                
                vcmd_ser = 0;
                VF_Vcmd = 0;                
                HOLD = 1;
        SPSEARCH = 1;
        if (DOnCNT==1){
          Motor2Pr();
          TQRBaseInit();
          TQRMaxInit();
          MotorPrInit();
          vtemp = GetFx2Vm(fcmd.uw.hi);
                    if (pr[CTRLM]==FOCPG)
                        Init_FOCPG();
        }
        else if (DOnCNT==2){
          VFPG_Init_SlipMax();
            set_Rs();    
            set_VcmpMax();
            TB1_VFCal_Slin();       
        }
            }
            else{
                if ((DCONNECTOK==1)&&(YDWGON==0)){
                    if (((pr[CTRLM]==VFPG)||(pr[CTRLM]==FOCPG))&&(pr[PGINPUT]!=0)){
                      SPSEARCH = 1;
                        PG_speed_search();
                    }                                                     
                    //HOLD = 0;
                    YDWGON = 1;
                }
        if (DCONNECTOK==0){
          if (DOnCNT<=(pr[YDDELAYT]+2000))
            DOnCNT++;
          else{
            WGOFF;
                Error = ydc_ERR;
                WGOFF;
          }
        }
        TB1_FOCPGSpdWait();
            }                
        }
        else if (YDConnectFlag==0){
            //Y-Connected
            MFO_DCON = 0;
            MFO_YCON = 1;
            if (YOnCNT<pr[YDDELAYT]){
                if (DCONNECTOK==0)
                    YOnCNT++;
                YDWGON = 0;
                vcmd_ser = 0;
                VF_Vcmd = 0;
                HOLD = 1;       
        SPSEARCH = 1;
        if (YOnCNT==1){
          Motor1Pr();
          TQRBaseInit();
          TQRMaxInit();
          MotorPrInit();    
          vtemp = GetFx2Vm(fcmd.uw.hi);     
                    if (pr[CTRLM]==FOCPG)
                        Init_FOCPG();
        }
        else if (YOnCNT==2){
          VFPG_Init_SlipMax();
            set_Rs();    
            set_VcmpMax();
            TB1_VFCal_Slin();
        }                         
            }
            else{
                if ((YCONNECTOK==1)&&(YDWGON==0)){
                    if (((pr[CTRLM]==VFPG)||(pr[CTRLM]==FOCPG))&&(pr[PGINPUT]!=0)){
                      SPSEARCH = 1;
                        PG_speed_search();
          }                                            
                    //HOLD = 0;
                    YDWGON = 1;                    
                }
        if (YCONNECTOK==0){
          if (YOnCNT<=(pr[YDDELAYT]+2000))
            YOnCNT++;
          else{
            WGOFF;
                Error = ydc_ERR;
                WGOFF;
          }
        }
        TB1_FOCPGSpdWait();
            }
        }
    }
}


void TimeBase_500us(void)
{
    UWORD uwTemp;
    ULONG	ulTmp;
	UDOUBLE	udTmp;


    // The PG Card Type Detact function move to Pr_Handle.c pr10-00 and main loop      //[Modify PG Type Define, Bernie, 12/05/2011]
    //GPT5.GTCCRE = 0x04B0;
    //GPT6.GTCCRE = 0x04B0;
    //GPTB.GTSTR.WORD = 0x06;  // GPT5 start count  
  
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    SIBO_STO_Safty();
#else
    TB3_STO_Safty(); //[Safty function, Bernie, 2013/10/29]
#endif
   
    if (((!STANDBY)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))&& STtune==0)|| pr[CTRLM]==FOCPM)
    {   
        // [Warning initial, Lyabryan, 2015/03/12]
        if ((pr[PROTBIT]&0x0040)==0x0000)
        {  
            //Bit 6: PGErr
            TB3_SpDtPG1_Err();
        }
    }
  
    if(((pr[DEBUG_PG]&0x0200)!=0x0200)&&(pr[PG_TYPE]==SIN_SIN))  //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
        PGDIR_Detect(); //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]

    if ((RUNNING)&&(!STANDBY)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))&& STtune==0 )
    {
        switch(pr[CTRLM])
        {
            case FOCPG:
            case TQCPG:
                TB3_SpDtPG1_LoIv();
                TB3_FOCPG();
                if ((pr[PROTBIT]&0x0040)==0x0000) //Bit 6: PGErr
                    TB3_SpDtPG1_Err();
            break;
            case VFPG:
                TB3_SpDtPG1_LoIv();
                if ((pr[PROTBIT]&0x0040)==0x0000) //Bit 6: PGErr
                    TB3_SpDtPG1_Err();
            break;
#if SCOTTY
            case FOCPM:               //ADDED BY SCOTTY
                TB3_SpDtPG1_LoIv();         //ADDED BY SCOTTY
                TB3_FOCPM();            //ADDED BY SCOTTY
                if ((pr[PROTBIT]&0x0040)==0x0000) //Bit 6: PGErr
                    TB3_SpDtPG1_Err();        
             break;              //ADDED BY SCOTTY
#endif      
            case SVC:
            case VF:                                
            case FOC:
            case DBCSECA:
            default:
                TB3_SpDtPG1_LoIv();
                if ((pr[PROTBIT]&0x0040)==0x0000)
                {
                    //Bit 6: PGErr
                    if (CTRLMCHG==1)
                        TB3_SpDtPG1_Err();
                }
                break;
        }
    }
    else
    {
        TB3_SpDtPG1_LoIv();   
    }

    TB3_AccFunction();

// -FAN CONTROL ----- added by scotty 10/15/20007
    if (FAN_ENABLE){
      if (pr[FAN_Dframe] == 1){  // Delete FAN Soft-Start Function, DINO, 06/01/2010
        TB1_uwFanCnt1++;
        if (TB1_uwFanCnt < 500 ){
          if ((TB1_uwFanCnt1&0x03) == 0x03){
            TB1_uwFanCnt++;
            //FAN_SWITCH = (pr[HPSPEC]<=VFD300V23A)?1:0;  // frame E fan control fix, Sean, 12/30/2010
            FAN_SWITCH = (pr[HPSPEC]<VFD300V23A ||pr[HPSPEC]==VFD300V43A ||pr[HPSPEC]==VFD022V21A ||pr[HPSPEC]==VFD037V21A)?1:0;  // 300V43A chg to frame D, Sean, 03/14/2011   //[Single phase input, Bernie, 01/19/2012]
          }
          else
            //FAN_SWITCH = (pr[HPSPEC]<=VFD300V23A)?0:1;  // frame E fan control fix, Sean, 12/30/2010
            FAN_SWITCH = (pr[HPSPEC]<VFD300V23A ||pr[HPSPEC]==VFD300V43A||pr[HPSPEC]==VFD022V21A ||pr[HPSPEC]==VFD037V21A)?0:1;  // 300V43A chg to frame D, Sean, 03/14/2011   //[Single phase input, Bernie, 01/19/2012]
        }
        else
          //FAN_SWITCH = (pr[HPSPEC]<=VFD300V23A)?0:1;  // frame E fan control fix, Sean, 12/30/2010
          FAN_SWITCH = (pr[HPSPEC]<VFD300V23A ||pr[HPSPEC]==VFD300V43A||pr[HPSPEC]==VFD022V21A ||pr[HPSPEC]==VFD037V21A)?0:1;  // 300V43A chg to frame D, Sean, 03/14/2011   //[Single phase input, Bernie, 01/19/2012]
      }
      else{
        //FAN_SWITCH = (pr[HPSPEC]<=VFD300V23A)?0:1;  // frame E fan control fix, Sean, 12/30/2010
        FAN_SWITCH = (pr[HPSPEC]<VFD300V23A ||pr[HPSPEC]==VFD300V43A||pr[HPSPEC]==VFD022V21A ||pr[HPSPEC]==VFD037V21A)?0:1;  // 300V43A chg to frame D, Sean, 03/14/2011   //[Single phase input, Bernie, 01/19/2012]
        TB1_uwFanCnt = 500;
      }
    }
    else{
      TB1_uwFanCnt = 0;
      TB1_uwFanCnt1 = 0;
      //FAN_SWITCH = (pr[HPSPEC]<=VFD300V23A)?1:0;  // frame E fan control fix, Sean, 12/30/2010
      FAN_SWITCH = (pr[HPSPEC]<VFD300V23A ||pr[HPSPEC]==VFD300V43A||pr[HPSPEC]==VFD022V21A ||pr[HPSPEC]==VFD037V21A)?1:0;  // 300V43A chg to frame D, Sean, 03/14/2011   //[Single phase input, Bernie, 01/19/2012]
    }
 // - END FAN CONTROL -----
   
    if (CMDRUN==RUN){
        uwTemp = dcbusDC;
        if (uwTemp>=uwMaxDcbus)
            uwMaxDcbus = uwTemp;
        else if (uwTemp<=uwMinDcbus)
            uwMinDcbus = uwTemp;
    }

    //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
    if(((pr[DEBUG_F2]&0x0001)==0x0001) && (SHOW_ALLPR) && (ICTDetectGBP))
    {
        //Special,Kung modfiy for ICT pull high GBP, 11/04/2022
        //PORT3.PDR.BIT.B1 = 1;
        GBP_ON = 1;
    }
    else
    {
        sw_brake();
    }

    TB_500us ^= 1;

	if(TB_500us == 1){
		TimeBase_1ms();
	}
	else{
		TimeBase_1msB();
		//DLC function, Henry, 2016/07/20 [
		DLC_uwPOWCnt=(DLC_uwPOWCnt<1000)?(DLC_uwPOWCnt+1):DLC_uwPOWCnt;
		//ulTmp = (SpDt_ulPG1Npulse>>2) * pr[FMAX];	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 source
		//COF_ulPls2MMgain = U32xU32divU32((pr[Lift_SPD]*COF_ubMPolePair), 655360000, ulTmp);	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 source
		udTmp = (UDOUBLE)SpDt_ulPG1Npulse * (UDOUBLE)pr[FMAX];	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 new
		COF_ulPls2MMgain = (ULONG)(((UDOUBLE)pr[Lift_SPD] * (UDOUBLE)COF_ubMPolePair * 2621440000 + (udTmp>>1)) / udTmp);	// Issue 277400 高速梯有拖尾速及平層不準的問題 // Mitong 20220902 new
			
		if(((pr[SOFC]==4)||(pr[SOFC]==5))&&(DLC_uwPOWCnt>=1000)){ //[Gfc DLC modify,Henry,2018/05/23]	
			if(DLC_uwInit == 0){			
				DLC_PrMgr(PR_INIT_RD);
				DLC_uwInit = 1;
			}
			
			pr[UNITSEL] = 3;
			DLC_Algorithm();
		
		//]
		}
		else{
			DLC_uwInit = 0;
		}
	}

}

void TimeBase_1ms(void)
{
    UWORD uwTemp, vcmdPu_tmp, uwIrmsAD, uwGffAD, GFFIn_LPG, uwStartSource;  
    SWORD ffd_swtmp;
    SLONG IsquarePu, f1;
    ULONG Vsquare, ulTemp;
    ULONG_UNION EleAng;
    UWORD uwIrms;  // 0~32767=>0~300% Rated current, add by dino, 08/21/2007
    UWORD uwI0DtLPu,uwCAN,uwCAN2;


  // [ Move from ReadAD() of 100us, Add by DINO, 03/06/2009
    SWORD sw_Itemp, swIAtemp, swICtemp;
    ULONG ul_Itemp1;

    /*--------- Calculate Isum from Iu, Iw ---------------------------
    --                                                              --
    -- Isum   = sqrt(2/3(Iu^2+IuIw+Iw^2))                           --
    --        = sqrt(2/3)*sqrt((Iu+Iw)^2-IuIw)  , Q11               --
    --                                                              --
    -- IrmsAD is 300%/Q12 rated peak current.                       --
    -- sw_Itemp is 250%/Q11 rated rms current.                      --
    -- Therefore:                                                   --
    -- IrmsAD = sw_Itemp / 300% * 250% * 2 * sqrt(2)  ,Q12          --
    --        = sqrt((Iu+Iw)^2-IuIw)*sqrt(2/3)/300*250*2*sqrt(2)    --
    --      = sqrt((Iu+Iw)^2-IuIw)*63190/32768                      --
    --                                                              --
    --                       250                                    --
    -- 63190  = sqrt(2/3) * ----- * 2 * sqrt(2) * 32768             --
    --                       300                                    --
    --                                                              --
    ----------------------------------------------------------------*/
    DINT();
    swIAtemp   = adc_swIAtemp;
    swICtemp   = adc_swICtemp;
    EINT();
    sw_Itemp   = swIAtemp + swICtemp; // dino, 03/29/2007
    ul_Itemp1  = (SLONG)sw_Itemp*sw_Itemp - (SLONG)swIAtemp*swICtemp ;  // Iu^2 + IuIw + Iw^2 = (Iu+Iw)^2 - IuIw
    sw_Itemp   = uw_Sqrt32c(ul_Itemp1);
    IrmsAD1    = ((SLONG)sw_Itemp * 63190) >> 15; // 3.34/sqrt(3) = 63190/32768 //2007/08/03  SCOTTY
    IrmsAD     = IrmsAD1;
  // ]
    TB1_uwNewIrmsAD = (ULONG)IrmsAD * 931 >> 10;  // New IED Irated is 110%, 1/1.1*1024=931, DINO, 09/06/2010
    if (TB1_uwRYCnt < Def_uwRYCnt)
    { 
        TB1_uwRYCnt++;
    }  // Add by DINO, 05/22/2008   

    if(TB1_uwPGQuality_1sec<1000)
    {
        TB1_uwPGQuality_1sec++;
    }


    if((RUNNING==RUN)&&(fcmd.uw.hi!=0))
    {

        if(SPR_uwPGDIRCnt>100)
        {
            if(PGABerr_LPF.sw.hi>0)
            {
               SPR_uwPGDIR = 1;
            }
            else
            {
               SPR_uwPGDIR = 0;
            }
        }
        else
        {
           SPR_uwPGDIRCnt++;
        }
    }
    else
    {
        SPR_uwPGDIRCnt = 0;
    }

    if(BTTx_ubTestCase==BTT_Testing)
    {
        BTTx_ulTestCount = BTTx_ulTestCount+1;
    }
    else
    {
        BTTx_ulTestCount = 0;
    }

    if(WarnCode == BTT2_WARN)
    {
        BTTx_ulClearbttnCount = BTTx_ulClearbttnCount+1;
    }
    else if(WarnCode == BTT3_WARN)
    {
        BTTx_ulClearbttnCount = BTTx_ulClearbttnCount+1;
    }
    else
    {
        BTTx_ulClearbttnCount = 0;
    }


  

    if (RUNNING == RUN)
    {
        TB1_uwSBKCnt = 0;
    }
    else
    {
        if ( TB1_uwSBKCnt < 750 )
        {
            TB1_uwSBKCnt++;
        }
    }

    mfi_status = (mfi_now^pr[MI_INV]);
    
   
    mfo_status = (mfo_now^pr[MO_INV]);

    if(mfi_status==0)
    {
        BTTx_btFWDREVReset = 0;
    }

    if(CC4KeyPad==1&&TB1_uw1secCnt<3000)
    {
        TB1_uw1secCnt++;
    }
    else{
        TB1_uw1secCnt = 0;
        if((CC4KeyPad == 1) && (prt_CCcnt==0)){
            CC4KeyPad = 0;
        }
    }
    // [ FanLock Treatment Selection, DINO, 04/27/2010
    uwTemp = pr[LV_OPTM];
    // bit0: LV Treatment
    if (uwTemp & 0x0001)
    {
        LVMOD = 1;    //Warning
    }
    else
    {
        LVMOD = 0;    //Error
    }
    // bit1: FanLock Treatment
    if (uwTemp & 0x0002)
    {
        FANLOCKMOD = 1; //Warning
    }
    else
    {
        FANLOCKMOD = 0; //Error
    }

    // [ Operation in Generation Direction if EPS
    if ((pr[EPS_OPTM] == 1) ||(pr[EPS_OPTM] == 2)||(pr[EPS_OPTM] == 3)||(pr[EPS_OPTM] == 4))
    {
        //[EPS autodetect dir,Lyabryan,2018/07/02] //[Modify EPS function, Bernie, 2012/11/27 ]
        GEN_EN = 1;   //AUTO
    }
    else
    {
        GEN_EN = 0;   //MANUAL
    }
    // ]
    
    if(!EPS){ //[EPS autodetect dir,Lyabryan,2018/07/02]
        EPS_NormalDetectCurrent();
    }
    //------ Calculate PGLOSS ( dino, 09/23/2008 )----------//
    //PGLadLPF.sl += (SLONG)( (SWORD)AN11 - PGLadLPF.sw.hi ) * 6554;  // 10ms (base 1ms)
    PGLadLPF.sl += (SLONG)( (SWORD)AN103 - PGLadLPF.sw.hi ) * 6554;  // 10ms (base 1ms)

    //------ Calculate TH1 and TH2 ( dino, 03/07/2007 )----------//
    //TH1adLPF.sl += (SLONG)( (SWORD)AN9 - TH1adLPF.sw.hi ) * 655;  // 100ms (base 1ms)
    //TH2adLPF.sl += (SLONG)( (SWORD)AN8 - TH2adLPF.sw.hi ) * 655;  // 100ms (base 1ms)
    TH1adLPF.sl += (SLONG)( (SWORD)AN03 - TH1adLPF.sw.hi ) * 655;  // 100ms (base 1ms)
    TH2adLPF.sl += (SLONG)( (SWORD)AN02 - TH2adLPF.sw.hi ) * 655;  // 100ms (base 1ms)
    //------ Analog GFF Low pass ( dino, 03/21/2007 )-----------//
    if ( STtune ){  // Dom't calculate GFF_AD when Standstill
      uwGffAD   = 0;
      GFFIn_LPG = 6554;  // 10ms
    }
    else {
    //uwGffAD   = AN4;
    uwGffAD   = AN100;
    GFFIn_LPG = 655;   // 100ms
    }
    GFFadLPF.sl += (SLONG)(uwGffAD-GFFadLPF.sw.hi)*GFFIn_LPG;

    //------ Analog Input Low pass ------------------------------//
// [ Modify the LPF function by DINO, 03/07/2009
/*
    AVIadLPF.sl = lowpass_sl(AUI1In_LPG,AD_uwAUI1ad,AVIadLPF.sl);   //AUI1
    ACIadLPF.sl = lowpass_sl(ACIIn_LPG,AD_uwACIad,ACIadLPF.sl);     //ACI
    AUIadLPF.sl = lowpass_sl(AUI2In_LPG,AD_uwAUI2ad,AUIadLPF.sl); //AUI2
    PTCInLPF.sl = lowpass_sl(PTCIn_LPG,PTCInValue,PTCInLPF.sl);   //PTC
*/
    AVIadLPF.sl += (SLONG)(AD_uwAUI1ad - AVIadLPF.sw.hi) * AUI1In_LPG;  //AUI1
    ACIadLPF.sl += (SLONG)(AD_uwACIad  - ACIadLPF.sw.hi) * ACIIn_LPG; //ACI
    AUIadLPF.sl += (SLONG)(AD_uwAUI2ad - AUIadLPF.sw.hi) * AUI2In_LPG;  //AUI2
    PTCInLPF.sl += (SLONG)(PTCInValue  - PTCInLPF.sw.hi) * PTCIn_LPG; //PTC
// ]

    //------ Display Low pass -----------------------------------//
// [ Modify the LPF function by DINO, 03/07/2009
/*
    slVcmdLLPF   = lowpass_sl(DisplayLPG, Vcmd_LL, slVcmdLLPF);
    slIrmsReLPF  = lowpass_sl(DisplayLPG, IrmsRe, slIrmsReLPF);
    slDcbusDCLPF = lowpass_sl(DisplayLPG, dcbusDC, slDcbusDCLPF);
*/
    VcmdLLPF.sl   += (SLONG)(Vcmd_LL - VcmdLLPF.sw.hi) * DisplayLPG;  //Vcmd_LL
    IrmsReLPF.sl  += (SLONG)(IrmsRe  - IrmsReLPF.sw.hi) * DisplayLPG; //Irms
    DcbusDCLPF.sl += (SLONG)(dcbusDC - DcbusDCLPF.sw.hi) * DisplayLPG;  //DCbus

    TqRefPuLPF.sl += (SLONG)(swTqRefPu - TqRefPuLPF.sw.hi) * LC01DisplayLPG;  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
// ]

  // [ Calculate Electrical angle, add by Sampo, 04/22/2009
    EleAng.ul   = SpDt_ulThetaR;
    EleAng.ul   = (ULONG)EleAng.uw.hi * 3600;
    uwElecAngle = EleAng.uw.hi;
  // ]

// [ Modify the LPF function by DINO, 03/07/2009
//    ulDcbusReLPF.ul = lowpass_ul(dcbusLPG, dcbusDC, ulDcbusReLPF.ul); //SCOTTY 09/05/2007
    PHLbusReLPF.sl += (SLONG)(dcbusDC - PHLbusReLPF.sw.hi) * dcbusLPG;  //DCbus for PHL detection
// ]

    if (RESTART){
        Restart_Prog();
    }
    else if ((SPSEARCH)&&(RUNDCI==0)){
        Speed_Search();
    }
 
    if((pr[SysControl]&0x0800)==0x0800){
        if(MODE2 &&((fcmd.uw.hi==0)/*||(IrmsRe==0)*/) ){    //[DIN time sequence, Bernie, 2013/03/07]
            MODE3 = 1;   
        }
    }
    else{
        MODE3 = 0;
    }

    /*================ Run Command ==============================================================*/
    if (LIFT_ENABLE && (MODE3==0)){
        if (CMDRUN == RUN){
            if ((Error==0)||(Error==DEB_ERR)){
                // [ Short_Circuit Detection, DINO, 05/19/2010
                if (BEFORERUN == 1){
                }
                // ]
                // [ MPHL Detection, Added by Sampo, 05/12/2009 
                else if ( MPHL_DET && pr[HPSPEC]!=VFD022V23A ){  // 220V23A MPHL detect bypass, Sean,03/14/2011  //[Ocd Error occurred when BeforeRun, Lyabryan, 2015/01/05]
                    MPHL_Detect();
                }
                // ]
                else{
                    
                    TB1_uw0p5secCnt = 0;
                    TB_500ms = 0;
                    Run_Execute();
                }
            }
        }
    }// end of RUN status
    /*================ STOP Command =============================================================*/
    else {                      // STOP function
        Stop_Execute();
    }// end of STOP function
    /*============End of STOP command ===========================================================*/

    // [ Add Zero Speed Gain of Landing, DINO, 08/02/2010
    if (RUNNING == RUN)
    {
        // [ Add condition, DINO, 08/25/2010
        if (RUNDCI)
        {
            ZEROSTOP = 0;
        }
        else if (STOPDCI)
        {
            ZEROSTOP = 1;
        }
        else
        {
            // ]
            if (Fcmd > TB1_uwFcmdOld)
            {
                ZEROSTOP = 0;
            }
            else if (Fcmd < TB1_uwFcmdOld)
            {
                ZEROSTOP = 1;
            }
        }
    }
    else
    {
        ZEROSTOP = 0;
    }
    TB1_uwFcmdOld = Fcmd;
  // ]
    if(IODLC_holdCNT == 1)
    { 
        // [IODLC, Lyabryan, 2016/11/11]
        IODLC_uwPR_Th_CNT++;
    }


    if (((pr[CTRLM]==FOCPG) || (pr[CTRLM]==FOCPM))&&(pr[OVER_ACC_LEVEL]!=0))
    {

        if(pr[OVER_ACC_SET]==0)
        {
            OverAccFunction();

        }
        else{                 //pr[OVER_ACC_SET] = 1;
            if((pr[OVER_ACC_SET]==1)&&(CMDRUN==RUN)){
                OverAccFunction();
            }
            else{
                OverAccInit();
            }
        }
        
    }

    if ((RUNNING)&&(!STANDBY)&&((Error==0)||((Error!=0)&&(WARNSTOPREC==1)))&& BEFORERUN==0){
            if ((pr[AUTO_T]!=0)||(pr[CTRLM]>2)||(pr[PM_AUTO_T]!=0)){
                ulTemp = fcmd.ul;
            }
            else{
              if (fhunt.sl<0){
                if (fcmd_vf.ul<abs(fhunt.sl))
                  ulTemp = 0;
                else
                  ulTemp = fcmd_vf.ul + fhunt.sl;
              }
              else
                ulTemp = fcmd_vf.ul + fhunt.sl;
                    
            }

            if (ulTemp>0xFFDC0000)
                ulTemp = 0xFFDC0000;

            //Calculate acc command                 //01252007  
            ffd_swtmp = (SWORD)(Fcmd - fcmd.uw.hi);             // Feedforward bug
            if (abs(ffd_swtmp)<1){
              TB1_slSpdAcc = 0;
            }
            else {
              TB1_slSpdAcc = (SLONG)(fcmd.ul - TB1_ulSpdtempPu.ul); // Feedforward compensation SCOTTY 01/04/2007                       
            }     
            TB1_ulSpdtempPu.ul = fcmd.ul;               // Feedforward compensation SCOTTY 01/04/2007
              
            if (WGDIR==FORWARD){
                //Calculate TB1_slSpdCmdPu = (Double unsigned long)fcmd.ul * 4 / pr[FB]; in Q31
                f1 = U32xU32divU32(ulTemp,0x8000,COF_uwFbRe);
            }
            else{
                //Calculate TB1_slSpdCmdPu = (Double unsigned long)fcmd.ul * 4 / pr[FB]; in Q31
                f1 = 0 - U32xU32divU32(ulTemp,0x8000,COF_uwFbRe);
                TB1_slSpdAcc = 0 - TB1_slSpdAcc;      //ADDED BY SCOTTY 02/05/2007
            }

        // [ Change CHGDIR Function, DINO, 08/02/2010
            if (pr[CHG_DIR] == 0){
                  TB1_slSpdCmdPu = f1;
            }
            else{
                  TB1_slSpdCmdPu = -f1;
                  TB1_slSpdAcc   = -TB1_slSpdAcc;
            }
        // ]

        TB1_CmdRpm.ul = ulTemp;

            
            uwTemp = pr[AUTO_T] + pr[PM_AUTO_T];        // ADDED by SCOTTY, 09/04/2007
        if((uwTemp==0)||(TUN_ROLLING==1)||(TUN_POS_DC_OK==1)||(MPHL_DET==1)){  // modify by SCOTTY, 09/04/2007

            //Vcmd_LL = sqrt(Ud^2+Uq^2)/32767 * Vb * sqrt(3/2) (L-L RMS)
            //        = sqrt(Ud^2+Uq^2)/32767 * (pr[VMAX]*sqrt(2/3)) * sqrt(3/2)
            //        = sqrt(Ud^2+Uq^2)/32767 * pr[VMAX]
            //sqrt(3/2)*2^15=40132,Q15
            if ((pr[CTRLM]==FOCPG) || (pr[CTRLM]==TQCPG)){
                vcmdPu_tmp = FLX_swVoutPu;
            }
            else{
                Vsquare = ((SLONG)TeS_swUdseInPu*TeS_swUdseInPu) + ((SLONG)TeS_swUqseInPu*TeS_swUqseInPu);    
                if (Vsquare >= 0x3FFFFFFF)
                    Vsquare = 0x3FFFFFFF;

                vcmdPu_tmp = uw_Sqrt32c(Vsquare); //Q15
            }

            // [ Add Voltage Limit, DINO, 08/20/2009
            if (vcmdPu_tmp > FLX_swVsMaxPu){
                vcmdPu_tmp = FLX_swVsMaxPu;
            }
            // ]

            vcmdPu_tmp = ((ULONG)vcmdPu_tmp * COF_uwVbRe + 32768)>>15; //Q0=Q(15-15)
            Vcmd_LL = ((ULONG)vcmdPu_tmp * 40132)>>15; //Q0=Q(0+15-15)

              // [ Calculate Irms by Ia & Ic when MPHL Detection, Modify by Sampo, 05/06/2009 
            if (pr[CTRLM]>=2 && MPHL_DET==0){
            // ]
            // Is = sqrt(Ids^2+Iqs^2)/sqrt(2)
                IsquarePu = ((SLONG)TsE_swIdseOutPu*TsE_swIdseOutPu + (SLONG)TsE_swIqseOutPu*TsE_swIqseOutPu);
                Ismax_uwPu = uw_Sqrt32c(IsquarePu); //Q15
                uwIrms = (ULONG)Ismax_uwPu * 5 / 6; // Ismax_uwPu:0~32767=>0~250%, uwIrms:0~32767=>0~300%, add by dino, 08/21/2007
            //            Is_uwPu = ((ULONG)Ismax_uwPu * 46341)>>16;  //46341 = 1/sqrt(2) * 2^16
                if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                    IrmsRe = U32xU16shlr16(((ULONG)Ismax_uwPu*5),CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE]);  //where 5 = 2.5 << 1, Modify by dino, 08/21/2007
                else
                    IrmsRe = U32xU16shlr16(((ULONG)Ismax_uwPu*5),CTispec[pr[HPSPEC]]);  //where 5 = 2.5 << 1, Modify by dino, 08/21/2007
            }
            else{
                //I1 =  Iu*(Iu+Iw)+Iw*Iw ;      
                //Ismax = sqrt32a(I1);
                IsquarePu = (SLONG)AD_swIAPu*(AD_swIAPu+AD_swICPu)+(SLONG)AD_swICPu*AD_swICPu;  //Q30
                Ismax_uwPu = uw_Sqrt32c(IsquarePu); //Q15
                uwIrms = IrmsAD << 3; // add by dino, 08/21/2007
                uwIrmsAD = IrmsAD>>2; // add by dino, 03/06/2007
                if (abs(uwIrmsAD-IrmsADOld)>5){
                    if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                        IrmsRe = ((ULONG)uwIrmsAD * CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE] * 3)>>10;  // Modify by dino, 08/21/2007
                    else
                        IrmsRe = ((ULONG)uwIrmsAD * CTispec[pr[HPSPEC]] * 3)>>10;  // Modify by dino, 08/21/2007
                  IrmsADOld = uwIrmsAD;
                }
            }
            uwIrms = (ULONG)uwIrms *931 >>10;  //New ED Irated is 110%,1/1.1*1024=931  //[OL follow 1.1 ctispec, Bernie,10/11/2011]
            prt_OLIrms.ul = lowpass_ul(4096, uwIrms, prt_OLIrms.ul);  // For OL calculate, Move by dino, 08/21/2007           
        }
        else{
            if (TUN_Method==DC_TEST){
                Vcmd_LL = ((ULONG)TUN_swUoutPu * COF_uwVbRe + 16384)>>15;
            }
            else if (TUN_Method==HFSS_TEST){
                Vcmd_LL = ((ULONG)(TUN_slUdIntPu>>1) * COF_uwVbRe + 16384)>>15;
            }

        //    IrmsRe = ((ULONG)IrmsAD * CTispec[pr[HPSPEC]] * 3)>>10;  // Modify by dino, 08/21/2007 
            if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                IrmsRe = ((ULONG)IrmsAD * CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE] * 3)>>12;  // Modify by SCOTTY, 09/27/2007  
            else
                IrmsRe = ((ULONG)IrmsAD * CTispec[pr[HPSPEC]] * 3)>>12;  // Modify by SCOTTY, 09/27/2007  
            WarnDisplaySave();
            WarnCode = tUn_WARN;
        }
            //========= Power Factor ===============================================//
            //                               P                   P                       P                                                                               //
            // cos(TB1_uwPhi) = --- = ------------- = ------------                                                                   //
            //                               S       sqrt(P^2+Q^2)     3*Umax*Imax                                                                   //
            // where P = I^2 * R                                                                                                                                 //
            //=================================================================//
    //        if ((pr[CTRLM] == FOCPG) || (pr[CTRLM] == TQCPG)){    //SCOTTY 09/05/2007
        if ((pr[CTRLM] == FOCPG) || (pr[CTRLM] == TQCPG)||(pr[CTRLM] == FOCPM) ){
        //------ Pin = (3/2)*(Ide*Ude + Iqe*Uqe),In Q28                         //
            f1 = (((SLONG)TeS_swUqseInPu*CUR_swIqseRefPu)+((SLONG)TeS_swUdseInPu*CUR_swIdseRefPu))>>2;
            PowerIn = ((SLONG)f1 *3)>>1;
            slPowerInLPF = LowPass(1000, PowerIn, slPowerInLPF);

            //------ Qin = (3/2)*(Ide*Uqe - Iqe*Ude),In Q30                         //
            f1 = ((SLONG)TeS_swUqseInPu*CUR_swIdseRefPu)-((SLONG)TeS_swUdseInPu*CUR_swIqseRefPu);
            QowerIn = ((SLONG)f1 * 3) >> 1;
        }
        else{
            //------ Pin = (3/2)*(Ide*Ude + Iqe*Uqe),In Q28                         //
            f1 = (((SLONG)CUR_swUqseOutPu*TsE_swIqseOutPu)+((SLONG)CUR_swUdseOutPu*TsE_swIdseOutPu))>>2;
            PowerIn = ((SLONG)f1 *3)>>1;

            slPowerInLPF = LowPass(1000, PowerIn, slPowerInLPF);
            //------ Qin = (3/2)*(Ide*Uqe - Iqe*Ude),In Q30                         //
            f1 = ((SLONG)CUR_swUqseOutPu*TsE_swIdseOutPu)-((SLONG)CUR_swUdseOutPu*TsE_swIqseOutPu);
            QowerIn = ((SLONG)f1 * 3) >> 1;
        }

        //----------------------------------------------------------------------//                
            
        //----------------------------------------------------------------------//
        Power_S = uw_Sqrt32c((SLONG)(PowerIn>>13)*(PowerIn>>13)+(SLONG)(QowerIn>>15)*(QowerIn>>15));    //Q15

        TB1_swCosphi = S32xS32divS32(PowerIn, 2, Power_S); //Q14
            //=======================================================//
            // TB1_swCosphi => 16384 => 90 degree                                                                        //
            // arccos()     => 125 => 90 degree                                                                                 //
            // arccos() * 6 => 125 * 6 = 750 => 90degree                                                                 //
            //=======================================================//
    // [ Modify the LPF function by DINO, 03/07/2009
    //    cosphiLPF.sl = lowpass_sl(cosphi_uwLPG, TB1_swCosphi, (SLONG)cosphiLPF.sl);
        cosphiLPF.sl += (SLONG)(TB1_swCosphi - cosphiLPF.sw.hi) * cosphi_uwLPG; //PF
    // ]
        TB1_uwPhi = arccos(cosphiLPF.sw.hi) * 6;        
            // PF_ANGLE = TB1_uwPhi * 900 / 750; 
            // where 900/750 = 1.2, 1.2 in Q16 = 78643    
        PF_ANGLE =  ((ULONG)TB1_uwPhi * 78643)>>16;                
                
          // [ Calculate MPHL Detected Output Voltage, Add by Sampo, 05/12/2009
            if ( MPHL_DET ){

                VFTB1_swUoutPu = U16xU16divU16(VF_Vcmd , 26755, COF_uwVbRe);    //26754 = sqrt(2/3) * 32767 

                if ((UWORD)VFTB1_swUoutPu >= COF_uwVratePu){
                    VFTB1_swUoutPu = COF_uwVratePu;
                }

                if ( EPS ){
                    if ((UWORD)VFTB1_swUoutPu >= COF_uwVEPSPu){
                        VFTB1_swUoutPu = COF_uwVEPSPu;
                    }
                }

                VF_swUout = VFTB1_swUoutPu;

            }
        // ]
        else if ( pr[AUTO_T]==0 && STtune==0 && pr[PM_AUTO_T]==0){
            switch(pr[CTRLM]){  
                default:
                case VF:
                case VFPG:
                case SVC:
                    TB1_VF();
                break;
                case FOC:
                    TB1_FOC();
                break;
                case FOCPG:
                case TQCPG:
                    TB1_FOCPG();
                break;
                case DBCSECA:
                break;
                case FOCPM:       //ADDED BY SCOTTY 01/29/2007
                    TB1_FOCPM();    //ADDED BY SCOTTY 01/29/2007
                break;        //ADDED BY SCOTTY 01/29/2007
            }
        }
        else{
            switch(pr[AUTO_T]){
                case 1:
                    if (TUN_ROTARY_OK==1){
                        TUN_NLRotary_OK();
                    } 
                break;
                case 2:
                break;
                case 3:
                    if (TUN_LFSL==1){
                        TB1_CurrentReg();
                        TUN_LFSLTB1();
                    } 
                break;
                case 10:
                break;
                default:
                break;    
            }

            switch(pr[PM_AUTO_T]){
                case 1:       //ADDED BY dino, 05/29/2007
                break;
                case 2:       //ADDED BY scotty 2006/09/04
                break;
                case 3:       //ADDED BY dino, 08/13/2008
                    if ( TUN_SS==0 )
                        TB1_FOCPM();
                break;
                default:
                break;    
            }
        }
    }

// [ ADDED BY DINO 01/09/2008 
    //if ((Error != 0) && (((pr[STO_LOCK] & 0x0004)== 0x0000)||((Error != STOL_ERR) && (Error != STOL1_ERR) && (Error != STOL2_ERR) && (Error != STOL3_ERR)))) 
    if(Error)
    {
        uwStartSource = 0;
    }
    else
    {
		//#12225,MC is independent of STO, James for 04-49=4~7, 2021/11/26
        if ((pr[SOOC]==2) || PUEN2 || CMDJOG)
        {
            uwStartSource = LIFT_ENABLE;
        }
        else if((pr[STO_LOCK] & 0x0004)== 0x0004)//04-49=4~7
        {
        	if(pr[SOFC]==4)//CANBus Cmd
            { 
        		uwStartSource = (DLC_PDO_RX_DI.uw & 0x0006)?1:0;
        	}
            else//MI Cmd
            {
                uwStartSource = (mfi_status & 0x0003)?1:0;
            }
        }
        else
        {
			if ( pr[SEQMOD]==0 )
            {         
				uwStartSource = LIFT_RUNCMD;
			}
            else
            {
                uwStartSource = LIFT_ENABLE;
            }
        }
    }

    if((uwStartSource == 1) && (STAR_CONTACTOR==1) && TB1_uwStarConRunCnt<=pr[SCDELAY_RUN]){
        STAR_OUTPUT = 1;                                        //[Star contactor function, Bernie, 2017/03/22]
        if (TB1_uwStarConRunCnt <= pr[SCDELAY_RUN]){
            TB1_uwStarConRunCnt ++;                             //[Star contactor function, Bernie, 2017/03/22]
        }  
    }
    else{
        if (uwStartSource == 1){
            MOTORCONNECTOR = 1;
            // [ Clear uwStartSource, DINO, 08/24/2009
            TB1_uwMCStopCnt = 0;
            TB1_uwStarConStopCnt = 0;
            // ]
            if (TB1_uwMCRunCnt <= pr[MCDELAY_RUN]){
                TB1_uwMCRunCnt ++;
            }
            else{
                if (LIFT_ENABLE==1){
                    if (RUN_GOING==0){
                        CMDRUN = RUN;
                        RUNNING = RUN;
                        RUN_GOING = 1;
                    }
                }
            }
        }
    }
  if(RUN_DETECT == RUN){            //[Russia time srequence for IM, Bernie, 2015/07/13]
      MOTORCONNECTOR2 = 1;
  }

  if (TB1_uwMCRunCnt>=0 && uwStartSource==0 && RUNNING==STOP){
      TB1_uwMCStopCnt++;
      if (TB1_uwMCStopCnt >= pr[MCDELAY_STOP]){   
          TB1_uwMCRunCnt  = 0;
          TB1_uwMCStopCnt = 0; 
          MOTORCONNECTOR  = 0;
          MOTORCONNECTOR2 = 0;          //[Russia time srequence for IM, Bernie, 2015/07/13]
      }
  }
  if((uwStartSource == 0) && (STAR_CONTACTOR==1) && (MOTORCONNECTOR ==0)&&(TB1_uwStarConRunCnt>0)){
      if (TB1_uwStarConStopCnt <= pr[SCDELAY_STOP]){                                      //[Star contactor function, Bernie, 2017/03/22]
          TB1_uwStarConStopCnt ++;
      }  
      else{
         STAR_OUTPUT = 0;               //[Star contactor function, Bernie, 2017/03/22]
         TB1_uwStarConStopCnt = 0;
         TB1_uwStarConRunCnt = 0;
      }
  }
  
//END--01/09/2008 ]

    sw_protect();
    CHK_DI_State();
    ef_check();
   
    //if (Com_WatchDog4<250)//[For IED PG-Card, Sampo, 01/11/2010]
       //Com_WatchDog4++;
    if (Com_WatchDog0<250)//[For IED PG-Card, Sampo, 01/11/2010]
       Com_WatchDog0++;
    //  [ kb(onboard)pin test, Sean, 08/09/2010

  if ((pr[DEBUG_F1]&0x0008) == 0x0008){ // Bit 3: Enable all ICT test
    if ((pr[DEBUG_F1]&0x0010)==0x0010){ // Bit 4: for ICT test
      LEDDI   = 0;  //TP37
      LEDLCH  = 1;  //TP41
      LEDCLK  = 1;  //TP38
      KEYCLK  = 0;  //TP40  
    }
    else if ((pr[DEBUG_F1]&0x0010)==0x0000){// Bit 4: for ICT test
      LEDDI   = 1;  //TP37
      LEDLCH  = 0;  //TP41
      LEDCLK  = 0;  //TP38
      KEYCLK  = 1;  //TP40      
    }
    else{
      LEDDI   = 0;  //TP37
      LEDLCH  = 0;  //TP41
      LEDCLK  = 0;  //TP38
      KEYCLK  = 0;  //TP40        
    }
  }
  else{
    // [ LED KEYPAD Out, DINO, 03/09/2010
    TB_2ms ^= 1;
    if ( TB_2ms ){
       // PORTE.PODR.BIT.B4 ^= 1;
      LED_OUT();
    }
    // ]
  }
  //  ] kb(onboard)pin test, Sean, 08/09/2010

//    bb_check(); //disable bb  SCOTTY  08/31/2007
    AFM_Output();
    //AFM_Output_GFC();            //[APP01 IO carde support, Bernie, 2013/03/20]
//#if SH7149  // dino, 03/08/2007
 //   TB1_Scale_PG();
//#endif
    if ((pr[YDSWEN]==1)&&(pr[AUTO_T]==0)&&((YDSetBit&0x33)==0x33)&&(EXT_EF==0)){
        TB1_YDSwitchFun();
    }
    else{
        YDWGON = 1;
    }
  
  //-------- Position Control ------------------------------------------------//  
    //if ((RUNNING==RUN)&&(pr[CTRLM]==FOCPG)){
    if (RUNNING==RUN){
      // [ 15-21 bit5=1, disable PHL detection, DINO, 08/15/2009
      if ((pr[CTRLSEL]&0x0020) == 0){ //CTRLSEL bit5 = 1
        PROTECT_PHL();    //SCOTTY 09/05/2007
      }
      // ]
      
    TB1_PositionControl();
    
    if (MFI_APRbyVcom==1){
      ulTemp = Pfdec.ul;
            if (ulTemp==0){
              VcomFmax.uw.hi = pr[FMAX];
                VcomFmax.uw.low = 0;
            }
            else{
        if (VcomFmax.uw.hi>pr[VCOMFT]){
          if (VcomFmax.ul<ulTemp)
                  VcomFmax.ul = 0;
                else
            VcomFmax.ul = VcomFmax.ul - ulTemp;
        }
        else if (VcomFmax.uw.hi<=pr[VCOMFT]){
          VcomFmax.ul = pr[VCOMFT]<<16;
          VPHOLD = 0;
        }  
            }
    }
    else{
      if (Pfdec.ul==0)
        ulTemp = 65535;
      else
        ulTemp = Pfdec.ul;
        
            if (((VcomFmax.ul + ulTemp)>>16)>=pr[FMAX]){
              VcomFmax.uw.hi = pr[FMAX];
                VcomFmax.uw.low = 0;
                VPHOLD = 0;
            }
            else{
        if (VcomFmax.uw.hi<pr[FMAX]){
          VcomFmax.ul = VcomFmax.ul + ulTemp;
        }
        else if (VcomFmax.uw.hi==pr[FMAX]){
          VPHOLD = 0;
        }
            }
    }
  }

  // [ Flux Confirm, Add by DINO, 06/29/2009
  if (pr[CTRLM] == FOCPG){
    uwI0DtLPu = COF_uwI0DtLPu;  // Iflux = Pr.05_05 * 70%
  }
  else{
    uwI0DtLPu = 0;        // Iflux = 0
  }
    
  /*-------------------------------------------
  --  I0CHK = 0: Confirm not okay => Lock
  --        = 1: Confirm okay     => Release
  -------------------------------------------*/
  uwTemp = pr[AUTO_T] + pr[PM_AUTO_T];

  if (pr[BRK_CHKTQR]==0 || uwTemp!=0 || BRK_RLS==1){
    I0CHK = 1;
  }
  else {  // pr[BRK_CHKTQR]==1, Torque Prove Enable
    if (IrmsRe >= uwIsDtL){
      if (CUR_swIdseFdbPu >= uwI0DtLPu){
        I0CHK = 1;
      }
      else{
        I0CHK = 0;
      }
    }
    else{
      I0CHK = 0;
    }
  }
  // ]

  // [ Waiting for absoulte signal ready (Move from run()), DINO, 12/23/2009
  // [ Wait for EnDat ready, DINO, 08/24/2009
  if (pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER || pr[PG_TYPE]==SIN_SIN){  // Add SIN_SIN Mode, DINO, 11/30/2009
    if (EDT_READY == 1){
      PGREADY = 1;
    }
    else{
      PGREADY = 0;
    }
  }
  else{
    PGREADY = 1;
  }
  // ]
  // ]
  if(WRITE_Z_1387 == 1)  // [IED 1387 static Tune, 2011/07/06]
      uwSt1387cnt++;
  else
      uwSt1387cnt = 0;

  //==========================================================================//    
	if (pr[ZCAB_MODE]==0){	//[Z cab mode, Jerry Yu, 2019/06/05]
	
		// [ Dynamic Z-pulse calibrate, Add by DINO, 08/11/2010
		if (RUNNING == RUN){
			if (zcal_swThetaErr != 0){
				uwTemp = (SpDt_uwAnglePeriod + 512) >> 15;	// Npulse divided to 512
				if (uwTemp == 0){
					uwTemp = 1;
				}

				vcmdPu_tmp = MTU1.TCNT;
				zcal_uwPulseDiff += uwTemp;
				
				if (zcal_uwPulseDiff > zcal_uwPulseErr){
					uwTemp = zcal_uwPulseErr - (zcal_uwPulseDiff - uwTemp);
					zcal_swThetaErr = 0;
					zcal_uwPulseErr = 0;
				}

				if (PGDIR==1){
					if (zcal_swThetaErr>=0){
						uwTemp = vcmdPu_tmp - uwTemp;
					}
					else{
						uwTemp = vcmdPu_tmp + uwTemp;
					}
				}
				else{
					if(zcal_swThetaErr>=0){
						uwTemp = vcmdPu_tmp + uwTemp;
					}
					else{
						uwTemp = vcmdPu_tmp - uwTemp;
					}
				}
				
				MTU1.TCNT = uwTemp;
			}
		}
		// ]
	}
    /* ------ LED 7-segment Display & keyin function ------ */
    TB1_ub1msCnt ++;

    if(TB1_ub1msCnt==10) {
      /* ------ 10ms timer ------*/      
        TB1_ub1msCnt = 0;
        ErrorAutoReset();       //[Add auto restart after fault, Bernie, 06/06/12]

        TB_20ms ^= 1; // Add by dino, 04/12/2007
        
        if ( TB_20ms ){

            if (pr[ZCAB_MODE]==1){	//[Z cab mode, Jerry Yu, 2019/06/05]

            // [ Dynamic Z-pulse calibrate, Add by DINO, 08/11/2010
                if (RUNNING == RUN){
                    if (zcal_swThetaErr != 0){

                        uwTemp = (SpDt_uwAnglePeriod + 512) >> 10;  // Npulse divided to 512
                        if (uwTemp == 0){ uwTemp = 1; }
                        //vcmdPu_tmp = MTU21.TCNT;
                        vcmdPu_tmp = MTU1.TCNT;

                        zcal_uwPulseDiff += uwTemp;
                        if (zcal_uwPulseDiff > zcal_uwPulseErr){
                            uwTemp = zcal_uwPulseErr - (zcal_uwPulseDiff - uwTemp);
                            zcal_swThetaErr = 0;
                            zcal_uwPulseErr = 0;
                        }

                        if (PGDIR==1){
                            if (zcal_swThetaErr>=0)
                                uwTemp = vcmdPu_tmp - uwTemp;
                            else
                                uwTemp = vcmdPu_tmp + uwTemp;
                        }
                        else{
                            if(zcal_swThetaErr>=0) 
                                uwTemp = vcmdPu_tmp + uwTemp;
                            else
                                uwTemp = vcmdPu_tmp - uwTemp;
                        }

                        //MTU21.TCNT = uwTemp;
                        MTU1.TCNT = uwTemp;
                    }
                }
            // ]
            }
            /* ------ 20ms timer ------*/
      SWDetectPHL();    //SCOTTY 09/05/2007
      
            if ( TB1_ubErrCnt < 25 ){ TB1_ubErrCnt++; }
            TB_40ms ^= 1;

//---ADDED BY DINO 10/16/2007---
        //--- Siwtch SIN/COS signals every 20ms
        if ( pr[PG_TYPE]==SIN_SIN ){  // Initial position is gotten from SIN/COS signal
#if SH7286 //Sean, 01/25/2010
      #if NEWIEDCB  // IO Define, Sean, 06/25/2010
      
#if 1 // add pghs01, Sean, 12/06/2010
        uwSIN_data = Pgc_uwCne;
        uwCOS_data = Pgc_uwDpo;
#else     
          if ( TB_40ms )  // Inverse SIN/COS, DINO, 09/28/2010, Modify for New PG Card, DINO, 10/20/2010
            uwSIN_data = AN7;  // SIN_data(PGSEL=1), // SIN/COS Signal is changed to AN7, DINO, 08/12/2010
          else
            uwCOS_data = AN7;  // COS_data(PGSEL=0), // SIN/COS Signal is changed to AN7, DINO, 08/12/2010
#endif 
            
        #else
          if ( TB_40ms )
            //uwSIN_data = AN8;  // SIN_data(PGSEL=0)
            uwSIN_data = AN02;  // SIN_data(PGSEL=0)
          else
            //uwCOS_data = AN8;  // COS_data(PGSEL=1)
            uwCOS_data = AN02;  // COS_data(PGSEL=1)
        #endif
        if ( (pr[DEBUG_F1]&0x0008)!=0x0008 && TUN_START==0 )  // Not for ICT test, not Z-phase tunning
          PGSEL = TB_40ms;  // Switch SCS2  // SIN/COS Signal is changed to AN7, DINO, 08/12/2010
#else         
          if ( TB_40ms )
            //uwSIN_data = AN10;  // SIN_data(SCI2_DIR=0)
            uwSIN_data = AN102;  // SIN_data(SCI2_DIR=0)
          else
            //uwCOS_data = AN10;  // COS_data(SCI2_DIR=1)
            uwCOS_data = AN102;  // COS_data(SCI2_DIR=1)
        if ( (pr[DEBUG_F1]&0x0008)!=0x0008 && TUN_START==0 )  // Not for ICT test, not Z-phase tunning
          SCI2_DIR = TB_40ms; // Switch SCS2            
#endif
      }
//---END 10/16/2007---------------

            if ( TB_40ms ){
              /* ------ 40ms timer ------*/
              Thermal_OLCHK();  
          }

          else {
              /* ------ 40ms timer ------*/
//---ADDED BY DINO 10/16/2007---
//              if ( RUNNING==STOP ){
                //------ Calculate Sin_data and Cos_data --------------------//
            SINadLPF.sl += (SLONG)( (SWORD)uwSIN_data - SINadLPF.sw.hi ) * 13107; // 200ms (base 40ms)
            COSadLPF.sl += (SLONG)( (SWORD)uwCOS_data - COSadLPF.sw.hi ) * 13107; // 200ms (base 40ms)
//          }
//---END 10/16/2007---------------
                   
            }

        }
        else{
          
          //  [ kb(onboard)pin test, Sean, 08/09/2010
      if ((pr[DEBUG_F1]&0x0008) == 0x0008){ // Bit 3: Enable all ICT test
        pr[_47th_DISP] = /*PORT9.PIDR.BIT.B5*/KEYDI;
      }
      else{
            // [ LED KEYPAD Input, DINO, 03/09/2010
            KEY_IN();
          } 
      //  ] kb(onboard)pin test, Sean, 08/09/2010

      // [ Initial Page, DINO, 06/01/2010
      if (KEY_uwPWRCnt < 150){  // 3sec/20ms=150
        KEY_uwPWRCnt++;
        if (KEY_uwPWRCnt == 150){
          if (KEY_ubDispMode == FunPAGE2){
            KEYPRESS = 1;
            keyinx = PROGKEY;
          }
        }
      }
      // ]

          Update_LEDKeyDisp();
          // ]
          
          
            /* ------ 20ms timer ------*/               
          if (TB1_ub100msCnt !=0){
              /* ------ 20ms timer ------*/
              TB1_ub100msCnt --;        
//-- Communication Encoder EnDat & Hiperface, Add by DINO, 08/15/2008
        if ( TB1_ub100msCnt==0 ){
#if SH7286  //[For IED PG-Card, Sampo
          if (RUNNING==STOP || pr[PM_AUTO_T]!=0){ // Add by DINO, 10/07/2008
            if ((pr[DEBUG_F1]&0x0008)!=0x0008 && TB_2sec==1){  // Not TE test and Encoder Ready
              if ( pr[PG_TYPE]==SIN_ENDAT )
                RxDecoder_EnDat();
              //-- Add by DINO, 10/08/2008
              else if ( pr[PG_TYPE]==SIN_HIPER )
                RxDecoder_Hiper();
            }
          }
#endif
              }
//-- End on 08/15/2008
            }
          else{
                TB1_ub100msCnt = 4;
                /* ------ 100ms timer ------*/
                TB_100ms = 1;

                PID_Loss();
                PID_Deviation();



//              if ((pr[CTODT2]!=0)&&(pr[C_FAULT2]!=3)) {            // Enable Time out Detection
                if ((pr[CTODT2]!=0)&&(pr[C_FAULT2]<2)) 
                {            // SCOTTY 09/03/2007
                    if (SCI2_TodCNT <= pr[CTODT2])      //tod_cnt, Time out detection count
                    {
                        SCI2_TodCNT++;
                    }
                }
                if ((pr[CTODT3]!=0)&&(pr[C_FAULT3]<2)) 
                {            // SCOTTY 09/03/2007
                    if (SCI3_TodCNT <= pr[CTODT3])      //tod_cnt, Time out detection count
                    {
                        SCI3_TodCNT++;
                    }
                }

                //if (Com_WatchDog3<250)    
                   //Com_WatchDog3++;
                   
                //if (Com_WatchDog4<250)    
                   //Com_WatchDog4++;

                  
                //if (Com_WatchDog2<250)
                //[JES SE1_ERR, Rational 282940, Special.Kung, 2022/08/24]
                if((Com_WatchDog2<250) && (COPYFLAG==0))
                {         
                    Com_WatchDog2++;
                }

                if(Com_WatchDog0<250)
                {
                    Com_WatchDog0++;
                }

                if((OT1CST)&&(TB1_uwOT1Cnt<0x3ff))  // OT1 count start
                {
                    TB1_uwOT1Cnt ++;
                }
            
                if((OT2CST)&&(TB1_uwOT2Cnt<0x3ff))  // OT2 count start
                {
                    TB1_uwOT2Cnt ++;
                }
                    
                if (OVERSLIP==1)
                {
                    if ((UWORD)TB1_ubOverWsCnt<=pr[SLIPDEVT])
                    {
                        TB1_ubOverWsCnt++;
                    }
                }         
              
                if (TB1_ub1secCnt!=0)
                {
                  TB1_ub1secCnt --;
                }
                else
                {               
                    TB1_ub1secCnt = 9;
                    /* ------ 1 sec timer ------*/
                    TB_1sec = 1;
                    if (pr[PGINPUT]!=0)
                    {
                        SpDt_uwPG1LoSpdCNT_Z1 = SpDt_uwPG1LoSpdCNT_Old;
                    }
                }        
                // [ LED KEYPAD, DINO, 03/12/2010
                if (TB1_ub1secCnt < 5)
                {
                    LEDBLINK = 1 ;
                }
                else
                {
                    LEDBLINK = 0;
                }
                chkamps();      
            }// 100ms End
        }// 20ms End
    }// 10ms End   

   if ((pr[DEBUG_F1]&0x0002) == 0x0002){      //[ICT Test, Bernie, 08/11/2011]   
         RCAN_Timer++;
         if(RCAN_Timer == 10){
             RCAN_Timer = 0;
             CAN_ICT_TX();
             if (CAN1.EIFR.BYTE != 0){
                 CAN1.EIFR.BYTE = 0;
                 //RCAN_ubErr4Rgst = CAN1.EIFR.BYTE;
                 //CAN_uwErrNo = 0x06;
                 //Error = CAN_ERR;
             }
         }
         if(CAN1.EIFR.BYTE != 0){
             CAN1.EIFR.BYTE = 0;
         }
         RCAN_RX_Count++;
         if(RCAN_RX_Count > uwCAN_ChkTime){
            CAN_uwErrNo = 0x06;
            Error = CAN_ERR;
         }
         
   }
   else{
       if((Error != CAN_ERR)){
           if((uwPDO_CNT < uwCAN_ChkTime)&&(pr[CAN_ChkTime]!=0)){
               uwPDO_CNT++;        // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
           }
       }
		//#if 1
	   //-----aevin add CAN fail rate--6/12/2017        //[CAN fail rate function, Aevin, 2017/06/14]
	   uwPDOfailCNT++;     
	   //if(!(uwPDOfailCNT % pr[CAN_ChkTime]) && uwPDOfailCNT!=0){
	   if(uwPDOfailCNT == 1000){
	       //uwCAN=(uwPDO_CNT>=pr[PDO_TX_Time])?uwPDO_CNT - pr[PDO_TX_Time]:pr[PDO_TX_Time]-uwPDO_CNT;
		   //uwCAN2 = pr[CAN_ChkTime]>=pr[PDO_TX_Time]?pr[CAN_ChkTime] - pr[PDO_TX_Time]:pr[PDO_TX_Time]-pr[CAN_ChkTime];

		   //uwPDOfailBuf += (uwCAN * 100)/uwCAN2;
		   //pr[CANFAILRATE] = (uwPDO_CNT * 100)/pr[CAN_ChkTime];
		   //uwPDOfailBuf = (uwPDO_CNT * 100)/pr[CAN_ChkTime];
		   uwCAN = 1000 / pr[CANPDOTXTIME];           //[CAN fail rate function, Aevin, 2017/06/14]
		   uwPDOfailBuf = (uwPDOInCnt *100)/uwCAN;
		   if(uwPDOfailBuf>100)
		   	uwPDOfailBuf = 100;
		   uwPDOfailCNT = 0;
		   uwPDOInCnt = 0;
	   }
	   //---------------------------------------
       //#endif
	   ubPDO_TxCNT++;
       //[claer state when Error occur ,Bernie, 2015/05/12]    
       if (((ubPDO_TxCNT >= pr[PDO_TX_Time])&&( pr[PDO_TX_Time]!=0))/* && (pr[SOFC]==4||pr[SOFC]==5)*/)
       {
           CAN_PDO_TX_return();
           ubPDO_TxCNT = 0;
       }
   }
 #if BOOTLOADER_ENABLE	// Bootloader enable, Sean, 20141022
  
   	if (switch_TxDon==1){
		switch_TxDonWait=(switch_TxDonWait<1100)?switch_TxDonWait+1:switch_TxDonWait;	// bootloader over usb for online mode, Sean, 20141030
	} 


#endif




#if 0   //CAN FUNCTION BERNIE
   if(pr[CAN_HC]==0)             // [CAN Protocol for High Cap , Sampo,  2011/09/05]
       car_vdRcan();             // [Can function, Bernie, 08/16/2011]

  if(pr[CAN_CTRL]==1){      //[CAN Control, Sampo, 09/15/2010]
    if( ubCanWarnCnt > 50 ){
      if(pr[CAN_FAULT]==0){
        if ((Error==0)&&(WarnCode==0)){
          Keypad_PageTmp = Keypad_Page;
          Keypad_Page = WarnPAGE;                       
          WarnCode = CANOFF_WARN;
        }
      }
      else if(pr[CAN_FAULT]==1){
        if (Error==0){
          Error = CAN_ERR;
        }
      }
      else{ //pr[CAN_FAULT] = 2 or 3    
      }
    }
    else if( WarnCode == CANOFF_WARN){
      Keypad_Page = Keypad_PageTmp;
      WarnCode = 0;
    }
    else 
      ubCanWarnCnt++;

  }
    if(pr[CAN_HC]==1){  
                                 //[CAN Communication PDO count, Bernie, 09/22/2011]
        if(uwPDO_CNT < uwCAN_ChkTime){
            uwPDO_CNT++;        // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
        }
    
        ubPDO_TxCNT++;
    
        if ( ubPDO_TxCNT == pr[PDO_TX_Time] ){
            PDO_TX_Decode();
            ubPDO_TxCNT = 0;
        }
    }
#endif
    if(pr[CTRLM]<= SVC /*&& GEN_MOT_START == 1*/){   //[Add Generator or Motor Direction, Bernie, 05/21/2012]
        VFGenOrMot_DIR();
    }

    if(IODLC_ubArea_status!=Arealand){
        if(IODLC_MIinput==MI_ON){
            
            if((pr[CTRLM]!=FOCPM)&&(pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=VFPG))
                IODLC_ulSFDistance += (speed_tmp+fcmd.uw.hi)/20;
            else
                IODLC_ulSFDistance += (speed_tmp+uwAbsMotorHz)/20;
        }
        if(IODLC_CRPLSset){            
            if((pr[CTRLM]!=FOCPM)&&(pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=VFPG))
                IODLC_ulCPSDistance += (speed_tmp+fcmd.uw.hi)/20;
            else
                IODLC_ulCPSDistance += (speed_tmp+uwAbsMotorHz)/20;
        }
        if((pr[CTRLM]!=FOCPM)&&(pr[CTRLM]!=FOCPG)&&(pr[CTRLM]!=VFPG))
            speed_tmp = fcmd.uw.hi;
        else
            speed_tmp = uwAbsMotorHz;
    }
    
    if((uwEPS_Delay_CNT<(pr[EPS_MO_DELAY]*100)) /*&& (MI_EPS_SWITCH)*/){ //[EPS MO Output,Lyabryan,2018/06/19]
        if((MI_EPS_SWITCH)&&(!EPS_MO_JUDGEMENT)){
            uwEPS_Delay_CNT++;
        }
      	else if((MI_EPS_SWITCH==0)&&(!EPS_MO_JUDGEMENT)&&  //IED2 EPS MO Output,Henry,2018/09/05
      		      ((Error==LvA_ERR)||(Error==Lvd_ERR)||(Error==Lvn_ERR)||(Error==LvS_ERR))){
            uwEPS_Delay_CNT++;
      	}
        else
            uwEPS_Delay_CNT = 0;
    }
    else{
        MO_EPS_SWITCH = 1;
    }
    
    if(EPS == 0 && EPS_MO_JUDGEMENT==1 && MO_EPS_SWITCH==1){
        if(uwEPS_Off_CNT<pr[EPS_MO_OFF]*100){
            uwEPS_Off_CNT++;
        }
    }
}


//****************************************************************************
//  Function: Detect motor connect loss
//  Date: 05/12/2009 , added by Sampo
//    step1==>dc inject with 5% Irated until Ia and Ic greater than 3%Irated
//    step2==>wait for double step1 counter time
//    step3==>dc inject with 5% Irated until Ib and Ic greater than 3%Irated
//    step4==>wait for double step3 counter time  than Detect complete
//    
//    MPHL_err enable time: dt = [(L * 3%Irated)*1.5]/(5%Vrated)
//****************************************************************************
void MPHL_Detect(void)
{
  UWORD uwILevel;
/*
  if (DCBUSREC==1){
    dcbusDCInit = dcbusDC;
    DCBUSREC = 0;
  }
*/
  if ((pr[AVR]==0)||((pr[AVR]==2)&&(ACCODEC==ACCON)))
    AVREN = 1;
  else
    AVREN = 0;

  // Output 5% Rated Current, 205=5%*4096
  uwILevel = (UWORD)((ULONG)COF_uwIIratePu * 205 >> 12);
  dci_MPHL(uwILevel,(vbase>>1));

  // Detection Level is 3% Rated Current, 123=3%*4096
  uwILevel = (UWORD)((ULONG)COF_uwIIratePu * 123 >> 12);

  if((TB1_swMPHLstep == 0)&&(abs(AD_swIAPu) > uwILevel)&&(abs(AD_swICPu) > uwILevel)){
    TB1_swTempcnt  = TB1_swMPHLcnt<<1; 
    TB1_swMPHLcnt  = 0;
    TB1_swMPHLstep = 1; 
  }
  else if((TB1_swMPHLstep == 1)&&(TB1_swMPHLcnt > TB1_swTempcnt)){
    TB1_swMPHLcnt  = 0;
    TB1_swMPHLstep = 2;
  }
  else if((TB1_swMPHLstep == 2)&&(abs(AD_swIBPu) > uwILevel)&&(abs(AD_swICPu) > uwILevel)){
    TB1_swTempcnt  = TB1_swMPHLcnt<<1;
    TB1_swMPHLcnt  = 0;
    TB1_swMPHLstep = 3;
  }
  else if((TB1_swMPHLstep == 3)&&(TB1_swMPHLcnt > TB1_swTempcnt)){
    STtune         = TB1_MPHL_Buf;
    TB1_swMPHLcnt  = 0;
    TB1_swMPHLstep = 4;
    MPHL_DET       = 0;
  }

  // Overtime is 30ms
  if(((TB1_swMPHLstep == 0)||(TB1_swMPHLstep == 2))&&(TB1_swMPHLcnt>30)){
    Error          = MPHL_ERR; 
    TB1_swMPHLcnt  = 0;
    LIFT_ENABLE    = 0;
    TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
    CMDFREE = 1;
  }    
       
       
  if ( MPHL_DET ){
    TB1_swMPHLcnt++;
  }
  else{
    TB1_swMPHLcnt = 0;
  }

}


//***************************************************
// function: DC Injection for MPHL
// date: 05/12/2009  added by Sampo
//***************************************************
void dci_MPHL(UWORD dci_ref, UWORD VLimit)
{
  SWORD ax;
        
  ax = dci_ref - Ismax_uwPu;

    if (TB1_swMPHLstep==1 || TB1_swMPHLstep==3){
    ax =0;
    VF_Vcmd = 0;
    }

  if (ax > (SWORD)0) {
    if (ax > DCI_LIMIT){    // Limit 20 = 2.0V
      ax = DCI_LIMIT;
    }

    VF_Vcmd = VF_Vcmd + (((ULONG)ax*250)>>8);

    if (VF_Vcmd >= VLimit){   // 50% vbase_l
      VF_Vcmd = VLimit;
    }
  }
  else if (ax < (SWORD)0) {

    ax = -ax;

    if (ax > DCI_LIMIT){    // Limit 20 = 2.0V
      ax = DCI_LIMIT;
    }

    ax = (((ULONG)ax*250)>>8);

    if (VF_Vcmd <= ax){
      VF_Vcmd = 0;
    }
    else{
      VF_Vcmd -= ax;
    }
  }

}

void VFGenOrMot_DIR(void){    //[Add Generator or Motor Direction, Bernie, 05/21/2012]  

    if (pr[CTRLM] <= SVC){
            VF_IqseOutPuLPF.sl += (SLONG)(TsE_swIqseOutPu - VF_IqseOutPuLPF.sw.hi ) * 655;  // 100ms (base 1ms)
    }
}

void EPS_NormalDetectCurrent(void){ //[EPS autodetect dir,Lyabryan,2018/07/02]
    
    if((pr[SOFC]!=4)&&(pr[SOFC]!=5)){       
        
        if((pr[S4ACC1]<100)||(pr[S4ACC1]>200)){
            EPS_S1current_get = 1;
            if((IODLC_ubArea_status>=AreaS1)&&(IODLC_ubArea_status<=AreaS2)){
                EPS_swRecord_CNT++;
                if(EPS_swRecord_CNT>1500){
                    EPS_DIR_CATCH = 1;
                    EPS_swRecord_CNT = 1500;
                }
            }
        }
        else{
            EPS_DIR_CATCH = 0;
        }
            



        if(((!EPS_S1current_get)&&(IODLC_ubArea_status>=AreaAcc))||EPS_DIR_CATCH){  
            EPS_swRecord_S1 = PF_ANGLE;
            EPS_S1current_get = 1;
            EPS_CAL_CUR = 1;
            EPS_DIR_CATCH = 0;
            EPS_NOS1 = 1;
            
        }
        else if((!EPS_NOS1)&&(IODLC_ubArea_status==AreaS1)){ // no arrival AreaAcc and EPS_DIR_CATCH
            pr[EPS_DIR] = !CMDDIR;
            pr[EPS_PFREF]= 2000;
            write_ep(0,EPS_PFREF,pr[EPS_PFREF]);
            write_ep(0,EPS_DIR,pr[EPS_DIR]);

        }
        
        if((!EPS_CAL_CUREND)&&EPS_CAL_CUR){
            EPS_swRecord_AVG = EPS_swRecord_S1; //(EPS_swRecord_S1+EPS_swRecord_S2)>>1;
            if(EPS_swRecord_AVG>(pr[EPS_PF]))
                EPS_btDirect = CMDDIR;
            else
                EPS_btDirect = !CMDDIR;
            
            EPS_CAL_CUREND = 1;
        }
        
        if(EPS_CAL_CUREND){
            EPS_swRecord_up++;
            if(EPS_swRecord_up>5){
                EPS_swRecord_up = 5;
                if(!EPS_TUNE_END){
                    pr[EPS_PFREF] = EPS_swRecord_AVG;
                    pr[EPS_DIR] = EPS_btDirect;
                    write_ep(0,EPS_PFREF,pr[EPS_PFREF]);
                    write_ep(0,EPS_DIR,pr[EPS_DIR]);
                }
                EPS_TUNE_END = 1;
            }
                    
        }
    }
    else{ 

        if((pr[S4ACC1]<100)||(pr[S4ACC1]>200)){
            EPS_S1current_get = 1;
            if((DLC_ubMode>=MODE_S1)&&(DLC_ubMode<=MODE_S2)){
                EPS_swRecord_CNT++;
                if(EPS_swRecord_CNT>1500){
                    EPS_DIR_CATCH = 1;
                    EPS_swRecord_CNT = 1500;
                }
            }
        }
        else{
            EPS_DIR_CATCH = 0;
        }
            
        
        
        
        if(((!EPS_S1current_get)&&(DLC_ubMode>=MODE_ACC))||EPS_DIR_CATCH){  
            EPS_swRecord_S1 = PF_ANGLE;
            EPS_S1current_get = 1;
            EPS_CAL_CUR = 1;
            EPS_DIR_CATCH = 0;
            EPS_NOS1 = 1;
            
        }
        else if((!EPS_NOS1)&&(DLC_ubMode==MODE_S1)){ // no arrival AreaAcc and EPS_DIR_CATCH
            pr[EPS_DIR] = !CMDDIR;
            pr[EPS_PFREF]= 2000;
            write_ep(0,EPS_PFREF,pr[EPS_PFREF]);
            write_ep(0,EPS_DIR,pr[EPS_DIR]);
        
        }
        
        if((!EPS_CAL_CUREND)&&EPS_CAL_CUR){
            EPS_swRecord_AVG = EPS_swRecord_S1; //(EPS_swRecord_S1+EPS_swRecord_S2)>>1;
            if(EPS_swRecord_AVG>(pr[EPS_PF]))
                EPS_btDirect = CMDDIR;
            else
                EPS_btDirect = !CMDDIR;
            
            EPS_CAL_CUREND = 1;
        }
        
        if(EPS_CAL_CUREND){
            EPS_swRecord_up++;
            if(EPS_swRecord_up>5){
                EPS_swRecord_up = 5;
                if(!EPS_TUNE_END){
                    pr[EPS_PFREF] = EPS_swRecord_AVG;
                    pr[EPS_DIR] = EPS_btDirect;
                    write_ep(0,EPS_PFREF,pr[EPS_PFREF]);
                    write_ep(0,EPS_DIR,pr[EPS_DIR]);
                }
                EPS_TUNE_END = 1;
            }
                    
        }
    }
}



//********************************************************************
// Function: Detect the sign of Iq, then let the command direction = generation direction
// Date: 2010/04/27 , by Justin 
//**********************************************************************
void Generation_DIR(void)     
{
  
  if ((pr[CTRLM] > SVC)&&(pr[EPS_OPTM]!=4)){
      if (TB1_uwGencnt < (pr[GEN_T]*100)){
          TB1_uwGencnt++;
          IqseOutPuLPF.sl += (SLONG)(TsE_swIqseOutPu - IqseOutPuLPF.sw.hi ) * 6550;  // 10ms (base 1ms)
      }
      else{
          if (GEN_OK == 0){
              if (IqseOutPuLPF.sw.hi < 0){     // Iq<6.25%Irated, then command direction=forward  //[Modify EPS function, Bernie, 2012/11/27 ]
                  if(pr[EPS_OPTM]==1){           //[Modify EPS function, Bernie, 2012/11/27 ]         
                      CMDDIR = FORWARD;
                      GEN_OK3 = 1;             		
                      if(pr[CHG_DIR]==1){
                          CMDDIR ^= 1; //GENDIR related to para 00-11, James, 2019/12/20
                      }
                  }
                  GEN_OK2_DIR = FORWARD;         //[Modify EPS function, Bernie, 2012/11/27 ]
              }
              else if (IqseOutPuLPF.sw.hi >= 0){  // Iq>6.25%Irated, then command direction=reverse  //[Modify EPS function, Bernie, 2012/11/27 ]
                  if(pr[EPS_OPTM]==1){          //[Modify EPS function, Bernie, 2012/11/27 ]
                      CMDDIR = REVERSE;
                      GEN_OK3 = 1;   
                      if(pr[CHG_DIR]==1){
                          CMDDIR ^= 1; //GENDIR related to para 00-11, James, 2019/12/20
                      }
                  }
                  GEN_OK2_DIR = REVERSE;        //[Modify EPS function, Bernie, 2012/11/27 ]
              }
              GEN_OK = 1;
              //if(pr[EPS_OPTM]==1)               //[Modify EPS function, Bernie, 2012/11/27 ]
                  //GEN_OK3 = 1;                  //be used to control CMDDIR in EPS function
              //GENDIR = CMDDIR ^ 1;
              GENDIR = GEN_OK2_DIR ^ 1;         //[Modify EPS function, Bernie, 2012/11/27 ]
              //TB1_uwGencnt = 0;
          		
          		//GENDIR related to para 00-11, Henry, 2017/05/24
          		if(pr[CHG_DIR]==1){
          		    GENDIR ^= 1;
					//CMDDIR ^= 1; //GENDIR related to para 00-11, James, 2019/12/20
          	    }
          }
          else{
              GEN_START = 0;
          }
      }
  }
  else if((pr[CTRLM] > SVC)&&(pr[EPS_OPTM]==4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]
    
      if (GEN_OK == 0){
          CMDDIR = pr[EPS_DIR];
          GEN_OK3 = 1;   
          GEN_OK2_DIR = pr[EPS_DIR];         //[Modify EPS function, Bernie, 2012/11/27 ]
          GENDIR = pr[EPS_DIR];         //[Modify EPS function, Bernie, 2012/11/27 ]
          if(pr[CHG_DIR]==1){
              GENDIR ^= 1;
          }
      }
      else
          GEN_START = 0;
  }
  else{
      if (TB1_uwGencnt < (pr[GEN_T]*100)){
          if (fcmd.uw.hi == Fcmd){
              TB1_uwGencnt++;
          }
      }
      else{              //[EPS, Sampo, 03/27/2011]
          
          if (CMDDIR == FORWARD)
              uwFWDPFangle = PF_ANGLE;
          else
              uwREVPFangle = PF_ANGLE;    
        
          uwEPScnt++;
          if(uwEPScnt<3){
              TB1_uwGencnt = 0;
              CMDDIR ^= 1;
              EPS_STOP = 1;
              stop();  
          }

      }
  }

}

void TimeBase_1msB(void){
    UWORD  uwPGF5_Type;

	//[GFF Maximum Value Record, Jerry Yu, 2019/11/11]
	if (pr[GFF_REC_SW] == 0){
        uwGFF_MaxVal = 0;
/* Don't do Record */
	}
	else if (pr[GFF_REC_SW] == 1){
		/* Do the Record */
		if (AN100 > uwGFF_MaxVal){
			uwGFF_MaxVal = AN100;
		}
	}
   vfd_btPGHSD1Set = (((pr[DEBUG_F1]&0x0008) != 0x0008)&&((pr[PG_TYPE]==SIN_ENDAT)||(pr[PG_TYPE]==SIN_SIN)||(pr[PG_TYPE]==SIN_HIPER)))?1:0; //USRDEF1.bit1	// PGHSD1 setting	// fix pghsd1 code, Sean, 06/01/2012  //[change default value for support PGHSD-1, Bernie, 2014/07/31]
   //vfd_btPGHSD1Set = (((pr[PG_TYPE]==SIN_ENDAT)||(pr[PG_TYPE]==SIN_SIN)||(pr[PG_TYPE]==SIN_HIPER)))?1:0; //USRDEF1.bit1	// PGHSD1 setting	// fix pghsd1 code, Sean, 06/01/2012  //[change default value for support PGHSD-1, Bernie, 2014/07/31] //[delete PGHSD, Lyabryan, 2015/12/17]
    if((pr[DEBUG_PG]&0x0002)!=0x0002 && RUNNING==STOP && ((pr[DEBUG_PG]&0x0020)==0)){ //[For IED PG-Card, Sampo, 02/25/2010]
        if((pr[PG_TYPE]==SIN_SIN ||pr[PG_TYPE]==SIN_ENDAT||pr[PG_TYPE]==SIN_HIPER)&& PGREADY&&!COPYEN){  //[For copy parameter get PGF5 error, Lyabryan, 2015/07/14]
            if(!HALL_LOSS){  //[HALL_LOSS for Error by TB3_SpDtPG1_Err(), Lyabryan, 2015/03/13]
                if (SpDt_uwPGLossCnt3<SpDt_uwPGErrDet){ //[HALL_LOSS for Error by TB3_SpDtPG1_Err(), Lyabryan, 2015/03/13]
                    SpDt_uwPGLossCnt3++;	 //PG Loss, start count  //[HALL_LOSS for Error by TB3_SpDtPG1_Err(), Lyabryan, 2015/03/13]
                }
                else{
                    //Error = PGF5_ERR;
                    if (SpDt_uwPGErrTmp==0) //[HALL_LOSS for Error by TB3_SpDtPG1_Err(), Lyabryan, 2015/03/13]
                    SpDt_uwPGErrTmp = PGHL_ERR; //[HALL_LOSS for Error by TB3_SpDtPG1_Err(), Lyabryan, 2015/03/13]
                }	       
            }
        }
    }

    if(AFE_ERR_TMR)
    {
        AFE_uwMOCNT--;
        if(AFE_uwMOCNT==0)
        {
            AFE_ERR_TRIG = 0;
            AFE_ERR_TMR = 0;
            AFE_Level_Delay = 1;
        }
    }
    else
    {
        AFE_uwMOCNT = AFE_ERR_RST_CNT;
    }
  
    if((Error == 0)&&((pr[DEBUG_PG]&0x0400)!=0x0400)&& Zphase_countAB_flag&&(pr[PG_TYPE]==SIN_SIN))
    { 
        //[Zphase broken, Lyabryan, 2015/09/17]  //[modify Error code,Lyabryan,2016/07/21]
        WGOFF;
        Error = PGAF_ERR;		  
        stop();
        Zphase_countAB_flag = 0;
    }
        
    uwPGF5_Type = 0;
    if(IED_PG_ERR_OVERTIME)//[For IED PG-Card, Sampo, 02/25/2010]
      uwPGF5_Type |=0x0001;
    if(IED_PG_ERR_AB)
      uwPGF5_Type |=0x0002;
    if(IED_PG_ERR_SIN)
      uwPGF5_Type |=0x0004;
    if(IED_PG_ERR_Z)
      uwPGF5_Type |=0x0008;
    if(IED_PG_ERR_ENDAT)
      uwPGF5_Type |=0x0010;
    if(IED_PG_ERR_HIPER)
      uwPGF5_Type |=0x0020;
     saf_uwPGF5_Type = uwPGF5_Type;
}
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
void SIBO_STO_Safty(void){

    UWORD uwSTO_CNT,chg,mfi_status_temp;
    ULONG ulSTO_SIBOCNT;

    STOLOSS = 0;
    STO1LOSS = 0;
    STO2LOSS = 0;
    STO3LOSS = 0;
    if(STO_STRWARN){
        if(TB1_uwSTOStrWARNCnt<8000){
            TB1_uwSTOStrWARNCnt++;
        }
        else{
            STO_STRWARN = 0;
            TB1_uwSTOStrWARNCnt = 8000;
        }
    }
    if(STO_RUNWARN){
        if(TB1_uwSTORunWARNCnt<8000){
            TB1_uwSTORunWARNCnt++;
        }
        else{
            STO_RUNWARN = 0;
            TB1_uwSTORunWARNCnt = 0;
        }
    }
        
    STO_Truth_Table();
	if(pr[SOFC]==4){ //經由CAN_BUS給定方向
		mfi_status_temp = (DLC_PDO_RX_DI.uw>>1)&0x003;
	}
	else{
		mfi_status_temp = mfi_status;
	}
    /*
	if(RUNNING==RUN)
        ulSTO_SIBOCNT = STO_ERR_CNT;
    else if(((mfi_status_temp&0x0003)!=0x0000)&&(RUNNING==STOP))
        ulSTO_SIBOCNT = 2000;  //2000 = 1sec
    */
    uwSTO_CNT = STO_ERR_CNT;
    
    if((STOLOSS ==1) || (STO1LOSS ==1) || (STO2LOSS ==1) || (STO3LOSS ==1)){
        STO_STATUS_FLAG = 1;

        if((uw_STOStatus != 0) && (uw_STOStatus == uw_STOStatusOld)){
            TB1_uwSTOErrCnt++;
            if((STO_STRWARN==0)&&((mfi_status_temp&0x0003) != 0x0000)){ //&&(STO_RUNWARN==0)
                TB1_uwSTOStrCnt++;
                if(WarnCode == STO_WARN)
                    TB1_uwSTOStrCnt = 0;
            }
            else{
                TB1_uwSTOStrCnt = 0;
            }
            if(TB1_uwSTOErrCnt >= uwSTO_CNT){
                TB1_uwSTOErrCnt = uwSTO_CNT+1;
                 if(Error == 0){
                    if(STOLOSS ==1){
                        WGOFF;
    	                Vcmd_LL = 0;	// Let Vcmd = 0LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    				    TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
              	        CMDFREE = 1; 
              	        LIFT_ENABLE = 0;
                        if(RUNNING == RUN){
                            if(WarnCode == 0 && Error == 0){
                                STO_RUNWARN = 1;
                                Keypad_PageTmp = Keypad_Page;
                                Keypad_Page = WarnPAGE;	 
                                WarnCode = STO_WARN;
                                STO_FLAG = 1;
                                if((mfi_status_temp&0x0003) != 0x0000){
                                    STO_FLAG2 = 1;
              	                }
                            }
                        }
                        if(TB1_uwSTOStrCnt>2000){
                                TB1_uwSTOStrCnt = 2000;
                            if((RUNNING != RUN)&&((mfi_status_temp&0x0003) != 0x0000)){
                                if(WarnCode == 0 && Error == 0){
                                    STO_STRWARN = 1;
                                    Keypad_PageTmp = Keypad_Page;
                                    Keypad_Page = WarnPAGE;	 
                                    WarnCode = STO_WARN;
                                    STO_FLAG = 1;
                                    //if((mfi_status_temp&0x0003) != 0x0000){
                                        //STO_FLAG2 = 1;
                  	                //}
                                }
                            }
                        }
                    }
                    else if(STO1LOSS ==1)
                        Error = STOL1_ERR;
                    else if(STO2LOSS ==1)
                        Error = STOL2_ERR;
                    else if(STO3LOSS ==1)
                        Error = STOL3_ERR;
                    LIFT_RUNCMD = 0;
                }

                WGOFF;
            }
        }
        else{
            TB1_uwSTOErrCnt = 0;
        }
        uw_STOStatusOld = uw_STOStatus;
    }
    else{
        STO_STATUS_FLAG = 0;
        if(TB1_uwSTOStrCnt<2000){
            TB1_uwSTOStrCnt = 0;
        }
        TB1_uwSTOErrCnt = 0;
        uw_STOStatusOld = 0;
        uw_STOStatus = 0;
		//[Sibocom SOS Warn, James, 2020/04/28]
		if((RUNNING != RUN)&&((mfi_status_temp&0x0003) == 0x0000)){
			if(TB1_uwSOSStrCnt<2000){  //2000 = 1sec
				TB1_uwSOSStrCnt++;
			}
			else{
				TB1_uwSOSStrCnt = 2000;
                if(WarnCode == 0 && Error == 0){
                    STO_SOSWARN = 1;					
					TB1_uwSOSRunWARNCnt = 0;
                    Keypad_PageTmp = Keypad_Page;
                    Keypad_Page = WarnPAGE;	 
                    WarnCode = SOS_WARN;
                    STO_FLAG = 1;
                }
			}
		}
		else{
			TB1_uwSOSStrCnt = 0;
            if(WarnCode != SOS_WARN){
            	TB1_uwSOSRunWARNCnt = 0;
            }
		}
    }
    TB1_uwSTORSETCnt++;
    if(TB1_uwSTORSETCnt>100){
        TB1_uwSTORSETCnt = 0;
        if(STO_RUNWARN==0){
            if(STO_STRWARN==0){
                if(((mfi_status_temp&0x0003) == 0x0000)){                
                    if((WarnCode==STO_WARN)){
                        WarnCode = 0;
                        //STO_FLAG = 0;
                        Keypad_Page = Keypad_PageTmp;
                        TB1_uwSTOErrCnt = 0;
                        uw_STOStatusOld = 0;
                        uw_STOStatus = 0;
                        TB1_uwSTOStrWARNCnt = 0;
                    }
                }            
                else{
                    if(STO_STATUS_FLAG==0){
                        if((WarnCode==STO_WARN)){
                            WarnCode = 0;
                            //STO_FLAG = 0;
                            Keypad_Page = Keypad_PageTmp;
                            TB1_uwSTOErrCnt = 0;
                            uw_STOStatusOld = 0;
                            uw_STOStatus = 0;
                            TB1_uwSTOStrWARNCnt = 0;
                        }
                    }
                }
            }
        }
        else{
        }
        
    }
	//[Sibocom SOS Warn, James, 2020/04/28]
    if(STO_SOSWARN){
        if(TB1_uwSOSRunWARNCnt<6000){//6000 = 3sec
            TB1_uwSOSRunWARNCnt++;
			TB1_uwSOSRSETCnt = 0; 
        }
        else{
			TB1_uwSOSRunWARNCnt = 6000;
        }
    }
	if(TB1_uwSOSRunWARNCnt == 6000)
	{			
    	if(((STOLOSS ==1) || (STO1LOSS ==1) || (STO2LOSS ==1) || (STO3LOSS ==1)) && ((mfi_status_temp&0x0003) == 0x0000))
		{				
			TB1_uwSOSRSETCnt++;
			if(TB1_uwSOSRSETCnt>2000) //2000 = 1sec
			{
				TB1_uwSOSRSETCnt = 2000;
                if(WarnCode==SOS_WARN)
				{
					STO_SOSWARN = 0;
                    WarnCode = 0;
                    Keypad_Page = Keypad_PageTmp;
					TB1_uwSOSStrCnt = 0;
            	}
        	}
        }
		else				
			TB1_uwSOSRSETCnt = 0;
    }

    if((pr[WIRE2_3]<2)&&((mfi_status_temp&0x0003) == 0x0000)){       //[STO function add Warning code and run rule, Bernie, 2016/03/22]
        STO_FLAG2 = 0;
    
        if(TUN_STOP){
            TUN_STOP = 0;
        }
    }
    else if(((pr[WIRE2_3]==2)||(pr[WIRE2_3]==3))&&((mfi_status_temp&0x0001) == 0x0000)){
        STO_FLAG2 = 0;
    
        if(TUN_STOP){
            TUN_STOP = 0;
        }
    }
    else if(((pr[WIRE2_3]==4)||(pr[WIRE2_3]==5))&&((mfi_status_temp&EXT_DI1) == 0x0000)){
        STO_FLAG2 = 0;
    
        if(TUN_STOP){
            TUN_STOP = 0;
        }
          
    }
    if(STO_FLAG2 == 0){                  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
        if(STO_FLAG == 1){
            if(((mfi_status_temp&0x0003) == 0x0000)&&(STO_RUNWARN==0)&&(STO_STRWARN==0)&&(STO_SOSWARN==0)){//[Sibocom SOS Warn, James, 2020/04/28]
                STO_FLAG = 0;
            }
            else if(((mfi_status_temp&0x0003) != 0x0000)&&(STO_SOSWARN==0)){
                if(((WarnCode!=STO_WARN))&&((STO_RUNWARN==0)||(STO_STRWARN==0)))
                STO_FLAG = 0;
            }
        }
    }
    
}
#endif
void TB3_STO_Safty(void){

    UWORD uwSTO_CNT, mfi_status_temp, uwSTOShortTime;

    STOLOSS = 0;
    STO1LOSS = 0;
    STO2LOSS = 0;
    STO3LOSS = 0;    
    STO_Truth_Table();

    if((STO1LOSS ==1) || (STO2LOSS ==1))
    {
        uwSTO_CNT = STOL1_ERR_CNT;
    }
    else
    {
        uwSTO_CNT = STO_ERR_CNT;
    }
    uwSTOShortTime = pr[STO_SHORT_T] * 200;//(1.0(dot1) *  200) *500us = 1sec
    
	//add STO run dir command source from CANbus, James, 2020/11/26
	if(pr[SOFC]==4)//經由CAN_BUS給定方向
	{ 
		mfi_status_temp = (DLC_PDO_RX_DI.uw>>1)&0x0003;
	}
	else//Command from MI or JOG
    {
		mfi_status_temp = mfi_status | CMDJOG;
	}

	if(RUNNING == RUN)
	{
		TB1_uwStoRunCnt = STO_RUN_CNT;
	}
	else
	{
        TB1_uwStoRunCnt = TB1_uwStoRunCnt>0?TB1_uwStoRunCnt-1:0;
	}

    if((STOLOSS ==1) || (STO1LOSS ==1) || (STO2LOSS ==1) || (STO3LOSS ==1))
    {
        if((uw_STOStatus != 0) && (uw_STOStatus == uw_STOStatusOld))
        {
            TB1_uwSTOErrCnt++;
            if((mfi_status_temp&0x0003) != 0x0000)
            { 
                TB1_uwSTOStrCnt++;
                if((WarnCode == STOb_WARN) || (Error == STOr_ERR))
                {
                    TB1_uwSTOStrCnt = 0;
                }
				else
				{;}
            }
            else
            {
                TB1_uwSTOStrCnt = 0;
            }
            
            if(TB1_uwSTOErrCnt >= uwSTO_CNT)
            {
                TB1_uwSTOErrCnt = uwSTO_CNT+1;
                 if(Error == 0)
                 {
                    if(STOLOSS ==1)
                    {
                        WGOFF;
    	                Vcmd_LL = 0;	// Let Vcmd = 0LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
    				    TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
              	        CMDFREE = 1; 
              	        LIFT_ENABLE = 0;
              	        
                        if((pr[STO_LOCK] & 0x0004)== 0x0004)//04-49=4~7
                        {
                            if((RUNNING == RUN) || (TB1_uwStoRunCnt > 0))
                            {
                                Error = STOr_ERR;
                                //STO_FLAG = 1;
                            }
                            else 
                            {
                                if(TB1_uwSTOStrCnt > STOb_RUN_CNT)//check FWD/REV after 1 second 
                                {
                                    TB1_uwSTOStrCnt = STOb_RUN_CNT;
                                    if((mfi_status_temp&0x0003) != 0x0000)
                                    {
                                        if(WarnCode == 0 && Error == 0)
                                        {
                                            Keypad_PageTmp = Keypad_Page;
                                            Keypad_Page = WarnPAGE;  
                                            WarnCode = STOb_WARN;
                                        }
										else
										{;}
                                    }
									else
									{;}
                                }
								else
								{
									if ((pr[SOOC] == 2) && (pr[SOFC] != 4) && (pr[SOFC] != 5))//Show warning when  STO open & Command from Keypad
									{
									    if(WarnCode == 0 && Error == 0)
										{
											Keypad_PageTmp = Keypad_Page;
											Keypad_Page = WarnPAGE;  
											WarnCode = STO_WARN;
										}
                                        else
                                        {;}
									}
									else
									{;}
								}
                             }
                        }
                        else if((pr[STO_LOCK] & 0x0001)== 0x0000)//[STO function add Warning code and run rule, Bernie, 2016/03/22]
                        {   
                            //LIFT_ENABLE = 0;
                            Error = STOL_ERR;
                            STO_FLAG = 1;
                            if((mfi_status_temp&0x0003) != 0x0000)
                            {
                                STO_FLAG2 = 1;
              	            }
							else
							{;}
                        }
                        else if((pr[STO_LOCK] & 0x0001)== 0x0001)
                        {
                            //LIFT_ENABLE = 0;
                            if(WarnCode == 0 && Error == 0)
                            {
                                Keypad_PageTmp = Keypad_Page;
                                Keypad_Page = WarnPAGE;	 
                                WarnCode = STO_WARN;
                                STO_FLAG = 1;
                                if((mfi_status_temp&0x0003) != 0x0000)
                                {
                                    STO_FLAG2 = 1;
              	                }
								else
								{;}
                            }
							else
							{;}
                        }                        
                    }
					else if(STO1LOSS == 1)
					{
						Error = STOL1_ERR;
					}
					else if(STO2LOSS == 1)
					{
						Error = STOL2_ERR;
					}
					else if(STO3LOSS == 1)
					{
						Error = STOL3_ERR;
					}
					else
					{;}
                    
                    if((pr[STO_LOCK] & 0x0004)== 0x0000)//04-49=0~3
                    {
                        LIFT_RUNCMD = 0;
                    }
                    //TB1_ubSTOErrCnt = 0;
                }
				else
				{;}
                WGOFF;
            }			
			else
			{;}
        }
        else{
            TB1_uwSTOErrCnt = 0;
        }
        uw_STOStatusOld = uw_STOStatus;
    }
    else
    {
        TB1_uwSTOErrCnt = 0;
        uw_STOStatusOld = 0;
        uw_STOStatus = 0;
		if((((pr[SOOC] != 2) || (pr[SOFC] == 4) || (pr[SOFC] == 5)) && ((mfi_status_temp&0x0003) == 0x0000))/*I/O & CAN: judge STO short by FWD/REV*/ 
            || (((pr[SOOC] == 2) && (pr[SOFC] != 4) && (pr[SOFC] != 5)) && (RUNNING != RUN)))               /*Keypad:     judge STO short by RUNNING*/
        {
            if(TB1_uwSOSStrCnt < uwSTOShortTime)//2000 = 1sec
			{  
				TB1_uwSOSStrCnt++;
			}
			else
			{
				TB1_uwSOSStrCnt = uwSTOShortTime;
                if(Error == 0)
                {
                    if(pr[STO_LOCK] == 0x0005)
                    {
                        if(WarnCode == 0)
                        {
                            Keypad_PageTmp = Keypad_Page;
                            Keypad_Page = WarnPAGE;	 
                            WarnCode = STOc_WARN;
                        }
						else
						{;}
                        //STO_FLAG = 1;
                    }
                    else if(pr[STO_LOCK] == 0x0006)
                    {
                        Error = STOS_ERR;
                        STO_FLAG = 1;
                    }
                    else if(pr[STO_LOCK] == 0x0007)
                    {
                        Error = STOL4_ERR;
                        STO_FLAG = 1;
                    }
					else
					{;}
                }
				else
				{;}
			}
		}
		else
        {
			TB1_uwSOSStrCnt = 0;
			if(WarnCode == STOc_WARN)//reset STOc_WARN at running
            {               
                WarnCode = 0;
                Keypad_Page = Keypad_PageTmp;
            }
			else
			{;}
		}        
    }
	//STOr reset
    if(Error == STOr_ERR)
    {
        if(TB1_uwSTORunWARNCnt<STOr_RESET_CNT)
        {
            TB1_uwSTORunWARNCnt++;
        }
        else
        {
            reset();
            TB1_uwSTORunWARNCnt = 0;
        }
    }
    else
    {
        TB1_uwSTORunWARNCnt = 0;
    }
	
	//STOb reset
    if((pr[STO_LOCK] & 0x0004)== 0x0004)//04-49=4~7
    {
        if((STOLOSS ==0) || ((mfi_status_temp&0x0003) == 0x0000))
        {
            TB1_uwSTObRESETCnt++;
            if(TB1_uwSTObRESETCnt > STOb_RESET_CNT)
            {
                TB1_uwSTObRESETCnt = 0;
                if(WarnCode == STOb_WARN)
                {
                    WarnCode = 0;
                }
				else
				{;}
            }
    		else
    		{;}
        }
        else
        {
            TB1_uwSTObRESETCnt = 0;
        }
    }
    else//reset warning in other mode
    {
        if(WarnCode == STOb_WARN)
        {
            WarnCode = 0;
        }
		else
		{;}
    }
    
    //reset STOc_WARN if STO is open for 1sec  
    if(pr[STO_LOCK] == 0x0005 || pr[STO_LOCK] == 0x0006)//04-49=5&6
    {
        if((TB1_uwSOSStrCnt == uwSTOShortTime) && ((STOLOSS ==1) || (STO1LOSS ==1) || (STO2LOSS ==1) || (STO3LOSS ==1)) && ((mfi_status_temp&0x0003) == 0x0000))
        {               
            TB1_uwSOSRSETCnt++;
            if(TB1_uwSOSRSETCnt > STOc_RESET_CNT) //1sec
            {
                TB1_uwSOSRSETCnt = STOc_RESET_CNT;
                if(WarnCode == STOc_WARN)
                {               
                    WarnCode = 0;
                    Keypad_Page = Keypad_PageTmp;
                    TB1_uwSOSStrCnt = 0;
                }
                else
                {;}
                if(Error == STOS_ERR)
                {               
                    STO_FLAG = 0;
                    if(pr[STO_LOCK] == 0x0006)
                    {
                        TB1_uwSOSStrCnt = 0;
                    }
                    else
                    {;}
                }
                else
                {;}
            }
            else
            {;}
        }
        else
        {      
            TB1_uwSOSRSETCnt = 0;
        } 
    }
    else
    {
        if(WarnCode == STOc_WARN)
        {               
            WarnCode = 0;
            Keypad_Page = Keypad_PageTmp;
        }
        else
        {;}
        if(Error == STOS_ERR)
        {               
            STO_FLAG = 0;
        }
        else
        {;}
    }
    
    //STOA reset
	if((pr[STO_LOCK] == 0x0001) || (pr[STO_LOCK] == 0x0003) || ((pr[SOOC] == 2) && (pr[SOFC] != 4) && (pr[SOFC] != 5)))//06-49=1,3 or Command from Keypad
    {
        TB1_uwSTOARESETCnt++;
        if(TB1_uwSTOARESETCnt>100)
        {
            TB1_uwSTOARESETCnt = 0;
            if(STOLOSS ==0)
			{
                if((WarnCode==STO_WARN))
				{
                    WarnCode = 0;
                    //STO_FLAG = 0;
                    Keypad_Page = Keypad_PageTmp;
                    TB1_uwSTOErrCnt = 0;
                    uw_STOStatusOld = 0;
                    uw_STOStatus = 0;                  
                }
				else
				{;}
            }
			else
			{;}
        }
		else
		{;}
	} 
    else//reset warning in other mode
    {
        if(WarnCode == STO_WARN)
        {
            WarnCode = 0;
        }
		else
		{;}
    }
	
	//STO_FLAG2 reset
    if((pr[WIRE2_3]<2)&&((mfi_status_temp&0x0003) == 0)){       //[STO function add Warning code and run rule, Bernie, 2016/03/22]
        STO_FLAG2 = 0;
    
        if(TUN_STOP){
            TUN_STOP = 0;
        }
		else
		{;}
    }
    else if(((pr[WIRE2_3]==2)||(pr[WIRE2_3]==3))&&((mfi_status_temp&0x0001) == 0))
	{
        STO_FLAG2 = 0;    
        if(TUN_STOP)
		{
            TUN_STOP = 0;
        }
		else
		{;}
    }
    else if(((pr[WIRE2_3]==4)||(pr[WIRE2_3]==5))&&((mfi_status_temp&EXT_DI1) == 0))
	{
        STO_FLAG2 = 0;    
        if(TUN_STOP)
		{
            TUN_STOP = 0;
        }
		else
		{;}          
    }
	//#15799 Re Run need after STO loss for Artemis, 20201222
    if(((pr[STO_LOCK] & 0x0008)==0x0008) && (WarnCode != STO_WARN))
	{
        //STO_FLAG = 0;
        STO_FLAG2 = 0;
        if(TUN_STOP)
		{
            TUN_STOP = 0;
        }
		else
		{;}
          
    }
	
	//STO_FLAG reset
    if(STO_FLAG2 == 0){                  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
        if((STO_FLAG == 1)&& ((pr[STO_LOCK]&0x0002) == 0x0000))
		{
            if(((mfi_status_temp&0x0003) == 0)&& (Error != STOL_ERR)&&(WarnCode != STO_WARN))
			{
                STO_FLAG = 0;
            }
			else
			{;}
        }
        else if((STO_FLAG == 1)&& ((pr[STO_LOCK]&0x0002) == 0x0002))
		{
            if((mfi_status_temp&0x0003) == 0){
                STO_FLAG = 0;
            }
			else
			{;}
        }
		//#15799 Re Run need after STO loss for Artemis, 20201222
        if((STO_FLAG == 1)&& ((pr[STO_LOCK] & 0x0008)==0x0008))
		{
			STO_FLAG = 0;
		}
		else
		{;}
    }
	else
	{;}
}
void Pgz_Disconnect_Init(void){ //[Zphase broken, Lyabryan, 2015/09/17]
    
    Zphase_countAB_flag = 0;
    Zphase_countAB_count = 0;
    Zphase_error_zero = 0;
    Zphase_tune_count = 0;

}

void STO_Truth_Table(void){

#if 1
    if(S1_C == 1){
       if(S2_C == 1){
           if(S1_DC == 1){   //|| P_5V == 0
               if(P_5V == 0){
                   STO3LOSS = 1;    //status14    
                   uw_STOStatus = 14;
               }
           }    
           else{          // S1_DC = 0
               if(P_5V == 1){
                   if(CC_S == 0){
                       STO3LOSS = 1; //status16   
                       uw_STOStatus = 16;
                   }
               }
               else{
                   STO3LOSS = 1;     //status15    
                   uw_STOStatus = 15;
               }
           }
       }
       else{          //S2_C = 0;
           if(S1_DC == 1){  //S1_DC = 1;
               if(P_5V == 1){    //+5Vp = 1
                   STO3LOSS = 1;     //status8 
                   uw_STOStatus = 8;
               }
               else{             
                   STO2LOSS = 1;     //status4   HLHL
                   uw_STOStatus = 4;
               }
           }    
           else{
               if(P_5V == 1){
                   STO3LOSS = 1;     //status9
                   uw_STOStatus = 9;
               }
               else{
                   STO3LOSS = 1;     //status10
                   uw_STOStatus = 10;
               } 
           }
       }
   }
   else{    // S1_C = 0;
       if(S2_C == 1){   //S2_C = 1;
           if(S1_DC == 1){  //S1_DC = 1
               if(P_5V == 1){    
                   STO3LOSS = 1;     //status5
                   uw_STOStatus = 5;
               }
               else{
                   STO3LOSS = 1;     //status6
                   uw_STOStatus = 6;
               }
           }
           else{            //S1_DC = 0
               if(P_5V == 1){   
                   STO1LOSS = 1;     //status3
                   uw_STOStatus = 3;
               }
               else{             
                   STO3LOSS = 1;     //status7
                   uw_STOStatus = 7;
               }
           }    
       }
       else{     //S2_C = 0
           if(S1_DC == 1){  //S1_DC = 1
               if(P_5V == 1){
                   STO3LOSS = 1;     //status12
                   uw_STOStatus = 12;
               }
               else{
                   STO3LOSS = 1;     //status11
                   uw_STOStatus = 11;
               }
           }
           else{
               if(P_5V == 1){  //+5Vp = 1
                   STO3LOSS = 1;     //status13
                   uw_STOStatus = 13;
               }
               else{             
                   STOLOSS = 1;      //status2   
                   uw_STOStatus = 2;
               }
           }
       }
   }


#else

    if((pr[STO_LOCK] < 4) || ((pr[STO_LOCK] == 4)&&(LIFT_RUNCMD == RUN))){ 
    if(S1_C == 1){
        if(S2_C == 1){
            if(S1_DC == 1){   //|| P_5V == 0
                if(P_5V == 0){
                    STO3LOSS = 1;    //status14    
                    uw_STOStatus = 14;
                }
            }    
            else{          // S1_DC = 0
                if(P_5V == 1){
                    if(CC_S == 0){
                        STO3LOSS = 1; //status16   
                        uw_STOStatus = 16;
                    }
                }
                else{
                    STO3LOSS = 1;     //status15    
                    uw_STOStatus = 15;
                }
            }
        }
        else{          //S2_C = 0;
            if(S1_DC == 1){  //S1_DC = 1;
                if(P_5V == 1){    //+5Vp = 1
                    STO3LOSS = 1;     //status8 
                    uw_STOStatus = 8;
                }
                else{             
                    STO2LOSS = 1;     //status4   HLHL
                    uw_STOStatus = 4;
                }
            }    
            else{
                if(P_5V == 1){
                    STO3LOSS = 1;     //status9
                    uw_STOStatus = 9;
                }
                else{
                    STO3LOSS = 1;     //status10
                    uw_STOStatus = 10;
                } 
            }
        }
    }
    else{    // S1_C = 0;
        if(S2_C == 1){   //S2_C = 1;
            if(S1_DC == 1){  //S1_DC = 1
                if(P_5V == 1){    
                    STO3LOSS = 1;     //status5
                    uw_STOStatus = 5;
                }
                else{
                    STO3LOSS = 1;     //status6
                    uw_STOStatus = 6;
                }
            }
            else{            //S1_DC = 0
                if(P_5V == 1){   
                    STO1LOSS = 1;     //status3
                    uw_STOStatus = 3;
                }
                else{             
                    STO3LOSS = 1;     //status7
                    uw_STOStatus = 7;
                }
            }    
        }
        else{     //S2_C = 0
            if(S1_DC == 1){  //S1_DC = 1
                if(P_5V == 1){
                    STO3LOSS = 1;     //status12
                    uw_STOStatus = 12;
                }
                else{
                    STO3LOSS = 1;     //status11
                    uw_STOStatus = 11;
                }
            }
            else{
                if(P_5V == 1){  //+5Vp = 1
                    STO3LOSS = 1;     //status13
                    uw_STOStatus = 13;
                }
                else{             
                    STOLOSS = 1;      //status2   
                    uw_STOStatus = 2;
                }
            }
        }
    }
    }
    else if(((pr[STO_LOCK] == 4)&&(LIFT_RUNCMD != RUN))){ 
    if(S1_C == 0){
        if(S2_C == 0){
            if(S1_DC == 0){   //|| P_5V == 0
                if(P_5V == 1){
                    STO3LOSS = 1;    //status14    
                    uw_STOStatus = 114;
                }
            }    
            else{          // S1_DC = 0
                if(P_5V == 0){
                    if(CC_S == 1){
                        STO3LOSS = 1; //status16   
                        uw_STOStatus = 116;
                    }
                }
                else{
                    STO3LOSS = 1;     //status15    
                    uw_STOStatus = 115;
                }
            }
        }
        else{          //S2_C = 0;
            if(S1_DC == 0){  //S1_DC = 1;
                if(P_5V == 0){    //+5Vp = 1
                    STO3LOSS = 1;     //status8 
                    uw_STOStatus = 108;
                }
                else{             
                    STO2LOSS = 1;     //status4   HLHL
                    uw_STOStatus = 104;
                }
            }    
            else{
                if(P_5V == 0){
                    STO3LOSS = 1;     //status9
                    uw_STOStatus = 109;
                }
                else{
                    STO3LOSS = 1;     //status10
                    uw_STOStatus = 110;
                } 
            }
        }
    }
    else{    // S1_C = 0;
        if(S2_C == 0){   //S2_C = 1;
            if(S1_DC == 0){  //S1_DC = 1
                if(P_5V == 0){    
                    STO3LOSS = 1;     //status5
                    uw_STOStatus = 105;
                }
                else{
                    STO3LOSS = 1;     //status6
                    uw_STOStatus = 106;
                }
            }
            else{            //S1_DC = 0
                if(P_5V == 0){   
                    STO1LOSS = 1;     //status3
                    uw_STOStatus = 103;
                }
                else{             
                    STO3LOSS = 1;     //status7
                    uw_STOStatus = 107;
                }
            }    
        }
        else{     //S2_C = 0
            if(S1_DC == 0){  //S1_DC = 1
                if(P_5V == 0){
                    STO3LOSS = 1;     //status12
                    uw_STOStatus = 112;
                }
                else{
                    STO3LOSS = 1;     //status11
                    uw_STOStatus = 111;
                }
            }
            else{
                if(P_5V == 0){  //+5Vp = 1
                    STO3LOSS = 1;     //status13
                    uw_STOStatus = 113;
                }
                else{             
                    STOLOSS = 1;      //status2   
                    uw_STOStatus = 102;
                }
            }
        }
    }
    }
#endif
}

void ErrorAutoReset(void){ //[Add auto restart after fault, Bernie, 06/06/12]
    /*================= Fault Reset Function ===================*/
	//[Add GFF and Ocx auto reset function, Jerry Yu, 2019/05/23]
	//	|
	//	V
	if((Error>=LvA_ERR && Error<=Lvn_ERR) || Error==PHL_ERR || (Error>=ovA_ERR && Error<=ovS_ERR) || (Error>=ocA_ERR && Error<=GFF_ERR) || (Error==ocS_ERR) ){
		if (ubIntervalSeted==0){
			if ((Error>=ocA_ERR && Error<=GFF_ERR) || (Error==ocS_ERR)){
				if (pr[RESETINTERVAL]<55){//lower than 5.5 sec				
					uwRetryTimeCnt = (50+1)*10;	//Only OC and GFF has minimum 5.1 sec reset interval, modify by Jerry Yu, 2019/05/23
				}
				else{
					uwRetryTimeCnt = pr[RESETINTERVAL]*10;
				}
			}
			else{
            	uwRetryTimeCnt = pr[RESETINTERVAL]*10;
			}
			ubIntervalSeted=1;
		}
        if(pr[RESETCNT]!=0){
            if((mfi_status&0x0003)== 0x0000){
                RST_EN = 1;
            }
            else{
                RST_EN = 0;
				if ((Error>=ocA_ERR && Error<=GFF_ERR) || (Error==ocS_ERR)){
					if (pr[RESETINTERVAL]<55){//lower than 5.5 sec
						uwRetryTimeCnt = (50+1)*10;	//Only OC and GFF has minimum 5.1 sec reset interval, modify by Jerry Yu, 2019/05/23
					}
					else{
						uwRetryTimeCnt = pr[RESETINTERVAL]*10;
					}
				}
				else{
                	uwRetryTimeCnt = pr[RESETINTERVAL]*10;
				}
            }
        }
    }


    if(RST_CNT_OK==1){   //10min count
        uwReset_10mCnt++;
    }

    if(RST_EN==1){                   //[Add auto restart after fault, Bernie, 06/06/12]
        if(uwRetryTimeCnt==0){
            if(pr[RESETCNT]!=0){
                uwRetryCnt--;
                reset();   // Reset Error

                RST_CNT_OK = 1;            //10min count start after error
                pr[RESETCNT] = uwRetryCnt;
				ubIntervalSeted=0;
                uwReset_10mCnt = 0;
            }
            else{
                pr[RESETCNT] = 0;
                uwRetryCnt = pr[RESETCNT];
                uwRetryTimeCnt = 0;     //if retry count=0,then retry count interval will stop to calculate
            }

            RST_EN = 0;                 //clear retry Enable then to detect the Error again
        }
        else{
            uwRetryTimeCnt--;
            uwReset_10mCnt = 0;   //10min count
        }
    }
    else{      //if(RST_EN==0)
        if(uwReset_10mCnt==TEN_MINS_CNT && RST_CNT_OK==1){
            RST_CNT_OK = 0;
            pr[RESETCNT] = rec_uwRetryCnt;
            uwRetryCnt = rec_uwRetryCnt;
            uwReset_10mCnt = 0;     //10min count
        }
    }   // end fault reset function

}

void OverAccFunction(void){                //[Over Acceleration protection function, Bernie, 2017/02/13]
    UWORD uwAccTemp;
    
    if(uwAcc10msCount<10){
        uwAcc10msCount++;
    }
    else{
        uwAcc10msCount = 0;
        if ((pr[PGINPUT]!=0)){
            DINT();
            if (SpDt_slSpdFdbPu >=0){
                uwAccTemp = abs((SLONG)COF_uwFbRe * (SpDt_slSpdFdbPu>>15))>>14;
            }
            else{
                uwAccTemp = abs((ULONG)COF_uwFbRe * (-SpDt_slSpdFdbPu>>15))>>14;
            }
            AccTemp_LPF.sl += (uwAccTemp - AccTemp_LPF.sw.hi)*(6553); // Lowpass
            //uwAccTemp = Hz2Metric(uwAccTemp);
            //SpDt_uwAccCalcul = Hz2Metric(AccTemp_LPF.sw.hi);
            SpDt_uwAccOpt = abs(AccTemp_LPF.sw.hi - SpDt_uwAccCalculOld);
        
            SpDt_uwAccCalculOld = AccTemp_LPF.sw.hi;   //
            EINT();



            //====== Over Acceleration detect ==============//
	        if ((pr[OVER_ACC_LEVEL]!=0)&&(TqSpdMode==0)){
       	        if ((SpDt_uwAccOpt) > uwOverAccLev){
                    if(uwOverAccCnt<= OverAccTimeSet){
                        uwOverAccCnt ++;
                    }
                    else{   
                        Error = OVERACC_ERR;	
                    }	        
                }
                else{
                    if(uwOverAccCnt < OverAccTimeSet){
                        uwOverAccCnt = 0;
                    }	   
    	        }
            }
            //==============================================//
        }
        else{
            SpDt_uwAccOpt = 0;
            SpDt_uwAccCalcul = 0;
            SpDt_uwAccCalculOld = 0;
        }

    }   
   
    
}

void OverAccInit(void){      //[Over Acceleration protection function, Bernie, 2017/02/13]

    AccTemp_LPF.sl = 0 ;
    uwAcc10msCount = 0;
    SpDt_uwAccOpt = 0;
    uwOverAccCnt = 0;
    SpDt_uwAccCalcul = 0;
    SpDt_uwAccCalculOld = 0;
    OverAccTimeSet = pr[OVER_ACC_TIME];
    uwOverAccLev = (((ULONG)(pr[OVER_ACC_LEVEL])*(pr[MFBASE1]/10))/(pr[Lift_SPD]))<<2;
}

void Torq_Tune_Process(void){  //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
    if((pr[CTRLM]==FOCPG)||(pr[CTRLM]==FOCPM)){
        if(AUI_TUNE){
            TB1_uwMaxFout++;
            if(TB1_uwMaxFout>=5000){
                TB1_uwMaxFout = 0;
                if(!AUI_TUNE_FINISH){
                    if(pr[LOCELTUN]==1){
                        AUI_swem_V = swAVICalib;
                        AUI_swem_T = swTqInPu_Mon;
                        AUI_TUNE_FINISH = 1;
                        AUI_TUNE = 0;
                        P03_15(LOCELTUN,0);
                    }
                    else if(pr[LOCELTUN]==2){
                        AUI_swfl_V = swAVICalib;
                        AUI_swfl_T = swTqInPu_Mon;
                        AUI_TUNE_FINISH = 1;
                        AUI_TUNE = 0;
                    }
                }
            }
        }
    }
}

#ifdef _TB_1ms_C
  #undef _TB_1ms_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
