//*****************************************************************/
//  @File Name: Keypad.H  
//  @Partner file: Keypad.C                                     
//  @Project: Wizard                                        
//  @Compiler: HEW V3.0 for H8/3687F                        
//  @Company: Delta Elec.INC CopyRight 2004                                  
//*****************************************************************/  
#ifdef _MFIO_C
   #define MFIO_EXT 
#else
   #define MFIO_EXT extern
#endif

//****************************************************************
// @Typedefs
//****************************************************************
//****************************************************************
// @Prototypes Of  Functions
//****************************************************************
MFIO_EXT void (*const mfi0_tbl[3])(UWORD chg,UWORD k);
MFIO_EXT void (*const mfi1_tbl[(MFIMAX+1)])(UWORD chg,UWORD k);
MFIO_EXT UWORD (*const mfo_tbl[(MFOMAX+1)])(UWORD pin,UWORD k);
MFIO_EXT void CHK_DI_State(void);
MFIO_EXT void mfi_process(void);
MFIO_EXT void mfo_process(void);
MFIO_EXT void mfi_Pin(void);
MFIO_EXT void mfo_Pin(void);
MFIO_EXT void mfo_ON(UWORD k);
MFIO_EXT void mfo_OFF(UWORD k);

MFIO_EXT void di_sub0(UWORD chg, UWORD k);
MFIO_EXT void di_sub1(UWORD chg, UWORD k);
MFIO_EXT void di_sub2(UWORD chg, UWORD k);
MFIO_EXT void no_func(UWORD chg,UWORD k);
MFIO_EXT void mispeed1(UWORD chg,UWORD k);
MFIO_EXT void mispeed2(UWORD chg,UWORD k);
MFIO_EXT void mispeed3(UWORD chg,UWORD k);
MFIO_EXT void mispeed4(UWORD chg,UWORD k);
MFIO_EXT void extreset(UWORD chg,UWORD k);
MFIO_EXT void extjog(UWORD chg,UWORD k);
MFIO_EXT void speedhold(UWORD chg,UWORD k);
MFIO_EXT void acc_dec_chg1(UWORD chg,UWORD k);
MFIO_EXT void acc_dec_chg2(UWORD chg,UWORD k);
MFIO_EXT void efnc(UWORD chg,UWORD k);
MFIO_EXT void ef1nc(UWORD chg,UWORD k);
MFIO_EXT void bb_up(UWORD chg,UWORD k);
MFIO_EXT void outputoff(UWORD chg,UWORD k);
MFIO_EXT void cancel_AAAD(UWORD chg,UWORD k);
MFIO_EXT void motor1_2(UWORD chg,UWORD k);
MFIO_EXT void AUI1_SOFC(UWORD chg,UWORD k);
MFIO_EXT void ACI_SOFC(UWORD chg,UWORD k);
MFIO_EXT void AUI2_SOFC(UWORD chg,UWORD k);
MFIO_EXT void ForceRampStop(UWORD chg,UWORD k);
MFIO_EXT void incspeed(UWORD chg,UWORD k);
MFIO_EXT void decspeed(UWORD chg,UWORD k);
MFIO_EXT void piddis(UWORD chg,UWORD k);
MFIO_EXT void CNT_IN(UWORD chg,UWORD k);
MFIO_EXT void CNT_CLR(UWORD chg,UWORD k);
MFIO_EXT void FWD_JOG(UWORD chg,UWORD k);
MFIO_EXT void REV_JOG(UWORD chg,UWORD k);
MFIO_EXT void TRQ_2_SPD(UWORD chg,UWORD k);
MFIO_EXT void ASR1_ASR2(UWORD chg,UWORD k);
MFIO_EXT void YconnectCHK(UWORD chg,UWORD k);
MFIO_EXT void DconnectCHK(UWORD chg,UWORD k);
MFIO_EXT void TqOfstHigh(UWORD chg,UWORD k);
MFIO_EXT void TqOfstMiddle(UWORD chg,UWORD k);
MFIO_EXT void TqOfstLow(UWORD chg,UWORD k);
MFIO_EXT void MISpdPosChang(UWORD chg,UWORD k);
MFIO_EXT void APREnable(UWORD chg,UWORD k);
MFIO_EXT void MIPosEnter(UWORD chg,UWORD k);
MFIO_EXT void PG2RefPosMode(UWORD chg,UWORD k);
MFIO_EXT void WriteEPDisable(UWORD chg,UWORD k);
MFIO_EXT void TqSetDirection(UWORD chg,UWORD k);
MFIO_EXT void ForceCoastStop(UWORD chg,UWORD k);
MFIO_EXT void ForceCoastStop1(UWORD chg,UWORD k);
MFIO_EXT void VcomPosition(UWORD chg,UWORD k);
MFIO_EXT void MCCHKEnable(UWORD chg,UWORD k);
MFIO_EXT void BKCHKEnable1(UWORD chg,UWORD k);//[change for EN81-1+A3, Bernie, 2015/03/16]
MFIO_EXT void BKCHKEnable2(UWORD chg,UWORD k);//[change for EN81-1+A3, Bernie, 2015/03/16]
MFIO_EXT void EPSEnable(UWORD chg,UWORD k);
MFIO_EXT void MI_Sensor819(UWORD chg,UWORD k);//[Artemis Add Sensor819 Function/Special/2022/06/06]
MFIO_EXT void AFE_ERRFBK(UWORD chg,UWORD k);

