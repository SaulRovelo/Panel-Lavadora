import utime
from inicializacion_motor import Inicializacion_motor

class Logica_motor:
    """
    Clase que gestiona la lógica para seleccionar la velocidad y controlar el motor.
    """
    perifericos = Inicializacion_motor()
    velocidades = [0, 21845, 43690, 65535]
    nivel = 0
    motor_encendido = False
    nivel_seleccionado = False
    confirmacion_recibida = False
    print("Logica inicializada.")

    @classmethod
    def seleccionar_velocidad_con_boton(cls):
        """
        Permite seleccionar la velocidad del motor usando un botón.

        El método incrementa el nivel de velocidad cada vez que se presiona el botón de velocidad.
        Si se presiona el botón de confirmación, la velocidad seleccionada se confirma.
        """
        while True:
            estado_velocidad = cls.perifericos.boton_velocidad.value()
            if estado_velocidad == 1 and not cls.motor_encendido:
                cls.nivel = (cls.nivel + 1) % len(cls.velocidades)
                if cls.nivel != 0:
                    print(f'Nivel de velocidad seleccionado: {int((cls.velocidades[cls.nivel] / 65535) * 100)}%')
                    cls.actualizar_leds()
                    cls.nivel_seleccionado = True
                    print("Presione el botón de confirmación para confirmar la velocidad seleccionada.")
                else:
                    print('No se puede seleccionar velocidad 0')
                # Esperar a que se libere el botón antes de continuar
                while cls.perifericos.boton_velocidad.value() == 1:
                    pass
                utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes
            
            # Permitir salida del bucle si se presiona el botón de confirmación
            estado_confirmar = cls.perifericos.boton_confirmar.value()
            if estado_confirmar == 1:
                cls.confirmar_velocidad()
                break

    @classmethod
    def confirmar_velocidad(cls):
        """
        Confirma la velocidad seleccionada usando un botón.

        Espera hasta que se presione y libere el botón de confirmación, estableciendo la confirmación de la velocidad.
        """
        while True:
            estado_confirmar = cls.perifericos.boton_confirmar.value()
            if estado_confirmar == 1:
                cls.confirmacion_recibida = True
                print("Velocidad confirmada.")
                # Esperar a que se libere el botón antes de continuar
                while cls.perifericos.boton_confirmar.value() == 1:
                    pass
                utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes
                break

    @classmethod
    def actualizar_leds(cls):
        """
        Actualiza los LEDs según la velocidad seleccionada.

        Enciende el LED correspondiente al nivel de velocidad actual y apaga los demás LEDs.
        """
        # Apagar todos los LEDs
        cls.perifericos.led1.value(0)
        cls.perifericos.led2.value(0)
        cls.perifericos.led3.value(0)
        # Encender el LED correspondiente a la velocidad actual
        if cls.nivel == 1:
            cls.perifericos.led1.value(1)
        elif cls.nivel == 2:
            cls.perifericos.led2.value(1)
        elif cls.nivel == 3:
            cls.perifericos.led3.value(1)

    @classmethod
    def iniciar_motor(cls):
        """
        Inicia el motor si se ha seleccionado y confirmado un nivel de velocidad.

        Configura el duty cycle del PWM según la velocidad seleccionada y enciende el motor.
        """
        if cls.nivel_seleccionado and cls.confirmacion_recibida:
            cls.perifericos.pwm.duty_u16(cls.velocidades[cls.nivel])
            cls.motor_encendido = True
            print(f'Motor encendido al {(cls.velocidades[cls.nivel] / 65535) * 100}% de potencia')
        else:
            print('Por favor, seleccione y confirme un nivel de velocidad antes de iniciar el motor.')

    @classmethod
    def detener_motor(cls):
        """
        Detiene el motor y apaga los LEDs.

        Pone el duty cycle del PWM a 0, apaga el motor y los LEDs, y reinicia los estados de selección y confirmación.
        """
        if cls.motor_encendido:
            cls.perifericos.pwm.duty_u16(0)
            cls.perifericos.motor1.value(0)
            cls.motor_encendido = False
            cls.nivel_seleccionado = False
            cls.confirmacion_recibida = False
            cls.perifericos.led1.value(0)
            cls.perifericos.led2.value(0)
            cls.perifericos.led3.value(0)
            print('Motor apagado')

    # Métodos adicionales comentados, podrían ser utilizados para más funcionalidades
    # @classmethod
    # def prender_motor(cls):
    #     """
    #     Método comentado que simula el encendido del motor en diferentes estados.
    #     """
    #     print("Motor Encendido")
    #     cls.perifericos.motor1.value(0)
    #     cls.perifericos.motor2.value(0)
    #     utime.sleep(1)
    #     cls.perifericos.motor1.value(0)
    #     cls.perifericos.motor2.value(1)
    #     utime.sleep(1)
    #     cls.perifericos.motor1.value(1)
    #     cls.perifericos.motor2.value(0)
    #     utime.sleep(1)
    #     cls.perifericos.motor1.value(1)
    #     cls.perifericos.motor2.value(1)
    #     utime.sleep(1)
        
    # @classmethod
    # def detener_motor2(cls):
    #     """
    #     Método comentado que simula el apagado del motor.
    #     """
    #     print("Motor Apagado")
    #     cls.perifericos.motor1.value(0)
    #     cls.perifericos.motor2.value(0)
