from machine import Pin, PWM
import time

# Pines para el control del motor
motor1 = Pin(19, Pin.OUT)
pwm = PWM(Pin(18))

# Inicializar el pin PWM y el motor apagado
motor1.value(0)
pwm.freq(1000)
pwm.duty_u16(0)

continuar = True

while continuar:
    try:
        vel = input('Digite velocidad de 0 a 100 (o "z" para salir): ')
        if vel.lower() == 'z':
            continuar = False
            pwm.deinit()
        else:
            velocidad = int(vel)
            if 0 <= velocidad <= 100:
                # Convertir la velocidad de 0-100 a 0-65535
                duty = int(velocidad * 655.35)
                pwm.duty_u16(duty)
            else:
                print('Por favor, digite un valor entre 0 y 100.')
    except ValueError:
        print('Entrada no válida, por favor digite un número o "z" para salir.')

print('Fin de programa')
