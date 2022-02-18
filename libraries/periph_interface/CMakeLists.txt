
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

aux_source_directory(. SRCS)

add_library(${MODULE_NAME} STATIC
    ${SRCS})

target_include_directories(${MODULE_NAME} PUBLIC
    .)

target_link_libraries(${MODULE_NAME} periph_config)
