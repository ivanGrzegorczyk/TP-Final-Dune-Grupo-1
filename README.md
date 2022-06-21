# TP FINAL DUNE

Integrantes:
Padrón: 104084
Nombre: Iván Grzegorczyk

## Introducción


## Implementación

## Servidor
#### Modelo
El servidor es el encargado de llevar la información de las partidas (para esta entrega hay implementada una sola partida con varios jugadores). Usa una cola protegida para la recepción de eventos por parte del cliente y una cola bloqueante para enviar un snapshot de la partida. Funciona con 4 hilos:

- El _hilo principal_ lleva a cabo el gameloop. Esto va a cambiar cuando implementemos múltiples partidas. En el mismo se manejan los eventos que llegan de los distintos clientes.
- El _hilo aceptador_ acepta los intentos de conexión de los clientes y lanza a su vez un nuevo hilo por cada uno en el que se reciben comandos. Los clientes se guardan en una estructura protegida para evitar tener una race condition entre el hilo aceptador y el broadcast. Al momento de lanzar un hilo para un cliente se le asigna al mismo un id y se le envía la información del terreno.
- El _hilo broadcast_ envía un snapshot de la partida a todos los jugadores en cada iteración del gameloop.
- El _hilo finish_ sirve para cerrar el servidor cuando se ingrese una 'q' por entrada estándar. Libera los recursos y corta el programa.

Para el protocolo de comunicación TCP/IP usamos el TDA de sockets que nos brindó la cátedra ligeramente modificado. Todavía faltan implementar excepciones custom para algunos casos particulares como por ejemplo cuando falla el accept. Para simplificar el parseo y por falta de tiempo decidimos enviar la gran mayoría de datos de a 2 bytes.

### Mapa
El mapa consiste de una matriz de _N x M_ dimensiones. Cada coordenada de la matriz es un puntero a una _ServerCell_, de esta manera se busca poder darle un comportamiento polimorfico a los distintos tipos de terreno. Actualmente solo está implementados el suelo de roca y arena. Para la arena se empezó a implementar la posibilidad de cosechar pero hasta que la parte gráfica no esté implementada es dificil de testear.
Cada celda del mapa tiene punteros del tipo _std::weak_ptr_ a las distintas entidades que posee. Con el objetivo de poder usarlas en el algoritmo de movimiento. Esta idea de momento no funciona y está todavía en desarrollo.

El mapa contiene tres diccionarios con clave el id del jugador y valor una clase _Player_ que contiene todos los datos correspondientes a cada jugador como unidades, recursos, etc. Cada entidad está identificada con un id único designado por el servidor.

Para recorrer el mapa se encapsuló dentro de la clase _Navigator_ el [algoritmo A-Star] basado en el pseudo código explicado en wikipedia. En caso de que la unidad no encuentre un camino posible a su destino va a proceder a desplazarse hasta la posición más cercana posible.

### Eventos
Por cada comando que llega de un cliente se crea un evento y se pushea en la _cola protegida_, luego en el gameloop se popean todos los eventos y se usan para actualizar todos los datos de la partida.

Actualmente hay implementados 3 eventos:

- El _Evento de spawneo_ sirve para crear unidades en la posición especificada. Actualmente se puede crear únicamente la infantería ligera. Cuando estén implementados los cuarteles se decidirá la posición en base a la ubicación del edificio y no en base a lo que pide el cliente.
- El _Evento de reposicionamiento_ sirve para que las unidades se desplacen por el mapa. Usando el identificador particular de cada unidad el cliente enviará un request de movimiento. El servidor usando los datos del mensaje procede a calcular el camino más corto para la unidad y lo guarda, luego en cada iteración del gameloop se actualiza la posición de la unidad.
- El _Evento de creación de edificios_ sirve para spawnear un edificio en las coordenadas especificadas. Actualmente solo está modelado el cuartel pero todavía no está implementado graficamente.

### Entidades
Todas las entidades están identificadas por un id designado al momento de ser creadas por el servidor y sus coordenadas en el mapa. Usando este dato el cliente puede enviar comandos para llevar a cabo con distintas unidades, vehículos, edificios, etc.

Las entidades que están parcialmente implementadas desde el servidor son la _infantería ligera_, el _cuartel_ y la _cosechadora_. Solo la infantería ligera tiene un comportamiento que se pueda observar en una partida.

[algoritmo A-Star]: <https://en.wikipedia.org/wiki/A*_search_algorithm>
