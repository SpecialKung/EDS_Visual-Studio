#ifndef _PH_IIC_C
	#define _PH_IIC_C
#endif

#include "ProgHeader.h"

void rtm_vdWrInt1(void);
void rtm_vdWrInt2(void);

void IIC_Init(){

  MSTP(RIIC1) = 0; // initial RIIC1 module

// ==== I/O setting ====//
  //MPC.P25PFS.BIT.PSEL = 15;
  //PORT2.PMR.BIT.B5 = 1;
  //PORT2.PDR.BIT.B5 = 0; // SCL is output

  //MPC.P26PFS.BIT.PSEL = 15;
  //PORT2.PMR.BIT.B6 = 1;
  //PORT2.PDR.BIT.B6 = 0; // SDA is output

  RIIC1.ICCR1.BIT.ICE = 0; // RIIC function disabled
  RIIC1.ICCR1.BIT.IICRST = 1; // RIIC internal reset
  RIIC1.ICCR1.BIT.IICRST = 0; // Cancel RIIC internal reset

  // [ Self address
  RIIC1.SARU0.BIT.FS = 0; // 7bit address format
//  RIIC1.SARL0.BYTE = 0x10; // Set self address
  RIIC1.SARL0.BYTE = 0x10;
  // ]

  // [ Set RIIC as 400KHz of PCLK48MHz // chiuju20110812
  RIIC1.ICMR1.BIT.CKS = 0x02; // IIC phi = PCLK/8 clock
  RIIC1.ICBRH.BIT.BRH = 7; // 400kbps (PCLK = 48MHz)
  RIIC1.ICBRL.BIT.BRL = 16;
  // ]

  RIIC1.ICMR3.BIT.ACKWP = 1; // Disable ACKBT protect
  RIIC1.ICMR3.BIT.SMBS = 0;

  RIIC1.ICIER.BYTE = 0x00; // Set interrupt enable

  RIIC1.ICCR1.BIT.ICE = 1; // RIIC transfer operation enabled


}

void write_ep(UBYTE wrFlag, UWORD prx, UWORD wrdata){
#if FRAM_BUF	// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 
	if (wrFlag == 0){
		 fram_buf[prx] = wrdata;
	}
	else
		pr[prx] = wrdata;
#else	
	UBYTE wrdata_h,wrdata_l;
	
	if(wrFlag==0){	// DINO, 03/03/2010
		IIC_Start();
		IIC_Data_Send(IIC_FRAM_WRITE_CODE);
		
		prx = prx*2;
		
		IIC_Data_Send((UBYTE)((prx&0xff00)>>8));
		IIC_Data_Send((UBYTE)(prx&0x00ff));
		wrdata_h = 0xff&wrdata>>8;
		wrdata_l = 0xff&wrdata;
		IIC_Data_Send(wrdata_l);
		IIC_Data_Send(wrdata_h);
		IIC_Stop();
	}
	else
		pr[prx] = wrdata;
#endif
}

UWORD read_ep(UWORD prx){
#if FRAM_BUF	// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 	
	return fram_buf[prx];	
#else		
	UBYTE dummy;	
	UBYTE rddata_h,rddata_l;
	UWORD rddata;
	UWORD wait=0;		//Timeout, Sean, 03/04/2010
	
	IIC_Start();
	IIC_Data_Send(IIC_FRAM_WRITE_CODE);
	
	prx= prx*2;
	
	IIC_Data_Send((UBYTE)((prx&0xff00)>>8));
	IIC_Data_Send((UBYTE)(prx&0x00ff));
	
	/* Start Condition */
	IIC3.ICCR2.BYTE = (IIC3.ICCR2.BYTE & 0xBF)|0x80;
	IIC_Data_Send(IIC_FRAM_READ_CODE);
		
	/* Select master recieve mode */
	IIC3.ICSR.BIT.TEND = 0;			/* Clears the TEND bit */
	IIC3.ICCR1.BIT.MST = 1;			/* Master mode */
	IIC3.ICCR1.BIT.TRS = 0;			/* Receive mode */
	IIC3.ICSR.BIT.TDRE = 0;			/* Clears the TDRE bit */
	//IIC3.ICCR1.BIT.RCVD = 1;		/* Disables to receive data continuously */	//sean: not in flowchart in manual
	
	/* Start recieving */
	IIC3.ICIER.BIT.ACKBT = 0;	/* ACK:low, keep recieving */
	dummy = IIC3.ICDRR;			/* Dummy Read */

	while(IIC3.ICSR.BIT.RDRF == 0){		//Timeout, Sean, 03/04/2010
		wait++;
		if(wait==65535){				
        	Error = cF2_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010								
			break;
		}
	}
	wait=0;
	IIC3.ICCR1.BIT.RCVD = 1;		//Sean, 05/17/2010
	IIC3.ICIER.BIT.ACKBT = 1;	/* ACK:high, to send ACK_ after reading last byte */
	rddata_l = IIC3.ICDRR;	
	
	while(IIC3.ICSR.BIT.RDRF == 0){		/* data ready */
		wait++;
		if(wait==65535){			    		
        	Error = cF2_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010						
			break;
		}
	}	
#if 1	//Sean, 05/17/2010	
	wait=0;
#endif	

	/* Stop Condition */
	//IIC3.ICSR.BIT.STOP = 0;				/* Clears the STOP flag */
	IIC3.ICSR.BYTE = IIC3.ICSR.BYTE & 0xf7;				/* Clears the STOP flag */	

	IIC3.ICCR2.BYTE	&= 0x3f;			/* Issues the STOP condition */
	//while(IIC3.ICSR.BIT.STOP == 0);		/* Wait Stop Condition confirmed */
	while((IIC3.ICSR.BYTE & 0x08) == 0x00){		/* Wait Stop Condition confirmed */  //Timeout, Sean, 03/04/2010
		wait++;
		if(wait==65535){				
        	Error = cF2_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010								
			break;
		}
	}	
	rddata_h = IIC3.ICDRR;				/* read data */
	IIC3.ICCR1.BIT.RCVD = 0;			/* Clears the RCVD bit */
	IIC3.ICCR1.BYTE &= 0xcf;			/* Slave receive mode */			
	
	rddata = rddata_h;
	rddata = rddata<<8;
	rddata |= rddata_l;
	return rddata;
#endif
}

void LoadEPData(void)       // called by initvar(main.c)
{
    UBYTE j, LimitErr = 0, ubParADR, HPSPEC_temp;
    UWORD i;
    
    // read parameter from eeprom
    //ewen(); //masked, FRAM no needed, Sean, 02/22/2010
    for(i=0; i<EPMAX; i++) {
        j = 10;
    //----------------------------------------------
	//[adjust floor position adjust,Aevin,2018/06/19]
    //Aevin add to adjust floor ----7/2/2018
    //if check 04-50~04-99 skip it
    #if 1
    if((i >= FL_POSIT_1H) && (i <= FL_POSIT_25L) )
        continue;
    #endif
    //----------------------------------------------
        
reload:
           
        pr[i]=read_ep(i);
         
        if ((attr[i].ati&SIGN)!=0){
        //if ((GetParAttr(i)&SIGN)!=0){
            if (((SWORD)pr[i]>(SWORD)attr[i].max)||((SWORD)pr[i]<(SWORD)attr[i].min)){
            //if (((SWORD)pr[i]>(SWORD)(GetParMax(i)))||((SWORD)pr[i]<(SWORD)GetParMin(i)))
                LimitErr = 1;
            }
            else
                LimitErr = 0;
        }
        else{
            if ((pr[i] > attr[i].max)||(pr[i] < attr[i].min)){ // parameter out of range
            //if ((pr[i] > GetParMax(i))||(pr[i] < GetParMin(i))) // parameter out of range
                LimitErr = 1;
            }
            else
                LimitErr = 0;
        }
     
        
        if (LimitErr==1){
            j--;
            if (j!=0)
                goto reload;
            else {
#if DINO  /* Record CF2 Parameter "cf2_index", add by dino, 10/01/2007 */
            	for ( ubParADR=GRENHANCE; ubParADR>=0; ubParADR-- ){
            		if ( ubParADR > GRENHANCE ){
            			cf2_index = 1500 + i;
            		    break;
            		}
            		else if ( i >= prtab[ubParADR] ){
            	    	cf2_index = (UWORD)ubParADR * 100 + (i - prtab[ubParADR]);
            	    	break;
            	    }
            	}
#endif
                Error = cF2_ERR;            // Read EEPROM ERROR
               
//				KEYRESET = 1;
                break;
            }
        }

#if DINO
		if ( i==HPSPEC ){
            HPSPEC_temp = pr[HPSPEC];        //[Single phase input, Bernie, 01/19/2012]
            if(pr[HPSPEC]>VFD_SINGLEPHASE)
                HPSPEC_temp -= VFD_SINGLEPHASE;
            
			//if (pr[HPSPEC] > MAXMODELNO)
			if (HPSPEC_temp > MAXMODELNO)     //[Single phase input, Bernie, 01/19/2012]
				pr[HPSPEC] = VFD110V23A;	// Modify by DINO, 05/27/2008
		}

		if ( (attr[i].ati&V440)==V440 ){		// Modify by DINO, 12/17/2008
			if ((pr[HPSPEC]&VFD440V)==VFD220V)	// 220V class
				pr[i] >>= 1;
		}
#else
        switch(i){
          	case HPSPEC:
                HPSPEC_temp = pr[HPSPEC];         //[Single phase input, Bernie, 01/19/2012]
                if(pr[HPSPEC]>VFD_SINGLEPHASE)
                    HPSPEC_temp -= VFD_SINGLEPHASE;
                
          	    //if (pr[HPSPEC] > MAXMODELNO)
          	    if (HPSPEC_temp > MAXMODELNO)     //[Single phase input, Bernie, 01/19/2012]
    	            pr[HPSPEC] = VFD110V23A;	// Modify by DINO, 05/27/2008
    	        break;     	
           	case VMAX1:
           	case VMID1_1:
           	case VMID1_2:
           	case VMIN1:
#if 0  // Delete Motor2 VF, DINO, 12/11/2010
           	case VMAX2:
           	case VMID2_1:
           	case VMID2_2:
           	case VMIN2:
#endif
           	case LVL:
           	case STALL4V:
           	case VEPS:
           	case DCBRK4V:
           	case PHL_L:
           	     if ((pr[HPSPEC]&VFD440V)==VFD220V)
           	         pr[i]>>=1;
           	     break;
           	default:
           	     break;
        }
#endif
    }
   // }
}


