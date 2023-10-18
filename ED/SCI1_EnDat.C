/*===============================================================
Author: DINO
                  
Project: VFD-VL

Filename: SCI1_EnDat.C

Partner Filename: SCI1_EnDat.H

Description: This is a sample code.

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:
	
History:
===============================================================*/
#ifndef _SCI1_EnDat_C
    #define _SCI1_EnDat_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void TxD_Data_EnDat(void)
{
#if SH7286 //Sean, 01/25/2010
	SCI0.SCR.BIT.TE   = 1;

	if ( SCI0.SSR.BIT.TEND==1 ){
		if ( /*pr[Par126]==0*/1 ){
			if ( EDT_INIT==0 ){	// Initial Step
				//-----------------------------------------
				// Reading out the "number of clock pulses
				//-----------------------------------------
				if ( edt_ubStep==0 ){
					//-- Step1: Selection of Memory Area (Reading Out)
					SCI0.TDR	= 0x0e;		// xx001110: EnDat Command: Selection of Memory Area
					TxBuf_0[1]	= 0xa1;		// 10100001: MRS code
					TxBuf_0[2]	= 0xaa;		// Random(D15~D8)
					TxBuf_0[3]	= 0xaa;		// Random(D7 ~D0)
					Tx0CNT		= 4;
					ubRx0CNT	= 3;
					edt_ubMode	= 1;
				}
				else if ( edt_ubStep==1 ){
					//-- Step2: Encoder to Transmit Parameters (Number of clock pulses)
					SCI0.TDR	= 0x23;		// xx100011: EnDat Command: Encoder to Recieve Parameters
					TxBuf_0[1]	= 0x0d;		// Address: 0DH:Number of Clock Pulses
					TxBuf_0[2]	= 0xaa;		// Random
					TxBuf_0[3]	= 0xaa;		// Random
					Tx0CNT		= 4;
					ubRx0CNT	= 13;
					edt_ubMode	= 1;	/*  */
				}
				//----------------------------------
				// Clearing Errors or Warnings
				//----------------------------------
				else {
					//-- Step3: Selection of Memory Area (Clear Error)
					SCI0.TDR	= 0x0e;		// xx001110: EnDat Command: Selection of Memory Area
					TxBuf_0[1]	= 0xb9;		// 10111001: MRS code
					TxBuf_0[2]	= 0xaa;		// Random(D15~D8)
					TxBuf_0[3]	= 0xaa;		// Random(D7 ~D0)
					Tx0CNT		= 4;
					ubRx0CNT	= 3;
					edt_ubMode	= 1;
				}
				edt_ubStep++;
			}
			else{
				if ( edt_ubMode==0 ){
					//--- Error BIT=1: Clear Error BIT
					if ( (edt_ubRxBuf0&0x10)==0x10 ){
						//-- Clearing Error Bit
						SCI0.TDR	= 0x1c;		// xx011100: EnDat Command: Encoder to Recieve Parameters
						TxBuf_0[1]	= 0x00;		// Address: 00H:Error Messages
						TxBuf_0[2]	= 0x00;		// 00H
						TxBuf_0[3]	= 0x00;		// 00H
						Tx0CNT		= 4;
						ubRx0CNT	= 3;
						edt_ubMode	= 1;
					}
					//--- Error BIT=0: Read Position Value
					else{
						SCI0.TDR	= 0xe0;			// xx000111: EnDat Command: Encoder to send position values
						Tx0CNT		= 1;
						ubRx0CNT	= 2;
						edt_ubMode  = 0;
					}
				}
				else {
					SCI0.TDR	= 0xe0;			// xx000111: EnDat Command: Encoder to send position values
					Tx0CNT		= 1;
					ubRx0CNT	= 2;
					edt_ubMode  = 0;
				}
			}	/*  */
		}
		else if (/*pr[Par126] == 9999*/0){
			//-- Encoder to Receive Reset
			SCI0.TDR	= 0x2a;		// xx101010: EnDat Command: Encoder to Receive Reset
			TxBuf_0[1]	= 0x0a;		// Random
			TxBuf_0[2]	= 0x0a;		// Random(D15~D8)
			TxBuf_0[3]	= 0x0a;		// Random(D7 ~D0)
			Tx0CNT		= 4;
			ubRx0CNT	= 13;
			edt_ubMode	= 1;		/*  */
		}

		if ( edt_ubMode==0 )
			//SCI4.SCSDCR.BYTE = 0;	// LSB in Encoder transmit position value
			SCI0.SCMR.BIT.SDIR = 0;	// LSB in Encoder transmit position value
		else
			//SCI4.SCSDCR.BYTE = 0x08;// MSB in others
			SCI0.SCMR.BIT.SDIR = 1; // MSB in others

		//SCI4.SCSSR.BIT.TDRE = 0;
		
		SCI0.SCR.BIT.TEIE = 1;	// Enable Transmit End interrupt, dino, 03/06/2007
		if ( SendCNT0<(Tx0CNT-1) )
			SCI0.SCR.BIT.TIE  = 1;	// Enable Transmit interrupt, dino, 08/27/2008
	}
#else
	SCI1.SCSCR.BIT.TE   = 1;

	if ( SCI1.SCSSR.BIT.TEND==1 ){
		if ( pr[Par126]==0 ){
			if ( EDT_INIT==0 ){	// Initial Step
				//-----------------------------------------
				// Reading out the "number of clock pulses
				//-----------------------------------------
				if ( edt_ubStep==0 ){
					//-- Step1: Selection of Memory Area (Reading Out)
					SCI1.SCTDR	= 0x0e;		// xx001110: EnDat Command: Selection of Memory Area
					TxBuf_2[1]	= 0xa1;		// 10100001: MRS code
					TxBuf_2[2]	= 0xaa;		// Random(D15~D8)
					TxBuf_2[3]	= 0xaa;		// Random(D7 ~D0)
					Tx2CNT		= 4;
					ubRx2CNT	= 3;
					edt_ubMode	= 1;
				}
				else if ( edt_ubStep==1 ){
					//-- Step2: Encoder to Transmit Parameters (Number of clock pulses)
					SCI1.SCTDR	= 0x23;		// xx100011: EnDat Command: Encoder to Recieve Parameters
					TxBuf_2[1]	= 0x0d;		// Address: 0DH:Number of Clock Pulses
					TxBuf_2[2]	= 0xaa;		// Random
					TxBuf_2[3]	= 0xaa;		// Random
					Tx2CNT		= 4;
					ubRx2CNT	= 13;
					edt_ubMode	= 1;	/*  */
				}
				//----------------------------------
				// Clearing Errors or Warnings
				//----------------------------------
				else {
					//-- Step3: Selection of Memory Area (Clear Error)
					SCI1.SCTDR	= 0x0e;		// xx001110: EnDat Command: Selection of Memory Area
					TxBuf_2[1]	= 0xb9;		// 10111001: MRS code
					TxBuf_2[2]	= 0xaa;		// Random(D15~D8)
					TxBuf_2[3]	= 0xaa;		// Random(D7 ~D0)
					Tx2CNT		= 4;
					ubRx2CNT	= 3;
					edt_ubMode	= 1;
				}
				edt_ubStep++;
			}
			else{
				if ( edt_ubMode==0 ){
					//--- Error BIT=1: Clear Error BIT
					if ( (edt_ubRxBuf0&0x10)==0x10 ){
						//-- Clearing Error Bit
						SCI1.SCTDR	= 0x1c;		// xx011100: EnDat Command: Encoder to Recieve Parameters
						TxBuf_2[1]	= 0x00;		// Address: 00H:Error Messages
						TxBuf_2[2]	= 0x00;		// 00H
						TxBuf_2[3]	= 0x00;		// 00H
						Tx2CNT		= 4;
						ubRx2CNT	= 3;
						edt_ubMode	= 1;
					}
					//--- Error BIT=0: Read Position Value
					else{
						SCI1.SCTDR	= 0xe0;			// xx000111: EnDat Command: Encoder to send position values
						Tx2CNT		= 1;
						ubRx2CNT	= 2;
						edt_ubMode  = 0;
					}
				}
				else {
					SCI1.SCTDR	= 0xe0;			// xx000111: EnDat Command: Encoder to send position values
					Tx2CNT		= 1;
					ubRx2CNT	= 2;
					edt_ubMode  = 0;
				}
			}	/*  */
		}
		else if (pr[Par126] == 9999){
			//-- Encoder to Receive Reset
			SCI1.SCTDR	= 0x2a;		// xx101010: EnDat Command: Encoder to Receive Reset
			TxBuf_2[1]	= 0x0a;		// Random
			TxBuf_2[2]	= 0x0a;		// Random(D15~D8)
			TxBuf_2[3]	= 0x0a;		// Random(D7 ~D0)
			Tx2CNT		= 4;
			ubRx2CNT	= 13;
			edt_ubMode	= 1;		/*  */
		}

		if ( edt_ubMode==0 )
			SCI1.SCSDCR.BYTE = 0;	// LSB in Encoder transmit position value
		else
			SCI1.SCSDCR.BYTE = 0x08;// MSB in others

		SCI1.SCSSR.BIT.TDRE = 0;
		SCI1.SCSCR.BIT.TEIE = 1;	// Enable Transmit End interrupt, dino, 03/06/2007
		if ( SendCNT2<(Tx2CNT-1) )
			SCI1.SCSCR.BIT.TIE  = 1;	// Enable Transmit interrupt, dino, 08/27/2008
	}
#endif	
}


