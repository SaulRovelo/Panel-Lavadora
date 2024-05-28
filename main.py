from Inicializacion import Inicializacion 
from SensorUltrasonico import SensorUltrasonico
import utime

def Sensor(): 
    iniciar = Inicializacion ()
    while True:
        distancia = SensorUltrasonico.medir(iniciar.trigger, iniciar.echo)
        print(f"Distancia: {distancia:.2f} cm")
        if distancia < SensorUltrasonico.nivel_deseado_distancia::

                print("se llego ")
                
           
                SensorUltrasonico.sonidito(2000, 1, iniciar.buzzer)

                SensorUltrasonico.encender_leds(distancia, iniciar.led_pins)
                utime.sleep(1)


if __name__ == "__main__":
    Sensor()