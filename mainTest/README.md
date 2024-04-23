#  mainTest Integracion Boton encendido/apagado y Nivel de agua - Panel de lavadora

# Implementacion 
Este código en lenguaje C, diseñado para el microcontrolador Raspberry Pi Pico W H, que modularizar el boton nivel de agua y boton de encendido y apagado del panel de la lavadora, teniendo las funciones se ingrena en un main para poder ejecutar los botones a la vez

# Materiales
Para prototipar el botón de encendido y apagado del LED:

1. Raspberry pi pico W H
2. Protoboard
3. 2 Botones DIL Push
4. 11 Cables M/M 
5. 6 LED
6. 6 Resistencia 220 Ohms 5%

#  Funcionamiento
Este código implementa un programa para controlar una lavadora mediante Raspberry Pi Pico. Se utilizan dos módulos principales: "boton_encendido.h" y "bAgua.h". El programa inicia inicializando la entrada/salida estándar y los componentes necesarios, como el botón de encendido y los LEDs que indican los niveles de agua. A través de un bucle infinito, el programa verifica si se presiona el botón de encendido y, en caso afirmativo, alterna el estado de la lavadora y actualiza el estado en la consola. Además, si la lavadora está encendida, se controlan los LEDs que indican los niveles de agua. Este código demuestra cómo modularizar la funcionalidad de la lavadora para facilitar la lectura y el mantenimiento del código.


# Prototipo

<img src="./Boton Agua-Encendido.png" style="max-height:600px;">
Nota:Los GPIO utilizados pueden variar dependiendo como se conecta.


# Pasos
1. Ejecutar el código en una IDE.
2. Cablear el prototipo según el ejemplo.
3. Cargar el código en el microcontrolador Raspberry Pi Pico W.
4. Probar el funcionamiento del botón de encendido/apagado y selecion de nivel de agua de la lavadora.


