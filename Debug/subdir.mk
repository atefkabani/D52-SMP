################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
main.o: ../main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\eclipse-workspace\D52-SMP\HAL\BUZZER" -I"C:\eclipse-workspace\D52-SMP\HAL\DCM" -I"C:\eclipse-workspace\D52-SMP\HAL\KPD" -I"C:\eclipse-workspace\D52-SMP\HAL\LCD" -I"C:\eclipse-workspace\D52-SMP\HAL\LED" -I"C:\eclipse-workspace\D52-SMP\HAL\LM35" -I"C:\eclipse-workspace\D52-SMP\HAL\RELAY" -I"C:\eclipse-workspace\D52-SMP\HAL\SERVO" -I"C:\eclipse-workspace\D52-SMP\MCAL\ADC" -I"C:\eclipse-workspace\D52-SMP\MCAL\DIO" -I"C:\eclipse-workspace\D52-SMP\MCAL\GI" -I"C:\eclipse-workspace\D52-SMP\MCAL\PWM" -I"C:\eclipse-workspace\D52-SMP\MCAL\TMR0" -I"C:\eclipse-workspace\D52-SMP\MCAL\TWI" -I"C:\eclipse-workspace\D52-SMP\MCAL\UART" -I"C:\eclipse-workspace\D52-SMP\UTILES_LIB" -I"C:\eclipse-workspace\D52-SMP\AIRCONDITION" -I"C:\eclipse-workspace\D52-SMP\ALERT SYSTEM" -I"C:\eclipse-workspace\D52-SMP\DIMMER" -I"C:\eclipse-workspace\D52-SMP\Door" -I"C:\eclipse-workspace\D52-SMP\HAL\EEPROM" -I"C:\eclipse-workspace\D52-SMP\LIGHT SYSTEM" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


