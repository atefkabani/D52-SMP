/*
 * SS_program.c
 *
 *  Created on: Aug 16, 2024
 *      Author: D52
 */
#define F_CPU 16000000UL
#include <util/delay.h>

/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*HAL*/
#include "KPD_interface.h"
#include "KPD_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LM35_interface.h"
#include "LM35_config.h"
#include "DCM_interface.h"
#include "DCM_config.h"
#include "RELAY_interface.h"
#include "RELAY_config.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "EEPROM_interface.h"

/*MCAL*/
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "PWM_interface.h"
#include "UART_interface.h"

/*Project*/
#include "AC_interface.h"
#include "DIMMER_interface.h"
#include "LS_interface.h"
#include "AS_interface.h"
#include "DOOR_interface.h"
#include "SS_interface.h"

typedef enum {
	none, admin, user1, user2, user3
} users;

static users local_loggedUser = none;
static BOOL_t local_isAuthenticated = FALSE;

static void SS_voidCheckCreateAdminAccount(); /* Function That check existence and  Create The Account For Admin   */
static void SS_voidCheckAdminPassword();
static void SS_voidCheckUserPassword(users copy_tUser);
static void SS_voidDisplayAdminMenu();
static void SS_voidDisplayUserMenu();
static void SS_voidCreateUser(); /* Function that */
static void SS_voidSelectEmptySlot(users *copy_tUser);
static void SS_voidDeleteUser();
static void SS_voidChangePassword();

void SS_voidIsAuthenticated(BOOL_t *copy_tIsAuthenticated) {
	*copy_tIsAuthenticated = local_isAuthenticated;
}
/*********************************************************************************************
 *   Function Name : SS_voidInit()
 *   Description   : This Function Used To Initiate System Devices
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/
void SS_voidInit() {
	LS_voidInit();
	AC_voidInit();
	DIMMER_voidInit();
	AS_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	UART_voidInit();
	EEPROM_voidInit();

}

/*********************************************************************************************
 *   Function Name : SS_voidCheckCreateAdminAccount()
 *   Description   : This Function Used To check if admin account is created or not
 *   				,	if not ,  Create Admin Account
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidCheckCreateAdminAccount() {
	u8 admin_check = 0;
	u8 local_u8RxData = 0;
	u8 counter;
	u8 EEPROM_Position = EEPROM_admin_password;

	/* clear users for test purpose only  */
//	EEPROM_voidWriteByte(EEPROM_admin_check, 0);
//	EEPROM_voidWriteByte(EEPROM_user1_check, 0);
//	EEPROM_voidWriteByte(EEPROM_user2_check, 0);
//	EEPROM_voidWriteByte(EEPROM_user3_check, 0);
	/******************************************************************/

//check if admin password is saved
	EEPROM_voidReadByte( EEPROM_admin_check, &admin_check);
	_delay_ms(10);

	//read from eeprom admin_check if admin_check = 1 then  admin password  is saved and exit function
	// if  if admin_check != 1  admin password not saved , and ask admin to create new password
	if (admin_check != 1) {

		UART_voidTxString((u8*) "Welcome Admin");
		UART_voidTxString((u8*) "Type new password");

		/*admin write his password from UART and saved in EEprom*/
		for (counter = 0; counter < Maximum_password; counter++) {
			do {
				UART_voidRxChar(&local_u8RxData);
			} while (local_u8RxData == NULL );
			LCD_voidDisplayChar('*');

			EEPROM_voidWriteByte(EEPROM_Position, local_u8RxData);
			_delay_ms(10);
			EEPROM_Position++;
		}

		/* save admin check = 1 , to indicate that admin saved his password*/
		EEPROM_voidWriteByte(EEPROM_admin_check, 1);

		UART_voidTxString((u8*) "Admin Password Created");

	}

}

/*********************************************************************************************
 *   Function Name : SS_voidUserSelection()
 *   Description   : This Function Used To select which user will login
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

void SS_voidLogin() {
	/* check if admin has password
	 * if no admin save his password
	 *
	 */
	SS_voidCheckCreateAdminAccount();
	u8 admin_check = 0;
	u8 user1_check = 0;
	u8 user2_check = 0;
	u8 user3_check = 0;
	u8 Username1[Maximum_password];
	u8 Username2[Maximum_password];
	u8 Username3[Maximum_password];
	u8 local_KPD0;
	u8 counter;
	u8 EEPROM_Position;
	BOOL_t success = FALSE;

	LCD_voidClear();
	LCD_voidDisplayString((u8*) "Welcome Home");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "press any key");
	do {

		KPD_voidGetValue(&local_KPD0);
	} while (local_KPD0 == KPD_NOT_PRESSED);

	LCD_voidClear();
	LCD_voidDisplayString((u8*) "Choose user");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "To Login");

	_delay_ms(3000);
	LCD_voidClear();

