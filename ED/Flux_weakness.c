#ifndef FLUXWEAKNESS_C
	#define FLUXWEAKNESS_C
#endif 


/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  DEFINES (OPT)
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  INCLUDES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "ProgHeader.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  ENUMS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  DEFINES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

#define ASM_AMR_CUR_REF_LOW_LIM ((Float32) 0.2F)
#define ASM_AMR_CUR_REF_UP_LIM ((Float32) 0.F)
#define ASM_DAXIS_CUR_REF_LOW_LIM ((Float32) 0.2F)

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  TYPEDEFS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  VARIABLES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
	tREUSE_LPF S_stAsmAmrCurRefLpfState = {
		0.F /* Description: 1st order low-pass filter state variable */
	};
	tREUSE_ASMFLUXWKN S_stAsmFluxWknCurRefState = {
		0.F
	};
	tREUSE_ASMAMR S_stAsmAmrCurRefState = {
		0,
		0.F,
		&S_stAsmAmrCurRefLpfState
	};
	
	static tREUSE_ASMIDREF S_stAsmDaxisSynCurRefState = {
		&S_stAsmAmrCurRefState,
		&S_stAsmFluxWknCurRefState
	};
	
	Float32 SAsmDCurRef1_f__AsmAmrIntegGain;
	Float32 SAsmDCurRef1_f__StatorResistOhm;
	Float32 SAsmDCurRef1_f__WknCurRefLimAmp;
	Float32 SAsmDCurRef1_f__nMotorTorqConst;
	Float32 SAsmDCurRef1_f__orSigmaInductLh;
	Float32 SAsmDCurRef1_f__pfTimeConstTsec;
	Float32 SAsmDCurRef1_f__rMutualInductLh;
	Float32 SAsmDCurRef1_f__torElectSpdRdps;
	Float32 SAsmDCurRef1_f__torNoLoadCurAmp;
	Float32 SAsmDCurRef1_flFluxWknCurRefAmp;
	Float32 SAsmDCurRef1_flIntTimeTsec;
	Float32 SAsmDCurRef1_flInvtCurLimAmp;
	Float32 SAsmDCurRef1_flMotorPolePairs;
	Float32 SAsmDCurRef1_flOutVoltLimVt;
	Float32 SAsmDCurRef1_flOutVoltMagVt;
	Float32 SAsmDCurRef1_flPrAsmAmrPropGain;
	
	SWORD swInvtCurLimAmp_test;
	SWORD swMotorNoLoadCurAmp_test;
	SWORD swMotorPolePairs_test;
	SWORD swMotorMutualInductLh_test;
	SWORD swMotorSigmaInductLh_test;
	SWORD swMotorStatorResistOhm_test;
	SWORD swStatorElectSpdRdps_test;
	SWORD swOutVoltLimVt_test;
	SWORD swOutVoltMagVt_test;
	
	SWORD swMotorTorqConst_test;
	SWORD swFluxWknCurRefAmp_test;
	SWORD swFluxWknCurRefLimAmp_test;
	
	SWORD swMotorTorqConst_test_Pu;
	SWORD swFluxWknCurRefAmp_test_Pu;
	SWORD swFluxWknCurRefLimAmp_test_Pu;

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        CTRLER_blSetStopIntegFlag
 *** 
 ***  DESCRIPTION:
 ***        Antiwindup judgement.           
 ***        Version |    DATE    |    Author    |    Description
 ***        0.1       2017-04-13  Brian.Yen.Chen  Create function.
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        Bool               blSaturateFlag      Saturation flag of saturation judgement. 0: OFF; 1: ON.
 ***        Float32            flCtrlerErr         Error of controller.
 ***        Float32            flCtrlerOut         Output of controller.
 ***        Float32            flBackCalcGain      Output of controller.
 ***
 ***  RETURNS:
 ***        Bool
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
Bool CTRLER_blSetStopIntegFlag(Bool blSaturateFlag, Float32 flCtrlerErr, Float32 flCtrlerOut, Float32 flBackCalcGain)
{
    Bool blStopIntegFlag;

    if (blSaturateFlag == ON) 
    {
        blStopIntegFlag = ((flCtrlerErr * flCtrlerOut) > FLOAT_ZERO) && (flBackCalcGain < GAIN_ENABLE_BOUND_RESD2);
    }
    else 
    {
        blStopIntegFlag = OFF;
    }
    return blStopIntegFlag;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        CTRLER_voPiCtrlShareState
 *** 
 ***  DESCRIPTION:
 ***        Discrete PI controller by finite difference approximation . With outer-state which created for the purpose of more flexibility of auto-cod
 ***        e.
 ***        Version |    DATE    |    Author    |    Description
 ***        0.1       2016-05-13  Brian.Yen.Chen  Create basic function.
 ***        0.2       2016-05-31  Jinlong.Lin     Create the CTRLER library.
 ***        0.3       2017-08-31  Brian.Yen.Chen  Add back-calculation method.
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        tPI_CTRLER_IN *    stPiCtrlerInPtr     
 ***        tPI_CTRLER_COEF *  stPiCoefPtr         
 ***        Float32            flIntegStateZ1      
 ***        tPI_CTRLER_OUT *   stPiCtrlerOutPtr    
 ***
 ***  RETURNS:
 ***        void
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
void CTRLER_voPiCtrlShareState(tPI_CTRLER_IN * stPiCtrlerInPtr, tPI_CTRLER_COEF * stPiCoefPtr, Float32 flIntegStateZ1, tPI_CTRLER_OUT *
  stPiCtrlerOutPtr)
{
    Float32 flPiOut;

    Float32 flTempIntegTerm;

    if (stPiCtrlerInPtr->blStopIntegFlag == ON) 
    {
        flTempIntegTerm = FLOAT_ZERO;
    }
    else 
    {
        flTempIntegTerm = (stPiCtrlerInPtr->flCtrlerErr * stPiCoefPtr->flDiscreteIntegGain) + stPiCtrlerInPtr->flBackCalValue;
    }
    stPiCtrlerOutPtr->flIntegStateOut = flTempIntegTerm + flIntegStateZ1;
    flPiOut = (stPiCoefPtr->flPropGain * stPiCtrlerInPtr->flCtrlerErr) + stPiCtrlerOutPtr->flIntegStateOut;
    stPiCtrlerOutPtr->flPiCtrlOut = flPiOut;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        FILTER_flLpf
 *** 
 ***  DESCRIPTION:
 ***        1st order low-pass filter using backforward method (Floating Point Type)
 ***        Version |    DATE    |    Author    |    Description
 ***        1.0       2014-07-01   Jin-Long Lin   First Version by using forward method.
 ***        1.1       2014-11-25   Jin-Long Lin   Change the discrete method from forward method to backward method.
 ***        1.2       2015-05-22   Jin-Long Lin   Change the function name to "REUSE_LpfFloating".
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        Float32            flLpfIn             1st order low-pass filter input value with single precesion floating point
 ***        Float32            flLpfGain           1st order low-pass filter gain with single precesion floating point, gain = (Sampling Time)/(Sampli
 ng Time+[time const/2pi])
 ***        Bool               blLpfReset          1st order low-pass filter state reset signal.
 ***        tREUSE_LPF *       pISV                
 ***
 ***  RETURNS:
 ***        Float32
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
Float32 FILTER_flLpf(Float32 flLpfIn, Float32 flLpfGain, Bool blLpfReset, tREUSE_LPF * pISV)
{
    Float32 flLpfOut;

    if ((flLpfGain < FLOAT_ZERO) || (flLpfGain > FLOAT_ONE)) 
    {
        flLpfOut = flLpfIn;
    }
    else 
    {
        Float32 flLpfOutputDelay;

        if (blLpfReset == SET) 
        {
            flLpfOutputDelay = FLOAT_ZERO;
        }
        else 
        {
            flLpfOutputDelay = pISV->flStateOut;
        }
        pISV->flStateOut = (flLpfGain * (flLpfIn - flLpfOutputDelay)) + flLpfOutputDelay;
        flLpfOut = pISV->flStateOut;
    }
    return flLpfOut;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        FILTER_flLpfWithSharedState
 *** 
 ***  DESCRIPTION:
 ***        1st order low-pass filter using backforward method (Floating Point Type) with outside-state as input parameter.
 ***        Version |    DATE    |    Author    |    Description
 ***        1.0       2017-11-20   Brian.Yen.Chen   First Version
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        Float32            flLpfIn             1st order low-pass filter input value with single precesion floating point
 ***        Float32            flLpfGain           1st order low-pass filter gain with single precesion floating point, gain = (Sampling Time)/(Sampli
 ng Time+[time const/2pi])
 ***        Float32            flLpfState          
 ***
 ***  RETURNS:
 ***        Float32
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
Float32 FILTER_flLpfWithSharedState(Float32 flLpfIn, Float32 flLpfGain, Float32 flLpfState)
{
    Float32 flSharedStateLpfOut;

    if ((flLpfGain < FLOAT_ZERO) || (flLpfGain > FLOAT_ONE)) 
    {
        flSharedStateLpfOut = flLpfIn;
    }
    else 
    {
        flSharedStateLpfOut = (flLpfGain * (flLpfIn - flLpfState)) + flLpfState;
    }
    return flSharedStateLpfOut;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        MATOOL_flGetMax
 *** 
 ***  DESCRIPTION:
 ***        Get bigger one by comparing inputs value.
 ***        
 ***        Version |    DATE    |        Author         |    Description
 ***        0.1       2018-08-17        YuShian.Lin          First Version.
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        Float32            flValueOne          First value which waiting for comparing.
 ***        Float32            flValueTwe          Second value which waiting for comparing.
 ***
 ***  RETURNS:
 ***        Float32
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
Float32 MATOOL_flGetMax(Float32 flValueOne, Float32 flValueTwe)
{
    Float32 flValueMax;

    if (flValueOne > flValueTwe) 
    {
        flValueMax = flValueOne;
    }
    else 
    {
        flValueMax = flValueTwe;
    }
    return flValueMax;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        MATOOL_voDynSatWiSatFlag
 *** 
 ***  DESCRIPTION:
 ***        Saturation function with dynamic upper-lower constraint with saturation flag.
 ***        Version |    DATE    |    Author    |    Description
 ***        1.0       2017-11-20   Brian.Yen.Chen   First Version
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        Float32            flInput             Dynamic saturation input value.
 ***        Float32            flUpLimit           Dynamic saturation upper limit value.
 ***        Float32            flLowLimit          Dynamic saturation lower limit value.
 ***        tSAT_OUT *         stSatOutPtr         
 ***
 ***  RETURNS:
 ***        void
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
void MATOOL_voDynSatWiSatFlag(Float32 flInput, Float32 flUpLimit, Float32 flLowLimit, tSAT_OUT * stSatOutPtr)
{
    if (flInput > flUpLimit) 
    {
        stSatOutPtr->flSatOut = flUpLimit;
        stSatOutPtr->ubSatFlag = OVER_UP_LIM;
    }
    else 
    {
        if (flInput < flLowLimit) 
        {
            stSatOutPtr->flSatOut = flLowLimit;
            stSatOutPtr->ubSatFlag = BELOW_LOW_LIM;
        }
        else 
        {
            stSatOutPtr->flSatOut = flInput;
            stSatOutPtr->ubSatFlag = NORMAL;
        }
    }
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        VECTOR_flCalAsmAmrCurRef
 *** 
 ***  DESCRIPTION:
 ***        Field-weakening control of induction motor based on PI regulator.
 ***        Version |    DATE    |     Author     |    Description
 ***        0.1       2018-09-28    Jason.YR.Chen      First version.
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        tASM_AMR_COEF *    stAsmAmrCoefPtr     
 ***        tASM_AMR_IN *      stAsmAmrInPtr       
 ***        tASM_AMR_PR *      stAsmAmrPrPtr       
 ***        tREUSE_ASMAMR *    pISV                
 ***
 ***  RETURNS:
 ***        Float32
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
Float32 VECTOR_flCalAsmAmrCurRef(tASM_AMR_COEF * stAsmAmrCoefPtr, tASM_AMR_IN * stAsmAmrInPtr, tASM_AMR_PR * stAsmAmrPrPtr, tREUSE_ASMAMR * pISV)
{
    Float32 flAsmAmrCtrlerOutAmp;
    Float32 flAsmAmrIntegStateOut;

    tSAT_OUT stAsmAmrLimOut;
    tPI_CTRLER_OUT stAsmAmrPiCtrlerOut;

    tPI_CTRLER_COEF stPiCoef;
    tPI_CTRLER_IN stPiCtrlerIn;
    tPI_CTRLER_OUT stPiCtrlerOut;
    tSAT_OUT stSatOut;

    stPiCoef.flPropGain = stAsmAmrPrPtr->flPrAsmAmrPropGain;
    stPiCoef.flDiscreteIntegGain = stAsmAmrPrPtr->flPrAsmAmrIntegGain * stAsmAmrInPtr->flIntTimeTsec;
    stPiCtrlerIn.flCtrlerErr = stAsmAmrInPtr->flOutVoltLimVt - stAsmAmrInPtr->flOutVoltMagVt;
    stPiCtrlerIn.blStopIntegFlag = pISV->blAsmAmrStopIntegFlagState;
    stPiCtrlerIn.flBackCalValue = FLOAT_ZERO;
    CTRLER_voPiCtrlShareState(&stPiCtrlerIn, &stPiCoef, pISV->flAsmAmrCtrlerIntegState, &stPiCtrlerOut);
    stAsmAmrPiCtrlerOut = stPiCtrlerOut;
    flAsmAmrCtrlerOutAmp = stAsmAmrPiCtrlerOut.flPiCtrlOut;
    MATOOL_voDynSatWiSatFlag(flAsmAmrCtrlerOutAmp, ASM_AMR_CUR_REF_UP_LIM, FLOAT_ZERO - (stAsmAmrCoefPtr->flMotorNoLoadCurAmp *
     ASM_AMR_CUR_REF_LOW_LIM), &stSatOut);
    stAsmAmrLimOut = stSatOut;
    pISV->blAsmAmrStopIntegFlagState = CTRLER_blSetStopIntegFlag(stAsmAmrLimOut.ubSatFlag != NORMAL, stPiCtrlerIn.flCtrlerErr, flAsmAmrCtrlerOutAmp,
     FLOAT_ZERO);
    flAsmAmrIntegStateOut = stAsmAmrPiCtrlerOut.flIntegStateOut;
    if (stAsmAmrLimOut.ubSatFlag == OVER_UP_LIM) 
    {
        pISV->flAsmAmrCtrlerIntegState = FLOAT_ZERO;
    }
    else 
    {
        pISV->flAsmAmrCtrlerIntegState = flAsmAmrIntegStateOut;
    }
    return FILTER_flLpf(stAsmAmrLimOut.flSatOut, stAsmAmrInPtr->flIntTimeTsec / stAsmAmrPrPtr->flPrAsmAmrLpfTimeConstTsec, OFF, pISV->ptREUSE_LPF);
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        VECTOR_flCalAsmFluxWknCurRef
 *** 
 ***  DESCRIPTION:
 ***        Field-weakening control based on voltage model of induction motor.
 ***        Flux weakening daxis synchronous reference current is divided into three region:
 ***        Region 0: Constant no-load current.
 ***        Region 1: Cross-section of voltage limit ellipse and current limit circle.
 ***        .                ______________________________________
 ***        .              /       1         /  Vmax^2                  \
 ***        .  Id_Ref1 =  / ---------------- |  ------- - Lsig^2*Imax^2 |
 ***        .           \/  (Ls^2 - Lsig^2)  \   we^2                   /
 ***        .
 ***        Region 2: MTPA under voltage limit constraint.
 ***        .                 1         Vmax
 ***        .  Id_Ref2 = ------------* --------
 ***        .             sqrt(2)*Ls      we
 ***        .
 ***        . Ls = LM + Lsig
 ***        ------------------------------------------------------------
 ***        Version |    DATE    |    Author    |    Description
 ***        0.1        2016-11-28  Jinlong Lin      First Version.
 ***        0.2        2016-11-30  BrianYenChen     Change to BusData form.
 ***        0.3        2017-07-11  BrianYenChen     Change library from FOCPGIM to FOC.
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        tASM_FLUX_WKN_COEF * stAsmFluxWknCoefPtr 
 ***        tASM_FLUX_WKN_IN * stAsmFluxWknInPtr   
 ***        tREUSE_ASMFLUXWKN * pISV               
 ***
 ***  RETURNS:
 ***        Float32
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
Float32 VECTOR_flCalAsmFluxWknCurRef(tASM_FLUX_WKN_COEF * stAsmFluxWknCoefPtr, tASM_FLUX_WKN_IN * stAsmFluxWknInPtr, tREUSE_ASMFLUXWKN * pISV)
{
    Float32 flMotorStatorInductLh; /* Description: stator inductance in [H]. (Ls = LM + Lsig) */
    Float32 flStatorElectSpdLpfGain;

    UWORD uwAbsStatorElectSpdLpfRdps; /* Description: fixed-point stator electrical absolute speed in [rad/sec]. */

    Float32 flAbsStatorElectSpdLpfRdps;

    Float32 flAsmFluxWknCurRefAmp;

    flMotorStatorInductLh = stAsmFluxWknCoefPtr->flMotorMutualInductLh + stAsmFluxWknCoefPtr->flMotorSigmaInductLh;
    flStatorElectSpdLpfGain = stAsmFluxWknInPtr->flIntTimeTsec / (stAsmFluxWknInPtr->flIntTimeTsec + (flMotorStatorInductLh / 
     stAsmFluxWknCoefPtr->flMotorStatorResistOhm));
    pISV->flStatorElectSpdLpfState = FILTER_flLpfWithSharedState(stAsmFluxWknInPtr->flStatorElectSpdRdps, flStatorElectSpdLpfGain,
     pISV->flStatorElectSpdLpfState);
    flAbsStatorElectSpdLpfRdps = fabsf(pISV->flStatorElectSpdLpfState);
    uwAbsStatorElectSpdLpfRdps = (UWORD) flAbsStatorElectSpdLpfRdps;
    if (uwAbsStatorElectSpdLpfRdps != 0) 
    {
        Float32 flFluxWknDaxisSynCurRefAmp; /* Description: Daxis synchronous current reference(Id_Ref) in flux weakening region. [A]  */
        Float32 flLinkageFluxWb;
        Float32 flMotorFluxWb;
        Float32 flRegion1DaxisSynCurRefAmp; /* Description: Daxis synchronous current reference(Id_Ref) in flux weakening region 1. [A]  */
        Float32 flRegion2DaxisSynCurRefAmp;

        flMotorFluxWb = stAsmFluxWknInPtr->flOutVoltLimVt / flAbsStatorElectSpdLpfRdps;
        flLinkageFluxWb = stAsmFluxWknCoefPtr->flMotorSigmaInductLh * stAsmFluxWknCoefPtr->flInvtCurLimAmp;
        flRegion1DaxisSynCurRefAmp = (Float32) sqrtf(((flMotorFluxWb + flLinkageFluxWb) * (flMotorFluxWb - flLinkageFluxWb)) / ((flMotorStatorInductLh
          + stAsmFluxWknCoefPtr->flMotorSigmaInductLh) * (flMotorStatorInductLh - stAsmFluxWknCoefPtr->flMotorSigmaInductLh)));
        flRegion2DaxisSynCurRefAmp = (INV_SQRT2 / flMotorStatorInductLh) * flMotorFluxWb;
		if (flRegion1DaxisSynCurRefAmp > flRegion2DaxisSynCurRefAmp) 
        {
            flFluxWknDaxisSynCurRefAmp = flRegion1DaxisSynCurRefAmp;
        }
        else 
        {
            flFluxWknDaxisSynCurRefAmp = flRegion2DaxisSynCurRefAmp;
        }
        if (stAsmFluxWknCoefPtr->flMotorNoLoadCurAmp < flFluxWknDaxisSynCurRefAmp) 
        {
            flAsmFluxWknCurRefAmp = stAsmFluxWknCoefPtr->flMotorNoLoadCurAmp;
        }
        else 
        {
            flAsmFluxWknCurRefAmp = flFluxWknDaxisSynCurRefAmp;
        }
    }
    else 
    {
        flAsmFluxWknCurRefAmp = stAsmFluxWknCoefPtr->flMotorNoLoadCurAmp;
    }
    return flAsmFluxWknCurRefAmp;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        VECTOR_voCalAsmDaxisSynCurRef
 *** 
 ***  DESCRIPTION:
 ***        Calculate d-axis syn. frame current reference of Asyn. Motor.
 ***        Version |    DATE    |     Author     |    Description
 ***        0.1       2018-09-28    Jason.YR.Chen      First version.
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***        tASM_DAXIS_CUR_REF_COEF * stAsmDaxisCurRefCoefPtr 
 ***        tASM_DAXIS_CUR_REF_IN * stAsmDaxisCurRefInPtr 
 ***        tASM_DAXIS_CUR_REF_OUT * stAsmDaxisCurRefOutPtr 
 ***        tREUSE_ASMIDREF *  pISV                
 ***        tASM_DAXIS_CUR_REF_PR * stAsmDaxisCurRefPrPtr 
 ***
 ***  RETURNS:
 ***        void
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
void VECTOR_voCalAsmDaxisSynCurRef(tASM_DAXIS_CUR_REF_COEF * stAsmDaxisCurRefCoefPtr, tASM_DAXIS_CUR_REF_IN * stAsmDaxisCurRefInPtr,
  tASM_DAXIS_CUR_REF_OUT * stAsmDaxisCurRefOutPtr, tREUSE_ASMIDREF * pISV, tASM_DAXIS_CUR_REF_PR * stAsmDaxisCurRefPrPtr)
{
    Float32 flMotorStatorInductLh; /* Description: stator inductance in [H]. (Ls = LM + Lsig) */

    tASM_AMR_COEF stAsmAmrCoef;
    tASM_AMR_IN stAsmAmrIn;
    tASM_AMR_PR stAsmAmrPr;
    tASM_FLUX_WKN_COEF stAsmFluxWknCoef;
    tASM_FLUX_WKN_IN stAsmFluxWknIn;

    Float32 flRegion1QaxisSynCurLimAmp; /* Description: Qaxis synchronous current limit in flux weakening region 1. [A] */
    Float32 flRegion2QaxisSynCurLimAmp; /* Description: Qaxis synchronous current limit in flux weakening region 2. [A]  */

    stAsmFluxWknCoef.flInvtCurLimAmp = stAsmDaxisCurRefCoefPtr->flInvtCurLimAmp;
    stAsmFluxWknCoef.flMotorNoLoadCurAmp = stAsmDaxisCurRefCoefPtr->flMotorNoLoadCurAmp;
    stAsmFluxWknCoef.flMotorMutualInductLh = stAsmDaxisCurRefCoefPtr->flMotorMutualInductLh;
    stAsmFluxWknCoef.flMotorSigmaInductLh = stAsmDaxisCurRefCoefPtr->flMotorSigmaInductLh;
    stAsmFluxWknCoef.flMotorStatorResistOhm = stAsmDaxisCurRefCoefPtr->flMotorStatorResistOhm;
    stAsmFluxWknIn.flIntTimeTsec = stAsmDaxisCurRefInPtr->flIntTimeTsec;
    stAsmFluxWknIn.flStatorElectSpdRdps = stAsmDaxisCurRefInPtr->flStatorElectSpdRdps;
    stAsmFluxWknIn.flOutVoltLimVt = stAsmDaxisCurRefInPtr->flOutVoltLimVt;
    stAsmAmrCoef.flMotorNoLoadCurAmp = stAsmDaxisCurRefCoefPtr->flMotorNoLoadCurAmp;
    stAsmAmrIn.flIntTimeTsec = stAsmDaxisCurRefInPtr->flIntTimeTsec;
    stAsmAmrIn.flOutVoltLimVt = stAsmDaxisCurRefInPtr->flOutVoltLimVt;
    stAsmAmrIn.flOutVoltMagVt = stAsmDaxisCurRefInPtr->flOutVoltMagVt;
    stAsmAmrPr.flPrAsmAmrPropGain = stAsmDaxisCurRefPrPtr->flPrAsmAmrPropGain;
    stAsmAmrPr.flPrAsmAmrIntegGain = stAsmDaxisCurRefPrPtr->flPrAsmAmrIntegGain;
    stAsmAmrPr.flPrAsmAmrLpfTimeConstTsec = stAsmDaxisCurRefPrPtr->flPrAsmAmrLpfTimeConstTsec;
    stAsmDaxisCurRefOutPtr->flFluxWknCurRefAmp = MATOOL_flGetMax(VECTOR_flCalAsmFluxWknCurRef(&stAsmFluxWknCoef, &stAsmFluxWknIn,
     pISV->ptREUSE_ASMFLUXWKN) + VECTOR_flCalAsmAmrCurRef(&stAsmAmrCoef, &stAsmAmrIn, &stAsmAmrPr, pISV->ptREUSE_ASMAMR),
     stAsmDaxisCurRefCoefPtr->flMotorNoLoadCurAmp * ASM_DAXIS_CUR_REF_LOW_LIM);
    flMotorStatorInductLh = stAsmDaxisCurRefCoefPtr->flMotorMutualInductLh + stAsmDaxisCurRefCoefPtr->flMotorSigmaInductLh;
    flRegion1QaxisSynCurLimAmp = (Float32) sqrtf((stAsmDaxisCurRefCoefPtr->flInvtCurLimAmp + stAsmDaxisCurRefOutPtr->flFluxWknCurRefAmp) *
     (stAsmDaxisCurRefCoefPtr->flInvtCurLimAmp - stAsmDaxisCurRefOutPtr->flFluxWknCurRefAmp));
    flRegion2QaxisSynCurLimAmp = stAsmDaxisCurRefOutPtr->flFluxWknCurRefAmp * (flMotorStatorInductLh / stAsmDaxisCurRefCoefPtr->flMotorSigmaInductLh);
    if (flRegion1QaxisSynCurLimAmp < flRegion2QaxisSynCurLimAmp) 
    {
        stAsmDaxisCurRefOutPtr->flFluxWknCurRefLimAmp = flRegion1QaxisSynCurLimAmp;
    }
    else 
    {
        stAsmDaxisCurRefOutPtr->flFluxWknCurRefLimAmp = flRegion2QaxisSynCurLimAmp;
    }
    stAsmDaxisCurRefOutPtr->flFluxWknMotorTorqConst = THREE_DIV_TWO * stAsmDaxisCurRefCoefPtr->flMotorPolePairs *
     (stAsmDaxisCurRefCoefPtr->flMotorMutualInductLh * stAsmDaxisCurRefOutPtr->flFluxWknCurRefAmp);
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        RESTART_AsmDaxisSynCurRefHarness
 *** 
 ***  DESCRIPTION:
 ***        Main restart function
 ***        
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***        void
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
void RESTART_AsmDaxisSynCurRefHarness(void)
{
    AsmDCurRef_voResetInitValue();
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        AsmDCurRef_voResetInitValue
 *** 
 ***  DESCRIPTION:
 ***        STATIC_GLOBAL_RESTART
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***        void
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
void AsmDCurRef_voResetInitValue(void)
{
    S_stAsmAmrCurRefLpfState.flStateOut = 0.F;
    S_stAsmAmrCurRefState.blAsmAmrStopIntegFlagState = 0;
    S_stAsmAmrCurRefState.flAsmAmrCtrlerIntegState = 0.F;
    S_stAsmFluxWknCurRefState.flStatorElectSpdLpfState = 0.F;
}

/****************************************************************************************************************************************************\
 ***  FUNCTION:
 ***        AsmDaxisSynCurRefHarness
 *** 
 ***  DESCRIPTION:
 ***        
 *** 
 ***  PARAMETERS:
 ***        Type               Name                Description
 ***        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***        void
 ***
 ***  SETTINGS:
 ***
\****************************************************************************************************************************************************/
void AsmDaxisSynCurRefHarness(void)
{
    tASM_DAXIS_CUR_REF_COEF stAsmDaxisCurRefCoef;
    tASM_DAXIS_CUR_REF_IN stAsmDaxisCurRefIn;
    tASM_DAXIS_CUR_REF_OUT stAsmDaxisCurRefOut;
    tASM_DAXIS_CUR_REF_PR stAsmDaxisCurRefPr;

	ULONG ulIqLim_tmp;
	SLONG slIdRef_tmp;
	
		stAsmDaxisCurRefCoef.flInvtCurLimAmp = (Float32)pr[CURRENT_LIM] / 100 * (Float32)COF_ulIbRe / 2.5 / 100 * 1.1; // Jerry.sk.tseng for GFC High elecator 2021/08/17
		stAsmDaxisCurRefCoef.flMotorNoLoadCurAmp = (Float32)COF_uwI0Pu / 32767 * (Float32)COF_ulIbRe / 100; // Jerry.sk.tseng for GFC High elecator 2021/08/17
		stAsmDaxisCurRefCoef.flMotorPolePairs = (Float32)pr[POLES1] / 2;
		stAsmDaxisCurRefCoef.flMotorMutualInductLh = (Float32)COF_uwLmPu * COF_uwLbRe / 1000 / 64000; 
		stAsmDaxisCurRefCoef.flMotorSigmaInductLh = (Float32)COF_uwLxPu * COF_uwLbRe / 1000 / 1024000; 
		stAsmDaxisCurRefCoef.flMotorStatorResistOhm =  (Float32)COF_uwRsPu * COF_uwRbRe / 1000 / 32768; 
		stAsmDaxisCurRefIn.flIntTimeTsec = 0.001F;
		stAsmDaxisCurRefIn.flStatorElectSpdRdps = TWO_PI * (Float32)(((CRM_slFlxFreqPu >> 15) * COF_uwFbRe) >> 16) / 100;
		stAsmDaxisCurRefIn.flOutVoltLimVt = (Float32)DcbusDCLPF.sw.hi / 10 * INV_SQRT3 * 0.9 ;//DcbusDCLPF.sw.hi;
		stAsmDaxisCurRefIn.flOutVoltMagVt = (Float32)FLX_swVoutPu / 32767 * (Float32)COF_uwVbRe / 10;
		stAsmDaxisCurRefPr.flPrAsmAmrPropGain = 0.1F;
		stAsmDaxisCurRefPr.flPrAsmAmrIntegGain = 0.1F;
		stAsmDaxisCurRefPr.flPrAsmAmrLpfTimeConstTsec = 0.016F;
	
	
		VECTOR_voCalAsmDaxisSynCurRef(&stAsmDaxisCurRefCoef, &stAsmDaxisCurRefIn, &stAsmDaxisCurRefOut, &S_stAsmDaxisSynCurRefState,
		 &stAsmDaxisCurRefPr);
		SAsmDCurRef1_f__nMotorTorqConst = stAsmDaxisCurRefOut.flFluxWknMotorTorqConst;
		SAsmDCurRef1_flFluxWknCurRefAmp = stAsmDaxisCurRefOut.flFluxWknCurRefAmp;
		SAsmDCurRef1_f__WknCurRefLimAmp = stAsmDaxisCurRefOut.flFluxWknCurRefLimAmp;
	
		swMotorTorqConst_test = stAsmDaxisCurRefOut.flFluxWknMotorTorqConst * 100;
		swFluxWknCurRefAmp_test = stAsmDaxisCurRefOut.flFluxWknCurRefAmp * 100;
		swFluxWknCurRefLimAmp_test = stAsmDaxisCurRefOut.flFluxWknCurRefLimAmp * 100;
	
	//	swMotorTorqConst_test_Pu = stAsmDaxisCurRefOut.flFluxWknMotorTorqConst * 256; // (Q8)
		FLX_swIdseRefPu = stAsmDaxisCurRefOut.flFluxWknCurRefAmp * 100 * 32767 / (Float32)COF_ulIbRe; // (Q15)  // Jerry.sk.tseng for GFC High elecator 2021/08/17
	//	swFluxWknCurRefLimAmp_test_Pu = stAsmDaxisCurRefOut.flFluxWknCurRefLimAmp * 100 / (Float32)COF_uwIbRe * 2.5 * 100 / 1.1;
		COF_uwKt = ((ULONG)COF_uwLmPu * FLX_swIdseRefPu) >> 13; //Q8 = Q(6+15-13)
	
		//IqRefLim = sqrt((InvIrate_max*pr[CURRENT_LIM])^2 - Ids^2)
	//	ulIqLim_tmp = ((ULONG)COF_uwIIratePu * ((ULONG)pr[CURRENT_LIM] * 563 >> 9)) / 100;	//New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
		if(UCMP)
        {        
            //[UCMP function, Bernie, 2016/06/14]  
			ulIqLim_tmp = ((ULONG)COF_uwMIratePu * ((ULONG)pr[CUR_LIM_UCMP] * 563 >> 9)) / 100;  //New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
        }
        else if((MFI_btTorqDetect) || (BTTx_btTorqDetect))
        {
            //[JES Torq Detect Function, Special.Kung, 2022/09/01]
            
            //because pr[BTT100] dot1 so /10
            //pr[BTTx_TestTorq] dot2 so *0.01
            //and TorqDetect output current should be 0.1/ 0.2/ .../ 1.0 times
            
            ulIqLim_tmp = U16xU16divU16(((pr[BTT100]/10)*100), COF_uwMIratePu, COF_uwMIratePu);
            //ulIqLim_tmp = ulIqLim_tmp+(ulIqLim_tmp*((pr[BTTx_TestTorq]*0.01)-1));
            
            //[Special.Kung, 2022/12/12]
            //Torque should 0.1¡A0.2 multiple increase
            ulIqLim_tmp = (ulIqLim_tmp*(BTTx_uwTestStep*0.1));
        }
		else
        {
			ulIqLim_tmp = ((ULONG)COF_uwIIratePu * ((ULONG)pr[CURRENT_LIM] * 563 >> 9)) / 100;	//New IED Irated is 110%, 1.1=563/512, DINO, 09/06/2010
		}
		if (ulIqLim_tmp >= 0x7FFF){
			ulIqLim_tmp = 0x7FFF;
		}
	
		// [ If Irms<Id, Iq=0, Add by DINO, 06/17/2009
		if ((SWORD)ulIqLim_tmp < FLX_swIdseRefPu){
			SPR_swIqseRefLimPu = 0;
		}
		else{
			ulIqLim_tmp = (ulIqLim_tmp * ulIqLim_tmp) - ((ULONG)FLX_swIdseRefPu * FLX_swIdseRefPu);
			SPR_swIqseRefLimPu = uw_Sqrt32c(ulIqLim_tmp); //Q15
		}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------------------*\
  END OF FILE
\*--------------------------------------------------------------------------------------------------------------------------------------------------*/

