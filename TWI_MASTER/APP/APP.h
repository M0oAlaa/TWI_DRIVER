#ifndef _APP_H_
#define _APP_H_

#include "../LIB/STD_TYPES.h"
#include "../MCAL/TWI/TWI_interface.h"

void App_init(void)
{
	TWI_MasterInit();
}

void App_prog(void)
{
	TWI_startCond();
	TWI_SendSlaveAddWrite(0x01);
	TWI_MasterSendData(0x55);
	TWI_SendStopCond();
}

#endif
