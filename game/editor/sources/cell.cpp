#include "../../game/editor/headers/cell.h"
#include "../../game/editor/headers/graphics_map.h"
#include <iostream>
#include <fstream>
#include <qpainter.h>
#include <QBitmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsColorizeEffect>
#include <QGraphicsEffect>
class GraphicsMap;
Cell::Cell(std::shared_ptr<MapaEditor> map, 
    std::shared_ptr<EditorState> brush, 
    coordenada_t position): 
        map(map), 
        position(position), 
        current_brush(brush) {
    this->update();
}

void Cell::update()
{
    const CeldaEditor cell = map->cell(position);
    QImage terrain_texture = cell.terrain->image();
    currentTexture = QPixmap::fromImage(terrain_texture);
    int seed_level = cell.seed_level();
    this->setPixmap(currentTexture);
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();
    if(map->is_in_construction_center(position)) {
        effect->setColor(Qt::blue);
        this->setGraphicsEffect(effect);
    } else if(cell.terrain->name() == "sand"){
        if(seed_level > 0 && seed_level <= 600) {
            effect->setColor(Qt::red);
            this->setGraphicsEffect(effect);
        } else if(seed_level > 600){
            effect->setColor(Qt::darkRed);
            this->setGraphicsEffect(effect);
        } else {
            this->setGraphicsEffect(nullptr);
        }
    }
    else {
        this->setGraphicsEffect(nullptr);
    }
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    this->setPixmap(currentTexture.transformed(QTransform().scale(1.05, 1.05)));
}

void Cell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)  {
    this->setPixmap(currentTexture);
}

/*
    Paints using the current texture the user is painting with.
*/
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if(current_brush->state() == "building") {
        move_building();
    } else {
        place_tile(current_brush->brush(), current_brush->seed());
    }
}

void Cell::place_tile(std::shared_ptr<Terrain> terrain, unsigned int seed) {
    std::vector<coordenada_t> coordinates{position};
    map->place_terrain(coordinates, terrain, seed);
    update();
}

void Cell::move_building() {
    try {
        map->colocar_centro_construccion(position);
    } catch(std::invalid_argument e) {
        std::cout << e.what(); 
    }
    GraphicsMap* parent = qgraphicsitem_cast<GraphicsMap*>(this->parentItem());
    parent->update();
}
