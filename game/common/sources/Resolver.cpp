#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>

#include "../headers/Resolver.h"

Resolver::Resolver(const char* hostname, const char* portname, bool server){
    this->result = this->_next = nullptr;
    int ipv4 = AF_INET; //sys/socket.h
    int tcp = SOCK_STREAM; //sys/socket.h
    int passive = AI_PASSIVE; //netdb.h

    struct addrinfo hints; //sys/types.h
    memset(&hints, 0, sizeof(hints)); //string.h
    hints.ai_family = ipv4;
    hints.ai_socktype = tcp;
    hints.ai_flags = server ? passive : 0;

    int result = getaddrinfo(hostname, portname, &hints, &this->result);

    if (result != 0) {
        printf("Could not resolve.\n"); //stdio.h
        perror("resolver error");
    }
    this->_next = this->result;
}
Resolver::~Resolver(){
    if (this->result) {
        freeaddrinfo(this->result);
    }
}
Resolver::Resolver(Resolver&& other) {
    // take ownership of other's resources
    this->result = other.result;
    this->_next = other._next;

    // remove other's ownership
    other.result = other._next = nullptr;
}

Resolver& Resolver::operator=(Resolver&& other) {
    // handle resolver = resolver
    if (this == &other)
        return *this;

    // remove self's data
    if (this->result)
        freeaddrinfo(this->result);

    // take ownership
    this->result = other.result;
    this->_next = other._next;
    other.result = other._next = nullptr;
    return *this;
}

bool Resolver::has_next() {
    return this->_next != NULL;
}

struct addrinfo* Resolver::next() {
    struct addrinfo *ret = this->_next;
    this->_next = ret->ai_next;
    return ret;
}
