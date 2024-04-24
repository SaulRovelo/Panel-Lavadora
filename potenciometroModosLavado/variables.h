#include <stdio.h>

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