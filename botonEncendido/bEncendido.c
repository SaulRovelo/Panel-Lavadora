#include "boton_encendido.h"  // Incluye el archivo de encabezado para el botón de encendido
#include <stdio.h>
#include <pico/stdlib.h>
#include "pico/stdlib.h"

#define LED_PIN_0 0        // Define el pin del LED
#define BUTTON_PIN_1 1     // Define el pin del botón

//static bool led_encendido = false;  // Variable para controlar el estado del LED

// Función para inicializar el botón de encendido y el LED
void inicializar_boton_encendido() {
    //stdio_init_all();   // Inicializa las funciones de E/S estándar
    gpio_init(LED_PIN_0);   // Inicializa el pin del LED
    gpio_set_dir(LED_PIN_0, GPIO_OUT);   // Establece el pin del LED como salida
    gpio_init(BUTTON_PIN_1);   // Inicializa el pin del botón
    gpio_set_dir(BUTTON_PIN_1, GPIO_IN);   // Establece el pin del botón como entrada
    gpio_pull_up(BUTTON_PIN_1);   // Habilita la resistencia pull-up en el pin del botón
}

// Función para verificar si se presiona el botón de encendido
bool verificar_boton_encendido() {
    return gpio_get(BUTTON_PIN_1) == 0;   // Retorna verdadero si el botón está presionado (estado bajo)
}

// Función para controlar el LED de encendido
void control_leds_encendido() {
    if (!led_encendido) {   // Si el LED está apagado
        gpio_put(LED_PIN_0, 1);   // Enciende el LED
        led_encendido = true;   // Actualiza el estado del LED
        printf("Lavadora encendida\n");   // Imprime un mensaje indicando que la lavadora está encendida
    } else {   // Si el LED está encendido
        gpio_put(LED_PIN_0, 0);   // Apaga el LED
        led_encendido = false;   // Actualiza el estado del LED
        printf("Lavadora apagada\n");   // Imprime un mensaje indicando que la lavadora está apagada
    }
    //sleep_ms(200);   // Espera 200 ms
}
