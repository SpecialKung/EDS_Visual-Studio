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
	"Cmd Freq. REC.  Hz  ",	   // 2120H  Error Fcmd      
	"Out Freq. REC.  Hz  ",	   // 2121H  Error Fout      
	"Isum Value REC. Amps",	   // 2122H  Error Isum      
	"Motor Freq. REC.Hz  ",	   // 2123H  Error Ffbk      
	"Out Voltage REC.V   ",	   // 2124H  Error Vout      
	"DcBus Value REC.V   ",	   // 2125H  Error Vbus      
	"Out Power REC.  KW  ",	   // 2126H  Error Power     
	"Out Torque REC. %   ",	   // 2127H  Error Torque    
	"IGBT Temp. REC. C   ",	   // 2128H  Error IGBT Temp.
	"DI State REC.   Hex ",	   // 2129H  Error MI State  
	"DO State REC.   Hex ",	   // 212AH  Error MO State  
	"Drive State REC.Hex ",	   // 212BH  Error Drive St.    
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
    "Cmd Freq. REC.  Hz  ",    //32 2220H  Error Fcmd      
    "Out Freq. REC.  Hz  ",    //33 2221H  Error Fout      
    "Isum Value REC. Amps",    //34 2222H  Error Isum      
    "Motor Freq. REC.Hz  ",    //35 2223H  Error Ffbk      
    "Out Voltage REC.V   ",    //36 2224H  Error Vout      
    "DcBus Value REC.V   ",    //37 2225H  Error Vbus      
    "Out Power REC.  KW  ",    //38 2226H  Error Power     
    "Out Torque REC. %   ",    //39 2227H  Error Torque    
    "IGBT Temp. REC. C   ",    //40 2228H  Error IGBT Temp.
    "DI State REC.   Hex ",    //41 2229H  Error MI State  
    "DO State REC.   Hex ",    //42 222AH  Error MO State  
    "Drive State REC.Hex ",    //43 222BH  Error Drive St.    
      
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
    "DLC Ctrl Method DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
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
	"AFE Error Lock  AEL ",    //97  //[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_TC
const string20 errinfo_tc[(ERRMAX+1)]={
//   12345678901234561234   //
    "No error            ",    //0
    "�[�t���L�q�y    ocA ",    //1
    "��t���L�q�y    ocd ",    //2
    "�w�t�B�त�L�q�yocn ",    //3
    "���a�L�q�y      GFF ",    //4
    "IGBT�W�U���u��  occ ",    //5
    "����L�q�y    ocS ",    //6
    "�[�t���L�q��    ovA ",    //7    
    "��t���L�q��    ovd ",    //8
    "�w�t�B�त�L�q��ovn ",    //9
    "����L�q��    ovS ",    //10
    "�[�t���C�q��    LvA ",    //11
    "��t���C�q��    Lvd ",    //12
    "�w�t�B�त�C�q��Lvn ",    //13
    "����C�q��    LvS ",    //14
    "�J�q��۫O�@    PHL ",    //15
    "IGBT�ū׹L��    oH1 ",    //16
    "�q���q�e�ū׹L��oH2 ",    //17
    "IGBT�ūװ������`tH1o",    //18
    "�q�e�ūװ������`tH2o",    //19
    "�������`        FAn ",    //20
    "�X�ʾ��L�t��    oL  ",    //21
    "�q���L�t��      EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "�q���L��        oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "�L��x1         ot1 ",    //26
    "�L��x2         ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "�O����g�J���`  cF1 ",    //30
    "�O����Ū�X���`  cF2 ",    //31
    "Isum�q�y�������`cd0 ",    //32
    "U�۹q�y�������` cd1 ",    //33
    "V�۹q�y�������` cd2 ",    //34
    "W�۹q�y�������` cd3 ",    //35
    "CC�w��u�����`  Hd0 ",    //36
    "OC�w��u�����`  Hd1 ",    //37
    "OV�w��u�����`  Hd2 ",    //38
    "GFF�w��u�����` Hd3 ",    //39
    "�q���۰ʶq�����~AUE ",    //40
    "PID �^�¿��~    AFE ",    //41
    "PG�^�²��`      PGF1",    //42
    "PG�^���_�u      PGF2",    //43
    "PG�^�¥��t      PGF3",    //44
    "PG��t���`      PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "�~�����~�T����JEF  ",    //49
    "�~���ݤl��氱��EF1 ",    //50
    "Base Block      bb  ",    //51
    "�K�X��J�T�����~Pcod",    //52
    "SW Code Error   ccod",    //53
    "���X�k�q�T�R�O  cE01",    //54
    "���X�k�q�T��}  cE02",    //55
    "�q�T��ƪ��׿��~cE03",    //56
    "�q�T�g�J��Ū��mcE04",    //57
    "MODBUS�ǿ�W��  cE10",    //58
    "KEYPAD�ǿ�W��  cP10",    //59
    "�����٨����鲧�`BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "�w���j�����`    SRY ",    //63  add by dino, 06/06/2007
    "����٨��^�²��`MBF ",    //64  add by dino, 05/14/2008
    "PG�w�鰻�����`  PGF5",    //65
    "�q�ϱ�Ĳ�����`  MCF ",    //66
    "��X���        MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus �_�u    CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "�q��L�[�t��    PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "�w����x��1   STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd�u�����`   PGcd",    //73  [Safty function, Bernie, 2013/10/29]
    "PG ����T�����` PGHL",    //74
    "PG Z�۰T����  PGAF",    //75
    "�w����x��X����STO ",    //76
    "�w����x��2   STL2",    //77
    "�w����x��3   STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "�A�ȹO��        SERV",    //81
    "��X��� U��    OPHL",    //82
    "��X��� V��    OPHL",    //83
    "��X��� W��    OPHL",    //84
    "DLC����Ҧ����~ DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "���h�}���u��    LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "���h�}���}��    LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "�q�y������`  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "�w����x�j���g�HSTL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "�w����x��X����STOr",    //90  //#12225,STO error at running 
    "�w����x�j���g�HSTOS",    //91  //#12225,STO Short error
    "Sensor817 ���~  SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 ���~  SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTT ����         btt",    //94	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT ���~        bttE",    //95  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE���~��w     AEL ",    //97  [AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_SC
const string20 errinfo_sc[(ERRMAX+1)]={
//   12345678901234561234   //
    "No error            ",    //0
    "�����й�����    ocA ",    //1
    "�����й�����    ocd ",    //2
    "������ת�й�����ocn ",    //3
    "�ӵع�����      GFF ",    //4
    "IGBT�����Ŷ�·  occ ",    //5
    "ֹͣ�й�����    ocS ",    //6
    "�����й���ѹ    ovA ",    //7    
    "�����й���ѹ    ovd ",    //8
    "������ת�й���ѹovn ",    //9
    "ֹͣ�й���ѹ    ovS ",    //10
    "�����е͵�ѹ    LvA ",    //11
    "�����е͵�ѹ    Lvd ",    //12
    "������ת�е͵�ѹLvn ",    //13
    "ֹͣ�е͵�ѹ    LvS ",    //14
    "���Ƿ�ౣ��    PHL ",    //15
    "IGBT�¶ȹ���    oH1 ",    //16
    "��Դ�����¶ȹ���oH2 ",    //17
    "IGBT�¶�����쳣tH1o",    //18
    "�����¶�����쳣tH2o",    //19
    "�����쳣        FAn ",    //20
    "����������      oL  ",    //21
    "���������      EoL1",    //22
    "Thermal Realy 2 EoL2",    //23
    "�������        oH3 ",    //24
    "Fuse Error      FuSE",    //25
    "��ת��1         ot1 ",    //26
    "��ת��2         ot2 ",    //27
    "Under Torque 1  uc1 ",    //28
    "Under Torque 2  uc2 ",    //29
    "������д���쳣  cF1 ",    //30
    "����������쳣  cF2 ",    //31
    "Isum��������쳣cd0 ",    //32
    "U���������쳣 cd1 ",    //33
    "V���������쳣 cd2 ",    //34
    "W���������쳣 cd3 ",    //35
    "CCӲ����·�쳣  Hd0 ",    //36
    "OCӲ����·�쳣  Hd1 ",    //37
    "OVӲ����·�쳣  Hd2 ",    //38
    "GFFӲ����·�쳣 Hd3 ",    //39
    "����Զ��������AUE ",    //40
    "PID ���ڴ���    AFE ",    //41
    "PG�����쳣      PGF1",    //42
    "PG���ڶ���      PGF2",    //43
    "PG����ʧ��      PGF3",    //44
    "PGת���쳣      PGF4",    //45
    "PG Ref Error    PGr1",    //46
    "PG Ref Loss     PGr2",    //47
    "ACI Loss        ACE ",    //48
    "�ⲿ����Ѷ������EF  ",    //49
    "�ⲿ���ӽ���ֹͣEF1 ",    //50
    "Base Block      bb  ",    //51
    "�����������δ���Pcod",    //52
    "SW Code Error   ccod",    //53
    "���Ϸ�ͨѶ����  cE01",    //54
    "���Ϸ�ͨѶλַ  cE02",    //55
    "ͨѶ���ϳ��ȴ���cE03",    //56
    "ͨѶд��Ψ��λ��cE04",    //57
    "MODBUS���䳬ʱ  cE10",    //58
    "KEYPAD���䳬ʱ  cP10",    //59
    "���ɷ�������쳣BF  ",    //60
    "Y-Delta Connect ydc ",    //61   
    "Dec. Energy BackdEb ",    //62   
    "��ȫ��·�쳣    SRY ",    //63  add by dino, 06/06/2007
    "��еɷ�������쳣MBF ",    //64  add by dino, 05/14/2008
    "PGӲ������쳣  PGF5",    //65
    "��ŽӴ����쳣  MCF ",    //66
    "���Ƿ��        MPHL",    //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN Bus ����    CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "���ݹ����ٶ�    PGOA",    //71  [Safty function, Bernie, 2013/10/29]
    "��ȫת����ʧ1   STL1",    //72  [Safty function, Bernie, 2013/10/29]
    "PG cd��·�쳣   PGcd",    //73
    "PG ����Ѷ���쳣 PGHL",    //74
    "PG Z��Ѷ����ʧ  PGAF",    //75
    "��ȫת�����ֹͣSTO ",    //76
    "��ȫת����ʧ2   STL2",    //77
    "��ȫת����ʧ3   STL3",    //78
    "                    ",    //79
    "                    ",    //80
    "������ʱ        SERV",    //81
    "���Ƿ�� U��    OPHL",    //82
    "���Ƿ�� V��    OPHL",    //83
    "���Ƿ�� W��    OPHL",    //84
    "DLC����ģʽ���� DLCC",    //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "ƽ�㿪�ض�·    LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "ƽ�㿪�ؿ�·    LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "�����������쳣  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "��ȫת�ػ�·մ�STL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "��ȫת�����ֹͣSTOr",    //90  //#12225,STO error at running 
    "��ȫת�ػ�·մ�STOS",    //91  //#12225,STO Short error
    "Sensor817 ����  SnE7",	   //92  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"Sensor818 ����  SnE8",	   //93  //[Artemis Add Sensor819 Function/Special/2022/06/06]
	"BTT ʧ��         btt",    //94	 //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT ����        bttE",    //95  //BTT Test Error for reset FWD/REV [JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTT No Action   bttn",    //96  //BTT No Action [JES Torq Detect Function, Special.Kung, 2022/09/01]
	"AFE��������     AEL ",    //97  //[AFE Error Handle/Lyabryan/2022/03/24]

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
	"AFE Error Lock  AEL ",    //97  //[AFE Error Handle/Lyabryan/2022/03/24]
};
#endif

#if Language_RUS
const string20 errinfo_rus[(ERRMAX+1)]={
//   12345678901234561234   //
    "��������          ",      //0
    "����.����.����ocA ",      //1
    "����.����.����ocd ",      //2
    "����.����.��    ocn ",    //3
    "������ ���� GFF ",        //4
    "�������� ���� occ ",      //5
    "����.����.����ocS ",      //6
    "����.����.����ovA ",      //7    
    "����.����.����ovd ",      //8
    "����.����.��    ovn ",    //9
    "����.����.����ovS ",      //10
    "������.���� LvA ",        //11
    "������.���� Lvd ",        //12
    "������.��     Lvn ",      //13
    "������.���� LvS ",        //14
    "������ ��. ���� PHL ",    //15
    "�������� IGBT   oH1 ",    //16
    "�������� ����.  oH2 ",    //17
    "����.��������1tH1o",      //18
    "����.��������2tH2o",      //19
    "����.����.      FAn ",    //20
    "�������� �� ����oL  ",    //21
    "����.������ ��1 EoL1",    //22
    "����.������ ��2 EoL2",    //23
    "�������� ������.oH3 ",    //24
    "����.������   FuSE",      //25
    "������. ������ot1 ",      //26
    "������. ������ot2 ",      //27
    "��������.������ uc1 ",    //28
    "��������.������ uc2 ",    //29
    "��.EEPROM��   cF1 ",      //30
    "��.EEPROM����   cF2 ",    //31
    "��.�������� cd0 ",        //32
    "����.�� U-����  cd1 ",    //33
    "����.�� V-����  cd2 ",    //34
    "����.�� W-����  cd3 ",    //35
    "���������� �c Hd0 ",      //36
    "���������� oc Hd1 ",      //37
    "���������� ov Hd2 ",      //38
    "���������� occHd3 ",      //39
    "������ ���������AUE ",    //40
    "��������ؿ��AFE ",        //41
    "������  PG  PGF1",        //42
    "������  PG  PGF2",        //43
    "����  PG    PGF3",        //44
    "����.������.PG  PGF4",    //45
    "����. �� ��.PGPGr1",      //46
    "������ ����.PGPGr2",      //47
    "������ ����. ACIACE ",    //48
    "����.����.������EF  ",    //49
    "�������������EF1 ",      //50
    "����.�������� bb  ",      //51
    "�������� ������ Pcod",    //52
    "������ ���� ��  ccod",    //53
    "������������cE01",        //54
    "������������cE02",        //55
    "������.������ cE03",      //56
    "������ ������   cE04",    //57
    "����������  cE10",        //58
    "������������  cP10",      //59
    "����.����.������BF  ",    //60
    "����.��Y-�����ydc ",      //61   
    "��������,   dEb ",        //62   
    "�������� ����   SRY ",    //63  add by dino, 06/06/2007
    "����.������   MBF ",      //64  add by dino, 05/14/2008
    "������PG����PGF5",        //65
    "����. ����������MCF ",    //66
    "��������.����.MPHL",      //67  added by sampo, for MPHL Detect ,05/12/2009
    "CAN ���� ����.  CANF",    //68  [CAN Control, Sampo, 09/15/2010]
    "                    ",    //69  [Safty function, Bernie, 2013/10/29]
    "                    ",    //70  [Safty function, Bernie, 2013/10/29]
    "������      PGOA",        //71  [Safty function, Bernie, 2013/10/29]
    "��������      STL1",      //72  [Safty function, Bernie, 2013/10/29]
    "��ѿ������    PGcd",      //73  [Safty function, Bernie, 2013/10/29]
    "��Ѱ��.����.��PGHL",      //74
    "���������Z      PGAF",    //75
    "���߾��ۼ�����  STO ",    //76
    "���� �� STO2  STL2",      //77
    "���� �� STO3  STL3",      //78
    "                    ",    //79
    "                    ",    //80
    "�������� ��   SERV",      //81
    "���� U ����     OPHL",    //82
    "���� V ����     OPHL",    //83
    "���� W ����     OPHL",    //84 
    "DLC Ctrl MethodDLCC",     //85  //#15266, Can't do Tuning without setting PG_TYPE, James, 20201201
    "Lv Sensor Short LSS ",    //86  //#15977, LULD detect, James, 2021/04/01
    "Lv Sensor Open  LSO ",    //87  //#15977, LULD detect, James, 2021/04/01
    "Cur. Ctrl. Err  CLCE",    //88  //#16434 MPHL improvement, Jerry, 2021/06/30
    "��ȫת�ػ�·մ�STL4",    //89  //#12225,STOL4 Short Error, power on to reset
    "��ȫת�����ֹͣSTOr",    //90  //#12225,STO error at running 
    "��ȫת�ػ�·մ�STOS",    //91  //#12225,STO Short error  
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
	"Direct Landing  dLc1", //warncode = 51  //IO�����ɧǲ��` //Task 268622 IO Direct Landing	//Mitong 20230221 add	
};
#endif

#if Language_TC
const string20 warninfo_tc[(WARNMAX+1)]={
//   12345678901234561234   //
    "No error            ",
    "���X�k�q�T�R�O  cE01", //warncode = 1
    "���X�k�q�T��}  cE02", //warncode = 2
    "�q�T��ƪ��׿��~cE03", //warncode = 3
    "�q�T�g�J��Ū��}cE04", //warncode = 4
    "Modbus�ǿ�W��  cE10", //warncode = 5
    "Keypad�ǿ�W��  cP10", //warncode = 6
    "�Ѽƽƻs���~    SE1 ", //warncode = 7
    "�Ѽƽƻs����    SE2 ", //warncode = 8
    "IGBT�L��        oH1 ", //warncode = 9
    "�q�e�L��        oH2 ", //warncode = 10
    "PID  �^�²��`   Pid ", //warncode = 11
    "����T�����`    AnL ", //warncode = 12
    "�q�y�L�C        uC  ", //warncode = 13
    "�ѼƦ۾ǲߥ���  AuE ", //warncode = 14
    "PG�^�²��`      PGF1", //warncode = 15
    "PG�^���_�u      PGF2", //warncode = 16
    "PG�^�¥��t      PGF3", //warncode = 17
    "PG��t���`      PGF4", //warncode = 18
    "��J���        PHL ", //warncode = 19
    "�L��x 1        ot1 ", //warncode = 20
    "�L��x 2        ot2 ", //warncode = 21
    "�q���L��        oH3 ", //warncode = 22
    "C.C Warning     c.c ", //warncode = 23
    "�Ʈt���`        oSL ", //warncode = 24
    "�ѼƦ۾ǲߤ�    tUn ", //warncdoe = 25
    "�������`        FAn ", //warncode = 26
    "Can Bus �_�u    dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]
    "�w����x��ĵ�iSTOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "UCMP ����ĵ�i   UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "���ؤ��P�ƻs���~SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "�A�ȹO��        SERV", //warncode = 31
    "DLC��V�R�O���~  dir", //warncode = 32  //Artemis DLC Reverse direction command Issue, James, 2020/01/16
    "�W1�űj��L�t   UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "�W2�űj��L�t   UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "�W3�űj��L�t   UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "�W4�űj��L�t   UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "�U1�űj��L�t   DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "�U2�űj��L�t   DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "�U3�űj��L�t   DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "�U4�űj��L�t   DDS4", //warncode = 40  // DD4_Vlim_WARN  
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "���h�}���H�����`LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STO�ɧǲ��`     STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STO�g�H         STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "Sensor817 ĵ�i  SnW7",	//warncode = 46
	"Sensor818 ĵ�i  SnW8",	//warncode = 47
	"BTTx ���դ�     bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx ���`       bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx ���\\      bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"IO�����ɧǲ��`  dLc1", //warncode = 51  //Task 268622 IO Direct Landing	//Mitong 20230221 add	
};
#endif

#if Language_SC
const string20 warninfo_sc[(WARNMAX+1)]={
//   12345678901234561234   //
    "No error            ",
    "���Ϸ�ͨѶ����  cE01", //warncode = 1                                                                       
    "���Ϸ�ͨѶλַ  cE02", //warncode = 2                                                                       
    "ͨѶ���ϳ��ȴ���cE03", //warncode = 3                                                                       
    "ͨѶд��Ψ��λַcE04", //warncode = 4                                                                       
    "Modbus���䳬ʱ  cE10", //warncode = 5                                                                       
    "Keypad���䳬ʱ  cP10", //warncode = 6                                                                       
    "�������ƴ���    SE1 ", //warncode = 7                                                                       
    "��������ʧ��    SE2 ", //warncode = 8                                                                       
    "IGBT����        oH1 ", //warncode = 9                                                                       
    "���ݹ���        oH2 ", //warncode = 10                                                                      
    "PID  �����쳣   Pid ", //warncode = 11                                                                      
    "���Ѷ���쳣    AnL ", //warncode = 12                                                                      
    "��������        uC  ", //warncode = 13                                                                      
    "������ѧϰʧ��  AuE ", //warncode = 14                                                                      
    "PG�����쳣      PGF1", //warncode = 15                                                                      
    "PG���ڶ���      PGF2", //warncode = 16                                                                      
    "PG����ʧ��      PGF3", //warncode = 17                                                                      
    "PGת���쳣      PGF4", //warncode = 18                                                                      
    "����Ƿ��        PHL ", //warncode = 19                                                                      
    "��ת�� 1        ot1 ", //warncode = 20                                                                      
    "��ת�� 2        ot2 ", //warncode = 21                                                                      
    "�������        oH3 ", //warncode = 22                                                                      
    "C.C Warning     c.c ", //warncode = 23                                                                      
    "�����쳣        oSL ", //warncode = 24                                                                      
    "������ѧϰ��    tUn ", //warncdoe = 25                                                                      
    "�����쳣        FAn ", //warncode = 26                                                                      
    "Can Bus ����    dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]                                //Sampo, 09/15/2010]
    "��ȫת����ʧ����STOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]//warncode = 28
    "UCMP ִ�о���   UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "���ֲ�ͬ���ƴ���SE3 ", //warncode = 30  COPY Fail 3, Model name Error   
    "������ʱ        SERV", //warncode = 31
    "��1��ǿ������   UDS1", //warncode = 33  // UD1_Vlim_WARN   //Artemis speed limit, James, 20200220
    "��2��ǿ������   UDS2", //warncode = 34  // UD2_Vlim_WARN    
    "��3��ǿ������   UDS3", //warncode = 35  // UD3_Vlim_WARN    
    "��4��ǿ������   UDS4", //warncode = 36  // UD4_Vlim_WARN    
    "��1��ǿ������   DDS1", //warncode = 37  // DD1_Vlim_WARN    
    "��2��ǿ������   DDS2", //warncode = 38  // DD2_Vlim_WARN    
    "��3��ǿ������   DDS3", //warncode = 39  // DD3_Vlim_WARN    
    "��4��ǿ������   DDS4", //warncode = 40  // DD4_Vlim_WARN  
    "Exist FWD & REV EFRn", //warncode = 41  //[exist FWD/REV Warn, Jason, 2019/10/07]
    "Stop Short STO  SOS ", //warncode = 42  //[Sibocom SOS Warn, James, 2020/04/28]
    "ƽ�㿪���ź��쳣LS  ", //warncode = 43  //#15977, LULD detect, James, 2021/04/01
    "STOʱ���쳣     STOb", //warncode = 44  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14
    "STOմ�         STOc", //warncode = 45  //#12225,STO short detect, James for 04-49=4~7, 2021/10/14 
    "Sensor817 ����  SnW7",	//warncode = 46
	"Sensor818 ����  SnW8",	//warncode = 47
	"BTTx ������     bttA", //warncode = 48  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Normal     bttn", //warncode = 49  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"BTTx Success    bttS", //warncode = 50  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
	"IOֱͣʱ���쳣  dLc1", //warncode = 51  //IO�����ɧǲ��` //Task 268622 IO Direct Landing	//Mitong 20230221 add	
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
	"Direct Landing  dLc1", //warncode = 51  //IO�����ɧǲ��` //Task 268622 IO Direct Landing	//Mitong 20230221 add	
};
#endif

#if Language_RUS
const string20 warninfo_rus[(WARNMAX+1)]={
//   12345678901234561234   //
    "��������          ",
    "�������� �������cE01", //warncode = 1
    "�������� ���� cE02",   //warncode = 2
    "�������� ���� cE03",   //warncode = 3
    "����������cE04",       //warncode = 4
    "����������  cE10",     //warncode = 5
    "������������  cP10",   //warncode = 6
    "������ ������ SE1 ",   //warncode = 7
    "������ ������ SE2 ",   //warncode = 8
    "�������� IGBT   oH1 ", //warncode = 9
    "�������� ������.oH2 ", //warncode = 10
    "������  ��Pid ",       //warncode = 11
    "����������.   AnL ",   //warncode = 12
    "������ ��     uC  ",   //warncode = 13
    "������ ��������.AuE ", //warncode = 14
    "������  PG  PGF1",     //warncode = 15
    "������  PG  PGF2",     //warncode = 16
    "����  PG    PGF3",     //warncode = 17
    "����.������.    PGF4", //warncode = 18
    "������ ����. ���PHL ", //warncode = 19
    "������. ������ot1 ",   //warncode = 20
    "������. ������ot2 ",   //warncode = 21
    "�������� ������.oH3 ", //warncode = 22
    "����������.´   c.c ", //warncode = 23
    "������.������.  oSL ", //warncode = 24
    "������������  tUn ",   //warncdoe = 25
    "����.����. Fan  FAn ", //warncode = 26
    "CAN ����. ����. dCAn", //warncode = 27  //[CAN Control, Sampo, 09/15/2010]
    "����������.STO  STOA", //warncode = 28  //[STO function add Warning code and run rule, Bernie, 2016/03/22]
    "����������UCMP  UCMP", //warncode = 29  //[UCMP function, Bernie, 2016/06/14]
    "����.���������SE3 ",   //warncode = 30  COPY Fail 3, Model name Error   
    "����������  SERV",     //warncode = 31
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
	"Direct Landing  dLc1", //warncode = 51  //IO�����ɧǲ��` //Task 268622 IO Direct Landing	//Mitong 20230221 add	
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
    "�t�ΰѼ�        00  ",     //  Group 13
    "�򥻰Ѽ�        01  ",     //  Group  0
    "�Ʀ�ݤl�\\��    02  ",    //  Group  1
    "����ݤl�\\��    03  ",    //  Group  2
    "�h�q�t�Ѽ�      04  ",     //  Group  3
    "IM �q���Ѽ�     05  ",     //  Group  4
    "�O�@�Ѽ�        06  ",     //  Group  5
    "�S��Ѽ�        07  ",     //  Group  6
    "PM ���F�Ѽ�     08  ",     //  Group  7
    "�q�T�Ѽ�        09  ",     //  Group  8
    "�t�צ^�°Ѽ�    10  ",     //  Group  9
    "�i���Ѽ�        11  ",     //  Group 10
    "�Τ�۩w�ѼƳ]�w12  ",     //  Group 11
    "�Τ�]�w�ѼƬd�\\13  ",    //  Group 12                  
    "RESERVED        14  ",     //  Group 14
    "FACTORY         15  ",     //  Group 15
};
#endif

#if Language_SC
const string20 gpname_sc[GRALL+1]={   // Prarmeter Group Description
   //12345678901234561234
    "ϵͳ����        00  ",     //  Group 13
    "��������        01  ",     //  Group  0
    "��λ���ӹ���    02  ",     //  Group  1
    "��ȶ��ӹ���    03  ",     //  Group  2
    "����ٲ���      04  ",     //  Group  3
    "IM �������     05  ",     //  Group  4
    "��������        06  ",     //  Group  5
    "�������        07  ",     //  Group  6
    "PM ������     08  ",     //  Group  7
    "ͨѶ����        09  ",     //  Group  8
    "�ٶȻ��ڲ���    10  ",     //  Group  9
    "�߼�����        11  ",     //  Group 10
    "�û��Զ������  12  ",     //  Group 11
    "�û��趨������ѯ13  ",     //  Group 12
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
    "����������  00  ",	       //  Group  0
    "����������  01  ",	       //  Group  1
    "����. ��/��   02  ",	   //  Group  2
    "������.��/��  03  ",	   //  Group  3
    "�û�¸-������¸ 04  ",	   //  Group  4
    "���������µ�05  ",	       //  Group  5
    "������ɸ��    06  ",	   //  Group  6
    "����. ����    07  ",	   //  Group  7
    "����. �����µ�08  ",	   //  Group  8
    "������Ϸ    09  ",	       //  Group  9
    "����ͽ������  10  ",	   //  Group 10
    "����������  11  ",	       //  Group 11
    "��������ÿ  12  ",	       //  Group 12
    "���¿��̷�  13  ",	       //  Group 13
    "������������    14  ",	   //  Group 14
    "��������    15  ",	       //  Group 15
    
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
	"RESERVE             "	,	//	128 15-128  RESERVED
//	"PPI filter point    "	,	//	128 15-128  PPI control    //[PPI function, Sampo, 2015/09/08]
    "RESERVE             "	,	//	129 15-129  RESERVED

/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
	"Identity Code       "	,	//	130 00-00	Model Type of Drive 
	"Rated Current   Amps"	,	//	131 00-01	Rated Current
	"Parameter Reset     "	,	//	132 00-02	Parameter Reset
	"Start up Display    "	,	//	133 00-03	Start up Display
	"User Display        "	,	//	134 00-04	User Display
	"User Coefficient    "	,	//	135	00-05	User Coefficient
	"Firmware Version    "	,	//	136	00-06	Software Version
	"Password decoder    "	,	//	137	00-07	Password Input
	"Password Input      "	,	//	138	00-08	Password Input
	"Control Method      "	,	//	139	00-09	Control Methods
	"Speed Unit Sel.     "	,	//	140	00-10	Velocity Unit Select
	"CHG. Output DIR     "	,	//	141 00-11   Change Output Direction, Added by sampo , 06/11/2009
	"Carry Frequency KHz "	,	//	142	00-12	Carry Frequency
	"AVR                 "	,	//	143	00-13	AVR
	"Source of Freq.     "	,	//	144	00-14	Source of Freq. Command
	"Source of Oper.     "	,	//	145	00-15	Source of Oper. Command

    "RESERVE             "	,	//	146 00-16   RESERVED
    "RESERVE             "	,	//	147 00-17   RESERVED
    "RESERVE             "	,	//	148 00-18   RESERVED
    "RESERVE             "	,	//	149 00-19   RESERVED

/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"Max Output Freq.Hz  "	,	//	150	01-00	Max Output Freq.
	"Motor1 Fbase    Hz  "	,	//	151	01-01	Motor Base Frequency 1
	"Max Out-Volt 1  V   "	,	//	152	01-02	Max Output Voltage
	"Mid Out-Freq.1-1Hz  "	,	//	153	01-03	Mid Output Freq.1
	"Mid Out-Volt 1-1V   "	,	//	154	01-04	Mid Output Voltage 1
	"Mid Out-Freq.1-2Hz  "	,	//	155	01-05	Mid Output Freq.2
	"Mid Out-Volt 1-2V   "	,	//	156	01-06	Mid Output Voltage 2
	"Min Out-Freq.1  Hz  "	,	//	157	01-07	Min Output Freq.
	"Min Out-Volt 1  V   "	,	//	158	01-08	Min Output Voltage
	"Start Frequency Hz  "	,	//	159	01-09	Start Frequency
	"Upper Bound FreqHz  "	,	//	160	01-10	Upper Bound Freq.
	"Lower Bound FreqHz  "	,	//	161	01-11	Lower Bound Freq.
	"1st Accel Time  sec "	,	//	162	01-12	1st Acceleration time
	"1st Decel Time  sec "	,	//	163	01-13	1st Deceleration time
	"2nd Accel Time  sec "	,	//	164	01-14	2nd Acceleration time
	"2nd Decel Time  sec "	,	//	165	01-15	2nd Deceleration time
	"3rd Accel Time  sec "	,	//	166	01-16	3rd Acceleration time
	"3rd Decel Time  sec "	,	//	167	01-17	3rd Deceleration time
	"4th Accel Time  sec "	,	//	168	01-18	4th Acceleration time
	"4th Decel Time  sec "	,	//	169	01-19	4th Deceleration time
	"JOG Accel Time  sec "	,	//	170	01-20	JOG Acceleration time
	"JOG Decel Time  sec "	,	//	171	01-21	JOG Deceleration time
	"JOG Frequency   Hz  "	,	//	172	01-22	JOG Frequency
	"Trans ACC/DEC1-4Hz  "	,	//	173	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"S Curve Time 1  sec "	,	//	174	01-24	S curve Accel time 1
	"S Curve Time 2  sec "	,	//	175	01-25	S curve Accel time 2
	"S Curve Time 3  sec "	,	//	176	01-26	S curve Decel time 1
	"S Curve Time 4  sec "	,	//	177	01-27	S curve Decel time 2
	"Select Zero Spd     "	,	//	178	01-28	Select Zero Speed
	"Landing Speed   Hz  "	,	//	179	01-29	Landing Frequency 
	"S Curve Time 5  sec "	,	//	180	01-30	S curve Decel time 3
	"Stop Decel Time sec "	,	//	181	01-31	Stop Deceleration time
    "Force Decel Spd m/s "	,	//	182	01-32
    "IOD Hold Time   sec "	,	//	183	01-33   IODHT IO direct hold time   
    "IOD Land Time   sec "	,	//	184	01-34   IODLT IO direct landing freq
    "CRPLS Jerk lim      "	,	//	185	01-35   IODLT IO direct landing time
    "IOD Dec Point   cm  "	,	//	186	01-36   IODLT IO direct DistancE
    "IOD D.Point Ref m   "	,	//	187	01-37   IODLT IO direct DistancE
    "IODLC Enable        "	,	//	188	01-38   IODLT IO direct DistancE
    "ETS Frequency   Hz  "  ,   //  189 01-39   IODLT IO direct DistancE
    "ESD Decel Time  sec "	,	//	190	01-40   IODLT IO direct DistancE
    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  191 01-41  RESERVED
    "Emergency S3    sec "  ,   //  192 01-42  RESERVED
    "Emergency S4    sec "  ,   //  193 01-43  RESERVED
#else
    "RESERVE             "	,	//	191 01-41   RESERVED
    "RESERVE             "	,	//	192 01-42   RESERVED
    "RESERVE             "	,	//	193 01-43   RESERVED
#endif    
    "IODLC TRIGGE SPDHz  "  ,   //	194 01-44   MI direct stop trigger speed		//Task 268622 IO Direct Landing	//Mitong 20230221 add	
    "RESERVE             "	,	//	195 01-45   RESERVED
    "RESERVE             "	,	//	196 01-46   RESERVED
    "RESERVE             "	,	//	197 01-47   RESERVED
    "RESERVE             "	,	//	198 01-48   RESERVED
    "RESERVE             "	,	//	199 01-49   RESERVED
    
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"2/3 wire Control    "	,	//	200	02-00	2/3 wire control                
	"Multi-Fun Input1    "	,	//	201	02-01	Multi-Function Input 1          
	"Multi-Fun Input2    "	,	//	202	02-02	Multi-Function Input 2          
	"Multi-Fun Input3    "	,	//	203	02-03	Multi-Function Input 3          
	"Multi-Fun Input4    "	,	//	204	02-04	Multi-Function Input 4          
	"Multi-Fun Input5    "	,	//	205	02-05	Multi-Function Input 5          
	"Multi-Fun Input6    "	,	//	206	02-06	Multi-Function Input 6          
	"Multi-Fun Input7    "	,	//	207	02-07	Multi-Function Input 7          
	"Multi-Fun Input8    "	,	//	208	02-08	Multi-Function Input 8		    
	"D-In Response T sec "	,	//	209	02-09	Digital in response time		
	"Multi-Input ACT     "	,	//	210	02-10	Multi-Function Input Inverse	
	"Multi-Fun RLY1      "	,	//	211	02-11	Multi-Function Relay 1		    
	"Multi-Fun RLY2      "	,	//	212	02-12	Multi-Function Relay 2		    
	"Multi-Fun RLY3      "	,	//	213	02-13	Multi-Function Output 1		    
	"Multi-Fun RLY4      "	,	//	214	02-14	Multi-Function Output 2		    
	"Multi-Fun Out 1     "	,	//	215	02-15	Multi-Function Output 1		    
	"Multi-Fun Out 2     "	,	//	216	02-16	Multi-Function Output 2		    
	"Multi-Fun Out 3     "	,	//	217	02-17	Multi-Function Output 1		    
	"Multi-Fun Out 4     "	,	//	218	02-18	Multi-Function Output 2		    
	"Multi-Fun Out 5     "	,	//	219	02-19	Multi-Function Output 1		    
	"Multi-Fun Out 6     "	,	//	220	02-20	Multi-Function Output 2		    
	"Multi-Fun Out 7     "	,	//	221	02-21	Multi-Function Output 1		    
	"Multi-Fun Out 8     "	,	//	222	02-22	Multi-Function Output 2		    
	"Multi-Output ACT    "	,	//	223	02-23	Multi-Function Output inverse	
    "Seq. Start Mode     "  ,   //  224 02-24   Sequence start mode
	"DESIRE-FREQ1    Hz  "	,	//	225	02-25	Desired Frequency 1		        
	"DESIRE-FREQ1 BNDHz  "	,	//	226	02-26	Band of Desired Frequency 1		
	"DESIRE-FREQ2    Hz  "	,	//	227	02-27	Desired Frequency 2		        
	"DESIRE-FREQ2 BNDHz  "	,	//	228	02-28	Band of Desired Frequency 2		
	"Brake RUN Delay sec "	,	//	229	02-29	Brake Delay Timer at run
	"Brake STOP Delaysec "	,	//	230	02-30	Brake Delay Timer at stop
	"MCDELAY_RUN Timesec "	,	//	231	02-31	Mech Contact Delay Timer run
	"MCDELAY_STP Timesec "	,	//	232	02-32	Mech Contact Delay Timer stop				            
	"Current Detect  %   "	,	//	233	02-33	Isum Current Output Detect	    
	"Speed Area Set  Hz  "	,	//	234	02-34	Speed Area
	"Brake CHK Time  sec "	,	//	235 02-35	Mechanical Brake Checking Time
	"MC CHK Time     sec "	,	//	236 02-36   Magnetic Contactor Checking Time
	"Torque Prove En     "  ,   //  237 02-37   Mechanical Brake Checking Current Enable
	"SCDELAY RUN Timesec "  ,   //  238 02-38   Star Contactor delay time when driver run    //[Star contactor function, Bernie, 2017/03/22]
	"SCDELAY STP Timesec "  ,   //  239 02-39   Star Contactor delay time when driver stop   //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD Fault SEL     "  ,   //  240 02-40   LU/LD error  Selection	                     //#15977, LULD detect, James, 2021/04/01
	"LU/LD Open Det. sec "  ,   //  241 02-41   LD/LD Open Detect Time                       //#15977, LULD detect, James, 2021/04/01
	"LU/LD Short Det.sec "  ,   //  242 02-42   LD/LD Short Detect Time                      //#15977, LULD detect, James, 2021/04/01
	"SPEED-REACH BND Hz  "	,   //  243 02-43   Band of Speed Agree Function                 //#18572
    "STO Short Det   sec "  ,   //  244 02-44   STO shor detect time                         //#18196  STO new function for SIL2, James, 2021/10/06    
    "819 Sensor          "  ,   //  245 02-45   819 Sensor                                   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Speed Limit     m/s "  ,   //  246 02-46   Speed Limit                                  //[Artemis Add Sensor819 Function/Special/2022/06/06]

    "RESERVE             "	,	//	247 02-47   RESERVED
    "RESERVE             "	,	//	248 02-48   RESERVED
    "RESERVE             "	,	//	249 02-49   RESERVED
    "RESERVE             "	,	//	250 02-50   RESERVED
    "RESERVE             "	,	//	251 02-51   RESERVED
    "RESERVE             "	,	//	252 02-52   RESERVED
    "RESERVE             "	,	//	253 02-53   RESERVED
    "RESERVE             "	,	//  254 02-54   RESERVED
    "RESERVE             "	,	//	255 02-55   RESERVED
    "RESERVE             "	,	//	256 02-56   RESERVED
    "RESERVE             "	,	//	257 02-57   RESERVED
    "RESERVE             "	,	//	258 02-58   RESERVED
    "RESERVE             "	,	//	259 02-59   RESERVED
    "RESERVE             "	,	//	260 02-60   RESERVED
    "RESERVE             "	,	//	261 02-61   RESERVED
    "RESERVE             "	,	//	262 02-62   RESERVED
    "RESERVE             "	,	//	263 02-63   RESERVED
    "RESERVE             "	,	//  264 02-64   RESERVED
    "RESERVE             "	,	//	265 02-65   RESERVED
    "RESERVE             "	,	//	266 02-66   RESERVED
    "RESERVE             "	,	//	267 02-67   RESERVED
    "RESERVE             "	,	//	268 02-68   RESERVED
    "RESERVE             "	,	//	269 02-69   RESERVED
    "RESERVE             "	,	//	270 02-70   RESERVED
    "RESERVE             "	,	//	271 02-71   RESERVED
    "RESERVE             "	,	//	272 02-72   RESERVED
    "RESERVE             "	,	//	273 02-73   RESERVED
    "RESERVE             "	,	//  274 02-74   RESERVED
    "RESERVE             "	,	//	275 02-75   RESERVED
    "RESERVE             "	,	//	276 02-76   RESERVED
    "RESERVE             "	,	//	277 02-77   RESERVED
    "RESERVE             "	,	//	278 02-78   RESERVED
    "RESERVE             "	,	//	279 02-79   RESERVED
    "RESERVE             "	,	//	280 02-80   RESERVED
    "RESERVE             "	,	//	281 02-81   RESERVED
    "RESERVE             "	,	//	282 02-82   RESERVED
    "RESERVE             "	,	//	283 02-83   RESERVED
    "RESERVE             "	,	//  284 02-84   RESERVED
    "RESERVE             "	,	//	285 02-85   RESERVED
    "RESERVE             "	,	//	286 02-86   RESERVED
    "RESERVE             "	,	//	287 02-87   RESERVED
    "RESERVE             "	,	//	288 02-88   RESERVED
    "RESERVE             "	,	//	289 02-89   RESERVED
    "RESERVE             "	,	//	280 02-90   RESERVED
    "RESERVE             "	,	//	291 02-91   RESERVED
    "RESERVE             "	,	//	292 02-92   RESERVED
    "RESERVE             "	,	//	293 02-93   RESERVED
    "RESERVE             "	,	//  294 02-94   RESERVED
    "RESERVE             "	,	//	295 02-95   RESERVED
    "RESERVE             "	,	//	296 02-96   RESERVED
    "RESERVE             "	,	//	297 02-97   RESERVED
    "RESERVE             "	,	//	298 02-98   RESERVED
    "RESERVE             "	,	//	299 02-99   RESERVED

/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"AUI1 Selection      "	,	//	300	03-00   AUI1 selection                  //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	301	03-01   ACI  selection                  //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Selection      "	,	//  302	03-02   AUI2 selection                  //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Input Bias %   "	,	//	303	03-03   AUI1 input Bias                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	307	03-04   ACI  input Bias                 //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Input Bias %   "	,	//	305	03-05   AUI2 input Bias                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Bias Mode      "	,	//	306 03-06   AUI1 input Polarity             //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	307 03-07   ACI  input Polarity             //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Bias Mode      "	,	//	308 03-08   AUI2 input Polarity             //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Input Gain %   "	,	//	309 03-09   AUI1 input Gain                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	310 03-10   ACI  input Gain                 //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Input Gain %   "	,	//	311 03-11   AUI2 input Gain                 //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 Input LPF  sec "	,	//	312 03-12   Low pass filter of AUI1 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"RESERVED            "	,	//	313 03-13   Low pass filter of ACI  input   //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 Input LPF  sec "	,	//	314 03-14   Low pass filter of AUI2 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"Load Cell Tune      "	,	//	315 03-15   Loss of ACI                     //[ACI function remove, Bernie, 01/20/2012]
    "RESERVED            "  ,   //  316 03-16   RESERVED
	"AO1 Setting         "	,	//	317 03-17   Analong Output 1
	"AO1 Gain        %   "	,	//	318 03-18   Analong Output 1 Gain
	"AO1 In Minus        "	,	//	319 03-19   AO1 in minus value
	"AO2 Setting         "	,	//	320 03-20   Analong Output 2
	"AO2 Gain        %   "	,	//	321 03-21   Analong Output 2 Gain
	"AO2 In Minus        "	,	//	322 03-22   AO2 in minus value
	"AUI1 Input Polar    "	,	//	323 03-23   AUI1 Input Polar                //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI2 Input Polar    "	,	//	324 03-24   AUI2 Input Polar                //[AI chenge to AUI, Lyabryan, 03/27/2015]
	//"AUI1 In Setting     "	,	//	325  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2 In Setting     "	,	//	326  03-26    AUI2 Communciate
	
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "Multi-Speed 0   Hz  "  ,   //  327 04-00   Multi-Speed 0
    "Multi-Speed 1   Hz  "  ,   //  328 04-01   Multi-Speed 1
    "Multi-Speed 2   Hz  "  ,   //  329 04-02   Multi-Speed 2
    "Multi-Speed 3   Hz  "  ,   //  330 04-03   Multi-Speed 3
    "Multi-Speed 4   Hz  "  ,   //  331 04-04   Multi-Speed 4
    "Multi-Speed 5   Hz  "  ,   //  332 04-05   Multi-Speed 5
    "Multi-Speed 6   Hz  "  ,   //  333 04-06   Multi-Speed 6
    "Multi-Speed 7   Hz  "  ,   //  334 04-07   Multi-Speed 7
    "Multi-Speed 8   Hz  "  ,   //  345 04-08   Multi-Speed 8
    "Multi-Speed 9   Hz  "  ,   //  346 04-09   Multi-Speed 9
    "Multi-Speed 10  Hz  "  ,   //  347 04-10   Multi-Speed 10
    "Multi-Speed 11  Hz  "  ,   //  348 04-11   Multi-Speed 11
    "Multi-Speed 12  Hz  "  ,   //  349 04-12   Multi-Speed 12
    "Multi-Speed 13  Hz  "  ,   //  350 04-13   Multi-Speed 13
    "Multi-Speed 14  Hz  "  ,   //  351 04-14   Multi-Speed 14
    "Multi-Speed 15  Hz  "  ,   //  352 04-15   Multi-Speed 15
    "Rescue Speed    m/s "  ,   //  353 04-16
    "Level Speed     m/s "  ,   //  354 04-17
    "Back Home Spd   m/s "  ,   //  355 04-18
	
    "Rope Slip Comp. mm  "  ,   //  356 04-19   GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //  357 04-20
    "TABST2 Status       "  ,   //  358 04-21
	
    "Max Floor           "  ,   //  359 04-22
    "Current Floor       "  ,   //  360 04-23
    "PG Revise PCT   %   "  ,   //  361 04-24
    "Sensor Delay Cmpsec "  ,   //  362 04-25
    "DLC Delay Time  ms  "  ,   //  363 04-26
    "Plank Length    mm  "  ,   //  364 04-27 
    "Current Pos. H  m   "  ,   //  365 04-28
    "Current Pos. L  mm  "  ,   //  366 04-29
    "Current PG H        "  ,   //  367 04-30 
    "Current PG L        "  ,   //  368 04-31
    "Plank PG H          "  ,   //  369 04-32
    "Plank PG L          "  ,   //  370 04-33
    "Sensor PG H         "  ,   //  371 04-34
    "Sensor PG L         "  ,   //  372 04-35    
    "DLC Function        "  ,   //  373 04-36
    "PDO TYPE            "  ,   //  374 04-37
    "Dec SW Tol. Gap mm  "  ,   //  375 04-38
    "% of Max Spd    %   "  ,   //  376 04-39   //[ADCO EPS Modify]
    "Spring Extend   mm  "  ,   //  377 04-40   //#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //  378 04-41
    "EST Count           "  ,   //  379 04-42
    "TABST0 Count        "  ,   //  380 04-43
    "TABST1 Count        "  ,   //  381 04-44
    "DDS1/UDS1Spd Limm/s "  ,   //  382 04-45   DD1_Vlim  //Artemis speed limit, James, 20200220                          
    "DDS2/UDS2Spd Limm/s "  ,   //  383 04-46   DD2_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS3/UDS3Spd Limm/s "  ,   //  384 04-47   DD3_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS4/UDS4Spd Limm/s "  ,   //  385 04-48   DD4_Vlim  //Artemis speed limit, James, 20200220
    "DLC user page       "  ,   //  386 04-49   user page cahnge
    
    "1F Position H   m   "  ,   //  387 04-50   1Floor Position H                                       
    "1F Position L   mm  "  ,   //  388 04-51   1Floor Position L                                       
    "2F Position H   m   "  ,   //  389 04-52   2Floor Position H                                       
    "2F Position L   mm  "  ,   //  390 04-53   2Floor Position L                                       
    "3F Position H   m   "  ,   //  391 04-54   3Floor Position H                                       
    "3F Position L   mm  "  ,   //  392 04-55   3Floor Position L                                       
    "4F Position H   m   "  ,   //  393 04-56   4Floor Position H                                       
    "4F Position L   mm  "  ,   //  394 04-57   4Floor Position L                                       
    "5F Position H   m   "  ,   //  395 04-58   5Floor Position H                                       
    "5F Position L   mm  "  ,   //  396 04-59   5Floor Position L                                       
    "6F Position H   m   "  ,   //  397 04-60   6Floor Position H                                       
    "6F Position L   mm  "  ,   //  398 04-61   6Floor Position L                                       
    "7F Position H   m   "  ,   //  399 04-62   7Floor Position H                                       
    "7F Position L   mm  "  ,   //  400 04-63   7Floor Position L                                       
    "8F Position H   m   "  ,   //  401 04-64   8Floor Position H                                       
    "8F Position L   mm  "  ,   //  402 04-65   8Floor Position L                                       
    "9F Position H   m   "  ,   //  403 04-66   9Floor Position H                                       
    "9F Position L   mm  "  ,   //  404 04-67   9Floor Position L                                       
    "10F Position H  m   "  ,   //  405 04-68   10Floor Position H                                      
    "10F Position L  mm  "  ,   //  406 04-69   10Floor Position L                                      
    "11F Position H  m   "  ,   //  407 04-70   11Floor Position H                                      
    "11F Position L  mm  "  ,   //  408 04-71   11Floor Position L                                      
    "12F Position H  m   "  ,   //  409 04-72   12Floor Position H                                      
    "12F Position L  mm  "  ,   //  410 04-73   12Floor Position L                                      
    "13F Position H  m   "  ,   //  411 04-74   13Floor Position H                                      
    "13F Position L  mm  "  ,   //  412 04-75   13Floor Position L                                      
    "14F Position H  m   "  ,   //  413 04-76   14Floor Position H                                      
    "14F Position L  mm  "  ,   //  414 04-77   14Floor Position L                                      
    "15F Position H  m   "  ,   //  415 04-78   15Floor Position H                                      
    "15F Position L  mm  "  ,   //  416 04-79   15Floor Position L                                      
    "16F Position H  m   "  ,   //  417 04-80   16Floor Position H                                      
    "16F Position L  mm  "  ,   //  418 04-81   16Floor Position L                                      
    "17F Position H  m   "  ,   //  419 04-82   17Floor Position H                                      
    "17F Position L  mm  "  ,   //  420 04-83   17Floor Position L                                      
    "18F Position H  m   "  ,   //  421 04-84   18Floor Position H                                      
    "18F Position L  mm  "  ,   //  422 04-85   18Floor Position L                                      
    "19F Position H  m   "  ,   //  423 04-86   19Floor Position H                                      
    "19F Position L  mm  "  ,   //  424 04-87   19Floor Position L                                      
    "20F Position H  m   "  ,   //  425 04-88   20Floor Position H                                      
    "20F Position L  mm  "  ,   //  426 04-89   20Floor Position L                                      
    "21F Position H  m   "  ,   //  427 04-90   21Floor Position H                                      
    "21F Position L  mm  "  ,   //  428 04-91   21Floor Position L                                      
    "22F Position H  m   "  ,   //  429 04-92   22Floor Position H                                      
    "22F Position L  mm  "  ,   //  430 04-93   22Floor Position L                                      
    "23F Position H  m   "  ,   //  431 04-94   23Floor Position H                                      
    "23F Position L  mm  "  ,   //  432 04-95   23Floor Position L                                      
    "24F Position H  m   "  ,   //  433 04-96   24Floor Position H                                      
    "24F Position L  mm  "  ,   //  434 04-97   24Floor Position L                                      
    "25F Position H  m   "  ,   //  435 04-98   25Floor Position H                                      
    "25F Position L  mm  "  ,   //  436 04-99   25Floor Position L                                     
   
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
	"IM Auto-Tuning      "	,	//	437 05-00	Motor Auto-Tuning
	"IM Motor Rated AAmps"	,	//	438 05-01	Motor 1 rated Current           
	"IM Motor Rated PKw  "	,	//	439 05-02	Motor 1 Rated Power             
	"IM Motor Rated  RPM "	,	//	440 05-03	Motor 1 Rated RPM               
	"IM Motor Poles      "	,	//	441 05-04	Motor 1 pole No.                
	"IM Motor No-LoadAmps"	,	//	442 05-05	Motor 1 No-Load Current         
	"IM Motor Rs     ohm "	,	//	443 05-06	Motor 1 Rs                      
	"IM Motor Rr     ohm "	,	//	444 05-07	Motor 1 Rr                      
	"IM Motor Lm      mH "	,	//	445 05-08	Motor 1 Lm                      
	"IM Motor Lx      mH "	,	//	446 05-09	Motor 1 Lx                      
	"SVC Volt. LPF   sec "	,	//	447 05-10	Vector Voltage Filter	        
	"SVC Slip LPF    sec "	,	//	448 05-11	Vector Slip Filter	            
	"TQR Comp Gain       "	,	//	449 05-12	Torque Compensation Gain	    
	"Slip Comp Gain      "	,	//	450 05-13	Slip Compensation Gain	        
	"Slip Deviation L%   "	,	//	451 05-14	Slip Deviation level	        
	"Slip Deviation Tsec "	,	//	452 05-15	Slip Deviation Detect Time	    
	"Over Slip Way       "	,	//	453 05-16	Over Slip treatment	            
	"HUNTING COEFF       "	,	//	454 05-17	Coeff for hunting disable	    
	"Cumulative Run  Mins"	,	//	455 05-18	Accumulative Motor Operation Min
	"Cumulative Run  Days"	,	//	456 05-19	Accumulative Motor Operation Day
	"Core Loss       %   "	,	//	457 05-20	Coreloss % of output Power	    
	"Power On Min    Mins"	,	//	458 05-21	Power On Min
	"Power On Day    Days"	,	//	459 05-22	Power On Day
    "GEN Slip Gain   %   "	,   //  460 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"Motor Slip Gain %   "	,	//	461 05-24   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
	"Low Voltage     V   "	,	//	462 06-00	Low voltage level
	"Phase loss          "	,	//	463 06-01	Phase loss
	"OCA Level       %   "	,	//	464 06-02	OC stall during Accel
	"OCN Level       %   "	,	//	465 06-03	OC stall during Decel
	"Stall AccDec SEL    "	,	//  466 06-04	Stall preventation Accel/Decel time selection
	"OL2 selection       "	,	//	467 06-05	Over-Torque 1 Selection
	"OverTorque Level%   "	,	//	468 06-06	Over-Torque 1 level
	"Over-Torque Timesec "	,	//	469 06-07	Over-Torque 1 Time
	"OL3 selection       "	,	//	470 06-08	Over-Torque 2 Selection	                     
	"OverLoad 3 Level%   "	,	//	471 06-09	Over-Torque 2 level	                         
	"OverLoad 3 Time sec "	,	//	472 06-10	Over-Torque 2 Time	                         
	"TQR LIMIT       %   "	,	//	473 06-11	Current Limit
	"Thermal RLY1 SEL    "	,	//	474 06-12	Thermal Relay 1 Selection
	"Thermal RLY1 T  sec "	,	//	475 06-13	Thermal Relay 1 Time
	"OH Warning Level C  "	,	//	476 06-14	OH Warning Level
	"Stall Level Limt%   "	,	//	477 06-15	Stall preventation Limit Level
	"1st Fault Record    "	,	//	478 06-16	1st Fault Record
	"2nd Fault Record    "	,	//	479 06-17	2nd Fault Record
	"3rd Fault Record    "	,	//	480 06-18	3rd Fault Record
	"4th Fault Record    "	,	//	481 06-19	4th Fault Record
	"5th Fault Record    "	,	//	482 06-20	5th Fault Record
	"6th Fault Record    "	,	//	483 06-21	6th Fault Record
	"Fault Option 1      "	,	//	484 06-22	Fault Option 1
	"Fault Option 2      "	,	//	485 06-23	Fault Option 2
	"Fault Option 3      "	,	//	486 06-24	Fault Option 3
	"Fault Option 4      "	,	//	487 06-25	Fault Option 4
	"PTC Treatments      "	,	//	488 06-26	PTC over Treatments	                         
	"PTC Level       %   "	,	//	489 06-27	PTC Level
	"PTC Detect FT   sec "	,	//	490 06-28	PTC Detect Filter time
	"EPS Voltage     V   "	,	//	491 06-29	EPS voltage level
	"Fault Option MOD    "	,	//	492 06-30	Fault Option Mode
	"Output Detection    "	,	//	493 06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
	"1st Fault Time  Mins"	,	//	494 06-32	1st Fault Time(MIN)
	"1st Fault Time  Days"	,	//	495 06-33	1st Fault Time(DAY)
	"2nd Fault Time  Mins"	,	//	496 06-34	2nd Fault Time(MIN)
	"2nd Fault Time  Days"	,	//	497 06-35	2nd Fault Time(DAY)
	"3rd Fault Time  Mins"	,	//	498 06-36	3rd Fault Time(MIN)
	"3rd Fault Time  Days"	,	//	499 06-37	3rd Fault Time(DAY)
	"4th Fault Time  Mins"	,	//	500 06-38	4th Fault Time(MIN)
	"4th Fault Time  Days"	,	//	501 06-39	4th Fault Time(DAY)
	"5th Fault Time  Mins"	,	//	502 06-40	5th Fault Time(MIN)
	"5th Fault Time  Days"	,	//	503 06-41	5th Fault Time(DAY)
	"6th Fault Time  Mins"	,	//	504 06-42	6th Fault Time(MIN)
	"6th Fault Time  Days"	,	//	505 06-43	6th Fault Time(DAY)
    "EPS Speed       Hz  "  ,   //  506 06-44	EPS Frequency
    "ERR Option MOD  BIN "  ,	//  507 06-45   LV Option Mode
    "EPS Option MOD      "  ,	//  508 06-46   EPS Option Mode
    "GEN SCAN TIME   sec "  ,   //  509 06-47   Generation Operation Detected Time
    "UPS CAPACITY    KVA "  ,   //  510 06-48   UPS Capacity (0.1KVA)
    "STO Func. select    "  ,   //  511 06-49   STO Lock selection     //[Safty function, Bernie] 
    "Restart Select      "	,   //  512 06-50   Base Block Speed Search (oc,ov,occ.......)  //[Add auto restart after fault, Bernie, 06/06/12]
    "Auto Restart T  sec "  ,   //  513 06-51   Auto restart times after fault     
    "Restart Intervalsec "  ,   //  514 06-52   Auto restart interval
    "Cmd Freq. REC.  Hz  "	,	//	515 06-53   Fkey Record
    "Out Freq. REC.  Hz  "	,	//	516 06-54   Fcmd Record"Out Freq. REC.  Hz  "	,	    //	94 	15-94   Fcmd Record
    "Isum Value REC. Amps"	,	//	517 06-55	Isum Record
    "Motor Freq. REC.Hz  "	,	//	518 06-56	Fout Record
    "Out Voltage REC.V   "	,	//	519 06-57	Vout Record
	"DcBus Value REC.V   "	,   //  520 06-58	Dcbus Record  
	"Out Power REC.  KW  "	,	//	521 06-59   Power Record
	"Out Torque REC. %   "	,	//	522 06-60   Torque Record
	"IGBT Temp. REC.  C  "	,	//	523 06-61	IGBT Temperature Record    
	"DI State REC.   Hex "	,	//	524 06-62   MFI State Record
	"DO State REC.   Hex "	,	//	525 06-63   MFO State Record
	"Drive State REC.Hex "	,	//	526 06-64   Drive State Record
	"UCMP Curnt limit%   "  ,   //  527 06-65   Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
	"Service times       "  ,   //  528 06-66   Service time count                          //[Service time function, Bernie, 2017/03/14]
	"Service Enable      "  ,   //  529 06-67   Service time function Enable                //[Service time function, Bernie, 2017/03/14]
    "EPS Detect PF   deg "  ,   //  530 06-68   EPS Detect Current    
    "EPS PF angle    deg "  ,   //  531 06-69   EPS Detect Current Ref
    "EPS Direction       "  ,   //  532 06-70   EPS Detect direction
    "EPS MO On delay sec "  ,   //  533 06-71   EPS MO Off Time
    "EPS MO Off delaysec "  ,   //  534 06-72   EPS MO Off Time
    "Run Dir. Count  H   "	,	//	535 06-73   Running direction count high						
    "Run Dir. Count  L   "	,	//	536 06-74   Running direction count low
    "Run Dir. Temp   H   "	,	//	537 06-75   Temp running direction count high
    "Run Dir. Temp   L   "	,	//  538 06-76   Temp running direction count low
    "Temp Count Rst.     "	,	//	539 06-77   Temp running reset count
    "Run Limit Level k   "	,	//	540 06-78   Running life
    "Run Count Treat     "	,	//	541 06-79   Running function
    "Out Freq. REC2  Hz  "  ,   //  542 06-80   Fcmd Record1"Out Freq. REC.  Hz  "
    "DcBus Value REC2V   "	,   //  543 06-81   Dcbus Record 1
    "Isum Value REC2 Amps"  ,   //  544 06-82   Isum Record1
    "IGBT Temp. REC2 C   "  ,   //  545 06-83   IGBT Temperature Record1
    "Out Freq. REC3  Hz  "  ,   //  546 06-84   Fcmd Record2"Out Freq. REC.  Hz  "
    "DcBus Value REC3V   "	,   //  547 06-85   Dcbus Record2
    "Isum Value REC3 Amps"  ,   //  548 06-86   Isum Record2
    "IGBT Temp. REC3 C   "  ,   //  549 06-87   IGBT Temperature Record2
    "Out Freq. REC4  Hz  "  ,   //  550 06-88   Fcmd Record3"Out Freq. REC.  Hz  "
    "DcBus Value REC4V   "	,   //  551 06-89   Dcbus Record3
    "Isum Value REC4 Amps"  ,   //  552 06-90   Isum Record3
    "IGBT Temp. REC4 C   "  ,   //  553 06-91   IGBT Temperature Record3
    "Out Freq. REC5  Hz  "  ,   //  554 06-92   Fcmd Record4"Out Freq. REC.  Hz  "
    "DcBus Value REC5V   "	,   //  555 06-93   Dcbus Record4
    "Isum Value REC5 Amps"  ,   //  556 06-94   Isum Record4
    "IGBT Temp. REC5 C   "  ,   //  557 06-95   IGBT Temperature Record4
    "Out Freq. REC6  Hz  "  ,   //  558 06-96   Fcmd Record5"Out Freq. REC.  Hz  "
    "DcBus Value REC6V   "	,   //  559 06-97   Dcbus Record5
    "Isum Value REC6 Amps"  ,   //  560 06-98   Isum Record5
    "IGBT Temp. REC6 C   "  ,   //  561 06-99   IGBT Temperature Record5
    
/*---- GROUP 07-----------------------------------------*/ 
/*  "12345678901234561234"	*/
	"SW Braking LevelV   "	,	//	562 07-00	SW Braking Level
    "BK Voltage Hold V   "  ,   //	563 07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
	"Start DCI Level %   "	,	//	564 07-02	DCI Current Level                       //[DCI Level when stop, Bernie, 05/21/2012]
	"DC Inject Start sec "	,	//	565 07-03	DCI Time at Start 
	"DC Inject Stop  sec "	,	//	566 07-04	DCI Time at STOP
	"DC Inject StartFHz  "	,	//	567 07-05	DCI Freq. At start
	"DC Injection Ki     "	,	//	568 07-06	DCI KI
	"GEAR ACC TIME   sec "	,	//	569 07-07	Gear wait time when acceleration
	"GEAR ACC FREQ   Hz  "	,	//	570 07-08	Gear wait frequency when acceleration
	"GEAR DEC TIME   sec "	,	//	572 07-09	Gear wait time when deceleration
	"GEAR DEC FREQ   Hz  "	,	//	573 07-10	Gear wait frequency when deceleration
	"Cooling Fan         "	,	//	574 07-11	Fan Control
	"Torque Ref.     %   "	,	//	575 07-12	TQC Reference from RS485
	"SOURCE OF TQR       "	,	//	576 07-13	Source of Torque Command
	"TQR MAX. LEVEL  %   "	,	//	577 07-14	Torque max. level
	"TQR COM Filter  sec "	,	//	578 07-15	Torque command filter
	"Speed Limit Sel.    "	,	//	579 07-16	Speed Limit selection
	"TQR +SPD LIMIT  %   "	,	//	580 07-17	Torque mode positive speed limit
	"TQR -SPD LIMIT  %   "	,	//  581 07-18	Torque mode negative speed limit
	"TQR OFFSET SEL      "	,	//	582 07-19	Torque offset selection
	"TQR OFFSET LEVEL%   "	,	//	583 07-20	Torque offset setting level
	"TQR OFFSET HIGH %   "	,	//	584 07-21	Torque offset setting level High
	"TQR OFFSET MID. %   "	,	//	585 07-22	Torque offset setting level Middle
	"TQR OFFSET LOW  %   "	,	//	586 07-23	Torque offset setting level Low
	"FWD Motor Tq LIM%   "	,	//	587 07-24	FWD Motoring Tq Limit
	"FWD Reg. Tq LIM %   "	,	//	588 07-25	FWD Regeneration Tq Limit
	"REV Motor Tq LIM%   "	,	//	589 07-26	REV Motoring Tq Limit
	"REV Reg. Tq LIM %   "	,	//	590 07-27	REV Regeneration Tq Limit
	"FORCE STOP WAY      "	,	//	591 07-28	Emergency Stop & Forced Stop selection
	"Torque DEC. Timesec "	,	//	592 07-29   Torque Decrease Time
	"STOP DCI Level  %   "	,	//	593 07-30   STOP DC Inject Level                    //[DCI Level when stop, Bernie, 05/21/2012]
	"BTT100             %"  ,   //  594 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect         "  ,   //  595 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Distance    ppr"  ,   //  596 07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect Time sec"  ,   //  597 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Fail Torq      "  ,   //  598 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Min Torq       "  ,   //  599 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Max Torq       "  ,   //  600 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]

    "RESERVE             "  ,   //	601 07-38   RESERVED
    "RESERVE             "  ,   //	602 07-39   RESERVED
    "RESERVE             "  ,   //	603 07-40   RESERVED
    "RESERVE             "  ,   //	604 07-41   RESERVED
    "RESERVE             "  ,   //	605 07-42   RESERVED
    "RESERVE             "  ,   //  606 07-43   RESERVED
    "RESERVE             "  ,   //  607 07-44   RESERVED
    "RESERVE             "  ,   //  608 07-45   RESERVED
    "RESERVE             "  ,   //  609 07-46   RESERVED
    "RESERVE             "  ,   //  610 07-47   RESERVED
    "RESERVE             "  ,   //  611 07-48   RESERVED
    "RESERVE             "  ,   //  612 07-49   RESERVED
    "RESERVE             "  ,   //  613 07-50   RESERVED
    "RESERVE             "  ,   //  614 07-51   RESERVED
    "RESERVE             "  ,   //	615 07-52   RESERVED
    "RESERVE             "  ,   //	616 07-53   RESERVED
    "RESERVE             "  ,   //	617 07-54   RESERVED
    "RESERVE             "  ,   //	618 07-55   RESERVED
    "RESERVE             "  ,   //	619 07-56   RESERVED
    "RESERVE             "  ,   //  620 07-57   RESERVED
    "RESERVE             "  ,   //	621 07-58   RESERVED
    "RESERVE             "  ,   //	622 07-59   RESERVED
    "RESERVE             "  ,   //	623 07-60   RESERVED
    "RESERVE             "  ,   //	624 07-61   RESERVED
    "RESERVE             "  ,   //	625 07-62   RESERVED
    "RESERVE             "  ,   //	626 07-63   RESERVED
    "RESERVE             "  ,   //  627 07-64   RESERVED
    "RESERVE             "  ,   //  628 07-65   RESERVED
    "RESERVE             "  ,   //  629 07-66   RESERVED
    "RESERVE             "  ,   //  630 07-67   RESERVED
    "RESERVE             "  ,   //  631 07-68   RESERVED
    "RESERVE             "  ,   //  632 07-69   RESERVED
    "RESERVE             "  ,   //  633 07-70   RESERVED
    "RESERVE             "  ,   //  634 07-71   RESERVED
    "RESERVE             "  ,   //	635 07-72   RESERVED
    "RESERVE             "  ,   //	636 07-73   RESERVED
    "RESERVE             "  ,   //	637 07-74   RESERVED
    "RESERVE             "  ,   //  638 07-75   RESERVED
    "RESERVE             "  ,   //	639 07-76   RESERVED
    "RESERVE             "  ,   //	640 07-77   RESERVED
    "RESERVE             "  ,   //	641 07-78   RESERVED
    "RESERVE             "  ,   //  642 07-79   RESERVED
    "RESERVE             "  ,   //  643 07-80   RESERVED
    "RESERVE             "  ,   //  644 07-81   RESERVED
    "RESERVE             "  ,   //  645 07-82   RESERVED
    "RESERVE             "  ,   //  646 07-83   RESERVED
    "RESERVE             "  ,   //  647 07-84   RESERVED
    "RESERVE             "  ,   //  648 07-85   RESERVED
    "RESERVE             "  ,   //  649 07-86   RESERVED
    "RESERVE             "  ,   //  650 07-87   RESERVED
    "RESERVE             "  ,   //  651 07-88   RESERVED
    "RESERVE             "  ,   //  652 07-89   RESERVED
    "RESERVE             "  ,   //  653 07-90   RESERVED
    "RESERVE             "  ,   //  654 07-91   RESERVED
    "RESERVE             "  ,   //  655 07-92   RESERVED
    "RESERVE             "  ,   //  656 07-93   RESERVED
    "RESERVE             "  ,   //  657 07-94   RESERVED
    "RESERVE             "  ,   //  658 07-95   RESERVED
    "RESERVE             "  ,   //  659 07-96   RESERVED
    "RESERVE             "  ,   //  660 07-97   RESERVED
    "RESERVE             "  ,   //  661 07-98   RESERVED
    "RESERVE             "  ,   //  662 07-99   RESERVED
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"PM Auto-Tuning      "	,	//	663 08-00	PMotor Auto-Tuning  
	"PM Motor Rated AAmps"	,	//	664 08-01	PMotor rated Current
	"PM Motor Rated PKw  "	,	//	665 08-02	PMotor Rated Power  
	"PM Motor Rated  RPM "	,	//	666 08-03	PMotor Rated RPM    
	"PM Motor Poles      "	,	//	667 08-04	PMotor pole No.     
	"PM Motor Rs     ohm "	,	//	668 08-05	PMotor Rs           
	"REVERSE             "	,	//	669 08-06	PMotor Ld           
	"PM Motor Lq     mH  "	,	//	670 08-07	PMotor Lq           
	"Back EMF        Vrms"	,	//	671 08-08	PMotor Bemf coff	
	"Z-Offset Angle  deg "	,	//	672 08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
	"Position Align      "	,	//	673 08-10	//ADDED BY DIN

/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "VFD Comm Address    "	,	//	674 09-00   Comm Address                              
    "COM Baud Rate   kbps"	,	//	675 09-01   Tranmission speed                         
    "COM Fault Treatment "	,	//	676 09-02   Comm fault Treatment                      
    "COM Time Out    sec "	,	//	677 09-03   Comm Time out                             
    "COM Protocol        "	,	//	678 09-04   Comm Protocol                             
    "Response Delay Tms  "	,	//	679 09-05   ASC remote Response Delay Time, 1=100us   
    "CAN_BUARD           "	,   //	680 09-06   CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "PDO_Tx_Time     ms  "	,   //  681 09-07   CAN PDO Handshaking Period  
    "CAN_Check_Time  ms  "	,   //	682 09-08   CAN Communiction Timeout
    "Elevator ID Code    "  ,   //	683 09-09   Elevator Control Identification Code
    "FHM Register        "  ,   //	684 09-10
    "DLC Register 1      "  ,   //	685 09-11
    "DLC Register 2      "  ,   //	686 09-12
    "DLC Register 3      "  ,   //	687 09-13     
    "PDO TXTIME      ms  "  ,   //	688 09-14   CAN fail rate---aevin 6/12/2017

/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"Encoder Types       "	,	//	689 10-00	Encoder TYPE                             
	"Encoder pulses  ppr "	,	//	690 10-01	Encoder pulses	                    
	"PG input setting    "	,	//  691 10-02	PG input setting	                
	"PG Err Treat        "	,	//  692 10-03	PG fbk fault treatment	            
	"PG Err Det. Timesec "	,	//  693 10-04	PG fbk Error Detection Time	        
	"PG FBK DET Level%   "	,	//  694 10-05	PG fbk overspeed detection level	
	"OverSPD Det.Timesec "	,	//  695 10-06	Over speed Detection Time	        
	"PG FBK DEV Level%   "	,	//	696 10-07	PG fbk speed deviation level	    
	"DEV Detect Time sec "	,	//	697 10-08	Deviation Detect Time	            
	"Over SPD Way        "	,	//	698 10-09	Operation at overspeed	            
	"Hall Input Types    "  ,   //  699 10-10   Hall Input Types
	"Zero SPD Loop Kp%   "	,	//	700 10-11	KP gain of ASR in Zero speed	
	"Zero SPD Loop Kisec "	,	//	701 10-12	Ki gain of ASR in Zero speed	
	"Low SPD Loop Kp %   "	,	//	702 10-13	ASR P Gain 1	                
	"Low SPD Loop Ki sec "	,	//	703 10-14	ASR I Gain 1	                
	"High SPD Loop Kp%   "	,	//	704 10-15	ASR P Gain 2	                
	"High SPD Loop Kisec "	,	//	705 10-16	ASR I Gain 2	                
	"ASR1/2 Switch F Hz  "	,	//  706 10-17	ASR1/ASR2 switch freq	        
	"Primary LPG     sec "	,	//  707 10-18	Primary LowPass filter Gain 
	"Position Loop Kp%   "  ,	//  708 10-19   position control Kp Gain  
    "Low SPD Slope   Hz  "  ,   //  709 10-20   Low Spd band
    "High SPD Slope  Hz  "  ,   //  710 10-21   High Spd band
	"POS CONT Time   sec "	,	//  711 10-22   Position control time
	"POS CONT LPG    sec "	,	//  712 10-23   Position control LOW POSS FILTER
	"Source of POS       "	,	//  713 10-24   Source of position control, add by dino, 06/30/2008
	"Zero SPD Land Kp%   "	,	//  714 10-25	KP gain of ASR in Zero speed of Landing
	"Zero SPD Land Kisec "	,	//	715 10-26	Ki gain of ASR in Zero speed of Landing
	"Position SPD Kp %   "	,	//	716 10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"Position SPD Ki sec "	,	//	717 10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"PG Card Freq Div    "	,   //	718 10-29   PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
	"PG Card Mode        "	,   //	719 10-30   PG Card Mode setting                //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C- TYPE       "  ,   //  720 10-31   RESERVE                             //[change parameter to normal group, Bernie, 2014/02/14]
    "Over Acc Level  m/s2"  ,   //	721 10-32   Over acc level setting              //[Over Acceleration protection function, Bernie, 2017/02/13]
    "OverAcc Det.Timesec "  ,   //	722 10-33   Over acc detect time                //[Over Acceleration protection function, Bernie, 2017/02/13]
    "Over Acc setting    "  ,   //	723 10-34   Over acc detect rule setting        //[Over Acceleration protection function, Bernie, 2017/02/13]

    "RESERVE             "  ,   //	724 10-35   RESERVED
    "RESERVE             "  ,   //	725 10-36   RESERVED
    "RESERVE             "  ,   //	726 10-37   RESERVED
    "RESERVE             "  ,   //	727 10-38   RESERVED
    "RESERVE             "  ,   //	728 10-39   RESERVED

/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"System Control  Hex "	,	//  729 11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "Fmax to Lift Spdm/s "  ,   //  730 11-01   Lift operation speed                                        
    "Sheave Diameter mm  "  ,   //  731 11-02   SHEAVE diameter			ADDED BY SCOTTY                     
    "Gear Ratio          "  ,   //  732 11-03   Gear Ratio                                              
    "Suspension Ratio    "  ,   //  733 11-04   Suspension ratio	                                        
    "Inertia Ratio   %   "  ,   //  734 11-05   inertia	percent			ADDED BY SCOTTY                     
	"Zero SP Loop BW Hz  "	,	//	735 11-06	Zero Speed Loop BandWidth	                                
	"Low SP Loop BW  Hz  "	,	//	736 11-07	Speed Loop BandWidth1		                                
	"High SP Loop BW Hz  "	,	//	737 11-08	Speed Loop BandWidth2		                                
	"SPD Loop Kr     %   "	,	//  738 11-09	PDFFKr		                                                
	"SPD FFD GAIN    %   "	,	//	739 11-10	SPEED FFD GAIN			ADDED BY SCOTTY                     
	"Netch Deep      db  "	,	//	740 11-11	Netch filter deep(db)	                                    
	"Netch Freq.     Hz  "	,	//	741 11-12	Netch filter frequency	                                    
	"LPF for display sec "	,	//  742 11-13	Low Pass Filter for display	                                
	"Max. ACC Current%   "	,	//  743 11-14	ACC Max current                                             
    "Max Meter per S m/s "  ,	//  744 11-15	max meter/sec	                                            
    "Disp address    Hex "  ,   //  745 11-16	Display address,add by dino 2007/03/08                      
    "Disp data           "  ,	//  746 11-17	Display data,   add by dino 2007/03/08                      
    "Protect Bit         "  ,   //  747 11-18   Protect Bit	                                                
	"Zero SP Land BW Hz  "	,	//  748 11-19	Zero Speed Loop BandWidth of Landing
	"PWM Mode            "	,	//  749 11-20	PWM MODE, 0=SVPWM+DPWM,1=SVPWM    PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LPF for LC01    sec "	,	//  750 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	750 11-21   Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]
    "RESERVE             "  ,   //	752 11-23   RESERVED
    "RESERVE             "  ,   //	753 11-24   RESERVED
    "RESERVE             "  ,   //	754 11-25   RESERVED
    "RESERVE             "  ,   //	755 11-26   RESERVED
    "RESERVE             "  ,   //	756 11-27   RESERVED
    "RESERVE             "  ,   //	757 11-28   RESERVED
    "RESERVE             "  ,   //	758 11-29   RESERVED
    
/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_ADD0           "  ,   //  759 12-00
    "UMAP_ADD1           "  ,   //  760 12-01
    "UMAP_ADD2           "  ,   //  761 12-02
    "UMAP_ADD3           "  ,   //  762 12-03
    "UMAP_ADD4           "  ,   //	763 12-04
    "UMAP_ADD5           "  ,   //	764 12-05
    "UMAP_ADD6           "  ,   //	765 12-06
    "UMAP_ADD7           "  ,   //	766 12-07
    "UMAP_ADD8           "  ,   //	767 12-08
    "UMAP_ADD9           "  ,   //	768 12-09
    "UMAP_ADD10          "  ,   //	769 12-10
    "UMAP_ADD11          "  ,   //	770 12-11
    "UMAP_ADD12          "  ,   //	771 12-12
    "UMAP_ADD13          "  ,   //	772 12-13
    "UMAP_ADD14          "  ,   //	773 12-14
    "UMAP_ADD15          "  ,   //  774 12-15
    "UMAP_ADD16          "  ,   //	775 12-16
    "UMAP_ADD17          "  ,   //	776 12-17
    "UMAP_ADD18          "  ,   //	777 12-18
    "UMAP_ADD19          "  ,   //	778 12-19 
    "UMAP_ADD20          "  ,   //	779 12-20
    "UMAP_ADD21          "  ,   //	780 12-21
    "UMAP_ADD22          "  ,   //  781 12-22
    "UMAP_ADD23          "  ,   //	782 12-23
    "UMAP_ADD24          "  ,   //	783 12-24
    "UMAP_ADD25          "  ,   //	784 12-25
    "UMAP_ADD26          "  ,   //	785 12-26
    "UMAP_ADD27          "  ,   //	786 12-27
    "UMAP_ADD28          "  ,   //	787 12-28
    "UMAP_ADD29          "  ,   //	788 12-29
    "UMAP_ADD30          "  ,   //  789 12-30
    "UMAP_ADD31          "  ,   //  790 12-31
    "UMAP_ADD32          "  ,   //  791 12-32
    "UMAP_ADD33          "  ,   //  792 12-33
    "UMAP_ADD34          "  ,   //  793 12-34
    "UMAP_ADD35          "  ,   //  794 12-35
    "UMAP_ADD36          "  ,   //  795 12-36
    "UMAP_ADD37          "  ,   //  796 12-37
    "UMAP_ADD38          "  ,   //  797 12-38
    "UMAP_ADD39          "  ,   //  798 12-39
    "UMAP_ADD40          "  ,   //  799 12-40
    "UMAP_ADD41          "  ,   //  800 12-41
    "UMAP_ADD42          "  ,   //  801 12-42
    "UMAP_ADD43          "  ,   //  802 12-43
    "UMAP_ADD44          "  ,   //  803 12-44
    "UMAP_ADD45          "  ,   //  804 12-45
    "UMAP_ADD46          "  ,   //  805 12-46
    "UMAP_ADD47          "  ,   //  806 12-47
    "UMAP_ADD48          "  ,   //  807 12-48
    "UMAP_ADD49          "  ,   //  808 12-49
    "RESERVED            "  ,   //  809 12-50    
    "RESERVED            "  ,   //  810 12-51    
    "RESERVED            "  ,   //  811 12-52    
    "RESERVED            "  ,   //  812 12-53    
    "RESERVED            "  ,   //  813 12-54    
    "RESERVED            "  ,   //  814 12-55    
    "RESERVED            "  ,   //  815 12-56    
    "RESERVED            "  ,   //  816 12-57    
    "RESERVED            "  ,   //  817 12-58    
    "RESERVED            "  ,   //  818 12-59    
    "RESERVED            "  ,   //  819 12-60    
    "RESERVED            "  ,   //  820 12-61    
    "RESERVED            "  ,   //  821 12-62    
    "RESERVED            "  ,   //  822 12-63    
    "RESERVED            "  ,   //  823 12-64    
    "RESERVED            "  ,   //  824 12-65    
    "RESERVED            "  ,   //  825 12-66    
    "RESERVED            "  ,   //  826 12-67    
    "RESERVED            "  ,   //  827 12-68    
    "RESERVED            "  ,   //  828 12-69    
    "RESERVED            "  ,   //  829 12-70    
    "RESERVED            "  ,   //  830 12-71    
    "RESERVED            "  ,   //  831 12-72    
    "RESERVED            "  ,   //  832 12-73    
    "RESERVED            "  ,   //  833 12-74    
    "RESERVED            "  ,   //  834 12-75    
    "RESERVED            "  ,   //  835 12-76    
    "RESERVED            "  ,   //  836 12-77    
    "RESERVED            "  ,   //  837 12-78    
    "RESERVED            "  ,   //  838 12-79    
    "RESERVED            "  ,   //  839 12-80    
    "RESERVED            "  ,   //  840 12-81    
    "RESERVED            "  ,   //  841 12-82    
    "RESERVED            "  ,   //  842 12-83    
    "RESERVED            "  ,   //  843 12-84    
    "RESERVED            "  ,   //  844 12-85    
    "RESERVED            "  ,   //  845 12-86    
    "RESERVED            "  ,   //  846 12-87    
    "RESERVED            "  ,   //  847 12-88    
    "RESERVED            "  ,   //  848 12-89    
    "RESERVED            "  ,   //  849 12-90    
    "RESERVED            "  ,   //  850 12-91    
    "RESERVED            "  ,   //  851 12-92    
    "RESERVED            "  ,   //  852 12-93    
    "RESERVED            "  ,   //  853 12-94    
    "RESERVED            "  ,   //  854 12-95    
    "RESERVED            "  ,   //  855 12-96    
    "RESERVED            "  ,   //  856 12-97    
    "RESERVED            "  ,   //  857 12-98    
    "RESERVED            "  ,   //  858 12-99    
    
/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_DATA0          "  ,   //  859 13-00
    "UMAP_DATA1          "  ,   //  860 13-01
    "UMAP_DATA2          "  ,   //  861 13-02
    "UMAP_DATA3          "  ,   //  862 13-33
    "UMAP_DATA4          "  ,   //  863 13-04
    "UMAP_DATA5          "  ,   //  864 13-05
    "UMAP_DATA6          "  ,   //  865 13-06
    "UMAP_DATA7          "  ,   //  866 13-07
    "UMAP_DATA8          "  ,   //  867 13-08
    "UMAP_DATA9          "  ,   //  868 13-09
    "UMAP_DATA10         "  ,   //  869 13-10
    "UMAP_DATA11         "  ,   //  870 13-11
    "UMAP_DATA12         "  ,   //  871 13-12
    "UMAP_DATA13         "  ,   //  872 13-13
    "UMAP_DATA14         "  ,   //  873 13-14
    "UMAP_DATA15         "  ,   //  874 13-15
    "UMAP_DATA16         "  ,   //  875 13-16
    "UMAP_DATA17         "  ,   //  876 13-17
    "UMAP_DATA18         "  ,   //  877 13-18
    "UMAP_DATA19         "  ,   //  878 13-19
    "UMAP_DATA20         "  ,   //  879 13-20
    "UMAP_DATA21         "  ,   //  880 13-21
    "UMAP_DATA22         "  ,   //  881 13-22
    "UMAP_DATA23         "  ,   //  882 13-23
    "UMAP_DATA24         "  ,   //  883 13-24
    "UMAP_DATA25         "  ,   //  884 13-25
    "UMAP_DATA26         "  ,   //  885 13-26
    "UMAP_DATA27         "  ,   //  886 13-27
    "UMAP_DATA28         "  ,   //  887 13-28
    "UMAP_DATA29         "  ,   //  888 13-29
    "UMAP_DATA30         "  ,   //  889 13-30
    "UMAP_DATA31         "  ,   //  890 13-31
    "UMAP_DATA32         "  ,   //  891 13-32
    "UMAP_DATA33         "  ,   //  892 13-33
    "UMAP_DATA34         "  ,   //  893 13-34
    "UMAP_DATA35         "  ,   //  893 13-35
    "UMAP_DATA36         "  ,   //  894 13-36
    "UMAP_DATA37         "  ,   //  895 13-37
    "UMAP_DATA38         "  ,   //  896 13-38
    "UMAP_DATA39         "  ,   //  897 13-39
    "UMAP_DATA40         "  ,   //  898 13-30
    "UMAP_DATA41         "  ,   //  899 13-41
    "UMAP_DATA42         "  ,   //  900 13-42
    "UMAP_DATA43         "  ,   //	901 13-43
    "UMAP_DATA44         "  ,   //	902 13-44
    "UMAP_DATA45         "  ,   //	903 13-45
    "UMAP_DATA46         "  ,   //	904 13-46
    "UMAP_DATA47         "  ,   //	905 13-47
    "UMAP_DATA48         "  ,   //  906 13-48
    "UMAP_DATA49         "  ,   //  907 13-49
    "UMAP_DATA50         "  ,   //  908 13-50
    "UMAP_DATA51         "  ,   //  909 13-51
    "UMAP_DATA52         "  ,   //  910 13-52
    "UMAP_DATA53         "  ,   //  911 13-53
    "UMAP_DATA54         "  ,   //  912 13-54
    "UMAP_DATA55         "  ,   //  913 13-55
    "UMAP_DATA56         "  ,   //  914 13-56
    "UMAP_DATA57         "  ,   //	915 13-57
    "UMAP_DATA58         "  ,   //	916 13-58
    "UMAP_DATA59         "  ,   //	917 13-59
    "UMAP_DATA60         "  ,   //	918 13-60
    "UMAP_DATA61         "  ,   //	919 13-61
    "UMAP_DATA62         "  ,   //  920 13-62
    "UMAP_DATA63         "  ,   //	921 13-63
    "UMAP_DATA64         "  ,   //	922 13-64
    "UMAP_DATA65         "  ,   //	923 13-65
    "UMAP_DATA66         "  ,   //	924 13-66
    "UMAP_DATA67         "  ,   //	925 13-67
    "UMAP_DATA68         "  ,   //	926 13-68
    "UMAP_DATA69         "  ,   //  927 13-69
    "UMAP_DATA70         "  ,   //  928 13-70
    "UMAP_DATA71         "  ,   //  929 13-71
    "UMAP_DATA72         "  ,   //  930 13-72
    "UMAP_DATA73         "  ,   //  931 13-73
    "UMAP_DATA74         "  ,   //  932 13-74
    "UMAP_DATA75         "  ,   //  933 13-75
    "UMAP_DATA76         "  ,   //  934 13-76
    "UMAP_DATA77         "  ,   //	935 13-77
    "UMAP_DATA78         "  ,   //	936 13-78
    "UMAP_DATA79         "  ,   //	937 13-79
    "UMAP_DATA80         "  ,   //  938 13-80
    "UMAP_DATA81         "  ,   //	939 13-81
    "UMAP_DATA82         "  ,   //	940 13-82
    "UMAP_DATA83         "  ,   //	941 13-83
    "UMAP_DATA84         "  ,   //  942 13-84
    "UMAP_DATA85         "  ,   //  943 13-85
    "UMAP_DATA86         "  ,   //  944 13-86
    "UMAP_DATA87         "  ,   //  945 13-87
    "UMAP_DATA88         "  ,   //  946 13-88
    "UMAP_DATA89         "  ,   //  947 13-89
    "UMAP_DATA90         "  ,   //  948 13-90
    "UMAP_DATA91         "  ,   //  949 13-91
    "UMAP_DATA92         "  ,   //  950 13-92
    "UMAP_DATA93         "  ,   //  951 13-93
    "UMAP_DATA94         "  ,   //  952 13-94
    "UMAP_DATA95         "  ,   //  953 13-95
    "UMAP_DATA96         "  ,   //  954 13-96
    "UMAP_DATA97         "  ,   //  955 13-97
    "UMAP_DATA98         "  ,   //  956 13-98
    "UMAP_DATA99         "  ,   //  957 13-99
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level%   "	,	//	958 14-00	Ids Power Save Level
	"VF CURVE MODE       "	,	//	959 14-01	VF voltage mode selection
	"Overload 1 Mode     "	,	//	960 14-02	Constant Torque Selection
	"Auto ACC/DEC        "	,	//	961 14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	962 14-04	Unit of Acc/Dec time
	"POWER SAVE MODE     "	,	//  963 14-05	Power Save mode
	"Stop Methods        "	,	//  964 14-06	Stop Methods
	"Reverse Operate     "	,	//  965 14-07	Reverse Operation
	"Skip Freq. 1UP  Hz  "	,	//  966 14-08	Skip Freq. Point 1 upper limit
	"Skip Freq. 1LOW Hz  "	,	//  967 14-09	Skip Freq. Point 1 lower limit
	"Skip Freq. 2UP  Hz  "	,	//  968 14-10	Skip Freq. Point 2 upper limit
	"Skip Freq. 2LOW Hz  "	,	//  969 14-11	Skip Freq. Point 2 lower limit
	"Skip Freq. 3UP  Hz  "	,	//  970 14-12	Skip Freq. Point 3 upper limit
	"Skip Freq. 3LOW Hz  "	,	//  971 14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz  "	,	//  972 14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//  973 14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//  974 14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//  975 14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//  976 14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//  977 14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2  Hz  "	,	//  978 14-20	Min Output Freq. 2
	"Min Out-Volt 2  V   "	,	//  979 14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//  980 14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//  981 14-23	up/down key speed
	"Counter Set         "	,	//  982 14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//  983 14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//  984 14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"Multi-Fun Input9    "	,	//  985 14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//  986 14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//  987 14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//  988 14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//  989 14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//  990 14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//  991 14-33	External Terminal Run after Fault Reset
	"ACI/AVI2 SEL        "	,	//  992 14-34	ACI change to AVI2
	"Addition of AI      "	,	//  993 14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//  993 14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//  994 14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//  995 14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//  996 14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//  997 14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//  998 14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//  999 14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//  1000 14-43	Multi-Position Point 8
	"Multi-Posit 9       "	,	//	1001 14-44	Multi-Position Point 9
	"Multi-Posit 10      "	,	//	1002 14-45	Multi-Position Point 10
	"Multi-Posit 11      "	,	//	1003 14-46	Multi-Position Point 11
	"Multi-Posit 12      "	,	//	1004 14-47	Multi-Position Point 12
	"Multi-Posit 13      "	,	//	1005 14-48	Multi-Position Point 13
	"Multi-Posit 14      "	,	//  1006 14-49	Multi-Position Point 14
	"Multi-Posit 15      "	,	//  1007 14-50	Multi-Position Point 15
	"MOTOR 1 OR 2        "	,	//  1008 14-51	Motor Selection 1 or 2
	"Y-D Switch Hz   Hz  "	,	//  1009 14-52	Y-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//  1010 14-53	Y-Delta switched Enable
	"Motor2 Rated    Amps"	,	//  1011 14-54	Motor 2 rated Current
	"Motor2 Rated P  Kw  "	,	//  1012 14-55	Motor 2 Rated Power
	"Motor2 Rated    RPM "	,	//  1013 14-56	Motor 2 Rated RPM
	"Motor2 Poles        "	,	//  1014 14-57	Motor 2 pole No.
	"Motor2 No-Load  Amps"	,	//	1015 14-58	Motor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	1016 14-59	Motor 2 Rs
	"Motor2 Rr       ohm "	,	//	1017 14-60	Motor 2 Rr
	"Motor2 Lm       mH  "	,	//	1018 14-61	Motor 2 Lm
	"Motor2 Lx       mH  "	,	//	1019 14-62	Motor 2 Lx
	"Y-D On Delay T      "	,	//  1020 14-63	Y-Delta On delay time
	"OV stall level  V   "	,	//	1021 14-64	OV stall level
	"Thermal RLY2 SEL    "	,	//	1022 14-65	Thermal Relay 2 Selection
	"Thermal RLY2 T      "	,	//	1023 14-66	Thermal Relay 2 Time
	"Momentary Power     "	,	//	1024 14-67	Momentary Power Loss
	"Power Loss Time sec "	,	//	1025 14-68	Max. allowable PL time
	"Base Block Time sec "	,	//	1026 14-69	BB Time for speed serach
	"SPD Search Curr %   "	,	//  1027 14-70	Current level for SPD serach
	"BB Treatment        "	,	//  1028 14-71	bb treatment for oc, ov, bb
	"Auto Restart        "	,	//  1029 14-72	Auto restart after fault
	"Restart Method      "	,	//  1030 14-73	Auto restart Speed serach method
	"DEB Decel SEL       "	,	//  1031 14-74	Deceleration at Momertary Power loss 
	"DEB Return Time     "	,	//  1032 14-75	KEB Return Time
	"PID Fdb SEL         "	,	//  1033 14-76	PID feedback selection	
	"P Gain of PID       "	,	//  1034 14-77	P gain of PID	
	"I Gain of PID   sec "	,	//	1035 14-78	I gain of PID	
	"D Gain of PID       "	,	//	1036 14-79	D gain of PID	
	"Up Limit for I  %   "	,	//	1037 14-80	Upper bound for integral	
	"PID Out-Limiter %   "	,	//  1038 14-81	PID output Freq. Limit	
	"PID Offset      %   "	,	//	1039 14-82	PID offset	
	"PID Out-Filter  sec "	,	//	1040 14-83	Derivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	1041 14-84	Feedback signal detection time	
	"PID Fdb Loss        "	,	//  1042 14-85	PID feedback loss	
	"SLEEP FREQ          "	,	//  1043 14-86	Sleep Frequency	
	"WAKE FREQ           "	,	//  1044 14-87	Wake up Frequency	
	"SLEEP TIME          "	,	//  1045 14-88	Sleep Time	
	"PID DEV. LEVEL  %   "	,	//  1046 14-89	PID Deviation Level	
	"PID DEV. TIME       "	,	//  1047 14-90	PID Deviation Time	
	"PID Fbk Filter  sec "	,	//  1048 14-91	PID feedback filter	
	"Comm Main Freq. Hz  "	,	//  1049 14-92	Main Frequency from communication	
	"Block Trans. 1      "	,	//  1050 14-93	Block Transfer 1	
	"Block Trans. 2      "	,	//  1051 14-94	Block Transfer 2	
	"Block Trans. 3      "	,	//  1052 14-95	Block Transfer 3
	"Block Trans. 4      "	,	//  1053 14-96	Block Transfer 4
	"Block Trans. 5      "	,	//  1054 14-97	Block Transfer 5
	"Block Trans. 6      "	,	//  1055 14-98	Block Transfer 6
	"Block Trans. 7      "	,	//  1056 14-99	Block Transfer 7
	"Block Trans. 8      "	,	//  1057 14-100 Block Transfer 8
	"Block Trans. 9      "	,	//	1086 14-101 Block Transfer 9
	"Block Trans. 10     "	,	//	1087 14-102 Block Transfer 10
	"WEAKLPF             "	,	//	1088 14-103 WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	1089 14-104 WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	1090 14-105 OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"PG Position Home    "	,	//	1091 14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	1092 14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	1093 14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	1094 14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	1095 14-110 FMax Target by Vcommand Position
	"RESERVE             "	,	//	1096 14-111 Accel. Time for Position
	"PG Mech. Gear A     "	,	//	1097 14-112 PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	1098 14-113 PG Mechanical Gear B
	"System Jm       PU  "	,	//	1099 14-114 Interia of motor PU
	"M1IdsRef Limit   %  "	,	//	1100 14-115 Motor1 IdsRef Limit
	"M2IdsRef Limit   %  "	,	//  1101 14-116 Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	1102 14-117 Phase Loss Time
	"TH Inside Temp   C  "	,	//	1103 14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	1104 14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	1105 14-120 SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//  1106 14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	1107 14-122 Tension of Torque Control
	"DIAMETER        m   "	,	//	1108 14-123 iameter of Material
	"DEPTH           cm  "	,	//	1109 14-124 Depth of meterial
	"RESERVE             "	,	//	1110 14-125 Reserve
	"ABZ ST Times        "	,	//	1111 14-126 Reserve
	"ABZ ST Duty         "	,	//	1112 14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	1113 14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	1114 14-129 Time of APR Curve
    "Jm source           "  ,   //	1115 14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	1116 14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	1117 14-132 muti input state
    "StandStill Curr.Amps"  ,   //  1118 14-133 Standstill Current
	"PG Scale Factor     "	,	//	1119 14-134 Division factor of PG	 
	"OLD Irate           "	,	//	1120 14-135 OLD Irate       // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   //  1121 14-136 [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   //  1122 14-137 [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time  sec "	,   //  1123 14-138 [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   //  1124 14-139 [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    "VFD Com1 Address    "	,	//	1125 14-140 Comm Address           //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                      
	"COM1 Baud Rate  kbps"	,	//	1126 14-141 Tranmission speed                         
	"COM1 Fault Treat    "	,	//	1127 14-142 Comm fault Treatment                      
	"COM1 Time Out   sec "	,	//	1128 14-143 Comm Time out                             
	"COM1 Protocol       "	,	//	1129 14-144 Comm Protocol                             
	"COM1 Delay Time ms  "	,	//	1130 14-145 ASC remote Response Delay Time, 1=100us 
    "OPHL 10Hz COUNT     "	,	//	1131 14-146 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "	,	//	1132 14-147 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "	,	//	1133 14-148 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "	,	//	1134 14-149 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "	,	//	1135 14-150 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "	,	//	1136 14-151 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "	,	//	1137 14-152 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 3       "	,	//	1138 14-153 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_TC
const string20 prinfo_tc_ACC_ms2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"�Ĥ@�[�t�ɶ�    m/s2"	,	//	156	01-12 1st Acceleration time      //chinese description creat by Bernie 
	"�Ĥ@��t�ɶ�    m/s2"	,	//	157	01-13 1st Deceleration time      //chinese description creat by Bernie 
	"�ĤG�[�t�ɶ�    m/s2"	,	//	158	01-14 2nd Acceleration time      //chinese description creat by Bernie 
	"�ĤG��t�ɶ�    m/s2"	,	//	159	01-15 2nd Deceleration time      //chinese description creat by Bernie 
	"�ĤT�[�t�ɶ�    m/s2"	,	//	160	01-16 3rd Acceleration time      //chinese description creat by Bernie 
	"�ĤT��t�ɶ�    m/s2"	,	//	161	01-17 3rd Deceleration time      //chinese description creat by Bernie 
	"�ĥ|�[�t�ɶ�    m/s2"	,	//	162	01-18 4th Acceleration time      //chinese description creat by Bernie 
	"�ĥ|��t�ɶ�    m/s2"	,	//	163	01-19 4th Deceleration time      //chinese description creat by Bernie 
	"�o�ʥ[�t�ɶ�    m/s2"	,	//	164	01-20 JOG Acceleration time
	"�o�ʴ�t�ɶ�    m/s2"	,	//	165	01-21 JOG Deceleration time
	"������t�ɶ�    m/s2"
};

const string20 prinfo_tc_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"�Ĥ@�[�t�ɶ�    f/s2"	,	//	156	01-12 1st Acceleration time      //chinese description creat by Bernie 
	"�Ĥ@��t�ɶ�    f/s2"	,	//	157	01-13 1st Deceleration time      //chinese description creat by Bernie 
	"�ĤG�[�t�ɶ�    f/s2"	,	//	158	01-14 2nd Acceleration time      //chinese description creat by Bernie 
	"�ĤG��t�ɶ�    f/s2"	,	//	159	01-15 2nd Deceleration time      //chinese description creat by Bernie 
	"�ĤT�[�t�ɶ�    f/s2"	,	//	160	01-16 3rd Acceleration time      //chinese description creat by Bernie 
	"�ĤT��t�ɶ�    f/s2"	,	//	161	01-17 3rd Deceleration time      //chinese description creat by Bernie 
	"�ĥ|�[�t�ɶ�    f/s2"	,	//	162	01-18 4th Acceleration time      //chinese description creat by Bernie 
	"�ĥ|��t�ɶ�    f/s2"	,	//	163	01-19 4th Deceleration time      //chinese description creat by Bernie 
	"�o�ʥ[�t�ɶ�    f/s2"	,	//	164	01-20 JOG Acceleration time
	"�o�ʴ�t�ɶ�    f/s2"	,	//	165	01-21 JOG Deceleration time
	"������t�ɶ�    f/s2"
};


const string20 prinfo_tc_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"�[�t�}�lS1�ɶ�  m/s3"	,	//	168	01-24 S curve Accel time 1
	"�[�t�}�lS2�ɶ�  m/s3"	,	//	169	01-25 S curve Accel time 2
	"�[�t�}�lS3�ɶ�  m/s3"	,	//	170	01-26 S curve Decel time 1
	"�[�t�}�lS4�ɶ�  m/s3"	,	//	171	01-27 S curve Decel time 2
	"�C�󥭼h�t��S5  m/s3"	
};

const string20 prinfo_tc_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"�[�t�}�lS1�ɶ�  f/s3"	,	//	168	01-24 S curve Accel time 1
	"�[�t�}�lS2�ɶ�  f/s3"	,	//	169	01-25 S curve Accel time 2
	"�[�t�}�lS3�ɶ�  f/s3"	,	//	170	01-26 S curve Decel time 1
	"�[�t�}�lS4�ɶ�  f/s3"	,	//	171	01-27 S curve Decel time 2
	"�C�󥭼h�t��S5  f/s3"	
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
    "RESERVE             "	,	//	128 15-128  RESERVED
    "RESERVE             "	,	//	129 15-129  RESERVED

/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
    "�����ѧO�X          "	,	//	130 00-00	Model Type of Drive 
    "���W���B�w�q�y  Amps"	,	//	131 00-01	Rated Current
    "�Ѽƭ��m�]�w        "	,	//	132 00-02	Parameter Reset
    "�}����ܵe�����    "	,	//	133 00-03	Start up Display       //chinese description creat by Bernie 
    "�h�\\����ܿ��     "	,	//	134 00-04	User Display            // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "�w�q��ҳ]�w        "	,	//	135	00-05	User Coefficient        //chinese description creat by Bernie 
    "�n�骩��            "	,	//	136	00-06	Software Version
    "�ѼƫO�@�ѽX��J    "	,	//	137	00-07	Password Input
    "�ѼƫO�@�ѽX�]�w    "	,	//	138	00-08	Password Input
    "����Ҧ�            "	,	//	139	00-09	Control Methods
    "�t�׳��            "	,	//	140	00-10	Velocity Unit Select
    "�X�ʾ���X��V      "	,	//	141 00-11   Change Output Direction, Added by sampo , 06/11/2009
    "���i�W�v        KHz "	,	//	142	00-12	Carry Frequency
    "�۰�í���\\��       "	,	//	143	00-13	AVR                     // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "�t�׫��O�ӷ�        "	,	//	144	00-14	Source of Freq. Command
    "�B����O�ӷ�        "	,	//	145	00-15	Source of Oper. Command

    "�O�d                "	,	//	146 00-16   RESERVED
    "�O�d                "	,	//	147 00-17   RESERVED
    "�O�d                "	,	//	148 00-18   RESERVED
    "�O�d                "	,	//	149 00-19   RESERVED
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"�̤j�ާ@�W�v    Hz  "	,	//	150	01-00	Max Output Freq.
	"�q���B�w�W�v    Hz  "	,	//	151	01-01	Motor Base Frequency 1
	"�q���B�w�q��    V   "	,	//	152	01-02	Max Output Voltage
	"�ĤG��X�W�v    Hz  "	,	//	153	01-03	Mid Output Freq.1
	"�ĤG��X�q��    V   "	,	//	154	01-04	Mid Output Voltage 1
	"�ĤT��X�W�v    Hz  "	,	//	155	01-05	Mid Output Freq.2
	"�ĤT��X�q��    V   "	,	//	156	01-06	Mid Output Voltage 2
	"�ĥ|��X�W�v    Hz  "	,	//	157	01-07	Min Output Freq.
	"�ĥ|��X�q��    V   "	,	//	158	01-08	Min Output Voltage
	"�Ұ��W�v        Hz  "	,	//	159	01-09	Start Frequency
	"��X�W�v�W����  Hz  "	,	//	160	01-10	Upper Bound Freq.
	"��X�W�v�U����  Hz  "	,	//	161	01-11	Lower Bound Freq.
	"�Ĥ@�[�t�ɶ�    sec "	,	//	162	01-12	1st Acceleration time      //chinese description creat by Bernie 
	"�Ĥ@��t�ɶ�    sec "	,	//	163	01-13	1st Deceleration time      //chinese description creat by Bernie 
	"�ĤG�[�t�ɶ�    sec "	,	//	164	01-14	2nd Acceleration time      //chinese description creat by Bernie 
	"�ĤG��t�ɶ�    sec "	,	//	165	01-15	2nd Deceleration time      //chinese description creat by Bernie 
	"�ĤT�[�t�ɶ�    sec "	,	//	166	01-16	3rd Acceleration time      //chinese description creat by Bernie 
	"�ĤT��t�ɶ�    sec "	,	//	167	01-17	3rd Deceleration time      //chinese description creat by Bernie 
	"�ĥ|�[�t�ɶ�    sec "	,	//	168	01-18	4th Acceleration time      //chinese description creat by Bernie 
	"�ĥ|��t�ɶ�    sec "	,	//	169	01-19	4th Deceleration time      //chinese description creat by Bernie 
	"�o�ʥ[�t�ɶ�    sec "	,	//	170	01-20	JOG Acceleration time
	"�o�ʴ�t�ɶ�    sec "	,	//	171	01-21	JOG Deceleration time
	"�o���W�v        Hz  "	,	//	172	01-22	JOG Frequency
	"1-4�[��t����   Hz  "	,	//	173	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"�[�t�}�lS1�ɶ�  sec "	,	//	174	01-24	S curve Accel time 1
	"�[�t�}�lS2�ɶ�  sec "	,	//	175	01-25	S curve Accel time 2
	"�[�t�}�lS3�ɶ�  sec "	,	//	176	01-26	S curve Decel time 1
	"�[�t�}�lS4�ɶ�  sec "	,	//	177	01-27	S curve Decel time 2
	"�p��ĥ|�W�v�Ҧ�    "	,	//	178	01-28	Select Zero Speed
	"���h�t�פ���    Hz  "	,	//	179	01-29	Landing Frequency 
	"�C�󥭼h�t��S5  sec "	,	//	180	01-30	S curve Decel time 3
	"������t�ɶ�    sec "	,	//	181	01-31	Stop Deceleration time
    "�׺ݱj���t��  m/s "	,	//	182	01-32
    "�ݤl�������t�ɶ�sec "	,	//	183	01-33   IODHT IO direct hold time   
    "�ݤl�������h�ɶ�sec "	,	//  184 01-34   IODLT IO direct landing freq
    "�ݤl�����Ķq����    "	,	//  185 01-35   IODLT IO direct landing time
    "�ݤl������t�Z��cm  "	,	//  186 01-36   IODLT IO direct DistancE
    "�����ѦҴ�t�Z��m   "	,	//  187 01-37   IODLT IO direct DistancE
    "�ݤl�������a�P��    "	,	//  188 01-38   IODLT IO direct DistancE
    "ETS�W�v����Ǧ� Hz  "  ,   //  189 01-39   IODLT IO direct DistancE
    "����t��t�ɶ�sec "	,	//  190 01-40   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Emergency DEC   sec "  ,   //  105 15-105  RESERVE
    "Emergency S3    sec "  ,   //  105 15-105  RESERVE
    "Emergency S4    sec "  ,   //  105 15-105  RESERVE
#else
    "�O�d                "	,	//	191 01-41   RESERVED
    "�O�d                "	,	//	192 01-42   RESERVED
    "�O�d                "	,	//	193 01-43   RESERVED
#endif    
    "�ݤl����Ĳ�o�t��Hz  "	,	//	194 01-44   MI direct stop trigger speed	//Task 268622 IO Direct Landing	//Mitong 20230221 add	
    "�O�d                "	,	//	195 01-45   RESERVED
    "�O�d                "	,	//	196 01-46   RESERVED
    "�O�d                "	,	//	197 01-47   RESERVED
    "�O�d                "	,	//	198 01-48   RESERVED
    "�O�d                "	,	//	199 01-49   RESERVED

    
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "2/3 �u���B�౱��    "	,	//	200	02-00	2/3 wire control                
    "MI1�\\����        "	,	//	201	02-01	Multi-Function Input 1          
    "MI2�\\����        "	,	//	202	02-02	Multi-Function Input 2       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]       
    "MI3�\\����        "	,	//	203	02-03	Multi-Function Input 3       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI4�\\����        "	,	//	204	02-04	Multi-Function Input 4       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI5�\\����        "	,	//	205	02-05	Multi-Function Input 5       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI6�\\����        "	,	//	206	02-06	Multi-Function Input 6       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI7�\\����        "	,	//	207	02-07	Multi-Function Input 7       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]      
    "MI8�\\����        "	,	//	208	02-08	Multi-Function Input 8       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "�Ʀ��J�T���ɶ�sec "	,	//	209	02-09	Digital in response time		
    "�Ʀ��J��V        "	,	//	210	02-10	Multi-Function Input Inverse	
    "RA �\\����        "	,	//	211	02-11	Multi-Function Relay 1	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MRA�\\����        "	,	//	212	02-12	Multi-Function Relay 2	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "R1A�\\����        "	,	//	213	02-13	Multi-Function Output 1	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19] 	    
    "R2A�\\����        "	,	//	214	02-14	Multi-Function Output 2	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO1�\\����        "	,	//	215	02-15	Multi-Function Output 3	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO2�\\����        "	,	//	216	02-16	Multi-Function Output 4	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO3�\\����        "	,	//	217	02-17	Multi-Function Output 5	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO4�\\����        "	,	//	218	02-18	Multi-Function Output 6	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]    
    "MO5�\\����        "	,	//	219	02-19	Multi-Function Output 7	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO6�\\����        "	,	//	220	02-20	Multi-Function Output 8	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO7�\\����        "	,	//	221	02-21	Multi-Function Output 9	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "MO8 �\\����       "	,	//	222	02-22	Multi-Function Output 10	   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]	    
    "�Ʀ��X��V        "	,	//	223	02-23	Multi-Function Output inverse	
    "�ҰʫH���Ҧ����    "  ,   //  224 02-24   Sequence start mode
    "���N�W�v��F1   Hz  "	,	//	225	02-25	Desired Frequency 1		        
    "���N�W�v��F1�e Hz  "	,	//	226	02-26	Band of Desired Frequency 1		
    "���N�W�v��F2   Hz  "	,	//	227	02-27	Desired Frequency 2		        
    "���N�W�v��F2�e Hz  "	,	//	228	02-28	Band of Desired Frequency 2		
    "����٨���h����sec "	,	//	229	02-29	Brake Delay Timer at run
    "����٨���h����sec "	,	//	230	02-30	Brake Delay Timer at stop
    "�q�ϻ־ɳq����  sec "	,	//	231	02-31	Mech Contact Delay Timer run
    "�q�ϻ��_�}����  sec "	,	//	232	02-32	Mech Contact Delay Timer stop				            
    "�q�y�Ǧ�]�w    %   "	,	//	233	02-33	Isum Current Output Detect	    
    "�t�װϬq�]�w    Hz  "	,	//	234	02-34	Speed Area
    "����٨��˥X�ɶ�sec "	,	//	235 02-35	Mechanical Brake Checking Time
    "�q�ϻ��˥X�ɶ�  sec "	,	//	236 02-36   Magnetic Contactor Checking Time
    "��x�T�{�ʧ@���    "  ,   //  237 02-37   Mechanical Brake Checking Current Enable
    "�ʬP�ɳq���ɶ�  sec "  ,   //  238 02-38   Mech Contact Delay Timer run            //[Star contactor function, Bernie, 2017/03/22] 
    "�ʬP�_�}���ɶ�  sec "  ,   //  239 02-39   Mech Contact Delay Timer stop           //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD���`���       "  ,   //  240 02-40   LU/LD error  Selection	                //#15977, LULD detect, James, 2021/04/01
	"LU/LD�}������   sec "  ,   //  241 02-41   LD/LD Open Detect Time                  //#15977, LULD detect, James, 2021/04/01
	"LU/LD�u������   sec "  ,   //  242 02-42   LD/LD Short Detect Time                 //#15977, LULD detect, James, 2021/04/01
    "�B��t�ר�F�e��Hz  "	,	//  243 02-43   Band of Speed Agree Function #18572			
    "STO�u�������ɶ� sec "  ,   //  244 02-44   STO shor detect time                    //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  245 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "�t�׭���        m/s "  ,   //  246 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06]

    "�O�d                "	,	//	247 02-47   RESERVED
    "�O�d                "	,	//	248 02-48   RESERVED
    "�O�d                "	,	//	249 02-49   RESERVED
    "�O�d                "	,	//	250 02-50   RESERVED
    "�O�d                "	,	//	251 02-51   RESERVED
    "�O�d                "	,	//	252 02-52   RESERVED
    "�O�d                "	,	//	253 02-53   RESERVED
    "�O�d                "	,	//  254 02-54   RESERVED
    "�O�d                "	,	//	255 02-55   RESERVED
    "�O�d                "	,	//	256 02-56   RESERVED
    "�O�d                "	,	//	257 02-57   RESERVED
    "�O�d                "	,	//	258 02-58   RESERVED
    "�O�d                "	,	//	259 02-59   RESERVED
    "�O�d                "	,	//	260 02-60   RESERVED
    "�O�d                "	,	//	261 02-61   RESERVED
    "�O�d                "	,	//	262 02-62   RESERVED
    "�O�d                "	,	//	263 02-63   RESERVED
    "�O�d                "	,	//  264 02-64   RESERVED
    "�O�d                "	,	//	265 02-65   RESERVED
    "�O�d                "	,	//	266 02-66   RESERVED
    "�O�d                "	,	//	267 02-67   RESERVED
    "�O�d                "	,	//	268 02-68   RESERVED
    "�O�d                "	,	//	269 02-69   RESERVED
    "�O�d                "	,	//	270 02-70   RESERVED
    "�O�d                "	,	//	271 02-71   RESERVED
    "�O�d                "	,	//	272 02-72   RESERVED
    "�O�d                "	,	//	273 02-73   RESERVED
    "�O�d                "	,	//  274 02-74   RESERVED
    "�O�d                "	,	//	275 02-75   RESERVED
    "�O�d                "	,	//	276 02-76   RESERVED
    "�O�d                "	,	//	277 02-77   RESERVED
    "�O�d                "	,	//	278 02-78   RESERVED
    "�O�d                "	,	//	279 02-79   RESERVED
    "�O�d                "	,	//	280 02-80   RESERVED
    "�O�d                "	,	//	281 02-81   RESERVED
    "�O�d                "	,	//	282 02-82   RESERVED
    "�O�d                "	,	//	283 02-83   RESERVED
    "�O�d                "	,	//  284 02-84   RESERVED
    "�O�d                "	,	//	285 02-85   RESERVED
    "�O�d                "	,	//	286 02-86   RESERVED
    "�O�d                "	,	//	287 02-87   RESERVED
    "�O�d                "	,	//	288 02-88   RESERVED
    "�O�d                "	,	//	289 02-89   RESERVED
    "�O�d                "	,	//	280 02-90   RESERVED
    "�O�d                "	,	//	291 02-91   RESERVED
    "�O�d                "	,	//	292 02-92   RESERVED
    "�O�d                "	,	//	293 02-93   RESERVED
    "�O�d                "	,	//  294 02-94   RESERVED
    "�O�d                "	,	//	295 02-95   RESERVED
    "�O�d                "	,	//	296 02-96   RESERVED
    "�O�d                "	,	//	297 02-97   RESERVED
    "�O�d                "	,	//	298 02-98   RESERVED
    "�O�d                "	,	//	299 02-99   RESERVED
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AUI1�\\����        "	,	//	300	03-00   AUI1 selection                    //[Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "�O�d                "	,	//	301	03-01   ACI  selection                    //[ACI function remove, Bernie, 01/20/2012]
    "AUI2�\\����        "	,	//  302	03-02   AUI2 selection                    //[Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1��J����    %   "	,	//	303	03-03   AUI1 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "�O�d                "	,	//	307	03-04   ACI  input Bias                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2��J����    %   "	,	//	305	03-05   AUI2 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1���t�����Ҧ�    "	,	//	306 03-06   AUI1 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "�O�d                "	,	//	307 03-07   ACI  input Polarity               //[ACI function remove, Bernie, 01/20/2012]
    "AUI2���t�����Ҧ�    "	,	//	308 03-08   AUI2 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1��J�W�q    %   "	,	//	309 03-09   AUI1 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "�O�d                "	,	//	310 03-10   ACI  input Gain                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2��J�W�q    %   "	,	//	311 03-11   AUI2 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1�o�i�ɶ�    sec "	,	//	312 03-12   Low pass filter of AUI1 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "�O�d                "	,	//	313 03-13   Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2�o�i�ɶ�    sec "	,	//	314 03-14   Low pass filter of AUI2 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "�������v�۾ǲ�      "	,	//	315 03-15   Loss of ACI                       //[ACI function remove, Bernie, 01/20/2012]
    "�O�d                "  ,   //  316 03-16   RESERVED 
    "AO1 ��X���        "	,	//	317 03-17   Analong Output 1
    "AO1 ��X�W�q    %   "	,	//	318 03-18   Analong Output 1 Gain
    "AO1 ��X�ϦV�P��    "	,	//	319 03-19   AO1 in minus value
    "AO2 ��X���        "	,	//	320 03-20   Analong Output 2
    "AO2 ��X�W�q    %   "	,	//	321 03-21   Analong Output 2 Gain
    "AO2 ��X�ϦV�P��    "	,	//	322 03-22   AO2 in minus value
    "AUI1�����J����    "	,	//	323 03-23   AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2�����J����    "	,	//	324 03-24   AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1��J�]�w        "	,	//	325  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2��J�]�w        "	,	//	326  03-26    AUI2 Communciate
	

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "�Ĺs�q�t        Hz  "	,   //  327 04-00   Multi-Speed 0
    "�Ĥ@�q�t        Hz  "	,   //  328 04-01   Multi-Speed 1
    "�ĤG�q�t        Hz  "	,   //  329 04-02   Multi-Speed 2
    "�ĤT�q�t        Hz  "	,   //  330 04-03   Multi-Speed 3
    "�ĥ|�q�t        Hz  "	,   //  331 04-04   Multi-Speed 4
    "�Ĥ��q�t        Hz  "	,   //  332 04-05   Multi-Speed 5
    "�Ĥ��q�t        Hz  "	,   //  333 04-06   Multi-Speed 6
    "�ĤC�q�t        Hz  "	,   //  334 04-07   Multi-Speed 7
    "�ĤK�q�t        Hz  "	,   //  345 04-08   Multi-Speed 8
    "�ĤE�q�t        Hz  "	,   //  346 04-09   Multi-Speed 9
    "�ĤQ�q�t        Hz  "	,   //  347 04-10   Multi-Speed 10 
    "�ĤQ�@�q�t      Hz  "	,   //  348 04-11   Multi-Speed 11
    "�ĤQ�G�q�t      Hz  "	,   //  349 04-12   Multi-Speed 12
    "�ĤQ�T�q�t      Hz  "	,   //  350 04-13   Multi-Speed 13
    "�ĤQ�|�q�t      Hz  "	,   //  351 04-14   Multi-Speed 14
    "�ĤQ���q�t      Hz  "	,   //  352 04-15   Multi-Speed 15
    "�ϴ��t��        m/s "  ,   //  353 04-16
    "���h�t��        m/s "  ,   //  354 04-17
    "�ϰ򯸳t��      m/s "  ,   //  355 04-18
    
    "�������Ƹ��v    mm  "  ,   //  356 04-19   GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //  357 04-20
    "TABST2 Status       "  ,   //  358 04-21
    
    "�̰����z�Ӽh        "  ,   //  359 04-22
    "�ثe�Ӽh            "  ,   //  360 04-23
    "�߽Įե�����    %   "  ,   //  361 04-24
    "�}��������v    sec "  ,   //  362 04-25
    "���t���l�ɶ�    ms  "  ,   //  363 04-26
    "�ۧɪO����      mm  "  ,   //  364 04-27 
    "�ثe��m ��     m   "  ,   //  365 04-28
    "�ثe��m �C     mm  "  ,   //  366 04-29
    "�ثe�߽� H          "  ,   //  367 04-30 
    "�ثe�߽� L          "  ,   //  368 04-31
    "�ۧɪO�߽� H        "  ,   //  369 04-32
    "�ۧɪO�߽� L        "  ,   //  370 04-33
    "���q���Z�߽�H       "  ,   //  371 04-34
    "���q���Z�߽�L       "  ,   //  372 04-35   
    "DLC�\\�ධ           "  ,  //  373 04-36   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "PDO��ܫ��A         "  ,   //  374 04-37
    "��t�}���e�\\�~�tmm  "  ,  //  375 04-38   // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "�̤j��t�ʤ���  %   "  ,   //  376 04-39   //[ADCO EPS Modify]
    "�u®�������v    mm  "  ,   //  377 04-40   //#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //  378 04-41
    "EST Count           "  ,   //  379 04-42
    "TABST0 Count        "  ,   //  380 04-43
    "TABST1 Count        "  ,   //  381 04-44
    "DDS1/UDS1�t��   m/s "  ,   //  382 04-45   DD1_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS2/UDS2�t��   m/s "  ,   //  383 04-46   DD2_Vlim  //Artemis speed limit, James, 20200220                                
    "DDS3/UDS3�t��   m/s "  ,   //  384 04-47   DD3_Vlim  //Artemis speed limit, James, 20200220                                      
    "DDS4/UDS4�t��   m/s "  ,   //  385 04-48   DD4_Vlim  //Artemis speed limit, James, 20200220
    "�\\�୶���]�w        "  ,  //  386 04-49   user page cahnge       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    
    "1 �Ӧ�m ��     m   "  ,   //  387 04-50   1Floor Position H 
    "1 �Ӧ�m �C     mm  "  ,   //  388 04-51   1Floor Position L                                       
    "2 �Ӧ�m ��     m   "  ,   //  389 04-52   2Floor Position H                                       
    "2 �Ӧ�m �C     mm  "  ,   //  390 04-53   2Floor Position L                                       
    "3 �Ӧ�m ��     m   "  ,   //  391 04-54   3Floor Position H                                       
    "3 �Ӧ�m �C     mm  "  ,   //  392 04-55   3Floor Position L                                       
    "4 �Ӧ�m ��     m   "  ,   //  393 04-56   4Floor Position H                                       
    "4 �Ӧ�m �C     mm  "  ,   //  394 04-57   4Floor Position L                                       
    "5 �Ӧ�m ��     m   "  ,   //  395 04-58   5Floor Position H                                       
    "5 �Ӧ�m �C     mm  "  ,   //  396 04-59   5Floor Position L                                       
    "6 �Ӧ�m ��     m   "  ,   //  397 04-60   6Floor Position H                                       
    "6 �Ӧ�m �C     mm  "  ,   //  398 04-61   6Floor Position L                                       
    "7 �Ӧ�m ��     m   "  ,   //  399 04-62   7Floor Position H                                       
    "7 �Ӧ�m �C     mm  "  ,   //  400 04-63   7Floor Position L                                       
    "8 �Ӧ�m ��     m   "  ,   //  401 04-64   8Floor Position H                                       
    "8 �Ӧ�m �C     mm  "  ,   //  402 04-65   8Floor Position L                                       
    "9 �Ӧ�m ��     m   "  ,   //  403 04-66   9Floor Position H                                       
    "9 �Ӧ�m �C     mm  "  ,   //  404 04-67   9Floor Position L                                       
    "10�Ӧ�m ��     m   "  ,   //  405 04-68   10Floor Position H                                      
    "10�Ӧ�m �C     mm  "  ,   //  406 04-69   10Floor Position L                                      
    "11�Ӧ�m ��     m   "  ,   //  407 04-70   11Floor Position H                                      
    "11�Ӧ�m �C     mm  "  ,   //  408 04-71   11Floor Position L                                      
    "12�Ӧ�m ��     m   "  ,   //  409 04-72   12Floor Position H                                      
    "12�Ӧ�m �C     mm  "  ,   //  410 04-73   12Floor Position L                                      
    "13�Ӧ�m ��     m   "  ,   //  411 04-74   13Floor Position H                                      
    "13�Ӧ�m �C     mm  "  ,   //  412 04-75   13Floor Position L                                      
    "14�Ӧ�m ��     m   "  ,   //  413 04-76   14Floor Position H                                      
    "14�Ӧ�m �C     mm  "  ,   //  414 04-77   14Floor Position L                                      
    "15�Ӧ�m ��     m   "  ,   //  415 04-78   15Floor Position H                                      
    "15�Ӧ�m �C     mm  "  ,   //  416 04-79   15Floor Position L                                      
    "16�Ӧ�m ��     m   "  ,   //  417 04-80   16Floor Position H                                      
    "16�Ӧ�m �C     mm  "  ,   //  418 04-81   16Floor Position L                                      
    "17�Ӧ�m ��     m   "  ,   //  419 04-82   17Floor Position H                                      
    "17�Ӧ�m �C     mm  "  ,   //  420 04-83   17Floor Position L                                      
    "18�Ӧ�m ��     m   "  ,   //  421 04-84   18Floor Position H                                      
    "18�Ӧ�m �C     mm  "  ,   //  422 04-85   18Floor Position L                                      
    "19�Ӧ�m ��     m   "  ,   //  423 04-86   19Floor Position H                                      
    "19�Ӧ�m �C     mm  "  ,   //  424 04-87   19Floor Position L                                      
    "20�Ӧ�m ��     m   "  ,   //  425 04-88   20Floor Position H                                      
    "20�Ӧ�m �C     mm  "  ,   //  426 04-89   20Floor Position L                                      
    "21�Ӧ�m ��     m   "  ,   //  427 04-90   21Floor Position H                                      
    "21�Ӧ�m �C     mm  "  ,   //  428 04-91   21Floor Position L                                      
    "22�Ӧ�m ��     m   "  ,   //  429 04-92   22Floor Position H                                      
    "22�Ӧ�m �C     mm  "  ,   //  430 04-93   22Floor Position L                                      
    "23�Ӧ�m ��     m   "  ,   //  431 04-94   23Floor Position H                                      
    "23�Ӧ�m �C     mm  "  ,   //  432 04-95   23Floor Position L                                      
    "24�Ӧ�m ��     m   "  ,   //  433 04-96   24Floor Position H                                      
    "24�Ӧ�m �C     mm  "  ,   //  434 04-97   24Floor Position L                                      
    "25�Ӧ�m ��     m   "  ,   //  435 04-98   25Floor Position H                                      
    "25�Ӧ�m �C     mm  "  ,   //  436 04-99   25Floor Position L                                      
    
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM�ѼƦ۾ǲ�        "	,	//	437 05-00	Motor Auto-Tuning
    "IM�q���B�w�q�y  Amps"	,	//	438 05-01	Motor 1 rated Current           
    "IM�q���B�w�\\�v  Kw  "	,	//	439 05-02	Motor 1 Rated Power       // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]           
    "IM�q���B�w��t  RPM "	,	//	440 05-03	Motor 1 Rated RPM               
    "IM�q������          "	,	//	441 05-04	Motor 1 pole No.                
    "IM�q���L���q�y  Amps"	,	//	442 05-05	Motor 1 No-Load Current         
    "IM�q���Ѽ� Rs   ohm "	,	//	443 05-06	Motor 1 Rs                      
    "IM�q���Ѽ� Rr   ohm "	,	//	444 05-07	Motor 1 Rr                      
    "IM�q���Ѽ� Lm   mH  "	,	//	445 05-08	Motor 1 Lm                      
    "IM�q���Ѽ� Lx   mH  "	,	//	446 05-09	Motor 1 Lx                      
    "��x���v�C�q�o�isec "	,	//	447 05-10	Vector Voltage Filter	        
    "�Ʈt���v�C�q�o�isec "	,	//	448 05-11	Vector Slip Filter	            
    "��x���v�W�q        "	,	//	449 05-12	Torque Compensation Gain	    
    "�Ʈt���v�W�q        "	,	//	450 05-13	Slip Compensation Gain	        
    "�Ʈt�~�t�Ǧ�    %   "	,	//	451 05-14	Slip Deviation level	        
    "�Ʈt�~�t�˥X�ɶ�sec "	,	//	452 05-15	Slip Deviation Detect Time	    
    "�L�Ʈt�˥X���      "	,	//	453 05-16	Over Slip treatment	            
    "�_�����v�]�l        "	,	//	454 05-17	Coeff for hunting disable	    
    "�ֿn�q���B��ɶ�Mins"	,	//	455 05-18	Accumulative Motor Operation Min
    "�ֿn�q���B��Ѽ�Days"	,	//	456 05-19	Accumulative Motor Operation Day
    "�K���l�����v    %   "	,	//	457 05-20	Coreloss % of output Power	    
    "���W���W�q�ɶ�  Mins"	,	//	458 05-21	Power On Min
    "���W���W�q�Ѽ�  Days"	,	//	459 05-22	Power On Day    
    "�^�ͷƮt���v�W�q%   "  ,   //  460 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"�q�ʷƮt���v�W�q%   "	,	//	461 05-24   RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "�C�q�����      V   "	,	//	462 06-00	Low voltage level
    "��۫O�@            "	,	//	463 06-01	Phase loss
    "�[�t�L�q�y���t  %   "	,	//	464 06-02	OC stall during Accel
    "�w�t�L�q�y���t  %   "	,	//	465 06-03	OC stall during Decel
    "�L�q�y���t�B�z      "	,	//  466 06-04	Stall preventation Accel/Decel time selection
    "�L��xOT1�B�z       "	,	//	467 06-05	Over-Torque 1 Selection
    "�L��xOT1���   %   "	,	//	468 06-06	Over-Torque 1 level
    "�L��xOT1�˥X   sec "	,	//	469 06-07	Over-Torque 1 Time
    "�L��xOT2�B�z       "	,	//	470 06-08	Over-Torque 2 Selection	                     
    "�L��xOT2���   %   "	,	//	471 06-09	Over-Torque 2 level	                         
    "�L��xOT2�˥X   sec "	,	//	472 06-10	Over-Torque 2 Time	                         
    "�q�y����        %   "	,	//	473 06-11	Current Limit
    "�q�l���q����      "	,	//	474 06-12	Thermal Relay 1 Selection
    "���q��@�ήɶ�  sec "	,	//	475 06-13	Thermal Relay 1 Time
    "�L��ĵ�i�ūצ��C   "	,	//	476 06-14	OH Warning Level
    "���t�������%   "	,	//	477 06-15	Stall preventation Limit Level
    "�̪�@���G�٬���    "	,	//	478 06-16	1st Fault Record
    "2���e���G�٬���     "	,	//	479 06-17	2nd Fault Record
    "3���e���G�٬���     "	,	//	480 06-18	3rd Fault Record
    "4���e���G�٬���     "	,	//	481 06-19	4th Fault Record
    "5���e���G�٬���     "	,	//	482 06-20	5th Fault Record
    "6���e���G�٬���     "	,	//	483 06-21	6th Fault Record
    "���`��X��� 1      "	,	//	484 06-22	Fault Option 1
    "���`��X��� 2      "	,	//	485 06-23	Fault Option 2
    "���`��X��� 3      "	,	//	486 06-24	Fault Option 3
    "���`��X��� 4      "	,	//	487 06-25	Fault Option 4
    "PTC�ʧ@���         "	,	//	488 06-26	PTC over Treatments	                         
    "PTC�Ǧ�         %   "	,	//	489 06-27	PTC Level
    "PTC�˥X�ɶ�     sec "	,	//	490 06-28	PTC Detect Filter time
    "���B��q���q��V   "	,	//	491 06-29	EPS voltage level
    "���~��X���        "	,	//	492 06-30	Fault Option Mode
    "ED ��X��۰���     "	,	//	493 06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "�e�@�����`�B��  Mins"	,	//	494 06-32	1st Fault Time(MIN)
    "�e�@�����`�B��  Days"	,	//	495 06-33	1st Fault Time(DAY)
    "2���e���`�B��   Mins"	,	//	496 06-34	2nd Fault Time(MIN)
    "2���e���`�B��   Days"	,	//	497 06-35	2nd Fault Time(DAY)
    "3���e���`�B��   Mins"	,	//	498 06-36	3rd Fault Time(MIN)
    "3���e���`�B��   Days"	,	//	499 06-37	3rd Fault Time(DAY)
    "4���e���`�B��   Mins"	,	//	500 06-38	4th Fault Time(MIN)
    "4���e���`�B��   Days"	,	//	501 06-39	4th Fault Time(DAY)
    "5���e���`�B��   Mins"	,	//	502 06-40	5th Fault Time(MIN)
    "5���e���`�B��   Days"	,	//	503 06-41	5th Fault Time(DAY)
    "6���e���`�B��   Mins"	,	//	504 06-42	6th Fault Time(MIN)
    "6���e���`�B��   Days"	,	//	505 06-43	6th Fault Time(DAY)
    "���q���B��t��Hz  "  ,   //  506 06-44	EPS Frequency
    "���~�ʧ@���        "  ,	//  507 06-45   LV Option Mode
    "EPS �Ҧ����        "  ,	//  508 06-46   EPS Option Mode
    "�o�q��V�j�M�ɶ�sec "  ,   //  509 06-47   Generation Operation Detected Time
    "���B��q���e�qKVA "  ,   //  510 06-48   UPS Capacity (0.1KVA)
    "STO�\\����        "  ,   //  511 06-49   STO Lock selection     //[Safty function, Bernie]    
    "�G�٭��ծ�MO�ʧ@    "  ,   //  512 06-50   Base Block Speed Search (oc,ov,occ.......)  //[Add auto restart after fault, Bernie, 06/06/12]
    "�G�٭��զ���        "  ,   //  513 06-51   Auto restart times after fault     
    "�G�٭��ծɶ�    sec "  ,   //  514 06-52   Auto restart interval
    "���`���W�v�R�O  Hz  "  ,   //	515 06-53   Fkey Record
    "���`���W�v��X  Hz  "  ,   //	516 06-54   Fcmd Record
    "���`�ɿ�X�q�y  Amps"  ,   //	517 06-55	Isum Record
    "���`�ɰ��F�W�v  Hz  "  ,   //	518 06-56	Fout Record
    "���`�ɿ�X�q��  V   "  ,   //	519 06-57	Vout Record
    "���`��DCBus�q�� V   "  ,   //  520 06-58	Dcbus Record    
    "���`�ɿ�X�\\�v  KW  "  ,  //	521 06-59   Power Record                                // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "���`�ɿ�X��x  %   "  ,   //	522 06-60   Torque Record
    "���`��IGBT�ū�  C   "  ,   //	523 06-61	IGBT Temperature Record   
    "���`�ɿ�J�ݤl  Hex "  ,   //	524 06-62   MFI State Record
    "���`�ɿ�X�ݤl  Hex "  ,   //	525 06-63   MFO State Record
    "���`���X�ʾ����AHex "  ,   //	526 06-64   Drive State Record
    "UCMP�q�y����Ǧ�%   "  ,   //  527 06-65   Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
    "�X�ʾ��A�Ȧ���      "  ,   //  528 06-66   Service time count                          //[Service time function, Bernie, 2017/03/14]
    "�X�ʾ��A�ȳ]�w      "  ,   //  529 06-67   Service time function Enable                //[Service time function, Bernie, 2017/03/14]
    "EPS�����\\�]�Ǧ� deg "  ,  //  530 06-68   EPS Detect Current    
    "EPS�\\�]��       deg "  ,  //  531 06-69   EPS Detect Current Ref
    "EPS��V��X         "  ,   //  532 06-70   EPS Detect direction
    "EPS�ݤl��X���� sec "  ,   //  533 06-71   EPS MO Off Time
    "EPS�ݤl���X���� sec "  ,   //  534 06-72   EPS MO Off Time
    "�ä[�B���V�p��H   "	,	//	535 06-73   Running direction count high						
    "�ä[�B���V�p��L   "	,	//	536 06-74   Running direction count low
    "�榸�B���V�p��H   "	,	//	537 06-75   Temp running direction count high
    "�榸�B���V�p��L   "	,	//  538 06-76   Temp running direction count low
    "�榸�B�歫�m����    "	,	//	539 06-77   Temp running reset count
    "�B���V�����k   "	,	//	540 06-78   Running life
    "�B�榸�ƥ\\��ﶵ    "	,	//	541 06-79   Running function
    "���`2���W�v��X  Hz  " ,   //  542 06-80   Fcmd Record1
    "���`2��DCBus�q�� V   " ,   //  543 06-81   Dcbus Record1
    "���`2�ɿ�X�q�y  Amps" ,   //  544 06-82   Isum Record1
    "���`2��IGBT�ū�  C   "	,	//  545 06-83   IGBT Temperature Record1
    "���`3���W�v��X  Hz  " ,   //  546 06-84   Fcmd Record2
    "���`3��DCBus�q�� V   " ,   //  547 06-85   Dcbus Record2
    "���`3�ɿ�X�q�y  Amps" ,   //  548 06-86   Isum Record2
    "���`3��IGBT�ū�  C   " ,   //  549 06-87   IGBT Temperature Record2
    "���`4���W�v��X  Hz  " ,   //  550 06-88   Fcmd Record3
    "���`4��DCBus�q�� V   " ,   //  551 06-89   Dcbus Record3
    "���`4�ɿ�X�q�y  Amps" ,   //  552 06-90   Isum Record3
    "���`4��IGBT�ū�  C   " ,   //  553 06-91   IGBT Temperature Record3
    "���`5���W�v��X  Hz  " ,   //  554 06-92   Fcmd Record4
    "���`5��DCBus�q�� V   " ,   //  555 06-93   Dcbus Record4
    "���`5�ɿ�X�q�y  Amps" ,   //  556 06-94   Isum Record4
    "���`5��IGBT�ū�  C   " ,   //  557 06-95   IGBT Temperature Record4
    "���`6���W�v��X  Hz  " ,   //  558 06-96   Fcmd Record5
    "���`6��DCBus�q�� V   " ,   //  559 06-97   Dcbus Record5
    "���`6�ɿ�X�q�y  Amps" ,   //  560 06-98   Isum Record5
    "���`6��IGBT�ū�  C   " ,   //  561 06-99   IGBT Temperature Record5

/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "�٨������q���V   "	,	//	562 07-00	SW Braking Level
    "�٨�����𺢹q��V   "  ,   //	563 07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "�_�ʪ��y��ʷǦ�%   "	,	//	564 07-02	DCI Current Level     //[DCI Level when stop, Bernie, 05/21/2012]
    "�_�ʪ��y��ʮɶ�sec "	,	//	565 07-03	DCI Time at Start 
    "�������y��ʮɶ�sec "	,	//	566 07-04	DCI Time at STOP
    "������ʰ_�l�W�vHz  "	,	//	567 07-05	DCI Freq. At start
    "���y���I�W�q       "	,	//	568 07-06	DCI KI
    "���إ[�t���_�ɶ�sec "	,	//	569 07-07	Gear wait time when acceleration
    "���إ[�t���_�W�vHz  "	,	//	570 07-08	Gear wait frequency when acceleration
    "���ش�t���_�ɶ�sec "	,	//	572 07-09	Gear wait time when deceleration
    "���ش�t���_�W�vHz  "	,	//	573 07-10	Gear wait frequency when deceleration
    "��������覡        "	,	//	574 07-11	Fan Control
    "��x�R�O        %   "	,	//	575 07-12	TQC Reference from RS485
    "��x�R�O�ӷ�        "	,	//	576 07-13	Source of Torque Command
    "�̤j��x�R�O    %   "	,	//	577 07-14	Torque max. level
    "��x�R�O�o�i�ɶ�sec "	,	//	578 07-15	Torque command filter
    "�t�׭�����        "	,	//	579 07-16	Speed Limit selection
    "��x�Ҧ�+SPD����%   "	,	//	580 07-17	Torque mode positive speed limit
    "��x�Ҧ�-SPD����%   "	,	//  581 07-18	Torque mode negative speed limit
    "��x�R�O�����ӷ�    "	,	//	582 07-19	Torque offset selection
    "��x�R�O�����]�w%   "	,	//	583 07-20	Torque offset setting level
    "����x���q      %   "	,	//	584 07-21	Torque offset setting level High
    "����x���q      %   "	,	//	585 07-22	Torque offset setting level Middle
    "�C��x���q      %   "	,	//	586 07-23	Torque offset setting level Low
    "����q����x����%   "	,	//	587 07-24	FWD Motoring Tq Limit
    "����^����x����%   "	,	//	588 07-25	FWD Regeneration Tq Limit
    "����q����x����%   "	,	//	589 07-26	REV Motoring Tq Limit
    "����^����x����%   "	,	//	590 07-27	REV Regeneration Tq Limit
    "�j����˥X�覡    "	,	//	591 07-28	Emergency Stop & Forced Stop selection
    "������x����ɶ�sec "	,	//	592 07-29   Torque Decrease Time
    "����y��ʷǦ�%   "	,	//	593 07-30   STOP DC Inject Level     //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  594 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�˴�            "  ,   //  595 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�˴��Z��     ppr"  ,   //  596 07-33   /[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�˴����        "  ,   //  597 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�˴�������x    "  ,   //  598 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�˴��̤p��x    "  ,   //  599 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�˴��̤j��x    "  ,   //  600 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]

    "�O�d                "  ,   //	601 07-38   RESERVED
    "�O�d                "  ,   //	602 07-39   RESERVED
    "�O�d                "  ,   //	603 07-40   RESERVED
    "�O�d                "  ,   //	604 07-41   RESERVED
    "�O�d                "  ,   //	605 07-42   RESERVED
    "�O�d                "  ,   //  606 07-43   RESERVED
    "�O�d                "  ,   //  607 07-44   RESERVED
    "�O�d                "  ,   //  608 07-45   RESERVED
    "�O�d                "  ,   //  609 07-46   RESERVED
    "�O�d                "  ,   //  610 07-47   RESERVED
    "�O�d                "  ,   //  611 07-48   RESERVED
    "�O�d                "  ,   //  612 07-49   RESERVED
    "�O�d                "  ,   //  613 07-50   RESERVED
    "�O�d                "  ,   //  614 07-51   RESERVED
    "�O�d                "  ,   //	615 07-52   RESERVED
    "�O�d                "  ,   //	616 07-53   RESERVED
    "�O�d                "  ,   //	617 07-54   RESERVED
    "�O�d                "  ,   //	618 07-55   RESERVED
    "�O�d                "  ,   //	619 07-56   RESERVED
    "�O�d                "  ,   //  620 07-57   RESERVED
    "�O�d                "  ,   //	621 07-58   RESERVED
    "�O�d                "  ,   //	622 07-59   RESERVED
    "�O�d                "  ,   //	623 07-60   RESERVED
    "�O�d                "  ,   //	624 07-61   RESERVED
    "�O�d                "  ,   //	625 07-62   RESERVED
    "�O�d                "  ,   //	626 07-63   RESERVED
    "�O�d                "  ,   //  627 07-64   RESERVED
    "�O�d                "  ,   //  628 07-65   RESERVED
    "�O�d                "  ,   //  629 07-66   RESERVED
    "�O�d                "  ,   //  630 07-67   RESERVED
    "�O�d                "  ,   //  631 07-68   RESERVED
    "�O�d                "  ,   //  632 07-69   RESERVED
    "�O�d                "  ,   //  633 07-70   RESERVED
    "�O�d                "  ,   //  634 07-71   RESERVED
    "�O�d                "  ,   //	635 07-72   RESERVED
    "�O�d                "  ,   //	636 07-73   RESERVED
    "�O�d                "  ,   //	637 07-74   RESERVED
    "�O�d                "  ,   //  638 07-75   RESERVED
    "�O�d                "  ,   //	639 07-76   RESERVED
    "�O�d                "  ,   //	640 07-77   RESERVED
    "�O�d                "  ,   //	641 07-78   RESERVED
    "�O�d                "  ,   //  642 07-79   RESERVED
    "�O�d                "  ,   //  643 07-80   RESERVED
    "�O�d                "  ,   //  644 07-81   RESERVED
    "�O�d                "  ,   //  645 07-82   RESERVED
    "�O�d                "  ,   //  646 07-83   RESERVED
    "�O�d                "  ,   //  647 07-84   RESERVED
    "�O�d                "  ,   //  648 07-85   RESERVED
    "�O�d                "  ,   //  649 07-86   RESERVED
    "�O�d                "  ,   //  650 07-87   RESERVED
    "�O�d                "  ,   //  651 07-88   RESERVED
    "�O�d                "  ,   //  652 07-89   RESERVED
    "�O�d                "  ,   //  653 07-90   RESERVED
    "�O�d                "  ,   //  654 07-91   RESERVED
    "�O�d                "  ,   //  655 07-92   RESERVED
    "�O�d                "  ,   //  656 07-93   RESERVED
    "�O�d                "  ,   //  657 07-94   RESERVED
    "�O�d                "  ,   //  658 07-95   RESERVED
    "�O�d                "  ,   //  659 07-96   RESERVED
    "�O�d                "  ,   //  660 07-97   RESERVED
    "�O�d                "  ,   //  661 07-98   RESERVED
    "�O�d                "  ,   //  662 07-99   RESERVED
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM�ѼƦ۾ǲ�        "	,	//	663 08-00	PMotor Auto-Tuning  
    "PM�q���B�w�q�y  Amps"	,	//	664 08-01	PMotor rated Current 
    "PM�q���B�w�\\�v  Kw  "	,	//	665 08-02	PMotor Rated Power           // [Fill up 20 bits for the parameter after specific BIG-5 character with space, Freeman, 2017/06/19]
    "PM�q���B�w��t  RPM "	,	//	666 08-03	PMotor Rated RPM    
    "PM�q������          "	,	//	667 08-04	PMotor pole No.     
    "PM�q���Ѽ� Rs   ohm "	,	//	668 08-05	PMotor Rs           
    "PM�q���Ѽ� Ld   mH  "	,	//	669 08-06	PMotor Ld           
    "PM�q���Ѽ� Lq   mH  "	,	//	670 08-07	PMotor Lq           
    "�q���Ϲq�ʶ�    Vrms"	,	//	671 08-08	PMotor Bemf coff	
    "�Ϸ�������      deg "	,	//	672 08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
    "�Ϸ����s�w��        "	,	//	673 08-10	//ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "�q�T��}            "	,	//	674 09-00   Comm Address                              
    "�q�T�ǰe�t��    kbps"	,	//	675 09-01   Tranmission speed                         
    "�q�T���~�B�z        "	,	//	676 09-02   Comm fault Treatment                      
    "�O���˥X�ɶ�    sec "	,	//	677 09-03   Comm Time out                             
    "�q�T�榡            "	,	//	678 09-04   Comm Protocol                             
    "�^������ɶ�    ms  "	,	//	679 09-05   ASC remote Response Delay Time, 1=100us   
    "CAN �q�T�]�v        "  ,   //	680 09-06   CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "CAN PDO�洤�ɶ� ms  "  ,   //  681 09-07   CAN PDO Handshaking Period
    "CAN PDO�q�T�O�� ms  "  ,   //	682 09-08   CAN Communiction Timeout 
    "�W����ѧO�X        "  ,   //	683 09-09   
    "FHM �Ȧs��          "  ,   //	684 09-10
    "DLC �Ȧs��1         "  ,   //	685 09-11
    "DLC �Ȧs��2         "  ,   //	686 09-12
    "DLC �Ȧs��3         "  ,   //	687 09-13   
    "PDO�ǰe���j     ms  "  ,   //	688 09-14   CAN fail rate---aevin 6/12/2017
/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"�s�X���������      "	,	//	689 10-00	Encoder TYPE                             
	"�s�X���ߨR�I��  ppr "	,	//	690 10-01	Encoder pulses	                    
	"�s�X����J����      "	,	//  691 10-02	PG input setting	                
	"PG���~�ʧ@���      "	,	//  692 10-03	PG fbk fault treatment	            
	"PG���~�˥X�ɶ�  sec "	,	//  693 10-04	PG fbk Error Detection Time	        
	"PG���t���      %   "	,	//  694 10-05	PG fbk overspeed detection level	
	"PF���t�˥X�ɶ�  sec "	,	//  695 10-06	Over speed Detection Time	        
	"PG��t���`���  %   "	,	//	696 10-07	PG fbk speed deviation level	    
	"PG��t�˥X�ɶ�  sec "	,	//	697 10-08	Deviation Detect Time	            
	"PG���t�ʧ@���      "	,	//	698 10-09	Operation at overspeed	            
	"HALL�H���Ҧ����    "  ,   //  699 10-10   Hall Input Types
	"�_�ʹs�t�W�qP       "	,	//	700 10-11	KP gain of ASR in Zero speed	
	"�_�ʹs�t�n��I   sec "	,	//	701 10-12	Ki gain of ASR in Zero speed	
	"�C�t�W�qP           "	,	//	702 10-13	ASR P Gain 1	                
	"�C�t�n���ɶ�I   sec "	,	//	703 10-14	ASR I Gain 1	                
	"���t�W�qP           "	,	//	704 10-15	ASR P Gain 2	                
	"���t�n���ɶ�I   sec "	,	//	705 10-16	ASR I Gain 2	                
	"�C/���t�����W�v Hz  "	,	//  706 10-17	ASR1/ASR2 switch freq	        
	"ASR�C�q�o�i�W�q sec "	,	//  707 10-18	Primary LowPass filter Gain 
	"��m����ASR�W�qP    "  ,	//  708 10-19   position control Kp Gain  
    "�s/�C�t�e�׽վ� Hz  "  ,   //  709 10-20   Low Spd band
    "�C/���t�e�׽վ� Hz  "  ,   //  710 10-21   High Spd band
	"��m����ASR�n��Isec "	,	//  711 10-22   Position control time
	"�_�ʦ�m����C�qsec "	,	//  712 10-23   Position control LOW POSS FILTER
	"��m����Ҧ����    "	,	//  713 10-24   Source of position control, add by dino, 06/30/2008
	"���h�s�t�W�qP   %   "	,	//  714 10-25	KP gain of ASR in Zero speed of Landing
	"���h�s�t�n��I   sec "	,	//	715 10-26	Ki gain of ASR in Zero speed of Landing
	"��m����s�t�W�q%   "	,	//	716 10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"��m����s�t�n��sec "	,	//	717 10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
    "PG�d���W��X��      "	,   //	718 10-29   PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG�d���W��X����    "	,   //	719 10-30   PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C-���        "  ,   //  720 10-31   RESERVED    //[change parameter to normal group, Bernie, 2014/02/14]
    "�q��L�[�t�׷Ǧ�m/s2"  ,   //	721 10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "�L�[�t�װ����ɶ�sec "  ,   //	722 10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "�L�[�t�װ����      "  ,   //	723 10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]

    "�O�d                "  ,   //	724 10-35   RESERVED
    "�O�d                "  ,   //	725 10-36   RESERVED
    "�O�d                "  ,   //	726 10-37   RESERVED
    "�O�d                "  ,   //	727 10-38   RESERVED
    "�O�d                "  ,   //	728 10-39   RESERVED
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "�t�α���        Hex "	,	//  729 11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "�̤j�W�v������tm/s "  ,   //  730 11-01   Lift operation speed                                        
    "���޽����|      mm  "  ,   //  731 11-02   SHEAVE diameter			ADDED BY SCOTTY                     
    "������              "  ,   //  732 11-03   Gear Ratio                                              
    "�a����              "  ,   //  733 11-04   Suspension ratio	                                        
    "����D�q�ʤ���  %   "  ,   //  734 11-05   inertia	percent			ADDED BY SCOTTY                     
    "�_�ʹs�t�W�e    Hz  "	,	//	735 11-06	Zero Speed Loop BandWidth	                                
    "�C�t�W�e        Hz  "	,	//	736 11-07	Speed Loop BandWidth1		                                
    "���t�W�e        Hz  "	,	//	737 11-08	Speed Loop BandWidth2		                                
    "PDFF�W�q��      %   "	,	//  738 11-09	PDFFKr		                                                
    "�t�ױ���e�X�W�q%   "	,	//	739 11-10	SPEED FFD GAIN			ADDED BY SCOTTY                     
    "�W���o�i�`��    db  "	,	//	740 11-11	Netch filter deep(db)	                                    
    "�W���o�i�W�v    Hz  "	,	//	741 11-12	Netch filter frequency	                                    
    "���O����o�i�ɶ�sec "	,	//  742 11-13	Low Pass Filter for display	                                
    "�[�t�ɳ̤j�q�y  %   "	,	//  743 11-14	ACC Max current                                             
    "�q��̤j�[�t��  m/s2"  ,	//  744 11-15	max meter/sec	                                            
    "�ʱ���Ʀ�}    Hex "  ,   //  745 11-16	Display address,add by dino 2007/03/08                      
    "�ʱ����            "  ,	//  746 11-17	Display data,   add by dino 2007/03/08                      
    "�O�d                "  ,   //  747 11-18   Protect Bit	                                                
    "�����s�t�W�e    Hz  "	,	//  748 11-19	Zero Speed Loop BandWidth of Landing
    "PWM �Ҧ����        "  ,   //  749 11-20	PWM mode selection  //[move parameter to 11-20, Bernie, 2017/02/16]
    "LC01����o�i�ɶ� sec"	,	//  750 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	750   11-21     Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22       //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]
    "�O�d                "  ,   //	752 11-23   RESERVED
    "�O�d                "  ,   //	753 11-24   RESERVED
    "�O�d                "  ,   //	754 11-25   RESERVED
    "�O�d                "  ,   //	755 11-26   RESERVED
    "�O�d                "  ,   //	756 11-27   RESERVED
    "�O�d                "  ,   //	757 11-28   RESERVED
    "�O�d                "  ,   //	758 11-29   RESERVED
    
/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "�ۭq�Ѽ� 1          "  ,   //  759 12-00
    "�ۭq�Ѽ� 2          "  ,   //  760 12-01
    "�ۭq�Ѽ� 3          "  ,   //  761 12-02
    "�ۭq�Ѽ� 4          "  ,   //  762 12-03
    "�ۭq�Ѽ� 5          "  ,   //	763 12-04
    "�ۭq�Ѽ� 6          "  ,   //	764 12-05
    "�ۭq�Ѽ� 7          "  ,   //	765 12-06
    "�ۭq�Ѽ� 8          "  ,   //	766 12-07
    "�ۭq�Ѽ� 9          "  ,   //	767 12-08
    "�ۭq�Ѽ� 10         "  ,   //	768 12-09
    "�ۭq�Ѽ� 11         "  ,   //	769 12-10
    "�ۭq�Ѽ� 12         "  ,   //	770 12-11
    "�ۭq�Ѽ� 13         "  ,   //	771 12-12
    "�ۭq�Ѽ� 14         "  ,   //	772 12-13
    "�ۭq�Ѽ� 15         "  ,   //	773 12-14
    "�ۭq�Ѽ� 16         "  ,   //  774 12-15
    "�ۭq�Ѽ� 17         "  ,   //	775 12-16
    "�ۭq�Ѽ� 18         "  ,   //	776 12-17
    "�ۭq�Ѽ� 19         "  ,   //	777 12-18
    "�ۭq�Ѽ� 20         "  ,   //	778 12-19 
    "�ۭq�Ѽ� 21         "  ,   //	779 12-20
    "�ۭq�Ѽ� 22         "  ,   //	780 12-21
    "�ۭq�Ѽ� 23         "  ,   //  781 12-22
    "�ۭq�Ѽ� 24         "  ,   //	782 12-23
    "�ۭq�Ѽ� 25         "  ,   //	783 12-24
    "�ۭq�Ѽ� 26         "  ,   //	784 12-25
    "�ۭq�Ѽ� 27         "  ,   //	785 12-26
    "�ۭq�Ѽ� 28         "  ,   //	786 12-27
    "�ۭq�Ѽ� 29         "  ,   //	787 12-28
    "�ۭq�Ѽ� 30         "  ,   //	788 12-29
    "�ۭq�Ѽ� 31         "  ,   //  789 12-30
    "�ۭq�Ѽ� 32         "  ,   //  790 12-31
    "�ۭq�Ѽ� 33         "  ,   //  791 12-32
    "�ۭq�Ѽ� 34         "  ,   //  792 12-33
    "�ۭq�Ѽ� 35         "  ,   //  793 12-34
    "�ۭq�Ѽ� 36         "  ,   //  794 12-35
    "�ۭq�Ѽ� 37         "  ,   //  795 12-36
    "�ۭq�Ѽ� 38         "  ,   //  796 12-37
    "�ۭq�Ѽ� 39         "  ,   //  797 12-38
    "�ۭq�Ѽ� 40         "  ,   //  798 12-39
    "�ۭq�Ѽ� 41         "  ,   //  799 12-40
    "�ۭq�Ѽ� 42         "  ,   //  800 12-41
    "�ۭq�Ѽ� 43         "  ,   //  801 12-42
    "�ۭq�Ѽ� 44         "  ,   //  802 12-43
    "�ۭq�Ѽ� 45         "  ,   //  803 12-44
    "�ۭq�Ѽ� 46         "  ,   //  804 12-45
    "�ۭq�Ѽ� 47         "  ,   //  805 12-46
    "�ۭq�Ѽ� 48         "  ,   //  806 12-47
    "�ۭq�Ѽ� 49         "  ,   //  807 12-48
    "�ۭq�Ѽ� 50         "  ,   //  808 12-49
    "�O�d                "  ,   //  809 12-50 
    "�O�d                "  ,   //  810 12-51 
    "�O�d                "  ,   //  811 12-52 
    "�O�d                "  ,   //  812 12-53 
    "�O�d                "  ,   //  813 12-54 
    "�O�d                "  ,   //  814 12-55 
    "�O�d                "  ,   //  815 12-56 
    "�O�d                "  ,   //  816 12-57 
    "�O�d                "  ,   //  817 12-58 
    "�O�d                "  ,   //  818 12-59 
    "�O�d                "  ,   //  819 12-60 
    "�O�d                "  ,   //  820 12-61 
    "�O�d                "  ,   //  821 12-62 
    "�O�d                "  ,   //  822 12-63 
    "�O�d                "  ,   //  823 12-64 
    "�O�d                "  ,   //  824 12-65 
    "�O�d                "  ,   //  825 12-66 
    "�O�d                "  ,   //  826 12-67 
    "�O�d                "  ,   //  827 12-68 
    "�O�d                "  ,   //  828 12-69 
    "�O�d                "  ,   //  829 12-70 
    "�O�d                "  ,   //  830 12-71 
    "�O�d                "  ,   //  831 12-72 
    "�O�d                "  ,   //  832 12-73 
    "�O�d                "  ,   //  833 12-74 
    "�O�d                "  ,   //  834 12-75 
    "�O�d                "  ,   //  835 12-76 
    "�O�d                "  ,   //  836 12-77 
    "�O�d                "  ,   //  837 12-78 
    "�O�d                "  ,   //  838 12-79 
    "�O�d                "  ,   //  839 12-80 
    "�O�d                "  ,   //  840 12-81 
    "�O�d                "  ,   //  841 12-82 
    "�O�d                "  ,   //  842 12-83 
    "�O�d                "  ,   //  843 12-84 
    "�O�d                "  ,   //  844 12-85 
    "�O�d                "  ,   //  845 12-86 
    "�O�d                "  ,   //  846 12-87 
    "�O�d                "  ,   //  847 12-88 
    "�O�d                "  ,   //  848 12-89 
    "�O�d                "  ,   //  849 12-90 
    "�O�d                "  ,   //  850 12-91 
    "�O�d                "  ,   //  851 12-92 
    "�O�d                "  ,   //  852 12-93 
    "�O�d                "  ,   //  853 12-94 
    "�O�d                "  ,   //  854 12-95 
    "�O�d                "  ,   //  855 12-96 
    "�O�d                "  ,   //  856 12-97 
    "�O�d                "  ,   //  857 12-98 
    "�O�d                "  ,   //  858 12-99 

/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "�۩w�`�ΰѼ� 1      "  ,   //  859 13-00
    "�۩w�`�ΰѼ� 2      "  ,   //  860 13-01
    "�۩w�`�ΰѼ� 3      "  ,   //  861 13-02
    "�۩w�`�ΰѼ� 4      "  ,   //  862 13-33
    "�۩w�`�ΰѼ� 5      "  ,   //  863 13-04
    "�۩w�`�ΰѼ� 6      "  ,   //  864 13-05
    "�۩w�`�ΰѼ� 7      "  ,   //  865 13-06
    "�۩w�`�ΰѼ� 8      "  ,   //  866 13-07
    "�۩w�`�ΰѼ� 9      "  ,   //  867 13-08
    "�۩w�`�ΰѼ� 10     "  ,   //  868 13-09
    "�۩w�`�ΰѼ� 11     "  ,   //  869 13-10
    "�۩w�`�ΰѼ� 12     "  ,   //  870 13-11
    "�۩w�`�ΰѼ� 13     "  ,   //  871 13-12
    "�۩w�`�ΰѼ� 14     "  ,   //  872 13-13
    "�۩w�`�ΰѼ� 15     "  ,   //  873 13-14
    "�۩w�`�ΰѼ� 16     "  ,   //  874 13-15
    "�۩w�`�ΰѼ� 17     "  ,   //  875 13-16
    "�۩w�`�ΰѼ� 18     "  ,   //  876 13-17
    "�۩w�`�ΰѼ� 19     "  ,   //  877 13-18
    "�۩w�`�ΰѼ� 20     "  ,   //  878 13-19
    "�۩w�`�ΰѼ� 21     "  ,   //  879 13-20
    "�۩w�`�ΰѼ� 22     "  ,   //  880 13-21
    "�۩w�`�ΰѼ� 23     "  ,   //  881 13-22
    "�۩w�`�ΰѼ� 24     "  ,   //  882 13-23
    "�۩w�`�ΰѼ� 25     "  ,   //  883 13-24
    "�۩w�`�ΰѼ� 26     "  ,   //  884 13-25
    "�۩w�`�ΰѼ� 27     "  ,   //  885 13-26
    "�۩w�`�ΰѼ� 28     "  ,   //  886 13-27
    "�۩w�`�ΰѼ� 29     "  ,   //  887 13-28
    "�۩w�`�ΰѼ� 30     "  ,   //  888 13-29
    "�۩w�`�ΰѼ� 31     "  ,   //  889 13-30
    "�۩w�`�ΰѼ� 32     "  ,   //  890 13-31
    "�۩w�`�ΰѼ� 33     "  ,   //  891 13-32
    "�۩w�`�ΰѼ� 34     "  ,   //  892 13-33
    "�۩w�`�ΰѼ� 35     "  ,   //  893 13-34
    "�۩w�`�ΰѼ� 36     "  ,   //  893 13-35
    "�۩w�`�ΰѼ� 37     "  ,   //  894 13-36
    "�۩w�`�ΰѼ� 38     "  ,   //  895 13-37
    "�۩w�`�ΰѼ� 39     "  ,   //  896 13-38
    "�۩w�`�ΰѼ� 40     "  ,   //  897 13-39
    "�۩w�`�ΰѼ� 41     "  ,   //  898 13-30
    "�۩w�`�ΰѼ� 42     "  ,   //  899 13-41
    "�۩w�`�ΰѼ� 43     "  ,   //  900 13-42
    "�۩w�`�ΰѼ� 44     "  ,   //	901 13-43
    "�۩w�`�ΰѼ� 45     "  ,   //	902 13-44
    "�۩w�`�ΰѼ� 46     "  ,   //	903 13-45
    "�۩w�`�ΰѼ� 47     "  ,   //	904 13-46
    "�۩w�`�ΰѼ� 48     "  ,   //	905 13-47
    "�۩w�`�ΰѼ� 49     "  ,   //  906 13-48
    "�۩w�`�ΰѼ� 50     "  ,   //  907 13-49
    "�۩w�`�ΰѼ� 51     "  ,   //  908 13-50
    "�۩w�`�ΰѼ� 52     "  ,   //  909 13-51
    "�۩w�`�ΰѼ� 53     "  ,   //  910 13-52
    "�۩w�`�ΰѼ� 54     "  ,   //  911 13-53
    "�۩w�`�ΰѼ� 55     "  ,   //  912 13-54
    "�۩w�`�ΰѼ� 56     "  ,   //  913 13-55
    "�۩w�`�ΰѼ� 57     "  ,   //  914 13-56
    "�۩w�`�ΰѼ� 58     "  ,   //	915 13-57
    "�۩w�`�ΰѼ� 59     "  ,   //	916 13-58
    "�۩w�`�ΰѼ� 60     "  ,   //	917 13-59
    "�۩w�`�ΰѼ� 61     "  ,   //	918 13-60
    "�۩w�`�ΰѼ� 62     "  ,   //	919 13-61
    "�۩w�`�ΰѼ� 63     "  ,   //  920 13-62
    "�۩w�`�ΰѼ� 64     "  ,   //	921 13-63
    "�۩w�`�ΰѼ� 65     "  ,   //	922 13-64
    "�۩w�`�ΰѼ� 66     "  ,   //	923 13-65
    "�۩w�`�ΰѼ� 67     "  ,   //	924 13-66
    "�۩w�`�ΰѼ� 68     "  ,   //	925 13-67
    "�۩w�`�ΰѼ� 69     "  ,   //	926 13-68
    "�۩w�`�ΰѼ� 70     "  ,   //  927 13-69
    "�۩w�`�ΰѼ� 71     "  ,   //  928 13-70
    "�۩w�`�ΰѼ� 72     "  ,   //  929 13-71
    "�۩w�`�ΰѼ� 73     "  ,   //  930 13-72
    "�۩w�`�ΰѼ� 74     "  ,   //  931 13-73
    "�۩w�`�ΰѼ� 75     "  ,   //  932 13-74
    "�۩w�`�ΰѼ� 76     "  ,   //  933 13-75
    "�۩w�`�ΰѼ� 77     "  ,   //  934 13-76
    "�۩w�`�ΰѼ� 78     "  ,   //	935 13-77
    "�۩w�`�ΰѼ� 79     "  ,   //	936 13-78
    "�۩w�`�ΰѼ� 80     "  ,   //	937 13-79
    "�۩w�`�ΰѼ� 81     "  ,   //  938 13-80
    "�۩w�`�ΰѼ� 82     "  ,   //	939 13-81
    "�۩w�`�ΰѼ� 83     "  ,   //	940 13-82
    "�۩w�`�ΰѼ� 84     "  ,   //	941 13-83
    "�۩w�`�ΰѼ� 85     "  ,   //  942 13-84
    "�۩w�`�ΰѼ� 86     "  ,   //  943 13-85
    "�۩w�`�ΰѼ� 87     "  ,   //  944 13-86
    "�۩w�`�ΰѼ� 88     "  ,   //  945 13-87
    "�۩w�`�ΰѼ� 89     "  ,   //  946 13-88
    "�۩w�`�ΰѼ� 90     "  ,   //  947 13-89
    "�۩w�`�ΰѼ� 91     "  ,   //  948 13-90
    "�۩w�`�ΰѼ� 92     "  ,   //  949 13-91
    "�۩w�`�ΰѼ� 93     "  ,   //  950 13-92
    "�۩w�`�ΰѼ� 94     "  ,   //  951 13-93
    "�۩w�`�ΰѼ� 95     "  ,   //  952 13-94
    "�۩w�`�ΰѼ� 96     "  ,   //  953 13-95
    "�۩w�`�ΰѼ� 97     "  ,   //  954 13-96
    "�۩w�`�ΰѼ� 98     "  ,   //  955 13-97
    "�۩w�`�ΰѼ� 99     "  ,   //  956 13-98
    "�۩w�`�ΰѼ� 100    "  ,   //  957 13-99
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level%   "	,	//	958 14-00	Ids Power Save Level
	"VF CURVE MODE       "	,	//	959 14-01	VF voltage mode selection
	"Overload 1 Mode     "	,	//	960 14-02	Constant Torque Selection
	"Auto ACC/DEC        "	,	//	961 14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	962 14-04	Unit of Acc/Dec time
	"POWER SAVE MODE     "	,	//  963 14-05	Power Save mode
	"Stop Methods        "	,	//  964 14-06	Stop Methods
	"Reverse Operate     "	,	//  965 14-07	Reverse Operation
	"Skip Freq. 1UP  Hz  "	,	//  966 14-08	Skip Freq. Point 1 upper limit
	"Skip Freq. 1LOW Hz  "	,	//  967 14-09	Skip Freq. Point 1 lower limit
	"Skip Freq. 2UP  Hz  "	,	//  968 14-10	Skip Freq. Point 2 upper limit
	"Skip Freq. 2LOW Hz  "	,	//  969 14-11	Skip Freq. Point 2 lower limit
	"Skip Freq. 3UP  Hz  "	,	//  970 14-12	Skip Freq. Point 3 upper limit
	"Skip Freq. 3LOW Hz  "	,	//  971 14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz  "	,	//  972 14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//  973 14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//  974 14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//  975 14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//  976 14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//  977 14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2  Hz  "	,	//  978 14-20	Min Output Freq. 2
	"Min Out-Volt 2  V   "	,	//  979 14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//  980 14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//  981 14-23	up/down key speed
	"Counter Set         "	,	//  982 14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//  983 14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//  984 14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"Multi-Fun Input9    "	,	//  985 14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//  986 14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//  987 14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//  988 14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//  989 14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//  990 14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//  991 14-33	External Terminal Run after Fault Reset
	"ACI/AVI2 SEL        "	,	//  992 14-34	ACI change to AVI2
	"Addition of AI      "	,	//  993 14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//  993 14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//  994 14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//  995 14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//  996 14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//  997 14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//  998 14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//  999 14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//  1000 14-43	ulti-Position Point 8
	"Multi-Posit 9       "	,	//	1001 14-44	ulti-Position Point 9
	"Multi-Posit 10      "	,	//	1002 14-45	ulti-Position Point 10
	"Multi-Posit 11      "	,	//	1003 14-46	ulti-Position Point 11
	"Multi-Posit 12      "	,	//	1004 14-47	ulti-Position Point 12
	"Multi-Posit 13      "	,	//	1005 14-48	ulti-Position Point 13
	"Multi-Posit 14      "	,	//  1006 14-49	ulti-Position Point 14
	"Multi-Posit 15      "	,	//  1007 14-50	ulti-Position Point 15
	"MOTOR 1 OR 2        "	,	//  1008 14-51	otor Selection 1 or 2
	"Y-D Switch Hz   Hz  "	,	//  1009 14-52	-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//  1010 14-53	-Delta switched Enable
	"Motor2 Rated    Amps"	,	//  1011 14-54	otor 2 rated Current
	"Motor2 Rated P  Kw  "	,	//  1012 14-55	otor 2 Rated Power
	"Motor2 Rated    RPM "	,	//  1013 14-56	otor 2 Rated RPM
	"Motor2 Poles        "	,	//  1014 14-57	otor 2 pole No.
	"Motor2 No-Load  Amps"	,	//	1015 14-58	otor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	1016 14-59	otor 2 Rs
	"Motor2 Rr       ohm "	,	//	1017 14-60	otor 2 Rr
	"Motor2 Lm       mH  "	,	//	1018 14-61	otor 2 Lm
	"Motor2 Lx       mH  "	,	//	1019 14-62	otor 2 Lx
	"Y-D On Delay T      "	,	//  1020 14-63	-Delta On delay time
	"OV stall level  V   "	,	//	1021 14-64	V stall level
	"Thermal RLY2 SEL    "	,	//	1022 14-65	hermal Relay 2 Selection
	"Thermal RLY2 T      "	,	//	1023 14-66	hermal Relay 2 Time
	"Momentary Power     "	,	//	1024 14-67	omentary Power Loss
	"Power Loss Time sec "	,	//	1025 14-68	ax. allowable PL time
	"Base Block Time sec "	,	//	1026 14-69	B Time for speed serach
	"SPD Search Curr %   "	,	//  1027 14-70	urrent level for SPD serach
	"BB Treatment        "	,	//  1028 14-71	b treatment for oc, ov, bb
	"Auto Restart        "	,	//  1029 14-72	uto restart after fault
	"Restart Method      "	,	//  1030 14-73	uto restart Speed serach method
	"DEB Decel SEL       "	,	//  1031 14-74	eceleration at Momertary Power loss 
	"DEB Return Time     "	,	//  1032 14-75	EB Return Time
	"PID Fdb SEL         "	,	//  1033 14-76	ID feedback selection	
	"P Gain of PID       "	,	//  1034 14-77	 gain of PID	
	"I Gain of PID   sec "	,	//	1035 14-78	 gain of PID	
	"D Gain of PID       "	,	//	1036 14-79	 gain of PID	
	"Up Limit for I  %   "	,	//	1037 14-80	pper bound for integral	
	"PID Out-Limiter %   "	,	//  1038 14-81	ID output Freq. Limit	
	"PID Offset      %   "	,	//	1039 14-82	ID offset	
	"PID Out-Filter  sec "	,	//	1040 14-83	erivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	1041 14-84	eedback signal detection time	
	"PID Fdb Loss        "	,	//  1042 14-85	ID feedback loss	
	"SLEEP FREQ          "	,	//  1043 14-86	leep Frequency	
	"WAKE FREQ           "	,	//  1044 14-87	ake up Frequency	
	"SLEEP TIME          "	,	//  1045 14-88	leep Time	
	"PID DEV. LEVEL  %   "	,	//  1046 14-89	ID Deviation Level	
	"PID DEV. TIME       "	,	//  1047 14-90	ID Deviation Time	
	"PID Fbk Filter  sec "	,	//  1048 14-91	ID feedback filter	
	"Comm Main Freq. Hz  "	,	//  1049 14-92	ain Frequency from communication	
	"Block Trans. 1      "	,	//  1050 14-93	lock Transfer 1	
	"Block Trans. 2      "	,	//  1051 14-94	lock Transfer 2	
	"Block Trans. 3      "	,	//  1052 14-95	lock Transfer 3
	"Block Trans. 4      "	,	//  1053 14-96	lock Transfer 4
	"Block Trans. 5      "	,	//  1054 14-97	lock Transfer 5
	"Block Trans. 6      "	,	//  1055 14-98	lock Transfer 6
	"Block Trans. 7      "	,	//  1056 14-99	lock Transfer 7
	"Block Trans. 8      "	,	//  1057 14-100 Block Transfer 8
	"Block Trans. 9      "	,	//	1086 14-101 Block Transfer 9
	"Block Trans. 10     "	,	//	1087 14-102 Block Transfer 10
	"WEAKLPF             "	,	//	1088 14-103 WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	1089 14-104 WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	1090 14-105 OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"PG Position Home    "	,	//	1091 14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	1092 14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	1093 14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	1094 14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	1095 14-110 FMax Target by Vcommand Position
	"RESERVE             "	,	//	1096 14-111 Accel. Time for Position
	"PG Mech. Gear A     "	,	//	1097 14-112 PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	1098 14-113 PG Mechanical Gear B
	"System Jm       PU  "	,	//	1099 14-114 Interia of motor PU
	"M1IdsRef Limit   %  "	,	//	1100 14-115 Motor1 IdsRef Limit
	"M2IdsRef Limit   %  "	,	//  1101 14-116 Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	1102 14-117 Phase Loss Time
	"TH Inside Temp   C  "	,	//	1103 14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	1104 14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	1105 14-120 SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//  1106 14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	1107 14-122 Tension of Torque Control
	"DIAMETER        m   "	,	//	1108 14-123 Diameter of Material
	"DEPTH           cm  "	,	//	1109 14-124 Depth of meterial
	"RESERVE             "	,	//	1110 14-125 Reserve
	"ABZ ST Times        "	,	//	1111 14-126 Reserve
	"ABZ ST Duty         "	,	//	1112 14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	1113 14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	1114 14-129 Time of APR Curve
    "Jm source           "  ,   //	1115 14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	1116 14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	1117 14-132 muti input state
    "StandStill Curr.Amps"  ,   //  1118 14-133 Standstill Current
	"PG Scale Factor     "	,	//	1119 14-134 Division factor of PG	
	"OLD Irate           "	,	//	1120 14-135 OLD Irate       // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   //  1121 14-136 [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   //  1122 14-137 [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time  sec "	,   //  1123 14-138 [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   //  1124 14-139 [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"COM1�q�T��}        "	,	//	1125 14-140 Comm Address             //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                        
    "COM1�q�T�ǰe�t��kbps"	,	//	1126 14-141 Tranmission speed                         
    "COM1�q�T���~�B�z    "	,	//	1127 14-142 Comm fault Treatment                      
    "COM1�O���˥X�ɶ�sec "	,	//	1128 14-143 Comm Time out                             
    "COM1�q�T�榡        "	,	//	1129 14-144 Comm Protocol                             
    "COM1�^������ɶ�ms  "	,	//	1130 14-145 ASC remote Response Delay Time, 1=100us     
    "OPHL 10Hz COUNT     "  ,   //	1131 14-146 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "  ,   //	1132 14-147 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "  ,   //	1133 14-148 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "  ,   //	1134 14-149 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "  ,   //	1135 14-150 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "  ,   //	1136 14-151 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,   //	1137 14-152 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 3       "	,	//	1138 14-153 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_SC
const string20 prinfo_sc_ACC_ms2[11] = { //[Sibocom S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"��һ����ʱ��    m/s2"	,	//	156	01-12	1st Acceleration time
	"��һ����ʱ��    m/s2"	,	//	157	01-13	1st Deceleration time
	"�ڶ�����ʱ��    m/s2"	,	//	158	01-14	2nd Acceleration time
	"�ڶ�����ʱ��    m/s2"	,	//	159	01-15	2nd Deceleration time
	"��������ʱ��    m/s2"	,	//	160	01-16	3rd Acceleration time
	"��������ʱ��    m/s2"	,	//	161	01-17	3rd Deceleration time
	"���ļ���ʱ��    m/s2"	,	//	162	01-18	4th Acceleration time
	"���ļ���ʱ��    m/s2"	,	//	163	01-19	4th Deceleration time
	"�綯����ʱ��    m/s2"	,	//	164	01-20	JOG Acceleration time
	"�綯����ʱ��    m/s2"	,	//	165	01-21	JOG Deceleration time
	"ͣ������ʱ��    m/s2"
};

const string20 prinfo_sc_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"��һ����ʱ��    f/s2"	,	//	156	01-12	1st Acceleration time
	"��һ����ʱ��    f/s2"	,	//	157	01-13	1st Deceleration time
	"�ڶ�����ʱ��    f/s2"	,	//	158	01-14	2nd Acceleration time
	"�ڶ�����ʱ��    f/s2"	,	//	159	01-15	2nd Deceleration time
	"��������ʱ��    f/s2"	,	//	160	01-16	3rd Acceleration time
	"��������ʱ��    f/s2"	,	//	161	01-17	3rd Deceleration time
	"���ļ���ʱ��    f/s2"	,	//	162	01-18	4th Acceleration time
	"���ļ���ʱ��    f/s2"	,	//	163	01-19	4th Deceleration time
	"�綯����ʱ��    f/s2"	,	//	164	01-20	JOG Acceleration time
	"�綯����ʱ��    f/s2"	,	//	165	01-21	JOG Deceleration time
	"ͣ������ʱ��    f/s2"
};

const string20 prinfo_sc_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"���ٿ�ʼS1ʱ��  m/s3"	,	//	168	01-24	S curve Accel time 1
	"���ٿ�ʼS2ʱ��  m/s3"	,	//	169	01-25	S curve Accel time 2
	"���ٿ�ʼS3ʱ��  m/s3"	,	//	170	01-26	S curve Decel time 1
	"���ٿ�ʼS4ʱ��  m/s3"	,	//	171	01-27	S curve Decel time 2
	"���ٿ�ʼS5ʱ��  m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_sc_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"���ٿ�ʼS1ʱ��  f/s3"	,	//	168	01-24	S curve Accel time 1
	"���ٿ�ʼS2ʱ��  f/s3"	,	//	169	01-25	S curve Accel time 2
	"���ٿ�ʼS3ʱ��  f/s3"	,	//	170	01-26	S curve Decel time 1
	"���ٿ�ʼS4ʱ��  f/s3"	,	//	171	01-27	S curve Decel time 2
	"���ٿ�ʼS5ʱ��  f/s3"	,	//	174	01-30	S curve Decel time 3
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
    "RESERVE             "	,	//	128 15-128  RESERVED
    "RESERVE             "	,	//	129 15-129  RESERVED

/*---- GROUP 00---------------------------------------*/
   //12345678901234561234
    "���ֱ�ʶ��          "	,	//	130 00-00	Model Type of Drive 
    "��Ƶ�������  Amps"	,	//	131 00-01	Rated Current
    "���������趨        "	,	//	132 00-02	Parameter Reset
    "������ʾ����ѡ��    "	,	//	133 00-03	Start up Display        //chinese 
    "�๦����ʾѡ��      "	,	//	134 00-04	User Display            //chinese 
    "��������趨        "	,	//	135	00-05	User Coefficient        //chinese 
    "����汾            "	,	//	136	00-06	Software Version
    "����������������    "	,	//	137	00-07	Password Input
    "�������������趨    "	,	//	138	00-08	Password Input
    "����ģʽ            "	,	//	139	00-09	Control Methods
    "�ٶȵ�λ            "	,	//	140	00-10	Velocity Unit Select
    "�������������      "	,	//	141 00-11   Change Output Direction, Added by 
    "�ز�Ƶ��        KHz "	,	//	142	00-12	Carry Frequency
    "�Զ���ѹ����        "	,	//	143	00-13	AVR
    "�ٶ�ָ����Դ        "	,	//	144	00-14	Source of Freq. Command
    "��תָ����Դ        "	,	//	145	00-15	Source of Oper. Command

    "����                "	,	//	146 00-16   RESERVED
    "����                "	,	//	147 00-17   RESERVED
    "����                "	,	//	148 00-18   RESERVED
    "����                "	,	//	149 00-19   RESERVED
    
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"������Ƶ��    Hz  "	,	//	150	01-00	Max Output Freq.
	"����Ƶ��    Hz  "	,	//	151	01-01	Motor Base Frequency 1
	"������ѹ    V   "	,	//	152	01-02	Max Output Voltage
	"�ڶ����Ƶ��    Hz  "	,	//	153	01-03	Mid Output Freq.1
	"�ڶ������ѹ    V   "	,	//	154	01-04	Mid Output Voltage 1
	"�������Ƶ��    Hz  "	,	//	155	01-05	Mid Output Freq.2
	"���������ѹ    V   "	,	//	156	01-06	Mid Output Voltage 2
	"�������Ƶ��    Hz  "	,	//	157	01-07	Min Output Freq.
	"���������ѹ    V   "	,	//	158	01-08	Min Output Voltage
	"����Ƶ��        Hz  "	,	//	159	01-09	Start Frequency
	"���Ƶ������ֵ  Hz  "	,	//	160	01-10	Upper Bound Freq.
	"���Ƶ������ֵ  Hz  "	,	//	161	01-11	Lower Bound Freq.
	"��һ����ʱ��    sec "	,	//	162	01-12	1st Acceleration time      //chinese 
	"��һ����ʱ��    sec "	,	//	163	01-13	1st Deceleration time      //chinese 
	"�ڶ�����ʱ��    sec "	,	//	164	01-14	2nd Acceleration time      //chinese 
	"�ڶ�����ʱ��    sec "	,	//	165	01-15	2nd Deceleration time      //chinese 
	"��������ʱ��    sec "	,	//	166	01-16	3rd Acceleration time      //chinese 
	"��������ʱ��    sec "	,	//	167	01-17	3rd Deceleration time      //chinese 
	"���ļ���ʱ��    sec "	,	//	168	01-18	4th Acceleration time      //chinese 
	"���ļ���ʱ��    sec "	,	//	169	01-19	4th Deceleration time      //chinese 
	"�綯����ʱ��    sec "	,	//	170	01-20	JOG Acceleration time
	"�綯����ʱ��    sec "	,	//	171	01-21	JOG Deceleration time
	"�綯Ƶ��        Hz  "	,	//	172	01-22	JOG Frequency
	"1-4�����л�     Hz  "	,	//	173	01-23	Transition Frequency ACC1/DEC1 to 
	"���ٿ�ʼS1ʱ��  sec "	,	//	174	01-24	S curve Accel time 1
	"���ٿ�ʼS2ʱ��  sec "	,	//	175	01-25	S curve Accel time 2
	"���ٿ�ʼS3ʱ��  sec "	,	//	176	01-26	S curve Decel time 1
	"���ٿ�ʼS4ʱ��  sec "	,	//	177	01-27	S curve Decel time 2
	"С�ڵ���Ƶ��ģʽ    "	,	//	178	01-28	Select Zero Speed
	"ƽ���ٶ��л�    Hz  "	,	//	179	01-29	Landing Frequency 
	"����ƽ���ٶ�S5  sec "	,	//	180	01-30	S curve Decel time 3
	"ͣ������ʱ��    sec "	,	//	181	01-31	Stop Deceleration time	
    "�ն�ǿ�Ƽ��ٶ�  m/s "	,	//	182	01-32
    "����ֱͣ����ʱ��sec "	,	//	183	01-33   IODHT IO direct hold time   
    "����ֱͣƽ��ʱ��sec "	,	//  184 01-34   IODLT IO direct landing freq
    "����ֱͣ��������    "	,	//  185 01-35   IODLT IO direct landing time
    "����ֱͣ���پ���cm  "	,	//  186 01-36   IODLT IO direct DistancE
    "ֱͣ�ο����پ���m   "	,	//  187 01-37   IODLT IO direct DistancE
    "����ֱ��ͣ������    "	,	//  188 01-38   IODLT IO direct DistancE
    "ETS���ʱȽ�׼λ Hz  "  ,   //  189 01-39   IODLT IO direct DistancE
    "�������ټ���ʱ��sec "	,	//  190 01-40   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105 RESERVED
    "Emergency S3    sec "  ,   //  105 15-105 RESERVED
    "Emergency S4    sec "  ,   //  105 15-105 RESERVED
#else
    "����                "	,	//	191 01-41   RESERVED
    "����                "	,	//	192 01-42   RESERVED
    "����                "	,	//	193 01-43   RESERVED
#endif    
    "����ֱͣ�����ٶ�Hz  "	,	//	194 01-44   �ݤl����Ĳ�o�t��  MI direct stop trigger speed	//Task 268622 IO Direct Landing	//Mitong 20230221 add
    "����                "	,	//	195 01-45   RESERVED
    "����                "	,	//	196 01-46   RESERVED
    "����                "	,	//	197 01-47   RESERVED
    "����                "	,	//	198 01-48   RESERVED
    "����                "	,	//	199 01-49   RESERVED
    
/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "2/3 ��ʽ��תģʽ    "	,	//	200	02-00	2/3 wire control                
    "MI1����ѡ��         "	,	//	201	02-01	Multi-Function Input 1          
    "MI2����ѡ��         "	,	//	202	02-02	Multi-Function Input 2          
    "MI3����ѡ��         "	,	//	203	02-03	Multi-Function Input 3          
    "MI4����ѡ��         "	,	//	204	02-04	Multi-Function Input 4          
    "MI5����ѡ��         "	,	//	205	02-05	Multi-Function Input 5          
    "MI6����ѡ��         "	,	//	206	02-06	Multi-Function Input 6          
    "MI7����ѡ��         "	,	//	207	02-07	Multi-Function Input 7          
    "MI8����ѡ��         "	,	//	208	02-08	Multi-Function Input 8		    
    "����������Ӧʱ��sec "	,	//	209	02-09	Digital in response time		
    "�������뷽��        "	,	//	210	02-10	Multi-Function Input Inverse	
    "RA ����ѡ��         "	,	//	211	02-11	Multi-Function Relay 1		    
    "MRA����ѡ��         "	,	//	212	02-12	Multi-Function Relay 2		    
    "R1A����ѡ��         "	,	//	213	02-13	Multi-Function Output 1		    
    "R2A����ѡ��         "	,	//	214	02-14	Multi-Function Output 2		    
    "MO1����ѡ��         "	,	//	215	02-15	Multi-Function Output 3		    
    "MO2����ѡ��         "	,	//	216	02-16	Multi-Function Output 4		    
    "MO3����ѡ��         "	,	//	217	02-17	Multi-Function Output 5		    
    "MO4����ѡ��         "	,	//	218	02-18	Multi-Function Output 6		    
    "MO5����ѡ��         "	,	//	219	02-19	Multi-Function Output 7		    
    "MO6����ѡ��         "	,	//	220	02-20	Multi-Function Output 8		    
    "MO7����ѡ��         "	,	//	221	02-21	Multi-Function Output 9		    
    "MO8����ѡ��         "	,	//	222	02-22	Multi-Function Output 10		    
    "�����������        "	,	//	223	02-23	Multi-Function Output inverse	
    "�����ź�ģʽѡ��    "  ,   //  224 02-24   Sequence start mode
    "����Ƶ�ʵ���1   Hz  "	,	//	225	02-25	Desired Frequency 1		        
    "����Ƶ�ʵ���1�� Hz  "	,	//	226	02-26	Band of Desired Frequency 1		
    "����Ƶ�ʵ���2   Hz  "	,	//	227	02-27	Desired Frequency 2		        
    "����Ƶ�ʵ���2�� Hz  "	,	//	228	02-28	Band of Desired Frequency 2		
    "��еɲ���ͷ���ʱsec "	,	//	229	02-29	Brake Delay Timer at run
    "��еɲ����բ��ʱsec "	,	//	230	02-30	Brake Delay Timer at stop
    "��ŷ���ͨ��ʱ  sec "	,	//	231	02-31	Mech Contact Delay Timer run
    "��ŷ��Ͽ���ʱ  sec "	,	//	232	02-32	Mech Contact Delay Timer stop		
    "����׼λ�趨    %   "	,	//	233	02-33	Isum Current Output Detect	    
    "�ٶ������趨    Hz  "	,	//	234	02-34	Speed Area
    "��еɲ�����ʱ��sec "	,	//	235 02-35	Mechanical Brake Checking Time
    "��ŷ����ʱ��  sec "	,	//	236 02-36   Magnetic Contactor Checking Time
    "ת��ȷ�϶���ѡ��    "  ,   //  237 02-37   Mechanical Brake Checking Current Enable
    "��ŷ���ͨ��ʱ  sec "	,	//  238 02-38   Mech Contact Delay Timer run
    "��ŷ��Ͽ���ʱ  sec "	,	//  239 02-39   Mech Contact Delay Timer stop	
	"LU/LD�쳣ѡ��       "  ,   //  240 02-40   LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
	"LU/LD��·���   sec "  ,   //  241 02-41   LD/LD Open Detect Time      //#15977, LULD detect, James, 2021/04/01
	"LU/LD��·���   sec "  ,   //  242 02-42   LD/LD Short Detect Time     //#15977, LULD detect, James, 2021/04/01
    "��ת�ٶȵ�����Hz  "	,	//  243 02-43   Band of Speed Agree Function #18572			
    "STO��·���ʱ�� sec "  ,   //  244 02-44   STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  245 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "�ٶ�����        m/s "  ,   //  246 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06]

    "����                "  ,   //	247 02-47   RESERVED
    "����                "  ,   //	248 02-48   RESERVED
    "����                "  ,   //	249 02-49   RESERVED
    "����                "  ,   //	250 02-50   RESERVED
    "����                "  ,   //	251 02-51   RESERVED
    "����                "  ,   //	252 02-52   RESERVED
    "����                "  ,   //	253 02-53   RESERVED
    "����                "  ,   //  254 02-54   RESERVED
    "����                "  ,   //	255 02-55   RESERVED
    "����                "  ,   //	256 02-56   RESERVED
    "����                "  ,   //	257 02-57   RESERVED
    "����                "  ,   //	258 02-58   RESERVED
    "����                "  ,   //	259 02-59   RESERVED
    "����                "  ,   //	260 02-60   RESERVED
    "����                "  ,   //	261 02-61   RESERVED
    "����                "  ,   //	262 02-62   RESERVED
    "����                "  ,   //	263 02-63   RESERVED
    "����                "  ,   //  264 02-64   RESERVED
    "����                "  ,   //	265 02-65   RESERVED
    "����                "  ,   //	266 02-66   RESERVED
    "����                "  ,   //	267 02-67   RESERVED
    "����                "  ,   //	268 02-68   RESERVED
    "����                "  ,   //	269 02-69   RESERVED
    "����                "  ,   //	270 02-70   RESERVED
    "����                "  ,   //	271 02-71   RESERVED
    "����                "  ,   //	272 02-72   RESERVED
    "����                "  ,   //	273 02-73   RESERVED
    "����                "  ,   //  274 02-74   RESERVED
    "����                "  ,   //	275 02-75   RESERVED
    "����                "  ,   //	276 02-76   RESERVED
    "����                "  ,   //	277 02-77   RESERVED
    "����                "  ,   //	278 02-78   RESERVED
    "����                "  ,   //	279 02-79   RESERVED
    "����                "  ,   //	280 02-80   RESERVED
    "����                "  ,   //	281 02-81   RESERVED
    "����                "  ,   //	282 02-82   RESERVED
    "����                "  ,   //	283 02-83   RESERVED
    "����                "  ,   //  284 02-84   RESERVED
    "����                "  ,   //	285 02-85   RESERVED
    "����                "  ,   //	286 02-86   RESERVED
    "����                "  ,   //	287 02-87   RESERVED
    "����                "  ,   //	288 02-88   RESERVED
    "����                "  ,   //	289 02-89   RESERVED
    "����                "  ,   //	280 02-90   RESERVED
    "����                "  ,   //	291 02-91   RESERVED
    "����                "  ,   //	292 02-92   RESERVED
    "����                "  ,   //	293 02-93   RESERVED
    "����                "  ,   //  294 02-94   RESERVED
    "����                "  ,   //	295 02-95   RESERVED
    "����                "  ,   //	296 02-96   RESERVED
	"����                "  ,   //  297 02-97   RESERVED
	"����                "  ,   //  298 02-98   RESERVED
	"����                "  ,   //  299 02-99   RESERVED

/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
    "AUI1����ѡ��        "	,	//	300	03-00   AUI1 selection                    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "����                "	,	//	301	03-01   ACI  selection                    //[ACI function remove, Bernie, 01/20/2012] 
    "AUI2����ѡ��        "	,	//  302	03-02   AUI2 selection                    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1����ƫѹ    %   "	,	//	303	03-03   AUI1 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "����                "	,	//	307	03-04   ACI  input Bias                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2����ƫѹ    %   "	,	//	305	03-05   AUI2 input Bias                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1����ƫѹģʽ    "	,	//	306 03-06   AUI1 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "����                "	,	//	307 03-07   ACI  input Polarity               //[ACI function remove, Bernie, 01/20/2012]
    "AUI2����ƫѹģʽ    "	,	//	308 03-08   AUI2 input Polarity               //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1��������    %   "	,	//	309 03-09   AUI1 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "����                "	,	//	310 03-10   ACI  input Gain                   //[ACI function remove, Bernie, 01/20/2012]
    "AUI2��������    %   "	,	//	311 03-11   AUI2 input Gain                   //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI1�˲�ʱ��    sec "	,	//	312 03-12   Low pass filter of AUI1 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "����                "	,	//	313 03-13   Low pass filter of ACI  input     //[ACI function remove, Bernie, 01/20/2012]
    "AUI2�˲�ʱ��    sec "	,	//	314 03-14   Low pass filter of AUI2 input     //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "���ز�����ѧϰ      "	,	//	315 03-15   Loss of ACI                       //[ACI function remove, Bernie, 01/20/2012]
    "����                "  ,   //  316 03-16   RESERVED 
    "AO1 ���ѡ��        "	,	//	317 03-17   Analong Output 1
    "AO1 �������    %   "	,	//	318 03-18   Analong Output 1 Gain
    "AO1 �������ʹ��    "	,	//	319 03-19   AO1 in minus value
    "AO2 ���ѡ��        "	,	//	320 03-20   Analong Output 2
    "AO2 �������    %   "	,	//	321 03-21   Analong Output 2 Gain
    "AO2 �������ʹ��    "	,	//	322 03-22   AO2 in minus value
    "AUI1ģ������ģʽ    "	,	//	323 03-23   AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    "AUI2ģ������ģʽ    "	,	//	324 03-24   AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
    //"AUI1�����趨        "	,	//	325  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
    //"AUI2�����趨        "	,	//	326  03-26    AUI2 Communciate

/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "�������        Hz  "	,	//  327 04-00   Multi-Speed 0
    "��һ����        Hz  "	,	//  328 04-01   Multi-Speed 1
    "�ڶ�����        Hz  "	,	//  329 04-02   Multi-Speed 2
    "��������        Hz  "	,	//  330 04-03   Multi-Speed 3
    "���Ķ���        Hz  "	,	//  331 04-04   Multi-Speed 4
    "�������        Hz  "	,	//  332 04-05   Multi-Speed 5
    "��������        Hz  "	,	//  333 04-06   Multi-Speed 6
    "���߶���        Hz  "	,	//  334 04-07   Multi-Speed 7
    "�ڰ˶���        Hz  "	,	//  345 04-08   Multi-Speed 8
    "�ھŶ���        Hz  "	,	//  346 04-09   Multi-Speed 9
    "��ʮ����        Hz  "	,	//  347 04-10   Multi-Speed 10 
    "��ʮһ����      Hz  "	,	//  348 04-11   Multi-Speed 11
    "��ʮ������      Hz  "	,	//  349 04-12   Multi-Speed 12
    "��ʮ������      Hz  "	,	//  350 04-13   Multi-Speed 13
    "��ʮ�Ķ���      Hz  "	,	//  351 04-14   Multi-Speed 14
    "��ʮ�����      Hz  "	,	//  352 04-15   Multi-Speed 15
    "��Ԯ�ٶ�        m/s "  ,   //  353 04-16
    "ƽ���ٶ�        m/s "  ,   //  354 04-17
    "����վ�ٶ�      m/s "  ,   //  355 04-18
    
    "�����򻬲���    mm  "  ,   //  356 04-19    GFC Rope compensation, 2021/03/30
    "TABST0 Status       "  ,   //  357 04-20
    "TABST2 Status       "  ,   //  358 04-21
    "�������¥��        "  ,   //  359 04-22
    "Ŀǰ¥��            "  ,   //  360 04-23
    "����У������    %   "  ,   //  361 04-24
    "�����ӳٲ���    sec "  ,   //  362 04-25
    "��������ʱ��    ms  "  ,   //  363 04-26
    "�Ŵ��峤��      mm  "  ,   //  364 04-27  
    "Ŀǰλ�� ��     m   "  ,   //  365 04-28
    "Ŀǰλ�� ��     mm  "  ,   //  366 04-29
    "Ŀǰ���� H          "  ,   //  367 04-30  
    "Ŀǰ���� L          "  ,   //  368 04-31
    "�Ŵ������� H        "  ,   //  369 04-32
    "�Ŵ������� L        "  ,   //  370 04-33
    "���������H       "  ,   //  371 04-34
    "���������L       "  ,   //  372 04-35   
    "DLC���ܼ�           "  ,   //  373 04-36   
    "PDO��ʾ��̬         "  ,   //  374 04-37
    "���ٿ����������mm  "  ,   //  375 04-38   
    "������ٰٷֱ�  %   "  ,   //  376 04-39    //[ADCO EPS Modify]
    "�������첹��    mm  "  ,   //  377 04-40    //#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "EST Status          "  ,   //  378 04-41
    "EST Count           "  ,   //  379 04-42
    "TABST0 Count        "  ,   //  380 04-43
    "TABST1 Count        "  ,   //  381 04-44
    "DDS1/UDS1����   m/s "  ,   //  382 04-45    DD1_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS2/UDS2����   m/s "  ,   //  383 04-46    DD2_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS3/UDS3����   m/s "  ,   //  384 04-47    DD3_Vlim  //Artemis speed limit, James, 20200220                                    
    "DDS4/UDS4����   m/s "  ,   //  385 04-48    DD4_Vlim  //Artemis speed limit, James, 20200220
    "����ҳ���趨        "  ,   //  386 04-49    user page cahnge
    
    "1 ¥λ�� ��     m   "  ,   //  387 04-50   1Floor Position H 
    "1 ¥λ�� ��     mm  "  ,   //  388 04-51   1Floor Position L                                       
    "2 ¥λ�� ��     m   "  ,   //  389 04-52   2Floor Position H                                       
    "2 ¥λ�� ��     mm  "  ,   //  390 04-53   2Floor Position L                                       
    "3 ¥λ�� ��     m   "  ,   //  391 04-54   3Floor Position H                                       
    "3 ¥λ�� ��     mm  "  ,   //  392 04-55   3Floor Position L                                       
    "4 ¥λ�� ��     m   "  ,   //  393 04-56   4Floor Position H                                       
    "4 ¥λ�� ��     mm  "  ,   //  394 04-57   4Floor Position L                                       
    "5 ¥λ�� ��     m   "  ,   //  395 04-58   5Floor Position H                                       
    "5 ¥λ�� ��     mm  "  ,   //  396 04-59   5Floor Position L                                       
    "6 ¥λ�� ��     m   "  ,   //  397 04-60   6Floor Position H                                       
    "6 ¥λ�� ��     mm  "  ,   //  398 04-61   6Floor Position L                                       
    "7 ¥λ�� ��     m   "  ,   //  399 04-62   7Floor Position H                                       
    "7 ¥λ�� ��     mm  "  ,   //  400 04-63   7Floor Position L                                       
    "8 ¥λ�� ��     m   "  ,   //  401 04-64   8Floor Position H                                       
    "8 ¥λ�� ��     mm  "  ,   //  402 04-65   8Floor Position L                                       
    "9 ¥λ�� ��     m   "  ,   //  403 04-66   9Floor Position H                                       
    "9 ¥λ�� ��     mm  "  ,   //  404 04-67   9Floor Position L                                       
    "10¥λ�� ��     m   "  ,   //  405 04-68   10Floor Position H                                      
    "10¥λ�� ��     mm  "  ,   //  406 04-69   10Floor Position L                                      
    "11¥λ�� ��     m   "  ,   //  407 04-70   11Floor Position H                                      
    "11¥λ�� ��     mm  "  ,   //  408 04-71   11Floor Position L                                      
    "12¥λ�� ��     m   "  ,   //  409 04-72   12Floor Position H                                      
    "12¥λ�� ��     mm  "  ,   //  410 04-73   12Floor Position L                                      
    "13¥λ�� ��     m   "  ,   //  411 04-74   13Floor Position H                                      
    "13¥λ�� ��     mm  "  ,   //  412 04-75   13Floor Position L                                      
    "14¥λ�� ��     m   "  ,   //  413 04-76   14Floor Position H                                      
    "14¥λ�� ��     mm  "  ,   //  414 04-77   14Floor Position L                                      
    "15¥λ�� ��     m   "  ,   //  415 04-78   15Floor Position H                                      
    "15¥λ�� ��     mm  "  ,   //  416 04-79   15Floor Position L                                      
    "16¥λ�� ��     m   "  ,   //  417 04-80   16Floor Position H                                      
    "16¥λ�� ��     mm  "  ,   //  418 04-81   16Floor Position L                                      
    "17¥λ�� ��     m   "  ,   //  419 04-82   17Floor Position H                                      
    "17¥λ�� ��     mm  "  ,   //  420 04-83   17Floor Position L                                      
    "18¥λ�� ��     m   "  ,   //  421 04-84   18Floor Position H                                      
    "18¥λ�� ��     mm  "  ,   //  422 04-85   18Floor Position L                                      
    "19¥λ�� ��     m   "  ,   //  423 04-86   19Floor Position H                                      
    "19¥λ�� ��     mm  "  ,   //  424 04-87   19Floor Position L                                      
    "20¥λ�� ��     m   "  ,   //  425 04-88   20Floor Position H                                      
    "20¥λ�� ��     mm  "  ,   //  426 04-89   20Floor Position L                                      
    "21¥λ�� ��     m   "  ,   //  427 04-90   21Floor Position H                                      
    "21¥λ�� ��     mm  "  ,   //  428 04-91   21Floor Position L                                      
    "22¥λ�� ��     m   "  ,   //  429 04-92   22Floor Position H                                      
    "22¥λ�� ��     mm  "  ,   //  430 04-93   22Floor Position L                                      
    "23¥λ�� ��     m   "  ,   //  431 04-94   23Floor Position H                                      
    "23¥λ�� ��     mm  "  ,   //  432 04-95   23Floor Position L                                      
    "24¥λ�� ��     m   "  ,   //  433 04-96   24Floor Position H                                      
    "24¥λ�� ��     mm  "  ,   //  434 04-97   24Floor Position L                                      
    "25¥λ�� ��     m   "  ,   //  435 04-98   25Floor Position H                                      
    "25¥λ�� ��     mm  "  ,   //  436 04-99   25Floor Position L                                      
        
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
    "IM������ѧϰ        "	,	//	437 05-00	Motor Auto-Tuning
    "IM��������  Amps"	,	//	438 05-01	Motor 1 rated Current           
    "IM��������  Kw  "	,	//	439 05-02	Motor 1 Rated Power             
    "IM����ת��  RPM "	,	//	440 05-03	Motor 1 Rated RPM               
    "IM�������          "	,	//	441 05-04	Motor 1 pole No.                
    "IM������ص���  Amps"	,	//	442 05-05	Motor 1 No-Load Current         
    "IM������� Rs   ohm "	,	//	443 05-06	Motor 1 Rs                      
    "IM������� Rr   ohm "	,	//	444 05-07	Motor 1 Rr                      
    "IM������� Lm   mH  "	,	//	445 05-08	Motor 1 Lm                      
    "IM������� Lx   mH  "	,	//	446 05-09	Motor 1 Lx                      
    "ת�ز�����ͨ�˲�sec "	,	//	447 05-10	Vector Voltage Filter	        
    "�������ͨ�˲�sec "	,	//	448 05-11	Vector Slip Filter	            
    "�綯ת�ز�������    "	,	//	449 05-12	Torque Compensation Gain	    
    "���������        "	,	//	450 05-13	Slip Compensation Gain	        
    "�������׼λ    %   "	,	//	451 05-14	Slip Deviation level	        
    "���������ʱ��sec "	,	//	452 05-15	Slip Deviation Detect Time	    
    "��������ѡ��      "	,	//	453 05-16	Over Slip treatment	            
    "�𵴲�������        "	,	//	454 05-17	Coeff for hunting disable	    
    "�ۼƵ����תʱ��Mins"	,	//	455 05-18	Accumulative Motor Operation Min
    "�ۼƵ����ת    Days"	,	//	456 05-19	Accumulative Motor Operation Day
    "��о��ʧ����    %   "	,	//	457 05-20	Coreloss % of output Power	    
    "��Ƶ���ϵ�ʱ��  Mins"	,	//	458 05-21	Power On Min
    "��Ƶ���ϵ�����  Days"	,	//	459 05-22	Power On Day    
    "�������������%   "  ,   //  460 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"�綯���������%   "	,	//	461 05-24   RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
    "�͵�ѹ׼λ      V   "	,	//	462 06-00	Low voltage level
    "Ƿ�ౣ��            "	,	//	463 06-01	Phase loss
    "���ٹ�����ʧ��  %   "	,	//	464 06-02	OC stall during Accel
    "���ٹ�����ʧ��  %   "	,	//	465 06-03	OC stall during Decel
    "������ʧ�ٴ���      "	,	//  466 06-04	Stall preventation Accel/Decel time selection
    "��ת��OT1����       "	,	//	467 06-05	Over-Torque 1 Selection
    "��ת��OT1׼λ   %   "	,	//	468 06-06	Over-Torque 1 level
    "��ת��OT1���   sec "	,	//	469 06-07	Over-Torque 1 Time
    "��ת��OT2����       "	,	//	470 06-08	Over-Torque 2 Selection	                     
    "��ת��OT2׼λ   %   "	,	//	471 06-09	Over-Torque 2 level	                         
    "��ת��OT2���   sec "	,	//	472 06-10	Over-Torque 2 Time	                         
    "��������        %   "	,	//	473 06-11	Current Limit
    "�����ȵ���ѡ��      "	,	//	474 06-12	Thermal Relay 1 Selection
    "�ȵ�������ʱ��  sec "	,	//	475 06-13	Thermal Relay 1 Time
    "���Ⱦ����¶�׼λC   "	,	//	476 06-14	OH Warning Level
    "ʧ�ٷ�ֹ����׼λ%   "	,	//	477 06-15	Stall preventation Limit Level
    "���һ�ι��ϼ�¼    "	,	//	478 06-16	1st Fault Record
    "2��ǰ�Ĺ��ϼ�¼     "	,	//	479 06-17	2nd Fault Record
    "3��ǰ�Ĺ��ϼ�¼     "	,	//	480 06-18	3rd Fault Record
    "4��ǰ�Ĺ��ϼ�¼     "	,	//	481 06-19	4th Fault Record
    "5��ǰ�Ĺ��ϼ�¼     "	,	//	482 06-20	5th Fault Record
    "6��ǰ�Ĺ��ϼ�¼     "	,	//	483 06-21	6th Fault Record
    "�쳣���ѡ�� 1      "	,	//	484 06-22	Fault Option 1
    "�쳣���ѡ��2       "	,	//	485 06-23	Fault Option 2
    "�쳣���ѡ��3       "	,	//	486 06-24	Fault Option 3
    "�쳣���ѡ��4       "	,	//	487 06-25	Fault Option 4
    "PTC����ѡ��         "	,	//	488 06-26	PTC over Treatments	                         
    "PTC׼λ         %   "	,	//	489 06-27	PTC Level
    "PTC���ʱ��     sec "	,	//	490 06-28	PTC Detect Filter time
    "�������е�Դ��ѹV   "	,	//	491 06-29	EPS voltage level
    "�������ѡ��        "	,	//	492 06-30	Fault Option Mode
    "ED ���Ƿ�����     "	,	//	493 06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
    "ǰһ���쳣��ת  Mins"	,	//	494 06-32	1st Fault Time(MIN)
    "ǰһ���쳣��ת  Days"	,	//	495 06-33	1st Fault Time(DAY)
    "2��ǰ�쳣��ת   Mins"	,	//	496 06-34	2nd Fault Time(MIN)
    "2��ǰ�쳣��ת   Days"	,	//	497 06-35	2nd Fault Time(DAY)
    "3��ǰ�쳣��ת   Mins"	,	//	498 06-36	3rd Fault Time(MIN)
    "3��ǰ�쳣��ת   Days"	,	//	499 06-37	3rd Fault Time(DAY)
    "4��ǰ�쳣��ת   Mins"	,	//	500 06-38	4th Fault Time(MIN)
    "4��ǰ�쳣��ת   Days"	,	//	501 06-39	4th Fault Time(DAY)
    "5��ǰ�쳣��ת   Mins"	,	//	502 06-40	5th Fault Time(MIN)
    "5��ǰ�쳣��ת   Days"	,	//	503 06-41	5th Fault Time(DAY)
    "6��ǰ�쳣��ת   Mins"	,	//	504 06-42	6th Fault Time(MIN)
    "6��ǰ�쳣��ת   Days"	,	//	505 06-43	6th Fault Time(DAY)
    "������Դ�����ٶ�Hz  "  ,   //  506 06-44	EPS Frequency
    "������ѡ��        "  ,	//  507 06-45   LV Option Mode
    "EPS ģʽѡ��        "  ,	//  508 06-46   EPS Option Mode
    "���㷽������ʱ��sec "  ,   //  509 06-47   Generation Operation Detected Time
    "�������е�Դ����KVA "  ,   //  510 06-48   UPS Capacity (0.1KVA)
    "STO����ѡ��         "  ,   //  511 06-49   STO Lock selection     //[Safty function, Bernie]   
    "��������ʱMO����    "  ,   //  512 06-50   Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "�������Դ���        "  ,   //  513 06-51   Auto restart times after fault     
    "��������ʱ��    sec "  ,   //  514 06-52   Auto restart interval
    "�쳣ʱƵ������  Hz  "  ,   //	515 06-53   Fkey Record
    "�쳣ʱƵ�����  Hz  "  ,   //	516 06-54   Fcmd Record
    "�쳣ʱ�������  Amps"  ,   //	517 06-55	Isum Record
    "�쳣ʱ���Ƶ��  Hz  "  ,   //	518 06-56	Fout Record
    "�쳣ʱ�����ѹ  V   "  ,   //	519 06-57	Vout Record
    "�쳣ʱDCBus��ѹ V   "  ,   //  520 06-58	Dcbus Record    
    "�쳣ʱ�������  KW  "  ,   //	521 06-59   Power Record
    "�쳣ʱ���ת��  %   "  ,   //	522 06-60   Torque Record
    "�쳣ʱIGBT�¶�  C   "  ,   //	523 06-61	IGBT Temperature Record   
    "�쳣ʱ�������  Hex "  ,   //	524 06-62   MFI State Record
    "�쳣ʱ�������  Hex "  ,   //	525 06-63   MFO State Record
    "�쳣ʱ������״̬Hex "  ,   //	526 06-64   Drive State Record
    "UCMP��������׼λ%   "  ,   //  527 06-65   Current limitation for UCMP function            //[UCMP function, Bernie, 2016/06/14]
    "�϶���������      "  ,   //  528 06-66   Service time count                              //[Service time function, Bernie, 2017/03/14]
    "�϶�������趨      "  ,   //  529 06-67   Service time function Enable                    //[Service time function, Bernie, 2017/03/14]
    "EPS��⹦��׼λ deg "  ,   //  530 06-68   EPS Detect Current    
    "EPS�����       deg "  ,   //  531 06-69   EPS Detect Current Ref
    "EPS���򼭳�         "  ,   //  532 06-70   EPS Detect direction
    "EPS���Ӽ�����ѡ sec "  ,   //  533 06-71   EPS MO Off Time
    "EPS���ӱպ���ѡ sec "  ,   //  534 06-72   EPS MO Off Time
    "�������з������H   "	,   //	535 06-73   Running direction count high						
    "�������з������L   "	,   //	536 06-74   Running direction count low
    "�������з������H   "	,   //	537 06-75   Temp running direction count high
    "�������з������L   "	,   //  538 06-76   Temp running direction count low
    "�����������ô���    "	,   //	539 06-77   Temp running reset count
    "���з������ƴ���k   "	,   //	540 06-78   Running life
    "���д�������ѡ��    "	,   //	541 06-79   Running function
    "�쳣2ʱƵ�����  Hz  " ,   //  542 06-80   Fcmd Record1
    "�쳣2ʱDCBus��ѹ V   " ,   //  543 06-81   Dcbus Record1
    "�쳣2ʱ�������  Amps" ,   //  544 06-82   Isum Record1
    "�쳣2ʱIGBT�¶�  C   "	,   //  545 06-83   IGBT Temperature Record1
    "�쳣3ʱƵ�����  Hz  " ,   //  546 06-84   Fcmd Record2
    "�쳣3ʱDCBus��ѹ V   " ,   //  547 06-85   Dcbus Record2
    "�쳣3ʱ�������  Amps" ,   //  548 06-86   Isum Record2
    "�쳣3ʱIGBT�¶�  C   " ,   //  549 06-87   IGBT Temperature Record2
    "�쳣4ʱƵ�����  Hz  " ,   //  550 06-88   Fcmd Record3
    "�쳣4ʱDCBus��ѹ V   " ,   //  551 06-89   Dcbus Record3
    "�쳣4ʱ�������  Amps" ,   //  552 06-90   Isum Record3
    "�쳣4ʱIGBT�¶�  C   " ,   //  553 06-91   IGBT Temperature Record3
    "�쳣5ʱƵ�����  Hz  " ,   //  554 06-92   Fcmd Record4
    "�쳣5ʱDCBus��ѹ V   " ,   //  555 06-93   Dcbus Record4
    "�쳣5ʱ�������  Amps" ,   //  556 06-94   Isum Record4
    "�쳣5ʱIGBT�¶�  C   " ,   //  557 06-95   IGBT Temperature Record4
    "�쳣6ʱƵ�����  Hz  " ,   //  558 06-96   Fcmd Record5
    "�쳣6ʱDCBus��ѹ V   " ,   //  559 06-97   Dcbus Record5
    "�쳣6ʱ�������  Amps" ,   //  560 06-98   Isum Record5
    "�쳣6ʱIGBT�¶�  C   " ,   //  561 06-99   IGBT Temperature Record5
/*---- GROUP 07-----------------------------------------*/
/*  "12345678901234561234"	*/
    "ɲ������ŵ�׼λV   "	,	//	562 07-00	SW Braking Level
    "ɷ��������͵�ѹV   "  ,   //	563 07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
    "����ֱ���ƶ�׼λ%   "	,	//	564 07-02	DCI Current Level    //[DCI Level when stop, Bernie, 05/21/2012]
    "����ֱ���ƶ�ʱ��sec "	,	//	565 07-03	DCI Time at Start 
    "ͣ��ֱ���ƶ�ʱ��sec "	,	//	566 07-04	DCI Time at STOP
    "ͣ���ƶ���ʼƵ��Hz  "	,	//	567 07-05	DCI Freq. At start
    "ֱ���ƶ�I����       "	,	//	568 07-06	DCI KI
    "��ϵ�����ж�ʱ��sec "	,	//	569 07-07	Gear wait time when acceleration
    "��ϵ�����ж�Ƶ��Hz  "	,	//	570 07-08	Gear wait frequency when acceleration
    "��ϵ�����ж�ʱ��sec "	,	//	572 07-09	Gear wait time when deceleration
    "��ϵ�����ж�Ƶ��Hz  "	,	//	573 07-10	Gear wait frequency when deceleration
    "���ȿ��Ʒ�ʽ        "	,	//	574 07-11	Fan Control
    "ת������        %   "	,	//	575 07-12	TQC Reference from RS485
    "ת��������Դ        "	,	//	576 07-13	Source of Torque Command
    "���ת������    %   "	,	//	577 07-14	Torque max. level
    "ת�������˲�ʱ��sec "	,	//	578 07-15	Torque command filter
    "�ٶ�����ѡ��        "	,	//	579 07-16	Speed Limit selection
    "ת��ģʽ+SPD����%   "	,	//	580 07-17	Torque mode positive speed limit
    "ת��ģʽ-SPD����%   "	,	//  581 07-18	Torque mode negative speed limit
    "ת������ƫѹ��Դ    "	,	//	582 07-19	Torque offset selection
    "ת������ƫѹ�趨%   "	,	//	583 07-20	Torque offset setting level
    "��ת��ƫ��      %   "	,	//	584 07-21	Torque offset setting level High
    "��ת��ƫ��      %   "	,	//	585 07-22	Torque offset setting level Middle
    "��ת��ƫ��      %   "	,	//	586 07-23	Torque offset setting level Low
    "��ת�綯ת������%   "	,	//	587 07-24	FWD Motoring Tq Limit
    "��ת����ת������%   "	,	//	588 07-25	FWD Regeneration Tq Limit
    "��ת�綯ת������%   "	,	//	589 07-26	REV Motoring Tq Limit
    "��ת����ת������%   "	,	//	590 07-27	REV Regeneration Tq Limit
    "ǿ��ͣ�������ʽ    "	,	//	591 07-28	Emergency Stop & Forced Stop selection
    "ͣ��ת�ؼ���ʱ��sec "	,	//	592 07-29   Torque Decrease Time
    "ֱֹͣ���ƶ�׼λ%   "  ,   //	593 07-30   STOP DC Inject Level       //[DCI Level when stop, Bernie, 05/21/2012]
    "BTT100             %"  ,   //  594 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx���            "  ,   //  595 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx������     ppr"  ,   //  596 07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�������        "  ,   //  597 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx���ʧ��ת��    "  ,   //  598 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx�����Сת��    "  ,   //  599 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx������ת��    "  ,   //  600 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "PM������ѧϰ        "	,	//	663 08-00	PMotor Auto-Tuning  
    "PM��������  Amps"	,	//	664 08-01	PMotor rated Current
    "PM��������  Kw  "	,	//	665 08-02	PMotor Rated Power  
    "PM����ת��  RPM "	,	//	666 08-03	PMotor Rated RPM    
    "PM�������          "	,	//	667 08-04	PMotor pole No.     
    "PM������� Rs   ohm "	,	//	668 08-05	PMotor Rs           
    "PM������� Ld   mH  "	,	//	669 08-06	PMotor Ld           
    "PM������� Lq   mH  "	,	//	670 08-07	PMotor Lq           
    "������綯��    Vrms"	,	//	671 08-08	PMotor Bemf coff	
    "�ż�ƫ�ƽ�      deg "	,	//	672 08-09	PM Z-pulse offset angle, 0.1 degree, dino
    "�ż����¶�λ        "	,	//	673 08-10	//ADDED BY DINO    
	
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "ͨѶ��ַ            "	,	//	674 09-00   Comm Address                              
    "ͨѶ�����ٶ�    kbps"	,	//	675 09-01   Tranmission speed                         
    "ͨѶ������        "	,	//	676 09-02   Comm fault Treatment                      
    "��ʱ���ʱ��    sec "	,	//	677 09-03   Comm Time out                             
    "ͨѶ��ʽ            "	,	//	678 09-04   Comm Protocol                             
    "��Ӧ��ʱʱ��    ms  "	,	//	679 09-05   ASC remote Response Delay Time, 1=100us   
    "CAN ͨѶ����        "	,   //	680 09-06   CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "CAN PDO����ʱ�� ms  "	,   //  681 09-07   CAN PDO Handshaking Period
    "CAN PDOͨѶ��ʱ ms  "	,   //	682 09-08   CAN Communiction Timeout	
    "��λ��ʶ����        "  ,   //	683 09-09   
    "FHM �ݴ���          "  ,   //	684 09-10  
    "DLC �ݴ���1         "  ,   //	685 09-11  
    "DLC �ݴ���2         "  ,   //	686 09-12   
    "DLC �ݴ���3         "  ,   //	687 09-13     
	"PDO���ͼ��     ms  "	,	//	688 09-14   CAN fail rate---aevin 6/12/2017

/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"����������ѡ��      "	,	//	689 10-00	Encoder TYPE                             
	"�������������  ppr "	,	//	690 10-01	Encoder pulses	                    
	"������������ʽ      "	,	//  691 10-02	PG input setting	                
	"PG������ѡ��      "	,	//  692 10-03	PG fbk fault treatment	            
	"PG������ʱ��  sec "	,	//  693 10-04	PG fbk Error Detection Time	        
	"PGʧ��׼λ      %   "	,	//  694 10-05	PG fbk overspeed detection level	
	"PFʧ�ټ��ʱ��  sec "	,	//  695 10-06	Over speed Detection Time	        
	"PGת���쳣׼λ  %   "	,	//	696 10-07	PG fbk speed deviation level	    
	"PGת����ʱ��  sec "	,	//	697 10-08	Deviation Detect Time	            
	"PGʧ�ٶ���ѡ��      "	,	//	698 10-09	Operation at overspeed	            
	"HALL�ź�ģʽѡ��    "  ,   //  699 10-10   Hall Input Types
	"������������P       "	,	//	700 10-11	KP gain of ASR in Zero speed	
	"�������ٻ���I   sec "	,	//	701 10-12	Ki gain of ASR in Zero speed	
	"��������P           "	,	//	702 10-13	ASR P Gain 1	                
	"���ٻ���ʱ��I   sec "	,	//	703 10-14	ASR I Gain 1	                
	"��������P           "	,	//	704 10-15	ASR P Gain 2	                
	"���ٻ���ʱ��I   sec "	,	//	705 10-16	ASR I Gain 2	                
	"��/�����л�Ƶ�� Hz  "	,	//  706 10-17	ASR1/ASR2 switch freq	        
	"ASR��ͨ�˲����� sec "	,	//  707 10-18	Primary LowPass filter Gain 
	"λ�ÿ���ASR���� P   "  ,	//  708 10-19   position control Kp Gain  
    "��/���ٴ������ Hz  "  ,   //  709 10-20   Low Spd band
    "��/���ٴ������ Hz  "  ,   //  710 10-21   High Spd band
	"λ�ÿ���ASR����Isec "	,	//  711 10-22   Position control time
	"����λ�ÿ��Ƶ�ͨsec "	,	//  712 10-23   Position control LOW POSS FILTER
	"λ�ÿ���ģʽѡ��    "	,	//  713 10-24   Source of position control, add by dino, 
	"ƽ����������P   %   "	,	//  714 10-25	KP gain of ASR in Zero speed of 
	"ƽ�����ٻ���I   sec "	,	//	715 10-26	Ki gain of ASR in Zero speed of Landing
	"λ�ÿ�����������%   "	,	//	716 10-27	KP gain of ASR in Zero speed during 
	"λ�ÿ������ٻ���sec "	,	//	717 10-28	Ki gain of ASR in Zero speed during 
    "PG����Ƶ���ֵ      "	,   //	718 10-29   PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG����Ƶ�����ʽ    "	,   //	719 10-30   PG Card Mode setting                      //[DCI Level when stop, Bernie, 05/21/2012]    
    "PG C+/C-ѡ��        "  ,   //  720 10-31   RESERVED     //[change parameter to normal group, Bernie, 2014/02/14]
    "���ݹ����ٶ�׼λm/s2"  ,   //	721 10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "�����ٶ����ʱ��sec "  ,   //	722 10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "�����ٶ����ѡ��    "  ,   //	723 10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]

    "����                "  ,   //	724 10-35   RESERVED
    "����                "  ,   //	725 10-36   RESERVED
    "����                "  ,   //	726 10-37   RESERVED
    "����                "  ,   //	727 10-38   RESERVED
    "����                "  ,   //	728 10-39   RESERVED
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "ϵͳ����        Hex "	,	//  729 11-00	system control bit0:auto, bit1:Jm tunning, 
    "���Ƶ�ʶ�Ӧ����m/s "  ,   //  730 11-01   Lift operation speed                                        
    "ҷ����ֱ��      mm  "  ,   //  731 11-02   SHEAVE diameter		                
    "���ֱ�              "  ,   //  732 11-03   Gear Ratio                                              
    "���ұ�              "  ,   //  733 11-04   Suspension ratio	                                        
    "��е�����ٷֱ�  %   "  ,   //  734 11-05   inertia	percent		                  
    "�������ٴ���    Hz  "	,	//	735 11-06	Zero Speed Loop BandWidth	                                
    "���ٴ���        Hz  "	,	//	736 11-07	Speed Loop BandWidth1		                                
    "���ٴ���        Hz  "	,	//	737 11-08	Speed Loop BandWidth2		                                
    "PDFF����ֵ      %   "	,	//  738 11-09	PDFFKr		                                                
    "�ٶȿ���ǰ������%   "	,	//	739 11-10	SPEED FFD GAIN		                    
    "�����˲����    db  "	,	//	740 11-11	Netch filter deep(db)	                                    
    "�����˲�Ƶ��    Hz  "	,	//	741 11-12	Netch filter frequency	                                    
    "�����ʾ�˲�ʱ��sec "	,	//  742 11-13	Low Pass Filter for display	                                
    "����ʱ������  %   "	,	//  743 11-14	ACC Max current                                             
    "���������ٶ�  m/s2"  ,	//  744 11-15	max meter/sec	                                            
    "�������λ��    Hex "  ,   //  745 11-16	Display address,add by dino 2007/03/08                      
    "�������            "  ,	//  746 11-17	Display data,   add by dino 2007/03/08                      
    "����                "  ,   //  747 11-18   Protect Bit	                                                
    "ͣ�����ٴ���    Hz  "	,	//  748 11-19	Zero Speed Loop BandWidth of Landing  
    "PWM ģʽģʽ        "  ,   //  749 11-20	PWM Mode selection  PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LC01��ʾ�˲�ʱ�� sec"	,	//  750 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
	"Motor SPD RPM       "	,	//	750   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]
    "����                "  ,   //	752 11-23   RESERVED
    "����                "  ,   //	753 11-24   RESERVED
    "����                "  ,   //	754 11-25   RESERVED
    "����                "  ,   //	755 11-26   RESERVED
    "����                "  ,   //	756 11-27   RESERVED
    "����                "  ,   //	757 11-28   RESERVED
    "����                "  ,   //	758 11-29   RESERVED
    
/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "�Զ�����1           "  ,   //  759 12-00
    "�Զ�����2           "  ,   //  760 12-01
    "�Զ�����3           "  ,   //  761 12-02
    "�Զ�����4           "  ,   //  762 12-03
    "�Զ�����5           "  ,   //	763 12-04
    "�Զ�����6           "  ,   //	764 12-05
    "�Զ�����7           "  ,   //	765 12-06
    "�Զ�����8           "  ,   //	766 12-07
    "�Զ�����9           "  ,   //	767 12-08
    "�Զ�����10          "  ,   //	768 12-09
    "�Զ�����11          "  ,   //	769 12-10
    "�Զ�����12          "  ,   //	770 12-11
    "�Զ�����13          "  ,   //	771 12-12
    "�Զ�����14          "  ,   //	772 12-13
    "�Զ�����15          "  ,   //	773 12-14
    "�Զ�����16          "  ,   //  774 12-15
    "�Զ�����17          "  ,   //	775 12-16
    "�Զ�����18          "  ,   //	776 12-17
    "�Զ�����19          "  ,   //	777 12-18
    "�Զ�����20          "  ,   //	778 12-19
    "�Զ�����21          "  ,   //	779 12-20
    "�Զ�����22          "  ,   //	780 12-21
    "�Զ�����23          "  ,   //  781 12-22
    "�Զ�����24          "  ,   //	782 12-23
    "�Զ�����25          "  ,   //	783 12-24
    "�Զ�����26          "  ,   //	784 12-25
    "�Զ�����27          "  ,   //	785 12-26
    "�Զ�����28          "  ,   //	786 12-27
    "�Զ�����29          "  ,   //	787 12-28
    "�Զ�����30          "  ,   //	788 12-29
    "�Զ�����31          "  ,   //  789 12-30
    "�Զ�����32          "  ,   //  790 12-31
    "�Զ�����33          "  ,   //  791 12-32
    "�Զ�����34          "  ,   //  792 12-33
    "�Զ�����35          "  ,   //  793 12-34
    "�Զ�����36          "  ,   //  794 12-35
    "�Զ�����37          "  ,   //  795 12-36
    "�Զ�����38          "  ,   //  796 12-37
    "�Զ�����39          "  ,   //  797 12-38
    "�Զ�����40          "  ,   //  798 12-39
    "�Զ�����41          "  ,   //  799 12-40
    "�Զ�����42          "  ,   //  800 12-41
    "�Զ�����43          "  ,   //  801 12-42
    "�Զ�����44          "  ,   //  802 12-43
    "�Զ�����45          "  ,   //  803 12-44
    "�Զ�����46          "  ,   //  804 12-45
    "�Զ�����47          "  ,   //  805 12-46
    "�Զ�����48          "  ,   //  806 12-47
    "�Զ�����49          "  ,   //  807 12-48
    "�Զ�����50          "  ,   //  808 12-49
    "����                "  ,   //  809 12-50
    "����                "  ,   //  810 12-51
    "����                "  ,   //  811 12-52
    "����                "  ,   //  812 12-53
    "����                "  ,   //  813 12-54
    "����                "  ,   //  814 12-55
    "����                "  ,   //  815 12-56
    "����                "  ,   //  816 12-57
    "����                "  ,   //  817 12-58
    "����                "  ,   //  818 12-59
    "����                "  ,   //  819 12-60
    "����                "  ,   //  820 12-61
    "����                "  ,   //  821 12-62
    "����                "  ,   //  822 12-63
    "����                "  ,   //  823 12-64
    "����                "  ,   //  824 12-65
    "����                "  ,   //  825 12-66
    "����                "  ,   //  826 12-67
    "����                "  ,   //  827 12-68
    "����                "  ,   //  828 12-69
    "����                "  ,   //  829 12-70
    "����                "  ,   //  830 12-71
    "����                "  ,   //  831 12-72
    "����                "  ,   //  832 12-73
    "����                "  ,   //  833 12-74
    "����                "  ,   //  834 12-75
    "����                "  ,   //  835 12-76
    "����                "  ,   //  836 12-77
    "����                "  ,   //  837 12-78
    "����                "  ,   //  838 12-79
    "����                "  ,   //  839 12-80
    "����                "  ,   //  840 12-81
    "����                "  ,   //  841 12-82
    "����                "  ,   //  842 12-83
    "����                "  ,   //  843 12-84
    "����                "  ,   //  844 12-85
    "����                "  ,   //  845 12-86
    "����                "  ,   //  846 12-87
    "����                "  ,   //  847 12-88
    "����                "  ,   //  848 12-89
    "����                "  ,   //  849 12-90
    "����                "  ,   //  850 12-91
    "����                "  ,   //  851 12-92
    "����                "  ,   //  852 12-93
    "����                "  ,   //  853 12-94
    "����                "  ,   //  854 12-95
    "����                "  ,   //  855 12-96
    "����                "  ,   //  856 12-97
    "����                "  ,   //  857 12-98
    "����                "  ,   //  858 12-99

/*---- GROUP 13------------------------------------------*/
/*  "12345678901234561234"	*/
    "�Զ����ò���1       "  ,   //  859 13-00
    "�Զ����ò���2       "  ,   //  860 13-01
    "�Զ����ò���3       "  ,   //  861 13-02
    "�Զ����ò���4       "  ,   //  862 13-33
    "�Զ����ò���5       "  ,   //  863 13-04
    "�Զ����ò���6       "  ,   //  864 13-05
    "�Զ����ò���7       "  ,   //  865 13-06
    "�Զ����ò���8       "  ,   //  866 13-07
    "�Զ����ò���9       "  ,   //  867 13-08
    "�Զ����ò���10      "  ,   //  868 13-09
    "�Զ����ò���11      "  ,   //  869 13-10
    "�Զ����ò���12      "  ,   //  870 13-11
    "�Զ����ò���13      "  ,   //  871 13-12
    "�Զ����ò���14      "  ,   //  872 13-13
    "�Զ����ò���15      "  ,   //  873 13-14
    "�Զ����ò���16      "  ,   //  874 13-15
    "�Զ����ò���17      "  ,   //  875 13-16
    "�Զ����ò���18      "  ,   //  876 13-17
    "�Զ����ò���19      "  ,   //  877 13-18
    "�Զ����ò���20      "  ,   //  878 13-19
    "�Զ����ò���21      "  ,   //  879 13-20
    "�Զ����ò���22      "  ,   //  880 13-21
    "�Զ����ò���23      "  ,   //  881 13-22
    "�Զ����ò���24      "  ,   //  882 13-23
    "�Զ����ò���25      "  ,   //  883 13-24
    "�Զ����ò���26      "  ,   //  884 13-25
    "�Զ����ò���27      "  ,   //  885 13-26
    "�Զ����ò���28      "  ,   //  886 13-27
    "�Զ����ò���29      "  ,   //  887 13-28
    "�Զ����ò���30      "  ,   //  888 13-29
    "�Զ����ò���31      "  ,   //  889 13-30
    "�Զ����ò���32      "  ,   //  890 13-31
    "�Զ����ò���33      "  ,   //  891 13-32
    "�Զ����ò���34      "  ,   //  892 13-33
    "�Զ����ò���35      "  ,   //  893 13-34
    "�Զ����ò���36      "  ,   //  893 13-35
    "�Զ����ò���37      "  ,   //  894 13-36
    "�Զ����ò���38      "  ,   //  895 13-37
    "�Զ����ò���39      "  ,   //  896 13-38
    "�Զ����ò���40      "  ,   //  897 13-39
    "�Զ����ò���41      "  ,   //  898 13-30
    "�Զ����ò���42      "  ,   //  899 13-41
    "�Զ����ò���43      "  ,   //  900 13-42
    "�Զ����ò���44      "  ,   //	901 13-43
    "�Զ����ò���45      "  ,   //	902 13-44
    "�Զ����ò���46      "  ,   //	903 13-45
    "�Զ����ò���47      "  ,   //	904 13-46
    "�Զ����ò���48      "  ,   //	905 13-47
    "�Զ����ò���49      "  ,   //  906 13-48
    "�Զ����ò���50      "  ,   //  907 13-49
    "�Զ����ò���51      "  ,   //  908 13-50
    "�Զ����ò���52      "  ,   //  909 13-51
    "�Զ����ò���53      "  ,   //  910 13-52
    "�Զ����ò���54      "  ,   //  911 13-53
    "�Զ����ò���55      "  ,   //  912 13-54
    "�Զ����ò���56      "  ,   //  913 13-55
    "�Զ����ò���57      "  ,   //  914 13-56
    "�Զ����ò���58      "  ,   //	915 13-57
    "�Զ����ò���59      "  ,   //	916 13-58
    "�Զ����ò���60      "  ,   //	917 13-59
    "�Զ����ò���61      "  ,   //	918 13-60
    "�Զ����ò���62      "  ,   //	919 13-61
    "�Զ����ò���63      "  ,   //  920 13-62
    "�Զ����ò���64      "  ,   //	921 13-63
    "�Զ����ò���65      "  ,   //	922 13-64
    "�Զ����ò���66      "  ,   //	923 13-65
    "�Զ����ò���67      "  ,   //	924 13-66
    "�Զ����ò���68      "  ,   //	925 13-67
    "�Զ����ò���69      "  ,   //	926 13-68
    "�Զ����ò���70      "  ,   //  927 13-69
    "�Զ����ò���71      "  ,   //  928 13-70
    "�Զ����ò���72      "  ,   //  929 13-71
    "�Զ����ò���73      "  ,   //  930 13-72
    "�Զ����ò���74      "  ,   //  931 13-73
    "�Զ����ò���75      "  ,   //  932 13-74
    "�Զ����ò���76      "  ,   //  933 13-75
    "�Զ����ò���77      "  ,   //  934 13-76
    "�Զ����ò���78      "  ,   //	935 13-77
    "�Զ����ò���79      "  ,   //	936 13-78
    "�Զ����ò���80      "  ,   //	937 13-79
    "�Զ����ò���81      "  ,   //  938 13-80
    "�Զ����ò���82      "  ,   //	939 13-81
    "�Զ����ò���83      "  ,   //	940 13-82
    "�Զ����ò���84      "  ,   //	941 13-83
    "�Զ����ò���85      "  ,   //  942 13-84
    "�Զ����ò���86      "  ,   //  943 13-85
    "�Զ����ò���87      "  ,   //  944 13-86
    "�Զ����ò���88      "  ,   //  945 13-87
    "�Զ����ò���89      "  ,   //  946 13-88
    "�Զ����ò���90      "  ,   //  947 13-89
    "�Զ����ò���91      "  ,   //  948 13-90
    "�Զ����ò���92      "  ,   //  949 13-91
    "�Զ����ò���93      "  ,   //  950 13-92
    "�Զ����ò���94      "  ,   //  951 13-93
    "�Զ����ò���95      "  ,   //  952 13-94
    "�Զ����ò���96      "  ,   //  953 13-95
    "�Զ����ò���97      "  ,   //  954 13-96
    "�Զ����ò���98      "  ,   //  955 13-97
    "�Զ����ò���99      "  ,   //  956 13-98
    "�Զ����ò���100     "  ,   //  957 13-99
    
/*--- GROUP 14------------------------------------------*/
/*  "12345678901234561234"	*/
	"Id PWRSAVE Level%   "	,	//	958 14-00	Ids Power Save Level
	"VF CURVE MODE       "	,	//	959 14-01	VF voltage mode selection
	"Overload 1 Mode     "	,	//	960 14-02	Constant Torque Selection
	"Auto ACC/DEC        "	,	//	961 14-03	Auto Accel/Decel
	"Unit ACC/DEC T      "	,	//	962 14-04	Unit of Acc/Dec time
	"POWER SAVE MODE     "	,	//  963 14-05	Power Save mode
	"Stop Methods        "	,	//  964 14-06	Stop Methods
	"Reverse Operate     "	,	//  965 14-07	Reverse Operation
	"Skip Freq. 1UP  Hz  "	,	//  966 14-08	Skip Freq. Point 1 upper limit
	"Skip Freq. 1LOW Hz  "	,	//  967 14-09	Skip Freq. Point 1 lower limit
	"Skip Freq. 2UP  Hz  "	,	//  968 14-10	Skip Freq. Point 2 upper limit
	"Skip Freq. 2LOW Hz  "	,	//  969 14-11	Skip Freq. Point 2 lower limit
	"Skip Freq. 3UP  Hz  "	,	//  970 14-12	Skip Freq. Point 3 upper limit
	"Skip Freq. 3LOW Hz  "	,	//  971 14-13	Skip Freq. Point 3 lower limit
	"Motor2 Fbase    Hz  "	,	//  972 14-14	Motor Base Frequency 2
	"Max Out-Volt 2  V   "	,	//  973 14-15	Max Output Voltage 2
	"Mid Out-Freq.2-1Hz  "	,	//  974 14-16	Mid Output Freq.2 1
	"Mid Out-Volt 2-1V   "	,	//  975 14-17	Mid Output Voltage 2 1
	"Mid Out-Freq.2-2Hz  "	,	//  976 14-18	Mid Output Freq.2 2
	"Mid Out-Volt 2-2V   "	,	//  977 14-19	Mid Output Voltage 2 2
	"Min Out-Freq.2  Hz  "	,	//  978 14-20	Min Output Freq. 2
	"Min Out-Volt 2  V   "	,	//  979 14-21	Min Output Voltage 2
	"UP/DOWN Key MODE    "	,	//  980 14-22	up/down key mode
	"UP/DOWN KEY SPD     "	,	//  981 14-23	up/down key speed
	"Counter Set         "	,	//  982 14-24	Counter Value Set (Complete)
	"Counter Reach       "	,	//  983 14-25	Counter Value Reach (Preset)
	"LIMIT SCALE         "	,	//  984 14-26	LIMIT_SCALE      //[weak 
	"Multi-Fun Input9    "	,	//  985 14-27	Multi-Function Input 9
	"Multi-Fun InputA    "	,	//  986 14-28	Multi-Function Input 10
	"Multi-Fun InputB    "	,	//  987 14-29	Multi-Function Input 11
	"Multi-Fun InputC    "	,	//  988 14-30	Multi-Function Input 12
	"Multi-Fun InputD    "	,	//  989 14-31	Multi-Function Input 13
	"Multi-Fun InputE    "	,	//  990 14-32	Multi-Function Input 14
	"Fault Reset OP      "	,	//  991 14-33	External Terminal Run after Fault 
	"ACI/AVI2 SEL        "	,	//  992 14-34	ACI change to AVI2
	"Addition of AI      "	,	//  993 14-35	Addition Function of AI
	"Multi-Posit 1       "	,	//  993 14-36	Multi-Position Point 1
	"Multi-Posit 2       "	,	//  994 14-37	Multi-Position Point 2
	"Multi-Posit 3       "	,	//  995 14-38	Multi-Position Point 3
	"Multi-Posit 4       "	,	//  996 14-39	Multi-Position Point 4
	"Multi-Posit 5       "	,	//  997 14-40	Multi-Position Point 5
	"Multi-Posit 6       "	,	//  998 14-41	Multi-Position Point 6
	"Multi-Posit 7       "	,	//  999 14-42	Multi-Position Point 7
	"Multi-Posit 8       "	,	//  1000 14-43	Multi-Position Point 8
	"Multi-Posit 9       "	,	//	1001 14-44	Multi-Position Point 9
	"Multi-Posit 10      "	,	//	1002 14-45	Multi-Position Point 10
	"Multi-Posit 11      "	,	//	1003 14-46	Multi-Position Point 11
	"Multi-Posit 12      "	,	//	1004 14-47	Multi-Position Point 12
	"Multi-Posit 13      "	,	//	1005 14-48	Multi-Position Point 13
	"Multi-Posit 14      "	,	//  1006 14-49	Multi-Position Point 14
	"Multi-Posit 15      "	,	//  1007 14-50	Multi-Position Point 15
	"MOTOR 1 OR 2        "	,	//  1008 14-51	Motor Selection 1 or 2
	"Y-D Switch Hz   Hz  "	,	//  1009 14-52	Y-Delta Connected switching rpm
	"Y-D Switch Sel      "	,	//  1010 14-53	Y-Delta switched Enable
	"Motor2 Rated    Amps"	,	//  1011 14-54	Motor 2 rated Current
	"Motor2 Rated P  Kw  "	,	//  1012 14-55	Motor 2 Rated Power
	"Motor2 Rated    RPM "	,	//  1013 14-56	Motor 2 Rated RPM
	"Motor2 Poles        "	,	//  1014 14-57	Motor 2 pole No.
	"Motor2 No-Load  Amps"	,	//	1015 14-58	Motor 2 No-Load Current
	"Motor2 Rs       ohm "	,	//	1016 14-59	Motor 2 Rs
	"Motor2 Rr       ohm "	,	//	1017 14-60	Motor 2 Rr
	"Motor2 Lm       mH  "	,	//	1018 14-61	Motor 2 Lm
	"Motor2 Lx       mH  "	,	//	1019 14-62	Motor 2 Lx
	"Y-D On Delay T      "	,	//  1020 14-63	Y-Delta On delay time
	"OV stall level  V   "	,	//	1021 14-64	OV stall level
	"Thermal RLY2 SEL    "	,	//	1022 14-65	Thermal Relay 2 Selection
	"Thermal RLY2 T      "	,	//	1023 14-66	Thermal Relay 2 Time
	"Momentary Power     "	,	//	1024 14-67	Momentary Power Loss
	"Power Loss Time sec "	,	//	1025 14-68	Max. allowable PL time
	"Base Block Time sec "	,	//	1026 14-69	BB Time for speed serach
	"SPD Search Curr %   "	,	//  1027 14-70	Current level for SPD serach
	"BB Treatment        "	,	//  1028 14-71	bb treatment for oc, ov, bb
	"Auto Restart        "	,	//  1029 14-72	Auto restart after fault
	"Restart Method      "	,	//  1030 14-73	Auto restart Speed serach method
	"DEB Decel SEL       "	,	//  1031 14-74	Deceleration at Momertary Power 
	"DEB Return Time     "	,	//  1032 14-75	KEB Return Time
	"PID Fdb SEL         "	,	//  1033 14-76	PID feedback selection	
	"P Gain of PID       "	,	//  1034 14-77	P gain of PID	
	"I Gain of PID   sec "	,	//	1035 14-78	I gain of PID	
	"D Gain of PID       "	,	//	1036 14-79	D gain of PID	
	"Up Limit for I  %   "	,	//	1037 14-80	Upper bound for integral	
	"PID Out-Limiter %   "	,	//  1038 14-81	PID output Freq. Limit	
	"PID Offset      %   "	,	//	1039 14-82	PID offset	
	"PID Out-Filter  sec "	,	//	1040 14-83	Derivative Filter Time Constant	
	"Fdb Detect Time sec "	,	//	1041 14-84	Feedback signal detection time	
	"PID Fdb Loss        "	,	//  1042 14-85	PID feedback loss	
	"SLEEP FREQ          "	,	//  1043 14-86	Sleep Frequency	
	"WAKE FREQ           "	,	//  1044 14-87	Wake up Frequency	
	"SLEEP TIME          "	,	//  1045 14-88	Sleep Time	
	"PID DEV. LEVEL  %   "	,	//  1046 14-89	PID Deviation Level	
	"PID DEV. TIME       "	,	//  1047 14-90	PID Deviation Time	
	"PID Fbk Filter  sec "	,	//  1048 14-91	PID feedback filter	
	"Comm Main Freq. Hz  "	,	//  1049 14-92	Main Frequency from 
	"Block Trans. 1      "	,	//  1050 14-93	Block Transfer 1	
	"Block Trans. 2      "	,	//  1051 14-94	Block Transfer 2	
	"Block Trans. 3      "	,	//  1052 14-95	Block Transfer 3
	"Block Trans. 4      "	,	//  1053 14-96	Block Transfer 4
	"Block Trans. 5      "	,	//  1054 14-97	Block Transfer 5
	"Block Trans. 6      "	,	//  1055 14-98	Block Transfer 6
	"Block Trans. 7      "	,	//  1056 14-99	Block Transfer 7
	"Block Trans. 8      "	,	//  1057 14-100 Block Transfer 8
	"Block Trans. 9      "	,	//  1086 14-101 Block Transfer 9
	"Block Trans. 10     "	,	//	1087 14-102 Block Transfer 10
	"WEAKLPF             "	,	//	1088 14-103 WEAKLPF    //[weak magnet, 
	"WEAKTHETA           "	,	//	1089 14-104 WEAKTHETA  //[weak magnet, 
	"OVER_SCALE          "	,	//	1090 14-105 OVER_SCALE //[weak magnet, 
	"PG Position Home    "	,	//	1091 14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	1092 14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	1093 14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	1094 14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	1095 14-110 FMax Target by Vcommand Position
	"RESERVE             "	,	//	1096 14-111 Accel. Time for Position
	"PG Mech. Gear A     "	,	//	1097 14-112 PG Mechanical Gear A
	"PG Mech. Gear B     "	,	//	1098 14-113 PG Mechanical Gear B
	"System Jm       PU  "	,	//	1099 14-114 Interia of motor PU
	"M1IdsRef Limit   %  "	,	//	1100 14-115 Motor1 IdsRef Limit
	"M2IdsRef Limit   %  "	,	//	1101 14-116 Motor2 IdsRef Limit
	"Phase Loss Time sec "	,	//	1102 14-117 Phase Loss Time
	"TH Inside Temp   C  "	,	//	1103 14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	1104 14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	1105 14-120 SVC Slip Generation Compensation 
	"PG-REF COM LPG      "	,	//	1106 14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	1107 14-122 Tension of Torque Control
	"DIAMETER        m   "	,	//	1108 14-123 Diameter of Material
	"DEPTH           cm  "	,	//	1109 14-124 Depth of meterial
	"RESERVE             "	,	//	1110 14-125 Reserve
	"ABZ ST Times        "	,	//	1111 14-126 Reserve
	"ABZ ST Duty         "	,	//	1112 14-127 Reserve
	"TIMER OF PHL    hr. "	,	//	1113 14-128 Timer of Phase loss (hour)
	"RESERVE             "	,	//	1114 14-129 Time of APR Curve
    "Jm source           "  ,   //	1115 14-130 IM control use inertia source
	"PHL LEVEL           "	,	//	1116 14-131 PHASE LOSS detect level
	"Muti-input state    "	,	//	1117 14-132 muti input state
    "StandStill Curr.Amps"  ,   //  1118 14-133 Standstill Current
	"PG Scale Factor     "	,	//	1119 14-134 Division factor of PG	
	"OLD Irate           "	,	//	1120 14-135 OLD Irate            // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_CONTROL         "	,   //  1121 14-136 [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   //  1122 14-137 [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_Check_Time  sec "	,   //  1123 14-138 [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_Time     ms  "	,   //  1124 14-139 [CAN Protocol for High Cap, Bernie, 09/22/2011]   
    "COM1ͨѶ��ַ        "  ,   //  1125 14-140 Comm Address                //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                       
    "COM1ͨѶ�����ٶ�kbps"  ,   //  1126 14-141 Tranmission speed                          
    "COM1ͨѶ������    "  ,   //  1127 14-142 Comm fault Treatment                      
    "COM1��ʱ���ʱ��sec "  ,   //  1128 14-143 Comm Time out                             
    "COM1ͨѶ��ʽ        "  ,   //  1129 14-144 Comm Protocol                             
    "COM1��Ӧ��ʱʱ��ms  "  ,   //  1130 14-145 ASC remote Response Delay Time,  
    "OPHL 10Hz COUNT     "  ,   //  1131 14-146 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  5Hz COUNT     "  ,   //  1132 14-147 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL  2Hz COUNT     "  ,   //  1133 14-148 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.5Hz COUNT    "  ,   //  1134 14-149 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL 0.2Hz COUNT    "  ,   //  1135 14-150 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 1       "  ,   //  1136 14-151 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,   //  1137 14-152 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "OPHL I GAIN 2       "  ,  	//	1138 14-153 The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
};
#endif

#if Language_TR
const string20 prinfo_tur[EPMAX] = {	
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
#else
	"Rezerve			 "	,	//	01-41  RESERVE
	"Rezerve			 "	,	//	01-42  RESERVE
	"Rezerve			 "	,	//	01-43  RESERVE
#endif
	"IODLC TRIGGE SPDHz  "  ,   //	01-44   MI direct stop trigger speed	//Task 268622 IO Direct Landing	//Mitong 20230221 add	
	"Rezerve			 "	,	//	195 01-45   RESERVED
    "Rezerve			 "	,	//	196 01-46   RESERVED
    "Rezerve			 "	,	//	197 01-47   RESERVED
    "Rezerve			 "	,	//	198 01-48   RESERVED
    "Rezerve			 "	,	//	199 01-49   RESERVED
//-----------------------------------------------------------------------------------------------------------	

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
    //"AUI1�����趨        "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
    //"AUI2�����趨        "	,	//	238  03-26    AUI2 Communciate

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
	"Hall Giris Tipi     "  ,   //  384   10-10 Hall Input Types
	"Zero SPD Loop Kp%   "	,	//	385   10-11 KP gain of ASR in Zero speed	
	"Zero SPD Loop Kisan "	,	//	386   10-12 Ki gain of ASR in Zero speed	
	"Low SPD Loop Kp %   "	,	//	387   10-13 ASR P Gain 1	                
	"Low SPD Loop Ki san "	,	//	388   10-14 ASR I Gain 1	                
	"High SPD Loop Kp%   "	,	//	389   10-15 ASR P Gain 2	                
	"High SPD Loop Kisan "	,	//	390   10-16 ASR I Gain 2	                
	"ASR1/2 Switch F Hz  "	,	//	391   10-17 ASR1/ASR2 switch freq	        
	"Primary LPG     san "	,	//	392   10-18 Primary LowPass filter Gain 
	"Position Loop Kp%   "  ,	//	393   10-19 position control Kp Gain  
    "Low SPD Slope   Hz  "  ,   //  394   10-20 Low Spd band
    "High SPD Slope  Hz  "  ,   //  395   10-21 High Spd band
	"POS CONT Time   san "	,	//	396   10-22 Position control time
	"POS CONT LPG    san "	,	//	397   10-23 Position control LOW POSS FILTER
	"Source of POS       "	,	//	398   10-24 Source of position control, add by dino, 
	"Zero SPD Land Kp%   "	,	//	399   10-25 KP gain of ASR in Zero speed of 
	"Zero SPD Land Kisan "	,	//	400   10-26 Ki gain of ASR in Zero speed of Landing
	"Position SPD Kp %   "	,	//	385   10-27 KP gain of ASR in Zero speed during 
	"Position SPD Ki san "	,	//	386   10-28 Ki gain of ASR in Zero speed during 
    "PG KardFrekBolme    "	,   //  4xx   10-29   PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG Kard Modu        "	,   //  4xx   10-30   PG Card Mode setting                      //[DCI Level when stop, Bernie, 05/21/2012]    
    "PG C+/C- Tipi       "  ,   //  110   15-110  RESERVED     //[change parameter to normal group, Bernie, 2014/02/14]
    "AsiriHizlanSev  m/s2"  ,   //  3XX   10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "AsiriHizlanTespisan "  ,   //  3XX   10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "AsiriHizlan Ayar    "  ,   //  3XX   10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
    "Sistem Kontrol      "	,	//	401   11-00 system control bit0:auto, bit1:Jm tunning, 
    "Fmax Spd        m/s "  ,   //  402   11-01 Lift operation speed                                        
    "Kasnak Cap          "  ,   //  403   11-02 SHEAVE diameter		                
    "Mek Disli Oran      "  ,   //  404   11-03 Gear Ratio                                              
    "Suspansiyon Oran    "  ,   //  405   11-04 Suspension ratio	                                        
    "Atalet Orani    %   "  ,   //  406   11-05 inertia	percent		                  
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
    "Koruma Biti         "  ,   //  419   11-18 Protect Bit	                                                
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
	"������������m/s2"	,	//	156	01-12	1st Acceleration time
	"������������.1m/s2"	,	//	157	01-13	1st Deceleration time
	"������������m/s2"	,	//	158	01-14	2nd Acceleration time
	"������������.2m/s2"	,	//	159	01-15	2nd Deceleration time
	"������������m/s2"	,	//	160	01-16	3rd Acceleration time
	"������������.3m/s2"	,	//	161	01-17	3rd Deceleration time
	"������������m/s2"	,	//	162	01-18	4th Acceleration time
	"������������.4m/s2"	,	//	163	01-19	4th Deceleration time
	"�������� JOGm/s2"	,	//	164	01-20	JOG Acceleration time
	"����������.JOGm/s2"	,	//	165	01-21	JOG Deceleration time
	"������������  m/s2"	,	//	175	01-31	Stop Deceleration time
};

const string20 prinfo_rus_ACC_fts2[11] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"������������f/s2"	,	//	156	01-12	1st Acceleration time
	"������������.1f/s2"	,	//	157	01-13	1st Deceleration time
	"������������f/s2"	,	//	158	01-14	2nd Acceleration time
	"������������.2f/s2"	,	//	159	01-15	2nd Deceleration time
	"������������f/s2"	,	//	160	01-16	3rd Acceleration time
	"������������.3f/s2"	,	//	161	01-17	3rd Deceleration time
	"������������f/s2"	,	//	162	01-18	4th Acceleration time
	"������������.4f/s2"	,	//	163	01-19	4th Deceleration time
	"�������� JOGf/s2"	,	//	164	01-20	JOG Acceleration time
	"����������.JOGf/s2"	,	//	165	01-21	JOG Deceleration time
	"������������  f/s2"
};

const string20 prinfo_rus_SCurve_ms3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S ������ 1      m/s3"	,	//	168	01-24	S curve Accel time 1
	"S ������ 2      m/s3"	,	//	169	01-25	S curve Accel time 2
	"S ������ 3      m/s3"	,	//	170	01-26	S curve Decel time 1
	"S ������ 4      m/s3"	,	//	171	01-27	S curve Decel time 2
	"S ������ 5      m/s3"	,	//	174	01-30	S curve Decel time 3
};

const string20 prinfo_rus_SCurve_fts3[5] = { //[S curve, ACC unit,Jason,2019/10/01]
/*	"12345678901234561234"	*/		
	"S ������ 1      f/s3"	,	//	168	01-24	S curve Accel time 1
	"S ������ 2      f/s3"	,	//	169	01-25	S curve Accel time 2
	"S ������ 3      f/s3"	,	//	170	01-26	S curve Decel time 1
	"S ������ 4      f/s3"	,	//	171	01-27	S curve Decel time 2
	"S ������ 5      f/s3"	,	//	174	01-30	S curve Decel time 3
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
	"���������� ��    "	,	//	128 00-00	Model Type of Drive 
	"�������� ��  Amps"	,	//	129 00-01	Rated Current
	"��������������     "	,	//	130 00-02	Parameter Reset
	"�� ��������      "	,	//	131 00-03	Start up Display
	"������������-    "	,	//	132 00-04	User Display
	"������������     "	,	//	133	00-05	User Coefficient
	"������ ��            "	,	//	134	00-06	Software Version
	"���� ������          "	,	//	135	00-07	Password Input
	"������������       "	,	//	136	00-08	Password Input
	"��������������     "	,	//	137	00-09	Control Methods
	"������. ��������	  "	,	//	138	00-10	Velocity Unit Select
	"������. ��������     "	,	//	139 00-11   Change Output Direction, Added by sampo , 06/11/2009
	"������ȸ     KHz "	,	//	140	00-12	Carry Frequency
	"��                 "	,	//	141	00-13	AVR
	"�������� ������    "	,	//	142	00-14	Source of Freq. Command
	"�������� ������      "	,	//	143	00-15	Source of Oper. Command
/*---- GROUP 01---------------------------------------*/
/*  "12345678901234561234"	*/
	"����.���������Hz  "	,	//	144	01-00	Max Output Freq.
	"����������.1Hz  "	,	//	145	01-01	Motor Base Frequency 1
	"��������.��.1 V   "	,	//	146	01-02	Max Output Voltage
	"��.������ ��.1Hz  "	,	//	147	01-03	Mid Output Freq.1
	"��.������.1 ��.1V   "	,	//	148	01-04	Mid Output Voltage 1
	"��.������ ��.1Hz  "	,	//	149	01-05	Mid Output Freq.2
	"��.������.2 ��.1V   "	,	//	150	01-06	Mid Output Voltage 2
	"����������.1Hz  "	,	//	151	01-07	Min Output Freq.
	"��������. ��.1V   "	,	//	152	01-08	Min Output Voltage
	"���� ������ Hz  "	,	//	153	01-09	Start Frequency
	"����.������.����Hz  "	,	//	154	01-10	Upper Bound Freq.
	"����.������.����Hz  "	,	//	155	01-11	Lower Bound Freq.
	"������������sec "	,	//	156	01-12	1st Acceleration time
	"������������.1sec "	,	//	157	01-13	1st Deceleration time
	"������������sec "	,	//	158	01-14	2nd Acceleration time
	"������������.2sec "	,	//	159	01-15	2nd Deceleration time
	"������������sec "	,	//	160	01-16	3rd Acceleration time
	"������������.3sec "	,	//	161	01-17	3rd Deceleration time
	"������������sec "	,	//	162	01-18	4th Acceleration time
	"������������.4sec "	,	//	163	01-19	4th Deceleration time
	"�������� JOGsec "	,	//	164	01-20	JOG Acceleration time
	"����������.JOGsec "	,	//	165	01-21	JOG Deceleration time
	"������JOG     Hz  "	,	//	166	01-22	JOG Frequency
	"�������-4Hz  "	,	//	167	01-23	Transition Frequency ACC1/DEC1 to ACC4/DEC4
	"S ������ 1      sec "	,	//	168	01-24	S curve Accel time 1
	"S ������ 2      sec "	,	//	169	01-25	S curve Accel time 2
	"S ������ 3      sec "	,	//	170	01-26	S curve Decel time 1
	"S ������ 4      sec "	,	//	171	01-27	S curve Decel time 2
	"��0-��������    "	,	//	172	01-28	Select Zero Speed
	"����.�����������Hz  "	,	//	173	01-29	Landing Frequency 
	"S ������ 5      sec "	,	//	174	01-30	S curve Decel time 3
	"������������  sec "	,	//	175	01-31	Stop Deceleration time
    "����.����.����m/s "	,	//	1xx	01-32
    "�����������.���sec "	,	//	1xx	01-33   IODHT IO direct hold time   
    "�����������.���sec "	,	//	1xx	01-34   IODLT IO direct landing freq
    "CRPLS��������   "	,	//	1xx	01-35   IODLT IO direct landing time
    "IOD ��������cm  "	,	//	1xx	01-36   IODLT IO direct DistancE
    "IOD����.����  m   "	,	//	1xx	01-37   IODLT IO direct DistancE
    "IODLC����         "	,	//	1xx	01-37   IODLT IO direct DistancE
    "����.����.������Hz  "  ,   //  1xx 01-37   IODLT IO direct DistancE
    "ESD����.������. sec "	,	//	1xx	01-37   IODLT IO direct DistancE
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Emergency DEC   sec "  ,   //  105 15-105  RESERVED
    "Emergency S3    sec "  ,   //  105 15-105  RESERVED
    "Emergency S4    sec "  ,   //  105 15-105  RESERVED
#else
	"��������������    "	,	//	01-41  RESERVE
	"��������������    "	,	//	01-42  RESERVE
	"��������������    "	,	//	01-43  RESERVE
#endif
	"IODLC TRIGGE SPDHz  "  ,   //	01-44   MI direct stop trigger speed	//Task 268622 IO Direct Landing	//Mitong 20230221 add	
	"��������������    "	,	//	195 01-45   RESERVED
    "��������������    "	,	//	196 01-46   RESERVED
    "��������������    "	,	//	197 01-47   RESERVED
    "��������������    "	,	//	198 01-48   RESERVED
    "��������������    "	,	//	199 01-49   RESERVED
//----------------------------------------------------------------------------------------------------------------

/*---- GROUP 02---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"2/3-������.��   "	,	//	176	02-00	2/3 wire control                
	"��������.���� 1     "	,	//	177	02-01	Multi-Function Input 1          
	"��������.���� 2     "	,	//	178	02-02	Multi-Function Input 2          
	"��������.���� 3     "	,	//	179	02-03	Multi-Function Input 3          
	"��������.���� 4     "	,	//	180	02-04	Multi-Function Input 4          
	"��������.���� 5     "	,	//	181	02-05	Multi-Function Input 5          
	"��������.���� 6     "	,	//	182	02-06	Multi-Function Input 6          
	"��������.���� 7     "	,	//	183	02-07	Multi-Function Input 7          
	"��������.���� 8     "	,	//	184	02-08	Multi-Function Input 8		    
	"�������� ����.��sec "	,	//	185	02-09	Digital in response time		
	"��������������    "	,	//	186	02-10	Multi-Function Input Inverse	
	"�������� ���� 1     "	,	//	187	02-11	Multi-Function Relay 1		    
	"�������� ���� 2     "	,	//	188	02-12	Multi-Function Relay 2		    
	"�������� ���� 3     "	,	//	189	02-13	Multi-Function Output 1		    
	"�������� ���� 4     "	,	//	190	02-14	Multi-Function Output 2		    
	"��������.����1    "	,	//	191	02-15	Multi-Function Output 1		    
	"��������.����2    "	,	//	192	02-16	Multi-Function Output 2		    
	"��������.����3    "	,	//	193	02-17	Multi-Function Output 1		    
	"��������.����4    "	,	//	194	02-18	Multi-Function Output 2		    
	"��������.����5    "	,	//	195	02-19	Multi-Function Output 1		    
	"��������.����6    "	,	//	196	02-20	Multi-Function Output 2		    
	"��������.����7    "	,	//	197	02-21	Multi-Function Output 1		    
	"��������.����8    "	,	//	198	02-22	Multi-Function Output 2		    
	"������ ������   "	,	//	199	02-23	Multi-Function Output inverse	
    "����������-��   "  ,   //  200 02-24   Sequence start mode
	"������������Hz  "	,	//	201	02-25	Desired Frequency 1		        
	"������ ������ Hz  "	,	//	202	02-26	Band of Desired Frequency 1		
	"������������Hz  "	,	//	203	02-27	Desired Frequency 2		        
	"������ ������ Hz  "	,	//	204	02-28	Band of Desired Frequency 2		
	"��������������sec "	,	//	205	02-29	Brake Delay Timer at run
	"�������������. sec "	,	//	206	02-30	Brake Delay Timer at stop
	"��������಺�. sec "	,	//	207	02-31	Mech Contact Delay Timer run
	"���������˺sec "	,	//	208	02-32	Mech Contact Delay Timer stop				            
	"��ڲ��.������   "	,	//	209	02-33	Isum Current Output Detect	    
	"����.�ڴ��ڲ��Hz  "	,	//	210	02-34	Speed Area
	"����������.����.sec "	,	//	211	02-35	Mechanical Brake Checking Time
	"���Ҳ�ۺ��������sec "	,	//	212 02-36   Magnetic Contactor Checking Time
	"����.��������   "  ,   //  213 02-37   Mechanical Brake Checking Current Enable
	"Y-D������������ sec "  ,   //  2xx 02-38   Star Contactor delay time when driver run    //[Star contactor function, Bernie, 2017/03/22]
	"Y-D���������� sec "  ,   //  2xx 02-39   Star Contactor delay time when driver stop  //[Star contactor function, Bernie, 2017/03/22]
	"LU/LD Fault SEL     "  ,   //  2xx 02-40   LU/LD error  Selection	  //#15977, LULD detect, James, 2021/04/01
	"LU/LD Open Det. sec "  ,   //  2xx 02-41   LD/LD Open Detect Time       //#15977, LULD detect, James, 2021/04/01
	"LU/LD Short Det.sec "  ,   //  2xx 02-42   LD/LD Short Detect Time      //#15977, LULD detect, James, 2021/04/01
	"SPEED-REACH BND Hz  "	,   //  202 02-43   Band of Speed Agree Function  //#18572
    "STO Short Det   sec "  ,   //  2xx 02-44   STO shor detect time //#18196  STO new function for SIL2, James, 2021/10/06
    "819 Sensor          "  ,   //  2xx 02-45   //[Artemis Add Sensor819 Function/Special/2022/06/06]
    "Speed Limit     m/s "  ,   //  2xx 02-46   //[Artemis Add Sensor819 Function/Special/2022/06/06]
/*---- GROUP 03---------------------------------------*/						
/*  "12345678901234561234"	*/					
	"������.���� AUI1    "	,	//	214	03-00    AUI1 selection     //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"��������������    "	,	//	215	03-01    ACI  selection      //[ACI function remove, Bernie, 01/20/2012]
	"������.���� AUI2    "	,	//	216	03-02    AUI2 selection    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"�������� AUI1   %   "	,	//	217	03-03    AUI1 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"��������������    "	,	//	218	03-04    ACI  input Bias    //[ACI function remove, Bernie, 01/20/2012]
	"�������� AUI2   %   "	,	//	219	03-05    AUI2 input Bias   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"����������AUI1    "	,	//	220  03-06    AUI1 input Polarity         //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"��������������    "	,	//	221  03-07    ACI  input Polarity     //[ACI function remove, Bernie, 01/20/2012]
	"����������AUI2    "	,	//	222  03-08    AUI2 input Polarity    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"����.������.AUI1%   "	,	//	223  03-09    AUI1 input Gain     //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"��������������    "	,	//	224  03-10    ACI  input Gain     //[ACI function remove, Bernie, 01/20/2012]
	"����.������.AUI2%   "	,	//	225  03-11    AUI2 input Gain   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"AUI1 ����Ľ   sec "	,	//	226  03-12    Low pass filter of AUI1 input   //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"��������������    "	,	//	227  03-13    Low pass filter of ACI  input      //[ACI function remove, Bernie, 01/20/2012]
	"AUI2 ����Ľ   sec "	,	//	228  03-14    Low pass filter of AUI2 input    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"��������������    "	,	//	229  03-15    Loss of ACI            //[ACI function remove, Bernie, 01/20/2012]
    "��������������    "  ,   //  230  03-16
	"�����ذ�1         "	,	//	231  03-17    Analong Output 1
	"����������.AO1%   "	,	//	232  03-18    Analong Output 1 Gain
	"AO1 ��������    "	,	//	233  03-19    AO1 in minus value
	"�����ذ�2         "	,	//	234  03-20    Analong Output 2
	"����������.AO2%   "	,	//	235  03-21    Analong Output 2 Gain
	"AO2 ��������    "	,	//	236  03-22    AO2 in minus value
	"���������� AUI1     "	,	//	237  03-23    AUI1 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	"���������� AUI2     "	,	//	238  03-24    AUI2 Input Polar    //[AI chenge to AUI, Lyabryan, 03/27/2015]
	//"AUI1��.����  /"AUI1 In Setting     "	,	//	237  03-25    AUI1 Communciate    //[DLC, Bernie, 2014/10/06]
	//"AUI2��.����  /"AUI2 In Setting     "	,	//	238  03-26    AUI2 Communciate
	
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/
    "0-��������    Hz  "  , //  239 04-00 Multi-Speed 0
    "1-��������    Hz  "  , //  240 04-01 Multi-Speed 1
    "2-��������    Hz  "  , //  241 04-02 Multi-Speed 2
    "3-��������    Hz  "  , //  242 04-03 Multi-Speed 3
    "4-��������    Hz  "  , //  243 04-04 Multi-Speed 4
    "5-��������    Hz  "  , //  244 04-05 Multi-Speed 5
    "6-��������    Hz  "  , //  245 04-06 Multi-Speed 6
    "7-��������    Hz  "  , //  246 04-07 Multi-Speed 7
    "8-��������    Hz  "  , //  247 04-08 Multi-Speed 8
    "9-��������    Hz  "  , //  248 04-09 Multi-Speed 9
    "10-��������   Hz  "  , //  249 04-10 Multi-Speed 10
    "11-��������   Hz  "  , //  250 04-11 Multi-Speed 11
    "12-��������   Hz  "  , //  251 04-12 Multi-Speed 12
    "13-��������   Hz  "  , //  252 04-13 Multi-Speed 13
    "14-��������   Hz  "  , //  253 04-14 Multi-Speed 14
    "15-��������   Hz  "  , //  254 04-15 Multi-Speed 15
    "������.��-��  m/s "  , //  2xx 04-16
    "����.�����������m/s "  , //  2xx 04-17
    "����.���������m/s "  , //  2xx 04-18
	                 
    "Rope Slip Comp. mm  "  , //  2xx 04-19 GFC Rope compensation, 2021/03/30
    "TABST0 ������       "  ,   //    2xx 04-20
    "TABST2 ������       "  ,   //    2xx 04-21
	                 
    "����. ����          "  , //  2xx 04-22
    "����������        "  , //  2xx 04-23
    "PG ��������   %   "  , //  2xx 04-24
    "Sensor Delay Cmpsec "  , //  2xx 04-25
    "DLC ������.����.ms  "  , //  2xx 04-26
    "����������    mm  "  , //  2xx 04-27 
    "�� �� ��  m   "  , //  2xx 04-28
    "�� �� ��  mm  "  , //  2xx 04-29
    "��������. PG H    "  , //  2xx 04-30 
    "��������. PG L    "  , //  2xx 04-31
    "������:����.PG H    "  , //  2xx 04-32
    "������:����.PG L    "  , //  2xx 04-33
    "������ PG ��      "  , //  2xx 04-34
    "������ PG ��      "  , //  2xx 04-35    
    "������DLC         "  , //  2xx 04-36
    "��PDO             "  , //  2xx 04-37
    "����SWTol.Gap mm  "  , //  2xx 04-38
    "% �� ���� ��-��   "  , //  2xx 04-39 //[ADCO EPS Modify]
    "Spring Extend   mm  "  , //  2xx 04-40//#16386 optimization for over landing cause from leveling sensor calibration , James, 2021/04/13
    "��������EST       "  , //  2xx 04-41
    "������EST         "  , //  2xx 04-42
    "TABST0 ����.        "  , //  2xx 04-43
    "TABST1 ����.        "  , //  2xx 04-44
    "DDS1/UDS1Spd Limm/s "  , //  2XX 04-45  DD1_Vlim  //Artemis speed limit, James, 20200220                          
    "DDS2/UDS2Spd Limm/s "  , //  2XX 04-46  DD2_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS3/UDS3Spd Limm/s "  , //  2XX 04-47  DD3_Vlim  //Artemis speed limit, James, 20200220                                     
    "DDS4/UDS4Spd Limm/s "  , //  2XX 04-48  DD4_Vlim  //Artemis speed limit, James, 20200220
    "DLC ������      "  , //  2XX 04-49   user page cahnge
                     
    "1�������� m   "  , //  2XX 04-30   1Floor Position H                                       
    "1�������� mm  "  , //  2XX 04-31   1Floor Position L                                       
    "2�������� m   "  , //  2XX 04-32   2Floor Position H                                       
    "2�������� mm  "  , //  2XX 04-33   2Floor Position L                                       
    "3�������� m   "  , //  2XX 04-34   3Floor Position H                                       
    "3�������� mm  "  , //  2XX 04-35   3Floor Position L                                       
    "4�������� m   "  , //  2XX 04-36   4Floor Position H                                       
    "4�������� mm  "  , //  2XX 04-37   4Floor Position L                                       
    "5�������� m   "  , //  2XX 04-38   5Floor Position H                                       
    "5�������� mm  "  , //  2XX 04-39   5Floor Position L                                       
    "6�������� m   "  , //  2XX 04-40   6Floor Position H                                       
    "6�������� mm  "  , //  2XX 04-41   6Floor Position L                                       
    "7�������� m   "  , //  2XX 04-42   7Floor Position H                                       
    "7�������� mm  "  , //  2XX 04-43   7Floor Position L                                       
    "8�������� m   "  , //  2XX 04-44   8Floor Position H                                       
    "8�������� mm  "  , //  2XX 04-45   8Floor Position L                                       
    "9�������� m   "  , //  2XX 04-46   9Floor Position H                                       
    "9�������� mm  "  , //  2XX 04-47   9Floor Position L                                       
    "10��������m   "  , //  2XX 04-48   10Floor Position H                                      
    "10��������mm  "  , //  2XX 04-49   10Floor Position L                                      
    "11��������m   "  , //  2XX 04-50   11Floor Position H                                      
    "11��������mm  "  , //  2XX 04-51   11Floor Position L                                      
    "12��������m   "  , //  2XX 04-52   12Floor Position H                                      
    "12��������mm  "  , //  2XX 04-53   12Floor Position L                                      
    "13��������m   "  , //  2XX 04-54   13Floor Position H                                      
    "13��������mm  "  , //  2XX 04-55   13Floor Position L                                      
    "14��������m   "  , //  2XX 04-56   14Floor Position H                                      
    "14��������mm  "  , //  2XX 04-57   14Floor Position L                                      
    "15��������m   "  , //  2XX 04-58   15Floor Position H                                      
    "15��������mm  "  , //  2XX 04-59   15Floor Position L                                      
    "16��������m   "  , //  2XX 04-60   16Floor Position H                                      
    "16��������mm  "  , //  2XX 04-61   16Floor Position L                                      
    "17��������m   "  , //  2XX 04-62   17Floor Position H                                      
    "17��������mm  "  , //  2XX 04-63   17Floor Position L                                      
    "18��������m   "  , //  2XX 04-64   18Floor Position H                                      
    "18��������mm  "  , //  2XX 04-65   18Floor Position L                                      
    "19��������m   "  , //  2XX 04-66   19Floor Position H                                      
    "19��������mm  "  , //  2XX 04-67   19Floor Position L                                      
    "20��������m   "  , //  2XX 04-68   20Floor Position H                                      
    "20��������mm  "  , //  2XX 04-69   20Floor Position L                                      
    "21��������m   "  , //  2XX 04-70   21Floor Position H                                      
    "21��������mm  "  , //  2XX 04-71   21Floor Position L                                      
    "22��������m   "  , //  2XX 04-72   22Floor Position H                                      
    "22��������mm  "  , //  2XX 04-73   22Floor Position L                                      
    "23��������m   "  , //  2XX 04-74   23Floor Position H                                      
    "23��������mm  "  , //  2XX 04-75   23Floor Position L                                      
    "24��������m   "  , //  2XX 04-76   24Floor Position H                                      
    "24��������mm  "  , //  2XX 04-77   24Floor Position L                                      
    "25��������m   "  , //  2XX 04-78   25Floor Position H                                      
    "25��������mm  "  , //  2XX 04-79   25Floor Position L                                     
   
/*---- GROUP 05----------------------------------------*/
/*  "12345678901234561234"	*/      	
	"���������� ��       "	,	//	255 05-00	Motor Auto-Tuning
	"�� �ް�     Amps"	,	//	256 05-01	Motor 1 rated Current           
	"���������� �� Kw  "	,	//	257 05-02	Motor 1 Rated Power             
	"�� �����ⰴ RPM "	,	//	258 05-03	Motor 1 Rated RPM               
	"���������ް�    "	,	//	259 05-04	Motor 1 pole No.                
	"���� ���� ��Amps"	,	//	260 05-05	Motor 1 No-Load Current         
	"Rs ��������   ohm "	,	//	261 05-06	Motor 1 Rs                      
	"Rr ��������   ohm "	,	//	262 05-07	Motor 1 Rr                      
	"Lm ��������    mH "	,	//	263 05-08	Motor 1 Lm                      
	"L��������    mH "	,	//	264 05-09	Motor 1 Lx                      
	"����. �� SVCsec "	,	//	265 05-10	Vector Voltage Filter	        
	"����������.SVCsec "	,	//	266 05-11	Vector Slip Filter	            
	"����.����.����    "	,	//	267 05-12	Torque Compensation Gain	    
	"����.����.������    "	,	//	268 05-13	Slip Compensation Gain	        
	"����������������%   "	,	//	269 05-14	Slip Deviation level	        
	"������������sec "	,	//	270 05-15	Slip Deviation Detect Time	    
	"�������������    "	,	//	271 05-16	Over Slip treatment	            
	"������.��������.    "	,	//	272 05-17	Coeff for hunting disable	    
	"�� ������     Mins"	,	//	273 05-18	Accumulative Motor Operation Min
	"�� ������     Days"	,	//	274 05-19	Accumulative Motor Operation Day
	"���߿���������%   "	,	//	275 05-20	Coreloss % of output Power	    
	"����������Mins"	,	//	276 05-21	Power On Min
	"����������. Days"	,	//	277 05-22	Power On Day
    "��������.���� %   "	,   //    2XX 05-23   Generator Slip Compensation percent    //[slip compensation function, Bernie, 2012/06/20]
	"����.������.����%   "	,	//	123 15-123  RESERVED
	
/*---- GROUP 06----------------------------------------*/
/*  "12345678901234561234"	*/
	"������.������ V   "	,	//	278  06-00	Low voltage level
	"�ؾ�������    "	,	//	279  06-01	Phase loss
	"������������%   "	,	//	280  06-02	OC stall during Accel
	"��������������%   "	,	//	281  06-03	OC stall during Decel
	"������������/��   "	,	//	282  06-04	Stall preventation Accel/Decel time selection
	"����������    "	,	//	283  06-05	Over-Torque 1 Selection
	"����������% %   "	,	//	284  06-06	Over-Torque 1 level
	"����.���������sec "	,	//	285  06-07	Over-Torque 1 Time
	"����������    "	,	//	286  06-08	Over-Torque 2 Selection	                     
	"����������  %   "	,	//	287  06-09	Over-Torque 2 level	                         
	"����.���������sec "	,	//	288  06-10	Over-Torque 2 Time	                         
	"������ ������   "	,	//	289  06-11	Current Limit
	"��.����.���� ��1    "	,	//	290  06-12	Thermal Relay 1 Selection
	"T ����.���� ��.1sec "	,	//	291  06-13	Thermal Relay 1 Time
	"�������� ������. C  "	,	//	292  06-14	OH Warning Level
	"��������������%   "	,	//	293  06-15	Stall preventation Limit Level
	"1������ ������    "	,	//	294  06-16	1st Fault Record
	"2������ ������    "	,	//	295  06-17	2nd Fault Record
	"3������ ������    "	,	//	296  06-18	3rd Fault Record
	"4������ ������    "	,	//	297  06-19	4th Fault Record
	"5������ ������    "	,	//	298  06-20	5th Fault Record
	"6������ ������    "	,	//	299  06-21	6th Fault Record
	"������ ����1    "	,	//	300  06-22	Fault Option 1
	"������ ����2    "	,	//	301  06-23	Fault Option 2
	"������ ����3    "	,	//	302  06-24	Fault Option 3
	"������ ����4    "	,	//	303  06-25	Fault Option 4
	"���� ����. PTC    "	,	//	304  06-26	PTC over Treatments	                         
	"������PTC     %   "	,	//	305  06-27	PTC Level
	"������ PTC      sec "	,	//	306  06-28	PTC Detect Filter time
	"������. ��    V   "	,	//	307  06-29	EPS voltage level
	"����ܰ����ؾ��      "	,	//	308  06-30	Fault Option Mode
	"�������в�����      "	,	//	309  06-31   Motor Phase Detection Mode, Add by DINO, 05/12/2009
	"����1-������Mins"	,	//	310  06-32	1st Fault Time(MIN)
	"����1-������Days"	,	//	311  06-33	1st Fault Time(DAY)
	"����2-������Mins"	,	//	312  06-34	2nd Fault Time(MIN)
	"����2-������Days"	,	//	313  06-35	2nd Fault Time(DAY)
	"����3-������Mins"	,	//	314  06-36	3rd Fault Time(MIN)
	"����3-������Days"	,	//	315  06-37	3rd Fault Time(DAY)
	"����4-������Mins"	,	//	316  06-38	4th Fault Time(MIN)
	"����4-������Days"	,	//	317  06-39	4th Fault Time(DAY)
	"����5-������Mins"	,	//	318  06-40	5th Fault Time(MIN)
	"����5-������Days"	,	//	319  06-41	5th Fault Time(DAY)
	"����6-������Mins"	,	//	320  06-42	6th Fault Time(MIN)
	"����6-������Days"	,	//	321  06-43	6th Fault Time(DAY)
    "��-�����������Hz  "  ,   //  322  06-44	EPS Frequency
    "����ܾ����    BIN "  ,	//  323  06-45  LV Option Mode
    "��������������      "  ,	//  324  06-46  EPS Option Mode
    "���ڽ�������sec "  ,   //  325  06-47  Generation Operation Detected Time
    "�������� ��   KVA "  ,   //  326  06-48  UPS Capacity (0.1KVA)
    "��������STO       "  ,   //  3xx   06-49      STO Lock selection     //[Safty function, Bernie] 
    "������ ����     "	,   //  356   06-50     Base Block Speed Search (oc,ov,occ.......)     //[Add auto restart after fault, Bernie, 06/06/12]
    "�� ��������.sec "  ,   //  356   06-51     Auto restart times after fault     
    "������.������ sec "  ,   //  356   06-52     Auto restart interval
    "��������.�� Hz  "	,	//	99  15-99   Fkey Record
    "��������.�� Hz  "	,	//	94 	 15-94   Fcmd Record"Out Freq. REC.  Hz  "	,	//	94 	15-94   Fcmd Record
    "������    Amps"	,	//	82   15-82	 Isum Record
    "������.����.��Hz  "	,	//	79   15-79	Fout Record
    "������.��   V   "	,	//	80   15-80	Vout Record
	"����.�����DC.���V   "	,   //  81   15-81	Dcbus Record  
	"������.��   KW  "	,	//	100 15-100  Power Record
	"��������.�� %   "	,	//	101 15-101  Torque Record
	"����.IGBT.��   C  "	,	//	83  15-83	IGBT Temperature Record    
	"����.����.��.���Hex "	,	//	102 15-102  MFI State Record
	"����.���ڲ����Hex "	,	//	103 15-103  MFO State Record
	"����.���������Hex "	,	//	104 15-104  Drive State Record
	"�� ���� UCMP  %   "  ,  //  3XX  06-65  Current limitation for UCMP function        //[UCMP function, Bernie, 2016/06/14]
	"����.������.        "  ,   //  3xx 06-66  Service time count                              //[Service time function, Bernie, 2017/03/14]
	"��������.         "  ,   //  3xx 06-67   Service time function Enable                 //[Service time function, Bernie, 2017/03/14]
    "����.��PF     deg "  ,   //  EPS Detect Current    
    "����.����.PF    deg "  ,   //  EPS Detect Current Ref
    "��������.����.    "  ,   //  EPS Detect direction
    "����.������۲��sec "  ,   //  EPS MO Off Time
    "����.������ڲ��sec "  ,   //  EPS MO Off Time
    "������ڽ�����۲H   "	,	//	Running direction count high						
    "������ڽ�����۽L   "	,	//	Running direction count low
    "����.����ݽ��� H   "	,	//	Temp running direction count high
    "����.����ݽ��� L   "	,	//   Temp running direction count low
    "�������ܸ�ܽ���    "	,	//	Temp running reset count
    "����ݲ��ܸ�ܽ���k   "	,	//	Running life
    "������ٲ������    "	,	//	Running function
    "��������.�� Hz  "  ,   //  Fcmd Record1"Out Freq. REC.  Hz  "
    "����.����DC.��V   "	,   //  Dcbus Record 1
    "������    Amps"  ,   //  Isum Record1
    "����.IGBT.��  C   "  ,   //  IGBT Temperature Record1
    "��������.�� Hz  "  ,   //  Fcmd Record2"Out Freq. REC.  Hz  "
    "����.����DC.��V   "	,   //  Dcbus Record2
    "������    Amps"  ,   //  Isum Record2
    "����.IGBT.��  C   "  ,   //  IGBT Temperature Record2
    "��������.�� Hz  "  ,   //  Fcmd Record3"Out Freq. REC.  Hz  "
    "����.����DC.��V   "	,   //  Dcbus Record3
    "������    Amps"  ,   //  Isum Record3
    "����.IGBT.��  C   "  ,   //  IGBT Temperature Record3
    "��������.�� Hz  "  ,   //  Fcmd Record4"Out Freq. REC.  Hz  "
    "����.����DC.��V   "	,   //  Dcbus Record4
    "������    Amps"  ,   //  Isum Record4
    "����.IGBT.��  C   "  ,   //  IGBT Temperature Record4
    "��������.�� Hz  "  ,   //  Fcmd Record5"Out Freq. REC.  Hz  "
    "����.��Udc.�� V   "	,   //  Dcbus Record5
    "������    Amps"  ,   //  Isum Record5
    "����.IGBT.��  C   "  ,   //  IGBT Temperature Record5
    
/*---- GROUP 07-----------------------------------------*/ 
/*  "12345678901234561234"	*/
	"���������ܺ����V   "	,	//	327   07-00	SW Braking Level
    "BK Voltage Hold V   "  ,   //	328   07-01	DB Enable Duty, add by dino 2007/02/12  //[RESERVED parameter, Bernie, 2012/05/21]
	"���DC-����.����   "	,	//	329   07-02	DCI Current Level      //[DCI Level when stop, Bernie, 05/21/2012]
	"����DC����C���� sec "	,	//	330   07-03	DCI Time at Start 
	"����DC��������  sec "	,	//	331   07-04	DCI Time at STOP
	"������DC������. Hz  "	,	//	332   07-05	DCI Freq. At start
	"����.����.����Ki    "	,	//	333   07-06	DCI KI
	"������������sec "	,	//	334   07-07	Gear wait time when acceleration
	"������������Hz  "	,	//	335   07-08	Gear wait frequency when acceleration
	"������������sec "	,	//	336   07-09	Gear wait time when deceleration
	"������������Hz  "	,	//	337   07-10	Gear wait frequency when deceleration
	"������������    "	,	//	338   07-11	Fan Control
	"������������%   "	,	//	339   07-12	TQC Reference from RS485
	"����������    "	,	//	340   07-13	Source of Torque Command
	"����.����.������%   "	,	//	341   07-14	Torque max. level
	"���� ���������sec "	,	//	342   07-15	Torque command filter
	"������������    "	,	//	343   07-16	Speed Limit selection
	"��ּ�ܾ�����%   "	,	//	344   07-17	Torque mode positive speed limit
	"��ּ�ܾ�����%   "	,	//	345   07-18	Torque mode negative speed limit
	"��������.����   "	,	//	346   07-19	Torque offset selection
	"�������� ������   "	,	//	347   07-20	Torque offset setting level
	"����.����.������%   "	,	//	348   07-21	Torque offset setting level High
	"����.����.������%   "	,	//	349   07-22	Torque offset setting level Middle
	"����.����.������%   "	,	//	350   07-23	Torque offset setting level Low
	"�������FWD��  %   "	,	//	351   07-24	FWD Motoring Tq Limit
	"�������FWD��%   "	,	//	352   07-25	FWD Regeneration Tq Limit
	"�������REV��  %   "	,	//	353   07-26	REV Motoring Tq Limit
	"�������REV��%   "	,	//	354   07-27	REV Regeneration Tq Limit
	"��߰���������    "	,	//	355   07-28	Emergency Stop & Forced Stop selection
	"���������������sec "	,	//	356   07-29   Torque Decrease Time
	"����.����DC����.%   "	,	//	356   07-30     STOP DC Inject Level    //[DCI Level when stop, Bernie, 05/21/2012]
	"BTT100             %"  ,   //  357 07-31   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect         "  ,   //  358 07-32   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Distance    ppr"  ,   //  359 07-33   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Detect Time sec"  ,   //  360 07-34   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Fail Torq      "  ,   //  361 07-35   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Min Torq       "  ,   //  362 07-36   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    "BTTx Max Torq       "  ,   //  362 07-37   //[JES Torq Detect Function, Special.Kung, 2022/09/01]
    
/*---- GROUP 08-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"������������        "	,	//	357   08-00	PMotor Auto-Tuning  
	"�� ����     Amps"	,	//	358   08-01	PMotor rated Current
	"���������� �� Kw  "	,	//	359   08-02	PMotor Rated Power  
	"�� �������� ��RPM "	,	//	360   08-03	PMotor Rated RPM    
	"����޿������ ��     "	,	//	361   08-04	PMotor pole No.     
	"Rs ����.����.   ohm "	,	//	362   08-05	PMotor Rs           
	"Ld ����.����.       "	,	//	363   08-06	PMotor Ld           
	"Lq ����.����.   mH  "	,	//	364   08-07	PMotor Lq           
	"�������� ʹ   Vrms"	,	//	365   08-08	PMotor Bemf coff	
	"Z-����. ����    deg "	,	//	366   08-09	PM Z-pulse offset angle, 0.1 degree, dino, 2007/01/03
	"�����������ӿ��    "	,	//	367   08-10	//ADDED BY DINO                                      
/*---- GROUP 09-----------------------------------------*/							
/*  "12345678901234561234"	*/
    "�������׿�      "	,	//	368   09-00	Comm Address                              
    "�������� COM    kbps"	,	//	369   09-01	Tranmission speed                         
    "����.����������   "	,	//	370   09-02	Comm fault Treatment                      
    "����-��COM    sec "	,	//	371   09-03	Comm Time out                             
    "�������� ����     "	,	//	372   09-04	Comm Protocol                             
    "�������� ������ ms  "	,	//	373   09-05	ASC remote Response Delay Time, 1=100us   
    "CAN_BUARD           "	,   //  3XX   09-06    CAN Bus Tranmission Baudrate      //[DLC, Bernie, 2014/10/06]
    "PDO_Tx_Time     ms  "	,   //  3XX   09-07    CAN PDO Handshaking Period  
    "CAN_Check_Time  ms  "	,   //  3XX   09-08    CAN Communiction Timeout
    "ID ������       "  ,   //  3XX   09-09    Elevator Control Identification Code
    "FHM ������        "  ,   //  3XX   09-10
    "DLC ������1       "  ,   //  3XX   09-11
    "DLC ������2       "  ,   //  3XX   09-12
    "DLC ������3       "  ,   //  3XX   09-13     
    "PDO TXTIME      ms  "  ,   //  3XX   09-14  CAN fail rate---aevin 6/12/2017  
/*---- GROUP 10------------------------------------------*/						
/*  "12345678901234561234"	*/
	"����������        "	,	//	374   10-00	Encoder TYPE                             
	"������������ppr "	,	//	375   10-01	Encoder pulses	                    
	"����������������    "	,	//	376   10-02	PG input setting	                
	"���������� ��   "	,	//	377   10-03	PG fbk fault treatment	            
	"�����־�������sec "	,	//	378   10-04	PG fbk Error Detection Time	        
	"���������������%   "	,	//	379   10-05	PG fbk overspeed detection level	
	"�������������sec "	,	//	380   10-06	Over speed Detection Time	        
	"����������������%   "	,	//	381   10-07	PG fbk speed deviation level	    
	"���������������sec "	,	//	382   10-08	Deviation Detect Time	            
	"��������.����     "	,	//	383   10-09	Operation at overspeed	            
	"������UVW       "  ,   //    384   10-10      Hall Input Types
	"0��-������ �� %   "	,	//	385   10-11	KP gain of ASR in Zero speed	
	"0��-������ Ki sec "	,	//	386   10-12	Ki gain of ASR in Zero speed	
	"������.����.��%   "	,	//	387   10-13	ASR P Gain 1	                
	"������.����.Kisec "	,	//	388   10-14	ASR I Gain 1	                
	"������.����.��%   "	,	//	389   10-15	ASR P Gain 2	                
	"������.����.Kisec "	,	//	390   10-16	ASR I Gain 2	                
	"��/2������.   Hz  "	,	//	391   10-17	ASR1/ASR2 switch freq	        
	"����.��Ľ sec "	,	//	392   10-18	Primary LowPass filter Gain 
	"������.���� ��%   "  ,	//	393   10-19     position control Kp Gain  
    "���������-�� Hz  "  ,   //    394   10-20     Low Spd band
    "���������-�� Hz  "  ,   //    395   10-21     High Spd band
	"����.���������sec "	,	//	396   10-22     Position control time
	"����.��Ľ   sec "	,	//	397   10-23     Position control LOW POSS FILTER
	"����������    "	,	//	398   10-24     Source of position control, add by dino, 06/30/2008
	"0��-��.���к� %   "	,	//	399   10-25	KP gain of ASR in Zero speed of Landing
	"0��-��.���кi sec "	,	//	400   10-26	Ki gain of ASR in Zero speed of Landing
	"���������  %   "	,	//	385   10-27	KP gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"��������i  sec "	,	//	386   10-28	Ki gain of ASR in Zero speed during Position Control, DINO, 05/16/2011
	"��������    "	,   //    4xx   10-29      PG Card Frequency Division Output   //[Modify PG Type Define, Bernie, 12/05/2011]
	"��������    "	,   //    4xx   10-30      PG Card Mode setting                      //[Modify PG Type Define, Bernie, 12/05/2011]
    "PG C+/C- ��       "  ,   //  110 15-110  RESERVED       //[change parameter to normal group, Bernie, 2014/02/14]
    "����.�������� m/s2"  ,   //    3XX  10-32   Over acc level setting        //[Over Acceleration protection function, Bernie, 2017/02/13]
    "����.���������sec "  ,   //    3XX  10-33   Over acc detect time          //[Over Acceleration protection function, Bernie, 2017/02/13]
    "����.��������   "  ,   //    3XX  10-34   Over acc detect rule setting  //[Over Acceleration protection function, Bernie, 2017/02/13]
    
/*---- GROUP 11-----------------------------------------*/						
/*  "12345678901234561234"	*/
	"������. c�������Hex "	,	//	401   11-00	system control bit0:auto, bit1:Jm tunning, bit2:Zero Servo	
    "����.��-�� �����m/s "  ,   //  402   11-01   Lift operation speed                                        
    "����. ��      mm  "  ,   //  403   11-02   SHEAVE diameter			ADDED BY SCOTTY                     
    "������������.     "  ,   //  404   11-03   Gear Ratio                                              
    "��������          "  ,   //  405   11-04   Suspension ratio	                                        
    "����.������   %   "  ,   //  406   11-05   inertia	percent			ADDED BY SCOTTY                     
	"��������-�� BWHz  "	,	//	407   11-06	Zero Speed Loop BandWidth	                                
	"������-�� BW  Hz  "	,	//	408   11-07	Speed Loop BandWidth1		                                
	"��������-�� BWHz  "	,	//	409   11-08	Speed Loop BandWidth2		                                
	"Kr ������.����  %   "	,	//	410   11-09	PDFFKr		                                                
	"����.����.������%   "	,	//	411   11-10	SPEED FFD GAIN			ADDED BY SCOTTY                     
	"����������. db  "	,	//	412   11-11	Netch filter deep(db)	                                    
	"����������. Hz  "	,	//	413   11-12	Netch filter frequency	                                    
	"Ľ������  sec "	,	//	414   11-13	Low Pass Filter for display	                                
	"��������.�� %   "	,	//	415   11-14	ACC Max current                                             
    "������������  m/s "  ,	//	416   11-15	max meter/sec	                                            
    "��������    Hex "  ,   //	417   11-16	Display address,add by dino 2007/03/08                      
    "����������        "  ,	//	418   11-17	Display data,   add by dino 2007/03/08                      
    "������.��         "  ,   //  419   11-18   Protect Bit	                                                
	"����.�����BW  Hz  "	,	//	420   11-19	Zero Speed Loop BandWidth of Landing
	"����ȸ          "	,	//	10    15-10	PWM MODE, 0=SVPWM+DPWM,1=SVPWM    PWM MODE, 0=SVPWM+DPWM,1=SVPWM	 //[move parameter to 11-20, Bernie, 2017/02/16]
    "LPF for LC01    sec "	,	//	422 11-21	Low Pass Filter for LC01 only APR_uwPGPosition  //[JES Torq Detect Function, Special.Kung, 2022/09/01]
#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    "Motor SPD RPM       "  ,   //  420   11-21 Lift_SPD_Hz Sibocom, Jason, 2019/12/31
#endif
    "Client_Mode         "  ,   //  422 11-22   //[Rational 332450 Artemis Warn Issue, Jerry.sk.Tseng 2023/03/31]

/*---- GROUP 12-----------------------------------------*/
/*  "12345678901234561234"	*/
    "UMAP_��           "  ,   //  421   12-00
    "UMAP_��           "  ,   //  422   12-01
    "UMAP_��           "  ,   //  423   12-02
    "UMAP_��           "  ,   //  424   12-33
    "UMAP_��           "  ,   //  425   12-04
    "UMAP_��           "  ,   //  426   12-05
    "UMAP_��           "  ,   //  427   12-06
    "UMAP_��           "  ,   //  428   12-07
    "UMAP_��           "  ,   //  429   12-08
    "UMAP_��           "  ,   //  430   12-09
    "UMAP_��0          "  ,   //  431   12-10
    "UMAP_��1          "  ,   //  432   12-11
    "UMAP_��2          "  ,   //  433   12-12
    "UMAP_��3          "  ,   //  434   12-13
    "UMAP_��4          "  ,   //  435   12-14
    "UMAP_��5          "  ,   //  436   12-15
    "UMAP_��6          "  ,   //  437   12-16
    "UMAP_��7          "  ,   //  438   12-17
    "UMAP_��8          "  ,   //  439   12-18
    "UMAP_��9          "  ,   //  440   12-19 
    "UMAP_��0          "  ,   //  441   12-20
    "UMAP_��1          "  ,   //  442   12-21
    "UMAP_��2          "  ,   //  443   12-22
    "UMAP_��3          "  ,   //  444   12-23
    "UMAP_��4          "  ,   //  445   12-24
    "UMAP_��5          "  ,   //  446   12-25
    "UMAP_��6          "  ,   //  447   12-26
    "UMAP_��7          "  ,   //  448   12-27
    "UMAP_��8          "  ,   //  449   12-28
    "UMAP_��9          "  ,   //  450   12-29
    "UMAP_��0          "  ,   //  451   12-30
    "UMAP_��1          "  ,   //  452   12-31
    "UMAP_��2          "  ,   //  423   12-02
    "UMAP_��3          "  ,   //  424   12-33
    "UMAP_��4          "  ,   //  425   12-04
    "UMAP_��5          "  ,   //  426   12-05
    "UMAP_��6          "  ,   //  427   12-06
    "UMAP_��7          "  ,   //  428   12-07
    "UMAP_��8          "  ,   //  429   12-08
    "UMAP_��9          "  ,   //  430   12-09
    "UMAP_��0          "  ,   //  421   12-00
    "UMAP_��1          "  ,   //  422   12-01
    "UMAP_��2          "  ,   //  423   12-02
    "UMAP_��3          "  ,   //  424   12-33
    "UMAP_��4          "  ,   //  425   12-04
    "UMAP_��5          "  ,   //  426   12-05
    "UMAP_��6          "  ,   //  427   12-06
    "UMAP_��7          "  ,   //  428   12-07
    "UMAP_��8          "  ,   //  429   12-08
    "UMAP_��9          "  ,   //  430   12-09
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
    "UMAP_����˵0        "  ,   //  453   13-00
    "UMAP_����˵1        "  ,   //  454   13-01
    "UMAP_����˵2        "  ,   //  455   13-02
    "UMAP_����˵3        "  ,   //  456   13-33
    "UMAP_����˵4        "  ,   //  457   13-04
    "UMAP_����˵5        "  ,   //  458   13-05
    "UMAP_����˵6        "  ,   //  459   13-06
    "UMAP_����˵7        "  ,   //  460   13-07
    "UMAP_����˵8        "  ,   //  461   13-08
    "UMAP_����˵9        "  ,   //  462   13-09
    "UMAP_����˵10       "  ,   //  463   13-10
    "UMAP_����˵11       "  ,   //  464   13-11
    "UMAP_����˵12       "  ,   //  465   13-12
    "UMAP_����˵13       "  ,   //  466   13-13
    "UMAP_����˵14       "  ,   //  467   13-14
    "UMAP_����˵15       "  ,   //  468   13-15
    "UMAP_����˵16       "  ,   //  469   13-16
    "UMAP_����˵17       "  ,   //  470   13-17
    "UMAP_����˵18       "  ,   //  471   13-18
    "UMAP_����˵19       "  ,   //  472   13-19
    "UMAP_����˵20       "  ,   //  473   13-20
    "UMAP_����˵21       "  ,   //  474   13-21
    "UMAP_����˵22       "  ,   //  475   13-22
    "UMAP_����˵23       "  ,   //  476   13-23
    "UMAP_����˵24       "  ,   //  477   13-24
    "UMAP_����˵25       "  ,   //  478   13-25
    "UMAP_����˵26       "  ,   //  479   13-26
    "UMAP_����˵27       "  ,   //  480   13-27
    "UMAP_����˵28       "  ,   //  481   13-28
    "UMAP_����˵29       "  ,   //  482   13-29
    "UMAP_����˵30       "  ,   //  483   13-30
    "UMAP_����˵31       "  ,   //  484   13-31
    "UMAP_����˵32       "  ,   //  455   13-02
    "UMAP_����˵33       "  ,   //  456   13-33
    "UMAP_����˵34       "  ,   //  457   13-04
    "UMAP_����˵35       "  ,   //  458   13-05
    "UMAP_����˵36       "  ,   //  459   13-06
    "UMAP_����˵37       "  ,   //  460   13-07
    "UMAP_����˵38       "  ,   //  461   13-08
    "UMAP_����˵39       "  ,   //  462   13-09
    "UMAP_����˵40       "  ,   //  453   13-00
    "UMAP_����˵41       "  ,   //  454   13-01
    "UMAP_����˵42       "  ,   //  455   13-02
    "UMAP_����˵43       "  ,   //  456   13-33
    "UMAP_����˵44       "  ,   //  457   13-04
    "UMAP_����˵45       "  ,   //  458   13-05
    "UMAP_����˵46       "  ,   //  459   13-06
    "UMAP_����˵47       "  ,   //  460   13-07
    "UMAP_����˵48       "  ,   //  461   13-08
    "UMAP_����˵49       "  ,   //  462   13-09
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
	"Id PWRSAVE ���� %   "	,	//	485   14-00	Ids Power Save Level
	"�ղ�.����       "	,	//	486   14-01	VF voltage mode selection
	"������������1     "	,	//	487   14-02	Constant Torque Selection
	"����������      "	,	//	488   14-03	Auto Accel/Decel
	"��.�������� T     "	,	//	489   14-04	Unit of Acc/Dec time
	"������������.     "	,	//	490   14-05	Power Save mode
	"�������������      "	,	//	491   14-06	Stop Methods
	"������.������       "	,	//	492   14-07	Reverse Operation
	"������1,����Hz  "	,	//	493   14-08	Skip Freq. Point 1 upper limit
	"������1,����Hz  "	,	//	494   14-09	Skip Freq. Point 1 lower limit
	"������2,����Hz  "	,	//	495   14-10	Skip Freq. Point 2 upper limit
	"������2,����Hz  "	,	//	496   14-11	Skip Freq. Point 2 lower limit
	"������3,����Hz  "	,	//	497   14-12	Skip Freq. Point 3 upper limit
	"������3,����Hz  "	,	//	498   14-13	Skip Freq. Point 3 lower limit
	"����������.2Hz  "	,	//	499   14-14	Motor Base Frequency 2
	"����.������.��.2V   "	,	//	500   14-15	Max Output Voltage 2
	"��.������ ��.2Hz  "	,	//	501   14-16	Mid Output Freq.2 1
	"��.������.1 ��.2V   "	,	//	502   14-17	Mid Output Voltage 2 1
	"��.������ ��.2Hz  "	,	//	503   14-18	Mid Output Freq.2 2
	"��.������.2 ��.2V   "	,	//	504   14-19	Mid Output Voltage 2 2
	"����������.2Hz  "	,	//	505   14-20	Min Output Freq. 2
	"��������. ��.2V   "	,	//	506   14-21	Min Output Voltage 2
	"������.Up/Down    "	,	//	507   14-22	up/down key mode
	"����.����.Up/Dwn    "	,	//	508   14-23	up/down key speed
	"������������      "	,	//	509   14-24	Counter Value Set (Complete)
	"������������      "	,	//	510   14-25	Counter Value Reach (Preset)
	"����������      "	,	//	511   14-26	LIMIT_SCALE      //[weak magnet, Sampo, 03/31/2011]
	"��������. ���� 9    "	,	//	512   14-27	Multi-Function Input 9
	"��������. ���� A    "	,	//	513   14-28	Multi-Function Input 10
	"��������. ���� B    "	,	//	514   14-29	Multi-Function Input 11
	"��������. ���� C    "	,	//	515   14-30	Multi-Function Input 12
	"��������. ���� D    "	,	//	516   14-31	Multi-Function Input 13
	"��������. ���� E    "	,	//	517   14-32	Multi-Function Input 14
	"��������. ���� B    "	,	//	518   14-33	External Terminal Run after Fault Reset
	"����ACI/AVI2      "	,	//	519   14-34	ACI change to AVI2
	"��������.AI         "	,	//	520   14-35	Addition Function of AI
	"������-����       "	,	//	521   14-36	Multi-Position Point 1
	"������-����       "	,	//	522   14-37	Multi-Position Point 2
	"������-����       "	,	//	523   14-38	Multi-Position Point 3
	"������-����       "	,	//	524   14-39	Multi-Position Point 4
	"������-����       "	,	//	525   14-40	Multi-Position Point 5
	"������-����       "	,	//	526   14-41	Multi-Position Point 6
	"������-����       "	,	//	527   14-42	Multi-Position Point 7
	"������-����       "	,	//	528   14-43	Multi-Position Point 8
	"������-����       "	,	//	529   14-44	Multi-Position Point 9
	"������-����0      "	,	//	530   14-45	Multi-Position Point 10
	"������-����1      "	,	//	531   14-46	Multi-Position Point 11
	"������-����2      "	,	//	532   14-47	Multi-Position Point 12
	"������-����3      "	,	//	533   14-48	Multi-Position Point 13
	"������-����4      "	,	//	534   14-49	Multi-Position Point 14
	"������-����5      "	,	//	535   14-50	Multi-Position Point 15
	"��������. 1-2     "	,	//	536   14-51	Motor Selection 1 or 2
	"����.��Y-D    Hz  "	,	//	537   14-52	Y-Delta Connected switching rpm
	"��������.Y-D        "	,	//	538   14-53	Y-Delta switched Enable
	"���� ����.2 Amps"	,	//	539   14-54	Motor 2 rated Current
	"�������� ����.2 Kw  "	,	//	540   14-55	Motor 2 Rated Power
	"����������.2RPM "	,	//	541   14-56	Motor 2 Rated RPM
	"����������.2    "	,	//	542   14-57	Motor 2 pole No.
	"������ ��.2 Amps"	,	//	543   14-58	Motor 2 No-Load Current
	"Rs ��������   ohm "	,	//	544   14-59	Motor 2 Rs
	"Rr  ��������2 ohm "	,	//	545   14-60	Motor 2 Rr
	"Lm ��������   mH  "	,	//	546   14-61	Motor 2 Lm
	"Lx ��������   mH  "	,	//	547   14-62	Motor 2 Lx
	"�������� Y-D        "	,	//	548   14-63	Y-Delta On delay time
	"������.��-��.�� V   "	,	//	549   14-64	OV stall level
	"��.����.���� ��2    "	,	//	550   14-65	Thermal Relay 2 Selection
	"��������.����2    "	,	//	551   14-66	Thermal Relay 2 Time
	"���� ������ U     "	,	//	552   14-67	Momentary Power Loss
	"����������U sec "	,	//	553   14-68	Max. allowable PL time
	"����.������ sec "	,	//	554   14-69	BB Time for speed serach
	"������п��������%   "	,	//	555   14-70	Current level for SPD serach
	"������������      "	,	//	556   14-71	bb treatment for oc, ov, bb
	"����������        "	,	//	557   14-72	Auto restart after fault
	"������������      "	,	//	558   14-73	Auto restart Speed serach method
	"DEB ������. SEL     "	,	//	559   14-74	Deceleration at Momertary Power loss 
	"DEB ��������    "	,	//	560   14-75	KEB Return Time
	"PID Fdb SEL         "	,	//	561   14-76	PID feedback selection	
	"����.P ������   "	,	//	562   14-77	P gain of PID	
	"����.I �������sec "	,	//	563   14-78	I gain of PID	
	"����.D ������   "	,	//	564   14-79	D gain of PID	
	"����������%   "	,	//	565   14-80	Upper bound for integral	
	"������������%   "	,	//	566   14-81	PID output Freq. Limit	
	"�������� ��   %   "	,	//	567   14-82	PID offset	
	"�������� ��   sec "	,	//	568   14-83	Derivative Filter Time Constant	
	"���������� �sec "	,	//	569   14-84	Feedback signal detection time	
	"����������    "	,	//	570   14-85	PID feedback loss	
	"���� ������ ����    "	,	//	571   14-86	Sleep Frequency	
	"���������� ��   "	,	//	572   14-87	Wake up Frequency	
	"������. ����.��   "	,	//	573   14-88	Sleep Time	
	"����. ������ ��   "	,	//	574   14-89	PID Deviation Level	
	"���������� ��   "	,	//	575   14-90	PID Deviation Time	
	"������  ��sec "	,	//	576   14-91	PID feedback filter	
	"�������� �������Hz  "	,	//	577   14-92	Main Frequency from communication	
	"���� �������� 1     "	,	//	578   14-93	Block Transfer 1	
	"���� �������� 2     "	,	//	579   14-94	Block Transfer 2	
	"���� �������� 3     "	,	//	580   14-95	Block Transfer 3
	"���� �������� 4     "	,	//	581   14-96	Block Transfer 4
	"���� �������� 5     "	,	//	582   14-97	Block Transfer 5
	"���� �������� 6     "	,	//	583   14-98	Block Transfer 6
	"���� �������� 7     "	,	//	584   14-99	Block Transfer 7
	"���� �������� 8     "	,	//	585   14-100 Block Transfer 8
	"���� �������� 9     "	,	//	586   14-101 Block Transfer 9
	"���� �������� 10    "	,	//	587   14-102 Block Transfer 10
	"WEAKLPF             "	,	//	588   14-103 WEAKLPF    //[weak magnet, Sampo, 03/31/2011]
	"WEAKTHETA           "	,	//	589   14-104 WEAKTHETA  //[weak magnet, Sampo, 03/31/2011]
	"OVER_SCALE          "	,	//	590   14-105 OVER_SCALE //[weak magnet, Sampo, 03/31/2011]
	"�����ݴ�      "	,	//	591   14-106 PG Position Control Point (Home)
	"PG Attained Home    "	,	//	592   14-107 Range for PG Position Attained
	"APR FFD Gain        "	,	//	593   14-108 Gain of APR feedforward
	"APR Decel Time  sec "	,	//	594   14-109 Decelerate time of APR
	"FMAX by VcomAPR Hz  "	,	//	595   14-110 FMax Target by Vcommand Position
	"������              "	,	//	596   14-111 Accel. Time for Position
	"������.������. A    "	,	//	597   14-112 PG Mechanical Gear A
	"��������.����   "	,	//	598   14-113 PG Mechanical Gear B
	"Jm ������ PU  PU  "	,	//	599   14-114 Interia of motor PU
	"M1IdsRef ������  %  "	,	//	600   14-115 Motor1 IdsRef Limit
	"M2IdsRef ������  %  "	,	//	601   14-116 Motor2 IdsRef Limit
	"�����в���sec "	,	//	602   14-117 Phase Loss Time
	"TH Inside ����.  C  "	,	//	603   14-118 Thermo inside Temp
	"ASR FeedForward     "	,	//	604   14-119 Speed feed forword
	"SlipGen.CompGain    "	,	//	605   14-120 SVC Slip Generation Compensation Gain //6a02j
	"PG-REF COM LPG      "	,	//	606   14-121 PG2 Command Low pass Filter Gain
	"TENSION OF TQCPGNt  "	,	//	607   14-122 Tension of Torque Control
	"������           "	,	//	608   14-123 Diameter of Material
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
	"CAN_����������      "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_BUARD           "	,   // [CAN Protocol for High Cap , Sampo,  2011/09/05]
	"CAN_������_���� sec "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
	"PDO_Tx_����   ms  "	,   // [CAN Protocol for High Cap, Bernie, 09/22/2011] 
    "���տ� COM1       "	,	//	368   09-00	Comm Address           //[move the keypad parameter to Group 14, Bernie, 11/08/2011 ]                      
	"�������� COM1   kbps"	,	//	369   09-01	Tranmission speed                         
	"����.������COM1     "	,	//	370   09-02	Comm fault Treatment                      
	"����-���COM1    sec "	,	//	371   09-03	Comm Time out                             
	"�������� COM1       "	,	//	372   09-04	Comm Protocol                             
	"����. ����COM1ms  "	,	//	373   09-05	ASC remote Response Delay Time, 1=100us 
    "���⾲0��         "	,	//	3XX   14-146    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "���⾲��          "	,	//	3XX   14-147    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "���⾲��          "	,	//	3XX   14-148    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "���⾲.5��        "	,	//	3XX   14-149    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "���⾲.2��        "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "����.��           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "����.��           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
    "����.��           "	,	//	3XX   14-150    The Count of Protect finction    //[Output Phase Loss 2, Sampo, 2015/05/21]
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
    "26�Ӧ�m ��     m   "  , //  2XX 04-80   26Floor Position H                                      
    "26�Ӧ�m �C     mm  "  , //  2XX 04-81   26Floor Position L                                      
    "27�Ӧ�m ��     m   "  , //  2XX 04-82   27Floor Position H                                      
    "27�Ӧ�m �C     mm  "  , //  2XX 04-83   27Floor Position L                                      
    "28�Ӧ�m ��     m   "  , //  2XX 04-84   28Floor Position H                                      
    "28�Ӧ�m �C     mm  "  , //  2XX 04-85   28Floor Position L                                      
    "29�Ӧ�m ��     m   "  , //  2XX 04-86   29Floor Position H                                      
    "29�Ӧ�m �C     mm  "  , //  2XX 04-87   29Floor Position L                                      
    "30�Ӧ�m ��     m   "  , //  2XX 04-88   30Floor Position H                                      
    "30�Ӧ�m �C     mm  "  , //  2XX 04-89   30Floor Position L                                      
    "31�Ӧ�m ��     m   "  , //  2XX 04-90   31Floor Position H                                      
    "31�Ӧ�m �C     mm  "  , //  2XX 04-91   31Floor Position L                                      
    "32�Ӧ�m ��     m   "  , //  2XX 04-92   32Floor Position H                                      
    "32�Ӧ�m �C     mm  "  , //  2XX 04-93   32Floor Position L                                      
    "33�Ӧ�m ��     m   "  , //  2XX 04-94   33Floor Position H                                      
    "33�Ӧ�m �C     mm  "  , //  2XX 04-95   33Floor Position L                                      
    "34�Ӧ�m ��     m   "  , //  2XX 04-96   34Floor Position H                                      
    "34�Ӧ�m �C     mm  "  , //  2XX 04-97   34Floor Position L                                      
    "35�Ӧ�m ��     m   "  , //  2XX 04-98   35Floor Position H                                      
    "35�Ӧ�m �C     mm  "  , //  2XX 04-99   35Floor Position L                                      
    "36�Ӧ�m ��     m   "  , //  2XX 04-100   36Floor Position H
    "36�Ӧ�m �C     mm  "  , //  2XX 04-101   36Floor Position L
    "37�Ӧ�m ��     m   "  , //  2XX 04-102   37Floor Position H
    "37�Ӧ�m �C     mm  "  , //  2XX 04-103   37Floor Position L
    "38�Ӧ�m ��     m   "  , //  2XX 04-104   38Floor Position H
    "38�Ӧ�m �C     mm  "  , //  2XX 04-105   38Floor Position L
    "39�Ӧ�m ��     m   "  , //  2XX 04-106   39Floor Position H
    "39�Ӧ�m �C     mm  "  , //  2XX 04-107   39Floor Position L
    "40�Ӧ�m ��     m   "  , //  2XX 04-108   40Floor Position H
    "40�Ӧ�m �C     mm  "  , //  2XX 04-109   40Floor Position L
    "41�Ӧ�m ��     m   "  , //  2XX 04-110   41Floor Position H
    "41�Ӧ�m �C     mm  "  , //  2XX 04-111   41Floor Position L
    "42�Ӧ�m ��     m   "  , //  2XX 04-112   42Floor Position H
    "42�Ӧ�m �C     mm  "  , //  2XX 04-113   42Floor Position L
    "43�Ӧ�m ��     m   "  , //  2XX 04-114   43Floor Position H
    "43�Ӧ�m �C     mm  "  , //  2XX 04-115   43Floor Position L
    "44�Ӧ�m ��     m   "  , //  2XX 04-116   44Floor Position H
    "44�Ӧ�m �C     mm  "  , //  2XX 04-117   44Floor Position L
    "45�Ӧ�m ��     m   "  , //  2XX 04-118   45Floor Position H
    "45�Ӧ�m �C     mm  "  , //  2XX 04-119   45Floor Position L
    "46�Ӧ�m ��     m   "  , //  2XX 04-120   46Floor Position H
    "46�Ӧ�m �C     mm  "  , //  2XX 04-121   46Floor Position L
    "47�Ӧ�m ��     m   "  , //  2XX 04-122   47Floor Position H
    "47�Ӧ�m �C     mm  "  , //  2XX 04-123   47Floor Position L
    "48�Ӧ�m ��     m   "  , //  2XX 04-124   48Floor Position H
    "48�Ӧ�m �C     mm  "  , //  2XX 04-125   48Floor Position L
    "49�Ӧ�m ��     m   "  , //  2XX 04-126   49Floor Position H
    "49�Ӧ�m �C     mm  "  , //  2XX 04-127   49Floor Position L
    "50�Ӧ�m ��     m   "  , //  2XX 04-128   50Floor Position H
    "50�Ӧ�m �C     mm  "  , //  2XX 04-129   50Floor Position L   
};

const string20 prinfo_tc_DLC2[DLC_TABLE] =
{               //[Modify DLC parameter, Bernie, 2016/01/22]
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"  */                                     
    "51�Ӧ�m ��     m   "  , //  2XX 04-80   26Floor Position H                                      
    "51�Ӧ�m �C     mm  "  , //  2XX 04-81   26Floor Position L                                      
    "52�Ӧ�m ��     m   "  , //  2XX 04-82   27Floor Position H                                      
    "52�Ӧ�m �C     mm  "  , //  2XX 04-83   27Floor Position L                                      
    "53�Ӧ�m ��     m   "  , //  2XX 04-84   28Floor Position H                                      
    "53�Ӧ�m �C     mm  "  , //  2XX 04-85   28Floor Position L                                      
    "54�Ӧ�m ��     m   "  , //  2XX 04-86   29Floor Position H                                      
    "54�Ӧ�m �C     mm  "  , //  2XX 04-87   29Floor Position L                                      
    "55�Ӧ�m ��     m   "  , //  2XX 04-88   30Floor Position H                                      
    "55�Ӧ�m �C     mm  "  , //  2XX 04-89   30Floor Position L                                      
    "56�Ӧ�m ��     m   "  , //  2XX 04-90   31Floor Position H                                      
    "56�Ӧ�m �C     mm  "  , //  2XX 04-91   31Floor Position L                                      
    "57�Ӧ�m ��     m   "  , //  2XX 04-92   32Floor Position H                                      
    "57�Ӧ�m �C     mm  "  , //  2XX 04-93   32Floor Position L                                      
    "58�Ӧ�m ��     m   "  , //  2XX 04-94   33Floor Position H                                      
    "58�Ӧ�m �C     mm  "  , //  2XX 04-95   33Floor Position L                                      
    "59�Ӧ�m ��     m   "  , //  2XX 04-96   34Floor Position H                                      
    "59�Ӧ�m �C     mm  "  , //  2XX 04-97   34Floor Position L                                      
    "60�Ӧ�m ��     m   "  , //  2XX 04-98   35Floor Position H                                      
    "60�Ӧ�m �C     mm  "  , //  2XX 04-99   35Floor Position L                                      
    "61�Ӧ�m ��     m   "  , //  2XX 04-100   36Floor Position H
    "61�Ӧ�m �C     mm  "  , //  2XX 04-101   36Floor Position L
    "62�Ӧ�m ��     m   "  , //  2XX 04-102   37Floor Position H
    "62�Ӧ�m �C     mm  "  , //  2XX 04-103   37Floor Position L
    "63�Ӧ�m ��     m   "  , //  2XX 04-104   38Floor Position H
    "63�Ӧ�m �C     mm  "  , //  2XX 04-105   38Floor Position L
    "64�Ӧ�m ��     m   "  , //  2XX 04-106   39Floor Position H
    "64�Ӧ�m �C     mm  "  , //  2XX 04-107   39Floor Position L
    "65�Ӧ�m ��     m   "  , //  2XX 04-108   40Floor Position H
    "65�Ӧ�m �C     mm  "  , //  2XX 04-109   40Floor Position L
    "66�Ӧ�m ��     m   "  , //  2XX 04-110   41Floor Position H
    "66�Ӧ�m �C     mm  "  , //  2XX 04-111   41Floor Position L
    "67�Ӧ�m ��     m   "  , //  2XX 04-112   42Floor Position H
    "67�Ӧ�m �C     mm  "  , //  2XX 04-113   42Floor Position L
    "68�Ӧ�m ��     m   "  , //  2XX 04-114   43Floor Position H
    "68�Ӧ�m �C     mm  "  , //  2XX 04-115   43Floor Position L
    "69�Ӧ�m ��     m   "  , //  2XX 04-116   44Floor Position H
    "69�Ӧ�m �C     mm  "  , //  2XX 04-117   44Floor Position L
    "70�Ӧ�m ��     m   "  , //  2XX 04-118   45Floor Position H
    "70�Ӧ�m �C     mm  "  , //  2XX 04-119   45Floor Position L
    "71�Ӧ�m ��     m   "  , //  2XX 04-120   46Floor Position H
    "71�Ӧ�m �C     mm  "  , //  2XX 04-121   46Floor Position L
    "72�Ӧ�m ��     m   "  , //  2XX 04-122   47Floor Position H
    "72�Ӧ�m �C     mm  "  , //  2XX 04-123   47Floor Position L
    "73�Ӧ�m ��     m   "  , //  2XX 04-124   48Floor Position H
    "73�Ӧ�m �C     mm  "  , //  2XX 04-125   48Floor Position L
    "74�Ӧ�m ��     m   "  , //  2XX 04-126   49Floor Position H
    "74�Ӧ�m �C     mm  "  , //  2XX 04-127   49Floor Position L
    "75�Ӧ�m ��     m   "  , //  2XX 04-128   50Floor Position H
    "75�Ӧ�m �C     mm  "  , //  2XX 04-129   50Floor Position L   
};

const string20 prinfo_tc_DLC3[DLC_TABLE] =
{
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"  */                                     
    "DDS1��m ��     m   "  ,                                    
    "DDS1��m �C     mm  "  ,                                      
    "DDS2��m ��     m   "  ,                                      
    "DDS2��m �C     mm  "  ,                                      
    "DDS3��m ��     m   "  ,                                      
    "DDS3��m �C     mm  "  ,                                    
    "DDS4��m ��     m   "  ,                                     
    "DDS4��m �C     mm  "  ,                                     
    "UDS1��m ��     m   "  ,                                     
    "UDS1��m �C     mm  "  ,                                
    "UDS2��m ��     m   "  ,                                   
    "UDS2��m �C     mm  "  ,                                     
    "UDS3��m ��     m   "  ,                                     
    "UDS3��m �C     mm  "  ,                                     
    "UDS4��m ��     m   "  ,                                   
    "UDS4��m �C     mm  "  ,                                    
    "�O�d                "  ,                                   
    "�O�d                "  ,                                    
    "�O�d                "  ,                                  
    "�O�d                "  ,                                   
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,
    "�O�d                "  ,  
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
  "26¥λ�� ��     m   "  , //  2XX 04-80   26Floor Position H                                      
  "26¥λ�� ��     mm  "  , //  2XX 04-81   26Floor Position L                                      
  "27¥λ�� ��     m   "  , //  2XX 04-82   27Floor Position H                                      
  "27¥λ�� ��     mm  "  , //  2XX 04-83   27Floor Position L                                      
  "28¥λ�� ��     m   "  , //  2XX 04-84   28Floor Position H                                      
  "28¥λ�� ��     mm  "  , //  2XX 04-85   28Floor Position L                                      
  "29¥λ�� ��     m   "  , //  2XX 04-86   29Floor Position H                                      
  "29¥λ�� ��     mm  "  , //  2XX 04-87   29Floor Position L                                      
  "30¥λ�� ��     m   "  , //  2XX 04-88   30Floor Position H                                      
  "30¥λ�� ��     mm  "  , //  2XX 04-89   30Floor Position L                                      
  "31¥λ�� ��     m   "  , //  2XX 04-90   31Floor Position H                                      
  "31¥λ�� ��     mm  "  , //  2XX 04-91   31Floor Position L                                      
  "32¥λ�� ��     m   "  , //  2XX 04-92   32Floor Position H                                      
  "32¥λ�� ��     mm  "  , //  2XX 04-93   32Floor Position L                                      
  "33¥λ�� ��     m   "  , //  2XX 04-94   33Floor Position H                                      
  "33¥λ�� ��     mm  "  , //  2XX 04-95   33Floor Position L                                      
  "34¥λ�� ��     m   "  , //  2XX 04-96   34Floor Position H                                      
  "34¥λ�� ��     mm  "  , //  2XX 04-97   34Floor Position L                                      
  "35¥λ�� ��     m   "  , //  2XX 04-98   35Floor Position H 
  "35¥λ�� ��     mm  "  , //  2XX 04-99   35Floor Position L 
  "36¥λ�� ��     m   "  , //  2XX 04-100   36Floor Position H
  "36¥λ�� ��     mm  "  , //  2XX 04-101   36Floor Position L
  "37¥λ�� ��     m   "  , //  2XX 04-102   37Floor Position H
  "37¥λ�� ��     mm  "  , //  2XX 04-103   37Floor Position L
  "38¥λ�� ��     m   "  , //  2XX 04-104   38Floor Position H
  "38¥λ�� ��     mm  "  , //  2XX 04-105   38Floor Position L
  "39¥λ�� ��     m   "  , //  2XX 04-106   39Floor Position H
  "39¥λ�� ��     mm  "  , //  2XX 04-107   39Floor Position L
  "40¥λ�� ��     m   "  , //  2XX 04-108   40Floor Position H
  "40¥λ�� ��     mm  "  , //  2XX 04-109   40Floor Position L
  "41¥λ�� ��     m   "  , //  2XX 04-110   41Floor Position H
  "41¥λ�� ��     mm  "  , //  2XX 04-111   41Floor Position L
  "42¥λ�� ��     m   "  , //  2XX 04-112   42Floor Position H
  "42¥λ�� ��     mm  "  , //  2XX 04-113   42Floor Position L
  "43¥λ�� ��     m   "  , //  2XX 04-114   43Floor Position H
  "43¥λ�� ��     mm  "  , //  2XX 04-115   43Floor Position L
  "44¥λ�� ��     m   "  , //  2XX 04-116   44Floor Position H
  "44¥λ�� ��     mm  "  , //  2XX 04-117   44Floor Position L
  "45¥λ�� ��     m   "  , //  2XX 04-118   45Floor Position H
  "45¥λ�� ��     mm  "  , //  2XX 04-119   45Floor Position L
  "46¥λ�� ��     m   "  , //  2XX 04-120   46Floor Position H
  "46¥λ�� ��     mm  "  , //  2XX 04-121   46Floor Position L
  "47¥λ�� ��     m   "  , //  2XX 04-122   47Floor Position H
  "47¥λ�� ��     mm  "  , //  2XX 04-123   47Floor Position L
  "48¥λ�� ��     m   "  , //  2XX 04-124   48Floor Position H
  "48¥λ�� ��     mm  "  , //  2XX 04-125   48Floor Position L
  "49¥λ�� ��     m   "  , //  2XX 04-126   49Floor Position H
  "49¥λ�� ��     mm  "  , //  2XX 04-127   49Floor Position L
  "50¥λ�� ��     m   "  , //  2XX 04-128   50Floor Position H
  "50¥λ�� ��     mm  "  , //  2XX 04-129   50Floor Position L

};

const string20 prinfo_sc_DLC2[DLC_TABLE] = {	
  /*---- GROUP 04---------------------------------------*/						
  /*  "12345678901234561234"	*/					
  "51¥λ�� ��     m   "  , //  2XX 04-80   26Floor Position H                                      
  "51¥λ�� ��     mm  "  , //  2XX 04-81   26Floor Position L                                      
  "52¥λ�� ��     m   "  , //  2XX 04-82   27Floor Position H                                      
  "52¥λ�� ��     mm  "  , //  2XX 04-83   27Floor Position L                                      
  "53¥λ�� ��     m   "  , //  2XX 04-84   28Floor Position H                                      
  "53¥λ�� ��     mm  "  , //  2XX 04-85   28Floor Position L                                      
  "54¥λ�� ��     m   "  , //  2XX 04-86   29Floor Position H                                      
  "54¥λ�� ��     mm  "  , //  2XX 04-87   29Floor Position L                                      
  "55¥λ�� ��     m   "  , //  2XX 04-88   30Floor Position H                                      
  "55¥λ�� ��     mm  "  , //  2XX 04-89   30Floor Position L                                      
  "56¥λ�� ��     m   "  , //  2XX 04-90   31Floor Position H                                      
  "56¥λ�� ��     mm  "  , //  2XX 04-91   31Floor Position L                                      
  "57¥λ�� ��     m   "  , //  2XX 04-92   32Floor Position H                                      
  "57¥λ�� ��     mm  "  , //  2XX 04-93   32Floor Position L                                      
  "58¥λ�� ��     m   "  , //  2XX 04-94   33Floor Position H                                      
  "58¥λ�� ��     mm  "  , //  2XX 04-95   33Floor Position L                                      
  "59¥λ�� ��     m   "  , //  2XX 04-96   34Floor Position H                                      
  "59¥λ�� ��     mm  "  , //  2XX 04-97   34Floor Position L                                      
  "60¥λ�� ��     m   "  , //  2XX 04-98   35Floor Position H 
  "60¥λ�� ��     mm  "  , //  2XX 04-99   35Floor Position L 
  "61¥λ�� ��     m   "  , //  2XX 04-100   36Floor Position H
  "61¥λ�� ��     mm  "  , //  2XX 04-101   36Floor Position L
  "62¥λ�� ��     m   "  , //  2XX 04-102   37Floor Position H
  "62¥λ�� ��     mm  "  , //  2XX 04-103   37Floor Position L
  "63¥λ�� ��     m   "  , //  2XX 04-104   38Floor Position H
  "63¥λ�� ��     mm  "  , //  2XX 04-105   38Floor Position L
  "64¥λ�� ��     m   "  , //  2XX 04-106   39Floor Position H
  "64¥λ�� ��     mm  "  , //  2XX 04-107   39Floor Position L
  "65¥λ�� ��     m   "  , //  2XX 04-108   40Floor Position H
  "65¥λ�� ��     mm  "  , //  2XX 04-109   40Floor Position L
  "66¥λ�� ��     m   "  , //  2XX 04-110   41Floor Position H
  "66¥λ�� ��     mm  "  , //  2XX 04-111   41Floor Position L
  "67¥λ�� ��     m   "  , //  2XX 04-112   42Floor Position H
  "67¥λ�� ��     mm  "  , //  2XX 04-113   42Floor Position L
  "68¥λ�� ��     m   "  , //  2XX 04-114   43Floor Position H
  "68¥λ�� ��     mm  "  , //  2XX 04-115   43Floor Position L
  "69¥λ�� ��     m   "  , //  2XX 04-116   44Floor Position H
  "69¥λ�� ��     mm  "  , //  2XX 04-117   44Floor Position L
  "70¥λ�� ��     m   "  , //  2XX 04-118   45Floor Position H
  "70¥λ�� ��     mm  "  , //  2XX 04-119   45Floor Position L
  "71¥λ�� ��     m   "  , //  2XX 04-120   46Floor Position H
  "71¥λ�� ��     mm  "  , //  2XX 04-121   46Floor Position L
  "72¥λ�� ��     m   "  , //  2XX 04-122   47Floor Position H
  "72¥λ�� ��     mm  "  , //  2XX 04-123   47Floor Position L
  "73¥λ�� ��     m   "  , //  2XX 04-124   48Floor Position H
  "73¥λ�� ��     mm  "  , //  2XX 04-125   48Floor Position L
  "74¥λ�� ��     m   "  , //  2XX 04-126   49Floor Position H
  "74¥λ�� ��     mm  "  , //  2XX 04-127   49Floor Position L
  "75¥λ�� ��     m   "  , //  2XX 04-128   50Floor Position H
  "75¥λ�� ��     mm  "  , //  2XX 04-129   50Floor Position L

};

// JINGDO
const string20 prinfo_sc_DLC3[DLC_TABLE] = {
/*---- GROUP 04---------------------------------------*/
/*  "12345678901234561234"	*/                                     
    "DDS1λ�� ��     m   "  ,                                    
    "DDS1λ�� ��     mm  "  ,                                      
    "DDS2λ�� ��     m   "  ,                                      
    "DDS2λ�� ��     mm  "  ,                                      
    "DDS3λ�� ��     m   "  ,                                      
    "DDS3λ�� ��     mm  "  ,                                    
    "DDS4λ�� ��     m   "  ,                                     
    "DDS4λ�� ��     mm  "  ,                                     
    "UDS1λ�� ��     m   "  ,                                     
    "UDS1λ�� ��     mm  "  ,                                
    "UDS2λ�� ��     m   "  ,                                   
    "UDS2λ�� ��     mm  "  ,                                     
    "UDS3λ�� ��     m   "  ,                                     
    "UDS3λ�� ��     mm  "  ,                                     
    "UDS4λ�� ��     m   "  ,                                   
    "UDS4λ�� ��     mm  "  ,                                    
    "����                "  ,                                   
    "����                "  ,                                    
    "����                "  ,                                  
    "����                "  ,                                   
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,
    "����                "  ,  
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
