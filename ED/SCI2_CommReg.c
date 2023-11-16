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
#ifndef _CommReg_C
	#define _CommReg_C
#endif

#include "ProgHeader.h"

UWORD BLKTransferRead(UWORD prx)
{
    UBYTE ax,gx,px;
    
    /*-------- Block Transfer Read --------*/
    prx = pr[prx];
  #if 1
    gx = (UBYTE)(prx/100);
    px = (UBYTE)(prx%100);  	
  #else
    gx = (UBYTE)((prx&0xff00)>>8);
    px = (UBYTE)(prx&0x00ff);
  #endif  
    if (SHOW_ALLPR==1)
        ax = GRALL;
    else{
    	// [ 00-02 Setting, DINO, 06/03/2010
    	
        if (SHOW_ENHANCE==1)
            ax = GRENHANCE;
        else
        
        // ]
    	    ax = GRUSER;            
	}
            
    if (gx <= ax) {         // group NO. //
        if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
        	ax = pr_gpno_Sibo[gx];
        else
        	ax = pr_gpno[gx];
       
     
     
        if (px < ax) {      // function NO. //
            prx = (UWORD)prtab[gx]+px;       // pr index //
            return (pr[prx]);
        }
        else
            return 0;   // Illegal function NO. //
    }
    else
        return 0;       // Illegal group NO. //
    /*-------- End of Block Transfer Read --------*/
}

void VFDStatus(void)	//main.c
{    
	UBYTE ubLEDS5;
	UWORD_UNION ax;

	ax.uw = 0;

	ubLEDS5 = led.s5;

	// [ Modify the LED Index, DINO, 09/28/2010
	if (RUNNING == RUN){
		if(CMDDIR == FORWARD){
    		ubLEDS5 = ubLEDS5 & ~LED_DN | LED_UP;
		}
		else {
    		ubLEDS5 = ubLEDS5 & ~LED_UP | LED_DN;
		}

		if(CMDDIR != WGDIR ){   // CMDDIR !=WGDIR, change Direction command, speed down
			if(CMDDIR == FORWARD){       // forward command >> REVLED blink
				if(LEDBLINK)
					ubLEDS5 |= LED_DN;
				else
					ubLEDS5 &= ~LED_DN;
			}
			else {      // reverse command >> FWDLED blink
				if(LEDBLINK)
					ubLEDS5 |= LED_UP;
				else
					ubLEDS5 &= ~LED_UP;
			}
		}
	}
	else{
		ubLEDS5 &= (~LED_UP & ~LED_DN);
	}

    if((STANDBY)||((CMDRUN==RUN)&&(Error==bb_ERR))){
        ax.ub.low = ax.ub.low | 0x02;         // STANDBY: bit1,0=10
    }
    else if((CMDRUN)&&(RUNNING)){
        ax.ub.low = ax.ub.low | 0x03;         // RUN: bit1,0=11
	}
    else if((!CMDRUN)&&(RUNNING)){
        ax.ub.low = ax.ub.low | 0x01;         // speed down: bit1,0=01
    }
    else if ((!CMDRUN)&&(!RUNNING)){
        ax.ub.low = ax.ub.low & 0xFC;
    }

	if(CMDJOG)
        ax.ub.low = ax.ub.low | 0x04;         // JOG Active: bit2

    // Low Byte bit 4 3
    // Forward    = 0 0 =0x00
    // Rve -> Fwd = 0 1 =0x01
    // Fwd -> Rev = 1 0 =0x10
    // Reverse    = 1 1 =0x18

	if(CMDDIR != WGDIR ){   // CMDDIR !=WGDIR, change Direction command, speed down
		if(CMDDIR == FORWARD){       // forward command >> REVLED blink
			ax.ub.low = ax.ub.low | 0x08;    // rev -> fwd
		}
		else {      // reverse command >> FWDLED blink
			ax.ub.low = ax.ub.low | 0x10;    // fwd -> rev
		}
	}
    else {     // CMDDIR == WGDIR
		if(CMDDIR == FORWARD){
			//ax.ub.low = ax.ub.low & 0xe7;
		}
		else {
			ax.ub.low = ax.ub.low | 0x18;
		}
	}
	// ] End of 09/28/2010

	led.s5 = ubLEDS5;	// LED KEYPAD Update, DINO, 03/12/2010

	//  [ DINO,04/06/2010
    if((SHOW_ALLPR)||(SHOW_ENHANCE))
   // if ( SHOW_ALLPR )  
		ax.ub.low = ax.ub.low | 0x20;   // bit5
	// ]

    if((MFI_AVI)||(MFI_ACI)||(MFI_AUI)||(pr[SOFC]>1))
       ax.ub.hi = ax.ub.hi | 0x02;     // HB.bit0(bit9), freq. command external(AVI/ACI/AUI)
    else if((pr[SOFC]==0)||(pr[SOFC]==1))  //else if((fc_source==4)||(fc_source==5)||FREM_ON)
       ax.ub.hi = ax.ub.hi | 0x01;     // HB.bit0(bit8), freq. command by remote

    // HB.bit2(bit10), control by remote
    if(PUEN3||PUEN2||pr[SOOC]==2)      // Modify by DINO, 05/13/2008
      ax.ub.hi = ax.ub.hi | 0x04;

    if(PRLOCK==1 || FSET_LOCK==1)
       ax.ub.hi = ax.ub.hi | 0x08;     // HB.bit3(bit11), Parameter been locked

    if(COPYEN==1)
       ax.ub.hi = ax.ub.hi | 0x10;     // HB.bit4(bit12) Enable to Copy

    C21xx[0x19] = ax.uw;               // 2119H, for delta standard TY

    //***************** Dynamic Data Exchange Define **********************
    // for 2305H
    if(KC23xx[0x05]&0x8000)         // 2305H.b15: Reflash the Comm Page
       ax.ub.hi |= 0x80;            // 0 ->1
       
	KC23xx[0x05] = ax.uw;         // 2305H
    
    Update_C21xx();
    Update_C22xx();
    // [ Display Group for VLI, DINO, 03/22/2010
    //Update_C2Axx();
    // ]
    
    KC23xx[0x04]=(((UWORD)WarnCode)<<8) + Error;  // 2304H      

}

