/*
 * KPD_program.c
 *
 * Created: 4/19/2024 3:15:06 PM
 *  Author :  D52
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"


void KPD_voidInit(void)
{
	// Initialize KPD COLS pins As OutPut Pins
	DIO_voidSetPinDirection(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_OUTPUT);
	
	// Initialize KPD COLS pins As High Pins
	DIO_voidSetPinValue(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_HIGH);
	
	
	// Initialize KPD ROWS pins As Input Pins
	DIO_voidSetPinDirection(KPD_ROW0_PORT, KPD_ROW0_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW1_PORT, KPD_ROW1_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW2_PORT, KPD_ROW2_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW3_PORT, KPD_ROW3_PIN, DIO_PIN_INPUT);
	
	// Active KPD ROWS pins Internal pull up
	DIO_voidActiveIntPullUpResistance(KPD_ROW0_PORT, KPD_ROW0_PIN);
	DIO_voidActiveIntPullUpResistance(KPD_ROW1_PORT, KPD_ROW1_PIN);
	DIO_voidActiveIntPullUpResistance(KPD_ROW2_PORT, KPD_ROW2_PIN);
	DIO_voidActiveIntPullUpResistance(KPD_ROW3_PORT, KPD_ROW3_PIN);
}


void KPD_voidGetValue(u8* copy_pu8ReturnedValue)
{
	if(copy_pu8ReturnedValue!=NULL)
	{
		* copy_pu8ReturnedValue = KPD_NOT_PRESSED;
		
		u8 local_u8ColsPorts[3] = {KPD_COL0_PORT, KPD_COL1_PORT, KPD_COL2_PORT};
		u8 local_u8ColsPins[3]  = {KPD_COL0_PIN,  KPD_COL1_PIN,  KPD_COL2_PIN};
		
		u8 local_u8RowsPorts[4] = {KPD_ROW0_PORT, KPD_ROW1_PORT, KPD_ROW2_PORT, KPD_ROW3_PORT};
		u8 local_u8RowsPins[4]  = {KPD_ROW0_PIN,  KPD_ROW1_PIN,  KPD_ROW2_PIN,  KPD_ROW3_PIN};
		
	    u8 local_u8Keys[4][3]   = KPD_KEYS;
		
		u8 local_u8ColsCounter,local_u8RowsCounter;
		u8 local_u8PinValue;
		
		for(local_u8ColsCounter=0; local_u8ColsCounter<3; local_u8ColsCounter++)
		{
			//Activate Each Column
			DIO_voidSetPinValue(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], DIO_PIN_LOW);
			
			/*switch(local_u8ColsCounter)
			{
				case 0: DIO_voidSetPinValue(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_LOW); break;
				case 1: DIO_voidSetPinValue(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_LOW); break;	
				case 2: DIO_voidSetPinValue(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_LOW); break;
				case 3: DIO_voidSetPinValue(KPD_COL3_PORT, KPD_COL3_PIN, DIO_PIN_LOW); break;
			}*/
			
			
			for(local_u8RowsCounter=0; local_u8RowsCounter<4; local_u8RowsCounter++)
			{
				//Check Each Row
				DIO_voidGetPinValue(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter], &local_u8PinValue);
				
				//Is Pressed?
				if(0 == local_u8PinValue) 
				{
					while(0 == local_u8PinValue)
					{
						DIO_voidGetPinValue(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter], &local_u8PinValue);
					}
					
					*copy_pu8ReturnedValue = local_u8Keys[local_u8RowsCounter][local_u8ColsCounter];
					return;
				}
			}
			
			//Deactivate Current Coloumn
			DIO_voidSetPinValue(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], DIO_PIN_HIGH);
		}
	}
	else 
	{
		// return Error State
	}
}
