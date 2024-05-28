from machine import Pin, PWM
import utime

# Pines para el control del motor
motor1 = Pin(19, Pin.OUT)
pwm = PWM(Pin(18))

# Pines para los LEDs
led1 = Pin(13, Pin.OUT)
led2 = Pin(12, Pin.OUT)
led3 = Pin(11, Pin.OUT)

# Pines para los botones
boton_velocidad = Pin(16, Pin.IN, Pin.PULL_DOWN)
boton_iniciar = Pin(17, Pin.IN, Pin.PULL_DOWN)

# Inicializar el pin PWM y el motor apagado
motor1.value(0)
pwm.freq(500)
pwm.duty_u16(0)

# Apagar los LEDs
led1.value(0)
led2.value(0)
led3.value(0)

# Velocidades definidas
velocidades = [0, 21845, 43690, 65535]  # 0%, 33%, 66%, 100%
nivel_seleccionado = False  # Indica si se ha seleccionado un nivel de velocidad
indice_velocidad = 0

def seleccionar_velocidad(nivel):
    global nivel_seleccionado, indice_velocidad
    if nivel != 0:
        nivel_seleccionado = True
        indice_velocidad = nivel
        print(f'Nivel de velocidad seleccionado: {int((velocidades[indice_velocidad] / 65535) * 100)}%')
        actualizar_leds()
        return nivel
    else:
        nivel_seleccionado = False
        pwm.duty_u16(0)  # Detener el motor
        print('Motor detenido')
        led1.value(0)    # Apagar los LEDs
        led2.value(0)
        led3.value(0)
        return 0


def actualizar_leds():
    # Apagar todos los LEDs
    led1.value(0)
    led2.value(0)
    led3.value(0)
    # Encender el LED correspondiente a la velocidad actual
    if indice_velocidad == 1:
        led1.value(1)
    elif indice_velocidad == 2:
        led2.value(1)
    elif indice_velocidad == 3:
        led3.value(1)

def iniciar_motor(opcion):
    if nivel_seleccionado:
        if opcion == 1:
            #pwm.duty_u16(velocidades[1])  # Establecer la velocidad seleccionada
            print('Motor encendido al 33% de potencia')
        elif opcion == 2:
            #pwm.duty_u16(velocidades[2])  # Establecer la velocidad seleccionada
            print('Motor encendido al 66% de potencia')
        elif opcion == 3:
            #pwm.duty_u16(velocidades[3])  # Establecer la velocidad seleccionada
            print('Motor encendido al 100% de potencia')
        else:
            print('Opción no válida')
    else:
        print('Por favor, seleccione un nivel de velocidad antes de iniciar el motor.')

print('Presiona el botón de velocidad para cambiar el nivel de velocidad del motor.')
print('Presiona el botón de iniciar para encender el motor con el nivel de velocidad seleccionado.')

# Variables para almacenar el estado anterior de los botones
estado_anterior_velocidad = boton_velocidad.value()
estado_anterior_iniciar = boton_iniciar.value()

while True:
    # Verificar el estado del botón de velocidad
    estado_actual_velocidad = boton_velocidad.value()
    
    # Comprobar si ha habido un cambio en el estado del botón de velocidad
    if estado_anterior_velocidad == 1 and estado_actual_velocidad == 0:  # Botón de velocidad presionado
        if not nivel_seleccionado:
            # Cambiar la velocidad solo si no se ha seleccionado un nivel antes
            seleccionar_velocidad((indice_velocidad + 1) % len(velocidades))
            # Esperar un tiempo para evitar cambios de velocidad rápidos debido al rebote del botón
            utime.sleep_ms(300)
    
    # Actualizar el estado anterior del botón de velocidad
    estado_anterior_velocidad = estado_actual_velocidad
    
    # Verificar el estado del botón de iniciar
    estado_actual_iniciar = boton_iniciar.value()
    
    # Comprobar si ha habido un cambio en el estado del botón de iniciar
    if estado_anterior_iniciar == 1 and estado_actual_iniciar == 0:  # Botón de iniciar presionado
        if nivel_seleccionado:
            # Solo iniciar el motor si se ha seleccionado un nivel de velocidad
            iniciar_motor(indice_velocidad)
            # Esperar un tiempo para evitar múltiples pulsaciones rápidas del botón de iniciar
            utime.sleep_ms(300)
    
    # Actualizar el estado anterior del botón de iniciar
    estado_anterior_iniciar = estado_actual_iniciar
