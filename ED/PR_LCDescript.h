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
    "硉い筁筿瑈    ocA ",    //1
    "搭硉い筁筿瑈    ocd ",    //2
    "﹚硉笲锣い筁筿瑈ocn ",    //3
    "钡筁筿瑈      GFF ",    //4
    "IGBT爵祏隔  occ ",    //5
    "氨ゎい筁筿瑈    ocS ",    //6
    "硉い筁筿溃    ovA ",    //7    
    "搭硉い筁筿溃    ovd ",    //8
    "﹚硉笲锣い筁筿溃ovn ",    //9
    "氨ゎい筁筿溃    ovS ",    //10
    "硉い筿溃    LvA ",    //11
    "搭硉い筿溃    Lvd ",    //12
    "﹚硉笲锣い筿溃Lvn ",    //13
    "氨ゎい筿溃    LvS ",    //14
    "筿ろ玂臔    PHL ",    //15
    "IGBT放筁蔼    oH1 ",    //16
    "筿方筿甧放筁蔼oH2 ",    //17
    "IGBT放盎代钵盽tH1o",    //18
    "筿甧放盎代钵盽tH2o",    //19
    "钵盽        FAn ",    //20
    "臱笆竟筁璽更    oL  ",    //21
    "筿诀筁璽更      EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "筿诀筁荐        oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "筁锣痻1         ot1 ",    //26
    "筁锣痻2         ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "癘拘砰糶钵盽  cF1 ",    //30
    "癘拘砰弄钵盽  cF2 ",    //31
    "Isum筿瑈盎代钵盽cd0 ",    //32
    "U筿瑈盎代钵盽 cd1 ",    //33
    "V筿瑈盎代钵盽 cd2 ",    //34
    "W筿瑈盎代钵盽 cd3 ",    //35
    "CC祑砰絬隔钵盽  Hd0 ",    //36
    "OC祑砰絬隔钵盽  Hd1 ",    //37
    "OV祑砰絬隔钵盽  Hd2 ",    //38
    "GFF祑砰絬隔钵盽 Hd3 ",    //39
    "筿诀笆秖代岿粇AUE ",    //40
    "PID 甭岿粇    AFE ",    //41
    "PG甭钵盽      PGF1",    //42
    "PG甭耞絬      PGF2",    //43
    "PG甭ア硉      PGF3",    //44
    "PG锣畉钵盽      PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "场岿粇癟腹块EF  ",    //49
    "场狠候氨ゎEF1 ",    //50
    "Base Block      bb  ",    //51
    "盞絏块Ω岿粇Pcod",    //52
    "SW Code Error   ccod",    //53
    "ぃ猭硄癟㏑  cE01",    //54
    "ぃ猭硄癟  cE02",    //55
    "硄癟戈岿粇cE03",    //56
    "硄癟糶斑弄竚cE04",    //57
    "MODBUS肚块禬  cE10",    //58
    "KEYPAD肚块禬  cP10",    //59
    "盎代焚ó垂砰钵盽BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "癹隔钵盽    SRY ",    //63  add by dino, 06/06/2007
    "诀瘪焚ó甭钵盽MBF ",    //64  add by dino, 05/14/2008
    "PG祑砰盎代钵盽  PGF5",    //65
    "筿合钡牟竟钵盽  MCF ",    //66
    "块ろ        MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus 耞絬    CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "筿辫筁硉    PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "锣痻框ア1   STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd絬隔钵盽   PGcd",    //73  [Safty function, Bernie, 2013/10/29]
    "PG 荡癸癟腹钵盽 PGHL",    //74
    "PG Z癟腹框ア  PGAF",    //75
    "锣痻块氨ゎSTO ",    //76
    "锣痻框ア2   STL2",    //77
    "锣痻框ア3   STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "狝叭筄        SERV",    //81
    "块ろ U    OPHL",    //82
    "块ろ V    OPHL",    //83
    "块ろ W    OPHL",    //84
    "DLC北家Α岿粇 DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "キ糷秨闽祏隔    LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "キ糷秨闽秨隔    LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "筿瑈吏北钵盽  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "锣痻癹隔猤翲STL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "锣痻块氨ゎSTOr",    //90  //#12225,STO error at running 
    "锣痻癹隔猤翲STOS",    //91  //#12225,STO Short error
    "Sensor817 岿粇  SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 岿粇  SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTT ア毖         btt",    //94	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT 岿粇        bttE",    //95  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE岿粇玛﹚     AEL ",		//97[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_SC
const string20 errinfo_sc[(ERRMAX+1)]={
//   12345678901234561234   //
    "No error            ",    //0
    "加速中过电流    ocA ",    //1
    "减速中过电流    ocd ",    //2
    "定速运转中过电流ocn ",    //3
    "接地过电流      GFF ",    //4
    "IGBT上下?哦搪?  occ ",    //5
    "停止中过电流    ocS ",    //6
    "加速中过电压    ovA ",    //7    
    "减速中过电压    ovd ",    //8
    "定速运转中过电压ovn ",    //9
    "停止中过电压    ovS ",    //10
    "加速中低电压    LvA ",    //11
    "减速中低电压    Lvd ",    //12
    "定速运转中低电压Lvn ",    //13
    "停止中低电压    LvS ",    //14
    "?氲缜废啾；?    PHL ",    //15
    "IGBT温度过高    oH1 ",    //16
    "电源电?菸露?过高oH2 ",    //17
    "IGBT温度侦测异常tH1o",    //18
    "电?菸露?侦测异常tH2o",    //19
    "风扇异常        FAn ",    //20
    "??动?鞴?载      oL  ",    //21
    "电机过负载      EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "电机过??        oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "过转矩1         ot1 ",    //26
    "过转矩2         ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "记忆体写?胍斐?  cF1 ",    //30
    "记忆体读出异常  cF2 ",    //31
    "Isum电流侦测异常cd0 ",    //32
    "U相电流侦测异常 cd1 ",    //33
    "V相电流侦测异常 cd2 ",    //34
    "W相电流侦测异常 cd3 ",    //35
    "CC硬体线路异常  Hd0 ",    //36
    "OC硬体线路异常  Hd1 ",    //37
    "OV硬体线路异常  Hd2 ",    //38
    "GFF硬体线路异常 Hd3 ",    //39
    "电机自动量测错误AUE ",    //40
    "PID 回授错误    AFE ",    //41
    "PG回授异常      PGF1",    //42
    "PG回授断线      PGF2",    //43
    "PG回授失速      PGF3",    //44
    "PG转差异常      PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "外部错误讯号输?隕F  ",    //49
    "外部端子紧急停止EF1 ",    //50
    "Base Block      bb  ",    //51
    "密码输?肴?次错误Pcod",    //52
    "SW Code Error   ccod",    //53
    "不合法通讯命令  cE01",    //54
    "不合法通讯位址  cE02",    //55
    "通讯资料长度错误cE03",    //56
    "通讯写?胛ǘ廖恢胏E04",    //57
    "MODBUS传输超时  cE10",    //58
    "KEYPAD传输超时  cP10",    //59
    "侦测煞车晶体异常BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "安?芈芬斐?    SRY ",    //63  add by dino, 06/06/2007
    "机械煞车回授异常MBF ",    //64  add by dino, 05/14/2008
    "PG硬体侦测异常  PGF5",    //65
    "电磁接触?饕斐?  MCF ",    //66
    "输出?废?        MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus 断线    CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "电梯过加速度    PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "安?匾攀?1   STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd线路异常   PGcd",    //73
    "PG 绝对讯号异常 PGHL",    //74
    "PG Z相讯号遗失  PGAF",    //75
    "安?厥涑鐾?止STO ",    //76
    "安?匾攀?2   STL2",    //77
    "安?匾攀?3   STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "服务逾时        SERV",    //81
    "输出?废? U相    OPHL",    //82
    "输出?废? V相    OPHL",    //83
    "输出?废? W相    OPHL",    //84
    "DLC控制模式错误 DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "?讲憧囟搪?    LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "?讲憧乜?    LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "电流环控制异常  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "安?鼗芈氛答TL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "安?厥涑鐾?止STOr",    //90  //#12225,STO error at running 
    "安?鼗芈氛答TOS",    //91  //#12225,STO Short error
    "Sensor817 错误  SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 错误  SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTT 失败         btt",    //94	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT 错误        bttE",    //95  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE错误锁定     AEL ",    //97//[AFE Error Handle/Lyabryan/2022/03/24]

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
    "秸掼匮挹          ",      //0
    "苦找.廪谛.汜谵ocA ",      //1
    "苦找.廪谛.仔苷ocd ",      //2
    "苦找.廪谛.萼    ocn ",    //3
    "沸茈菪 渍苒 GFF ",        //4
    "恨噢廒拚 仔茈 occ ",      //5
    "苦找.廪谛.掎庑ocS ",      //6
    "苦找.菪哙.汜谵ovA ",      //7    
    "苦找.菪哙.仔苷ovd ",      //8
    "苦找.菪哙.萼    ovn ",    //9
    "苦找.菪哙.掎庑ovS ",      //10
    "截菪哙.汜谵 LvA ",        //11
    "截菪哙.仔苷 Lvd ",        //12
    "截菪哙.萼     Lvn ",      //13
    "截菪哙.掎庑 LvS ",        //14
    "哭庹囡 义. 湫纂 PHL ",    //15
    "空嗾余找 IGBT   oH1 ",    //16
    "空嗾余找 谵菰.  oH2 ",    //17
    "捐匮.庹嘬拊锈1tH1o",      //18
    "捐匮.庹嘬拊锈2tH2o",      //19
    "臂挹.艺葩.      FAn ",    //20
    "空嗾余阕 咿 廪阢oL  ",    //21
    "抡咣.仔樨庑 砸1 EoL1",    //22
    "抡咣.仔樨庑 砸2 EoL2",    //23
    "空嗾余找 砸赜锈.oH3 ",    //24
    "捐匮.哙赵掊   FuSE",      //25
    "苦找腓. 苻苷葩ot1 ",      //26
    "苦找腓. 苻苷葩ot2 ",      //27
    "秸赞徕锈.苻苷葩 uc1 ",    //28
    "秸赞徕锈.苻苷葩 uc2 ",    //29
    "捐.EEPROM仔   cF1 ",      //30
    "捐.EEPROM玮蛰   cF2 ",    //31
    "捐.孕徙廪谛 cd0 ",        //32
    "捐匮.绰 U-湫纂  cd1 ",    //33
    "捐匮.绰 V-湫纂  cd2 ",    //34
    "捐匮.绰 W-湫纂  cd3 ",    //35
    "斑咝掼匮谛 醕 Hd0 ",      //36
    "斑咝掼匮谛 oc Hd1 ",      //37
    "斑咝掼匮谛 ov Hd2 ",      //38
    "斑咝掼匮谛 occHd3 ",      //39
    "捐匮谛 幸廪庹徕蠥UE ",    //40
    "秸扪嵋镒乜复AFE ",        //41
    "捐匮谛  PG  PGF1",        //42
    "哭庹囡  PG  PGF2",        //43
    "拎胍  PG    PGF3",        //44
    "捐匮.掴谯掭.PG  PGF4",    //45
    "捐匮. 剀 义.PGPGr1",      //46
    "哭庹囡 剀义.PGPGr2",      //47
    "哭庹囡 嶝虞. ACIACE ",    //48
    "草砧.嶝虞.幸朽刎EF  ",    //49
    "草砧耙朽刭菱捱EF1 ",      //50
    "臂挹.嶝苻糟埏 bb  ",      //51
    "秸艺噍胭 咝噢垤 Pcod",    //52
    "捐匮谛 谵孕 烤  ccod",    //53
    "秸艺谵谵苄菰cE01",        //54
    "秸艺性孕葺脲cE02",        //55
    "秸艺咱.孕葺脲 cE03",      //56
    "捐匮谛 仔哓嶝   cE04",    //57
    "滦佘秀嵋镒  cE10",        //58
    "滦佘秀咩垤庑  cP10",      //59
    "耙朽.廪嘬.嗾棕徕BF  ",    //60
    "捐匮.亿Y-忄浙觵dc ",      //61   
    "哭庹哓庑,   dEb ",        //62   
    "沸樨廨拚 嗾壅   SRY ",    //63  add by dino, 06/06/2007
    "捐匮.苷廪嘬   MBF ",      //64  add by dino, 05/14/2008
    "斑掼匮PG谛噔PGF5",        //65
    "捐匮. 恨葩汹廪嘈MCF ",    //66
    "狙嚯湫纂.砸赜.MPHL",      //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN 柝菪 掴谯.  CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "嗾汜仫      PGOA",        //71  [Safty function, Bernie, 2013/10/29]
    "凶嚯嬲哓      STL1",      //72  [Safty function, Bernie, 2013/10/29]
    "柝芽拊谯洼    PGcd",      //73  [Safty function, Bernie, 2013/10/29]
    "柝寻厌.霖虞.洼PGHL",      //74
    "掴锗锪赜軿      PGAF",    //75
    "兆捱锯谯嫁苷葩  STO ",    //76
    "燕胍 嶝 STO2  STL2",      //77
    "燕胍 嶝 STO3  STL3",      //78
    "                    ",    //79
    "                    ",    //80
    "绎重庹犰 疗   SERV",      //81
    "燕胍 U 湫纂     OPHL",    //82
    "燕胍 V 湫纂     OPHL",    //83
    "燕胍 W 湫纂     OPHL",    //84 
    "DLC Ctrl MethodDLCC",     //85 //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "Lv Sensor Short LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "Lv Sensor Open  LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "Cur. Ctrl. Err  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "安?鼗芈氛答TL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "安?厥涑鐾?止STOr",    //90  //#12225,STO error at running 
    "安?鼗芈氛答TOS",    //91  //#12225,STO Short error  
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
    "ぃ猭硄癟㏑  cE01", //warncode = 1
    "ぃ猭硄癟  cE02", //warncode = 2
    "硄癟戈岿粇cE03", //warncode = 3
    "硄癟糶斑弄cE04", //warncode = 4
    "Modbus肚块禬  cE10", //warncode = 5
    "Keypad肚块禬  cP10", //warncode = 6
    "把计狡籹岿粇    SE1 ", //warncode = 7
    "把计狡籹ア毖    SE2 ", //warncode = 8
    "IGBT筁荐        oH1 ", //warncode = 9
    "筿甧筁荐        oH2 ", //warncode = 10
    "PID  甭钵盽   Pid ", //warncode = 11
    "摸ゑ癟腹钵盽    AnL ", //warncode = 12
    "筿瑈筁        uC  ", //warncode = 13
    "把计厩策ア毖  AuE ", //warncode = 14
    "PG甭钵盽      PGF1", //warncode = 15
    "PG甭耞絬      PGF2", //warncode = 16
    "PG甭ア硉      PGF3", //warncode = 17
    "PG锣畉钵盽      PGF4", //warncode = 18
    "块ろ        PHL ", //warncode = 19
    "筁锣痻 1        ot1 ", //warncode = 20
    "筁锣痻 2        ot2 ", //warncode = 21
    "筿诀筁荐        oH3 ", //warncode = 22
    "C.C Warning     c.c ", //warncode = 23
    "菲畉钵盽        oSL ", //warncode = 24
    "把计厩策い    tUn ", //warncdoe = 25
    "钵盽        FAn ", //warncode = 26
    "Can Bus 耞絬    dCAn", //warncode = 27   //[CAN Control, Sampo, 09/15/2010]
    "锣痻框ア牡STOA", //warncode = 28   //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "UCMP 磅︽牡   UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "诀贺ぃ狡籹岿粇SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "狝叭筄        SERV", //warncode = 31
    "DLCよ㏑岿粇  dir", //warncode = 32  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
    "1眏搭筁硉   UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "2眏搭筁硉   UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "3眏搭筁硉   UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "4眏搭筁硉   UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "1眏搭筁硉   DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "2眏搭筁硉   DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "3眏搭筁硉   DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "4眏搭筁硉   DDS4", //warncode = 40  // DD4_Vlim_WARN  
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "キ糷秨闽獺腹钵盽LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO钵盽     STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO猤翲         STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "Sensor817 牡  SnW7",	//warncode = 46
	"Sensor818 牡  SnW8",	//warncode = 47
	"BTTx 代刚い     bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx タ盽       bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Θ\       bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
};
#endif

#if Language_SC
const string20 warninfo_sc[(WARNMAX+1)]={
//   12345678901234561234   //
    "No error            ",
    "不合法通讯命令  cE01", //warncode = 1                                                                       
    "不合法通讯位址  cE02", //warncode = 2                                                                       
    "通讯资料长度错误cE03", //warncode = 3                                                                       
    "通讯写?胛ǘ廖恢穋E04", //warncode = 4                                                                       
    "Modbus传输超时  cE10", //warncode = 5                                                                       
    "Keypad传输超时  cP10", //warncode = 6                                                                       
    "参数复制错误    SE1 ", //warncode = 7                                                                       
    "参数复制失败    SE2 ", //warncode = 8                                                                       
    "IGBT过??        oH1 ", //warncode = 9                                                                       
    "电?莨???        oH2 ", //warncode = 10                                                                      
    "PID  回授异常   Pid ", //warncode = 11                                                                      
    "类比讯号异常    AnL ", //warncode = 12                                                                      
    "电流过低        uC  ", //warncode = 13                                                                      
    "参数自学习失败  AuE ", //warncode = 14                                                                      
    "PG回授异常      PGF1", //warncode = 15                                                                      
    "PG回授断线      PGF2", //warncode = 16                                                                      
    "PG回授失速      PGF3", //warncode = 17                                                                      
    "PG转差异常      PGF4", //warncode = 18                                                                      
    "输?肭废?        PHL ", //warncode = 19                                                                      
    "过转矩 1        ot1 ", //warncode = 20                                                                      
    "过转矩 2        ot2 ", //warncode = 21                                                                      
    "电机过??        oH3 ", //warncode = 22                                                                      
    "C.C Warning     c.c ", //warncode = 23                                                                      
    "滑差异常        oSL ", //warncode = 24                                                                      
    "参数自学习中    tUn ", //warncdoe = 25                                                                      
    "风扇异常        FAn ", //warncode = 26                                                                      
    "Can Bus 断线    dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]                                //Sampo, 09/15/2010]
    "安?匾攀Ь鍿TOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]//warncode = 28
    "UCMP 执行警告   UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "机种不同复制错误SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "服务逾时        SERV", //warncode = 31
    "上1级?考豕?速   UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "上2级?考豕?速   UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "上3级?考豕?速   UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "上4级?考豕?速   UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "下1级?考豕?速   DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "下2级?考豕?速   DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "下3级?考豕?速   DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "下4级?考豕?速   DDS4", //warncode = 40  // DD4_Vlim_WARN  
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "?讲憧匦藕乓斐S  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO时序异常     STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO沾黏         STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14 
    "Sensor817 警告  SnW7",	//warncode = 46
	"Sensor818 警告  SnW8",	//warncode = 47
	"BTTx 测试中     bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
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
    "秸掼匮挹          ",
    "秸艺噍酗 谵苄菰衏E01", //warncode = 1
    "秸艺噍胭 性嗾 cE02",   //warncode = 2
    "秸艺噍酗 咱剌 cE03",   //warncode = 3
    "沸哓扪玮蛰cE04",       //warncode = 4
    "滦佘秀嵋镒  cE10",     //warncode = 5
    "滦佘秀咩垤庑  cP10",   //warncode = 6
    "捐匮谛 谵哓噢 SE1 ",   //warncode = 7
    "捐匮谛 谵哓噢 SE2 ",   //warncode = 8
    "空嗾余找 IGBT   oH1 ", //warncode = 9
    "空嗾余找 嘈载锈.oH2 ", //warncode = 10
    "捐匮谛  扛Pid ",       //warncode = 11
    "狙嚯休雄抻.   AnL ",   //warncode = 12
    "截宗刭 廪     uC  ",   //warncode = 13
    "捐匮谛 幸廪菪徕.AuE ", //warncode = 14
    "捐匮谛  PG  PGF1",     //warncode = 15
    "哭庹囡  PG  PGF2",     //warncode = 16
    "拎胍  PG    PGF3",     //warncode = 17
    "捐匮.嶷捋熘.    PGF4", //warncode = 18
    "哭庹囡 义拊. 湫譖HL ", //warncode = 19
    "苦找腓. 苻苷葩ot1 ",   //warncode = 20
    "苦找腓. 苻苷葩ot2 ",   //warncode = 21
    "空嗾余找 砸赜锈.oH3 ", //warncode = 22
    "苦赵氵嗾衷.麓   c.c ", //warncode = 23
    "苦找腓.嶷捋熘.  oSL ", //warncode = 24
    "耙廪菪徕噢仝  tUn ",   //warncdoe = 25
    "臂挹.艺葩. Fan  FAn ", //warncode = 26
    "CAN 柝菪. 译谯. dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]
    "苦赵氵嗾衷.STO  STOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "苦赵氵嗾衷UCMP  UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "捐匮.谵哓苻哉跾E3 ",   //warncode = 30  COPY Fail 3, Model name Error   
    "烈镏剽蔗疗  SERV",     //warncode = 31
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
    "╰参把计        00  ",     //  Group 13
    "膀セ把计        01  ",     //  Group  0
    "计狠\    02  ",    //  Group  1
    "摸ゑ狠\    03  ",    //  Group  2
    "琿硉把计      04  ",     //  Group  3
    "IM 筿诀把计     05  ",     //  Group  4
    "玂臔把计        06  ",     //  Group  5
    "疭把计        07  ",     //  Group  6
    "PM 皑笷把计     08  ",     //  Group  7
    "硄癟把计        09  ",     //  Group  8
    "硉甭把计    10  ",     //  Group  9
    "秈顶把计        11  ",     //  Group 10
    "ノめ﹚把计砞﹚12  ",     //  Group 11
    "ノめ砞﹚把计琩綷\13  ",    //  Group 12                  
    "RESERVED        14  ",     //  Group 14
    "FACTORY         15  ",     //  Group 15
};
#endif

#if Language_SC
const string20 gpname_sc[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "系统参数        00  ",     //  Group 13
    "基本参数        01  ",     //  Group  0
    "数位端子功能    02  ",     //  Group  1
    "类比端子功能    03  ",     //  Group  2
    "多段速参数      04  ",     //  Group  3
    "IM 电机参数     05  ",     //  Group  4
    "保护参数        06  ",     //  Group  5
    "特殊参数        07  ",     //  Group  6
    "PM 马达参数     08  ",     //  Group  7
    "通讯参数        09  ",     //  Group  8
    "速度回授参数    10  ",     //  Group  9
    "高级参数        11  ",     //  Group 10
    "用户自定义参数  12  ",     //  Group 11
    "用户设定参数查询13  ",     //  Group 12
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
    "堪腊坷覆敬  00  ",	       //  Group  0
    "卑堪腊嫉吕  01  ",	       //  Group  1
    "锤梁. 才/菜   02  ",	   //  Group  2
    "敖盎境.才/菜  03  ",	   //  Group  3
    "济惶赂-梁纠玖赂 04  ",	   //  Group  4
    "傲附床赋奥祷05  ",	       //  Group  5
    "堪腊钒筛滤    06  ",	   //  Group  6
    "量灯. 堪腊    07  ",	   //  Group  7
    "粮脚. 床赋奥祷08  ",	   //  Group  8
    "堪腊敛戏    09  ",	       //  Group  9
    "堪腊徒壕吹腊  10  ",	   //  Group 10
    "淳堪腊嫉吕  11  ",	       //  Group 11
    "堪腊淳谅每  12  ",	       //  Group 12
    "桨谅烤惶肪  13  ",	       //  Group 13
    "钒赖返啦咐静    14  ",	   //  Group 14
    "钒簿堪腊    15  ",	       //  Group 15
    
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
    "ACC LPF             "  ,   //  422 10-35   //Rationa 362631, Special.Kung
    "ACC SampleRate    ms"  ,   //  422 10-36   //Rationa 362631, Special.Kung

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
	"材硉丁    m/s2"	,	//	156	01-12 1st Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    m/s2"	,	//	157	01-13 1st Deceleration time      //chinese description creat by Bernie 
	"材硉丁    m/s2"	,	//	158	01-14 2nd Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    m/s2"	,	//	159	01-15 2nd Deceleration time      //chinese description creat by Bernie 
	"材硉丁    m/s2"	,	//	160	01-16 3rd Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    m/s2"	,	//	161	01-17 3rd Deceleration time      //chinese description creat by Bernie 
	"材硉丁    m/s2"	,	//	162	01-18 4th Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    m/s2"	,	//	163	01-19 4th Deceleration time      //chinese description creat by Bernie 
	"笆硉丁    m/s2"	,	//	164	01-20 JOG Acceleration time
	"笆搭硉丁    m/s2"	,	//	165	01-21 JOG Deceleration time
	"氨ó搭硉丁    m/s2"
};

const string20 prinfo_tc_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"材硉丁    f/s2"	,	//	156	01-12 1st Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    f/s2"	,	//	157	01-13 1st Deceleration time      //chinese description creat by Bernie 
	"材硉丁    f/s2"	,	//	158	01-14 2nd Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    f/s2"	,	//	159	01-15 2nd Deceleration time      //chinese description creat by Bernie 
	"材硉丁    f/s2"	,	//	160	01-16 3rd Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    f/s2"	,	//	161	01-17 3rd Deceleration time      //chinese description creat by Bernie 
	"材硉丁    f/s2"	,	//	162	01-18 4th Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    f/s2"	,	//	163	01-19 4th Deceleration time      //chinese description creat by Bernie 
	"笆硉丁    f/s2"	,	//	164	01-20 JOG Acceleration time
	"笆搭硉丁    f/s2"	,	//	165	01-21 JOG Deceleration time
	"氨ó搭硉丁    f/s2"
};


const string20 prinfo_tc_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"硉秨﹍S1丁  m/s3"	,	//	168	01-24 S curve Accel time 1
	"硉秨﹍S2丁  m/s3"	,	//	169	01-25 S curve Accel time 2
	"硉秨﹍S3丁  m/s3"	,	//	170	01-26 S curve Decel time 1
	"硉秨﹍S4丁  m/s3"	,	//	171	01-27 S curve Decel time 2
	"キ糷硉S5  m/s3"	
};

