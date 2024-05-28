from machine import Pin
import utime

#Pines
in1= Pin(13, Pin.OUT)
in2= Pin(12, Pin.OUT)

#Ciclo prender y apagar
while True:
    in1.value(0)
    in2.value(0)
    utime.sleep(1)
    
    in1.value(0)
    in2.value(1)
    utime.sleep(1)
    
    in1.value(1)
    in2.value(0)
    utime.sleep(1)
    
    in1.value(1)
    in2.value(1)
    utime.sleep(1)
    
    