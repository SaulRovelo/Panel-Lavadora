add_executable(Led_start
    Led_start.c
)

target_link_libraries(Led_start
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(Led_start)