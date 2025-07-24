################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/NUEDC/Car_2.0/sys/Debug_Proc" -I"D:/NUEDC/Car_2.0/sys/Broad_Init" -I"D:/NUEDC/Car_2.0/lib/task" -I"D:/NUEDC/Car_2.0/lib/command" -I"D:/NUEDC/Car_2.0/lib/i2c" -I"D:/NUEDC/Car_2.0/lib/key" -I"D:/NUEDC/Car_2.0/lib/usart" -I"D:/NUEDC/Car_2.0/lib/delay" -I"D:/NUEDC/Car_2.0/app/W25Q128" -I"D:/NUEDC/Car_2.0/app/Servos" -I"D:/NUEDC/Car_2.0/app/OpenMV" -I"D:/NUEDC/Car_2.0/app/Motor" -I"D:/NUEDC/Car_2.0/app/JY61P" -I"D:/NUEDC/Car_2.0/app/Encoder" -I"D:/NUEDC/Car_2.0/app/CKP" -I"D:/NUEDC/Car_2.0/app/BLE05" -I"D:/NUEDC/Car_2.0/app/Button" -I"D:/NUEDC/Car_2.0/app/ADC" -I"D:/NUEDC/Car_2.0/app/AT8236" -I"D:/NUEDC/Car_2.0/app/Timer" -I"D:/NUEDC/Car_2.0" -I"D:/NUEDC/Car_2.0/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -I"D:/NUEDC/Car_2.0/test/Servos" -I"D:/NUEDC/Car_2.0/test/OpenMV" -I"D:/NUEDC/Car_2.0/test/CKP" -I"D:/NUEDC/Car_2.0/test/Button" -I"D:/NUEDC/Car_2.0/test/AT8236" -I"D:/NUEDC/Car_2.0/lib/pid" -I"D:/NUEDC/Car_2.0/lib/servo" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-238814753: ../main.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/TI/sysconfig_1.22.0/sysconfig_cli.bat" --script "D:/NUEDC/Car_2.0/main.syscfg" -o "." -s "C:/TI/mspm0_sdk_2_04_00_06/.metadata/product.json" -d "MSPM0G350X" -p "LQFP-64(PM)" -r "Default" --context "system" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-238814753 ../main.syscfg
device.opt: build-238814753
device.cmd.genlibs: build-238814753
ti_msp_dl_config.c: build-238814753
ti_msp_dl_config.h: build-238814753
Event.dot: build-238814753

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/NUEDC/Car_2.0/sys/Debug_Proc" -I"D:/NUEDC/Car_2.0/sys/Broad_Init" -I"D:/NUEDC/Car_2.0/lib/task" -I"D:/NUEDC/Car_2.0/lib/command" -I"D:/NUEDC/Car_2.0/lib/i2c" -I"D:/NUEDC/Car_2.0/lib/key" -I"D:/NUEDC/Car_2.0/lib/usart" -I"D:/NUEDC/Car_2.0/lib/delay" -I"D:/NUEDC/Car_2.0/app/W25Q128" -I"D:/NUEDC/Car_2.0/app/Servos" -I"D:/NUEDC/Car_2.0/app/OpenMV" -I"D:/NUEDC/Car_2.0/app/Motor" -I"D:/NUEDC/Car_2.0/app/JY61P" -I"D:/NUEDC/Car_2.0/app/Encoder" -I"D:/NUEDC/Car_2.0/app/CKP" -I"D:/NUEDC/Car_2.0/app/BLE05" -I"D:/NUEDC/Car_2.0/app/Button" -I"D:/NUEDC/Car_2.0/app/ADC" -I"D:/NUEDC/Car_2.0/app/AT8236" -I"D:/NUEDC/Car_2.0/app/Timer" -I"D:/NUEDC/Car_2.0" -I"D:/NUEDC/Car_2.0/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -I"D:/NUEDC/Car_2.0/test/Servos" -I"D:/NUEDC/Car_2.0/test/OpenMV" -I"D:/NUEDC/Car_2.0/test/CKP" -I"D:/NUEDC/Car_2.0/test/Button" -I"D:/NUEDC/Car_2.0/test/AT8236" -I"D:/NUEDC/Car_2.0/lib/pid" -I"D:/NUEDC/Car_2.0/lib/servo" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/TI/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/NUEDC/Car_2.0/sys/Debug_Proc" -I"D:/NUEDC/Car_2.0/sys/Broad_Init" -I"D:/NUEDC/Car_2.0/lib/task" -I"D:/NUEDC/Car_2.0/lib/command" -I"D:/NUEDC/Car_2.0/lib/i2c" -I"D:/NUEDC/Car_2.0/lib/key" -I"D:/NUEDC/Car_2.0/lib/usart" -I"D:/NUEDC/Car_2.0/lib/delay" -I"D:/NUEDC/Car_2.0/app/W25Q128" -I"D:/NUEDC/Car_2.0/app/Servos" -I"D:/NUEDC/Car_2.0/app/OpenMV" -I"D:/NUEDC/Car_2.0/app/Motor" -I"D:/NUEDC/Car_2.0/app/JY61P" -I"D:/NUEDC/Car_2.0/app/Encoder" -I"D:/NUEDC/Car_2.0/app/CKP" -I"D:/NUEDC/Car_2.0/app/BLE05" -I"D:/NUEDC/Car_2.0/app/Button" -I"D:/NUEDC/Car_2.0/app/ADC" -I"D:/NUEDC/Car_2.0/app/AT8236" -I"D:/NUEDC/Car_2.0/app/Timer" -I"D:/NUEDC/Car_2.0" -I"D:/NUEDC/Car_2.0/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -I"D:/NUEDC/Car_2.0/test/Servos" -I"D:/NUEDC/Car_2.0/test/OpenMV" -I"D:/NUEDC/Car_2.0/test/CKP" -I"D:/NUEDC/Car_2.0/test/Button" -I"D:/NUEDC/Car_2.0/test/AT8236" -I"D:/NUEDC/Car_2.0/lib/pid" -I"D:/NUEDC/Car_2.0/lib/servo" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


