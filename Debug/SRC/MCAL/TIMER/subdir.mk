################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/MCAL/TIMER/timer.c 

OBJS += \
./SRC/MCAL/TIMER/timer.o 

C_DEPS += \
./SRC/MCAL/TIMER/timer.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/MCAL/TIMER/%.o: ../SRC/MCAL/TIMER/%.c SRC/MCAL/TIMER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


