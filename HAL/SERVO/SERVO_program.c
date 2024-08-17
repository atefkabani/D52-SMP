/*
 * SERVO_program.c
 *
 *  Created on: May 13, 2024
 *  Author :  D52
 */

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM_interface.h"
#include "DIO_interface.h"

/* HAL */
#include "SERVO_interface.h"
#include "SERVO_config.h"


void SERVO_voidInit()
{
	DIO_voidSetPinDirection(SERVO_PORT, SERVO_PIN, DIO_PIN_OUTPUT);
	PWM1_voidInitChannel_1A();

}

void SERVO_voidRotate0_180(u8 copy_u8Angle)
{

	PWM1_voidGenerate_PWM_Channel_1A(50,((f32)copy_u8Angle/36)+5 );
	//PWM1_voidGenerate_PWM_Channel_1A(50,5 );
}
