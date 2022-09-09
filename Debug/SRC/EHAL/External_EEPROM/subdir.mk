################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/EHAL/External_EEPROM/external_eeprom.c 

OBJS += \
./SRC/EHAL/External_EEPROM/external_eeprom.o 

C_DEPS += \
./SRC/EHAL/External_EEPROM/external_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/EHAL/External_EEPROM/%.o: ../SRC/EHAL/External_EEPROM/%.c SRC/EHAL/External_EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


