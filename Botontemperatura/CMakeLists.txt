add_executable(Botontemperatura
    botontemperatura.c
    botontemperatura.h
    variables.h 

)

target_link_libraries(Botontareas
    pico_stdlib
    hardware_adc
)

pico_add_extra_outputs(Botontareas)