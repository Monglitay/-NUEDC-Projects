################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
test/AT8236/%.o: ../test/AT8236/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/NUEDC/Car_2.0" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"D:/NUEDC/Car_2.0/lib/delay" -I"D:/NUEDC/Car_2.0/lib/task" -I"D:/NUEDC/Car_2.0/lib/usart" -I"D:/NUEDC/Car_2.0/lib/i2c" -I"D:/NUEDC/Car_2.0/test/AT8236" -I"D:/NUEDC/Car_2.0/app/AT8236" -I"D:/NUEDC/Car_2.0/lib/command" -I"D:/NUEDC/Car_2.0/test/button" -I"D:/NUEDC/Car_2.0/test/openmv" -I"D:/NUEDC/Car_2.0/app/openmv" -I"D:/NUEDC/Car_2.0/app/JY61P" -I"D:/NUEDC/Car_2.0/app/button" -I"D:/NUEDC/Car_2.0/app/BLE05" -I"D:/NUEDC/Car_2.0/Debug" -I"D:/NUEDC/Car_2.0/lib/key" -I"D:/NUEDC/Car_2.0/lib/pid" -g -MMD -MP -MF"test/AT8236/$(basename $(<F)).d_raw" -MT"$(@)" -I"D:/NUEDC/Car_2.0/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