const string20 prinfo_tc_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"硉秨﹍S1丁  f/s3"	,	//	168	01-24 S curve Accel time 1
	"硉秨﹍S2丁  f/s3"	,	//	169	01-25 S curve Accel time 2
	"硉秨﹍S3丁  f/s3"	,	//	170	01-26 S curve Decel time 1
	"硉秨﹍S4丁  f/s3"	,	//	171	01-27 S curve Decel time 2
	"キ糷硉S5  f/s3"	
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
    "诀贺醚絏          "	,	//	128 00-00	Model Type of Drive 
    "跑繵竟肂﹚筿瑈  Amps"	,	//	129 00-01	Rated Current
    "把计竚砞﹚        "	,	//	130 00-02	Parameter Reset
    "秨诀陪ボ礶匡拒    "	,	//	131 00-03	Start up Display       //chinese description creat by Bernie 
    "\陪ボ匡拒      "	,	//	132 00-04	User Display            // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "﹚竡ゑㄒ砞﹚        "	,	//	133 00-05	User Coefficient        //chinese description creat by Bernie 
    "硁砰セ            "	,	//	134 00-06	Software Version
    "把计玂臔秆絏块    "	,	//	135 00-07	Password Input
    "把计玂臔秆絏砞﹚    "	,	//	136 00-08	Password Input
    "北家Α            "	,	//	137 00-09	Control Methods
    "硉虫            "	,	//	138 00-10	Velocity Unit Select
    "臱笆竟块よ      "	,	//	139 00-11   Change Output Direction, Added by sampo , 06/11/2009
    "更猧繵瞯        KHz "	,	//	140 00-12	Carry Frequency
    "笆铆溃\        "	,	//	141 00-13	AVR                     // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "硉ㄓ方        "	,	//	142 00-14	Source of Freq. Command
    "笲锣ㄓ方        "	,	//	143 00-15	Source of Oper. Command
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"程巨繵瞯    Hz  "	,	//	144	01-00   Max Output Freq.
	"筿诀肂﹚繵瞯    Hz  "	,	//	145	01-01   Motor Base Frequency 1
	"筿诀肂﹚筿溃    V   "	,	//	146	01-02   Max Output Voltage
	"材块繵瞯    Hz  "	,	//	147	01-03   Mid Output Freq.1
	"材块筿溃    V   "	,	//	148	01-04   Mid Output Voltage 1
	"材块繵瞯    Hz  "	,	//	149	01-05   Mid Output Freq.2
	"材块筿溃    V   "	,	//	150	01-06   Mid Output Voltage 2
	"材块繵瞯    Hz  "	,	//	151	01-07   Min Output Freq.
	"材块筿溃    V   "	,	//	152	01-08   Min Output Voltage
	"币笆繵瞯        Hz  "	,	//	153	01-09   Start Frequency
	"块繵瞯  Hz  "	,	//	154	01-10   Upper Bound Freq.
	"块繵瞯  Hz  "	,	//	155	01-11   Lower Bound Freq.
	"材硉丁    sec "	,	//	156	01-12   1st Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    sec "	,	//	157	01-13   1st Deceleration time      //chinese description creat by Bernie 
	"材硉丁    sec "	,	//	158	01-14   2nd Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    sec "	,	//	159	01-15   2nd Deceleration time      //chinese description creat by Bernie 
	"材硉丁    sec "	,	//	160	01-16   3rd Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    sec "	,	//	161	01-17   3rd Deceleration time      //chinese description creat by Bernie 
	"材硉丁    sec "	,	//	162	01-18   4th Acceleration time      //chinese description creat by Bernie 
	"材搭硉丁    sec "	,	//	163	01-19   4th Deceleration time      //chinese description creat by Bernie 
	"笆硉丁    sec "	,	//	164	01-20   JOG Acceleration time
	"笆搭硉丁    sec "	,	//	165	01-21   JOG Deceleration time
	"笆繵瞯        Hz  "	,	//	166	01-22   JOG Frequency
	"1-4搭硉ち传   Hz  "	,	//	167	01-23   Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"硉秨﹍S1丁  sec "	,	//	168	01-24   S curve Accel time 1
	"硉秨﹍S2丁  sec "	,	//	169	01-25   S curve Accel time 2
	"硉秨﹍S3丁  sec "	,	//	170	01-26   S curve Decel time 1
	"硉秨﹍S4丁  sec "	,	//	171	01-27   S curve Decel time 2
	"材繵瞯家Α    "	,	//	172	01-28   Select Zero Speed
	"キ糷硉ち传    Hz  "	,	//	173	01-29   Landing Frequency 
	"キ糷硉S5  sec "	,	//	174	01-30   S curve Decel time 3
	"氨ó搭硉丁    sec "	,	//	175	01-31   Stop Deceleration time
    "沧狠眏搭硉  m/s "	,	//  1xx 01-32
    "狠氨蔼硉丁sec "	,	//	1xx	01-33   IODHT IO direct hold time   
    "狠氨キ糷丁sec "	,	//	1xx	01-34   IODLT IO direct landing freq
    "狠氨侥秖    "	,	//	1xx	01-35   IODLT IO direct landing time
    "狠氨搭硉禯瞒cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "氨把σ搭硉禯瞒m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "狠钡氨綼璓    "	,	//	1xx	01-38   IODLT IO direct DistancE
    "ETS繵瞯ゑ耕非 Hz  "  ,   //  1xx 01-37   IODLT IO direct DistancE
    "候搭硉搭硉丁sec "	,	//	1xx	01-37   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Emergency DEC   sec "  ,   //  105 15-105  RESERVE
    "Emergency S3    sec "  ,   //  105 15-105  RESERVE
    "Emergency S4    sec "  ,   //  105 15-105  RESERVE
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "2/3 絬Α笲锣北    "	,	//	176	02-00   2/3 wire control                
    "MI1\匡拒         "	,	//	177	02-01   Multi-Function Input 1          
    "MI2\匡拒         "	,	//	178	02-02   Multi-Function Input 2       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]       
    "MI3\匡拒         "	,	//	179	02-03   Multi-Function Input 3       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI4\匡拒         "	,	//	180	02-04   Multi-Function Input 4       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI5\匡拒         "	,	//	181	02-05   Multi-Function Input 5       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI6\匡拒         "	,	//	182	02-06   Multi-Function Input 6       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI7\匡拒         "	,	//	183	02-07   Multi-Function Input 7       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI8\匡拒         "	,	//	184	02-08   Multi-Function Input 8       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "计块臫莱丁sec "	,	//	185	02-09   Digital in response time		
    "计块よ        "	,	//	186	02-10   Multi-Function Input Inverse	
    "RA \匡拒         "	,	//	187	02-11   Multi-Function Relay 1	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MRA\匡拒         "	,	//	188	02-12   Multi-Function Relay 2	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "R1A\匡拒         "	,	//	189	02-13   Multi-Function Output 1	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19] 	    
    "R2A\匡拒         "	,	//	190	02-14   Multi-Function Output 2	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO1\匡拒         "	,	//	191	02-15   Multi-Function Output 3	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO2\匡拒         "	,	//	192	02-16   Multi-Function Output 4	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO3\匡拒         "	,	//	193	02-17   Multi-Function Output 5	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO4\匡拒         "	,	//	194	02-18   Multi-Function Output 6	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO5\匡拒         "	,	//	195	02-19   Multi-Function Output 7	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO6\匡拒         "	,	//	196	02-20   Multi-Function Output 8	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO7\匡拒         "	,	//	197	02-21   Multi-Function Output 9	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO8 \匡拒        "	,	//	198	02-22   Multi-Function Output 10	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "计块よ        "	,	//	199	02-23   Multi-Function Output inverse	
    "币笆獺腹家Α匡拒    "  ,   //  200 02-24   Sequence start mode
    "ヴ種繵瞯笷1   Hz  "	,	//	201	02-25   Desired Frequency 1		        
    "ヴ種繵瞯笷1糴 Hz  "	,	//	202	02-26   Band of Desired Frequency 1		
    "ヴ種繵瞯笷2   Hz  "	,	//	203	02-27   Desired Frequency 2		        
    "ヴ種繵瞯笷2糴 Hz  "	,	//	204	02-28   Band of Desired Frequency 2		
    "诀瘪焚ó筯┑sec "	,	//	205	02-29   Brake Delay Timer at run
    "诀瘪焚ó╆筯┑sec "	,	//	206	02-30   Brake Delay Timer at stop
    "筿合恢旧硄┑  sec "	,	//	207	02-31   Mech Contact Delay Timer run
    "筿合恢耞秨┑  sec "	,	//	208	02-32   Mech Contact Delay Timer stop				            
    "筿瑈非砞﹚    %   "	,	//	209	02-33   Isum Current Output Detect	    
    "硉跋琿砞﹚    Hz  "	,	//	210	02-34   Speed Area
    "诀瘪焚ó浪丁sec "	,	//	211	02-35   Mechanical Brake Checking Time
    "筿合恢浪丁  sec "	,	//	212 02-36   Magnetic Contactor Checking Time
    "锣痻絋粄笆匡拒    "  ,   //  213 02-37   Mechanical Brake Checking Current Enable
    "琍旧硄┑丁  sec "  ,   //  207 02-38   Mech Contact Delay Timer run            //[Star contactor function, Bernie, 2017/03/22] 
    "琍耞秨┑丁  sec "  ,   //  208 02-39   Mech Contact Delay Timer stop           //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD钵盽匡拒       "  ,   //  2xx 02-40   LU/LD error  Selection	                //#15977, LULD detect, James, 2021/04/01
	"LU/LD秨隔盎代   sec "  ,   //  2xx 02-41   LD/LD Open Detect Time                  //#15977, LULD detect, James, 2021/04/01
	"LU/LD祏隔盎代   sec "  ,   //  2xx 02-42   LD/LD Short Detect Time                 //#15977, LULD detect, James, 2021/04/01
    "笲锣硉笷糴Hz  "	,	//  202 02-43   Band of Speed Agree Function #18572			
    "STO祏隔盎代丁 sec "  ,   //  2xx 02-44   STO shor detect time                    //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "硉        m/s "  ,   //  2xx 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06] 
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AUI1\匡拒        "	,	//	214	03-00   AUI1 selection                    //[Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "玂痙                "	,	//	215	03-01   ACI  selection                    //[ACI function remove, Bernie, 01/20/2012]
    "AUI2\匡拒        "	,	//	216	03-02   AUI2 selection                    //[Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1块熬溃    %   "	,	//	217	03-03   AUI1 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "玂痙                "	,	//	218	03-04   ACI  input Bias                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2块熬溃    %   "	,	//	219	03-05   AUI2 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1タ璽熬溃家Α    "	,	//	220 03-06   AUI1 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "玂痙                "	,	//	221 03-07   ACI  input Polarity               //[ACI function remove, Bernie, 01/20/2012]
    "AUI2タ璽熬溃家Α    "	,	//	222 03-08   AUI2 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1块糤痲    %   "	,	//	223 03-09   AUI1 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "玂痙                "	,	//	224 03-10   ACI  input Gain                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2块糤痲    %   "	,	//	225 03-11   AUI2 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1耾猧丁    sec "	,	//	226 03-12   Low pass filter of AUI1 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "玂痙                "	,	//	227 03-13   Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2耾猧丁    sec "	,	//	228 03-14   Low pass filter of AUI2 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "颤干纕厩策      "	,	//	229 03-15   Loss of ACI                       //[ACI function remove, Bernie, 01/20/2012]
    "玂痙                "  ,   //  230 03-16   RESERVED 
    "AO1 块匡拒        "	,	//	231 03-17   Analong Output 1
    "AO1 块糤痲    %   "	,	//	232 03-18   Analong Output 1 Gain
    "AO1 块は璓    "	,	//	233 03-19   AO1 in minus value
    "AO2 块匡拒        "	,	//	234 03-20   Analong Output 2
    "AO2 块糤痲    %   "	,	//	235 03-21   Analong Output 2 Gain
    "AO2 块は璓    "	,	//	236 03-22   AO2 in minus value
    "AUI1摸ゑ块Α    "	,	//	237 03-23   AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2摸ゑ块Α    "	,	//	238 03-24   AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1块砞﹚        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2块砞﹚        "	,	//	238  03-26    AUI2 Communciate
	

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "材箂琿硉        Hz  "	,   //  239 04-00   Multi-Speed 0
    "材琿硉        Hz  "	,   //  240 04-01   Multi-Speed 1
    "材琿硉        Hz  "	,   //  241 04-02   Multi-Speed 2
    "材琿硉        Hz  "	,   //  242 04-03   Multi-Speed 3
    "材琿硉        Hz  "	,   //  243 04-04   Multi-Speed 4
    "材き琿硉        Hz  "	,   //  244 04-05   Multi-Speed 5
    "材せ琿硉        Hz  "	,   //  245 04-06   Multi-Speed 6
    "材琿硉        Hz  "	,   //  246 04-07   Multi-Speed 7
    "材琿硉        Hz  "	,   //  247 04-08   Multi-Speed 8
    "材琿硉        Hz  "	,   //  248 04-09   Multi-Speed 9
    "材⑻琿硉        Hz  "	,   //  249 04-10   Multi-Speed 10 
    "材⑻琿硉      Hz  "	,   //  250 04-11   Multi-Speed 11
    "材⑻琿硉      Hz  "	,   //  251 04-12   Multi-Speed 12
    "材⑻琿硉      Hz  "	,   //  252 04-13   Multi-Speed 13
    "材⑻琿硉      Hz  "	,   //  253 04-14   Multi-Speed 14
    "材⑻き琿硉      Hz  "	,   //  254 04-15   Multi-Speed 15
    
    "毕穿硉        m/s "  ,   //  2xx 04-16
    "キ糷硉        m/s "  ,   //  2xx 04-17
    "は膀硉      m/s "  ,   //  2xx 04-18
    "葵ゴ菲干纕    mm  "  ,   //  2xx 04-19   GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //  2xx 04-20
    "TABST2 Status       "  ,   //  2xx 04-21
    "程蔼瞶加糷        "  ,   //  2xx 04-22
    "ヘ玡加糷            "  ,   //  2xx 04-23
    "侥タ兵ン    %   "  ,   //  2xx 04-24
    "秨闽┑筐干纕    sec "  ,   //    2xx 04-25
    "单硉ぞ緇丁    ms  "  ,   //  2xx 04-26
    "帝狾      mm  "  ,   //  2xx 04-27 
    "ヘ玡竚 蔼     m   "  ,   //  2xx 04-28
    "ヘ玡竚      mm  "  ,   //  2xx 04-29
    "ヘ玡侥 H          "  ,   //  2xx 04-30 
    "ヘ玡侥 L          "  ,   //  2xx 04-31
    "帝狾侥 H        "  ,   //  2xx 04-32
    "帝狾侥 L        "  ,   //  2xx 04-33
    "筿丁禯侥H       "  ,   //  2xx 04-34
    "筿丁禯侥L       "  ,   //  2xx 04-35
    "DLC\栋           "  ,  //  2xx 04-36   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "PDO陪ボ篈         "  ,   //  2xx 04-37
    "搭硉秨闽甧砛\粇畉mm  "  ,  //  2xx 04-38   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "程辫硉κだゑ  %   "  ,   //  2xx 04-39   //[ADCO EPS Modify]
    "紆庐┑干纕    mm  "  ,   //    2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //  2xx 04-41
    "EST Count           "  ,   //  2xx 04-42
    "TABST0 Count        "  ,   //  2xx 04-43
    "TABST1 Count        "  ,   //  2xx 04-44
    "DDS1/UDS1硉   m/s "  ,   //  2XX 04-45   DD1_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS2/UDS2硉   m/s "  ,   //  2XX 04-46   DD2_Vlim  //Artemis speed limit, James, 20200220                                
    "DDS3/UDS3硉   m/s "  ,   //  2XX 04-47   DD3_Vlim  //Artemis speed limit, James, 20200220                                      
    "DDS4/UDS4硉   m/s "  ,   //  2XX 04-48   DD4_Vlim  //Artemis speed limit, James, 20200220
    "\砞﹚        "  ,  //  2XX 04-49   user page cahnge       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    
    "1 加竚 蔼     m   "  ,   //  2XX 04-50   1Floor Position H 
    "1 加竚      mm  "  ,   //  2XX 04-51   1Floor Position L                                       
    "2 加竚 蔼     m   "  ,   //  2XX 04-52   2Floor Position H                                       
    "2 加竚      mm  "  ,   //  2XX 04-53   2Floor Position L                                       
    "3 加竚 蔼     m   "  ,   //  2XX 04-54   3Floor Position H                                       
    "3 加竚      mm  "  ,   //  2XX 04-55   3Floor Position L                                       
    "4 加竚 蔼     m   "  ,   //  2XX 04-56   4Floor Position H                                       
    "4 加竚      mm  "  ,   //  2XX 04-57   4Floor Position L                                       
    "5 加竚 蔼     m   "  ,   //  2XX 04-58   5Floor Position H                                       
    "5 加竚      mm  "  ,   //  2XX 04-59   5Floor Position L                                       
    "6 加竚 蔼     m   "  ,   //  2XX 04-60   6Floor Position H                                       
    "6 加竚      mm  "  ,   //  2XX 04-61   6Floor Position L                                       
    "7 加竚 蔼     m   "  ,   //  2XX 04-62   7Floor Position H                                       
    "7 加竚      mm  "  ,   //  2XX 04-63   7Floor Position L                                       
    "8 加竚 蔼     m   "  ,   //  2XX 04-64   8Floor Position H                                       
    "8 加竚      mm  "  ,   //  2XX 04-65   8Floor Position L                                       
    "9 加竚 蔼     m   "  ,   //  2XX 04-66   9Floor Position H                                       
    "9 加竚      mm  "  ,   //  2XX 04-67   9Floor Position L                                       
    "10加竚 蔼     m   "  ,   //  2XX 04-68   10Floor Position H                                      
    "10加竚      mm  "  ,   //  2XX 04-69   10Floor Position L                                      
    "11加竚 蔼     m   "  ,   //  2XX 04-70   11Floor Position H                                      
    "11加竚      mm  "  ,   //  2XX 04-71   11Floor Position L                                      
    "12加竚 蔼     m   "  ,   //  2XX 04-72   12Floor Position H                                      
    "12加竚      mm  "  ,   //  2XX 04-73   12Floor Position L                                      
    "13加竚 蔼     m   "  ,   //  2XX 04-74   13Floor Position H                                      
    "13加竚      mm  "  ,   //  2XX 04-75   13Floor Position L                                      
    "14加竚 蔼     m   "  ,   //  2XX 04-76   14Floor Position H                                      
    "14加竚      mm  "  ,   //  2XX 04-77   14Floor Position L                                      
    "15加竚 蔼     m   "  ,   //  2XX 04-78   15Floor Position H                                      
    "15加竚      mm  "  ,   //  2XX 04-79   15Floor Position L                                      
    "16加竚 蔼     m   "  ,   //  2XX 04-80   16Floor Position H                                      
    "16加竚      mm  "  ,   //  2XX 04-81   16Floor Position L                                      
    "17加竚 蔼     m   "  ,   //  2XX 04-82   17Floor Position H                                      
    "17加竚      mm  "  ,   //  2XX 04-83   17Floor Position L                                      
    "18加竚 蔼     m   "  ,   //  2XX 04-84   18Floor Position H                                      
    "18加竚      mm  "  ,   //  2XX 04-85   18Floor Position L                                      
    "19加竚 蔼     m   "  ,   //  2XX 04-86   19Floor Position H                                      
    "19加竚      mm  "  ,   //  2XX 04-87   19Floor Position L                                      
    "20加竚 蔼     m   "  ,   //  2XX 04-88   20Floor Position H                                      
    "20加竚      mm  "  ,   //  2XX 04-89   20Floor Position L                                      
    "21加竚 蔼     m   "  ,   //  2XX 04-90   21Floor Position H                                      
    "21加竚      mm  "  ,   //  2XX 04-91   21Floor Position L                                      
    "22加竚 蔼     m   "  ,   //  2XX 04-92   22Floor Position H                                      
    "22加竚      mm  "  ,   //  2XX 04-93   22Floor Position L                                      
    "23加竚 蔼     m   "  ,   //  2XX 04-94   23Floor Position H                                      
    "23加竚      mm  "  ,   //  2XX 04-95   23Floor Position L                                      
    "24加竚 蔼     m   "  ,   //  2XX 04-96   24Floor Position H                                      
    "24加竚      mm  "  ,   //  2XX 04-97   24Floor Position L                                      
    "25加竚 蔼     m   "  ,   //  2XX 04-98   25Floor Position H                                      
    "25加竚      mm  "  ,   //  2XX 04-99   25Floor Position L                                      
    
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM把计厩策        "	,	//	255 05-00   Motor Auto-Tuning
    "IM筿诀肂﹚筿瑈  Amps"	,	//	256 05-01   Motor 1 rated Current           
    "IM筿诀肂﹚\瞯  Kw  "	,	//	257 05-02   Motor 1 Rated Power       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]           
    "IM筿诀肂﹚锣硉  RPM "	,	//	258 05-03   Motor 1 Rated RPM               
    "IM筿诀伐计          "	,	//	259 05-04   Motor 1 pole No.                
    "IM筿诀礚更筿瑈  Amps"	,	//	260 05-05   Motor 1 No-Load Current         
    "IM筿诀把计 Rs   ohm "	,	//	261 05-06   Motor 1 Rs                      
    "IM筿诀把计 Rr   ohm "	,	//	262 05-07   Motor 1 Rr                      
    "IM筿诀把计 Lm   mH  "	,	//	263 05-08   Motor 1 Lm                      
    "IM筿诀把计 Lx   mH  "	,	//	264 05-09   Motor 1 Lx                      
    "锣痻干纕硄耾猧sec "	,	//	265 05-10   Vector Voltage Filter	        
    "菲畉干纕硄耾猧sec "	,	//	266 05-11   Vector Slip Filter	            
    "锣痻干纕糤痲        "	,	//	267 05-12   Torque Compensation Gain	    
    "菲畉干纕糤痲        "	,	//	268 05-13   Slip Compensation Gain	        
    "菲畉粇畉非    %   "	,	//	269 05-14   Slip Deviation level	        
    "菲畉粇畉浪丁sec "	,	//	270 05-15   Slip Deviation Detect Time	    
    "筁菲畉浪匡拒      "	,	//	271 05-16   Over Slip treatment	            
    "綺历干纕        "	,	//	272 05-17   Coeff for hunting disable	    
    "仓縩筿诀笲锣丁Mins"	,	//	273 05-18   Accumulative Motor Operation Min
    "仓縩筿诀笲锣ぱ计Days"	,	//	274 05-19   Accumulative Motor Operation Day
    "臟慷穕ア干纕    %   "	,	//	275 05-20   Coreloss % of output Power	    
    "跑繵竟筿丁  Mins"	,	//	276 05-21   Power On Min
    "跑繵竟筿ぱ计  Days"	,	//	277 05-22   Power On Day    
    "ネ菲畉干纕糤痲%   "  ,   //  2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"筿笆菲畉干纕糤痲%   "	,	//	123 05-24   RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "筿溃非      V   "	,	//  278 06-00   Low voltage level
    "ろ玂臔            "	,	//  279 06-01   Phase loss
    "硉筁筿瑈ア硉  %   "	,	//	280 06-02   OC stall during Accel
    "﹚硉筁筿瑈ア硉  %   "	,	//	281 06-03   OC stall during Decel
    "筁筿瑈ア硉矪瞶      "	,	//	282 06-04   Stall preventation Accel/Decel time selection
    "筁锣痻OT1矪瞶       "	,	//	283 06-05   Over-Torque 1 Selection
    "筁锣痻OT1非   %   "	,	//	284 06-06   Over-Torque 1 level
    "筁锣痻OT1浪   sec "	,	//	285 06-07   Over-Torque 1 Time
    "筁锣痻OT2矪瞶       "	,	//	286 06-08   Over-Torque 2 Selection	                     
    "筁锣痻OT2非   %   "	,	//	287 06-09   Over-Torque 2 level	                         
    "筁锣痻OT2浪   sec "	,	//	288 06-10   Over-Torque 2 Time	                         
    "筿瑈        %   "	,	//	289 06-11   Current Limit
    "筿荐筿沛匡拒      "	,	//	290 06-12   Thermal Relay 1 Selection
    "荐筿沛ノ丁  sec "	,	//	291 06-13   Thermal Relay 1 Time
    "筁荐牡放非C   "	,	//	292 06-14   OH Warning Level
    "ア硉ňゎ非%   "	,	//	293 06-15   Stall preventation Limit Level
    "程Ω珿毁魁    "	,	//	294 06-16   1st Fault Record
    "2Ω玡珿毁魁     "	,	//	295 06-17   2nd Fault Record
    "3Ω玡珿毁魁     "	,	//	296 06-18   3rd Fault Record
    "4Ω玡珿毁魁     "	,	//	297 06-19   4th Fault Record
    "5Ω玡珿毁魁     "	,	//	298 06-20   5th Fault Record
    "6Ω玡珿毁魁     "	,	//	299 06-21   6th Fault Record
    "钵盽块匡拒 1      "	,	//	300 06-22   Fault Option 1
    "钵盽块匡拒 2      "	,	//	301 06-23   Fault Option 2
    "钵盽块匡拒 3      "	,	//	302 06-24   Fault Option 3
    "钵盽块匡拒 4      "	,	//	303 06-25   Fault Option 4
    "PTC笆匡拒         "	,	//	304 06-26   PTC over Treatments	                         
    "PTC非         %   "	,	//	305 06-27   PTC Level
    "PTC浪丁     sec "	,	//	306 06-28   PTC Detect Filter time
    "候笲︽筿方筿溃V   "	,	//	307 06-29   EPS voltage level
    "岿粇块匡拒        "	,	//	308 06-30   Fault Option Mode
    "ED 块ろ盎代     "	,	//	309 06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "玡Ω钵盽笲锣  Mins"	,	//	310 06-32   1st Fault Time(MIN)
    "玡Ω钵盽笲锣  Days"	,	//	311 06-33   1st Fault Time(DAY)
    "2Ω玡钵盽笲锣   Mins"	,	//	312 06-34   2nd Fault Time(MIN)
    "2Ω玡钵盽笲锣   Days"	,	//	313 06-35   2nd Fault Time(DAY)
    "3Ω玡钵盽笲锣   Mins"	,	//	314 06-36   3rd Fault Time(MIN)
    "3Ω玡钵盽笲锣   Days"	,	//	315 06-37   3rd Fault Time(DAY)
    "4Ω玡钵盽笲锣   Mins"	,	//	316 06-38   4th Fault Time(MIN)
    "4Ω玡钵盽笲锣   Days"	,	//	317 06-39   4th Fault Time(DAY)
    "5Ω玡钵盽笲锣   Mins"	,	//	318 06-40   5th Fault Time(MIN)
    "5Ω玡钵盽笲锣   Days"	,	//	319 06-41   5th Fault Time(DAY)
    "6Ω玡钵盽笲锣   Mins"	,	//	320 06-42   6th Fault Time(MIN)
    "6Ω玡钵盽笲锣   Days"	,	//	321 06-43   6th Fault Time(DAY)
    "候筿方笲︽硉Hz  "  ,   //  322 06-44   EPS Frequency
    "岿粇笆匡拒        "  ,	//  323 06-45   LV Option Mode
    "EPS 家Α匡拒        "  ,	//  324 06-46   EPS Option Mode
    "祇筿よ穓碝丁sec "  ,   //  325 06-47   Generation Operation Detected Time
    "候笲︽筿方甧秖KVA "  ,   //  326 06-48   UPS Capacity (0.1KVA)
    "STO\匡拒        "  ,   //  3xx 06-49   STO Lock selection     //[Safty function, Bernie]    
    "珿毁刚MO笆    "  ,   //  356 06-50   Base Block Speed Search (oc,ov,occ.......)  //[Add auto restart after fault, Bernie, 06/06/12]
    "珿毁刚Ω计        "  ,   //  356 06-51   Auto restart times after fault     
    "珿毁刚丁    sec "  ,   //  356 06-52   Auto restart interval
    "钵盽繵瞯㏑  Hz  "  ,   //  3xx 06-53   Fkey Record
    "钵盽繵瞯块  Hz  "  ,   //  3xx 06-54   Fcmd Record
    "钵盽块筿瑈  Amps"  ,   //  3xx 06-55   Isum Record
    "钵盽皑笷繵瞯  Hz  "  ,   //  3xx 06-56   Fout Record
    "钵盽块筿溃  V   "  ,   //  3xx 06-57   Vout Record
    "钵盽DCBus筿溃 V   "  ,   //  3xx 06-58   Dcbus Record    
    "钵盽块\瞯  KW  "  ,  //  3xx 06-59   Power Record                                // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "钵盽块锣痻  %   "  ,   //  3xx 06-60   Torque Record
    "钵盽IGBT放  C   "  ,   //  3xx 06-61   IGBT Temperature Record   
    "钵盽块狠  Hex "  ,   //  3xx 06-62   MFI State Record
    "钵盽块狠  Hex "  ,   //  3xx 06-63   MFO State Record
    "钵盽臱笆竟篈Hex "  ,   //  3xx 06-64   Drive State Record
    "UCMP筿瑈非%   "  ,   //  3XX 06-65   Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
    "臱笆竟狝叭Ω计      "  ,   //  3xx 06-66   Service time count                          //[Service time function, Bernie, 2017/03/14]
    "臱笆竟狝叭砞﹚      "  ,   //  3xx 06-67   Service time function Enable                //[Service time function, Bernie, 2017/03/14]
    "EPS盎代\非 deg "  ,  //  3xx 06-68   EPS Detect Current    
    "EPS\à       deg "  ,  //  3xx 06-69   EPS Detect Current Ref
    "EPSよ块         "  ,   //  3xx 06-70   EPS Detect direction
    "EPS狠块┑筐 sec "  ,   //  3xx 06-71   EPS MO Off Time
    "EPS狠超┑筐 sec "  ,   //  3xx 06-72   EPS MO Off Time
    "ッ笲︽よ璸计H   "	,	//	3xx 06-73   Running direction count high						
    "ッ笲︽よ璸计L   "	,	//	3xx 06-74   Running direction count low
    "虫Ω笲︽よ璸计H   "	,	//	3xx 06-75   Temp running direction count high
    "虫Ω笲︽よ璸计L   "	,	//  3xx 06-76   Temp running direction count low
    "虫Ω笲︽竚Ω计    "	,	//	3xx 06-77   Temp running reset count
    "笲︽よΩ计k   "	,	//	3xx 06-78   Running life
    "笲︽Ω计\匡兜    "	,	//	3xx 06-79   Running function
    "钵盽2繵瞯块  Hz  " ,   //  3xx 06-80   Fcmd Record1
    "钵盽2DCBus筿溃 V   " ,   //  3xx 06-81   Dcbus Record1
    "钵盽2块筿瑈  Amps" ,   //  3xx 06-82   Isum Record1
    "钵盽2IGBT放  C   "	,	//  3xx 06-83   IGBT Temperature Record1
    "钵盽3繵瞯块  Hz  " ,   //  3xx 06-84   Fcmd Record2
    "钵盽3DCBus筿溃 V   " ,   //  3xx 06-85   Dcbus Record2
    "钵盽3块筿瑈  Amps" ,   //  3xx 06-86   Isum Record2
    "钵盽3IGBT放  C   " ,   //  3xx 06-87   IGBT Temperature Record2
    "钵盽4繵瞯块  Hz  " ,   //  3xx 06-88   Fcmd Record3
    "钵盽4DCBus筿溃 V   " ,   //  3xx 06-89   Dcbus Record3
    "钵盽4块筿瑈  Amps" ,   //  3xx 06-90   Isum Record3
    "钵盽4IGBT放  C   " ,   //  3xx 06-91   IGBT Temperature Record3
    "钵盽5繵瞯块  Hz  " ,   //  3xx 06-92   Fcmd Record4
    "钵盽5DCBus筿溃 V   " ,   //  3xx 06-93   Dcbus Record4
    "钵盽5块筿瑈  Amps" ,   //  3xx 06-94   Isum Record4
    "钵盽5IGBT放  C   " ,   //  3xx 06-95   IGBT Temperature Record4
    "钵盽6繵瞯块  Hz  " ,   //  3xx 06-96   Fcmd Record5
    "钵盽6DCBus筿溃 V   " ,   //  3xx 06-97   Dcbus Record5
    "钵盽6块筿瑈  Amps" ,   //  3xx 06-98   Isum Record5
    "钵盽6IGBT放  C   " ,   //  3xx 06-99   IGBT Temperature Record5

