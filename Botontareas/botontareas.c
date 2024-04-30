#include <stdio.h>
#include <pico/stdlib.h>
#include "botontareas.h"

int main(){
    stdio_init_all();
    inicializar_leds_tareas();

while (true)
{
       control_leds_tareas();
       sleep_ms(200);
       
}
 }