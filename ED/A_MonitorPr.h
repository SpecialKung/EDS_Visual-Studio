/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename:

Partner Filename:

Description:

Complier: 

	
History:

===============================================================*/
#ifdef _MonitorPr_C
   #define MonitorPr_EXT 
#else
   #define MonitorPr_EXT extern
#endif
#if 0
/* Function Call ==============================================*/
#if 1

#pragma address uw_SCTEST		= 0xfff80042
#pragma address uw_SCTEST2		= 0xfff80044
#pragma address uw_SCTEST3		= 0xfff80046
#pragma address uw_SCTEST4		= 0xfff80048
#pragma address uw_SCTEST5		= 0xfff8004a
#pragma address uw_SCTEST6		= 0xfff8004c
#pragma address uw_SCTEST7		= 0xfff8004e
#pragma address uw_SCTEST8		= 0xfff80050
#pragma address uw_fcomref		= 0xfff80052
#pragma address uw_fcomfbk		= 0xfff80054

#if 0
#pragma address AN0				= 0xfff80056
#pragma address AN1				= 0xfff80058
#pragma address AN2				= 0xfff8005a
#pragma address AN3 			= 0xfff8005c
#pragma address AN4				= 0xfff8005e
#pragma address AN5				= 0xfff80060
#pragma address AN6				= 0xfff80062
#pragma address AN7				= 0xfff80064
#pragma address AN8				= 0xfff80066
#pragma address AN9				= 0xfff80068
#pragma address AN10			= 0xfff8006a
#pragma address AN11			= 0xfff8006c
#endif

#pragma address AN000			= 0xfff80056
#pragma address AN001			= 0xfff80058
#pragma address AN002			= 0xfff8005a
#pragma address AN003 			= 0xfff8005c
#pragma address AN100			= 0xfff8005e
#pragma address AN00			= 0xfff80060
#pragma address AN01			= 0xfff80062
#pragma address AN101			= 0xfff80064
#pragma address AN02			= 0xfff80066
#pragma address AN03			= 0xfff80068
#pragma address AN102			= 0xfff8006a
#pragma address AN103			= 0xfff8006c


#pragma address Pgc_uwCpo	= 0xfff8006e  //[For IED PG-Card, Sampo, 01/11/2010]
#pragma address Pgc_uwCne	= 0xfff80070  
#pragma address Pgc_uwDpo	= 0xfff80072  
#pragma address Pgc_uwDne	= 0xfff80074  
#pragma address Pgc_uwApo	= 0xfff80076  
#pragma address Pgc_uwAne	= 0xfff80078 
#pragma address Pgc_uwBpo	= 0xfff8007a  
#pragma address Pgc_uwBne	= 0xfff8007c 
#pragma address Pgc_uwRpo	= 0xfff8007e  
#pragma address Pgc_uwRne	= 0xfff80080 

#else
#pragma address uw_SCTEST		= 0xffff8042
#pragma address uw_SCTEST2		= 0xffff8044
#pragma address uw_SCTEST3		= 0xffff8046
#pragma address uw_SCTEST4		= 0xffff8048
#pragma address uw_SCTEST5		= 0xffff804a
#pragma address uw_SCTEST6		= 0xffff804c
#pragma address uw_SCTEST7		= 0xffff804e
#pragma address uw_SCTEST8		= 0xffff8050
#pragma address uw_fcomref		= 0xffff8052
#pragma address uw_fcomfbk		= 0xffff8054

#endif

#endif

#pragma address fout=0x0000a104             //[Address fixed, Aevin, 2017/06/28]
MonitorPr_EXT ULONG_UNION	fkey,			//Freq. Command
							fout;			//Output Frequency

#pragma address fkeyDisplay=0x0000a176      //[Address fixed, Special.Kung, 2022/11/4]
MonitorPr_EXT UWORD         fkeyDisplay;    //Freq. Command for vfd-soft/ explore Display, Special.Kung, 2022/11/4

#pragma address TB1_swAccOpt=0x0000a17A		//[Rationa 362631, Special.Kung]
MonitorPr_EXT SWORD			TB1_swAccOpt;	//[Rationa 362631, Special.Kung]

#pragma address VcmdLLPF=0x0000a10a         //[Address fixed, Aevin, 2017/06/28]
MonitorPr_EXT SLONG_UNION	PHLbusReLPF,	//Dcbus (Vdc)	SCOTTY 09/05/2007
							VcmdLLPF,		//Output Voltage (Vac)
							IrmsReLPF;		//Output Current (A rms)

