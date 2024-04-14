@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ LED_PIN, 15
.equ BUTTON_PIN, 14
.equ GPIO_OUT, 1
.equ GPIO_IN, 0
.equ GPIO_IRQ_EDGE_FALL, 4
.equ true, 1

main:
    @ Prologue
    push {r7, lr} @ Guardar los registros r7 y lr en la pila
    sub sp, 8 @ Reservar espacio en la pila para dos variables locales
    mov r7, sp @ Guardar la direccion de la pila en r7
    
    @ * bool boton_presionado = false;
    movs r3, 0
    str r3, [r7, 0]

    @ * bool led_encendido = false;
    movs r3, 0
    str r3, [r7, 4]

    @ * stdio_init_all();
    bl stdio_init_all

    @ * gpio_init(LED_PIN);
    movs r0, LED_PIN
    bl gpio_init

    @ * gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r0, LED_PIN
    movs r1, GPIO_OUT
    bl gpio_set_dir_wrapper

    @ * gpio_init(BUTTON_PIN);
    movs r0, BUTTON_PIN
    bl gpio_init

    @ * gpio_set_dir(BUTTON_PIN, GPIO_IN);
    movs r0, BUTTON_PIN
    movs r1, GPIO_IN
    bl gpio_set_dir_wrapper

    @ * gpio_pull_up(BUTTON_PIN);
    movs r0, BUTTON_PIN
    bl gpio_pull_up_wrapper

    @ * gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    movs r0, BUTTON_PIN
    movs r1, GPIO_IRQ_EDGE_FALL
    movs r2, true
    ldr r3, =button_callback
    bl gpio_set_irq_enabled_with_callback

loop_while:
    @ * while (true) {
    ldr r3, [r7, 0]
    cmp r3, 0
    bne if_led_on

if_led_on:
    ldr r3, [r7, 4]
    cmp r3, 0
    beq if_led_off
    @ gpio_put(LED_PIN, 0);
    @ led_encendido = false;
    movs r0, LED_PIN
    movs r1, 0
    bl gpio_put_wrapper
    ldr r3, [r7, 4]
    movs r3, 0
    str r3, [r7, 4]
    b final_if
    
if_led_off:
    @ gpio_put(LED_PIN, 1);
    @ led_encendido = true;
    movs r0, LED_PIN
    movs r1, 1
    bl gpio_put_wrapper
    ldr r3, [r7, 4]
    movs r3, 1
    str r3, [r7, 4]

final_if:
    ldr r3, [r7, 0]
    movs r3, 0
    str r3, [r7, 0]

    ldr r0, DELAY
    bl sleep_ms
    b loop_while
    @ * }

button_callback:
    ldr r3, [r7, 0]
    movs r3, 1
    str r3, [r7, 0]
    bx lr

.align 4
DELAY: .word 200 @ Definir la constante DELAY con valor 1000

@ * Importante
@ ! Alerta
@ ? Duda
@ TODO: Por hacer