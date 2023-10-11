#ifdef FLUXWEAKNESS_C
	#define FLUX_WEAKNESS_EXT
#else
   	#define FLUX_WEAKNESS_EXT extern
#endif
/*======= Modules used (included header files) ==================*/


/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  DEFINES 
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
#define FLOAT_DEG_TO_RAD ((Float32) 0.01745329252F) /* Description: PI/180 in single precision floating point */
#define FLOAT_EIGHT ((Float32) 8.F) /* Description: Numerical constant 8. */
#define FLOAT_FIVE ((Float32) 5.F) /* Description: Numerical constant 5. */
#define FLOAT_FORTY ((Float32) 40.F) /* Description: Numerical constant 40. */
#define FLOAT_FOUR ((Float32) 4.F) /* Description: Numerical constant 4. */
#define FLOAT_HALF ((Float32) 0.5F) /* Description: Numerical contstant 0.5. */
#define FLOAT_HUNDRED_FORTY_FIVE ((Float32) 145.F) /* Description: Numerical constant 145. */
#define FLOAT_INV_THREE ((Float32) 0.333333333F) /* Description: Numerical constant 1/3. */
#define FLOAT_MINUS_ONE ((Float32) -1.F) /* Description: Numerical constant -1. */
#define FLOAT_MINUS_POINT_ONE ((Float32) -0.1F) /* Description: Numerical constant 0.1. */
#define FLOAT_NINE ((Float32) 9.F) /* Description: Numerical constant 9. */
#define FLOAT_ONE ((Float32) 1.F) /* Description: Numerical constant 1. */
#define FLOAT_POINT_ONE ((Float32) 0.1F) /* Description: Numerical constant 0.1. */
#define FLOAT_POINT_ZERO_ONE ((Float32) 0.01F) /* Description: Numerical constant 0.01. */
#define FLOAT_QUARTER ((Float32) 0.25F) /* Description: Numerical contstant 0.25. */
#define FLOAT_RAD_TO_DEG ((Float32) 57.29577951F) /* Description: 180/PI in single precision floating point */
#define FLOAT_SEVEN ((Float32) 7.F) /* Description: Numerical constant 7. */
#define FLOAT_SIX ((Float32) 6.F) /* Description: Numerical constant 6. */
#define FLOAT_SIXTEEN ((Float32) 16.F) /* Description: Floating point 16 for QAC used. */
#define FLOAT_TEN ((Float32) 10.F) /* Description: Numerical constant 10. */
#define FLOAT_THREE ((Float32) 3.F) /* Description: Numerical constant 3. */
#define FLOAT_TWENTY_FIVE ((Float32) 25.F) /* Description: Numerical constant 25. */
#define FLOAT_TWO ((Float32) 2.F) /* Description: Numerical constant 2. */
#define FLOAT_TWO_HUNDRED_EIGHTY ((Float32) 280.F) /* Description: Numerical constant 280. */
#define FLOAT_ZERO ((Float32) 0.F) /* Description: Floating point zero for QAC used. */
#define GAIN_ENABLE_BOUND_RESD1 ((Float32) 0.1F) /* Description: Function enable/disable switching boundary. By checking the minimum resolution of\
	 floating point gain which being compared with, you can choose suitable macro to use. */
#define GAIN_ENABLE_BOUND_RESD2 ((Float32) 0.01F) /* Description: Function enable/disable switching boundary. By checking the minimum resolution of\
	 floating point gain which being compared with, you can choose suitable macro to use. */
#define GAIN_ENABLE_BOUND_RESD3 ((Float32) 0.001F) /* Description: Function enable/disable switching boundary. By checking the minimum resolution of\
	 floating point gain which being compared with, you can choose suitable macro to use. */
#define GAIN_ENABLE_BOUND_RESD4 ((Float32) 0.0001F) /* Description: Function enable/disable switching boundary. By checking the minimum resolution of\
	 floating point gain which being compared with, you can choose suitable macro to use. */
