#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define POT_PIN 26

int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    while (true) {
        // Leer el valor del ADC en el pin GPIO configurado (pin 26)
        uint16_t adc_value = adc_read();
        // Convertir la lectura del ADC a voltaje (asumiendo una referencia de 3.3V)
        float voltage = adc_value * (3.3 / 65535.0);
        // Imprimir el valor del voltaje en el terminal
        printf("Voltage: %.2fV\n", voltage);
        sleep_ms(1000);
    }
    return 0;
}