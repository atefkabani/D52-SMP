/*
 * ADC_program.c
 *
 * Created: 4/27/2024 3:33:21 PM
 *  Author :  D52
 */ 

//UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL
#include "ADC_interface.h"
#include "ADC_register.h"


void ADC_voidInit (u8 copy_u8ReferenceVoltage)
{
	switch(copy_u8ReferenceVoltage)
	{
		case ADC_REFERENCE_AVCC:
		SET_BIT(ADMUX_REG, REFS0);
		CLR_BIT(ADMUX_REG, REFS1);
		break;
		
		case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX_REG, REFS0);
		CLR_BIT(ADMUX_REG, REFS1);
		break;
		
		case ADC_REFERENCE_INTERNAL:
		SET_BIT(ADMUX_REG, REFS0);
		SET_BIT(ADMUX_REG, REFS1);
		break;
	}
	// Select Right Adjustment
	CLR_BIT(ADMUX_REG, ADLAR);
	
	// Single Conversion Mode
	CLR_BIT(ADMUX_REG, ADATE);
	
	//Disable ADC Interrupt
	CLR_BIT(ADMUX_REG, ADIE);
	
	// Prescaler 128 For 16MHZ (125 KHZ)
	SET_BIT(ADCSRA_REG, ADPS0);
	SET_BIT(ADCSRA_REG, ADPS1);
	SET_BIT(ADCSRA_REG, ADPS2);
	//ADC Enable
	SET_BIT(ADCSRA_REG, ADEN);
}
void ADC_voidGetDigiatlValue (u8 copy_u8ChannelNumber, u16* copy_pu16DigitalValue)
{
	if ( (copy_pu16DigitalValue != NULL) && (copy_u8ChannelNumber<32))
	{
		// Clear ADMUX Channel Bits
		ADMUX_REG &= 0xE0;   //0b11100000;
		
		// Select Channel Number
		ADMUX_REG |= copy_u8ChannelNumber;
		
		// Start Conversion
		SET_BIT(ADCSRA_REG, ADSC);
		
		// Busy Wait ADC Flag
		while(0 == GET_BIT(ADCSRA_REG, ADIF));
		
		//Clear H.W Flag (Write one To Clear)
		SET_BIT(ADCSRA_REG, ADIF);
		*copy_pu16DigitalValue = ADC_u16_REG;
	} 
	else
	{
		//Return Error State
	}
		
}
