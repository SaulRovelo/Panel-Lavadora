
#include <stdio.h>
#include <pico/stdlib.h>
#include "Variables.h"

void inicializar() {

    // Inicialización de los LED
    gpio_init(LED1_PIN);
    gpio_set_dir(LED1_PIN, GPIO_OUT);
    gpio_init(LED2_PIN);
    gpio_set_dir(LED2_PIN, GPIO_OUT);
    gpio_init(LED3_PIN);
    gpio_set_dir(LED3_PIN, GPIO_OUT);

    // Inicialización del botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}

bool isButtonPressed() {
    // Verificar el estado del botón (0 o 1)
    return gpio_get(BUTTON_PIN) == 0;
}