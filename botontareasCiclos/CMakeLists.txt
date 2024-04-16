add_executable(botontareasCiclos
    botontareasC.c
    ../common/sdk_inlines.c
)

target_link_libraries(botontareasCiclos
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botontareasCiclos) 