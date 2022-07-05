## Integrantes:

Padrón: 104084
Nombre: Iván Grzegorczyk

Padrón: 104229
Nombre: María Pont

Padrón: 104082
Nombre: Daniel Aceval

## Introducción
Este proyecto consiste en una reimplementación del juego clásico Dune 2000.

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

## Editor
El editor es un módulo independiente del resto del juego que utiliza QT y YAML para permitirle al usuario crear y editar mapas. Estos mapas pueden definir el tamaño, terreno, cantidad de jugadores, cantidad de especia y ubicación de centros de construcción de un juego inicial.

En la primera ventana, el usuario puede o crear un nuevo mapa de cierto tamaño, o abrir uno existente, proveyendo
la dirección del archivo respecto de la carpeta del proyecto.

La segunda ventana provee una vista del mapa y una serie de botones para colocar los centros de construcción,
arena con cierta cantidad de especia, terreno de montaña y roca. Sólo se pueden colocar tantos centros
de construcción como hayan jugadores, y actualmente no pueden ser borrados una vez construidos.
Con el botón save se puede guardar un mapa con cierto nombre en un archivo .yaml, que
puede ser deserializado por el servidor.

## Cliente

En el caso del cliente la estructura es similar con respecto a los hilos. Se tienen 3 de ellos cada uno con una función diferente.
- Hilo Principal: El cual como en el **servidor** es el encargado de llevar el gameloop.
- Hilo de envío: Este hilo en su interior maneja una cola bloqueante encargada de llevar cada una de las solicitudes del usuario al servidor que es procesada por el protocolo para su correcto envío.
- Hilo para recibir cada una de las respuestas ya procesadas por el servidor para luego modificar el estado de juego. Este hilo manipula una cola protegida para recibir dichas respuestas.

### UI
#### Controles
La tecla B corresponde a crear un edificio, la H a una cosechadora, la A a una unidad. Se usa click izquierdo para seleccionar unidades y click derecho para moverlas en una dirección. Se pueden seleccionar y mover muchas unidades a la vez. 
#### Menú
Un menú en la esquina superior derecha muestra los distintos tipos de edificios que se pueden crear.
Al hacer click izquierdo a uno de estos, la tecla *b* generará el edificio seleccionado. Este edificio tiene colisión determinada por el servidor tal que las unidades no pisan sobre él.

### Mapa
El mapa consta momentáneamente de un diccionario para las unidades/edificios, en él se contiene como clave el id del jugador y cada una de las unidades/edificios que le pertenecen, tiene un vector de clase **Celda** que poseen una textura y la capacidad de copiar una porción de su textura en el render y además un vector con cada uno de los tipos de terreno que hay en el mapa.


El mapa es lo primero que se carga en el cliente dado que al iniciar la comunicación con el servidor este le envía cada una de las características del terreno para que se construya utilizando la clase **Celda** mencionada anteriormente para luego ser renderizada y mostrada al usuario.

### Solicitudes
El cliente posee la solicitud de caminar y de spawn de personaje que son accionadas por un evento del mouse y teclado respectivamente. La solicitud de caminar posee la posición en el cual el personaje se quiere mover capturando las posiciones __x__ e __y__ del mouse junto con el id del personaje para que el servidor pueda identificarlo. Esta solicitud es procesada por el servidor y como respuesta devuelve el estado actual del juego incluyendo la nueva posición del personaje que accionó el evento de caminar.
Para mover al personaje se tiene que hacer click con el botón izquierdo para seleccionarlo y elegir con el botón derecho la celda objetivo para disparar dicha solicitud.

Por otro lado, para hacer aparecer personajes en diferentes lugares del mapa se tiene que pulsar la tecla **a** que generará la solicitud de spawn de personaje al servidor con las coordenadas de donde se desea posicionar. De igual manera se puede generar un edificio con la letra *b* y una cosechadora con la letra *h*. 

### Response
Esta clase es la encargada de llevar toda la información de la respuesta del servidor al cliente para actualizar el estado del mapa. Se recibe por parámetro todas las unidades para luego posicionarlas en su nuevo lugar si es que sufrieron algún cambio de posición o crear nuevos personajes si no estaban.
Esta clase se tiene que refactorizar, ya que se tiene que si se tiene que actualizar edificios, vehículos tal como está momentáneamente implementada se duplicaría en tamaño y mucho de ese código sería repetido.
