################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/%.o Drivers/STM32F4xx_HAL_Driver/Src/%.su: ../Drivers/STM32F4xx_HAL_Driver/Src/%.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/lehmann_workstation/Desktop/work_dir/projects/side_projects/robolympics/scioi-robochallenge-hub/firmware/firmware" -I../firmware/communication -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/lehmann_workstation/Desktop/work_dir/projects/side_projects/robolympics/scioi-robochallenge-hub/firmware/firmware/led" -I"C:/Users/lehmann_workstation/Desktop/work_dir/projects/side_projects/robolympics/scioi-robochallenge-hub/firmware/firmware/sensors" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.su ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.d ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.o ./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.su

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

