#ifndef SHAREDBRUSH_H_
#define SHAREDBRUSH_H_
#include "terrain.h"
#include <vector>
#include <string>
#include <QImage>
#include <memory>
class SharedBrush {
    private:
    std::shared_ptr<Terrain> terrain;
    public:
    SharedBrush(std::shared_ptr<Terrain> t) : terrain(t) {}
    void change_brush(std::shared_ptr<Terrain> t) {
        terrain = t;
    }
    std::shared_ptr<Terrain> brush() {
        return terrain;
    }
};
#endif  // SHAREDBRUSH_H_