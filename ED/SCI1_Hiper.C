/*===============================================================
Author: DINO
                  
Project: VFD-VL

Filename: SCI1_Hiper.C

Partner Filename: SCI1_Hiper.H

Description: This is a sample code.

Complier: 

Input Variables: N/A

Output/Return Variables: N/A

Subroutine:
	
History:
===============================================================*/
#ifndef _SCI1_Hiper_C
    #define _SCI1_Hiper_C
#endif

/* Include File ===============================================*/
#include "ProgHeader.h"

void TxD_Data_Hiper(void)
{
	UBYTE i, ubChecksum;

	Com_WatchDog0 = 0;
	RTU_CNT0 = 0;		 // clr rtu space timer
	SendCNT0 = 0;
	// [ Modify Hiperface communication, DINO, 05/19/2009
	RX_OK0 = 0;
	// ]
	ubChecksum  = 0;

	if ( EDT_INIT==0 ){		// Reset when Power ON
		TxBuf_0[0]	= 0x40;	// address
		TxBuf_0[1]	= 0x53;	// Reset
		Tx0CNT		= 2;
		EDT_INIT	= 1;
	}
	else{
		TxBuf_0[0]	= 0x40;	// address
		TxBuf_0[1]	= 0x42;	// Read Position
		Tx0CNT		= 2;
	}
	for(i=0; i<Tx0CNT; i++){
		ubChecksum ^= TxBuf_0[i];
	}
	TxBuf_0[Tx0CNT] = ubChecksum;	// checksum

#if SH7286 //Sean, 01/25/2010
	SCI0.SCR.BIT.RIE = 0;
	SCI0.TDR = TxBuf_0[0];
	//SCI4.SCSSR.BIT.TDRE = 0;
	SCI0.SCR.BIT.TEIE = 1;		// Enable Transmit End interrupt
#else
	SCI1.SCSCR.BIT.RIE = 0;
	SCI1.SCTDR = TxBuf_2[0];
	SCI1.SCSSR.BIT.TDRE = 0;
	SCI1.SCSCR.BIT.TEIE = 1;		// Enable Transmit End interrupt
#endif
}

