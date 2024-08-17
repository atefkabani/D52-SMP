/*
 * TMR2_interface.h
 *
 *  Created on: May 4, 2024
 *      Author: AtefAlkabani
 */

#ifndef MCAL_TMR2_TMR2_INTERFACE_H_
#define MCAL_TMR2_TMR2_INTERFACE_H_

typedef enum {
	TMR2_Prescaler_0  ,
	TMR2_Prescaler_1  ,
	TMR2_Prescaler_8 ,
	TMR2_Prescaler_32  ,
	TMR2_Prescaler_64 ,
	TMR2_Prescaler_128,
	TMR2_Prescaler_256,
	TMR2_Prescaler_1024

}TMR2_ClockSelect_t;

typedef enum{
	TMR2_Normal_mode ,
	TMR2_PWM_mode,
	TMR2_CTC_mode,
	TMR2_Fast_PWM_mode
}TMR2_Timer2Mode_t;

void TMR2_voidInit(TMR2_Timer2Mode_t copy_tTimer2Mode  ,TMR2_ClockSelect_t copy_tClockSelect);

void TMR2_voidStart(void);
void TMR2_voidStop(void);
void TMR2_voidSetCallBackOVR(void (*copy_pFunAction)(void));
void TMR2_voidSetCallBackCTC(void (*copy_pFunAction)(void));
void TMR2_voidSetDelay_ms_CTC(u16 copy_u16DelayTime_ms);
void TMR2_voidSetDelay_ms_OVR(u16 copy_u16DelayTime_ms);


#endif /* MCAL_TMR2_TMR2_INTERFACE_H_ */
