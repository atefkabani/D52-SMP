/*
 * LCD_interface.h
 *
 * Created: 6/16/2024 2:55:26 PM
 *  Author :  D52
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_SHIFT_RIGHT 1
#define LCD_SHIFT_LEFT  2

#define LCD_LINE_ONE    1
#define LCD_LINE_TWO    2


								/***** APIS PROTOTYPES *****/
								
void LCD_voidInit                (void);
void LCD_voidSendCommand         (u8 copy_u8Cmd);
void LCD_voidDisplayChar         (u8 copy_u8Char);
void LCD_voidDisplayString       (u8* copy_pu8String);
void LCD_voidDisplayNumber       (u32 copy_u32Number);
void LCD_voidClear               (void);
void LCD_voidShift               (u8 copy_u8ShifttingDirection); // DATA SHEET
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position); // DATA SHEET


#endif /* LCD_INTERFACE_H_ */
