################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
UART.Challenge.MC1.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: UART.Challenge.MC1.elf secondary-outputs

# Tool invocations
UART.Challenge.MC1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART.Challenge.MC1.map -mmcu=atmega16 -o "UART.Challenge.MC1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART.Challenge.MC1.lss: UART.Challenge.MC1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART.Challenge.MC1.elf  >"UART.Challenge.MC1.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART.Challenge.MC1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 UART.Challenge.MC1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UART.Challenge.MC1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
