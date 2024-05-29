#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_BUTTON 2
#define BOTON2 3

int main(){
    stdio_init_all();
    uart_init(uart0, 9600);

    gpio_set_function(0, GPIO_FUNC_UART);  // TX
    gpio_set_function(1, GPIO_FUNC_UART);  // RX

    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_pull_up(PIN_BUTTON);

    gpio_init(BOTON2);
    gpio_set_dir(BOTON2, GPIO_IN);
    gpio_pull_up(BOTON2);

    while (1) {
        if (gpio_get(PIN_BUTTON) == 0) {
            uart_puts(uart0, "1");
            printf("1\n");
        }
        if (gpio_get(BOTON2) == 0) {
            uart_puts(uart0, "2");
            printf("2\n");
        }
        sleep_ms(200);
    }
}