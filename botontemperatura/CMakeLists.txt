add_executable(botontemperatura
    main.c
    led_control.h
    botontemp.c
    ../common/sdk_inlines.c
)

target_link_libraries(botontemperatura
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(botontemperatura)