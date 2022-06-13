#ifndef TP_FINAL_DUNE_GRUPO_1_REQUEST_H
#define TP_FINAL_DUNE_GRUPO_1_REQUEST_H
#include "Protocol.h"

class Request {
protected:
public:
    virtual void send(Protocol &protocol) = 0;

};


#endif //TP_FINAL_DUNE_GRUPO_1_REQUEST_H