//DLC function, Henry, 2016/07/20 [
MFIO_EXT void DLC_LU(UWORD chg,UWORD k);
MFIO_EXT void DLC_LD(UWORD chg,UWORD k);
MFIO_EXT void DLC_DZN(UWORD chg,UWORD k);
MFIO_EXT void DLC_CANOFF(UWORD chg,UWORD k);
MFIO_EXT void DLC_LOW_SPD(UWORD chg,UWORD k);
MFIO_EXT void DLC_FSD(UWORD chg,UWORD k);
MFIO_EXT void DLC_DDS(UWORD chg,UWORD k);
MFIO_EXT void DLC_UDS(UWORD chg,UWORD k);
//]
MFIO_EXT void IODLC_CRPLS_IO(UWORD chg,UWORD k); // [IODLC, Lyabryan, 2016/11/11]
MFIO_EXT void EPS_MI_DETCT(UWORD chg,UWORD k);   //[EPS MO Output,Lyabryan,2018/06/19]
MFIO_EXT void SMTRISE_ETS(UWORD chg,UWORD k);    //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
MFIO_EXT void SMTRISE_ESD(UWORD chg,UWORD k);    //[KEB ESD&ETS Function/Lyabryan/2018/08/10]
MFIO_EXT void Torq_Detect(UWORD chg,UWORD k);    //[JES Torq Detect Function, Special.Kung, 2022/09/01]


    


MFIO_EXT void ef_check(void);
MFIO_EXT void bb_check(void);
MFIO_EXT void ext_updown(void);