//check if admin is created
	EEPROM_voidReadByte( EEPROM_admin_check, &admin_check);
	_delay_ms(10);

//check if user1 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user1_check, &user1_check);
	_delay_ms(10);

	EEPROM_Position = EEPROM_user1_username;
	if (user1_check == 1) {
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &Username1[counter]);
			_delay_ms(10);
			EEPROM_Position++;
		}
	}

//check if user2 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user2_check, &user2_check);
	_delay_ms(10);
	EEPROM_Position = EEPROM_user2_username;
	if (user2_check == 1) {
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &Username2[counter]);
			_delay_ms(10);
			EEPROM_Position++;
		}
	}

//check if user3 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user3_check, &user3_check);
	_delay_ms(10);
	EEPROM_Position = EEPROM_user3_username;
	if (user3_check == 1) {
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &Username3[counter]);
			_delay_ms(10);
			EEPROM_Position++;
		}
	}

	/* Display available user , user select his username to login  */
	do {
		if (admin_check == 1)
			LCD_voidDisplayString((u8*) "1-Admin");

		if (user1_check == 1) {
			LCD_voidDisplayString((u8*) " 2-");
			for (counter = 0; counter < Maximum_password; counter++) {
				LCD_voidDisplayChar(Username1[counter]);
			}
		}

		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		//check if user2 is created  then display username on screen

		if (user2_check == 1) {
			LCD_voidDisplayString((u8*) "3-");
			for (counter = 0; counter < Maximum_password; counter++) {
				LCD_voidDisplayChar(Username2[counter]);
			}
		}

		//check if user3 is created  then display username on screen
		if (user3_check == 1) {
			LCD_voidDisplayString((u8*) " 4-");
			for (counter = 0; counter < Maximum_password; counter++) {
				LCD_voidDisplayChar(Username3[counter]);
			}
		}
		/*User select his username to login  by keypad*/
		do {

			KPD_voidGetValue(&local_KPD0);
		} while (local_KPD0 == KPD_NOT_PRESSED);

		/* user type his password and system compare entered password with saved password
		 * */

		switch (local_KPD0) {
		case '1':
			SS_voidCheckAdminPassword();
			success = TRUE;
			local_loggedUser = admin;
			break;
		case '2':
			SS_voidCheckUserPassword(user1);
			success = TRUE;
			local_loggedUser = user1;
			break;
		case '3':
			SS_voidCheckUserPassword(user2);
			success = TRUE;
			local_loggedUser = user2;
			break;
		case '4':
			SS_voidCheckUserPassword(user3);
			success = TRUE;
			local_loggedUser = user3;
			break;
		default:
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Invalid Entry");
			LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
			LCD_voidDisplayString((u8*) "Try Again ");
			_delay_ms(3000);
			LCD_voidClear();
			break;
		}

	} while (success == FALSE);

}
/*********************************************************************************************
 *   Function Name : SS_voidCheckAdminPassword(users copy_tUser)
 *   Description   : This Function Used To  check password in admin mode, it compare the password saved in eeprom with
 *   				the one that user type , if the same user will login  ,
 *   				if not , user have 3 trials then alarm system will be activated
 *   				till system is reset
 *   Parameters    : variable of type users enum
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidCheckAdminPassword() {
	u8 saved_password[Maximum_password];
	u8 user_password[Maximum_password];
	u8 counter = 0;
	u8 correct = 0;
	u8 EEPROM_Position = EEPROM_admin_password;
	u8 trials = 0;

	/* read password from eeprom for the selected user */

	for (counter = 0; counter < Maximum_password; counter++) {
		EEPROM_voidReadByte(EEPROM_Position, &saved_password[counter]);
		_delay_ms(10);
		EEPROM_Position++;
	}

	while (trials < 3) {

		UART_voidTxString((u8*) "password ?");

		/* if admin mode accept password from Bluetooth
		 * */
		for (counter = 0; counter < Maximum_password; counter++) {

			do {
				UART_voidRxChar(&user_password[counter]);
			} while (user_password[counter] == NULL );

		}

		//Check password
		for (counter = 0; counter < Maximum_password; counter++) {
			if (user_password[counter] == saved_password[counter]) {
				++correct;
			} else {
				break;
			}
		}

		// if password valid
		if (correct == Maximum_password) {

			UART_voidTxString((u8*) "Login Success");

			local_isAuthenticated = TRUE;
			SS_voidDisplayAdminMenu();
			break;
		} else {
			trials++;

			if (trials < 3) {
				UART_voidTxString((u8*) "wrong password");
				LCD_voidDisplayString((u8*) "try again ");
			}

		}
	}
	if (trials >= 3) {
		/*If there are 3 false  trials , activate alarm  */
		AS_voidInit();
		AS_voidStart();

	}
}