/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "焚ó垂砰筿非V   "	,	//	327 07-00 SW Braking Level
    "焚ó垂砰筐孩筿溃V   "  ,   //	328 07-01 DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "癬笆瑈笆非%   "	,	//	329 07-02 DCI Current Level     //[DCI Level when stop, Bernie, 05/21/2012]
    "癬笆瑈笆丁sec "	,	//	330 07-03 DCI Time at Start 
    "氨ó瑈笆丁sec "	,	//	331 07-04 DCI Time at STOP
    "氨ó笆癬﹍繵瞯Hz  "	,	//	332 07-05 DCI Freq. At start
    "瑈笆I糤痲       "	,	//	333 07-06 DCI KI
    "睛回硉い耞丁sec "	,	//	334 07-07 Gear wait time when acceleration
    "睛回硉い耞繵瞯Hz  "	,	//	335 07-08 Gear wait frequency when acceleration
    "睛回搭硉い耞丁sec "	,	//	336 07-09 Gear wait time when deceleration
    "睛回搭硉い耞繵瞯Hz  "	,	//	337 07-10 Gear wait frequency when deceleration
    "北よΑ        "	,	//	338 07-11 Fan Control
    "锣痻㏑        %   "	,	//	339 07-12 TQC Reference from RS485
    "锣痻㏑ㄓ方        "	,	//	340 07-13 Source of Torque Command
    "程锣痻㏑    %   "	,	//	341 07-14 Torque max. level
    "锣痻㏑耾猧丁sec "	,	//	342 07-15 Torque command filter
    "硉匡拒        "	,	//	343 07-16 Speed Limit selection
    "锣痻家Α+SPD%   "	,	//	344 07-17 Torque mode positive speed limit
    "锣痻家Α-SPD%   "	,	//	345 07-18 Torque mode negative speed limit
    "锣痻㏑熬溃ㄓ方    "	,	//	346 07-19 Torque offset selection
    "锣痻㏑熬溃砞﹚%   "	,	//	347 07-20 Torque offset setting level
    "蔼锣痻熬秖      %   "	,	//	348 07-21 Torque offset setting level High
    "い锣痻熬秖      %   "	,	//	349 07-22 Torque offset setting level Middle
    "锣痻熬秖      %   "	,	//	350 07-23 Torque offset setting level Low
    "タ锣筿笆锣痻%   "	,	//	351 07-24 FWD Motoring Tq Limit
    "タ锣ネ锣痻%   "	,	//	352 07-25 FWD Regeneration Tq Limit
    "は锣筿笆锣痻%   "	,	//	353 07-26 REV Motoring Tq Limit
    "は锣ネ锣痻%   "	,	//	354 07-27 REV Regeneration Tq Limit
    "眏氨诀浪よΑ    "	,	//	355 07-28 Emergency Stop & Forced Stop selection
    "氨ó锣痻患搭丁sec "	,	//	356 07-29 Torque Decrease Time
    "氨ゎ瑈笆非%   "	,	//	356 07-30 STOP DC Inject Level     //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  357 07-31  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx浪代            "  ,   //  358 07-32  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx浪代禯瞒     ppr"  ,   //  359 07-33  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx浪代计        "  ,   //  360 07-34  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx浪代ア毖锣痻    "  ,   //  361 07-35  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx浪代程锣痻    "  ,   //  362 07-36  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx浪代程锣痻    "  ,   //  362 07-37  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM把计厩策        "	,	//	357 08-00   PMotor Auto-Tuning  
    "PM筿诀肂﹚筿瑈  Amps"	,	//	358 08-01   PMotor rated Current 
    "PM筿诀肂﹚\瞯  Kw  "	,	//	359 08-02   PMotor Rated Power           // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "PM筿诀肂﹚锣硉  RPM "	,	//	360 08-03   PMotor Rated RPM    
    "PM筿诀伐计          "	,	//	361 08-04   PMotor pole No.     
    "PM筿诀把计 Rs   ohm "	,	//	362 08-05   PMotor Rs           
    "PM筿诀把计 Ld   mH  "	,	//	363 08-06   PMotor Ld           
    "PM筿诀把计 Lq   mH  "	,	//	364 08-07   PMotor Lq           
    "筿诀は筿笆墩    Vrms"	,	//	365 08-08   PMotor Bemf coff	
    "合伐熬簿à      deg "	,	//	366 08-09   PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
    "合伐穝﹚        "	,	//	367 08-10   //ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "硄癟            "	,	//	368   09-06    Comm Address                              
    "硄癟肚癳硉    kbps"	,	//	369   09-07    Tranmission speed                         
    "硄癟岿粇矪瞶        "	,	//	370   09-08    Comm fault Treatment                      
    "筄浪丁    sec "	,	//	371   09-09    Comm Time out                             
    "硄癟Α            "	,	//	372   09-10    Comm Protocol                             
    "莱┑筐丁    ms  "	,	//	373   09-11    ASC remote Response Delay Time, 1=100us   
    "CAN 硄癟瞯        "  ,   //  3XX   09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "CAN PDOユ搐丁 ms  "  ,   //  3XX   09-07    CAN PDO Handshaking Period
    "CAN PDO硄癟筄 ms  "  ,   //  3XX   09-08    CAN Communiction Timeout 
    "诀醚絏        "  ,   //  3XX   09-09 
    "FHM 既竟          "  ,   //  3XX   09-10   
    "DLC 既竟1         "  ,   //  3XX   09-11   
    "DLC 既竟2         "  ,   //  3XX   09-12    
    "DLC 既竟3         "  ,   //  3XX   09-13    
    "PDO肚癳丁筳     ms  "  ,   //  3XX   09-14     CAN fail rate---aevin 6/12/2017
/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"絪絏竟贺摸匡拒      "	,	//	374   10-00 Encoder TYPE                             
	"絪絏竟≧翴计  ppr "	,	//	375   10-01 Encoder pulses	                    
	"絪絏竟块Α      "	,	//	376   10-02 PG input setting	                
	"PG岿粇笆匡拒      "	,	//	377   10-03 PG fbk fault treatment	            
	"PG岿粇浪丁  sec "	,	//	378   10-04 PG fbk Error Detection Time	        
	"PGア硉非      %   "	,	//	379   10-05 PG fbk overspeed detection level	
	"PFア硉浪丁  sec "	,	//	380   10-06 Over speed Detection Time	        
	"PG锣畉钵盽非  %   "	,	//	381   10-07 PG fbk speed deviation level	    
	"PG锣畉浪丁  sec "	,	//	382   10-08 Deviation Detect Time	            
	"PGア硉笆匡拒      "	,	//	383   10-09 Operation at overspeed	            
	"HALL獺腹家Α匡拒    "  ,   //  384   10-10 Hall Input Types
	"癬笆箂硉糤痲P       "	,	//	385   10-11 KP gain of ASR in Zero speed	
	"癬笆箂硉縩だI   sec "	,	//	386   10-12 Ki gain of ASR in Zero speed	
	"硉糤痲P           "	,	//	387   10-13 ASR P Gain 1	                
	"硉縩だ丁I   sec "	,	//	388   10-14 ASR I Gain 1	                
	"蔼硉糤痲P           "	,	//	389   10-15 ASR P Gain 2	                
	"蔼硉縩だ丁I   sec "	,	//	390   10-16 ASR I Gain 2	                
	"/蔼硉ち传繵瞯 Hz  "	,	//	391   10-17 ASR1/ASR2 switch freq	        
	"ASR硄耾猧糤痲 sec "	,	//	392   10-18 Primary LowPass filter Gain 
	"竚北ASR糤痲P    "  ,	//	393   10-19 position control Kp Gain  
    "箂/硉糴秸俱 Hz  "  ,   //  394   10-20 Low Spd band
    "/蔼硉糴秸俱 Hz  "  ,   //  395   10-21 High Spd band
	"竚北ASR縩だIsec "	,	//	396   10-22 Position control time
	"癬笆竚北硄sec "	,	//	397   10-23 Position control LOW POSS FILTER
	"竚北家Α匡拒    "	,	//	398   10-24 Source of position control, add by dino, 06/30/2008
	"キ糷箂硉糤痲P   %   "	,	//	399   10-25 KP gain of ASR in Zero speed of Landing
	"キ糷箂硉縩だI   sec "	,	//	400   10-26 Ki gain of ASR in Zero speed of Landing
	"竚北箂硉糤痲%   "	,	//	385   10-27 KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"竚北箂硉縩だsec "	,	//	386   10-28 Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
    "PG埃繵块      "	,   //  4xx   10-29 PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG埃繵块Α    "	,   //  4xx   10-30 PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C-匡拒        "  ,   //  110   10-31 RESERVED    //[change parameter to normal group, Bernie, 2014/02/14]
    "筿辫筁硉非m/s2"  ,   //  3XX   10-32 Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "筁硉盎代丁sec "  ,   //  3XX   10-33     Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "筁硉盎匡拒      "  ,   //  3XX   10-34     Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    "ACC LPF             "  ,   //  422 10-35   //Rationa 362631, Special.Kung
    "ACC SampleRate    ms"  ,   //  422 10-36   //Rationa 362631, Special.Kung
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "╰参北        Hex "	,	//	401   11-00     system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "程繵瞯癸莱辫硉m/s "  ,   //  402   11-01     Lift operation speed                                        
    "Σま近畖      mm  "  ,   //  403   11-02     SHEAVE diameter			ADDED BY SCOTTY                     
    "睛近ゑ              "  ,   //  404   11-03     Gear Ratio                                              
    "腶本ゑ              "  ,   //  405   11-04     Suspension ratio	                                        
    "诀瘪篋秖κだゑ  %   "  ,   //  406   11-05     inertia	percent			ADDED BY SCOTTY                     
    "癬笆箂硉繵糴    Hz  "	,	//	407   11-06     Zero Speed Loop BandWidth	                                
    "硉繵糴        Hz  "	,	//	408   11-07     Speed Loop BandWidth1		                                
    "蔼硉繵糴        Hz  "	,	//	409   11-08     Speed Loop BandWidth2		                                
    "PDFF糤痲      %   "	,	//	410   11-09     PDFFKr		                                                
    "硉北玡鮔糤痲%   "	,	//	411   11-10     SPEED FFD GAIN			ADDED BY SCOTTY                     
    "炒耾猧瞏    db  "	,	//	412   11-11     Netch filter deep(db)	                                    
    "炒耾猧繵瞯    Hz  "	,	//	413   11-12     Netch filter frequency	                                    
    "狾陪ボ耾猧丁sec "	,	//	414   11-13     Low Pass Filter for display	                                
    "硉程筿瑈  %   "	,	//	415   11-14     ACC Max current                                             
    "筿辫程硉  m/s2"  ,	//	416   11-15     max meter/sec	                                            
    "菏北戈    Hex "  ,   //	417   11-16     Display address,add by dino 2007/03/08                      
    "菏北戈            "  ,	//	418   11-17     Display data,   add by dino 2007/03/08                      
    "玂痙                "  ,   //  419   11-18     Protect Bit	                                                
    "氨ó箂硉繵糴    Hz  "	,	//	420   11-19     Zero Speed Loop BandWidth of Landing
    "PWM 家Α匡拒        "  ,   //  4XX   11-20     PWM mode selection  //[move parameter to 11-20, Bernie, 2017/02/16]
    "LC01陪ボ耾猧丁 sec"	,	//	422   11-21	    Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	420   11-21     Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22       //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "璹把计 1          "  ,   //  421   12-00
    "璹把计 2          "  ,   //  422   12-01
    "璹把计 3          "  ,   //  423   12-02
    "璹把计 4          "  ,   //  424   12-33
    "璹把计 5          "  ,   //  425   12-04
    "璹把计 6          "  ,   //  426   12-05
    "璹把计 7          "  ,   //  427   12-06
    "璹把计 8          "  ,   //  428   12-07
    "璹把计 9          "  ,   //  429   12-08
    "璹把计 10         "  ,   //  430   12-09
    "璹把计 11         "  ,   //  431   12-10
    "璹把计 12         "  ,   //  432   12-11
    "璹把计 13         "  ,   //  433   12-12
    "璹把计 14         "  ,   //  434   12-13
    "璹把计 15         "  ,   //  435   12-14
    "璹把计 16         "  ,   //  436   12-15
    "璹把计 17         "  ,   //  437   12-16
    "璹把计 18         "  ,   //  438   12-17
    "璹把计 19         "  ,   //  439   12-18
    "璹把计 20         "  ,   //  440   12-19
    "璹把计 21         "  ,   //  441   12-20
    "璹把计 22         "  ,   //  442   12-21
    "璹把计 23         "  ,   //  443   12-22
    "璹把计 24         "  ,   //  444   12-23
    "璹把计 25         "  ,   //  445   12-24
    "璹把计 26         "  ,   //  446   12-25
    "璹把计 27         "  ,   //  447   12-26
    "璹把计 28         "  ,   //  448   12-27
    "璹把计 29         "  ,   //  449   12-28
    "璹把计 30         "  ,   //  450   12-29
    "璹把计 31         "  ,   //  451   12-30
    "璹把计 32         "  ,   //  452   12-31
    "璹把计 33         "  ,   //  433   12-12
    "璹把计 34         "  ,   //  434   12-13
    "璹把计 35         "  ,   //  435   12-14
    "璹把计 36         "  ,   //  436   12-15
    "璹把计 37         "  ,   //  437   12-16
    "璹把计 38         "  ,   //  438   12-17
    "璹把计 39         "  ,   //  439   12-18
    "璹把计 40         "  ,   //  430   12-09
    "璹把计 41         "  ,   //  431   12-10
    "璹把计 42         "  ,   //  432   12-11
    "璹把计 43         "  ,   //  433   12-12
    "璹把计 44         "  ,   //  434   12-13
    "璹把计 45         "  ,   //  435   12-14
    "璹把计 46         "  ,   //  436   12-15
    "璹把计 47         "  ,   //  437   12-16
    "璹把计 48         "  ,   //  438   12-17
    "璹把计 49         "  ,   //  439   12-18
    "璹把计 50         "  ,   //  430   12-09
    "玂痙                "  ,   //  431   12-10
    "玂痙                "  ,   //  432   12-11
    "玂痙                "  ,   //  433   12-12
    "玂痙                "  ,   //  434   12-13
    "玂痙                "  ,   //  435   12-14
    "玂痙                "  ,   //  436   12-15
    "玂痙                "  ,   //  437   12-16
    "玂痙                "  ,   //  438   12-17
    "玂痙                "  ,   //  439   12-18
    "玂痙                "  ,   //  430   12-09
    "玂痙                "  ,   //  431   12-10
    "玂痙                "  ,   //  432   12-11
    "玂痙                "  ,   //  433   12-12
    "玂痙                "  ,   //  434   12-13
    "玂痙                "  ,   //  435   12-14
    "玂痙                "  ,   //  436   12-15
    "玂痙                "  ,   //  437   12-16
    "玂痙                "  ,   //  438   12-17
    "玂痙                "  ,   //  439   12-18
    "玂痙                "  ,   //  430   12-09
    "玂痙                "  ,   //  431   12-10
    "玂痙                "  ,   //  432   12-11
    "玂痙                "  ,   //  433   12-12
    "玂痙                "  ,   //  434   12-13
    "玂痙                "  ,   //  435   12-14
    "玂痙                "  ,   //  436   12-15
    "玂痙                "  ,   //  437   12-16
    "玂痙                "  ,   //  438   12-17
    "玂痙                "  ,   //  439   12-18
    "玂痙                "  ,   //  430   12-09
    "玂痙                "  ,   //  431   12-10
    "玂痙                "  ,   //  432   12-11
    "玂痙                "  ,   //  433   12-12
    "玂痙                "  ,   //  434   12-13
    "玂痙                "  ,   //  435   12-14
    "玂痙                "  ,   //  436   12-15
    "玂痙                "  ,   //  437   12-16
    "玂痙                "  ,   //  438   12-17
    "玂痙                "  ,   //  439   12-18
    "玂痙                "  ,   //  430   12-09
    "玂痙                "  ,   //  431   12-10
    "玂痙                "  ,   //  432   12-11
    "玂痙                "  ,   //  433   12-12
    "玂痙                "  ,   //  434   12-13
    "玂痙                "  ,   //  435   12-14
    "玂痙                "  ,   //  436   12-15
    "玂痙                "  ,   //  437   12-16
    "玂痙                "  ,   //  438   12-17
    "玂痙                "  ,   //  439   12-18
    "玂痙                "  ,   //  439   12-18

/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "﹚盽ノ把计 1      "  ,   //  453   13-00
    "﹚盽ノ把计 2      "  ,   //  454   13-01
    "﹚盽ノ把计 3      "  ,   //  455   13-02
    "﹚盽ノ把计 4      "  ,   //  456   13-33
    "﹚盽ノ把计 5      "  ,   //  457   13-04
    "﹚盽ノ把计 6      "  ,   //  458   13-05
    "﹚盽ノ把计 7      "  ,   //  459   13-06
    "﹚盽ノ把计 8      "  ,   //  460   13-07
    "﹚盽ノ把计 9      "  ,   //  461   13-08
    "﹚盽ノ把计 10     "  ,   //  462   13-09
    "﹚盽ノ把计 11     "  ,   //  463   13-10
    "﹚盽ノ把计 12     "  ,   //  464   13-11
    "﹚盽ノ把计 13     "  ,   //  465   13-12
    "﹚盽ノ把计 14     "  ,   //  466   13-13
    "﹚盽ノ把计 15     "  ,   //  467   13-14
    "﹚盽ノ把计 16     "  ,   //  468   13-15
    "﹚盽ノ把计 17     "  ,   //  469   13-16
    "﹚盽ノ把计 18     "  ,   //  470   13-17
    "﹚盽ノ把计 19     "  ,   //  471   13-18
    "﹚盽ノ把计 20     "  ,   //  472   13-19
    "﹚盽ノ把计 21     "  ,   //  473   13-20
    "﹚盽ノ把计 22     "  ,   //  474   13-21
    "﹚盽ノ把计 23     "  ,   //  475   13-22
    "﹚盽ノ把计 24     "  ,   //  476   13-23
    "﹚盽ノ把计 25     "  ,   //  477   13-24
    "﹚盽ノ把计 26     "  ,   //  478   13-25
    "﹚盽ノ把计 27     "  ,   //  479   13-26
    "﹚盽ノ把计 28     "  ,   //  480   13-27
    "﹚盽ノ把计 29     "  ,   //  481   13-28
    "﹚盽ノ把计 30     "  ,   //  482   13-29
    "﹚盽ノ把计 31     "  ,   //  483   13-30
    "﹚盽ノ把计 32     "  ,   //  484   13-31
    "﹚盽ノ把计 33     "  ,   //  455   13-02
    "﹚盽ノ把计 34     "  ,   //  456   13-33
    "﹚盽ノ把计 35     "  ,   //  457   13-04
    "﹚盽ノ把计 36     "  ,   //  458   13-05
    "﹚盽ノ把计 37     "  ,   //  459   13-06
    "﹚盽ノ把计 38     "  ,   //  460   13-07
    "﹚盽ノ把计 39     "  ,   //  461   13-08
    "﹚盽ノ把计 40     "  ,   //  462   13-09
    "﹚盽ノ把计 41     "  ,   //  463   13-10
    "﹚盽ノ把计 42     "  ,   //  464   13-11
    "﹚盽ノ把计 43     "  ,   //  465   13-12
    "﹚盽ノ把计 44     "  ,   //  466   13-13
    "﹚盽ノ把计 45     "  ,   //  467   13-14
    "﹚盽ノ把计 46     "  ,   //  468   13-15
    "﹚盽ノ把计 47     "  ,   //  469   13-16
    "﹚盽ノ把计 48     "  ,   //  470   13-17
    "﹚盽ノ把计 49     "  ,   //  471   13-18
    "﹚盽ノ把计 50     "  ,   //  462   13-09
    "﹚盽ノ把计 51     "  ,   //  463   13-10
    "﹚盽ノ把计 52     "  ,   //  464   13-11
    "﹚盽ノ把计 53     "  ,   //  465   13-12
    "﹚盽ノ把计 54     "  ,   //  466   13-13
    "﹚盽ノ把计 55     "  ,   //  467   13-14
    "﹚盽ノ把计 56     "  ,   //  468   13-15
    "﹚盽ノ把计 57     "  ,   //  469   13-16
    "﹚盽ノ把计 58     "  ,   //  470   13-17
    "﹚盽ノ把计 59     "  ,   //  471   13-18
    "﹚盽ノ把计 60     "  ,   //  462   13-09
    "﹚盽ノ把计 61     "  ,   //  463   13-10
    "﹚盽ノ把计 62     "  ,   //  464   13-11
    "﹚盽ノ把计 63     "  ,   //  465   13-12
    "﹚盽ノ把计 64     "  ,   //  466   13-13
    "﹚盽ノ把计 65     "  ,   //  467   13-14
    "﹚盽ノ把计 66     "  ,   //  468   13-15
    "﹚盽ノ把计 67     "  ,   //  469   13-16
    "﹚盽ノ把计 68     "  ,   //  470   13-17
    "﹚盽ノ把计 69     "  ,   //  471   13-18
    "﹚盽ノ把计 70     "  ,   //  462   13-09
    "﹚盽ノ把计 71     "  ,   //  463   13-10
    "﹚盽ノ把计 72     "  ,   //  464   13-11
    "﹚盽ノ把计 73     "  ,   //  465   13-12
    "﹚盽ノ把计 74     "  ,   //  466   13-13
    "﹚盽ノ把计 75     "  ,   //  467   13-14
    "﹚盽ノ把计 76     "  ,   //  468   13-15
    "﹚盽ノ把计 77     "  ,   //  469   13-16
    "﹚盽ノ把计 78     "  ,   //  470   13-17
    "﹚盽ノ把计 79     "  ,   //  471   13-18
    "﹚盽ノ把计 80     "  ,   //  462   13-09
    "﹚盽ノ把计 81     "  ,   //  463   13-10
    "﹚盽ノ把计 82     "  ,   //  464   13-11
    "﹚盽ノ把计 83     "  ,   //  465   13-12
    "﹚盽ノ把计 84     "  ,   //  466   13-13
    "﹚盽ノ把计 85     "  ,   //  467   13-14
    "﹚盽ノ把计 86     "  ,   //  468   13-15
    "﹚盽ノ把计 87     "  ,   //  469   13-16
    "﹚盽ノ把计 88     "  ,   //  470   13-17
    "﹚盽ノ把计 89     "  ,   //  471   13-18
    "﹚盽ノ把计 90     "  ,   //  462   13-09
    "﹚盽ノ把计 91     "  ,   //  463   13-10
    "﹚盽ノ把计 92     "  ,   //  464   13-11
    "﹚盽ノ把计 93     "  ,   //  465   13-12
    "﹚盽ノ把计 94     "  ,   //  466   13-13
    "﹚盽ノ把计 95     "  ,   //  467   13-14
    "﹚盽ノ把计 96     "  ,   //  468   13-15
    "﹚盽ノ把计 97     "  ,   //  469   13-16
    "﹚盽ノ把计 98     "  ,   //  470   13-17
    "﹚盽ノ把计 99     "  ,   //  471   13-18
    "﹚盽ノ把计 100    "  ,   //  471   13-18
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
	"COM1硄癟        "	,	//	368   09-00 Comm Address             //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                        
    "COM1硄癟肚癳硉kbps"	,	//	369   09-01 Tranmission speed                         
    "COM1硄癟岿粇矪瞶    "	,	//	370   09-02 Comm fault Treatment                      
    "COM1筄浪丁sec "	,	//	371   09-03 Comm Time out                             
    "COM1硄癟Α        "	,	//	372   09-04 Comm Protocol                             
    "COM1莱┑筐丁ms  "	,	//	373   09-05 ASC remote Response Delay Time, 1=100us     
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
	"第一加速时间    m/s2"	,	//	156	01-12	1st Acceleration time
	"第一减速时间    m/s2"	,	//	157	01-13	1st Deceleration time
	"第二加速时间    m/s2"	,	//	158	01-14	2nd Acceleration time
	"第二减速时间    m/s2"	,	//	159	01-15	2nd Deceleration time
	"第??加速时间    m/s2"	,	//	160	01-16	3rd Acceleration time
	"第??减速时间    m/s2"	,	//	161	01-17	3rd Deceleration time
	"第四加速时间    m/s2"	,	//	162	01-18	4th Acceleration time
	"第四减速时间    m/s2"	,	//	163	01-19	4th Deceleration time
	"寸动加速时间    m/s2"	,	//	164	01-20	JOG Acceleration time
	"寸动减速时间    m/s2"	,	//	165	01-21	JOG Deceleration time
	"停车减速时间    m/s2"
};

