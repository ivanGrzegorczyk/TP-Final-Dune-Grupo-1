#include  "../../game/editor/headers/terrain.h"
Terrain::Terrain(std::string& name) : _name(name) {
    // for now all terrain uses the same texture
    std::string filename = ":d2k_BLOXXMAS.bmp";
    if(!img.load(filename.c_str())) throw std::invalid_argument(filename);
    // TODO: merge image processing code with d2k
    if(_name == "sand") {
        img = img.copy(0,32,16,16);
    } else if (_name == "mountain") {
        img = img.copy(32,32,16,16);
    } else if (_name == "rock") {
        img = img.copy(0,0,16,16);
    } else if (_name == "dune") {
        img = img.copy(32,0,16,16);
    } else if (_name == "cliff") {
        img = img.copy(32,32,16,16);
    } else {
        throw std::invalid_argument("bad terrain name");
    }
    img= img.scaledToWidth(32);
}
QImage Terrain::image() {
    return img;
}

std::string Terrain::name() {
    return _name;
}