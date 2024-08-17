/*
 * BUZZER_interface.h
 *
 * Created: 4/11/2024 5:38:57 PM
 *  Author :  D52
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

void BUZZER_voidInit   (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);
void BUZZER_voidOn     (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);
void BUZZER_voidOff    (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);
void BUZZER_voidToggle (u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);





#endif /* BUZZER_INTERFACE_H_ */
