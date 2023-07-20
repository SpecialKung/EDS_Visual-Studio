/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _PG2Ref_C
   #define PG2Ref_EXT 
#else
   #define PG2Ref_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
PG2Ref_EXT void Init_PG2Ref(void);
PG2Ref_EXT void PG2RefCal(void);
PG2Ref_EXT void TB1_PG2Ref(void);
/* Exported Variable List ======================================*/
PG2Ref_EXT UBYTE	PG2_1msCNT;		//CalUBYTE: 1 UBYTE
					
//PG2Ref_EXT SBYTE
PG2Ref_EXT UWORD	PG2R_uwCmdLPG,
					PG2_uwCNTNew,
					PG2_uwCNTOld,
					PG2_uwCNTOrg,
					PG2_uwTheta;

PG2Ref_EXT SWORD	PG2_swCNTIntgral;

PG2Ref_EXT ULONG	PG2_ulNpulse;
PG2Ref_EXT SLONG	PG2_slAPRIntgral,
					PG2_slSpdCmd;
//PG2Ref_EXT ULONG_UNION	PG2_ulSpdCmdLPF;	// Move to A_Monitor.h, 11/04/2008
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
