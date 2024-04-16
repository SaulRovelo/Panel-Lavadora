@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ LED_PIN_1, 0
.equ LED_PIN_2, 1
.equ LED_PIN_3, 2
.equ LED_PIN_4, 3
.equ LED_PIN_5, 4
.equ BUTTON_PIN, 5
.equ GPIO_OUT, 1
.equ GPIO_IN, 0

main:
    @ Almacer variables

    @ Prologue
    push {r7,lr}
    sub sp,4
    add r7,sp,0

init:
    @ stdio_init_all();
    bl stdio_init_all







