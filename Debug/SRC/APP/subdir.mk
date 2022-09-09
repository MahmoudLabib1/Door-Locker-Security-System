################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/APP/AMIT_Final_Project.c 

OBJS += \
./SRC/APP/AMIT_Final_Project.o 

C_DEPS += \
./SRC/APP/AMIT_Final_Project.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/APP/%.o: ../SRC/APP/%.c SRC/APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


