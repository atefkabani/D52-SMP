/*
 * LM35_interface.h
 *
 * Created: 6/30/2024 7:52:34 PM
 * Author :  D52
 */ 


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

									/***** APIS PROTOTYPES *****/
void LM35_voidInit (void);									
void LM35_voidGetTemp (u8 copy_u8FeedbackPin,u8* copy_pTemperature);


#endif /* LM35_INTERFACE_H_ */
