/*
 * PWM0_register.h
 *
 * Created: 5/10/2024 2:22:15 PM
 *  Author :  D52
 */ 


#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_
										
										/*TMR0 REGISTERS*/
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

										/*TMR1 REGISTERS*/
//Timer/counter1 Control Register A
#define TCCR1A_REG   (*(volatile u8*)0X4F)
#define COM1A1       7
#define COM1A0       6
#define COM1B1       5
#define COM1B0       4
#define FOC1A        3
#define FOC1B        2
#define WGM11        1
#define WGM10        0
//Timer/Counter1 Control Register B
#define TCCR1B_REG   (*(volatile u8*)0X4E)
#define ICNC1        7
#define ICES1        6
#define WGM13        4
#define	WGM12        3
#define CS12         2
#define CS11         1
#define CS10         0
//Timer/Counter 1
#define TCNT1_U16_REG  (*(volatile u16*)0X4C)
//Output Compare Register 1A
#define OCR1A_U16_REG  (*(volatile u16*)0X4A)
//Output Compare Register 1B
#define OCR1B_U16_REG  (*(volatile u16*)0X48)
//Input Capture Register 1
#define ICR1_U16_REG   (*(volatile u16*)0X46)
//Timer/Counter Interrupt Mask Register
#define TIMSK_REG      (*(volatile u8*)0X59)
#define TICIE1         5
#define OCIE1A         4
#define OCIE1B         3
#define TOIE1          2
//Timer/Counter Interrupt Flag Register
#define TIFR_REG       (*(volatile u8*)0X58)
#define ICF1           5
#define OCF1A          4
#define OCF1B          3
#define TOV1           2

#endif /* PWM_REGISTER_H_ */
