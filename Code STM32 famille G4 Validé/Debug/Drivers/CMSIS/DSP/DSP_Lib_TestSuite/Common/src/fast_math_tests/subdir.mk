################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/RTOS2/Include -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM3 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM4_FP -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP -I../Drivers/CMSIS/RTOS2/Source -I../Drivers/CMSIS/NN/Sourse -I../Drivers/CMSIS/Core_A/Include -I../Drivers/CMSIS/DSP/Include -I../Drivers/CMSIS/NN/Include -I../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples_cifar10/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0/RTE_Components.h -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src-2f-fast_math_tests

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src-2f-fast_math_tests:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/fast_math_tests/fast_math_tests_common_data.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src-2f-fast_math_tests

