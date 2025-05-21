################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.c \
../Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.c \
../Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.c 

OBJS += \
./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.o \
./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.o \
./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.o 

C_DEPS += \
./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.d \
./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.d \
./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/%.o Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/%.su Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/%.cyclo: ../Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/%.c Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/RTOS2/Include -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM3 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM4_FP -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP -I../Drivers/CMSIS/RTOS2/Source -I../Drivers/CMSIS/NN/Sourse -I../Drivers/CMSIS/Core_A/Include -I../Drivers/CMSIS/DSP/Include -I../Drivers/CMSIS/NN/Include -I../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples_cifar10/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0/RTE_Components.h -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-Examples-2f-ARM-2f-arm_graphic_equalizer_example

clean-Drivers-2f-CMSIS-2f-DSP-2f-Examples-2f-ARM-2f-arm_graphic_equalizer_example:
	-$(RM) ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.cyclo ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.d ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.o ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_data.su ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.cyclo ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.d ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.o ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/arm_graphic_equalizer_example_q31.su ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.cyclo ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.d ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.o ./Drivers/CMSIS/DSP/Examples/ARM/arm_graphic_equalizer_example/math_helper.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-Examples-2f-ARM-2f-arm_graphic_equalizer_example

