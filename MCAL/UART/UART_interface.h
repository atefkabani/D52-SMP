/*
 * UART_interface.h
 *
 * Created: 5/18/2024 2:19:49 PM
 *  Author :  D52
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
										/*****APIS PROTOTYPES*****/
void UART_voidInit     (void);
void UART_voidTxChar   (u8  copy_u8TxData);
void UART_voidRxChar   (u8* copy_pu8RxData);
void UART_voidTxString (u8* copy_pu8TxString);
void UART_voidRxString (u8* copy_pu8RxString);
void UART_voidTxNewLine();
void UART_voidTxNumber(u8 copy_u8Number);

#endif /* UART_INTERFACE_H_ */
