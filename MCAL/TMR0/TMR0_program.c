/*
 * TMR0_program.c
 *
 * Created: 5/10/2024 2:28:15 AM
 *  Author :  D52
 */ 

/***UTILES_LIB***/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***MCAL***/
#include "TMR0_config.h"
#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_register.h"

static void (*PRV_pFunCallBackOVF)(void) = NULL;
static void (*PRV_pFunCallBackCTC)(void) = NULL;
static u16 PRV_u16ctcCounter;

void TMR0_voidInit (void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
	//Select Normal Mode
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	//Enable Overflow Interrupt
	SET_BIT(TIMSK_REG,TOIE0);
	//Set Preload Value
	TCNT0_REG = TMR0_PRELOAD_VALUE;
	
	#elif TMR0_MODE == TMR0_CTC_MODE
	//Select CTC Mode
	CLR_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	//Enable OC Interrupt
	SET_BIT(TIMSK_REG,OCIE0);
	//Init Timer With Output Compare Value
	OCR0_REG = TMR0_COMPARE_VALUE;
	#endif
	
}
void TMR0_voidStart (void)
{
	#if   TMR0_PRESCALER_VALUE == TMR0_NO_PRESCALER
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
	
	#elif TMR0_PRESCALER_VALUE == TMR0_8_PRESCALER
	CLR_BIT(TCCR0_REG,CS00);
	SET_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
	
	#elif TMR0_PRESCALER_VALUE == TMR0_64_PRESCALER
	SET_BIT(TCCR0_REG,CS00);
	SET_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
	
	#elif TMR0_PRESCALER_VALUE == TMR0_256_PRESCALER
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
	
	#elif TMR0_PRESCALER_VALUE == TMR0_1024_PRESCALER
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
#endif
	
	
}
void TMR0_voidStop (void)
{
	//No Clock Source (Timer/Counter Stopped)
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}
void TMR0_voidSetDelay_ms_UsingCTC(u16 copy_u16Delay_ms)
{
	//Under Condition TickTime = 4us
	OCR0_REG = TMR0_COMPARE_VALUE;
	copy_u16Delay_ms = PRV_u16ctcCounter;
}

void TMR0_voidSetCallBackOVF      (void(*copy_pFunAction)(void))
{
	if (copy_pFunAction !=NULL)
	{
		PRV_pFunCallBackOVF = copy_pFunAction;
	} 
	else
	{
		//Return Error Statement
	}
}
void TMR0_voidSetCallBackCTC      (void(*copy_pFunAction)(void))
{
	if (copy_pFunAction != NULL)
	{
		PRV_pFunCallBackCTC = copy_pFunAction;
	} 
	else
	{
		//Return Error Statement
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16ctcCounter=0;
	local_u16ctcCounter++;
	if (local_u16ctcCounter = PRV_u16ctcCounter)
	{
		//Clear Counter
		local_u16ctcCounter = 0;
		//Call Action
		PRV_pFunCallBackCTC();
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16OVFCounter=0;
	local_u16OVFCounter++;
	if (local_u16OVFCounter == TMR0_OVER_FLOW_COUNTER)
	{
		//Init Timer With Preload Value 
		TCNT0_REG = TMR0_PRELOAD_VALUE;
		//Reset Counter
		local_u16OVFCounter = 0;
		//Call Action
		PRV_pFunCallBackOVF();
	}
}
