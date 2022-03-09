################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../firmware/communication/messages.c \
../firmware/communication/request_messages.c \
../firmware/communication/usb_comm.c \
../firmware/communication/write_messages.c 

OBJS += \
./firmware/communication/messages.o \
./firmware/communication/request_messages.o \
./firmware/communication/usb_comm.o \
./firmware/communication/write_messages.o 

C_DEPS += \
./firmware/communication/messages.d \
./firmware/communication/request_messages.d \
./firmware/communication/usb_comm.d \
./firmware/communication/write_messages.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/communication/%.o: ../firmware/communication/%.c firmware/communication/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware/distance" -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware" -I../firmware/communication -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware/led" -I"C:/work_dir/projects/side_projects/robolympics/software/robochallenge_stm32_firmware/firmware_robochallenge_hub/firmware/sensors" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-firmware-2f-communication

clean-firmware-2f-communication:
	-$(RM) ./firmware/communication/messages.d ./firmware/communication/messages.o ./firmware/communication/request_messages.d ./firmware/communication/request_messages.o ./firmware/communication/usb_comm.d ./firmware/communication/usb_comm.o ./firmware/communication/write_messages.d ./firmware/communication/write_messages.o

.PHONY: clean-firmware-2f-communication

