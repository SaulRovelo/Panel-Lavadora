@ Directivas de ensamblador
.text                   @ La sección .text indica donde se almacena el código.
.align 1                @ Alinea el código a direcciones de memoria que sean múltiplos de 2^1 (2 bytes).
.global main            @ Hace que la función main sea accesible desde otros archivos o módulos.
.syntax unified         @ Establece el uso de la sintaxis unificada de ARM.
.thumb_func             @ Indica que main será compilada en el modo Thumb, usando instrucciones de 16 bits.

.equ LED_PIN, 15        @ Define LED_PIN como una constante con valor 15.

main:                   @ Etiqueta de inicio de la función principal.
    @ Prologue - Preparación de la función
    push {r7, lr}       @ Guarda los registros r7 (frame pointer) y lr (link register) en la pila.
    sub sp, 4           @ Reserva espacio en la pila para variables locales.
    add r7, sp, 0       @ Establece r7 como el nuevo frame pointer.

    @ Inicialización de sistemas estándar de E/S
    bl stdio_init_all   @ Llama a stdio_init_all para inicializar todas las funciones de E/S estándar.

    @ Configuración del GPIO para el LED
    movs r0, LED_PIN     @ Carga en r0 el valor de LED_PIN.
    bl gpio_init        @ Llama a gpio_init para inicializar el pin LED_PIN.

    @ Establece la dirección del GPIO a salida
    movs r1, 1          @ Mueve el valor 1 a r1, indicando 'salida'.
    movs r0, LED_PIN     @ Recarga el valor de LED_PIN en r0.
    bl gpio_set_dir_wrapper @ Llama a gpio_set_dir_wrapper con r0 como pin y r1 como dirección.

    @ Bucle infinito
while:
    @ Enciende el LED
    movs r1, 1          @ Mueve el valor 1 a r1 (encendido).
    movs r0, LED_PIN     @ Carga en r0 el valor de LED_PIN.
    bl gpio_put_wrapper @ Llama a gpio_put_wrapper para actualizar el estado del GPIO.

    @ Retardo
    ldr r0, DELAY       @ Carga en r0 el valor de DELAY.
    bl sleep_ms         @ Llama a sleep_ms con el retardo especificado.

    @ Apaga el LED
    movs r1, 0          @ Mueve el valor 0 a r1 (apagado).
    movs r0, LED_PIN     @ Carga en r0 el valor de LED_PIN.
    bl gpio_put_wrapper @ Llama a gpio_put_wrapper para actualizar el estado del GPIO.

    @ Retardo
    ldr r0, DELAY       @ Recarga en r0 el valor de DELAY.
    bl sleep_ms         @ Llama a sleep_ms con el retardo especificado.

    @ Vuelve al inicio del bucle
    b while             @ Salta incondicionalmente a la etiqueta 'while'.


.align 4
DELAY: .word 1000       @ Define DELAY como una palabra (32 bits) con valor 1000 (milisegundos).
