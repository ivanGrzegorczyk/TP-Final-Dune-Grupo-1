#ifndef CELDA_EDITOR_H_
#define CELDA_EDITOR_H_

#include "terrain.h"
#include <vector>
#include <string>
#include <memory>
typedef std::pair<int, int> coordenada_t;

class CeldaEditor {
    public:
    coordenada_t id;
    std::shared_ptr<Terrain> terrain;
    std::vector<std::string> propiedades;
    CeldaEditor(coordenada_t id, std::shared_ptr<Terrain> t);
    std::string to_string();
};

#endif  // CELDA_EDITOR_H_