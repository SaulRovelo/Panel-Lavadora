cmake_minimum_required(VERSION 3.15)
set (PICO_SDK_PATH "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/pico-sdk")
# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(Panel_lavadora C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(Led_start)