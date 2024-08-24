/*
 * AC_program.c
 *
 * Created: 7/5/2024 12:54:10 PM
 *Author :  D52
 */

#define F_CPU 16000000UL
#include <util/delay.h>
/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*HAL*/
#include "LM35_config.h"
#include "LM35_interface.h"
#include "DCM_config.h"
#include "DCM_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"

/*MCAL*/
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "PWM_interface.h"
#include "TMR2_interface.h"
#include "TMR2_config.h"
#include "GI_interface.h"
#include "UART_interface.h"

static BOOL_t Local_AC_Is_ON = FALSE;
static BOOL_t LocalIsKPD;

static void action(void);
static void AC_voidStart(void);
static void AC_voidStop(void);
static void AC_voidStatus() ;
/************************************************************************/
/*       Function That Init LM35 Temperature Sensor and LCD and DCM      */
 /************************************************************************/
void AC_voidInit(void) {
	LM35_voidInit();
	DCM_voidInit(DCM1);
	GI_voidEnable();
	TMR2_voidInit(TMR2_Normal_mode, TMR2_Prescaler_64);
	TMR2_voidSetCallBackOVR(&action);
	TMR2_voidSetDelay_ms_OVR(1000);

}

void AC_voidShowMenuKPD(void) {

	u8 local_u8KPD;
	LocalIsKPD = TRUE;
	LCD_voidClear();
	LCD_voidDisplayString((u8*) "1-AC ON 2-AC OFF");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "3-AC Status");
	do {
		KPD_voidGetValue(&local_u8KPD);
	} while (local_u8KPD == KPD_NOT_PRESSED);
	switch (local_u8KPD) {
	case '1':
		AC_voidStart();
		break;
	case '2':
		AC_voidStop();
		break;
	case '3':

		AC_voidStatus();
		break;
	default:

		LCD_voidClear();
		LCD_voidDisplayString((u8*) "Wrong Choice");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "Please Try again!!");
		_delay_ms(1500);
		LCD_voidClear();
		AC_voidShowMenuKPD();
	}

}
void AC_voidShowMenuBluetooth(void) {
	u8 local_u8RxData;
	LocalIsKPD = FALSE;
	UART_voidTxString((u8*) " 		AC");
		UART_voidTxString((u8*) "1-ON");
	UART_voidTxString((u8*) "2-OFF");
	UART_voidTxString((u8*) "3-Status");
	do {
		UART_voidRxChar(&local_u8RxData);
	} while (local_u8RxData == NULL);
	switch (local_u8RxData) {
	case '1':
		AC_voidStart();
		break;
	case '2':
		AC_voidStop();
		break;
	case '3':

		AC_voidStatus(FALSE);
		break;
	default:

		LCD_voidClear();
		UART_voidTxString((u8*) "Wrong Choice");
		UART_voidTxString((u8*) "Please Try again!!");
		_delay_ms(1500);

		AC_voidShowMenuBluetooth();
	}

}
/************************************************************************/
/*      Function That Control DCM by getting Temperature From LM35       */
 /************************************************************************/

static void AC_voidStart(void) {

	TMR2_voidStart();


	Local_AC_Is_ON = TRUE;
	AC_voidStatus();
}

static void AC_voidStop(void) {
	TMR2_voidStop();
	Local_AC_Is_ON = FALSE;
	DCM_voidOff(DCM1);
	AC_voidStatus();

}
/************************************************************************/
/*        Function That Write Temperature Sensed by LM35 On LCD          */
 /************************************************************************/
static void AC_voidStatus( ) {
	u8 local_u8Temp;
	LM35_voidGetTemp(LM35_FEEDBACK0_PIN, &local_u8Temp);

	LCD_voidClear();
	LCD_voidDisplayString((u8*) "Temp Is:");
	LCD_voidDisplayNumber(local_u8Temp);
	LCD_voidDisplayChar('C');
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);

	if(LocalIsKPD == FALSE){
		UART_voidTxString((u8*) "Temp Is:");
			UART_voidTxNumber(local_u8Temp);
			UART_voidTxChar('C');
			UART_voidTxNewLine();
	}

	if (Local_AC_Is_ON == TRUE) {

		LCD_voidDisplayString((u8*) "AC is ON");
		if(LocalIsKPD == FALSE)
		UART_voidTxString((u8*) "AC is ON");

	} else {

		LCD_voidDisplayString((u8*) "AC is OFF");
		if(LocalIsKPD == FALSE)
		UART_voidTxString((u8*) "AC is OFF");
	}

	_delay_ms(3000);
	LCD_voidClear();
}

static void action(void) {
	u8 local_u8Temp;
	LM35_voidGetTemp(LM35_FEEDBACK0_PIN, &local_u8Temp);

	if (local_u8Temp <= 21) {
		DCM_voidOff(DCM1);

	} else {
		DCM_voidOn(DCM1, DCM_CW);

	}

}
