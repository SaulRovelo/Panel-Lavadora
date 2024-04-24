#include<stdio.h>
#include "botonIP.h"
#include "variables.h"

int main(){
    initGpioSegmentDisplay();
    initGpioButton();
    displayLoop();
}