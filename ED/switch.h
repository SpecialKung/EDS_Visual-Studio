//*****************************************************************/
//  @File Name: Decipher.h  
//  @Partner file: Decipher.c                                     
//  @Project:                                       
//  @Compiler: HEW for M16C64A                    
//  @Company: Delta Elec.INC CopyRight 2011                                  
//*****************************************************************/  
#ifdef _SWITCH_C_
   #define SWITCH_EXT 
#else
   #define SWITCH_EXT extern
#endif

//****************************************************************
// Typedefs
//****************************************************************
#define SWITCH_BLD_START_ADDR	(0xFFFF4000)		//bootloader的start address for SCI BLD in Rx63T	// bootloader over usb for online mode, Sean, 20141030

#define SWITCH_ACK01FIRST_VAL	(0x55)
#define SWITCH_ACK01SECOND_VAL	(0xAA)

#define	BOOTLOADER_ENABLE	(1)// Bootloader enable, Sean, 20141022

//****************************************************************
// Constant Data Table Declaration
//****************************************************************


//****************************************************************
// @Prototypes Of  Functions
//****************************************************************
SWITCH_EXT void SWITCH_GOTO_App_Section(void);
SWITCH_EXT void SWITCH_GOTO_BLD_Section(void);

SWITCH_EXT void SWITCH_Set_App_StartAddr(UBYTE *start);
SWITCH_EXT void SWITCH_Set_BLD_StartAddr(UBYTE *start);

SWITCH_EXT void SWITCH_Initial_Val(void);		//initial all val in SWITCH.h

//****************************************************************
// File Variables Declaration
//****************************************************************
SWITCH_EXT 	ULONG	SWITCH_L_Address;
SWITCH_EXT	ULONG	*SWITCH_p_Address;

SWITCH_EXT  UBYTE   SWITCH_APP_StartAddr[4];	//APP start address   目前預設 0xfff80000 in ED board
SWITCH_EXT	void	(*SWITCH_UserApp) (void);		

SWITCH_EXT  UBYTE   SWITCH_BLD_StartAddr[4];	//BLD start address目前預設0xFFFFC000  in ED board
SWITCH_EXT	void	(*SWITCH_BLD) (void);

SWITCH_EXT	UBYTE	SWITCH_ACK01FIRST[4];		//when in App, reply 55,55,55,55
SWITCH_EXT	UBYTE	SWITCH_ACK01Second[4];		//when in BLD, reply AA,AA,AA,AA

SWITCH_EXT	UBYTE	switchFlag;					//bootloader/app control flag	// Bootloader enable, Sean, 20141022
SWITCH_EXT	UBYTE	switch_TxDon;				// bootloader over usb for online mode, Sean, 20141030	
SWITCH_EXT	UWORD	switch_TxDonWait;




