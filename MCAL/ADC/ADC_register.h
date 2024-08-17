/*
 * ADC_register.h
 *
 * Created: 4/27/2024 3:33:35 PM
 *  Author :  D52
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
										/********** ADC Registers & Pins **********/
										
/* (ADC Multiplexer Selection Register) */
#define ADMUX_REG  (*(volatile u8*)0X27)
//ADMUX_REG Pins
#define REFS1    7  //Reference Selection Bit
#define REFS0    6  //Reference Selection Bit
#define ADLAR    5  //ADC Left Adjust Result
//Channel And Gain Selection Bit
#define MUX4     4  
#define MUX3     3
#define MUX2     2
#define MUX1     1
#define MUX0     0

/* (ADC Control & Status Register) */
#define ADCSRA_REG (*(volatile u8*)0X26)
//ADCSR_REG Pins
#define ADEN     7  //ADC Enable
#define ADSC     6  //ADC Start Conversion
#define ADATE    5  //ADC Auto Trigger Enable
#define ADIF     4  //ADC Interrupt Flag
#define ADIE     3  //ADC Interrupt Enable
//ADC Prescaler Select Bits
#define ADPS2    2  
#define ADPS1    1
#define ADPS0    0

/* (ADC Data Register) */
#define ADC_u16_REG  (*(volatile u16*)0X24)     /* ADCL=>0X24
                                                  ADCH=>0X25 */
/* (Special Function IO Register) */
#define SFIOR_REG  (*(volatile u8*)0X50)
//SFIOR_REG Pins (ADTS => AutoTrigger Source)
#define ADTS2   7 
#define ADTS1   6
#define ADTS0   5
#define RES_BIT 4 //Must be Zero When SFIOR Is Written





#endif /* ADC_REGISTER_H_ */
