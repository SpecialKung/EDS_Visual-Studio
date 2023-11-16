
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
#ifndef _KeyPad_C
    #define _KeyPad_C
#endif
/*----------------------------------------------------------------*/

//*****************************************************************/
// @Project Includes
//*****************************************************************/
/* Include File ===============================================*/
#include "ProgHeader.h"

/* ---[ Local Variable ]-----------------------------------------------*/

UWORD Keypadscrollup_disp(UBYTE page)
{
    UBYTE ax;

    page++;


#if DINO	// Modify the WarnPage display, 12/26/2008
	if (Error!=0 || WarnCode!=0){
		if ( key_ubPageCnt==0 )
			page = pr[S_DISP];
		
		key_ubPageCnt++;

		if( key_ubPageCnt>DebugPAGE)
			key_ubPageCnt = 0;
	}

  	ax = DebugPAGE - 1;			// Max page = Debug page = 6

    if (page > ax)
        page = 0;

#else
    if (Error!=0){
    	if (uw_SCTEST7==0)
    		page--;
    }

  #if 0
    if (SHOW_ALLPR==1)
        ax = DebugPAGE - 1;		// Max page = Debug page = 6
    else
        ax = prmax[S_DISP];		// Max page = Nomral page
  #else
  	ax = DebugPAGE - 1;			// Max page = Debug page = 6
  #endif
    if (page > ax)
        page = 0;  

	if (Error!=0){	
		uw_SCTEST7++;
		if (uw_SCTEST7>DebugPAGE){
			uw_SCTEST7 = 0;
			page = 0;	
		}
	}
	else
		uw_SCTEST7 = 0;
#endif


    return page;
}


UWORD Keypadscrolldown_disp(UBYTE page)
{
    UBYTE ax;
    
    page--;
    
    if (page==0xff){
      #if 0
        if (SHOW_ALLPR==1)
            ax = DebugPAGE - 1;         // Max page = Debug page =  6
        else
            ax = prmax[S_DISP];         // Max page , prmax[S_DISP] = 4;
      #else
      	ax = DebugPAGE - 1;           // Max page = Debug page =  6
      #endif
        page = ax;
    }

    return page;	

}


UWORD scrollup_data(UBYTE px, UWORD dx)
{
        return (dx);
}


UWORD scrolldown_data(UBYTE px, UWORD dx)
{
        return (dx);
}

void ShowDescription(string20 str)
{
        UWORD_UNION ix;
        UBYTE i,j;

        i = 0;
        j = 0;
        do{
          ix.ub.hi = str.x[i];
          i++;
          ix.ub.low = str.x[i];
          i++;
          Descript[j] = ix.uw;
          j++;
          if (str.x[i]=='\0' && i<20){
            do{
              ix.ub.hi = '\0';
              i++;
              ix.ub.low = '\0';
              i++;
              Descript[j] = ix.uw;
              j++;
            }while(i<20);
          }
        }while (i<20);
}

/*
void ShowError(void)
{
          KC23xx[7] = 0;
          switch(Error) {
            case 1:{                    //oc
              KC23xx[6] = ('o'<<8)+'c';
            } break;
            case 2:{                    //ov
              KC23xx[6] = ('o'<<8)+'v';
            } break;
            case 3:{                    //oH
              KC23xx[6] = ('o'<<8)+'H';
            } break;
            case 4:{                    //oL
              KC23xx[6] = ('o'<<8)+'L';
            } break;
            case 5:{                    //oL1
              KC23xx[6] = ('L'<<8)+'1';
              KC23xx[7] = 'o';
            } break;
            case 6:{                    //EF
              KC23xx[6] = ('E'<<8)+'F';
            } break;
            case 7:{                    //cF1
              KC23xx[6] = ('F'<<8)+'1';
              KC23xx[7] = 'c';
            } break;
            case 8:{                    //cF3
              KC23xx[6] = ('F'<<8)+'3';
              KC23xx[7] = 'c';
            } break;
            case 9:{                    //HPF
              KC23xx[6] = ('P'<<8)+'F';
              KC23xx[7] = 'H';
            } break;
            case 10:{                   //ocA
              KC23xx[6] = ('c'<<8)+'A';
              KC23xx[7] = 'o';
            } break;
            case 11:{                   //ocd
              KC23xx[6] = ('c'<<8)+'d';
              KC23xx[7] = 'o';
            } break;
            case 12:{                   //ocn
              KC23xx[6] = ('c'<<8)+'n';
              KC23xx[7] = 'o';
            } break;
            case 13:{                   //GFF
              KC23xx[6] = ('F'<<8)+'F';
              KC23xx[7] = 'G';
            } break;
            case 14:{                   //Lv
              KC23xx[6] = ('L'<<8)+'v';
            } break;
            case 15:{                   //PHL
              KC23xx[6] = ('H'<<8)+'L';
              KC23xx[7] = 'P';
            } break;
            case 16:{                   //cF2
              KC23xx[6] = ('F'<<8)+'2';
              KC23xx[7] = 'c';
            } break;
            case 17:{                   //bb
              KC23xx[6] = ('b'<<8)+'b';
            } break;
            case 18:{                   //oL2
              KC23xx[6] = ('L'<<8)+'2';
              KC23xx[7] = 'o';
            } break;
            case 19:{                   //cFA
              KC23xx[6] = ('F'<<8)+'A';
              KC23xx[7] = 'c';
            } break;
            case 20:{                   //codE
              KC23xx[6] = ('d'<<8)+'E';
              KC23xx[7] = ('c'<<8)+'o';
            } break;
            default:{
            } break;
          } 
}
void ShowWarn(void)
{
            switch (WarnCode){
              case 1:{
                KC23xx[6] = ('0'<<8)+'1';
                KC23xx[7] = ('c'<<8)+'E';
              } break;
              case 2:{
                KC23xx[6] = ('0'<<8)+'2';
                KC23xx[7] = ('c'<<8)+'E';
              } break;
              case 3:{
                KC23xx[6] = ('0'<<8)+'3';
                KC23xx[7] = ('c'<<8)+'E';
              } break;
              case 4:{
                KC23xx[6] = ('0'<<8)+'4';
                KC23xx[7] = ('c'<<8)+'E';
              } break;
              case 5:{              // Time Out
                KC23xx[6] = ('1'<<8)+'0';
                KC23xx[7] = ('c'<<8)+'E';
              } break;
              case 6:{
                KC23xx[6] = ('L'<<8)+'2';
                KC23xx[7] = 'o';
              } break;
              case 7:{                      // FeedBack Error
                KC23xx[6] = ('b'<<8)+'E';
                KC23xx[7] = 'F';
              } break;
              case 8:{                      // Auto Tun Error
                KC23xx[6] = ('U'<<8)+'E';
                KC23xx[7] = 'A';
              } break;
              case 9:{
                KC23xx[6] = ('E'<<8)+'1';
                KC23xx[7] = 'S';
              } break;
              case 10:{
                KC23xx[6] = ('E'<<8)+'2';
                KC23xx[7] = 'S';
              } break;
              default:
              break;
            }
}
*/

void Keypad_20xxH(UBYTE func,UWORD datac)
{
    
//   if ((pr[SOOC]>=3)||(PUON2LINE && OPKEY_LOCK==0)){  /* delete by dino, 06/25/2007 */
	    switch (func) {
            case 0x00:{ //2000H: PU on/off, FWD, REV, RUN, STOP, JOG, Multi-speed
//                if ((pr[SOOC]>=3)||(PUON2LINE && OPKEY_LOCK==0)){  /* add by dino, 06/25/2007 */
#if DINO	// Modify the Key Lock Function, DINO, 09/08/2008
				if (pr[CAN_CTRL]==0){
					if ( PUON3LINE ){ //[CAN Control, Sampo, 09/15/2010]
						if ( OPKEY_LOCK==0 )
                			Keypad_2000H(datac);
                	}
                	else{
                		if (pr[SOOC] == 2) //[CAN Control, Sampo, 09/15/2010]
                			Keypad_2000H(datac);
					}
				}
#else
				if ((pr[SOOC]==2)||(PUON3LINE && OPKEY_LOCK==0)){  /* add by SCOTTY, 08/31/2007 */				
                	Keypad_2000H(datac);
                }
#endif
            }break;
            case 0x01:{ //2001H: Frequency Command
#if DINO	// Modify the Key Lock Function, DINO, 09/08/2008
				// [ Multi-speed is 0, Add by DINO, 05/15/2009
				if (speed == 0){
				// ]
					if ( PUON3LINE ){
						if ( OPKEY_LOCK==0 )
                			PCRemote2001H(datac);
                	}
                	else{
                		if ( pr[SOFC]==1)
                			PCRemote2001H(datac);
					}
				}
#else
        	    if ((pr[SOFC]==1)||(PUON3LINE && OPKEY_LOCK==0)){  /* add by dino, 06/25/2007 */
                    PCRemote2001H(datac);                          
                }
#endif
            }break;
            case 0x02:  //2002H: ef/bb/reset
                Keypad_2002H(datac);
                C20xx[0x02] = datac;
            	break;
            case 0x03:  //2003H: User Defined setpoint low
                C20xx[0x03] = datac;
            	break;
            case 0x04:  //2004H User defined setpoint high
        	    C20xx[0x04] = datac;
            	break;
            case 0x05:  //2005H
//        	    if ((pr[SOOC]>=3)||(PUON2LINE && OPKEY_LOCK==0)){  /* add by dino, 06/25/2007 */
#if DINO	// Modify the Key Lock Function, DINO, 09/08/2008
				if ( PUON3LINE ){
					if ( OPKEY_LOCK==0 ){
        	        	Keypad_2005H(datac);
                                            
                        if ((datac & 0xff00) == 0) //language not update       //[language update when switch user page, Bernie, 12/23/2011]
                            datac |= (C20xx[0x05] & 0xff00); 
                       
        	            C20xx[0x05] = datac;
        	        }
        	        else{
        	        	// Cannot be copyed when Key Lock, Add by DINO, 09/08/2008
        	        	if (datac!=0x0003 && datac!=0x0004 && datac!=0x0005){
        	        		Keypad_2005H(datac);

        	        		if ((datac & 0xff00) == 0) //language not update   //[language update when switch user page, Bernie, 12/23/2011]
                                datac |= (C20xx[0x05] & 0xff00);
                            
        	        	   C20xx[0x05] = datac;
        	        	}
        	        }
                }
                else{
//					if ( pr[SOOC]==2){	// Delete by DINO, 03/27/2009
        	        	Keypad_2005H(datac);

        	        	if ((datac & 0xff00) == 0) //language not update  //[language update when switch user page, Bernie, 12/23/2011]
                            datac |= (C20xx[0x05]&0xff00);
                
        	        	C20xx[0x05] = datac;
//					}
				}                
#else
				if ((pr[SOOC]==2)||(PUON3LINE && OPKEY_LOCK==0)){  /* add by SCOTTY, 08/31/2007 */
        	        Keypad_2005H(datac);

        	        if ((datac & 0xff00) == 0) //language not update  //[language update when switch user page, Bernie, 12/23/2011]
                        datac |= (C20xx[0x05] & 0xff00);

        	        C20xx[0x05] = datac;
        	    }
#endif
            	break;
            // [ User Password mapping to Pr.15-105, DINO, 12/23/2009
            case 0x06:  //2006H: User Password
				write_ep(BLK_WRITE,PSW_2006H,datac);
				pr[PSW_2006H] = datac;
            	break;
            // ]
            
              // [For VFD-Cx reload parameter information, Bernie, 09/22/2011]
        	case 0x11:        
        	    if ((datac&0x0002) == 0x0002)
                    C21xx[0x20] &= 0xefff;       //]
                break;
        		
            default:
            	break;
        }
//    }
}

