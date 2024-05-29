#include "variables.h"
#include "stdbool.h"
#include "pico/stdlib.h"

void inicio_pausa(){
    if (inicio == true) {
        inicio = false;
    } else {
        inicio = true;
    }
}

bool verificar_boton_inicio_pausa() {
    return gpio_get(BUTTON_PIN_28) == 0;   // Retorna verdadero si el botón está presionado (estado bajo)
}