MFIO_EXT UWORD mfo_none(UWORD pin,UWORD k);          // Not used
MFIO_EXT UWORD mfo_running(UWORD pin,UWORD k);       // Inverter Running //
MFIO_EXT UWORD mfo_atmaxf(UWORD pin,UWORD k);        // At Setpoint Speed (disable output at STOP)
MFIO_EXT UWORD mfo_atmaxf_Band(UWORD pin,UWORD k);   // At Setpoint Speed (disable output at STOP) (flexible band)//Band of Speed Agree Function #18572	
MFIO_EXT UWORD mfo_atspeed1(UWORD pin,UWORD k);      // At Speed 1 //
MFIO_EXT UWORD mfo_atspeed2(UWORD pin,UWORD k);      // At Speed 2 //
MFIO_EXT UWORD mfo_fcmdzero(UWORD pin,UWORD k);      // Zero Speed //
MFIO_EXT UWORD mfo_fcmdzerostp(UWORD pin,UWORD k);   // Zero Speed, include drive stop
MFIO_EXT UWORD mfo_overtq1(UWORD pin,UWORD k);       // Over Torque Dectted 1) //
MFIO_EXT UWORD mfo_overtq2(UWORD pin,UWORD k);       // Over Torque Dectted 2) //
MFIO_EXT UWORD mfo_ready(UWORD pin,UWORD k);         // Ready
MFIO_EXT UWORD mfo_lv(UWORD pin,UWORD k);            // Low voltage indication
MFIO_EXT UWORD mfo_fault(UWORD pin,UWORD k);         // Inverter Fault //
MFIO_EXT UWORD mfo_braker_release(UWORD pin,UWORD k);// Braker release
MFIO_EXT UWORD mfo_braker_release2(UWORD pin,UWORD k);// Braker release   //DIN function
MFIO_EXT UWORD mfo_ohalarm(UWORD pin,UWORD k);       // OH alarm
MFIO_EXT UWORD mfo_SWbrakeOut(UWORD pin,UWORD k);    // SW brake Output
MFIO_EXT UWORD mfo_LiftEnable(UWORD pin,UWORD k);    // LIFT ENABLE
MFIO_EXT UWORD mfo_pidalarm(UWORD pin,UWORD k);      // PID Deviation Alarm //
MFIO_EXT UWORD mfo_overslip(UWORD pin,UWORD k);      // Over Slip
MFIO_EXT UWORD mfo_trgdone(UWORD pin,UWORD k);       // Trigger attained
MFIO_EXT UWORD mfo_trgpre(UWORD pin,UWORD k);        // Preliminary conter attained
MFIO_EXT UWORD mfo_bb(UWORD pin,UWORD k);            // bb indication
MFIO_EXT UWORD mfo_bf(UWORD pin,UWORD k);            // bF Error, dino, 12/13/2007
MFIO_EXT UWORD mfo_warning(UWORD pin,UWORD k);       // All of Warning
MFIO_EXT UWORD mfo_ovalarm(UWORD pin,UWORD k);       // Ov alarm
MFIO_EXT UWORD mfo_ocsalarm(UWORD pin,UWORD k);      // Oc stall alarm
MFIO_EXT UWORD mfo_ovsalarm(UWORD pin,UWORD k);      // Ov stall alarm
MFIO_EXT UWORD mfo_opmode(UWORD pin,UWORD k);        // Operation Mode
MFIO_EXT UWORD mfo_fwdcmd(UWORD pin,UWORD k);        // Fwd command //
MFIO_EXT UWORD mfo_revcmd(UWORD pin,UWORD k);        // Rev command //
MFIO_EXT UWORD mfo_abv_curt(UWORD pin,UWORD k);      // Above Current
MFIO_EXT UWORD mfo_low_curt(UWORD pin,UWORD k);      // Below Current
MFIO_EXT UWORD mfo_abv_spa(UWORD pin,UWORD k);       // Above Speed Area
MFIO_EXT UWORD mfo_abv_PGspa(UWORD pin,UWORD k);     // Above Speed Area
MFIO_EXT UWORD mfo_low_spa(UWORD pin,UWORD k);       // Below Speed Area
MFIO_EXT UWORD mfo_chg2Y(UWORD pin,UWORD k);         // change to Y-connected
MFIO_EXT UWORD mfo_chg2D(UWORD pin,UWORD k);         // change to Delta-connected
MFIO_EXT UWORD mfo_foutzero(UWORD pin,UWORD k);		 // fout, zero speed at running
MFIO_EXT UWORD mfo_foutzerostp(UWORD pin,UWORD k);	 // fout, zero speed include stop
MFIO_EXT UWORD mfo_faultoption1(UWORD pin,UWORD k);	 // Fault option 1
MFIO_EXT UWORD mfo_faultoption2(UWORD pin,UWORD k);	 // Fault option 2
MFIO_EXT UWORD mfo_faultoption3(UWORD pin,UWORD k);	 // Fault option 3
MFIO_EXT UWORD mfo_faultoption4(UWORD pin,UWORD k);	 // Fault option 4
MFIO_EXT UWORD mfo_OnPosition(UWORD pin,UWORD k);	 // On Position
MFIO_EXT UWORD mfo_atFSET(UWORD pin,UWORD k);		 // At setpoint Speed
MFIO_EXT UWORD mfo_atFSET_Band(UWORD pin,UWORD k);   // At setpoint Speed
MFIO_EXT UWORD mfo_multiposition(UWORD pin,UWORD k); // Multi-position
MFIO_EXT UWORD mfo_Fault2(UWORD pin,UWORD k);		 // Fault Output including delay time
MFIO_EXT UWORD mfo_gen_ok(UWORD pin,UWORD k);		 // Generation Operation detected ok
MFIO_EXT UWORD mfo_gen_dir(UWORD pin,UWORD k);		 // Generation Operation Direction
MFIO_EXT UWORD mfo_STO_OUT(UWORD pin,UWORD k);       //42:STO logic1
MFIO_EXT UWORD mfo_DLC_UP(UWORD pin,UWORD k);        //43:DLC UP
MFIO_EXT UWORD mfo_DLC_DN(UWORD pin,UWORD k);        //44:DLC DN
//MFIO_EXT UWORD mfo_STO2(UWORD pin,UWORD k);        //43:STO logic2
MFIO_EXT UWORD mfo_IMEnable(UWORD pin,UWORD k); 
MFIO_EXT UWORD mfo_fault_rst(UWORD pin,UWORD k);     //[Add auto restart after fault, Bernie, 06/06/12]
MFIO_EXT UWORD mfo_star_Contactor(UWORD pin,UWORD k);//[Add star Contactor]
MFIO_EXT UWORD mfo_EPS_MODE(UWORD pin,UWORD k);      //[EPS MO Output,Lyabryan,2018/06/19]  // Lift enable, WTL, 20170621
MFIO_EXT UWORD mfo_Torq_Detect(UWORD pin,UWORD k);   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
MFIO_EXT UWORD mfo_AFE_RST(UWORD pin,UWORD k);      //[AFE Error Handle/Lyabryan/2022/03/24]