const string20 prinfo_sc_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"第一加速时间    f/s2"	,	//	156	01-12	1st Acceleration time
	"第一减速时间    f/s2"	,	//	157	01-13	1st Deceleration time
	"第二加速时间    f/s2"	,	//	158	01-14	2nd Acceleration time
	"第二减速时间    f/s2"	,	//	159	01-15	2nd Deceleration time
	"第??加速时间    f/s2"	,	//	160	01-16	3rd Acceleration time
	"第??减速时间    f/s2"	,	//	161	01-17	3rd Deceleration time
	"第四加速时间    f/s2"	,	//	162	01-18	4th Acceleration time
	"第四减速时间    f/s2"	,	//	163	01-19	4th Deceleration time
	"寸动加速时间    f/s2"	,	//	164	01-20	JOG Acceleration time
	"寸动减速时间    f/s2"	,	//	165	01-21	JOG Deceleration time
	"停车减速时间    f/s2"
};

const string20 prinfo_sc_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"加速开始S1时间  m/s3"	,	//	168	01-24	S curve Accel time 1
	"加速开始S2时间  m/s3"	,	//	169	01-25	S curve Accel time 2
	"加速开始S3时间  m/s3"	,	//	170	01-26	S curve Decel time 1
	"加速开始S4时间  m/s3"	,	//	171	01-27	S curve Decel time 2
	"加速开始S5时间  m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_sc_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"加速开始S1时间  f/s3"	,	//	168	01-24	S curve Accel time 1
	"加速开始S2时间  f/s3"	,	//	169	01-25	S curve Accel time 2
	"加速开始S3时间  f/s3"	,	//	170	01-26	S curve Decel time 1
	"加速开始S4时间  f/s3"	,	//	171	01-27	S curve Decel time 2
	"加速开始S5时间  f/s3"	,	//	174	01-30	S curve Decel time 3
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
    "机种标识符          "	,	//	128 00-00	Model Type of Drive 
    "变?灯鞫疃ǖ缌?  Amps"	,	//	129 00-01	Rated Current
    "参数重置设定        "	,	//	130 00-02	Parameter Reset
    "开机显示画面选择    "	,	//	131 00-03	Start up Display        //chinese 
    "多功能显示选择      "	,	//	132 00-04	User Display            //chinese 
    "定义比例设定        "	,	//	133 00-05	User Coefficient        //chinese 
    "?砑?版本            "	,	//	134 00-06	Software Version
    "参数保护密码输??    "	,	//	135 00-07	Password Input
    "参数保护密码设定    "	,	//	136 00-08	Password Input
    "控制模式            "	,	//	137 00-09	Control Methods
    "速度单位            "	,	//	138 00-10	Velocity Unit Select
    "??动?魇涑龇较?      "	,	//	139 00-11   Change Output Direction, Added by 
    "载波?德?        KHz "	,	//	140 00-12	Carry Frequency
    "自动稳压功能        "	,	//	141 00-13	AVR
    "速度指令来源        "	,	//	142 00-14	Source of Freq. Command
    "运转指令来源        "	,	//	143 00-15	Source of Oper. Command
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"最大操作?德?    Hz  "	,	//	144	01-00 Max Output Freq.
	"电机额定?德?    Hz  "	,	//	145	01-01 Motor Base Frequency 1
	"电机额定电压    V   "	,	//	146	01-02 Max Output Voltage
	"第二输出?德?    Hz  "	,	//	147	01-03 Mid Output Freq.1
	"第二输出电压    V   "	,	//	148	01-04 Mid Output Voltage 1
	"第??输出?德?    Hz  "	,	//	149	01-05 Mid Output Freq.2
	"第??输出电压    V   "	,	//	150	01-06 Mid Output Voltage 2
	"第四输出?德?    Hz  "	,	//	151	01-07 Min Output Freq.
	"第四输出电压    V   "	,	//	152	01-08 Min Output Voltage
	"?舳德?        Hz  "	,	//	153	01-09 Start Frequency
	"输出?德噬舷拗?  Hz  "	,	//	154	01-10 Upper Bound Freq.
	"输出?德氏孪拗?  Hz  "	,	//	155	01-11 Lower Bound Freq.
	"第一加速时间    sec "	,	//	156	01-12 1st Acceleration time      //chinese 
	"第一减速时间    sec "	,	//	157	01-13 1st Deceleration time      //chinese 
	"第二加速时间    sec "	,	//	158	01-14 2nd Acceleration time      //chinese 
	"第二减速时间    sec "	,	//	159	01-15 2nd Deceleration time      //chinese 
	"第??加速时间    sec "	,	//	160	01-16 3rd Acceleration time      //chinese 
	"第??减速时间    sec "	,	//	161	01-17 3rd Deceleration time      //chinese 
	"第四加速时间    sec "	,	//	162	01-18 4th Acceleration time      //chinese 
	"第四减速时间    sec "	,	//	163	01-19 4th Deceleration time      //chinese 
	"寸动加速时间    sec "	,	//	164	01-20 JOG Acceleration time
	"寸动减速时间    sec "	,	//	165	01-21 JOG Deceleration time
	"寸动?德?        Hz  "	,	//	166	01-22 JOG Frequency
	"1-4加速?谢?     Hz  "	,	//	167	01-23 Transition Frequency ACC1/DEC1 to 
	"加速开始S1时间  sec "	,	//	168	01-24 S curve Accel time 1
	"加速开始S2时间  sec "	,	//	169	01-25 S curve Accel time 2
	"加速开始S3时间  sec "	,	//	170	01-26 S curve Decel time 1
	"加速开始S4时间  sec "	,	//	171	01-27 S curve Decel time 2
	"小于第四?德誓?式    "	,	//	172	01-28 Select Zero Speed
	"?讲闼俣??谢?    Hz  "	,	//	173	01-29 Landing Frequency 
	"低于?讲闼俣?S5  sec "	,	//	174	01-30 S curve Decel time 3
	"停车减速时间    sec "	,	//	175	01-31 Stop Deceleration time	
    "终端?恐?减速度  m/s "	,	//  1xx 01-32
    "端子直停高速时间sec "	,	//	1xx	01-33 IODHT IO direct hold time   
    "端子直停?讲闶奔鋝ec "	,	//	1xx	01-34 IODLT IO direct landing freq
    "端子直停冲量限制    "	,	//	1xx	01-35 IODLT IO direct landing time
    "端子直停减速距离cm  "	,	//	1xx	01-36 IODLT IO direct DistancE
    "直停参考减速距离m   "	,	//	1xx	01-37 IODLT IO direct DistancE
    "端子直接停靠致能    "	,	//	1xx	01-38 IODLT IO direct DistancE
    "ETS颈率比较准位 Hz  "  ,   //  1xx 01-39 IODLT IO direct DistancE
    "紧急减速减速时间sec "	,	//	1xx	01-40 IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105 RESERVED
    "Emergency S3    sec "  ,   //  105 15-105 RESERVED
    "Emergency S4    sec "  ,   //  105 15-105 RESERVED
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "2/3 线式运转模式    "	,	//	176	02-00 2/3 wire control                
    "MI1功能选择         "	,	//	177	02-01 Multi-Function Input 1          
    "MI2功能选择         "	,	//	178	02-02 Multi-Function Input 2          
    "MI3功能选择         "	,	//	179	02-03 Multi-Function Input 3          
    "MI4功能选择         "	,	//	180	02-04 Multi-Function Input 4          
    "MI5功能选择         "	,	//	181	02-05 Multi-Function Input 5          
    "MI6功能选择         "	,	//	182	02-06 Multi-Function Input 6          
    "MI7功能选择         "	,	//	183	02-07 Multi-Function Input 7          
    "MI8功能选择         "	,	//	184	02-08 Multi-Function Input 8		    
    "数字输?胂煊κ奔鋝ec "	,	//	185	02-09 Digital in response time		
    "数字输?敕较?        "	,	//	186	02-10 Multi-Function Input Inverse	
    "RA 功能选择         "	,	//	187	02-11 Multi-Function Relay 1		    
    "MRA功能选择         "	,	//	188	02-12 Multi-Function Relay 2		    
    "R1A功能选择         "	,	//	189	02-13 Multi-Function Output 1		    
    "R2A功能选择         "	,	//	190	02-14 Multi-Function Output 2		    
    "MO1功能选择         "	,	//	191	02-15 Multi-Function Output 3		    
    "MO2功能选择         "	,	//	192	02-16 Multi-Function Output 4		    
    "MO3功能选择         "	,	//	193	02-17 Multi-Function Output 5		    
    "MO4功能选择         "	,	//	194	02-18 Multi-Function Output 6		    
    "MO5功能选择         "	,	//	195	02-19 Multi-Function Output 7		    
    "MO6功能选择         "	,	//	196	02-20 Multi-Function Output 8		    
    "MO7功能选择         "	,	//	197	02-21 Multi-Function Output 9		    
    "MO8功能选择         "	,	//	198	02-22 Multi-Function Output 10		    
    "数字输出方向        "	,	//	199	02-23 Multi-Function Output inverse	
    "?舳藕拍?式选择    "  ,   //  200 02-24 Sequence start mode
    "?我馄德实酱?1   Hz  "	,	//	201	02-25 Desired Frequency 1		        
    "?我馄德实酱?1宽 Hz  "	,	//	202	02-26 Band of Desired Frequency 1		
    "?我馄德实酱?2   Hz  "	,	//	203	02-27 Desired Frequency 2		        
    "?我馄德实酱?2宽 Hz  "	,	//	204	02-28 Band of Desired Frequency 2		
    "机械刹车释放延时sec "	,	//	205	02-29 Brake Delay Timer at run
    "机械刹车抱闸延时sec "	,	//	206	02-30 Brake Delay Timer at stop
    "电磁阀导通延时  sec "	,	//	207	02-31 Mech Contact Delay Timer run
    "电磁阀断开延时  sec "	,	//	208	02-32 Mech Contact Delay Timer stop		
    "电流准位设定    %   "	,	//	209	02-33 Isum Current Output Detect	    
    "速度?紊瓒?    Hz  "	,	//	210	02-34 Speed Area
    "机械刹车检出时间sec "	,	//	211	02-35 Mechanical Brake Checking Time
    "电磁阀检出时间  sec "	,	//	212 02-36 Magnetic Contactor Checking Time
    "转矩?啡隙餮≡?    "  ,   //  213 02-37 Mechanical Brake Checking Current Enable
    "电磁阀导通延时  sec "	,	//	207	02-38 Mech Contact Delay Timer run
    "电磁阀断开延时  sec "	,	//	208	02-39 Mech Contact Delay Timer stop	
	"LU/LD异常选择       "  ,   //  2xx 02-40 LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
	"LU/LD开路侦测   sec "  ,   //  2xx 02-41 LD/LD Open Detect Time      //#15977, LULD detect, James, 2021/04/01
	"LU/LD短路侦测   sec "  ,   //  2xx 02-42 LD/LD Short Detect Time     //#15977, LULD detect, James, 2021/04/01
    "运转速度到达宽度Hz  "	,	//  202 02-43 Band of Speed Agree Function #18572			
    "STO短路侦测时间 sec "  ,   //  2xx 02-44 STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45 //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "速度限制        m/s "  ,   //  2xx 02-46 //[Artemis Add Sensor819 Function/Special/2022/06/06]
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AUI1功能选择        "	,	//	214	03-00 AUI1 selection                    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	215	03-01 ACI  selection                    //[ACI function remove, Bernie, 01/20/2012] 
    "AUI2功能选择        "	,	//	216	03-02 AUI2 selection                    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1输?肫?    %   "	,	//	217	03-03 AUI1 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	218	03-04 ACI  input Bias                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2输?肫?    %   "	,	//	219	03-05 AUI2 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1正负?鼓?式    "	,	//	220 03-06 AUI1 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	221 03-07 ACI  input Polarity               //[ACI function remove, Bernie, 01/20/2012]
    "AUI2正负?鼓?式    "	,	//	222 03-08 AUI2 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1输?朐鲆?    %   "	,	//	223 03-09 AUI1 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	224 03-10 ACI  input Gain                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2输?朐鲆?    %   "	,	//	225 03-11 AUI2 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1滤波时间    sec "	,	//	226 03-12 Low pass filter of AUI1 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "保留                "	,	//	227 03-13 Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2滤波时间    sec "	,	//	228 03-14 Low pass filter of AUI2 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "荷重补偿自学习      "	,	//	229 03-15 Loss of ACI                       //[ACI function remove, Bernie, 01/20/2012]
    "保留                "  ,   //  230 03-16 RESERVED 
    "AO1 输出选择        "	,	//	231 03-17 Analong Output 1
    "AO1 输出增益    %   "	,	//	232 03-18 Analong Output 1 Gain
    "AO1 输出反向使能    "	,	//	233 03-19 AO1 in minus value
    "AO2 输出选项        "	,	//	234 03-20 Analong Output 2
    "AO2 输出增益    %   "	,	//	235 03-21 Analong Output 2 Gain
    "AO2 输出反向使能    "	,	//	236 03-22 AO2 in minus value
    "AUI1模拟输?肽?式    "	,	//	237 03-23 AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2模拟输?肽?式    "	,	//	238 03-24 AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1输?肷瓒?        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
    //"AUI2输?肷瓒?        "	,	//	238  03-26    AUI2 Communciate

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "第零段速        Hz  "	,	//	239 04-00 Multi-Speed 0
    "第一段速        Hz  "	,	//	240 04-01 Multi-Speed 1
    "第二段速        Hz  "	,	//	241 04-02 Multi-Speed 2
    "第??段速        Hz  "	,	//	242 04-03 Multi-Speed 3
    "第四段速        Hz  "	,	//	243 04-04 Multi-Speed 4
    "第五段速        Hz  "	,	//	244 04-05 Multi-Speed 5
    "第六段速        Hz  "	,	//	245 04-06 Multi-Speed 6
    "第?叨嗡?        Hz  "	,	//	246 04-07 Multi-Speed 7
    "第八段速        Hz  "	,	//	247 04-08 Multi-Speed 8
    "第九段速        Hz  "	,	//	248 04-09 Multi-Speed 9
    "第十段速        Hz  "	,	//	249 04-10 Multi-Speed 10 
    "第十一段速      Hz  "	,	//	250 04-11 Multi-Speed 11
    "第十二段速      Hz  "	,	//	251 04-12 Multi-Speed 12
    "第十??段速      Hz  "	,	//	252 04-13 Multi-Speed 13
    "第十四段速      Hz  "	,	//	253 04-14 Multi-Speed 14
    "第十五段速      Hz  "	,	//	254 04-15 Multi-Speed 15
    
    "救援速度        m/s "  ,   //    2xx 04-16
    "?讲闼俣?        m/s "  ,   //    2xx 04-17
    "反基站速度      m/s "  ,   //    2xx 04-18
    "钢索打滑补偿    mm  "  ,   //    2xx 04-19 GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //    2xx 04-20
    "TABST2 Status       "  ,   //    2xx 04-21
    "最高物理楼层        "  ,   //    2xx 04-22
    "目?奥ゲ?            "  ,   //    2xx 04-23
    "脉冲校正条件    %   "  ,   //    2xx 04-24
    "开关延迟补偿    sec "  ,   //    2xx 04-25
    "等速?哂嗍奔?    ms  "  ,   //    2xx 04-26
    "着床板长度      mm  "  ,   //    2xx 04-27 
    "目?拔恢? 高     m   "  ,   //    2xx 04-28
    "目?拔恢? 低     mm  "  ,   //    2xx 04-29
    "目?奥龀? H          "  ,   //    2xx 04-30 
    "目?奥龀? L          "  ,   //    2xx 04-31
    "着床板脉冲 H        "  ,   //    2xx 04-32
    "着床板脉冲 L        "  ,   //    2xx 04-33
    "光电间距脉冲H       "  ,   //    2xx 04-34
    "光电间距脉冲L       "  ,   //    2xx 04-35
    "DLC功能集           "  ,   //    2xx 04-36
    "PDO显示型态         "  ,   //    2xx 04-37
    "减速开关?菪砦蟛頼m  "  ,   //    2xx 04-38
    "最大梯速百分比  %   "  ,   //    2xx 04-39 //[ADCO EPS Modify]
    "弹簧延伸补偿    mm  "  ,   //    2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //    2xx 04-41
    "EST Count           "  ,   //    2xx 04-42
    "TABST0 Count        "  ,   //    2xx 04-43
    "TABST1 Count        "  ,   //    2xx 04-44
    "DDS1/UDS1速限   m/s "  ,   //    2XX 04-45  DD1_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS2/UDS2速限   m/s "  ,   //    2XX 04-46  DD2_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS3/UDS3速限   m/s "  ,   //    2XX 04-47  DD3_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS4/UDS4速限   m/s "  ,   //    2XX 04-48  DD4_Vlim  //Artemis speed limit, James, 20200220
    "功能页面设定        "  ,   //    2XX 04-49  user page cahnge
    
    "1 楼位置 高     m   "  , //  2XX 04-50   1Floor Position H 
    "1 楼位置 低     mm  "  , //  2XX 04-51   1Floor Position L                                       
    "2 楼位置 高     m   "  , //  2XX 04-52   2Floor Position H                                       
    "2 楼位置 低     mm  "  , //  2XX 04-53   2Floor Position L                                       
    "3 楼位置 高     m   "  , //  2XX 04-54   3Floor Position H                                       
    "3 楼位置 低     mm  "  , //  2XX 04-55   3Floor Position L                                       
    "4 楼位置 高     m   "  , //  2XX 04-56   4Floor Position H                                       
    "4 楼位置 低     mm  "  , //  2XX 04-57   4Floor Position L                                       
    "5 楼位置 高     m   "  , //  2XX 04-58   5Floor Position H                                       
    "5 楼位置 低     mm  "  , //  2XX 04-59   5Floor Position L                                       
    "6 楼位置 高     m   "  , //  2XX 04-60   6Floor Position H                                       
    "6 楼位置 低     mm  "  , //  2XX 04-61   6Floor Position L                                       
    "7 楼位置 高     m   "  , //  2XX 04-62   7Floor Position H                                       
    "7 楼位置 低     mm  "  , //  2XX 04-63   7Floor Position L                                       
    "8 楼位置 高     m   "  , //  2XX 04-64   8Floor Position H                                       
    "8 楼位置 低     mm  "  , //  2XX 04-65   8Floor Position L                                       
    "9 楼位置 高     m   "  , //  2XX 04-66   9Floor Position H                                       
    "9 楼位置 低     mm  "  , //  2XX 04-67   9Floor Position L                                       
    "10楼位置 高     m   "  , //  2XX 04-68   10Floor Position H                                      
    "10楼位置 低     mm  "  , //  2XX 04-69   10Floor Position L                                      
    "11楼位置 高     m   "  , //  2XX 04-70   11Floor Position H                                      
    "11楼位置 低     mm  "  , //  2XX 04-71   11Floor Position L                                      
    "12楼位置 高     m   "  , //  2XX 04-72   12Floor Position H                                      
    "12楼位置 低     mm  "  , //  2XX 04-73   12Floor Position L                                      
    "13楼位置 高     m   "  , //  2XX 04-74   13Floor Position H                                      
    "13楼位置 低     mm  "  , //  2XX 04-75   13Floor Position L                                      
    "14楼位置 高     m   "  , //  2XX 04-76   14Floor Position H                                      
    "14楼位置 低     mm  "  , //  2XX 04-77   14Floor Position L                                      
    "15楼位置 高     m   "  , //  2XX 04-78   15Floor Position H                                      
    "15楼位置 低     mm  "  , //  2XX 04-79   15Floor Position L                                      
    "16楼位置 高     m   "  , //  2XX 04-80   16Floor Position H                                      
    "16楼位置 低     mm  "  , //  2XX 04-81   16Floor Position L                                      
    "17楼位置 高     m   "  , //  2XX 04-82   17Floor Position H                                      
    "17楼位置 低     mm  "  , //  2XX 04-83   17Floor Position L                                      
    "18楼位置 高     m   "  , //  2XX 04-84   18Floor Position H                                      
    "18楼位置 低     mm  "  , //  2XX 04-85   18Floor Position L                                      
    "19楼位置 高     m   "  , //  2XX 04-86   19Floor Position H                                      
    "19楼位置 低     mm  "  , //  2XX 04-87   19Floor Position L                                      
    "20楼位置 高     m   "  , //  2XX 04-88   20Floor Position H                                      
    "20楼位置 低     mm  "  , //  2XX 04-89   20Floor Position L                                      
    "21楼位置 高     m   "  , //  2XX 04-90   21Floor Position H                                      
    "21楼位置 低     mm  "  , //  2XX 04-91   21Floor Position L                                      
    "22楼位置 高     m   "  , //  2XX 04-92   22Floor Position H                                      
    "22楼位置 低     mm  "  , //  2XX 04-93   22Floor Position L                                      
    "23楼位置 高     m   "  , //  2XX 04-94   23Floor Position H                                      
    "23楼位置 低     mm  "  , //  2XX 04-95   23Floor Position L                                      
    "24楼位置 高     m   "  , //  2XX 04-96   24Floor Position H                                      
    "24楼位置 低     mm  "  , //  2XX 04-97   24Floor Position L                                      
    "25楼位置 高     m   "  , //  2XX 04-98   25Floor Position H                                      
    "25楼位置 低     mm  "  , //  2XX 04-99   25Floor Position L                                      
        
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM参数自学习        "	,	//	255 05-00 Motor Auto-Tuning
    "IM电机额定电流  Amps"	,	//	256 05-01 Motor 1 rated Current           
    "IM电机额定功率  Kw  "	,	//	257 05-02 Motor 1 Rated Power             
    "IM电机额定转速  RPM "	,	//	258 05-03 Motor 1 Rated RPM               
    "IM电机极数          "	,	//	259 05-04 Motor 1 pole No.                
    "IM电机五载电流  Amps"	,	//	260 05-05 Motor 1 No-Load Current         
    "IM电机参数 Rs   ohm "	,	//	261 05-06 Motor 1 Rs                      
    "IM电机参数 Rr   ohm "	,	//	262 05-07 Motor 1 Rr                      
    "IM电机参数 Lm   mH  "	,	//	263 05-08 Motor 1 Lm                      
    "IM电机参数 Lx   mH  "	,	//	264 05-09 Motor 1 Lx                      
    "转矩补偿低通滤波sec "	,	//	265 05-10 Vector Voltage Filter	        
    "滑差补偿低通滤波sec "	,	//	266 05-11 Vector Slip Filter	            
    "电动转矩补偿增益    "	,	//	267 05-12 Torque Compensation Gain	    
    "滑差补偿增益        "	,	//	268 05-13 Slip Compensation Gain	        
    "滑差误差准位    %   "	,	//	269 05-14 Slip Deviation level	        
    "滑差误差检出时间sec "	,	//	270 05-15 Slip Deviation Detect Time	    
    "过滑差检出选择      "	,	//	271 05-16 Over Slip treatment	            
    "震荡补偿因子        "	,	//	272 05-17 Coeff for hunting disable	    
    "累计电机运转时间Mins"	,	//	273 05-18 Accumulative Motor Operation Min
    "累计电机运转    Days"	,	//	274 05-19 Accumulative Motor Operation Day
    "铁芯损失补偿    %   "	,	//	275 05-20 Coreloss % of output Power	    
    "变?灯魃系缡奔?  Mins"	,	//	276 05-21 Power On Min
    "变?灯魃系缣焓?  Days"	,	//	277 05-22 Power On Day    
    "回生滑差补偿增益%   "  ,   //  2XX 05-23 Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"电动滑差补偿增益%   "	,	//	2XX 05-24 RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "低电压准位      V   "	,	//  278  06-00 Low voltage level
    "?废啾；?            "	,	//  279  06-01 Phase loss
    "加速过电流失速  %   "	,	//	280  06-02 OC stall during Accel
    "定速过电流失速  %   "	,	//	281  06-03 OC stall during Decel
    "过电流失速处理      "	,	//	282  06-04 Stall preventation Accel/Decel time selection
    "过转矩OT1处理       "	,	//	283  06-05 Over-Torque 1 Selection
    "过转矩OT1准位   %   "	,	//	284  06-06 Over-Torque 1 level
    "过转矩OT1检出   sec "	,	//	285  06-07 Over-Torque 1 Time
    "过转矩OT2处理       "	,	//	286  06-08 Over-Torque 2 Selection	                     
    "过转矩OT2准位   %   "	,	//	287  06-09 Over-Torque 2 level	                         
    "过转矩OT2检出   sec "	,	//	288  06-10 Over-Torque 2 Time	                         
    "电流限制        %   "	,	//	289  06-11 Current Limit
    "电子??电驿选择      "	,	//	290  06-12 Thermal Relay 1 Selection
    "??电驿作用时间  sec "	,	//	291  06-13 Thermal Relay 1 Time
    "过??警告温度准位C   "	,	//	292  06-14 OH Warning Level
    "失速防止限制准位%   "	,	//	293  06-15 Stall preventation Limit Level
    "最近一次故障记录    "	,	//	294  06-16 1st Fault Record
    "2次?暗墓收霞?录     "	,	//	295  06-17 2nd Fault Record
    "3次?暗墓收霞?录     "	,	//	296  06-18 3rd Fault Record
    "4次?暗墓收霞?录     "	,	//	297  06-19 4th Fault Record
    "5次?暗墓收霞?录     "	,	//	298  06-20 5th Fault Record
    "6次?暗墓收霞?录     "	,	//	299  06-21 6th Fault Record
    "异常输出选择 1      "	,	//	300  06-22 Fault Option 1
    "异常输出选择2       "	,	//	301  06-23 Fault Option 2
    "异常输出选择3       "	,	//	302  06-24 Fault Option 3
    "异常输出选择4       "	,	//	303  06-25 Fault Option 4
    "PTC动作选择         "	,	//	304  06-26 PTC over Treatments	                         
    "PTC准位         %   "	,	//	305  06-27 PTC Level
    "PTC检出时间     sec "	,	//	306  06-28 PTC Detect Filter time
    "紧急运行电源电压V   "	,	//	307  06-29 EPS voltage level
    "错误输出选择        "	,	//	308  06-30 Fault Option Mode
    "ED 输出?废嗾觳?     "	,	//	309  06-31 Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "?耙淮我斐?运转  Mins"	,	//	310  06-32 1st Fault Time(MIN)
    "?耙淮我斐?运转  Days"	,	//	311  06-33 1st Fault Time(DAY)
    "2次?耙斐?运转   Mins"	,	//	312  06-34 2nd Fault Time(MIN)
    "2次?耙斐?运转   Days"	,	//	313  06-35 2nd Fault Time(DAY)
    "3次?耙斐?运转   Mins"	,	//	314  06-36 3rd Fault Time(MIN)
    "3次?耙斐?运转   Days"	,	//	315  06-37 3rd Fault Time(DAY)
    "4次?耙斐?运转   Mins"	,	//	316  06-38 4th Fault Time(MIN)
    "4次?耙斐?运转   Days"	,	//	317  06-39 4th Fault Time(DAY)
    "5次?耙斐?运转   Mins"	,	//	318  06-40 5th Fault Time(MIN)
    "5次?耙斐?运转   Days"	,	//	319  06-41 5th Fault Time(DAY)
    "6次?耙斐?运转   Mins"	,	//	320  06-42 6th Fault Time(MIN)
    "6次?耙斐?运转   Days"	,	//	321  06-43 6th Fault Time(DAY)
    "紧急电源运行速度Hz  "  ,   //  322  06-44 EPS Frequency
    "错误动作选择        "  ,	//  323  06-45 LV Option Mode
    "EPS 模式选择        "  ,	//  324  06-46 EPS Option Mode
    "发点方向搜索时间sec "  ,   //  325  06-47 Generation Operation Detected Time
    "紧急运行电源?萘縆VA "  ,   //  326  06-48 UPS Capacity (0.1KVA)
    "STO功能选择         "  ,   //  3xx  06-49 STO Lock selection     //[Safty function, Bernie]   
    "故障重试时MO动作    "  ,   //  356  06-50 Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "故障重试次数        "  ,   //  356  06-51 Auto restart times after fault     
    "故障重试时间    sec "  ,   //  356  06-52 Auto restart interval
    "异常时?德拭?令  Hz  "  ,   //  3xx  06-53 Fkey Record
    "异常时?德适涑?  Hz  "  ,   //  3xx  06-54 Fcmd Record
    "异常时输出电流  Amps"  ,   //  3xx  06-55 Isum Record
    "异常时马达?德?  Hz  "  ,   //  3xx  06-56 Fout Record
    "异常时输出电压  V   "  ,   //  3xx  06-57 Vout Record
    "异常时DCBus电压 V   "  ,   //  3xx  06-58 Dcbus Record    
    "异常时输出功率  KW  "  ,   //  3xx  06-59 Power Record
    "异常时输出转矩  %   "  ,   //  3xx  06-60 Torque Record
    "异常时IGBT温度  C   "  ,   //  3xx  06-61 IGBT Temperature Record   
    "异常时输?攵俗?  Hex "  ,   //  3xx  06-62 MFI State Record
    "异常时输出端子  Hex "  ,   //  3xx  06-63 MFO State Record
    "异常时??动?髯刺琀ex "  ,   //  3xx  06-64 Drive State Record
    "UCMP电流限制准位%   "  ,   //  3XX  06-65 Current limitation for UCMP function            //[UCMP function, Bernie, 2016/06/14]
    "飨动噪服务次数      "  ,   //  3xx  06-66 Service time count                              //[Service time function, Bernie, 2017/03/14]
    "飨动噪服务设定      "  ,   //  3xx  06-67 Service time function Enable                    //[Service time function, Bernie, 2017/03/14]
    "EPS侦测功因准位 deg "  ,   //  3xx  06-68 EPS Detect Current    
    "EPS功因角       deg "  ,   //  3xx  06-69 EPS Detect Current Ref
    "EPS方向辑出         "  ,   //  3xx  06-70 EPS Detect direction
    "EPS端子辑出延选 sec "  ,   //  3xx  06-71 EPS MO Off Time
    "EPS端子闭合延选 sec "  ,   //  3xx  06-72 EPS MO Off Time
    "永久运行方向计数H   "	,   //	3xx  06-73 Running direction count high						
    "永久运行方向计数L   "	,   //	3xx  06-74 Running direction count low
    "单次运行方向计数H   "	,   //	3xx  06-75 Temp running direction count high
    "单次运行方向计数L   "	,   //  3xx  06-76 Temp running direction count low
    "单次运行重置次数    "	,   //	3xx  06-77 Temp running reset count
    "运行方向限制次数k   "	,   //	3xx  06-78 Running life
    "运行次数功能选项    "	,   //	3xx  06-79 Running function
    "异常2时?德适涑?  Hz  " ,   //  3xx  06-80 Fcmd Record1
    "异常2时DCBus电压 V   " ,   //  3xx  06-81 Dcbus Record1
    "异常2时输出电流  Amps" ,   //  3xx  06-82 Isum Record1
    "异常2时IGBT温度  C   "	,   //  3xx  06-83 IGBT Temperature Record1
    "异常3时?德适涑?  Hz  " ,   //  3xx  06-84 Fcmd Record2
    "异常3时DCBus电压 V   " ,   //  3xx  06-85 Dcbus Record2
    "异常3时输出电流  Amps" ,   //  3xx  06-86 Isum Record2
    "异常3时IGBT温度  C   " ,   //  3xx  06-87 IGBT Temperature Record2
    "异常4时?德适涑?  Hz  " ,   //  3xx  06-88 Fcmd Record3
    "异常4时DCBus电压 V   " ,   //  3xx  06-89 Dcbus Record3
    "异常4时输出电流  Amps" ,   //  3xx  06-90 Isum Record3
    "异常4时IGBT温度  C   " ,   //  3xx  06-91 IGBT Temperature Record3
    "异常5时?德适涑?  Hz  " ,   //  3xx  06-92 Fcmd Record4
    "异常5时DCBus电压 V   " ,   //  3xx  06-93 Dcbus Record4
    "异常5时输出电流  Amps" ,   //  3xx  06-94 Isum Record4
    "异常5时IGBT温度  C   " ,   //  3xx  06-95 IGBT Temperature Record4
    "异常6时?德适涑?  Hz  " ,   //  3xx  06-96 Fcmd Record5
    "异常6时DCBus电压 V   " ,   //  3xx  06-97 Dcbus Record5
    "异常6时输出电流  Amps" ,   //  3xx  06-98 Isum Record5
    "异常6时IGBT温度  C   " ,   //  3xx  06-99 IGBT Temperature Record5
