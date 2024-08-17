/*
 * UART_program.c
 *
 * Created: 5/18/2024 2:19:37 PM
 * Author :  D52
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_interface.h"
#include "UART_register.h"


void UART_voidInit(void)
{
	// Set Buad Rate = 9600
	CLR_BIT(UCSRA_REG, U2X);
	UBRRL_REG = 103;
	
	// writing on UCSRC
	// select UART MODE = Asynchronous
	// configure no parity
	// configure stop bits = 1
	// configure data bits = 8
	// configure no polarity
	CLR_BIT(UCSRB_REG, UCSZ2);
	UCSRC_REG = 0x86; //0b10000110;
	
	//Enable Tx
	SET_BIT(UCSRB_REG, TXEN);
	
	//Enable Rx
	SET_BIT(UCSRB_REG, RXEN);
}


void UART_voidTxChar(u8 copy_u8TxData)
{
	UDR_REG = copy_u8TxData;
	while(0 == GET_BIT(UCSRA_REG, UDRE));
}

void UART_voidTxString (u8* copy_pu8TxString){
	if (copy_pu8TxString != NULL)
	{
		u8 local_u8Counter=0;
		while(copy_pu8TxString[local_u8Counter] != 0)
		{
			UART_voidTxChar(copy_pu8TxString[local_u8Counter]);
			local_u8Counter++;
		}
		UART_voidTxNewLine();
	} 

}




void UART_voidTxNumber(u8 copy_u8Number)
{
	u8 local_u32ReversedNumber=1;

	if(copy_u8Number == 0)
	{
		UART_voidTxChar('0');
	}
	else
	{
		// Reverse The Number
		while(copy_u8Number != 0)
		{
			local_u32ReversedNumber = local_u32ReversedNumber*10+(copy_u8Number%10);
			copy_u8Number /= 10;
		}

		do
		{
			UART_voidTxChar((local_u32ReversedNumber%10)+'0');
			local_u32ReversedNumber /= 10;
		} while (local_u32ReversedNumber != 1);
	}
}
void UART_voidTxNewLine(){

	UART_voidTxChar(13);
	UART_voidTxChar(10);
}

void UART_voidRxChar(u8* copy_pu8RxData)
{
	if(copy_pu8RxData!=NULL)
	{
		while(0 == GET_BIT(UCSRA_REG, RXC));
		{
			*copy_pu8RxData = UDR_REG;
		}
	}
	else
	{
		//return Error State
	}
}
