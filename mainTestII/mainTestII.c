#include "boton_encendido.h"
#include <pico/stdlib.h>
#include "bAgua.h"
#include "variables.h"

int main() {
    // Inicialización de las funciones de entrada/salida estándar
    stdio_init_all();

    // Inicialización del botón de encendido y de los LEDs de agua
    inicializar_boton_encendido();
    inicializar_leds_agua();

    while (true) {
        // Verificar si se presiona el botón de encendido
        if (verificar_boton_encendido()) {
            // Controlar el estado de los LEDs de encendido
            control_leds_encendido();
            // Alternar el estado de la lavadora
            lavadora_encendida = !lavadora_encendida;
            // Imprimir el estado actual de la lavadora
            printf("Lavadora %s\n", lavadora_encendida ? "encendida" : "apagada");
            sleep_ms(200); 
            
        } 

        // Si la lavadora está encendida, controlar los LEDs de agua
        if (lavadora_encendida) {
            control_leds_agua();
            
        }else{
            apagar_y_reiniciar_leds();
        }
    }
    
    return 0;
}

// int main() {
//     stdio_init_all();
//     inicializar_boton_encendido();
//     inicializar_leds_agua();

//     while (true) {
//         control_leds_agua();

//         if (verificar_boton_encendido()) {
//             control_leds_encendido();
//             sleep_ms(200);
//             control_leds_agua();
//         }
//     }

//     return 0;
// }
