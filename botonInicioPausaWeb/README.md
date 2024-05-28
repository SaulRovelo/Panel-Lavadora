# Boton Inicio/Pausa WEB
## Raspberry Pi Pico W

## Impementación
El código está dividido en tres partes principales:

    -Configuración de la UART para la comunicación serial.
    -Configuración de un servidor web para recibir señales desde una página web.
    -Manejador de interrupciones y señales desde la web.

## Esquema fisico

<img src="diagrama.png">

## Funcionamiento

Se desarrollo una aplicacion web capaz de enviar señales a la raspberry pi pico w para controlar los estados de inicio/pausa y despues enviar la señar recibida al puerto UART,  para despues enviarla a otra raspberry y esta haga las acciones programadas anteriormente.

## Diagrama de Flujo
<img src="diagrama_Flujo.png"> 



## Instalación y Uso

1. Clona este repositorio en tu dispositivo.
2. Conecta los componentes a las Raspberrys Pi Pico W y a la protoboard según el esquema de conexión proporcionado.
4. Conecta los puertos RX y TX de ambas raspberry ( RX-TX y TX-RX ) y alguna tierra entre ambas.
4. Compila y carga el código de coneccion web (boot.py )en la Raspberry Pi Pico W el cual te genera la conección IP.
5. Copila y carga el código ( boton.py ) e introduce en cualquier navegador la direccion ip creada anteriormente. 
6. Pulsa cualquier boton para emitir una señal.


