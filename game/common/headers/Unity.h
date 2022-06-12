#ifndef UNITY_H_
#define UNITY_H_

#include <utility>

#include "Entity.h"

class Unity: public Entity {  // abstracta
protected:
    coordenada_t coord;
    std::stack<coordenada_t> path;

public:
    void setPath(std::stack<coordenada_t> _path) { this->path = std::move(_path);}
    coordenada_t getPosition() {return coord;}

    ~Unity() override = 0;
};

#endif  // UNITY_H_
