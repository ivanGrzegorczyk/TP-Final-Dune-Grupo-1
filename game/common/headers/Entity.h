#ifndef ENTITY_H_
#define ENTITY_H_

typedef std::pair<int, int> coordenada_t;

class Entity {  // Va terminar siendo una clase abstracta
protected:
    int id;
    double HP;

public:
    virtual ~Entity() = 0;
};

#endif  // ENTITY_H_
