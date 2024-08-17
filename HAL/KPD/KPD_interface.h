/*
 * KPD_interface.h
 *
 * Created: 4/19/2024 3:15:25 PM
 *  Author :  D52
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


#define KPD_NOT_PRESSED			0xff

                     /*************** APIS PROTO TYPES ***************/
					 
void KPD_voidInit    (void);
void KPD_voidGetValue(u8* copy_pu8ReturnedValue);


#endif /* KPD_INTERFACE_H_ */
