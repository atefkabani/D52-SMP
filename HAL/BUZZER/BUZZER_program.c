/*
 * BUZZER_program.c
 *
 * Created: 4/11/2024 5:38:37 PM
 *  Author :  D52
 */ 

/********** UTILES_LIB **********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/********** MCAL **********/
#include "DIO_interface.h"
#include "DIO_register.h"
/********** HAL **********/
#include "BUZZER_interface.h"
#include "BUZZER_config.h"

void BUZZER_voidInit   (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId)//Function To Init A Buzzer
{
	DIO_voidSetPinDirection(copy_u8BuzzerPortId, copy_u8BuzzerPinId,DIO_PIN_OUTPUT);
}

void BUZZER_voidOn     (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId)//Function To Set Buzzer On
{
	DIO_voidSetPinValue(copy_u8BuzzerPortId, copy_u8BuzzerPinId, DIO_PIN_HIGH);
}

void BUZZER_voidOff    (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId)//Function To Set Buzzer Off
{
	DIO_voidSetPinValue(copy_u8BuzzerPortId, copy_u8BuzzerPinId, DIO_PIN_LOW);
}

void BUZZER_voidToggle (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId)//Function To Toggle a Buzzer
{
	DIO_voidTogglePinValue(copy_u8BuzzerPortId, copy_u8BuzzerPinId);
}


