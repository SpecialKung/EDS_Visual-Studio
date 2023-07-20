/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _FluxControl_C
   #define FLUX_EXT 
#else
   #define FLUX_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
FLUX_EXT void Init_Flux(void);
FLUX_EXT void Flux_FlxWkn(void);


/* Exported Variable List ======================================*/
FLUX_EXT UWORD            FLX_uwWslMaxPu;

FLUX_EXT SWORD            FLX_swIdseRefPu,
                          FLX_swFlxFreqPu,
                          FLX_swVsMaxPu,
                          FLX_swVoutPu,
                          FLX_swVoutLimPu;

FLUX_EXT SLONG            FLX_slWslErrKi,
                          FLX_slVsErrKi;
//                          FLX_slIdRefPu_LP;

FLUX_EXT SLONG_UNION	FLX_IdRefPuLPF;

/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
