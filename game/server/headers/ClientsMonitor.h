#ifndef CLIENTSMONITOR_H_
#define CLIENTSMONITOR_H_

#include <list>

#include "ThCLient.h"

class ClientsMonitor {
private:
    std::list<ThClient *> clients;
    std::mutex mutex;

    static bool cleanClient(ThClient *client);
public:

    ~ClientsMonitor();

    void push(ThClient *client);
    void broadCast(const std::vector<uint16_t> &snapshot);
    void clean();

    void clearAll();
};

#endif  // CLIENTSMONITOR_H_
