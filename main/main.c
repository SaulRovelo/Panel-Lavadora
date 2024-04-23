#include <stdio.h>
#include <pico/stdlib.h>

#include "potenciometroModosLavado.h"

int main(){
    stdio_init_all();
    inicializar_leds_ModosLavado();
    while (true){
        leer_potenciometro();
        encender_leds_potenciometro();
        sleep_ms(50);
        apagar_leds_potenciometro();
    }
    return 0;
}