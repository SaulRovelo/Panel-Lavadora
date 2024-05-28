import utime

class Logica:
    def __init__(self, perifericos):
        self.perifericos = perifericos
        self.velocidades = [0, 21845, 43690, 65535]
        self.nivel = 0
        self.motor_encendido = False
        self.nivel_seleccionado = False
        self.confirmacion_recibida = False
        print("Lógica inicializada.")

    def seleccionar_velocidad_con_boton(self):
        while True:
            estado_velocidad = self.perifericos.boton_velocidad.value()
            if estado_velocidad == 1 and not self.motor_encendido:
                self.nivel = (self.nivel + 1) % len(self.velocidades)
                if self.nivel != 0:
                    print(f'Nivel de velocidad seleccionado: {int((self.velocidades[self.nivel] / 65535) * 100)}%')
                    self.actualizar_leds()
                    self.nivel_seleccionado = True
                else:
                    print('No se puede seleccionar velocidad 0')
                # Esperar a que se libere el botón antes de continuar
                while self.perifericos.boton_velocidad.value() == 1:
                    pass
                utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes
                break

    def confirmar_velocidad(self):
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
        if self.nivel_seleccionado and self.confirmacion_recibida:
            self.perifericos.pwm.duty_u16(self.velocidades[self.nivel])
            self.motor_encendido = True
            print(f'Motor encendido al {(self.velocidades[self.nivel] / 65535) * 100}% de potencia')
        else:
            print('Por favor, seleccione y confirme un nivel de velocidad antes de iniciar el motor.')

    def detener_motor(self):
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