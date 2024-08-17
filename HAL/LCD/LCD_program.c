/*
 * LCD_program.c
 *
 * Created: 6/16/2024 2:55:02 PM
 *  Author :  D52
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
/**UTILES_LIB**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**MCAL**/
#include "DIO_interface.h"
/**HAL**/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_voidInit (void)
{
	//Initialize LCD Pins As Output Pins
	DIO_voidSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	
	_delay_ms(35);
	//Set RS = 0 (Command)
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	//Set RW = 0 (Write)
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	//Write The Most 4-Bits Of Command On Data Pins
	PRV_voidWriteHalfPort(0b0010);
	
	//Enable Pulse (H => L)
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	 LCD_voidSendCommand(0b00101000);
	 _delay_us(45);
	 
	 //Display On/Off Control (Display=>On, Crusor=>Off, Blink=>Off)
	 LCD_voidSendCommand(0b00001100);
	  _delay_us(45);

	 //Display Clear 
	 LCD_voidSendCommand(0b00000001);
	 _delay_ms(2);
	 
	 //Entry Mode Set (Increment=>On, Shift=>Off)
	 LCD_voidSendCommand(0b00000110);
	 _delay_ms(10);
}
void LCD_voidSendCommand (u8 copy_u8Cmd)
{
	//Set RS = 0 (Command)
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
	//Set RW = 0 (Write)
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	//Write Most 4-Bits Of The Command On Data Pins
	PRV_voidWriteHalfPort(copy_u8Cmd>>4);
	
	//Enable Pulse (H => L)
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	//Write Least 4-Bits Of The Command On Data Pins
	PRV_voidWriteHalfPort(copy_u8Cmd);
	
	//Enable Pulse (H => L)
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
}
void LCD_voidDisplayChar (u8 copy_u8Char)
{
	//Set RS = 1 (Data)
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
	//Set RW = 0 (Write)
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	//Write Most 4-Bits Of The Command On Data Pins
	PRV_voidWriteHalfPort(copy_u8Char>>4);
	
	//Enable Pulse (H => L)
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	//Write Least 4-Bits Of The Command On Data Pins
	PRV_voidWriteHalfPort(copy_u8Char);
	
	//Enable Pulse (H => L)
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
}
void LCD_voidDisplayString (u8* copy_pu8String)
{
	if (copy_pu8String != NULL)
	{
		u8 local_u8Counter=0;
		while(copy_pu8String[local_u8Counter] != '\0')
		{
			LCD_voidDisplayChar(copy_pu8String[local_u8Counter]);
			local_u8Counter++;
		}
	} 
	else
	{
		//Return Error Statement
	}
}
void LCD_voidDisplayNumber(u32 copy_u32Number)
{
	u32 local_u32ReversedNumber=1;
	
	if(copy_u32Number == 0)
	{
		LCD_voidDisplayChar('0');
	}
	else
	{
		// Reverse The Number
		while(copy_u32Number != 0)
		{
			local_u32ReversedNumber = local_u32ReversedNumber*10+(copy_u32Number%10);
			copy_u32Number /= 10;
		}
		
		do
		{
			LCD_voidDisplayChar((local_u32ReversedNumber%10)+'0');
			local_u32ReversedNumber /= 10;
		} while (local_u32ReversedNumber != 1);
	}
}
void LCD_voidClear(void)
{
	//Display Clear
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}

void LCD_voidShift               (u8 copy_u8ShifttingDirection)
{
	switch(copy_u8ShifttingDirection)
	{
		case LCD_SHIFT_RIGHT:
		LCD_voidSendCommand(0b00011100);
		_delay_ms(10);
		break;
		case LCD_SHIFT_LEFT:
		LCD_voidSendCommand(0b00011000);
		_delay_ms(10);
		break;
	}
}
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position)
{
	switch(copy_u8LineNumber)
	{
		case LCD_LINE_ONE:
		LCD_voidSendCommand(0x80 + copy_u8Position);
		break;
		
		case LCD_LINE_TWO:
		LCD_voidSendCommand(0xC0 + copy_u8Position);
	}
		
}

static void PRV_voidWriteHalfPort(u8 copy_u8Value)
{
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Value,0));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Value,1));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Value,2));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Value,3));

}
