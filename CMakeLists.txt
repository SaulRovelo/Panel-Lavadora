cmake_minimum_required(VERSION 3.13)


# Agregar tus archivos fuente al proyecto
add_executable(hello_7segment
        hello_7segment.S
        ../common/sdk_inlines.c
        
)

# Enlazar la biblioteca estándar a tu ejecutable
target_link_libraries(hello_7segment pico_stdlib)


# create map/bin/hex file etc.
pico_add_extra_outputs(hello_7segment)