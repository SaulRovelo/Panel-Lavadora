from machine import Pin, PWM

class Inicializacion:
    """
    Clase encargada de inicializar los pines necesarios para el funcionamiento del programa.
    """

    def __init__(self):
        """
        Inicializa los pines necesarios para el sensor ultrasónico, los LEDs y el zumbador.

        - self.echo: Pin de entrada para recibir la señal del sensor ultrasónico.
        - self.trigger: Pin de salida para enviar la señal al sensor ultrasónico.
        - self.led_pins: Lista de pines de salida para controlar los LEDs.
        - self.buzzer_pin: Pin de salida para controlar el zumbador.
        - self.buzzer: Objeto PWM para generar señales de sonido con el zumbador.
        """
        self.echo = Pin(8, Pin.IN)  # Pin de entrada para sensor ultrasónico.
        self.trigger = Pin(9, Pin.OUT)  # Pin de salida para sensor ultrasónico.
        # Pines de salida para los LEDs.
        self.led_pins = [Pin(i, Pin.OUT) for i in range(10, 14)]
        self.buzzer_pin = Pin(15, Pin.OUT)  # Pin de salida para el zumbador.
        self.buzzer = PWM(self.buzzer_pin)  # Objeto PWM para generar señales de sonido con el zumbador.