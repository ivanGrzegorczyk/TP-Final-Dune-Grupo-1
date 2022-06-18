#ifndef ENTITY_H_
#define ENTITY_H_

#include <utility>
#include "Constantes.h"

class Entity {  // Va terminar siendo una clase abstracta
protected:
    int id;
    int HP;
    int type;
    coordenada_t coord;

public:
    int getType() const;
    coordenada_t getPosition();
    Entity(int id, int HP, int type, coordenada_t coord);
    virtual ~Entity() = default;
};

#endif  // ENTITY_H_
