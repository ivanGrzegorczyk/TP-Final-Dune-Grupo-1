#include "../headers/CreateUnity.h"

void CreateUnity::send(Protocol &protocol) {
    protocol.sendCreateUnity();
}

int CreateUnity::CreateUnity() {
    return 0;
}
