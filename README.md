# TP FINAL DUNE

Integrantes:

Padrón: 104084
Nombre: Iván Grzegorczyk

Padrón: 104229
Nombre: María Pont

Padrón: 104082
Nombre: Daniel Aceval

## Instalación
Este proyecto sólo es ejecutable en Ubuntu 20.04 hasta 21.04
### Dependencias
Para compilar el código es necesario instalar los siguientes paquetes:
cmake (3.22.4+)
make
yaml-cpp
Qt5
SDL
SDL2cpp

### Línea de compilación
El juego puede ser compilado desde la línea de comandos mediante:
cmake . && make

## Ejecución
Para ejecutar el servidor podrá hacerlo con la línea:
./Server \[puerto]

El cliente:
./Client \[nombre de host] \[puerto]

Y finalmente el editor:
./Editor

## Controles
Con las teclas A y B se crean unidades de infantería ligera y pesada respectivamente. Con la letra C se crean edificios previamente seleccionados con click izquierdo en la gui. Se usa click izquierdo para seleccionar unidades y click derecho para moverlas en una dirección. Se pueden seleccionar y mover muchas unidades a la vez. 

#### Menú
Un menú en la esquina superior derecha muestra los distintos tipos de edificios que se pueden crear.
Al hacer click izquierdo a uno de estos, la tecla *b* generará el edificio seleccionado. Este edificio tiene colisión determinada por el servidor tal que las unidades no pisan sobre él.

## Diagramas
![diagrama de hilos server](https://user-images.githubusercontent.com/56945900/177440787-c762daf5-f6e0-4c95-93e8-c25be83587e3.png)

