cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

# Set up compiler and mcu arch 
set(COMPILER_TYPE "armcc") # options: 'armcc' or 'arm-none-eabi'
set(MCU_ARCH_TYPE "cortex_m3") # options: 'cortex_m0', 'cortex_m3' ...
set(MCU_MFPU_TYPE "default") # options: 'sp', 'dp', 'none', 'default'
set(TOOLCHAIN_DIR "D:/Keil/ARM/ARMCC/bin") # toolchain root folder for armcc

# Include toolchain config
include(${CMAKE_SOURCE_DIR}/cmake/${COMPILER_TYPE}/${MCU_ARCH_TYPE}.cmake)

# Set up project name
set(PRJ_NAME "modbus_rtu_embed")

# Set up the project
project(${PRJ_NAME}
    VERSION "0.1.0"
    LANGUAGES C ASM CXX)

set(VERBOSE true)
set(CMAKE_VERBOSE_MAKEFILE on)

# Build test project
add_subdirectory(libraries)
add_subdirectory(main)
