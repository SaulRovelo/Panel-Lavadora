#include<stdio.h>
#include "botonIP.h"
#include "variables.h"

int main(){
    stdio_init_all();
    initGpioSegmentDisplay();
    initGpioButton();
    while (true){    
        displayLoop();
    }
    
}