#define HALF_PI ((Float32) 1.570796327F) /* Description: half pi in single precision  floating point */
#define INT_100US ((Float32) 0.0001F) /* Description: interrupt timer for 100us in [sec] */
#define INT_1MS ((Float32) 0.001F) /* Description: interrupt time for 1ms in [sec] */
#define INT_500US ((Float32) 0.0005F) /* Description: interrupt time for 500us in [sec] */
#define INVT_MAX_CUR_COEF ((Float32) 2.5F) /* Description: Maximum current coeficient to inverter rated current. */
#define INV_PI ((Float32) 0.318309886F) /* Description: pi in single precision  floating point */
	#define INV_SQRT2 ((Float32) 0.70710678F) /* Description: 1/sqrt(2) in single precision floating point. */
	#define INV_SQRT3 ((Float32) 0.57735027F) /* Description: 1/sqrt(3) in single precision floating point. */
#define INV_TWO_PI ((Float32) 0.159154943F) /* Description: Inverse 2*pi in single precision floating point */
#define MIN_FREQ_CMD ((Float32) 0.01F) /* Description: Minimum frequency command Step. */
#define NEG_TWO_PI ((Float32) -6.28318531F) /* Description: -2*pi in single precision floating point */
#define PCT_UNIT ((Float32) 0.01F) /* Description: Percentage unit value. */
	//#define PI ((Float32) 3.141592653F) /* Description: pi in single precision  floating point */
	#define SQRT_2 ((Float32) 1.41421356F) /* Description: sqrt(2) in single precision floating point */
#define SQRT_2DIV3 ((Float32) 0.81649658F) /* Description: sqrt(2/3) in single precision floating point. */
	#define SQRT_3 ((Float32) 1.73205081F) /* Description: sqrt(3) in single precision floating point. */
#define SQRT_3DIV2 ((Float32) 1.2247449F) /* Description: sqrt(3/2) in single precision floating point. */
#define SQRT_3DIV4 ((Float32) 0.8660254F) /* Description: sqrt(3/4) in single precision floating point. */
#define THREE_DIV_FOUR ((Float32) 0.75F) /* Description: numerical constant for 3/4 */
#define THREE_DIV_TWO ((Float32) 1.5F) /* Description: numerical constant for 3/2 */
#define TWO_PI ((Float32) 6.28318531F) /* Description: 2*pi in single precision floating point */
	
#define ABS_P2P ((UWORD) 4096) /* Description: Absolute point to point control operation mode */
#define ACR_TQCPG ((UWORD) 1024) /* Description: Current control in TQC PG operation mode */
#define ASR_FOCPG ((UWORD) 512) /* Description: Speed control in FOC PG operation mode */
#define CM_ABS_APRIM ((UWORD) 4773) /* Description: ABS_APRIM(Absolute point control): no VF, with PG, Speed control, point 2 point control, IM, with\
	 ASR, No ACR, Absolute point, No Homing, No Sensorless (CTRLM =5) */
#define CM_ABS_APRPM ((UWORD) 5029)
#define CM_FOCIM ((UWORD) 16387) /* Description: FOCIM Control Mode, no VF, no PG, Speed control, IM, No ASR, No ACR, Relative point, No Homing,\
	 Sensorless (CTRLM =3) */
#define CM_FOCPGIM ((UWORD) 548) /* Description: FOCPGIM Control Mode: no VF, with PG, Speed control, IM, with ASR, No ACR, Relative point, No Homing,\
	 No Sensorless (CTRLM =4) */
#define CM_FOCPGPM ((UWORD) 804)
#define CM_FOCPM ((UWORD) 16643)
#define CM_REL_APRIM ((UWORD) 677) /* Description: REL_APRIM(Relative point control): no VF, with PG, Speed control, point 2 point control, IM, with\
	 ASR, No ACR, Relative point, No Homing, No Sensorless (CTRLM =5) */
#define CM_REL_APRPM ((UWORD) 933)
#define CM_REL_HOMIM ((UWORD) 8872)
#define CM_REL_HOMPM ((UWORD) 9128)
#define CM_SVC ((UWORD) 17) /* Description: SVC Control Mode, VF, no PG, Speed control, IM, No ASR, No ACR, Relative point, No Homing, No Sensorless\
	 (CTRLM =1) */