//-- Decoder EnDat RX data, called by 100ms
void RxDecoder_EnDat(void)
{
	//UBYTE ubError1, ubCRCEnDat;				//clear Warning, Special.kung, 03/08/2023
	

	if (vfd_btPGHSD1Set==1)	// fix pghsd1 code, Sean, 06/01/2012
		edt_uwPar = hsd_stPgReplyOut.uwAngle;	
    	
    //--------------------------------------------------------
		//  encoder_theta = encoder_value % (resolution/pairs)
		//  EnDat resolution = 8192
		//--------------------------------------------------------
		edt_uwEnDatTheta = edt_uwPar % ((8192+(COF_ubMPolePair>>1))/COF_ubMPolePair);

		//---------------------------------------------------------
		//  Zero_offset = encoder_theta / (resolution/pairs) * Q16
		//---------------------------------------------------------
		if ( PGDIR==1 )   
			TUN_uwTheta = CRM_uwTheta - (((ULONG)edt_uwEnDatTheta<<16)*COF_ubMPolePair>>13);
		else
			TUN_uwTheta = CRM_uwTheta + (((ULONG)edt_uwEnDatTheta<<16)*COF_ubMPolePair>>13);

		//----------------------------------------------------------------------
		//  electrcal_theta = encoder_theta / (resolution/pairs) * theta_period
		//----------------------------------------------------------------------
		st_uwPGThetaM = ((ULONG)edt_uwEnDatTheta * SpDt_uwAnglePeriod * COF_ubMPolePair >> 13);

}


