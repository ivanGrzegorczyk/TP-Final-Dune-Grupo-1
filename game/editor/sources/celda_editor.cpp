#include "../../game/editor/headers/celda_editor.h"
CeldaEditor::CeldaEditor(coordenada_t id, std::shared_ptr<Terrain> t) : terrain(t), id(id) {}
std::string CeldaEditor::to_string() {
    return propiedades.empty() ? terrain->name().substr(0,1) : propiedades[0].substr(0,1);
}