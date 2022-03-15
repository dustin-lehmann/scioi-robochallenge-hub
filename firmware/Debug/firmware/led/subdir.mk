################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../firmware/led/led.c \
../firmware/led/ws2812.c 

OBJS += \
./firmware/led/led.o \
./firmware/led/ws2812.o 

C_DEPS += \
./firmware/led/led.d \
./firmware/led/ws2812.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/led/%.o firmware/led/%.su: ../firmware/led/%.c firmware/led/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/lehmann_workstation/Desktop/firmware_robochallenge_hub/firmware_robochallenge_hub/firmware" -I../firmware/communication -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/lehmann_workstation/Desktop/firmware_robochallenge_hub/firmware_robochallenge_hub/firmware/led" -I"C:/Users/lehmann_workstation/Desktop/firmware_robochallenge_hub/firmware_robochallenge_hub/firmware/sensors" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-firmware-2f-led

clean-firmware-2f-led:
	-$(RM) ./firmware/led/led.d ./firmware/led/led.o ./firmware/led/led.su ./firmware/led/ws2812.d ./firmware/led/ws2812.o ./firmware/led/ws2812.su

.PHONY: clean-firmware-2f-led

