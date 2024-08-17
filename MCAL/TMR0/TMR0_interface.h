/*
 * TMR0_interface.h
 *
 * Created: 5/10/2024 2:28:31 AM
 *  Author :  D52
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_
										/**********APIS PROTOTYPES**********/
void TMR0_voidInit                (void);
void TMR0_voidStart               (void);
void TMR0_voidStop                (void);
void TMR0_voidSetCallBackOVF      (void(*copy_pFunAction)(void));
void TMR0_voidSetCallBackCTC      (void(*copy_pFunAction)(void));
void TMR0_voidSetDelay_ms_UsingCTC(u16 copy_u16Delay_ms);


#endif /* TMR0_INTERFACE_H_ */
