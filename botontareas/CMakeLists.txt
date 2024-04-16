add_executable(botontareas
    botontareas.c
    ../common/sdk_inlines.c
)

target_link_libraries(botontareas
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botontareas) 