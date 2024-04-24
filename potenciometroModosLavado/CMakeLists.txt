add_executable(potenciometroModosLavado
    variables.h
    potenciometroModosLavado.h
    mainTest.c
)

target_link_libraries(potenciometroModosLavado
    pico_stdlib
    hardware_adc
)

pico_add_extra_outputs(potenciometroModosLavado)