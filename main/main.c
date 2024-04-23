#include <stdio.h>
#include "pico/stdlib.h"
#include "variables.h"


int main(){
    stdio_init_all(); 

    initGpioSegmentDisplay();
    initGpioButton();
    displayLoop();        
}