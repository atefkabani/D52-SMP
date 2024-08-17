/*
 * UART_register.h
 *
 * Created: 5/18/2024 2:20:01 PM
 * Author :  D52
 */ 


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_
										/***** (UART REGISTERS) *****/
//USART I/O Data Register
#define UDR_REG      (*(volatile u8*)0x2C)

//USART Control and Status Register A
#define UCSRA_REG    (*(volatile u8*)0x2B)
#define RXC          7 //USART Receive Complete
#define TXC          6 //USART Transmit Complete
#define UDRE         5 //USART Data Register Empty
#define FE           4 //Frame Error
#define DOR          3 //Data OverRun
#define PE           2 //Parity Error
#define U2X          1 //Double the USART Transmission Speed
#define MPCM0 //Multi-processor Communication Mode

//USART Control and Status Register B
#define UCSRB_REG    (*(volatile u8*)0x2A)
#define RXCIE        7 //RX Complete Interrupt Enable
#define TXCIE        6 //TX Complete Interrupt Enable
#define UDRIE        5 //USART Data Register Empty Interrupt Enable
#define RXEN         4 //Receiver Enable
#define TXEN         3 //Transmitter Enable
#define UCSZ2        2 //Character Size
#define RXB8         1 //Receive Data Bit 8
#define TXB8         0 //Transmit Data Bit 8

//USART Control and Status Register C
#define UCSRC_REG    (*(volatile u8*)0x40)
#define URSEL        7
#define UMSEL        6
#define UPM1         5
#define UPM0         4
#define USBS         3
#define UCSZ1        2
#define UCSZ0        1
#define UCPOL        0

// USART Baud Rate Registers
#define UBRRL_REG    (*(volatile u8*)0x29)
#define UBRRH_REG    (*(volatile u8*)0x40)

#endif /* UART_REGISTER_H_ */
