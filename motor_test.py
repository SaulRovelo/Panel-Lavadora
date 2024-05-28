from machine import Pin, PWM
import utime

# Pines para el control del motor
motor1 = Pin(19, Pin.OUT)
pwm = PWM(Pin(18))

# Pines para los LEDs
led1 = Pin(13, Pin.OUT)
led2 = Pin(12, Pin.OUT)
led3 = Pin(11, Pin.OUT)

# Pin para el botón
boton = Pin(16, Pin.IN, Pin.PULL_DOWN)

# Inicializar el pin PWM y el motor apagado
motor1.value(0)
pwm.freq(1000)
pwm.duty_u16(0)

# Velocidades definidas
velocidades = [0, 21845, 43690, 65535]  # 0%, 33%, 66%, 100%
indice_velocidad = 0

def cambiar_velocidad(pin):
    global indice_velocidad
    indice_velocidad = (indice_velocidad + 1) % len(velocidades)
    pwm.duty_u16(velocidades[indice_velocidad])
    actualizar_leds()
    print(f'Velocidad cambiada a: {int((velocidades[indice_velocidad] / 65535) * 100)}%')

def actualizar_leds():
    # Apagar todos los LEDs
    led1.value(0)
    led2.value(0)
    led3.value(0)
    # Encender el LED correspondiente a la velocidad actual
    if indice_velocidad == 1:
        print('led 1')
        led1.value(1)
    elif indice_velocidad == 2:
        print('led 2')
        led2.value(1)
    elif indice_velocidad == 3:
        print('led 3')
        led3.value(1)

# Configurar la interrupción del botón
boton.irq(trigger=Pin.IRQ_FALLING, handler=cambiar_velocidad)

print('Presiona el botón para cambiar la velocidad del motor.')

try:
    while True:
        # Mantén el programa corriendo para que pueda responder a la interrupción
        utime.sleep(1)
except KeyboardInterrupt:
    # Limpiar los recursos al salir del programa
    pwm.deinit()
    print('Fin de programa')
