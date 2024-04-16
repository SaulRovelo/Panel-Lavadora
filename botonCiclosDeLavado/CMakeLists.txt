add_executable(botonCiclosDeLavado
    botonCiclos.c
    ../common/sdk_inlines.c

)

target_link_libraries(botonCiclosDeLavado
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botonCiclosDeLavado)