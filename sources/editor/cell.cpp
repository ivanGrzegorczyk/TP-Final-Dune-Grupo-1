#include "cell.h"
#include <iostream>
#include <qpainter.h>
#include <QBitmap>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsColorizeEffect>
#include <QGraphicsEffect>
Cell::Cell(): currentPixmap(0), hovering(false)
{
    QImage img;
    // qrc resource handling
    if(!img.load(":crate.png")) throw std::invalid_argument("bad filename");
    QPixmap pm = QPixmap::fromImage(img);
    pixmaps.push_back(pm);
    currentTexture = pixmaps[0];
    this->setPixmap(currentTexture);
}

void Cell::update()
{

}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    this->setPixmap(currentTexture.transformed(QTransform().scale(1.05, 1.05)));
}

void Cell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)  {
    this->setPixmap(currentTexture);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    place_tile("sand");
}

void Cell::place_tile(std::string terrain) {
    current_terrain = terrain;
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect;
    effect->setColor((terrain == "sand") ? Qt::red : Qt::blue);
    this->setGraphicsEffect(effect);
}
