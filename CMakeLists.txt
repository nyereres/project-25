# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if(EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(Pico_ePaper_Code)
pico_sdk_init()

# Add compilation subdirectory
add_subdirectory(lib/Config)
add_subdirectory(lib/Devices)
add_subdirectory(examples)

# Add header file directory
include_directories(examples)
include_directories(./lib/Config)
include_directories(./lib/Devices)

# Generate executable file using the file from c for now, will change it to c++ file later.
add_executable(main
    main.cpp
    motor.cpp
    servo.cpp
    obstacle.cpp
    lib/Devices/MotorDriver.cpp
    lib/Devices/PCA9685.cpp
    lib/Config/DEV_Config.cpp
    sensor.cpp
    coordinates.cpp
)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(main)

# Explicitly added PCA9685 and DEV_Config to the target_link_libraries command.
target_link_libraries(main examples Config pico_stdlib Devices hardware_i2c)