void Keypad_2000H(UWORD datac)
{
    UWORD ax;
  
    ax = datac & 0x6000;
    if (ax!=0) {//=========== bit 14,13, PU on/off ========
        switch(ax){
            case 0x2000:{    //bit13: operation control by PU
                PUON2 = 1;
            } break;
            case 0x4000:{    //bit14: operation control by Pr setting
                PUON2 = 0;
            } break;
            case 0x6000:{    //bit14 & 13: switch between PU and Pr setting
                if (PUON2==1)
                    PUON2 = 0;
                else
                    PUON2= 1;
            } break;
            default:
            break;
        } // end of [ switch(ax) ]
        if (PUON2==1)
            PUEN2 = 1;
        else
            PUEN2 = 0;
    }  // end of [ if(ax != 0) ], bit 14,13, PU on/off
    
	if (((pr[SOOC]==2)||PUEN2||PUEN3)&&(pr[CAN_CTRL]==0)){    //[CAN Control, Sampo, 09/15/2010]
        //========================= bit4,5: direction select
        ax = datac & 0x0030 ; // bit4,5: direction select
        if ((ax!=0)&&(TUN_START==0)&&((PWM_Status.ub&0x42)==0)){  //GEN_OK3 = 0; GEN_START = 0; //Generation Operation, DINO, 04/27/2010
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
            } break;
            case 3: {             // jog command
                    if ((RUNNING==STOP)||CMDJOG){
                    	if (/*(speed==0)&&*/((pr[PIDSL]==0)||(MFI_PIDDIS))){
	                        CMDJOG = 1;
	                        run();
	                        CMDJOG = 1;
	                    }
                    }
            } break;
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
    C20xx[0x00] = datac;  // add by dino, 06/25/2007
}

void Keypad_2002H(UWORD datac)
{
    datac =  datac & 0x0007;   // ef/bb/reset  //
    switch(datac) {
	    case 0x0001:    // EF
	        if(Error==0){
                Error = EF_ERR;
                Keypad_Page = ErrPAGE;
//                WARNSTOPREC = 1;		//09/10/2007
            }
        break;
	    case 0x0002:          // reset command
	        rst_det = 1;      //[Add auto restart after fault, Bernie, 06/06/12]
        	reset();
        break;
        case 0x0004:    //bb
            COM_BB = 1;    
        break;
       	default: 
       	    if (COM_BB)
       	        COM_BB = 0;
        break;
	}  
}

void Keypad_2005H(UWORD datac)
{
    switch (datac){
        case 0x0000:
        	// Reset Display page same as power-on page
            Keypad_Page = pr[S_DISP];               
//            uw_SCTEST7 = 0;
            key_ubPageCnt = 0;
			break;      
        case 0x0001:{
        	// Page Down
          #if 0
            Keypad_Page = Keypadscrolldown_disp(Keypad_Page);             
          #endif
          
          //--- 02/06/06	Max.SJ.Chang: 
          #if 0
            if((MFD_page > 0)&&(Keypad_Page==USER_PAGE))
            	MFD_page--;
          	else
            	MFD_page = MFDPAGEMAX;
          #endif
          //--- 02/06/06	Max.SJ.Chang: 
          
        }break;        
        case 0x0002:{
        	// Page Up
            Keypad_Page = Keypadscrollup_disp(Keypad_Page);
            
          //--- 02/06/06	Max.SJ.Chang: 
          #if 0
            if(MFD_page < MFDPAGEMAX)
            	MFD_page++;
          	else
            	MFD_page = 0;
          #endif
          //--- 02/06/06	Max.SJ.Chang: 
          
        }break;        
        case 0x0003:{
        	// Start to copy all of parameters
            if (RUNNING==STOP && PRLOCK==0 && Error==0 && WarnCode==0 && FSET_LOCK==0){
                COPYEN = 1;
                KC23xx[0x05] |= 0x1000;     // bit12 Enable to Copy
            }
        }break;        
        case 0x0004:{
        	// Copy Failed
            if (COPYEN==1){
                COPYFAIL = 1;
                KC23xx[0x05] &= 0xefff;     // clear bit12 Enable to Copy
            }
        }break;
        case 0x0005:{
        	// Copy Completed
            if (COPYEN==1){
                COPYOK = 1;
                KC23xx[0x05] &= 0xefff;     // clear bit12 Enable to Copy            
            }
        }break;
        case 0x0006:{
        	// Left Arrow key
        	//if((MFD_page < MFDPAGEMAX)&&(Keypad_Page==USER_PAGE))
        	if (MFD_page < MFDPAGEMAX)
            	MFD_page++;
          	else
            	MFD_page = 0;
        }break;
        case 0x0007:{
        	// Right Arrow key
        	if (MFD_page > 0)
            	MFD_page--;
          	else
            	MFD_page = MFDPAGEMAX;
        } break;
        default:
        break;
    }
}

void Update_KeypadDisp(void)
{
	UWORD uwParData, uwPRMax;

    //------ below status put in initvar
//  KC23xx[0] = SWVERS_L;         // Software version
//  KC23xx[1] = 0;                // LCD string count, Monitor status count
//  KC23xx[2] = 0;                // Reserved
//  KC23xx[3] = 0;                // Reserved
    KC23xx[0x04] = ((UWORD)WarnCode<<8) + Error;   // C21xx[0x18];
    
    KC23xx[0x05] = C21xx[0x19];
    KC23xx[0x09] = 0;
    //------ The Attribution of Dynamic data for display --------
	switch(Keypad_Page){
		case F_PAGE:
		    KC23xx[0x09] = 0x0001;
		    if (pr[U_SET]==0){
   	            if (VH_EN==1)
					KC23xx[0x08] = 0x0100;      // dot = 1
	            else
			        KC23xx[0x08] = 0x0200;      // dot = 2

				// [ Velocity Unit Change, Add by DINO, 05/25/2009
				if (pr[UNITSEL] == 1){  		// Hz->m/s
					uwParData = flHz2Metric(fkey.uw.hi);
					uwPRMax   = flHz2Metric(pr[FMAX]);
				}
				else if(pr[UNITSEL] == 2){		// Hz->ft/s
					uwParData = Hz2Ft(fkey.uw.hi);
					uwPRMax   = Hz2Ft(pr[FMAX]);
				}
                //else if(pr[UNITSEL] == 3){		// Hz->ft/s
					//uwParData = Hz2Ft(fkey.uw.hi);
					//uwPRMax   = Hz2Ft(pr[FMAX]);
				//}
				else{
					uwParData = fkey.uw.hi;
					uwPRMax   = pr[FMAX];
				}
				// ]
			    KC23xx[0x06] = uwParData;
			    KC23xx[0x07] = uwPRMax;	
			}
			else{
			    KC23xx[0x08] = (KPDdot<<8);
		        KC23xx[0x06] = U16xU16divU16(KPDmax, fkey.uw.hi, pr[FMAX]);
			    KC23xx[0x07] = KPDmax;
		    }
			KC23xx[0x08] |= 0x6000;
			break;
      	case H_PAGE:          // "H"
//--- Modify by DINO, 10/30/2008
			if (pr[UNITSEL] == 1){			// Hz->m/s
				uwParData = Hz2Metric(C21xx[0x03]);
			}
			else if(pr[UNITSEL] == 2){		// Hz->ft/s
				uwParData = Hz2Ft(fkey.uw.hi);
			}
			else{
				uwParData = fkey.uw.hi;
			}
			KC23xx[0x06] = uwParData;	// Dynamic Data
			KC23xx[0x07] = 0;			// Data Max.
			KC23xx[0x08] = C21xx[0x1D];	// digital point
        	KC23xx[0x09] = 0x0002;      // H Led on
			break;				
//--- End on 10/30/2008
      	case U_PAGE:
      		KC23xx[0x08] = 0x97; 	    //U-bar
        	KC23xx[0x08] |= 0x0100;     // dot = 1
//        	KC23xx[0x09] = 0x0002;      // H Led on	// Delete by DINO, 10/30/2008
        	KC23xx[0x06] = DcbusDCLPF.sw.hi;
        	KC23xx[0x07] = 0;
			break;
      	case A_PAGE:          // "A"
      		KC23xx[0x07] = 0;
      		KC23xx[0x09] = 0;
   			KC23xx[0x08] = 'A';
   			KC23xx[0x08] |= 0x0200;	//dot = 2;
   			if(CC4KeyPad){                         //[CC Display, Bernie, 2017/04/12]
                KC23xx[0x06] = pr[I_RATE2]*9/5;
            }
            else{
   			    KC23xx[0x06] = IrmsReLPF.sw.hi;
            }
			break;
        case E_PAGE:
      		KC23xx[0x08] = 'E';
      		KC23xx[0x08] |= 0x0100;
            KC23xx[0x06] = VcmdLLPF.sw.hi;
			break;            	
       	case USER_PAGE:					// user define
//        	KC23xx[0x08] = 0x0200;      // dot = 2
        	KC23xx[0x08] = 0x0800;      // User Page Define Bit
        	KC23xx[0x09] = 0x0004;      // "U" LED light on
        	switch(MFD_page){		
      			case 0:		//Output Current
      				KC23xx[0x08] |= 'A';
      				KC23xx[0x08] |= 0x0200;	//dot = 2;
      				//KC23xx[0x06]  = IrmsReLPF.sw.hi;
      				if(CC4KeyPad){                            //[CC Display, Bernie, 2017/04/12]
                        KC23xx[0x06] = pr[I_RATE2]*9/5;
                    }
                    else{
   			            KC23xx[0x06] = IrmsReLPF.sw.hi;
                    }
      				break;
/*      				
      			case 1:		//Counter
      				KC23xx[0x08] = 'c';
      				KC23xx[0x06] = trg_cnt;
      				break;
*/      				
      			case 2:     //Actual Motor Hz
      			    if ( slMotorHz >= 0 ){
      					KC23xx[0x08] &= 0x7FFF;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      				}
      				KC23xx[0x08] |= 0x0200;	//dot = 2;
      				// [ Velocity Unit Change, Add by DINO, 05/25/2009
      				KC23xx[0x06]  = uwAbsMotorHz;
      				// ]
      				break;
      				
      			case 3:		//Dcbus
      				KC23xx[0x08] |= 0x97; 	//U-bus
      				KC23xx[0x08] |= 0x0100;	//dot = 1;
      				KC23xx[0x06]  = DcbusDCLPF.sw.hi;
      				break;
      				
      			case 4:		//Output Voltage
      				KC23xx[0x08] |= 'E';
      				KC23xx[0x08] |= 0x0100;
                    KC23xx[0x06]  = VcmdLLPF.sw.hi;
      				break;
      				
      			case 5:		//Power Factor
      				KC23xx[0x08] |= 'n';
      				KC23xx[0x08] |= 0x0100;      // dot = 1
      				KC23xx[0x06]  = PF_ANGLE;
      				break;
      				
//--- Modify by DINO, 09/22/2008
      			case 6:		//Output Power
      			    if ( (Pinput.uw.hi&0x8000)==0 ){
      					KC23xx[0x08] &= 0x7FFF;
      					KC23xx[0x06]  = Pinput.uw.hi;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      					KC23xx[0x06]  = 0xffff - Pinput.uw.hi + 1;
      				}
      				KC23xx[0x08] |= 'P';
      				KC23xx[0x08] |= 0x0200;		//dot = 3
      				break;
//--- End on 09/22/2008

      			case 7:		//Motor RPM
      				KC23xx[0x09]  = 0x0006;
      				KC23xx[0x08] |= 0x0000;
      				KC23xx[0x06]  = abs(swMotorRpm);
      				break;
      				
      			case 8:		//Torque
      			    // [ Add Minus Display, DION, 09/30/2009
      			    if (swTqRefPu >= 0){
      					KC23xx[0x08] &= 0x7FFF;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      				}
      				// ]
					KC23xx[0x08] |= 't';
      				KC23xx[0x08] |= 0x0100;
//      				KC23xx[0x06]  = TqC_swTqCmd; //6a16j display Torque input
      				//KC23xx[0x08] |= 0x0200;  //6911j
      				//KC23xx[0x06] = TorqueOut;   //6a16j
          			KC23xx[0x06] = abs(swTqRefPu); //080318 by tj
      				break;
      				
      			case 9:		//PG Feedback
      				KC23xx[0x09]  = 0x0006;
      				KC23xx[0x08] |= 0x0000;
      				KC23xx[0x06]  = APR_uwThetaNoMx;
      				break;
				// [ Display Electrical angle, add by Sampo, 04/22/2009
				case 10:	//Electric Angle
					KC23xx[0x08] |= 'd';
					KC23xx[0x08] |= 0x0100;	//dot = 1;
					KC23xx[0x06] = uwElecAngle;
					break;
				// ]
      			case 11:	//AUI1 AD
      			    // [ Modify the scale of swAVICalib, DINO, 06/17/2009
      			    if ( swAVICalib >= 0 ){
      					KC23xx[0x08] &= 0x7FFF;
      					KC23xx[0x06]  = swAVICalib;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      					KC23xx[0x06]  = -swAVICalib;
      				}
      				// ]
      				KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100;
      				break;
      				
      			case 12:		//ACI AD
      				KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100;
      			    // [ Modify the scale of swACICalib, DINO, 06/17/2009
      				KC23xx[0x06]  = swACICalib;
      				// ]
      				break;
      				
      			case 13:		//AUI2 AD
      			    // [ Modify the scale of swAUICalib, DINO, 06/17/2009
      			    if ( swAUICalib >= 0 ){
      					KC23xx[0x08] &= 0x7FFF;
      					KC23xx[0x06]  = swAUICalib;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      					KC23xx[0x06]  = -swAUICalib;
      				}
      				// ]
      				KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100;
      				break;
      				
      		    case 14:        //TH1
      			    if ( HS_Temp >= 0 ){
      					KC23xx[0x08] &= 0x7FFF;
      					KC23xx[0x06]  = HS_Temp;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      					KC23xx[0x06]  = -HS_Temp;
      				}
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100;
      				break; 
      				
      			case 15:        //TH2
      			    if ( IGBT_Temp >= 0 ){
      					KC23xx[0x08] &= 0x7FFF;
      					KC23xx[0x06]  = IGBT_Temp;
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      					KC23xx[0x06]  = -IGBT_Temp;
      				}
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100;
      				break; 
     				         		     
      			case 16:        //DI, Multi-Function input ON/OFF Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;	 // hex
      				KC23xx[0x06]  = mfi_status;
      				break;
      				
      			case 17:        //DO, Multi-Function output ON/OFF Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;  // hex
      				KC23xx[0x06]  = mfo_status;
      				break;
      					
      			case 18:        //Multi-speed status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0000;
      				KC23xx[0x06]  = speed;
      				break;
      				
      		    case 19:        //DI, Multi-Function input Pin Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;  // hex
      				KC23xx[0x06]  = (0xffff - mfi_now);
      				break;
      				
      			case 20:        //DO, Multi-Function output Pin Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;  // hex
      				KC23xx[0x06]  = (0xffff - mfo_now);
      				break;
/*      				
				case 21:        //Running number of Encoder (Channel 1)
		            KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0000;
      				KC23xx[0x06]  = APR_uwZpulseCnt;
    				break;
    				
		        case 22:		//Pulse Input Frequency (Channel 2)
		        	KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0200;
      				KC23xx[0x06]  = PG2_ulSpdCmdLPF.uw.hi;
		        	break;
		        	
    			case 23:		//Pulse Input Position (Channel 2)
		        	KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0000;
      				KC23xx[0x06]  = APR_uwPG2PCom;
    				break;
*/    				
      		    case 24:        //Error Vout
      				KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100; // dot1
      				KC23xx[0x06]  = pr[VOUT_REC];
      				break;
      				
      			case 25:        //Error Vbus
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0100;	// dot1
      				KC23xx[0x06]  = pr[DCBUS_REC];
      				break; 
     				         		     
      			case 26:        //Error Ffbk
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0200;	// dot2
      				KC23xx[0x06]  = pr[FFBK_REC];
      				break;
      				
      			case 27:        //Error Current
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0200; // dot2
      				KC23xx[0x06]  = pr[ISUM_REC];
      				break;
      					
      			case 28:        //Error Fout
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0200; // dot2
      				KC23xx[0x06]  = pr[FOUT_REC];
      				break;

      			case 29:        //Error Fcmd
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x0200; // dot2
      				KC23xx[0x06]  = pr[FKEY_REC];
      				break;

      			case 30:		//Output Power
      			    if ( (pr[POWER_REC]&0x8000)==0 ){
      					KC23xx[0x08] &= 0x7FFF;
      					KC23xx[0x06]  = pr[POWER_REC];
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
      					KC23xx[0x06]  = 0xffff - pr[POWER_REC] + 1;
      				}
      				KC23xx[0x08] |= 'P';
      				KC23xx[0x08] |= 0x0200;		//dot = 3
      				break;
      				
      			case 31:		//Torque
      			    // [ Add Minus Display, DION, 09/30/2009
      			    if ((pr[TQ_REC]&0x8000)==0){
      					KC23xx[0x08] &= 0x7FFF;
         				KC23xx[0x06]  = abs(pr[TQ_REC]);
      				}
      				else {
      					KC23xx[0x08] |= 0x8000;
         				KC23xx[0x06]  = 0xffff - pr[TQ_REC] + 1;
      				}
      				// ]
					KC23xx[0x08] |= 't';
      				KC23xx[0x08] |= 0x0100;
      				break;

      			case 32:        //DI, Multi-Function input ON/OFF Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;	 // hex
      				KC23xx[0x06]  = (pr[MFI_REC]^pr[MI_INV]);	// DINO, 04/27/2010
      				break;

      			case 33:        //DO, Multi-Function output ON/OFF Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;  // hex
      				KC23xx[0x06]  = (pr[MFO_REC]^pr[MO_INV]);	// DINO, 04/27/2010
      				break;

      			case 34:        //DO, Multi-Function output ON/OFF Status
      			    KC23xx[0x08] |= '1';
      				KC23xx[0x08] |= 0x1000;  // hex
      				KC23xx[0x06]  = pr[STATE_REC];
      				break;

				case 41:      //[TUV_STOCRC]								//[TUV_STO Checksum,  Special.Kung]
					KC23xx[0x08] |= '1';									//[TUV_STO Checksum,  Special.Kung]
					KC23xx[0x08] |= 0x1000;  // hex							//[TUV_STO Checksum,  Special.Kung]
					KC23xx[0x06] = uwTUV_STOCRC;							//[TUV_STO Checksum,  Special.Kung]
					break;													//[TUV_STO Checksum,  Special.Kung]

    			default:
      				KC23xx[0x06]  = 0;
    				break;	
      		}
			break;
		default:
			break;
    }
}

void Update_LCDescription(void)
{
#if DINO	// Modify the WarnPage display, 12/26/2008
	if ( (Error!=0||WarnCode!=0) && key_ubPageCnt==0){
    	if (Error!=0){
			if ((C20xx[0x05]&0xff00) == 0x0400)
                #if Language_TR
    			ShowDescription(errinfo_tur[Error]);
                #else
    			ShowDescription(errinfo[Error]);
                #endif
			else if ((C20xx[0x05]&0xff00) == 0x0800)
                #if Language_RUS
    			ShowDescription(errinfo_rus[Error]); 
                #else
    			ShowDescription(errinfo[Error]);
                #endif
			else if ((C20xx[0x05]&0xff00) == 0x0200)
                #if Language_TC
    			ShowDescription(errinfo_tc[Error]); 
                #else
    			ShowDescription(errinfo[Error]);
                #endif
			else if ((C20xx[0x05]&0xff00) == 0x0300)
                #if Language_SC
    			ShowDescription(errinfo_sc[Error]);
                #else
    			ShowDescription(errinfo[Error]);
                #endif
			else
    			ShowDescription(errinfo[Error]);
    	}
    	else{            
            if ((C20xx[0x05]&0xff00) == 0x0400)
                #if Language_TR
                ShowDescription(warninfo_tur[WarnCode]);
                #else
                ShowDescription(warninfo[WarnCode]);
                #endif
            else if ((C20xx[0x05]&0xff00) == 0x0800)
                #if Language_RUS
                ShowDescription(warninfo_rus[WarnCode]);
                #else
                ShowDescription(warninfo[WarnCode]);
                #endif
            else if ((C20xx[0x05]&0xff00) == 0x0200)
                #if Language_TC
                ShowDescription(warninfo_tc[WarnCode]);
                #else
                ShowDescription(warninfo[WarnCode]);
                #endif
            else if ((C20xx[0x05]&0xff00) == 0x0300)
                #if Language_SC
                ShowDescription(warninfo_sc[WarnCode]);
                #else
                ShowDescription(warninfo[WarnCode]);
                #endif
            else
                ShowDescription(warninfo[WarnCode]);
    	}
	}
    else{
		if (Keypad_Page==USER_PAGE){
			// [ Actual Freq. Unit Change, Add by DINO, 05/25/2009
			if (MFD_page == 2){
				if (pr[UNITSEL] == 1){
            		ShowDescription(sfrinfo_vel_sel[0]);	// Actual Speed m/s
				}
				else if (pr[UNITSEL] == 2){
            		ShowDescription(sfrinfo_vel_sel[1]);	// Actual Speed ft/s
				}
                else if (pr[UNITSEL] == 3){                          //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
            		ShowDescription(sfrinfo_vel_sel[2]);	// Actual Speed m/s^2
				}
				else{
					ShowDescription(sfrinfo[MFD_page]);		// Actual Freq. Hz
				}
			}
			else{
				ShowDescription(sfrinfo[MFD_page]);
			}
			// ]
		}
		else{
			if (pr[U_SET] == 0){
				// [ Velocity Unit Change, Add by DINO, 05/25/2009
				if (Keypad_Page < 2){  // F or H Page has to change description
					if (pr[UNITSEL] == 1){		// m/s
						ShowDescription(usrdefinfo_metric[Keypad_Page]);
					}
					else if (pr[UNITSEL] == 2){	// ft/s
						ShowDescription(usrdefinfo_ft[Keypad_Page]);
					}
                    else if (pr[UNITSEL] == 3){	// m/s2                         //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
						ShowDescription(usrdefinfo_ft[Keypad_Page]);
					}
					else{						// Hz
						ShowDescription(usrdefinfo[Keypad_Page]);
					}
				}
				else{
		        	ShowDescription(usrdefinfo[Keypad_Page]);
		        }
				// ]
			}
			else{
				ShowDescription(usrdefinfo_0005[Keypad_Page]);
			}
		}
	}
#else
    if (Error!=0){
  		if (uw_SCTEST7==0){ 
			if ((C20xx[0x05]&0xff00) == 0x0200)
                #if Language_TC
    			ShowDescription(errinfo_tc[Error]); 
                #else
    			ShowDescription(errinfo[Error]); 
                #endif
			else if ((C20xx[0x05]&0xff00) == 0x0300)
                #if Language_SC
    			ShowDescription(errinfo_sc[Error]); 
                #else
    			ShowDescription(errinfo[Error]); 
                #endif
			else
    			ShowDescription(errinfo[Error]); 
    		Keypad_Page = pr[S_DISP];
    	}
    	else{
        	if (Keypad_Page==USER_PAGE)
        		ShowDescription(sfrinfo[MFD_page]);
        	else{
        		if (pr[U_SET] == 0){
					// [ Velocity Unit Change, Add by DINO, 05/25/2009
					if (Keypad_Page < 2){
						if (pr[UNITSEL] == 1){		// m/s
							ShowDescription(usrdefinfo_metric[Keypad_Page]);
						}
						else if (pr[UNITSEL] == 2){	// ft/s
							ShowDescription(usrdefinfo_ft[Keypad_Page]);
						}
                        else if (pr[UNITSEL] == 3){	// m/s2                         //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
							ShowDescription(usrdefinfo_ft[Keypad_Page]);
						}
						else{						// Hz
							ShowDescription(usrdefinfo[Keypad_Page]);
						}
					}
					else{
		        		ShowDescription(usrdefinfo[Keypad_Page]);
		        	}
					// ]
      		    }
				else{
					ShowDescription(usrdefinfo_0005[Keypad_Page]);
				}
			}
		}
    }
    else{
       	if (WarnCode!=0){
            if ((C20xx[0x05]&0xff00) == 0x0200)
                #if Language_TC
                ShowDescription(warninfo_tc[WarnCode]);
                #else
                ShowDescription(warninfo[WarnCode]);
                #endif
            else if ((C20xx[0x05]&0xff00) == 0x0300)
                #if Language_SC
                ShowDescription(warninfo_sc[WarnCode]);
                #else
                ShowDescription(warninfo[WarnCode]);
                #endif
            else
                ShowDescription(warninfo[WarnCode]);
    	}
    }
        else{ 
        	if (Keypad_Page==USER_PAGE)
        		ShowDescription(sfrinfo[MFD_page]);
        	else{
        		if (pr[U_SET] == 0){
					// [ Velocity Unit Change, Add by DINO, 05/25/2009
					if (Keypad_Page < 2){
						if (pr[UNITSEL] == 1){		// m/s
							ShowDescription(usrdefinfo_metric[Keypad_Page]);
						}
						else if (pr[UNITSEL] == 2){	// ft/s
							ShowDescription(usrdefinfo_ft[Keypad_Page]);
						}
                        else if (pr[UNITSEL] == 3){	// m/s2                    //[DLC  function Change unit to m/s2, Bernie, 2015/09/02]
							ShowDescription(usrdefinfo_ft[Keypad_Page]);
						}
						else{						// Hz
							ShowDescription(usrdefinfo[Keypad_Page]);
						}
					}
					else{
		        		ShowDescription(usrdefinfo[Keypad_Page]);
		        	}
					// ]
      		    }
				else{
					ShowDescription(usrdefinfo_0005[Keypad_Page]);
				}
			}
      	}
    }
#endif
}

