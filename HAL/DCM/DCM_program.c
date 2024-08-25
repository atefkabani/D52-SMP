/*
 * DCM_program.c
 *
 * Created: 5/11/2024 1:20:08 PM
 *  Author :  D52
 */ 

//UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "PWM_interface.h"

//HAL
#include "DCM_config.h"
#include "DCM_interface.h"


void DCM_voidInit              (u8 copy_u8DCM_ID)
{
	if ((copy_u8DCM_ID==DCM1)||(copy_u8DCM_ID==DCM2))
	{
		switch(copy_u8DCM_ID)
		{
			case DCM1:
			DIO_voidSetPinDirection(DCM1_A1_PORT, DCM1_A1_PIN, DIO_PIN_OUTPUT);
			DIO_voidSetPinDirection(DCM1_A2_PORT, DCM1_A2_PIN, DIO_PIN_OUTPUT);
			DIO_voidSetPinDirection(DCM1_ENABLE_PORT, DCM1_ENABLE_PIN, DIO_PIN_OUTPUT);
			break;
			
			case DCM2:
			DIO_voidSetPinDirection(DCM2_A3_PORT, DCM2_A3_PIN, DIO_PIN_OUTPUT);
			DIO_voidSetPinDirection(DCM2_A4_PORT, DCM2_A4_PIN, DIO_PIN_OUTPUT);
			DIO_voidSetPinDirection(DCM2_ENABLE_PORT, DCM2_ENABLE_PIN, DIO_PIN_OUTPUT);
			break;
		}
	} 
	else
	{
		//Return Error Statement
	}
}
void DCM_voidOn                (u8 copy_u8DCM_ID, u8 copy_u8MotorDirection)
{
	if (((copy_u8MotorDirection==DCM_CW)||(copy_u8MotorDirection==DCM_CCW))&&((copy_u8DCM_ID==DCM1)||(copy_u8DCM_ID==DCM2)))
	{
		switch(copy_u8DCM_ID)
		{
			case DCM1:
			switch(copy_u8MotorDirection)
			{
				case DCM_CW:
				DIO_voidSetPinValue(DCM1_A1_PORT, DCM1_A1_PIN, DIO_PIN_HIGH);
				DIO_voidSetPinValue(DCM1_A2_PORT, DCM1_A2_PIN, DIO_PIN_LOW);
				DIO_voidSetPinValue(DCM1_ENABLE_PORT, DCM1_ENABLE_PIN, DIO_PIN_HIGH);
				break;
				
				case DCM_CCW:
				DIO_voidSetPinValue(DCM1_A1_PORT, DCM1_A1_PIN, DIO_PIN_LOW);
				DIO_voidSetPinValue(DCM1_A2_PORT, DCM1_A2_PIN, DIO_PIN_HIGH);
				DIO_voidSetPinValue(DCM1_ENABLE_PORT, DCM1_ENABLE_PIN, DIO_PIN_HIGH);
				break;
			}
			break;
			
			case DCM2:
			switch(copy_u8MotorDirection)
			{
			case DCM_CW:
			DIO_voidSetPinValue(DCM2_A3_PORT, DCM2_A3_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM2_A4_PORT, DCM2_A4_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM2_ENABLE_PORT, DCM2_ENABLE_PIN, DIO_PIN_HIGH);
			break;
			
			case DCM_CCW:
			DIO_voidSetPinValue(DCM2_A3_PORT, DCM2_A3_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM2_A4_PORT, DCM2_A4_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM2_ENABLE_PORT, DCM2_ENABLE_PIN, DIO_PIN_HIGH);
			break;
			}
		}
	} 
	else
	{
		//Return Error Statement
	}
}
void DCM_voidOff               (u8 copy_u8DCM_ID)
{
	if ((copy_u8DCM_ID==DCM1)||(copy_u8DCM_ID==DCM2))
	{
		switch(copy_u8DCM_ID)
		{
			case DCM1:
			DIO_voidSetPinValue(DCM1_A1_PORT, DCM1_A1_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM1_A2_PORT, DCM1_A2_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM1_ENABLE_PORT, DCM1_ENABLE_PIN, DIO_PIN_LOW);
			break;
			
			case DCM2:
			DIO_voidSetPinValue(DCM2_A3_PORT, DCM2_A3_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM2_A4_PORT, DCM2_A4_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM2_ENABLE_PORT, DCM2_ENABLE_PIN, DIO_PIN_LOW);
			break;
		}
	} 
	else
	{
		//Return Error Statement
	}
}

void DCM_voidControlMotorSpeed (u8 copy_u8DCM_ID, u8 copy_u8MotorDirection, u8 copy_u8DesiredSpeed)
{
	if (((copy_u8MotorDirection==DCM_CW)||(copy_u8MotorDirection==DCM_CCW))&&((copy_u8DCM_ID==DCM1)||(copy_u8DCM_ID==DCM2))&&(copy_u8DesiredSpeed<=100))
	{
		PWM0_voidInitChannel_0();
		PWM0_voidGenerate_PWM_Channel_0(copy_u8DesiredSpeed);
		switch(copy_u8DCM_ID)
		{
			case DCM1:
			switch(copy_u8MotorDirection)
			{
				case DCM_CW:
				DIO_voidSetPinDirection(DCM1_ENABLE_PORT, DCM1_ENABLE_PIN, DIO_PIN_INPUT);
				DIO_voidSetPinValue(DCM1_A1_PORT, DCM1_A1_PIN, DIO_PIN_HIGH);
				DIO_voidSetPinValue(DCM1_A2_PORT, DCM1_A2_PIN, DIO_PIN_LOW);
				break;
				
				case DCM_CCW:
				DIO_voidSetPinDirection(DCM1_ENABLE_PORT, DCM1_ENABLE_PIN, DIO_PIN_INPUT);
				DIO_voidSetPinValue(DCM1_A1_PORT, DCM1_A1_PIN, DIO_PIN_LOW);
				DIO_voidSetPinValue(DCM1_A2_PORT, DCM1_A2_PIN, DIO_PIN_HIGH);
				break;
			}
			break;
			
			case DCM2:
			switch(copy_u8MotorDirection)
			{
				case DCM_CW:
				DIO_voidSetPinDirection(DCM2_ENABLE_PORT, DCM2_ENABLE_PIN, DIO_PIN_INPUT);
				DIO_voidSetPinValue(DCM2_A3_PORT, DCM2_A3_PIN, DIO_PIN_HIGH);
				DIO_voidSetPinValue(DCM2_A4_PORT, DCM2_A4_PIN, DIO_PIN_LOW);
				break;
				
				case DCM_CCW:
				DIO_voidSetPinDirection(DCM2_ENABLE_PORT, DCM2_ENABLE_PIN, DIO_PIN_INPUT);
				DIO_voidSetPinValue(DCM2_A3_PORT, DCM2_A3_PIN, DIO_PIN_LOW);
				DIO_voidSetPinValue(DCM2_A4_PORT, DCM2_A4_PIN, DIO_PIN_HIGH);
				break;
			}
			break;
		}
	} 
	else
	{
		//Return Error Statement
	}
}
