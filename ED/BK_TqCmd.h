/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _TqCmd_C
   #define TqCmd_EXT 
#else
   #define TqCmd_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
TqCmd_EXT void Init_TqCmd(void);
//TqCmd_EXT void TB1_TqCmd(void);		//removed by SCOTTY 02/01/2007
TqCmd_EXT void TB3_TqCmd(void);
TqCmd_EXT void TqLimt(void);

/* Exported Variable List ======================================*/
                          
TqCmd_EXT  UWORD		TqC_uwTqCmdPu,
                        Tqc_uwTqCmdLPG,
                        TqC_uwPSpdLimRe,
                        TqC_uwNSpdLimRe;
                        
TqCmd_EXT  SWORD		TqC_swTqCmd,//6a16j
						TqC_swTqSetPu,
						TqC_swIqseRefPu;
						
TqCmd_EXT  SWORD        TqC_swTqOfstPu,
                        TqC_swPSpdLimPu,
                        TqC_swNSpdLimPu;

TqCmd_EXT  SLONG        TqC_slTqCmdPuLPF;
TqCmd_EXT  SLONG_UNION  TqC_slTqOfstPu; //[Pre-Torque with Load-Cell,Lyabryan,2019/01/08]

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
