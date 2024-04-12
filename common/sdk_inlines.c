#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

void gpio_set_dir_wrapper(unsigned gpio, bool out){
    gpio_set_dir(gpio, out);
}

void gpio_pull_up_wrapper(unsigned gpio){
    gpio_pull_up(gpio);
}

void gpio_put_wrapper(unsigned gpio, bool value){
    gpio_put(gpio, value);
}

void gpio_set_irq_enabled_with_callback_wrapper(unsigned gpio, unsigned irq, bool enabled, gpio_irq_callback_t callback){
    gpio_set_irq_enabled_with_callback(gpio, irq, enabled, callback);
}

