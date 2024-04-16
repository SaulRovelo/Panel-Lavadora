@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ LED_PIN, 0
.equ BUTTON_PIN, 1
.equ GPIO_OUT, 1
.equ GPIO_IN, 0


main:
    @almacenar variables 

    @ Prologue
    push {r7,lr}
    sub sp, 4
    add r7, sp, 0
    

init:

    @ stdio_init_all();
    bl stdio_init_all

    @ gpio_init(LED_PIN);
    movs r0, LED_PIN
    bl gpio_init

    @ gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r0, LED_PIN
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

    @ bool led_encendido = false;
    movs r3,0
    str r3,[r7,0]
    
@ while (true)
while:
    @ if (gpio_get(BUTTON_PIN) == 0) 
    movs r0, BUTTON_PIN
    bl gpio_get_wrapper
    cmp r0,1
    bne if_2

    b Final

if_2:
    @ if (!led_encendido) 
    ldr r0,[r7,0]
    cmp r0,0
    bne else

    
    @ gpio_put(LED_PIN, 1); 
    movs r0, LED_PIN
    movs r1, 1
    bl gpio_put_wrapper

    @ led_encendido = true; 
    ldr r3, [r7,0]
    movs r3, 1
    str r3, [r7,0]

    @ printf("Lavadora encendida\n");
    ldr r0, =MSG1
    bl printf

    b Final


else:
    @ gpio_put(LED_PIN, 0);
    movs r0, LED_PIN
    movs r1, 0
    bl gpio_put_wrapper
    @ led_encendido = false;
    ldr r3, [r7,0]
    movs r3, 0
    str r3, [r7,0]

    @ printf("Lavadora apagada\n");
    ldr r0, =MSG2
    bl printf
    b Final

Final:
    @ sleep_ms(200);
    ldr r0, DELAY
    bl sleep_ms

    ldr r0, =MSG3
    bl printf

    b while

.align 4
DELAY: .word 200 @ Definir la constante DELAY con valor 200
MSG1: .ascii "Lavadora Encendida\012\000"
MSG2: .ascii "Lavadora Apagada\012\000"
MSG3: .ascii "Boton\012\000"