void wr_def2ep(void)
{
    UWORD i,uwTemp;
    UWORD MIRate,MIRate_tmp;
    UBYTE HPSPEC_temp;

    //ewen(); //masked, FRAM no needed, Sean, 02/22/2010
    pr[HPSPEC] = read_ep(HPSPEC);

    HPSPEC_temp = pr[HPSPEC];        //[Single phase input, Bernie, 01/19/2012]
    if(pr[HPSPEC]>VFD_SINGLEPHASE)
        HPSPEC_temp -= VFD_SINGLEPHASE;
    
    //if (pr[HPSPEC] > MAXMODELNO)
    if (HPSPEC_temp > MAXMODELNO)     //[Single phase input, Bernie, 01/19/2012]
    	pr[HPSPEC] = VFD110V23A;	// Modify by DINO, 05/27/2008

    for (i=0; i<EPMAX; i++){
  
    	if ((Error==cF2_ERR)||(pr[DEBUG_F1]&0x0400)==0x0400){

            if (i==SETCRF){
            	//if (pr[HPSPEC]<=VFD037V43A)		// ~ 5HP	
            	if (HPSPEC_temp<=VFD037V43A)		// ~ 5HP	//[Single phase input, Bernie, 01/19/2012]
					write_ep(0,i,8);	// Modify frame B default value of CF, Sean, 03/11/2011
            	//else if (pr[HPSPEC]<=VFD110V43A)       //7.5 ~ 15Hp
            	else if (HPSPEC_temp<=VFD110V43A)       //7.5 ~ 15Hp
                    write_ep(0,i,10);	// Modify default value of CF, DINO, 09/01/2010
              	//else if ((pr[HPSPEC]<=VFD220V43A) || (pr[HPSPEC]==VFD300V43A)) //15 ~ 30Hp	// 300V43A chg to frame D, Sean, 03/14/2011
                else if ((HPSPEC_temp<=VFD220V43A) || (HPSPEC_temp==VFD300V43A)) //15 ~ 30Hp	// 300V43A chg to frame D, Sean, 03/14/2011
                    write_ep(0,i,8);	// Modify default value of CF, DINO, 09/01/2010		  
                else
                	 write_ep(0,i,6);             //30 ~ 100Hp
            }
			// [ Soft Start Delay Time, Add by DINO, 12/17/2008
            else if (i==RLY_TIME){
            	//if (pr[HPSPEC]<=VFD110V43A){  // C Frame
            	if (HPSPEC_temp<=VFD110V43A){  // C Frame   //[Single phase input, Bernie, 01/19/2012]
            		if ( (pr[HPSPEC]&VFD440V)==VFD220V )	// 220 ClaSS
                    	write_ep(0,i,700);
                    else	// 440 Class
                    	write_ep(0,i,300);
            	}
            	//else if (pr[HPSPEC]>=VFD300V23A && pr[HPSPEC]!=VFD300V43A){  // E Frame	// 300V43A chg to frame D, Sean, 03/14/2011
                else if (HPSPEC_temp>=VFD300V23A && HPSPEC_temp!=VFD300V43A){  // E Frame	// 300V43A chg to frame D, Sean, 03/14/2011  //[Single phase input, Bernie, 01/19/2012]
                    if ( (pr[HPSPEC]&VFD440V)==VFD220V )	// 220 ClaSS
                    	write_ep(0,i,900);
                    else	// 440 Class
                    	write_ep(0,i,500);
				}
				else  // D Frame
					write_ep(0,i,0);
            }
            // ]
            else{ 

            	if(i!=HPSPEC){
/*              	    if ((i>=ACCEL1)&&(i<=JOGDEC)){		// Delete by DINO, 05/19/2008
                  	    if (pr[HPSPEC]>=VFD220V23A) //30.0HP
                    	    write_ep(0,i,6000);       //60.0sec
                  	    else
                    	    write_ep(0,i,attr[i].def);
                    }
            	    else*/ if ((i==MI_RAT1)||(i==MI_RAT2)||(i==PM_MI_RAT)){  // Delete Motor2 VF, DINO, 12/11/2010   //[Fixed PM I Rate not include in parameter, Bernie, 2013/03/12]
            	        if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                            pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
                        else
            		        pr[I_RATE] = CTispec[pr[HPSPEC]];
			            MIRate = ((ULONG)pr[I_RATE]*3686)>>12;    // 3686 / 2^12 = 0.8999023 
            		    write_ep(0,i,MIRate);
            	    }
            	    else if ((i==MI_NL1)/*||(i==MI_NL2)*/){  // Delete Motor2 VF, DINO, 12/11/2010
            		    if(pr[I_RATE] <= 15000)
                        {
                            COF_ulIbRe = ((ULONG)pr[I_RATE] * 231705) >> 16;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
                        }else
                        {
                            COF_ulIbRe = ((ULONG)pr[I_RATE] * 115258) >> 15;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
                        }
            		    COF_uwIIratePu = U32xU32divU32(pr[I_RATE], 46341, COF_ulIbRe);  // in Q15, 46341 = sqrt(2) * 2^15   // Jerry.sk.tseng for GFC High elecator 2021/08/17
            		    //[ //[Noload current default,Lyabryan,2016/05/12]
			            MIRate_tmp = ((ULONG)pr[I_RATE]*3686)>>12;    // 3686 / 2^12 = 0.8999023
            		    //MIRate = ((ULONG)COF_uwIIratePu*1638)>>12;    // 1638 / 2^12 = 0.3999023
            		    MIRate = ((ULONG)COF_uwIIratePu*3686)>>12;    // 3686 / 2^12 = 0.8999023 // motor rated = CTi*0.9
                        if((pr[HPSPEC]>=VFD370V23A)&&(pr[HPSPEC]<VFD_SINGLEPHASE))
                            MIRate = MIRate*3000/10000;    // 3686 / 2^12 = 0.8999023                            
                        else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD220V))
                            MIRate = MIRate*(((SLONG)MIRate_tmp*(-5681)+468046114)>>17)/10000;    // 3686 / 2^12 = 0.8999023
                        else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD440V))
                            MIRate = MIRate*(((SLONG)MIRate_tmp*(-5846)+234874163)>>16)/10000;    // 3686 / 2^12 = 0.8999023
                        else if(pr[HPSPEC]>VFD_SINGLEPHASE)
                            MIRate = MIRate*3500/10000;    // 3686 / 2^12 = 0.8999023                            
            		    write_ep(0,i,MIRate);
                        //] //[Noload current default,Lyabryan,2016/05/12]
            	    }
            	    else if ((i==P_RATED1)/*||(i==P_RATED2)/*||(i==PM_P_RATED)*/){  // Delete Motor2 VF, DINO, 12/11/2010
                        if(pr[HPSPEC]>VFD_SINGLEPHASE)  //[Single phase input, Bernie, 01/19/2012]
                            Power_RAT = HorsePower[(pr[HPSPEC]-VFD_SINGLEPHASE)>>1];
                        else
                            Power_RAT = HorsePower[pr[HPSPEC]>>1];
            		    write_ep(0,i,Power_RAT);
            	    }
		            else{

			            if ((pr[DEBUG_F1]&0x0400)==0x0400){	// Load all parameter to default value
			    			write_ep(0,i,attr[i].def);
			            }
			            else{
		            		if ((i>=FACTORY1)&&(i<=FACTORY4)){
				            	nop();
		            		}
		            		else if ((i>=DCB_AD1)&&(i<=DCB_AD3)){
		               	   		nop();
			        		}
			        		else if ((i>=CAUI2ZERO)&&(i<=CAUI1MIN)){ // dino, 03/21/2007
				            	nop();
			        		}
			        		else if ((i>=SINMAX)&&(i<=COSMIN)){  	// dino, 05/19/2008
				            	nop();
			        		}
			        		else if (i==Z_SECT){					// dino, 05/19/2008
				            	nop();
				            }
				            // [ Cannot load default, DINO, 12/23/2009
				            else if (i==PSW_2006H){
				            	nop();
				            }
				            // ]
			        		else
				            	write_ep(0,i,attr[i].def);
				        }
		    		}
              	}
            }
        }
        else{
        	if (SHOW_ALLPR==1){
            	if ((attr[i].ati&RLD)==RLD){          	  // Can Reset pratt bit4 = 1
            		if (i==SETCRF){
            			//if (pr[HPSPEC]<=VFD037V43A)		// ~ 5HP	
            			if (HPSPEC_temp<=VFD037V43A)		// ~ 5HP	//[Single phase input, Bernie, 01/19/2012]
							write_ep(0,i,8);	// Modify frame B default value of CF, Sean, 03/11/2011       			
            			//else if (pr[HPSPEC]<=VFD110V43A) 	  //7.5 ~ 15Hp
            			else if (HPSPEC_temp<=VFD110V43A) 	  //7.5 ~ 15Hp
                    		write_ep(0,i,10);	// Modify default value of CF, DINO, 09/01/2010
              			//else if ((pr[HPSPEC]<=VFD220V43A) || (pr[HPSPEC]==VFD300V43A)) //15 ~ 30Hp	// 300V43A chg to frame D, Sean, 03/14/2011
              			else if ((HPSPEC_temp<=VFD220V43A) || (HPSPEC_temp==VFD300V43A)) //15 ~ 30Hp	// 300V43A chg to frame D, Sean, 03/14/2011
                    		write_ep(0,i,8);	// Modify default value of CF, DINO, 09/01/2010
               			else
                	 		write_ep(0,i,6);			  //30 ~ 100Hp
            		}
            		/*-- Soft Start Delay Time, Add by DINO, 12/17/2008 ---*/
            		else if (i==RLY_TIME){
            			//if (pr[HPSPEC]<=VFD110V43A){  // C Frame
            			if (HPSPEC_temp<=VFD110V43A){  // C Frame    //[Single phase input, Bernie, 01/19/2012]
            				if ( (pr[HPSPEC]&VFD440V)==VFD220V )	// 220 ClaSS
            		        	write_ep(0,i,700);
            		        else	// 440 Class
            		        	write_ep(0,i,300);
            			}
            			//else if (pr[HPSPEC]>=VFD300V23A && pr[HPSPEC]!=VFD300V43A){  // E Frame	// 300V43A chg to frame D, Sean, 03/14/2011
            			else if (HPSPEC_temp>=VFD300V23A && HPSPEC_temp!=VFD300V43A){  // E Frame	// 300V43A chg to frame D, Sean, 03/14/2011
            				if ( (pr[HPSPEC]&VFD440V)==VFD220V )	// 220 ClaSS
            		        	write_ep(0,i,900);
            		        else	// 440 Class
            		        	write_ep(0,i,500);
						}
						else  // D Frame
							write_ep(0,i,0);
            		}
            		else{ 
/*                  		if ((i>=ACCEL1)&&(i<=JOGDEC)){		// Delete by DINO, 05/19/2008
                    		if (pr[HPSPEC]>=VFD220V23A) //30.0HP
                      			write_ep(BLK_WRITE,i,6000);       //60.0sec
                    		else
                      			write_ep(BLK_WRITE,i,attr[i].def);
                  		}
            			else*/ if ((i==MI_RAT1)||(i==MI_RAT2)||(i==PM_MI_RAT)){  // Delete Motor2 VF, DINO, 12/11/2010   //[Fixed PM I Rate not include in parameter, Bernie, 2013/03/12]
                            if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                                 pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
                            else
            			        pr[I_RATE] = CTispec[pr[HPSPEC]];
            			    MIRate = ((ULONG)pr[I_RATE]*3686)>>12;    // 3686 / 2^12 = 0.8999023
            			    write_ep(BLK_WRITE,i,MIRate);
            		    }
            		    else if ((i==MI_NL1)/*||(i==MI_NL2)*/){  // Delete Motor2 VF, DINO, 12/11/2010
            		        if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                                pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
                            else
            			        pr[I_RATE] = CTispec[pr[HPSPEC]];
            			    if(pr[I_RATE] <= 15000)
                            {
                                COF_ulIbRe = ((ULONG)pr[I_RATE] * 231705) >> 16;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
                            }else
                            {
                                COF_ulIbRe = ((ULONG)pr[I_RATE] * 115258) >> 15;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
                            }
            			    COF_uwIIratePu = U32xU32divU32(pr[I_RATE], 46341, COF_ulIbRe);
                            //[ //[Noload current default,Lyabryan,2016/05/12]
                            MIRate_tmp = ((ULONG)pr[I_RATE]*3686)>>12;    // 3686 / 2^12 = 0.8999023 
                            //MIRate = ((ULONG)COF_uwIIratePu*1638)>>12;    // 1638 / 2^12 = 0.3999023
                            MIRate = ((ULONG)COF_uwIIratePu*3686)>>12;    // 3686 / 2^12 = 0.8999023 // motor rated = CTi*0.9
                            if((pr[HPSPEC]>=VFD370V23A)&&(pr[HPSPEC]<VFD_SINGLEPHASE))
                                MIRate = MIRate*3000/10000;    // 3686 / 2^12 = 0.8999023                            
                            else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD220V))
                                MIRate = MIRate*(((SLONG)MIRate_tmp*(-5681)+468046114)>>17)/10000;    // 3686 / 2^12 = 0.8999023
                            else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD440V))
                                MIRate = MIRate*(((SLONG)MIRate_tmp*(-5846)+234874163)>>16)/10000;    // 3686 / 2^12 = 0.8999023
                            else if(pr[HPSPEC]>VFD_SINGLEPHASE)
                                MIRate = MIRate*3500/10000;    // 3686 / 2^12 = 0.8999023                            
                            write_ep(BLK_WRITE,i,MIRate);
                            //] //[Noload current default,Lyabryan,2016/05/12]
            		    }
                  		else if ((i==P_RATED1)/*||(i==P_RATED2)/*||(i==PM_P_RATED)*/){  // Delete Motor2 VF, DINO, 12/11/2010
                            if(pr[HPSPEC]>VFD_SINGLEPHASE)  //[Single phase input, Bernie, 01/19/2012]
                                Power_RAT = HorsePower[(pr[HPSPEC]-VFD_SINGLEPHASE)>>1];
                            else
                                Power_RAT = HorsePower[pr[HPSPEC]>>1];
            				write_ep(BLK_WRITE,i,Power_RAT);
            			}
