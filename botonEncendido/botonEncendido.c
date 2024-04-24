#include <stdio.h>
#include "boton_encendido.h"

int main() {
    // Inicialización de las funciones de entrada/salida estándar
    stdio_init_all();

    // Inicialización del botón de encendido 
    inicializar_boton_encendido();

    while (true) {
        // Verificar si se presiona el botón de encendido
        if (verificar_boton_encendido()) {
            // Controlar el estado de los LEDs de encendido
            control_leds_encendido();
        }
    }
    return 0;
}