/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "刹车晶体放电准位V   "	,	//	327   07-00 SW Braking Level
    "煞车晶体迟滞电压V   "  ,   //	328   07-01 DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "?舳绷髦?动准位%   "	,	//	329   07-02 DCI Current Level    //[DCI Level when stop, Bernie, 05/21/2012]
    "?舳绷髦?动时间sec "	,	//	330   07-03 DCI Time at Start 
    "停车直流制动时间sec "	,	//	331   07-04 DCI Time at STOP
    "停车制动?鹗计德蔋z  "	,	//	332   07-05 DCI Freq. At start
    "直流制动I增益       "	,	//	333   07-06 DCI KI
    "齿系加速中断时间sec "	,	//	334   07-07 Gear wait time when acceleration
    "齿系加速中断?德蔋z  "	,	//	335   07-08 Gear wait frequency when acceleration
    "齿系减速中断时间sec "	,	//	336   07-09 Gear wait time when deceleration
    "齿系减速中断?德蔋z  "	,	//	337   07-10 Gear wait frequency when deceleration
    "风扇控制方式        "	,	//	338   07-11 Fan Control
    "转矩命令        %   "	,	//	339   07-12 TQC Reference from RS485
    "转矩命令来源        "	,	//	340   07-13 Source of Torque Command
    "最大转矩命令    %   "	,	//	341   07-14 Torque max. level
    "转矩命令滤波时间sec "	,	//	342   07-15 Torque command filter
    "速度限制选择        "	,	//	343   07-16 Speed Limit selection
    "转矩模式+SPD限制%   "	,	//	344   07-17 Torque mode positive speed limit
    "转矩模式-SPD限制%   "	,	//	345   07-18 Torque mode negative speed limit
    "转矩命令?估丛?    "	,	//	346   07-19 Torque offset selection
    "转矩命令?股瓒?%   "	,	//	347   07-20 Torque offset setting level
    "高转矩??      %   "	,	//	348   07-21 Torque offset setting level High
    "中转矩??      %   "	,	//	349   07-22 Torque offset setting level Middle
    "低转矩??      %   "	,	//	350   07-23 Torque offset setting level Low
    "正转电动转矩限制%   "	,	//	351   07-24 FWD Motoring Tq Limit
    "反转回生转矩限制%   "	,	//	352   07-25 FWD Regeneration Tq Limit
    "正转电动转矩限制%   "	,	//	353   07-26 REV Motoring Tq Limit
    "反转回生转矩限制%   "	,	//	354   07-27 REV Regeneration Tq Limit
    "?恐?停机检出方式    "	,	//	355   07-28 Emergency Stop & Forced Stop selection
    "停车转矩减速时间sec "	,	//	356   07-29 Torque Decrease Time
    "停止直流制动准位%   "  ,   //  356   07-30 STOP DC Inject Level       //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  357   07-31  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 检测           "  ,   //  358   07-32  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 检测距离    ppr"  ,   //  359   07-33  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 检测秒数       "  ,   //  360   07-34  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 检测失败转矩   "  ,   //  361   07-35  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 检测最小转矩   "  ,   //  362   07-36  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx 检测最大转矩   "  ,   //  362   07-37  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM参数自学习        "	,	//	357   08-00 PMotor Auto-Tuning  
    "PM电机额定电流  Amps"	,	//	358   08-01 PMotor rated Current
    "PM电机额定功率  Kw  "	,	//	359   08-02 PMotor Rated Power  
    "PM电机额定转速  RPM "	,	//	360   08-03 PMotor Rated RPM    
    "PM电机极数          "	,	//	361   08-04 PMotor pole No.     
    "PM电机参数 Rs   ohm "	,	//	362   08-05 PMotor Rs           
    "PM电机参数 Ld   mH  "	,	//	363   08-06 PMotor Ld           
    "PM电机参数 Lq   mH  "	,	//	364   08-07 PMotor Lq           
    "电机反电动势    Vrms"	,	//	365   08-08 PMotor Bemf coff	
    "磁极??角      deg "	,	//	366   08-09 PM Z-pulse offset angle, 0.1 degree, dino
    "磁极重新定位        "	,	//	367   08-10 //ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "通讯地址            "	,	//	368   09-06 Comm Address                              
    "通讯传输速度    kbps"	,	//	369   09-07 Tranmission speed                         
    "通讯错误处理        "	,	//	370   09-08 Comm fault Treatment                      
    "逾时检出时间    sec "	,	//	371   09-09 Comm Time out                             
    "通讯格式            "	,	//	372   09-10 Comm Protocol                             
    "响应延时时间    ms  "	,	//	373   09-11 ASC remote Response Delay Time, 1=100us   
    "CAN 通讯包率        "	,   //  3XX   09-06 CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "CAN PDO交握时间 ms  "	,   //  3XX   09-07 CAN PDO Handshaking Period
    "CAN PDO通讯逾时 ms  "	,   //  3XX   09-08 CAN Communiction Timeout	
    "上位机识别码        "  ,   //  3XX   09-09 
    "FHM 暂存??          "  ,   //  3XX   09-10   
    "DLC 暂存??1         "  ,   //  3XX   09-11   
    "DLC 暂存??2         "  ,   //  3XX   09-12    
    "DLC 暂存??3         "  ,   //  3XX   09-13   
	"PDO传送间隔     ms  "	,	//	3XX   09-14 CAN fail rate---aevin 6/12/2017

/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"编码?髦掷嘌≡?      "	,	//	374   10-00 Encoder TYPE                             
	"编码?髀龀宓闶?  ppr "	,	//	375   10-01 Encoder pulses	                    
	"编码?魇淙胄问?      "	,	//	376   10-02 PG input setting	                
	"PG错误动作选择      "	,	//	377   10-03 PG fbk fault treatment	            
	"PG错误检出时间  sec "	,	//	378   10-04 PG fbk Error Detection Time	        
	"PG失速准位      %   "	,	//	379   10-05 PG fbk overspeed detection level	
	"PF失速检出时间  sec "	,	//	380   10-06 Over speed Detection Time	        
	"PG转差异常准位  %   "	,	//	381   10-07 PG fbk speed deviation level	    
	"PG转差检出时间  sec "	,	//	382   10-08 Deviation Detect Time	            
	"PG失速动作选择      "	,	//	383   10-09 Operation at overspeed	            
	"HALL信号模式选择    "  ,   //  384   10-10 Hall Input Types
	"?舳闼僭鲆鍼       "	,	//	385   10-11 KP gain of ASR in Zero speed	
	"?舳闼倩?分I   sec "	,	//	386   10-12 Ki gain of ASR in Zero speed	
	"低速增益P           "	,	//	387   10-13 ASR P Gain 1	                
	"低速积分时间I   sec "	,	//	388   10-14 ASR I Gain 1	                
	"高速增益P           "	,	//	389   10-15 ASR P Gain 2	                
	"高速积分时间I   sec "	,	//	390   10-16 ASR I Gain 2	                
	"低/高速?谢黄德? Hz  "	,	//	391   10-17 ASR1/ASR2 switch freq	        
	"ASR低通滤波增益 sec "	,	//	392   10-18 Primary LowPass filter Gain 
	"位置控制ASR增益 P   "  ,	//	393   10-19 position control Kp Gain  
    "零/低速带宽调整 Hz  "  ,   //  394   10-20 Low Spd band
    "低/高速带宽调整 Hz  "  ,   //  395   10-21 High Spd band
	"位置控制ASR积分Isec "	,	//	396   10-22 Position control time
	"?舳恢每刂?低通sec "	,	//	397   10-23 Position control LOW POSS FILTER
	"位置控制模式选择    "	,	//	398   10-24 Source of position control, add by dino, 
	"?讲懔闼僭鲆鍼   %   "	,	//	399   10-25 KP gain of ASR in Zero speed of 
	"?讲懔闼倩?分I   sec "	,	//	400   10-26 Ki gain of ASR in Zero speed of Landing
	"位置控制零速增益%   "	,	//	385   10-27 KP gain of ASR in Zero speed during 
	"位置控制零速积分sec "	,	//	386   10-28 Ki gain of ASR in Zero speed during 
    "PG卡除?凳涑鲋?      "	,   //  4xx   10-29 PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG卡除?凳涑鲂褪?    "	,   //  4xx   10-30 PG Card Mode setting                      //[DCI Level when stop, Bernie, 05/21/2012]    
    "PG C+/C-选择        "  ,   //  110   10-31 RESERVED     //[change parameter to normal group, Bernie, 2014/02/14]
    "电梯过加速度准位m/s2"  ,   //  3XX   10-32 Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "过加速度侦测时间sec "  ,   //  3XX   10-33 Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "过加速度侦测选择    "  ,   //  3XX   10-34 Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    "ACC LPF             "  ,   //  422 10-35   //Rationa 362631, Special.Kung
    "ACC SampleRate    ms"  ,   //  422 10-36   //Rationa 362631, Special.Kung
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "系统控制        Hex "	,	//	401   11-00 system control bit0:auto, bit1:Jm tunning, 
    "最大?德识杂μ菟賛/s "  ,   //  402   11-01 Lift operation speed                                        
    "曳引轮直径      mm  "  ,   //  403   11-02 SHEAVE diameter		                
    "齿轮比              "  ,   //  404   11-03 Gear Ratio                                              
    "悬挂比              "  ,   //  405   11-04 Suspension ratio	                                        
    "机械惯量百分比  %   "  ,   //  406   11-05 inertia	percent		                  
    "?舳闼俅?    Hz  "	,	//	407   11-06 Zero Speed Loop BandWidth	                                
    "低速带宽        Hz  "	,	//	408   11-07 Speed Loop BandWidth1		                                
    "高速带宽        Hz  "	,	//	409   11-08 Speed Loop BandWidth2		                                
    "PDFF增益值      %   "	,	//	410   11-09 PDFFKr		                                                
    "速度控制?袄≡鲆?%   "	,	//	411   11-10 SPEED FFD GAIN		                    
    "凹陷滤波深度    db  "	,	//	412   11-11 Netch filter deep(db)	                                    
    "凹陷滤波?德?    Hz  "	,	//	413   11-12 Netch filter frequency	                                    
    "面板显示滤波时间sec "	,	//	414   11-13 Low Pass Filter for display	                                
    "加速时最大电流  %   "	,	//	415   11-14 ACC Max current                                             
    "电梯最大加速度  m/s2"  ,	//	416   11-15 max meter/sec	                                            
    "监控数据位置    Hex "  ,   //	417   11-16 Display address,add by dino 2007/03/08                      
    "监控资料            "  ,	//	418   11-17 Display data,   add by dino 2007/03/08                      
    "保留                "  ,   //  419   11-18 Protect Bit	                                                
    "停车零速带宽    Hz  "	,	//	420   11-19 Zero Speed Loop BandWidth of Landing  
    "PWM 模式模式        "  ,   //  4XX   11-20 PWM Mode selection  PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LC01显示滤波时间 sec"	,	//	422   11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	420   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "自定参数1           "  ,   //  421   12-00
    "自定参数2           "  ,   //  422   12-01
    "自定参数3           "  ,   //  423   12-02
    "自定参数4           "  ,   //  424   12-33
    "自定参数5           "  ,   //  425   12-04
    "自定参数6           "  ,   //  426   12-05
    "自定参数7           "  ,   //  427   12-06
    "自定参数8           "  ,   //  428   12-07
    "自定参数9           "  ,   //  429   12-08
    "自定参数10          "  ,   //  430   12-09
    "自定参数11          "  ,   //  431   12-10
    "自定参数12          "  ,   //  432   12-11
    "自定参数13          "  ,   //  433   12-12
    "自定参数14          "  ,   //  434   12-13
    "自定参数15          "  ,   //  435   12-14
    "自定参数16          "  ,   //  436   12-15
    "自定参数17          "  ,   //  437   12-16
    "自定参数18          "  ,   //  438   12-17
    "自定参数19          "  ,   //  439   12-18
    "自定参数20          "  ,   //  440   12-19
    "自定参数21          "  ,   //  441   12-20
    "自定参数22          "  ,   //  442   12-21
    "自定参数23          "  ,   //  443   12-22
    "自定参数24          "  ,   //  444   12-23
    "自定参数25          "  ,   //  445   12-24
    "自定参数26          "  ,   //  446   12-25
    "自定参数27          "  ,   //  447   12-26
    "自定参数28          "  ,   //  448   12-27
    "自定参数29          "  ,   //  449   12-28
    "自定参数30          "  ,   //  450   12-29
    "自定参数31          "  ,   //  451   12-30
    "自定参数32          "  ,   //  452   12-31
    "自定参数33          "  ,   //  433   12-12
    "自定参数34          "  ,   //  434   12-13
    "自定参数35          "  ,   //  435   12-14
    "自定参数36          "  ,   //  436   12-15
    "自定参数37          "  ,   //  437   12-16
    "自定参数38          "  ,   //  438   12-17
    "自定参数39          "  ,   //  439   12-18
    "自定参数40          "  ,   //  430   12-09
    "自定参数41          "  ,   //  431   12-10
    "自定参数42          "  ,   //  432   12-11
    "自定参数43          "  ,   //  433   12-12
    "自定参数44          "  ,   //  434   12-13
    "自定参数45          "  ,   //  435   12-14
    "自定参数46          "  ,   //  436   12-15
    "自定参数47          "  ,   //  437   12-16
    "自定参数48          "  ,   //  438   12-17
    "自定参数49          "  ,   //  439   12-18
    "自定参数50          "  ,   //  430   12-09
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
    "自定常用参数1       "  ,   //  453   13-00
    "自定常用参数2       "  ,   //  454   13-01
    "自定常用参数3       "  ,   //  455   13-02
    "自定常用参数4       "  ,   //  456   13-33
    "自定常用参数5       "  ,   //  457   13-04
    "自定常用参数6       "  ,   //  458   13-05
    "自定常用参数7       "  ,   //  459   13-06
    "自定常用参数8       "  ,   //  460   13-07
    "自定常用参数9       "  ,   //  461   13-08
    "自定常用参数10      "  ,   //  462   13-09
    "自定常用参数11      "  ,   //  463   13-10
    "自定常用参数12      "  ,   //  464   13-11
    "自定常用参数13      "  ,   //  465   13-12
    "自定常用参数14      "  ,   //  466   13-13
    "自定常用参数15      "  ,   //  467   13-14
    "自定常用参数16      "  ,   //  468   13-15
    "自定常用参数17      "  ,   //  469   13-16
    "自定常用参数18      "  ,   //  470   13-17
    "自定常用参数19      "  ,   //  471   13-18
    "自定常用参数20      "  ,   //  472   13-19
    "自定常用参数21      "  ,   //  473   13-20
    "自定常用参数22      "  ,   //  474   13-21
    "自定常用参数23      "  ,   //  475   13-22
    "自定常用参数24      "  ,   //  476   13-23
    "自定常用参数25      "  ,   //  477   13-24
    "自定常用参数26      "  ,   //  478   13-25
    "自定常用参数27      "  ,   //  479   13-26
    "自定常用参数28      "  ,   //  480   13-27
    "自定常用参数29      "  ,   //  481   13-28
    "自定常用参数30      "  ,   //  482   13-29
    "自定常用参数31      "  ,   //  483   13-30
    "自定常用参数32      "  ,   //  484   13-31
    "自定常用参数33      "  ,   //  465   13-12
    "自定常用参数34      "  ,   //  466   13-13
    "自定常用参数35      "  ,   //  467   13-14
    "自定常用参数36      "  ,   //  468   13-15
    "自定常用参数37      "  ,   //  469   13-16
    "自定常用参数38      "  ,   //  470   13-17
    "自定常用参数39      "  ,   //  471   13-18
    "自定常用参数40      "  ,   //  462   13-09
    "自定常用参数41      "  ,   //  463   13-10
    "自定常用参数42      "  ,   //  464   13-11
    "自定常用参数43      "  ,   //  465   13-12
    "自定常用参数44      "  ,   //  466   13-13
    "自定常用参数45      "  ,   //  467   13-14
    "自定常用参数46      "  ,   //  468   13-15
    "自定常用参数47      "  ,   //  469   13-16
    "自定常用参数48      "  ,   //  470   13-17
    "自定常用参数49      "  ,   //  471   13-18
    "自定常用参数50      "  ,   //  462   13-09
    "自定常用参数51      "  ,   //  463   13-10
    "自定常用参数52      "  ,   //  464   13-11
    "自定常用参数53      "  ,   //  465   13-12
    "自定常用参数54      "  ,   //  466   13-13
    "自定常用参数55      "  ,   //  467   13-14
    "自定常用参数56      "  ,   //  468   13-15
    "自定常用参数57      "  ,   //  469   13-16
    "自定常用参数58      "  ,   //  470   13-17
    "自定常用参数59      "  ,   //  471   13-18
    "自定常用参数60      "  ,   //  462   13-09
    "自定常用参数61      "  ,   //  463   13-10
    "自定常用参数62      "  ,   //  464   13-11
    "自定常用参数63      "  ,   //  465   13-12
    "自定常用参数64      "  ,   //  466   13-13
    "自定常用参数65      "  ,   //  467   13-14
    "自定常用参数66      "  ,   //  468   13-15
    "自定常用参数67      "  ,   //  469   13-16
    "自定常用参数68      "  ,   //  470   13-17
    "自定常用参数69      "  ,   //  471   13-18
    "自定常用参数70      "  ,   //  462   13-09
    "自定常用参数71      "  ,   //  463   13-10
    "自定常用参数72      "  ,   //  464   13-11
    "自定常用参数73      "  ,   //  465   13-12
    "自定常用参数74      "  ,   //  466   13-13
    "自定常用参数75      "  ,   //  467   13-14
    "自定常用参数76      "  ,   //  468   13-15
    "自定常用参数77      "  ,   //  469   13-16
    "自定常用参数78      "  ,   //  470   13-17
    "自定常用参数79      "  ,   //  471   13-18
    "自定常用参数80      "  ,   //  462   13-09
    "自定常用参数81      "  ,   //  463   13-10
    "自定常用参数82      "  ,   //  464   13-11
    "自定常用参数83      "  ,   //  465   13-12
    "自定常用参数84      "  ,   //  466   13-13
    "自定常用参数85      "  ,   //  467   13-14
    "自定常用参数86      "  ,   //  468   13-15
    "自定常用参数87      "  ,   //  469   13-16
    "自定常用参数88      "  ,   //  470   13-17
    "自定常用参数89      "  ,   //  471   13-18
    "自定常用参数90      "  ,   //  462   13-09
    "自定常用参数91      "  ,   //  463   13-10
    "自定常用参数92      "  ,   //  464   13-11
    "自定常用参数93      "  ,   //  465   13-12
    "自定常用参数94      "  ,   //  466   13-13
    "自定常用参数95      "  ,   //  467   13-14
    "自定常用参数96      "  ,   //  468   13-15
    "自定常用参数97      "  ,   //  469   13-16
    "自定常用参数98      "  ,   //  470   13-17
    "自定常用参数99      "  ,   //  471   13-18
    "自定常用参数100     "  ,   //  471   13-18
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
    "COM1通讯地址        "  ,   //  368   09-00 Comm Address                //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                       
    "COM1通讯传输速度kbps"  ,   //  369   09-01 Tranmission speed                          
    "COM1通讯错误处理    "  ,   //  370   09-02 Comm fault Treatment                      
    "COM1逾时检出时间sec "  ,   //  371   09-03 Comm Time out                             
    "COM1通讯格式        "  ,   //  372   09-04 Comm Protocol                             
    "COM1响应延时时间ms  "  ,   //  373   09-05 ASC remote Response Delay Time,  
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
    //"AUI1输?肷瓒?        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
    //"AUI2输?肷瓒?        "	,	//	238  03-26    AUI2 Communciate

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
    "ACC LPF             "  ,   //  422 10-35   //Rationa 362631, Special.Kung
    "ACC SampleRate    ms"  ,   //  422 10-36   //Rationa 362631, Special.Kung
    
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
	"侧哲汜谵嗾葚m/s2"	,	//	156	01-12	1st Acceleration time
	"侧哲仔苷咱蛰.1m/s2"	,	//	157	01-13	1st Deceleration time
	"侧哲汜谵嗾葚m/s2"	,	//	158	01-14	2nd Acceleration time
	"侧哲仔苷咱蛰.2m/s2"	,	//	159	01-15	2nd Deceleration time
	"侧哲汜谵嗾葚m/s2"	,	//	160	01-16	3rd Acceleration time
	"侧哲仔苷咱蛰.3m/s2"	,	//	161	01-17	3rd Deceleration time
	"侧哲汜谵嗾葚m/s2"	,	//	162	01-18	4th Acceleration time
	"侧哲仔苷咱蛰.4m/s2"	,	//	163	01-19	4th Deceleration time
	"侧哲汜谵 JOGm/s2"	,	//	164	01-20	JOG Acceleration time
	"侧哲仔苷咱.JOGm/s2"	,	//	165	01-21	JOG Deceleration time
	"侧哲掎庑蒉倚  m/s2"	,	//	175	01-31	Stop Deceleration time
};

const string20 prinfo_rus_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"侧哲汜谵嗾葚f/s2"	,	//	156	01-12	1st Acceleration time
	"侧哲仔苷咱蛰.1f/s2"	,	//	157	01-13	1st Deceleration time
	"侧哲汜谵嗾葚f/s2"	,	//	158	01-14	2nd Acceleration time
	"侧哲仔苷咱蛰.2f/s2"	,	//	159	01-15	2nd Deceleration time
	"侧哲汜谵嗾葚f/s2"	,	//	160	01-16	3rd Acceleration time
	"侧哲仔苷咱蛰.3f/s2"	,	//	161	01-17	3rd Deceleration time
	"侧哲汜谵嗾葚f/s2"	,	//	162	01-18	4th Acceleration time
	"侧哲仔苷咱蛰.4f/s2"	,	//	163	01-19	4th Deceleration time
	"侧哲汜谵 JOGf/s2"	,	//	164	01-20	JOG Acceleration time
	"侧哲仔苷咱.JOGf/s2"	,	//	165	01-21	JOG Deceleration time
	"侧哲掎庑蒉倚  f/s2"
};

