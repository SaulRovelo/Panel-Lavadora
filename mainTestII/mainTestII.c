#include "boton_encendido.h"
#include <pico/stdlib.h>

int main()
{
    stdio_init_all();
    inicializar_boton_encendido();
    while (true)
    {
        if (verificar_boton_encendido()){
        control_leds_encendido();
        sleep_ms(200);
        }
    }
    
    return 0;
}
