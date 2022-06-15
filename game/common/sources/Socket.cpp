
/* 
Crédito del código: https://github.com/Taller-de-Programacion/sockets-en-cpp
2022 facultad de ingeniería de la UBA
Licencia: https://opensource.org/licenses/gpl-2.0.php
*/

#include <unistd.h> //::close
#include <exception>
#include <sys/socket.h>
#include <netdb.h>  //defines addrinfo
#include <iostream>

#include "../headers/Socket.h"
#include "../headers/Resolver.h"

#define NO_SOCKET -1

//constructor for client
Socket::Socket(const char* hostname, const char* portname){
    Resolver r(hostname, portname, false);
    closed = false;
    int skt = NO_SOCKET;
    int result = -1;
    while (r.has_next()) {
        struct addrinfo *addr = r.next();
        if (skt != NO_SOCKET){
            ::close(skt);
        }
        skt = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (skt == NO_SOCKET)
            continue;

        result = connect(skt, addr->ai_addr, addr->ai_addrlen);
        if (result == -1) {
            continue;
        }

        this->skt = skt;
        return;
    }
}
// constructor for server
Socket::Socket(const char* portname) {
    Resolver resolver(nullptr, portname, true);
    closed = false;
    int s;
    int skt = -1;
    while (resolver.has_next()) {
        struct addrinfo *addr = resolver.next();
        if (skt != -1)
            ::close(skt);

        skt = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (skt == -1) {
            continue;
        }

        int val = 1;
        s = setsockopt(skt, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (s == -1) {
            continue;
        }

        s = bind(skt, addr->ai_addr, addr->ai_addrlen);
        if (s == -1) {
            continue;
        }

        s = listen(skt, 20);
        if (s == -1) {
            continue;
        }
        this->skt = skt;
        return;
    }
    perror("socket setup failed");
    if (skt != -1)
        ::close(skt);
}

/*
 * Constructor privado que inicializa el socket pasandole directamente el file descriptor.
 * */
Socket::Socket(int skt) {
    this->skt = skt;
    this->closed = false;
}

Socket::~Socket() {
    if (not this->closed) {
        ::shutdown(this->skt, 2);
        ::close(this->skt);
    }
}
int Socket::recvsome(void *data, unsigned int sz) {
    int s = recv(this->skt, (char*)data, sz, 0);
    if (s == 0) {
        throw TCPClosedSocketError();
    } else if (s < 0) {
        throw std::invalid_argument("Recvsome error");
    } else {
        return s;
    }
}

int Socket::sendsome(const void *data, unsigned int sz) {
    int s = send(this->skt, (char*)data, sz, MSG_NOSIGNAL);
    if (s == 0) {
        // Puede o no ser un error (vease el comentario en recvsome())
        throw TCPClosedSocketError();
    // todo use more exceptions not numbers
    } else if (s < 0) {
        if (errno == EPIPE) {
            std::cout << "epipe" << std::endl;
            throw std::exception();
        }
        // 99% casi seguro que es un error
        std::cout << "socket getData failed" << std::endl;
        throw std::exception();
    } else {
        return s;
    }
}

int Socket::recvall(void *data, unsigned int sz) {
    unsigned int received = 0;
    while (received < sz) {
        int s = this->recvsome(
            (char*)data + received, sz - received);
        received += s;
    }
    return sz;
}


int Socket::sendall(const void *data, unsigned int sz) {
    unsigned int sent = 0;
    while (sent < sz) {
        //TODO bug! not checking sendsome's output
        int s = this->sendsome((char*)data + sent, sz - sent);
        sent += s;
    }

    return sz;
}

Socket Socket::accept() {
    int skt = ::accept(this->skt, nullptr, nullptr);
    if (skt < 0) {
        // TODO descriptive exc
        throw std::exception();
    }
    return Socket(skt);
}

int Socket::shutdown(int how) {
    if (::shutdown(this->skt, how) == -1) {
        perror("socket shutdown failed");
        throw std::exception();
    }
    return 0;
}

int Socket::close() {
    this->closed = true;
    return ::close(this->skt);
}

// move constructor
Socket::Socket(Socket &&other) {
    this->skt = other.skt;
    other.skt = -1; 
}
// move assignment
Socket& Socket::operator=(Socket &&other) {
    this->skt = other.skt;
    other.skt = -1;
    return *this;
}
