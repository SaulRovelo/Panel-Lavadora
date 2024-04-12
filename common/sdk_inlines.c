#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

void gpio_set_dir_wrapper(unsigned gpio, bool out)
{
    gpio_set_dir(gpio, out);
}

void gpio_pull_up_wrapper(unsigned gpio)
{
    gpio_pull_up(gpio);    
}

void gpio_get_wrapper(unsigned gpio)
{
    gpio_get(gpio);
}

void gpio_set_mask_wrapper(unsigned gpio)
{
    gpio_set_mask(gpio);
}

void gpio_clr_mask_wrapper(unsigned  gpio)
{
    gpio_clr_mask(gpio);
}

void gpio_put_wrapper(unsigned gpio, unsigned n){
    gpio_put(gpio, n);
}