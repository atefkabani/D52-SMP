/*
 * TMR0_config.h
 *
 * Created: 5/10/2024 2:29:04 AM
 *  Author :  D52
 */ 


#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_
/*Options For TMR0 Mode:
1- TMR0_NORMAL_MODE
2- TMR0_CTC_MODE
*/
#define TMR0_MODE            TMR0_NORMAL_MODE

/*Options For TMR0 Prescaler:
1- TMR0_NO_PRESCALER
2- TMR0_8_PRESCALER
3- TMR0_64_PRESCALER
4- TMR0_256_PRESCALER
5- TMR0_1024_PRESCALER
*/
#define TMR0_PRESCALER_VALUE TMR0_64_PRESCALER

#define TMR0_PRELOAD_VALUE      10

#define TMR0_OVER_FLOW_COUNTER  10

#define TMR0_COMPARE_VALUE   249

#endif /* TMR0_CONFIG_H_ */
