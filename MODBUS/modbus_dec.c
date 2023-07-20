/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
@Copyright (c)			: Delta Electronic Inc. 2011
@Module Name			: Modbus Decode 
@Objective				:
@Description			: Modbus decode function library
@Domain					: [Public/Private]
@Input					: Modbus Request and request length, not include Slave ID 
@Output					: Modbus Response and replay length, not include Slave ID

@Development History	:  
@author					:  Kevin 
@date					:  2011/07/08
@remarks				: 

Notes					:  1. Provide Modbus Function Code 0x01, 0x02, 0x03, 0x04, x05
							  0x06, 0x0f, 0x10, 0x17

						   2. Abbreviation :
							  mdb	 : Modbus
							  dec	 : Decode
							  func	 : Function 
							  dev	 : Device	 
							  reg	 : register 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
   
 

#include	 "modbus_dec.h"
#include     "lib_access.h"
#include	 "PR_MacroEQU.h"

//----------------------------------------------------------------------------------------------------------------------
// Definitions and Macros
#ifndef NULL
#define  	NULL	 ( void * ) 0U
#endif



//----------------------------------------------------------------------------------------------------------------------
// Gloabal Functions Declaration and Global Variables Definition
//	Gloabal Functions Declaration 
//	 Initial and Decode Function 
uint16_t				 modbus_device_init( void );
uint16_t				 modbus_decode( uint8_t  *cmd, uint8_t	len );

// API for user add new funcion code and device
uint8_t mdb_dev_add( const struct mdb_dev_struct * device_ctrl);
uint8_t mdb_func_code_add( const struct mdb_func_struct *func_ctrl );

// API for user defined function code usage
uint16_t		modbus_exception( uint8_t	*cmd, uint8_t  code );
const struct	mdb_dev_struct	*mdb_get_device( uint16_t  type, uint16_t  addr, uint16_t  quantity );


// Gloabal Variables Definition
// Devces
const struct	mdb_dev_struct	 * mdb_dev[ MODBUS_DEVICE_MAX ];
uint16_t				 mdb_dev_count = 0U;

// Function Call
const struct	mdb_func_struct  * mdb_func[ MODBUS_FUNCTION_MAX ];
uint16_t				 mdb_func_count = 0;


