#ifndef __MODBUS_ENC_H__
#define __MODBUS_ENC_H__ 1

#include "stdint.h"

//---------------------------------------------------------------------------------------------------------
uint16_t mdbenc_read(uint8_t  *buf, const uint16_t code, const uint32_t  addr, const uint16_t  quantity );
uint16_t mdbenc_write(uint8_t  *buf, const uint16_t code, const uint32_t  addr, const uint16_t  quantity, const uint16_t* var );

uint16_t mdbchk_read(uint8_t  *buf, const uint16_t len, const uint16_t code, const uint16_t  quantity, uint16_t * var );
uint16_t mdbchk_write(uint8_t  *buf, const uint16_t len, const uint16_t code, const uint16_t  addr, const uint16_t  quantity);

uint16_t mdbenc_read_write(uint8_t  *buf, const uint16_t code, const uint32_t  r_addr, const uint16_t  r_quantity, const uint32_t  w_addr, const uint16_t  w_quantity, const uint16_t* var );
uint16_t mdbchk_read_write(uint8_t  *buf, const uint16_t len, const uint16_t code, const uint16_t  quantity, uint16_t * var );



//-----------------------------------------------------------------------------
// Encode Funciton 
uint16_t mdbenc_01_read_coils( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_02_read_discrete_input( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_03_read_holding_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_04_read_input_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity );
uint16_t mdbenc_05_write_single_coil( uint8_t  *buf, const uint16_t  addr, const uint8_t var);
uint16_t mdbenc_06_write_single_register( uint8_t  *buf, const uint16_t  addr, const uint16_t var);
uint16_t mdbenc_0f_write_multiple_coil( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity, const uint16_t* var);
uint16_t mdbenc_10_write_multiple_register( uint8_t  *buf, const uint16_t  addr, const uint16_t  quantity, const uint16_t* var);
uint16_t mdbenc_17_read_write_register( uint8_t  *buf, const uint16_t  r_addr, const uint16_t  r_quantity, const uint16_t  w_addr, const uint16_t  w_quantity, const uint16_t* var);


//-----------------------------------------------------------------------------
// Check Function 
uint16_t mdbchk_01_read_coils( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_02_read_discrete_input(  uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_03_read_holding_register( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_04_read_input_register( uint8_t  *buf, const uint16_t len, const uint16_t  quantity,  uint16_t * var );
uint16_t mdbchk_05_write_single_coil( uint8_t  *buf, const uint16_t len, const uint16_t  addr );
uint16_t mdbchk_06_write_single_register( uint8_t  *buf, const uint16_t len, const uint16_t  addr );
uint16_t mdbchk_0f_write_multiple_coil( uint8_t  *buf, const uint16_t len, const uint16_t  addr, const uint16_t  quantity);
uint16_t mdbchk_10_write_multiple_register( uint8_t  *buf, const uint16_t len, const uint16_t  addr, const uint16_t  quantity);
uint16_t mdbchk_17_read_write_register( uint8_t  *buf, const uint16_t len, const uint16_t  r_quantity,  uint16_t * var );

#endif