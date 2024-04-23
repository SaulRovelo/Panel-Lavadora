#include <stdio.h>
#include <pico/stdlib.h>
#include "Variables.h"


void inicio(){
    // Inicializamos los LEDs
    gpio_init(LED_PIN_18);
    gpio_set_dir(LED_PIN_18, GPIO_OUT);

    gpio_init(LED_PIN_19);
    gpio_set_dir(LED_PIN_19, GPIO_OUT);
    
    gpio_init(LED_PIN_20);
    gpio_set_dir(LED_PIN_20, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN_21);
    gpio_set_dir(BUTTON_PIN_21, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_21);

}

void temperatura()
{
    if (gpio_get(BUTTON_PIN_21) == 0) // Verificar el estado del botón (0 o 1)
        {
            // Enciende el siguiente LED y apaga el anterior
            if (contadorT == 1) 
            {
                gpio_put(LED_PIN_18, 1); // Encender LED 1
                gpio_put(LED_PIN_19, 0); // Apagar LED 2
                gpio_put(LED_PIN_20, 0); // Apagar LED 3
                printf("Temperatura 1\n");
                contadorT = 2;
            } 
            
            else if (contadorT == 2) 
            {
                gpio_put(LED_PIN_18, 1); // Encender LED 1
                gpio_put(LED_PIN_19, 1); // Encender LED 2
                gpio_put(LED_PIN_20, 0); // Apagar LED 3
                printf("Temperatura 2\n");
                contadorT = 3;
            }

            else if (contadorT == 3) 
            {
                gpio_put(LED_PIN_18, 0); // Apagar LED 1
                gpio_put(LED_PIN_19, 1); // encender LED 2
                gpio_put(LED_PIN_20, 0); // apagar LED 3
                printf("Temperatura 3\n");
                contadorT = 4;
            }
            else if (contadorT == 4) 
            {
                gpio_put(LED_PIN_18, 0); // Apagar LED 1
                gpio_put(LED_PIN_19, 1); // encender LED 2
                gpio_put(LED_PIN_20, 1); // encender LED 3
                contadorT = 5;
            }
            else if (contadorT == 5) 
            {
                gpio_put(LED_PIN_18, 0); // Apagar LED 1
                gpio_put(LED_PIN_19, 0); // Apagar LED 2
                gpio_put(LED_PIN_20, 1); // encender LED 3
                contadorT = 6;
            }
            else if (contadorT == 6) 
            {
                gpio_put(LED_PIN_18, 0); // Apagar LED 1
                gpio_put(LED_PIN_19, 0); // Apagar LED 2
                gpio_put(LED_PIN_20, 0); // Apagar LED 3
                contadorT = 1;
            }
}
 }