/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _PWMGen_C
   #define PWMGen_EXT 
#else
   #define PWMGen_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
PWMGen_EXT void ZeroPWM(void);
PWMGen_EXT void PWM_GEN(void);
PWMGen_EXT void UabcPu2Duty(void);

/* Exported Variable List ======================================*/
DQ2ABC_EXT SWORD          Duty_swTasInPu,
                          Duty_swTbsInPu,
                          Duty_swTcsInPu;


PWMGen_EXT SWORD          PWM_swTaInPu,
                          PWM_swTbInPu,
                          PWM_swTcInPu;
                          
PWMGen_EXT SWORD          PWM_swTaOut,
                          PWM_swTbOut,
                          PWM_swTcOut,
                          experiod_Buf,			//ADDED BY SCOTTY 2007/07/02
                          PWM_swTaOut_Buf,		//ADDED BY SCOTTY 2007/07/02
    					  PWM_swTbOut_Buf,    	//ADDED BY SCOTTY 2007/07/02
    					  PWM_swTcOut_Buf,		//ADDED BY SCOTTY 2007/07/02
    					  update_experiod,		//ADDED BY SCOTTY 2007/07/02
                          experiod_Buf,			//ADDED BY SCOTTY 2007/07/02
                          PWM_swGBP,
                          PWM_swTabOut,
                          PWM_swTbcOut,
                          PWM_swTcaOut,
                          swTest1,
                          swTest2,
                          swTest3,
                          swTest4;

PWMGen_EXT ULONG          ulKu4Uout;

PWMGen_EXT UBYTE_UNION	  PWM_Status,
                          EPS_Direct_flag; //[EPS autodetect dir,Lyabryan,2018/07/02]

PWMGen_EXT UWORD 		  uw_UPdeadtime,		//ADDED BY SCOTTY 2007/07/11
						  uw_LOWdeadtime;		//ADDED BY SCOTTY 2007/07/11
/*== Local Variable List (Variables not open to other files)  ==*/

/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