void reset(void)
{
    if(Error == MbF_ERR){     //[MBF can be recorded after power down, Bernie, 2016/02/19]
        pr[MBF_ERR_REC] = 0;
        write_ep(0,MBF_ERR_REC, 0);
    }
    if(Error == OVERACC_ERR){   //[Over Acceleration protection function, Bernie, 2017/02/13]

        OverAccInit();
    }
    if(Error == OPHLW_ERR || Error == OPHLV_ERR || Error == OPHLU_ERR || Error == MPHL_ERR){
        uwIacnt = 0; 
        uwIbcnt = 0; 
        uwIccnt = 0; 
        uwIabcCnt = 0;   
    }
	//rst_det = 1;	// reset key detecting and excuting, Sean, 08/19/2010

	if(Error == PGcd_ERR){//[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
        SpDt_swPGCDerr_Detect = 0;        
        SpDt_swNoground_CNT = 0; //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
	}
    
    ResetByKeypad();     //[Add auto restart after fault, Bernie, 06/06/12]
    IODLC_ubArea_status = AreaStop; // [IODLC, Lyabryan, 2016/11/11]
	//[ //reset Err_count,Lyabryan,2015/04/08
    SpDt_uwPGF1ErrCnt = 0;			// PGF1_Err: feedback Error
    SpDt_uwPGLossCnt  = 0;			// PGF2_Err: PG Loss
    SpDt_uwPGLossCnt1 = 0;			
    SpDt_uwPGLossCnt2 = 0;
    SpDt_uwPGLossCnt4 = 0;			// Absolute signal LOSS
    SpDt_uwOvSpdCnt	= 0;			// PGF3_Err: Overspeed
    SpDt_uwSpdDeCnt	= 0;			// PGF4_Err: PG Devation
    SpDt_uwPGErrTmp = 0;
	//]
    if(Error == CAN_ERR){
        InitCAN();
        //Error = 0;
        uwPDO_CNT = 0;      //[claer state when Error occur ,Bernie, 2015/05/12]

        ubPDO_TxCNT = 0;    //[claer state when Error occur ,Bernie, 2015/05/12]
        RCAN_RX_Count = 0;  //[claer state when Error occur ,Bernie, 2015/05/12]
        CAN_uwErrNo = 0;    //[claer state when Error occur ,Bernie, 2015/05/12]
        CAN_status.uw = 0;  //[claer state when Error occur ,Bernie, 2015/05/12]

    }  
	//#12225,Don't reset STO flag, James for 04-49=4~7, 2021/10/25
#if 0	
    if((Error == STOL_ERR)||(Error == STOL1_ERR)||(Error == STOL2_ERR)||(Error == STOL3_ERR)||(Error == STOL4_ERR)){
        //STOLOSS = 0;
        //STO1LOSS = 0;
        //STO2LOSS = 0;
        //STO3LOSS = 0;
        //TB1_uwSTOErrCnt = 0;
        //uw_STOStatusOld = 0;
        //uw_STOStatus = 0;
    }
#endif	
    if(KEYRESET&&(Error == GFCAFE_ERR)|| (AFE_ERR_RECORD==1))
    {
        AFE_ERR_TMR = 1;
        AFE_Level_Delay = 0;
        AFE_ERR_RECORD = 0;
    }
    if ( Error!=0 && WARNSTOPREC==0 ){  // Modify by DINO, 05/29/2008
        if(Error!=bb_ERR){    //bb
//            if ( KEYRESET && (PB.PRL.BYTE.L&0x3c)==0x3c ){  /* Confirm OV,OC,OCC,GFF is high, Modify by dino, 06/13/2007 */

			//if ( KEYRESET &&   
				 //((PB.PR.BIT.B7  &1)==1) &&			// Confirm OC/CC/GF is high
				 //((PA.PR.BIT.B23 &1)==1) ){			// Confirm OV is high
		    if ( KEYRESET &&   
				 //((PORT9.PIDR.BIT.B6 &1)==1) &&			// Confirm OC/CC/GF is high
				 //((PORT7.PIDR.BIT.B0 &1)==1) ){			// Confirm OV is high
				 ((PORT7.PIDR.BIT.B0 &1)==1) &&			// Confirm OC/CC/GF is high  //[OC Error can't clear, Bernie, 2014/12/18]
				 ((PORTB.PIDR.BIT.B4 &1)==1) ){			// Confirm OV is high  
	     
                if (Error==cF2_ERR){         
                    wr_def2ep();       // update eeprom only
          
                }
//                imaskValue = DINT();  //Delete by DINO, 05/11/2010
    	        InitValue();
//      	        EINT(imaskValue);
            }
        }        
    }
//    else if (WarnCode!=0){
    else if (WarnCode==SE1_WARN || WarnCode==SE2_WARN || WarnCode==SE3_WARN/*|| WarnCode==Fan_WARN*/){	// Modify by DINO, 10/16/2008
        WarnCode = 0;
        Keypad_Page = pr[S_DISP];
        Keypad_PageTmp = 0;
    }   
}