/*********************************************************************************************
 *   Function Name : SS_voidCheckUserPassword(users copy_tUser)
 *   Description   : This Function Used To  check password for user mode, it compare the password saved in eeprom with
 *   				the one that user type , if the same user will login  ,
 *   				if not , user have 3 trials then alarm system will be activated
 *   				till system is reset
 *   Parameters    : variable of type users enum
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidCheckUserPassword(users copy_tUser) {
	u8 saved_password[Maximum_password];
	u8 user_password[Maximum_password];
	u8 counter = 0;
	u8 correct = 0;
	u8 EEPROM_Position = 0;
	u8 trials = 0;

	/* read password from eeprom for the selected user */
	switch (copy_tUser) {

	case user1:
		EEPROM_Position = EEPROM_user1_password;
		break;
	case user2:
		EEPROM_Position = EEPROM_user2_password;
		break;
	case user3:
		EEPROM_Position = EEPROM_user3_password;
		break;
	}

	for (counter = 0; counter < Maximum_password; counter++) {
		EEPROM_voidReadByte(EEPROM_Position, &saved_password[counter]);
		_delay_ms(10);
		EEPROM_Position++;
	}

	while (trials < 3) {
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "password ?");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);

		/* if admin mode accept password from Bluetooth
		 * if user mode accept password from user from keypad
		 * */
		for (counter = 0; counter < Maximum_password; counter++) {
			do {
				KPD_voidGetValue(&user_password[counter]);
			} while (user_password[counter] == KPD_NOT_PRESSED);

			LCD_voidDisplayChar('*');
		}

		//Check password
		for (counter = 0; counter < Maximum_password; counter++) {
			if (user_password[counter] == saved_password[counter]) {
				++correct;
			} else {
				break;
			}
		}

		// if password valid
		if (correct == Maximum_password) {
			LCD_voidClear();
			LCD_voidDisplayString((u8*) "Login Success");
			_delay_ms(3000);
			LCD_voidClear();
			local_isAuthenticated = TRUE;
			SS_voidDisplayUserMenu();
			break;
		} else {
			trials++;
			LCD_voidClear();
			if (trials < 3) {
				LCD_voidDisplayString((u8*) "wrong password");
				LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
				LCD_voidDisplayString((u8*) "try again ");
				_delay_ms(3000);
				LCD_voidClear();
			}

		}
	}
	if (trials >= 3) {
		/*If there are 3 false  trials , activate alarm  */
		AS_voidInit();
		AS_voidStart();

	}
}
/*********************************************************************************************
 *   Function Name : SS_voidDisplayAdminMenu( )
 *   Description   : This Function Used To  display  menu in admin mode
 *   				1-LEDS :   controll led
 *   				2-Dimmer :  control dimmer
 *   				3-AC : Display Temp
 *   				4-Door : Control Door (admin only)
 *   				5-Create User  :save new user in free slot (system has 3 slots)
 *   				6-Delete User : delete user , and mark slot as empty
 *   				7-Change password : change the pass of any user
 *   				8-Logout :  Logout and return to first screen
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidDisplayAdminMenu() {
	u8 local_u8RxData;

	UART_voidTxString((u8*) "   Choose from Menu : ");

	/*admin mode : display 1st admin Menu
	 * accept input from bluetooth*/

	UART_voidTxString((u8*) "1-LEDS");
	UART_voidTxString((u8*) "2-Dimmer");
	UART_voidTxString((u8*) "3-AC");
	UART_voidTxString((u8*) "4-Door");
	UART_voidTxString((u8*) "5-Create User");
	UART_voidTxString((u8*) "6-Delete User");
	UART_voidTxString((u8*) "7-Change password");
	UART_voidTxString((u8*) "8-Logout");

	UART_voidTxNewLine();

	/*Read user input for menu*/
	do {
		UART_voidRxChar(&local_u8RxData);
	} while (local_u8RxData == NULL );

	switch (local_u8RxData) {
	case '1': // LEDS
		LS_voidStartBluetooth();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;
	case '2': // Dimmer
		DIMMER_voidInit();
		DIMMER_voidStartBluetooth();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;
	case '3': //AC
		AC_voidInit();
		AC_voidShowMenuBluetooth();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;
	case '4': // Door  ( available only in admin mode )
		DOOR_voidInit();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;
	case '5': //Create_user
		SS_voidCreateUser();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;
	case '6': //Delete_user
		SS_voidDeleteUser();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;

	case '7': //Change_password
		SS_voidChangePassword();
		UART_voidTxNewLine();
		UART_voidTxNewLine();
		SS_voidDisplayAdminMenu();
		break;
	case '8': // logout
		local_isAuthenticated = FALSE;
		local_loggedUser = none;
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "   Log Out ");
		UART_voidTxString((u8*) "   Log Out ");
		_delay_ms(3000);
		SS_voidLogin();
		break;
	default:
		UART_voidTxString((u8*) "Wrong Choice");
		UART_voidTxString((u8*) "Please Try again!!");
	}

}
/*********************************************************************************************
 *   Function Name : SS_voidDisplayUserMenu( )
 *   Description   : This Function Used To  display  menu in user mode
 *   				1-LEDS :   controll led
 *   				2-Dimmer :  control dimmer
 *   				3-AC : Display Temp
 *   				4-Logout :  Logout and return to first screen
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidDisplayUserMenu() {
	u8 local_KPD1;
	LCD_voidClear();
	LCD_voidDisplayString((u8*) "   Choose from ");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "     Menu");
	_delay_ms(3000);
	LCD_voidClear();

	/*user mode :  display  user Menu
	 * accept input from keypad*/

	LCD_voidDisplayString((u8*) "1-LEDS 2-Dimmer");
	LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_voidDisplayString((u8*) "3-AC 4-Logout");
	do {
		KPD_voidGetValue(&local_KPD1);
	} while (local_KPD1 == KPD_NOT_PRESSED);

	switch (local_KPD1) {
	case '1': // LED
		LS_voidStartKPD();
		SS_voidDisplayUserMenu();
		break;
	case '2': // Dimmer
		DIMMER_voidInit();
		DIMMER_voidStartKPD();
		SS_voidDisplayUserMenu();
		break;
	case '3': // AC
		AC_voidInit();
		AC_voidShowMenuKPD();
		SS_voidDisplayUserMenu();
		break;
	case '4': // logout
		local_isAuthenticated = FALSE;
		local_loggedUser = none;
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "   Log Out ");
		_delay_ms(3000);
		SS_voidLogin();
		break;
	default: //Invalid Entry
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "Wrong Choice");
		LCD_voidGoToSpecificPosition(LCD_LINE_TWO, 0);
		LCD_voidDisplayString((u8*) "Please Try again!!");
		_delay_ms(1500);
		LCD_voidClear();
		SS_voidDisplayUserMenu();
	}

}