/*            			else if ((i>=FACTORY1)&&(i<=FACTORY4)){  // Delete by DINO, 05/19/2008
							nop();                		
	                    }
	                    else if ((i>=DCB_AD1)&&(i<=DCB_AD3)){
	                    	nop();
						}
						else if ((i>=CAUI2ZERO)&&(i<=CAUI1MIN)){  // dino, 03/21/2007
							nop();
						}	*/
                            
                  		else
                    		write_ep(BLK_WRITE,i,attr[i].def);
               		}       
              	}
            }
            else{                           //Normal Reset
				// [ 00-02 Setting, DINO, 06/03/2010
				
            	if (SHOW_ENHANCE==1)
            		uwTemp = PRMAX;
            	else if (SHOW_ENHANCE==0)
            		uwTemp = GROUP13;
            
            	//uwTemp = GROUP13;
            	// ]

            	if (i > GROUP0){	//[Reload data ,Bernie, 08/09/2011]
            		if (i<uwTemp){
              			if ((attr[i].ati&RLD)==RLD){              // Can Reset pratt bit4 = 1
//modify C Frame 12k  D Frame 12k 
            				if (i==SETCRF){
            					//if (pr[HPSPEC]<=VFD037V43A)		// ~ 5HP	//[Single phase input, Bernie, 01/19/2012]
            					if (HPSPEC_temp<=VFD037V43A)		// ~ 5HP	
									write_ep(0,i,8);	// Modify frame B default value of CF, Sean, 03/11/2011
            					//else if (pr[HPSPEC]<=VFD110V43A) 	  //7.5 ~ 15Hp
            					else if (HPSPEC_temp<=VFD110V43A) 	  //7.5 ~ 15Hp
                    				write_ep(0,i,10);	// Modify default value of CF, DINO, 09/01/2010
              					//else if ((pr[HPSPEC]<=VFD220V43A) || (pr[HPSPEC]==VFD300V43A)) //15 ~ 30Hp	// 300V43A chg to frame D, Sean, 03/14/2011
              					else if ((HPSPEC_temp<=VFD220V43A) || (HPSPEC_temp==VFD300V43A)) //15 ~ 30Hp	// 300V43A chg to frame D, Sean, 03/14/2011
                    				write_ep(0,i,8);	// Modify default value of CF, DINO, 09/01/2010
                				else                              //30 ~ 100Hp
                	 				write_ep(0,i,6);
            				}
            				/*-- Soft Start Delay Time, Add by DINO, 12/17/2008 ---*/
            				else if (i==RLY_TIME){
            					//if (pr[HPSPEC]<=VFD110V43A){  // C Frame
            					if (HPSPEC_temp<=VFD110V43A){  // C Frame     //[Single phase input, Bernie, 01/19/2012]
            						if ( (pr[HPSPEC]&VFD440V)==VFD220V )	// 220 ClaSS
            				        	write_ep(0,i,700);
            				        else	// 440 Class
            				        	write_ep(0,i,300);
            					}
            					//else if (pr[HPSPEC]>=VFD300V23A && pr[HPSPEC]!=VFD300V43A){  // E Frame	// 300V43A chg to frame D, Sean, 03/14/2011
            					else if (HPSPEC_temp>=VFD300V23A && HPSPEC_temp!=VFD300V43A){  // E Frame	// 300V43A chg to frame D, Sean, 03/14/2011
            						if ( (pr[HPSPEC]&VFD440V)==VFD220V )	// 220 ClaSS
            				        	write_ep(0,i,900);
            				        else	// 440 Class
            				        	write_ep(0,i,500);
								}
								else  // D Frame
									write_ep(0,i,0);
            				}
            				else{ 
/*                    			if ((i>=ACCEL1)&&(i<=JOGDEC)){		// Delete by DINO, 05/19/2008
                      				if (pr[HPSPEC]>=VFD220V23A)     //30.0HP
                        				write_ep(BLK_WRITE,i,6000);           //60.0sec
                      				else
                        				write_ep(BLK_WRITE,i,attr[i].def);
                    			}
            					else*/ if ((i==MI_RAT1)||(i==MI_RAT2)||(i==PM_MI_RAT)){  // Delete Motor2 VF, DINO, 12/11/2010    //[Fixed PM I Rate not include in parameter, Bernie, 2013/03/12]
            					    if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                                        pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
                                    else
                                        pr[I_RATE] = CTispec[pr[HPSPEC]];
            				        MIRate = ((ULONG)pr[I_RATE]*3686)>>12;    // 3686 / 2^12 = 0.8999023
            				        write_ep(BLK_WRITE,i,MIRate);
            		    	    }
            		    	    else if ((i==MI_NL1)/*||(i==MI_NL2)*/){  // Delete Motor2 VF, DINO, 12/11/2010
                                    if(pr[HPSPEC] > VFD_SINGLEPHASE) //[Single phase input, Bernie, 01/19/2012]
                                        pr[I_RATE] = CTispecSingle[pr[HPSPEC]-VFD_SINGLEPHASE];
                                    else
                                        pr[I_RATE] = CTispec[pr[HPSPEC]];
            				        if(pr[I_RATE] <= 15000)
                                    {
                                        COF_ulIbRe = ((ULONG)pr[I_RATE] * 231705) >> 16;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
                                    }else
                                    {
                                        COF_ulIbRe = ((ULONG)pr[I_RATE] * 115258) >> 15;    // Jerry.sk.tseng for GFC High elecator 2021/08/17
                                    }
            				        COF_uwIIratePu = U32xU32divU32(pr[I_RATE], 46341, COF_ulIbRe);
                                    //[ //[Noload current default,Lyabryan,2016/05/12]
                                    MIRate_tmp = ((ULONG)pr[I_RATE]*3686)>>12;    // 3686 / 2^12 = 0.8999023 // motor rated = CTi*0.9
                                    //MIRate = ((ULONG)COF_uwIIratePu*1638)>>12;    // 1638 / 2^12 = 0.3999023
                                    MIRate = ((ULONG)COF_uwIIratePu*3686)>>12;    // 3686 / 2^12 = 0.8999023
                                    if((pr[HPSPEC]>=VFD370V23A)&&(pr[HPSPEC]<VFD_SINGLEPHASE))
                                        MIRate = MIRate*3000/10000;    // 3686 / 2^12 = 0.8999023                            
                                    else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD220V))
                                        MIRate = MIRate*(((SLONG)MIRate_tmp*(-5681)+468046114)>>17)/10000;    // 3686 / 2^12 = 0.8999023
                                    else if((pr[HPSPEC]<VFD370V23A)&&((pr[HPSPEC]&VFD440V)==VFD440V))
                                        MIRate = MIRate*(((SLONG)MIRate_tmp*(-5846)+234874163)>>16)/10000;    // 3686 / 2^12 = 0.8999023
                                    else if(pr[HPSPEC]>VFD_SINGLEPHASE)
                                        MIRate = MIRate*3500/10000;    // 3686 / 2^12 = 0.8999023                            
                                    write_ep(BLK_WRITE,i,MIRate);
                                    //] //[Noload current default,Lyabryan,2016/05/12]
            		    	    }
            					else if ((i==P_RATED1)/*||(i==P_RATED2)/*||(i==PM_P_RATED)*/){  // Delete Motor2 VF, DINO, 12/11/2010
                                    if(pr[HPSPEC] > VFD_SINGLEPHASE)        //[Single phase input, Bernie, 01/19/2012]
                                        Power_RAT = HorsePower[(pr[HPSPEC]-VFD_SINGLEPHASE)>>1];
                                    else
                                        Power_RAT = HorsePower[pr[HPSPEC]>>1];
            						write_ep(BLK_WRITE,i,Power_RAT);
            					}  
                    			else
                      				write_ep(BLK_WRITE,i,attr[i].def);
                  			}
                		}
              		}
            	}
            }
            
         
        } 
    }//End For loop
   //[ //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]
    if(Driver_ID == IEDS_DRIVER){ 
    
        DLC_Initial_value();
        DINT();
        InitValue();
        EINT();   
    }
    else if(Driver_ID == EDS_DRIVER){
	//#16550 Artemis default value, James, 20210520
//#if Artemis_ENABLE
    //[btArtemisEnable at pr[00-02]=200, Special.Kung, 2022/12/02]
    if(btArtemisEnable)
    {
    	pr[CAN_BURD] = 2;
    	write_ep(BLK_WRITE,CAN_BURD, 2);
    	DLC_Initial_value();
    	DINT();
    	InitValue();
    	EINT();
    }
//#endif		
    }
    //] //[IEDS vs. EDS deriver,Lyabryan,2016/07/14]

    for(i=0; i<DLCMAX; i++){
            DLCxx[i] = 0;
    }
	//--- Update BUFFER Data, Add by DINO, 10/27/2008
	rec_uwFault1  = read_ep(ERR_REC1);
	rec_uwFault2  = read_ep(ERR_REC2);
	rec_uwFault3  = read_ep(ERR_REC3);
	rec_uwFault4  = read_ep(ERR_REC4);
	rec_uwFault5  = read_ep(ERR_REC5);
	rec_uwFault6  = read_ep(ERR_REC6);
    //[special,increase error record, 2018/09/20
    rec_uwError1_1 = read_ep(FOUT_REC1);
    rec_uwError1_2 = read_ep(DCBUS_REC2);
    rec_uwError1_3 = read_ep(ISUM_REC2);
    rec_uwError1_4 = read_ep(TH_TEMP1);
    rec_uwError2_1 = read_ep(FOUT_REC2);
    rec_uwError2_2 = read_ep(DCBUS_REC2);
    rec_uwError2_3 = read_ep(ISUM_REC2);
    rec_uwError2_4 = read_ep(TH_TEMP2);
    rec_uwError3_1 = read_ep(FOUT_REC3);
    rec_uwError3_2 = read_ep(DCBUS_REC3);
    rec_uwError3_3 = read_ep(ISUM_REC3);
    rec_uwError3_4 = read_ep(TH_TEMP3);
    rec_uwError4_1 = read_ep(FOUT_REC4);
    rec_uwError4_2 = read_ep(DCBUS_REC4);
    rec_uwError4_3 = read_ep(ISUM_REC4);
    rec_uwError4_4 = read_ep(TH_TEMP4);
    rec_uwError5_1 = read_ep(FOUT_REC5);
    rec_uwError5_2 = read_ep(DCBUS_REC5);
    rec_uwError5_3 = read_ep(ISUM_REC5);
    rec_uwError5_4 = read_ep(TH_TEMP5);
    //special,increase error record, 2018/09/20]
	rec_uwFfbk    = read_ep(FFBK_REC);
	rec_uwFcmd    = read_ep(FOUT_REC);
	rec_uwVout    = read_ep(VOUT_REC);
	rec_uwDcbus   = read_ep(DCBUS_REC);
	rec_uwIsum    = read_ep(ISUM_REC);
	rec_uwIGBT    = read_ep(TH_TEMP);
	rec_uwSRY     = read_ep(SRYREC);	
	rec_uwPWRmin  = read_ep(PWR_MIN);
	rec_uwRUNmin  = read_ep(RUNMIN);
	TQRCMemswPer  = read_ep(TQREF);
	uwFkeypad	  = read_ep(FMAIN);
	C20xx[0x01]   = read_ep(FCMAIN);
	MI_INVMem  	  = read_ep(MI_INV);
	MO_INVMem     = read_ep(MO_INV);
	PGHOMEMem     = read_ep(PGHOME);
	// [ Add Fault Record Data, DINO, 06/11/2009
	rec_uwErrMin1 = read_ep(ERR_MIN1);
	rec_uwErrDay1 = read_ep(ERR_DAY1);
	rec_uwErrMin2 = read_ep(ERR_MIN2);
	rec_uwErrDay2 = read_ep(ERR_DAY2);
	rec_uwErrMin3 = read_ep(ERR_MIN3);
	rec_uwErrDay3 = read_ep(ERR_DAY3);
	rec_uwErrMin4 = read_ep(ERR_MIN4);
	rec_uwErrDay4 = read_ep(ERR_DAY4);
	rec_uwErrMin5 = read_ep(ERR_MIN5);
	rec_uwErrDay5 = read_ep(ERR_DAY5);
	rec_uwErrMin6 = read_ep(ERR_MIN6);
	rec_uwErrDay6 = read_ep(ERR_DAY6);
	rec_uwFkey	  = read_ep(FKEY_REC);
    rec_uwPower   = read_ep(POWER_REC);
    rec_uwTorq    = read_ep(TQ_REC);
    rec_uwMFI    = read_ep(MFI_REC);
    rec_uwMFO     = read_ep(MFO_REC);
	rec_uwState   = read_ep(STATE_REC);
	// ]

    // [ Initial Page, DINO, 06/01/2010
    KEY_ubPrno[0]  = 0;
    if (grno == 0){
    	prno = 0;
    }
    // ]

}

