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

main:
    @almacenar variables 

    @ Prologue
    push {r7,lr}
    sub sp, #16
    
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

    movs r4, #1  @ Inicializar contador en 1

while: 
    @ if (gpio_get(BUTTON_PIN) == 0) 
    movs r0, BUTTON_PIN
    bl gpio_get_wrapper
    cmp r0, #0
    bne else

    @ Incrementar contador
    adds r4, r4, #1  @ Incrementar contador
    cmp r4, #4       @ Comprobar si el contador llegó a 4
    bne if1          @ Si no ha llegado a 4, saltar a if1
    movs r4, #1      @ Si llegó a 4, reiniciar el contador a 1
    b while          @ Volver al inicio del bucle

//Encender LED 1
if1: 
    cmp r4, #1        @ Verificar el valor del contador
    beq contador_es_1  @ Si el contador es 1, saltar a contador_es_1

    cmp r4, #2        @ Verificar el valor del contador
    beq contador_es_2  @ Si el contador es 2, saltar a contador_es_2

    cmp r4, #3        @ Verificar el valor del contador
    beq contador_es_3  @ Si el contador es 3, saltar a contador_es_3

    cmp r4, #4
    beq contador_es_4
    b else            @ Si el contador no es 1, 2 o 3, ir a else

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
    @poner contador en 2
    b while

contador_es_2: 
    movs r0, LED_PIN
    movs r1, 0
    bl gpio_put_wrapper

    movs r0, LED_PIN2
    movs r1, 1
    bl gpio_put_wrapper

    movs r0, LED_PIN3
    movs r1, 0
    bl gpio_put_wrapper
    @poner contador en 3
    b while

contador_es_3: 
    movs r0, LED_PIN
    movs r1, 0
    bl gpio_put_wrapper

    movs r0, LED_PIN2
    movs r1, 0
    bl gpio_put_wrapper

    movs r0, LED_PIN3
    movs r1, 1
    bl gpio_put_wrapper
    @poner contador en 4
    b while

contador_es_4: 
    movs r0, LED_PIN
    movs r1, 0
    bl gpio_put_wrapper

    movs r0, LED_PIN2
    movs r1, 0
    bl gpio_put_wrapper

    movs r0, LED_PIN3
    movs r1, 0
    bl gpio_put_wrapper
    @poner contador en 1
    b while

else:
    b while
