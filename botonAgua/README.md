# Descripcion
Este código, diseñado para el microcontrolador Raspberry Pi Pico W H, añade la funcionalidad de selección de nivel de agua a una lavadora simulada. Se utiliza un botón adicional para seleccionar entre cinco niveles de agua, representados por LEDs.

# Implementacion
El código en lenguaje C configura los pines del botón de selección de nivel de agua y los LEDs correspondientes. Se utiliza una resistencia pull-up en el pin del botón de selección de nivel de agua para estabilizar su estado. Cuando se presiona el botón de selección de nivel de agua, se activa un LED que indica el nivel seleccionado.


# Materiales
1. Raspberry Pi Pico W H
2. Protoboard
3. Botón DIL Push (para selección de nivel de agua)
4. 8 Cables Macho/Macho
5. 5 LEDs adicionales (para representar los niveles de agua)
6. 5 Resistencias de 220 Ohms (5%) (para los LEDs de nivel de agua)

# Funcionamiento
Al inicializar el código, se configuran los pines de los LEDs de nivel de agua y el botón de selección de nivel de agua. La función verificar_boton_nivel_agua() detecta la presión del botón de selección de nivel de agua y la función control_leds_nivel_agua() activa el LED correspondiente al nivel seleccionado.

# Prototipo
<img src="./Boton nivel de agua.png" style="max-height:600px;">


Nota: Los GPIO utilizados pueden variar dependiendo de la configuración.

# Pasos
1. Ejecutar el código en una IDE compatible con Raspberry Pi Pico.
2. Cablear el prototipo según el esquema proporcionado.
3. Cargar el código en el microcontrolador Raspberry Pi Pico W.
4. Probar el funcionamiento del botón de selección de nivel de agua de la lavadora.