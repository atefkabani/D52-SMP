/*
 * RELAY_program.c
 *
 * Created: 7/2/2024 9:23:20 PM
 *  Author :  D52
 */ 

/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*HAL*/
#include "RELAY_config.h"
#include "RELAY_interface.h"
/*MCAL*/
#include "DIO_interface.h"

void RELAY_voidInit (void)
{
	DIO_voidSetPinDirection(RELAY_COIL_PORT,RELAY_COIL_PIN,DIO_PIN_OUTPUT);
}
void RELAY_voidOn   (void)
{
	DIO_voidSetPinValue(RELAY_COIL_PORT,RELAY_COIL_PIN,DIO_PIN_HIGH);
}
void RELAY_voidOff  (void)
{
	DIO_voidSetPinValue(RELAY_COIL_PORT,RELAY_COIL_PIN,DIO_PIN_LOW);
}
