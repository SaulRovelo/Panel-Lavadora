cmake_minimum_required(VERSION 3.15)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(Panel_lavadora C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(botonEncendido)
add_subdirectory(prenderLed)
add_subdirectory(botonAgua)
add_subdirectory(mainTest)
add_subdirectory(mainTestII)  
add_subdirectory(main)
#add_subdirectory(botonInicio)
# export PICO_SDK_PATH=../../pico-sdk