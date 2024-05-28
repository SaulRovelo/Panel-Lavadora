import usocket as socket

from utime import sleep_ms
from machine import Pin
import network

led = Pin("LED", Pin.OUT)

ssid = "Yayo"
password = "uwu_211i"

#Interfaz
station = network.WLAN(network.STA_IF)
station.active(True)
station.connect(ssid, password)

#Coneccion a la red
max_attempts = 10
attempt = 0

while not station.isconnected() and attempt < max_attempts:
    attempt += 1
    sleep_ms(500)
    print("Intento de coneccion: ", attempt)
if station.isconnected():
    print("Coneccion exitosa")
    print("Direccion IP: ", station.ifconfig()[0])
    led.on()
else:
    print("Fallo de coneccion")