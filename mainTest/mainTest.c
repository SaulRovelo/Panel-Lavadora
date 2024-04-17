#include <stdio.h>
#include "boton_encendido.h"


int main() {
    inicializar_boton_encendido();

    while (true) {
        if (verificar_boton_encendido()) {
            control_leds_encendido();
            printf("Main\n");
            
        } 
    }
    
    return 0;
}