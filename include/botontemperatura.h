#include <stdio.h>
#include <pico/stdlib.h>

#include "Variables.h"

void inicio(){
    // Inicializamos los LEDs
    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);

    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);
    
    gpio_init(LED_PIN_3);
    gpio_set_dir(LED_PIN_3, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

}

void temperatura(){
    if (gpio_get(BUTTON_PIN) == 0) // Verificar el estado del botón (0 o 1)
        {
            // Enciende el siguiente LED y apaga el anterior
            if (contador == 1) 
            {
                gpio_put(LED_PIN_1, 1); // Encender LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                printf("Temperatura 1\n");
                contador = 2;
            } 
            
            else if (contador == 2) 
            {
                gpio_put(LED_PIN_1, 1); // Encender LED 1
                gpio_put(LED_PIN_2, 1); // Encender LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                printf("Temperatura 2\n");
                contador = 3;
            }

            else if (contador == 3) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 1); // encender LED 2
                gpio_put(LED_PIN_3, 0); // apagar LED 3
                printf("Temperatura 3\n");
                contador = 4;
            }
            else if (contador == 4) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 1); // encender LED 2
                gpio_put(LED_PIN_3, 1); // encender LED 3
                contador = 5;
            }
            else if (contador == 5) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 1); // encender LED 3
                contador = 6;
            }
            else if (contador == 6) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                contador = 1;
            }
}