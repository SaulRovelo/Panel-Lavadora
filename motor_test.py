from machine import Pin, PWM
import utime

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

class Logica:
    def __init__(self):
        self.perifericos = Perifericos()
        self.velocidades = [0, 21845, 43690, 65535]
        self.nivel = 0
        self.motor_encendido = False
        self.nivel_seleccionado = False
        print("Lógica inicializada.")

    def seleccionar_velocidad(self):
        estado_velocidad = self.perifericos.boton_velocidad.value()
        if estado_velocidad == 1 and not self.motor_encendido:
            self.nivel = (self.nivel + 1) % len(self.velocidades)
            if self.nivel != 0:
                print(f'Nivel de velocidad seleccionado: {int((self.velocidades[self.nivel] / 65535) * 100)}%')
                self.actualizar_leds()  # Llama al método actualizar_leds usando self
                self.nivel_seleccionado = True
            else:
                print('No se puede seleccionar velocidad 0')
            # Esperar a que se libere el botón antes de continuar
            while self.perifericos.boton_velocidad.value() == 1:
                pass
            utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes

    def actualizar_leds(self):
        # Apagar todos los LEDs
        self.perifericos.led1.value(0)
        self.perifericos.led2.value(0)
        self.perifericos.led3.value(0)
        # Encender el LED correspondiente a la velocidad actual
        if self.nivel == 1:
            self.perifericos.led1.value(1)
        elif self.nivel == 2:
            self.perifericos.led2.value(1)
        elif self.nivel == 3:
            self.perifericos.led3.value(1)

    def iniciar_motor(self):
        if self.nivel_seleccionado:
            self.perifericos.pwm.duty_u16(self.velocidades[self.nivel])
            self.motor_encendido = True
            print(f'Motor encendido al {(self.velocidades[self.nivel] / 65535) * 100}% de potencia')
        else:
            print('Por favor, seleccione un nivel de velocidad antes de iniciar el motor.')

    def detener_motor(self):
        if self.motor_encendido:
            self.perifericos.pwm.duty_u16(0)
            self.perifericos.motor1.value(0)
            self.motor_encendido = False
            self.nivel_seleccionado = False
            self.perifericos.led1.value(0)
            self.perifericos.led2.value(0)
            self.perifericos.led3.value(0)
            print('Motor apagado')

class Main:
    def __init__(self):
        self.perifericos = Perifericos()
        self.logica = Logica()

    def ejecutar(self):
        print('Seleccione la velocidad (33, 66, 100)')
        while True:
            self.logica.seleccionar_velocidad()
            estado_iniciar = self.perifericos.boton_iniciar.value()
            # Verificar si se presionó el botón de iniciar
            if estado_iniciar == 1:
                if self.logica.motor_encendido:
                    # Apagar el motor
                    self.logica.detener_motor()
                elif self.logica.nivel_seleccionado:
                    # Encender el motor con la velocidad seleccionada
                    self.logica.iniciar_motor()
                # Esperar un tiempo para evitar múltiples pulsaciones rápidas del botón de iniciar
                utime.sleep_ms(300)

if __name__ == "__main__":
    app = Main()
    app.ejecutar()