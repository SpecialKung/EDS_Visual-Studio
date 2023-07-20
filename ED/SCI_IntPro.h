/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: Main.H

Partner Filename: Main.C

Description: This is a inclue file of Main.C

Complier: 

	
History:

===============================================================*/
#ifdef _SCI_IntPro_C
   #define SCI_IntPro_EXT
#else
   #define SCI_IntPro_EXT extern
#endif

SCI_IntPro_EXT void SCI12_RxINT(void);
SCI_IntPro_EXT void SCI12_TxINT(void);
SCI_IntPro_EXT void SCI1_RxINT(void);
SCI_IntPro_EXT void SCI1_TxINT(void);
SCI_IntPro_EXT void SCI2_RxINT(void);
SCI_IntPro_EXT void SCI2_TxINT(void);
SCI_IntPro_EXT void SCI0_RxINT(void);
SCI_IntPro_EXT void SCI0_TxINT(void);
SCI_IntPro_EXT void SCI3_RxINT(void);
SCI_IntPro_EXT void SCI3_TxINT(void);
                                                     
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/