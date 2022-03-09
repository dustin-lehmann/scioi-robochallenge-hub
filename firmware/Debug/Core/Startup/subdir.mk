################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f401rctx.s 

OBJS += \
./Core/Startup/startup_stm32f401rctx.o 

S_DEPS += \
./Core/Startup/startup_stm32f401rctx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware" -I/firmware/communication -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware/led" -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware/distance" -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware/sensors" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f401rctx.d ./Core/Startup/startup_stm32f401rctx.o

.PHONY: clean-Core-2f-Startup

