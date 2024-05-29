from machine import Pin, PWM

class Incializacion_motor:
    """
    Clase para inicializar los pines y periféricos del motor.
    """
    def __init__(self):
        """
        Inicializa los pines del motor, LEDs y botones.
        """    
        # Pines para el control del motor
        self.motor1 = Pin(21, Pin.OUT)
        self.pwm = PWM(Pin(22))
        #self.motor2 = Pin(22, Pin.OUT)

        # Pines para los LEDs
        self.led1 = Pin(18, Pin.OUT)
        self.led2 = Pin(19, Pin.OUT)
        self.led3 = Pin(20, Pin.OUT)

        # Pines para los botones
        self.boton_velocidad = Pin(16, Pin.IN, Pin.PULL_DOWN)
        self.boton_confirmar = Pin(17, Pin.IN, Pin.PULL_DOWN)  # Nuevo botón de confirmación

        # Inicializar el pin PWM y el motor apagado
        self.motor1.value(0)
        #self.motor2.value(0)
        self.pwm.freq(500)
        self.pwm.duty_u16(0)

        # Apagar los LEDs
        self.led1.value(0)
        self.led2.value(0)
        self.led3.value(0)
