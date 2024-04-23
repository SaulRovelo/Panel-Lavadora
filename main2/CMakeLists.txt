add_executable(main2
    main.c
)

target_link_libraries(main2
    pico_stdlib
    hardware_adc
)

target_include_directories(main2
    PRIVATE
    ../include
)

pico_add_extra_outputs(main2)