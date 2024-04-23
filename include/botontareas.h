
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
void ciclos() {
    uint32_t tiempo_actual = time_us_32(); // Obtener tiempo actual en microsegundos

    // Verificar si se ha pulsado el botón
    if (condicion()) {
        // Verificar si ha pasado menos de 500ms desde la última pulsación
        if (tiempo_actual - tiempo_anterior < 500000) {
            pulsaciones++; // Incrementar contador de pulsaciones
        } else {
            pulsaciones = 1; // Reiniciar contador de pulsaciones
        }
    }

    // Actualizar tiempo anterior
    tiempo_anterior = tiempo_actual;

    // Verificar si el botón está siendo presionado
    if (condicion()) {
        tiempo_presionado = tiempo_actual; // Actualizar tiempo de inicio de presión del botón
        boton_presionado = true; // Indicar que el botón está siendo presionado
    } else {
        // Verificar si se ha mantenido presionado por 2 segundos
        if (tiempo_actual - tiempo_presionado >= 2000000) {
            // Apagar todos los LEDs
            gpio_put(LED1_PIN, 0);
            gpio_put(LED2_PIN, 0);
            gpio_put(LED3_PIN, 0);
            pulsaciones = 0; // Reiniciar contador de pulsaciones
        }
        boton_presionado = false; // Indicar que el botón no está siendo presionado
    }

    // Realizar acciones según el número de pulsaciones
    switch (pulsaciones) {
        case 1:
            gpio_put(LED1_PIN, 1); // Encender LED 1
            gpio_put(LED2_PIN, 0); // Apagar LED 2
            gpio_put(LED3_PIN, 0); // Apagar LED 3
            break;
        case 2:
            gpio_put(LED1_PIN, 0); // Apagar LED 1
            gpio_put(LED2_PIN, 1); // Encender LED 2
            gpio_put(LED3_PIN, 1); // Encender LED 3
            break;
        case 3:
            gpio_put(LED1_PIN, 1); // Encender LED 1
            gpio_put(LED2_PIN, 1); // Encender LED 2
            gpio_put(LED3_PIN, 1); // Encender LED 3
            break;
        default:
            // No hacer nada en otros casos
            break;
    }
}
