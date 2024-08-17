/*
 * LM35_program.c
 *
 * Created: 6/30/2024 7:52:16 PM
 *  Author :  D52
 */ 

/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "ADC_interface.h"
#include "DIO_interface.h"
/*HAL*/
#include "LM35_interface.h"
#include "LM35_config.h"

void LM35_voidInit ()
{
	//Choose Internal Voltage Reference = 2.56 V
	ADC_voidInit(ADC_REFERENCE_INTERNAL);
}
void LM35_voidGetTemp (u8 copy_u8FeedbackPin,u8* copy_pTemperature)
{
	if (copy_pTemperature != NULL)
	{
		//Choose Which ADC Channel Will Receive LM35 Feedback Signal
		DIO_voidSetPinDirection(LM35_FEEDBACK_PORT,copy_u8FeedbackPin,DIO_PIN_INPUT);
		u16 copy_u16AnalogValue, copy_u16DigitalValue;
		ADC_voidGetDigiatlValue(copy_u8FeedbackPin,&copy_u16DigitalValue);
		copy_u16AnalogValue = (copy_u16DigitalValue*2560UL)/1024;
		*copy_pTemperature  = (copy_u16AnalogValue/10);
	} 
	else
	{
		//Return Error Statement
	}
}
