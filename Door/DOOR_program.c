/*
 * SERVO_program.c
 *
 *  Created on: May 13, 2024
 *Author :  D52
 */
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*HAL*/
#include "LCD_interface.h"


/*MCAL*/
#include "UART_interface.h"

/*Project*/
#include "DOOR_interface.h"


void DOOR_voidInit(void) {
	SERVO_voidInit();
	u8 local_u8RxData;
	UART_voidTxString((u8*) "1- Open Door ");

	UART_voidTxString((u8*) "2- Close Door");
	do {
		UART_voidRxChar(&local_u8RxData);

	} while (local_u8RxData == NULL);
	if (local_u8RxData == '1') {
		DOOR_voidOpen();
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "Door Opened");
		UART_voidTxString((u8*)  "Door Opened");
	} else if (local_u8RxData == '2') {

		DOOR_voidClose();
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "Door Closed");
		UART_voidTxString((u8*) "Door Closed");
	}else {

		UART_voidTxString((u8*) "Wrong Choice");
		UART_voidTxString((u8*) "Please Try again!!");

	}
	_delay_ms(3000);
	LCD_voidClear();

}

void DOOR_voidOpen(void) {
	SERVO_voidRotate0_180(SERVO_OPEN_ANGLE);
}

void DOOR_voidClose(void) {
	SERVO_voidRotate0_180(SERVO_CLOSE_ANGLE);
}
