/*
 * LS_program.c
 *
 * Created: 7/7/2024 8:22:55 AM
 *  Author :  D52
 */

#define F_CPU 16000000UL
#include <util/delay.h>
/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "LED_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "LED_config.h"

/************************************************************************/
/*               Function That Init 5 leds and Keypad and LCD            /
 /************************************************************************/
void LS_voidInit(void) {
	LED_voidInit(LED1_PORT, LED1_PIN);
	LED_voidInit(LED2_PORT, LED2_PIN);
	LED_voidInit(LED3_PORT, LED3_PIN);
	LED_voidInit(LED4_PORT, LED4_PIN);
	LED_voidInit(LED5_PORT, LED5_PIN);



}
/************************************************************************/
/*         Function That Control Lightening System From Keypad           /
 /************************************************************************/
void LS_voidStartKPD(void) {
	u8 local_u8KPD1; /* Local variable to return  */
	u8 local_u8KPD2; /*      KPD Button state     */

	LCD_voidClear();
	LCD_voidDisplayString((u8*) "Choose From");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "LED1 TO LED5");
	/* Get Keypad Status*/
	do {
		KPD_voidGetValue(&local_u8KPD1);
	} while (local_u8KPD1 == KPD_NOT_PRESSED);

	/* if condition to choose between 5 leds */

	if (local_u8KPD1 == '1') //LED1
			{

		LCD_voidClear();
		LCD_voidDisplayString((u8*) "      LED1");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "1-ON       2-OFF");

		do {
			KPD_voidGetValue(&local_u8KPD2);
		} while (local_u8KPD2 == KPD_NOT_PRESSED);
		LCD_voidClear();
		if (local_u8KPD2 == '1') {
			LED_voidLedOn(LED1_PORT, LED1_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 1 is ON");
			_delay_ms(3000);
		} else if (local_u8KPD2 == '2') {
			LED_voidLedOff(LED1_PORT, LED1_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 1 is OFF");
			_delay_ms(3000);
		} else {
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Wrong Choice");
			LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
			LCD_voidDisplayString((u8*) "Please Try again!!");
			_delay_ms(1500);
			LCD_voidClear();
		}
	}

	else if (local_u8KPD1 == '2') //LED2
			{
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "      LED2");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "1-ON       2-OFF");
		do {
			KPD_voidGetValue(&local_u8KPD2);
		} while (local_u8KPD2 == KPD_NOT_PRESSED);
		LCD_voidClear();
		if (local_u8KPD2 == '1') {
			LED_voidLedOn(LED2_PORT, LED2_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 2 is ON");
					_delay_ms(3000);
		} else if (local_u8KPD2 == '2') {
			LED_voidLedOff(LED2_PORT, LED2_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 2 is OFF");
						_delay_ms(3000);
		} else {
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Wrong Choice");
			LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
			LCD_voidDisplayString((u8*) "Please Try again!!");
			_delay_ms(1500);
			LCD_voidClear();
		}
	}

	else if (local_u8KPD1 == '3') //LED3
			{
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "      LED3");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "1-ON       2-OFF");
		do {
			KPD_voidGetValue(&local_u8KPD2);
		} while (local_u8KPD2 == KPD_NOT_PRESSED);
		LCD_voidClear();
		if (local_u8KPD2 == '1') {
			LED_voidLedOn(LED3_PORT, LED3_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 3 is ON");
					_delay_ms(3000);
		} else if (local_u8KPD2 == '2') {
			LED_voidLedOff(LED3_PORT, LED3_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 3 is OFF");
								_delay_ms(3000);
		} else {
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Wrong Choice");
			LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
			LCD_voidDisplayString((u8*) "Please Try again!!");
			_delay_ms(1500);
			LCD_voidClear();
		}
	} else if (local_u8KPD1 == '4') //LED4
			{
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "      LED4");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "1-ON       2-OFF");
		do {
			KPD_voidGetValue(&local_u8KPD2);
		} while (local_u8KPD2 == KPD_NOT_PRESSED);
		LCD_voidClear();
		if (local_u8KPD2 == '1') {
			LED_voidLedOn(LED4_PORT, LED4_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 4 is ON");
					_delay_ms(3000);
		} else if (local_u8KPD2 == '2') {
			LED_voidLedOff(LED4_PORT, LED4_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 4 is OFF");
											_delay_ms(3000);
		} else {
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Wrong Choice");
			LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
			LCD_voidDisplayString((u8*) "Please Try again!!");
			_delay_ms(1500);
			LCD_voidClear();
		}
	}

	else if (local_u8KPD1 == '5') //LED5
			{
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "      LED5");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "1-ON       2-OFF");
		do {
			KPD_voidGetValue(&local_u8KPD2);
		} while (local_u8KPD2 == KPD_NOT_PRESSED);
		LCD_voidClear();
		if (local_u8KPD2 == '1') {
			LED_voidLedOn(LED5_PORT, LED5_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 5 is ON");
					_delay_ms(3000);
		} else if (local_u8KPD2 == '2') {
			LED_voidLedOff(LED5_PORT, LED5_PIN, LED_FORWARD_CONNECTION);
			LCD_voidDisplayString((u8*) "LED 5 is OFF");
											_delay_ms(3000);
		} else {
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Wrong Choice");
			LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
			LCD_voidDisplayString((u8*) "Please Try again!!");
			_delay_ms(1500);
			LCD_voidClear();
		}
	} else {
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "Wrong Choice");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "Please Try again!!");
		_delay_ms(1500);
		LCD_voidClear();
	}
}

