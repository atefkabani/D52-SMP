/*
 * SERVO_program.h
 *
 *  Created on: May 13, 2024
 *Author :  D52
 */


#ifndef HAL_DOOR_INTERFACE_H_
#define HAL_DOOR_INTERFACE_H_

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SERVO_interface.h"


#define SERVO_OPEN_ANGLE	90
#define SERVO_CLOSE_ANGLE	0

void DOOR_voidInit(void);
void DOOR_voidOpen(void);
void DOOR_voidClose(void);





#endif 




