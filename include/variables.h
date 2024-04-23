#include <stdbool.h>
#ifndef VARIABLES_H
#define VARIABLES_H

#define TOTAL_GPIO_PINS 26

#define LED_PIN_0 0        // Define el pin del LED
#define BUTTON_PIN_1 1     // Define el pin del botón

#define LED_PIN_2 2
#define LED_PIN_3 3
#define LED_PIN_4 4
#define LED_PIN_5 5
#define LED_PIN_6 6
#define BUTTON_PIN_7 7

static bool led_encendido = false;

static int contador = 0; 

bool lavadora_encendida = false;

//Variables boton Temperatura

#define LED_PIN_18 18
#define LED_PIN_19 19
#define LED_PIN_20 20
#define BUTTON_PIN_21 21
static int contadorT = 1;

#endif // VARIABLES_H