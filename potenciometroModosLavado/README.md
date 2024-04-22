# Seleccionar Modo de Lavado - Panel de Lavadora

## Implementación

Esta funcionalidad lo que permite es seleccionar el modo de lavado mediante un potenciometro por medio de una Raspberry Pi Pico W la cual encendera y apagará leds, manteniendo encendido el que se quede seleccionado.

## Esquema Fisico

<img src="./EsquemaFisico.png" style="max-height:300px;">

## Funcionamiento

Al energinar la raspberry el programa estará leyendo la entrada analogica del potenciometro, la cual cambiará si es girado este mismo.
Los leds encendidos nos indican los diferentes modos de lavado:
* Normal
* Lavado Rápido
* Delicados
* Ropa de Cama
* Jeans
* Lavado Eco de Tambor

## Diagrama de Flujo del programa modularizado

<img src="./DiagramaFlujo.png" style="max-height:300px;">

## Instalación y Uso

1. Clona este repositorio en tu dispositivo.
2. Conecta los componentes a la Raspberry Pi Pico W y a la protoboard según el esquema de conexión proporcionado.
3. Compila y carga el código en la Raspberry Pi Pico W.
4. Gira la perilla del potenciómetro para seleccionar un modo.