#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
//asigna el numero de pin para cada marco
#define LED_PIN 11
#define BOTON_PIN 12

int main() {
    // Inicializa entradas salidas de stdio
    stdio_init_all(); 
    // Inicializa el pin del LED
    gpio_init(LED_PIN);
    // Pin del LED como salida
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);
    // Inicializa el pin del botón
    gpio_init(BOTON_PIN);
    //pin del botón como entrada 
    gpio_set_dir(BOTON_PIN, GPIO_IN);
    //asegura que el pin del botón tenga un valor 1 por lo que detecta cuendo el boton es precionado
    gpio_pull_up(BOTON_PIN);

    //Variables inician en Flse
    bool boton_pres = false;
    bool led_on = false;

    while (true) {
        // Verifica si el botón está presionado
        if (!gpio_get(BOTON_PIN)) {
            if (!boton_pres) {
                // Cambia el estado del LED solo si el botón no estaba presionado
                gpio_put(LED_PIN, !led_on);
                led_on = !led_on;
            }
            boton_pres = true;
        } else {
            boton_pres = false;
        }
    }

    return 0;
}
