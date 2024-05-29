import utime
from inizializacion_motor import Incializacion_motor
from machine import Pin, PWM, UART, I2C 
from sounds import play_tone
from ssd1306 import SSD1306_I2C

i2c = I2C(1, scl=Pin(3), sda=Pin(2))
oled = SSD1306_I2C(128, 64, i2c)
uart = UART(0, 9600, tx=Pin(0), rx=Pin(1))
buzz = PWM(Pin(15))

class Logica:
    perifericos = Incializacion_motor()
    velocidades = [0, 21845, 43690, 65535]
    nivel = 0
    motor_encendido = False
    nivel_seleccionado = False
    confirmacion_recibida = False

    @classmethod
    def proceso_de_seleccion(cls):
        counter = 10 
        while counter > 0:
            if uart.any():
                data = uart.read().decode().strip()
                print(data)
                if data == "s1":
                    play_tone(1500, 500, buzz)
                elif data == "s2":
                    play_tone(1000, 500, buzz)
                elif data == "s3":
                    play_tone(500, 500, buzz)

            oled.fill(0)
            oled.text('Counter:', 32, 32)  
            oled.text(str(counter), 32, 48)  
            oled.show()
            utime.sleep_ms(1000)  
            counter -= 1

        oled.fill(0)
        oled.text('Counter stopped', 32, 64)
        oled.show()
        oled.fill(0)

        estado_velocidad = cls.perifericos.boton_velocidad.value()
        if estado_velocidad == 1 and not cls.motor_encendido:
            cls.nivel = (cls.nivel + 1) % len(cls.velocidades)
            if cls.nivel != 0:
                print(f'Nivel de velocidad seleccionado: {int((cls.velocidades[cls.nivel] / 65535) * 100)}%')
                cls.actualizar_leds()
                cls.nivel_seleccionado = True
                print("Presione el boton de confirmacion para confirmar la velocidad seleccionada.")
            else:
                print('No se puede seleccionar velocidad 0')
            while cls.perifericos.boton_velocidad.value() == 1:
                pass
            utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes

        estado_confirmar = cls.perifericos.boton_confirmar.value()
        if estado_confirmar == 1:
            cls.confirmar_velocidad()

    @classmethod
    def confirmar_velocidad(cls):
        while True:
            estado_confirmar = cls.perifericos.boton_confirmar.value()
            if estado_confirmar == 1:
                cls.confirmacion_recibida = True
                print("Velocidad confirmada.")
                while cls.perifericos.boton_confirmar.value() == 1:
                    pass
                utime.sleep_ms(300)  # Esperar un tiempo para evitar rebotes
                break

    @classmethod
    def actualizar_leds(cls):
        cls.perifericos.led1.value(0)
        cls.perifericos.led2.value(0)
        cls.perifericos.led3.value(0)
        if cls.nivel == 1:
            cls.perifericos.led1.value(1)
        elif cls.nivel == 2:
            cls.perifericos.led2.value(1)
        elif cls.nivel == 3:
            cls.perifericos.led3.value(1)

    @classmethod
    def iniciar_motor(cls):
        if cls.nivel_seleccionado and cls.confirmacion_recibida:
            cls.perifericos.pwm.duty_u16(cls.velocidades[cls.nivel])
            cls.motor_encendido = True
            print(f'Motor encendido al {(cls.velocidades[cls.nivel] / 65535) * 100}% de potencia')
        else:
            print('Por favor, seleccione y confirme un nivel de velocidad antes de iniciar el motor.')

    @classmethod
    def detener_motor(cls):
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

# Ejemplo de uso
Logica.proceso_de_seleccion()
Logica.iniciar_motor()
# Para detener el motor
# Logica_motor.detener_motor()
