/*
 * EEPROM_program.c
 *
 *  Created on: May 31, 2024
 *      Author :  D52
 */

#define F_CPU 16000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

/* MCAL */
#include "TWI_interface.h"

/* HAL */
#include "EEPROM_interface.h"
#include "EEPROM_register.h"
#include "EEPROM_private.h"

void EEPROM_voidInit(void) {
	TWI_voidInit();
}
void EEPROM_voidWriteByte(u16 copy_u16WordAddress, u8 copy_u8Data) {
	u8 local_u8DeviceAddress = (copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS;

	TWI_voidSendStartCondition();

	TWI_voidSendSlaveAddressWithWrite(local_u8DeviceAddress);

	TWI_voidSendMasterByteData((u8) copy_u16WordAddress);

	TWI_voidSendMasterByteData(copy_u8Data);

	TWI_voidSendStopCondition();

	_delay_ms(5);
}

void EEPROM_voidReadByte(u16 copy_u16WordAddress, u8 *copy_pu8Data) {
	if (copy_pu8Data != NULL) {
		u8 local_u8DeviceAddress = (copy_u16WordAddress >> 8) | 0x50;

		TWI_voidSendStartCondition();

		TWI_voidSendSlaveAddressWithWrite(local_u8DeviceAddress);

		TWI_voidSendMasterByteData((u8) copy_u16WordAddress);

		TWI_voidSendRepeatStartCondition();

		TWI_voidSendSlaveAddressWithRead(local_u8DeviceAddress);

		TWI_voidReceiveMasterByteDataWithNAck(copy_pu8Data);

		TWI_voidSendStopCondition();

		_delay_ms(5);
	}
}
