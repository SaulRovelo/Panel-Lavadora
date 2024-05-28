from perifericos import Perifericos
from logica import Logica
import utime

class Main:
    def _init_(self):
        self.perifericos = Perifericos()
        self.logica = Logica(self.perifericos)

    def ejecutar(self):
        print('Seleccione la velocidad (33%, 66%, 100%)')
        while True:
            comando = input("Ingrese comando ('pausa' para seleccionar velocidad, 'inicio' para iniciar el motor): ").strip().lower()
            if comando == 'pausa':
                print("Presione el botón de velocidad para seleccionar el nivel de velocidad.")
                self.logica.seleccionar_velocidad_con_boton()
                print("Presione el botón de confirmación para confirmar la velocidad seleccionada.")
                self.logica.confirmar_velocidad()
            elif comando == 'inicio':
                if self.logica.nivel_seleccionado and self.logica.confirmacion_recibida:
                    if self.logica.motor_encendido:
                        self.logica.detener_motor()
                    else:
                        self.logica.iniciar_motor()
                else:
                    print("Seleccione y confirme un nivel de velocidad antes de iniciar el motor.")

if __name__ == "__main__":
    app = Main()
    app.ejecutar()
    