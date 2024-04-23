#ifdef VARIABLES_H
#define VARIABLES_H

// Este array convierte un número del 0 al 9 en un patrón de bits para enviar a los GPIOs
static int bits[10] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67  // 9
};

static int word[4] = {
    0x76, // H
    0x3f, // 0
    0x38, // L
    0x77 // A
};
 
#endif