#ifndef UNITY_H_
#define UNITY_H_

#include <utility>
#include <stack>
#include <memory>

#include "common/headers/Entity.h"
#include "common/headers/Constantes.h"

class Unit: public Entity {  // abstracta
protected:
    int range;
    int speed;
    std::stack<coordenada_t> path;

public:
    Unit(int id, double hp, int range, int speed, int type, coordenada_t coord);
    void setPath(std::stack<coordenada_t> _path);
    void setPosition(coordenada_t newPosition);
    coordenada_t relocate();
    virtual std::shared_ptr<Unit> copy() = 0;

    virtual ~Unit() = default;
};

#endif  // UNITY_H_
