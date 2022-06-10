#ifndef UNITY_H_
#define UNITY_H_

#include "Entity.h"

class Unity: public Entity {  // abstracta
private:
    coordenada_t id;

public:
    virtual ~Unity() = 0;
};

#endif  // UNITY_H_