void wr_FF2ep(void)
{
	UWORD i;
	
    for (i=0; i<EPMAX; i++){
    	write_ep(0,i,0xFFFF);
	}
}


void IIC_Start(){
	UWORD wait=0;//Timeout, Sean, 03/04/2010

    wait=0;
	while (RIIC1.ICCR2.BIT.BBSY != 0){    // Check Bus free
		wait++;
		if(wait==65535){			    	
        	Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
        	err_uwFRAMErrRd = 0x01;
			break;
		}
	}
	/* Master Transmission Mode */
	RIIC1.ICCR2.BIT.MST = 1;		/* Selects the master */
	RIIC1.ICCR2.BIT.TRS = 1;		/* Selects the transmission */	
	/* Start Condition */
	//IIC3.ICCR2.BYTE = (IIC3.ICCR2.BYTE & 0xBF)|0x80;
    RIIC1.ICCR2.BIT.ST = 1; // Issue a start condition
}


void IIC_RStart(void)
{
   RIIC1.ICCR2.BIT.RS = 1;
   RIIC1.ICMR1.BIT.MTWP = 1; // When the MTWP bit in ICMR1 is set to 1, the MST and TRS bits can be written to.
   RIIC1.ICCR2.BIT.TRS = 0;
   RIIC1.ICCR2.BIT.MST = 1;
}

