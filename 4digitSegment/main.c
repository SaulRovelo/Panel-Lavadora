#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define firstGpio 6

int nums[12] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 4
    0x66, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67, // 9
    0x76, // H
    0x77 // A
};

int main(){
    stdio_init_all();
    int val = 0;

    for (int gpio = 0; gpio < firstGpio + 10; gpio++){
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    while (true){
        int32_t mask = nums[val] << firstGpio;
        gpio_set_mask(mask);
        sleep_ms(1000);
        gpio_clr_mask(mask);
        val++;    
    }
    
}