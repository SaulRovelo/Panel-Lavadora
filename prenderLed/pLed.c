#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#define LED_PIN 15

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1); // Enciende el LED
        sleep_ms(1000); // Espera 1 segundo
        gpio_put(LED_PIN, 0); // Apaga el LED
        sleep_ms(1000); // Espera 1 segundo
    }

    return 0;
}
