from machine import UART, Pin, PWM
from zumbador import play_tone
from utime import sleep

# Configurar UART0
uart = UART(0, baudrate=9600, tx=Pin(0), rx=Pin(1))

# Configurar el pin para el buzzer
buzzer_pin = Pin(19, Pin.OUT)
buzzer = PWM(buzzer_pin)

while True:
    if uart.any():
        data = uart.read(1)
        data = data.decode()
        if data == '1':
            print("Encendiendo el buzzer boton 1")
            play_tone(1500, 0.5, buzzer)

        if data == '2':
            print("Encendiendo el buzzer boton 2")
            play_tone(2000, 0.5, buzzer)
        else:
            print("Comando no reconocido")