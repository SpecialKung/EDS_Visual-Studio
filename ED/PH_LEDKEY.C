/*===============================================================
Author: Delta Electronic, INC. IABU, DEIN
                  
Project: VFD-VLI

Filename: PH_LEDKEY.C

Partner Filename: PH_LEDKEY.H

Description: This is a sample code.

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:

History:
===============================================================*/
#ifndef _LEDKEY_C
	#define _LEDKEY_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

const UBYTE chartab[16]={  //[for VD keypad, sampo, 10/27/2009]
	_0, _1, _2, _3, _4, _5, _6, _7,
	_8, _9, _A, _b, _C, _d, _E, _F
};


void KEY_IN(void)
{
   UBYTE i, keyc=0 ;

	for(i=1; i<9; i++) {
		KEYCLK = 1;	// KEYCLK= P9.6 (B6:74165_clk)
		//PORT9.PODR.BIT.B4 = 1;
		if(/*PORT9.PIDR.BIT.B5*/KEYDI == 0) {	// KEYDI=0 -> key pressed, KEYDI= P9.7(B5:data_in, *QH)
			keyc=keyc*8 + i;
		}
		KEYCLK = 0;	// one clock //
		//PORT9.PODR.BIT.B4 = 0;
	}

	if ( keyc ) {          		// keyc1!=0 -> key pressed
		if (keyc == keyin1) {		// keyc=keyin1 -> same key pressed
			if (KEYPRESS == 0) {    		// KEYPRESS=0, new key active
				if (keyc == keyinx){     	//repeat key
					if((KEY_ubDispMode>USER_PAGE2 && KEY_ubDispMode<MsgPAGE2) && (keyinx==UPKEY || keyinx==DOWNKEY)) {
						keyct0-- ;
						if (keyct0 == 0) {
							if(keyct1 > 1) {
								keyct1--;
							}
							if (keyct1 == 1) {
								keyct2-- ;
								if (keyct2 == 0){
									KEY_10x = 1;
								}
							}	// 10x up/down
							if ( KEY_10x ) {
								if ( !KEY_50x ) {
									keyct3-- ;
									if (keyct3 == 0){
								   		KEY_50x = 1;
								   	}
								}
							}
							keyct0 = keyct1;
							KEYPRESS = 1;
							keyinx = keyc;
						}  
					}     
				}        
				else {  // keyc!=keyinx -> non repeat key //
					KEYPRESS = 1;
					keyinx = keyc;
					KEY_uwPWRCnt = 5000;  // Initial Page, DINO, 06/01/2010
				}        
			}
		}
		else {     // keyc1=keyin1 -> new key pressed //
			keyin1 = keyc ;
			keyct0 = REPEATC0 ;
			keyct1 = REPEATC0 ;
			keyct2 = REPEATC1 ;
			keyct3 = REPEATC1 ;
			KEY_10x = 0;
			KEY_50x = 0;
		}
	}
	else {       // keyc==0 -> no key pressed //
		keyin1 = 0;
		keyinx = 0;
	}
}
void D1toD4_Display(void){
    //======  on board keypad D1~D4 ====== //    //[Added D1 to D4 on board display, Bernie, 2013/01/29]
      if((mfi_status&0x04)== 0x04){    // On board keypad D1
          led.s5 |= 0x08;
      }
      else{
          led.s5 &= 0xF7;
      }
      if((mfi_status&0x08)== 0x08){    // On board keypad D2
          led.s5 |= 0x40;
      }
      else{
          led.s5 &= 0xBF;
      }
      if((mfi_status&0x10)== 0x10){    // On board keypad D3
          led.s5 |= 0x10;
      }
      else{
          led.s5 &= 0xEF;
      }
      if((mfi_status&0x20)== 0x20){    // On board keypad D4
          led.s0 |= 0x01;
      }
      else{
          led.s0 &= 0xFE;
      }
      

}

void LED_MIMO_Display(void){

    //=========== MI Status =========== //    //[Added MI & MO on board display, Bernie, 2013/01/30]
    if((mfi_status&0x0004)== 0x0004){    // On board keypad MI1
        led.s0 |= 0x08;
    }
    else{
        led.s0 &= 0xF7;
    }
    if((mfi_status&0x0008)== 0x0008){    // On board keypad MI2
        led.s0 |= 0x80;
    }
    else{
        led.s0 &= 0x7F;
    }
    if((mfi_status&0x0010)== 0x0010){    // On board keypad MI3
        led.s0 |= 0x02;
    }
    else{
        led.s0 &= 0xFD;
    }
    if((mfi_status&0x0020)== 0x0020){    // On board keypad MI4
        led.s0 |= 0x20;
    }
    else{
        led.s0 &= 0xDF;
    }
    if((mfi_status&0x0040)== 0x0040){    // On board keypad MI5
        led.s1 |= 0x08;
    }
    else{
        led.s1 &= 0xF7;
    }
    if((mfi_status&0x0080)== 0x0080){    // On board keypad MI6
        led.s1 |= 0x80;
    }
    else{
        led.s1 &= 0x7F;
    }
    if((mfi_status&0x0100)== 0x0100){    // On board keypad MI7
        led.s1 |= 0x02;
    }
    else{
        led.s1 &= 0xFD;
    }
    if((mfi_status&0x0200)== 0x0200){    // On board keypad MI8
        led.s1 |= 0x20;
    }
    else{
        led.s1 &= 0xDF;
    }

    //=========== MO Status =========== //
    if((mfo_status&0x0001)== 0x0001){    // On board keypad RA/RC
        led.s2 &= 0xF7;
        led.s2 |= 0x08;
    }
    else{
        led.s2 &= 0x7F;
        led.s2 |= 0x80;
    }
    if((mfo_status&0x0002)== 0x0002){    // On board keypad MRA/MRC
        led.s2 &= 0xFD;
        led.s2 |= 0x02;
    }
    else{
        led.s2 &= 0xDF;
        led.s2 |= 0x20;
    }
    if((mfo_status&0x0004)== 0x0004){    // On board keypad R1A
        led.s4 |= 0x08;
    }
    else{
        led.s4 &= 0xF7;
    }
    if((mfo_status&0x0008)== 0x0008){    // On board keypad R2A
        led.s4 |= 0x80;
    }
    else{
        led.s4 &= 0x7F;
    }

}

void LED_OUT(void)
{
	UBYTE i ;
	UWORD_UNION transmit;


	transmit.uw = 0;
    
    D1toD4_Display();  //[Added D1 to D4 on board display, Bernie, 2013/01/29]

    
   
	/* ------ LED 7-segment Display & keyin function ------ */
	ledx++ ;
	if ( ledx == 6 ) { ledx = 0 ; }
		
#if 0 //[Mask MIOPAGE2,Lyabryan,2019/10/29]	
	if (KEY_ubDispMode==MIOPAGE2){	// add mi/mo page in led keypad, Sean, 05/04/2011
		led.s5 = _BLK;
	}
	else{
#if 0		
		if (lev_ubWelUpTri==1)
			led.s5 |= LED_D2;
		else
			led.s5 &= ~LED_D2;
				
		if (lev_ubWelDnTri==1)
			led.s0 |= LED_D4;
		else
			led.s0 &= ~LED_D4;	
			
		if ((gen_uwSta.uw&gen_uwSTASAFE)==gen_uwSTASAFE)
			led.s5 |= LED_D1;
		else
			led.s5 &= ~LED_D1;
			
		if ((gen_uwSta.uw&gen_uwSTADLK)==gen_uwSTADLK)
			led.s5 |= LED_D3;
		else
			led.s5 &= ~LED_D3;
#endif 
	}
#endif	

#if NEWIEDCB  // New IED Control Board, DINO, 06/25/2010
	switch (ledx) {
		case 0:
			transmit.ub.hi = 0x01;
			transmit.ub.low = led.s0;
			break;
		case 1:
			transmit.ub.hi = 0x02;
			transmit.ub.low = led.s1;
			break;
		case 2:
			transmit.ub.hi = 0x04;
			transmit.ub.low = led.s2;
			break;
		case 3:
			transmit.ub.hi = 0x10;
			transmit.ub.low = led.s3;
			break;
		case 4:
			transmit.ub.hi = 0x08;
			transmit.ub.low = led.s4;
			break;
		case 5:
			transmit.ub.hi = 0x20;
			transmit.ub.low = led.s5;
			break;
		default: ;
	}

	// send data to 74595
	for (i = 0; i<16; i++) {


		LEDCLK = 0 ;          // P9.3(B4) 74595_srclk
		//PORT9.PODR.BIT.B3 = 0;

		if ((transmit.uw & 0x8000) != 0){
			LEDDI = 1;          // P9.2(B3) 74595_ser(data_in)
			//PORT3.PODR.BIT.B2 = 1;
		}
		else{
			LEDDI = 0;
            //PORT3.PODR.BIT.B2 = 0;
        }
		transmit.uw = transmit.uw << 1  ;    // left shift
		LEDCLK = 1 ;          // B4(P9.3)
		//PORT9.PODR.BIT.B3 = 1;

	}

	LEDLCH = 0;             // B8(P9.5)=0 -> load keypad data //
	//PORT3.PODR.BIT.B3 = 0;
	LEDCLK = 0;
    //PORT9.PODR.BIT.B3 = 0;
	LEDLCH = 1;             // P9.5 Low to High, latch 74595 data //
	//PORT3.PODR.BIT.B3 = 1;
#else
   switch (ledx) {
      case 0:{
         transmit.ub.hi = 0x04;    // for 2003
         transmit.ub.low = led.s0;
      } break;
      case 1:{
         transmit.ub.hi = 0x08;    // for 2003
         transmit.ub.low = led.s1;
      } break;
      case 2:{
         transmit.ub.hi = 0x10;    // for 2003
         transmit.ub.low = led.s2;
      } break;
      case 3:{
         transmit.ub.hi = 0x01;    // for 2003
         transmit.ub.low = led.s3;
      } break;
      case 4:{
         transmit.ub.hi = 0x20;    // for 2003
         transmit.ub.low = led.s4;
      } break;
      case 5:{
         transmit.ub.hi = 0x02;    // for 2003
         transmit.ub.low = led.s5;
      } break;
      default: ;
   }

   // send data to 74595
   for (i = 0; i<16; i++) {

      LEDCLK = 0 ;          // P9.3(B4) 74595_srclk

      if ((transmit.uw & 0x8000) != 0)
         LEDDI = !1;          // P9.2(B3) 74595_ser(data_in)
      else
         LEDDI = !0;

      transmit.uw = transmit.uw << 1  ;    // left shift
      LEDCLK = 1 ;          // B4(P9.3)

   }

   LEDLCH = !0;             // B8(P9.5)=0 -> load keypad data //
   LEDCLK = 0;
   LEDLCH = !1;             // P9.5 Low to High, latch 74595 data //
#endif
}


