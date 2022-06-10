#ifndef CELDA_EDITOR_H_
#define CELDA_EDITOR_H_

#include <vector>
#include <string>

#include "../../common/headers/Entity.h"

class CeldaEditor {
    public:
    coordenada_t id;
    std::string terreno;
    std::vector<std::string> propiedades;
    CeldaEditor(coordenada_t id);
    CeldaEditor(coordenada_t id, std::string textura);
    std::string to_string();
};

#endif  // CELDA_EDITOR_H_