/*
 * TWI_interface.h
 *
 *  Created on: May 24, 2024
 *      Author :  D52
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_



void TWI_voidInit();

void TWI_voidSendStartCondition(void);
void TWI_voidSendRepeatStartCondition(void);
void TWI_voidSendStopCondition(void);
void TWI_voidSendSlaveAddressWithWrite(u8 copy_u8SlaveAddress);
void TWI_voidSendSlaveAddressWithRead(u8 copy_u8SlaveAddress);
void TWI_voidSendMasterByteData(u8 copy_u8TxData);
void TWI_voidReceiveMasterByteDataWithAck(u8 * copy_u8RxData);
void TWI_voidReceiveMasterByteDataWithNAck(u8 * copy_u8RxData);

void TWI_voidListenToMaster(void);


#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
