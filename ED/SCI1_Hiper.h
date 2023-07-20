/*===============================================================
Author: DINO

Project: VFD-VL

Filename: SCI1_Hiper.H

Partner Filename: SCI1_Hiper.C

Description: This is a inclue file of SCI1_Hiper.C

Complier: 

	
History:

===============================================================*/
#ifdef _SCI1_Hiper_C
   #define SCI1_Hiper_EXT
#else
   #define SCI1_Hiper_EXT extern
#endif


/* Function Call ==============================================*/
SCI1_Hiper_EXT void TxD_Data_Hiper(void);
SCI1_Hiper_EXT void RxDecoder_Hiper(void);


/* Exported Variable List ======================================*/



/************************************************************************
 Copyright (c) 2008 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
