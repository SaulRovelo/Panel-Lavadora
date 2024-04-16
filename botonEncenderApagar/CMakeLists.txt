add_executable(botonEncenderApagar
    bEncApg.S
    ../common/sdk_inlines.c
)

target_link_libraries(botonEncenderApagar
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botonEncenderApagar)

pico_enable_stdio_usb(botonEncenderApagar 1)
pico_enable_stdio_uart(botonEncenderApagar 0)