/*-------- BCD to LED -----------------------------------
 -      LED4NOTE: Hint for special display flag         -
 -------------------------------------------------------*/
void LED_DecBcd(ULONG data, UBYTE unit)
{
	UWORD uwData, uwChar;


	if (data >= 10000){
		//uwChar = U32divU16(data, 10000);
        uwChar = data/10000;    //[Parameter display problem, Bernie, 2015/05/27]
		led.s4 = chartab[uwChar];
	}
	else{
		uwChar = 0;
		led.s4 = chartab[0];
	}
	uwData = data - (ULONG)uwChar * 10000;

	if (uwData >= 1000){
		uwChar = uwData / 1000;
		led.s3 = chartab[uwChar];
	}
	else{
		uwChar = 0;
		led.s3 = chartab[0];
	}
	uwData = uwData - uwChar * 1000;

	if (uwData >= 100){
		uwChar = uwData / 100;
		led.s2 = chartab[uwChar];
	}
	else{
		uwChar = 0;
		led.s2 = chartab[0];
	}
	uwData = uwData - uwChar * 100;

	if (uwData >= 10){
		uwChar = uwData / 10;
		led.s1 = chartab[uwChar];
	}
	else{
		uwChar = 0;
		led.s1 = chartab[0];
	}
	uwData = uwData - uwChar * 10;

	led.s0 = chartab[uwData];
    
   if (LED4NOTE) {	// has unit
       if (data > 9999) {      //[fix on board keypad display when Current over 100 , Bernie, 05/17/2012]
           dot-- ;
           //dot = dot-2;
           led.s0 = led.s1;
           led.s1 = led.s2;
           led.s2 = led.s3;
           led.s3 = led.s4;
       }
       if (data > 999){
          dot = dot-1;
          led.s0 = led.s1;
          led.s1 = led.s2;
          led.s2 = led.s3;
       }
      
       if ((led.s2 == _0)&&(dot!=2)) { led.s2 = _BLK; }
       led.s3 = _BLK;
       led.s4 = unit;
   }
   else {	// LED4NOTE=0
		if (data > 9999) {
			dot-- ;
			//dot=dot-2;
			led.s0 = led.s1;
			led.s1 = led.s2;
			led.s2 = led.s3;
			led.s3 = led.s4;
		}

		led.s4 = led.s3 ;

		if(led.s4 == _0) {
			if ((blinks<3) && (dot!=3)){
				led.s4 = _BLK;
				if ((led.s2==_0) && (dot!=2) && (blinks<2)){
					led.s2 = _BLK;
				}
			}
		}
		led.s3 = _BLK;
	}

	if(dot == 1)
		led.s1 |= _DOT;
	else if(dot == 2)
		led.s2 |= _DOT;
	else if(dot == 3)
		led.s4 |= _DOT;
	else if(dot == 0xff)
		led.s0 |= _DOT;
	else if(dot == 0xfe){
		led.s0 |= _DOT;
		led.s1 |= _DOT;
	}
}


/*-------- BCD to LED -----------------------------------
 -      LED4NOTE: Hint for special display flag         -
 -------------------------------------------------------*/
void LED_HexBcd(ULONG data, UBYTE unit)
{
	led.s0 = chartab[data&0x000f];
	led.s1 = chartab[(data&0x00f0)>>4];
	led.s2 = chartab[(data&0x0f00)>>8];
	led.s3 = _BLK;
	led.s4 = chartab[(data&0xf000)>>12];
	if ( LED4NOTE ) {
/*
		if (led.s2 == _0){
			led.s2 = _BLK;
		}
*/
		led.s4 = unit;
	}
/*
	else {
		if(led.s4 == _0) {
			led.s4 = _BLK;
			if ( (led.s2==_0) && (blinks<2) ){
				led.s2 = _BLK;
			}
		}
	}
*/
}


/*-------- BCD to LED -----------------------------------
 -      LED4NOTE: Hint for special display flag         -
 -------------------------------------------------------*/
void LED_BinBcd(ULONG data, UBYTE unit)
{
   led.s0 = chartab[data&0x0001];
   led.s1 = chartab[(data&0x0002)>>1];
   led.s2 = chartab[(data&0x0004)>>2];
   led.s3 = _BLK;
   led.s4 = chartab[(data&0x0008)>>3];

}


/*-------- IO Status to LED -----------------------------
 -      page: select IO status section			        -
 -------------------------------------------------------*/
void LED_MioBcd(UBYTE page)
{
   	ULONG_UNION ulDat;
   	UBYTE_UNION ubDat;
   	UWORD_UNION uwDat;
   
   	if (page<=KEY_MI_PAG3)
   		ulDat.ul = mio_ulMfiSta;
   	else
   		ulDat.ul = mfo_status;
   	
	switch(page){
		default:		
			break;
		case KEY_MI_PAG0:
			ubDat.ub = ulDat.ub.b0;
			break;
		case KEY_MI_PAG1:
			ubDat.ub = ulDat.ub.b1;
			break;
		case KEY_MI_PAG2:
			ubDat.ub = ulDat.ub.b2;
			break;			
		case KEY_MI_PAG3:
			ubDat.ub = ulDat.ub.b3;
			break;
		case KEY_MO_PAG0:
			ubDat.ub = ulDat.ub.b0;
			break;
		case KEY_MO_PAG1:
			ubDat.ub = ulDat.ub.b1;
			break;					
   	}
   	
   	if (page==KEY_MI_PAGA || page==KEY_MO_PAGA){
   		led.s0 = _BLK;
   		led.s1 = _BLK;
   		led.s2 = _BLK;
   		led.s4 = _BLK;
   		led.s0 = (ulDat.bit.b0)?(led.s0 | _IOB1):(led.s0 & ~_IOB1);
   		led.s0 = (ulDat.bit.b1)?(led.s0 | _IOB2):(led.s0 & ~_IOB2);
   		led.s0 = (ulDat.bit.b2)?(led.s0 | _IOB3):(led.s0 & ~_IOB3);  
   		led.s0 = (ulDat.bit.b3)?(led.s0 | _IOB4):(led.s0 & ~_IOB4);
   		led.s0 = (ulDat.bit.b4)?(led.s0 | _IOB5):(led.s0 & ~_IOB5);
   		led.s0 = (ulDat.bit.b5)?(led.s0 | _IOB6):(led.s0 & ~_IOB6);
   		led.s0 = (ulDat.bit.b6)?(led.s0 | _IOB7):(led.s0 & ~_IOB7);
   		led.s0 = (ulDat.bit.b7)?(led.s0 | _IOB8):(led.s0 & ~_IOB8);
   		led.s1 = (ulDat.bit.b8)?(led.s1 | _IOB1):(led.s1 & ~_IOB1);
   		led.s1 = (ulDat.bit.b9)?(led.s1 | _IOB2):(led.s1 & ~_IOB2);
   		led.s1 = (ulDat.bit.b10)?(led.s1 | _IOB3):(led.s1 & ~_IOB3);  
   		led.s1 = (ulDat.bit.b11)?(led.s1 | _IOB4):(led.s1 & ~_IOB4);
   		led.s1 = (ulDat.bit.b12)?(led.s1 | _IOB5):(led.s1 & ~_IOB5);
   		led.s1 = (ulDat.bit.b13)?(led.s1 | _IOB6):(led.s1 & ~_IOB6);
   		led.s1 = (ulDat.bit.b14)?(led.s1 | _IOB7):(led.s1 & ~_IOB7);
   		led.s1 = (ulDat.bit.b15)?(led.s1 | _IOB8):(led.s1 & ~_IOB8);
   		led.s2 = (ulDat.bit.b16)?(led.s2 | _IOB1):(led.s2 & ~_IOB1);
   		led.s2 = (ulDat.bit.b17)?(led.s2 | _IOB2):(led.s2 & ~_IOB2);
   		led.s2 = (ulDat.bit.b18)?(led.s2 | _IOB3):(led.s2 & ~_IOB3);  
   		led.s2 = (ulDat.bit.b19)?(led.s2 | _IOB4):(led.s2 & ~_IOB4);
   		led.s2 = (ulDat.bit.b20)?(led.s2 | _IOB5):(led.s2 & ~_IOB5);
   		led.s2 = (ulDat.bit.b21)?(led.s2 | _IOB6):(led.s2 & ~_IOB6);
   		led.s2 = (ulDat.bit.b22)?(led.s2 | _IOB7):(led.s2 & ~_IOB7);
   		led.s2 = (ulDat.bit.b23)?(led.s2 | _IOB8):(led.s2 & ~_IOB8);
   		led.s4 = (ulDat.bit.b24)?(led.s4 | _IOB1):(led.s4 & ~_IOB1); 
   		led.s4 = (ulDat.bit.b25)?(led.s4 | _IOB2):(led.s4 & ~_IOB2); 
   		led.s4 = (ulDat.bit.b26)?(led.s4 | _IOB3):(led.s4 & ~_IOB3); 
   		led.s4 = (ulDat.bit.b27)?(led.s4 | _IOB4):(led.s4 & ~_IOB4); 
   		led.s4 = (ulDat.bit.b28)?(led.s4 | _IOB5):(led.s4 & ~_IOB5); 
   		led.s4 = (ulDat.bit.b29)?(led.s4 | _IOB6):(led.s4 & ~_IOB6); 
   		led.s4 = (ulDat.bit.b30)?(led.s4 | _IOB7):(led.s4 & ~_IOB7); 
   		led.s4 = (ulDat.bit.b31)?(led.s4 | _IOB8):(led.s4 & ~_IOB8); 
  
	   	// add underline as notation for output   			
	   	if (page==KEY_MO_PAGA){
	   		led.s2 |= 0x04;
	   		led.s4 |= 0x04;
	   	}   			
   	}
   	else{
	   	if (ubDat.bit.b0!=0)	//digit 0
	   		if (ubDat.bit.b1!=0)
	   			led.s0 = _ONON;
	   		else
	   			led.s0 = _OFON;
	   	else
	   		if (ubDat.bit.b1!=0)
	   			led.s0 = _ONOF;
	   		else
	   			led.s0 = _OFOF;   	
	   			
	   	if (ubDat.bit.b2!=0)	//digit 1
	   		if (ubDat.bit.b3!=0)
	   			led.s1 = _ONON;
	   		else
	   			led.s1 = _OFON;
	   	else
	   		if (ubDat.bit.b3!=0)
	   			led.s1 = _ONOF;
	   		else
	   			led.s1 = _OFOF; 
	   			
	   	if (ubDat.bit.b4!=0)	//digit 2
	   		if (ubDat.bit.b5!=0)
	   			led.s2 = _ONON;
	   		else
	   			led.s2 = _OFON;
	   	else
	   		if (ubDat.bit.b5!=0)
	   			led.s2 = _ONOF;
	   		else
	   			led.s2 = _OFOF; 
	   			
	   	if (ubDat.bit.b6!=0)	//digit 3
	   		if (ubDat.bit.b7!=0)
	   			led.s4 = _ONON;
	   		else
	   			led.s4 = _OFON;
	   	else
	   		if (ubDat.bit.b7!=0)
	   			led.s4 = _ONOF;
	   		else
	   			led.s4 = _OFOF;    			   			   			
	   			
	   	// add underline as notation for output
	   	if (page==KEY_MO_PAG0 || page==KEY_MO_PAG1){
	   		led.s0 |= 0x04;
	   		led.s1 |= 0x04;
	   		led.s2 |= 0x04;
	   		led.s4 |= 0x04;
	   	}
	}	   	
	
	// dot setting
	switch(page){
		case KEY_MI_PAG0:
		case KEY_MO_PAG0:
			led.s0 |= _DOT;
			break;
		case KEY_MI_PAG1:
		case KEY_MO_PAG1:
			led.s1 |= _DOT;
			break;
		case KEY_MI_PAG2:
			led.s2 |= _DOT;
			break;			
		case KEY_MI_PAG3:
			led.s4 |= _DOT;
			break;
		case KEY_MI_PAGA:
		case KEY_MO_PAGA:
			break;
		default:				
			led.s0 &= ~_DOT;
			led.s1 &= ~_DOT;
			led.s2 &= ~_DOT;
			led.s4 &= ~_DOT;
			break;
	} 	
	led.s3 = _BLK;

}


