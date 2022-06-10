#include <mutex>
#include <vector>
#include <utility>
#include <iostream>

#include "../headers/ThCLient.h"

ThClient::ThClient(Socket &&skt):
        keep_talking(true), is_running(true), peer(std::move(skt)) {}

void ThClient::run() {
    while (keep_talking) {
        //recibirComando();
    }

    is_running = false;
}

void ThClient::stop() {
    keep_talking = false;
    peer.shutdown(SHUT_RDWR);
    peer.close();
}

bool ThClient::isDead() {
    return !is_running;
}
