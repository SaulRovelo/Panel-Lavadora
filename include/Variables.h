#include <stdio.h>

#define LED1_PIN 14
#define LED2_PIN 15
#define LED3_PIN 16
#define BUTTON_PIN 17
uint32_t tiempo_anterior = 0;
bool boton_presionado = false;
uint32_t tiempo_presionado = 0;
int pulsaciones = 0;
/*
#define LED_PIN_1 18
#define LED_PIN_2 19
#define LED_PIN_3 20
#define BUTTON_PIN 21
int contador = 1;
*/