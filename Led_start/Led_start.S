@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ Led_PIN, 
.equ GPIO_OUT, 1
.equ GPIO_IN, 0

maim:
@prologue
    push {r7, lr} @ Guardar los registros r7 y lr en la pila
    sub sp, 56 @ Reservar espacio en la pila para las variables locales
    add r7, sp, 0 @ Asignar la direccion de la pila al registro r7


@ Llamar a la funcion stdio_init_all
bl      stdio_init_all 
    @gpio_init(LED_PIN);
    movs    r0, LED_PIN
    bl      gpio_init 
    @gpio_set_dir(LED_PIN, GPIO_IN);
    movs    r0, LED_PIN
    movs    r1, 0
    bl      gpio_set_dir_wrapper

while:
    @gpio_put(LED_PIN, 1);Enciende el LED
    movs r1, 1
    ldr r0, [r7, 4]
    bl gpio_put_wrapper
    @sleep_ms(1000); Espera
    ldr r0, DELAY
    bl sleep_ms 
    @gpio_put(LED_PIN, 0); Apaga el LED
    movs r1, 0
    ldr r0, [r7, 4]
    bl gpio_put_wrapper
    @sleep_ms(1000); Espera
    ldr r0, DELAY
    bl sleep_ms

    b while


    .align 4
    DELAY: .word 500