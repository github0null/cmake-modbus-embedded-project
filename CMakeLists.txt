cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

# Set up compiler and mcu arch 
set(COMPILER_TYPE "arm-none-eabi") # options: 'armcc' or 'arm-none-eabi'
set(MCU_ARCH_TYPE "cortex_m4") # options: 'cortex_m0', 'cortex_m3' ...
set(MCU_MFPU_TYPE "default") # options: 'sp', 'dp', 'none', 'default'

# Include toolchain config
include(${CMAKE_SOURCE_DIR}/cmake/${COMPILER_TYPE}/${MCU_ARCH_TYPE}.cmake)

# Set up project name
set(PRJ_NAME "modbus_rtu_embed")

# Set up the project
project(${PRJ_NAME}
    VERSION "0.1.0"
    LANGUAGES C ASM CXX)

# Add executable
aux_source_directory(main MAIN_SRCS)
add_executable(${PRJ_NAME} ${MAIN_SRCS})
target_include_directories(${PRJ_NAME} PUBLIC main)

# Add libraries
add_subdirectory(libraries)
target_link_libraries(${PRJ_NAME} periph_config modbus)

target_link_options(${PRJ_NAME} PRIVATE -T "${CMAKE_CURRENT_LIST_DIR}/STM32F407ZETx_FLASH.ld")
output_binary_files(${PRJ_NAME})
