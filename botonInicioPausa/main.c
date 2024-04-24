#include<stdio.h>
#include "botonIP.h"
#include "variables.h"

int main(){
    stdio_init_all();
    inicializarBotonInicioPausa();

    while (true){    
        logicLoop();
        sleep_ms(700);
    }
    
}