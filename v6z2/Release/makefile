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
v6z2.lss \

FLASH_IMAGE += \
v6z2.hex \

EEPROM_IMAGE += \
v6z2.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: v6z2.elf secondary-outputs

# Tool invocations
v6z2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,v6z2.map -L"C:\Users\vasil\Desktop\Eclipse work\usart\Release" -mmcu=atmega328p -o "v6z2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

v6z2.lss: v6z2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S v6z2.elf  >"v6z2.lss"
	@echo 'Finished building: $@'
	@echo ' '

v6z2.hex: v6z2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex v6z2.elf  "v6z2.hex"
	@echo 'Finished building: $@'
	@echo ' '

v6z2.eep: v6z2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex v6z2.elf  "v6z2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: v6z2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p v6z2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) v6z2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
