#include <stdio.h>
#include <pico/stdlib.h>
#include "variables.h"


void inicializar_Leds_temperatura(){
    // Inicializamos los LEDs
    gpio_init(LED_PIN_18);
    gpio_set_dir(LED_PIN_18, GPIO_OUT);

    gpio_init(LED_PIN_21);
    gpio_set_dir(LED_PIN_21, GPIO_OUT);
    
    gpio_init(LED_PIN_22);
    gpio_set_dir(LED_PIN_22, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN_27);
    gpio_set_dir(BUTTON_PIN_27, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_27);

}
void control_leds_temperatura()
{
    if (gpio_get(BUTTON_PIN_27) == 0) // Verificar el estado del botón (0 o 1)
        {
            // Enciende el siguiente LED y apaga el anterior
            if (contadorT == 1) 
            {
                gpio_put(LED_PIN_18, 1); // Encender LED 1
                gpio_put(LED_PIN_21, 0); // Apagar LED 2
                gpio_put(LED_PIN_22, 0); // Apagar LED 3
                printf("Temperatura 1\n");
                contadorT = 2;
            } 