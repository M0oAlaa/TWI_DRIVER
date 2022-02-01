#ifndef _APP_H_
#define _APP_H_

#include "../LIB/STD_TYPES.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

uint8_t global_u8Read;

void App_init(void)
{
	TWI_SlaveInit(0x01);
	DIO_SETportDir(DIO_PORTA,DIO_portOUTPUT);
}

void App_prog(void)
{
	TWI_slave_check_slave_address_received_with_write_req();
	global_u8Read=TWI_slave_read_byte();
	DIO_SETportVal(DIO_PORTA,global_u8Read);
}

#endif
