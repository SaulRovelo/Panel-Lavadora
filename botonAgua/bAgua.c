#include <stdio.h>
#include <pico/stdlib.h>
#include "pico/stdlib.h"
#include "bAgua.h"

#define LED_PIN_2 2
#define LED_PIN_3 3
#define LED_PIN_4 4
#define LED_PIN_5 5
#define LED_PIN_6 6
#define BUTTON_PIN_7 7

// Variable para controlar el estado de los LEDs
static int contador = 0;

// Función inicialización de pines
void inicializar_leds_agua() {
    // Inicializamos los LEDs
    //stdio_init_all();
    for (int i = LED_PIN_2; i <= LED_PIN_5; i++) {
        gpio_init(i);        // Inicializamos el pin
        gpio_set_dir(i, GPIO_OUT); // Configuramos como salida
    }

    // Inicializamos el botón
    gpio_init(BUTTON_PIN_7);
    gpio_set_dir(BUTTON_PIN_7, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_7);
}



// Función para controlar el estado de los LEDs según el botón presionado
void control_leds_agua() {
    if (gpio_get(BUTTON_PIN_7) == 0) {    // Verificar el estado del botón (0 o 1)
        if (contador == 5) {
            // Si el contador llega a 5, apagamos todos los LEDs
            for (int i = LED_PIN_2; i <= LED_PIN_5; i++) {
                gpio_put(i, 0);
            }
            printf("Ningún nivel seleccionado\n");
            contador = 0;
        } else {
            // Enciende el siguiente LED y apaga el anterior
            gpio_put(LED_PIN_2 + contador, 1);
            if (contador > 0) {
                gpio_put(LED_PIN_2 + contador - 1, 0);
            }
            printf("Seleccion: Nivel %d\n", contador + 1);
            contador++;
        }
        sleep_ms(200); 
    }
}

