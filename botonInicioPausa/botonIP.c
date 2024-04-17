#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#define BUTTON 0 
#define DELAY 60000
#define S1 2
bool PRESSED = false;

// This array converts a number 0-9 to a bit pattern to send to the GPIOs
int bits[10] = {
        0x67,  // 9
        0x7f,  // 8
        0x07,  // 7
        0x7d,  // 6
        0x6d,  // 5
        0x66,  // 4
        0x4f,  // 3
        0x5b,  // 2
        0x06,  // 1
        0x3f,  // 0
};

int main() {
    stdio_init_all();
    
    for (int gpio = S1; gpio < S1 + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        
        //SE INVIERTE LA SALIDA
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }


    int val = 9;

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN); 
    gpio_pull_up(BUTTON);

    if (!gpio_get(BUTTON)){
        //Si se presiona el boton por primera vez inicia el contador 
        while (true){
        int32_t mask = bits[val] << S1;
            //VERIFICAR SI SE PRESIONA EL BOTON
            if (!gpio_get(BUTTON)){
                if (!PRESSED){
                    while (!PRESSED){
                        if (!gpio_get(BUTTON)){
                            PRESSED = false;
                        }
                        gpio_set_mask(mask);
                        sleep_ms(100);
                        gpio_clr_mask(mask);
                    }
                }
                PRESSED = true;
            }
            gpio_set_mask(mask);
            sleep_ms(1000);
            gpio_clr_mask(mask);
        }
    }
       
}