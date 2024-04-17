#include <stdio.h>
#include "boton_encendido.h"
#include "bAgua.h"


int main() {
    stdio_init_all();
    inicializar_boton_encendido();
    inicializar_leds_agua();
    


    while (true) {
        
        if (verificar_boton_encendido()) {
            control_leds_encendido();
            control_leds_agua();
            sleep_ms(200); 
            printf("Test\n");
            
        } 
    }
    
    return 0;
}