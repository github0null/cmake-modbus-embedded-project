
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

aux_source_directory(. MAIN_SRCS)

add_executable(${PRJ_NAME} 
    ${MAIN_SRCS})

target_include_directories(${PRJ_NAME} PUBLIC 
    .)

target_link_libraries(${PRJ_NAME} periph_interface modbus)

target_link_options(${PRJ_NAME} PRIVATE 
    -T "${CMAKE_SOURCE_DIR}/STM32F407ZETx_FLASH.ld")

output_binary_files(${PRJ_NAME})
output_flash_command(${PRJ_NAME})
