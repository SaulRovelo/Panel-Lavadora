#include <stdio.h>
#include "botonAgua.h"

int main() {
    // Inicialización de las funciones de entrada/salida estándar
    stdio_init_all();

    // Inicialización de los LEDs de agua
    inicializar_leds_agua();

    while (true) {
            control_leds_agua();
    }
    return 0;
}
