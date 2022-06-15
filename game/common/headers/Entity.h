#ifndef ENTITY_H_
#define ENTITY_H_

#include <utility>

class Entity {  // Va terminar siendo una clase abstracta
protected:
    int id;
    double HP;

public:
    Entity(int id, double HP);
    virtual ~Entity() = default;
};

#endif  // ENTITY_H_
