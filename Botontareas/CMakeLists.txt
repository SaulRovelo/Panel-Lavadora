add_executable(Botontareas
    botontareas.c
    botontareas.h
    variables.h 

)

target_link_libraries(Botontareas
    pico_stdlib
    hardware_adc
)

pico_add_extra_outputs(Botontareas)