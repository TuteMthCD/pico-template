cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_SDK_FETCH_FROM_GIT ON)

include(extern/pico-sdk/external/pico_sdk_import.cmake)

include_directories(extern/gcc-arm-none-eabi-win32/main/arm-none-eabi/include)

project(firm C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#seteo la board de Wifi
set(PICO_BOARD pico_w)

pico_sdk_init()

#add main.cpp
add_executable(${PROJECT_NAME} src/main.cpp)

pico_add_extra_outputs(${PROJECT_NAME})

#uart pins?
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

#extern libs
target_link_libraries(${PROJECT_NAME}
	pico_stdlib              # for core functionality
    pico_cyw43_arch_none     # we need Wifi
) 
