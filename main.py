from Inicializacion import Inicializacion 
from SensorUltrasonico import SensorUltrasonico
import utime

def Sensor(): 
    iniciar = Inicializacion ()
    while True:
        distancia = SensorUltrasonico.medir(iniciar.trigger, iniciar.echo)
        print(f"Distancia: {distancia:.2f} cm")
        if distancia < SensorUltrasonico.nivel:
                print("se llego ")


