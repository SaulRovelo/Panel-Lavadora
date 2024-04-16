add_executable(botonEncendido
    bEncendido.S
    ../common/sdk_inlines.c
)

target_link_libraries(botonEncendido
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botonEncendido)

pico_enable_stdio_usb(botonEncendido 1)
pico_enable_stdio_uart(botonEncendido 0)
