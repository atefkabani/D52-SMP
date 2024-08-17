/*
 * DIO_interface.h
 *
 * Created: 5/2/2024 1:17:35 PM
 *  Author :  D52
 */ 

#include "STD_TYPES.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_LOW    0 
#define DIO_PIN_HIGH   1

#define DIO_PORT_INPUT  0
#define DIO_PORT_OUTPUT 1

#define DIO_PORT_LOW    0
#define DIO_PORT_HIGH   1
										/*****PIN APIS PROTOTYPES (APPLICATION PROGRAM INTERFACE)*****/
										
void DIO_voidSetPinDirection           (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);
void DIO_voidSetPinValue               (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue);	
void DIO_voidGetPinValue               (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue);	
void DIO_voidTogglePinValue            (u8 copy_u8PortId, u8 copy_u8PinId);
void DIO_voidActiveIntPullUpResistance (u8 copy_u8PortId, u8 copy_u8PinId);

										/*****Port APIS PROTOTYPES (APPLICATION PROGRAM INTERFACE)*****/
								
void DIO_voidSetPortDirection              (u8 copy_u8PortId, u8 copy_u8PortDirection);
void DIO_voidSetPortValue                  (u8 copy_u8PortId, u8 copy_u8PortValue);
void DIO_voidGetPortValue                  (u8 copy_u8PortId, u8* copy_pu8PortValue);
void DIO_voidTogglePortValue               (u8 copy_u8PortId);
void DIO_voidActiveIntPortPullUpResistance (u8 copy_u8PortId);





#endif /* DIO_INTERFACE_H_ */
