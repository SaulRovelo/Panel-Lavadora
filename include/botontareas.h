
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

bool condicion() {
    // Verificar el estado del botón (0 o 1)
    return gpio_get(BUTTON_PIN) == 0;
}
void handleLEDs() {
    uint32_t tiempo_actual = time_us_32(); // Obtener tiempo actual en microsegundos

    if (pulsaciones > 3) {
        pulsaciones = 0; // Reiniciar contador de pulsaciones si es mayor que 3
    }

    if (isButtonPressed()) {
        // Verificamos si han pasado menos de 500ms desde la última pulsación
        if (tiempo_actual - tiempo_anterior < 500000) {
            pulsaciones++; // Incrementar contador de pulsaciones
        } else {
            pulsaciones = 1; // Reiniciar contador de pulsaciones
        }
    }