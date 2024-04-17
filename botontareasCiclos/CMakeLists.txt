add_executable(botontareasCiclos
    botontareasC.c
    #../common/sdk_inlines.c
)

target_link_libraries(botontareasCiclos
    pico_stdlib
    hardware_gpio
    pico_binary_info
)
# Habilitar stdio USB para pruebas
pico_enable_stdio_usb(botontareasCiclos 1)
pico_enable_stdio_uart(botontareasCiclos 0)

pico_add_extra_outputs(botontareasCiclos) 