void IIC_Data_Send(UBYTE Data){
	UWORD wait=0;	//Timeout, Sean, 03/04/2010	

    wait=0;
    while (RIIC1.ICSR2.BIT.TDRE == 0){
		wait++;
		if(wait==65535){			    		
        	Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
        	err_uwFRAMErrRd = 0x02;
			break;
		}
	}
    RIIC1.ICDRT = Data;					/* Data Register:put data for transfer */
	wait=0;	

    
	while (RIIC1.ICSR2.BIT.TEND == 0){	//Timeout, Sean, 03/04/2010
		wait++;
		if(wait==65535){			    		
        	Error = cF1_ERR;          // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
        	err_uwFRAMErrRd = 0x03;
			break;
		}
	}
	wait=0;		
	while (RIIC1.ICSR2.BIT.NACKF == 1){		/* wait ACK from slave */ //Timeout, Sean, 03/04/2010
		wait++;
		if(wait==65535){			    		
        	Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
        	err_uwFRAMErrRd = 0x04;
			break;
		}
	}
}

void IIC_DataSend4Read(UBYTE Data)
{
  UWORD wait;


  wait = 0;
 
  while (RIIC1.ICSR2.BIT.TDRE == 0) { // Transmit Data Empty Flag
        wait++;
		if(wait==65535){			    // 0: ICDRT contains transmit data  1: ICDRT contains no transmit data    		
        	Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
        	err_uwFRAMErrRd = 0x05;
			break;
		}  
  }

  RIIC1.ICDRT = Data; // Transmit data

  wait = 0;

  while (RIIC1.ICSR2.BIT.RDRF == 0) { // Receive Data Full Flag
     wait++;
	 if(wait==65535){			   // 0: ICDRT contains transmit data   1: ICDRT contains no transmit data
         Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
         err_uwFRAMErrRd = 0x06;
         break;
     }  
  }

  wait = 0;

  while (RIIC1.ICSR2.BIT.NACKF == 1) { // NACK Detection Flag
     wait++;
	 if(wait==65535){			      // 0: NACK is not detected   1: NACK is detected
         Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
         err_uwFRAMErrRd = 0x07;
         break;
     }  
  }
}

void IIC_Stop(){
	UWORD wait=0;
    UWORD uwHoldOnWait;

  //RIIC1.ICSR2.BIT.STOP = 0;
  RIIC1.ICSR2.BYTE &= 0xF7;
  RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition
  uwHoldOnWait = RIIC1.ICDRR; // Dummy read

  uwHoldOnWait = 0;

  //while (RIIC1.ICSR2.BIT.STOP == 0) { // Wait Stop Condition confirmed
  wait=0;
  while ((RIIC1.ICSR2.BYTE & 0x08) == 0) { // Wait Stop Condition confirmed
      wait++;
	  if(wait==65535){			    		
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
          err_uwFRAMErrRd = 0x08;
	      break;
      }
  }

  RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
  //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
  RIIC1.ICSR2.BYTE &= 0xF7;

}

// Fram_Buf added and FRAM read/write to Fram_Buf instead, Sean, 06/30/2010 
void frm_vdWrite(void){
	UWORD DataSizeCnt;
	UBYTE wrdata_h,wrdata_l,address_h,address_l;
    UWORD wait=0;
    UWORD uwWrAdsFram;
    
	for (DataSizeCnt = GROUP15; DataSizeCnt<EPMAX; DataSizeCnt++){ 
	     IIC_Start();
	     IIC_Data_Send(IIC_FRAM_WRITE_CODE);

         uwWrAdsFram = (GROUP15+DataSizeCnt) * 2;
         //address_h = (UBYTE)(0xff00 &(GROUP15+DataSizeCnt) >> 8);
         //address_l = (UBYTE)(0x00ff &(GROUP15+DataSizeCnt));
         address_h = (UBYTE)((0xff00 & uwWrAdsFram) >> 8);
         address_l = (UBYTE)( 0x00ff & uwWrAdsFram);
         
	     IIC_Data_Send(address_h);
	     IIC_Data_Send(address_l);
	
		 wrdata_h = (UBYTE)((0xff00 & fram_buf[GROUP15+DataSizeCnt]) >> 8);
		 wrdata_l = (UBYTE)(0x00ff & fram_buf[GROUP15+DataSizeCnt]);
		 IIC_Data_Send(wrdata_l);
        
		 IIC_Data_Send(wrdata_h);
	
         wait=0;
         while (RIIC1.ICSR2.BIT.TEND == 0){	//Timeout, Sean, 03/04/2010
		     wait++;
		     if(wait==65535){			    		
        	     Error = cF1_ERR;          // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
        	     err_uwFRAMErrRd = 0x09;
			     break;
		     }
	     }
	IIC_Stop();
    }
}

