#include <stdio.h>
#include <pico/stdlib.h>

#define LED_PIN_1 0
#define LED_PIN_2 1
#define LED_PIN_3 2
#define LED_PIN_4 3
#define LED_PIN_5 4
#define LED_PIN_6 5


#define LED_PIN_7 6
#define LED_PIN_8 7
#define LED_PIN_9 8

#define BUTTON_PIN 14
#define BUTTON_PIN2 15

void ciclos() {
    // Inicializamos los LEDs
    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);
    gpio_init(LED_PIN_3);
    gpio_set_dir(LED_PIN_3, GPIO_OUT);
    gpio_init(LED_PIN_4);
    gpio_set_dir(LED_PIN_4, GPIO_OUT);
    gpio_init(LED_PIN_5);
    gpio_set_dir(LED_PIN_5, GPIO_OUT);
    gpio_init(LED_PIN_6);
    gpio_set_dir(LED_PIN_6, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Variable para controlar el estado de los LEDs
    int contador = 1;

    while (true) {
        if (gpio_get(BUTTON_PIN) == 0) {
            // Enciende el siguiente LED y apaga el anterior
            if (contador == 1) {
                gpio_put(LED_PIN_1, 1);
                gpio_put(LED_PIN_2, 0);
                gpio_put(LED_PIN_3, 0);
                gpio_put(LED_PIN_4, 0);
                gpio_put(LED_PIN_5, 0);
                gpio_put(LED_PIN_6, 0);
                printf("Normal\n");
                contador = 2;
            } else if (contador == 2) {
                gpio_put(LED_PIN_1, 0);
                gpio_put(LED_PIN_2, 1);
                gpio_put(LED_PIN_3, 0);
                gpio_put(LED_PIN_4, 0);
                gpio_put(LED_PIN_5, 0);
                gpio_put(LED_PIN_6, 0);
                printf("Lavado rapido\n");
                contador = 3;
            } else if (contador == 3) {
                gpio_put(LED_PIN_1, 0);
                gpio_put(LED_PIN_2, 0);
                gpio_put(LED_PIN_3, 1);
                gpio_put(LED_PIN_4, 0);
                gpio_put(LED_PIN_5, 0);
                gpio_put(LED_PIN_6, 0);
                printf("Delicados\n");
                contador = 4;
            } else if (contador == 4) {
                gpio_put(LED_PIN_1, 0);
                gpio_put(LED_PIN_2, 0);
                gpio_put(LED_PIN_3, 0);
                gpio_put(LED_PIN_4, 1);
                gpio_put(LED_PIN_5, 0);
                gpio_put(LED_PIN_6, 0);
                printf("Ropa de cama\n");
                contador = 5;
            } else if (contador == 5) {
                gpio_put(LED_PIN_1, 0);
                gpio_put(LED_PIN_2, 0);
                gpio_put(LED_PIN_3, 0);
                gpio_put(LED_PIN_4, 0);
                gpio_put(LED_PIN_5, 1);
                gpio_put(LED_PIN_6, 0);
                printf("Jeans\n");
                contador = 6;
            } else if (contador == 6) {
                gpio_put(LED_PIN_1, 0);
                gpio_put(LED_PIN_2, 0);
                gpio_put(LED_PIN_3, 0);
                gpio_put(LED_PIN_4, 0);
                gpio_put(LED_PIN_5, 0);
                gpio_put(LED_PIN_6, 1);
                printf("Lavado eco de tambor\n");
                contador = 7;
            } else if (contador == 7) {
                gpio_put(LED_PIN_1, 0);
                gpio_put(LED_PIN_2, 0);
                gpio_put(LED_PIN_3, 0);
                gpio_put(LED_PIN_4, 0);
                gpio_put(LED_PIN_5, 0);
                gpio_put(LED_PIN_6, 0);
                return;
            }
            while (gpio_get(BUTTON_PIN) == 0);
        }
    }
}

void control() {
    // Inicializamos los LEDs
    gpio_init(LED_PIN_7);
    gpio_set_dir(LED_PIN_7, GPIO_OUT);
    gpio_init(LED_PIN_8);
    gpio_set_dir(LED_PIN_8, GPIO_OUT);
    gpio_init(LED_PIN_9);
    gpio_set_dir(LED_PIN_9, GPIO_OUT);

    // Inicializamos el botón
    gpio_init(BUTTON_PIN2);
    gpio_set_dir(BUTTON_PIN2, GPIO_IN);
    gpio_pull_up(BUTTON_PIN2);

    // Variable para controlar el estado de los LEDs
    int contador = 1;

    while (true) {
        if (gpio_get(BUTTON_PIN2) == 0) {
            // Enciende el siguiente LED y apaga el anterior
            if (contador == 1) {
                gpio_put(LED_PIN_7, 1);
                gpio_put(LED_PIN_8, 0);
                gpio_put(LED_PIN_9, 0);
                printf("Temperatura 1\n");
                contador = 2;
            } else if (contador == 2) {
                gpio_put(LED_PIN_7, 0);
                gpio_put(LED_PIN_8, 1);
                gpio_put(LED_PIN_9, 0);
                printf("Temperatura 2\n");
                contador = 3;
            } else if (contador == 3) {
                gpio_put(LED_PIN_7, 0);
                gpio_put(LED_PIN_8, 0);
                gpio_put(LED_PIN_9, 1);
                printf("Temperatura 3\n");
                contador = 4;
            } else if (contador == 4) {
                gpio_put(LED_PIN_7, 0);
                gpio_put(LED_PIN_8, 0);
                gpio_put(LED_PIN_9, 0);
                return;
            }
            while (gpio_get(BUTTON_PIN2) == 0);
        }
    }
}
int main() {
    // Inicialización de la biblioteca stdio
    stdio_init_all();

    // Inicialización de los botones
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    gpio_init(BUTTON_PIN2);
    gpio_set_dir(BUTTON_PIN2, GPIO_IN);
    gpio_pull_up(BUTTON_PIN2);

    // Variables para almacenar el estado anterior de los botones
    bool button_state = true;
    bool button2_state = true;

    while (true) {
        
        // Verificar el estado del primer botón
        bool current_button_state = gpio_get(BUTTON_PIN) == 0;
        if (current_button_state != button_state && current_button_state == false) {
            ciclos();
            printf("Hola\n");
        }
        button_state = current_button_state;

        // Verificar el estado del segundo botón
        bool current_button2_state = gpio_get(BUTTON_PIN2) == 0;
        if (current_button2_state != button2_state && current_button2_state == false) {
            control();
            printf("adios\n");
        }
        button2_state = current_button2_state;
    }

    return 0;
}
