#include	 "modbus_dec.h"
#include	 "modbus_dev.h"
#include     "lib_access.h"


#ifndef NULL
#define  	NULL	 ( void * ) 0U
#endif



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Private Device Definition

//static	uint16_t mdbdec_67_read_private_regs( uint8_t  *cmd, uint16_t  len );
static	uint16_t mdbdec_74_get_mntr_table( uint8_t  *cmd, uint16_t  len );	// MNTR for VFDExplorer,Sean, 20141225
static	uint16_t mdbdec_75_set_mntr_channel( uint8_t  *cmd, uint16_t  len );
static	uint16_t mdbdec_71_set_mntr_start( uint8_t  *cmd, uint16_t  len );
static	uint16_t mdbdec_72_set_mntr_stop( uint8_t  *cmd, uint16_t  len );
static	uint16_t mdbdec_70_enter_vfd_Explorer( uint8_t  *cmd, uint16_t  len );//Aevin add 0x70 ----7/2/2015
static	uint16_t mdbdec_76_read_spd_cycle_chl( uint8_t  *cmd, uint16_t  len );//aevin add --11/25/2015


//const static struct	mdb_func_struct mdb_func_67 = {0x67 , 0 , mdbdec_67_read_private_regs};
const static struct	mdb_func_struct mdb_func_71 = {0x71 , 0 , mdbdec_71_set_mntr_start};	
const static struct	mdb_func_struct mdb_func_72 = {0x72 , 0 , mdbdec_72_set_mntr_stop};	
const static struct	mdb_func_struct mdb_func_74 = {0x74 , 0 , mdbdec_74_get_mntr_table};
const static struct	mdb_func_struct mdb_func_75 = {0x75 , 0 , mdbdec_75_set_mntr_channel};	
const static struct	mdb_func_struct mdb_func_70 = {0x70 , 0 , mdbdec_70_enter_vfd_Explorer};		//aevin add--7/2/2015
//aevin add  for new explorer read explorer 's speed and cycle , channel number--11/25/2015
const static struct	mdb_func_struct mdb_func_76 = {0x76 , 0 , mdbdec_76_read_spd_cycle_chl};		


//#define	CHN_MAX				4U	//old Explorer only support 4 channels 
#define	CHN_MAX				20U //new Explorer support max 20 channels

#define	MNTR_TABLE_SIZE		30U
#define	M00xx_SIZE	        53U	
#define	MNTR_START	0x0001

#pragma pack
struct	stMNTR_TABLE{
	uint8_t	ubRow;
	uint8_t uwAddr_Hi;
	uint8_t uwAddr_Low;
	uint8_t ubAddrPage;
	uint8_t	ubDesc[25];
	uint8_t	ubType;	//1=U8 ;2=I8 ;3=U16;4=I16;5=U32;6=I32 
};
#pragma unpack

