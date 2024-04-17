add_executable(potenciometroModosLavado
    potenciometroModosLavado.c
)

target_link_libraries(potenciometroModosLavado
    pico_stdlib
    hardware_adc
)

pico_enable_stdio_usb(potenciometroModosLavado 1)
pico_enable_stdio_uart(potenciometroModosLavado 0)

pico_add_extra_outputs(potenciometroModosLavado)