/*********************************************************************************************
 *   Function Name : SS_voidCreateUser( )
 *   Description   : This Function Used To create user in free slot
 *   				it search for first empty slot and save user username and password
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidCreateUser() {

	u8 counter;
	u8 EEPROM_user_Position;
	u8 EEPROM_check_Position;
	u8 EEPROM_password_Position;
	u8 local_u8RxData;
	users local_UserSlot;

	LCD_voidClear();

	/*check empty user slot*/
	SS_voidSelectEmptySlot(&local_UserSlot);
	/*set position in EEPROM for empty slot*/
	switch (local_UserSlot) {
	case user1:
		EEPROM_check_Position = EEPROM_user1_check;
		EEPROM_user_Position = EEPROM_user1_username;
		EEPROM_password_Position = EEPROM_user1_password;
		break;
	case user2:
		EEPROM_check_Position = EEPROM_user2_check;
		EEPROM_user_Position = EEPROM_user2_username;
		EEPROM_password_Position = EEPROM_user2_password;
		break;
	case user3:
		EEPROM_check_Position = EEPROM_user3_check;
		EEPROM_user_Position = EEPROM_user3_username;
		EEPROM_password_Position = EEPROM_user3_password;
		break;
	default:
		UART_voidTxString((u8*) "no empty slot");

		return;

	}

	UART_voidTxString((u8*) "Type username");

	/*read username from UART and save in eeprom*/
	for (counter = 0; counter < Maximum_password; counter++) {
		do {
			UART_voidRxChar(&local_u8RxData);
		} while (local_u8RxData == NULL );

		EEPROM_voidWriteByte(EEPROM_user_Position, local_u8RxData);
		_delay_ms(10);
		EEPROM_user_Position++;

	}

	/*read password from UART and save in eeprom*/
	LCD_voidClear();
	UART_voidTxString((u8*) "Type password");

	for (counter = 0; counter < Maximum_password; counter++) {
		do {
			UART_voidRxChar(&local_u8RxData);
		} while (local_u8RxData == NULL );

		EEPROM_voidWriteByte(EEPROM_password_Position, local_u8RxData);
		_delay_ms(10);
		EEPROM_password_Position++;

	}

	/* write index of this user  = 1 to indicate that user is saved in this slot*/
	EEPROM_voidWriteByte(EEPROM_check_Position, 1);
	_delay_ms(10);

	LCD_voidClear();
	LCD_voidDisplayString((u8*) "User Created");
	UART_voidTxString((u8*) "User Created");
	_delay_ms(3000);
	LCD_voidClear();
}
/*********************************************************************************************
 *   Function Name : SS_voidSelectEmptySlot(users *copy_tUser )
 *   Description   : This Function Used  select the empty slot to create new user
 *
 *   Parameters    : users *copy_tUser
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidSelectEmptySlot(users *copy_tUser) {
	if (copy_tUser != NULL) {
		u8 user1_check = 0;
		u8 user2_check = 0;
		u8 user3_check = 0;
		/*check if username at slot 1 is exist or not*/
		EEPROM_voidReadByte(EEPROM_user1_check, &user1_check);
		_delay_ms(10);
		/*check if username at slot 2 is exist or not*/
		EEPROM_voidReadByte(EEPROM_user2_check, &user2_check);
		_delay_ms(10);
		/*check if username at slot 3 is exist or not*/
		EEPROM_voidReadByte(EEPROM_user3_check, &user3_check);
		_delay_ms(10);

		if (user1_check != 1)
			*copy_tUser = user1;
		else if (user2_check != 1)
			*copy_tUser = user2;
		else if (user3_check != 1)
			*copy_tUser = user3;

	}
}
/*********************************************************************************************
 *   Function Name : SS_voidDeleteUser( )
 *   Description   : This Function Used To select the user and delete it and mark its slot as empty
 *
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidDeleteUser() {
	u8 user1_check = 0;
	u8 user2_check = 0;
	u8 user3_check = 0;
	u8 local_u8RxData;
	u8 counter;
	u8 EEPROM_Position;

	UART_voidTxString((u8*) "Choose user To delete");

	//check if user1 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user1_check, &user1_check);
	_delay_ms(10);

	EEPROM_Position = EEPROM_user1_username;
	if (user1_check == 1) {
		UART_voidTxChar('1');
		UART_voidTxChar('-');
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &local_u8RxData);
			_delay_ms(10);
			UART_voidTxChar(local_u8RxData);
			EEPROM_Position++;
		}
	}

//check if user2 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user2_check, &user2_check);
	_delay_ms(10);
	EEPROM_Position = EEPROM_user2_username;
	if (user2_check == 1) {
		UART_voidTxChar('2');
		UART_voidTxChar('-');
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &local_u8RxData);
			_delay_ms(10);
			UART_voidTxChar(local_u8RxData);
			EEPROM_Position++;
		}
	}

//check if user3 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user3_check, &user3_check);
	_delay_ms(10);
	EEPROM_Position = EEPROM_user3_username;
	if (user3_check == 1) {
		UART_voidTxChar('3');
		UART_voidTxChar('-');
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &local_u8RxData);
			_delay_ms(10);
			UART_voidTxChar(local_u8RxData);
			EEPROM_Position++;
		}
	}

	if (user1_check != 1 && user2_check != 1 && user3_check != 1) {
		UART_voidTxString((u8*) "No user exist ");
		_delay_ms(3000);
		return;
	}
	UART_voidTxNewLine();
// read user inpput

	do {
		UART_voidRxChar(&local_u8RxData);
	} while (local_u8RxData == NULL );

	switch (local_u8RxData) {
	case '1':
		EEPROM_voidWriteByte(EEPROM_user1_check, 0);
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "user deleted");
		UART_voidTxString((u8*) "user deleted");
		_delay_ms(2000);
		break;
	case '2':
		EEPROM_voidWriteByte(EEPROM_user2_check, 0);
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "user deleted");
		UART_voidTxString((u8*) "user deleted");
		_delay_ms(2000);
		break;
	case '3':
		EEPROM_voidWriteByte(EEPROM_user3_check, 0);
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "user deleted");
		UART_voidTxString((u8*) "user deleted");
		_delay_ms(2000);
		break;
	default:

		UART_voidTxString((u8*) "Invalid Entry");
		_delay_ms(3000);

	}
}
/*********************************************************************************************
 *   Function Name : SS_voidChangePassword( )
 *   Description   : This Function Used To select the user and  change its password
 *
 *   Parameters    : Void
 *   Return Value  : Void
 *   Remarks       : None
 **********************************************************************************************/

