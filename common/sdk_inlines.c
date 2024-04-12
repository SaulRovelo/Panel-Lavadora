#include <stdbool.h>
#include <stdio.h>

//#include "hardware/gpio.h"

void gpio_set_dir_wrapper (unsigned gpio, bool out) {
    gpio_set_dir(gpio, out);
}

void gpio_pull_up_wrapper (unsigned gpio) { 
    gpio_pull_up(gpio);
}

void gpio_put_wrapper (unsigned gpio, bool value){
    gpio_put(gpio,value);
}
