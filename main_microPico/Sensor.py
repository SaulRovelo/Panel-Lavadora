from Inicializacion_sensor import Inicializacion_sensor  
from SensorUltrasonico import SensorUltrasonico 
from machine import I2C, Pin
from ssd1306 import SSD1306_I2C
import utime  
oled = SSD1306_I2C(128,32, I2C(0, scl=Pin(5), sda=Pin(4)))  # Inicializamos la pantalla OLED
def Sensor():
    """
    Función principal que coordina la ejecución del programa.

    Inicializa las clases necesarias y entra en un bucle para medir la distancia,
    mostrar los mensajes en pantalla y controlar los dispositivos según el nivel de agua.
    """
    iniciar = Inicializacion_sensor()  # Inicialización

    while True:  # Medimos continuamente la distancia.
        
        distancia = SensorUltrasonico.medir(iniciar.trigger, iniciar.echo)  # Medimos la distancia con el sensor ultrasónico.
        # print(f"Distancia: {distancia:.2f} cm")  # Imprimimos la distancia medida.
        oled.fill(0)
        oled.text("Distancia: ", 0, 0)
        oled.text(str(distancia), 0, 20)
        oled.show()
        if distancia < SensorUltrasonico.nivel_deseado_distancia:  # Comprobamos si se supera el nivel deseado de agua.
            # print("Se ha superado el nivel deseado de agua")
            oled.fill(0)
            oled.text("Nivel de agua ", 0, 0)
            oled.text("superado", 0, 20)
            oled.show()
            SensorUltrasonico.sonidito(2000, 3, iniciar.buzzer)  # Emitimos el sonido de alerta
            # utime.sleep(2)  # Espera 2 segundos
            iniciar.led_pins[0].value(0)
            iniciar.led_pins[1].value(0)
            iniciar.led_pins[2].value(0)
            iniciar.led_pins[3].value(0)
            break  # Salir del bucle

        SensorUltrasonico.encender_leds(distancia, iniciar.led_pins)  # Controlamos los LEDs según el nivel de agua.
        utime.sleep_ms(500)  # 1 segundo
