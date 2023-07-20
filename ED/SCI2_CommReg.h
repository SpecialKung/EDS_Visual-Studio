/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: Main.H

Partner Filename: Main.C

Description: This is a inclue file of Main.C

Complier: 

	
History:

===============================================================*/
#ifdef _CommReg_C
   #define CommReg_EXT
#else
   #define CommReg_EXT extern
#endif

CommReg_EXT void VFDStatus(void);
CommReg_EXT void PCRemote2000H(UWORD datac);
CommReg_EXT void PCRemote2001H(UWORD datac);
CommReg_EXT void PCRemote20xxH(UBYTE func,UWORD datac);
CommReg_EXT void Update_C21xx(void);
CommReg_EXT void Update_C22xx(void);
CommReg_EXT void Update2119(void);
CommReg_EXT void Update2116(void);
CommReg_EXT void Update_CFFxx(void);
CommReg_EXT void Update_C40xx(void);  //[DLC, Bernie, 2014/10/06]  

//CommReg_EXT void Update_C2Axx(void);

CommReg_EXT UWORD          C20xx[C20MAX],
                           C21xx[C21MAX],
                           C22xx[C22MAX],
                           CFFxx[CALIMAX],  // address ffxx  //for calibration
                           KC23xx[C23MAX],
                           Descript[C24MAX],
                           C40xx[DLCMAX],   //adjust floor position,Henry,2019/01/07
                           DLCxx[DLCMAX],
//                         C2Axx[C2AMAX],
                           uwElecAngle;		//Add by Sampo

CommReg_EXT UBYTE          ubpage;          //[User page reserve jump, Bernie, 08/05/2011]         

                           
/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
