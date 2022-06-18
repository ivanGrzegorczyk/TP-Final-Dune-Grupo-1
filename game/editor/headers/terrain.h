#ifndef TERRAIN_H_
#define TERRAIN_H_

#include <vector>
#include <string>
#include <QImage>

class Terrain {
    private:
    std::string _name;
    QImage img;
    public:
    Terrain(std::string& name);
    QImage image();
    std::string name();
};

#endif  // TERRAIN_H_