################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Interpolation_Algorithms/CubicSpline.cpp \
../src/Interpolation_Algorithms/Newton.cpp \
../src/Interpolation_Algorithms/Newton_1.cpp \
../src/Interpolation_Algorithms/cubic.cpp \
../src/Interpolation_Algorithms/test.cpp 

OBJS += \
./src/Interpolation_Algorithms/CubicSpline.o \
./src/Interpolation_Algorithms/Newton.o \
./src/Interpolation_Algorithms/Newton_1.o \
./src/Interpolation_Algorithms/cubic.o \
./src/Interpolation_Algorithms/test.o 

CPP_DEPS += \
./src/Interpolation_Algorithms/CubicSpline.d \
./src/Interpolation_Algorithms/Newton.d \
./src/Interpolation_Algorithms/Newton_1.d \
./src/Interpolation_Algorithms/cubic.d \
./src/Interpolation_Algorithms/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/Interpolation_Algorithms/%.o: ../src/Interpolation_Algorithms/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


