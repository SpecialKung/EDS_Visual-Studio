#ifdef _SCI3_Remote_C
   #define SCI3_Remote_EXT 
#else
   #define SCI3_Remote_EXT extern
#endif

#ifdef _SCI3_Remote_C
const string20 Modelinfo[MAXMODELNO]={
//   12345678901234561234   //
	"0.25Hp 230V     	 ",	// 0
	"0.25Hp 460V      	 ",	// 1
	" 0.5Hp 230V      	 ",	// 2
	" 0.5Hp 460V      	 ",	// 3
	" 1  Hp 230V      	 ",	// 4
	" 1  Hp 460V      	 ",	// 5
	" 2  Hp 230V      	 ",	// 6
	" 2  Hp 460V      	 ",	// 7
	" 3  Hp 230V      	 ",	// 8
	" 3  Hp 460V      	 ",	// 9
	" 5  Hp 230V      	 ",	// 10
	" 5  Hp 460V      	 ",	// 11
	" 7.5Hp 230V      	 ",	// 12
	" 7.5Hp 460V     	 ",	// 13
	" 10 Hp 230V      	 ",	// 14
	" 10 Hp 460V      	 ",	// 15
	" 15 Hp 230V      	 ",	// 16
	" 15 Hp 460V      	 ",	// 17
	" 20 Hp 230V      	 ",	// 18
	" 20 Hp 460V      	 ",	// 19
	" 25 Hp 230V      	 ",	// 20
	" 25 Hp 460V      	 ",	// 21
	" 30 Hp 230V      	 ",	// 22
	" 30 Hp 460V      	 ",	// 23
	" 40 Hp 230V      	 ",	// 24
	" 40 Hp 460V      	 ",	// 25
	" 50 Hp 230V      	 ",	// 26
	" 50 Hp 460V      	 ",	// 27
	" 60 Hp 460V      	 ",	// 28
	" 60 Hp 230V      	 ",	// 29
	" 75 Hp 460V      	 ",	// 30
	" 75 Hp 230V      	 ",	// 31
	"100 Hp 460V      	 ",	// 32
	"100 Hp 230V      	 ",	// 33
	"125 Hp 460V         ",	// 34
};
const string20 ModelinfoSingle[MAXMODELNO]={        //[Single phase input, Bernie, 01/19/2012]
//   12345678901234561234   //
	"0.25Hp 230V Single  ",	// 0
	"0.25Hp 460V Single  ",	// 1
	" 0.5Hp 230V Single  ",	// 2
	" 0.5Hp 460V Single  ",	// 3
	" 1  Hp 230V Single  ",	// 4
	" 1  Hp 460V Single  ",	// 5
	" 2  Hp 230V Single  ",	// 6
	" 2  Hp 460V Single  ",	// 7
	" 3  Hp 230V Single  ",	// 8
	" 3  Hp 460V Single  ",	// 9
	" 5  Hp 230V Single  ",	// 10
	" 5  Hp 460V Single  ",	// 11
	" 7.5Hp 230V Single  ",	// 12
	" 7.5Hp 460V Single  ",	// 13
	" 10 Hp 230V Single  ",	// 14
	" 10 Hp 460V Single  ",	// 15
	" 15 Hp 230V Single  ",	// 16
	" 15 Hp 460V Single  ",	// 17
	" 20 Hp 230V Single  ",	// 18
	" 20 Hp 460V Single  ",	// 19
	" 25 Hp 230V Single  ",	// 20
	" 25 Hp 460V Single  ",	// 21
	" 30 Hp 230V Single  ",	// 22
	" 30 Hp 460V Single  ",	// 23
	" 40 Hp 230V Single  ",	// 24
	" 40 Hp 460V Single  ",	// 25
	" 50 Hp 230V Single  ",	// 26
	" 50 Hp 460V Single  ",	// 27
	" 60 Hp 460V Single  ",	// 28
	" 60 Hp 230V Single  ",	// 29
	" 75 Hp 460V Single  ",	// 30
	" 75 Hp 230V Single  ",	// 31
	"100 Hp 460V Single  ",	// 32
	"100 Hp 230V Single  ",	// 33
	"125 Hp 460V Single  ",	// 34
};

const string20 usrdefinfo[UPAGEMAX]={ // user keypad information
//   12345678901234561234   //
    "FREQ. SETPOINT  Hz  ",     //F  page
    "OUTPUT FREQ.    Hz  ",     //H  page
    "DC-BUS VOLTAGE  Vdc ",     //U_ page
    "OUTPUT CURRENT  Amps",     //A  page
    "OUTPUT VOLTAGE  Volt",     //E  page
    "USER DEFINITION Usr ",     //User page
};

const string20 usrdefinfo_0005[UPAGEMAX]={ // user keypad information
//   12345678901234561234   //
    "FREQ. SETPOINT      ",     //F  page
    "OUTPUT FREQ.        ",     //H  page
    "DC-BUS VOLTAGE  Vdc ",     //U_ page
    "OUTPUT CURRENT  Amps",     //A  page
    "OUTPUT VOLTAGE  Volt",     //E  page
    "USER DEFINITION Usr ",     //User page
};

// [ F, H Page Metric Display, Add by DINO, 05/25/2009
const string20 usrdefinfo_metric[UPAGEMAX]={ // user keypad information
//   12345678901234561234   //
    "SPEED SETPOINT  m/s ",     //F  page
    "OUTPUT SPEED    m/s ",     //H  page
};
// ]

// [ F, H Page English Display, Add by DINO, 05/25/2009
const string20 usrdefinfo_ft[UPAGEMAX]={ // user keypad information
//   12345678901234561234   //
    "SPEED SETPOINT  ft/s",     //F  page
    "OUTPUT SPEED    ft/s",     //H  page
};
// ]

// [ F, H Page English Display, Add by DINO, 05/25/2009
const string20 usrdefinfo_mpers2[UPAGEMAX]={ // user keypad information
//   12345678901234561234   //
    "SPEED SETPOINT  m/s2",     //F  page
    "OUTPUT SPEED    m/s2",     //H  page
};
// ]


const string20 Otherinfo[1]={
//   12345678901234561234   //
//    "TORQUE REFERENCENt-m"      // Torque Reference 
    "TORQUE REFERENCE%   ",      // Torque Reference
};
// multi function display description

const string20 BTTxinfo[11]=
{
    "No error            ",    //0
    "BTTA Testing1.1 bttA",    //1
    "BTTA Testing1.2 bttA",    //2
    "BTTA Testing1.3 bttA",    //3
    "BTTA Testing1.4 bttA",    //4
    "BTTA Testing1.5 bttA",    //5
    "BTTA Testing1.6 bttA",    //6
    "BTTA Testing1.7 bttA",    //7    
    "BTTA Testing1.8 bttA",    //8
    "BTTA Testing1.9 bttA",    //9
    "BTTA Testing2.0 bttA",    //10
};


const string20 sfrinfo[(MFDPAGEMAX+1)]={
   //12345678901234561234
    "U:Output CurrentAmps",     // 0
    "U:Reserved          ",     // 1
    "U:Actual Freq.  Hz  ",     // 2
    "U:DC Bus        Volt",     // 3
    "U:Output VoltageVolt",     // 4
    "U:Power Angle   deg ",     // 5
    "U:Ouput Power   KW  ",     // 6
    "U:Motor Speed   RPM ",     // 7
    "U:Torque        %   ",     // 8, Change the unit to %, DINO, 09/30/2009
    "U:PG Feedback       ",     // 9
    "U:Electric Angledeg ",     // 10 //Modify by Sampo
    "U:AUI1          %   ",     // 11 
    "U:ACI           %   ",     // 12
    "U:AUI2          %   ",     // 13
    "U:Heat Sink     C   ",     // 14
    "U:IGBT Temp     C   ",     // 15
    "U:DI ON/OFF Stat    ",     // 16       //[Hex display for user define page, Bernie, 2016/02/16]
	"U:DO ON/OFF Stat    ",     // 17       //[Hex display for user define page, Bernie, 2016/02/16]
    "U:Multi-Speed       ",     // 18
    "U:DI Pin Status     ",     // 19      //[Hex display for user define page, Bernie, 2016/02/16]
	"U:DO Pin Status     ",     // 20      //[Hex display for user define page, Bernie, 2016/02/16]
	"U:Reserved          ",		// 21
	"U:Reserved          ",		// 22
	"U:Reserved          ",		// 23
    "U:Error Vout    Vac ",     // 24
	"U:Error Vbus    Vdc ",     // 25
	"U:Error Ffbk    Hz  ",		// 26
	"U:Error Current Amps",		// 27
	"U:Error Fout    Hz  ",		// 28
    "U:Error Fcmd    Hz  ",     // 29
	"U:Error Power   KW  ",     // 30
	"U:Error Torque  %   ",		// 31
	"U:Error DI StateHex ",		// 32
	"U:Error DO StateHex ",		// 33
    "U:Error Drive   Hex ",     // 34
    "U:MI/MO status      ",     // 35
    "U:CAN Fail Rate %   ",     // 36---aevin add 6/14/2017
	"U:PG Quality    %   ",     // 37
#if 1//SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]	
    "U:Velocity Cmd  m/s ",	    // 38
	"U:Act Speed     m/s ",	    // 39
#endif
    "U:Actual Speed  m/s ",     // 40
};

// [ Actual Freq. Metric/English Display, Add by DINO, 05/25/2009
const string20 sfrinfo_vel_sel[3]={
    "U:Actual Speed  m/s ",     // 00-10=1
    "U:Actual Speed  ft/s",     // 00-10=2
    "U:Actual Speed  m/s2",     // 00-10=3
};
// ]

const string20 c20info[C20MAX]={
//   12345678901234561234   //
    "Command 2000H       ",
    "Frequency source    ",
    "Command 2002H       ",
    "Reserved            ",
    "Reserved            ",
    "Copy function       ",
    "User Password		 ",
};

const string20 c21info[C21MAX]={
//   12345678901234561234   //
    "Error code          ",    // 2100H  Error code      
    "Drive status        ",    // 2101H  Drive status    
    "Freq. setpoint  Hz  ",    // 2102H  Freq. setpoint  
    "Output freq.    Hz  ",    // 2103H  Output freq.    
    "Output current  Amps",    // 2104H  Output current  
    "DC-Bus voltage  Vdc ",    // 2105H  DC-Bus voltage  
    "Output voltage  Vac ",    // 2106H  Output voltage  
    "Multi-speed     Step",    // 2107H  Multi-speed     
    "Freq. command   Sec ",    // 2108H  PLC timer       
    "Trigger count   Cnt ",    // 2109H  Trigger count   
    "PF angle        Deg ",    // 210AH  PF angle        
    "User define(LWd)Usr ",    // 210BH  User define(LWd)
    "User define(HWd)Usr ",    // 210CH  User define(HWd)
    "Unit temperatureC   ",    // 210DH  Unit temperature
    "PID pv signal   Hz  ",    // 210EH  PID pv signal
    "PID setpoint    Hz  ",    // 210FH  PID setpoint    
    "VFD type ID         ",    // 2110H  VFD type ID     
    "Group number        ",    // 2111H  Group number    
    "Software ver.       ",    // 2112H  Software ver.   
    "Start up disp.      ",    // 2113H  Start up disp.  
    "Reserved            ",    // 2114H  Reserved        
    "Feedback freq.  Hz  ",    // 2115H  Feedback freq.  
    "User define         ",    // 2116H  User define     
    "User define att     ",    // 2117H  User define att 
    "Warn + Error        ",    // 2118H  Warn + Error    
    "Drive status        ",    // 2119H  Drive status    
    "F page value        ",    // 211AH  F page value    
    "Max of Fcmd         ",    // 211BH  Max of Fcmd     
    "H page value        ",    // 211CH  H page value    
    "F, Fmax, H att      ",    // 211DH  F, Fmax, H att  
    "A page value        ",    // 211EH  A page value    
    "A attribute         ",    // 211FH  A attribute     
	"Cmd Freq. REC.  Hz  ",	   // 2120H Error Fcmd      
	"Out Freq. REC.  Hz  ",	   // 2121H Error Fout      
	"Isum Value REC. Amps",	   // 2122H Error Isum      
	"Motor Freq. REC.Hz  ",	   // 2123H Error Ffbk      
	"Out Voltage REC.V   ",	   // 2124H Error Vout      
	"DcBus Value REC.V   ",	   // 2125H Error Vbus      
	"Out Power REC.  KW  ",	   // 2126H Error Power     
	"Out Torque REC. %   ",	   // 2127H Error Torque    
	"IGBT Temp. REC. C   ",	   // 2128H Error IGBT Temp.
	"DI State REC.   Hex ",	   // 2129H Error MI State  
	"DO State REC.   Hex ",	   // 212AH Error MO State  
	"Drive State REC.Hex ",	   // 212BH Error Drive St.    
};

const string20 c22info[C22MAX]={
//   12345678901234561234   //
    "PID Feedback        ",	   //00 2200H  PID Feedback
    "User define(LWd)    ",    //01 2201H  User define(LWd)
    "User define(HWd)    ",    //02 2202H  User define(HWd)
    "AUI1            %   ",    //03 2203H  AUI1 
    "ACI             %   ",    //04 2204H  ACI
    "AUI2            %   ",    //05 2205H  AUI2
    "IGBT Temp.      C   ",    //06 2206H  IGBT Temp.
    "HeatSink Temp.  C   ",    //07 2207H  HeatSink Temp.
    "DI ON/OFF Status    ",    //08 2208H  Reserved
    "DO ON/OFF Status    ",    //09 2209H  Reserved
    "Reserved            ",    //10 220AH  Reserved
    "Reserved            ",    //11 220BH  Reserved
    "Debug Page Num.     ",    //12 220CH  Debug Page Num.
    "Z Pulse Flag        ",    //13 220DH  Z Pulse Flag
    "GFF Analog          ",    //14 220EH  GFF Analog
    "Safety & CC Flag    ",    //15 220FH  Safety & CC Flag
    "Date Code Y.WKD     ",    //16 2210H  Date Code
    "                    ",    //17 2211H  Date Code
    "                    ",    //18 2212H  Date Code
    "                    ",    //19 2213H  Date Code
    "                    ",    //20 2214H  Date Code
    "                    ",    //21 2215H  Date Code
    "                    ",    //22 2216H  Date Code
    "                    ",    //23 2217H  Date Code
    "                    ",    //24 2218H  Date Code
    "                    ",    //25 2219H  Date Code  
    "                    ",    //26 221AH  Date Code 
    "                    ",    //27 221BH  Date Code 
    "                    ",    //28 221CH  Date Code 
    "                    ",    //29 221DH  Date Code 
    "                    ",    //30 221EH  Date Code 
    "                    ",    //31 221FH  Date Code 
    "Cmd Freq. REC.  Hz  ",    //32 2220H Error Fcmd      
    "Out Freq. REC.  Hz  ",    //33 2221H Error Fout      
    "Isum Value REC. Amps",    //34 2222H Error Isum      
    "Motor Freq. REC.Hz  ",    //35 2223H Error Ffbk      
    "Out Voltage REC.V   ",    //36 2224H Error Vout      
    "DcBus Value REC.V   ",    //37 2225H Error Vbus      
    "Out Power REC.  KW  ",    //38 2226H Error Power     
    "Out Torque REC. %   ",    //39 2227H Error Torque    
    "IGBT Temp. REC. C   ",    //40 2228H Error IGBT Temp.
    "DI State REC.   Hex ",    //41 2229H Error MI State  
    "DO State REC.   Hex ",    //42 222AH Error MO State  
    "Drive State REC.Hex ",    //43 222BH Error Drive St.    
      
};

#if Language_EN
const string20 errinfo[(ERRMAX+1)]={
//   12345678901234561234   //
    "No error            ",    //0
    "oc at Accel     ocA ",    //1
    "oc at Decel     ocd ",    //2
    "oc at Normal SPDocn ",    //3
    "Ground Fault    GFF ",    //4
    "Short Circuit   occ ",    //5
    "oc at Stop      ocS ",    //6
    "ov at Accel     ovA ",    //7    
    "ov at Decel     ovd ",    //8
    "ov at Normal SPDovn ",    //9
    "ov at Stop      ovS ",    //10
    "Lv at Accel     LvA ",    //11
    "Lv at Decel     Lvd ",    //12
    "Lv at Normal SPDLvn ",    //13
    "Lv at Stop      LvS ",    //14
    "Phase Loss      PHL ",    //15
    "IGBT Over Heat  oH1 ",    //16
    "Capacitance oH  oH2 ",    //17
    "Thermo 1 Open   tH1o",    //18
    "Thermo 2 Open   tH2o",    //19
    "Fan Locked      FAn ",    //20
    "Over Load       oL  ",    //21
    "Thermal Realy 1 EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "Motor Over Heat oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "Over Torque 1   ot1 ",    //26
    "Over Torque 2   ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "EEPROM Write ErrcF1 ",    //30
    "EEPROM Read Err cF2 ",    //31
    "Isum Sensor Err cd0 ",    //32
    "Ias Sensor Err  cd1 ",    //33
    "Ibs Sensor Err  cd2 ",    //34
    "Ics Sensor Err  cd3 ",    //35
    "cc HW Error     Hd0 ",    //36
    "oc HW Error     Hd1 ",    //37
    "ov HW Error     Hd2 ",    //38
    "GFF HW Error    Hd3 ",    //39
    "Auto Tuning Err AUE ",    //40
    "PID Fbk Error   AFE ",    //41
    "PG Fbk Error    PGF1",    //42
    "PG Fbk Loss     PGF2",    //43
    "PG Fbk Over SPD PGF3",    //44
    "PG Fbk Deviate  PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "External Fault  EF  ",    //49
    "Emergency Stop  EF1 ",    //50
    "Base Block      bb  ",    //51
    "Password Error  Pcod",    //52
    "SW Code Error   ccod",    //53
    "Comm. Cmd. Err  cE01",    //54
    "Data Addr. Err  cE02",    //55
    "Data length Err cE03",    //56
    "Wrong Writing   cE04",    //57
    "Comm, Time Out  cE10",    //58
    "Keypad Time Out cP10",    //59
    "Braking Fault   BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "Safety Relay ErrSRY ",    //63  add by dino, 06/06/2007
    "Mech. Brake FailMBF ",    //64  add by dino, 05/14/2008
    "PG HW Error     PGF5",    //65
    "Contactor Fail  MCF ",    //66
    "Motor Phase LossMPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus Off     CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "Over Acc.       PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "STO Loss 1      STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd Wrong WirePGcd",    //73  [Safty function, Bernie, 2013/10/29]
    "PG Hall loss ErrPGHL",    //74
    "Z Sig. loss Err PGAF",    //75
    "Safe Torque Off STO ",    //76
    "STO Loss 2      STL2",    //77
    "STO Loss 3      STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "Contact Service SERV",    //81
    "U Phase Loss    OPHL",    //82
    "V Phase Loss    OPHL",    //83
    "W Phase Loss    OPHL",    //84
    "DLC Ctrl MethodDLCC",     //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "Lv Sensor Short LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "Lv Sensor Open  LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "Cur. Ctrl. Err  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "STO Short       STL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "STO at Running  STOr",    //90  //#12225,STO error at running 
    "STO Short       STOS",    //91  //#12225,STO Short error
    "Sensor817 Err   SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 Err   SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTTx Fail        btt",    //94	 //BTT Test Fail [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Error      bttE",    //95	 //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE Error Lock  AEL ",    //97//[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_TC
const string20 errinfo_tc[(ERRMAX+1)]={
//   12345678901234561234   //
    "No error            ",    //0
    "加速中過電流    ocA ",    //1
    "減速中過電流    ocd ",    //2
    "定速運轉中過電流ocn ",    //3
    "接地過電流      GFF ",    //4
    "IGBT上下橋短路  occ ",    //5
    "停止中過電流    ocS ",    //6
    "加速中過電壓    ovA ",    //7    
    "減速中過電壓    ovd ",    //8
    "定速運轉中過電壓ovn ",    //9
    "停止中過電壓    ovS ",    //10
    "加速中低電壓    LvA ",    //11
    "減速中低電壓    Lvd ",    //12
    "定速運轉中低電壓Lvn ",    //13
    "停止中低電壓    LvS ",    //14
    "入電欠相保護    PHL ",    //15
    "IGBT溫度過高    oH1 ",    //16
    "電源電容溫度過高oH2 ",    //17
    "IGBT溫度偵測異常tH1o",    //18
    "電容溫度偵測異常tH2o",    //19
    "風扇異常        FAn ",    //20
    "驅動器過負載    oL  ",    //21
    "電機過負載      EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "電機過熱        oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "過轉矩1         ot1 ",    //26
    "過轉矩2         ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "記憶體寫入異常  cF1 ",    //30
    "記憶體讀出異常  cF2 ",    //31
    "Isum電流偵測異常cd0 ",    //32
    "U相電流偵測異常 cd1 ",    //33
    "V相電流偵測異常 cd2 ",    //34
    "W相電流偵測異常 cd3 ",    //35
    "CC硬體線路異常  Hd0 ",    //36
    "OC硬體線路異常  Hd1 ",    //37
    "OV硬體線路異常  Hd2 ",    //38
    "GFF硬體線路異常 Hd3 ",    //39
    "電機自動量測錯誤AUE ",    //40
    "PID 回授錯誤    AFE ",    //41
    "PG回授異常      PGF1",    //42
    "PG回授斷線      PGF2",    //43
    "PG回授失速      PGF3",    //44
    "PG轉差異常      PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "外部錯誤訊號輸入EF  ",    //49
    "外部端子緊急停止EF1 ",    //50
    "Base Block      bb  ",    //51
    "密碼輸入三次錯誤Pcod",    //52
    "SW Code Error   ccod",    //53
    "不合法通訊命令  cE01",    //54
    "不合法通訊位址  cE02",    //55
    "通訊資料長度錯誤cE03",    //56
    "通訊寫入唯讀位置cE04",    //57
    "MODBUS傳輸超時  cE10",    //58
    "KEYPAD傳輸超時  cP10",    //59
    "偵測煞車晶體異常BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "安全迴路異常    SRY ",    //63  add by dino, 06/06/2007
    "機械煞車回授異常MBF ",    //64  add by dino, 05/14/2008
    "PG硬體偵測異常  PGF5",    //65
    "電磁接觸器異常  MCF ",    //66
    "輸出欠相        MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus 斷線    CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "電梯過加速度    PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "安全轉矩遺失1   STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd線路異常   PGcd",    //73  [Safty function, Bernie, 2013/10/29]
    "PG 絕對訊號異常 PGHL",    //74
    "PG Z相訊號遺失  PGAF",    //75
    "安全轉矩輸出停止STO ",    //76
    "安全轉矩遺失2   STL2",    //77
    "安全轉矩遺失3   STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "服務逾時        SERV",    //81
    "輸出欠相 U相    OPHL",    //82
    "輸出欠相 V相    OPHL",    //83
    "輸出欠相 W相    OPHL",    //84
    "DLC控制模式錯誤 DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "平層開關短路    LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "平層開關開路    LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "電流環控制異常  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "安全轉矩迴路沾黏STL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "安全轉矩輸出停止STOr",    //90  //#12225,STO error at running 
    "安全轉矩迴路沾黏STOS",    //91  //#12225,STO Short error
    "Sensor817 錯誤  SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 錯誤  SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTT 失敗         btt",    //94	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT 錯誤        bttE",    //95  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE錯誤鎖定     AEL ",		//97[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_SC
const string20 errinfo_sc[(ERRMAX+1)]={
//   12345678901234561234   //
    "No error            ",    //0
    "樓厒笢徹萇霜    ocA ",    //1
    "熬厒笢徹萇霜    ocd ",    //2
    "隅厒堍蛌笢徹萇霜ocn ",    //3
    "諉華徹萇霜      GFF ",    //4
    "IGBT奻狟Э傻繚  occ ",    //5
    "礿砦笢徹萇霜    ocS ",    //6
    "樓厒笢徹萇揤    ovA ",    //7    
    "熬厒笢徹萇揤    ovd ",    //8
    "隅厒堍蛌笢徹萇揤ovn ",    //9
    "礿砦笢徹萇揤    ovS ",    //10
    "樓厒笢腴萇揤    LvA ",    //11
    "熬厒笢腴萇揤    Lvd ",    //12
    "隅厒堍蛌笢腴萇揤Lvn ",    //13
    "礿砦笢腴萇揤    LvS ",    //14
    "�賮褘煙鈺˙�    PHL ",    //15
    "IGBT恲僅徹詢    oH1 ",    //16
    "萇埭萇�楱繞�徹詢oH2 ",    //17
    "IGBT恲僅淈聆祑都tH1o",    //18
    "萇�楱繞�淈聆祑都tH2o",    //19
    "瑞圮祑都        FAn ",    //20
    "��雄ん徹婥      oL  ",    //21
    "萇儂徹蛹婥      EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "萇儂徹��        oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "徹蛌撻1         ot1 ",    //26
    "徹蛌撻2         ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "暮砪极迡�遻麭�  cF1 ",    //30
    "暮砪极黍堤祑都  cF2 ",    //31
    "Isum萇霜淈聆祑都cd0 ",    //32
    "U眈萇霜淈聆祑都 cd1 ",    //33
    "V眈萇霜淈聆祑都 cd2 ",    //34
    "W眈萇霜淈聆祑都 cd3 ",    //35
    "CC茞极盄繚祑都  Hd0 ",    //36
    "OC茞极盄繚祑都  Hd1 ",    //37
    "OV茞极盄繚祑都  Hd2 ",    //38
    "GFF茞极盄繚祑都 Hd3 ",    //39
    "萇儂赻雄講聆渣昫AUE ",    //40
    "PID 隙忨渣昫    AFE ",    //41
    "PG隙忨祑都      PGF1",    //42
    "PG隙忨剿盄      PGF2",    //43
    "PG隙忨囮厒      PGF3",    //44
    "PG蛌船祑都      PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "俋窒渣昫捅瘍怀�蕄F  ",    //49
    "俋窒傷赽踡摹礿砦EF1 ",    //50
    "Base Block      bb  ",    //51
    "躇鎢怀�躽�棒渣昫Pcod",    //52
    "SW Code Error   ccod",    //53
    "祥磁楊籵捅韜鍔  cE01",    //54
    "祥磁楊籵捅弇硊  cE02",    //55
    "籵捅訧蹋酗僅渣昫cE03",    //56
    "籵捅迡�輷邑蹉閥壢E04",    //57
    "MODBUS換怀閉奀  cE10",    //58
    "KEYPAD換怀閉奀  cP10",    //59
    "淈聆伢陬儒极祑都BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "假�姣娷煉麭�    SRY ",    //63  add by dino, 06/06/2007
    "儂迮伢陬隙忨祑都MBF ",    //64  add by dino, 05/14/2008
    "PG茞极淈聆祑都  PGF5",    //65
    "萇棠諉揖ん祑都  MCF ",    //66
    "怀堤Й眈        MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus 剿盄    CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "萇枍徹樓厒僅    PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "假�度知寋戀�1   STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd盄繚祑都   PGcd",    //73
    "PG 橈勤捅瘍祑都 PGHL",    //74
    "PG Z眈捅瘍疻囮  PGAF",    //75
    "假�度知婽銙黭�砦STO ",    //76
    "假�度知寋戀�2   STL2",    //77
    "假�度知寋戀�3   STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "督昢貣奀        SERV",    //81
    "怀堤Й眈 U眈    OPHL",    //82
    "怀堤Й眈 V眈    OPHL",    //83
    "怀堤Й眈 W眈    OPHL",    //84
    "DLC諷秶耀宒渣昫 DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "す脯羲壽傻繚    LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "す脯羲壽羲繚    LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "萇霜遠諷秶祑都  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "假�度知婸娷煬湘又TL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "假�度知婽銙黭�砦STOr",    //90  //#12225,STO error at running 
    "假�度知婸娷煬湘又TOS",    //91  //#12225,STO Short error
    "Sensor817 渣昫  SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 渣昫  SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTT 囮啖         btt",    //94	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT 渣昫        bttE",    //95  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE渣昫坶隅     AEL ",    //97//[AFE Error Handle/Lyabryan/2022/03/24]

};
#endif

#if Language_TR
const string20 errinfo_tur[(ERRMAX+1)]={
//   12345678901234561234   //
    "Hata yok            ",    //0
    "oc hizlanmada   ocA ",    //1
    "oc yavaSlamada  ocD ",    //2
    "oc normal SPD   ocn ",    //3
    "Toprak hatasi   GFF ",    //4
    "Kisa devre      occ ",    //5
    "oc durusta      ocS ",    //6
    "ov hizlanmada   ovA ",    //7    
    "ov yavaslamada  ovd ",    //8
    "ov normal SPD   ovn ",    //9
    "oc durusta      ovS ",    //10
    "Lv hizlanmada   LvA ",    //11
    "Lv yavaslamada  Lvd ",    //12
    "Lv normal SPD   Lvn ",    //13
    "Lv durusta      LvS ",    //14
    "Faz kaybi       PHL ",    //15
    "IGBT asiri isi  oH1 ",    //16
    "Kapasitor oH    oH2 ",    //17
    "Termik 1 acik   tH1o",    //18
    "Termik 2 acik   tH2o",    //19
    "Fan Kilitli     FAn ",    //20
    "Asiri yuk        oL ",    //21
    "Termik role 1   EoL1",    //22
    "Termik role 2   EoL2",    //23
    "Motor asiri isi oH3 ",    //24
    "Sigorta hatasi  FUSE",    //25
    "Asiri tork 1    ot1 ",    //26
    "Asiri tork 2    ot2 ",    //27
    "Dusuk tork 1    uc1 ",    //28
    "Dusuk tork 2    uc2 ",    //29
    "EEPROM Yazma    cF1 ",    //30
    "EEPROM Okuma    cF2 ",    //31
    "Isum Sensor Err cd0 ",    //32
    "Ias Sensor hata cd1 ",    //33
    "Ibs Sensor hata cd2 ",    //34
    "Ics Sensor hata cd3 ",    //35
    "cc HW hata      Hd0 ",    //36
    "oc HW hata      Hd1 ",    //37
    "ov HW hata      Hd2 ",    //38
    "GFF HW hata     Hd3 ",    //39
    "Oto Tune hata   AUE ",    //40
    "PiD Fbk hata    AFE ",    //41
    "PG Fbk hata     PGF1",    //42
    "PG Fbk Kaybi    PGF2",    //43
    "PG Fbk AsiriHiz PGF3",    //44
    "PG Fbk Sapma    PGF4",    //45
    "PG Ref Hata     PGr1",    //46
    "PG Ref Kaybi    PGr2",    //47
    "ACi kaybi       ACE ",    //48
    "Harici Hata     EF  ",    //49
    "Acil stop       EF1 ",    //50
    "Base Block      bb  ",    //51
    "Sifre Hatasi    Pcod",    //52
    "SW Code Error   ccod",    //53
    "Comm. Cmd. Err  cE01",    //54
    "Data Adres Hata cE02",    //55
    "Data Uzun Hata  cE03",    //56
    "Yanlis Yazma    cE04",    //57
    "HaberlesmeKoptu cE10",    //58
    "Ekran Koptu     cP10",    //59
    "Frenleme hatasi BF  ",    //60
    "Y-UcgenBaglanti ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "Guvenlik RoleErrSRY ",    //63  add by dino, 06/06/2007
    "Mekanik fren FailMBF",    //64  add by dino, 05/14/2008
    "PG HW Hatasi    PGF5",    //65
    "KontaktorHatasi MCF ",    //66
    "Motor Faz Kaybi MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus Off     CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "Over Acc.       PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "STO Loss 1      STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd Wrong WirePGcd",    //73  [Safty function, Bernie, 2013/10/29]
    "PG Hall loss ErrPGHL",    //74
    "Z Sig. loss Err PGAF",    //75
    "Safe Torque Off STO ",    //76
    "STO Loss 2      STL2",    //77
    "STO Loss 3      STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "ServisleGorusun SERV",    //81
    "U Faz Eksik     OPHL",    //82
    "V Faz Eksik     OPHL",    //83
    "W Faz Eksik     OPHL",    //84
    "DLC Ctrl MethodDLCC",     //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "Lv Sensor Short LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "Lv Sensor Open  LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "Cur. Ctrl. Err  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "STO Loss 4      STL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "STO at Running  STOr",    //90  //#12225,STO error at running 
    "STO Short       STOS",    //91  //#12225,STO Short error
    "Sensor817 Hata  SnE7",    //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Sensor818 Hata  SnE8",    //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "BTTx Fail        btt",    //94	 //BTT Test Fail [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Error      bttE",    //95	 //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE Error Lock  AEL ",    //97//[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_RUS
const string20 errinfo_rus[(ERRMAX+1)]={
//   12345678901234561234   //
    "調碄寍睠          ",      //0
    "賴梑.瘑硞.蝁筊ocA ",      //1
    "賴梑.瘑硞.豝喿ocd ",      //2
    "賴梑.瘑硞.椴    ocn ",    //3
    "煩塝楅 赹嗖 GFF ",        //4
    "管頏瘖皙 豝塝 occ ",      //5
    "賴梑.瘑硞.睙瑱ocS ",      //6
    "賴梑.楅葮.蝁筊ovA ",      //7    
    "賴梑.楅葮.豝喿ovd ",      //8
    "賴梑.楅葮.椴    ovn ",    //9
    "賴梑.楅葮.睙瑱ovS ",      //10
    "諍楅葮.蝁筊 LvA ",        //11
    "諍楅葮.豝喿 Lvd ",        //12
    "諍楅葮.椴     Lvn ",      //13
    "諍楅葮.睙瑱 LvS ",        //14
    "豭甀黽 砱. 餇郴 PHL ",    //15
    "諾雎豻梑 IGBT   oH1 ",    //16
    "諾雎豻梑 筊楗.  oH2 ",    //17
    "曇寍.甀靸痽凄1tH1o",      //18
    "曇寍.甀靸痽凄2tH2o",      //19
    "旋睠.眙楀.      FAn ",    //20
    "諾雎豻蜨 葠 瘑筎oL  ",    //21
    "謬葾.豝橞瑱 婞1 EoL1",    //22
    "謬葾.豝橞瑱 婞2 EoL2",    //23
    "諾雎豻梑 婞寔凄.oH3 ",    //24
    "曇寍.葮梊碚   FuSE",      //25
    "賴梑錒. 嗍喿楀ot1 ",      //26
    "賴梑錒. 嗍喿楀ot2 ",      //27
    "調婝摵凄.嗍喿楀 uc1 ",    //28
    "調婝摵凄.嗍喿楀 uc2 ",    //29
    "曇.EEPROM豝   cF1 ",      //30
    "曇.EEPROM誺殎   cF2 ",    //31
    "曇.婕摦瘑硞 cd0 ",        //32
    "曇寍.朝 U-餇郴  cd1 ",    //33
    "曇寍.朝 V-餇郴  cd2 ",    //34
    "曇寍.朝 W-餇郴  cd3 ",    //35
    "唯葎碄寍硞 塶 Hd0 ",      //36
    "唯葎碄寍硞 oc Hd1 ",      //37
    "唯葎碄寍硞 ov Hd2 ",      //38
    "唯葎碄寍硞 occHd3 ",      //39
    "曇寍硞 倷瘑甀摵竑UE ",    //40
    "調痶愻擼媬葩AFE ",        //41
    "曇寍硞  PG  PGF1",        //42
    "豭甀黽  PG  PGF2",        //43
    "醜遻  PG    PGF3",        //44
    "曇寍.睭窙睚.PG  PGF4",    //45
    "曇寍. 嵁 砱.PGPGr1",      //46
    "豭甀黽 嵁砱.PGPGr2",      //47
    "豭甀黽 戫訒. ACIACE ",    //48
    "翌涷.戫訒.倷冓尰EF  ",    //49
    "翌涷曼冓崷鎂睧EF1 ",      //50
    "旋睠.戫嗍媎趉 bb  ",      //51
    "調眙靲醐 葎頏貵 Pcod",    //52
    "曇寍硞 筊婕 蕪  ccod",    //53
    "調眙筊筊嗝楗cE01",        //54
    "調眙俶婕楥錼cE02",        //55
    "調眙婤.婕楥錼 cE03",      //56
    "曇寍硞 豝萶戫   cE04",    //57
    "覆欿凅愻擼  cE10",        //58
    "覆欿凅蜄貵瑱  cP10",      //59
    "曼冓.瘑靸.雎趹摵BF  ",    //60
    "曇寍.砬Y-瘔涳荖dc ",      //61   
    "豭甀萶瑱,   dEb ",        //62   
    "煩橞瘕皙 雎觛   SRY ",    //63  add by dino, 06/06/2007
    "曇寍.喿瘑靸   MBF ",      //64  add by dino, 05/14/2008
    "唯碄寍PG硞飶PGF5",        //65
    "曇寍. 管楀倵瘑閛MCF ",    //66
    "憾鳪餇郴.婞寔.MPHL",      //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN 魆楅 睭窙.  CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "雎蝁崶      PGOA",        //71  [Safty function, Bernie, 2013/10/29]
    "倜鳪窳萶      STL1",      //72  [Safty function, Bernie, 2013/10/29]
    "魆捁痽窙俍    PGcd",      //73  [Safty function, Bernie, 2013/10/29]
    "魆扆栖.遽訒.俍PGHL",      //74
    "睭淀嬼寔幊      PGAF",    //75
    "欳睧撾窙毆喿楀  STO ",    //76
    "桏遻 戫 STO2  STL2",      //77
    "桏遻 戫 STO3  STL3",      //78
    "                    ",    //79
    "                    ",    //80
    "秠笭甀摐 谿   SERV",      //81
    "桏遻 U 餇郴     OPHL",    //82
    "桏遻 V 餇郴     OPHL",    //83
    "桏遻 W 餇郴     OPHL",    //84 
    "DLC Ctrl MethodDLCC",     //85 //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "Lv Sensor Short LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "Lv Sensor Open  LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "Cur. Ctrl. Err  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "假�度知婸娷煬湘又TL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "假�度知婽銙黭�砦STOr",    //90  //#12225,STO error at running 
    "假�度知婸娷煬湘又TOS",    //91  //#12225,STO Short error  
    "Sensor817 Err   SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 Err   SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTTx Fail        btt",    //94	 //BTT Test Fail [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Error      bttE",    //95	 //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE Error Lock  AEL ",    //97  //[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_EN
const string20 warninfo[(WARNMAX+1)]={
//   12345678901234561234   //
    "No error            ",
    "Comm. Cmd. Err  cE01", //warncode = 1
    "Data Adrr. Err  cE02", //warncode = 2
    "Data length Err cE03", //warncode = 3
    "Wrong Writing   cE04", //warncode = 4
    "Comm. Time Out  cE10", //warncode = 5
    "Keypad Time Out cP10", //warncode = 6
    "Keypad Copy Err SE1 ", //warncode = 7
    "Keypad Copy FailSE2 ", //warncode = 8
    "IGBT Over Heat  oH1 ", //warncode = 9
    "Capacitance oH  oH2 ", //warncode = 10
    "PID FBK Error   Pid ", //warncode = 11
    "Analog Loss     AnL ", //warncode = 12
    "under Current   uC  ", //warncode = 13
    "Auto-tune error AuE ", //warncode = 14
    "PG FBK Warn     PGF1", //warncode = 15
    "PG Loss Warn    PGF2", //warncode = 16
    "PG Fbk OverSPD  PGF3", //warncode = 17
    "PG Fbk Deviate  PGF4", //warncode = 18
    "Phase Loss      PHL ", //warncode = 19
    "Over Torque 1   ot1 ", //warncode = 20
    "Over Torque 2   ot2 ", //warncode = 21
    "Motor Over Heat oH3 ", //warncode = 22
    "C.C Warning     c.c ", //warncode = 23
    "Over Slip Warn  oSL ", //warncode = 24
    "Auto Tuning     tUn ", //warncdoe = 25
    "Fan Locked      FAn ", //warncode = 26
    "Can Bus Off     dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]
    "STO Warning     STOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "UCMP Warn       UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "Copy Model Err  SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "Contact Service SERV", //warncode = 31
    "Wrong DLC DIRcmd dir", //warncode = 32  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
    "UD1 Over Speed  UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "UD2 Over Speed  UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "UD3 Over Speed  UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "UD4 Over Speed  UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "DD1 Over Speed  DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "DD2 Over Speed  DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "DD3 Over Speed  DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "DD4 Over Speed  DDS4", //warncode = 40  // DD4_Vlim_WARN       
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "Lv Sensor Warn  LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO Sequence    STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO Short       STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
	"Sensor817 Warn  SnW7",	//warncode = 46  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 Warn  SnW8",	//warncode = 47  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTTx Testing    bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Normal     bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Success    bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
#endif

#if Language_TC
const string20 warninfo_tc[(WARNMAX+1)]={
//   12345678901234561234   //
    "No error            ",
    "不合法通訊命令  cE01", //warncode = 1
    "不合法通訊位址  cE02", //warncode = 2
    "通訊資料長度錯誤cE03", //warncode = 3
    "通訊寫入唯讀位址cE04", //warncode = 4
    "Modbus傳輸超時  cE10", //warncode = 5
    "Keypad傳輸超時  cP10", //warncode = 6
    "參數複製錯誤    SE1 ", //warncode = 7
    "參數複製失敗    SE2 ", //warncode = 8
    "IGBT過熱        oH1 ", //warncode = 9
    "電容過熱        oH2 ", //warncode = 10
    "PID  回授異常   Pid ", //warncode = 11
    "類比訊號異常    AnL ", //warncode = 12
    "電流過低        uC  ", //warncode = 13
    "參數自學習失敗  AuE ", //warncode = 14
    "PG回授異常      PGF1", //warncode = 15
    "PG回授斷線      PGF2", //warncode = 16
    "PG回授失速      PGF3", //warncode = 17
    "PG轉差異常      PGF4", //warncode = 18
    "輸入欠相        PHL ", //warncode = 19
    "過轉矩 1        ot1 ", //warncode = 20
    "過轉矩 2        ot2 ", //warncode = 21
    "電機過熱        oH3 ", //warncode = 22
    "C.C Warning     c.c ", //warncode = 23
    "滑差異常        oSL ", //warncode = 24
    "參數自學習中    tUn ", //warncdoe = 25
    "風扇異常        FAn ", //warncode = 26
    "Can Bus 斷線    dCAn", //warncode = 27   //[CAN Control, Sampo, 09/15/2010]
    "安全轉矩遺失警告STOA", //warncode = 28   //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "UCMP 執行警告   UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "機種不同複製錯誤SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "服務逾時        SERV", //warncode = 31
    "DLC方向命令錯誤  dir", //warncode = 32  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
    "上1級強減過速   UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "上2級強減過速   UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "上3級強減過速   UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "上4級強減過速   UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "下1級強減過速   DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "下2級強減過速   DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "下3級強減過速   DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "下4級強減過速   DDS4", //warncode = 40  // DD4_Vlim_WARN  
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "平層開關信號異常LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO時序異常     STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO沾黏         STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "Sensor817 警告  SnW7",	//warncode = 46
	"Sensor818 警告  SnW8",	//warncode = 47
	"BTTx 測試中     bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx 正常       bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx 成功\       bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
#endif

#if Language_SC
const string20 warninfo_sc[(WARNMAX+1)]={
//   12345678901234561234   //
    "No error            ",
    "祥磁楊籵捅韜鍔  cE01", //warncode = 1                                                                       
    "祥磁楊籵捅弇硊  cE02", //warncode = 2                                                                       
    "籵捅訧蹋酗僅渣昫cE03", //warncode = 3                                                                       
    "籵捅迡�輷邑蹉閥搾E04", //warncode = 4                                                                       
    "Modbus換怀閉奀  cE10", //warncode = 5                                                                       
    "Keypad換怀閉奀  cP10", //warncode = 6                                                                       
    "統杅葩秶渣昫    SE1 ", //warncode = 7                                                                       
    "統杅葩秶囮啖    SE2 ", //warncode = 8                                                                       
    "IGBT徹��        oH1 ", //warncode = 9                                                                       
    "萇�搮���        oH2 ", //warncode = 10                                                                      
    "PID  隙忨祑都   Pid ", //warncode = 11                                                                      
    "濬掀捅瘍祑都    AnL ", //warncode = 12                                                                      
    "萇霜徹腴        uC  ", //warncode = 13                                                                      
    "統杅赻悝炾囮啖  AuE ", //warncode = 14                                                                      
    "PG隙忨祑都      PGF1", //warncode = 15                                                                      
    "PG隙忨剿盄      PGF2", //warncode = 16                                                                      
    "PG隙忨囮厒      PGF3", //warncode = 17                                                                      
    "PG蛌船祑都      PGF4", //warncode = 18                                                                      
    "怀�踿煙�        PHL ", //warncode = 19                                                                      
    "徹蛌撻 1        ot1 ", //warncode = 20                                                                      
    "徹蛌撻 2        ot2 ", //warncode = 21                                                                      
    "萇儂徹��        oH3 ", //warncode = 22                                                                      
    "C.C Warning     c.c ", //warncode = 23                                                                      
    "賑船祑都        oSL ", //warncode = 24                                                                      
    "統杅赻悝炾笢    tUn ", //warncdoe = 25                                                                      
    "瑞圮祑都        FAn ", //warncode = 26                                                                      
    "Can Bus 剿盄    dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]                                //Sampo, 09/15/2010]
    "假�度知寋戀屁站漀TOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]//warncode = 28
    "UCMP 硒俴劑豢   UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "儂笱祥肮葩秶渣昫SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "督昢貣奀        SERV", //warncode = 31
    "奻1撰Ч熬徹厒   UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "奻2撰Ч熬徹厒   UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "奻3撰Ч熬徹厒   UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "奻4撰Ч熬徹厒   UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "狟1撰Ч熬徹厒   DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "狟2撰Ч熬徹厒   DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "狟3撰Ч熬徹厒   DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "狟4撰Ч熬徹厒   DDS4", //warncode = 40  // DD4_Vlim_WARN  
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "す脯羲壽陓瘍祑都LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO奀唗祑都     STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO桭薴         STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14 
    "Sensor817 劑豢  SnW7",	//warncode = 46
	"Sensor818 劑豢  SnW8",	//warncode = 47
	"BTTx 聆彸笢     bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Normal     bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Success    bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
#endif

#if Language_TR
const string20 warninfo_tur[(WARNMAX+1)]={   
//   12345678901234561234   //
    "Hata yok            ",
    "Bag. Komut Hata cE01", //warncode = 1
    "Veri Adres Hata cE02", //warncode = 2
    "Uzun VeriHatasi cE03", //warncode = 3
    "Yanlis Yazma    cE04", //warncode = 4
    "HaberlesmeKoptu cE10", //warncode = 5
    "Ekran Koptu     cP10", //warncode = 6
    "Keypad Koptu     SE1", //warncode = 7
    "Kopya Basarisiz  SE2", //warncode = 8
    "IGBT Asiri isi   oH1", //warncode = 9
    "Kapasitans oH    oH2", //warncode = 10
    "PID FBK Error    Pid", //warncode = 11
    "Analog Kaybi     AnL", //warncode = 12
    "Dusuk Akim        uC", //warncode = 13
    "Oto-tune Hatasi  AuE", //warncode = 14
    "PG FBK Uyari    PGF1", //warncode = 15
    "PG Loss Uyari   PGF2", //warncode = 16
    "PG Fbk AsiriHiz PGF3", //warncode = 17
    "PG Fbk Sapma    PGF4", //warncode = 18
    "Faz Kaybi        PHL", //warncode = 19
    "Asiri Tork 1     ot1", //warncode = 20
    "Asiri Tork 2     ot2", //warncode = 21
    "Motor Asiri Isi  oH3", //warncode = 22
    "KisaDevreUyari   c.c", //warncode = 23
    "Asiri Kayma      oSL", //warncode = 24
    "Auto Tuning      tUn", //warncdoe = 25
    "Fan Kilitli      FAn", //warncode = 26
    "Can Bus Off     dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]
    "STO Uyarisi     STOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "UCMP Uyarisi    UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "Copy Model Err  SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "Servisle GorusunSERV", //warncode = 31
    "Wrong DLC DIRcmd dir", //warncode = 32  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
    "UD1 Over Speed  UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "UD2 Over Speed  UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "UD3 Over Speed  UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "UD4 Over Speed  UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "DD1 Over Speed  DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "DD2 Over Speed  DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "DD3 Over Speed  DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "DD4 Over Speed  DDS4", //warncode = 40  // DD4_Vlim_WARN       
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "Lv Sensor Warn  LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO Sequence    STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO Short       STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "Sensor817 Uyari SnW7",	//warncode = 46
	"Sensor818 Uyari SnW8",	//warncode = 47
	"BTTx Testing    bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Normal     bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Success    bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
#endif

#if Language_RUS
const string20 warninfo_rus[(WARNMAX+1)]={
//   12345678901234561234   //
    "調碄寍睠          ",
    "調眙靲厞 筊嗝楗胉E01", //warncode = 1
    "調眙靲醐 俶雎 cE02",   //warncode = 2
    "調眙靲厞 婤嵋 cE03",   //warncode = 3
    "煩萶痶誺殎cE04",       //warncode = 4
    "覆欿凅愻擼  cE10",     //warncode = 5
    "覆欿凅蜄貵瑱  cP10",   //warncode = 6
    "曇寍硞 筊萶頏 SE1 ",   //warncode = 7
    "曇寍硞 筊萶頏 SE2 ",   //warncode = 8
    "諾雎豻梑 IGBT   oH1 ", //warncode = 9
    "諾雎豻梑 閛婥凄.oH2 ", //warncode = 10
    "曇寍硞  蕈Pid ",       //warncode = 11
    "憾鳪倎倯痵.   AnL ",   //warncode = 12
    "諍跁崷 瘑     uC  ",   //warncode = 13
    "曇寍硞 倷瘑楅摵.AuE ", //warncode = 14
    "曇寍硞  PG  PGF1",     //warncode = 15
    "豭甀黽  PG  PGF2",     //warncode = 16
    "醜遻  PG    PGF3",     //warncode = 17
    "曇寍.摍睒嬮.    PGF4", //warncode = 18
    "豭甀黽 砱痽. 餇脝HL ", //warncode = 19
    "賴梑錒. 嗍喿楀ot1 ",   //warncode = 20
    "賴梑錒. 嗍喿楀ot2 ",   //warncode = 21
    "諾雎豻梑 婞寔凄.oH3 ", //warncode = 22
    "賴梊蝃雎笪.織   c.c ", //warncode = 23
    "賴梑錒.摍睒嬮.  oSL ", //warncode = 24
    "曼瘑楅摵頏欹  tUn ",   //warncdoe = 25
    "旋睠.眙楀. Fan  FAn ", //warncode = 26
    "CAN 魆楅. 祒窙. dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]
    "賴梊蝃雎笪.STO  STOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "賴梊蝃雎笪UCMP  UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "曇寍.筊萶嗍婭臮E3 ",   //warncode = 30  COPY Fail 3, Model name Error   
    "轄攃嵕涫谿  SERV",     //warncode = 31
    "Wrong DLC DIRcmd dir", //warncode = 32  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
    "UD1 Over Speed  UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "UD2 Over Speed  UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "UD3 Over Speed  UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "UD4 Over Speed  UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "DD1 Over Speed  DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "DD2 Over Speed  DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "DD3 Over Speed  DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "DD4 Over Speed  DDS4", //warncode = 40  // DD4_Vlim_WARN       
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "Lv Sensor Warn  LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO Sequence    STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO Short       STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "Sensor817 Warn  SnW7",	//warncode = 46
	"Sensor818 Warn  SnW8",	//warncode = 47
	"BTTx Testing    bttA", //warncode = 43  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Normal     bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Success    bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
#endif


#if SIBO_ENABLE   
const string20 SIBO_SPOPTTABLE[6+1]={   // Prarmeter Group Description
   //12345678901234561234
    "Inspection Speed    ",     
    "Leveling Speed      ",     
    "Relevel. Speed      ",     
    "Low Speed           ",     
    "Medium Speed        ",     
    "High Speed          ",     
    "Nominal Speed       ",     
};
const string20 ENABLE_TABLE[1+1]={   // Prarmeter Group Description
   //12345678901234561234
    "DISABLE FUNCTION    ",     
    "ENABLE FUNCTION     ",     
};

const string20 SIBO_INS[2+1]={   // Prarmeter Group Description
   //12345678901234561234
   "ACC Inspection  m/s2"  ,   
   "DEC Inspection  m/s2"  ,   
   "Inspection Speedm/s "  ,   
};

const string20 SIBO_GROUP4[15+1]={   // Prarmeter Group Description
   //12345678901234561234
   "Termal Speed 1      "  ,   
   "Termal Speed 2      "  ,   
   "Termal Speed 3      "  ,   
   "Termal Speed 4      "  ,   
   "Termal Speed 5      "  ,   
   "Termal Speed 6      "  ,   
   "Termal Speed 7      "  ,   
   "Leveling Speed  m/s "  ,   
   "Relevel. Speed  m/s "  ,   
   "Low Speed       m/s "  ,   
   "Medium Speed    m/s "  ,   
   "High Speed      m/s "  ,   
   "Nominal Speed   m/s "  ,   
   "RESERVED            "  ,
   "RESERVED            "  ,    
   "RESERVED            "  ,
};
#endif

#if Language_EN
const string20 gpname[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "SYSTEM PARAMETER00  ",     //  Group  0
    "BASIC PARAMETER 01  ",     //  Group  1
    "DIGITAL IN/OUT  02  ",     //  Group  2
    "ANALOG IN/OUT   03  ",     //  Group  3
    "MULTI-SPEED     04  ",     //  Group  4
    "IM PARAMETER    05  ",     //  Group  5
    "PROTECTION      06  ",     //  Group  6
    "SPECIAL         07  ",     //  Group  7
    "PM PARAMETER    08  ",     //  Group  8
    "COMMUNICATION   09  ",     //  Group  9
    "SPEED FEEDBACK  10  ",     //  Group 10
    "ADVANCE SET     11  ",     //  Group 11
    "ACCESS PARAMETER12  ",     //  Group 12
    "DISPLAY USER-SET13  ",     //  Group 13
    "RESERVED        14  ",     //  Group 14
    "FACTORY         15  ",     //  Group 15
};
#endif

#if Language_TC
const string20 gpname_tc[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "系統參數        00  ",     //  Group 13
    "基本參數        01  ",     //  Group  0
    "數位端子功\能    02  ",    //  Group  1
    "類比端子功\能    03  ",    //  Group  2
    "多段速參數      04  ",     //  Group  3
    "IM 電機參數     05  ",     //  Group  4
    "保護參數        06  ",     //  Group  5
    "特殊參數        07  ",     //  Group  6
    "PM 馬達參數     08  ",     //  Group  7
    "通訊參數        09  ",     //  Group  8
    "速度回授參數    10  ",     //  Group  9
    "進階參數        11  ",     //  Group 10
    "用戶自定參數設定12  ",     //  Group 11
    "用戶設定參數查閱\13  ",    //  Group 12                  
    "RESERVED        14  ",     //  Group 14
    "FACTORY         15  ",     //  Group 15
};
#endif

#if Language_SC
const string20 gpname_sc[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "炵苀統杅        00  ",     //  Group 13
    "價掛統杅        01  ",     //  Group  0
    "杅弇傷赽髡夔    02  ",     //  Group  1
    "濬掀傷赽髡夔    03  ",     //  Group  2
    "嗣僇厒統杅      04  ",     //  Group  3
    "IM 萇儂統杅     05  ",     //  Group  4
    "悵誘統杅        06  ",     //  Group  5
    "杻忷統杅        07  ",     //  Group  6
    "PM 鎮湛統杅     08  ",     //  Group  7
    "籵捅統杅        09  ",     //  Group  8
    "厒僅隙忨統杅    10  ",     //  Group  9
    "詢撰統杅        11  ",     //  Group 10
    "蚚誧赻隅砱統杅  12  ",     //  Group 11
    "蚚誧扢隅統杅脤戙13  ",     //  Group 12
    "RESERVED        14  ",     //  Group 14
    "FACTORY         15  ",     //  Group 15
};
#endif

#if Language_TR
const string20 gpname_tur[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "SISTEM AYARLARI 00	 ",	   //  Group  0
    "TEMEL AYARLAR   01	 ",	   //  Group  1
    "DIJITAL GIR/CIK 02	 ",	   //  Group  2
    "ANALOG GIR/CIK  03	 ",	   //  Group  3
    "COKLU HIZ       04	 ",	   //  Group  4
    "IM AYARLARI     05	 ",	   //  Group  5
    "KORUMA          06	 ",	   //  Group  6
    "OZEL            07	 ",	   //  Group  7
    "PM AYARLARI     08	 ",	   //  Group  8
    "HABERLESME      09	 ",	   //  Group  9
    "ENKODER         10	 ",	   //  Group 10
    "GELISMIS AYAR   11	 ",	   //  Group 11
    "ERISIM AYARLARI 12	 ",	   //  Group 12
    "EKRAN KUL AYAR  13  ",	   //  Group 13
    "REZERVE         14	 ",	   //  Group 14
    "FABRIKA AYAR    15	 ",	   //  Group 15
    
};
#endif

#if Language_RUS
const string20 gpname_rus[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "膩幫螃葡噹  00  ",	       //  Group  0
    "掠膩幫撐臍  01  ",	       //  Group  1
    "晴褽. 符/粕   02  ",	   //  Group  2
    "偷偵噫.符/粕  03  ",	   //  Group  3
    "撳鉻繡-褽壁墾繡 04  ",	   //  Group  4
    "偭蜇散董兜絰05  ",	       //  Group  5
    "膩幫楣伓薦    06  ",	   //  Group  6
    "講腑. 膩幫    07  ",	   //  Group  7
    "襄褐. 散董兜絰08  ",	   //  Group  8
    "膩幫螻牁    09  ",	       //  Group  9
    "膩幫芺瑣斯幫  10  ",	   //  Group 10
    "晷膩幫撐臍  11  ",	       //  Group 11
    "膩幫晷謝藩  12  ",	       //  Group 12
    "蔑謝蕪鉻溝  13  ",	       //  Group 13
    "楣懇殿徽蛻噙    14  ",	   //  Group 14
    "楣移膩幫    15  ",	       //  Group 15
    
};
#endif

#if Language_EN
const string20 prinfo_ACC_ms2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"1st Accel Time  m/s2"	,	//	156	01-12	1st Acceleration time
	"1st Decel Time  m/s2"	,	//	157	01-13	1st Deceleration time
	"2nd Accel Time  m/s2"	,	//	158	01-14	2nd Acceleration time
	"2nd Decel Time  m/s2"	,	//	159	01-15	2nd Deceleration time
	"3rd Accel Time  m/s2"	,	//	160	01-16	3rd Acceleration time
	"3rd Decel Time  m/s2"	,	//	161	01-17	3rd Deceleration time
	"4th Accel Time  m/s2"	,	//	162	01-18	4th Acceleration time
	"4th Decel Time  m/s2"	,	//	163	01-19	4th Deceleration time
	"JOG Accel Time  m/s2"	,	//	164	01-20	JOG Acceleration time
	"JOG Decel Time  m/s2"	,	//	165	01-21	JOG Deceleration time
	"Stop Decel Time m/s2"
};

const string20 prinfo_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"1st Accel Time  f/s2"	,	//	156	01-12	1st Acceleration time
	"1st Decel Time  f/s2"	,	//	157	01-13	1st Deceleration time
	"2nd Accel Time  f/s2"	,	//	158	01-14	2nd Acceleration time
	"2nd Decel Time  f/s2"	,	//	159	01-15	2nd Deceleration time
	"3rd Accel Time  f/s2"	,	//	160	01-16	3rd Acceleration time
	"3rd Decel Time  f/s2"	,	//	161	01-17	3rd Deceleration time
	"4th Accel Time  f/s2"	,	//	162	01-18	4th Acceleration time
	"4th Decel Time  f/s2"	,	//	163	01-19	4th Deceleration time
	"JOG Accel Time  f/s2"	,	//	164	01-20	JOG Acceleration time
	"JOG Decel Time  f/s2"	,	//	165	01-21	JOG Deceleration time
	"Stop Decel Time f/s2"
};

const string20 prinfo_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S Curve Time 1  m/s3"	,	//	168	01-24	S curve Accel time 1
	"S Curve Time 2  m/s3"	,	//	169	01-25	S curve Accel time 2
	"S Curve Time 3  m/s3"	,	//	170	01-26	S curve Decel time 1
	"S Curve Time 4  m/s3"	,	//	171	01-27	S curve Decel time 2
	"S Curve Time 5  m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S Curve Time 1  f/s3"	,	//	168	01-24	S curve Accel time 1
	"S Curve Time 2  f/s3"	,	//	169	01-25	S curve Accel time 2
	"S Curve Time 3  f/s3"	,	//	170	01-26	S curve Decel time 1
	"S Curve Time 4  f/s3"	,	//	171	01-27	S curve Decel time 2
	"S Curve Time 5  f/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo[EPMAX] = {	
/*---- GROUP 15---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"DEBUG FLAG          "	,	//	0   15-00	Debug Flag 1	                                
	"DBC Change Freq.    "	,	//	1   15-01	DBC CHANGE FREQ	                                
	"EFFICIENCY      %   "	,	//	2   15-02	efficiency of Motor	                            
    "ZOffset Tune I  %   "  ,   //  3   15-03   Z Phase search current level                    
	"RATED-I AD VALUE    "	,	//	4   15-04	AD value at Rated Current	                    
	"Ide Iqe LPF Gain    "	,	//	5   15-05	Id*,Iq* LPF	                                    
	"Factory Serial 1    "	,	//	6   15-06	Only for Factory 1	                            
	"Factory Serial 2    "	,	//	7   15-07	Only for Factory 2	                            
	"Factory Serial 3    "	,	//	8   15-08	Only for Factory 3	                            
	"Factory Serial 4    "	,	//	9   15-09	Only for Factory 4	                            
	"REVERSE             "  ,   //  10  15-10   REVERSED   	//[move parameter to 11-20, Bernie, 2017/02/16]                
	"Skip DeadTime       "	,	//	11  15-11	Skip Dead Time	                                
	"210.0 VDC AD        "	,	//	12  15-12	DCBUS 210.0 VDC ad value	                    
	"310.0 VDC AD        "	,	//	13  15-13	DCBUS 310.0 VDC ad value	                    
	"390.0 VDC AD        "	,	//	14  15-14	DCBUS 390.0 VDC ad value	                    
	"TRQ_P               "	,	//	15  15-15	Torque control Kp	                            
	"TRQ_I               "	,	//	16  15-16	Torque Control Ki	                            
	"FLUX_P              "	,	//	17  15-17	Flux Control Kp	                                
	"FLUX_I              "	,	//	18  15-18	Flux Control Ki	                                
	"SpdSlop_P           "	,	//	19  15-19	Speed slop Control Kp gain	                    
	"SpdSlop_I           "	,	//	20  15-20	Speed slop Control Ki gain	                    
	"Control Select      "	,	//	21  15-21	Control Selection	                            
	"TEST SOURCE Amp.    "	,	//	22  15-22	Test Source Value Amplitude	                    
	"High Speed LPG  Hz  "	,	//	23  15-23	High Speed Low pass Filter Gain	                
	"Low Speed LPG   Hz  "	,	//	24  15-24	Low Speed Low pass filter Gain	                
	"TEST SOURCE Bias    "	,	//	25  15-25	Test Source Value Bias	                        
	"Est J LPG       s   "	,	//	26  15-26	Estimate J Low pass Filter Gain	                
	"Calibration A RE    "	,	//	27  15-27	Calibration current REF	                        
	"Calibration P       "	,	//	28  15-28	Calibration P	                                
	"Calibration I       "	,	//	29  15-29	Calibration I	                                
	"DC-Tun current P    "	,	//	30  15-30	Auto tuning DC test Kp gain	                    
	"DC-Tun current I    "	,	//	31  15-31	Auto Tuning DC test Ki gain	                    
	"High Freq. Tun P    "	,	//	32  15-32	Auto tuning High Freq. Lock test Kp gain	    
	"High Freq. Tun I    "	,	//	33  15-33	ADcbus Low Pass Gain	                        
	"Gain of VcmpMax %   "	,	//	34  15-34	Select Zero Speed	                            
	"NL-Boost Gain       "	,	//	35  15-35	No Load Boost Gain	                            
	"Auto Accel. KP      "	,	//	36  15-36	Acceleration AKP	                            
	"Auto Accel. KI      "	,	//	37  15-37	Acceleration AKI	                            
	"Current Loop BW     "	,	//	38  15-38	Current Loop BandWidth                          
	"DBC Leading 2       "	,	//	39  15-39	DBC Leading 2                                   
	"DBC Ration 2        "	,	//	40  15-40	DBC Ratio 2 with close loop                     
	"DBC Coef.           "	,	//	41  15-41	DBC Coef.                                       
	"DBC Dcbus Coef.     "	,	//	42  15-42	DBC Dcbus Coef.                                 
	"DBC Leading 1       "	,	//	43  15-43	DBC leading 1                                   
	"DBC Ratio 1         "	,	//	44  15-44	DBC Linear Ratio 1                              
	"RESERVE             "	,	//	45  15-45	DBC MODE                                        
	"Magnitization L1    "	,	//	46  15-46	magnitization inductance 1                      
	"Main Flux Link 1    "	,	//	47  15-47	main flux linkage 1                             
	"Magnitization L2    "	,	//	48  15-48	magnitization inductance 2                      
	"Main Flux Link 2    "	,	//	49  15-49	main flux linkage 2                             
	"Magnitization L3    "	,	//	50  15-50	magnitization inductance 3                      
	"Main Flux Link 3    "	,	//	51  15-51	main flux linkage 3                             
	"Magnitization L4    "	,	//	52  15-52	magnitization inductance 4                      
	"Main Flux Link 4    "	,	//	53  15-53	main flux linkage 4                             
	"Magnitization L5    "	,	//	54  15-54	magnitization inductance 5                      
	"Main Flux Link 5    "	,	//	55  15-55	main flux linkage 5                             
	"Magnitization L6    "	,	//	56  15-56	magnitization inductance 6                      
	"Main Flux Link 6    "	,	//	57  15-57	main flux linkage 6                             
	"Modulation Index    "	,	//	58  15-58	Modulation Index                                
	"Zero Current LPG    "	,	//	59  15-59	Current Zero Low Pass Gain                      
	"COSphi LPF      ms  "	,	//	60  15-60	cos(TB1_uwPhi) low pass gain                          
	"Date Code Y.WKD     "  ,   //  61  15-61   DateCode  //Datecode para change, Henry, 2016/07/20 
	"AUI2 0V ADC     adc "	,	//	62  15-62	calibration for AUI ZeroPoint (0V)
	"AUI2 -10V ADC   adc "	,	//	63  15-63	calibration for AUI2 max (-10V)
	"AUI2 +10V ADC   adc "	,	//	64  15-64	calibration for AUI2 min (+10V)
	"ACI 20mA ADC    adc "	,	//	65  15-65	calibration for ACI2 max (20mA)                 
	"ACI 12mA ADC    adc "	,	//	66  15-66	calibration for ACI mid (12mA)                  
	"ACI 4mA ADC     adc "	,	//	67  15-67	calibration for ACI min (4mA)                   
	"AUI1 0V ADC     adc "	,	//	68  15-68	calibration for AUI1 ZeroPoint (0V)
	"AUI1 -10V ADC   adc "	,	//	69  15-69	calibration for AUI1 max (-10V)
	"AUI1 +10V ADC   adc "	,	//	70  15-70	calibration for AUI1 min (+10V)
	"Auto Decel. DKP     "	,	//	71  15-71	Deceleration DKP                                
	"Auto Decel. DKI     "	,	//	72  15-72	Deceleration DKI                                
	"Low Speed Comp. Hz  "	,	//	73  15-73	more volt. comp. below this freq.               
	"PGLOSS Detcect T    "	,	//	74  15-74	PGLOSS Detect Counter                           
	"Main Frequency      "	,	//	75  15-75	Main Frequency                                  
	"Power On Counter    "	,	//	76  15-76	Power On Counter                                
	"GFF_Pk Detec SW     "	,	//	77  15-77	GFF Maximum Value Record Switch, Jerry Yu, 2019/11/11 
	"BLD Version         "	,	//	78  15-78   //[BootLoader Version, Special.Kung, 2022/10/31]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"SIBO EPS FRMODE     "  ,   //  79  15-79   SIBO EPS FRMODE
#else
    "RESERVE             "  ,   //  79  15-79
#endif
    "OPHL_SPER           "  ,   //  80  15-80
    "OPHL_CURER          "  ,   //  81  15-81
    "OPHL_ERCNT          "  ,   //  82  15-82                               
	"BLD DateCode        "  ,   //  83  15-83   //[BootLoader DataCode, Special.Kung, 2022/10/31]               
	"FineAUI 0V ADC  adc "	,	//	84  15-84	calibration for AUI ZeroPoint (0V)              
	"FineAUI +2V ADC adc "	,	//	85  15-85	calibration for AUI max (+2V)                   
	"FineAUI -2V ADC adc "	,	//	86  15-86	calibration for AUI min (-2V)                   
	"SIN MAX V ADC   adc "	,	//	87  15-87	calibration for SIN max, add by dino, 06/01/2007
	"SIN MIN V ADC   adc "	,	//	88  15-88	calibration for SIN min, add by dino, 06/01/2007
	"COS MAX V ADC   adc "	,	//	89  15-89	calibration for COS max, add by dino, 06/01/2007
	"COS MIN V ADC   adc "	,	//	90  15-90	calibration for COS min, add by dino, 06/01/2007
    "Min. Pulse Width    "  ,   //  91  15-91   minimum pulse, ADDED BY SCOTTY,2007/07/11
	"D Frame FAN Cont    "	,	//	92 	15-92	D Frame Fan control
	"Z Phase UVW Sect    "	,	//	93 	15-93	Z phase UVW Section when PG_TYPE = 2
	"RESERVE             "  ,   //  94  15-94
    "LAST PG COUNTER     "  ,   //  95  15-95   PG Position Record, add by scotty, 12/07/2007
	"AFM MAX. Value      "	,	//	96 	15-96   AFM max. value
	"AFM MIN. Value      "	,	//	97 	15-97   AFM min. value
	"Soft Start Time sec "	,	//	98  15-98	Softstart Delay Time
	"DEBUG FLAG2         "  ,   //  99  15-99   //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
	"Z-cab Mode          "  ,   //  100 15-100
	"Qer_min             "  ,   //  101 15-101
	"Qer_Shift           "  ,   //  102 15-102
	"Sin_HS_Tab          "  ,   //  103 15-103
	"RESERVE             "  ,   //  104 15-104
	"RESERVE             "	,	//	105 15-105  RESERVED
	"CAN Control         "	,	//	106 15-106  Can Control      //[CAN Control, Sampo, 09/15/2010]
	"CAN Fault Handle    "	,	//	107 15-107  Can Fault Handle //[CAN Control, Sampo, 09/15/2010]
	"DEBUG_PG            "	,	//	108 15-108  DEBUG_PG
	"_47th_DISP          "	,	//	109 15-109  _47th_DISP
	"PG_MODE             "	,	//	110 15-110  RESERVED
	"WDT Divider         "	,	//	111 15-111  WDT_DIV     //[ICT WDT test, Bernie, 08/16/2011]
	"AFM1 +10V CNT       "	,	//	112 15-112  AFM1_P10CNT for AFM1 +10V output
	"AFM1 0V CNT         "	,	//	113 15-113  AFM1_0CNT for AFM1 0V output
	"AFM1 -10V CNT       "	,	//	114 15-114  AFM1_M10CNT for AFM1 -10V output
	"AFM2 +10V CNT       "	,	//	115 15-115  AFM2_P10CNT for AFM2 +10V output
	"AFM2 0V CNT         "	,	//	116 15-116  AFM2_0CNT for AFM2 0V output
	"AFM2 -10V CNT       "	,	//	117 15-117  AFM2_M10CNT for AFM2 -10V output
	"Protect Bit SW      "	,	//	118 15-118  The switch of Protect finction         //[The switch of Protect finction, Bernie, 2015/05/21]
	"OPHL COUNT          "	,	//	119 15-119  The Count of Protect finction          //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL IRMS           "	,	//	120 15-120  The IRMS value of Protect finction     //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL COUNT          "	,	//	121 15-121  The Gain value of Protect finction     //[Output Phase Loss 2, Sampo, 2015/05/21]
	"PPI filter point    "	,	//	122 15-122  RESERVED
	"MBF Recoder         "	,	//	123 15-123  MBF record after power off
	"EoL Cnt Recder H    "	,	//	124 15-124  RESERVED       //[add for UL EoL Verification,Bernie, 2013/04/22]
	"EoL Cnt Recder L    "	,	//	125 15-125  RESERVED       //[add for UL EoL Verification,Bernie, 2013/04/22]
	"RESERVE             "	,	//	126 15-126  RESERVED
	"Unavailable         "	,	//	127 15-127  RESERVED
//	"PPI filter point    "	,	//	128 15-128  PPI control    //[PPI function, Sampo, 2015/09/08]

/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
	"Identity Code       "	,	//	128 00-00	Model Type of Drive 
	"Rated Current   Amps"	,	//	129 00-01	Rated Current
	"Parameter Reset     "	,	//	130 00-02	Parameter Reset
	"Start up Display    "	,	//	131 00-03	Start up Display
	"User Display        "	,	//	132 00-04	User Display
	"User Coefficient    "	,	//	133	00-05	User Coefficient
	"Firmware Version    "	,	//	134	00-06	Software Version
	"Password decoder    "	,	//	135	00-07	Password Input
	"Password Input      "	,	//	136	00-08	Password Input
	"Control Method      "	,	//	137	00-09	Control Methods
	"Speed Unit Sel.     "	,	//	138	00-10	Velocity Unit Select
	"CHG. Output DIR     "	,	//	139 00-11   Change Output Direction, Added by sampo , 06/11/2009
	"Carry Frequency KHz "	,	//	140	00-12	Carry Frequency
	"AVR                 "	,	//	141	00-13	AVR
	"Source of Freq.     "	,	//	142	00-14	Source of Freq. Command
	"Source of Oper.     "	,	//	143	00-15	Source of Oper. Command

/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"Max Output Freq.Hz  "	,	//	144	01-00	Max Output Freq.
	"Motor1 Fbase    Hz  "	,	//	145	01-01	Motor Base Frequency 1
	"Max Out-Volt 1  V   "	,	//	146	01-02	Max Output Voltage
	"Mid Out-Freq.1-1Hz  "	,	//	147	01-03	Mid Output Freq.1
	"Mid Out-Volt 1-1V   "	,	//	148	01-04	Mid Output Voltage 1
	"Mid Out-Freq.1-2Hz  "	,	//	149	01-05	Mid Output Freq.2
	"Mid Out-Volt 1-2V   "	,	//	150	01-06	Mid Output Voltage 2
	"Min Out-Freq.1  Hz  "	,	//	151	01-07	Min Output Freq.
	"Min Out-Volt 1  V   "	,	//	152	01-08	Min Output Voltage
	"Start Frequency Hz  "	,	//	153	01-09	Start Frequency
	"Upper Bound FreqHz  "	,	//	154	01-10	Upper Bound Freq.
	"Lower Bound FreqHz  "	,	//	155	01-11	Lower Bound Freq.
	"1st Accel Time  sec "	,	//	156	01-12	1st Acceleration time
	"1st Decel Time  sec "	,	//	157	01-13	1st Deceleration time
	"2nd Accel Time  sec "	,	//	158	01-14	2nd Acceleration time
	"2nd Decel Time  sec "	,	//	159	01-15	2nd Deceleration time
	"3rd Accel Time  sec "	,	//	160	01-16	3rd Acceleration time
	"3rd Decel Time  sec "	,	//	161	01-17	3rd Deceleration time
	"4th Accel Time  sec "	,	//	162	01-18	4th Acceleration time
	"4th Decel Time  sec "	,	//	163	01-19	4th Deceleration time
	"JOG Accel Time  sec "	,	//	164	01-20	JOG Acceleration time
	"JOG Decel Time  sec "	,	//	165	01-21	JOG Deceleration time
	"JOG Frequency   Hz  "	,	//	166	01-22	JOG Frequency
	"Trans ACC/DEC1-4Hz  "	,	//	167	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"S Curve Time 1  sec "	,	//	168	01-24	S curve Accel time 1
	"S Curve Time 2  sec "	,	//	169	01-25	S curve Accel time 2
	"S Curve Time 3  sec "	,	//	170	01-26	S curve Decel time 1
	"S Curve Time 4  sec "	,	//	171	01-27	S curve Decel time 2
	"Select Zero Spd     "	,	//	172	01-28	Select Zero Speed
	"Landing Speed   Hz  "	,	//	173	01-29	Landing Frequency 
	"S Curve Time 5  sec "	,	//	174	01-30	S curve Decel time 3
	"Stop Decel Time sec "	,	//	175	01-31	Stop Deceleration time
    "Force Decel Spd m/s "	,	//	1xx	01-32
    "IOD Hold Time   sec "	,	//	1xx	01-33   IODHT IO direct hold time   
    "IOD Land Time   sec "	,	//	1xx	01-34   IODLT IO direct landing freq
    "CRPLS Jerk lim      "	,	//	1xx	01-35   IODLT IO direct landing time
    "IOD Dec Point   cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "IOD D.Point Ref m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "IODLC Enable        "	,	//	1xx	01-38   IODLT IO direct DistancE
    "ETS Frequency   Hz  "  ,   //  1xx 01-39   IODLT IO direct DistancE
    "ESD Decel Time  sec "	,	//	1xx	01-40   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105  RESERVE
    "Emergency S3    sec "  ,   //  105 15-105  RESERVE
    "Emergency S4    sec "  ,   //  105 15-105  RESERVE
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"2/3 wire Control    "	,	//	176	02-00	2/3 wire control                
	"Multi-Fun Input1    "	,	//	177	02-01	Multi-Function Input 1          
	"Multi-Fun Input2    "	,	//	178	02-02	Multi-Function Input 2          
	"Multi-Fun Input3    "	,	//	179	02-03	Multi-Function Input 3          
	"Multi-Fun Input4    "	,	//	180	02-04	Multi-Function Input 4          
	"Multi-Fun Input5    "	,	//	181	02-05	Multi-Function Input 5          
	"Multi-Fun Input6    "	,	//	182	02-06	Multi-Function Input 6          
	"Multi-Fun Input7    "	,	//	183	02-07	Multi-Function Input 7          
	"Multi-Fun Input8    "	,	//	184	02-08	Multi-Function Input 8		    
	"D-In Response T sec "	,	//	185	02-09	Digital in response time		
	"Multi-Input ACT     "	,	//	186	02-10	Multi-Function Input Inverse	
	"Multi-Fun RLY1      "	,	//	187	02-11	Multi-Function Relay 1		    
	"Multi-Fun RLY2      "	,	//	188	02-12	Multi-Function Relay 2		    
	"Multi-Fun RLY3      "	,	//	189	02-13	Multi-Function Output 1		    
	"Multi-Fun RLY4      "	,	//	190	02-14	Multi-Function Output 2		    
	"Multi-Fun Out 1     "	,	//	191	02-15	Multi-Function Output 1		    
	"Multi-Fun Out 2     "	,	//	192	02-16	Multi-Function Output 2		    
	"Multi-Fun Out 3     "	,	//	193	02-17	Multi-Function Output 1		    
	"Multi-Fun Out 4     "	,	//	194	02-18	Multi-Function Output 2		    
	"Multi-Fun Out 5     "	,	//	195	02-19	Multi-Function Output 1		    
	"Multi-Fun Out 6     "	,	//	196	02-20	Multi-Function Output 2		    
	"Multi-Fun Out 7     "	,	//	197	02-21	Multi-Function Output 1		    
	"Multi-Fun Out 8     "	,	//	198	02-22	Multi-Function Output 2		    
	"Multi-Output ACT    "	,	//	199	02-23	Multi-Function Output inverse	
    "Seq. Start Mode     "  ,   //  200 02-24   Sequence start mode
	"DESIRE-FREQ1    Hz  "	,	//	201	02-25	Desired Frequency 1		        
	"DESIRE-FREQ1 BNDHz  "	,	//	202	02-26	Band of Desired Frequency 1		
	"DESIRE-FREQ2    Hz  "	,	//	203	02-27	Desired Frequency 2		        
	"DESIRE-FREQ2 BNDHz  "	,	//	204	02-28	Band of Desired Frequency 2		
	"Brake RUN Delay sec "	,	//	205	02-29	Brake Delay Timer at run
	"Brake STOP Delaysec "	,	//	206	02-30	Brake Delay Timer at stop
	"MCDELAY_RUN Timesec "	,	//	207	02-31	Mech Contact Delay Timer run
	"MCDELAY_STP Timesec "	,	//	208	02-32	Mech Contact Delay Timer stop				            
	"Current Detect  %   "	,	//	209	02-33	Isum Current Output Detect	    
	"Speed Area Set  Hz  "	,	//	210	02-34	Speed Area
	"Brake CHK Time  sec "	,	//	211	02-35	Mechanical Brake Checking Time
	"MC CHK Time     sec "	,	//	212 02-36   Magnetic Contactor Checking Time
	"Torque Prove En     "  ,   //  213 02-37   Mechanical Brake Checking Current Enable
	"SCDELAY RUN Timesec "  ,   //  214 02-38   Star Contactor delay time when driver run    //[Star contactor function, Bernie, 2017/03/22]
	"SCDELAY STP Timesec "  ,   //  2XX 02-39   Star Contactor delay time when driver stop   //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD Fault SEL     "  ,   //  2XX 02-40   LU/LD error  Selection	                     //#15977, LULD detect, James, 2021/04/01
	"LU/LD Open Det. sec "  ,   //  2XX 02-41   LD/LD Open Detect Time                       //#15977, LULD detect, James, 2021/04/01
	"LU/LD Short Det.sec "  ,   //  2XX 02-42   LD/LD Short Detect Time                      //#15977, LULD detect, James, 2021/04/01
	"SPEED-REACH BND Hz  "	,   //  2XX 02-43   Band of Speed Agree Function                 //#18572
    "STO Short Det   sec "  ,   //  2XX 02-44   STO shor detect time                         //#18196  STO new function for SIL2, James, 2021/10/06    
    "819 Sensor          "  ,   //  2XX 02-45   819 Sensor                                   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Speed Limit     m/s "  ,   //  2XX 02-46   Speed Limit                                  //[Artemis Add Sensor819 Function/Special/2022/06/06]

/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"AUI1 Selection      "	,	//	214	03-00   AUI1 selection                  //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	215	03-01   ACI  selection                  //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Selection      "	,	//	216	03-02   AUI2 selection                  //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Input Bias %   "	,	//	217	03-03   AUI1 input Bias                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	218	03-04   ACI  input Bias                 //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Input Bias %   "	,	//	219	03-05   AUI2 input Bias                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Bias Mode      "	,	//	220 03-06   AUI1 input Polarity             //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	221 03-07   ACI  input Polarity             //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Bias Mode      "	,	//	222 03-08   AUI2 input Polarity             //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Input Gain %   "	,	//	223 03-09   AUI1 input Gain                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	224 03-10   ACI  input Gain                 //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Input Gain %   "	,	//	225 03-11   AUI2 input Gain                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Input LPF  sec "	,	//	226 03-12   Low pass filter of AUI1 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	227 03-13   Low pass filter of ACI  input   //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Input LPF  sec "	,	//	228 03-14   Low pass filter of AUI2 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"Load Cell Tune      "	,	//	229 03-15   Loss of ACI                     //[ACI function remove, Bernie, 01/20/2012]
    "RESERVED            "  ,   //  230 03-16
	"AO1 Setting         "	,	//	231 03-17   Analong Output 1
	"AO1 Gain        %   "	,	//	232 03-18   Analong Output 1 Gain
	"AO1 In Minus        "	,	//	233 03-19   AO1 in minus value
	"AO2 Setting         "	,	//	234 03-20   Analong Output 2
	"AO2 Gain        %   "	,	//	235 03-21   Analong Output 2 Gain
	"AO2 In Minus        "	,	//	236 03-22   AO2 in minus value
	"AUI1 Input Polar    "	,	//	237 03-23   AUI1 Input Polar                //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI2 Input Polar    "	,	//	238 03-24   AUI2 Input Polar                //[AI chenge to AUI, Lyabryan, 03/27/2015]
	//"AUI1 In Setting     "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2 In Setting     "	,	//	238  03-26    AUI2 Communciate
	
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "Multi-Speed 0   Hz  "  ,   //  239 04-00   Multi-Speed 0
    "Multi-Speed 1   Hz  "  ,   //  240 04-01   Multi-Speed 1
    "Multi-Speed 2   Hz  "  ,   //  241 04-02   Multi-Speed 2
    "Multi-Speed 3   Hz  "  ,   //  242 04-03   Multi-Speed 3
    "Multi-Speed 4   Hz  "  ,   //  243 04-04   Multi-Speed 4
    "Multi-Speed 5   Hz  "  ,   //  244 04-05   Multi-Speed 5
    "Multi-Speed 6   Hz  "  ,   //  245 04-06   Multi-Speed 6
    "Multi-Speed 7   Hz  "  ,   //  246 04-07   Multi-Speed 7
    "Multi-Speed 8   Hz  "  ,   //  247 04-08   Multi-Speed 8
    "Multi-Speed 9   Hz  "  ,   //  248 04-09   Multi-Speed 9
    "Multi-Speed 10  Hz  "  ,   //  249 04-10   Multi-Speed 10
    "Multi-Speed 11  Hz  "  ,   //  250 04-11   Multi-Speed 11
    "Multi-Speed 12  Hz  "  ,   //  251 04-12   Multi-Speed 12
    "Multi-Speed 13  Hz  "  ,   //  252 04-13   Multi-Speed 13
    "Multi-Speed 14  Hz  "  ,   //  253 04-14   Multi-Speed 14
    "Multi-Speed 15  Hz  "  ,   //  254 04-15   Multi-Speed 15
    "Rescue Speed    m/s "  ,   //  2xx 04-16
    "Level Speed     m/s "  ,   //  2xx 04-17
    "Back Home Spd   m/s "  ,   //  2xx 04-18
	
    "Rope Slip Comp. mm  "  ,   //  2xx 04-19   GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //  2xx 04-20
    "TABST2 Status       "  ,   //  2xx 04-21
	
    "Max Floor           "  ,   //  2xx 04-22
    "Current Floor       "  ,   //  2xx 04-23
    "PG Revise PCT   %   "  ,   //  2xx 04-24
    "Sensor Delay Cmpsec "  ,   //  2xx 04-25
    "DLC Delay Time  ms  "  ,   //  2xx 04-26
    "Plank Length    mm  "  ,   //  2xx 04-27 
    "Current Pos. H  m   "  ,   //  2xx 04-28
    "Current Pos. L  mm  "  ,   //  2xx 04-29
    "Current PG H        "  ,   //  2xx 04-30 
    "Current PG L        "  ,   //  2xx 04-31
    "Plank PG H          "  ,   //  2xx 04-32
    "Plank PG L          "  ,   //  2xx 04-33
    "Sensor PG H         "  ,   //  2xx 04-34
    "Sensor PG L         "  ,   //  2xx 04-35    
    "DLC Function        "  ,   //  2xx 04-36
    "PDO TYPE            "  ,   //  2xx 04-37
    "Dec SW Tol. Gap mm  "  ,   //  2xx 04-38
    "% of Max Spd    %   "  ,   //  2xx 04-39   //[ADCO EPS Modify]
    "Spring Extend   mm  "  ,   //  2xx 04-40   //#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //  2xx 04-41
    "EST Count           "  ,   //  2xx 04-42
    "TABST0 Count        "  ,   //  2xx 04-43
    "TABST1 Count        "  ,   //  2xx 04-44
    "DDS1/UDS1Spd Limm/s "  ,   //  2XX 04-45   DD1_Vlim  //Artemis speed limit, James, 20200220                          
    "DDS2/UDS2Spd Limm/s "  ,   //  2XX 04-46   DD2_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS3/UDS3Spd Limm/s "  ,   //  2XX 04-47   DD3_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS4/UDS4Spd Limm/s "  ,   //  2XX 04-48   DD4_Vlim  //Artemis speed limit, James, 20200220
    "DLC user page       "  ,   //  2XX 04-49   user page cahnge
    
    "1F Position H   m   "  ,   //  2XX 04-30   1Floor Position H                                       
    "1F Position L   mm  "  ,   //  2XX 04-31   1Floor Position L                                       
    "2F Position H   m   "  ,   //  2XX 04-32   2Floor Position H                                       
    "2F Position L   mm  "  ,   //  2XX 04-33   2Floor Position L                                       
    "3F Position H   m   "  ,   //  2XX 04-34   3Floor Position H                                       
    "3F Position L   mm  "  ,   //  2XX 04-35   3Floor Position L                                       
    "4F Position H   m   "  ,   //  2XX 04-36   4Floor Position H                                       
    "4F Position L   mm  "  ,   //  2XX 04-37   4Floor Position L                                       
    "5F Position H   m   "  ,   //  2XX 04-38   5Floor Position H                                       
    "5F Position L   mm  "  ,   //  2XX 04-39   5Floor Position L                                       
    "6F Position H   m   "  ,   //  2XX 04-40   6Floor Position H                                       
    "6F Position L   mm  "  ,   //  2XX 04-41   6Floor Position L                                       
    "7F Position H   m   "  ,   //  2XX 04-42   7Floor Position H                                       
    "7F Position L   mm  "  ,   //  2XX 04-43   7Floor Position L                                       
    "8F Position H   m   "  ,   //  2XX 04-44   8Floor Position H                                       
    "8F Position L   mm  "  ,   //  2XX 04-45   8Floor Position L                                       
    "9F Position H   m   "  ,   //  2XX 04-46   9Floor Position H                                       
    "9F Position L   mm  "  ,   //  2XX 04-47   9Floor Position L                                       
    "10F Position H  m   "  ,   //  2XX 04-48   10Floor Position H                                      
    "10F Position L  mm  "  ,   //  2XX 04-49   10Floor Position L                                      
    "11F Position H  m   "  ,   //  2XX 04-50   11Floor Position H                                      
    "11F Position L  mm  "  ,   //  2XX 04-51   11Floor Position L                                      
    "12F Position H  m   "  ,   //  2XX 04-52   12Floor Position H                                      
    "12F Position L  mm  "  ,   //  2XX 04-53   12Floor Position L                                      
    "13F Position H  m   "  ,   //  2XX 04-54   13Floor Position H                                      
    "13F Position L  mm  "  ,   //  2XX 04-55   13Floor Position L                                      
    "14F Position H  m   "  ,   //  2XX 04-56   14Floor Position H                                      
    "14F Position L  mm  "  ,   //  2XX 04-57   14Floor Position L                                      
    "15F Position H  m   "  ,   //  2XX 04-58   15Floor Position H                                      
    "15F Position L  mm  "  ,   //  2XX 04-59   15Floor Position L                                      
    "16F Position H  m   "  ,   //  2XX 04-60   16Floor Position H                                      
    "16F Position L  mm  "  ,   //  2XX 04-61   16Floor Position L                                      
    "17F Position H  m   "  ,   //  2XX 04-62   17Floor Position H                                      
    "17F Position L  mm  "  ,   //  2XX 04-63   17Floor Position L                                      
    "18F Position H  m   "  ,   //  2XX 04-64   18Floor Position H                                      
    "18F Position L  mm  "  ,   //  2XX 04-65   18Floor Position L                                      
    "19F Position H  m   "  ,   //  2XX 04-66   19Floor Position H                                      
    "19F Position L  mm  "  ,   //  2XX 04-67   19Floor Position L                                      
    "20F Position H  m   "  ,   //  2XX 04-68   20Floor Position H                                      
    "20F Position L  mm  "  ,   //  2XX 04-69   20Floor Position L                                      
    "21F Position H  m   "  ,   //  2XX 04-70   21Floor Position H                                      
    "21F Position L  mm  "  ,   //  2XX 04-71   21Floor Position L                                      
    "22F Position H  m   "  ,   //  2XX 04-72   22Floor Position H                                      
    "22F Position L  mm  "  ,   //  2XX 04-73   22Floor Position L                                      
    "23F Position H  m   "  ,   //  2XX 04-74   23Floor Position H                                      
    "23F Position L  mm  "  ,   //  2XX 04-75   23Floor Position L                                      
    "24F Position H  m   "  ,   //  2XX 04-76   24Floor Position H                                      
    "24F Position L  mm  "  ,   //  2XX 04-77   24Floor Position L                                      
    "25F Position H  m   "  ,   //  2XX 04-78   25Floor Position H                                      
    "25F Position L  mm  "  ,   //  2XX 04-79   25Floor Position L                                     
   
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
	"IM Auto-Tuning      "	,	//	255 05-00	Motor Auto-Tuning
	"IM Motor Rated AAmps"	,	//	256 05-01	Motor 1 rated Current           
	"IM Motor Rated PKw  "	,	//	257 05-02	Motor 1 Rated Power             
	"IM Motor Rated  RPM "	,	//	258 05-03	Motor 1 Rated RPM               
	"IM Motor Poles      "	,	//	259 05-04	Motor 1 pole No.                
	"IM Motor No-LoadAmps"	,	//	260 05-05	Motor 1 No-Load Current         
	"IM Motor Rs     ohm "	,	//	261 05-06	Motor 1 Rs                      
	"IM Motor Rr     ohm "	,	//	262 05-07	Motor 1 Rr                      
	"IM Motor Lm      mH "	,	//	263 05-08	Motor 1 Lm                      
	"IM Motor Lx      mH "	,	//	264 05-09	Motor 1 Lx                      
	"SVC Volt. LPF   sec "	,	//	265 05-10	Vector Voltage Filter	        
	"SVC Slip LPF    sec "	,	//	266 05-11	Vector Slip Filter	            
	"TQR Comp Gain       "	,	//	267 05-12	Torque Compensation Gain	    
	"Slip Comp Gain      "	,	//	268 05-13	Slip Compensation Gain	        
	"Slip Deviation L%   "	,	//	269 05-14	Slip Deviation level	        
	"Slip Deviation Tsec "	,	//	270 05-15	Slip Deviation Detect Time	    
	"Over Slip Way       "	,	//	271 05-16	Over Slip treatment	            
	"HUNTING COEFF       "	,	//	272 05-17	Coeff for hunting disable	    
	"Cumulative Run  Mins"	,	//	273 05-18	Accumulative Motor Operation Min
	"Cumulative Run  Days"	,	//	274 05-19	Accumulative Motor Operation Day
	"Core Loss       %   "	,	//	275 05-20	Coreloss % of output Power	    
	"Power On Min    Mins"	,	//	276 05-21	Power On Min
	"Power On Day    Days"	,	//	277 05-22	Power On Day
    "GEN Slip Gain   %   "	,   //  2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"Motor Slip Gain %   "	,	//	2XX 05-24   RESERVE
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
	"Low Voltage     V   "	,	//	278 06-00	Low voltage level
	"Phase loss          "	,	//	279 06-01	Phase loss
	"OCA Level       %   "	,	//	280 06-02	OC stall during Accel
	"OCN Level       %   "	,	//	281 06-03	OC stall during Decel
	"Stall AccDec SEL    "	,	//	282 06-04	Stall preventation Accel/Decel time selection
	"OL2 selection       "	,	//	283 06-05	Over-Torque 1 Selection
	"OverTorque Level%   "	,	//	284 06-06	Over-Torque 1 level
	"Over-Torque Timesec "	,	//	285 06-07	Over-Torque 1 Time
	"OL3 selection       "	,	//	286 06-08	Over-Torque 2 Selection	                     
	"OverLoad 3 Level%   "	,	//	287 06-09	Over-Torque 2 level	                         
	"OverLoad 3 Time sec "	,	//	288 06-10	Over-Torque 2 Time	                         
	"TQR LIMIT       %   "	,	//	289 06-11	Current Limit
	"Thermal RLY1 SEL    "	,	//	290 06-12	Thermal Relay 1 Selection
	"Thermal RLY1 T  sec "	,	//	291 06-13	Thermal Relay 1 Time
	"OH Warning Level C  "	,	//	292 06-14	OH Warning Level
	"Stall Level Limt%   "	,	//	293 06-15	Stall preventation Limit Level
	"1st Fault Record    "	,	//	294 06-16	1st Fault Record
	"2nd Fault Record    "	,	//	295 06-17	2nd Fault Record
	"3rd Fault Record    "	,	//	296 06-18	3rd Fault Record
	"4th Fault Record    "	,	//	297 06-19	4th Fault Record
	"5th Fault Record    "	,	//	298 06-20	5th Fault Record
	"6th Fault Record    "	,	//	299 06-21	6th Fault Record
	"Fault Option 1      "	,	//	300 06-22	Fault Option 1
	"Fault Option 2      "	,	//	301 06-23	Fault Option 2
	"Fault Option 3      "	,	//	302 06-24	Fault Option 3
	"Fault Option 4      "	,	//	303 06-25	Fault Option 4
	"PTC Treatments      "	,	//	304 06-26	PTC over Treatments	                         
	"PTC Level       %   "	,	//	305 06-27	PTC Level
	"PTC Detect FT   sec "	,	//	306 06-28	PTC Detect Filter time
	"EPS Voltage     V   "	,	//	307 06-29	EPS voltage level
	"Fault Option MOD    "	,	//	308 06-30	Fault Option Mode
	"Output Detection    "	,	//	309 06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
	"1st Fault Time  Mins"	,	//	310 06-32	1st Fault Time(MIN)
	"1st Fault Time  Days"	,	//	311 06-33	1st Fault Time(DAY)
	"2nd Fault Time  Mins"	,	//	312 06-34	2nd Fault Time(MIN)
	"2nd Fault Time  Days"	,	//	313 06-35	2nd Fault Time(DAY)
	"3rd Fault Time  Mins"	,	//	314 06-36	3rd Fault Time(MIN)
	"3rd Fault Time  Days"	,	//	315 06-37	3rd Fault Time(DAY)
	"4th Fault Time  Mins"	,	//	316 06-38	4th Fault Time(MIN)
	"4th Fault Time  Days"	,	//	317 06-39	4th Fault Time(DAY)
	"5th Fault Time  Mins"	,	//	318 06-40	5th Fault Time(MIN)
	"5th Fault Time  Days"	,	//	319 06-41	5th Fault Time(DAY)
	"6th Fault Time  Mins"	,	//	320 06-42	6th Fault Time(MIN)
	"6th Fault Time  Days"	,	//	321 06-43	6th Fault Time(DAY)
    "EPS Speed       Hz  "  ,   //  322 06-44	EPS Frequency
    "ERR Option MOD  BIN "  ,	//  323 06-45   LV Option Mode
    "EPS Option MOD      "  ,	//  324 06-46   EPS Option Mode
    "GEN SCAN TIME   sec "  ,   //  325 06-47   Generation Operation Detected Time
    "UPS CAPACITY    KVA "  ,   //  326 06-48   UPS Capacity (0.1KVA)
    "STO Func. select    "  ,   //  327 06-49   STO Lock selection     //[Safty function, Bernie] 
    "Restart Select      "	,   //  328 06-50   Base Block Speed Search (oc,ov,occ.......)  //[Add auto restart after fault, Bernie, 06/06/12]
    "Auto Restart T  sec "  ,   //  329 06-51   Auto restart times after fault     
    "Restart Intervalsec "  ,   //  330 06-52   Auto restart interval
    "Cmd Freq. REC.  Hz  "	,	//	331 06-53   Fkey Record
    "Out Freq. REC.  Hz  "	,	//	332 06-54   Fcmd Record"Out Freq. REC.  Hz  "	,	    //	94 	15-94   Fcmd Record
    "Isum Value REC. Amps"	,	//	333 06-55	Isum Record
    "Motor Freq. REC.Hz  "	,	//	334 06-56	Fout Record
    "Out Voltage REC.V   "	,	//	335 06-57	Vout Record
	"DcBus Value REC.V   "	,   //  336 06-58	Dcbus Record  
	"Out Power REC.  KW  "	,	//	337 06-59   Power Record
	"Out Torque REC. %   "	,	//	338 06-60   Torque Record
	"IGBT Temp. REC.  C  "	,	//	339 06-61	IGBT Temperature Record    
	"DI State REC.   Hex "	,	//	340 06-62   MFI State Record
	"DO State REC.   Hex "	,	//	341 06-63   MFO State Record
	"Drive State REC.Hex "	,	//	342 06-64   Drive State Record
	"UCMP Curnt limit%   "  ,   //  3XX 06-65   Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
	"Service times       "  ,   //  3xx 06-66   Service time count                          //[Service time function, Bernie, 2017/03/14]
	"Service Enable      "  ,   //  3xx 06-67   Service time function Enable                //[Service time function, Bernie, 2017/03/14]
    "EPS Detect PF   deg "  ,   //  3xx 06-68   EPS Detect Current    
    "EPS PF angle    deg "  ,   //  3xx 06-69   EPS Detect Current Ref
    "EPS Direction       "  ,   //  3xx 06-70   EPS Detect direction
    "EPS MO On delay sec "  ,   //  3xx 06-71   EPS MO Off Time
    "EPS MO Off delaysec "  ,   //  3xx 06-72   EPS MO Off Time
    "Run Dir. Count  H   "	,	//	3xx 06-73   Running direction count high						
    "Run Dir. Count  L   "	,	//	3xx 06-74   Running direction count low
    "Run Dir. Temp   H   "	,	//	3xx 06-75   Temp running direction count high
    "Run Dir. Temp   L   "	,	//  3xx 06-76   Temp running direction count low
    "Temp Count Rst.     "	,	//	3xx 06-77   Temp running reset count
    "Run Limit Level k   "	,	//	3xx 06-78   Running life
    "Run Count Treat     "	,	//	3xx 06-79   Running function
    "Out Freq. REC2  Hz  "  ,   //  3xx 06-80   Fcmd Record1"Out Freq. REC.  Hz  "
    "DcBus Value REC2V   "	,   //  3xx 06-81   Dcbus Record 1
    "Isum Value REC2 Amps"  ,   //  3xx 06-82   Isum Record1
    "IGBT Temp. REC2 C   "  ,   //  3xx 06-83   IGBT Temperature Record1
    "Out Freq. REC3  Hz  "  ,   //  3xx 06-84   Fcmd Record2"Out Freq. REC.  Hz  "
    "DcBus Value REC3V   "	,   //  3xx 06-85   Dcbus Record2
    "Isum Value REC3 Amps"  ,   //  3xx 06-86   Isum Record2
    "IGBT Temp. REC3 C   "  ,   //  3xx 06-87   IGBT Temperature Record2
    "Out Freq. REC4  Hz  "  ,   //  3xx 06-88   Fcmd Record3"Out Freq. REC.  Hz  "
    "DcBus Value REC4V   "	,   //  3xx 06-89   Dcbus Record3
    "Isum Value REC4 Amps"  ,   //  3xx 06-90   Isum Record3
    "IGBT Temp. REC4 C   "  ,   //  3xx 06-91   IGBT Temperature Record3
    "Out Freq. REC5  Hz  "  ,   //  3xx 06-92   Fcmd Record4"Out Freq. REC.  Hz  "
    "DcBus Value REC5V   "	,   //  3xx 06-93   Dcbus Record4
    "Isum Value REC5 Amps"  ,   //  3xx 06-94   Isum Record4
    "IGBT Temp. REC5 C   "  ,   //  3xx 06-95   IGBT Temperature Record4
    "Out Freq. REC6  Hz  "  ,   //  3xx 06-96   Fcmd Record5"Out Freq. REC.  Hz  "
    "DcBus Value REC6V   "	,   //  3xx 06-97   Dcbus Record5
    "Isum Value REC6 Amps"  ,   //  3xx 06-98   Isum Record5
    "IGBT Temp. REC6 C   "  ,   //  3xx 06-99   IGBT Temperature Record5
    
/*---- GROUP 07-----------------------------------------*/ 
/*  "12345678901234561234"	*/
	"SW Braking LevelV   "	,	//	327 07-00	SW Braking Level
    "BK Voltage Hold V   "  ,   //	328 07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
	"Start DCI Level %   "	,	//	329 07-02	DCI Current Level                       //[DCI Level when stop, Bernie, 05/21/2012]
	"DC Inject Start sec "	,	//	330 07-03	DCI Time at Start 
	"DC Inject Stop  sec "	,	//	331 07-04	DCI Time at STOP
	"DC Inject StartFHz  "	,	//	332 07-05	DCI Freq. At start
	"DC Injection Ki     "	,	//	333 07-06	DCI KI
	"GEAR ACC TIME   sec "	,	//	334 07-07	Gear wait time when acceleration
	"GEAR ACC FREQ   Hz  "	,	//	335 07-08	Gear wait frequency when acceleration
	"GEAR DEC TIME   sec "	,	//	336 07-09	Gear wait time when deceleration
	"GEAR DEC FREQ   Hz  "	,	//	337 07-10	Gear wait frequency when deceleration
	"Cooling Fan         "	,	//	338 07-11	Fan Control
	"Torque Ref.     %   "	,	//	339 07-12	TQC Reference from RS485
	"SOURCE OF TQR       "	,	//	340 07-13	Source of Torque Command
	"TQR MAX. LEVEL  %   "	,	//	341 07-14	Torque max. level
	"TQR COM Filter  sec "	,	//	342 07-15	Torque command filter
	"Speed Limit Sel.    "	,	//	343 07-16	Speed Limit selection
	"TQR +SPD LIMIT  %   "	,	//	344 07-17	Torque mode positive speed limit
	"TQR -SPD LIMIT  %   "	,	//	345 07-18	Torque mode negative speed limit
	"TQR OFFSET SEL      "	,	//	346 07-19	Torque offset selection
	"TQR OFFSET LEVEL%   "	,	//	347 07-20	Torque offset setting level
	"TQR OFFSET HIGH %   "	,	//	348 07-21	Torque offset setting level High
	"TQR OFFSET MID. %   "	,	//	349 07-22	Torque offset setting level Middle
	"TQR OFFSET LOW  %   "	,	//	350 07-23	Torque offset setting level Low
	"FWD Motor Tq LIM%   "	,	//	351 07-24	FWD Motoring Tq Limit
	"FWD Reg. Tq LIM %   "	,	//	352 07-25	FWD Regeneration Tq Limit
	"REV Motor Tq LIM%   "	,	//	353 07-26	REV Motoring Tq Limit
	"REV Reg. Tq LIM %   "	,	//	354 07-27	REV Regeneration Tq Limit
	"FORCE STOP WAY      "	,	//	355 07-28	Emergency Stop & Forced Stop selection
	"Torque DEC. Timesec "	,	//	356 07-29   Torque Decrease Time
	"STOP DCI Level  %   "	,	//	356 07-30   STOP DC Inject Level                    //[DCI Level when stop, Bernie, 05/21/2012]
	"BTT100             %"  ,   //  357 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect         "  ,   //  358 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Distance    ppr"  ,   //  359 07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect Time sec"  ,   //  360 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Fail Torq      "  ,   //  361 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Min Torq       "  ,   //  362 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Max Torq       "  ,   //  362 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"PM Auto-Tuning      "	,	//	357 08-00	PMotor Auto-Tuning  
	"PM Motor Rated AAmps"	,	//	358 08-01	PMotor rated Current
	"PM Motor Rated PKw  "	,	//	359 08-02	PMotor Rated Power  
	"PM Motor Rated  RPM "	,	//	360 08-03	PMotor Rated RPM    
	"PM Motor Poles      "	,	//	361 08-04	PMotor pole No.     
	"PM Motor Rs     ohm "	,	//	362 08-05	PMotor Rs           
	"REVERSE             "	,	//	363 08-06	PMotor Ld           
	"PM Motor Lq     mH  "	,	//	364 08-07	PMotor Lq           
	"Back EMF        Vrms"	,	//	365 08-08	PMotor Bemf coff	
	"Z-Offset Angle  deg "	,	//	366 08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
	"Position Align      "	,	//	367 08-10	//ADDED BY DIN

/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "VFD Comm Address    "	,	//	368 09-00   Comm Address                              
    "COM Baud Rate   kbps"	,	//	369 09-01   Tranmission speed                         
    "COM Fault Treatment "	,	//	370 09-02   Comm fault Treatment                      
    "COM Time Out    sec "	,	//	371 09-03   Comm Time out                             
    "COM Protocol        "	,	//	372 09-04   Comm Protocol                             
    "Response Delay Tms  "	,	//	373 09-05   ASC remote Response Delay Time, 1=100us   
    "CAN_BUARD           "	,   //  3XX 09-06   CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "PDO_Tx_Time     ms  "	,   //  3XX 09-07   CAN PDO Handshaking Period  
    "CAN_Check_Time  ms  "	,   //  3XX 09-08   CAN Communiction Timeout
    "Elevator ID Code    "  ,   //  3XX 09-09   Elevator Control Identification Code
    "FHM Register        "  ,   //  3XX 09-10
    "DLC Register 1      "  ,   //  3XX 09-11
    "DLC Register 2      "  ,   //  3XX 09-12
    "DLC Register 3      "  ,   //  3XX 09-13     
    "PDO TXTIME      ms  "  ,   //  3XX 09-14   CAN fail rate---aevin 6/12/2017

/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"Encoder Types       "	,	//	374 10-00	Encoder TYPE                             
	"Encoder pulses  ppr "	,	//	375 10-01	Encoder pulses	                    
	"PG input setting    "	,	//	376 10-02	PG input setting	                
	"PG Err Treat        "	,	//	377 10-03	PG fbk fault treatment	            
	"PG Err Det. Timesec "	,	//	378 10-04	PG fbk Error Detection Time	        
	"PG FBK DET Level%   "	,	//	379 10-05	PG fbk overspeed detection level	
	"OverSPD Det.Timesec "	,	//	380 10-06	Over speed Detection Time	        
	"PG FBK DEV Level%   "	,	//	381 10-07	PG fbk speed deviation level	    
	"DEV Detect Time sec "	,	//	382 10-08	Deviation Detect Time	            
	"Over SPD Way        "	,	//	383 10-09	Operation at overspeed	            
	"Hall Input Types    "  ,   //  384 10-10   Hall Input Types
	"Zero SPD Loop Kp%   "	,	//	385 10-11	KP gain of ASR in Zero speed	
	"Zero SPD Loop Kisec "	,	//	386 10-12	Ki gain of ASR in Zero speed	
	"Low SPD Loop Kp %   "	,	//	387 10-13	ASR P Gain 1	                
	"Low SPD Loop Ki sec "	,	//	388 10-14	ASR I Gain 1	                
	"High SPD Loop Kp%   "	,	//	389 10-15	ASR P Gain 2	                
	"High SPD Loop Kisec "	,	//	390 10-16	ASR I Gain 2	                
	"ASR1/2 Switch F Hz  "	,	//	391 10-17	ASR1/ASR2 switch freq	        
	"Primary LPG     sec "	,	//	392 10-18	Primary LowPass filter Gain 
	"Position Loop Kp%   "  ,	//	393 10-19   position control Kp Gain  
    "Low SPD Slope   Hz  "  ,   //  394 10-20   Low Spd band
    "High SPD Slope  Hz  "  ,   //  395 10-21   High Spd band
	"POS CONT Time   sec "	,	//	396 10-22   Position control time
	"POS CONT LPG    sec "	,	//	397 10-23   Position control LOW POSS FILTER
	"Source of POS       "	,	//	398 10-24   Source of position control, add by dino, 06/30/2008
	"Zero SPD Land Kp%   "	,	//	399 10-25	KP gain of ASR in Zero speed of Landing
	"Zero SPD Land Kisec "	,	//	400 10-26	Ki gain of ASR in Zero speed of Landing
	"Position SPD Kp %   "	,	//	401 10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"Position SPD Ki sec "	,	//	402 10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"PG Card Freq Div    "	,   //  403 10-29   PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
	"PG Card Mode        "	,   //  404 10-30   PG Card Mode setting                //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C- TYPE       "  ,   //  405 10-31   RESERVE                             //[change parameter to normal group, Bernie, 2014/02/14]
    "Over Acc Level  m/s2"  ,   //  406 10-32   Over acc level setting              //[Over Acceleration protection function, Bernie, 2017/02/13]
    "OverAcc Det.Timesec "  ,   //  407 10-33   Over acc detect time                //[Over Acceleration protection function, Bernie, 2017/02/13]
    "Over Acc setting    "  ,   //  408 10-34   Over acc detect rule setting        //[Over Acceleration protection function, Bernie, 2017/02/13]

/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"System Control  Hex "	,	//	401 11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "Fmax to Lift Spdm/s "  ,   //  402 11-01   Lift operation speed                                        
    "Sheave Diameter mm  "  ,   //  403 11-02   SHEAVE diameter			ADDED BY SCOTTY                     
    "Gear Ratio          "  ,   //  404 11-03   Gear Ratio                                              
    "Suspension Ratio    "  ,   //  405 11-04   Suspension ratio	                                        
    "Inertia Ratio   %   "  ,   //  406 11-05   inertia	percent			ADDED BY SCOTTY                     
	"Zero SP Loop BW Hz  "	,	//	407 11-06	Zero Speed Loop BandWidth	                                
	"Low SP Loop BW  Hz  "	,	//	408 11-07	Speed Loop BandWidth1		                                
	"High SP Loop BW Hz  "	,	//	409 11-08	Speed Loop BandWidth2		                                
	"SPD Loop Kr     %   "	,	//	410 11-09	PDFFKr		                                                
	"SPD FFD GAIN    %   "	,	//	411 11-10	SPEED FFD GAIN			ADDED BY SCOTTY                     
	"Netch Deep      db  "	,	//	412 11-11	Netch filter deep(db)	                                    
	"Netch Freq.     Hz  "	,	//	413 11-12	Netch filter frequency	                                    
	"LPF for display sec "	,	//	414 11-13	Low Pass Filter for display	                                
	"Max. ACC Current%   "	,	//	415 11-14	ACC Max current                                             
    "Max Meter per S m/s "  ,	//	416 11-15	max meter/sec	                                            
    "Disp address    Hex "  ,   //	417 11-16	Display address,add by dino 2007/03/08                      
    "Disp data           "  ,	//	418 11-17	Display data,   add by dino 2007/03/08                      
    "Protect Bit         "  ,   //  419 11-18   Protect Bit	                                                
	"Zero SP Land BW Hz  "	,	//	420 11-19	Zero Speed Loop BandWidth of Landing
	"PWM Mode            "	,	//	4XX 11-20	PWM MODE, 0=SVPWM+DPWM,1=SVPWM    PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LPF for LC01    sec "	,	//	422 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	420 11-21   Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]


/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_ADD0           "  ,   //  421 12-00
    "UMAP_ADD1           "  ,   //  422 12-01
    "UMAP_ADD2           "  ,   //  423 12-02
    "UMAP_ADD3           "  ,   //  424 12-03
    "UMAP_ADD4           "  ,   //  425 12-04
    "UMAP_ADD5           "  ,   //  426 12-05
    "UMAP_ADD6           "  ,   //  427 12-06
    "UMAP_ADD7           "  ,   //  428 12-07
    "UMAP_ADD8           "  ,   //  429 12-08
    "UMAP_ADD9           "  ,   //  430 12-09
    "UMAP_ADD10          "  ,   //  431 12-10
    "UMAP_ADD11          "  ,   //  432 12-11
    "UMAP_ADD12          "  ,   //  433 12-12
    "UMAP_ADD13          "  ,   //  434 12-13
    "UMAP_ADD14          "  ,   //  435 12-14
    "UMAP_ADD15          "  ,   //  436 12-15
    "UMAP_ADD16          "  ,   //  437 12-16
    "UMAP_ADD17          "  ,   //  438 12-17
    "UMAP_ADD18          "  ,   //  439 12-18
    "UMAP_ADD19          "  ,   //  440 12-19 
    "UMAP_ADD20          "  ,   //  441 12-20
    "UMAP_ADD21          "  ,   //  442 12-21
    "UMAP_ADD22          "  ,   //  443 12-22
    "UMAP_ADD23          "  ,   //  444 12-23
    "UMAP_ADD24          "  ,   //  445 12-24
    "UMAP_ADD25          "  ,   //  446 12-25
    "UMAP_ADD26          "  ,   //  447 12-26
    "UMAP_ADD27          "  ,   //  448 12-27
    "UMAP_ADD28          "  ,   //  449 12-28
    "UMAP_ADD29          "  ,   //  450 12-29
    "UMAP_ADD30          "  ,   //  451 12-30
    "UMAP_ADD31          "  ,   //  452 12-31
    "UMAP_ADD32          "  ,   //  4xx 12-32
    "UMAP_ADD33          "  ,   //  4xx 12-33
    "UMAP_ADD34          "  ,   //  4xx 12-34
    "UMAP_ADD35          "  ,   //  4xx 12-35
    "UMAP_ADD36          "  ,   //  4xx 12-36
    "UMAP_ADD37          "  ,   //  4xx 12-37
    "UMAP_ADD38          "  ,   //  4xx 12-38
    "UMAP_ADD39          "  ,   //  4xx 12-39
    "UMAP_ADD40          "  ,   //  4xx 12-40
    "UMAP_ADD41          "  ,   //  4xx 12-41
    "UMAP_ADD42          "  ,   //  4xx 12-42
    "UMAP_ADD43          "  ,   //  4xx 12-43
    "UMAP_ADD44          "  ,   //  4xx 12-44
    "UMAP_ADD45          "  ,   //  4xx 12-45
    "UMAP_ADD46          "  ,   //  4xx 12-46
    "UMAP_ADD47          "  ,   //  4xx 12-47
    "UMAP_ADD48          "  ,   //  4xx 12-48
    "UMAP_ADD49          "  ,   //  4xx 12-49
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    
/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_DATA0          "  ,   //  453 13-00
    "UMAP_DATA1          "  ,   //  454 13-01
    "UMAP_DATA2          "  ,   //  455 13-02
    "UMAP_DATA3          "  ,   //  456 13-33
    "UMAP_DATA4          "  ,   //  457 13-04
    "UMAP_DATA5          "  ,   //  458 13-05
    "UMAP_DATA6          "  ,   //  459 13-06
    "UMAP_DATA7          "  ,   //  460 13-07
    "UMAP_DATA8          "  ,   //  461 13-08
    "UMAP_DATA9          "  ,   //  462 13-09
    "UMAP_DATA10         "  ,   //  463 13-10
    "UMAP_DATA11         "  ,   //  464 13-11
    "UMAP_DATA12         "  ,   //  465 13-12
    "UMAP_DATA13         "  ,   //  466 13-13
    "UMAP_DATA14         "  ,   //  467 13-14
    "UMAP_DATA15         "  ,   //  468 13-15
    "UMAP_DATA16         "  ,   //  469 13-16
    "UMAP_DATA17         "  ,   //  470 13-17
    "UMAP_DATA18         "  ,   //  471 13-18
    "UMAP_DATA19         "  ,   //  472 13-19
    "UMAP_DATA20         "  ,   //  473 13-20
    "UMAP_DATA21         "  ,   //  474 13-21
    "UMAP_DATA22         "  ,   //  475 13-22
    "UMAP_DATA23         "  ,   //  476 13-23
    "UMAP_DATA24         "  ,   //  477 13-24
    "UMAP_DATA25         "  ,   //  478 13-25
    "UMAP_DATA26         "  ,   //  479 13-26
    "UMAP_DATA27         "  ,   //  480 13-27
    "UMAP_DATA28         "  ,   //  481 13-28
    "UMAP_DATA29         "  ,   //  482 13-29
    "UMAP_DATA30         "  ,   //  483 13-30
    "UMAP_DATA31         "  ,   //  484 13-31
    "UMAP_DATA32         "  ,   //  455 13-32
    "UMAP_DATA33         "  ,   //  456 13-33
    "UMAP_DATA34         "  ,   //  457 13-34
    "UMAP_DATA35         "  ,   //  458 13-35
    "UMAP_DATA36         "  ,   //  459 13-36
    "UMAP_DATA37         "  ,   //  460 13-37
    "UMAP_DATA38         "  ,   //  461 13-38
    "UMAP_DATA39         "  ,   //  462 13-39
    "UMAP_DATA40         "  ,   //  463 13-30
    "UMAP_DATA41         "  ,   //  464 13-41
    "UMAP_DATA42         "  ,   //  465 13-42
    "UMAP_DATA43         "  ,   //  466 13-43
    "UMAP_DATA44         "  ,   //  467 13-44
    "UMAP_DATA45         "  ,   //  468 13-45
    "UMAP_DATA46         "  ,   //  469 13-46
    "UMAP_DATA47         "  ,   //  470 13-47
    "UMAP_DATA48         "  ,   //  471 13-48
    "UMAP_DATA49         "  ,   //  472 13-49
    "UMAP_DATA50         "  ,   //  473 13-50
    "UMAP_DATA51         "  ,   //  474 13-51
    "UMAP_DATA52         "  ,   //  475 13-52
    "UMAP_DATA53         "  ,   //  476 13-53
    "UMAP_DATA54         "  ,   //  477 13-54
    "UMAP_DATA55         "  ,   //  478 13-55
    "UMAP_DATA56         "  ,   //  479 13-56
    "UMAP_DATA57         "  ,   //  480 13-57
    "UMAP_DATA58         "  ,   //  481 13-58
    "UMAP_DATA59         "  ,   //  482 13-59
    "UMAP_DATA60         "  ,   //  483 13-60
    "UMAP_DATA61         "  ,   //  484 13-61
    "UMAP_DATA62         "  ,   //  485 13-62
    "UMAP_DATA63         "  ,   //  4xx 13-63
    "UMAP_DATA64         "  ,   //  4xx 13-64
    "UMAP_DATA65         "  ,   //  4xx 13-65
    "UMAP_DATA66         "  ,   //  4xx 13-66
    "UMAP_DATA67         "  ,   //  4xx 13-67
    "UMAP_DATA68         "  ,   //  4xx 13-68
    "UMAP_DATA69         "  ,   //  4xx 13-69
    "UMAP_DATA70         "  ,   //  4xx 13-70
    "UMAP_DATA71         "  ,   //  4xx 13-71
    "UMAP_DATA72         "  ,   //  4xx 13-72
    "UMAP_DATA73         "  ,   //  4xx 13-73
    "UMAP_DATA74         "  ,   //  4xx 13-74
    "UMAP_DATA75         "  ,   //  4xx 13-75
    "UMAP_DATA76         "  ,   //  4xx 13-76
    "UMAP_DATA77         "  ,   //  4xx 13-77
    "UMAP_DATA78         "  ,   //  4xx 13-78
    "UMAP_DATA79         "  ,   //  4xx 13-79
    "UMAP_DATA80         "  ,   //  4xx 13-80
    "UMAP_DATA81         "  ,   //  4xx 13-81
    "UMAP_DATA82         "  ,   //  4xx 13-82
    "UMAP_DATA83         "  ,   //  4xx 13-83
    "UMAP_DATA84         "  ,   //  4xx 13-84
    "UMAP_DATA85         "  ,   //  4xx 13-85
    "UMAP_DATA86         "  ,   //  4xx 13-86
    "UMAP_DATA87         "  ,   //  4xx 13-87
    "UMAP_DATA88         "  ,   //  4xx 13-88
    "UMAP_DATA89         "  ,   //  4xx 13-89
    "UMAP_DATA90         "  ,   //  4xx 13-90
    "UMAP_DATA91         "  ,   //  4xx 13-91
    "UMAP_DATA92         "  ,   //  4xx 13-92
    "UMAP_DATA93         "  ,   //  4xx 13-93
    "UMAP_DATA94         "  ,   //  4xx 13-94
    "UMAP_DATA95         "  ,   //  4xx 13-95
    "UMAP_DATA96         "  ,   //  4xx 13-96
    "UMAP_DATA97         "  ,   //  4xx 13-97
    "UMAP_DATA98         "  ,   //  4xx 13-98
    "UMAP_DATA99         "  ,   //  4xx 13-99
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level%   "	,	//	485 14-00	Ids Power Save Level
	"VF CURVE MODE       "	,	//	486 14-01	VF voltage mode selection
	"Overload 1 Mode     "	,	//	487 14-02	Constant Torque Selection
	"Auto ACC/DEC        "	,	//	488 14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	489 14-04	Unit of Acc/Dec time
	"POWER SAVE MODE     "	,	//	490 14-05	Power Save mode
	"Stop Methods        "	,	//	491 14-06	Stop Methods
	"Reverse Operate     "	,	//	492 14-07	Reverse Operation
	"Skip Freq. 1UP  Hz  "	,	//	493 14-08	Skip Freq. Point 1 upper limit
	"Skip Freq. 1LOW Hz  "	,	//	494 14-09	Skip Freq. Point 1 lower limit
	"Skip Freq. 2UP  Hz  "	,	//	495 14-10	Skip Freq. Point 2 upper limit
	"Skip Freq. 2LOW Hz  "	,	//	496 14-11	Skip Freq. Point 2 lower limit
	"Skip Freq. 3UP  Hz  "	,	//	497 14-12	Skip Freq. Point 3 upper limit
	"Skip Freq. 3LOW Hz  "	,	//	498 14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz  "	,	//	499 14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//	500 14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//	501 14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//	502 14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//	503 14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//	504 14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2  Hz  "	,	//	505 14-20	Min Output Freq. 2
	"Min Out-Volt 2  V   "	,	//	506 14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//	507 14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//	508 14-23	up/down key speed
	"Counter Set         "	,	//	509 14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//	510 14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//	511 14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"Multi-Fun Input9    "	,	//	512 14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//	513 14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//	514 14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//	515 14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//	516 14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//	517 14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//	518 14-33	External Terminal Run after Fault Reset
	"ACI/AVI2 SEL        "	,	//	519 14-34	ACI change to AVI2
	"Addition of AI      "	,	//	520 14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//	521 14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//	522 14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//	523 14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//	524 14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//	525 14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//	526 14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//	527 14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//	528 14-43	Multi-Position Point 8
	"Multi-Posit 9       "	,	//	529 14-44	Multi-Position Point 9
	"Multi-Posit 10      "	,	//	530 14-45	Multi-Position Point 10
	"Multi-Posit 11      "	,	//	531 14-46	Multi-Position Point 11
	"Multi-Posit 12      "	,	//	532 14-47	Multi-Position Point 12
	"Multi-Posit 13      "	,	//	533 14-48	Multi-Position Point 13
	"Multi-Posit 14      "	,	//	534 14-49	Multi-Position Point 14
	"Multi-Posit 15      "	,	//	535 14-50	Multi-Position Point 15
	"MOTOR 1 OR 2        "	,	//	536 14-51	Motor Selection 1 or 2
	"Y-D Switch Hz   Hz  "	,	//	537 14-52	Y-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//	538 14-53	Y-Delta switched Enable
	"Motor2 Rated    Amps"	,	//	539 14-54	Motor 2 rated Current
	"Motor2 Rated P  Kw  "	,	//	540 14-55	Motor 2 Rated Power
	"Motor2 Rated    RPM "	,	//	541 14-56	Motor 2 Rated RPM
	"Motor2 Poles        "	,	//	542 14-57	Motor 2 pole No.
	"Motor2 No-Load  Amps"	,	//	543 14-58	Motor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	544 14-59	Motor 2 Rs
	"Motor2 Rr       ohm "	,	//	545 14-60	Motor 2 Rr
	"Motor2 Lm       mH  "	,	//	546 14-61	Motor 2 Lm
	"Motor2 Lx       mH  "	,	//	547 14-62	Motor 2 Lx
	"Y-D On Delay T      "	,	//	548 14-63	Y-Delta On delay time
	"OV stall level  V   "	,	//	549 14-64	OV stall level
	"Thermal RLY2 SEL    "	,	//	550 14-65	Thermal Relay 2 Selection
	"Thermal RLY2 T      "	,	//	551 14-66	Thermal Relay 2 Time
	"Momentary Power     "	,	//	552 14-67	Momentary Power Loss
	"Power Loss Time sec "	,	//	553 14-68	Max. allowable PL time
	"Base Block Time sec "	,	//	554 14-69	BB Time for speed serach
	"SPD Search Curr %   "	,	//	555 14-70	Current level for SPD serach
	"BB Treatment        "	,	//	556 14-71	bb treatment for oc, ov, bb
	"Auto Restart        "	,	//	557 14-72	Auto restart after fault
	"Restart Method      "	,	//	558 14-73	Auto restart Speed serach method
	"DEB Decel SEL       "	,	//	559 14-74	Deceleration at Momertary Power loss 
	"DEB Return Time     "	,	//	560 14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561 14-76	PID feedback selection	
	"P Gain of PID       "	,	//	562 14-77	P gain of PID	
	"I Gain of PID   sec "	,	//	563 14-78	I gain of PID	
	"D Gain of PID       "	,	//	564 14-79	D gain of PID	
	"Up Limit for I  %   "	,	//	565 14-80	Upper bound for integral	
	"PID Out-Limiter %   "	,	//	566 14-81	PID output Freq. Limit	
	"PID Offset      %   "	,	//	567 14-82	PID offset	
	"PID Out-Filter  sec "	,	//	568 14-83	Derivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	569 14-84	Feedback signal detection time	
	"PID Fdb Loss        "	,	//	570 14-85	PID feedback loss	
	"SLEEP FREQ          "	,	//	571 14-86	Sleep Frequency	
	"WAKE FREQ           "	,	//	572 14-87	Wake up Frequency	
	"SLEEP TIME          "	,	//	573 14-88	Sleep Time	
	"PID DEV. LEVEL  %   "	,	//	574 14-89	PID Deviation Level	
	"PID DEV. TIME       "	,	//	575 14-90	PID Deviation Time	
	"PID Fbk Filter  sec "	,	//	576 14-91	PID feedback filter	
	"Comm Main Freq. Hz  "	,	//	577 14-92	Main Frequency from communication	
	"Block Trans. 1      "	,	//	578 14-93	Block Transfer 1	
	"Block Trans. 2      "	,	//	579 14-94	Block Transfer 2	
	"Block Trans. 3      "	,	//	580 14-95	Block Transfer 3
	"Block Trans. 4      "	,	//	581 14-96	Block Transfer 4
	"Block Trans. 5      "	,	//	582 14-97	Block Transfer 5
	"Block Trans. 6      "	,	//	583 14-98	Block Transfer 6
	"Block Trans. 7      "	,	//	584 14-99	Block Transfer 7
	"Block Trans. 8      "	,	//	585 14-100  Block Transfer 8
	"Block Trans. 9      "	,	//	586 14-101  Block Transfer 9
	"Block Trans. 10     "	,	//	587 14-102  Block Transfer 10
	"WEAKLPF             "	,	//	588 14-103  WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	589 14-104  WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	590 14-105  OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"PG Position Home    "	,	//	591 14-106  PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592 14-107  Range for PG Position Attained
	"APR FFD Gain        "	,	//	593 14-108  Gain of APR feedforward
	"APR Decel Time  sec "	,	//	594 14-109  Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	595 14-110  FMax Target by Vcommand Position
	"RESERVE             "	,	//	596 14-111  Accel. Time for Position
	"PG Mech. Gear A     "	,	//	597 14-112  PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	598 14-113  PG Mechanical Gear B
	"System Jm       PU  "	,	//	599 14-114  Interia of motor PU
	"M1IdsRef Limit   %  "	,	//	600 14-115  Motor1 IdsRef Limit
	"M2IdsRef Limit   %  "	,	//	601 14-116  Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	602 14-117  Phase Loss Time
	"TH Inside Temp   C  "	,	//	603 14-118  Thermo inside Temp
	"ASR FeedForward     "	,	//	604 14-119  Speed feed forword
	"SlipGen.CompGain    "	,	//	605 14-120  SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//	606 14-121  PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607 14-122  Tension of Torque Control
	"DIAMETER        m   "	,	//	608 14-123  Diameter of Material
	"DEPTH           cm  "	,	//	609 14-124  Depth of meterial
	"RESERVE             "	,	//	610 14-125  Reserve
	"ABZ ST Times        "	,	//	611 14-126  Reserve
	"ABZ ST Duty         "	,	//	612 14-127  Reserve
	"TIMER OF PHL    hr. "	,	//	613 14-128  Timer of Phase loss (hour)
	"RESERVE             "	,	//	614 14-129  Time of APR Curve
    "Jm source           "  ,   //	615 14-130  IM control use inertia source
	"PHL LEVEL           "	,	//	616 14-131  PHASE LOSS detect level
	"Muti-input state    "	,	//	617 14-132  muti input state
    "StandStill Curr.Amps"  ,   //  618 14-133  Standstill Current
	"PG Scale Factor     "	,	//	619 14-134  Division factor of PG	 
	"OLD Irate           "	,	//	620 14-135  OLD Irate       // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   //  6XX 14-136  [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   //  6XX 14-137  [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time  sec "	,   //  6XX 14-138  [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   //  6XX 14-139  [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    "VFD Com1 Address    "	,	//	6XX 14-140  Comm Address           //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                      
	"COM1 Baud Rate  kbps"	,	//	6XX 14-141  Tranmission speed                         
	"COM1 Fault Treat    "	,	//	6XX 14-142  Comm fault Treatment                      
	"COM1 Time Out   sec "	,	//	6XX 14-143  Comm Time out                             
	"COM1 Protocol       "	,	//	6XX 14-144  Comm Protocol                             
	"COM1 Delay Time ms  "	,	//	6XX 14-145  ASC remote Response Delay Time, 1=100us 
    "OPHL 10Hz COUNT     "	,	//	6XX 14-146  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "	,	//	6XX 14-147  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "	,	//	6XX 14-148  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "	,	//	6XX 14-149  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "	,	//	6XX 14-150  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "	,	//	6XX 14-151  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "	,	//	6XX 14-152  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 3       "	,	//	6XX 14-153  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_TC
const string20 prinfo_tc_ACC_ms2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"第一加速時間    m/s2"	,	//	156	01-12 1st Acceleration time      //chinese description creat by Bernie 
	"第一減速時間    m/s2"	,	//	157	01-13 1st Deceleration time      //chinese description creat by Bernie 
	"第二加速時間    m/s2"	,	//	158	01-14 2nd Acceleration time      //chinese description creat by Bernie 
	"第二減速時間    m/s2"	,	//	159	01-15 2nd Deceleration time      //chinese description creat by Bernie 
	"第三加速時間    m/s2"	,	//	160	01-16 3rd Acceleration time      //chinese description creat by Bernie 
	"第三減速時間    m/s2"	,	//	161	01-17 3rd Deceleration time      //chinese description creat by Bernie 
	"第四加速時間    m/s2"	,	//	162	01-18 4th Acceleration time      //chinese description creat by Bernie 
	"第四減速時間    m/s2"	,	//	163	01-19 4th Deceleration time      //chinese description creat by Bernie 
	"寸動加速時間    m/s2"	,	//	164	01-20 JOG Acceleration time
	"寸動減速時間    m/s2"	,	//	165	01-21 JOG Deceleration time
	"停車減速時間    m/s2"
};

const string20 prinfo_tc_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"第一加速時間    f/s2"	,	//	156	01-12 1st Acceleration time      //chinese description creat by Bernie 
	"第一減速時間    f/s2"	,	//	157	01-13 1st Deceleration time      //chinese description creat by Bernie 
	"第二加速時間    f/s2"	,	//	158	01-14 2nd Acceleration time      //chinese description creat by Bernie 
	"第二減速時間    f/s2"	,	//	159	01-15 2nd Deceleration time      //chinese description creat by Bernie 
	"第三加速時間    f/s2"	,	//	160	01-16 3rd Acceleration time      //chinese description creat by Bernie 
	"第三減速時間    f/s2"	,	//	161	01-17 3rd Deceleration time      //chinese description creat by Bernie 
	"第四加速時間    f/s2"	,	//	162	01-18 4th Acceleration time      //chinese description creat by Bernie 
	"第四減速時間    f/s2"	,	//	163	01-19 4th Deceleration time      //chinese description creat by Bernie 
	"寸動加速時間    f/s2"	,	//	164	01-20 JOG Acceleration time
	"寸動減速時間    f/s2"	,	//	165	01-21 JOG Deceleration time
	"停車減速時間    f/s2"
};


const string20 prinfo_tc_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"加速開始S1時間  m/s3"	,	//	168	01-24 S curve Accel time 1
	"加速開始S2時間  m/s3"	,	//	169	01-25 S curve Accel time 2
	"加速開始S3時間  m/s3"	,	//	170	01-26 S curve Decel time 1
	"加速開始S4時間  m/s3"	,	//	171	01-27 S curve Decel time 2
	"低於平層速度S5  m/s3"	
};

const string20 prinfo_tc_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"加速開始S1時間  f/s3"	,	//	168	01-24 S curve Accel time 1
	"加速開始S2時間  f/s3"	,	//	169	01-25 S curve Accel time 2
	"加速開始S3時間  f/s3"	,	//	170	01-26 S curve Decel time 1
	"加速開始S4時間  f/s3"	,	//	171	01-27 S curve Decel time 2
	"低於平層速度S5  f/s3"	
};

const string20 prinfo_tc[EPMAX] = {	
/*---- GROUP 15---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"DEBUG FLAG          "	,	//	0   15-00	Debug Flag 1	                                
	"DBC Change Freq.    "	,	//	1   15-01	DBC CHANGE FREQ	                                
	"EFFICIENCY      %   "	,	//	2   15-02	efficiency of Motor	                            
    "ZOffset Tune I  %   "  ,   //  3   15-03   Z Phase search current level                    
	"RATED-I AD VALUE    "	,	//	4   15-04	AD value at Rated Current	                    
	"Ide Iqe LPF Gain    "	,	//	5   15-05	Id*,Iq* LPF	                                    
	"Factory Serial 1    "	,	//	6   15-06	Only for Factory 1	                            
	"Factory Serial 2    "	,	//	7   15-07	Only for Factory 2	                            
	"Factory Serial 3    "	,	//	8   15-08	Only for Factory 3	                            
	"Factory Serial 4    "	,	//	9   15-09	Only for Factory 4	                            
	"REVERSED            "	,	//	10  15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]               
	"Skip DeadTime       "	,	//	11  15-11	Skip Dead Time	                                
	"210.0 VDC AD        "	,	//	12  15-12	DCBUS 210.0 VDC ad value	                    
	"310.0 VDC AD        "	,	//	13  15-13	DCBUS 310.0 VDC ad value	                    
	"390.0 VDC AD        "	,	//	14  15-14	DCBUS 390.0 VDC ad value	                    
	"TRQ_P               "	,	//	15  15-15	Torque control Kp	                            
	"TRQ_I               "	,	//	16  15-16	Torque Control Ki	                            
	"FLUX_P              "	,	//	17  15-17	Flux Control Kp	                                
	"FLUX_I              "	,	//	18  15-18	Flux Control Ki	                                
	"SpdSlop_P           "	,	//	19  15-19	Speed slop Control Kp gain	                    
	"SpdSlop_I           "	,	//	20  15-20	Speed slop Control Ki gain	                    
	"Control Select      "	,	//	21  15-21	Control Selection	                            
	"TEST SOURCE Amp.    "	,	//	22  15-22	Test Source Value Amplitude	                    
	"High Speed LPG  Hz  "	,	//	23  15-23	High Speed Low pass Filter Gain	                
	"Low Speed LPG   Hz  "	,	//	24  15-24	Low Speed Low pass filter Gain	                
	"TEST SOURCE Bias    "	,	//	25  15-25	Test Source Value Bias	                        
	"Est J LPG       s   "	,	//	26  15-26	Estimate J Low pass Filter Gain	                
	"Calibration A RE    "	,	//	27  15-27	Calibration current REF	                        
	"Calibration P       "	,	//	28  15-28	Calibration P	                                
	"Calibration I       "	,	//	29  15-29	Calibration I	                                
	"DC-Tun current P    "	,	//	30  15-30	Auto tuning DC test Kp gain	                    
	"DC-Tun current I    "	,	//	31  15-31	Auto Tuning DC test Ki gain	                    
	"High Freq. Tun P    "	,	//	32  15-32	Auto tuning High Freq. Lock test Kp gain	    
	"High Freq. Tun I    "	,	//	33  15-33	ADcbus Low Pass Gain	                        
	"Gain of VcmpMax %   "	,	//	34  15-34	Select Zero Speed	                            
	"NL-Boost Gain       "	,	//	35  15-35	No Load Boost Gain	                            
	"Auto Accel. KP      "	,	//	36  15-36	Acceleration AKP	                            
	"Auto Accel. KI      "	,	//	37  15-37	Acceleration AKI	                            
	"Current Loop BW     "	,	//	38  15-38	Current Loop BandWidth                          
	"DBC Leading 2       "	,	//	39  15-39	DBC Leading 2                                   
	"DBC Ration 2        "	,	//	40  15-40	DBC Ratio 2 with close loop                     
	"DBC Coef.           "	,	//	41  15-41	DBC Coef.                                       
	"DBC Dcbus Coef.     "	,	//	42  15-42	DBC Dcbus Coef.                                 
	"DBC Leading 1       "	,	//	43  15-43	DBC leading 1                                   
	"DBC Ratio 1         "	,	//	44  15-44	DBC Linear Ratio 1                              
	"RESERVE             "	,	//	45  15-45	DBC MODE                                        
	"Magnitization L1    "	,	//	46  15-46	magnitization inductance 1                      
	"Main Flux Link 1    "	,	//	47  15-47	main flux linkage 1                             
	"Magnitization L2    "	,	//	48  15-48	magnitization inductance 2                      
	"Main Flux Link 2    "	,	//	49  15-49	main flux linkage 2                             
	"Magnitization L3    "	,	//	50  15-50	magnitization inductance 3                      
	"Main Flux Link 3    "	,	//	51  15-51	main flux linkage 3                             
	"Magnitization L4    "	,	//	52  15-52	magnitization inductance 4                      
	"Main Flux Link 4    "	,	//	53  15-53	main flux linkage 4                             
	"Magnitization L5    "	,	//	54  15-54	magnitization inductance 5                      
	"Main Flux Link 5    "	,	//	55  15-55	main flux linkage 5                             
	"Magnitization L6    "	,	//	56  15-56	magnitization inductance 6                      
	"Main Flux Link 6    "	,	//	57  15-57	main flux linkage 6                             
	"Modulation Index    "	,	//	58  15-58	Modulation Index                                
	"Zero Current LPG    "	,	//	59  15-59	Current Zero Low Pass Gain                      
	"COSphi LPF      ms  "	,	//	60  15-60	cos(TB1_uwPhi) low pass gain                          
	"Date Code Y.WKD     "  ,   //  61  15-61   DateCode  //Datecode para change, Henry, 2016/07/20 
	"AUI2 0V ADC     adc "	,	//	62  15-62	calibration for AUI ZeroPoint (0V)
	"AUI2 -10V ADC   adc "	,	//	63  15-63	calibration for AUI2 max (-10V)
	"AUI2 +10V ADC   adc "	,	//	64  15-64	calibration for AUI2 min (+10V)
	"ACI 20mA ADC    adc "	,	//	65  15-65	calibration for ACI2 max (20mA)                 
	"ACI 12mA ADC    adc "	,	//	66  15-66	calibration for ACI mid (12mA)                  
	"ACI 4mA ADC     adc "	,	//	67  15-67	calibration for ACI min (4mA)                   
	"AUI1 0V ADC     adc "	,	//	68  15-68	calibration for AUI1 ZeroPoint (0V)
	"AUI1 -10V ADC   adc "	,	//	69  15-69	calibration for AUI1 max (-10V)
	"AUI1 +10V ADC   adc "	,	//	70  15-70	calibration for AUI1 min (+10V)
	"Auto Decel. DKP     "	,	//	71  15-71	Deceleration DKP                                
	"Auto Decel. DKI     "	,	//	72  15-72	Deceleration DKI                                
	"Low Speed Comp. Hz  "	,	//	73  15-73	more volt. comp. below this freq.               
	"PGLOSS Detcect T    "	,	//	74  15-74	PGLOSS Detect Counter                           
	"Main Frequency      "	,	//	75  15-75	Main Frequency                                  
	"Power On Counter    "	,	//	76  15-76	Power On Counter                                
	"GFF_Pk Detec SW     "	,	//	77  15-77	GFF Maximum Value Record Switch, Jerry Yu, 2019/11/11 
	"BLD Version         "	,	//	78  15-78   //[BootLoader Version, Special.Kung, 2022/10/31]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"SIBO EPS FRMODE     "  ,   //  89  15-79   SIBO EPS FRMODE
#else
    "RESERVE             "  ,   //  79  15-79
#endif
    "OPHL_SPER           "  ,   //  80  15-80
    "OPHL_CURER          "  ,   //  81  15-81
    "OPHL_ERCNT          "  ,   //  82  15-82                                 
	"BLD DateCode        "  ,   //  83  15-83   //[BootLoader DataCode, Special.Kung, 2022/10/31] 
	"FineAUI 0V ADC  adc "	,	//	84  15-84	calibration for AUI ZeroPoint (0V)              
	"FineAUI +2V ADC adc "	,	//	85  15-85	calibration for AUI max (+2V)                   
	"FineAUI -2V ADC adc "	,	//	86  15-86	calibration for AUI min (-2V)                   
	"SIN MAX V ADC   adc "	,	//	87  15-87	calibration for SIN max, add by dino, 06/01/2007
	"SIN MIN V ADC   adc "	,	//	88  15-88	calibration for SIN min, add by dino, 06/01/2007
	"COS MAX V ADC   adc "	,	//	89  15-89	calibration for COS max, add by dino, 06/01/2007
	"COS MIN V ADC   adc "	,	//	90  15-90	calibration for COS min, add by dino, 06/01/2007
    "Min. Pulse Width    "  ,   //  91  15-91   minimum pulse, ADDED BY SCOTTY,2007/07/11
	"D Frame FAN Cont    "	,	//	92 	15-92	D Frame Fan control
	"Z Phase UVW Sect    "	,	//	93 	15-93	Z phase UVW Section when PG_TYPE = 2
    "                    "  ,   //  94  15-94   
    "LAST PG COUNTER     "  ,   //  95  15-95   PG Position Record, add by scotty, 12/07/2007
	"AFM MAX. Value      "	,	//	96 	15-96   AFM max. value
	"AFM MIN. Value      "	,	//	97 	15-97   AFM min. value
	"Soft Start Time sec "	,	//	98  15-98	Softstart Delay Time
    "DEBUG FLAG2         "  ,   //  99  15-99   //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
	"Z-cab Mode          "  ,   //  100 15-100
	"Qer_min             "  ,   //  101 15-101
	"Qer_Shift           "  ,   //  102 15-102
	"Sin_HS_Tab          "  ,   //  103 15-103
	"                    "  ,   //  104 15-104
	"RESERVE             "	,	//	105 15-105  RESERVED
	"CAN Control         "	,	//	106 15-106  Can Control      //[CAN Control, Sampo, 09/15/2010]
	"CAN Fault Handle    "	,	//	107 15-107  Can Fault Handle //[CAN Control, Sampo, 09/15/2010]
	"DEBUG_PG            "	,	//	108 15-108  DEBUG_PG
	"_47th_DISP          "	,	//	109 15-109  _47th_DISP
	"PG_MODE             "	,	//	110 15-110  RESERVED
	"WDT Divider         "	,	//	111 15-111  WDT_DIV          //[ICT WDT test, Bernie, 08/16/2011]
	"AFM1 +10V CNT       "	,	//	112 15-112  AFM1_P10CNT for AFM1 +10V output
	"AFM1 0V CNT         "	,	//	113 15-113  AFM1_0CNT for AFM1 0V output
	"AFM1 -10V CNT       "	,	//	114 15-114  AFM1_M10CNT for AFM1 -10V output
	"AFM2 +10V CNT       "	,	//	115 15-115  AFM2_P10CNT for AFM2 +10V output
	"AFM2 0V CNT         "	,	//	116 15-116  AFM2_0CNT for AFM2 0V output
	"AFM2 -10V CNT       "	,	//	117 15-117  AFM2_M10CNT for AFM2 -10V output
	"Protect Bit SW      "	,	//	118 15-118  The switch of Protect finction        //[The switch of Protect finction, Bernie, 2015/05/21]
	"OPHL COUNT          "	,	//	119 15-119  The Count of Protect finction         //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL IRMS           "	,	//	120 15-120  The IRMS value of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL COUNT          "	,	//	121 15-121  The Gain value of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
	"PPI filter point    "	,	//	122 15-122  RESERVED
	"MBF Recoder         "	,	//	123 15-123  MBF record after power off
	"EoL Cnt Recder H    "	,	//	124 15-124  RESERVED        //[add for UL EoL Verification,Bernie, 2013/04/22]
	"EoL Cnt Recder L    "	,	//	125 15-125  RESERVED        //[add for UL EoL Verification,Bernie, 2013/04/22]
	"RESERVE             "	,	//	126 15-126  RESERVED
	"Unavailable         "	,	//	127 15-127  RESERVED
//	"PPI filter point    "	,	//	128 15-128  PPI control     //[PPI function, Sampo, 2015/09/08]

/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
    "機種識別碼          "	,	//	128 00-00	Model Type of Drive 
    "變頻器額定電流  Amps"	,	//	129 00-01	Rated Current
    "參數重置設定        "	,	//	130 00-02	Parameter Reset
    "開機顯示畫面選擇    "	,	//	131 00-03	Start up Display       //chinese description creat by Bernie 
    "多功\能顯示選擇      "	,	//	132 00-04	User Display            // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "定義比例設定        "	,	//	133 00-05	User Coefficient        //chinese description creat by Bernie 
    "軟體版本            "	,	//	134 00-06	Software Version
    "參數保護解碼輸入    "	,	//	135 00-07	Password Input
    "參數保護解碼設定    "	,	//	136 00-08	Password Input
    "控制模式            "	,	//	137 00-09	Control Methods
    "速度單位            "	,	//	138 00-10	Velocity Unit Select
    "驅動器輸出方向      "	,	//	139 00-11   Change Output Direction, Added by sampo , 06/11/2009
    "載波頻率        KHz "	,	//	140 00-12	Carry Frequency
    "自動穩壓功\能        "	,	//	141 00-13	AVR                     // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "速度指令來源        "	,	//	142 00-14	Source of Freq. Command
    "運轉指令來源        "	,	//	143 00-15	Source of Oper. Command
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"最大操作頻率    Hz  "	,	//	144	01-00   Max Output Freq.
	"電機額定頻率    Hz  "	,	//	145	01-01   Motor Base Frequency 1
	"電機額定電壓    V   "	,	//	146	01-02   Max Output Voltage
	"第二輸出頻率    Hz  "	,	//	147	01-03   Mid Output Freq.1
	"第二輸出電壓    V   "	,	//	148	01-04   Mid Output Voltage 1
	"第三輸出頻率    Hz  "	,	//	149	01-05   Mid Output Freq.2
	"第三輸出電壓    V   "	,	//	150	01-06   Mid Output Voltage 2
	"第四輸出頻率    Hz  "	,	//	151	01-07   Min Output Freq.
	"第四輸出電壓    V   "	,	//	152	01-08   Min Output Voltage
	"啟動頻率        Hz  "	,	//	153	01-09   Start Frequency
	"輸出頻率上限值  Hz  "	,	//	154	01-10   Upper Bound Freq.
	"輸出頻率下限值  Hz  "	,	//	155	01-11   Lower Bound Freq.
	"第一加速時間    sec "	,	//	156	01-12   1st Acceleration time      //chinese description creat by Bernie 
	"第一減速時間    sec "	,	//	157	01-13   1st Deceleration time      //chinese description creat by Bernie 
	"第二加速時間    sec "	,	//	158	01-14   2nd Acceleration time      //chinese description creat by Bernie 
	"第二減速時間    sec "	,	//	159	01-15   2nd Deceleration time      //chinese description creat by Bernie 
	"第三加速時間    sec "	,	//	160	01-16   3rd Acceleration time      //chinese description creat by Bernie 
	"第三減速時間    sec "	,	//	161	01-17   3rd Deceleration time      //chinese description creat by Bernie 
	"第四加速時間    sec "	,	//	162	01-18   4th Acceleration time      //chinese description creat by Bernie 
	"第四減速時間    sec "	,	//	163	01-19   4th Deceleration time      //chinese description creat by Bernie 
	"寸動加速時間    sec "	,	//	164	01-20   JOG Acceleration time
	"寸動減速時間    sec "	,	//	165	01-21   JOG Deceleration time
	"寸動頻率        Hz  "	,	//	166	01-22   JOG Frequency
	"1-4加減速切換   Hz  "	,	//	167	01-23   Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"加速開始S1時間  sec "	,	//	168	01-24   S curve Accel time 1
	"加速開始S2時間  sec "	,	//	169	01-25   S curve Accel time 2
	"加速開始S3時間  sec "	,	//	170	01-26   S curve Decel time 1
	"加速開始S4時間  sec "	,	//	171	01-27   S curve Decel time 2
	"小於第四頻率模式    "	,	//	172	01-28   Select Zero Speed
	"平層速度切換    Hz  "	,	//	173	01-29   Landing Frequency 
	"低於平層速度S5  sec "	,	//	174	01-30   S curve Decel time 3
	"停車減速時間    sec "	,	//	175	01-31   Stop Deceleration time
    "終端強制減速度  m/s "	,	//  1xx 01-32
    "端子直停高速時間sec "	,	//	1xx	01-33   IODHT IO direct hold time   
    "端子直停平層時間sec "	,	//	1xx	01-34   IODLT IO direct landing freq
    "端子直停衝量限制    "	,	//	1xx	01-35   IODLT IO direct landing time
    "端子直停減速距離cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "直停參考減速距離m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "端子直接停靠致能    "	,	//	1xx	01-38   IODLT IO direct DistancE
    "ETS頻率比較準位 Hz  "  ,   //  1xx 01-37   IODLT IO direct DistancE
    "緊急減速減速時間sec "	,	//	1xx	01-37   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Emergency DEC   sec "  ,   //  105 15-105  RESERVE
    "Emergency S3    sec "  ,   //  105 15-105  RESERVE
    "Emergency S4    sec "  ,   //  105 15-105  RESERVE
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "2/3 線式運轉控制    "	,	//	176	02-00   2/3 wire control                
    "MI1功\能選擇         "	,	//	177	02-01   Multi-Function Input 1          
    "MI2功\能選擇         "	,	//	178	02-02   Multi-Function Input 2       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]       
    "MI3功\能選擇         "	,	//	179	02-03   Multi-Function Input 3       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI4功\能選擇         "	,	//	180	02-04   Multi-Function Input 4       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI5功\能選擇         "	,	//	181	02-05   Multi-Function Input 5       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI6功\能選擇         "	,	//	182	02-06   Multi-Function Input 6       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI7功\能選擇         "	,	//	183	02-07   Multi-Function Input 7       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI8功\能選擇         "	,	//	184	02-08   Multi-Function Input 8       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "數位輸入響應時間sec "	,	//	185	02-09   Digital in response time		
    "數位輸入方向        "	,	//	186	02-10   Multi-Function Input Inverse	
    "RA 功\能選擇         "	,	//	187	02-11   Multi-Function Relay 1	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MRA功\能選擇         "	,	//	188	02-12   Multi-Function Relay 2	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "R1A功\能選擇         "	,	//	189	02-13   Multi-Function Output 1	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19] 	    
    "R2A功\能選擇         "	,	//	190	02-14   Multi-Function Output 2	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO1功\能選擇         "	,	//	191	02-15   Multi-Function Output 3	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO2功\能選擇         "	,	//	192	02-16   Multi-Function Output 4	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO3功\能選擇         "	,	//	193	02-17   Multi-Function Output 5	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO4功\能選擇         "	,	//	194	02-18   Multi-Function Output 6	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO5功\能選擇         "	,	//	195	02-19   Multi-Function Output 7	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO6功\能選擇         "	,	//	196	02-20   Multi-Function Output 8	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO7功\能選擇         "	,	//	197	02-21   Multi-Function Output 9	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO8 功\能選擇        "	,	//	198	02-22   Multi-Function Output 10	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "數位輸出方向        "	,	//	199	02-23   Multi-Function Output inverse	
    "啟動信號模式選擇    "  ,   //  200 02-24   Sequence start mode
    "任意頻率到達1   Hz  "	,	//	201	02-25   Desired Frequency 1		        
    "任意頻率到達1寬 Hz  "	,	//	202	02-26   Band of Desired Frequency 1		
    "任意頻率到達2   Hz  "	,	//	203	02-27   Desired Frequency 2		        
    "任意頻率到達2寬 Hz  "	,	//	204	02-28   Band of Desired Frequency 2		
    "機械煞車放閘延時sec "	,	//	205	02-29   Brake Delay Timer at run
    "機械煞車抱閘延時sec "	,	//	206	02-30   Brake Delay Timer at stop
    "電磁閥導通延時  sec "	,	//	207	02-31   Mech Contact Delay Timer run
    "電磁閥斷開延時  sec "	,	//	208	02-32   Mech Contact Delay Timer stop				            
    "電流準位設定    %   "	,	//	209	02-33   Isum Current Output Detect	    
    "速度區段設定    Hz  "	,	//	210	02-34   Speed Area
    "機械煞車檢出時間sec "	,	//	211	02-35   Mechanical Brake Checking Time
    "電磁閥檢出時間  sec "	,	//	212 02-36   Magnetic Contactor Checking Time
    "轉矩確認動作選擇    "  ,   //  213 02-37   Mechanical Brake Checking Current Enable
    "封星導通延時間  sec "  ,   //  207 02-38   Mech Contact Delay Timer run            //[Star contactor function, Bernie, 2017/03/22] 
    "封星斷開延時間  sec "  ,   //  208 02-39   Mech Contact Delay Timer stop           //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD異常選擇       "  ,   //  2xx 02-40   LU/LD error  Selection	                //#15977, LULD detect, James, 2021/04/01
	"LU/LD開路偵測   sec "  ,   //  2xx 02-41   LD/LD Open Detect Time                  //#15977, LULD detect, James, 2021/04/01
	"LU/LD短路偵測   sec "  ,   //  2xx 02-42   LD/LD Short Detect Time                 //#15977, LULD detect, James, 2021/04/01
    "運轉速度到達寬度Hz  "	,	//  202 02-43   Band of Speed Agree Function #18572			
    "STO短路偵測時間 sec "  ,   //  2xx 02-44   STO shor detect time                    //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "速度限制        m/s "  ,   //  2xx 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06] 
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AUI1功\能選擇        "	,	//	214	03-00   AUI1 selection                    //[Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	215	03-01   ACI  selection                    //[ACI function remove, Bernie, 01/20/2012]
    "AUI2功\能選擇        "	,	//	216	03-02   AUI2 selection                    //[Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1輸入偏壓    %   "	,	//	217	03-03   AUI1 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	218	03-04   ACI  input Bias                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2輸入偏壓    %   "	,	//	219	03-05   AUI2 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1正負偏壓模式    "	,	//	220 03-06   AUI1 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	221 03-07   ACI  input Polarity               //[ACI function remove, Bernie, 01/20/2012]
    "AUI2正負偏壓模式    "	,	//	222 03-08   AUI2 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1輸入增益    %   "	,	//	223 03-09   AUI1 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	224 03-10   ACI  input Gain                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2輸入增益    %   "	,	//	225 03-11   AUI2 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1濾波時間    sec "	,	//	226 03-12   Low pass filter of AUI1 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	227 03-13   Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2濾波時間    sec "	,	//	228 03-14   Low pass filter of AUI2 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "荷重補償自學習      "	,	//	229 03-15   Loss of ACI                       //[ACI function remove, Bernie, 01/20/2012]
    "保留                "  ,   //  230 03-16   RESERVED 
    "AO1 輸出選擇        "	,	//	231 03-17   Analong Output 1
    "AO1 輸出增益    %   "	,	//	232 03-18   Analong Output 1 Gain
    "AO1 輸出反向致能    "	,	//	233 03-19   AO1 in minus value
    "AO2 輸出選擇        "	,	//	234 03-20   Analong Output 2
    "AO2 輸出增益    %   "	,	//	235 03-21   Analong Output 2 Gain
    "AO2 輸出反向致能    "	,	//	236 03-22   AO2 in minus value
    "AUI1類比輸入型式    "	,	//	237 03-23   AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2類比輸入型式    "	,	//	238 03-24   AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1輸入設定        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2輸入設定        "	,	//	238  03-26    AUI2 Communciate
	

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "第零段速        Hz  "	,   //  239 04-00   Multi-Speed 0
    "第一段速        Hz  "	,   //  240 04-01   Multi-Speed 1
    "第二段速        Hz  "	,   //  241 04-02   Multi-Speed 2
    "第三段速        Hz  "	,   //  242 04-03   Multi-Speed 3
    "第四段速        Hz  "	,   //  243 04-04   Multi-Speed 4
    "第五段速        Hz  "	,   //  244 04-05   Multi-Speed 5
    "第六段速        Hz  "	,   //  245 04-06   Multi-Speed 6
    "第七段速        Hz  "	,   //  246 04-07   Multi-Speed 7
    "第八段速        Hz  "	,   //  247 04-08   Multi-Speed 8
    "第九段速        Hz  "	,   //  248 04-09   Multi-Speed 9
    "第十段速        Hz  "	,   //  249 04-10   Multi-Speed 10 
    "第十一段速      Hz  "	,   //  250 04-11   Multi-Speed 11
    "第十二段速      Hz  "	,   //  251 04-12   Multi-Speed 12
    "第十三段速      Hz  "	,   //  252 04-13   Multi-Speed 13
    "第十四段速      Hz  "	,   //  253 04-14   Multi-Speed 14
    "第十五段速      Hz  "	,   //  254 04-15   Multi-Speed 15
    
    "救援速度        m/s "  ,   //  2xx 04-16
    "平層速度        m/s "  ,   //  2xx 04-17
    "反基站速度      m/s "  ,   //  2xx 04-18
    "鋼索打滑補償    mm  "  ,   //  2xx 04-19   GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //  2xx 04-20
    "TABST2 Status       "  ,   //  2xx 04-21
    "最高物理樓層        "  ,   //  2xx 04-22
    "目前樓層            "  ,   //  2xx 04-23
    "脈衝校正條件    %   "  ,   //  2xx 04-24
    "開關延遲補償    sec "  ,   //    2xx 04-25
    "等速冗餘時間    ms  "  ,   //  2xx 04-26
    "著床板長度      mm  "  ,   //  2xx 04-27 
    "目前位置 高     m   "  ,   //  2xx 04-28
    "目前位置 低     mm  "  ,   //  2xx 04-29
    "目前脈衝 H          "  ,   //  2xx 04-30 
    "目前脈衝 L          "  ,   //  2xx 04-31
    "著床板脈衝 H        "  ,   //  2xx 04-32
    "著床板脈衝 L        "  ,   //  2xx 04-33
    "光電間距脈衝H       "  ,   //  2xx 04-34
    "光電間距脈衝L       "  ,   //  2xx 04-35
    "DLC功\能集           "  ,  //  2xx 04-36   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "PDO顯示型態         "  ,   //  2xx 04-37
    "減速開關容許\誤差mm  "  ,  //  2xx 04-38   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "最大梯速百分比  %   "  ,   //  2xx 04-39   //[ADCO EPS Modify]
    "彈簧延伸補償    mm  "  ,   //    2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //  2xx 04-41
    "EST Count           "  ,   //  2xx 04-42
    "TABST0 Count        "  ,   //  2xx 04-43
    "TABST1 Count        "  ,   //  2xx 04-44
    "DDS1/UDS1速限   m/s "  ,   //  2XX 04-45   DD1_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS2/UDS2速限   m/s "  ,   //  2XX 04-46   DD2_Vlim  //Artemis speed limit, James, 20200220                                
    "DDS3/UDS3速限   m/s "  ,   //  2XX 04-47   DD3_Vlim  //Artemis speed limit, James, 20200220                                      
    "DDS4/UDS4速限   m/s "  ,   //  2XX 04-48   DD4_Vlim  //Artemis speed limit, James, 20200220
    "功\能頁面設定        "  ,  //  2XX 04-49   user page cahnge       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    
    "1 樓位置 高     m   "  ,   //  2XX 04-50   1Floor Position H 
    "1 樓位置 低     mm  "  ,   //  2XX 04-51   1Floor Position L                                       
    "2 樓位置 高     m   "  ,   //  2XX 04-52   2Floor Position H                                       
    "2 樓位置 低     mm  "  ,   //  2XX 04-53   2Floor Position L                                       
    "3 樓位置 高     m   "  ,   //  2XX 04-54   3Floor Position H                                       
    "3 樓位置 低     mm  "  ,   //  2XX 04-55   3Floor Position L                                       
    "4 樓位置 高     m   "  ,   //  2XX 04-56   4Floor Position H                                       
    "4 樓位置 低     mm  "  ,   //  2XX 04-57   4Floor Position L                                       
    "5 樓位置 高     m   "  ,   //  2XX 04-58   5Floor Position H                                       
    "5 樓位置 低     mm  "  ,   //  2XX 04-59   5Floor Position L                                       
    "6 樓位置 高     m   "  ,   //  2XX 04-60   6Floor Position H                                       
    "6 樓位置 低     mm  "  ,   //  2XX 04-61   6Floor Position L                                       
    "7 樓位置 高     m   "  ,   //  2XX 04-62   7Floor Position H                                       
    "7 樓位置 低     mm  "  ,   //  2XX 04-63   7Floor Position L                                       
    "8 樓位置 高     m   "  ,   //  2XX 04-64   8Floor Position H                                       
    "8 樓位置 低     mm  "  ,   //  2XX 04-65   8Floor Position L                                       
    "9 樓位置 高     m   "  ,   //  2XX 04-66   9Floor Position H                                       
    "9 樓位置 低     mm  "  ,   //  2XX 04-67   9Floor Position L                                       
    "10樓位置 高     m   "  ,   //  2XX 04-68   10Floor Position H                                      
    "10樓位置 低     mm  "  ,   //  2XX 04-69   10Floor Position L                                      
    "11樓位置 高     m   "  ,   //  2XX 04-70   11Floor Position H                                      
    "11樓位置 低     mm  "  ,   //  2XX 04-71   11Floor Position L                                      
    "12樓位置 高     m   "  ,   //  2XX 04-72   12Floor Position H                                      
    "12樓位置 低     mm  "  ,   //  2XX 04-73   12Floor Position L                                      
    "13樓位置 高     m   "  ,   //  2XX 04-74   13Floor Position H                                      
    "13樓位置 低     mm  "  ,   //  2XX 04-75   13Floor Position L                                      
    "14樓位置 高     m   "  ,   //  2XX 04-76   14Floor Position H                                      
    "14樓位置 低     mm  "  ,   //  2XX 04-77   14Floor Position L                                      
    "15樓位置 高     m   "  ,   //  2XX 04-78   15Floor Position H                                      
    "15樓位置 低     mm  "  ,   //  2XX 04-79   15Floor Position L                                      
    "16樓位置 高     m   "  ,   //  2XX 04-80   16Floor Position H                                      
    "16樓位置 低     mm  "  ,   //  2XX 04-81   16Floor Position L                                      
    "17樓位置 高     m   "  ,   //  2XX 04-82   17Floor Position H                                      
    "17樓位置 低     mm  "  ,   //  2XX 04-83   17Floor Position L                                      
    "18樓位置 高     m   "  ,   //  2XX 04-84   18Floor Position H                                      
    "18樓位置 低     mm  "  ,   //  2XX 04-85   18Floor Position L                                      
    "19樓位置 高     m   "  ,   //  2XX 04-86   19Floor Position H                                      
    "19樓位置 低     mm  "  ,   //  2XX 04-87   19Floor Position L                                      
    "20樓位置 高     m   "  ,   //  2XX 04-88   20Floor Position H                                      
    "20樓位置 低     mm  "  ,   //  2XX 04-89   20Floor Position L                                      
    "21樓位置 高     m   "  ,   //  2XX 04-90   21Floor Position H                                      
    "21樓位置 低     mm  "  ,   //  2XX 04-91   21Floor Position L                                      
    "22樓位置 高     m   "  ,   //  2XX 04-92   22Floor Position H                                      
    "22樓位置 低     mm  "  ,   //  2XX 04-93   22Floor Position L                                      
    "23樓位置 高     m   "  ,   //  2XX 04-94   23Floor Position H                                      
    "23樓位置 低     mm  "  ,   //  2XX 04-95   23Floor Position L                                      
    "24樓位置 高     m   "  ,   //  2XX 04-96   24Floor Position H                                      
    "24樓位置 低     mm  "  ,   //  2XX 04-97   24Floor Position L                                      
    "25樓位置 高     m   "  ,   //  2XX 04-98   25Floor Position H                                      
    "25樓位置 低     mm  "  ,   //  2XX 04-99   25Floor Position L                                      
    
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM參數自學習        "	,	//	255 05-00   Motor Auto-Tuning
    "IM電機額定電流  Amps"	,	//	256 05-01   Motor 1 rated Current           
    "IM電機額定功\率  Kw  "	,	//	257 05-02   Motor 1 Rated Power       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]           
    "IM電機額定轉速  RPM "	,	//	258 05-03   Motor 1 Rated RPM               
    "IM電機極數          "	,	//	259 05-04   Motor 1 pole No.                
    "IM電機無載電流  Amps"	,	//	260 05-05   Motor 1 No-Load Current         
    "IM電機參數 Rs   ohm "	,	//	261 05-06   Motor 1 Rs                      
    "IM電機參數 Rr   ohm "	,	//	262 05-07   Motor 1 Rr                      
    "IM電機參數 Lm   mH  "	,	//	263 05-08   Motor 1 Lm                      
    "IM電機參數 Lx   mH  "	,	//	264 05-09   Motor 1 Lx                      
    "轉矩補償低通濾波sec "	,	//	265 05-10   Vector Voltage Filter	        
    "滑差補償低通濾波sec "	,	//	266 05-11   Vector Slip Filter	            
    "轉矩補償增益        "	,	//	267 05-12   Torque Compensation Gain	    
    "滑差補償增益        "	,	//	268 05-13   Slip Compensation Gain	        
    "滑差誤差準位    %   "	,	//	269 05-14   Slip Deviation level	        
    "滑差誤差檢出時間sec "	,	//	270 05-15   Slip Deviation Detect Time	    
    "過滑差檢出選擇      "	,	//	271 05-16   Over Slip treatment	            
    "震盪補償因子        "	,	//	272 05-17   Coeff for hunting disable	    
    "累積電機運轉時間Mins"	,	//	273 05-18   Accumulative Motor Operation Min
    "累積電機運轉天數Days"	,	//	274 05-19   Accumulative Motor Operation Day
    "鐵蕊損失補償    %   "	,	//	275 05-20   Coreloss % of output Power	    
    "變頻器上電時間  Mins"	,	//	276 05-21   Power On Min
    "變頻器上電天數  Days"	,	//	277 05-22   Power On Day    
    "回生滑差補償增益%   "  ,   //  2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"電動滑差補償增益%   "	,	//	123 05-24   RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "低電壓位準      V   "	,	//  278 06-00   Low voltage level
    "欠相保護            "	,	//  279 06-01   Phase loss
    "加速過電流失速  %   "	,	//	280 06-02   OC stall during Accel
    "定速過電流失速  %   "	,	//	281 06-03   OC stall during Decel
    "過電流失速處理      "	,	//	282 06-04   Stall preventation Accel/Decel time selection
    "過轉矩OT1處理       "	,	//	283 06-05   Over-Torque 1 Selection
    "過轉矩OT1位準   %   "	,	//	284 06-06   Over-Torque 1 level
    "過轉矩OT1檢出   sec "	,	//	285 06-07   Over-Torque 1 Time
    "過轉矩OT2處理       "	,	//	286 06-08   Over-Torque 2 Selection	                     
    "過轉矩OT2位準   %   "	,	//	287 06-09   Over-Torque 2 level	                         
    "過轉矩OT2檢出   sec "	,	//	288 06-10   Over-Torque 2 Time	                         
    "電流限制        %   "	,	//	289 06-11   Current Limit
    "電子熱電驛選擇      "	,	//	290 06-12   Thermal Relay 1 Selection
    "熱電驛作用時間  sec "	,	//	291 06-13   Thermal Relay 1 Time
    "過熱警告溫度位準C   "	,	//	292 06-14   OH Warning Level
    "失速防止限制位準%   "	,	//	293 06-15   Stall preventation Limit Level
    "最近一次故障紀錄    "	,	//	294 06-16   1st Fault Record
    "2次前的故障紀錄     "	,	//	295 06-17   2nd Fault Record
    "3次前的故障紀錄     "	,	//	296 06-18   3rd Fault Record
    "4次前的故障紀錄     "	,	//	297 06-19   4th Fault Record
    "5次前的故障紀錄     "	,	//	298 06-20   5th Fault Record
    "6次前的故障紀錄     "	,	//	299 06-21   6th Fault Record
    "異常輸出選擇 1      "	,	//	300 06-22   Fault Option 1
    "異常輸出選擇 2      "	,	//	301 06-23   Fault Option 2
    "異常輸出選擇 3      "	,	//	302 06-24   Fault Option 3
    "異常輸出選擇 4      "	,	//	303 06-25   Fault Option 4
    "PTC動作選擇         "	,	//	304 06-26   PTC over Treatments	                         
    "PTC準位         %   "	,	//	305 06-27   PTC Level
    "PTC檢出時間     sec "	,	//	306 06-28   PTC Detect Filter time
    "緊急運行電源電壓V   "	,	//	307 06-29   EPS voltage level
    "錯誤輸出選擇        "	,	//	308 06-30   Fault Option Mode
    "ED 輸出欠相偵測     "	,	//	309 06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "前一次異常運轉  Mins"	,	//	310 06-32   1st Fault Time(MIN)
    "前一次異常運轉  Days"	,	//	311 06-33   1st Fault Time(DAY)
    "2次前異常運轉   Mins"	,	//	312 06-34   2nd Fault Time(MIN)
    "2次前異常運轉   Days"	,	//	313 06-35   2nd Fault Time(DAY)
    "3次前異常運轉   Mins"	,	//	314 06-36   3rd Fault Time(MIN)
    "3次前異常運轉   Days"	,	//	315 06-37   3rd Fault Time(DAY)
    "4次前異常運轉   Mins"	,	//	316 06-38   4th Fault Time(MIN)
    "4次前異常運轉   Days"	,	//	317 06-39   4th Fault Time(DAY)
    "5次前異常運轉   Mins"	,	//	318 06-40   5th Fault Time(MIN)
    "5次前異常運轉   Days"	,	//	319 06-41   5th Fault Time(DAY)
    "6次前異常運轉   Mins"	,	//	320 06-42   6th Fault Time(MIN)
    "6次前異常運轉   Days"	,	//	321 06-43   6th Fault Time(DAY)
    "緊急電源運行速度Hz  "  ,   //  322 06-44   EPS Frequency
    "錯誤動作選擇        "  ,	//  323 06-45   LV Option Mode
    "EPS 模式選擇        "  ,	//  324 06-46   EPS Option Mode
    "發電方向搜尋時間sec "  ,   //  325 06-47   Generation Operation Detected Time
    "緊急運行電源容量KVA "  ,   //  326 06-48   UPS Capacity (0.1KVA)
    "STO功\能選擇        "  ,   //  3xx 06-49   STO Lock selection     //[Safty function, Bernie]    
    "故障重試時MO動作    "  ,   //  356 06-50   Base Block Speed Search (oc,ov,occ.......)  //[Add auto restart after fault, Bernie, 06/06/12]
    "故障重試次數        "  ,   //  356 06-51   Auto restart times after fault     
    "故障重試時間    sec "  ,   //  356 06-52   Auto restart interval
    "異常時頻率命令  Hz  "  ,   //  3xx 06-53   Fkey Record
    "異常時頻率輸出  Hz  "  ,   //  3xx 06-54   Fcmd Record
    "異常時輸出電流  Amps"  ,   //  3xx 06-55   Isum Record
    "異常時馬達頻率  Hz  "  ,   //  3xx 06-56   Fout Record
    "異常時輸出電壓  V   "  ,   //  3xx 06-57   Vout Record
    "異常時DCBus電壓 V   "  ,   //  3xx 06-58   Dcbus Record    
    "異常時輸出功\率  KW  "  ,  //  3xx 06-59   Power Record                                // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "異常時輸出轉矩  %   "  ,   //  3xx 06-60   Torque Record
    "異常時IGBT溫度  C   "  ,   //  3xx 06-61   IGBT Temperature Record   
    "異常時輸入端子  Hex "  ,   //  3xx 06-62   MFI State Record
    "異常時輸出端子  Hex "  ,   //  3xx 06-63   MFO State Record
    "異常時驅動器狀態Hex "  ,   //  3xx 06-64   Drive State Record
    "UCMP電流限制準位%   "  ,   //  3XX 06-65   Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
    "驅動器服務次數      "  ,   //  3xx 06-66   Service time count                          //[Service time function, Bernie, 2017/03/14]
    "驅動器服務設定      "  ,   //  3xx 06-67   Service time function Enable                //[Service time function, Bernie, 2017/03/14]
    "EPS偵測功\因準位 deg "  ,  //  3xx 06-68   EPS Detect Current    
    "EPS功\因角       deg "  ,  //  3xx 06-69   EPS Detect Current Ref
    "EPS方向輸出         "  ,   //  3xx 06-70   EPS Detect direction
    "EPS端子輸出延遲 sec "  ,   //  3xx 06-71   EPS MO Off Time
    "EPS端子閉合延遲 sec "  ,   //  3xx 06-72   EPS MO Off Time
    "永久運行方向計數H   "	,	//	3xx 06-73   Running direction count high						
    "永久運行方向計數L   "	,	//	3xx 06-74   Running direction count low
    "單次運行方向計數H   "	,	//	3xx 06-75   Temp running direction count high
    "單次運行方向計數L   "	,	//  3xx 06-76   Temp running direction count low
    "單次運行重置次數    "	,	//	3xx 06-77   Temp running reset count
    "運行方向限制次數k   "	,	//	3xx 06-78   Running life
    "運行次數功\能選項    "	,	//	3xx 06-79   Running function
    "異常2時頻率輸出  Hz  " ,   //  3xx 06-80   Fcmd Record1
    "異常2時DCBus電壓 V   " ,   //  3xx 06-81   Dcbus Record1
    "異常2時輸出電流  Amps" ,   //  3xx 06-82   Isum Record1
    "異常2時IGBT溫度  C   "	,	//  3xx 06-83   IGBT Temperature Record1
    "異常3時頻率輸出  Hz  " ,   //  3xx 06-84   Fcmd Record2
    "異常3時DCBus電壓 V   " ,   //  3xx 06-85   Dcbus Record2
    "異常3時輸出電流  Amps" ,   //  3xx 06-86   Isum Record2
    "異常3時IGBT溫度  C   " ,   //  3xx 06-87   IGBT Temperature Record2
    "異常4時頻率輸出  Hz  " ,   //  3xx 06-88   Fcmd Record3
    "異常4時DCBus電壓 V   " ,   //  3xx 06-89   Dcbus Record3
    "異常4時輸出電流  Amps" ,   //  3xx 06-90   Isum Record3
    "異常4時IGBT溫度  C   " ,   //  3xx 06-91   IGBT Temperature Record3
    "異常5時頻率輸出  Hz  " ,   //  3xx 06-92   Fcmd Record4
    "異常5時DCBus電壓 V   " ,   //  3xx 06-93   Dcbus Record4
    "異常5時輸出電流  Amps" ,   //  3xx 06-94   Isum Record4
    "異常5時IGBT溫度  C   " ,   //  3xx 06-95   IGBT Temperature Record4
    "異常6時頻率輸出  Hz  " ,   //  3xx 06-96   Fcmd Record5
    "異常6時DCBus電壓 V   " ,   //  3xx 06-97   Dcbus Record5
    "異常6時輸出電流  Amps" ,   //  3xx 06-98   Isum Record5
    "異常6時IGBT溫度  C   " ,   //  3xx 06-99   IGBT Temperature Record5

/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "煞車晶體放電位準V   "	,	//	327 07-00 SW Braking Level
    "煞車晶體遲滯電壓V   "  ,   //	328 07-01 DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "起動直流制動準位%   "	,	//	329 07-02 DCI Current Level     //[DCI Level when stop, Bernie, 05/21/2012]
    "起動直流制動時間sec "	,	//	330 07-03 DCI Time at Start 
    "停車直流制動時間sec "	,	//	331 07-04 DCI Time at STOP
    "停車制動起始頻率Hz  "	,	//	332 07-05 DCI Freq. At start
    "直流制動I增益       "	,	//	333 07-06 DCI KI
    "齒隙加速中斷時間sec "	,	//	334 07-07 Gear wait time when acceleration
    "齒隙加速中斷頻率Hz  "	,	//	335 07-08 Gear wait frequency when acceleration
    "齒隙減速中斷時間sec "	,	//	336 07-09 Gear wait time when deceleration
    "齒隙減速中斷頻率Hz  "	,	//	337 07-10 Gear wait frequency when deceleration
    "風扇控制方式        "	,	//	338 07-11 Fan Control
    "轉矩命令        %   "	,	//	339 07-12 TQC Reference from RS485
    "轉矩命令來源        "	,	//	340 07-13 Source of Torque Command
    "最大轉矩命令    %   "	,	//	341 07-14 Torque max. level
    "轉矩命令濾波時間sec "	,	//	342 07-15 Torque command filter
    "速度限制選擇        "	,	//	343 07-16 Speed Limit selection
    "轉矩模式+SPD限制%   "	,	//	344 07-17 Torque mode positive speed limit
    "轉矩模式-SPD限制%   "	,	//	345 07-18 Torque mode negative speed limit
    "轉矩命令偏壓來源    "	,	//	346 07-19 Torque offset selection
    "轉矩命令偏壓設定%   "	,	//	347 07-20 Torque offset setting level
    "高轉矩偏量      %   "	,	//	348 07-21 Torque offset setting level High
    "中轉矩偏量      %   "	,	//	349 07-22 Torque offset setting level Middle
    "低轉矩偏量      %   "	,	//	350 07-23 Torque offset setting level Low
    "正轉電動轉矩限制%   "	,	//	351 07-24 FWD Motoring Tq Limit
    "正轉回生轉矩限制%   "	,	//	352 07-25 FWD Regeneration Tq Limit
    "反轉電動轉矩限制%   "	,	//	353 07-26 REV Motoring Tq Limit
    "反轉回生轉矩限制%   "	,	//	354 07-27 REV Regeneration Tq Limit
    "強制停機檢出方式    "	,	//	355 07-28 Emergency Stop & Forced Stop selection
    "停車轉矩遞減時間sec "	,	//	356 07-29 Torque Decrease Time
    "停止直流制動準位%   "	,	//	356 07-30 STOP DC Inject Level     //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  357 07-31  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx檢測            "  ,   //  358 07-32  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx檢測距離     ppr"  ,   //  359 07-33  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx檢測秒數        "  ,   //  360 07-34  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx檢測失敗轉矩    "  ,   //  361 07-35  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx檢測最小轉矩    "  ,   //  362 07-36  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx檢測最大轉矩    "  ,   //  362 07-37  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM參數自學習        "	,	//	357 08-00   PMotor Auto-Tuning  
    "PM電機額定電流  Amps"	,	//	358 08-01   PMotor rated Current 
    "PM電機額定功\率  Kw  "	,	//	359 08-02   PMotor Rated Power           // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "PM電機額定轉速  RPM "	,	//	360 08-03   PMotor Rated RPM    
    "PM電機極數          "	,	//	361 08-04   PMotor pole No.     
    "PM電機參數 Rs   ohm "	,	//	362 08-05   PMotor Rs           
    "PM電機參數 Ld   mH  "	,	//	363 08-06   PMotor Ld           
    "PM電機參數 Lq   mH  "	,	//	364 08-07   PMotor Lq           
    "電機反電動勢    Vrms"	,	//	365 08-08   PMotor Bemf coff	
    "磁極偏移角      deg "	,	//	366 08-09   PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
    "磁極重新定位        "	,	//	367 08-10   //ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "通訊位址            "	,	//	368   09-06    Comm Address                              
    "通訊傳送速度    kbps"	,	//	369   09-07    Tranmission speed                         
    "通訊錯誤處理        "	,	//	370   09-08    Comm fault Treatment                      
    "逾時檢出時間    sec "	,	//	371   09-09    Comm Time out                             
    "通訊格式            "	,	//	372   09-10    Comm Protocol                             
    "回應延遲時間    ms  "	,	//	373   09-11    ASC remote Response Delay Time, 1=100us   
    "CAN 通訊包率        "  ,   //  3XX   09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "CAN PDO交握時間 ms  "  ,   //  3XX   09-07    CAN PDO Handshaking Period
    "CAN PDO通訊逾時 ms  "  ,   //  3XX   09-08    CAN Communiction Timeout 
    "上位機識別碼        "  ,   //  3XX   09-09 
    "FHM 暫存器          "  ,   //  3XX   09-10   
    "DLC 暫存器1         "  ,   //  3XX   09-11   
    "DLC 暫存器2         "  ,   //  3XX   09-12    
    "DLC 暫存器3         "  ,   //  3XX   09-13    
    "PDO傳送間隔     ms  "  ,   //  3XX   09-14     CAN fail rate---aevin 6/12/2017
/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"編碼器種類選擇      "	,	//	374   10-00 Encoder TYPE                             
	"編碼器脈沖點數  ppr "	,	//	375   10-01 Encoder pulses	                    
	"編碼器輸入型式      "	,	//	376   10-02 PG input setting	                
	"PG錯誤動作選擇      "	,	//	377   10-03 PG fbk fault treatment	            
	"PG錯誤檢出時間  sec "	,	//	378   10-04 PG fbk Error Detection Time	        
	"PG失速位準      %   "	,	//	379   10-05 PG fbk overspeed detection level	
	"PF失速檢出時間  sec "	,	//	380   10-06 Over speed Detection Time	        
	"PG轉差異常位準  %   "	,	//	381   10-07 PG fbk speed deviation level	    
	"PG轉差檢出時間  sec "	,	//	382   10-08 Deviation Detect Time	            
	"PG失速動作選擇      "	,	//	383   10-09 Operation at overspeed	            
	"HALL信號模式選擇    "  ,   //  384   10-10 Hall Input Types
	"起動零速增益P       "	,	//	385   10-11 KP gain of ASR in Zero speed	
	"起動零速積分I   sec "	,	//	386   10-12 Ki gain of ASR in Zero speed	
	"低速增益P           "	,	//	387   10-13 ASR P Gain 1	                
	"低速積分時間I   sec "	,	//	388   10-14 ASR I Gain 1	                
	"高速增益P           "	,	//	389   10-15 ASR P Gain 2	                
	"高速積分時間I   sec "	,	//	390   10-16 ASR I Gain 2	                
	"低/高速切換頻率 Hz  "	,	//	391   10-17 ASR1/ASR2 switch freq	        
	"ASR低通濾波增益 sec "	,	//	392   10-18 Primary LowPass filter Gain 
	"位置控制ASR增益P    "  ,	//	393   10-19 position control Kp Gain  
    "零/低速寬度調整 Hz  "  ,   //  394   10-20 Low Spd band
    "低/高速寬度調整 Hz  "  ,   //  395   10-21 High Spd band
	"位置控制ASR積分Isec "	,	//	396   10-22 Position control time
	"起動位置控制低通sec "	,	//	397   10-23 Position control LOW POSS FILTER
	"位置控制模式選擇    "	,	//	398   10-24 Source of position control, add by dino, 06/30/2008
	"平層零速增益P   %   "	,	//	399   10-25 KP gain of ASR in Zero speed of Landing
	"平層零速積分I   sec "	,	//	400   10-26 Ki gain of ASR in Zero speed of Landing
	"位置控制零速增益%   "	,	//	385   10-27 KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"位置控制零速積分sec "	,	//	386   10-28 Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
    "PG卡除頻輸出值      "	,   //  4xx   10-29 PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG卡除頻輸出型式    "	,   //  4xx   10-30 PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C-選擇        "  ,   //  110   10-31 RESERVED    //[change parameter to normal group, Bernie, 2014/02/14]
    "電梯過加速度準位m/s2"  ,   //  3XX   10-32 Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "過加速度偵測時間sec "  ,   //  3XX   10-33     Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "過加速度偵選擇      "  ,   //  3XX   10-34     Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "系統控制        Hex "	,	//	401   11-00     system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "最大頻率對應梯速m/s "  ,   //  402   11-01     Lift operation speed                                        
    "曳引輪直徑      mm  "  ,   //  403   11-02     SHEAVE diameter			ADDED BY SCOTTY                     
    "齒輪比              "  ,   //  404   11-03     Gear Ratio                                              
    "懸掛比              "  ,   //  405   11-04     Suspension ratio	                                        
    "機械慣量百分比  %   "  ,   //  406   11-05     inertia	percent			ADDED BY SCOTTY                     
    "起動零速頻寬    Hz  "	,	//	407   11-06     Zero Speed Loop BandWidth	                                
    "低速頻寬        Hz  "	,	//	408   11-07     Speed Loop BandWidth1		                                
    "高速頻寬        Hz  "	,	//	409   11-08     Speed Loop BandWidth2		                                
    "PDFF增益值      %   "	,	//	410   11-09     PDFFKr		                                                
    "速度控制前饋增益%   "	,	//	411   11-10     SPEED FFD GAIN			ADDED BY SCOTTY                     
    "凹陷濾波深度    db  "	,	//	412   11-11     Netch filter deep(db)	                                    
    "凹陷濾波頻率    Hz  "	,	//	413   11-12     Netch filter frequency	                                    
    "面板顯示濾波時間sec "	,	//	414   11-13     Low Pass Filter for display	                                
    "加速時最大電流  %   "	,	//	415   11-14     ACC Max current                                             
    "電梯最大加速度  m/s2"  ,	//	416   11-15     max meter/sec	                                            
    "監控資料位址    Hex "  ,   //	417   11-16     Display address,add by dino 2007/03/08                      
    "監控資料            "  ,	//	418   11-17     Display data,   add by dino 2007/03/08                      
    "保留                "  ,   //  419   11-18     Protect Bit	                                                
    "停車零速頻寬    Hz  "	,	//	420   11-19     Zero Speed Loop BandWidth of Landing
    "PWM 模式選擇        "  ,   //  4XX   11-20     PWM mode selection  //[move parameter to 11-20, Bernie, 2017/02/16]
    "LC01顯示濾波時間 sec"	,	//	422   11-21	    Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	420   11-21     Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22       //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "自訂參數 1          "  ,   //  421   12-00
    "自訂參數 2          "  ,   //  422   12-01
    "自訂參數 3          "  ,   //  423   12-02
    "自訂參數 4          "  ,   //  424   12-33
    "自訂參數 5          "  ,   //  425   12-04
    "自訂參數 6          "  ,   //  426   12-05
    "自訂參數 7          "  ,   //  427   12-06
    "自訂參數 8          "  ,   //  428   12-07
    "自訂參數 9          "  ,   //  429   12-08
    "自訂參數 10         "  ,   //  430   12-09
    "自訂參數 11         "  ,   //  431   12-10
    "自訂參數 12         "  ,   //  432   12-11
    "自訂參數 13         "  ,   //  433   12-12
    "自訂參數 14         "  ,   //  434   12-13
    "自訂參數 15         "  ,   //  435   12-14
    "自訂參數 16         "  ,   //  436   12-15
    "自訂參數 17         "  ,   //  437   12-16
    "自訂參數 18         "  ,   //  438   12-17
    "自訂參數 19         "  ,   //  439   12-18
    "自訂參數 20         "  ,   //  440   12-19
    "自訂參數 21         "  ,   //  441   12-20
    "自訂參數 22         "  ,   //  442   12-21
    "自訂參數 23         "  ,   //  443   12-22
    "自訂參數 24         "  ,   //  444   12-23
    "自訂參數 25         "  ,   //  445   12-24
    "自訂參數 26         "  ,   //  446   12-25
    "自訂參數 27         "  ,   //  447   12-26
    "自訂參數 28         "  ,   //  448   12-27
    "自訂參數 29         "  ,   //  449   12-28
    "自訂參數 30         "  ,   //  450   12-29
    "自訂參數 31         "  ,   //  451   12-30
    "自訂參數 32         "  ,   //  452   12-31
    "自訂參數 33         "  ,   //  433   12-12
    "自訂參數 34         "  ,   //  434   12-13
    "自訂參數 35         "  ,   //  435   12-14
    "自訂參數 36         "  ,   //  436   12-15
    "自訂參數 37         "  ,   //  437   12-16
    "自訂參數 38         "  ,   //  438   12-17
    "自訂參數 39         "  ,   //  439   12-18
    "自訂參數 40         "  ,   //  430   12-09
    "自訂參數 41         "  ,   //  431   12-10
    "自訂參數 42         "  ,   //  432   12-11
    "自訂參數 43         "  ,   //  433   12-12
    "自訂參數 44         "  ,   //  434   12-13
    "自訂參數 45         "  ,   //  435   12-14
    "自訂參數 46         "  ,   //  436   12-15
    "自訂參數 47         "  ,   //  437   12-16
    "自訂參數 48         "  ,   //  438   12-17
    "自訂參數 49         "  ,   //  439   12-18
    "自訂參數 50         "  ,   //  430   12-09
    "保留                "  ,   //  431   12-10
    "保留                "  ,   //  432   12-11
    "保留                "  ,   //  433   12-12
    "保留                "  ,   //  434   12-13
    "保留                "  ,   //  435   12-14
    "保留                "  ,   //  436   12-15
    "保留                "  ,   //  437   12-16
    "保留                "  ,   //  438   12-17
    "保留                "  ,   //  439   12-18
    "保留                "  ,   //  430   12-09
    "保留                "  ,   //  431   12-10
    "保留                "  ,   //  432   12-11
    "保留                "  ,   //  433   12-12
    "保留                "  ,   //  434   12-13
    "保留                "  ,   //  435   12-14
    "保留                "  ,   //  436   12-15
    "保留                "  ,   //  437   12-16
    "保留                "  ,   //  438   12-17
    "保留                "  ,   //  439   12-18
    "保留                "  ,   //  430   12-09
    "保留                "  ,   //  431   12-10
    "保留                "  ,   //  432   12-11
    "保留                "  ,   //  433   12-12
    "保留                "  ,   //  434   12-13
    "保留                "  ,   //  435   12-14
    "保留                "  ,   //  436   12-15
    "保留                "  ,   //  437   12-16
    "保留                "  ,   //  438   12-17
    "保留                "  ,   //  439   12-18
    "保留                "  ,   //  430   12-09
    "保留                "  ,   //  431   12-10
    "保留                "  ,   //  432   12-11
    "保留                "  ,   //  433   12-12
    "保留                "  ,   //  434   12-13
    "保留                "  ,   //  435   12-14
    "保留                "  ,   //  436   12-15
    "保留                "  ,   //  437   12-16
    "保留                "  ,   //  438   12-17
    "保留                "  ,   //  439   12-18
    "保留                "  ,   //  430   12-09
    "保留                "  ,   //  431   12-10
    "保留                "  ,   //  432   12-11
    "保留                "  ,   //  433   12-12
    "保留                "  ,   //  434   12-13
    "保留                "  ,   //  435   12-14
    "保留                "  ,   //  436   12-15
    "保留                "  ,   //  437   12-16
    "保留                "  ,   //  438   12-17
    "保留                "  ,   //  439   12-18
    "保留                "  ,   //  439   12-18

/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "自定常用參數 1      "  ,   //  453   13-00
    "自定常用參數 2      "  ,   //  454   13-01
    "自定常用參數 3      "  ,   //  455   13-02
    "自定常用參數 4      "  ,   //  456   13-33
    "自定常用參數 5      "  ,   //  457   13-04
    "自定常用參數 6      "  ,   //  458   13-05
    "自定常用參數 7      "  ,   //  459   13-06
    "自定常用參數 8      "  ,   //  460   13-07
    "自定常用參數 9      "  ,   //  461   13-08
    "自定常用參數 10     "  ,   //  462   13-09
    "自定常用參數 11     "  ,   //  463   13-10
    "自定常用參數 12     "  ,   //  464   13-11
    "自定常用參數 13     "  ,   //  465   13-12
    "自定常用參數 14     "  ,   //  466   13-13
    "自定常用參數 15     "  ,   //  467   13-14
    "自定常用參數 16     "  ,   //  468   13-15
    "自定常用參數 17     "  ,   //  469   13-16
    "自定常用參數 18     "  ,   //  470   13-17
    "自定常用參數 19     "  ,   //  471   13-18
    "自定常用參數 20     "  ,   //  472   13-19
    "自定常用參數 21     "  ,   //  473   13-20
    "自定常用參數 22     "  ,   //  474   13-21
    "自定常用參數 23     "  ,   //  475   13-22
    "自定常用參數 24     "  ,   //  476   13-23
    "自定常用參數 25     "  ,   //  477   13-24
    "自定常用參數 26     "  ,   //  478   13-25
    "自定常用參數 27     "  ,   //  479   13-26
    "自定常用參數 28     "  ,   //  480   13-27
    "自定常用參數 29     "  ,   //  481   13-28
    "自定常用參數 30     "  ,   //  482   13-29
    "自定常用參數 31     "  ,   //  483   13-30
    "自定常用參數 32     "  ,   //  484   13-31
    "自定常用參數 33     "  ,   //  455   13-02
    "自定常用參數 34     "  ,   //  456   13-33
    "自定常用參數 35     "  ,   //  457   13-04
    "自定常用參數 36     "  ,   //  458   13-05
    "自定常用參數 37     "  ,   //  459   13-06
    "自定常用參數 38     "  ,   //  460   13-07
    "自定常用參數 39     "  ,   //  461   13-08
    "自定常用參數 40     "  ,   //  462   13-09
    "自定常用參數 41     "  ,   //  463   13-10
    "自定常用參數 42     "  ,   //  464   13-11
    "自定常用參數 43     "  ,   //  465   13-12
    "自定常用參數 44     "  ,   //  466   13-13
    "自定常用參數 45     "  ,   //  467   13-14
    "自定常用參數 46     "  ,   //  468   13-15
    "自定常用參數 47     "  ,   //  469   13-16
    "自定常用參數 48     "  ,   //  470   13-17
    "自定常用參數 49     "  ,   //  471   13-18
    "自定常用參數 50     "  ,   //  462   13-09
    "自定常用參數 51     "  ,   //  463   13-10
    "自定常用參數 52     "  ,   //  464   13-11
    "自定常用參數 53     "  ,   //  465   13-12
    "自定常用參數 54     "  ,   //  466   13-13
    "自定常用參數 55     "  ,   //  467   13-14
    "自定常用參數 56     "  ,   //  468   13-15
    "自定常用參數 57     "  ,   //  469   13-16
    "自定常用參數 58     "  ,   //  470   13-17
    "自定常用參數 59     "  ,   //  471   13-18
    "自定常用參數 60     "  ,   //  462   13-09
    "自定常用參數 61     "  ,   //  463   13-10
    "自定常用參數 62     "  ,   //  464   13-11
    "自定常用參數 63     "  ,   //  465   13-12
    "自定常用參數 64     "  ,   //  466   13-13
    "自定常用參數 65     "  ,   //  467   13-14
    "自定常用參數 66     "  ,   //  468   13-15
    "自定常用參數 67     "  ,   //  469   13-16
    "自定常用參數 68     "  ,   //  470   13-17
    "自定常用參數 69     "  ,   //  471   13-18
    "自定常用參數 70     "  ,   //  462   13-09
    "自定常用參數 71     "  ,   //  463   13-10
    "自定常用參數 72     "  ,   //  464   13-11
    "自定常用參數 73     "  ,   //  465   13-12
    "自定常用參數 74     "  ,   //  466   13-13
    "自定常用參數 75     "  ,   //  467   13-14
    "自定常用參數 76     "  ,   //  468   13-15
    "自定常用參數 77     "  ,   //  469   13-16
    "自定常用參數 78     "  ,   //  470   13-17
    "自定常用參數 79     "  ,   //  471   13-18
    "自定常用參數 80     "  ,   //  462   13-09
    "自定常用參數 81     "  ,   //  463   13-10
    "自定常用參數 82     "  ,   //  464   13-11
    "自定常用參數 83     "  ,   //  465   13-12
    "自定常用參數 84     "  ,   //  466   13-13
    "自定常用參數 85     "  ,   //  467   13-14
    "自定常用參數 86     "  ,   //  468   13-15
    "自定常用參數 87     "  ,   //  469   13-16
    "自定常用參數 88     "  ,   //  470   13-17
    "自定常用參數 89     "  ,   //  471   13-18
    "自定常用參數 90     "  ,   //  462   13-09
    "自定常用參數 91     "  ,   //  463   13-10
    "自定常用參數 92     "  ,   //  464   13-11
    "自定常用參數 93     "  ,   //  465   13-12
    "自定常用參數 94     "  ,   //  466   13-13
    "自定常用參數 95     "  ,   //  467   13-14
    "自定常用參數 96     "  ,   //  468   13-15
    "自定常用參數 97     "  ,   //  469   13-16
    "自定常用參數 98     "  ,   //  470   13-17
    "自定常用參數 99     "  ,   //  471   13-18
    "自定常用參數 100    "  ,   //  471   13-18
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level%   "	,	//	485   14-00	Ids Power Save Level
	"VF CURVE MODE       "	,	//	486   14-01	VF voltage mode selection
	"Overload 1 Mode     "	,	//	487   14-02	Constant Torque Selection
	"Auto ACC/DEC        "	,	//	488   14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	489   14-04	Unit of Acc/Dec time
	"POWER SAVE MODE     "	,	//	490   14-05	Power Save mode
	"Stop Methods        "	,	//	491   14-06	Stop Methods
	"Reverse Operate     "	,	//	492   14-07	Reverse Operation
	"Skip Freq. 1UP  Hz  "	,	//	493   14-08	Skip Freq. Point 1 upper limit
	"Skip Freq. 1LOW Hz  "	,	//	494   14-09	Skip Freq. Point 1 lower limit
	"Skip Freq. 2UP  Hz  "	,	//	495   14-10	Skip Freq. Point 2 upper limit
	"Skip Freq. 2LOW Hz  "	,	//	496   14-11	Skip Freq. Point 2 lower limit
	"Skip Freq. 3UP  Hz  "	,	//	497   14-12	Skip Freq. Point 3 upper limit
	"Skip Freq. 3LOW Hz  "	,	//	498   14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz  "	,	//	499   14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//	500   14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//	501   14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//	502   14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//	503   14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//	504   14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2  Hz  "	,	//	505   14-20	Min Output Freq. 2
	"Min Out-Volt 2  V   "	,	//	506   14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//	507   14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//	508   14-23	up/down key speed
	"Counter Set         "	,	//	509   14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//	510   14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//	511   14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"Multi-Fun Input9    "	,	//	512   14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//	513   14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//	514   14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//	515   14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//	516   14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//	517   14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//	518   14-33	External Terminal Run after Fault Reset
	"ACI/AVI2 SEL        "	,	//	519   14-34	ACI change to AVI2
	"Addition of AI      "	,	//	520   14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//	521   14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//	522   14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//	523   14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//	524   14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//	525   14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//	526   14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//	527   14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//	528   14-43	Multi-Position Point 8
	"Multi-Posit 9       "	,	//	529   14-44	Multi-Position Point 9
	"Multi-Posit 10      "	,	//	530   14-45	Multi-Position Point 10
	"Multi-Posit 11      "	,	//	531   14-46	Multi-Position Point 11
	"Multi-Posit 12      "	,	//	532   14-47	Multi-Position Point 12
	"Multi-Posit 13      "	,	//	533   14-48	Multi-Position Point 13
	"Multi-Posit 14      "	,	//	534   14-49	Multi-Position Point 14
	"Multi-Posit 15      "	,	//	535   14-50	Multi-Position Point 15
	"MOTOR 1 OR 2        "	,	//	536   14-51	Motor Selection 1 or 2
	"Y-D Switch Hz   Hz  "	,	//	537   14-52	Y-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//	538   14-53	Y-Delta switched Enable
	"Motor2 Rated    Amps"	,	//	539   14-54	Motor 2 rated Current
	"Motor2 Rated P  Kw  "	,	//	540   14-55	Motor 2 Rated Power
	"Motor2 Rated    RPM "	,	//	541   14-56	Motor 2 Rated RPM
	"Motor2 Poles        "	,	//	542   14-57	Motor 2 pole No.
	"Motor2 No-Load  Amps"	,	//	543   14-58	Motor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	544   14-59	Motor 2 Rs
	"Motor2 Rr       ohm "	,	//	545   14-60	Motor 2 Rr
	"Motor2 Lm       mH  "	,	//	546   14-61	Motor 2 Lm
	"Motor2 Lx       mH  "	,	//	547   14-62	Motor 2 Lx
	"Y-D On Delay T      "	,	//	548   14-63	Y-Delta On delay time
	"OV stall level  V   "	,	//	549   14-64	OV stall level
	"Thermal RLY2 SEL    "	,	//	550   14-65	Thermal Relay 2 Selection
	"Thermal RLY2 T      "	,	//	551   14-66	Thermal Relay 2 Time
	"Momentary Power     "	,	//	552   14-67	Momentary Power Loss
	"Power Loss Time sec "	,	//	553   14-68	Max. allowable PL time
	"Base Block Time sec "	,	//	554   14-69	BB Time for speed serach
	"SPD Search Curr %   "	,	//	555   14-70	Current level for SPD serach
	"BB Treatment        "	,	//	556   14-71	bb treatment for oc, ov, bb
	"Auto Restart        "	,	//	557   14-72	Auto restart after fault
	"Restart Method      "	,	//	558   14-73	Auto restart Speed serach method
	"DEB Decel SEL       "	,	//	559   14-74	Deceleration at Momertary Power loss 
	"DEB Return Time     "	,	//	560   14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561   14-76	PID feedback selection	
	"P Gain of PID       "	,	//	562   14-77	P gain of PID	
	"I Gain of PID   sec "	,	//	563   14-78	I gain of PID	
	"D Gain of PID       "	,	//	564   14-79	D gain of PID	
	"Up Limit for I  %   "	,	//	565   14-80	Upper bound for integral	
	"PID Out-Limiter %   "	,	//	566   14-81	PID output Freq. Limit	
	"PID Offset      %   "	,	//	567   14-82	PID offset	
	"PID Out-Filter  sec "	,	//	568   14-83	Derivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	569   14-84	Feedback signal detection time	
	"PID Fdb Loss        "	,	//	570   14-85	PID feedback loss	
	"SLEEP FREQ          "	,	//	571   14-86	Sleep Frequency	
	"WAKE FREQ           "	,	//	572   14-87	Wake up Frequency	
	"SLEEP TIME          "	,	//	573   14-88	Sleep Time	
	"PID DEV. LEVEL  %   "	,	//	574   14-89	PID Deviation Level	
	"PID DEV. TIME       "	,	//	575   14-90	PID Deviation Time	
	"PID Fbk Filter  sec "	,	//	576   14-91	PID feedback filter	
	"Comm Main Freq. Hz  "	,	//	577   14-92	Main Frequency from communication	
	"Block Trans. 1      "	,	//	578   14-93	Block Transfer 1	
	"Block Trans. 2      "	,	//	579   14-94	Block Transfer 2	
	"Block Trans. 3      "	,	//	580   14-95	Block Transfer 3
	"Block Trans. 4      "	,	//	581   14-96	Block Transfer 4
	"Block Trans. 5      "	,	//	582   14-97	Block Transfer 5
	"Block Trans. 6      "	,	//	583   14-98	Block Transfer 6
	"Block Trans. 7      "	,	//	584   14-99	Block Transfer 7
	"Block Trans. 8      "	,	//	585   14-100 Block Transfer 8
	"Block Trans. 9      "	,	//	586   14-101 Block Transfer 9
	"Block Trans. 10     "	,	//	587   14-102 Block Transfer 10
	"WEAKLPF             "	,	//	588   14-103 WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	589   14-104 WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	590   14-105 OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"PG Position Home    "	,	//	591   14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592   14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	593   14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	594   14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	595   14-110 FMax Target by Vcommand Position
	"RESERVE             "	,	//	596   14-111 Accel. Time for Position
	"PG Mech. Gear A     "	,	//	597   14-112 PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	598   14-113 PG Mechanical Gear B
	"System Jm       PU  "	,	//	599   14-114 Interia of motor PU
	"M1IdsRef Limit   %  "	,	//	600   14-115 Motor1 IdsRef Limit
	"M2IdsRef Limit   %  "	,	//	601   14-116 Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	602   14-117 Phase Loss Time
	"TH Inside Temp   C  "	,	//	603   14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	604   14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	605   14-120 SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//	606   14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607   14-122 Tension of Torque Control
	"DIAMETER        m   "	,	//	608   14-123 Diameter of Material
	"DEPTH           cm  "	,	//	609   14-124 Depth of meterial
	"RESERVE             "	,	//	610   14-125 Reserve
	"ABZ ST Times        "	,	//	611   14-126 Reserve
	"ABZ ST Duty         "	,	//	612   14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	613   14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	614   14-129 Time of APR Curve
    "Jm source           "  ,   //	615   14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	616   14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	617   14-132 muti input state
    "StandStill Curr.Amps"  ,   //  618   14-133 Standstill Current
	"PG Scale Factor     "	,	//	619   14-134 Division factor of PG	
	"OLD Irate           "	,	//	619   14-135 OLD Irate       // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time  sec "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"COM1通訊位址        "	,	//	368   09-00 Comm Address             //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                        
    "COM1通訊傳送速度kbps"	,	//	369   09-01 Tranmission speed                         
    "COM1通訊錯誤處理    "	,	//	370   09-02 Comm fault Treatment                      
    "COM1逾時檢出時間sec "	,	//	371   09-03 Comm Time out                             
    "COM1通訊格式        "	,	//	372   09-04 Comm Protocol                             
    "COM1回應延遲時間ms  "	,	//	373   09-05 ASC remote Response Delay Time, 1=100us     
    "OPHL 10Hz COUNT     "  ,   //  3XX   14-146    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "  ,   //  3XX   14-147    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "  ,   //  3XX   14-148    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "  ,   //  3XX   14-149    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 3       "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_SC
const string20 prinfo_sc_ACC_ms2[11] = { //[Sibocom S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"菴珨樓厒奀潔    m/s2"	,	//	156	01-12	1st Acceleration time
	"菴珨熬厒奀潔    m/s2"	,	//	157	01-13	1st Deceleration time
	"菴媼樓厒奀潔    m/s2"	,	//	158	01-14	2nd Acceleration time
	"菴媼熬厒奀潔    m/s2"	,	//	159	01-15	2nd Deceleration time
	"菴��樓厒奀潔    m/s2"	,	//	160	01-16	3rd Acceleration time
	"菴��熬厒奀潔    m/s2"	,	//	161	01-17	3rd Deceleration time
	"菴侐樓厒奀潔    m/s2"	,	//	162	01-18	4th Acceleration time
	"菴侐熬厒奀潔    m/s2"	,	//	163	01-19	4th Deceleration time
	"渡雄樓厒奀潔    m/s2"	,	//	164	01-20	JOG Acceleration time
	"渡雄熬厒奀潔    m/s2"	,	//	165	01-21	JOG Deceleration time
	"礿陬熬厒奀潔    m/s2"
};

const string20 prinfo_sc_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"菴珨樓厒奀潔    f/s2"	,	//	156	01-12	1st Acceleration time
	"菴珨熬厒奀潔    f/s2"	,	//	157	01-13	1st Deceleration time
	"菴媼樓厒奀潔    f/s2"	,	//	158	01-14	2nd Acceleration time
	"菴媼熬厒奀潔    f/s2"	,	//	159	01-15	2nd Deceleration time
	"菴��樓厒奀潔    f/s2"	,	//	160	01-16	3rd Acceleration time
	"菴��熬厒奀潔    f/s2"	,	//	161	01-17	3rd Deceleration time
	"菴侐樓厒奀潔    f/s2"	,	//	162	01-18	4th Acceleration time
	"菴侐熬厒奀潔    f/s2"	,	//	163	01-19	4th Deceleration time
	"渡雄樓厒奀潔    f/s2"	,	//	164	01-20	JOG Acceleration time
	"渡雄熬厒奀潔    f/s2"	,	//	165	01-21	JOG Deceleration time
	"礿陬熬厒奀潔    f/s2"
};

const string20 prinfo_sc_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"樓厒羲宎S1奀潔  m/s3"	,	//	168	01-24	S curve Accel time 1
	"樓厒羲宎S2奀潔  m/s3"	,	//	169	01-25	S curve Accel time 2
	"樓厒羲宎S3奀潔  m/s3"	,	//	170	01-26	S curve Decel time 1
	"樓厒羲宎S4奀潔  m/s3"	,	//	171	01-27	S curve Decel time 2
	"樓厒羲宎S5奀潔  m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_sc_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"樓厒羲宎S1奀潔  f/s3"	,	//	168	01-24	S curve Accel time 1
	"樓厒羲宎S2奀潔  f/s3"	,	//	169	01-25	S curve Accel time 2
	"樓厒羲宎S3奀潔  f/s3"	,	//	170	01-26	S curve Decel time 1
	"樓厒羲宎S4奀潔  f/s3"	,	//	171	01-27	S curve Decel time 2
	"樓厒羲宎S5奀潔  f/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_sc[EPMAX] = {	
/*---- GROUP 15---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"DEBUG FLAG          "	,	//	0   15-00	Debug Flag 1	                                
	"DBC Change Freq.    "	,	//	1   15-01	DBC CHANGE FREQ	                                
	"EFFICIENCY      %   "	,	//	2   15-02	efficiency of Motor	                            
    "ZOffset Tune I  %   "  ,   //  3   15-03   Z Phase search current level                    
	"RATED-I AD VALUE    "	,	//	4   15-04	AD value at Rated Current	                    
	"Ide Iqe LPF Gain    "	,	//	5   15-05	Id*,Iq* LPF	                                    
	"Factory Serial 1    "	,	//	6   15-06	Only for Factory 1	                            
	"Factory Serial 2    "	,	//	7   15-07	Only for Factory 2	                            
	"Factory Serial 3    "	,	//	8   15-08	Only for Factory 3	                            
	"Factory Serial 4    "	,	//	9   15-09	Only for Factory 4	                            
	"REVERSED            "	,	//	10  15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]                
	"Skip DeadTime       "	,	//	11  15-11	Skip Dead Time	                                
	"210.0 VDC AD        "	,	//	12  15-12	DCBUS 210.0 VDC ad value	                    
	"310.0 VDC AD        "	,	//	13  15-13	DCBUS 310.0 VDC ad value	                    
	"390.0 VDC AD        "	,	//	14  15-14	DCBUS 390.0 VDC ad value	                    
	"TRQ_P               "	,	//	15  15-15	Torque control Kp	                            
	"TRQ_I               "	,	//	16  15-16	Torque Control Ki	                            
	"FLUX_P              "	,	//	17  15-17	Flux Control Kp	                                
	"FLUX_I              "	,	//	18  15-18	Flux Control Ki	                                
	"SpdSlop_P           "	,	//	19  15-19	Speed slop Control Kp gain	                    
	"SpdSlop_I           "	,	//	20  15-20	Speed slop Control Ki gain	                    
	"Control Select      "	,	//	21  15-21	Control Selection	                            
	"TEST SOURCE Amp.    "	,	//	22  15-22	Test Source Value Amplitude	                    
	"High Speed LPG  Hz  "	,	//	23  15-23	High Speed Low pass Filter Gain	                
	"Low Speed LPG   Hz  "	,	//	24  15-24	Low Speed Low pass filter Gain	                
	"TEST SOURCE Bias    "	,	//	25  15-25	Test Source Value Bias	                        
	"Est J LPG       s   "	,	//	26  15-26	Estimate J Low pass Filter Gain	                
	"Calibration A RE    "	,	//	27  15-27	Calibration current REF	                        
	"Calibration P       "	,	//	28  15-28	Calibration P	                                
	"Calibration I       "	,	//	29  15-29	Calibration I	                                
	"DC-Tun current P    "	,	//	30  15-30	Auto tuning DC test Kp gain	                    
	"DC-Tun current I    "	,	//	31  15-31	Auto Tuning DC test Ki gain	                    
	"High Freq. Tun P    "	,	//	32  15-32	Auto tuning High Freq. Lock test Kp gain	    
	"High Freq. Tun I    "	,	//	33  15-33	ADcbus Low Pass Gain	                        
	"Gain of VcmpMax %   "	,	//	34  15-34	Select Zero Speed	                            
	"NL-Boost Gain       "	,	//	35  15-35	No Load Boost Gain	                            
	"Auto Accel. KP      "	,	//	36  15-36	Acceleration AKP	                            
	"Auto Accel. KI      "	,	//	37  15-37	Acceleration AKI	                            
	"Current Loop BW     "	,	//	38  15-38	Current Loop BandWidth                          
	"DBC Leading 2       "	,	//	39  15-39	DBC Leading 2                                   
	"DBC Ration 2        "	,	//	40  15-40	DBC Ratio 2 with close loop                     
	"DBC Coef.           "	,	//	41  15-41	DBC Coef.                                       
	"DBC Dcbus Coef.     "	,	//	42  15-42	DBC Dcbus Coef.                                 
	"DBC Leading 1       "	,	//	43  15-43	DBC leading 1                                   
	"DBC Ratio 1         "	,	//	44  15-44	DBC Linear Ratio 1                              
	"RESERVE             "	,	//	45  15-45	DBC MODE                                        
	"Magnitization L1    "	,	//	46  15-46	magnitization inductance 1                      
	"Main Flux Link 1    "	,	//	47  15-47	main flux linkage 1                             
	"Magnitization L2    "	,	//	48  15-48	magnitization inductance 2                      
	"Main Flux Link 2    "	,	//	49  15-49	main flux linkage 2                             
	"Magnitization L3    "	,	//	50  15-50	magnitization inductance 3                      
	"Main Flux Link 3    "	,	//	51  15-51	main flux linkage 3                             
	"Magnitization L4    "	,	//	52  15-52	magnitization inductance 4                      
	"Main Flux Link 4    "	,	//	53  15-53	main flux linkage 4                             
	"Magnitization L5    "	,	//	54  15-54	magnitization inductance 5                      
	"Main Flux Link 5    "	,	//	55  15-55	main flux linkage 5                             
	"Magnitization L6    "	,	//	56  15-56	magnitization inductance 6                      
	"Main Flux Link 6    "	,	//	57  15-57	main flux linkage 6                             
	"Modulation Index    "	,	//	58  15-58	Modulation Index                                
	"Zero Current LPG    "	,	//	59  15-59	Current Zero Low Pass Gain                      
	"COSphi LPF      ms  "	,	//	60  15-60	cos(TB1_uwPhi) low pass gain                          
	"Date Code Y.WKD     "  ,   //  61  15-61   DateCode  //Datecode para change, Henry, 2016/07/20 
	"AUI2 0V ADC     adc "	,	//	62  15-62	calibration for AUI ZeroPoint (0V)
	"AUI2 -10V ADC   adc "	,	//	63  15-63	calibration for AUI2 max (-10V)
	"AUI2 +10V ADC   adc "	,	//	64  15-64	calibration for AUI2 min (+10V)
	"ACI 20mA ADC    adc "	,	//	65  15-65	calibration for ACI2 max (20mA)                 
	"ACI 12mA ADC    adc "	,	//	66  15-66	calibration for ACI mid (12mA)                  
	"ACI 4mA ADC     adc "	,	//	67  15-67	calibration for ACI min (4mA)                   
	"AUI1 0V ADC     adc "	,	//	68  15-68	calibration for AUI1 ZeroPoint (0V)
	"AUI1 -10V ADC   adc "	,	//	69  15-69	calibration for AUI1 max (-10V)
	"AUI1 +10V ADC   adc "	,	//	70  15-70	calibration for AUI1 min (+10V)
	"Auto Decel. DKP     "	,	//	71  15-71	Deceleration DKP                                
	"Auto Decel. DKI     "	,	//	72  15-72	Deceleration DKI                                
	"Low Speed Comp. Hz  "	,	//	73  15-73	more volt. comp. below this freq.               
	"PGLOSS Detcect T    "	,	//	74  15-74	PGLOSS Detect Counter                           
	"Main Frequency      "	,	//	75  15-75	Main Frequency                                  
	"Power On Counter    "	,	//	76  15-76	Power On Counter                                
	"GFF_Pk Detec SW     "	,	//	77  15-77	GFF Maximum Value Record Switch, Jerry Yu, 2019/11/11 
	"BLD Version         "	,	//	78  15-78   //[BootLoader Version, Special.Kung, 2022/10/31] 
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"SIBO EPS FRMODE     "  ,   //  89  15-79 SIBO EPS FRMODE
#else
    "RESERVE             "  ,   //  79  15-80
#endif
    "OPHL_SPER           "  ,   //  80
    "OPHL_CURER          "  ,   //  81
    "OPHL_ERCNT          "  ,   //  82                                 
	"BLD DateCode        "  ,   //  83  15-83   //[BootLoader DataCode, Special.Kung, 2022/10/31] 
	"FineAUI 0V ADC  adc "	,	//	84  15-84	calibration for AUI ZeroPoint (0V)              
	"FineAUI +2V ADC adc "	,	//	85  15-85	calibration for AUI max (+2V)                   
	"FineAUI -2V ADC adc "	,	//	86  15-86	calibration for AUI min (-2V)                   
	"SIN MAX V ADC   adc "	,	//	87  15-87	calibration for SIN max, add by dino, 06/01/2007
	"SIN MIN V ADC   adc "	,	//	88  15-88	calibration for SIN min, add by dino, 06/01/2007
	"COS MAX V ADC   adc "	,	//	89  15-89	calibration for COS max, add by dino, 06/01/2007
	"COS MIN V ADC   adc "	,	//	90  15-90	calibration for COS min, add by dino, 06/01/2007
    "Min. Pulse Width    "  ,   //  91  15-91   minimum pulse, ADDED BY SCOTTY,2007/07/11
	"D Frame FAN Cont    "	,	//	92 	15-92	D Frame Fan control
	"Z Phase UVW Sect    "	,	//	93 	15-93	Z phase UVW Section when PG_TYPE = 2
    "RESERVE             "  ,   //  94  15-94
    "LAST PG COUNTER     "  ,   //  95  15-95   PG Position Record, add by scotty, 12/07/2007
	"AFM MAX. Value      "	,	//	96 	15-96   AFM max. value
	"AFM MIN. Value      "	,	//	97 	15-97   AFM min. value
	"Soft Start Time sec "	,	//	98  15-98	Softstart Delay Time
	"DEBUG FLAG2         "  ,   //  99  15-99   //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
	"Z-cab Mode          "  ,   //  100 15-100
	"Qer_min             "  ,   //  101 15-101
	"Qer_Shift           "  ,   //  102 15-102
	"Sin_HS_Tab          "  ,   //  103 15-103
	"                    "  ,   //  104 15-104
	"RESERVE             "	,	//	105 15-105  RESERVED
	"CAN Control         "	,	//	106 15-106  Can Control      //[CAN Control, Sampo, 09/15/2010]
	"CAN Fault Handle    "	,	//	107 15-107  Can Fault Handle //[CAN Control, Sampo, 09/15/2010]
	"DEBUG_PG            "	,	//	108 15-108  DEBUG_PG
	"_47th_DISP          "	,	//	109 15-109  _47th_DISP
	"PG_MODE             "	,	//	110 15-110  RESERVED
	"WDT Divider         "	,	//	111 15-111  WDT_DIV     //[ICT WDT test, Bernie, 08/16/2011]
	"AFM1 +10V CNT       "	,	//	112 15-112  AFM1_P10CNT for AFM1 +10V output
	"AFM1 0V CNT         "	,	//	113 15-113  AFM1_0CNT for AFM1 0V output
	"AFM1 -10V CNT       "	,	//	114 15-114  AFM1_M10CNT for AFM1 -10V output
	"AFM2 +10V CNT       "	,	//	115 15-115  AFM2_P10CNT for AFM2 +10V output
	"AFM2 0V CNT         "	,	//	116 15-116  AFM2_0CNT for AFM2 0V output
	"AFM2 -10V CNT       "	,	//	117 15-117  AFM2_M10CNT for AFM2 -10V output
	"Protect Bit SW      "	,	//	118 15-118  The switch of Protect finction          //[The switch of Protect finction, Bernie, 2015/05/21]
	"OPHL COUNT          "	,	//	119 15-119  The Count of Protect finction           //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL IRMS           "	,	//	120 15-120  The IRMS value of Protect finction      //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL COUNT          "	,	//	121 15-121  The Gain value of Protect finction      //[Output Phase Loss 2, Sampo, 2015/05/21]
	"PPI filter point    "	,	//	122 15-122  RESERVED
	"MBF Recoder         "	,	//	123 15-123  MBF record after power off
	"EoL Cnt Recder H    "	,	//	124 15-124  RESERVED        //[add for UL EoL Verification,Bernie, 2013/04/22]
	"EoL Cnt Recder L    "	,	//	125 15-125  RESERVED	    //[add for UL EoL Verification,Bernie, 2013/04/22]
	"RESERVE             "	,	//	126 15-126  RESERVED
	"Unavailable         "	,	//	127 15-127  RESERVED
//	"PPI filter point    "	,	//	127 15-128  PPI control     //[PPI function, Sampo, 2015/09/08]


/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
    "儂笱梓妎睫          "	,	//	128 00-00	Model Type of Drive 
    "曹けん塗隅萇霜  Amps"	,	//	129 00-01	Rated Current
    "統杅笭离扢隅        "	,	//	130 00-02	Parameter Reset
    "羲儂珆尨賒醱恁寁    "	,	//	131 00-03	Start up Display        //chinese 
    "嗣髡夔珆尨恁寁      "	,	//	132 00-04	User Display            //chinese 
    "隅砱掀瞰扢隅        "	,	//	133 00-05	User Coefficient        //chinese 
    "�篲�唳掛            "	,	//	134 00-06	Software Version
    "統杅悵誘躇鎢怀��    "	,	//	135 00-07	Password Input
    "統杅悵誘躇鎢扢隅    "	,	//	136 00-08	Password Input
    "諷秶耀宒            "	,	//	137 00-09	Control Methods
    "厒僅等弇            "	,	//	138 00-10	Velocity Unit Select
    "��雄ん怀堤源砃      "	,	//	139 00-11   Change Output Direction, Added by 
    "婥疏け薹        KHz "	,	//	140 00-12	Carry Frequency
    "赻雄恛揤髡夔        "	,	//	141 00-13	AVR
    "厒僅硌鍔懂埭        "	,	//	142 00-14	Source of Freq. Command
    "堍蛌硌鍔懂埭        "	,	//	143 00-15	Source of Oper. Command
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"郔湮紱釬け薹    Hz  "	,	//	144	01-00 Max Output Freq.
	"萇儂塗隅け薹    Hz  "	,	//	145	01-01 Motor Base Frequency 1
	"萇儂塗隅萇揤    V   "	,	//	146	01-02 Max Output Voltage
	"菴媼怀堤け薹    Hz  "	,	//	147	01-03 Mid Output Freq.1
	"菴媼怀堤萇揤    V   "	,	//	148	01-04 Mid Output Voltage 1
	"菴��怀堤け薹    Hz  "	,	//	149	01-05 Mid Output Freq.2
	"菴��怀堤萇揤    V   "	,	//	150	01-06 Mid Output Voltage 2
	"菴侐怀堤け薹    Hz  "	,	//	151	01-07 Min Output Freq.
	"菴侐怀堤萇揤    V   "	,	//	152	01-08 Min Output Voltage
	"ゐ雄け薹        Hz  "	,	//	153	01-09 Start Frequency
	"怀堤け薹奻癹硉  Hz  "	,	//	154	01-10 Upper Bound Freq.
	"怀堤け薹狟癹硉  Hz  "	,	//	155	01-11 Lower Bound Freq.
	"菴珨樓厒奀潔    sec "	,	//	156	01-12 1st Acceleration time      //chinese 
	"菴珨熬厒奀潔    sec "	,	//	157	01-13 1st Deceleration time      //chinese 
	"菴媼樓厒奀潔    sec "	,	//	158	01-14 2nd Acceleration time      //chinese 
	"菴媼熬厒奀潔    sec "	,	//	159	01-15 2nd Deceleration time      //chinese 
	"菴��樓厒奀潔    sec "	,	//	160	01-16 3rd Acceleration time      //chinese 
	"菴��熬厒奀潔    sec "	,	//	161	01-17 3rd Deceleration time      //chinese 
	"菴侐樓厒奀潔    sec "	,	//	162	01-18 4th Acceleration time      //chinese 
	"菴侐熬厒奀潔    sec "	,	//	163	01-19 4th Deceleration time      //chinese 
	"渡雄樓厒奀潔    sec "	,	//	164	01-20 JOG Acceleration time
	"渡雄熬厒奀潔    sec "	,	//	165	01-21 JOG Deceleration time
	"渡雄け薹        Hz  "	,	//	166	01-22 JOG Frequency
	"1-4樓厒з遙     Hz  "	,	//	167	01-23 Transition Frequency ACC1/DEC1 to 
	"樓厒羲宎S1奀潔  sec "	,	//	168	01-24 S curve Accel time 1
	"樓厒羲宎S2奀潔  sec "	,	//	169	01-25 S curve Accel time 2
	"樓厒羲宎S3奀潔  sec "	,	//	170	01-26 S curve Decel time 1
	"樓厒羲宎S4奀潔  sec "	,	//	171	01-27 S curve Decel time 2
	"苤衾菴侐け薹耀宒    "	,	//	172	01-28 Select Zero Speed
	"す脯厒僅з遙    Hz  "	,	//	173	01-29 Landing Frequency 
	"腴衾す脯厒僅S5  sec "	,	//	174	01-30 S curve Decel time 3
	"礿陬熬厒奀潔    sec "	,	//	175	01-31 Stop Deceleration time	
    "笝傷Ч秶熬厒僅  m/s "	,	//  1xx 01-32
    "傷赽眻礿詢厒奀潔sec "	,	//	1xx	01-33 IODHT IO direct hold time   
    "傷赽眻礿す脯奀潔sec "	,	//	1xx	01-34 IODLT IO direct landing freq
    "傷赽眻礿喳講癹秶    "	,	//	1xx	01-35 IODLT IO direct landing time
    "傷赽眻礿熬厒擒燭cm  "	,	//	1xx	01-36 IODLT IO direct DistancE
    "眻礿統蕉熬厒擒燭m   "	,	//	1xx	01-37 IODLT IO direct DistancE
    "傷赽眻諉礿蕞祡夔    "	,	//	1xx	01-38 IODLT IO direct DistancE
    "ETS勳薹掀誕袧弇 Hz  "  ,   //  1xx 01-39 IODLT IO direct DistancE
    "踡摹熬厒熬厒奀潔sec "	,	//	1xx	01-40 IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105 RESERVED
    "Emergency S3    sec "  ,   //  105 15-105 RESERVED
    "Emergency S4    sec "  ,   //  105 15-105 RESERVED
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "2/3 盄宒堍蛌耀宒    "	,	//	176	02-00 2/3 wire control                
    "MI1髡夔恁寁         "	,	//	177	02-01 Multi-Function Input 1          
    "MI2髡夔恁寁         "	,	//	178	02-02 Multi-Function Input 2          
    "MI3髡夔恁寁         "	,	//	179	02-03 Multi-Function Input 3          
    "MI4髡夔恁寁         "	,	//	180	02-04 Multi-Function Input 4          
    "MI5髡夔恁寁         "	,	//	181	02-05 Multi-Function Input 5          
    "MI6髡夔恁寁         "	,	//	182	02-06 Multi-Function Input 6          
    "MI7髡夔恁寁         "	,	//	183	02-07 Multi-Function Input 7          
    "MI8髡夔恁寁         "	,	//	184	02-08 Multi-Function Input 8		    
    "杅趼怀�輴嬧百掉酲ec "	,	//	185	02-09 Digital in response time		
    "杅趼怀�賰誕�        "	,	//	186	02-10 Multi-Function Input Inverse	
    "RA 髡夔恁寁         "	,	//	187	02-11 Multi-Function Relay 1		    
    "MRA髡夔恁寁         "	,	//	188	02-12 Multi-Function Relay 2		    
    "R1A髡夔恁寁         "	,	//	189	02-13 Multi-Function Output 1		    
    "R2A髡夔恁寁         "	,	//	190	02-14 Multi-Function Output 2		    
    "MO1髡夔恁寁         "	,	//	191	02-15 Multi-Function Output 3		    
    "MO2髡夔恁寁         "	,	//	192	02-16 Multi-Function Output 4		    
    "MO3髡夔恁寁         "	,	//	193	02-17 Multi-Function Output 5		    
    "MO4髡夔恁寁         "	,	//	194	02-18 Multi-Function Output 6		    
    "MO5髡夔恁寁         "	,	//	195	02-19 Multi-Function Output 7		    
    "MO6髡夔恁寁         "	,	//	196	02-20 Multi-Function Output 8		    
    "MO7髡夔恁寁         "	,	//	197	02-21 Multi-Function Output 9		    
    "MO8髡夔恁寁         "	,	//	198	02-22 Multi-Function Output 10		    
    "杅趼怀堤源砃        "	,	//	199	02-23 Multi-Function Output inverse	
    "ゐ雄陓瘍耀宒恁寁    "  ,   //  200 02-24 Sequence start mode
    "�扂牓肅妗蓬�1   Hz  "	,	//	201	02-25 Desired Frequency 1		        
    "�扂牓肅妗蓬�1遵 Hz  "	,	//	202	02-26 Band of Desired Frequency 1		
    "�扂牓肅妗蓬�2   Hz  "	,	//	203	02-27 Desired Frequency 2		        
    "�扂牓肅妗蓬�2遵 Hz  "	,	//	204	02-28 Band of Desired Frequency 2		
    "儂迮价陬庋溫晊奀sec "	,	//	205	02-29 Brake Delay Timer at run
    "儂迮价陬惕掅晊奀sec "	,	//	206	02-30 Brake Delay Timer at stop
    "萇棠概絳籵晊奀  sec "	,	//	207	02-31 Mech Contact Delay Timer run
    "萇棠概剿羲晊奀  sec "	,	//	208	02-32 Mech Contact Delay Timer stop		
    "萇霜袧弇扢隅    %   "	,	//	209	02-33 Isum Current Output Detect	    
    "厒僅⑹僇扢隅    Hz  "	,	//	210	02-34 Speed Area
    "儂迮价陬潰堤奀潔sec "	,	//	211	02-35 Mechanical Brake Checking Time
    "萇棠概潰堤奀潔  sec "	,	//	212 02-36 Magnetic Contactor Checking Time
    "蛌撻�溜炩脂劙√�    "  ,   //  213 02-37 Mechanical Brake Checking Current Enable
    "萇棠概絳籵晊奀  sec "	,	//	207	02-38 Mech Contact Delay Timer run
    "萇棠概剿羲晊奀  sec "	,	//	208	02-39 Mech Contact Delay Timer stop	
	"LU/LD祑都恁寁       "  ,   //  2xx 02-40 LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
	"LU/LD羲繚淈聆   sec "  ,   //  2xx 02-41 LD/LD Open Detect Time      //#15977, LULD detect, James, 2021/04/01
	"LU/LD傻繚淈聆   sec "  ,   //  2xx 02-42 LD/LD Short Detect Time     //#15977, LULD detect, James, 2021/04/01
    "堍蛌厒僅善湛遵僅Hz  "	,	//  202 02-43 Band of Speed Agree Function #18572			
    "STO傻繚淈聆奀潔 sec "  ,   //  2xx 02-44 STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45 //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "厒僅癹秶        m/s "  ,   //  2xx 02-46 //[Artemis Add Sensor819 Function/Special/2022/06/06]
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AUI1髡夔恁寁        "	,	//	214	03-00 AUI1 selection                    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "悵隱                "	,	//	215	03-01 ACI  selection                    //[ACI function remove, Bernie, 01/20/2012] 
    "AUI2髡夔恁寁        "	,	//	216	03-02 AUI2 selection                    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1怀�踰巷�    %   "	,	//	217	03-03 AUI1 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "悵隱                "	,	//	218	03-04 ACI  input Bias                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2怀�踰巷�    %   "	,	//	219	03-05 AUI2 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1淏蛹ぇ揤耀宒    "	,	//	220 03-06 AUI1 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "悵隱                "	,	//	221 03-07 ACI  input Polarity               //[ACI function remove, Bernie, 01/20/2012]
    "AUI2淏蛹ぇ揤耀宒    "	,	//	222 03-08 AUI2 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1怀�郺齎�    %   "	,	//	223 03-09 AUI1 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "悵隱                "	,	//	224 03-10 ACI  input Gain                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2怀�郺齎�    %   "	,	//	225 03-11 AUI2 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1薦疏奀潔    sec "	,	//	226 03-12 Low pass filter of AUI1 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "悵隱                "	,	//	227 03-13 Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2薦疏奀潔    sec "	,	//	228 03-14 Low pass filter of AUI2 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "盡笭硃野赻悝炾      "	,	//	229 03-15 Loss of ACI                       //[ACI function remove, Bernie, 01/20/2012]
    "悵隱                "  ,   //  230 03-16 RESERVED 
    "AO1 怀堤恁寁        "	,	//	231 03-17 Analong Output 1
    "AO1 怀堤崝祔    %   "	,	//	232 03-18 Analong Output 1 Gain
    "AO1 怀堤毀砃妏夔    "	,	//	233 03-19 AO1 in minus value
    "AO2 怀堤恁砐        "	,	//	234 03-20 Analong Output 2
    "AO2 怀堤崝祔    %   "	,	//	235 03-21 Analong Output 2 Gain
    "AO2 怀堤毀砃妏夔    "	,	//	236 03-22 AO2 in minus value
    "AUI1耀攜怀�踽�宒    "	,	//	237 03-23 AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2耀攜怀�踽�宒    "	,	//	238 03-24 AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1怀�輶頞�        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
    //"AUI2怀�輶頞�        "	,	//	238  03-26    AUI2 Communciate

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "菴錨僇厒        Hz  "	,	//	239 04-00 Multi-Speed 0
    "菴珨僇厒        Hz  "	,	//	240 04-01 Multi-Speed 1
    "菴媼僇厒        Hz  "	,	//	241 04-02 Multi-Speed 2
    "菴��僇厒        Hz  "	,	//	242 04-03 Multi-Speed 3
    "菴侐僇厒        Hz  "	,	//	243 04-04 Multi-Speed 4
    "菴拻僇厒        Hz  "	,	//	244 04-05 Multi-Speed 5
    "菴鞠僇厒        Hz  "	,	//	245 04-06 Multi-Speed 6
    "菴ほ僇厒        Hz  "	,	//	246 04-07 Multi-Speed 7
    "菴匐僇厒        Hz  "	,	//	247 04-08 Multi-Speed 8
    "菴嬝僇厒        Hz  "	,	//	248 04-09 Multi-Speed 9
    "菴坋僇厒        Hz  "	,	//	249 04-10 Multi-Speed 10 
    "菴坋珨僇厒      Hz  "	,	//	250 04-11 Multi-Speed 11
    "菴坋媼僇厒      Hz  "	,	//	251 04-12 Multi-Speed 12
    "菴坋��僇厒      Hz  "	,	//	252 04-13 Multi-Speed 13
    "菴坋侐僇厒      Hz  "	,	//	253 04-14 Multi-Speed 14
    "菴坋拻僇厒      Hz  "	,	//	254 04-15 Multi-Speed 15
    
    "寰堔厒僅        m/s "  ,   //    2xx 04-16
    "す脯厒僅        m/s "  ,   //    2xx 04-17
    "毀價桴厒僅      m/s "  ,   //    2xx 04-18
    "詩坰湖賑硃野    mm  "  ,   //    2xx 04-19 GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //    2xx 04-20
    "TABST2 Status       "  ,   //    2xx 04-21
    "郔詢昜燴瞼脯        "  ,   //    2xx 04-22
    "醴ヶ瞼脯            "  ,   //    2xx 04-23
    "闕喳苺淏沭璃    %   "  ,   //    2xx 04-24
    "羲壽晊喧硃野    sec "  ,   //    2xx 04-25
    "脹厒�葯鉌掉�    ms  "  ,   //    2xx 04-26
    "覂散啣酗僅      mm  "  ,   //    2xx 04-27 
    "醴ヶ弇离 詢     m   "  ,   //    2xx 04-28
    "醴ヶ弇离 腴     mm  "  ,   //    2xx 04-29
    "醴ヶ闕喳 H          "  ,   //    2xx 04-30 
    "醴ヶ闕喳 L          "  ,   //    2xx 04-31
    "覂散啣闕喳 H        "  ,   //    2xx 04-32
    "覂散啣闕喳 L        "  ,   //    2xx 04-33
    "嫖萇潔擒闕喳H       "  ,   //    2xx 04-34
    "嫖萇潔擒闕喳L       "  ,   //    2xx 04-35
    "DLC髡夔摩           "  ,   //    2xx 04-36
    "PDO珆尨倰怓         "  ,   //    2xx 04-37
    "熬厒羲壽�楅簊馦螸m  "  ,   //    2xx 04-38
    "郔湮枍厒啃煦掀  %   "  ,   //    2xx 04-39 //[ADCO EPS Modify]
    "粟銅晊扥硃野    mm  "  ,   //    2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //    2xx 04-41
    "EST Count           "  ,   //    2xx 04-42
    "TABST0 Count        "  ,   //    2xx 04-43
    "TABST1 Count        "  ,   //    2xx 04-44
    "DDS1/UDS1厒癹   m/s "  ,   //    2XX 04-45  DD1_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS2/UDS2厒癹   m/s "  ,   //    2XX 04-46  DD2_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS3/UDS3厒癹   m/s "  ,   //    2XX 04-47  DD3_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS4/UDS4厒癹   m/s "  ,   //    2XX 04-48  DD4_Vlim  //Artemis speed limit, James, 20200220
    "髡夔珜醱扢隅        "  ,   //    2XX 04-49  user page cahnge
    
    "1 瞼弇离 詢     m   "  , //  2XX 04-50   1Floor Position H 
    "1 瞼弇离 腴     mm  "  , //  2XX 04-51   1Floor Position L                                       
    "2 瞼弇离 詢     m   "  , //  2XX 04-52   2Floor Position H                                       
    "2 瞼弇离 腴     mm  "  , //  2XX 04-53   2Floor Position L                                       
    "3 瞼弇离 詢     m   "  , //  2XX 04-54   3Floor Position H                                       
    "3 瞼弇离 腴     mm  "  , //  2XX 04-55   3Floor Position L                                       
    "4 瞼弇离 詢     m   "  , //  2XX 04-56   4Floor Position H                                       
    "4 瞼弇离 腴     mm  "  , //  2XX 04-57   4Floor Position L                                       
    "5 瞼弇离 詢     m   "  , //  2XX 04-58   5Floor Position H                                       
    "5 瞼弇离 腴     mm  "  , //  2XX 04-59   5Floor Position L                                       
    "6 瞼弇离 詢     m   "  , //  2XX 04-60   6Floor Position H                                       
    "6 瞼弇离 腴     mm  "  , //  2XX 04-61   6Floor Position L                                       
    "7 瞼弇离 詢     m   "  , //  2XX 04-62   7Floor Position H                                       
    "7 瞼弇离 腴     mm  "  , //  2XX 04-63   7Floor Position L                                       
    "8 瞼弇离 詢     m   "  , //  2XX 04-64   8Floor Position H                                       
    "8 瞼弇离 腴     mm  "  , //  2XX 04-65   8Floor Position L                                       
    "9 瞼弇离 詢     m   "  , //  2XX 04-66   9Floor Position H                                       
    "9 瞼弇离 腴     mm  "  , //  2XX 04-67   9Floor Position L                                       
    "10瞼弇离 詢     m   "  , //  2XX 04-68   10Floor Position H                                      
    "10瞼弇离 腴     mm  "  , //  2XX 04-69   10Floor Position L                                      
    "11瞼弇离 詢     m   "  , //  2XX 04-70   11Floor Position H                                      
    "11瞼弇离 腴     mm  "  , //  2XX 04-71   11Floor Position L                                      
    "12瞼弇离 詢     m   "  , //  2XX 04-72   12Floor Position H                                      
    "12瞼弇离 腴     mm  "  , //  2XX 04-73   12Floor Position L                                      
    "13瞼弇离 詢     m   "  , //  2XX 04-74   13Floor Position H                                      
    "13瞼弇离 腴     mm  "  , //  2XX 04-75   13Floor Position L                                      
    "14瞼弇离 詢     m   "  , //  2XX 04-76   14Floor Position H                                      
    "14瞼弇离 腴     mm  "  , //  2XX 04-77   14Floor Position L                                      
    "15瞼弇离 詢     m   "  , //  2XX 04-78   15Floor Position H                                      
    "15瞼弇离 腴     mm  "  , //  2XX 04-79   15Floor Position L                                      
    "16瞼弇离 詢     m   "  , //  2XX 04-80   16Floor Position H                                      
    "16瞼弇离 腴     mm  "  , //  2XX 04-81   16Floor Position L                                      
    "17瞼弇离 詢     m   "  , //  2XX 04-82   17Floor Position H                                      
    "17瞼弇离 腴     mm  "  , //  2XX 04-83   17Floor Position L                                      
    "18瞼弇离 詢     m   "  , //  2XX 04-84   18Floor Position H                                      
    "18瞼弇离 腴     mm  "  , //  2XX 04-85   18Floor Position L                                      
    "19瞼弇离 詢     m   "  , //  2XX 04-86   19Floor Position H                                      
    "19瞼弇离 腴     mm  "  , //  2XX 04-87   19Floor Position L                                      
    "20瞼弇离 詢     m   "  , //  2XX 04-88   20Floor Position H                                      
    "20瞼弇离 腴     mm  "  , //  2XX 04-89   20Floor Position L                                      
    "21瞼弇离 詢     m   "  , //  2XX 04-90   21Floor Position H                                      
    "21瞼弇离 腴     mm  "  , //  2XX 04-91   21Floor Position L                                      
    "22瞼弇离 詢     m   "  , //  2XX 04-92   22Floor Position H                                      
    "22瞼弇离 腴     mm  "  , //  2XX 04-93   22Floor Position L                                      
    "23瞼弇离 詢     m   "  , //  2XX 04-94   23Floor Position H                                      
    "23瞼弇离 腴     mm  "  , //  2XX 04-95   23Floor Position L                                      
    "24瞼弇离 詢     m   "  , //  2XX 04-96   24Floor Position H                                      
    "24瞼弇离 腴     mm  "  , //  2XX 04-97   24Floor Position L                                      
    "25瞼弇离 詢     m   "  , //  2XX 04-98   25Floor Position H                                      
    "25瞼弇离 腴     mm  "  , //  2XX 04-99   25Floor Position L                                      
        
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM統杅赻悝炾        "	,	//	255 05-00 Motor Auto-Tuning
    "IM萇儂塗隅萇霜  Amps"	,	//	256 05-01 Motor 1 rated Current           
    "IM萇儂塗隅髡薹  Kw  "	,	//	257 05-02 Motor 1 Rated Power             
    "IM萇儂塗隅蛌厒  RPM "	,	//	258 05-03 Motor 1 Rated RPM               
    "IM萇儂憤杅          "	,	//	259 05-04 Motor 1 pole No.                
    "IM萇儂拻婥萇霜  Amps"	,	//	260 05-05 Motor 1 No-Load Current         
    "IM萇儂統杅 Rs   ohm "	,	//	261 05-06 Motor 1 Rs                      
    "IM萇儂統杅 Rr   ohm "	,	//	262 05-07 Motor 1 Rr                      
    "IM萇儂統杅 Lm   mH  "	,	//	263 05-08 Motor 1 Lm                      
    "IM萇儂統杅 Lx   mH  "	,	//	264 05-09 Motor 1 Lx                      
    "蛌撻硃野腴籵薦疏sec "	,	//	265 05-10 Vector Voltage Filter	        
    "賑船硃野腴籵薦疏sec "	,	//	266 05-11 Vector Slip Filter	            
    "萇雄蛌撻硃野崝祔    "	,	//	267 05-12 Torque Compensation Gain	    
    "賑船硃野崝祔        "	,	//	268 05-13 Slip Compensation Gain	        
    "賑船昫船袧弇    %   "	,	//	269 05-14 Slip Deviation level	        
    "賑船昫船潰堤奀潔sec "	,	//	270 05-15 Slip Deviation Detect Time	    
    "徹賑船潰堤恁寁      "	,	//	271 05-16 Over Slip treatment	            
    "涾絕硃野秪赽        "	,	//	272 05-17 Coeff for hunting disable	    
    "濛數萇儂堍蛌奀潔Mins"	,	//	273 05-18 Accumulative Motor Operation Min
    "濛數萇儂堍蛌    Days"	,	//	274 05-19 Accumulative Motor Operation Day
    "沺郋囷囮硃野    %   "	,	//	275 05-20 Coreloss % of output Power	    
    "曹けん奻萇奀潔  Mins"	,	//	276 05-21 Power On Min
    "曹けん奻萇毞杅  Days"	,	//	277 05-22 Power On Day    
    "隙汜賑船硃野崝祔%   "  ,   //  2XX 05-23 Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"萇雄賑船硃野崝祔%   "	,	//	2XX 05-24 RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "腴萇揤袧弇      V   "	,	//  278  06-00 Low voltage level
    "Й眈悵誘            "	,	//  279  06-01 Phase loss
    "樓厒徹萇霜囮厒  %   "	,	//	280  06-02 OC stall during Accel
    "隅厒徹萇霜囮厒  %   "	,	//	281  06-03 OC stall during Decel
    "徹萇霜囮厒揭燴      "	,	//	282  06-04 Stall preventation Accel/Decel time selection
    "徹蛌撻OT1揭燴       "	,	//	283  06-05 Over-Torque 1 Selection
    "徹蛌撻OT1袧弇   %   "	,	//	284  06-06 Over-Torque 1 level
    "徹蛌撻OT1潰堤   sec "	,	//	285  06-07 Over-Torque 1 Time
    "徹蛌撻OT2揭燴       "	,	//	286  06-08 Over-Torque 2 Selection	                     
    "徹蛌撻OT2袧弇   %   "	,	//	287  06-09 Over-Torque 2 level	                         
    "徹蛌撻OT2潰堤   sec "	,	//	288  06-10 Over-Torque 2 Time	                         
    "萇霜癹秶        %   "	,	//	289  06-11 Current Limit
    "萇赽��萇緛恁寁      "	,	//	290  06-12 Thermal Relay 1 Selection
    "��萇緛釬蚚奀潔  sec "	,	//	291  06-13 Thermal Relay 1 Time
    "徹��劑豢恲僅袧弇C   "	,	//	292  06-14 OH Warning Level
    "囮厒滅砦癹秶袧弇%   "	,	//	293  06-15 Stall preventation Limit Level
    "郔輪珨棒嘟梤暮翹    "	,	//	294  06-16 1st Fault Record
    "2棒ヶ腔嘟梤暮翹     "	,	//	295  06-17 2nd Fault Record
    "3棒ヶ腔嘟梤暮翹     "	,	//	296  06-18 3rd Fault Record
    "4棒ヶ腔嘟梤暮翹     "	,	//	297  06-19 4th Fault Record
    "5棒ヶ腔嘟梤暮翹     "	,	//	298  06-20 5th Fault Record
    "6棒ヶ腔嘟梤暮翹     "	,	//	299  06-21 6th Fault Record
    "祑都怀堤恁寁 1      "	,	//	300  06-22 Fault Option 1
    "祑都怀堤恁寁2       "	,	//	301  06-23 Fault Option 2
    "祑都怀堤恁寁3       "	,	//	302  06-24 Fault Option 3
    "祑都怀堤恁寁4       "	,	//	303  06-25 Fault Option 4
    "PTC雄釬恁寁         "	,	//	304  06-26 PTC over Treatments	                         
    "PTC袧弇         %   "	,	//	305  06-27 PTC Level
    "PTC潰堤奀潔     sec "	,	//	306  06-28 PTC Detect Filter time
    "踡摹堍俴萇埭萇揤V   "	,	//	307  06-29 EPS voltage level
    "渣昫怀堤恁寁        "	,	//	308  06-30 Fault Option Mode
    "ED 怀堤Й眈淈聆     "	,	//	309  06-31 Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "ヶ珨棒祑都堍蛌  Mins"	,	//	310  06-32 1st Fault Time(MIN)
    "ヶ珨棒祑都堍蛌  Days"	,	//	311  06-33 1st Fault Time(DAY)
    "2棒ヶ祑都堍蛌   Mins"	,	//	312  06-34 2nd Fault Time(MIN)
    "2棒ヶ祑都堍蛌   Days"	,	//	313  06-35 2nd Fault Time(DAY)
    "3棒ヶ祑都堍蛌   Mins"	,	//	314  06-36 3rd Fault Time(MIN)
    "3棒ヶ祑都堍蛌   Days"	,	//	315  06-37 3rd Fault Time(DAY)
    "4棒ヶ祑都堍蛌   Mins"	,	//	316  06-38 4th Fault Time(MIN)
    "4棒ヶ祑都堍蛌   Days"	,	//	317  06-39 4th Fault Time(DAY)
    "5棒ヶ祑都堍蛌   Mins"	,	//	318  06-40 5th Fault Time(MIN)
    "5棒ヶ祑都堍蛌   Days"	,	//	319  06-41 5th Fault Time(DAY)
    "6棒ヶ祑都堍蛌   Mins"	,	//	320  06-42 6th Fault Time(MIN)
    "6棒ヶ祑都堍蛌   Days"	,	//	321  06-43 6th Fault Time(DAY)
    "踡摹萇埭堍俴厒僅Hz  "  ,   //  322  06-44 EPS Frequency
    "渣昫雄釬恁寁        "  ,	//  323  06-45 LV Option Mode
    "EPS 耀宒恁寁        "  ,	//  324  06-46 EPS Option Mode
    "楷萸源砃刲坰奀潔sec "  ,   //  325  06-47 Generation Operation Detected Time
    "踡摹堍俴萇埭�暕熾VA "  ,   //  326  06-48 UPS Capacity (0.1KVA)
    "STO髡夔恁寁         "  ,   //  3xx  06-49 STO Lock selection     //[Safty function, Bernie]   
    "嘟梤笭彸奀MO雄釬    "  ,   //  356  06-50 Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "嘟梤笭彸棒杅        "  ,   //  356  06-51 Auto restart times after fault     
    "嘟梤笭彸奀潔    sec "  ,   //  356  06-52 Auto restart interval
    "祑都奀け薹韜鍔  Hz  "  ,   //  3xx  06-53 Fkey Record
    "祑都奀け薹怀堤  Hz  "  ,   //  3xx  06-54 Fcmd Record
    "祑都奀怀堤萇霜  Amps"  ,   //  3xx  06-55 Isum Record
    "祑都奀鎮湛け薹  Hz  "  ,   //  3xx  06-56 Fout Record
    "祑都奀怀堤萇揤  V   "  ,   //  3xx  06-57 Vout Record
    "祑都奀DCBus萇揤 V   "  ,   //  3xx  06-58 Dcbus Record    
    "祑都奀怀堤髡薹  KW  "  ,   //  3xx  06-59 Power Record
    "祑都奀怀堤蛌撻  %   "  ,   //  3xx  06-60 Torque Record
    "祑都奀IGBT恲僅  C   "  ,   //  3xx  06-61 IGBT Temperature Record   
    "祑都奀怀�賱匋�  Hex "  ,   //  3xx  06-62 MFI State Record
    "祑都奀怀堤傷赽  Hex "  ,   //  3xx  06-63 MFO State Record
    "祑都奀��雄ん袨怓Hex "  ,   //  3xx  06-64 Drive State Record
    "UCMP萇霜癹秶袧弇%   "  ,   //  3XX  06-65 Current limitation for UCMP function            //[UCMP function, Bernie, 2016/06/14]
    "龢雄婑督昢棒杅      "  ,   //  3xx  06-66 Service time count                              //[Service time function, Bernie, 2017/03/14]
    "龢雄婑督昢扢隅      "  ,   //  3xx  06-67 Service time function Enable                    //[Service time function, Bernie, 2017/03/14]
    "EPS淈聆髡秪袧弇 deg "  ,   //  3xx  06-68 EPS Detect Current    
    "EPS髡秪褒       deg "  ,   //  3xx  06-69 EPS Detect Current Ref
    "EPS源砃憮堤         "  ,   //  3xx  06-70 EPS Detect direction
    "EPS傷赽憮堤晊恁 sec "  ,   //  3xx  06-71 EPS MO Off Time
    "EPS傷赽敕磁晊恁 sec "  ,   //  3xx  06-72 EPS MO Off Time
    "蚗壅堍俴源砃數杅H   "	,   //	3xx  06-73 Running direction count high						
    "蚗壅堍俴源砃數杅L   "	,   //	3xx  06-74 Running direction count low
    "等棒堍俴源砃數杅H   "	,   //	3xx  06-75 Temp running direction count high
    "等棒堍俴源砃數杅L   "	,   //  3xx  06-76 Temp running direction count low
    "等棒堍俴笭离棒杅    "	,   //	3xx  06-77 Temp running reset count
    "堍俴源砃癹秶棒杅k   "	,   //	3xx  06-78 Running life
    "堍俴棒杅髡夔恁砐    "	,   //	3xx  06-79 Running function
    "祑都2奀け薹怀堤  Hz  " ,   //  3xx  06-80 Fcmd Record1
    "祑都2奀DCBus萇揤 V   " ,   //  3xx  06-81 Dcbus Record1
    "祑都2奀怀堤萇霜  Amps" ,   //  3xx  06-82 Isum Record1
    "祑都2奀IGBT恲僅  C   "	,   //  3xx  06-83 IGBT Temperature Record1
    "祑都3奀け薹怀堤  Hz  " ,   //  3xx  06-84 Fcmd Record2
    "祑都3奀DCBus萇揤 V   " ,   //  3xx  06-85 Dcbus Record2
    "祑都3奀怀堤萇霜  Amps" ,   //  3xx  06-86 Isum Record2
    "祑都3奀IGBT恲僅  C   " ,   //  3xx  06-87 IGBT Temperature Record2
    "祑都4奀け薹怀堤  Hz  " ,   //  3xx  06-88 Fcmd Record3
    "祑都4奀DCBus萇揤 V   " ,   //  3xx  06-89 Dcbus Record3
    "祑都4奀怀堤萇霜  Amps" ,   //  3xx  06-90 Isum Record3
    "祑都4奀IGBT恲僅  C   " ,   //  3xx  06-91 IGBT Temperature Record3
    "祑都5奀け薹怀堤  Hz  " ,   //  3xx  06-92 Fcmd Record4
    "祑都5奀DCBus萇揤 V   " ,   //  3xx  06-93 Dcbus Record4
    "祑都5奀怀堤萇霜  Amps" ,   //  3xx  06-94 Isum Record4
    "祑都5奀IGBT恲僅  C   " ,   //  3xx  06-95 IGBT Temperature Record4
    "祑都6奀け薹怀堤  Hz  " ,   //  3xx  06-96 Fcmd Record5
    "祑都6奀DCBus萇揤 V   " ,   //  3xx  06-97 Dcbus Record5
    "祑都6奀怀堤萇霜  Amps" ,   //  3xx  06-98 Isum Record5
    "祑都6奀IGBT恲僅  C   " ,   //  3xx  06-99 IGBT Temperature Record5
/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "价陬儒极溫萇袧弇V   "	,	//	327   07-00 SW Braking Level
    "伢陬儒极喧笴萇揤V   "  ,   //	328   07-01 DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "ゐ雄眻霜秶雄袧弇%   "	,	//	329   07-02 DCI Current Level    //[DCI Level when stop, Bernie, 05/21/2012]
    "ゐ雄眻霜秶雄奀潔sec "	,	//	330   07-03 DCI Time at Start 
    "礿陬眻霜秶雄奀潔sec "	,	//	331   07-04 DCI Time at STOP
    "礿陬秶雄れ宎け薹Hz  "	,	//	332   07-05 DCI Freq. At start
    "眻霜秶雄I崝祔       "	,	//	333   07-06 DCI KI
    "喘炵樓厒笢剿奀潔sec "	,	//	334   07-07 Gear wait time when acceleration
    "喘炵樓厒笢剿け薹Hz  "	,	//	335   07-08 Gear wait frequency when acceleration
    "喘炵熬厒笢剿奀潔sec "	,	//	336   07-09 Gear wait time when deceleration
    "喘炵熬厒笢剿け薹Hz  "	,	//	337   07-10 Gear wait frequency when deceleration
    "瑞圮諷秶源宒        "	,	//	338   07-11 Fan Control
    "蛌撻韜鍔        %   "	,	//	339   07-12 TQC Reference from RS485
    "蛌撻韜鍔懂埭        "	,	//	340   07-13 Source of Torque Command
    "郔湮蛌撻韜鍔    %   "	,	//	341   07-14 Torque max. level
    "蛌撻韜鍔薦疏奀潔sec "	,	//	342   07-15 Torque command filter
    "厒僅癹秶恁寁        "	,	//	343   07-16 Speed Limit selection
    "蛌撻耀宒+SPD癹秶%   "	,	//	344   07-17 Torque mode positive speed limit
    "蛌撻耀宒-SPD癹秶%   "	,	//	345   07-18 Torque mode negative speed limit
    "蛌撻韜鍔ぇ揤懂埭    "	,	//	346   07-19 Torque offset selection
    "蛌撻韜鍔ぇ揤扢隅%   "	,	//	347   07-20 Torque offset setting level
    "詢蛌撻ぇ講      %   "	,	//	348   07-21 Torque offset setting level High
    "笢蛌撻ぇ講      %   "	,	//	349   07-22 Torque offset setting level Middle
    "腴蛌撻ぇ講      %   "	,	//	350   07-23 Torque offset setting level Low
    "淏蛌萇雄蛌撻癹秶%   "	,	//	351   07-24 FWD Motoring Tq Limit
    "毀蛌隙汜蛌撻癹秶%   "	,	//	352   07-25 FWD Regeneration Tq Limit
    "淏蛌萇雄蛌撻癹秶%   "	,	//	353   07-26 REV Motoring Tq Limit
    "毀蛌隙汜蛌撻癹秶%   "	,	//	354   07-27 REV Regeneration Tq Limit
    "Ч秶礿儂潰堤源宒    "	,	//	355   07-28 Emergency Stop & Forced Stop selection
    "礿陬蛌撻熬厒奀潔sec "	,	//	356   07-29 Torque Decrease Time
    "礿砦眻霜秶雄袧弇%   "  ,   //  356   07-30 STOP DC Inject Level       //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  357   07-31  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 潰聆           "  ,   //  358   07-32  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 潰聆擒燭    ppr"  ,   //  359   07-33  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 潰聆鏃杅       "  ,   //  360   07-34  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 潰聆囮啖蛌撻   "  ,   //  361   07-35  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 潰聆郔苤蛌撻   "  ,   //  362   07-36  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 潰聆郔湮蛌撻   "  ,   //  362   07-37  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM統杅赻悝炾        "	,	//	357   08-00 PMotor Auto-Tuning  
    "PM萇儂塗隅萇霜  Amps"	,	//	358   08-01 PMotor rated Current
    "PM萇儂塗隅髡薹  Kw  "	,	//	359   08-02 PMotor Rated Power  
    "PM萇儂塗隅蛌厒  RPM "	,	//	360   08-03 PMotor Rated RPM    
    "PM萇儂憤杅          "	,	//	361   08-04 PMotor pole No.     
    "PM萇儂統杅 Rs   ohm "	,	//	362   08-05 PMotor Rs           
    "PM萇儂統杅 Ld   mH  "	,	//	363   08-06 PMotor Ld           
    "PM萇儂統杅 Lq   mH  "	,	//	364   08-07 PMotor Lq           
    "萇儂毀萇雄岊    Vrms"	,	//	365   08-08 PMotor Bemf coff	
    "棠憤ぇ痄褒      deg "	,	//	366   08-09 PM Z-pulse offset angle, 0.1 degree, dino
    "棠憤笭陔隅弇        "	,	//	367   08-10 //ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "籵捅華硊            "	,	//	368   09-06 Comm Address                              
    "籵捅換怀厒僅    kbps"	,	//	369   09-07 Tranmission speed                         
    "籵捅渣昫揭燴        "	,	//	370   09-08 Comm fault Treatment                      
    "貣奀潰堤奀潔    sec "	,	//	371   09-09 Comm Time out                             
    "籵捅跡宒            "	,	//	372   09-10 Comm Protocol                             
    "砒茼晊奀奀潔    ms  "	,	//	373   09-11 ASC remote Response Delay Time, 1=100us   
    "CAN 籵捅婦薹        "	,   //  3XX   09-06 CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "CAN PDO蝠挍奀潔 ms  "	,   //  3XX   09-07 CAN PDO Handshaking Period
    "CAN PDO籵捅貣奀 ms  "	,   //  3XX   09-08 CAN Communiction Timeout	
    "奻弇儂妎梗鎢        "  ,   //  3XX   09-09 
    "FHM 婃湔ん          "  ,   //  3XX   09-10   
    "DLC 婃湔ん1         "  ,   //  3XX   09-11   
    "DLC 婃湔ん2         "  ,   //  3XX   09-12    
    "DLC 婃湔ん3         "  ,   //  3XX   09-13   
	"PDO換冞潔路     ms  "	,	//	3XX   09-14 CAN fail rate---aevin 6/12/2017

/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"晤鎢ん笱濬恁寁      "	,	//	374   10-00 Encoder TYPE                             
	"晤鎢ん闕喳萸杅  ppr "	,	//	375   10-01 Encoder pulses	                    
	"晤鎢ん怀�遶恀�      "	,	//	376   10-02 PG input setting	                
	"PG渣昫雄釬恁寁      "	,	//	377   10-03 PG fbk fault treatment	            
	"PG渣昫潰堤奀潔  sec "	,	//	378   10-04 PG fbk Error Detection Time	        
	"PG囮厒袧弇      %   "	,	//	379   10-05 PG fbk overspeed detection level	
	"PF囮厒潰堤奀潔  sec "	,	//	380   10-06 Over speed Detection Time	        
	"PG蛌船祑都袧弇  %   "	,	//	381   10-07 PG fbk speed deviation level	    
	"PG蛌船潰堤奀潔  sec "	,	//	382   10-08 Deviation Detect Time	            
	"PG囮厒雄釬恁寁      "	,	//	383   10-09 Operation at overspeed	            
	"HALL陓瘍耀宒恁寁    "  ,   //  384   10-10 Hall Input Types
	"ゐ雄錨厒崝祔P       "	,	//	385   10-11 KP gain of ASR in Zero speed	
	"ゐ雄錨厒儅煦I   sec "	,	//	386   10-12 Ki gain of ASR in Zero speed	
	"腴厒崝祔P           "	,	//	387   10-13 ASR P Gain 1	                
	"腴厒儅煦奀潔I   sec "	,	//	388   10-14 ASR I Gain 1	                
	"詢厒崝祔P           "	,	//	389   10-15 ASR P Gain 2	                
	"詢厒儅煦奀潔I   sec "	,	//	390   10-16 ASR I Gain 2	                
	"腴/詢厒з遙け薹 Hz  "	,	//	391   10-17 ASR1/ASR2 switch freq	        
	"ASR腴籵薦疏崝祔 sec "	,	//	392   10-18 Primary LowPass filter Gain 
	"弇离諷秶ASR崝祔 P   "  ,	//	393   10-19 position control Kp Gain  
    "錨/腴厒湍遵覃淕 Hz  "  ,   //  394   10-20 Low Spd band
    "腴/詢厒湍遵覃淕 Hz  "  ,   //  395   10-21 High Spd band
	"弇离諷秶ASR儅煦Isec "	,	//	396   10-22 Position control time
	"ゐ雄弇离諷秶腴籵sec "	,	//	397   10-23 Position control LOW POSS FILTER
	"弇离諷秶耀宒恁寁    "	,	//	398   10-24 Source of position control, add by dino, 
	"す脯錨厒崝祔P   %   "	,	//	399   10-25 KP gain of ASR in Zero speed of 
	"す脯錨厒儅煦I   sec "	,	//	400   10-26 Ki gain of ASR in Zero speed of Landing
	"弇离諷秶錨厒崝祔%   "	,	//	385   10-27 KP gain of ASR in Zero speed during 
	"弇离諷秶錨厒儅煦sec "	,	//	386   10-28 Ki gain of ASR in Zero speed during 
    "PG縐壺け怀堤硉      "	,   //  4xx   10-29 PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG縐壺け怀堤倰宒    "	,   //  4xx   10-30 PG Card Mode setting                      //[DCI Level when stop, Bernie, 05/21/2012]    
    "PG C+/C-恁寁        "  ,   //  110   10-31 RESERVED     //[change parameter to normal group, Bernie, 2014/02/14]
    "萇枍徹樓厒僅袧弇m/s2"  ,   //  3XX   10-32 Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "徹樓厒僅淈聆奀潔sec "  ,   //  3XX   10-33 Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "徹樓厒僅淈聆恁寁    "  ,   //  3XX   10-34 Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "炵苀諷秶        Hex "	,	//	401   11-00 system control bit0:auto, bit1:Jm tunning, 
    "郔湮け薹勤茼枍厒m/s "  ,   //  402   11-01 Lift operation speed                                        
    "珝竘謫眻噤      mm  "  ,   //  403   11-02 SHEAVE diameter		                
    "喘謫掀              "  ,   //  404   11-03 Gear Ratio                                              
    "唑境掀              "  ,   //  405   11-04 Suspension ratio	                                        
    "儂迮嫦講啃煦掀  %   "  ,   //  406   11-05 inertia	percent		                  
    "ゐ雄錨厒湍遵    Hz  "	,	//	407   11-06 Zero Speed Loop BandWidth	                                
    "腴厒湍遵        Hz  "	,	//	408   11-07 Speed Loop BandWidth1		                                
    "詢厒湍遵        Hz  "	,	//	409   11-08 Speed Loop BandWidth2		                                
    "PDFF崝祔硉      %   "	,	//	410   11-09 PDFFKr		                                                
    "厒僅諷秶ヶ嚏崝祔%   "	,	//	411   11-10 SPEED FFD GAIN		                    
    "側疪薦疏旮僅    db  "	,	//	412   11-11 Netch filter deep(db)	                                    
    "側疪薦疏け薹    Hz  "	,	//	413   11-12 Netch filter frequency	                                    
    "醱啣珆尨薦疏奀潔sec "	,	//	414   11-13 Low Pass Filter for display	                                
    "樓厒奀郔湮萇霜  %   "	,	//	415   11-14 ACC Max current                                             
    "萇枍郔湮樓厒僅  m/s2"  ,	//	416   11-15 max meter/sec	                                            
    "潼諷杅擂弇离    Hex "  ,   //	417   11-16 Display address,add by dino 2007/03/08                      
    "潼諷訧蹋            "  ,	//	418   11-17 Display data,   add by dino 2007/03/08                      
    "悵隱                "  ,   //  419   11-18 Protect Bit	                                                
    "礿陬錨厒湍遵    Hz  "	,	//	420   11-19 Zero Speed Loop BandWidth of Landing  
    "PWM 耀宒耀宒        "  ,   //  4XX   11-20 PWM Mode selection  PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LC01珆尨薦疏奀潔 sec"	,	//	422   11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	420   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "赻隅統杅1           "  ,   //  421   12-00
    "赻隅統杅2           "  ,   //  422   12-01
    "赻隅統杅3           "  ,   //  423   12-02
    "赻隅統杅4           "  ,   //  424   12-33
    "赻隅統杅5           "  ,   //  425   12-04
    "赻隅統杅6           "  ,   //  426   12-05
    "赻隅統杅7           "  ,   //  427   12-06
    "赻隅統杅8           "  ,   //  428   12-07
    "赻隅統杅9           "  ,   //  429   12-08
    "赻隅統杅10          "  ,   //  430   12-09
    "赻隅統杅11          "  ,   //  431   12-10
    "赻隅統杅12          "  ,   //  432   12-11
    "赻隅統杅13          "  ,   //  433   12-12
    "赻隅統杅14          "  ,   //  434   12-13
    "赻隅統杅15          "  ,   //  435   12-14
    "赻隅統杅16          "  ,   //  436   12-15
    "赻隅統杅17          "  ,   //  437   12-16
    "赻隅統杅18          "  ,   //  438   12-17
    "赻隅統杅19          "  ,   //  439   12-18
    "赻隅統杅20          "  ,   //  440   12-19
    "赻隅統杅21          "  ,   //  441   12-20
    "赻隅統杅22          "  ,   //  442   12-21
    "赻隅統杅23          "  ,   //  443   12-22
    "赻隅統杅24          "  ,   //  444   12-23
    "赻隅統杅25          "  ,   //  445   12-24
    "赻隅統杅26          "  ,   //  446   12-25
    "赻隅統杅27          "  ,   //  447   12-26
    "赻隅統杅28          "  ,   //  448   12-27
    "赻隅統杅29          "  ,   //  449   12-28
    "赻隅統杅30          "  ,   //  450   12-29
    "赻隅統杅31          "  ,   //  451   12-30
    "赻隅統杅32          "  ,   //  452   12-31
    "赻隅統杅33          "  ,   //  433   12-12
    "赻隅統杅34          "  ,   //  434   12-13
    "赻隅統杅35          "  ,   //  435   12-14
    "赻隅統杅36          "  ,   //  436   12-15
    "赻隅統杅37          "  ,   //  437   12-16
    "赻隅統杅38          "  ,   //  438   12-17
    "赻隅統杅39          "  ,   //  439   12-18
    "赻隅統杅40          "  ,   //  430   12-09
    "赻隅統杅41          "  ,   //  431   12-10
    "赻隅統杅42          "  ,   //  432   12-11
    "赻隅統杅43          "  ,   //  433   12-12
    "赻隅統杅44          "  ,   //  434   12-13
    "赻隅統杅45          "  ,   //  435   12-14
    "赻隅統杅46          "  ,   //  436   12-15
    "赻隅統杅47          "  ,   //  437   12-16
    "赻隅統杅48          "  ,   //  438   12-17
    "赻隅統杅49          "  ,   //  439   12-18
    "赻隅統杅50          "  ,   //  430   12-09
    "悵隱                "  ,   //  431   12-10
    "悵隱                "  ,   //  432   12-11
    "悵隱                "  ,   //  433   12-12
    "悵隱                "  ,   //  434   12-13
    "悵隱                "  ,   //  435   12-14
    "悵隱                "  ,   //  436   12-15
    "悵隱                "  ,   //  437   12-16
    "悵隱                "  ,   //  438   12-17
    "悵隱                "  ,   //  439   12-18
    "悵隱                "  ,   //  430   12-09
    "悵隱                "  ,   //  431   12-10
    "悵隱                "  ,   //  432   12-11
    "悵隱                "  ,   //  433   12-12
    "悵隱                "  ,   //  434   12-13
    "悵隱                "  ,   //  435   12-14
    "悵隱                "  ,   //  436   12-15
    "悵隱                "  ,   //  437   12-16
    "悵隱                "  ,   //  438   12-17
    "悵隱                "  ,   //  439   12-18
    "悵隱                "  ,   //  430   12-09
    "悵隱                "  ,   //  431   12-10
    "悵隱                "  ,   //  432   12-11
    "悵隱                "  ,   //  433   12-12
    "悵隱                "  ,   //  434   12-13
    "悵隱                "  ,   //  435   12-14
    "悵隱                "  ,   //  436   12-15
    "悵隱                "  ,   //  437   12-16
    "悵隱                "  ,   //  438   12-17
    "悵隱                "  ,   //  439   12-18
    "悵隱                "  ,   //  430   12-09
    "悵隱                "  ,   //  431   12-10
    "悵隱                "  ,   //  432   12-11
    "悵隱                "  ,   //  433   12-12
    "悵隱                "  ,   //  434   12-13
    "悵隱                "  ,   //  435   12-14
    "悵隱                "  ,   //  436   12-15
    "悵隱                "  ,   //  437   12-16
    "悵隱                "  ,   //  438   12-17
    "悵隱                "  ,   //  439   12-18
    "悵隱                "  ,   //  430   12-09
    "悵隱                "  ,   //  431   12-10
    "悵隱                "  ,   //  432   12-11
    "悵隱                "  ,   //  433   12-12
    "悵隱                "  ,   //  434   12-13
    "悵隱                "  ,   //  435   12-14
    "悵隱                "  ,   //  436   12-15
    "悵隱                "  ,   //  437   12-16
    "悵隱                "  ,   //  438   12-17
    "悵隱                "  ,   //  439   12-18
    "悵隱                "  ,   //  439   12-18

/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "赻隅都蚚統杅1       "  ,   //  453   13-00
    "赻隅都蚚統杅2       "  ,   //  454   13-01
    "赻隅都蚚統杅3       "  ,   //  455   13-02
    "赻隅都蚚統杅4       "  ,   //  456   13-33
    "赻隅都蚚統杅5       "  ,   //  457   13-04
    "赻隅都蚚統杅6       "  ,   //  458   13-05
    "赻隅都蚚統杅7       "  ,   //  459   13-06
    "赻隅都蚚統杅8       "  ,   //  460   13-07
    "赻隅都蚚統杅9       "  ,   //  461   13-08
    "赻隅都蚚統杅10      "  ,   //  462   13-09
    "赻隅都蚚統杅11      "  ,   //  463   13-10
    "赻隅都蚚統杅12      "  ,   //  464   13-11
    "赻隅都蚚統杅13      "  ,   //  465   13-12
    "赻隅都蚚統杅14      "  ,   //  466   13-13
    "赻隅都蚚統杅15      "  ,   //  467   13-14
    "赻隅都蚚統杅16      "  ,   //  468   13-15
    "赻隅都蚚統杅17      "  ,   //  469   13-16
    "赻隅都蚚統杅18      "  ,   //  470   13-17
    "赻隅都蚚統杅19      "  ,   //  471   13-18
    "赻隅都蚚統杅20      "  ,   //  472   13-19
    "赻隅都蚚統杅21      "  ,   //  473   13-20
    "赻隅都蚚統杅22      "  ,   //  474   13-21
    "赻隅都蚚統杅23      "  ,   //  475   13-22
    "赻隅都蚚統杅24      "  ,   //  476   13-23
    "赻隅都蚚統杅25      "  ,   //  477   13-24
    "赻隅都蚚統杅26      "  ,   //  478   13-25
    "赻隅都蚚統杅27      "  ,   //  479   13-26
    "赻隅都蚚統杅28      "  ,   //  480   13-27
    "赻隅都蚚統杅29      "  ,   //  481   13-28
    "赻隅都蚚統杅30      "  ,   //  482   13-29
    "赻隅都蚚統杅31      "  ,   //  483   13-30
    "赻隅都蚚統杅32      "  ,   //  484   13-31
    "赻隅都蚚統杅33      "  ,   //  465   13-12
    "赻隅都蚚統杅34      "  ,   //  466   13-13
    "赻隅都蚚統杅35      "  ,   //  467   13-14
    "赻隅都蚚統杅36      "  ,   //  468   13-15
    "赻隅都蚚統杅37      "  ,   //  469   13-16
    "赻隅都蚚統杅38      "  ,   //  470   13-17
    "赻隅都蚚統杅39      "  ,   //  471   13-18
    "赻隅都蚚統杅40      "  ,   //  462   13-09
    "赻隅都蚚統杅41      "  ,   //  463   13-10
    "赻隅都蚚統杅42      "  ,   //  464   13-11
    "赻隅都蚚統杅43      "  ,   //  465   13-12
    "赻隅都蚚統杅44      "  ,   //  466   13-13
    "赻隅都蚚統杅45      "  ,   //  467   13-14
    "赻隅都蚚統杅46      "  ,   //  468   13-15
    "赻隅都蚚統杅47      "  ,   //  469   13-16
    "赻隅都蚚統杅48      "  ,   //  470   13-17
    "赻隅都蚚統杅49      "  ,   //  471   13-18
    "赻隅都蚚統杅50      "  ,   //  462   13-09
    "赻隅都蚚統杅51      "  ,   //  463   13-10
    "赻隅都蚚統杅52      "  ,   //  464   13-11
    "赻隅都蚚統杅53      "  ,   //  465   13-12
    "赻隅都蚚統杅54      "  ,   //  466   13-13
    "赻隅都蚚統杅55      "  ,   //  467   13-14
    "赻隅都蚚統杅56      "  ,   //  468   13-15
    "赻隅都蚚統杅57      "  ,   //  469   13-16
    "赻隅都蚚統杅58      "  ,   //  470   13-17
    "赻隅都蚚統杅59      "  ,   //  471   13-18
    "赻隅都蚚統杅60      "  ,   //  462   13-09
    "赻隅都蚚統杅61      "  ,   //  463   13-10
    "赻隅都蚚統杅62      "  ,   //  464   13-11
    "赻隅都蚚統杅63      "  ,   //  465   13-12
    "赻隅都蚚統杅64      "  ,   //  466   13-13
    "赻隅都蚚統杅65      "  ,   //  467   13-14
    "赻隅都蚚統杅66      "  ,   //  468   13-15
    "赻隅都蚚統杅67      "  ,   //  469   13-16
    "赻隅都蚚統杅68      "  ,   //  470   13-17
    "赻隅都蚚統杅69      "  ,   //  471   13-18
    "赻隅都蚚統杅70      "  ,   //  462   13-09
    "赻隅都蚚統杅71      "  ,   //  463   13-10
    "赻隅都蚚統杅72      "  ,   //  464   13-11
    "赻隅都蚚統杅73      "  ,   //  465   13-12
    "赻隅都蚚統杅74      "  ,   //  466   13-13
    "赻隅都蚚統杅75      "  ,   //  467   13-14
    "赻隅都蚚統杅76      "  ,   //  468   13-15
    "赻隅都蚚統杅77      "  ,   //  469   13-16
    "赻隅都蚚統杅78      "  ,   //  470   13-17
    "赻隅都蚚統杅79      "  ,   //  471   13-18
    "赻隅都蚚統杅80      "  ,   //  462   13-09
    "赻隅都蚚統杅81      "  ,   //  463   13-10
    "赻隅都蚚統杅82      "  ,   //  464   13-11
    "赻隅都蚚統杅83      "  ,   //  465   13-12
    "赻隅都蚚統杅84      "  ,   //  466   13-13
    "赻隅都蚚統杅85      "  ,   //  467   13-14
    "赻隅都蚚統杅86      "  ,   //  468   13-15
    "赻隅都蚚統杅87      "  ,   //  469   13-16
    "赻隅都蚚統杅88      "  ,   //  470   13-17
    "赻隅都蚚統杅89      "  ,   //  471   13-18
    "赻隅都蚚統杅90      "  ,   //  462   13-09
    "赻隅都蚚統杅91      "  ,   //  463   13-10
    "赻隅都蚚統杅92      "  ,   //  464   13-11
    "赻隅都蚚統杅93      "  ,   //  465   13-12
    "赻隅都蚚統杅94      "  ,   //  466   13-13
    "赻隅都蚚統杅95      "  ,   //  467   13-14
    "赻隅都蚚統杅96      "  ,   //  468   13-15
    "赻隅都蚚統杅97      "  ,   //  469   13-16
    "赻隅都蚚統杅98      "  ,   //  470   13-17
    "赻隅都蚚統杅99      "  ,   //  471   13-18
    "赻隅都蚚統杅100     "  ,   //  471   13-18
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level%   "	,	//	485   14-00	Ids Power Save Level
	"VF CURVE MODE       "	,	//	486   14-01	VF voltage mode selection
	"Overload 1 Mode     "	,	//	487   14-02	Constant Torque Selection
	"Auto ACC/DEC        "	,	//	488   14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	489   14-04	Unit of Acc/Dec time
	"POWER SAVE MODE     "	,	//	490   14-05	Power Save mode
	"Stop Methods        "	,	//	491   14-06	Stop Methods
	"Reverse Operate     "	,	//	492   14-07	Reverse Operation
	"Skip Freq. 1UP  Hz  "	,	//	493   14-08	Skip Freq. Point 1 upper limit
	"Skip Freq. 1LOW Hz  "	,	//	494   14-09	Skip Freq. Point 1 lower limit
	"Skip Freq. 2UP  Hz  "	,	//	495   14-10	Skip Freq. Point 2 upper limit
	"Skip Freq. 2LOW Hz  "	,	//	496   14-11	Skip Freq. Point 2 lower limit
	"Skip Freq. 3UP  Hz  "	,	//	497   14-12	Skip Freq. Point 3 upper limit
	"Skip Freq. 3LOW Hz  "	,	//	498   14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz  "	,	//	499   14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//	500   14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//	501   14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//	502   14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//	503   14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//	504   14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2  Hz  "	,	//	505   14-20	Min Output Freq. 2
	"Min Out-Volt 2  V   "	,	//	506   14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//	507   14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//	508   14-23	up/down key speed
	"Counter Set         "	,	//	509   14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//	510   14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//	511   14-26	LIMIT_SCALE      //[weak 
	"Multi-Fun Input9    "	,	//	512   14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//	513   14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//	514   14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//	515   14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//	516   14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//	517   14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//	518   14-33	External Terminal Run after Fault 
	"ACI/AVI2 SEL        "	,	//	519   14-34	ACI change to AVI2
	"Addition of AI      "	,	//	520   14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//	521   14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//	522   14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//	523   14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//	524   14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//	525   14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//	526   14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//	527   14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//	528   14-43	Multi-Position Point 8
	"Multi-Posit 9       "	,	//	529   14-44	Multi-Position Point 9
	"Multi-Posit 10      "	,	//	530   14-45	Multi-Position Point 10
	"Multi-Posit 11      "	,	//	531   14-46	Multi-Position Point 11
	"Multi-Posit 12      "	,	//	532   14-47	Multi-Position Point 12
	"Multi-Posit 13      "	,	//	533   14-48	Multi-Position Point 13
	"Multi-Posit 14      "	,	//	534   14-49	Multi-Position Point 14
	"Multi-Posit 15      "	,	//	535   14-50	Multi-Position Point 15
	"MOTOR 1 OR 2        "	,	//	536   14-51	Motor Selection 1 or 2
	"Y-D Switch Hz   Hz  "	,	//	537   14-52	Y-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//	538   14-53	Y-Delta switched Enable
	"Motor2 Rated    Amps"	,	//	539   14-54	Motor 2 rated Current
	"Motor2 Rated P  Kw  "	,	//	540   14-55	Motor 2 Rated Power
	"Motor2 Rated    RPM "	,	//	541   14-56	Motor 2 Rated RPM
	"Motor2 Poles        "	,	//	542   14-57	Motor 2 pole No.
	"Motor2 No-Load  Amps"	,	//	543   14-58	Motor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	544   14-59	Motor 2 Rs
	"Motor2 Rr       ohm "	,	//	545   14-60	Motor 2 Rr
	"Motor2 Lm       mH  "	,	//	546   14-61	Motor 2 Lm
	"Motor2 Lx       mH  "	,	//	547   14-62	Motor 2 Lx
	"Y-D On Delay T      "	,	//	548   14-63	Y-Delta On delay time
	"OV stall level  V   "	,	//	549   14-64	OV stall level
	"Thermal RLY2 SEL    "	,	//	550   14-65	Thermal Relay 2 Selection
	"Thermal RLY2 T      "	,	//	551   14-66	Thermal Relay 2 Time
	"Momentary Power     "	,	//	552   14-67	Momentary Power Loss
	"Power Loss Time sec "	,	//	553   14-68	Max. allowable PL time
	"Base Block Time sec "	,	//	554   14-69	BB Time for speed serach
	"SPD Search Curr %   "	,	//	555   14-70	Current level for SPD serach
	"BB Treatment        "	,	//	556   14-71	bb treatment for oc, ov, bb
	"Auto Restart        "	,	//	557   14-72	Auto restart after fault
	"Restart Method      "	,	//	558   14-73	Auto restart Speed serach method
	"DEB Decel SEL       "	,	//	559   14-74	Deceleration at Momertary Power 
	"DEB Return Time     "	,	//	560   14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561   14-76	PID feedback selection	
	"P Gain of PID       "	,	//	562   14-77	P gain of PID	
	"I Gain of PID   sec "	,	//	563   14-78	I gain of PID	
	"D Gain of PID       "	,	//	564   14-79	D gain of PID	
	"Up Limit for I  %   "	,	//	565   14-80	Upper bound for integral	
	"PID Out-Limiter %   "	,	//	566   14-81	PID output Freq. Limit	
	"PID Offset      %   "	,	//	567   14-82	PID offset	
	"PID Out-Filter  sec "	,	//	568   14-83	Derivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	569   14-84	Feedback signal detection time	
	"PID Fdb Loss        "	,	//	570   14-85	PID feedback loss	
	"SLEEP FREQ          "	,	//	571   14-86	Sleep Frequency	
	"WAKE FREQ           "	,	//	572   14-87	Wake up Frequency	
	"SLEEP TIME          "	,	//	573   14-88	Sleep Time	
	"PID DEV. LEVEL  %   "	,	//	574   14-89	PID Deviation Level	
	"PID DEV. TIME       "	,	//	575   14-90	PID Deviation Time	
	"PID Fbk Filter  sec "	,	//	576   14-91	PID feedback filter	
	"Comm Main Freq. Hz  "	,	//	577   14-92	Main Frequency from 
	"Block Trans. 1      "	,	//	578   14-93	Block Transfer 1	
	"Block Trans. 2      "	,	//	579   14-94	Block Transfer 2	
	"Block Trans. 3      "	,	//	580   14-95	Block Transfer 3
	"Block Trans. 4      "	,	//	581   14-96	Block Transfer 4
	"Block Trans. 5      "	,	//	582   14-97	Block Transfer 5
	"Block Trans. 6      "	,	//	583   14-98	Block Transfer 6
	"Block Trans. 7      "	,	//	584   14-99	Block Transfer 7
	"Block Trans. 8      "	,	//	585   14-100 Block Transfer 8
	"Block Trans. 9      "	,	//	586   14-101 Block Transfer 9
	"Block Trans. 10     "	,	//	587   14-102 Block Transfer 10
	"WEAKLPF             "	,	//	588   14-103 WEAKLPF    //[weak magnet, 
	"WEAKTHETA           "	,	//	589   14-104 WEAKTHETA  //[weak magnet, 
	"OVER_SCALE          "	,	//	590   14-105 OVER_SCALE //[weak magnet, 
	"PG Position Home    "	,	//	591   14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592   14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	593   14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	594   14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	595   14-110 FMax Target by Vcommand Position
	"RESERVE             "	,	//	596   14-111 Accel. Time for Position
	"PG Mech. Gear A     "	,	//	597   14-112 PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	598   14-113 PG Mechanical Gear B
	"System Jm       PU  "	,	//	599   14-114 Interia of motor PU
	"M1IdsRef Limit   %  "	,	//	600   14-115 Motor1 IdsRef Limit
	"M2IdsRef Limit   %  "	,	//	601   14-116 Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	602   14-117 Phase Loss Time
	"TH Inside Temp   C  "	,	//	603   14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	604   14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	605   14-120 SVC Slip Generation Compensation 
	"PG-REF COM LPG      "	,	//	606   14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607   14-122 Tension of Torque Control
	"DIAMETER        m   "	,	//	608   14-123 Diameter of Material
	"DEPTH           cm  "	,	//	609   14-124 Depth of meterial
	"RESERVE             "	,	//	610   14-125 Reserve
	"ABZ ST Times        "	,	//	611   14-126 Reserve
	"ABZ ST Duty         "	,	//	612   14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	613   14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	614   14-129 Time of APR Curve
    "Jm source           "  ,   //	615   14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	616   14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	617   14-132 muti input state
    "StandStill Curr.Amps"  ,   //  618   14-133 Standstill Current
	"PG Scale Factor     "	,	//	619   14-134 Division factor of PG	
	"OLD Irate           "	,	//	619   14-135 OLD Irate            // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   //  [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   //  [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time  sec "	,   //  [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   //  [CAN Protocol for High Cap, Bernie, 09/22/2011]   
    "COM1籵捅華硊        "  ,   //  368   09-00 Comm Address                //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                       
    "COM1籵捅換怀厒僅kbps"  ,   //  369   09-01 Tranmission speed                          
    "COM1籵捅渣昫揭燴    "  ,   //  370   09-02 Comm fault Treatment                      
    "COM1貣奀潰堤奀潔sec "  ,   //  371   09-03 Comm Time out                             
    "COM1籵捅跡宒        "  ,   //  372   09-04 Comm Protocol                             
    "COM1砒茼晊奀奀潔ms  "  ,   //  373   09-05 ASC remote Response Delay Time,  
    "OPHL 10Hz COUNT     "  ,   //  3XX   14-146    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "  ,   //  3XX   14-147    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "  ,   //  3XX   14-148    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "  ,   //  3XX   14-149    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,  	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_TR
const string20 prinfo_tur[EPMAX] = {	
/*---- GROUP 15---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"DEBUG FLAG          "	,	//	0   15-00	Debug Flag 1	                                
	"DBC Change Freq.    "	,	//	1   15-01	DBC CHANGE FREQ	                                
	"EFFICIENCY      %   "	,	//	2   15-02	efficiency of Motor	                            
    "ZOffset Tune I  %   "  ,   //    3   15-03   Z Phase search current level                    
	"RATED-I AD VALUE    "	,	//	4   15-04	AD value at Rated Current	                    
	"Ide Iqe LPF Gain    "	,	//	5   15-05	Id*,Iq* LPF	                                    
	"Factory Serial 1    "	,	//	6   15-06	Only for Factory 1	                            
	"Factory Serial 2    "	,	//	7   15-07	Only for Factory 2	                            
	"Factory Serial 3    "	,	//	8   15-08	Only for Factory 3	                            
	"Factory Serial 4    "	,	//	9   15-09	Only for Factory 4	                            
	"REVERSED            "	,	//	10  15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]                
	"Skip DeadTime       "	,	//	11  15-11	Skip Dead Time	                                
	"210.0 VDC AD        "	,	//	12  15-12	DCBUS 210.0 VDC ad value	                    
	"310.0 VDC AD        "	,	//	13  15-13	DCBUS 310.0 VDC ad value	                    
	"390.0 VDC AD        "	,	//	14  15-14	DCBUS 390.0 VDC ad value	                    
	"TRQ_P               "	,	//	15  15-15	Torque control Kp	                            
	"TRQ_I               "	,	//	16  15-16	Torque Control Ki	                            
	"FLUX_P              "	,	//	17  15-17	Flux Control Kp	                                
	"FLUX_I              "	,	//	18  15-18	Flux Control Ki	                                
	"SpdSlop_P           "	,	//	19  15-19	Speed slop Control Kp gain	                    
	"SpdSlop_I           "	,	//	20  15-20	Speed slop Control Ki gain	                    
	"Control Select      "	,	//	21  15-21	Control Selection	                            
	"TEST SOURCE Amp.    "	,	//	22  15-22	Test Source Value Amplitude	                    
	"High Speed LPG  Hz  "	,	//	23  15-23	High Speed Low pass Filter Gain	                
	"Low Speed LPG   Hz  "	,	//	24  15-24	Low Speed Low pass filter Gain	                
	"TEST SOURCE Bias    "	,	//	25  15-25	Test Source Value Bias	                        
	"Est J LPG       s   "	,	//	26  15-26	Estimate J Low pass Filter Gain	                
	"Calibration A RE    "	,	//	27  15-27	Calibration current REF	                        
	"Calibration P       "	,	//	28  15-28	Calibration P	                                
	"Calibration I       "	,	//	29  15-29	Calibration I	                                
	"DC-Tun current P    "	,	//	30  15-30	Auto tuning DC test Kp gain	                    
	"DC-Tun current I    "	,	//	31  15-31	Auto Tuning DC test Ki gain	                    
	"High Freq. Tun P    "	,	//	32  15-32	Auto tuning High Freq. Lock test Kp gain	    
	"High Freq. Tun I    "	,	//	33  15-33	ADcbus Low Pass Gain	                        
	"Gain of VcmpMax %   "	,	//	34  15-34	Select Zero Speed	                            
	"NL-Boost Gain       "	,	//	35  15-35	No Load Boost Gain	                            
	"Auto Accel. KP      "	,	//	36  15-36	Acceleration AKP	                            
	"Auto Accel. KI      "	,	//	37  15-37	Acceleration AKI	                            
	"Current Loop BW     "	,	//	38  15-38	Current Loop BandWidth                          
	"DBC Leading 2       "	,	//	39  15-39	DBC Leading 2                                   
	"DBC Ration 2        "	,	//	40  15-40	DBC Ratio 2 with close loop                     
	"DBC Coef.           "	,	//	41  15-41	DBC Coef.                                       
	"DBC Dcbus Coef.     "	,	//	42  15-42	DBC Dcbus Coef.                                 
	"DBC Leading 1       "	,	//	43  15-43	DBC leading 1                                   
	"DBC Ratio 1         "	,	//	44  15-44	DBC Linear Ratio 1                              
	"RESERVE             "	,	//	45  15-45	DBC MODE                                        
	"Magnitization L1    "	,	//	46  15-46	magnitization inductance 1                      
	"Main Flux Link 1    "	,	//	47  15-47	main flux linkage 1                             
	"Magnitization L2    "	,	//	48  15-48	magnitization inductance 2                      
	"Main Flux Link 2    "	,	//	49  15-49	main flux linkage 2                             
	"Magnitization L3    "	,	//	50  15-50	magnitization inductance 3                      
	"Main Flux Link 3    "	,	//	51  15-51	main flux linkage 3                             
	"Magnitization L4    "	,	//	52  15-52	magnitization inductance 4                      
	"Main Flux Link 4    "	,	//	53  15-53	main flux linkage 4                             
	"Magnitization L5    "	,	//	54  15-54	magnitization inductance 5                      
	"Main Flux Link 5    "	,	//	55  15-55	main flux linkage 5                             
	"Magnitization L6    "	,	//	56  15-56	magnitization inductance 6                      
	"Main Flux Link 6    "	,	//	57  15-57	main flux linkage 6                             
	"Modulation Index    "	,	//	58  15-58	Modulation Index                                
	"Zero Current LPG    "	,	//	59  15-59	Current Zero Low Pass Gain                      
	"COSphi LPF      ms  "	,	//	60  15-60	cos(TB1_uwPhi) low pass gain                          
	"Date Code Y.WKD     "  ,   //  61  15-61   DateCode  //Datecode para change, Henry, 2016/07/20 
	"AUI2 0V ADC     adc "	,	//	62  15-62	calibration for AUI ZeroPoint (0V)
	"AUI2 -10V ADC   adc "	,	//	63  15-63	calibration for AUI2 max (-10V)
	"AUI2 +10V ADC   adc "	,	//	64  15-64	calibration for AUI2 min (+10V)
	"ACI 20mA ADC    adc "	,	//	65  15-65	calibration for ACI2 max (20mA)                 
	"ACI 12mA ADC    adc "	,	//	66  15-66	calibration for ACI mid (12mA)                  
	"ACI 4mA ADC     adc "	,	//	67  15-67	calibration for ACI min (4mA)                   
	"AUI1 0V ADC     adc "	,	//	68  15-68	calibration for AUI1 ZeroPoint (0V)
	"AUI1 -10V ADC   adc "	,	//	69  15-69	calibration for AUI1 max (-10V)
	"AUI1 +10V ADC   adc "	,	//	70  15-70	calibration for AUI1 min (+10V)
	"Auto Decel. DKP     "	,	//	71  15-71	Deceleration DKP                                
	"Auto Decel. DKI     "	,	//	72  15-72	Deceleration DKI                                
	"Low Speed Comp. Hz  "	,	//	73  15-73	more volt. comp. below this freq.               
	"PGLOSS Detcect T    "	,	//	74  15-74	PGLOSS Detect Counter                           
	"Main Frequency      "	,	//	75  15-75	Main Frequency                                  
	"Power On Counter    "	,	//	76  15-76	Power On Counter                                
	"GFF_Pk Detec SW     "	,	//	77  15-77	GFF Maximum Value Record Switch, Jerry Yu, 2019/11/11 
	"BLD  Version        "	,	//	78  15-78   //[BootLoader Version, Special.Kung, 2022/10/31] 
#if SIBO_ENABLE
    "SIBO EPS FRMODE     "  ,   //  79  15-79 SIBO EPS FRMODE
#else
    "RESERVE             "  ,   //  79  15-79
#endif
    "OPHL_SPER           "  ,   //  80  15-80
    "OPHL_CURER          "  ,   //  81  15-81
    "OPHL_ERCNT          "  ,   //  82  15-82
	"BLD DateCode        "  ,   //  83  15-83   //[BootLoader DataCode, Special.Kung, 2022/10/31] 
	"FineAUI 0V ADC  adc "	,	//	84  15-84	calibration for AUI ZeroPoint (0V)              
	"FineAUI +2V ADC adc "	,	//	85  15-85	calibration for AUI max (+2V)                   
	"FineAUI -2V ADC adc "	,	//	86  15-86	calibration for AUI min (-2V)                   
	"SIN MAX V ADC   adc "	,	//	87  15-87	calibration for SIN max, add by dino, 06/01/2007
	"SIN MIN V ADC   adc "	,	//	88  15-88	calibration for SIN min, add by dino, 06/01/2007
	"COS MAX V ADC   adc "	,	//	89  15-89	calibration for COS max, add by dino, 06/01/2007
	"COS MIN V ADC   adc "	,	//	90  15-90	calibration for COS min, add by dino, 06/01/2007
    "Min. Pulse Width    "  ,   //  91  15-91   minimum pulse, ADDED BY SCOTTY,2007/07/11
	"D Frame FAN Cont    "	,	//	92 	15-92	D Frame Fan control
	"Z Phase UVW Sect    "	,	//	93 	15-93	Z phase UVW Section when PG_TYPE = 2
    "                    "  ,   //
    "LAST PG COUNTER     "  ,   //  95  15-95   PG Position Record, add by scotty, 12/07/2007
	"AFM MAX. Value      "	,	//	96 	15-96   AFM max. value
	"AFM MIN. Value      "	,	//	97 	15-97   AFM min. value
	"Soft Start Time sec "	,	//	98  15-98	Softstart Delay Time
	"DEBUG FLAG2         "  ,   //  99  15-99   //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
	"Z-cab Mode          "  ,   //  100
	"Qer_min             "  ,   //  101
	"Qer_Shift           "  ,   //  102
	"Sin_HS_Tab          "  ,   //  103
	"                    "  ,   //  104
	"RESERVE             "	,	//	105 15-105  RESERVED
	"CAN Control         "	,	//	106 15-106  Can Control      //[CAN Control, Sampo, 09/15/2010]
	"CAN Fault Handle    "	,	//	107 15-107  Can Fault Handle //[CAN Control, Sampo, 09/15/2010]
	"DEBUG_PG            "	,	//	108 15-108  DEBUG_PG
	"_47th_DISP          "	,	//	109 15-109  _47th_DISP
	"PG_MODE             "	,	//	110 15-110  RESERVED
	"WDT Divider         "	,	//	111 15-111  WDT_DIV     //[ICT WDT test, Bernie, 08/16/2011]
	"AFM1 +10V CNT       "	,	//	112 15-112  AFM1_P10CNT for AFM1 +10V output
	"AFM1 0V CNT         "	,	//	113 15-113  AFM1_0CNT for AFM1 0V output
	"AFM1 -10V CNT       "	,	//	114 15-114  AFM1_M10CNT for AFM1 -10V output
	"AFM2 +10V CNT       "	,	//	115 15-115  AFM2_P10CNT for AFM2 +10V output
	"AFM2 0V CNT         "	,	//	116 15-116  AFM2_0CNT for AFM2 0V output
	"AFM2 -10V CNT       "	,	//	117 15-117  AFM2_M10CNT for AFM2 -10V output
	"Protect Bit SW      "	,	//	118 15-118  The switch of Protect finction    //[The switch of Protect finction, Bernie, 2015/05/21]
	"OPHL COUNT          "	,	//	119 15-119  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL IRMS           "	,	//	120 15-120  The IRMS value of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL COUNT          "	,	//	121 15-121  The Gain value of Protect finction     //[Output Phase Loss 2, Sampo, 2015/05/21]
	"PPI filter point    "	,	//	122 15-122  RESERVED
	"MBF Recoder         "	,	//	123 15-123  MBF record after power off
	"EoL Cnt Recder H    "	,	//	124 15-124  RESERVED        //[add for UL EoL Verification,Bernie, 2013/04/22]
	"EoL Cnt Recder L    "	,	//	125 15-125  RESERVED	    //[add for UL EoL Verification,Bernie, 2013/04/22]
	"RESERVE             "	,	//	126 15-126  RESERVED
	"Unavailable         "	,	//	127 15-127  RESERVED
//	"PPI filter point    "	,	//	127 15-128  PPI control    //[PPI function, Sampo, 2015/09/08]


/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
    "SurucuKimlikKodu    "	,	//	128 00-00	   Model Type of Drive 
    "Nominal Akim    Amps"	,	//	129 00-01	   Rated Current
    "Parametre Reset     "	,	//	130 00-02	   Parameter Reset
    "Baslangic Ekrani    "	,	//	131 00-03	   Start up Display       //chinese 
    "Kullanici Ekrani    "	,	//	132 00-04	   User Display            //chinese 
    "KullaniciKatsayi    "	,	//	133 00-05	   User Coefficient        //chinese 
    "YazilimVersiyonu    "	,	//	134 00-06	   Software Version
    "Sifre Girisi        "	,	//	135 00-07	   Password Input
    "Sifre Ayarlama      "	,	//	136 00-08	   Password Input
    "Kontrol Metodu      "	,	//	137 00-09	   Control Methods
    "Hiz Birimi          "	,	//	138 00-10	   Velocity Unit Select
    "Cikis Yon Secimi    "	,	//	139 00-11   Change Output Direction, Added by 
    "Tasiyici FrekanskHz "	,	//	140 00-12	   Carry Frequency
    "OtoVoltajDuzenle    "	,	//	141 00-13	   AVR
    "Frekans Kaynagi     "	,	//	142 00-14	   Source of Freq. Command
    "Calisma Kaynagi     "	,	//	143 00-15	   Source of Oper. Command
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"MaxCikisFrekans Hz  "	,	//	144	01-00 Max Output Freq.
	"MotorNomFrekansi    "	,	//	145	01-01 Motor Base Frequency 1
	"MaxCikisGerilim1V   "	,	//	146	01-02 Max Output Voltage
	"Orta Frekans 1-1Hz  "	,	//	147	01-03 Mid Output Freq.1
	"Orta Gerilim 1-1V   "	,	//	148	01-04 Mid Output Voltage 1
	"Orta Frekans 1-2Hz  "	,	//	149	01-05 Mid Output Freq.2
	"Orta Gerilim 1-2V   "	,	//	150	01-06 Mid Output Voltage 2
	"MinCikisFrekans1Hz  "	,	//	151	01-07 Min Output Freq.
	"MinCikisGerilim1V   "	,	//	152	01-08 Min Output Voltage
	"Kalkis Frekansi Hz  "	,	//	153	01-09 Start Frequency
	"FrekansUstLimitiHz  "	,	//	154	01-10 Upper Bound Freq.
	"FrekansAltLimitiHz  "	,	//	155	01-11 Lower Bound Freq.
	"1.HizlanmaSuresisan "	,	//	156	01-12 1st Acceleration time        //chinese 
	"1.Yavaslama Suresan "	,	//	157	01-13 1st Deceleration time       //chinese 
	"2.HizlanmaSuresisan "	,	//	158	01-14 2nd Acceleration time      //chinese 
	"2.Yavaslama Suresan "	,	//	159	01-15 2nd Deceleration time      //chinese 
	"3.HizlanmaSuresisan "	,	//	160	01-16 3rd Acceleration time      //chinese 
	"3.Yavaslama Suresan "	,	//	161	01-17 3rd Deceleration time      //chinese 
	"4.HizlanmaSuresisan "	,	//	162	01-18 4th Acceleration time      //chinese 
	"4.Yavaslama Suresan "	,	//	163	01-19 4th Deceleration time     //chinese 
	"JogHizlanmaSure san "	,	//	164	01-20 JOG Acceleration time
	"JogYavaslamaSuresan "	,	//	165	01-21 JOG Deceleration time
	"Jog Frekansi    Hz  "	,	//	166	01-22 JOG Frequency
	"Rampa1-4GecisFreHz  "	,	//	167	01-23 Transition Frequency ACC1/DEC1 to 
	"S-Egri Zamani 1 san "	,	//	168	01-24 S curve Accel time 1
	"S-Egri Zamani 2 san "	,	//	169	01-25 S curve Accel time 2
	"S-Egri Zamani 3 san "	,	//	170	01-26 S curve Decel time 1
	"S-Egri Zamani 4 san "	,	//	171	01-27 S curve Decel time 2
	"Sifir Hiz Secimi    "	,	//	172	01-28 Select Zero Speed
	"Seviyeleme Hizi Hz  "	,	//	173	01-29 Landing Frequency 
	"S-Egri Zamani 5 san "	,	//	174	01-30 S curve Decel time 3
	"DurusRampaSuresisan "	,	//	175	01-31 Stop Deceleration time	
    "AcilYavasH?z?   m/s "	,	//  1xx 01-32
    "IOD Hold Time   san "	,	//	1xx	01-33   IODHT IO direct hold time   
    "IOD Land Time   san "	,	//	1xx	01-34   IODLT IO direct landing freq
    "CRPLS Jerk lim      "	,	//	1xx	01-35   IODLT IO direct landing time
    "IOD Dec Point   cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "IOD D.Point Ref m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "IODLC Aktif         "	,	//	1xx	01-38   IODLT IO direct DistancE
    "Oto ESD FrekansiHz  "  ,   //  1xx 01-37   IODLT IO direct DistancE
    "ESD YavasSuresi san "	,	//	1xx	01-37   IODLT IO direct DistancE    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105  RESERVED
    "Emergency S3    sec "  ,   //  105 15-105  RESERVED
    "Emergency S4    sec "  ,   //  105 15-105  RESERVED
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/
    "2/3 KabloKontrol    "	,	//	176	02-00 2/3 wire control                
    "DijitalGiris MI1    "	,	//	177	02-01 Multi-Function Input 1          
    "DijitalGiris MI2    "	,	//	178	02-02 Multi-Function Input 2          
    "DijitalGiris MI3    "	,	//	179	02-03 Multi-Function Input 3          
    "DijitalGiris MI4    "	,	//	180	02-04 Multi-Function Input 4          
    "DijitalGiris MI5    "	,	//	181	02-05 Multi-Function Input 5          
    "DijitalGiris MI6    "	,	//	182	02-06 Multi-Function Input 6          
    "DijitalGiris MI7    "	,	//	183	02-07 Multi-Function Input 7          
    "DijitalGiris MI8    "	,	//	184	02-08 Multi-Function Input 8		    
    "DI tepki Suresi san "	,	//	185	02-09 Digital in response time		
    "DI Calisma Yonu     "	,	//	186	02-10 Multi-Function Input Inverse	
    "Role Cikis RLY1     "	,	//	187	02-11 Multi-Function Relay 1		    
    "Role Cikis RLY2     "	,	//	188	02-12 Multi-Function Relay 2		    
    "Role Cikis RLY3     "	,	//	189	02-13 Multi-Function Output 1		    
    "Role Cikis RLY4     "	,	//	190	02-14 Multi-Function Output 2		    
    "DijitalCikis MO1    "	,	//	191	02-15 Multi-Function Output 3		    
    "DijitalCikis MO2    "	,	//	192	02-16 Multi-Function Output 4		    
    "DijitalCikis MO3    "	,	//	193	02-17 Multi-Function Output 5		    
    "DijitalCikis MO4    "	,	//	194	02-18 Multi-Function Output 6		    
    "DijitalCikis MO5    "	,	//	195	02-19 Multi-Function Output 7		    
    "DijitalCikis MO6    "	,	//	196	02-20 Multi-Function Output 8		    
    "DijitalCikis MO7    "	,	//	197	02-21 Multi-Function Output 9		    
    "DijitalCikis MO8    "	,	//	198	02-22 Multi-Function Output 10		    
    "DO Calisma Yonu     "	,	//	199	02-23 Multi-Function Output inverse	
    "SiraliCalismaMod    "  ,   //  200 02-24 Sequence start mode
    "Hedef Frekans 1 Hz  "	,	//	201	02-25 Desired Frequency 1		        
    "HedefFrekanBand1Hz  "	,	//	202	02-26 Band of Desired Frequency 1		
    "Hedef Frekans 2 Hz  "	,	//	203	02-27 Desired Frequency 2		        
    "HedefFrekanBand2Hz  "	,	//	204	02-28 Band of Desired Frequency 2		
    "FrenCekmeGecikmesan "	,	//	205	02-29 Brake Delay Timer at run
    "FrenBirakmaGeciksan "	,	//	206	02-30 Brake Delay Timer at stop
    "KontakCekmeGeciksan "	,	//	207	02-31 Mech Contact Delay Timer run
    "KontakBirakGeciksan "	,	//	208	02-32 Mech Contact Delay Timer stop		
    "AkimAlgiSeviyesi%   "	,	//	209	02-33 Isum Current Output Detect	    
    "Speed Area Set	 Hz  "	,	//	210	02-34 Speed Area
    "Fren TepkiSuresisan "	,	//	211	02-35 Mechanical Brake Checking Time
    "KontakTepkiSure san "	,	//	212 02-36 Magnetic Contactor Checking Time
    "Torque Prove En     "  ,   //  213 02-37 Mechanical Brake Checking Current Enable
    "SCDELAY RUN Timesan "  ,	//	207	02-38 Mech Contact Delay Timer run
    "SCDELAY STP Timesan "  ,	//	208	02-39 Mech Contact Delay Timer stop	
    "LU/LD Fault SEL     "  ,   //  2xx 02-40   LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
    "LU/LD Open Det. sec "  ,   //  2xx 02-41   LD/LD Open Detect Time       //#15977, LULD detect, James, 2021/04/01
    "LU/LD Short Det.sec "  ,   //  2xx 02-42   LD/LD Short Detect Time      //#15977, LULD detect, James, 2021/04/01
	"SPEED-REACH BND Hz  "	,   //  202 02-43   Band of Speed Agree Function  //#18572
    "STO Short Det   sec "  ,   //  2xx 02-44   STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-40   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Hiz Limiti      m/s "  ,   //  2xx 02-41   //[Artemis Add Sensor819 Function/Special/2022/06/06]      

/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AnalogGiris AUI1    "	,	//	214	03-00 AUI1 selection   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "Rezerve             "	,	//	215	03-01 ACI  selection     //[ACI function remove, Bernie, 01/20/2012] 
    "AnalogGiris AUI2    "	,	//	216	03-02 AUI2 selection   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1 Egimi      %   "	,	//	217	03-03 AUI1 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "Rezerve             "	,	//	218	03-04 ACI  input Bias     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2 Egimi      %   "	,	//	219	03-05 AUI2 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1 Egim Modu      "	,	//	220  03-06 AUI1 input Polarity   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "Rezerve             "	,	//	221  03-07 ACI  input Polarity      //[ACI function remove, Bernie, 01/20/2012]
    "AUI2 Egim Modu      "	,	//	222  03-08 AUI2 input Polarity   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1 Kazanc     %   "	,	//	223  03-09 AUI1 input Gain    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "Rezerve             "	,	//	224  03-10 ACI  input Gain     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2 Kazanc     %   "	,	//	225  03-11 AUI2 input Gain    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1FiltreSuresisan "	,	//	226  03-12 Low pass filter of AUI1 input    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "Rezerve             "	,	//	227  03-13 Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2FiltreSuresisan "	,	//	228  03-14 Low pass filter of AUI2 input    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "Rezerve             "	,	//	229  03-15 Loss of ACI     //[ACI function remove, Bernie, 01/20/2012]
    "Rezerve             "  ,   //    230  03-16 RESERVED 
    "Analog Giris AO1    "	,	//	231  03-17 Analong Output 1
    "AO1 Kazanc      %   "	,	//	232  03-18 Analong Output 1 Gain
    "AO1 Ters Yon        "	,	//	233  03-19 AO1 in minus value
    "Analog Giris AO2    "	,	//	234  03-20 Analong Output 2
    "AO2 Kazanc      %   "	,	//	235  03-21 Analong Output 2 Gain
    "AO2 Ters Yon        "	,	//	236  03-22 AO2 in minus value
    "AUI1 Polarite       "	,	//	237  03-23 AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2 Polarite       "	,	//	238  03-24 AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1怀�輶頞�        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
    //"AUI2怀�輶頞�        "	,	//	238  03-26    AUI2 Communciate

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "Coklu Hiz 0     Hz  "	,	//	239 04-00 Multi-Speed 0
    "Coklu Hiz 1     Hz  "	,	//	240 04-01 Multi-Speed 1
    "Coklu Hiz 2     Hz  "	,	//	241 04-02 Multi-Speed 2
    "Coklu Hiz 3     Hz  "	,	//	242 04-03 Multi-Speed 3
    "Coklu Hiz 4     Hz  "	,	//	243 04-04 Multi-Speed 4
    "Coklu Hiz 5     Hz  "	,	//	244 04-05 Multi-Speed 5
    "Coklu Hiz 6     Hz  "	,	//	245 04-06 Multi-Speed 6
    "Coklu Hiz 7     Hz  "	,	//	246 04-07 Multi-Speed 7
    "Coklu Hiz 8     Hz  "	,	//	247 04-08 Multi-Speed 8
    "Coklu Hiz 9     Hz  "	,	//	248 04-09 Multi-Speed 9
    "Coklu Hiz 10    Hz  "	,	//	249 04-10 Multi-Speed 10 
    "Coklu Hiz 11    Hz  "	,	//	250 04-11 Multi-Speed 11
    "Coklu Hiz 12    Hz  "	,	//	251 04-12 Multi-Speed 12
    "Coklu Hiz 13    Hz  "	,	//	252 04-13 Multi-Speed 13
    "Coklu Hiz 14    Hz  "	,	//	253 04-14 Multi-Speed 14
    "Coklu Hiz 15    Hz  "	,	//	254 04-15 Multi-Speed 15
    
    "Kurtarma Hizi   m/s "  ,   //    2xx 04-16
    "Seviyeleme Hizi m/s "  ,   //    2xx 04-17
    "Parka Donus Hizim/s "  ,   //    2xx 04-18
    "Rope Slip Comp. mm  "  ,   //  2xx 04-19 GFC Rope compensation, 2021/03/30
    "TABST0 Durum        "  ,   //    2xx 04-20
    "TABST2 Durum        "  ,   //    2xx 04-21
    "Maksimum Durak      "  ,   //    2xx 04-22
    "Anlik Durak         "  ,   //    2xx 04-23
    "PG Revize PCT   %   "  ,   //    2xx 04-24
    "Sensor Delay Cmpsec "  ,   //    2xx 04-25
    "DLC Gecikmesi   ms  "  ,   //    2xx 04-26
    "Plank Uzunlugu  mm  "  ,   //    2xx 04-27 
    "Anlik Pozisyon Hm   "  ,   //    2xx 04-28
    "Anlik Pozisyon Lmm  "  ,   //    2xx 04-29
    "Anlik PG H          "  ,   //    2xx 04-30 
    "Anlik PG L          "  ,   //    2xx 04-31
    "Plank PG H          "  ,   //    2xx 04-32
    "Plank PG L          "  ,   //    2xx 04-33
    "Sensor PG H         "  ,   //    2xx 04-34
    "Sensor PG L         "  ,   //    2xx 04-35
    "DLC Fonksiyonu      "  ,   //    2xx 04-36
    "PDO Tipi            "  ,   //    2xx 04-37
    "Dec Sw Tol. Gap   mm"  ,   //    2xx 04-38
    "Max Hiz Yuzdesi    %"  ,   //    2xx 04-39 //[ADCO EPS Modify]
    "Spring Extend   mm  "  , //  2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Durumu          "  ,   //    2xx 04-41
    "EST Sayimi          "  ,   //    2xx 04-42
    "TABST0 Sayimi       "  ,   //    2xx 04-43
    "TABST1 Sayimi       "  ,   //    2xx 04-44
    "DDS1/UDS1Spd Limm/s "  ,   //    2XX 04-45  DD1_Vlim  //Artemis speed limit, James, 20200220                          
    "DDS2/UDS2Spd Limm/s "  ,   //    2XX 04-46  DD2_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS3/UDS3Spd Limm/s "  ,   //    2XX 04-47  DD3_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS4/UDS4Spd Limm/s "  ,   //    2XX 04-48  DD4_Vlim  //Artemis speed limit, James, 20200220
    "DLC Kull Sayfasi    "  ,   //    2XX 04-49  user page cahnge
    
    "1F Konum H      m   "  , //  2XX 04-50   1Floor Position H 
    "1F Konum L      mm  "  , //  2XX 04-51   1Floor Position L                                       
    "2F Konum H      m   "  , //  2XX 04-52   2Floor Position H                                       
    "2F Konum L      mm  "  , //  2XX 04-53   2Floor Position L                                       
    "3F Konum H      m   "  , //  2XX 04-54   3Floor Position H                                       
    "3F Konum L      mm  "  , //  2XX 04-55   3Floor Position L                                       
    "4F Konum H      m   "  , //  2XX 04-56   4Floor Position H                                       
    "4F Konum L      mm  "  , //  2XX 04-57   4Floor Position L                                       
    "5F Konum H      m   "  , //  2XX 04-58   5Floor Position H                                       
    "5F Konum L      mm  "  , //  2XX 04-59   5Floor Position L                                       
    "6F Konum H      m   "  , //  2XX 04-60   6Floor Position H                                       
    "6F Konum L      mm  "  , //  2XX 04-61   6Floor Position L                                       
    "7F Konum H      m   "  , //  2XX 04-62   7Floor Position H                                       
    "7F Konum L      mm  "  , //  2XX 04-63   7Floor Position L                                       
    "8F Konum H      m   "  , //  2XX 04-64   8Floor Position H                                       
    "8F Konum L      mm  "  , //  2XX 04-65   8Floor Position L                                       
    "9F Konum H      m   "  , //  2XX 04-66   9Floor Position H                                       
    "9F Konum L      mm  "  , //  2XX 04-67   9Floor Position L                                       
    "10F Konum H     m   "  , //  2XX 04-68   10Floor Position H                                      
    "10F Konum L     mm  "  , //  2XX 04-69   10Floor Position L                                      
    "11F Konum H     m   "  , //  2XX 04-70   11Floor Position H                                      
    "11F Konum L     mm  "  , //  2XX 04-71   11Floor Position L                                      
    "12F Konum H     m   "  , //  2XX 04-72   12Floor Position H                                      
    "12F Konum L     mm  "  , //  2XX 04-73   12Floor Position L                                      
    "13F Konum H     m   "  , //  2XX 04-74   13Floor Position H                                      
    "13F Konum L     mm  "  , //  2XX 04-75   13Floor Position L                                      
    "14F Konum H     m   "  , //  2XX 04-76   14Floor Position H                                      
    "14F Konum L     mm  "  , //  2XX 04-77   14Floor Position L                                      
    "15F Konum H     m   "  , //  2XX 04-78   15Floor Position H                                      
    "15F Konum L     mm  "  , //  2XX 04-79   15Floor Position L                                      
    "16F Konum H     m   "  , //  2XX 04-80   16Floor Position H                                      
    "16F Konum L     mm  "  , //  2XX 04-81   16Floor Position L                                      
    "17F Konum H     m   "  , //  2XX 04-82   17Floor Position H                                      
    "17F Konum L     mm  "  , //  2XX 04-83   17Floor Position L                                      
    "18F Konum H     m   "  , //  2XX 04-84   18Floor Position H                                      
    "18F Konum L     mm  "  , //  2XX 04-85   18Floor Position L                                      
    "19F Konum H     m   "  , //  2XX 04-86   19Floor Position H                                      
    "19F Konum L     mm  "  , //  2XX 04-87   19Floor Position L                                      
    "20F Konum H     m   "  , //  2XX 04-88   20Floor Position H                                      
    "20F Konum L     mm  "  , //  2XX 04-89   20Floor Position L                                      
    "21F Konum H     m   "  , //  2XX 04-90   21Floor Position H                                      
    "21F Konum L     mm  "  , //  2XX 04-91   21Floor Position L                                      
    "22F Konum H     m   "  , //  2XX 04-92   22Floor Position H                                      
    "22F Konum L     mm  "  , //  2XX 04-93   22Floor Position L                                      
    "23F Konum H     m   "  , //  2XX 04-94   23Floor Position H                                      
    "23F Konum L     mm  "  , //  2XX 04-95   23Floor Position L                                      
    "24F Konum H     m   "  , //  2XX 04-96   24Floor Position H                                      
    "24F Konum L     mm  "  , //  2XX 04-97   24Floor Position L                                      
    "25F Konum H     m   "  , //  2XX 04-98   25Floor Position H                                      
    "25F Konum L     mm  "  , //  2XX 04-99   25Floor Position L                                      
        
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM Oto-Tuning       "	,	//	255 05-00 Motor Auto-Tuning
    "IM Motor NomAkimAmp "	,	//	256 05-01 Motor 1 rated Current           
    "IM Motor Nom GuckW  "	,	//	257 05-02 Motor 1 Rated Power             
    "IM MotorNomDevirrpm "	,	//	258 05-03 Motor 1 Rated RPM               
    "IMMotorKutupSayi    "	,	//	259 05-04 Motor 1 pole No.                
    "IMMotorBostaAkimAmp "	,	//	260 05-05 Motor 1 No-Load Current         
    "IM Motor Rs     Ohm "	,	//	261 05-06 Motor 1 Rs                      
    "IM Motor Rr     Ohm "	,	//	262 05-07 Motor 1 Rr                      
    "IM Motor Lm     mH  "	,	//	263 05-08 Motor 1 Lm                      
    "IM Motor Lx     mH  "	,	//	264 05-09 Motor 1 Lx                      
    "Svc Volt. Lpf   san "	,	//	265 05-10 Vector Voltage Filter	        
    "Svc Slip Lpf    san "	,	//	266 05-11 Vector Slip Filter	            
    "Tork Komp Kazanc    "	,	//	267 05-12 Torque Compensation Gain	    
    "Kayma KompKazanc    "	,	//	268 05-13 Slip Compensation Gain	        
    "KaymaSapmaSeviye%   "	,	//	269 05-14 Slip Deviation level	        
    "KaymaSapmaSuresisan "	,	//	270 05-15 Slip Deviation Detect Time	    
    "AsiriKaymaDurumu    "	,	//	271 05-16 Over Slip treatment	            
    "HuntingKatsayisi    "	,	//	272 05-17 Coeff for hunting disable	    
    "Toplam Calisma  Dak "	,	//	273 05-18 Accumulative Motor Operation Min
    "Toplam Calisma  Gun "	,	//	274 05-19 Accumulative Motor Operation Day
    "Core Kayiplar?  %   "	,	//	275 05-20 Coreloss % of output Power	    
    "Enerjide Kalma  Dak "	,	//	276 05-21	 Power On Min
    "Enerjide Kalma  Gun "	,	//	277 05-22	 Power On Day    
    "Gen KaymaKazanci%   "  ,   //    2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"MotorKaymaKazanc%   "	,	//	123 15-123  RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "Dusuk Gerilim   V   "	,	//    278  06-00 Low voltage level
    "Faz Kaybi"	,	//    279  06-01 Phase loss
    "OCA Seviyesi    %   "	,	//	280  06-02 OC stall during Accel
    "OCN Seviyesi    %   "	,	//	281  06-03 OC stall during Decel
    "Stall Accdec Sel    "	,	//	282  06-04 Stall preventation Accel/Decel time selection
    "OL2 Secimi          "	,	//	283  06-05 Over-Torque 1 Selection
    "Asiri TorkSeviye    "	,	//	284  06-06 Over-Torque 1 level
    "Asiri TorkSuresi    "	,	//	285  06-07 Over-Torque 1 Time
    "OL3 Secimi          "	,	//	286  06-08 Over-Torque 2 Selection	                     
    "AsiriYuk3 Seviye    "	,	//	287  06-09 Over-Torque 2 level	                         
    "Asiri Yuk 3 Sure    "	,	//	288  06-10 Over-Torque 2 Time	                         
    "Tork Limiti     %   "	,	//	289  06-11 Current Limit
    "Termik RLY1Secim    "	,	//	290  06-12 Thermal Relay 1 Selection
    "Termik RLY1 Sure    "	,	//	291  06-13 Thermal Relay 1 Time
    "OH Ikaz Seviye  C   "	,	//	292  06-14 OH Warning Level
    "Stall Seviye Lim%   "	,	//	293  06-15 Stall preventation Limit Level
    "1. Hata Kaydi       "	,	//	294  06-16 1st Fault Record
    "2. Hata Kaydi       "	,	//	295  06-17 2nd Fault Record
    "3. Hata Kaydi       "	,	//	296  06-18 3rd Fault Record
    "4. Hata Kaydi       "	,	//	297  06-19 4th Fault Record
    "5. Hata Kaydi       "	,	//	298  06-20 5th Fault Record
    "6. Hata Kaydi       "	,	//	299  06-21 6th Fault Record
    "Hata Opsiyonu 1     "	,	//	300  06-22 Fault Option 1
    "Hata Opsiyonu 2     "	,	//	301  06-23 Fault Option 2
    "Hata Opsiyonu 3     "	,	//	302  06-24 Fault Option 3
    "Hata Opsiyonu 4     "	,	//	303  06-25 Fault Option 4
    "PTC Aksiyonu        "	,	//	304  06-26 PTC over Treatments	                         
    "PTC Seviyesi    %   "	,	//	305  06-27 PTC Level
    "PTCAligilamaSuresan "	,	//	306  06-28 PTC Detect Filter time
    "EPS Gerilimi    V   "	,	//	307  06-29 EPS voltage level
    "Hata Ops Modu       "	,	//	308  06-30 Fault Option Mode
    "Cikis Tespit        "	,	//	309  06-31 Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "1. Hata Zamani  Dak "	,	//	310  06-32 1st Fault Time(MIN)
    "1. Hata Zamani  Gun "	,	//	311  06-33 1st Fault Time(DAY)
    "2. Hata Zamani  Dak "	,	//	312  06-34 2nd Fault Time(MIN)
    "2. Hata Zamani  Gun "	,	//	313  06-35 2nd Fault Time(DAY)
    "3. Hata Zamani  Dak "	,	//	314  06-36 3rd Fault Time(MIN)
    "3. Hata Zamani  Gun "	,	//	315  06-37 3rd Fault Time(DAY)
    "4. Hata Zamani  Dak "	,	//	316  06-38 4th Fault Time(MIN)
    "4. Hata Zamani  Gun "	,	//	317  06-39 4th Fault Time(DAY)
    "5. Hata Zamani  Dak "	,	//	318  06-40 5th Fault Time(MIN)
    "5. Hata Zamani  Gun "	,	//	319  06-41 5th Fault Time(DAY)
    "6. Hata Zamani  Dak "	,	//	320  06-42 6th Fault Time(MIN)
    "6. Hata Zamani  Gun "	,	//	321  06-43 6th Fault Time(DAY)
    "EPS Calisma HiziHz  "  ,   //  322  06-44 EPS Frequency
    "Hata OpsiyonuMODBIN "  ,	//  323  06-45 LV Option Mode
    "EPS Opsiyon Modu    "  ,	//  324  06-46 EPS Option Mode
    "Gen Tarama Sure san "  ,   //  325  06-47 Generation Operation Detected Time
    "UPS Kapasitesi  KVA "  ,   //  326  06-48 UPS Capacity (0.1KVA)
    "STO Kilit Secimi    "  ,   //  3xx  06-49 STO Lock selection     //[Safty function, Bernie]   
    "Tekrar Bas Secim    "  ,   //  356  06-50 Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "Otomatik BaslamaSan "  ,   //  356  06-51 Auto restart times after fault     
    "Oto Baslama Ara San "  ,   //  356  06-52 Auto restart interval
    "KontFrekansKaydiHz  "  ,   //  3xx  06-53 Fkey Record
    "Cikis Frek KaydiHz  "  ,   //  3xx  06-54 Fcmd Record
    "Cikis Akim KaydiAmp "  ,   //  3xx  06-55 Isum Record
    "Motor Frek KaydiHz  "  ,   //  3xx  06-56 Fout Record
    "Cikis Ger Kaydi V   "  ,   //  3xx  06-57 Vout Record
    "DC Bara Kaydi   V   "  ,   //  3xx  06-58 Dcbus Record    
    "Cikis Guc Kaydi kW  "  ,   //  3xx  06-59 Power Record
    "Cikis Tork Kaydi%   "  ,   //  3xx  06-60 Torque Record
    "IGBT Sicak KaydiC   "  ,   //  3xx  06-61 IGBT Temperature Record   
    "DI Durum Kayd?  Hex "  ,   //  3xx  06-62 MFI State Record
    "DO Durum Kayd?  Hex "  ,   //  3xx  06-63 MFO State Record
    "Durum Kaydi     Hex "  ,   //  3xx  06-64 Drive State Record
    "UCMP Akim Limiti%   "  ,   //  3XX  06-65 Current limitation for UCMP function            //[UCMP function, Bernie, 2016/06/14]
    "Servis Zamanlari    "  ,   //  3xx  06-66 Service time count                                   //[Service time function, Bernie, 2017/03/14]
    "Servis Enable       "  ,   //  3xx  06-67 Service time function Enable                       //[Service time function, Bernie, 2017/03/14]
    "EPS Algilama GucFak "  ,   //  3xx  06-68 EPS Detect Current    
    "EPS PF Acisi        "  ,   //  3xx  06-69 EPS Detect Current Ref
    "EPS Calisma Yonu    "  ,   //  3xx  06-70 EPS Detect direction
    "EPS Acma GecikmeSn  "  ,   //  3xx  06-71 EPS MO Off Time
    "EPS Kapama GecikmeSn"  ,   //  3xx  06-72 EPS MO Off Time
    "Calisma Yonu Sayma H"	,   //  3xx  06-73 Running direction count high				
    "Calisma Yonu Sayma L"	,   //  3xx  06-74 Running direction count low
    "Run Dir. Temp   H   "	,   //  3xx  06-75 Temp running direction count high
    "Run Dir. Temp   L   "	,   //  3xx  06-76 Temp running direction count low
    "Temp Count Rst.     "	,   //  3xx  06-77 Temp running reset count
    "Run Limit Level Thou"	,   //  3xx  06-78 Running life
    "Run Count Treat     "	,   //  3xx  06-79 Running function
    "Cikis FrekKaydi1Hz  " ,    //  3xx  06-80 Fcmd Record1
    "DC Bara Kaydi1  V   " ,    //  3xx  06-81 Dcbus Record1
    "Cikis AkimKaydi1Amp " ,    //  3xx  06-82 Isum Record1
    "IGBT SicakKaydi1C   "	,   //  3xx  06-83 IGBT Temperature Record1
    "Cikis FrekKaydi2Hz  " ,    //  3xx  06-84 Fcmd Record2
    "DC Bara Kaydi2  V   " ,    //  3xx  06-85 Dcbus Record2
    "Cikis AkimKaydi2Amp " ,    //  3xx  06-86 Isum Record2
    "IGBT SicakKaydi2C   " ,    //  3xx  06-87 IGBT Temperature Record2
    "Cikis FrekKaydi3Hz  " ,    //  3xx  06-88 Fcmd Record3
    "DC Bara Kaydi3  V   " ,    //  3xx  06-89 Dcbus Record3
    "Cikis AkimKaydi3Amp " ,    //  3xx  06-90 Isum Record3
    "IGBT SicakKaydi3C   " ,    //  3xx  06-91 IGBT Temperature Record3
    "Cikis FrekKaydi4Hz  " ,    //  3xx  06-92 Fcmd Record4
    "DC Bara Kaydi4  V   " ,    //  3xx  06-93 Dcbus Record4
    "Cikis AkimKaydi4Amp " ,    //  3xx  06-94 Isum Record4
    "IGBT SicakKaydi4C   " ,    //  3xx  06-95 IGBT Temperature Record4
    "Cikis FrekKaydi5Hz  " ,    //  3xx  06-96 Fcmd Record5
    "DC Bara Kaydi5  V   " ,    //  3xx  06-97 Dcbus Record5
    "Cikis AkimKaydi5Amp " ,    //  3xx  06-98 Isum Record5
    "IGBT SicakKaydi5C   " ,    //  3xx  06-99 IGBT Temperature Record5
/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "Fren Direnc Sev V   "	,	//	327   07-00 SW Braking Level
    "BK Voltage Hold V   "  ,   //	328   07-01 DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "Start DCI Level %   "	,	//	329   07-02 DCI Current Level    //[DCI Level when stop, Bernie, 05/21/2012]
    "DC Basma Baslamasan "	,	//	330   07-03 DCI Time at Start 
    "DC Basma Durma  sec "	,	//	331   07-04 DCI Time at STOP
    "DC Basma BaslamaHz  "	,	//	332   07-05 DCI Freq. At start
    "DC Basma Kazanc Ki  "	,	//	333   07-06 DCI KI
    "GEAR ACC TIME   sec "	,	//	334   07-07 Gear wait time when acceleration
    "GEAR ACC FREQ   Hz  "	,	//	335   07-08 Gear wait frequency when acceleration
    "GEAR DEC TIME   sec "	,	//	336   07-09 Gear wait time when deceleration
    "GEAR DEC FREQ   Hz  "	,	//	337   07-10 Gear wait frequency when deceleration
    "Sogutma Fani        "	,	//	338   07-11 Fan Control
    "Tork Referansi  %   "	,	//	339   07-12 TQC Reference from RS485
    "Tork Kaynagi        "	,	//	340   07-13 Source of Torque Command
    "Max Tork Seviye %   "	,	//	341   07-14 Torque max. level
    "Tork Kom Filtre sec "	,	//	342   07-15 Torque command filter
    "H?z Limit Secimi    "	,	//	343   07-16 Speed Limit selection
    "Tork Mod +HizLim%   "	,	//	344   07-17 Torque mode positive speed limit
    "Tork Mod -HizLim%   "	,	//	345   07-18 Torque mode negative speed limit
    "TorkOffsetSecimi    "	,	//	346   07-19 Torque offset selection
    "TorkOffsetSeviye%   "	,	//	347   07-20 Torque offset setting level
    "Tork Offset Ust %   "	,	//	348   07-21 Torque offset setting level High
    "Tork Offset Orta%   "	,	//	349   07-22 Torque offset setting level Middle
    "Tork Offset Alt %   "	,	//	350   07-23 Torque offset setting level Low
    "FWD MotorTorkLim%   "	,	//	351   07-24 FWD Motoring Tq Limit
    "FWD RejenTorkLim%   "	,	//	352   07-25 FWD Regeneration Tq Limit
    "REV MotorTorkLim%   "	,	//	353   07-26 REV Motoring Tq Limit
    "REV RejenTorkLim%   "	,	//	354   07-27 REV Regeneration Tq Limit
    "Acil Stop Durus     "	,	//	355   07-28 Emergency Stop & Forced Stop selection
    "Tork Yavas Zamansan "	,	//	356   07-29 Torque Decrease Time
    "Durma DCI Seviye    "  ,   //  356   07-30 STOP DC Inject Level       //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  357   07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect         "  ,   //  358   07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Distance    ppr"  ,   //  359   07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect Time sec"  ,   //  360   07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Fail Torq      "  ,   //  361   07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Min Torq       "  ,   //  362   07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Max Torq       "  ,   //  362   07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM Oto-Tuning       "	,	//	357   08-00 PMotor Auto-Tuning  
    "PM Motor NomAkimAmp "	,	//	358   08-01 PMotor rated Current
    "PM Motor Nom GuckW  "	,	//	359   08-02 PMotor Rated Power  
    "PM MotorNomDevirrpm "	,	//	360   08-03 PMotor Rated RPM    
    "PMMotorKutupSayi    "	,	//	361   08-04 PMotor pole No.     
    "PM Motor Rs     Ohm "	,	//	362   08-05 PMotor Rs           
    "Reverse             "	,	//	363   08-06 PMotor Ld           
    "Pm Motor Lq     Mh  "	,	//	364   08-07 PMotor Lq           
    "Geri EMF        Vrms"	,	//	365   08-08 PMotor Bemf coff	
    "Z-Offset Acisi  der "	,	//	366   08-09 PM Z-pulse offset angle, 0.1 degree, dino
    "PositionDuzeltme    "	,	//	367   08-10 //ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "VFD HaberAdresi     "	,	//	368   09-06 Comm Address                              
    "Com Baud Rate  Kbps "	,	//	369   09-07 Tranmission speed                         
    "Com Fault Treatment "	,	//	370   09-08 Comm fault Treatment                      
    "Com Time Out    Sec "	,	//	371   09-09 Comm Time out                             
    "Com Protocol        "	,	//	372   09-10 Comm Protocol                             
    "Response Delay  Tms "	,	//	373   09-11 ASC remote Response Delay Time, 1=100us   
    "Can_Buard           "	,   //  3XX   09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "Pdo_Tx_Time     Ms  "	,   //  3XX   09-07    CAN PDO Handshaking Period
    "Can_Check_Time  Ms  "	,   //  3XX   09-08    CAN Communiction Timeout	
    "Asansor ID Kodu     "  ,   //  3XX   09-09 
    "Fhm Register        "  ,   //  3XX   09-10   
    "Dlc Register 1      "  ,   //  3XX   09-11   
    "Dlc Register 2      "  ,   //  3XX   09-12    
    "Dlc Register 3      "  ,   //  3XX   09-13   
	"Pdo Txtime      Ms  "	,	//	3XX   09-14  CAN fail rate---aevin 6/12/2017

/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"Enkoder Tipi        "	,	//	374   10-00 Encoder TYPE                             
	"EnkoderPulseSayi    "	,	//	375   10-01 Encoder pulses	                    
	"EnkoderGirisAyar    "	,	//	376   10-02 PG input setting	                
	"Enkoder Hata Dur    "	,	//	377   10-03 PG fbk fault treatment	            
	"Enkoder HataSure    "	,	//	378   10-04 PG fbk Error Detection Time	        
	"Enkoder Hata Sev    "	,	//	379   10-05 PG fbk overspeed detection level	
	"Asiri Hiz Seviye%   "	,	//	380   10-06 Over speed Detection Time	        
	"EnkoderSapma Sev    "	,	//	381   10-07 PG fbk speed deviation level	    
	"SapmaAlg.Suresi san "	,	//	382   10-08 Deviation Detect Time	            
	"Asiri Hiz Durumu    "	,	//	383   10-09 Operation at overspeed	            
	"Hall Giris Tipi     "  ,   //    384   10-10 Hall Input Types
	"Zero SPD Loop Kp%   "	,	//	385   10-11 KP gain of ASR in Zero speed	
	"Zero SPD Loop Kisan "	,	//	386   10-12 Ki gain of ASR in Zero speed	
	"Low SPD Loop Kp %   "	,	//	387   10-13 ASR P Gain 1	                
	"Low SPD Loop Ki san "	,	//	388   10-14 ASR I Gain 1	                
	"High SPD Loop Kp%   "	,	//	389   10-15 ASR P Gain 2	                
	"High SPD Loop Kisan "	,	//	390   10-16 ASR I Gain 2	                
	"ASR1/2 Switch F Hz  "	,	//	391   10-17 ASR1/ASR2 switch freq	        
	"Primary LPG     san "	,	//	392   10-18 Primary LowPass filter Gain 
	"Position Loop Kp%   "  ,	//	393   10-19 position control Kp Gain  
    "Low SPD Slope   Hz  "  ,   //    394   10-20 Low Spd band
    "High SPD Slope  Hz  "  ,   //    395   10-21 High Spd band
	"POS CONT Time   san "	,	//	396   10-22 Position control time
	"POS CONT LPG    san "	,	//	397   10-23 Position control LOW POSS FILTER
	"Source of POS       "	,	//	398   10-24 Source of position control, add by dino, 
	"Zero SPD Land Kp%   "	,	//	399   10-25 KP gain of ASR in Zero speed of 
	"Zero SPD Land Kisan "	,	//	400   10-26 Ki gain of ASR in Zero speed of Landing
	"Position SPD Kp %   "	,	//	385   10-27 KP gain of ASR in Zero speed during 
	"Position SPD Ki san "	,	//	386   10-28 Ki gain of ASR in Zero speed during 
    "PG KardFrekBolme    "	,   //    4xx   10-29   PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG Kard Modu        "	,   //    4xx   10-30   PG Card Mode setting                      //[DCI Level when stop, Bernie, 05/21/2012]    
    "PG C+/C- Tipi       "  ,   //  110 15-110  RESERVED     //[change parameter to normal group, Bernie, 2014/02/14]
    "AsiriHizlanSev  m/s2"  ,   //    3XX  10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "AsiriHizlanTespisan "  ,   //    3XX  10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "AsiriHizlan Ayar    "  ,   //    3XX  10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "Sistem Kontrol      "	,	//	401   11-00 system control bit0:auto, bit1:Jm tunning, 
    "Fmax Spd        m/s "  ,   //    402   11-01 Lift operation speed                                        
    "Kasnak Cap          "  ,   //    403   11-02 SHEAVE diameter		                
    "Mek Disli Oran      "  ,   //    404   11-03 Gear Ratio                                              
    "Suspansiyon Oran    "  ,   //    405   11-04 Suspension ratio	                                        
    "Atalet Orani    %   "  ,   //    406   11-05 inertia	percent		                  
    "0 Hiz Bant Gen  Hz  "	,	//	407   11-06 Zero Speed Loop BandWidth	                                
    "DusukHizBantGen Hz  "	,	//	408   11-07 Speed Loop BandWidth1		                                
    "YuksekHizBantGenHz  "	,	//	409   11-08 Speed Loop BandWidth2		                                
    "SPD Loop Kr     %   "	,	//	410   11-09 PDFFKr		                                                
    "SPD FFD GAIN    %   "	,	//	411   11-10 SPEED FFD GAIN		                    
    "Netch Deep      db  "	,	//	412   11-11 Netch filter deep(db)	                                    
    "Netch Freq.     Hz  "	,	//	413   11-12 Netch filter frequency	                                    
    "LPF for display san "	,	//	414   11-13 Low Pass Filter for display	                                
    "MaksHizlan Akimi%   "	,	//	415   11-14 ACC Max current                                             
    "Kabin Hizlanma  m/s "  ,	//	416   11-15 max meter/sec	                                            
    "Disp address    Hex "  ,   //	417   11-16 Display address,add by dino 2007/03/08                      
    "Disp data           "  ,	//	418   11-17 Display data,   add by dino 2007/03/08                      
    "Koruma Biti         "  ,   //    419   11-18 Protect Bit	                                                
    "Zero SP Land BW Hz  "	,	//	420   11-19 Zero Speed Loop BandWidth of Landing  
    "PWM Modu            "  ,   //  4XX   11-20 PWM Mode selection  PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LPF for LC01    sec "	,	//	422   11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Motor SPD RPM       "  ,   //  420   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]
/*---- GROUP 12-----------------------------------------*/
/*	"12345678901234561234"	*/
	"UMAP_ADD0			 "	,	//	421   12-00
	"UMAP_ADD1			 "	,	//	422   12-01
	"UMAP_ADD2			 "	,	//	423   12-02
	"UMAP_ADD3			 "	,	//	424   12-33
	"UMAP_ADD4			 "	,	//	425   12-04
	"UMAP_ADD5			 "	,	//	426   12-05
	"UMAP_ADD6			 "	,	//	427   12-06
	"UMAP_ADD7			 "	,	//	428   12-07
	"UMAP_ADD8			 "	,	//	429   12-08
	"UMAP_ADD9			 "	,	//	430   12-09
	"UMAP_ADD10 		 "	,	//	431   12-10
	"UMAP_ADD11 		 "	,	//	432   12-11
	"UMAP_ADD12 		 "	,	//	433   12-12
	"UMAP_ADD13 		 "	,	//	434   12-13
	"UMAP_ADD14 		 "	,	//	435   12-14
	"UMAP_ADD15 		 "	,	//	436   12-15
	"UMAP_ADD16 		 "	,	//	437   12-16
	"UMAP_ADD17 		 "	,	//	438   12-17
	"UMAP_ADD18 		 "	,	//	439   12-18
	"UMAP_ADD19 		 "	,	//	440   12-19 
	"UMAP_ADD20 		 "	,	//	441   12-20
	"UMAP_ADD21 		 "	,	//	442   12-21
	"UMAP_ADD22 		 "	,	//	443   12-22
	"UMAP_ADD23 		 "	,	//	444   12-23
	"UMAP_ADD24 		 "	,	//	445   12-24
	"UMAP_ADD25 		 "	,	//	446   12-25
	"UMAP_ADD26 		 "	,	//	447   12-26
	"UMAP_ADD27 		 "	,	//	448   12-27
	"UMAP_ADD28 		 "	,	//	449   12-28
	"UMAP_ADD29 		 "	,	//	450   12-29
	"UMAP_ADD30 		 "	,	//	451   12-30
	"UMAP_ADD31 		 "	,	//	452   12-31
    "UMAP_ADD32          "  ,   //  423   12-02
    "UMAP_ADD33          "  ,   //  424   12-33
    "UMAP_ADD34          "  ,   //  425   12-04
    "UMAP_ADD35          "  ,   //  426   12-05
    "UMAP_ADD36          "  ,   //  427   12-06
    "UMAP_ADD37          "  ,   //  428   12-07
    "UMAP_ADD38          "  ,   //  429   12-08
    "UMAP_ADD39          "  ,   //  430   12-09
    "UMAP_ADD40          "  ,   //  421   12-00
    "UMAP_ADD41          "  ,   //  422   12-01
    "UMAP_ADD42          "  ,   //  423   12-02
    "UMAP_ADD43          "  ,   //  424   12-33
    "UMAP_ADD44          "  ,   //  425   12-04
    "UMAP_ADD45          "  ,   //  426   12-05
    "UMAP_ADD46          "  ,   //  427   12-06
    "UMAP_ADD47          "  ,   //  428   12-07
    "UMAP_ADD48          "  ,   //  429   12-08
    "UMAP_ADD49          "  ,   //  430   12-09
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
/*---- GROUP 13------------------------------------------*/
/*	"12345678901234561234"	*/
	"UMAP_DATA0 		 "	,	//	453   13-00
	"UMAP_DATA1 		 "	,	//	454   13-01
	"UMAP_DATA2 		 "	,	//	455   13-02
	"UMAP_DATA3 		 "	,	//	456   13-33
	"UMAP_DATA4 		 "	,	//	457   13-04
	"UMAP_DATA5 		 "	,	//	458   13-05
	"UMAP_DATA6 		 "	,	//	459   13-06
	"UMAP_DATA7 		 "	,	//	460   13-07
	"UMAP_DATA8 		 "	,	//	461   13-08
	"UMAP_DATA9 		 "	,	//	462   13-09
	"UMAP_DATA10		 "	,	//	463   13-10
	"UMAP_DATA11		 "	,	//	464   13-11
	"UMAP_DATA12		 "	,	//	465   13-12
	"UMAP_DATA13		 "	,	//	466   13-13
	"UMAP_DATA14		 "	,	//	467   13-14
	"UMAP_DATA15		 "	,	//	468   13-15
	"UMAP_DATA16		 "	,	//	469   13-16
	"UMAP_DATA17		 "	,	//	470   13-17
	"UMAP_DATA18		 "	,	//	471   13-18
	"UMAP_DATA19		 "	,	//	472   13-19
	"UMAP_DATA20		 "	,	//	473   13-20
	"UMAP_DATA21		 "	,	//	474   13-21
	"UMAP_DATA22		 "	,	//	475   13-22
	"UMAP_DATA23		 "	,	//	476   13-23
	"UMAP_DATA24		 "	,	//	477   13-24
	"UMAP_DATA25		 "	,	//	478   13-25
	"UMAP_DATA26		 "	,	//	479   13-26
	"UMAP_DATA27		 "	,	//	480   13-27
	"UMAP_DATA28		 "	,	//	481   13-28
	"UMAP_DATA29		 "	,	//	482   13-29
	"UMAP_DATA30		 "	,	//	483   13-30
	"UMAP_DATA31		 "	,	//	484   13-31
    "UMAP_DATA32         "  ,   //  455   13-02
    "UMAP_DATA33         "  ,   //  456   13-33
    "UMAP_DATA34         "  ,   //  457   13-04
    "UMAP_DATA35         "  ,   //  458   13-05
    "UMAP_DATA36         "  ,   //  459   13-06
    "UMAP_DATA37         "  ,   //  460   13-07
    "UMAP_DATA38         "  ,   //  461   13-08
    "UMAP_DATA39         "  ,   //  462   13-09
    "UMAP_DATA40         "  ,   //  453   13-00
    "UMAP_DATA41         "  ,   //  454   13-01
    "UMAP_DATA42         "  ,   //  455   13-02
    "UMAP_DATA43         "  ,   //  456   13-33
    "UMAP_DATA44         "  ,   //  457   13-04
    "UMAP_DATA45         "  ,   //  458   13-05
    "UMAP_DATA46         "  ,   //  459   13-06
    "UMAP_DATA47         "  ,   //  460   13-07
    "UMAP_DATA48         "  ,   //  461   13-08
    "UMAP_DATA49         "  ,   //  462   13-09
    "UMAP_DATA50         "  ,   //  453   13-00
    "UMAP_DATA51         "  ,   //  454   13-01
    "UMAP_DATA52         "  ,   //  455   13-02
    "UMAP_DATA53         "  ,   //  456   13-33
    "UMAP_DATA54         "  ,   //  457   13-04
    "UMAP_DATA55         "  ,   //  458   13-05
    "UMAP_DATA56         "  ,   //  459   13-06
    "UMAP_DATA57         "  ,   //  460   13-07
    "UMAP_DATA58         "  ,   //  461   13-08
    "UMAP_DATA59         "  ,   //  462   13-09
    "UMAP_DATA60         "  ,   //  453   13-00
    "UMAP_DATA61         "  ,   //  454   13-01
    "UMAP_DATA62         "  ,   //  455   13-02
    "UMAP_DATA63         "  ,   //  456   13-33
    "UMAP_DATA64         "  ,   //  457   13-04
    "UMAP_DATA65         "  ,   //  458   13-05
    "UMAP_DATA66         "  ,   //  459   13-06
    "UMAP_DATA67         "  ,   //  460   13-07
    "UMAP_DATA68         "  ,   //  461   13-08
    "UMAP_DATA69         "  ,   //  462   13-09
    "UMAP_DATA70         "  ,   //  453   13-00
    "UMAP_DATA71         "  ,   //  454   13-01
    "UMAP_DATA72         "  ,   //  455   13-02
    "UMAP_DATA73         "  ,   //  456   13-33
    "UMAP_DATA74         "  ,   //  457   13-04
    "UMAP_DATA75         "  ,   //  458   13-05
    "UMAP_DATA76         "  ,   //  459   13-06
    "UMAP_DATA77         "  ,   //  460   13-07
    "UMAP_DATA78         "  ,   //  461   13-08
    "UMAP_DATA79         "  ,   //  462   13-09
    "UMAP_DATA80         "  ,   //  453   13-00
    "UMAP_DATA81         "  ,   //  454   13-01
    "UMAP_DATA82         "  ,   //  455   13-02
    "UMAP_DATA83         "  ,   //  456   13-33
    "UMAP_DATA84         "  ,   //  457   13-04
    "UMAP_DATA85         "  ,   //  458   13-05
    "UMAP_DATA86         "  ,   //  459   13-06
    "UMAP_DATA87         "  ,   //  460   13-07
    "UMAP_DATA88         "  ,   //  461   13-08
    "UMAP_DATA89         "  ,   //  462   13-09
    "UMAP_DATA90         "  ,   //  453   13-00
    "UMAP_DATA91         "  ,   //  454   13-01
    "UMAP_DATA92         "  ,   //  455   13-02
    "UMAP_DATA93         "  ,   //  456   13-33
    "UMAP_DATA94         "  ,   //  457   13-04
    "UMAP_DATA95         "  ,   //  458   13-05
    "UMAP_DATA96         "  ,   //  459   13-06
    "UMAP_DATA97         "  ,   //  460   13-07
    "UMAP_DATA98         "  ,   //  461   13-08
    "UMAP_DATA99         "  ,   //  462   13-09
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level   %"	,	//	485   14-00	Ids Power Save Level
	"VF Egri Modu        "	,	//	486   14-01	VF voltage mode selection
	"Asiri Yuk 1 Modu    "	,	//	487   14-02	Constant Torque Selection
	"Oto ACC/DEC         "	,	//	488   14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	489   14-04	Unit of Acc/Dec time
	"Enerji Tas Modu     "	,	//	490   14-05	Power Save mode
	"Durma Metodu        "	,	//	491   14-06	Stop Methods
	"Ters Yone Donus     "	,	//	492   14-07	Reverse Operation
	"Atlama Frek1 Ust    "	,	//	493   14-08	Skip Freq. Point 1 upper limit
	"Atlama Frek1 Alt    "	,	//	494   14-09	Skip Freq. Point 1 lower limit
	"Atlama Frek2 Ust    "	,	//	495   14-10	Skip Freq. Point 2 upper limit
	"Atlama Frek2 Alt    "	,	//	496   14-11	Skip Freq. Point 2 lower limit
	"Atlama Frek3 Ust    "	,	//	497   14-12	Skip Freq. Point 3 upper limit
	"Atlama Frek3 Alt    "	,	//	498   14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz	 "	,	//	499   14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//	500   14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//	501   14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//	502   14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//	503   14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//	504   14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2	 Hz  "	,	//	505   14-20	Min Output Freq. 2
	"Min Out-Volt 2	 V   "	,	//	506   14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//	507   14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//	508   14-23	up/down key speed
	"Counter Set         "	,	//	509   14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//	510   14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//	511   14-26	LIMIT_SCALE      //[weak 
	"Multi-Fun Input9    "	,	//	512   14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//	513   14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//	514   14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//	515   14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//	516   14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//	517   14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//	518   14-33	External Terminal Run after Fault 
	"ACI/AVI2 SEL        "	,	//	519   14-34	ACI change to AVI2
	"Addition of AI      "	,	//	520   14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//	521   14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//	522   14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//	523   14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//	524   14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//	525   14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//	526   14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//	527   14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//	528   14-43	Multi-Position Point 8
	"Multi-Posit 9       "	,	//	529   14-44	Multi-Position Point 9
	"Multi-Posit 10      "	,	//	530   14-45	Multi-Position Point 10
	"Multi-Posit 11      "	,	//	531   14-46	Multi-Position Point 11
	"Multi-Posit 12      "	,	//	532   14-47	Multi-Position Point 12
	"Multi-Posit 13      "	,	//	533   14-48	Multi-Position Point 13
	"Multi-Posit 14      "	,	//	534   14-49	Multi-Position Point 14
	"Multi-Posit 15      "	,	//	535   14-50	Multi-Position Point 15
	"MOTOR 1 OR 2        "	,	//	536   14-51	Motor Selection 1 or 2
	"Y-D Switch Hz	 Hz  "	,	//	537   14-52	Y-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//	538   14-53	Y-Delta switched Enable
	"Motor2 Rated    Amps"	,	//	539   14-54	Motor 2 rated Current
	"Motor2 Rated P	 Kw  "	,	//	540   14-55	Motor 2 Rated Power
	"Motor2 Rated    RPM "	,	//	541   14-56	Motor 2 Rated RPM
	"Motor2 Poles        "	,	//	542   14-57	Motor 2 pole No.
	"Motor2 No-Load	 Amps"	,	//	543   14-58	Motor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	544   14-59	Motor 2 Rs
	"Motor2 Rr       ohm "	,	//	545   14-60	Motor 2 Rr
	"Motor2 Lm		 mH  "	,	//	546   14-61	Motor 2 Lm
	"Motor2 Lx       mH  "	,	//	547   14-62	Motor 2 Lx
	"Y-D On Delay    T   "	,	//	548   14-63	Y-Delta On delay time
	"OV stall level	 V   "	,	//	549   14-64	OV stall level
	"Thermal RLY2 SEL    "	,	//	550   14-65	Thermal Relay 2 Selection
	"Thermal RLY2    T   "	,	//	551   14-66	Thermal Relay 2 Time
	"Momentary Power     "	,	//	552   14-67	Momentary Power Loss
	"Power Loss Time sec "	,	//	553   14-68	Max. allowable PL time
	"Base Block Time sec "	,	//	554   14-69	BB Time for speed serach
	"SPD Search Curr %	 "	,	//	555   14-70	Current level for SPD serach
	"BB Treatment        "	,	//	556   14-71	bb treatment for oc, ov, bb
	"Auto Restart        "	,	//	557   14-72	Auto restart after fault
	"Restart Method      "	,	//	558   14-73	Auto restart Speed serach method
	"DEB Decel SEL       "	,	//	559   14-74	Deceleration at Momertary Power 
	"DEB Return Time     "	,	//	560   14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561   14-76	PID feedback selection	
	"P Gain of PID       "	,	//	562   14-77	P gain of PID	
	"I Gain of PID   sec "	,	//	563   14-78	I gain of PID	
	"D Gain of PID       "	,	//	564   14-79	D gain of PID	
	"Up Limit for I	 %   "	,	//	565   14-80	Upper bound for integral	
	"PID Out-Limiter %   "	,	//	566   14-81	PID output Freq. Limit	
	"PID Offset      %   "	,	//	567   14-82	PID offset	
	"PID Out-Filter	 sec "	,	//	568   14-83	Derivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	569   14-84	Feedback signal detection time	
	"PID Fdb Loss        "	,	//	570   14-85	PID feedback loss	
	"SLEEP FREQ          "	,	//	571   14-86	Sleep Frequency	
	"WAKE FREQ           "	,	//	572   14-87	Wake up Frequency	
	"SLEEP TIME          "	,	//	573   14-88	Sleep Time	
	"PID DEV. LEVEL	 %   "	,	//	574   14-89	PID Deviation Level	
	"PID DEV. TIME       "	,	//	575   14-90	PID Deviation Time	
	"PID Fbk Filter	 sec "	,	//	576   14-91	PID feedback filter	
	"Comm Main Freq. Hz	 "	,	//	577   14-92	Main Frequency from 
	"Block Trans. 1      "	,	//	578   14-93	Block Transfer 1	
	"Block Trans. 2      "	,	//	579   14-94	Block Transfer 2	
	"Block Trans. 3      "	,	//	580   14-95	Block Transfer 3
	"Block Trans. 4      "	,	//	581   14-96	Block Transfer 4
	"Block Trans. 5      "	,	//	582   14-97	Block Transfer 5
	"Block Trans. 6      "	,	//	583   14-98	Block Transfer 6
	"Block Trans. 7      "	,	//	584   14-99	Block Transfer 7
	"Block Trans. 8      "	,	//	585   14-100 Block Transfer 8
	"Block Trans. 9      "	,	//	586   14-101 Block Transfer 9
	"Block Trans. 10     "	,	//	587   14-102 Block Transfer 10
	"WEAKLPF             "	,	//	588   14-103 WEAKLPF    //[weak magnet, 
	"WEAKTHETA           "	,	//	589   14-104 WEAKTHETA  //[weak magnet, 
	"OVER_SCALE          "	,	//	590   14-105 OVER_SCALE //[weak magnet, 
	"PG Position Home    "	,	//	591   14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592   14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	593   14-108 Gain of APR feedforward
	"APR Decel Time	 sec "	,	//	594   14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz	 "	,	//	595   14-110 FMax Target by Vcommand Position
	"RESERVE             "	,	//	596   14-111 Accel. Time for Position
	"PG Mech. Gear A     "	,	//	597   14-112 PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	598   14-113 PG Mechanical Gear B
	"System Jm		 PU  "	,	//	599   14-114 Interia of motor PU
	"M1IdsRef Limit	 %   "	,	//	600   14-115 Motor1 IdsRef Limit
	"M2IdsRef Limit	 %   "	,	//	601   14-116 Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	602   14-117 Phase Loss Time
	"TH Inside Temp	 C   "	,	//	603   14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	604   14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	605   14-120 SVC Slip Generation Compensation 
	"PG-REF COM LPG      "	,	//	606   14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607   14-122 Tension of Torque Control
	"DIAMETER        m   "	,	//	608   14-123 Diameter of Material
	"DEPTH           cm	 "	,	//	609   14-124 Depth of meterial
	"RESERVE             "	,	//	610   14-125 Reserve
	"ABZ ST Times        "	,	//	611   14-126 Reserve
	"ABZ ST Duty         "	,	//	612   14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	613   14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	614   14-129 Time of APR Curve
    "Jm source           "  ,   //	615   14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	616   14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	617   14-132 muti input state
    "StandStill Curr.Amps"  ,   //  618   14-133 Standstill Current
	"PG Scale Factor     "	,	//	619   14-134 Division factor of PG	
	"OLD Irate           "	,	//	619   14-135 OLD Irate            // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   //  [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   //  [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time	 sec "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011]   
    "VFD Com1 Address    "  ,   //  368   09-00 Comm Address                //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                       
    "COM1 Baud Rate	 kbps"  ,   //  369   09-01 Tranmission speed                          
    "COM1 Fault Treat    "  ,   //  370   09-02 Comm fault Treatment                      
    "COM1 Time Out   sec "  ,   //  371   09-03 Comm Time out                             
    "COM1 Protocol       "  ,   //  372   09-04 Comm Protocol                             
    "COM1 Delay Time ms	 "  ,   //  373   09-05 ASC remote Response Delay Time,  
    "OPHL 10Hz COUNT     "  ,   //  3XX   14-146    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "  ,   //  3XX   14-147    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "  ,   //  3XX   14-148    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "  ,   //  3XX   14-149    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,   //  3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 3       "  ,  	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_RUS
const string20 prinfo_rus_ACC_ms2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"耜殍蝁筊雎楉m/s2"	,	//	156	01-12	1st Acceleration time
	"耜殍豝喿婤殎.1m/s2"	,	//	157	01-13	1st Deceleration time
	"耜殍蝁筊雎楉m/s2"	,	//	158	01-14	2nd Acceleration time
	"耜殍豝喿婤殎.2m/s2"	,	//	159	01-15	2nd Deceleration time
	"耜殍蝁筊雎楉m/s2"	,	//	160	01-16	3rd Acceleration time
	"耜殍豝喿婤殎.3m/s2"	,	//	161	01-17	3rd Deceleration time
	"耜殍蝁筊雎楉m/s2"	,	//	162	01-18	4th Acceleration time
	"耜殍豝喿婤殎.4m/s2"	,	//	163	01-19	4th Deceleration time
	"耜殍蝁筊 JOGm/s2"	,	//	164	01-20	JOG Acceleration time
	"耜殍豝喿婤.JOGm/s2"	,	//	165	01-21	JOG Deceleration time
	"耜殍睙瑱棰眓  m/s2"	,	//	175	01-31	Stop Deceleration time
};

const string20 prinfo_rus_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"耜殍蝁筊雎楉f/s2"	,	//	156	01-12	1st Acceleration time
	"耜殍豝喿婤殎.1f/s2"	,	//	157	01-13	1st Deceleration time
	"耜殍蝁筊雎楉f/s2"	,	//	158	01-14	2nd Acceleration time
	"耜殍豝喿婤殎.2f/s2"	,	//	159	01-15	2nd Deceleration time
	"耜殍蝁筊雎楉f/s2"	,	//	160	01-16	3rd Acceleration time
	"耜殍豝喿婤殎.3f/s2"	,	//	161	01-17	3rd Deceleration time
	"耜殍蝁筊雎楉f/s2"	,	//	162	01-18	4th Acceleration time
	"耜殍豝喿婤殎.4f/s2"	,	//	163	01-19	4th Deceleration time
	"耜殍蝁筊 JOGf/s2"	,	//	164	01-20	JOG Acceleration time
	"耜殍豝喿婤.JOGf/s2"	,	//	165	01-21	JOG Deceleration time
	"耜殍睙瑱棰眓  f/s2"
};

const string20 prinfo_rus_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S 筄寋厞 1      m/s3"	,	//	168	01-24	S curve Accel time 1
	"S 筄寋厞 2      m/s3"	,	//	169	01-25	S curve Accel time 2
	"S 筄寋厞 3      m/s3"	,	//	170	01-26	S curve Decel time 1
	"S 筄寋厞 4      m/s3"	,	//	171	01-27	S curve Decel time 2
	"S 筄寋厞 5      m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_rus_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S 筄寋厞 1      f/s3"	,	//	168	01-24	S curve Accel time 1
	"S 筄寋厞 2      f/s3"	,	//	169	01-25	S curve Accel time 2
	"S 筄寋厞 3      f/s3"	,	//	170	01-26	S curve Decel time 1
	"S 筄寋厞 4      f/s3"	,	//	171	01-27	S curve Decel time 2
	"S 筄寋厞 5      f/s3"	,	//	174	01-30	S curve Decel time 3
};


const string20 prinfo_rus[EPMAX] = {	
/*---- GROUP 15---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"DEBUG FLAG          "	,	//	0   15-00	Debug Flag 1	                                
	"DBC Change Freq.    "	,	//	1   15-01	DBC CHANGE FREQ	                                
	"EFFICIENCY      %   "	,	//	2   15-02	efficiency of Motor	                            
    "ZOffset Tune I  %   "  ,   //  3   15-03   Z Phase search current level                    
	"RATED-I AD VALUE    "	,	//	4   15-04	AD value at Rated Current	                    
	"Ide Iqe LPF Gain    "	,	//	5   15-05	Id*,Iq* LPF	                                    
	"Factory Serial 1    "	,	//	6   15-06	Only for Factory 1	                            
	"Factory Serial 2    "	,	//	7   15-07	Only for Factory 2	                            
	"Factory Serial 3    "	,	//	8   15-08	Only for Factory 3	                            
	"Factory Serial 4    "	,	//	9   15-09	Only for Factory 4	                            
	"REVERSE             "  ,   //  10  15-10   REVERSED   	//[move parameter to 11-20, Bernie, 2017/02/16]                
	"Skip DeadTime       "	,	//	11  15-11	Skip Dead Time	                                
	"210.0 VDC AD        "	,	//	12  15-12	DCBUS 210.0 VDC ad value	                    
	"310.0 VDC AD        "	,	//	13  15-13	DCBUS 310.0 VDC ad value	                    
	"390.0 VDC AD        "	,	//	14  15-14	DCBUS 390.0 VDC ad value	                    
	"TRQ_P               "	,	//	15  15-15	Torque control Kp	                            
	"TRQ_I               "	,	//	16  15-16	Torque Control Ki	                            
	"FLUX_P              "	,	//	17  15-17	Flux Control Kp	                                
	"FLUX_I              "	,	//	18  15-18	Flux Control Ki	                                
	"SpdSlop_P           "	,	//	19  15-19	Speed slop Control Kp gain	                    
	"SpdSlop_I           "	,	//	20  15-20	Speed slop Control Ki gain	                    
	"Control Select      "	,	//	21  15-21	Control Selection	                            
	"TEST SOURCE Amp.    "	,	//	22  15-22	Test Source Value Amplitude	                    
	"High Speed LPG  Hz  "	,	//	23  15-23	High Speed Low pass Filter Gain	                
	"Low Speed LPG   Hz  "	,	//	24  15-24	Low Speed Low pass filter Gain	                
	"TEST SOURCE Bias    "	,	//	25  15-25	Test Source Value Bias	                        
	"Est J LPG       s   "	,	//	26  15-26	Estimate J Low pass Filter Gain	                
	"Calibration A RE    "	,	//	27  15-27	Calibration current REF	                        
	"Calibration P       "	,	//	28  15-28	Calibration P	                                
	"Calibration I       "	,	//	29  15-29	Calibration I	                                
	"DC-Tun current P    "	,	//	30  15-30	Auto tuning DC test Kp gain	                    
	"DC-Tun current I    "	,	//	31  15-31	Auto Tuning DC test Ki gain	                    
	"High Freq. Tun P    "	,	//	32  15-32	Auto tuning High Freq. Lock test Kp gain	    
	"High Freq. Tun I    "	,	//	33  15-33	ADcbus Low Pass Gain	                        
	"Gain of VcmpMax %   "	,	//	34  15-34	Select Zero Speed	                            
	"NL-Boost Gain       "	,	//	35  15-35	No Load Boost Gain	                            
	"Auto Accel. KP      "	,	//	36  15-36	Acceleration AKP	                            
	"Auto Accel. KI      "	,	//	37  15-37	Acceleration AKI	                            
	"Current Loop BW     "	,	//	38  15-38	Current Loop BandWidth                          
	"DBC Leading 2       "	,	//	39  15-39	DBC Leading 2                                   
	"DBC Ration 2        "	,	//	40  15-40	DBC Ratio 2 with close loop                     
	"DBC Coef.           "	,	//	41  15-41	DBC Coef.                                       
	"DBC Dcbus Coef.     "	,	//	42  15-42	DBC Dcbus Coef.                                 
	"DBC Leading 1       "	,	//	43  15-43	DBC leading 1                                   
	"DBC Ratio 1         "	,	//	44  15-44	DBC Linear Ratio 1                              
	"RESERVE             "	,	//	45  15-45	DBC MODE                                        
	"Magnitization L1    "	,	//	46  15-46	magnitization inductance 1                      
	"Main Flux Link 1    "	,	//	47  15-47	main flux linkage 1                             
	"Magnitization L2    "	,	//	48  15-48	magnitization inductance 2                      
	"Main Flux Link 2    "	,	//	49  15-49	main flux linkage 2                             
	"Magnitization L3    "	,	//	50  15-50	magnitization inductance 3                      
	"Main Flux Link 3    "	,	//	51  15-51	main flux linkage 3                             
	"Magnitization L4    "	,	//	52  15-52	magnitization inductance 4                      
	"Main Flux Link 4    "	,	//	53  15-53	main flux linkage 4                             
	"Magnitization L5    "	,	//	54  15-54	magnitization inductance 5                      
	"Main Flux Link 5    "	,	//	55  15-55	main flux linkage 5                             
	"Magnitization L6    "	,	//	56  15-56	magnitization inductance 6                      
	"Main Flux Link 6    "	,	//	57  15-57	main flux linkage 6                             
	"Modulation Index    "	,	//	58  15-58	Modulation Index                                
	"Zero Current LPG    "	,	//	59  15-59	Current Zero Low Pass Gain                      
	"COSphi LPF      ms  "	,	//	60  15-60	cos(TB1_uwPhi) low pass gain                          
	"Date Code Y.WKD     "  ,   //  61  15-61   DateCode  //Datecode para change, Henry, 2016/07/20 
	"AUI2 0V ADC     adc "	,	//	62  15-62	calibration for AUI ZeroPoint (0V)
	"AUI2 -10V ADC   adc "	,	//	63  15-63	calibration for AUI2 max (-10V)
	"AUI2 +10V ADC   adc "	,	//	64  15-64	calibration for AUI2 min (+10V)
	"ACI 20mA ADC    adc "	,	//	65  15-65	calibration for ACI2 max (20mA)                 
	"ACI 12mA ADC    adc "	,	//	66  15-66	calibration for ACI mid (12mA)                  
	"ACI 4mA ADC     adc "	,	//	67  15-67	calibration for ACI min (4mA)                   
	"AUI1 0V ADC     adc "	,	//	68  15-68	calibration for AUI1 ZeroPoint (0V)
	"AUI1 -10V ADC   adc "	,	//	69  15-69	calibration for AUI1 max (-10V)
	"AUI1 +10V ADC   adc "	,	//	70  15-70	calibration for AUI1 min (+10V)
	"Auto Decel. DKP     "	,	//	71  15-71	Deceleration DKP                                
	"Auto Decel. DKI     "	,	//	72  15-72	Deceleration DKI                                
	"Low Speed Comp. Hz  "	,	//	73  15-73	more volt. comp. below this freq.               
	"PGLOSS Detcect T    "	,	//	74  15-74	PGLOSS Detect Counter                           
	"Main Frequency      "	,	//	75  15-75	Main Frequency                                  
	"Power On Counter    "	,	//	76  15-76	Power On Counter                                
	"GFF_Pk Detec SW     "	,	//	77  15-77	GFF Maximum Value Record Switch, Jerry Yu, 2019/11/11 
	"BLD  Version        "	,	//	78  15-78   //[BootLoader Version, Special.Kung, 2022/10/31]
#if SIBO_ENABLE
    "SIBO EPS FRMODE     "  ,   //  79  15-79 SIBO EPS FRMODE
#else
    "RESERVE             "  ,   //  79  15-79
#endif
    "OPHL_SPER           "  ,   //  80  15-80
    "OPHL_CURER          "  ,   //  81  15-81
    "OPHL_ERCNT          "  ,   //  82  15-82
	"BLD DateCode        "  ,   //  83  15-83   //[BootLoader DataCode, Special.Kung, 2022/10/31]
	"FineAUI 0V ADC  adc "	,	//	84  15-84	calibration for AUI ZeroPoint (0V)              
	"FineAUI +2V ADC adc "	,	//	85  15-85	calibration for AUI max (+2V)                   
	"FineAUI -2V ADC adc "	,	//	86  15-86	calibration for AUI min (-2V)                   
	"SIN MAX V ADC   adc "	,	//	87  15-87	calibration for SIN max, add by dino, 06/01/2007
	"SIN MIN V ADC   adc "	,	//	88  15-88	calibration for SIN min, add by dino, 06/01/2007
	"COS MAX V ADC   adc "	,	//	89  15-89	calibration for COS max, add by dino, 06/01/2007
	"COS MIN V ADC   adc "	,	//	90  15-90	calibration for COS min, add by dino, 06/01/2007
    "Min. Pulse Width    "  ,   //  91  15-91   minimum pulse, ADDED BY SCOTTY,2007/07/11
	"D Frame FAN Cont    "	,	//	92 	15-92	D Frame Fan control
	"Z Phase UVW Sect    "	,	//	93 	15-93	Z phase UVW Section when PG_TYPE = 2
	"RESERVE             "  ,   //  94
    "LAST PG COUNTER     "  ,   //  95  15-95   PG Position Record, add by scotty, 12/07/2007
	"AFM MAX. Value      "	,	//	96 	15-96   AFM max. value
	"AFM MIN. Value      "	,	//	97 	15-97   AFM min. value
	"Soft Start Time sec "	,	//	98  15-98	Softstart Delay Time
	"DEBUG FLAG2         "  ,   //  99  15-99   //Rational 341544, Pr[15-99] replace Pr[15-09], Special 05/22/2023
	"Z-cab Mode          "  ,   //  100  
	"Qer_min             "  ,   //  101
	"Qer_Shift           "  ,   //  102
	"Sin_HS_Tab          "  ,   //  103
	"RESERVE             "  ,   //  104
	"RESERVE             "	,	//	105 15-105  RESERVED
	"CAN Control         "	,	//	106 15-106  Can Control      //[CAN Control, Sampo, 09/15/2010]
	"CAN Fault Handle    "	,	//	107 15-107  Can Fault Handle //[CAN Control, Sampo, 09/15/2010]
	"DEBUG_PG            "	,	//	108 15-108  DEBUG_PG
	"_47th_DISP          "	,	//	109 15-109  _47th_DISP
	"PG_MODE             "	,	//	110 15-110  RESERVED
	"WDT Divider         "	,	//	111 15-111  WDT_DIV     //[ICT WDT test, Bernie, 08/16/2011]
	"AFM1 +10V CNT       "	,	//	112 15-112  AFM1_P10CNT for AFM1 +10V output
	"AFM1 0V CNT         "	,	//	113 15-113  AFM1_0CNT for AFM1 0V output
	"AFM1 -10V CNT       "	,	//	114 15-114  AFM1_M10CNT for AFM1 -10V output
	"AFM2 +10V CNT       "	,	//	115 15-115  AFM2_P10CNT for AFM2 +10V output
	"AFM2 0V CNT         "	,	//	116 15-116  AFM2_0CNT for AFM2 0V output
	"AFM2 -10V CNT       "	,	//	117 15-117  AFM2_M10CNT for AFM2 -10V output
	"Protect Bit SW      "	,	//	118 15-118  The switch of Protect finction    //[The switch of Protect finction, Bernie, 2015/05/21]
	"OPHL COUNT          "	,	//	119 15-119  The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL IRMS           "	,	//	120 15-120  The IRMS value of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
	"OPHL COUNT          "	,	//	121 15-121  The Gain value of Protect finction     //[Output Phase Loss 2, Sampo, 2015/05/21]
	"PPI filter point    "	,	//	122 15-122  RESERVED
	"MBF Recoder         "	,	//	123 15-123  MBF record after power off
	"EoL Cnt Recder H    "	,	//	124 15-124  RESERVED       //[add for UL EoL Verification,Bernie, 2013/04/22]
	"EoL Cnt Recder L    "	,	//	125 15-125  RESERVED       //[add for UL EoL Verification,Bernie, 2013/04/22]
	"RESERVE             "	,	//	126 15-126  RESERVED
	"Unavailable         "	,	//	127 15-127  RESERVED
//	"PPI filter point    "	,	//	128 15-128  PPI control    //[PPI function, Sampo, 2015/09/08]

/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
	"詳殎畽馽硞 管    "	,	//	128 00-00	Model Type of Drive 
	"豬嗏楅貵 瘑  Amps"	,	//	129 00-01	Rated Current
	"蹊頏葎閛喿瘔痭     "	,	//	130 00-02	Parameter Reset
	"請 嵋婥硞箾      "	,	//	131 00-03	Start up Display
	"豭貵軜眓軝剚-    "	,	//	132 00-04	User Display
	"管罽馽葠貵趉     "	,	//	133	00-05	User Coefficient
	"組颬崶 蕪            "	,	//	134	00-06	Software Version
	"絀痽 葎頏趉          "	,	//	135	00-07	Password Input
	"煩婕楉葎頏趉       "	,	//	136	00-08	Password Input
	"毚笭蝃閛砢殎崶     "	,	//	137	00-09	Control Methods
	"菠嵋崽. 摍睔睙畽	  "	,	//	138	00-10	Velocity Unit Select
	"請葮倷. 耜剞殎崶     "	,	//	139 00-11   Change Output Direction, Added by sampo , 06/11/2009
	"з摵睭��     KHz "	,	//	140	00-12	Carry Frequency
	"偯                 "	,	//	141	00-13	AVR
	"詬瘑誾嵃 覣摵睭    "	,	//	142	00-14	Source of Freq. Command
	"詬瘑誾嵃 筊嗝楗      "	,	//	143	00-15	Source of Oper. Command
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"標筈.祒覣摵睭粀z  "	,	//	144	01-00	Max Output Freq.
	"豬覣摵睭婞.1Hz  "	,	//	145	01-01	Motor Base Frequency 1
	"豬楅葮攃.婞.1 V   "	,	//	146	01-02	Max Output Voltage
	"醜.覣摵睭 婞.1Hz  "	,	//	147	01-03	Mid Output Freq.1
	"醜.楅葮攃.1 婞.1V   "	,	//	148	01-04	Mid Output Voltage 1
	"醜.覣摵睭 婞.1Hz  "	,	//	149	01-05	Mid Output Freq.2
	"醜.楅葮攃.2 婞.1V   "	,	//	150	01-06	Mid Output Voltage 2
	"槭覣摵睭婞.1Hz  "	,	//	151	01-07	Min Output Freq.
	"槭楅葮攃. 婞.1V   "	,	//	152	01-08	Min Output Voltage
	"鎂冓 з摵睭 Hz  "	,	//	153	01-09	Start Frequency
	"組馲.豻倎崽.覣摵Hz  "	,	//	154	01-10	Upper Bound Freq.
	"諍笣.豻倎崽.覣摵Hz  "	,	//	155	01-11	Lower Bound Freq.
	"耜殍蝁筊雎楉sec "	,	//	156	01-12	1st Acceleration time
	"耜殍豝喿婤殎.1sec "	,	//	157	01-13	1st Deceleration time
	"耜殍蝁筊雎楉sec "	,	//	158	01-14	2nd Acceleration time
	"耜殍豝喿婤殎.2sec "	,	//	159	01-15	2nd Deceleration time
	"耜殍蝁筊雎楉sec "	,	//	160	01-16	3rd Acceleration time
	"耜殍豝喿婤殎.3sec "	,	//	161	01-17	3rd Deceleration time
	"耜殍蝁筊雎楉sec "	,	//	162	01-18	4th Acceleration time
	"耜殍豝喿婤殎.4sec "	,	//	163	01-19	4th Deceleration time
	"耜殍蝁筊 JOGsec "	,	//	164	01-20	JOG Acceleration time
	"耜殍豝喿婤.JOGsec "	,	//	165	01-21	JOG Deceleration time
	"з摵睭JOG     Hz  "	,	//	166	01-22	JOG Frequency
	"諾雎轔煩-4Hz  "	,	//	167	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"S 筄寋厞 1      sec "	,	//	168	01-24	S curve Accel time 1
	"S 筄寋厞 2      sec "	,	//	169	01-25	S curve Accel time 2
	"S 筄寋厞 3      sec "	,	//	170	01-26	S curve Decel time 1
	"S 筄寋厞 4      sec "	,	//	171	01-27	S curve Decel time 2
	"毚0-摍睔睙畽    "	,	//	172	01-28	Select Zero Speed
	"邁睔.婝碨衯眓楉顉z  "	,	//	173	01-29	Landing Frequency 
	"S 筄寋厞 5      sec "	,	//	174	01-30	S curve Decel time 3
	"耜殍睙瑱棰眓  sec "	,	//	175	01-31	Stop Deceleration time
    "邁睔.栝摵.睙瑱m/s "	,	//	1xx	01-32
    "耜殍黿睒邁睔.綰滻ec "	,	//	1xx	01-33   IODHT IO direct hold time   
    "耜殍鼢睭擽寋.綰滻ec "	,	//	1xx	01-34   IODLT IO direct landing freq
    "CRPLS痵閛鳪砬   "	,	//	1xx	01-35   IODLT IO direct landing time
    "IOD 瘑諕豝喿cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "IOD婥摵.豝喿  m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "IODLC倵畽         "	,	//	1xx	01-37   IODLT IO direct DistancE
    "翌涷.摵睧.覣摵睭Hz  "  ,   //  1xx 01-37   IODLT IO direct DistancE
    "ESD砫殍.豝喿婤. sec "	,	//	1xx	01-37   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105  RESERVED
    "Emergency S3    sec "  ,   //  105 15-105  RESERVED
    "Emergency S4    sec "  ,   //  105 15-105  RESERVED
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"2/3-葮痭痽.蝃   "	,	//	176	02-00	2/3 wire control                
	"楮摍雎瘕.砱痽 1     "	,	//	177	02-01	Multi-Function Input 1          
	"楮摍雎瘕.砱痽 2     "	,	//	178	02-02	Multi-Function Input 2          
	"楮摍雎瘕.砱痽 3     "	,	//	179	02-03	Multi-Function Input 3          
	"楮摍雎瘕.砱痽 4     "	,	//	180	02-04	Multi-Function Input 4          
	"楮摍雎瘕.砱痽 5     "	,	//	181	02-05	Multi-Function Input 5          
	"楮摍雎瘕.砱痽 6     "	,	//	182	02-06	Multi-Function Input 6          
	"楮摍雎瘕.砱痽 7     "	,	//	183	02-07	Multi-Function Input 7          
	"楮摍雎瘕.砱痽 8     "	,	//	184	02-08	Multi-Function Input 8		    
	"煩婭雺硞 婥摍.砱sec "	,	//	185	02-09	Digital in response time		
	"啊畽眓箾砱痽痭    "	,	//	186	02-10	Multi-Function Input Inverse	
	"舵槧婃皙 雎觛 1     "	,	//	187	02-11	Multi-Function Relay 1		    
	"舵槧婃皙 雎觛 2     "	,	//	188	02-12	Multi-Function Relay 2		    
	"舵槧婃皙 雎觛 3     "	,	//	189	02-13	Multi-Function Output 1		    
	"舵槧婃皙 雎觛 4     "	,	//	190	02-14	Multi-Function Output 2		    
	"楮摍雎瘕.祒槧1    "	,	//	191	02-15	Multi-Function Output 1		    
	"楮摍雎瘕.祒槧2    "	,	//	192	02-16	Multi-Function Output 2		    
	"楮摍雎瘕.祒槧3    "	,	//	193	02-17	Multi-Function Output 1		    
	"楮摍雎瘕.祒槧4    "	,	//	194	02-18	Multi-Function Output 2		    
	"楮摍雎瘕.祒槧5    "	,	//	195	02-19	Multi-Function Output 1		    
	"楮摍雎瘕.祒槧6    "	,	//	196	02-20	Multi-Function Output 2		    
	"楮摍雎瘕.祒槧7    "	,	//	197	02-21	Multi-Function Output 1		    
	"楮摍雎瘕.祒槧8    "	,	//	198	02-22	Multi-Function Output 2		    
	"啊畽眓 祒槧婝   "	,	//	199	02-23	Multi-Function Output inverse	
    "鎂冓葠摛梊-摵   "  ,   //  200 02-24   Sequence start mode
	"管楀頏覣摵睭Hz  "	,	//	201	02-25	Desired Frequency 1		        
	"�嵑嵋� 覣摵睭 Hz  "	,	//	202	02-26	Band of Desired Frequency 1		
	"管楀頏覣摵睭Hz  "	,	//	203	02-27	Desired Frequency 2		        
	"�嵑嵋� 覣摵睭 Hz  "	,	//	204	02-28	Band of Desired Frequency 2		
	"煩婭鈶凊瘑鉰睔sec "	,	//	205	02-29	Brake Delay Timer at run
	"煩婭鉠倯皵蹕靸. sec "	,	//	206	02-30	Brake Delay Timer at stop
	"管楀倵瘑鉦獄. sec "	,	//	207	02-31	Mech Contact Delay Timer run
	"管楀倵瘑鉦侉sec "	,	//	208	02-32	Mech Contact Delay Timer stop				            
	"蹕痦窙.楮摍祒   "	,	//	209	02-33	Isum Current Output Detect	    
	"з摵.缽楮摍舵嘺z  "	,	//	210	02-34	Speed Area
	"賴痭淀檗摵.瘑靸.sec "	,	//	211	02-35	Mechanical Brake Checking Time
	"賴痭缽蛜睚瑱筌睔sec "	,	//	212 02-36   Magnetic Contactor Checking Time
	"賴痭.祒嗍喿楀   "  ,   //  213 02-37   Mechanical Brake Checking Current Enable
	"Y-D管楀倵煻瑱飶 sec "  ,   //  2xx 02-38   Star Contactor delay time when driver run    //[Star contactor function, Bernie, 2017/03/22]
	"Y-D管楀倵煻瘑 sec "  ,   //  2xx 02-39   Star Contactor delay time when driver stop  //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD Fault SEL     "  ,   //  2xx 02-40   LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
	"LU/LD Open Det. sec "  ,   //  2xx 02-41   LD/LD Open Detect Time       //#15977, LULD detect, James, 2021/04/01
	"LU/LD Short Det.sec "  ,   //  2xx 02-42   LD/LD Short Detect Time      //#15977, LULD detect, James, 2021/04/01
	"SPEED-REACH BND Hz  "	,   //  202 02-43   Band of Speed Agree Function  //#18572
    "STO Short Det   sec "  ,   //  2xx 02-44   STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Speed Limit     m/s "  ,   //  2xx 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06]
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"問倯痵.砱痽 AUI1    "	,	//	214	03-00    AUI1 selection     //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"煩雎赹隓嵑痭倎    "	,	//	215	03-01    ACI  selection      //[ACI function remove, Bernie, 01/20/2012]
	"問倯痵.砱痽 AUI2    "	,	//	216	03-02    AUI2 selection    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"邀淶殎寊 AUI1   %   "	,	//	217	03-03    AUI1 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"煩雎赹隓嵑痭倎    "	,	//	218	03-04    ACI  input Bias    //[ACI function remove, Bernie, 01/20/2012]
	"邀淶殎寊 AUI2   %   "	,	//	219	03-05    AUI2 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"毚笭僋喿橩AUI1    "	,	//	220  03-06    AUI1 input Polarity         //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"煩雎赹隓嵑痭倎    "	,	//	221  03-07    ACI  input Polarity     //[ACI function remove, Bernie, 01/20/2012]
	"毚笭僋喿橩AUI2    "	,	//	222  03-08    AUI2 input Polarity    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"管罽.轔嵫殎.AUI1%   "	,	//	223  03-09    AUI1 input Gain     //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"煩雎赹隓嵑痭倎    "	,	//	224  03-10    ACI  input Gain     //[ACI function remove, Bernie, 01/20/2012]
	"管罽.轔嵫殎.AUI2%   "	,	//	225  03-11    AUI2 input Gain   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 砱痽躅   sec "	,	//	226  03-12    Low pass filter of AUI1 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"煩雎赹隓嵑痭倎    "	,	//	227  03-13    Low pass filter of ACI  input      //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 砱痽躅   sec "	,	//	228  03-14    Low pass filter of AUI2 input    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"煩雎赹隓嵑痭倎    "	,	//	229  03-15    Loss of ACI            //[ACI function remove, Bernie, 01/20/2012]
    "煩雎赹隓嵑痭倎    "  ,   //  230  03-16
	"斕楬箾偏1         "	,	//	231  03-17    Analong Output 1
	"管罽轔嵫殎.AO1%   "	,	//	232  03-18    Analong Output 1 Gain
	"AO1 葮雎眙颬    "	,	//	233  03-19    AO1 in minus value
	"斕楬箾偏2         "	,	//	234  03-20    Analong Output 2
	"管罽轔嵫殎.AO2%   "	,	//	235  03-21    Analong Output 2 Gain
	"AO2 葮雎眙颬    "	,	//	236  03-22    AO2 in minus value
	"豭趉靲睙碪 AUI1     "	,	//	237  03-23    AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"豭趉靲睙碪 AUI2     "	,	//	238  03-24    AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	//"AUI1砱.楅摵  /"AUI1 In Setting     "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2砱.楅摵  /"AUI2 In Setting     "	,	//	238  03-26    AUI2 Communciate
	
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "0-摍睔睙碪    Hz  "  , //  239 04-00 Multi-Speed 0
    "1-摍睔睙碪    Hz  "  , //  240 04-01 Multi-Speed 1
    "2-摍睔睙碪    Hz  "  , //  241 04-02 Multi-Speed 2
    "3-摍睔睙碪    Hz  "  , //  242 04-03 Multi-Speed 3
    "4-摍睔睙碪    Hz  "  , //  243 04-04 Multi-Speed 4
    "5-摍睔睙碪    Hz  "  , //  244 04-05 Multi-Speed 5
    "6-摍睔睙碪    Hz  "  , //  245 04-06 Multi-Speed 6
    "7-摍睔睙碪    Hz  "  , //  246 04-07 Multi-Speed 7
    "8-摍睔睙碪    Hz  "  , //  247 04-08 Multi-Speed 8
    "9-摍睔睙碪    Hz  "  , //  248 04-09 Multi-Speed 9
    "10-摍睔睙碪   Hz  "  , //  249 04-10 Multi-Speed 10
    "11-摍睔睙碪   Hz  "  , //  250 04-11 Multi-Speed 11
    "12-摍睔睙碪   Hz  "  , //  251 04-12 Multi-Speed 12
    "13-摍睔睙碪   Hz  "  , //  252 04-13 Multi-Speed 13
    "14-摍睔睙碪   Hz  "  , //  253 04-14 Multi-Speed 14
    "15-摍睔睙碪   Hz  "  , //  254 04-15 Multi-Speed 15
    "醞凊凄.摍-摵  m/s "  , //  2xx 04-16
    "邁睔.婝碨衯眓楉鮛/s "  , //  2xx 04-17
    "邁睔.砨貥婝嗍揋/s "  , //  2xx 04-18
	                 
    "Rope Slip Comp. mm  "  , //  2xx 04-19 GFC Rope compensation, 2021/03/30
    "TABST0 摵凄蝁       "  ,   //    2xx 04-20
    "TABST2 摵凄蝁       "  ,   //    2xx 04-21
	                 
    "標筈. 罿倗          "  , //  2xx 04-22
    "謬筎橞罿倗        "  , //  2xx 04-23
    "PG 詰喿葮碔   %   "  , //  2xx 04-24
    "Sensor Delay Cmpsec "  , //  2xx 04-25
    "DLC 煩婭雺.砫殍.ms  "  , //  2xx 04-26
    "欺嵋葾倎稃    mm  "  , //  2xx 04-27 
    "謬 葠 舵  m   "  , //  2xx 04-28
    "謬 葠 諍  mm  "  , //  2xx 04-29
    "謬筎軝剚. PG H    "  , //  2xx 04-30 
    "謬筎軝剚. PG L    "  , //  2xx 04-31
    "諶倎硞:爺剚.PG H    "  , //  2xx 04-32
    "諶倎硞:爺剚.PG L    "  , //  2xx 04-33
    "轅楩睔 PG 舵      "  , //  2xx 04-34
    "轅楩睔 PG 諍      "  , //  2xx 04-35    
    "斕楬箾DLC         "  , //  2xx 04-36
    "贅PDO             "  , //  2xx 04-37
    "煩喿SWTol.Gap mm  "  , //  2xx 04-38
    "% 睭 標筈 摍-摵   "  , //  2xx 04-39 //[ADCO EPS Modify]
    "Spring Extend   mm  "  , //  2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "醣摵碙楉EST       "  , //  2xx 04-41
    "鍋涴諑EST         "  , //  2xx 04-42
    "TABST0 鍋涴.        "  , //  2xx 04-43
    "TABST1 鍋涴.        "  , //  2xx 04-44
    "DDS1/UDS1Spd Limm/s "  , //  2XX 04-45  DD1_Vlim  //Artemis speed limit, James, 20200220                          
    "DDS2/UDS2Spd Limm/s "  , //  2XX 04-46  DD2_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS3/UDS3Spd Limm/s "  , //  2XX 04-47  DD3_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS4/UDS4Spd Limm/s "  , //  2XX 04-48  DD4_Vlim  //Artemis speed limit, James, 20200220
    "DLC 葠貵摵      "  , //  2XX 04-49   user page cahnge
                     
    "1葠趹箾祒 m   "  , //  2XX 04-30   1Floor Position H                                       
    "1葠趹箾楉 mm  "  , //  2XX 04-31   1Floor Position L                                       
    "2葠趹箾祒 m   "  , //  2XX 04-32   2Floor Position H                                       
    "2葠趹箾楉 mm  "  , //  2XX 04-33   2Floor Position L                                       
    "3葠趹箾祒 m   "  , //  2XX 04-34   3Floor Position H                                       
    "3葠趹箾楉 mm  "  , //  2XX 04-35   3Floor Position L                                       
    "4葠趹箾祒 m   "  , //  2XX 04-36   4Floor Position H                                       
    "4葠趹箾楉 mm  "  , //  2XX 04-37   4Floor Position L                                       
    "5葠趹箾祒 m   "  , //  2XX 04-38   5Floor Position H                                       
    "5葠趹箾楉 mm  "  , //  2XX 04-39   5Floor Position L                                       
    "6葠趹箾祒 m   "  , //  2XX 04-40   6Floor Position H                                       
    "6葠趹箾楉 mm  "  , //  2XX 04-41   6Floor Position L                                       
    "7葠趹箾祒 m   "  , //  2XX 04-42   7Floor Position H                                       
    "7葠趹箾楉 mm  "  , //  2XX 04-43   7Floor Position L                                       
    "8葠趹箾祒 m   "  , //  2XX 04-44   8Floor Position H                                       
    "8葠趹箾楉 mm  "  , //  2XX 04-45   8Floor Position L                                       
    "9葠趹箾祒 m   "  , //  2XX 04-46   9Floor Position H                                       
    "9葠趹箾楉 mm  "  , //  2XX 04-47   9Floor Position L                                       
    "10葠趹箾祒m   "  , //  2XX 04-48   10Floor Position H                                      
    "10葠趹箾楉mm  "  , //  2XX 04-49   10Floor Position L                                      
    "11葠趹箾祒m   "  , //  2XX 04-50   11Floor Position H                                      
    "11葠趹箾楉mm  "  , //  2XX 04-51   11Floor Position L                                      
    "12葠趹箾祒m   "  , //  2XX 04-52   12Floor Position H                                      
    "12葠趹箾楉mm  "  , //  2XX 04-53   12Floor Position L                                      
    "13葠趹箾祒m   "  , //  2XX 04-54   13Floor Position H                                      
    "13葠趹箾楉mm  "  , //  2XX 04-55   13Floor Position L                                      
    "14葠趹箾祒m   "  , //  2XX 04-56   14Floor Position H                                      
    "14葠趹箾楉mm  "  , //  2XX 04-57   14Floor Position L                                      
    "15葠趹箾祒m   "  , //  2XX 04-58   15Floor Position H                                      
    "15葠趹箾楉mm  "  , //  2XX 04-59   15Floor Position L                                      
    "16葠趹箾祒m   "  , //  2XX 04-60   16Floor Position H                                      
    "16葠趹箾楉mm  "  , //  2XX 04-61   16Floor Position L                                      
    "17葠趹箾祒m   "  , //  2XX 04-62   17Floor Position H                                      
    "17葠趹箾楉mm  "  , //  2XX 04-63   17Floor Position L                                      
    "18葠趹箾祒m   "  , //  2XX 04-64   18Floor Position H                                      
    "18葠趹箾楉mm  "  , //  2XX 04-65   18Floor Position L                                      
    "19葠趹箾祒m   "  , //  2XX 04-66   19Floor Position H                                      
    "19葠趹箾楉mm  "  , //  2XX 04-67   19Floor Position L                                      
    "20葠趹箾祒m   "  , //  2XX 04-68   20Floor Position H                                      
    "20葠趹箾楉mm  "  , //  2XX 04-69   20Floor Position L                                      
    "21葠趹箾祒m   "  , //  2XX 04-70   21Floor Position H                                      
    "21葠趹箾楉mm  "  , //  2XX 04-71   21Floor Position L                                      
    "22葠趹箾祒m   "  , //  2XX 04-72   22Floor Position H                                      
    "22葠趹箾楉mm  "  , //  2XX 04-73   22Floor Position L                                      
    "23葠趹箾祒m   "  , //  2XX 04-74   23Floor Position H                                      
    "23葠趹箾楉mm  "  , //  2XX 04-75   23Floor Position L                                      
    "24葠趹箾祒m   "  , //  2XX 04-76   24Floor Position H                                      
    "24葠趹箾楉mm  "  , //  2XX 04-77   24Floor Position L                                      
    "25葠趹箾祒m   "  , //  2XX 04-78   25Floor Position H                                      
    "25葠趹箾楉mm  "  , //  2XX 04-79   25Floor Position L                                     
   
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
	"曼瘑碭楉楂 偌       "	,	//	255 05-00	Motor Auto-Tuning
	"豬 瘑偌     Amps"	,	//	256 05-01	Motor 1 rated Current           
	"豬嗍橆睙碪 偌 Kw  "	,	//	257 05-02	Motor 1 Rated Power             
	"豬 覣摵睭偌 RPM "	,	//	258 05-03	Motor 1 Rated RPM               
	"п摛葠趀摶偌    "	,	//	259 05-04	Motor 1 pole No.                
	"蹕槧 槧婕 偌Amps"	,	//	260 05-05	Motor 1 No-Load Current         
	"Rs 婞寔凄殏   ohm "	,	//	261 05-06	Motor 1 Rs                      
	"Rr 婞寔凄殏   ohm "	,	//	262 05-07	Motor 1 Rr                      
	"Lm 婞寔凄殏    mH "	,	//	263 05-08	Motor 1 Lm                      
	"L婞寔凄殏    mH "	,	//	264 05-09	Motor 1 Lx                      
	"筊嗙. 嗍 SVCsec "	,	//	265 05-10	Vector Voltage Filter	        
	"蹣睖摍睒嬮.SVCsec "	,	//	266 05-11	Vector Slip Filter	            
	"管罽.筊嗙.嗍瑱    "	,	//	267 05-12	Torque Compensation Gain	    
	"管罽.筊嗙.摍睒嬮    "	,	//	268 05-13	Slip Compensation Gain	        
	"殖蜄摵嵁皙邁睒嬮%   "	,	//	269 05-14	Slip Deviation level	        
	"煩婭睧摍睒嬮sec "	,	//	270 05-15	Slip Deviation Detect Time	    
	"毚倵瞈雎摍睒嬮    "	,	//	271 05-16	Over Slip treatment	            
	"管嗙殎.楙蝁瘑淼.    "	,	//	272 05-17	Coeff for hunting disable	    
	"褲 閛栻甀     Mins"	,	//	273 05-18	Accumulative Motor Operation Min
	"褲 閛栻甀     Days"	,	//	274 05-19	Accumulative Motor Operation Day
	"管嗙豭甀鳭鎂倯%   "	,	//	275 05-20	Coreloss % of output Power	    
	"諷瑱楉砬嗏Mins"	,	//	276 05-21	Power On Min
	"諷瑱楉砬婃. Days"	,	//	277 05-22	Power On Day
    "博摍睒嬮.蝁嵫 %   "	,   //    2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"棍寔.摍睒嬮.蝁嵫%   "	,	//	123 15-123  RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
	"諍蜬痭.楅葮攃 V   "	,	//	278  06-00	Low voltage level
	"箾憾鳪餇郴    "	,	//	279  06-01	Phase loss
	"蹕筊痵閛蝁筊%   "	,	//	280  06-02	OC stall during Accel
	"蹕筊痵閛閛栻瑱%   "	,	//	281  06-03	OC stall during Decel
	"蹕筊痵鈱摍睔/煩   "	,	//	282  06-04	Stall preventation Accel/Decel time selection
	"毚痵嗍喿楀    "	,	//	283  06-05	Over-Torque 1 Selection
	"懈閛嗍喿楀% %   "	,	//	284  06-06	Over-Torque 1 level
	"耜殍.痵嗍喿楀苫ec "	,	//	285  06-07	Over-Torque 1 Time
	"毚痵嗍喿楀    "	,	//	286  06-08	Over-Torque 2 Selection	                     
	"懈閛嗍喿楀  %   "	,	//	287  06-09	Over-Torque 2 level	                         
	"耜殍.痵嗍喿楀苫ec "	,	//	288  06-10	Over-Torque 2 Time	                         
	"懈閛楉 毆喿楀   "	,	//	289  06-11	Current Limit
	"阺.甀葾.雎觛 婞1    "	,	//	290  06-12	Thermal Relay 1 Selection
	"T 甀葾.雎觛 婞.1sec "	,	//	291  06-13	Thermal Relay 1 Time
	"諾雎豻梑 閛婥凄. C  "	,	//	292  06-14	OH Warning Level
	"蹕筊痵閛楉諆楉%   "	,	//	293  06-15	Stall preventation Limit Level
	"1豝萶摐 倷冓尰    "	,	//	294  06-16	1st Fault Record
	"2豝萶摐 倷冓尰    "	,	//	295  06-17	2nd Fault Record
	"3豝萶摐 倷冓尰    "	,	//	296  06-18	3rd Fault Record
	"4豝萶摐 倷冓尰    "	,	//	297  06-19	4th Fault Record
	"5豝萶摐 倷冓尰    "	,	//	298  06-20	5th Fault Record
	"6豝萶摐 倷冓尰    "	,	//	299  06-21	6th Fault Record
	"曼冓崶 婤祒1    "	,	//	300  06-22	Fault Option 1
	"曼冓崶 婤祒2    "	,	//	301  06-23	Fault Option 2
	"曼冓崶 婤祒3    "	,	//	302  06-24	Fault Option 3
	"曼冓崶 婤祒4    "	,	//	303  06-25	Fault Option 4
	"毚倵 摳倳. PTC    "	,	//	304  06-26	PTC over Treatments	                         
	"蹴痭殎PTC     %   "	,	//	305  06-27	PTC Level
	"儸貵瘔 PTC      sec "	,	//	306  06-28	PTC Detect Filter time
	"請葮攃. 萵    V   "	,	//	307  06-29	EPS voltage level
	"毚笭黹眓雸媥蛺      "	,	//	308  06-30	Fault Option Mode
	"賴痭淀硞舵暰倜      "	,	//	309  06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
	"耜殍1-倷冓尰Mins"	,	//	310  06-32	1st Fault Time(MIN)
	"耜殍1-倷冓尰Days"	,	//	311  06-33	1st Fault Time(DAY)
	"耜殍2-倷冓尰Mins"	,	//	312  06-34	2nd Fault Time(MIN)
	"耜殍2-倷冓尰Days"	,	//	313  06-35	2nd Fault Time(DAY)
	"耜殍3-倷冓尰Mins"	,	//	314  06-36	3rd Fault Time(MIN)
	"耜殍3-倷冓尰Days"	,	//	315  06-37	3rd Fault Time(DAY)
	"耜殍4-倷冓尰Mins"	,	//	316  06-38	4th Fault Time(MIN)
	"耜殍4-倷冓尰Days"	,	//	317  06-39	4th Fault Time(DAY)
	"耜殍5-倷冓尰Mins"	,	//	318  06-40	5th Fault Time(MIN)
	"耜殍5-倷冓尰Days"	,	//	319  06-41	5th Fault Time(DAY)
	"耜殍6-倷冓尰Mins"	,	//	320  06-42	6th Fault Time(MIN)
	"耜殍6-倷冓尰Days"	,	//	321  06-43	6th Fault Time(DAY)
    "邁-摵繂倵蓒箾陭z  "  ,   //  322  06-44	EPS Frequency
    "毚笭僁魆栚    BIN "  ,	//  323  06-45  LV Option Mode
    "毚笭嗐眓筎剡尰      "  ,	//  324  06-46  EPS Option Mode
    "閣衾請葮耜豭嵎sec "  ,   //  325  06-47  Generation Operation Detected Time
    "毆橆睙碪 萵   KVA "  ,   //  326  06-48  UPS Capacity (0.1KVA)
    "請摵頏欹STO       "  ,   //  3xx   06-49      STO Lock selection     //[Safty function, Bernie] 
    "諾雎豝 楅摵     "	,   //  356   06-50     Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "曼 蒎雎豝砫.sec "  ,   //  356   06-51     Auto restart times after fault     
    "誅甀隓.蒎雎豝 sec "  ,   //  356   06-52     Auto restart interval
    "煩覣摵睭.豝 Hz  "	,	//	99  15-99   Fkey Record
    "舵覣摵睭.豝 Hz  "	,	//	94 	 15-94   Fcmd Record"Out Freq. REC.  Hz  "	,	//	94 	15-94   Fcmd Record
    "舵瘑豝    Amps"	,	//	82   15-82	 Isum Record
    "з摵睭.婞寔.豝Hz  "	,	//	79   15-79	Fout Record
    "舵楅葮.豝   V   "	,	//	80   15-80	Vout Record
	"請葮.貥殎籺C.豝粯   "	,   //  81   15-81	Dcbus Record  
	"舵嗍橆.豝   KW  "	,	//	100 15-100  Power Record
	"舵嗍喿楀.豝 %   "	,	//	101 15-101  Torque Record
	"謬嗙.IGBT.豝   C  "	,	//	83  15-83	IGBT Temperature Record    
	"醣摵.婥摍.砱.豝筭ex "	,	//	102 15-102  MFI State Record
	"醣摵.楮摍舵豝筭ex "	,	//	103 15-103  MFO State Record
	"醣摵.葮寋痽豝筭ex "	,	//	104 15-104  Drive State Record
	"懈 瘑硞 UCMP  %   "  ,  //  3XX  06-65  Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
	"耜殍.痶摛蜣.        "  ,   //  3xx 06-66  Service time count                              //[Service time function, Bernie, 2017/03/14]
	"缽痶摛蜣.         "  ,   //  3xx 06-67   Service time function Enable                 //[Service time function, Bernie, 2017/03/14]
    "迗倵.睧PF     deg "  ,   //  EPS Detect Current    
    "迗倵.蒑睒.PF    deg "  ,   //  EPS Detect Current Ref
    "撿雎楅葮.繂倵.    "  ,   //  EPS Detect direction
    "迗倵.豝婭鉦窙舵廛ec "  ,   //  EPS MO Off Time
    "迗倵.豝婭鉦醑舵廛ec "  ,   //  EPS MO Off Time
    "鍋涴踴摍請葮倷蛢H   "	,	//	Running direction count high						
    "鍋涴踴摍請葮倷蛗L   "	,	//	Running direction count low
    "鍋涴.詰喿斒冔鉦 H   "	,	//	Temp running direction count high
    "鍋涴.詰喿斒冔鉠 L   "	,	//   Temp running direction count low
    "蹊頏幘雎僄軞請葮    "	,	//	Temp running reset count
    "懈閛搚雎僄軞請葮k   "	,	//	Running life
    "請摵頏椏雎堽檗    "	,	//	Running function
    "舵覣摵睭.豝 Hz  "  ,   //  Fcmd Record1"Out Freq. REC.  Hz  "
    "請葮.貥殎DC.豝V   "	,   //  Dcbus Record 1
    "舵瘑豝    Amps"  ,   //  Isum Record1
    "謬嗙.IGBT.豝  C   "  ,   //  IGBT Temperature Record1
    "舵覣摵睭.豝 Hz  "  ,   //  Fcmd Record2"Out Freq. REC.  Hz  "
    "請葮.貥殎DC.豝V   "	,   //  Dcbus Record2
    "舵瘑豝    Amps"  ,   //  Isum Record2
    "謬嗙.IGBT.豝  C   "  ,   //  IGBT Temperature Record2
    "舵覣摵睭.豝 Hz  "  ,   //  Fcmd Record3"Out Freq. REC.  Hz  "
    "請葮.貥殎DC.豝V   "	,   //  Dcbus Record3
    "舵瘑豝    Amps"  ,   //  Isum Record3
    "謬嗙.IGBT.豝  C   "  ,   //  IGBT Temperature Record3
    "舵覣摵睭.豝 Hz  "  ,   //  Fcmd Record4"Out Freq. REC.  Hz  "
    "請葮.貥殎DC.豝V   "	,   //  Dcbus Record4
    "舵瘑豝    Amps"  ,   //  Isum Record4
    "謬嗙.IGBT.豝  C   "  ,   //  IGBT Temperature Record4
    "舵覣摵睭.豝 Hz  "  ,   //  Fcmd Record5"Out Freq. REC.  Hz  "
    "請葮.貥Udc.豝 V   "	,   //  Dcbus Record5
    "舵瘑豝    Amps"  ,   //  Isum Record5
    "謬嗙.IGBT.豝  C   "  ,   //  IGBT Temperature Record5
    
/*---- GROUP 07-----------------------------------------*/ 
/*  "12345678901234561234"	*/
	"請葮缽衕睔傴趀覣V   "	,	//	327   07-00	SW Braking Level
    "BK Voltage Hold V   "  ,   //	328   07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
	"蹕渨C-瘑靸.摵冓   "	,	//	329   07-02	DCI Current Level      //[DCI Level when stop, Bernie, 05/21/2012]
	"耜殍DC蹕靸C瑱飶 sec "	,	//	330   07-03	DCI Time at Start 
	"耜殍DC蹕靸鎂睧  sec "	,	//	331   07-04	DCI Time at STOP
	"з摵睭DC嵋笝筅. Hz  "	,	//	332   07-05	DCI Freq. At start
	"管罽.蝁嵫.楅葮Ki    "	,	//	333   07-06	DCI KI
	"煩婭蝁筊砫殍sec "	,	//	334   07-07	Gear wait time when acceleration
	"煩婭蝁筊覣摵Hz  "	,	//	335   07-08	Gear wait frequency when acceleration
	"煩婭豝喿砫殍sec "	,	//	336   07-09	Gear wait time when deceleration
	"煩婭豝喿覣摵Hz  "	,	//	337   07-10	Gear wait frequency when deceleration
	"蹺眙楀嵫檺睔    "	,	//	338   07-11	Fan Control
	"煩婕楉嗍喿楀%   "	,	//	339   07-12	TQC Reference from RS485
	"詬瘑豝婕嗍    "	,	//	340   07-13	Source of Torque Command
	"標筈.蜬痭.嗍喿楀%   "	,	//	341   07-14	Torque max. level
	"囂瘔 豝婕嗍喿酨ec "	,	//	342   07-15	Torque command filter
	"槳瘑痵閛摍睔    "	,	//	343   07-16	Speed Limit selection
	"毚祤睖懈鉡摵%   "	,	//	344   07-17	Torque mode positive speed limit
	"毚祤睖懈鉡摵%   "	,	//	345   07-18	Torque mode negative speed limit
	"詬瘑摝淶.嗍喿   "	,	//	346   07-19	Torque offset selection
	"邀淶殎寊 嗍喿楀   "	,	//	347   07-20	Torque offset setting level
	"組馲.摝淶.嗍喿楀%   "	,	//	348   07-21	Torque offset setting level High
	"醜梊.摝淶.嗍喿楀%   "	,	//	349   07-22	Torque offset setting level Middle
	"諍笣.摝淶.嗍喿楀%   "	,	//	350   07-23	Torque offset setting level Low
	"懈閛嗍軨WD婞  %   "	,	//	351   07-24	FWD Motoring Tq Limit
	"懈閛嗍軨WD袀%   "	,	//	352   07-25	FWD Regeneration Tq Limit
	"懈閛嗍鄄EV婞  %   "	,	//	353   07-26	REV Motoring Tq Limit
	"懈閛嗍鄄EV袀%   "	,	//	354   07-27	REV Regeneration Tq Limit
	"贅葥眓鉧摵倎痭    "	,	//	355   07-28	Emergency Stop & Forced Stop selection
	"耜殍嬼楉笝楉嚗睖sec "	,	//	356   07-29   Torque Decrease Time
	"蹴痭.瘑硞DC瘑靸.%   "	,	//	356   07-30     STOP DC Inject Level    //[DCI Level when stop, Bernie, 05/21/2012]
	"BTT100             %"  ,   //  357 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect         "  ,   //  358 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Distance    ppr"  ,   //  359 07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect Time sec"  ,   //  360 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Fail Torq      "  ,   //  361 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Min Torq       "  ,   //  362 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Max Torq       "  ,   //  362 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"曼瘑碭楉楂蟈        "	,	//	357   08-00	PMotor Auto-Tuning  
	"豬 瘑蟈     Amps"	,	//	358   08-01	PMotor rated Current
	"豬嗍橆睙碪 蟈 Kw  "	,	//	359   08-02	PMotor Rated Power  
	"豬 摍睔睙碪 蟈RPM "	,	//	360   08-03	PMotor Rated RPM    
	"п摛瓡睒鍕痭 蟈     "	,	//	361   08-04	PMotor pole No.     
	"Rs 戫楶.婞寔.   ohm "	,	//	362   08-05	PMotor Rs           
	"Ld 戫楶.婞寔.       "	,	//	363   08-06	PMotor Ld           
	"Lq 戫楶.婞寔.   mH  "	,	//	364   08-07	PMotor Lq           
	"憾閛瘕厞 芫   Vrms"	,	//	365   08-08	PMotor Bemf coff	
	"Z-摝淶. 譚睒    deg "	,	//	366   08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
	"諾雎睔寊楀標蚇睒    "	,	//	367   08-10	//ADDED BY DINO                                      
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "啪雎愻擼褲      "	,	//	368   09-00	Comm Address                              
    "邁睔睙碪 COM    kbps"	,	//	369   09-01	Tranmission speed                         
    "毚倵.葠甀雸轄擼   "	,	//	370   09-02	Comm fault Treatment                      
    "覆欿-凅COM    sec "	,	//	371   09-03	Comm Time out                             
    "賴睭睠睒 愻擼     "	,	//	372   09-04	Comm Protocol                             
    "煩婭雺硞 睭眙瑱 ms  "	,	//	373   09-05	ASC remote Response Delay Time, 1=100us   
    "CAN_BUARD           "	,   //  3XX   09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "PDO_Tx_Time     ms  "	,   //  3XX   09-07    CAN PDO Handshaking Period  
    "CAN_Check_Time  ms  "	,   //  3XX   09-08    CAN Communiction Timeout
    "ID 筊訹鳱       "  ,   //  3XX   09-09    Elevator Control Identification Code
    "FHM 雎衯摵        "  ,   //  3XX   09-10
    "DLC 毚衯摵1       "  ,   //  3XX   09-11
    "DLC 毚衯摵2       "  ,   //  3XX   09-12
    "DLC 毚衯摵3       "  ,   //  3XX   09-13     
    "PDO TXTIME      ms  "  ,   //  3XX   09-14  CAN fail rate---aevin 6/12/2017  
/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"贅縻筊婭閛        "	,	//	374   10-00	Encoder TYPE                             
	"п摛嵁蜄貵痶ppr "	,	//	375   10-01	Encoder pulses	                    
	"贅萴寔楅覕俍筊婄    "	,	//	376   10-02	PG input setting	                
	"毚倵碄寍稃 縻   "	,	//	377   10-03	PG fbk fault treatment	            
	"煩婭雺曇寍稃俍sec "	,	//	378   10-04	PG fbk Error Detection Time	        
	"蹴痭殎儩魆栚媏楬%   "	,	//	379   10-05	PG fbk overspeed detection level	
	"憾楅鉯雎祒餑筊sec "	,	//	380   10-06	Over speed Detection Time	        
	"蹴痭殎嚌筊貵笴楬%   "	,	//	381   10-07	PG fbk speed deviation level	    
	"煩婭鉧栳冓邁睒嬮sec "	,	//	382   10-08	Deviation Detect Time	            
	"毚倵葮梑.摍睔     "	,	//	383   10-09	Operation at overspeed	            
	"請摵縻UVW       "  ,   //    384   10-10      Hall Input Types
	"0摍-摵筊罽 箋 %   "	,	//	385   10-11	KP gain of ASR in Zero speed	
	"0摍-摵筊罽 Ki sec "	,	//	386   10-12	Ki gain of ASR in Zero speed	
	"標摍睔.筊罽.箋%   "	,	//	387   10-13	ASR P Gain 1	                
	"標摍睔.筊罽.Kisec "	,	//	388   10-14	ASR I Gain 1	                
	"晝摍睔.筊罽.箋%   "	,	//	389   10-15	ASR P Gain 2	                
	"晝摍睔.筊罽.Kisec "	,	//	390   10-16	ASR I Gain 2	                
	"偯/2蒎雎窙.   Hz  "	,	//	391   10-17	ASR1/ASR2 switch freq	        
	"諾隓.偯躅 sec "	,	//	392   10-18	Primary LowPass filter Gain 
	"管楀蜬.葠趹 箋%   "  ,	//	393   10-19     position control Kp Gain  
    "�嵑偯邀凊�-畽 Hz  "  ,   //    394   10-20     Low Spd band
    "�嵑偯蹊睙�-畽 Hz  "  ,   //    395   10-21     High Spd band
	"譎淀.葠趹砫殍鮢ec "	,	//	396   10-22     Position control time
	"譎淀.葠躅   sec "	,	//	397   10-23     Position control LOW POSS FILTER
	"毚笭蝃葠趹    "	,	//	398   10-24     Source of position control, add by dino, 06/30/2008
	"0摍-碪.祒閛箋 %   "	,	//	399   10-25	KP gain of ASR in Zero speed of Landing
	"0摍-碪.祒閛槐 sec "	,	//	400   10-26	Ki gain of ASR in Zero speed of Landing
	"豭趹摵冓箋  %   "	,	//	385   10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"豭趹摵冓槐  sec "	,	//	386   10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"椎戫縻祒    "	,   //    4xx   10-29      PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
	"毚戫縻祒    "	,   //    4xx   10-30      PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C- 畽       "  ,   //  110 15-110  RESERVED       //[change parameter to normal group, Bernie, 2014/02/14]
    "賴梑.蝁筊蜬痭 m/s2"  ,   //    3XX  10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "賴梑.蝁筊痶楅跴ec "  ,   //    3XX  10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "賴梑.蝁筊楅摵   "  ,   //    3XX  10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"蹺閛砢. c嵎甀嗍惾ex "	,	//	401   11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "標筈.摍-碪 訹瞅苹/s "  ,   //  402   11-01   Lift operation speed                                        
    "楮倱. 熔      mm  "  ,   //  403   11-02   SHEAVE diameter			ADDED BY SCOTTY                     
    "諾雎婕雎媎筌.     "  ,   //  404   11-03   Gear Ratio                                              
    "豭訹摲凊          "  ,   //  405   11-04   Suspension ratio	                                        
    "管罽.嵋淀箾   %   "  ,   //  406   11-05   inertia	percent			ADDED BY SCOTTY                     
	"賬觛眓摍-碪 BWHz  "	,	//	407   11-06	Zero Speed Loop BandWidth	                                
	"標覕摍-碪 BW  Hz  "	,	//	408   11-07	Speed Loop BandWidth1		                                
	"晝貵駗摍-碪 BWHz  "	,	//	409   11-08	Speed Loop BandWidth2		                                
	"Kr 筊楀蜬.摍睔  %   "	,	//	410   11-09	PDFFKr		                                                
	"管罽.摍睔.砮淀梊%   "	,	//	411   11-10	SPEED FFD GAIN			ADDED BY SCOTTY                     
	"槳馽貵衴蓛. db  "	,	//	412   11-11	Netch filter deep(db)	                                    
	"槳馽貵覣摵. Hz  "	,	//	413   11-12	Netch filter frequency	                                    
	"躅婤婥摲  sec "	,	//	414   11-13	Low Pass Filter for display	                                
	"標筈蹕婞.蝁 %   "	,	//	415   11-14	ACC Max current                                             
    "標筈轔硞朓楋  m/s "  ,	//	416   11-15	max meter/sec	                                            
    "楮摲俶雎    Hex "  ,   //	417   11-16	Display address,add by dino 2007/03/08                      
    "楮摲婕楥鄳        "  ,	//	418   11-17	Display data,   add by dino 2007/03/08                      
    "煩橞瘕.朓         "  ,   //  419   11-18   Protect Bit	                                                
	"賬摍.祒閛毢W  Hz  "	,	//	420   11-19	Zero Speed Loop BandWidth of Landing
	"雎笭��          "	,	//	10    15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM    PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LPF for LC01    sec "	,	//	422 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Motor SPD RPM       "  ,   //  420   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_偌           "  ,   //  421   12-00
    "UMAP_偌           "  ,   //  422   12-01
    "UMAP_偌           "  ,   //  423   12-02
    "UMAP_偌           "  ,   //  424   12-33
    "UMAP_偌           "  ,   //  425   12-04
    "UMAP_偌           "  ,   //  426   12-05
    "UMAP_偌           "  ,   //  427   12-06
    "UMAP_偌           "  ,   //  428   12-07
    "UMAP_偌           "  ,   //  429   12-08
    "UMAP_偌           "  ,   //  430   12-09
    "UMAP_偌0          "  ,   //  431   12-10
    "UMAP_偌1          "  ,   //  432   12-11
    "UMAP_偌2          "  ,   //  433   12-12
    "UMAP_偌3          "  ,   //  434   12-13
    "UMAP_偌4          "  ,   //  435   12-14
    "UMAP_偌5          "  ,   //  436   12-15
    "UMAP_偌6          "  ,   //  437   12-16
    "UMAP_偌7          "  ,   //  438   12-17
    "UMAP_偌8          "  ,   //  439   12-18
    "UMAP_偌9          "  ,   //  440   12-19 
    "UMAP_偌0          "  ,   //  441   12-20
    "UMAP_偌1          "  ,   //  442   12-21
    "UMAP_偌2          "  ,   //  443   12-22
    "UMAP_偌3          "  ,   //  444   12-23
    "UMAP_偌4          "  ,   //  445   12-24
    "UMAP_偌5          "  ,   //  446   12-25
    "UMAP_偌6          "  ,   //  447   12-26
    "UMAP_偌7          "  ,   //  448   12-27
    "UMAP_偌8          "  ,   //  449   12-28
    "UMAP_偌9          "  ,   //  450   12-29
    "UMAP_偌0          "  ,   //  451   12-30
    "UMAP_偌1          "  ,   //  452   12-31
    "UMAP_偌2          "  ,   //  423   12-02
    "UMAP_偌3          "  ,   //  424   12-33
    "UMAP_偌4          "  ,   //  425   12-04
    "UMAP_偌5          "  ,   //  426   12-05
    "UMAP_偌6          "  ,   //  427   12-06
    "UMAP_偌7          "  ,   //  428   12-07
    "UMAP_偌8          "  ,   //  429   12-08
    "UMAP_偌9          "  ,   //  430   12-09
    "UMAP_偌0          "  ,   //  421   12-00
    "UMAP_偌1          "  ,   //  422   12-01
    "UMAP_偌2          "  ,   //  423   12-02
    "UMAP_偌3          "  ,   //  424   12-33
    "UMAP_偌4          "  ,   //  425   12-04
    "UMAP_偌5          "  ,   //  426   12-05
    "UMAP_偌6          "  ,   //  427   12-06
    "UMAP_偌7          "  ,   //  428   12-07
    "UMAP_偌8          "  ,   //  429   12-08
    "UMAP_偌9          "  ,   //  430   12-09
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
    "RESERVED            "  ,   //  421   12-00    
    "RESERVED            "  ,   //  422   12-01    
    "RESERVED            "  ,   //  423   12-02    
    "RESERVED            "  ,   //  424   12-33    
    "RESERVED            "  ,   //  425   12-04    
    "RESERVED            "  ,   //  426   12-05    
    "RESERVED            "  ,   //  427   12-06    
    "RESERVED            "  ,   //  428   12-07    
    "RESERVED            "  ,   //  429   12-08    
    "RESERVED            "  ,   //  430   12-09    
/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_敦蝸佽0        "  ,   //  453   13-00
    "UMAP_敦蝸佽1        "  ,   //  454   13-01
    "UMAP_敦蝸佽2        "  ,   //  455   13-02
    "UMAP_敦蝸佽3        "  ,   //  456   13-33
    "UMAP_敦蝸佽4        "  ,   //  457   13-04
    "UMAP_敦蝸佽5        "  ,   //  458   13-05
    "UMAP_敦蝸佽6        "  ,   //  459   13-06
    "UMAP_敦蝸佽7        "  ,   //  460   13-07
    "UMAP_敦蝸佽8        "  ,   //  461   13-08
    "UMAP_敦蝸佽9        "  ,   //  462   13-09
    "UMAP_敦蝸佽10       "  ,   //  463   13-10
    "UMAP_敦蝸佽11       "  ,   //  464   13-11
    "UMAP_敦蝸佽12       "  ,   //  465   13-12
    "UMAP_敦蝸佽13       "  ,   //  466   13-13
    "UMAP_敦蝸佽14       "  ,   //  467   13-14
    "UMAP_敦蝸佽15       "  ,   //  468   13-15
    "UMAP_敦蝸佽16       "  ,   //  469   13-16
    "UMAP_敦蝸佽17       "  ,   //  470   13-17
    "UMAP_敦蝸佽18       "  ,   //  471   13-18
    "UMAP_敦蝸佽19       "  ,   //  472   13-19
    "UMAP_敦蝸佽20       "  ,   //  473   13-20
    "UMAP_敦蝸佽21       "  ,   //  474   13-21
    "UMAP_敦蝸佽22       "  ,   //  475   13-22
    "UMAP_敦蝸佽23       "  ,   //  476   13-23
    "UMAP_敦蝸佽24       "  ,   //  477   13-24
    "UMAP_敦蝸佽25       "  ,   //  478   13-25
    "UMAP_敦蝸佽26       "  ,   //  479   13-26
    "UMAP_敦蝸佽27       "  ,   //  480   13-27
    "UMAP_敦蝸佽28       "  ,   //  481   13-28
    "UMAP_敦蝸佽29       "  ,   //  482   13-29
    "UMAP_敦蝸佽30       "  ,   //  483   13-30
    "UMAP_敦蝸佽31       "  ,   //  484   13-31
    "UMAP_敦蝸佽32       "  ,   //  455   13-02
    "UMAP_敦蝸佽33       "  ,   //  456   13-33
    "UMAP_敦蝸佽34       "  ,   //  457   13-04
    "UMAP_敦蝸佽35       "  ,   //  458   13-05
    "UMAP_敦蝸佽36       "  ,   //  459   13-06
    "UMAP_敦蝸佽37       "  ,   //  460   13-07
    "UMAP_敦蝸佽38       "  ,   //  461   13-08
    "UMAP_敦蝸佽39       "  ,   //  462   13-09
    "UMAP_敦蝸佽40       "  ,   //  453   13-00
    "UMAP_敦蝸佽41       "  ,   //  454   13-01
    "UMAP_敦蝸佽42       "  ,   //  455   13-02
    "UMAP_敦蝸佽43       "  ,   //  456   13-33
    "UMAP_敦蝸佽44       "  ,   //  457   13-04
    "UMAP_敦蝸佽45       "  ,   //  458   13-05
    "UMAP_敦蝸佽46       "  ,   //  459   13-06
    "UMAP_敦蝸佽47       "  ,   //  460   13-07
    "UMAP_敦蝸佽48       "  ,   //  461   13-08
    "UMAP_敦蝸佽49       "  ,   //  462   13-09
    "UMAP_DATA50         "  ,   //  453   13-00
    "UMAP_DATA51         "  ,   //  454   13-01
    "UMAP_DATA52         "  ,   //  455   13-02
    "UMAP_DATA53         "  ,   //  456   13-33
    "UMAP_DATA54         "  ,   //  457   13-04
    "UMAP_DATA55         "  ,   //  458   13-05
    "UMAP_DATA56         "  ,   //  459   13-06
    "UMAP_DATA57         "  ,   //  460   13-07
    "UMAP_DATA58         "  ,   //  461   13-08
    "UMAP_DATA59         "  ,   //  462   13-09
    "UMAP_DATA60         "  ,   //  453   13-00
    "UMAP_DATA61         "  ,   //  454   13-01
    "UMAP_DATA62         "  ,   //  455   13-02
    "UMAP_DATA63         "  ,   //  456   13-33
    "UMAP_DATA64         "  ,   //  457   13-04
    "UMAP_DATA65         "  ,   //  458   13-05
    "UMAP_DATA66         "  ,   //  459   13-06
    "UMAP_DATA67         "  ,   //  460   13-07
    "UMAP_DATA68         "  ,   //  461   13-08
    "UMAP_DATA69         "  ,   //  462   13-09
    "UMAP_DATA70         "  ,   //  453   13-00
    "UMAP_DATA71         "  ,   //  454   13-01
    "UMAP_DATA72         "  ,   //  455   13-02
    "UMAP_DATA73         "  ,   //  456   13-33
    "UMAP_DATA74         "  ,   //  457   13-04
    "UMAP_DATA75         "  ,   //  458   13-05
    "UMAP_DATA76         "  ,   //  459   13-06
    "UMAP_DATA77         "  ,   //  460   13-07
    "UMAP_DATA78         "  ,   //  461   13-08
    "UMAP_DATA79         "  ,   //  462   13-09
    "UMAP_DATA80         "  ,   //  453   13-00
    "UMAP_DATA81         "  ,   //  454   13-01
    "UMAP_DATA82         "  ,   //  455   13-02
    "UMAP_DATA83         "  ,   //  456   13-33
    "UMAP_DATA84         "  ,   //  457   13-04
    "UMAP_DATA85         "  ,   //  458   13-05
    "UMAP_DATA86         "  ,   //  459   13-06
    "UMAP_DATA87         "  ,   //  460   13-07
    "UMAP_DATA88         "  ,   //  461   13-08
    "UMAP_DATA89         "  ,   //  462   13-09
    "UMAP_DATA90         "  ,   //  453   13-00
    "UMAP_DATA91         "  ,   //  454   13-01
    "UMAP_DATA92         "  ,   //  455   13-02
    "UMAP_DATA93         "  ,   //  456   13-33
    "UMAP_DATA94         "  ,   //  457   13-04
    "UMAP_DATA95         "  ,   //  458   13-05
    "UMAP_DATA96         "  ,   //  459   13-06
    "UMAP_DATA97         "  ,   //  460   13-07
    "UMAP_DATA98         "  ,   //  461   13-08
    "UMAP_DATA99         "  ,   //  462   13-09
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE 蹴痭 %   "	,	//	485   14-00	Ids Power Save Level
	"毚笞.槱稃       "	,	//	486   14-01	VF voltage mode selection
	"毚蒎雎豻蜨稃1     "	,	//	487   14-02	Constant Torque Selection
	"曼藪楣撐暑      "	,	//	488   14-03	Auto Accel/Decel
	"菠.藪楣撐暑 T     "	,	//	489   14-04	Unit of Acc/Dec time
	"毚俍淀豇慥淀.     "	,	//	490   14-05	Power Save mode
	"槳瘑婑擔瑱棰眓      "	,	//	491   14-06	Stop Methods
	"毚眙颬.閛栻瑱       "	,	//	492   14-07	Reverse Operation
	"賴睧蝁1,眙馲Hz  "	,	//	493   14-08	Skip Freq. Point 1 upper limit
	"賴睧蝁1,楉笣Hz  "	,	//	494   14-09	Skip Freq. Point 1 lower limit
	"賴睧蝁2,眙馲Hz  "	,	//	495   14-10	Skip Freq. Point 2 upper limit
	"賴睧蝁2,楉笣Hz  "	,	//	496   14-11	Skip Freq. Point 2 lower limit
	"賴睧蝁3,眙馲Hz  "	,	//	497   14-12	Skip Freq. Point 3 upper limit
	"賴睧蝁3,楉笣Hz  "	,	//	498   14-13	Skip Freq. Point 3 lower limit
	"豬覣摵睭婞.2Hz  "	,	//	499   14-14	Motor Base Frequency 2
	"標筈.楅葮攃.婞.2V   "	,	//	500   14-15	Max Output Voltage 2
	"醜.覣摵睭 婞.2Hz  "	,	//	501   14-16	Mid Output Freq.2 1
	"醜.楅葮攃.1 婞.2V   "	,	//	502   14-17	Mid Output Voltage 2 1
	"醜.覣摵睭 婞.2Hz  "	,	//	503   14-18	Mid Output Freq.2 2
	"醜.楅葮攃.2 婞.2V   "	,	//	504   14-19	Mid Output Voltage 2 2
	"槭覣摵睭婞.2Hz  "	,	//	505   14-20	Min Output Freq. 2
	"槭楅葮攃. 婞.2V   "	,	//	506   14-21	Min Output Voltage 2
	"毚窙倷.Up/Down    "	,	//	507   14-22	up/down key mode
	"邁睔.窙倷.Up/Dwn    "	,	//	508   14-23	up/down key speed
	"請摵摞涴諑硞      "	,	//	509   14-24	Counter Value Set (Complete)
	"轔瑱摞涴諑硞      "	,	//	510   14-25	Counter Value Reach (Preset)
	"�硞詅豻倎�      "	,	//	511   14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"楮摍雎瘕. 砱痽 9    "	,	//	512   14-27	Multi-Function Input 9
	"楮摍雎瘕. 砱痽 A    "	,	//	513   14-28	Multi-Function Input 10
	"楮摍雎瘕. 砱痽 B    "	,	//	514   14-29	Multi-Function Input 11
	"楮摍雎瘕. 砱痽 C    "	,	//	515   14-30	Multi-Function Input 12
	"楮摍雎瘕. 砱痽 D    "	,	//	516   14-31	Multi-Function Input 13
	"楮摍雎瘕. 砱痽 E    "	,	//	517   14-32	Multi-Function Input 14
	"楮摍雎瘕. 砱痽 B    "	,	//	518   14-33	External Terminal Run after Fault Reset
	"舵栻ACI/AVI2      "	,	//	519   14-34	ACI change to AVI2
	"殖葠詄嵕.AI         "	,	//	520   14-35	Addition Function of AI
	"潦貵畽-葠趹       "	,	//	521   14-36	Multi-Position Point 1
	"潦貵畽-葠趹       "	,	//	522   14-37	Multi-Position Point 2
	"潦貵畽-葠趹       "	,	//	523   14-38	Multi-Position Point 3
	"潦貵畽-葠趹       "	,	//	524   14-39	Multi-Position Point 4
	"潦貵畽-葠趹       "	,	//	525   14-40	Multi-Position Point 5
	"潦貵畽-葠趹       "	,	//	526   14-41	Multi-Position Point 6
	"潦貵畽-葠趹       "	,	//	527   14-42	Multi-Position Point 7
	"潦貵畽-葠趹       "	,	//	528   14-43	Multi-Position Point 8
	"潦貵畽-葠趹       "	,	//	529   14-44	Multi-Position Point 9
	"潦貵畽-葠趹0      "	,	//	530   14-45	Multi-Position Point 10
	"潦貵畽-葠趹1      "	,	//	531   14-46	Multi-Position Point 11
	"潦貵畽-葠趹2      "	,	//	532   14-47	Multi-Position Point 12
	"潦貵畽-葠趹3      "	,	//	533   14-48	Multi-Position Point 13
	"潦貵畽-葠趹4      "	,	//	534   14-49	Multi-Position Point 14
	"潦貵畽-葠趹5      "	,	//	535   14-50	Multi-Position Point 15
	"舵栻婞寔. 1-2     "	,	//	536   14-51	Motor Selection 1 or 2
	"蹴痭.砬Y-D    Hz  "	,	//	537   14-52	Y-Delta Connected switching rpm
	"檗軠涷殎.Y-D        "	,	//	538   14-53	Y-Delta switched Enable
	"豬瘑 婞寔.2 Amps"	,	//	539   14-54	Motor 2 rated Current
	"毆橆睙碪 婞寔.2 Kw  "	,	//	540   14-55	Motor 2 Rated Power
	"豬覣摵睭婞.2RPM "	,	//	541   14-56	Motor 2 Rated RPM
	"п摛葠趀婞.2    "	,	//	542   14-57	Motor 2 pole No.
	"蹕槧婕 婞.2 Amps"	,	//	543   14-58	Motor 2 No-Load Current
	"Rs 婞寔凄殏   ohm "	,	//	544   14-59	Motor 2 Rs
	"Rr  婞寔凄殏2 ohm "	,	//	545   14-60	Motor 2 Rr
	"Lm 婞寔凄殏   mH  "	,	//	546   14-61	Motor 2 Lm
	"Lx 婞寔凄殏   mH  "	,	//	547   14-62	Motor 2 Lx
	"煩婭雺硞 Y-D        "	,	//	548   14-63	Y-Delta On delay time
	"蕭楉跁.摍-畽.蹴 V   "	,	//	549   14-64	OV stall level
	"阺.甀葾.雎觛 婞2    "	,	//	550   14-65	Thermal Relay 2 Selection
	"耜殍甀葾.雎觛2    "	,	//	551   14-66	Thermal Relay 2 Time
	"毚倵 葮痭倯 U     "	,	//	552   14-67	Momentary Power Loss
	"耜殍葮痭倯U sec "	,	//	553   14-68	Max. allowable PL time
	"旋睠.戫覣摵 sec "	,	//	554   14-69	BB Time for speed serach
	"懈鉰睠郈痽樠邁睔%   "	,	//	555   14-70	Current level for SPD serach
	"旋睠豳楅摵頏      "	,	//	556   14-71	bb treatment for oc, ov, bb
	"曼瘑毚摵冓        "	,	//	557   14-72	Auto restart after fault
	"槳瘑埬涫瑱飶      "	,	//	558   14-73	Auto restart Speed serach method
	"DEB 煩喿婤. SEL     "	,	//	559   14-74	Deceleration at Momertary Power loss 
	"DEB 翎豝砫殍    "	,	//	560   14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561   14-76	PID feedback selection	
	"管罽.P 蕈雎赶   "	,	//	562   14-77	P gain of PID	
	"管罽.I 蕈雎赶菋ec "	,	//	563   14-78	I gain of PID	
	"管罽.D 蕈雎赶   "	,	//	564   14-79	D gain of PID	
	"組痵閛嵋甀%   "	,	//	565   14-80	Upper bound for integral	
	"懈閛祒覣摵睭%   "	,	//	566   14-81	PID output Freq. Limit	
	"邀淶殎寊 蕈   %   "	,	//	567   14-82	PID offset	
	"煩婭雺硞 蕈   sec "	,	//	568   14-83	Derivative Filter Time Constant	
	"耜殍碄寍稃 臃ec "	,	//	569   14-84	Feedback signal detection time	
	"毚倵葠甀雸    "	,	//	570   14-85	PID feedback loss	
	"脣痽 摲毉崷 雎笭    "	,	//	571   14-86	Sleep Frequency	
	"舵槧摲毉崷 雎   "	,	//	572   14-87	Wake up Frequency	
	"煩婭雺. 摲毉.雎   "	,	//	573   14-88	Sleep Time	
	"標筈. 碄寍硞 蕈   "	,	//	574   14-89	PID Deviation Level	
	"耜殍碄寍稃 蕈   "	,	//	575   14-90	PID Deviation Time	
	"儸貵瘔  蕈sec "	,	//	576   14-91	PID feedback filter	
	"煩婕楥厞 覣摵睭粀z  "	,	//	577   14-92	Main Frequency from communication	
	"旋睠 蒎雎婕諑 1     "	,	//	578   14-93	Block Transfer 1	
	"旋睠 蒎雎婕諑 2     "	,	//	579   14-94	Block Transfer 2	
	"旋睠 蒎雎婕諑 3     "	,	//	580   14-95	Block Transfer 3
	"旋睠 蒎雎婕諑 4     "	,	//	581   14-96	Block Transfer 4
	"旋睠 蒎雎婕諑 5     "	,	//	582   14-97	Block Transfer 5
	"旋睠 蒎雎婕諑 6     "	,	//	583   14-98	Block Transfer 6
	"旋睠 蒎雎婕諑 7     "	,	//	584   14-99	Block Transfer 7
	"旋睠 蒎雎婕諑 8     "	,	//	585   14-100 Block Transfer 8
	"旋睠 蒎雎婕諑 9     "	,	//	586   14-101 Block Transfer 9
	"旋睠 蒎雎婕諑 10    "	,	//	587   14-102 Block Transfer 10
	"WEAKLPF             "	,	//	588   14-103 WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	589   14-104 WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	590   14-105 OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"豭趹俍殖      "	,	//	591   14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592   14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	593   14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	594   14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	595   14-110 FMax Target by Vcommand Position
	"毚赹隓              "	,	//	596   14-111 Accel. Time for Position
	"п摛嵕.雎媎筌. A    "	,	//	597   14-112 PG Mechanical Gear A
	"爺倱殎凄.雎媎   "	,	//	598   14-113 PG Mechanical Gear B
	"Jm 戫摵殍 PU  PU  "	,	//	599   14-114 Interia of motor PU
	"M1IdsRef 葮梊殏  %  "	,	//	600   14-115 Motor1 IdsRef Limit
	"M2IdsRef 葮梊殏  %  "	,	//	601   14-116 Motor2 IdsRef Limit
	"憾鳪鹹耜殍sec "	,	//	602   14-117 Phase Loss Time
	"TH Inside 謬嗙.  C  "	,	//	603   14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	604   14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	605   14-120 SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//	606   14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607   14-122 Tension of Torque Control
	"楮倱涴           "	,	//	608   14-123 Diameter of Material
	"DEPTH           cm  "	,	//	609   14-124 Depth of meterial
	"RESERVE             "	,	//	610   14-125 Reserve
	"ABZ ST Times        "	,	//	611   14-126 Reserve
	"ABZ ST Duty         "	,	//	612   14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	613   14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	614   14-129 Time of APR Curve
    "Jm source           "  ,   //	615   14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	616   14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	617   14-132 muti input state
    "StandStill Curr Amps"  ,   //  618   14-133 Standstill Current
	"PG Scale Factor     "	,	//	619   14-134 Division factor of PG	 
	"OLD Irate           "	,	//	619   14-135 OLD Irate       // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_蝃閛砢殎寊      "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_賴痭淀_耜殍 sec "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_耜殍   ms  "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    "啪雎褲 COM1       "	,	//	368   09-00	Comm Address           //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                      
	"邁睔睙碪 COM1   kbps"	,	//	369   09-01	Tranmission speed                         
	"毚倵.葠甀雸COM1     "	,	//	370   09-02	Comm fault Treatment                      
	"覆欿-凅榰OM1    sec "	,	//	371   09-03	Comm Time out                             
	"賴睭睠睒 COM1       "	,	//	372   09-04	Comm Protocol                             
	"擁寑. 愻擼COM1ms  "	,	//	373   09-05	ASC remote Response Delay Time, 1=100us 
    "鍋涴噙0單         "	,	//	3XX   14-146    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "鍋涴噙單          "	,	//	3XX   14-147    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "鍋涴噙單          "	,	//	3XX   14-148    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "鍋涴噙.5單        "	,	//	3XX   14-149    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "鍋涴噙.2單        "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "轔嵫.噙           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "轔嵫.噙           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "轔嵫.噙           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_EN
const string20 prinfo_DLC[DLC_TABLE] = { 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   
    "26F Position H  m   "  , //  2XX 04-80   26Floor Position H                                      
    "26F Position L  mm  "  , //  2XX 04-81   26Floor Position L                                      
    "27F Position H  m   "  , //  2XX 04-82   27Floor Position H                                      
    "27F Position L  mm  "  , //  2XX 04-83   27Floor Position L                                      
    "28F Position H  m   "  , //  2XX 04-84   28Floor Position H                                      
    "28F Position L  mm  "  , //  2XX 04-85   28Floor Position L                                      
    "29F Position H  m   "  , //  2XX 04-86   29Floor Position H                                      
    "29F Position L  mm  "  , //  2XX 04-87   29Floor Position L                                      
    "30F Position H  m   "  , //  2XX 04-88   30Floor Position H                                      
    "30F Position L  mm  "  , //  2XX 04-89   30Floor Position L                                      
    "31F Position H  m   "  , //  2XX 04-90   31Floor Position H                                      
    "31F Position L  mm  "  , //  2XX 04-91   31Floor Position L                                      
    "32F Position H  m   "  , //  2XX 04-92   32Floor Position H                                      
    "32F Position L  mm  "  , //  2XX 04-93   32Floor Position L                                      
    "33F Position H  m   "  , //  2XX 04-94   33Floor Position H                                      
    "33F Position L  mm  "  , //  2XX 04-95   33Floor Position L                                      
    "34F Position H  m   "  , //  2XX 04-96   34Floor Position H                                      
    "34F Position L  mm  "  , //  2XX 04-97   34Floor Position L                                      
    "35F Position H  m   "  , //  2XX 04-98   35Floor Position H                                      
    "35F Position L  mm  "  , //  2XX 04-99   35Floor Position L                                      
    "36F Position H  m   "  , //  2XX 04-100   Floor Position H
    "36F Position L  mm  "  , //  2XX 04-101   Floor Position L
    "37F Position H  m   "  , //  2XX 04-102   Floor Position H
    "37F Position L  mm  "  , //  2XX 04-103   Floor Position L                                                                    
    "38F Position H  m   "  , //  2XX 04-104   Floor Position H
    "38F Position L  mm  "  , //  2XX 04-105   Floor Position L
    "39F Position H  m   "  , //  2XX 04-106   Floor Position H
    "39F Position L  mm  "  , //  2XX 04-107   Floor Position L
    "40F Position H  m   "  , //  2XX 04-108   Floor Position H
    "40F Position L  mm  "  , //  2XX 04-109   Floor Position L
    "41F Position H  m   "  , //  2XX 04-110   Floor Position H
    "41F Position L  mm  "  , //  2XX 04-111   Floor Position L                                                                    
    "42F Position H  m   "  , //  2XX 04-112   Floor Position H
    "42F Position L  mm  "  , //  2XX 04-113   Floor Position L
    "43F Position H  m   "  , //  2XX 04-114   Floor Position H
    "43F Position L  mm  "  , //  2XX 04-115   Floor Position L
    "44F Position H  m   "  , //  2XX 04-116   Floor Position H
    "44F Position L  mm  "  , //  2XX 04-117   Floor Position L
    "45F Position H  m   "  , //  2XX 04-118   Floor Position H
    "45F Position L  mm  "  , //  2XX 04-119   Floor Position L                                                                    
    "46F Position H  m   "  , //  2XX 04-120   Floor Position H
    "46F Position L  mm  "  , //  2XX 04-121   Floor Position L
    "47F Position H  m   "  , //  2XX 04-121   Floor Position H
    "47F Position L  mm  "  , //  2XX 04-123   Floor Position L
    "48F Position H  m   "  , //  2XX 04-124   Floor Position H
    "48F Position L  mm  "  , //  2XX 04-125   Floor Position L
    "49F Position H  m   "  , //  2XX 04-126   Floor Position H
    "49F Position L  mm  "  , //  2XX 04-127   Floor Position L                                                                    
    "50F Position H  m   "  , //  2XX 04-128   Floor Position H
    "50F Position L  mm  "  , //  2XX 04-129   Floor Position L
};
const string20 prinfo_DLC2[DLC_TABLE] = 
{ 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   
    "51F Position H  m   "  , //  2XX 04-80   26Floor Position H                                      
    "51F Position L  mm  "  , //  2XX 04-81   26Floor Position L                                      
    "52F Position H  m   "  , //  2XX 04-82   27Floor Position H                                      
    "52F Position L  mm  "  , //  2XX 04-83   27Floor Position L                                      
    "53F Position H  m   "  , //  2XX 04-84   28Floor Position H                                      
    "53F Position L  mm  "  , //  2XX 04-85   28Floor Position L                                      
    "54F Position H  m   "  , //  2XX 04-86   29Floor Position H                                      
    "54F Position L  mm  "  , //  2XX 04-87   29Floor Position L                                      
    "55F Position H  m   "  , //  2XX 04-88   30Floor Position H                                      
    "55F Position L  mm  "  , //  2XX 04-89   30Floor Position L                                      
    "56F Position H  m   "  , //  2XX 04-90   31Floor Position H                                      
    "56F Position L  mm  "  , //  2XX 04-91   31Floor Position L                                      
    "57F Position H  m   "  , //  2XX 04-92   32Floor Position H                                      
    "57F Position L  mm  "  , //  2XX 04-93   32Floor Position L                                      
    "58F Position H  m   "  , //  2XX 04-94   33Floor Position H                                      
    "58F Position L  mm  "  , //  2XX 04-95   33Floor Position L                                      
    "59F Position H  m   "  , //  2XX 04-96   34Floor Position H                                      
    "59F Position L  mm  "  , //  2XX 04-97   34Floor Position L                                      
    "60F Position H  m   "  , //  2XX 04-98   35Floor Position H                                      
    "60F Position L  mm  "  , //  2XX 04-99   35Floor Position L                                      
    "61F Position H  m   "  , //  2XX 04-100   Floor Position H
    "61F Position L  mm  "  , //  2XX 04-101   Floor Position L
    "62F Position H  m   "  , //  2XX 04-102   Floor Position H
    "62F Position L  mm  "  , //  2XX 04-103   Floor Position L                                                                    
    "63F Position H  m   "  , //  2XX 04-104   Floor Position H
    "63F Position L  mm  "  , //  2XX 04-105   Floor Position L
    "64F Position H  m   "  , //  2XX 04-106   Floor Position H
    "64F Position L  mm  "  , //  2XX 04-107   Floor Position L
    "65F Position H  m   "  , //  2XX 04-108   Floor Position H
    "65F Position L  mm  "  , //  2XX 04-109   Floor Position L
    "66F Position H  m   "  , //  2XX 04-110   Floor Position H
    "66F Position L  mm  "  , //  2XX 04-111   Floor Position L                                                                    
    "67F Position H  m   "  , //  2XX 04-112   Floor Position H
    "67F Position L  mm  "  , //  2XX 04-113   Floor Position L
    "68F Position H  m   "  , //  2XX 04-114   Floor Position H
    "68F Position L  mm  "  , //  2XX 04-115   Floor Position L
    "69F Position H  m   "  , //  2XX 04-116   Floor Position H
    "69F Position L  mm  "  , //  2XX 04-117   Floor Position L
    "70F Position H  m   "  , //  2XX 04-118   Floor Position H
    "70F Position L  mm  "  , //  2XX 04-119   Floor Position L                                                                    
    "71F Position H  m   "  , //  2XX 04-120   Floor Position H
    "71F Position L  mm  "  , //  2XX 04-121   Floor Position L
    "72F Position H  m   "  , //  2XX 04-121   Floor Position H
    "72F Position L  mm  "  , //  2XX 04-123   Floor Position L
    "73F Position H  m   "  , //  2XX 04-124   Floor Position H
    "73F Position L  mm  "  , //  2XX 04-125   Floor Position L
    "74F Position H  m   "  , //  2XX 04-126   Floor Position H
    "74F Position L  mm  "  , //  2XX 04-127   Floor Position L                                                                    
    "75F Position H  m   "  , //  2XX 04-128   Floor Position H
    "75F Position L  mm  "  , //  2XX 04-129   Floor Position L
};

const string20 prinfo_DLC3[DLC_TABLE] =
{ 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   
    "DDS1 position H m   "  , //  2XX 04-80   26Floor Position H                                      
    "DDS1 Position L mm  "  , //  2XX 04-81   26Floor Position L                                      
    "DDS2 Position H m   "  , //  2XX 04-82   27Floor Position H                                      
    "DDS2 Position L mm  "  , //  2XX 04-83   27Floor Position L                                      
    "DDS3 Position H m   "  , //  2XX 04-84   28Floor Position H                                      
    "DDS3 Position L mm  "  , //  2XX 04-85   28Floor Position L                                      
    "DDS4 Position H m   "  , //  2XX 04-86   29Floor Position H                                      
    "DDS4 Position L mm  "  , //  2XX 04-87   29Floor Position L                                      
    "UDS1 Position H m   "  , //  2XX 04-88   30Floor Position H                                      
    "UDS1 Position L mm  "  , //  2XX 04-89   30Floor Position L                                      
    "UDS2 Position H m   "  , //  2XX 04-90   31Floor Position H                                      
    "UDS2 Position L mm  "  , //  2XX 04-91   31Floor Position L                                      
    "UDS3 Position H m   "  , //  2XX 04-92   32Floor Position H                                      
    "UDS3 Position L mm  "  , //  2XX 04-93   32Floor Position L                                      
    "UDS4 Position H m   "  , //  2XX 04-94   33Floor Position H                                      
    "UDS4 Position L mm  "  , //  2XX 04-95   33Floor Position L                                      
    "Reserved            "  , //  2XX 04-96   34Floor Position H                                      
    "Reserved            "  , //  2XX 04-97   34Floor Position L                                      
    "Reserved            "  , //  2XX 04-98   35Floor Position H                                      
    "Reserved            "  , //  2XX 04-99   35Floor Position L                                      
    "Reserved            "  , //  2XX 04-100   Floor Position H
    "Reserved            "  , //  2XX 04-101   Floor Position L
    "Reserved            "  , //  2XX 04-102   Floor Position H
    "Reserved            "  , //  2XX 04-103   Floor Position L                                                                    
    "Reserved            "  , //  2XX 04-104   Floor Position H
    "Reserved            "  , //  2XX 04-105   Floor Position L
    "Reserved            "  , //  2XX 04-106   Floor Position H
    "Reserved            "  , //  2XX 04-107   Floor Position L
    "Reserved            "  , //  2XX 04-108   Floor Position H
    "Reserved            "  , //  2XX 04-109   Floor Position L
    "Reserved            "  , //  2XX 04-110   Floor Position H
    "Reserved            "  , //  2XX 04-111   Floor Position L                                                                    
    "Reserved            "  , //  2XX 04-112   Floor Position H
    "Reserved            "  , //  2XX 04-113   Floor Position L
    "Reserved            "  , //  2XX 04-114   Floor Position H
    "Reserved            "  , //  2XX 04-115   Floor Position L
    "Reserved            "  , //  2XX 04-116   Floor Position H
    "Reserved            "  , //  2XX 04-117   Floor Position L
    "Reserved            "  , //  2XX 04-118   Floor Position H
    "Reserved            "  , //  2XX 04-119   Floor Position L                                                                    
    "Reserved            "  , //  2XX 04-120   Floor Position H
    "Reserved            "  , //  2XX 04-121   Floor Position L
    "Reserved            "  , //  2XX 04-121   Floor Position H
    "Reserved            "  , //  2XX 04-123   Floor Position L
    "Reserved            "  , //  2XX 04-124   Floor Position H
    "Reserved            "  , //  2XX 04-125   Floor Position L
    "Reserved            "  , //  2XX 04-126   Floor Position H
    "Reserved            "  , //  2XX 04-127   Floor Position L                                                                    
    "Reserved            "  , //  2XX 04-128   Floor Position H
    "Reserved            "  , //  2XX 04-129   Floor Position L
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_Adjst[DLC_TABLE] =
{ 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   

    "1F Up Offset    mm  "  ,      
    "2F Up Offset    mm  "  ,                                  
    "3F Up Offset    mm  "  ,          
    "4F Up Offset    mm  "  ,                                 
    "5F Up Offset    mm  "  ,                              
    "6F Up Offset    mm  "  ,                                  
    "7F Up Offset    mm  "  ,                             
    "8F Up Offset    mm  "  ,                                     
    "9F Up Offset    mm  "  ,                                 
    "10F Up Offset   mm  "  ,                                     
    "11F Up Offset   mm  "  ,                                  
    "12F Up Offset   mm  "  ,                                   
    "13F Up Offset   mm  "  ,                                 
    "14F Up Offset   mm  "  ,                                   
    "15F Up Offset   mm  "  ,                                 
    "16F Up Offset   mm  "  ,                                 
    "17F Up Offset   mm  "  ,                              
    "18F Up Offset   mm  "  ,                                    
    "19F Up Offset   mm  "  ,                                
    "20F Up Offset   mm  "  ,
    "21F Up Offset   mm  "  ,                                 
    "22F Up Offset   mm  "  ,                                   
    "23F Up Offset   mm  "  ,                                  
    "24F Up Offset   mm  "  ,                                    
    "25F Up Offset   mm  "  ,                               
    "26F Up Offset   mm  "  ,                               
    "27F Up Offset   mm  "  ,                             
    "28F Up Offset   mm  "  ,                                   
    "29F Up Offset   mm  "  ,                                    
    "30F Up Offset   mm  "  ,                                   
    "31F Up Offset   mm  "  ,                                   
    "32F Up Offset   mm  "  ,                                  
    "33F Up Offset   mm  "  ,                                   
    "34F Up Offset   mm  "  ,                                
    "35F Up Offset   mm  "  ,                                 
    "36F Up Offset   mm  "  ,                                 
    "37F Up Offset   mm  "  ,                                
    "38F Up Offset   mm  "  ,                                     
    "39F Up Offset   mm  "  ,                                     
    "40F Up Offset   mm  "  , 
    "41F Up Offset   mm  "  ,                                
    "42F Up Offset   mm  "  ,                                   
    "43F Up Offset   mm  "  ,                                 
    "44F Up Offset   mm  "  ,                                    
    "45F Up Offset   mm  "  ,                                 
    "46F Up Offset   mm  "  ,                                   
    "47F Up Offset   mm  "  ,                       
    "48F Up Offset   mm  "  ,                                  
    "49F Up Offset   mm  "  ,                                 
    "50F Up Offset   mm  "  ,
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_Adjst2[DLC_TABLE] =
{ 
 /* "12345678901234561234"  */  
    "1F Down Offset  mm  "  ,      
    "2F Down Offset  mm  "  ,                                  
    "3F Down Offset  mm  "  ,          
    "4F Down Offset  mm  "  ,                                 
    "5F Down Offset  mm  "  ,                              
    "6F Down Offset  mm  "  ,                                  
    "7F Down Offset  mm  "  ,                             
    "8F Down Offset  mm  "  ,                                     
    "9F Down Offset  mm  "  ,                                 
    "10F Down Offset mm  "  ,                                     
    "11F Down Offset mm  "  ,                                  
    "12F Down Offset mm  "  ,                                   
    "13F Down Offset mm  "  ,                                 
    "14F Down Offset mm  "  ,                                   
    "15F Down Offset mm  "  ,                                 
    "16F Down Offset mm  "  ,                                 
    "17F Down Offset mm  "  ,                              
    "18F Down Offset mm  "  ,                                    
    "19F Down Offset mm  "  ,                                
    "20F Down Offset mm  "  ,
    "21F Down Offset mm  "  ,                                 
    "22F Down Offset mm  "  ,                                   
    "23F Down Offset mm  "  ,                                  
    "24F Down Offset mm  "  ,                                    
    "25F Down Offset mm  "  ,                               
    "26F Down Offset mm  "  ,                               
    "27F Down Offset mm  "  ,                             
    "28F Down Offset mm  "  ,                                   
    "29F Down Offset mm  "  ,                                    
    "30F Down Offset mm  "  ,                                   
    "31F Down Offset mm  "  ,                                   
    "32F Down Offset mm  "  ,                                  
    "33F Down Offset mm  "  ,                                   
    "34F Down Offset mm  "  ,                                
    "35F Down Offset mm  "  ,                                 
    "36F Down Offset mm  "  ,                                 
    "37F Down Offset mm  "  ,                                
    "38F Down Offset mm  "  ,                                     
    "39F Down Offset mm  "  ,                                     
    "40F Down Offset mm  "  , 
    "41F Down Offset mm  "  ,                                
    "42F Down Offset mm  "  ,                                   
    "43F Down Offset mm  "  ,                                 
    "44F Down Offset mm  "  ,                                    
    "45F Down Offset mm  "  ,                                 
    "46F Down Offset mm  "  ,                                   
    "47F Down Offset mm  "  ,                       
    "48F Down Offset mm  "  ,
    "49F Down Offset mm  "  ,
    "50F Down Offset mm  "
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_Adjst3[DLC_TABLE] =
{ 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   

    "51F Up Offset   mm  "  ,      
    "52F Up Offset   mm  "  ,                                  
    "53F Up Offset   mm  "  ,          
    "54F Up Offset   mm  "  ,                                 
    "55F Up Offset   mm  "  ,                              
    "56F Up Offset   mm  "  ,                                  
    "57F Up Offset   mm  "  ,                             
    "58F Up Offset   mm  "  ,                                     
    "59F Up Offset   mm  "  ,                                 
    "60F Up Offset   mm  "  ,                                     
    "61F Up Offset   mm  "  ,                                  
    "62F Up Offset   mm  "  ,                                   
    "63F Up Offset   mm  "  ,                                 
    "64F Up Offset   mm  "  ,                                   
    "65F Up Offset   mm  "  ,                                 
    "66F Up Offset   mm  "  ,                                 
    "67F Up Offset   mm  "  ,                              
    "68F Up Offset   mm  "  ,                                    
    "69F Up Offset   mm  "  ,                                
    "70F Up Offset   mm  "  ,
    "71F Up Offset   mm  "  ,                                 
    "72F Up Offset   mm  "  ,                                   
    "73F Up Offset   mm  "  ,                                  
    "74F Up Offset   mm  "  ,                                    
    "75F Up Offset   mm  "  ,                               
    "51F Dn Offset   mm  "  ,                               
    "52F Dn Offset   mm  "  ,                             
    "53F Dn Offset   mm  "  ,                                   
    "54F Dn Offset   mm  "  ,                                    
    "55F Dn Offset   mm  "  ,                                   
    "56F Dn Offset   mm  "  ,                                   
    "57F Dn Offset   mm  "  ,                                  
    "58F Dn Offset   mm  "  ,                                   
    "59F Dn Offset   mm  "  ,                                
    "60F Dn Offset   mm  "  ,                                 
    "61F Dn Offset   mm  "  ,                                 
    "62F Dn Offset   mm  "  ,                                
    "63F Dn Offset   mm  "  ,                                     
    "64F Dn Offset   mm  "  ,                                     
    "65F Dn Offset   mm  "  , 
    "66F Dn Offset   mm  "  ,                                
    "67F Dn Offset   mm  "  ,                                   
    "68F Dn Offset   mm  "  ,                                 
    "69F Dn Offset   mm  "  ,                                    
    "70F Dn Offset   mm  "  ,                                 
    "71F Dn Offset   mm  "  ,                                   
    "72F Dn Offset   mm  "  ,                       
    "73F Dn Offset   mm  "  ,                                  
    "74F Dn Offset   mm  "  ,                                 
    "75F Dn Offset   mm  "  ,
};
#endif

#if Language_TC
const string20 prinfo_tc_DLC[DLC_TABLE] = {	            //[Modify DLC parameter, Bernie, 2016/01/22]
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/                                     
    "26樓位置 高     m   "  , //  2XX 04-80   26Floor Position H                                      
    "26樓位置 低     mm  "  , //  2XX 04-81   26Floor Position L                                      
    "27樓位置 高     m   "  , //  2XX 04-82   27Floor Position H                                      
    "27樓位置 低     mm  "  , //  2XX 04-83   27Floor Position L                                      
    "28樓位置 高     m   "  , //  2XX 04-84   28Floor Position H                                      
    "28樓位置 低     mm  "  , //  2XX 04-85   28Floor Position L                                      
    "29樓位置 高     m   "  , //  2XX 04-86   29Floor Position H                                      
    "29樓位置 低     mm  "  , //  2XX 04-87   29Floor Position L                                      
    "30樓位置 高     m   "  , //  2XX 04-88   30Floor Position H                                      
    "30樓位置 低     mm  "  , //  2XX 04-89   30Floor Position L                                      
    "31樓位置 高     m   "  , //  2XX 04-90   31Floor Position H                                      
    "31樓位置 低     mm  "  , //  2XX 04-91   31Floor Position L                                      
    "32樓位置 高     m   "  , //  2XX 04-92   32Floor Position H                                      
    "32樓位置 低     mm  "  , //  2XX 04-93   32Floor Position L                                      
    "33樓位置 高     m   "  , //  2XX 04-94   33Floor Position H                                      
    "33樓位置 低     mm  "  , //  2XX 04-95   33Floor Position L                                      
    "34樓位置 高     m   "  , //  2XX 04-96   34Floor Position H                                      
    "34樓位置 低     mm  "  , //  2XX 04-97   34Floor Position L                                      
    "35樓位置 高     m   "  , //  2XX 04-98   35Floor Position H                                      
    "35樓位置 低     mm  "  , //  2XX 04-99   35Floor Position L                                      
    "36樓位置 高     m   "  , //  2XX 04-100   36Floor Position H
    "36樓位置 低     mm  "  , //  2XX 04-101   36Floor Position L
    "37樓位置 高     m   "  , //  2XX 04-102   37Floor Position H
    "37樓位置 低     mm  "  , //  2XX 04-103   37Floor Position L
    "38樓位置 高     m   "  , //  2XX 04-104   38Floor Position H
    "38樓位置 低     mm  "  , //  2XX 04-105   38Floor Position L
    "39樓位置 高     m   "  , //  2XX 04-106   39Floor Position H
    "39樓位置 低     mm  "  , //  2XX 04-107   39Floor Position L
    "40樓位置 高     m   "  , //  2XX 04-108   40Floor Position H
    "40樓位置 低     mm  "  , //  2XX 04-109   40Floor Position L
    "41樓位置 高     m   "  , //  2XX 04-110   41Floor Position H
    "41樓位置 低     mm  "  , //  2XX 04-111   41Floor Position L
    "42樓位置 高     m   "  , //  2XX 04-112   42Floor Position H
    "42樓位置 低     mm  "  , //  2XX 04-113   42Floor Position L
    "43樓位置 高     m   "  , //  2XX 04-114   43Floor Position H
    "43樓位置 低     mm  "  , //  2XX 04-115   43Floor Position L
    "44樓位置 高     m   "  , //  2XX 04-116   44Floor Position H
    "44樓位置 低     mm  "  , //  2XX 04-117   44Floor Position L
    "45樓位置 高     m   "  , //  2XX 04-118   45Floor Position H
    "45樓位置 低     mm  "  , //  2XX 04-119   45Floor Position L
    "46樓位置 高     m   "  , //  2XX 04-120   46Floor Position H
    "46樓位置 低     mm  "  , //  2XX 04-121   46Floor Position L
    "47樓位置 高     m   "  , //  2XX 04-122   47Floor Position H
    "47樓位置 低     mm  "  , //  2XX 04-123   47Floor Position L
    "48樓位置 高     m   "  , //  2XX 04-124   48Floor Position H
    "48樓位置 低     mm  "  , //  2XX 04-125   48Floor Position L
    "49樓位置 高     m   "  , //  2XX 04-126   49Floor Position H
    "49樓位置 低     mm  "  , //  2XX 04-127   49Floor Position L
    "50樓位置 高     m   "  , //  2XX 04-128   50Floor Position H
    "50樓位置 低     mm  "  , //  2XX 04-129   50Floor Position L   
};

const string20 prinfo_tc_DLC2[DLC_TABLE] =
{               //[Modify DLC parameter, Bernie, 2016/01/22]
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"  */                                     
    "51樓位置 高     m   "  , //  2XX 04-80   26Floor Position H                                      
    "51樓位置 低     mm  "  , //  2XX 04-81   26Floor Position L                                      
    "52樓位置 高     m   "  , //  2XX 04-82   27Floor Position H                                      
    "52樓位置 低     mm  "  , //  2XX 04-83   27Floor Position L                                      
    "53樓位置 高     m   "  , //  2XX 04-84   28Floor Position H                                      
    "53樓位置 低     mm  "  , //  2XX 04-85   28Floor Position L                                      
    "54樓位置 高     m   "  , //  2XX 04-86   29Floor Position H                                      
    "54樓位置 低     mm  "  , //  2XX 04-87   29Floor Position L                                      
    "55樓位置 高     m   "  , //  2XX 04-88   30Floor Position H                                      
    "55樓位置 低     mm  "  , //  2XX 04-89   30Floor Position L                                      
    "56樓位置 高     m   "  , //  2XX 04-90   31Floor Position H                                      
    "56樓位置 低     mm  "  , //  2XX 04-91   31Floor Position L                                      
    "57樓位置 高     m   "  , //  2XX 04-92   32Floor Position H                                      
    "57樓位置 低     mm  "  , //  2XX 04-93   32Floor Position L                                      
    "58樓位置 高     m   "  , //  2XX 04-94   33Floor Position H                                      
    "58樓位置 低     mm  "  , //  2XX 04-95   33Floor Position L                                      
    "59樓位置 高     m   "  , //  2XX 04-96   34Floor Position H                                      
    "59樓位置 低     mm  "  , //  2XX 04-97   34Floor Position L                                      
    "60樓位置 高     m   "  , //  2XX 04-98   35Floor Position H                                      
    "60樓位置 低     mm  "  , //  2XX 04-99   35Floor Position L                                      
    "61樓位置 高     m   "  , //  2XX 04-100   36Floor Position H
    "61樓位置 低     mm  "  , //  2XX 04-101   36Floor Position L
    "62樓位置 高     m   "  , //  2XX 04-102   37Floor Position H
    "62樓位置 低     mm  "  , //  2XX 04-103   37Floor Position L
    "63樓位置 高     m   "  , //  2XX 04-104   38Floor Position H
    "63樓位置 低     mm  "  , //  2XX 04-105   38Floor Position L
    "64樓位置 高     m   "  , //  2XX 04-106   39Floor Position H
    "64樓位置 低     mm  "  , //  2XX 04-107   39Floor Position L
    "65樓位置 高     m   "  , //  2XX 04-108   40Floor Position H
    "65樓位置 低     mm  "  , //  2XX 04-109   40Floor Position L
    "66樓位置 高     m   "  , //  2XX 04-110   41Floor Position H
    "66樓位置 低     mm  "  , //  2XX 04-111   41Floor Position L
    "67樓位置 高     m   "  , //  2XX 04-112   42Floor Position H
    "67樓位置 低     mm  "  , //  2XX 04-113   42Floor Position L
    "68樓位置 高     m   "  , //  2XX 04-114   43Floor Position H
    "68樓位置 低     mm  "  , //  2XX 04-115   43Floor Position L
    "69樓位置 高     m   "  , //  2XX 04-116   44Floor Position H
    "69樓位置 低     mm  "  , //  2XX 04-117   44Floor Position L
    "70樓位置 高     m   "  , //  2XX 04-118   45Floor Position H
    "70樓位置 低     mm  "  , //  2XX 04-119   45Floor Position L
    "71樓位置 高     m   "  , //  2XX 04-120   46Floor Position H
    "71樓位置 低     mm  "  , //  2XX 04-121   46Floor Position L
    "72樓位置 高     m   "  , //  2XX 04-122   47Floor Position H
    "72樓位置 低     mm  "  , //  2XX 04-123   47Floor Position L
    "73樓位置 高     m   "  , //  2XX 04-124   48Floor Position H
    "73樓位置 低     mm  "  , //  2XX 04-125   48Floor Position L
    "74樓位置 高     m   "  , //  2XX 04-126   49Floor Position H
    "74樓位置 低     mm  "  , //  2XX 04-127   49Floor Position L
    "75樓位置 高     m   "  , //  2XX 04-128   50Floor Position H
    "75樓位置 低     mm  "  , //  2XX 04-129   50Floor Position L   
};

const string20 prinfo_tc_DLC3[DLC_TABLE] =
{
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"  */                                     
    "DDS1位置 高     m   "  ,                                    
    "DDS1位置 低     mm  "  ,                                      
    "DDS2位置 高     m   "  ,                                      
    "DDS2位置 低     mm  "  ,                                      
    "DDS3位置 高     m   "  ,                                      
    "DDS3位置 低     mm  "  ,                                    
    "DDS4位置 高     m   "  ,                                     
    "DDS4位置 低     mm  "  ,                                     
    "UDS1位置 高     m   "  ,                                     
    "UDS1位置 低     mm  "  ,                                
    "UDS2位置 高     m   "  ,                                   
    "UDS2位置 低     mm  "  ,                                     
    "UDS3位置 高     m   "  ,                                     
    "UDS3位置 低     mm  "  ,                                     
    "UDS4位置 高     m   "  ,                                   
    "UDS4位置 低     mm  "  ,                                    
    "保留                "  ,                                   
    "保留                "  ,                                    
    "保留                "  ,                                  
    "保留                "  ,                                   
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,
    "保留                "  ,  
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_tc_Adjst[DLC_TABLE] =
{ 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   

    "1F Up Offset    mm  "  ,      
    "2F Up Offset    mm  "  ,                                  
    "3F Up Offset    mm  "  ,          
    "4F Up Offset    mm  "  ,                                 
    "5F Up Offset    mm  "  ,                              
    "6F Up Offset    mm  "  ,                                  
    "7F Up Offset    mm  "  ,                             
    "8F Up Offset    mm  "  ,                                     
    "9F Up Offset    mm  "  ,                                 
    "10F Up Offset   mm  "  ,                                     
    "11F Up Offset   mm  "  ,                                  
    "12F Up Offset   mm  "  ,                                   
    "13F Up Offset   mm  "  ,                                 
    "14F Up Offset   mm  "  ,                                   
    "15F Up Offset   mm  "  ,                                 
    "16F Up Offset   mm  "  ,                                 
    "17F Up Offset   mm  "  ,                              
    "18F Up Offset   mm  "  ,                                    
    "19F Up Offset   mm  "  ,                                
    "20F Up Offset   mm  "  ,
    "21F Up Offset   mm  "  ,                                 
    "22F Up Offset   mm  "  ,                                   
    "23F Up Offset   mm  "  ,                                  
    "24F Up Offset   mm  "  ,                                    
    "25F Up Offset   mm  "  ,                               
    "26F Up Offset   mm  "  ,                               
    "27F Up Offset   mm  "  ,                             
    "28F Up Offset   mm  "  ,                                   
    "29F Up Offset   mm  "  ,                                    
    "30F Up Offset   mm  "  ,                                   
    "31F Up Offset   mm  "  ,                                   
    "32F Up Offset   mm  "  ,                                  
    "33F Up Offset   mm  "  ,                                   
    "34F Up Offset   mm  "  ,                                
    "35F Up Offset   mm  "  ,                                 
    "36F Up Offset   mm  "  ,                                 
    "37F Up Offset   mm  "  ,                                
    "38F Up Offset   mm  "  ,                                     
    "39F Up Offset   mm  "  ,                                     
    "40F Up Offset   mm  "  , 
    "41F Up Offset   mm  "  ,                                
    "42F Up Offset   mm  "  ,                                   
    "43F Up Offset   mm  "  ,                                 
    "44F Up Offset   mm  "  ,                                    
    "45F Up Offset   mm  "  ,                                 
    "46F Up Offset   mm  "  ,                                   
    "47F Up Offset   mm  "  ,                       
    "48F Up Offset   mm  "  ,                                  
    "49F Up Offset   mm  "  ,                                 
    "50F Up Offset   mm  "  ,
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_tc_Adjst2[DLC_TABLE] =
{
 /* "12345678901234561234"  */  
    "1F Down Offset  mm  "  ,      
    "2F Down Offset  mm  "  ,                                  
    "3F Down Offset  mm  "  ,          
    "4F Down Offset  mm  "  ,                                 
    "5F Down Offset  mm  "  ,                              
    "6F Down Offset  mm  "  ,                                  
    "7F Down Offset  mm  "  ,                             
    "8F Down Offset  mm  "  ,                                     
    "9F Down Offset  mm  "  ,                                 
    "10F Down Offset mm  "  ,                                     
    "11F Down Offset mm  "  ,                                  
    "12F Down Offset mm  "  ,                                   
    "13F Down Offset mm  "  ,                                 
    "14F Down Offset mm  "  ,                                   
    "15F Down Offset mm  "  ,                                 
    "16F Down Offset mm  "  ,                                 
    "17F Down Offset mm  "  ,                              
    "18F Down Offset mm  "  ,                                    
    "19F Down Offset mm  "  ,                                
    "20F Down Offset mm  "  ,
    "21F Down Offset mm  "  ,                                 
    "22F Down Offset mm  "  ,                                   
    "23F Down Offset mm  "  ,                                  
    "24F Down Offset mm  "  ,                                    
    "25F Down Offset mm  "  ,                               
    "26F Down Offset mm  "  ,                               
    "27F Down Offset mm  "  ,                             
    "28F Down Offset mm  "  ,                                   
    "29F Down Offset mm  "  ,                                    
    "30F Down Offset mm  "  ,                                   
    "31F Down Offset mm  "  ,                                   
    "32F Down Offset mm  "  ,                                  
    "33F Down Offset mm  "  ,                                   
    "34F Down Offset mm  "  ,                                
    "35F Down Offset mm  "  ,                                 
    "36F Down Offset mm  "  ,                                 
    "37F Down Offset mm  "  ,                                
    "38F Down Offset mm  "  ,                                     
    "39F Down Offset mm  "  ,                                     
    "40F Down Offset mm  "  , 
    "41F Down Offset mm  "  ,                                
    "42F Down Offset mm  "  ,                                   
    "43F Down Offset mm  "  ,                                 
    "44F Down Offset mm  "  ,                                    
    "45F Down Offset mm  "  ,                                 
    "46F Down Offset mm  "  ,                                   
    "47F Down Offset mm  "  ,                       
    "48F Down Offset mm  "  ,
    "49F Down Offset mm  "  ,
    "50F Down Offset mm  "
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_tc_Adjst3[DLC_TABLE] =
{ 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   

    "51F Up Offset   mm  "  ,      
    "52F Up Offset   mm  "  ,                                  
    "53F Up Offset   mm  "  ,          
    "54F Up Offset   mm  "  ,                                 
    "55F Up Offset   mm  "  ,                              
    "56F Up Offset   mm  "  ,                                  
    "57F Up Offset   mm  "  ,                             
    "58F Up Offset   mm  "  ,                                     
    "59F Up Offset   mm  "  ,                                 
    "60F Up Offset   mm  "  ,                                     
    "61F Up Offset   mm  "  ,                                  
    "62F Up Offset   mm  "  ,                                   
    "63F Up Offset   mm  "  ,                                 
    "64F Up Offset   mm  "  ,                                   
    "65F Up Offset   mm  "  ,                                 
    "66F Up Offset   mm  "  ,                                 
    "67F Up Offset   mm  "  ,                              
    "68F Up Offset   mm  "  ,                                    
    "69F Up Offset   mm  "  ,                                
    "70F Up Offset   mm  "  ,
    "71F Up Offset   mm  "  ,                                 
    "72F Up Offset   mm  "  ,                                   
    "73F Up Offset   mm  "  ,                                  
    "74F Up Offset   mm  "  ,                                    
    "75F Up Offset   mm  "  ,                               
    "51F Dn Offset   mm  "  ,                               
    "52F Dn Offset   mm  "  ,                             
    "53F Dn Offset   mm  "  ,                                   
    "54F Dn Offset   mm  "  ,                                    
    "55F Dn Offset   mm  "  ,                                   
    "56F Dn Offset   mm  "  ,                                   
    "57F Dn Offset   mm  "  ,                                  
    "58F Dn Offset   mm  "  ,                                   
    "59F Dn Offset   mm  "  ,                                
    "60F Dn Offset   mm  "  ,                                 
    "61F Dn Offset   mm  "  ,                                 
    "62F Dn Offset   mm  "  ,                                
    "63F Dn Offset   mm  "  ,                                     
    "64F Dn Offset   mm  "  ,                                     
    "65F Dn Offset   mm  "  , 
    "66F Dn Offset   mm  "  ,                                
    "67F Dn Offset   mm  "  ,                                   
    "68F Dn Offset   mm  "  ,                                 
    "69F Dn Offset   mm  "  ,                                    
    "70F Dn Offset   mm  "  ,                                 
    "71F Dn Offset   mm  "  ,                                   
    "72F Dn Offset   mm  "  ,                       
    "73F Dn Offset   mm  "  ,                                  
    "74F Dn Offset   mm  "  ,                                 
    "75F Dn Offset   mm  "  ,
};
#endif

#if Language_SC
const string20 prinfo_sc_DLC[DLC_TABLE] = {	
  /*---- GROUP 04---------------------------------------*/						
  /*  "12345678901234561234"	*/					
  "26瞼弇离 詢     m   "  , //  2XX 04-80   26Floor Position H                                      
  "26瞼弇离 腴     mm  "  , //  2XX 04-81   26Floor Position L                                      
  "27瞼弇离 詢     m   "  , //  2XX 04-82   27Floor Position H                                      
  "27瞼弇离 腴     mm  "  , //  2XX 04-83   27Floor Position L                                      
  "28瞼弇离 詢     m   "  , //  2XX 04-84   28Floor Position H                                      
  "28瞼弇离 腴     mm  "  , //  2XX 04-85   28Floor Position L                                      
  "29瞼弇离 詢     m   "  , //  2XX 04-86   29Floor Position H                                      
  "29瞼弇离 腴     mm  "  , //  2XX 04-87   29Floor Position L                                      
  "30瞼弇离 詢     m   "  , //  2XX 04-88   30Floor Position H                                      
  "30瞼弇离 腴     mm  "  , //  2XX 04-89   30Floor Position L                                      
  "31瞼弇离 詢     m   "  , //  2XX 04-90   31Floor Position H                                      
  "31瞼弇离 腴     mm  "  , //  2XX 04-91   31Floor Position L                                      
  "32瞼弇离 詢     m   "  , //  2XX 04-92   32Floor Position H                                      
  "32瞼弇离 腴     mm  "  , //  2XX 04-93   32Floor Position L                                      
  "33瞼弇离 詢     m   "  , //  2XX 04-94   33Floor Position H                                      
  "33瞼弇离 腴     mm  "  , //  2XX 04-95   33Floor Position L                                      
  "34瞼弇离 詢     m   "  , //  2XX 04-96   34Floor Position H                                      
  "34瞼弇离 腴     mm  "  , //  2XX 04-97   34Floor Position L                                      
  "35瞼弇离 詢     m   "  , //  2XX 04-98   35Floor Position H 
  "35瞼弇离 腴     mm  "  , //  2XX 04-99   35Floor Position L 
  "36瞼弇离 詢     m   "  , //  2XX 04-100   36Floor Position H
  "36瞼弇离 腴     mm  "  , //  2XX 04-101   36Floor Position L
  "37瞼弇离 詢     m   "  , //  2XX 04-102   37Floor Position H
  "37瞼弇离 腴     mm  "  , //  2XX 04-103   37Floor Position L
  "38瞼弇离 詢     m   "  , //  2XX 04-104   38Floor Position H
  "38瞼弇离 腴     mm  "  , //  2XX 04-105   38Floor Position L
  "39瞼弇离 詢     m   "  , //  2XX 04-106   39Floor Position H
  "39瞼弇离 腴     mm  "  , //  2XX 04-107   39Floor Position L
  "40瞼弇离 詢     m   "  , //  2XX 04-108   40Floor Position H
  "40瞼弇离 腴     mm  "  , //  2XX 04-109   40Floor Position L
  "41瞼弇离 詢     m   "  , //  2XX 04-110   41Floor Position H
  "41瞼弇离 腴     mm  "  , //  2XX 04-111   41Floor Position L
  "42瞼弇离 詢     m   "  , //  2XX 04-112   42Floor Position H
  "42瞼弇离 腴     mm  "  , //  2XX 04-113   42Floor Position L
  "43瞼弇离 詢     m   "  , //  2XX 04-114   43Floor Position H
  "43瞼弇离 腴     mm  "  , //  2XX 04-115   43Floor Position L
  "44瞼弇离 詢     m   "  , //  2XX 04-116   44Floor Position H
  "44瞼弇离 腴     mm  "  , //  2XX 04-117   44Floor Position L
  "45瞼弇离 詢     m   "  , //  2XX 04-118   45Floor Position H
  "45瞼弇离 腴     mm  "  , //  2XX 04-119   45Floor Position L
  "46瞼弇离 詢     m   "  , //  2XX 04-120   46Floor Position H
  "46瞼弇离 腴     mm  "  , //  2XX 04-121   46Floor Position L
  "47瞼弇离 詢     m   "  , //  2XX 04-122   47Floor Position H
  "47瞼弇离 腴     mm  "  , //  2XX 04-123   47Floor Position L
  "48瞼弇离 詢     m   "  , //  2XX 04-124   48Floor Position H
  "48瞼弇离 腴     mm  "  , //  2XX 04-125   48Floor Position L
  "49瞼弇离 詢     m   "  , //  2XX 04-126   49Floor Position H
  "49瞼弇离 腴     mm  "  , //  2XX 04-127   49Floor Position L
  "50瞼弇离 詢     m   "  , //  2XX 04-128   50Floor Position H
  "50瞼弇离 腴     mm  "  , //  2XX 04-129   50Floor Position L

};

const string20 prinfo_sc_DLC2[DLC_TABLE] = {	
  /*---- GROUP 04---------------------------------------*/						
  /*  "12345678901234561234"	*/					
  "51瞼弇离 詢     m   "  , //  2XX 04-80   26Floor Position H                                      
  "51瞼弇离 腴     mm  "  , //  2XX 04-81   26Floor Position L                                      
  "52瞼弇离 詢     m   "  , //  2XX 04-82   27Floor Position H                                      
  "52瞼弇离 腴     mm  "  , //  2XX 04-83   27Floor Position L                                      
  "53瞼弇离 詢     m   "  , //  2XX 04-84   28Floor Position H                                      
  "53瞼弇离 腴     mm  "  , //  2XX 04-85   28Floor Position L                                      
  "54瞼弇离 詢     m   "  , //  2XX 04-86   29Floor Position H                                      
  "54瞼弇离 腴     mm  "  , //  2XX 04-87   29Floor Position L                                      
  "55瞼弇离 詢     m   "  , //  2XX 04-88   30Floor Position H                                      
  "55瞼弇离 腴     mm  "  , //  2XX 04-89   30Floor Position L                                      
  "56瞼弇离 詢     m   "  , //  2XX 04-90   31Floor Position H                                      
  "56瞼弇离 腴     mm  "  , //  2XX 04-91   31Floor Position L                                      
  "57瞼弇离 詢     m   "  , //  2XX 04-92   32Floor Position H                                      
  "57瞼弇离 腴     mm  "  , //  2XX 04-93   32Floor Position L                                      
  "58瞼弇离 詢     m   "  , //  2XX 04-94   33Floor Position H                                      
  "58瞼弇离 腴     mm  "  , //  2XX 04-95   33Floor Position L                                      
  "59瞼弇离 詢     m   "  , //  2XX 04-96   34Floor Position H                                      
  "59瞼弇离 腴     mm  "  , //  2XX 04-97   34Floor Position L                                      
  "60瞼弇离 詢     m   "  , //  2XX 04-98   35Floor Position H 
  "60瞼弇离 腴     mm  "  , //  2XX 04-99   35Floor Position L 
  "61瞼弇离 詢     m   "  , //  2XX 04-100   36Floor Position H
  "61瞼弇离 腴     mm  "  , //  2XX 04-101   36Floor Position L
  "62瞼弇离 詢     m   "  , //  2XX 04-102   37Floor Position H
  "62瞼弇离 腴     mm  "  , //  2XX 04-103   37Floor Position L
  "63瞼弇离 詢     m   "  , //  2XX 04-104   38Floor Position H
  "63瞼弇离 腴     mm  "  , //  2XX 04-105   38Floor Position L
  "64瞼弇离 詢     m   "  , //  2XX 04-106   39Floor Position H
  "64瞼弇离 腴     mm  "  , //  2XX 04-107   39Floor Position L
  "65瞼弇离 詢     m   "  , //  2XX 04-108   40Floor Position H
  "65瞼弇离 腴     mm  "  , //  2XX 04-109   40Floor Position L
  "66瞼弇离 詢     m   "  , //  2XX 04-110   41Floor Position H
  "66瞼弇离 腴     mm  "  , //  2XX 04-111   41Floor Position L
  "67瞼弇离 詢     m   "  , //  2XX 04-112   42Floor Position H
  "67瞼弇离 腴     mm  "  , //  2XX 04-113   42Floor Position L
  "68瞼弇离 詢     m   "  , //  2XX 04-114   43Floor Position H
  "68瞼弇离 腴     mm  "  , //  2XX 04-115   43Floor Position L
  "69瞼弇离 詢     m   "  , //  2XX 04-116   44Floor Position H
  "69瞼弇离 腴     mm  "  , //  2XX 04-117   44Floor Position L
  "70瞼弇离 詢     m   "  , //  2XX 04-118   45Floor Position H
  "70瞼弇离 腴     mm  "  , //  2XX 04-119   45Floor Position L
  "71瞼弇离 詢     m   "  , //  2XX 04-120   46Floor Position H
  "71瞼弇离 腴     mm  "  , //  2XX 04-121   46Floor Position L
  "72瞼弇离 詢     m   "  , //  2XX 04-122   47Floor Position H
  "72瞼弇离 腴     mm  "  , //  2XX 04-123   47Floor Position L
  "73瞼弇离 詢     m   "  , //  2XX 04-124   48Floor Position H
  "73瞼弇离 腴     mm  "  , //  2XX 04-125   48Floor Position L
  "74瞼弇离 詢     m   "  , //  2XX 04-126   49Floor Position H
  "74瞼弇离 腴     mm  "  , //  2XX 04-127   49Floor Position L
  "75瞼弇离 詢     m   "  , //  2XX 04-128   50Floor Position H
  "75瞼弇离 腴     mm  "  , //  2XX 04-129   50Floor Position L

};

// JINGDO
const string20 prinfo_sc_DLC3[DLC_TABLE] = {
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/                                     
    "DDS1弇离 詢     m   "  ,                                    
    "DDS1弇离 腴     mm  "  ,                                      
    "DDS2弇离 詢     m   "  ,                                      
    "DDS2弇离 腴     mm  "  ,                                      
    "DDS3弇离 詢     m   "  ,                                      
    "DDS3弇离 腴     mm  "  ,                                    
    "DDS4弇离 詢     m   "  ,                                     
    "DDS4弇离 腴     mm  "  ,                                     
    "UDS1弇离 詢     m   "  ,                                     
    "UDS1弇离 腴     mm  "  ,                                
    "UDS2弇离 詢     m   "  ,                                   
    "UDS2弇离 腴     mm  "  ,                                     
    "UDS3弇离 詢     m   "  ,                                     
    "UDS3弇离 腴     mm  "  ,                                     
    "UDS4弇离 詢     m   "  ,                                   
    "UDS4弇离 腴     mm  "  ,                                    
    "悵隱                "  ,                                   
    "悵隱                "  ,                                    
    "悵隱                "  ,                                  
    "悵隱                "  ,                                   
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,
    "悵隱                "  ,  
};


//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_sc_Adjst[DLC_TABLE] = { 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   

    "1F Up Offset    mm  "  ,      
    "2F Up Offset    mm  "  ,                                  
    "3F Up Offset    mm  "  ,          
    "4F Up Offset    mm  "  ,                                 
    "5F Up Offset    mm  "  ,                              
    "6F Up Offset    mm  "  ,                                  
    "7F Up Offset    mm  "  ,                             
    "8F Up Offset    mm  "  ,                                     
    "9F Up Offset    mm  "  ,                                 
    "10F Up Offset   mm  "  ,                                     
    "11F Up Offset   mm  "  ,                                  
    "12F Up Offset   mm  "  ,                                   
    "13F Up Offset   mm  "  ,                                 
    "14F Up Offset   mm  "  ,                                   
    "15F Up Offset   mm  "  ,                                 
    "16F Up Offset   mm  "  ,                                 
    "17F Up Offset   mm  "  ,                              
    "18F Up Offset   mm  "  ,                                    
    "19F Up Offset   mm  "  ,                                
    "20F Up Offset   mm  "  ,
    "21F Up Offset   mm  "  ,                                 
    "22F Up Offset   mm  "  ,                                   
    "23F Up Offset   mm  "  ,                                  
    "24F Up Offset   mm  "  ,                                    
    "25F Up Offset   mm  "  ,                               
    "26F Up Offset   mm  "  ,                               
    "27F Up Offset   mm  "  ,                             
    "28F Up Offset   mm  "  ,                                   
    "29F Up Offset   mm  "  ,                                    
    "30F Up Offset   mm  "  ,                                   
    "31F Up Offset   mm  "  ,                                   
    "32F Up Offset   mm  "  ,                                  
    "33F Up Offset   mm  "  ,                                   
    "34F Up Offset   mm  "  ,                                
    "35F Up Offset   mm  "  ,                                 
    "36F Up Offset   mm  "  ,                                 
    "37F Up Offset   mm  "  ,                                
    "38F Up Offset   mm  "  ,                                     
    "39F Up Offset   mm  "  ,                                     
    "40F Up Offset   mm  "  , 
    "41F Up Offset   mm  "  ,                                
    "42F Up Offset   mm  "  ,                                   
    "43F Up Offset   mm  "  ,                                 
    "44F Up Offset   mm  "  ,                                    
    "45F Up Offset   mm  "  ,                                 
    "46F Up Offset   mm  "  ,                                   
    "47F Up Offset   mm  "  ,                       
    "48F Up Offset   mm  "  ,                                  
    "49F Up Offset   mm  "  ,                                 
    "50F Up Offset   mm  "  ,
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_sc_Adjst2[DLC_TABLE] = { 
 /* "12345678901234561234"  */  
    "1F Down Offset  mm  "  ,      
    "2F Down Offset  mm  "  ,                                  
    "3F Down Offset  mm  "  ,          
    "4F Down Offset  mm  "  ,                                 
    "5F Down Offset  mm  "  ,                              
    "6F Down Offset  mm  "  ,                                  
    "7F Down Offset  mm  "  ,                             
    "8F Down Offset  mm  "  ,                                     
    "9F Down Offset  mm  "  ,                                 
    "10F Down Offset mm  "  ,                                     
    "11F Down Offset mm  "  ,                                  
    "12F Down Offset mm  "  ,                                   
    "13F Down Offset mm  "  ,                                 
    "14F Down Offset mm  "  ,                                   
    "15F Down Offset mm  "  ,                                 
    "16F Down Offset mm  "  ,                                 
    "17F Down Offset mm  "  ,                              
    "18F Down Offset mm  "  ,                                    
    "19F Down Offset mm  "  ,                                
    "20F Down Offset mm  "  ,
    "21F Down Offset mm  "  ,                                 
    "22F Down Offset mm  "  ,                                   
    "23F Down Offset mm  "  ,                                  
    "24F Down Offset mm  "  ,                                    
    "25F Down Offset mm  "  ,                               
    "26F Down Offset mm  "  ,                               
    "27F Down Offset mm  "  ,                             
    "28F Down Offset mm  "  ,                                   
    "29F Down Offset mm  "  ,                                    
    "30F Down Offset mm  "  ,                                   
    "31F Down Offset mm  "  ,                                   
    "32F Down Offset mm  "  ,                                  
    "33F Down Offset mm  "  ,                                   
    "34F Down Offset mm  "  ,                                
    "35F Down Offset mm  "  ,                                 
    "36F Down Offset mm  "  ,                                 
    "37F Down Offset mm  "  ,                                
    "38F Down Offset mm  "  ,                                     
    "39F Down Offset mm  "  ,                                     
    "40F Down Offset mm  "  , 
    "41F Down Offset mm  "  ,                                
    "42F Down Offset mm  "  ,                                   
    "43F Down Offset mm  "  ,                                 
    "44F Down Offset mm  "  ,                                    
    "45F Down Offset mm  "  ,                                 
    "46F Down Offset mm  "  ,                                   
    "47F Down Offset mm  "  ,                       
    "48F Down Offset mm  "  ,
    "49F Down Offset mm  "  ,
    "50F Down Offset mm  "
};

//adjust floor position,Henry,2019/01/07
const string20 prinfo_DLC_sc_Adjst3[DLC_TABLE] = { 
 /*---- GROUP 04---------------------------------------*/
 /*  "12345678901234561234"  */   

    "51F Up Offset   mm  "  ,      
    "52F Up Offset   mm  "  ,                                  
    "53F Up Offset   mm  "  ,          
    "54F Up Offset   mm  "  ,                                 
    "55F Up Offset   mm  "  ,                              
    "56F Up Offset   mm  "  ,                                  
    "57F Up Offset   mm  "  ,                             
    "58F Up Offset   mm  "  ,                                     
    "59F Up Offset   mm  "  ,                                 
    "60F Up Offset   mm  "  ,                                     
    "61F Up Offset   mm  "  ,                                  
    "62F Up Offset   mm  "  ,                                   
    "63F Up Offset   mm  "  ,                                 
    "64F Up Offset   mm  "  ,                                   
    "65F Up Offset   mm  "  ,                                 
    "66F Up Offset   mm  "  ,                                 
    "67F Up Offset   mm  "  ,                              
    "68F Up Offset   mm  "  ,                                    
    "69F Up Offset   mm  "  ,                                
    "70F Up Offset   mm  "  ,
    "71F Up Offset   mm  "  ,                                 
    "72F Up Offset   mm  "  ,                                   
    "73F Up Offset   mm  "  ,                                  
    "74F Up Offset   mm  "  ,                                    
    "75F Up Offset   mm  "  ,                               
    "51F Dn Offset   mm  "  ,                               
    "52F Dn Offset   mm  "  ,                             
    "53F Dn Offset   mm  "  ,                                   
    "54F Dn Offset   mm  "  ,                                    
    "55F Dn Offset   mm  "  ,                                   
    "56F Dn Offset   mm  "  ,                                   
    "57F Dn Offset   mm  "  ,                                  
    "58F Dn Offset   mm  "  ,                                   
    "59F Dn Offset   mm  "  ,                                
    "60F Dn Offset   mm  "  ,                                 
    "61F Dn Offset   mm  "  ,                                 
    "62F Dn Offset   mm  "  ,                                
    "63F Dn Offset   mm  "  ,                                     
    "64F Dn Offset   mm  "  ,                                     
    "65F Dn Offset   mm  "  , 
    "66F Dn Offset   mm  "  ,                                
    "67F Dn Offset   mm  "  ,                                   
    "68F Dn Offset   mm  "  ,                                 
    "69F Dn Offset   mm  "  ,                                    
    "70F Dn Offset   mm  "  ,                                 
    "71F Dn Offset   mm  "  ,                                   
    "72F Dn Offset   mm  "  ,                       
    "73F Dn Offset   mm  "  ,                                  
    "74F Dn Offset   mm  "  ,                                 
    "75F Dn Offset   mm  "  ,
};
#endif

#else
extern const string20 Modelinfo[MAXMODELNO];
extern const string20 ModelinfoSingle[MAXMODELNO];   //[Single phase input, Bernie, 01/19/2012]
extern const string20 usrdefinfo[UPAGEMAX];
extern const string20 usrdefinfo_0005[UPAGEMAX];
extern const string20 usrdefinfo_metric[UPAGEMAX];
extern const string20 usrdefinfo_ft[UPAGEMAX];
extern const string20 usrdefinfo_mpers2[UPAGEMAX];
extern const string20 sfrinfo[MFDPAGEMAX+1];
extern const string20 sfrinfo_vel_sel[3];
extern const string20 c20info[C20MAX];
extern const string20 c21info[C21MAX];
extern const string20 c22info[C22MAX];
extern const string20 errinfo[ERRMAX+1];
extern const string20 warninfo[WARNMAX];
extern const string20 gpname[12];

#if Language_EN
extern const string20 prinfo[EPMAX];
extern const string20 gpname[12];
extern const string20 warninfo[WARNMAX];
extern const string20 errinfo[ERRMAX+1];
extern const string20 prinfo_ACC_fts2[11];
extern const string20 prinfo_SCurve_ms3[5];
extern const string20 prinfo_SCurve_fts3[5];
extern const string20 prinfo_DLC[DLC_TABLE];
extern const string20 prinfo_DLC2[DLC_TABLE];   // JINGDO
extern const string20 prinfo_DLC3[DLC_TABLE];   // JINGDO
extern const string20 prinfo_DLC_Adjst[DLC_TABLE];
extern const string20 prinfo_DLC_Adjst2[DLC_TABLE];
extern const string20 prinfo_DLC_Adjst3[DLC_TABLE];
extern const string20 BTTxinfo[11];
#endif

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
extern const string20 SIBO_OPTTABLE[7];
#endif
extern const string20 prinfo[EPMAX];
extern const string20 Otherinfo[1];

#if Language_TC
// [ Add Traditional and Simple Chinese Text, Bernie, 07/22/2011
extern const string20 prinfo_tc[EPMAX];
extern const string20 gpname_tc[GRALL+1];
extern const string20 warninfo_tc[(WARNMAX+1)];
extern const string20 errinfo_tc[(ERRMAX+1)];
extern const string20 prinfo_tc_ACC_fts2[11];
extern const string20 prinfo_tc_SCurve_ms3[5];
extern const string20 prinfo_tc_SCurve_fts3[5];
extern const string20 prinfo_tc_DLC[DLC_TABLE];
extern const string20 prinfo_tc_DLC2[DLC_TABLE];// JINGDO
extern const string20 prinfo_tc_DLC3[DLC_TABLE];// JINGDO
extern const string20 prinfo_DLC_tc_Adjst[DLC_TABLE];
extern const string20 prinfo_DLC_tc_Adjst2[DLC_TABLE];
extern const string20 prinfo_DLC_tc_Adjst3[DLC_TABLE];
#endif

#if Language_SC
extern const string20 prinfo_sc[EPMAX];
extern const string20 gpname_sc[GRALL+1];
extern const string20 warninfo_sc[(WARNMAX+1)];
extern const string20 errinfo_sc[(ERRMAX+1)];
extern const string20 prinfo_sc_ACC_ms2[11];
extern const string20 prinfo_sc_ACC_fts2[11];
extern const string20 prinfo_sc_SCurve_ms3[5];
extern const string20 prinfo_sc_SCurve_fts3[5];
extern const string20 prinfo_sc_DLC[DLC_TABLE];
extern const string20 prinfo_sc_DLC2[DLC_TABLE];// JINGDO
extern const string20 prinfo_sc_DLC3[DLC_TABLE];// JINGDO
extern const string20 prinfo_DLC_sc_Adjst[DLC_TABLE];
extern const string20 prinfo_DLC_sc_Adjst2[DLC_TABLE];
extern const string20 prinfo_DLC_sc_Adjst3[DLC_TABLE];
#endif

#if Language_TR
// [ Add Turkce Text, Jason, 01/20/2020
extern const string20 prinfo_tur[EPMAX];
extern const string20 gpname_tur[GRALL+1];
extern const string20 warninfo_tur[(WARNMAX+1)];
extern const string20 errinfo_tur[(ERRMAX+1)];
#endif

#if Language_RUS
extern const string20 prinfo_rus[EPMAX];
extern const string20 gpname_rus[GRALL+1];
extern const string20 warninfo_rus[(WARNMAX+1)];
extern const string20 errinfo_rus[(ERRMAX+1)];
extern const string20 prinfo_rus_ACC_ms2[11];
extern const string20 prinfo_rus_ACC_fts2[11];
extern const string20 prinfo_rus_SCurve_ms3[5];
extern const string20 prinfo_rus_SCurve_fts3[5];
#endif

#endif
