#include "../headers/Server.h"

int main(int argc, char* argv[]) {
    if (argc > 0) {
        Server server(argv[0], 10, 30);

        try {
            server.run();
        } catch(const std::exception &e) {
            return 1;
        }
    }
}
