#include "boton_encendido.h"
#include <stdio.h>
#include <pico/stdlib.h>
#include "pico/stdlib.h"

#define TOTAL_GPIO_PINS 26

#define LED_PIN_6 6
#define BUTTON_PIN_7 7

static bool led_encendido = false;

// Implementación de la función para apagar todos los LEDs
void apagar_todos_los_leds() {
    // Apaga todas las salidas GPIO
    for (int pin = 0; pin < TOTAL_GPIO_PINS; pin++) {
        gpio_put(pin, 0);
    }
}

void inicializar_boton_encendido() {
    //stdio_init_all();
    gpio_init(LED_PIN_6);
    gpio_set_dir(LED_PIN_6, GPIO_OUT);
    gpio_init(BUTTON_PIN_7);
    gpio_set_dir(BUTTON_PIN_7, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_7);
}

bool verificar_boton_encendido() {
    return gpio_get(BUTTON_PIN_7) == 0;
}

void control_leds_encendido() {
    if (!led_encendido) {
        gpio_put(LED_PIN_6, 1);
        led_encendido = true;
        printf("Lavadora encendida\n");
    } else {
        gpio_put(LED_PIN_6, 0);
        led_encendido = false;
        printf("Lavadora apagada\n");
        // Llama a la función para apagar todos los LEDs
        apagar_todos_los_leds();
    }
    sleep_ms(200);
}

