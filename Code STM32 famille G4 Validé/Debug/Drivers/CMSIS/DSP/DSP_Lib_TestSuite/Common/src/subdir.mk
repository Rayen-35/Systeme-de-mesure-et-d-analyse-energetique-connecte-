################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/RTOS2/Include -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM3 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM4_FP -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP -I../Drivers/CMSIS/RTOS2/Source -I../Drivers/CMSIS/NN/Sourse -I../Drivers/CMSIS/Core_A/Include -I../Drivers/CMSIS/DSP/Include -I../Drivers/CMSIS/NN/Include -I../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples_cifar10/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0/RTE_Components.h -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src

