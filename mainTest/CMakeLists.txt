add_executable(mainTest
    main.c
    botonIP.c
    botonIP.h
    ../common/sdk_inlines.c

)

target_link_libraries(mainTest
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_enable_stdio_usb(mainTest 1)
pico_enable_stdio_uart(mainTest 0)

pico_add_extra_outputs(mainTest)