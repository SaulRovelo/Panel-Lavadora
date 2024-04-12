add_executable(botonEncendido
    botonEnc.c
    ../common/sdk_inlines.c

)

target_link_libraries(botonEncendido
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botonEncendido)
