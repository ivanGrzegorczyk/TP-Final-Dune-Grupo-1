#ifndef SHAREDBRUSH_H_
#define SHAREDBRUSH_H_
#include "terrain.h"
#include <vector>
#include <string>
#include <QImage>
#include <memory>
// TODO Replace with state pattern
class EditorState {
    private:
    std::shared_ptr<Terrain> terrain;
    std::string _state;
    unsigned int _seed;
    public:
    EditorState(std::shared_ptr<Terrain> t) : terrain(t), _state("terrain"), _seed(0) {}
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
    unsigned int seed() {
        return _seed;
    }
    void set_seed(unsigned int seed) {
        std::cout << "seed set!" << std::endl;
        _seed = seed;
    }
};
#endif  // SHAREDBRUSH_H_