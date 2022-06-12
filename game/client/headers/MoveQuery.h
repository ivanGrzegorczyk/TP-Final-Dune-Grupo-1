#ifndef TP_FINAL_DUNE_GRUPO_1_MOVEQUERY_H
#define TP_FINAL_DUNE_GRUPO_1_MOVEQUERY_H
#include "InputEvent.h"


class MoveQuery : public InputEvent {
private:
    int unityId;
    coordenada_t dest;
public:
    explicit MoveQuery(int id, coordenada_t &&dst);
    void send(Protocol &protocol) override;
};

#endif //TP_FINAL_DUNE_GRUPO_1_MOVEQUERY_H