#pragma address swTqRefPu=0x0000a110        //[Address fixed, Aevin, 2017/06/28]

MonitorPr_EXT SWORD		swMotorRpm,			//Real Motor speed (RPM)
						pv,					//PID feedback (%)
						swTqRefPu;			//Torque Command (%)

MonitorPr_EXT UWORD		PIDsource,			//PID reference (%)
						APR_uwPGPosition,	//PG1 position
						APR_uwZPosition,	//PG1 Z-position
						APR_uwPG2PCom;		//PG2 position
						
MonitorPr_EXT ULONG_UNION					
						PG2_ulSpdCmdLPF;	//PG2 velocity

#pragma address swAVICalib=0x0000a112   	//[Address fixed, Aevin, 2017/06/28]
#pragma address swAUICalib=0x0000a114   	//[Address fixed, Aevin, 2017/06/28]

MonitorPr_EXT SWORD 	swAVICalib,			//AVI percent (%)
                    	swACICalib,			//ACI percent (%)
                    	swAUICalib;			//AUI percent (%)

MonitorPr_EXT ULONG		mio_ulMfiNow;		//DI value, Move from PH_MFIO_VLI_New.h, DINO, 09/01/2010

MonitorPr_EXT UWORD		mio_uwMfoNow,		//Move from PH_MFIO_VLI_New.h, DINO, 09/01/2010
						mfi_now,			//Digital Input status
						mfo_now;			//Digital Output status

MonitorPr_EXT SWORD 	SPR_swFFD;

#pragma address TB1_slSpdCmdPu=0x0000a11a    //[Address fixed, Aevin, 2017/06/28]
#pragma address SpDt_slSpdFdbPu=0x0000a11e   //[Address fixed, Aevin, 2017/06/28]

MonitorPr_EXT SLONG 	CRM_slFlxFreqPu,
                    	TB1_slSpdCmdPu,
                    	SpDt_slSpdFdbPu;

#pragma address dcbusDC=0x0000a108			  //[Address fixed, Aevin, 2017/06/28]
MonitorPr_EXT UWORD		Vcmd_LL,
			            dcbusDC;

#pragma address CUR_swIqseRefPu=0x0000a122    //[Address fixed, Aevin, 2017/06/28]
#pragma address CUR_swIdseRefPu=0x0000a126    //[Address fixed, Aevin, 2017/06/28]
MonitorPr_EXT SWORD		AD_swIAPu,
                   		AD_swIBPu,
                    	AD_swICPu,
                    	CUR_swIqseRefPu,
			            CUR_swIdseRefPu,
			            swCmdRpm, 
                        swTqFbkPu;

#pragma address uw_SCTEST8=0x0000a138    //[Address fixed, Aevin, 2017/06/28]
MonitorPr_EXT UWORD		uw_SCTEST,
						uw_SCTEST2,
						uw_SCTEST3,
						uw_SCTEST4,
						uw_SCTEST5,
						uw_SCTEST6,
						uw_SCTEST7,
						uw_SCTEST8,
			  			uw_fcomref,		//ADDED BY SCOTTY
			  			uw_fcomfbk;		//ADDED BY SCOTTY
			  			
// fix AD position, Sean, 10/18/2010
MonitorPr_EXT UWORD		AN00,			  			
			  			AN01,
			  			AN02,
			  			AN03,
			  			//AN4,
			  			//AN5,
			  			AN06,
			  			AN07,
			  			AN08,
			  			AN09,
			  			//AN10,
                        //AN11,
                        AN000,
                        AN001,
                        AN002,
                        AN003,
                        AN100,
                        AN101,
                        AN102,
                        AN103,
                        Pgc_uwCpo,  //[For IED PG-Card, Sampo, 01/11/2010]
	  				    Pgc_uwCne,
	  					Pgc_uwDpo,
	  					Pgc_uwDne,
	  					Pgc_uwApo,
	  					Pgc_uwAne,
	  					Pgc_uwBpo,
	  					Pgc_uwBne,
	  					Pgc_uwRpo,
	  					Pgc_uwRne;

MonitorPr_EXT UWORD     uw_PGtest,             //[ED for HW test, Bernie, 2014/08/18]
                        uw_PGReCoDer;

                        
MonitorPr_EXT SLONG_UNION		
						DcbusDCLPF,		//Dcbus (Vdc)
                        TqRefPuLPF;     //[JES Torq Detect Function, Special.Kung, 2022/09/01]


/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
