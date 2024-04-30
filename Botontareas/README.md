# BOTON TAREAS CICLOS DE LAVADO

## Implementación del código
Este código, desarrollado en lenguaje C, tiene como propósito gestionar un conjunto de LEDs empleando un microcontrolador Raspberry Pi Pico W. El sistema se adapta dinámicamente en respuesta al número de pulsaciones de un botón. Cada pulsación desencadena un comportamiento específico:

- Una sola pulsación enciende la tarea de lavado.
- Dos pulsaciones activan simultáneamente las tareas de enjuague y centrifugado.
- Tres pulsaciones encienden todas las tareas disponibles: lavado, enjuague y centrifugado.

## Materiales que se necesitan para implementar el prototipo:
1. LEDs x3
1. Resistencias de 220 Ohms (recomendado) x3
1. Botón DIL Push x1
1. Cables Jumper Tipo Macho-Macho x4
1. Raspberry Pi Pico W
1. Protoboard x1

## Funcionalidades
El sistema tiene las siguientes características:
Al presionar una vez, se enciende el primer LED. Al presionar nuevamente, se enciende el segundo LED y el tercer LED. Si se vuelve a presionar, se encienden los tres LEDs simultáneamente. Y si se presiona otra vez, se apagan todos los LEDs.

## Ejemplo de ensamble del prototipo
El prototipo se monta de la siguiente manera:

- Conexión de los LEDs: Utiliza cables jumper para conectar los LEDs a los pines GPIO 14,GPIO 15, GPIO 16 del Raspberry Pi Pico W. 

- Conexión del botón: Conecta el pin de entrada GPIO 17 al botón de la protoboard usando un cable jumper.

- Conexión a tierra: Asegúrate de conectar el pin de tierra (GND) del Raspberry Pi Pico W a la protoboard para proporcionar una referencia común para las conexiones.

- Conexión de resistencias: Conecta resistencias en serie con los LEDs para limitar la corriente.

<img src="./boton tareas.png" style="max-height:600px;">

## Diagrama de Flujo del programa modularizado
<img src="./Diagrama de flujo.png" style="max-height:600px;">

## Instalación y Uso
1. Clona este repositorio en tu dispositivo.
1. Conecta los componentes a la Raspberry Pi Pico W y a la protoboard según el esquema de conexión proporcionado.
1. Compila y carga el código en la Raspberry Pi Pico W.
1. Presiona el botón según el comportamiento deseado de los LEDs.
1. Mantén presionado el botón por más de 2 segundos para apagar todos los LEDs.
