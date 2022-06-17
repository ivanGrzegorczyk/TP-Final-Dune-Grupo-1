#include "../../game/editor/headers/cell.h"
#include <iostream>
#include <fstream>
#include <qpainter.h>
#include <QBitmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsColorizeEffect>
#include <QGraphicsEffect>
Cell::Cell(MapaEditor& map, std::shared_ptr<SharedBrush> brush, coordenada_t position): 
        hovering(false), map(map), position(position), current_brush(brush) {
    // qrc resource handling
    //pm is a pixmap of the terrain to use
    currentTexture = QPixmap::fromImage(current_brush->brush()->image());
    this->setPixmap(currentTexture);
    this->update();
}

void Cell::update()
{
    CeldaEditor c = std::move(map.cell(position));
    //QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect;
    //effect->setColor((c.terrain->name() == "mountain") ? Qt::red : Qt::blue);
    //this->setGraphicsEffect(effect);
    QImage terrain_texture = c.terrain->image();
    QPixmap pm = QPixmap::fromImage(terrain_texture);
    this->setPixmap(pm);
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
    place_tile(current_brush->brush());
}

void Cell::place_tile(std::shared_ptr<Terrain> terrain) {
    std::vector<coordenada_t> coordinates{position};
    std::cout << terrain->name() << std::endl;
    map.place_terrain(coordinates, terrain);
    update();
}
