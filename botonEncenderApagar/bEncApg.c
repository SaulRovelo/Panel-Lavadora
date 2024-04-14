#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#define LED_PIN 15
#define BUTTON_PIN 14

bool boton_presionado = false;
bool led_encendido = false;

void button_callback() {
    boton_presionado = true;
}

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (true) {
        if (boton_presionado) {
            if (led_encendido) {
                // Si el LED está encendido, apágalo
                gpio_put(LED_PIN, 0);
                led_encendido = false;
            } else {
                // Si el LED está apagado, enciéndelo
                gpio_put(LED_PIN, 1);
                led_encendido = true;
            }
            boton_presionado = false; // Reinicia el estado del botón
            sleep_ms(200); // Espera para evitar rebotes del botón
        }
    }

    return 0;
}
