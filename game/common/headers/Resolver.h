#ifndef RESOLVER_H_
#define RESOLVER_H_

struct addrinfo;

class Resolver {
    addrinfo* result; // struct addrinfo* next
    addrinfo* _next;
public:
    // interface
    bool has_next();
    addrinfo* next();

    //constructor and destructor
    Resolver(const char* hostname, const char* servicename, bool server);
    ~Resolver();

    // forbid copying
    Resolver(const Resolver&) = delete;
    Resolver& operator=(const Resolver&) = delete;

    // allow moving
    Resolver(Resolver&&);
    Resolver& operator=(Resolver&&);
};

#endif  // RESOLVER_H_
