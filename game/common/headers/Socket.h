#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/socket.h>
#include <exception>

struct addrinfo;

class Socket {
    int skt;
    bool closed;
    explicit Socket(int skt); // private constructor

    public:
    Socket(const char* hostname, const char* portname);
    explicit Socket(const char* portname);
    ~Socket();
        /* Socket::sendsome() lee hasta sz bytes del buffer y los envia. La funcion
     * puede enviar menos bytes sin embargo.
     *
     * Si el socket detecto que la conexion fue cerrada, la variable
     * was_closed es puesta a True, de otro modo sera False.
     *
     * Retorna 0 si se cerro el socket, menor a 0 si hubo un error
     * o positivo que indicara cuantos bytes realmente se enviaron/recibieron.
     * */
    int sendsome(const void *data, unsigned int sz);

        /* Socket::recvsome() recibe hasta sz bytes y los escribe
     * en el buffer (que debe estar pre-allocado). La funcion puede recibir
     * menos bytes sin embargo.
     *
     * Si el socket detecto que la conexion fue cerrada, la variable
     * was_closed es puesta a True, de otro modo sera False.
     *
     * Retorna 0 si se cerro el socket, menor a 0 si hubo un error
     * o positivo que indicara cuantos bytes realmente se enviaron/recibieron.
     * */
    int recvsome(void *data, unsigned int sz);

    /*
     * Socket::sendall() envia exactamente sz bytes leidos del buffer, ni mas,
     * ni menos. Socket::recvall() recibe exactamente sz bytes.
     *
     * Si hay un error o el socket se cerro durante el envio/recibo de los bytes
     * no hay forma certera de saber cuantos bytes realmente se enviaron/recibieron.
     *
     * En caso de error se retorna un valor negativo, se retorna 0
     * si el socket se cerro o un valor positivo igual a sz si se envio/recibio
     * todo lo pedido.
     *
     * En caso de que se cierre el socket, was_closed es puesto a True.
     * */
    int sendall(const void *data, unsigned int sz);
    int recvall(void *data, unsigned int sz);

    // forbid copying
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    // allow moving
    Socket(Socket&&);
    Socket& operator=(Socket&&);

    Socket accept();
    int shutdown(int how);
    int close();
};

//TODO move
class TCPClosedSocketError: public std::exception { 
    public:
    const char* what() const noexcept {
        return "Socket was closed\n";
    }
};

#endif  // SOCKET_H_
