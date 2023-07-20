//*****************************************************************/
//  @File Name: Keypad.H  
//  @Partner file: Keypad.C                                     
//  @Project: Wizard                                        
//  @Compiler: HEW V3.0 for H8/3687F                        
//  @Company: Delta Elec.INC CopyRight 2004                                  
//*****************************************************************/  
#ifdef _KeyPad_C
   #define KeyPad_EXT 
#else
   #define KeyPad_EXT extern
#endif


//****************************************************************
// @Defines
//****************************************************************
//Flash segment
#define FLASHSEG0      0x01
#define FLASHSEG1      0x02
#define FLASHSEG2      0x04
#define FLASHSEG3      0x08
#define FLASHSEG4      0x20 //0x10 //all state LED

#define FLASHSEG10     0x03
#define FLASHSEG210    0x07
#define FLASHSEG3210   0x0F
#define FLASHSEG43210  0x2F //0x1F

#define KEYDLYT         3

//Keypad information
#define KEYINEND          1
#define KEYINERR          2

//****************************************************************
// @Prototypes Of  Functions
//****************************************************************
KeyPad_EXT void reset(void);
KeyPad_EXT void SpdSearchAtStart(void);
KeyPad_EXT void run(void);
KeyPad_EXT void stop(void);
KeyPad_EXT void fwd_rev(void);
KeyPad_EXT UWORD Keypadscrollup_disp(UBYTE page);
KeyPad_EXT UWORD Keypadscrolldown_disp(UBYTE page);
KeyPad_EXT UWORD scrollup_data(UBYTE px, UWORD dx);
KeyPad_EXT UWORD scrolldown_data(UBYTE px, UWORD dx);
KeyPad_EXT void ShowDescription(string20 str);
KeyPad_EXT void ShowError(void);
KeyPad_EXT void ShowWarn(void);

KeyPad_EXT void Keypad_20xxH(UBYTE func,UWORD datac);
KeyPad_EXT void Keypad_2000H(UWORD datac);
KeyPad_EXT void Keypad_2002H(UWORD datac);
KeyPad_EXT void Keypad_2005H(UWORD datac);
KeyPad_EXT void Update_KeypadDisp(void);
KeyPad_EXT void Update_LCDescription(void);

KeyPad_EXT void ResetByKeypad(void);    //[Add auto restart after fault, Bernie, 06/06/12]

//****************************************************************
// @File Global Variables
//****************************************************************
KeyPad_EXT UBYTE	key_ubPageCnt;

KeyPad_EXT UWORD	KPDdot,
                    KPDmax,
                    KPDset;
                           
KeyPad_EXT SWORD	swInitPos;

KeyPad_EXT UWORD_UNION	  RUN_sequence;  // DINO, 06/22/2010