/*-------- Blink 7 segment ------------------------------
 -      index from right to left: 0 ~ 4                 -
 -      x : index                                       -
 --------- Blink 7 segment -----------------------------*/
void blink_seg(UBYTE x)
{
	UBYTE ubBlink;

	if (Error!=0 || WarnCode!=0) {
		if ( !LEDBLINK ) {
			led.s0 = _BLK;
			led.s1 = _BLK;
			led.s2 = _BLK;
			led.s3 = _BLK;
			led.s4 = _BLK;
		}
	}
	else {
		if (KEY_ubDispMode == PU02SAVE2) {
			if (LEDBLINK == 0) {
				led.s0 = _BLK;
				led.s1 = _BLK;
				led.s2 = _BLK;
				led.s3 = _BLK;
				led.s4 = _BLK;
			}
		}
		else if (LEDBLINK==0 && (keyinx!=UPKEY && keyinx!=DOWNKEY)) { //(LEDBLINK=0)&&(non UP/DOWN key)
			// [ LED BLINK, DINO, 03/16/2010
	
			if (KEY_uwPrData>9999 && ((GetParAttr(relprno)&0x0060)==0)&& ((GetParAttr(relprno)&SIGN)==0)){  //[LED Keypad overflow, Bernie, 02/15/2016]
				ubBlink = x - 1;
			}
			else if((GetParAttr(relprno)&SIGN)==SIGN){   //[LED Keypad overflow, Bernie, 02/15/2016]
			    if(KEY_uwPrData>32767){
			        ubBlink = x;
			        if(ubBlink>3)
			            ubBlink = 3;
			    }
			    else{             //[LED Keypad overflow, Bernie, 02/15/2016]
			        ubBlink = x;
			    }
			}
			else{
				ubBlink = x;
			}
			switch(ubBlink) {
				case 0:
					led.s0 = _BLK;
					break;
				case 1:
					led.s1 = _BLK;
					break;
				case 2:
					led.s2 = _BLK;
					break;
				case 3:
					led.s4 = _BLK;
					break;
				default:
					break;
			}
			// ]
		}
		else {	// LEDBLINK=1 and UP/DOWN key
			switch(x) {
				case 4:
					if (led.s4 == _BLK)
						led.s4 = _0;
				case 3:
					if (led.s3 == _BLK)
						led.s3 = _0;
				case 2:
					if (led.s2 == _BLK)
						led.s2 = _0;
					break;
				default:
					break;
			}
		}
	}
}

void ErrorMSG(void)	// called by tb1_hex2bcd(), 25ms timebase
{
	LEDDATASEG ErrMsgLED;

#if 1
	// [ Change Error Code to saf_ubIedErr, DINO, 08/09/2010
	if ( Error ){

		led.s3 = _BLK;

		ErrMsgLED = ErrMSG[(Error-1)];
		led.s4 = ErrMsgLED.s4;
		led.s2 = ErrMsgLED.s2;
		led.s1 = ErrMsgLED.s1;
		led.s0 = ErrMsgLED.s0;
	}
	// ]
#else

	if ( Error ) {
		led.s4 = _BLK;
		led.s3 = _BLK;
		led.s2 = _BLK;
		led.s1 = _BLK;
		led.s0 = _BLK;

		switch(Error) {

			case ocA_ERR:
            	led.s0 = _A;
        		goto errdisp;
			case ocd_ERR:     
            	led.s0 = _d;
        		goto errdisp;
			case ocn_ERR:
            	led.s0 = _n;
        		goto errdisp;
			case occ_ERR:     
            	led.s0 = _c;
        		goto errdisp;
			case ocS_ERR:     
            	led.s0 = _S;
errdisp:
            	led.s2 = _o;
            	led.s1 = _c;
            	break;
			case GFF_ERR:     
            	led.s2 = _G;
            	led.s1 = _F;
            	led.s0 = _F;
            	break;
			case ovA_ERR:     
            	led.s0 = _A;
        		goto errovdisp;
			case ovd_ERR:     
            	led.s0 = _d;
        		goto errovdisp;
			case ovn_ERR:     
            	led.s0 = _n;
        		goto errovdisp;
			case ovS_ERR:     
            	led.s0 = _S;
errovdisp:
            	led.s2 = _o;
            	led.s1 = _Ubar;
            	break;
			case LvA_ERR:     
            	led.s0 = _A;
        		goto errlvdisp;
			case Lvd_ERR:     
            	led.s0 = _d;
        		goto errlvdisp;
			case Lvn_ERR:     
            	led.s0 = _n;
        		goto errlvdisp;
			case LvS_ERR:     
            	led.s0 = _S;
errlvdisp:
            	led.s2 = _L;
            	led.s1 = _Ubar;
            	break;
			case PHL_ERR:     
            	led.s2 = _P;
            	led.s1 = _H;
            	led.s0 = _L;
            	break;
			case oH1_ERR:     
            	led.s0 = _1;
        		goto errohdisp;
			case oH2_ERR:     
            	led.s0 = _2;
        		goto errohdisp;
			case oH3_ERR:
            	led.s0 = _3;
errohdisp:
            	led.s2 = _o;
            	led.s1 = _H;
            	break;
			case tH1o_ERR:
            	led.s1 = _1;
        		goto errthdisp;
			case tH2o_ERR:   
            	led.s1 = _2;
errthdisp:
            	led.s4 = _t;
            	led.s2 = _H;
            	led.s0 = _o;
            	break;
			case Fan_ERR:   
            	led.s2 = _F;
            	led.s1 = _A;
            	led.s0 = _n;
            	break;
			case oL_ERR:   
            	led.s1 = _o;
            	led.s0 = _L;
            	break;
			case EoL1_ERR:   
            	led.s0 = _1;
        		goto erreoldisp;
			case EoL2_ERR:   
            	led.s0 = _2;
erreoldisp:
            	led.s4 = _E;
            	led.s2 = _o;
            	led.s1 = _L;
            	break;
			case ot1_ERR:   
            	led.s0 = _1;
        		goto erreotdisp;
			case ot2_ERR:   
            	led.s0 = _2;
erreotdisp:
            	led.s2 = _o;
            	led.s1 = _t;
            	break;
			case cF1_ERR:   
            	led.s0 = _1;
        		goto errecfdisp;
			case cF2_ERR:   
            	led.s0 = _2;
errecfdisp:
            	led.s2 = _c;
            	led.s1 = _F;
            	break;
			case cd0_ERR:   
            	led.s0 = _0;
        		goto errecddisp;
			case cd1_ERR:   
            	led.s0 = _1;
        		goto errecddisp;
			case cd2_ERR:   
            	led.s0 = _2;
        		goto errecddisp;
			case cd3_ERR:   
            	led.s0 = _3;
errecddisp:
            	led.s2 = _c;
            	led.s1 = _d;
            	break;
			case Hd0_ERR:   
            	led.s0 = _0;
        		goto erreHddisp;
			case Hd1_ERR:   
            	led.s0 = _1;
        		goto erreHddisp;
			case Hd2_ERR:   
            	led.s0 = _2;
        		goto erreHddisp;
			case Hd3_ERR:   
            	led.s0 = _3;
erreHddisp:
            	led.s2 = _H;
            	led.s1 = _d;
            	break;
			case AuE_ERR:   
            	led.s2 = _A;
            	led.s1 = _U;
            	led.s0 = _E;
            	break;
			case PGF1_ERR:   
            	led.s0 = _1;
        		goto errePGFdisp;
			case PGF2_ERR:   
            	led.s0 = _2;
        		goto errePGFdisp;
			case PGF3_ERR:   
            	led.s0 = _3;
        		goto errePGFdisp;
			case PGF4_ERR:   
            	led.s0 = _4;
        		goto errePGFdisp;
			case PGF5_ERR:
            	led.s0 = _5;
errePGFdisp:
            	led.s1 = _F;
        		goto errePGdisp;
			case PGr1_ERR:   
            	led.s0 = _1;
            	led.s1 = _r;
        		goto errePGdisp;
			case PGr2_ERR:   
            	led.s0 = _2;
            	led.s1 = _r;
errePGdisp:
            	led.s4 = _P;
            	led.s2 = _G;
            	break;
			case EF1_ERR:   
            	led.s0 = _1;
			case EF_ERR:   
            	led.s2 = _E;
            	led.s1 = _F;
            	break;
			case PcodE_ERR:   
            	led.s4 = _P;
            	led.s2 = _c;
            	led.s1 = _d;
            	led.s0 = _E;
            	break;
			case cE1_ERR:   
            	led.s1 = _0;
            	led.s0 = _1;
        		goto erreCEdisp;
			case cE2_ERR:   
            	led.s1 = _0;
            	led.s0 = _2;
        		goto erreCEdisp;
			case cE3_ERR:   
            	led.s1 = _0;
            	led.s0 = _3;
        		goto erreCEdisp;
			case cE4_ERR:   
            	led.s1 = _0;
            	led.s0 = _4;
        		goto erreCEdisp;
			case cE10_ERR:   
            	led.s1 = _1;
            	led.s0 = _0;
erreCEdisp:
            	led.s4 = _C;
            	led.s2 = _E;
            	break;
			case cP10_ERR:   
            	led.s4 = _C;
            	led.s2 = _P;
            	led.s1 = _1;
            	led.s0 = _0;
            	break;
			case bF_ERR:   
				led.s2 = _b;
				led.s1 = _F;
				break;
			case SRY_ERR:   
				led.s2 = _S;
				led.s1 = _r;
				led.s0 = _y;
				break;
			case MbF_ERR:	
				led.s2 = _M;
				led.s1 = _b;
				led.s0 = _F;
				break;
			case MCF_ERR:	
				led.s2 = _M;
				led.s1 = _C;
				led.s0 = _F;
				break;
			case MPHL_ERR:
				led.s4 = _M;
				led.s2 = _P;
				led.s1 = _H;
				led.s0 = _L;
				break;
/*
			case ccodE_ERR:   
			case ydc_ERR:   
			case DEB_ERR:   
			case bb_ERR:   
			case ACE_ERR:   
			case AFE_ERR:   
			case FuSE_ERR:   
			case uc1_ERR:   
			case uc2_ERR:   
*/
			default:	// Error
            	led.s2 = _E;
            	led.s1 = _r;
            	led.s0 = _r;
				break;
		}
	}
#endif
}

