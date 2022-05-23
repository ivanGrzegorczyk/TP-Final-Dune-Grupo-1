#include "../../headers/editor/celda_editor.h"
CeldaEditor::CeldaEditor(coordenada_t id) : id(id) {
    terreno = std::move("default");
}
CeldaEditor::CeldaEditor(coordenada_t id, std::string terreno) : terreno(terreno), id(id) {}