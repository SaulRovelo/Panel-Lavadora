class Inicializacion:
    
    def __init__(self):
        self.echo = Pin(8, Pin.IN)    
        self.trigger = Pin(9, Pin.OUT) 
        self.led_pins = [Pin(i, Pin.OUT) for i in range(10, 14)]
        self.buzzer_pin = Pin(15, Pin.OUT) 