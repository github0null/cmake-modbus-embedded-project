cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

# Set up compiler and mcu arch 
set(COMPILER_TYPE "arm-none-eabi") # options: 'armcc' or 'arm-none-eabi'
set(MCU_ARCH_TYPE "cortex_m4") # options: 'cortex_m0', 'cortex_m3' ...
set(MCU_MFPU_TYPE "default") # options: 'sp', 'dp', 'none', 'default'

# flasher config
set(FLASHER_TYPE_NAME "jlink")
set(FLASHER_PORT_TYPE "swd")
set(FLASHER_MCPU_NAME "STM32F407ZG")

# Include toolchain config
include(${CMAKE_SOURCE_DIR}/cmake/toolchain/${COMPILER_TYPE}/${MCU_ARCH_TYPE}.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/flasher/${FLASHER_TYPE_NAME}-${FLASHER_PORT_TYPE}.cmake)

# Set up project name
set(PRJ_NAME "modbus_rtu_embed")

# Set up the project
project(${PRJ_NAME}
    VERSION "0.1.0"
    LANGUAGES C ASM CXX)

# Add libraries
add_subdirectory(libraries)
add_subdirectory(main)