/*===============================================================
Function: MakeCrcPos

The function MakeCrcPos generates the CRC code for the following mode commands:
- Encoder to send position values (EnDat 2.1)
- Encoder to send position values (EnDat 2.2)
- Encoder to send test values

Parameters
clocks 	:	Data width in bits
		 	For the mode command “Encoder to send position values,” this value
			is specific to the encoder and can be transferred from word 13 of the
			parameter area for the encoder manufacturer.
			For the mode command “Encoder to send test values,” the data width is
			always 40 bits.
error1 	: 	Error message 1
error2 	:	Error message 2 (any for EnDat 2.1)
endat22 :	0 = CRC calculation for “Encoder to send position value” (EnDat 2.1)
			1 = CRC calculation for “Encoder to send position value” (EnDat 2.2)
highpos :	Bits 32 to 63 of the position value or of the test value
lowpos 	:	Bits 0 to 31 of the position value or of the test value

Return code
CRC code (5-bit ?? see section 2.3.1 Transferring the Position Value)

Example: CRC calculation for “Encoder to send position value” (EnDat 2.2)
clocks 	= 25
error1 	= 0
error2 	= 1 // any for EnDat 2.1
endat22 = 1 // for EnDat 2.2
highpos = 0
lowpos 	= 104462
Return code : 3
===============================================================*/
UBYTE MakeCrcPos(UBYTE clocks,UBYTE error1,UBYTE error2,UBYTE endat22,ULONG highpos,ULONG lowpos)
{
	UBYTE ff[5], 	// State of the 5 flip-flops
		  code[66], // Data-bit array
		  ex, 		// Auxiliary variable
		  crc = 0;	// Determined CRC code
	SBYTE i; 		// Controlled variable for looping

	for(i = 0; i < 5; i++) // Set all flip-flops to 1
		ff[i] = 1;

	if (endat22) // Transfer alarm bits into code array
	{
		code[0] = error1;
		code[1] = error2;
	}
	else
		code[1] = error1;

	for(i = 2; i < 34; i++) // Transfer lowpos bits into code array
	{
		code[i] = (lowpos & 0x00000001L) ? 1 : 0;
		lowpos >>= 1;
	}

	for(i = 34; i < 66; i++) // Transfer highpos bits into code array
	{
		code[i] = (highpos & 0x00000001L) ? 1 : 0;
		highpos >>= 1;
	}

	for(i = (endat22 ? 0 : 1); i <= (clocks+1); i++)
	{ // Calculate the CRC analog to the
		ex = ff[4] ^ code[i]; // described generator hardware
		ff[4] = ff[3];
		ff[3] = ff[2] ^ ex;
		ff[2] = ff[1];
		ff[1] = ff[0] ^ ex;
		ff[0] = ex;
	}

	for(i = 4; i >= 0; i--) // Store CRC in variable
	{
		ff[i] = ff[i] ? 0 : 1; // Invert bits
		crc <<= 1;
		crc |= ff[i];
	}

	return crc;
}