const string20 prinfo_rus_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S 卩匾酗 1      m/s3"	,	//	168	01-24	S curve Accel time 1
	"S 卩匾酗 2      m/s3"	,	//	169	01-25	S curve Accel time 2
	"S 卩匾酗 3      m/s3"	,	//	170	01-26	S curve Decel time 1
	"S 卩匾酗 4      m/s3"	,	//	171	01-27	S curve Decel time 2
	"S 卩匾酗 5      m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_rus_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S 卩匾酗 1      f/s3"	,	//	168	01-24	S curve Accel time 1
	"S 卩匾酗 2      f/s3"	,	//	169	01-25	S curve Accel time 2
	"S 卩匾酗 3      f/s3"	,	//	170	01-26	S curve Decel time 1
	"S 卩匾酗 4      f/s3"	,	//	171	01-27	S curve Decel time 2
	"S 卩匾酗 5      f/s3"	,	//	174	01-30	S curve Decel time 3
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
	"冈蛰庳湄谛 恨    "	,	//	128 00-00	Model Type of Drive 
	"睫茇菪垤 廪  Amps"	,	//	129 00-01	Rated Current
	"裂噢咝嘈苷忄抟     "	,	//	130 00-02	Parameter Reset
	"叫 剌载谛尕      "	,	//	131 00-03	Start up Display
	"哭垤邹倚纵戌-    "	,	//	132 00-04	User Display
	"恨礓湄咿垤埏     "	,	//	133	00-05	User Coefficient
	"舱噌仫 烤            "	,	//	134	00-06	Software Version
	"惨拊 咝噢埏          "	,	//	135	00-07	Password Input
	"沸孕葚咝噢埏       "	,	//	136	00-08	Password Input
	"勒重氵嘈役蛰仫     "	,	//	137	00-09	Control Methods
	"翟剌劓. 嶷捺掎庳	  "	,	//	138	00-10	Velocity Unit Select
	"叫哙幸. 侧虚蛰仫     "	,	//	139 00-11   Change Output Direction, Added by sampo , 06/11/2009
	"?嗅廪馊?     KHz "	,	//	140	00-12	Carry Frequency
	"袄                 "	,	//	141	00-13	AVR
	"羔廪巛刳 缧徕掴    "	,	//	142	00-14	Source of Freq. Command
	"羔廪巛刳 谵苄菰      "	,	//	143	00-15	Source of Oper. Command
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"夹卺.译缧徕掴蠬z  "	,	//	144	01-00	Max Output Freq.
	"睫缧徕掴砸.1Hz  "	,	//	145	01-01	Motor Base Frequency 1
	"睫菪哙镏.砸.1 V   "	,	//	146	01-02	Max Output Voltage
	"拎.缧徕掴 砸.1Hz  "	,	//	147	01-03	Mid Output Freq.1
	"拎.菪哙镏.1 砸.1V   "	,	//	148	01-04	Mid Output Voltage 1
	"拎.缧徕掴 砸.1Hz  "	,	//	149	01-05	Mid Output Freq.2
	"拎.菪哙镏.2 砸.1V   "	,	//	150	01-06	Mid Output Voltage 2
	"钾缧徕掴砸.1Hz  "	,	//	151	01-07	Min Output Freq.
	"钾菪哙镏. 砸.1V   "	,	//	152	01-08	Min Output Voltage
	"菱朽 ?嗅廪? Hz  "	,	//	153	01-09	Start Frequency
	"舱噱.余休劓.缧徕Hz  "	,	//	154	01-10	Upper Bound Freq.
	"截州.余休劓.缧徕Hz  "	,	//	155	01-11	Lower Bound Freq.
	"侧哲汜谵嗾葚sec "	,	//	156	01-12	1st Acceleration time
	"侧哲仔苷咱蛰.1sec "	,	//	157	01-13	1st Deceleration time
	"侧哲汜谵嗾葚sec "	,	//	158	01-14	2nd Acceleration time
	"侧哲仔苷咱蛰.2sec "	,	//	159	01-15	2nd Deceleration time
	"侧哲汜谵嗾葚sec "	,	//	160	01-16	3rd Acceleration time
	"侧哲仔苷咱蛰.3sec "	,	//	161	01-17	3rd Deceleration time
	"侧哲汜谵嗾葚sec "	,	//	162	01-18	4th Acceleration time
	"侧哲仔苷咱蛰.4sec "	,	//	163	01-19	4th Deceleration time
	"侧哲汜谵 JOGsec "	,	//	164	01-20	JOG Acceleration time
	"侧哲仔苷咱.JOGsec "	,	//	165	01-21	JOG Deceleration time
	"?嗅廪釰OG     Hz  "	,	//	166	01-22	JOG Frequency
	"空嗾冕沸-4Hz  "	,	//	167	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"S 卩匾酗 1      sec "	,	//	168	01-24	S curve Accel time 1
	"S 卩匾酗 2      sec "	,	//	169	01-25	S curve Accel time 2
	"S 卩匾酗 3      sec "	,	//	170	01-26	S curve Decel time 1
	"S 卩匾酗 4      sec "	,	//	171	01-27	S curve Decel time 2
	"勒0-嶷捺掎庳    "	,	//	172	01-28	Select Zero Speed
	"邻捺.赞怙迂倚葚颒z  "	,	//	173	01-29	Landing Frequency 
	"S 卩匾酗 5      sec "	,	//	174	01-30	S curve Decel time 3
	"侧哲掎庑蒉倚  sec "	,	//	175	01-31	Stop Deceleration time
    "邻捺.央徕.掎庑m/s "	,	//	1xx	01-32
    "侧哲锉捋邻捺.喉鈙ec "	,	//	1xx	01-33   IODHT IO direct hold time   
    "侧哲锎掴镉匾.喉鈙ec "	,	//	1xx	01-34   IODLT IO direct landing freq
    "CRPLS抻嘈嚯亿   "	,	//	1xx	01-35   IODLT IO direct landing time
    "IOD 廪缵仔苷cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "IOD载徕.仔苷  m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "IODLC汹庳         "	,	//	1xx	01-37   IODLT IO direct DistancE
    "草砧.徕捱.缧徕掴Hz  "  ,   //  1xx 01-37   IODLT IO direct DistancE
    "ESD亦哲.仔苷咱. sec "	,	//	1xx	01-37   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105  RESERVED
    "Emergency S3    sec "  ,   //  105 15-105  RESERVED
    "Emergency S4    sec "  ,   //  105 15-105  RESERVED
#endif
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"2/3-哙抟拊.氵   "	,	//	176	02-00	2/3 wire control                
	"簇嶷嗾廨.义拊 1     "	,	//	177	02-01	Multi-Function Input 1          
	"簇嶷嗾廨.义拊 2     "	,	//	178	02-02	Multi-Function Input 2          
	"簇嶷嗾廨.义拊 3     "	,	//	179	02-03	Multi-Function Input 3          
	"簇嶷嗾廨.义拊 4     "	,	//	180	02-04	Multi-Function Input 4          
	"簇嶷嗾廨.义拊 5     "	,	//	181	02-05	Multi-Function Input 5          
	"簇嶷嗾廨.义拊 6     "	,	//	182	02-06	Multi-Function Input 6          
	"簇嶷嗾廨.义拊 7     "	,	//	183	02-07	Multi-Function Input 7          
	"簇嶷嗾廨.义拊 8     "	,	//	184	02-08	Multi-Function Input 8		    
	"沸哉嘀谛 载嶷.义sec "	,	//	185	02-09	Digital in response time		
	"摆庳倚尕义拊抟    "	,	//	186	02-10	Multi-Function Input Inverse	
	"搽遛暂拚 嗾壅 1     "	,	//	187	02-11	Multi-Function Relay 1		    
	"搽遛暂拚 嗾壅 2     "	,	//	188	02-12	Multi-Function Relay 2		    
	"搽遛暂拚 嗾壅 3     "	,	//	189	02-13	Multi-Function Output 1		    
	"搽遛暂拚 嗾壅 4     "	,	//	190	02-14	Multi-Function Output 2		    
	"簇嶷嗾廨.译遛1    "	,	//	191	02-15	Multi-Function Output 1		    
	"簇嶷嗾廨.译遛2    "	,	//	192	02-16	Multi-Function Output 2		    
	"簇嶷嗾廨.译遛3    "	,	//	193	02-17	Multi-Function Output 1		    
	"簇嶷嗾廨.译遛4    "	,	//	194	02-18	Multi-Function Output 2		    
	"簇嶷嗾廨.译遛5    "	,	//	195	02-19	Multi-Function Output 1		    
	"簇嶷嗾廨.译遛6    "	,	//	196	02-20	Multi-Function Output 2		    
	"簇嶷嗾廨.译遛7    "	,	//	197	02-21	Multi-Function Output 1		    
	"簇嶷嗾廨.译遛8    "	,	//	198	02-22	Multi-Function Output 2		    
	"摆庳倚 译遛赞   "	,	//	199	02-23	Multi-Function Output inverse	
    "菱朽咿巅赵-徕   "  ,   //  200 02-24   Sequence start mode
	"恨葩噢缧徕掴Hz  "	,	//	201	02-25	Desired Frequency 1		        
	"?剜剌? 缧徕掴 Hz  "	,	//	202	02-26	Band of Desired Frequency 1		
	"恨葩噢缧徕掴Hz  "	,	//	203	02-27	Desired Frequency 2		        
	"?剜剌? 缧徕掴 Hz  "	,	//	204	02-28	Band of Desired Frequency 2		
	"沸哉嗬嗅廪嗦捺sec "	,	//	205	02-29	Brake Delay Timer at run
	"沸哉嘟雄拗罗嘬. sec "	,	//	206	02-30	Brake Delay Timer at stop
	"恨葩汹廪嗖夯. sec "	,	//	207	02-31	Mech Contact Delay Timer run
	"恨葩汹廪嗖撕sec "	,	//	208	02-32	Mech Contact Delay Timer stop				            
	"罗诓谯.簇嶷译   "	,	//	209	02-33	Isum Current Output Detect	    
	"?嗅?.糙簇嶷搽錒z  "	,	//	210	02-34	Speed Area
	"苦抟锗佬徕.廪嘬.sec "	,	//	211	02-35	Mechanical Brake Checking Time
	"苦抟糙酆掭庑阝捺sec "	,	//	212 02-36   Magnetic Contactor Checking Time
	"苦抟.译苻苷葩   "  ,   //  213 02-37   Mechanical Brake Checking Current Enable
	"Y-D恨葩汹饬庑噔 sec "  ,   //  2xx 02-38   Star Contactor delay time when driver run    //[Star contactor function, Bernie, 2017/03/22]
	"Y-D恨葩汹饬廪 sec "  ,   //  2xx 02-39   Star Contactor delay time when driver stop  //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD Fault SEL     "  ,   //  2xx 02-40   LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
	"LU/LD Open Det. sec "  ,   //  2xx 02-41   LD/LD Open Detect Time       //#15977, LULD detect, James, 2021/04/01
	"LU/LD Short Det.sec "  ,   //  2xx 02-42   LD/LD Short Detect Time      //#15977, LULD detect, James, 2021/04/01
	"SPEED-REACH BND Hz  "	,   //  202 02-43   Band of Speed Agree Function  //#18572
    "STO Short Det   sec "  ,   //  2xx 02-44   STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Speed Limit     m/s "  ,   //  2xx 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06]
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"拜雄抻.义拊 AUI1    "	,	//	214	03-00    AUI1 selection     //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"沸嗾渍嘁剜抟休    "	,	//	215	03-01    ACI  selection      //[ACI function remove, Bernie, 01/20/2012]
	"拜雄抻.义拊 AUI2    "	,	//	216	03-02    AUI2 selection    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"淋臻蛰卣 AUI1   %   "	,	//	217	03-03    AUI1 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"沸嗾渍嘁剜抟休    "	,	//	218	03-04    ACI  input Bias    //[ACI function remove, Bernie, 01/20/2012]
	"淋臻蛰卣 AUI2   %   "	,	//	219	03-05    AUI2 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"勒重芰苷檎AUI1    "	,	//	220  03-06    AUI1 input Polarity         //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"沸嗾渍嘁剜抟休    "	,	//	221  03-07    ACI  input Polarity     //[ACI function remove, Bernie, 01/20/2012]
	"勒重芰苷檎AUI2    "	,	//	222  03-08    AUI2 input Polarity    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"恨礓.冕刿蛰.AUI1%   "	,	//	223  03-09    AUI1 input Gain     //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"沸嗾渍嘁剜抟休    "	,	//	224  03-10    ACI  input Gain     //[ACI function remove, Bernie, 01/20/2012]
	"恨礓.冕刿蛰.AUI2%   "	,	//	225  03-11    AUI2 input Gain   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 义拊慕   sec "	,	//	226  03-12    Low pass filter of AUI1 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"沸嗾渍嘁剜抟休    "	,	//	227  03-13    Low pass filter of ACI  input      //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 义拊慕   sec "	,	//	228  03-14    Low pass filter of AUI2 input    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"沸嗾渍嘁剜抟休    "	,	//	229  03-15    Loss of ACI            //[ACI function remove, Bernie, 01/20/2012]
    "沸嗾渍嘁剜抟休    "  ,   //  230  03-16
	"你葳尕熬1         "	,	//	231  03-17    Analong Output 1
	"恨礓冕刿蛰.AO1%   "	,	//	232  03-18    Analong Output 1 Gain
	"AO1 哙嗾艺噌    "	,	//	233  03-19    AO1 in minus value
	"你葳尕熬2         "	,	//	234  03-20    Analong Output 2
	"恨礓冕刿蛰.AO2%   "	,	//	235  03-21    Analong Output 2 Gain
	"AO2 哙嗾艺噌    "	,	//	236  03-22    AO2 in minus value
	"哭埏噍掎忪 AUI1     "	,	//	237  03-23    AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"哭埏噍掎忪 AUI2     "	,	//	238  03-24    AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	//"AUI1义.菪徕  /"AUI1 In Setting     "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2义.菪徕  /"AUI2 In Setting     "	,	//	238  03-26    AUI2 Communciate
	
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "0-嶷捺掎忪    Hz  "  , //  239 04-00 Multi-Speed 0
    "1-嶷捺掎忪    Hz  "  , //  240 04-01 Multi-Speed 1
    "2-嶷捺掎忪    Hz  "  , //  241 04-02 Multi-Speed 2
    "3-嶷捺掎忪    Hz  "  , //  242 04-03 Multi-Speed 3
    "4-嶷捺掎忪    Hz  "  , //  243 04-04 Multi-Speed 4
    "5-嶷捺掎忪    Hz  "  , //  244 04-05 Multi-Speed 5
    "6-嶷捺掎忪    Hz  "  , //  245 04-06 Multi-Speed 6
    "7-嶷捺掎忪    Hz  "  , //  246 04-07 Multi-Speed 7
    "8-嶷捺掎忪    Hz  "  , //  247 04-08 Multi-Speed 8
    "9-嶷捺掎忪    Hz  "  , //  248 04-09 Multi-Speed 9
    "10-嶷捺掎忪   Hz  "  , //  249 04-10 Multi-Speed 10
    "11-嶷捺掎忪   Hz  "  , //  250 04-11 Multi-Speed 11
    "12-嶷捺掎忪   Hz  "  , //  251 04-12 Multi-Speed 12
    "13-嶷捺掎忪   Hz  "  , //  252 04-13 Multi-Speed 13
    "14-嶷捺掎忪   Hz  "  , //  253 04-14 Multi-Speed 14
    "15-嶷捺掎忪   Hz  "  , //  254 04-15 Multi-Speed 15
    "吝嗅锈.嶷-徕  m/s "  , //  2xx 04-16
    "邻捺.赞怙迂倚葚飉/s "  , //  2xx 04-17
    "邻捺.肄滓赞苻賛/s "  , //  2xx 04-18
	                 
    "Rope Slip Comp. mm  "  , //  2xx 04-19 GFC Rope compensation, 2021/03/30
    "TABST0 徕锈汜       "  ,   //    2xx 04-20
    "TABST2 徕锈汜       "  ,   //    2xx 04-21
	                 
    "夹卺. 礅兄          "  , //  2xx 04-22
    "抡阢樨礅兄        "  , //  2xx 04-23
    "PG 缸苷哙捩   %   "  , //  2xx 04-24
    "Sensor Delay Cmpsec "  , //  2xx 04-25
    "DLC 沸哉嘀.亦哲.ms  "  , //  2xx 04-26
    "篡剌咣休谪    mm  "  , //  2xx 04-27 
    "抡 咿 搽  m   "  , //  2xx 04-28
    "抡 咿 截  mm  "  , //  2xx 04-29
    "抡阢纵戌. PG H    "  , //  2xx 04-30 
    "抡阢纵戌. PG L    "  , //  2xx 04-31
    "扣休谛:份戌.PG H    "  , //  2xx 04-32
    "扣休谛:份戌.PG L    "  , //  2xx 04-33
    "琳葆捺 PG 搽      "  , //  2xx 04-34
    "琳葆捺 PG 截      "  , //  2xx 04-35    
    "你葳尕DLC         "  , //  2xx 04-36
    "仑PDO             "  , //  2xx 04-37
    "沸苷SWTol.Gap mm  "  , //  2xx 04-38
    "% 掴 夹卺 嶷-徕   "  , //  2xx 04-39 //[ADCO EPS Modify]
    "Spring Extend   mm  "  , //  2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "赁徕揎葚EST       "  , //  2xx 04-41
    "羚这缲EST         "  , //  2xx 04-42
    "TABST0 羚这.        "  , //  2xx 04-43
    "TABST1 羚这.        "  , //  2xx 04-44
    "DDS1/UDS1Spd Limm/s "  , //  2XX 04-45  DD1_Vlim  //Artemis speed limit, James, 20200220                          
    "DDS2/UDS2Spd Limm/s "  , //  2XX 04-46  DD2_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS3/UDS3Spd Limm/s "  , //  2XX 04-47  DD3_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS4/UDS4Spd Limm/s "  , //  2XX 04-48  DD4_Vlim  //Artemis speed limit, James, 20200220
    "DLC 咿垤徕      "  , //  2XX 04-49   user page cahnge
                     
    "1咿棕尕译 m   "  , //  2XX 04-30   1Floor Position H                                       
    "1咿棕尕葚 mm  "  , //  2XX 04-31   1Floor Position L                                       
    "2咿棕尕译 m   "  , //  2XX 04-32   2Floor Position H                                       
    "2咿棕尕葚 mm  "  , //  2XX 04-33   2Floor Position L                                       
    "3咿棕尕译 m   "  , //  2XX 04-34   3Floor Position H                                       
    "3咿棕尕葚 mm  "  , //  2XX 04-35   3Floor Position L                                       
    "4咿棕尕译 m   "  , //  2XX 04-36   4Floor Position H                                       
    "4咿棕尕葚 mm  "  , //  2XX 04-37   4Floor Position L                                       
    "5咿棕尕译 m   "  , //  2XX 04-38   5Floor Position H                                       
    "5咿棕尕葚 mm  "  , //  2XX 04-39   5Floor Position L                                       
    "6咿棕尕译 m   "  , //  2XX 04-40   6Floor Position H                                       
    "6咿棕尕葚 mm  "  , //  2XX 04-41   6Floor Position L                                       
    "7咿棕尕译 m   "  , //  2XX 04-42   7Floor Position H                                       
    "7咿棕尕葚 mm  "  , //  2XX 04-43   7Floor Position L                                       
    "8咿棕尕译 m   "  , //  2XX 04-44   8Floor Position H                                       
    "8咿棕尕葚 mm  "  , //  2XX 04-45   8Floor Position L                                       
    "9咿棕尕译 m   "  , //  2XX 04-46   9Floor Position H                                       
    "9咿棕尕葚 mm  "  , //  2XX 04-47   9Floor Position L                                       
    "10咿棕尕译m   "  , //  2XX 04-48   10Floor Position H                                      
    "10咿棕尕葚mm  "  , //  2XX 04-49   10Floor Position L                                      
    "11咿棕尕译m   "  , //  2XX 04-50   11Floor Position H                                      
    "11咿棕尕葚mm  "  , //  2XX 04-51   11Floor Position L                                      
    "12咿棕尕译m   "  , //  2XX 04-52   12Floor Position H                                      
    "12咿棕尕葚mm  "  , //  2XX 04-53   12Floor Position L                                      
    "13咿棕尕译m   "  , //  2XX 04-54   13Floor Position H                                      
    "13咿棕尕葚mm  "  , //  2XX 04-55   13Floor Position L                                      
    "14咿棕尕译m   "  , //  2XX 04-56   14Floor Position H                                      
    "14咿棕尕葚mm  "  , //  2XX 04-57   14Floor Position L                                      
    "15咿棕尕译m   "  , //  2XX 04-58   15Floor Position H                                      
    "15咿棕尕葚mm  "  , //  2XX 04-59   15Floor Position L                                      
    "16咿棕尕译m   "  , //  2XX 04-60   16Floor Position H                                      
    "16咿棕尕葚mm  "  , //  2XX 04-61   16Floor Position L                                      
    "17咿棕尕译m   "  , //  2XX 04-62   17Floor Position H                                      
    "17咿棕尕葚mm  "  , //  2XX 04-63   17Floor Position L                                      
    "18咿棕尕译m   "  , //  2XX 04-64   18Floor Position H                                      
    "18咿棕尕葚mm  "  , //  2XX 04-65   18Floor Position L                                      
    "19咿棕尕译m   "  , //  2XX 04-66   19Floor Position H                                      
    "19咿棕尕葚mm  "  , //  2XX 04-67   19Floor Position L                                      
    "20咿棕尕译m   "  , //  2XX 04-68   20Floor Position H                                      
    "20咿棕尕葚mm  "  , //  2XX 04-69   20Floor Position L                                      
    "21咿棕尕译m   "  , //  2XX 04-70   21Floor Position H                                      
    "21咿棕尕葚mm  "  , //  2XX 04-71   21Floor Position L                                      
    "22咿棕尕译m   "  , //  2XX 04-72   22Floor Position H                                      
    "22咿棕尕葚mm  "  , //  2XX 04-73   22Floor Position L                                      
    "23咿棕尕译m   "  , //  2XX 04-74   23Floor Position H                                      
    "23咿棕尕葚mm  "  , //  2XX 04-75   23Floor Position L                                      
    "24咿棕尕译m   "  , //  2XX 04-76   24Floor Position H                                      
    "24咿棕尕葚mm  "  , //  2XX 04-77   24Floor Position L                                      
    "25咿棕尕译m   "  , //  2XX 04-78   25Floor Position H                                      
    "25咿棕尕葚mm  "  , //  2XX 04-79   25Floor Position L                                     
   
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
	"耙廪忸葚萦 按       "	,	//	255 05-00	Motor Auto-Tuning
	"睫 廪按     Amps"	,	//	256 05-01	Motor 1 rated Current           
	"睫苻檩掎忪 按 Kw  "	,	//	257 05-02	Motor 1 Rated Power             
	"睫 缧徕掴按 RPM "	,	//	258 05-03	Motor 1 Rated RPM               
	"?蒯圻捋钺薨?    "	,	//	259 05-04	Motor 1 pole No.                
	"罗遛 遛孕 按Amps"	,	//	260 05-05	Motor 1 No-Load Current         
	"Rs 砸赜锈折   ohm "	,	//	261 05-06	Motor 1 Rs                      
	"Rr 砸赜锈折   ohm "	,	//	262 05-07	Motor 1 Rr                      
	"Lm 砸赜锈折    mH "	,	//	263 05-08	Motor 1 Lm                      
	"L砸赜锈折    mH "	,	//	264 05-09	Motor 1 Lx                      
	"谵苓. 苻 SVCsec "	,	//	265 05-10	Vector Voltage Filter	        
	"纶捃嶷捋熘.SVCsec "	,	//	266 05-11	Vector Slip Filter	            
	"恨礓.谵苓.苻庑    "	,	//	267 05-12	Torque Compensation Gain	    
	"恨礓.谵苓.嶷捋熘    "	,	//	268 05-13	Slip Compensation Gain	        
	"崔咩徕剀拚邻捋熘%   "	,	//	269 05-14	Slip Deviation level	        
	"沸哉捱嶷捋熘sec "	,	//	270 05-15	Slip Deviation Detect Time	    
	"勒汹婵嗾嶷捋熘    "	,	//	271 05-16	Over Slip treatment	            
	"恨苓蛰.菡汜廪夔.    "	,	//	272 05-17	Coeff for hunting disable	    
	"壳 嘈艳庹     Mins"	,	//	273 05-18	Accumulative Motor Operation Min
	"壳 嘈艳庹     Days"	,	//	274 05-19	Accumulative Motor Operation Day
	"恨苓哭庹囔菱雄%   "	,	//	275 05-20	Coreloss % of output Power	    
	"控庑葚亿茇Mins"	,	//	276 05-21	Power On Min
	"控庑葚亿暂. Days"	,	//	277 05-22	Power On Day
    "痴嶷捋熘.汜刿 %   "	,   //    2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"匆赜.嶷捋熘.汜刿%   "	,	//	123 15-123  RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
	"截汔抟.菪哙镏 V   "	,	//	278  06-00	Low voltage level
	"尕狙嚯湫纂    "	,	//	279  06-01	Phase loss
	"罗谵抻嘈汜谵%   "	,	//	280  06-02	OC stall during Accel
	"罗谵抻嘈嘈艳庑%   "	,	//	281  06-03	OC stall during Decel
	"罗谵抻嗝嶷捺/沸   "	,	//	282  06-04	Stall preventation Accel/Decel time selection
	"勒抻苻苷葩    "	,	//	283  06-05	Over-Torque 1 Selection
	"居嘈苻苷葩% %   "	,	//	284  06-06	Over-Torque 1 level
	"侧哲.抻苻苷葩衧ec "	,	//	285  06-07	Over-Torque 1 Time
	"勒抻苻苷葩    "	,	//	286  06-08	Over-Torque 2 Selection	                     
	"居嘈苻苷葩  %   "	,	//	287  06-09	Over-Torque 2 level	                         
	"侧哲.抻苻苷葩衧ec "	,	//	288  06-10	Over-Torque 2 Time	                         
	"居嘈葚 嫁苷葩   "	,	//	289  06-11	Current Limit
	"哇.庹咣.嗾壅 砸1    "	,	//	290  06-12	Thermal Relay 1 Selection
	"T 庹咣.嗾壅 砸.1sec "	,	//	291  06-13	Thermal Relay 1 Time
	"空嗾余找 嘈载锈. C  "	,	//	292  06-14	OH Warning Level
	"罗谵抻嘈葚缯葚%   "	,	//	293  06-15	Stall preventation Limit Level
	"1仔哓犰 幸朽刎    "	,	//	294  06-16	1st Fault Record
	"2仔哓犰 幸朽刎    "	,	//	295  06-17	2nd Fault Record
	"3仔哓犰 幸朽刎    "	,	//	296  06-18	3rd Fault Record
	"4仔哓犰 幸朽刎    "	,	//	297  06-19	4th Fault Record
	"5仔哓犰 幸朽刎    "	,	//	298  06-20	5th Fault Record
	"6仔哓犰 幸朽刎    "	,	//	299  06-21	6th Fault Record
	"耙朽仫 咱译1    "	,	//	300  06-22	Fault Option 1
	"耙朽仫 咱译2    "	,	//	301  06-23	Fault Option 2
	"耙朽仫 咱译3    "	,	//	302  06-24	Fault Option 3
	"耙朽仫 咱译4    "	,	//	303  06-25	Fault Option 4
	"勒汹 徉醒. PTC    "	,	//	304  06-26	PTC over Treatments	                         
	"绵抟蛰PTC     %   "	,	//	305  06-27	PTC Level
	"呢垤忄 PTC      sec "	,	//	306  06-28	PTC Detect Filter time
	"叫哙镏. 副    V   "	,	//	307  06-29	EPS voltage level
	"勒重馨倚嘭鼐哝      "	,	//	308  06-30	Fault Option Mode
	"苦抟锗谛搽迥凶      "	,	//	309  06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
	"侧哲1-幸朽刎Mins"	,	//	310  06-32	1st Fault Time(MIN)
	"侧哲1-幸朽刎Days"	,	//	311  06-33	1st Fault Time(DAY)
	"侧哲2-幸朽刎Mins"	,	//	312  06-34	2nd Fault Time(MIN)
	"侧哲2-幸朽刎Days"	,	//	313  06-35	2nd Fault Time(DAY)
	"侧哲3-幸朽刎Mins"	,	//	314  06-36	3rd Fault Time(MIN)
	"侧哲3-幸朽刎Days"	,	//	315  06-37	3rd Fault Time(DAY)
	"侧哲4-幸朽刎Mins"	,	//	316  06-38	4th Fault Time(MIN)
	"侧哲4-幸朽刎Days"	,	//	317  06-39	4th Fault Time(DAY)
	"侧哲5-幸朽刎Mins"	,	//	318  06-40	5th Fault Time(MIN)
	"侧哲5-幸朽刎Days"	,	//	319  06-41	5th Fault Time(DAY)
	"侧哲6-幸朽刎Mins"	,	//	320  06-42	6th Fault Time(MIN)
	"侧哲6-幸朽刎Days"	,	//	321  06-43	6th Fault Time(DAY)
    "邻-徕硪汹阈尕豀z  "  ,   //  322  06-44	EPS Frequency
    "勒重芫柝掩    BIN "  ,	//  323  06-45  LV Option Mode
    "勒重芡倚阢墟刎      "  ,	//  324  06-46  EPS Option Mode
    "徽于叫哙侧哭蒯sec "  ,   //  325  06-47  Generation Operation Detected Time
    "嫁檩掎忪 副   KVA "  ,   //  326  06-48  UPS Capacity (0.1KVA)
    "叫徕噢仝STO       "  ,   //  3xx   06-49      STO Lock selection     //[Safty function, Bernie] 
    "空嗾仔 菪徕     "	,   //  356   06-50     Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "耙 哒嗾仔亦.sec "  ,   //  356   06-51     Auto restart times after fault     
    "篙庹嘁.哒嗾仔 sec "  ,   //  356   06-52     Auto restart interval
    "沸缧徕掴.仔 Hz  "	,	//	99  15-99   Fkey Record
    "搽缧徕掴.仔 Hz  "	,	//	94 	 15-94   Fcmd Record"Out Freq. REC.  Hz  "	,	//	94 	15-94   Fcmd Record
    "搽廪仔    Amps"	,	//	82   15-82	 Isum Record
    "?嗅廪?.砸赜.仔Hz  "	,	//	79   15-79	Fout Record
    "搽菪哙.仔   V   "	,	//	80   15-80	Vout Record
	"叫哙.滓蛰蠨C.仔遃   "	,   //  81   15-81	Dcbus Record  
	"搽苻檩.仔   KW  "	,	//	100 15-100  Power Record
	"搽苻苷葩.仔 %   "	,	//	101 15-101  Torque Record
	"抡苓.IGBT.仔   C  "	,	//	83  15-83	IGBT Temperature Record    
	"赁徕.载嶷.义.仔逪ex "	,	//	102 15-102  MFI State Record
	"赁徕.簇嶷搽仔逪ex "	,	//	103 15-103  MFO State Record
	"赁徕.哙匾拊仔逪ex "	,	//	104 15-104  Drive State Record
	"居 廪谛 UCMP  %   "  ,  //  3XX  06-65  Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
	"侧哲.扪巅阒.        "  ,   //  3xx 06-66  Service time count                              //[Service time function, Bernie, 2017/03/14]
	"糙扪巅阒.         "  ,   //  3xx 06-67   Service time function Enable                 //[Service time function, Bernie, 2017/03/14]
    "鸵汹.捱PF     deg "  ,   //  EPS Detect Current    
    "鸵汹.阌捋.PF    deg "  ,   //  EPS Detect Current Ref
    "具嗾菪哙.硪汹.    "  ,   //  EPS Detect direction
    "鸵汹.仔哉嗖谯搽錽ec "  ,   //  EPS MO Off Time
    "鸵汹.仔哉嗖脍搽錽ec "  ,   //  EPS MO Off Time
    "羚这裤嶷叫哙幸鄄H   "	,	//	Running direction count high						
    "羚这裤嶷叫哙幸劢L   "	,	//	Running direction count low
    "羚这.缸苷萁羞嗖 H   "	,	//	Temp running direction count high
    "羚这.缸苷萁羞嘟 L   "	,	//   Temp running direction count low
    "裂噢岵嗾芨总叫哙    "	,	//	Temp running reset count
    "居嘈莶嗾芨总叫哙k   "	,	//	Running life
    "叫徕噢俨嗾茱佬    "	,	//	Running function
    "搽缧徕掴.仔 Hz  "  ,   //  Fcmd Record1"Out Freq. REC.  Hz  "
    "叫哙.滓蛰DC.仔V   "	,   //  Dcbus Record 1
    "搽廪仔    Amps"  ,   //  Isum Record1
    "抡苓.IGBT.仔  C   "  ,   //  IGBT Temperature Record1
    "搽缧徕掴.仔 Hz  "  ,   //  Fcmd Record2"Out Freq. REC.  Hz  "
    "叫哙.滓蛰DC.仔V   "	,   //  Dcbus Record2
    "搽廪仔    Amps"  ,   //  Isum Record2
    "抡苓.IGBT.仔  C   "  ,   //  IGBT Temperature Record2
    "搽缧徕掴.仔 Hz  "  ,   //  Fcmd Record3"Out Freq. REC.  Hz  "
    "叫哙.滓蛰DC.仔V   "	,   //  Dcbus Record3
    "搽廪仔    Amps"  ,   //  Isum Record3
    "抡苓.IGBT.仔  C   "  ,   //  IGBT Temperature Record3
    "搽缧徕掴.仔 Hz  "  ,   //  Fcmd Record4"Out Freq. REC.  Hz  "
    "叫哙.滓蛰DC.仔V   "	,   //  Dcbus Record4
    "搽廪仔    Amps"  ,   //  Isum Record4
    "抡苓.IGBT.仔  C   "  ,   //  IGBT Temperature Record4
    "搽缧徕掴.仔 Hz  "  ,   //  Fcmd Record5"Out Freq. REC.  Hz  "
    "叫哙.滓Udc.仔 V   "	,   //  Dcbus Record5
    "搽廪仔    Amps"  ,   //  Isum Record5
    "抡苓.IGBT.仔  C   "  ,   //  IGBT Temperature Record5
    
