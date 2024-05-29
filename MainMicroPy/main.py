from machine import UART, Pin, PWM
import time
from shared_obj import *

# Configurar UART0
uart = UART(0, baudrate=115200, tx=Pin(0), rx=Pin(1))

# Configurar el pin para el buzzer
buzzer_pin = Pin(19, Pin.OUT)
buzzer = PWM(buzzer_pin)

# Función para generar un tono
def play_tone(frequency, duration):
    buzzer.freq(frequency)
    buzzer.duty_u16(32768)  # 50% de ciclo de trabajo
    time.sleep(duration)
    buzzer.duty_u16(0)  # Apagar el buzzer

while True:
        tiempo = 0
        if uart.any():
            data = uart.read()
            mensaje = data.decode()
            # print("Mensaje recibido: ", mensaje)
            if mensaje == "verificar_boton_encendido":
                print("Botón encendido")
                shared_obj.lavadora_encencida = True
                pass
            elif mensaje == "control_leds_agua":
                print("Control de LEDs de agua")
                pass
            elif mensaje == "control_leds_tareas":
                print("Control de LEDs de tareas")
                pass
            elif mensaje == "control_leds_temperatura":
                print("Control de LEDs de temperatura")
                pass
            else:
                print("Comando no reconocido")
