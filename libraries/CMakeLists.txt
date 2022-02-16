#
# auto add subdirectory
#
file(GLOB sub_dirs RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_CURRENT_LIST_DIR}/*")
foreach(dir_name ${sub_dirs})
    if(IS_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/${dir_name}")
        if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${dir_name}/CMakeLists.txt")
            add_subdirectory("${dir_name}")
        endif()
    endif()
endforeach()
