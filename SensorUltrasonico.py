import utime

class SensorUltrasonico:

    def medir(trigger, echo):
        trigger.low()
        utime.sleep_us(2)
        trigger.high()
        utime.sleep_us(10)
        trigger.low()

        while echo.value() == 0:
            start = utime.ticks_us()
        while echo.value() == 1:
            end = utime.ticks_us()
        
        tiempo = utime.ticks_diff(end, start)
        distancia = (tiempo * 0.0343) / 2
        return distancia

    def sonidito(frecuencia, duracion, buzer):
        buzer.freq(frecuencia)
        buzer.duty_u16(32768)
        utime.sleep(duracion)
        buzer.duty_u16(0)
        
    def encender_leds(distancia, leds):
        for led in leds:
            led.low()
        
        if distancia > 11:
            print("Nivel de agua: 0")
        elif distancia > 8.8:
            leds[0].value(1)
            print("Nivel de agua: 1")
        elif distancia > 6.8:
            leds[0].value(1)
            leds[1].value(1)
            print("Nivel de agua: 2")
        elif distancia > 4:
            leds[0].value(1)
            leds[1].value(1)
            leds[2].value(1)
            print("Nivel de agua: 3")
        elif distancia > 0:
            leds[0].value(1)
            leds[1].value(1)
            leds[2].value(1)
            leds[3].value(1)
            print("Nivel de agua: 4")