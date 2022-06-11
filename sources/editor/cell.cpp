#include "../../headers/editor/cell.h"
#include <iostream>
#include <qpainter.h>
#include <QBitmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsColorizeEffect>
#include <QGraphicsEffect>
Cell::Cell(MapaEditor& map, std::shared_ptr<std::string> curr_terrain_brush, coordenada_t position): 
    current_brush(curr_terrain_brush), currentPixmap(0), hovering(false), map(map), position(position)
{
    QImage img;
    // qrc resource handling
    if(!img.load(":crate.png")) throw std::invalid_argument("bad filename");
    QPixmap pm = QPixmap::fromImage(img);
    currentTexture = pm;
    this->setPixmap(currentTexture);
}

void Cell::update()
{
    CeldaEditor c = std::move(map.cell(position));
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect;
    effect->setColor((c.terreno == "mountain") ? Qt::red : Qt::blue);
    this->setGraphicsEffect(effect);
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
    std:: cout << "texture is  " << *current_brush << std::endl;
    place_tile(*current_brush);
}

void Cell::place_tile(std::string terrain) {
    std::vector<coordenada_t> coordinates{position};
    map.poner_terreno(coordinates, terrain);
    update();
}