void RxDecoder_Hiper(void)
{
	//UBYTE i, ubChecksum, ubError;				//clear Warning, Special.kung, 03/08/2023

#if 1 //[For IED PG-Card, Sampo, 02/14/2010]

	if (vfd_btPGHSD1Set==1)	// fix pghsd1 code, Sean, 06/01/2012
		edt_uwPar = hsd_stPgReplyOut.uwAngle;	
	else //[delete PGHSD, Lyabryan, 2015/12/17]
    	edt_uwPar = uwHiperPosition;
	
	//[PGHSD Add Hiperface, Jerry Yu, 2019/11/15]
	if ((pr[PG_C_TYPE]&0x4000)==0x0000){
		//--------------------------------------------------------
		//	encoder_theta = encoder_value % (resolution/pairs)
		//	Hiperface resolution = 32768 -> 8192
		//--------------------------------------------------------
		edt_uwEnDatTheta = edt_uwPar % ((8192+(COF_ubMPolePair>>1))/COF_ubMPolePair);

		//---------------------------------------------------------
		//	Zero_offset = encoder_theta / (resolution/pairs) * Q16
		//---------------------------------------------------------
		if ( PGDIR==1 )   
			TUN_uwTheta = CRM_uwTheta - (((ULONG)edt_uwEnDatTheta<<16)*COF_ubMPolePair>>13);
		else
			TUN_uwTheta = CRM_uwTheta + (((ULONG)edt_uwEnDatTheta<<16)*COF_ubMPolePair>>13);

		//----------------------------------------------------------------------
		//	electrcal_theta = encoder_theta / (resolution/pairs) * theta_period
		//----------------------------------------------------------------------
		st_uwPGThetaM = ((ULONG)edt_uwEnDatTheta * SpDt_uwAnglePeriod * COF_ubMPolePair >> 13);
	}
	if ((pr[PG_C_TYPE]&0x4000)==0x4000){
		//Original
		//--------------------------------------------------------
		//  encoder_theta = position_value % (resolution/pairs)
		//  Hiperface resoultion = 32768
		//--------------------------------------------------------
		edt_uwEnDatTheta = edt_uwPar % ((32768+(COF_ubMPolePair>>1))/COF_ubMPolePair);

		//--------------------------------------------------------
		//  Zero_offset = encoder_theta / (resolution/pairs) * Q16
		//--------------------------------------------------------
		if ( PGDIR==1 )
			TUN_uwTheta = CRM_uwTheta - ((ULONG)edt_uwEnDatTheta<<1)*COF_ubMPolePair;
		else
			TUN_uwTheta = CRM_uwTheta + ((ULONG)edt_uwEnDatTheta<<1)*COF_ubMPolePair;

		//-----------------------------------------------------------------
		//  electrcal_theta = encoder_theta / (resolution/pairs) * theta_period
		//-----------------------------------------------------------------
		st_uwPGThetaM = ((ULONG)edt_uwEnDatTheta * SpDt_uwAnglePeriod * COF_ubMPolePair >> 15);
	}
#else
	if ( RX_OK2 ){

		/*=====================================================================================
		  Normal:
		    RxBuf_2[0]  RxBuf_2[1]	RxBuf_2[2]  RxBuf_2[3]  RxBuf_2[4]	RxBuf_2[5]  RxBuf_2[6]
		      address     0x42		  POS_HH      POS+HL      POS_LH      POS_LL     checksum
		--------------------------------------------------------------------------------------
		  Error:
		    RxBuf_2[0]  RxBuf_2[1]	RxBuf_2[2]  RxBuf_2[3]
		      address     0x50		  status     checksum
		=====================================================================================*/
		if ( RxBuf_2[1]==0x50 ){	// Error Handling
			ubError = 1;
		}
		else{
			ubError = 0;
		}

		ubChecksum = 0;
		for(i=0; i<Rx2CNT; i++){
			ubChecksum ^= RxBuf_2[i];
		}

		edt_uwPar = ((UWORD)RxBuf_2[4]<<8) | RxBuf_2[5];	// position_value
		edt_uwCRC = RxBuf_2[6];								// Checksum

		//--------------------------------------------------------
		//  encoder_theta = position_value % (resolution/pairs)
		//  Hiperface resoultion = 32768
		//--------------------------------------------------------
		edt_uwEnDatTheta = edt_uwPar % ((32768+(COF_ubMPolePair>>1))/COF_ubMPolePair);

		//--------------------------------------------------------
		//  Zero_offset = encoder_theta / (resolution/pairs) * Q16
		//--------------------------------------------------------
		if ( PGDIR==1 )
			TUN_uwTheta = CRM_uwTheta - ((ULONG)edt_uwEnDatTheta<<1)*COF_ubMPolePair;
		else
			TUN_uwTheta = CRM_uwTheta + ((ULONG)edt_uwEnDatTheta<<1)*COF_ubMPolePair;

		//-----------------------------------------------------------------
		//  electrcal_theta = encoder_theta / (resolution/pairs) * theta_period
		//-----------------------------------------------------------------
		st_uwPGThetaM = ((ULONG)edt_uwEnDatTheta * SpDt_uwAnglePeriod * COF_ubMPolePair >> 15);

		if ( ubError==1 || edt_uwCRC!=ubChecksum ){
			edt_ubErr = 1;
			if (ubError == 1){
			}
			else{
			}
		}
		else{
			edt_ubErr = 0;
		}
    }
    else{
    	edt_ubErr = 1;
    	// [ 05/19/2009
#if SH7286 //Sean, 01/25/2010
		InitSCI4();
#else    	
    	InitSCI1();
#endif    	
    	// ]
    }

	// [ Add by DINO, 10/05/2009
	if (TxBuf_2[1] == 0x42)
		EDT_READY = 1;
	// ]

	SCI2_TodCNT = 0;
#endif
}

#ifdef _SCI1_Hiper_C
	#undef _SCI1_Hiper_C
#endif

/************************************************************************
 Copyright (c) 2008 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/