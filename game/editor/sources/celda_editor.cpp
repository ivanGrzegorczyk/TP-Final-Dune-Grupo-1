#include "../../game/editor/headers/celda_editor.h"
CeldaEditor::CeldaEditor(coordenada_t id, std::shared_ptr<Terrain> t) : terrain(t), id(id), seed(0) {}
std::string CeldaEditor::to_string() {
    return propiedades.empty() ? terrain->name().substr(0,1) : propiedades[0].substr(0,1);
}

//todo use terrain object for this state
void CeldaEditor::set_seed_level(unsigned int level) {
    if(terrain->name() != "sand") {
        throw std::invalid_argument("seed is not a thing for this terrain.");
    }
    this->seed = level;
}

//todo use terrain object for this state
unsigned int CeldaEditor::seed_level() const {
    return this->seed;
}