//DLC function, Henry, 2016/07/20
MFIO_EXT UWORD mfo_DLCLevOn(UWORD pin,UWORD k);

#pragma address mfi_status=0x0000a116    //[Address fixed, Aevin, 2017/06/28]
#pragma address mfo_status=0x0000a118
MFIO_EXT UWORD trg_cnt,
               mfi_old,			  
//			     mfi_now,			// Move to A_Monitor.h, 11/04/2008
			   mfi_buf,
			   mfi_status,
//			     mfo_now,			// Move to A_Monitor.h, 11/04/2008
			   mfo_status,
               YOnCNT,
               DOnCNT,
               DIstCNT,
			   uwFaultBitCode,
			   uwPcomClkMI,
			   uwPcomDataMI,
			   uwSPIPcom;

MFIO_EXT UWORD swmaxT1,
	           swmaxT2,
	           swmaxT3;

MFIO_EXT ULONG slmaxT1,
               slmaxT2,
               mio_ulMfiSta;

MFIO_EXT UWORD_UNION		vfd_uwFunSel2;				// VFD Functions Selection 2

MFIO_EXT UBYTE EXT_AISEL,
               speed,
               acc_dec,
               YDSetBit,
               YCONChkCNT,
               DCONChkCNT,
               MFI_TQCSel,
			   SPIPcomBit,
			   SPIPcomCNT,		// CalUBYTE: 10 UBYTE
			   MFI_ubFaultBit,
			   prt_ubWgEna,  // add wgoff interception flag, Sean, 11/18/2010
			   Speed_old,
			   Speed_priority,
			   Speed_INS,
			   Speed_RELEVEL;				
			 

#ifdef _MFIO_C              
const UWORD _16BitTab[16] = {
    0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,
    0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000,};              
#else
extern const UWORD _16BitTab[16];
#endif
//****************************************************************
// @File Global Variables
//****************************************************************
