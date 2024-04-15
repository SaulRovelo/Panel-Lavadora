#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#define LED_PIN 15
#define BUTTON_PIN 14

bool boton_presionado = false;
bool led_encendido = false;

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    while (true) {
        // Verifica si el botón está presionado
        if (!gpio_get(BUTTON_PIN)) {
            if (!boton_presionado) {
                // Cambia el estado del LED solo si el botón no estaba previamente presionado
                gpio_put(LED_PIN, !led_encendido);
                led_encendido = !led_encendido;
            }
            boton_presionado = true;
        } else {
            boton_presionado = false;
        }
    }

    return 0;
}