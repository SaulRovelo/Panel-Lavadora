from machine import Pin, UART
from utime import sleep_ms
import socket

#Inicializamos el puerto UART

uart  = UART(0, 9600, tx=Pin(0), rx=Pin(1))

on_state = False

def web_page():
    html = """<html>
    <head>
    <title>Boton de inicio y pausa</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
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
    global on_state
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', 80))
    s.listen(5)
    try:
        while True: 
            conn, addr = s.accept()
            print("Conexion desde %s" % str(addr))
            request = conn.recv(1024).decode('utf-8')
            try:
                if '/?start' in request and on_state:
                    on_state = True
                    uart.write('1')
                    sleep_ms(100)
                    print("Inicio")
                elif '/?pause' in request and not on_state:
                    on_state = False
                    uart.write('0')
                    sleep_ms(100)
                    print("Pausa")
                response = web_page()
                conn.sendall(response).encode('utf-8')
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
