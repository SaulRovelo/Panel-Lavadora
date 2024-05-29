from machine import Pin, PWM
from utime import sleep_ms


def play_tone( frequency, duration , buzz: PWM):
    """Play a tone with the given frequency and duration.

    Args:
        frequency (int): Frequency of the tone
        duration (int): Duration of the tone
        buzz (PWM): Object of the class PWM 
    """
    buzz.freq(frequency)
    buzz.duty_u16(35000)
    sleep_ms(duration)
    buzz.duty_u16(0)
    

    