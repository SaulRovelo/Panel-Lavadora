#include<stdio.h>
#include "botonIP.h"
#include "variables.h"

int main(){
    stdio_init_all();
    initGpioSegmentDisplay();
    initGpioButton();

    while (true){ 
        if (!exit){
        paused = deteccionDePulsacion();    
        exit = logicLoop(paused);
        sleep_ms(700);
        }
    }
    
}