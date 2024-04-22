#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define POT_PIN 26
#define FIRST_GPIO 2

static int bits[10] = {
    0x01,  // 1
    0x02,  // 2
    0x04,  // 3
    0x08,  // 4
    0x10,  // 5
    0x20,  // 6
};

static int value = 0;

static int32_t mask;

static uint16_t adc_value;

void inicializar_leds_ModosLavado(){
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 6; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
}

void leer_potenciometro(){
    adc_value = adc_read();

    if (adc_value >= 0 && adc_value < 697){
        value = 0;
    } else if (adc_value >= 697 && adc_value < 1377){
        value = 1;
    } else if (adc_value >= 1377 && adc_value < 2057){
        value = 2;
    } else if (adc_value >= 2057 && adc_value < 2737){
        value = 3;
    } else if (adc_value >= 2737 && adc_value < 3417){
        value = 4;
    } else {
        value = 5;
    }
}

void encender_leds_potenciometro(){
    // We are starting with GPIO 2, our bitmap starts at bit 0 so shift to start at 2.
    mask = bits[value] << FIRST_GPIO;

    gpio_set_mask(mask);
}

// sleep_ms(SLEEP);

void apagar_leds_potenciometro(){
    gpio_clr_mask(mask);
}