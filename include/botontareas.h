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

void control_leds_tareas(){
    if (gpio_get(BUTTON_PIN) == 0){ // Verificar el estado del botón (0 o 1)
        // Enciende el siguiente LED y apaga el anterior
        if (contadorTA == 1) 
        {
            gpio_put(LED_PIN_14, 1); // Encender LED 1
            gpio_put(LED_PIN_15, 0); // Apagar LED 2
            gpio_put(LED_PIN_16, 0); // Apagar LED 3
        
            contadorTA = 2;
        } 
        
        else if (contadorTA == 2) 
        {
            gpio_put(LED_PIN_14, 0); // Encender LED 1
            gpio_put(LED_PIN_15, 1); // Encender LED 2
            gpio_put(LED_PIN_16, 1); // Apagar LED 3
        
            contadorTA = 3;
        }

        else if (contadorTA == 3) 
        {
            gpio_put(LED_PIN_14, 1); // Apagar LED 1
            gpio_put(LED_PIN_15, 1); // encender LED 2
            gpio_put(LED_PIN_16, 1); // apagar LED 3
            
            contadorTA = 4;
        }
        else if (contadorTA == 4) 
        {
            gpio_put(LED_PIN_14, 0); // Apagar LED 1
            gpio_put(LED_PIN_15, 0); // encender LED 2
            gpio_put(LED_PIN_16, 0); // encender LED 3
            contadorTA = 1;
        }
        uart_puts(uart0, "s3");
    }
}