void PCRemote2001H(UWORD datac)
{
    UWORD ax, uwParData;

	if (pr[CTRLM]!=TQCPG)
	{    
        if (pr[U_SET]==0)
		{    
			// [ Change Velocity Data, Add by DINO, 05/25/2009
			if (pr[UNITSEL] == 1)		// m/s
			{	
				uwParData = flMetric2Hz(datac);
			}
			else if(pr[UNITSEL] == 2)	// ft/s
			{	
				uwParData = Ft2Hz(datac);
			}
            //else if(pr[UNITSEL] == 3){	// ft/s
				//uwParData = Ft2Hz(datac);
			//}
			else
			{
				uwParData = datac;
			}
			// ]
            //[Gfc DLC modify,Henry,2018/05/23]
            //if (((pr[SOFC]<=1)||(pr[SOFC]==4))&&(uwParData<=pr[FMAX])&&(speed==0)){ //Source of operation control
			if (((pr[SOFC]<=1)||(pr[SOFC]==4)||(pr[SOFC]==5))&&(uwParData<=pr[FMAX])&&(speed==0))	//Source of operation control
			{ 
				// [ Change Velocity Data, Add by DINO, 05/25/2009
                C20xx[0x01] = uwParData;
	            uwFkeypad = uwParData;
				// ]
	            fkey.uw.hi = uwFkeypad;
            
	        }
	    }
	    else
		{
	    	    //[Gfc DLC modify,Henry,2018/05/23]
            //if (((pr[SOFC]<=1)||(pr[SOFC]==4))&&(datac<=KPDmax)&&(speed==0)){ //Source of operation control
            if (((pr[SOFC]<=1)||(pr[SOFC]==4)||(pr[SOFC]==5))&&(datac<=KPDmax)&&(speed==0))	//Source of operation control
			{ 
	            KPDset = datac;
	            ax = U16xU16divU16(datac, pr[FMAX], KPDmax);
	            uwFkeypad = ax;
	            fkey.uw.hi = uwFkeypad;
	            C20xx[0x01] = uwFkeypad;
	        }
	    }
	}
	else	//6a23j** Torque mode Speed limit by keypad
	{  
		if (pr[SPLIMIT_SL]==1)
		{		    
            //[Gfc DLC modify,Henry,2018/05/23]
            //if ((pr[SOFC]<=1)||(pr[SOFC]==4)){
            if ((pr[SOFC]<=1)||(pr[SOFC]==4)||(pr[SOFC]==5))
			{ 
                C20xx[0x01] = datac;
   			    if (pr[U_SET]==0)
				{
    	            uwFkeypad = datac;
    	            fkey.uw.hi = uwFkeypad;
    	        }
    	        else
				{
    	            KPDset = datac;
    	            ax = U16xU16divU16(datac, pr[FMAX], KPDmax);
    	            uwFkeypad = ax;
    	            fkey.uw.hi = ax;
    	        }
    	    }  
		}
		else
		{
            fkey.ul = 0;
		}
	}//6a23j&& Torque mode Speed limit by keypad
}

void PCRemote20xxH(UBYTE func,UWORD datac)
{
  
  	switch (func) {
    	case 0x00:{ //2000H
			if ((pr[SOOC]==2)||(PUON3LINE && OPKEY_LOCK==0)){  		//SCOTTY 08/31/2007
               	PCRemote2000H(datac);
			}                
            }break;
        case 0x01:{ //2001H: Frequency Command
        	if ((pr[SOFC]==1)||(PUON3LINE && OPKEY_LOCK==0)){
                PCRemote2001H(datac);    	
            }
            }break;
        case 0x02:{ //2002H
        	Keypad_2002H(datac);
            C20xx[0x02] = datac;
        	}break;
        case 0x03:{ //2003H: User Defined setpoint low
        	C20xx[0x03] = datac;
        	}break;
        case 0x04:{ //2004H User defined setpoint high
        	C20xx[0x04] = datac;
        	}break;
        case 0x05:{ //2005H
        	if ((pr[SOOC]==2)||(PUON3LINE && OPKEY_LOCK==0)){	//SCOTTY 08/31/2007
        	    Keypad_2005H(datac);
        	    C20xx[0x05] = datac;
        	}
            }break;
        default:
            break;
    }   
}

void PCRemote2000H(UWORD datac)
{
    UWORD ax;
  
    ax = datac & 0x6000;
    if (ax != 0) {//=========== bit 14,13, PU on/off ========
        switch(ax){
            case 0x2000:{    //bit13: operation control by PU
                PUON3 = 1;
            } break;
            case 0x4000:{    //bit14: operation control by Pr setting
                PUON3 = 0;
            } break;
            case 0x6000:{    //bit14 & 13: switch between PU and Pr setting
                if (PUON3==1)
                    PUON3 = 0;
                else
                    PUON3 = 1;
            } break;
            default:
            break;
        } // end of [ switch(ax) ]
        if (PUON3==1)
            PUEN3 = 1;
        else
            PUEN3 = 0;
    }  // end of [ if(ax != 0) ], bit 14,13, PU on/off
    
    if ((pr[SOOC]==2)||PUEN2||PUEN3){	//SCOTTY 08/31/2007
        //========================= bit4,5: direction select
        ax = datac & 0x0030 ; // bit4,5: direction select
     if ((ax!=0)&&(TUN_START==0)&&((PWM_Status.ub&0x42)==0)&&(!EPS_MODE4)){ //[EPS autodetect dir,Lyabryan,2018/07/02]  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
            switch(ax) {
                case 0x10: {          // forward direction
                    if (pr[SETDIR]!=2) {    // disable forward 
                        CMDDIR=FORWARD;
                        if (RUNNING==STOP)
                            WGDIR = FORWARD;
                    }
                } break;
                case 0x20: {          // reverse direction
                    if (pr[SETDIR]!=1) {    // disable reverse
                        CMDDIR=REVERSE;                  
                        if (RUNNING==STOP)
                            WGDIR = REVERSE;
                    }
                } break;
                case 0x30: {          // change direction
                    fwd_rev();
                } break;
                default:
                    break;
            } // end of [ switch(ax) ], ax=(pr_data & 0x0030), bit4,5: Direction select
        }    
        //========================= bit0,1: run/stop/jog
        ax = datac & 0x0003 ; // bit0,1: run/stop/jog
        switch(ax) {
            case 1: {             // stop command
                stop();
            }break;
            case 2: {             // run command
                if (!CMDJOG)
                    run();
            }break;
            case 3: {             // jog command
                if ((RUNNING==0)||CMDJOG){
                	if (/*(speed==0)&&*/((pr[PIDSL]==0)||(MFI_PIDDIS))){
	                    CMDJOG = 1;
	                    run();
	                    CMDJOG = 1;
	                }
                }
            }break;
            default:
            break;
        }       
        //------ Multi-speed ------  
        if (datac & 0x1000) {  // bit.12=1 -> remote multi_speed setup
            // set ext. multi_speed disable
            speed = ((UBYTE)((datac & 0x0f00)>>8)) ; // bit11~8 multi-step
            acc_dec = ((UBYTE)((datac & 0x00c0)>>6)) ; // bit6,7 1,2,3,4 acc/decc selection
            MFI_REMOTE = 1;
        }
        else 
            MFI_REMOTE = 0;
    }
    C20xx[0x00] = datac;
}


