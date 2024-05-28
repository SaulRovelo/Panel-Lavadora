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