void frm_vdWrite2(void){
	UWORD DataSizeCnt;
	UBYTE wrdata_h,wrdata_l;
    UWORD wait=0;

	IIC_Start();
	IIC_Data_Send(IIC_FRAM_WRITE_CODE);
	IIC_Data_Send(0xFF);
	IIC_Data_Send(0x00);
	//for (DataSizeCnt = GROUP15; DataSizeCnt<=EPMAX; DataSizeCnt++){ 
		wrdata_h = 0x01;
		wrdata_l = 0x02;
		IIC_Data_Send(wrdata_h);
        
		IIC_Data_Send(wrdata_l);
	//}
    //while (RIIC1.ICSR2.BIT.TEND == 0){	//Timeout, Sean, 03/04/2010
		//wait++;
		//if(wait==65535){			    		
        	//Error = cF1_ERR;          // cF1 Write to EEPROM  Error, Sean, 03/04/2010										
			//break;
		//}
	//}
	IIC_Stop();
}
#if 0
void frm_vdRead(void){
	UBYTE dummy;	// tmp for IIC processing
	UWORD read_cnt;	
	UBYTE rdrf;
	UBYTE rddata_l,rddata_h;
	UWORD wait=0;	//Timeout, Sean, 03/04/2010		

	IIC_Start();
	
	/* Send Device Info and Address */
	IIC_Data_Send(IIC_FRAM_WRITE_CODE);
	
	IIC_Data_Send(0x00);
	
	IIC_Data_Send((UBYTE)GROUP15);	

	/* Start Condition */
	//IIC3.ICCR2.BYTE = (IIC3.ICCR2.BYTE & 0xBF)|0x80;
    IIC_RStart();
	/* Issue read command */
	IIC_Data_Send(IIC_FRAM_READ_CODE);		
	
	/* Select master recieve mode */
	//IIC3.ICSR.BIT.TEND = 0;			/* Clears the TEND bit */
	//IIC3.ICCR1.BIT.MST = 1;			/* Master mode */
	//IIC3.ICCR1.BIT.TRS = 0;			/* Receive mode */
	//IIC3.ICSR.BIT.TDRE = 0;			/* Clears the TDRE bit */
	//IIC3.ICCR1.BIT.RCVD = 1;		/* Disables to receive data continuously */	//sean: not in flowchart in manual

	/* Start recieving */
	//IIC3.ICIER.BIT.ACKBT = 0;	/* ACK:low, keep recieving */
	RIIC1.ICMR3.BIT.WAIT = 1; // 0: No WAIT   1: WAIT
    RIIC1.ICMR3.BIT.ACKBT = 1; // Set NACK
	dummy = RIIC1.ICDRR;			/* Dummy Read */
	
	//normal read
	for (read_cnt=GROUP15;read_cnt<EPMAX;read_cnt++){
		//get low byte data
		if(read_cnt<EPMAX){
    		while(RIIC1.ICSR2.BIT.RDRF == 0){		/* last byte ready */	//Timeout, Sean, 03/04/2010
    			wait++;
    			if(wait==65535){			    	
            		Error = cF1_ERR;            // cF1 Write to EEPROM  Error, Sean, 03/04/2010									
    				break;
    			}
    		}	
    		wait=0;	
    		rddata_l = RIIC1.ICDRR;				// low byte data
    		
    		//get high byte data
    		while(RIIC1.ICSR2.BIT.RDRF == 0){		/* last byte ready */	//Timeout, Sean, 03/04/2010
    			wait++;
    			if(wait==65535){			    	
            		Error = cF1_ERR;            // cF1 Write to EEPROM  Error, Sean, 03/04/2010									
    				break;
    			}
    		}
    		wait=0;
    		rddata_h = RIIC1.ICDRR;				// high byte data
		}
        else{  // the last two byte
            while(RIIC1.ICSR2.BIT.RDRF == 0){		/* last byte ready */	//Timeout, Sean, 03/04/2010
    			wait++;
    			if(wait==65535){			    	
            		Error = cF1_ERR;            // cF1 Write to EEPROM  Error, Sean, 03/04/2010									
    				break;
    			}
    		}	
    		wait=0;
            
            RIIC1.ICMR3.BIT.RDRFS = 1;
            RIIC1.ICMR3.BIT.ACKBT = 1;
                
            rddata_l = RIIC1.ICDRR;
            
            while(RIIC1.ICSR2.BIT.RDRF == 0){		/* last byte ready */	//Timeout, Sean, 03/04/2010
    			wait++;
    			if(wait==65535){			    	
            		Error = cF1_ERR;            // cF1 Write to EEPROM  Error, Sean, 03/04/2010									
    				break;
    			}
    		}	
    		wait=0;
            
            //RIIC1.ICSR2.BIT.STOP = 0;
            RIIC1.ICSR2.BYTE &= 0xF7;
            RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition

            rddata_h = RIIC1.ICDRR;				// high byte data
            
            RIIC1.ICMR3.BIT.ACKBT = 1;
            RIIC1.ICMR3.BIT.WAIT = 0;

            while ((RIIC1.ICSR2.BYTE & 0x08) == 0) { // Wait Stop Condition confirmed
                wait++;
	            if(wait==65535){			    		
                    Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010								
	                break;
                }
            }

            RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
            //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
            RIIC1.ICSR2.BYTE &= 0xF7;
            
        }
		//combine data
		fram_buf[read_cnt] = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
	}
		
	//to end IIC read
	while(RIIC1.ICSR2.BIT.RDRF == 0){	//Timeout, Sean, 03/04/2010
		wait++;
		if(wait==65535){			    		
    		Error = cF1_ERR;            	  // cF1 Write to EEPROM  Error, Sean, 03/04/2010									
			break;
		}
	}	
	wait=0;
    //RIIC1.ICSR2.BIT.STOP = 0;
    RIIC1.ICSR2.BYTE &= 0xF7;
    RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition
	//IIC3.ICCR1.BIT.RCVD = 1;		/* Disables to receive data continuously */	//sean: not in flowchart in manual
	//IIC3.ICIER.BIT.ACKBT = 1;	    /* ACK:high, to send ACK_ after reading last byte */
	dummy = RIIC1.ICDRR;
	while(RIIC1.ICSR2.BIT.RDRF == 0){		/* last byte ready */	//Timeout, Sean, 03/04/2010
			wait++;
			if(wait==65535){			    	
        		Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010								
				break;
			}
	}	
    RIIC1.ICMR3.BIT.WAIT = 0;
    wait=0;	
	/* Stop Condition */
//	IIC3.ICSR.BIT.STOP 	= 0;				/* Clears the STOP flag */
	//IIC3.ICSR.BYTE = IIC3.ICSR.BYTE & 0xf7;	/* Clears the STOP flag */	
	//IIC3.ICCR2.BYTE	&= 0x3f;				/* Issues the STOP condition */
//	while(IIC3.ICSR.BIT.STOP == 0);			/* Wait Stop Condition confirmed */
	while((RIIC1.ICSR2.BYTE & 0x08) == 0){	/* Wait Stop Condition confirmed */	
		wait++;
		if(wait==65535){			    	
       		Error = cF1_ERR;             	// cF1 Write to EEPROM  Error, Sean, 03/04/2010								
			break;
		}
	}	
	dummy = RIIC1.ICDRR;						/* The last byte */

    RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
    //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
    RIIC1.ICSR2.BYTE &= 0xF7;
	/* reset mode */                    	
	//IIC3.ICCR1.BIT.RCVD = 0;				/* Clears the RCVD bit */
	//IIC3.ICCR1.BYTE &= 0xcf;				/* Slave receive mode */					
}
#endif

void frm_vdWrite4User(void){
	UWORD DataSizeCnt;
	UBYTE wrdata_h,wrdata_l,address_h,address_l;
    UWORD wait=0;
    UWORD uwWrAdsFram;
    
	for (DataSizeCnt = GROUP0; DataSizeCnt<GROUP14; DataSizeCnt++){ 
	     IIC_Start();
	     IIC_Data_Send(IIC_FRAM_WRITE_CODE);

         //uwWrAdsFram = ((GROUP15+DataSizeCnt) * 2)+4097;
         uwWrAdsFram = ((GROUP15+DataSizeCnt) * 2) + SECTION2_StAddr;

         //address_h = (UBYTE)(0xff00 &(GROUP15+DataSizeCnt) >> 8);
         //address_l = (UBYTE)(0x00ff &(GROUP15+DataSizeCnt));
         address_h = (UBYTE)((0xff00 & uwWrAdsFram) >> 8);
         address_l = (UBYTE)( 0x00ff & uwWrAdsFram);
         
	     IIC_Data_Send(address_h);
	     IIC_Data_Send(address_l);
	
		 //wrdata_h = (UBYTE)((0xff00 & pr[GROUP15+DataSizeCnt]) >> 8);
		 //wrdata_l = (UBYTE)(0x00ff & pr[GROUP15+DataSizeCnt]);
         wrdata_h = (UBYTE)((0xff00 & pr[GROUP15+DataSizeCnt]) >> 8);
		 wrdata_l = (UBYTE)(0x00ff & pr[GROUP15+DataSizeCnt]);

         //wrdata_h = (UBYTE)((0xff00 & 3000) >> 8);
		 //wrdata_l = (UBYTE)(0x00ff & 3000);

         
		 IIC_Data_Send(wrdata_l);
		 IIC_Data_Send(wrdata_h);
	
         wait=0;
         while (RIIC1.ICSR2.BIT.TEND == 0){	//Timeout, Sean, 03/04/2010
		     wait++;
		     if(wait==65535){			    		
        	     Error = cF1_ERR;          // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
        	     err_uwFRAMErrRd = 0x09;
			     break;
		     }
	     }
	IIC_Stop();
    }
}

