/*
 * DIMMER_program.c
 *
 * Created: 7/7/2024 1:06:01 PM
 *Author :  D52
 */
#define F_CPU 16000000UL
#include <util/delay.h>
/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "PWM_interface.h"
#include "DIO_interface.h"
#include "UART_interface.h"
/*HAL*/
#include "RELAY_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
/************************************************************************/
/*Function That init PWM0 to control LED intense and Relay and setting  */
/*                     Pb3 as a output pin  (oc0)                       */
/************************************************************************/
void DIMMER_voidInit(void) {
	PWM0_voidInitChannel_0();
	RELAY_voidInit();
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
}
/************************************************************************/
/*             Function that control Dimmer Circuit                     */
/************************************************************************/
void DIMMER_voidStartKPD(void) {
	u8 local_u8KPD;

	LCD_voidClear();
	LCD_voidDisplayString((u8*) "Enter The LED");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "Intensity (0-9)");
	do {
		KPD_voidGetValue(&local_u8KPD);
	} while (local_u8KPD == KPD_NOT_PRESSED);
	LCD_voidClear();

	if (local_u8KPD == '0') {
		RELAY_voidOff();

		LCD_voidDisplayString((u8*) "LED Intensity 0");
		_delay_ms(2000);

	} else {
		RELAY_voidOn();
		_delay_ms(100);
		PWM0_voidGenerate_PWM_Channel_0(local_u8KPD * 11);

		LCD_voidDisplayString((u8*) "LED Intensity ");
				LCD_voidDisplayChar(local_u8KPD);
				_delay_ms(2000);

	}

}

void DIMMER_voidStartBluetooth(void) {
	u8 local_u8RxData;
	LCD_voidClear();
	UART_voidTxString((u8*) "Enter The LED Intensity (0-9)");

	do {
		UART_voidRxChar(&local_u8RxData);
	} while (local_u8RxData == NULL );
	if (local_u8RxData == '0') {
		RELAY_voidOff();
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "LED Intensity 0");
		UART_voidTxString((u8*) "LED Intensity is 0");
	} else {
		RELAY_voidOn();
		_delay_ms(100);
		PWM0_voidGenerate_PWM_Channel_0(local_u8RxData * 11);
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "LED Intensity ");
		LCD_voidDisplayChar(local_u8RxData);
		UART_voidTxString((u8*) "LED Intensity is ");
		UART_voidTxChar(local_u8RxData);

	}
}
