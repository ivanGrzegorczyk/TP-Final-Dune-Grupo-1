#ifndef UNITY_H_
#define UNITY_H_

#include <utility>
#include <stack>
#include <memory>

#include "server/headers/model/ServerEntity.h"
#include "common/headers/Constantes.h"
class Weapon;
#include "server/headers/weapons/Weapon.h"

class Unit: public ServerEntity {  // abstracta
protected:
    unsigned int range;
    unsigned int speed;
    unsigned int cost;
    Weapon *weapon;
    std::pair<int, int> target;
    std::stack<coordenada_t> path;
    bool attacking;

public:
    Unit(int id, unsigned int hp, unsigned int range, unsigned int speed,
         int type, unsigned int cost, Weapon * weapon, coordenada_t coord);
    Unit(int id, unsigned int hp, unsigned int range, unsigned int speed,
         int type, unsigned int cost, Weapon * weapon, coordenada_t coord, bool attacking);
    void setPath(std::stack<coordenada_t> _path);
    void setPosition(coordenada_t newPosition);
    coordenada_t relocate();
    virtual std::shared_ptr<Unit> copy() = 0;

    virtual ~Unit() = default;

    bool isStill();

    unsigned int getRange() const;

    void setTarget(int enemyId, int _target);

    bool hasTarget() const;

    std::pair<int, int> getTarget();

    void stopMoving();

    // TODO ataque polimorfico a entidades
    bool attack(std::shared_ptr<Unit> &enemy);

    bool isAttacking() const;

    void stopAttacking();

    coordenada_t getGoal();

    coordenada_t getNextPosition();
};

#endif  // UNITY_H_
