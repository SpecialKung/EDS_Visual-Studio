/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _TB_WG_C
   #define TB_WG_EXT 
#else
   #define TB_WG_EXT  extern
#endif
/*======= Modules used (included header files) ==================*/

/*========== @ Defines =========================================*/

/*=== MTU3 & 4 Internal Clcok: count with phi/1 ============================*/
/*           WG_period
     1KHz    28000
     2KHz    14000
     3KHz     9333
     4KHz     7000
     5KHz     5600
     6KHz     4666
     7KHz     4000
     8KHz     3500
     9KHz     3111
    10KHz     2800
    11KHz     2545
    12KHz     2333
    13KHz     2153
    14KHz     2000
    15KHz     1866 
*/

/* Struct Type define =========================================*/

/* Function Call ==============================================*/
TB_WG_EXT void WG_Enable(void);
TB_WG_EXT void WG_Disable(void);
TB_WG_EXT void WG_Init(void);
TB_WG_EXT void WG_isr(void);

/* Exported Variable List ======================================*/

                          
/*== Local Variable List (Variables not open to other files)  ==*/
#ifdef TB_WG_EXT
//	_UWORD smpl_uwPrivatePu;
#endif

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/