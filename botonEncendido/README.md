#  Boton de encedido y apagado - Panel de lavadora

# Implementacion 
Este código en lenguaje C, diseñado para el microcontrolador Raspberry Pi Pico W H, permite controlar el encendido y apagado de una lavadora mediante un botón. Al presionar el botón, se enciende un LED que simboliza el funcionamiento de la lavadora. Presionar nuevamente el botón apaga el LED y desactiva las funciones de la lavadora.

# Materiales
Para prototipar el botón de encendido y apagado del LED:

1. Raspberry pi pico W H
2. Protoboard
3. Boton DIL Push
4. 4 Cables M/M 
5. 1 LED
6. 1 Resistencia 220 Ohms 5%

#  Funcionamiento
Al inicializar el codigo, se configuran los pines del LED y el botón, y se habilita una resistencia pull-up en el pin del botón para evitar fluctuaciones en el estado. La función verificar_boton_encendido() comprueba si el botón está presionado. Cuando se detecta que el botón está presionado, la función control_leds_encendido() alterna el estado del LED entre encendido y apagado y muestra un mensaje correspondiente en la consola. El ciclo de espera de 200 milisegundos entre cada cambio de estado evita que se detecten múltiples pulsaciones inadvertidas.

# Prototipo
[Imagen]

Nota:Los GPIO utilizados pueden variar dependiendo como se conecta.


# Pasos
1. Ejecutar el código en una IDE.
2. Cablear el prototipo según el ejemplo.
3. Cargar el código en el microcontrolador Raspberry Pi Pico W.
4. Probar el funcionamiento del botón de encendido y apagado de la lavadora.








