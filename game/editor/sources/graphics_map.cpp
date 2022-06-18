#include "../../game/editor/headers/graphics_map.h"
#include "../../game/editor/headers/cell.h"
GraphicsMap::GraphicsMap() {};
void GraphicsMap::update() {
    std::cout << "updating all cells" << std::endl;
    for(QGraphicsItem* item : this->childItems()) {
        Cell* cell_item = qgraphicsitem_cast<Cell*>(item);
        if(cell_item != nullptr)
            cell_item->update();
    }
};
int GraphicsMap::type() const {
    return Type;
}