cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(treasure_hunt C CXX ASM) set(CMAKE_C_STANDARD 11) set(CMAKE_CXX_STANDARD 17)

add_executable(PROJECT-25 src/main.cpp )

Include directories

target_include_directories(PROJECT-25 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include )

Link Pico SDK libraries

target_link_libraries(PROJECT-25 pico_stdlib hardware_pwm hardware_gpio )

Enable USB output, disable UART output

pico_enable_stdio_usb(PROJECT-25 1) pico_enable_stdio_uart(PROJECT-25 0)

pico_add_extra_outputs(PROJECT-25)

target_compile_options(PROJECT-25 PRIVATE -Wall -Wextra )