/************************************************************************/
/*    Function That Control Lightening System From Virtual Screen        /
 /************************************************************************/
void LS_voidStartBluetooth(void) {
	u8 local_u8RXData1; /* Local variable to return  */
	u8 local_u8RXData2; /*Received data from Virtual screen*/

//Writing Some MSG On LCD
	UART_voidTxString((u8*) "Choose From");
	UART_voidTxString((u8*) "LED1 TO LED5");

	/* Get UART STATUS*/
	do {
		UART_voidRxChar(&local_u8RXData1);
	} while (local_u8RXData1 == NULL );

	/* if condition to choose between 5 leds */

	if (local_u8RXData1 == '1') //LED1
			{

		LCD_voidClear();
		UART_voidTxString((u8*) "      LED1");

		UART_voidTxString((u8*) "1-ON       2-OFF");
		do {
			UART_voidRxChar(&local_u8RXData2);
		} while (local_u8RXData2 == NULL );

		if (local_u8RXData2 == '1') {
			LED_voidLedOn(LED1_PORT, LED1_PIN, LED_FORWARD_CONNECTION);

			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 1 is ON");
			UART_voidTxString((u8*) "LED 1 is ON");
		} else if (local_u8RXData2 == '2') {
			LED_voidLedOff(LED1_PORT, LED1_PIN, LED_FORWARD_CONNECTION);

			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 1 is OFF");
			UART_voidTxString((u8*) "LED 1 is OFF");
		} else {

			UART_voidTxString((u8*) "Wrong Choice");
			UART_voidTxString((u8*) "Please Try again!!");

		}
	}

	else if (local_u8RXData1 == '2') //LED2
			{

		UART_voidTxString((u8*) "      LED2");

		UART_voidTxString((u8*) "1-ON       2-OFF");
		do {
			UART_voidRxChar(&local_u8RXData2);
		} while (local_u8RXData2 == NULL );
		if (local_u8RXData2 == '1') {
			LED_voidLedOn(LED2_PORT, LED2_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 2 is ON");
			UART_voidTxString((u8*) "LED 2 is ON");
		} else if (local_u8RXData2 == '2') {
			LED_voidLedOff(LED2_PORT, LED2_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 2 is OFF");
			UART_voidTxString((u8*) "LED 2 is OFF");
		} else {
			UART_voidTxString((u8*) "Wrong Choice");
			UART_voidTxString((u8*) "Please Try again!!");
		}
	}

	else if (local_u8RXData1 == '3') //LED3
			{
		LCD_voidClear();
		UART_voidTxString((u8*) "      LED3");
		UART_voidTxString((u8*) "1-ON       2-OFF");
		do {
			UART_voidRxChar(&local_u8RXData2);
		} while (local_u8RXData2 == NULL );

		if (local_u8RXData2 == '1') {
			LED_voidLedOn(LED3_PORT, LED3_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 3 is ON");
			UART_voidTxString((u8*) "LED 3 is ON");
		} else if (local_u8RXData2 == '2') {
			LED_voidLedOff(LED3_PORT, LED3_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 3 is OFF");
			UART_voidTxString((u8*) "LED 3 is OFF");
		} else {
			UART_voidTxString((u8*) "Wrong Choice");
			UART_voidTxString((u8*) "Please Try again!!");
		}
	} else if (local_u8RXData1 == '4') //LED4
			{
		LCD_voidClear();
		UART_voidTxString((u8*) "      LED4");

		UART_voidTxString((u8*) "1-ON       2-OFF");
		do {
			UART_voidRxChar(&local_u8RXData2);
		} while (local_u8RXData2 == NULL );
		if (local_u8RXData2 == '1') {
			LED_voidLedOn(LED4_PORT, LED4_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 4 is ON");
			UART_voidTxString((u8*) "LED 4 is ON");
		} else if (local_u8RXData2 == '2') {
			LED_voidLedOff(LED4_PORT, LED4_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 4 is OFF");
			UART_voidTxString((u8*) "LED 4 is OFF");
		} else {
			UART_voidTxString((u8*) "Wrong Choice");
			UART_voidTxString((u8*) "Please Try again!!");
		}
	}

	else if (local_u8RXData1 == '5') //LED5
			{
		LCD_voidClear();
		UART_voidTxString((u8*) "      LED5");

		UART_voidTxString((u8*) "1-ON       2-OFF");
		do {
			UART_voidRxChar(&local_u8RXData2);
		} while (local_u8RXData2 == NULL );
		if (local_u8RXData2 == '1') {
			LED_voidLedOn(LED5_PORT, LED5_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 5 is ON");
			UART_voidTxString((u8*) "LED 5 is ON");
		} else if (local_u8RXData2 == '2') {
			LED_voidLedOff(LED5_PORT, LED5_PIN, LED_FORWARD_CONNECTION);
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "LED 5 is OFF");
			UART_voidTxString((u8*) "LED 5 is OFF");
		} else {
			UART_voidTxString((u8*) "Wrong Choice");
			UART_voidTxString((u8*) "Please Try again!!");
		}
	} else {
		UART_voidTxString((u8*) "Wrong Choice");
		UART_voidTxString((u8*) "Please Try again!!");
	}
}
