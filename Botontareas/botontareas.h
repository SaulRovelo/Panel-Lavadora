#include <stdio.h>
#include <pico/stdlib.h>
#include "variables.h"

void inicializar_leds_tareas() {

    // Inicialización de los LED
    gpio_init(LED_PIN_14);
    gpio_set_dir(LED_PIN_14, GPIO_OUT);
    gpio_init(LED_PIN_15);
    gpio_set_dir(LED_PIN_15, GPIO_OUT);
    gpio_init(LED_PIN_16);
    gpio_set_dir(LED_PIN_16, GPIO_OUT);

    // Inicialización del botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}