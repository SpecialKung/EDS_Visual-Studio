/*===============================================================
Author: DINO

Project: VFD-VL

Filename: SCI1_EnDat.H

Partner Filename: SCI1_EnDat.C

Description: This is a inclue file of SCI1_EnDat.C

Complier: 

	
History:

===============================================================*/
#ifdef _SCI1_EnDat_C
   #define SCI1_EnDat_EXT
#else
   #define SCI1_EnDat_EXT extern
#endif


/* Function Call ==============================================*/
SCI1_EnDat_EXT void TxD_Data_EnDat(void);
SCI1_EnDat_EXT void RxDecoder_EnDat(void);
SCI1_EnDat_EXT UBYTE MakeCrcPos(UBYTE,UBYTE,UBYTE,UBYTE,ULONG,ULONG);
SCI1_EnDat_EXT UBYTE MakeCrcNorm(UBYTE,UWORD);


/* Exported Variable List ======================================*/
SCI1_EnDat_EXT UBYTE	edt_ubMode,
			  			edt_ubErr,
			  			edt_ubStep,
			  			edt_ubRxBuf0,
			  			edt_ubRxBuf1,
			  			edt_ubRxBuf2,
			  			edt_ubRxBuf3;

SCI1_EnDat_EXT UWORD	edt_uwEnDatTheta,
			  			edt_uwCRCEnDat,
			  			edt_uwCRC,
			  			edt_uwAddr,
			  			edt_uwPar;



/************************************************************************
 Copyright (c) 2008 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
