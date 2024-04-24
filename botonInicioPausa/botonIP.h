#include"pico/stdio.h"
#include "variables.h"
#include "pico/time.h"
#include <hardware/gpio.h>

#ifndef BOTONIP_H
#define BOTONIP_H
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

void inicializarBotonInicioPausa(){
    //Inicializamos los GPIO para cada segmento del display
    for (int gpio = S1; gpio < S1 + 7; gpio++){
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        //gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    //Inicializamos el GPIO para el bóton
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON,GPIO_IN);
    gpio_pull_up(BUTTON);
    
}

void logicLoop(){
    if (!gpio_get(BUTTON) && to_ms_since_boot(get_absolute_time()) - ultimaPulsacion > debounce_time){
            paused = !paused;
            ultimaPulsacion = to_ms_since_boot(get_absolute_time());
        }     
        if (!paused) {
            if (val >= 0) {
                int32_t mask = bits[val] << S1;
                gpio_set_mask(mask);
                sleep_ms(1500);
                gpio_clr_mask(mask);
                val--;
            } else {
                printf("Ropa Limpia :))\n");
            }
        } else {
            int32_t mask = bits[val] << S1;
            gpio_set_mask(mask);
            sleep_ms(500);
            gpio_clr_mask(mask);
            sleep_ms(500);
        }
}

#endif