@ Directivas minimas
.text @ Guardar las instrucciones en la seccion de codigo
.align 1 @ Indica que el codigo ocupa direcciones de memoria de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la funcion son de 2 B

.equ LED_PIN, 15
.equ BUTTON_PIN, 14
.equ GPIO_OUT,1
.equ GPIO_IN,0
.equ GPIO_IRQ_EDGE_FALL, 4

main:
    @almacenar variables 

    @ Prologue
    push {r7,lr}
    sub sp, 8
    add r7, sp, 0

    @ bool boton_presionado = false;
    movs r3,0
    str r3,[r7,0]
    @ bool led_encendido = false;
    movs r3,0
    str r3,[r7,4]

    @void button_callback() {
    @boton_presionado = true;

    bl button_callback
    movs r3,1
    str r3,[r7,0]

init:
    @ stdio_init_all();
    bl stdio_init_all

    @ gpio_init(LED_PIN);
    movs r1, LED_PIN
    bl gpio_init

    @ gpio_set_dir(LED_PIN, GPIO_OUT);
    movs r1, GPIO_OUT
    movs r0, LED_PIN
    bl gpio_set_dir_wrapper

    @ gpio_init(BUTTON_PIN);
    movs r1,BUTTON_PIN
    bl gpio_init

    @ gpio_set_dir(BUTTON_PIN, GPIO_IN);
    movs r1, GPIO_IN
    movs r0, BUTTON_PIN
    bl gpio_set_dir_wrapper
    

    @ gpio_pull_up(BUTTON_PIN);
    movs r1, BUTTON_PIN
    bl gpio_pull_up_wrapper

    @  gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, button_callback);
    

while:

if_1:
    ldr r3, [r7,0]
    cmp r3,1
    beq if_2

if_2:
    ldr r3,[r7,4]
    cmp r3,1
    bne else

    @ gpio_put(LED_PIN, 0);
    movs r1, 0
    movs r0, LED_PIN
    bl gpio_put_wrapper

ldr r3,[r7 ,44]
    movs r3,0 @ val = 0;
    str r3,[r7 ,44]

    @ led_encendido = false;
    ldr r3,[r7,4]
    movs r3, 0 @ led_encendido = false;
    str r3,[r7,4]

else:
    @ gpio_put(LED_PIN, 1);
    movs r1,1
    movs r0,LED_PIN
    bl gpio_put_wrapper

    @ led_encendido = true;
    ldr r3,[r7,4]
    movs r3, 1 @ led_encendido = true;
    str r3,[r7,4]

    @ boton_presionado = false;
    ldr r3,[r7,0]
    movs r3,0
    str r3,[r7,0]

    @ sleep_ms(200);
    ldr r0, DELAY
    bl sleep_ms

    b while

.align 4
DELAY: .word 200 @ Definir la constante DELAY con valor 200