@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ LED_PIN, 0
.equ LED_PIN2, 1
.equ LED_PIN3, 2
.equ BUTTON_PIN, 3
.equ GPIO_OUT, 1
.equ GPIO_IN, 0
.equ contador, 1


main:
    @almacenar variables 

    @ Prologue
    push {r7,lr}
    sub sp, 
init:

    @ stdio_init_all();
    bl stdio_init_all

//lED 1
    @ gpio_init(LED_PIN);
    movs r0, LED_PIN
    bl gpio_init

    @ gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r0, LED_PIN
    movs r1, GPIO_OUT
    bl gpio_set_dir_wrapper

//LED 2
    @ gpio_init(LED_PIN);
    movs r0, LED_PIN2
    bl gpio_init

    @ gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r0, LED_PIN2
    movs r1, GPIO_OUT
    bl gpio_set_dir_wrapper

//LED 3
    @ gpio_init(LED_PIN);
    movs r0, LED_PIN3
    bl gpio_init

    @ gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r0, LED_PIN3
    movs r1, GPIO_OUT
    bl gpio_set_dir_wrapper


    @ gpio_init(BUTTON_PIN);
    movs r0,BUTTON_PIN
    bl gpio_init

    @ gpio_set_dir(BUTTON_PIN, GPIO_IN);
    movs r0, BUTTON_PIN
    movs r1, GPIO_IN
    bl gpio_set_dir_wrapper
    
    @ gpio_pull_up(BUTTON_PIN);
    movs r0, BUTTON_PIN
    bl gpio_pull_up_wrapper

while: 
    @ if (gpio_get(BUTTON_PIN) == 0) 
    movs r0, BUTTON_PIN
    bl gpio_get_wrapper
    cmp r0,1
    bne if1

    b Final

//Encender LED 1
if1: 
    movs r0, contador   ; Cargar el valor de 'contador' en el registro R0
    cmp R0, #1         ; Comparar R0 con 1
    beq contador_es_1  ; Saltar a contador_es_1 si son iguales

contador_es_1: 
    
    movs r0, LED_PIN
    movs r1, 1
    bl gpio_put_wrapper

    movs r0, LED_PIN2
    movs r1, 0
    bl gpio_put_wrapper

    movs r0, LED_PIN3
    movs r1, 0
    bl gpio_put_wrapper