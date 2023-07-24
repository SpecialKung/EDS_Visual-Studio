//****************************************************************/
//  @File Name: Keypad.C
//  @Description: This file contains standard keypad interface
//                and Key-in & LED display process.
//  @Partner file: Keypad.H
//  @Project: Wizard
//  @Compiler: HEW V3.0 for H8/3687F
//  @Company:  Delta Elec.INC.  CopyRight 2004
//****************************************************************/
/*-----------------------------start of file---------------------*/
#ifndef _MFIO_C
    #define _MFIO_C
#endif
/*----------------------------------------------------------------*/

//*****************************************************************/
// @Project Includes
//*****************************************************************/
/* Include File ===============================================*/
#include "ProgHeader.h"


void (*const mfi0_tbl[3])(UWORD chg,UWORD k) = {
        di_sub0, di_sub1, di_sub2,
};
void (*const mfi1_tbl[(MFIMAX+1)])(UWORD chg,UWORD k) = {

#if NEWPARA
		no_func,        //0: No Function
        mispeed1,       //1: MI speed 1
        mispeed2,		//2: MI speed 2        
        mispeed3,       //3: MI speed 3
        mispeed4,       //4: MI speed 4
		extreset,       //5: Reset
		extjog,			//6: JOG
		speedhold,      //7: Speed Hold
		acc_dec_chg1,	//8: Accel_1/decel_1 change to Accel_2/ decel_2
		acc_dec_chg2,	//9: Accel_3/decel_3 change to Accel_4/ decel_4
        efnc,           //10:Exteral Fault, EF normal close
        no_func,        //11:Base Block
        outputoff,		//12:Output OFF
        cancel_AAAD,	//13:Cancel Auto-Accel/Decel  function
        no_func,		//14:Motor 1 change to motor 2
        AUI1_SOFC,		//15:Frequency Command from AUI1
        no_func,        //ACI_SOFC,//16:Frequency Command from ACI      //[ACI function remove, Bernie, 01/20/2012]
        AUI2_SOFC,		//17:Frequency Command from AUI2
        ForceRampStop,	//18:Force Ramp Stop
        no_func,		//19:Up command
        no_func,		//20:Down command
        no_func,		//21:PID disable
        no_func,		//22:Counter input
        no_func,		//23:Cleat Counter
        FWD_JOG,		//24:FWD JOG
        REV_JOG,		//25:REV JOG
        no_func,		//26:Torque mode t0 Speed mode
        ASR1_ASR2,		//27:ASR1 to ASR2
        ef1nc,  		//28:Emergency Stop (EF1)
        no_func,		//29:Y-Connected check(MFI_YCONCHK)
        no_func,		//30:Delta-Connected Check(MFI_DCONCHK)
        TqOfstHigh,     //31:Torque offset compensation High
        TqOfstMiddle,   //32:Torque offset compensation Middle
        TqOfstLow,      //33:Torque offset compensation Low
        no_func,		//34:MI Speed/MI Position
        no_func,		//35:APR Control Enable
        no_func,		//36:MI position Enter
        no_func,		//37:PG Ref2 ON (Position Mode)
        WriteEPDisable,	//38:Write to EEPROM disable
        TqSetDirection,	//39:direction of Torque command
        ForceCoastStop,	//40:Force Coast Stop
        MCCHKEnable,	//41:Megnetic Contactor Signal
        BKCHKEnable1,	//42:Mechanical Brake Signal  1   //[change for EN81-1+A3, Bernie, 2015/03/16]
        EPSEnable,		//43:EPS enable
        BKCHKEnable2,	//44:Mechanical Brake Signal  2   //[change for EN81-1+A3, Bernie, 2015/03/16]
       	
       	//DLC function, Henry, 2016/07/20 [
       	DLC_LU,         //45:DLC LU
       	DLC_LD,	        //46:DLC LD         
       	DLC_CANOFF,     //47:DLC CAN Off  
       	DLC_LOW_SPD,    //48:DLC Low Speed
       	DLC_FSD,        //49:FSD Mode
       	DLC_DDS,        //50:DDS1
       	DLC_UDS,        //51:UDS1
       	DLC_DZN,        //52:DZN   adco
       	//]  
        IODLC_CRPLS_IO, //53:IODLC_CRPLS // [IODLC, Lyabryan, 2016/11/11]
        EPS_MI_DETCT,   //54:EPS_MI_DETCT //[EPS MO Output,Lyabryan,2018/06/19]
        SMTRISE_ESD,    //55:ESD //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
        SMTRISE_ETS,    //56:ETS //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
        MI_Sensor819,	//57Sensor819 //[Artemis Add top and ground floor Switch Function/Special/2022/06/06]
        Torq_Detect,	//58:Torq Detect [JES Torq Detect Function, Special.Kung, 2022/09/01]
		AFE_ERRFBK,	    //59:AFE Error Triger //[AFE Error Handle/Lyabryan/2022/03/24]
#else
		no_func,        //0: No Function
        mispeed1,       //1: MI speed 1
        mispeed2,		//2: MI speed 2        
        mispeed3,       //3: MI speed 3
        mispeed4,       //4: MI speed 4
		extreset,       //5: Reset
		extjog,			//6: JOG
		speedhold,      //7: Speed Hold
		acc_dec_chg1,	//8: Accel_1/decel_1 change to Accel_2/ decel_2
		acc_dec_chg2,	//9: Accel_3/decel_3 change to Accel_4/ decel_4
        efnc,           //10:Exteral Fault, EF normal close
        bb_up,          //11:Base Block
        outputoff,      //12:Output OFF
        cancel_AAAD,	//13:Cancel Auto-Accel/Decel  function
        motor1_2,		//14:Motor 1 change to motor 2
        AUI1_SOFC,		//15:Frequency Command from AUI1
        ACI_SOFC,		//16:Frequency Command from ACI
        AUI2_SOFC,		//17:Frequency Command from AUI2
        ForceRampStop,	//18:Force Ramp Stop
        incspeed,		//19:Up command
        decspeed,       //20:Down command
        piddis,       	//21:PID disable
        CNT_CLR,		//22:Counter input
        CNT_IN,	        //23:Cleat Counter
        FWD_JOG,		//24:FWD JOG
        REV_JOG,		//25:REV JOG
        TRQ_2_SPD,		//26:Torque mode t0 Speed mode
        ASR1_ASR2,		//27:ASR1 to ASR2
        ef1nc,  		//28:Emergency Stop (EF1)
        YconnectCHK,    //29:Y-Connected check(MFI_YCONCHK)
        DconnectCHK,    //30:Delta-Connected Check(MFI_DCONCHK)
        TqOfstHigh,     //31:Torque offset compensation High
        TqOfstMiddle,   //32:Torque offset compensation Middle
        TqOfstLow,      //33:Torque offset compensation Low
        MISpdPosChang,	//34:MI Speed/MI Position
        APREnable,		//35:APR Control Enable
        MIPosEnter,		//36:MI position Enter
        PG2RefPosMode,	//37:PG Ref2 ON (Position Mode)
        WriteEPDisable,	//38:Write to EEPROM disable
        TqSetDirection,	//39:direction of Torque command
        ForceCoastStop,	//40:Force Coast Stop
        no_func,		//41:Position Command Clock
        no_func,		//42:Position Data 
        VcomPosition,	//43:Position by Vcom
#endif         
};

/*-----------------------------------------------------------------------------------------
 -      mfo jump table
 ------------------------------------------------------------------------------------------*/
UWORD (*const mfo_tbl[(MFOMAX+1)])(UWORD pin, UWORD k) = {

#if	NEWPARA
    mfo_none,           // 0: Not used
    mfo_running,        // 1: Inverter Running //
    mfo_atmaxf_Band,    // 2: At Setpoint Speed
    mfo_atspeed1,       // 3: At Speed 1 //
    mfo_atspeed2,       // 4: At Speed 2 //
    mfo_fcmdzero,       // 5: Zero Speed at Drive Running
    mfo_fcmdzerostp,    // 6: Zero Speed, include drive stop
    mfo_overtq1,        // 7: Over Torque Dectted 1) //
    mfo_overtq2,        // 8: Over Torque Dectted 2) //
    mfo_ready,          // 9: Ready
    mfo_lv,             //10: Low voltage indication
    mfo_fault,          //11: Inverter Fault //
    mfo_braker_release, //12: Braker release
    mfo_ohalarm,        //13: OH alarm
    mfo_SWbrakeOut,     //14: SW brake Output
    mfo_LiftEnable,     //15: lift enable
    mfo_overslip,       //16: Over Slip
    mfo_Fault2,     	//17: Fault Output including delay time, Add by DINO, 10/24/2008
    mfo_none,           //18: 
    mfo_bf,             //19: BF error, dino, 12/13/2007
    mfo_warning,        //20: All of Warning
    mfo_ovalarm,        //21: Ov alarm
    mfo_ocsalarm,       //22: Oc stall alarm
    mfo_ovsalarm,       //23: Ov stall alarm
    mfo_opmode,         //24: Operation Mode
    mfo_fwdcmd,         //25: Fwd command //
    mfo_revcmd,         //26: Rev command //
    mfo_abv_curt,       //27: Above Current Output
    mfo_low_curt,       //28: below Current Output
    mfo_abv_spa,        //29: Above Speed Area
    mfo_low_spa,        //30: below Speed Area
    mfo_gen_ok,         //31: Generation Operation detected ok
    mfo_gen_dir,        //32: Generation Operation Direction
    mfo_foutzero,		//33: fout, zero speed at drive running
    mfo_foutzerostp,	//34: fout, zero speed including drive stop
    mfo_faultoption1,	//35: Fault option 1, refer to 06-23
    mfo_faultoption2,	//36: Fault option 2, refer to 06-24
    mfo_faultoption3,	//37: Fault option 3, refer to 06-25
    mfo_faultoption4,	//38: Fault option 4, refer to 06-26
    mfo_none,           //39: 
    mfo_atFSET_Band,	//40: At Setpoint Speed
    mfo_none,			//41: 
    mfo_STO_OUT,        //42: STO logic1
    mfo_DLC_UP,         //43: DLC UP  //DLC function, Henry, 2016/07/20
    mfo_DLC_DN,         //44: DLC DN  //DLC function, Henry, 2016/07/20
    //mfo_STO2,         //:STO logic2
    //mfo_braker_release2,//DIN function
    mfo_IMEnable,       //45:
    mfo_fault_rst,      //46: retry
    //DLC function, Henry, 2016/07/20
    mfo_DLCLevOn,       //47: Car Stop and Level Sensor Enable ON Flag
    mfo_star_Contactor, //48
    
    mfo_EPS_MODE,       //49:Lift enable, WTL, 20170621 //[EPS MO Output,Lyabryan,2018/06/19]
    mfo_abv_PGspa,      //50:PG speed Above Speed Area for  NRG, #16698//James, 2021/08/09
    mfo_Torq_Detect,	//51:Torq Detect [JES Torq Detect Function, Special.Kung, 2022/09/01]
	mfo_AFE_RST,       // 52: AFE RST //[AFE Error Handle/Lyabryan/2022/03/24]
#else 
    mfo_none,           // 0: Not used
    mfo_running,        // 1: Inverter Running //
    mfo_atmaxf,         // 2: At Setpoint Speed
    mfo_atspeed1,       // 3: At Speed 1 //
    mfo_atspeed2,       // 4: At Speed 2 //
    mfo_fcmdzero,       // 5: Zero Speed at Drive Running
    mfo_fcmdzerostp,    // 6: Zero Speed, include drive stop
    mfo_overtq1,        // 7: Over Torque Dectted 1) //
    mfo_overtq2,        // 8: Over Torque Dectted 2) //
    mfo_ready,          // 9: Ready
    mfo_lv,             //10: Low voltage indication
    mfo_fault,          //11: Inverter Fault //
    mfo_braker_release, //12: Braker release
    mfo_ohalarm,        //13: OH alarm
    mfo_SWbrakeOut,     //14: SW brake Output
    mfo_pidalarm,       //15: PID Deviation Alarm //
    mfo_overslip,       //16: Over Slip
    mfo_trgdone,        //17: Trigger attained
    mfo_trgpre,         //18: Preliminary conter attained
    mfo_bb,             //19: bb indication
    mfo_warning,        //20: All of Warning
    mfo_ovalarm,        //21: Ov alarm
    mfo_ocsalarm,       //22: Oc stall alarm
    mfo_ovsalarm,       //23: Ov stall alarm
    mfo_opmode,         //24: Operation Mode
    mfo_fwdcmd,         //25: Fwd command //
    mfo_revcmd,         //26: Rev command //
    mfo_abv_curt,       //27: Above Current Output
    mfo_low_curt,       //28: below Current Output
    mfo_abv_spa,        //29: Above Speed Area
    mfo_low_spa,        //30: below Speed Area
    mfo_chg2Y,			//31: Change to Y-Connected(MFO_YCON)
    mfo_chg2D,          //32: Change to Delta-connected(MFO_DCON)
    mfo_foutzero,		//33: fout, zero speed at drive running
    mfo_foutzerostp,	//34: fout, zero speed including drive stop
    mfo_faultoption1,	//35: Fault option 1, refer to 06-23
    mfo_faultoption2,	//36: Fault option 2, refer to 06-24
    mfo_faultoption3,	//37: Fault option 3, refer to 06-25
    mfo_faultoption4,	//38: Fault option 4, refer to 06-26
    mfo_OnPosition,		//39: On Position
    mfo_atFSET,			//40: At Setpoint Speed
    mfo_multiposition,	//41: multi position output
#endif 
};
/*
#define DI_FWD_PIN  PE.DR.BIT.B8
#define DI_REV_PIN  PE.DR.BIT.B10
#define DI_1_PIN    PE.DR.BIT.B7
#define DI_2_PIN    PE.DR.BIT.B6
#define DI_3_PIN    PE.DR.BIT.B5
#define DI_4_PIN    PE.DR.BIT.B4
#define DI_5_PIN    PE.DR.BIT.B3
#define DI_6_PIN    PE.DR.BIT.B2
*/
void mfi_Pin(void)
{

	
    UWORD ax = 0;
	
    //    DI6---DI5---DI4---DI3---DI2---DI1---REV---FWD 
    //bit: 7     6     5     4     3     2     1     0
    //    PE.2  PE.3  PE.4  PE.5  PE.6  PE.7  PE.10 PE.8 
    if (DI_FWD_PIN==0)
        ax |= EXT_FWD;
    else
        ax &= (0xffff-EXT_FWD);    
    if (DI_REV_PIN==0)
        ax |= EXT_REV;
    else
        ax &= (0xffff-EXT_REV);    
    if (DI_1_PIN==0)
        ax |= EXT_DI1;
    else
        ax &= (0xffff-EXT_DI1);        	        
    if (DI_2_PIN==0)
        ax |= EXT_DI2;
    else
        ax &= (0xffff-EXT_DI2);    
    if (DI_3_PIN==0)
        ax |= EXT_DI3;
    else
        ax &= (0xffff-EXT_DI3);    
    if (DI_4_PIN==0)
        ax |= EXT_DI4;
    else
        ax &= (0xffff-EXT_DI4);    
    if (DI_5_PIN==0)
        ax |= EXT_DI5;
    else
        ax &= (0xffff-EXT_DI5);    
    if (DI_6_PIN==0)
        ax |= EXT_DI6;
    else
        ax &= (0xffff-EXT_DI6);    
#if SH7147  // dino, 04/03/2007
    if (DI_7_PIN==0)
        ax |= EXT_DI7;
    else
        ax &= (0xffff-EXT_DI7);    
    if (DI_8_PIN==0)
        ax |= EXT_DI8;
    else
        ax &= (0xffff-EXT_DI8);    
#endif    
    mfi_now = ax | (pr[MI_STATE] << 10) ;  // Modify by dino, 09/11/2007
}    

