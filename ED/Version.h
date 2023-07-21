#define SIBO_ENABLE  0
#define Artemis_ENABLE  0
#define OFFICIAL_VERSION  0

#if SIBO_ENABLE //[Sibocom Function,Lyabryan,2020/6/15]
    #define SWVERS_H      1085  //[5=S for Sibocom]
    #define SWVERS_L         0
    #define DateCode      20195	/* 20150615 Mon. */
#else
    #if OFFICIAL_VERSION
        #define SWVERS_H      111
        #define SWVERS_L         1
        #define DateCode      23211	/* 20200803 Mon. */
    #else
        #define SWVERS_H      9111
        #define SWVERS_L         0
        #define DateCode      23271	/* 20200803 Mon. */
    #endif
#endif
/*============================================================================================
History:
Version    Date    - Notes
----------------------------------------------------------------------------------------------
12020-1 2005/12/02 - 1. Adding Low Pass Filter Gain
                     2. Adding rated current table of Variable Torque motor: VTispec[]
                     3. Please have more detail notes in history list
0.01.1 6291        - 1. Change the speed search method in FOCPG control, the speed command is
                        increasing to Fcmd.
    .2 6292        - 2. Enable POE interrupt at the End of once initialize (Power On), and                    
                        clear POE Flag
    .3 6293        - 3. The Factory parameter 12-06~12-09 would show writing data after writing
	                and can't change those parameters in PrHandel.c unless writing FFxxH
    .4         	   - 4. Change the VF table for motor1 & motor2, adding "vbase" & 
		        "fmin" global variable, and the "VFTableStruct" type define 
			    add "Fx2VmCompare" function
    .5 6303	   - 1. add power save function by Tunglong
----------------------------------------------------------------------------------------------        



=============================================================================================*/
