#include <pico/stdlib.h>
#include "botonIP.h"


int main(){
    initGpioSegmentDisplay();
    initGpioButton();
    displayLoop();        
}