void Update2116(void)
{
	UWORD_UNION Unit;
	UWORD uwFkey, uwFout;
	C21xx[0x17] = 0x00A0;	// DINO,03/03/2010

	// [ Unit Description of User Page, DINO, 08/13/2010
	Unit.ub.hi = sfrinfo[MFD_page].x[16];
	Unit.ub.low = sfrinfo[MFD_page].x[17];
	C21xx[0x21] = Unit.uw;
	Unit.ub.hi = sfrinfo[MFD_page].x[18];
	Unit.ub.low = sfrinfo[MFD_page].x[19];
	C21xx[0x22] = Unit.uw;
	// ]

	//[User page reserve jump, Bernie, 08/05/2011]
    if(MFD_page == 1){
        if(ubpage == 1)
           MFD_page = 2;
        else
           MFD_page = 0;
    }
    if(MFD_page == 12){
        if(ubpage == 1)
           MFD_page = 13;
        else
           MFD_page = 11;
    }
	if(MFD_page == 21 || MFD_page == 23){
        if(ubpage == 20)
           MFD_page = 24;
        else
           MFD_page = 20;
    }

    switch(MFD_page){
        
        case 0:		//Output Current
        	C21xx[0x17] = 'A';
        	C21xx[0x17] |= 0x0200;	//dot = 2;
        	if(CC4KeyPad){              //[CC Display, Bernie, 2017/04/12]
                C21xx[0x16] = pr[I_RATE2]*9/5;
               }
            else{
        	C21xx[0x16] = IrmsReLPF.sw.hi;
                }
			ubpage = 1;       //[User page reserve jump, Bernie, 08/05/2011]
        	break;

/*        case 1:		//Counter
        	//C21xx[0x17] = 0x0800;
        	//C21xx[0x16] = trg_cnt;
        	break;
*/        	
        case 2:     //Actual Motor Hz        	

        	if (slMotorHz>=0){
        		C21xx[0x17] = ('H'&0x7F) & 0x7FFF;
        	}
			else{
				C21xx[0x17] = '-' | 0x8000;
			}
    		if (pr[UNITSEL] != 4){  // RPM Display, DINO, 03/25/2010
    			C21xx[0x17] |= 0x0200;	//dot = 2;
    		}
			// [ Velocity Unit Change, Add by DINO, 05/25/2009
        	C21xx[0x16] = uwAbsMotorHz;
        	// ]
        	ubpage = 2;        //[User page reserve jump, Bernie, 08/05/2011]
        	break;
        	
        case 3:		//Dcbus
        	C21xx[0x17] = 'V'; 	//U-bus
        	C21xx[0x17] |= 0x0100;	//dot = 1;
        	C21xx[0x16] = DcbusDCLPF.sw.hi;
        	break;
        	
        case 4:		//Output Voltage
        	C21xx[0x17] = 'E';
        	C21xx[0x17] |= 0x0100;
            C21xx[0x16] = VcmdLLPF.sw.hi;
        	break;
        	
        case 5:		//Power Factor
        	C21xx[0x17] = 'n';
        	C21xx[0x17] |= 0x0100;	//dot 1
        	C21xx[0x16] = PF_ANGLE;
        	break;

//--- Modify by DINO, 09/22/2008
        case 6:		//Output Power
        	if ((Pinput.uw.hi&0x8000)==0){
            	C21xx[0x17] = 'P' & 0x7FFF;
        		C21xx[0x16] = Pinput.uw.hi;
        	}
            else{
            	C21xx[0x17] = '-' | 0x8000;
        		C21xx[0x16] = 0xffff - Pinput.uw.hi + 1;
        	}
        	C21xx[0x17] |= 0x0200;	//dot 2

        	break;
//--- End on 09/22/2008

        case 7:		//Motor RPM            
            if (swMotorRpm>=0)
            	C21xx[0x17] = 'r' & 0x7FFF;            	
            else
            	C21xx[0x17] = '-' | 0x8000;

          	C21xx[0x16] = abs(swMotorRpm);
        	break;

        case 8:		//Torque
            //if (TorqueOut>=0)
            //if(TqC_swTqCmd>=0)
            if (swTqRefPu >= 0)
				C21xx[0x17] = 't' & 0x7FFF; //[Uniform char, Bernie, 08/05/2011]
		    else
		      	C21xx[0x17] = '-' | 0x8000;
          	C21xx[0x17] |= 0x0100;	//dot = 1;

          	// [ Display Torque Output %, DINO, 09/30/2009
        	C21xx[0x16] = abs(swTqRefPu); // 080318 by tj
			// ]
        	break;
        	
        case 9:		//PG Feedback        	
            C21xx[0x17] = 'G';       
        	  C21xx[0x16] = APR_uwPGPosition;
        	break;
       	
        // [ Display Electrical Angle, Add by Sampo, 04/22/2009
        case 10:		//Electric Angle
        	C21xx[0x17] = 'd';
        	C21xx[0x16] = uwElecAngle;
        	C21xx[0x17] |= 0x0100;	//dot = 1;
        	break;
        // ]

        case 11:	//AUI1 AD
        	if (swAVICalib>=0)
            	C21xx[0x17] = '1' | 0x0080 & 0x7FFF;
            else
            	C21xx[0x17] = '-' | 0x8000;
			C21xx[0x17] |= 0x0100;   //dot 1
        	// [ Modify the scale of swAVICalib, DINO, 06/17/2009
        	C21xx[0x16] = abs(swAVICalib);
        	// ]
        	ubpage = 1;    //[ACI function remove, Bernie, 01/20/2012]
        	break;

        /*case 12:		//ACI AD
        	C21xx[0x17] = '2' | 0x0080;
			C21xx[0x17] |= 0x0100;   //dot 1
        	// [ Modify the scale of swACICalib, DINO, 06/17/2009
        	C21xx[0x16] = swACICalib;
        	// ]
        	break;*/          //[ACI function remove, Bernie, 01/20/2012]

        case 13:		//AUI2 AD
        	if (swAUICalib>=0)
            	C21xx[0x17] = '3' | 0x0080 & 0x7FFF;
            else
            	C21xx[0x17] = '-' | 0x8000;
			C21xx[0x17] |= 0x0100;   //dot 1
         	// [ Modify the scale of swAUICalib, DINO, 06/17/2009
			C21xx[0x16] = abs(swAUICalib);
			// ]
			ubpage = 2;    //[ACI function remove, Bernie, 01/20/2012]
        	break;

        case 14:        //TH1
            if ( HS_Temp >= 0 ){
            	//C21xx[0x17] = 0x00c4 & 0x7FFF;
            	C21xx[0x17] = 't';  //[Uniform char, Bernie, 08/05/2011]
        		C21xx[0x16] = HS_Temp;
        	}
            else{
            	C21xx[0x17] = '-' | 0x8000;
        		C21xx[0x16] = -HS_Temp;
            }
            C21xx[0x17] |= 0x0100;   //dot 1
        	break;

        case 15:        //TH2
            if ( IGBT_Temp >= 0 ){
            	//C21xx[0x17] = 0x00bd & 0x7FFF;
            	C21xx[0x17] = 'T';   //[Uniform char, Bernie, 08/05/2011]
        		C21xx[0x16] = IGBT_Temp;
        	}
            else{
            	C21xx[0x17] = '-' | 0x8000;
        		C21xx[0x16] = -IGBT_Temp;
            }
            C21xx[0x17] |= 0x0100;   //dot 1
        	break;

        case 16:        //DI, Multi-Function input ON/OFF Status
            C21xx[0x17] = 'i';
            C21xx[0x17] |= 0x4000;             //[Hex display for user define page, Bernie, 2016/02/16]
        	C21xx[0x16] = mfi_status;
        	break;

        case 17:        //DO, Multi-Function output ON/OFF Status
            C21xx[0x17] = 'o';
            C21xx[0x17] |= 0x4000;             //[Hex display for user define page, Bernie, 2016/02/16]
        	C21xx[0x16] = mfo_status;
        	break;

        case 18:        //Multi-speed status
            C21xx[0x17] = 'S'& 0x7FFF;  //[Uniform char, Bernie, 08/05/2011]
			C21xx[0x16] = speed;
        	break;

        case 19:        //DI, Multi-Function input Pin Status
            C21xx[0x17] = 0xc4 & 0x7FFF;   //[Uniform char, Bernie, 08/05/2011]
            C21xx[0x17] |= 0x4000;             //[Hex display for user define page, Bernie, 2016/02/16]
        	C21xx[0x16] = (0xffff - mfi_now);
        	break;

        case 20:        //DO, Multi-Function output Pin Status
            C21xx[0x17] = 0xca & 0x7FFF;   //[Uniform char, Bernie, 08/05/2011]
            C21xx[0x17] |= 0x4000;             //[Hex display for user define page, Bernie, 2016/02/16]
        	C21xx[0x16] = (0xffff - mfo_now);	// DINO, 07/05/2010
        	ubpage = 20;               //[User page reserve jump, Bernie, 08/05/2011]
        	break;
/*        	
        case 21:        //Running number of Encoder (Channel 1)
            C21xx[0x17] = CHAR_Z;
        	C21xx[0x16] = APR_uwZpulseCnt;
        	break;
        	
        case 22:		//Pulse Input Frequency (Channel 2)
        	C21xx[0x17] = CHAR_4;
            C21xx[0x17] |= 0x0200;   //dot 2
        	C21xx[0x16] = PG2_ulSpdCmdLPF.uw.hi;
        	break;
        	
        case 23:		//Pulse Input Position (Channel 2)
        	C21xx[0x17] = (CHAR_4|0x80);
        	C21xx[0x16] = APR_uwPG2PCom;
        	break;
*/        	
        case 24:		//Error Vout
        	C21xx[0x17] = 'E';
        	C21xx[0x17] |= 0x0100;
            C21xx[0x16] = pr[VOUT_REC];
			ubpage = 24;    //[User page reserve jump, Bernie, 08/05/2011]
        	break;

        case 25:		//Error Vbus
        	C21xx[0x17] = 0x76; 	//U-bus
        	C21xx[0x17] |= 0x0100;	//dot = 1;
        	C21xx[0x16] = pr[DCBUS_REC];
        	break;

        case 26:    	//Error Ffbk
       		C21xx[0x17] = 'H';
    		C21xx[0x17] |= 0x0200;	//dot = 2;     			
        	C21xx[0x16] = pr[FFBK_REC];
        	break;

        case 27:		//Error Current
        	C21xx[0x17] = 'A';
        	C21xx[0x17] |= 0x0200;	//dot = 2;
        	C21xx[0x16] = pr[ISUM_REC];
        	break;

        case 28:		//Error Fout
       		C21xx[0x17] = 'F';
    		C21xx[0x17] |= 0x0200;	//dot = 2;     			
        	C21xx[0x16] = pr[FOUT_REC];
        	break;

		case 29:        //Error Fcmd
		    C21xx[0x17] = 'F';
			C21xx[0x17] |= 0x0200; // dot2
			C21xx[0x16]  = pr[FKEY_REC];
			break;

		case 30:		//Error Output Power
        	if ((Pinput.uw.hi&0x8000)==0){
            	C21xx[0x17] = 'P' & 0x7FFF;
        		C21xx[0x16] = pr[POWER_REC];
        	}
            else{
            	C21xx[0x17] = '-' | 0x8000;
        		C21xx[0x16] = 0xffff - pr[POWER_REC] + 1;
        	}
        	C21xx[0x17] |= 0x0200;	//dot 2
			break;
			
		case 31:		//Error Output Torque
       		// [ Add Minus Display, DION, 09/30/2009
           if ((pr[TQ_REC]&0x8000)==0){
				C21xx[0x17] = 't' & 0x7FFF; 
       			C21xx[0x16] = pr[TQ_REC];
       		}
		    else{
		      	C21xx[0x17] = '-' | 0x8000;
       			C21xx[0x16] = 0xffff - pr[TQ_REC] + 1;
		    }
		    // ]
          	C21xx[0x17] |= 0x0100;	//dot = 1;
			break;

		case 32:        //Error DI Status
            C21xx[0x17] = 'i';
            C21xx[0x17] |= 0x1000;
        	C21xx[0x16] = pr[MFI_REC]^pr[MI_INV];
			break;

		case 33:        //Error DO Status
            C21xx[0x17] = 'o';
            C21xx[0x17] |= 0x1000;
        	C21xx[0x16] = pr[MFO_REC]^pr[MO_INV];
			break;

		case 34:        //Error Drive Status
		    C21xx[0x17]  = 's';
			C21xx[0x17] |= 0x1000;  // hex
			C21xx[0x16]  = pr[STATE_REC];
			break;
			
       case 36:		//CAN fail rate	Aevin add-6/14/2017   //[CAN fail rate function, Aevin, 2017/06/14]
			C21xx[0x17]  = 'c';
			C21xx[0x16]  = uwPDOfailBuf;
			break;

	    case 37:     //[PG quality function, Bernie, 2017/06/20]
	        C21xx[0x17]  = 'q';
			C21xx[0x17] |= 0x0100;
			C21xx[0x16]  = TB1_swPGQualityDsp;
			break;
        case 40://show direction & real speed in m/s,#16698 for NRG, James, 2021/08/09  
        
            if (slMotorHz>=0){
                C21xx[0x17] = ('+'&0x7F) & 0x7FFF;
            }
            else{
                C21xx[0x17] = '-' | 0x8000;
            }
            C21xx[0x17] |= 0x0200;  //dot = 2;
            C21xx[0x16] = Hz2Metric(abs(slMotorHz));
            break;
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	    case 38:     //[Velocity m/s or ft/s, Bernie, 2017/06/20]
	        C21xx[0x17]  = 'v';
			C21xx[0x17] |= 0x0200;		
			// [ Velocity Unit Change, Add by DINO, 03/25/2010
			if (pr[U_SET]!=0){
				uwFkey = KPDset;
			}	 
			else {
				if (pr[UNITSEL] == 1){	// Hz->m/s
					uwFkey = flHz2Metric(fkey.uw.hi);
				}
				else if(pr[UNITSEL] == 2){	// Hz->ft/s
					uwFkey = Hz2Ft(fkey.uw.hi);
				}
				else{
					uwFkey = fkey.uw.hi;
				}
			}
			//]
			C21xx[0x16]  = uwFkey;	
			/* Unit */
			if(pr[UNITSEL]==2){
				Unit.ub.hi = sfrinfo_vel_sel[1].x[16];
				Unit.ub.low = sfrinfo_vel_sel[1].x[17];
				C21xx[0x21] = Unit.uw;
				Unit.ub.hi = sfrinfo_vel_sel[1].x[18];
				Unit.ub.low = sfrinfo_vel_sel[1].x[19];
				C21xx[0x22] = Unit.uw;
			}
			break;        
		case 39:	 //[PG quality function, Bernie, 2017/06/20]
			C21xx[0x17]  = 'h';
			C21xx[0x17] |= 0x0200;
			// [ Velocity Unit Change, Add by DINO, 03/25/2010
			if (pr[U_SET]!=0){
				uwFout = U16xU16divU16(KPDmax, fout.uw.hi, pr[FMAX]);
			}	 
			else {
				if (pr[UNITSEL] == 1){	// Hz->m/s
					uwFout = flHz2Metric(fout.uw.hi);
				}
				else if(pr[UNITSEL] == 2){	// Hz->ft/s
					uwFout = Hz2Ft(fout.uw.hi);
				}
				else{
					uwFout = fout.uw.hi;
				}
			}
			//]
			C21xx[0x16]  = uwFout;
			/* Unit */
			if(pr[UNITSEL]==2){
				Unit.ub.hi = sfrinfo_vel_sel[1].x[16];
				Unit.ub.low = sfrinfo_vel_sel[1].x[17];
				C21xx[0x21] = Unit.uw;
				Unit.ub.hi = sfrinfo_vel_sel[1].x[18];
				Unit.ub.low = sfrinfo_vel_sel[1].x[19];
				C21xx[0x22] = Unit.uw;
			}
			break;	
#endif        

        default:
    		C21xx[0x17] = 0;
        	C21xx[0x16] = 0;
        	break;

    }
}

