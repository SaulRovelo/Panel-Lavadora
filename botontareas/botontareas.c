//ejemplo pulsaciones
#include <stdio.h>
#include <pico/stdlib.h>

#define LED_PIN 0
#define BUTTON_PIN 1

int main(){
    // Función inicialización de todas las E/S
    stdio_init_all();

    // Inicializamos el led
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Inicializamos el boton
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Variables
    bool led_encendido = false;
    int pulsaciones = 0;
    uint32_t tiempo_anterior = 0;

   
    while (true){
        if (gpio_get(BUTTON_PIN) == 0) { // Verificar el estado del botón (0 o 1)
            uint32_t tiempo_actual = time_us_32(); // Obtener tiempo actual en microsegundos

            // Verificar si han pasado menos de 500ms desde la última pulsación
            if (tiempo_actual - tiempo_anterior < 500000) {
                pulsaciones++; // Incrementar contador de pulsaciones
            } else {
                pulsaciones = 1; // Reiniciar contador de pulsaciones
            }

            tiempo_anterior = tiempo_actual; // Actualizar tiempo anterior

            // Verificar si se han registrado dos pulsaciones consecutivas
            if (pulsaciones == 2) {
                if (!led_encendido) {
                    gpio_put(LED_PIN, 1); // Encender led
                    led_encendido = true; // Actualizar led encendido
                    printf("Lavadora encendida\n");
                } else {
                    gpio_put(LED_PIN, 0); // Apagar led
                    led_encendido = false; // Actualizar led apagado
                    printf("Lavadora apagada\n");
                }
                pulsaciones = 0; // Reiniciar contador de pulsaciones
            }
            
            sleep_ms(200); // Espera para evitar rebotes del botón
        }
    }
    
    return 0;
}
