#ifndef UNITY_H_
#define UNITY_H_

#include <utility>
#include <stack>
#include <memory>

#include "common/headers/Entity.h"
#include "common/headers/Constantes.h"

class Unit: public Entity {  // abstracta
protected:
    unsigned int range;
    unsigned int speed;
    unsigned int cost;
    int target;
    std::stack<coordenada_t> path;

public:
    Unit(int id, unsigned int hp, unsigned int range, unsigned int speed,
         int type, unsigned int cost, coordenada_t coord);
    void setPath(std::stack<coordenada_t> _path);
    void setPosition(coordenada_t newPosition);
    coordenada_t relocate();
    virtual std::shared_ptr<Unit> copy() = 0;

    virtual ~Unit() = default;

    bool isStill();

    unsigned int getRange() const;

    void setTarget(int _target);

    bool hasTarget();

    coordenada_t getGoal();

    coordenada_t getNextPosition();
};

#endif  // UNITY_H_
