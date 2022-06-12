#ifndef TP_FINAL_DUNE_GRUPO_1_INPUTEVENT_H
#define TP_FINAL_DUNE_GRUPO_1_INPUTEVENT_H
#include "Protocol.h"
#include "../../common/headers/Event.h"

class InputEvent: public Event {
protected:
public:
    virtual void send(Protocol &protocol) = 0;

};


#endif //TP_FINAL_DUNE_GRUPO_1_INPUTEVENT_H
