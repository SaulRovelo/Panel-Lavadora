## Implementación del código
Este código, escrito en lenguaje C, tiene como objetivo controlar tres LEDs utilizando un microcontrolador Raspberry Pi Pico W. Los LEDs representan diferentes niveles de temperatura y se cambian en respuesta a las pulsaciones de un botón. Si presionas una vez, se enciende el nivel 1 de temperatura; si presionas una vez más, se activa el nivel 2; si presionas una vez más, se activa el nivel 3; y finalmente, si presionas una vez más, se apagan todos los LEDs.
## Materiales que se necesitan para implementar el prototipo:
1. LEDs x3
1. Resistencias de 220 Ohms (recomendado) x3
1. Botón DIL Push x1
1. Cables Jumper Tipo Macho-Macho x4
1. Raspberry Pi Pico W
1. Protoboard x1

## Funcionalidades
El sistema tiene las siguientes características:
- Al presionar una vez el botón, se enciende el primer LED, representando el nivel de temperatura 1.
- Al presionar dos veces el botón, se enciende el segundo LED, representando el nivel de temperatura 2.
- Al presionar tres veces el botón, se enciende el tercer LED, representando el nivel de temperatura 3.
- Al presionar nuevamente el botón, se apagan todos los LEDs y se reinicia el ciclo.
- Este enfoque proporciona una representación visual clara de los diferentes niveles de temperatura.


## Ejemplo de ensamble del prototipo
El prototipo se monta de la siguiente manera:

- Conexión de los LEDs: Utiliza cables jumper para conectar los LEDs a los pines GPIO 0,GPIO 1, GPIO 2 del Raspberry Pi Pico W. 

- Conexión del botón: Conecta el pin de entrada GPIO 3 al botón de la protoboard usando un cable jumper.
- Conexión a tierra: Asegúrate de conectar el pin de tierra (GND) del Raspberry Pi Pico W a la protoboard para proporcionar una referencia común para las conexiones.

- Conexión de resistencias: Conecta resistencias en serie con los LEDs para limitar la corriente.


## Instalación y Uso
1. Clona este repositorio en tu dispositivo.
1. Conecta los componentes a la Raspberry Pi Pico W y a la protoboard según el esquema de conexión proporcionado.
1. Compila y carga el código en la Raspberry Pi Pico W.
1. Presiona el botón según el nivel de temperatura deseado.
1. Repite el paso anterior para cambiar entre los diferentes niveles de temperatura. 