/*---- GROUP 07-----------------------------------------*/ 
/*  "12345678901234561234"	*/
	"叫哙糙勐捺芎垲缧V   "	,	//	327   07-00	SW Braking Level
    "BK Voltage Hold V   "  ,   //	328   07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
	"罗贒C-廪嘬.徕朽   "	,	//	329   07-02	DCI Current Level      //[DCI Level when stop, Bernie, 05/21/2012]
	"侧哲DC罗嘬C庑噔 sec "	,	//	330   07-03	DCI Time at Start 
	"侧哲DC罗嘬菱捱  sec "	,	//	331   07-04	DCI Time at STOP
	"?嗅廪釪C剌终阪. Hz  "	,	//	332   07-05	DCI Freq. At start
	"恨礓.汜刿.菪哙Ki    "	,	//	333   07-06	DCI KI
	"沸哉汜谵亦哲sec "	,	//	334   07-07	Gear wait time when acceleration
	"沸哉汜谵缧徕Hz  "	,	//	335   07-08	Gear wait frequency when acceleration
	"沸哉仔苷亦哲sec "	,	//	336   07-09	Gear wait time when deceleration
	"沸哉仔苷缧徕Hz  "	,	//	337   07-10	Gear wait frequency when deceleration
	"眠艺葩刿镡捺    "	,	//	338   07-11	Fan Control
	"沸孕葚苻苷葩%   "	,	//	339   07-12	TQC Reference from RS485
	"羔廪仔孕苻    "	,	//	340   07-13	Source of Torque Command
	"夹卺.汔抟.苻苷葩%   "	,	//	341   07-14	Torque max. level
	"嫩忄 仔孕苻苷輘ec "	,	//	342   07-15	Torque command filter
	"颊廪抻嘈嶷捺    "	,	//	343   07-16	Speed Limit selection
	"勒旨捃居嗔徕%   "	,	//	344   07-17	Torque mode positive speed limit
	"勒旨捃居嗔徕%   "	,	//	345   07-18	Torque mode negative speed limit
	"羔廪彳臻.苻苷   "	,	//	346   07-19	Torque offset selection
	"淋臻蛰卣 苻苷葩   "	,	//	347   07-20	Torque offset setting level
	"舱噱.彳臻.苻苷葩%   "	,	//	348   07-21	Torque offset setting level High
	"拎赵.彳臻.苻苷葩%   "	,	//	349   07-22	Torque offset setting level Middle
	"截州.彳臻.苻苷葩%   "	,	//	350   07-23	Torque offset setting level Low
	"居嘈苻蹻WD砸  %   "	,	//	351   07-24	FWD Motoring Tq Limit
	"居嘈苻蹻WD诱%   "	,	//	352   07-25	FWD Regeneration Tq Limit
	"居嘈苻躌EV砸  %   "	,	//	353   07-26	REV Motoring Tq Limit
	"居嘈苻躌EV诱%   "	,	//	354   07-27	REV Regeneration Tq Limit
	"仑甙倚嗑徕休抟    "	,	//	355   07-28	Emergency Stop & Forced Stop selection
	"侧哲锪葚终葚锛捃sec "	,	//	356   07-29   Torque Decrease Time
	"绵抟.廪谛DC廪嘬.%   "	,	//	356   07-30     STOP DC Inject Level    //[DCI Level when stop, Bernie, 05/21/2012]
	"BTT100             %"  ,   //  357 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect         "  ,   //  358 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Distance    ppr"  ,   //  359 07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect Time sec"  ,   //  360 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Fail Torq      "  ,   //  361 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Min Torq       "  ,   //  362 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Max Torq       "  ,   //  362 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"耙廪忸葚萦链        "	,	//	357   08-00	PMotor Auto-Tuning  
	"睫 廪链     Amps"	,	//	358   08-01	PMotor rated Current
	"睫苻檩掎忪 链 Kw  "	,	//	359   08-02	PMotor Rated Power  
	"睫 嶷捺掎忪 链RPM "	,	//	360   08-03	PMotor Rated RPM    
	"?蒯坜哭垲徂? 链     "	,	//	361   08-04	PMotor pole No.     
	"Rs 嶝蒎.砸赜.   ohm "	,	//	362   08-05	PMotor Rs           
	"Ld 嶝蒎.砸赜.       "	,	//	363   08-06	PMotor Ld           
	"Lq 嶝蒎.砸赜.   mH  "	,	//	364   08-07	PMotor Lq           
	"狙嘈廨酗 痛   Vrms"	,	//	365   08-08	PMotor Bemf coff	
	"Z-彳臻. 糜捋    deg "	,	//	366   08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
	"空嗾捺卣葩夹涌捋    "	,	//	367   08-10	//ADDED BY DINO                                      
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "霸嗾嵋镒壳      "	,	//	368   09-00	Comm Address                              
    "邻捺掎忪 COM    kbps"	,	//	369   09-01	Tranmission speed                         
    "勒汹.咿庹嘭烈镒   "	,	//	370   09-02	Comm fault Treatment                      
    "滦佘-秀COM    sec "	,	//	371   09-03	Comm Time out                             
    "苦掴挹捋 嵋镒     "	,	//	372   09-04	Comm Protocol                             
    "沸哉嘀谛 掴艺庑 ms  "	,	//	373   09-05	ASC remote Response Delay Time, 1=100us   
    "CAN_BUARD           "	,   //  3XX   09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "PDO_Tx_Time     ms  "	,   //  3XX   09-07    CAN PDO Handshaking Period  
    "CAN_Check_Time  ms  "	,   //  3XX   09-08    CAN Communiction Timeout
    "ID 谵圬溻       "  ,   //  3XX   09-09    Elevator Control Identification Code
    "FHM 嗾迂徕        "  ,   //  3XX   09-10
    "DLC 勒迂徕1       "  ,   //  3XX   09-11
    "DLC 勒迂徕2       "  ,   //  3XX   09-12
    "DLC 勒迂徕3       "  ,   //  3XX   09-13     
    "PDO TXTIME      ms  "  ,   //  3XX   09-14  CAN fail rate---aevin 6/12/2017  
/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"仑磔谵哉嘈        "	,	//	374   10-00	Encoder TYPE                             
	"?蒯圬苓阚燹裵pr "	,	//	375   10-01	Encoder pulses	                    
	"仑吡赜菪坌洼谵脏    "	,	//	376   10-02	PG input setting	                
	"勒汹掼匮谪 磔   "	,	//	377   10-03	PG fbk fault treatment	            
	"沸哉嘀捐匮谪洼sec "	,	//	378   10-04	PG fbk Error Detection Time	        
	"绵抟蛰炀柝掩赝葳%   "	,	//	379   10-05	PG fbk overspeed detection level	
	"狙菪嗫嗾译枇谵sec "	,	//	380   10-06	Over speed Detection Time	        
	"绵抟蛰炝谵垤滞葳%   "	,	//	381   10-07	PG fbk speed deviation level	    
	"沸哉嗑演朽邻捋熘sec "	,	//	382   10-08	Deviation Detect Time	            
	"勒汹哙找.嶷捺     "	,	//	383   10-09	Operation at overspeed	            
	"叫徕磔UVW       "  ,   //    384   10-10      Hall Input Types
	"0嶷-徕谵礓 亨 %   "	,	//	385   10-11	KP gain of ASR in Zero speed	
	"0嶷-徕谵礓 Ki sec "	,	//	386   10-12	Ki gain of ASR in Zero speed	
	"夹嶷捺.谵礓.亨%   "	,	//	387   10-13	ASR P Gain 1	                
	"夹嶷捺.谵礓.Kisec "	,	//	388   10-14	ASR I Gain 1	                
	"鞭嶷捺.谵礓.亨%   "	,	//	389   10-15	ASR P Gain 2	                
	"鞭嶷捺.谵礓.Kisec "	,	//	390   10-16	ASR I Gain 2	                
	"袄/2哒嗾谯.   Hz  "	,	//	391   10-17	ASR1/ASR2 switch freq	        
	"空嘁.袄慕 sec "	,	//	392   10-18	Primary LowPass filter Gain 
	"恨葩汔.咿棕 亨%   "  ,	//	393   10-19     position control Kp Gain  
    "?剜袄淋嗅?-庳 Hz  "  ,   //    394   10-20     Low Spd band
    "?剜袄裂掎?-庳 Hz  "  ,   //    395   10-21     High Spd band
	"迷锗.咿棕亦哲飐ec "	,	//	396   10-22     Position control time
	"迷锗.咿慕   sec "	,	//	397   10-23     Position control LOW POSS FILTER
	"勒重氵咿棕    "	,	//	398   10-24     Source of position control, add by dino, 06/30/2008
	"0嶷-忪.译嘈亨 %   "	,	//	399   10-25	KP gain of ASR in Zero speed of Landing
	"0嶷-忪.译嘈篿 sec "	,	//	400   10-26	Ki gain of ASR in Zero speed of Landing
	"哭棕徕朽亨  %   "	,	//	385   10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"哭棕徕朽篿  sec "	,	//	386   10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"凑嶝磔译    "	,   //    4xx   10-29      PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
	"勒嶝磔译    "	,   //    4xx   10-30      PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C- 庳       "  ,   //  110 15-110  RESERVED       //[change parameter to normal group, Bernie, 2014/02/14]
    "苦找.汜谵汔抟 m/s2"  ,   //    3XX  10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "苦找.汜谵扪菪鄐ec "  ,   //    3XX  10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "苦找.汜谵菪徕   "  ,   //    3XX  10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    "ACC LPF             "  ,   //  422 10-35   //Rationa 362631, Special.Kung
    "ACC SampleRate    ms"  ,   //  422 10-36   //Rationa 362631, Special.Kung
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"眠嘈役. c蒯庹苻貶ex "	,	//	401   11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "夹卺.嶷-忪 圬怃衜/s "  ,   //  402   11-01   Lift operation speed                                        
    "簇熊. 翰      mm  "  ,   //  403   11-02   SHEAVE diameter			ADDED BY SCOTTY                     
    "空嗾孕嗾糟阝.     "  ,   //  404   11-03   Gear Ratio                                              
    "哭圬徇嗅          "  ,   //  405   11-04   Suspension ratio	                                        
    "恨礓.剌锗尕   %   "  ,   //  406   11-05   inertia	percent			ADDED BY SCOTTY                     
	"姐壅倚嶷-忪 BWHz  "	,	//	407   11-06	Zero Speed Loop BandWidth	                                
	"夹坌嶷-忪 BW  Hz  "	,	//	408   11-07	Speed Loop BandWidth1		                                
	"鞭垤栊嶷-忪 BWHz  "	,	//	409   11-08	Speed Loop BandWidth2		                                
	"Kr 谵葩汔.嶷捺  %   "	,	//	410   11-09	PDFFKr		                                                
	"恨礓.嶷捺.疫锗赵%   "	,	//	411   11-10	SPEED FFD GAIN			ADDED BY SCOTTY                     
	"颊湄垤盂阊. db  "	,	//	412   11-11	Netch filter deep(db)	                                    
	"颊湄垤缧徕. Hz  "	,	//	413   11-12	Netch filter frequency	                                    
	"慕咱载徇  sec "	,	//	414   11-13	Low Pass Filter for display	                                
	"夹卺罗砸.汜 %   "	,	//	415   11-14	ACC Max current                                             
    "夹卺冕谛沿蓦  m/s "  ,	//	416   11-15	max meter/sec	                                            
    "簇徇性嗾    Hex "  ,   //	417   11-16	Display address,add by dino 2007/03/08                      
    "簇徇孕葺胝        "  ,	//	418   11-17	Display data,   add by dino 2007/03/08                      
    "沸樨廨.沿         "  ,   //  419   11-18   Protect Bit	                                                
	"姐嶷.译嘈褺W  Hz  "	,	//	420   11-19	Zero Speed Loop BandWidth of Landing
	"嗾重??          "	,	//	10    15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM    PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LPF for LC01    sec "	,	//	422 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Motor SPD RPM       "  ,   //  420   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_按           "  ,   //  421   12-00
    "UMAP_按           "  ,   //  422   12-01
    "UMAP_按           "  ,   //  423   12-02
    "UMAP_按           "  ,   //  424   12-33
    "UMAP_按           "  ,   //  425   12-04
    "UMAP_按           "  ,   //  426   12-05
    "UMAP_按           "  ,   //  427   12-06
    "UMAP_按           "  ,   //  428   12-07
    "UMAP_按           "  ,   //  429   12-08
    "UMAP_按           "  ,   //  430   12-09
    "UMAP_按0          "  ,   //  431   12-10
    "UMAP_按1          "  ,   //  432   12-11
    "UMAP_按2          "  ,   //  433   12-12
    "UMAP_按3          "  ,   //  434   12-13
    "UMAP_按4          "  ,   //  435   12-14
    "UMAP_按5          "  ,   //  436   12-15
    "UMAP_按6          "  ,   //  437   12-16
    "UMAP_按7          "  ,   //  438   12-17
    "UMAP_按8          "  ,   //  439   12-18
    "UMAP_按9          "  ,   //  440   12-19 
    "UMAP_按0          "  ,   //  441   12-20
    "UMAP_按1          "  ,   //  442   12-21
    "UMAP_按2          "  ,   //  443   12-22
    "UMAP_按3          "  ,   //  444   12-23
    "UMAP_按4          "  ,   //  445   12-24
    "UMAP_按5          "  ,   //  446   12-25
    "UMAP_按6          "  ,   //  447   12-26
    "UMAP_按7          "  ,   //  448   12-27
    "UMAP_按8          "  ,   //  449   12-28
    "UMAP_按9          "  ,   //  450   12-29
    "UMAP_按0          "  ,   //  451   12-30
    "UMAP_按1          "  ,   //  452   12-31
    "UMAP_按2          "  ,   //  423   12-02
    "UMAP_按3          "  ,   //  424   12-33
    "UMAP_按4          "  ,   //  425   12-04
    "UMAP_按5          "  ,   //  426   12-05
    "UMAP_按6          "  ,   //  427   12-06
    "UMAP_按7          "  ,   //  428   12-07
    "UMAP_按8          "  ,   //  429   12-08
    "UMAP_按9          "  ,   //  430   12-09
    "UMAP_按0          "  ,   //  421   12-00
    "UMAP_按1          "  ,   //  422   12-01
    "UMAP_按2          "  ,   //  423   12-02
    "UMAP_按3          "  ,   //  424   12-33
    "UMAP_按4          "  ,   //  425   12-04
    "UMAP_按5          "  ,   //  426   12-05
    "UMAP_按6          "  ,   //  427   12-06
    "UMAP_按7          "  ,   //  428   12-07
    "UMAP_按8          "  ,   //  429   12-08
    "UMAP_按9          "  ,   //  430   12-09
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
    "UMAP_窗浇说0        "  ,   //  453   13-00
    "UMAP_窗浇说1        "  ,   //  454   13-01
    "UMAP_窗浇说2        "  ,   //  455   13-02
    "UMAP_窗浇说3        "  ,   //  456   13-33
    "UMAP_窗浇说4        "  ,   //  457   13-04
    "UMAP_窗浇说5        "  ,   //  458   13-05
    "UMAP_窗浇说6        "  ,   //  459   13-06
    "UMAP_窗浇说7        "  ,   //  460   13-07
    "UMAP_窗浇说8        "  ,   //  461   13-08
    "UMAP_窗浇说9        "  ,   //  462   13-09
    "UMAP_窗浇说10       "  ,   //  463   13-10
    "UMAP_窗浇说11       "  ,   //  464   13-11
    "UMAP_窗浇说12       "  ,   //  465   13-12
    "UMAP_窗浇说13       "  ,   //  466   13-13
    "UMAP_窗浇说14       "  ,   //  467   13-14
    "UMAP_窗浇说15       "  ,   //  468   13-15
    "UMAP_窗浇说16       "  ,   //  469   13-16
    "UMAP_窗浇说17       "  ,   //  470   13-17
    "UMAP_窗浇说18       "  ,   //  471   13-18
    "UMAP_窗浇说19       "  ,   //  472   13-19
    "UMAP_窗浇说20       "  ,   //  473   13-20
    "UMAP_窗浇说21       "  ,   //  474   13-21
    "UMAP_窗浇说22       "  ,   //  475   13-22
    "UMAP_窗浇说23       "  ,   //  476   13-23
    "UMAP_窗浇说24       "  ,   //  477   13-24
    "UMAP_窗浇说25       "  ,   //  478   13-25
    "UMAP_窗浇说26       "  ,   //  479   13-26
    "UMAP_窗浇说27       "  ,   //  480   13-27
    "UMAP_窗浇说28       "  ,   //  481   13-28
    "UMAP_窗浇说29       "  ,   //  482   13-29
    "UMAP_窗浇说30       "  ,   //  483   13-30
    "UMAP_窗浇说31       "  ,   //  484   13-31
    "UMAP_窗浇说32       "  ,   //  455   13-02
    "UMAP_窗浇说33       "  ,   //  456   13-33
    "UMAP_窗浇说34       "  ,   //  457   13-04
    "UMAP_窗浇说35       "  ,   //  458   13-05
    "UMAP_窗浇说36       "  ,   //  459   13-06
    "UMAP_窗浇说37       "  ,   //  460   13-07
    "UMAP_窗浇说38       "  ,   //  461   13-08
    "UMAP_窗浇说39       "  ,   //  462   13-09
    "UMAP_窗浇说40       "  ,   //  453   13-00
    "UMAP_窗浇说41       "  ,   //  454   13-01
    "UMAP_窗浇说42       "  ,   //  455   13-02
    "UMAP_窗浇说43       "  ,   //  456   13-33
    "UMAP_窗浇说44       "  ,   //  457   13-04
    "UMAP_窗浇说45       "  ,   //  458   13-05
    "UMAP_窗浇说46       "  ,   //  459   13-06
    "UMAP_窗浇说47       "  ,   //  460   13-07
    "UMAP_窗浇说48       "  ,   //  461   13-08
    "UMAP_窗浇说49       "  ,   //  462   13-09
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
	"Id PWRSAVE 绵抟 %   "	,	//	485   14-00	Ids Power Save Level
	"勒睬.逍谪       "	,	//	486   14-01	VF voltage mode selection
	"勒哒嗾余阕谪1     "	,	//	487   14-02	Constant Torque Selection
	"耙昧钒嫉椿      "	,	//	488   14-03	Auto Accel/Decel
	"翟.昧钒嫉椿 T     "	,	//	489   14-04	Unit of Acc/Dec time
	"勒洼锗愚嵫锗.     "	,	//	490   14-05	Power Save mode
	"颊廪噪踞庑蒉倚      "	,	//	491   14-06	Stop Methods
	"勒艺噌.嘈艳庑       "	,	//	492   14-07	Reverse Operation
	"苦捱汜1,艺噱Hz  "	,	//	493   14-08	Skip Freq. Point 1 upper limit
	"苦捱汜1,葚州Hz  "	,	//	494   14-09	Skip Freq. Point 1 lower limit
	"苦捱汜2,艺噱Hz  "	,	//	495   14-10	Skip Freq. Point 2 upper limit
	"苦捱汜2,葚州Hz  "	,	//	496   14-11	Skip Freq. Point 2 lower limit
	"苦捱汜3,艺噱Hz  "	,	//	497   14-12	Skip Freq. Point 3 upper limit
	"苦捱汜3,葚州Hz  "	,	//	498   14-13	Skip Freq. Point 3 lower limit
	"睫缧徕掴砸.2Hz  "	,	//	499   14-14	Motor Base Frequency 2
	"夹卺.菪哙镏.砸.2V   "	,	//	500   14-15	Max Output Voltage 2
	"拎.缧徕掴 砸.2Hz  "	,	//	501   14-16	Mid Output Freq.2 1
	"拎.菪哙镏.1 砸.2V   "	,	//	502   14-17	Mid Output Voltage 2 1
	"拎.缧徕掴 砸.2Hz  "	,	//	503   14-18	Mid Output Freq.2 2
	"拎.菪哙镏.2 砸.2V   "	,	//	504   14-19	Mid Output Voltage 2 2
	"钾缧徕掴砸.2Hz  "	,	//	505   14-20	Min Output Freq. 2
	"钾菪哙镏. 砸.2V   "	,	//	506   14-21	Min Output Voltage 2
	"勒谯幸.Up/Down    "	,	//	507   14-22	up/down key mode
	"邻捺.谯幸.Up/Dwn    "	,	//	508   14-23	up/down key speed
	"叫徕徵这缲谛      "	,	//	509   14-24	Counter Value Set (Complete)
	"冕庑徵这缲谛      "	,	//	510   14-25	Counter Value Reach (Preset)
	"?谛坜余休?      "	,	//	511   14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"簇嶷嗾廨. 义拊 9    "	,	//	512   14-27	Multi-Function Input 9
	"簇嶷嗾廨. 义拊 A    "	,	//	513   14-28	Multi-Function Input 10
	"簇嶷嗾廨. 义拊 B    "	,	//	514   14-29	Multi-Function Input 11
	"簇嶷嗾廨. 义拊 C    "	,	//	515   14-30	Multi-Function Input 12
	"簇嶷嗾廨. 义拊 D    "	,	//	516   14-31	Multi-Function Input 13
	"簇嶷嗾廨. 义拊 E    "	,	//	517   14-32	Multi-Function Input 14
	"簇嶷嗾廨. 义拊 B    "	,	//	518   14-33	External Terminal Run after Fault Reset
	"搽艳ACI/AVI2      "	,	//	519   14-34	ACI change to AVI2
	"崔咿圯剽.AI         "	,	//	520   14-35	Addition Function of AI
	"笺垤庳-咿棕       "	,	//	521   14-36	Multi-Position Point 1
	"笺垤庳-咿棕       "	,	//	522   14-37	Multi-Position Point 2
	"笺垤庳-咿棕       "	,	//	523   14-38	Multi-Position Point 3
	"笺垤庳-咿棕       "	,	//	524   14-39	Multi-Position Point 4
	"笺垤庳-咿棕       "	,	//	525   14-40	Multi-Position Point 5
	"笺垤庳-咿棕       "	,	//	526   14-41	Multi-Position Point 6
	"笺垤庳-咿棕       "	,	//	527   14-42	Multi-Position Point 7
	"笺垤庳-咿棕       "	,	//	528   14-43	Multi-Position Point 8
	"笺垤庳-咿棕       "	,	//	529   14-44	Multi-Position Point 9
	"笺垤庳-咿棕0      "	,	//	530   14-45	Multi-Position Point 10
	"笺垤庳-咿棕1      "	,	//	531   14-46	Multi-Position Point 11
	"笺垤庳-咿棕2      "	,	//	532   14-47	Multi-Position Point 12
	"笺垤庳-咿棕3      "	,	//	533   14-48	Multi-Position Point 13
	"笺垤庳-咿棕4      "	,	//	534   14-49	Multi-Position Point 14
	"笺垤庳-咿棕5      "	,	//	535   14-50	Multi-Position Point 15
	"搽艳砸赜. 1-2     "	,	//	536   14-51	Motor Selection 1 or 2
	"绵抟.亿Y-D    Hz  "	,	//	537   14-52	Y-Delta Connected switching rpm
	"佬奏砧蛰.Y-D        "	,	//	538   14-53	Y-Delta switched Enable
	"睫廪 砸赜.2 Amps"	,	//	539   14-54	Motor 2 rated Current
	"嫁檩掎忪 砸赜.2 Kw  "	,	//	540   14-55	Motor 2 Rated Power
	"睫缧徕掴砸.2RPM "	,	//	541   14-56	Motor 2 Rated RPM
	"?蒯圻捋钤?.2    "	,	//	542   14-57	Motor 2 pole No.
	"罗遛孕 砸.2 Amps"	,	//	543   14-58	Motor 2 No-Load Current
	"Rs 砸赜锈折   ohm "	,	//	544   14-59	Motor 2 Rs
	"Rr  砸赜锈折2 ohm "	,	//	545   14-60	Motor 2 Rr
	"Lm 砸赜锈折   mH  "	,	//	546   14-61	Motor 2 Lm
	"Lx 砸赜锈折   mH  "	,	//	547   14-62	Motor 2 Lx
	"沸哉嘀谛 Y-D        "	,	//	548   14-63	Y-Delta On delay time
	"拷葚宗.嶷-庳.绵 V   "	,	//	549   14-64	OV stall level
	"哇.庹咣.嗾壅 砸2    "	,	//	550   14-65	Thermal Relay 2 Selection
	"侧哲庹咣.嗾壅2    "	,	//	551   14-66	Thermal Relay 2 Time
	"勒汹 哙抟雄 U     "	,	//	552   14-67	Momentary Power Loss
	"侧哲哙抟雄U sec "	,	//	553   14-68	Max. allowable PL time
	"臂挹.嶝缧徕 sec "	,	//	554   14-69	BB Time for speed serach
	"居嗦挹锌拊逡邻捺%   "	,	//	555   14-70	Current level for SPD serach
	"臂挹燎菪徕噢      "	,	//	556   14-71	bb treatment for oc, ov, bb
	"耙廪勒徕朽        "	,	//	557   14-72	Auto restart after fault
	"颊廪岳蔗庑噔      "	,	//	558   14-73	Auto restart Speed serach method
	"DEB 沸苷咱. SEL     "	,	//	559   14-74	Deceleration at Momertary Power loss 
	"DEB 厕仔亦哲    "	,	//	560   14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561   14-76	PID feedback selection	
	"恨礓.P 扛嗾鱼   "	,	//	562   14-77	P gain of PID	
	"恨礓.I 扛嗾鱼踫ec "	,	//	563   14-78	I gain of PID	
	"恨礓.D 扛嗾鱼   "	,	//	564   14-79	D gain of PID	
	"舱抻嘈剌庹%   "	,	//	565   14-80	Upper bound for integral	
	"居嘈译缧徕掴%   "	,	//	566   14-81	PID output Freq. Limit	
	"淋臻蛰卣 扛   %   "	,	//	567   14-82	PID offset	
	"沸哉嘀谛 扛   sec "	,	//	568   14-83	Derivative Filter Time Constant	
	"侧哲掼匮谪 羢ec "	,	//	569   14-84	Feedback signal detection time	
	"勒汹咿庹嘭    "	,	//	570   14-85	PID feedback loss	
	"插拊 徇镩刭 嗾重    "	,	//	571   14-86	Sleep Frequency	
	"搽遛徇镩刭 嗾   "	,	//	572   14-87	Wake up Frequency	
	"沸哉嘀. 徇镩.嗾   "	,	//	573   14-88	Sleep Time	
	"夹卺. 掼匮谛 扛   "	,	//	574   14-89	PID Deviation Level	
	"侧哲掼匮谪 扛   "	,	//	575   14-90	PID Deviation Time	
	"呢垤忄  扛sec "	,	//	576   14-91	PID feedback filter	
	"沸孕葺酗 缧徕掴蠬z  "	,	//	577   14-92	Main Frequency from communication	
	"臂挹 哒嗾孕缲 1     "	,	//	578   14-93	Block Transfer 1	
	"臂挹 哒嗾孕缲 2     "	,	//	579   14-94	Block Transfer 2	
	"臂挹 哒嗾孕缲 3     "	,	//	580   14-95	Block Transfer 3
	"臂挹 哒嗾孕缲 4     "	,	//	581   14-96	Block Transfer 4
	"臂挹 哒嗾孕缲 5     "	,	//	582   14-97	Block Transfer 5
	"臂挹 哒嗾孕缲 6     "	,	//	583   14-98	Block Transfer 6
	"臂挹 哒嗾孕缲 7     "	,	//	584   14-99	Block Transfer 7
	"臂挹 哒嗾孕缲 8     "	,	//	585   14-100 Block Transfer 8
	"臂挹 哒嗾孕缲 9     "	,	//	586   14-101 Block Transfer 9
	"臂挹 哒嗾孕缲 10    "	,	//	587   14-102 Block Transfer 10
	"WEAKLPF             "	,	//	588   14-103 WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	589   14-104 WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	590   14-105 OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"哭棕洼崔      "	,	//	591   14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592   14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	593   14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	594   14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	595   14-110 FMax Target by Vcommand Position
	"勒渍嘁              "	,	//	596   14-111 Accel. Time for Position
	"?蒯圬?.嗾糟阝. A    "	,	//	597   14-112 PG Mechanical Gear A
	"份熊蛰锈.嗾糟   "	,	//	598   14-113 PG Mechanical Gear B
	"Jm 嶝徕哲 PU  PU  "	,	//	599   14-114 Interia of motor PU
	"M1IdsRef 哙赵折  %  "	,	//	600   14-115 Motor1 IdsRef Limit
	"M2IdsRef 哙赵折  %  "	,	//	601   14-116 Motor2 IdsRef Limit
	"狙嚯男侧哲sec "	,	//	602   14-117 Phase Loss Time
	"TH Inside 抡苓.  C  "	,	//	603   14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	604   14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	605   14-120 SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//	606   14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607   14-122 Tension of Torque Control
	"簇熊这           "	,	//	608   14-123 Diameter of Material
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
	"CAN_氵嘈役蛰卣      "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_苦抟锗_侧哲 sec "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_侧哲   ms  "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    "霸嗾壳 COM1       "	,	//	368   09-00	Comm Address           //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                      
	"邻捺掎忪 COM1   kbps"	,	//	369   09-01	Tranmission speed                         
	"勒汹.咿庹嘭COM1     "	,	//	370   09-02	Comm fault Treatment                      
	"滦佘-秀釩OM1    sec "	,	//	371   09-03	Comm Time out                             
	"苦掴挹捋 COM1       "	,	//	372   09-04	Comm Protocol                             
	"局卦. 嵋镒COM1ms  "	,	//	373   09-05	ASC remote Response Delay Time, 1=100us 
    "羚这静0虫         "	,	//	3XX   14-146    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "羚这静虫          "	,	//	3XX   14-147    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "羚这静虫          "	,	//	3XX   14-148    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "羚这静.5虫        "	,	//	3XX   14-149    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "羚这静.2虫        "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "冕刿.静           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "冕刿.静           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "冕刿.静           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
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
    "26加竚 蔼     m   "  , //  2XX 04-80   26Floor Position H                                      
    "26加竚      mm  "  , //  2XX 04-81   26Floor Position L                                      
    "27加竚 蔼     m   "  , //  2XX 04-82   27Floor Position H                                      
    "27加竚      mm  "  , //  2XX 04-83   27Floor Position L                                      
    "28加竚 蔼     m   "  , //  2XX 04-84   28Floor Position H                                      
    "28加竚      mm  "  , //  2XX 04-85   28Floor Position L                                      
    "29加竚 蔼     m   "  , //  2XX 04-86   29Floor Position H                                      
    "29加竚      mm  "  , //  2XX 04-87   29Floor Position L                                      
    "30加竚 蔼     m   "  , //  2XX 04-88   30Floor Position H                                      
    "30加竚      mm  "  , //  2XX 04-89   30Floor Position L                                      
    "31加竚 蔼     m   "  , //  2XX 04-90   31Floor Position H                                      
    "31加竚      mm  "  , //  2XX 04-91   31Floor Position L                                      
    "32加竚 蔼     m   "  , //  2XX 04-92   32Floor Position H                                      
    "32加竚      mm  "  , //  2XX 04-93   32Floor Position L                                      
    "33加竚 蔼     m   "  , //  2XX 04-94   33Floor Position H                                      
    "33加竚      mm  "  , //  2XX 04-95   33Floor Position L                                      
    "34加竚 蔼     m   "  , //  2XX 04-96   34Floor Position H                                      
    "34加竚      mm  "  , //  2XX 04-97   34Floor Position L                                      
    "35加竚 蔼     m   "  , //  2XX 04-98   35Floor Position H                                      
    "35加竚      mm  "  , //  2XX 04-99   35Floor Position L                                      
    "36加竚 蔼     m   "  , //  2XX 04-100   36Floor Position H
    "36加竚      mm  "  , //  2XX 04-101   36Floor Position L
    "37加竚 蔼     m   "  , //  2XX 04-102   37Floor Position H
    "37加竚      mm  "  , //  2XX 04-103   37Floor Position L
    "38加竚 蔼     m   "  , //  2XX 04-104   38Floor Position H
    "38加竚      mm  "  , //  2XX 04-105   38Floor Position L
    "39加竚 蔼     m   "  , //  2XX 04-106   39Floor Position H
    "39加竚      mm  "  , //  2XX 04-107   39Floor Position L
    "40加竚 蔼     m   "  , //  2XX 04-108   40Floor Position H
    "40加竚      mm  "  , //  2XX 04-109   40Floor Position L
    "41加竚 蔼     m   "  , //  2XX 04-110   41Floor Position H
    "41加竚      mm  "  , //  2XX 04-111   41Floor Position L
    "42加竚 蔼     m   "  , //  2XX 04-112   42Floor Position H
    "42加竚      mm  "  , //  2XX 04-113   42Floor Position L
    "43加竚 蔼     m   "  , //  2XX 04-114   43Floor Position H
    "43加竚      mm  "  , //  2XX 04-115   43Floor Position L
    "44加竚 蔼     m   "  , //  2XX 04-116   44Floor Position H
    "44加竚      mm  "  , //  2XX 04-117   44Floor Position L
    "45加竚 蔼     m   "  , //  2XX 04-118   45Floor Position H
    "45加竚      mm  "  , //  2XX 04-119   45Floor Position L
    "46加竚 蔼     m   "  , //  2XX 04-120   46Floor Position H
    "46加竚      mm  "  , //  2XX 04-121   46Floor Position L
    "47加竚 蔼     m   "  , //  2XX 04-122   47Floor Position H
    "47加竚      mm  "  , //  2XX 04-123   47Floor Position L
    "48加竚 蔼     m   "  , //  2XX 04-124   48Floor Position H
    "48加竚      mm  "  , //  2XX 04-125   48Floor Position L
    "49加竚 蔼     m   "  , //  2XX 04-126   49Floor Position H
    "49加竚      mm  "  , //  2XX 04-127   49Floor Position L
    "50加竚 蔼     m   "  , //  2XX 04-128   50Floor Position H
    "50加竚      mm  "  , //  2XX 04-129   50Floor Position L   
};