void CHK_DI_State(void)        // Execute once 1ms
{
        
    mfi_Pin();
    if (mfi_buf!=mfi_now){
        DIstCNT = 0;
        mfi_buf = mfi_now;
    }
    else{
        if (DIstCNT >= pr[DIN_RES])	//unit of pr[DIN_RES] is 0.001sec
            MFI_CHG = 1;		// Port status change
        else
            DIstCNT++;
    }
        
    // ------TRG function Enable------
    if (pr[CNTCPL] != 0){
        if (TRGRST == 0){
            if (TRGEN == 1){
                if (((mfi_now^pr[MI_INV])&EXT_DI6)==EXT_DI6){   //DI6(0x04), Low Active
                    if (TRGST==0){
                        TRGST = 1;        // TRG START
                        if (trg_cnt>=pr[CNTCPL])
                            trg_cnt = 0;
                        trg_cnt++;
                    }
                }
                else{
                   TRGST = 0;
                   if (trg_cnt>=pr[CNTCPL])
                       trg_cnt = 0;
                }    
            }
        }
    }
    if ((uwPcomClkMI!=0)&&(uwPcomDataMI!=0)){
        if (((mfi_now^pr[MI_INV])&uwPcomClkMI)==uwPcomClkMI){	//low active
        	EXT_PcomCLK = 1;
		}
        else{
        	EXT_PcomCLK = 0;
		}
        
        if (((mfi_now^pr[MI_INV])&uwPcomDataMI)==uwPcomDataMI){	//low active
        	EXT_PcomData = 1;
		}
        else{
        	EXT_PcomData = 0;		        
		}
		
        if ((SPIPcomCNT==0)&&(EXT_PcomCLK==0)&&(EXT_PcomData==0)){
        	EXT_SPIPcomGO = 1;
			SPIPcomBit = 0x01;
			uwSPIPcom = 0;
			SPIPcomCNT = 0;
		}

		if (EXT_SPIPcomGO==1){
			if (SPIPcomCNT<=11){
				if ((SPIPcomBit==0x01)&&(EXT_PcomCLK==1)){
					if (EXT_PcomData==1){
					  	#if 1
					  		uwSPIPcom |= (0x0001<<SPIPcomCNT);
					  	#else
							if (SPIPcomCNT==0)
								uwSPIPcom = 0x0001;
							else if (SPIPcomCNT==1)
								uwSPIPcom = uwSPIPcom + 0x0002;
							else if (SPIPcomCNT==2)
								uwSPIPcom = uwSPIPcom + 0x0004;
							else if (SPIPcomCNT==3)
								uwSPIPcom = uwSPIPcom + 0x0008;
							else if (SPIPcomCNT==4)
								uwSPIPcom = uwSPIPcom + 0x0010;
							else if (SPIPcomCNT==5)
								uwSPIPcom = uwSPIPcom + 0x0020;
							else if (SPIPcomCNT==6)
								uwSPIPcom = uwSPIPcom + 0x0040;
							else if (SPIPcomCNT==7)
								uwSPIPcom = uwSPIPcom + 0x0080;
							else if (SPIPcomCNT==8)
								uwSPIPcom = uwSPIPcom + 0x0100;
							else if (SPIPcomCNT==9)
								uwSPIPcom = uwSPIPcom + 0x0200;
							else if (SPIPcomCNT==10)
								uwSPIPcom = uwSPIPcom + 0x0400;
							else if (SPIPcomCNT==11)
								uwSPIPcom = uwSPIPcom + 0x0800;
					  	#endif				
					}
					SPIPcomCNT++;
					SPIPcomBit = 0x02;
				}					
				else if ((SPIPcomBit==0x02)&&(EXT_PcomCLK==0)){
					SPIPcomBit = 0x01;
				}
			}
	    	else{
				if ((EXT_PcomCLK==1)&&(EXT_PcomData==1)){
		    		//	if (SPIPcomCNT>=30){
		    		EXT_SPIPcomGO = 0;
		    		pr[PGHOME] = uwSPIPcom;
		    		SPIPcomBit = 0;
		    		SPIPcomCNT = 0;
		    		//	}
		    		//	else{
		    		//		SPIPcomCNT ++;
		    		//	}
				}
	    	}
        }
    }
}

/*-----------------------------------------------------------------------------------------
 -      Multi Function Input Process
 ------------------------------------------------------------------------------------------*/

void mfi_process(void)
{
    UBYTE j;
    UWORD  mix_chg,k, uwtemp;

    void (*mfi_ptr)(UWORD ,UWORD);

    if (MFI_CHG==1){
		MFI_CHG = 0;
		DINT();
		mix_chg = (mfi_old^mfi_buf);
		mfi_old = mfi_buf;
		EINT();
        // NOTE !!
        // (mfi_old, mfi_buf) = (RUN,RUN) in line 1
        // if mfi_buf becomes STOP at interrupt function between line 1 and line 2.
        // (mfi_old, mfi_buf) = (STOP,STOP) in line 2
        // Drive should stop but chg is 0, so keep running!
        // We disable interrput to prevent it !
        for (j=0;j<=15;j++) {
            if ((j<=1)||((j==2)&&(pr[WIRE2_3]>=4))){  	// 3 line operatation
//              if ((pr[SOOC]==1||pr[SOOC]==2)) 		// Source of operation command
				if ((pr[CAN_CTRL]==0)&&(pr[SOOC]==1 && PUEN3==0 && PUEN2 ==0)){ 	//[CAN Control, Sampo, 09/15/2010]
                    mfi_ptr = mfi0_tbl[(pr[WIRE2_3]>>1)];	// 2,3 wire
                    if (pr[WIRE2_3]>=4)					// 3 line operatation
                      	k = ((mfi_old^pr[MI_INV])&(EXT_FWDREV|EXT_DI1));
                    else
                       	k = ((mfi_old^pr[MI_INV])&(EXT_FWDREV));
                       	
                    (*mfi_ptr)((mix_chg&_16BitTab[j]),k);
                }
            }
            else{
#if 0
              	if (j<=7){
	            	if (pr[(MI1-2)+j] <= MFIMAX){    // Max item of Multi-Input
	                	mfi_ptr=mfi1_tbl[pr[(MI1-2)+j]];
	                	k = ((mfi_old^pr[MI_INV])&_16BitTab[j]);
	                	//if ( j==2 )
	                	uwtemp = k;    
	                	(*mfi_ptr)((mix_chg&_16BitTab[j]),uwtemp);
	            	}
				}
				else if ((j>7)&&(j<=15)){
		    		if (pr[MI7+(j-8)] <= MFIMAX){    // Max item of Multi-Input
	                	mfi_ptr=mfi1_tbl[pr[MI7+(j-8)]];
	                	k = ((mfi_old^pr[MI_INV])&_16BitTab[j]);
	                	
	                	(*mfi_ptr)((mix_chg&_16BitTab[j]),k);
	            	}
				}    

#else
              	if (j<=9){
	            	if (pr[(MI1-2)+j] <= MFIMAX){    // Max item of Multi-Input
	                	mfi_ptr=mfi1_tbl[pr[(MI1-2)+j]];
	                	k = ((mfi_old^pr[MI_INV])&_16BitTab[j]);
	                	(*mfi_ptr)((mix_chg&_16BitTab[j]),k);
	            	}
				}
				else {
		    		if (pr[MI9+(j-10)] <= MFIMAX){    // Max item of Multi-Input
	                	mfi_ptr=mfi1_tbl[pr[MI9+(j-10)]];
	                	k = ((mfi_old^pr[MI_INV])&_16BitTab[j]);

	                	(*mfi_ptr)((mix_chg&_16BitTab[j]),k);
	            	}
				}    

#endif
			}
		}
    }
}

