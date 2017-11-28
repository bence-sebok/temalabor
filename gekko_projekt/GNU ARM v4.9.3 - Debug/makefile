################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include driver/subdir.mk
-include CMSIS/EFM32GG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: temalabor.axf

# Tool invocations
temalabor.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "temalabor.ld" -Xlinker --gc-sections -Xlinker -Map="temalabor.map" --specs=nano.specs -o temalabor.axf "./CMSIS/EFM32GG/startup_gcc_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./driver/segmentlcd.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_lcd.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./src/InitDevice.o" "./src/main.o" "./src/message.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: temalabor.hex'
	arm-none-eabi-objcopy -O ihex "temalabor.axf" "temalabor.hex"
	@echo ' '

	@echo 'Building bin file: temalabor.bin'
	arm-none-eabi-objcopy -O binary "temalabor.axf" "temalabor.bin"
	@echo ' '

	@echo 'Building s37 file: temalabor.s37'
	arm-none-eabi-objcopy -O srec "temalabor.axf" "temalabor.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "temalabor.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) temalabor.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
