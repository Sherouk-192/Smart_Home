################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEYPADDR/KEYPAD_PROG.c 

OBJS += \
./KEYPADDR/KEYPAD_PROG.o 

C_DEPS += \
./KEYPADDR/KEYPAD_PROG.d 


# Each subdirectory must supply rules for building sources it contributes
KEYPADDR/%.o: ../KEYPADDR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


