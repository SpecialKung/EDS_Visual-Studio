/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _DEADTIME_C
   #define DEADTIME_EXT 
#else
   #define DEADTIME_EXT extern
#endif

/* Function Call ==============================================*/
DEADTIME_EXT void DBC_COEFInit(void);
DEADTIME_EXT void DBC_Open(void);
DEADTIME_EXT void DBC_Close(void);
DEADTIME_EXT void DBCValue(void);

DEADTIME_EXT SWORD      DBC_swAtemp, 
						DBC_swBtemp, 
						DBC_swCtemp,
                        UaDBC, 
						UbDBC, 
						DBC_swSTEPANGLE,	//ADDED BY SCOTTY 2007/07/16 
						UcDBC;                         

DEADTIME_EXT UWORD      DBC_uwIaCnt, 
						DBC_uwIbCnt, 
						DBC_uwIcCnt,
                    	DBC_ATmCNT, 
						DBC_BTmCNT, 
						DBC_CTmCNT,
                        DBC_ATm, 
						DBC_BTm,			
						DBC_CTm;  

DEADTIME_EXT SWORD      DBCDt,
						DBCDu,
						DBheight;
						
DEADTIME_EXT UBYTE  	CLorOP ;	//ADDED BY SCOTTY 2007/07/17		

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
