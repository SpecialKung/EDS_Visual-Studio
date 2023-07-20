/***********************************************************************************************************************
* File Name    : resetprg.c
* Version      : 1.0
* Device(s)    : RX63T
* Description  : Defines post-reset routines that are used to configure the MCU prior to the main program starting. 
*                This is were the program counter starts on power-up or reset.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : 2014.02.21 Version  Description
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include    <machine.h>			/* Defines machine level functions used in this file */
#include    <_h_c_lib.h>			/* Defines MCU configuration functions used in this file */
#include    <stdbool.h>			/* Defines standard variable types used in this file */
#include    <stdint.h>			/* Defines standard variable types used in this file */
#include    "stacksct.h"			/* Defines the size of the stack which configured in this file */
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define PSW_init    0x00010000    // PSW bit pattern Default:(0x00030000), Zeus:0x00010000
#define FPSW_init   0x00000000    // FPSW bit base pattern Default:0x00000100, Zeus:0x00000000
/***********************************************************************************************************************
Pre-processor Directives
***********************************************************************************************************************/
/* Declare the contents of the function 'Change_PSW_PM_to_UserMode' as assembler to the compiler */
#pragma inline_asm Change_PSW_PM_to_UserMode
/***********************************************************************************************************************
Exported global variables and functions
***********************************************************************************************************************/
/***********************************************************************************************************************
External function Prototypes
***********************************************************************************************************************/
extern void usb_cstd_main_task(USB_VP_INT);
//extern void usb_cpu_SdramInit(void);

#ifdef __cplusplus
 extern "C" {
#endif
extern void _INIT_IOLIB(void);
extern void _CLOSEALL(void);
extern void HardwareSetup(void);
#ifdef __cplusplus
 }
#endif

/***********************************************************************************************************************
Private global variables and functions
**********************************************************************************************************************/
//void    usb_cstd_MainTask(USB_VP_INT stacd);
//void    usb_cpu_McuInitialize(void);
//void    usb_cstd_ScheInit(void);

#pragma section ResetPRG	// combine ED&USB, Sean, 20140812
#pragma entry PowerON_Reset_PC
/***********************************************************************************************************************
* Function name: PowerON_Reset_PC
* Description  : This function is the MCU's entry point from a power-on reset.
*                The following steps are taken in the startup code:
*                1. The User Stack Pointer (USP) and Interrupt Stack Pointer (ISP) are both set immediately after entry 
*                   to this function. The USP and ISP stack sizes are set in the file stacksct.h.
*                   Default sizes are USP=4K and ISP=1K.
*                2. The interrupt vector base register is set to point to the beginning of the relocatable interrupt 
*                   vector table.
*                3. The MCU is setup for floating point operations by setting the initial value of the Floating Point 
*                   Status Word (FPSW).
*                4. The MCU operating frequency is set by configuring the Clock Generation Circuit (CGC) in
*                   operating_frequency_set.
*                5. Calls are made to functions to setup the C runtime environment which involves initializing all 
*                   initialed data, zeroing all uninitialized variables, and configuring STDIO if used
*                   (calls to _INITSCT and _INIT_IOLIB).
*                6. Board-specific hardware setup, including configuring I/O pins on the MCU, in hardware_setup.
*                7. Global interrupts are enabled by setting the I bit in the Program Status Word (PSW), and the stack 
*                   is switched from the ISP to the USP.  The initial Interrupt Priority Level is set to zero, enabling 
*                   any interrupts with a priority greater than zero to be serviced.
*                8. The processor is optionally switched to user mode.  To run in user mode, set the macro 
*                   RUN_IN_USER_MODE above to a 1.
*                9. The bus error interrupt is enabled to catch any accesses to invalid or reserved areas of memory.
*
*                Once this initialization is complete, the user's main() function is called.  It should not return.
* Arguments    : none
* Return value : none
***********************************************************************************************************************/
void PowerON_Reset_PC(void)
{
    /* Initialise the MCU processor word */
    #if __RENESAS_VERSION__ >= 0x01010000    
     set_intb((void *)__sectop("C$VECT"));
    #else
     set_intb((unsigned long)__sectop("C$VECT"));
    #endif

    /* Initialize FPSW for floating-point operations */
    #ifdef __ROZ
    #define _ROUND 0x00000001  /* Let FPSW RMbits=01 (round to zero) */
    #else 
    #define _ROUND 0x00000000  /* Let FPSW RMbits=00 (round to nearest) */
    #endif 
    #ifdef __DOFF 
    #define _DENOM 0x00000100  /* Let FPSW DNbit=1 (denormal as zero) */
    #else 
    #define _DENOM 0x00000000  /* Let FPSW DNbit=0 (denormal as is) */
    #endif 
    set_fpsw(FPSW_init | _ROUND | _DENOM); 
    
    /* Condition compilation by the difference of hardware reference */
    //#ifdef USB_SDRAM_USE_PP
    // usb_cpu_SdramInit();
    //#endif /* USB_SDRAM_USE_PP */

    /* Section initialized */
    _INITSCT();
    /* Library initialized */
    /* _INITLIB(); */
    /* Low-level interface initialized */
    /* _INIT_LOWLEVEL(); */
    /* I/O library initialized */
    //_INIT_IOLIB();
    /* Other library initialized */
    /* _INIT_OTHERLIB(); */

    //set_psw(0x20000);  /*User stack pointer(USP) is selected, Interrupt disabled.*/
    //set_psw(0x30000);  /*User stack pointer(USP) is selected, Interrupt enabled.*/
	set_psw(PSW_init);
     
     // combine ED&USB, Sean, 20140812
	HardwareSetup();                // Use Hardware Setup  
	main();
	
    #if 0   //Add later to enable. Also uncomment BusErrorISR() in rx_rsk.c.
    /* Enable the bus error interrupt to catch accesses to illegal/reserved areas of memory */
    /* The ISR for this interrupt can be found in vecttbl.c in the function "BusErrorISR" */
    /* Clear any pending interrupts */
    IR(BSC,BUSERR) = 0;
    /* Make this the highest priority interrupt (adjust as necessary for your application */
    IPR(BSC,BUSERR) = 0x0F; 
    /* Enable the interrupt in the ICU*/
    IEN(BSC,BUSERR) = 1; 
    /* Enable illegal address interrupt in the BSC */
    BSC.BEREN.BIT.IGAEN = 1;
    #endif
}

/***********************************************************************************************************************
* Function name: Change_PSW_PM_to_UserMode
* Description  : Assembler function, used to change the MCU's usermode from supervisor to user.
* Arguments    : none
* Return value : none
***********************************************************************************************************************/
#if __RENESAS_VERSION__ < 0x01010000
static void Change_PSW_PM_to_UserMode(void)
{
    MVFC   PSW,R1
    OR     #00100000h,R1
    PUSH.L R1
    MVFC   PC,R1
    ADD    #10,R1
    PUSH.L R1
    RTE
    NOP
    NOP
}
#endif
/* eof */