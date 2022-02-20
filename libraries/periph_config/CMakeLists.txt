#
# add sub folder by device name
#
file(GLOB sub_files RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_CURRENT_LIST_DIR}/*")
foreach(dir_name ${sub_files})
    if(${dir_name} STREQUAL ${MCPU_NAME})
        if(IS_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/${dir_name}")
            if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${dir_name}/CMakeLists.txt")
                add_subdirectory("${dir_name}")
                set(periph_conf_valid true)
                break()
            endif()
        endif()
    endif()
endforeach()

if(NOT periph_conf_valid)
    message(FATAL_ERROR "Now, we not support device: '${MCPU_NAME}'")
endif()
