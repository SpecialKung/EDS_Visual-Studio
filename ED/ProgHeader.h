#include <machine.h>
#include <stdio.h>
#include <stdlib.h>         //clear Warning, Special.kung, 03/08/2023
#include <string.h>         //clear Warning, Special.kung, 03/08/2023


#include "iodefine.h"
#include "TypeDefine.h"
#include "Version.h"

#include "PR_MacroEQU.h"
#include "PR_Handel.h"
#include "PR_Data.h"
#include "PR_Romdata.h"
#include "PR_Const.h"
#include "PR_LCDescript.h"
#include "PR_Motor.h"

#include "Main.h"


#include "PH_KeyPad.h"
#include "PH_MFIO.h"
#include "PH_IIC.h"			// add by DINO, 03/01/2010
#include "PH_USB.h"			// add by Sean, 02/22/2010
#include "PH_LEDKEY.h"		// add by DINO, 03/09/2010
#include "PH_RCAN.h"		// [Can function, Bernie, 08/16/2011]


#include "SCI_IntPro.h"
#include "SCI2_CommReg.h"
#include "SCI1_EnDat.h"		// add by DINO, 09/16/2008
#include "SCI1_Hiper.h"		// add by DINO, 10/08/2008
#include "SCI1_Remote.h"
#include "SCI3_Remote.h"
#include "SCI4_PGComm.h"	// Add by DINO, 08/19/2010

#include "RCAN_ET.h"		// add by dino, 06/21/2007


#include "TB_1ms.h"
#include "TB_100us.h"
#include "TB_WG.h"

#include "ADProg.h"
#include "ProtectFun.h"
#include "COEFhandel.h"
#include "mathtool_c.h"
#include "mathf.h"


#include "BK_FFD.h"
#include "BK_FluxControl.h"
#include "BK_RegSpeed.h"
#include "BK_RegCurrent.h"
#include "BK_TSyn2Stat.h"
#include "BK_TStat2Syn.h"
#include "BK_Tabc2dq.h"
#include "BK_Tdq2abc.h"
#include "BK_CurrentMod.h"
#include "BK_PWMGen.h"
#include "BK_ATuning.h"
#include "BK_SpDtPG1.h"
#include "BK_DeadTimeComp.h"
#include "BK_TqCmd.h"
#include "BK_EstJ.h"
#include "BK_TestSource.h"
#include "BK_PG2Ref.h"

#include "CM_VF.h"
#include "CM_FOC.h"
#include "CM_FOCPG.h"
#include "CM_FOCPM.h"
#include "CM_TQCPG.h"

#include "A_MonitorPr.h"
#include "BK_APR.h"

#include "USB_CDC.h"	// combine ED&USB, Sean, 20140819

#include "DLC.h"      //[DLC, Bernie, 2014/10/06]

#include "switch.h"		// Bootloader enable, Sean, 20141022

#include "SYSInit.h"    //clear Warning, Special.kung, 03/08/2023

#include "modbus_dec.h"	// modbus framework, Sean, 20141225

#include "IODLC.h"      //[IODLC,Lyabryan,2016/09/21]

#include "Flux_weakness.h" //Flux Weakness, JJ, 2018/10/31