void frm_vdRead4User(void){
  UWORD uwTemp;
  UBYTE rddata_l;
  UBYTE rddata_h;
  UWORD read_cnt, read_Addr;	

  err_uwFRAMErrRd = 0;
  read_Addr = 0;
  //for (read_cnt=GROUP15;read_cnt<EPMAX;read_cnt++){
  for (read_cnt=GROUP0;read_cnt<GROUP14;read_cnt++){
      //
      //read_cnt += 4097;
      read_Addr = GROUP15+read_cnt;
      // [ Combine two bytes to one word // chiuju20110812

      rddata_l = IIC_PrRd4UserStep1(read_Addr);
      rddata_h = IIC_PrRd4UserStep2();

      //uwTemp = rddata_h;
      //uwTemp = uwTemp << 8;
      //uwTemp |= rddata_l;
      // ]
      if(read_cnt == GROUP4)
        //uwtest6++;
          //uwtest6 = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
      if(read_cnt == GROUP4+1)
        //uwtest7++;
          //uwtest7 = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
      if(read_cnt == GROUP4+2)
        //uwtest8++;
          //uwtest8 = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
      if(read_cnt == GROUP4+3)
        //uwtest9++;
          //uwtest9 = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
      //pr[FMAX] = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
      
      fram_buf[read_cnt] = (UWORD)rddata_l + ((UWORD)rddata_h << 8);
  }

}

void frm_vdRead(void){
  UWORD uwTemp;
  UBYTE rddata_l;
  UBYTE rddata_h;
  UWORD read_cnt;	

  err_uwFRAMErrRd = 0;
  
  for (read_cnt=GROUP15;read_cnt<EPMAX;read_cnt++){

      //
  
      // [ Combine two bytes to one word // chiuju20110812
      rddata_l = IIC_PrRdStep1(read_cnt);
      rddata_h = IIC_PrRdStep2();

      //uwTemp = rddata_h;
      //uwTemp = uwTemp << 8;
      //uwTemp |= rddata_l;
      // ]
      fram_buf[read_cnt] = (UWORD)rddata_l + ((UWORD)rddata_h << 8);

  }

}

UBYTE IIC_PrRdStep1(UWORD uwRdAds) 
{
    UWORD uwRdAdsFram;
    UBYTE rddata_l;
    UBYTE ubTemp;
    UWORD wait;


    uwRdAdsFram = 0xFFFF;
/*
  if (uwRdAds >= 0x1000) {
    err_uwNvsErrRd = 0x11;
    return (OFF);
  }
*/
  // [
    IIC_Start();
    if (Error != 0) {
        IIC_Stop();
        err_uwFRAMErrRd = 0x10;
  
    }
  
    IIC_Data_Send(IIC_FRAM_WRITE_CODE);
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x11;

    }
    // ]

  // [
    uwRdAdsFram = uwRdAds * 2; // FRAM is byte-unit,hence address * 2 for one word(two bytes)
  
    IIC_Data_Send((UBYTE)((uwRdAdsFram&0xff00)>>8));
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x12;
    }

    IIC_Data_Send((UBYTE)(uwRdAdsFram&0x00ff));
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x13;
    }
  // ]

  // [
    IIC_Stop();
    if (err_uwFRAMErrRd != 0) {
      err_uwFRAMErrRd = 0x14;
    }
  
    IIC_Start();
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x15;
    }
  
    IIC_DataSend4Read(IIC_FRAM_READ_CODE);
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x16;
    }
  
    RIIC1.ICMR3.BIT.WAIT = 1; // 0: No WAIT   1: WAIT
    RIIC1.ICMR3.BIT.ACKBT = 1; // Set NACK
  
    ubTemp = RIIC1.ICDRR; // Dummy read
  // ]

  // [
  wait = 0;
  while (RIIC1.ICSR2.BIT.RDRF == 0) {
      wait++;
      if(wait==65535){	
          IIC_Stop();
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
          err_uwFRAMErrRd = 0x17;
  	      break;
      }
  }

  //RIIC1.ICSR2.BIT.STOP = 0;
  RIIC1.ICSR2.BYTE &= 0xF7;
  RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition

  rddata_l = RIIC1.ICDRR; // Receive first data byte
  // ]

  RIIC1.ICMR3.BIT.WAIT = 0;

  wait = 0;
  //while (RIIC1.ICSR2.BIT.STOP == 0) { // Wait Stop Condition confirmed
  while ((RIIC1.ICSR2.BYTE & 0x08) == 0) {
      wait++;
      if(wait==65535){	
          IIC_Stop();
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
          err_uwFRAMErrRd = 0x18;
  	      break;
      }
  }

  RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
  //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
  RIIC1.ICSR2.BYTE &= 0xF7;
  return (rddata_l);
}

/*----------------------------------------------------------------------------*/
UBYTE IIC_PrRdStep2(void) // chiuju20110812
{
  UBYTE rddata_h;
  UBYTE ubTemp;
  UWORD wait;


  // [
  IIC_Start();
  if (err_uwFRAMErrRd != 0) {
    IIC_Stop();
    err_uwFRAMErrRd = 0x21;
  }

  IIC_DataSend4Read(IIC_FRAM_READ_CODE);
  if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x22;
  }

  RIIC1.ICMR3.BIT.WAIT = 1; // 0: No WAIT   1: WAIT
  RIIC1.ICMR3.BIT.ACKBT = 1; // Set NACK

  ubTemp = RIIC1.ICDRR; // Dummy read
  // ]

  // [
  wait = 0;

  while (RIIC1.ICSR2.BIT.RDRF == 0) {
      wait++;
      if(wait==65535){	
          IIC_Stop();
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
          err_uwFRAMErrRd = 0x23;
          break;
      }
  }

  //RIIC1.ICSR2.BIT.STOP = 0;
  RIIC1.ICSR2.BYTE &= 0xF7;
  RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition

  rddata_h = RIIC1.ICDRR; // Receive last data byte
  // ]

  RIIC1.ICMR3.BIT.WAIT = 0;

  wait = 0;

  //while (RIIC1.ICSR2.BIT.STOP == 0) { // Wait Stop Condition confirmed
  while ((RIIC1.ICSR2.BYTE & 0x08) == 0) {
    wait++;
    if(wait==65535){	
        IIC_Stop();
        Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
        err_uwFRAMErrRd = 0x24;
        break;
    }
  }

  RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
  //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
  RIIC1.ICSR2.BYTE &= 0xF7;
  return (rddata_h);
}

void frm_vdDLCWrite(void){
    UWORD DataSizeCnt;
    UBYTE wrdata_h,wrdata_l,address_h,address_l;
    UWORD wait=0;
    UWORD uwWrAdsFram;
    
	for (DataSizeCnt = 0; DataSizeCnt < DLCMAX; DataSizeCnt++){ 
	     IIC_Start();
	     IIC_Data_Send(IIC_FRAM_WRITE_CODE);

         uwWrAdsFram = (EPMAX+DataSizeCnt) * 2;
         //address_h = (UBYTE)(0xff00 &(GROUP15+DataSizeCnt) >> 8);
         //address_l = (UBYTE)(0x00ff &(GROUP15+DataSizeCnt));
         address_h = (UBYTE)((0xff00 & uwWrAdsFram) >> 8);
         address_l = (UBYTE)( 0x00ff & uwWrAdsFram);
         
	     IIC_Data_Send(address_h);
	     IIC_Data_Send(address_l);
	
		 wrdata_h = (UBYTE)((0xff00 & DLCxx[DataSizeCnt]) >> 8);
		 wrdata_l = (UBYTE)(0x00ff & DLCxx[DataSizeCnt]);

		 
         //wrdata_h = (UBYTE)((0xff00 & 0) >> 8);
         //wrdata_l = (UBYTE)(0x00ff & 0);

		 IIC_Data_Send(wrdata_l);
        
		 IIC_Data_Send(wrdata_h);
	
         wait=0;
         while (RIIC1.ICSR2.BIT.TEND == 0){	//Timeout, Sean, 03/04/2010
		     wait++;
		     if(wait==65535){			    		
        	     Error = cF1_ERR;          // cF1 Write to EEPROM  Error, Sean, 03/04/2010		
        	     err_uwFRAMErrRd = 0x09;
			     break;
		     }
	     }
	IIC_Stop();
    }
    
    // 沒有這段, LV無法紀錄
    write_ep(0,MAX_FLOOR,pr[MAX_FLOOR]);
    write_ep(0,LEV_CUR,pr[LEV_CUR]);
    write_ep(0,PG_RST_MODE,pr[PG_RST_MODE]);
    write_ep(0,LAND_DLY_TIME,pr[LAND_DLY_TIME]);
    write_ep(0,LEV_LEN,pr[LEV_LEN]);
    write_ep(0,INV_POS_H,pr[INV_POS_H]);
    write_ep(0,INV_POS_L,pr[INV_POS_L]);
    write_ep(0,CUR_PG_H,pr[CUR_PG_H]);
    write_ep(0,CUR_PG_L,pr[CUR_PG_L]);
    write_ep(0,LEV_BRD_PG_H,pr[LEV_BRD_PG_H]);
    write_ep(0,LEV_BRD_PG_L,pr[LEV_BRD_PG_L]);
    write_ep(0,SENSOR_H,pr[SENSOR_H]);
    write_ep(0,SENSOR_L,pr[SENSOR_L]);
    write_ep(0,DLC_FUN,pr[DLC_FUN]);
    write_ep(0,PDO_TYPE,pr[PDO_TYPE]);
    write_ep(0,DS_LEN,pr[DS_LEN]);
    write_ep(0,RATIO,pr[RATIO]);
    write_ep(0,CAN_FUN,pr[CAN_FUN]); 
    //write_ep(0,POS_DDS_H,pr[POS_DDS_H]);  // JINGDO
    //write_ep(0,POS_DDS_L,pr[POS_DDS_L]);  // JINGDO
    //write_ep(0,POS_UDS_H,pr[POS_UDS_H]);  // JINGDO
    //write_ep(0,POS_UDS_L,pr[POS_UDS_L]);  // JINGDO
}

