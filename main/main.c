#include "boton_encendido.h"
#include <pico/stdlib.h>
#include "bAgua.h"
#include "variables.h"
#include "botontemperatura.h"
#include "potenciometroModosLavado.h"
#include "botontareas.h"

int main() {
    // Inicialización de las funciones de entrada/salida estándar
    stdio_init_all();

    // Inicialización de pines
    inicializar_boton_encendido();
    inicializar_leds_agua();
    inicializar_leds_ModosLavado();
    inicializar_Leds_temperatura();
    inicializar_leds_tareas();

    while (true) {
        // Verificar si se presiona el botón de encendido
        if (verificar_boton_encendido()) {
            // Controlar el estado de los LEDs de encendido
            control_leds_encendido();
            // Alternar el estado de la lavadora
            lavadora_encendida = !lavadora_encendida;
            // Imprimir el estado actual de la lavadora
            printf("Lavadora %s\n", lavadora_encendida ? "encendida" : "apagada");
            sleep_ms(200); 
            
        } 

        // Si la lavadora está encendida, controlar los LEDs de agua
        if (lavadora_encendida) {
            //if(boton)
            leer_potenciometro();
            encender_leds_potenciometro();
            
            control_leds_agua();
            
            temperatura();
            
            tareas();
            

            sleep_ms(200);
            apagar_leds_potenciometro(); 
            
        } else {
            apagar_y_reiniciar_leds();
        }
    }
    
    return 0;
}