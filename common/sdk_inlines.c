#include <stdbool.h>
#include <stdio.h>
#include "pico/stdlib.h"
//#include "hardware/gpio.h"
void gpio_set_dir_wrapper(unsigned gpio, bool out)
{
    gpio_set_dir(gpio, out);
}

void gpio_pull_up_wrapper(unsigned gpio)
{
    gpio_pull_up (gpio);

}

bool gpio_get_wrapper(unsigned gpio){
return gpio_get (gpio);
}


void gpio_set_mask_wrapper(long mask){
gpio_set_mask(mask);
}

void gpio_clr_mask_wrapper(long mask){
gpio_clr_mask(mask);
}

void gpio_put_wrapper(unsigned gpio, bool value)
{
    gpio_put(gpio,value);
}