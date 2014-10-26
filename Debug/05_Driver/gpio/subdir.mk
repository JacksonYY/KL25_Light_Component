################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../05_Driver/gpio/gpio.c 

OBJS += \
./05_Driver/gpio/gpio.o 

C_DEPS += \
./05_Driver/gpio/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
05_Driver/gpio/%.o: ../05_Driver/gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/08_Source" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/06_App_Component" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/03_MCU" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/06_App_Component/light" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/05_Driver" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/07_Soft_Component/common" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/02_CPU" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/07_Soft_Component" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/05_Driver/gpio" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/04_Linker_File" -I"E:/BOOK/2012-2014 KL25/06-KL25CD/SD-FSL-KL25-CD(V3.3)KDS-20140930/KL25-Program(KDS_V3.3)/ch04-Light(KDS)20141006/KL25_Light_Component/03_MCU" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


