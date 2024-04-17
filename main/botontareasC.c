#include <stdio.h>
#include <pico/stdlib.h>
#include <stdlib.h>

#define LED_PIN_1 0
#define LED_PIN_2 1
#define LED_PIN_3 2
#define LED_PIN_4 3
#define LED_PIN_5 4
#define LED_PIN_6 5
#define BUTTON_PIN 6

void ciclos(){
    // Función inicialización 
    stdio_init_all();

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
    gpio_init(LED_PIN_6);
    gpio_set_dir(LED_PIN_6, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Variable para controlar el estado de los LEDs
    int contador = 1;

    while (true){
        if (gpio_get(BUTTON_PIN) == 0) // Verificar el estado del botón (0 o 1)
        {
            // Enciende el siguiente LED y apaga el anterior
            if (contador == 1) 
            {
                gpio_put(LED_PIN_1, 1); // Encender LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                gpio_put(LED_PIN_4, 0); // Apagar LED 4
                gpio_put(LED_PIN_5, 0); // Apagar LED 5
                gpio_put(LED_PIN_6, 0); // Apagar LED 6
                printf("Normal\n");
                contador = 2;
            } 
            else if (contador == 2) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 1); // Encender LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                gpio_put(LED_PIN_4, 0); // Apagar LED 4
                gpio_put(LED_PIN_5, 0); // Apagar LED 5
                gpio_put(LED_PIN_6, 0); // Apagar LED 6
                printf("Lavado rapido\n");
                contador = 3;
            }
            else if (contador == 3) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 1); // Encender LED 3
                gpio_put(LED_PIN_4, 0); // Apagar LED 4
                gpio_put(LED_PIN_5, 0); // Apagar LED 5
                gpio_put(LED_PIN_6, 0); // Apagar LED 6
                printf("Delicados\n");
                contador = 4;
            }
            else if (contador == 4) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                gpio_put(LED_PIN_4, 1); // Encender LED 4
                gpio_put(LED_PIN_5, 0); // Apagar LED 5
                gpio_put(LED_PIN_6, 0); // Apagar LED 6
                printf("Ropa de cama\n");
                contador = 5;
            }
            else if (contador == 5) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                gpio_put(LED_PIN_4, 0); // Apagar LED 4
                gpio_put(LED_PIN_5, 1); // Encender LED 5
                gpio_put(LED_PIN_6, 0); // Apagar LED 6
                printf("Jeans\n");
                contador = 6;
            }
            else if (contador == 6) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                gpio_put(LED_PIN_4, 0); // Apagar LED 4
                gpio_put(LED_PIN_5, 0); // Apagar LED 5
                gpio_put(LED_PIN_6, 1); // Encender LED 6
                printf("Lavado eco de tambor\n");
                contador = 7;
            }
             else if (contador == 7) 
            {
                gpio_put(LED_PIN_1, 0); // Apagar LED 1
                gpio_put(LED_PIN_2, 0); // Apagar LED 2
                gpio_put(LED_PIN_3, 0); // Apagar LED 3
                gpio_put(LED_PIN_4, 0); // Apagar LED 4
                gpio_put(LED_PIN_5, 0); // Apagar LED 5
                gpio_put(LED_PIN_6, 0); // Apagar LED 6
               return; 
            }
            while(gpio_get(BUTTON_PIN) == 0); // Esperar hasta que el botón se suelte
        }
    }
    
}
