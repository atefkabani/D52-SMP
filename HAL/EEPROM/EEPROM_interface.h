/*
 * EEPROM_interface.h
 *
 *  Created on: May 31, 2024
 *      Author :  D52
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWriteByte(u16 copy_u16WordAddress, u8 copy_u8Data);
void EEPROM_voidReadByte(u16 copy_u16WordAddress, u8 * copy_pu8Data);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