#define CM_TQCIM ((UWORD) 16454) /* Description: TQCIM(IM torque control): no VF, no PG, Speed control, No point 2 point control, IM, no ASR, No ACR,\
	 Relative point, No Homing, Sensorless (CTRLM =6) */
#define CM_TQCPGIM ((UWORD) 1127) /* Description: TQCPGIM(IM torque control with PG): no VF, with PG, Speed control, No point 2 point control, IM, no\
	 ASR, with ACR, Relative point, No Homing, No Sensorless (CTRLM =7) */
#define CM_TQCPGPM ((UWORD) 1383)
#define CM_TQCPM ((UWORD) 326)
#define CM_VF ((UWORD) 16) /* Description: VF Control Mode, no PG, Speed control, IM, No ASR, No ACR, Relative point, No Homing, No Sensorless (CTRLM\
	 = 0) */
#define CM_VFPG ((UWORD) 50) /* Description: VFPG Control Mode: VF, with PG, Speed control, IM, No ASR, No ACR, Relative point, No Homing, No\
	 Sensorless (CTRLM =2) */
#define COUNT_TRIRTY_SECOND_IN_1MS ((UWORD) 30000) /* Description: Counter value in 1ms-function when 5 second. */
#define FOC_SENSORLESS ((UWORD) 16384) /* Description: FOC sensorless operation mode */
#define HOMING_MODE ((UWORD) 8192) /* Description: Homing mode operation mode */
#define P2P_MODE ((UWORD) 128) /* Description: Point to Point operation mode */
#define PM_MOTOR ((UWORD) 256) /* Description: PM motor operation mode */
#define TQC_MODE ((UWORD) 64) /* Description: Torque control operation mode */
#define VF_MODE ((UWORD) 16) /* Description: VF operation mode */
#define WITH_PG ((UWORD) 32) /* Description: PG operation mode */
	
//#define ACCON ((Bool) 1) /* Description: acceleration condition */        //clear Warning, Special.kung, 03/08/2023
#define AUTO_CT_GAIN ((UBYTE) 10) /* Description: Gain of Current Sensor Calibration Testing */
#define AUTO_CURCALIB ((UBYTE) 11) /* Description: New Current Gain Calibration */
#define AUTO_DBCSECA ((UBYTE) 7) /* Description: Dead Band Compensation SElf CAlibration testing */
#define AUTO_HFSS ((UBYTE) 2) /* Description: High Frequency Lock testing */
#define AUTO_IM_FLXCRV ((UBYTE) 6) /* Description: IM flux curve testing */
#define AUTO_IM_STANDSTILL ((UBYTE) 8) /* Description: Standstill auto tuning testing for IM */
#define AUTO_JM_ESTM ((UBYTE) 12) /* Description: Jm Estimation in sensorless FOC */
#define AUTO_LFSL ((UBYTE) 3) /* Description: Mechanical Shaft Lock low Frequency testing */
#define AUTO_PM_HFSS ((UBYTE) 13) /* Description: HFSS tuning of PM motor to get Rs&Ld&Lq */
#define AUTO_PM_MAG_ANG ((UBYTE) 4) /* Description: PM magnetic angle testing */
#define AUTO_PM_PR ((UBYTE) 5) /* Description: PM parameter testing */
#define AUTO_PM_STANDSTILL ((UBYTE) 9) /* Description: Standstill auto tuning testing for PM  */
#define AUTO_PM_ZTHETA ((UBYTE) 14) /* Description: PM Z-pulse electric angle tuning for ABZ type encoder */
#define AUTO_ROTARY ((UBYTE) 1) /* Description: Rotary Testing */
#define BELOW_LOW_LIM ((UBYTE) 2) /* Description: Input is below lower limit. */
#define BRAKE ((Bool) 0)
//#define CLR ((Bool) 0)
//#define DECON ((Bool) 0) /* Description: deceleration condition */        //clear Warning, Special.kung, 03/08/2023
//#define END ((Bool) 1) /* Description: end condition */
//#define ERR ((Bool) 0) /* Description: error condition */
//#define FALSE ((Bool) 0)
//#define FORWARD ((Bool) 0)                                                //clear Warning, Special.kung, 03/08/2023
#define HI ((Bool) 1)
#define LO ((Bool) 0)
#define NEG_TORQ_LIMIT ((UBYTE) 8) /* Description: Analog input seletion for negtive torque limit. */
#define NORMAL ((UBYTE) 0) /* Description: Normal state, no saturation occurs. */
#define OFF ((Bool) 0)
#define ON ((Bool) 1)
#define OVER_UP_LIM ((UBYTE) 1) /* Description: Input is over upper limit. */
#define POSNEG_TORQ_LIMIT ((UBYTE) 10) /* Description: Analog input seletion for positive and negtive torque limit. */
#define POS_TORQ_LIMIT ((UBYTE) 7) /* Description: Analog input seletion for positive torque limit. */
#define REG_TORQ_LIMIT ((UBYTE) 9) /* Description: Analog input seletion for regenerative torque limit. */
#define RELEASE ((Bool) 1)
//#define REVERSE ((Bool) 1)        //clear Warning, Special.kung, 03/08/2023
//#define RUN ((Bool) 1)            //clear Warning, Special.kung, 03/08/2023
#define SET ((Bool) 1)
#define SPD_MODE ((Bool) 0)
//#define STOP ((Bool) 0)
#define TORQ_MODE ((Bool) 1)
//#define TRUE ((Bool) 1)

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  INCLUDES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  DEFINES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  TYPEDEFS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  VARIABLES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

