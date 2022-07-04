#ifndef MOVABLEENTITY_H_
#define MOVABLEENTITY_H_

#include <stack>
#include "common/headers/Constantes.h"
#include "common/headers/Entity.h"

class MovableEntity : public Entity {
protected:
    unsigned int speed;
    std::stack<coordenada_t> path;

public:
    MovableEntity(int id, unsigned int hp, int type, unsigned int speed, coordenada_t coord);
    coordenada_t getGoal();
    coordenada_t getNextPosition();
    void setPath(std::stack<coordenada_t> _path);
    bool isStill();
    virtual coordenada_t relocate();
};

#endif  // MOVABLEENTITY_H_
