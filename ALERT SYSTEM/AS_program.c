/*
 * AS_program.c
 *
 * Created: 7/9/2024 8:49:37 PM
 *Author :  D52
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "BUZZER_interface.h"
#include "BUZZER_config.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "LCD_interface.h"

void AS_voidInit(void)
{
	LED_voidInit   (ALERT_LED_PORT,ALERT_LED_PIN);
	BUZZER_voidInit(ALERT_BUZZER_PORT,ALERT_BUZZER_PIN);
	
}

void AS_voidStart(void)
{
	LCD_voidClear();
	LCD_voidDisplayString((u8*)"ALERT IS ON");



		while(1){
			BUZZER_voidToggle(ALERT_BUZZER_PORT,ALERT_BUZZER_PIN);
			LED_voidLedToggle(ALERT_LED_PORT,ALERT_LED_PIN);
		_delay_ms(1500);
	}
	
}

