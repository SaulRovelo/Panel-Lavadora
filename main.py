from inizializacion_motor import Incializacion_motor
from logica_motor import Logica_motor
import utime

class Main:
    """
    Clase principal que inicializa y gestiona la lógica del motor.
    """
    def __init__(self):
        """
        Inicializa las instancias de Incializacion_motor y Logica_motor.
        """
        self.inicializacion_motor = Incializacion_motor()
        self.logica = Logica_motor(self.inicializacion_motor)

    def ejecutar(self):
        """
        Ejecuta el bucle principal que permite al usuario seleccionar
        la velocidad del motor y controlarlo.
        """
        print('Seleccione la velocidad (33%, 66%, 100%)')
    
        while True:
            comando = input("Ingrese comando ('pausa' para seleccionar velocidad, 'inicio' para iniciar el motor): ").strip().lower()
            if comando == 'pausa':
                print("Presione el botón de velocidad para seleccionar el nivel de velocidad.")
                self.logica.seleccionar_velocidad_con_boton()
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
