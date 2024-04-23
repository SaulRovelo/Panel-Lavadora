#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "variables.h"

/**
 * @brief Inicializa los pines de los leds y el potenciometro.
*/
void inicializar_leds_ModosLavado(){
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 6; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
}

/**
 * @brief Lee el valor del potenciometro y asigna un valor entre 0 a 5 a una variable.
*/
void leer_potenciometro(){
    adc_value = adc_read();

    if (adc_value < 697){
        value = 0;
    } else if (adc_value < 1377){
        value = 1;
    } else if (adc_value < 2057){
        value = 2;
    } else if (adc_value < 2737){
        value = 3;
    } else if (adc_value < 3417){
        value = 4;
    } else {
        value = 5;
    }
}

/**
 * @brief Enciende los leds segun el valor del potenciometro.
*/
void encender_leds_potenciometro(){
    // Estamos empezando con GPIO 2, por lo que hay que desplazar para empezar en 2.
    mask = bits[value] << FIRST_GPIO;

    gpio_set_mask(mask);
}

// sleep_ms(SLEEP);

/**
 * @brief Apaga los leds.
*/
void apagar_leds_potenciometro(){
    gpio_clr_mask(mask);
}