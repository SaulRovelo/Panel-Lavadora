from machine import Pin, PWM
from utime import sleep_ms


def play_tone( frequency, duration , buzz: PWM):
    buzz.freq(frequency)
    buzz.duty_u16(35000)
    sleep_ms(duration)
    buzz.duty_u16(0)
    

    