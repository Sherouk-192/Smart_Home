################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LCD_DR/subdir.mk
-include KEYPADDR/subdir.mk
-include GIE/subdir.mk
-include EXIT/subdir.mk
-include DIO/subdir.mk
-include ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
pr17_smart_home.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: pr17_smart_home.elf secondary-outputs

# Tool invocations
pr17_smart_home.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,pr17_smart_home.map -mmcu=atmega32 -o "pr17_smart_home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

pr17_smart_home.lss: pr17_smart_home.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S pr17_smart_home.elf  >"pr17_smart_home.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: pr17_smart_home.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 pr17_smart_home.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) pr17_smart_home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
