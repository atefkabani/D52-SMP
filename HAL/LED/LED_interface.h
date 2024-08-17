/*
 * LED_interface.h
 *
 * Created: 4/10/2024 6:06:10 PM
 *  Author :  D52
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_FORWARD_CONNECTION 1
#define LED_REVERSE_CONNECTION 2

void LED_voidInit       (u8 copy_u8LedPortId, u8 copy_u8LedPinId);
void LED_voidLedOn      (u8 copy_u8LedPortId, u8 copy_u8LedPinId, u8 copy_u8LedConnectionType);
void LED_voidLedOff     (u8 copy_u8LedPortId, u8 copy_u8LedPinId, u8 copy_u8LedConnectionType);
void LED_voidLedToggle  (u8 copy_u8LedPortId, u8 copy_u8LedPinId);
				    
#endif /* LED_INTERFACE_H_ */
