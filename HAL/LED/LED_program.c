/*
 * LED_program.c
 *
 * Created: 4/10/2024 6:05:42 PM
 *  Author :  D52
 */ 

/**********UTILES_LIB**********/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/**********MCAL**********/
#include "DIO_interface.h"
#include "DIO_register.h"
/**********HAL**********/
#include "LED_interface.h"
#include "LED_config.h"

void LED_voidInit       (u8 copy_u8LedPortId, u8 copy_u8LedPinId)//Function For Intilization a Led
{
	DIO_voidSetPinDirection(copy_u8LedPortId, copy_u8LedPinId, DIO_PIN_OUTPUT);//Set Pin Of The Led As Output
}

void LED_voidLedOn      (u8 copy_u8LedPortId, u8 copy_u8LedPinId, u8 copy_u8LedConnectionType)//Function To Turn Led On In (For/Rev) Connection
{
	switch(copy_u8LedConnectionType)//Forward Or Reverse
	{
		case LED_FORWARD_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPortId,copy_u8LedPinId,DIO_PIN_HIGH);//High => On Led
		break;
		
		case LED_REVERSE_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPortId,copy_u8LedPinId,DIO_PIN_LOW);//Low  => On Led
		break;
		
	}
}
void LED_voidLedOff     (u8 copy_u8LedPortId, u8 copy_u8LedPinId, u8 copy_u8LedConnectionType)//Function To Turn Led Off In (For/Rev) Connection
{
	switch(copy_u8LedConnectionType)//Forward Or Reverse
	{
		case LED_FORWARD_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPortId,copy_u8LedPinId,DIO_PIN_LOW);//Low => Off Led
		break;
		
		case LED_REVERSE_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPortId,copy_u8LedPinId,DIO_PIN_HIGH);//High  => Off Led
		break;
	}
		
}
void LED_voidLedToggle  (u8 copy_u8LedPortId, u8 copy_u8LedPinId)//Function To Toggle Led 
{
	DIO_voidTogglePinValue(copy_u8LedPortId, copy_u8LedPinId);
}

