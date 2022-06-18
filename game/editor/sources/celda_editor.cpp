#include "../headers/celda_editor.h"

CeldaEditor::CeldaEditor(coordenada_t id) : id(id) {
    terreno = std::move("default");
}
CeldaEditor::CeldaEditor(coordenada_t id, std::string terreno) : terreno(terreno), id(id) {}
std::string CeldaEditor::to_string() {
    return propiedades.empty() ? terreno.substr(0,1) : propiedades[0].substr(0,1);
}