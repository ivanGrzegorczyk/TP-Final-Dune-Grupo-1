#include "cell.h"
#include <iostream>
#include <qpainter.h>
Cell::Cell(): currentPixmap(0), hovering(false)
{
    QImage img;
    // qrc resource handling
    if(!img.load(":crate.png")) throw std::invalid_argument("bad filename");
    int imageCount = 1;
    int sideLength = img.width();

    auto pix = QPixmap::fromImage(img);
    pixmaps.push_back(pix);

    auto painter = QPainter();
    painter.setPen(QColor(0, 0, 255));
    painter.drawPixmap(pix.rect(), pix, pix.rect());

    this->setPixmap(pix);
}

void Cell::update()
{
    auto current = pixmaps[0];
    if (hovering){
        this->setPixmap(current.transformed(QTransform().scale(1.05, 1.05)));
    } else {
        this->setPixmap(current);
    }
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    auto current = pixmaps[0];
    this->setPixmap(current.transformed(QTransform().scale(1.05, 1.05)));
}

void Cell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)  {
    auto current = pixmaps[0];
    this->setPixmap(current);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->update();
}
