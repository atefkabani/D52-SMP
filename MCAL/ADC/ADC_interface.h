/*
 * ADC_interface.h
 *
 * Created: 4/27/2024 3:33:49 PM
 *  Author :  D52
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* Macros for Channel Number as Single Ended Input */
#define ADC_CHANNEL0   0
#define ADC_CHANNEL1   1
#define ADC_CHANNEL2   2
#define ADC_CHANNEL3   3
#define ADC_CHANNEL4   4
#define ADC_CHANNEL5   5
#define ADC_CHANNEL6   6
#define ADC_CHANNEL7   7

/* Macros For Refernce_Voltage */
#define ADC_REFERENCE_AVCC          1
#define ADC_REFERENCE_AREF          2
#define ADC_REFERENCE_INTERNAL      3
										/********** APIS PROTOTYPES **********/
										
void ADC_voidInit            (u8 copy_u8ReferenceVoltage);
void ADC_voidGetDigiatlValue (u8 copy_u8ChannelNumber, u16* copy_pu16DigitalValue);



#endif /* ADC_INTERFACE_H_ */
