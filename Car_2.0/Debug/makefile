################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS

GEN_OPTS__FLAG := @"syscfg/device.opt" 
GEN_CMDS__FLAG := -Wl,-l"syscfg/device_linker.cmd" 

ORDERED_OBJS += \
"./main.o" \
"./syscfg/ti_msp_dl_config.o" \
"./startup_mspm0g350x_ticlang.o" \
"./app/AT8236/app_AT8236.o" \
"./app/BLE05/app_ble05.o" \
"./app/JY61P/app_jy61p.o" \
"./app/button/app_button.o" \
"./app/openmv/app_openmv.o" \
"./lib/command/command.o" \
"./lib/delay/delay.o" \
"./lib/i2c/i2c.o" \
"./lib/key/key.o" \
"./lib/pid/pid.o" \
"./lib/servo/servo.o" \
"./lib/usart/usart.o" \
"./test/AT8236/test_AT8236.o" \
"./test/button/test_button.o" \
"./test/openmv/test_openmv.o" \
$(GEN_CMDS__FLAG) \
-Wl,-ldevice.cmd.genlibs \
-Wl,-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include app/AT8236/subdir_vars.mk
-include app/BLE05/subdir_vars.mk
-include app/JY61P/subdir_vars.mk
-include app/button/subdir_vars.mk
-include app/openmv/subdir_vars.mk
-include lib/command/subdir_vars.mk
-include lib/delay/subdir_vars.mk
-include lib/i2c/subdir_vars.mk
-include lib/key/subdir_vars.mk
-include lib/pid/subdir_vars.mk
-include lib/servo/subdir_vars.mk
-include lib/usart/subdir_vars.mk
-include test/AT8236/subdir_vars.mk
-include test/button/subdir_vars.mk
-include test/openmv/subdir_vars.mk
-include subdir_rules.mk
-include app/AT8236/subdir_rules.mk
-include app/BLE05/subdir_rules.mk
-include app/JY61P/subdir_rules.mk
-include app/button/subdir_rules.mk
-include app/openmv/subdir_rules.mk
-include lib/command/subdir_rules.mk
-include lib/delay/subdir_rules.mk
-include lib/i2c/subdir_rules.mk
-include lib/key/subdir_rules.mk
-include lib/pid/subdir_rules.mk
-include lib/servo/subdir_rules.mk
-include lib/usart/subdir_rules.mk
-include test/AT8236/subdir_rules.mk
-include test/button/subdir_rules.mk
-include test/openmv/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Car_2.0.out 

EXE_OUTPUTS__QUOTED += \
"Car_2.0.out" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Car_2.0.out"

# Tool invocations
Car_2.0.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -g -Wl,-m"Car_2.0.map" -Wl,-i"D:/NUEDC/Car_2.0/Debug/syscfg" -Wl,-i"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/lib" -Wl,-i"D:/NUEDC/Car_2.0" -Wl,-i"C:/TI/mspm0_sdk_2_04_00_06/source" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="Car_2.0_linkInfo.xml" -Wl,--rom_model -o "Car_2.0.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.o" "syscfg\ti_msp_dl_config.o" "startup_mspm0g350x_ticlang.o" "app\AT8236\app_AT8236.o" "app\BLE05\app_ble05.o" "app\JY61P\app_jy61p.o" "app\button\app_button.o" "app\openmv\app_openmv.o" "lib\command\command.o" "lib\delay\delay.o" "lib\i2c\i2c.o" "lib\key\key.o" "lib\pid\pid.o" "lib\servo\servo.o" "lib\usart\usart.o" "test\AT8236\test_AT8236.o" "test\button\test_button.o" "test\openmv\test_openmv.o" 
	-$(RM) "main.d" "syscfg\ti_msp_dl_config.d" "startup_mspm0g350x_ticlang.d" "app\AT8236\app_AT8236.d" "app\BLE05\app_ble05.d" "app\JY61P\app_jy61p.d" "app\button\app_button.d" "app\openmv\app_openmv.d" "lib\command\command.d" "lib\delay\delay.d" "lib\i2c\i2c.d" "lib\key\key.d" "lib\pid\pid.d" "lib\servo\servo.d" "lib\usart\usart.d" "test\AT8236\test_AT8236.d" "test\button\test_button.d" "test\openmv\test_openmv.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

