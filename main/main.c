#include <stdio.h>
#include "pico/stdlib.h"    
#include "botonIP.h"


int main(){
    stdio_init_all(); 

    initGpioSegmentDisplay();
    initGpioButton();
    displayLoop();        
}