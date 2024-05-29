from machine import Pin, UART, PWM, I2C
from utime import sleep_ms
import socket
from sounds import play_tone
from Sensor import Sensor
from logica import Logica 
from ssd1306 import SSD1306_I2C


#Inicializamos el puerto UART
uart  = UART(0, 9600, tx=Pin(0), rx=Pin(1))
buzz = PWM(Pin(15))
on_state = False
motor = Logica()
i2c = I2C(0, scl=Pin(5), sda=Pin(4))
oled = SSD1306_I2C(128, 32, i2c)
contador = 3


def web_page():
    html = """<html>
    <head>
    <title>Boton de inicio y pausa</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <style>
        html {
            font-family: Fira Code;
            display: inline-block;
            margin: 0px auto;
            text-align: center;
        }
        h2 {
            color: #0a0a0a;
        }
        p {
            font-size: 1.5rem;
        }
        .button {
            display: inline-block;
            background-color: #e7bd3b;
            border: none;
            border-radius: 4px;
            color: white;
            padding: 16px 40px;
            text-decoration: none;
            font-size: 30px;
            margin: 2px;
            cursor: pointer;
        }
        .button1 {
            background-color: #e7bd3b;
        }
        .button2 {
            background-color: #4286f4;
        }
    </style>
    </head>
    <body>
    <h1>Boton de inicio y pausa</h1>
    <p>Presiona el boton para iniciar o pausar la lavadora</p>
    <button><a href="/?start" class="button button1">Inicio</a></button>
    <button><a href="/?pause" class="button button2">Pausa</a></button>
    </form>
    </body>
    </html>"""
    return html

def init_server():
    global on_state, contador
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', 80))
    s.listen(5)
    try:
        while True: 
            conn, addr = s.accept()
            print("Conexion desde %s" % str(addr))
            request = conn.recv(1024).decode('utf-8')
            try:
                response = web_page()
                conn.sendall(response.encode('utf-8'))
                if '/?start' in request and on_state: 
                    on_state = False
                    uart.write('1')
                    play_tone(1000, 500, buzz)
                    Sensor()
                    while contador > 0:
                        contador -= 1
                        oled.fill(0)
                        oled.text("Lavandoooo :) ", 0, 0)
                        oled.show()
                    motor.iniciar_motor()
                    sleep_ms(3000)
                    motor.detener_motor()
                    print("Inicio")
                elif '/?pause' in request and not on_state:
                    oled.fill(0)
                    oled.text("Pausa ", 0, 0)
                    oled.show()
                    on_state = True
                    uart.write('0')
                    play_tone(1500, 500, buzz) 
                    motor.seleccionar_velocidad_con_boton()
                    print("Pausa")
            except Exception as e:
                print("Error: ", e)
            finally:
                conn.close()
    except KeyboardInterrupt:
        print("Servidor detenido")
    finally:
        s.close() 
        
if __name__ == '__main__':
    init_server()