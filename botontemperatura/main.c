#include "led_control.h"

int main() {
    init_led_control(); // Inicializa los LEDs y el botón

    // Controla los LEDs
    control_leds();

    return 0;
}
