from machine import Pin
import utime
from logica import Logica
from perifericos import Perifericos


class Main:
    def __init__(self):
        self.perifericos = Perifericos()
        self.logica = Logica(self.perifericos)

    def ejecutar(self):
        print('Seleccione la velocidad (33, 66, 100)')
        while True:
            self.logica.seleccionar_velocidad()
            estado_iniciar = self.perifericos.boton_iniciar.value()
            # Verificar si se presionó el botón de iniciar
            if estado_iniciar == 1:
                if self.logica.motor_encendido:
                    # Apagar el motor
                    self.logica.detener_motor()
                elif self.logica.nivel_seleccionado:
                    # Encender el motor con la velocidad seleccionada
                    self.logica.iniciar_motor()
                # Esperar un tiempo para evitar múltiples pulsaciones rápidas del botón de iniciar
                utime.sleep_ms(300)

if __name__ == "__main__":
    app = Main()
    app.ejecutar()