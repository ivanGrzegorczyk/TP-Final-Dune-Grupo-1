#ifndef UNITY_H_
#define UNITY_H_

#include "Entity.h"

class Unity: public Entity {  // abstracta
protected:
    coordenada_t coord;
    std::stack<coordenada_t> path;

public:
    virtual ~Unity() = 0;
};

#endif  // UNITY_H_
