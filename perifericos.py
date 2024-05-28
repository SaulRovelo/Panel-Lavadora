from machine import Pin, PWM

class Perifericos:
    def __init__(self):
        # Pines para el control del motor
        self.motor1 = Pin(19, Pin.OUT)
        self.pwm = PWM(Pin(18))

        # Pines para los LEDs
        self.led1 = Pin(13, Pin.OUT)
        self.led2 = Pin(12, Pin.OUT)
        self.led3 = Pin(11, Pin.OUT)

        # Pines para los botones
        self.boton_velocidad = Pin(16, Pin.IN, Pin.PULL_DOWN)
        self.boton_iniciar = Pin(17, Pin.IN, Pin.PULL_DOWN)

        # Inicializar el pin PWM y el motor apagado
        self.motor1.value(0)
        self.pwm.freq(500)
        self.pwm.duty_u16(0)

        # Apagar los LEDs
        self.led1.value(0)
        self.led2.value(0)
        self.led3.value(0)