void SpdSearchAtStart(void)
{
    UWORD uwIdci;

	// [ RUNDCI double check, DINO, 02/02/2010
	RUNDCI2 = 0;
	// ]

    if (CMDJOG==0) {
    	if ((pr[CTRLM]==FOCPM)){SPSEARCH = 0; }		//ADDED BY SCOTTY 01/29/2007
    	
        if ((pr[CTRLM]==FOCPG)||(pr[CTRLM]==VFPG)){
            if (pr[SPD_SER]!=0){
                vcmd_ser = 0;                
                PG_speed_search();
                SPSEARCH = 1;
            }
            else
                SPSEARCH = 0;
        }
        else{
            switch (pr[SPD_SER]){		//Pr[14-73]
                case 1:
                    vcmd_ser = 0;                                        
                    fcmd.uw.hi = pr[FMAX];
                    ftemp.uw.hi = pr[FMAX];
                    fcmd_vf.uw.hi = pr[FMAX];
                    vtemp = GetFx2Vm(fcmd.uw.hi);
                    SPSEARCH = 1;
                break;
                case 2:
                    vcmd_ser = 0;                    
                    fcmd.uw.hi = fkey.uw.hi;
                    ftemp.uw.hi = fkey.uw.hi;
                    fcmd_vf.uw.hi = fkey.uw.hi;
                    vtemp = GetFx2Vm(fcmd.uw.hi);
                    SPSEARCH = 1;
                break;            
                default:
                    vcmd_ser = 0;                    
                    SPSEARCH = 0;
                break;
            }    
        }
        if ((pr[PIDSL]!=0)&&(MFI_PIDDIS==0)){
            SPSEARCH = 0;
        }    
        if (SPSEARCH==0){
			/* Set uwIdci!=0, Add by dino, 12/12/2007 */
    		if ( pr[CTRLM]==FOCPG || pr[CTRLM]==FOCPM )
    			uwIdci = 10;
    		else
    			uwIdci = pr[DCICL];

            if ( (uwIdci!=0) && (pr[DCISTA]!=0) && (!CMDJOG) && TUN_START==0 ) {
                //------ Have DC Injection -------------------------//           
                fout.ul = 0;                                                     
                fcmd.ul = 0;                                                     
                RUNDCI = 1;                                                      
				// [ RUNDCI double check, DINO, 02/02/2010
                RUNDCI2 = 1;
                // ]
                TB1_uwDCICnt = 0;	// DC injection  counter.    
                                                                                 
				// [ Modify PPI Counter, DINO, 06/03/2010
//                SpDt_ubT1OverCnt = SPR_ubT1OverCntOLD;	//PPI Control, SCOTTY 10/1/2007			
//                SpDt_ubT1UderCnt = SPR_ubT1UnderCntOLD;	//PPI Control, SCOTTY 10/11/2007
 				SPR_swPIVUVCnt = 0;  						// Modify PPI overflow/underflow Counter, DINO,  06/03/2010
                //SPR_slPIVthidaCom = MTU21.TCNT;				//PPI Control, SCOTTY 10/11/2007
                //SPR_slPIVthidaFbk = MTU21.TCNT;				//PPI Control, SCOTTY 10/11/2007
                SPR_slPIVthidaCom = MTU1.TCNT;				//PPI Control, SCOTTY 10/11/2007
                SPR_slPIVthidaFbk = MTU1.TCNT;				//PPI Control, SCOTTY 10/11/2007
                if (PGDIR != 1){							//PPI Control, SCOTTY 10/11/207
                	SPR_slPIVthidaCom = -SPR_slPIVthidaCom;	//PPI Control, SCOTTY 10/11/2007
                	SPR_slPIVthidaFbk = -SPR_slPIVthidaFbk;	//PPI Control, SCOTTY 10/11/2007
                } 											//PPI Control, SCOTTY 10/11/2007
 				// ]
            }                                                                    
            else {                                                               
               	//------ no DC injection ---------------------------//           
                if (Fcmd>=fmin){                                                 
                    fcmd.uw.hi = fmin;                                           
                    ftemp.uw.hi = fmin;                                          
                }                                                                
            }                                                                    
        }                                                                        
    }                                                                            
}    

