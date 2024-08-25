/*
 * D52_SmartHome_Project.c
 *
 * Created: 7/6/2024 4:20:26 PM
 * Author :  D52
 */
/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Project*/
#include "SS_interface.h"



int main(void) {

	/*Initiate System Devices*/
	SS_voidInit();

	/*enable users to login*/
	SS_voidLogin();



	while (1);


}
