#include <stdio.h>
#include "pico/stdlib.h"
#include "variables.h"

// Implementación de la función para apagar todos los LEDs y reiniciar el contador
void apagar_y_reiniciar_leds() {
    // Apaga todas las salidas GPIO
    for (int pin = 0; pin < TOTAL_GPIO_PINS; pin++) {
        gpio_put(pin, 0);
    }
    // Reinicia el contador a su estado inicial
    contador = 0;
    contadorTA = 1;
    contadorT =1;
}

/**
 * @brief Inicializa los pines de los LEDs y el botón de encendido
 * @note Se establece el pin 19 para el led y el pin 20 para el botón
*/
void inicializar_boton_encendido() {
    //stdio_init_all();   // Inicializa las funciones de E/S estándar
    gpio_init(19);   // Inicializa el pin del LED //! Cambiar de 0 a 19
    gpio_set_dir(LED_PIN_0, GPIO_OUT);   // Establece el pin del LED como salida
    gpio_init(20);   // Inicializa el pin del botón //! Cambiar de 1 a 20
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
        //printf("Lavadora encendida\n");   // Imprime un mensaje indicando que la lavadora está encendida
    } else {   // Si el LED está encendido
        gpio_put(LED_PIN_0, 0);   // Apaga el LED
        led_encendido = false;   // Actualiza el estado del LED
        //printf("Lavadora apagada\n");   // Imprime un mensaje indicando que la lavadora está apagada
    }
    //sleep_ms(200);   // Espera 200 ms
}


