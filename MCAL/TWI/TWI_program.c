/*
 * TWI_program.c
 *
 *  Created on: May 24, 2024
 *  Author :  D52
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* MCAL */
#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"

void TWI_voidInit() {
	TWBR_REG = 12;
	CLR_BIT(TWSR_REG, TWSR_TWPS0);
	CLR_BIT(TWSR_REG, TWSR_TWPS1);

	SET_BIT(TWCR_REG, TWCR_TWEN);

}

void TWI_voidSendStartCondition(void) {
	SET_BIT(TWCR_REG, TWCR_TWSTA);

	//clear flag to start job
	SET_BIT(TWCR_REG, TWCR_TWINT);

	//busy wait uti
	while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))
		;

	//check Staus code
	while (TWI_status_VALUE != TWI_Start_ACK)
		;

}
void TWI_voidSendRepeatStartCondition(void) {
	SET_BIT(TWCR_REG, TWCR_TWSTA);

	//clear flag to start job
	SET_BIT(TWCR_REG, TWCR_TWINT);

	//busy wait uti
	while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))
		;

	//check Staus code
	while (TWI_status_VALUE != TWI__REP_Start_ACK)
		;
}
void TWI_voidSendStopCondition(void) {
	SET_BIT(TWCR_REG, TWCR_TWSTO);

	//clear flag to start job
	SET_BIT(TWCR_REG, TWCR_TWINT);

}
void TWI_voidSendSlaveAddressWithWrite(u8 copy_u8SlaveAddress) {
	if (copy_u8SlaveAddress < 128) {
		TWDR_REG = (copy_u8SlaveAddress << 1);
		//WRITE CONDITION
		CLR_BIT(TWDR_REG, 0);
		//CLEAR START
		CLR_BIT(TWCR_REG, TWCR_TWSTA);

		//clear flag to start job
		SET_BIT(TWCR_REG, TWCR_TWINT);

		//busy wait uti
		while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))
			;

		//check Staus code
		while (TWI_status_VALUE != TWI_SLAVE_ADDRESS_WRITE_ACK)
			;
	}

}
void TWI_voidSendSlaveAddressWithRead(u8 copy_u8SlaveAddress) {
	if (copy_u8SlaveAddress < 128) {
		TWDR_REG = (copy_u8SlaveAddress << 1);
		//WRITE CONDITION
		SET_BIT(TWDR_REG, 0);
		//CLEAR START
		CLR_BIT(TWCR_REG, TWCR_TWSTA);

		//clear flag to start job
		SET_BIT(TWCR_REG, TWCR_TWINT);

		//busy wait uti
		while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))
			;

		//check Staus code
		while (TWI_status_VALUE != TWI_SLAVE_ADDRESS_READ_ACK)
			;
	}
}
void TWI_voidSendMasterByteData(u8 copy_u8TxData) {
	TWDR_REG = copy_u8TxData;
	//clear flag to start job
	SET_BIT(TWCR_REG, TWCR_TWINT);

	//busy wait uti
	while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))
		;

	//check Staus code
	while (TWI_status_VALUE != TWI_MASTER_DATA_TRANSMIT_ACK)
		;

}
void TWI_voidReceiveMasterByteDataWithAck(u8 *copy_u8RxData) {
	if(copy_u8RxData != NULL)
	{
		//SEND ACK
		SET_BIT(TWCR_REG,  TWCR_TWEA);

		//clear flag to start job
		SET_BIT(TWCR_REG, TWCR_TWINT);

		//busy wait uti
		while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))
			;

		//check Staus code
		while (TWI_status_VALUE != TWI_MASTER_DATA_RECEIVE_ACK)			;

		*copy_u8RxData = TWDR_REG;

		//CLEAR ACK
		CLR_BIT(TWCR_REG,  TWCR_TWEA);
	}

}
void TWI_voidReceiveMasterByteDataWithNAck(u8 *copy_u8RxData){
	if(copy_u8RxData != NULL)
	{

		//clear flag to start job
		SET_BIT(TWCR_REG, TWCR_TWINT);

		//busy wait uti
		while (0 == GET_BIT(TWCR_REG, TWCR_TWINT))			;

		//check Staus code
		while (TWI_status_VALUE != TWI_MASTER_DATA_RECEIVE_NACK)			;

		*copy_u8RxData = TWDR_REG;

	}
}

void TWI_voidListenToMaster(void) {
	while (0 == GET_BIT(TWCR_REG, TWCR_TWEA))
		;

}