//-----------------------------------------------------------------
// Increase Pr Group No.					  -
// -      prno: Pr No.                                            -
// -      grno: Group No.                                         -
//-----------------------------------------------------------------
void incgrno(void)
{
	UBYTE gx;

//	prno = 0;
	grno++;
	if (SHOW_ALLPR){
		gx = 16;
	}
	else if(SHOW_ENHANCE){
		gx = 15;
	}
	else
	   gx = 14;

	if (grno >= gx){
		grno = 0;
	}
	prno = KEY_ubPrno[grno];  // Initial Page, DINO, 06/01/2010
}


//-----------------------------------------------------------------
// Decrease Pr Group No.					                      -
// -      prno: Pr No.                                            -
// -      grno: Group No.                                         -
//-----------------------------------------------------------------
void decgrno(void)
{
	UBYTE gx;

	if (SHOW_ALLPR){
		gx = 16;
	}
	else if(SHOW_ENHANCE){
		gx = 15;
	}
	else
	   gx = 14;
	   
	grno-- ;
	if (grno == 0xff){
		grno = gx - 1;
	}

	// [ Initial Page, DINO, 06/01/2010
	prno = KEY_ubPrno[grno];
	// ]
}


//---------------------------------------------------------------------------
// Key Program Function
//---------------------------------------------------------------------------
void key_prog(void)     // called by main.c; main subroutine
{
    UBYTE gpno;
	UWORD key_uwCnt, uwAttr, bx, ubMon;
	UWORD ax;
	SWORD cx;
	UWORD pr_limit;
    UWORD uwParAdr,uwParAdr_grno,uwParAdr_prno; //[13Grop modify,Lyabryan,2016/07/19]
	if ( KEYPRESS ) {
		KEYPRESS = 0 ;
		
		switch(keyinx) {

         case MODEKEY:

            if ( COPYRIGHT ) { COPYRIGHT = 0 ; }	// Clear copyright message



			if (KEY_ubDispMode == ErrPAGE2){
				KEY_ubDispTmp = ErrPAGE2;
				KEY_ubDispMode = pr[S_DISP];
			}
			else if (KEY_ubDispMode == WarnPAGE2){
				KEY_ubWarnTmp = WarnPAGE2;
				KEY_ubDispMode = pr[S_DISP];
			}
            else {
				if (KEY_ubDispMode < USER_PAGE2){		// F,H,V,A,E,User
                	KEY_ubDispMode++;
                    //if(KEY_ubDispMode == MIOPAGE2)
                      //KEY_ubDispMode ++;                //[User page for LED Keyboard, Bernie, 08/05/2011]
                	if (KEY_ubDispMode == USER_PAGE2){
                		//KEY_ubDispMode = F_PAGE2;
                		spdispx = pr[U_DISP];           //[User page for LED Keyboard, Bernie, 08/05/2011]
                	}
					//if (KEY_ubDispMode!=MIOPAGE2){	//reset sub-page // add mi/mo page in led keypad, Sean, 05/04/2011
						//KEY_MioPag = KEY_MI_PAGA;
					//}                	
                }
                else if (KEY_ubDispMode == USER_PAGE2)  //[User page for LED Keyboard, Bernie, 08/05/2011]
                    KEY_ubDispMode = F_PAGE2;
				else if (KEY_ubDispMode == RECENTPG) {
                    GPMODE = 0;
                    KEY_ubDispMode = F_PAGE2;
				}
/*  Delete by DINO, 03/23/2010
				if ( KEY_ubDispMode == USER_PAGE2)	// User page
					spdispx = pr[U_DISP];
*/
               	if (KEY_ubDispMode==GrPAGE2 || KEY_ubDispMode==pr[S_DISP]){		//  Gx- page (Group Index page)
                	if (Error != 0){
                    	KEY_ubDispMode = ErrPAGE2 ;
                  	}
                  	else if (WarnCode != 0){
                    	KEY_ubDispMode = WarnPAGE2;
                  	}
                  	else {
                    	KEY_ubDispMode = pr[S_DISP];
//                     	blinks = blinkf;
                  	}
					
				}
				else if (KEY_ubDispMode == FunPAGE2)	// Gx-Fx
					KEY_ubDispMode = GrPAGE2;
				else if (GPMODE==0&&(KEY_ubDispMode == DataPAGE2))	// data page
					KEY_ubDispMode = FunPAGE2 ;
                else if (GPMODE==1&&(KEY_ubDispMode == DataPAGE2))
					KEY_ubDispMode = RECENTPG;
            }
			
			break;
#if NEWIEDCB	// New IED Control Board, DINO, 06/25/2010
			case STOPKEY:

                rst_det = 1;	// reset key detecting and excuting, Sean, 08/19/2010
                if(Error == CAN_ERR){
                    InitCAN();
                    //Error = 0;
                    uwPDO_CNT = 0;      //[claer state when Error occur ,Bernie, 2015/05/12]
                    ubPDO_TxCNT = 0;    //[claer state when Error occur ,Bernie, 2015/05/12]
                    RCAN_RX_Count = 0;  //[claer state when Error occur ,Bernie, 2015/05/12]
                    CAN_uwErrNo = 0;    //[claer state when Error occur ,Bernie, 2015/05/12]
                    CAN_status.uw = 0;  //[claer state when Error occur ,Bernie, 2015/05/12]
                }    

				if ( Error ) {
					reset();
				}
				else if (WarnCode==SE1_WARN || WarnCode==SE2_WARN || WarnCode==SE3_WARN){
            		WarnCode = 0;      
       	    		Keypad_Page = Keypad_PageTmp;
				}
/*
				else { // Error==0)
				   if ( (OPKEY_LOCK|MFI_EXTOP) == 0 ) {
				      if ( MFI_KPADOP || ( (opc_source&0x01)==1 ) || opc_source==0 ) {
				     HOLDPU = 1 ;  // stop the door by PU, dino, 20050202
				         stop(1);
				      }
				   }
				   if ( keyct1==6 ) { STOPDCI = 0;    dci_ct = 0 ; }  // keyct1==(REPEATC0>>1)
				}
*/
				break;
#endif
/*
         case RUNKEY:{
            if ( !OPKEY_LOCK && !EN2PLC ) {	// source of operation control
               HOLDPU = 0 ;
               if ( (PUEN|MFI_EXTOP)==0 && ( !CMDJOG && ( opc_source==0 || MFI_KPADOP ) ) ) {
                  if ( RUNNING == STOP ) {
 	             if ( CMDDIR == FORWARD ) { DC = 1; }
	             else { DT = 1; }
	             FCHG = 1;
                  }
                  run();
               }
            }
         } break;
*/
			case SHIFTKEY:
				
            	if(KEY_ubDispMode == F_PAGE2) {		// F page
               		blinkf ++ ;
               		if (blinkf == 5){
               			blinkf = 0;
               		}
//               		blinks = blinkf;
            	}
/*
            	else if (KEY_ubDispMode == U_PAGE2) {	// user define
               		blinku++ ;
               		if ( blinku == 5 ) {
               			blinku = 0;
               		}
               		blinks = blinku ;
            	}
*/
            	else if (KEY_ubDispMode == USER_PAGE2){		// user page
               		spdispx++ ;
               		if (spdispx > MFDPAGEMAX){
               			spdispx = 0;
               		}
            	}
            	else if (KEY_ubDispMode == DataPAGE2){	// data page
#if 0            	
					// [ Time Display, DINO, 08/16/2010
            		if (relprno==RTM_HOURMIN || relprno==RTM_MONDAY) 
            			blinks += 2;
            		else
               			blinks++;
               		// ]
#endif
                    if((GetParAttr(relprno)&SIGN)==0){      //[LED Keypad overflow, Bernie, 02/15/2016]
					    blinks ++;		//[LED Keypad Direction Key, Bernie, 08/04/2011]
					}
					else{                                   //[LED Keypad overflow, Bernie, 02/15/2016]
					    blinks ++;
					    if(KEY_uwPrData>32767){   
					         if(blinks>2){
					             blinks = 0;
					         }
					    }
					}
               		// [ LED BLINK, DINO, 03/16/2010
					if (KEY_uwPrData>9999 && (GetParAttr(relprno)&(DPB|DPH))==0){
						ax = 5;
					}
					else{
						ax = 4;
					}
               		if (blinks == ax){
               			blinks = 0;    
               		}
               		// ]
//#endif
            	}
            	/* //[Mask MIOPAGE2,Lyabryan,2019/10/29]	
            	else if (KEY_ubDispMode == MIOPAGE2){	// add mi/mo page in led keypad, Sean, 05/04/2011
            		if (KEY_MioPag >= KEY_MO_PAG1)
            			KEY_MioPag = KEY_MI_PAGA;
            		else
            			KEY_MioPag++;
            	}
                */ //]
         		break;
/*
         case JOGKEY:{
            if ( (OPKEY_LOCK==0) && (Error==0) ) {
               if ( (opc_source<3) && !PUEN ) {	 // not PU control
                  if ( !RUNNING || CMDJOG ) {
                     HOLDPU = 0;    CMDJOG = 1;    run();    led.s5 |= 0x04;	// jog(b2)=1
                  }
               }
            }
         } break;
*/
			case UPKEY:
				if (KEY_ubDispMode == GrPAGE2)        // Gn-
               		incgrno();
                else if(KEY_ubDispMode == RECENTPG){
                    recent_pr++;
                    if(recent_pr>99)
                        recent_pr = 50;
                }
            	else if (KEY_ubDispMode == FunPAGE2){       // Gn-Fx
                  	prno++ ;
                  	// [ Enhance Parameter, DINO, 12/15/2010
                  	 //(pr[PRRESET]==3 || SHOW_ALLPR==1){
                  	 
                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                        gpno = pr_gpno_Sibo[grno];
                    else
                        gpno = pr_gpno[grno];
                    
                  		if (prno >= gpno){
                  			prno = 0;
                  		}
				//	}
                  //	else{
                  	//	if (prno >= pr_gpno_IED[grno]){
                  			//prno = 0;
                  		//}
					//}
					// ]
				}
				else if (KEY_ubDispMode == DataPAGE2){
					
					if((OPKEY_LOCK==0)||(relprno==PRRESET)){
				    	pr_limit = (ULONG)GetParMax(relprno);  // DINO, 03/22/2010

				    	//if (KEY_uwPrData < pr_limit){
		
                            uwAttr = GetParAttr(relprno);
                            if ((uwAttr&0x0060) == DPB) {
                                ax = 0x0001 << blinks;
                            }
                            else if ((uwAttr&0x0060) == DPH){
                                ax = 0x0001 << (blinks << 2);
                            }
                            else {
//                              if ( KEY_uwPrData > 9999 ) { blinks = 1 ; }
                                key_uwCnt = 1 + 9 * KEY_10x + 40 * KEY_50x ;
                                if      (blinks == 0) {ax= key_uwCnt; }
                                else if (blinks == 1) {ax= 10 * key_uwCnt; }
                                else if (blinks == 2) {ax= 100 * key_uwCnt; }
                                else if (blinks == 3) {ax= 1000 * key_uwCnt; }
                                else if (blinks == 4) {ax= 10000 * key_uwCnt; }	// range

                             }
                             
                             if ((uwAttr&SIGN) != SIGN){          //[LED Keypad overflow, Bernie, 02/15/2016]
                                 ax += KEY_uwPrData ;	// if ax<=KEY_uwPrData ->data overflow
                                 if (ax>=pr_limit || ax<=KEY_uwPrData){
                                     KEY_uwPrData = pr_limit;
                                 }
                                 else {
                                     KEY_uwPrData = ax;
                                 }
                             }
                             else{                          //[LED Keypad overflow, Bernie, 02/15/2016]
                                 if((SWORD)KEY_uwPrData<=0){
                                     cx = KEY_uwPrData + ax;
                                     KEY_uwPrData = cx;
                                 }
                                 else{
                                     ax = KEY_uwPrData + ax;
                                     if(ax > pr_limit)
    				        			KEY_uwPrData = pr_limit;
    				        		 else
    				        			KEY_uwPrData = ax;
                                 }
                             }
//				    		}
                        //}
                    }
                }
                break;

			case DOWNKEY:
				if (KEY_ubDispMode == GrPAGE2){
//					prno = 0;  // Initial Page, DINO, 06/01/2010
					decgrno();
				}
                else if(KEY_ubDispMode == RECENTPG){
                    recent_pr--;
                    if(recent_pr<50)
                        recent_pr = 99;
				}
				else if (KEY_ubDispMode == FunPAGE2){
					prno-- ;
                    if(SIBO_PARAMETER) //[Group12&13 Limit count,Lyabryan,2020/09/10]
                        gpno = pr_gpno_Sibo[grno];
                    else
                        gpno = pr_gpno[grno];
					if (prno == 0xff) {
                        
                         
                        
						// [ Enhance Parameter, DINO, 12/15/2010
						//if (pr[PRRESET]==3 || SHOW_ALLPR==1)
							prno = gpno - 1;
						//else
						//	prno = pr_gpno_IED[grno] - 1;
						// ]
					}
                    else if(prno>gpno){
                        prno = gpno - 1;
                    }
				}
				else if (KEY_ubDispMode == DataPAGE2){
//#if 0 
					if(OPKEY_LOCK==0  || relprno==PRRESET){

				    	pr_limit = (ULONG)GetParMin(relprno);  // DINO, 03/22/2010


				      		uwAttr = GetParAttr(relprno);
							if ((uwAttr&0x0060) == DPB){
					   			ax = 0x0001 << blinks;
							}
							else if ((uwAttr&0x0060) == DPH){
					   			ax = 0x0001 << (blinks << 2);
							}
							else {
//					   			if ( KEY_uwPrData == 10000 ) { blinks = 0 ; }
					   			key_uwCnt = 1 + 9 * KEY_10x + 40 * KEY_50x ;
				        		if		(blinks == 0 ) { ax = key_uwCnt ; }
				        		else if (blinks == 1 ) { ax = 10 * key_uwCnt ; }
				        		else if (blinks == 2 ) { ax = 100 * key_uwCnt ; }
				        		else if (blinks == 3 ) { ax = 1000 * key_uwCnt ; }
				        		else if (blinks == 4 ) { ax = 10000 * key_uwCnt ; }
				        	}

				        	if ((uwAttr&SIGN) != SIGN){       //[LED Keypad overflow, Bernie, 02/15/2016]
				        	    ax = KEY_uwPrData - ax;

    				        	if(ax>=KEY_uwPrData)
    				        		KEY_uwPrData = pr_limit;
    				        	else {
    				        		if(ax > pr_limit)
    				        			KEY_uwPrData = ax;
    				        		else
    				        			KEY_uwPrData = pr_limit;
    				        	}
                            }
                            else{                            //[LED Keypad overflow, Bernie, 02/15/2016]
                                if((SWORD)KEY_uwPrData<=0){
                                cx = KEY_uwPrData - ax;
    				        		//KEY_uwPrData = ax;
    				        		if((SWORD)cx <= (SWORD)pr_limit)
    				        			KEY_uwPrData = (SWORD)pr_limit;
    				        		else
    				        			KEY_uwPrData = cx;
    				            }
    				        	else {
    				        	    ax = KEY_uwPrData - ax;
    				        	    KEY_uwPrData = ax;
    				        	}
                                
                            }
				        	
				        	// [ LED BLINK, DINO, 03/16/2010
							if ((uwAttr&0x0060) == DPB){
				        		if (blinks == 3){
				        			if (KEY_uwPrData < 0x0008){
				        				blinks = 2;
				        			}
				        		}
				        		if (blinks == 2){
				        			if (KEY_uwPrData < 0x0004){
				        				blinks = 1;
				        			}
				        		}
				        		if (blinks == 1){
				        			if (KEY_uwPrData < 0x0002){
				        				blinks = 0;
				        			}
				        		}
							}
							else if ((uwAttr&0x0060) == DPH){
				        		if (blinks == 3){
				        			if (KEY_uwPrData < 0x1000){
				        				blinks = 2;
				        			}
				        		}
				        		if (blinks == 2){
				        			if (KEY_uwPrData < 0x0100){
				        				blinks = 1;
				        			}
				        		}
				        		if (blinks == 1){
				        			if (KEY_uwPrData < 0x0010){
				        				blinks = 0;
				        			}
				        		}
							}
							else {
				        		if (blinks == 4){
				        			if (KEY_uwPrData < 10000){
				        				blinks = 3;
				        			}
				        		}
				        		if (blinks == 3){
				        			if (KEY_uwPrData < 1000){
				        				blinks = 2;
				        			}
				        		}
				        		if (blinks == 2){
				        			if (KEY_uwPrData < 100){
				        				blinks = 1;
				        			}
				        		}
				        		if (blinks == 1){
				        			if (KEY_uwPrData < 10){
				        				blinks = 0;
				        			}
				        		}
				        	}
				        	// ]
				        //}
					}
//#endif
				}
				break;

			case PROGKEY:
            	if(KEY_ubDispMode < GrPAGE2){
            		KEY_ubDispMode = GrPAGE2;
            	}
            	else if(KEY_ubDispMode == GrPAGE2){
					KEY_ubDispMode = FunPAGE2;
            	}
                else if(KEY_ubDispMode == RECENTPG){
                    relprno = prtab[recent_no/100]+(recent_no%100);
                    uwAttr = GetParAttr(relprno);
                    KEY_uwPrData = GetParData(relprno);  // DINO, 03/22/2010
               		KEY_ubDispMode = DataPAGE2;
					if ((uwAttr&0x0060) == 0){  //decimal
						if (KEY_uwPrData > 9999){
							blinks = 1;
						}
	       				else{
                  			blinks = 0;
                  		}
                  	}
                  	else{
                  		blinks = 0;
                  	}
                }
            	else if(KEY_ubDispMode ==FunPAGE2){
               		relprno = prtab[grno] + prno ;
               		/*if ( MFI_PRLOCK ){
               			KEY_uwPrData = 0;
               		}
               		else */
               		
                    if(grno==13){ //[ //[13Grop modify,Lyabryan,2016/07/19]
                        uwParAdr = pr[prtab[grno-1] + prno];
                        uwParAdr_grno = uwParAdr/100;
                        uwParAdr_prno = uwParAdr%100;
                        relprno = prtab[uwParAdr_grno] + uwParAdr_prno;
                        //uwParData = uwParData_Group13;
                    }//] //[13Grop modify,Lyabryan,2016/07/19]
                    uwAttr = GetParAttr(relprno);
                    KEY_uwPrData = GetParData(relprno);  // DINO, 03/22/2010
               		KEY_ubDispMode = DataPAGE2;
					// [ LED BLINK, DINO, 03/16/2010
					if ((uwAttr&0x0060) == 0){  //decimal
						if (KEY_uwPrData > 9999){
							blinks = 1;
						}
	       				else{
                  			blinks = 0;
                  		}
                  	}
                  	else{
                  		blinks = 0;
                  	}
                  	// ]
            	}
            	else if(KEY_ubDispMode == DataPAGE2){  // pr DATA ENTER
					endct = DLY4END ;
					KEY_ubDispMode = MsgPAGE2;
					if ( OPKEY_LOCK ){
						if (relprno == PRRESET){
							write_pr(relprno, KEY_uwPrData);
						}
						else{
							KEYEND = ERR;
						}
					}
					else{
						write_pr(relprno, KEY_uwPrData);
					}
				}
				else if(KEY_ubDispMode == ErrPAGE2){  // error page
					if (Error == EF_ERR) {
				    	disptemp = KEY_ubDispMode;
						KEY_ubDispMode = GrPAGE2;        // group page, 6-->5 (02112004)
					}
				}
				break ;

/*
			case PROGKEY*8+SHIFTKEY:	// current calibration page
			case SHIFTKEY*8+PROGKEY:
				if ( SHOW_ALLPR ){
					if (KEY_ubDispMode^12){
						KEY_ubDispMode = 12;
						blinks = 0;
					}
				}
				break;

			case UPKEY*8+DOWNKEY:
			case DOWNKEY*8+UPKEY:
				if (Error == CF2_ERR){
					KEY_ubDispMode = 0;
					Error = 0;
				}
				break;
*/
            case RECENT_KEY:
            	if(KEY_ubDispMode < GrPAGE2){
            		KEY_ubDispMode = RECENTPG;
                    GPMODE = 1;
                    recent_pr = 99;
            	}

            break;
			default:
				break;
		}  // end of switch(keyinx)
	
	
	}
/*
	else {     // KEYPRESS=0
		if( CMDRUN==RUN && CMDJOG && keyinx!=JOGKEY && !MFI_JOG && !REM_JOG ){ stop(1); }	// JOG Stop
	}
*/

}