FLUX_WEAKNESS_EXT void RESTART_AsmDaxisSynCurRefHarness(void);
FLUX_WEAKNESS_EXT void AsmDCurRef_voResetInitValue(void);

FLUX_WEAKNESS_EXT void AsmDaxisSynCurRefHarness(void);

FLUX_WEAKNESS_EXT Bool CTRLER_blSetStopIntegFlag(Bool blSaturateFlag, Float32 flCtrlerErr, Float32 flCtrlerOut, Float32 flBackCalcGain);

FLUX_WEAKNESS_EXT void CTRLER_voPiCtrlShareState(tPI_CTRLER_IN * stPiCtrlerInPtr, tPI_CTRLER_COEF * stPiCoefPtr, Float32 flIntegStateZ1, tPI_CTRLER_OUT *
   stPiCtrlerOutPtr);

FLUX_WEAKNESS_EXT Float32 FILTER_flLpf(Float32 flLpfIn, Float32 flLpfGain, Bool blLpfReset, tREUSE_LPF * pISV);
FLUX_WEAKNESS_EXT Float32 FILTER_flLpfWithSharedState(Float32 flLpfIn, Float32 flLpfGain, Float32 flLpfState);

FLUX_WEAKNESS_EXT Float32 MATOOL_flGetMax(Float32 flValueOne, Float32 flValueTwe);

FLUX_WEAKNESS_EXT void MATOOL_voDynSatWiSatFlag(Float32 flInput, Float32 flUpLimit, Float32 flLowLimit, tSAT_OUT * stSatOutPtr);

FLUX_WEAKNESS_EXT Float32 VECTOR_flCalAsmAmrCurRef(tASM_AMR_COEF * stAsmAmrCoefPtr, tASM_AMR_IN * stAsmAmrInPtr, tASM_AMR_PR * stAsmAmrPrPtr, tREUSE_ASMAMR *
   pISV);
FLUX_WEAKNESS_EXT Float32 VECTOR_flCalAsmFluxWknCurRef(tASM_FLUX_WKN_COEF * stAsmFluxWknCoefPtr, tASM_FLUX_WKN_IN * stAsmFluxWknInPtr, tREUSE_ASMFLUXWKN * pISV);

FLUX_WEAKNESS_EXT void VECTOR_voCalAsmDaxisSynCurRef(tASM_DAXIS_CUR_REF_COEF * stAsmDaxisCurRefCoefPtr, tASM_DAXIS_CUR_REF_IN * stAsmDaxisCurRefInPtr,
   tASM_DAXIS_CUR_REF_OUT * stAsmDaxisCurRefOutPtr, tREUSE_ASMIDREF * pISV, tASM_DAXIS_CUR_REF_PR * stAsmDaxisCurRefPrPtr);

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  END OF FILE
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

