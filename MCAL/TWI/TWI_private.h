/*
 * TWI_private.h
 *
 *  Created on: May 24, 2024
 *     Author :  D52
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

#define TWI_status_VALUE				(TWSR_REG&0XF8)
#define TWI_Start_ACK					0x08
#define TWI__REP_Start_ACK				0x10
#define TWI_SLAVE_ADDRESS_WRITE_ACK		0x18
#define TWI_SLAVE_ADDRESS_READ_ACK		0x40
#define TWI_MASTER_DATA_TRANSMIT_ACK	0x28
#define TWI_MASTER_DATA_RECEIVE_ACK		0x50
#define TWI_MASTER_DATA_RECEIVE_NACK	0x58


#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