void run(void)
{
    UBYTE ubZSPDCI;
    UWORD SRYcnt, PGFbkCnt, FreqStart;
    SWORD swZOffset, swUOffset;
    ULONG ulPGSWCnt;

	ubZSPDCI = 0;
    SRYcnt = 0;

	if ( pr[CTRLM]==FOCPM )
		FreqStart = 0;
	else
		FreqStart = fstart;

	// [ Clear TUN_STOP, DINO, 06/24/2010
	TUN_STOP = 0;
	// ]

    if ((Error==0) && (COPYEN==0) && (EXT_ENABLE==0) &&(RelayOFF==0) && (PGREADY==1) && (CAN_ENABLE==0)){	// RUN after Soft-start turn ON, Add by DINO, 12/01/2008  //[CAN Control, Sampo, 09/15/2010]
//		if(RUNNING == STOP) {               // (RUNNING == STOP) -> vfd stop -> go run
		// [ Modify by DINO, 04/04/2009
		if(RUNNING==STOP && LIFT_ENABLE==0) {               // (RUNNING == STOP) -> vfd stop -> go run
		// ]
            uwStartMphl2cnt = 0;
            //Init_SpDtPG1(); 
            SpDt_uwPGLossCnt3 = 0;			// Hardware PG Loss
/*  //reset Err_count,Lyabryan,2015/04/08 mask
	SpDt_uwPGF1ErrCnt = 0;			// PGF1_Err: feedback Error
    	SpDt_uwPGLossCnt  = 0;			// PGF2_Err: PG Loss
            SpDt_uwPGLossCnt1 = 0;			
            SpDt_uwPGLossCnt2 = 0;
            SpDt_uwPGLossCnt4 = 0;			// Absolute signal LOSS
            SpDt_uwOvSpdCnt   = 0;			// PGF3_Err: Overspeed
            SpDt_uwSpdDeCnt   = 0;			// PGF4_Err: PG Devation

/* Item 46: Marked,			SpDt_ubPGLossDtCnt = 0;	*/
/* Item 46: Marked,         PGLOSS = 0;	*/
            
//	    	SpDt_uwPGErrTmp = 0;  //reset Err_count,Lyabryan,2015/04/08 mask
/* Item 46: Marked,         PGLOSSCNT = 0;	*/
            
            if ((PositionCom==1)&&(pr[CTRLM]==FOCPG)){                    
                STOPgoAPR = 1;    //In run();
                STPgoAPRChkZ = 0;
            }

    	    //----- Diagnostic Absolute Position Signal----- dino, 06/12/2008 -----
			if ( pr[PG_TYPE]==ABZ_UVW ){
	    		//MTU2S4.TIER.BYTE &= 0xF7;	// TGIED, Z-pulse capture interrupt disable
	    	    MTU6.TIER.BYTE &= 0xF7;    // TGIED, Z-pulse capture interrupt disable
	    		// [ TCNT0, TCNT1 counter are stopped, dino, 04/04/2009
	    		//MTU2.TSTR.BYTE   &= 0xFC;
                MTU.TSTRA.BYTE   &= 0xFC;
	    		// ]
        		//SCI1_DIR = 1;
	            PGSEL = 0;	// Read UVW, DINO, 03/09/2010
        		ulPGSWCnt = 0;
        	
      			while ( ulPGSWCnt < 90000){	// waiting for ABZ->UVW 6560us(At least > 2400us+100us), turn on 4ms, sample UVW 100us
      	   			ulPGSWCnt++;
      	   			nop();
      	   			nop();
      	   			nop();
      	   			nop();
      			}

#if NEWIEDCB  // PGLOSS2 for Hall Sensor Loss, DINO, 06/28/2010
				if (HALL_LOSS == 1)
					PGLOSS_ABS = 1;
#else
				if ( st_uwHallNew==0 || st_uwHallNew==7 )
					PGLOSS_ABS = 1;
#endif
				PGSEL = 1;	// Read ABZ, DINO, 03/09/2010
        		ulPGSWCnt = 0;
      			while ( ulPGSWCnt < 15000){ // waiting for UVW->ABZ 960us(At least 280us), DINO, 03/09/2010
      	   			ulPGSWCnt++;
      	   			nop();
      			}

	    		//MTU2S4.TSR.BYTE  &= 0xF7;	// clear TGFD flag, dino, 04/09/2007	
				//MTU2S4.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable, dino, 04/09/2007 
				MTU6.TSR.BYTE  &= 0xF7;	// clear TGFD flag
    			MTU6.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable  
				// [ TCNT0, TCNT1 counter are operated, dino, 04/04/2009
	    		//MTU2.TSTR.BYTE   |= 0x03;	// TCNT0, TCNT1 counter are operated
	    		MTU.TSTRA.BYTE   |= 0x03;
	    		// ]
      		}
      		else if ( pr[PG_TYPE]==SIN_SIN && 0 ){
   				SRYcnt = 0;
   				// SIN is too high or too low
   				if (SINadLPF.sw.hi>3900 ||  SINadLPF.sw.hi<200 )
   					SRYcnt = 2;
   				// COS is too high or too low
   				else if ( COSadLPF.sw.hi>3900 || COSadLPF.sw.hi<200 )
   					SRYcnt = 2;
   				// (SIN^2+COS^2) is too low, Q15=>1* 32768^2 * 0.9 = 966367642
   				else if ( (slSINsquarePu<966367642) && pr[Z_OFFSET]!=3600 ){
   					if ( pr[PM_AUTO_T]==0 )
   						SRYcnt = 2;
   				}

				if ( SRYcnt==2 ){ PGLOSS_ABS = 1; }
      		}
			//-- Detect EnDat Loss, Add by DINO, 09/30/2008
      		else if (pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER){
				if ( edt_ubErr==1 && 0){ PGLOSS_ABS = 1; }
      		}

            if (pr[AUTO_T]!=0 || pr[PM_AUTO_T]!=0){
            	if ( TUN_SS ){
					// Delete by DINO, 05/11/2009
//            		STtune 			  = 1;
					// ]
            		ALIGN 			  = 1;	    //ADDED SCOTTY 2007/08/06
            		Zpulse 			  = 1;
            		ZCALIB 			  = 0;
            		TUN_HFSS_OK 	  = 0;
					zcal_uwPulseErr   = 0;		//SCOTTY 01/15/2008
					zcal_swThetaErr   = 0;		//SCOTTY 01/15/2008
//            		REPOS_FAULT_FLAG  = 1;
    		        //MTU2S4.TSR.BYTE  &= 0xF7;	// clear TGFD flag, dino, 04/09/2007	
    		        MTU6.TSR.BYTE  &= 0xF7;	// clear TGFD flag
    				if ( pr[PG_TYPE]!=SIN_ENDAT && pr[PG_TYPE]!=SIN_HIPER )	// Don't interrupt Z-pulse when EnDat, dino, 08/29/2008
    		        	//MTU2S4.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable, dino, 04/09/2007 
    		        	MTU6.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable  
			    	STDutyInit();				// calculate uwTGain for StandStill duty
			    	PM_swTmax = experiod + DeadTime;
			    	PM_swTmin = (SWORD)(experiod + DeadTime) - (SWORD)((ULONG)experiod*uwTGain>>8); 
            	}
            	else{
            		//****** Auto Tun Running Command **************************//
                	TUN_StartInit();	//TUN_START=1;
                }
            }
#if StandStill	// 02/07/2006
	    	else if ( STtune ){
				if ( REPOS_FAULT_FLAG==0 && (pr[SysControl]&0x8000)==0x8000 ){
                    Init_SpDtPG1();
					if (PGDIR == 1){
    					if (WGDIR == REVERSE)
							//MTU21.TCNT = 65535 - (SpDt_uwAnglePeriod - pr[PG_POSatLV]) + 1;
                            MTU1.TCNT = 65535 - (SpDt_uwAnglePeriod - pr[PG_POSatLV]) + 1;
    					else
    						//MTU21.TCNT  = pr[PG_POSatLV];	
                            MTU1.TCNT  = pr[PG_POSatLV];	
    				}
    				else {
    					if (WGDIR == REVERSE)
    						//MTU21.TCNT  = SpDt_uwAnglePeriod - pr[PG_POSatLV];
                            MTU1.TCNT  = SpDt_uwAnglePeriod - pr[PG_POSatLV];
    					else 
    						//MTU21.TCNT = 65535 - pr[PG_POSatLV] + 1;
                            MTU1.TCNT = 65535 - pr[PG_POSatLV] + 1;
    				}

                    //SpDt_uwPG1100usCNT_Old = MTU21.TCNT;
                    SpDt_uwPG1100usCNT_Old = MTU1.TCNT;
    				if (PGDIR != 1)
						SpDt_uwPG1100usCNT_Old = 65535 - SpDt_uwPG1100usCNT_Old + 1;	
                    STtune = 0;
                    REPOS_FAULT_FLAG = 1;
                    Init_FOCPG();
                    SpdSearchAtStart();
				}
				else if ( pr[PG_TYPE]==SIN_SIN && pr[Z_OFFSET]!=3600 ){	//Scotty check Z phase 09/28/2007
                    Sinusoidal_Position();
                    Init_SpDtPG1();
                    //MTU21.TCNT = st_uwAnaPGInit;
                    MTU1.TCNT = st_uwAnaPGInit;
		    SpDt_uwPGABin_old = MTU1.TCNT; //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
                    st_uwInitPos = st_uwAnaPGInit;
                    //SpDt_uwPG1100usCNT_Old = MTU21.TCNT;
                    SpDt_uwPG1100usCNT_Old = MTU1.TCNT;
				    if (PGDIR != 1)
						SpDt_uwPG1100usCNT_Old = 65535 - SpDt_uwPG1100usCNT_Old + 1;
                    STtune = 0;
                    pr[ST_TUNE] = 0;
                    Init_FOCPG();
                    SpdSearchAtStart();
				}
                else if ( pr[PG_TYPE]==ABZ_UVW && pr[Z_OFFSET]!=3600 ){  // Read Initial Position by UVW Signal

	    		    //MTU2S4.TIER.BYTE &= 0xF7;	// TGIED, Z-pulse capture interrupt disable 
	    		    MTU6.TIER.BYTE &= 0xF7;    // TGIED, Z-pulse capture interrupt disable 
	    			// [ TCNT0, TCNT1 counter are stopped, dino, 04/04/2009
	    			//MTU2.TSTR.BYTE   &= 0xFC;
                    MTU.TSTRA.BYTE   &= 0xFC;
	    			// ]
        			PGSEL = 0;	// Read UVW, DINO, 03/09/2010
        			ulPGSWCnt = 0;
      				while ( ulPGSWCnt < 90000){ // waiting for ABZ->UVW 7000us(At least 3914us+100us), turn on 4ms, sample UVW 100us, DINO, 03/09/2010
      	   				ulPGSWCnt++;
      	   				nop();
      	   				nop();
      	   				nop();
      	   				nop();
      				}
//-- Add by dino, 04/02/2008
			    	if (PGDIR != 1)  // pr[PGINPUT]==2
			    		swZOffset = -pr[Z_OFFSET];
			    	else  // pr[PGINPUT]==1
			    		swZOffset = pr[Z_OFFSET];

					if ( pr[UVW_TYPE]==0 )
						swUOffset = 1800;
					else
						swUOffset = 0;

      				if ( st_uwHallNew==1 ){
      				    Start_Section = 5;
      				    swInitPos = swZOffset - 300 + swUOffset;
      				}
      				else if ( st_uwHallNew==2 ){
      				    Start_Section = 3;
      				    swInitPos = swZOffset - 1500 + swUOffset;
      				}
      				else if ( st_uwHallNew==3 ){
      				    Start_Section = 4;
      				    swInitPos = swZOffset - 900 + swUOffset;
      				}
      				else if ( st_uwHallNew==4 ){
      				    Start_Section = 1;
      				    swInitPos = swZOffset + 900 + swUOffset;
      				}
      				else if ( st_uwHallNew==5 ){
      				    Start_Section = 0;
      				    swInitPos = swZOffset + 300 + swUOffset;
      				}
      				else{  // st_uwHallNew==6
      				    Start_Section = 2;
      				    swInitPos = swZOffset + 1500 + swUOffset;
      				}
//-- End 04/02/2008
    				STtune = 0;
                    PGSEL = 1;	// Read ABZ
	    			//SCI1_DIR = 0;
	    			if ( swInitPos<(-3600) ){ swInitPos += 3600; }

	    			if ( swInitPos>=3600 ){ swInitPos -= 3600; }
	    			else if ( swInitPos<0 ){ swInitPos += 3600; }
	    			st_uwInitPos  = (ULONG)swInitPos * SpDt_uwAnglePeriod / 3600;

	    			PM_uwStart = (Start_Section - pr[Z_SECT]) * SpDt_uwAnglePeriod / 6;

      				ulPGSWCnt = 0;
      				while ( ulPGSWCnt < 15000){ // waiting for UVW->ABZ 960us(At least 280us), DINO, 03/09/2010
      	   				ulPGSWCnt++;
      	   				nop();
      				}

	    		    //MTU2S4.TSR.BYTE  &= 0xF7;	// clear TGFD flag, dino, 04/09/2007	
	    		    MTU6.TSR.BYTE  &= 0xF7;     // clear TGFD flag
				    //MTU2S4.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable, dino, 04/09/2007 
				    MTU6.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable 
				    // [ TCNT0, TCNT1 counter are operated, dino, 04/04/2009
	    			//MTU2.TSTR.BYTE   |= 0x03;
                    MTU.TSTRA.BYTE   |= 0x03;
	    			// ]

        			Init_SpDtPG1();
        			if ( (pr[DEBUG_F1]&0x0040)==0 )  // Bit6==0, New method
        				//MTU21.TCNT = st_uwInitPos;   
                        MTU1.TCNT = st_uwInitPos;    
        			else
        				//MTU21.TCNT = PM_uwStart;
                        MTU1.TCNT = PM_uwStart;
                	//SpDt_uwPG1100usCNT_Old = MTU21.TCNT;
                    SpDt_uwPG1100usCNT_Old = MTU1.TCNT;
			    	if (PGDIR != 1)
						SpDt_uwPG1100usCNT_Old = 65535 - SpDt_uwPG1100usCNT_Old + 1;	

	    			Init_FOCPG();    
	    			SpdSearchAtStart();    // FOCPM initial
	    			pr[ST_TUNE] = 0;
                }
//-- Read Initial Position by EnDat, Add by dino, 08/29/2008
                else if ( (pr[PG_TYPE]==SIN_ENDAT || pr[PG_TYPE]==SIN_HIPER) && pr[Z_OFFSET]!=3600 ){
                    if ( TB_2sec==1 ){
                        Init_SpDtPG1();
                        swZOffset = (SWORD)st_uwPGThetaM;

						if ( PGDIR==1 )
							swZOffset += (SWORD)PG_Zoffset;
						else
							swZOffset -= (SWORD)PG_Zoffset;

						if ( swZOffset>SpDt_uwAnglePeriod )
							swZOffset -= (SWORD)SpDt_uwAnglePeriod;
						else if ( swZOffset<0 )
							swZOffset += (SWORD)SpDt_uwAnglePeriod;

                        //MTU21.TCNT = swZOffset;
                        MTU1.TCNT = swZOffset;
                        st_uwInitPos = st_uwAnaPGInit;
                        //SpDt_uwPG1100usCNT_Old = MTU21.TCNT;
                        SpDt_uwPG1100usCNT_Old = MTU1.TCNT;
				        if (PGDIR != 1)
							SpDt_uwPG1100usCNT_Old = 65535 - SpDt_uwPG1100usCNT_Old + 1;
                        STtune = 0;
                        pr[ST_TUNE] = 0;
                        Init_FOCPG();
                        SpdSearchAtStart();
                	}
                }
//-- End on 08/29/2008
                else {
			    	STDutyInit();	// calculate uwTGain for StandStill duty
			    	PM_swTmax = experiod + DeadTime;
			    	PM_swTmin = (SWORD)(experiod + DeadTime) - (SWORD)((ULONG)experiod*uwTGain>>8); 
			    }
            }
#endif
            else {
            	switch(pr[CTRLM]){
            		default:
            		case VF:
            		case VFPG:
            		case SVC:
						Init_VF();
						SpdSearchAtStart();
            			break;            		
            		case FOC:
            		    Init_FOC();
            		    SpdSearchAtStart();
            		    break;
            		case FOCPG:
#if SCOTTY										//ADDED BY SCOTTY 01/29/2007
					case FOCPM:				
#endif            		
            		    Init_FOCPG();			// determine TqSpdMode 
            		    SpdSearchAtStart();
            		    break;
            		case TQCPG:
            		    Init_FOCPG();
//            		    Init_TQCPG();
//            		    SpdSearchAtStart();
            			break;
 
                   case DBCSECA:
                        DBC_period = 2000;  // 10K
          		        TUN_Sector = DBC_IDLE0;          		         
                        TUN_WAIT = 1;
                        TUN_START = 1;
                        TUN_OK = 0;
            		    DBC_Init();
            		    DBC_VarInit();
                        break;
            	}
            }
            
            WG_Init();                                      // set carrier freq.

            if ((TqSpdMode == 0)&&(SPSEARCH==0)){
                if ((fkey.uw.hi<=fmin)||(MFI_WG==1)){
                	// [ Change STANDBY condition, DINO, 05/03/2010
                	if (pr[CTRLM]!=FOCPG && pr[CTRLM]!=FOCPM){
                		if (pr[SL_ZSP]==0)       			//Pr[01-34]
   		    	    	    // [ Setting flag after CMDRUN=RUN, DINO, 02/02/2010
                    		ubZSPDCI = 1;
                    		//STANDBY = 1;
                    		// ]
						else if (pr[SL_ZSP]==1){
							fcmd.ul = 0;
							ftemp.ul = 0;
   		    	    	    // [ Setting flag after CMDRUN=RUN, DINO, 02/02/2010
   		    	    	    ubZSPDCI = 1;
   		    	    	    /*
   		    	    	    RUNDCI = 1;
   			    		    ZEROST = 1;
		        			ZEROSP = 1;
		        			*/
		        			// ]
			        	}
			        	else if (pr[SL_ZSP]==2){
			     			fcmd.ul = ((ULONG)fmin<<16);
							ftemp.ul = ((ULONG)fmin<<16);
						}
					}
					else{
			        	if (pr[SL_ZSP]==2){
			     			fcmd.ul = ((ULONG)fmin<<16);
							ftemp.ul = ((ULONG)fmin<<16);   
						}
                         else{                 //[When Fcmd = fmin can't stop, Bernie, 2012/02/06]     
                             fcmd.ul = 0;
                             ftemp.ul = 0;
                         }
					}
					// ]
                }
                else{
                    if (fkey.uw.hi > fmin){
                    	if (Fcmd>FreqStart){
                        	fcmd.uw.hi = FreqStart;
                        	ftemp.uw.hi = FreqStart;
						}
						else{
                        	fcmd.uw.hi = Fcmd;
                        	ftemp.uw.hi = Fcmd;
						}
                    }
                }
            }
            
            //-�w�O�x
            // [ Delete by DINO, 06/17/2009
            /*
            if (pr[CTRLM] == FOCPM){
            	sw_preload = TqC_swTqOfstPu;	//SCOTTY 2007/08/07
        	}
        	*/
			// ]

    	    //----- Diagnostic MPHL Detection --------, added by Sampo, 05/12/2009
			if (pr[MPHLM] == 1){
				MPHL_DET = 1;
				TB1_swMPHLstep = 0;
				TB1_swMPHLcnt  = 0;
			}
			//]

            DINT();
            swTqInPu = 0; //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
            TqC_slTqOfstPu.sl = 0; //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]
			LIFT_ENABLE = 1;
			RUN_GOING = 0;
			if ( TUN_WAIT ){	// Add by DINO, 10/28/2008
				TUN_START = 1;			
			}
            // [ Add by DINO, 05/11/2009
            if ( TUN_SS ){
            	STtune = 1;
            }
            // ]

			// [ MPHL Detect, added by Sampo, 05/12/2009
			if (MPHL_DET == 1){
				TB1_MPHL_Buf = STtune;
				STtune = 0;
			}
			// ]

		    // [ For generation direction, by Justin , 2010/04/27 
		    if ( EPS && !GEN_START &&(GEN_OK==0)){ //[EPS, Sampo, 03/27/2011]   //[Modify EPS function, Bernie, 2012/11/27 ]
		    	if (GEN_EN == 1){
		    	    TB1_uwGencnt    = 0;
		    	    IqseOutPuLPF.sl = 0;
		    	    GEN_START       = 1;                    
                    if(PR_ubEpsOptMod==4){ //[EPS autodetect dir,Lyabryan,2018/07/02]
                        uwEPScnt = 2;
                        EPS_MODE4 = 1;
                        EPS_STOP = 1;
                    }
		    	}
		    }	
			//]

            EINT();
           // [ Short_Circuit Detection, DINO, 05/19/2010
			if ((pr[SysControl]&0x0020) == 0x0000){  //System Control bit5 = 1 (BEFORE RUN Diagnose)
				prt_ubBRStatus = CHARGE_START;
				BEFORERUN = 1;
			}
			// ]
			// [ RUNDCI double check, DINO, 02/02/2010
			if (RUNDCI2){
				RUNDCI = 1;
			}
			
			if (ubZSPDCI == 1){
				if (pr[SL_ZSP]==0){
					STANDBY = 1;
				}
				else{
				    if((pr[SysControl]&0x0800)==0x0000){   //[DCI redesign, Bernie, 2016/11/18]
    					RUNDCI = 1;
    					ZEROST = 1;
    					ZEROSP = 1;
					}
				}
			}
			// ]
        }
        else {
        	//****** (RUNNING==RUN || LIFT_ENABLE==1) -> vfd running now ******************//
            if(TUN_START==0 && STtune==0){
                if (STOPDCI){

                    STOPDCI = 0;      // STOP DCI mode ->> Disable Stop DC Injection
                    TB1_uwDCICnt = 0; //[DCI redesign, Bernie, 2016/11/18]
                    RUNDCI = 1;

                    if ( BRK_RLS==0 ){	// lock, add by dino, 12/12/2007
                    	SpdSearchAtStart();
                    }
                    else{
                    	if (Fcmd>FreqStart){
                    		fcmd.uw.hi = FreqStart;
                    		ftemp.uw.hi = FreqStart;
						}
						else{
                    		fcmd.uw.hi = Fcmd;
                    		ftemp.uw.hi = Fcmd;
						}
					}
                }    

				LIFT_ENABLE = 1;
            }
        }// end of vfd RUN/STOP status check
    }
}

