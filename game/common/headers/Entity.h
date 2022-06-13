#ifndef ENTITY_H_
#define ENTITY_H_

#include <utility>

typedef std::pair<int, int> coordenada_t;

class Entity {  // Va terminar siendo una clase abstracta
protected:
    int id;
    double HP;

public:
    Entity(int id, double HP);
    virtual ~Entity() = 0;
};

#endif  // ENTITY_H_
