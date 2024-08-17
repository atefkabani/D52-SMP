/*
 * GI_register.h
 *
 * Created: 4/23/2024 5:58:35 PM
 *  Author :  D52
 */ 


#ifndef GI_REGISTER_H_
#define GI_REGISTER_H_
										/* Global Interrupt Register & Pins Configuration */
										
//SREG ==> AVR Status Register
#define SREG_REG    (*(volatile u8*)0x5F) 
//Global Interrupt Enable Bit (7)								
#define I           7



#endif /* GI_REGISTER_H_ */
