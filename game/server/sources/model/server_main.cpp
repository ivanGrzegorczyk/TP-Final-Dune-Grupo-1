#include "server/headers/model/Server.h"
#include <sstream>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return -1;
    } 
    Server server(argv[1]);

    try {
        server.run();
    } catch(const std::exception &e) {
        std::ostringstream oss;
        oss << "[main]: " << e.what() << std::endl;
        // Para evitar RC en el flujo de error
        std::cerr << oss.str();
        return -1;
    }
    return 0;
}
