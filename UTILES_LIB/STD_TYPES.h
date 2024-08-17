/*
 * STD_TYPES.h
 *
 * Created: 4/30/2024 5:05:09 PM
 *  Author :  D52
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
										/**(Define New Data Types)**/
typedef unsigned char        u8;
typedef signed   char        s8;

typedef unsigned short int  u16;
typedef signed   short int  s16;

typedef unsigned long int   u32;
typedef signed   long int   s32;

typedef float               f32;
typedef double              f64;

typedef enum
{
	FALSE, //0
	TRUE   //1
	}BOOL_t;

#define NULL (void*)0


#endif /* STD_TYPES_H_ */
