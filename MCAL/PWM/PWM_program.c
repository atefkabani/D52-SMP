/*
 * PWM_program.c
 *
 * Created: 5/10/2024 2:21:45 PM
 *  Author :  D52
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "PWM_config.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_register.h"

void PWM0_voidInitChannel_0 (void)
{
	//Select Fast PWM0 Mode
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	//Choose Between (Inverting-Non Inverting)
	#if PWM0_MODE == PWM0_NON_INVERTING_MODE
    CLR_BIT(TCCR0_REG,COM00);
    SET_BIT(TCCR0_REG,COM01);
	
	#elif PWM0_MODE == PWM0_INVERTING_MODE
    SET_BIT(TCCR0_REG,COM00);
    SET_BIT(TCCR0_REG,COM01);	
	
#endif
	
	
}
void PWM0_voidGenerate_PWM_Channel_0 (u8 copy_u8DutyCycle)
{
	if (copy_u8DutyCycle <= 100)
	{
		OCR0_REG = ((u16)copy_u8DutyCycle*256)-1;
		
		#if PWM0_PRESCALER == PWM_NO_PRESCALER
		SET_BIT(TCCR0_REG ,CS00);
		CLR_BIT(TCCR0_REG ,CS01);
		CLR_BIT(TCCR0_REG ,CS02);
		
		#elif PWM0_PRESCALER == PWM_8_PRESCALER
		CLR_BIT(TCCR0_REG ,CS00);
		SET_BIT(TCCR0_REG ,CS01);
		CLR_BIT(TCCR0_REG ,CS02);
		
		#elif PWM0_PRESCALER == PWM_64_PRESCALER
		SET_BIT(TCCR0_REG ,CS00);
		SET_BIT(TCCR0_REG ,CS01);
		CLR_BIT(TCCR0_REG ,CS02);
		
		#elif PWM0_PRESCALER == PWM_256_PRESCALER
		CLR_BIT(TCCR0_REG ,CS00);
		CLR_BIT(TCCR0_REG ,CS01);
		SET_BIT(TCCR0_REG ,CS02);
		
		#elif PWM0_PRESCALER == PWM_1024_PRESCALER
		SET_BIT(TCCR0_REG ,CS00);
		CLR_BIT(TCCR0_REG ,CS01);
		SET_BIT(TCCR0_REG ,CS02);
		#endif
	} 
	else
	{
		//Return Error Statement 
	}
	
}

void PWM1_voidInitChannel_1A (void)
{
	//Select Fast PWM (Mode 14 From Data Sheet)
	CLR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);
	
	//Choose Between (Inverting-Non Inverting)
	#if PWM1_MODE == PWM1_NON_INVERTING_MODE
	CLR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
	
	#elif PWM1_MODE == PWM1_INVERTING_MODE
	SET_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);

#endif
	
}
void PWM1_voidGenerate_PWM_Channel_1A  (u16 copy_u16Frequency_hz, f32 copy_f32DutyCycle)
{
	if (copy_f32DutyCycle <= 100.0)
	{
		// under condition tick time 4 MS by setting prescaller 64
		ICR1_U16_REG = ((1000000UL/copy_u16Frequency_hz)/4)-1;
		
		OCR1A_U16_REG = (copy_f32DutyCycle*(ICR1_U16_REG+1)/100)-1;
		// select prescaller 64
		SET_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);
	} 
	else
	{
		//Return Error Statement
	}
	}
