@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ LED_PIN, 15
@.equ GPIO_OUT, 1

main: 
    @prologue
    push {r7, lr} @ Guardar los registros r7 y lr en la pila
    sub sp, 4 @ Reservar espacio en la pila para las variables locales
    add r7, sp, 0 @ Asignar la direccion de la pila al registro r7

    @stdio_init_all
    bl stdio_init_all

    @gpio_init(LED_PIN)
    ldr r0 [r7, 4]
    bl gpio_init

    @gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r1, 1
    ldr  r0, [r7, 4]
    bl gpio_set_dir_wrapper


    @While(true)
while:
    @gpio_put(LED_PIN, 1); // Enciende el LED
    movs r1, 1
    ldr r0, [r7, 4]
    bl gpio_put_wrapper

    @sleep_ms(1000); // Espera 1 segundo
    ldr r0, DELAY
    bl sleep_ms 

    @gpio_put(LED_PIN, 0); // Apaga el LED
    movs r1, 0
    ldr r0, [r7, 4]
    bl gpio_put_wrapper

    @sleep_ms(1000); // Espera 1 segundo
    ldr r0, DELAY
    bl sleep_ms

    b while

    @return 0
    movs lr, 0

.align 4
DELAY: .word 1000