void Update_LEDKeyDisp(void)	// called by 40ms time base
{
	UBYTE unit;
    UBYTE ubgr_10,ubgr_1,ubpr_10,ubpr_1;
	UWORD uwAttr,uwParData;
	UWORD uwFkey,uwFout;
	ULONG_UNION showdata;
    UWORD uwParAdr,uwParAdr_grno,uwParAdr_prno; //[13Grop modify,Lyabryan,2016/07/19]
	LED4NOTE = 0;
	dot = 0;

	unit = KEY_ubDispMode;



	// [ DISPLAY is invalid during Save, DINO, 03/16/2010
	if (COPYEN){
		KEY_ubDispMode = PU02SAVE2;
	}
	else{
		KEY_ubDispMode = unit;
	}
	// ]

	if ( COPYRIGHT ) {	// show "dELtA"
		led.s4 = _d;
		led.s3 = _BLK;
		led.s2 = _E;
		led.s1 = _L;
		led.s0 = _t;
	}
	else {
		switch(KEY_ubDispMode) {
			case F_PAGE2: 	//  F xxx.xx
				if (pr[U_SET]==0){
					LED4NOTE = 1;	
					unit = _F;	// F xx.xx
					if (C21xx[0x02] < 10000){  // DINO, 03/22/2010
						dot = 2;
						showdata.ul = C21xx[0x02];
					}
					else {
						dot = 1 ;
						showdata.ul = C21xx[0x02] / 10 ;
					}
					//if (pr[UNITSEL] == 3){  // RPM Display    //that is masked by Bernie
						//LED4NOTE = 0;
						//dot = 0;
					//}
				}
				else{
			    	dot = KPDdot;
		        	showdata.ul = U16xU16divU16(KPDmax, fkey.uw.hi, pr[FMAX]);
				}
				LED_DecBcd(showdata.ul, unit);
				break;
			case H_PAGE2:	// H xxx.xx
				LED4NOTE = 1;
				unit = _H;        // H xx.xx
          		if (C21xx[0x03] < 10000){
             		dot = 2;
             		showdata.ul = C21xx[0x03];
          		}
				else{
					dot = 1;
					showdata.ul = C21xx[0x03] / 10;
				}
				//if (pr[U_SET]==0){
					//if (pr[UNITSEL] == 3){
						//LED4NOTE = 0;
						//dot = 0;
					//}
				//}
				//else{
					//dot = KPDdot;
				//}
				LED_DecBcd(showdata.ul , unit);
				break;
/*
			case 2:{	// User scale: Fcmd*pr[FSCALE]   ???
//				led.s5 = led.s5 | 0x80;       // U indicator
          LED4NOTE = 1;
          unit = CHAR_U;        // U xx.xx
          if(disp_userdef.ul >=100000000L){
             dot = 0xff;
             showdata.ul = xdivuz(disp_userdef.ul, 1000);
             showdata.ul = xdivuz(showdata.ul, 100);
          }
          else if(disp_userdef.ul >=10000000L){
             showdata.ul = xdivuz(disp_userdef.ul, 10000);
          }
          else if(disp_userdef.ul >=1000000L){
             dot = 1;
             showdata.ul = xdivuz(disp_userdef.ul, 1000);
          }
          else {
             dot = 2;
             showdata.ul = xdivuz(disp_userdef.ul, 100);
          }
          LED_DecBcd(showdata.ul , unit);
        } break;
*/
			case U_PAGE2:	// /u (u bar)  DC Bus
			  	LED4NOTE=1;
			  	unit = _Ubar;     // u*
			  	dot = 1;
			  	showdata.ul = DcbusDCLPF.sw.hi;
			  	LED_DecBcd(showdata.ul, unit);
				break;
			case A_PAGE2:	// A. Irms by Iu, Iw
				LED4NOTE = 1;
				unit = _A;        // A
				dot = 2 ;
                if(CC4KeyPad){                         //[CC Display, Bernie, 2017/04/12]
                     showdata.ul = pr[I_RATE2]*9/5;
                }
                else{
				    showdata.ul = IrmsReLPF.sw.hi;
                }
				LED_DecBcd(showdata.ul , unit);
				break;
          	case E_PAGE2:	// E  AC Output Voltage
          	  	LED4NOTE=1;
          	  	unit = _E;        // E
          	  	dot = 1;
          	  	showdata.ul = VcmdLLPF.sw.hi;
          	  	LED_DecBcd(showdata.ul, unit);
          		break;
            /* //[ //[Mask MIOPAGE2,Lyabryan,2019/10/29]
			case MIOPAGE2:	// Multi-Fun Input/Output Status	// add mi/mo page in led keypad, Sean, 05/04/2011
				LED_MioBcd(KEY_MioPag);
				break;
            */ //] //[Mask MIOPAGE2,Lyabryan,2019/10/29]
			case USER_PAGE2:	// User define: ref to 00-04    E, n, P, H.U. .....
          		switch (spdispx) {
          		  	default:
          		  	case 0:	// A. Irms by Iu, Iw
          		  	  	dot = 2 ;
          		  	  	LED4NOTE = 1;
          		  	  	unit = _A;        // A
          		  	  	if(CC4KeyPad){                     //[CC Display, Bernie, 2017/04/12]
                            showdata.ul = pr[I_RATE2]*9/5;
                        }
                        else{
          		  	  	    showdata.ul = IrmsReLPF.sw.hi;
                        }
          		  	  	LED_DecBcd(showdata.ul , unit);
          		  		break;
          		  	case 1:	// c  Counter
/* //[Mask By Bernie, 08/08/2011 ]  
          		  	  	LED4NOTE = 1;
          		  	  	unit = _c;        // c
          		  	  	showdata.ul = 0;
          		  	  	LED_DecBcd(showdata.ul , unit);
*/
                        spdispx++;              //[User page for LED Keyboard, Bernie, 08/05/2011]
          		  		break;
          		  	case 2:	//  s.tttt: step, timer of PLC
          		  	  	LED4NOTE=1;
          		  	  	unit = _H;	// 0x01 is decimal point
          		  	  	showdata.ul = uwAbsMotorHz;
          		  	  	dot = 2;
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 3:	// /u (u bar)  DC Bus
          		  	  	LED4NOTE=1;
          		  	  	unit = _Ubar;     // u*
          		  	  	dot = 1;
          		  	  	showdata.ul = DcbusDCLPF.sw.hi;
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 4:	// E  AC Output Voltage
          		  	  	LED4NOTE=1;
          		  	  	unit = _E;        // E
          		  	  	dot = 1;
          		  	  	showdata.ul = VcmdLLPF.sw.hi;
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 5:	//  d: Power factor angle
          		  	  	LED4NOTE = 1;
          		  	  	unit = _n;
          		  	  	dot = 1 ;
          		  	  	showdata.ul = PF_ANGLE;
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	
          		  	case 6:	// Power (W) signed data,  +/-
          		  		LED4NOTE = 1;
          		  	  	unit = _P;                 // P
          		  	  	dot = 2;
          		  		if ((Pinput.uw.hi&0x8000) == 0){
          		  	  		showdata.ul = Pinput.uw.hi;
          		  	  	}
          		  	  	else{
          		  	  		//showdata.ul = -Pinput.uw.hi;
                            showdata.ul = (abs(Pinput.ul))>>16;
          		  			unit = _NEG;
          		  	  	}
         		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 7:	// Wr: rpm
          		  	    LED4NOTE = 1;
                        unit = _r;      // r                 //[Uniform char, Bernie, 08/05/2011]
          		  		showdata.ul=abs(swMotorRpm);
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 8:	// t: torque estimation(0.01Nm) TqRefPuLPF
          		  		LED4NOTE = 1;
          		  		unit = _t;      // t
          		  		dot = 1;
                        /*
      			    	if (swTqRefPu >= 0){
          		  			showdata.ul = swTqRefPu;
          		  		}
          		  		else{
          		  			showdata.ul = -swTqRefPu;
          		  			unit = _NEG;
          		  		}
          		  		*/
          		  		
                        //[JES Torq Detect Function, Special.Kung, 2022/09/01]
                        if (TqRefPuLPF.sw.hi >= 0)
                        {
          		  			showdata.ul = abs(TqRefPuLPF.sw.hi);
          		  		}
          		  		else
                        {
          		  			showdata.ul = abs(TqRefPuLPF.sw.hi);
          		  			unit = _NEG;
          		  		}
          		  		
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 9:	// Pulse count per 0.01sec
          		  		LED4NOTE = 1;
          		  		unit = _G;      // G
          		  		showdata.ul = APR_uwThetaNoMx;
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 10:	// d: Electric Angle
          		  		LED4NOTE = 1;
          		  		unit = _d;      // d
          		  		dot = 1;
          		  	  	showdata.ul = uwElecAngle;
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 11:	// 1.:AVI
          		  		LED4NOTE = 1;
          		  		unit = _1 | _DOT;
          		  		dot = 1;
          		  	  	showdata.ul = swAVICalib;
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 12:	// 2.:ACI
          		  		/*LED4NOTE = 1;             //[ACI function remove, Bernie, 01/20/2012]
                                             unit = _2 | _DOT;
          		  		        dot = 1;
          		  	  	        showdata.ul = swACICalib;
          		  		        LED_DecBcd(showdata.ul, unit);*/  
                        spdispx++;  
          		  		break;
          		  	case 13:	// 3:AUI2
          		  		LED4NOTE = 1;
          		  		unit = _3 | _DOT;
          		  		dot = 1;
          		  	  	showdata.ul = swAUICalib;
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
         		  	case 14:	// t.: TH1
          		  		LED4NOTE = 1;
          		  		unit = (_t|_DOT);
          		  		dot = 1;
          		  		if (HS_Temp >= 0){
          		  			showdata.ul = HS_Temp;
          		  		}
          		  		else{
          		  			showdata.ul = -HS_Temp;
          		  			unit = _NEG;
          		  		}
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
         		  	case 15:	// T.: TH2
          		  		LED4NOTE = 1;
          		  		unit = (_T|_DOT);
          		  		dot = 1;
          		  		if (IGBT_Temp > 0){
          		  			showdata.ul = IGBT_Temp;
          		  		}
          		  		else{
          		  			showdata.ul = -IGBT_Temp;
          		  			unit = _NEG;
          		  		}
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 16:	//DI, Multi-Function input ON/OFF Status
          		  		LED4NOTE = 1;
          		  		unit = _i;
          		  		showdata.ul = mfi_status;
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  	case 17:	//DO, Multi-Function output ON/OFF Status
          		  		LED4NOTE = 1;
          		  		unit = _o;
          		  		showdata.ul = mfo_status;
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  	case 18:	//Multi-speed status
          		  		LED4NOTE = 1;
          		  		unit = _S|_DOT;
          		  		showdata.ul = speed;
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  	case 19:	//DI, Multi-Function input Pin Status
          		  		LED4NOTE = 1;
          		  		unit = _i|_DOT;
          		  		showdata.ul = (0xffff - mfi_now);
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  	case 20:	//DO, Multi-Function output Pin Status
          		  		LED4NOTE = 1;
          		  		unit = _o|_DOT;
          		  		showdata.ul = (0xffff - mio_uwMfoNow);	// DINO, 07/05/2010
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
                    case 21:      
                        spdispx++;         //[User page for LED Keyboard, Bernie, 08/05/2011]
                        break;
                    case 22:
                        spdispx++;         //[User page for LED Keyboard, Bernie, 08/05/2011]
                        break;
                    case 23:
                        spdispx++;         //[User page for LED Keyboard, Bernie, 08/05/2011]
                        break;
          		  	case 24:	// Error Vout
          		  	  	LED4NOTE=1;
          		  	  	unit = _E;
          		  	  	dot = 1;
          		  	  	showdata.ul = pr[VOUT_REC];
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 25:	// Error Vbus
          		  	  	LED4NOTE = 1;
          		  	  	unit = _Ubar;
          		  	  	dot = 1;
          		  	  	showdata.ul = pr[DCBUS_REC];
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 26:	// Error Ffbk
          		  	  	LED4NOTE = 1;
          		  	  	unit = _H;    //[Uniform char, Bernie, 08/05/2011]
          		  	  	dot = 2;
          		  	  	showdata.ul = pr[FFBK_REC];
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 27:	// Error Current
          		  	  	LED4NOTE = 1;
          		  	  	unit = _A;        // A
          		  	  	dot = 2 ;
          		  	  	showdata.ul = pr[ISUM_REC];
          		  	  	LED_DecBcd(showdata.ul , unit);
          		  		break;
          		  	case 28:	// Error Fout
          		  	  	LED4NOTE = 1;
          		  	  	unit = _F;
          		  	  	dot = 2;
          		  	  	showdata.ul = pr[FOUT_REC];
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 29:	// Error Fcmd
          		  	  	LED4NOTE = 1;
          		  	  	unit = _F;
          		  	  	dot = 2;
          		  	  	showdata.ul = pr[FKEY_REC];
          		  	  	LED_DecBcd(showdata.ul, unit);
          		  		break;         		  	
          		  	case 30:	// Error Power
          		  		LED4NOTE = 1;
          		  	  	unit = _P;                 // P
          		  	  	dot = 2;
      			   		if ( (pr[POWER_REC]&0x8000)==0 ){
          		  	  		showdata.ul = pr[POWER_REC];
          		  	  	}
          		  	  	else{
          		  	  		showdata.ul = 0xffff - pr[POWER_REC] + 1;;
          		  	  	}
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 31:	// Error Torque
          		  		LED4NOTE = 1;
          		  		unit = _t;
          		  		dot = 1;
      			    	if ((pr[TQ_REC]&0x8000)==0){
          		  			showdata.ul = pr[TQ_REC];
          		  		}
          		  		else{
          		  			showdata.ul = 0xffff - pr[TQ_REC] + 1;
          		  		}
          		  		LED_DecBcd(showdata.ul, unit);
          		  		break;
          		  	case 32:	// Error Input Status
          		  		LED4NOTE = 1;
          		  		unit = _i;
          		  		showdata.ul = pr[MFI_REC]^pr[MO_INV];
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  	case 33:	// Error Output Status
          		  		LED4NOTE = 1;
          		  		unit = _o;
          		  		showdata.ul = (pr[MFO_REC]^pr[MO_INV]);
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  	case 34:	// Error Drive Status
          		  	    LED4NOTE = 1;     //[Uniform char, Bernie, 08/05/2011]
                        unit = _S;
          		  		showdata.ul = pr[STATE_REC];
          		  		LED_HexBcd(showdata.ul, unit);
          		  		break;
          		  		
                    case 35:	// MI MI Display
                    //LED4NOTE=1;          //[Added MI & MO on board display, Bernie, 2013/01/30]
                        led.s1 = _BLK;
				        led.s0 = _BLK;
                        led.s2 = _BLK;
                        led.s4 = _BLK;
                        LED_MIMO_Display();
          		  		break;
          		  		
          		    case 36:                //[CAN fail rate function, Aevin, 2017/06/14]
                         LED4NOTE = 1;     
                         unit = _c;
                         showdata.ul = uwPDOfailBuf;
          		  		 LED_DecBcd(showdata.ul, unit);
          		  		 break;
          		  		 
          		    case 37:	// PG quality    //[PG quality function, Bernie, 2017/06/20]
                   
                         LED4NOTE=1;
			  	         unit = _q;     // q
			  	         //dot = 1;
			  	         showdata.ul = TB1_swPGQualityDsp;
			  	         LED_DecBcd(showdata.ul, unit);
                         break;
                    case 40: //show direction & real speed in m/s,#16698 for NRG, James, 2021/08/09
                    
                         //fout.ul = ((ULONG)COF_uwFbRe * abs(CRM_slFlxFreqPu>>15));
                         LED4NOTE=1;

                         if(slMotorHz==0)
                         {
                             unit = _BLK;
                         }
                         else if(slMotorHz>=0)
                         {
                             unit = _UP;
                         }
                         else
                         {
                             unit = _DN;
                         }
                         dot = 2;                             
                         showdata.ul = Hz2Metric(abs(slMotorHz));
                         LED_DecBcd(showdata.ul, unit);
                         break;
					case 41:      //[TUV_STOCRC]								//[TUV_STO Checksum,  Special.Kung]
						LED4NOTE = 1;											//[TUV_STO Checksum,  Special.Kung]
						unit = _C|_DOT;											//[TUV_STO Checksum,  Special.Kung]
						showdata.ul = uwTUV_STOCRC;								//[TUV_STO Checksum,  Special.Kung]
						LED_HexBcd(showdata.ul, unit);							//[TUV_STO Checksum,  Special.Kung]
						break;													//[TUV_STO Checksum,  Special.Kung]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
					case 38:	 // Velocity cmd  //[Sibocom, Jason, 2019/11/26]
						LED4NOTE=1;
						unit = _v;  // 0x01 is decimal point

						if (pr[UNITSEL] == 1){  // Hz->m/s
							uwFkey = flHz2Metric(fkey.uw.hi);
						}
						else if(pr[UNITSEL] == 2){  // Hz->ft/s
							uwFkey = Hz2Ft(fkey.uw.hi);
						}
						else{
							uwFkey = fkey.uw.hi;
						}
						
						showdata.ul = uwFkey;
						dot = 2;
						LED_DecBcd(showdata.ul, unit);
						break;
					case 39:	  // Velocity fdb  //[Sibocom, Jason, 2019/11/26]
						LED4NOTE=1;
						unit = _h;  // 0x01 is decimal point
						
						if (pr[UNITSEL] == 1){  // Hz->m/s
							uwFout = Hz2Metric(fout.uw.hi);
						}
						else if(pr[UNITSEL] == 2){  // Hz->ft/s
							uwFout = Hz2Ft(fout.uw.hi);
						}
						else{
							uwFout = fout.uw.hi;
						}
						
						showdata.ul = uwFout;
						dot = 2;
						LED_DecBcd(showdata.ul, unit);
						break;
#endif
          		}  // end of special display
				break; // end of case 3 [ multi-function display ]

			case GrPAGE2:	// xx-  Group page
				led.s1 = _BLK;
				led.s0 = _BLK;
        		goto prxxdisp;
        	case FunPAGE2:	//  xx-xx   Parameter Index page
				unit = prno / 10;
				led.s1 = chartab[unit];
				unit = prno - unit * 10;
				led.s0 = chartab[unit];
                prxxdisp:
				unit = grno / 10;
				led.s4 = chartab[unit];
				unit = grno - unit * 10;
				led.s2 = chartab[unit] | _DOT;
        		break;

			case DataPAGE2:	// dxxxxx  data page
			
                if(grno==13){ //[ //[13Grop modify,Lyabryan,2016/07/19]
                    uwParAdr = pr[prtab[grno-1] + prno];
                    uwParAdr_grno = uwParAdr/100;
                    uwParAdr_prno = uwParAdr%100;
                    relprno = prtab[uwParAdr_grno] + uwParAdr_prno;
                    //uwParData = uwParData_Group13;
                }//] //[13Grop modify,Lyabryan,2016/07/19]
                uwAttr = GetParAttr(relprno);
                if(OBKEYPROG){//[ //[13Grop modify,Lyabryan,2016/07/19]
                    KEY_uwPrData = GetParData(relprno);
                    OBKEYPROG = 0; 
                } //] //[13Grop modify,Lyabryan,2016/07/19]
				if (uwAttr & READ){  // parameter is read only
					showdata.ul = GetParData(relprno);  // DINO, 03/22/2010
				}
				else{
					showdata.ul = KEY_uwPrData;
				}
				dot = (uwAttr&0x0300) >> 8 ;
				if ((uwAttr&0x0060) == DPB){
					LED_BinBcd(showdata.ul, unit);
				}
				else if((uwAttr&0x0060) == DPH){
					LED_HexBcd(showdata.ul, unit);
				}
				else{
					// [ "SIGN" Display, DINO, 03/22/2010
					if (uwAttr & SIGN){
						if (showdata.uw.low > 32767){  // MINUS DATA
							LED4NOTE = 1;
							unit = _NEG;
							showdata.ul = 65535 - showdata.uw.low + 1;
							LED_DecBcd(showdata.ul, unit);
						}
						else{
							LED_DecBcd(showdata.ul, unit);
						}
					}
					else{
						LED_DecBcd(showdata.ul, unit);
					}
					// ]
				}
				if ((uwAttr&READ)==0 || Error!=0 || WarnCode!=0){  // parameter is read only
					blink_seg(blinks);
				}
				break;

			case MsgPAGE2:	// End, Err
				if (endct != 0){   // delay 4 show End , Err
					endct-- ;
					if ( KEYEND ){   /* SHOW -End- */
						led.s4 = _BLK;
						led.s3 = _BLK;
						led.s2 = _E;
						led.s1 = _n;
						led.s0 = _d;
					}
					else {     /* SHOW -Err- */
						led.s4 = _BLK;
						led.s3 = _BLK;
						led.s2 = _E;
						led.s1 = _r;
						led.s0 = _r;
					}
				}
				else{
					KEY_ubDispMode = DataPAGE2;
				}
				break;

			case ErrPAGE2:	// Error code
				ErrorMSG();
				if (KEYRESET == 0)       // if could not be reset >> blink
					blink_seg(ledx);
				break;

			case WarnPAGE2:	// Warning
				warndisp(WarnCode);
				blink_seg(ledx);      // blink warning message
				break;

			case PU02SAVE2:	// Copy message: "SAVE"
				if(COPYEN){
					led.s4 = _S;
					led.s3 = _BLK;
					led.s2 = _A;
					led.s1 = _v;
					led.s0 = _E;
					blink_seg(ledx);
				}
				break;
            case RECENTPG:
                recent_no = pr[UMAP_ADD0+recent_pr];
                ubgr_10 = recent_no/1000;
                ubgr_1 = (recent_no/100)%10;
                ubpr_10 = (recent_no%100)/10;
                ubpr_1 = recent_no%10;
				led.s1 = chartab[ubpr_10];
				led.s0 = chartab[ubpr_1];
				led.s4 = chartab[ubgr_10];
				led.s2 = chartab[ubgr_1] | _DOT;
            break;
#if 0	// DINO_TEST
        case 12: {	// current calibration page A.
          dot = 1;
          LED4NOTE = 1;
          unit = CHAR_A | 0x01;        // A. Irms by Iu, Iw
          showdata.ul = disp_IrmsLPF.sw.hi ;
          LED_DecBcd(showdata.ul, unit);
        } break;
#if LSCTEST
        case 13: {	// | | | |
           led.s4 = 0xaa;
           led.s3 = 0xaa;
           led.s2 = 0xaa;
           led.s1 = 0xaa;
           led.s0 = 0xaa;
        } break;
        case 14: {	// = = = =
           led.s4 = 0x54;
           led.s3 = 0x54;
           led.s2 = 0x54;
           led.s1 = 0x54;
           led.s0 = 0x54;
        } break;
        case 15: {	// . . . .
           led.s4 = 0x01;
           led.s3 = 0x01;
           led.s2 = 0x01;
           led.s1 = 0x01;
           led.s0 = 0x01;
        } break;
#endif
#endif	// DINO_TEST
        default:
        break;
      }
   }
}

