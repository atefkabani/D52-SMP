################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIGHT\ SYSTEM/LS_program.c 

OBJS += \
./LIGHT\ SYSTEM/LS_program.o 

C_DEPS += \
./LIGHT\ SYSTEM/LS_program.d 


# Each subdirectory must supply rules for building sources it contributes
LIGHT\ SYSTEM/LS_program.o: ../LIGHT\ SYSTEM/LS_program.c LIGHT\ SYSTEM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Eclipse_workspace\D52-SMP\UTILES_LIB" -I"E:\Eclipse_workspace\D52-SMP\HAL\EEPROM" -I"E:\Eclipse_workspace\D52-SMP\AIRCONDITION" -I"E:\Eclipse_workspace\D52-SMP\ALERT SYSTEM" -I"E:\Eclipse_workspace\D52-SMP\DIMMER" -I"E:\Eclipse_workspace\D52-SMP\Door" -I"E:\Eclipse_workspace\D52-SMP\LIGHT SYSTEM" -I"E:\Eclipse_workspace\D52-SMP\HAL\BUZZER" -I"E:\Eclipse_workspace\D52-SMP\HAL\DCM" -I"E:\Eclipse_workspace\D52-SMP\HAL\KPD" -I"E:\Eclipse_workspace\D52-SMP\HAL\LCD" -I"E:\Eclipse_workspace\D52-SMP\HAL\LED" -I"E:\Eclipse_workspace\D52-SMP\HAL\LM35" -I"E:\Eclipse_workspace\D52-SMP\HAL\RELAY" -I"E:\Eclipse_workspace\D52-SMP\HAL\SERVO" -I"E:\Eclipse_workspace\D52-SMP\MCAL\ADC" -I"E:\Eclipse_workspace\D52-SMP\MCAL\DIO" -I"E:\Eclipse_workspace\D52-SMP\MCAL\GI" -I"E:\Eclipse_workspace\D52-SMP\MCAL\PWM" -I"E:\Eclipse_workspace\D52-SMP\MCAL\TMR0" -I"E:\Eclipse_workspace\D52-SMP\MCAL\TWI" -I"E:\Eclipse_workspace\D52-SMP\MCAL\UART" -I"E:\Eclipse_workspace\D52-SMP\SecuritySystem" -I"E:\Eclipse_workspace\D52-SMP\MCAL\TMR2" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"LIGHT SYSTEM/LS_program.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


