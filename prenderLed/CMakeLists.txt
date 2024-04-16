add_executable(prenderLed
    pLed.c
)

target_link_libraries(prenderLed
    pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(prenderLed)