/*===============================================================
Function: MakeCrcNorm
The function MakeCrcNorm generates the CRC code for the following mode commands:
- Selection of memory area
- Encoder to receive parameters
- Encoder to send parameters
- Encoder to receive reset
- Encoder to receive test command
- Additional information (EnDat 2.2)
Parameters
param8 : 8-bit value (address, MRS code,...)
param16 : 16-bit value (parameter)
Return code
CRC code (5-bit)
Example
param8 = 13
param16 = 32793
Return code : 14
===============================================================*/
UBYTE MakeCrcNorm(UBYTE param8,UWORD param16)
{
	UBYTE ff[5],	// State of the 5 flip-flops
		  code[24], // Data-bit array
	  	  ex, 		// Auxiliary variable
		  crc = 0;	// Determined CRC code
	SBYTE i; // Controlled variable for looping

	for(i = 0; i < 5; i++) // Set all flip-flops to 1
		ff[i] = 1;

	for(i = 0; i < 8; i++) // Read 8-bit parameter into code array
	{ // and convert the bit sequence
		code[i] = (param8 & 0x0080) ? 1 : 0;
		param8 <<= 1;
	}

	for(i = 8; i < 24; i++) // Read 16-bit parameter into code array
	{ // and convert the bit sequence
		code[i] = (param16 & 0x8000) ? 1 : 0;
		param16 <<= 1;
	}

	for(i = 0; i < 24; i++) // Calculate the CRC, analog to the
	{ // described generator hardware
		ex = ff[4] ^ code[i];
		ff[4] = ff[3];
		ff[3] = ff[2] ^ ex;
		ff[2] = ff[1];
		ff[1] = ff[0] ^ ex;
		ff[0] = ex;
	}

	for(i = 4; i >= 0; i--) // Store CRC in variable
	{
		ff[i] = ff[i] ? 0 : 1; // Invert bits
		crc <<= 1;
		crc |= ff[i];
	}

	return crc;
}

#ifdef _SCI1_EnDat_C
	#undef _SCI1_EnDat_C
#endif

/************************************************************************
 Copyright (c) 2008 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/