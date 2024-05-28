from Inicializacion import Inicializacion 
from SensorUltrasonico import SensorUltrasonico
import utime

def Sensor(): 
    Inicializacion()
    while True:
        distancia=SensorUltrasonico.medir(trigger,echo)
        print(f"Distancia: {distancia:.2f} cm")


if __name__ == "__main__":
    Sensor()
