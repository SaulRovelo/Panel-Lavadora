from Inicializacion_sensor import Inicializacion_sensor  
from SensorUltrasonico import SensorUltrasonico 
from SensorUltrasonico import SensorUltrasonico
import utime  

def Sensor():
    """
    Función principal que coordina la ejecución del programa.

    Inicializa las clases necesarias y entra en un bucle para medir la distancia,
    mostrar los mensajes en pantalla y controlar los dispositivos según el nivel de agua.
    """
    iniciar = Inicializacion_sensor()  # Inicialización

    while True:  # Medimos continuamente la distancia.
        
        distancia = SensorUltrasonico.medir(iniciar.trigger, iniciar.echo)  # Medimos la distancia con el sensor ultrasónico.
        print(f"Distancia: {distancia:.2f} cm")  # Imprimimos la distancia medida.

        if distancia < SensorUltrasonico.nivel_deseado_distancia:  # Comprobamos si se supera el nivel deseado de agua.
            print("Se ha superado el nivel deseado de agua")
            SensorUltrasonico.sonidito(2000, 3, iniciar.buzzer)  # Emitimos el sonido de alerta
            # utime.sleep(2)  # Espera 2 segundos
            break  # Salir del bucle

        SensorUltrasonico.encender_leds(distancia, iniciar.led_pins)  # Controlamos los LEDs según el nivel de agua.
        utime.sleep_ms(500)  # 1 segundo
