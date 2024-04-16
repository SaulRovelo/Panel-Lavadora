#include <stdio.h>
#include <pico/stdlib.h>

#define LED_PIN 0
#define BUTTON_PIN 1

int main(){
    // Función inicilizacion de todas la E/S
    stdio_init_all();

    // Inicializamos el led
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Inicializamos el boton
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Variable booleana (led apagado)
    bool led_encendido = false;

    //Bucle While
    while (true){
        if (gpio_get(BUTTON_PIN) == 0) //Verificar el estado del boton (0 o 1)
        {
            if (!led_encendido) 
            {
                gpio_put(LED_PIN, 1); // Encender led
                led_encendido = true; // Actualizar led encendido
                printf("Lavadora encendida\n");

            }else{ 
                gpio_put(LED_PIN, 0); // Apagar led
                led_encendido = false; // Actualizar led apagado
                printf("Lavadora apagada\n");

            }
            sleep_ms(200); // Espera para evitar rebotes del botón
        }
        
    }
    
    return 0;
}