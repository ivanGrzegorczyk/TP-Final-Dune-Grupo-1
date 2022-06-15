#ifndef UNITY_H_
#define UNITY_H_

#include <utility>
#include <stack>

#include "Entity.h"
#include "Constantes.h"

class Units: public Entity {  // abstracta
protected:
    int range;
    int speed;
    coordenada_t coord;
    std::stack<coordenada_t> path;

public:
    Units(int id, double hp, int range, int speed, coordenada_t coord);
    void setPath(std::stack<coordenada_t> _path);
    coordenada_t getPosition();
    void setPosition(coordenada_t newPosition);
    void relocate();
};

#endif  // UNITY_H_
