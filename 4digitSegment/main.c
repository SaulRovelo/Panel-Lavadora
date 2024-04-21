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
    for (int gpio = 0; gpio < firstGpio + 10; gpio++){
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
}