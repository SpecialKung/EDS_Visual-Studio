/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _ADProg_C
   #define ADProg_EXT 
#else
   #define ADProg_EXT extern
#endif

/* Function Call ==============================================*/
ADProg_EXT void ADInitCalib(void);
ADProg_EXT void ReadAD(void);

ADProg_EXT UWORD	IrmsAD,
			        IrmsAD1,		//ADDED BY SCOTTY TEST, 03/01/2007 IrmsAD1 repleace IrmsAD
			        IrmsADOld,
			        dcbusAD,
			        dcbusADAVG,
			        dcbusDCInit;
			        
#if 0	// fix AD position, Sean, 10/18/2010			        
ADProg_EXT UWORD	AN0,AN1,AN2,AN3,AN4,AN5,AN6,AN7
#if SH7286 //Sean, 01/25/2010
#else			        
			        ,AN12,AN13,AN14,AN15
#endif			        
			        ,AN8,AN9,AN10,AN11;
#endif			        

ADProg_EXT UWORD	AD_uwIA0,
			        AD_uwIB0,
			        AD_uwIC0,			        			        			        
                    AD_uwPHL,		// dino, 03/29/2007    
                    				// PHL can be deleted, Sean, 01/25/2010            
                    AD_uwFLock,		// dino, 03/29/2007
			        AD_uwAUI1ad,
			        AD_uwAUI1adReal,
			        AD_uwACIad,
            		AD_uwAUI2ad,
			        AD_uwAUI2adReal;                    

ADProg_EXT ULONG	AD_ulIA0, AD_ulIB0, AD_ulIC0;

ADProg_EXT SWORD    //AD_swIAPu,
					AD_swIAPu_Old,	
             		//AD_swIBPu,
					AD_swIBPu_Old,
                   	//AD_swICPu,
					AD_swICPu_Old,
					swIdssPu,
					swIqssPu,                          
					swIasRefPu,
					swIbsRefPu,
					swIcsRefPu,
       				adc_swIAtemp,
					adc_swICtemp;

Main_EXT UBYTE_UNION STO_status;

                   
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