void stop(void)
{
    if (((pr[AUTO_T]!=0) ||(pr[PM_AUTO_T]!=0))&&(TUN_START==1)&&(TUN_OK==0)){

		// [ Change to edge trigger after tuning, DINO, 06/24/2010
		TUN_STOP = 1;
		// ]

    	if (pr[AUTO_T]==1){
    		if (TUN_ROTARY_OK==0){
                if(Error == 0) //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
    			    Error = AuE_ERR;
            }
    	}
    	else if (pr[AUTO_T]==2){
    		if (TUN_HFSS_OK==0){
                if(Error == 0) //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
    			    Error = AuE_ERR;
            }
		}
		else if (pr[AUTO_T]==3){
			if (TUN_LFSL_OK==0){
                if(Error == 0) //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
				    Error = AuE_ERR;
            }
		}
//ADD SCOTTY 2007/06/13
		if (pr[PM_AUTO_T]==1 ){  // 08/13/2008
			if (TUN_PHASEZ_OK==0){
//				if (TUN_TuningCNT > (COF_ubMPolePair<<2))
				if ( TUN_Z_COMFIRM >=2 ){  // Modify by DINO, 08/14/2008
					// [ Set SpDt_uwPGErrTmp when PGFx_ERR, DINO, 05/11/2009
    				SpDt_uwPGErrTmp = PGF1_ERR;
    				// ]
					Error = PGF1_ERR;  // PG FBK ERROR
				}
				else if ( TUN_TuningCNT >(COF_ubMPolePair<<2) ){  // Z phase loss, add by DINO, 08/14/2008
					// [ Set SpDt_uwPGErrTmp when PGFx_ERR, DINO, 05/11/2009
    				SpDt_uwPGErrTmp = PGF2_ERR;
    				// ]
					Error = PGF2_ERR;  // PG LOSS
				}
				else{
                    if(Error == 0) //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
					    Error = AuE_ERR;
                }
			}
//			BRK_RLS = 0;	//lock   09/15/2007  // Delete by DINO, 07/09/2008
		}
		//--- PM Parameter Tune Error, Add by DINO, 08/14/2008 ---
		else if (pr[PM_AUTO_T]==2 ){
			if ( TUN_PMLS_OK==0 ){
                if(Error == 0) //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
    			    Error = AuE_ERR;
            }
    	}
		//---  With Load Tune Error, Add by DINO, 08/14/2008  ---
		else if ( pr[PM_AUTO_T]==3){  // 08/13/2008
			if (TUN_PHASEZ_OK==0){
				if ( TUN_uwTB1CNT>90 ){  // Z Phase Loss
					// [ Set SpDt_uwPGErrTmp when PGFx_ERR, DINO, 05/11/2009
    				SpDt_uwPGErrTmp = PGF2_ERR;
    				// ]
					Error = PGF2_ERR;
				}
				else{
				    if(Error == 0){ //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
					    Error = AuE_ERR;
					}
                }
			}
		}

		if ( pr[PG_TYPE]==ABZ_UVW ){
			PGSEL = 1;	
    		//MTU2S4.TSR.BYTE  &= 0xF7;	// clear TGFD flag
    		MTU6.TSR.BYTE  &= 0xF7;	// clear TGFD flag
    		//MTU2S4.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable  	
    		MTU6.TIER.BYTE |= 0x08;	// TGIED, Z-pulse capture interrupt enable 
		}
//End --- 2007/06/13
    }

	if ( TUN_SS && STtune==1 ){
		TUN_SS = 0;
		if (TUN_HFSS_OK == 0){
		    if(Error == 0){ //[Other erroe cause AUE_ERR,lyabryan,2016/06/12]
    		    Error = AuE_ERR;
    		}
    	}
    	// Add Absolute signal detection, DINO, 05/11/2009
    	else if (PGLOSS_ABS == 1){
    		//SpDt_uwPGErrTmp = PGF5_ERR;
    		//Error = PGF5_ERR;
    		SpDt_uwPGErrTmp = PGHL_ERR;   //[modify Error code,Lyabryan,2016/07/21]
    		Error = PGHL_ERR;
    	}
    	// ]
	}

    if ( CMDRUN==RUN ){
        TB1_uwDCICnt = 0;	// DC injection  counter.
    	TB1_uwBrkStopCnt   = 0;	// BK STOP Counter, dino, 12/12/2007
	}

    DINT();
    CMDRUN = STOP;
    LIFT_ENABLE = 0;
    RUN_GOING   = 0;		// dino, 12/12/2007
    EINT();  
	// [IODLC, Lyabryan, 2016/11/11] //[
	if(fcmd.uw.hi==0) //[Creep-Optimis,Lyabryan,2019/02/11]
        IODLC_ubArea_status = AreaStop;

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
    //] // [IODLC, Lyabryan, 2016/11/11]  

    //[ //[KEB ESD&ETS Function/Lyabryan/2018/08/10]

    btSR_ESD_EDGE = 0;
    btSR_speedCTRL_ESD = SR_control_return;
    btSR_speedCTRL_ETS = SR_control_return;
    btSR_ETS_EDGE = 0;

    //] //[KEB ESD&ETS Function/Lyabryan/2018/08/10]











    
    //[ //[EPS auto detect direction,Lyabryan,2018/07/16] 
    EPS_S1current_get = 0;
    EPS_S2current_get = 0;
    EPS_CAL_CUR = 0;
    EPS_CAL_CUREND = 0;
    EPS_MODE4 = 0;
    EPS_NOS1 = 0;
    EPS_TUNE_END = 0;
    EPS_swRecord_CNT = 0;
    EPS_swRecord_up = 0;
    EPS_DIR_CATCH = 0;
    //] //[EPS auto detect direction,Lyabryan,2018/07/16] 
    
    NORMALSP = 0;
    adjcnt = 0;
    Fcmd = 0;
    SPD_slPOScon.sl = 0;	//SCOTTY 03/11/2008
//    uw_SCTEST8 =0;			//SCOTTY 03/11/2008  
    SpDt_swNoground_CNT = 0; //[Encoder absulate position wrong detect, Lyabryan, 2015/08/21]
    Pgz_Disconnect_Init(); //[Zphase broken, Lyabryan, 2015/09/17]
    
    if (EXT_FORCESTOP==1){
    	if ((EXT_COASTSTOP==1)||((TqSpdMode == 1)&&(pr[SPLIMIT_SL]==0)))
    	{
    		CMDFREE = 1;
    	}
    	else{
    		// [ Debug the Force Stop, DINO, 06/29/2009
            if ((EXT_COASTSTOP==0)&&(pr[FORSTPWAY]==0))
            {
                CMDFREE = 1;
            }
            else
                CMDFREE = 0;
            // ]
    	}
	}
	else{
	    if ((pr[STOPM]==1)||((TqSpdMode == 1)&&(pr[SPLIMIT_SL]==0)))
	    {
	    	CMDFREE = 1;
	    }
	    else
	        CMDFREE = 0;
	}    

    //MTU20.TIER.BYTE &= 0xEF;	//TCIEV, timer 0 overflow interrupt disable
    //MTU0.TIER.BYTE &= 0xEF;	//TCIEV, timer 0 overflow interrupt disable // disable TCIV0 in Init_SpDtPG1() JOSH 20170706
    
}
    

