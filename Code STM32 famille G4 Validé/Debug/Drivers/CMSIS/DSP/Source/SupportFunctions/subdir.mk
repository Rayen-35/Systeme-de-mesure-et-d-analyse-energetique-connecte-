################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.c \
../Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.o \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.d \
./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/Source/SupportFunctions/%.o Drivers/CMSIS/DSP/Source/SupportFunctions/%.su Drivers/CMSIS/DSP/Source/SupportFunctions/%.cyclo: ../Drivers/CMSIS/DSP/Source/SupportFunctions/%.c Drivers/CMSIS/DSP/Source/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/RTOS2/Include -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM3 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM4_FP -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP -I../Drivers/CMSIS/RTOS2/Source -I../Drivers/CMSIS/NN/Sourse -I../Drivers/CMSIS/Core_A/Include -I../Drivers/CMSIS/DSP/Include -I../Drivers/CMSIS/NN/Include -I../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples_cifar10/RTE/_ARMCM0 -I../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM0/RTE_Components.h -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-Source-2f-SupportFunctions

clean-Drivers-2f-CMSIS-2f-DSP-2f-Source-2f-SupportFunctions:
	-$(RM) ./Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/SupportFunctions.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.su ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.cyclo ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.d ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.o ./Drivers/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-Source-2f-SupportFunctions

