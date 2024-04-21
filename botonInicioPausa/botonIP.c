#include "botonIP.h"
// Este array convierte un número del 0 al 9 en un patrón de bits para enviar a los GPIOs
static int bits[10] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67  // 9
};

void initGpioSegmentDisplay(){
    //Inicializamos los GPIO para cada segmento del display
    for (int gpio = S1; gpio < S1 + 7; gpio++){
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
    
}

void initGpioButton(){
    //Inicializamos el GPIO para el bóton
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON,GPIO_IN);
    gpio_pull_up(BUTTON);
}

void displayLoop(){

}


