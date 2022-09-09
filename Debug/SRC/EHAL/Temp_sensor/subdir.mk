################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/EHAL/Temp_sensor/lm35.c 

OBJS += \
./SRC/EHAL/Temp_sensor/lm35.o 

C_DEPS += \
./SRC/EHAL/Temp_sensor/lm35.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/EHAL/Temp_sensor/%.o: ../SRC/EHAL/Temp_sensor/%.c SRC/EHAL/Temp_sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


