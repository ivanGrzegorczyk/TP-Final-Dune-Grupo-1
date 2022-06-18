#include "../../game/editor/headers/cell.h"
#include <iostream>
#include <fstream>
#include <qpainter.h>
#include <QBitmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsColorizeEffect>
#include <QGraphicsEffect>
Cell::Cell(std::shared_ptr<MapaEditor> map, std::shared_ptr<SharedBrush> brush, coordenada_t position): 
        hovering(false), map(map), position(position), current_brush(brush) {
    this->update();
}

void Cell::update()
{
    QImage terrain_texture = map->cell(position).terrain->image();
    currentTexture = QPixmap::fromImage(terrain_texture);
    this->setPixmap(currentTexture);
    if(position == map->construction_center()) {
        QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();
        effect->setColor(Qt::red);
        this->setGraphicsEffect(effect);
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
        place_tile(current_brush->brush());
    }
}

void Cell::place_tile(std::shared_ptr<Terrain> terrain) {
    std::vector<coordenada_t> coordinates{position};
    map->place_terrain(coordinates, terrain);
    update();
}

void Cell::move_building() {
    map->colocar_centro_construccion(position);
    update();
}