static void SS_voidChangePassword() {

	u8 user1_check = 0;
	u8 user2_check = 0;
	u8 user3_check = 0;
	u8 local_u8RxData;
	u8 counter;
	u8 EEPROM_Position = 0;

	UART_voidTxString((u8*) "Choose user to change password");

	UART_voidTxString((u8*) "1-admin ");
	//check if user1 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user1_check, &user1_check);
	_delay_ms(10);

	EEPROM_Position = EEPROM_user1_username;
	if (user1_check == 1) {
		UART_voidTxChar('2');
		UART_voidTxChar('-');
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &local_u8RxData);
			_delay_ms(10);
			UART_voidTxChar(local_u8RxData);
			EEPROM_Position++;
		}
		UART_voidTxNewLine();
	}

//check if user2 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user2_check, &user2_check);
	_delay_ms(10);
	EEPROM_Position = EEPROM_user2_username;
	if (user2_check == 1) {
		UART_voidTxChar('3');
		UART_voidTxChar('-');
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &local_u8RxData);
			_delay_ms(10);
			UART_voidTxChar(local_u8RxData);
			EEPROM_Position++;
		}
		UART_voidTxNewLine();
	}

//check if user3 is created  then copy username
	EEPROM_voidReadByte( EEPROM_user3_check, &user3_check);
	_delay_ms(10);
	EEPROM_Position = EEPROM_user3_username;
	if (user3_check == 1) {
		UART_voidTxChar('4');
		UART_voidTxChar('-');
		for (counter = 0; counter < Maximum_password; counter++) {
			EEPROM_voidReadByte(EEPROM_Position, &local_u8RxData);
			_delay_ms(10);
			UART_voidTxChar(local_u8RxData);
			EEPROM_Position++;
		}
		UART_voidTxNewLine();
	}

	/* read user inpput  to select user*/

	do {
		UART_voidRxChar(&local_u8RxData);
	} while (local_u8RxData == NULL );

	switch (local_u8RxData) {
	case '1':
		EEPROM_Position = EEPROM_admin_password;
		break;
	case '2':
		EEPROM_Position = EEPROM_user1_password;
		break;
	case '3':
		EEPROM_Position = EEPROM_user2_password;
		break;
	case '4':
		EEPROM_Position = EEPROM_user3_password;

		break;
	default:

		UART_voidTxString((u8*) "Invalid Entry");
		_delay_ms(3000);

	}

	/* read user inpput  to change password for selected user*/

	UART_voidTxString((u8*) "type password");

	if (EEPROM_Position != 0) {
		for (counter = 0; counter < Maximum_password; counter++) {
			do {
				UART_voidRxChar(&local_u8RxData);
			} while (local_u8RxData == NULL );

			EEPROM_voidWriteByte(EEPROM_Position, local_u8RxData);
			_delay_ms(10);
			EEPROM_Position++;
		}
		LCD_voidClear();
		LCD_voidDisplayString((u8*) "password changed");
		UART_voidTxString((u8*) "password changed");
		_delay_ms(2000);

	}
}
