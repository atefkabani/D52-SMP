/*
 * TMR2_program.c
 *
 *  Created on: May 4, 2024
 *      Author: AtefAlkabani
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* MCAL */
#include "TMR2_interface.h"
#include "TMR2_register.h"
#include "TMR2_config.h"

static void (*PRV_pFunCallBackOVR)(void) = NULL;
static void (*PRV_pFunCallBackCTC)(void) = NULL;

static u16 PRV_u16No_Of_Interrupts_CTC = 0;
static u8 PRV_u8PreloadValue = 0;
static u16 PRV_u16NoOfOVF = 0;
static TMR2_ClockSelect_t PRV_tClockSelect;

void TMR2_voidInit(TMR2_Timer2Mode_t copy_tTimer2Mode,
		TMR2_ClockSelect_t copy_tClockSelect) {
	PRV_tClockSelect = copy_tClockSelect;

	//Waveform Generation Mode
	switch (copy_tTimer2Mode) {
	case TMR2_Normal_mode:
		CLR_BIT(TCCR2_REG, TCCR2_WGM20);
		CLR_BIT(TCCR2_REG, TCCR2_WGM21);

		//Timer/Counter0 Overflow Interrupt Enable
		SET_BIT(TIMSK_REG, TIMSK_TOIE2);

		break;
	case TMR2_PWM_mode:
		SET_BIT(TCCR2_REG, TCCR2_WGM20);
		CLR_BIT(TCCR2_REG, TCCR2_WGM21);
		break;
	case TMR2_CTC_mode:
		CLR_BIT(TCCR2_REG, TCCR2_WGM20);
		SET_BIT(TCCR2_REG, TCCR2_WGM21);

		//Timer/Counter0 CTC Interrupt Enable
		SET_BIT(TIMSK_REG, TIMSK_OCIE2);

		//SET Output Compare
		OCR2_REG = TMR2_COMPARE_VALUE;

		break;
	case TMR2_Fast_PWM_mode:
		SET_BIT(TCCR2_REG, TCCR2_WGM20);
		SET_BIT(TCCR2_REG, TCCR2_WGM21);
		break;
	}

}

void TMR2_voidStart(void) {

//Clock Select
	TCCR2_REG &= 0xF8;

	TCCR2_REG |= PRV_tClockSelect;

}

void TMR2_voidStop(void) {
	//Timer/Counter0 Overflow Interrupt Disable
	CLR_BIT(TIMSK_REG, TIMSK_TOIE2);
	CLR_BIT(TIMSK_REG, TIMSK_OCIE2);

	//Clock Select
	TCCR2_REG &= 0xF8;

}

void TMR2_voidSetDelay_ms_OVR(u16 copy_u16DelayTime_ms) {
	if (PRV_tClockSelect != 0 && copy_u16DelayTime_ms != 0) {

		f32 Noofoverflow = 0;
		switch (PRV_tClockSelect) {
		case TMR2_Prescaler_0:

			break;
		case TMR2_Prescaler_1:
			Noofoverflow = F_CPU_KHZ;
			break;
		case TMR2_Prescaler_8:
			Noofoverflow = F_CPU_KHZ / 8;
			break;
		case TMR2_Prescaler_32:
			Noofoverflow = F_CPU_KHZ / 32;
			break;
		case TMR2_Prescaler_64:
			Noofoverflow = F_CPU_KHZ / 64;
			break;
		case TMR2_Prescaler_128:
			Noofoverflow = F_CPU_KHZ / 128;
			break;
		case TMR2_Prescaler_256:
			Noofoverflow = F_CPU_KHZ / 256;
			break;
		case TMR2_Prescaler_1024:
			Noofoverflow = F_CPU_KHZ / 1024;
			break;
		}
		Noofoverflow = (copy_u16DelayTime_ms * Noofoverflow) / (TMR2_OVF_MAX);

		PRV_u16NoOfOVF = Noofoverflow;
		PRV_u8PreloadValue = (1 - Noofoverflow + PRV_u16NoOfOVF) * TMR2_OVF_MAX;

		PRV_u16NoOfOVF++;

		//Set Preload
		TCNT2_REG = PRV_u8PreloadValue;
	}
}
void TMR2_voidSetDelay_ms_CTC(u16 copy_u16DelayTime_ms) {
	switch (PRV_tClockSelect) {
		case TMR2_Prescaler_0:
				PRV_u16No_Of_Interrupts_CTC = 0;
				break;
		case TMR2_Prescaler_1:
			PRV_u16No_Of_Interrupts_CTC = F_CPU_KHZ;
			break;
		case TMR2_Prescaler_8:
			PRV_u16No_Of_Interrupts_CTC = (F_CPU_KHZ / 8);
			break;
		case TMR2_Prescaler_32:
			PRV_u16No_Of_Interrupts_CTC = (F_CPU_KHZ / 32);
			break;
		case TMR2_Prescaler_64:
			PRV_u16No_Of_Interrupts_CTC = (F_CPU_KHZ / 64);
			break;
		case TMR2_Prescaler_128:
			PRV_u16No_Of_Interrupts_CTC = (F_CPU_KHZ / 128);
			break;
		case TMR2_Prescaler_256:
			PRV_u16No_Of_Interrupts_CTC = (F_CPU_KHZ / 256);
			break;
		case TMR2_Prescaler_1024:
			PRV_u16No_Of_Interrupts_CTC = (F_CPU_KHZ / 1024);
			break;
		}

		PRV_u16No_Of_Interrupts_CTC /= (TMR2_COMPARE_VALUE + 1);

		PRV_u16No_Of_Interrupts_CTC *= copy_u16DelayTime_ms;

}

void TMR2_voidSetCallBackOVR(void (*copy_pFunAction)(void)) {
	if (copy_pFunAction != NULL) {
		PRV_pFunCallBackOVR = copy_pFunAction;
	}
}

void TMR2_voidSetCallBackCTC(void (*copy_pFunAction)(void)) {
	if (copy_pFunAction != NULL) {
		PRV_pFunCallBackCTC = copy_pFunAction;
	}
}

//Overflow ISR
void __vector_5(void) __attribute__ ((signal));
void __vector_5(void) {
	static u16 local_u16OVFCounter = 0;
	if (PRV_pFunCallBackOVR != NULL)

		//Increase Counter
		local_u16OVFCounter++;
	if (local_u16OVFCounter == PRV_u16NoOfOVF) {
		//set Preload Value
		TCNT2_REG = PRV_u8PreloadValue;

		//Reset Counter
		local_u16OVFCounter = 0;

		//Call Function in Main
		PRV_pFunCallBackOVR();
	}
}

//CTC ISR
void __vector_4(void) __attribute__ ((signal));
void __vector_4(void) {
	static u16 counter = 0;
	if (PRV_pFunCallBackCTC != NULL)

		counter++;
	if (counter == PRV_u16No_Of_Interrupts_CTC) {

		counter = 0;

		PRV_pFunCallBackCTC();
	}
}

