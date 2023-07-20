//------------------ Parameter attribute -------------------------------------------------------
#define     V440    0x0001     // bit0:V440      V440 show twice value as the voltage class
#define     WRUN    0x0002     // bit1:RUNSET    1:the parameter can be set in RUN mode
#define	    JMP	    0x0004     // bit2:reseved parameter
#define     READ    0x0008     // bit3:read only
#define     RLD     0x0010     // bit4:reload default when 00-02 set d10

#define     DPB	    0x0020     // bit5:binary display
#define     DPH     0x0040     // bit6:hex display

#define     SIGN    0x0080     // bit7:Signed bit

#define     DOT0    0x0000     // b9b8=00 DOT0      display value has divide by    1
#define     DOT1    0x0100     // b9b8=01 DOT1      display value has divide by   10
#define     DOT2    0x0200     // b9b8=10 DOT2      display value has divide by  100
#define     DOT3    0x0300     // b9b8=11 DOT3      display value has divide by 1000

#define	    CHG	    0x0400     // bit10:Change Dot Location
#define     ITEM    0x2000     // bit13:have item
#define     S2EEP   0x4000     // bit14:unable to copy
#define	    HIDE    0x8000     // bit15:factory parameter