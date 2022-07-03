#ifndef ENTITY_H_
#define ENTITY_H_

#include <utility>
#include "common/headers/Constantes.h"

class ServerEntity {  // Va terminar siendo una clase abstracta
protected:
    int id;
    unsigned int HP;
    int type;
    coordenada_t coord;

public:
    ServerEntity(int id, unsigned int HP, int type, coordenada_t coord);

    int getType() const;
    int getId() const;
    coordenada_t getPosition();

    bool receiveDamage(unsigned int damage);

    virtual ~ServerEntity() = default;
};

#endif  // ENTITY_H_
