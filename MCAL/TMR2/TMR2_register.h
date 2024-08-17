/*
 * TMR2_register.h
 *
 *  Created on: May 4, 2024
 *      Author: AtefAlkabani
 */

#ifndef MCAL_TMR2_TMR2_REGISTER_H_
#define MCAL_TMR2_TMR2_REGISTER_H_

//Timer/Counter Control Register
#define TCCR2_REG 		(*(volatile u8*) 0x45)
#define TCCR2_FOC2 			7
#define TCCR2_WGM20 		6
#define TCCR2_COM21 		5
#define TCCR2_COM20 		4
#define TCCR2_WGM21 		3
#define TCCR2_CS22 			2
#define TCCR2_CS21 			1
#define TCCR2_CS20			0
//Timer/Counter  Interrupt Mask Register
#define TIMSK_REG 		(*(volatile u8*) 0x59)
#define TIMSK_TOIE2		 	6
#define TIMSK_OCIE2		 	7


//Timer/Counter Register
#define TCNT2_REG 			(*(volatile u8*) 0x44)
#define OCR2_REG 			(*(volatile u8*) 0x43)

//Timer/Counter Interrupt Flag Register
#define TIFR_REG 			(*(volatile u8*) 0x58)
#define TIFR_OCF2 			7
#define TIFR_TOV2			6

#endif /* MCAL_TMR2_TMR2_REGISTER_H_ */