void Update2119(void)
{
        if (PRLOCK==1 || FSET_LOCK==1)      // pr Locked.
          C21xx[0x19] |= 0x0800;
        else
          C21xx[0x19] &= 0xf7ff;
        if (PUEN3||PUEN2||pr[SOOC]==2)   // Source of command.
          C21xx[0x19] |= 0x0400;
        else
          C21xx[0x19] &= 0xfbff;

        if (SHOW_ALLPR==1)  // Factory setting open
          C21xx[0x19] |= 0x0020;
        else
          C21xx[0x19] &= 0xffdf;
        /*
        if (PAGECHG==1)
          C21xx[0x19] |= 0x8000;
        else
          C21xx[0x19] &= 0x7fff;
        */          
}

void Update_C21xx(void)
{  
	UWORD uwFkey, uwFout;

     //---------------- update 2100H ----------------------------------------
     C21xx[0x00] = Error;

     //---------------- update 2101H ----------------------------------------
     // bit 0~4: RUN/STOP & FWD/REV status
     // bit 5  : Reserved Parameter opened
     C21xx[0x01] = (KC23xx[0x05]&0x0F3F);
     
     // bit 7: Operation command Controlled by external terminal
//     if ((pr[SOOC]==1)||(pr[SOOC]==2))
     if ((pr[SOOC]==1))				//SCOTTY 08/31/2007
         C21xx[0x01] = C21xx[0x01] | 0x0080;
     else
         C21xx[0x01] = C21xx[0x01] & 0xff7f;
     
     // bit 8: Source of Freq Command by Communication
     if (pr[SOFC]==1)                               
         C21xx[0x01] = C21xx[0x01] | 0x0100;
     else
         C21xx[0x01] = C21xx[0x01] & 0xfeff;
        
     // bit 9: Source of Freq Command by External Input
     if (pr[SOFC]>=2)
         C21xx[0x01] = C21xx[0x01] | 0x0200;          
     else
         C21xx[0x01] = C21xx[0x01] & 0xfdff;

     // bit 10: Source of operation command by Communication
//     if (pr[SOOC]>=3)
     if (pr[SOOC]==2)
         C21xx[0x01] = C21xx[0x01] | 0x0400;
     else
         C21xx[0x01] = C21xx[0x01] & 0xfbff;
    
     // bit 11: Parameter been Locked
     if (PRLOCK==1 || FSET_LOCK==1)
         C21xx[0x01] = C21xx[0x01] | 0x0800;
     else
         C21xx[0x01] = C21xx[0x01] & 0xf7ff;
    
     // bit 12: Inverter Running(include standby)
     if (RUNNING)
         C21xx[0x01] = C21xx[0x01] | 0x1000;
     else
         C21xx[0x01] = C21xx[0x01] & 0xefff;
        
     //bit 13: JOG command
     if (CMDJOG)
         C21xx[0x01] = C21xx[0x01] | 0x2000;
     else
         C21xx[0x01] = C21xx[0x01] & 0xdfff;
         
    if ((TqSpdMode == 1) && (pr[SPLIMIT_SL] == 0)){
        if (TqC_swTqSetPu >= 0)
            C21xx[0x02] = TqC_uwPSpdLimRe;
        else
            C21xx[0x02] = TqC_uwNSpdLimRe;
    }
    else{
		// [ Velocity Unit Change, Add by DINO, 03/25/2010
        if (pr[U_SET]!=0){
            uwFkey = KPDset;
            uwFout = U16xU16divU16(KPDmax, fout.uw.hi, pr[FMAX]);
        }    
        else {
        	if (pr[UNITSEL] == 1){  // Hz->m/s
				uwFkey = flHz2Metric(fkey.uw.hi);
				uwFout = flHz2Metric(fout.uw.hi);
			}
			else if(pr[UNITSEL] == 2){	// Hz->ft/s
				uwFkey = Hz2Ft(fkey.uw.hi);
				uwFout = Hz2Ft(fout.uw.hi);
			}
			else{
            	uwFkey = fkey.uw.hi;
            	uwFout = fout.uw.hi;
        	}
        }
        if(btGearFlag)
        {
            //C21xx[0x02] = pr[FMI0+speed];
            C21xx[0x02] = fkeyDisplay;   //Freq. Command for vfd-soft/ explore Display
        }
        else
        {
            C21xx[0x02] = uwFkey;
        }

		C21xx[0x03] = uwFout;
		// ]
   	}
        
//    C21xx[0x03] = fout.uw.hi;
    if(CC4KeyPad){                //[CC Display, Bernie, 2017/04/12]
        C21xx[0x04] = pr[I_RATE2]*9/5;
    }
    else{
        C21xx[0x04] = IrmsReLPF.sw.hi;
    }
    C21xx[0x05] = DcbusDCLPF.sw.hi;
    C21xx[0x06] = VcmdLLPF.sw.hi;
    C21xx[0x07] = speed;
    C21xx[0x08] = fcmd.uw.hi;
    C21xx[0x09] = trg_cnt;
    
    if ((RUNNING)&&(STANDBY==0)){
        C21xx[0x0A] = PF_ANGLE;
    }
    else
        C21xx[0x0A] = 0;
        
    Pin_power();    

    //C21xx[0x0B] = TorqueOut;  //6a16j
    C21xx[0x0B] = TqC_swTqCmd;//6116j display Torque input
    
/* Item 46: Marked,    if (pr[PGINPUT]!=0 && PGLOSS==0)	*/
    if (pr[PGINPUT]!=0)
        C21xx[0x0C] = swMotorRpm;
    else
        C21xx[0x0C] = 0;
        
    C21xx[0x0D] = APR_uwTheta;
    C21xx[0x0E] = APR_uwPG2PCom;
    C21xx[0x0F] = Pinput.uw.hi;
    
    //C21xx[0x10] = 0x0200 + pr[HPSPEC];        	//B type ID code
    //C21xx[0x10] = 0x0400 + pr[HPSPEC];          	//V type ID code
    //C21xx[0x10] = 0x0900 + pr[HPSPEC];            //VL type ID code
    
    if(Driver_ID == EDS_DRIVER)
        C21xx[0x10] = (EDS_VFDSOFT_ID<<8) + pr[HPSPEC];          	//[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
    else if(Driver_ID == IEDS_DRIVER)
        C21xx[0x10] = (EDS_VFDSOFT_ID<<8) + pr[HPSPEC];          	//[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
    else if(Driver_ID == NULL)
        C21xx[0x10] = (VL_VFDSOFT_ID<<8) + pr[HPSPEC];          	//[IEDS vs. EDS deriver,Lyabryan,2016/07/14]

  //  if (SHOW_ENHANCE==1)
    	//C21xx[0x11] = GRALL;						// NO. of Grouping ,2111H
//    else
    	//C21xx[0x11] = GRENHANCE;					// NO. of Grouping ,2111H

   if (SHOW_ALLPR==1)  // 00-02 Setting, DINO, 06/03/2010
    	C21xx[0x11] = GRALL;						// NO. of Grouping ,2111H
    else{
    				
    	if (SHOW_ENHANCE==1)
    	   C21xx[0x11] = 15;
    	else
           C21xx[0x11] = 14;
    }
    // ]
    GROUPTmp = C21xx[0x11];
		
    C21xx[0x12] = SWVERS_H;                       	// software version    
    if(pr[S_DISP]== 4)                        //[Start Page, Bernie, 08/08/2011]
	C21xx[0x13] = ((pr[S_DISP]-2) << 8) + pr[U_DISP];
	else if(pr[S_DISP]== 5)                   //[Start Page, Bernie, 08/08/2011]
    C21xx[0x13] = ((pr[S_DISP]-3) << 8) + pr[U_DISP];
	else
    C21xx[0x13] = (pr[S_DISP] << 8) + pr[U_DISP];	// Group name available bit0:1, 2113H
    
    C21xx[0x15] = SpDt_uwFfbk;						// feedback frequency, dino, 05/30/2007
    
    Update2116();
    //------ High: Warning code, Low: Error Code //
    C21xx[0x18] = ((UWORD)WarnCode<<8)+Error;
    Update2119();
    //------ F frame display value --------------//
    C21xx[0x1A] = C21xx[0x02];
    //------ Max of Fcmd ------------------------//
    if (pr[U_SET]==0)
        C21xx[0x1B] = pr[FMAX];
    else
        C21xx[0x1B] = KPDmax;
    //------ H frame display value --------------//
    C21xx[0x1C] = C21xx[0x03];
    //------ Unit of F,H,MaxF, b9-b8 ------------//
    if (VH_EN==0){
      if (pr[U_SET]==0)
            C21xx[0x1D] = 0x0A00;         //[Dot display ,Bernie, 08/10/2011]
        else
            C21xx[0x1D] = (KPDdot<<8);
    }
    else
        C21xx[0x1D] = 0x0100;
    //------ A frame display value --------------//
    C21xx[0x1E] = C21xx[0x04];
    //------ Unit of A, b9-b8 -------------------//
    C21xx[0x1F] = 0x0200;

	// [ Modify F, H Page display for VFD-Cx, DINO, 12/27/2010
	switch (pr[UNITSEL]){
		case 1:
			C21xx[0x23] = ('m'<<8)+'/';
			C21xx[0x24] = ('s'<<8)+' ';
			break;
		case 2:
			C21xx[0x23] = ('f'<<8)+'t';
			C21xx[0x24] = ('/'<<8)+'s';
			break;
		case 3:
			C21xx[0x23] = ('H'<<8)+'z';          //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
			C21xx[0x24] = (' '<<8)+' ';
			break;
		case 4:
			C21xx[0x23] = ('%'<<8)+' ';
			C21xx[0x24] = (' '<<8)+' ';
			break;
		default:
			C21xx[0x23] = ('H'<<8)+'z';
			C21xx[0x24] = (' '<<8)+' ';
			break;
	}
	// ]

	// [ Add Fault Record Data, DINO, 06/11/2009
	// [ 2120H is special for VFD-Cx, DINO, 03/03/2010
//    C21xx[0x20] = pr[FKEY_REC];		// Command Frequency
//    C21xx[0x20] = 0;	// 2120H for VFD-Cx, Delete by DINO, 12/11/2010
    // ]
/*
	C21xx[0x21] = pr[FOUT_REC];		// Output Frequency
	C21xx[0x22] = pr[ISUM_REC];		// Output Current
    C21xx[0x23] = pr[FFBK_REC];		// Motor Frequency
    C21xx[0x24] = pr[VOUT_REC];		// Output Voltage
    C21xx[0x25] = pr[DCBUS_REC];	// DC Bus
    C21xx[0x26] = pr[POWER_REC];	// Power
    C21xx[0x27] = pr[TQ_REC];		// Torque
    C21xx[0x28] = pr[TH_TEMP];		// IGBT Temperature
    C21xx[0x29] = pr[MFI_REC1];		// MI State
    C21xx[0x2A] = pr[MFO_REC];		// MO State
    C21xx[0x2B] = pr[STATE_REC];	// Drive State
*/
	// ]

}