const string20 prinfo_tc_DLC2[DLC_TABLE] =
{               //[Modify DLC parameter, Bernie, 2016/01/22]
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"  */                                     
    "51加竚 蔼     m   "  , //  2XX 04-80   26Floor Position H                                      
    "51加竚      mm  "  , //  2XX 04-81   26Floor Position L                                      
    "52加竚 蔼     m   "  , //  2XX 04-82   27Floor Position H                                      
    "52加竚      mm  "  , //  2XX 04-83   27Floor Position L                                      
    "53加竚 蔼     m   "  , //  2XX 04-84   28Floor Position H                                      
    "53加竚      mm  "  , //  2XX 04-85   28Floor Position L                                      
    "54加竚 蔼     m   "  , //  2XX 04-86   29Floor Position H                                      
    "54加竚      mm  "  , //  2XX 04-87   29Floor Position L                                      
    "55加竚 蔼     m   "  , //  2XX 04-88   30Floor Position H                                      
    "55加竚      mm  "  , //  2XX 04-89   30Floor Position L                                      
    "56加竚 蔼     m   "  , //  2XX 04-90   31Floor Position H                                      
    "56加竚      mm  "  , //  2XX 04-91   31Floor Position L                                      
    "57加竚 蔼     m   "  , //  2XX 04-92   32Floor Position H                                      
    "57加竚      mm  "  , //  2XX 04-93   32Floor Position L                                      
    "58加竚 蔼     m   "  , //  2XX 04-94   33Floor Position H                                      
    "58加竚      mm  "  , //  2XX 04-95   33Floor Position L                                      
    "59加竚 蔼     m   "  , //  2XX 04-96   34Floor Position H                                      
    "59加竚      mm  "  , //  2XX 04-97   34Floor Position L                                      
    "60加竚 蔼     m   "  , //  2XX 04-98   35Floor Position H                                      
    "60加竚      mm  "  , //  2XX 04-99   35Floor Position L                                      
    "61加竚 蔼     m   "  , //  2XX 04-100   36Floor Position H
    "61加竚      mm  "  , //  2XX 04-101   36Floor Position L
    "62加竚 蔼     m   "  , //  2XX 04-102   37Floor Position H
    "62加竚      mm  "  , //  2XX 04-103   37Floor Position L
    "63加竚 蔼     m   "  , //  2XX 04-104   38Floor Position H
    "63加竚      mm  "  , //  2XX 04-105   38Floor Position L
    "64加竚 蔼     m   "  , //  2XX 04-106   39Floor Position H
    "64加竚      mm  "  , //  2XX 04-107   39Floor Position L
    "65加竚 蔼     m   "  , //  2XX 04-108   40Floor Position H
    "65加竚      mm  "  , //  2XX 04-109   40Floor Position L
    "66加竚 蔼     m   "  , //  2XX 04-110   41Floor Position H
    "66加竚      mm  "  , //  2XX 04-111   41Floor Position L
    "67加竚 蔼     m   "  , //  2XX 04-112   42Floor Position H
    "67加竚      mm  "  , //  2XX 04-113   42Floor Position L
    "68加竚 蔼     m   "  , //  2XX 04-114   43Floor Position H
    "68加竚      mm  "  , //  2XX 04-115   43Floor Position L
    "69加竚 蔼     m   "  , //  2XX 04-116   44Floor Position H
    "69加竚      mm  "  , //  2XX 04-117   44Floor Position L
    "70加竚 蔼     m   "  , //  2XX 04-118   45Floor Position H
    "70加竚      mm  "  , //  2XX 04-119   45Floor Position L
    "71加竚 蔼     m   "  , //  2XX 04-120   46Floor Position H
    "71加竚      mm  "  , //  2XX 04-121   46Floor Position L
    "72加竚 蔼     m   "  , //  2XX 04-122   47Floor Position H
    "72加竚      mm  "  , //  2XX 04-123   47Floor Position L
    "73加竚 蔼     m   "  , //  2XX 04-124   48Floor Position H
    "73加竚      mm  "  , //  2XX 04-125   48Floor Position L
    "74加竚 蔼     m   "  , //  2XX 04-126   49Floor Position H
    "74加竚      mm  "  , //  2XX 04-127   49Floor Position L
    "75加竚 蔼     m   "  , //  2XX 04-128   50Floor Position H
    "75加竚      mm  "  , //  2XX 04-129   50Floor Position L   
};

const string20 prinfo_tc_DLC3[DLC_TABLE] =
{
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"  */                                     
    "DDS1竚 蔼     m   "  ,                                    
    "DDS1竚      mm  "  ,                                      
    "DDS2竚 蔼     m   "  ,                                      
    "DDS2竚      mm  "  ,                                      
    "DDS3竚 蔼     m   "  ,                                      
    "DDS3竚      mm  "  ,                                    
    "DDS4竚 蔼     m   "  ,                                     
    "DDS4竚      mm  "  ,                                     
    "UDS1竚 蔼     m   "  ,                                     
    "UDS1竚      mm  "  ,                                
    "UDS2竚 蔼     m   "  ,                                   
    "UDS2竚      mm  "  ,                                     
    "UDS3竚 蔼     m   "  ,                                     
    "UDS3竚      mm  "  ,                                     
    "UDS4竚 蔼     m   "  ,                                   
    "UDS4竚      mm  "  ,                                    
    "玂痙                "  ,                                   
    "玂痙                "  ,                                    
    "玂痙                "  ,                                  
    "玂痙                "  ,                                   
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,
    "玂痙                "  ,  
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
  "26楼位置 高     m   "  , //  2XX 04-80   26Floor Position H                                      
  "26楼位置 低     mm  "  , //  2XX 04-81   26Floor Position L                                      
  "27楼位置 高     m   "  , //  2XX 04-82   27Floor Position H                                      
  "27楼位置 低     mm  "  , //  2XX 04-83   27Floor Position L                                      
  "28楼位置 高     m   "  , //  2XX 04-84   28Floor Position H                                      
  "28楼位置 低     mm  "  , //  2XX 04-85   28Floor Position L                                      
  "29楼位置 高     m   "  , //  2XX 04-86   29Floor Position H                                      
  "29楼位置 低     mm  "  , //  2XX 04-87   29Floor Position L                                      
  "30楼位置 高     m   "  , //  2XX 04-88   30Floor Position H                                      
  "30楼位置 低     mm  "  , //  2XX 04-89   30Floor Position L                                      
  "31楼位置 高     m   "  , //  2XX 04-90   31Floor Position H                                      
  "31楼位置 低     mm  "  , //  2XX 04-91   31Floor Position L                                      
  "32楼位置 高     m   "  , //  2XX 04-92   32Floor Position H                                      
  "32楼位置 低     mm  "  , //  2XX 04-93   32Floor Position L                                      
  "33楼位置 高     m   "  , //  2XX 04-94   33Floor Position H                                      
  "33楼位置 低     mm  "  , //  2XX 04-95   33Floor Position L                                      
  "34楼位置 高     m   "  , //  2XX 04-96   34Floor Position H                                      
  "34楼位置 低     mm  "  , //  2XX 04-97   34Floor Position L                                      
  "35楼位置 高     m   "  , //  2XX 04-98   35Floor Position H 
  "35楼位置 低     mm  "  , //  2XX 04-99   35Floor Position L 
  "36楼位置 高     m   "  , //  2XX 04-100   36Floor Position H
  "36楼位置 低     mm  "  , //  2XX 04-101   36Floor Position L
  "37楼位置 高     m   "  , //  2XX 04-102   37Floor Position H
  "37楼位置 低     mm  "  , //  2XX 04-103   37Floor Position L
  "38楼位置 高     m   "  , //  2XX 04-104   38Floor Position H
  "38楼位置 低     mm  "  , //  2XX 04-105   38Floor Position L
  "39楼位置 高     m   "  , //  2XX 04-106   39Floor Position H
  "39楼位置 低     mm  "  , //  2XX 04-107   39Floor Position L
  "40楼位置 高     m   "  , //  2XX 04-108   40Floor Position H
  "40楼位置 低     mm  "  , //  2XX 04-109   40Floor Position L
  "41楼位置 高     m   "  , //  2XX 04-110   41Floor Position H
  "41楼位置 低     mm  "  , //  2XX 04-111   41Floor Position L
  "42楼位置 高     m   "  , //  2XX 04-112   42Floor Position H
  "42楼位置 低     mm  "  , //  2XX 04-113   42Floor Position L
  "43楼位置 高     m   "  , //  2XX 04-114   43Floor Position H
  "43楼位置 低     mm  "  , //  2XX 04-115   43Floor Position L
  "44楼位置 高     m   "  , //  2XX 04-116   44Floor Position H
  "44楼位置 低     mm  "  , //  2XX 04-117   44Floor Position L
  "45楼位置 高     m   "  , //  2XX 04-118   45Floor Position H
  "45楼位置 低     mm  "  , //  2XX 04-119   45Floor Position L
  "46楼位置 高     m   "  , //  2XX 04-120   46Floor Position H
  "46楼位置 低     mm  "  , //  2XX 04-121   46Floor Position L
  "47楼位置 高     m   "  , //  2XX 04-122   47Floor Position H
  "47楼位置 低     mm  "  , //  2XX 04-123   47Floor Position L
  "48楼位置 高     m   "  , //  2XX 04-124   48Floor Position H
  "48楼位置 低     mm  "  , //  2XX 04-125   48Floor Position L
  "49楼位置 高     m   "  , //  2XX 04-126   49Floor Position H
  "49楼位置 低     mm  "  , //  2XX 04-127   49Floor Position L
  "50楼位置 高     m   "  , //  2XX 04-128   50Floor Position H
  "50楼位置 低     mm  "  , //  2XX 04-129   50Floor Position L

};

const string20 prinfo_sc_DLC2[DLC_TABLE] = {	
  /*---- GROUP 04---------------------------------------*/						
  /*  "12345678901234561234"	*/					
  "51楼位置 高     m   "  , //  2XX 04-80   26Floor Position H                                      
  "51楼位置 低     mm  "  , //  2XX 04-81   26Floor Position L                                      
  "52楼位置 高     m   "  , //  2XX 04-82   27Floor Position H                                      
  "52楼位置 低     mm  "  , //  2XX 04-83   27Floor Position L                                      
  "53楼位置 高     m   "  , //  2XX 04-84   28Floor Position H                                      
  "53楼位置 低     mm  "  , //  2XX 04-85   28Floor Position L                                      
  "54楼位置 高     m   "  , //  2XX 04-86   29Floor Position H                                      
  "54楼位置 低     mm  "  , //  2XX 04-87   29Floor Position L                                      
  "55楼位置 高     m   "  , //  2XX 04-88   30Floor Position H                                      
  "55楼位置 低     mm  "  , //  2XX 04-89   30Floor Position L                                      
  "56楼位置 高     m   "  , //  2XX 04-90   31Floor Position H                                      
  "56楼位置 低     mm  "  , //  2XX 04-91   31Floor Position L                                      
  "57楼位置 高     m   "  , //  2XX 04-92   32Floor Position H                                      
  "57楼位置 低     mm  "  , //  2XX 04-93   32Floor Position L                                      
  "58楼位置 高     m   "  , //  2XX 04-94   33Floor Position H                                      
  "58楼位置 低     mm  "  , //  2XX 04-95   33Floor Position L                                      
  "59楼位置 高     m   "  , //  2XX 04-96   34Floor Position H                                      
  "59楼位置 低     mm  "  , //  2XX 04-97   34Floor Position L                                      
  "60楼位置 高     m   "  , //  2XX 04-98   35Floor Position H 
  "60楼位置 低     mm  "  , //  2XX 04-99   35Floor Position L 
  "61楼位置 高     m   "  , //  2XX 04-100   36Floor Position H
  "61楼位置 低     mm  "  , //  2XX 04-101   36Floor Position L
  "62楼位置 高     m   "  , //  2XX 04-102   37Floor Position H
  "62楼位置 低     mm  "  , //  2XX 04-103   37Floor Position L
  "63楼位置 高     m   "  , //  2XX 04-104   38Floor Position H
  "63楼位置 低     mm  "  , //  2XX 04-105   38Floor Position L
  "64楼位置 高     m   "  , //  2XX 04-106   39Floor Position H
  "64楼位置 低     mm  "  , //  2XX 04-107   39Floor Position L
  "65楼位置 高     m   "  , //  2XX 04-108   40Floor Position H
  "65楼位置 低     mm  "  , //  2XX 04-109   40Floor Position L
  "66楼位置 高     m   "  , //  2XX 04-110   41Floor Position H
  "66楼位置 低     mm  "  , //  2XX 04-111   41Floor Position L
  "67楼位置 高     m   "  , //  2XX 04-112   42Floor Position H
  "67楼位置 低     mm  "  , //  2XX 04-113   42Floor Position L
  "68楼位置 高     m   "  , //  2XX 04-114   43Floor Position H
  "68楼位置 低     mm  "  , //  2XX 04-115   43Floor Position L
  "69楼位置 高     m   "  , //  2XX 04-116   44Floor Position H
  "69楼位置 低     mm  "  , //  2XX 04-117   44Floor Position L
  "70楼位置 高     m   "  , //  2XX 04-118   45Floor Position H
  "70楼位置 低     mm  "  , //  2XX 04-119   45Floor Position L
  "71楼位置 高     m   "  , //  2XX 04-120   46Floor Position H
  "71楼位置 低     mm  "  , //  2XX 04-121   46Floor Position L
  "72楼位置 高     m   "  , //  2XX 04-122   47Floor Position H
  "72楼位置 低     mm  "  , //  2XX 04-123   47Floor Position L
  "73楼位置 高     m   "  , //  2XX 04-124   48Floor Position H
  "73楼位置 低     mm  "  , //  2XX 04-125   48Floor Position L
  "74楼位置 高     m   "  , //  2XX 04-126   49Floor Position H
  "74楼位置 低     mm  "  , //  2XX 04-127   49Floor Position L
  "75楼位置 高     m   "  , //  2XX 04-128   50Floor Position H
  "75楼位置 低     mm  "  , //  2XX 04-129   50Floor Position L

};

// JINGDO
const string20 prinfo_sc_DLC3[DLC_TABLE] = {
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/                                     
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
