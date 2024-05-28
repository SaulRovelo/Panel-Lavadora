from Inicializacion import Inicializacion  
from SensorUltrasonico import SensorUltrasonico  
import utime  

def Sensor():
    """
    Función principal que coordina la ejecución del programa.

    Inicializa las clases necesarias y entra en un bucle para medir la distancia,
    mostrar los mensajes en pantalla y controlar los dispositivos según el nivel de agua.
    """
    iniciar = Inicializacion()  # Inicializacion

    while True:  #Medimos continuamente la distancia.
            distancia = SensorUltrasonico.medir(iniciar.trigger, iniciar.echo)  # Medimos la distancia con el sensor ultrasónico.
            print(f"Distancia: {distancia:.2f} cm")  # Imprimmos la distancia medida.

            if distancia < SensorUltrasonico.nivel_deseado_distancia:  # Comprobamos si se supera el nivel deseado de agua.
                print("Se ha superado el nivel deseado de agua")
                SensorUltrasonico.sonidito(2000, 1, iniciar.buzzer)  # Emitimos el sonido de alerta

            SensorUltrasonico.encender_leds(distancia, iniciar.led_pins)  # Controlamos los LEDs segun el nivel de agua.
            utime.sleep(1)  # 1 segundo

if __name__ == "__main__":
    Sensor()  #ejecucion del programa 
