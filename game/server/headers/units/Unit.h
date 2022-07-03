#ifndef UNITY_H_
#define UNITY_H_

#include <utility>
#include <stack>
#include <memory>

#include "common/headers/Entity.h"
#include "common/headers/Constantes.h"
#include "server/headers/model/MovableEntity.h"

class Unit: public MovableEntity {  // abstracta
protected:
    unsigned int range;
    unsigned int cost;
    int target;

public:
    Unit(int id, unsigned int hp, unsigned int range, unsigned int speed,
         int type, unsigned int cost, coordenada_t coord);

    virtual std::shared_ptr<Unit> copy() = 0;

    virtual ~Unit() = default;

    unsigned int getRange() const;

    void setTarget(int _target);

    bool hasTarget();
};

#endif  // UNITY_H_
