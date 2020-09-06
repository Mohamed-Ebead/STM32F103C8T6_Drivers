################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EXTI0_program.c \
../src/GPIO_program.c \
../src/IR_program.c \
../src/NVIC_program.c \
../src/RCC_program.c \
../src/RGB_LED_program.c \
../src/STK_program.c \
../src/main.c 

OBJS += \
./src/EXTI0_program.o \
./src/GPIO_program.o \
./src/IR_program.o \
./src/NVIC_program.o \
./src/RCC_program.o \
./src/RGB_LED_program.o \
./src/STK_program.o \
./src/main.o 

C_DEPS += \
./src/EXTI0_program.d \
./src/GPIO_program.d \
./src/IR_program.d \
./src/NVIC_program.d \
./src/RCC_program.d \
./src/RGB_LED_program.d \
./src/STK_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"E:\IMT_ARM\Work_Space\IR_V0.3\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


