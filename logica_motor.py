import utime

class Logica_motor:
    """
    Clase que gestiona la lógica para seleccionar la velocidad y controlar el motor.
    """

    def __init__(self, perifericos):
        """
        Inicializa la lógica del motor con los periféricos dados.

        Parámetros:
        -----------
        perifericos : object
            Objeto que contiene los periféricos del motor, como pines y LEDs.
        """
        self.perifericos = perifericos
        self.velocidades = [0, 21845, 43690, 65535]
        self.nivel = 0
        self.motor_encendido = False
        self.nivel_seleccionado = False
        self.confirmacion_recibida = False
        print("Logica inicializada.")

    def seleccionar_velocidad_con_boton(self):
        """
        Permite seleccionar la velocidad del motor usando un botón.

        El método incrementa el nivel de velocidad cada vez que se presiona el botón de velocidad.
        Si se presiona el botón de confirmación, la velocidad seleccionada se confirma.
        """
        while True:
            estado_velocidad = self.perifericos.boton_velocidad.value()
            if estado_velocidad == 1 and not self.motor_encendido:
                self.nivel = (self.nivel + 1) % len(self.velocidades)
                if self.nivel != 0:
                    print(f'Nivel de velocidad seleccionado: {int((self.velocidades[self.nivel] / 65535) * 100)}%')
                    self.actualizar_leds()
                    self.nivel_seleccionado = True
                    print("Presione el botón de confirmación para confirmar la velocidad seleccionada.")
                else:
                    print('No se puede seleccionar velocidad 0')
                # Esperar a que se libere el botón antes de continuar
                while self.perifericos.boton_velocidad.value() == 1:
                    pass
                utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes
            
            # Permitir salida del bucle si se presiona el botón de confirmación
            estado_confirmar = self.perifericos.boton_confirmar.value()
            if estado_confirmar == 1:
                self.confirmar_velocidad()
                break

    def confirmar_velocidad(self):
        """
        Confirma la velocidad seleccionada usando un botón.

        Espera hasta que se presione y libere el botón de confirmación, estableciendo la confirmación de la velocidad.
        """
        while True:
            estado_confirmar = self.perifericos.boton_confirmar.value()
            if estado_confirmar == 1:
                self.confirmacion_recibida = True
                print("Velocidad confirmada.")
                # Esperar a que se libere el botón antes de continuar
                while self.perifericos.boton_confirmar.value() == 1:
                    pass
                utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes
                break

    def actualizar_leds(self):
        """
        Actualiza los LEDs según la velocidad seleccionada.

        Enciende el LED correspondiente al nivel de velocidad actual y apaga los demás LEDs.
        """
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
        """
        Inicia el motor si se ha seleccionado y confirmado un nivel de velocidad.

        Configura el duty cycle del PWM según la velocidad seleccionada y enciende el motor.
        """
        if self.nivel_seleccionado and self.confirmacion_recibida:
            self.perifericos.pwm.duty_u16(self.velocidades[self.nivel])
            self.motor_encendido = True
            print(f'Motor encendido al {(self.velocidades[self.nivel] / 65535) * 100}% de potencia')
        else:
            print('Por favor, seleccione y confirme un nivel de velocidad antes de iniciar el motor.')

    def detener_motor(self):
        """
        Detiene el motor y apaga los LEDs.

        Pone el duty cycle del PWM a 0, apaga el motor y los LEDs, y reinicia los estados de selección y confirmación.
        """
        if self.motor_encendido:
            self.perifericos.pwm.duty_u16(0)
            self.perifericos.motor1.value(0)
            self.motor_encendido = False
            self.nivel_seleccionado = False
            self.confirmacion_recibida = False
            self.perifericos.led1.value(0)
            self.perifericos.led2.value(0)
            self.perifericos.led3.value(0)
            print('Motor apagado')

    # Métodos adicionales comentados, podrían ser utilizados para más funcionalidades
    # def prender_motor(self):
    #     """
    #     Método comentado que simula el encendido del motor en diferentes estados.
    #     """
    #     print("Motor Encendido")
    #     self.perifericos.motor1.value(0)
    #     self.perifericos.motor2.value(0)
    #     utime.sleep(1)
    #     self.perifericos.motor1.value(0)
    #     self.perifericos.motor2.value(1)
    #     utime.sleep(1)
    #     self.perifericos.motor1.value(1)
    #     self.perifericos.motor2.value(0)
    #     utime.sleep(1)
    #     self.perifericos.motor1.value(1)
    #     self.perifericos.motor2.value(1)
    #     utime.sleep(1)
        
    # def detener_motor2(self):
    #     """
    #     Método comentado que simula el apagado del motor.
    #     """
    #     print("Motor Apagado")
    #     self.perifericos.motor1.value(0)
    #     self.perifericos.motor2.value(0)
