#include <stdio.h>
#include <pico/stdlib.h>
#include "pico/stdlib.h"
#include "bAgua.h"

#define LED_PIN_1 0
#define LED_PIN_2 1
#define LED_PIN_3 2
#define LED_PIN_4 3
#define LED_PIN_5 4
#define BUTTON_PIN_2 5

// Variable para controlar el estado de los LEDs
static int contador = 0;

void inicializar_leds_agua() {
    // Función inicialización 
    //stdio_init_all();

    // Inicializamos los LEDs
    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);
    gpio_init(LED_PIN_3);
    gpio_set_dir(LED_PIN_3, GPIO_OUT);
    gpio_init(LED_PIN_4);
    gpio_set_dir(LED_PIN_4, GPIO_OUT);
    gpio_init(LED_PIN_5);
    gpio_set_dir(LED_PIN_5, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN_2);
    gpio_set_dir(BUTTON_PIN_2, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_2);
}


void control_leds_agua() {
    printf("Dentro nivel agua\n");
    if (gpio_get(BUTTON_PIN_2) == 0) {    // Verificar el estado del botón (0 o 1)
        if (contador == 0) {
            // Enciende el siguiente LED y apaga el anterior
            printf("Dentro nivel agua 1 \n");
            gpio_put(LED_PIN_1, 1);
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            printf("Seleccion: Nivel 1\n");
            contador = 1;
        } else if (contador == 1) {
            gpio_put(LED_PIN_1, 0);
            gpio_put(LED_PIN_2, 1);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            printf("Seleccion: Nivel 2\n");
            contador = 2;
        } else if (contador == 2) {
            gpio_put(LED_PIN_1, 0);
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 1);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            printf("Seleccion: Nivel 3\n");
            contador = 3;
        } else if (contador == 3) {
            gpio_put(LED_PIN_1, 0);
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 1);
            gpio_put(LED_PIN_5, 0);
            printf("Seleccion: Nivel 4\n");
            contador = 4;
        } else if (contador == 4) {
            gpio_put(LED_PIN_1, 0);
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 1);
            printf("Seleccion: Nivel 5\n");
            contador = 5;
        } else if (contador == 5) {
            gpio_put(LED_PIN_1, 0);
            gpio_put(LED_PIN_2, 0);
            gpio_put(LED_PIN_3, 0);
            gpio_put(LED_PIN_4, 0);
            gpio_put(LED_PIN_5, 0);
            printf("Ningún nivel seleccionado\n");
            contador = 0;
        }
        sleep_ms(200); 
    }
}
