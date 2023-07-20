/****************************************************************/
//  @File Name: Decipher.c                                          
//  @Description: This file contains FW decipher of software   
//                process.
//  @Partner file:Decipher.h 
//  @Project:                                          
//  @Compiler: HEW(Ver.4.15) for M16C64A
//  @Company:  Delta Elec.INC.  CopyRight 2011                               
//****************************************************************/ 
/*-----------------------------start of file---------------------*/
/*-----------------------------start of file---------------------*/
#ifndef _SWITCH_C_
#define _SWITCH_C_
#endif
/*----------------------------------------------------------------*/
//*****************************************************************/
// @Project Includes
//*****************************************************************/
//#include    "iodefine.h"
//#include 	"CRC.H"
//#include	"typedefine.h"
//#include 	"switch.h"
#include	"ProgHeader.h"


void SWITCH_GOTO_App_Section(void)
{
	//DINT();
	//if wabt to use App's fixed vect table, use this one
	//BLD_L_Address = (uint32_t)BLD_FWCheckSumStartAddr[0]<<24 | (uint32_t)BLD_FWCheckSumStartAddr[1]<<16 | (uint32_t)BLD_FWCheckSumStartAddr[2]<<8 | (uint32_t)BLD_FWCheckSumStartAddr[3]; 
	//BLD_p_RunUserProgramAddress = (uint32_t *)(BLD_L_Address+BLD_RESET_OFFSET);
	// 強制將 p_RunUserProgramAddress 位址指標轉型成函式指標，之後將值給 UserApp
	//BLD_UserApp = (void (*) (void)) *BLD_p_RunUserProgramAddress;
	
	//now we dont user App's vect table
	SWITCH_L_Address = (ULONG)SWITCH_APP_StartAddr[0]<<24 | 
					   (ULONG)SWITCH_APP_StartAddr[1]<<16 | 
					   (ULONG)SWITCH_APP_StartAddr[2]<<8 | 
					   (ULONG)SWITCH_APP_StartAddr[3];
	//for testing------------
	//SWITCH_L_Address = 0xFFF00000;	//for rx63N
	
	SWITCH_p_Address = (ULONG *)(SWITCH_L_Address);
	SWITCH_UserApp = (void (*) (void)) SWITCH_p_Address;
	SWITCH_UserApp();	// 將 UserApp 當作副程式執行。
}

void SWITCH_GOTO_BLD_Section(void)
{
	//DINT();
	//now we dont user App's vect table
	SWITCH_L_Address = (ULONG)SWITCH_BLD_StartAddr[0]<<24 | 
					   (ULONG)SWITCH_BLD_StartAddr[1]<<16 | 
					   (ULONG)SWITCH_BLD_StartAddr[2]<<8 | 
					   (ULONG)SWITCH_BLD_StartAddr[3];
	
	//SWITCH_L_Address = 0xFFFF4000;	// test, Sean, 20141030
	
	SWITCH_p_Address = (ULONG *)(SWITCH_L_Address);
	SWITCH_BLD = (void (*) (void)) SWITCH_p_Address;
	SWITCH_BLD();	// 將 BLD 當作副程式執行。
}


void SWITCH_Set_App_StartAddr(UBYTE *start)
{
	int count;
	for(count = 0;count<4;count++){
		SWITCH_APP_StartAddr[count] = *(start+count);
	}
}

void SWITCH_Set_BLD_StartAddr(UBYTE *start)
{
	int count;
	for(count = 0;count<4;count++){
		SWITCH_BLD_StartAddr[count] = *(start+count);
	}
}

void SWITCH_Initial_Val(void)
{
	int i;
	ULONG Addr = SWITCH_BLD_START_ADDR;
	//這裡要修改  SWITCH 初始化的
	SWITCH_BLD_StartAddr[0] = Addr>>24;
	SWITCH_BLD_StartAddr[1] = (UBYTE)(Addr>>16);
	SWITCH_BLD_StartAddr[2] = (UBYTE)(Addr>>8);
	SWITCH_BLD_StartAddr[3] = (UBYTE)Addr;

	for(i = 0;i<4;i++){
		SWITCH_ACK01FIRST[i] = SWITCH_ACK01FIRST_VAL;
		SWITCH_ACK01Second[i] = SWITCH_ACK01SECOND_VAL;
	}
}

#if 0
//the original go to App function
void BLD_GOTO_App_Section(void)
{
	//DINT();
	//if wabt to use App's fixed vect table, use this one
	//BLD_L_Address = (uint32_t)BLD_FWCheckSumStartAddr[0]<<24 | (uint32_t)BLD_FWCheckSumStartAddr[1]<<16 | (uint32_t)BLD_FWCheckSumStartAddr[2]<<8 | (uint32_t)BLD_FWCheckSumStartAddr[3]; 
	//BLD_p_RunUserProgramAddress = (uint32_t *)(BLD_L_Address+BLD_RESET_OFFSET);
	// 強制將 p_RunUserProgramAddress 位址指標轉型成函式指標，之後將值給 UserApp
	//BLD_UserApp = (void (*) (void)) *BLD_p_RunUserProgramAddress;
	
	//now we dont user App's vect table
	BLD_L_Address = (ULONG)BLD_FWCheckSumStartAddr[0]<<24 | (ULONG)BLD_FWCheckSumStartAddr[1]<<16 | (ULONG)BLD_FWCheckSumStartAddr[2]<<8 | (ULONG)BLD_FWCheckSumStartAddr[3]; 
	BLD_p_RunUserProgramAddress = (ULONG *)(BLD_L_Address);//BLD_USER_APP_FIXED_VECT_TBL_BASE_ADDR
	BLD_UserApp = (void (*) (void)) BLD_p_RunUserProgramAddress;
	BLD_UserApp();	// 將 UserApp 當作副程式執行。
}
#endif


/*------------------------End of file----------------------------*/
#ifdef _SWITCH_C_
#undef _SWITCH_C_
#endif
/*---------------------------------------------------------------*/