/*
************************************************************************************************************************
Objective				: Modbus Device Initialization
Description				: 
Input					: 
Output					: 0  		  Success
						  1  		  Failure	 -- MODBUS_DEVICE_MAX should be increased 
Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/  
extern struct mdb_dev_struct 	// modbus framework, Sean, 20141225	
	stPar_Grp_0, 	// add MODBUS_PARA_GROUP, Sean, 20141225
	stPar_Grp_1, 
	stPar_Grp_2,
	stPar_Grp_3,
	stPar_Grp_4,
	stPar_Grp_5,
	stPar_Grp_6,
	stPar_Grp_7,
	stPar_Grp_8,
	stPar_Grp_9,
	stPar_Grp_10,
	stPar_Grp_11,
	stPar_Grp_12,
	stPar_Grp_13,
	stPar_Grp_14,
	stPar_Grp_15,
	stPar_Grp_GpNo,
	stC20xx,			//aevin add ---6/30/2015
	stC21xx, 
	stC22xx, 
	stC23xx,
	stC31xx,
	stC32xx, 
	stC33xx,
	stC34xx,			//aevin add ---6/30/2015
	stC35xx,			
	stCFFxx,
	stC_MEMADDR;

extern uint8_t COM2Err;//add for getting err msg---7/31/2015

uint8_t WRITE_fORBIDDEN( uint32_t  addr, uint32_t  count, uint8_t  *ptr ){
	return 0 ;
}


//----------------------------------------------------------------------------------------------------------------------
// Local Functions Declaration and File Scope Variables Definition
// Local Functions Declaration
#if MDOBUS_FUNCTION_CODE_01_ENABLE == 1
static	uint16_t mdbdec_01_read_coils( uint8_t	*cmd, uint16_t	len );
const static struct	mdb_func_struct mdb_func_01 = {0x01 , 0 , mdbdec_01_read_coils};
#endif
#if MDOBUS_FUNCTION_CODE_02_ENABLE == 1
static	uint16_t mdbdec_02_read_discrete_inputs( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_02 = {0x02 , 0 , mdbdec_02_read_discrete_inputs};
#endif
#if MDOBUS_FUNCTION_CODE_03_ENABLE == 1
static	uint16_t mdbdec_03_read_regs( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_03 = {0x03 , 0 , mdbdec_03_read_regs};
#endif
#if MDOBUS_FUNCTION_CODE_04_ENABLE == 1
static	uint16_t mdbdec_04_read_input_regs( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_04 = {0x04 , 0 , mdbdec_04_read_input_regs};
#endif
#if MDOBUS_FUNCTION_CODE_05_ENABLE == 1
static	uint16_t mdbdec_05_write_coil( uint8_t	*cmd, uint16_t	len );
const static struct	mdb_func_struct mdb_func_05 = {0x05 , 0 , mdbdec_05_write_coil};
#endif
#if MDOBUS_FUNCTION_CODE_06_ENABLE == 1
static	uint16_t mdbdec_06_write_reg( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_06 = {0x06 , 0 , mdbdec_06_write_reg};
#endif
#if MDOBUS_FUNCTION_CODE_08_ENABLE == 1	// modbus framework, Sean, 20141225
static	uint16_t mdbdec_08_read_reg( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_08 = {0x08 , 0 , mdbdec_08_read_reg};
#endif
#if MDOBUS_FUNCTION_CODE_0F_ENABLE == 1
static	uint16_t mdbdec_0f_write_coils( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_0f = {0x0f , 0 , mdbdec_0f_write_coils};
#endif
#if MDOBUS_FUNCTION_CODE_10_ENABLE == 1
static	uint16_t mdbdec_10_write_regs( uint8_t	*cmd, uint16_t	len );
const static struct	mdb_func_struct mdb_func_10 = {0x10 , 0 , mdbdec_10_write_regs};
#endif
#if MDOBUS_FUNCTION_CODE_17_ENABLE == 1
static	uint16_t mdbdec_17_read_write_regs( uint8_t  *cmd, uint16_t  len );
const static struct	mdb_func_struct mdb_func_17 = {0x17 , 0 , mdbdec_17_read_write_regs};
#endif

/*
************************************************************************************************************************
Objective				: Initial the modbus decode system, include Default function Call and 
						  User Devices 
Description				: 
Input					: void 
Output					: 0    Success
						  1    Failure 

Development History 	:
@author					: Kevin Tseng
@date					: 2010/07/08
@remarks				: 1. User can add your Modbus devices in this function.
						  2. Call this function before decoding any Modbus Command.   
						  3. You should edit this function for your Project. 

************************************************************************************************************************
*/
uint16_t modbus_decode_init( void )
{

	//------------------------------------------------------------------
	// initial Function Code
	mdb_func_count = ( uint16_t )0U;

#if MDOBUS_FUNCTION_CODE_01_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_01 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_02_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_02 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_03_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_03 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_04_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_04 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_05_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_05 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_06_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_06 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_08_ENABLE == 1	// modbus framework, Sean, 20141225
	if( mdb_func_code_add( &mdb_func_08 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_0F_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_0f ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_10_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_10 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif

#if MDOBUS_FUNCTION_CODE_17_ENABLE == 1
	if( mdb_func_code_add( &mdb_func_17 ) != ( uint16_t )0U )
	{
		return ( uint16_t )1U;
	}
#endif


	//------------------------------------------------------------
	// initial device 
	mdb_dev_count = ( uint16_t )0U;

	return ( uint16_t )0U;
}


/*
************************************************************************************************************************
Objective				: add a Modbus Device to the Modbus decoder system
Description  			: 
Input					: device_ctrl    The control information of this device -- see example in modbus_dev.c 
Output					: 0  		  Success
						  1  		  Failure	 -- MODBUS_DEVICE_MAX should be increased 

Development History  	: 
@author  				: Kevin, Simon 
@date					: 2011/07/08
@remarks				: 

************************************************************************************************************************
*/
uint8_t mdb_dev_add(const struct mdb_dev_struct * device_ctrl)
{
	uint16_t result = ( uint16_t )0U;
    uint16_t i;
    for( i = 0; i < mdb_dev_count; i++ )
    {
         if( mdb_dev[i]->type == device_ctrl->type ) 
         {
             if( mdb_dev[i]->type == device_ctrl->type ) 
             {         	
                 if( !((mdb_dev[i]->addr >(device_ctrl->addr + device_ctrl->max)) || 
                       ((mdb_dev[i]->addr + mdb_dev[i]->max) < device_ctrl->addr)) ) 
                 {
                     result = 1U;
                     break;
                 }
             }
         }
    }

    if (result == 0U) 
    {
    	if( mdb_dev_count < MODBUS_DEVICE_MAX )
    	{
    		mdb_dev[ mdb_dev_count ] = device_ctrl;
    		mdb_dev_count++;
    		result = ( uint16_t )0U;
    	}
    	else
    	{
    		result = ( uint16_t )1U;
    	}
    }
	return result;
}
/*
************************************************************************************************************************
Objective				: add a Modbus Function Code support to the Modbus decoder system
Description  			: 
Input					: code		  Modbus function Code
						  func		  Pointer to the function Code process function
Output					: 0  		  Success
						  1  		  Failure	 -- MODBUS_FUNCTION_MAX should be increased 

Development History  	: 
@author  				: Kevin, Simon 
@date					: 2011/07/08
@remarks				: 

************************************************************************************************************************
*/
uint8_t mdb_func_code_add( const struct mdb_func_struct *func_ctrl )
{
	uint16_t result = ( uint16_t )0U;
    uint16_t i;
    
    for( i = 0; i< mdb_func_count; i++) 
    {
         if( mdb_func[i]->code == func_ctrl->code ) 
         {
             result = 1U;
             break;
         }        
    }
    
    if ( result == 0 ){
    	if( mdb_func_count < MODBUS_FUNCTION_MAX )
    	{
    		mdb_func[ mdb_func_count ] =  func_ctrl;
    		mdb_func_count++;
    		result = ( uint16_t )0U;
    	}
    	else
    	{
    		result = ( uint16_t )1U;
    	}
    }
	return result;
}






//----------------------------------------------------------------------------------------------------------------------
// Modbus Decode Function

#if MDOBUS_FUNCTION_CODE_01_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x01 Process - Read Coils
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_01_read_coils( uint8_t	*cmd, uint16_t	len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint16_t				 i;
	uint8_t  				 bytecount;
	const struct	mdb_dev_struct	*device;


	// Command len too short 
	if( len < 5U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check Quantity 
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_BIT_READ_MAX ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Count Byte Count
	bytecount = ( uint8_t )( quantity / 8U );
	if( ( quantity % 8U ) != 0U )
	{
		bytecount++;
	}

	// Check Address and Quantity
	addr = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the Modbus Device 
	device = mdb_get_device( MODBUS_INTERNAL_BIT, addr, quantity );

	// Cannot find any matched Device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	addr	 -= device->addr;
	cmd[ 1 ]  = bytecount;

	for( i = 0U; i < bytecount; i++ )
	{
		cmd[ 2U  + i ] = 0U;
	}

	// No read function
	if( device->read == NULL )
	{
		for( i = 0U; i < quantity; i++ )
		{
		    set_bit( &cmd[ 2 ], i, ( uint16_t )get_bit( (uint8_t *)&device->dev[0], ( addr + i ) ) );
		}
	}
	else
	{
		device->read( addr, quantity, &cmd[ 2U ] );
	}
	return ( ( uint16_t )bytecount + 2U );
}
#endif


#if MDOBUS_FUNCTION_CODE_02_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x02 Process - Read Discrete Inputs
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_02_read_discrete_inputs( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint16_t				 i;
	const struct	mdb_dev_struct	*device;
	uint8_t  				 bytecount;

	// Command len too short 
	if( len < 5U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check Quantity
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_BIT_READ_MAX ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Count Byte Count 
	bytecount = ( uint8_t )( ( quantity ) / 8U );
	if( ( quantity % 8U ) != 0U )
	{
		bytecount++;
	}

	// Check addr and Quantity	  
	addr = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the Modbus Device 
	device = mdb_get_device( MODUBS_INPUT_BIT, addr, quantity );

	// cannot find any matched device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	addr	 -= device->addr;
	cmd[ 1 ]  = bytecount;
	for( i = 0U; i < bytecount; i++ )
	{
		cmd[ 2U  + i ] = 0U;
	}

	// No read function  
	if( device->read == NULL )
	{
		for( i = 0U; i < quantity; i++ )
		{
		    set_bit( &cmd[ 2 ], i, ( uint16_t )get_bit( (uint8_t *)&device->dev[0], ( addr + i ) ) );
		}
	}
	else
	{
		device->read( addr, quantity, &cmd[ 2U ] );
	}
	return ( ( uint16_t )bytecount + 2U );
}
#endif


#if MDOBUS_FUNCTION_CODE_03_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x03 Process - Read Registers
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_03_read_regs( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	const struct	mdb_dev_struct	*device;
	uint8_t  				 bytecount;
	
	extern uint8_t GROUPTmp;
	//extern struct mdb_dev_struct stPar_Grp_GpNo;

	// Command len too short 
	if( len < 5U )
	{
		COM2Err = PC_CE03;//7/31/2015
		return modbus_exception( cmd, 0x03U );
	}

	// Check quantity
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_REGISTER_READ_MAX ) )
	{
		COM2Err = PC_CE03;//7/31/2015
		return modbus_exception( cmd, 0x03U );
	}

	// Count byte count 
	bytecount = ( uint8_t )( quantity * 2U );

	// Check Address overflow
	addr	  = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		COM2Err = PC_CE02;//7/31/2015
		return modbus_exception( cmd, 0x02U );
	}
	//-----此為特殊位置 GNxx 因此只能寫例外
	if(((addr&0xff00)>>8) == (GROUPTmp+1)){
		device = &stPar_Grp_GpNo;
		addr = addr&0x00ff;
	}
	//例外  // Communication Memory Address >= 80xxH + SFR(0300~03FF)---7/6/2015
	else if( (((addr&0xff00)>>8)<=0xF3)&&(((addr&0xff00)>>8)>=0xC0)){
		device = &stC_MEMADDR;
	}
	else{
		// Get the Modbus Device: parameter device
		device = mdb_get_device( MODBUS_PARA_GROUP, addr, quantity );	// add MODBUS_PARA_GROUP, Sean, 20141225
	
		// Get the Modbus Device: common device
		if( device == NULL ){
			device = mdb_get_device( MODBUS_INTERNAL_REGISTER, addr, quantity );
			addr	 -= device->addr;
			
			//---------to detect to prrameter's number exceed or not------7/3/201			
			if(addr > device->paranumber)//---">=" 改為 ">" 讓他支援34 FF -----7/6/2015
				return modbus_exception( cmd, 0x0aU );
			
		}
		// cannot find any matched device
		if( device == NULL ){
			COM2Err = PC_CE02;//7/31/2015
			return modbus_exception( cmd, 0x02U );
		}

	}
	cmd[ 1 ]  = bytecount;

	// No Read Function 
	if( device->read == NULL )
	{
        u16u8bcpy(&cmd[2], &device->dev[addr], quantity);
	}
	else
	{
		device->read( addr, quantity, &cmd[ 2U ] );
	}	
	
	return ( ( uint16_t )bytecount + 2U );

	
}
#endif


#if MDOBUS_FUNCTION_CODE_04_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x04 Process - Read Input Registers
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_04_read_input_regs( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint16_t				 i;
	const struct	mdb_dev_struct	*device;
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

	// Count Byte Count 
	bytecount = ( uint8_t )( quantity * 2U );

	// Check Address Overflow 
	addr	  = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the Modbus Device 
	device = mdb_get_device( MODBUS_INPUT_REGISTER, addr, quantity );

	// cannot find any matched device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}


	addr	 -= device->addr;
	cmd[ 1 ]  = bytecount;
	// No read function  
	if( device->read == NULL )
	{
        u16u8bcpy(&cmd[2], &device->dev[addr], quantity);
	}
	else
	{
		device->read( addr, quantity, &cmd[ 2U ] );
	}
	return ( ( uint16_t )bytecount + 2U );
}
#endif


#if MDOBUS_FUNCTION_CODE_05_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x05 Process - Write Signal Coil
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_05_write_coil( uint8_t	*cmd, uint16_t	len )
{
	uint16_t				 addr;
	uint16_t				 value;
	const struct	mdb_dev_struct	*device;

	// Check the Command Length 
	if( len < 5U )
	{
		return modbus_exception( cmd, 0x03U );
	}
	// Check the Falue is Vaild
	value = get_u16b( & cmd[ 3 ] );
	if( ( value != 0xFF00U ) && ( value != 0x0000U ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Get the Address
	addr   = get_u16b( & cmd[ 1 ] );

	// Get the Modbus Device 
	device = mdb_get_device( MODBUS_INTERNAL_BIT, addr, 1U );

	// Cannot find any matched device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	addr -= device->addr;

	// With Check Funciton 
	if( device->check != NULL )
	{
		if( device->check( addr, 1U, &cmd[ 3 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x03U );
		}
	}

	// No write Function 
	if( device->write == NULL )
	{
	    // Write Bit
	    set_bit( (uint8_t *)&device->dev[ 0 ], addr, ( uint16_t )get_bit( &cmd[ 3 ], 0U ) );
	}
	else
	{
		if( device->write( addr, 1U, &cmd[ 3 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x04U );
		}
	}
	return ( 5U );
}
#endif


#if MDOBUS_FUNCTION_CODE_06_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x06 Process - Write Signal Register
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
uint16_t mdbdec_06_write_reg( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 value;
	const struct	mdb_dev_struct	*device;

	// Check the command length  
	if( len < 5U )
	{
		COM2Err = PC_CE03;//7/31/2015
		return modbus_exception( cmd, 0x03U );
	}

	// Read value and Check 
	value  = get_u16b( & cmd[ 3 ] );
	// Never go into here -> so, disable it
	//if (value > 0xFFFFU && value < 0x0000U){
	//	  // Exception code 03
	//	  return modbus_exception(cmd, 0x03);
	//}

	addr   = get_u16b( & cmd[ 1 ] );

	// Get the Modbus Device: parameter device
	device = mdb_get_device( MODBUS_PARA_GROUP, addr, 1U );	// add MODBUS_PARA_GROUP, Sean, 20141225
	
	// Get the Modbus Device: common device
	if( device == NULL ){
		device = mdb_get_device( MODBUS_INTERNAL_REGISTER, addr, 1U );
	}
	
	// cannot find any matched device
	if( device == NULL ){
		COM2Err = PC_CE02;//7/31/2015
		return modbus_exception( cmd, 0x02U );
	}
	
	//addr	 -= device->addr;		//Aevin mark and move down---7/2/2015
	
	// With Check Function  
	if( device->check != NULL )
	{
		if( device->check( addr, 1U, &cmd[ 3 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x03U );
		}
	}	
	//if this dev is not allow to write , return fail----7/6/2015
	if(device->write == WRITE_fORBIDDEN){
		// Write data fail 
		COM2Err = PC_CE04;//7/31/2015
		return modbus_exception( cmd, 0x01U );
	}
	else{
		// No write function  , so use the default write function
		if( device->write == NULL )
		{
			addr	 -= device->addr;	//Aevin move to here---7/2/2015
			// Default Write Bit
			device->dev[ addr ] = value;
		}
		else
		{
			if( device->write( addr, 1U, &cmd[ 3 ] ) != 0U )
			{
				// Write data fail 
				COM2Err = PC_CE04;//7/31/2015
				return modbus_exception( cmd, 0x04U );
			}
		}	
	}
	return ( 5U );
}
#endif

#if MDOBUS_FUNCTION_CODE_08_ENABLE == 1	// modbus framework, Sean, 20141225
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x08 Process - Echo
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
static	uint16_t mdbdec_08_read_reg( uint8_t  *cmd, uint16_t  len )
{
	// Command len too short 
	if( len < 1U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	return ( ( uint16_t )len );
}
#endif



#if MDOBUS_FUNCTION_CODE_0F_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x0F Process - Write Coils
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_0f_write_coils( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint8_t  				 bytecount;
	uint16_t				 i;
	const struct	mdb_dev_struct	*device;

	// Check the command length  
	if( len < 7U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the Quantity
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_BIT_WRITE_MAX ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Count the Byte Count and Check 
	bytecount = ( uint8_t )( quantity / 8U );
	if( ( quantity % 8U ) != 0U )
	{
		bytecount++;
	}
	if( bytecount != cmd[ 5 ] )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the Comman dLength
	if( len < ( ( uint16_t )bytecount + 6U ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the address overflow
	addr = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the Modbus device 
	device = mdb_get_device( MODBUS_INTERNAL_BIT, addr, quantity );

	// Cannot find any matched device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	addr -= device->addr;

	// with check function  
	if( device->check != NULL )
	{
		if( device->check( addr, quantity, &cmd[ 6 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x03U );
		}
	}

	// Without write function  
	if( device->write == NULL )
	{
		// Default Write Registers
		for( i = 0U; i < quantity; i++ )
		{
		    set_bit( (uint8_t *)&device->dev[ 0 ], addr + i, ( uint16_t )get_bit( &cmd[ 6 ], i ) );
		}
	}
	else
	{
		if( device->write( addr, quantity, &cmd[ 6 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x04U );
		}
	}
	return ( 5U );
}
#endif


#if MDOBUS_FUNCTION_CODE_10_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x10 Process - Write Registers
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_10_write_regs( uint8_t	*cmd, uint16_t	len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint8_t  				 bytecount;
	const struct	mdb_dev_struct	*device;

	// Check the command length  
	if( len < 8U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check quantity
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_REGISTER_WRITE_MAX ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Count and check the Byte Count
	bytecount = ( uint8_t )( quantity * 2U );
	if( bytecount != cmd[ 5 ] )
	{
		return modbus_exception( cmd, 0x03U );
	}
	if( len < ( ( uint16_t )bytecount + 6U ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the address overflow
	addr = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the Modbus Device 
	device = mdb_get_device( MODBUS_INTERNAL_REGISTER, addr, quantity );

	// Cannot find any matched device
	if( device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	addr -= device->addr;

	// With Check function  
	if( device->check != NULL )
	{
		if( device->check( addr, quantity, &cmd[ 6 ] ) != 0U )
		{
			// Data Error 
			return modbus_exception( cmd, 0x03U );
		}
	}

	// Without Write Function  
	if( device->write == NULL )
	{
		// Default Write Registers
		u8bu16cpy(&device->dev[ addr ], &cmd[6], quantity);
	}
	// With Write Function  
	else
	{
		if( device->write( addr, quantity, &cmd[ 6 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x04U );
		}
	}
	return ( 5U );
}
#endif

#if MDOBUS_FUNCTION_CODE_17_ENABLE == 1
/*
************************************************************************************************************************
Objective				: Modbus Function Code 0x17 Process - Read and Write Registers
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command 
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
static	uint16_t mdbdec_17_read_write_regs( uint8_t  *cmd, uint16_t  len )
{
	uint16_t				 addr;
	uint16_t				 quantity;
	uint16_t				 read_type;
	uint8_t  				 bytecount;
	uint8_t  				 i;
	const struct	mdb_dev_struct	*read_device;
	const struct	mdb_dev_struct	*write_device;

	// Command len too short
	if( len < 12U )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the Read Quantity
	quantity = get_u16b( & cmd[ 3 ] );
	if( ( quantity < 0x0001U ) || ( quantity > MODBUS_REGISTER_READ_MAX ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the read address overflow
	addr = get_u16b( & cmd[ 1 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// get the read Modbus device 
	read_device = mdb_get_device( MODBUS_INTERNAL_REGISTER, addr, quantity );

	// Cannot find any matched device
	if( read_device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Check the quantity of writing registers
	quantity = get_u16b( & cmd[ 7 ] );
	if( ( quantity < 0x0001U ) || ( quantity > ( MODBUS_REGISTER_WRITE_MAX - 2U ) ) )
																				//	 less 2 words of len then		    
																				//		Function code 0x10			    
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Count and Check Write Byte count  
	bytecount = ( uint8_t )( quantity * 2U );
	if( bytecount != cmd[ 9 ] )
	{
		return modbus_exception( cmd, 0x03U );
	}
	if( len < ( ( uint16_t )bytecount + 10U ) )
	{
		return modbus_exception( cmd, 0x03U );
	}

	// Check the write address overflow 
	addr = get_u16b( & cmd[ 5 ] );
	if( ( addr + quantity ) < addr )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Get the write Modbus Device 
	write_device = mdb_get_device( MODBUS_INTERNAL_REGISTER, addr, quantity );

	// Cannot find any matched device
	if( write_device == NULL )
	{
		return modbus_exception( cmd, 0x02U );
	}

	// Write process				
	addr -= write_device->addr;
	// With check function  
	if( write_device->check != NULL )
	{
		if( write_device->check( addr, quantity, &cmd[ 10 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x03U );
		}
	}

	// Without write function  
	if( write_device->write == NULL )
	{
		// Default Write Registers
		u8bu16cpy(&write_device->dev[ addr ], &cmd[10], quantity);
	}
	// With Write function 
	else
	{
		if( write_device->write( addr, quantity, &cmd[ 10 ] ) != 0U )
		{
			return modbus_exception( cmd, 0x04U );
		}
	}


	// read process
	quantity   = get_u16b( & cmd[ 3 ] );
	bytecount  = ( uint8_t )( quantity * 2U );
	addr	   = get_u16b( & cmd[ 1 ] );
	addr	  -= read_device->addr;
	cmd[ 1 ]   = bytecount;

	// Without read function  
	if( read_device->read == NULL )
	{
        u16u8bcpy(&cmd[2], &read_device->dev[addr], quantity);
	}
	// With read function  
	else
	{
		read_device->read( addr, quantity, &cmd[ 2U ] );
	}
	return ( ( uint16_t )bytecount + 2U );
}
#endif


/*
************************************************************************************************************************
Objective				: Modbus Exception Code Reply
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  code		  Exception Code 
Output					: Length of Modbus exception reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
uint16_t modbus_exception( uint8_t	*cmd, uint8_t  code )
{
	cmd[ 0 ] |= ( uint8_t )0x80U;
	cmd[ 1 ]  = code;
	return 2U;
}


/*
************************************************************************************************************************
Objective				: Modbus Device look up 
Description				: return when
						  1. type matched
						  2. addr+quantity within device range(address+size)
Input					: type	   Modbus Device Type
						  addr	   Modbus Device Address
						  quantity Quantitiy of the device	  
Output					: Pointer to the matched device  
						  NULL for address vaild						   
Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/

const struct mdb_dev_struct	*mdb_get_device( uint16_t  type, uint16_t  addr, uint16_t  quantity )
{
	uint16_t i;

	for( i = ( uint16_t )0U; i < mdb_dev_count; i++ )
	{
		
		if( mdb_dev[ i ]->type == type )
		{
			//-------to fix the problem----------Aevin 7/3/2015
		#if 0	
			if( ( addr >= mdb_dev[ i ]->addr )
				 && ( ( addr + quantity ) <= ( mdb_dev[ i ]->addr + mdb_dev[ i ]->max ) ) )
			{
				return mdb_dev[ i ];
			}
		#else	
			if( ((addr & 0xFF00) == mdb_dev[ i ]->addr) &&
				  quantity <= mdb_dev[ i ]->max){
				return mdb_dev[ i ];
			}
		#endif
		}
	}

	//address not vaild
	return NULL;
}


/*
************************************************************************************************************************
Objective				: Modbus Command Decode
Description				: 
Input					: cmd		  pointer to command, include funtion code, not include Slave ID
						  len		  length of the command, not include Slave ID  
Output					: Length of Modbus Reply, Reply message in cmd  

Development History 	:
@author					: Kevin
@date					: 2011/07/08
@remarks				:

************************************************************************************************************************
*/
uint16_t modbus_decode( uint8_t  *cmd, uint8_t	len )
{
	uint16_t i = 0;
	uint16_t code = 0;

	code = ( uint16_t )cmd[ 0 ];

	for( i = ( uint16_t )0U; i < mdb_func_count; i++ )
	{
		if( code == mdb_func[ i ]->code )
		{
			return ( mdb_func[ i ]->func( &cmd[ 0 ], ( uint16_t )len ) );
		}
	}
	
	// No Function Code Supported 
	return ( modbus_exception( &cmd[ 0 ], 0x01U ) );
}
 
	
uint16_t modbus_device_init( void ){
	
	if (mdb_dev_add(&stPar_Grp_0) != 0U){	// add MODBUS_PARA_GROUP, Sean, 20141225
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_1) != 0U){
		return 1U;	
	}	

	if (mdb_dev_add(&stPar_Grp_2) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_3) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_4) != 0U){
		return 1U;	
	}	

	if (mdb_dev_add(&stPar_Grp_5) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_6) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_7) != 0U){
		return 1U;	
	}	

	if (mdb_dev_add(&stPar_Grp_8) != 0U){
		return 1U;	
	}			

	if (mdb_dev_add(&stPar_Grp_9) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_10) != 0U){
		return 1U;	
	}	

	if (mdb_dev_add(&stPar_Grp_11) != 0U){
		return 1U;	
	}		

	if (mdb_dev_add(&stPar_Grp_12) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_13) != 0U){
		return 1U;	
	}	

	if (mdb_dev_add(&stPar_Grp_14) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stPar_Grp_15) != 0U){
		return 1U;	
	}
	
	if (mdb_dev_add(&stPar_Grp_GpNo) != 0U){
		return 1U;	
	}	

		

	
	if (mdb_dev_add(&stC21xx) != 0U){
		return 1U;	
	}
	//not neccesary for cc01 keypad
	if (mdb_dev_add(&stC22xx) != 0U){
		return 1U;	
	}
	
	
	//useless for CC01 keypad
	if (mdb_dev_add(&stC23xx) != 0U){
		return 1U;	
	}	
	
	if (mdb_dev_add(&stC31xx) != 0U){
		return 1U;	
	}		
	
	//useless for CC01 keypad		
	if (mdb_dev_add(&stC32xx) != 0U){
		return 1U;	
	}
	//useless for CC01 keypad
	if (mdb_dev_add(&stC33xx) != 0U){
		return 1U;	
	}
	

	//----------add C20xx---------------------6/30/2015
	if (mdb_dev_add(&stC20xx) != 0U){	
		return 1U;	
	}
	
	//neccesary for keypad
	if (mdb_dev_add(&stC34xx) != 0U){
		return 1U;	
	}
	
	//----------Add C35xx-------------------7/3/2015
	if (mdb_dev_add(&stC35xx) != 0U){
		return 1U;	
	}

	//----------Add CFFxx-------------------7/6/2015
	if (mdb_dev_add(&stCFFxx) != 0U){
		return 1U;	
	}

	//----------Add CMEMADDR-------------------7/6/2015
	if (mdb_dev_add(&stC_MEMADDR) != 0U){
		return 1U;	
	}
	
	return 0U;
}
  
