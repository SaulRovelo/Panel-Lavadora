# Programa principal
import utime
from logica_motor import Logica_motor

def ejecutar():
    """
    Ejecuta el bucle principal que permite al usuario seleccionar
    la velocidad del motor y controlarlo.
    """
    print('Seleccione la velocidad (33%, 66%, 100%)')

    while True:
        comando = input("Ingrese comando ('pausa' para seleccionar velocidad, 'inicio' para iniciar el motor): ").strip().lower()
        if comando == 'p':
            print("Presione el botón de velocidad para seleccionar el nivel de velocidad.")
            Logica_motor.seleccionar_velocidad_con_boton()
        elif comando == 'i':
            if Logica_motor.nivel_seleccionado and Logica_motor.confirmacion_recibida:
                Logica_motor.iniciar_motor()
                utime.sleep(2)  # Esperar 2 segundos
                Logica_motor.detener_motor()  # Apagar el motor después de 2 segundos
            else:
                print("Seleccione y confirme un nivel de velocidad antes de iniciar el motor.")

if __name__ == "__main__":
    ejecutar()