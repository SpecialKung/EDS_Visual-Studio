/*===============================================================
Author: Delta Electronic, INC. EMBU, DEIN

Project: VFD-V pro

Filename: SYSInit.H

Partner Filename: SYSInit.C

Description: This is a inclue file of SYSInit.C

Complier: 

	
History:

===============================================================*/
#ifdef _mathtool_C
   #define mathtool_EXT 
#else
   #define mathtool_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*========== @ Defines =========================================*/


/* Struct Type define =========================================*/

/* Function Call ==============================================*/
mathtool_EXT SLONG LowPass(ULONG ak, SLONG xn, SLONG yn);
mathtool_EXT SLONG lowpass_sl(UWORD ak, SWORD xn, SLONG yn);
mathtool_EXT ULONG lowpass_ul(UWORD ak, UWORD xn, ULONG yn);
mathtool_EXT SLONG LowPass_Hz(ULONG ak, SLONG xn, SLONG yn);
//mathtool_EXT SLONG S32xS32divS32_c(int x, int y, int z);
mathtool_EXT SLONG uw_Sqrt32c(ULONG x);
mathtool_EXT UWORD uw_Sqrt32c_1(ULONG x);
mathtool_EXT UWORD arccos(SWORD c);
mathtool_EXT SWORD Notch(int xn, int wn, int damp_z);
mathtool_EXT void Init_Notch(void);


mathtool_EXT UWORD U16xU16divU16 (UWORD x,UWORD y,UWORD z);
mathtool_EXT SWORD S16xS16divS16 (SWORD x,SWORD y,SWORD z);
mathtool_EXT UWORD U32divU16(ULONG x, UWORD y);
mathtool_EXT ULONG U32xU32divU32 (ULONG x, ULONG y, ULONG z);
mathtool_EXT SLONG S32xS32divS32(SLONG x, SLONG y, SLONG z);
mathtool_EXT ULONG U32xU16shlr16 (ULONG x, UWORD y);
mathtool_EXT int S32xS16shlr16 (int x, int y);
mathtool_EXT ULONG U32xU32shlr32 (ULONG x, ULONG y);
mathtool_EXT ULONG U32xU32getlo (ULONG x, ULONG y);
mathtool_EXT SLONG S32xS32shlr31 (SLONG x, SLONG y);
mathtool_EXT SLONG S32xS32shlr32 (SLONG x, SLONG y);
mathtool_EXT SLONG sl_limit(SLONG x, SLONG y, SLONG z);
mathtool_EXT SLONG sl_limit_modify(SLONG x, SLONG y, SLONG z);  // revise negative limit by JOSH 2017/03/15
mathtool_EXT UWORD ReadRamData(UWORD x);
mathtool_EXT UWORD memadd_rd(UWORD x);
mathtool_EXT UWORD memadd_rd1(UWORD x);


/* Exported Variable List ======================================*/
                          
/*== Local Variable List (Variables not open to other files)  ==*/
mathtool_EXT SWORD  Nh_swWn,
                    Nh_swDampZ;
                    
mathtool_EXT SLONG  Nh_sltmp4,
                    Nh_sltmp5,
                    Nh_sltmp4_Old,
                    Nh_sltmp6_Old;
/* Flag Define   ==============================================*/

/************************************************************************
 Copyright (c) 2005 EMBU DELTA
 All rights reserved.
*************************************************************************
 End of this File (EOF):
 !!!!!!Do not put anything after this part!!!!!!!!!!!
*************************************************************************/
