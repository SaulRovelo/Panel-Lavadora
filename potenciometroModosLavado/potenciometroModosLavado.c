#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define POT_PIN 26
#define FIRST_GPIO 2
#define SLEEP 50

int main() {

    int bits[10] = {
        0x01,  // 1
        0x02,  // 2
        0x04,  // 3
        0x08,  // 4
        0x10,  // 5
        0x20,  // 6
    };

    stdio_init_all();
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    // We could use gpio_set_dir_out_masked() here
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 6; gpio++) {
        printf("GPIO: %d\n", gpio);
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        // Our bitmap above has a bit set where we need an LED on, BUT, we are pulling low to light
        // so invert our output
        // gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT); //Así es para anodo común
        // sleep_ms(SLEEP);
    }

    int value = 0;

    while (true) {
        // Leer el valor del ADC en el pin GPIO configurado (pin 26)
        uint16_t adc_value = adc_read();
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

        // We are starting with GPIO 2, our bitmap starts at bit 0 so shift to start at 2.
        int32_t mask = bits[value] << FIRST_GPIO;

        // Set all our GPIOs in one go!
        // If something else is using GPIO, we might want to use gpio_put_masked()
        gpio_set_mask(mask);
        sleep_ms(SLEEP);
        gpio_clr_mask(mask);

        /*
        printf("ADC Value: %d\n", adc_value);
        // Convertir la lectura del ADC a voltaje (asumiendo una referencia de 3.3V)
        float voltage = adc_value * (3.3 / 65535.0);
        // Imprimir el valor del voltaje en el terminal
        printf("Voltage: %fV\n", voltage);
        sleep_ms(1000);
        */
    }
    return 0;
}