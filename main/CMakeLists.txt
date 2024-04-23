add_executable(main
    main.c
)

target_link_libraries(main
    pico_stdlib
    hardware_adc
)

target_include_directories(main
    PRIVATE
    ../include
)

pico_add_extra_outputs(main)