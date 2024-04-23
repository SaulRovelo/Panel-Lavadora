add_executable(mainTestII
    mainTestII.c
)


target_link_libraries(mainTestII
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

target_include_directories(mainTestII
    PRIVATE
    ../include
)

pico_add_extra_outputs(mainTestII)

pico_enable_stdio_usb(mainTestII 1)
pico_enable_stdio_uart(mainTestII 0)