void frm_vdDLCRead(void){
  UWORD uwTemp;
  UBYTE rddata_l;
  UBYTE rddata_h;
  UWORD read_cnt;	

  err_uwFRAMErrRd = 0;
  
  for (read_cnt=0x00;read_cnt<DLCMAX;read_cnt++){

      //
  
      // [ Combine two bytes to one word // chiuju20110812
      rddata_l = IIC_PrRdStep1(EPMAX+read_cnt);
      rddata_h = IIC_PrRdStep2();

      //uwTemp = rddata_h;
      //uwTemp = uwTemp << 8;
      //uwTemp |= rddata_l;
      // ]

      DLCxx[read_cnt] = (UWORD)rddata_l + ((UWORD)rddata_h << 8);

  }

}


void DLC_PR_initial(void){
  UWORD i;
  
	if (pr[FLOOR_PAGE] == 0){  //prvalue = 0
	  for(i=0; i<DLC_25ADDR; i++){
	  	pr[FL_POSIT_1H+i]= DLCxx[i];
	  }
	}    
	else if(pr[FLOOR_PAGE] == 1){    //JINGDO   
	  for(i=DLC_25ADDR; i<DLC_50ADDR; i++){
	  	pr[FL_POSIT_1H+i-DLC_25ADDR]= DLCxx[i];
	  }
	}
	else if(pr[FLOOR_PAGE] == 2){    //JINGDO   
	  for(i=DLC_50ADDR; i<DLC_75ADDR; i++){
	  	pr[FL_POSIT_1H+i-DLC_50ADDR]= DLCxx[i];
	  } 
	}
    else if(pr[FLOOR_PAGE] == 3){    //JINGDO   
	  for(i=DLC_75ADDR; i<DLC_LimADDR; i++){
	  	pr[FL_POSIT_1H+i-DLC_75ADDR]= DLCxx[i];
	  } 
	}
  else if(pr[FLOOR_PAGE] == 4){		//[adjust floor position,Henry,2019/01/07]
      for(i=DLC_LimADDR; i<DLC_Adj50ADDRUP; i++){
          pr[FL_POSIT_1H+i-DLC_LimADDR]= DLCxx[i];
      }
  }  
  else if(pr[FLOOR_PAGE] == 5){		//[adjust floor position,Henry,2019/01/07]
      for(i=DLC_Adj50ADDRUP; i<DLC_Adj50ADDRDN; i++){
          pr[FL_POSIT_1H+i-DLC_Adj50ADDRUP]= DLCxx[(DLC_Adj50ADDRUP+i)];
      }
  }  
  else if(pr[FLOOR_PAGE] == 6){		//[adjust floor position,Henry,2019/01/07]
      for(i=DLC_Adj50ADDRDN; i<DLC_Adj5175ADDRUPDN; i++){
          pr[FL_POSIT_1H+i-DLC_Adj50ADDRDN]= DLCxx[i];
      }
  }
}



UBYTE IIC_PrRd4UserStep1(UWORD uwRdAds)    
{
    UWORD uwRdAdsFram;
    UBYTE rddata_l;
    UBYTE ubTemp;
    UWORD wait;


    uwRdAdsFram = 0xFFFF;
/*
  if (uwRdAds >= 0x1000) {
    err_uwNvsErrRd = 0x11;
    return (OFF);
  }
*/
  // [
    IIC_Start();
    if (Error != 0) {
        IIC_Stop();
        err_uwFRAMErrRd = 0x10;
  
    }
  
    IIC_Data_Send(IIC_FRAM_WRITE_CODE);
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x11;

    }
    // ]

  // [
    //uwRdAdsFram = (uwRdAds - 4096 )* 2; // FRAM is byte-unit,hence address * 2 for one word(two bytes)
     uwRdAdsFram = (uwRdAds * 2) + SECTION2_StAddr; // FRAM is byte-unit,hence address * 2 for one word(two bytes) 

    IIC_Data_Send((UBYTE)((uwRdAdsFram&0xff00)>>8));
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x12;
    }

    IIC_Data_Send((UBYTE)(uwRdAdsFram&0x00ff));
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x13;
    }
  // ]

  // [
    IIC_Stop();
    if (err_uwFRAMErrRd != 0) {
      err_uwFRAMErrRd = 0x14;
    }
  
    IIC_Start();
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x15;
    }
  
    IIC_DataSend4Read(IIC_FRAM_READ_CODE);
    if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x16;
    }
  
    RIIC1.ICMR3.BIT.WAIT = 1; // 0: No WAIT   1: WAIT
    RIIC1.ICMR3.BIT.ACKBT = 1; // Set NACK
  
    ubTemp = RIIC1.ICDRR; // Dummy read
  // ]

  // [
  wait = 0;
  while (RIIC1.ICSR2.BIT.RDRF == 0) {
      wait++;
      if(wait==65535){	
          IIC_Stop();
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
          err_uwFRAMErrRd = 0x17;
  	      break;
      }
  }

  //RIIC1.ICSR2.BIT.STOP = 0;
  RIIC1.ICSR2.BYTE &= 0xF7;
  RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition

  rddata_l = RIIC1.ICDRR; // Receive first data byte
  // ]

  RIIC1.ICMR3.BIT.WAIT = 0;

  wait = 0;
  //while (RIIC1.ICSR2.BIT.STOP == 0) { // Wait Stop Condition confirmed
  while ((RIIC1.ICSR2.BYTE & 0x08) == 0) {
      wait++;
      if(wait==65535){	
          IIC_Stop();
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
          err_uwFRAMErrRd = 0x18;
  	      break;
      }
  }

  RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
  //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
  RIIC1.ICSR2.BYTE &= 0xF7;
  return (rddata_l);
}

/*----------------------------------------------------------------------------*/
UBYTE IIC_PrRd4UserStep2(void) // chiuju20110812
{
  UBYTE rddata_h;
  UBYTE ubTemp;
  UWORD wait;


  // [
  IIC_Start();
  if (err_uwFRAMErrRd != 0) {
    IIC_Stop();
    err_uwFRAMErrRd = 0x21;
  }

  IIC_DataSend4Read(IIC_FRAM_READ_CODE);
  if (err_uwFRAMErrRd != 0) {
      IIC_Stop();
      err_uwFRAMErrRd = 0x22;
  }

  RIIC1.ICMR3.BIT.WAIT = 1; // 0: No WAIT   1: WAIT
  RIIC1.ICMR3.BIT.ACKBT = 1; // Set NACK

  ubTemp = RIIC1.ICDRR; // Dummy read
  // ]

  // [
  wait = 0;

  while (RIIC1.ICSR2.BIT.RDRF == 0) {
      wait++;
      if(wait==65535){	
          IIC_Stop();
          Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
          err_uwFRAMErrRd = 0x23;
          break;
      }
  }

  //RIIC1.ICSR2.BIT.STOP = 0;
  RIIC1.ICSR2.BYTE &= 0xF7;
  RIIC1.ICCR2.BIT.SP = 1; // Issue a stop condition

  rddata_h = RIIC1.ICDRR; // Receive last data byte
  // ]

  RIIC1.ICMR3.BIT.WAIT = 0;

  wait = 0;

  //while (RIIC1.ICSR2.BIT.STOP == 0) { // Wait Stop Condition confirmed
  while ((RIIC1.ICSR2.BYTE & 0x08) == 0) {
    wait++;
    if(wait==65535){	
        IIC_Stop();
        Error = cF1_ERR;              // cF1 Write to EEPROM  Error, Sean, 03/04/2010	
        err_uwFRAMErrRd = 0x24;
        break;
    }
  }

  RIIC1.ICSR2.BIT.NACKF = 0; // NACKF=0
  //RIIC1.ICSR2.BIT.STOP = 0; // STOP=0
  RIIC1.ICSR2.BYTE &= 0xF7;
  return (rddata_h);
}


#ifndef _PH_IIC_C
	#undef _PH_IIC_C
#endif
