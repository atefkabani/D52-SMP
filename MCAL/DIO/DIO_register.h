/*
 * DIO_register.h
 *
 * Created: 5/2/2024 1:17:48 PM
 *  Author :  D52
 */ 


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
										/***** DIO Registers *****/
//Data Direction Registers (DDR)
#define DDRA_REG  (*(volatile u8*)0X3A)
#define DDRB_REG  (*(volatile u8*)0X37)
#define DDRC_REG  (*(volatile u8*)0X34)
#define DDRD_REG  (*(volatile u8*)0X31)

//Input Registers (PIN)
#define PINA_REG  (*(volatile u8*)0X39)
#define PINB_REG  (*(volatile u8*)0X36)
#define PINC_REG  (*(volatile u8*)0X33)
#define PIND_REG  (*(volatile u8*)0X30)

//Output Registers (PORT)
#define PORTA_REG  (*(volatile u8*)0X3B)
#define PORTB_REG  (*(volatile u8*)0X38)
#define PORTC_REG  (*(volatile u8*)0X35)
#define PORTD_REG  (*(volatile u8*)0X32)

#endif /* DIO_REGISTER_H_ */
