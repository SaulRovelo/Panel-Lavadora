add_executable(botonInicioPausa
    botonIP.c
    ../common/sdk_inlines.c

)

target_link_libraries(botonInicioPausa
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_enable_stdio_usb(botonInicioPausa 1)
pico_enable_stdio_uart(botonInicioPausa 0)

pico_add_extra_outputs(botonInicioPausa)