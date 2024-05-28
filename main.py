from logica import Logica_motor
from perifericos import Incializacion_motor
import utime

class Main:
    def __init__(self):
        self.inicializacion_motor = Incializacion_motor()
        self.logica = Logica_motor(self.inicializacion_motor)

    def ejecutar(self):
        print('Seleccione la velocidad (33%, 66%, 100%)')
    
        while True:
            comando = input("Ingrese comando ('pausa' para seleccionar velocidad, 'inicio' para iniciar el motor): ").strip().lower()
            if comando == 'pausa':
                print("Presione el boton de velocidad para seleccionar el nivel de velocidad.")
                self.logica.seleccionar_velocidad_con_boton()
                # print("Presione el botón de confirmación para confirmar la velocidad seleccionada.")
                # self.logica.confirmar_velocidad()
            elif comando == 'inicio':
                if self.logica.nivel_seleccionado and self.logica.confirmacion_recibida:
                    if self.logica.motor_encendido:
                        self.logica.detener_motor()
                    else:
                        self.logica.iniciar_motor()
                        utime.sleep(2)  # Esperar 2 segundos
                        self.logica.detener_motor()  # Apagar el motor después de 2 segundos
                else:
                    print("Seleccione y confirme un nivel de velocidad antes de iniciar el motor.")

if __name__ == "__main__":
    app = Main()
    app.ejecutar()
