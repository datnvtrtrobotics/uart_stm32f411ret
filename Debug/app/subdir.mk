################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/uart_f411.c 

OBJS += \
./app/uart_f411.o 

C_DEPS += \
./app/uart_f411.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o app/%.su app/%.cyclo: ../app/%.c app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/drvs" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/drvs/Inc" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/drvs/Src" -I"/home/tdat/STM32CubeIDE/workspace_1.15.1/uart_stm32f411ret/app" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app

clean-app:
	-$(RM) ./app/uart_f411.cyclo ./app/uart_f411.d ./app/uart_f411.o ./app/uart_f411.su

.PHONY: clean-app

