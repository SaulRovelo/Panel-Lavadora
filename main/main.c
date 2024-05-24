#include "boton_encendido.h"
#include <pico/stdlib.h>
#include "botonAgua.h"
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
    
    // Configurar UART0
    uart_init(uart0, 115200);
    gpio_set_function(0, GPIO_FUNC_UART); // TX
    gpio_set_function(1, GPIO_FUNC_UART); // RX

    while (true) {
        // Verificar si se presiona el botón de encendido
        if (verificar_boton_encendido()) {
            uart_puts(uart0, "verificar_boton_encendido");
            // Controlar el estado de los LEDs de encendido
            control_leds_encendido();
            // Alternar el estado de la lavadora
            lavadora_encendida = !lavadora_encendida;
            // Imprimir el estado actual de la lavadora
            printf("Lavadora %s\n", lavadora_encendida ? "encendida" : "apagada");
            sleep_ms(sleep_duration_ms); 
        } 

        // Si la lavadora está encendida, Controla las funcionalidades
        if (lavadora_encendida) {
            /*if (boton_inicio())
            {
                //Funcion parpadeo

            }*///else (boton_pausa){
                leer_potenciometro(); // Lee el valor del potenciometro y asigna un valor entre 0 a 5 a una variable.
                encender_leds_potenciometro(); // Enciende los leds segun el valor del potenciometro.
                
                control_leds_agua(); // Enciende los led's de nivel de agua al presionar el boton
                
                control_leds_temperatura(); // Enciende los led's de temperatura al presionar el boton
                
                control_leds_tareas(); // Enciende los led's de Tareas de lavado al presionar el boton
                sleep_ms(sleep_duration_ms);  // Sleep de 125 ms
            
                apagar_leds_potenciometro(); // Apaga los leds del potenciometro 
            //}
        } else {
            apagar_y_reiniciar_leds(); // Implementación de la función para apagar todos los LEDs y reiniciar los leds.
        }
        
    }
    
    return 0;
}