extern uint16_t uwVfd_Explorer_Flag,uwVfd_Explorer_Count;//Aevin add--7/2/2015
extern uint8_t ubNew_VfdExplorerFlag;
//Type:		Type ID		|type		|
//			1			|UBYTE		|
//			2			|SBYTE		|
//			3			|UWORD		|
//			4			|SWORD		|
//			5			|ULONG		|
//			6			|SLONG		|
//			7			|FLOAT		|
const struct stMNTR_TABLE stMntrTable[M00xx_SIZE+2]={
//	Row,	AddrHi,	AddrLo,	AddrPage,	"0123456789012345678901234",	Type,	
	1U,		0x00,	0x00,	0x00,		"No Selection             ",	0U,		// ROW for checksum type. 0:LRC, 1:CRC	// MNTR LRC/CRC mode, Sean, 20141225
	1U,		0xa1,	0x02,	0x00,		"frq Cmd(fcmd)            ",	3U,
	2U,	    0xa1, 	0x76,	0x00,		"frq Cmd(fkey)            ",	3U,
	3U,		0xa1,	0x06,	0x00,		"Out Frq(fout)            ",	3U,
	4U,		0xa1,	0x7A,	0x00,		"DLC_swCurAcc             ",	4U,
	5U,		0xa1,	0x08,	0x00,		"DC-Bus(dcbusDC)          ",	3U,
	6U,		0xa1,	0x0c,	0x00,		"Out Volt(VcmdLLPF)       ",	4U,
	7U,		0xa1,	0x0e,	0x00,		"Out Cur(IrmsRe)          ",	3U,		
	8U,		0xa1, 	0x10,	0x00,		"Torgue Cmd(swTqRefPu)    ",	4U,		
	9U,	    0xa1, 	0x12,	0x00,		"AUI1(swAVICalib)         ",	4U,
	10U,	0xa1, 	0x14,	0x00,		"AUI2(swAUICalib)         ",	4U,
		
	11U,	0xa1,	0x16,	0x00,	    "mfi_status               ",	3U,	
	12U,	0xa1,	0x18,	0x00,		"mfo_status               ",	3U,
	13U,	0xa1,	0x1c,	0x00,		"TB1_slSpdCmdPu           ",	4U,
	14U,	0xa1,	0x20,	0x00,		"SpDt_slSpdFdbPu          ",	4U,
	15U,	0xa1,	0x22,	0x00,		"CUR_swIqseRefPu          ",	4U,		
	16U,	0xa1, 	0x24,	0x00,		"CUR_swIqseFdbPu          ",	4U,		
	17U,	0xa1, 	0x26,	0x00,		"CUR_swIdseRefPu          ",	4U,		
	18U,	0xa1, 	0x28,	0x00,		"CUR_swIdseFdbPu          ",	4U,		
	19U,	0xa1, 	0x2a,	0x00,		"TB1_uwBrkRunCnt          ",	3U,	
	20U,	0xa1,	0x2c,	0x00,		"TB1_uwBrkStopCnt		  ",	3U,

	21U,	0xa1,	0x2e,	0x00,		"TB1_uwMCRunCnt           ",	3U, 
	22U,	0xa1,	0x30,	0x00,		"TB1_uwMCStopCnt          ",	3U,
	23U,	0xa1,	0x32,	0x00,		"TB1_uwStarConRunCnt      ",	3U,
	24U,	0xa1,	0x34,	0x00,		"TB1_uwStarConStopCnt     ",	3U,
	25U,	0xa1,	0x36,	0x00,		"TB1_uwDCICnt             ",	3U,		
	26U,	0xa1, 	0x38,	0x00,		"uw_SCTEST8               ",	3U,
	27U,	0xa1, 	0x72,	0x00,		"zcal_uwMTU1cnt           ",	3U,//new add--aevin 7/24/2017
	28U,	0xa1, 	0x74,	0x00,		"hsd_uwAbsAngle           ",	3U,//new add--aevin 7/24/2017
	29U,	0xa1, 	0x40,	0x00,		"uwtest1                  ",	4U,	
	30U,	0xa1, 	0x42,	0x00,		"uwtest2                  ",	4U,		
	
	31U,	0xa1, 	0x44,	0x00,		"uwtest3                  ",	4U,	
	32U,	0xa1,	0x46,	0x00,		"uwtest4   		          ",	4U, 	
	33U,	0xa1,	0x48,	0x00,		"uwtest5                  ",	4U,
	34U,	0xa1,	0x4a,	0x00,		"uwtest6				  ",	4U, 	
	35U,	0xa1,	0x4c,	0x00,		"uwtest7				  ",	4U, 
	36U,	0xa1,	0x4e,	0x00,		"uwtest8				  ",	4U, 	
	37U,	0xa1,	0x50,	0x00,		"uwtest9				  ",	4U, 
	38U,	0xa1,	0x52,	0x00,		"uwtest10				  ",	4U, 	
	39U,	0xa1,	0x54,	0x00,		"uwtest11				  ",	4U, 
	40U,	0xa1,	0x56,	0x00,		"uwtest12				  ",	4U, 	
	
	41U,	0xa1,	0x58,	0x00,		"uwtest13				  ",	4U, 
	42U,	0xa1, 	0x5a,	0x00,		"uwtest14                 ",	4U,		
	43U,	0xa1, 	0x5c,	0x00,		"uwtest15                 ",	4U,	
	44U,	0xa1,	0x5e,	0x00,		"uwtest16  		          ",	4U, 	
	45U,	0xa1,	0x60,	0x00,		"uwtest17                 ",	4U, 
	46U,	0xa1,	0x62,	0x00,		"uwtest18				  ",	4U, 	
	47U,	0xa1,	0x64,	0x00,		"uwtest19				  ",	4U, 
	48U,	0xa1,	0x66,	0x00,		"uwtest20				  ",	4U, 	
	49U,	0xa1,	0x68,	0x00,		"uwtest21				  ",	4U, 
	50U,	0xa1,	0x6a,	0x00,		"uwtest22				  ",	4U, 	
	
	51U,	0xa1,	0x6c,	0x00,		"uwtest23				  ",	4U, 
	52U,	0xa1,	0x6e,	0x00,		"uwtest24				  ",	4U, 	
	53U,	0xa1,	0x70,	0x00,		"uwtest25				  ",	4U, 
 	0U,		0x00,	0xFF,	0x00,		"END OF MONITOR			  ",	0U,
};
/*
// NOTE: strcuture(stMntrTable) not mdb_dev_struct, false maappiing might occured..
const struct mdb_dev_struct stM00xx = {
	MODBUS_MNTR_REGISTER,	
	0,
	0x0000,				//	MODBUS ADDR
	M00xx_SIZE,			//  MAX LENGTH
	&stMntrTable[0],	//  MEMORY ADDRESS
	NULL,				//  READ FUNC
	NULL,				// 	WRITE FUNC
	NULL,				//  CHK FUNC
};
*/
uint16_t modbus_usr_init( void )
{
	uwVfd_Explorer_Flag = 0x0000;  //init this flag------Aevin---7/2/2015
	uwVfd_Explorer_Count = 0x0000; //init this count----Aevin---7/2/2015	
	ubNew_VfdExplorerFlag = 0x00;//init this,default type is using old vfd explorer--3/31/2016
	#if 0
    // Modbus Register
    if( mdb_dev_add( &stM00xx ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
	#endif
    // user definded function code
	if( mdb_func_code_add( &mdb_func_74 ) ){
		return 1U;
	}
	
	if( mdb_func_code_add( &mdb_func_75 ) ){
		return 1U;
	}	
	
	if( mdb_func_code_add( &mdb_func_71 ) ){
		return 1U;
	}	
	
	if( mdb_func_code_add( &mdb_func_72 ) ){
		return 1U;
	}			

//--------aevin add 0x70 function-----------------7/2/2015
	if( mdb_func_code_add( &mdb_func_70 ) ){
		return 1U;
	}

	/**/

	if( mdb_func_code_add( &mdb_func_76 ) ){//aevin add---11/25/2015
		return 1U;
	}
	return ( uint16_t )0U;

}





// Example
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// @brief	 Modbus Function Code 0x67 process (Read Internal Registers)
/// @param	 cmd   pointer to aommand, include funtion code, not include Slave ID
/// @param	 len   lenth of the command  		 
/// @return  Length of Modbus Reply, Reply message in cmd
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Function code 0x67
/*
static	uint16_t mdbdec_67_read_private_regs( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint16_t				 i;
	const struct mdb_dev_struct	*device;
	uint8_t  				 bytecount;

	// Command len too short 
	if( len < 5U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check quantity
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_REGISTER_READ_MAX ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Count byte count 
	bytecount = ( uint8_t )( quantity * 2U );

	// Check Address overflow
	addr	  = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the Modbus Device
	device = mdb_get_device( MODBUS_PRIVATE_REGISTER, addr, quantity );

	// cannot find any matched device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	addr	 -= device->addr;
	cmd[ 1 ]  = bytecount;

	// No Read Function 
	if( device->read == NULL )
	{
		for( i = 0U; i < quantity; i++ )
		{
			cmd[ 2U  + ( 2U * i ) ] = ( uint8_t )( device->dev[ addr + i ]>>8 );
			cmd[ 3U  + ( 2U * i ) ] = ( uint8_t )( device->dev[ addr + i ] & 0x00FFU );
		}
	}
	else
	{
		device->read( addr, quantity, &cmd[ 2U ] );
	}
	return ( ( uint16_t )bytecount + 2U );		
}
*/

/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x74 Process - Read Monitor Predefined Table
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  cmd[1]: row number
						  cmd[2,3]: address
						  cmd[4]: address page
						  cmd[5~29]: description
						  cmd[30]: type
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: 
@date					: 
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_74_get_mntr_table( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint8_t  				 bytecount;

	// Check: Command len too short 
	if( len < 5U )
		return modbus_exception( cmd, 0x03U );

	// set byte count 
	bytecount = ( uint8_t ) 31U;	// Func_Code:1, Row Num:1, Addr:2, Addr_Page:1, Desc:25, Type: 1

	// get target address: cmd[3] + cmd[4]
	addr	  = get_u16b( & cmd[ 3 ] );
	#if 0
	// get the Modbus Device
	device = mdb_get_device( MODBUS_MNTR_REGISTER, addr, 0 );

	// cannot find any matched device
	if( device == NULL )
		return modbus_exception( cmd, 0x02U );
	addr	 -= device->addr;
	#endif
//	if (addr < M00xx_SIZE){
	if (addr <= M00xx_SIZE){	
		memcpy(&cmd[1],&stMntrTable[addr],MNTR_TABLE_SIZE);
	}
	else{
//		memcpy(&cmd[1],&stMntrTable[M00xx_SIZE-1],MNTR_TABLE_SIZE);	//reply last line
		memcpy(&cmd[1],&stMntrTable[M00xx_SIZE+1],MNTR_TABLE_SIZE);	//reply last line
	}		
	
	return ( ( uint16_t )bytecount );
}

/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x75 Process - Write Monitor Channel Address
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  cmd[1]: chn number
						  cmd[2]: address page
						  cmd[3,4]: adress
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: 
@date					: 
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_75_set_mntr_channel( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint8_t  				 bytecount;
	uint8_t					 chn;
	extern	uint16_t		 Ch1Add;
	extern	uint16_t		 ChxAdd[20];
	extern	uint8_t			 ChCount;


	// Check: Command len too short 
	if( len < 5U )
		return modbus_exception( cmd, 0x03U );

	// set byte count 
	bytecount = ( uint8_t )len;	

	// get target channel: cmd[1]
	chn 	  = cmd[1];
	
	// cannot find any matched device
	if( chn > CHN_MAX )
	{
		return modbus_exception( cmd, 0x02U );
	}	
	
	// get data: MNTR address: cmd[3] + cmd[4]
	addr	  = get_u16b( & cmd[ 3 ] );	

#if 0
	ChnPtr = &Ch1Add;
	*(ChnPtr+chn-1) = addr;
#else
	ChxAdd[chn-1] = addr;
	if(ChCount < chn)
		ChCount = chn; 
#endif	
	return ( ( uint16_t )bytecount );
}

/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x71 Process - MNTR start
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: 
@date					: 
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_71_set_mntr_start( uint8_t  *cmd, uint16_t  len )
{
	extern uint16_t	Mntr_uwGenReg;	
	// Check: Command len too short 
	if( len < 5U )
		return modbus_exception( cmd, 0x03U );

	//-------------------to ressure ChCount is croorect--5/24/2016
	if(ChCount > 5 && ChCount <= 8)
		ChCount = 8;
	else if(ChCount > 9 && ChCount <= 20)
		ChCount = 20;
	else
		ChCount = 4;
	
	Mntr_uwGenReg |= MNTR_START;

	return ( ( uint16_t )len );
}
//-------------------0x70 cmd--------------------------Aevin add----7/2/2015
static	uint16_t mdbdec_70_enter_vfd_Explorer( uint8_t  *cmd, uint16_t  len )
{
	extern	uint8_t ChCount,ChCountTmp;//aevin add	
	uwVfd_Explorer_Flag = 0x0001;//if get 0x70 cmd from outside, then turn on ubVfd_Explorer_Flag--7/2/2015
	ChCount = 0;//init the Chcount--5/24/2016
	ChCountTmp = 0;//init the Chcount--5/24/2016
	return ( 0 );
//	return ( ( uint16_t )len );//0x70 no need to reply
}


//-------------------0x76 cmd--------------------------Aevin add----11/25/2015
static	uint16_t mdbdec_76_read_spd_cycle_chl( uint8_t  *cmd, uint16_t  len )
{
	// for read scope speed & cycle and channel number

	// Check: Command len too short 
	if( len < 5U )
		return modbus_exception( cmd, 0x03U );
	//send  baud rate to master
	cmd[1] = 0x10;	//usb 1.2M
	
	//send	the sample rate 
	cmd[2] = 0x10;	//100us 4channel
		

	//send	the channel number
	cmd[3] = 0x00;	//	
	cmd[4] = 0x02;	////  00 02 = 20 channel

	ubNew_VfdExplorerFlag = 1;//if use 0x76 , then use new explorer--3/31/2016

	return ( ( uint16_t )len );//0x70 no need to reply

}



/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x72 Process - MNTR stop
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: 
@date					: 
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_72_set_mntr_stop( uint8_t  *cmd, uint16_t  len )
{
	// Check: Command len too short 
	if( len < 5U )
		return modbus_exception( cmd, 0x03U );
	USB_vdIniTx(0);
	
	return ( ( uint16_t )len );
}










