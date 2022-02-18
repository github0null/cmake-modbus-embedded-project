
set(MODULE_NAME "periph_config")

aux_source_directory(Core/Src CORE_SRCS)
aux_source_directory(Drivers/STM32F4xx_HAL_Driver/Src DRV_SRCS)

add_library(${MODULE_NAME} STATIC 
    ${CORE_SRCS}
    ${DRV_SRCS}
    startup_stm32f407xx.s)

target_include_directories(${MODULE_NAME} PUBLIC 
    Core/Inc
    Drivers/CMSIS/Include
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/STM32F4xx_HAL_Driver/Inc
    Drivers/STM32F4xx_HAL_Driver/Inc/Legacy)

target_compile_definitions(${MODULE_NAME} PUBLIC    
    USE_HAL_DRIVER
    STM32F407xx)