#define EXT_RLY1	0x0001
#define EXT_RLY2    0x0002
#define EXT_RLY3    0x0004
#define EXT_RLY4    0x0008
#define EXT_RLY5    0x0010
#define EXT_RLY6    0x0020
#define EXT_RLY7    0x0040
#define EXT_RLY8    0x0080
#define EXT_RLYE1   0x0100
#define EXT_RLYE2   0x0200
#define EXT_RLYE3   0x0400
#define EXT_RLYE4   0x0800
#define EXT_RLYE5   0x1000
#define EXT_RLYE6   0x2000
#define EXT_RLYE7   0x4000
#define EXT_RLYE8   0x8000
/*
#define DO_RLY1_PIN PD.DRL.BIT.B0
#define DO_RLY2_PIN PA.DRL.BIT.B15
#define DO_MO1_PIN  PD.DRL.BIT.B2
#define DO_MO2_PIN  PD.DRL.BIT.B1
*/
void mfo_Pin(void)
{
    UWORD ax=0;
    if (DO_RLY1_PIN==0)          //[Inverse output , Bernie, 03/29/2012]
        ax |= EXT_RLY1;
    else
        ax &= (0xffff-EXT_RLY1);
    if (DO_RLY2_PIN==0)          //[Inverse output , Bernie, 03/29/2012]
        ax |= EXT_RLY2;
    else
        ax &= (0xffff-EXT_RLY2); 
    if (DO_RLY3_PIN==0)          //[Inverse output , Bernie, 03/29/2012]
        ax |= EXT_RLY3;
    else
        ax &= (0xffff-EXT_RLY3);
    if (DO_RLY4_PIN==0)          //[Inverse output , Bernie, 03/29/2012]
        ax |= EXT_RLY4;
    else
        ax &= (0xffff-EXT_RLY4); 
    if (DO_RLY5_PIN==0)          //[Inverse output , Bernie, 03/29/2012]
        ax |= EXT_RLY5;
    else
        ax &= (0xffff-EXT_RLY5); 
    if (DO_RLY6_PIN==0)          //[Inverse output , Bernie, 03/29/2012]
        ax |= EXT_RLY6;
    else
        ax &= (0xffff-EXT_RLY6); 
        
//-- Add by Dino, 2008/02/29
    //[ //[New addition IO card,Lyabryan,2019/07/22]
    if (DO_RLY7_PIN==0)
        ax |= EXT_RLY7;
    else
        ax &= (0xffff-EXT_RLY7); 
    if (DO_RLY8_PIN==0)
        ax |= EXT_RLY8;
    else
        ax &= (0xffff-EXT_RLY8); 
    if (DO_RLY9_PIN==0)
        ax |= EXT_RLYE1;
    else
        ax &= (0xffff-EXT_RLYE1); 
    if (DO_RLY10_PIN==0)
        ax |= EXT_RLYE2;
    else
        ax &= (0xffff-EXT_RLYE2); 
	//] //[New addition IO card,Lyabryan,2019/07/22]
 /*   if (DO_MO7_PIN==0)
        ax |= EXT_RLY8;
    else
        ax &= (0xffff-EXT_RLY9); 
    if (DO_MO8_PIN==0)
        ax |= EXT_RLY9;
    else
        ax &= (0xffff-EXT_RLY10); 
    if (DO_MO9_PIN==0)
        ax |= EXT_RLY10;
    else
        ax &= (0xffff-EXT_RLY11); 
    if (DO_MO10_PIN==0)
        ax |= EXT_RLY11;
    else
        ax &= (0xffff-EXT_RLY12); */
//-- End 2008/02/29
    mfo_now = ax;    
}

void mfo_OFF(UWORD k)
{
   DINT();
    switch (k){
        case EXT_RLY1:
            DO_RLY1_PIN = 1;      //[Inverse output , Bernie, 08/17/2011]
            mfo_now &= (0xffff-EXT_RLY1);
        break;
        case EXT_RLY2:
            DO_RLY2_PIN = 1;      //[Inverse output , Bernie, 08/17/2011]
            mfo_now &= (0xffff-EXT_RLY2);
        break;
        case EXT_RLY3:
            DO_RLY3_PIN = 1;      //[Inverse output , Bernie, 08/17/2011]
            mfo_now &= (0xffff-EXT_RLY3);
        break;
        case EXT_RLY4:
            DO_RLY4_PIN = 1;      //[Inverse output , Bernie, 08/17/2011]
            mfo_now &= (0xffff-EXT_RLY4);
        break;
         case EXT_RLY5:
            DO_RLY5_PIN = 1;      //[Inverse output , Bernie, 08/17/2011]
            mfo_now &= (0xffff-EXT_RLY5);
        break;
        case EXT_RLY6:
            DO_RLY6_PIN = 1;      //[Inverse output , Bernie, 08/17/2011]
            mfo_now &= (0xffff-EXT_RLY6);
        break;
//-- Add by Dino, 2008/02/29
        //[ //[New addition IO card,Lyabryan,2019/07/22]
        case EXT_RLY7:
            DO_RLY7_PIN = 1;
            mfo_now &= (0xffff-EXT_RLY7);
        break;
        case EXT_RLY8:
            DO_RLY8_PIN = 1;
            mfo_now &= (0xffff-EXT_RLY8);
        break;
        case EXT_RLYE1:
            DO_RLY9_PIN = 1;
            mfo_now &= (0xffff-EXT_RLYE1);
        break;
        case EXT_RLYE2:
            DO_RLY10_PIN = 1;
            mfo_now &= (0xffff-EXT_RLYE2);
        break;
		//] //[New addition IO card,Lyabryan,2019/07/22]
/*        case EXT_MO7:
            DO_MO7_PIN = 1;
            mfo_now &= (0xffff-EXT_MO7);
        break;
        case EXT_MO8:
            DO_MO8_PIN = 1;
            mfo_now &= (0xffff-EXT_MO8);
        break;
        case EXT_MO9:
            DO_MO9_PIN = 1;
            mfo_now &= (0xffff-EXT_MO9);
        break;
        case EXT_MO10:
            DO_MO10_PIN = 1;
            mfo_now &= (0xffff-EXT_MO10);
        break;*/
//-- End 2008/02/29
        default:
        break;
    }
    EINT();
}
void mfo_ON(UWORD k)
{
    DINT();
    switch (k){
        case EXT_RLY1:
            DO_RLY1_PIN = 0;     //[Inverse output , Bernie, 08/17/2011]
            mfo_now |= EXT_RLY1;
        break;
        case EXT_RLY2:
            DO_RLY2_PIN = 0;     //[Inverse output , Bernie, 08/17/2011]
            mfo_now |= EXT_RLY2;
        break;
        case EXT_RLY3:
            DO_RLY3_PIN = 0;     //[Inverse output , Bernie, 08/17/2011]
            mfo_now |= EXT_RLY3;
        break;
        case EXT_RLY4:
            DO_RLY4_PIN = 0;     //[Inverse output , Bernie, 08/17/2011]
            mfo_now |= EXT_RLY4;
        break;
        case EXT_RLY5:
            DO_RLY5_PIN = 0;     //[Inverse output , Bernie, 08/17/2011]
            mfo_now |= EXT_RLY5;
        break;
        case EXT_RLY6:
            DO_RLY6_PIN = 0;     //[Inverse output , Bernie, 08/17/2011]
            mfo_now |= EXT_RLY6;
        break;
//-- Add by Dino, 2008/02/29
        //[ //[New addition IO card,Lyabryan,2019/07/22]
        case EXT_RLY7:
            DO_RLY7_PIN = 0;
            mfo_now |= EXT_RLY7;
        break;
        case EXT_RLY8:
            DO_RLY8_PIN = 0;
            mfo_now |= EXT_RLY8;
        break;
        case EXT_RLYE1:
            DO_RLY9_PIN = 0;
            mfo_now |= EXT_RLYE1;
        break;
        case EXT_RLYE2:
            DO_RLY10_PIN = 0;
            mfo_now |= EXT_RLYE2;
        break;
		//] //[New addition IO card,Lyabryan,2019/07/22]
/*        case EXT_MO7:
            DO_MO7_PIN = 0;
            mfo_now |= EXT_MO7;
        break;
        case EXT_MO8:
            DO_MO8_PIN = 0;
            mfo_now |= EXT_MO8;
        break;
        case EXT_MO9:
            DO_MO9_PIN = 0;
            mfo_now |= EXT_MO9;
        break;
        case EXT_MO10:
            DO_MO10_PIN = 0;
            mfo_now |= EXT_MO10;
        break;*/
//-- End 2008/02/29
        default:
        break;
    }
    EINT();
}

void mfo_process(void)
{
    UBYTE ubTemp, i;
    UWORD mox_on, j;
    UWORD (*mfo_ptr)(UWORD, UWORD);
    //                    PD.1 PD.2 PD.0 PA.15  
    //                   -MO2--MO1--RLY2-RLY1 
    //bit: 7   6   5   4   3    2    1    0
    mfo_Pin();
    i = 0;
  
    if ((pr[DEBUG_F1]&0x0008)!=0x0008){ /* doesn't for ICT test, dino, 05/08/2007 */
//        for (j=0;j<=3;j++){
        for (j=0;j<=11;j++){
    	    mox_on = 0;
            mfo_ptr = mfo_tbl[pr[RLY1+j]];       // Multi-Function Output Terminal 1
            mox_on = (*mfo_ptr)(_16BitTab[j],(pr[MO_INV]&_16BitTab[j]));
            if (mox_on==0){
	        	if (pr[RLY1+j]==41){
		    		ubTemp = 0x01<<i;
		    		i++;
		    		if ((speed&ubTemp)==0x00)
		        		mfo_OFF(_16BitTab[j]);
                }
                else
                   	mfo_OFF(_16BitTab[j]);
            }  
            else{
	        	if (pr[RLY1+j]==41){
		    		ubTemp = 0x01<<i;
		    		i++;
		    		if ((speed&ubTemp)!=0x00)
		        		mfo_ON(_16BitTab[j]);
	        	}
	        	else{        	
		    		mfo_ON(_16BitTab[j]);
		    		//mfo_now |= _16BitTab[j];
	        	}
            }
        }
    }
}

