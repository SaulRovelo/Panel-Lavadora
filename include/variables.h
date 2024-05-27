#include <stdbool.h>
#include <stdio.h>

#ifndef VARIABLES_H
#define VARIABLES_H

// Variables Boton encendido/apagado
#define TOTAL_GPIO_PINS 26

#define LED_PIN_0 19        // Define el pin del LED
#define BUTTON_PIN_1 20     // Define el pin del botón

static bool led_encendido = false;

// Variables boton de nivel de agua

#define LED_PIN_2 2
#define LED_PIN_3 3
#define LED_PIN_4 4
#define LED_PIN_5 5
#define LED_PIN_6 6
#define BUTTON_PIN_7 7


static int contador = 0; 

bool lavadora_encendida = false;

//Variables boton Temperatura

#define LED_PIN_18 18
#define LED_PIN_21 21
#define LED_PIN_22 22
#define BUTTON_PIN_27 27
static int contadorT = 1;

// Variables Potenciometro (Modos de lavado)

#define POT_PIN 26
#define FIRST_GPIO 8

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


//Variables boton tareas

#define LED_PIN_14 14
#define LED_PIN_15 15
#define LED_PIN_16 16
#define BUTTON_PIN 17
static int contadorTA = 1;


uint32_t sleep_duration_ms = 200;

#define BUTTON_PIN_28 28
static bool inicio = true;

#endif // VARIABLES_H