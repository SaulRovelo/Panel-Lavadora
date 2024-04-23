#ifndef BOTONIP_H
#define BOTONIP_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "variables.h"

#define BUTTON 0
#define S1 2

void initGpioSegmentDisplay();
void initGpioButton();
void displayLoop();

#endif