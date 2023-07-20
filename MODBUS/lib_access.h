#ifndef __LIB_ACCESS_H_
#define __LIB_ACCESS_H_


#include "stdint.h"

// Bit Access
uint8_t get_bit  ( const uint8_t  *ptr, const uint16_t  index );
void    set_bit  ( uint8_t  *ptr, const uint16_t	index, const uint16_t  value );
uint8_t get_16bit( const uint16_t  *ptr, const uint16_t  index );
void    set_16bit( uint16_t  *ptr, const uint16_t  index, const uint16_t	value );
uint8_t get_32bit( const uint32_t  *ptr, const uint16_t  index );
void    set_32bit( uint32_t  *ptr, const uint16_t  index, const uint16_t	value );



// Big Endian Access
uint16_t get_u16b(const uint8_t * addr);
void set_u16b(uint8_t * addr, const uint16_t var);

uint32_t get_u32b( const uint8_t * addr);
void set_u32b( uint8_t * addr, const uint32_t var);

uint16_t u16u8bcpy(uint8_t *dst8, const uint16_t *src16,  uint16_t wcount);
uint16_t u8bu16cpy(uint16_t *dst16, const uint8_t *src8, uint16_t wcount);




// Little Endian Access
uint16_t get_u16l( const uint8_t  *addr );
void set_u16l( uint8_t  *addr, uint16_t  var );

void set_u32l( uint8_t  *addr, uint32_t  var );
uint32_t get_u32l( uint8_t  *addr);

uint16_t u8lu16cpy(uint16_t *dst16, const uint8_t *src8, uint16_t wcount);
uint16_t u16u8lcpy(uint8_t *dst8, const uint16_t *src16,  uint16_t wcount);

uint16_t u16lu32cpy( uint32_t  *dst32, const uint16_t  *src16, uint16_t  dwcount );


#endif
