#include <stdio.h>
#include "pico/stdlib.h"

#include "variables.h"

int main() {
    stdio_init_all();
    uart_init(uart0, 9600);

    gpio_set_function(0, GPIO_FUNC_UART);  // TX
    gpio_set_function(1, GPIO_FUNC_UART);  // RX

    while (true) {
        char buffer[20];
        sprintf(buffer, "%d", contador);
        uart_puts(uart0, buffer);
        sleep_ms(1000);
    }
}