import utime
from machine import PWM, Pin

# Función para generar un tono
def play_tone(frequency: int, duration : float, buzzer : PWM):
    """Genera un tono en el buzzer

    Args:
        frequency (int): Frecuencia en Hrz
        duration (float): Duracion en segundos
        buzzer (PWM): buzzer inicializado con PWM
    """
    buzzer.freq(frequency)
    buzzer.duty_u16(32768)  # 50% de ciclo de trabajo
    utime.sleep(duration)
    buzzer.duty_u16(0)  # Apagar el buzzer

# # Ejemplo de uso
# buzzer_pin = Pin(19, Pin.OUT)
# buzzer = PWM(buzzer_pin)

# while True:
#     play_tone(1500,1,buzzer)
#     utime.sleep(1)