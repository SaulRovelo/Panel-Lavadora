#include <stdio.h>
#include "pico/stdlib.h"
#include "variables.h"


// Función inicialización de pines
void inicializar_leds_agua() {
    // Inicializamos los LEDs
    //stdio_init_all();
    for (int i = LED_PIN_2; i <= LED_PIN_6; i++) {
        gpio_init(i);        // Inicializamos el pin
        gpio_set_dir(i, GPIO_OUT); // Configuramos como salida
    }
    // Inicializamos el botón
    gpio_init(BUTTON_PIN_7);
    gpio_set_dir(BUTTON_PIN_7, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_7);
}

// Función de control de LEDs
void control_leds_agua() {
    if (gpio_get(BUTTON_PIN_7) == 0) {    // Verificar el estado del botón (0 o 1)
        if (contador == 0) {
            // Enciende el siguiente LED y apaga el anterior
            gpio_put(LED_PIN_2, 1);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            gpio_put(LED_PIN_6, 0);
            printf("Seleccion: Nivel 1\n");
            contador = 1;
        } else if (contador == 1) {
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 1);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            gpio_put(LED_PIN_6, 0);
            printf("Seleccion: Nivel 2\n");
            contador = 2;
        } else if (contador == 2) {
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 1);
            gpio_put(LED_PIN_5, 0);
            gpio_put(LED_PIN_6, 0);
            printf("Seleccion: Nivel 3\n");
            contador = 3;
        } else if (contador == 3) {
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 1);
            gpio_put(LED_PIN_6, 0);
            printf("Seleccion: Nivel 4\n");
            contador = 4;
        } else if (contador == 4) {
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            gpio_put(LED_PIN_6, 1);
            printf("Seleccion: Nivel 5\n");
            contador = 5;
        } else if (contador == 5) {
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            gpio_put(LED_PIN_6, 0);
            printf("Ningún nivel seleccionado\n");
            contador = 0;
        }
        //sleep_ms(200); 
    }
}