void Update_C22xx(void)
{
    C22xx[0x00] = pv;
    C22xx[0x01] = C21xx[0x16];							//User defined data (low word)
    C22xx[0x02] = C21xx[0x17];							//User defined data (high word)
    // [ Modify the scale of swAVICalib, DINO, 06/17/2009
    C22xx[0x03] = swAVICalib;							// Debug by DINO, 09/08/2008
    C22xx[0x04] = swAUICalib;							// Debug by DINO, 09/08/2008
    C22xx[0x05] = uwtest6;							// Debug by DINO, 09/08/2008
    // ]
    C22xx[0x06] = IGBT_Temp;							//TH1
    C22xx[0x07] = HS_Temp;								//TH2
    C22xx[0x08] = mfi_status;							// Add by DINO, 10/29/2008
    C22xx[0x09] = mfo_status;							// Add by DINO, 10/29/2008
    C22xx[0x0A] = COF_uwPassWord;						// PassWord, Add by DINO, 01/05/2009
    C22xx[0x0B] = AN003;
    C22xx[0x0C] = DebugPAGE;
    C22xx[0x0D] = Zpulse;								// Z capture flag for TE, dino, 05/08/2007
 
    C22xx[0x0E] = AN100;									// Change AN3>AN4, DINO, 03/01/2010
    C22xx[0x0F] = CCSET;   //  CC Flag fot TE, Modify by dino, 10/16/2007	    													//  PC&0020:PC5, Safty Relay B, Sean, 01/25/2010

    C22xx[0x10] = DateCode;   

    //[For MIMO Test, Bernie, 08/12/2011]
    C22xx[0x11] = 0xFF&((S1_C)|(S2_C<<1)|(S1_DC<<2)|(P_5V<<3));          //Digital Input Status (MI1~MI8)
    // [Can function, Bernie, 08/16/2011]
    C22xx[0x12] = RCAN_uwstatus;   //[Modify for CAN function, Bernie, 2014/09/26]
    //if ((pr[DEBUG_F1]&0x8000)==0x8000)
    C22xx[0x13] = KEYDI;
    C22xx[0x14] = ((0xFF&PG_LOSS)|(HALL_LOSS<<1)|(PG_RST<<2));   //[Used For PG ABD LOSS Test, Bernie, 11/03/2011]
    C22xx[0x15] = APR_uwThetaNoMx;             //[Used For PG Feedback Test, Bernie, 11/18/2011]
    //if((pr[DEBUG_F1]&0x0008)==0x0008){            //[ICT program, Bernie, 2014/04/29]
        C22xx[0x16] = AN101;       //ABS_DATA-TGND
        C22xx[0x17] = AN00;        //PGT-TGND
        C22xx[0x18] = AN03;        //TH1
        C22xx[0x19] = AN02;        //TH2
        C22xx[0x1A] = AN001;       //IV
        C22xx[0x1B] = AN000;       //IU
        C22xx[0x1C] = AN002;       //IW
        C22xx[0x1D] = AN100;       //GFF_AD
        C22xx[0x1E] = AN103;       //AI1
        C22xx[0x1F] = AN102;       //AI2
    //}
    //C22xx[0x20] = CAN_uwErrNo;
    //C22xx[0x21] = RCAN_ubErr4Rgst;
    //C22xx[0x30] = DLC_PDO_RX_EM.uw;

    //===== For CAN test  =====//
    //C22xx[0x31] = DLC_SDO_RX_Command;
    //C22xx[0x32] = DLCxx[0x01];; 
    //C22xx[0x33] = DLCxx[0x02];; 
    //C22xx[0x34] = DLCxx[0x03];; 
    //C22xx[0x35] = DLCxx[0x04];;

    C22xx[0x21] = pr[FOUT_REC];		// Output Frequency
	C22xx[0x22] = pr[ISUM_REC];		// Output Current
    C22xx[0x23] = pr[FFBK_REC];		// Motor Frequency
    C22xx[0x24] = pr[VOUT_REC];		// Output Voltage
    C22xx[0x25] = pr[DCBUS_REC];	// DC Bus
    C22xx[0x26] = pr[POWER_REC];	// Power
    C22xx[0x27] = pr[TQ_REC];		// Torque
    C22xx[0x28] = pr[TH_TEMP];		// IGBT Temperature
    C22xx[0x29] = pr[MFI_REC];		// MI State
    C22xx[0x2A] = pr[MFO_REC];		// MO State
    C22xx[0x2B] = pr[STATE_REC];	// Drive State

    
}


