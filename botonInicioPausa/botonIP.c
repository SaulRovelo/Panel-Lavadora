#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#define BUTTON 0 // Definir el pin del GPIO para el botón
#define S1 2     // Definir el pin de inicio para los segmentos del display de 7 segmentos

// Este array convierte un número del 0 al 9 en un patrón de bits para enviar a los GPIOs
int bits[10] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67  // 9
};

int main() {
    stdio_init_all(); // Inicializar las funciones de entrada/salida estándar del Pico

    // Inicializar los GPIO para los segmentos del display
    for (int gpio = S1; gpio < S1 + 7; gpio++) {
        gpio_init(gpio);  // Inicializar el pin GPIO
        gpio_set_dir(gpio, GPIO_OUT);  // Configurar el pin como salida
        //gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);  // Invertir la salida del GPIO
    }

    // Inicializar el GPIO para el botón
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);  // Configurar el pin como entrada
    gpio_pull_up(BUTTON);  // Activar la resistencia de pull-up interna para el botón

    int val = 9;  // Valor inicial para mostrar en el display
    bool paused = false;  // Indicador de si el display está en pausa
    uint64_t ultimaPulsacion = 0;  // Registrar el último tiempo de pulsación para el debounce
    const uint64_t debounce_time = 300;  // Tiempo de debounce en milisegundos

    while (true) {
        // Comprobar si el botón es presionado con debouncing
        if (!gpio_get(BUTTON) && to_ms_since_boot(get_absolute_time()) - ultimaPulsacion > debounce_time) {
            paused = !paused;  // Alternar el estado de pausa
            ultimaPulsacion = to_ms_since_boot(get_absolute_time());  // Actualizar el último tiempo de pulsación
        }

        // Mostrar el valor actual en el display de 7 segmentos solo si no está en pausa
        if (!paused) {
            if (val > 0){
            int32_t mask = bits[val] << S1;  // Calcular la máscara de bits para los pines del display
            gpio_set_mask(mask);  // Establecer los pines del GPIO según la máscara de bits
            sleep_ms(500);  // Mostrar el número durante 500 milisegundos
            gpio_clr_mask(mask);  // Apagar los pines del GPIO
            sleep_ms(500);  // Apagar durante 500 milisegundos
            val--;
            } else{
                printf("Ropa Limpia :))");
                break;
            }
            
        } else {
            // Cuando está en pausa, mostrar continuamente el valor actual sin cambiar
            int32_t mask = bits[val] << S1;
            gpio_set_mask(mask);  // Mantener los pines del GPIO establecidos continuamente
        }
    }
}
