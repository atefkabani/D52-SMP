/*
 * GI_program.c
 *
 * Created: 4/23/2024 5:57:46 PM
 *  Author :  D52
 */ 

//MCAL
#include "GI_interface.h"
#include "GI_register.h"
#include "DIO_interface.h"
//UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void GI_voidEnable()
{
	SET_BIT(SREG_REG,I);
}
void GI_voidDisable()
{
    CLR_BIT(SREG_REG,I);
}
