################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drvs/Src/uart.c 

OBJS += \
./drvs/Src/uart.o 

C_DEPS += \
./drvs/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
drvs/Src/%.o drvs/Src/%.su drvs/Src/%.cyclo: ../drvs/Src/%.c drvs/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/drvs" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/drvs/Inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/drvs/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drvs-2f-Src

clean-drvs-2f-Src:
	-$(RM) ./drvs/Src/uart.cyclo ./drvs/Src/uart.d ./drvs/Src/uart.o ./drvs/Src/uart.su

.PHONY: clean-drvs-2f-Src