void Update_CFFxx(void)
{
    CFFxx[0x01] = IrmsAD;
    CFFxx[0x02] = AD_uwAUI1ad;		// AVI mid
    CFFxx[0x03] = AD_uwACIad;		// ACI mid
    CFFxx[0x04] = AD_uwAUI1ad;		// AVI min
    CFFxx[0x05] = AD_uwAUI1ad;		// AVI max
    CFFxx[0x06] = AD_uwACIad;		// ACI min
    CFFxx[0x07] = AD_uwACIad;		// ACI max
    CFFxx[0x08] = AD_uwAUI2ad ;
    CFFxx[0x09] = AD_uwAUI2ad ;
    CFFxx[0x0A] = AD_uwAUI2ad ;
    CFFxx[0x0C] = uwAFMda ;			// AFM max value
    CFFxx[0x0D] = uwAFMda ;			// AFM min value
    CFFxx[0x0E] = dcbusAD;
    CFFxx[0x0F] = dcbusAD;
    CFFxx[0x10] = dcbusAD;
	CFFxx[0x11] = uwGFF_MaxVal;		//[GFF Maximum Value Record, Jerry Yu, 2019/11/11]
    CFFxx[0x13] = pr[FACTORY1];
    CFFxx[0x14] = pr[FACTORY2];
    CFFxx[0x15] = pr[FACTORY3];
    CFFxx[0x16] = pr[FACTORY4];
}

