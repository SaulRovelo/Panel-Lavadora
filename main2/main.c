#include <stdio.h>
#include <pico/stdlib.h>
#include "botontareas.h"
#include "botontemperatura.h"

int main(){
    stdio_init_all();
    /* inicializar();

while (true)
{
    if (condicion())
    {
       ciclos();
       sleep_ms(200);
       
    }else{
         boton_presionado = false;
    }
       
}*/
inicio();
    while (true)
    {
        temperatura();
        sleep_ms(200);
    }
    
}