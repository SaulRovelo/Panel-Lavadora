#include<stdio.h>
#include"botonIP.h"

int main(){
    initGpioSegmentDisplay();
    initGpioButton();
    displayLoop();
}