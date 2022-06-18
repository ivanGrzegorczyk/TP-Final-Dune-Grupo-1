#include  "../../game/editor/headers/terrain.h"
Terrain::Terrain(std::string& name) : _name(name) {
    // for now all terrain uses the same texture
    std::string filename = ":d2k_BLOXXMAS.bmp";
    if(!img.load(filename.c_str())) throw std::invalid_argument(filename);
    // TODO: merge image processing code with d2k
    img = (_name == "mountain") ? img.copy(0,0,32,32) : img.copy(32,32,32,32);
}
QImage Terrain::image() {
    return img;
}

std::string Terrain::name() {
    return _name;
}