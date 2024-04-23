#include <stdbool.h>
#include <stdio.h>

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

// Variables Potenciometro

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
#define LED1_PIN 14
#define LED2_PIN 15
#define LED3_PIN 16
#define BUTTON_PIN 17
uint32_t tiempo_anterior = 0;
bool boton_presionado = false;
uint32_t tiempo_presionado = 0;
int pulsaciones = 0;

#endif // VARIABLES_H