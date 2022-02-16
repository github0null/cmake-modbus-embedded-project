# gen config header
file(READ "./configure.ac" modbus_cfg_str)
string(REGEX MATCH "m4_define\\(\\[libmodbus_version_major\\], \\[([0-9]+)\\]\\)" LIBMODBUS_VERSION_MAJOR ${modbus_cfg_str})
string(REGEX MATCH "m4_define\\(\\[libmodbus_version_minor\\], \\[([0-9]+)\\]\\)" LIBMODBUS_VERSION_MINOR ${modbus_cfg_str})
string(REGEX MATCH "m4_define\\(\\[libmodbus_version_micro\\], \\[([0-9]+)\\]\\)" LIBMODBUS_VERSION_MICRO ${modbus_cfg_str})
string(REGEX REPLACE "m4_define\\(\\[libmodbus_version_major\\], \\[([0-9]+)\\]\\)" "\\1" LIBMODBUS_VERSION_MAJOR ${LIBMODBUS_VERSION_MAJOR})
string(REGEX REPLACE "m4_define\\(\\[libmodbus_version_minor\\], \\[([0-9]+)\\]\\)" "\\1" LIBMODBUS_VERSION_MINOR ${LIBMODBUS_VERSION_MINOR})
string(REGEX REPLACE "m4_define\\(\\[libmodbus_version_micro\\], \\[([0-9]+)\\]\\)" "\\1" LIBMODBUS_VERSION_MICRO ${LIBMODBUS_VERSION_MICRO})
configure_file("src/modbus-version.h.in" "src/modbus-version.h" @ONLY)
configure_file("src/win32/config.h.win32" "config.h" COPYONLY @ONLY)

# add sources
set(libmodbus_SRCS
    src/modbus-data.c
    src/modbus-rtu.c
    src/modbus.c)

add_library(libmodbus STATIC 
    ${libmodbus_SRCS})

target_include_directories(libmodbus PUBLIC 
    src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/src)