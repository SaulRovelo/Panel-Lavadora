import utime

class SensorUltrasonico:
    """
    Clase encargada de la lógica de medición y control del sensor ultrasónico, LEDs y zumbador.
    """

    nivel_deseado = 4  # Nivel maximo 
    nivel_deseado_cm = [11, 8.8, 6.8, 4, 3]  # Distancias de los niveles 
    # Calcula la distancia correspondiente al nivel maximo 
    nivel_deseado_distancia = nivel_deseado_cm[int(nivel_deseado)]

    @staticmethod
    def medir(trigger, echo):
        """
        Realiza una medición de distancia utilizando el sensor ultrasónico.

        Args:
        - trigger: Pin de salida para enviar la señal al sensor ultrasónico.
        - echo: Pin de entrada para recibir la señal del sensor ultrasónico.

        Returns:
        - distancia: Distancia medida en centímetros.
        """
        trigger.low()  # Baja el pin de trigger para un inicio limpio de la señal.
        utime.sleep_us(2)  # 2 microsegundos.
        trigger.high()  # Levanta el pin de trigger para enviar la señal al sensor.
        utime.sleep_us(10)  # 10 microsegundos.
        trigger.low()  # Baja el pin de trigger.

        while echo.value() == 0:  # Esperamos a que el pin de echo se active.
            start = utime.ticks_us()  # Registramos el tiempo de inicio.

        while echo.value() == 1:  # Esperamos a que el pin de echo se desactive.
            end = utime.ticks_us()  # Registramos el tiempo de fin.
        
        tiempo = utime.ticks_diff(end, start)  # Calculamos la duración de la señal.
        distancia = (tiempo * 0.0343) / 2  # Calculamos la distancia en centímetros.
        return distancia

    @staticmethod
    def sonidito(frecuencia, duracion, buzer):
        """
        Produce un sonido con el zumbador pasivo.

        Args:
        - frecuencia: Frecuencia del sonido.
        - duracion: Duración del sonido en segundos.
        - buzer: Objeto PWM para generar el sonido con el zumbador.
        """
        buzer.freq(frecuencia)  # Configuramos la frecuencia del zumbador.
        buzer.duty_u16(32768)  # Configuramos el ciclo de trabajo para generar el sonido.
        utime.sleep(duracion)  # Esperamos la duración especificada.
        buzer.duty_u16(0)  # Detemos el sonido apagando el zumbador.

    @staticmethod
    def encender_leds(distancia, led_pins):
        """
        Enciende los LEDs según el nivel de agua medido.

        Args:
        - distancia: Distancia medida por el sensor ultrasónico.
        - led_pins: Lista de pines de salida para controlar los LEDs.
        """
        for led in led_pins:  # Apagamos todos los LEDs.
            led.low()

        if distancia > 11:  
            print("Nivel de agua: 0")
        elif distancia > 8.8:  
            led_pins[0].value(1)
            print("Nivel de agua: 1")
        elif distancia > 6.8:  
            led_pins[0].value(1)
            led_pins[1].value(1)
            print("Nivel de agua: 2")
        elif distancia > 4:  
            led_pins[0].value(1)
            led_pins[1].value(1)
            led_pins[2].value(1)
            print("Nivel de agua: 3")
        elif distancia > 0:  
            led_pins[0].value(1)
            led_pins[1].value(1)
            led_pins[2].value(1)
            led_pins[3].value(1)
            print("Nivel de agua: 4")
        else:
            for led in led_pins:
                led.low()
