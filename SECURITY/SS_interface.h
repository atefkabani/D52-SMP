/*
 * SS_interface.h
 *
 *  Created on: Aug 16, 2024
 *      Author: D52
 */

#ifndef SECURITY_SS_INTERFACE_H_
#define SECURITY_SS_INTERFACE_H_



#define Maximum_password 5                   /* Maximium Array Password Size */
#define EEPROM_admin_check 0
#define EEPROM_user1_check 1
#define EEPROM_user2_check 2
#define EEPROM_user3_check 3
#define EEPROM_admin_password 4
#define EEPROM_user1_username (EEPROM_admin_password + Maximum_password)
#define EEPROM_user1_password (EEPROM_user1_username + Maximum_password)
#define EEPROM_user2_username (EEPROM_user1_password + Maximum_password)
#define EEPROM_user2_password (EEPROM_user2_username + Maximum_password)
#define EEPROM_user3_username (EEPROM_user2_password + Maximum_password)
#define EEPROM_user3_password (EEPROM_user3_username + Maximum_password)



void SS_voidInit();
void SS_voidLogin();

#endif /* SECURITY_SS_INTERFACE_H_ */
