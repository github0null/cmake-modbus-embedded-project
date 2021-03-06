#
# gen config header
#
file(READ "./configure.ac" modbus_cfg_str)
string(REGEX MATCH "m4_define\\(\\[libmodbus_version_major\\], \\[([0-9]+)\\]\\)" LIBMODBUS_VERSION_MAJOR ${modbus_cfg_str})
string(REGEX MATCH "m4_define\\(\\[libmodbus_version_minor\\], \\[([0-9]+)\\]\\)" LIBMODBUS_VERSION_MINOR ${modbus_cfg_str})
string(REGEX MATCH "m4_define\\(\\[libmodbus_version_micro\\], \\[([0-9]+)\\]\\)" LIBMODBUS_VERSION_MICRO ${modbus_cfg_str})
string(REGEX REPLACE "m4_define\\(\\[libmodbus_version_major\\], \\[([0-9]+)\\]\\)" "\\1" LIBMODBUS_VERSION_MAJOR ${LIBMODBUS_VERSION_MAJOR})
string(REGEX REPLACE "m4_define\\(\\[libmodbus_version_minor\\], \\[([0-9]+)\\]\\)" "\\1" LIBMODBUS_VERSION_MINOR ${LIBMODBUS_VERSION_MINOR})
string(REGEX REPLACE "m4_define\\(\\[libmodbus_version_micro\\], \\[([0-9]+)\\]\\)" "\\1" LIBMODBUS_VERSION_MICRO ${LIBMODBUS_VERSION_MICRO})
configure_file("src/modbus-version.h.in" "src/modbus-version.h" @ONLY)

set(LIBMODBUS_VERSION "${LIBMODBUS_VERSION_MAJOR}.${LIBMODBUS_VERSION_MINOR}.${LIBMODBUS_VERSION_MICRO}")
configure_file("ports/config.h.in" "conf/config.h" @ONLY)

#
# add sources
#
set(LIB_NAME "modbus")

set(libmodbus_SRCS
    src/modbus.c
    src/modbus-data.c
    src/modbus-rtu.c
    ports/modbus_port.c
    ports/modbus_rtu_port.c)

add_library(${LIB_NAME} OBJECT 
    ${libmodbus_SRCS})

target_include_directories(${LIB_NAME} PUBLIC 
    src
    ports
    ${CMAKE_CURRENT_BINARY_DIR}/src)

target_include_directories(${LIB_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/conf)

target_link_libraries(${LIB_NAME} periph_config)
