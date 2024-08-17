/*
 * LCD_config.h
 *
 * Created: 6/16/2024 2:55:35 PM
 *  Author :  D52
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Macros For RS Configuration*/
#define LCD_RS_PORT  DIO_PORTB
#define LCD_RS_PIN   DIO_PIN5

/*Macros For RW Configuration*/
#define LCD_RW_PORT  DIO_PORTB
#define LCD_RW_PIN   DIO_PIN6

/*Macros For Enable Configuration*/
#define LCD_E_PORT  DIO_PORTB
#define LCD_E_PIN   DIO_PIN7

/*Macros For 4-Bit Configuration*/
#define LCD_D4_PORT  DIO_PORTA
#define LCD_D4_PIN   DIO_PIN4

#define LCD_D5_PORT  DIO_PORTA
#define LCD_D5_PIN   DIO_PIN5

#define LCD_D6_PORT  DIO_PORTA
#define LCD_D6_PIN   DIO_PIN6

#define LCD_D7_PORT  DIO_PORTA
#define LCD_D7_PIN   DIO_PIN7


#endif /* LCD_CONFIG_H_ */
