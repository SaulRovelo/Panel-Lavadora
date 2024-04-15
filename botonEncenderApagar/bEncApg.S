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

loop_while:
    @ * while (true) {
    @ * if (!gpio_get(BUTTON_PIN)) {
    movs r0, BUTTON_PIN
    bl gpio_get_wrapper
    cmp r0, 0
    bne if_interno

else:
    @ * boton_presionado = false;
    ldr r0, [r7, 0]
    movs r0, 0
    str r0, [r7, 0]
    b loop_while

if_interno:
    @ * if (!boton_presionado) {
    ldr r0, [r7, 0]
    cmp r0, 0
    bne if_interno_fuera
    @ * gpio_put(LED_PIN, !led_encendido);
    movs r0, LED_PIN
    ldr r1, [r7, 4]
    mvns r1, r1 @ ! Negar el valor de r1
    bl gpio_put_wrapper
    str r1, [r7, 4]

if_interno_fuera:
    @ * boton_presionado = true;
    ldr r0, [r7, 0]
    movs r0, 1
    str r0, [r7, 0]
    b loop_while
    @ * }

@ * Importante
@ ! Alerta
@ ? Duda
@ TODO: Por hacer