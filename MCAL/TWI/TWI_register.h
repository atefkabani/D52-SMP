/*
 * TWI_register.h
 *
 *  Created on: May 24, 2024
 *      Author :  D52
 */

#ifndef MCAL_TWI_TWI_REGISTER_H_
#define MCAL_TWI_TWI_REGISTER_H_

#define TWBR_REG 		(*(volatile u8*) 0x20)
#define TWCR_REG 		(*(volatile u8*) 0x56)
#define TWCR_TWINT 		7
#define TWCR_TWEA 		6
#define TWCR_TWSTA 		5
#define TWCR_TWSTO 		4
#define TWCR_TWWC 		3
#define TWCR_TWEN 		2
#define TWCR_TWIE		0

#define TWSR_REG 		(*(volatile u8*) 0x21)
#define TWSR_TWS7 		7
#define TWSR_TWS6 		6
#define TWSR_TWS5 		5
#define TWSR_TWS4 		4
#define TWSR_TWS3 		3
#define TWSR_TWPS1 		1
#define TWSR_TWPS0		0

#define TWDR_REG 		(*(volatile u8*) 0x23)
#define TWAR_REG 		(*(volatile u8*) 0x22)
#define TWAR_TWGCE		0




#endif /* MCAL_TWI_TWI_REGISTER_H_ */
