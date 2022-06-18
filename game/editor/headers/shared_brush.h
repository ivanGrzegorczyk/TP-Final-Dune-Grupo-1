#ifndef SHAREDBRUSH_H_
#define SHAREDBRUSH_H_
#include "terrain.h"
#include <vector>
#include <string>
#include <QImage>
#include <memory>
// TODO Replace with state pattern
class SharedBrush {
    private:
    std::shared_ptr<Terrain> terrain;
    std::string _state;
    public:
    SharedBrush(std::shared_ptr<Terrain> t) : terrain(t), _state("terrain") {}
    void change_brush(std::shared_ptr<Terrain> t) {
        _state = "terrain";
        terrain = t;
    }
    void move_building() {
        _state = "building";
    }
    std::shared_ptr<Terrain> brush() {
        return terrain;
    }
    std::string state() {
        return _state;
    }
};
#endif  // SHAREDBRUSH_H_