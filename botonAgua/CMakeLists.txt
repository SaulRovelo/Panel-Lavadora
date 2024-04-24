add_executable(botonAgua
    botonAgua.c
    variables.h
    # bAgua.c
)

target_link_libraries(botonAgua
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botonAgua)

pico_enable_stdio_usb(botonAgua 1)
pico_enable_stdio_uart(botonAgua 0)