// [ Display Group for VLI, DINO, 03/22/2010
/*void Update_C2Axx(void)
{
	C2Axx[0x00] = C21xx[0x02]; 								//Speed Command
	C2Axx[0x01] = C21xx[0x03]; 								//Output Speed
	C2Axx[0x02] = C21xx[0x05]; 								//DC Bus Voltage
	C2Axx[0x03] = C21xx[0x04];								//Output Current
	C2Axx[0x04] = C21xx[0x06];								//Output Voltage
	C2Axx[0x05] = PF_ANGLE;									// Power Factor
	C2Axx[0x06] = Pinput.uw.hi;								//Output Power*
//	C2Axx[0x07] 											//Process Display
	C2Axx[0x08] = uwAbsMotorHz;								//Motor Speed
	C2Axx[0x09] = swTqRefPu;								//Output Torque*
	C2Axx[0x0A] = APR_uwThetaNoMx;							//PG Feedback
	C2Axx[0x0B] = uwElecAngle;								//Electrical Angle
	C2Axx[0x0C] = swAVICalib;								//AVI (%)
	C2Axx[0x0D] = HS_Temp;									//Heatsink Temperature*
	C2Axx[0x0E] = IGBT_Temp;								//IGBT Temperature*
	C2Axx[0x0F] = mio_ulMfiSta;								//Digital Input Status (MI1~MI16)
	C2Axx[0x10] = mio_ulMfiSta >> 16;						//Digital Input Status (MI17 ~ MI24)
	C2Axx[0x11] = ubIot110_Di.ub;							//External Digital Input (MI25~MI36)
	C2Axx[0x12] = mfo_status;								//Digital output (RY1 ~ RY16)
	C2Axx[0x13] = speed;									//Multi-Speed
	C2Axx[0x14] = C21xx[0x19];								//Drive Status
	C2Axx[0x15] = Error;									//Error Code
	C2Axx[0x16] = WarnCode;									//Warn Code
	C2Axx[0x17] = car_uwStatus.uw;							//Car Status
	C2Axx[0x18] = car_uwStaGen.uw;							//Car General Status	//Sean, 05/17/2010
	C2Axx[0x19] = car_uwMode.uw;							//Car Mode
	C2Axx[0x1A] = ((UWORD)dor_ubStatus.ub << 8) | (UWORD)dor_ubControl.ub;	//Door Status
	C2Axx[0x1B] = lev_udCarSig.uw.w0;						//Level Siganl - Car1
	C2Axx[0x1C] = lev_udCarSig.uw.w1;                   	//Level Siganl - Car2
	C2Axx[0x1D] = lev_udCarSig.uw.w2;          				//Level Siganl - Car3
	C2Axx[0x1E] = lev_udCarCmd.uw.w0;          				//Level Status - Car1
	C2Axx[0x1F] = lev_udCarCmd.uw.w1;                   	//Level Status - Car2
	C2Axx[0x20] = lev_udCarCmd.uw.w2;                   	//Level Status - Car3
	C2Axx[0x21]	= lev_udHcbUpSig.uw.w0;                   	//Level Siganl - HCB Up1
	C2Axx[0x22]	= lev_udHcbUpSig.uw.w1;        				//Level Siganl - HCB Up2
	C2Axx[0x23] = lev_udHcbUpSig.uw.w2;        				//Level Siganl - HCB Up3
	C2Axx[0x24] = lev_udHcbUpCmd.uw.w0;                   	//Level Status - HCB Up1
	C2Axx[0x25] = lev_udHcbUpCmd.uw.w1;                   	//Level Status - HCB Up2
	C2Axx[0x26] = lev_udHcbUpCmd.uw.w2;                   	//Level Status - HCB Up3
	C2Axx[0x27] = lev_udHcbDnSig.uw.w0;                   	//Level Siganl - HCB Down1
	C2Axx[0x28] = lev_udHcbDnSig.uw.w1;                   	//Level Siganl - HCB Down2
	C2Axx[0x29] = lev_udHcbDnSig.uw.w2;                   	//Level Siganl - HCB Down3
	C2Axx[0x2A] = lev_udHcbDnCmd.uw.w0;                   	//Level Status - HCB Down1
	C2Axx[0x2B] = lev_udHcbDnCmd.uw.w1;                   	//Level Status - HCB Down2
	C2Axx[0x2C] = lev_udHcbDnCmd.uw.w2;                   	//Level Status - HCB Down3
	C2Axx[0x2D] = (UWORD)lev_ubCur;                   		//Level Current
	C2Axx[0x2E] = U32divU16(lev_ulPosVal, 10000);			//Position Current Hi Word, DINO, 10/21/2010
	C2Axx[0x2F] = lev_ulPosVal - (ULONG)C2Axx[0x2E]*10000;  //Position Current Low Word, DINO, 10/21/2010
	C2Axx[0x30] = saf_ubIedErr;                 			//Error Code of IED, update, Sean, 05/17/2010
	C2Axx[0x31] = car_uwLoadCell.uw;                   		//Preload
	C2Axx[0x32] = (UWORD)mio_ulCfiNow.ub.b0;
	C2Axx[0x33] = (UWORD)mio_ulCfoNow.ub.b0;
	C2Axx[0x34] = U32divU16(vfd_ulOpeCnt, 10000);			// operation count, Sean, 10/26/2010
	C2Axx[0x35] = vfd_ulOpeCnt - (ULONG)C2Axx[0x34]*10000;	// operation count, Sean, 10/26/2010
	C2Axx[0x36] = uwHCBRX1;									// HCB Comm failed dispaly 1, Add by DINO, 12/12/2010
	C2Axx[0x37] = uwHCBRX2;									// HCB Comm failed dispaly 2, Add by DINO, 12/12/2010
	C2Axx[0x38] = uwHCBRX3;									// HCB Comm failed dispaly 3, Add by DINO, 12/12/2010
	C2Axx[0x39] = saf_uwPGF5_Type;							// PGF5 Error Diagnostic [[For IED PG-Card, Sampo, 02/25/2010]
	C2Axx[0x3A] = 0x2A3A;
	C2Axx[0x3B] = 0x2A3B;
	C2Axx[0x3C] = pr[ERR_REC1];
	C2Axx[0x3D] = pr[ERR_MIN1];
	C2Axx[0x3E] = pr[ERR_DAY1];
	C2Axx[0x3F] = pr[FKEY_REC];								// Speed Command (Malfunction)
	C2Axx[0x40] = pr[VOUT_REC];								// Output Voltage (Malfunction)
	C2Axx[0x41] = pr[DCBUS_REC];							// DC Bus Voltage (Malfunction)
	C2Axx[0x42] = pr[FOUT_REC];								// Output Frequency (Malfunction)
	C2Axx[0x43] = pr[ISUM_REC];								// Output Current (Malfunction)
	C2Axx[0x44] = pr[FFBK_REC];								// Motor Speed (Malfunction)
	C2Axx[0x45] = pr[POWER_REC];							// Output Power (Malfunction)*
	C2Axx[0x46] = pr[TQ_REC];								// Output Torque (Malfunction)*
	C2Axx[0x47] = pr[MFI_REC1]^pr[MI_INV1];					// MI1~MI16 Status (Malfunction) 
	C2Axx[0x48] = pr[MFI_REC2]^pr[MI_INV2];					// MI17~MI24 Status (Malfunction), Add by DINO, 08/24/2010
	C2Axx[0x49] = 0x2A49;									// MI25~MI34 Status (Malfunction), Add by DINO, 08/24/2010
	C2Axx[0x4A] = pr[MFO_REC]^pr[MO_INV];					// Digital output (RY1 ~ RY16)(Malfunction)         
	C2Axx[0x4B] = pr[STATE_REC];							// Drive Status (Malfunction)                       
	C2Axx[0x4C] = pr[ERR_REC2];             				//
	C2Axx[0x4D] = pr[ERR_MIN2];             				//
	C2Axx[0x4E] = pr[ERR_DAY2];             				//
	C2Axx[0x4F] = pr[ERR_REC3];             				//
	C2Axx[0x50] = pr[ERR_MIN3];             				//
	C2Axx[0x51] = pr[ERR_DAY3];             				//
	C2Axx[0x52] = pr[ERR_REC4];             				//
	C2Axx[0x53] = pr[ERR_MIN4];             				//
	C2Axx[0x54] = pr[ERR_DAY4];             				//
	C2Axx[0x55] = pr[ERR_REC5];             				//
	C2Axx[0x56] = pr[ERR_MIN5];             				//
	C2Axx[0x57] = pr[ERR_DAY5];             				//
	C2Axx[0x58] = pr[ERR_REC6];             				//
	C2Axx[0x59] = pr[ERR_MIN6];             				//
	C2Axx[0x5A] = pr[ERR_DAY6];             				//
	C2Axx[0x5B] = ReadRamData(pr[DATA_SEL]);				// Display data
	C2Axx[0x5C] = pr[PWR_MIN];              				// Power On Min
	C2Axx[0x5D] = pr[PWR_DAY];								// Power On Day
	C2Axx[0x5E] = ((ULONG)pr[I_RATE]*563+256) >> 9;               // Rated Current
	C2Axx[0x5F] = SWVERS_H;                 				// Firmware Version
}*/
// ]                
                  
#ifdef _CommReg_C   
	#undef _CommReg_C 
#endif                                                                  
                      
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved. 
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
