/*
 * DCM_interface.h
 *
 * Created: 5/11/2024 1:20:23 PM
 *  Author :  D52
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define DCM1    0
#define DCM2    1

#define DCM_CW   1
#define DCM_CCW  2



										/***** APIS PROTOTYPES *****/
										
void DCM_voidInit              (u8 copy_u8DCM_ID);
void DCM_voidOn                (u8 copy_u8DCM_ID, u8 copy_u8MotorDirection);
void DCM_voidOff               (u8 copy_u8DCM_ID);
void DCM_voidControlMotorSpeed (u8 copy_u8DCM_ID, u8 copy_u8MotorDirection, u8 copy_u8DesiredSpeed);


#endif /* DCM_INTERFACE_H_ */
