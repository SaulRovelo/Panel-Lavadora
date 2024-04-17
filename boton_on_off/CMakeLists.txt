add_executable(boton_on_off
    boton_on_off.c
)

target_link_libraries(boton_on_off
    pico_stdlib
    hardware_gpio
)

pico_add_extra_outputs(boton_on_off)