void di_sub0(UWORD chg, UWORD k)          // 2_wire: di_0: run/fwd, di_1:run/rev //
{

    if(((chg)||((pr[EXTON_RUN]==1)&&((pr[WIRE2_3]&0x01)==0x00)&&TUN_STOP==0))&& (STO_FLAG ==0)&&(AFE_ERR_TRIG==0)&&(BTTx_btFWDREVReset==0))
    {   
        //[STO function has fixed, Bernie, 2015/03/02]
		//k=EXT_FWD, mean EXT_REV active

		if(k==EXT_FWD)
        {        
            //run();	// delete by dino, 03/08/2007
            RUN_DETECT = 1;
            RUN_SENSOR0 = 1;   //[Service time function, Bernie, 2017/03/14]
            if (pr[SETDIR]==2) 
            {           
                // disable Forward //
				CMDDIR = REVERSE;// gfc //[Wrong dir in Ins,Lyabryan,2018/07/16]
				if(RUNNING==STOP)
                {
					CMDDIR = REVERSE;// gfc
    		    	WGDIR = REVERSE;
    		    }
	    	}
	    	else
            {
	    		if(((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4))
                { 
                    //[EPS autodetect dir,Lyabryan,2018/07/02]  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010   //0x12 to 0x42 [Modify EPS function, Bernie, 2012/11/27 ]
					CMDDIR = FORWARD;// gfc
             		if(WGDIR!=CMDDIR) 
                    {     
                        //[Wrong dir in Ins,Lyabryan,2018/07/16]
                        stop();
                    }
                    if(RUNNING==STOP)
                    {
                        CMDDIR = FORWARD;  // gfc
                        WGDIR = FORWARD;
                    }
		    	}
	    	}
	    	// gfc
	    	if(CMDJOG==0 && !GEN_START && (MODE3==0)&&(RUNNING==STOP))
            {   
                // Add by DINO, 11/28/2008 //[EPS, Sampo, 03/27/2011]  //[DIN time sequence, Bernie, 2013/03/07]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
			//[ //[Sibocom FWD & REV only one exist set EPS mode 0, Jason, 2019/12/31]
				if(EPS && (pr[SIBO_EPS_FRMODE]!=0)){ 
					PR_ubEpsOptMod = pr[EPS_OPTM];
					GEN_EN = 0;
				}
				//] //[Sibocom FWD & REV only one exist set EPS mode 0, Jason, 2019/12/31]
#endif
	    		LIFT_RUNCMD = 1;
	    		run();	// dino, 03/08/2007
	    	}
            else
            {
                //[DIN time sequence, Bernie, 2013/03/07]
                if((MODE3 == 1))
                {
                    LIFT_RUNCMD = 0;
	    		    stop();
                }
            }
			if(WarnCode == FWDREV_WARN)
            { 
                //[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
				Keypad_Page = Keypad_PageTmp;
				WarnCode = 0;
            }
		}
		//k=EXT_REV, mean EXT_FWD active
		else if(k==EXT_REV) 
        {  
            //run();	// delete by dino, 03/08/2007
            RUN_DETECT = 1;
            RUN_SENSOR0 = 1;   //[Service time function, Bernie, 2017/03/14]
	    	if (pr[SETDIR]==1)
            {
              	CMDDIR = FORWARD; // gfc   //[Wrong dir in Ins,Lyabryan,2018/07/16]
              	if(RUNNING==STOP)
                {
                    CMDDIR = FORWARD;// gfc
                    WGDIR = FORWARD;
                }
	    	}
	    	else
            {
	    		if(((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4))
                {
                    //[EPS autodetect dir,Lyabryan,2018/07/02] //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010    //0x12 to 0x42 [Modify EPS function, Bernie, 2012/11/27 ]
             		CMDDIR = REVERSE;// gfc
             		if(WGDIR!=CMDDIR)
                    {
                        //[Wrong dir in Ins,Lyabryan,2018/07/16]
                        stop();
                    }
               		if(RUNNING==STOP)
                    {
               			CMDDIR = REVERSE;// gfc
                        WGDIR = REVERSE;
                    }
                }
	    	}
	    	// gfc
	    	if(CMDJOG==0 && !GEN_START && (MODE3==0)&&(RUNNING==STOP))
            {   
                // Add by DINO, 11/28/2008 //[EPS, Sampo, 03/27/2011]  //[DIN time sequence, Bernie, 2013/03/07]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
			//[ //[Sibocom FWD & REV only one exist set EPS mode 0, Jason, 2019/12/31]
				if(EPS && (pr[SIBO_EPS_FRMODE]!=0)){ 
					PR_ubEpsOptMod = pr[EPS_OPTM];
					GEN_EN = 0;
				}			
				//] //[Sibocom FWD & REV only one exist set EPS mode 0, Jason, 2019/12/31]
#endif
	    		LIFT_RUNCMD = 1;
	    		run();	// dino, 03/08/2007
	    	}
            else
            {                    
                //[DIN time sequence, Bernie, 2013/03/07]
                if((MODE3 == 1))
                {
                    LIFT_RUNCMD = 0;
                    stop();
      	        }
            }			
			if(WarnCode == FWDREV_WARN)
            {
				Keypad_Page = Keypad_PageTmp;
				WarnCode = 0;
			}

		}
		else
        {
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15] //[FWD & REV Warning only for Sibocom,Lyabryan,2020/09/01]
	    	if (CMDJOG==0){	// Add by DINO, 11/28/2008
			    if(k==EXT_FWDREV){
                    WarnDisplaySave();
                    mfi_FwdRevWarn(); //[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
					
					//[ //[Sibocom FWD & REV only one exist set EPS mode 0, Jason, 2019/12/31]
                    if(EPS && (pr[SIBO_EPS_FRMODE]!=0)){ 
						if((MODE3==0) && (!GEN_START) && (RUNNING==STOP)){
                            PR_ubEpsOptMod = pr[SIBO_EPS_FRMODE];
                            GEN_EN = 1;
							LIFT_RUNCMD = 1;
							run();
						}
						else{
                            if((MODE3 == 1)){
                                LIFT_RUNCMD = 0;
                                stop();
                            }
						}
            	    }
					else{
						LIFT_RUNCMD = 0;		   
						MODE2 = 0;	//[DIN time sequence, Bernie, 2013/03/07]
						MODE3 = 0;			
						IODLC_CRPLS_SW = 0; // [IODLC, Lyabryan, 2016/11/11]
						stop();
						RUN_DETECT = 0; //[Russia time srequence for IM, Bernie, 2015/07/13]
						RUN_SENSOR0 = 0;  //[Service time function, Bernie, 2017/03/14]
						RUN_SENSOR1 = 0;
					}
					//] //[Sibocom FWD & REV only one exist set EPS mode 0, Jason, 2019/12/31]
				}
                else{
                    if(WarnCode == FWDREV_WARN){ //[Sibocom exist FWD/REV Warn, Jason, 2019/10/07]
                        Keypad_Page = Keypad_PageTmp;
                        WarnCode = 0;
                    }					
				    LIFT_RUNCMD = 0;		   
				    MODE2 = 0;	//[DIN time sequence, Bernie, 2013/03/07]
				    MODE3 = 0;			
				    IODLC_CRPLS_SW = 0; // [IODLC, Lyabryan, 2016/11/11]
				    stop();
				    RUN_DETECT = 0; //[Russia time srequence for IM, Bernie, 2015/07/13]
				    RUN_SENSOR0 = 0;  //[Service time function, Bernie, 2017/03/14]
				    RUN_SENSOR1 = 0;
                }
	    	}
#else
            if(CMDJOG==0)
            { 
                // Add by DINO, 11/28/2008
                LIFT_RUNCMD = 0;           
                MODE2 = 0;  //[DIN time sequence, Bernie, 2013/03/07]
                MODE3 = 0;          
                IODLC_CRPLS_SW = 0; // [IODLC, Lyabryan, 2016/11/11]
                stop();
                RUN_DETECT = 0; //[Russia time srequence for IM, Bernie, 2015/07/13]
                RUN_SENSOR0 = 0;  //[Service time function, Bernie, 2017/03/14]
                RUN_SENSOR1 = 0;
            }
#endif
	    }
    }
}

void di_sub1(UWORD chg, UWORD k)          // 2_wire: di_0: run/stop, di_1:fwd/rev //
{

	//FORWARD -> RUN/STOP, chg=EXT_REV, mean EXT_FWD active
	if(((chg)||(EXT_PWRONRUN==1)||((pr[EXTON_RUN]==1)&&((pr[WIRE2_3]&0x01)==0x00)&&TUN_STOP==0&&AFE_ERR_TRIG==0))&& (STO_FLAG ==0)&&(BTTx_btFWDREVReset==0))
    {   
        //[STO function has fixed, Bernie, 2015/03/02]
		EXT_PWRONRUN = 0;
	    /*if (CMDJOG==0){	// Add by DINO, 11/28/2008
		    if ((k&EXT_FWD)==EXT_FWD &&  !GEN_START){ //[EPS, Sampo, 03/27/2011]
		    	LIFT_RUNCMD = 1;
		        run();
		    }
		    else{
		    	LIFT_RUNCMD = 0;
		        stop();
		    }
		}*/

		if(((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4))
        {  
            //[EPS autodetect dir,Lyabryan,2018/07/02]  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
			if ((k&EXT_REV)==EXT_REV)
            { 
                // Reverse
			    if(pr[SETDIR]!=1) 
                {
			        CMDDIR = REVERSE;
				    if(RUNNING==STOP)
                    {            
					    WGDIR = REVERSE;
                    }
			    }
			}    
			else
            {   
                // Forward
			    if(pr[SETDIR]!=2)
                {
				    CMDDIR = FORWARD;
			   	    if(RUNNING==STOP)
                    {         
			    	    WGDIR = FORWARD;
                    }
				}
			}
		}

        if(CMDJOG==0 && !GEN_START && (MODE3==0))
        {   
            // Add by DINO, 11/28/2008   //[DIN time sequence, Bernie, 2013/03/07]
		    if ((k&EXT_FWD)==EXT_FWD )
            { 
                //[EPS, Sampo, 03/27/2011]            
                RUN_DETECT = 1;
                RUN_SENSOR0 = 1;   //[Service time function, Bernie, 2017/03/14]
		    	LIFT_RUNCMD = 1;
		        run();
		    }
		    else
            {
		    	LIFT_RUNCMD = 0;
                MODE2 = 0;  //[DIN time sequence, Bernie, 2013/03/07]
                MODE3 = 0;      
                RUN_DETECT = 0;
		        stop();
                RUN_SENSOR0 = 0;  //[Service time function, Bernie, 2017/03/14]
                RUN_SENSOR1 = 0;
		    }
		}
	}
}

void di_sub2(UWORD chg, UWORD k)        // 3_wire: di_0, di_2:run/stop, di_1:fwd/rev //
{
	if(((chg)||(EXT_PWRONRUN==1)||((pr[EXTON_RUN]==1)&&((pr[WIRE2_3]&0x01)==0x00)&&TUN_STOP==0&&AFE_ERR_TRIG==0))&& (STO_FLAG ==0)&&(BTTx_btFWDREVReset==0))
    {   
        //[STO function has fixed, Bernie, 2015/03/02]
		EXT_PWRONRUN = 0;
		if(CMDJOG==0)
        {   
            // Add by DINO, 11/28/2008
        	if((k&EXT_DI1)==0)
            { 
                // DI1 OFF
        		LIFT_RUNCMD = 0;
                RUN_DETECT = 0;
        		stop();
        		RUN_SENSOR0 = 0;  //[Service time function, Bernie, 2017/03/14]
                RUN_SENSOR1 = 0;
        	}
        	else if((k&EXT_FWD)==EXT_FWD  && !GEN_START && (MODE3==0))
            { 
                //[EPS, Sampo, 03/27/2011]   //[DIN time sequence, Bernie, 2013/03/07]
            	LIFT_RUNCMD = 1;
                RUN_DETECT = 1;
                MODE2 = 0;  //[DIN time sequence, Bernie, 2013/03/07]
                MODE3 = 0;
                RUN_SENSOR0 = 1;   //[Service time function, Bernie, 2017/03/14]
            	run();
            }
        }

		if(((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4))
        { 
            //[EPS autodetect dir,Lyabryan,2018/07/02]    //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
        	if((k&EXT_REV)==EXT_REV)
            { 
                // Reverse
	    	    if(pr[SETDIR]!=1)
                 {
       		        CMDDIR = REVERSE;
       			    if (RUNNING==STOP)
                    {      
                        WGDIR = REVERSE;
                    }
       		    }
	    	}    
	    	else
            {   
                // Forward
	    	    if (pr[SETDIR]!=2)
                {
        		    CMDDIR = FORWARD;
        	   	    if (RUNNING==STOP)
                    {   
                        WGDIR = FORWARD;
                    }
       			}
	    	}
		}
    }
}

/*--------------------------------------------------------------------------------------------
 -  Multu Function Input Subroutine
 --------------------------------------------------------------------------------------------*/
void no_func(UWORD chg,UWORD k)                      // no function
{
}

void mispeed1(UWORD chg,UWORD k)
{

    if (MFI_REMOTE==0){
	    if (k==0){               //k = 0(OFF), 1(ON)
          speed &= 0xfe;
		  // [IODLC, Lyabryan, 2016/11/11] //[
          if(RUNNING == RUN){
              IODLC_MIcheck = 1;
              if(IODLC_CRPLS_SWSPD&&(IODLC_ubArea_status>= AreaS3)) //&&IODLC_ubArea_status!= Arealand
                  IODLC_CRPLS_SW = 1;
          }
          else{
              IODLC_CRPLS_SW = 0;
              IODLC_CRPLS_SWSPD = 0;
          }
		  //] // [IODLC, Lyabryan, 2016/11/11]
	    }
        else{
		    // [IODLC, Lyabryan, 2016/11/11] //[
            if(RUNNING == RUN){
                IODLC_MIcheck = 0;
                IODLC_MIinput = MI_OFF;
            }
			//] // [IODLC, Lyabryan, 2016/11/11]
          speed |= 0x01;
        }
    }

}
void mispeed2(UWORD chg,UWORD k)
{
    if (MFI_REMOTE==0){
        if (k==0){
		    // [IODLC, Lyabryan, 2016/11/11] //[
            if(RUNNING == RUN){
                IODLC_MIcheck = 0;
                IODLC_MIinput = MI_OFF;
                IODLC_CRPLS_SWSPD = 1;
            }
			//] // [IODLC, Lyabryan, 2016/11/11]
          speed &= 0xfd;
        }
        else{// [IODLC, Lyabryan, 2016/11/11] //[
            if((IODLC_MIcheck)&&(RUNNING == RUN)){
                  IODLC_MIinput = MI_ON;
            }
		//] // [IODLC, Lyabryan, 2016/11/11]
          speed |= 0x02;
        }
    }      

}
void mispeed3(UWORD chg,UWORD k)
{
    if (MFI_REMOTE==0){
        if (k==0)
          speed &= 0xfb;
        else
          speed |= 0x04;
    }     

}
void mispeed4(UWORD chg,UWORD k)
{
    if (MFI_REMOTE==0){
        if (k==0)
          speed &= 0xf7;
        else
          speed |= 0x08;
    }     
}

void extreset(UWORD chg,UWORD k)
{
        if (k!=0)
          reset();
}

void extjog(UWORD chg,UWORD k)
{
	if (chg) {
    	if (k!=0){
    		if ((!RUNNING)||(CMDJOG==1)){
        	    EXT_JOG = 1;
                CMDJOG = 1;
                run();
                CMDJOG = 1;
            }
        }
        else {
        	if (EXT_JOG==1){
        		EXT_JOG = 0;
            	if ((CMDRUN==RUN)&&(CMDJOG==1))     // JOG Stop
            		stop();
            }
        }
    }
}

void speedhold(UWORD chg,UWORD k)
{
	if (k!=0){
   		if (HOLD==0)
   			HOLD = 1;
   	}
    else{
   		if (HOLD==1)
   			HOLD = 0;
    }
}

void acc_dec_chg1(UWORD chg,UWORD k)
{
    if (MFI_REMOTE==0){
        if (k==0){
        	acc_dec &= 0xFE;
        }
        else{
        	acc_dec |= 0x01;
        }
    }  	
}

void acc_dec_chg2(UWORD chg,UWORD k)
{
    if (MFI_REMOTE==0){
		if (k==0){
        	acc_dec &= 0xFD;
        }
        else{
        	acc_dec |= 0x02;
        }
    }    
}

void efnc(UWORD chg,UWORD k)
{
        if (k!=0){
        	if (EXT_EF==0)
       			EXT_EF = 1;
        }
        else{
        	if (EXT_EF==1)
       			EXT_EF = 0;
        }

}
void ef1nc(UWORD chg,UWORD k)
{
        if (k!=0){
        	if (EXT_EF1==0)
       			EXT_EF1 = 1;
        }
        else{
        	if (EXT_EF1==1)
       			EXT_EF1 = 0;
        }
}

void bb_up(UWORD chg,UWORD k)
{

        if (k!=0){
        	if (MFI_BB==0)
        		MFI_BB = 1;
        }
        else{
        	if (MFI_BB==1)
          		MFI_BB = 0;
        }
        
}

void outputoff(UWORD chg, UWORD k)                   // Output OFF
{
        if (k!=0)
            MFI_WG = 1;
        else
            MFI_WG = 0;
}

void cancel_AAAD(UWORD chg,UWORD k)
{

        if (k!=0)
            MFI_AAADDIS = 1;
        else
            MFI_AAADDIS = 0;

}

void motor1_2(UWORD chg,UWORD k)
{

		if (k!=0){
        	if ((EXT_MOTOR1to2==0)&&(RUNNING==STOP)){
        		EXT_MOTOR1to2 = 1;  // Select Motor 2
        		Motor2Pr();
    			TQRBaseInit();
    			TQRMaxInit();
    			MotorPrInit();
            }
        }
        else{
        	if ((EXT_MOTOR1to2==1)&&(RUNNING==STOP)){
          		EXT_MOTOR1to2 = 0;	// Select Motor 1
          		Motor1Pr();
    			TQRBaseInit();
    			TQRMaxInit();
    			MotorPrInit();
          	}
        }

}

void AUI1_SOFC(UWORD chg,UWORD k)
{
		if (k!=0){
        	EXT_AISEL |= 0x01;
        }
        else{
        	EXT_AISEL &= 0xFE;
    	}
}

void ACI_SOFC(UWORD chg,UWORD k)
{
		if (k!=0){
        	EXT_AISEL |= 0x02;
        }
        else{
        	EXT_AISEL &= 0xFD;
    	}
}

void AUI2_SOFC(UWORD chg,UWORD k)
{
		if (k!=0){
        	EXT_AISEL |= 0x04;
        }
        else{
        	EXT_AISEL &= 0xFB;
    	}
}

void ForceRampStop(UWORD chg,UWORD k)
{
	    if (k!=0){
	    	EXT_FORCESTOP = 1;
	    	EXT_COASTSTOP = 0;
		    stop();	    
	    }
}

void ForceCoastStop(UWORD chg,UWORD k)
{

	    if (k==0){
	    	EXT_FORCESTOP = 1;
	    	EXT_COASTSTOP = 1;
	    	EXT_ENABLE    = 1;
		    stop();	    
	    }
	    else
			EXT_ENABLE    = 0;

}

void ForceCoastStop1(UWORD chg,UWORD k)
{

	    if (k==0){
	    	EXT_FORCESTOP = 1;
	    	EXT_COASTSTOP = 1;
		    stop();	    
	    }


}

void incspeed(UWORD chg,UWORD k)
{

        if (k!=0){                   
            MFI_UP = 1;
        }
        else{
            MFI_UP = 0;
        }

}

void decspeed(UWORD chg,UWORD k)
{

        if (k!=0){                       
            MFI_DOWN= 1;
		}          
        else{
            MFI_DOWN = 0;
        }

}

void piddis(UWORD chg,UWORD k)
{

        if (pr[PIDSL]!=0){
            if (k!=0)
                MFI_PIDDIS = 1;
            else
                MFI_PIDDIS = 0;
        }

}

void CNT_IN(UWORD chg,UWORD k)
{

	if (pr[MI6]==23)
        TRGEN = 1;

}

void CNT_CLR(UWORD chg,UWORD k)
{

    if (k==0){                         
        trg_cnt = 0;
        TRGRST = 1;
    }
    else
        TRGRST = 0;

}

void FWD_JOG(UWORD chg,UWORD k)
{
	if (chg) {
    	if (k!=0){                       
        	if ((!RUNNING)||(CMDJOG==1)){
        	    if (Error==0){
        			if (pr[SETDIR] != 2){
        				if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]   //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
        					if (CMDDIR==REVERSE){
        						JOG_DIR = 1;
        						CMDDIR = FORWARD;
        					}
            			}
            			EXT_JOG = 1;
                		CMDJOG = 1;
                		run();                  			
						CMDJOG = 1;            			
                  	}
                }
            }
        }
        else {
        	if (EXT_JOG==1){
        		EXT_JOG = 0;
            	if ((CMDRUN==RUN)&&(CMDJOG==1))          // JOG Stop
            		stop();
            }
        }
    }
}

void REV_JOG(UWORD chg,UWORD k)
{
	if (chg) {
    	if (k!=0){                       
       		if ((!RUNNING)||((CMDRUN==STOP)&&(CMDJOG==1))){
       			if (Error==0){
       				if (pr[SETDIR]!=1){
       					if (((PWM_Status.ub&0x42) == 0)&&(!EPS_MODE4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]    //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
       						if (CMDDIR==FORWARD){
       							JOG_DIR = 1;
       							CMDDIR = REVERSE;
       						}
           				}
           				EXT_JOG = 1;
               			CMDJOG = 1;
               			run();
               			CMDJOG = 1;
                  	}
                }
            }
        }
        else {
        	if (EXT_JOG==1){
        		EXT_JOG = 0;
            	if ((CMDRUN==RUN)&&(CMDJOG==1))          // JOG Stop
            		stop();
            }
        }
    }
}

void TRQ_2_SPD(UWORD chg,UWORD k)
{

    if ((pr[CTRLM]==FOCPG)||(pr[CTRLM]==TQCPG)){
//        if (CMDRUN==RUN){
            if (k==0){
		        EXT_TqSpd_flag = 0; //Speed mode
            }
            else{
		        EXT_TqSpd_flag = 1; //Toqure mode    
            }
//        }
    }

}

void ASR1_ASR2(UWORD chg,UWORD k)
{
	if (k!=0){                       
    	EXT_ASR1to2 = 1;
	}          
    else{
    	EXT_ASR1to2 = 0;
    }

}

void YconnectCHK(UWORD chg,UWORD k)
{

	if (k!=0){
        if (DCONNECTOK==1){
            WGOFF;
            Error = ydc_ERR;            
            WGOFF;
        }        
        if ((YOnCNT>=pr[YDDELAYT])&&(YCONChkCNT>=20))
            YCONNECTOK = 1;
        else{
            YCONChkCNT++;
        }
	}          
    else{
        YCONChkCNT = 0;
    	YCONNECTOK = 0;
    }

}
void DconnectCHK(UWORD chg,UWORD k)
{

	if (k!=0){                       
        if (YCONNECTOK==1){
            WGOFF;
            Error = ydc_ERR;            
            WGOFF;            
        }
    	if ((DOnCNT>=pr[YDDELAYT])&&(DCONChkCNT>=20))
            DCONNECTOK = 1;
        else
            DCONChkCNT++;
	}          
    else{
        DCONChkCNT = 0;
    	DCONNECTOK = 0;
    }

}

void VcomPosition(UWORD chg,UWORD k)
{

	//if (pr[CTRLM]==FOCPG){
    	if (k!=0){
    		if (MFI_APRbyVcom==0){
    			MFI_APRbyVcom = 1;
    			VPHOLD = 1;
    		}
    	}
    	else{
    		if (MFI_APRbyVcom==1){
    			MFI_APRbyVcom = 0;
    			VPHOLD = 1;
    		}
		}
	//}

}

void MCCHKEnable(UWORD chg,UWORD k)
{
	if (k!=0){                       
    	MFI_MCCHK = 1;
	}          
    else{
    	MFI_MCCHK = 0;
    }
}

void BKCHKEnable1(UWORD chg,UWORD k)    //[change for EN81-1+A3, Bernie, 2015/03/16]
{
	if (k!=0){                       
    	MFI_BRKCHK1 = 1;
	}          
    else{
    	MFI_BRKCHK1 = 0;
    }
}

void BKCHKEnable2(UWORD chg,UWORD k)    //[change for EN81-1+A3, Bernie, 2015/03/16]
{
	if (k!=0){                       
    	MFI_BRKCHK2 = 1;
	}          
    else{
    	MFI_BRKCHK2 = 0;
    }
}


void EPSEnable(UWORD chg,UWORD k)
{
	if (k!=0){                       
    	EPS = 1;
        DLC_btEPS = 1; //EPS function of DLC mode , James, 20200408
    	//BLK_WRITE = 1;
	}          
    else{
    	EPS = 0;
        DLC_btEPS = 0; //EPS function of DLC mode , James, 20200408
    	//BLK_WRITE = 0;
    }
}

//DLC function, Henry, 2016/07/20 [
void DLC_LU(UWORD chg,UWORD k){
	if(k != 0){                    
		DLC_btLU1 = 1;
	}   
	else{
  	    DLC_btLU1 = 0;
	}
}

void DLC_LD(UWORD chg,UWORD k){
	if(k != 0)                   
    	DLC_btLD1 = 1; 
    else
        DLC_btLD1 = 0;
}

void DLC_DZN(UWORD chg,UWORD k){
	if(k != 0)               
   DLC_btDZN = 1;
	else
   DLC_btDZN = 0;
}

void DLC_CANOFF(UWORD chg,UWORD k){
	if(k != 0)                   
        DLC_btCANOff = 1; 
    else
        DLC_btCANOff = 0;
}

void DLC_LOW_SPD(UWORD chg,UWORD k){
	if(k != 0)
 	 	DLC_btSpdL = 1;
    else
  	    DLC_btSpdL = 0;
}

void DLC_FSD(UWORD chg,UWORD k){
    if(k != 0)                   
  	    DLC_btFSD1 = 1; 
    else
  	    DLC_btFSD1 = 0;
}

void DLC_DDS(UWORD chg,UWORD k){
    if(k != 0)
    	mio_btDD1 = 1;        //JINGDO               
    else
    	mio_btDD1 = 0;        //JINGDO 
}

void DLC_UDS(UWORD chg,UWORD k){
    if(k != 0)                   
  	    mio_btUD1 = 1;      //JINGDO
    else
  	    mio_btUD1 = 0;      //JINGDO
}

//]

void IODLC_CRPLS_IO(UWORD chg,UWORD k){ // [IODLC, Lyabryan, 2016/11/11]
    if(k != 0){
        if(IODLC_ubArea_status<Arealand) //[Creep-Optimis,Lyabryan,2019/02/11]
      	    IODLC_CRPLS_SW = 1; 
    }
    else
  	    IODLC_CRPLS_SW = 0;
}

void EPS_MI_DETCT(UWORD chg,UWORD k){     //[EPS MO Output,Lyabryan,2018/06/19] //[ADCO request function for EPS function, Bernie, 2017/09/06]

    if(k != 0){                   
  	    MI_EPS_SWITCH = 1; 
  	    //MO_EPS_SWITCH = 1;
  	}
    else{
  	    MI_EPS_SWITCH = 0;
  	    EPS_MO_JUDGEMENT = 0;
  	    uwEPS_Delay_CNT = 0;
  	}

}

void SMTRISE_ESD(UWORD chg,UWORD k){ //[KEB ESD&ETS Function/Lyabryan/2018/08/10]

    if((k != 0)||(btSR_ESD_EDGE)){               
        btSR_ESD = 1;
        if((pr[CTRLM]==FOCPM)||(pr[CTRLM]==FOCPG)||(pr[CTRLM]==VFPG))
            btSR_speedCTRL_ESD = SR_control_get; 
        btSR_ESD_EDGE = 1;
    }
    else{
        btSR_speedCTRL_ESD = SR_control_return;
        btSR_ESD = 0;
    }

}

void SMTRISE_ETS(UWORD chg,UWORD k){ //[KEB ESD&ETS Function/Lyabryan/2018/08/10]

    if((k != 0)||(btSR_ETS_EDGE)){ 
        if(((pr[CTRLM]==FOCPM)||(pr[CTRLM]==FOCPG)||(pr[CTRLM]==VFPG))&&(uwAbsMotorHz>=pr[FETS])){
            btSR_ETS = 1;
            btSR_speedCTRL_ETS = SR_control_get; 
            btSR_ETS_EDGE = 1;
        }
    }
    else{
        btSR_speedCTRL_ETS = SR_control_return;
        btSR_ETS = 0;
    }

}

void AFE_ERRFBK(UWORD chg,UWORD k)
{
    if(AFE_Level_Delay)
    {
        if (k!=0)
        {
        	if (AFE_ERR_TRIG==0)
        	{   
       			AFE_ERR_TRIG = 1;
                if((Error != 0)&&(Error != GFCAFE_ERR))
                {
                    AFE_ERR_RECORD = 1;
                }
        	}
        }
        else
        {
        	if (AFE_Level_Delay==1)
        	{
       			AFE_Level_Delay = 0;
        	}
        }
    }
    
    if (chg){
        if (k!=0){
        	if (AFE_ERR_TRIG==0)
        	{   
       			AFE_ERR_TRIG = 1;
                if((Error != 0)&&(Error != GFCAFE_ERR))
                {
                    AFE_ERR_RECORD = 1;
                }
        	}
        }
        else{
        }
	}

}

void ef_check(void){
     if(Error==0){
        if(EXT_EF){
        	Error = EF_ERR;
        	Keypad_Page = ErrPAGE;
			WARNSTOPREC = 1;		//09/10/2007        	
		}
		else if (ACI_EF){
            Error = ACE_ERR;
            Keypad_Page = ErrPAGE;
        }
        else if (EXT_EF1){
            Error = EF1_ERR;
            Keypad_Page = ErrPAGE;
        }
     }
/*  Move to Error_Handel(), Modify by DINO, 11/28/2008
     else {
		if((Error==EF_ERR)&&(EXT_EF==0))
        	KEYRESET = 1;
		else if ((Error==ACE_ERR)&&(ACI_EF==0))
			KEYRESET = 1;
		else if ((Error==EF1_ERR)&&(EXT_EF1==0))   
			KEYRESET = 1;  
     }	/*  */
}

void bb_check(void){ //per Timer_Base.1ms
	if (Error==0){
    	if (MFI_BB||COM_BB){        	
            Error = bb_ERR;
            Keypad_PageTmp = Keypad_Page;
        }
    }
    else if (Error==bb_ERR) {
    	if ((CMDRUN==STOP)||(pr[REST_M]==0)) {
//        	CMDRUN = STOP;
			LIFT_ENABLE = 0;					// Add by DINO, 03/28/2008
 			TB1_uwMCStopCnt = pr[MCDELAY_STOP]; // Add by DINO, 03/28/2008
            CMDFREE = 1;
            if (MFI_BB==0&&COM_BB==0){
            	KEYRESET = 1;
				Error = 0;
				Keypad_Page = Keypad_PageTmp;
            }
        }
        else {
        	if (MFI_BB==0&&COM_BB==0){
              	if(Error==bb_ERR){
                	RESTART = 1;
                	KEYRESET = 1;                         // Enable Reset
              	}
            }
            else {
            	RESTART = 0;
            	KEYRESET = 0;                         // Disable Reset
            }
        }
    }//else if(Error==18) 
}

/*------ External UP/DOWN key, freq. source=keypad only */
void ext_updown(void){
#if SH7149
	ULONG ax;     

    if ((pr[SOFC]==3)&&(speed==0)&&(CMDJOG==0)&&(HOLD==0)) {
    	if (MFI_UP!=MFI_DOWN) {
    		if ((EXTUPDN==0)&&(CMDRUN==RUN)){
    			fexternal.ul = fout.ul;
    			EXTUPDN = 1;
    		}
    		
         	if (MFI_UP){
           		ACCODEC = ACCON;          // ACCEL OR DECEL = ACCEL ON
           		if (pr[UPDNKEYM]==0)
				    ax = acc_decel();
				else
				    ax = ((ULONG)pr[UPDNKEYS]<<16);    
           		fexternal.ul = fexternal.ul + ax;
           		if (fexternal.uw.hi > pr[FMAX])
             		fexternal.uw.hi = pr[FMAX];
           		if (fexternal.uw.hi > pr[FUPPER])
             		fexternal.uw.hi = pr[FUPPER];
           
         	}
         	else if(MFI_DOWN) {
           		ACCODEC = DECON;
           		if (pr[UPDNKEYM]==0)
				    ax = acc_decel();
				else
				    ax = ((ULONG)pr[UPDNKEYS]<<16);    
           		
           		if (fexternal.ul > ax)
             		fexternal.ul = fexternal.ul - ax;
           		else
             		fexternal.ul = 0;
         	}
         	fkey.ul = fexternal.ul;
       	}
       	else
       	    EXTUPDN = 0;
	}
#endif
}

void TqOfstHigh(UWORD chg,UWORD k){       
    if (k==0)               //k = 0(OFF), 1(ON)
        MFI_TQCSel &= 0xfb;
    else
        MFI_TQCSel |= 0x04;	
}

void TqOfstMiddle(UWORD chg,UWORD k){
    if (k==0)               //k = 0(OFF), 1(ON)
        MFI_TQCSel &= 0xfd;
    else
        MFI_TQCSel |= 0x02;	

}

void TqOfstLow(UWORD chg,UWORD k){
    if (k==0)               //k = 0(OFF), 1(ON)
        MFI_TQCSel &= 0xfe;
    else
        MFI_TQCSel |= 0x01;	

}

void MISpdPosChang(UWORD chg,UWORD k){

	if (k==0)               //k = 0(OFF), 1(ON)
		EXT_SPD2POS = 0;
	else
		EXT_SPD2POS = 1;	

}

void APREnable(UWORD chg,UWORD k){
	if (pr[CTRLM]==FOCPG){
    	if (k==0){               //k = 0(OFF), 1(ON)
    		if (EXT_PG2REFMODE==0){		// PG2 Ref Speed Control
    			//APR_status, keep status of Bit 3(APRCMDDIR) & 4(ZeroServo)
				PositionCom = 0;	//Bit 0
		   		APRExeFlag = 0;		//Bit 1
		   		LOOPFlag = 0;		//Bit 2		   		
		   		EnterLoop = 0;		//Bit 5
				PcurveFlg = 0;		//Bit 6
				P2PFlag = 0;		//Bit 7
				PcurveReach = 0;
				
				ONPosition = 0;
				MultiONPosition = 0;
				APR_uwOnPCNT = 0;
				
				STOPgoAPR = 0;    //In MFIO, APREnable();
								
				Psacc.ul = 0;
				APR_uwPCom = 0;			
				APR_uwPFbk = 0;
				APR_uwPGCycle = 0;
				APR_slSpdCmd = 0;
				PsaccMax.ul = 0;
				Psacc.ul = 0;
        		if (EXT_SPD2POS==0)
            		APR_uwPGHome = pr[PGHOME];
				else
            		APR_uwPGHome = pr[PMI1+speed-1];
						
			}
    	}
    	else{        	
        	if ((PositionCom==0)&&(APRFirstGo==0)){
        		STOPgoAPR = 1;    //In run();
            	STPgoAPRChkZ = 0;
            }
            if (PositionCom==0){
            	ZeroServo = 0;
            	APRExeFlag = 0;
			}
            PositionCom = 1;
        }
	}
}

void MIPosEnter(UWORD chg,UWORD k){
	if ((chg)&&(k!=0)&&(CMDRUN==STOP)){    //k = 0(OFF), 1(ON)	
		if (pr[PMI1+speed-1]!=APR_uwThetaNoMx)
			updatepr((PMI1+speed-1), APR_uwThetaNoMx);
	}
}

void PG2RefPosMode(UWORD chg,UWORD k){
	/*if ((pr[PGREFIN]!=0)&&(pr[SOFC]>=4)){
		if (k!=0)               //k = 0(OFF), 1(ON)
			EXT_PG2REFMODE = 1;		// PG2 Ref Position control
		else
			EXT_PG2REFMODE = 0;		// PG2 Ref Speed control
	}*/
}

void WriteEPDisable(UWORD chg,UWORD k){
	if ( EPS==0 ){
		if (k==0)               //k = 0(OFF), 1(ON)
			BLK_WRITE = 0;
		else
			BLK_WRITE = 1;	
	}
	else
		BLK_WRITE = 1;
}

void TqSetDirection(UWORD chg,UWORD k){
	if (CMDRUN==RUN){
		if (k==0){               //k = 0(OFF), 1(ON)
			EXT_TQCDIR = 0;
		}
		else
			EXT_TQCDIR = 1;
	}	
}

//[Artemis Add Sensor819 Function/Special/2022/06/06]
void MI_Sensor819(UWORD chg,UWORD k)
{		
	if (k!=0)
	{
		if(pr[Sensor819]==4)
		{
			MFI_btSensor819_Button = 0;
			MFI_btSensor819_Top    = 0;
			MFI_btSensor819_Both   = 1;
		}
		else if(pr[Sensor819]==3)
		{
			MFI_btSensor819_Button = 1;
			MFI_btSensor819_Top    = 0;
			MFI_btSensor819_Both   = 0;
		}
		else if(pr[Sensor819]==2)
		{
			MFI_btSensor819_Button = 0;
			MFI_btSensor819_Top    = 1;
			MFI_btSensor819_Both   = 0;
		}
		else if(pr[Sensor819]==1)
		{
			MFI_btSensor819_Button = 0;
			MFI_btSensor819_Top    = 0;
			MFI_btSensor819_Both   = 0;
		}
        else if(pr[Sensor819]==0)
		{
			MFI_btSensor819_Button = 0;
			MFI_btSensor819_Top    = 0;
			MFI_btSensor819_Both   = 0;
		}
	}          
    else
	{
		MFI_btSensor819_Button = 0;
		MFI_btSensor819_Top    = 0;
		MFI_btSensor819_Both   = 0;
    }
}
//[Artemis Add Sensor819 Function/Special/2022/06/06]

//[JES Torq Detect Function, Special.Kung, 2022/09/01]
void Torq_Detect(UWORD chg,UWORD k)
{    
	if(k!=0)
    {                       
    	MFI_btTorqDetect = 1;
	}          
    else
    {
    	MFI_btTorqDetect = 0;
		BTTx_ubTorqDetectRst = 0;
    }
}

/*-----------------------------------------------------------------------------------------
 -      Multi Function Output  Subroutine
 ------------------------------------------------------------------------------------------*/
UWORD mfo_none(UWORD pin,UWORD k){          // Not used

    return (0^k);
}
UWORD mfo_running(UWORD pin,UWORD k){       // Inverter Running //

       if (RUNNING)
         return (pin^k);
       else
         return (0^k);
}
UWORD mfo_atmaxf(UWORD pin,UWORD k){        // At Setpoint Speed (disable output at STOP)

       UWORD bx;
	
	if (RUNNING==RUN){
    	if (fout.uw.hi >= fkey.uw.hi)
			bx = fout.uw.hi - fkey.uw.hi;
    	else
			bx = fkey.uw.hi - fout.uw.hi ;

		if (bx <= 200)            //+- 2.0Hz
        	return (pin^k);
    	else if (bx > 400)        //+- 4.0Hz
        	return (0^k);
		else 
			return (pin&mfo_now);
	} 
    else{
    	return (0^k);
	}       
}
UWORD mfo_atmaxf_Band(UWORD pin,UWORD k){        // At Setpoint Speed (disable output at STOP)//Band of Speed Agree Function #18572	

       UWORD bx;
	
	if((RUNNING==RUN) && (btGearFlag==0))       //[JES Gear no output MO=2, Special.Kung, 2022/10/12]
    {
    	//if (fout.uw.hi >= fkey.uw.hi)
			//bx = fout.uw.hi - fkey.uw.hi;
    	//else
		    //bx = fkey.uw.hi - fout.uw.hi ;

        //[JES test IM with slip and Relay(MO=2) will always ON/OFF, Special.Kung, 2022/12/21]
        if (fcmd.uw.hi >= fkey.uw.hi)
			bx = fcmd.uw.hi - fkey.uw.hi;
    	else
			bx = fkey.uw.hi - fcmd.uw.hi ;

		if (bx <= pr[SpdAgree_B])            //+- 2.0Hz
        	return (pin^k);
    	else if (bx > pr[SpdAgree_B])        //+- 4.0Hz
        	return (0^k);
		else 
			return (pin&mfo_now);
	} 
    else
    {
    	return (0^k);
	}       
}

UWORD mfo_atspeed1(UWORD pin,UWORD k)       // At Speed 1 //
{
       UWORD bx;

       if (fout.uw.hi >= pr[DESIRE_F1])
         bx = fout.uw.hi - pr[DESIRE_F1] ;
       else
         bx = pr[DESIRE_F1] - fout.uw.hi ;

       if (bx <= pr[DESIRE_F1B])            //+- 2.0Hz
         return (pin^k);
       else if (bx > pr[DESIRE_F1B])        //+- 4.0Hz
         return (0^k);
       else 
         return (pin&mfo_now);
         
}
UWORD mfo_atspeed2(UWORD pin,UWORD k)       // At Speed 2 //
{
       UWORD bx;

       if (fout.uw.hi >= pr[DESIRE_F2])
         bx = fout.uw.hi - pr[DESIRE_F2] ;
       else
         bx = pr[DESIRE_F2] - fout.uw.hi ;

       if (bx <= pr[DESIRE_F2B])            //+- 2.0Hz
         return (pin^k);
       else if (bx > pr[DESIRE_F2B])        //+- 4.0Hz
         return (0^k);
       else 
         return (pin&mfo_now);
         
}
UWORD mfo_fcmdzero(UWORD pin,UWORD k){	// Zero Speed //

        //2006/5/26 ¤U¤È 04:49:10 if ((fout.uw.hi == 0)&&(RUNNING==RUN))
        if ((fcmd.uw.hi==0)&&(RUNNING==RUN))
          return (pin^k);
        else
          return (0^k);
}
UWORD mfo_fcmdzerostp(UWORD pin,UWORD k){	// Zero Speed, include drive stop

        //2006/5/24 ¤U¤È 04:49:09if (fout.uw.hi == 0)
        if (fcmd.uw.hi==0)
          return (pin^k);
        else
          return (0^k);
}
UWORD mfo_overtq1(UWORD pin,UWORD k){        // Over Torque Dectted 1) //

       if (((OT1CST==1)&&(TB1_uwOT1Cnt>=pr[OTDT]))||(Error==ot1_ERR))
         return (pin^k);
       else
         return (0^k);
}
UWORD mfo_overtq2(UWORD pin,UWORD k){        // Over Torque Dectted 2) //

       if (((OT2CST==1)&&(TB1_uwOT2Cnt>=pr[OTDT2]))||(Error==ot2_ERR))
         return (pin^k);
       else
         return (0^k);
}
UWORD mfo_ready(UWORD pin,UWORD k){         // Ready

	if (Error==0 && RelayOFF==0 && AFE_ERR_TRIG==0) //[Reduce Start time,Lyabryan,2020/03/14] // && PGREADY==1	// Add PGREADY and RelayOFF Flag, DINO, 12/23/2009 
		return (pin^k);
	else
		return (0^k);
}

UWORD mfo_lv(UWORD pin,UWORD k){            // Low voltage indication

    UWORD uwTemp;

      if ((Error==LvA_ERR)||(Error==Lvd_ERR)||(Error==Lvn_ERR)||(Error==LvS_ERR)){
          //return (pin^k);
          if((Error>=LvA_ERR && Error<=LvS_ERR) || Error==PHL_ERR || (Error>=ovA_ERR && Error<=ovS_ERR)){  //disable Lvs  //[Add auto restart after fault, Bernie, 06/06/12]
	          if((pr[RESET_SLT]==0)||(pr[RESETCNT]==0)){
                  uwTemp = 1;
                    //RST_EN = 0;
              }    
              else{
                  uwTemp = 0;
                    //RST_EN = 1;
              }
          }
      }
      else{
          //return (0^k);
          uwTemp = 0;
      }

    if (uwTemp != 0)
    	return (pin^k);
    else
		return (0^k);
}
UWORD mfo_fault(UWORD pin,UWORD k){         // Inverter Fault //

	// [ LV Option Mode, Add by DINO, 11/30/2009
	UWORD uwTemp;

	uwTemp = Error;
	//Except for Lv Stop or LV when pr[LV_OPTM]==1
	if (Error==LvS_ERR || (LVMOD==1 && (Error==LvA_ERR || Error==Lvd_ERR || Error==Lvn_ERR))){
		uwTemp = 0;
	}
	// ]

	if((LVMOD==0 &&(Error>=LvA_ERR && Error<=Lvn_ERR)) || Error==PHL_ERR || (Error>=ovA_ERR && Error<=ovS_ERR)){  //disable Lvs  //[Add auto restart after fault, Bernie, 06/06/12]
	    if(pr[RESET_SLT]==0||pr[RESETCNT]==0){
            uwTemp = 1;
            //RST_EN = 0;
        }    
        else{
            uwTemp = 0;
            //RST_EN = 1;
        }
    }

	if (uwTemp != 0)
    	return (pin^k);
    else
		return (0^k);
}
UWORD mfo_braker_release(UWORD pin,UWORD k){   // Braker release

    if (BRK_RLS)
        return (pin^k);
    else
        return (0^k);
    
}
UWORD mfo_braker_release2(UWORD pin,UWORD k){   // Braker release 2   // DIN function

    if (BRK_RLS2)
        return (pin^k);
    else
        return (0^k);
    
}

UWORD mfo_ohalarm(UWORD pin,UWORD k){       // OH alarm

    if ((IGBT_Temp>=(SWORD)pr[OHWL])||(HS_Temp>=(SWORD)pr[OHWL]))
        return (pin^k);
    else if ((IGBT_Temp<=(SWORD)(pr[OHWL]-100))&&(HS_Temp<=(SWORD)(pr[OHWL]-100)))
        return (0^k);
    else
        return (pin&mfo_now);
}
UWORD mfo_SWbrakeOut(UWORD pin,UWORD k){   // SW brake Output

    if (GBP_ON==1)
        return (pin^k);
    else
        return (0^k);
/*
// dino, 03/08/2007
    if (PWM_swGBP==0)
        return (0^k);
    else
        return (pin^k);
*/
}

UWORD mfo_LiftEnable(UWORD pin,UWORD k){

    if (MOTORCONNECTOR)
        return (pin^k);
    else
        return (0^k);		
}

UWORD mfo_pidalarm(UWORD pin,UWORD k){      // PID Deviation Alarm //

        if (PIDDEVF)
          return (pin^k);
        else
          return (0^k);
}
UWORD mfo_overslip(UWORD pin,UWORD k){  		// Over Slip

	if (OVERSLIP==1)
		return (pin^k);
    else
    	return (0^k);
    
}
UWORD mfo_trgdone(UWORD pin,UWORD k){       // Trigger attained

    if (trg_cnt==pr[CNTCPL])
      return (pin^k);
    else
      return (0^k);
}
UWORD mfo_trgpre(UWORD pin,UWORD k){        // Preliminary conter attained

    if ((trg_cnt >= pr[CNTPRS])&&(pr[CNTPRS]!=0))
      return (pin^k);
    else
      return (0^k);
}
UWORD mfo_bb(UWORD pin,UWORD k){            // bb indication

    if (Error==bb_ERR)
        return (pin^k);
    else
        return (0^k);
}
//- add 12/13/2007 	DINO
UWORD mfo_bf(UWORD pin,UWORD k){            // bF Error

    if (Error==bF_ERR)
        return (pin^k);
    else
        return (0^k);
}
//- end 12/13/2007
UWORD mfo_warning(UWORD pin,UWORD k){       // All of Warning

    if (WarnCode!=0)
        return (pin^k);
    else
        return (0^k);
}
UWORD mfo_ovalarm(UWORD pin,UWORD k){       // Ov alarm


    if (dcbusAD >= OVR4ad)  //OVR4ad = VDC2AD(3735)
        return (pin^k);
#if SH7149
    else if (dcbusAD<=(OVR4ad-20))         // 20 around 12Vdc/24Vdc (220V/440V)
#else	// dino, 03/07/2007
    else if (dcbusAD<=(OVR4ad-80))         // 20 around 12Vdc/24Vdc (220V/440V)
#endif
        return (0^k);
    else 
        return (pin&mfo_now);
}
UWORD mfo_ocsalarm(UWORD pin,UWORD k){      // Oc stall alarm

    if (STALLC==1)
      return (pin^k);
    else
      return (0^k);
}
UWORD mfo_ovsalarm(UWORD pin,UWORD k){      // Ov stall alarm

    if (STALLV)
      return (pin^k);
    else
      return (0^k);
}
UWORD mfo_opmode(UWORD pin,UWORD k){         // Operation Mode

	// [ Modify by DINO, 06/29/2009
	if (pr[SOOC]==1 && PUEN3==0 && PUEN2==0)
//	if (pr[SOOC]!=0)
	// ]
      return (pin^k);
	else
      return (0^k);
}
UWORD mfo_fwdcmd(UWORD pin,UWORD k){      // Fwd command //

    if (CMDDIR==FORWARD)
      return (pin^k);
    else
      return (0^k);
}
UWORD mfo_revcmd(UWORD pin,UWORD k){      // Rev command //

    if (CMDDIR==REVERSE)
      return (pin^k);
    else
      return (0^k);
}

UWORD mfo_abv_curt(UWORD pin,UWORD k){      // Above Current detect//

    if (ABV_CURT==1)
        return (pin^k);
    else
	    return (0^k);
}
UWORD mfo_low_curt(UWORD pin,UWORD k){      // Below Current detect//

    if (ABV_CURT==0)
        return (pin^k);
    else
	    return (0^k);
}
UWORD mfo_abv_spa(UWORD pin,UWORD k){      // Above Speed Area//

    if (ABV_SPDA==1)
        return (pin^k);
    else
	    return (0^k);
}
UWORD mfo_abv_PGspa(UWORD pin,UWORD k){      // #16698 PG speed Above Speed Area for NRG//James, 2021/08/09

    if (ABV_PGSPDA==1)
    {
        // Rational351466, Special.Kung, 2023/07/10
        if(Error == 0)
        {
            Error = PGF3_ERR;
        }
        return (pin^k);
    }
    else
    {
        return (0^k);
    }
}
UWORD mfo_low_spa(UWORD pin,UWORD k){      // Below Speed Area//

    if (ABV_SPDA==0)
        return (pin^k);
    else
	    return (0^k);
}
UWORD mfo_chg2Y(UWORD pin,UWORD k){      // Change to Y-connected

    if ((MFO_YCON==1)&&(MFO_DCON==0)){
        if ((DCONNECTOK==0)&&(YOnCNT>=(pr[YDDELAYT]>>1)))
            return (pin^k);
        else
            return 0;        
    }
    else{
        YOnCNT = 0;
        return 0;
    }
}
UWORD mfo_chg2D(UWORD pin,UWORD k){      // Change to Delta-connected

    if ((MFO_DCON==1)&&(MFO_YCON==0)){
        if ((YCONNECTOK==0)&&(DOnCNT>=(pr[YDDELAYT]>>1)))
            return (pin^k);
        else
            return 0;
    }
    else{
        DOnCNT = 0;
        return 0;
    }
}
UWORD mfo_foutzero(UWORD pin,UWORD k){		// fout, Zero Speed

        if ((fout.uw.hi==0)&&(RUNNING==RUN))
          return (pin^k);
        else
          return (0^k);
}
UWORD mfo_foutzerostp(UWORD pin,UWORD k){	// fout, Zero Speed, include drive stop

        if (fout.uw.hi==0)
          return (pin^k);
        else
          return (0^k);
}
UWORD mfo_faultoption1(UWORD pin,UWORD k){

	if (pr[ERR_OPTM]==0){
		if ((uwFaultBitCode & pr[ERR_OPT1])!=0)
			return (pin^k);
		else
			return (0^k);
	}
	else{
		if ((MFI_ubFaultBit & 0x01)!=0)
			return (pin^k);
		else
			return (0^k);
	}
}
UWORD mfo_faultoption2(UWORD pin,UWORD k){
	if (pr[ERR_OPTM]==0){
		if ((uwFaultBitCode & pr[ERR_OPT2])!=0)
			return (pin^k);
		else
			return (0^k);
	}
	else{
		if ((MFI_ubFaultBit & 0x02)!=0)
			return (pin^k);
		else
			return (0^k);
	}
}
UWORD mfo_faultoption3(UWORD pin,UWORD k){
	if (pr[ERR_OPTM]==0){
		if ((uwFaultBitCode & pr[ERR_OPT3])!=0)
			return (pin^k);
		else
			return (0^k);
	}
	else{
		if ((MFI_ubFaultBit & 0x04)!=0)
			return (pin^k);
		else
			return (0^k);
	}
}
UWORD mfo_faultoption4(UWORD pin,UWORD k){
	if (pr[ERR_OPTM]==0){
		if ((uwFaultBitCode & pr[ERR_OPT4])!=0)
			return (pin^k);
		else
			return (0^k);
	}
	else{
		if ((MFI_ubFaultBit & 0x08)!=0)
			return (pin^k);
		else
			return (0^k);
	}
}
UWORD mfo_OnPosition(UWORD pin,UWORD k){
	if (ONPosition==1)
		return (pin^k);
	else
		return (0^k);
}

UWORD mfo_atFSET(UWORD pin,UWORD k){        // At Setpoint Speed

       UWORD bx;
	
    	if (fout.uw.hi >= fkey.uw.hi)
			bx = fout.uw.hi - fkey.uw.hi;
    	else
			bx = fkey.uw.hi - fout.uw.hi ;

		if (bx <= 200)            //+- 2.0Hz
        	return (pin^k);
    	else if (bx > 400)        //+- 4.0Hz
        	return (0^k);
		else 
			return (pin&mfo_now);
}
UWORD mfo_atFSET_Band(UWORD pin,UWORD k){        // At Setpoint Speed//Band of Speed Agree Function #18572

       UWORD bx;
        
        if(btGearFlag==0)      //[JES Gear no output MO=2, Special.Kung, 2022/10/12]
        {
        	//if (fout.uw.hi >= fkey.uw.hi)
        		//bx = fout.uw.hi - fkey.uw.hi;
        	//else
        		//bx = fkey.uw.hi - fout.uw.hi ;

            //[JES test IM with slip and Relay(MO=2) will always ON/OFF, Special.Kung, 2022/12/21]
            if (fcmd.uw.hi >= fkey.uw.hi)
    			bx = fcmd.uw.hi - fkey.uw.hi;
        	else
    			bx = fkey.uw.hi - fcmd.uw.hi ;

		if (bx <= pr[SpdAgree_B])            
        	return (pin^k);
    	else if (bx > pr[SpdAgree_B])       
        	return (0^k);
		else 
			return (pin&mfo_now);
        }
}

UWORD mfo_EPS_MODE(UWORD pin,UWORD k){ //[EPS MO Output,Lyabryan,2018/06/19]

    if (MO_EPS_SWITCH)
            return (pin^k);
        else
            return (0^k);
}

UWORD mfo_multiposition(UWORD pin,UWORD k){	// Multi-position

	if (MultiONPosition==1)
		return (pin^k);
	else
		return (0^k);
}

UWORD mfo_Fault2(UWORD pin,UWORD k){   // Fault Output including delay time

    if (ERR_MO)
        return (pin^k);
    else
        return (0^k);
    
}

UWORD mfo_gen_ok(UWORD pin,UWORD k){      // Generation Operation detected ok//

    if (GEN_OK==1)
        return (pin^k);
    else
	    return (0^k);
}

UWORD mfo_gen_dir(UWORD pin,UWORD k){      // Generation Operation Direction//

    if (GENDIR==1)
        return (pin^k);
    else
	    return (0^k);
}

UWORD mfo_AFE_RST(UWORD pin,UWORD k){ //[AFE Error Handle/Lyabryan/2022/03/24]

    if (AFE_ERR_TMR)
        return (pin^k);
    else
        return (0^k);
}

UWORD mfo_STO_OUT(UWORD pin,UWORD k){  
	//#12225,STO short detect, James for 04-49=4~7, 2021/10/14
     if((pr[STO_LOCK] == 0x0000) || (pr[STO_LOCK] == 0x0002))//06-49=0,2
     {
         if((Error ==STOL_ERR) || (Error ==STOL1_ERR) || (Error ==STOL2_ERR) || (Error ==STOL3_ERR))
         {
            return (pin^k);  
         }
         else
         {
            return (0^k);
         }
     }
     else//06-49=1,3~7
     {
         if((STOLOSS ==1) && (TB1_uwSTOErrCnt >= STO_ERR_CNT))//STO delay, James, 2021/10/25
         {
            return (pin^k);  
         }
         else
         {
            return (0^k);
         }
     }
}

UWORD mfo_IMEnable(UWORD pin,UWORD k){
    if (MOTORCONNECTOR2)
        return (pin^k);
    else
        return (0^k);		
}

//DLC function, Henry, 2016/07/20 [

UWORD mfo_DLC_UP(UWORD pin,UWORD k){
	if(DLC_ubDIR == DIR_UP)
		return (pin^k);
	else
		return (0^k);
}

UWORD mfo_DLC_DN(UWORD pin,UWORD k){
	if(DLC_ubDIR == DIR_DN)
		return (pin^k);
	else
		return (0^k);
}

//]

UWORD mfo_fault_rst(UWORD pin,UWORD k){   //[Add auto restart after fault, Bernie, 06/06/12]

    if(RST_EN==1)
        return (pin^k);
        
    else
	    return (0^k);      
}

//DLC function, Henry, 2016/07/20
UWORD mfo_DLCLevOn(UWORD pin,UWORD k){

    if((DLC_btLU == 1) && (DLC_btLD == 1) && (fcmd.uw.hi == 0)){
      return (pin^k);  
    }
    else{
	    return (0^k);
	  }      
}
UWORD mfo_star_Contactor(UWORD pin,UWORD k){
    if (STAR_OUTPUT)
        return (pin^k);
    else
        return (0^k);
}

UWORD mfo_Torq_Detect(UWORD pin,UWORD k)
{
    if (MFO_btTorqDetect)
        return (pin^k);
    else
        return (0^k);
}

#ifdef _MFIO_C
	#undef _MFIO_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************
not put anything after this part!!!!!!!!!!!
*************************************************************************/

