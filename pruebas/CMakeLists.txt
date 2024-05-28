add_executable(pruebas
    pruebasZumbador.c
)

target_link_libraries(pruebas
    pico_stdlib
)

target_include_directories(pruebas
    PRIVATE
    ../include
)

pico_add_extra_outputs(pruebas)

pico_enable_stdio_usb(pruebas 1)
pico_enable_stdio_uart(pruebas 1)