void fwd_rev(void)
{
    if (JOG_DIR==0){
        if (CMDDIR == FORWARD) {
            if (pr[SETDIR]!=1) {               // Accept REVERSE command
                CMDDIR = REVERSE;
                if (RUNNING == STOP)
                    WGDIR = REVERSE;
            }
        }
        else{
            if (pr[SETDIR]!=2){                 // Accept FORWARD command
                CMDDIR = FORWARD;            
                if (RUNNING == STOP)
                    WGDIR = FORWARD;
            }
        }
    }
}

void ResetByKeypad(void){      //[Add auto restart after fault, Bernie, 06/06/12]

    if(rst_det == 1){       // reset key detecting and excuting, Sean, 08/19/2010                                       
        if((Error>=LvA_ERR && Error<=LvS_ERR) || Error==PHL_ERR || (Error>=ovA_ERR && Error<=ovS_ERR) || (Error>=ocA_ERR && Error<=GFF_ERR) || (Error==ocS_ERR)){ //[Add GFF and Ocx auto reset function, Jerry Yu, 2019/05/23]
    	    RST_EN = 0;                             //clear reset flag when reset by keypad
            pr[RESETCNT] = rec_uwRetryCnt;
            uwRetryCnt = rec_uwRetryCnt;
            uwRetryTimeCnt = pr[RESETINTERVAL]*10;   //re-assign original setting to time interval parameter setting
            rst_det = 0;                            //clear reset key enable flag
            RST_CNT_OK = 0;
            uwReset_10mCnt = 0;
        }
    }
}


#ifdef _KeyPad_C
	#undef _KeyPad_C
#endif
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/



