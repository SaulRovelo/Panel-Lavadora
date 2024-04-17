add_executable(main

    
    main.c
    
    
    ../common/sdk_inlines.c
)

target_link_libraries(main
        pico_stdlib
    hardware_gpio
    pico_binary_info
)

pico_add_extra_outputs(main)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)