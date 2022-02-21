
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

aux_source_directory(. MAIN_SRCS)

add_executable(${PROJECT_NAME}
    ${MAIN_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC 
    .)

target_link_libraries(${PROJECT_NAME} 
    periph_config
    modbus)

target_link_options(${PROJECT_NAME} PRIVATE
    -Wl,-Map=./${PROJECT_NAME}.map)

output_binary_files(${PROJECT_NAME})
output_flash_command(${PROJECT_NAME})
