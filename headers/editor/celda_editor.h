
#include <vector>
#include <string>
#pragma once
//TODO codigo repetido
typedef std::pair<int, int> coordenada_t;
class CeldaEditor {
    public:
    coordenada_t id;
    std::string terreno;
    std::vector<std::string> propiedades;
    CeldaEditor(coordenada_t id);
    CeldaEditor(coordenada_t id, std::string textura);
};