"""  
    Este archivo se ejecuta al iniciar el dispositivo y se encarga de conectar el dispositivo a la red wifi y encender el led de la placa    
"""
    

try:
    import usocket as socket
except ImportError:
    import socket
from utime import sleep_ms
from machine import Pin
import network

led = Pin("LED", Pin.OUT)
ssid = "HuaweiDulche"
password = "Dulche:)"

#Interfaz
station = network.WLAN(network.STA_IF)
station.active(True)
station.connect(ssid, password)

#Coneccion a la red
max_attempts = 10
attempt = 0

while not station.isconnected() and attempt < max_attempts:
    attempt += 1
    sleep_ms(1500)
    print("Intento de coneccion: ", attempt)
if station.isconnected():
    print("Coneccion exitosa")
    print("Direccion IP: ", station.ifconfig()[0])
    led.on()
else:
    print("Fallo de coneccion")