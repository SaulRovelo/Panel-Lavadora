add_executable(4digitSegment
    main.c
)

target_link_libraries(4digitSegment
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_enable_stdio_usb(4digitSegment 1)
pico_enable_stdio_uart(4digitSegment 0)

pico_add_extra_outputs(4digitSegment)