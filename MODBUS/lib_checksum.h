#ifndef _LIB_CHECKSUM_H_
#define     _LIB_CHECKSUM_H_


#include     "stdint.h"


//SUM chekcsum 
uint8_t  sum_1b( const uint8_t  *buf, uint16_t  len, uint8_t  init, uint8_t  comp );
uint16_t sum_2b( const uint8_t  *buf, uint16_t  len, uint16_t  init, uint8_t  comp );


//CRC checksum  
uint16_t crc_ccitt( const uint8_t  *buf, uint16_t  len, uint16_t  init );
uint16_t crc_16( const uint8_t  *buf, uint16_t  len, uint16_t  init );
uint16_t crc( const uint8_t  *buf, uint16_t  len );

//LRC checksum
uint8_t  lrc_1b( const uint8_t  *buf, uint16_t  len, uint16_t  init, uint8_t  comp );
uint16_t lrc_2b( const uint16_t  *buf, uint16_t  wlen );
uint16_t lrc_2b_dec( const uint16_t  *buf, uint16_t  wlen );


//Binary to ASCII conversion
uint16_t to_modbus_ascii( uint8_t  *dst, uint8_t  *src, uint16_t  len );

#endif
