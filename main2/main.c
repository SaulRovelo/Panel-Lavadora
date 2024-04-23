#include <stdio.h>
#include <pico/stdlib.h>
#include "botontareas.h"

int main(){
    stdio_init_all();
     inicializar();

while (true)
{
    if (condicion())
    {
       ciclos();
       sleep_ms(200);
       
    }else{
         boton_presionado = false;
    }
       
}

}