#include <stdio.h>
#include <pico/stdlib.h>
#include "botontemperatura.h"

int main(){
    stdio_init_all();
    inicializar_Leds_temperatura();

while (true)
{
     control_leds_temperatura();
       sleep_ms(200);
       
}
 }