//-- KEY_ubDispMode=10, Warning code page (OL2, CE-XX)
void warndisp(UBYTE ubWarnCode)
{
	LEDDATASEG WarnMsgLED;

#if 1
	// [ Change Error Code to saf_ubIedErr, DINO, 08/09/2010
	if ( ubWarnCode ){

		led.s3 = _BLK;

		WarnMsgLED = WarnMSG[(ubWarnCode-1)];
		led.s4 = WarnMsgLED.s4;
		led.s2 = WarnMsgLED.s2;
		led.s1 = WarnMsgLED.s1;
		led.s0 = WarnMsgLED.s0;
	}
	// ]
#else
	led.s4 = _BLK;
	led.s3 = _BLK;
	led.s2 = _BLK;
	led.s1 = _BLK;
	led.s0 = _BLK;

	switch (ubWarnCode) {

		case PC_CE01:
            led.s1 = _0;
            led.s0 = _1;
        	goto erreCEdisp;
		case PC_CE02:
            led.s1 = _0;
            led.s0 = _2;
        	goto erreCEdisp;
		case PC_CE03:
            led.s1 = _0;
            led.s0 = _3;
        	goto erreCEdisp;
		case PC_CE04:
            led.s1 = _0;
            led.s0 = _4;
        	goto erreCEdisp;
		case PC_CE10:
            led.s1 = _1;
            led.s0 = _0;
erreCEdisp:
            led.s4 = _C;
            led.s2 = _E;
            break;
		case CP_CE10:
            led.s4 = _C;
            led.s2 = _P;
            led.s1 = _1;
            led.s0 = _0;
            break;
		case SE1_WARN:
            led.s2 = _S;
            led.s1 = _E;
            led.s0 = _1;
            break;
		case SE2_WARN:
            led.s2 = _S;
            led.s1 = _E;
            led.s0 = _2;
            break;
		case oH1_WARN:
            led.s0 = _1;
        	goto errohdisp;
		case oH2_WARN:
            led.s0 = _2;
        	goto errohdisp;
		case oH3_WARN:
            led.s0 = _3;
errohdisp:
            led.s2 = _o;
            led.s1 = _H;
            break;
		case PGFBK_WARN:
            led.s4 = _P;
            led.s2 = _G;
            led.s1 = _F;
            led.s0 = _1;
            break;
		case PGL_WARN:
            led.s4 = _P;
            led.s2 = _G;
            led.s1 = _F;
            led.s0 = _2;
            break;
		case OSPD_WARN:
            led.s4 = _P;
            led.s2 = _G;
            led.s1 = _F;
            led.s0 = _3;
            break;
		case DEVA_WARN:
            led.s4 = _P;
            led.s2 = _G;
            led.s1 = _F;
            led.s0 = _4;
            break;
		case PHL_WARN:
            led.s2 = _P;
            led.s1 = _H;
            led.s0 = _L;
            break;
		case OT1_WARN:
            led.s0 = _1;
        	goto erreotdisp;
		case OT2_WARN:
        	led.s0 = _2;
erreotdisp:
            led.s2 = _o;
            led.s1 = _t;
            break;
		case oSL_WARN:
            led.s2 = _o;
            led.s1 = _S;
            led.s0 = _L;
            break;
		case tUn_WARN:
            led.s2 = _t;
            led.s1 = _U;
            led.s0 = _n;
            break;
		case Fan_WARN:
            led.s2 = _F;
            led.s1 = _A;
            led.s0 = _n;
            break;
/*
		case Fan_WARN
		case PID_WARN    
		case ANL_WARN    
		case uC_WARN     
		case AUE_WARN    
		case CC_WARN     
*/
	}
#endif
}


#ifdef _LEDKEY_C
    #undef _LEDKEY_C
#endif

/************************************************************************
 Copyright (c) 2006 IABU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
