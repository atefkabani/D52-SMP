/*
 * DIO_program.c
 *
 * Created: 5/2/2024 1:17:22 PM
 *  Author :  D52
 */ 

//UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL
#include "DIO_interface.h"
#include "DIO_register.h"

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	if ((copy_u8PortId<4) && (copy_u8PinId<8) && ((copy_u8PinDirection==DIO_PIN_INPUT) || (copy_u8PinDirection==DIO_PIN_OUTPUT)))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PinDirection)
			{
				case DIO_PIN_INPUT:
				CLR_BIT(DDRA_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_OUTPUT:
				SET_BIT(DDRA_REG,copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTB:
			switch(copy_u8PinDirection)
			{
				case DIO_PIN_INPUT:
				CLR_BIT(DDRB_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_OUTPUT:
				SET_BIT(DDRB_REG,copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTC:
			switch(copy_u8PinDirection)
			{
				case DIO_PIN_INPUT:
				CLR_BIT(DDRC_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_OUTPUT:
				SET_BIT(DDRC_REG,copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTD:
			switch(copy_u8PinDirection)
			{
				case DIO_PIN_INPUT:
				CLR_BIT(DDRD_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_OUTPUT:
				SET_BIT(DDRD_REG,copy_u8PinId);
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
void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	if ((copy_u8PortId<4) && (copy_u8PinId<8) && ((copy_u8PinValue==DIO_PIN_LOW) || (copy_u8PinValue==DIO_PIN_HIGH)))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTA_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTA_REG,copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTB:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTB_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTB_REG,copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTC:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTC_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTC_REG,copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTD:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTD_REG,copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTD_REG,copy_u8PinId);
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
void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	if ((copy_u8PortId<4) && (copy_u8PinId<8) && (copy_pu8PinValue != NULL))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			*copy_pu8PinValue = GET_BIT(PINA_REG,copy_u8PinId);
			break;
			
			case DIO_PORTB:
			*copy_pu8PinValue = GET_BIT(PINB_REG,copy_u8PinId);
			break;
			
			case DIO_PORTC:
			*copy_pu8PinValue = GET_BIT(PINC_REG,copy_u8PinId);
			break;
			
			case DIO_PORTD:
			*copy_pu8PinValue = GET_BIT(PIND_REG,copy_u8PinId);
			break;
		}
	}
	else
	{
		//Return Error Statement

	}
	
}
void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	if ((copy_u8PortId<4) && (copy_u8PinId<8))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA_REG,copy_u8PinId);
			break; 
			
			case DIO_PORTB:
			TOG_BIT(PORTB_REG,copy_u8PinId);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC_REG,copy_u8PinId);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD_REG,copy_u8PinId);
			break;
		}
	}
	else
	{
		//Return Error Statement

	}
	
}
void DIO_voidActiveIntPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	//Pin Direction Should be Input To Active Internal PullUp Resistance
	if ((copy_u8PortId<4) && (copy_u8PinId<8))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA_REG,copy_u8PinId);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB_REG,copy_u8PinId);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC_REG,copy_u8PinId);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD_REG,copy_u8PinId);
			break;
		}
	}
	else
	{
		//Return Error Statement
	}
}

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	if ((copy_u8PortId<4)&&((copy_u8PortDirection==DIO_PORT_INPUT)||(copy_u8PortDirection==DIO_PORT_OUTPUT)))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_INPUT:
				DDRA_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_OUTPUT:
				DDRA_REG=0XFF; //0b11111111
				break;
			}
			break;
			
			case DIO_PORTB:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_INPUT:
				DDRB_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_OUTPUT:
				DDRB_REG=0XFF; //0b11111111
				break;
			}
			break;
			
			case DIO_PORTC:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_INPUT:
				DDRC_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_OUTPUT:
				DDRC_REG=0XFF; //0b11111111
				break;
			}
			break;
			
			case DIO_PORTD:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_INPUT:
				DDRD_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_OUTPUT:
				DDRD_REG=0XFF; //0b11111111
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
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	if ((copy_u8PortId<4)&&((copy_u8PortValue==DIO_PORT_LOW)||(copy_u8PortValue==DIO_PORT_HIGH)))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PortValue)
			{
				case DIO_PORT_LOW:
				PORTA_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_HIGH:
				PORTA_REG=0XFF; //0b11111111
				break;
			}
			break;
			
			case DIO_PORTB:
			switch(copy_u8PortValue)
			{
				case DIO_PORT_LOW:
				PORTB_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_HIGH:
				PORTB_REG=0XFF; //0b11111111
				break;
			}
			break;
			
			case DIO_PORTC:
			switch(copy_u8PortValue)
			{
				case DIO_PORT_LOW:
				PORTC_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_HIGH:
				PORTC_REG=0XFF; //0b11111111
				break;
			}
			break;
			
			case DIO_PORTD:
			switch(copy_u8PortValue)
			{
				case DIO_PORT_LOW:
				PORTD_REG=0X00; //0b00000000
				break;
				
				case DIO_PORT_HIGH:
				PORTD_REG=0XFF; //0b11111111
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
void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	if ((copy_u8PortId<4)&&(copy_pu8PortValue != NULL))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			*copy_pu8PortValue = PINA_REG;
			break;
			
			case DIO_PORTB:
			*copy_pu8PortValue = PINB_REG;
			break;
			
			case DIO_PORTC:
			*copy_pu8PortValue = PINC_REG;
			break;
			
			case DIO_PORTD:
			*copy_pu8PortValue = PIND_REG;
			break;
		}
	} 
	else
	{
		//Return Error Statement
	}
}
void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	if (copy_u8PortId<4)
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			PORTA_REG^=0XFF; //0b11111111
			break;
			
			case DIO_PORTB:
			PORTB_REG^=0XFF; //0b11111111
			break;
			
			case DIO_PORTC:
			PORTC_REG^=0XFF; //0b11111111
			break;
			
			case DIO_PORTD:
			PORTD_REG^=0XFF; //0b11111111
			break;
		}
	} 
	else
	{
		//Return Error Statement
	}
}
void DIO_voidActiveIntPortPullUpResistance(u8 copy_u8PortId)
{
	if (copy_u8PortId<4)
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			PORTA_REG=0XFF; //0b11111111 
			break;
			
			case DIO_PORTB:
			PORTB_REG=0XFF; //0b11111111
			break;
			
			case DIO_PORTC:
			PORTC_REG=0XFF; //0b11111111
			break;
			
			case DIO_PORTD:
			PORTD_REG=0XFF; //0b11111111
			break;
		}
	} 
	else
	{
		//Return Error Statement
	}
}
