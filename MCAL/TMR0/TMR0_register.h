/*
 * TMR0_register.h
 *
 * Created: 5/10/2024 2:28:44 AM
 *  Author :  D52
 */ 


#ifndef TMR0_REGISTER_H_
#define TMR0_REGISTER_H_

//Timer/Counter Control Register
#define TCCR0_REG    (*(volatile u8*)0X53)
#define FOC0         7
#define WGM00        6
#define COM01        5
#define COM00        4
#define WGM01        3
#define CS02         2
#define CS01         1
#define CS00         0
//Timer/Counter Register
#define TCNT0_REG    (*(volatile u8*)0X52)
//Output Compare Register
#define OCR0_REG     (*(volatile u8*)0X5C)
//Timer/Counter Interrupt Mask Register
#define TIMSK_REG    (*(volatile u8*)0X59)
#define OCIE0        1
#define TOIE0        0
//Timer/Counter Interrupt Flag Register
#define TIFR_REG     (*(volatile u8*)0X58)
#define OCF0         1
#define TOV0         0



#endif /* TMR0_REGISTER_H_ */
