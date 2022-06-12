#ifndef REPOSITIONEVENT_H_
#define REPOSITIONEVENT_H_

#include <utility>
#include "../../common/headers/Entity.h"
#include "ServerEvent.h"

class RepositionEvent : public ServerEvent {
public:
    int unitId;
    coordenada_t goal;

    RepositionEvent(int id, coordenada_t goal);

    void performEvent(Server *server) override;
};

#endif  // REPOSITIONEVENT_H_
