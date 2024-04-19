#include <stdio.h>
#include <pico/stdlib.h>

#include "potenciometroModosLavado.h"

int main(){
    stdio_init_all();
    inicializar_leds_ModosLavado();
    while (true){
        leds_potenciometro();
    }
    return 0;
}